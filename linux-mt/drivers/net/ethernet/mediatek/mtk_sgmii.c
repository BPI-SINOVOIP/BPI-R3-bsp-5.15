// SPDX-License-Identifier: GPL-2.0
// Copyright (c) 2018-2019 MediaTek Inc.

/* A library for MediaTek SGMII circuit
 *
 * Author: Sean Wang <sean.wang@mediatek.com>
 *
 */

#include <linux/delay.h>
#include <linux/mfd/syscon.h>
#include <linux/of.h>
#include <linux/phylink.h>
#include <linux/regmap.h>

#include "mtk_eth_soc.h"

static struct mtk_pcs *pcs_to_mtk_pcs(struct phylink_pcs *pcs)
{
	return container_of(pcs, struct mtk_pcs, pcs);
}

/* For SGMII interface mode */
static int mtk_pcs_setup_mode_an(struct mtk_pcs *mpcs, phy_interface_t interface)
{
	unsigned int val;

	/* PHYA power down */
	regmap_write(mpcs->regmap, SGMSYS_QPHY_PWR_STATE_CTRL, SGMII_PHYA_PWD);

	/* Set SGMII phy speed */
	regmap_read(mpcs->regmap, mpcs->ana_rgc3, &val);
	val &= ~RG_PHY_SPEED_MASK;
	if (interface == PHY_INTERFACE_MODE_2500BASEX)
		val |= RG_PHY_SPEED_3_125G;
	regmap_write(mpcs->regmap, mpcs->ana_rgc3, val);

	/* Setup the link timer and QPHY power up inside SGMIISYS */
	regmap_write(mpcs->regmap, SGMSYS_PCS_LINK_TIMER,
		     SGMII_LINK_TIMER_DEFAULT);

	/* disable remote fault & enable auto neg */
	regmap_read(mpcs->regmap, SGMSYS_SGMII_MODE, &val);
	val |= SGMII_REMOTE_FAULT_DIS | SGMII_SPEED_DUPLEX_AN;
	regmap_write(mpcs->regmap, SGMSYS_SGMII_MODE, val);

	regmap_read(mpcs->regmap, SGMSYS_PCS_CONTROL_1, &val);
	val |= SGMII_AN_RESTART | SGMII_AN_ENABLE;
	regmap_write(mpcs->regmap, SGMSYS_PCS_CONTROL_1, val);

	/* Release PHYA power down state
	 * unknown how much the QPHY needs but it is racy without a sleep
	 */
	usleep_range(50, 100);
	regmap_write(mpcs->regmap, SGMSYS_QPHY_PWR_STATE_CTRL, 0);

	return 0;

}

/* For 1000BASE-X and 2500BASE-X interface modes, which operate at a
 * fixed speed.
 */
static int mtk_pcs_setup_mode_force(struct mtk_pcs *mpcs,
				    phy_interface_t interface)
{
	unsigned int val;

	/* PHYA power down */
	regmap_write(mpcs->regmap, SGMSYS_QPHY_PWR_STATE_CTRL, SGMII_PHYA_PWD);

	regmap_read(mpcs->regmap, mpcs->ana_rgc3, &val);
	val &= ~RG_PHY_SPEED_MASK;
	if (interface == PHY_INTERFACE_MODE_2500BASEX)
		val |= RG_PHY_SPEED_3_125G;
	regmap_write(mpcs->regmap, mpcs->ana_rgc3, val);

	/* Disable SGMII AN */
	regmap_read(mpcs->regmap, SGMSYS_PCS_CONTROL_1, &val);
	val &= ~SGMII_AN_ENABLE;
	regmap_write(mpcs->regmap, SGMSYS_PCS_CONTROL_1, val);

	/* Set the speed etc but leave the duplex unchanged.
	 * The SGMII mode for 2.5gbit is the same as for 1gbit, expect the speed in ANA_RGC3 */
	regmap_read(mpcs->regmap, SGMSYS_SGMII_MODE, &val);
	val &= SGMII_DUPLEX_FULL | ~SGMII_IF_MODE_MASK;
	val |= SGMII_SPEED_1000;
	regmap_write(mpcs->regmap, SGMSYS_SGMII_MODE, val);

	/* Release PHYA power down state
	 * unknown how much the QPHY needs but it is racy without a sleep
	 */
	usleep_range(50, 100);
	regmap_write(mpcs->regmap, SGMSYS_QPHY_PWR_STATE_CTRL, 0);

	return 0;
}

static int mtk_pcs_config(struct phylink_pcs *pcs, unsigned int mode,
			  phy_interface_t interface,
			  const unsigned long *advertising,
			  bool permit_pause_to_mac)
{
	struct mtk_pcs *mpcs = pcs_to_mtk_pcs(pcs);
	int err = 0;

	/* Setup SGMIISYS with the determined property */
	if (interface != PHY_INTERFACE_MODE_SGMII)
		err = mtk_pcs_setup_mode_force(mpcs, interface);
	else if (phylink_autoneg_inband(mode))
		err = mtk_pcs_setup_mode_an(mpcs, interface);

	return err;
}

static void mtk_pcs_restart_an(struct phylink_pcs *pcs)
{
	struct mtk_pcs *mpcs = pcs_to_mtk_pcs(pcs);
	unsigned int val;

	regmap_read(mpcs->regmap, SGMSYS_PCS_CONTROL_1, &val);
	val |= SGMII_AN_RESTART;
	regmap_write(mpcs->regmap, SGMSYS_PCS_CONTROL_1, val);
}

static void mtk_pcs_link_up(struct phylink_pcs *pcs, unsigned int mode,
			    phy_interface_t interface, int speed, int duplex)
{
	struct mtk_pcs *mpcs = pcs_to_mtk_pcs(pcs);
	unsigned int val;

	if (!phy_interface_mode_is_8023z(interface))
		return;

	/* SGMII force duplex setting */
	regmap_read(mpcs->regmap, SGMSYS_SGMII_MODE, &val);
	val &= ~SGMII_DUPLEX_FULL;
	if (duplex == DUPLEX_FULL)
		val |= SGMII_DUPLEX_FULL;

	regmap_write(mpcs->regmap, SGMSYS_SGMII_MODE, val);
}

static void mtk_pcs_get_state(struct phylink_pcs *pcs, struct phylink_link_state *state)
{
	struct mtk_pcs *mpcs = pcs_to_mtk_pcs(pcs);
	unsigned int val;

	regmap_read(mpcs->regmap, SGMSYS_PCS_CONTROL_1, &val);
	state->an_complete = !!(val & SGMII_AN_COMPLETE);
	state->link = !!(val & SGMII_LINK_STATYS);
	if (!state->link)
		return;

	regmap_read(mpcs->regmap, mpcs->ana_rgc3, &val);
	state->speed = val & RG_PHY_SPEED_3_125G ? SPEED_2500 : SPEED_1000;
	state->duplex = DUPLEX_FULL;
	state->pause = 0;
}

static const struct phylink_pcs_ops mtk_pcs_ops = {
	.pcs_config = mtk_pcs_config,
	.pcs_an_restart = mtk_pcs_restart_an,
	.pcs_link_up = mtk_pcs_link_up,
	.pcs_get_state = mtk_pcs_get_state,
};

int mtk_sgmii_init(struct mtk_sgmii *ss, struct device_node *r, u32 ana_rgc3)
{
	struct device_node *np;
	int i;

	for (i = 0; i < MTK_MAX_DEVS; i++) {
		np = of_parse_phandle(r, "mediatek,sgmiisys", i);
		if (!np)
			break;

		ss->pcs[i].ana_rgc3 = ana_rgc3;
		ss->pcs[i].regmap = syscon_node_to_regmap(np);
		of_node_put(np);
		if (IS_ERR(ss->pcs[i].regmap))
			return PTR_ERR(ss->pcs[i].regmap);

		ss->pcs[i].pcs.ops = &mtk_pcs_ops;
		ss->pcs[i].pcs.poll = 1;
	}

	return 0;
}

struct phylink_pcs *mtk_sgmii_select_pcs(struct mtk_sgmii *ss, int id)
{
	if (!ss->pcs[id].regmap)
		return NULL;

	return &ss->pcs[id].pcs;
}

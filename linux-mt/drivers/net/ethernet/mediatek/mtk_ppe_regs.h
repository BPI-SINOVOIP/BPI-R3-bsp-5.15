// SPDX-License-Identifier: GPL-2.0-only
/* Copyright (C) 2020 Felix Fietkau <nbd@nbd.name> */

#ifndef __MTK_PPE_REGS_H
#define __MTK_PPE_REGS_H

#define MTK_PPE_GLO_CFG				0x200
#define MTK_PPE_GLO_CFG_EN			BIT(0)
#define MTK_PPE_GLO_CFG_TSID_EN			BIT(1)
#define MTK_PPE_GLO_CFG_IP4_L4_CS_DROP		BIT(2)
#define MTK_PPE_GLO_CFG_IP4_CS_DROP		BIT(3)
#define MTK_PPE_GLO_CFG_TTL0_DROP		BIT(4)
#define MTK_PPE_GLO_CFG_PPE_BSWAP		BIT(5)
#define MTK_PPE_GLO_CFG_PSE_HASH_OFS		BIT(6)
#define MTK_PPE_GLO_CFG_MCAST_TB_EN		BIT(7)
#define MTK_PPE_GLO_CFG_FLOW_DROP_KA		BIT(8)
#define MTK_PPE_GLO_CFG_FLOW_DROP_UPDATE	BIT(9)
#define MTK_PPE_GLO_CFG_UDP_LITE_EN		BIT(10)
#define MTK_PPE_GLO_CFG_UDP_LEN_DROP		BIT(11)
#define MTK_PPE_GLO_CFG_MCAST_ENTRIES		GNEMASK(13, 12)
#define MTK_PPE_GLO_CFG_BUSY			BIT(31)

#define MTK_PPE_FLOW_CFG			0x204
#define MTK_PPE_MD_TOAP_BYP_CRSN0		BIT(1)
#define MTK_PPE_MD_TOAP_BYP_CRSN1		BIT(2)
#define MTK_PPE_MD_TOAP_BYP_CRSN2		BIT(3)
#define MTK_PPE_FLOW_CFG_IP4_TCP_FRAG		BIT(6)
#define MTK_PPE_FLOW_CFG_IP4_UDP_FRAG		BIT(7)
#define MTK_PPE_FLOW_CFG_IP6_3T_ROUTE		BIT(8)
#define MTK_PPE_FLOW_CFG_IP6_5T_ROUTE		BIT(9)
#define MTK_PPE_FLOW_CFG_IP6_6RD		BIT(10)
#define MTK_PPE_FLOW_CFG_IP4_NAT		BIT(12)
#define MTK_PPE_FLOW_CFG_IP4_NAPT		BIT(13)
#define MTK_PPE_FLOW_CFG_IP4_DSLITE		BIT(14)
#define MTK_PPE_FLOW_CFG_L2_BRIDGE		BIT(15)
#define MTK_PPE_FLOW_CFG_IP_PROTO_BLACKLIST	BIT(16)
#define MTK_PPE_FLOW_CFG_IP4_NAT_FRAG		BIT(17)
#define MTK_PPE_FLOW_CFG_IP4_HASH_FLOW_LABEL	BIT(18)
#define MTK_PPE_FLOW_CFG_IP4_HASH_GRE_KEY	BIT(19)
#define MTK_PPE_FLOW_CFG_IP6_HASH_GRE_KEY	BIT(20)

#define MTK_PPE_IP_PROTO_CHK			0x208
#define MTK_PPE_IP_PROTO_CHK_IPV4		GENMASK(15, 0)
#define MTK_PPE_IP_PROTO_CHK_IPV6		GENMASK(31, 16)

#define MTK_PPE_TB_CFG				0x21c
#define MTK_PPE_TB_CFG_ENTRY_NUM		GENMASK(2, 0)
#define MTK_PPE_TB_CFG_ENTRY_80B		BIT(3)
#define MTK_PPE_TB_CFG_SEARCH_MISS		GENMASK(5, 4)
#define MTK_PPE_TB_CFG_AGE_PREBIND		BIT(6)
#define MTK_PPE_TB_CFG_AGE_NON_L4		BIT(7)
#define MTK_PPE_TB_CFG_AGE_UNBIND		BIT(8)
#define MTK_PPE_TB_CFG_AGE_TCP			BIT(9)
#define MTK_PPE_TB_CFG_AGE_UDP			BIT(10)
#define MTK_PPE_TB_CFG_AGE_TCP_FIN		BIT(11)
#define MTK_PPE_TB_CFG_KEEPALIVE		GENMASK(13, 12)
#define MTK_PPE_TB_CFG_HASH_MODE		GENMASK(15, 14)
#define MTK_PPE_TB_CFG_SCAN_MODE		GENMASK(17, 16)
#define MTK_PPE_TB_CFG_HASH_DEBUG		GENMASK(19, 18)
#define MTK_PPE_TB_CFG_INFO_SEL			BIT(20)

enum {
	MTK_PPE_SCAN_MODE_DISABLED,
	MTK_PPE_SCAN_MODE_CHECK_AGE,
	MTK_PPE_SCAN_MODE_KEEPALIVE_AGE,
};

enum {
	MTK_PPE_KEEPALIVE_DISABLE,
	MTK_PPE_KEEPALIVE_UNICAST_CPU,
	MTK_PPE_KEEPALIVE_DUP_CPU = 3,
};

enum {
	MTK_PPE_SEARCH_MISS_ACTION_DROP,
	MTK_PPE_SEARCH_MISS_ACTION_FORWARD = 2,
	MTK_PPE_SEARCH_MISS_ACTION_FORWARD_BUILD = 3,
};

#define MTK_PPE_TB_BASE				0x220

#define MTK_PPE_TB_USED				0x224
#define MTK_PPE_TB_USED_NUM			GENMASK(13, 0)

#define MTK_PPE_BIND_RATE			0x228
#define MTK_PPE_BIND_RATE_BIND			GENMASK(15, 0)
#define MTK_PPE_BIND_RATE_PREBIND		GENMASK(31, 16)

#define MTK_PPE_BIND_LIMIT0			0x22c
#define MTK_PPE_BIND_LIMIT0_QUARTER		GENMASK(13, 0)
#define MTK_PPE_BIND_LIMIT0_HALF		GENMASK(29, 16)

#define MTK_PPE_BIND_LIMIT1			0x230
#define MTK_PPE_BIND_LIMIT1_FULL		GENMASK(13, 0)
#define MTK_PPE_BIND_LIMIT1_NON_L4		GENMASK(23, 16)

#define MTK_PPE_KEEPALIVE			0x234
#define MTK_PPE_KEEPALIVE_TIME			GENMASK(15, 0)
#define MTK_PPE_KEEPALIVE_TIME_TCP		GENMASK(23, 16)
#define MTK_PPE_KEEPALIVE_TIME_UDP		GENMASK(31, 24)

#define MTK_PPE_UNBIND_AGE			0x238
#define MTK_PPE_UNBIND_AGE_MIN_PACKETS		GENMASK(31, 16)
#define MTK_PPE_UNBIND_AGE_DELTA		GENMASK(7, 0)

#define MTK_PPE_BIND_AGE0			0x23c
#define MTK_PPE_BIND_AGE0_DELTA_NON_L4		GENMASK(30, 16)
#define MTK_PPE_BIND_AGE0_DELTA_UDP		GENMASK(14, 0)

#define MTK_PPE_BIND_AGE1			0x240
#define MTK_PPE_BIND_AGE1_DELTA_TCP_FIN		GENMASK(30, 16)
#define MTK_PPE_BIND_AGE1_DELTA_TCP		GENMASK(14, 0)

#define MTK_PPE_HASH_SEED			0x244

#define MTK_PPE_DEFAULT_CPU_PORT		0x248
#define MTK_PPE_DEFAULT_CPU_PORT_MASK(_n)	(GENMASK(2, 0) << ((_n) * 4))

#define MTK_PPE_DEFAULT_CPU_PORT1		0x24c

#define MTK_PPE_MTU_DROP			0x308

#define MTK_PPE_VLAN_MTU0			0x30c
#define MTK_PPE_VLAN_MTU0_NONE			GENMASK(13, 0)
#define MTK_PPE_VLAN_MTU0_1TAG			GENMASK(29, 16)

#define MTK_PPE_VLAN_MTU1			0x310
#define MTK_PPE_VLAN_MTU1_2TAG			GENMASK(13, 0)
#define MTK_PPE_VLAN_MTU1_3TAG			GENMASK(29, 16)

#define MTK_PPE_VPM_TPID			0x318

#define MTK_PPE_CACHE_CTL			0x320
#define MTK_PPE_CACHE_CTL_EN			BIT(0)
#define MTK_PPE_CACHE_CTL_LOCK_CLR		BIT(4)
#define MTK_PPE_CACHE_CTL_REQ			BIT(8)
#define MTK_PPE_CACHE_CTL_CLEAR			BIT(9)
#define MTK_PPE_CACHE_CTL_CMD			GENMASK(13, 12)

#define MTK_PPE_MIB_CFG				0x334
#define MTK_PPE_MIB_CFG_EN			BIT(0)
#define MTK_PPE_MIB_CFG_RD_CLR			BIT(1)

#define MTK_PPE_MIB_TB_BASE			0x338

#define MTK_PPE_MIB_SER_CR			0x33C
#define MTK_PPE_MIB_SER_CR_ST			BIT(16)
#define MTK_PPE_MIB_SER_CR_ADDR			GENMASK(13, 0)

#define MTK_PPE_MIB_SER_R0			0x340
#define MTK_PPE_MIB_SER_R0_BYTE_CNT_LOW		GENMASK(31, 0)

#define MTK_PPE_MIB_SER_R1			0x344
#define MTK_PPE_MIB_SER_R1_PKT_CNT_LOW		GENMASK(31, 16)
#define MTK_PPE_MIB_SER_R1_BYTE_CNT_HIGH	GENMASK(15, 0)

#define MTK_PPE_MIB_SER_R2			0x348
#define MTK_PPE_MIB_SER_R2_PKT_CNT_HIGH		GENMASK(23, 0)

#define MTK_PPE_MIB_CACHE_CTL			0x350
#define MTK_PPE_MIB_CACHE_CTL_EN		BIT(0)
#define MTK_PPE_MIB_CACHE_CTL_FLUSH		BIT(2)

#define MTK_PPE_SBW_CTRL			0x374

#endif

/*
 * Copyright (c) 2021, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <lib/xlat_tables/xlat_tables_v2.h>

#include <platform_def.h>

/* Table of regions to map using the MMU.  */
const mmap_region_t plat_mmap[] = {
	/* for TF text, RO, RW */
	MAP_REGION_FLAT(MTK_DEV_RNG0_BASE, MTK_DEV_RNG0_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(MTK_DEV_RNG2_BASE, MTK_DEV_RNG2_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(MTK_MCDI_SRAM_BASE, MTK_MCDI_SRAM_MAP_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(DP_SEC_BASE, DP_SEC_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(eDP_SEC_BASE, eDP_SEC_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(APUSYS_SCTRL_REVISER_BASE, APUSYS_SCTRL_REVISER_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(APUSYS_APU_S_S_4_BASE, APUSYS_APU_S_S_4_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(APUSYS_APU_PLL_BASE, APUSYS_APU_PLL_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	MAP_REGION_FLAT(APUSYS_APU_ACC_BASE, APUSYS_APU_ACC_SIZE,
			MT_DEVICE | MT_RW | MT_SECURE),
	{ 0 }
};

/*******************************************************************************
 * Macro generating the code for the function setting up the pagetables as per
 * the platform memory map & initialize the mmu, for the given exception level
 ******************************************************************************/
void plat_configure_mmu_el3(uintptr_t total_base,
			    uintptr_t total_size,
			    uintptr_t ro_start,
			    uintptr_t ro_limit)
{
	mmap_add_region(total_base, total_base, total_size,
			MT_RW_DATA | MT_SECURE);
	mmap_add_region(ro_start, ro_start, ro_limit - ro_start,
			MT_CODE | MT_SECURE);
	mmap_add(plat_mmap);
	init_xlat_tables();
	enable_mmu_el3(0);
}

unsigned int plat_get_syscnt_freq2(void)
{
	return SYS_COUNTER_FREQ_IN_TICKS;
}

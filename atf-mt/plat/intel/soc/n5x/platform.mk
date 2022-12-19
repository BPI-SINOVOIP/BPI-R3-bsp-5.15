#
# Copyright (c) 2020-2022, Intel Corporation. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

PLAT_INCLUDES		:=	\
			-Iplat/intel/soc/n5x/include/			\
			-Iplat/intel/soc/common/drivers/		\
			-Iplat/intel/soc/common/include/

# Include GICv2 driver files
include drivers/arm/gic/v2/gicv2.mk
DM_GICv2_SOURCES	:=	\
			${GICV2_SOURCES}                                \
			plat/common/plat_gicv2.c


PLAT_BL_COMMON_SOURCES	:=	\
			${DM_GICv2_SOURCES}				\
			drivers/delay_timer/delay_timer.c		\
			drivers/delay_timer/generic_delay_timer.c  	\
			drivers/ti/uart/aarch64/16550_console.S		\
			lib/xlat_tables/aarch64/xlat_tables.c 		\
			lib/xlat_tables/xlat_tables_common.c 		\
			plat/intel/soc/common/aarch64/platform_common.c \
			plat/intel/soc/common/aarch64/plat_helpers.S	\
			plat/intel/soc/common/socfpga_delay_timer.c     \
			plat/intel/soc/common/drivers/ccu/ncore_ccu.c

BL2_SOURCES     +=

BL31_SOURCES	+=	\
		drivers/arm/cci/cci.c					\
		lib/cpus/aarch64/aem_generic.S				\
		lib/cpus/aarch64/cortex_a53.S				\
		plat/common/plat_psci_common.c				\
		plat/intel/soc/n5x/bl31_plat_setup.c			\
		plat/intel/soc/common/socfpga_psci.c			\
		plat/intel/soc/common/socfpga_sip_svc.c			\
		plat/intel/soc/common/socfpga_sip_svc_v2.c		\
		plat/intel/soc/common/socfpga_topology.c		\
		plat/intel/soc/common/sip/socfpga_sip_ecc.c             \
		plat/intel/soc/common/sip/socfpga_sip_fcs.c		\
		plat/intel/soc/common/soc/socfpga_mailbox.c		\
		plat/intel/soc/common/soc/socfpga_reset_manager.c

PROGRAMMABLE_RESET_ADDRESS	:= 0
BL2_AT_EL3			:= 1
BL2_INV_DCACHE			:= 0
MULTI_CONSOLE_API		:= 1
SIMICS_BUILD			:= 0
USE_COHERENT_MEM		:= 1

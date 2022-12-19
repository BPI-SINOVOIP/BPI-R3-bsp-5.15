#
# Copyright 2018-2022 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#

# board-specific build parameters
BOOT_MODE	?=	qspi
BOARD		:=	ls1046aqds
POVDD_ENABLE	:=	no

 # DDR Compilation Configs
NUM_OF_DDRC	:=	1
DDRC_NUM_DIMM	:=	1
DDRC_NUM_CS	:=	4
DDR_ECC_EN	:=	yes
CONFIG_STATIC_DDR := 0

# On-Board Flash Details
QSPI_FLASH_SZ	:=	0x20000000
NOR_FLASH_SZ	:=	0x20000000

# Platform specific features.
WARM_BOOT	:=	no

# Adding Platform files build files
BL2_SOURCES	+=	${BOARD_PATH}/ddr_init.c\
			${BOARD_PATH}/platform.c

SUPPORTED_BOOT_MODE	:=	qspi	\
				sd	\
				nor	\
				nand

# Adding platform board build info
include plat/nxp/common/plat_make_helper/plat_common_def.mk

# Adding SoC build info
include plat/nxp/soc-ls1046a/soc.mk

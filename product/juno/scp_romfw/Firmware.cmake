#
# Arm SCP/MCP Software
# Copyright (c) 2021, Arm Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

set(SCP_FIRMWARE "juno-bl1")
set(SCP_FIRMWARE_TARGET "juno-bl1")

set(SCP_TOOLCHAIN_INIT "GNU")

set(SCP_FIRMWARE_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}")

set(SCP_GENERATE_FLAT_BINARY TRUE)
set(SCP_ARCHITECTURE "armv7-m")

set(SCP_ENABLE_MULTITHREADING FALSE)

set(SCP_ENABLE_NOTIFICATIONS TRUE)

set(SCP_ENABLE_IPO_INIT FALSE)

list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/juno_rom")
list(PREPEND SCP_MODULE_PATHS "${CMAKE_CURRENT_LIST_DIR}/../module/juno_ppu")
list(PREPEND SCP_MODULE_PATHS
     "${CMAKE_CURRENT_LIST_DIR}/../module/juno_soc_clock")

# The order of the modules in the following list is the order in which the
# modules are initialized, bound, started during the pre-runtime phase.
# any change in the order will cause firmware initialization errors.

list(APPEND SCP_MODULES "juno-ppu")
list(APPEND SCP_MODULES "juno-rom")
list(APPEND SCP_MODULES "juno-soc-clock")
list(APPEND SCP_MODULES "clock")
list(APPEND SCP_MODULES "gtimer")
list(APPEND SCP_MODULES "sds")
list(APPEND SCP_MODULES "bootloader")
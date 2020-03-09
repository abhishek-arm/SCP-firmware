/*
 * Arm SCP/MCP Software
 * Copyright (c) 2015-2020, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "juno_clock.h"
#include "juno_scmi.h"

#include <mod_scmi_clock.h>

#include <fwk_id.h>
#include <fwk_macros.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

static const struct mod_scmi_clock_device agent_device_table_ospm[] = {
    {
        /* Big */
        .element_id =
            FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_CLOCK, JUNO_CLOCK_IDX_BIGCLK),
        .permissions = MOD_SCMI_CLOCK_PERM_ATTRIBUTES |
                       MOD_SCMI_CLOCK_PERM_DESCRIBE_RATES |
                       MOD_SCMI_CLOCK_PERM_GET_RATE,
    },
    {
        /* Little */
        .element_id =
            FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_CLOCK, JUNO_CLOCK_IDX_LITTLECLK),
        .permissions = MOD_SCMI_CLOCK_PERM_ATTRIBUTES |
                       MOD_SCMI_CLOCK_PERM_DESCRIBE_RATES |
                       MOD_SCMI_CLOCK_PERM_GET_RATE,
    },
    {
        /* GPU */
        .element_id =
            FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_CLOCK, JUNO_CLOCK_IDX_GPUCLK),
        .permissions = MOD_SCMI_CLOCK_PERM_ATTRIBUTES |
                       MOD_SCMI_CLOCK_PERM_DESCRIBE_RATES |
                       MOD_SCMI_CLOCK_PERM_GET_RATE,
    },
    {
        /* HDLCD0 */
        .element_id =
            FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_CLOCK, JUNO_CLOCK_IDX_HDLCD0),
        .permissions = MOD_SCMI_CLOCK_PERM_ATTRIBUTES |
                       MOD_SCMI_CLOCK_PERM_DESCRIBE_RATES |
                       MOD_SCMI_CLOCK_PERM_GET_RATE |
                       MOD_SCMI_CLOCK_PERM_SET_RATE |
                       MOD_SCMI_CLOCK_PERM_SET_CONFIG,
    },
    {
        /* HDLCD1 */
        .element_id =
            FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_CLOCK, JUNO_CLOCK_IDX_HDLCD1),
        .permissions = MOD_SCMI_CLOCK_PERM_ATTRIBUTES |
                       MOD_SCMI_CLOCK_PERM_DESCRIBE_RATES,
    },
    {
        /* I2S */
        .element_id =
            FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_CLOCK, JUNO_CLOCK_IDX_I2SCLK),
        .permissions = MOD_SCMI_CLOCK_PERM_ATTRIBUTES |
                       MOD_SCMI_CLOCK_PERM_DESCRIBE_RATES |
                       MOD_SCMI_CLOCK_PERM_GET_RATE |
                       MOD_SCMI_CLOCK_PERM_SET_RATE |
                       MOD_SCMI_CLOCK_PERM_SET_CONFIG,
    },
};

static const struct
    mod_scmi_clock_agent agent_table[JUNO_SCMI_SERVICE_IDX_COUNT] = {
    [JUNO_SCMI_AGENT_IDX_PSCI] = { 0 /* No Access */ },
    [JUNO_SCMI_AGENT_IDX_OSPM] = {
        .device_table = agent_device_table_ospm,
        .device_count = FWK_ARRAY_SIZE(agent_device_table_ospm),
    },
};

struct fwk_module_config config_scmi_clock = {
    .data = &((struct mod_scmi_clock_config) {
        .max_pending_transactions = 0,
        .agent_table = agent_table,
        .agent_count = FWK_ARRAY_SIZE(agent_table),
    }),
};

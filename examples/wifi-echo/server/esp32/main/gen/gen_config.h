/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *
 *    Copyright (c) 2020 Silicon Labs
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef SILABS_ZNET_CONFIG
#define SILABS_ZNET_CONFIG

#include "debug-printing-test.h"

/**** Included Header Section ****/

// Networks
#define EM_AF_GENERATED_NETWORK_TYPES                                                                                              \
    {                                                                                                                              \
        EM_AF_NETWORK_TYPE_ZIGBEE_PRO, /* Primary */                                                                               \
    }
#define EM_AF_GENERATED_ZIGBEE_PRO_NETWORKS                                                                                        \
    {                                                                                                                              \
        {                                                                                                                          \
            /* Primary */                                                                                                          \
            ZA_ROUTER,                                                                                                             \
            EMBER_AF_SECURITY_PROFILE_Z3,                                                                                          \
        },                                                                                                                         \
    }
#define EM_AF_GENERATED_NETWORK_STRINGS "Primary (pro)", /**** ZCL Section ****/
#define ZA_PROMPT "CHIPv1Clusters"
#define ZCL_USING_BASIC_CLUSTER_CLIENT
#define ZCL_USING_BASIC_CLUSTER_SERVER
#define ZCL_USING_IDENTIFY_CLUSTER_CLIENT
#define ZCL_USING_IDENTIFY_CLUSTER_SERVER
#define ZCL_USING_GROUPS_CLUSTER_CLIENT
#define ZCL_USING_GROUPS_CLUSTER_SERVER
#define ZCL_USING_SCENES_CLUSTER_CLIENT
#define ZCL_USING_SCENES_CLUSTER_SERVER
#define ZCL_USING_ON_OFF_CLUSTER_CLIENT
#define ZCL_USING_ON_OFF_CLUSTER_SERVER
#define ZCL_USING_ON_OFF_SWITCH_CONFIG_CLUSTER_CLIENT
#define ZCL_USING_ON_OFF_SWITCH_CONFIG_CLUSTER_SERVER
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_CLIENT
#define ZCL_USING_LEVEL_CONTROL_CLUSTER_SERVER
#define ZCL_USING_POLL_CONTROL_CLUSTER_CLIENT
#define ZCL_USING_POLL_CONTROL_CLUSTER_SERVER
#define ZCL_USING_DOOR_LOCK_CLUSTER_CLIENT
#define ZCL_USING_DOOR_LOCK_CLUSTER_SERVER
#define ZCL_USING_BARRIER_CONTROL_CLUSTER_CLIENT
#define ZCL_USING_BARRIER_CONTROL_CLUSTER_SERVER
#define ZCL_USING_COLOR_CONTROL_CLUSTER_CLIENT
#define ZCL_USING_COLOR_CONTROL_CLUSTER_SERVER
#define ZCL_USING_IAS_ZONE_CLUSTER_CLIENT
#define ZCL_USING_IAS_ZONE_CLUSTER_SERVER
#define EMBER_AF_MANUFACTURER_CODE 0x1002
#define EMBER_AF_DEFAULT_RESPONSE_POLICY_ALWAYS

/**** Cluster endpoint counts ****/
#define EMBER_AF_BASIC_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BASIC_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_IDENTIFY_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_IDENTIFY_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_GROUPS_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_GROUPS_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_SCENES_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_SCENES_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_ON_OFF_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ON_OFF_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_ON_OFF_SWITCH_CONFIG_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_ON_OFF_SWITCH_CONFIG_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_LEVEL_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_LEVEL_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_POLL_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_POLL_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_DOOR_LOCK_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_DOOR_LOCK_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_BARRIER_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BARRIER_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_COLOR_CONTROL_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_COLOR_CONTROL_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_IAS_ZONE_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_IAS_ZONE_CLUSTER_SERVER_ENDPOINT_COUNT (1)

/**** Cluster Endpoint Summaries ****/
#define EMBER_AF_MAX_SERVER_CLUSTER_COUNT (12)
#define EMBER_AF_MAX_CLIENT_CLUSTER_COUNT (12)
#define EMBER_AF_MAX_TOTAL_CLUSTER_COUNT (24)

/**** CLI Section ****/
#define EMBER_AF_GENERATE_CLI

/**** Security Section ****/
#define EMBER_AF_HAS_SECURITY_PROFILE_Z3

/**** Network Section ****/
#define EMBER_SUPPORTED_NETWORKS (1)
#define EMBER_AF_NETWORK_INDEX_PRIMARY (0)
#define EMBER_AF_DEFAULT_NETWORK_INDEX EMBER_AF_NETWORK_INDEX_PRIMARY
#define EMBER_AF_HAS_ROUTER_NETWORK
#define EMBER_AF_HAS_RX_ON_WHEN_IDLE_NETWORK
#define EMBER_AF_TX_POWER_MODE EMBER_TX_POWER_MODE_USE_TOKEN

/**** Callback Section ****/
#define EMBER_CALLBACK_STACK_STATUS
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY_QUERY_RESPONSE
#define EMBER_CALLBACK_BARRIER_CONTROL_CLUSTER_BARRIER_CONTROL_STOP
#define EMBER_CALLBACK_BARRIER_CONTROL_CLUSTER_BARRIER_CONTROL_GO_TO_PERCENT
#define EMBER_CALLBACK_BASIC_CLUSTER_RESET_TO_FACTORY_DEFAULTS
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_COLOR
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_COLOR_TEMPERATURE
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_TO_COLOR
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_HUE
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_SATURATION
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_TO_COLOR_TEMPERATURE
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_TO_HUE_AND_SATURATION
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_TO_HUE
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_MOVE_TO_SATURATION
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_STEP_COLOR
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_STEP_COLOR_TEMPERATURE
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_STEP_HUE
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_STEP_SATURATION
#define EMBER_CALLBACK_COLOR_CONTROL_CLUSTER_STOP_MOVE_STEP
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_CLEAR_ALL_PINS
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_CLEAR_ALL_RFIDS
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_CLEAR_HOLIDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_CLEAR_PIN
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_CLEAR_RFID
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_CLEAR_WEEKDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_GET_HOLIDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_GET_LOG_RECORD
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_GET_PIN
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_GET_RFID
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_GET_USER_TYPE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_GET_WEEKDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_GET_YEARDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_LOCK_DOOR
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_SET_HOLIDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_SET_PIN
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_SET_RFID
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_CLEAR_YEARDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_SET_USER_TYPE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_SET_WEEKDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_SET_YEARDAY_SCHEDULE
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_UNLOCK_DOOR
#define EMBER_CALLBACK_DOOR_LOCK_CLUSTER_UNLOCK_WITH_TIMEOUT
#define EMBER_CALLBACK_GROUPS_CLUSTER_ADD_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_ADD_GROUP_IF_IDENTIFYING
#define EMBER_CALLBACK_GROUPS_CLUSTER_ADD_GROUP_RESPONSE
#define EMBER_CALLBACK_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP
#define EMBER_CALLBACK_GROUPS_CLUSTER_GET_GROUP_MEMBERSHIP_RESPONSE
#define EMBER_CALLBACK_GROUPS_CLUSTER_REMOVE_ALL_GROUPS
#define EMBER_CALLBACK_GROUPS_CLUSTER_REMOVE_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_REMOVE_GROUP_RESPONSE
#define EMBER_CALLBACK_GROUPS_CLUSTER_VIEW_GROUP
#define EMBER_CALLBACK_GROUPS_CLUSTER_VIEW_GROUP_RESPONSE
#define EMBER_CALLBACK_IAS_ZONE_CLUSTER_ZONE_ENROLL_REQUEST
#define EMBER_CALLBACK_IAS_ZONE_CLUSTER_ZONE_ENROLL_RESPONSE
#define EMBER_CALLBACK_IAS_ZONE_CLUSTER_ZONE_STATUS_CHANGE_NOTIFICATION
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY
#define EMBER_CALLBACK_IDENTIFY_CLUSTER_IDENTIFY_QUERY
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE_TO_LEVEL_WITH_ON_OFF
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_MOVE_WITH_ON_OFF
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STEP
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STOP
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STEP_WITH_ON_OFF
#define EMBER_CALLBACK_LEVEL_CONTROL_CLUSTER_STOP_WITH_ON_OFF
#define EMBER_CALLBACK_POLL_CONTROL_CLUSTER_CHECK_IN
#define EMBER_CALLBACK_POLL_CONTROL_CLUSTER_CHECK_IN_RESPONSE
#define EMBER_CALLBACK_POLL_CONTROL_CLUSTER_FAST_POLL_STOP
#define EMBER_CALLBACK_POLL_CONTROL_CLUSTER_SET_LONG_POLL_INTERVAL
#define EMBER_CALLBACK_POLL_CONTROL_CLUSTER_SET_SHORT_POLL_INTERVAL
#define EMBER_CALLBACK_SCENES_CLUSTER_ADD_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_ADD_SCENE_RESPONSE
#define EMBER_CALLBACK_SCENES_CLUSTER_GET_SCENE_MEMBERSHIP
#define EMBER_CALLBACK_SCENES_CLUSTER_GET_SCENE_MEMBERSHIP_RESPONSE
#define EMBER_CALLBACK_SCENES_CLUSTER_RECALL_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_REMOVE_ALL_SCENES
#define EMBER_CALLBACK_SCENES_CLUSTER_REMOVE_ALL_SCENES_RESPONSE
#define EMBER_CALLBACK_SCENES_CLUSTER_REMOVE_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_REMOVE_SCENE_RESPONSE
#define EMBER_CALLBACK_SCENES_CLUSTER_STORE_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_STORE_SCENE_RESPONSE
#define EMBER_CALLBACK_SCENES_CLUSTER_VIEW_SCENE
#define EMBER_CALLBACK_SCENES_CLUSTER_VIEW_SCENE_RESPONSE
#define EMBER_CALLBACK_ENERGY_SCAN_RESULT
#define EMBER_CALLBACK_SCAN_COMPLETE
#define EMBER_CALLBACK_NETWORK_FOUND
/**** Debug printing section ****/

// Global switch
#define EMBER_AF_PRINT_ENABLE

#define EMBER_AF_SUPPORT_COMMAND_DISCOVERY

// Generated plugin macros

// Use this macro to check if Antenna Stub plugin is included
#define EMBER_AF_PLUGIN_ANTENNA_STUB

// Use this macro to check if Binding Table Library plugin is included
#define EMBER_AF_PLUGIN_BINDING_TABLE_LIBRARY
// User options for plugin Binding Table Library
#define EMBER_BINDING_TABLE_SIZE 10

// Use this macro to check if CCM* Encryption plugin is included
#define EMBER_AF_PLUGIN_CCM_ENCRYPTION
// User options for plugin CCM* Encryption
#define EMBER_AF_PLUGIN_CCM_ENCRYPTION_SOFTWARE_CCM
#define USE_SOFTWARE_CCM

// Use this macro to check if Radio Coexistence Stub plugin is included
#define EMBER_AF_PLUGIN_COEXISTENCE_STUB

// Use this macro to check if Debug Basic Library plugin is included
#define EMBER_AF_PLUGIN_DEBUG_BASIC_LIBRARY

// Use this macro to check if Debug JTAG plugin is included
#define EMBER_AF_PLUGIN_DEBUG_JTAG

// Use this macro to check if Ember Minimal Printf plugin is included
#define EMBER_AF_PLUGIN_EMBER_MINIMAL_PRINTF

// Use this macro to check if HAL Library plugin is included
#define EMBER_AF_PLUGIN_HAL_LIBRARY

// Use this macro to check if mbed TLS plugin is included
#define EMBER_AF_PLUGIN_MBEDTLS
// User options for plugin mbed TLS
#define EMBER_AF_PLUGIN_MBEDTLS_CONF_DEVICE_ACCELERATION
#define EMBER_AF_PLUGIN_MBEDTLS_CONF_DEVICE_ACCELERATION_APP

// Use this macro to check if Network Steering plugin is included
#define EMBER_AF_PLUGIN_NETWORK_STEERING
// User options for plugin Network Steering
#define EMBER_AF_PLUGIN_NETWORK_STEERING_CHANNEL_MASK 0x0318C800
#define EMBER_AF_PLUGIN_NETWORK_STEERING_RADIO_TX_POWER 3
#define EMBER_AF_PLUGIN_NETWORK_STEERING_SCAN_DURATION 4
#define EMBER_AF_PLUGIN_NETWORK_STEERING_COMMISSIONING_TIME_S 180
#define EMBER_AF_PLUGIN_NETWORK_STEERING_OPTIMIZE_SCANS

// Use this macro to check if NVM3 Library plugin is included
#define EMBER_AF_PLUGIN_NVM3
// User options for plugin NVM3 Library
#define EMBER_AF_PLUGIN_NVM3_FLASH_PAGES 18
#define EMBER_AF_PLUGIN_NVM3_CACHE_SIZE 200
#define EMBER_AF_PLUGIN_NVM3_MAX_OBJECT_SIZE 254
#define EMBER_AF_PLUGIN_NVM3_USER_REPACK_HEADROOM 0

// Use this macro to check if Packet Validate Library plugin is included
#define EMBER_AF_PLUGIN_PACKET_VALIDATE_LIBRARY

// Use this macro to check if RAIL Library plugin is included
#define EMBER_AF_PLUGIN_RAIL_LIBRARY
// User options for plugin RAIL Library
#define EMBER_AF_PLUGIN_RAIL_LIBRARY_RAILPHYDEF 1

// Use this macro to check if Scan Dispatch plugin is included
#define EMBER_AF_PLUGIN_SCAN_DISPATCH
// User options for plugin Scan Dispatch
#define EMBER_AF_PLUGIN_SCAN_DISPATCH_SCAN_QUEUE_SIZE 10

// Use this macro to check if Serial plugin is included
#define EMBER_AF_PLUGIN_SERIAL

// Use this macro to check if Simulated EEPROM version 2 to NVM3 Upgrade Stub plugin is included
#define EMBER_AF_PLUGIN_SIM_EEPROM2_TO_NVM3_UPGRADE_STUB

// Use this macro to check if Simple Main plugin is included
#define EMBER_AF_PLUGIN_SIMPLE_MAIN

// Use this macro to check if Strong Random plugin is included
#define EMBER_AF_PLUGIN_STRONG_RANDOM
// User options for plugin Strong Random
#define EMBER_AF_PLUGIN_STRONG_RANDOM_RADIO_PRNG
#define USE_RADIO_API_FOR_TRNG

// Use this macro to check if Update TC Link Key plugin is included
#define EMBER_AF_PLUGIN_UPDATE_TC_LINK_KEY
// User options for plugin Update TC Link Key
#define EMBER_AF_PLUGIN_UPDATE_TC_LINK_KEY_MAX_ATTEMPTS 3

// Use this macro to check if ZCL Framework Core plugin is included
#define EMBER_AF_PLUGIN_ZCL_FRAMEWORK_CORE
// User options for plugin ZCL Framework Core
#define EMBER_AF_PLUGIN_ZCL_FRAMEWORK_CORE_CLI_ENABLED
#define ZA_CLI_FULL

// Use this macro to check if ZigBee PRO Stack Library plugin is included
#define EMBER_AF_PLUGIN_ZIGBEE_PRO_LIBRARY
// User options for plugin ZigBee PRO Stack Library
#define EMBER_MAX_END_DEVICE_CHILDREN 6
#define EMBER_PACKET_BUFFER_COUNT 75
#define EMBER_END_DEVICE_KEEP_ALIVE_SUPPORT_MODE EMBER_KEEP_ALIVE_SUPPORT_ALL
#define EMBER_END_DEVICE_POLL_TIMEOUT MINUTES_256
#define EMBER_END_DEVICE_POLL_TIMEOUT_SHIFT 6
#define EMBER_LINK_POWER_DELTA_INTERVAL 300
#define EMBER_APS_UNICAST_MESSAGE_COUNT 10
#define EMBER_BROADCAST_TABLE_SIZE 15
#define EMBER_NEIGHBOR_TABLE_SIZE 16

// Generated API headers

// API antenna from Antenna Stub plugin
#define EMBER_AF_API_ANTENNA                                                                                                       \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/base/hal/plugin/antenna/antenna.h"

// API coexistence from Radio Coexistence Stub plugin
#define EMBER_AF_API_COEXISTENCE                                                                                                   \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/radio/rail_lib/plugin/coexistence/protocol/"         \
    "ieee802154/coexistence-802154.h"

// API network-steering from Network Steering plugin
#define EMBER_AF_API_NETWORK_STEERING                                                                                              \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/protocol/zigbee/app/framework/plugin/network-steering/"       \
    "network-steering.h"

// API nvm3 from NVM3 Library plugin
#define EMBER_AF_API_NVM3                                                                                                          \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/base/hal/plugin/nvm3/nvm3-token.h"

// API rail-library from RAIL Library plugin
#define EMBER_AF_API_RAIL_LIBRARY                                                                                                  \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/radio/rail_lib/common/rail.h"

// API scan-dispatch from Scan Dispatch plugin
#define EMBER_AF_API_SCAN_DISPATCH                                                                                                 \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/protocol/zigbee/app/framework/plugin/scan-dispatch/"          \
    "scan-dispatch.h"

// API serial from Serial plugin
#define EMBER_AF_API_SERIAL                                                                                                        \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/base/hal/plugin/serial/serial.h"

// API update-tc-link-key from Update TC Link Key plugin
#define EMBER_AF_API_UPDATE_TC_LINK_KEY                                                                                            \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/protocol/zigbee/app/framework/plugin/update-tc-link-key/"     \
    "update-tc-link-key.h"

// API command-interpreter2 from ZCL Framework Core plugin
#define EMBER_AF_API_COMMAND_INTERPRETER2                                                                                          \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/protocol/zigbee/app/util/serial/command-interpreter2.h"

// Custom macros
#ifdef TRANSITION_TIME_DS
#undef TRANSITION_TIME_DS
#endif
#define TRANSITION_TIME_DS 20

#ifdef FINDING_AND_BINDING_DELAY_MS
#undef FINDING_AND_BINDING_DELAY_MS
#endif
#define FINDING_AND_BINDING_DELAY_MS 3000

#endif // SILABS_ZNET_CONFIG

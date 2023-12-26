# Power Wakeup Action Source Customization

## Overview

### Introduction

OpenHarmony provides the function of waking up the system in sleep mode to take expected actions. For example, when the battery level is low, OpenHarmony can wake up the system to shut down the device. When the system is in the sleep state, it can be woken up based on the configuration policy to perform the scheduled action. However, supported application scenarios may vary according to products. For example, wakeup at low battery level may not be supported by certain products. To address this issue, OpenHarmony provides the function that allows you to customize power wakeup action sources depending on your product specifications.

### Constraints

 
Required adaptation:

- Triggering a power button event when the wakeup condition is met (for example, the battery level is lower than the specified threshold).
- Saving the wakeup reason (for example, wakeup due to low battery level) to the kernel node.

Configuration rule:
The configuration path for power wakeup action source customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

Hardware requirements:

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

Environment requirements:

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate post-wakeup system action customization.

1. Create the `power_manager` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default folder of power wakeup action source configuration](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile), and install it in `/vendor/hihope/rk3568/power_manager`. The content is as follows:

    ```text
    profile
    ├── BUILD.gn
    ├── power_wakeup_action.json
    ```

3. Write the custom `power_wakeup_action.json` file, which contains the custom wakeup reasons and actions as follows:

    ```json
    {
        "53": {
            "scene": "LowCapacity",
            "action": 2,
            "description": "(such as)53 is a uniquely wakeup reason by reading node through HDI interface(GetWakeupReason)"
        }
    }
    ```

    **Table 1** Description of wakeup sources

    | Wakeup Source| Description|
    | -------- | -------- |
    | 53 | Wakeup due to low battery level.|

    The wakeup source can be obtained by reading node data or by other ways.

    **Table 2** Description of wakeup scenarios

    | Wakeup Scenario| Description|
    | -------- | -------- |
    | LowCapacity | Low battery level.|

    **Table 3** Description of actions

    | action | Value| Description|
    | -------- | -------- | -------- |
    | ACTION_NONE | 0 | No action|
    | ACTION_HIBERNATE | 1 | Hibernation|
    | ACTION_SHUTDOWN | 2 | Shutdown|

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn) file in the default folder of power wakeup action source configuration to pack the `power_wakeup_action.json` file to the `/vendor/etc/power_wakeup_action` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")               # Reference build/ohos.gni.

    ohos_prebuilt_etc("wakeup_action_config") {
        source = "power_wakeup_action.json"
        relative_install_dir = "power_config"
        install_images = [ chipset_base_dir ] # Required configuration for installing the battery_config.json file in the vendor directory.
        part_name = "product_rk3568"          # Set part_name to product_rk3568 for subsequent build.
    }
    ```

5. Add the build target to `module_list` in [ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build) in the `/vendor/hihope/rk3568` directory. For example:

    ```json
    {
        "parts": {
            "product_rk3568": {
                "module_list": [
                    "//vendor/hihope/rk3568/default_app_config:default_app_config",
                    "//vendor/hihope/rk3568/image_conf:custom_image_conf",
                    "//vendor/hihope/rk3568/preinstall-config:preinstall-config",
                    "//vendor/hihope/rk3568/resourceschedule:resourceschedule",
                    "//vendor/hihope/rk3568/etc:product_etc_conf",
                    "//vendor/hihope/rk3568/power_manager/profile:wakeup_action_config" // Add the configuration for building of wakeup_action_config.
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/power_manager/` is the folder path, `profile` is the folder name, and `wakeup_action_config` is the build target.

6. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. Customize power wakeup action sources in the new configuration file.
    ```json
    {
        "53": {
            "scene": "LowCapacity",
            "action": 2,
            "description": "(such as)53 is a uniquely wakeup reason by reading node through HDI interface(GetWakeupReason)"
        }
    }
    ```

2. In the [powermgr.gni](https://gitee.com/openharmony/powermgr_power_manager/blob/master/powermgr.gni) file, set **power_manager_feature_wakeup_action** to **true** to enable the feature.
    ```
    power_manager_feature_wakeup_action = true
    ```
    
3. Add the following configuration to the [battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json) file:
    ```json
    "charge_scene": {
        "low_battery_thers": {
          "set": {
            "path": "xxx"
          }
        }
    }
    ```
    In the preceding configuration, **path** indicates the path of the node that stores the low battery threshold.

4. In the [batterymgr.gni](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/batterymgr.gni) file, set **battery_manager_feature_set_low_capacity_threshold** to **true** to enable the feature.
    ```
    battery_manager_feature_set_low_capacity_threshold = true
    ```    
5. Add the following configuration to the [power_config.json](https://gitee.com/openharmony/drivers_peripheral/blob/master/power/interfaces/hdi_service/profile/power_config.json) file:
    ```json
    {
        "scene" :{
            "wakeuo_cause": {
                "get": {
                    "path": "yyy"
                }
            }
        }
    }
    ```
    In the preceding configuration, **get** indicates the path of the node that stores the low battery wakeup reason.

5. In the [power.gni](https://gitee.com/openharmony/drivers_peripheral/blob/master/power/power.gni) file, set **drivers_peripheral_power_wakeup_cause_path** to **true** to enable the feature.
    ```
    drivers_peripheral_power_wakeup_cause_path = true
    ```
6. Change the node permission to **system** in the **pre-init** field of the [hdf_peripheral.cfg](https://gitee.com/openharmony/drivers_peripheral/blob/master/base/hdf_peripheral.cfg) file.
    ```
    "chown system system xxx",
    "chown system system yyy",
    ```
7. Decrease the battery level to fall below the specified threshold when the system is in the sleep state.

    The device is shut down.

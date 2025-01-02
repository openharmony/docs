# Charging Current and Voltage Limit Customization

## Overview

### Introduction

By default, OpenHarmony supports setting of charging current and voltage limits. When a device is being charged, the battery temperature may become excessively high due to the impact of ambient environment. In such a case, the charging current or voltage needs to be limited to ensure safety use of the device. However, the impact of charging current or voltage on device safety varies according to product specifications. To address this issue, OpenHarmony provides the function of customizing charging current and voltage limits.

### Constraints

 
The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate charging current and voltage limit configuration.

1. Create the `battery` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default folder of charging current and voltage limit configuration](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile), and install it in `//vendor/hihope/rk3568/battery`. The content is as follows:

    ```text
    profile
    ├── BUILD.gn
    ├── battery_config.json
    ```

3. Write the custom `battery_config.json` file by referring to the [battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json) file in the default folder of charging current and voltage limit configuration. For example:

    ```json
    {
        "charger": {
            "current_limit":{
                "path": "/data/service/el0/battery/current_limit"
            },
            "voltage_limit":{
                "path": "/data/service/el0/battery/voltage_limit"
            }
        }
    }
    ``` 

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/BUILD.gn) in the default folder of charging current and voltage limit configuration to pack the `battery_config.json` file to the `//vendor/etc/battery` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")                # Reference build/ohos.gni.

    ohos_prebuilt_etc("battery_config") {
        source = "battery_config.json"
        relative_install_dir = "battery"
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
            "//vendor/hihope/rk3568/battery/profile:battery_config" # Add the configuration for building of battery_config.
        ]
        }
    },
    "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/battery/` is the folder path, `profile` is the folder name, and `battery_config` is the build target.

6. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. Build the battery-specific hats test cases. For details about the build commands and framework setup, see [XTS Subsystem](https://gitee.com/openharmony/xts_hats).

2. Run the test cases, and check the test report.

    ![battery_limit_current_test_report](figures/battery_limit_current_test_report.jpg)

## Reference

During development, you can refer to the [default charging current and voltage configuration](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json), as shown below:

 

```json
{
    "charger": {
        "current_limit":{
            "path": "/data/service/el0/battery/current_limit"
        },
        "voltage_limit":{
            "path": "/data/service/el0/battery/voltage_limit"
        }
    }
}
```

Packing path: /system/etc/battery

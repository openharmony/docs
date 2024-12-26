# Default Hibernation Behavior Customization

## Overview

### Introduction

By default, after a device screen is turned off, OpenHarmony starts the running lock loop detection thread and then enters the hibernation state. For different devices, the mode of turning off the screen is different, which can be closing the lid, setting a timeout, covering the screen, or pressing the power button. Besides, the default hibernation behavior is also different, which can be performing no action, powering off the screen, or entering the hibernation state. To address this issue, OpenHarmony provides the default hibernation behavior customization function, allowing you to customize the default hibernation behavior depending on your hardware specifications.

### Constraints

The configuration paths for battery level customization are subject to the configuration policy.
The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate default hibernation behavior customization.

1. Create the `power_manager` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default folder of hibernation behavior configuration](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile), and install it in `/vendor/hihope/rk3568/power_manager`. The content is as follows:

    ```text
    profile
    ├── BUILD.gn
    ├── power_suspend.json
    ```

3. Write the custom `power_suspend.json` file that contains the custom default hibernation behavior. The following is an example of hibernation behavior configuration:

    ```json
    {
        "powerkey": {
            "action": 1,
            "delayMs": 0
        },
        "timeout": {
            "action": 1,
            "delayMs": 0
        },
        "lid": {
            "action": 1,
            "delayMs": 0
        },
        "switch": {
            "action": 1,
            "delayMs": 0
        },
        "tp_cover": {
            "action": 1,
            "delayMs": 0
        }
    }
    ```

    **Table 1** Description of hibernation sources

    | Hibernation Source| Description|
    | -------- | -------- |
    | powerkey | Hibernation by power button|
    | timeout | Hibernation by timeout|
    | lid | Hibernation by lid|
    | switch | Hibernation by switch|
    | tp_cover | Hibernation by screen covering|

    **Table 2** Description of the hibernation source configuration

    | Item| Description|
    | -------- | -------- |
    | action | Action to take after the screen is turned off. Set this parameter to an enumerated value. For details, see Table 3.|
    | delayMs | Delay, in ms.|

    **Table 3** Description of action

    | action | Value| Description|
    | -------- | -------- | -------- |
    | ACTION_NONE | 0 | No action.|
    | ACTION_AUTO_SUSPEND | 1 | Automatically entering the sleep mode.|
    | ACTION_FORCE_SUSPEND | 2 | Forcibly entering the sleep mode.|
    | ACTION_HIBERNATE | 3 | Entering the hibernation state.|
    | ACTION_SHUTDOWN | 4 | Shutting down the system.|

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn) file in the default folder of hibernation behavior configuration to pack the `power_suspend.json` file to the `/vendor/etc/power_config` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")               # Reference build/ohos.gni.

    ohos_prebuilt_etc("suspend_config") {
        source = "power_suspend.json"
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
                    "//vendor/hihope/rk3568/power_manager/profile:wakeup_config" // Add the configuration for building of suspend_config.
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/power_manager/` is the folder path, `profile` is the folder name, and `suspend_config` is the build target.

6. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. Customize hibernation sources in the `power_suspend.json` file.
    ```json
    {
        "powerkey": {
            "action": 4,
            "delayMs": 0
        },
        "timeout": {
            "action": 1,
            "delayMs": 0
        },
        "lid": {
            "action": 1,
            "delayMs": 0
        },
        "switch": {
            "action": 1,
            "delayMs": 0
        },
        "tp_cover": {
            "action": 1,
            "delayMs": 0
        }
    }
    ```

2. Power on the device, and then press the power button.

    The device is powered off.

3. Power on the device again, and then wait for a while.

    The device screen is turned off.

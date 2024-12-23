# Wakeup Source Customization

## Overview

### Introduction

OpenHarmony supports multiple wakeup sources, such as the power button, keyboard, and mouse, and provides custom modes for turning on and off these wakeup sources. After a device enters the sleep state, you can turn on the screen and wake up the device by touching the power button, keyboard, mouse, or screen. However, different products may support different peripherals, for example, stylus or folio keyboard. To address this issue, OpenHarmony provides the wakeup source customization function, allowing you to customize wakeup sources depending on your hardware specifications.

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

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate wakeup source customization.

1. Create the `power_manager` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default folder of wakeup source configuration](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile), and install it in `/vendor/hihope/rk3568/power_manager`. The content is as follows:

    ```text
    profile
    ├── BUILD.gn
    ├── power_wakeup.json
    ```

3. Write the custom `power_wakeup.json` file that contains the custom wakeup sources. The following is an example of wakeup source configuration:

    ```json
    {
        "powerkey": {
            "enable": true
        },
        "keyborad": {
            "enable": true
        },
        "mouse": {
            "enable": true
        },
        "touchscreen": {
            "enable": true,
            "click": 2
        },
        "touchpad": {
            "enable": true
        },
        "pen": {
            "enable": true
        },
        "lid": {
            "enable": true
        },
        "switch": {
            "enable": true
        },
        "tp_touch": {
            "enable": true
        }
    }
    ```

    **Table 1** Description of wakeup sources

    | Wakeup Source| Description|
    | -------- | -------- |
    | powerkey | Wakeup by power button|
    | keyborad | Wakeup by keyboard|
    | mouse | Wakeup by mouse|
    | touchscreen | Wakeup by touchscreen|
    | touchpad | Wakeup by touchpad|
    | pen | Wakeup by stylus|
    | lid | Wakeup by lid|
    | switch | Wakeup by switch|
    | tp_touch | Wakeup by touch|

    **Table 2** Description of the wakeup source configuration

    | Item| Type| Description|
    | -------- | -------- | -------- |
    | enable | bool | Whether to enable wakeup listening|
    | click | int | Number of clicks|


4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn) file in the default folder of wakeup source configuration to pack the `power_wakeup.json` file to the `/vendor/etc/power_config` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")               # Reference build/ohos.gni.

    ohos_prebuilt_etc("wakeup_config") {
        source = "power_wakeup.json"
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
                    "//vendor/hihope/rk3568/power_manager/profile:wakeup_config" // Add the configuration for building of wakeup_config.
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/power_manager/` is the folder path, `profile` is the folder name, and `wakeup_config` is the build target.

6. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

> **NOTE**
> 
> Currently, the Double-tap to wake feature is not supported. That is, **enable** in **touchscreen** can only be set to **false**. This feature will be provided in later versions.

1. Customize wakeup sources in the `power_wakeup.json` file.
    ```json
    {
        "powerkey": {
            "enable": true
        },
        "keyborad": {
            "enable": true
        },
        "mouse": {
            "enable": true
        },
        "touchscreen": {
            "enable": false,
            "click": 2
        },
        "touchpad": {
            "enable": false
        },
        "pen": {
            "enable": false
        },
        "lid": {
            "enable": false
        },
        "switch": {
            "enable": false
        },
        "tp_touch": {
            "enable": false
        }
    }
    ```

2. After the device is powered on, press the power button to switch the device to the sleep mode. Then, press the power button again.

    The device screen is turned on and the device is woken up.

3. Press the power button to switch the device to the sleep mode, and then press the keyboard.

    The device screen is turned on and the device is woken up.

4. Press the power button to switch the device to the sleep mode, and then move the mouse.

    The device screen is turned on and the device is woken up.

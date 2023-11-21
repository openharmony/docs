# Thermal Scene Customization

## Overview

### Introduction

By default, OpenHarmony provides the thermal scene feature. During device usage, for example, gaming, photographing, or calling, the system will try to balance the performance, temperature, and power consumption. The thermal policy is usually scenario-specific. For example, the thermal policy in the gaming scenario does not decrease the screen brightness. However, the thermal scene definition varies according to product specifications. To address this issue, OpenHarmony provides the thermal scene customization function.

### Constraints

The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate thermal scene customization.

1. Create the `thermal` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default thermal scene configuration folder](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile), and install it in `//vendor/hihope/rk3568/thermal`. The content is as follows:
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. Write the custom `thermal_service_config.xml` file by referring to the [thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml) file in the default thermal scene configuration folder. The following table describes the related configuration items.

    **Table 1** Configuration items for the thermal scene

    | Configuration Item| Description| Parameter| Parameter Description| Parameter Type| Value Range|
    | -------- | -------- | -------- | -------- | -------- | -------- |
    | name="scene" | One or more thermal scenes specified by enum values.| param | Available thermal scenes: photographing, calling, and gaming.| enum | cam, call, and game|

    **screen** and **charge** indicate the thermal status of the application; and specifically, whether the screen is turned on and whether the battery is being charged.
    
    ```shell
    <state>
        <item name="scene" param="cam,call,game"/>
        <item name="screen"/>
        <item name="charge"/>
    </state>
    ```
4. An external system can call the **UpdateThermalState** API of the thermal service to set the thermal status.
```cpp
bool UpdateThermalState(const std::string& tag, const std::string& val, bool isImmed = false)
```
| Parameter| Description| Type|
|---|---|---|
| tag | Scenario tag.| string |
| val | Scenario status value.| string |
| isImmed | Whether to update the thermal control action value immediately.| bool |

5. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn) file in the default thermal scene configuration folder to pack the `thermal_service_config.xml` file to the `/vendor/etc/thermal_config` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")                      # Reference build/ohos.gni.

    ohos_prebuilt_etc("thermal_service_config") {
        source = "thermal_service_config.xml"
        relative_install_dir = "thermal_config"
        install_images = [ chipset_base_dir ]       # Required configuration for installing the thermal_service_config.xml file in the vendor directory.
        part_name = "product_rk3568"                # Set part_name to product_rk3568 for subsequent build. You can change it as required.
    }
    ```

6. Add the build target to `module_list` in [ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build). For example:

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
                    "//vendor/hihope/rk3568/thermal/profile:thermal_service_config", // Add the configuration for building of thermal_service_config.
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/thermal/` is the folder path, `profile` is the folder name, and `thermal_service_config` is the build target.

7. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

8. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. After startup, run the following command to launch the shell command line:
    ```shell
    hdc shell
    ```

2. Obtain the current thermal scene information.
    ```shell
    hidumper -s 3303 -a -s
    ```

    The following is the reference thermal scene result after customization:
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    name: scene  params: cam,call,game
    name: screen
    name: charge
    ```

## Reference
During development, you can refer to the [default thermal scene configuration](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml).

Packing path: `/vendor/etc/thermal_config/hdf`

# Charging Idle State Customization

## Overview

### Introduction

By default, OpenHarmony provides the charging idle state feature. It determines whether a device is currently in the idle state according to a thermal level, battery level, charging state, and charging current of the device. A device in this state may execute some background intensive tasks. However, the conditions that determine the charging idle state vary according to product specifications. To address this issue, OpenHarmony provides the charging idle state customization function.

### Constraints

The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate charging idle state customization.

1. Create the `thermal` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default folder of battery idle state configuration](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile), and install it in `//vendor/hihope/rk3568/thermal`. The content is as follows:
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. Write the custom `thermal_service_config.xml` file by referring to the [thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml) file in the default folder of charging idle state configuration. The following table describes the related configuration items.

    **Table 1** Configuration items for the charging idle state
    
    | Configuration Item| Description| Data Type| Value Range|
    | -------- | -------- | -------- | -------- |
    | thermallevel | Thermal level threshold| int | This field is defined based on the thermal level of a device. If the thermal level of a device is less than or equal to the threshold, the device is in the charging idle state.|
    | soc | Battery level threshold| int | The value of this field ranges from 0 to 100. If the battery level of the device is greater than or equal to the specified threshold, the device is in the charging idle state.|
    | charging | Charging status| int | The value **1** indicates that the battery is being charged, and the value **0** indicates the opposite.|
    | current | Battery charging current threshold| int | When the battery charging current is greater than or equal to the specified threshold (in mA), the battery is in the charging idle state.|

    ```shell
    <idle name="charging">
        <thermallevel>1</thermallevel>
        <soc>90</soc>
        <charging>1</charging>
        <current>1000</current>
    </idle>
    ```

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn) file in the default folder of charging idle state configuration to pack the `thermal_service_config.xml` file to the `/vendor/etc/thermal_config` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")                      # Reference build/ohos.gni.

    ohos_prebuilt_etc("thermal_service_config") {
        source = "thermal_service_config.xml"
        relative_install_dir = "thermal_config"
        install_images = [ chipset_base_dir ]       # Required configuration for installing the thermal_service_config.xml file in the vendor directory.
        part_name = "product_rk3568"                # Set part_name to product_rk3568 for subsequent build. You can change it as required.
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
                    "//vendor/hihope/rk3568/thermal/profile:thermal_service_config", // Add the configuration for building of thermal_service_config.
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/thermal/` is the folder path, `profile` is the folder name, and `thermal_service_config` is the build target.

6. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. After startup, run the following command to launch the shell command line:
    ```shell
    hdc shell
    ```

2. Obtain the current charging idle state.
    ```shell
    hidumper -s 3303 -a -i
    ```

    The following is the reference charging idle state after customization:
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    thermallevel: 1
    soc: 100
    charging: 1
    current: 1000
    ```

## Reference
During development, you can refer to the [default charging idle state configuration](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml).

Packing path: `/vendor/etc/thermal_config/hdf`

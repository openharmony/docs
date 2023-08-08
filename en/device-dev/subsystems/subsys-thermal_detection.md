# Thermal Detection Customization

## Overview

### Introduction

By default, OpenHarmony provides the thermal detection feature. A component, for example, the CPU or battery, generates heat while it is running. In this case, the component reports its temperature in real time through the corresponding temperature sensor. The thermal detection feature detects the temperature of components in real time and provides temperature input for the thermal management module. However, thermal detection on components varies according to product specifications. To address this issue, OpenHarmony provides the thermal detection customization function.

### Constraints

The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate thermal detection customization.

1. Create the `thermal` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default thermal detection configuration folder](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/interfaces/hdi_service/profile), and install it in `//vendor/hihope/rk3568/thermal`. The content is as follows:
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_hdi_config.xml
    ```

3. Write the custom `thermal_hdi_config.xml` file by referring to the [thermal_hdi_config.xml](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/thermal_hdi_config.xml) file in the default thermal detection configuration folder. The following table describes the related configuration items.

    **Table 1** Configuration items for thermal detection

    |Node| Configuration Item| Description| Value Type|
    | -------- | -------- | -------- | -------- |
    | item | tag | Temperature flag name of an actual or simulated node.| string |
    | item | value | Temperature flag value. Value **1** means to obtain the temperature of a simulated node, and the value **0**, means to obtain the temperature of an actual node.| int |
    | group | name | Name of the actual or simulated node group.| string |
    | group | interval | Polling interval, in ms (default).| int |
    | thermal_zone | type | Thermal zone name.| string |
    | thermal_zone | path | Path for obtaining the thermal zone temperature of an actual node.| string |
    | thermal_node | type | Thermal node name.| string |
    | thermal_node | path | Path for obtaining the thermal node temperature of a simulated node.| string |

    ```shell
    <base>
        <item tag="sim_tz" value="0"/>
    </base>

    <polling>
        <group name="actual" interval="30000">
            <thermal_zone type="soc-thermal" path="sys/class/thermal/thermal_zone0/temp"/>
            <thermal_zone type="gpu-thermal" path="sys/class/thermal/thermal_zone0/temp"/>
        </group>
        <group name="sim" interval="30000">
            <thermal_node type="soc" path="data/service/el0/thermal/sensor/soc/temp"/>
            <thermal_node type="cpu" path="data/service/el0/thermal/sensor/cpu/temp"/>
            <thermal_node type="ap" path="data/service/el0/thermal/sensor/ap/temp"/>
            <thermal_node type="pa" path="data/service/el0/thermal/sensor/pa/temp"/>
            <thermal_node type="ambient" path="data/service/el0/thermal/sensor/ambient/temp"/>
            <thermal_node type="charger" path="data/service/el0/thermal/sensor/charger/temp"/>
            <thermal_node type="battery" path="data/service/el0/thermal/sensor/battery/temp"/>
            <thermal_node type="shell" path="data/service/el0/thermal/sensor/shell/temp"/>
        </group>
    </polling>
    ```
    For details about the path for obtaining the actual node temperature, see the path for obtaining the thermal zone temperature in [Thermal Log](../subsystems/subsys-thermal_log.md). For details about the path for obtaining the simulated node temperature, see [Default Thermal Detection Configuration](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/thermal_hdi_config.xml).

5. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/BUILD.gn) file in the default thermal detection configuration folder to pack the `thermal_hdi_config.xml` file to the `//vendor/etc/thermal_config/hdf` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")

    ohos_prebuilt_etc("thermal_hdf_config") {
        source = "thermal_hdi_config.xml"
        relative_install_dir = "thermal_config/hdf"
        install_images = [ chipset_base_dir ]       # Required configuration for installing the thermal_hdi_config.xml file in the vendor directory.
        part_name = "product_rk3568"                # Set part_name to product_rk3568 for subsequent build. You can change it as required.
    }
    ```

6. Add the build target to `module_list` in [ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build) in the `/vendor/hihope/rk3568` directory. For example:

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
                    "//vendor/hihope/rk3568/thermal/profile:thermal_hdf_config", // Add the configuration for building of thermal_hdf_config.
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/thermal/` is the folder path, `profile` is the folder name, and `thermal_hdf_config` is the build target.

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

2. Obtain the thermal detection result of the thermal zone.
    ```shell
    hidumper -s 3303 -a -t
    ```

    The following is the reference thermal detection result of the thermal zone. The value of **Temperature** is in unit of 0.001°C by default.
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    ········· (Only the thermal detection result is displayed here. Other information is omitted.)
    Type: gpu-thermal
    Temperature: 35555
    Type: soc-thermal
    Temperature: 35000
    ······
    ```

## Reference
During development, you can refer to the [default thermal detection configuration](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/thermal_hdi_config.xml).

Packing path: `/vendor/etc/thermal_config/hdf`

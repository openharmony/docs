# Thermal Level Customization

## Overview

### Introduction

By default, OpenHarmony provides the thermal level feature. Different hardware devices generate different amounts of heat and can tolerate different maximum temperatures. Therefore, for different components, the thermal level standard needs to be defined based on their temperatures to clearly indicate the thermal status and provide input for thermal control. However, the thermal level of components at different temperatures varies according to product specifications. To address this issue, OpenHarmony provides the thermal level customization function.

### Constraints

The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate thermal level customization.

1. Create the `thermal` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default thermal level configuration folder](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile), and install it in `//vendor/hihope/rk3568/thermal`. The content is as follows:
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. Write the custom `thermal_service_config.xml` file by referring to the [thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml) file in the default thermal level configuration folder. The following tables describe the related configuration items.

    **Table 1** Description of the base configuration
    | Configuration Item| Description| Parameter| Parameter Description| Type| Value Range|
    | -------- | -------- | -------- | -------- | -------- | -------- |
    | tag="history_temp_count" | Name of the tag indicating the number of historical temperature reporting times.| value | Number of historical temperature reporting times.| int | >0 |
    | tag="temperature_query_enum" | Tag name of the device list for obtaining the temperature.| value | Device list for obtaining the temperature.| enum | soc, battery, shell, cpu, charger, ambient, ap, and pa|


    **Table 2** Description of the sensor_cluster configuration

    | Configuration Item | Description | Data Type | Value Range |
    | -------- | -------- | -------- | -------- |
    | name | Sensor cluster name | string | None |
    | sensor | Sensors in the cluster | string | soc, battery, shell, cpu, charger, ambient, ap, and pa |
    | aux_sensor | Auxiliary sensors in the cluster | string | soc, battery, shell, cpu, charger, ambient, ap, and pa |

    **Table 3** Description of the item configuration

    | Configuration Item | Description | Data Type | Value Range |
    | -------- | -------- | -------- | -------- |
    | level | Thermal level defined for each sensor cluster | int | >0 |
    | threshold | Temperature threshold for each sensor in the cluster to reach the corresponding thermal level. The value is in unit of 0.001°C by default and can be changed as needed. | int | Product-specific |
    | threshold_clr | Temperature threshold for each sensor in the cluster to roll back to the previous thermal level. | int | Product-specific |
    | temp_rise_rate | Temperature rise frequency. | double | Product-specific |

    ```shell
    <thermal version="0.01" product="lya">
    <base>
        <item tag="history_temp_count" value="10"/>
        <item tag="temperature_query_enum" value="soc,battery,shell,cpu,charger,ambient,ap,pa"/>
    </base>

    <level>
        <sensor_cluster name="base_safe" sensor="battery,charger,cpu,soc">
            <item level="1" threshold="42000,40000,30000,40000" threshold_clr="38000,36000,28000,38000"/>
            <item level="2" threshold="43000,41000,32000,42000" threshold_clr="41000,39000,30000,40000"/>
            <item level="3" threshold="46000,44000,34000,44000" threshold_clr="44000,42000,32000,42000"/>
            <item level="4" threshold="48000,46000,36000,46000" threshold_clr="46000,44000,34000,44000"/>
        </sensor_cluster>
    </level>
    ```

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn) file in the default thermal level configuration folder to pack the `thermal_service_config.xml` file to the `/vendor/etc/thermal_config` directory. The configuration is as follows:

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

2. Go to the `data/service/el0/thermal/sensor/soc/` directory.
    ```shell
    cd data/service/el0/thermal/sensor/soc
    ```
    
3. Change the SOC temperature.
    ```shell
    echo 42000 > temp
    ```

4. Obtain the current thermal level information.
    ```shell
    hidumper -s 3303 -a -l
    ```

    The following is the reference thermal level information after customization:
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    name: base_safe	level: 2
    name: cold_safe	level: 0
    name: high_safe	level: 0
    name: warm_5G	level: 0
    name: warm_safe	level: 1
    ```

## Reference
During development, you can refer to the [default thermal level configuration](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml).

Packing path: `/vendor/etc/thermal_config/hdf`

# Thermal Policy Customization

## Overview

### Introduction

By default, the OpenHarmony provides the thermal policy feature. Various components on a device can generate heat. Therefore, for different components, the thermal policy needs to be defined based on their thermal levels and thermal scenes. However, thermal control at different thermal levels varies according to product specifications. To address this issue, OpenHarmony provides the thermal policy customization function.

### Constraints

The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate thermal policy customization.

1. Create the `thermal` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default thermal policy configuration folder](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile), and install it in `//vendor/hihope/rk3568/thermal`. The content is as follows:
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. Write the custom `thermal_service_config.xml` file by referring to the [thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml) file in the default thermal policy configuration folder. The following tables describe the related configuration items.

    **Table 1** Description of the config configuration

    | Configuration Item| Description| Type| Value Range|
    | -------- | -------- | -------- | -------- |
    | name | Name of the sensor cluster corresponding to the thermal policy.| string | Corresponding to the sensor cluster name defined in [Thermal Level](../subsystems/subsys-thermal_level.md).|
    | level | Thermal level corresponding to the thermal policy.| int | Corresponding to the thermal level defined for the sensor cluster in [Thermal Level](../subsystems/subsys-thermal_level.md).|
    
    **Table 2** Description of configuration items

    | Configuration Item| Description| Type| Value Range|
    | -------- | -------- | -------- | -------- |
    | scene	| Application scenario.| string | Corresponding to the application scenario defined in [Thermal Scene](../subsystems/subsys-thermal_scene.md).|
    | charge | Charging status.| int | The value **1** indicates charging, and the value **0** indicates the opposite.|
    | screen | Screen status.| int | The value **1** indicates that the screen is on, and the value **0** indicates the opposite.|

    **Table 3** Description of the node configuration

    | Node| Value Type| Value Range| Description|
    | -------- | -------- | -------- | -------- |
    | lcd | double | 0.00~1.00 | Percentage of the screen brightness (represented by a floating point number).|
    | cpu_big | int | Product-specific| CPU big core frequency.|
    | cpu_med | int | Product-specific| CPU medium-core frequency.|
    | cpu_lit | int | Product-specific| CPU small-core frequency.|
    | process_ctrl | enum | 1: KILL_FG_PROCESS_APP<br>2: KILL_BG_PROCESS_APP<br>3: KILL_ALL_PROCESS_APP| Process control.|
    | gpu | int | Product-specific| GPU frequency.|
    | thermallevel | int | Corresponding to **level** defined in the **config** node| Thermal level.|
    | current_sc | int | Product-specific| Fast charging current.|
    | current_buck | int | Product-specific| Slow charging current.|
    | voltage_sc | int | Product-specific| Fast charging voltage.|
    | voltage_buck | int | Product-specific| Slow charging voltage.|
    | volume | double | 0.00~1.00 | Volume percentage (represented by a floating point number).|

    ```shell
    <policy>
        <config name="base_safe" level="1">
            <lcd>1.00</lcd>
            <lcd scene="cam">0.99</lcd>
            <lcd scene="call">0.98</lcd>
            <lcd scene="game">0.95</lcd>
            <cpu_big>1992000</cpu_big>
            <cpu_med>1991500</cpu_med>
            <cpu_lit>1991200</cpu_lit>
            <process_ctrl>3</process_ctrl>
            <cpu_big scene="cam" charge="1">1991800</cpu_big>
            <cpu_big scene="cam" charge="0">1991600</cpu_big>
            <gpu screen="0">524288</gpu>
            <gpu screen="1">512000</gpu>
            <thermallevel>1</thermallevel>
            <current_sc>1800</current_sc>
            <current_sc scene="cam">1200</current_sc>
            <current_buck>1200</current_buck>
            <voltage_sc>4000</voltage_sc>
            <voltage_buck>3000</voltage_buck>
            <volume>1.0</volume>
        </config>
    <policy>
        <config name="base_safe" level="2">
            <lcd>0.90</lcd>
            <lcd scene="cam">0.89</lcd>
            <lcd scene="call">0.88</lcd>
            <lcd scene="game">0.87</lcd>
            <cpu_big>1991000</cpu_big>
            <cpu_med>1990500</cpu_med>
            <cpu_lit>1990200</cpu_lit>
            <process_ctrl>2</process_ctrl>
            <cpu_big scene="cam" charge="1">1990800</cpu_big>
            <cpu_big scene="cam" charge="0">1990600</cpu_big>
            <gpu screen="0">499712</gpu>
            <gpu screen="1">487424</gpu>
            <thermallevel>2</thermallevel>
            <current_sc>1500</current_sc>
            <current_sc scene="cam">1000</current_sc>
            <current_buck>1000</current_buck>
            <voltage_sc>3000</voltage_sc>
            <voltage_buck>2000</voltage_buck>
            <volume>0.8</volume>
        </config>
    </policy>
    ```

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn) file in the default thermal policy configuration folder to pack the `thermal_service_config.xml` file to the `/vendor/etc/thermal_config` directory. The configuration is as follows:

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

2. Obtain the current thermal policy information.
    ```shell
    hidumper -s 3303 -a -p
    ```

    The following is the reference thermal policy result after customization: 
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    name: base_safe	level: 1
    actionName: lcd	actionValue: 1.00	isProp: 0
    actionName: lcd	actionValue: 0.99	scene: cam	isProp: 1
    actionName: lcd	actionValue: 0.98	scene: call	isProp: 1
    actionName: lcd	actionValue: 0.95	scene: game	isProp: 1
    actionName: cpu_big	actionValue: 1992000	isProp: 0
    actionName: cpu_med	actionValue: 1991500	isProp: 0
    actionName: cpu_lit	actionValue: 1991200	isProp: 0
    actionName: process_ctrl	actionValue: 3	isProp: 0
    actionName: cpu_big	actionValue: 1991800	charge: 1	scene: cam	isProp: 1
    actionName: cpu_big	actionValue: 1991600	charge: 0	scene: cam	isProp: 1
    actionName: gpu	actionValue: 524288	screen: 0	isProp: 1
    actionName: gpu	actionValue: 512000	screen: 1	isProp: 1
    actionName: thermallevel	actionValue: 1	isProp: 0
    actionName: current_sc	actionValue: 1800	isProp: 0
    actionName: current_sc	actionValue: 1200	scene: cam	isProp: 1
    actionName: current_buck	actionValue: 1200	isProp: 0
    actionName: voltage_sc	actionValue: 4000	isProp: 0
    actionName: voltage_buck	actionValue: 3000	isProp: 0
    actionName: volume	actionValue: 1.0	isProp: 0
    actionName: boost	actionValue: 1	isProp: 0

    level: 2
    actionName: lcd	actionValue: 0.90	isProp: 0
    actionName: lcd	actionValue: 0.89	scene: cam	isProp: 1
    actionName: lcd	actionValue: 0.88	scene: call	isProp: 1
    actionName: lcd	actionValue: 0.87	scene: game	isProp: 1
    actionName: cpu_big	actionValue: 1991000	isProp: 0
    actionName: cpu_med	actionValue: 1990500	isProp: 0
    actionName: cpu_lit	actionValue: 1990200	isProp: 0
    actionName: process_ctrl	actionValue: 2	isProp: 0
    actionName: cpu_big	actionValue: 1990800	charge: 1	scene: cam	isProp: 1
    actionName: cpu_big	actionValue: 1990600	charge: 0	scene: cam	isProp: 1
    actionName: gpu	actionValue: 499712	screen: 0	isProp: 1
    actionName: gpu	actionValue: 487424	screen: 1	isProp: 1
    actionName: thermallevel	actionValue: 2	isProp: 0
    actionName: current_sc	actionValue: 1500	isProp: 0
    actionName: current_sc	actionValue: 1000	scene: cam	isProp: 1
    actionName: current_buck	actionValue: 1000	isProp: 0
    actionName: voltage_sc	actionValue: 3000	isProp: 0
    actionName: voltage_buck	actionValue: 2000	isProp: 0
    actionName: volume	actionValue: 0.8	isProp: 0
    actionName: boost	actionValue: 1	isProp: 0
    ```

## Reference
During development, you can refer to the [default thermal policy configuration](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml).

Packing path: `/vendor/etc/thermal_config/hdf`

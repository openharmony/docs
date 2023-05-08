# Battery Level Customization

## Overview

### Introduction

By default, OpenHarmony provides the battery level based on the current battery power, such as the full battery level, high battery level, low battery level, and extremely low battery level. It can generate an alert or take required service processing based on the current battery level. However, the battery level specifications vary according to products. To address this issue, OpenHarmony provides the function of customizing battery levels.

### Constraints

 
The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate battery level customization.

1. Create the `battery` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default folder of battery level configuration](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile), and install it in `//vendor/hihope/rk3568/battery`. The content is as follows:

    ```text
    profile
    ├── BUILD.gn
    ├── battery_config.json
    ```

3. Write the custom `battery_config.json` file by referring to the [battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json) file in the default folder of battery level configuration. For example:

    ```json
    {
        "soc": {
            "shutdown": 5,
            "critical": 10,
            "warning": 15,
            "low": 30,
            "normal": 60,
            "high": 90,
            "full": 100
        }
    }
    ``` 

    **Table 1** Battery level configuration

    | Battery Level| Battery Volume| Description|
    | -------- | -------- | -------- |
    | shutdown | 5 | Power-off battery level|
    | critical | 10 | Extremely low battery level|
    | warning | 15 | Alarm battery level|
    | low | 30 | Low battery level|
    | normal | 60 | Normal battery level|
    | high | 90 | High battery level|
    | full | 100 | Full battery level|


4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/BUILD.gn) file in the default folder of battery level configuration to pack the `battery_config.json` file to the `//vendor/etc/battery` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")               # Reference build/ohos.gni.

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

1. After startup, run the following command to launch the shell command line:
    ```
    hdc shell
    ```

2. Go to the custom battery level configuration directory. The path of DAYU200 is used as an example.
    ```
    cd /data/service/el0/battery/battery/
    ```

3. Modify the charging status, simulate reporting of the battery power change, and check whether the returned battery level is correct. The following uses the default charging type as an example.

    1. Modify the battery power.
    ```
    echo 100 > capacity
    ```
    2. Report the battery power change to obtain the current battery level.
    ```
    hidumper -s 3302 -a -i
    ```
    3. Check whether the battery level is correct.
    
    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:22:48.589

    ··· (Only the battery level configuration is displayed here. Other information is omitted.)

    batteryLevel: 1

    ······
    ```

    4. Modify the battery power.
    ```
    echo 90 > capacity
    ```
    5. Report the battery power change to obtain the current battery level.
    ```
    hidumper -s 3302 -a -i
    ```
    6. Check whether the battery level is correct.
    
    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:24:29.716

    ··· (Only the battery level configuration is displayed here. Other information is omitted.)

    batteryLevel: 2
    
    ······
    ```

    7. Modify the battery power.
    ```
    echo 60 > capacity
    ```
    8. Report the battery power change to obtain the current battery level.
    ```
    hidumper -s 3302 -a -i
    ```
    9. Check whether the battery level is correct.

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:25:09.837

    ··· (Only the battery level configuration is displayed here. Other information is omitted.)

    batteryLevel: 3
    
    ······
    ```

    10. Modify the battery power.
    ```
    echo 30 > capacity
    ```
    11. Report the battery power change to obtain the current battery level.
    ```
    hidumper -s 3302 -a -i
    ```
    12. Check whether the battery level is correct.

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:26:20.495

    ··· (Only the battery level configuration is displayed here. Other information is omitted.)

    batteryLevel: 4
    
    ······
    ```

    13. Modify the battery power.
    ```
    echo 15 > capacity
    ```
    14. Report the battery power change to obtain the current battery level.
    ```
    hidumper -s 3302 -a -i
    ```
    15. Check whether the battery level is correct.

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:27:05.312

    ··· (Only the battery level configuration is displayed here. Other information is omitted.)

    batteryLevel: 5
    
    ······
    ```

    16. Modify the battery power.
    ```
    echo 10 > capacity
    ```
    17. Report the battery power change to obtain the current battery level.
    ```
    hidumper -s 3302 -a -i
    ```
    18. Check whether the battery level is correct.

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:27:56.270

    ··· (Only the battery level configuration is displayed here. Other information is omitted.)

    batteryLevel: 6
    
    ······
    ```

    19. Modify the battery power.
    ```
    echo 5 > capacity
    ```
    20. Report the battery power change to obtain the current battery level.
    ```
    hidumper -s 3302 -a -i
    ```
    21. Check whether the battery level is correct.

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:28:38.066

    ··· (Only the battery level configuration is displayed here. Other information is omitted.)

    batteryLevel: 7
    
    ······
    ```

## Reference
During development, you can refer to the [default battery level configuration](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json), as shown below:

 

```json
{
    "soc": {
        "shutdown": 1,
        "critical": 5,
        "warning": 10,
        "low": 20,
        "normal": 90,
        "high": 99,
        "full": 100
    }
}
``` 

Packing path: /system/etc/battery

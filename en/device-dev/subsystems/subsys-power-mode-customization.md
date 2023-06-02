# Power Mode Customization

## Overview

### Introduction

By default, OpenHarmony provides the power mode feature, which offers the following options: normal mode, performance mode, power-saving mode, and super power-saving mode. However, the power mode configuration varies according to hardware specifications of different products. To address this issue, OpenHarmony provides the power mode customization function, allowing you to customize power modes depending on your hardware specifications.

### Basic Concepts

OpenHarmony supports the following four power modes, each of which corresponds to the specified power and performance policy.

- Normal mode: default power mode, in which the system brightness, screen-off time, and sleep time meet the requirements of most users.

- Performance mode: power mode that emphasizes on the performance, such as increasing the system brightness, disabling the screen-off time, and preventing the system from entering the sleep mode.

- Power-saving mode: power mode that emphasizes on power saving, such as decreasing the system brightness, reducing the screen-off time, and shortening the time for entering sleep mode.

- Super power-saving mode: power mode that emphasizes on ultimate power saving, such as greatly decreasing the system brightness, greatly reducing the screen-off time, and greatly shortening the time for entering sleep mode.


### Constraints

The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate power mode customization.

1. Create the `power_manager` folder in the product directory [vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default power mode configuration folder](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile), and install it in `//vendor/hihope/rk3568/power_manager`. The content is as follows:
     
    ```text
    profile
    ├── BUILD.gn
    ├── power_mode_config.xml
    ```

3. Write the custom `power_mode_config.xml` file by referring to the [power_mode_config.xml](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_mode_config.xml) file in the default power mode configuration folder.

    The **proxy** node is used to configure the power mode.

    **Table 1** Description of the proxy node 
    | Power Mode| ID |
    | :------ | --- |
    | Normal mode| 600 |
    | Power-saving mode| 601 |
    | Performance mode| 602 |
    | Super power-saving mode| 603 |

    The **switch** node is used to configure items of the power mode.

    **Table 2** Description of the **switch** node
    | Configuration Item| ID | Value Range|
    | :------ | ----- | ----- |
    | Screen-off time| 101 | **value** indicates the screen-off duration, in unit of ms. It is an integer greater than or equal to **-1**. The value **-1** indicates that the screen-off function is disabled.|
    | Auto sleep time| 102 | **value** indicates the time for automatically entering the sleep mode, in unit of ms. It is an integer greater than or equal to **-1**. The value **-1** indicates that the auto sleep function is disabled. |
    | Automatic brightness adjustment| 103 | **value** indicates whether to enable automatic brightness adjustment. The options are as follows:<br>- **-1**: disable automatic brightness adjustment.<br>- **1**: enable automatic brightness adjustment.|
    | Automatic screen rotation| 107 | **value** indicates whether to enable automatic screen rotation. The options are as follows:<br>- **-1**: disable automatic screen rotation.<br>- **1**: enable automatic screen rotation.|
    | System brightness| 115 | **value** indicates the screen brightness. It is an integer ranging from 0 to 255.|
    | Vibration switch| 120 | **value** indicates whether to enable vibration. The options are as follows:<br>- **-1**: disable vibration.<br>- **1**: enable vibration.|

    The following uses the normal mode as an example:

    ```xml
    <switch_proxy version="1">
        <proxy id="600">
            <switch id="101" value="10000"/>
            <switch id="102" value="0"/>
            <switch id="103" value="-1"/>
            <switch id="107" value="1"/>
            <switch id="115" value="30"/>
            <switch id="120" value="1"/>
        </proxy>
    ``` 

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn) file in the default power mode configuration folder to pack the `power_mode_config.xml` file to the `/vendor/etc/power_config` directory. The configuration is as follows:

    ```shell
    import("//base/powermgr/power_manager/powermgr.gni") 
    import("//build/ohos.gni")

    ## Install vendor power_mode_config.xml to /vendor/etc/power_config/power_mode_config.xml
    ohos_prebuilt_etc("power_mode_config_vendor") {  # custom name, for example, power_mode_config_vendor.
    source = "power_mode_config.xml"
    relative_install_dir = "power_config"
    install_images = [ chipset_base_dir ]            # Required configuration for installing the power_mode_config.xml file in the vendor directory, where chipset_base_dir = "vendor". If this field is left unspecified, the power_mode_config.xml file is installed in the system directory by default.
    part_name = "${product_rk3568}"                  # Set part_name to product_rk3568 for subsequent build.
    }

    group("power_service_config") {
    deps = [ ":power_mode_config_vendor" ]
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
            "//vendor/hihope/rk3568/power_manager/profile:power_mode_config_vendor", # Add the configuration for building of power_mode_config_vendor.
            "//vendor/hihope/rk3568/preinstall-config:preinstall-config",
            "//vendor/hihope/rk3568/resourceschedule:resourceschedule",
            "//vendor/hihope/rk3568/etc:product_etc_conf"
          ]
        }
      },
      "subsystem": "product_hihope"
    }
    ``` 
    

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

2. Set the power mode to the normal mode, and verify the setting.

    1. Set the power mode to the normal mode.

        ```shell
        power-shell setmode 600
        ```    

    2. Check whether the setting of the power mode is successful.

        ```shell
        Set Mode: 600
        Set Mode Success!

        ```
    3. Obtain the auto sleep time.

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=10000ms
        ··· (Only the auto sleep time configuration is displayed here. Other information is omitted.)

        ```

    4. Turn on the screen. If the screen turns off after 10 seconds, the setting of the auto sleep time is successful.

3. Set the power mode to the power-saving mode, and verify the setting.

    1. Set the power mode to the power-saving mode.

        ```shell
        power-shell setmode 601
        ```    

    2. Check whether the setting of the power mode is successful.

        ```shell
        Set Mode: 601
        Set Mode Success!

        ```
    3. Obtain the auto sleep time.

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=20000ms
        ··· (Only the auto sleep time configuration is displayed here. Other information is omitted.)

        ```

    4. Turn on the screen. If the screen turns off after 20 seconds, the setting of the auto sleep time is successful.

4. Set the power mode to the performance mode, and verify the setting.

    1. Set the power mode to the performance mode.

        ```shell
        power-shell setmode 602
        ```    

    2. Check whether the setting of the power mode is successful.

        ```shell
        Set Mode: 602
        Set Mode Success!

        ```
    3. Obtain the auto sleep time.

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=30000ms
        ··· (Only the auto sleep time configuration is displayed here. Other information is omitted.)

        ```

    4. Turn on the screen. If the screen turns off after 30 seconds, the setting of the auto sleep time is successful.

5. Set the power mode to the super power-saving mode, and verify the setting.

    1. Set the power mode to the super power-saving mode.

        ```shell
        power-shell setmode 603
        ```    

    2. Check whether the setting of the power mode is successful.

        ```shell
        Set Mode: 603
        Set Mode Success!

        ```
    3. Obtain the auto sleep time.

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=40000ms
        ··· (Only the auto sleep time configuration is displayed here. Other information is omitted.)

        ```

    4. Turn on the screen. If the screen turns off after 40 seconds, the setting of the auto sleep time is successful.

## Reference

During development, you can refer to the [default power mode configuration](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_mode_config.xml):

Packing path: `/system/etc/power_config/power_mode_config.xml`

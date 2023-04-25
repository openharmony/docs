# System Brightness Customization

## Overview

### Introduction

By default, the system brightness of OpenHarmony ranges from **0** to **255** (**0** indicates the minimum luminance and **255** the maximum). It is applicable to the entire system and all application windows. Due to hardware restrictions, some display devices are unable to support the system brightness range. To address this issue, OpenHarmony provides the function of customizing the system brightness range. This way, you can adjust the system brightness range based on the hardware specifications of the display devices.

### Basic Concepts

**System brightness**
Global brightness of OpenHarmony. The customized brightness range is effective for all application windows.

**Window brightness**
Brightness of an application window. The customized brightness range is effective only for this application window. After a brightness is specified for an application window, its brightness is not affected by the system brightness.

### Constraints

The [sysparam](./subsys-boot-init-sysparam.md) module of OpenHarmony provides an easy-to-use key-value pair access interface for system services to configure service functions based on their own system parameters. The customization of the system brightness range is dependent on this feature.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/Readme-EN.md).

### Getting Started with Development

1. In the target directory, create a target folder by referring to the [default brightness value configuration folder](https://gitee.com/openharmony/powermgr_display_manager/tree/master/service/etc). The content is as follows:
     
    ```text
    etc
    ├── BUILD.gn
    ├── display.para
    ├── display.para.dac
    ```

2. Write the customized **display.para** file by referring to the [**display.para** file](https://gitee.com/openharmony/powermgr_display_manager/blob/master/service/etc/display.para) in the default brightness range configuration folder. Include the customized brightness thresholds, for example, **max=150**, **default=75**, and **min=50**, into the file:

    ```shell
    # Brightness limits is 0-255.
    const.display.brightness.min=50
    const.display.brightness.default=75
    const.display.brightness.max=150
    ``` 

3. Write the customized **display.para.dac** file by referring to the [**display.para.dac** file](https://gitee.com/openharmony/powermgr_display_manager/blob/master/service/etc/display.para.dac) in the default brightness range configuration folder, so as to grant the permission required to access the customized configuration.

    ```shell
    const.display.brightness.="foundation:foundation:444"
    ``` 

4. Write the customized **BUILD.gn** file by referring to the [**BUILD.gn** file](https://gitee.com/openharmony/powermgr_display_manager/blob/master/service/etc/BUILD.gn) in the default brightness range configuration folder. Then, put the **display.para** and **display.para.dac** files to the **/vendor/etc/param** directory. For example:

    ```shell
    import("//base/powermgr/display_manager/displaymgr.gni")
    import("//build/ohos.gni")

    ## Install display.para to /vendor/etc/param/display.para
    ohos_prebuilt_etc("display.para") {
    source = "display.para"
    relative_install_dir = "param"
    install_images = [ chipset_base_dir ]
    part_name = "${displaymgr_part_name}"
    subsystem_name = "powermgr"
    }

    ohos_prebuilt_etc("display.para.dac") {
    source = "display.para.dac"
    relative_install_dir = "param"
    install_images = [ chipset_base_dir ]
    part_name = "${displaymgr_part_name}"
    subsystem_name = "powermgr"
    }

    group("param_files") {
    deps = [
        ":display.para",
        ":display.para.dac",
    ]
    }
    ```

5. Write the customized **bundle.json** file by referring to the [**bundle.json** file](https://gitee.com/openharmony/powermgr_display_manager/blob/master/bundle.json) in the default brightness range configuration folder, so as to compile the **BUILD.gn** file.
 
    ```shell
    "service_group": [ "//base/powermgr/display_manager/service/etc:param_files" ]
    ``` 
    In the preceding code, **//base/powermgr/display_manager/service** indicates the directory of the created folder, and **etc** indicates the folder name.

6. Build the customized version by referring to [Quick Start](../quick-start/Readme-EN.md). The following command uses DAYU200 as an example:

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. After startup, run the following command to launch the shell command line:

    ```shell
    hdc shell
    ```

2. Run the following command to check the console output:

    ```shell
    hidumper -s 3308 -a -a
    ```

3. Check the console output for the customized system brightness thresholds.

    The default system brightness thresholds are as follows:

    ```shell
    ----------------------------------DisplayPowerManagerService---------------------------------
    DISPLAY POWER MANAGER DUMP:
    Display Id=0 State=2 Discount=1.000000 Brightness=102
    DeviceBrightness=102
    Support Ambient Light: FALSE
    Auto Adjust Brightness: OFF
    Brightness Limits: Max=255 Min=5 Default=102

    ```

    Assume that the system brightness thresholds are set to **Max=150 Min=50 Default=75**. The console output is as follows:

    ```shell
    # cd vendor/etc/param                                                          
    # ls
    display.para      thermal.para      usb.para.dac  
    display.para.dac  thermal.para.dac  
    # cat display.para
    # Copyright (C) 2022 Huawei Device Co., Ltd.
    # Licensed under the Apache License, Version 2.0 (the "License");
    # you may not use this file except in compliance with the License.
    # You may obtain a copy of the License at
    #
    #     http://www.apache.org/licenses/LICENSE-2.0
    #
    # Unless required by applicable law or agreed to in writing, software
    # distributed under the License is distributed on an "AS IS" BASIS,
    # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    # See the License for the specific language governing permissions and
    # limitations under the License.

    # Brightness limits is 0-255.
    const.display.brightness.min=50
    const.display.brightness.default=75
    const.display.brightness.max=150# 
    # 
    # cd
    # hidumper -s 3308 -a -a

    -------------------------------[ability]-------------------------------


    ----------------------------------DisplayPowerManagerService---------------------------------
    DISPLAY POWER MANAGER DUMP:
    Display Id=0 State=0 Discount=1.000000 Brightness=75
    DeviceBrightness=75
    Support Ambient Light: FALSE
    Auto Adjust Brightness: OFF
    Brightness Limits: Max=150 Min=50 Default=75

    ```

4. Set the system brightness thresholds to the customized values.

## Reference

For details about how to write the configuration file during system brightness customization, refer to the [default brightness range configuration file](https://gitee.com/openharmony/powermgr_display_manager/tree/master/service/etc).

Default configuration:

```shell
# Brightness limits is 0-255.
const.display.brightness.min=5
const.display.brightness.default=102
const.display.brightness.max=255
``` 

Packing directory: /system/etc/param

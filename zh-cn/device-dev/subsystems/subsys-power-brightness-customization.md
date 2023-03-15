# 系统亮度范围定制开发指导 

## 概述 

### 简介 

OpenHarmony默认的亮度范围为0 ~ 255（0代表最小亮度，255代表最大亮度），是系统和所有应用窗口的亮度调节范围。部分显示设备受到其硬件约束，亮度调节范围无法达到0 ~ 255，即无法达到默认的亮度调节范围。为此OpenHarmony提供了系统亮度范围定制方式，在与不同显示设备适配时，产品定制开发者可根据显示设备自身硬件条件灵活调整系统亮度范围。

### 基本概念 

系统亮度：
OpenHarmony系统全局的亮度，调节后会使所有应用窗口亮度范围更改为定制的系统亮度范围。 

窗口亮度：
某个应用窗口的亮度，调节后只影响此窗口，窗口退出后，恢复为系统亮度。当设置窗口亮度后，此窗口的亮度不受系统亮度的影响。

### 约束与限制

[OpenHarmony系统参数](./subsys-boot-init-sysparam.md)为各系统服务提供简单易用的键值对访问接口，使得各个系统服务可以通过各自的系统参数来进行业务功能的配置。系统亮度范围的定制基于此特性实现。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/Readme-CN.md)》。

### 开发步骤 

1. 参考[默认亮度范围配置文件夹](https://gitee.com/openharmony/powermgr_display_manager/tree/master/service/etc)创建目标文件夹，并安装到相应目录，文件格式如下：
     
    ```text
    etc
    ├── BUILD.gn
    ├── display.para
    ├── display.para.dac
    ```

2. 参考[默认亮度范围配置文件夹中的display.para](https://gitee.com/openharmony/powermgr_display_manager/blob/master/service/etc/display.para)编写定制的display.para。包含定制后的亮度阈值，以max=150，default=75，min=50为例：

    ```shell
    # Brightness limits is 0-255.
    const.display.brightness.min=50
    const.display.brightness.default=75
    const.display.brightness.max=150
    ``` 

3. 参考[默认亮度范围配置文件夹中的display.para.dac](https://gitee.com/openharmony/powermgr_display_manager/blob/master/service/etc/display.para.dac)编写display.para.dac数据访问控制文件，保证有权限解析定制后的配置： 

    ```shell
    const.display.brightness.="foundation:foundation:444"
    ``` 

4. 参考[默认亮度范围配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_display_manager/blob/master/service/etc/BUILD.gn)编写BUILD.gn文件，将display.para和display.para.dac打包到/vendor/etc/param目录下，例如： 

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

5. 参考[默认亮度范围配置bundle.json](https://gitee.com/openharmony/powermgr_display_manager/blob/master/bundle.json)编写bundle.json文件，使BUILD.gn文件进行编译，例如：
 
    ```shell
    "service_group": [ "//base/powermgr/display_manager/service/etc:param_files" ]
    ``` 
    “//base/powermgr/display_manager/service”为文件夹路径，“etc”为创建的文件夹名字。

6. 参考《[快速入门](../quick-start/Readme-CN.md)》编译定制版本，以编译DAYU200为例，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 开机后，先进入shell命令行：

    ```shell
    hdc shell
    ```

2. 执行下列命令，观察console输出。

    ```shell
    hidumper -s 3308 -a -a
    ```

3. console输出的是定制后的系统亮度阈值，如：

    定制系统亮度阈值之前，默认为：

    ```shell
    ----------------------------------DisplayPowerManagerService---------------------------------
    DISPLAY POWER MANAGER DUMP:
    Display Id=0 State=2 Discount=1.000000 Brightness=102
    DeviceBrightness=102
    Support Ambient Light: FALSE
    Auto Adjust Brightness: OFF
    Brightness Limits: Max=255 Min=5 Default=102

    ```

    本节以Max=150 Min=50 Default=75为例，更改之后：

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

4. 系统全局的亮度阈值统一为定制后的，如设置中的亮度调节。

## 参考 

开发过程中可参考的配置文件路径：[系统默认亮度范围配置源码路径](https://gitee.com/openharmony/powermgr_display_manager/tree/master/service/etc) 

默认配置：

```shell
# Brightness limits is 0-255.
const.display.brightness.min=5
const.display.brightness.default=102
const.display.brightness.max=255
``` 

打包路径：/system/etc/param 
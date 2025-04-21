# 电源模式定制开发指导 

## 概述 

### 简介 

OpenHarmony默认提供了电源模式（如正常模式、性能模式、省电模式、超级省电模式）的特性。但由于不同产品的部件存在差异，导致在同样场景下电源模式的配置需要也存在差异，为此，OpenHarmony提供了电源管理的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。

### 基本概念 

OpenHarmony支持的可定制的电源模式如下，每种模式对应了不同的电源和性能策略模式。

- 正常模式：默认的电源模式，无特殊需求的情况下，此模式下的系统亮度、灭屏时间，进入睡眠时间等均适合大部分用户的需要。

- 性能模式：强调性能表现的电源模式，如增加系统亮度、关闭灭屏时间、防止进入睡眠等。

- 省电模式：强调省电表现的电源模式，如降低系统亮度、缩短灭屏时间、缩短进入睡眠时间等。

- 超级省电模式：强调超级省电表现的电源模式，如大幅降低系统亮度、大幅缩短灭屏时间，大幅缩短进入睡眠时间等。


### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以定制[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)的电源模式为例介绍电源模式的定制方法:

1. 在[vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建power_manager文件夹。

2. 参考[默认电源模式配置文件夹](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile)创建目标文件夹，并安装到//vendor/hihope/rk3568/power_manager，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── power_mode_config.xml
    ```

3. 参考[默认电源模式配置文件夹中的power_mode_config.xml](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_mode_config.xml)编写定制的power_mode_config.xml：

    proxy节点的说明是电源模式：

    **表1** proxy节点说明
    | 电源模式 | ID |
    | :------ | --- |
    | 正常模式 | 600 |
    | 省电模式 | 601 |
    | 性能模式 | 602 |
    | 超级省电模式 | 603 |

    switch节点的说明是配置项：

    **表2** switch节点说明
    | 配置项 | ID | 取值范围 |
    | :------ | ----- | ----- |
    | 灭屏时间 | 101 | value是时长，为整数，value>=-1，单位为毫秒（ms），-1为关闭灭屏功能。 |
    | 系统自动睡眠时间 | 102 | value是时长，为整数，value>=-1，单位为毫秒（ms），-1为关闭系统自动睡眠功能。  |
    | 自动调节亮度 | 103 | value为是否开启，取值范围：<br>-1为关闭自动调节亮度功能。 <br>1为开启自动调节亮度功能。 |
    | 自动调节屏幕旋转 | 107 | value为是否开启，取值范围：<br>-1为关闭自动调节屏幕旋转。 <br>1为开启自动调节屏幕旋转。 |
    | 系统亮度 | 115 | value是亮度，为整数，取值范围：0~255。 |
    | 震动开关 | 120 | value为是否开启，取值范围：<br>-1为关闭震动， <br>1为开启震动。 |

    以正常模式为例：

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

4. 参考[默认电源模式配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将power_mode_config.xml打包到 `/vendor/etc/power_config`目录下，例如： 

    ```shell
    import("//base/powermgr/power_manager/powermgr.gni") 
    import("//build/ohos.gni")

    ## Install vendor power_mode_config.xml to /vendor/etc/power_config/power_mode_config.xml
    ohos_prebuilt_etc("power_mode_config_vendor") {  # 自定义名称，例子中用名：power_mode_config_vendor
    source = "power_mode_config.xml"
    relative_install_dir = "power_config"
    install_images = [ chipset_base_dir ]            # 安装到vendor目录下的必要配置，chipset_base_dir = "vendor"， 如果不配置，默认安装到system目录
    part_name = "${product_rk3568}"                  # part_name为product_rk3568，以实现后续编译
    }

    group("power_service_config") {
    deps = [ ":power_mode_config_vendor" ]
    }

    ```

5. 将编译目标添加到[rk3568默认的ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build)的"module_list"中，例如：
 
    ```json
    {
      "parts": {
        "product_rk3568": {
          "module_list": [
            "//vendor/hihope/rk3568/default_app_config:default_app_config",
            "//vendor/hihope/rk3568/image_conf:custom_image_conf",
            "//vendor/hihope/rk3568/power_manager/profile:power_mode_config_vendor", # 添加power_mode_config_vendor的编译。
            "//vendor/hihope/rk3568/preinstall-config:preinstall-config",
            "//vendor/hihope/rk3568/resourceschedule:resourceschedule",
            "//vendor/hihope/rk3568/etc:product_etc_conf"
          ]
        }
      },
      "subsystem": "product_hihope"
    }
    ``` 
    

6. 参考《[快速入门](../quick-start/Readme-CN.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 开机后，先进入shell命令行：

    ```shell
    hdc shell
    ```

2. 设置电源模式为正常模式，并验证。

    1. 执行下列命令，更改电源模式，使设备进入正常模式：

        ```shell
        power-shell setmode 600
        ```    

    2. 成功进入正常模式：

        ```shell
        Set Mode: 600
        Set Mode Success!

        ```
    3. 执行下列命令，获取当前系统自动睡眠时间：

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=10000ms
        ······（省略其他，只显示系统自动睡眠时间的配置）

        ```

    4. 点亮屏幕，观察设备屏幕，10秒后灭屏，设置成功。

3. 设置电源模式为省电模式，并验证。

    1. 执行下列命令，更改电源模式，使设备进入省电模式：

        ```shell
        power-shell setmode 601
        ```    

    2. 成功进入省电模式：

        ```shell
        Set Mode: 601
        Set Mode Success!

        ```
    3. 执行下列命令，获取当前系统自动睡眠时间：

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=20000ms
        ······（省略其他，只显示系统自动睡眠时间的配置）

        ```

    4. 点亮屏幕，观察设备屏幕，20秒后灭屏，设置成功。

4. 设置电源模式为性能模式，并验证。

    1. 执行下列命令，更改电源模式，使设备进入性能模式：

        ```shell
        power-shell setmode 602
        ```    

    2. 成功进入性能模式：

        ```shell
        Set Mode: 602
        Set Mode Success!

        ```
    3. 执行下列命令，获取当前系统自动睡眠时间：

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=30000ms
        ······（省略其他，只显示系统自动睡眠时间的配置）

        ```

    4. 点亮屏幕，观察设备屏幕，30秒后灭屏，设置成功。

5. 设置电源模式为超级省电模式，并验证。

    1. 执行下列命令，更改电源模式，使设备进入超级省电模式：

        ```shell
        power-shell setmode 603
        ```    

    2. 成功进入超级省电模式：

        ```shell
        Set Mode: 603
        Set Mode Success!

        ```
    3. 执行下列命令，获取当前系统自动睡眠时间：

        ```shell
        hidumper -s 3301 -a -a

        -------------------------------[ability]-------------------------------


        ----------------------------------PowerManagerService---------------------------------
        POWER STATE DUMP:
        Current State: INACTIVE  Reason: 1  Time: 33227
        ScreenOffTime: Timeout=40000ms
        ······（省略其他，只显示系统自动睡眠时间的配置）

        ```

    4. 点亮屏幕，观察设备屏幕，40秒后灭屏，设置成功。

## 参考 

开发过程中可参考的配置文件路径：[系统默认电源模式配置源码路径](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile) 

[默认配置](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_mode_config.xml) 

打包路径：`/system/etc/power_config/power_mode_config.xml`

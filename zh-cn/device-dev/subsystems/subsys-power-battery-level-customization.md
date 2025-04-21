# 电量等级定制开发指导 

## 概述 

### 简介 

OpenHarmony默认提供了电量等级，根据当前的电量来定义系统统一的电量等级，如满电量、高电量、低电量、极低电量等。系统可以根据当前的电量等级对用户进行提示或处理相关业务。但是电量等级对应的电量值在不同的产品上规格是不同的，产品希望根据产品的设计规格来定制此特性。为此OpenHarmony提供了电量等级的定制方式，产品定制开发者可根据设计规格来定制此特性。

### 约束与限制

配置策略：
产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以/vendor进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍电量等级的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建battery文件夹。

2. 参考[默认电量等级配置文件夹](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/battery`目录下，文件格式如下：

    ```text
    profile
    ├── BUILD.gn
    ├── battery_config.json
    ```

3. 参考[默认电量等级的配置文件夹中的battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json)编写定制的battery_config.json，包含定制后的电量等级配置如下：

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

    **表1** 电量等级配置说明

    | 电量等级 | 电量 | 说明 |
    | -------- | -------- | -------- |
    | shutdown | 5 | 关机电量 |
    | critical | 10 | 极低电量 |
    | warning | 15 | 告警电量 |
    | low | 30 | 低电量 |
    | normal | 60 | 正常电量 |
    | high | 90 | 高电量 |
    | full | 100 | 满电量 |


4. 参考[默认电量等级的配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将battery_config.json打包到`//vendor/etc/battery`目录下，配置如下：

    ```shell
    import("//build/ohos.gni")               #引用build/ohos.gni

    ohos_prebuilt_etc("battery_config") {
        source = "battery_config.json"
        relative_install_dir = "battery"
        install_images = [ chipset_base_dir ] #安装到vendor目录下的必要配置
        part_name = "product_rk3568"          #part_name为product_rk3568，以实现后续编译
    }
    ```

5. 将编译目标添加到`/vendor/hihope/rk3568`目录下[ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build)的"module_list"中，例如：

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
            "//vendor/hihope/rk3568/battery/profile:battery_config" #添加battery_config的编译
        ]
        }
    },
    "subsystem": "product_hihope"
    }
    ```
    “//vendor/hihope/rk3568/battery/”为文件夹路径，“profile”为创建的文件夹名字，“battery_config”为编译目标。

6. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 开机后，进入shell命令行：
    ```
    hdc shell
    ```

2. 进入电池电量的节点路径（以当前DAYU开发版路径为例）。
    ```
    cd /data/service/el0/battery/battery/
    ```

3. 默认充电类型的映射配置数据为例，修改充电状态，模拟电池信息上报，观察发送是否发送对应充电类型广播。

    1. 修改电量信息。
    ```
    echo 100 > capacity
    ```
    2. 上报电量信息改变，获取当前电量等级。
    ```
    hidumper -s 3302 -a -i
    ```
    3. 成功获取电量等级如下: 
    
    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:22:48.589

    ······(省略其他，只显示batteryLevel的配置)

    batteryLevel: 1

    ······
    ```

    4. 修改电量信息。
    ```
    echo 90 > capacity
    ```
    5. 上报电量信息改变，获取当前电量等级。
    ```
    hidumper -s 3302 -a -i
    ```
    6. 成功获取电量等级如下: 
    
    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:24:29.716

    ······(省略其他，只显示batteryLevel的配置)

    batteryLevel: 2
    
    ······
    ```

    7. 修改电量信息。
    ```
    echo 60 > capacity
    ```
    8. 上报电量信息改变，获取当前电量等级。
    ```
    hidumper -s 3302 -a -i
    ```
    9. 成功获取电量等级如下:

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:25:09.837

    ······(省略其他，只显示batteryLevel的配置)

    batteryLevel: 3
    
    ······
    ```

    10. 修改电量信息。
    ```
    echo 30 > capacity
    ```
    11. 上报电量信息改变，获取当前电量等级。
    ```
    hidumper -s 3302 -a -i
    ```
    12. 成功获取电量等级如下:

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:26:20.495

    ······(省略其他，只显示batteryLevel的配置)

    batteryLevel: 4
    
    ······
    ```

    13. 修改电量信息。
    ```
    echo 15 > capacity
    ```
    14. 上报电量信息改变，获取当前电量等级。
    ```
    hidumper -s 3302 -a -i
    ```
    15. 成功获取电量等级如下:

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:27:05.312

    ······(省略其他，只显示batteryLevel的配置)

    batteryLevel: 5
    
    ······
    ```

    16. 修改电量信息。
    ```
    echo 10 > capacity
    ```
    17. 上报电量信息改变，获取当前电量等级。
    ```
    hidumper -s 3302 -a -i
    ```
    18. 成功获取电量等级如下:

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:27:56.270

    ······(省略其他，只显示batteryLevel的配置)

    batteryLevel: 6
    
    ······
    ```

    19. 修改电量信息。
    ```
    echo 5 > capacity
    ```
    20. 上报电量信息改变，获取当前电量等级。
    ```
    hidumper -s 3302 -a -i
    ```
    21. 成功获取电量等级如下:

    ```
    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryService---------------------------------
    Current time: 2017-08-05 17:28:38.066

    ······(省略其他，只显示batteryLevel的配置)

    batteryLevel: 7
    
    ······
    ```

## 参考 
开发过程中可参考的配置文件路径：[电量等级配置源码路径](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile/) 

默认配置：

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

打包路径：/system/etc/battery

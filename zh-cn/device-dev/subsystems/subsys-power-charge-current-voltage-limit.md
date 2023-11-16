# 充电限流限压定制开发指导 

## 概述 

### 简介 

OpenHarmony默认提供了充电限流限压的特性。在对终端设备进行充电时，由于环境影响，可能会导致电池温度过高，因此需要对充电电流或电压进行限制，从而保证终端设备使用的安全性。但是充电时的电流电压对安全性的影响在不同的产品上规格是不同的，产品希望根据产品的设计规格来定制此特性。为此OpenHarmony提供了充电限流限压的定制方式，产品定制开发者可根据产品的设计规格来定制此特性。

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

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍充电限流限压的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建battery文件夹。

2. 参考[默认充电限流限压配置文件夹](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/battery`目录下，文件格式如下：

    ```text
    profile
    ├── BUILD.gn
    ├── battery_config.json
    ```

3. 参考[默认充电限流限压的配置文件夹中的battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json)编写定制的battery_config.json，包含定制后的充电限流限压配置如下：

    ```json
    {
        "charger": {
            "current_limit":{
                "path": "/data/service/el0/battery/current_limit"
            },
            "voltage_limit":{
                "path": "/data/service/el0/battery/voltage_limit"
            }
        }
    }
    ``` 

4. 参考[默认充电限流限压的配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将battery_config.json打包到`//vendor/etc/battery`目录下，配置如下：

    ```shell
    import("//build/ohos.gni")                #引用build/ohos.gni

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

1. 编译battery对应的hats测试用例，编译命令与框架搭建参考[XTS子系统](https://gitee.com/openharmony/xts_hats)。

2. 用框架执行测试，输出测试报告。

    ![battery_limit_current_test_report](figures/battery_limit_current_test_report.jpg)

## 参考 

开发过程中可参考[默认充电限流限压的配置文件夹中的battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json)

默认配置：

```json
{
    "charger": {
        "current_limit":{
            "path": "/data/service/el0/battery/current_limit"
        },
        "voltage_limit":{
            "path": "/data/service/el0/battery/voltage_limit"
        }
    }
}
```

打包路径：/system/etc/battery
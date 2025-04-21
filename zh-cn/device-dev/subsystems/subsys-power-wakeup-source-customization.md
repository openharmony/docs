# 唤醒源定制开发指导

## 概述 

### 简介 

OpenHarmony支持多种唤醒源，如电源键、键盘、鼠标等，并提供了定制开启和关闭的方式。当设备进入休眠状态后，用户可以通过按电源键、按键盘、鼠标事件、轻触屏幕等，来点亮屏幕并唤醒设备。但不同的产品可能支持不同的外设，比如无手写笔、无皮套等。为此，OpenHarmony提供唤醒源的定制方式，产品可以根据具体的设计规格来定制此特性。

### 约束与限制

配置策略：
产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍唤醒源的定制方法。

1. 在产品目录`/vendor/hihope/rk3568`下创建power_manager文件夹。

2. 参考[唤醒源文件夹](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`/vendor/hihope/rk3568/power_manager`目录下，文件格式如下：

    ```text
    profile
    ├── BUILD.gn
    ├── power_wakeup.json
    ```

3. 编写定制的power_wakeup.json，包含定制后的唤醒源如下：

    ```json
    {
        "powerkey": {
            "enable": true
        },
        "keyborad": {
            "enable": true
        },
        "mouse": {
            "enable": true
        },
        "touchscreen": {
            "enable": true,
            "click": 2
        },
        "touchpad": {
            "enable": true
        },
        "pen": {
            "enable": true
        },
        "lid": {
            "enable": true
        },
        "switch": {
            "enable": true
        },
        "tp_touch": {
            "enable": true
        }
    }
    ```

    **表1** 唤醒源说明

    | 休眠源 | 描述 |
    | -------- | -------- |
    | powerkey | 电源键唤醒 |
    | keyborad | 键盘唤醒 |
    | mouse | 鼠标唤醒 |
    | touchscreen | 触摸屏幕唤醒 |
    | touchpad | 触摸板唤醒 |
    | pen | 手写笔唤醒 |
    | lid | 皮套唤醒 |
    | switch | 盖子唤醒 |
    | tp_touch | 触屏唤醒 |

    **表2** 唤醒源配置说明

    | 配置项 | 类型 | 描述 |
    | -------- | -------- | -------- |
    | enable | bool | 是否开启唤醒监听 |
    | click | int | 点击次数 |


4. 参考[唤醒源的配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将power_wakeup.json打包到`/vendor/etc/power_config`目录下，配置如下：

    ```shell
    import("//build/ohos.gni")               #引用build/ohos.gni

    ohos_prebuilt_etc("wakeup_config") {
        source = "power_wakeup.json"
        relative_install_dir = "power_config"
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
                    "//vendor/hihope/rk3568/power_manager/profile:wakeup_config" //添加wakeup_config的编译
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    “//vendor/hihope/rk3568/power_manager/”为文件夹路径，“profile”为创建的文件夹名字，“wakeup_config”为编译目标。

6. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

> **说明**：
> 
> 双击亮屏当前暂不支持，即"touchscreen"中的"enable"当前仅支持为false。能力将会在后续版本提供。

1. 以新的唤醒源配置文件为例，更改之后：
    ```json
    {
        "powerkey": {
            "enable": true
        },
        "keyborad": {
            "enable": true
        },
        "mouse": {
            "enable": true
        },
        "touchscreen": {
            "enable": false,
            "click": 2
        },
        "touchpad": {
            "enable": false
        },
        "pen": {
            "enable": false
        },
        "lid": {
            "enable": false
        },
        "switch": {
            "enable": false
        },
        "tp_touch": {
            "enable": false
        }
    }
    ```

2. 开机后，点击电源键使设备进入休眠状态，再次点击电源键。

    设备屏幕点亮，设备被唤醒。

3. 点击电源键使设备进入休眠状态，按下键盘。

    设备屏幕点亮，设备被唤醒。

4. 点击电源键使设备进入休眠状态，滑动鼠标。

    设备屏幕点亮，设备被唤醒。
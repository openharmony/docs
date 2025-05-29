# 电源默认休眠行为定制开发指导

## 概述 

### 简介 

当前OpenHarmony灭屏后会启动运行锁循环检测线程，然后默认进入休眠状态。不同设备的灭屏方式不相同，可能为合盖灭屏、超时灭屏、盖屏灭屏或是按电源键灭屏等；灭屏后的默认行为也不相同，可能为无动作、将屏幕下电，或是进入休眠状态等。为此，OpenHarmony提供电源默认休眠行为的定制方式，产品可以根据具体的设计规格来定制此特性。

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

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍电源默认休眠行为的定制方法。

1. 在产品目录`/vendor/hihope/rk3568`下创建power_manager文件夹。

2. 参考电源管理服务组件中的[电源默认休眠行为配置文件夹](https://gitee.com/openharmony/powermgr_power_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`/vendor/hihope/rk3568/power_manager`目录下，文件格式如下：

    ```text
    profile
    ├── BUILD.gn
    ├── power_suspend.json
    ```

3. 编写定制的power_suspend.json，定制后的电源默认休眠行为示例如下：

    ```json
    {
        "powerkey": {
            "action": 1,
            "delayMs": 0
        },
        "timeout": {
            "action": 1,
            "delayMs": 0
        },
        "lid": {
            "action": 1,
            "delayMs": 0
        },
        "switch": {
            "action": 1,
            "delayMs": 0
        },
        "tp_cover": {
            "action": 1,
            "delayMs": 0
        }
    }
    ```

    **表1** 休眠源说明

    | 休眠源 | 描述 |
    | -------- | -------- |
    | powerkey | 电源键灭屏 |
    | timeout | 超时灭屏 |
    | lid | 皮套灭屏 |
    | switch | 合盖灭屏 |
    | tp_cover | 盖屏灭屏 |

    **表2** 休眠源配置说明

    | 配置项 | 描述 |
    | -------- | -------- |
    | action | 执行动作，需配置具体枚举值数字，详细说明见下表。 |
    | delayMs | 延迟时间，单位毫秒。 |

    **表3** action说明

    | action | 取值 | 描述 |
    | -------- | -------- | -------- |
    | ACTION_NONE | 0 | 无动作 |
    | ACTION_AUTO_SUSPEND | 1 | 自动进入睡眠 |
    | ACTION_FORCE_SUSPEND | 2 | 强制进入睡眠 |
    | ACTION_HIBERNATE | 3 | 进入休眠 |
    | ACTION_SHUTDOWN | 4 | 关机 |

4. 参考[电源默认休眠行为的配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将power_suspend.json打包到`/vendor/etc/power_config`目录下，配置如下：

    ```shell
    import("//build/ohos.gni")               #引用build/ohos.gni

    ohos_prebuilt_etc("suspend_config") {
        source = "power_suspend.json"
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
                    "//vendor/hihope/rk3568/power_manager/profile:suspend_config" //添加suspend_config的编译
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    “//vendor/hihope/rk3568/power_manager/”为文件夹路径，“profile”为创建的文件夹名字，“suspend_config”为编译目标。

6. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 以新的休眠源配置文件为例，更改之后：
    ```json
    {
        "powerkey": {
            "action": 4,
            "delayMs": 0
        },
        "timeout": {
            "action": 1,
            "delayMs": 0
        },
        "lid": {
            "action": 1,
            "delayMs": 0
        },
        "switch": {
            "action": 1,
            "delayMs": 0
        },
        "tp_cover": {
            "action": 1,
            "delayMs": 0
        }
    }
    ```

2. 开机后，点击电源按键。

    设备进入关机状态。

3. 再次开机后等待一段时间。

    设备进入黑屏状态。

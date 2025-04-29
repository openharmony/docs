# 唤醒后系统动作定制开发指导

## 概述 

### 简介 

OpenHarmony支持系统睡眠时唤醒执行动作，如在睡眠中低电量情况下唤醒使系统关机。当设备进入睡眠状态后，可以根据用户配置的策略唤醒并执行对应动作。但不同产品可支持的场景可能不同，比如不支持低电量唤醒。为此，OpenHarmony提供唤醒后动作的定制方式，产品可以根据具体的设计规格来定制此特性。

### 约束与限制

约束：
唤醒后动作特性需要适配：

- 满足唤醒条件（如电量低于阈值）时触发电源键事件。
- 唤醒原因（如低电量唤醒）保存到内核节点。

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
    ├── power_wakeup_action.json
    ```

3. 编写定制的power_wakeup_action.json，包含定制后的唤醒原因和动作如下：

    ```json
    {
        "53": {
            "scene": "LowCapacity",
            "action": 2,
            "description": "(such as)53 is a uniquely wakeup reason by reading node through HDI interface(GetWakeupReason)"
        }
    }
    ```

    **表1** 唤醒源说明

    | 唤醒源 | 描述 |
    | -------- | -------- |
    | 53 | 低电量唤醒 |

    唤醒源配置来源于实际场景，如读取节点或其他获得，description用来描述具体来源。

    **表2** 唤醒场景说明

    | 唤醒场景 | 描述 |
    | -------- | -------- |
    | LowCapacity | 低电量 |

    **表3** action说明

    | action | 取值 | 描述 |
    | -------- | -------- | -------- |
    | ACTION_NONE | 0 | 无动作 |
    | ACTION_HIBERNATE | 1 | 进入休眠 |
    | ACTION_SHUTDOWN | 2 | 关机 |

4. 参考[唤醒源的配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将power_wakeup_action.json打包到`/vendor/etc/power_wakeup_action`目录下，配置如下：

    ```shell
    import("//build/ohos.gni")               #引用build/ohos.gni

    ohos_prebuilt_etc("wakeup_action_config") {
        source = "power_wakeup_action.json"
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
                    "//vendor/hihope/rk3568/power_manager/profile:wakeup_action_config" //添加wakeup_action_config的编译
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    “//vendor/hihope/rk3568/power_manager/”为文件夹路径，“profile”为创建的文件夹名字，“wakeup_action_config”为编译目标。

6. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 以新的唤醒源配置文件为例，更改之后：
    ```json
    {
        "53": {
            "scene": "LowCapacity",
            "action": 2,
            "description": "(such as)53 is a uniquely wakeup reason by reading node through HDI interface(GetWakeupReason)"
        }
    }
    ```

2. 修改[powermgr.gni](https://gitee.com/openharmony/powermgr_power_manager/blob/master/powermgr.gni)，使能power_manager_feature_wakeup_action特性。
    ```
    power_manager_feature_wakeup_action = true
    ```
    
3. 参考[battery_config.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_config.json)中添加如下配置。
    ```json
    "charge_scene": {
        "low_battery_thers": {
          "set": {
            "path": "xxx"
          }
        }
    }
    ```
    其中path为保存低电量阈值的节点路径。

4. 修改[batterymgr.gni](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/batterymgr.gni)，使能battery_manager_feature_set_low_capacity_threshold特性。
    ```
    battery_manager_feature_set_low_capacity_threshold = true
    ```    
5. 在[power_config.json](https://gitee.com/openharmony/drivers_peripheral/blob/master/power/interfaces/hdi_service/profile/power_config.json)中添加如下部分。
    ```json
    {
        "scene" :{
            "wakeuo_cause": {
                "get": {
                    "path": "yyy"
                }
            }
        }
    }
    ```
    其中get为保存低电量唤醒原因的节点路径。

5. 修改[power.gni](https://gitee.com/openharmony/drivers_peripheral/blob/master/power/power.gni)，打开drivers_peripheral_power_wakeup_cause_path特性。
    ```
    drivers_peripheral_power_wakeup_cause_path = true
    ```
6. 在[hdf_peripheral.cfg](https://gitee.com/openharmony/drivers_peripheral/blob/master/base/hdf_peripheral.cfg)的pre-init修改节点权限为system。
    ```
    "chown system system xxx",
    "chown system system yyy",
    ```
7. 使系统在睡眠中电量下降至阈值。

    设备关机。
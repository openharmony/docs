# 热场景定制开发指导

## 概述 

### 简介 

OpenHarmony默认提供了热场景的特性。在设备使用过程中，比如游戏、拍照、通话时需要保证性能、温度和功耗的平衡。在不同场景下，热管理的策略会有所不同，如游戏场景下不会降低屏幕亮度，但是在不同的产品上对热场景的定义是不同的，产品希望根据产品的设计规格来定制此特性。OpenHarmony提供了热场景的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。

### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍热场景的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建thermal文件夹。

2. 参考[默认热场景的配置文件夹](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. 参考[默认热场景的配置文件夹中的thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)编写定制的thermal_service_config.xml。包含热场景配置说明及定制后的热场景配置如下：

    **表1** 热场景配置说明

    | 配置项 | 配置项描述 | 配置项参数 | 配置项参数描述 | 配置项参数类型 | 配置项参数取值范围 |
    | -------- | -------- | -------- | -------- | -------- | -------- |
    | name="scene" | 配置一种或多种使用场景，可以在枚举中任选 | param | 具体的使用场景：拍照、电话、游戏 | enum | cam，call，game |

    screen和charge是配置的使用场景的状态，分别为是否亮屏和是否充电。
    
    ```shell
    <state>
        <item name="scene" param="cam,call,game"/>
        <item name="screen"/>
        <item name="charge"/>
    </state>
    ```
4. 外部可调用thermal service的UpdateThermalState接口设置场景状态值。
```cpp
bool UpdateThermalState(const std::string& tag, const std::string& val, bool isImmed = false)
```
| 参数 | 说明 | 类型 |
|---|---|---|
| tag | 场景标签 | string |
| val | 场景状态值 | string |
| isImmed | 是否立即更新温控动作值 | bool |

5. 参考[默认热场景配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将thermal_service_config.xml打包到`/vendor/etc/thermal_config`目录下

    ```shell
    import("//build/ohos.gni")                      # 引用build/ohos.gni 

    ohos_prebuilt_etc("thermal_service_config") {
        source = "thermal_service_config.xml"
        relative_install_dir = "thermal_config"
        install_images = [ chipset_base_dir ]       # 安装到vendor目录下的必要配置
        part_name = "product_rk3568"                # part_name暂定为product_rk3568，以实现后续编译，产品定制根据需要自行修改
    }
    ```

6. 将编译目标添加到[ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build)的"module_list"中，例如：

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
                    "//vendor/hihope/rk3568/thermal/profile:thermal_service_config", // 添加thermal_service_config的编译
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    “//vendor/hihope/rk3568/thermal/”为文件夹路径，“profile”为创建的文件夹名字，“thermal_service_config”为编译目标。

7. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

8. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 开机后，进入shell命令行：
    ```shell
    hdc shell
    ```

2. 获取当前热场景信息。
    ```shell
    hidumper -s 3303 -a -s
    ```

    查看定制后的热场景结果如下：
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    name: scene  params: cam,call,game
    name: screen
    name: charge
    ```

## 参考 
开发过程中可参考的配置文件路径：[默认热场景源码路径](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)

打包路径：`/vendor/etc/thermal_config/hdf`


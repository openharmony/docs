# 充电空闲状态定制开发指导

## 概述 

### 简介 

OpenHarmony默认提供了充电空闲状态的特性。根据设备的热等级、电量、充电状态和充电电流，来决策当前设备是否处于空闲状态，处于此种状态的设备可以执行一些重度的后台任务。但是各设备达到充电空闲状态的条件在不同的产品上规格是不同的，产品希望根据产品的设计规格来定制此特性。OpenHarmony提供了充电空闲状态的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。

### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍充电空闲状态的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建thermal文件夹。

2. 参考[默认充电空闲状态的配置文件夹](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. 参考[默认充电空闲状态的配置文件夹中的thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)编写定制的thermal_service_config.xml。包含充电空闲状态配置说明及定制后的充电空闲状态配置如下：

    **表1** 充电空闲状态配置说明
    
    | 配置项 | 描述 | 数据类型 | 取值范围 |
    | -------- | -------- | -------- | -------- |
    | thermallevel | 热等级阈值 | int | 根据产品的热等级进行定义，当设备热等级小于等于该阈值时，其状态为充电空闲状态。 |
    | soc | 电池电量阈值 | int | 0~100，当设备电量大于等于该阈值时，其状态为充电空闲状态。 |
    | charging | 电池是否在充电 | int | 1为正在充电，0为不在充电。 |
    | current | 电池充电电流阈值 | int | 单位为mA，当电池充电电流大于等于该阈值时，其状态为充电空闲状态。 |

    ```shell
    <idle name="charging">
        <thermallevel>1</thermallevel>
        <soc>90</soc>
        <charging>1</charging>
        <current>1000</current>
    </idle>
    ```

4. 参考[默认充电空闲状态配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将thermal_service_config.xml打包到`/vendor/etc/thermal_config`目录下

    ```shell
    import("//build/ohos.gni")                      # 引用build/ohos.gni

    ohos_prebuilt_etc("thermal_service_config") {
        source = "thermal_service_config.xml"
        relative_install_dir = "thermal_config"
        install_images = [ chipset_base_dir ]       # 安装到vendor目录下的必要配置
        part_name = "product_rk3568"                # part_name暂定为product_rk3568，以实现后续编译，产品定制根据需要自行修改
    }
    ```

5. 将编译目标添加到[ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build)的"module_list"中，例如：

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

6. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 开机后，进入shell命令行：
    ```shell
    hdc shell
    ```

2. 获取当前充电空闲状态。
    ```shell
    hidumper -s 3303 -a -i
    ```

    查看定制后的充电空闲状态结果如下: 
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    thermallevel: 1
    soc: 100
    charging: 1
    current: 1000
    ```

## 参考 
开发过程中可参考的配置文件路径：[默认充电空闲状态源码路径](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)

打包路径：`/vendor/etc/thermal_config/hdf`




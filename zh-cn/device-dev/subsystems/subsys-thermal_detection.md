# 热检测定制开发指导

## 概述 

### 简介 

OpenHarmony默认提供了热检测的特性。设备在运行过程中会产生热量，如CPU发热、电池发热等，此时器件会通过相应的温度传感器，将其温度进行实时上报。热检测特性是实时检测器件的温度，为热管理模块提供温度输入。但是在不同产品中，对不同器件进行热检测的规格是不同的，针对此种情况，OpenHarmony提供了热检测的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。

### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍热检测的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建thermal文件夹。

2. 参考[默认热检测的配置文件夹](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/interfaces/hdi_service/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_hdi_config.xml
    ```

3. 参考[默认热检测的配置文件夹中的thermal_hdi_config.xml](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/thermal_hdi_config.xml)编写定制的thermal_hdi_config.xml。包含热检测配置说明及定制后的热检测配置如下：

    **表1** 热检测配置说明

    |节点名称| 配置项名称 | 配置项描述 | 值的类型 |
    | -------- | -------- | -------- | -------- |
    | item | tag | 获取真实节点或模拟节点温度值标志位的名称 | string |
    | item | value | 为1时获取模拟节点温度值，为0时获取真实节点温度值 | int |
    | group | name | 真实节点组（actual）或模拟节点组（sim）的名称 | string |
    | group | interval | 轮询时间间隔（默认单位为ms） | int |
    | thermal_zone | type | thermal zone名称 | string |
    | thermal_zone | path | 获取真实节点thermal zone温度值的路径 | string |
    | thermal_node | type | thermal node名称 | string |
    | thermal_node | path | 获取模拟节点thermal node温度值的路径 | string |

    ```shell
    <base>
        <item tag="sim_tz" value="0"/>
    </base>

    <polling>
        <group name="actual" interval="30000">
            <thermal_zone type="soc-thermal" path="sys/class/thermal/thermal_zone0/temp"/>
            <thermal_zone type="gpu-thermal" path="sys/class/thermal/thermal_zone0/temp"/>
        </group>
        <group name="sim" interval="30000">
            <thermal_node type="soc" path="data/service/el0/thermal/sensor/soc/temp"/>
            <thermal_node type="cpu" path="data/service/el0/thermal/sensor/cpu/temp"/>
            <thermal_node type="ap" path="data/service/el0/thermal/sensor/ap/temp"/>
            <thermal_node type="pa" path="data/service/el0/thermal/sensor/pa/temp"/>
            <thermal_node type="ambient" path="data/service/el0/thermal/sensor/ambient/temp"/>
            <thermal_node type="charger" path="data/service/el0/thermal/sensor/charger/temp"/>
            <thermal_node type="battery" path="data/service/el0/thermal/sensor/battery/temp"/>
            <thermal_node type="shell" path="data/service/el0/thermal/sensor/shell/temp"/>
        </group>
    </polling>
    ```
    获取真实节点温度的路径参考[热日志文档](../subsystems/subsys-thermal_log.md)中获取thermal zone温度的路径，获取模拟节点温度的路径参考[热检测的默认配置](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/thermal_hdi_config.xml)。

5. 参考[默认热检测配置文件夹中的BUILD.gn](https://gitee.com/openharmony/drivers_peripheral/blob/master/thermal/interfaces/hdi_service/profile/BUILD.gn)编写BUILD.gn文件，将thermal_hdi_config.xml打包到`//vendor/etc/thermal_config/hdf`目录下：

    ```shell
    import("//build/ohos.gni")

    ohos_prebuilt_etc("thermal_hdf_config") {
        source = "thermal_hdi_config.xml"
        relative_install_dir = "thermal_config/hdf"
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
                    "//vendor/hihope/rk3568/thermal/profile:thermal_hdf_config", // 添加thermal_hdf_config的编译
                ]
            }
        },
        "subsystem": "product_hihope"
    }
    ```
    “//vendor/hihope/rk3568/thermal/”为文件夹路径，“profile”为创建的文件夹名字，“thermal_hdf_config”为编译目标。

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

2. 获取thermal zone的热检测结果：
    ```shell
    hidumper -s 3303 -a -t
    ```

    成功获取thermal zone的热检测结果如下，其中Temperature的默认温度单位为0.001摄氏度：
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    ······(省略其他，只显示定制后的热检测结果)
    Type: gpu-thermal
    Temperature: 35555
    Type: soc-thermal
    Temperature: 35000
    ······
    ```

## 参考 
开发过程中可参考的配置文件路径：[默认热检测的配置源码路径](https://gitee.com/openharmony/drivers_peripheral/tree/master/thermal/interfaces/hdi_service/profile/)

打包路径：`/vendor/etc/thermal_config/hdf`


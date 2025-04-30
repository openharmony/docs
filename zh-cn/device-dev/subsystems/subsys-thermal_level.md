# 热等级定制开发指导

## 概述 

### 简介 

OpenHarmony默认提供了热等级的特性。不同的硬件设备发热量和所能承受的最大温度都不相同，因此需要根据不同器件的温度，来定义系统的热等级标准，从而清晰的表明当前设备的发热状态，给热策略提供输入。但是器件在不同温度下对应的热等级在不同的产品上规格是不同的，产品希望根据产品的设计规格来定制此特性。OpenHarmony提供了热等级的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。

### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍热等级的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建thermal文件夹。

2. 参考[默认热等级的配置文件夹](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. 参考[默认热等级的配置文件夹中的thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)编写定制的thermal_service_config.xml。包含热等级配置说明及定制后的热等级配置如下：

    **表1** base配置说明
    | 配置项 | 配置项描述 | 配置项参数 | 配置项参数描述 | 参数类型 | 参数取值范围 |
    | -------- | -------- | -------- | -------- | -------- | -------- |
    | tag="history_temp_count" | 历史上报温度次数标签的名称 | value | 历史上报温度次数 | int | >0 |
    | tag="temperature_query_enum" | 获取温度的设备列表的标签名称 | value | 要获取温度的设备列表 | enum | soc，battery，shell，cpu，charger，ambient，ap，pa |


    **表2** sensor_cluster配置说明

    | 配置项名称 | 配置项描述 | 数据类型 | 取值范围 |
    | -------- | -------- | -------- | -------- |
    | name | 传感器集合名称 | string | 无 |
    | sensor | 集合内的传感器 | string | soc，battery，shell，cpu，charger，ambient，ap，pa |
    | aux_sensor | 集合内的辅助传感器 | string | soc，battery，shell，cpu，charger，ambient，ap，pa |

    **表3** item配置说明

    | 配置项名称 | 配置项描述 | 数据类型 | 取值范围 |
    | -------- | -------- | -------- | -------- |
    | level | 各传感器集合下定义的热等级 | int | >0 |
    | threshold | 集合内每个传感器达到对应热等级的温度阈值（默认单位0.001摄氏度，开发者可定制） | int | 根据产品定制 |
    | threshold_clr | 集合内每个传感器回退到上一热等级的温度阈值 | int | 根据产品定制 |
    | temp_rise_rate | 温度升高频率 | double | 根据产品定制 |

    ```shell
    <thermal version="0.01" product="lya">
    <base>
        <item tag="history_temp_count" value="10"/>
        <item tag="temperature_query_enum" value="soc,battery,shell,cpu,charger,ambient,ap,pa"/>
    </base>

    <level>
        <sensor_cluster name="base_safe" sensor="battery,charger,cpu,soc">
            <item level="1" threshold="42000,40000,30000,40000" threshold_clr="38000,36000,28000,38000"/>
            <item level="2" threshold="43000,41000,32000,42000" threshold_clr="41000,39000,30000,40000"/>
            <item level="3" threshold="46000,44000,34000,44000" threshold_clr="44000,42000,32000,42000"/>
            <item level="4" threshold="48000,46000,36000,46000" threshold_clr="46000,44000,34000,44000"/>
        </sensor_cluster>
    </level>
    ```

4. 参考[默认热等级配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将thermal_service_config.xml打包到`/vendor/etc/thermal_config`目录下：

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

2. 进入`data/service/el0/thermal/sensor/soc/`路径：
    ```shell
    cd data/service/el0/thermal/sensor/soc
    ```
    
3. 修改soc的温度：
    ```shell
    echo 42000 > temp
    ```

4. 获取当前热等级信息：
    ```shell
    hidumper -s 3303 -a -l
    ```

    成功获取热等级信息如下：
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    name: base_safe	level: 2
    name: cold_safe	level: 0
    name: high_safe	level: 0
    name: warm_5G	level: 0
    name: warm_safe	level: 1
    ```

## 参考 
开发过程中可参考的配置文件路径：[默认热等级源码路径](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)

打包路径：`/vendor/etc/thermal_config/hdf`


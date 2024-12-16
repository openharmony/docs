# 热管控定制开发指导

## 概述 

### 简介 

OpenHarmony默认提供了热管控的特性。设备在使用的过程中如果发热过多，则需要对发热的器件进行管控，如充电时电池温度过高，则需要对充电进行限制。但是管控动作在不同的产品上规格是不同的，产品希望根据产品的设计规格来定制此特性。为此OpenHarmony提供了热管控的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。

### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍热管控的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建thermal文件夹。

2. 参考[默认热管控的配置文件夹](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile)创建目标profile文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. 参考[默认热管控的配置文件夹中的thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)编写定制的thermal_service_config.xml。包含热管控配置说明及定制后的热管控配置如下：

    **表1** 热管控配置说明

    | 管控动作配置项名称 | 管控动作配置项描述 | 管控动作配置项参数 | 管控动作配置项参数描述 | 数据类型 |取值范围 |
    | -------- | -------- | -------- | -------- | -------- | -------- |
    | name="airplane" | 飞行模式管控动作 | 无 | 无 | 无 | 无 |
    | name="cpu_big" | 大核CPU管控动作（控制大核CPU频率） | 无 | 无 | 无 | 无 |
    | name="cpu_med" | 中核CPU管控动作（控制中核CPU频率） | 无 | 无 | 无 | 无 |
    | name="cpu_lit" | 小核CPU管控动作（控制小核CPU频率） | 无 | 无 | 无 | 无 |
    | name="gpu" | GPU管控动作（控制GPU频率） | 无 | 无 | 无 | 无 |
    | name="boost" | SOCPERF热等级管控动作 | event | 为1时发送事件，为0时不发送事件 | int | 0，1 |
    | name="isolate" | CPU提高频率管控动作 | event | 为1时发送事件，为0时不发送事件 | int | 0，1 |
    | name="lcd" | LCD管控动作（控制屏幕亮度） | 无 | 无 | 无 | 无 |
    | name="volume" | 声音管控动作（控制音量大小） | uid | 用户id | int | 根据产品定义 | 
    | name="current_xxx" | 充电电流管控动作（控制快充和慢充时的充电电流大小） | protocol<br>param | protocol填写current，param填写支持的充电协议，快充（sc）和慢充（buck） | string |protocol="current" param="sc" |
    | name="current_xxx" | 充电电流管控动作 | event | 为1时发送事件，为0时不发送事件 | int | 0，1 |
    | name="voltage_xxx" | 充电电压管控动作（控制快充和慢充时的充电电压大小） | protocol<br>param | protocol填写voltage，param填写支持的充电协议，快充（sc）和慢充（buck） | string | protocol="voltage" param="buck" |
    | name="voltage_xxx" | 充电电压管控动作 | event | 为1时发送事件，为0时不发送事件 | int | 0，1 |
    | name="process_ctrl" | 进程管控动作（控制前台和后台进程存活状态） | param | param填写任意字符串 | string | 无 |
    | name="process_ctrl" | 进程管控动作（控制前台和后台进程存活状态） | event | 为1时发送事件，为0时不发送事件，为空时默认值为0 | int | 0，1 |
    | name="shut_down" | 关机管控动作（控制是否关机） | event | 为1时发送事件，为0时不发送事件 | int | 0，1 |
    | name="thermallevel" | 热等级管控动作（控制热等级上报） | event | 为1时发送事件，为0时不发送事件 | int | 0，1 |
    | name="popup" | 弹窗管控动作（控制是否弹窗） | 无 | 无 | 无 | 无 |
    | name="xxx" | 节点定制温控动作 | protocol<br>param | protocol填入node<br>param填入节点路径及回退值，用"\|"隔开 | string | 无 |

    ```shell
    <action>
        <item name="airplane"/>
        <item name="cpu_big"/>
        <item name="cpu_med"/>
        <item name="cpu_lit"/>
        <item name="gpu"/>
        <item name="boost" event="1"/>
        <item name="isolate" event="1"/>
        <item name="lcd"/>
        <item name="volume" uid="2001,2002"/>
        <item name="current_sc" protocol="current" param="sc" event="1"/>
        <item name="voltage_buck" protocol="voltage" param="buck" event="1"/>
        <item name="process_ctrl" param="32,64,128,256" event=""/>
        <item name="shut_down" event="0"/>
        <item name="thermallevel" event="1"/>
        <item name="popup"/>
        <item name="(action_name)" protocol="node" param="/sys/class/thermal/xxx"/>
        <item name="test"/>
    </action>
    ```

4. 参考[默认热管控配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将thermal_service_config.xml打包到`/vendor/etc/thermal_config`目录下

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

OpenHarmony从5.0.0 Release版本起，支持温度模拟调测功能。下述操作通过模拟温度变化实现温度等级的跃迁，以此来验证热管控策略的定制能力。下述调测验证步骤，默认定制的thermal_service_config.xml按照[默认热管控的配置文件夹中的thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)配置。

1. 开机后，进入shell命令行：
    ```shell
    hdc shell
    ```

2. 获取当前热管控信息。
    ```shell
    hidumper -s 3303 -a -a
    ```

    查看定制后的热管控结果如下: 
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    name: airplane	strict: 0	enableEvent: 0
    name: cpu_big	strict: 0	enableEvent: 0
    name: cpu_med	strict: 0	enableEvent: 0
    name: cpu_lit	strict: 0	enableEvent: 0
    name: gpu	strict: 0	enableEvent: 0
    name: boost	strict: 0	enableEvent: 1
    name: isolate	strict: 0	enableEvent: 1
    name: lcd	strict: 0	enableEvent: 0
    name: volume	uid: 2001,2002	strict: 0	enableEvent: 0
    name: current_sc    params: sc	protocol: current	strict: 0	enableEvent: 1
    name: current_buck    params: buck	protocol: current	strict: 0	enableEvent: 1
    name: voltage_sc   params: sc	protocol: voltage	strict: 0	enableEvent: 1
    name: voltage_buck   params: buck	protocol: voltage	strict: 0	enableEvent: 1
    name: process_ctrl  params: 32,64,128,256	strict: 0	enableEvent: 0
    name: shut_down	strict: 0	enableEvent: 0
    name: thermallevel	strict: 0	enableEvent: 1
    name: popup	strict: 0	enableEvent: 0
    name: test	strict: 0	enableEvent: 0
    ```

3. 停止自动上报温度。
    
    使用```hidumper -s 3303 -a '-st [f] [...]'```指令控制是否自动上报温度。其中...表示任意字符串。如果f为0，则停止自动上报温度；否则，则恢复自动上报温度。

    ```shell
    $ hidumper -s 3303 -a '-st 0'

    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService----------------------------------
    Temperature reporting has been stopped.
    ```

4. 模拟温度变化。
    
    为触发热管控策略，先设置低温，再设置高温。使用```hidumper -s 3303 -a '-te [name] [num]'```指令上报模拟温度。其中name表示温度传感器名称，num表示该传感器对应的模拟温度。多组name和num，表示同时上传多组模拟温度。

    ```shell
    $ hidumper -s 3303 -a '-te battery 32000 charger 32000'

    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService----------------------------------
    Report temperature [ battery ]: 32000
    Report temperature [ charger ]: 32000
    $ hidumper -s 3303 -a '-te battery 39000 charger 39000'

    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService----------------------------------
    Report temperature [ battery ]: 39000
    Report temperature [ charger ]: 39000
    ```

5. 获取当前温度等级信息。
    ```shell
    hidumper -s 3303 -a -l
    ```

    查看上传模拟温度后的温度等级信息如下：
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService----------------------------------
    name: base_safe level: 1
    name: cold_safe level: 0
    name: high_safe level: 0
    name: screenoff_charge  level: 0
    name: warm_5G   level: 0
    name: warm_safe level: 0
    ```

6. 查看温控结点信息。
    ```shell
    cat /data/service/el0/thermal/config/process_ctrl
    ```

    查看温控结点信息如下，表明process_ctrl热管控策略正确执行：
    ```shell
    3
    ```

## 参考 
开发过程中可参考的配置文件路径：[默认热管控源码路径](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)

打包路径：`/vendor/etc/thermal_config/hdf`


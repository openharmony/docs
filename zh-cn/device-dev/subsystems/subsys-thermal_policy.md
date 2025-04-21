# 热策略定制开发指导

## 概述 

### 简介 

OpenHarmony默认提供了热策略的特性。设备上发热的器件种类繁多，因此需要结合热等级和热场景，针对各类发热器件定制统一的管控策略。但是不同热等级下的管控动作在不同的产品上规格是不同的，产品希望根据产品的设计规格来定制此特性。OpenHarmony提供了热策略的定制方式，产品定制开发者可根据产品的设计规格来定制这些特性。同时，出于安全性考虑，提供了热策略配置文件加解密的功能支持（可选）。

### 约束与限制

产品定制的配置路径，需要根据[配置策略](https://gitee.com/openharmony/customization_config_policy)决定。本开发指导中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤 

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍热策略的定制方法。

1. 在产品目录[（/vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建thermal文件夹。

2. 参考[默认热策略的配置文件夹](https://gitee.com/openharmony/powermgr_thermal_manager/tree/master/services/native/profile)创建目标文件夹，并安装到`//vendor/hihope/rk3568/thermal`，文件格式如下：
     
    ```text
    profile
    ├── BUILD.gn
    ├── thermal_service_config.xml
    ```

3. 参考[默认热策略的配置文件夹中的thermal_service_config.xml](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)编写定制的thermal_service_config.xml。包含热策略配置说明及定制后的热策略配置如下，以其中两个热等级为例：

    **表1** config配置说明

    | 配置项名称 | 配置项描述 | 配置项类型 | 配置项范围 |
    | -------- | -------- | -------- | -------- |
    | name | 定义热策略对应的传感器集合名称 | string | 对应[热等级文档](../subsystems/subsys-thermal_level.md)中定义的传感器集合名称 |
    | level | 定义热策略对应的热等级 | int | 对应[热等级文档](../subsystems/subsys-thermal_level.md)中传感器集合下定义的热等级 |
    
    **表2** 配置项说明

    | 配置项名称 | 配置项描述 | 配置项类型 | 配置项范围 |
    | -------- | -------- | -------- | -------- |
    | scene	| 使用场景 | string | 对应[热场景文档](../subsystems/subsys-thermal_scene.md)中定义的使用场景 |
    | charge | 是否在充电 | int | 0（不在充电），1（正在充电） |
    | screen | 是否亮屏 | int | 0（灭屏），1（亮屏） |

    **表3** 节点配置说明

    | 节点名称 | 节点值类型 | 节点值范围 | 节点描述 |
    | -------- | -------- | -------- | -------- |
    | lcd | double | 0.00~1.00 | 屏幕亮度的百分比（用浮点数表示） |
    | cpu_big | int | 根据产品定义 | CPU大核频率 |
    | cpu_med | int | 根据产品定义 | CPU中核频率 |
    | cpu_lit | int | 根据产品定义 | CPU小核频率 |
    | process_ctrl | enum | 1：KILL_FG_PROCESS_APP<br>2：KILL_BG_PROCESS_APP<br>3：KILL_ALL_PROCESS_APP | 进程控制 |
    | gpu | int | 根据产品定义 | GPU频率 |
    | thermallevel | int | 对应config节点中的level | 热等级 |
    | current_sc | int | 根据产品定义 | 快充电流 |
    | current_buck | int | 根据产品定义 | 慢充电流 |
    | voltage_sc | int | 根据产品定义 | 快充电压 |
    | voltage_buck | int | 根据产品定义 | 慢充电压 |
    | volume | double | 0.00~1.00 | 音量百分比（用浮点数表示） |

    ```shell
    <policy>
        <config name="base_safe" level="1">
            <lcd>1.00</lcd>
            <lcd scene="cam">0.99</lcd>
            <lcd scene="call">0.98</lcd>
            <lcd scene="game">0.95</lcd>
            <cpu_big>1992000</cpu_big>
            <cpu_med>1991500</cpu_med>
            <cpu_lit>1991200</cpu_lit>
            <process_ctrl>3</process_ctrl>
            <cpu_big scene="cam" charge="1">1991800</cpu_big>
            <cpu_big scene="cam" charge="0">1991600</cpu_big>
            <gpu screen="0">524288</gpu>
            <gpu screen="1">512000</gpu>
            <thermallevel>1</thermallevel>
            <current_sc>1800</current_sc>
            <current_sc scene="cam">1200</current_sc>
            <current_buck>1200</current_buck>
            <voltage_sc>4000</voltage_sc>
            <voltage_buck>3000</voltage_buck>
            <volume>1.0</volume>
        </config>
    <policy>
        <config name="base_safe" level="2">
            <lcd>0.90</lcd>
            <lcd scene="cam">0.89</lcd>
            <lcd scene="call">0.88</lcd>
            <lcd scene="game">0.87</lcd>
            <cpu_big>1991000</cpu_big>
            <cpu_med>1990500</cpu_med>
            <cpu_lit>1990200</cpu_lit>
            <process_ctrl>2</process_ctrl>
            <cpu_big scene="cam" charge="1">1990800</cpu_big>
            <cpu_big scene="cam" charge="0">1990600</cpu_big>
            <gpu screen="0">499712</gpu>
            <gpu screen="1">487424</gpu>
            <thermallevel>2</thermallevel>
            <current_sc>1500</current_sc>
            <current_sc scene="cam">1000</current_sc>
            <current_buck>1000</current_buck>
            <voltage_sc>3000</voltage_sc>
            <voltage_buck>2000</voltage_buck>
            <volume>0.8</volume>
        </config>
    </policy>
    ```

4. （可选）对热策略配置文件进行本地加密，同时配置解密方法。

    1. 开发者自行选择合适的加密工具对本地将编写好的thermal_service_config.xml进行加密。

    2. 开发者需要编写动态库libthermal_manager_ext.z.so并安装在文件系统中，动态库中包含解密接口getDecryptConfig的实现，程序将调用动态库中实现了的getDecryptConfig（在[base/powermgr/thermal_manager/services/native/src/thermal_policy/thermal_srv_config_parser.cpp](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/src/thermal_policy/thermal_srv_config_parser.cpp)中）对配置文件进行解密，解密过程如下所示：

        ```c++
        bool ThermalSrvConfigParser::DecryptConfig(const std::string& path, std::string& result)
        {
            // 请开发者自行实现动态库libthermal_manager_ext.z.so
            void *handler = dlopen(THERMAL_CONFIG_LIBRARY_PATH, RTLD_LAZY);
            if (handler == nullptr) {
                THERMAL_HILOGE(COMP_SVC, "dlopen failed, reason : %{public}s", dlerror());
                return false;
            }
            // 请开发者根据所使用的工具自行实现解密接口getDecryptConfig
            Func getDecryptConfig = reinterpret_cast<Func>(dlsym(handler, GET_THERMAL_EXT_CONGIH_FUNC)); 
            if (getDecryptConfig == nullptr) {
                THERMAL_HILOGE(COMP_SVC, "find function %{public}s failed, reason : %{public}s",
                    GET_THERMAL_EXT_CONGIH_FUNC, dlerror());
                dlclose(handler);
                return false;
            }
            // 调用解密接口进行解密，将解密结果以字符串的形式存储在result中
            int32_t ret = getDecryptConfig(THERMAL_SERVICE_CONFIG_INDEX, result);
            if (ret != 0) {
                THERMAL_HILOGE(COMP_SVC, "decrypt config failed, ret:%{public}d", ret);
                dlclose(handler);
                return false;
            }
            dlclose(handler);
            return true;
        }
        ```

5. 参考[默认热策略配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/BUILD.gn)编写BUILD.gn文件，将thermal_service_config.xml打包到`/vendor/etc/thermal_config`目录下：

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

2. 获取当前热策略信息。
    ```shell
    hidumper -s 3303 -a -p
    ```

    查看定制后的热策略结果如下：
    ```shell
    -------------------------------[ability]-------------------------------


    ----------------------------------ThermalService---------------------------------
    name: base_safe	level: 1
    actionName: lcd	actionValue: 1.00	isProp: 0
    actionName: lcd	actionValue: 0.99	scene: cam	isProp: 1
    actionName: lcd	actionValue: 0.98	scene: call	isProp: 1
    actionName: lcd	actionValue: 0.95	scene: game	isProp: 1
    actionName: cpu_big	actionValue: 1992000	isProp: 0
    actionName: cpu_med	actionValue: 1991500	isProp: 0
    actionName: cpu_lit	actionValue: 1991200	isProp: 0
    actionName: process_ctrl	actionValue: 3	isProp: 0
    actionName: cpu_big	actionValue: 1991800	charge: 1	scene: cam	isProp: 1
    actionName: cpu_big	actionValue: 1991600	charge: 0	scene: cam	isProp: 1
    actionName: gpu	actionValue: 524288	screen: 0	isProp: 1
    actionName: gpu	actionValue: 512000	screen: 1	isProp: 1
    actionName: thermallevel	actionValue: 1	isProp: 0
    actionName: current_sc	actionValue: 1800	isProp: 0
    actionName: current_sc	actionValue: 1200	scene: cam	isProp: 1
    actionName: current_buck	actionValue: 1200	isProp: 0
    actionName: voltage_sc	actionValue: 4000	isProp: 0
    actionName: voltage_buck	actionValue: 3000	isProp: 0
    actionName: volume	actionValue: 1.0	isProp: 0
    actionName: boost	actionValue: 1	isProp: 0

    level: 2
    actionName: lcd	actionValue: 0.90	isProp: 0
    actionName: lcd	actionValue: 0.89	scene: cam	isProp: 1
    actionName: lcd	actionValue: 0.88	scene: call	isProp: 1
    actionName: lcd	actionValue: 0.87	scene: game	isProp: 1
    actionName: cpu_big	actionValue: 1991000	isProp: 0
    actionName: cpu_med	actionValue: 1990500	isProp: 0
    actionName: cpu_lit	actionValue: 1990200	isProp: 0
    actionName: process_ctrl	actionValue: 2	isProp: 0
    actionName: cpu_big	actionValue: 1990800	charge: 1	scene: cam	isProp: 1
    actionName: cpu_big	actionValue: 1990600	charge: 0	scene: cam	isProp: 1
    actionName: gpu	actionValue: 499712	screen: 0	isProp: 1
    actionName: gpu	actionValue: 487424	screen: 1	isProp: 1
    actionName: thermallevel	actionValue: 2	isProp: 0
    actionName: current_sc	actionValue: 1500	isProp: 0
    actionName: current_sc	actionValue: 1000	scene: cam	isProp: 1
    actionName: current_buck	actionValue: 1000	isProp: 0
    actionName: voltage_sc	actionValue: 3000	isProp: 0
    actionName: voltage_buck	actionValue: 2000	isProp: 0
    actionName: volume	actionValue: 0.8	isProp: 0
    actionName: boost	actionValue: 1	isProp: 0
    ```

## 参考 
开发过程中可参考的配置文件路径：[默认热策略源码路径](https://gitee.com/openharmony/powermgr_thermal_manager/blob/master/services/native/profile/thermal_service_config.xml)

打包路径：`/vendor/etc/thermal_config/hdf`


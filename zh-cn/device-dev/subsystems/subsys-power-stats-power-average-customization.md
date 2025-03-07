# 耗电统计定制开发指导 

## 概述 

### 简介 

OpenHarmony默认提供了耗电统计的特性。由于不同产品的硬件规格是不同的，各个硬件的耗电基准也不同。产品希望根据产品的设计规格来定制耗电基准。OpenHarmony提供了耗电基准的定制方式，产品定制开发者可根据产品的设计规格来定制。

### 基本概念 

耗电统计：在用户使用设备的过程中，各种软硬件服务会通过[HiSysEvent](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-dfx-hisysevent-overview.md)上报软硬件的使用事件，根据这些事件可以计算软硬件的使用时长，然后基于硬件的耗电基准，统计所得软硬件的耗电量。

耗电基准：产品硬件在各种状态下的基准耗电量（单位：毫安时），如相机打开时的基准耗电量，CPU在各种频率下的基准耗电量等。

### 约束与限制

按照[配置策略组件介绍](https://gitee.com/openharmony/customization_config_policy)的说明，设定产品定制的配置路径，需要根据配置策略决定。本开发指南中的定制路径以`/vendor`进行举例，请开发者根据具体的产品配置策略，修改定制路径。

## 开发指导

### 搭建环境 

设备要求：

标准系统开发板，如DAYU200/Hi3516DV300开源套件。

环境要求：

Linux调测环境，相关要求和配置可参考《[快速入门](../quick-start/quickstart-overview.md)》。

### 开发步骤

本文以[DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)为例介绍耗电统计的定制方法。

1. 在产品目录[（vendor/hihope/rk3568）](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568)下创建battery_statistics文件夹。


2. 参考[默认耗电统计配置文件夹](https://gitee.com/openharmony/powermgr_battery_statistics/tree/master/services/profile)创建目标文件夹，并安装到`vendor/hihope/rk3568/battery_statistics`目录，文件格式如下：

    ```shell
    profile
    ├── BUILD.gn           # BUILD.gn文件
    └── power_average.json # 耗电统计配置文件，包含硬件的耗电基准
    ```

3. 参考[默认耗电统计配置文件夹中的power_average.json](https://gitee.com/openharmony/powermgr_battery_statistics/blob/master/services/profile/power_average.json)编写定制的power_average.json，包含定制后的耗电基准。详细说明如下：

    **表1** 耗电基准配置项说明
    | 配置项 | 硬件类型 | 数据类型 | 描述 |
    |----------|------|---------|-------------------------------------------------------------------------|
    | alarm_on | - | Double | 定时器Timer触发一次耗电量，即基准耗电量，用于计算系统或者应用对Timer使用的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 触发次数 * 耗电基准 |
    | bluetooth_br_on | Bluetooth | Double | 蓝牙开启时的基准耗电量，用于计算蓝牙开启过程中的功耗。<br/>-&nbsp;功耗类型：硬件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | bluetooth_br_scan | Bluetooth | Double | 蓝牙扫描状态的基准耗电量，用于计算蓝牙扫描过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | bluetooth_ble_on | Bluetooth | Double | 低功耗蓝牙开启时的基准耗电量，用于计算蓝牙开启过程中的功耗。<br/>-&nbsp;功耗类型：硬件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | bluetooth_ble_scan | Bluetooth | Double | 低功耗蓝牙扫描状态的基准耗电量，用于计算蓝牙扫描过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | wifi_on | WIFI | Double | WIFI开启时的基准耗电量，用于计算WIFI开启过程中的功耗。<br/>-&nbsp;功耗类型：硬件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | wifi_scan | WIFI | Double | WIFI扫描一次耗电量，用于计算WIFI扫描时的功耗。<br/>-&nbsp;功耗类型：硬件功耗<br/>-&nbsp;统计方法：耗电量 = 触发次数 * 耗电基准 |
    | radio_on | Phone | Double数组 | 通话开启时的基准耗电量，数组形式，用于配置不同等级信号强度的基准耗电量。默认配置包括4个信号等级的基准耗电信息。<br/>-&nbsp;功耗类型：硬件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | radio_data | Phone | Double数组 | 网络开启时的基准耗电量，数组形式，用于配置不同等级信号强度的基准耗电量。默认配置包括4个信号等级的基准耗电信息。<br/>-&nbsp;功耗类型：硬件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | camera_on | Camera | Double | 相机开启时的基准耗电量，用于计算相机开启过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | flashlight_on | Flashlight | Double | 闪光灯开启时的基准耗电量，用于计算闪光灯开启过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | gnss_on | GNSS | Double | GNSS（Global Navigation Satellite System）开启时的基准耗电量，用于计算GNSS开启过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | sensor_gravity_on | Gravity Sensor | Double | 重力传感器开启时的基准耗电量，用于计算重力传感器开启过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | sensor_proximity_on | Proximity Sensor | Double | 接近传感器开启时的基准耗电量，用于计算接近传感器开启过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | audio_on | Audio | Double | 音响开启时的基准耗电量，用于计算音响开启过程中的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | screen_on<br/>screen_brightness | Screen | Double | screen_on：屏幕的基础状态下的基准耗电量（不包括屏幕亮度产生的耗电量）；<br/>screen_brightness：屏幕亮度每提升一个等级，需要额外增加的基准耗电量；<br/>例如：假定条件，screen_on = 90，screen_brightness = 2，屏幕亮度为100，屏幕亮度100时的基准耗电量：90 + 2 * 100 = 290<br/>-&nbsp;功耗类型：硬件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | cpu_awake | CPU | Double | CPU唤醒锁持锁状态时的基准耗电量，用于计算CPU唤醒锁持锁状态时的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | cpu_idle | CPU | Double | CPU空闲状态时的基准耗电量，用于计算CPU空闲状态的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | cpu_suspend | CPU | Double | CPU休眠状态时的基准耗电量，用于计算CPU休眠状态的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | cpu_active | CPU | Double | CPU活动状态时的基准耗电量，用于计算CPU活动状态的功耗。<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |
    | cpu_clusters<br/>cpu_speed_clusterX | CPU | Double数组 | cpu_clusters：cpu cluster的基准耗电量，数组形式，用于配置不同cpu cluster基准耗电量。默认配置包括3个不同cpu cluster基准耗电信息。<br/>cpu_speed_clusterX：cpu cluster不同频率的基准耗电量，数组形式。X代表序号，默认配置中X的范围0~2，对应cpu_clusters数组大小。例如：默认配置cpu_clusters的数组大小为3，顺序对应配置项cpu_speed_cluster0、cpu_speed_cluster1、cpu_speed_cluster2。<br/>-&nbsp;扩展性：可扩展<br/>-&nbsp;功耗类型：软件功耗<br/>-&nbsp;统计方法：耗电量 = 持续时间 * 耗电基准 |

    >说明：表格中描述的硬件类型为真实硬件名称，不代表耗电统计类型，具体的耗电统计类型，请参考[ConsumptionType](../../application-dev/reference/apis-basic-services-kit/js-apis-batteryStatistics-sys.md#consumptiontype)定义。

4. 参考[默认耗电统计配置文件夹中的BUILD.gn](https://gitee.com/openharmony/powermgr_battery_statistics/blob/master/services/profile/BUILD.gn)编写BUILD.gn文件，将power_average.json打包安装到`/vendor/etc/profile`目录下，例如： 

    ```shell
    import("//build/ohos.gni")                  # 引用build/ohos.gni

    # Install power_average.json to /vendor/etc/profile/power_average.json
    ohos_prebuilt_etc("power_average_config") { # 自定义名称，例子中用名：power_average_config
        source = "power_average.json"
        relative_install_dir = "profile"
        install_images = [ chipset_base_dir ]   # 安装到vendor目录下的必要配置，chipset_base_dir = “vendor”， 如果不配置，默认安装到system目录
        part_name = "product_rk3568"            # part_name为product_rk3568，以实现后续编译
    }
    ```

5. 将编译目标添加到`/vendor/hihope/rk3568`目录下[ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build)的“module_list”中，例如：

    ```json
    {
      "parts": {
          "product_rk3568": {
          "module_list": [
              "//vendor/hihope/rk3568/default_app_config:default_app_config",
              "//vendor/hihope/rk3568/image_conf:custom_image_conf",
              "//vendor/hihope/rk3568/battery_statistics/profile:power_average_config", # 添加power_average_config的编译
              "//vendor/hihope/rk3568/preinstall-config:preinstall-config",
              "//vendor/hihope/rk3568/resourceschedule:resourceschedule",
              "//vendor/hihope/rk3568/etc:product_etc_conf"
          ]
          }
      },
      "subsystem": "product_hihope"
    }
    ``` 

    “//vendor/hihope/rk3568/power/battery_statistics/”为文件夹路径，“profile”为创建的文件夹名字，“power_average_config”为编译目标。

6. 参考《[快速入门](../quick-start/quickstart-overview.md)》编译定制版本，编译命令如下：

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. 将定制版本烧录到DAYU200开发板中。

### 调测验证 

1. 开机后，先进入shell命令行。

    ```shell
    hdc shell
    ```

2. 执行下列命令，观察vendor目录下power_average.json是否创建成功。

    ```shell
    ls -l /vendor/etc/profile/
    ```

    创建成功，在/vendor/etc/profile/存在配置文件power_average.json。

    ```shell
    # ls -l /vendor/etc/profile/                                                   
    total 4
    -rw-r--r-- 1 root root 1446 2023-03-26 16:47 power_average.json
    # 
    ```

3. 如果创建成功，执行下列命令，观察vendor目录下power_average.json中的信息是否与定制信息一致。

    ```shell
    cat /vendor/etc/profile/power_average.json
    ```

4. 如果信息一致，执行下列命令，观察console输出。

    ```shell
    hidumper -s 3304 -a -poweraverage
    ```

5. console输出的是定制后的耗电基准信息，如：

    定制耗电统计之前，使用默认耗电基准为：

    ```shell
    # hidumper -s 3304 -a -poweraverage                                            

    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryStatisticsService---------------------------------
    POWER AVERAGE CONFIGATION DUMP:

    ······（省略其他，只显示camera的配置）

    camera_on : 810.000000

    ······
    ```

    本节以“camera_on”：3000为例（默认值为810），更改之后：

    ```shell
    # hidumper -s 3304 -a -poweraverage                                            

    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryStatisticsService---------------------------------
    POWER AVERAGE CONFIGATION DUMP:

    ······（省略其他，只显示camera的配置）

    camera_on : 3000.000000 # 修改后，“camera_on”：3000

    ······
    ```

6. 耗电统计配置文件定制成功后，耗电统计会根据定制的耗电基准进行计算。

7. 通过batterystatistics模块提供的[JS API](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.batteryStatistics.d.ts)或[Inner API](https://gitee.com/openharmony/powermgr_battery_statistics/blob/master/interfaces/inner_api/include/battery_stats_client.h)可以获得详细的耗电信息，验证定制的耗电基准。

## 参考 

开发过程中可参考的配置文件路径：[系统默认耗电统计配置源码路径](https://gitee.com/openharmony/powermgr_battery_statistics/tree/master/services/profile) 

默认打包路径：/system/etc/profile

定制路径：/vendor/etc/profile

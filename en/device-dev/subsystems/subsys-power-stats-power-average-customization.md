# Power Consumption Statistics Customization

## Overview

### Introduction

By default, OpenHarmony provides the power consumption statistics feature. However, the power consumption benchmarks vary according to hardware specifications of different products.  To address this issue, OpenHarmony provides the power consumption statistics customization function, allowing you to customize power consumption benchmarks depending on your hardware specifications.

### Basic Concepts

Power consumption statistics: When a user uses a device, software and hardware services running on the device report usage events through [HiSysEvent](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-dfx-hisysevent-overview.md). The usage duration of software and hardware can be calculated based on these reported events. Then, the power consumption of the software and hardware can be calculated based on the hardware power consumption benchmarks.

Power consumption benchmark: baseline power consumption (unit: mA) of the product hardware in various states, for example, the baseline power consumption when the camera is turned on and the baseline power consumption of the CPU at different frequencies.

### Constraints

The configuration path for power consumption statistics customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate power consumption statistics customization.

1. Create the `battery_statistics` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).


2. Create a target folder by referring to the [default folder of power consumption statistics configuration](https://gitee.com/openharmony/powermgr_battery_statistics/tree/master/services/profile), and install it in `//vendor/hihope/rk3568/battery_statistics`. The content is as follows:

    ```shell
    profile
    ├── BUILD.gn           # BUILD.gn file
    └── power_average.json # Configuration file for power consumption statistics, including the hardware power consumption benchmarks
    ```

3. Write the custom `power_average.json` file by referring to the [power_average.json](https://gitee.com/openharmony/powermgr_battery_statistics/blob/master/services/profile/power_average.json) file in the default folder of power consumption statistics configuration. The following table describes the configuration items for power consumption benchmarks.

    **Table 1** Description of the configuration items for power consumption benchmarks
    | Configuration Item| Hardware Type| Data Type| Description|
    |----------|------|---------|-------------------------------------------------------------------------|
    | alarm_on | - | Double | Power consumption when the timer is triggered by the system or application once; that is, the baseline power consumption.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Number of triggering times x Power consumption benchmark|
    | bluetooth_br_on | Bluetooth | Double | Baseline power consumption when Bluetooth is enabled.<br>- Power consumption type: hardware power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | bluetooth_br_scan | Bluetooth | Double | Baseline power consumption for Bluetooth scanning.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | bluetooth_ble_on | Bluetooth | Double | Baseline power consumption when Bluetooth Low Energy (BLE) is enabled.<br>- Power consumption type: hardware power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | bluetooth_ble_scan | Bluetooth | Double | Baseline power consumption for Bluetooth Low Energy (BLE) scanning.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | wifi_on | WIFI | Double | Baseline power consumption when Wi-Fi is enabled.<br>- Power consumption type: hardware power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | wifi_scan | WIFI | Double | Power consumption when Wi-Fi scanning is performed once.<br>- Power consumption type: hardware power consumption<br>- Statistical method: Power consumption = Number of triggering times x Power consumption benchmark|
    | radio_on | Phone | Double array| Baseline power consumption when the call service is enabled. The value is in array format and is used to configure the baseline power consumption for different signal strength levels. The default configuration provides the baseline power consumption for four signal strength levels.<br>- Power consumption type: hardware power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | radio_data | Phone | Double array| Baseline power consumption when the network service is enabled. The value is in array format and is used to configure the baseline power consumption for different signal strength levels. The default configuration provides the baseline power consumption for four signal strength levels.<br>- Power consumption type: hardware power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | camera_on | Camera | Double | Baseline power consumption when the camera is enabled.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | flashlight_on | Flashlight | Double | Baseline power consumption when the flashlight is enabled.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | gnss_on | GNSS | Double | Baseline power consumption when the Global Navigation Satellite System (GNSS) is enabled.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | sensor_gravity_on | Gravity Sensor | Double | Baseline power consumption when the gravity sensor is enabled.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | sensor_proximity_on | Proximity Sensor | Double | Baseline power consumption when the proximity sensor is enabled.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | audio_on | Audio | Double | Baseline power consumption when the audio is enabled.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | screen_on<br>screen_brightness | Screen | Double | **screen\_on**: baseline power consumption of the screen in the basic state (excluding power consumption generated by screen brightness).<br>**screen\_brightness**: baseline power consumption additionally required when the screen brightness increases by one level.<br>For example, if **screen_on** is **90**, **screen_brightness** is **2**, and the screen brightness is **100**, then the baseline power consumption is calculated as follows: 90 + 2 x 100 = 290.<br>- Power consumption type: hardware power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | cpu_awake | CPU | Double | Baseline power consumption when the CPU wakes up the lock from the lock holding state.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | cpu_idle | CPU | Double | Baseline power consumption when the CPU is in the idle state.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | cpu_suspend | CPU | Double | Baseline power consumption when the CPU is in the sleep state.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | cpu_active | CPU | Double | Baseline power consumption when the CPU is in the active state.<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|
    | cpu_clusters<br>cpu_speed_clusterX | CPU | Double array| **cpu\_clusters**: baseline power consumption of a CPU cluster. The value is in array format and is used to configure the baseline power consumption for different CPU clusters. The default configuration provides the baseline power consumption for three CPU clusters.<br>**cpu\_speed\_clusterX**: baseline power consumption of a CPU cluster at different frequencies, in array format. **X** indicates the sequence number. By default, its value ranges from **0** to **2**, corresponding to the size of the **cpu_clusters** array. For example, if the default size of the **cpu_clusters** array is **3**, the sequence number corresponds to the configuration items **cpu_speed_cluster0**, **cpu_speed_cluster1**, and **cpu_speed_cluster2**.<br>- Scalability: scalability of CPU clusters<br>- Power consumption type: software power consumption<br>- Statistical method: Power consumption = Usage duration x Power consumption benchmark|

    >**NOTE**<br>The hardware type described in the table is the actual hardware name and does not represent the power consumption statistics type. For details about the power consumption statistics type, see [ConsumptionType](../../application-dev/reference/apis-basic-services-kit/js-apis-batteryStatistics-sys.md#consumptiontype).

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_battery_statistics/blob/master/services/profile/BUILD.gn) file in the default folder of power consumption statistics configuration to pack the `power_average.json` file to the `//vendor/etc/profile` directory. The configuration is as follows:

    ```shell
    import("//build/ohos.gni")                  # Reference build/ohos.gni.

    # Install power_average.json to /vendor/etc/profile/power_average.json
    ohos_prebuilt_etc("power_average_config") { # Custom name, for example, power_average_config.
        source = "power_average.json"
        relative_install_dir = "profile"
        install_images = [ chipset_base_dir ]   # Required configuration for installing the power_average_config file in the vendor directory, where chipset_base_dir = "vendor". If this field is left unspecified, the power_average_config file is installed in the system directory by default.
        part_name = "product_rk3568"            # Set part_name to product_rk3568 for subsequent build.
    }
    ```

5. Add the build target to `module_list` in [ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build) in the `/vendor/hihope/rk3568` directory. For example:

    ```json
    {
      "parts": {
          "product_rk3568": {
          "module_list": [
              "//vendor/hihope/rk3568/default_app_config:default_app_config",
              "//vendor/hihope/rk3568/image_conf:custom_image_conf",
              "//vendor/hihope/rk3568/battery_statistics/profile:power_average_config", # Add the configuration for building of power_average_config.
              "//vendor/hihope/rk3568/preinstall-config:preinstall-config",
              "//vendor/hihope/rk3568/resourceschedule:resourceschedule",
              "//vendor/hihope/rk3568/etc:product_etc_conf"
          ]
          }
      },
      "subsystem": "product_hihope"
    }
    ``` 

    In the preceding code, `//vendor/hihope/rk3568/power/battery_statistics/` is the folder path, `profile` is the folder name, and `power_average_config` is the build target.

6. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

7. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. After startup, run the following command to launch the shell command line:

    ```shell
    hdc shell
    ```

2. Run the following command to check whether the `power\_average\_config` file is successfully created in the `vendor` directory:

    ```shell
    ls -l /vendor/etc/profile/
    ```

    The `power\_average\_config` file is successfully created if it exists in `/vendor/etc/profile/`.

    ```shell
    # ls -l /vendor/etc/profile/                                                   
    total 4
    -rw-r--r-- 1 root root 1446 2023-03-26 16:47 power_average.json
    # 
    ```

3. If the `power_average_config` file is successfully created, run the following command to check whether the information in the `power_average_config` file in the `vendor` directory is consistent with the customized information:

    ```shell
    cat /vendor/etc/profile/power_average.json
    ```

4. If the information is consistent, run the following command to view the power consumption statistics:

    ```shell
    hidumper -s 3304 -a -poweraverage
    ```

5. Check the console output for the custom power consumption benchmark information.

    For example, the default power consumption benchmark information is as follows:

    ```shell
    # hidumper -s 3304 -a -poweraverage                                            

    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryStatisticsService---------------------------------
    POWER AVERAGE CONFIGATION DUMP:

    ··· (Only the camera configuration is displayed here. Other information is omitted.)

    camera_on : 810.000000

    ······
    ```

    If the power consumption statistics benchmark is set to **camera_on:3000** (default value: **810**), the console output is as follows:

    ```shell
    # hidumper -s 3304 -a -poweraverage                                            

    -------------------------------[ability]-------------------------------


    ----------------------------------BatteryStatisticsService---------------------------------
    POWER AVERAGE CONFIGATION DUMP:

    ··· (Only the camera configuration is displayed here. Other information is omitted.)

    camera_on : 3000.000000 # Set the power consumption benchmark to "camera_on": 3000.

    ······
    ```

6. Check whether the power consumption statistics are calculated according to the custom power consumption benchmark in the `power_average_config` file.

7. You can use the [JS APIs](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.batteryStatistics.d.ts) or [Inner APIs](https://gitee.com/openharmony/powermgr_battery_statistics/blob/master/interfaces/inner_api/include/battery_stats_client.h) provided by the **batterystatistics** module to obtain detailed power consumption information and verify the custom power consumption benchmark.

## Reference

During development, you can refer to the [default power consumption statistics configuration](https://gitee.com/openharmony/powermgr_battery_statistics/blob/master/services/profile/power_average.json).

Default packing path: /system/etc/profile

Customization path: /vendor/etc/profile

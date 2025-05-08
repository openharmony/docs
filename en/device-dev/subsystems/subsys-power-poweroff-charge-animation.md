# Power-off Charging Animation Customization

## Overview

### Introduction

By default, the OpenHarmony provides the animation that displays information such as the battery level during power-off charging. However, some vendors may expect to use custom power-off charging animations for their products. To address this requirement, OpenHarmony provides the function of customizing power-off charging animations.

### Constraints

 
The configuration path for battery level customization is subject to the [configuration policy](https://gitee.com/openharmony/customization_config_policy). In this development guide, `/vendor` is used as an example of the configuration path. During actual development, you need to modify the customization path based on the product configuration policy.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate power-off charging animation customization.

1. Create the `animation` folder in the product directory [/vendor/hihope/rk3568](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568).

2. Create a target folder by referring to the [default folder of power-off charging animation configuration](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/charger/sa_profile), and install it in `//vendor/hihope/rk3568/animation`. The content is as follows:

    ```text
    profile
    ├── BUILD.gn
    ├── animation.json
    ```

3. Create the `resources` folder by referring to [default folder of power-off charging animation image resources](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/charger/resources) to store the images that form the animation, and install the folder in `//vendor/hihope/rk3568/animation`. The content is as follows:

    ```text
    animation
    ├── resources
    ├── profile
    ```

4. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/charger/resources/BUILD.gn) in the default folder of power-off charging animation configuration, and put it to the `//vendor/hihope/rk3568/animation/resource` directory. The configuration is as follows:
    ```gn
    import("//build/ohos.gni")

    ohos_prebuilt_etc("resources_config0") {
        source = "loop00000.png"                                        # Image resource
        relative_install_dir = "poweroff_charger_animation/resources"
        install_images = [ chipset_base_dir ]                           # Required configuration for installing the resources folder in the vendor directory.
        part_name = "product_rk3568"
    }
    ```

5. Write the custom **animation.json** file by referring to the [animation.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/charger/sa_profile/animation.json) file in the default folder of power-off charging animation image resources.  The configuration is as follows:

    ```json
    {
        "animation": {
            "components": [
                {
                    "type": "UIImageView",
                    "id": "Charging_Animation_Image",
                    "x": 200,
                    "y": 480,
                    "w": 400,
                    "h": 400,
                    "resPath": "/system/etc/charger/resources/",
                    "imgCnt": 62,
                    "updInterval": 60,
                    "filePrefix": "loop"
                },
                {
                    "type": "UILabel",
                    "id": "Charging_Percent_Label",
                    "text": "",
                    "x": 326,
                    "y": 616,
                    "w": 68,
                    "h": 48,
                    "fontSize": 32,
                    "fontColor": "#ffffffe6",
                    "bgColor": "#00000000"
                    "align": "center"
                }
            ]
        },
        "lackpowerChargingPrompt": {
            "components": [
                {
                    "type": "UILabel",
                    "id": "LackPower_Charging_Label",
                    "text": "Low battery level",
                    "x": 229,
                    "y": 1037,
                    "w": 250,
                    "h": 45,
                    "fontSize": 42,
                    "fontColor": "#ff0000ff",
                    "bgColor": "#00000000",
                    "align": "center"
                }
            ]
        },
        "lackpowerNotChargingPrompt": {
            "components": [
                {
                    "type": "UILabel",
                    "id": "LackPower_Not_Charging_Label",
                    "text": "Low battery level. Please connect the power supply.",
                    "x": 110,
                    "y": 1037,
                    "w": 500,
                    "h": 45,
                    "fontSize": 42,
                    "fontColor": "#ff0000ff",
                    "bgColor": "#00000000",
                    "align": "center"
                }
            ]
        }
    }
    ``` 

    **Table 1** Description of the power-off charging animation configuration
    | Item| Description|
    | -------- | -------- |
    | animation | Animation configuration.|
    | lackpowerChargingPrompt| Prompt for the **Charging** state in the low battery level.|
    | lackpowerNotChargingPrompt | Prompt for the **Not charging** state in the low battery level.|
    | components | Component set.|
    | type | Component type.|
    | id | Component ID.|
    | text | Text content of a component.|
    | x | X coordinate of the component.|
    | y | Y coordinate of the component.|
    | w | Component width, in pixels.|
    | h | Component height, in pixels.|
    | fontSize | Font size of the text.|
    | fontColor | Font color of the text.|
    | align | Text alignment mode.|
    | imgCnt | Number of images.|
    | updInterval | Image updating interval, in ms.|
    | filePrefix | Prefix of an image file name.|
    | resPath | Resource file path of the component.|



6. Write the `BUILD.gn` file by referring to the [BUILD.gn](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/charger/sa_profile/BUILD.gn) file in the default folder of power-off charging animation configuration to pack the `animation_config.json` file to the `//vendor/etc/charger` directory. The configuration is as follows:

    ```gn
    import("//build/ohos.gni")

    ohos_prebuilt_etc("animation_config") {
        source = "animation.json"             # Reference build/ohos.gni.
        relative_install_dir = "animation/resources"
        install_images = [ chipset_base_dir ] # Required configuration for installing the battery_config.json file in the vendor directory.
        part_name = "product_rk3568"          # Set part_name to product_rk3568 for subsequent build.
    }
    ```

7. Add the build target to `module_list` in [ohos.build](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/ohos.build) in the `/vendor/hihope/rk3568` directory. For example:

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
            "//vendor/hihope/rk3568/battery/profile:battery_config",
            "//vendor/hihope/rk3568/animation/profile:animation_config", # Add the configuration for building of animation_config.
            "//vendor/hihope/rk3568/animation/resource/resources_config" # Add the configuration for building of image resources.
        ]
        }
    },
    "subsystem": "product_hihope"
    }
    ```
    In the preceding code, `//vendor/hihope/rk3568/animation/` is the folder path, `profile` is the folder name, and `animation_config` is the build target.

8. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ``` 

9. Burn the customized version to the DAYU200 development board.

### Debugging and Verification
1. Modify the code configuration.<br>
    Code path: `base/startup/init/services/init/init_config.c`<br>
    Function: `ReadConfig`<br>
    Before:
    ```c
    void ReadConfig(void)
    {
        // parse cfg
        char buffer[32] = {0}; // 32 reason max leb
        uint32_t len = sizeof(buffer);
        SystemReadParam("ohos.boot.mode", buffer, &len);
        INIT_LOGI("ohos.boot.mode %s", buffer);
        if (strcmp(buffer, "charger_mode") == 0) {
            // Execute this branch process for product customization.
            ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
            ReadFileInDir(OTHER_CHARGE_PATH, ".cfg", ParseInitCfg, NULL);
            ParseInitCfgByPriority();
        } else if (strcmp(buffer, "charger") == 0) {
            ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
            ReadFileInDir(OTHER_CHARGE_PATH, ".cfg", ParseInitCfg, NULL);
        } else if (InUpdaterMode() == 0) {
            ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
            ParseInitCfgByPriority();
        } else {
            ReadFileInDir("/etc", ".cfg", ParseInitCfg, NULL);
        }
    }
    ```
    After:
    ```c
    void ReadConfig(void)
    {
        // parse cfg
        char buffer[32] = {0}; // 32 reason max leb
        uint32_t len = sizeof(buffer);
        SystemReadParam("ohos.boot.mode", buffer, &len);
        INIT_LOGI("ohos.boot.mode %s", buffer);
        ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
        ReadFileInDir(OTHER_CHARGE_PATH, ".cfg", ParseInitCfg, NULL);
        ParseInitCfgByPriority();
    }
    ```

2. Use the hdc tool to run the following commands to force the development board to enter the power-off charging state.
    ```shell
    hdc shell
    reboot charge
    ```

    ![animation_initial_power](figures/animation_initial_power.jpg)

3. Go to the custom battery level configuration directory. The path of DAYU200 is used as an example.
    ```shell
    cd /data/service/el0/battery/battery
    ```

4. Change the battery power, and observe the number change on the charging animation.
    ```shell
    cat capacity
    ```
    Change the current battery power to **3**.
    ```shell
    echo 3 > capacity
    ```
    ![animation_charing_power](figures/animation_charing_power.jpg)

5. Switch to the **Not charging** state. The device is powered off.
    ```shell
    echo Not charging > status
    ```

6. Change the charging status when the battery level is extremely low (1% by default). This can trigger the mapping animation or device shutdown.
    
    1. Go to the custom battery level configuration directory.
    ```shell
    cd /data/service/el0/battery/battery
    cat capacity
    ```
    2. Change the current battery power to **1**.
    ```shell
    echo 1 > capacity
    ```
    3. Check the charging status.
    ```shell
    cat status
    ```
    The current status is **Charging**.

    ![animation_low_power](figures/animation_low_power.jpg)

    4. Switch to the **Not charging** state.
    ```shell
    echo Not charging > status
    ```
    ![animation_low_power2](figures/animation_low_power2.jpg)

7. Test the power-off animation customization function by changing related images. The procedure is the same as that described above.

    1. Initial state

    ![animation_charging_power2](figures/animation_charging_power2.jpg)

    2. %3 battery power

    ![animation_initial_power2](figures/animation_initial_power2.jpg)

    3. 1% battery power, **Charging** state

    ![animation_low_power](figures/animation_low_power.jpg)

    4. 1% battery power, **Not charging** state

    ![animation_low_power2](figures/animation_low_power2.jpg)

    5. When the battery level is higher than 1%, the system switches to the **Not charging** state.
    ```shell
    echo 3 > capacity
    echo Not charging > status
    ```



## Reference
During development, you can refer to the [default power-off animation configuration](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/charger/sa_profile/animation.json), as shown below:

 
```json
{
        "animation": {
            "components": [
                {
                    "type": "UIImageView",
                    "id": "Charging_Animation_Image",
                    "x": 180,
                    "y": 410,
                    "w": 400,
                    "h": 400,
                    "resPath": "/system/etc/charger/resources/",
                    "imgCnt": 62,
                    "updInterval": 60,
                    "filePrefix": "loop"
                },
                {
                    "type": "UILabel",
                    "id": "Charging_Percent_Label",
                    "text": "",
                    "x": 365,
                    "y": 580,
                    "w": 65,
                    "h": 43,
                    "fontSize": 32,
                    "fontColor": "#ffffffe6",
                    "bgColor": "#00000000",
                    "align": "center"
                }
            ],
        },
        "lackpowerChargingPrompt": {
            "components": [
                {
                    "type": "UILabel",
                    "id": "LackPower_Charging_Label",
                    "text": "Low battery level",
                    "x": 229,
                    "y": 1037,
                    "w": 250,
                    "h": 45,
                    "fontSize": 42,
                    "fontColor": "#ff0000ff",
                    "bgColor": "#00000000",
                    "align": "center"
                }
            ]
        },
        "lackpowerNotChargingPrompt": {
            "components": [
                {
                    "type": "UILabel",
                    "id": "LackPower_Not_Charging_Label",
                    "text": "Low battery level. Please connect the power supply.",
                    "x": 110,
                    "y": 1037,
                    "w": 500,
                    "h": 45,
                    "fontSize": 42,
                    "fontColor": "#ff0000ff",
                    "bgColor": "#00000000",
                    "align": "center"
                }
            ]
        }
    }
``` 

Packing path: /system/etc/charger/resource

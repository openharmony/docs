# Battery Vibrator Customization

## Overview

### Introduction

OpenHarmony provides the vibrator customization function for the battery service. Specifically, you can modify the vibrator configuration file of the battery service so that vibration is triggered when a charger is connected to the device.

### Constraints

The device must be equipped with a vibrator.


## **How to Develop**

### Setting Up the Environment

- **Hardware requirements:**

  Development board running the standard system, for example, the DAYU200 open source suite, and connected to a vibrator

- **Environment requirements:**

  For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses the RK3568 development board as an example to illustrate battery charging vibration customization.

1. Write the custom `battery_vibrator.json` file by referring to the [battery_vibrator.json](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_vibrator.json) file in the default folder of battery vibrator configuration. 

    ```text
    profile
    ├── BUILD.gn
    ├── battery_config.json
    ├── battery_vibrator.json
    ```

    Example configuration:

    ```json
    {
        "start_charge": {
            "enable": true, 
            "type": "haptic.charging"
        }
    }
    ```
   - **start_charge**: name of the vibration scenario, which cannot be changed.

   - **enable**: whether to enable vibration. The value **true** indicates that vibration is enabled, and the value **false** indicates the opposite. The default value is **false**.

   - **type**: vibration type. The default value is **haptic.charging** in the current mode.

2. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. Burn the customized version to the RK3568 development board.

### Debugging and Verification

Upon device restarting, connect a charger to the device and check whether the device vibrates. If the device vibrates, the customization is successful.


## Reference

During development, you can refer to the default battery vibrator configuration:

[Default Battery Vibrator Configuration](https://gitee.com/openharmony/powermgr_battery_manager/blob/master/services/native/profile/battery_vibrator.json)

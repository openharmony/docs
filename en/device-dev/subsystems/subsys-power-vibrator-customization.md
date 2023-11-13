# Power Vibrator Customization

## Overview

### Introduction

OpenHarmony provides the vibrator customization function for the power service. Specifically, you can modify the vibrator configuration file of the power service so that vibration is triggered when the dialog for device power-off is displayed. 

### Basic Concepts

### Constraints

The device must be equipped with a vibrator.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 open source suite and connected to a vibrator

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses the DAYU200 development board as an example to illustrate power-off vibration customization.

1. Write the custom `power_vibrator.json` file by referring to the [power_vibrator.json](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_vibrator.json) file in the default folder of battery vibrator configuration. For example:

    ```json
    {
    "shutdown_diag": {
        "enable": true,
        "type": "haptic.long_press.heavy"
        }
    }
    ```
    - **shutdown_diag**: name of the vibration scenario, which cannot be changed.

    - **enable**: whether to enable vibration. The value **true** indicates that vibration is enabled, and the value **false** indicates the opposite. The default value is **false**.

    - **type**: vibration type. The default value is **haptic.long_press.heavy** in the current mode.

2. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. Burn the customized version to the DAYU200 development board.

### Commissioning and Verification

Press and hold the power button. The power-off dialog is displayed, and the device vibrates.

## Reference

[Default Power-off Vibration Configuration](https://gitee.com/openharmony/powermgr_power_manager/blob/master/services/native/profile/power_vibrator.json)

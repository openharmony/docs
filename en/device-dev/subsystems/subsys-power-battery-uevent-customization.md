# uevent Customization

## Overview

### Introduction

By default, OpenHarmony is designed to take an action based on the uevent received by the battery management system. To address your diverse demands, OpenHarmony provides the uevent customization function, allowing you to customize the uevents for taking desired actions. The customization is simply done through modification of the configuration file.

## How to Develop

### Setting Up the Environment

**Hardware requirements:**

Development board running the standard system, for example, the DAYU200 or Hi3516D V300 open source suite.

**Environment requirements:**

For details about the requirements on the Linux environment, see [Quick Start](../quick-start/quickstart-overview.md).

### Getting Started with Development

The following uses [DAYU200](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568) as an example to illustrate uevent customization.

1. Modify the `battery_config.json` file in the battery service configuration folder of the [HDI layer](https://gitee.com/openharmony/drivers_peripheral/tree/master/battery/interfaces/hdi_service/profile) and the [service layer](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile). The uevent configuration is as follows:

    ```json
    {
        "uevent": {
            "SUBSYSTEM=hw_power": {
                "BATTERY_UNDER_VOLTAGE=1": "shutdown",
                "BATTERY_UNDER_CURRENT=2": "reboot",
                "BATTERY_UNDER_VOLTAGE=3": "sendcommonevent"
            }
        }
    }
    ``` 

    **Table 1** Subsystem configuration

    | **Subsystem**| Description|
    | -------- | -------- |
    | SUBSYSTEM=hw_power | Subsystem: **hw_power**|

    **Table 2** uevent description

    | uevent| Description|
    | -------- | -------- |
    | BATTERY_UNDER_VOLTAGE=1 | uevent (regular expression supported) indicating that the battery voltage is less than 1.|
    | BATTERY_UNDER_CURRENT=2 | uevent (regular expression supported) indicating that the battery voltage is less than 2.|
    | BATTERY_UNDER_VOLTAGE=3 | uevent (regular expression supported) indicating that the battery voltage is less than 3.|

    **Table 3** Action description

    | Action| Type| Description|
    | -------- | -------- | -------- |
    | shutdown | string | Shut down the system.|
    | reboot | string | Restart the system.|
    | sendcommonevent | string | Send broadcast.|

2. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. Burn the customized version to the DAYU200 development board.

### Debugging and Verification

1. Change the uevent receiving code (https://gitee.com/openharmony/drivers_peripheral/blob/master/battery/interfaces/hdi_service/src/battery_thread.cpp) to forcibly receive the uevent event BATTERY_UNDER_VOLTAGE=1 in the configuration file.
   ```c++
    void BatteryThread::UeventCallback(void* service)
    {
        char msg[UEVENT_MSG_LEN + UEVENT_RESERVED_SIZE] = { 0 };

        ssize_t len = recv(ueventFd_, msg, UEVENT_MSG_LEN, 0);
        if (len < 0 || len >= UEVENT_MSG_LEN) {
            BATTERY_HILOGI(COMP_HDI, "recv return msg is invalid, len: %{public}zd", len);
            return;
        }

        // msg separator
        msg[len] = '\0';
        msg[len + 1] = '\0';

        std::string powerUevent;
        if (!MatchPowerUevent(msg, powerUevent)) {
            return;
        }
        powerUevent = "BATTERY_UNDER_VOLTAGE=1";
        BATTERY_HILOGI(FEATURE_BATT_INFO, "PowerUevent msg:%{public}s",
        powerUevent.c_str());
        UpdateBatteryInfo(service, powerUevent);
    }
    ```
2. Build the customized version by referring to [Quick Start](../quick-start/quickstart-overview.md).

    ```shell
    ./build.sh --product-name rk3568 --ccache
    ```

3. Burn the customized version to the DAYU200 development board.
4. Check whether the device is powered off when it receives a uevent indicating that the battery voltage is less than 1.
    
## Reference
During development, you can refer to the [default uevent configuration](https://gitee.com/openharmony/powermgr_battery_manager/tree/master/services/native/profile/), as shown below:

The default configuration is as follows:

```json
{
    "uevent": {
        "SUBSYSTEM=hw_power": {
            "BATTERY_UNDER_VOLTAGE=1": "shutdown",
            "BATTERY_UNDER_VOLTAGE=2": "reboot",
            "BATTERY_UNDER_VOLTAGE=3": "sendcommonevent"
        }
    }
}
``` 

Packing path: /system/etc/battery

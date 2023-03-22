# Power Subsystem Changelog

## cl.powermgr.1 CommonEventBatteryChangedCode API Change

Changed the **CommonEventBatteryChangedCode** enum class in [@ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) as follows:

- Changed the class name to **CommonEventBatteryChangedKey**.
- Deleted **EXTRA_MAX_CURRENT**, **EXTRA_MAX_VOLTAGE**, and **EXTRA_CHARGE_COUNTER**.
- Changed the enum value type from numeric to string.

#### Change Impact

The JS API needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

#### Key API/Component Changes

Before change:

| Name                | Value  | Description                                              |
| -------------------- | ---- | -------------------------------------------------- |
| EXTRA_SOC            | 0    | Remaining battery level in percentage.                  |
| EXTRA_VOLTAGE        | 1    | Battery voltage of the device.                    |
| EXTRA_TEMPERATURE    | 2    | Battery temperature of the device.                    |
| EXTRA_HEALTH_STATE   | 3    | Battery health status of the device.                |
| EXTRA_PLUGGED_TYPE   | 4    | Type of the charger connected to the device.            |
| EXTRA_MAX_CURRENT    | 5    | Maximum battery current of the device.                |
| EXTRA_MAX_VOLTAGE    | 6    | Maximum battery voltage of the device.                |
| EXTRA_CHARGE_STATE   | 7    | Battery charging status of the device.                |
| EXTRA_CHARGE_COUNTER | 8    | Number of battery charging times of the device.                |
| EXTRA_PRESENT        | 9    | Whether the battery is supported by the device or installed.|
| EXTRA_TECHNOLOGY     | 10   | Battery technology of the device.                |
| EXTRA_CAPACITY_LEVEL | 11   | Battery level of the device.                |

After change:

| Name                | Value             | Description                                              |
| -------------------- | --------------- | -------------------------------------------------- |
| EXTRA_SOC            | "soc"           | Remaining battery level in percentage.                  |
| EXTRA_CHARGE_STATE   | "chargeState"   | Battery charging status of the device.                |
| EXTRA_HEALTH_STATE   | "healthState"   | Battery health status of the device.                |
| EXTRA_PLUGGED_TYPE   | "pluggedType"   | Type of the charger connected to the device.            |
| EXTRA_VOLTAGE        | "voltage"       | Battery voltage of the device.                    |
| EXTRA_TECHNOLOGY     | "technology"    | Battery technology of the device.                |
| EXTRA_TEMPERATURE    | "temperature"   | Battery temperature of the device.                    |
| EXTRA_PRESENT        | "present"       | Whether the battery is supported by the device or installed.|
| EXTRA_CAPACITY_LEVEL | "capacityLevel" | Battery level of the device.                |

#### Adaptation Guide

For details, see the API reference of the [@ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) API.
## cl.powermgr.2 estimatedRemainingChargeTime API Change

Changed the **estimatedRemainingChargeTime** API in [@ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) to a system API.

#### Change Impact

The JS API needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

#### Adaptation Guide

For details, see the API reference of the [@ohos.batteryInfo](../../../application-dev/reference/apis/js-apis-battery-info.md) API.

## cl.powermgr.3 System Common Event Behavior Change

The following common events are provided in the battery information through [@ohos.commonEventManager (common event module)](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-commonEventManager.md):

- COMMON_EVENT_BATTERY_LOW: common event for low battery level. It includes the remaining battery in percentage.
- COMMON_EVENT_BATTERY_OKAY: common event for normal battery level. It includes the remaining battery in percentage.
- COMMON_EVENT_POWER_CONNECTED: common event for connection to an external power supply. It includes the type of the power supply to which the device is connected.
- COMMON_EVENT_POWER_DISCONNECTED: common event for disconnection from an external power supply. It includes the type of the power supply from which the device is disconnected.
- COMMON_EVENT_CHARGING: common event for starting of battery charging. It includes the battery charging status.
- COMMON_EVENT_DISCHARGING: common event for ending of battery charging. It includes the battery charging status.

Changed the method of obtaining data from common events from **CommonEventData.data** to **CommonEventData.code**.

#### Change Impact

The application developed based on earlier versions needs to adapt the method for obtaining common events in the battery information. Otherwise, the original service logic will be affected.

#### Adaptation Guide

For details, see the API reference of the [@ohos.commonEventManager (Common Event Manager)](../../../application-dev/reference/apis/js-apis-commonEventManager.md) API.

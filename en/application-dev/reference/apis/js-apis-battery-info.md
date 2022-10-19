# Battery Info

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Battery Info module provides APIs for querying the charger type, battery health status, and battery charging status.


## Modules to Import

```js
import batteryInfo from '@ohos.batteryInfo';
```

## System Capabilities

SystemCapability.PowerManager.BatteryManager

## Attributes

Describes battery information.

| Name                          | Type                                      | Readable | Writable | Description                                                  |
| ----------------------------- | ----------------------------------------- | -------- | -------- | ------------------------------------------------------------ |
| batterySOC                    | number                                    | Yes      | No       | Battery state of charge (SoC) of the current device, in unit of percentage. |
| chargingStatus                | [BatteryChargeState](#batterychargestate) | Yes      | No       | Battery charging state of the current device.                |
| healthStatus                  | [BatteryHealthState](#batteryhealthstate) | Yes      | No       | Battery health state of the current device.                  |
| pluggedType                   | [BatteryPluggedType](#batterypluggedtype) | Yes      | No       | Charger type of the current device.                          |
| voltage                       | number                                    | Yes      | No       | Battery voltage of the current device, in unit of microvolt. |
| technology                    | string                                    | Yes      | No       | Battery technology of the current device.                    |
| batteryTemperature            | number                                    | Yes      | No       | Battery temperature of the current device, in unit of 0.1°C. |
| isBatteryPresent<sup>7+</sup> | boolean                                   | Yes      | No       | Whether the battery is supported or present.                 |

**Example**

```js
import batteryInfo from '@ohos.batteryInfo';
var batterySoc = batteryInfo.batterySOC;
```


## BatteryPluggedType

Enumerates charger types.

| Name     | Default Value | Description       |
| -------- | ------------- | ----------------- |
| NONE     | 0             | Unknown type.     |
| AC       | 1             | AC charger.       |
| USB      | 2             | USB charger.      |
| WIRELESS | 3             | Wireless charger. |


## BatteryChargeState

Enumerates charging states.

| Name    | Default Value | Description                       |
| ------- | ------------- | --------------------------------- |
| NONE    | 0             | Unknown state.                    |
| ENABLE  | 1             | The battery is being charged.     |
| DISABLE | 2             | The battery is not being charged. |
| FULL    | 3             | The battery is fully charged.     |


## BatteryHealthState

Enumerates battery health states.

| Name        | Default Value | Description                          |
| ----------- | ------------- | ------------------------------------ |
| UNKNOWN     | 0             | Unknown state.                       |
| GOOD        | 1             | The battery is in the healthy state. |
| OVERHEAT    | 2             | The battery is overheated.           |
| OVERVOLTAGE | 3             | The battery voltage is over high.    |
| COLD        | 4             | The battery temperature is low.      |
| DEAD        | 5             | The battery is dead.                 |


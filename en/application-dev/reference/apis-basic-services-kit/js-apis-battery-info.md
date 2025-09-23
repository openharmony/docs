# @ohos.batteryInfo (Battery Information)

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

The **batteryInfo** module provides APIs for querying the charger type, battery health status, and battery charging status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import {batteryInfo} from '@kit.BasicServicesKit';
```

## batteryInfo

Describes battery information.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name     | Type       | Read-Only| Optional|  Description    |
| --------------- | ------------------- | ---- | ---- | ---------------------|
| batterySOC                                | number                                         | Yes  | No  | Battery state of charge (SoC) of the device, in unit of percentage.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                          |
| chargingStatus                            | [BatteryChargeState](#batterychargestate)      | Yes  | No  | Battery charging state of the current device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                              |
| healthStatus                              | [BatteryHealthState](#batteryhealthstate)      | Yes  | No  | Battery health status of the device.                              |
| pluggedType                               | [BatteryPluggedType](#batterypluggedtype)      | Yes  | No  | Charger type of the device.                            |
| voltage                                   | number                                         | Yes  | No  | Battery voltage of the device, in unit of microvolt.                        |
| technology                                | string                                         | Yes  | No  | Battery technology of the device.                              |
| batteryTemperature                        | number                                         | Yes  | No  | Battery temperature of the device, in unit of 0.1°C.                   |
| isBatteryPresent<sup>7+</sup>             | boolean                                        | Yes  | No  | Whether the battery is supported or present. The value **true** means that the battery is supported or present; **false** means the opposite.<br>Default value: **false**.                |
| batteryCapacityLevel<sup>9+</sup> | [BatteryCapacityLevel](#batterycapacitylevel9) | Yes       | No       | Battery level of the device. |
| nowCurrent<sup>12+</sup> | number                                         | Yes       | No       | Battery current of the device, in unit of mA. |
**Example**

  ```ts
  import {batteryInfo} from '@kit.BasicServicesKit';

  let batterySOCInfo: number = batteryInfo.batterySOC;
  console.info("The batterySOCInfo is: " + batterySOCInfo);

  let chargingStatusInfo = batteryInfo.chargingStatus;
  console.info("The chargingStatusInfo is: " + chargingStatusInfo);

  let healthStatusInfo = batteryInfo.healthStatus;
  console.info("The healthStatusInfo is: " + healthStatusInfo);

  let pluggedTypeInfo = batteryInfo.pluggedType;
  console.info("The pluggedTypeInfo is: " + pluggedTypeInfo);

  let voltageInfo: number = batteryInfo.voltage;
  console.info("The voltageInfo is: " + voltageInfo);

  let technologyInfo: string = batteryInfo.technology;
  console.info("The technologyInfo is: " + technologyInfo);

  let batteryTemperatureInfo: number = batteryInfo.batteryTemperature;
  console.info("The batteryTemperatureInfo is: " + batteryTemperatureInfo);

  let isBatteryPresentInfo: boolean = batteryInfo.isBatteryPresent;
  console.info("The isBatteryPresentInfo is: " + isBatteryPresentInfo);

  let batteryCapacityLevelInfo = batteryInfo.batteryCapacityLevel;
  console.info("The batteryCapacityLevelInfo is: " + batteryCapacityLevelInfo);

  let nowCurrentInfo: number = batteryInfo.nowCurrent;
  console.info("The nowCurrentInfo is: " + nowCurrentInfo);
  ```

## BatteryPluggedType

Enumerates charger types.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name      | Value | Description             |
| -------- | ---- | ----------------- |
| NONE     | 0    | Unknown charger type.     |
| AC       | 1    | AC charger.|
| USB      | 2    | USB charger.  |
| WIRELESS | 3    | Wireless charger.|

## BatteryChargeState

Enumerates charging states.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name     | Value | Description           |
| ------- | ---- | --------------- |
| NONE    | 0    | Unknown state.    |
| ENABLE  | 1    | The battery is being charged. |
| DISABLE | 2    | The battery is not being charged. |
| FULL    | 3    | The battery is fully charged.|

## BatteryHealthState

Enumerates battery health states.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name         | Value | Description          |
| ----------- | ---- | -------------- |
| UNKNOWN     | 0    | Unknown state.   |
| GOOD        | 1    | The battery is in the healthy state.  |
| OVERHEAT    | 2    | The battery is overheated.  |
| OVERVOLTAGE | 3    | The battery voltage is over high.  |
| COLD        | 4    | The battery temperature is low.  |
| DEAD        | 5    | The battery is dead.|

## BatteryCapacityLevel<sup>9+</sup>

Enumerates battery levels.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name          | Value| Description                      |
| -------------- | ------ | ---------------------------- |
| LEVEL_FULL     | 1      | Full battery level.  |
| LEVEL_HIGH     | 2      | High battery level.  |
| LEVEL_NORMAL   | 3      | Normal battery level.|
| LEVEL_LOW      | 4      | Low battery level.  |
| LEVEL_WARNING  | 5      | Alarm battery level.|
| LEVEL_CRITICAL | 6      | Ultra-low battery level.|
| LEVEL_SHUTDOWN | 7      | Power-down battery level.|

## CommonEventBatteryChangedKey<sup>9+</sup>

Enumerates keys for querying the additional information about the **COMMON_EVENT_BATTERY_CHANGED** event.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name                | Value| Description                                            |
| -------------------- | ------ | -------------------------------------------------- |
| EXTRA_SOC            | "soc" | Remaining battery level in percentage.                  |
| EXTRA_CHARGE_STATE   | "chargeState" | Battery charging status of the device.                |
| EXTRA_HEALTH_STATE   | "healthState" | Battery health status of the device.                |
| EXTRA_PLUGGED_TYPE   | "pluggedType" | Type of the charger connected to the device.            |
| EXTRA_VOLTAGE        | "voltage" | Battery voltage of the device.                    |
| EXTRA_TECHNOLOGY     | "technology" | Battery technology of the device.                |
| EXTRA_TEMPERATURE    | "temperature" | Battery temperature of the device.                    |
| EXTRA_PRESENT        | "present" | Whether the battery is supported by the device or installed.|
| EXTRA_CAPACITY_LEVEL | "capacityLevel" | Battery level of the device.                |

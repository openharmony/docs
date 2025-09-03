# @ohos.batteryStatistics (Battery Statistics) (System API)

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

The **batteryStatistics** module provides APIs for querying software and hardware power consumption statistics.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import {batteryStats} from '@kit.BasicServicesKit';
```

## batteryStats.getBatteryStats

getBatteryStats(): Promise<Array&lt;BatteryStatsInfo&gt;>

Obtains the power consumption information list. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

**Return value**

| Type                                                 | Description                           |
| ----------------------------------------------------- | ------------------------------- |
| Promise<Array<[BatteryStatsInfo](#batterystatsinfo)>> | Promise used to return the power consumption information list.|

**Error codes**

For details about the error codes, see [Power Consumption Statistics Error Codes](errorcode-batteryStatistics.md) and [Universal Error Codes](../errorcode-universal.md).

| Code  | Error Message   |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example**

```js
batteryStats.getBatteryStats()
.then((data: batteryStats.BatteryStatsInfo[]) => {
    console.info('battery statistics info: ' + data);
})
.catch((err: Error) => {
    console.error('get battery statistics failed, err: ' + err);
});
```

## batteryStats.getBatteryStats

getBatteryStats(callback: AsyncCallback<Array&lt;BatteryStatsInfo&gt;>): void

Obtains the power consumption information list. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<Array<[BatteryStatsInfo](#batterystatsinfo)>> | Yes  | Callback used to return the result. If the operation is successful, **err** is undefined and **data** is the obtained Array<[BatteryStatsInfo](#batterystatsinfo)>. Otherwise, **err** is an error object. **AsyncCallback** has encapsulated an API of the **BatteryStatsInfo** class.|

**Error codes**

For details about the error codes, see [Power Consumption Statistics Error Codes](errorcode-batteryStatistics.md) and [Universal Error Codes](../errorcode-universal.md).

| Code  | Error Message   |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example**

```js
batteryStats.getBatteryStats((err: Error, data : batteryStats.BatteryStatsInfo[]) => {
    if (typeof err === 'undefined') {
        console.info('battery statistics info: ' + data);
    } else {
        console.error('get battery statistics failed, err: ' + err);
    }
});
```

## batteryStats.getAppPowerValue

getAppPowerValue(uid: number): number

Obtains the power consumption of an application.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| uid    | number | Yes  | Application UID.|

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| number | Power consumption of the application with this UID, in unit of mAh.|

**Error codes**

For details about the error codes, see [Power Consumption Statistics Error Codes](errorcode-batteryStatistics.md) and [Universal Error Codes](../errorcode-universal.md).

| Code  | Error Message   |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |

**Example**

```js
try {
    let value = batteryStats.getAppPowerValue(10021);
    console.info('battery statistics value of app is: ' + value);
} catch(err) {
    console.error('get battery statistics value of app failed, err: ' + err);
}
```

## batteryStats.getAppPowerPercent

getAppPowerPercent(uid: number): number

Obtains the proportion of the power consumption of an application.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

**Parameters**

| Name| Type  | Mandatory| Description       |
| ------ | ------ | ---- | ----------- |
| uid    | number | Yes  | Application UID.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Proportion of the power consumption of an application with this UID.|

**Error codes**

For details about the error codes, see [Power Consumption Statistics Error Codes](errorcode-batteryStatistics.md) and [Universal Error Codes](../errorcode-universal.md).

| Code  | Error Message   |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |

**Example**

```js
try {
    let percent = batteryStats.getAppPowerPercent(10021);
    console.info('battery statistics percent of app is: ' + percent);
} catch(err) {
    console.error('get battery statistics percent of app failed, err: ' + err);
}
```

## batteryStats.getHardwareUnitPowerValue

getHardwareUnitPowerValue(type: ConsumptionType): number

Obtains the power consumption of a hardware unit according to the consumption type.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| type   | [ConsumptionType](#consumptiontype) | Yes  | Power consumption type. The value must be an enum.|

**Return value**

| Type  | Description                                      |
| ------ | ------------------------------------------ |
| number | Power consumption of the hardware unit corresponding to the power consumption type, in unit of mAh.|

**Error codes**

For details about the error codes, see [Power Consumption Statistics Error Codes](errorcode-batteryStatistics.md) and [Universal Error Codes](../errorcode-universal.md).

| Code  | Error Message   |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example**

```js
try {
    let value = batteryStats.getHardwareUnitPowerValue(batteryStats.ConsumptionType.CONSUMPTION_TYPE_SCREEN);
    console.info('battery statistics value of hardware is: ' + value);
} catch(err) {
    console.error('get battery statistics percent of hardware failed, err: ' + err);
}
```

## batteryStats.getHardwareUnitPowerPercent

getHardwareUnitPowerPercent(type: ConsumptionType): number

Obtains the proportion of the power consumption of a hardware unit according to the power consumption type.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

**Parameters**

| Name| Type                               | Mandatory| Description          |
| ------ | ----------------------------------- | ---- | -------------- |
| type   | [ConsumptionType](#consumptiontype) | Yes  | Power consumption type. The value must be an enum.|

**Return value**

| Type  | Description                              |
| ------ | ---------------------------------- |
| number | Proportion of the power consumption of the hardware unit corresponding to the power consumption type.|

**Error codes**

For details about the error codes, see [Power Consumption Statistics Error Codes](errorcode-batteryStatistics.md) and [Universal Error Codes](../errorcode-universal.md).

| Code  | Error Message   |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 202     | Permission verification failed. A non-system application calls a system API. |

**Example**

```js
try {
    let percent = batteryStats.getHardwareUnitPowerPercent(batteryStats.ConsumptionType.CONSUMPTION_TYPE_SCREEN);
    console.info('battery statistics percent of hardware is: ' + percent);
} catch(err) {
    console.error('get battery statistics percent of hardware failed, err: ' + err);
}
```

## BatteryStatsInfo

Describes the device power consumption information.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

### Attributes

| Name | Type                               | Read-Only| Optional| Description                  |
| ----- | ----------------------------------- | ---- | ---- | ---------------------- |
| uid   | number                              | Yes  | No  | UID related to power consumption information.   |
| type  | [ConsumptionType](#consumptiontype) | Yes  | No  | Power consumption type.  |
| power | number                              | Yes  | No  | Power consumption, in unit of mAh.|

## ConsumptionType

Enumerates power consumption types.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryStatistics

| Name                      | Value  | Description                         |
| -------------------------- | ---- | ----------------------------- |
| CONSUMPTION_TYPE_INVALID   | -17  | Unknown type.       |
| CONSUMPTION_TYPE_APP       | -16  | Power consumption of an application.     |
| CONSUMPTION_TYPE_BLUETOOTH | -15  | Power consumption of Bluetooth.     |
| CONSUMPTION_TYPE_IDLE      | -14  | Power consumption when the CPU is idle.|
| CONSUMPTION_TYPE_PHONE     | -13  | Power consumption of a phone call. |
| CONSUMPTION_TYPE_RADIO     | -12  | Power consumption of wireless communication. |
| CONSUMPTION_TYPE_SCREEN    | -11  | Power consumption of the screen.     |
| CONSUMPTION_TYPE_USER      | -10  | Power consumption of the user.     |
| CONSUMPTION_TYPE_WIFI      | -9   | Power consumption of Wi-Fi.   |

# @ohos.power (Power Management)

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

The **power** module provides APIs for rebooting and shutting down the system, as well as querying the screen status. You can use these APIs to obtain the device activity status, power mode, and screen on/off status.
> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import {power} from '@kit.BasicServicesKit';
```

## power.isActive<sup>9+</sup>

isActive(): boolean

Checks whether the current device is active.
- A device with a screen is active when the screen is on and inactive when the screen is off.
- A device without a screen is active when it exits the sleep mode and inactive when it enters the sleep mode.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Returns**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| boolean | Returns **true** if the device is active; returns **false** otherwise.|

**Example**

```js
let isActive = power.isActive();
console.info('power is active: ' + isActive);
```

## power.rebootDevice<sup>(deprecated)</sup>

rebootDevice(reason: string): void

> **NOTE**<br>This API is supported since API version 7 and is deprecated since API version 9. The substitute API is available only for system applications.

Reboots a device.

**Required permissions**: ohos.permission.REBOOT (available only for system applications)

**System capability**: SystemCapability.PowerManager.PowerManager.Core


**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| reason | string | Yes   | Reason for system reboot.|

**Example**

```js
power.rebootDevice('reboot_test');
```

## power.getPowerMode<sup>9+</sup>

getPowerMode(): DevicePowerMode

Obtains the power mode of this device.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Returns**

| Type                                | Description      |
| ------------------------------------ | ---------- |
| [DevicePowerMode](#devicepowermode9) | Power mode.|

**Example**

```js
let mode = power.getPowerMode();
console.info('power mode: ' + mode);
```

## power.isStandby<sup>10+</sup>

isStandby(): boolean

Checks whether the device is in standby mode.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Returns**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| boolean | The value **true** indicates that the device is in standby mode, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |

**Example**

```js
try {
    let isStandby = power.isStandby();
    console.info('device is in standby: ' + isStandby);
} catch(err) {
    console.error('check isStandby failed, err: ' + err);
}
```

## power.isScreenOn<sup>(deprecated)</sup>

isScreenOn(callback: AsyncCallback&lt;boolean&gt;): void

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [power.isActive](#powerisactive9) instead.

Checks the screen status of the current device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the screen status obtained, where the value **true** indicates on and the value **false** indicates off. Otherwise, **err** is an error object.|

**Example**

```js
power.isScreenOn((err: Error, data: boolean) => {
    if (typeof err === 'undefined') {
        console.info('screen on status is ' + data);
    } else {
        console.error('check screen status failed, err: ' + err);
    }
})
```

## power.isScreenOn<sup>(deprecated)</sup>

isScreenOn(): Promise&lt;boolean&gt;

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [power.isActive](#powerisactive9) instead.

Checks the screen status of the current device. This API uses a promise to return the result.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

**Returns**
| Type                  | Description                                              |
| ---------------------- | -------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the screen is on, and the value **false** indicates the opposite.|

**Example**

```js
power.isScreenOn()
.then((data: boolean) => {
    console.info('screen on status is ' + data);
})
.catch((err: Error) => {
    console.error('check screen status failed, err: ' + err);
})
```

## DevicePowerMode<sup>9+</sup>

Enumerates power modes.

**System capability**: SystemCapability.PowerManager.PowerManager.Core

| Name                   | Value  | Description                  |
| ----------------------- | ---- | ---------------------- |
| MODE_NORMAL             | 600  | Standard mode. It is the default value.|
| MODE_POWER_SAVE         | 601  | Power saving mode.        |
| MODE_PERFORMANCE        | 602  | Performance mode.        |
| MODE_EXTREME_POWER_SAVE | 603  | Ultra power saving mode.    |
| MODE_CUSTOM_POWER_SAVE<sup>20+</sup>  | 650  | Custom power saving mode.    |

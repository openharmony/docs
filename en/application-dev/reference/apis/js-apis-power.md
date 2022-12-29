# Power Manager

The Power Manager module provides APIs for rebooting and shutting down the system, as well as querying the screen status.

> **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import power from '@ohos.power';
```

## power.shutdown

shutdown(reason: string): void

Shuts down the system.

**System API**: This is a system API.

**Required permission**: ohos.permission.REBOOT

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| reason | string | Yes   | Reason for system shutdown.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    power.shutdown('shutdown_test');
} catch(err) {
    console.error('shutdown failed, err: ' + err);
}
```

## power.reboot<sup>9+</sup>

reboot(reason: string): void

Reboots the system.

**System API**: This is a system API.

**Required permission**: ohos.permission.REBOOT

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| reason | string | Yes  | Reason for system reboot.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    power.reboot('reboot_test');
} catch(err) {
    console.error('reboot failed, err: ' + err);
}
```

## power.isActive<sup>9+</sup>

isActive(): boolean

Checks whether the current device is active.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    var isActive = power.isActive();
    console.info('power is active: ' + isActive);
} catch(err) {
    console.error('check active status failed, err: ' + err);
}
```

## power.wakeup<sup>9+</sup>

wakeup(detail: string): void

Wakes up a device.

**System API**: This is a system API.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| detail | string | Yes  | Reason for wakeup.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    power.wakeup('wakeup_test');
} catch(err) {
    console.error('wakeup failed, err: ' + err);
}
```

## power.suspend<sup>9+</sup>

suspend(): void

Hibernates a device.

**System API**: This is a system API.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    power.suspend();
} catch(err) {
    console.error('suspend failed, err: ' + err);
}
```

## power.getPowerMode<sup>9+</sup>

getPowerMode(): DevicePowerMode

Obtains the power mode of this device.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Return value**

| Type                                | Description      |
| ------------------------------------ | ---------- |
| [DevicePowerMode](#devicepowermode9) | Power mode.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    var mode = power.getPowerMode();
    console.info('power mode: ' + mode);
} catch(err) {
    console.error('get power mode failed, err: ' + err);
}
```

## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode, callback: AsyncCallback&lt;void&gt;): void

Sets the power mode of this device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.POWER_OPTIMIZATION

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| mode     | [DevicePowerMode](#devicepowermode9) | Yes  | Power mode.                                                  |
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback used to return the result. If the power mode is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE, err => {
    if (typeof err === 'undefined') {
        console.info('set power mode to MODE_PERFORMANCE');
    } else {
        console.error('set power mode failed, err: ' + err);
    }
});
```

## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode): Promise&lt;void&gt;

Sets the power mode of this device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.POWER_OPTIMIZATION

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type                                | Mandatory| Description      |
| ------ | ------------------------------------ | ---- | ---------- |
| mode   | [DevicePowerMode](#devicepowermode9) | Yes  | Power mode.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](../errorcodes/errorcode-power.md).

| Code  | Error Message   |
|---------|---------|
| 4900101 | Operation failed. Cannot connect to service.|

**Example**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE)
.then(() => {
    console.info('set power mode to MODE_PERFORMANCE');
})
.catch(err => {
    console.error('set power mode failed, err: ' + err);
});
```

## power.rebootDevice<sup>(deprecated)</sup>

rebootDevice(reason: string): void

> This API is deprecated since API version 9. You are advised to use [power.reboot](#powerreboot9) instead.

Reboots the system.

**Required permission**: ohos.permission.REBOOT

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| reason | string | Yes   | Reason for system reboot.|

**Example**

```js
power.rebootDevice('reboot_test');
```

## power.isScreenOn<sup>(deprecated)</sup>

isScreenOn(callback: AsyncCallback&lt;boolean&gt;): void

> This API is deprecated since API version 9. You are advised to use [power.isActive](#powerisactive9) instead.

Checks the screen status of the current device. This API uses an asynchronous callback to return the result.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the screen status obtained, where the value **true** indicates on and the value **false** indicates the opposite. Otherwise, **err** is an error object.|

**Example**

```js
power.isScreenOn((err, data) => {
    if (typeof err === 'undefined') {
        console.info('screen on status is ' + data);
    } else {
        console.error('check screen status failed, err: ' + err);
    }
})
```

## power.isScreenOn<sup>(deprecated)</sup>

isScreenOn(): Promise&lt;boolean&gt;

> This API is deprecated since API version 9. You are advised to use [power.isActive](#powerisactive9) instead.

Checks the screen status of the current device. This API uses a promise to return the result.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Return value**
| Type                  | Description                                              |
| ---------------------- | -------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the screen is on, and the value **false** indicates the opposite.|

**Example**

```js
power.isScreenOn()
.then(data => {
    console.info('screen on status is ' + data);
})
.catch(err => {
    console.error('check screen status failed, err: ' + err);
})
```

## DevicePowerMode<sup>9+</sup>

Enumerates power modes.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

| Name                   | Value  | Description                  |
| ----------------------- | ---- | ---------------------- |
| MODE_NORMAL             | 600  | Standard mode. It is the default value.|
| MODE_POWER_SAVE         | 601  | Power saving mode.        |
| MODE_PERFORMANCE        | 602  | Performance mode.        |
| MODE_EXTREME_POWER_SAVE | 603  | Ultra power saving mode.    |

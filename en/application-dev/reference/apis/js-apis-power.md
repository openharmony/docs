# Power Manager

The Power Manager module provides APIs for rebooting and shutting down the system, as well as querying the screen status.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import power from '@ohos.power';
```


## power.shutdownDevice

shutdownDevice(reason: string): void

Shuts down the system.

This is a system API and cannot be called by third-party applications.

**Required permission**: ohos.permission.REBOOT

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| reason | string | Yes   | Reason for system shutdown.|

**Example**

```js
power.shutdownDevice("shutdown_test");
console.info('power_shutdown_device_test success')
```


## power.rebootDevice

rebootDevice(reason: string): void

Reboots the system.

**Required permission**: ohos.permission.REBOOT

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| reason | string | Yes   | Reason for system reboot.|

**Example**

```js
power.rebootDevice("reboot_test");
console.info('power_reboot_device_test success')
```


## power.isScreenOn

isScreenOn(callback: AsyncCallback&lt;boolean&gt;): void

Checks the screen status of the current device.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                                      |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to obtain the return value.<br>Return value: The value **true** indicates that the screen is on, and the value **false** indicates the opposite.|

**Example**

```js
power.isScreenOn((error, screenOn) => {
    if (typeof error === "undefined") {
        console.info('screenOn status is ' + screenOn);
    } else {
        console.log('error: ' + error);
    }
})
```


## power.isScreenOn

isScreenOn(): Promise&lt;boolean&gt;

Checks the screen status of the current device.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Return value**
| Type                    | Description                                     |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to obtain the return value. <br/>Return value: The value **true** indicates that the screen is on, and the value **false** indicates the opposite.|

**Example**

```js
power.isScreenOn()
.then(screenOn => {
    console.info('screenOn status is ' + screenOn);
})
.catch(error => {
    console.log('error: ' + error);
})
```

## power.wakeupDevice<sup>9+</sup>

wakeupDevice(detail: string): void

Wakes up a device.

This is a system API and cannot be called by third-party applications.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| detail | string | Yes  | Reason for wakeup.|

**Example**

```js
power.wakeupDevice("application");
console.info('power_wakeup_device_test success')
```

## power.suspendDevice<sup>9+</sup>

suspendDevice(): void

Hibernates a device.

This is a system API and cannot be called by third-party applications.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Example**

```js
power.suspendDevice();
console.info('power_suspend_device_test success')
```

## power.getPowerMode<sup>9+</sup>

getPowerMode(callback: AsyncCallback&lt;DevicePowerMode&gt;): void

Obtains the power mode of this device.

**Required permission**: ohos.permission.POWER_OPTIMIZATION

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;DevicePowerMode&gt; | Yes  | Callback used to obtain the return value.<br>Return value: [DevicePowerMode](#devicepowermode9)|

**Example**

```js
power.getPowerMode((error, mode) => {
    if (typeof error === "undefined") {
        console.info('power mode is ' + mode);
    } else {
        console.log('error: ' + error);
    }
})
```


## power.getPowerMode<sup>9+</sup>

getPowerMode(): Promise&lt;DevicePowerMode&gt;

Obtains the power mode of this device.

**Required permission**: ohos.permission.POWER_OPTIMIZATION

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Return value**

| Type                          | Description                                                        |
| ------------------------------ | ------------------------------------------------------------ |
| Promise&lt;DevicePowerMode&gt; | Promise used to obtain the return value. <br/>Return value: [DevicePowerMode](#devicepowermode9)|

**Example**

```js
power.getPowerMode()
.then(mode => {
    console.info('power mode is ' + mode);
})
.catch(error => {
    console.log('error: ' + error);
})
```

## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode, callback: AsyncCallback&lt;void&gt;): void

Sets the power mode of this device.

This is a system API and cannot be called by third-party applications.

**Required permission**: ohos.permission.POWER_OPTIMIZATION

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                    |
| -------- | ------------------------------------ | ---- | ------------------------ |
| mode     | [DevicePowerMode](#devicepowermode9) | Yes  | Power mode.              |
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback used to return the result.|

**Example**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE, error => {
    if (typeof error === "undefined") {
        console.info('set power mode to MODE_PERFORMANCE');
    } else {
        console.log('error: ' + error);
    }
})
```


## power.setPowerMode<sup>9+</sup>

setPowerMode(mode: DevicePowerMode): Promise&lt;void&gt;

Sets the power mode of this device.

This is a system API and cannot be called by third-party applications.

**Required permission**: ohos.permission.POWER_OPTIMIZATION

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type                                | Mandatory| Description      |
| ------ | ------------------------------------ | ---- | ---------- |
| mode   | [DevicePowerMode](#devicepowermode9) | Yes  | Power mode.|

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE)
.then(() => {
    console.info('set power mode to MODE_PERFORMANCE');
})
.catch(error => {
    console.log('error: ' + error);
})
```

## DevicePowerMode<sup>9+</sup>

Enumerates power modes.

**System capability:** SystemCapability.PowerManager.PowerManager.Core


| Name                   | Default Value| Description                  |
| ----------------------- | ------ | ---------------------- |
| MODE_NORMAL             | 600    | Standard mode. It is the default value.|
| MODE_POWER_SAVE         | 601    | Power saving mode.        |
| MODE_PERFORMANCE        | 602    | Performance mode.        |
| MODE_EXTREME_POWER_SAVE | 603    | Ultra power saving mode.    |

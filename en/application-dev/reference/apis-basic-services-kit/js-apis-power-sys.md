# @ohos.power (Power Management) (System API)

The **power** module provides APIs for rebooting and shutting down the system, as well as querying the screen status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.power (Power Management)](js-apis-power.md).

## Modules to Import

```js
import {power} from '@kit.BasicServicesKit';
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
| reason | string | Yes   | Shutdown reason. The value must be a string.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |


**Example:**

```js
try {
    power.shutdown('shutdown_test');
} catch(err) {
    console.error('shutdown failed, err: ' + err);
}
```

## power.reboot<sup>9+</sup>

reboot(reason: string): void

The device is restarted.

**System API**: This is a system API.

**Required permission**: ohos.permission.REBOOT

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| reason | string | Yes  | Restart reason. The value must be a string.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example:**

```js
try {
    power.reboot('reboot_test');
} catch(err) {
    console.error('reboot failed, err: ' + err);
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
| detail | string | Yes  | Wakeup reason. The value must be a string.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example:**

```js
try {
    power.wakeup('wakeup_test');
} catch(err) {
    console.error('wakeup failed, err: ' + err);
}
```

## power.suspend<sup>9+</sup>

suspend(isImmediate?: boolean): void

Hibernates a device.

**System API**: This is a system API.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| isImmediate<sup>10+</sup> | boolean |  No | Whether to hibernate a device immediately. If this parameter is not specified, the default value **false** is used. The system automatically determines when to enter the hibernation state.<br>**NOTE**: This parameter is supported since API version 10.|


**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**Example:**

```js
try {
    power.suspend();
} catch(err) {
    console.error('suspend failed, err: ' + err);
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
| mode     | DevicePowerMode | Yes  | Power mode. The value must be an enum.                                                  |
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback invoked to return the result.<br> If the power mode is successfully set, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example:**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE, (err: Error) => {
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
| mode   | DevicePowerMode | Yes  | Power mode. The value must be an enum.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example:**

```js
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE)
.then(() => {
    console.info('set power mode to MODE_PERFORMANCE');
})
.catch((err : Error)=> {
    console.error('set power mode failed, err: ' + err);
});
```

## power.setScreenOffTime<sup>12+</sup>

setScreenOffTime(timeout: number): void

Set the screen-off timeout duration.

**System API**: This is a system API.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| timeout | number | Yes   | Screen-off timeout duration, in milliseconds. A value greater than **0** indicates the specified timeout duration is used, and the value **-1** indicates that the default timeout duration is used. Other values are invalid.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1. Parameter verification failed. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**Example:**

```js
try {
    power.setScreenOffTime(30000);
} catch(err) {
    console.error('set screen off time failed, err: ' + err);
}
```

## power.hibernate<sup>12+</sup>

hibernate(clearMemory: boolean): void

Hibernates a device.

**System API**: This is a system API.

**System capability:** SystemCapability.PowerManager.PowerManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| clearMemory | boolean | Yes   | Whether to clear the memory. The value **true** means to clear the memory before the system enters the hibernation state, and the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Power Manager Error Codes](errorcode-power.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Incorrect parameter types. |

**Example:**

```js
try {
    power.hibernate(true);
} catch(err) {
    console.error('hibernate failed, err: ' + err);
}
```

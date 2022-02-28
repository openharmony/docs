# Power Management

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import power from '@ohos.power';
```

## System Capabilities

SystemCapability.PowerManager.PowerManager


## power.shutdownDevice

shutdownDevice(reason: string): void

Shuts down the system.

Before using this API, you must declare the **ohos.permission.SHUTDOWN** permission.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reason | string | Yes| Reason for system shutdown.|

**Example**

```
power.shutdownDevice("shutdown_test");
console.info('power_shutdown_device_test success')
```


## power.rebootDevice

rebootDevice(reason: string): void

Restarts the device.

Before using this API, you must declare the **ohos.permission.REBOOT** permission (to reboot) or the **ohos.permission.REBOOT_RECOVERY** permission (to reboot and enter the recovery mode)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reason | string | Yes| Reason for system reboot.|

**Example**

```
power.rebootDevice("reboot_test");
console.info('power_reboot_device_test success')
```


## power.isScreenOn

isScreenOn(callback: AsyncCallback&lt;boolean&gt;): void

Checks the screen status of the current device.

**Parameters**

| Type| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to obtain the return value. <br/>The value **true** indicates that the screen is on, and value **false** indicates the opposite.|

**Example**

```
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

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to asynchronously obtain the return value. <br/>The value **true** indicates that the screen is on, and value **false** indicates the opposite.|

**Example**

```
power.isScreenOn()
.then(screenOn => {
    console.info('screenOn status is ' + screenOn);
})
.catch(error => {
    console.log('error: ' + error);
})
```

# Power Manager

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Power Manager module provides APIs for rebooting and shutting down the system, as well as querying the screen status.


## Modules to Import

```
import power from '@ohos.power';
```

## System Capability

SystemCapability.PowerManager.PowerManager.Core


## power.shutdownDevice

shutdownDevice(reason: string): void

Shuts down the system.

This is a system API and cannot be called by third-party applications.

**Required permission**: ohos.permission.REBOOT

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| reason | string | Yes   | Reason for system shutdown.|

**Example**

```
power.shutdownDevice("shutdown_test");
console.info('power_shutdown_device_test success')
```


## power.rebootDevice

rebootDevice(reason: string): void

Reboots the system.

**Required permission**: ohos.permission.REBOOT (to reboot) or ohos.permission.REBOOT_RECOVERY (to reboot and enter the recovery or updater mode)

**Parameters**

| Name   | Type    | Mandatory  | Description   |
| ------ | ------ | ---- | ----- |
| reason | string | Yes   | Reason for system reboot.|

**Example**

```
power.rebootDevice("reboot_test");
console.info('power_reboot_device_test success')
```


## power.isScreenOn

isScreenOn(callback: AsyncCallback&lt;boolean&gt;): void

Checks the screen status of the current device.

**Parameters**

| Name     | Type                          | Mandatory  | Description                                      |
| -------- | ---------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to obtain the return value.<br>Return value: The value **true** indicates that the screen is on, and the value **false** indicates the opposite.|

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
| Type                    | Description                                     |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to obtain the return value. <br/>Return value: The value **true** indicates that the screen is on, and the value **false** indicates the opposite.|

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

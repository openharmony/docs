# Power Manager

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Power Manager module provides APIs for rebooting and shutting down the system, as well as querying the screen status.


## Modules to Import

```
import power from '@ohos.power';
```

## System Capabilities

SystemCapability.PowerManager.PowerManager.Core


## power.shutdownDevice

shutdownDevice(reason: string): void

Shuts down the system.

**Required permission:** ohos.permission.SHUTDOWN

**Note:** This is a system API and it is used only for system applications.

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

Restarts the device.

**Required permission:** ohos.permission.REBOOT (to reboot) or ohos.permission.REBOOT_UPDATER (to reboot and enter the updater mode)

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

| Type      | Type                          | Mandatory  | Description                                      |
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

**Return Value**
| Type                    | Description                                     |
| ---------------------- | --------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to asynchronously obtain the return value. <br/>Return value: The value **true** indicates that the screen is on, and the value **false** indicates the opposite.|

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

# @ohos.bluetooth.hid (Bluetooth hid Module)

The **hid** module provides APIs for using the Bluetooth Human Interface Device Profile (HID).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import hid from '@ohos.bluetooth.hid';
```


## hid.createHidHostProfile<a name="createHidHostProfile"></a>

createHidHostProfile(): HidHostProfile

Creates a **HidHostProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| HidHostProfile | **HidHostProfile** instance created.|

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let hidHostProfile = hid.createHidHostProfile();
    console.info('hidHost success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## HidHostProfile

Before using any API of **HidHostProfile**, you need to create an instance of this class by using **createHidHostProfile()**.


### connect<a name="HidHost-connect"></a>

connect(deviceId: string): void

Connects to the HidHost service of a device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let hidHostProfile = hid.createHidHostProfile();
    hidHostProfile.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect<a name="HidHost-disconnect"></a>

disconnect(deviceId: string): void

Disconnects from the HidHost service of a device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let hidHostProfile = hid.createHidHostProfile();
    hidHostProfile.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

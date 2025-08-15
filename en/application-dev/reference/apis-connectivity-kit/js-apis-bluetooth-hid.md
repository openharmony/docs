# @ohos.bluetooth.hid (Bluetooth HID Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->

The **hid** module provides Bluetooth capabilities based on Bluetooth Classic's Human Interface Device Profile (HID), and supports functions such as obtaining the connection status. All the APIs in this module are also accessible to devices using Bluetooth Low Energy (BLE)'s HID over GATT Profile (HOGP).
> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import { hid } from '@kit.ConnectivityKit';
```


## BaseProfile

type BaseProfile = baseProfile.BaseProfile

**BaseProfile** API definition.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md)| **BaseProfile** API definition.|


## hid.createHidHostProfile

createHidHostProfile(): HidHostProfile

Creates a **HidHostProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| HidHostProfile | **HidHostProfile** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |


**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let hidHostProfile = hid.createHidHostProfile();
    console.info('hidHost success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

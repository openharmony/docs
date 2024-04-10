# @ohos.bluetooth.hid (Bluetooth HID Module)

The **hid** module provides APIs for using the Bluetooth Human Interface Device Profile (HID).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import hid from '@ohos.bluetooth.hid';
```


## hid.createHidHostProfile

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

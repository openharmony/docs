# @ohos.bluetooth.pan (Bluetooth PAN Module)

The **pan** module provides APIs for accessing the Bluetooth personal area network (PAN).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import { pan } from '@kit.ConnectivityKit';
```


## BaseProfile

type BaseProfile = baseProfile.BaseProfile

Defines **BaseProfile** APIs.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md)| **BaseProfile** API definition.|


## pan.createPanProfile

createPanProfile(): PanProfile

Creates a **PanProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| PanProfile | **PanProfile** instance created.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let panProfile : pan.PanProfile= pan.createPanProfile();
    console.info('pan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

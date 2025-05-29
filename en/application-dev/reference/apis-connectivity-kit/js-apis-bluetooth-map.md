# @ohos.bluetooth.map (Bluetooth MAP Module)

The **bluetooth.map** module provides APIs for exchanging messages between devices using the Bluetooth Message Access Profile (MAP).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import { map } from '@kit.ConnectivityKit';
```


## BaseProfile

type BaseProfile = baseProfile.BaseProfile

**BaseProfile** API definition.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#baseprofile) | **BaseProfile** API definition.|


## map.createMapMseProfile

createMapMseProfile(): MapMseProfile

Creates a **MapMseProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| MapMseProfile | **MapMseProfile** instance created.|

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let mapMseProfile = map.createMapMseProfile();
    console.info('MapMse success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

## mapMseProfile

Provides APIs for exchanging messages between devices. Before using any API of **mapMseProfile**, you need to create an instance of this class by using [createMapMseProfile()](#mapcreatemapmseprofile).

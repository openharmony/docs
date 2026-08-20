# @ohos.bluetooth.pan (Bluetooth PAN Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=14ca614ebb030bf413b2d8393352ad7521a1d1b9 translatedAt=2026-08-19T10:01:07.638Z pushedAt=2026-08-20T01:44:27.574Z -->

The pan module implements Bluetooth-based network sharing through Bluetooth Classic's [Personal Area Networking (PAN)](../../connectivity/bluetooth/terminology.md#pan), such as obtaining the network connection status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { pan } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

**BaseProfile** class, which provides public capabilities such as obtaining the connection status and listening for connection status changes.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#baseprofile) | **BaseProfile** API definition.|

## pan.createPanProfile

createPanProfile(): PanProfile

Creates a Bluetooth [PAN](../../connectivity/bluetooth/terminology.md#pan) instance. Through this instance, you can use the local devices as the [NAP](../../connectivity/bluetooth/terminology.md#nap) and [PANU](../../connectivity/bluetooth/terminology.md#panu) and implement functions such as obtaining the PAN service connection status.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| PanProfile | PAN instance. The **PanProfile** class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
try {
    let panProfile : pan.PanProfile= pan.createPanProfile();
    console.info('pan success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## PanProfile

Represents a Bluetooth PAN communication instance.

- Before using any API of **PanProfile**, you need to create an instance of this class by using [createPanProfile](#pancreatepanprofile).

- This class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class.

### isPanSupported

isPanSupported(): boolean

Obtains the tethering status when the local devices is used as the NAP.

**Since:** 26.0.0

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type      | Description                  |
| --------------------- | --------------------------------- |
| boolean | Whether the PAN is supported on the device. The value **true** indicates it is supported, and **false** indicates otherwise. |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID | Error Message |
| -------- | ---------------------------- |
|2900099 | Operation failed.                        |

**Example**

```js
try {
    let panProfile: pan.PanProfile = pan.createPanProfile();
    let isPanSupported: boolean = panProfile.isPanSupported();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### isTetheringOn

isTetheringOn(): boolean

Obtains the tethering status when the local devices is used as the NAP.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type      | Description                  |
| --------------------- | --------------------------------- |
| boolean | Whether tethering is available over a Bluetooth PAN. The value **true** indicates it is available, and **false** indicates otherwise. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported. Only can be called on phone, tablet, and 2in1 devices. Failed to call the API when the short-range chip is not inserted on 2in1 device.          |

**Example**

```js
try {
    let panProfile: pan.PanProfile = pan.createPanProfile();
    let isTetheringOn: boolean = panProfile.isTetheringOn();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```
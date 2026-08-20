# @ohos.bluetooth.hfp (Bluetooth HFP Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=14ca614ebb030bf413b2d8393352ad7521a1d1b9 translatedAt=2026-08-19T10:00:03.242Z pushedAt=2026-08-19T12:17:38.452Z -->

The **hfp** module provides the Bluetooth call audio capability based on the [Hands-Free Profile (HFP)](../../connectivity/bluetooth/terminology.md#hfp), such as obtaining the call audio connection status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { hfp } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

**BaseProfile** class, which provides public capabilities such as obtaining the connection status and listening for connection status changes.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#baseprofile) | **BaseProfile** API definition.|

## hfp.createHfpAgProfile

createHfpAgProfile(): HandsFreeAudioGatewayProfile

Creates an [HFP AG](../../connectivity/bluetooth/terminology.md#hfp-ag) instance. Through this instance, you can use the local device as the HFP AG and implement functions such as obtaining the Bluetooth call audio connection status.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [HandsFreeAudioGatewayProfile](#handsfreeaudiogatewayprofile) | HFP AG instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let hfpAgProfile = hfp.createHfpAgProfile();
    console.info('hfpAg success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## hfp.createHfpHfProfile

createHfpHfProfile(): HandsFreeHfProfile

Creates an [HF](../../connectivity/bluetooth/terminology.md#hf) instance. Through this instance, you can use the local device as the HF and implement functions such as obtaining the Bluetooth call audio connection status.

**Since:** 26.0.0

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                            | Description         |
| ----------------------------- | ---------- |
| [HandsFreeHfProfile](#handsfreehfprofile) | HF instance. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | ---------------------------- |
|801 | Capability not supported.          |

**Example**

```js
try {
    let hfProfile = hfp.createHfpHfProfile();
    console.info('hf success');
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## HandsFreeAudioGatewayProfile

Represents the [HFP AG](../../connectivity/bluetooth/terminology.md#hfp-ag) role in Bluetooth call audio.

- The **HandsFreeAudioGatewayProfile** class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class.

- Before using the APIs of this class, you need to construct an HFP AG instance by calling [createHfpAgProfile](#hfpcreatehfpagprofile).

- The counterpart of the HFP AG role is the [HF](../../connectivity/bluetooth/terminology.md#hf) role.

**System capability**: SystemCapability.Communication.Bluetooth.Core

## HandsFreeHfProfile

Represents the [HF](../../connectivity/bluetooth/terminology.md#hf) role in Bluetooth call audio.

- This class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class.

- Before using the APIs of this class, you need to construct an instance of this class by calling [createHfpHfProfile](#hfpcreatehfphfprofile).

- The counterpart of the HF role is the [HFP AG](../../connectivity/bluetooth/terminology.md#hfp-ag) role.

**Since:** 26.0.0

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.
# Interface (MediaKeySession)

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29f3919446ee01733553b9b39493ee11224dad86 translatedAt=2026-07-31T02:12:32.641Z pushedAt=2026-07-31T03:50:44.367Z -->

MediaKeySession implements media key management. Before calling any API in MediaKeySession, you must use [createMediaKeySession](arkts-apis-drm-MediaKeySystem.md#createmediakeysession) to create a MediaKeySession instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { drm } from '@kit.DrmKit';
```

## generateMediaKeyRequest

generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediaKeyType: number, options?: OptionsData[]): Promise<MediaKeyRequest\>

Generates a media key request. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                                                                                                    |
| -------- | ----------------------------------------------- | ---- |--------------------------------------------------------------------------------------------------------|
| mimeType  | string     | Yes  | MIME type. The supported DRM solution names can be obtained by calling [isMediaKeySystemSupported](arkts-apis-drm-f.md#drmismediakeysystemsupported-1).|
| initData  | Uint8Array     | Yes  | Initial data, that is, the actual PSSH data in the PSSH box of the encrypted stream. You can obtain the DRM information by listening for **mediaKeySystemInfoUpdate** events of the AVPlayer (via [on('mediaKeySystemInfoUpdate')](../apis-media-kit/arkts-apis-media-AVPlayer.md#onmediakeysysteminfoupdate11)), and then extract the **pssh** field to generate **initData**. For details about the development process, see [DRM Playback with AVPlayer (ArkTS)](../../media/drm/drm-avplayer-arkts-integration.md).                                                                                                    |
| mediaKeyType| number     | Yes  | Type of the media key. The value range is [0, 1]. The value **0** means an online media key, and **1** means an offline media key.<br>If a value beyond the specified range is passed, parameter verification will fail and error code 401 will be reported.                                                                                   |
| options  | [OptionsData[]](arkts-apis-drm-i.md#optionsdata)     | No  | Optional data. The default value is an empty array.                                                                                                 |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<[MediaKeyRequest](arkts-apis-drm-i.md#mediakeyrequest)\>          | Promise used to return the media key request generated.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                | The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// Protection System Specific Header (PSSH) data is embedded in the encrypted stream. For MP4 files, it is located in the pssh box. In DASH streams, it is located in the MPD and MP4 pssh box. For HLS + TS streams, it is located in the m3u8 file and each TS segment. Pass in the actual value as required.
let uint8pssh = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateMediaKeyRequest('video/avc', uint8pssh, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE).then((mediaKeyRequest: drm.MediaKeyRequest) =>{
  console.info('generateMediaKeyRequest' + mediaKeyRequest);
});
```

## processMediaKeyResponse

processMediaKeyResponse(response: Uint8Array): Promise<Uint8Array\>

Processes a media key response. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | Yes  | Media key response.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<Uint8Array\>          | Promise used to return an array of media key IDs.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyResponse is obtained from the DRM service. Pass in the actual value as required.
let mediaKeyResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(mediaKeyResponse).then((mediaKeyId: Uint8Array) => {
  console.info('processMediaKeyResponse:' + mediaKeyId);
});
```

## checkMediaKeyStatus

 checkMediaKeyStatus(): MediaKeyStatus[]

Checks the status of the media keys in use.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeyStatus[]](arkts-apis-drm-i.md#mediakeystatus)          | Media key status.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
let keyStatus: drm.MediaKeyStatus[] =  mediaKeySession.checkMediaKeyStatus();
```

## clearMediaKeys

clearMediaKeys(): void

Clears the media keys in use.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyResponse is obtained from the DRM service. Pass in the actual value as required.
let mediaKeyResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(mediaKeyResponse).then((mediaKeyId: Uint8Array) => {
  console.info('processMediaKeyResponse:' + mediaKeyId);
});
mediaKeySession.clearMediaKeys();
```

## generateOfflineReleaseRequest

generateOfflineReleaseRequest(mediaKeyId: Uint8Array): Promise<Uint8Array\>

Generates a request to release offline media keys. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array    | Yes  | Array of offline media key IDs.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<Uint8Array\>          | Promise used to return the request generated if the DRM solution on the device supports the release of offline media keys.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual value as required.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateOfflineReleaseRequest(mediaKeyId).then((offlineReleaseRequest: Uint8Array) => {
  console.info('generateOfflineReleaseRequest:' + offlineReleaseRequest);
});
```

## processOfflineReleaseResponse

processOfflineReleaseResponse(mediaKeyId: Uint8Array, response: Uint8Array): Promise<void\>

Processes a response to a request for releasing offline media keys. This API uses a promise to return the result.

If the DRM solution on the device does not support the release of offline media keys, error code 24700101 will be reported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | Array of offline media key IDs.                  |
| response  | Uint8Array     | Yes  | Response to the request for releasing offline media keys.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<void\>          | Promise that returns no value.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Apply for memory based on the actual length.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateOfflineReleaseRequest(mediaKeyId).then((offlineReleaseRequest: Uint8Array) => {
  console.info('generateOfflineReleaseRequest:' + offlineReleaseRequest);
});
// offlineReleaseResponse is obtained from the DRM service. Apply for memory based on the actual length.
let offlineReleaseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processOfflineReleaseResponse(mediaKeyId, offlineReleaseResponse).then(() => {
  console.info('processOfflineReleaseResponse');
});
```

## restoreOfflineMediaKeys

restoreOfflineMediaKeys(mediaKeyId: Uint8Array): Promise<void\>

Restores offline media keys. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | Array of offline media key IDs.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<void\>          | Promise that returns no value.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual value as required.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.restoreOfflineMediaKeys(mediaKeyId).then(() => {
  console.info("restoreOfflineMediaKeys");
});
```

## getContentProtectionLevel

getContentProtectionLevel(): ContentProtectionLevel

Obtains the content protection level of this media key session.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ContentProtectionLevel](arkts-apis-drm-e.md#contentprotectionlevel)          | Content protection level.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeySession.getContentProtectionLevel();
console.info(`contentProtectionLevel: ${contentProtectionLevel}`);
```

## requireSecureDecoderModule

requireSecureDecoderModule(mimeType: string): boolean

Checks whether secure decoding is required.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                                                                                                    |
| -------- | ----------------------------------------------- | ---- |--------------------------------------------------------------------------------------------------------|
| mimeType  | string     | Yes  | MIME type. The supported MIME types depend on the DRM solution and can be obtained by calling [isMediaKeySystemSupported](arkts-apis-drm-f.md#drmismediakeysystemsupported-1).|

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Check result for whether secure decoding is required. **true** if required, **false** otherwise.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
let status: boolean = mediaKeySession.requireSecureDecoderModule('video/avc');
```

## on('keyRequired')

on(type: 'keyRequired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the application requests a media key. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyRequired'**, which is triggered when the application requires a media key.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('keyRequired', (eventInfo: drm.EventInfo) => {
  console.info('keyRequired ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

## off('keyRequired')

off(type: 'keyRequired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the application requests a media key. This API uses an asynchronous callback to return the result.

This API is used to unregister listeners registered via **on('keyRequired')**, which are used to listen for events triggered when the media key is required during DRM program playback.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyRequired'**.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | No  | Callback used to return the event information. This parameter is optional. If it is not passed, all listeners for the event type are unregistered.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('keyRequired');
```

## on('keyExpired')

on(type: 'keyExpired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that a media key expires. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyExpired'**, which is triggered when a media key expires.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('keyExpired', (eventInfo: drm.EventInfo) => {
  console.info('keyExpired ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

## off('keyExpired')

off(type: 'keyExpired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that a media key expires. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyExpired'**.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | No  | Callback used to return the event information. This parameter is optional. If it is not passed, all listeners for the event type are unregistered.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('keyExpired');
```

## on('vendorDefined')

on(type: 'vendorDefined', callback: (eventInfo: EventInfo) => void): void

Subscribes to vendor-defined events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'vendorDefined'**, which is triggered when a vendor-defined event occurs.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('vendorDefined', (eventInfo: drm.EventInfo) => {
  console.info('vendorDefined ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

## off('vendorDefined')

off(type: 'vendorDefined', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from vendor-defined events. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'vendorDefined'**.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | No  | Callback used to return the event information. This parameter is optional. If it is not passed, all listeners for the event type are unregistered.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('vendorDefined');
```

## on('expirationUpdate')

on(type: 'expirationUpdate', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that a media key is updated upon expiry. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'expirationUpdate'**, which is triggered when a media key is updated upon expiry.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
  console.info('expirationUpdate ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

## off('expirationUpdate')

off(type: 'expirationUpdate', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that a media key is updated upon expiry. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'expirationUpdate'**.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | No  | Callback used to return the event information. This parameter is optional. If it is not passed, all listeners for the event type are unregistered.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.       |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('expirationUpdate');
```

## on('keysChange')

on(type: 'keysChange', callback: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

Subscribes to events indicating that a media key changes. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keysChange'**, which is triggered when a media key changes.|
| callback | (keyInfo: [KeysInfo[]](arkts-apis-drm-i.md#keysinfo), newKeyAvailable: boolean) => void | Yes  | Callback used to return the event information, including a list of key IDs, descriptions of their statuses, and whether each key is available.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('keysChange', (keyInfo: drm.KeysInfo[], newKeyAvailable: boolean) => {
  for (let i = 0; i < keyInfo.length; i++) {
    console.info('keysChange' + 'keyId:' + keyInfo[i].keyId + ' data:' + keyInfo[i].value);
  }
});
```

## off('keysChange')

off(type: 'keysChange', callback?: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

Unsubscribes from events indicating that a media key changes. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keysChange'**.|
| callback | (keyInfo: [KeysInfo[]](arkts-apis-drm-i.md#keysinfo), newKeyAvailable: boolean) => void | No  | Callback used to return the event information, including a list of key IDs, descriptions of their statuses, and whether each key is available.<br>This parameter is optional. If it is not passed, all listeners for the event type are unregistered.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('keysChange');
```

## destroy

destroy(): void

Destroys this MediaKeySession instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.destroy();
```
# Interface (MediaKeySystem)

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29f3919446ee01733553b9b39493ee11224dad86 translatedAt=2026-07-31T02:11:52.470Z pushedAt=2026-07-31T03:50:40.117Z -->

MediaKeySystem manages MediaKeySystem instances, handles device certificate (DRM certificate) requests and processing, creates sessions, manages offline media keys, obtains DRM metrics, and obtains device configurations. Before calling any API in MediaKeySystem, you must use [createMediaKeySystem](arkts-apis-drm-f.md#drmcreatemediakeysystem) to create a MediaKeySystem instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { drm } from '@kit.DrmKit';
```

## setConfigurationString

setConfigurationString(configName: string, value: string): void

Sets a configuration item in the form of a string.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](arkts-apis-drm-e.md#predefinedconfigname).                  |
| value  | string     | Yes  | Value of the configuration item.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
mediaKeySystem.setConfigurationString('stringConfigName', 'stringConfigValue'); // Ensure that stringConfigName is configurable.
```

## getConfigurationString

getConfigurationString(configName: string): string

Obtains the value of a configuration item in the form of a string.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Configuration item name, which cannot be empty and can contain a maximum of 4096 bytes.<br>If the parameter value exceeds 4096 bytes, error code 401 will be returned.<br>The configuration item name is determined by the DRM solution on the device. For details about available options, see [PreDefinedConfigName](arkts-apis-drm-e.md#predefinedconfigname).                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| string          | Value of the configuration item in the form of a string.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed, the param's length is zero or too big(exceeds 4096 Bytes).                              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let configValue: string = mediaKeySystem.getConfigurationString('vendor');
```

## setConfigurationByteArray

setConfigurationByteArray(configName: string, value: Uint8Array): void

Sets a configuration item in the form of a byte array.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](arkts-apis-drm-e.md#predefinedconfigname).                  |
| value  | Uint8Array     | Yes  | Value of the configuration item in the form of an array. The specific value is determined by the DRM solution on the device.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors.                  |
| 24700201                |  Fatal service error, for example, service died.                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
// Set configValue based on project requirements.
let configValue: Uint8Array = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
// Ensure that byteArrayConfigName of the current DRM solution is configurable.
mediaKeySystem.setConfigurationByteArray('byteArrayConfigName', configValue);
```

## getConfigurationByteArray

getConfigurationByteArray(configName: string): Uint8Array

Obtains the value of a configuration item in the form of a byte array.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item. It cannot be null. For details about available options, see [PreDefinedConfigName](arkts-apis-drm-e.md#predefinedconfigname). The specific supported names are determined by the DRM solution on the device.              |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Uint8Array          | Value of the configuration item in the form of an array.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let configValue: Uint8Array = mediaKeySystem.getConfigurationByteArray('deviceUniqueId'); // Ensure that the deviceUniqueId property exists.
```

## getStatistics

getStatistics(): StatisticKeyValue[]

Obtains the DRM metrics, including the number of active sessions, plugin version details, the maximum decryption time for each session (over three attempts), the total count of decryption operations, and the number of decryption failures.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [StatisticKeyValue[]](arkts-apis-drm-i.md#statistickeyvalue)          | Metrics.                  |

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
let statisticKeyValue: drm.StatisticKeyValue[] = mediaKeySystem.getStatistics();
```

## getMaxContentProtectionLevel

getMaxContentProtectionLevel(): ContentProtectionLevel

Obtains the maximum content protection level supported by the current DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ContentProtectionLevel](arkts-apis-drm-e.md#contentprotectionlevel)          | Maximum content protection level supported.                  |

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
let maxLevel: drm.ContentProtectionLevel = mediaKeySystem.getMaxContentProtectionLevel();
```

## generateKeySystemRequest

generateKeySystemRequest(): Promise<ProvisionRequest\>

Generates a request to obtain a device certificate for the MediaKeySystem. This API uses a promise to return the result.

If a device certificate already exists on the device, the API will return a failure.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<[ProvisionRequest](arkts-apis-drm-i.md#provisionrequest)\>          | Promise used to return the request for a device certificate. If a device certificate already exists on the device, this operation fails.  |

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
// Do not call this API if a device certificate already exists on the device.
mediaKeySystem.generateKeySystemRequest().then((provisionRequest: drm.ProvisionRequest) => {
  // provisionRequest is the device certificate request object returned by the API, including the request data and default URL.
  console.info("generateKeySystemRequest, defaultURL: " + provisionRequest.defaultURL);
});
```

## processKeySystemResponse

processKeySystemResponse(response: Uint8Array): Promise<void\>

Processes the response to a previously generated device certificate request. This API uses a promise to return the result.

If a device certificate already exists on the device, the API will return a failure.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | Yes  | Device certificate response obtained from the DRM service.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<void\>          | Promise that returns no value.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
// keySystemResponse is the device certificate response obtained from the DRM service. Pass in the actual value as required.
let keySystemResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySystem.processKeySystemResponse(keySystemResponse).then(() => {
  console.info("processKeySystemResponse");
});
```

## getCertificateStatus

getCertificateStatus(): CertificateStatus

Obtains the status of the device certificate.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CertificateStatus](arkts-apis-drm-e.md#certificatestatus)          | Certificate status.                  |

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
let certificateStatus: drm.CertificateStatus = mediaKeySystem.getCertificateStatus();
```

## on('keySystemRequired')

on(type: 'keySystemRequired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the application requests a device certificate. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. This event is available for listening after a MediaKeySystem instance is created by calling [createMediaKeySystem](arkts-apis-drm-f.md#drmcreatemediakeysystem). It is triggered when a device certificate is required.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | Yes   | Callback used to return the event information. When this event is received, it indicates that a device certificate needs to be requested.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
mediaKeySystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
  console.info('keySystemRequired ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

## off('keySystemRequired')

off(type: 'keySystemRequired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the application requests a device certificate. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. This event is available for listening after a MediaKeySystem instance is created by calling [createMediaKeySystem](arkts-apis-drm-f.md#drmcreatemediakeysystem).|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | No  | Callback used to return the event information. This parameter is optional. If it is not passed, all listeners for the event type are unregistered.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
mediaKeySystem.off('keySystemRequired');
```

## createMediaKeySession

createMediaKeySession(level: ContentProtectionLevel): MediaKeySession

Creates a MediaKeySession instance with the specified content protection level.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| level  | [ContentProtectionLevel](arkts-apis-drm-e.md#contentprotectionlevel)     | Yes  | Content protection level.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySession](arkts-apis-drm-MediaKeySession.md)          | MediaKeySession instance.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.The param level exceeds reasonable range, please use value in ContentProtectionLevel.          |
| 24700101                 |  All unknown errors                  |
| 24700104                 |  Meet max MediaKeySession num limit                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession(drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
```

## createMediaKeySession

createMediaKeySession(): MediaKeySession

Creates a MediaKeySession instance with the default content protection level.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySession](arkts-apis-drm-MediaKeySession.md)          | MediaKeySession instance.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700104                 |  Meet max MediaKeySession num limit                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
```

## getOfflineMediaKeyIds

getOfflineMediaKeyIds(): Uint8Array[]

Obtains the IDs of offline media keys.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Uint8Array[]          | Array of offline media key IDs.                  |

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
let offlineMediaKeyIds: Uint8Array[] = mediaKeySystem.getOfflineMediaKeyIds();
```

## getOfflineMediaKeyStatus

getOfflineMediaKeyStatus(mediaKeyId: Uint8Array): OfflineMediaKeyStatus

Obtains the status of offline media keys with the specified IDs.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId | Uint8Array     | Yes  | Offline media key ID.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [OfflineMediaKeyStatus](arkts-apis-drm-e.md#offlinemediakeystatus)          | Status of the offline media keys.                  |

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

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual value as required.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
let configValue: drm.OfflineMediaKeyStatus = mediaKeySystem.getOfflineMediaKeyStatus(mediaKeyId);
```

## clearOfflineMediaKeys

clearOfflineMediaKeys(mediaKeyId: Uint8Array): void

Clears offline media keys with the specified IDs.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | Offline media key ID.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.           |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem('com.clearplay.drm');
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual value as required.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySystem.clearOfflineMediaKeys(mediaKeyId);
```

## destroy

destroy(): void

Destroys this MediaKeySystem instance.

**Atomic service API**: This API can be used in atomic services since API version 14.

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
mediaKeySystem.destroy();
```
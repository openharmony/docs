# Interface (MediaKeySystem)
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->
> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

MediaKeySystem implements MediaKeySystem instance management. Specifically, it provides APIs to request and process DRM certificates, creates session, manages offline media key, obtain DRM statistical information, and obtain device configuration information. Before calling any API in MediaKeySystem, you must use [createMediaKeySystem](arkts-apis-drm-f.md#drmcreatemediakeysystem) to create a MediaKeySystem instance.

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

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  mediaKeySystem.setConfigurationString("stringConfigName", "stringConfigValue"); // Ensure that stringConfigName is configurable.
} catch (err) {
  let error = err as BusinessError;
  console.error(`setConfigurationString ERROR: ${error}`);
}
```

## getConfigurationString

getConfigurationString(configName: string): string

Obtains the value of a configuration item in the form of a string.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](arkts-apis-drm-e.md#predefinedconfigname).                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| string          | Value of the configuration item in the form of a string.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed, the param's length is zero or too big(exceeds 4096 Bytes).                              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let configValue: string = mediaKeySystem.getConfigurationString("vendor");
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationString ERROR: ${error}`);  
}
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

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors.                  |
| 24700201                |  Fatal service error, for example, service died.                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
// Set configValue based on project requirements.
let configValue: Uint8Array = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
try {
  // Ensure that byteArrayConfigName of the current DRM solution is configurable.
  mediaKeySystem.setConfigurationByteArray("byteArrayConfigName", configValue);
} catch (err) {
  let error = err as BusinessError;
  console.error(`setConfigurationByteArray ERROR: ${error}`);  
}
```

## getConfigurationByteArray

getConfigurationByteArray(configName: string): Uint8Array

Obtains the value of a configuration item in the form of a byte array.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](arkts-apis-drm-e.md#predefinedconfigname).                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Uint8Array          | Value of the configuration item in the form of an array.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let configValue: Uint8Array = mediaKeySystem.getConfigurationByteArray("deviceUniqueId"); // Ensure that deviceUniqueId exists.
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);  
}
```

## getStatistics

getStatistics(): StatisticKeyValue[]

Obtains the statistical information, including the number of current sessions, plugin version, maximum decryption duration for each session, number of decryption times, and number of decryption failures.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [StatisticKeyValue[]](arkts-apis-drm-i.md#statistickeyvalue)          | Statistical information.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let statisticKeyValue: drm.StatisticKeyValue[] = mediaKeySystem.getStatistics();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);
}
```

## getMaxContentProtectionLevel

getMaxContentProtectionLevel(): ContentProtectionLevel

Obtains the maximum content protection level supported by the current DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ContentProtectionLevel](arkts-apis-drm-e.md#contentprotectionlevel)          | Maximum content protection level.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let maxLevel: drm.ContentProtectionLevel = mediaKeySystem.getMaxContentProtectionLevel();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);
}
```

## generateKeySystemRequest

generateKeySystemRequest(): Promise<ProvisionRequest\>

Generates a provision request.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<[ProvisionRequest](arkts-apis-drm-i.md#provisionrequest)\>          | Promise used to return the provision request obtained. If a DRM certificate already exists on the device, a failure message is returned.  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
// Do not call this API if a DRM certificate already exists on the device.
mediaKeySystem.generateKeySystemRequest().then((ProvisionRequest: drm.ProvisionRequest) => {
  console.log("generateKeySystemRequest");
}).catch((err: BusinessError) => {
  console.error(`generateKeySystemRequest: ERROR: ${err}`);
});
```

## processKeySystemResponse

processKeySystemResponse(response: Uint8Array): Promise<void\>

Processes a provision response.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | Yes  | Provision response.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<void\>          | Promise                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
// keySystemResponse is the response obtained from the DRM service. Pass in the actual data obtained.
let keySystemResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySystem.processKeySystemResponse(keySystemResponse).then(() => {
  console.log("processKeySystemResponse");
}).catch((err: BusinessError) => {
  console.error(`processKeySystemResponse: ERROR: ${err}`);
});
```

## getCertificateStatus

getCertificateStatus():CertificateStatus

Obtains the status of the DRM certificate.

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
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let certificateStatus: drm.CertificateStatus = mediaKeySystem.getCertificateStatus();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getCertificateStatus ERROR: ${error}`);
}
```

## on('keySystemRequired')

on(type: 'keySystemRequired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the application requires a DRM certificate.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The event can be listened for when a MediaKeySystem instance is created by calling [createMediaKeySystem](arkts-apis-drm-f.md#drmcreatemediakeysystem). This event is triggered when the application requests a DRM certificate.|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | Yes  | Callback used to return the event information. If this event callback is returned, a DRM certificate must be requested.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
mediaKeySystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
  console.log('keySystemRequired ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

## off('keySystemRequired')

off(type: 'keySystemRequired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the application requests a DRM certificate.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The event can be listened for when a MediaKeySystem instance is created by calling [createMediaKeySystem](arkts-apis-drm-f.md#drmcreatemediakeysystem).|
| callback | (eventInfo: [EventInfo](arkts-apis-drm-i.md#eventinfo)) => void  | No  | Callback used to return the event information.                 |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
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

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.The param level exceeds reasonable range, please use value in ContentProtectionLevel.          |
| 24700101                 |  All unknown errors                  |
| 24700104                 |  Meet max MediaKeySession num limit                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession(drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySession ERROR: ${error}`);
}
```

## createMediaKeySession

createMediaKeySession(): MediaKeySession

Creates a MediaKeySession instance with the default content protection level of the DRM solution.

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
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySession ERROR: ${error}`);
}
```

## getOfflineMediaKeyIds

getOfflineMediaKeyIds(): Uint8Array[]

Obtains the IDs of offline media keys.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Uint8Array[]          | Array holding the IDs of offline media keys.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let offlineMediaKeyIds: Uint8Array[] = mediaKeySystem.getOfflineMediaKeyIds();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOfflineMediaKeyIds ERROR: ${error}`);
}
```

## getOfflineMediaKeyStatus

getOfflineMediaKeyStatus(mediaKeyId: Uint8Array): OfflineMediaKeyStatus

Obtains the status of offline media keys with the specified IDs.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId | Uint8Array     | Yes  | Array holding the IDs of offline media keys.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [OfflineMediaKeyStatus](arkts-apis-drm-e.md#offlinemediakeystatus)          | Status of the offline media keys.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual data returned.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
try {
  let configValue: drm.OfflineMediaKeyStatus = mediaKeySystem.getOfflineMediaKeyStatus(mediaKeyId);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
}
```

## clearOfflineMediaKeys

clearOfflineMediaKeys(mediaKeyId: Uint8Array): void

Clears offline media keys by ID.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | Array holding the IDs of offline media keys.           |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed.Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.           |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual data returned.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
try {
  mediaKeySystem.clearOfflineMediaKeys(mediaKeyId);
} catch (err) {
  let error = err as BusinessError;
  console.error(`clearOfflineMediaKeys ERROR: ${error}`);
}
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
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  mediaKeySystem.destroy();
} catch (err) {
  let error = err as BusinessError;
  console.error(`mediaKeySystem destroy ERROR: ${error}`);
}
```

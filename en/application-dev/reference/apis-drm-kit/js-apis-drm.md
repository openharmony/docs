# @ohos.multimedia.drm (Digital Rights Management)

The Digital Rights Management (DRM) framework provides APIs for you to develop digital rights management for audio and video applications. You can call the DRM plug-ins provided by the system to implement the following features:

* DRM certificate management: generates media key system requests, and processes responses to media key system requests to implement provision request management.
* DRM media key management: generates media key requests, processes responses to media key requests, and manages offline media keys.
* DRM authorization: authorizes access to DRM-protected content based on the media keys.
* DRM decryption: decrypts DRM-protected content.

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import drm from '@ohos.multimedia.drm';
```

## DrmErrorCode

Enumerates the DRM error codes.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| ERROR_UNKNOWN       | 24700101    | Unknown error.  |
| MAX_SYSTEM_NUM_REACHED   | 24700103    | The number of **MediaKeySystem** instances reaches 64.    |
| MAX_SESSION_NUM_REACHED    | 24700104    | The number of **MediaKeySession** instances reaches 64.      |
| SERVICE_FATAL_ERROR  | 24700201    | IPC service error.    |

## PreDefinedConfigName

Enumerates the predefined configuration options.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CONFIG_DEVICE_VENDOR        | 'vendor'    | Plug-in name.  |
| CONFIG_DEVICE_VERSION    | 'version'    | Plug-in version.    |
| CONFIG_DEVICE_DESCRIPTION     | 'description'    | Device descriptor.      |
| CONFIG_DEVICE_ALGORITHMS   | 'algorithms'    | Algorithm names.    |
| CONFIG_DEVICE_UNIQUE_ID    | 'deviceUniqueId'    | Unique device ID.    |
| CONFIG_SESSION_MAX         | 'maxSessionNum'    | Maximum number of sessions supported by the device.    |
| CONFIG_SESSION_CURRENT   | 'currentSessionNum'    | Number of current sessions.    |

## MediaKeyType

Enumerates the media key types.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| MEDIA_KEY_TYPE_OFFLINE        | 0    | Offline.  |
| MEDIA_KEY_TYPE_ONLINE   | 1    | Online.    |

## OfflineMediaKeyStatus

Enumerates the statuses of offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN        | 0    | Unknown status.  |
| OFFLINE_MEDIA_KEY_STATUS_USABLE   | 1    | The media key is available.    |
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE     | 2    | The media key is inactive.      |

## CertificateStatus

Enumerates the device certificate statuses.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CERT_STATUS_PROVISIONED        | 0    | A device certificate has been installed on the device.  |
| CERT_STATUS_NOT_PROVISIONED   | 1    | No device certificate is installed on the device.    |
| CERT_STATUS_EXPIRED    | 2    | The device certificate has expired.      |
| CERT_STATUS_INVALID  | 3    | The device certificate is invalid.    |
| CERT_STATUS_UNAVAILABLE  | 4    | The device certificate is unavailable.    |

## MediaKeyRequestType

Enumerates the types of requests for media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN        | 0    | Unknown type.  |
| MEDIA_KEY_REQUEST_TYPE_INITIAL    | 1    | Initial request.    |
| MEDIA_KEY_REQUEST_TYPE_RENEWAL     | 2    | Renewal request.      |
| MEDIA_KEY_REQUEST_TYPE_RELEASE   | 3    | Release request.    |
| MEDIA_KEY_REQUEST_TYPE_NONE    | 4    | None.    |
| MEDIA_KEY_REQUEST_TYPE_UPDATE    | 5    | Update request.    |

## ContentProtectionLevel

Enumerates the content protection levels.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CONTENT_PROTECTION_LEVEL_UNKNOWN        | 0    | Unknown level.  |
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO   | 1    | Software content protection level.    |
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO    | 2    | Hardware content protection level.      |
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW  | 3    | Hardware enhancement level.    |
| CONTENT_PROTECTION_LEVEL_MAX  | 4    | Highest content protection level.    |

## ProvisionRequest

Describes a provision request, which is used to request a device certificate from a provisioning server.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| data   | Uint8Array | Yes | Data carried in the provision request.     |
| defaultURL     | string                 | Yes | URL of the provisioning server.      |

## OptionsData

Describes the operation data carried in a provision request.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the operation data.     |
| value     | string                 | Yes | Value of the operation data.      |

## MediaKeyRequest

Describes a media key request, which is used to request a media key from a license server.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| mediaKeyRequestType   | [MediaKeyRequestType](#mediakeyrequesttype) | Yes | Type of the media key request.     |
| data     | Uint8Array                 | Yes | Data carried in the media key request.      |
| defaultURL     | string                 | Yes | URL of the license server.      |

## EventInfo

Describes the event information.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| info   | Uint8Array | Yes | Event information.     |
| extraInfo     | string                 | Yes | Additional event information.      |

## StatisticKeyValue

Describes the statistics information.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the statistical item.     |
| value     | string                 | Yes | Value of the statistical item.      |

## MediaKeyStatus

Describes the media key status.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | ID of the media key.     |
| value     | string                 | Yes | Status of the media key.      |

## KeysInfo

Describes the information about media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| keyId   | Uint8Array | Yes | ID of the media keys, in the form of a byte array.     |
| value     | string                 | Yes | Status of the media key.      |

## MediaKeySystemInfo

Describes the DRM information of a media source.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| uuid   | string | Yes | Unique ID of the DRM plug-in.     |
| pssh     | Uint8Array                 | Yes | Protection Scheme Specific Header (PSSH) in the DRM information.      |

## drm.createMediaKeySystem

createMediaKeySystem(name: string): MediaKeySystem

Creates a **MediaKeySystem** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | Plug-in type.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySystem](#mediakeysystem)           | **MediaKeySystem** instance.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700103                |  Meet max MediaKeySystem num limit                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';
try {
  let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySystem ERROR: ${error}`);  
}
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string): boolean

Checks whether the device supports the media key system with a given plug-in type.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | Plug-in type.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | **true**: The device supports the media key system.<br>**false**: The device does not support the media key system.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

try {
  let Supported = drm.isMediaKeySystemSupported("com.clearplay.drm");
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);  
}

```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string): boolean

Checks whether the device supports the media key system with a given plug-in type and MIME type.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | Plug-in type.                  |
| mimeType  | string     | Yes  | MIME type. The supported MIME types are determined by the DRM scheme on the device.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | **true**: The device supports the media key system.<br>**false**: The device does not support the media key system.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.                |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

try {
  let Supported = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/mp4");
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);
}
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string, level: ContentProtectionLevel): boolean

Checks whether the device supports the media key system with a given plug-in type, MIME type, and content protection level.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | Plug-in type.                  |
| mimeType  | string     | Yes  | MIME type. The supported MIME types are determined by the DRM scheme on the device.                  |
| level  | [ContentProtectionLevel](#contentprotectionlevel)     | Yes  | Content protection level of the device.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | **true**: The device supports the media key system.<br>**false**: The device does not support the media key system.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed.  Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed, the param name's length is zero or too big(exceeds 4096 Bytes)               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

try {
  let Supported = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/mp4", drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);
}

```

## MediaKeySystem
Manages and records media key sessions. Before calling any API in **MediaKeySystem**, you must use [createMediaKeySystem](#drmcreatemediakeysystem) to create a **MediaKeySystem** instance.

### setConfigurationString

setConfigurationString(configName: string, value: string): void

Sets a configuration item in the form of a string.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM scheme on the device.                  |
| value  | string     | Yes  | Value of the configuration item.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  mediaKeysystem.setConfigurationString("configName", "configValue");
} catch (err) {
  let error = err as BusinessError;
  console.error(`setConfigurationString ERROR: ${error}`);
}

```

### getConfigurationString

getConfigurationString(configName: string): string

Obtains the value of a configuration item in the form of a string.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| string          | Value of the configuration item, in the form of a string.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed, the param's length is zero or too big(exceeds 4096 Bytes).                              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let configValue: string = mediaKeysystem.getConfigurationString("configName");
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationString ERROR: ${error}`);  
}

```

### setConfigurationByteArray

setConfigurationByteArray(configName: string, value: Uint8Array): void

Sets a configuration item in the form of a byte array.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item.                  |
| value  | Uint8Array     | Yes  | Value of the configuration item, in the form of an array.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let configValue = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
try {
  mediaKeysystem.setConfigurationByteArray("configName", configValue);
} catch (err) {
  let error = err as BusinessError;
  console.error(`setConfigurationByteArray ERROR: ${error}`);  
}

```

### getConfigurationByteArray

getConfigurationByteArray(configName: string): Uint8Array

Obtains the values of a configuration item in the form of a byte array.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Uint8Array          | Value of the configuration item, in the form of an array.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let configValue: Uint8Array = mediaKeysystem.getConfigurationByteArray("configName");
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);  
}

```

### getStatistics

getStatistics(): StatisticKeyValue[]

Obtains the statistics information, including the number of current sessions, decryption times, and decryption failures, as well as the plug-in version.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [StatisticKeyValue[]](#statistickeyvalue)          | Statistics information, in the form of an array.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let statisticKeyValue: drm.StatisticKeyValue[] = mediaKeysystem.getStatistics();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);
}

```

### getMaxContentProtectionLevel

getMaxContentProtectionLevel(): ContentProtectionLevel

Obtains the maximum content protection level supported by the device.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ContentProtectionLevel](#contentprotectionlevel)          | Maximum content protection level.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let maxLevel: drm.ContentProtectionLevel = mediaKeysystem.getMaxContentProtectionLevel();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getConfigurationByteArray ERROR: ${error}`);
}

```

### generateKeySystemRequest

generateKeySystemRequest(): Promise<ProvisionRequest\>

Generates a media key system request to obtain a provision request.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ProvisionRequest](#provisionrequest)          | Provision request.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
mediaKeysystem.generateKeySystemRequest().then((ProvisionRequest: drm.ProvisionRequest) => {
  console.log("generateKeySystemRequest");
}).catch((err: BusinessError) => {
  console.error(`generateKeySystemRequest: ERROR: ${err}`);
});
```

### processKeySystemResponse

processKeySystemResponse(response: Uint8Array): Promise<void\>

Processes a response to the media key system request.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | Yes  | Response to the media key system request.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  he parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let keySystemResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeysystem.processKeySystemResponse(keySystemResponse).then(() => {
  console.log("processKeySystemResponse");
}).catch((err: BusinessError) => {
  console.error(`processKeySystemResponse: ERROR: ${err}`);
});
```

### getCertificateStatus

getCertificateStatus():CertificateStatus

Obtains the status of the OEM device certificate.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CertificateStatus](#certificatestatus)          | Status of the OEM device certificate.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let certificateStatus: drm.CertificateStatus = mediaKeysystem.getCertificateStatus();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getCertificateStatus ERROR: ${error}`);
}

```

### on('keySystemRequired')

on(type: 'keySystemRequired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the application needs to request a device certificate.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keySystemRequired'**. The event can be listened for when a **MediaKeySystem** instance is created. This event is triggered when the application sends a media key system request.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the result. If this event callback is returned, a device certificate must be requested.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function registerkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
  mediaKeysystem.on('keySystemRequired', (eventInfo: drm.EventInfo) => {
    console.log('keySystemRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
  });
}
```

### off('keySystemRequired')

off(type: 'keySystemRequired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the application needs to request a device certificate.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keySystemRequired'**. The event can be listened for when a **MediaKeySystem** instance is created.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used for unsubscription.               |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**Example**

```ts
function unregisterkeySystemRequired(mediaKeysystem: drm.MediaKeySystem): void {
  mediaKeysystem.off('keySystemRequired');
}
```

### createMediaKeySession

createMediaKeySession(level: ContentProtectionLevel): MediaKeySession

Creates a **MediaKeySession** instance based on the specified content protection level.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| level  | [ContentProtectionLevel](#contentprotectionlevel)     | Yes  | Content protection level of the device.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySession](#mediakeysession)          | **MediaKeySession** instance.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.The param level exceeds reasonable range, please use value in ContentProtectionLevel.          |
| 24700101                 |  MAll unknown errors                  |
| 24700104                 |  Meet max MediaKeySession num limit                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession(drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySession ERROR: ${error}`);
}

```

### createMediaKeySession

createMediaKeySession(): MediaKeySession

Creates a **MediaKeySession** instance based on the default content protection level.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySession](#mediakeysession)          | **MediaKeySession** instance.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700104                 |  Meet max MediaKeySession num limit                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySession ERROR: ${error}`);
}

```

### getOfflineMediaKeyIds

getOfflineMediaKeyIds(): Uint8Array[]

Obtains the IDs of offline media keys.

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
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  let offlineMediaKeyIds: Uint8Array[] = mediaKeysystem.getOfflineMediaKeyIds();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOfflineMediaKeyIds ERROR: ${error}`);
}

```

### getOfflineMediaKeyStatus

getOfflineMediaKeyStatus(mediaKeyId: Uint8Array): OfflineMediaKeyStatus

Obtain the status of the offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId | Uint8Array     | Yes  | ID of the offline media keys.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [OfflineMediaKeyStatus](#offlinemediakeystatus)          | Status of the offline media keys.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeyIdString = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
try {
  let configValue: drm.OfflineMediaKeyStatus = mediaKeysystem.getOfflineMediaKeyStatus(mediaKeyIdString);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getOfflineMediaKeyStatus ERROR: ${error}`);
}

```

### clearOfflineMediaKeys

clearOfflineMediaKeys(mediaKeyId: Uint8Array): void

Clears offline media keys by ID.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | ID of the offline media keys.                  | The ID can be obtained from the return value of **processMeidaKeyResponse**.|

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed.Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.           |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeyIdString = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
try {
  mediaKeysystem.clearOfflineMediaKeys(mediaKeyIdString);
} catch (err) {
  let error = err as BusinessError;
  console.error(`clearOfflineMediaKeys ERROR: ${error}`);
}

```

### destroy

destroy(): void

Destroys the resources applied for running the **MediaKeySystem** instance.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
try {
  mediaKeysystem.destroy();
} catch (err) {
  let error = err as BusinessError;
  console.error(`mediaKeysystem destroy ERROR: ${error}`);
}

```

## MediaKeySession
Manages the media keys and decoder. Before calling any API in **MediaKeySession**, you must use [createMediaKeySession](#createmediakeysession) to create a **MediaKeySession** instance.

### generateMediaKeyRequest

generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediaKeyType: number, options?: OptionsData[]): Promise<MediaKeyRequest\>

Generates a media key request.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mimeType  | string     | Yes  | MIME type.                  |
| initData  | Uint8Array     | Yes  | PSSH data (not encoded using Base64).                  |
| mediaKeyType| number     | Yes  | Media key type.                  | The value **0** means an online media key, and **1** means an offline media key.|
| OptionsData  | [OptionsData[]](#optionsdata)     | Yes  | Reserved operation data.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeyRequest](#mediakeyrequest)          | Media key request.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                | The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let optionsData: drm.OptionsData[]  = [
    {name : "optionsDataNameA", value : "optionsDataValueA"},
    {name : "optionsDataNameB", value : "optionsDataValueB"}
];
let uint8pssh = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateMediaKeyRequest("video/mp4", uint8pssh, 0, optionsData).then((mediaKeyRequest: drm.MediaKeyRequest) =>{
  console.log('generateMediaKeyRequest' + mediaKeyRequest);
}).catch((err: BusinessError) => {
  console.error(`generateMediaKeyRequest: ERROR: ${err}`);
});
```

### processMediaKeyResponse

processMediaKeyResponse(response: Uint8Array): Promise<Uint8Array\>

Processes a response to the media key request.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | Yes  | Response to the media key request.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [Uint8Array]          | ID of offline media keys.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let mediaKeyResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(mediaKeyResponse).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
```

### checkMediaKeyStatus

 checkMediaKeyStatus(): MediaKeyStatus[]

Checks the status of online media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeyStatus[]](#mediakeystatus)          | Array holding the media key statuses.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  let keyStatus: drm.MediaKeyStatus[] =  mediaKeySession.checkMediaKeyStatus();
} catch (err) {
  let error = err as BusinessError;
  console.error(`checkMediaKeyStatus ERROR: ${error}`);
}

```

### clearMediaKeys

clearMediaKeys(): void

Clears online media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  mediaKeySession.clearMediaKeys();
} catch (err) {
  let error = err as BusinessError;
  console.error(`clearMediaKeys ERROR: ${error}`);
}
 
```

### generateOfflineReleaseRequest

generateOfflineReleaseRequest(mediaKeyId: Uint8Array): Promise<Uint8Array\>

Generates a request to release offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array    | Yes  | ID of the offline media keys.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [Uint8Array]          | Request for releasing the offline media keys.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let Request = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(Request).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateOfflineReleaseRequest(mediaKeyId).then((offlineReleaseRequest: Uint8Array) => {
  console.log('generateOfflineReleaseRequest:' + offlineReleaseRequest);
}).catch((err: BusinessError) => {
  console.error(`generateOfflineReleaseRequest: ERROR: ${err}`);
});
```

### processOfflineReleaseResponse

processOfflineReleaseResponse(mediaKeyId: Uint8Array, response: Uint8Array): Promise<void\>

Processes a response to a request for releasing offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | ID of the offline media keys.                  |
| response  | Uint8Array     | Yes  | Response to the request for releasing the offline media keys.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let offlineReleaseRequest = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(offlineReleaseRequest).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
let response = new Uint8Array([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processOfflineReleaseResponse(mediaKeyId, response).then(() => {
  console.log('processOfflineReleaseResponse');
}).catch((err: BusinessError) => {
  console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
});
```

### restoreOfflineMediaKeys

restoreOfflineMediaKeys(mediaKeyId: Uint8Array): Promise<void\>

Restores offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | ID of the offline media keys.                  |


**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
let response = new Uint8Array ([0x00,0x00]);
let mediaKeyId = new Uint8Array ([0x00,0x00]);
mediaKeySession.processOfflineReleaseResponse(mediaKeyId, response).then(() => {
  console.log('processOfflineReleaseResponse');
}).catch((err: BusinessError) => {
  console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
});
mediaKeySession.restoreOfflineMediaKeys(mediaKeyId).then(() => {
  console.log("restoreOfflineMediaKeys");
}).catch((err: BusinessError) => {
  console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
});
```

### getContentProtectionLevel

getContentProtectionLevel(): ContentProtectionLevel

Obtains the content protection level of this media key session.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [ContentProtectionLevel](#contentprotectionlevel)          | Content protection level.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeySession.getContentProtectionLevel();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getContentProtectionLevel ERROR: ${error}`);
}

```

### requireSecureDecoderModule

requireSecureDecoderModule(mimeType: string): boolean

Obtains the status of the secure decoder.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mimeType  | string     | Yes  | MIME type.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [boolean]          | Status of the secure decoder. The value **true** means that the secure decoder is ready, and **false** means the opposite.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';

let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  let status: boolean = mediaKeySession.requireSecureDecoderModule("mimeType");
} catch (err) {
  let error = err as BusinessError;
  console.error(`requireSecureDecoderModule ERROR: ${error}`);
}

```

### on('keyRequired')

on(type: 'keyRequired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the application needs to request a media key. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyRequired'**. The event can be listened for when a **MediaKeySystem** instance is created. This event is triggered when the application sends a media key request.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the result. If this event callback is returned, a media key request is being sent.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function registerKeyRequired(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('keyRequired', (eventInfo: drm.EventInfo) => {
        console.log('keyRequired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('keyRequired')

off(type: 'keyRequired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the application needs to request a media key.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyRequired'**. The event can be listened for when a **MediaKeySystem** instance is created.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used for unsubscription.               |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterKeyRequired(mediaKeysession: drm.MediaKeySession): void {
  mediaKeysession.off('keyRequired');
}
```

### on('keyExpired')

on(type: 'keyExpired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the media key expires. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyExpired'**. The event can be listened for when a **MediaKeySystem** instance is created. This event is triggered when the media key expires.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the result. If this event callback is returned, the session is lost.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function registerKeyExpired(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('keyExpired', (eventInfo: drm.EventInfo) => {
        console.log('keyExpired' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('keyExpired')

off(type: 'keyExpired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the media key expires.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyExpired'**. The event can be listened for when a **MediaKeySystem** instance is created.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used for unsubscription.               |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterKeyExpired(mediaKeysession: drm.MediaKeySession): void {
  mediaKeysession.off('keyExpired');
}
```

### on('vendorDefined')

on(type: 'vendorDefined', callback: (eventInfo: EventInfo) => void): void

Subscribes to vendor-defined events. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'vendorDefined'**. The event can be listened for when a **MediaKeySystem** instance is created. This event is triggered when a vendor-defined event occurs.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the result. If this event callback is returned, the session is lost.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function registerVendorDefinedt(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('vendorDefined', (eventInfo: drm.EventInfo) => {
        console.log('vendorDefined' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('vendorDefined')

off(type: 'vendorDefined', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from vendor-defined events.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'vendorDefined'**. The event can be listened for when a **MediaKeySystem** instance is created.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used for unsubscription.               |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterVendorDefined(mediaKeysession: drm.MediaKeySession): void {
  mediaKeysession.off('vendorDefined');
}
```

### on('expirationUpdate')

on(type: 'expirationUpdate', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the media key updates on expiry. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'expirationUpdate'**. The event can be listened for when a **MediaKeySystem** instance is created. This event is triggered when the media key updates on expiry.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the result. If this event callback is returned, the session is lost.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function registerExpirationUpdate(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
        console.log('expirationUpdate' + 'extra:' + eventInfo.extraInfo + ' data:' + eventInfo.info);
    });
}
```

### off('expirationUpdate')

off(type: 'expirationUpdate', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the media key updates on expiry. 

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'expirationUpdate'**. The event can be listened for when a **MediaKeySystem** instance is created.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used for unsubscription.               |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.       |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterExpirationUpdate(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.off('expirationUpdate');
}
```

### on('keysChange')

on(type: 'keysChange', callback: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

Subscribes to events indicating that the media key changes. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keysChange'**. The event can be listened for when a **MediaKeySystem** instance is created. This event is triggered when the media key changes.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the result. If this event callback is returned, the session is lost.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function registerkeysChange(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.on('keysChange', (keyInfo: drm.KeysInfo[], newKeyAvailable: boolean) => {
        console.log('keysChange' + 'keyId:' + keyInfo.keyId + ' data:' + keyInfo.value);
    });
}
```

### off('keysChange')

off(type: 'keysChange', callback?: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

Unsubscribes from events indicating that the media key changes.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keysChange'**. The event can be listened for when a **MediaKeySystem** instance is created.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used for unsubscription.               |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';

function unregisterkeyChange(mediaKeysession: drm.MediaKeySession): void {
    mediaKeysession.off('keysChange');
}
```

### destroy

destroy(): void

Destroys the resources applied for running the **MediaKeySession** instance.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Service fatal error e.g. service died                  |

**Example**

```ts
import drm from '@ohos.multimedia.drm';
import { BusinessError } from '@ohos.base';
let mediaKeysystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeysystem.createMediaKeySession();
try {
  mediaKeySession.destroy();
} catch (err) {
  let error = err as BusinessError;
  console.error(`mediaKeySession destroy ERROR: ${error}`);
}

```

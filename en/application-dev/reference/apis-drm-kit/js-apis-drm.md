# @ohos.multimedia.drm (Digital Rights Management)

The Digital Rights Management (DRM) framework provides APIs for you to develop digital rights management for your audio and video applications. You can call the DRM solutions (which exist as DRM plugins) provided by the system to implement the following features:

* DRM certificate management: generates provision requests and processes responses to these requests. Such a request/response exchange occurs between an application and a provisioning server to retrieve a DRM certificate.
* DRM media key management: generates media key requests, processes responses to these requests, and manages offline media keys. Such a request/response exchange occurs between an application and a license server to obtain or release a media key, which is used to decrypt DRM-protected content.
* DRM authorization: authorizes access to DRM-protected content based on media keys.
* DRM decryption: decrypts DRM-protected content.

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { drm } from '@kit.DrmKit';
```

## DrmErrorCode

Enumerates the DRM error codes.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| ERROR_UNKNOWN       | 24700101    | Unknown error.  |
| MAX_SYSTEM_NUM_REACHED   | 24700103    | The number of **MediaKeySystem** instances reaches the upper limit (64).   |
| MAX_SESSION_NUM_REACHED    | 24700104    | The number of **MediaKeySession** instances reaches the upper limit (64).    |
| SERVICE_FATAL_ERROR  | 24700201    | DRM service error.    |

## PreDefinedConfigName

Enumerates the names of predefined configuration items.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CONFIG_DEVICE_VENDOR        | 'vendor'    | Plugin vendor name, which corresponds to the value of **vendor** in the return value of [getConfigurationString](#getconfigurationstring).  |
| CONFIG_DEVICE_VERSION    | 'version'    | Plugin version number, which corresponds to the value of **version** in the return value of [getConfigurationString](#getconfigurationstring).    |
| CONFIG_DEVICE_DESCRIPTION     | 'description'    | Device descriptor, which corresponds to the value of **description** in the return value of [getConfigurationString](#getconfigurationstring).     |
| CONFIG_DEVICE_ALGORITHMS   | 'algorithms'    | Supported algorithm names, which correspond to the value of **algorithms** in the return value of [getConfigurationString](#getconfigurationstring).    |
| CONFIG_DEVICE_UNIQUE_ID    | 'deviceUniqueId'    | Unique device ID, which corresponds to the value of **deviceUniqueId** in the return value of [getConfigurationByteArray](#getconfigurationbytearray).    |
| CONFIG_SESSION_MAX         | 'maxSessionNum'    | Maximum number of sessions supported by the device, which corresponds to the value of **maxSessionNum** in the return value of [getConfigurationString](#getconfigurationstring).    |
| CONFIG_SESSION_CURRENT   | 'currentSessionNum'    | Number of existing sessions, which corresponds to the value of **currentSessionNum** in the return value of [getConfigurationString](#getconfigurationstring).    |

## MediaKeyType

Enumerates the types of media keys.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| MEDIA_KEY_TYPE_OFFLINE        | 0    | Offline.  |
| MEDIA_KEY_TYPE_ONLINE   | 1    | Online.    |

## OfflineMediaKeyStatus

Enumerates the statuses of offline media keys.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN        | 0    | Unknown status.  |
| OFFLINE_MEDIA_KEY_STATUS_USABLE   | 1    | The media key is available.    |
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE     | 2    | The media key is inactive.      |

## CertificateStatus

Enumerates the statuses of DRM certificates.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CERT_STATUS_PROVISIONED        | 0    | A DRM certificate has been installed on the device.  |
| CERT_STATUS_NOT_PROVISIONED   | 1    | No DRM certificate is installed on the device.    |
| CERT_STATUS_EXPIRED    | 2    | The DRM certificate has expired.      |
| CERT_STATUS_INVALID  | 3    | The DRM certificate is invalid.    |
| CERT_STATUS_UNAVAILABLE  | 4    | The DRM certificate is unavailable.    |

## MediaKeyRequestType

Enumerates the types of media key requests.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CONTENT_PROTECTION_LEVEL_UNKNOWN        | 0    | Unknown content protection level.  |
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO   | 1    | Software content protection level.    |
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO    | 2    | Hardware content protection level.      |
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW  | 3    | Enhanced hardware content protection level.    |
| CONTENT_PROTECTION_LEVEL_MAX  | 4    | Highest content protection level.    |

## ProvisionRequest

Describes a provision request, which is used to request a DRM certificate from a provisioning server.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| data   | Uint8Array | Yes | Data carried in the provision request.     |
| defaultURL     | string                 | Yes | URL of the provisioning server (which provisions DRM certificates).      |

## OptionsData

Describes the optional data carried in a media key request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the optional data.     |
| value     | string                 | Yes | Value of the optional data.      |

## MediaKeyRequest

Describes a media key request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| mediaKeyRequestType   | [MediaKeyRequestType](#mediakeyrequesttype) | Yes | Type of the media key request.     |
| data     | Uint8Array                 | Yes | Data carried in the media key request.      |
| defaultURL     | string                 | Yes | URL of the license server (which provisions media keys).      |

## EventInfo

Describes the event information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| info   | Uint8Array | Yes | Event information.     |
| extraInfo     | string                 | Yes | Extended event information.      |

## StatisticKeyValue

Describes the statistical information.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the statistical item.     |
| value     | string                 | Yes | Value of the statistical item.      |

## MediaKeyStatus

Describes the media key status.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the media key status (such as the media key expiration time and content protection level).     |
| value     | string                 | Yes | Value of the media key status.      |

## KeysInfo

Describes the information about media keys.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| keyId   | Uint8Array | Yes | Media key ID.     |
| value     | string                 | Yes | Media key status.      |

## MediaKeySystemInfo

Describes the DRM information, which is used to encrypt content.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| uuid   | string | Yes | UUID of the DRM content protection system.     |
| pssh     | Uint8Array                 | Yes | Protection System Specific Header (PSSH) in the DRM information.      |

## MediaKeySystemDescription<sup>12+</sup>

Describes the plugin information.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| name   | string | Yes | Name of the plugin.     |
| uuid   | string | Yes | UUID of the plugin.     |

## drm.createMediaKeySystem

createMediaKeySystem(name: string): MediaKeySystem

Creates a **MediaKeySystem** instance.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name.                  |

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
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
} catch (err) {
  let error = err as BusinessError;
  console.error(`createMediaKeySystem ERROR: ${error}`);  
}
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string): boolean

Checks whether the device supports the specified DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Returns **true** if the device supports the DRM solution; returns **false** otherwise.                    |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed, the param name's length is zero or too big(exceeds 4096 Bytes).               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let supported: boolean = drm.isMediaKeySystemSupported("com.clearplay.drm");
  console.log("isMediaKeySystemSupported: ", supported);
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);
}
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string): boolean

Checks whether the device supports the combination of the DRM solution and MIME type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name.                  |
| mimeType  | string     | Yes  | MIME type, which is determined by the DRM solution.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Returns **true** if the device supports the combination; returns **false** otherwise.                    |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.                |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let supported: boolean = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/avc");
  console.log("isMediaKeySystemSupported: ", supported);
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);
}
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string, level: ContentProtectionLevel): boolean

Checks whether the device supports the combination of the DRM solution, MIME type, and content protection level.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name.                  |
| mimeType  | string     | Yes  | MIME type, which is determined by the DRM solution.                  |
| level  | [ContentProtectionLevel](#contentprotectionlevel)     | Yes  | Content protection level.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Returns **true** if the device supports the combination; returns **false** otherwise.                    |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let supported: boolean = drm.isMediaKeySystemSupported("com.clearplay.drm", "video/avc", drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
  console.log("isMediaKeySystemSupported: ", supported);
} catch (err) {
  let error = err as BusinessError;
  console.error(`isMediaKeySystemSupported ERROR: ${error}`);
}
```

## drm.getMediaKeySystemUuid<sup>12+</sup>

getMediaKeySystemUuid(name: string): string;

Obtains the UUID of the DRM content protection system supported by the specified DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| string  | UUID of the DRM content protection system.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed.Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.                |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let uuid: String = drm.getMediaKeySystemUuid("com.clearplay.drm");
  console.log("getMediaKeySystemUuid: ", uuid);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getMediaKeySystemUuid ERROR: ${error}`);  
}
```

## drm.getMediaKeySystems<sup>12+</sup>

getMediaKeySystems(): MediaKeySystemDescription[]

Obtains the list of plugins supported by the device.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySystemDescription[]](#mediakeysystemdescription12)           | Array of the supported plugins.                  |

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
try {
  let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getMediaKeySystems ERROR: ${error}`);  
}
```

## MediaKeySystem
Implements **MediaKeySystem** instance management. Specifically, it provides APIs to request and process DRM certificates, creates session, manages offline media key, obtain DRM statistical information, and obtain device configuration information. Before calling any API in **MediaKeySystem**, you must use [createMediaKeySystem](#drmcreatemediakeysystem) to create a **MediaKeySystem** instance.

### setConfigurationString

setConfigurationString(configName: string, value: string): void

Sets a configuration item in the form of a string.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](#predefinedconfigname).                  |
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

### getConfigurationString

getConfigurationString(configName: string): string

Obtains the value of a configuration item in the form of a string.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](#predefinedconfigname).                  |

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

### setConfigurationByteArray

setConfigurationByteArray(configName: string, value: Uint8Array): void

Sets a configuration item in the form of a byte array.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](#predefinedconfigname).                  |
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

### getConfigurationByteArray

getConfigurationByteArray(configName: string): Uint8Array

Obtains the value of a configuration item in the form of a byte array.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| configName  | string     | Yes  | Name of the configuration item, which is determined by the DRM solution on the device and cannot be empty. For details about available options, see [PreDefinedConfigName](#predefinedconfigname).                  |

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

### getStatistics

getStatistics(): StatisticKeyValue[]

Obtains the statistical information, including the number of current sessions, plugin version, maximum decryption duration for each session, number of decryption times, and number of decryption failures.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [StatisticKeyValue[]](#statistickeyvalue)          | Statistical information.                  |

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

### getMaxContentProtectionLevel

getMaxContentProtectionLevel(): ContentProtectionLevel

Obtains the maximum content protection level supported by the current DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

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

### generateKeySystemRequest

generateKeySystemRequest(): Promise<ProvisionRequest\>

Generates a provision request.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<[ProvisionRequest](#provisionrequest)\>          | Promise used to return the provision request obtained. If a DRM certificate already exists on the device, a failure message is returned.  |

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

### processKeySystemResponse

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

### getCertificateStatus

getCertificateStatus():CertificateStatus

Obtains the status of the DRM certificate.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CertificateStatus](#certificatestatus)          | Certificate status.                  |

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

### on('keySystemRequired')

on(type: 'keySystemRequired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the application requires a DRM certificate.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The event can be listened for when a **MediaKeySystem** instance is created. This event is triggered when the application requests a DRM certificate.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the event information. If this event callback is returned, a DRM certificate must be requested.                |

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

### off('keySystemRequired')

off(type: 'keySystemRequired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the application requests a DRM certificate.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The event can be listened for when a **MediaKeySystem** instance is created.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used to return the event information.                 |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.               |
| 24700101                |  All unknown errors                  |

**Example**

```ts
let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
mediaKeySystem.off('keySystemRequired');
```

### createMediaKeySession

createMediaKeySession(level: ContentProtectionLevel): MediaKeySession

Creates a **MediaKeySession** instance with the specified content protection level.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| level  | [ContentProtectionLevel](#contentprotectionlevel)     | Yes  | Content protection level.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySession](#mediakeysession)          | **MediaKeySession** instance.                  |

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

### createMediaKeySession

createMediaKeySession(): MediaKeySession

Creates a **MediaKeySession** instance with the default content protection level of the DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

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

### getOfflineMediaKeyIds

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

### getOfflineMediaKeyStatus

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
| [OfflineMediaKeyStatus](#offlinemediakeystatus)          | Status of the offline media keys.                  |

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

### clearOfflineMediaKeys

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

### destroy

destroy(): void

Destroys this **MediaKeySystem** instance.

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

## MediaKeySession
Implements media key management. Before calling any API in **MediaKeySession**, you must use [createMediaKeySession](#createmediakeysession) to create a **MediaKeySession** instance.

### generateMediaKeyRequest

generateMediaKeyRequest(mimeType: string, initData: Uint8Array, mediaKeyType: number, options?: OptionsData[]): Promise<MediaKeyRequest\>

Generates a media key request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mimeType  | string     | Yes  | MIME type, which is determined by the DRM solution.                  |
| initData  | Uint8Array     | Yes  | Initial data.                  |
| mediaKeyType| number     | Yes  | Type of the media key. The value **0** means an online media key, and **1** means an offline media key.|
| options  | [OptionsData[]](#optionsdata)     | No  | Optional data.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<[MediaKeyRequest](#mediakeyrequest)\>          | Promise used to return the media key request generated.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                | The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// PSSH data is the descriptive header of the copyright protection system and is encapsulated in encrypted streams. Specifically, in MP4 file, the PSSH data is found within the PSSH box; for DASH streams, the PSSH data is located in the MPD and MP4 PSSH box; for HLS+TS streams, the PSSH data is located in the M3U8 file and each TS segment. Pass in the actual value.
let uint8pssh = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateMediaKeyRequest("video/avc", uint8pssh, drm.MediaKeyType.MEDIA_KEY_TYPE_ONLINE).then((mediaKeyRequest: drm.MediaKeyRequest) =>{
  console.log('generateMediaKeyRequest' + mediaKeyRequest);
}).catch((err: BusinessError) => {
  console.error(`generateMediaKeyRequest: ERROR: ${err}`);
});
```

### processMediaKeyResponse

processMediaKeyResponse(response: Uint8Array): Promise<Uint8Array\>

Processes a media key response.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| response  | Uint8Array     | Yes  | Media key response.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<Uint8Array\>          | Promise used to return the media key IDs.                  |

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
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyResponse is obtained from the DRM service. Pass in the actual value obtained.
let mediaKeyResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(mediaKeyResponse).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
```

### checkMediaKeyStatus

 checkMediaKeyStatus(): MediaKeyStatus[]

Checks the status of the media keys in use.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeyStatus[]](#mediakeystatus)          | Media key status.                  |

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
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
try {
  let keyStatus: drm.MediaKeyStatus[] =  mediaKeySession.checkMediaKeyStatus();
} catch (err) {
  let error = err as BusinessError;
  console.error(`checkMediaKeyStatus ERROR: ${error}`);
}
```

### clearMediaKeys

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
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyResponse is obtained from the DRM service. Pass in the actual value obtained.
let mediaKeyResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processMediaKeyResponse(mediaKeyResponse).then((mediaKeyId: Uint8Array) => {
  console.log('processMediaKeyResponse:' + mediaKeyId);
}).catch((err: BusinessError) => {
  console.error(`processMediaKeyResponse: ERROR: ${err}`);
});
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

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array    | Yes  | Array holding the IDs of offline media keys.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<Uint8Array\>          | Promise used to return the request generated if the DRM solution on the device supports offline media key release.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual data returned.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateOfflineReleaseRequest(mediaKeyId).then((offlineReleaseRequest: Uint8Array) => {
  console.log('generateOfflineReleaseRequest:' + offlineReleaseRequest);
}).catch((err: BusinessError) => {
  console.error(`generateOfflineReleaseRequest: ERROR: ${err}`);
});
```

### processOfflineReleaseResponse

processOfflineReleaseResponse(mediaKeyId: Uint8Array, response: Uint8Array): Promise<void\>

Processes a response to a request for releasing offline media keys.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | Array holding the IDs of offline media keys.                  |
| response  | Uint8Array     | Yes  | Response to the request for releasing offline media keys.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<void\>          | Promise used to return the result if the DRM solution on the device supports offline media key release.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Apply for memory based on the actual length.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.generateOfflineReleaseRequest(mediaKeyId).then((offlineReleaseRequest: Uint8Array) => {
  console.log('generateOfflineReleaseRequest:' + offlineReleaseRequest);
}).catch((err: BusinessError) => {
  console.error(`generateOfflineReleaseRequest: ERROR: ${err}`);
});
// offlineReleaseResponse is obtained from the DRM service. Apply for memory based on the actual length.
let offlineReleaseResponse = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.processOfflineReleaseResponse(mediaKeyId, offlineReleaseResponse).then(() => {
  console.log('processOfflineReleaseResponse');
}).catch((err: BusinessError) => {
  console.error(`processOfflineReleaseResponse: ERROR: ${err}`);
});
```

### restoreOfflineMediaKeys

restoreOfflineMediaKeys(mediaKeyId: Uint8Array): Promise<void\>

Restores offline media keys.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mediaKeyId  | Uint8Array     | Yes  | Array holding the IDs of offline media keys.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Promise<void\>          | Promise                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
// mediaKeyId is the return value of processMediaKeyResponse or getOfflineMediaKeyIds. Pass in the actual data returned.
let mediaKeyId = new Uint8Array([0x00, 0x00, 0x00, 0x00]);
mediaKeySession.restoreOfflineMediaKeys(mediaKeyId).then(() => {
  console.log("restoreOfflineMediaKeys");
}).catch((err: BusinessError) => {
  console.error(`restoreOfflineMediaKeys: ERROR: ${err}`);
});
```

### getContentProtectionLevel

getContentProtectionLevel(): ContentProtectionLevel

Obtains the content protection level of this media key session.

**Atomic service API**: This API can be used in atomic services since API version 12.

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
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
try {
  let contentProtectionLevel: drm.ContentProtectionLevel = mediaKeySession.getContentProtectionLevel();
} catch (err) {
  let error = err as BusinessError;
  console.error(`getContentProtectionLevel ERROR: ${error}`);
}
```

### requireSecureDecoderModule

requireSecureDecoderModule(mimeType: string): boolean

Checks whether secure decoding is required.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| mimeType  | string     | Yes  | MIME type, which is determined by the DRM solution.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Whether secure decoding is required. The value **true** means that secure decoding is required, and **false** means the opposite.                  |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
try {
  let status: boolean = mediaKeySession.requireSecureDecoderModule("video/avc");
} catch (err) {
  let error = err as BusinessError;
  console.error(`requireSecureDecoderModule ERROR: ${error}`);
} 
```

### on('keyRequired')

on(type: 'keyRequired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that the application requests a media key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyRequired'**. This event is triggered when the application requires a media key.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.         |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('keyRequired', (eventInfo: drm.EventInfo) => {
  console.log('keyRequired ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

### off('keyRequired')

off(type: 'keyRequired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that the application requests a media key.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyRequired'**.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used to return the event information.                 |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('keyRequired');
```

### on('keyExpired')

on(type: 'keyExpired', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that a media key expires.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyExpired'**. This event is triggered when a media key expires.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.          |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('keyExpired', (eventInfo: drm.EventInfo) => {
  console.log('keyExpired ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

### off('keyExpired')

off(type: 'keyExpired', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that a media key expires.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keyExpired'**.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used to return the event information.                 |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('keyExpired');
```

### on('vendorDefined')

on(type: 'vendorDefined', callback: (eventInfo: EventInfo) => void): void

Subscribes to vendor-defined events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'vendorDefined'**. This event is triggered when a vendor-defined event occurs.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.              |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('vendorDefined', (eventInfo: drm.EventInfo) => {
  console.log('vendorDefined ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

### off('vendorDefined')

off(type: 'vendorDefined', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from vendor-defined events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'vendorDefined'**.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used to return the event information.                 |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.      |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('vendorDefined');
```

### on('expirationUpdate')

on(type: 'expirationUpdate', callback: (eventInfo: EventInfo) => void): void

Subscribes to events indicating that a media key updates on expiry.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'expirationUpdate'**. This event is triggered when a media key updates on expiry.|
| callback | Callback\<[EventInfo](#eventinfo)\> | Yes  | Callback used to return the event information.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.        |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('expirationUpdate', (eventInfo: drm.EventInfo) => {
  console.log('expirationUpdate ' + 'extra: ' + eventInfo.extraInfo + 'data: ' + eventInfo.info);
});
```

### off('expirationUpdate')

off(type: 'expirationUpdate', callback?: (eventInfo: EventInfo) => void): void

Unsubscribes from events indicating that a media key updates on expiry. 

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'expirationUpdate'**.|
| callback | Callback\<[EventInfo](#eventinfo)\> | No  | Callback used to return the event information.                 |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.       |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('expirationUpdate');
```

### on('keysChange')

on(type: 'keysChange', callback: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

Subscribes to events indicating that a media key changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keysChange'**. This event is triggered when a media key changes.|
| callback | Callback\<[KeysInfo[]](#keysinfo), boolean\> | Yes  | Callback used to return the event information, including the lists of key IDs, statuses, and availability.                |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.             |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.on('keysChange', (keyInfo: drm.KeysInfo[], newKeyAvailable: boolean) => {
  for (let i = 0; i < keyInfo.length; i++) {
    console.log('keysChange' + 'keyId:' + keyInfo[i].keyId + ' data:' + keyInfo[i].value);
  }
});
```

### off('keysChange')

off(type: 'keysChange', callback?: (keyInfo: KeysInfo[], newKeyAvailable: boolean) => void): void

Unsubscribes from events indicating that a media key changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'keysChange'**.|
| callback | Callback\<[KeysInfo[]](#keysinfo), boolean\> | No  | Callback used to return the event information, including the lists of key IDs, statuses, and availability.               |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified or too many parameters. 2.Incorrect parameter types. 3.Parameter verification failed.            |
| 24700101                |  All unknown errors                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
mediaKeySession.off('keysChange');
```

### destroy

destroy(): void

Destroys this **MediaKeySession** instance.

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
import { BusinessError } from '@kit.BasicServicesKit';

let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem("com.clearplay.drm");
let mediaKeySession: drm.MediaKeySession = mediaKeySystem.createMediaKeySession();
try {
  mediaKeySession.destroy();
} catch (err) {
  let error = err as BusinessError;
  console.error(`mediaKeySession destroy ERROR: ${error}`);
}

```

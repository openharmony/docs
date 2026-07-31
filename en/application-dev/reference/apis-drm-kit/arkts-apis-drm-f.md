# Functions

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29f3919446ee01733553b9b39493ee11224dad86 translatedAt=2026-07-31T02:11:58.000Z pushedAt=2026-07-31T03:50:48.736Z -->

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { drm } from '@kit.DrmKit';
```

## drm.createMediaKeySystem

createMediaKeySystem(name: string): MediaKeySystem

Creates a MediaKeySystem instance. A maximum of 64 MediaKeySystem instances can be created. If the number of MediaKeySystem instances exceeds this limit, error code 24700103 will be reported. You are advised to call the [destroy](arkts-apis-drm-MediaKeySystem.md#destroy) API in a timely manner to release MediaKeySystem instances that are no longer used.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name. You can obtain the DRM solution name supported by the device through the [drm.getMediaKeySystems](arkts-apis-drm-f.md#drmgetmediakeysystems12) API, for example, **com.clearplay.drm**.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySystem](arkts-apis-drm-MediaKeySystem.md)           | MediaKeySystem instance.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700103                |  Meet max MediaKeySystem num limit                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';
// name indicates the DRM solution name. You can obtain the DRM solution name supported by the device through the drm.getMediaKeySystems API, for example, **com.clearplay.drm**.
let name = 'com.clearplay.drm';
let mediaKeySystem: drm.MediaKeySystem = drm.createMediaKeySystem(name);
console.info(`createMediaKeySystem success, name: ${name}`);
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string): boolean

Checks whether the device supports the specified DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name. You can obtain the DRM solution name supported by the device through the [drm.getMediaKeySystems](arkts-apis-drm-f.md#drmgetmediakeysystems12) API, for example, **com.clearplay.drm**.                    |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Whether the specified DRM solution is supported. The value **true** indicates yes, and the value **false** indicates no.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Parameter verification failed, the param name's length is zero or too big(exceeds 4096 Bytes).               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let supported: boolean = drm.isMediaKeySystemSupported('com.clearplay.drm');
console.info("isMediaKeySystemSupported: ", supported);
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string): boolean

Checks whether the device supports the specified DRM solution and MIME type.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                                                                                                         |
| -------- | ----------------------------------------------- | ---- |-------------------------------------------------------------------------------------------------------------|
| name  | string     | Yes  | DRM solution name. You can obtain the DRM solution name supported by the device through the [drm.getMediaKeySystems](arkts-apis-drm-f.md#drmgetmediakeysystems12) API, for example, **com.clearplay.drm**.|
| mimeType  | string     | Yes  | MIME type. The supported MIME types depend on the DRM solution. For example, video/avc and video/hevc.                                                              |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Whether the specified DRM solution and MIME type are supported. If both are supported, **true** is returned. Otherwise, **false** is returned.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.                |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let supported: boolean = drm.isMediaKeySystemSupported('com.clearplay.drm', 'video/avc');
console.info("isMediaKeySystemSupported: ", supported);
```

## drm.isMediaKeySystemSupported

isMediaKeySystemSupported(name: string, mimeType: string, level: ContentProtectionLevel): boolean

Checks whether the device supports the specified DRM solution, MIME type, and content protection level.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                                                                                                                           |
| -------- | ----------------------------------------------- | ---- |-------------------------------------------------------------------------------------------------------------------------------|
| name  | string     | Yes  | DRM solution name. You can obtain the DRM solution name supported by the device through the [drm.getMediaKeySystems](arkts-apis-drm-f.md#drmgetmediakeysystems12) API, for example, **com.clearplay.drm**.         |
| mimeType  | string     | Yes  | MIME type. The supported MIME types depend on the DRM solution.|
| level  | [ContentProtectionLevel](arkts-apis-drm-e.md#contentprotectionlevel)     | Yes   | Content protection level used to specify the security protection degree of DRM content. Different levels correspond to different decryption capabilities and security requirements.                                                                                                                       |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Whether the specified DRM solution, MIME type, and content protection level are supported. If all of them are supported, **true** is returned. Otherwise, **false** is returned.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.               |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let supported: boolean = drm.isMediaKeySystemSupported('com.clearplay.drm', 'video/avc', drm.ContentProtectionLevel.CONTENT_PROTECTION_LEVEL_SW_CRYPTO);
console.info("isMediaKeySystemSupported: ", supported);
```

## drm.getMediaKeySystemUuid<sup>12+</sup>

getMediaKeySystemUuid(name: string): string

Obtains the UUID of the DRM content protection system supported by the specified DRM solution.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name. You can obtain the DRM solution name supported by the device through the [drm.getMediaKeySystems](arkts-apis-drm-f.md#drmgetmediakeysystems12) API, for example, **com.clearplay.drm**.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| string  | UUID of the DRM content protection system.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 401                |  The parameter check failed. Possibly because: 1. Mandatory parameters are left unspecified. 2. Parameter verification failed.                |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let uuid: string = drm.getMediaKeySystemUuid('com.clearplay.drm');
console.info("getMediaKeySystemUuid: ", uuid);
```

## drm.getMediaKeySystems<sup>12+</sup>

getMediaKeySystems(): MediaKeySystemDescription[]

Obtains the list of plugins supported by the device.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySystemDescription](arkts-apis-drm-i.md#mediakeysystemdescription12)[]           | List of plugin information supported by the device.                   |

**Error codes**

For details about the error codes, see [DRM Error Codes](errorcode-drm.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 24700101                |  All unknown errors                  |
| 24700201                |  Fatal service error, for example, service died                  |

**Example**

```ts
import { drm } from '@kit.DrmKit';

let description: drm.MediaKeySystemDescription[] = drm.getMediaKeySystems();
// Verify the returned result. description indicates the plugin information list, including the plugin names and unique IDs.
if (description.length > 0) {
  console.info(`getMediaKeySystems success, count: ${description.length}`);
  for (let i = 0; i < description.length; i++) {
    console.info(`name: ${description[i].name}, uuid: ${description[i].uuid}`);
  }
} else {
  console.info('No DRM system available');
}
```
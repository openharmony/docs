# Functions

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { drm } from '@kit.DrmKit';
```

## drm.createMediaKeySystem

createMediaKeySystem(name: string): MediaKeySystem

Creates a MediaKeySystem instance.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| name  | string     | Yes  | DRM solution name.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [MediaKeySystem](arkts-apis-drm-MediaKeySystem.md)           | MediaKeySystem instance.                  |

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
| boolean          | Check result for the support of the DRM solution. **true** if supported, **false** otherwise.                  |

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
| boolean          | Check result for the support of the combination. **true** if supported, **false** otherwise.                  |

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
| level  | [ContentProtectionLevel](arkts-apis-drm-e.md#contentprotectionlevel)     | Yes  | Content protection level.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| boolean          | Check result for the support of the combination. **true** if supported, **false** otherwise.                  |

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
| [MediaKeySystemDescription[]](arkts-apis-drm-i.md#mediakeysystemdescription12)           | Array of the supported plugins.                  |

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

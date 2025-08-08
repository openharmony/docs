# Enums

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## DrmErrorCode

Enumerates the DRM error codes.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| ERROR_UNKNOWN       | 24700101    | Unknown error.  |
| MAX_SYSTEM_NUM_REACHED   | 24700103    | The number of MediaKeySystem instances reaches the upper limit (64).   |
| MAX_SESSION_NUM_REACHED    | 24700104    | The number of MediaKeySession instances reaches the upper limit (64).    |
| SERVICE_FATAL_ERROR  | 24700201    | DRM service error.    |

## PreDefinedConfigName

Enumerates the names of predefined configuration items.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Multimedia.Drm.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CONFIG_DEVICE_VENDOR        | 'vendor'    | Plugin vendor name, which corresponds to the value of **vendor** in the return value of [getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring).  |
| CONFIG_DEVICE_VERSION    | 'version'    | Plugin version number, which corresponds to the value of **version** in the return value of [getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring).    |
| CONFIG_DEVICE_DESCRIPTION     | 'description'    | Device descriptor, which corresponds to the value of **description** in the return value of [getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring).     |
| CONFIG_DEVICE_ALGORITHMS   | 'algorithms'    | Supported algorithm names, which correspond to the value of **algorithms** in the return value of [getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring).    |
| CONFIG_DEVICE_UNIQUE_ID    | 'deviceUniqueId'    | Unique device ID, which corresponds to the value of **deviceUniqueId** in the return value of [getConfigurationByteArray](arkts-apis-drm-MediaKeySystem.md#getconfigurationbytearray).    |
| CONFIG_SESSION_MAX         | 'maxSessionNum'    | Maximum number of sessions supported by the device, which corresponds to the value of **maxSessionNum** in the return value of [getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring).    |
| CONFIG_SESSION_CURRENT   | 'currentSessionNum'    | Number of existing sessions, which corresponds to the value of **currentSessionNum** in the return value of [getConfigurationString](arkts-apis-drm-MediaKeySystem.md#getconfigurationstring).    |

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

# native_drm_common.h

<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=29f3919446ee01733553b9b39493ee11224dad86 translatedAt=2026-07-31T02:14:07.612Z pushedAt=2026-07-31T03:50:28.692Z -->

## Overview

The file declares the DRM data types.

**File to include**: <multimedia/drm_framework/native_drm_common.h>

**Library**: libnative_drm.so

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](capi-drm.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DRM_MediaKeyRequestInfo](capi-drm-drm-mediakeyrequestinfo.md) | DRM_MediaKeyRequestInfo | Describes the information about a media key request.|
| [DRM_MediaKeyRequest](capi-drm-drm-mediakeyrequest.md) | DRM_MediaKeyRequest | Describes the media key request.|
| [DRM_Statistics](capi-drm-drm-statistics.md) | DRM_Statistics | Describes the metrics for a media key system.|
| [DRM_OfflineMediakeyIdArray](capi-drm-drm-offlinemediakeyidarray.md) | DRM_OfflineMediakeyIdArray | Describes an array of offline media key IDs.|
| [DRM_KeysInfo](capi-drm-drm-keysinfo.md) | DRM_KeysInfo | Describes the information about media keys.|
| [DRM_MediaKeyStatus](capi-drm-drm-mediakeystatus.md) | DRM_MediaKeyStatus | Describes the media key status.|
| [DRM_PsshInfo](capi-drm-drm-psshinfo.md) | DRM_PsshInfo | Describes the Protection System Specific Header (PSSH) data for a DRM system.|
| [DRM_MediaKeySystemInfo](capi-drm-drm-mediakeysysteminfo.md) | DRM_MediaKeySystemInfo | Describes the DRM information for encrypted content.|
| [DRM_MediaKeySystemDescription](capi-drm-drm-mediakeysystemdescription.md) | DRM_MediaKeySystemDescription | Describes the DRM solution name and UUID list.|
| [MediaKeySystem](capi-drm-mediakeysystem.md) | MediaKeySystem | Describes the media key system.|
| [MediaKeySession](capi-drm-mediakeysession.md) | MediaKeySession | Describes the media key session. |

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DRM_EventType](#drm_eventtype) | DRM_EventType | Enumerates the types of events that can be subscribed to.|
| [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) | DRM_ContentProtectionLevel | Enumerates the content protection levels.|
| [DRM_MediaKeyType](#drm_mediakeytype) | DRM_MediaKeyType | Enumerates the types of media keys.|
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) | DRM_MediaKeyRequestType | Enumerates the types of media key requests.|
| [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) | DRM_OfflineMediaKeyStatus | Enumerates the statuses of offline media keys.|
| [DRM_CertificateStatus](#drm_certificatestatus) | DRM_CertificateStatus | Enumerates the device certificate statuses.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#drm_mediakeysysteminfocallback) | DRM_MediaKeySystemInfoCallback | Defines the callback function used to obtain DRM information from a media source.|

### Macros

| Name| Description|
| -- | -- |
| MAX_MEDIA_KEY_REQUEST_OPTION_COUNT 16 | Maximum number of optional data entries in a media key request.<br>**Since**: 11|
| MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN 64 | Maximum length of an optional data name in a media key request.<br>**Since**: 11|
| MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN 128 | Maximum length of optional data in a media key request.<br>**Since**: 11|
| MAX_INIT_DATA_LEN 2048 | Maximum length of initialization data for a media key request.<br>**Since**: 11|
| MAX_MIMETYPE_LEN 64 | Maximum length of a MIME type.<br>**Since**: 11|
| MAX_MEDIA_KEY_REQUEST_DATA_LEN 8192 | Maximum length of data in a media key request.<br>**Since**: 11|
| MAX_DEFAULT_URL_LEN 2048 | Maximum length of a URL.<br>**Since**: 11|
| MAX_STATISTICS_COUNT 10 | Maximum number of metric records.<br>**Since**: 11|
| MAX_STATISTICS_NAME_LEN 64 | Maximum length of a metric name.<br>**Since**: 11|
| MAX_STATISTICS_BUFFER_LEN 256 | Maximum length of a metric buffer.<br>**Since**: 11|
| MAX_OFFLINE_MEDIA_KEY_ID_COUNT 512 | Maximum number of offline media key IDs.<br>**Since**: 11|
| MAX_OFFLINE_MEDIA_KEY_ID_LEN 64 | Maximum length of an offline media key ID.<br>**Since**: 11|
| MAX_KEY_INFO_COUNT 64 | Maximum number of key information entries.<br>**Since**: 11|
| MAX_KEY_ID_LEN 16 | Maximum length of a key ID.<br>**Since**: 11|
| MAX_KEY_STATUS_VALUE_LEN 128 | Maximum length of a key status value.<br>**Since**: 11|
| MAX_MEDIA_KEY_STATUS_COUNT 64 | Maximum number of media key statuses.<br>**Since**: 11|
| MAX_MEDIA_KEY_STATUS_NAME_LEN 64 | Maximum length of a media key status name.<br>**Since**: 11|
| MAX_MEDIA_KEY_STATUS_VALUE_LEN 256 | Maximum length of a media key status value.<br>**Since**: 11|
| DRM_UUID_LEN 16 | Length of the UUID of a DRM solution.<br>**Since**: 11|
| MAX_PSSH_DATA_LEN 2048 | Maximum length of Protection System Specific Header (PSSH) information.<br>**Since:** 11 |
| MAX_PSSH_INFO_COUNT 8 | Maximum number of PSSH information entries.<br>**Since:** 11 |
| MAX_MEDIA_KEY_SYSTEM_NAME_LEN 128 | Maximum length of a MediaKeySystem instance name.<br>**Since**: 12|
| MAX_MEDIA_KEY_SYSTEM_NUM 8 | Maximum number of MediaKeySystem instances.<br>**Since**: 12|

## Enum Description

### DRM_EventType

```c
enum DRM_EventType
```

**Description**

Enumerates the types of events that can be subscribed to.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item| Description|
| -- | -- |
| EVENT_DRM_BASE = 200 | DRM event.|
| EVENT_PROVISION_REQUIRED = 201 | Event indicating that the application needs to request a device certificate.|
| EVENT_KEY_REQUIRED = 202 | Event indicating that the application needs to request a media key.|
| EVENT_KEY_EXPIRED = 203 | Event indicating that the media key expires.|
| EVENT_VENDOR_DEFINED = 204 | Vendor-defined event.|
| EVENT_EXPIRATION_UPDATE = 206 | Event indicating that the media key is updated on expiry.|

### DRM_ContentProtectionLevel

```c
enum DRM_ContentProtectionLevel
```

**Description**

Enumerates the content protection levels.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item| Description|
| -- | -- |
| CONTENT_PROTECTION_LEVEL_UNKNOWN = 0 | Unknown level.|
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO | Software-based content protection.|
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO | Hardware-based content protection.|
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO | Enhanced hardware-based content protection.|
| CONTENT_PROTECTION_LEVEL_MAX | Maximum content protection level.|

### DRM_MediaKeyType

```c
enum DRM_MediaKeyType
```

**Description**

Enumerates the types of media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item| Description|
| -- | -- |
| MEDIA_KEY_TYPE_OFFLINE = 0 | Offline media key.|
| MEDIA_KEY_TYPE_ONLINE | Online media key.|

### DRM_MediaKeyRequestType

```c
enum DRM_MediaKeyRequestType
```

**Description**

Enumerates the types of media key requests.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item| Description|
| -- | -- |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0 | Unknown type.|
| MEDIA_KEY_REQUEST_TYPE_INITIAL | Initialization request.|
| MEDIA_KEY_REQUEST_TYPE_RENEWAL | Renewal request.|
| MEDIA_KEY_REQUEST_TYPE_RELEASE | Release request.|
| MEDIA_KEY_REQUEST_TYPE_NONE | No request.|
| MEDIA_KEY_REQUEST_TYPE_UPDATE | Update request.|

### DRM_OfflineMediaKeyStatus

```c
enum DRM_OfflineMediaKeyStatus
```

**Description**

Enumerates the statuses of offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item| Description|
| -- | -- |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0 | Unknown status.|
| OFFLINE_MEDIA_KEY_STATUS_USABLE | The media key is available.|
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE | The media key is inactive.|

### DRM_CertificateStatus

```c
enum DRM_CertificateStatus
```

**Description**

Enumerates the device certificate statuses.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Enum Item | Description |
| -- | -- |
| CERT_STATUS_PROVISIONED = 0 | A device certificate is provisioned.|
| CERT_STATUS_NOT_PROVISIONED | No device certificate is provisioned or the certificate status is abnormal.|
| CERT_STATUS_EXPIRED | The device certificate has expired.|
| CERT_STATUS_INVALID | The device certificate is invalid.|
| CERT_STATUS_UNAVAILABLE | The device certificate is unavailable.|

## Function Description

### DRM_MediaKeySystemInfoCallback()

```c
typedef void (*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Defines the callback function used to obtain DRM information from a media source.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [DRM_MediaKeySystemInfo](capi-drm-drm-mediakeysysteminfo.md) *mediaKeySystemInfo | Pointer to the DRM information obtained from the media source, including the unique identifier of the DRM system and PSSH data.|
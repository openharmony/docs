# native_drm_common.h


## Overview

The **native_drm_common.h** file declares the DRM data types.

**Library**: libnative_drm.so

**File to include**: &lt;multimedia/drm_framework/native_drm_common.h&gt;

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) | Describes the information about a media key request.| 
| struct  [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) | Describes a media key request.| 
| struct  [DRM_Statistics](_d_r_m___statistics.md) | Describes the statistical information of a media key system.| 
| struct  [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) | Describes an array holding the IDs of offline media keys.| 
| struct  [DRM_KeysInfo](_d_r_m___keys_info.md) | Describes the information about media keys.| 
| struct  [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) | Describes the media key status.| 
| struct  [DRM_PsshInfo](_d_r_m___pssh_info.md) | Describes the Protection System Specific Header (PSSH) data in DRM information.| 
| struct  [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) | Describes the DRM information, which is used to encrypt content.| 
| struct  [DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) | Describes the DRM solution name and UUID list. | 


### Macros

| Name| Description| 
| -------- | -------- |
| [MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](_drm.md#max_media_key_request_option_count)&nbsp;&nbsp;&nbsp;16 | Maximum number of optional data items in a media key request.| 
| [MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](_drm.md#max_media_key_request_option_name_len)&nbsp;&nbsp;&nbsp;64 | Maximum length of an optional data name in a media key request.| 
| [MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](_drm.md#max_media_key_request_option_data_len)&nbsp;&nbsp;&nbsp;128 | Maximum length of optional data in a media key request.| 
| [MAX_INIT_DATA_LEN](_drm.md#max_init_data_len)&nbsp;&nbsp;&nbsp;2048 | Maximum length of data in an initial request.| 
| [MAX_MIMETYPE_LEN](_drm.md#max_mimetype_len)&nbsp;&nbsp;&nbsp;64 | Maximum length of a MIME type.| 
| [MAX_MEDIA_KEY_REQUEST_DATA_LEN](_drm.md#max_media_key_request_data_len)&nbsp;&nbsp;&nbsp;8192 | Maximum length of data in a media key request.| 
| [MAX_DEFAULT_URL_LEN](_drm.md#max_default_url_len)&nbsp;&nbsp;&nbsp;2048 | Maximum length of a URL.| 
| [MAX_STATISTICS_COUNT](_drm.md#max_statistics_count)&nbsp;&nbsp;&nbsp;10 | Maximum number of statistical items.| 
| [MAX_STATISTICS_NAME_LEN](_drm.md#max_statistics_name_len)&nbsp;&nbsp;&nbsp;64 | Maximum length of a statistical item name.| 
| [MAX_STATISTICS_BUFFER_LEN](_drm.md#max_statistics_buffer_len)&nbsp;&nbsp;&nbsp;256 | Maximum length of a statistical item buffer.| 
| [MAX_OFFLINE_MEDIA_KEY_ID_COUNT](_drm.md#max_offline_media_key_id_count)&nbsp;&nbsp;&nbsp;512 | Maximum number of offline media key IDs.| 
| [MAX_OFFLINE_MEDIA_KEY_ID_LEN](_drm.md#max_offline_media_key_id_len)&nbsp;&nbsp;&nbsp;64 | Maximum length of an offline media key ID.| 
| [MAX_KEY_INFO_COUNT](_drm.md#max_key_info_count)&nbsp;&nbsp;&nbsp;64 | Maximum number of pieces of media key information.| 
| [MAX_KEY_ID_LEN](_drm.md#max_key_id_len)&nbsp;&nbsp;&nbsp;16 | Maximum length of a media key ID.| 
| [MAX_KEY_STATUS_VALUE_LEN](_drm.md#max_key_status_value_len)&nbsp;&nbsp;&nbsp;128 | Maximum length of a key status value.| 
| [MAX_MEDIA_KEY_STATUS_COUNT](_drm.md#max_media_key_status_count)&nbsp;&nbsp;&nbsp;64 | Maximum number of media key statuses.| 
| [MAX_MEDIA_KEY_STATUS_NAME_LEN](_drm.md#max_media_key_status_name_len)&nbsp;&nbsp;&nbsp;64 | Maximum length of a media key status name.| 
| [MAX_MEDIA_KEY_STATUS_VALUE_LEN](_drm.md#max_media_key_status_value_len)&nbsp;&nbsp;&nbsp;256 | Maximum length of a media key status value.| 
| [DRM_UUID_LEN](_drm.md#drm_uuid_len)&nbsp;&nbsp;&nbsp;16 | Length of the UUID of a DRM solution.| 
| [MAX_PSSH_DATA_LEN](_drm.md#max_pssh_data_len)&nbsp;&nbsp;&nbsp;2048 | Maximum length of PSSH data.| 
| [MAX_PSSH_INFO_COUNT](_drm.md#max_pssh_info_count)&nbsp;&nbsp;&nbsp;8 | Maximum number of pieces of PSSH data.| 
| [MAX_MEDIA_KEY_SYSTEM_NAME_LEN](_drm.md#max_media_key_system_name_len)&nbsp;&nbsp;&nbsp;128 | Maximum length of a **MediaKeySystem** instance name. | 
| [MAX_MEDIA_KEY_SYSTEM_NUM](_drm.md#max_media_key_system_num)&nbsp;&nbsp;&nbsp;8 | Maximum number of **MediaKeySystem** instances. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [DRM_EventType](_drm.md#drm_eventtype-1) [DRM_EventType](_drm.md#drm_eventtype) | Defines an enum for the types of events that can be subscribed to.| 
| typedef enum [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel-1) [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) | Defines an enum for the content protection levels.| 
| typedef enum [DRM_MediaKeyType](_drm.md#drm_mediakeytype-1) [DRM_MediaKeyType](#drm_mediakeytype) | Defines an enum for the types of media keys.| 
| typedef enum [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype-1) [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) | Defines an enum for the types of media key requests.| 
| typedef enum [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus-1) [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) | Defines an enum for the statuses of offline media keys.| 
| typedef enum [DRM_CertificateStatus](_drm.md#drm_certificatestatus-1) [DRM_CertificateStatus](#drm_certificatestatus) | Defines an enum for the DRM certificate statuses.| 
| typedef struct [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) [DRM_MediaKeyRequestInfo](_drm.md#drm_mediakeyrequestinfo) | Defines a struct for the information about a media key request.| 
| typedef struct [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) [DRM_MediaKeyRequest](_drm.md#drm_mediakeyrequest) | Defines a struct for a media key request.| 
| typedef struct [DRM_Statistics](_d_r_m___statistics.md) [DRM_Statistics](_drm.md#drm_statistics) | Defines a struct for the statistical information of a media key system.| 
| typedef struct [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) [DRM_OfflineMediakeyIdArray](_drm.md#drm_offlinemediakeyidarray) | Defines a struct for the array holding the IDs of offline media keys.| 
| typedef struct [DRM_KeysInfo](_d_r_m___keys_info.md) [DRM_KeysInfo](_drm.md#drm_keysinfo) | Defines a struct for the information about media keys.| 
| typedef struct [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) [DRM_MediaKeyStatus](_drm.md#drm_mediakeystatus) | Defines a struct for the media key status.| 
| typedef struct [DRM_PsshInfo](_d_r_m___pssh_info.md) [DRM_PsshInfo](_drm.md#drm_psshinfo) | Defines a struct for PSSH data in DRM information.| 
| typedef struct [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) [DRM_MediaKeySystemInfo](_drm.md#drm_mediakeysysteminfo) | Defines a struct for the DRM information, which is used to encrypt content.| 
| typedef struct [DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) [DRM_MediaKeySystemDescription](_drm.md#drm_mediakeysystemdescription) | Defines a struct for the DRM solution name and UUID list. | 
| typedef void(\* [DRM_MediaKeySystemInfoCallback](_drm.md#drm_mediakeysysteminfocallback)) ([DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | Defines a callback for media key system information.| 
| typedef struct [MediaKeySystem](_drm.md#mediakeysystem) [MediaKeySystem](_drm.md#mediakeysystem) | Defines a struct for a media key system.| 
| typedef struct [MediaKeySession](_drm.md#mediakeysession) [MediaKeySession](_drm.md#mediakeysession) | Defines a struct for a media key session.| 

### Enums

| Name| Description| 
| -------- | -------- |
| [DRM_EventType](_drm.md#drm_eventtype-1) {<br>EVENT_DRM_BASE = 200, <br>EVENT_PROVISION_REQUIRED = 201, <br>EVENT_KEY_REQUIRED = 202, <br>EVENT_KEY_EXPIRED = 203,<br>EVENT_VENDOR_DEFINED = 204, <br>EVENT_EXPIRATION_UPDATE = 206<br>} | Enumerates the event types.| 
| [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel-1) {<br>CONTENT_PROTECTION_LEVEL_UNKNOWN = 0, <br>CONTENT_PROTECTION_LEVEL_SW_CRYPTO, <br>CONTENT_PROTECTION_LEVEL_HW_CRYPTO, <br>CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO,<br>CONTENT_PROTECTION_LEVEL_MAX<br>} | Enumerates the content protection levels.| 
| [DRM_MediaKeyType](_drm.md#drm_mediakeytype-1) { <br>MEDIA_KEY_TYPE_OFFLINE = 0, <br>MEDIA_KEY_TYPE_ONLINE <br>} | Enumerates the types of media keys.| 
| [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype-1) {<br>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0, <br>MEDIA_KEY_REQUEST_TYPE_INITIAL, <br>MEDIA_KEY_REQUEST_TYPE_RENEWAL, <br>MEDIA_KEY_REQUEST_TYPE_RELEASE,<br>MEDIA_KEY_REQUEST_TYPE_NONE, <br>MEDIA_KEY_REQUEST_TYPE_UPDATE<br>} | Enumerates the types of media key requests.| 
| [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus-1) { <br>OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0, <br>OFFLINE_MEDIA_KEY_STATUS_USABLE, <br>OFFLINE_MEDIA_KEY_STATUS_INACTIVE } | Enumerates the statuses of offline media keys.| 
| [DRM_CertificateStatus](_drm.md#drm_certificatestatus-1) {<br>CERT_STATUS_PROVISIONED = 0, <br>CERT_STATUS_NOT_PROVISIONED, <br>CERT_STATUS_EXPIRED, <br>CERT_STATUS_INVALID,<br>CERT_STATUS_UNAVAILABLE<br>} | Enumerates the DRM certificate statuses.| 

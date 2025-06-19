# native_drm_common.h


## 概述

定义DRM数据类型。

**库：** libnative_drm.so

**引用文件：** &lt;multimedia/drm_framework/native_drm_common.h&gt;

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) | 媒体密钥请求信息。 | 
| struct  [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) | 媒体密钥请求。 | 
| struct  [DRM_Statistics](_d_r_m___statistics.md) | MediaKeySystem的度量信息。 | 
| struct  [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) | 离线媒体密钥标识列表。 | 
| struct  [DRM_KeysInfo](_d_r_m___keys_info.md) | 媒体密钥信息。 | 
| struct  [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) | 媒体密钥状态。 | 
| struct  [DRM_PsshInfo](_d_r_m___pssh_info.md) | DRM内容保护系统专用头（Protection System Specific Header）信息。 | 
| struct  [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) | 加密媒体内容的DRM信息。 | 
| struct  [DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) | DRM解决方案名称及其UUID的列表。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](_drm.md#max_media_key_request_option_count)&nbsp;&nbsp;&nbsp;16 | 媒体密钥请求可选数据的最大数量。 | 
| [MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](_drm.md#max_media_key_request_option_name_len)&nbsp;&nbsp;&nbsp;64 | 媒体密钥请求可选数据名称的最大长度。 | 
| [MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](_drm.md#max_media_key_request_option_data_len)&nbsp;&nbsp;&nbsp;128 | 媒体密钥请求可选数据的最大长度。 | 
| [MAX_INIT_DATA_LEN](_drm.md#max_init_data_len)&nbsp;&nbsp;&nbsp;2048 | 媒体密钥请求初始化数据的最大长度。 | 
| [MAX_MIMETYPE_LEN](_drm.md#max_mimetype_len)&nbsp;&nbsp;&nbsp;64 | 媒体mimetype的最大长度。 | 
| [MAX_MEDIA_KEY_REQUEST_DATA_LEN](_drm.md#max_media_key_request_data_len)&nbsp;&nbsp;&nbsp;8192 | 媒体密钥请求数据的最大长度。 | 
| [MAX_DEFAULT_URL_LEN](_drm.md#max_default_url_len)&nbsp;&nbsp;&nbsp;2048 | URL最大长度。 | 
| [MAX_STATISTICS_COUNT](_drm.md#max_statistics_count)&nbsp;&nbsp;&nbsp;10 | 度量记录的最大数量。 | 
| [MAX_STATISTICS_NAME_LEN](_drm.md#max_statistics_name_len)&nbsp;&nbsp;&nbsp;64 | 度量记录名称的最大长度。 | 
| [MAX_STATISTICS_BUFFER_LEN](_drm.md#max_statistics_buffer_len)&nbsp;&nbsp;&nbsp;256 | 度量记录缓冲区的最大长度。 | 
| [MAX_OFFLINE_MEDIA_KEY_ID_COUNT](_drm.md#max_offline_media_key_id_count)&nbsp;&nbsp;&nbsp;512 | 离线媒体密钥标识的最大数量。 | 
| [MAX_OFFLINE_MEDIA_KEY_ID_LEN](_drm.md#max_offline_media_key_id_len)&nbsp;&nbsp;&nbsp;64 | 离线媒体密钥标识的最大长度。 | 
| [MAX_KEY_INFO_COUNT](_drm.md#max_key_info_count)&nbsp;&nbsp;&nbsp;64 | 密钥信息的最大数量。 | 
| [MAX_KEY_ID_LEN](_drm.md#max_key_id_len)&nbsp;&nbsp;&nbsp;16 | 密钥标识的最大长度。 | 
| [MAX_KEY_STATUS_VALUE_LEN](_drm.md#max_key_status_value_len)&nbsp;&nbsp;&nbsp;128 | 密钥状态值的最大长度。 | 
| [MAX_MEDIA_KEY_STATUS_COUNT](_drm.md#max_media_key_status_count)&nbsp;&nbsp;&nbsp;64 | 媒体密钥状态的最大数量。 | 
| [MAX_MEDIA_KEY_STATUS_NAME_LEN](_drm.md#max_media_key_status_name_len)&nbsp;&nbsp;&nbsp;64 | 媒体密钥状态名称的最大长度。 | 
| [MAX_MEDIA_KEY_STATUS_VALUE_LEN](_drm.md#max_media_key_status_value_len)&nbsp;&nbsp;&nbsp;256 | 媒体密钥状态值的最大长度。 | 
| [DRM_UUID_LEN](_drm.md#drm_uuid_len)&nbsp;&nbsp;&nbsp;16 | DRM解决方案的UUID长度。 | 
| [MAX_PSSH_DATA_LEN](_drm.md#max_pssh_data_len)&nbsp;&nbsp;&nbsp;2048 | PSSH数据的最大长度。 | 
| [MAX_PSSH_INFO_COUNT](_drm.md#max_pssh_info_count)&nbsp;&nbsp;&nbsp;8 | PSSH信息的最大数量。 | 
| [MAX_MEDIA_KEY_SYSTEM_NAME_LEN](_drm.md#max_media_key_system_name_len)&nbsp;&nbsp;&nbsp;128 | MediaKeySystem名称的最大长度。  | 
| [MAX_MEDIA_KEY_SYSTEM_NUM](_drm.md#max_media_key_system_num)&nbsp;&nbsp;&nbsp;8 | MediaKeySystem的最大数量。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [DRM_EventType](_drm.md#drm_eventtype-1) [DRM_EventType](_drm.md#drm_eventtype) | 监听事件类型。 | 
| typedef enum [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel-1) [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel-1) | 内容保护级别。 | 
| typedef enum [DRM_MediaKeyType](_drm.md#drm_mediakeytype-1) [DRM_MediaKeyType](_drm.md#drm_mediakeytype-1) | 媒体密钥类型。 | 
| typedef enum [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype-1) [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype-1) | 媒体密钥请求类型。 | 
| typedef enum [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus-1) [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus-1) | 离线媒体密钥状态。 | 
| typedef enum [DRM_CertificateStatus](_drm.md#drm_certificatestatus-1) [DRM_CertificateStatus](_drm.md#drm_certificatestatus-1) | 设备DRM证书状态。 | 
| typedef struct [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) [DRM_MediaKeyRequestInfo](_drm.md#drm_mediakeyrequestinfo) | 媒体密钥请求信息。 | 
| typedef struct [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) [DRM_MediaKeyRequest](_drm.md#drm_mediakeyrequest) | 媒体密钥请求。 | 
| typedef struct [DRM_Statistics](_d_r_m___statistics.md) [DRM_Statistics](_drm.md#drm_statistics) | MediaKeySystem的度量记录。 | 
| typedef struct [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) [DRM_OfflineMediakeyIdArray](_drm.md#drm_offlinemediakeyidarray) | 离线媒体密钥标识列表。 | 
| typedef struct [DRM_KeysInfo](_d_r_m___keys_info.md) [DRM_KeysInfo](_drm.md#drm_keysinfo) | 媒体密钥信息。 | 
| typedef struct [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) [DRM_MediaKeyStatus](_drm.md#drm_mediakeystatus) | 媒体密钥状态。 | 
| typedef struct [DRM_PsshInfo](_d_r_m___pssh_info.md) [DRM_PsshInfo](_drm.md#drm_psshinfo) | DRM内容保护系统专用头（Protection System Specific Header）信息。| 
| typedef struct [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) [DRM_MediaKeySystemInfo](_drm.md#drm_mediakeysysteminfo) | 加密媒体内容的DRM信息。 | 
| typedef struct [DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) [DRM_MediaKeySystemDescription](_drm.md#drm_mediakeysystemdescription) | DRM解决方案名称及其UUID的列表。  | 
| typedef void(\* [DRM_MediaKeySystemInfoCallback](_drm.md#drm_mediakeysysteminfocallback)) ([DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | MediakeySystem信息的回调函数。 | 
| typedef struct [MediaKeySystem](_drm.md#mediakeysystem) [MediaKeySystem](_drm.md#mediakeysystem) | MediaKeySystem结构。 | 
| typedef struct [MediaKeySession](_drm.md#mediakeysession) [MediaKeySession](_drm.md#mediakeysession) | MediaKeySession结构。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_EventType](_drm.md#drm_eventtype-1) {<br/>EVENT_DRM_BASE = 200, <br/>EVENT_PROVISION_REQUIRED = 201, <br/>EVENT_KEY_REQUIRED = 202, <br/>EVENT_KEY_EXPIRED = 203,<br/>EVENT_VENDOR_DEFINED = 204, <br/>EVENT_EXPIRATION_UPDATE = 206<br/>} | 事件类型。 | 
| [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel-1) {<br/>CONTENT_PROTECTION_LEVEL_UNKNOWN = 0, <br/>CONTENT_PROTECTION_LEVEL_SW_CRYPTO, <br/>CONTENT_PROTECTION_LEVEL_HW_CRYPTO, <br/>CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_MAX<br/>} | 内容保护级别。 | 
| [DRM_MediaKeyType](_drm.md#drm_mediakeytype-1) { <br/>MEDIA_KEY_TYPE_OFFLINE = 0, <br/>MEDIA_KEY_TYPE_ONLINE <br/>} | 媒体密钥类型。 | 
| [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype-1) {<br/>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0, <br/>MEDIA_KEY_REQUEST_TYPE_INITIAL, <br/>MEDIA_KEY_REQUEST_TYPE_RENEWAL, <br/>MEDIA_KEY_REQUEST_TYPE_RELEASE,<br/>MEDIA_KEY_REQUEST_TYPE_NONE, <br/>MEDIA_KEY_REQUEST_TYPE_UPDATE<br/>} | 媒体密钥请求类型。 | 
| [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus-1) { <br/>OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0, <br/>OFFLINE_MEDIA_KEY_STATUS_USABLE, <br/>OFFLINE_MEDIA_KEY_STATUS_INACTIVE } | 离线媒体密钥状态。 | 
| [DRM_CertificateStatus](_drm.md#drm_certificatestatus-1) {<br/>CERT_STATUS_PROVISIONED = 0, <br/>CERT_STATUS_NOT_PROVISIONED, <br/>CERT_STATUS_EXPIRED, <br/>CERT_STATUS_INVALID,<br/>CERT_STATUS_UNAVAILABLE<br/>} | 设备DRM证书状态。 | 
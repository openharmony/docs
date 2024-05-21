# native_drm_common.h


## 概述

定义DRM数据类型。

**库：** libnative_drm.z.so

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) | 媒体密钥请求信息。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeyRequest](_d_r_m___media_key_request.md) | 媒体密钥请求。 | 
| struct&nbsp;&nbsp;[DRM_Statistics](_d_r_m___statistics.md) | MediaKeySystem的度量信息。 | 
| struct&nbsp;&nbsp;[DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) | 离线媒体密钥ID数组。 | 
| struct&nbsp;&nbsp;[DRM_KeysInfo](_d_r_m___keys_info.md) | 媒体密钥信息。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeyStatus](_d_r_m___media_key_status.md) | 媒体密钥状态。 | 
| struct&nbsp;&nbsp;[DRM_PsshInfo](_d_r_m___pssh_info.md) | uuid的PSSH信息。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) | 播放器从媒体源获取媒体密钥系统信息。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) | DRM插件的名称和UUID。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](_drm.md#max_media_key_request_option_count)&nbsp;&nbsp;&nbsp;16 | 媒体密钥请求选项的最大计数。 | 
| [MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](_drm.md#max_media_key_request_option_name_len)&nbsp;&nbsp;&nbsp;64 | 媒体密钥请求选项名称的最大长度。 | 
| [MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](_drm.md#max_media_key_request_option_data_len)&nbsp;&nbsp;&nbsp;128 | 媒体密钥请求选项数据的最大长度。 | 
| [MAX_INIT_DATA_LEN](_drm.md#max_init_data_len)&nbsp;&nbsp;&nbsp;2048 | 媒体密钥请求初始化数据的最大长度。 | 
| [MAX_MIMETYPE_LEN](_drm.md#max_mimetype_len)&nbsp;&nbsp;&nbsp;64 | 媒体mimetype类型的最大长度。 | 
| [MAX_MEDIA_KEY_REQUEST_DATA_LEN](_drm.md#max_media_key_request_data_len)&nbsp;&nbsp;&nbsp;8192 | 媒体密钥请求的最大长度。 | 
| [MAX_DEFAULT_URL_LEN](_drm.md#max_default_url_len)&nbsp;&nbsp;&nbsp;2048 | URL最大长度。 | 
| [MAX_STATISTICS_COUNT](_drm.md#max_statistics_count)&nbsp;&nbsp;&nbsp;10 | 统计项的最大计数。 | 
| [MAX_STATISTICS_NAME_LEN](_drm.md#max_statistics_name_len)&nbsp;&nbsp;&nbsp;64 | 统计项名称的最大长度。 | 
| [MAX_STATISTICS_BUFFER_LEN](_drm.md#max_statistics_buffer_len)&nbsp;&nbsp;&nbsp;256 | 统计项缓冲区的最大长度。 | 
| [MAX_OFFLINE_MEDIA_KEY_ID_COUNT](_drm.md#max_offline_media_key_id_count)&nbsp;&nbsp;&nbsp;512 | 离线媒体密钥id的最大计数。 | 
| [MAX_OFFLINE_MEDIA_KEY_ID_LEN](_drm.md#max_offline_media_key_id_len)&nbsp;&nbsp;&nbsp;64 | 离线媒体密钥id的最大长度。 | 
| [MAX_KEY_INFO_COUNT](_drm.md#max_key_info_count)&nbsp;&nbsp;&nbsp;64 | 密钥信息的最大计数。 | 
| [MAX_KEY_ID_LEN](_drm.md#max_key_id_len)&nbsp;&nbsp;&nbsp;16 | 密钥id的最大长度。 | 
| [MAX_KEY_STATUS_VALUE_LEN](_drm.md#max_key_status_value_len)&nbsp;&nbsp;&nbsp;128 | 密钥状态值的最大长度。 | 
| [MAX_MEDIA_KEY_STATUS_COUNT](_drm.md#max_media_key_status_count)&nbsp;&nbsp;&nbsp;64 | 媒体密钥状态的最大计数。 | 
| [MAX_MEDIA_KEY_STATUS_NAME_LEN](_drm.md#max_media_key_status_name_len)&nbsp;&nbsp;&nbsp;64 | 媒体密钥状态名称的最大长度。 | 
| [MAX_MEDIA_KEY_STATUS_VALUE_LEN](_drm.md#max_media_key_status_value_len)&nbsp;&nbsp;&nbsp;256 | 媒体密钥状态值的最大长度。 | 
| [DRM_UUID_LEN](_drm.md#drm_uuid_len)&nbsp;&nbsp;&nbsp;16 | Drm系统 uuid长度。 | 
| [MAX_PSSH_DATA_LEN](_drm.md#max_pssh_data_len)&nbsp;&nbsp;&nbsp;2048 | PSSH数据的最大长度。 | 
| [MAX_PSSH_INFO_COUNT](_drm.md#max_pssh_info_count)&nbsp;&nbsp;&nbsp;8 | PSSH信息的最大计数。 | 
| [MAX_MEDIA_KEY_SYSTEM_NAME_LEN](_drm.md#max_media_key_system_name_len)&nbsp;&nbsp;&nbsp;128 | 媒体密钥系统名称的最大长度。  | 
| [MAX_MEDIA_KEY_SYSTEM_NUM](_drm.md#max_media_key_system_num)&nbsp;&nbsp;&nbsp;8 | 支持的媒体密钥系统的最大数量。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [DRM_EventType](_drm.md#drm_eventtype-1) [DRM_EventType](_drm.md#drm_eventtype) | 监听事件类型。 | 
| typedef enum [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel-1) [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) | 内容保护级别类型。 | 
| typedef enum [DRM_MediaKeyType](_drm.md#drm_mediakeytype-1) [DRM_MediaKeyType](_drm.md#drm_mediakeytype) | 许可证类型。 | 
| typedef enum [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype-1) [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype) | 许可证请求类型。 | 
| typedef enum [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus-1) [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus) | 离线许可证状态。 | 
| typedef enum [DRM_CertificateStatus](_drm.md#drm_certificatestatus-1) [DRM_CertificateStatus](_drm.md#drm_certificatestatus) | 设备证书状态类型。 | 
| typedef struct [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) [DRM_MediaKeyRequestInfo](_drm.md#drm_mediakeyrequestinfo) | 媒体密钥请求信息。 | 
| typedef struct [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) [DRM_MediaKeyRequest](_drm.md#drm_mediakeyrequest) | 媒体密钥请求。 | 
| typedef struct [DRM_Statistics](_d_r_m___statistics.md) [DRM_Statistics](_drm.md#drm_statistics) | MediaKeySystem的度量信息。 | 
| typedef struct [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) [DRM_OfflineMediakeyIdArray](_drm.md#drm_offlinemediakeyidarray) | 离线媒体密钥ID数组。 | 
| typedef struct [DRM_KeysInfo](_d_r_m___keys_info.md) [DRM_KeysInfo](_drm.md#drm_keysinfo) | 媒体密钥信息。 | 
| typedef struct [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) [DRM_MediaKeyStatus](_drm.md#drm_mediakeystatus) | 媒体密钥状态。 | 
| typedef struct [DRM_PsshInfo](_d_r_m___pssh_info.md) [DRM_PsshInfo](_drm.md#drm_psshinfo) | uuid的PSSH信息。 | 
| typedef struct [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) [DRM_MediaKeySystemInfo](_drm.md#drm_mediakeysysteminfo) | 播放器从媒体源获取媒体密钥系统信息。 | 
| typedef void(\* [DRM_MediaKeySystemInfoCallback](_drm.md#drm_mediakeysysteminfocallback)) ([DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | 应用程序为从媒体源获取媒体密钥系统信息而设置的回调。 | 
| typedef struct [MediaKeySystem](_drm.md#mediakeysystem) [MediaKeySystem](_drm.md#mediakeysystem) | 媒体密钥系统结构。 | 
| typedef struct [MediaKeySession](_drm.md#mediakeysession) [MediaKeySession](_drm.md#mediakeysession) | 媒体密钥会话结构。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_EventType](_drm.md#drm_eventtype-1) {<br/>EVENT_DRM_BASE = 200, <br/>EVENT_PROVISION_REQUIRED = 201, <br/>EVENT_KEY_REQUIRED = 202, <br/>EVENT_KEY_EXPIRED = 203,<br/>EVENT_VENDOR_DEFINED = 204, <br/>EVENT_EXPIRATION_UPDATE = 206<br/>} | 监听事件类型。 | 
| [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel-1) {<br/>CONTENT_PROTECTION_LEVEL_UNKNOWN = 0, <br/>CONTENT_PROTECTION_LEVEL_SW_CRYPTO, <br/>CONTENT_PROTECTION_LEVEL_HW_CRYPTO, <br/>CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_MAX<br/>} | 内容保护级别类型。 | 
| [DRM_MediaKeyType](_drm.md#drm_mediakeytype-1) { <br/>MEDIA_KEY_TYPE_OFFLINE = 0, <br/>MEDIA_KEY_TYPE_ONLINE <br/>} | 许可证类型。 | 
| [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype) {<br/>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0, <br/>MEDIA_KEY_REQUEST_TYPE_INITIAL, <br/>MEDIA_KEY_REQUEST_TYPE_RENEWAL, <br/>MEDIA_KEY_REQUEST_TYPE_RELEASE,<br/>MEDIA_KEY_REQUEST_TYPE_NONE, <br/>MEDIA_KEY_REQUEST_TYPE_UPDATE<br/>} | 许可证请求类型。 | 
| [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus-1) { <br/>OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0, <br/>OFFLINE_MEDIA_KEY_STATUS_USABLE, <br/>OFFLINE_MEDIA_KEY_STATUS_INACTIVE } | 离线许可证状态。 | 
| [DRM_CertificateStatus](_drm.md#drm_certificatestatus-1) {<br/>CERT_STATUS_PROVISIONED = 0, <br/>CERT_STATUS_NOT_PROVISIONED, <br/>CERT_STATUS_EXPIRED, <br/>CERT_STATUS_INVALID,<br/>CERT_STATUS_UNAVAILABLE<br/>} | 设备证书状态类型。 | 

# native_drm_common.h


## 概述

定义DRM数据类型

**库：** libnative_drm.z.so

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) | DRM uint_8 数组类型。 | 
| struct&nbsp;&nbsp;[DRM_CharBuffer](_d_r_m___char_buffer.md) | DRM 字符数组类型。 | 
| struct&nbsp;&nbsp;[DRM_CharBufferPair](_d_r_m___char_buffer_pair.md) | 字符数组类型的名值对。 | 
| struct&nbsp;&nbsp;[DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md) | 整形数组类型的名值对。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) | 许可证请求参数类型。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeyRequest](_d_r_m___media_key_request.md) | 许可证请求类型。 | 
| struct&nbsp;&nbsp;[DRM_Statistics](_d_r_m___statistics.md) | DRM度量统计信息。 | 
| struct&nbsp;&nbsp;[DRM_MediakeyIdArray](_d_r_m___mediakey_id_array.md) | 离线许可证Id数组。 | 
| struct&nbsp;&nbsp;[DRM_KeysInfo](_d_r_m___keys_info.md) | 密钥信息。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeyDescription](_d_r_m___media_key_description.md) | 在线许可证描述信息。 | 
| struct&nbsp;&nbsp;[DRM_PsshInfo](_d_r_m___pssh_info.md) | DRM Pssh信息。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) | 从媒体源获取的DRM信息。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_UUID_LEN](_drm.md#drm_uuid_len)&nbsp;&nbsp;&nbsp;16 | DRM插件类型名。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [DRM_ListenerType](_drm.md#drm_listenertype)[DRM_ListenerType](_drm.md#drm_listenertype) | 监听类型。 | 
| typedef enum [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel)[DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) | 内容保护级别类型。 | 
| typedef enum [DRM_MediaKeyType](_drm.md#drm_mediakeytype)[DRM_MediaKeyType](_drm.md#drm_mediakeytype) | 许可证类型。 | 
| typedef enum [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype)[DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype) | 许可证请求类型。 | 
| typedef enum [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus)[DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus) | 离线许可证状态。 | 
| typedef enum [DRM_CertificateStatus](_drm.md#drm_certificatestatus)[DRM_CertificateStatus](_drm.md#drm_certificatestatus) | 设备证书状态类型。 | 
| typedef enum [DRM_MediaKeyStatus](_drm.md#drm_mediakeystatus)[DRM_MediaKeyStatus](_drm.md#drm_mediakeystatus) | 在线许可证状态。 | 
| typedef struct [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md)[DRM_Uint8Buffer](_drm.md#drm_uint8buffer) | DRM uint_8 数组类型。 | 
| typedef struct [DRM_CharBuffer](_d_r_m___char_buffer.md)[DRM_CharBuffer](_drm.md#drm_charbuffer) | DRM 字符数组类型。 | 
| typedef struct [DRM_CharBufferPair](_d_r_m___char_buffer_pair.md)[DRM_CharBufferPair](_drm.md#drm_charbufferpair) | 字符数组类型的名值对。 | 
| typedef struct [DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md)[DRM_Uint8CharBufferPair](_drm.md#drm_uint8charbufferpair) | 整形数组类型的名值对。 | 
| typedef struct [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md)[DRM_MediaKeyRequestInfo](_drm.md#drm_mediakeyrequestinfo) | 许可证请求参数类型。 | 
| typedef struct [DRM_MediaKeyRequest](_d_r_m___media_key_request.md)[DRM_MediaKeyRequest](_drm.md#drm_mediakeyrequest) | 许可证请求类型。 | 
| typedef struct [DRM_Statistics](_d_r_m___statistics.md)[DRM_Statistics](_drm.md#drm_statistics) | DRM度量统计信息。 | 
| typedef struct [DRM_MediakeyIdArray](_d_r_m___mediakey_id_array.md)[DRM_MediakeyIdArray](_drm.md#drm_mediakeyidarray) | 离线许可证Id数组。 | 
| typedef struct [DRM_KeysInfo](_d_r_m___keys_info.md)[DRM_KeysInfo](_drm.md#drm_keysinfo) | 密钥信息。 | 
| typedef struct [DRM_MediaKeyDescription](_d_r_m___media_key_description.md)[DRM_MediaKeyDescription](_drm.md#drm_mediakeydescription) | 在线许可证描述信息。 | 
| typedef struct [DRM_PsshInfo](_d_r_m___pssh_info.md)[DRM_PsshInfo](_drm.md#drm_psshinfo) | DRM Pssh信息。 | 
| typedef struct [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md)[DRM_MediaKeySystemInfo](_drm.md#drm_mediakeysysteminfo) | 从媒体源获取的DRM信息。 | 
| typedef void(\* [DRM_MediaKeySystemInfoCallback](_drm.md#drm_mediakeysysteminfocallback)) ([DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | MeidiaKeySystem函数指针类型。 | 
| typedef struct [MediaKeySystem](_drm.md#mediakeysystem)[MediaKeySystem](_drm.md#mediakeysystem) | MediaKeySystem结构体。 | 
| typedef struct [MediaKeySession](_drm.md#mediakeysession)[MediaKeySession](_drm.md#mediakeysession) | MediaKeySession结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_ListenerType](_drm.md#drm_listenertype) {<br/>LISTENER_DRM_EVENT = 200,<br/>LISTENER_PROVISION_REQUIRED = 201,<br/>LISTENER_KEY_REQUIRED = 202,<br/>LISTENER_KEY_EXPIRED = 203,<br/>LISTENER_VENDOR_DEFINED = 204,<br/>LISTENER_EXPIRATION_UPDATE = 206<br/>} | 监听类型。 | 
| [DRM_ContentProtectionLevel](_drm.md#drm_contentprotectionlevel) {<br/>CONTENT_PROTECTION_LEVEL_UNKNOWN = 0,<br/>CONTENT_PROTECTION_LEVEL_SW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_HW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_MAX<br/>} | 内容保护级别类型。 | 
| [DRM_MediaKeyType](_drm.md#drm_mediakeytype) {<br/>MEDIA_KEY_TYPE_OFFLINE = 0,<br/>MEDIA_KEY_TYPE_ONLINE<br/>} | 许可证类型。 | 
| [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype) {<br/>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0,<br/>MEDIA_KEY_REQUEST_TYPE_INITIAL,<br/>MEDIA_KEY_REQUEST_TYPE_RENEWAL,<br/>MEDIA_KEY_REQUEST_TYPE_RELEASE,<br/>MEDIA_KEY_REQUEST_TYPE_NONE,<br/>MEDIA_KEY_REQUEST_TYPE_UPDATE<br/>} | 许可证请求类型。 | 
| [DRM_OfflineMediaKeyStatus](_drm.md#drm_offlinemediakeystatus) {<br/>OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0,<br/>OFFLINE_MEDIA_KEY_STATUS_USABLE,<br/>OFFLINE_MEDIA_KEY_STATUS_INACTIVE<br/>} | 离线许可证状态。 | 
| [DRM_CertificateStatus](_drm.md#drm_certificatestatus) {<br/>CERT_STATUS_PROVISIONED = 0,<br/>CERT_STATUS_NOT_PROVISIONED,<br/>CERT_STATUS_EXPIRED,<br/>CERT_STATUS_INVALID,<br/>CERT_STATUS_UNAVAILABLE<br/>} | 设备证书状态类型。 | 
| [DRM_MediaKeyStatus](_drm.md#drm_mediakeystatus) {<br/>MEDIA_KEY_STATUS_OK = 0,<br/>MEDIA_KEY_STATUS_UNAVAILABLE = 1<br/>} | 在线许可证状态。 | 

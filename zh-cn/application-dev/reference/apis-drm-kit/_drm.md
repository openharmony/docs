# Drm


## 概述

提供数字版权保护能力的API。

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_drm_common.h](native__drm__common_8h.md) | 定义DRM数据类型。<br/>**引用文件：** &lt;multimedia/drm_framework/native_drm_common.h&gt;<br/>**库：** libnative_drm.so | 
| [native_drm_err.h](native__drm__err_8h.md) | 定义DRM错误码。<br/>**引用文件：** &lt;multimedia/drm_framework/native_drm_err.h&gt;<br/>**库：** libnative_drm.so | 
| [native_mediakeysession.h](native__mediakeysession_8h.md) | 定义Drm MediaKeySession API。<br/>**引用文件：** &lt;multimedia/drm_framework/native_mediakeysession.h&gt;<br/>**库：** libnative_drm.so | 
| [native_mediakeysystem.h](native__mediakeysystem_8h.md) | 定义Drm MediaKeySystem API。<br/>**引用文件：** &lt;multimedia/drm_framework/native_mediakeysystem.h&gt;<br/>**库：** libnative_drm.so | 


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
| struct&nbsp;&nbsp;[MediaKeySession_Callback](_media_key_session___callback.md) | MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件。 | 
| struct&nbsp;&nbsp;[DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) | DRM插件的名称和UUID。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](#max_media_key_request_option_count)&nbsp;&nbsp;&nbsp;16 | 媒体密钥请求选项的最大计数。 | 
| [MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](#max_media_key_request_option_name_len)&nbsp;&nbsp;&nbsp;64 | 媒体密钥请求选项名称的最大长度。 | 
| [MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](#max_media_key_request_option_data_len)&nbsp;&nbsp;&nbsp;128 | 媒体密钥请求选项数据的最大长度。 | 
| [MAX_INIT_DATA_LEN](#max_init_data_len)&nbsp;&nbsp;&nbsp;2048 | 媒体密钥请求初始化数据的最大长度。 | 
| [MAX_MIMETYPE_LEN](#max_mimetype_len)&nbsp;&nbsp;&nbsp;64 | 媒体mimetype类型的最大长度。 | 
| [MAX_MEDIA_KEY_REQUEST_DATA_LEN](#max_media_key_request_data_len)&nbsp;&nbsp;&nbsp;8192 | 媒体密钥请求的最大长度。 | 
| [MAX_DEFAULT_URL_LEN](#max_default_url_len)&nbsp;&nbsp;&nbsp;2048 | URL最大长度。 | 
| [MAX_STATISTICS_COUNT](#max_statistics_count)&nbsp;&nbsp;&nbsp;10 | 统计项的最大计数。 | 
| [MAX_STATISTICS_NAME_LEN](#max_statistics_name_len)&nbsp;&nbsp;&nbsp;64 | 统计项名称的最大长度。 | 
| [MAX_STATISTICS_BUFFER_LEN](#max_statistics_buffer_len)&nbsp;&nbsp;&nbsp;256 | 统计项缓冲区的最大长度。 | 
| [MAX_OFFLINE_MEDIA_KEY_ID_COUNT](#max_offline_media_key_id_count)&nbsp;&nbsp;&nbsp;512 | 离线媒体密钥id的最大计数。 | 
| [MAX_OFFLINE_MEDIA_KEY_ID_LEN](#max_offline_media_key_id_len)&nbsp;&nbsp;&nbsp;64 | 离线媒体密钥id的最大长度。 | 
| [MAX_KEY_INFO_COUNT](#max_key_info_count)&nbsp;&nbsp;&nbsp;64 | 密钥信息的最大计数。 | 
| [MAX_KEY_ID_LEN](#max_key_id_len)&nbsp;&nbsp;&nbsp;16 | 密钥id的最大长度。 | 
| [MAX_KEY_STATUS_VALUE_LEN](#max_key_status_value_len)&nbsp;&nbsp;&nbsp;128 | 密钥状态值的最大长度。 | 
| [MAX_MEDIA_KEY_STATUS_COUNT](#max_media_key_status_count)&nbsp;&nbsp;&nbsp;64 | 媒体密钥状态的最大计数。 | 
| [MAX_MEDIA_KEY_STATUS_NAME_LEN](#max_media_key_status_name_len)&nbsp;&nbsp;&nbsp;64 | 媒体密钥状态名称的最大长度。 | 
| [MAX_MEDIA_KEY_STATUS_VALUE_LEN](#max_media_key_status_value_len)&nbsp;&nbsp;&nbsp;256 | 媒体密钥状态值的最大长度。 | 
| [DRM_UUID_LEN](#drm_uuid_len)&nbsp;&nbsp;&nbsp;16 | Drm系统 uuid长度。 | 
| [MAX_PSSH_DATA_LEN](#max_pssh_data_len)&nbsp;&nbsp;&nbsp;2048 | PSSH数据的最大长度。 | 
| [MAX_PSSH_INFO_COUNT](#max_pssh_info_count)&nbsp;&nbsp;&nbsp;8 | PSSH信息的最大计数。 | 
| [MAX_MEDIA_KEY_SYSTEM_NAME_LEN](#max_media_key_system_name_len)&nbsp;&nbsp;&nbsp;128 | 媒体密钥系统名称的最大长度。  | 
| [MAX_MEDIA_KEY_SYSTEM_NUM](#max_media_key_system_num)&nbsp;&nbsp;&nbsp;8 | 支持的媒体密钥系统的最大数量。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [DRM_EventType](#drm_eventtype-1) [DRM_EventType](#drm_eventtype) | 监听事件类型。 | 
| typedef enum [DRM_ContentProtectionLevel](#drm_contentprotectionlevel-1) [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) | 内容保护级别类型。 | 
| typedef enum [DRM_MediaKeyType](#drm_mediakeytype-1) [DRM_MediaKeyType](#drm_mediakeytype) | 许可证类型。 | 
| typedef enum [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype-1) [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) | 许可证请求类型。 | 
| typedef enum [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus-1) [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) | 离线许可证状态。 | 
| typedef enum [DRM_CertificateStatus](#drm_certificatestatus-1) [DRM_CertificateStatus](#drm_certificatestatus) | 设备证书状态类型。 | 
| typedef struct [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) [DRM_MediaKeyRequestInfo](#drm_mediakeyrequestinfo) | 媒体密钥请求信息。 | 
| typedef struct [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) [DRM_MediaKeyRequest](#drm_mediakeyrequest) | 媒体密钥请求。 | 
| typedef struct [DRM_Statistics](_d_r_m___statistics.md) [DRM_Statistics](#drm_statistics) | MediaKeySystem的度量信息。 | 
| typedef struct [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) [DRM_OfflineMediakeyIdArray](#drm_offlinemediakeyidarray) | 离线媒体密钥ID数组。 | 
| typedef struct [DRM_KeysInfo](_d_r_m___keys_info.md) [DRM_KeysInfo](#drm_keysinfo) | 媒体密钥信息。 | 
| typedef struct [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) [DRM_MediaKeyStatus](#drm_mediakeystatus) | 媒体密钥状态。 | 
| typedef struct [DRM_PsshInfo](_d_r_m___pssh_info.md) [DRM_PsshInfo](#drm_psshinfo) | uuid的PSSH信息。 | 
| typedef struct [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) | 播放器从媒体源获取媒体密钥系统信息。 | 
| typedef struct [DRM_MediaKeySystemDescription](_d_r_m___media_key_system_description.md) [DRM_MediaKeySystemDescription](#drm_mediakeysystemdescription) | DRM插件的名称和UUID。  | 
| typedef void(\* [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)) ([DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | 应用程序为从媒体源获取媒体密钥系统信息而设置的回调。 | 
| typedef struct [MediaKeySystem](#mediakeysystem) [MediaKeySystem](#mediakeysystem) | 媒体密钥系统结构。 | 
| typedef struct [MediaKeySession](#mediakeysession) [MediaKeySession](#mediakeysession) | 媒体密钥会话结构。 | 
| typedef enum [Drm_ErrCode](#drm_errcode-1) [Drm_ErrCode](#drm_errcode) | DRM错误码。 | 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySession_EventCallback](#mediakeysession_eventcallback)) ([DRM_EventType](#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | 事件触发时将调用的回调。 | 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySession_KeyChangeCallback](#mediakeysession_keychangecallback)) ([DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | 密钥更改时将调用回调。 | 
| typedef struct [MediaKeySession_Callback](_media_key_session___callback.md) [MediaKeySession_Callback](#mediakeysession_callback) | MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件。 | 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySystem_Callback](#mediakeysystem_callback)) ([DRM_EventType](#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | 事件触发时将调用的回调。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_EventType](#drm_eventtype-1) {<br/>EVENT_DRM_BASE = 200, <br/>EVENT_PROVISION_REQUIRED = 201, <br/>EVENT_KEY_REQUIRED = 202, <br/>EVENT_KEY_EXPIRED = 203,<br/>EVENT_VENDOR_DEFINED = 204, <br/>EVENT_EXPIRATION_UPDATE = 206<br/>} | 监听事件类型。 | 
| [DRM_ContentProtectionLevel](#drm_contentprotectionlevel-1) {<br/>CONTENT_PROTECTION_LEVEL_UNKNOWN = 0, <br/>CONTENT_PROTECTION_LEVEL_SW_CRYPTO, <br/>CONTENT_PROTECTION_LEVEL_HW_CRYPTO, <br/>CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_MAX<br/>} | 内容保护级别类型。 | 
| [DRM_MediaKeyType](#drm_mediakeytype-1) { <br/>MEDIA_KEY_TYPE_OFFLINE = 0, <br/>MEDIA_KEY_TYPE_ONLINE <br/>} | 许可证类型。 | 
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype-1) {<br/>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0, <br/>MEDIA_KEY_REQUEST_TYPE_INITIAL, <br/>MEDIA_KEY_REQUEST_TYPE_RENEWAL, <br/>MEDIA_KEY_REQUEST_TYPE_RELEASE,<br/>MEDIA_KEY_REQUEST_TYPE_NONE, <br/>MEDIA_KEY_REQUEST_TYPE_UPDATE<br/>} | 许可证请求类型。 | 
| [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus-1) { <br/>OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0, <br/>OFFLINE_MEDIA_KEY_STATUS_USABLE, <br/>OFFLINE_MEDIA_KEY_STATUS_INACTIVE } | 离线许可证状态。 | 
| [DRM_CertificateStatus](#drm_certificatestatus-1) {<br/>CERT_STATUS_PROVISIONED = 0, <br/>CERT_STATUS_NOT_PROVISIONED, <br/>CERT_STATUS_EXPIRED, <br/>CERT_STATUS_INVALID,<br/>CERT_STATUS_UNAVAILABLE<br/>} | 设备证书状态类型。 | 
| [Drm_ErrCode](#drm_errcode-1) {<br/>DRM_ERR_OK = 0, <br/>DRM_CAPI_ERR_BASE = 24700500, <br/>DRM_ERR_NO_MEMORY = DRM_CAPI_ERR_BASE + 1, <br/>DRM_ERR_OPERATION_NOT_PERMITTED = DRM_CAPI_ERR_BASE + 2,<br/>DRM_ERR_INVALID_VAL = DRM_CAPI_ERR_BASE + 3, <br/>DRM_ERR_IO = DRM_CAPI_ERR_BASE + 4, <br/>DRM_ERR_TIMEOUT = DRM_CAPI_ERR_BASE + 5, <br/>DRM_ERR_UNKNOWN = DRM_CAPI_ERR_BASE + 6,<br/>DRM_ERR_SERVICE_DIED = DRM_CAPI_ERR_BASE + 7, <br/>DRM_ERR_INVALID_STATE = DRM_CAPI_ERR_BASE + 8, <br/>DRM_ERR_UNSUPPORTED = DRM_CAPI_ERR_BASE + 9, <br/>DRM_ERR_MAX_SYSTEM_NUM_REACHED = DRM_CAPI_ERR_BASE + 10,<br/>DRM_ERR_MAX_SESSION_NUM_REACHED = DRM_CAPI_ERR_BASE + 11, <br/>DRM_ERR_EXTEND_START = DRM_CAPI_ERR_BASE + 100<br/>} | DRM错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_GenerateMediaKeyRequest](#oh_mediakeysession_generatemediakeyrequest) ([MediaKeySession](#mediakeysession) \*mediaKeySession, [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) \*info, [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) \*mediaKeyRequest) | 生成媒体密钥请求。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_ProcessMediaKeyResponse](#oh_mediakeysession_processmediakeyresponse) ([MediaKeySession](#mediakeysession) \*mediaKeySession, uint8_t \*response, int32_t responseLen, uint8_t \*offlineMediaKeyId, int32_t \*offlineMediaKeyIdLen) | 处理媒体密钥响应。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_CheckMediaKeyStatus](#oh_mediakeysession_checkmediakeystatus) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) \*mediaKeyStatus) | 检查媒体密钥状态。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_ClearMediaKeys](#oh_mediakeysession_clearmediakeys) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin) | 清除当前会话的媒体密钥。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_GenerateOfflineReleaseRequest](#oh_mediakeysession_generateofflinereleaserequest) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseRequest, int32_t \*releaseRequestLen) | 生成离线媒体密钥释放请求。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_ProcessOfflineReleaseResponse](#oh_mediakeysession_processofflinereleaseresponse) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseReponse, int32_t releaseReponseLen) | 处理离线媒体密钥释放响应。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_RestoreOfflineMediaKeys](#oh_mediakeysession_restoreofflinemediakeys) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | 按ID还原离线媒体密钥。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_GetContentProtectionLevel](#oh_mediakeysession_getcontentprotectionlevel) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取会话的内容保护级别。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_RequireSecureDecoderModule](#oh_mediakeysession_requiresecuredecodermodule) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, const char \*mimeType, bool \*status) | 加密内容是否需要安全解码。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_SetMediaKeySessionCallback](#oh_mediakeysession_setmediakeysessioncallback) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [MediaKeySession_Callback](_media_key_session___callback.md) \*callback) | 设置媒体密钥会话事件回调。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_Destroy](#oh_mediakeysession_destroy) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin) | 释放会话资源。 | 
| bool [OH_MediaKeySystem_IsSupported](#oh_mediakeysystem_issupported) (const char \*name) | 查询是否支持媒体密钥系统。 | 
| bool [OH_MediaKeySystem_IsSupported2](#oh_mediakeysystem_issupported2) (const char \*name, const char \*mimeType) | 查询是否支持媒体密钥系统。 | 
| bool [OH_MediaKeySystem_IsSupported3](#oh_mediakeysystem_issupported3) (const char \*name, const char \*mimeType, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) contentProtectionLevel) | 查询是否支持媒体密钥系统。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_Create](#oh_mediakeysystem_create) (const char \*name, [MediaKeySystem](#mediakeysystem) \*\*mediaKeySystem) | 根据名称创建媒体密钥系统实例。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_SetConfigurationString](#oh_mediakeysystem_setconfigurationstring) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, const char \*value) | 按字符串类型名称设置媒体密钥系统配置值。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetConfigurationString](#oh_mediakeysystem_getconfigurationstring) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, char \*value, int32_t valueLen) | 按字符串类型名称获取媒体密钥系统配置值。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_SetConfigurationByteArray](#oh_mediakeysystem_setconfigurationbytearray) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t valueLen) | 通过字符数组类型配置名设置MediaKeySystem的配置值。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetConfigurationByteArray](#oh_mediakeysystem_getconfigurationbytearray) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t \*valueLen) | 按字符数组类型名称获取媒体密钥系统配置值。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetStatistics](#oh_mediakeysystem_getstatistics) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_Statistics](_d_r_m___statistics.md) \*statistics) | 获取媒体密钥系统度量信息。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetMaxContentProtectionLevel](#oh_mediakeysystem_getmaxcontentprotectionlevel) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取支持的最高内容保护级别的媒体密钥系统。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_SetMediaKeySystemCallback](#oh_mediakeysystem_setmediakeysystemcallback) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [MediaKeySystem_Callback](#mediakeysystem_callback) callback) | 设置媒体密钥系统事件回调。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_CreateMediaKeySession](#oh_mediakeysystem_createmediakeysession) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*level, [MediaKeySession](#mediakeysession) \*\*mediaKeySession) | 创建媒体密钥会话实例。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GenerateKeySystemRequest](#oh_mediakeysystem_generatekeysystemrequest) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*request, int32_t \*requestLen, char \*defaultUrl, int32_t defaultUrlLen) | 生成媒体密钥系统提供请求。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_ProcessKeySystemResponse](#oh_mediakeysystem_processkeysystemresponse) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*response, int32_t responseLen) | 处理媒体密钥系统提供响应。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyIds](#oh_mediakeysystem_getofflinemediakeyids) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) \*offlineMediaKeyIds) | 获取离线媒体密钥ID。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyStatus](#oh_mediakeysystem_getofflinemediakeystatus) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) \*status) | 获取离线密钥状态。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_ClearOfflineMediaKeys](#oh_mediakeysystem_clearofflinemediakeys) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | 按id清除离线媒体密钥。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetCertificateStatus](#oh_mediakeysystem_getcertificatestatus) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_CertificateStatus](#drm_certificatestatus) \*certStatus) | 获取媒体密钥系统的证书状态。 | 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_Destroy](#oh_mediakeysystem_destroy) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem) | Destroy a 媒体密钥系统实例。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_MediaKeyType](#drm_mediakeytype) [DRM_MediaKeyRequestInfo::type](#type-12) | 密钥类型 | 
| int32_t [DRM_MediaKeyRequestInfo::initDataLen](#initdatalen) | 初始数据长度。 | 
| uint8_t [DRM_MediaKeyRequestInfo::initData](#initdata) [[MAX_INIT_DATA_LEN](#max_init_data_len)] | base64解码后格式为PSSH的初始数据。 | 
| char [DRM_MediaKeyRequestInfo::mimeType](#mimetype) [[MAX_MIMETYPE_LEN](#max_mimetype_len)] | 媒体上下文的mime类型。 | 
| uint32_t [DRM_MediaKeyRequestInfo::optionsCount](#optionscount) | 选项数据计数。 | 
| char [DRM_MediaKeyRequestInfo::optionName](#optionname) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](#max_media_key_request_option_name_len)] | 选项名称集合。 | 
| char [DRM_MediaKeyRequestInfo::optionData](#optiondata) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](#max_media_key_request_option_data_len)] | 选项数据集合。 | 
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) [DRM_MediaKeyRequest::type](#type-22) | 媒体密钥请求类型。 | 
| int32_t [DRM_MediaKeyRequest::dataLen](#datalen-12) | 媒体密钥请求数据长度。 | 
| uint8_t [DRM_MediaKeyRequest::data](#data-12) [[MAX_MEDIA_KEY_REQUEST_DATA_LEN](#max_media_key_request_data_len)] | 发送到媒体密钥服务器的媒体密钥请求数据。 | 
| char [DRM_MediaKeyRequest::defaultUrl](#defaulturl) [[MAX_DEFAULT_URL_LEN](#max_default_url_len)] | 媒体密钥服务器URL。 | 
| uint32_t [DRM_Statistics::statisticsCount](#statisticscount) | 度量计数。 | 
| char [DRM_Statistics::statisticsName](#statisticsname) [[MAX_STATISTICS_COUNT](#max_statistics_count)][[MAX_STATISTICS_NAME_LEN](#max_statistics_name_len)] | 度量信息名称集合。 | 
| char [DRM_Statistics::statisticsDescription](#statisticsdescription) [[MAX_STATISTICS_COUNT](#max_statistics_count)][[MAX_STATISTICS_BUFFER_LEN](#max_statistics_buffer_len)] | 度量信息描述集合。 | 
| uint32_t [DRM_OfflineMediakeyIdArray::idsCount](#idscount) | ID计数。 | 
| int32_t [DRM_OfflineMediakeyIdArray::idsLen](#idslen) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](#max_offline_media_key_id_count)] | ID长度集合。 | 
| uint8_t [DRM_OfflineMediakeyIdArray::ids](#ids) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](#max_offline_media_key_id_count)][[MAX_OFFLINE_MEDIA_KEY_ID_LEN](#max_offline_media_key_id_len)] | ID数据集合。 | 
| uint32_t [DRM_KeysInfo::keysInfoCount](#keysinfocount) | 钥匙计数。 | 
| uint8_t [DRM_KeysInfo::keyId](#keyid) [[MAX_KEY_INFO_COUNT](#max_key_info_count)][[MAX_KEY_ID_LEN](#max_key_id_len)] | 密钥ID集合。 | 
| char [DRM_KeysInfo::statusValue](#statusvalue-12) [[MAX_KEY_INFO_COUNT](#max_key_info_count)][[MAX_KEY_STATUS_VALUE_LEN](#max_key_status_value_len)] | 关键状态值。 | 
| uint32_t [DRM_MediaKeyStatus::statusCount](#statuscount) | 状态计数。 | 
| char [DRM_MediaKeyStatus::statusName](#statusname) [[MAX_MEDIA_KEY_STATUS_COUNT](#max_media_key_status_count)][[MAX_MEDIA_KEY_STATUS_NAME_LEN](#max_media_key_status_name_len)] | 状态名数组。 | 
| char [DRM_MediaKeyStatus::statusValue](#statusvalue-22) [[MAX_MEDIA_KEY_STATUS_COUNT](#max_media_key_status_count)][[MAX_MEDIA_KEY_STATUS_VALUE_LEN](#max_media_key_status_value_len)] | 状态值数组。 | 
| uint8_t [DRM_PsshInfo::uuid](#uuid-12) [[DRM_UUID_LEN](#drm_uuid_len)] | Uuid。 | 
| int32_t [DRM_PsshInfo::dataLen](#datalen-22) | PSSH数据长度。 | 
| uint8_t [DRM_PsshInfo::data](#data-22) [[MAX_PSSH_DATA_LEN](#max_pssh_data_len)] | uint8_t PSSH数据。 | 
| uint32_t [DRM_MediaKeySystemInfo::psshCount](#psshcount) | PSSH计数。 | 
| [DRM_PsshInfo](_d_r_m___pssh_info.md) [DRM_MediaKeySystemInfo::psshInfo](#psshinfo) [[MAX_PSSH_INFO_COUNT](#max_pssh_info_count)] | PSSH信息。 | 
| char [DRM_MediaKeySystemDescription::name](#name) [[MAX_MEDIA_KEY_SYSTEM_NAME_LEN](#max_media_key_system_name_len)] | DRM插件的名称。  | 
| uint8_t [DRM_MediaKeySystemDescription::uuid](#uuid-22) [[DRM_UUID_LEN](#drm_uuid_len)] | UUID。  | 
| [MediaKeySession_EventCallback](#mediakeysession_eventcallback) [MediaKeySession_Callback::eventCallback](#eventcallback) | 正常事件回调，如密钥过期等。 | 
| [MediaKeySession_KeyChangeCallback](#mediakeysession_keychangecallback) [MediaKeySession_Callback::keyChangeCallback](#keychangecallback) | 密钥更改事件的密钥更改回调。 | 


## 宏定义说明


### DRM_UUID_LEN

```
#define DRM_UUID_LEN   16
```

**描述**

Drm系统 uuid长度。

**起始版本：** 11


### MAX_DEFAULT_URL_LEN

```
#define MAX_DEFAULT_URL_LEN   2048
```

**描述**

URL最大长度。

**起始版本：** 11


### MAX_INIT_DATA_LEN

```
#define MAX_INIT_DATA_LEN   2048
```

**描述**

媒体密钥请求初始化数据的最大长度。

**起始版本：** 11


### MAX_KEY_ID_LEN

```
#define MAX_KEY_ID_LEN   16
```

**描述**

密钥id的最大长度。

**起始版本：** 11


### MAX_KEY_INFO_COUNT

```
#define MAX_KEY_INFO_COUNT   64
```

**描述**

密钥信息的最大计数。

**起始版本：** 11


### MAX_KEY_STATUS_VALUE_LEN

```
#define MAX_KEY_STATUS_VALUE_LEN   128
```

**描述**

密钥状态值的最大长度。

**起始版本：** 11


### MAX_MEDIA_KEY_REQUEST_DATA_LEN

```
#define MAX_MEDIA_KEY_REQUEST_DATA_LEN   8192
```

**描述**

媒体密钥请求的最大长度。

**起始版本：** 11


### MAX_MEDIA_KEY_REQUEST_OPTION_COUNT

```
#define MAX_MEDIA_KEY_REQUEST_OPTION_COUNT   16
```

**描述**

媒体密钥请求选项的最大计数。

**起始版本：** 11


### MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN

```
#define MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN   128
```

**描述**

媒体密钥请求选项数据的最大长度。

**起始版本：** 11


### MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN

```
#define MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN   64
```

**描述**

媒体密钥请求选项名称的最大长度。

**起始版本：** 11


### MAX_MEDIA_KEY_STATUS_COUNT

```
#define MAX_MEDIA_KEY_STATUS_COUNT   64
```

**描述**

媒体密钥状态的最大计数。

**起始版本：** 11


### MAX_MEDIA_KEY_STATUS_NAME_LEN

```
#define MAX_MEDIA_KEY_STATUS_NAME_LEN   64
```

**描述**

媒体密钥状态名称的最大长度。

**起始版本：** 11


### MAX_MEDIA_KEY_STATUS_VALUE_LEN

```
#define MAX_MEDIA_KEY_STATUS_VALUE_LEN   256
```

**描述**

媒体密钥状态值的最大长度。

**起始版本：** 11


### MAX_MEDIA_KEY_SYSTEM_NAME_LEN

```
#define MAX_MEDIA_KEY_SYSTEM_NAME_LEN   128
```
**描述**

媒体密钥系统名称的最大长度。

**起始版本：** 12


### MAX_MEDIA_KEY_SYSTEM_NUM

```
#define MAX_MEDIA_KEY_SYSTEM_NUM   8
```
**描述**

支持的媒体密钥系统的最大数量。

**起始版本：** 12


### MAX_MIMETYPE_LEN

```
#define MAX_MIMETYPE_LEN   64
```

**描述**

媒体mimetype类型的最大长度。

**起始版本：** 11


### MAX_OFFLINE_MEDIA_KEY_ID_COUNT

```
#define MAX_OFFLINE_MEDIA_KEY_ID_COUNT   512
```

**描述**

离线媒体密钥id的最大计数。

**起始版本：** 11


### MAX_OFFLINE_MEDIA_KEY_ID_LEN

```
#define MAX_OFFLINE_MEDIA_KEY_ID_LEN   64
```

**描述**

离线媒体密钥id的最大长度。

**起始版本：** 11


### MAX_PSSH_DATA_LEN

```
#define MAX_PSSH_DATA_LEN   2048
```

**描述**

PSSH数据的最大长度。

**起始版本：** 11


### MAX_PSSH_INFO_COUNT

```
#define MAX_PSSH_INFO_COUNT   8
```

**描述**

PSSH信息的最大计数。

**起始版本：** 11


### MAX_STATISTICS_BUFFER_LEN

```
#define MAX_STATISTICS_BUFFER_LEN   256
```

**描述**

统计项缓冲区的最大长度。

**起始版本：** 11


### MAX_STATISTICS_COUNT

```
#define MAX_STATISTICS_COUNT   10
```

**描述**

统计项的最大计数。

**起始版本：** 11


### MAX_STATISTICS_NAME_LEN

```
#define MAX_STATISTICS_NAME_LEN   64
```

**描述**

统计项名称的最大长度。

**起始版本：** 11


## 类型定义说明


### DRM_CertificateStatus

```
typedef enum DRM_CertificateStatus DRM_CertificateStatus
```

**描述**

设备证书状态类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_ContentProtectionLevel

```
typedef enum DRM_ContentProtectionLevel DRM_ContentProtectionLevel
```

**描述**

内容保护级别类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### Drm_ErrCode

```
typedef enum Drm_ErrCode Drm_ErrCode
```

**描述**

DRM错误码。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_EventType

```
typedef enum DRM_EventType DRM_EventType
```

**描述**

监听事件类型。

**起始版本：** 11


### DRM_KeysInfo

```
typedef struct DRM_KeysInfo DRM_KeysInfo
```

**描述**

媒体密钥信息。

**起始版本：** 11


### DRM_MediaKeyRequest

```
typedef struct DRM_MediaKeyRequest DRM_MediaKeyRequest
```

**描述**

媒体密钥请求。

**起始版本：** 11


### DRM_MediaKeyRequestInfo

```
typedef struct DRM_MediaKeyRequestInfo DRM_MediaKeyRequestInfo
```

**描述**

媒体密钥请求信息。

**起始版本：** 11


### DRM_MediaKeyRequestType

```
typedef enum DRM_MediaKeyRequestType DRM_MediaKeyRequestType
```

**描述**

许可证请求类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediaKeyStatus

```
typedef struct DRM_MediaKeyStatus DRM_MediaKeyStatus
```

**描述**

媒体密钥状态。

**起始版本：** 11


### DRM_MediaKeySystemDescription

```
typedef struct DRM_MediaKeySystemDescription DRM_MediaKeySystemDescription
```
**描述**

DRM插件的名称和UUID。

**起始版本：** 12


### DRM_MediaKeySystemInfo

```
typedef struct DRM_MediaKeySystemInfo DRM_MediaKeySystemInfo
```

**描述**

播放器从媒体源获取媒体密钥系统信息。

**起始版本：** 11


### DRM_MediaKeySystemInfoCallback

```
typedef void(* DRM_MediaKeySystemInfoCallback) (DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**

应用程序为从媒体源获取媒体密钥系统信息而设置的回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystemInfo | 从媒体源获取的媒体密钥系统信息。 | 

### DRM_MediaKeyType

```
typedef enum DRM_MediaKeyType DRM_MediaKeyType
```

**描述**

许可证类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_OfflineMediakeyIdArray

```
typedef struct DRM_OfflineMediakeyIdArray DRM_OfflineMediakeyIdArray
```

**描述**

离线媒体密钥ID数组。

**起始版本：** 11


### DRM_OfflineMediaKeyStatus

```
typedef enum DRM_OfflineMediaKeyStatus DRM_OfflineMediaKeyStatus
```

**描述**

离线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_PsshInfo

```
typedef struct DRM_PsshInfo DRM_PsshInfo
```

**描述**

uuid的PSSH信息。

**起始版本：** 11


### DRM_Statistics

```
typedef struct DRM_Statistics DRM_Statistics
```

**描述**

MediaKeySystem的度量信息。

**起始版本：** 11


### MediaKeySession

```
typedef struct MediaKeySession MediaKeySession
```

**描述**

媒体密钥会话结构。

**起始版本：** 11


### MediaKeySession_Callback

```
typedef struct MediaKeySession_Callback MediaKeySession_Callback
```

**描述**

MediaKeySession_Callback结构体，用于监听密钥过期、密钥更改等事件。

**起始版本：** 11


### MediaKeySession_EventCallback

```
typedef Drm_ErrCode(* MediaKeySession_EventCallback) (DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
```

**描述**

事件触发时将调用的回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventType | 事件类型。 | 
| info | 从媒体密钥会话获取的事件信息。 | 
| infoLen | 事件信息长度。 | 
| extra | 从媒体密钥会话中获得的额外信息。 | 

**返回：**

Drm_ErrCode 错误码。


### MediaKeySession_KeyChangeCallback

```
typedef Drm_ErrCode(* MediaKeySession_KeyChangeCallback) (DRM_KeysInfo *keysInfo, bool newKeysAvailable)
```

**描述**

密钥更改时将调用回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keysInfo | 从媒体密钥系统获取的密钥信息。 | 
| newKeysAvailable | 新密钥是否可用 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### MediaKeySystem

```
typedef struct MediaKeySystem MediaKeySystem
```

**描述**

媒体密钥系统结构。

**起始版本：** 11


### MediaKeySystem_Callback

```
typedef Drm_ErrCode(* MediaKeySystem_Callback) (DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
```

**描述**

事件触发时将调用的回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventType | 事件类型。 | 
| info | 从媒体密钥系统获取的事件信息。 | 
| infoLen | 事件信息长度。 | 
| extra | 从媒体密钥系统获得的额外信息。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


## 枚举类型说明


### DRM_CertificateStatus

```
enum DRM_CertificateStatus
```

**描述**

设备证书状态类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CERT_STATUS_PROVISIONED | 设备已安装设备证书 | 
| CERT_STATUS_NOT_PROVISIONED | 设备未安装设备证书 | 
| CERT_STATUS_EXPIRED | 设备证书过期 | 
| CERT_STATUS_INVALID | 设备证书无效 | 
| CERT_STATUS_UNAVAILABLE | 设备证书不可用 | 


### DRM_ContentProtectionLevel

```
enum DRM_ContentProtectionLevel
```

**描述**

内容保护级别类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CONTENT_PROTECTION_LEVEL_UNKNOWN | 未知级别 | 
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO | 软件安全级别 | 
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO | 硬件安全级别 | 
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO | 硬件增强级别 | 
| CONTENT_PROTECTION_LEVEL_MAX | 最大安全级别 | 


### Drm_ErrCode

```
enum Drm_ErrCode
```

**描述**

DRM错误码。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| DRM_ERR_OK | 操作成功完成。 | 
| DRM_CAPI_ERR_BASE | 基础错误。 | 
| DRM_ERR_NO_MEMORY | 内存不足。 | 
| DRM_ERR_OPERATION_NOT_PERMITTED | 不允许的操作。 | 
| DRM_ERR_INVALID_VAL | 无效参数。 | 
| DRM_ERR_IO | IO 错误。 | 
| DRM_ERR_TIMEOUT | 网络超时。 | 
| DRM_ERR_UNKNOWN | 未知错误。 | 
| DRM_ERR_SERVICE_DIED | drm服务挂死。 | 
| DRM_ERR_INVALID_STATE | 无效的操作状态。 | 
| DRM_ERR_UNSUPPORTED | 不支持的操作。 | 
| DRM_ERR_MAX_SYSTEM_NUM_REACHED | MediaKeySystem最大实例数。 | 
| DRM_ERR_MAX_SESSION_NUM_REACHED | MediaKeySession最大实例数。 | 
| DRM_ERR_EXTEND_START | 扩展错误。 | 


### DRM_EventType

```
enum DRM_EventType
```

**描述**

监听事件类型。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| EVENT_DRM_BASE | DRM基础事件 | 
| EVENT_PROVISION_REQUIRED | 设备证书请求事件 | 
| EVENT_KEY_REQUIRED | 密钥请求事件 | 
| EVENT_KEY_EXPIRED | 密钥过期事件 | 
| EVENT_VENDOR_DEFINED | 第三方定义事件 | 
| EVENT_EXPIRATION_UPDATE | 密钥过期更新事件 | 


### DRM_MediaKeyRequestType

```
enum DRM_MediaKeyRequestType
```

**描述**

许可证请求类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN | 未知请求类型 | 
| MEDIA_KEY_REQUEST_TYPE_INITIAL | 初始化请求 | 
| MEDIA_KEY_REQUEST_TYPE_RENEWAL | 续订请求 | 
| MEDIA_KEY_REQUEST_TYPE_RELEASE | 释放请求 | 
| MEDIA_KEY_REQUEST_TYPE_NONE | 无请求 | 
| MEDIA_KEY_REQUEST_TYPE_UPDATE | 更新请求 | 


### DRM_MediaKeyType

```
enum DRM_MediaKeyType
```

**描述**

许可证类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_KEY_TYPE_OFFLINE | 离线 | 
| MEDIA_KEY_TYPE_ONLINE | 在线 | 


### DRM_OfflineMediaKeyStatus

```
enum DRM_OfflineMediaKeyStatus
```

**描述**

离线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN | 未知状态 | 
| OFFLINE_MEDIA_KEY_STATUS_USABLE | 可用状态 | 
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE | 失活状态 | 


## 函数说明


### OH_MediaKeySession_CheckMediaKeyStatus()

```
Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus (MediaKeySession * mediaKeySessoin, DRM_MediaKeyStatus * mediaKeyStatus )
```

**描述**

检查媒体密钥状态。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| mediaKeyStatus | 媒体密钥状态。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_ClearMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_ClearMediaKeys (MediaKeySession * mediaKeySessoin)
```

**描述**

清除当前会话的媒体密钥。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_Destroy()

```
Drm_ErrCode OH_MediaKeySession_Destroy (MediaKeySession * mediaKeySessoin)
```

**描述**

释放会话资源。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_GenerateMediaKeyRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateMediaKeyRequest (MediaKeySession * mediaKeySession, DRM_MediaKeyRequestInfo * info, DRM_MediaKeyRequest * mediaKeyRequest )
```

**描述**

生成媒体密钥请求。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| info | 媒体密钥请求信息。 | 
| mediaKeyRequest | 媒体密钥请求。 | 

**返回：**

Drm_ErrCode 错误码。


### OH_MediaKeySession_GenerateOfflineReleaseRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest (MediaKeySession * mediaKeySessoin, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t * releaseRequest, int32_t * releaseRequestLen )
```

**描述**

生成离线媒体密钥释放请求。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| offlineMediaKeyId | 离线媒体密钥标识符。 | 
| releaseRequestLen | 离线媒体密钥标识符长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_GetContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySession_GetContentProtectionLevel (MediaKeySession * mediaKeySessoin, DRM_ContentProtectionLevel * contentProtectionLevel )
```

**描述**

获取会话的内容保护级别。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| contentProtectionLevel | 内容保护级别。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_ProcessMediaKeyResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse (MediaKeySession * mediaKeySession, uint8_t * response, int32_t responseLen, uint8_t * offlineMediaKeyId, int32_t * offlineMediaKeyIdLen )
```

**描述**

处理媒体密钥响应。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| response | 媒体密钥响应。 | 
| responseLen | 媒体密钥响应长度。 | 
| offlineMediaKeyId | 离线媒体密钥标识符。 | 
| offlineMediaKeyIdLen | 缓冲区内和缓冲区外数据的离线媒体密钥标识符的长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_ProcessOfflineReleaseResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse (MediaKeySession * mediaKeySessoin, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t * releaseReponse, int32_t releaseReponseLen )
```

**描述**

处理离线媒体密钥释放响应。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| offlineMediaKeyId | 离线媒体密钥标识符。 | 
| offlineMediaKeyIdLen | 离线媒体密钥标识符长度。 | 
| releaseReponse | 媒体密钥响应。 | 
| releaseReponseLen | 媒体密钥响应长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_RequireSecureDecoderModule()

```
Drm_ErrCode OH_MediaKeySession_RequireSecureDecoderModule (MediaKeySession * mediaKeySessoin, const char * mimeType, bool * status )
```

**描述**

加密内容是否需要安全解码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| mimeType | 媒体类型。 | 
| status | 是否需要安全解码。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_RestoreOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_RestoreOfflineMediaKeys (MediaKeySession * mediaKeySessoin, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen )
```

**描述**

按ID还原离线媒体密钥。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| offlineMediaKeyId | 离线媒体密钥标识符。 | 
| offlineMediaKeyIdLen | 离线媒体密钥标识符长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySession_SetMediaKeySessionCallback()

```
Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback (MediaKeySession * mediaKeySessoin, MediaKeySession_Callback * callback )
```

**描述**

设置媒体密钥会话事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | 媒体密钥会话实例。 | 
| callback | 要设置为媒体密钥会话的回调。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_ClearOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySystem_ClearOfflineMediaKeys (MediaKeySystem * mediaKeySystem, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen )
```

**描述**

按id清除离线媒体密钥。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| offlineMediaKeyId | 离线媒体密钥标识符。 | 
| offlineMediaKeyIdLen | 离线媒体密钥标识符长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_Create()

```
Drm_ErrCode OH_MediaKeySystem_Create (const char * name, MediaKeySystem ** mediaKeySystem )
```

**描述**

根据名称创建媒体密钥系统实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 说明将按名称创建哪个drm系统。 | 
| mediaKeySystem | 媒体密钥系统实例。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK， 当达到媒体密钥会话的最大数量时，返回DRM_ERR_MAX_SYSTEM_NUM_REACHED。


### OH_MediaKeySystem_CreateMediaKeySession()

```
Drm_ErrCode OH_MediaKeySystem_CreateMediaKeySession (MediaKeySystem * mediaKeySystem, DRM_ContentProtectionLevel * level, MediaKeySession ** mediaKeySession )
```

**描述**

创建媒体密钥会话实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 将创建媒体密钥会话的媒体密钥系统实例。 | 
| level | 指定内容保护级别。 | 
| mediaKeySession | 媒体密钥会话实例。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK， 当达到媒体密钥会话的最大数量时，返回DRM_ERR_MAX_SESSION_NUM_REACHED。


### OH_MediaKeySystem_Destroy()

```
Drm_ErrCode OH_MediaKeySystem_Destroy (MediaKeySystem * mediaKeySystem)
```

**描述**

Destroy a 媒体密钥系统实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 指定将销毁哪个媒体密钥系统实例。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GenerateKeySystemRequest()

```
Drm_ErrCode OH_MediaKeySystem_GenerateKeySystemRequest (MediaKeySystem * mediaKeySystem, uint8_t * request, int32_t * requestLen, char * defaultUrl, int32_t defaultUrlLen )
```

**描述**

生成媒体密钥系统提供请求。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| request | 发送给设备服务器的请求。 | 
| requestLen | 设备证书请求的长度。 | 
| defaultUrl | 设备证书服务器的网址。 | 
| defaultUrlLen | 设备证书服务器的网址长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetCertificateStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetCertificateStatus (MediaKeySystem * mediaKeySystem, DRM_CertificateStatus * certStatus )
```

**描述**

获取媒体密钥系统的证书状态。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| certStatus | 获得的证书状态值。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationByteArray (MediaKeySystem * mediaKeySystem, const char * configName, uint8_t * value, int32_t * valueLen )
```

**描述**

按字符数组类型的名称获取媒体密钥系统配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| configName | 配置名称字符串。 | 
| value | 要获取数组中的配置值。 | 
| valueLen | 数据的配置值长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationString (MediaKeySystem * mediaKeySystem, const char * configName, char * value, int32_t valueLen )
```

**描述**

按字符串类型名称获取媒体密钥系统配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| configName | 字符串类型配置名。 | 
| value | 字符串形式配置值。 | 
| valueLen | 字符串形式配置值长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetMaxContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySystem_GetMaxContentProtectionLevel (MediaKeySystem * mediaKeySystem, DRM_ContentProtectionLevel * contentProtectionLevel )
```

**描述**

获取支持的最高内容保护级别的媒体密钥系统。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| contentProtectionLevel | 内容保护级别。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetMediaKeySystems()

```
Drm_ErrCode OH_MediaKeySystem_GetMediaKeySystems (DRM_MediaKeySystemDescription * infos, uint32_t * count )
```
**描述**

获取支持的媒体密钥系统的名称和uuid。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| infos | 用于保存媒体密钥系统的名称和uuid的数组。  | 
| count | 用于指示结构体DRM_MediaKeySystemMapInfo的计数。  | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetOfflineMediaKeyIds()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyIds (MediaKeySystem * mediaKeySystem, DRM_OfflineMediakeyIdArray * offlineMediaKeyIds )
```

**描述**

获取离线媒体密钥ID。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| offlineMediaKeyIds | 所有离线媒体密钥的媒体密钥ID。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetOfflineMediaKeyStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyStatus (MediaKeySystem * mediaKeySystem, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen, DRM_OfflineMediaKeyStatus * status )
```

**描述**

获取离线密钥状态。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| offlineMediaKeyId | 离线媒体密钥标识符。 | 
| offlineMediaKeyIdLen | 离线媒体密钥标识符长度。 | 
| status | 已获取媒体密钥状态。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_GetStatistics()

```
Drm_ErrCode OH_MediaKeySystem_GetStatistics (MediaKeySystem * mediaKeySystem, DRM_Statistics * statistics )
```

**描述**

获取媒体密钥系统度量信息。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| statistics | 已获取度量信息。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_IsSupported()

```
bool OH_MediaKeySystem_IsSupported (const char * name)
```

**描述**

查询是否支持媒体密钥系统。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 用于指向数字权限管理解决方案。 | 

**返回：**

是否支持。


### OH_MediaKeySystem_IsSupported2()

```
bool OH_MediaKeySystem_IsSupported2 (const char * name, const char * mimeType )
```

**描述**

查询是否支持媒体密钥系统。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 用于指向数字权限管理解决方案。 | 
| mimeType | 用于指定媒体类型。 | 

**返回：**

是否支持。


### OH_MediaKeySystem_IsSupported3()

```
bool OH_MediaKeySystem_IsSupported3 (const char * name, const char * mimeType, DRM_ContentProtectionLevel contentProtectionLevel )
```
**描述**

查询是否支持媒体密钥系统。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 用于指向数字权限管理解决方案。 | 
| mimeType | 用于指定媒体类型。 | 
| contentProtectionLevel | 用于指定安全等级。 | 

**返回：**

是否支持。


### OH_MediaKeySystem_ProcessKeySystemResponse()

```
Drm_ErrCode OH_MediaKeySystem_ProcessKeySystemResponse (MediaKeySystem * mediaKeySystem, uint8_t * response, int32_t responseLen )
```

**描述**

处理媒体密钥系统提供响应。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| response | 将处理的响应。 | 
| responseLen | 响应长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_SetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationByteArray (MediaKeySystem * mediaKeySystem, const char * configName, uint8_t * value, int32_t valueLen )
```

**描述**

通过字符数组类型配置名设置MediaKeySystem的配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| configName | 字符串类型配置名。 | 
| value | 字节数组形式配置值。 | 
| valueLen | 字节数组形式配置值长度。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_SetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationString (MediaKeySystem * mediaKeySystem, const char * configName, const char * value )
```

**描述**

按字符串类型名称设置媒体密钥系统配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| configName | 配置名称字符串。 | 
| value | 要设置的字符串的配置值。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


### OH_MediaKeySystem_SetMediaKeySystemCallback()

```
Drm_ErrCode OH_MediaKeySystem_SetMediaKeySystemCallback (MediaKeySystem * mediaKeySystem, MediaKeySystem_Callback callback )
```

**描述**

设置媒体密钥系统事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 媒体密钥系统实例。 | 
| callback | 将回调设置为媒体密钥系统。 | 

**返回：**

当参数检查失败时返回DRM_ERR_INVALID_VAL，当函数调用成功时返回DRM_ERR_OK。


## 变量说明


### data [1/2]

```
uint8_t DRM_MediaKeyRequest::data[MAX_MEDIA_KEY_REQUEST_DATA_LEN]
```

**描述**

发送到媒体密钥服务器的媒体密钥请求数据。


### data [2/2]

```
uint8_t DRM_PsshInfo::data[MAX_PSSH_DATA_LEN]
```

**描述**

uint8_t PSSH数据。


### dataLen [1/2]

```
int32_t DRM_MediaKeyRequest::dataLen
```

**描述**

媒体密钥请求数据长度。


### dataLen [2/2]

```
int32_t DRM_PsshInfo::dataLen
```

**描述**

PSSH数据长度。


### defaultUrl

```
char DRM_MediaKeyRequest::defaultUrl[MAX_DEFAULT_URL_LEN]
```

**描述**

媒体密钥服务器URL。


### eventCallback

```
MediaKeySession_EventCallback MediaKeySession_Callback::eventCallback
```

**描述**

正常事件回调，如密钥过期等。


### ids

```
uint8_t DRM_OfflineMediakeyIdArray::ids[MAX_OFFLINE_MEDIA_KEY_ID_COUNT][MAX_OFFLINE_MEDIA_KEY_ID_LEN]
```

**描述**

ID数据集合


### idsCount

```
uint32_t DRM_OfflineMediakeyIdArray::idsCount
```

**描述**

ID计数


### idsLen

```
int32_t DRM_OfflineMediakeyIdArray::idsLen[MAX_OFFLINE_MEDIA_KEY_ID_COUNT]
```

**描述**

ID长度集合


### initData

```
uint8_t DRM_MediaKeyRequestInfo::initData[MAX_INIT_DATA_LEN]
```

**描述**

base64解码后格式为PSSH的初始数据。


### initDataLen

```
int32_t DRM_MediaKeyRequestInfo::initDataLen
```

**描述**

初始数据长度。


### keyChangeCallback

```
MediaKeySession_KeyChangeCallback MediaKeySession_Callback::keyChangeCallback
```

**描述**

密钥更改事件的密钥更改回调。


### keyId

```
uint8_t DRM_KeysInfo::keyId[MAX_KEY_INFO_COUNT][MAX_KEY_ID_LEN]
```

**描述**

密钥ID集合。


### keysInfoCount

```
uint32_t DRM_KeysInfo::keysInfoCount
```

**描述**

钥匙计数。


### mimeType

```
char DRM_MediaKeyRequestInfo::mimeType[MAX_MIMETYPE_LEN]
```

**描述**

媒体上下文的mime类型。


### name

```
char DRM_MediaKeySystemDescription::name[MAX_MEDIA_KEY_SYSTEM_NAME_LEN]
```
**描述**
DRM插件的名称。


### optionData

```
char DRM_MediaKeyRequestInfo::optionData[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN]
```

**描述**

选项数据集合。


### optionName

```
char DRM_MediaKeyRequestInfo::optionName[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN]
```

**描述**

选项名称集合。


### optionsCount

```
uint32_t DRM_MediaKeyRequestInfo::optionsCount
```

**描述**

选项数据计数。


### psshCount

```
uint32_t DRM_MediaKeySystemInfo::psshCount
```

**描述**

PSSH计数。


### psshInfo

```
DRM_PsshInfo DRM_MediaKeySystemInfo::psshInfo[MAX_PSSH_INFO_COUNT]
```

**描述**

PSSH信息.


### statisticsCount

```
uint32_t DRM_Statistics::statisticsCount
```

**描述**

度量计数。


### statisticsDescription

```
char DRM_Statistics::statisticsDescription[MAX_STATISTICS_COUNT][MAX_STATISTICS_BUFFER_LEN]
```

**描述**

度量信息描述集合。


### statisticsName

```
char DRM_Statistics::statisticsName[MAX_STATISTICS_COUNT][MAX_STATISTICS_NAME_LEN]
```

**描述**

度量信息名称集合。


### statusCount

```
uint32_t DRM_MediaKeyStatus::statusCount
```

**描述**

状态计数。


### statusName

```
char DRM_MediaKeyStatus::statusName[MAX_MEDIA_KEY_STATUS_COUNT][MAX_MEDIA_KEY_STATUS_NAME_LEN]
```

**描述**

状态名数组。


### statusValue [1/2]

```
char DRM_KeysInfo::statusValue[MAX_KEY_INFO_COUNT][MAX_KEY_STATUS_VALUE_LEN]
```

**描述**

关键状态值。


### statusValue [2/2]

```
char DRM_MediaKeyStatus::statusValue[MAX_MEDIA_KEY_STATUS_COUNT][MAX_MEDIA_KEY_STATUS_VALUE_LEN]
```

**描述**

状态值数组。


### type [1/2]

```
DRM_MediaKeyType DRM_MediaKeyRequestInfo::type
```

**描述**

密钥类型。


### type [2/2]

```
DRM_MediaKeyRequestType DRM_MediaKeyRequest::type
```

**描述**

媒体密钥请求类型。


### uuid [1/2]

```
uint8_t DRM_PsshInfo::uuid[DRM_UUID_LEN]
```

**描述**
Uuid。


### uuid [2/2]

```
uint8_t DRM_MediaKeySystemDescription::uuid[DRM_UUID_LEN]
```
**描述**
UUID。

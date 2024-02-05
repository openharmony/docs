# Drm


## 概述

提供数字版权保护能力的API。

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_drm_common.h](native__drm__common_8h.md) | 定义DRM数据类型。<br/>**引用文件：** &lt;multimedia/drm_framework/native_drm_common.h&gt;<br/>**库：** libnative_drm.z.so | 
| [native_drm_err.h](native__drm__err_8h.md) | 定义DRM错误码。<br/>**引用文件：** &lt;multimedia/drm_framework/native_drm_err.h&gt;<br/>**库：** libnative_drm.z.so | 
| [native_mediakeysession.h](native__mediakeysession_8h.md) | 定义Drm MediaKeySession API。<br/>**引用文件：** &lt;multimedia/drm_framework/native_mediakeysession.h&gt;<br/>**库：** libnative_drm.z.so | 
| [native_mediakeysystem.h](native__mediakeysystem_8h.md) | 定义Drm MediaKeySystem API。<br/>**引用文件：** &lt;multimedia/drm_framework/native_mediakeysystem.h&gt;<br/>**库：** libnative_drm.z.so | 


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
| struct&nbsp;&nbsp;[MediaKeySession_Callback](_media_key_session___callback.md) | MediaKeySession回调结构体, 用来监听密钥过期、密钥变化等事件。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_UUID_LEN](#drm_uuid_len)&nbsp;&nbsp;&nbsp;16 | DRM插件类型名。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [DRM_ListenerType](#drm_listenertype)[DRM_ListenerType](#drm_listenertype) | 监听类型。 | 
| typedef enum [DRM_ContentProtectionLevel](#drm_contentprotectionlevel)[DRM_ContentProtectionLevel](#drm_contentprotectionlevel) | 内容保护级别类型。 | 
| typedef enum [DRM_MediaKeyType](#drm_mediakeytype)[DRM_MediaKeyType](#drm_mediakeytype) | 许可证类型。 | 
| typedef enum [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype)[DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) | 许可证请求类型。 | 
| typedef enum [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus)[DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) | 离线许可证状态。 | 
| typedef enum [DRM_CertificateStatus](#drm_certificatestatus)[DRM_CertificateStatus](#drm_certificatestatus) | 设备证书状态类型。 | 
| typedef enum [DRM_MediaKeyStatus](#drm_mediakeystatus)[DRM_MediaKeyStatus](#drm_mediakeystatus) | 在线许可证状态。 | 
| typedef struct [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md)[DRM_Uint8Buffer](#drm_uint8buffer) | DRM uint_8 数组类型。 | 
| typedef struct [DRM_CharBuffer](_d_r_m___char_buffer.md)[DRM_CharBuffer](#drm_charbuffer) | DRM 字符数组类型。 | 
| typedef struct [DRM_CharBufferPair](_d_r_m___char_buffer_pair.md)[DRM_CharBufferPair](#drm_charbufferpair) | 字符数组类型的名值对。 | 
| typedef struct [DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md)[DRM_Uint8CharBufferPair](#drm_uint8charbufferpair) | 整形数组类型的名值对。 | 
| typedef struct [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md)[DRM_MediaKeyRequestInfo](#drm_mediakeyrequestinfo) | 许可证请求参数类型。 | 
| typedef struct [DRM_MediaKeyRequest](_d_r_m___media_key_request.md)[DRM_MediaKeyRequest](#drm_mediakeyrequest) | 许可证请求类型。 | 
| typedef struct [DRM_Statistics](_d_r_m___statistics.md)[DRM_Statistics](#drm_statistics) | DRM度量统计信息。 | 
| typedef struct [DRM_MediakeyIdArray](_d_r_m___mediakey_id_array.md)[DRM_MediakeyIdArray](#drm_mediakeyidarray) | 离线许可证Id数组。 | 
| typedef struct [DRM_KeysInfo](_d_r_m___keys_info.md)[DRM_KeysInfo](#drm_keysinfo) | 密钥信息。 | 
| typedef struct [DRM_MediaKeyDescription](_d_r_m___media_key_description.md)[DRM_MediaKeyDescription](#drm_mediakeydescription) | 在线许可证描述信息。 | 
| typedef struct [DRM_PsshInfo](_d_r_m___pssh_info.md)[DRM_PsshInfo](#drm_psshinfo) | DRM Pssh信息。 | 
| typedef struct [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md)[DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) | 从媒体源获取的DRM信息。 | 
| typedef void(\* [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)) ([DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | MeidiaKeySystem函数指针类型。 | 
| typedef struct [MediaKeySystem](#mediakeysystem)[MediaKeySystem](#mediakeysystem) | MediaKeySystem结构体。 | 
| typedef struct [MediaKeySession](#mediakeysession)[MediaKeySession](#mediakeysession) | MediaKeySession结构体。 | 
| typedef enum [Drm_ErrCode](#drm_errcode)[Drm_ErrCode](#drm_errcode) | DRM错误码。 | 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySession_EventCallback](#mediakeysession_eventcallback)) ([DRM_ListenerType](#drm_listenertype) eventType, [DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md) \*eventInfo) | 事件触发时将调用的回调。 | 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySession_KeyChangeCallback](#mediakeysession_keychangecallback)) ([DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | 注册监听，监听密钥变化。 | 
| typedef struct [MediaKeySession_Callback](_media_key_session___callback.md)[MediaKeySession_Callback](#mediakeysession_callback) | MediaKeySession回调结构体, 用来监听密钥过期、密钥变化等事件。 | 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySystem_Callback](#mediakeysystem_callback)) ([DRM_ListenerType](#drm_listenertype) eventType, [DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md) \*eventInfo) | 事件触发时将调用的回调。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_ListenerType](#drm_listenertype) {<br/>LISTENER_DRM_EVENT = 200,<br/>LISTENER_PROVISION_REQUIRED = 201,<br/>LISTENER_KEY_REQUIRED = 202,<br/>LISTENER_KEY_EXPIRED = 203,<br/>LISTENER_VENDOR_DEFINED = 204,<br/>LISTENER_EXPIRATION_UPDATE = 206<br/>} | 监听类型。 | 
| [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) {<br/>CONTENT_PROTECTION_LEVEL_UNKNOWN = 0,<br/>CONTENT_PROTECTION_LEVEL_SW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_HW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO,<br/>CONTENT_PROTECTION_LEVEL_MAX<br/>} | 内容保护级别类型。 | 
| [DRM_MediaKeyType](#drm_mediakeytype) {<br/>MEDIA_KEY_TYPE_OFFLINE = 0,<br/>MEDIA_KEY_TYPE_ONLINE<br/>} | 许可证类型。 | 
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) {<br/>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0,<br/>MEDIA_KEY_REQUEST_TYPE_INITIAL,<br/>MEDIA_KEY_REQUEST_TYPE_RENEWAL,<br/>MEDIA_KEY_REQUEST_TYPE_RELEASE,<br/>MEDIA_KEY_REQUEST_TYPE_NONE,<br/>MEDIA_KEY_REQUEST_TYPE_UPDATE<br/>} | 许可证请求类型。 | 
| [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) {<br/>OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0,<br/>OFFLINE_MEDIA_KEY_STATUS_USABLE,<br/>OFFLINE_MEDIA_KEY_STATUS_INACTIVE<br/>} | 离线许可证状态。 | 
| [DRM_CertificateStatus](#drm_certificatestatus) {<br/>CERT_STATUS_PROVISIONED = 0,<br/>CERT_STATUS_NOT_PROVISIONED,<br/>CERT_STATUS_EXPIRED,<br/>CERT_STATUS_INVALID,<br/>CERT_STATUS_UNAVAILABLE<br/>} | 设备证书状态类型。 | 
| [DRM_MediaKeyStatus](#drm_mediakeystatus) {<br/>MEDIA_KEY_STATUS_OK = 0,<br/>MEDIA_KEY_STATUS_UNAVAILABLE = 1<br/>} | 在线许可证状态。 | 
| [Drm_ErrCode](#drm_errcode) {<br/>DRM_ERR_OK = 0,<br/>DRM_ERR_NO_MEMORY,<br/>DRM_ERR_OPERATION_NOT_PERMITTED,<br/>DRM_ERR_INVALID_VAL,<br/>DRM_ERR_IO,<br/>DRM_ERR_TIMEOUT,<br/>DRM_ERR_UNKNOWN,<br/>DRM_ERR_SERVICE_DIED,<br/>DRM_ERR_INVALID_STATE,<br/>DRM_ERR_UNSUPPORTED,<br/>DRM_ERR_MAX_SYSTEM_NUM_REACHED,<br/>DRM_ERR_MAX_SESSION_NUM_REACHED,<br/>DRM_ERR_EXTEND_START = 100<br/>} | DRM错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_GenerateMediaKeyRequest](#oh_mediakeysession_generatemediakeyrequest) ([MediaKeySession](#mediakeysession) \*mediaKeySession, [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) \*info, [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) \*\*mediaKeyRequest) | 生成许可证请求。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_ProcessMediaKeyResponse](#oh_mediakeysession_processmediakeyresponse) ([MediaKeySession](#mediakeysession) \*keySession, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*response, unsigned char \*\*mediaKeyId, int32_t \*mediaKeyIdLen) | 处理许可证响应。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_CheckMediaKeyStatus](#oh_mediakeysession_checkmediakeystatus) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_MediaKeyDescription](_d_r_m___media_key_description.md) \*\*mediaKeyDescription) | 检查许可证状态. | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_ClearMediaKeys](#oh_mediakeysession_clearmediakeys) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin) | 清除当前会话的许可证 . | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_GenerateOfflineReleaseRequest](#oh_mediakeysession_generateofflinereleaserequest) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId, unsigned char \*\*releaseRequest, int32_t \*releaseRequestLen) | 生成离线许可证释放请求。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_ProcessOfflineReleaseResponse](#oh_mediakeysession_processofflinereleaseresponse) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*releaseReponse) | 处理离线许可证释放响应。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_RestoreOfflineMediaKeys](#oh_mediakeysession_restoreofflinemediakeys) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId) | 根据许可证ID恢复对应许可证状态。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_GetContentProtectionLevel](#oh_mediakeysession_getcontentprotectionlevel) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取当前会话的内容保护级别。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_RequireSecureDecoderModule](#oh_mediakeysession_requiresecuredecodermodule) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, const char \*mimeType, bool \*status) | 查询是否需要安全解码。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_SetMediaKeySessionCallback](#oh_mediakeysession_setmediakeysessioncallback) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [MediaKeySession_Callback](_media_key_session___callback.md) \*callback) | 设置MediaKeySession事件回调。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySession_Destroy](#oh_mediakeysession_destroy) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin) | MediaKeySession资源销毁。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetMediaKeySystemName](#oh_mediakeysystem_getmediakeysystemname) (const char \*uuid, unsigned char \*\*name, int32_t \*nameLen) | 通过MediaKeySystem方案唯一编号获取MediaKeySystem方案名。 | 
| bool [OH_MediaKeySystem_IsSupported](#oh_mediakeysystem_issupported) (const char \*name) | 查询设备是否支持指定MediaKeySystem方案。 | 
| bool [OH_MediaKeySystem_IsSupported2](#oh_mediakeysystem_issupported2) (const char \*name, const char \*mimeType) | 查询设备是否支持指定MediaKeySystem方案、指定媒体类型。 | 
| bool [OH_MediaKeySystem_IsSupported3](#oh_mediakeysystem_issupported3) (const char \*name, const char \*mimeType, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) contentProtectionLevel) | 查询设备是否支持指定MediaKeySystem方案、指定媒体类型、指定内容保护级别。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_Create](#oh_mediakeysystem_create) (const char \*name, [MediaKeySystem](#mediakeysystem) \*\*mediaKeySystem) | 根据方案名创建一个MediaKeySystem实例。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_SetConfigurationString](#oh_mediakeysystem_setconfigurationstring) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, const char \*value) | 通过配置名设置MediaKeySystem的字符串类型配置值。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetConfigurationString](#oh_mediakeysystem_getconfigurationstring) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, char \*\*value, int32_t \*valueLen) | 通过配置名获取MediaKeySystem的字符串类型配置值。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_SetConfigurationByteArray](#oh_mediakeysystem_setconfigurationbytearray) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*value) | 通过配置名设置MediaKeySystem的字符数组类型配置值。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetConfigurationByteArray](#oh_mediakeysystem_getconfigurationbytearray) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, unsigned char \*\*value, int32_t \*valueLen) | 通过配置名获取MediaKeySystem的字符数组类型配置值。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetStatistics](#oh_mediakeysystem_getstatistics) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_Statistics](_d_r_m___statistics.md) \*\*statistics) | 获取MediaKeySystem的度量统计信息。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetMaxContentProtectionLevel](#oh_mediakeysystem_getmaxcontentprotectionlevel) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*contentProtectionLevel) | 获取MediaKeySystem支持的最大内容保护级别。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_SetMediaKeySystemCallback](#oh_mediakeysystem_setmediakeysystemcallback) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [MediaKeySystem_Callback](#mediakeysystem_callback) callback) | 设置MediaKeySystem回调监听。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_CreateMediaKeySession](#oh_mediakeysystem_createmediakeysession) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*level, [MediaKeySession](#mediakeysession) \*\*mediaKeySession) | 创建一个MediaKeySession实例。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GenerateKeySystemRequest](#oh_mediakeysystem_generatekeysystemrequest) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, unsigned char \*\*request, int32_t \*requestLen, char \*\*defaultUrl, int32_t \*defaultUrlLen) | 生成设备证书请求。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_ProcessKeySystemResponse](#oh_mediakeysystem_processkeysystemresponse) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*response) | 处理设备证书响应。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetOfflineMediaKeyIds](#oh_mediakeysystem_getofflinemediakeyids) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_MediakeyIdArray](_d_r_m___mediakey_id_array.md) \*\*mediaKeyIds) | 获取离线许可证状态。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetOfflineMediaKeyStatus](#oh_mediakeysystem_getofflinemediakeystatus) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId, [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) \*status) | 获取离线许可证状态。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_ClearOfflineMediaKeys](#oh_mediakeysystem_clearofflinemediakeys) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md) \*mediaKeyId) | 根据许可证Id清理许可证。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_GetCertificateStatus](#oh_mediakeysystem_getcertificatestatus) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_CertificateStatus](#drm_certificatestatus) \*certStatus) | 获取设备证书状态。 | 
| [Drm_ErrCode](#drm_errcode)[OH_MediaKeySystem_Destroy](#oh_mediakeysystem_destroy) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem) | 销毁MediaKeySystem实例。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| unsigned char \* [DRM_Uint8Buffer::buffer](#buffer-12) | 数组首地址 | 
| uint32_t [DRM_Uint8Buffer::bufferLen](#bufferlen-12) | 数组长度 | 
| char \* [DRM_CharBuffer::buffer](#buffer-22) | 数组首地址 | 
| uint32_t [DRM_CharBuffer::bufferLen](#bufferlen-22) | 数组长度 | 
| [DRM_CharBuffer](_d_r_m___char_buffer.md)[DRM_CharBufferPair::name](#name) | 名字 | 
| [DRM_CharBuffer](_d_r_m___char_buffer.md)[DRM_CharBufferPair::value](#value-12) | 值 | 
| [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md)[DRM_Uint8CharBufferPair::key](#key) | 名字 | 
| [DRM_CharBuffer](_d_r_m___char_buffer.md)[DRM_Uint8CharBufferPair::value](#value-22) | 值 | 
| [DRM_MediaKeyType](#drm_mediakeytype)[DRM_MediaKeyRequestInfo::type](#type-12) | 许可证类型 | 
| [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md)[DRM_MediaKeyRequestInfo::data](#data-13) | base64编码后的pssh数据 | 
| [DRM_CharBuffer](_d_r_m___char_buffer.md)[DRM_MediaKeyRequestInfo::mimeType](#mimetype) | 媒体类型 | 
| uint32_t [DRM_MediaKeyRequestInfo::optionsCount](#optionscount) | 操作数数组长度 | 
| [DRM_CharBufferPair](_d_r_m___char_buffer_pair.md)[DRM_MediaKeyRequestInfo::optionsData](#optionsdata) [0] | 操作数数组 | 
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype)[DRM_MediaKeyRequest::type](#type-22) | 许可证请求类型 | 
| [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md)[DRM_MediaKeyRequest::data](#data-23) | 许可证请求数据 | 
| [DRM_CharBuffer](_d_r_m___char_buffer.md)[DRM_MediaKeyRequest::defaultUrl](#defaulturl) | 许可证服务器URL | 
| uint32_t [DRM_Statistics::statisticsCount](#statisticscount) | 度量信息数组长度 | 
| [DRM_CharBufferPair](_d_r_m___char_buffer_pair.md)[DRM_Statistics::info](#info) [0] | 度量信息数组 | 
| uint32_t [DRM_MediakeyIdArray::mediaKeyIdCount](#mediakeyidcount) | 许可证Id数组长度 | 
| [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md)[DRM_MediakeyIdArray::mediaKeyIds](#mediakeyids) [0] | 许可证Id数组 | 
| uint32_t [DRM_KeysInfo::keysCount](#keyscount) | 密钥信息数组长度 | 
| [DRM_Uint8CharBufferPair](_d_r_m___uint8_char_buffer_pair.md)[DRM_KeysInfo::keysInfo](#keysinfo) [0] | 密钥信息数组 | 
| uint32_t [DRM_MediaKeyDescription::mediaKeyCount](#mediakeycount) | 许可证信息数组长度 | 
| [DRM_CharBufferPair](_d_r_m___char_buffer_pair.md)[DRM_MediaKeyDescription::description](#description) [0] | 许可证信息数组 | 
| char [DRM_PsshInfo::uuid](#uuid) [[DRM_UUID_LEN](#drm_uuid_len)] | DRM插件类型名 | 
| uint32_t [DRM_PsshInfo::dataLen](#datalen) | PSSH数据长度 | 
| unsigned char \* [DRM_PsshInfo::data](#data-33) | PSSH数据 | 
| uint32_t [DRM_MediaKeySystemInfo::psshCount](#psshcount) | PSSH信息数组长度 | 
| [DRM_PsshInfo](_d_r_m___pssh_info.md)[DRM_MediaKeySystemInfo::psshInfo](#psshinfo) [0] | PSSH信息数组 | 
| [MediaKeySession_EventCallback](#mediakeysession_eventcallback)[MediaKeySession_Callback::eventCallback](#eventcallback) | KeySession回调事件，如许可证过期。 | 
| [MediaKeySession_KeyChangeCallback](#mediakeysession_keychangecallback)[MediaKeySession_Callback::keyChangeCallback](#keychangecallback) | 密钥变化事件触发的keyChange事件。 | 


## 宏定义说明


### DRM_UUID_LEN

```
#define DRM_UUID_LEN   16
```

**描述**

DRM插件类型名。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


## 类型定义说明


### DRM_CertificateStatus

```
typedef enum DRM_CertificateStatusDRM_CertificateStatus
```

**描述**

设备证书状态类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_CharBuffer

```
typedef struct DRM_CharBufferDRM_CharBuffer
```

**描述**

DRM 字符数组类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_CharBufferPair

```
typedef struct DRM_CharBufferPairDRM_CharBufferPair
```

**描述**

字符数组类型的名值对。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_ContentProtectionLevel

```
typedef enum DRM_ContentProtectionLevelDRM_ContentProtectionLevel
```

**描述**

内容保护级别类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### Drm_ErrCode

```
typedef enum Drm_ErrCodeDrm_ErrCode
```

**描述**

DRM错误码。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_KeysInfo

```
typedef struct DRM_KeysInfoDRM_KeysInfo
```

**描述**

密钥信息。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_ListenerType

```
typedef enum DRM_ListenerTypeDRM_ListenerType
```

**描述**

监听类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core.

**起始版本：** 11


### DRM_MediaKeyDescription

```
typedef struct DRM_MediaKeyDescriptionDRM_MediaKeyDescription
```

**描述**

在线许可证描述信息。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediakeyIdArray

```
typedef struct DRM_MediakeyIdArrayDRM_MediakeyIdArray
```

**描述**

离线许可证Id数组。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediaKeyRequest

```
typedef struct DRM_MediaKeyRequestDRM_MediaKeyRequest
```

**描述**

许可证请求类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediaKeyRequestInfo

```
typedef struct DRM_MediaKeyRequestInfoDRM_MediaKeyRequestInfo
```

**描述**

许可证请求参数类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediaKeyRequestType

```
typedef enum DRM_MediaKeyRequestTypeDRM_MediaKeyRequestType
```

**描述**

许可证请求类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediaKeyStatus

```
typedef enum DRM_MediaKeyStatusDRM_MediaKeyStatus
```

**描述**

在线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediaKeySystemInfoCallback

```
typedef void (*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo* mediaKeySystemInfo)
```

**描述**

MeidiaKeySystem函数指针类型。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystemInfo | 密钥信息。 | 


### DRM_MediaKeySystemInfo

```
typedef struct DRM_MediaKeySystemInfoDRM_MediaKeySystemInfo
```

**描述**

从媒体源获取的DRM信息。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_MediaKeyType

```
typedef enum DRM_MediaKeyTypeDRM_MediaKeyType
```

**描述**

许可证类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_OfflineMediaKeyStatus

```
typedef enum DRM_OfflineMediaKeyStatusDRM_OfflineMediaKeyStatus
```

**描述**

离线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_PsshInfo

```
typedef struct DRM_PsshInfoDRM_PsshInfo
```

**描述**

DRM Pssh信息。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_Statistics

```
typedef struct DRM_StatisticsDRM_Statistics
```

**描述**

DRM度量统计信息。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_Uint8Buffer

```
typedef struct DRM_Uint8BufferDRM_Uint8Buffer
```

**描述**

DRM uint_8 数组类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### DRM_Uint8CharBufferPair

```
typedef struct DRM_Uint8CharBufferPairDRM_Uint8CharBufferPair
```

**描述**

整形数组类型的名值对。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### MediaKeySession

```
typedef struct MediaKeySessionMediaKeySession
```

**描述**

MediaKeySession结构体。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### MediaKeySession_Callback

```
typedef struct MediaKeySession_CallbackMediaKeySession_Callback
```

**描述**

MediaKeySession回调结构体, 用来监听密钥过期、密钥变化等事件。

**起始版本：** 11


### MediaKeySession_EventCallback

```
typedef Drm_ErrCode(* MediaKeySession_EventCallback) (DRM_ListenerType eventType, DRM_Uint8CharBufferPair *eventInfo)
```

**描述**

事件触发时将调用的回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventType | 事件类型。 | 
| eventInfo | 从MediaKeySystem中获取的事件信息。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### MediaKeySession_KeyChangeCallback

```
typedef Drm_ErrCode(* MediaKeySession_KeyChangeCallback) (DRM_KeysInfo *keysInfo, bool newKeysAvailable)
```

**描述**

注册监听，监听密钥变化。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keysInfo | 密钥信息。 | 
| newKeysAvailable | 新密钥释放可用。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### MediaKeySystem

```
typedef struct MediaKeySystemMediaKeySystem
```

**描述**

MediaKeySystem结构体。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11


### MediaKeySystem_Callback

```
typedef Drm_ErrCode(* MediaKeySystem_Callback) (DRM_ListenerType eventType, DRM_Uint8CharBufferPair *eventInfo)
```

**描述**

事件触发时将调用的回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| eventType | 事件类型。 | 
| eventInfo | MediaKeySystem获取到的事件信息。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


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
| CERT_STATUS_INVALID | 无效设备证书 | 
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
| DRM_ERR_NO_MEMORY | 内存不足。 | 
| DRM_ERR_OPERATION_NOT_PERMITTED | 不支持的操作。 | 
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


### DRM_ListenerType

```
enum DRM_ListenerType
```

**描述**

监听类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core.

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| LISTENER_DRM_EVENT | DRM基础事件 | 
| LISTENER_PROVISION_REQUIRED | 设备证书请求事件 | 
| LISTENER_KEY_REQUIRED | 密钥请求事件 | 
| LISTENER_KEY_EXPIRED | 密钥过期事件 | 
| LISTENER_VENDOR_DEFINED | 第三方定义事件 | 
| LISTENER_EXPIRATION_UPDATE | 密钥过期更新事件 | 


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


### DRM_MediaKeyStatus

```
enum DRM_MediaKeyStatus
```

**描述**

在线许可证状态。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_KEY_STATUS_OK | 可用状态 | 
| MEDIA_KEY_STATUS_UNAVAILABLE | 许可证不存在 | 


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
Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus (MediaKeySession * mediaKeySessoin, DRM_MediaKeyDescription ** mediaKeyDescription )
```

**描述**

检查许可证状态.

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| mediaKeyDescription | 许可证状态描述。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_ClearMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_ClearMediaKeys (MediaKeySession * mediaKeySessoin)
```

**描述**

清除当前会话的许可证 .

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_Destroy()

```
Drm_ErrCode OH_MediaKeySession_Destroy (MediaKeySession * mediaKeySessoin)
```

**描述**

MediaKeySession资源销毁.

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_GenerateMediaKeyRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateMediaKeyRequest (MediaKeySession * mediaKeySession, DRM_MediaKeyRequestInfo * info, DRM_MediaKeyRequest ** mediaKeyRequest )
```

**描述**

生成许可证请求。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| info | 许可证请求信息。 | 
| mediaKeyRequest | 许可证请求 | 

**返回：**

Drm_ErrCode.


### OH_MediaKeySession_GenerateOfflineReleaseRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest (MediaKeySession * mediaKeySessoin, DRM_Uint8Buffer * mediaKeyId, unsigned char ** releaseRequest, int32_t * releaseRequestLen )
```

**描述**

生成离线许可证释放请求。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| mediaKeyId | 许可证Id。 | 
| releaseRequest | 离线许可证请求。 | 
| releaseRequestLen | 离线许可证请求长度。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_GetContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySession_GetContentProtectionLevel (MediaKeySession * mediaKeySessoin, DRM_ContentProtectionLevel * contentProtectionLevel )
```

**描述**

获取当前会话的内容保护级别。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| contentProtectionLevel | 内容保护级别。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_ProcessMediaKeyResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse (MediaKeySession * keySession, DRM_Uint8Buffer * response, unsigned char ** mediaKeyId, int32_t * mediaKeyIdLen )
```

**描述**

处理许可证响应。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| response | 许可证响应。 | 
| mediaKeyId | 许可证Id。 | 
| mediaKeyIdLen | 许可证Id长度。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_ProcessOfflineReleaseResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse (MediaKeySession * mediaKeySessoin, DRM_Uint8Buffer * mediaKeyId, DRM_Uint8Buffer * releaseReponse )
```

**描述**

处理离线许可证释放响应。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| mediaKeyId | 许可证Id。 | 
| releaseReponse | 许可证响应。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_RequireSecureDecoderModule()

```
Drm_ErrCode OH_MediaKeySession_RequireSecureDecoderModule (MediaKeySession * mediaKeySessoin, const char * mimeType, bool * status )
```

**描述**

查询是否需要安全解码.

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| mimeType | 媒体类型。 | 
| status | 是否安全解码。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_RestoreOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_RestoreOfflineMediaKeys (MediaKeySession * mediaKeySessoin, DRM_Uint8Buffer * mediaKeyId )
```

**描述**

根据许可证ID恢复对应许可证状态。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| mediaKeyId | 许可证Id。 | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySession_SetMediaKeySessionCallback()

```
Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback (MediaKeySession * mediaKeySessoin, MediaKeySession_Callback * callback )
```

**描述**

设置MediaKeySession事件回调。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySession | mediaKeySession实例。 | 
| callback | 设置到MediaKeySession中的回调. | 

**返回：**

参数检查错误返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_ClearOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySystem_ClearOfflineMediaKeys (MediaKeySystem * mediaKeySystem, DRM_Uint8Buffer * mediaKeyId )
```

**描述**

根据许可证Id清理许可证.

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| mediaKeyId | 许可证Id. | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_Create()

```
Drm_ErrCode OH_MediaKeySystem_Create (const char * name, MediaKeySystem ** mediaKeySystem )
```

**描述**

根据方案名创建一个MediaKeySystem实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | MediaKeySystem方案名 | 
| mediaKeySystem | MediaKeySystem实例。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。 达到MediaKeySession实例最大数量返回DRM_ERR_MAX_SYSTEM_NUM_REACHED。


### OH_MediaKeySystem_CreateMediaKeySession()

```
Drm_ErrCode OH_MediaKeySystem_CreateMediaKeySession (MediaKeySystem * mediaKeySystem, DRM_ContentProtectionLevel * level, MediaKeySession ** mediaKeySession )
```

**描述**

创建一个MediaKeySession实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 用来创建MediaKeySession实例的MediaKeySystem实例。 | 
| level | 内容保护级别。 | 
| mediaKeySession | MediaKeySession实例。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。 达到MediaKeySession实例最大数量返回DRM_ERR_MAX_SESSION_NUM_REACHED。


### OH_MediaKeySystem_Destroy()

```
Drm_ErrCode OH_MediaKeySystem_Destroy (MediaKeySystem * mediaKeySystem)
```

**描述**

销毁MediaKeySystem实例。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | 被销毁的MediaKeySystem实例。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GenerateKeySystemRequest()

```
Drm_ErrCode OH_MediaKeySystem_GenerateKeySystemRequest (MediaKeySystem * mediaKeySystem, unsigned char ** request, int32_t * requestLen, char ** defaultUrl, int32_t * defaultUrlLen )
```

**描述**

生成设备证书请求。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| request | Provision请求数据。 | 
| requestLen | Provision请求长度。 | 
| defaultUrl | Provision服务器URL。 | 
| defaultUrlLen | Provision服务器URL长度。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetCertificateStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetCertificateStatus (MediaKeySystem * mediaKeySystem, DRM_CertificateStatus * certStatus )
```

**描述**

获取设备证书状态.

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| certStatus | 获取的设备证书状态。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationByteArray (MediaKeySystem * mediaKeySystem, const char * configName, unsigned char ** value, int32_t * valueLen )
```

**描述**

通过配置名获取MediaKeySystem的字符数组类型配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| configName | 字符串类型配置名。 | 
| value | 字节数组形式配置值。 | 
| valueLen | 字节数组形式配置值长度。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationString (MediaKeySystem * mediaKeySystem, const char * configName, char ** value, int32_t * valueLen )
```

**描述**

通过配置名获取MediaKeySystem的字符串类型配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| configName | 字符串类型配置名。 | 
| value | 字符串形式配置值。 | 
| valueLen | 字符串形式配置值长度。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetMaxContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySystem_GetMaxContentProtectionLevel (MediaKeySystem * mediaKeySystem, DRM_ContentProtectionLevel * contentProtectionLevel )
```

**描述**

获取MediaKeySystem支持的最大内容保护级别。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| contentProtectionLevel | 内容保护级别。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetMediaKeySystemName()

```
Drm_ErrCode OH_MediaKeySystem_GetMediaKeySystemName (const char * uuid, unsigned char ** name, int32_t * nameLen )
```

**描述**

通过MediaKeySystem方案唯一编号获取MediaKeySystem方案名。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uuid | MediaKeySystem方案唯一编号。 | 
| name | MediaKeySystem方案名。 | 
| nameLen | MediaKeySystem方案名长度。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetOfflineMediaKeyIds()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyIds (MediaKeySystem * mediaKeySystem, DRM_MediakeyIdArray ** mediaKeyIds )
```

**描述**

获取离线许可证状态。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| mediaKeyIds | 离线许可证Id。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetOfflineMediaKeyStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyStatus (MediaKeySystem * mediaKeySystem, DRM_Uint8Buffer * mediaKeyId, DRM_OfflineMediaKeyStatus * status )
```

**描述**

获取离线许可证状态。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| mediaKeyId | 许可证Id。 | 
| status | 获取到的许可证状态。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_GetStatistics()

```
Drm_ErrCode OH_MediaKeySystem_GetStatistics (MediaKeySystem * mediaKeySystem, DRM_Statistics ** statistics )
```

**描述**

获取MediaKeySystem的度量统计信息。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| statistics | 度量统计信息。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_IsSupported()

```
bool OH_MediaKeySystem_IsSupported (const char * name)
```

**描述**

查询设备是否支持指定MediaKeySystem方案。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | MediaKeySystem方案名。 | 

**返回：**

支持与否。


### OH_MediaKeySystem_IsSupported2()

```
bool OH_MediaKeySystem_IsSupported2 (const char * name, const char * mimeType )
```

**描述**

查询设备是否支持指定MediaKeySystem方案、指定媒体类型。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | MediaKeySystem方案名。 | 
| mimeType | 媒体类型。 | 

**返回：**

支持与否。


### OH_MediaKeySystem_IsSupported3()

```
bool OH_MediaKeySystem_IsSupported3 (const char * name, const char * mimeType, DRM_ContentProtectionLevel contentProtectionLevel )
```

**描述**

查询设备是否支持指定MediaKeySystem方案、指定媒体类型、指定内容保护级别。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | MediaKeySystem方案名。 | 
| mimeType | 媒体类型。 | 
| contentProtectionLevel | 内容保护级别。 | 

**返回：**

支持与否。


### OH_MediaKeySystem_ProcessKeySystemResponse()

```
Drm_ErrCode OH_MediaKeySystem_ProcessKeySystemResponse (MediaKeySystem * mediaKeySystem, DRM_Uint8Buffer * response )
```

**描述**

处理设备证书响应。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| response | 设备证书响应。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_SetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationByteArray (MediaKeySystem * mediaKeySystem, const char * configName, DRM_Uint8Buffer * value )
```

**描述**

通过配置名设置MediaKeySystem的字符数组类型配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| configName | 字符串类型配置名。 | 
| value | 字节数组形式配置值。 | 
| valueLen | 字节数组形式配置值长度。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_SetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationString (MediaKeySystem * mediaKeySystem, const char * configName, const char * value )
```

**描述**

通过配置名设置MediaKeySystem的字符串类型配置值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| configName | 字符串类型配置名。 | 
| value | 字符串形式配置值。 | 
| valueLen | 字符串形式配置值长度。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


### OH_MediaKeySystem_SetMediaKeySystemCallback()

```
Drm_ErrCode OH_MediaKeySystem_SetMediaKeySystemCallback (MediaKeySystem * mediaKeySystem, MediaKeySystem_Callback callback )
```

**描述**

设置MediaKeySystem回调监听。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaKeySystem | MediaKeySystem实例。 | 
| callback | 设置到MediaKeySystem中的回调函数。 | 

**返回：**

参数检查失败返回DRM_ERR_INVALID_VAL, 调用成功返回DRM_ERR_OK。


## 变量说明


### buffer [1/2]

```
unsigned char* DRM_Uint8Buffer::buffer
```

**描述**

数组首地址


### buffer [2/2]

```
char* DRM_CharBuffer::buffer
```

**描述**

数组首地址


### bufferLen [1/2]

```
uint32_t DRM_Uint8Buffer::bufferLen
```

**描述**

数组长度


### bufferLen [2/2]

```
uint32_t DRM_CharBuffer::bufferLen
```

**描述**

数组长度


### data [1/3]

```
DRM_Uint8Buffer DRM_MediaKeyRequestInfo::data
```

**描述**

base64编码后的pssh数据


### data [2/3]

```
DRM_Uint8Buffer DRM_MediaKeyRequest::data
```

**描述**

许可证请求数据


### data [3/3]

```
unsigned char* DRM_PsshInfo::data
```

**描述**

PSSH数据


### dataLen

```
uint32_t DRM_PsshInfo::dataLen
```

**描述**

PSSH数据长度


### defaultUrl

```
DRM_CharBuffer DRM_MediaKeyRequest::defaultUrl
```

**描述**

许可证服务器URL


### description

```
DRM_CharBufferPair DRM_MediaKeyDescription::description[0]
```

**描述**

许可证信息数组


### eventCallback

```
MediaKeySession_EventCallback MediaKeySession_Callback::eventCallback
```

**描述**

KeySession回调事件，如许可证过期。


### info

```
DRM_CharBufferPair DRM_Statistics::info[0]
```

**描述**

度量信息数组


### key

```
DRM_Uint8Buffer DRM_Uint8CharBufferPair::key
```

**描述**

名字


### keyChangeCallback

```
MediaKeySession_KeyChangeCallback MediaKeySession_Callback::keyChangeCallback
```

**描述**

密钥变化事件触发的keyChange事件。


### keysCount

```
uint32_t DRM_KeysInfo::keysCount
```

**描述**

密钥信息数组长度


### keysInfo

```
DRM_Uint8CharBufferPair DRM_KeysInfo::keysInfo[0]
```

**描述**

密钥信息数组


### mediaKeyCount

```
uint32_t DRM_MediaKeyDescription::mediaKeyCount
```

**描述**

许可证信息数组长度


### mediaKeyIdCount

```
uint32_t DRM_MediakeyIdArray::mediaKeyIdCount
```

**描述**

许可证Id数组长度


### mediaKeyIds

```
DRM_Uint8Buffer DRM_MediakeyIdArray::mediaKeyIds[0]
```

**描述**

许可证Id数组


### mimeType

```
DRM_CharBuffer DRM_MediaKeyRequestInfo::mimeType
```

**描述**

媒体类型


### name

```
DRM_CharBuffer DRM_CharBufferPair::name
```

**描述**

名字


### optionsCount

```
uint32_t DRM_MediaKeyRequestInfo::optionsCount
```

**描述**

操作数数组长度


### optionsData

```
DRM_CharBufferPair DRM_MediaKeyRequestInfo::optionsData[0]
```

**描述**

操作数数组


### psshCount

```
uint32_t DRM_MediaKeySystemInfo::psshCount
```

**描述**

PSSH信息数组长度


### psshInfo

```
DRM_PsshInfo DRM_MediaKeySystemInfo::psshInfo[0]
```

**描述**

PSSH信息数组


### statisticsCount

```
uint32_t DRM_Statistics::statisticsCount
```

**描述**

度量信息数组长度


### type [1/2]

```
DRM_MediaKeyType DRM_MediaKeyRequestInfo::type
```

**描述**

许可证类型


### type [2/2]

```
DRM_MediaKeyRequestType DRM_MediaKeyRequest::type
```

**描述**

许可证请求类型


### uuid

```
char DRM_PsshInfo::uuid[DRM_UUID_LEN]
```

**描述**

DRM插件类型名


### value [1/2]

```
DRM_CharBuffer DRM_CharBufferPair::value
```

**描述**

值


### value [2/2]

```
DRM_CharBuffer DRM_Uint8CharBufferPair::value
```

**描述**

值

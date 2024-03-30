# Drm


## Overview

The Digital Rights Management (DRM) module provides APIs to implement digital rights protection.

**Since**: 11


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_drm_common.h](native__drm__common_8h.md) | Declares the DRM data types.<br>**File to include**: &lt;multimedia/drm_framework/native_drm_common.h&gt;<br>**Library**: libnative_drm.z.so| 
| [native_drm_err.h](native__drm__err_8h.md) | Declares the DRM error codes.<br>**File to include**: &lt;multimedia/drm_framework/native_drm_err.h&gt;<br>**Library**: libnative_drm.z.so| 
| [native_mediakeysession.h](native__mediakeysession_8h.md) | Declares the **MediaKeySession** API.<br>**File to include**: &lt;multimedia/drm_framework/native_mediakeysession.h&gt;<br>**Library**: libnative_drm.z.so| 
| [native_mediakeysystem.h](native__mediakeysystem_8h.md) | Declares the **MediaKeySystem** API.<br>**File to include**: &lt;multimedia/drm_framework/native_mediakeysystem.h&gt;<br>**Library**: libnative_drm.z.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) | Defines the information about a media key request.| 
| struct&nbsp;&nbsp;[DRM_MediaKeyRequest](_d_r_m___media_key_request.md) | Defines a media key request.| 
| struct&nbsp;&nbsp;[DRM_Statistics](_d_r_m___statistics.md) | Defines the statistics information about a media key system.| 
| struct&nbsp;&nbsp;[DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) | Defines an array holding the IDs of offline media keys.| 
| struct&nbsp;&nbsp;[DRM_KeysInfo](_d_r_m___keys_info.md) | Defines the information about media keys.| 
| struct&nbsp;&nbsp;[DRM_MediaKeyStatus](_d_r_m___media_key_status.md) | Defines the media key status.| 
| struct&nbsp;&nbsp;[DRM_PsshInfo](_d_r_m___pssh_info.md) | Defines the Protection Scheme Specific Header (PSSH) information of the UUID.| 
| struct&nbsp;&nbsp;[DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) | Defines the media key system information obtained from a media source.| 
| struct&nbsp;&nbsp;[MediaKeySession_Callback](_media_key_session___callback.md) | Defines the callback used to listen for events such as media key expiry or change.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](#max_media_key_request_option_count)&nbsp;&nbsp;&nbsp;16 | Defines the maximum number of options in a media key request.| 
| [MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](#max_media_key_request_option_name_len)&nbsp;&nbsp;&nbsp;64 | Defines the maximum length of an option name in a media key request.| 
| [MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](#max_media_key_request_option_data_len)&nbsp;&nbsp;&nbsp;128 | Defines the maximum length of option data in a media key request.| 
| [MAX_INIT_DATA_LEN](#max_init_data_len)&nbsp;&nbsp;&nbsp;2048 | Defines the maximum length of data in an initial request.| 
| [MAX_MIMETYPE_LEN](#max_mimetype_len)&nbsp;&nbsp;&nbsp;64 | Defines the maximum length of a MIME type.| 
| [MAX_MEDIA_KEY_REQUEST_DATA_LEN](#max_media_key_request_data_len)&nbsp;&nbsp;&nbsp;8192 | Defines the maximum length of a media key request.| 
| [MAX_DEFAULT_URL_LEN](#max_default_url_len)&nbsp;&nbsp;&nbsp;2048 | Defines the maximum length of a URL.| 
| [MAX_STATISTICS_COUNT](#max_statistics_count)&nbsp;&nbsp;&nbsp;10 | Defines the maximum number of statistical items.| 
| [MAX_STATISTICS_NAME_LEN](#max_statistics_name_len)&nbsp;&nbsp;&nbsp;64 | Defines the maximum length of a statistical item name.| 
| [MAX_STATISTICS_BUFFER_LEN](#max_statistics_buffer_len)&nbsp;&nbsp;&nbsp;256 | Defines the maximum length of a statistical item buffer.| 
| [MAX_OFFLINE_MEDIA_KEY_ID_COUNT](#max_offline_media_key_id_count)&nbsp;&nbsp;&nbsp;512 | Defines the maximum number of offline media key IDs.| 
| [MAX_OFFLINE_MEDIA_KEY_ID_LEN](#max_offline_media_key_id_len)&nbsp;&nbsp;&nbsp;64 | Defines the maximum length of an offline media key ID.| 
| [MAX_KEY_INFO_COUNT](#max_key_info_count)&nbsp;&nbsp;&nbsp;64 | Defines the maximum number of pieces of media key information.| 
| [MAX_KEY_ID_LEN](#max_key_id_len)&nbsp;&nbsp;&nbsp;16 | Defines the maximum length of a media key ID.| 
| [MAX_KEY_STATUS_VALUE_LEN](#max_key_status_value_len)&nbsp;&nbsp;&nbsp;128 | Defines the maximum length of a key status value.| 
| [MAX_MEDIA_KEY_STATUS_COUNT](#max_media_key_status_count)&nbsp;&nbsp;&nbsp;64 | Defines the maximum number of media key statuses.| 
| [MAX_MEDIA_KEY_STATUS_NAME_LEN](#max_media_key_status_name_len)&nbsp;&nbsp;&nbsp;64 | Defines the maximum length of a media key status name.| 
| [MAX_MEDIA_KEY_STATUS_VALUE_LEN](#max_media_key_status_value_len)&nbsp;&nbsp;&nbsp;256 | Defines the maximum length of a media key status value.| 
| [DRM_UUID_LEN](#drm_uuid_len)&nbsp;&nbsp;&nbsp;16 | Defines the UUID length.| 
| [MAX_PSSH_DATA_LEN](#max_pssh_data_len)&nbsp;&nbsp;&nbsp;2048 | Defines the maximum length of PSSH data.| 
| [MAX_PSSH_INFO_COUNT](#max_pssh_info_count)&nbsp;&nbsp;&nbsp;8 | Defines the maximum number of pieces of PSSH information.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [DRM_EventType](#drm_eventtype-1) [DRM_EventType](#drm_eventtype) | Defines an enum that enumerates the types of events that can be subscribed to.| 
| typedef enum [DRM_ContentProtectionLevel](#drm_contentprotectionlevel-1) [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) | Defines an enum that enumerates the content protection levels.| 
| typedef enum [DRM_MediaKeyType](#drm_mediakeytype-1) [DRM_MediaKeyType](#drm_mediakeytype) | Defines an enum that enumerates the media key types.| 
| typedef enum [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype-1) [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) | Defines an enum that enumerates the types of requests for media keys.| 
| typedef enum [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus-1) [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) | Defines an enum that enumerates the statuses of offline media keys.| 
| typedef enum [DRM_CertificateStatus](#drm_certificatestatus-1) [DRM_CertificateStatus](#drm_certificatestatus) | Defines an enum that enumerates the certificate statuses.| 
| typedef struct [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) [DRM_MediaKeyRequestInfo](#drm_mediakeyrequestinfo) | Defines the information about a media key request.| 
| typedef struct [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) [DRM_MediaKeyRequest](#drm_mediakeyrequest) | Defines a media key request.| 
| typedef struct [DRM_Statistics](_d_r_m___statistics.md) [DRM_Statistics](#drm_statistics) | Defines the statistics information about a media key system.| 
| typedef struct [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) [DRM_OfflineMediakeyIdArray](#drm_offlinemediakeyidarray) | Defines an array holding the IDs of offline media keys.| 
| typedef struct [DRM_KeysInfo](_d_r_m___keys_info.md) [DRM_KeysInfo](#drm_keysinfo) | Defines the information about media keys.| 
| typedef struct [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) [DRM_MediaKeyStatus](#drm_mediakeystatus) | Defines the media key status.| 
| typedef struct [DRM_PsshInfo](_d_r_m___pssh_info.md) [DRM_PsshInfo](#drm_psshinfo) | Defines the PSSH information of the UUID.| 
| typedef struct [DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) [DRM_MediaKeySystemInfo](#drm_mediakeysysteminfo) | Defines the media key system information obtained from a media source.| 
| typedef void(\* [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)) ([DRM_MediaKeySystemInfo](_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | Defines the callback used to obtain media key system information from a media source.| 
| typedef struct [MediaKeySystem](#mediakeysystem) [MediaKeySystem](#mediakeysystem) | Defines a media key system.| 
| typedef struct [MediaKeySession](#mediakeysession) [MediaKeySession](#mediakeysession) | Defines a media key session.| 
| typedef enum [Drm_ErrCode](#drm_errcode-1) [Drm_ErrCode](#drm_errcode) | Defines an enum that enumerates the DRM error codes.| 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySession_EventCallback](#mediakeysession_eventcallback)) ([DRM_EventType](#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | Defines the callback that is invoked when a DRM event is triggered.| 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySession_KeyChangeCallback](#mediakeysession_keychangecallback)) ([DRM_KeysInfo](_d_r_m___keys_info.md) \*keysInfo, bool newKeysAvailable) | Defines the callback that is invoked when the key is changed.| 
| typedef struct [MediaKeySession_Callback](_media_key_session___callback.md) [MediaKeySession_Callback](#mediakeysession_callback) | Defines the callback used to listen for events such as media key expiry or change.| 
| typedef [Drm_ErrCode](#drm_errcode)(\* [MediaKeySystem_Callback](#mediakeysystem_callback)) ([DRM_EventType](#drm_eventtype) eventType, uint8_t \*info, int32_t infoLen, char \*extra) | Defines the callback that is invoked when a DRM event is triggered.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [DRM_EventType](#drm_eventtype-1) {<br>EVENT_DRM_BASE = 200, <br>EVENT_PROVISION_REQUIRED = 201, <br>EVENT_KEY_REQUIRED = 202, <br>EVENT_KEY_EXPIRED = 203,<br>EVENT_VENDOR_DEFINED = 204, <br>EVENT_EXPIRATION_UPDATE = 206<br>} | Enumerates the types of events that can be subscribed to.| 
| [DRM_ContentProtectionLevel](#drm_contentprotectionlevel-1) {<br>CONTENT_PROTECTION_LEVEL_UNKNOWN = 0, <br>CONTENT_PROTECTION_LEVEL_SW_CRYPTO, <br>CONTENT_PROTECTION_LEVEL_HW_CRYPTO, <br>CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO,<br>CONTENT_PROTECTION_LEVEL_MAX<br>} | Enumerates the content protection levels.| 
| [DRM_MediaKeyType](#drm_mediakeytype-1) { <br>MEDIA_KEY_TYPE_OFFLINE = 0, <br>MEDIA_KEY_TYPE_ONLINE <br>} | Enumerates the media key types.| 
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype-1) {<br>MEDIA_KEY_REQUEST_TYPE_UNKNOWN = 0, <br>MEDIA_KEY_REQUEST_TYPE_INITIAL, <br>MEDIA_KEY_REQUEST_TYPE_RENEWAL, <br>MEDIA_KEY_REQUEST_TYPE_RELEASE,<br>MEDIA_KEY_REQUEST_TYPE_NONE, <br>MEDIA_KEY_REQUEST_TYPE_UPDATE<br>} | Enumerates the types of requests for media keys.| 
| [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus-1) { <br>OFFLINE_MEDIA_KEY_STATUS_UNKNOWN = 0, <br>OFFLINE_MEDIA_KEY_STATUS_USABLE, <br>OFFLINE_MEDIA_KEY_STATUS_INACTIVE } | Enumerates the statuses of offline media keys.| 
| [DRM_CertificateStatus](#drm_certificatestatus-1) {<br>CERT_STATUS_PROVISIONED = 0, <br>CERT_STATUS_NOT_PROVISIONED, <br>CERT_STATUS_EXPIRED, <br>CERT_STATUS_INVALID,<br>CERT_STATUS_UNAVAILABLE<br>} | Enumerates the certificate statuses.| 
| [Drm_ErrCode](#drm_errcode-1) {<br>DRM_ERR_OK = 0, <br>DRM_CAPI_ERR_BASE = 24700500, <br>DRM_ERR_NO_MEMORY = DRM_CAPI_ERR_BASE + 1, <br>DRM_ERR_OPERATION_NOT_PERMITTED = DRM_CAPI_ERR_BASE + 2,<br>DRM_ERR_INVALID_VAL = DRM_CAPI_ERR_BASE + 3, <br>DRM_ERR_IO = DRM_CAPI_ERR_BASE + 4, <br>DRM_ERR_TIMEOUT = DRM_CAPI_ERR_BASE + 5, <br>DRM_ERR_UNKNOWN = DRM_CAPI_ERR_BASE + 6,<br>DRM_ERR_SERVICE_DIED = DRM_CAPI_ERR_BASE + 7, <br>DRM_ERR_INVALID_STATE = DRM_CAPI_ERR_BASE + 8, <br>DRM_ERR_UNSUPPORTED = DRM_CAPI_ERR_BASE + 9, <br>DRM_ERR_MAX_SYSTEM_NUM_REACHED = DRM_CAPI_ERR_BASE + 10,<br>DRM_ERR_MAX_SESSION_NUM_REACHED = DRM_CAPI_ERR_BASE + 11, <br>DRM_ERR_EXTEND_START = DRM_CAPI_ERR_BASE + 100<br>} | Enumerates the DRM error codes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_GenerateMediaKeyRequest](#oh_mediakeysession_generatemediakeyrequest) ([MediaKeySession](#mediakeysession) \*mediaKeySession, [DRM_MediaKeyRequestInfo](_d_r_m___media_key_request_info.md) \*info, [DRM_MediaKeyRequest](_d_r_m___media_key_request.md) \*mediaKeyRequest) | Generates a media key request.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_ProcessMediaKeyResponse](#oh_mediakeysession_processmediakeyresponse) ([MediaKeySession](#mediakeysession) \*mediaKeySession, uint8_t \*response, int32_t responseLen, uint8_t \*offlineMediaKeyId, int32_t \*offlineMediaKeyIdLen) | Processes a response to the media key request.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_CheckMediaKeyStatus](#oh_mediakeysession_checkmediakeystatus) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_MediaKeyStatus](_d_r_m___media_key_status.md) \*mediaKeyStatus) | Checks the status of media keys.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_ClearMediaKeys](#oh_mediakeysession_clearmediakeys) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin) | Clears media keys.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_GenerateOfflineReleaseRequest](#oh_mediakeysession_generateofflinereleaserequest) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseRequest, int32_t \*releaseRequestLen) | Generates a request to release offline media keys.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_ProcessOfflineReleaseResponse](#oh_mediakeysession_processofflinereleaseresponse) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t \*releaseReponse, int32_t releaseReponseLen) | Processes a response to a request for releasing offline media keys.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_RestoreOfflineMediaKeys](#oh_mediakeysession_restoreofflinemediakeys) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | Restores offline media keys.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_GetContentProtectionLevel](#oh_mediakeysession_getcontentprotectionlevel) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*contentProtectionLevel) | Obtains the content protection level of a media key session.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_RequireSecureDecoderModule](#oh_mediakeysession_requiresecuredecodermodule) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, const char \*mimeType, bool \*status) | Checks whether secure decoding is required for encrypted content.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_SetMediaKeySessionCallback](#oh_mediakeysession_setmediakeysessioncallback) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin, [MediaKeySession_Callback](_media_key_session___callback.md) \*callback) | Sets a media key session event callback.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySession_Destroy](#oh_mediakeysession_destroy) ([MediaKeySession](#mediakeysession) \*mediaKeySessoin) | Releases the media key session resources.| 
| bool [OH_MediaKeySystem_IsSupported](#oh_mediakeysystem_issupported) (const char \*name) | Checks whether a media key system is supported.| 
| bool [OH_MediaKeySystem_IsSupported2](#oh_mediakeysystem_issupported2) (const char \*name, const char \*mimeType) | Checks whether a media key system is supported.| 
| bool [OH_MediaKeySystem_IsSupported3](#oh_mediakeysystem_issupported3) (const char \*name, const char \*mimeType, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) contentProtectionLevel) | Checks whether a media key system is supported.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_Create](#oh_mediakeysystem_create) (const char \*name, [MediaKeySystem](#mediakeysystem) \*\*mediaKeySystem) | Creates a **MediaKeySystem** instance by name.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_SetConfigurationString](#oh_mediakeysystem_setconfigurationstring) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, const char \*value) | Sets a configuration item in the form of a string for a media key system.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetConfigurationString](#oh_mediakeysystem_getconfigurationstring) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, char \*value, int32_t valueLen) | Obtains the value of a configuration item in the form of a string for a media key system.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_SetConfigurationByteArray](#oh_mediakeysystem_setconfigurationbytearray) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t valueLen) | Sets a configuration item in the form of a byte array for a media key system.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetConfigurationByteArray](#oh_mediakeysystem_getconfigurationbytearray) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, const char \*configName, uint8_t \*value, int32_t \*valueLen) | Obtains the value of a configuration item in the form of a byte array for a media key system.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetStatistics](#oh_mediakeysystem_getstatistics) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_Statistics](_d_r_m___statistics.md) \*statistics) | Obtains the statistics information about a media key system.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetMaxContentProtectionLevel](#oh_mediakeysystem_getmaxcontentprotectionlevel) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*contentProtectionLevel) | Obtains the media key system with the maximum content protection level supported by the device.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_SetMediaKeySystemCallback](#oh_mediakeysystem_setmediakeysystemcallback) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [MediaKeySystem_Callback](#mediakeysystem_callback) callback) | Sets a media key system event callback.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_CreateMediaKeySession](#oh_mediakeysystem_createmediakeysession) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_ContentProtectionLevel](#drm_contentprotectionlevel) \*level, [MediaKeySession](#mediakeysession) \*\*mediaKeySession) | Creates a **MediaKeySession** instance.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GenerateKeySystemRequest](#oh_mediakeysystem_generatekeysystemrequest) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*request, int32_t \*requestLen, char \*defaultUrl, int32_t defaultUrlLen) | Generates a media key system request to obtain a provision request.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_ProcessKeySystemResponse](#oh_mediakeysystem_processkeysystemresponse) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*response, int32_t responseLen) | Processes a response to the media key system request.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyIds](#oh_mediakeysystem_getofflinemediakeyids) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_OfflineMediakeyIdArray](_d_r_m___offline_mediakey_id_array.md) \*offlineMediaKeyIds) | Obtains the IDs of offline media keys.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetOfflineMediaKeyStatus](#oh_mediakeysystem_getofflinemediakeystatus) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen, [DRM_OfflineMediaKeyStatus](#drm_offlinemediakeystatus) \*status) | Obtains the status of offline media keys.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_ClearOfflineMediaKeys](#oh_mediakeysystem_clearofflinemediakeys) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, uint8_t \*offlineMediaKeyId, int32_t offlineMediaKeyIdLen) | Clears offline media keys by ID.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_GetCertificateStatus](#oh_mediakeysystem_getcertificatestatus) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem, [DRM_CertificateStatus](#drm_certificatestatus) \*certStatus) | Obtains the certificate status of a media key system.| 
| [Drm_ErrCode](#drm_errcode) [OH_MediaKeySystem_Destroy](#oh_mediakeysystem_destroy) ([MediaKeySystem](#mediakeysystem) \*mediaKeySystem) | Destroys a **MediaKeySystem** instance.| 


### Variables

| Name| Description| 
| -------- | -------- |
| [DRM_MediaKeyType](#drm_mediakeytype) [DRM_MediaKeyRequestInfo::type](#type-12) | Defines the key type.| 
| int32_t [DRM_MediaKeyRequestInfo::initDataLen](#initdatalen) | Defines the initial data length.| 
| uint8_t [DRM_MediaKeyRequestInfo::initData](#initdata) [[MAX_INIT_DATA_LEN](#max_init_data_len)] | Defines the initial data in PSSH format after Base64 decoding.| 
| char [DRM_MediaKeyRequestInfo::mimeType](#mimetype) [[MAX_MIMETYPE_LEN](#max_mimetype_len)] | Defines the MIME type of the media context.| 
| uint32_t [DRM_MediaKeyRequestInfo::optionsCount](#optionscount) | Defines the number of options.| 
| char [DRM_MediaKeyRequestInfo::optionName](#optionname) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](#max_media_key_request_option_name_len)] | Defines the option name set.| 
| char [DRM_MediaKeyRequestInfo::optionData](#optiondata) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](#max_media_key_request_option_data_len)] | Defines the option data set.| 
| [DRM_MediaKeyRequestType](#drm_mediakeyrequesttype) [DRM_MediaKeyRequest::type](#type-22) | Defines the type of a media key request.| 
| int32_t [DRM_MediaKeyRequest::dataLen](#datalen-12) | Defines the length of data in a media key request.| 
| uint8_t [DRM_MediaKeyRequest::data](#data-12) [[MAX_MEDIA_KEY_REQUEST_DATA_LEN](#max_media_key_request_data_len)] | Defines the data in a media key request sent to the media key server.| 
| char [DRM_MediaKeyRequest::defaultUrl](#defaulturl) [[MAX_DEFAULT_URL_LEN](#max_default_url_len)] | Defines the URL of a media key server.| 
| uint32_t [DRM_Statistics::statisticsCount](#statisticscount) | Defines the number of statistical items.| 
| char [DRM_Statistics::statisticsName](#statisticsname) [[MAX_STATISTICS_COUNT](#max_statistics_count)][[MAX_STATISTICS_NAME_LEN](#max_statistics_name_len)] | Defines the statistical item name set.| 
| char [DRM_Statistics::statisticsDescription](#statisticsdescription) [[MAX_STATISTICS_COUNT](#max_statistics_count)][[MAX_STATISTICS_BUFFER_LEN](#max_statistics_buffer_len)] | Defines the set of statistics information description.| 
| uint32_t [DRM_OfflineMediakeyIdArray::idsCount](#idscount) | Defines the number of IDs.| 
| int32_t [DRM_OfflineMediakeyIdArray::idsLen](#idslen) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](#max_offline_media_key_id_count)] | Defines the ID length set.| 
| uint8_t [DRM_OfflineMediakeyIdArray::ids](#ids) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](#max_offline_media_key_id_count)][[MAX_OFFLINE_MEDIA_KEY_ID_LEN](#max_offline_media_key_id_len)] | Defines the ID data set.| 
| uint32_t [DRM_KeysInfo::keysInfoCount](#keysinfocount) | Defines the number of keys.| 
| uint8_t [DRM_KeysInfo::keyId](#keyid) [[MAX_KEY_INFO_COUNT](#max_key_info_count)][[MAX_KEY_ID_LEN](#max_key_id_len)] | Defines the key ID set.| 
| char [DRM_KeysInfo::statusValue](#statusvalue-12) [[MAX_KEY_INFO_COUNT](#max_key_info_count)][[MAX_KEY_STATUS_VALUE_LEN](#max_key_status_value_len)] | Defines the key status value.| 
| uint32_t [DRM_MediaKeyStatus::statusCount](#statuscount) | Defines the number of media key statuses.| 
| char [DRM_MediaKeyStatus::statusName](#statusname) [[MAX_MEDIA_KEY_STATUS_COUNT](#max_media_key_status_count)][[MAX_MEDIA_KEY_STATUS_NAME_LEN](#max_media_key_status_name_len)] | Defines the array of status names.| 
| char [DRM_MediaKeyStatus::statusValue](#statusvalue-22) [[MAX_MEDIA_KEY_STATUS_COUNT](#max_media_key_status_count)][[MAX_MEDIA_KEY_STATUS_VALUE_LEN](#max_media_key_status_value_len)] | Defines the array of status values.| 
| uint8_t [DRM_PsshInfo::uuid](#uuid) [[DRM_UUID_LEN](#drm_uuid_len)] | Defines the UUID.| 
| int32_t [DRM_PsshInfo::dataLen](#datalen-22) | Defines the PSSH data length.| 
| uint8_t [DRM_PsshInfo::data](#data-22) [[MAX_PSSH_DATA_LEN](#max_pssh_data_len)] | Defines the uint8_t PSSH data.| 
| uint32_t [DRM_MediaKeySystemInfo::psshCount](#psshcount) | Defines the number of pieces of PSSH data.| 
| [DRM_PsshInfo](_d_r_m___pssh_info.md) [DRM_MediaKeySystemInfo::psshInfo](#psshinfo) [[MAX_PSSH_INFO_COUNT](#max_pssh_info_count)] | Defines the PSSH information.| 
| [MediaKeySession_EventCallback](#mediakeysession_eventcallback) [MediaKeySession_Callback::eventCallback](#eventcallback) | Defines an event callback, for example, a media key expiry event.| 
| [MediaKeySession_KeyChangeCallback](#mediakeysession_keychangecallback) [MediaKeySession_Callback::keyChangeCallback](#keychangecallback) | Defines the callback of the media key change event.| 


## Macro Description


### DRM_UUID_LEN

```
#define DRM_UUID_LEN   16
```

**Description**

Defines the UUID length.

**Since**: 11


### MAX_DEFAULT_URL_LEN

```
#define MAX_DEFAULT_URL_LEN   2048
```

**Description**

Defines the maximum length of a URL.

**Since**: 11


### MAX_INIT_DATA_LEN

```
#define MAX_INIT_DATA_LEN   2048
```

**Description**

Defines the maximum length of data in an initial request.

**Since**: 11


### MAX_KEY_ID_LEN

```
#define MAX_KEY_ID_LEN   16
```

**Description**

Defines the maximum length of a media key ID.

**Since**: 11


### MAX_KEY_INFO_COUNT

```
#define MAX_KEY_INFO_COUNT   64
```

**Description**

Defines the maximum number of pieces of media key information.

**Since**: 11


### MAX_KEY_STATUS_VALUE_LEN

```
#define MAX_KEY_STATUS_VALUE_LEN   128
```

**Description**

Defines the maximum length of a key status value.

**Since**: 11


### MAX_MEDIA_KEY_REQUEST_DATA_LEN

```
#define MAX_MEDIA_KEY_REQUEST_DATA_LEN   8192
```

**Description**

Defines the maximum length of a media key request.

**Since**: 11


### MAX_MEDIA_KEY_REQUEST_OPTION_COUNT

```
#define MAX_MEDIA_KEY_REQUEST_OPTION_COUNT   16
```

**Description**

Defines the maximum number of options in a media key request.

**Since**: 11


### MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN

```
#define MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN   128
```

**Description**

Defines the maximum length of option data in a media key request.

**Since**: 11


### MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN

```
#define MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN   64
```

**Description**

Defines the maximum length of an option name in a media key request.

**Since**: 11


### MAX_MEDIA_KEY_STATUS_COUNT

```
#define MAX_MEDIA_KEY_STATUS_COUNT   64
```

**Description**

Defines the maximum number of media key statuses.

**Since**: 11


### MAX_MEDIA_KEY_STATUS_NAME_LEN

```
#define MAX_MEDIA_KEY_STATUS_NAME_LEN   64
```

**Description**

Defines the maximum length of a media key status name.

**Since**: 11


### MAX_MEDIA_KEY_STATUS_VALUE_LEN

```
#define MAX_MEDIA_KEY_STATUS_VALUE_LEN   256
```

**Description**

Defines the maximum length of a media key status value.

**Since**: 11


### MAX_MIMETYPE_LEN

```
#define MAX_MIMETYPE_LEN   64
```

**Description**

Defines the maximum length of a MIME type.

**Since**: 11


### MAX_OFFLINE_MEDIA_KEY_ID_COUNT

```
#define MAX_OFFLINE_MEDIA_KEY_ID_COUNT   512
```

**Description**

Defines the maximum number of offline media key IDs.

**Since**: 11


### MAX_OFFLINE_MEDIA_KEY_ID_LEN

```
#define MAX_OFFLINE_MEDIA_KEY_ID_LEN   64
```

**Description**

Defines the maximum length of an offline media key ID.

**Since**: 11


### MAX_PSSH_DATA_LEN

```
#define MAX_PSSH_DATA_LEN   2048
```

**Description**

Defines the maximum length of PSSH data.

**Since**: 11


### MAX_PSSH_INFO_COUNT

```
#define MAX_PSSH_INFO_COUNT   8
```

**Description**

Defines the maximum number of pieces of PSSH information.

**Since**: 11


### MAX_STATISTICS_BUFFER_LEN

```
#define MAX_STATISTICS_BUFFER_LEN   256
```

**Description**

Defines the maximum length of a statistical item buffer.

**Since**: 11


### MAX_STATISTICS_COUNT

```
#define MAX_STATISTICS_COUNT   10
```

**Description**

Defines the maximum number of statistical items.

**Since**: 11


### MAX_STATISTICS_NAME_LEN

```
#define MAX_STATISTICS_NAME_LEN   64
```

**Description**

Defines the maximum length of a statistical item name.

**Since**: 11


## Type Description


### DRM_CertificateStatus

```
typedef enum DRM_CertificateStatusDRM_CertificateStatus
```

**Description**

Defines an enum that enumerates the certificate statuses.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11


### DRM_ContentProtectionLevel

```
typedef enum DRM_ContentProtectionLevelDRM_ContentProtectionLevel
```

**Description**

Defines an enum that enumerates the content protection levels.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11


### Drm_ErrCode

```
typedef enum Drm_ErrCodeDrm_ErrCode
```

**Description**

Defines an enum that enumerates the DRM error codes.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11


### DRM_EventType

```
typedef enum DRM_EventTypeDRM_EventType
```

**Description**

Defines an enum that enumerates the types of events that can be subscribed to.

**Since**: 11


### DRM_KeysInfo

```
typedef struct DRM_KeysInfoDRM_KeysInfo
```

**Description**

Defines the information about media keys.

**Since**: 11


### DRM_MediaKeyRequest

```
typedef struct DRM_MediaKeyRequestDRM_MediaKeyRequest
```

**Description**

Defines a media key request.

**Since**: 11


### DRM_MediaKeyRequestInfo

```
typedef struct DRM_MediaKeyRequestInfoDRM_MediaKeyRequestInfo
```

**Description**

Defines the information about a media key request.

**Since**: 11


### DRM_MediaKeyRequestType

```
typedef enum DRM_MediaKeyRequestTypeDRM_MediaKeyRequestType
```

**Description**

Defines an enum that enumerates the types of requests for media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11


### DRM_MediaKeyStatus

```
typedef struct DRM_MediaKeyStatusDRM_MediaKeyStatus
```

**Description**

Defines the media key status.

**Since**: 11


### DRM_MediaKeySystemInfo

```
typedef struct DRM_MediaKeySystemInfoDRM_MediaKeySystemInfo
```

**Description**

Defines the media key system information obtained from a media source.

**Since**: 11


### DRM_MediaKeySystemInfoCallback

```
typedef void(* DRM_MediaKeySystemInfoCallback) (DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Defines the callback used to obtain media key system information from a media source.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystemInfo | Pointer to the media key system information obtained from the media source.| 


### DRM_MediaKeyType

```
typedef enum DRM_MediaKeyTypeDRM_MediaKeyType
```

**Description**

Defines an enum that enumerates the media key types.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11


### DRM_OfflineMediakeyIdArray

```
typedef struct DRM_OfflineMediakeyIdArrayDRM_OfflineMediakeyIdArray
```

**Description**

Defines an array holding the IDs of offline media keys.

**Since**: 11


### DRM_OfflineMediaKeyStatus

```
typedef enum DRM_OfflineMediaKeyStatusDRM_OfflineMediaKeyStatus
```

**Description**

Defines an enum that enumerates the statuses of offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11


### DRM_PsshInfo

```
typedef struct DRM_PsshInfoDRM_PsshInfo
```

**Description**

Defines the PSSH information of the UUID.

**Since**: 11


### DRM_Statistics

```
typedef struct DRM_StatisticsDRM_Statistics
```

**Description**

Defines the statistics information about a media key system.

**Since**: 11


### MediaKeySession

```
typedef struct MediaKeySessionMediaKeySession
```

**Description**

Defines a media key session.

**Since**: 11


### MediaKeySession_Callback

```
typedef struct MediaKeySession_CallbackMediaKeySession_Callback
```

**Description**

Defines the callback used to listen for events such as media key expiry or change.

**Since**: 11


### MediaKeySession_EventCallback

```
typedef Drm_ErrCode(* MediaKeySession_EventCallback) (DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
```

**Description**

Defines the callback that is invoked when a DRM event is triggered.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| eventType | Event type.| 
| info | Pointer to the event information obtained from the media key session.| 
| infoLen | Length of the event information.| 
| extra | Pointer to the additional information obtained from the media key session.| 

**Returns**

Returns an error code defined in **Drm_ErrCode**.


### MediaKeySession_KeyChangeCallback

```
typedef Drm_ErrCode(* MediaKeySession_KeyChangeCallback) (DRM_KeysInfo *keysInfo, bool newKeysAvailable)
```

**Description**

Defines the callback that is invoked when the key is changed.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| keysInfo | Pointer to the key information obtained from the media key system.| 
| newKeysAvailable | Whether the new key is available.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### MediaKeySystem

```
typedef struct MediaKeySystemMediaKeySystem
```

**Description**

Defines a media key system.

**Since**: 11


### MediaKeySystem_Callback

```
typedef Drm_ErrCode(* MediaKeySystem_Callback) (DRM_EventType eventType, uint8_t *info, int32_t infoLen, char *extra)
```

**Description**

Defines the callback that is invoked when a DRM event is triggered.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| eventType | Event type.| 
| info | Pointer to the event information obtained from the media key system.| 
| infoLen | Length of the event information.| 
| extra | Pointer to the additional information obtained from the media key system.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


## Enum Description


### DRM_CertificateStatus

```
enum DRM_CertificateStatus
```

**Description**

Enumerates the certificate statuses.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CERT_STATUS_PROVISIONED | A device certificate has been installed on the device.| 
| CERT_STATUS_NOT_PROVISIONED | No device certificate is installed on the device.| 
| CERT_STATUS_EXPIRED | The device certificate has expired.| 
| CERT_STATUS_INVALID | The device certificate is invalid.| 
| CERT_STATUS_UNAVAILABLE | The device certificate is unavailable.| 


### DRM_ContentProtectionLevel

```
enum DRM_ContentProtectionLevel
```

**Description**

Enumerates the content protection levels.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CONTENT_PROTECTION_LEVEL_UNKNOWN | Unknown level.| 
| CONTENT_PROTECTION_LEVEL_SW_CRYPTO | Software content protection level.| 
| CONTENT_PROTECTION_LEVEL_HW_CRYPTO | Hardware content protection level.| 
| CONTENT_PROTECTION_LEVEL_ENHANCED_HW_CRYPTO | Hardware enhancement level.| 
| CONTENT_PROTECTION_LEVEL_MAX | Highest content protection level.| 


### Drm_ErrCode

```
enum Drm_ErrCode
```

**Description**

Enumerates the DRM error codes.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| DRM_ERR_OK | Operation successful.| 
| DRM_CAPI_ERR_BASE | Basic error.| 
| DRM_ERR_NO_MEMORY | Insufficient memory.| 
| DRM_ERR_OPERATION_NOT_PERMITTED | Unsupported operation.| 
| DRM_ERR_INVALID_VAL | Invalid parameters.| 
| DRM_ERR_IO | I/O error.| 
| DRM_ERR_TIMEOUT | Network timeout.| 
| DRM_ERR_UNKNOWN | Unknown error.| 
| DRM_ERR_SERVICE_DIED | DRM service suspended.| 
| DRM_ERR_INVALID_STATE | Invalid operation status.| 
| DRM_ERR_UNSUPPORTED | Unsupported operation.| 
| DRM_ERR_MAX_SYSTEM_NUM_REACHED | Too many **MediaKeySystem** instances.| 
| DRM_ERR_MAX_SESSION_NUM_REACHED | Too many **MediaKeySession** instances.| 
| DRM_ERR_EXTEND_START | Extended error.| 


### DRM_EventType

```
enum DRM_EventType
```

**Description**

Enumerates the types of events that can be subscribed to.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| EVENT_DRM_BASE | DRM event.| 
| EVENT_PROVISION_REQUIRED | Event indicating that the application needs to request a device certificate.| 
| EVENT_KEY_REQUIRED | Event indicating that the application needs to request a media key.| 
| EVENT_KEY_EXPIRED | Event indicating that the media key expires.| 
| EVENT_VENDOR_DEFINED | Vendor-defined event.| 
| EVENT_EXPIRATION_UPDATE | Event indicating that the media key updates on expiry.| 


### DRM_MediaKeyRequestType

```
enum DRM_MediaKeyRequestType
```

**Description**

Enumerates the types of requests for media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| MEDIA_KEY_REQUEST_TYPE_UNKNOWN | Unknown type.| 
| MEDIA_KEY_REQUEST_TYPE_INITIAL | Initial request.| 
| MEDIA_KEY_REQUEST_TYPE_RENEWAL | Renewal request.| 
| MEDIA_KEY_REQUEST_TYPE_RELEASE | Release request.| 
| MEDIA_KEY_REQUEST_TYPE_NONE | None.| 
| MEDIA_KEY_REQUEST_TYPE_UPDATE | Update request.| 


### DRM_MediaKeyType

```
enum DRM_MediaKeyType
```

**Description**

Enumerates the media key types.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| MEDIA_KEY_TYPE_OFFLINE | Offline.| 
| MEDIA_KEY_TYPE_ONLINE | Online.| 


### DRM_OfflineMediaKeyStatus

```
enum DRM_OfflineMediaKeyStatus
```

**Description**

Enumerates the statuses of offline media keys.

**System capability**: SystemCapability.Multimedia.Drm.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| OFFLINE_MEDIA_KEY_STATUS_UNKNOWN | Unknown status.| 
| OFFLINE_MEDIA_KEY_STATUS_USABLE | The media key is available.| 
| OFFLINE_MEDIA_KEY_STATUS_INACTIVE | The media key is inactive.| 


## Function Description


### OH_MediaKeySession_CheckMediaKeyStatus()

```
Drm_ErrCode OH_MediaKeySession_CheckMediaKeyStatus (MediaKeySession * mediaKeySessoin, DRM_MediaKeyStatus * mediaKeyStatus )
```

**Description**

Checks the status of media keys.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| mediaKeyStatus | Pointer to the media key status obtained.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_ClearMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_ClearMediaKeys (MediaKeySession * mediaKeySessoin)
```

**Description**

Clears media keys.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_Destroy()

```
Drm_ErrCode OH_MediaKeySession_Destroy (MediaKeySession * mediaKeySessoin)
```

**Description**

Releases the media key session resources.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_GenerateMediaKeyRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateMediaKeyRequest (MediaKeySession * mediaKeySession, DRM_MediaKeyRequestInfo * info, DRM_MediaKeyRequest * mediaKeyRequest )
```

**Description**

Generates a media key request.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| info | Pointer to the information about the media key request.| 
| mediaKeyRequest | Pointer to the media key request generated.| 

**Returns**

Returns an error code defined in **Drm_ErrCode**.


### OH_MediaKeySession_GenerateOfflineReleaseRequest()

```
Drm_ErrCode OH_MediaKeySession_GenerateOfflineReleaseRequest (MediaKeySession * mediaKeySessoin, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t * releaseRequest, int32_t * releaseRequestLen )
```

**Description**

Generates a request to release offline media keys.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| offlineMediaKeyId | Pointer to the ID of the offline media keys.| 
| releaseRequestLen | Length of the offline media key ID.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_GetContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySession_GetContentProtectionLevel (MediaKeySession * mediaKeySessoin, DRM_ContentProtectionLevel * contentProtectionLevel )
```

**Description**

Obtains the content protection level of a media key session.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| contentProtectionLevel | Pointer to the content protection level obtained.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_ProcessMediaKeyResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessMediaKeyResponse (MediaKeySession * mediaKeySession, uint8_t * response, int32_t responseLen, uint8_t * offlineMediaKeyId, int32_t * offlineMediaKeyIdLen )
```

**Description**

Processes a response to the media key request.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| response | Pointer to the response.| 
| responseLen | Length of the response.| 
| offlineMediaKeyId | Pointer to the ID of the offline media keys.| 
| offlineMediaKeyIdLen | Pointer to the length of the offline media key ID for data inside and outside the buffer.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_ProcessOfflineReleaseResponse()

```
Drm_ErrCode OH_MediaKeySession_ProcessOfflineReleaseResponse (MediaKeySession * mediaKeySessoin, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen, uint8_t * releaseReponse, int32_t releaseReponseLen )
```

**Description**

Processes a response to a request for releasing offline media keys.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| offlineMediaKeyId | Pointer to the ID of the offline media keys.| 
| offlineMediaKeyIdLen | Length of the offline media key ID.| 
| releaseReponse | Pointer to the response.| 
| releaseReponseLen | Length of the response.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_RequireSecureDecoderModule()

```
Drm_ErrCode OH_MediaKeySession_RequireSecureDecoderModule (MediaKeySession * mediaKeySessoin, const char * mimeType, bool * status )
```

**Description**

Checks whether secure decoding is required for encrypted content.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| mimeType | Pointer to the MIME type.| 
| status | Pointer to the result indicating whether secure decoding is required.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_RestoreOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySession_RestoreOfflineMediaKeys (MediaKeySession * mediaKeySessoin, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen )
```

**Description**

Restores offline media keys.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| offlineMediaKeyId | Pointer to the ID of the offline media keys.| 
| offlineMediaKeyIdLen | Length of the offline media key ID.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySession_SetMediaKeySessionCallback()

```
Drm_ErrCode OH_MediaKeySession_SetMediaKeySessionCallback (MediaKeySession * mediaKeySessoin, MediaKeySession_Callback * callback )
```

**Description**

Sets a media key session event callback.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySession | Pointer to the **MediaKeySession** instance.| 
| callback | Pointer to the callback to be set for the media key session.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_ClearOfflineMediaKeys()

```
Drm_ErrCode OH_MediaKeySystem_ClearOfflineMediaKeys (MediaKeySystem * mediaKeySystem, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen )
```

**Description**

Clears offline media keys by ID.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| offlineMediaKeyId | Pointer to the ID of the offline media keys.| 
| offlineMediaKeyIdLen | Length of the offline media key ID.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_Create()

```
Drm_ErrCode OH_MediaKeySystem_Create (const char * name, MediaKeySystem ** mediaKeySystem )
```

**Description**

Creates a **MediaKeySystem** instance by name.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Pointer to the name.| 
| mediaKeySystem | Double pointer to the **MediaKeySystem** instance created.| 

**Returns**

Returns **DRM_ERR_OK** if the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails; returns **DRM_ERR_MAX_SYSTEM_NUM_REACHED** if the maximum number of media key systems is reached.


### OH_MediaKeySystem_CreateMediaKeySession()

```
Drm_ErrCode OH_MediaKeySystem_CreateMediaKeySession (MediaKeySystem * mediaKeySystem, DRM_ContentProtectionLevel * level, MediaKeySession ** mediaKeySession )
```

**Description**

Creates a **MediaKeySession** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance for which a **MediaKeySession** instance will be created.| 
| level | Pointer to the content protection level.| 
| mediaKeySession | Double pointer to the **MediaKeySession** instance created.| 

**Returns**

Returns **DRM_ERR_OK** if the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails; returns **DRM_ERR_MAX_SESSION_NUM_REACHED** if the maximum number of media key sessions is reached.


### OH_MediaKeySystem_Destroy()

```
Drm_ErrCode OH_MediaKeySystem_Destroy (MediaKeySystem * mediaKeySystem)
```

**Description**

Destroys a **MediaKeySystem** instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GenerateKeySystemRequest()

```
Drm_ErrCode OH_MediaKeySystem_GenerateKeySystemRequest (MediaKeySystem * mediaKeySystem, uint8_t * request, int32_t * requestLen, char * defaultUrl, int32_t defaultUrlLen )
```

**Description**

Generates a media key system request to obtain a provision request.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| request | Pointer to the provision request, which will be sent to the provisioning server.| 
| requestLen | Pointer to the length of the provision request.| 
| defaultUrl | Pointer to the URL of the provisioning server.| 
| defaultUrlLen | Length of the URL of the provisioning server.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GetCertificateStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetCertificateStatus (MediaKeySystem * mediaKeySystem, DRM_CertificateStatus * certStatus )
```

**Description**

Obtains the certificate status of a media key system.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| certStatus | Pointer to the certificate status obtained.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationByteArray (MediaKeySystem * mediaKeySystem, const char * configName, uint8_t * value, int32_t * valueLen )
```

**Description**

Obtains the value of a configuration item in the form of a byte array for a media key system.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| configName | Pointer to the name of the configuration item.| 
| value | Pointer to the value of the configuration item.| 
| valueLen | Pointer to the length of the value.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_GetConfigurationString (MediaKeySystem * mediaKeySystem, const char * configName, char * value, int32_t valueLen )
```

**Description**

Obtains the value of a configuration item in the form of a string for a media key system.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| configName | Pointer to the name of the configuration item.| 
| value | Pointer to the value of the configuration item.| 
| valueLen | Pointer to the length of the value.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GetMaxContentProtectionLevel()

```
Drm_ErrCode OH_MediaKeySystem_GetMaxContentProtectionLevel (MediaKeySystem * mediaKeySystem, DRM_ContentProtectionLevel * contentProtectionLevel )
```

**Description**

Obtains the media key system with the maximum content protection level supported by the device.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| contentProtectionLevel | Pointer to the content protection level.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GetOfflineMediaKeyIds()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyIds (MediaKeySystem * mediaKeySystem, DRM_OfflineMediakeyIdArray * offlineMediaKeyIds )
```

**Description**

Obtains the IDs of offline media keys.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| offlineMediaKeyIds | Pointer to the IDs of all offline media keys.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GetOfflineMediaKeyStatus()

```
Drm_ErrCode OH_MediaKeySystem_GetOfflineMediaKeyStatus (MediaKeySystem * mediaKeySystem, uint8_t * offlineMediaKeyId, int32_t offlineMediaKeyIdLen, DRM_OfflineMediaKeyStatus * status )
```

**Description**

Obtains the status of offline media keys.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| offlineMediaKeyId | Pointer to the ID of the offline media keys.| 
| offlineMediaKeyIdLen | Length of the offline media key ID.| 
| status | Pointer to the media key status obtained.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_GetStatistics()

```
Drm_ErrCode OH_MediaKeySystem_GetStatistics (MediaKeySystem * mediaKeySystem, DRM_Statistics * statistics )
```

**Description**

Obtains the statistics information about a media key system.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| statistics | Pointer to the statistics information obtained.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_IsSupported()

```
bool OH_MediaKeySystem_IsSupported (const char * name)
```

**Description**

Checks whether a media key system is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Pointer to the name of the media key system.| 

**Returns**

Returns **true** if the media key system is supported; returns **false** otherwise.


### OH_MediaKeySystem_IsSupported2()

```
bool OH_MediaKeySystem_IsSupported2 (const char * name, const char * mimeType )
```

**Description**

Checks whether a media key system is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Pointer to the name of the media key system.| 
| mimeType | Pointer to the MIME type.| 

**Returns**

Returns **true** if the media key system is supported; returns **false** otherwise.


### OH_MediaKeySystem_IsSupported3()

```
bool OH_MediaKeySystem_IsSupported3 (const char * name, const char * mimeType, DRM_ContentProtectionLevel contentProtectionLevel )
```

**Description**

Checks whether a media key system is supported.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Pointer to the name of the media key system.| 
| mimeType | Pointer to the MIME type.| 
| contentProtectionLevel | Content protection level.| 

**Returns**

Returns **true** if the media key system is supported; returns **false** otherwise.


### OH_MediaKeySystem_ProcessKeySystemResponse()

```
Drm_ErrCode OH_MediaKeySystem_ProcessKeySystemResponse (MediaKeySystem * mediaKeySystem, uint8_t * response, int32_t responseLen )
```

**Description**

Processes a response to the media key system request.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| response | Pointer to the response.| 
| responseLen | Length of the response.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_SetConfigurationByteArray()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationByteArray (MediaKeySystem * mediaKeySystem, const char * configName, uint8_t * value, int32_t valueLen )
```

**Description**

Sets a configuration item in the form of a byte array for a media key system.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| configName | Pointer to the name of the configuration item.| 
| value | Pointer to the values of the configuration item, in the form of a byte array.| 
| valueLen | Length of the byte array.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_SetConfigurationString()

```
Drm_ErrCode OH_MediaKeySystem_SetConfigurationString (MediaKeySystem * mediaKeySystem, const char * configName, const char * value )
```

**Description**

Sets a configuration item in the form of a string for a media key system.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| configName | Pointer to the name of the configuration item.| 
| value | Pointer to the value of the configuration item, in the form of a string.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


### OH_MediaKeySystem_SetMediaKeySystemCallback()

```
Drm_ErrCode OH_MediaKeySystem_SetMediaKeySystemCallback (MediaKeySystem * mediaKeySystem, MediaKeySystem_Callback callback )
```

**Description**

Sets a media key system event callback.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| mediaKeySystem | Pointer to the **MediaKeySystem** instance.| 
| callback | Callback to be set for the media key system.| 

**Returns**

Returns **DRM_ERR_OK** is the call is successful; returns **DRM_ERR_INVALID_VAL** if the parameter check fails.


## Variable Description


### data [1/2]

```
uint8_t DRM_MediaKeyRequest::data[MAX_MEDIA_KEY_REQUEST_DATA_LEN]
```

**Description**

Defines the data in a media key request sent to the media key server.


### data [2/2]

```
uint8_t DRM_PsshInfo::data[MAX_PSSH_DATA_LEN]
```

**Description**

Defines the uint8_t PSSH data.


### dataLen [1/2]

```
int32_t DRM_MediaKeyRequest::dataLen
```

**Description**

Defines the length of data in a media key request.


### dataLen [2/2]

```
int32_t DRM_PsshInfo::dataLen
```

**Description**

Defines the PSSH data length.


### defaultUrl

```
char DRM_MediaKeyRequest::defaultUrl[MAX_DEFAULT_URL_LEN]
```

**Description**

Defines the URL of a media key server.


### eventCallback

```
MediaKeySession_EventCallback MediaKeySession_Callback::eventCallback
```

**Description**

Defines an event callback, for example, a media key expiry event.


### ids

```
uint8_t DRM_OfflineMediakeyIdArray::ids[MAX_OFFLINE_MEDIA_KEY_ID_COUNT][MAX_OFFLINE_MEDIA_KEY_ID_LEN]
```

**Description**

Defines the ID data set.


### idsCount

```
uint32_t DRM_OfflineMediakeyIdArray::idsCount
```

**Description**

Defines the number of IDs.


### idsLen

```
int32_t DRM_OfflineMediakeyIdArray::idsLen[MAX_OFFLINE_MEDIA_KEY_ID_COUNT]
```

**Description**

Defines the ID length set.


### initData

```
uint8_t DRM_MediaKeyRequestInfo::initData[MAX_INIT_DATA_LEN]
```

**Description**

Defines the initial data in PSSH format after Base64 decoding.


### initDataLen

```
int32_t DRM_MediaKeyRequestInfo::initDataLen
```

**Description**

Defines the initial data length.


### keyChangeCallback

```
MediaKeySession_KeyChangeCallback MediaKeySession_Callback::keyChangeCallback
```

**Description**

Defines the callback of the media key change event.


### keyId

```
uint8_t DRM_KeysInfo::keyId[MAX_KEY_INFO_COUNT][MAX_KEY_ID_LEN]
```

**Description**

Defines the key ID set.


### keysInfoCount

```
uint32_t DRM_KeysInfo::keysInfoCount
```

**Description**

Defines the number of keys.


### mimeType

```
char DRM_MediaKeyRequestInfo::mimeType[MAX_MIMETYPE_LEN]
```

**Description**

Defines the MIME type of the media context.


### optionData

```
char DRM_MediaKeyRequestInfo::optionData[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN]
```

**Description**

Defines the option data set.


### optionName

```
char DRM_MediaKeyRequestInfo::optionName[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN]
```

**Description**

Defines the option name set.


### optionsCount

```
uint32_t DRM_MediaKeyRequestInfo::optionsCount
```

**Description**

Defines the number of options.


### psshCount

```
uint32_t DRM_MediaKeySystemInfo::psshCount
```

**Description**

Defines the number of pieces of PSSH data.


### psshInfo

```
DRM_PsshInfo DRM_MediaKeySystemInfo::psshInfo[MAX_PSSH_INFO_COUNT]
```

**Description**

Defines the PSSH information.


### statisticsCount

```
uint32_t DRM_Statistics::statisticsCount
```

**Description**

Defines the number of statistical items.


### statisticsDescription

```
char DRM_Statistics::statisticsDescription[MAX_STATISTICS_COUNT][MAX_STATISTICS_BUFFER_LEN]
```

**Description**

Defines the set of statistics information description.


### statisticsName

```
char DRM_Statistics::statisticsName[MAX_STATISTICS_COUNT][MAX_STATISTICS_NAME_LEN]
```

**Description**

Defines the statistical item name set.


### statusCount

```
uint32_t DRM_MediaKeyStatus::statusCount
```

**Description**

Defines the number of media key statuses.


### statusName

```
char DRM_MediaKeyStatus::statusName[MAX_MEDIA_KEY_STATUS_COUNT][MAX_MEDIA_KEY_STATUS_NAME_LEN]
```

**Description**

Defines the array of status names.


### statusValue [1/2]

```
char DRM_KeysInfo::statusValue[MAX_KEY_INFO_COUNT][MAX_KEY_STATUS_VALUE_LEN]
```

**Description**

Defines the key status value.


### statusValue [2/2]

```
char DRM_MediaKeyStatus::statusValue[MAX_MEDIA_KEY_STATUS_COUNT][MAX_MEDIA_KEY_STATUS_VALUE_LEN]
```

**Description**

Defines the array of status values.


### type [1/2]

```
DRM_MediaKeyType DRM_MediaKeyRequestInfo::type
```

**Description**

Defines the key type.


### type [2/2]

```
DRM_MediaKeyRequestType DRM_MediaKeyRequest::type
```

**Description**

Defines the type of a media key request.


### uuid

```
uint8_t DRM_PsshInfo::uuid[DRM_UUID_LEN]
```

**Description**

Defines the UUID.

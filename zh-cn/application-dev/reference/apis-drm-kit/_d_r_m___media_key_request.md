# DRM_MediaKeyRequest


## 概述

媒体密钥请求。

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype) [type](_drm.md#type-22) | 媒体密钥请求类型。 | 
| int32_t [dataLen](_drm.md#datalen-12) | 媒体密钥请求数据长度。 | 
| uint8_t [data](_drm.md#data-12) [[MAX_MEDIA_KEY_REQUEST_DATA_LEN](_drm.md#max_media_key_request_data_len)] | 发送到媒体密钥服务器的媒体密钥请求数据。 | 
| char [defaultUrl](_drm.md#defaulturl) [[MAX_DEFAULT_URL_LEN](_drm.md#max_default_url_len)] | 媒体密钥服务器URL。 | 

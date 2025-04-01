# DRM_MediaKeyRequestInfo


## 概述

媒体密钥请求信息。

**起始版本：** 11

**相关模块：**[Drm](_drm.md)

**所在头文件：**[native_drm_common.h](native__drm__common_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_MediaKeyType](_drm.md#drm_mediakeytype) [type](_drm.md#type-12) | 密钥类型。 | 
| int32_t [initDataLen](_drm.md#initdatalen) | 初始数据长度。 | 
| uint8_t [initData](_drm.md#initdata) [[MAX_INIT_DATA_LEN](_drm.md#max_init_data_len)] | base64解码后格式为PSSH的初始数据。 | 
| char [mimeType](_drm.md#mimetype) [[MAX_MIMETYPE_LEN](_drm.md#max_mimetype_len)] | 媒体上下文的mime类型。 | 
| uint32_t [optionsCount](_drm.md#optionscount) | 选项数据计数。 | 
| char [optionName](_drm.md#optionname) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](_drm.md#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](_drm.md#max_media_key_request_option_name_len)] | 选项名称集合。 | 
| char [optionData](_drm.md#optiondata) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](_drm.md#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](_drm.md#max_media_key_request_option_data_len)] | 选项数据集合。 | 

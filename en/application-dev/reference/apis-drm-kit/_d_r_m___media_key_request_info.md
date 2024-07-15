# DRM_MediaKeyRequestInfo


## Overview

The DRM_MediaKeyRequestInfo struct describes the information about a media key request.

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [DRM_MediaKeyType](_drm.md#drm_mediakeytype) [type](_drm.md#type-12) | Key type.| 
| int32_t [initDataLen](_drm.md#initdatalen) | Initial data length.| 
| uint8_t [initData](_drm.md#initdata) [[MAX_INIT_DATA_LEN](_drm.md#max_init_data_len)] | Initial data in PSSH format after Base64 decoding.| 
| char [mimeType](_drm.md#mimetype) [[MAX_MIMETYPE_LEN](_drm.md#max_mimetype_len)] | MIME type of the media context.| 
| uint32_t [optionsCount](_drm.md#optionscount) | Number of options.| 
| char [optionName](_drm.md#optionname) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](_drm.md#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN](_drm.md#max_media_key_request_option_name_len)] | Option name set.| 
| char [optionData](_drm.md#optiondata) [[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT](_drm.md#max_media_key_request_option_count)][[MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN](_drm.md#max_media_key_request_option_data_len)] | Option data set.| 

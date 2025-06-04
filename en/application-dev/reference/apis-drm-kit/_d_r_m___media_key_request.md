# DRM_MediaKeyRequest


## Overview

The DRM_MediaKeyRequest struct describes a media key request.

**Since**: 11

**Related module**: [Drm](_drm.md)

**Header file**: [native_drm_common.h](native__drm__common_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [DRM_MediaKeyRequestType](_drm.md#drm_mediakeyrequesttype) [type](_drm.md#type-22) | Type of a media key request.| 
| int32_t [dataLen](_drm.md#datalen-12) | Length of data in a media key request.| 
| uint8_t [data](_drm.md#data-12) [[MAX_MEDIA_KEY_REQUEST_DATA_LEN](_drm.md#max_media_key_request_data_len)] | Data in a media key request sent to the media key server.| 
| char [defaultUrl](_drm.md#defaulturl) [[MAX_DEFAULT_URL_LEN](_drm.md#max_default_url_len)] | URL of a media key server.| 

# DRM_MediaKeyStatus


## Overview

The DRM_MediaKeyStatus struct describes the media key status.

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [statusCount](_drm.md#statuscount) | Number of media key statuses.| 
| char [statusName](_drm.md#statusname) [[MAX_MEDIA_KEY_STATUS_COUNT](_drm.md#max_media_key_status_count)][[MAX_MEDIA_KEY_STATUS_NAME_LEN](_drm.md#max_media_key_status_name_len)] | Array of status names.| 
| char [statusValue](_drm.md#statusvalue-22) [[MAX_MEDIA_KEY_STATUS_COUNT](_drm.md#max_media_key_status_count)][[MAX_MEDIA_KEY_STATUS_VALUE_LEN](_drm.md#max_media_key_status_value_len)] | Array of status values.| 

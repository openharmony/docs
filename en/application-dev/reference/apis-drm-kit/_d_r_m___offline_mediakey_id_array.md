# DRM_OfflineMediakeyIdArray


## Overview

The DRM_OfflineMediakeyIdArray struct defines an array holding the IDs of offline media keys.

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [idsCount](_drm.md#idscount) | Defines the number of IDs.| 
| int32_t [idsLen](_drm.md#idslen) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](_drm.md#max_offline_media_key_id_count)] | Defines the ID length set.| 
| uint8_t [ids](_drm.md#ids) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](_drm.md#max_offline_media_key_id_count)][[MAX_OFFLINE_MEDIA_KEY_ID_LEN](_drm.md#max_offline_media_key_id_len)] | Defines the ID data set.| 

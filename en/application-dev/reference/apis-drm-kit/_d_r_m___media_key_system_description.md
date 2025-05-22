# DRM_MediaKeySystemDescription


## Overview

The DRM_MediaKeySystemDescription struct describes the name and UUID of a DRM plugin.

**Since**: 12

**Related module**: [Drm](_drm.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char [name](_drm.md#name) [[MAX_MEDIA_KEY_SYSTEM_NAME_LEN](_drm.md#max_media_key_system_name_len)] | Name of the DRM plugin.| 
| uint8_t [uuid](_drm.md#uuid-22) [[DRM_UUID_LEN](_drm.md#drm_uuid_len)] | UUID of the DRM plugin.| 

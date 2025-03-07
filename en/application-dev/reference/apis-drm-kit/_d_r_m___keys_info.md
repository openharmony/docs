# DRM_KeysInfo


## Overview

The DRM_KeysInfo struct describes the information about media keys.

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [keysInfoCount](_drm.md#keysinfocount) | Number of keys.| 
| uint8_t [keyId](_drm.md#keyid) [[MAX_KEY_INFO_COUNT](_drm.md#max_key_info_count)][[MAX_KEY_ID_LEN](_drm.md#max_key_id_len)] | Key ID set.| 
| char [statusValue](_drm.md#statusvalue-12) [[MAX_KEY_INFO_COUNT](_drm.md#max_key_info_count)][[MAX_KEY_STATUS_VALUE_LEN](_drm.md#max_key_status_value_len)] | Key status value.| 

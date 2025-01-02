# DRM_PsshInfo


## Overview

The DRM_PsshInfo struct describes the PSSH information of the UUID.

**Since**: 11

**Related module**: [Drm](_drm.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t [uuid](_drm.md#uuid) [[DRM_UUID_LEN](_drm.md#drm_uuid_len)] | Protection Scheme Specific Header (PSSH) information of the UUID.| 
| int32_t [dataLen](_drm.md#datalen-22) | PSSH data length.| 
| uint8_t [data](_drm.md#data-22) [[MAX_PSSH_DATA_LEN](_drm.md#max_pssh_data_len)] | PSSH data.| 

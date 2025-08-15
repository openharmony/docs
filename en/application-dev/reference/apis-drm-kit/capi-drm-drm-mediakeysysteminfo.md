# DRM_MediaKeySystemInfo

## Overview

The struct describes the DRM information, which is used to encrypt content.

**Since**: 11

**Related module**: [Drm](capi-drm.md)

**Header file**: [native_drm_common.h](capi-native-drm-common-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t psshCount | Number of pieces of Protection Scheme Specific Header (PSSH) data.|
| [DRM_PsshInfo](capi-drm-drm-psshinfo.md) psshInfo[MAX_PSSH_INFO_COUNT] | PSSH information.|

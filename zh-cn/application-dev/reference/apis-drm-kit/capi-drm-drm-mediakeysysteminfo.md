# DRM_MediaKeySystemInfo

## 概述

加密媒体内容的DRM信息。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t psshCount | PSSH计数。 |
| [DRM_PsshInfo](capi-drm-drm-psshinfo.md) psshInfo[MAX_PSSH_INFO_COUNT] | PSSH信息。 |



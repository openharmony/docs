# DRM_MediaKeySystemInfo
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_MediaKeySystemInfo {...} DRM_MediaKeySystemInfo
```

## 概述

 加密媒体内容的DRM信息。
 
**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t psshCount | PSSH信息的数量，表示psshInfo数组中有效元素的个数。一个媒体文件可能包含多个DRM系统的PSSH，取值范围为[0, MAX_PSSH_INFO_COUNT]。 |
| [DRM_PsshInfo](capi-drm-drm-psshinfo.md) psshInfo[MAX_PSSH_INFO_COUNT] | PSSH信息数组，每项包含一个DRM内容保护系统专用头的信息。数组长度由MAX_PSSH_INFO_COUNT宏定义，每项包含DRM系统UUID和初始化数据。 |



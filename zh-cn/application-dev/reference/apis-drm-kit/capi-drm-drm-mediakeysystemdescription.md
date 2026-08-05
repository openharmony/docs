# DRM_MediaKeySystemDescription
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_MediaKeySystemDescription {...} DRM_MediaKeySystemDescription
```

## 概述

DRM解决方案名称及其UUID的列表。

**起始版本：** 12

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| char name[MAX_MEDIA_KEY_SYSTEM_NAME_LEN] | DRM插件的名称，用于唯一标识一个DRM解决方案。名称格式由DRM解决方案定义，如"com.widevine.alpha"、"com.microsoft.playready"等。数组长度由MAX_MEDIA_KEY_SYSTEM_NAME_LEN宏定义。 |
| uint8_t uuid[DRM_UUID_LEN] | DRM系统的UUID（通用唯一标识符），用于唯一标识一个DRM内容保护系统。UUID长度为16字节（DRM_UUID_LEN），由DRM解决方案提供商分配。UUID与name对应同一DRM解决方案的不同表示形式。 |



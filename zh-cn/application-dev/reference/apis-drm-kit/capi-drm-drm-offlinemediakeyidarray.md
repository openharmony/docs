# DRM_OfflineMediakeyIdArray
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_OfflineMediakeyIdArray {...} DRM_OfflineMediakeyIdArray
```

## 概述

离线媒体密钥ID数组。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t idsCount | 离线媒体密钥ID的数量，表示idsLen和ids数组中有效元素的个数。取值范围为[0, MAX_OFFLINE_MEDIA_KEY_ID_COUNT]。 |
| int32_t idsLen[MAX_OFFLINE_MEDIA_KEY_ID_COUNT] | 离线媒体密钥ID长度数组，每个元素表示对应ids数组行中有效数据的字节数。数组长度由MAX_OFFLINE_MEDIA_KEY_ID_COUNT宏定义。 |
| uint8_t ids[MAX_OFFLINE_MEDIA_KEY_ID_COUNT][MAX_OFFLINE_MEDIA_KEY_ID_LEN] | 离线媒体密钥ID数据数组，用于存储离线媒体密钥的标识符。每行存储一个密钥ID，有效长度由对应的idsLen元素指定。数组维度由MAX_OFFLINE_MEDIA_KEY_ID_COUNT和MAX_OFFLINE_MEDIA_KEY_ID_LEN宏定义。 |



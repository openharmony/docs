# DRM_KeysInfo
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_KeysInfo {...} DRM_KeysInfo
```

## 概述

 媒体密钥信息。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t keysInfoCount | 媒体密钥信息的数量，表示keyId和statusValue数组中有效元素的个数。取值范围为[0, MAX_KEY_INFO_COUNT]。 |
| uint8_t keyId[MAX_KEY_INFO_COUNT][MAX_KEY_ID_LEN] | 媒体密钥ID数组，每行存储一个密钥的标识符。密钥ID由DRM解决方案定义，用于唯一标识一个媒体密钥。数组维度由MAX_KEY_INFO_COUNT和MAX_KEY_ID_LEN宏定义。 |
| char statusValue[MAX_KEY_INFO_COUNT][MAX_KEY_STATUS_VALUE_LEN] | 媒体密钥状态值数组，每行存储对应keyId的密钥状态。状态值由DRM解决方案定义，常见状态包括"usable"（可用）、"expired"（已过期）等。数组维度由MAX_KEY_INFO_COUNT和MAX_KEY_STATUS_VALUE_LEN宏定义。 |



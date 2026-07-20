# DRM_MediaKeyRequest
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_MediaKeyRequest {...} DRM_MediaKeyRequest
```

## 概述

 媒体密钥请求。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [DRM_MediaKeyRequestType](capi-native-drm-common-h.md#drm_mediakeyrequesttype) type | 媒体密钥请求类型，指示请求的用途。常见类型包括DRM_MEDIA_KEY_REQUEST_TYPE_INITIAL（初始请求）、DRM_MEDIA_KEY_REQUEST_TYPE_RENEWAL（续期请求）等，具体类型由DRM解决方案决定。 |
| int32_t dataLen | 媒体密钥请求数据的长度（单位：字节），表示data数组中有效数据的字节数。取值范围为[0, MAX_MEDIA_KEY_REQUEST_DATA_LEN]。 |
| uint8_t data[MAX_MEDIA_KEY_REQUEST_DATA_LEN] | 媒体密钥请求数据，需要发送到许可证服务器的数据。数据格式由DRM解决方案定义，通常为特定格式的二进制数据或JSON格式。数组长度由MAX_MEDIA_KEY_REQUEST_DATA_LEN宏定义。 |
| char defaultUrl[MAX_DEFAULT_URL_LEN] | 许可证服务器的默认URL，用于获取媒体密钥。该URL由DRM解决方案提供，应用可使用此URL或自定义URL发送请求。数组长度由MAX_DEFAULT_URL_LEN宏定义。 |



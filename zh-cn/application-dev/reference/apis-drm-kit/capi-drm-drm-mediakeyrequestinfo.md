# DRM_MediaKeyRequestInfo
<!--Kit: Drm Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qin_wei_jie-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct DRM_MediaKeyRequestInfo {...} DRM_MediaKeyRequestInfo
```

## 概述

媒体密钥请求信息。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [DRM_MediaKeyType](capi-native-drm-common-h.md#drm_mediakeytype) type | 媒体密钥类型，指定请求的密钥用途。取值为DRM_MEDIA_KEY_TYPE_STREAMING（在线流媒体）或DRM_MEDIA_KEY_TYPE_OFFLINE（离线播放）。 |
| int32_t initDataLen | 初始化数据的长度，表示initData数组中有效数据的字节数。单位为字节（Byte），取值范围为[1, MAX_INIT_DATA_LEN]。 |
| uint8_t initData[MAX_INIT_DATA_LEN] | 初始化数据，包含DRM内容保护系统特定头（PSSH）格式的数据。通常从媒体内容的PSSH box中提取，需进行base64解码后传入。数组长度由MAX_INIT_DATA_LEN宏定义。 |
| char mimeType[MAX_MIMETYPE_LEN] | 媒体内容的MIME类型，用于标识媒体内容的格式。常见取值如"video/mp4"、"video/webm"等，具体支持类型由DRM解决方案决定。数组长度由MAX_MIMETYPE_LEN宏定义。 |
| uint32_t optionsCount | 选项数据的数量，表示optionName和optionData数组中有效元素的个数。取值范围为[0, MAX_MEDIA_KEY_REQUEST_OPTION_COUNT]。 |
| char optionName[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN] | 选项名称数组，每行存储一个选项的名称。选项名称由DRM解决方案定义，用于传递特定的请求参数。数组维度由MAX_MEDIA_KEY_REQUEST_OPTION_COUNT和MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN宏定义。 |
| char optionData[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN] | 选项数据数组，每行存储对应optionName的选项值。数组维度由MAX_MEDIA_KEY_REQUEST_OPTION_COUNT和MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN宏定义。 |



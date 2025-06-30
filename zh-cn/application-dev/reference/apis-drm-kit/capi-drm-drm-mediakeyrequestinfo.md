# DRM_MediaKeyRequestInfo

## 概述

媒体密钥请求信息。

**起始版本：** 11

**相关模块：** [Drm](capi-drm.md)

**所在头文件：** [native_drm_common.h](capi-native-drm-common-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| DRM_MediaKeyType type | 密钥类型。 |
| int32_t initDataLen | 初始数据长度。 |
| uint8_t initData[MAX_INIT_DATA_LEN] | base64解码后格式为PSSH的初始数据。 |
| char mimeType[MAX_MIMETYPE_LEN] | 媒体上下文的mime类型。 |
| uint32_t optionsCount | 选项数据计数。 |
| char optionName[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_NAME_LEN] | 选项将应用程序集命名到drm框架。 |
| char optionData[MAX_MEDIA_KEY_REQUEST_OPTION_COUNT][MAX_MEDIA_KEY_REQUEST_OPTION_DATA_LEN] | 选项数据应用程序设置到drm框架。 |



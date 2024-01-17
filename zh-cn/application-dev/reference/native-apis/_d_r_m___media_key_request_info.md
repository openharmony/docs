# DRM_MediaKeyRequestInfo


## 概述

许可证请求参数类型。

**系统能力：** SystemCapability.Multimedia.Drm.Core

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [DRM_MediaKeyType](_drm.md#drm_mediakeytype)[type](_drm.md#type-12) | 许可证类型 | 
| [DRM_Uint8Buffer](_d_r_m___uint8_buffer.md)[data](_drm.md#data-13) | base64编码后的pssh数据 | 
| [DRM_CharBuffer](_d_r_m___char_buffer.md)[mimeType](_drm.md#mimetype) | 媒体类型 | 
| uint32_t [optionsCount](_drm.md#optionscount) | 操作数数组长度 | 
| [DRM_CharBufferPair](_d_r_m___char_buffer_pair.md)[optionsData](_drm.md#optionsdata) [0] | 操作数数组 | 

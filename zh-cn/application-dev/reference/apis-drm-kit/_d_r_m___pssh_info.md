# DRM_PsshInfo


## 概述

uuid的PSSH信息。

**起始版本：** 11

**相关模块：**[Drm](_drm.md)

**所在头文件：**[native_drm_common.h](native__drm__common_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [uuid](_drm.md#uuid-12) [[DRM_UUID_LEN](_drm.md#drm_uuid_len)] | uuid的PSSH信息。 |
| int32_t [dataLen](_drm.md#datalen-22) | PSSH数据长度。 |
| uint8_t [data](_drm.md#data-22) [[MAX_PSSH_DATA_LEN](_drm.md#max_pssh_data_len)] | PSSH数据。 |

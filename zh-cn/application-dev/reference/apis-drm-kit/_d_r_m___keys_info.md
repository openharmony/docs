# DRM_KeysInfo


## 概述

媒体密钥信息。

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [keysInfoCount](_drm.md#keysinfocount) | 钥匙计数。 | 
| uint8_t [keyId](_drm.md#keyid) [[MAX_KEY_INFO_COUNT](_drm.md#max_key_info_count)][[MAX_KEY_ID_LEN](_drm.md#max_key_id_len)] | 密钥ID集合。 | 
| char [statusValue](_drm.md#statusvalue-12) [[MAX_KEY_INFO_COUNT](_drm.md#max_key_info_count)][[MAX_KEY_STATUS_VALUE_LEN](_drm.md#max_key_status_value_len)] | 关键状态值。 | 

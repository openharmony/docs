# DRM_OfflineMediakeyIdArray


## 概述

离线媒体密钥ID数组。

**起始版本：** 11

**相关模块：**[Drm](_drm.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [idsCount](_drm.md#idscount) | ID计数 | 
| int32_t [idsLen](_drm.md#idslen) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](_drm.md#max_offline_media_key_id_count)] | ID长度集合 | 
| uint8_t [ids](_drm.md#ids) [[MAX_OFFLINE_MEDIA_KEY_ID_COUNT](_drm.md#max_offline_media_key_id_count)][[MAX_OFFLINE_MEDIA_KEY_ID_LEN](_drm.md#max_offline_media_key_id_len)] | ID数据集合 | 

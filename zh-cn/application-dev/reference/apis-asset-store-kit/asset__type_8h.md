# asset_type.h


## 概述

声明调用ASSET接口需要使用的枚举值、数据结构和错误码。

**起始版本：** 11

**相关模块：**[AssetType](_asset_type.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Asset_Blob](_asset___blob.md) | 二进制数组类型，即不定长的字节数组。 |
| [Asset_Value](union_asset___value.md) | 关键资产属性内容。 |
| [Asset_Attr](_asset___attr.md) | 关键资产属性。 |
| [Asset_Result](_asset___result.md) | 关键资产查询结果，用于定义一条关键资产。 |
| [Asset_ResultSet](_asset___result_set.md) | 关键资产查询结果集合，用于定义多条关键资产。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [ASSET_TAG_TYPE_MASK](_asset_type.md#asset_tag_type_mask)&nbsp;&nbsp;&nbsp;(0xF &lt;&lt; 28) | 用于获取关键资产属性类型的掩码。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Asset_TagType](_asset_type.md#asset_tagtype) {<br/>[ASSET_TYPE_BOOL](_asset_type.md) = 0x1 &lt;&lt; 28, <br/>[ASSET_TYPE_NUMBER](_asset_type.md) = 0x2 &lt;&lt; 28,<br/>[ASSET_TYPE_BYTES](_asset_type.md) = 0x3 &lt;&lt; 28 <br/>} | 关键资产属性的类型定义。 |
| [Asset_Tag](_asset_type.md#asset_tag) {<br/>[ASSET_TAG_SECRET](_asset_type.md) = ASSET_TYPE_BYTES \| 0x01, <br/>[ASSET_TAG_ALIAS](_asset_type.md) = ASSET_TYPE_BYTES \| 0x02,<br/>[ASSET_TAG_ACCESSIBILITY](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x03,<br/>[ASSET_TAG_REQUIRE_PASSWORD_SET](_asset_type.md) = ASSET_TYPE_BOOL \| 0x04,<br/>[ASSET_TAG_AUTH_TYPE](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x05, <br/>[ASSET_TAG_AUTH_VALIDITY_PERIOD](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x06, <br/>[ASSET_TAG_AUTH_CHALLENGE](_asset_type.md) = ASSET_TYPE_BYTES \| 0x07, <br/>[ASSET_TAG_AUTH_TOKEN](_asset_type.md) = ASSET_TYPE_BYTES \| 0x08,<br/>[ASSET_TAG_SYNC_TYPE](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x10, <br/>[ASSET_TAG_IS_PERSISTENT](_asset_type.md) = ASSET_TYPE_BOOL \| 0x11,<br/>[ASSET_TAG_DATA_LABEL_CRITICAL_1](_asset_type.md) = ASSET_TYPE_BYTES \| 0x20, <br/>[ASSET_TAG_DATA_LABEL_CRITICAL_2](_asset_type.md) = ASSET_TYPE_BYTES \| 0x21,<br/>[ASSET_TAG_DATA_LABEL_CRITICAL_3](_asset_type.md) = ASSET_TYPE_BYTES \| 0x22, <br/>[ASSET_TAG_DATA_LABEL_CRITICAL_4](_asset_type.md) = ASSET_TYPE_BYTES \| 0x23,<br/>[ASSET_TAG_DATA_LABEL_NORMAL_1](_asset_type.md) = ASSET_TYPE_BYTES \| 0x30, <br/>[ASSET_TAG_DATA_LABEL_NORMAL_2](_asset_type.md) = ASSET_TYPE_BYTES \| 0x31,<br/>[ASSET_TAG_DATA_LABEL_NORMAL_3](_asset_type.md) = ASSET_TYPE_BYTES \| 0x32, <br/>[ASSET_TAG_DATA_LABEL_NORMAL_4](_asset_type.md) = ASSET_TYPE_BYTES \| 0x33,<br/>[ASSET_TAG_RETURN_TYPE](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x40, <br/>[ASSET_TAG_RETURN_LIMIT](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x41,<br/>[ASSET_TAG_RETURN_OFFSET](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x42, <br/>[ASSET_TAG_RETURN_ORDERED_BY](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x43, <br/>[ASSET_TAG_CONFLICT_RESOLUTION](_asset_type.md) = ASSET_TYPE_NUMBER \| 0x44<br/>} | 关键资产属性的名称。 |
| [Asset_ResultCode](_asset_type.md#asset_resultcode) {<br/>[ASSET_SUCCESS](_asset_type.md) = 0, <br/>[ASSET_PERMISSION_DENIED](_asset_type.md) = 201, <br/>[ASSET_INVALID_ARGUMENT](_asset_type.md) = 401, <br/>[ASSET_SERVICE_UNAVAILABLE](_asset_type.md) = 24000001,<br/>[ASSET_NOT_FOUND](_asset_type.md) = 24000002, <br/>[ASSET_DUPLICATED](_asset_type.md) = 24000003, <br/>[ASSET_ACCESS_DENIED](_asset_type.md) = 24000004, <br/>[ASSET_STATUS_MISMATCH](_asset_type.md) = 24000005,<br/>[ASSET_OUT_OF_MEMORY](_asset_type.md) = 24000006,<br/>[ASSET_DATA_CORRUPTED](_asset_type.md) = 24000007, <br/>[ASSET_DATABASE_ERROR](_asset_type.md) = 24000008, <br/>[ASSET_CRYPTO_ERROR](_asset_type.md) = 24000009,<br/>[ASSET_IPC_ERROR](_asset_type.md) = 24000010,<br/>[ASSET_BMS_ERROR](_asset_type.md) = 24000011,<br/>[ASSET_ACCOUNT_ERROR](_asset_type.md) = 24000012,<br/>[ASSET_ACCESS_TOKEN_ERROR](_asset_type.md) = 24000013,<br/>[ASSET_FILE_OPERATION_ERROR](_asset_type.md) = 24000014, <br/>[ASSET_GET_SYSTEM_TIME_ERROR](_asset_type.md) = 24000015, <br/>[ASSET_LIMIT_EXCEEDED](_asset_type.md) = 24000016,<br/>[ASSET_UNSUPPORTED](_asset_type.md) = 24000017<br/>} | 调用ASSET返回的结果码。 |
| [Asset_Accessibility](_asset_type.md#asset_accessibility) { <br/>[ASSET_ACCESSIBILITY_DEVICE_POWERED_ON](_asset_type.md) = 0,<br/>[ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED](_asset_type.md) = 1, <br/>[ASSET_ACCESSIBILITY_DEVICE_UNLOCKED](_asset_type.md) = 2 } | 基于锁屏状态的访问控制类型。 |
| [Asset_AuthType](_asset_type.md#asset_authtype) { <br/>[ASSET_AUTH_TYPE_NONE](_asset_type.md) = 0x00, <br/>[ASSET_AUTH_TYPE_ANY](_asset_type.md) = 0xFF<br/>} | 关键资产支持的用户认证类型。 |
| [Asset_SyncType](_asset_type.md#asset_synctype) { <br/>[ASSET_SYNC_TYPE_NEVER](_asset_type.md) = 0, <br/>[ASSET_SYNC_TYPE_THIS_DEVICE](_asset_type.md) = 1 &lt;&lt; 0, <br/>[ASSET_SYNC_TYPE_TRUSTED_DEVICE](_asset_type.md) = 1 &lt;&lt; 1<br/>} | 关键资产支持的同步类型。 |
| [Asset_ConflictResolution](_asset_type.md#asset_conflictresolution) { <br/>[ASSET_CONFLICT_OVERWRITE](_asset_type.md) = 0, <br/>[ASSET_CONFLICT_THROW_ERROR](_asset_type.md) = 1<br/>} | 新增关键资产时的冲突（如：别名相同）处理策略。 |
| [Asset_ReturnType](_asset_type.md#asset_returntype) { <br/>[ASSET_RETURN_ALL](_asset_type.md) = 0, <br/>[ASSET_RETURN_ATTRIBUTES](_asset_type.md) = 1<br/>} | 关键资产查询返回的结果类型。 |

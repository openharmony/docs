# asset_type.h


## 概述

定义关键资产存储服务中通用的枚举值、数据结构和错误码。

**库：** libasset_ndk.z.so

**系统能力：** SystemCapability.Security.Asset

**起始版本：** 11

**相关模块：**[AssetType](_asset_type.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [Asset_Blob](_asset___blob.md) | 二进制数组类型，即不定长的字节数组。 |
| union  [Asset_Value](union_asset___value.md) | 关键资产属性内容。 |
| struct  [Asset_Attr](_asset___attr.md) | 关键资产属性。 |
| struct  [Asset_Result](_asset___result.md) | 关键资产查询结果，用于定义一条关键资产。 |
| struct  [Asset_ResultSet](_asset___result_set.md) | 关键资产查询结果集合，用于定义多条关键资产。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [ASSET_TAG_TYPE_MASK](_asset_type.md#asset_tag_type_mask)   (0xF &lt;&lt; 28) | 用于获取关键资产属性类型的掩码。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Asset_TagType](_asset_type.md#asset_tagtype) {<br/>ASSET_TYPE_BOOL = 0x1 &lt;&lt; 28,<br/>ASSET_TYPE_NUMBER = 0x2 &lt;&lt; 28,<br/>ASSET_TYPE_BYTES = 0x3 &lt;&lt; 28 } | 关键资产属性的类型定义。 |
| [Asset_Tag](_asset_type.md#asset_tag) {<br/>ASSET_TAG_SECRET = ASSET_TYPE_BYTES \| 0x01,<br/>ASSET_TAG_ALIAS = ASSET_TYPE_BYTES \| 0x02,<br/>ASSET_TAG_ACCESSIBILITY = ASSET_TYPE_NUMBER \| 0x03,<br/>ASSET_TAG_REQUIRE_PASSWORD_SET = ASSET_TYPE_BOOL \| 0x04,<br/>ASSET_TAG_AUTH_TYPE = ASSET_TYPE_NUMBER \| 0x05,<br/>ASSET_TAG_AUTH_VALIDITY_PERIOD = ASSET_TYPE_NUMBER \| 0x06,<br/>ASSET_TAG_AUTH_CHALLENGE = ASSET_TYPE_BYTES \| 0x07,<br/>ASSET_TAG_AUTH_TOKEN = ASSET_TYPE_BYTES \| 0x08,<br/>ASSET_TAG_SYNC_TYPE = ASSET_TYPE_NUMBER \| 0x10,<br/>ASSET_TAG_IS_PERSISTENT = ASSET_TYPE_BOOL \| 0x11,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_1 = ASSET_TYPE_BYTES \| 0x20,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_2 = ASSET_TYPE_BYTES \| 0x21,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_3 = ASSET_TYPE_BYTES \| 0x22,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_4 = ASSET_TYPE_BYTES \| 0x23,<br/>ASSET_TAG_DATA_LABEL_NORMAL_1 = ASSET_TYPE_BYTES \| 0x30,<br/>ASSET_TAG_DATA_LABEL_NORMAL_2 = ASSET_TYPE_BYTES \| 0x31,<br/>ASSET_TAG_DATA_LABEL_NORMAL_3 = ASSET_TYPE_BYTES \| 0x32,<br/>ASSET_TAG_DATA_LABEL_NORMAL_4 = ASSET_TYPE_BYTES \| 0x33,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x34,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x35,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x36,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x37,<br/>ASSET_TAG_RETURN_TYPE = ASSET_TYPE_NUMBER \| 0x40,<br/>ASSET_TAG_RETURN_LIMIT = ASSET_TYPE_NUMBER \| 0x41,<br/>ASSET_TAG_RETURN_OFFSET = ASSET_TYPE_NUMBER \| 0x42,<br/>ASSET_TAG_RETURN_ORDERED_BY = ASSET_TYPE_NUMBER \| 0x43,<br/>ASSET_TAG_CONFLICT_RESOLUTION = ASSET_TYPE_NUMBER \| 0x44,<br/>ASSET_TAG_UPDATE_TIME<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x45,<br/>ASSET_TAG_OPERATION_TYPE<sup>12+</sup> = ASSET_TYPE_NUMBER \| 0x46,<br/>ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> = ASSET_TYPE_BOOL \| 0x47,<br/>ASSET_TAG_GROUP_ID<sup>16+</sup> = ASSET_TYPE_BYTES \| 0x48,<br/>ASSET_TAG_WRAP_TYPE<sup>16+</sup> = ASSET_TYPE_NUMBER \| 0x49,<br/>} | 关键资产属性的名称。 |
| [Asset_ResultCode](_asset_type.md#asset_resultcode) {<br/>ASSET_SUCCESS = 0,<br/>ASSET_PERMISSION_DENIED = 201,<br/>ASSET_INVALID_ARGUMENT = 401,<br/>ASSET_SERVICE_UNAVAILABLE = 24000001,<br/>ASSET_NOT_FOUND = 24000002,<br/>ASSET_DUPLICATED = 24000003,<br/>ASSET_ACCESS_DENIED = 24000004,<br/>ASSET_STATUS_MISMATCH = 24000005,<br/>ASSET_OUT_OF_MEMORY = 24000006,<br/>ASSET_DATA_CORRUPTED = 24000007,<br/>ASSET_DATABASE_ERROR = 24000008,<br/>ASSET_CRYPTO_ERROR = 24000009,<br/>ASSET_IPC_ERROR = 24000010,<br/>ASSET_BMS_ERROR = 24000011,<br/>ASSET_ACCOUNT_ERROR = 24000012,<br/>ASSET_ACCESS_TOKEN_ERROR = 24000013,<br/>ASSET_FILE_OPERATION_ERROR = 24000014,<br/>ASSET_GET_SYSTEM_TIME_ERROR = 24000015,<br/>ASSET_LIMIT_EXCEEDED = 24000016,<br/>ASSET_UNSUPPORTED = 24000017<br/>} | 调用ASSET返回的结果码。 |
| [Asset_Accessibility](_asset_type.md#asset_accessibility) {<br/>ASSET_ACCESSIBILITY_DEVICE_POWERED_ON = 0,<br/>ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED = 1,<br/>ASSET_ACCESSIBILITY_DEVICE_UNLOCKED = 2<br/>} | 基于锁屏状态的访问控制类型。 |
| [Asset_AuthType](_asset_type.md#asset_authtype) { ASSET_AUTH_TYPE_NONE = 0x00,<br/>ASSET_AUTH_TYPE_ANY = 0xFF } | 关键资产支持的用户认证类型。 |
| [Asset_SyncType](_asset_type.md#asset_synctype) {<br/>ASSET_SYNC_TYPE_NEVER = 0,<br/>ASSET_SYNC_TYPE_THIS_DEVICE = 1 &lt;&lt; 0,<br/>ASSET_SYNC_TYPE_TRUSTED_DEVICE = 1 &lt;&lt; 1,<br/>ASSET_SYNC_TYPE_TRUSTED_ACCOUNT<sup>12+</sup> = 1 &lt;&lt; 2<br/>} | 关键资产支持的同步类型。 |
| [Asset_ConflictResolution](_asset_type.md#asset_conflictresolution) {<br/>ASSET_CONFLICT_OVERWRITE = 0,<br/>ASSET_CONFLICT_THROW_ERROR = 1<br/>} | 新增关键资产时的冲突（如：别名相同）处理策略。 |
| [Asset_ReturnType](_asset_type.md#asset_returntype) {<br/>ASSET_RETURN_ALL = 0,<br/>ASSET_RETURN_ATTRIBUTES = 1<br/>} | 关键资产查询返回的结果类型。 |
| [Asset_OperationType](_asset_type.md#asset_operationtype)<sup>12+</sup> {<br/>ASSET_NEED_SYNC = 0,<br/>ASSET_NEED_LOGOUT = 1<br/>} | 附属的操作类型。 |
| [Asset_WrapType](_asset_type.md#asset_wraptype)<sup>16+</sup> {<br/>ASSET_WRAP_TYPE_NEVER = 0,<br/>ASSET_WRAP_TYPE_TRUSTED_ACCOUNT = 1<br/>} | 关键资产支持的加密导入导出类型。 |

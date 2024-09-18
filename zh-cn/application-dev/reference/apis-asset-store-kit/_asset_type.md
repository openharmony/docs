# AssetType


## 概述

提供关键资产存储服务中通用的枚举值、数据结构和错误码。

**系统能力：** SystemCapability.Security.Asset

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [asset_type.h](asset__type_8h.md) | 定义关键资产存储服务中通用的枚举值、数据结构和错误码。 |


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
| [ASSET_TAG_TYPE_MASK](#asset_tag_type_mask)   (0xF &lt;&lt; 28) | 用于获取关键资产属性类型的掩码。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Asset_TagType](#asset_tagtype) {<br/>ASSET_TYPE_BOOL = 0x1 &lt;&lt; 28,<br/>ASSET_TYPE_NUMBER = 0x2 &lt;&lt; 28,<br/>ASSET_TYPE_BYTES = 0x3 &lt;&lt; 28 } | 关键资产属性的类型定义。 |
| [Asset_Tag](#asset_tag) {<br/>ASSET_TAG_SECRET = ASSET_TYPE_BYTES \| 0x01,<br/>ASSET_TAG_ALIAS = ASSET_TYPE_BYTES \| 0x02,<br/>ASSET_TAG_ACCESSIBILITY = ASSET_TYPE_NUMBER \| 0x03,<br/>ASSET_TAG_REQUIRE_PASSWORD_SET = ASSET_TYPE_BOOL \| 0x04,<br/>ASSET_TAG_AUTH_TYPE = ASSET_TYPE_NUMBER \| 0x05,<br/>ASSET_TAG_AUTH_VALIDITY_PERIOD = ASSET_TYPE_NUMBER \| 0x06,<br/>ASSET_TAG_AUTH_CHALLENGE = ASSET_TYPE_BYTES \| 0x07,<br/>ASSET_TAG_AUTH_TOKEN = ASSET_TYPE_BYTES \| 0x08,<br/>ASSET_TAG_SYNC_TYPE = ASSET_TYPE_NUMBER \| 0x10,<br/>ASSET_TAG_IS_PERSISTENT = ASSET_TYPE_BOOL \| 0x11,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_1 = ASSET_TYPE_BYTES \| 0x20,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_2 = ASSET_TYPE_BYTES \| 0x21,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_3 = ASSET_TYPE_BYTES \| 0x22,<br/>ASSET_TAG_DATA_LABEL_CRITICAL_4 = ASSET_TYPE_BYTES \| 0x23,<br/>ASSET_TAG_DATA_LABEL_NORMAL_1 = ASSET_TYPE_BYTES \| 0x30,<br/>ASSET_TAG_DATA_LABEL_NORMAL_2 = ASSET_TYPE_BYTES \| 0x31,<br/>ASSET_TAG_DATA_LABEL_NORMAL_3 = ASSET_TYPE_BYTES \| 0x32,<br/>ASSET_TAG_DATA_LABEL_NORMAL_4 = ASSET_TYPE_BYTES \| 0x33,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x34,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x35,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x36,<br/>ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x37,<br/>ASSET_TAG_RETURN_TYPE = ASSET_TYPE_NUMBER \| 0x40,<br/>ASSET_TAG_RETURN_LIMIT = ASSET_TYPE_NUMBER \| 0x41,<br/>ASSET_TAG_RETURN_OFFSET = ASSET_TYPE_NUMBER \| 0x42,<br/>ASSET_TAG_RETURN_ORDERED_BY = ASSET_TYPE_NUMBER \| 0x43,<br/>ASSET_TAG_CONFLICT_RESOLUTION = ASSET_TYPE_NUMBER \| 0x44,<br/>ASSET_TAG_UPDATE_TIME<sup>12+</sup> = ASSET_TYPE_BYTES \| 0x45,<br/>ASSET_TAG_OPERATION_TYPE<sup>12+</sup> = ASSET_TYPE_NUMBER \| 0x46,<br/>ASSET_TAG_REQUIRE_ATTR_ENCRYPTED = ASSET_TYPE_BOOL \| 0x47,<br/>} | 关键资产属性的名称。 |
| [Asset_ResultCode](#asset_resultcode) {<br/>ASSET_SUCCESS = 0,<br/>ASSET_PERMISSION_DENIED = 201,<br/>ASSET_INVALID_ARGUMENT = 401,<br/>ASSET_SERVICE_UNAVAILABLE = 24000001,<br/>ASSET_NOT_FOUND = 24000002,<br/>ASSET_DUPLICATED = 24000003,<br/>ASSET_ACCESS_DENIED = 24000004,<br/>ASSET_STATUS_MISMATCH = 24000005,<br/>ASSET_OUT_OF_MEMORY = 24000006,<br/>ASSET_DATA_CORRUPTED = 24000007,<br/>ASSET_DATABASE_ERROR = 24000008,<br/>ASSET_CRYPTO_ERROR = 24000009,<br/>ASSET_IPC_ERROR = 24000010,<br/>ASSET_BMS_ERROR = 24000011,<br/>ASSET_ACCOUNT_ERROR = 24000012,<br/>ASSET_ACCESS_TOKEN_ERROR = 24000013,<br/>ASSET_FILE_OPERATION_ERROR = 24000014,<br/>ASSET_GET_SYSTEM_TIME_ERROR = 24000015,<br/>ASSET_LIMIT_EXCEEDED = 24000016,<br/>ASSET_UNSUPPORTED = 24000017<br/>} | 调用ASSET返回的结果码。 |
| [Asset_Accessibility](#asset_accessibility) {<br/>ASSET_ACCESSIBILITY_DEVICE_POWERED_ON = 0,<br/>ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED = 1,<br/>ASSET_ACCESSIBILITY_DEVICE_UNLOCKED = 2<br/>} | 基于锁屏状态的访问控制类型。 |
| [Asset_AuthType](#asset_authtype) { ASSET_AUTH_TYPE_NONE = 0x00,<br/>ASSET_AUTH_TYPE_ANY = 0xFF } | 关键资产支持的用户认证类型。 |
| [Asset_SyncType](#asset_synctype) {<br/>ASSET_SYNC_TYPE_NEVER = 0,<br/>ASSET_SYNC_TYPE_THIS_DEVICE = 1 &lt;&lt; 0,<br/>ASSET_SYNC_TYPE_TRUSTED_DEVICE = 1 &lt;&lt; 1,<br/>ASSET_SYNC_TYPE_TRUSTED_ACCOUNT<sup>12+</sup> = 1 &lt;&lt; 2<br/>} | 关键资产支持的同步类型。 |
| [Asset_ConflictResolution](#asset_conflictresolution) {<br/>ASSET_CONFLICT_OVERWRITE = 0,<br/>ASSET_CONFLICT_THROW_ERROR = 1<br/>} | 新增关键资产时的冲突（如：别名相同）处理策略。 |
| [Asset_ReturnType](#asset_returntype) {<br/>ASSET_RETURN_ALL = 0,<br/>ASSET_RETURN_ATTRIBUTES = 1<br/>} | 关键资产查询返回的结果类型。 |
| [Asset_OperationType](#asset_operationtype) {<br/>ASSET_NEED_SYNC = 0,<br/>ASSET_NEED_LOGOUT = 1<br/>} | 附属的操作类型。 |


## 宏定义说明


### ASSET_TAG_TYPE_MASK

```
#define ASSET_TAG_TYPE_MASK   (0xF << 28)
```

**描述**

用于获取关键资产属性类型的掩码。

**起始版本：** 11


## 枚举类型说明


### Asset_Accessibility

```
enum Asset_Accessibility
```

**描述**

基于锁屏状态的访问控制类型。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_ACCESSIBILITY_DEVICE_POWERED_ON | 开机后可访问。 |
| ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED | 首次解锁后可访问。 |
| ASSET_ACCESSIBILITY_DEVICE_UNLOCKED | 解锁时可访问。 |


### Asset_AuthType

```
enum Asset_AuthType
```

**描述**

关键资产支持的用户认证类型。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_AUTH_TYPE_NONE | 访问关键资产前无需用户认证。 |
| ASSET_AUTH_TYPE_ANY | 任意一种用户认证方式（PIN码、人脸、指纹等）通过后，均可访问关键资产。 |


### Asset_ConflictResolution

```
enum Asset_ConflictResolution
```

**描述**

新增关键资产时的冲突（如：别名相同）处理策略。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_CONFLICT_OVERWRITE | 覆盖原本的关键资产。 |
| ASSET_CONFLICT_THROW_ERROR | 抛出异常，由业务进行后续处理。 |


### Asset_ResultCode

```
enum Asset_ResultCode
```

**描述**

调用ASSET返回的结果码。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_SUCCESS | 表示操作成功。 |
| ASSET_PERMISSION_DENIED | 表示调用者没有权限。 |
| ASSET_INVALID_ARGUMENT | 表示参数错误。 |
| ASSET_SERVICE_UNAVAILABLE | 表示关键资产服务不可用。 |
| ASSET_NOT_FOUND | 表示未找到关键资产。 |
| ASSET_DUPLICATED | 表示关键资产已存在。 |
| ASSET_ACCESS_DENIED | 表示拒绝访问关键资产。 |
| ASSET_STATUS_MISMATCH | 表示锁屏状态不匹配。 |
| ASSET_OUT_OF_MEMORY | 表示系统内存不足。 |
| ASSET_DATA_CORRUPTED | 表示关键资产损坏。 |
| ASSET_DATABASE_ERROR | 表示数据库操作失败。 |
| ASSET_CRYPTO_ERROR | 表示算法库操作失败。 |
| ASSET_IPC_ERROR | 表示进程通信错误。 |
| ASSET_BMS_ERROR | 表示包管理服务异常。 |
| ASSET_ACCOUNT_ERROR | 表示账号系统异常。 |
| ASSET_ACCESS_TOKEN_ERROR | 表示访问控制服务异常。 |
| ASSET_FILE_OPERATION_ERROR | 表示文件操作失败。 |
| ASSET_GET_SYSTEM_TIME_ERROR | 表示获取系统时间失败。 |
| ASSET_LIMIT_EXCEEDED | 表示缓存数量超限。 |
| ASSET_UNSUPPORTED | 表示该子功能不支持。 |


### Asset_ReturnType

```
enum Asset_ReturnType
```

**描述**

关键资产查询返回的结果类型。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_RETURN_ALL | 返回关键资产明文及属性。 |
| ASSET_RETURN_ATTRIBUTES | 返回关键资产属性，不含关键资产明文。 |


### Asset_SyncType

```
enum Asset_SyncType
```

**描述**

关键资产支持的同步类型。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_SYNC_TYPE_NEVER | 不允许同步关键资产。 |
| ASSET_SYNC_TYPE_THIS_DEVICE | 只在本设备进行同步，如仅在本设备还原的备份场景。 |
| ASSET_SYNC_TYPE_TRUSTED_DEVICE | 只在可信设备间进行同步，如克隆场景。 |
| ASSET_SYNC_TYPE_TRUSTED_ACCOUNT | 只在登录可信账号的设备间进行同步，如云同步场景。<br>**起始版本：** 12 |


### Asset_Tag

```
enum Asset_Tag
```

**描述**

关键资产属性的名称。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_TAG_SECRET | 表示用户敏感数据，如口令、令牌等，其值为bytes类型。 |
| ASSET_TAG_ALIAS | 表示一个关键资产的标识，其值为bytes类型。 |
| ASSET_TAG_ACCESSIBILITY | 表示关键资产何时可访问，其值为uint32_t类型。 |
| ASSET_TAG_REQUIRE_PASSWORD_SET | 表示关键资产是否在设备是否设置了锁屏密码时可用，其值为bool类型。 |
| ASSET_TAG_AUTH_TYPE | 表示关键资产需要的用户认证类型，其值为uint32_t类型。 |
| ASSET_TAG_AUTH_VALIDITY_PERIOD | 表示用户认证的有效时间，其值为uint32_t类型，单位为秒。 |
| ASSET_TAG_AUTH_CHALLENGE | 表示认证时防重放用的挑战值，其值为bytes类型。 |
| ASSET_TAG_AUTH_TOKEN | 表示用户认证后获取到的认证令牌，其值为bytes类型。 |
| ASSET_TAG_SYNC_TYPE | 表示关键资产的同步类型，其值为uint32_t类型。 |
| ASSET_TAG_IS_PERSISTENT | 表示关键资产是否需持久化存储，其值为bool类型。 |
| ASSET_TAG_DATA_LABEL_CRITICAL_1 | 表示一个用户可自定义传入的字段，该字段不可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_CRITICAL_2 | 表示一个用户可自定义传入的字段，该字段不可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_CRITICAL_3 | 表示一个用户可自定义传入的字段，该字段不可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_CRITICAL_4 | 表示一个用户可自定义传入的字段，该字段不可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_NORMAL_1 | 表示一个用户可自定义传入的字段，该字段可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_NORMAL_2 | 表示一个用户可自定义传入的字段，该字段可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_NORMAL_3 | 表示一个用户可自定义传入的字段，该字段可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_NORMAL_4 | 表示一个用户可自定义传入的字段，该字段可被更新，其值为bytes类型。 |
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1 | 表示一个用户可自定义传入的字段，该字段可被更新，该项信息不会进行同步，其值为bytes类型。<br>**起始版本：** 12 |
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2 | 表示一个用户可自定义传入的字段，该字段可被更新，该项信息不会进行同步，其值为bytes类型。<br>**起始版本：** 12 |
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3 | 表示一个用户可自定义传入的字段，该字段可被更新，该项信息不会进行同步，其值为bytes类型。<br>**起始版本：** 12 |
| ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4 | 表示一个用户可自定义传入的字段，该字段可被更新，该项信息不会进行同步，其值为bytes类型。<br>**起始版本：** 12 |
| ASSET_TAG_RETURN_TYPE | 表示查询关键资产时的返回类型，其值为uint32_t类型。 |
| ASSET_TAG_RETURN_LIMIT | 表示查询关键资产时的最大返回数量，其值为uint32_t类型。 |
| ASSET_TAG_RETURN_OFFSET | 表示查询关键资产时的偏移量，其值为uint32_t类型。 |
| ASSET_TAG_RETURN_ORDERED_BY | 表示查询关键资产时的排序依据，其值为uint32_t类型。 |
| ASSET_TAG_CONFLICT_RESOLUTION | 表示增加关键资产时的冲突处理策略，其值为uint32_t类型。 |
| ASSET_TAG_UPDATE_TIME | 表示关键资产的更新时间（时间戳形式），其值为bytes类型。<br>**起始版本：** 12 |
| ASSET_TAG_OPERATION_TYPE | 表示附加的操作类型，其值为uint32_t类型。<br>**起始版本：** 12 |
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED | 表示是否加密业务自定义附属信息，其值为bool类型。<br>**起始版本：** 13 |


### Asset_TagType

```
enum Asset_TagType
```

**描述**

关键资产属性的类型定义。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_TYPE_BOOL | 标识关键资产属性的类型是bool。 |
| ASSET_TYPE_NUMBER | 标识关键资产属性的类型是uint32_t。 |
| ASSET_TYPE_BYTES | 标识关键资产属性的类型是byte数组。 |


### Asset_OperationType

```
enum Asset_OperationType
```

**描述**

附属的操作类型。

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| ASSET_NEED_SYNC | 需要进行同步操作。 |
| ASSET_NEED_LOGOUT | 需要进行登出操作。 |

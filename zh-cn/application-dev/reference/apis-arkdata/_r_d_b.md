# RDB


## 概述

关系型数据库（Relational Database，RDB）是一种基于关系模型来管理数据的数据库。关系型数据库基于SQLite组件提供了一套完整的 对本地数据库进行管理的机制，对外提供了一系列的增、删、改、查等接口，也可以直接运行用户输入的SQL语句来满足复杂的场景需要。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [oh_cursor.h](oh__cursor_8h.md) | 提供通过查询数据库生成的数据库结果集的访问方法。<br/>**引用文件：** <database/rdb/oh_cursor.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [oh_data_value.h](oh__data__value_8h.md) | 提供与单条数据值相关的函数和枚举。<br/>从API version 18开始，OH_ColumnType从oh_cursor.h移动至此头文件呈现，对于此类型，API version 18之前即支持使用，各版本均可正常使用。<br/>**引用文件：** <database/rdb/oh_data_value.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [oh_data_values.h](oh__data__values_8h.md) | 提供与多条数据值相关的函数和枚举。<br/>**引用文件：** <database/rdb/oh_data_values.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [oh_data_values_buckets.h](oh__data__values__buckets_8h.md) | 提供与存储数据值相关的结构定义、函数和枚举。<br/>**引用文件：** <database/rdb/oh_data_values_buckets.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [oh_predicates.h](oh__predicates_8h.md) | 表示关系型数据库（RDB）的谓词。<br/>**引用文件：** <database/rdb/oh_predicates.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [oh_rdb_transaction.h](oh__rdb__transaction_8h.md) | 提供与数据库事务相关的函数和枚举。<br/>**引用文件：** <database/rdb/oh_rdb_transaction.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [oh_rdb_types.h](oh__rdb__types_8h.md) | 提供与数据值相关的类型定义。<br/>**引用文件：** <database/rdb/oh_rdb_types.h><br/>**库：** libnative_rdb_ndk.z.so<br/> | 
| [oh_value_object.h](oh__value__object_8h.md) | 提供类型转换方法。<br/>**引用文件：** <database/rdb/oh_value_object.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [oh_values_bucket.h](oh__values__bucket_8h.md) | 用于存储键值对的类型。<br/>**引用文件：** <database/rdb/oh_values_bucket.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [relational_store.h](relational__store_8h.md) | 提供管理关系数据库（RDB）方法的接口，未标注支持向量数据库的接口仅支持关系型数据库。<br/>**引用文件：** <database/rdb/relational_store.h><br/>**库：** libnative_rdb_ndk.z.so<br/> |
| [relational_store_error_code.h](relational__store__error__code_8h.md) | 声明关系型数据库（RDB）的错误码信息。<br/>**引用文件：** <database/rdb/relational_store_error_code.h><br/>**库：** libnative_rdb_ndk.z.so |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_Cursor](_o_h___cursor.md) | 表示结果集。 |
| [OH_Predicates](_o_h___predicates.md) | 表示谓词。 |
| [OH_VObject](_o_h___v_object.md) | 表示允许的数据字段类型。 |
| [OH_VBucket](_o_h___v_bucket.md) | 用于存储键值对的类型。 |
| [OH_Rdb_Config](_o_h___rdb___config.md) | 管理关系数据库配置。 |
| [OH_Rdb_Store](_o_h___rdb___store.md) | 表示数据库类型。 |
| [Rdb_DistributedConfig](_rdb___distributed_config.md) | 记录表的分布式配置信息。 |
| [Rdb_KeyInfo](_rdb___key_info.md) | 描述发生变化的行的主键或者行号。 |
| [Rdb_KeyInfo::Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) | 存放变化的具体数据。 |
| [Rdb_ChangeInfo](_rdb___change_info.md) | 记录端云同步过程详情。 |
| [Rdb_SubscribeCallback](union_rdb___subscribe_callback.md) | 表示回调函数。 |
| [Rdb_DataObserver](_rdb___data_observer.md) | 表示数据观察者。 |
| [Rdb_Statistic](_rdb___statistic.md) | 描述数据库表的端云同步过程的统计信息。 |
| [Rdb_TableDetails](_rdb___table_details.md) | 描述数据库表执行端云同步任务上传和下载的统计信息。 |
| [Rdb_ProgressDetails](_rdb___progress_details.md) | 描述数据库整体执行端云同步任务上传和下载的统计信息。 |
| [Rdb_ProgressObserver](_rdb___progress_observer.md) | 端云同步进度观察者。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [DISTRIBUTED_CONFIG_VERSION](#distributed_config_version)&nbsp;&nbsp;&nbsp;1 | 描述[Rdb_DistributedConfig](_rdb___distributed_config.md)的版本。 |
| [DISTRIBUTED_CHANGE_INFO_VERSION](#distributed_change_info_version)&nbsp;&nbsp;&nbsp;1 | 描述[Rdb_ChangeInfo](_rdb___change_info.md)的版本。 |
| [DISTRIBUTED_PROGRESS_DETAIL_VERSION](#distributed_progress_detail_version)&nbsp;&nbsp;&nbsp;1 | 描述[Rdb_ProgressDetails](_rdb___progress_details.md)的版本。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [Rdb_ConflictResolution](#rdb_conflictresolution) [Rdb_ConflictResolution](#rdb_conflictresolution) | 表示冲突解决策略的枚举。 |
| typedef struct [OH_Rdb_ConfigV2](#oh_rdb_configv2) [OH_Rdb_ConfigV2](#oh_rdb_configv2) | 管理关系数据库配置，与[OH_Rdb_Config](_o_h___rdb___config.md)的区别是该结构体成员变量不对外暴露，使用一系列方法配置该结构体的属性，支持向量数据库。 |
| typedef enum [Rdb_DBType](#rdb_dbtype) [Rdb_DBType](#rdb_dbtype) | 描述数据库的内核类型。 |
| typedef enum [Rdb_Tokenizer](#rdb_tokenizer) [Rdb_Tokenizer](#rdb_tokenizer) | 描述数据库的分词器类型。 |
| typedef enum [OH_ColumnType](#oh_columntype) [OH_ColumnType](#oh_columntype) | 表示列的类型。 |
| typedef struct [OH_Data_Value](#oh_data_value) [OH_Data_Value](#oh_data_value) | 定义[OH_Data_Value](#oh_data_value)结构类型。 |
| typedef struct [OH_Data_Values](#oh_data_values) [OH_Data_Values](#oh_data_values) | 定义[OH_Data_Values](#oh_data_values)结构类型。 |
| typedef struct [OH_Data_VBuckets](#oh_data_vbuckets) [OH_Data_VBuckets](#oh_data_vbuckets) | 定义OH_Data_VBuckets结构类型。 |
| typedef enum [OH_RDB_TransType](#oh_rdb_transtype) [OH_RDB_TransType](#oh_rdb_transtype) | 表示关系型数据库事务类型。 |
| typedef struct [OH_RDB_TransOptions](#oh_rdb_transoptions) [OH_RDB_TransOptions](#oh_rdb_transoptions) | 定义[OH_RDB_TransOptions](#oh_rdb_transoptions)结构类型。 |
| typedef struct [OH_Rdb_Transaction](#oh_rdb_transaction) [OH_Rdb_Transaction](#oh_rdb_transaction) | 定义[OH_Rdb_Transaction](#oh_rdb_transaction)结构类型。 |
| [OH_Cursor](#oh_cursor) | 表示结果集。 |
| [OH_OrderType](#oh_ordertype) | 排序方式。 |
| [OH_Predicates](#oh_predicates) | 表示谓词。 |
| [OH_VObject](#oh_vobject) | 表示允许的数据字段类型。 |
| [OH_VBucket](#oh_vbucket) | 用于存储键值对的类型。 |
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) | 数据库的安全级别枚举。 |
| [Rdb_SecurityArea](#rdb_securityarea) | 描述数据库的安全区域等级。 |
| [Rdb_DistributedType](#rdb_distributedtype) | 描述表的分布式类型的枚举。 |
| [Rdb_DistributedConfig](#rdb_distributedconfig) | 记录表的分布式配置信息。 |
| [Rdb_ChangeType](#rdb_changetype) | 描述数据变更类型。 |
| [Rdb_KeyInfo](#rdb_keyinfo) | 描述发生变化的行的主键或者行号。 |
| [Rdb_ChangeInfo](#rdb_changeinfo) | 记录端云同步过程详情。 |
| [Rdb_SubscribeType](#rdb_subscribetype) | 描述订阅类型。 |
| [Rdb_BriefObserver](#rdb_briefobserver) | 端云数据更改事件的回调函数。 |
| [Rdb_DetailsObserver](#rdb_detailsobserver) | 端云数据更改事件的细节的回调函数。 |
| [Rdb_SubscribeCallback](#rdb_subscribecallback) | 表示回调函数。 |
| [Rdb_DataObserver](#rdb_dataobserver) | 表示数据观察者。 |
| [Rdb_SyncMode](#rdb_syncmode) | 表示数据库的同步模式。 |
| [Rdb_Statistic](#rdb_statistic) | 描述数据库表的端云同步过程的统计信息。 |
| [Rdb_TableDetails](#rdb_tabledetails) | 描述数据库表执行端云同步任务上传和下载的统计信息。 |
| [Rdb_Progress](#rdb_progress) | 描述端云同步过程。 |
| [Rdb_ProgressCode](#rdb_progresscode) | 表示端云同步过程的状态。 |
| [Rdb_ProgressDetails](#rdb_progressdetails) | 描述数据库整体执行端云同步任务上传和下载的统计信息。 |
| [Rdb_ProgressCallback](#rdb_progresscallback) | 端云同步进度的回调函数。 |
| [Rdb_SyncCallback](#rdb_synccallback) | 数据库端云同步的回调函数。 |
| [Rdb_ProgressObserver](#rdb_progressobserver) | 端云同步进度观察者。 |
| [OH_Rdb_ErrCode](#oh_rdb_errcode) | 表示错误码信息。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [Rdb_DBType](#rdb_dbtype-1) { RDB_SQLITE = 1, RDB_CAYLEY = 2, DBTYPE_BUTT = 64 } | 描述数据库的内核类型。 |
| [OH_OrderType](#oh_ordertype-1) { ASC = 0, DESC = 1 } | 排序方式。 |
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel-1) { S1 = 1, S2, S3, S4 } | 数据库的安全级别枚举。 |
| [Rdb_SecurityArea](#rdb_securityarea-1) { RDB_SECURITY_AREA_EL1 = 1, RDB_SECURITY_AREA_EL2, RDB_SECURITY_AREA_EL3, RDB_SECURITY_AREA_EL4 } | 描述数据库的安全区域等级。 |
| [Rdb_DistributedType](#rdb_distributedtype-1) { RDB_DISTRIBUTED_CLOUD } | 描述表的分布式类型的枚举。 |
| [Rdb_ChangeType](#rdb_changetype-1) { RDB_DATA_CHANGE, RDB_ASSET_CHANGE } | 描述数据变更类型。 |
| [Rdb_SubscribeType](#rdb_subscribetype-1) { RDB_SUBSCRIBE_TYPE_CLOUD, RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS, RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS } | 描述订阅类型。 |
| [Rdb_SyncMode](#rdb_syncmode-1) { RDB_SYNC_MODE_TIME_FIRST, RDB_SYNC_MODE_NATIVE_FIRST, RDB_SYNC_MODE_CLOUD_FIRST } | 表示数据库的同步模式。 |
| [Rdb_Progress](#rdb_progress-1) { RDB_SYNC_BEGIN, RDB_SYNC_IN_PROGRESS, RDB_SYNC_FINISH } | 描述端云同步过程。 |
| [Rdb_ProgressCode](#rdb_progresscode-1) {<br/>RDB_SUCCESS, RDB_UNKNOWN_ERROR, RDB_NETWORK_ERROR, RDB_CLOUD_DISABLED,<br/>RDB_LOCKED_BY_OTHERS, RDB_RECORD_LIMIT_EXCEEDED, RDB_NO_SPACE_FOR_ASSET<br/>} | 表示端云同步过程的状态。 |
| [OH_ColumnType](#oh_columntype-1) {<br/>TYPE_NULL = 0, TYPE_INT64, TYPE_REAL, TYPE_TEXT,<br/>TYPE_BLOB, TYPE_ASSET, TYPE_ASSETS, TYPE_FLOAT_VECTOR,<br/>TYPE_UNLIMITED_INT<br/>} | 表示列的类型。 |
| [OH_RDB_TransType](#oh_rdb_transtype-1) { RDB_TRANS_DEFERRED = 0, RDB_TRANS_IMMEDIATE, RDB_TRANS_EXCLUSIVE, RDB_TRANS_BUTT } | 表示关系型数据库事务类型。 |
| [Rdb_Tokenizer](#rdb_tokenizer-1) { RDB_NONE_TOKENIZER = 1, RDB_ICU_TOKENIZER = 2, RDB_CUSTOM_TOKENIZER = 3 } | 描述数据库的分词器类型。 |
| [Rdb_ConflictResolution](#rdb_conflictresolution-1) {<br/>RDB_CONFLICT_NONE = 1, RDB_CONFLICT_ROLLBACK, RDB_CONFLICT_ABORT, RDB_CONFLICT_FAIL,<br/>RDB_CONFLICT_IGNORE, RDB_CONFLICT_REPLACE<br/>} | 表示冲突解决策略的枚举。 | 
| [OH_Rdb_ErrCode](#oh_rdb_errcode-1) {<br/>RDB_ERR = -1, RDB_OK = 0, E_BASE = 14800000, RDB_E_NOT_SUPPORTED = 801,<br/>RDB_E_ERROR = E_BASE, RDB_E_INVALID_ARGS = (E_BASE + 1), RDB_E_CANNOT_UPDATE_READONLY = (E_BASE + 2), RDB_E_REMOVE_FILE = (E_BASE + 3),<br/>RDB_E_EMPTY_TABLE_NAME = (E_BASE + 5), RDB_E_EMPTY_VALUES_BUCKET = (E_BASE + 6), RDB_E_EXECUTE_IN_STEP_QUERY = (E_BASE + 7), RDB_E_INVALID_COLUMN_INDEX = (E_BASE + 8),<br/>RDB_E_INVALID_COLUMN_TYPE = (E_BASE + 9), RDB_E_EMPTY_FILE_NAME = (E_BASE + 10), RDB_E_INVALID_FILE_PATH = (E_BASE + 11), RDB_E_TRANSACTION_IN_EXECUTE = (E_BASE + 12),<br/>RDB_E_INVALID_STATEMENT = (E_BASE + 13), RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION = (E_BASE + 14), RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION = (E_BASE + 15), RDB_E_NO_TRANSACTION_IN_SESSION = (E_BASE + 16),<br/>RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION = (E_BASE + 17), RDB_E_NO_ROW_IN_QUERY = (E_BASE + 18), RDB_E_INVALID_BIND_ARGS_COUNT = (E_BASE + 19), RDB_E_INVALID_OBJECT_TYPE = (E_BASE + 20),<br/>RDB_E_INVALID_CONFLICT_FLAG = (E_BASE + 21), RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY = (E_BASE + 22), RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET = (E_BASE + 23), RDB_E_STEP_RESULT_SET_CROSS_THREADS = (E_BASE + 24),<br/>RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED = (E_BASE + 25), RDB_E_STEP_RESULT_IS_AFTER_LAST = (E_BASE + 26), RDB_E_STEP_RESULT_QUERY_EXCEEDED = (E_BASE + 27), RDB_E_STATEMENT_NOT_PREPARED = (E_BASE + 28),<br/>RDB_E_EXECUTE_RESULT_INCORRECT = (E_BASE + 29), RDB_E_STEP_RESULT_CLOSED = (E_BASE + 30), RDB_E_RELATIVE_PATH = (E_BASE + 31), RDB_E_EMPTY_NEW_ENCRYPT_KEY = (E_BASE + 32),<br/>RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED = (E_BASE + 33), RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY = (E_BASE + 34), RDB_E_STEP_STATEMENT_NOT_INIT = (E_BASE + 35), RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE = (E_BASE + 36),<br/>RDB_E_CREATE_FOLDER_FAIL = (E_BASE + 37), RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL = (E_BASE + 38), RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY = (E_BASE + 39), RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION = (E_BASE + 40),<br/>RDB_E_NOT_SUPPORT = (E_BASE + 41), RDB_E_INVALID_PARCEL = (E_BASE + 42), RDB_E_QUERY_IN_EXECUTE = (E_BASE + 43), RDB_E_SET_PERSIST_WAL = (E_BASE + 44),<br/>RDB_E_DB_NOT_EXIST = (E_BASE + 45), RDB_E_ARGS_READ_CON_OVERLOAD = (E_BASE + 46), RDB_E_WAL_SIZE_OVER_LIMIT = (E_BASE + 47), RDB_E_CON_OVER_LIMIT = (E_BASE + 48),<br/>RDB_E_ALREADY_CLOSED = (E_BASE + 50), RDB_E_DATABASE_BUSY = (E_BASE + 51), RDB_E_SQLITE_CORRUPT = (E_BASE + 52), RDB_E_SQLITE_PERM = (E_BASE + 53),<br/>RDB_E_SQLITE_BUSY = (E_BASE + 54), RDB_E_SQLITE_LOCKED = (E_BASE + 55), RDB_E_SQLITE_NOMEM = (E_BASE + 56), RDB_E_SQLITE_READONLY = (E_BASE + 57),<br/>RDB_E_SQLITE_IOERR = (E_BASE + 58), RDB_E_SQLITE_FULL = (E_BASE + 59), RDB_E_SQLITE_CANT_OPEN = (E_BASE + 60), RDB_E_SQLITE_TOO_BIG = (E_BASE + 61),<br/>RDB_E_SQLITE_MISMATCH = (E_BASE + 62), RDB_E_DATA_TYPE_NULL = (E_BASE + 63), RDB_E_TYPE_MISMATCH = (E_BASE + 64), RDB_E_SQLITE_CONSTRAINT = (E_BASE + 65)<br/>} | 表示错误码信息。 | 


### 函数

| 名称 | 描述 |
| -------- | -------- |
| int [OH_RdbTrans_BatchInsert](#oh_rdbtrans_batchinsert) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*table, const [OH_Data_VBuckets](#oh_data_vbuckets) \*rows, [Rdb_ConflictResolution](#rdb_conflictresolution) resolution, int64_t \*changes) | 将一组数据批量插入到目标表中。 | 
| int [OH_Rdb_BatchInsert](#oh_rdb_batchinsert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, const [OH_Data_VBuckets](#oh_data_vbuckets) \*rows, [Rdb_ConflictResolution](#rdb_conflictresolution) resolution, int64_t \*changes) | 将一批数据插入到目标表中。 | 
| int [OH_Rdb_SetPersistent](#oh_rdb_setpersistent) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, bool isPersistent) | 指定数据库是否需要持久化。 | 
| int [OH_Rdb_IsTokenizerSupported](#oh_rdb_istokenizersupported) ([Rdb_Tokenizer](#rdb_tokenizer) tokenizer, bool \*isSupported) | 判断当前平台是否支持传入的分词器。 |
| int [OH_Rdb_SetTokenizer](#oh_rdb_settokenizer) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, [Rdb_Tokenizer](#rdb_tokenizer) tokenizer) | 给指定的数据库文件配置设置分词器类型。 |
| int [OH_Cursor_GetFloatVectorCount](#oh_cursor_getfloatvectorcount) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, size_t \*length) | 获取当前行中指定列的浮点数数组大小。 |
| int [OH_Cursor_GetFloatVector](#oh_cursor_getfloatvector) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, float \*val, size_t inLen, size_t \*outLen) | 以浮点数数组的形式获取当前行中指定列的值。 |
| int [OH_Rdb_ExecuteV2](#oh_rdb_executev2) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args, [OH_Data_Value](#oh_data_value) \*\*result) | 执行有返回值的SQL语句，支持向量数据库。 |
| [OH_Cursor](_o_h___cursor.md) \* [OH_Rdb_ExecuteQueryV2](#oh_rdb_executequeryv2) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args) | 根据指定SQL语句查询数据库中的数据，支持向量数据库。 |
| [OH_Data_Value](#oh_data_value) \* [OH_Value_Create](#oh_value_create) (void) | 创建[OH_Data_Value](#oh_data_value)实例，用于储存单条键值对数据。 |
| int [OH_Value_Destroy](#oh_value_destroy) ([OH_Data_Value](#oh_data_value) \*value) | 销毁[OH_Data_Value](#oh_data_value)对象。 |
| int [OH_Value_PutNull](#oh_value_putnull) ([OH_Data_Value](#oh_data_value) \*value) | 添加空数据。 |
| int [OH_Value_PutInt](#oh_value_putint) ([OH_Data_Value](#oh_data_value) \*value, int64_t val) | 添加整型数据。 |
| int [OH_Value_PutReal](#oh_value_putreal) ([OH_Data_Value](#oh_data_value) \*value, double val) | 添加REAL类型数据。 |
| int [OH_Value_PutText](#oh_value_puttext) ([OH_Data_Value](#oh_data_value) \*value, const char \*val) | 添加字符串类型数据。 |
| int [OH_Value_PutBlob](#oh_value_putblob) ([OH_Data_Value](#oh_data_value) \*value, const unsigned char \*val, size_t length) | 添加BLOB类型数据。 |
| int [OH_Value_PutAsset](#oh_value_putasset) ([OH_Data_Value](#oh_data_value) \*value, const Data_Asset \*val) | 添加ASSET类型数据。 |
| int [OH_Value_PutAssets](#oh_value_putassets) ([OH_Data_Value](#oh_data_value) \*value, const Data_Asset \*const \*val, size_t length) | 添加ASSETS类型数据。 |
| int [OH_Value_PutFloatVector](#oh_value_putfloatvector) ([OH_Data_Value](#oh_data_value) \*value, const float \*val, size_t length) | 添加float数组类型数据。 |
| int [OH_Value_PutUnlimitedInt](#oh_value_putunlimitedint) ([OH_Data_Value](#oh_data_value) \*value, int sign, const uint64_t \*trueForm, size_t length) | 添加任意长度的整型数组数据。 |
| int [OH_Value_GetType](#oh_value_gettype) ([OH_Data_Value](#oh_data_value) \*value, [OH_ColumnType](#oh_columntype) \*type) | 获取数据类型。 |
| int [OH_Value_IsNull](#oh_value_isnull) ([OH_Data_Value](#oh_data_value) \*value, bool \*val) | 检查数据是否为空。 |
| int [OH_Value_GetInt](#oh_value_getint) ([OH_Data_Value](#oh_data_value) \*value, int64_t \*val) | 获取整型数据。 |
| int [OH_Value_GetReal](#oh_value_getreal) ([OH_Data_Value](#oh_data_value) \*value, double \*val) | 获取REAL类型数据。 |
| int [OH_Value_GetText](#oh_value_gettext) ([OH_Data_Value](#oh_data_value) \*value, const char \*\*val) | 获取字符串类型数据。 |
| int [OH_Value_GetBlob](#oh_value_getblob) ([OH_Data_Value](#oh_data_value) \*value, const uint8_t \*\*val, size_t \*length) | 获取BLOB类型数据。 |
| int [OH_Value_GetAsset](#oh_value_getasset) ([OH_Data_Value](#oh_data_value) \*value, Data_Asset \*val) | 获取ASSET类型数据。 |
| int [OH_Value_GetAssetsCount](#oh_value_getassetscount) ([OH_Data_Value](#oh_data_value) \*value, size_t \*length) | 获取ASSETS类型数据的大小。 |
| int [OH_Value_GetAssets](#oh_value_getassets) ([OH_Data_Value](#oh_data_value) \*value, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | 获取ASSETS类型数据。 |
| int [OH_Value_GetFloatVectorCount](#oh_value_getfloatvectorcount) ([OH_Data_Value](#oh_data_value) \*value, size_t \*length) | 获取float数组类型数据的大小。 |
| int [OH_Value_GetFloatVector](#oh_value_getfloatvector) ([OH_Data_Value](#oh_data_value) \*value, float \*val, size_t inLen, size_t \*outLen) | 获取float数组类型数据。 |
| int [OH_Value_GetUnlimitedIntBand](#oh_value_getunlimitedintband) ([OH_Data_Value](#oh_data_value) \*value, size_t \*length) | 获取任意长度的整型数据的大小。 |
| int [OH_Value_GetUnlimitedInt](#oh_value_getunlimitedint) ([OH_Data_Value](#oh_data_value) \*value, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | 获取任意长度的整型数据。 |
| [OH_Data_Values](#oh_data_values) \* [OH_Values_Create](#oh_values_create) (void) | 创建[OH_Data_Values](#oh_data_values)实例，用于储存多条键值对数据。 |
| int [OH_Values_Destroy](#oh_values_destroy) ([OH_Data_Values](#oh_data_values) \*values) | 销毁[OH_Data_Values](#oh_data_values)对象。 |
| int [OH_Values_Put](#oh_values_put) ([OH_Data_Values](#oh_data_values) \*values, const [OH_Data_Value](#oh_data_value) \*val) | 添加OH_Data_Value类型数据给OH_Data_Values对象。 |
| int [OH_Values_PutNull](#oh_values_putnull) ([OH_Data_Values](#oh_data_values) \*values) | 添加空数据给OH_Data_Values对象。 |
| int [OH_Values_PutInt](#oh_values_putint) ([OH_Data_Values](#oh_data_values) \*values, int64_t val) | 添加整型数据给OH_Data_Values对象。 |
| int [OH_Values_PutReal](#oh_values_putreal) ([OH_Data_Values](#oh_data_values) \*values, double val) | 添加REAL类型数据给OH_Data_Values对象。 |
| int [OH_Values_PutText](#oh_values_puttext) ([OH_Data_Values](#oh_data_values) \*values, const char \*val) | 添加字符串类型数据给OH_Data_Values对象。 |
| int [OH_Values_PutBlob](#oh_values_putblob) ([OH_Data_Values](#oh_data_values) \*values, const unsigned char \*val, size_t length) | 添加BLOB类型数据给OH_Data_Values对象。 |
| int [OH_Values_PutAsset](#oh_values_putasset) ([OH_Data_Values](#oh_data_values) \*values, const Data_Asset \*val) | 添加ASSET类型数据给OH_Data_Values对象。 |
| int [OH_Values_PutAssets](#oh_values_putassets) ([OH_Data_Values](#oh_data_values) \*values, const Data_Asset \*const \*val, size_t length) | 添加ASSETS类型数据给OH_Data_Values对象。 |
| int [OH_Values_PutFloatVector](#oh_values_putfloatvector) ([OH_Data_Values](#oh_data_values) \*values, const float \*val, size_t length) | 添加float数组类型数据给OH_Data_Values对象。 |
| int [OH_Values_PutUnlimitedInt](#oh_values_putunlimitedint) ([OH_Data_Values](#oh_data_values) \*values, int sign, const uint64_t \*trueForm, size_t length) | 添加任意长度的整型数组数据给OH_Data_Values对象。 |
| int [OH_Values_Count](#oh_values_count) ([OH_Data_Values](#oh_data_values) \*values, size_t \*count) | 获取数据个数。 |
| int [OH_Values_GetType](#oh_values_gettype) ([OH_Data_Values](#oh_data_values) \*values, int index, [OH_ColumnType](#oh_columntype) \*type) | 获取数据类型。 |
| int [OH_Values_Get](#oh_values_get) ([OH_Data_Values](#oh_data_values) \*values, int index, [OH_Data_Value](#oh_data_value) \*\*val) | 获取OH_Data_Value类型数据。 |
| int [OH_Values_IsNull](#oh_values_isnull) ([OH_Data_Values](#oh_data_values) \*values, int index, bool \*val) | 检查数据是否为空。 |
| int [OH_Values_GetInt](#oh_values_getint) ([OH_Data_Values](#oh_data_values) \*values, int index, int64_t \*val) | 获取整型数据。 |
| int [OH_Values_GetReal](#oh_values_getreal) ([OH_Data_Values](#oh_data_values) \*values, int index, double \*val) | 获取REAL类型数据。 |
| int [OH_Values_GetText](#oh_values_gettext) ([OH_Data_Values](#oh_data_values) \*values, int index, const char \*\*val) | 获取字符串类型数据。 |
| int [OH_Values_GetBlob](#oh_values_getblob) ([OH_Data_Values](#oh_data_values) \*values, int index, const uint8_t \*\*val, size_t \*length) | 获取BLOB类型数据。 |
| int [OH_Values_GetAsset](#oh_values_getasset) ([OH_Data_Values](#oh_data_values) \*values, int index, Data_Asset \*val) | 获取ASSET类型数据。 |
| int [OH_Values_GetAssetsCount](#oh_values_getassetscount) ([OH_Data_Values](#oh_data_values) \*values, int index, size_t \*length) | 获取ASSETS类型数据的大小。 |
| int [OH_Values_GetAssets](#oh_values_getassets) ([OH_Data_Values](#oh_data_values) \*values, int index, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | 获取ASSETS类型数据。 |
| int [OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount) ([OH_Data_Values](#oh_data_values) \*values, int index, size_t \*length) | 获取float数组类型数据的大小。 |
| int [OH_Values_GetFloatVector](#oh_values_getfloatvector) ([OH_Data_Values](#oh_data_values) \*values, int index, float \*val, size_t inLen, size_t \*outLen) | 获取float数组类型数据。 |
| int [OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband) ([OH_Data_Values](#oh_data_values) \*values, int index, size_t \*length) | 获取任意长度的整型数据的大小。 |
| int [OH_Values_GetUnlimitedInt](#oh_values_getunlimitedint) ([OH_Data_Values](#oh_data_values) \*values, int index, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | 获取任意长度的整型数据。 |
| [OH_Data_VBuckets](#oh_data_vbuckets) \* [OH_VBuckets_Create](#oh_vbuckets_create) (void) | 创建OH_Data_VBuckets实例。 |
| int [OH_VBuckets_Destroy](#oh_vbuckets_destroy) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets) | 销毁OH_Data_VBuckets对象。 |
| int [OH_VBuckets_PutRow](#oh_vbuckets_putrow) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets, const [OH_VBucket](_o_h___v_bucket.md) \*row) | 添加OH_VBucket类型数据。 |
| int [OH_VBuckets_PutRows](#oh_vbuckets_putrows) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets, const [OH_Data_VBuckets](#oh_data_vbuckets) \*rows) | 添加OH_Data_VBuckets类型数据。 |
| int [OH_VBuckets_RowCount](#oh_vbuckets_rowcount) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets, size_t \*count) | 获取OH_Data_VBuckets中OH_VBucket的行数。 |
| [OH_RDB_TransOptions](#oh_rdb_transoptions) \* [OH_RdbTrans_CreateOptions](#oh_rdbtrans_createoptions) (void) | 创建事务配置对象。 |
| int [OH_RdbTrans_DestroyOptions](#oh_rdbtrans_destroyoptions) ([OH_RDB_TransOptions](#oh_rdb_transoptions) \*opitons) | 销毁事务配置对象。 |
| int [OH_RdbTransOption_SetType](#oh_rdbtransoption_settype) ([OH_RDB_TransOptions](#oh_rdb_transoptions) \*opitons, [OH_RDB_TransType](#oh_rdb_transtype) type) | 设置关系型数据库事务类型。 |
| int [OH_RdbTrans_Commit](#oh_rdbtrans_commit) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans) | 提交事务。 |
| int [OH_RdbTrans_Rollback](#oh_rdbtrans_rollback) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans) | 回滚事务。 |
| int [OH_RdbTrans_Insert](#oh_rdbtrans_insert) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*table, const [OH_VBucket](_o_h___v_bucket.md) \*row, int64_t \*rowId) | 将一行数据插入到目标表中。 |
| int [OH_RdbTrans_Update](#oh_rdbtrans_update) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const [OH_VBucket](_o_h___v_bucket.md) \*row, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | 根据指定的条件更新数据库中的数据。 |
| int [OH_RdbTrans_Delete](#oh_rdbtrans_delete) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | 根据指定条件从数据库中删除数据。 |
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_Query](#oh_rdbtrans_query) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*columns[], int len) | 根据指定的条件查询数据库中的数据。 |
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_QuerySql](#oh_rdbtrans_querysql) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args) | 根据SQL语句查询数据库中的数据。 |
| int [OH_RdbTrans_Execute](#oh_rdbtrans_execute) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args, [OH_Data_Value](#oh_data_value) \*\*result) | 执行包含指定参数的SQL语句。 |
| int [OH_RdbTrans_Destroy](#oh_rdbtrans_destroy) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans) | 销毁事务对象。 |
| int [OH_VBucket_PutFloatVector](#oh_vbucket_putfloatvector) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, const float \*vec, size_t len) | 将float数组类型对象放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| int [OH_VBucket_PutUnlimitedInt](#oh_vbucket_putunlimitedint) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, int sign, const uint64_t \*trueForm, size_t len) | 将任意长度的整数类型对象放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_Rdb_ConfigV2](#oh_rdb_configv2) \* [OH_Rdb_CreateConfig](#oh_rdb_createconfig) () | 创建一个[OH_Rdb_ConfigV2](#oh_rdb_configv2)实例，并返回指向该实例的指针。 |
| int [OH_Rdb_DestroyConfig](#oh_rdb_destroyconfig) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config) | 销毁由[OH_Rdb_CreateConfig](#oh_rdb_createconfig)创建的[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象。 |
| int [OH_Rdb_SetDatabaseDir](#oh_rdb_setdatabasedir) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*databaseDir) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库文件路径。 |
| int [OH_Rdb_SetStoreName](#oh_rdb_setstorename) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*storeName) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库名称。 |
| int [OH_Rdb_SetBundleName](#oh_rdb_setbundlename) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*bundleName) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置应用包名。 |
| int [OH_Rdb_SetModuleName](#oh_rdb_setmodulename) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*moduleName) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置应用模块名。 |
| int [OH_Rdb_SetEncrypted](#oh_rdb_setencrypted) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, bool isEncrypted) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库是否加密。 |
| int [OH_Rdb_SetSecurityLevel](#oh_rdb_setsecuritylevel) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int securityLevel) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库安全级别[OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)。 |
| int [OH_Rdb_SetArea](#oh_rdb_setarea) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int area) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库安全区域等级[Rdb_SecurityArea](#rdb_securityarea)。 |
| int [OH_Rdb_SetDbType](#oh_rdb_setdbtype) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int dbType) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库类型[Rdb_DBType](#rdb_dbtype)。 |
| const int \* [OH_Rdb_GetSupportedDbType](#oh_rdb_getsupporteddbtype) (int \*typeCount) | 获得支持的数据库类型[Rdb_DBType](#rdb_dbtype)。 |
| [OH_Rdb_Store](_o_h___rdb___store.md) \* [OH_Rdb_CreateOrOpen](#oh_rdb_createoropen) (const [OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int \*errCode) | 使用指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，获得一个对应的[OH_Rdb_Store](_o_h___rdb___store.md)实例，用来操作关系型数据库。 |
| int [OH_Rdb_DeleteStoreV2](#oh_rdb_deletestorev2) (const [OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config) | 使用指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)删除数据库。当使用向量数据库时，在调用接口前，应当确保向量数据库已经被正确关闭。 |
| int [OH_Rdb_ExecuteByTrxId](#oh_rdb_executebytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId, const char \*sql) | 使用指定的事务ID执行无返回值的SQL语句，仅支持向量数据库。 |
| int [OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t \*trxId) | 在开始执行SQL语句之前，开始事务，并获得该事务的ID，仅支持向量数据库。 |
| int [OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId) | 使用指定的事务ID，回滚已经执行的SQL语句，仅支持向量数据库。 |
| int [OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId) | 使用指定的事务ID，提交已经执行的SQL语句，仅支持向量数据库。 |
| [OH_VBucket_PutAsset](#oh_vbucket_putasset) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*value) | 将**OH_Asset**类型的对象放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket_PutAssets](#oh_vbucket_putassets) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*\*value, int count) | 将**OH_Asset**类型的对象数组放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_Rdb_CreateValueObject](#oh_rdb_createvalueobject) () | 创建[OH_VObject](_o_h___v_object.md)实例。 |
| [OH_Rdb_CreateValuesBucket](#oh_rdb_createvaluesbucket) () | 创建[OH_VBucket](_o_h___v_bucket.md)实例。 |
| [OH_Rdb_CreatePredicates](#oh_rdb_createpredicates) (const char \*table) | 创建[OH_Predicates](_o_h___predicates.md)实例。 |
| [OH_Rdb_GetOrOpen](#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | 获得一个相关的[OH_Rdb_Store](_o_h___rdb___store.md)实例，操作关系型数据库。 |
| [OH_Rdb_CloseStore](#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 销毁[OH_Rdb_Store](_o_h___rdb___store.md)对象，并回收该对象占用的内存。 |
| [OH_Rdb_DeleteStore](#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | 使用指定的数据库文件配置删除数据库。 |
| [OH_Rdb_Insert](#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | 向目标表中插入一行数据。 |
| [OH_Rdb_Update](#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件更新数据库中的数据。 |
| [OH_Rdb_Delete](#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件删除数据库中的数据。 |
| [OH_Rdb_Query](#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | 根据指定条件查询数据库中的数据。 |
| [OH_Rdb_Execute](#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | 执行无返回值的SQL语句。 |
| [OH_Rdb_ExecuteQuery](#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | 根据指定SQL语句查询数据库中的数据，支持向量数据库。 |
| [OH_Rdb_BeginTransaction](#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 在开始执行SQL语句之前，开始事务。 |
| [OH_Rdb_RollBack](#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 回滚已经执行的SQL语句。 |
| [OH_Rdb_Commit](#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 提交已执行的SQL语句。 |
| [OH_Rdb_Backup](#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | 以指定路径备份数据库，支持向量数据库。 |
| [OH_Rdb_Restore](#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | 从指定的数据库备份文件恢复数据库，支持向量数据库。 |
| [OH_Rdb_GetVersion](#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | 获取数据库版本。 |
| [OH_Rdb_SetVersion](#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | 设置数据库版本。 |
| [OH_Rdb_SetDistributedTables](#oh_rdb_setdistributedtables) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tables[], uint32_t count, [Rdb_DistributedType](#rdb_distributedtype) type, const [Rdb_DistributedConfig](_rdb___distributed_config.md) \*config) | 设置分布式数据库表。 |
| [OH_Rdb_FindModifyTime](#oh_rdb_findmodifytime) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tableName, const char \*columnName, [OH_VObject](_o_h___v_object.md) \*values) | 获取数据库表中数据的最后修改时间。 |
| [OH_Rdb_Subscribe](#oh_rdb_subscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | 为数据库注册观察者。当分布式数据库中的数据发生更改时，将调用回调。 |
| [OH_Rdb_Unsubscribe](#oh_rdb_unsubscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | 从数据库中删除指定类型的指定观察者。 |
| [OH_Rdb_GetTableDetails](#oh_rdb_gettabledetails) ([Rdb_ProgressDetails](_rdb___progress_details.md) \*progress, int32_t version) | 从端云同步任务的统计信息中获取数据库表的统计信息。 |
| [OH_Rdb_CloudSync](#oh_rdb_cloudsync) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SyncMode](#rdb_syncmode) mode, const char \*tables, int count, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | 进行端云同步。 |
| [OH_Rdb_SubscribeAutoSyncProgress](#oh_rdb_subscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | 订阅RDB存储的自动同步进度。当收到自动同步进度的通知时，将调用回调。 |
| [OH_Rdb_UnsubscribeAutoSyncProgress](#oh_rdb_unsubscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | 取消订阅RDB存储的自动同步进程。 |
| int [OH_Rdb_LockRow](#oh_rdb_lockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件锁定数据库中的数据，锁定数据不执行端云同步。 |
| int [OH_Rdb_UnlockRow](#oh_rdb_unlockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件锁解锁数据库中的数据。 |
| [OH_Cursor](_o_h___cursor.md) \* [OH_Rdb_QueryLockedRow](#oh_rdb_querylockedrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | 根据指定条件查询数据库中锁定的数据。 |

### 变量

| 名称 | 描述 |
| -------- | -------- |
| [OH_Cursor::id](#id-15) | OH_Cursor结构体的唯一标识符。 |
| [OH_Cursor::getColumnCount](#getcolumncount) | 函数指针，获取结果集中的列数。 |
| [OH_Cursor::getColumnType](#getcolumntype) | 函数指针，根据指定的列索引获取列类型。 |
| [OH_Cursor::getColumnIndex](#getcolumnindex) | 函数指针，根据指定的列名获取列索引。 |
| [OH_Cursor::getColumnName](#getcolumnname) | 函数指针，根据指定的列索引获取列名。 |
| [OH_Cursor::getRowCount](#getrowcount) | 函数指针，获取结果集中的行数。 |
| [OH_Cursor::goToNextRow](#gotonextrow) | 函数指针，转到结果集的下一行。 |
| [OH_Cursor::getSize](#getsize) | 函数指针，当结果集中列的数据类型是BLOB或者TEXT时，获取其值所需的内存。 |
| [OH_Cursor::getText](#gettext) | 函数指针，以字符串形式获取当前行中指定列的值。 |
| [OH_Cursor::getInt64](#getint64) | 函数指针，以int64_t形式获取当前行中指定列的值。 |
| [OH_Cursor::getReal](#getreal) | 函数指针，以double形式获取当前行中指定列的值。 |
| [OH_Cursor::getBlob](#getblob) | 函数指针，以字节数组的形式获取当前行中指定列的值。 |
| [OH_Cursor::isNull](#isnull-12) | 函数指针，检查当前行中指定列的值是否为null。 |
| [OH_Cursor::destroy](#destroy-14) | 函数指针，关闭结果集。 |
| [OH_Cursor::getAsset](#getasset) | 函数指针，以资产的形式获取当前行中指定列的值。 |
| [OH_Cursor::getAssets](#getassets) | 函数指针，以资产数组的形式获取当前行中指定列的值。 |
| [OH_Predicates::id](#id-25) | OH_Predicates结构体的唯一标识符。 |
| [OH_Predicates::equalTo](#equalto) | 函数指针，配置谓词以匹配数据字段等于指定值的字段。 |
| [OH_Predicates::notEqualTo](#notequalto) | 函数指针，配置谓词以匹配数据字段不等于指定值的字段。 |
| [OH_Predicates::beginWrap](#beginwrap) | 函数指针，向谓词添加左括号。 |
| [OH_Predicates::endWrap](#endwrap) | 函数指针，向谓词添加右括号。 |
| [OH_Predicates::orOperate](#oroperate) | 函数指针，将或条件添加到谓词中。 |
| [OH_Predicates::andOperate](#andoperate) | 函数指针，向谓词添加和条件。 |
| [OH_Predicates::isNull](#isnull-22) | 函数指针，配置谓词以匹配值为null的字段。 |
| [OH_Predicates::isNotNull](#isnotnull) | 函数指针，配置谓词以匹配值不为null的指定字段。 |
| [OH_Predicates::like](#like) | 函数指针，配置谓词以匹配数据字段为field且值类似于指定字符串的字段。 |
| [OH_Predicates::between](#between) | 函数指针，将谓词配置为匹配数据字段为field且其值在给定范围内的指定字段。 |
| [OH_Predicates::notBetween](#notbetween) | 函数指针，将谓词配置为匹配数据字段为field且其值超出给定范围内的指定字段。 |
| [OH_Predicates::greaterThan](#greaterthan) | 函数指针，配置谓词以匹配数据字段为field且值大于指定值valueObject的字段。 |
| [OH_Predicates::lessThan](#lessthan) | 函数指针，配置谓词以匹配数据字段为field且值小于指定值valueObject的字段 |
| [OH_Predicates::greaterThanOrEqualTo](#greaterthanorequalto) | 函数指针，配置谓词以匹配数据字段为field且值大于或等于指定值valueObject的字段 |
| [OH_Predicates::lessThanOrEqualTo](#lessthanorequalto) | 函数指针，配置谓词以匹配数据字段为field且值小于或等于指定值valueObject的字段 |
| [OH_Predicates::orderBy](#orderby) | 函数指针，配置谓词以匹配其值按升序或降序排序的列。 |
| [OH_Predicates::distinct](#distinct) | 函数指针，配置谓词以过滤重复记录并仅保留其中一个。 |
| [OH_Predicates::limit](#limit) | 函数指针，设置最大数据记录数的谓词。 |
| [OH_Predicates::offset](#offset) | 函数指针，配置谓词以指定返回结果的起始位置。 |
| [OH_Predicates::groupBy](#groupby) | 函数指针，配置R谓词按指定列分组查询结果。 |
| [OH_Predicates::in](#in) | 函数指针，配置谓词以匹配数据字段为field且值在给定范围内的指定字段。 |
| [OH_Predicates::notIn](#notin) | 函数指针，配置谓词以匹配数据字段为field且值超出给定范围内的指定字段。 |
| [OH_Predicates::clear](#clear-12) | 函数指针，清空谓词。 |
| [OH_Predicates::destroy](#destroy-24) | 销毁[OH_Predicates](_o_h___predicates.md)对象，并回收该对象占用的内存。 |
| [OH_VObject::id](#id-35) | OH_VObject结构体的唯一标识符。 |
| [OH_VObject::putInt64](#putint64-22) | 将int64类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::putDouble](#putdouble) | 将double类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::putText](#puttext-22) | 将char \*类型的字符数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::putTexts](#puttexts) | 将char \*类型的字符串数组转换为[OH_VObject](_o_h___v_object.md)类型的值。 |
| [OH_VObject::destroy](#destroy-44) | 销毁[OH_VObject](_o_h___v_object.md)对象，并回收该对象占用的内存。 |
| [OH_VBucket::id](#id-45) | OH_VBucket结构体的唯一标识符。 |
| [OH_VBucket::capability](#capability) | 表示结构体的存储键值对的数量 |
| [OH_VBucket::putText](#puttext-12) | 将char\*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::putInt64](#putint64-12) | 将int64_t值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::putReal](#putreal) | 将double值放入给定列名的｛**OH_VBucket｝对象中。** |
| [OH_VBucket::putBlob](#putblob) | 将const uint8_t \*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::putNull](#putnull) | 将NULL值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。 |
| [OH_VBucket::clear](#clear-22) | 清空[OH_VBucket](_o_h___v_bucket.md)对象。 |
| [OH_VBucket::destroy](#destroy-34) | 销毁[OH_VBucket](_o_h___v_bucket.md)对象，并回收该对象占用的内存。 |
| [OH_Rdb_Config::selfSize](#selfsize) | 该结构体的大小。 |
| [OH_Rdb_Config::dataBaseDir](#databasedir) | 数据库文件路径。 |
| [OH_Rdb_Config::storeName](#storename) | 数据库名称。 |
| [OH_Rdb_Config::bundleName](#bundlename) | 应用包名。 |
| [OH_Rdb_Config::moduleName](#modulename) | 应用模块名。 |
| [OH_Rdb_Config::isEncrypt](#isencrypt) | 指定数据库是否加密。 |
| [OH_Rdb_Config::securityLevel](#securitylevel) | 设置数据库安全级别[OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)。 |
| [OH_Rdb_Config::area](#area) | 设置数据库安全区域等级[Rdb_SecurityArea](#rdb_securityarea)。 |
| [OH_Rdb_Store::id](#id-55) | OH_Rdb_Store结构体的唯一标识符。 |
| [Rdb_DistributedConfig::version](#version-13) | 用于唯一标识Rdb_DistributedConfig结构的版本。 |
| [Rdb_DistributedConfig::isAutoSync](#isautosync) | 表示该表是否支持自动同步。 |
| [Rdb_KeyInfo::count](#count) | 表示发生变化的主键或者行号的数量。 |
| [Rdb_KeyInfo::type](#type) | 表示主键的类型[OH_ColumnType](#oh_columntype)。 |
| [Rdb_KeyInfo::Rdb_KeyData::integer](#integer) | 存放uint64_t类型的数据。 |
| [Rdb_KeyInfo::Rdb_KeyData::real](#real) | 存放double类型的数据。 |
| [Rdb_KeyInfo::Rdb_KeyData::text](#text) | 存放char \*类型的数据。 |
| [Rdb_KeyInfo::data](_rdb___key_info.md#成员变量) | 存放变化的具体数据。 |
| [Rdb_ChangeInfo::version](#version-23) | 用于唯一标识Rdb_DistributedConfig结构的版本。 |
| [Rdb_ChangeInfo::tableName](#tablename) | 表示发生变化的表的名称。 |
| [Rdb_ChangeInfo::ChangeType](#changetype) | 表示发生变化的数据的类型，数据或者资产附件发生变化。 |
| [Rdb_ChangeInfo::inserted](#inserted) | 记录插入数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示插入数据的行号。 |
| [Rdb_ChangeInfo::updated](#updated) | 记录更新数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示更新数据的行号。 |
| [Rdb_ChangeInfo::deleted](#deleted) | 记录删除数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示删除数据的行号。 |
| [Rdb_SubscribeCallback::detailsObserver](#detailsobserver) | 端云数据更改事件的细节的回调函数。 |
| [Rdb_SubscribeCallback::briefObserver](#briefobserver) | 端云数据更改事件的回调函数。 |
| [Rdb_DataObserver::context](#context-12) | 表示数据观察者的上下文。 |
| [Rdb_DataObserver::callback](#callback-12) | 数据观察者的回调。 |
| [Rdb_Statistic::total](#total) | 表示数据库表中需要端云同步的总行数。 |
| [Rdb_Statistic::successful](#successful) | 表示数据库表中端云同步成功的行数。 |
| [Rdb_Statistic::failed](#failed) | 表示数据库表中端云同步失败的行数。 |
| [Rdb_Statistic::remained](#remained) | 表示数据库表中端云同步剩余未执行的行数。 |
| [Rdb_TableDetails::table](#table) | 数据库表名。 |
| [Rdb_TableDetails::upload](#upload) | 表示数据库表中端云同步上传过程的统计信息。 |
| [Rdb_TableDetails::download](#download) | 表示数据库表中端云同步下载过程的统计信息。 |
| [Rdb_ProgressDetails::version](#version-33) | 用于唯一标识OH_TableDetails结构的版本。 |
| [Rdb_ProgressDetails::schedule](#schedule) | 表示端云同步过程。 |
| [Rdb_ProgressDetails::code](#code) | 表示端云同步过程的状态。 |
| [Rdb_ProgressDetails::tableLength](#tablelength) | 表示端云同步的表的数量 |
| [Rdb_ProgressObserver::context](#context-22) | 端云同步进度观察者的上下文。 |
| [Rdb_ProgressObserver::callback](#callback-22) | 端云同步进度观察者的回调函数。 |


## 宏定义说明


### DISTRIBUTED_CHANGE_INFO_VERSION

```
#define DISTRIBUTED_CHANGE_INFO_VERSION   1
```

**描述**

描述[Rdb_ChangeInfo](_rdb___change_info.md)的版本。

**起始版本：** 11


### DISTRIBUTED_CONFIG_VERSION

```
#define DISTRIBUTED_CONFIG_VERSION   1
```

**描述**

描述[Rdb_DistributedConfig](_rdb___distributed_config.md)的版本。

**起始版本：** 11


### DISTRIBUTED_PROGRESS_DETAIL_VERSION

```
#define DISTRIBUTED_PROGRESS_DETAIL_VERSION   1
```

**描述**

描述**OH_ProgressDetails**的版本。

**起始版本：** 11


## 类型定义说明

### Rdb_ConflictResolution

```
typedef enum Rdb_ConflictResolution Rdb_ConflictResolution
```

**描述**

表示冲突解决策略的枚举。

**起始版本：** 18

### OH_ColumnType

```
typedef enum OH_ColumnType OH_ColumnType
```

**描述**

表示列的类型。

**起始版本：** 10

### OH_Data_Value

```
typedef struct OH_Data_Value OH_Data_Value
```

**描述**

定义[OH_Data_Value](#oh_data_value)结构类型。

**起始版本：** 18


### OH_Data_Values

```
typedef struct OH_Data_Values OH_Data_Values
```

**描述**

定义[OH_Data_Values](#oh_data_values)结构类型。

**起始版本：** 18


### OH_Data_VBuckets

```
typedef struct OH_Data_VBuckets OH_Data_VBuckets
```

**描述**

定义OH_Data_VBuckets结构类型。

**起始版本：** 18

### OH_Rdb_Transaction

```
typedef struct OH_Rdb_Transaction OH_Rdb_Transaction
```

**描述**

定义[OH_Rdb_Transaction](#oh_rdb_transaction)结构类型。

**起始版本：** 18


### OH_RDB_TransOptions

```
typedef struct OH_RDB_TransOptions OH_RDB_TransOptions
```

**描述**

定义[OH_RDB_TransOptions](#oh_rdb_transoptions)结构类型。

**起始版本：** 18


### OH_RDB_TransType

```
typedef enum OH_RDB_TransType OH_RDB_TransType
```

**描述**

表示关系型数据库事务类型。

**起始版本：** 18

### Rdb_Tokenizer

```
typedef enum Rdb_Tokenizer Rdb_Tokenizer
```

**描述**

描述数据库的分词器类型。

**起始版本：** 18

### OH_Rdb_ConfigV2

```
typedef struct OH_Rdb_ConfigV2 OH_Rdb_ConfigV2
```

**描述**

管理关系数据库配置，与[OH_Rdb_Config](_o_h___rdb___config.md)的区别是该结构体成员变量不对外暴露，使用一系列方法配置该结构体的属性。

**起始版本：** 14


### Rdb_DBType

```
typedef enum Rdb_DBType Rdb_DBType
```

**描述**

描述数据库的内核类型。

**起始版本：** 14

### OH_Cursor

```
typedef struct OH_Cursor OH_Cursor
```

**描述**

表示结果集。

提供通过查询数据库生成的数据库结果集的访问方法。

**起始版本：** 10


### OH_OrderType

```
typedef enum OH_OrderType OH_OrderType
```

**描述**

排序方式。

**起始版本：** 10


### OH_Predicates

```
typedef struct OH_Predicates OH_Predicates
```

**描述**

表示谓词。

**起始版本：** 10


### OH_Rdb_ErrCode

```
typedef enum OH_Rdb_ErrCode OH_Rdb_ErrCode
```

**描述**

表示错误码信息。

**起始版本：** 10


### OH_Rdb_SecurityLevel

```
typedef enum OH_Rdb_SecurityLevel OH_Rdb_SecurityLevel
```

**描述**

数据库的安全级别枚举。

**起始版本：** 10


### OH_VBucket

```
typedef struct OH_VBucket OH_VBucket
```

**描述**

用于存储键值对的类型。

**起始版本：** 10


### OH_VObject

```
typedef struct OH_VObject OH_VObject
```

**描述**

表示允许的数据字段类型。

**起始版本：** 10


### Rdb_BriefObserver

```
typedef void(* Rdb_BriefObserver) (void *context, const char *values[], uint32_t count)
```

**描述**

端云数据更改事件的回调函数。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| context | 表示数据观察者的上下文。 |
| values | 表示更改的端云账号。 |
| count | 表示更改的端云账号数量。 |


### Rdb_ChangeInfo

```
typedef struct Rdb_ChangeInfo Rdb_ChangeInfo
```

**描述**

记录端云同步过程详情。

**起始版本：** 11


### Rdb_ChangeType

```
typedef enum Rdb_ChangeType Rdb_ChangeType
```

**描述**

描述数据变更类型。

**起始版本：** 11


### Rdb_DataObserver

```
typedef struct Rdb_DataObserver Rdb_DataObserver
```

**描述**

表示数据观察者。

**起始版本：** 11


### Rdb_DetailsObserver

```
typedef void(* Rdb_DetailsObserver) (void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)
```

**描述**

端云数据更改事件的细节的回调函数。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| context | 表示数据观察者的上下文。 |
| changeInfo | 表示已更改表的信息[Rdb_ChangeInfo](_rdb___change_info.md)。 |
| count | 表示更改的表的数量。 |

**参见：**

[Rdb_ChangeInfo](_rdb___change_info.md).


### Rdb_DistributedConfig

```
typedef struct Rdb_DistributedConfig Rdb_DistributedConfig
```

**描述**

记录表的分布式配置信息。

**起始版本：** 11


### Rdb_DistributedType

```
typedef enum Rdb_DistributedType Rdb_DistributedType
```

**描述**

描述表的分布式类型的枚举。

**起始版本：** 11


### Rdb_KeyInfo

```
typedef struct Rdb_KeyInfo Rdb_KeyInfo
```

**描述**

描述发生变化的行的主键或者行号。

**起始版本：** 11


### Rdb_Progress

```
typedef enum Rdb_Progress Rdb_Progress
```

**描述**

描述端云同步过程。

**起始版本：** 11


### Rdb_ProgressCallback

```
typedef void(* Rdb_ProgressCallback) (void *context, Rdb_ProgressDetails *progressDetails)
```

**描述**

端云同步进度的回调函数。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| progressDetails | 端云同步进度的详细信息。 |

**参见：**

[Rdb_ProgressDetails](_rdb___progress_details.md).


### Rdb_ProgressCode

```
typedef enum Rdb_ProgressCode Rdb_ProgressCode
```

**描述**

表示端云同步过程的状态。

**起始版本：** 11


### Rdb_ProgressDetails

```
typedef struct Rdb_ProgressDetails Rdb_ProgressDetails
```

**描述**

描述数据库整体执行端云同步任务上传和下载的统计信息。

**起始版本：** 11


### Rdb_ProgressObserver

```
typedef struct Rdb_ProgressObserver Rdb_ProgressObserver
```

**描述**

端云同步进度观察者。

**起始版本：** 11


### Rdb_SecurityArea

```
typedef enum Rdb_SecurityArea Rdb_SecurityArea
```

**描述**

描述数据库的安全区域等级。

**起始版本：** 11


### Rdb_Statistic

```
typedef struct Rdb_Statistic Rdb_Statistic
```

**描述**

描述数据库表的端云同步过程的统计信息。

**起始版本：** 11


### Rdb_SubscribeCallback

```
typedef union Rdb_SubscribeCallback Rdb_SubscribeCallback
```

**描述**

表示回调函数。

**起始版本：** 11


### Rdb_SubscribeType

```
typedef enum Rdb_SubscribeType Rdb_SubscribeType
```

**描述**

描述订阅类型。

**起始版本：** 11


### Rdb_SyncCallback

```
typedef void(* Rdb_SyncCallback) (Rdb_ProgressDetails *progressDetails)
```

**描述**

数据库端云同步的回调函数。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| progressDetails | 数据库端云同步的统计信息。 |

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### Rdb_SyncMode

```
typedef enum Rdb_SyncMode Rdb_SyncMode
```

**描述**

表示数据库的同步模式。

**起始版本：** 11


### Rdb_TableDetails

```
typedef struct Rdb_TableDetails Rdb_TableDetails
```

**描述**

描述数据库表执行端云同步任务上传和下载的统计信息。

**起始版本：** 11

## 枚举类型说明

### Rdb_ConflictResolution

```
enum Rdb_ConflictResolution
```

**描述**

表示冲突解决策略的枚举。

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| RDB_CONFLICT_NONE | 发生冲突时不执行任何操作。 | 
| RDB_CONFLICT_ROLLBACK | 发生冲突时抛错误码，同时回滚本次事务。 | 
| RDB_CONFLICT_ABORT | 发生冲突时抛错误码，同时回滚本次修改。 | 
| RDB_CONFLICT_FAIL | 发生冲突时抛错误码，不回滚冲突前的修改同时终止本次修改。 | 
| RDB_CONFLICT_IGNORE | 发生冲突时忽略冲突的数据，继续执行后续修改。 | 
| RDB_CONFLICT_REPLACE | 发生冲突时，尝试删除后插入，如果还是冲突则等同于RDB_CONFLICT_ABORT。 | 

### OH_Rdb_ErrCode

```
enum OH_Rdb_ErrCode
```

**描述**

表示错误码信息。

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| RDB_ERR | 执行出错。 | 
| RDB_OK | 执行成功。 | 
| E_BASE | 异常错误代码的基础。 | 
| RDB_E_NOT_SUPPORTED | RDB不具备该能力。 | 
| RDB_E_ERROR | 常见异常的错误代码。 | 
| RDB_E_INVALID_ARGS | 参数非法。 | 
| RDB_E_CANNOT_UPDATE_READONLY | 更新只读数据库。 | 
| RDB_E_REMOVE_FILE | 删除文件失败。 | 
| RDB_E_EMPTY_TABLE_NAME | 表名为空。 | 
| RDB_E_EMPTY_VALUES_BUCKET | 键值对内容为空。 | 
| RDB_E_EXECUTE_IN_STEP_QUERY | 查询时执行的SQL语句错误。 | 
| RDB_E_INVALID_COLUMN_INDEX | 列索引非法。 | 
| RDB_E_INVALID_COLUMN_TYPE | 列类型非法。 | 
| RDB_E_EMPTY_FILE_NAME | 文件名称为空。 | 
| RDB_E_INVALID_FILE_PATH | 文件路径非法。 | 
| RDB_E_TRANSACTION_IN_EXECUTE | 开启事务执行出错。 | 
| RDB_E_INVALID_STATEMENT | SQL语句预编译出错。 | 
| RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION | 在读连接中执行写操作。 | 
| RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION | 在读连接中开启事务。 | 
| RDB_E_NO_TRANSACTION_IN_SESSION | 在数据库会话中不存在开启的事务。 | 
| RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION | 在一个数据库会话中执行多次查询。 | 
| RDB_E_NO_ROW_IN_QUERY | 查询得到的结果集不存在任何记录。 | 
| RDB_E_INVALID_BIND_ARGS_COUNT | SQL语句中绑定的参数个数非法。 | 
| RDB_E_INVALID_OBJECT_TYPE | 对象类型非法。 | 
| RDB_E_INVALID_CONFLICT_FLAG | 冲突解决类型非法。 | 
| RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY | HAVING关键字只能用于GROUP BY之后。 | 
| RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET | 不支持step形式数据库结果集。 | 
| RDB_E_STEP_RESULT_SET_CROSS_THREADS | 结果集查询出错。 | 
| RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED | 结果集查询语句未被执行。 | 
| RDB_E_STEP_RESULT_IS_AFTER_LAST | 结果集的游标已经处于最后一行。 | 
| RDB_E_STEP_RESULT_QUERY_EXCEEDED | 结果集查询次数已经超过上限。 | 
| RDB_E_STATEMENT_NOT_PREPARED | SQL语句未被预编译。 | 
| RDB_E_EXECUTE_RESULT_INCORRECT | 数据库执行结果异常。 | 
| RDB_E_STEP_RESULT_CLOSED | 结果集已经关闭。 | 
| RDB_E_RELATIVE_PATH | 相对路径。 | 
| RDB_E_EMPTY_NEW_ENCRYPT_KEY | 新的密钥文件为空。 | 
| RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED | 将非加密的数据库更改为加密数据库。 | 
| RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY | 在数据库繁忙时更新数据库密钥。 | 
| RDB_E_STEP_STATEMENT_NOT_INIT | 预编译的SQL语句未被初始化。 | 
| RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE | 在WAL日志模式下不支持ATTACH操作。 | 
| RDB_E_CREATE_FOLDER_FAIL | 创建文件夹失败。 | 
| RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL | SQL语句构建失败。 | 
| RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY | 数据库会话暂未提供连接。 | 
| RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION | 数据库会话不具有当前的事务。 | 
| RDB_E_NOT_SUPPORT | 不支持当前操作。 | 
| RDB_E_INVALID_PARCEL | 当前PARCEL非法。 | 
| RDB_E_QUERY_IN_EXECUTE | 执行query查询出错。 | 
| RDB_E_SET_PERSIST_WAL | 设置WAL模式下数据库文件的持久化时出错。 | 
| RDB_E_DB_NOT_EXIST | 数据库不存在。 | 
| RDB_E_ARGS_READ_CON_OVERLOAD | 设置的读连接数大于上限。 | 
| RDB_E_WAL_SIZE_OVER_LIMIT | WAL日志文件大小超过默认值。 | 
| RDB_E_CON_OVER_LIMIT | 数据库连接数已用完。 | 
| RDB_E_ALREADY_CLOSED<sup>18+</sup> | 数据库已关闭。 | 
| RDB_E_DATABASE_BUSY<sup>18+</sup> | 数据库无响应。 | 
| RDB_E_SQLITE_CORRUPT<sup>18+</sup> | 数据库损坏。 | 
| RDB_E_SQLITE_PERM<sup>18+</sup> | SQLite错误码：访问权限被拒绝。 | 
| RDB_E_SQLITE_BUSY<sup>18+</sup> | SQLite错误码：数据库文件被锁定。 | 
| RDB_E_SQLITE_LOCKED<sup>18+</sup> | SQLite错误码：数据库中的表被锁定。 | 
| RDB_E_SQLITE_NOMEM<sup>18+</sup> | SQLite错误码：数据库内存不足。| 
| RDB_E_SQLITE_READONLY<sup>18+</sup> | SQLite错误码：尝试写入只读数据库。 | 
| RDB_E_SQLITE_IOERR<sup>18+</sup> | SQLite错误码：磁盘I/O错误。 | 
| RDB_E_SQLITE_FULL<sup>18+</sup> | SQLite错误码：数据库已满。 | 
| RDB_E_SQLITE_CANT_OPEN<sup>18+</sup> | SQLite错误码：无法打开数据库文件。 | 
| RDB_E_SQLITE_TOO_BIG<sup>18+</sup> | SQLite错误码：TEXT或BLOB超出大小限制。 | 
| RDB_E_SQLITE_MISMATCH<sup>18+</sup> | SQLite错误码：数据类型不匹配。 | 
| RDB_E_DATA_TYPE_NULL<sup>18+</sup> | 表示存储数据为空。 | 
| RDB_E_TYPE_MISMATCH<sup>18+</sup> | 表示数据类型不匹配。 | 
| RDB_E_SQLITE_CONSTRAINT<sup>18+</sup> | 表示SQLite错误码：SQLite约束。 | 

### OH_ColumnType

```
enum OH_ColumnType
```

**描述**

表示列的类型。

**起始版本：** 10

| 枚举值 | 描述 |
| -------- | -------- |
| TYPE_NULL | 表示NULL类型。 |
| TYPE_INT64 | 表示INT64数据类型。 |
| TYPE_REAL | 表示REAL数据类型。 |
| TYPE_TEXT | 表示TEXT数据类型。 |
| TYPE_BLOB | 表示BLOB数据类型。 |
| TYPE_ASSET<sup>11+</sup> | 表示ASSET（资产附件）数据类型。 |
| TYPE_ASSETS<sup>11+</sup> | 表示ASSETS（多个资产附件）数据类型。 |
| TYPE_FLOAT_VECTOR<sup>18+</sup> | 表示FLOAT VECTOR数据类型。 |
| TYPE_UNLIMITED_INT<sup>18+</sup> | 表示列类型为长度大于64位的数字。 |

### OH_RDB_TransType

```
enum OH_RDB_TransType
```

**描述**

表示关系型数据库事务类型。

**起始版本：** 18

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_TRANS_DEFERRED | 在首次访问数据库之前，事务默认设置不会启动。 |
| RDB_TRANS_IMMEDIATE | 数据库连接立即开始新的写入，而无需等待写入语句。 |
| RDB_TRANS_EXCLUSIVE | 与RDB_TRANS_IMMEDIATE类型相似，写事务会立即启动。RDB_TRANS_EXCLUSIVE和RDB_TRANS_IMMEDIATE类型在WAL模式下相同，但在其他日志模式下，RDB_TRANS_EXCLUSIVE会阻止其他数据库连接在事务进行时读取数据库。 |
| RDB_TRANS_BUTT | RDB事务类型的最大值。 |

### Rdb_Tokenizer

```
enum Rdb_Tokenizer
```

**描述**

描述数据库的分词器类型。

**起始版本：** 18

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_NONE_TOKENIZER | 表示不使用分词器。 |
| RDB_ICU_TOKENIZER | 表示使用原生ICU分词器。 |
| RDB_CUSTOM_TOKENIZER | 表示使用CUSTOM分词器。 |

### Rdb_DBType

```
enum Rdb_DBType
```

**描述**

描述数据库的内核类型。

**起始版本：** 14

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_SQLITE | 表示使用sqlite作为数据库内核。 |
| RDB_CAYLEY | 表示使用凯莱数据库作为数据库内核。 |
| DBTYPE_BUTT | 表示内核类型枚举值允许取值的最大值，这是一个非法值。 |

### OH_Rdb_SecurityLevel

```
enum OH_Rdb_SecurityLevel
```

**描述**

数据库的安全级别枚举。

**起始版本：** 10

| 枚举值 | 描述 |
| -------- | -------- |
| S1 | S1: 表示数据库的安全级别为低级别。<br/>当数据泄露时会产生较低影响。 |
| S2 | S2: 表示数据库的安全级别为中级别。<br/>当数据泄露时会产生较大影响。 |
| S3 | S3: 表示数据库的安全级别为高级别。<br/>当数据泄露时会产生重大影响。 |
| S4 | S4: 表示数据库的安全级别为关键级别。<br/>当数据泄露时会产生严重影响。 |


### Rdb_ChangeType

```
enum Rdb_ChangeType
```

**描述**

描述数据变更类型。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_DATA_CHANGE | 表示是数据发生变更。 |
| RDB_ASSET_CHANGE | 表示是资产附件发生了变更。 |


### Rdb_DistributedType

```
enum Rdb_DistributedType
```

**描述**

描述表的分布式类型的枚举。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_DISTRIBUTED_CLOUD | 表示在设备和云端之间分布式的数据库表。 |


### Rdb_Progress

```
enum Rdb_Progress
```

**描述**

描述端云同步过程。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_SYNC_BEGIN | 表示端云同步过程开始。 |
| RDB_SYNC_IN_PROGRESS | 表示正在端云同步过程中。 |
| RDB_SYNC_FINISH | 表示端云同步过程已完成。 |


### Rdb_ProgressCode

```
enum Rdb_ProgressCode
```

**描述**

表示端云同步过程的状态。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_SUCCESS | 表示端云同步过程成功。 |
| RDB_UNKNOWN_ERROR | 表示端云同步过程遇到未知错误。 |
| RDB_NETWORK_ERROR | 表示端云同步过程遇到网络错误。 |
| RDB_CLOUD_DISABLED | 表示云端不可用。 |
| RDB_LOCKED_BY_OTHERS | 表示有其他设备正在端云同步，本设备无法进行端云同步。 |
| RDB_RECORD_LIMIT_EXCEEDED | 表示本次端云同步需要同步的条目或大小超出最大值。由云端配置最大值。 |
| RDB_NO_SPACE_FOR_ASSET | 表示云空间剩余空间小于待同步的资产大小。 |


### Rdb_SecurityArea

```
enum Rdb_SecurityArea
```

**描述**

描述数据库的安全区域等级。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_SECURITY_AREA_EL1 | 安全区域等级为1。 |
| RDB_SECURITY_AREA_EL2 | 安全区域等级为2。 |
| RDB_SECURITY_AREA_EL3 | 安全区域等级为3。 |
| RDB_SECURITY_AREA_EL4 | 安全区域等级为4。 |


### Rdb_SubscribeType

```
enum Rdb_SubscribeType
```

**描述**

描述订阅类型。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_SUBSCRIBE_TYPE_CLOUD | 订阅云端数据更改。 |
| RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS | 订阅云端数据更改详情。 |
| RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS<sup>12+</sup>  | 订阅本地数据更改详情。从API version 12开始支持此枚举。 |


### Rdb_SyncMode

```
enum Rdb_SyncMode
```

**描述**

表示数据库的同步模式。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RDB_SYNC_MODE_TIME_FIRST | 表示数据从修改时间较近的一端同步到修改时间较远的一端。 |
| RDB_SYNC_MODE_NATIVE_FIRST | 表示数据从本地设备同步到云端。 |
| RDB_SYNC_MODE_CLOUD_FIRST | 表示数据从云端同步到本地设备。 |


## 函数说明

### OH_RdbTrans_BatchInsert()

```
int OH_RdbTrans_BatchInsert (OH_Rdb_Transaction *trans, const char *table, const OH_Data_VBuckets *rows, Rdb_ConflictResolution resolution, int64_t *changes)
```

**描述**

将一组数据批量插入到目标表中。

**起始版本：** 18

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 | 
| table | 表示目标表。 | 
| rows | 表示要插入到表中的一组数据。 | 
| resolution | 表示发生冲突时的解决策略。 | 
| changes | 输出参数，表示插入成功的次数。 | 

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

返回RDB_E_SQLITE_CONSTRAINT表示SQLite错误码：SQLite约束。


### OH_Rdb_BatchInsert()

```
int OH_Rdb_BatchInsert (OH_Rdb_Store *store, const char *table, const OH_Data_VBuckets *rows, Rdb_ConflictResolution resolution, int64_t *changes )
```

**描述**

将一批数据插入到目标表中。

**起始版本：** 18

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 | 
| tables | 要设置的分布式数据库表表名。 | 
| rows | 表示要插入到表中的一组数据。 | 
| resolution | 表示发生冲突时的解决策略。 | 
| changes | 输出参数，表示插入成功的次数。 | 

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

返回RDB_E_SQLITE_CONSTRAINT表示SQLite错误码：SQLite约束。


### OH_Rdb_SetPersistent()

```
int OH_Rdb_SetPersistent (OH_Rdb_ConfigV2 *config, bool isPersistent )
```

**描述**

指定数据库是否需要持久化。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| config | 表示指向OH_Rdb_ConfigV2实例的指针。指示与此RDB存储相关的数据库的配置。|
| isPersistent | 指示数据库是否需要持久性。 |

**返回：**

返回执行的状态代码。RDB_OK表示成功。RDB_E_INVALID_ARGS表示无效参数。| 

### OH_Cursor_GetFloatVector()

```
int OH_Cursor_GetFloatVector (OH_Cursor *cursor, int32_t columnIndex, float *val, size_t inLen, size_t *outLen )
```

**描述**

以浮点数数组的形式获取当前行中指定列的值。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| val | 该参数是输出参数，结果集中指定列的值会以浮点数数组形式写入该变量，调用者需要申请数组内存。 |
| inLen | 表示申请的浮点数数组大小。 |
| outLen | 该参数是输出参数，表示实际浮点数数组的大小。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_STEP_RESULT_CLOSED表示查询到的结果集已经关闭。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_SQLITE_PERM表示SQLite错误：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误：数据库内存不足。

返回RDB_E_SQLITE_IOERR表示SQLite错误：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

**参见：**

[OH_Cursor_GetFloatVectorCount](#oh_cursor_getfloatvectorcount).


### OH_Cursor_GetFloatVectorCount()

```
int OH_Cursor_GetFloatVectorCount (OH_Cursor *cursor, int32_t columnIndex, size_t *length )
```

**描述**

获取当前行中指定列的浮点数数组大小。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| length | 该参数是输出参数，结果集中指定列的浮点数数组大小会写入该变量。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_STEP_RESULT_CLOSED表示查询到的结果集已经关闭。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_SQLITE_PERM表示SQLite错误：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误：数据库内存不足。

返回RDB_E_SQLITE_IOERR表示SQLite错误：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

### OH_Rdb_CreateTransaction()

```
int OH_Rdb_CreateTransaction (OH_Rdb_Store *store, const OH_RDB_TransOptions *options, OH_Rdb_Transaction **trans )
```

**描述**

创建一个事务对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| options | 表示指向[OH_RDB_TransOptions](#oh_rdb_transoptions)实例的指针。 |
| trans | 输出参数，表示执行成功时指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。否则返回 nullptr。使用完成后，必须通过[OH_RdbTrans_Destroy](#oh_rdbtrans_destroy)接口释放内存。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已关闭。

返回RDB_E_DATABASE_BUSY表示数据库无响应。

返回RDB_E_SQLITE_FULL表示SQLite错误：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库已损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误：数据库文件被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误：数据库内存不足。

返回RDB_E_SQLITE_IOERR表示SQLite错误：磁盘I/O错误。

返回RDB_E_SQLITE_CANT_OPEN表示SQLite错误：无法打开数据库文件。

**参见：**

[OH_RdbTrans_Destroy](#oh_rdbtrans_destroy).


### OH_Rdb_ExecuteQueryV2()

```
OH_Cursor *OH_Rdb_ExecuteQueryV2 (OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args )
```

**描述**

根据指定SQL语句查询数据库中的数据，支持向量数据库。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| sql | 指定要执行的SQL语句。 |
| args | 可选参数，表示指向OH_Data_Values实例的指针。 |

**返回：**

如果查询成功则返回一个指向[OH_Cursor](_o_h___cursor.md)结构体实例的指针，使用完成后及时释放[OH_Cursor](_o_h___cursor.md)。如果SQL语句无效或内存分配失败，则返回NULL。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_ExecuteV2()

```
int OH_Rdb_ExecuteV2 (OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args, OH_Data_Value **result )
```

**描述**

执行有返回值的SQL语句，支持向量数据库。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| sql | 指定要执行的SQL语句。 |
| args | 可选参数，表示指向{\@OH_Data_Values}实例的指针。 |
| result | 执行成功时指向[OH_Data_Value](#oh_data_value)实例的指针，作为出参使用。<br/>使用完成后，必须通过[OH_Value_Destroy](#oh_value_destroy)接口释放内存。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

**参见：**

[OH_Value_Destroy](#oh_value_destroy).


### OH_Rdb_IsTokenizerSupported()

```
int OH_Rdb_IsTokenizerSupported (Rdb_Tokenizer tokenizer, bool *isSupported )
```

**描述**

判断当前平台是否支持传入的分词器。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| tokenizer | 要校验是否支持的分词器。 |
| isSupported | 校验结果的指针，作为出参使用。<br/>true表示当前平台支持当前校验的分词器，false表示当前平台不支持当前校验的分词器。 |

**返回：**

返回接口操作执行的状态码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_SetTokenizer()

```
int OH_Rdb_SetTokenizer (OH_Rdb_ConfigV2 *config, Rdb_Tokenizer tokenizer )
```

**描述**

给指定的数据库文件配置设置分词器类型。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向此RDB存储相关的数据库配置的指针。 |
| tokenizer | 表示数据库的分词器类型。 |

**返回：**

返回接口操作执行的状态码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

RDB_E_NOT_SUPPORTED 表示不支持当前操作。

### OH_RdbTrans_Commit()

```
int OH_RdbTrans_Commit (OH_Rdb_Transaction *trans)
```

**描述**

提交事务。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

### OH_RdbTrans_Delete()

```
int OH_RdbTrans_Delete (OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes )
```

**描述**

根据指定条件从数据库中删除数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |
| predicates | 表示[OH_Predicates](_o_h___predicates.md)指定的删除条件。 |
| changes | 表示删除成功的次数。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

### OH_RdbTrans_CreateOptions()

```
OH_RDB_TransOptions* OH_RdbTrans_CreateOptions (void )
```

**描述**

创建事务配置对象。

**起始版本：** 18

**返回：**

执行成功时返回指向[OH_RDB_TransOptions](#oh_rdb_transoptions)实例的指针。否则返回nullptr。使用完成后，必须通过[OH_RdbTrans_DestroyOptions](#oh_rdbtrans_destroyoptions)接口释放内存。

**参见：**

[OH_RdbTrans_DestroyOptions](#oh_rdbtrans_destroyoptions).

### OH_RdbTrans_Destroy()

```
int OH_RdbTrans_Destroy (OH_Rdb_Transaction *trans)
```

**描述**

销毁事务对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_RdbTrans_DestroyOptions()

```
int OH_RdbTrans_DestroyOptions (OH_RDB_TransOptions *opitons)
```

**描述**

销毁事务配置对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| opitons | 表示指向[OH_RDB_TransOptions](#oh_rdb_transoptions)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_RdbTrans_Execute()

```
int OH_RdbTrans_Execute (OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result )
```

**描述**

执行包含指定参数的SQL语句。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |
| sql | 表示要执行的SQL语句。 |
| args | SQL语句中包含的参数。 |
| result | 执行成功时指向[OH_Data_Value](#oh_data_value)实例的指针。使用完成后，必须通过[OH_Value_Destroy](#oh_value_destroy)接口释放内存。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

**参见：**

[OH_Value_Destroy](#oh_value_destroy).


### OH_RdbTrans_Insert()

```
int OH_RdbTrans_Insert (OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId )
```

**描述**

将一行数据插入到目标表中。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |
| table | 表示目标表。 |
| row | 表示要插入到表中的数据行。 |
| rowId | 输出参数，表示插入后返回的行号。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

### OH_RdbTrans_Query()

```
OH_Cursor* OH_RdbTrans_Query (OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[], int len )
```

**描述**

根据指定的条件查询数据库中的数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |
| predicates | 表示[OH_Predicates](_o_h___predicates.md)指定的查询条件。 |
| columns | 表示要查询的列，如果传入空值，则查询适用于所有列。 |
| len | 表示列中元素的个数。 |

**返回：**

如果执行成功，则返回指向[OH_Cursor](_o_h___cursor.md)实例的指针。如果数据库已关闭或数据库没有响应，则返回空。


### OH_RdbTrans_QuerySql()

```
OH_Cursor* OH_RdbTrans_QuerySql (OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args )
```

**描述**

根据SQL语句查询数据库中的数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |
| sql | 表示要执行的SQL语句。 |
| args | 表示指向[OH_Data_Values](#oh_data_values)的指针。 |

**返回：**

如果执行成功，则返回指向[OH_Cursor](_o_h___cursor.md)实例的指针。如果数据库已关闭或数据库没有响应，则返回空。


### OH_RdbTrans_Rollback()

```
int OH_RdbTrans_Rollback (OH_Rdb_Transaction *trans)
```

**描述**

回滚事务。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。


### OH_RdbTrans_Update()

```
int OH_RdbTrans_Update (OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates, int64_t *changes )
```

**描述**

根据指定的条件更新数据库中的数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| trans | 表示指向[OH_Rdb_Transaction](#oh_rdb_transaction)实例的指针。 |
| row | 表示要更新到表中的数据行。 |
| predicates | 表示[OH_Predicates](_o_h___predicates.md)指定的更新条件。 |
| changes | 输出参数，表示更新成功的次数。 |

**返回：**

返回执行结果。

返回RDB_OK表示成功。

返回RDB_E_ERROR表示数据库常见错误。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。

返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。

返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。

返回RDB_E_SQLITE_CORRUPT表示数据库损坏。

返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。

返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。

返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。

返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。

返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。

返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。

返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。

返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。

### OH_RdbTransOption_SetType()

```
int OH_RdbTransOption_SetType (OH_RDB_TransOptions *opitons, OH_RDB_TransType type )
```

**描述**

设置关系型数据库事务类型。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| opitons | 表示指向[OH_RDB_TransOptions](#oh_rdb_transoptions)实例的指针。 |
| type | 表示关系型数据库事务类型。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_Create()

```
OH_Data_Value* OH_Value_Create (void )
```

**描述**

创建[OH_Data_Value](#oh_data_value)实例，用于储存单条键值对数据。

**起始版本：** 18

**返回：**

执行成功时返回指向[OH_Data_Value](#oh_data_value)实例的指针，否则返回nullptr。使用完成后，必须通过[OH_Value_Destroy](#oh_value_destroy)接口释放内存。

**参见：**

[OH_Value_Destroy](#oh_value_destroy).


### OH_Value_Destroy()

```
int OH_Value_Destroy (OH_Data_Value *value)
```

**描述**

销毁[OH_Data_Value](#oh_data_value)对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_GetAsset()

```
int OH_Value_GetAsset (OH_Data_Value *value, Data_Asset *val )
```

**描述**

获取ASSET类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示指向**Data_Asset**对象的指针。需要申请数据内存。此函数仅填充数据。否则执行失败。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

### OH_Value_GetAssets()

```
int OH_Value_GetAssets (OH_Data_Value *value, Data_Asset **val, size_t inLen, size_t *outLen )
```

**描述**

获取ASSETS类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示指向**Data_Asset**对象的指针。需要申请数据内存。此函数仅填充数据。否则执行失败。 |
| inLen | 表示val的大小。可以通过[OH_Values_GetAssetsCount](#oh_values_getassetscount)获取。 |
| outLen | 该参数为输出参数，表示实际获取的数据大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

**参见：**

[OH_Value_GetAssetsCount](#oh_value_getassetscount).


### OH_Value_GetAssetsCount()

```
int OH_Value_GetAssetsCount (OH_Data_Value *value, size_t *length )
```

**描述**

获取ASSETS类型数据的大小。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| length | 该参数是输出参数，表示ASSETS类型数据的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Value_GetBlob()

```
int OH_Value_GetBlob (OH_Data_Value *value, const uint8_t **val, size_t *length )
```

**描述**

获取BLOB类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 该参数是输出参数，表示指向BLOB类型数据的指针。无需申请内存和释放内存。val的生命周期遵循value中index的值。 |
| length | 该参数是输出参数，表示BLOB类型数组的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Value_GetFloatVector()

```
int OH_Value_GetFloatVector (OH_Data_Value *value, float *val, size_t inLen, size_t *outLen )
```

**描述**

获取float数组类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示指向float数组的指针。需要申请数据内存。此函数仅填充数据。否则执行失败。 |
| inLen | 表示val的大小。可以通过[OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount)获取。 |
| outLen | 该参数为输出参数，表示实际获取的数据大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

**参见：**

[OH_Value_GetFloatVectorCount](#oh_value_getfloatvectorcount).


### OH_Value_GetFloatVectorCount()

```
int OH_Value_GetFloatVectorCount (OH_Data_Value *value, size_t *length )
```

**描述**

获取float数组类型数据的大小。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| length | 该参数是输出参数，表示float数组类型数据的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS返回。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Value_GetInt()

```
int OH_Value_GetInt (OH_Data_Value *value, int64_t *val )
```

**描述**

获取整型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 该参数为输出参数，表示指向整型数据的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Value_GetReal()

```
int OH_Value_GetReal (OH_Data_Value *value, double *val )
```

**描述**

获取REAL类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 该参数为输出参数，表示指向REAL类型数据的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Value_GetText()

```
int OH_Value_GetText (OH_Data_Value *value, const char **val )
```

**描述**

获取字符串类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 该参数为输出参数，表示指向字符串类型数据的指针。无需申请内存和释放内存。val的生命周期遵循value中index的值。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

### OH_Value_GetType()

```
int OH_Value_GetType (OH_Data_Value *value, OH_ColumnType *type )
```

**描述**

获取数据类型。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| type | 该参数为输出参数，表示数据类型。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_GetUnlimitedInt()

```
int OH_Value_GetUnlimitedInt (OH_Data_Value *value, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen )
```

**描述**

获取任意长度的整型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| sign | 该参数为输出参数，表示正负数，0表示正整数，1表示负整数。 |
| trueForm | 表示指向整型数组的指针。需要申请数据内存。此函数仅填充数据。否则执行失败。 |
| inLen | 表示trueForm的大小。可以通过[OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband)获取。 |
| outLen | 该参数为输出参数，表示实际获取的数据大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

**参见：**

[OH_Value_GetUnlimitedIntBand](#oh_value_getunlimitedintband).


### OH_Value_GetUnlimitedIntBand()

```
int OH_Value_GetUnlimitedIntBand (OH_Data_Value *value, size_t *length )
```

**描述**

获取任意长度的整型数据的大小。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| length | 该参数是输出参数，表示整型数组的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

### OH_Value_IsNull()

```
int OH_Value_IsNull (OH_Data_Value *value, bool *val )
```

**描述**

检查数据是否为空。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 该参数为输出参数，ture表示空，false表示不为空。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutAsset()

```
int OH_Value_PutAsset (OH_Data_Value *value, const Data_Asset *val )
```

**描述**

添加ASSET类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示指向**Data_Asset**对象的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutAssets()

```
int OH_Value_PutAssets (OH_Data_Value *value, const Data_Asset * const * val, size_t length )
```

**描述**

添加ASSETS类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示指向**Data_Asset**对象的指针。 |
| length | 该参数是输入参数，表示开发者传入的**Data_Asset**对象数组元素的个数。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutBlob()

```
int OH_Value_PutBlob (OH_Data_Value *value, const unsigned char *val, size_t length )
```

**描述**

添加BLOB类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示BLOB类型数据。 |
| length | 该参数是输入参数，表示开发者传入的BLOB类型数据的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutFloatVector()

```
int OH_Value_PutFloatVector (OH_Data_Value *value, const float *val, size_t length )
```

**描述**

添加float数组类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示指向float数组对象的指针。 |
| length | 该参数是输入参数，表示开发者传入的表示float数组的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

### OH_Value_PutInt()

```
int OH_Value_PutInt (OH_Data_Value *value, int64_t val )
```

**描述**

添加整型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示整型数据。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutNull()

```
int OH_Value_PutNull (OH_Data_Value *value)
```

**描述**

添加空数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutReal()

```
int OH_Value_PutReal (OH_Data_Value *value, double val )
```

**描述**

添加REAL类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示REAL类型数据。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutText()

```
int OH_Value_PutText (OH_Data_Value *value, const char *val )
```

**描述**

添加字符串类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| val | 表示字符串类型数据。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Value_PutUnlimitedInt()

```
int OH_Value_PutUnlimitedInt (OH_Data_Value *value, int sign, const uint64_t *trueForm, size_t length )
```

**描述**

添加任意长度的整型数组数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| value | 表示指向[OH_Data_Value](#oh_data_value)实例的指针。 |
| sign | 表示正负数，0表示正整数，1表示负整数。 |
| trueForm | 表示指向整型数组的指针。 |
| length | 该参数是输入参数，表示开发者传入的表示整型数组的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

### OH_Values_Count()

```
int OH_Values_Count (OH_Data_Values *values, size_t *count )
```

**描述**

获取数据个数。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| count | 该参数为输出参数，表示values中数据的个数。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_Create()

```
OH_Data_Values* OH_Values_Create (void )
```

**描述**

创建[OH_Data_Values](#oh_data_values)实例，用于储存多条键值对数据。

**起始版本：** 18

**返回：**

执行成功时返回指向[OH_Data_Values](#oh_data_values)实例的指针，否则返回nullptr。使用完成后，必须通过[OH_Values_Destroy](#oh_values_destroy)接口释放内存。

**参见：**

[OH_Values_Destroy](#oh_values_destroy).


### OH_Values_Destroy()

```
int OH_Values_Destroy (OH_Data_Values *values)
```

**描述**

销毁[OH_Data_Values](#oh_data_values)对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_Get()

```
int OH_Values_Get (OH_Data_Values *values, int index, OH_Data_Value **val )
```

**描述**

获取OH_Data_Value类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 该参数为输出参数，表示指向[OH_Data_Value](#oh_data_value)实例的指针。无需申请内存和释放内存。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

### OH_Values_GetAsset()

```
int OH_Values_GetAsset (OH_Data_Values *values, int index, Data_Asset *val )
```

**描述**

获取ASSET类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 表示指向**Data_Asset**对象的指针。需要申请数据内存。此函数仅填充数据。否则执行失败。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Values_GetAssets()

```
int OH_Values_GetAssets (OH_Data_Values *values, int index, Data_Asset **val, size_t inLen, size_t *outLen )
```

**描述**

获取ASSETS类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 表示指向**Data_Asset**对象的指针。使用时需要申请数据内存。此函数仅填充数据。否则执行失败。 |
| inLen | 表示val的大小。可以通过[OH_Values_GetAssetsCount](#oh_values_getassetscount)获取。 |
| outLen | 该参数为输出参数，表示实际获取的数据大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

**参见：**

[OH_Values_GetAssetsCount](#oh_values_getassetscount).


### OH_Values_GetAssetsCount()

```
int OH_Values_GetAssetsCount (OH_Data_Values *values, int index, size_t *length )
```

**描述**

获取ASSETS类型数据的大小。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| length | 该参数为输出参数，表示ASSETS类型数据的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Values_GetBlob()

```
int OH_Values_GetBlob (OH_Data_Values *values, int index, const uint8_t **val, size_t *length )
```

**描述**

获取BLOB类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 该参数为输出参数，表示指向BLOB类型数据的指针。无需申请内存和释放内存。val的生命周期遵循values中index的值。 |
| length | 该参数为输出参数，表示BLOB类型数组的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

### OH_Values_GetFloatVector()

```
int OH_Values_GetFloatVector (OH_Data_Values *values, int index, float *val, size_t inLen, size_t *outLen )
```

**描述**

获取float数组类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 表示指向float数组的指针。需要申请数据内存。此函数仅填充数据。否则执行失败。 |
| inLen | 表示val的大小。可以通过[OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount)获取。 |
| outLen | 该参数为输出参数，表示实际获取的数据大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

**参见：**

[OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount).


### OH_Values_GetFloatVectorCount()

```
int OH_Values_GetFloatVectorCount (OH_Data_Values *values, int index, size_t *length )
```

**描述**

获取float数组类型数据的大小。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| length | 该参数为输出参数，表示float数组类型数据的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Values_GetInt()

```
int OH_Values_GetInt (OH_Data_Values *values, int index, int64_t *val )
```

**描述**

获取整型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 该参数为输出参数，表示指向整型数据的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

### OH_Values_GetReal()

```
int OH_Values_GetReal (OH_Data_Values *values, int index, double *val )
```

**描述**

获取REAL类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 该参数为输出参数，表示指向REAL类型数据的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Values_GetText()

```
int OH_Values_GetText (OH_Data_Values *values, int index, const char **val )
```

**描述**

获取字符串类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 该参数为输出参数，表示指向字符串类型数据的指针。无需申请内存和释放内存。val的生命周期遵循values中index的值。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Values_GetType()

```
int OH_Values_GetType (OH_Data_Values *values, int index, OH_ColumnType *type )
```

**描述**

获取数据类型。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| type | 该参数为输出参数，表示数据类型。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_GetUnlimitedInt()

```
int OH_Values_GetUnlimitedInt (OH_Data_Values *values, int index, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen )
```

**描述**

获取任意长度的整型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| sign | 该参数为输出参数，表示正负数，0表示正整数，1表示负整数。 |
| trueForm | 表示指向整型数组的指针。需要申请数据内存。此函数仅填充数据。否则执行失败。 |
| inLen | 表示trueForm的大小。可以通过[OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband)获取。 |
| outLen | 该参数为输出参数，表示实际获取的数据大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。

**参见：**

[OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband).


### OH_Values_GetUnlimitedIntBand()

```
int OH_Values_GetUnlimitedIntBand (OH_Data_Values *values, int index, size_t *length )
```

**描述**

获取任意长度的整型数据的大小。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| length | 该参数为输出参数，表示整型数组的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

返回RDB_E_DATA_TYPE_NULL表示存储数据为空。

返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。


### OH_Values_IsNull()

```
int OH_Values_IsNull (OH_Data_Values *values, int index, bool *val )
```

**描述**

检查数据是否为空。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| index | 表示values中目标数据的从零开始的索引。 |
| val | 该参数为输出参数，ture表示空，false表示不为空。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

### OH_Values_Put()

```
int OH_Values_Put (OH_Data_Values *values, const OH_Data_Value *val )
```

**描述**

添加OH_Data_Value类型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示指向[OH_Data_Value](#oh_data_value)对象的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutAsset()

```
int OH_Values_PutAsset (OH_Data_Values *values, const Data_Asset *val )
```

**描述**

添加ASSET类型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示指向**Data_Asset**对象的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutAssets()

```
int OH_Values_PutAssets (OH_Data_Values *values, const Data_Asset * const * val, size_t length )
```

**描述**

添加ASSETS类型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示指向**Data_Asset**对象的指针。 |
| length | 该参数为输入参数，表示开发者传入的**Data_Asset**对象数组元素的个数。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutBlob()

```
int OH_Values_PutBlob (OH_Data_Values *values, const unsigned char *val, size_t length )
```

**描述**

添加BLOB类型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示BLOB类型数据。 |
| length | 该参数为输入参数，表示开发者传入的BLOB类型数据的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutFloatVector()

```
int OH_Values_PutFloatVector (OH_Data_Values *values, const float *val, size_t length )
```

**描述**

添加float数组类型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示指向float数组对象的指针。 |
| length | 该参数为输入参数，表示开发者传入的float数组的长度。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutInt()

```
int OH_Values_PutInt (OH_Data_Values *values, int64_t val )
```

**描述**

添加整型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示整型数据。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutNull()

```
int OH_Values_PutNull (OH_Data_Values *values)
```

**描述**

添加空数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutReal()

```
int OH_Values_PutReal (OH_Data_Values *values, double val )
```

**描述**

添加REAL类型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示REAL类型数据。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutText()

```
int OH_Values_PutText (OH_Data_Values *values, const char *val )
```

**描述**

添加字符串类型数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| val | 表示字符串类型数据。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_Values_PutUnlimitedInt()

```
int OH_Values_PutUnlimitedInt (OH_Data_Values *values, int sign, const uint64_t *trueForm, size_t length )
```

**描述**

添加任意长度的整型数组数据给OH_Data_Values对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| values | 表示指向[OH_Data_Values](#oh_data_values)实例的指针。 |
| sign | 表示正负数，0表示正整数，1表示负整数。 |
| trueForm | 表示指向整型数组的指针。 |
| length | 该参数为输入参数，表示开发者传入的整型数组的大小。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

### OH_VBucket_PutFloatVector()

```
int OH_VBucket_PutFloatVector (OH_VBucket *bucket, const char *field, const float *vec, size_t len )
```

**描述**

将float数组类型对象放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| vec | 表示指向float数组的指针。 |
| len | 表示float数组的大小。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### OH_VBucket_PutUnlimitedInt()

```
int OH_VBucket_PutUnlimitedInt (OH_VBucket *bucket, const char *field, int sign, const uint64_t *trueForm, size_t len )
```

**描述**

将任意长度的整数类型对象放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| sign | 表示整数类型对象是正数还是负数，0表示正数，1表示负数。 |
| trueForm | 表示指向整数类型数组的指针。 |
| len | 表示整数数组的大小。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### OH_VBuckets_Create()

```
OH_Data_VBuckets* OH_VBuckets_Create (void)
```

**描述**

创建OH_Data_VBuckets实例。

**起始版本：** 18

**返回：**

执行成功时返回指向[OH_Data_VBuckets](#oh_data_vbuckets)实例的指针，否则返回nullptr。使用完成后，必须通过[OH_VBuckets_Destroy](#oh_vbuckets_destroy)接口释放内存。

**参见：**

[OH_VBuckets_Destroy](#oh_vbuckets_destroy).


### OH_VBuckets_Destroy()

```
int OH_VBuckets_Destroy (OH_Data_VBuckets *buckets)
```

**描述**

销毁OH_Data_VBuckets对象。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| buckets | 表示指向[OH_Data_VBuckets](#oh_data_vbuckets)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_VBuckets_PutRow()

```
int OH_VBuckets_PutRow (OH_Data_VBuckets *buckets, const OH_VBucket *row )
```

**描述**

添加OH_VBucket类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| buckets | 表示指向[OH_Data_VBuckets](#oh_data_vbuckets)实例的指针。 |
| row | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_VBuckets_PutRows()

```
int OH_VBuckets_PutRows (OH_Data_VBuckets *buckets, const OH_Data_VBuckets *rows )
```

**描述**

添加OH_Data_VBuckets类型数据。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| buckets | 表示指向[OH_Data_VBuckets](#oh_data_vbuckets)实例的指针。 |
| rows | 表示指向[OH_Data_VBuckets](#oh_data_vbuckets)实例的指针。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。


### OH_VBuckets_RowCount()

```
int OH_VBuckets_RowCount (OH_Data_VBuckets *buckets, size_t *count )
```

**描述**

获取OH_Data_VBuckets中OH_VBucket的行数。

**起始版本：** 18

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| buckets | 表示指向[OH_Data_VBuckets](#oh_data_vbuckets)实例的指针。 |
| count | 该参数为输出参数，表示[OH_Data_VBuckets](#oh_data_vbuckets)中[OH_VBucket](_o_h___v_bucket.md)的个数。 |

**返回：**

返回错误码。

返回RDB_OK表示成功。

返回RDB_E_INVALID_ARGS表示无效参数。

### OH_Rdb_CreateOrOpen()

```
OH_Rdb_Store *OH_Rdb_CreateOrOpen (const OH_Rdb_ConfigV2 *config, int *errCode )
```

**描述**

使用指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，获得一个对应的[OH_Rdb_Store](_o_h___rdb___store.md)实例，用来操作关系型数据库。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| errCode | 表示函数执行状态，作为出参使用。RDB_OK表示成功。RDB_E_INVALID_ARGS表示无效参数。 |

**返回：**

创建成功则返回一个指向[OH_Rdb_Store](_o_h___rdb___store.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_Rdb_ConfigV2](#oh_rdb_configv2), [OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_BeginTransWithTrxId()

```
int OH_Rdb_BeginTransWithTrxId (OH_Rdb_Store *store, int64_t *trxId )
```

**描述**

在开始执行SQL语句之前，开始事务，并获得该事务的ID，仅支持向量数据库。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示一个指向 [OH_Rdb_Store](_o_h___rdb___store.md) 实例的指针。 |
| trxId | 事务ID，作为出参使用。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

RDB_E_NOT_SUPPORTED 表示不支持当前操作。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CommitByTrxId()

```
int OH_Rdb_CommitByTrxId (OH_Rdb_Store *store, int64_t trxId )
```

**描述**

使用指定的事务ID，提交已经执行的SQL语句，仅支持向量数据库。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示一个指向 [OH_Rdb_Store](_o_h___rdb___store.md) 实例的指针。 |
| trxId | 表示需要提交的事务的ID。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。RDB_E_INVALID_ARGS 表示无效参数，可能情况如下：传入参数为空指针。当前事务ID不是调用[OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid)获得的。当前事务ID已经调用[OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid)提交。当前事务ID已经调用[OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid)回滚。

RDB_E_NOT_SUPPORTED 表示不支持当前操作。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CreateConfig()

```
OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig ()
```

**描述**

创建一个[OH_Rdb_ConfigV2](#oh_rdb_configv2)实例，并返回指向该实例的指针。

**起始版本：** 14

**返回：**

返回一个指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)实例的指针。

**参见：**

[OH_Rdb_ConfigV2](#oh_rdb_configv2)



### OH_Rdb_DeleteStoreV2()

```
int OH_Rdb_DeleteStoreV2 (const OH_Rdb_ConfigV2 *config)
```

**描述**

使用指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)删除数据库。当使用向量数据库时，在调用接口前，应当确保向量数据库已经被正确关闭。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示数据库的配置。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

OH_Rdb_ErrCode.


### OH_Rdb_DestroyConfig()

```
int OH_Rdb_DestroyConfig (OH_Rdb_ConfigV2 *config)
```

**描述**

销毁由[OH_Rdb_CreateConfig](#oh_rdb_createconfig)创建的[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_ExecuteByTrxId()

```
int OH_Rdb_ExecuteByTrxId (OH_Rdb_Store *store, int64_t trxId, const char *sql )
```

**描述**

使用指定的事务ID执行无返回值的SQL语句，仅支持向量数据库。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示一个指向 [OH_Rdb_Store](_o_h___rdb___store.md) 实例的指针。 |
| trxId | 调用[OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid)获得的事务ID，当设置为0时，表示不启用事务。 |
| sql | 指定要执行的SQL语句。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数，可能情况如下：传入参数为空指针。当前事务ID不是调用[OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid)获得的。当前事务ID已经调用[OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid)提交。当前事务ID已经调用[OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid)回滚。当store或者sql为NULL时。

RDB_E_NOT_SUPPORTED 表示不支持当前操作。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetSupportedDbType()

```
const int *OH_Rdb_GetSupportedDbType (int *typeCount)
```

**描述**

获得支持的数据库类型[Rdb_DBType](#rdb_dbtype)。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| typeCount | 表示支持的数据库类型的数组的长度，作为出参使用。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_RollBackByTrxId()

```
int OH_Rdb_RollBackByTrxId (OH_Rdb_Store *store, int64_t trxId )
```

**描述**

使用指定的事务ID，回滚已经执行的SQL语句，仅支持向量数据库。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示一个指向 [OH_Rdb_Store](_o_h___rdb___store.md) 实例的指针。 |
| trxId | 表示需要回滚的事务的ID。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数，可能情况如下：传入参数为空指针。当前事务ID不是调用[OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid)获得的。当前事务ID已经调用[OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid)提交。当前事务ID已经调用[OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid)回滚。

RDB_E_NOT_SUPPORTED 表示不支持当前操作。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetArea()

```
int OH_Rdb_SetArea (OH_Rdb_ConfigV2 *config, int area )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库安全区域等级[Rdb_SecurityArea](#rdb_securityarea)。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| area | 表示数据库安全区域等级[Rdb_SecurityArea](#rdb_securityarea)。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_SetBundleName()

```
int OH_Rdb_SetBundleName (OH_Rdb_ConfigV2 *config, const char *bundleName )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置应用包名。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| bundleName | 表示数据库应用包名。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_SetDatabaseDir()

```
int OH_Rdb_SetDatabaseDir (OH_Rdb_ConfigV2 *config, const char *databaseDir )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库文件路径。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| dataBaseDir | 表示数据库文件路径。包含数据库名称在内的全路径长度不超过1024个字符。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_SetDbType()

```
int OH_Rdb_SetDbType (OH_Rdb_ConfigV2 *config, int dbType )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库类型[Rdb_DBType](#rdb_dbtype)。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| dbType | 表示数据库的数据库类型 [Rdb_DBType](#rdb_dbtype)。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

RDB_E_NOT_SUPPORTED 表示不支持当前操作。


### OH_Rdb_SetEncrypted()

```
int OH_Rdb_SetEncrypted (OH_Rdb_ConfigV2 *config, bool isEncrypted )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库是否加密。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| isEncrypted | 表示数据库是否加密，true表示加密，false表示不加密。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_SetModuleName()

```
int OH_Rdb_SetModuleName (OH_Rdb_ConfigV2 *config, const char *moduleName )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置应用模块名。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| moduleName | 表示数据库应用模块名。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_SetSecurityLevel()

```
int OH_Rdb_SetSecurityLevel (OH_Rdb_ConfigV2 *config, int securityLevel )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库安全级别[OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| securityLevel | 表示数据库安全级别 [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。


### OH_Rdb_SetStoreName()

```
int OH_Rdb_SetStoreName (OH_Rdb_ConfigV2 *config, const char *storeName )
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](#oh_rdb_configv2)，设置数据库名称。

**起始版本：** 14

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_ConfigV2](#oh_rdb_configv2)对象的指针，即与此RDB存储相关的数据库配置。 |
| storeName | 表示数据库名称。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

### OH_Rdb_Backup()

```
int OH_Rdb_Backup (OH_Rdb_Store *store, const char *databasePath )
```

**描述**

以指定路径备份数据库，支持向量数据库。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| databasePath | 指定数据库的备份文件路径。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_BeginTransaction()

```
int OH_Rdb_BeginTransaction (OH_Rdb_Store *store)
```

**描述**

在开始执行SQL语句之前，开始事务。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CloseStore()

```
int OH_Rdb_CloseStore (OH_Rdb_Store *store)
```

**描述**

销毁[OH_Rdb_Store](_o_h___rdb___store.md)对象，并回收该对象占用的内存。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CloudSync()

```
int OH_Rdb_CloudSync (OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables, int count, const Rdb_ProgressObserver *observer )
```

**描述**

进行端云同步。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| mode | 表示同步过程的类型[Rdb_SyncMode](#rdb_syncmode). |
| tables | 表示需要同步的表名。 |
| count | 同步的表的数量，如果传入的值为0，同步数据库的所有表。 |
| observer | 端云同步进度的观察者[Rdb_ProgressObserver](_rdb___progress_observer.md)。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Commit()

```
int OH_Rdb_Commit (OH_Rdb_Store *store)
```

**描述**

提交已执行的SQL语句。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CreatePredicates()

```
OH_Predicates* OH_Rdb_CreatePredicates (const char *table)
```

**描述**

创建[OH_Predicates](_o_h___predicates.md)实例。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| table | 表示数据库表名。 |

**返回：**

创建成功则返回一个指向[OH_Predicates](_o_h___predicates.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### OH_Rdb_CreateValueObject()

```
OH_VObject* OH_Rdb_CreateValueObject ()
```

**描述**

创建[OH_VObject](_o_h___v_object.md)实例。

**起始版本：** 10

**返回：**

创建成功则返回一个指向[OH_VObject](_o_h___v_object.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_VObject](_o_h___v_object.md).


### OH_Rdb_CreateValuesBucket()

```
OH_VBucket* OH_Rdb_CreateValuesBucket ()
```

**描述**

创建[OH_VBucket](_o_h___v_bucket.md)实例。

**起始版本：** 10

**返回：**

创建成功则返回一个指向[OH_VBucket](_o_h___v_bucket.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### OH_Rdb_Delete()

```
int OH_Rdb_Delete (OH_Rdb_Store *store, OH_Predicates *predicates )
```

**描述**

根据指定的条件删除数据库中的数据。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定删除条件。 |

**返回：**

如果删除成功，返回删除的行数；如果失败，则返回的结果小于0。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).


### OH_Rdb_DeleteStore()

```
int OH_Rdb_DeleteStore (const OH_Rdb_Config *config)
```

**描述**

使用指定的数据库文件配置删除数据库。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示数据库的配置。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。


### OH_Rdb_Execute()

```
int OH_Rdb_Execute (OH_Rdb_Store *store, const char *sql )
```

**描述**

执行无返回值的SQL语句。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| sql | 指定要执行的SQL语句。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_ExecuteQuery()

```
OH_Cursor* OH_Rdb_ExecuteQuery (OH_Rdb_Store *store, const char *sql )
```

**描述**

根据指定SQL语句查询数据库中的数据，支持向量数据库 。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| sql | 指定要执行的SQL语句。 |

**返回：**

如果查询成功则返回一个指向[OH_Cursor](_o_h___cursor.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_FindModifyTime()

```
OH_Cursor* OH_Rdb_FindModifyTime (OH_Rdb_Store *store, const char *tableName, const char *columnName, OH_VObject *values )
```

**描述**

获取数据库表中数据的最后修改时间。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| tableName | 要查找的分布式数据库表表名。 |
| columnName | 指定要查询的数据库表的列名。 |
| values | 指定要查询的行的主键。如果数据库表无主键，参数columnName需传入"rowid"，此时values为要查询的数据库表的行号。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetOrOpen()

```
OH_Rdb_Store* OH_Rdb_GetOrOpen (const OH_Rdb_Config *config, int *errCode )
```

**描述**

获得一个相关的[OH_Rdb_Store](_o_h___rdb___store.md)实例，操作关系型数据库。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| config | 表示指向[OH_Rdb_Config](_o_h___rdb___config.md)实例的指针，与此RDB存储相关的数据库配置。 |
| errCode | 该参数是输出参数，函数执行状态写入该变量。 |

**返回：**

创建成功则返回一个指向[OH_Rdb_Store](_o_h___rdb___store.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_Rdb_Config](_o_h___rdb___config.md), [OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetTableDetails()

```
Rdb_TableDetails* OH_Rdb_GetTableDetails (Rdb_ProgressDetails *progress, int32_t version )
```

**描述**

从端云同步任务的统计信息中获取数据库表的统计信息。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| progress | 表示指向**OH_ProgressDetails**实例的指针。 |
| version | 表示当前[Rdb_ProgressDetails](_rdb___progress_details.md)的版本。 |

**返回：**

如果操作成功，会返回一个[Rdb_TableDetails](_rdb___table_details.md)结构体的指针，否则返回NULL。

**参见：**

[Rdb_ProgressDetails](_rdb___progress_details.md)

[Rdb_TableDetails](_rdb___table_details.md)


### OH_Rdb_GetVersion()

```
int OH_Rdb_GetVersion (OH_Rdb_Store *store, int *version )
```

**描述**

获取数据库版本。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| version |  该参数是输出参数，表示版本号。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Insert()

```
int OH_Rdb_Insert (OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket )
```

**描述**

向目标表中插入一行数据。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| table | 表示指定的目标表名。 |
| valuesBucket | 表示要插入到表中的数据行[OH_VBucket](_o_h___v_bucket.md)。 |

**返回：**

如果插入成功，返回rowID，否则返回的结果小于0。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_VBucket](_o_h___v_bucket.md).

### OH_Rdb_LockRow()

```
int OH_Rdb_LockRow (OH_Rdb_Store *store, OH_Predicates *predicates )
```

**描述**

根据指定的条件锁定数据库中的数据，锁定数据不执行端云同步。

**起始版本：** 12

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定锁定条件。 |

**返回：**

返回锁定结果。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).

### OH_Rdb_Query()

```
OH_Cursor* OH_Rdb_Query (OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length )
```

**描述**

根据指定条件查询数据库中的数据。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定查询条件。 |
| columnNames | 表示要查询的列。如果值为空，则查询应用于所有列。 |
| length | 该参数为输入参数，表示开发者传入的columnNames数组的长度。若length大于columnNames数组的实际长度，则会访问越界。 |

**返回：**

如果查询成功则返回一个指向[OH_Cursor](_o_h___cursor.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md), [OH_Cursor](_o_h___cursor.md).

### OH_Rdb_QueryLockedRow()

```
OH_Cursor *OH_Rdb_QueryLockedRow (OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length )
```

**描述**

根据指定条件查询数据库中锁定的数据。

**起始版本：** 12

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定查询条件。 |
| columnNames | 表示要查询的列。如果值为空，则查询应用于所有列。 |
| length | 该参数为输入参数，表示开发者传入的columnNames数组的长度。若length大于columnNames数组的实际长度，则会访问越界。 |

**返回：**

如果查询成功则返回一个指向[OH_Cursor](_o_h___cursor.md)结构体实例的指针，否则返回NULL。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md), [OH_Cursor](_o_h___cursor.md).

### OH_Rdb_Restore()

```
int OH_Rdb_Restore (OH_Rdb_Store *store, const char *databasePath )
```

**描述**

从指定的数据库备份文件恢复数据库，支持向量数据库。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| databasePath | 指定数据库的备份文件路径。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_RollBack()

```
int OH_Rdb_RollBack (OH_Rdb_Store *store)
```

**描述**

回滚已经执行的SQL语句。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetDistributedTables()

```
int OH_Rdb_SetDistributedTables (OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type, const Rdb_DistributedConfig * config )
```

**描述**

设置分布式数据库表。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| tables | 要设置的分布式数据库表表名。 |
| count | 要设置的分布式数据库表的数量。 |
| type | 表的分布式类型 [Rdb_DistributedType](#rdb_distributedtype)。 |
| config | 表的分布式配置信息。[Rdb_DistributedConfig](_rdb___distributed_config.md)。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetVersion()

```
int OH_Rdb_SetVersion (OH_Rdb_Store *store, int version )
```

**描述**

设置数据库版本。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| version | 表示版本号。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Subscribe()

```
int OH_Rdb_Subscribe (OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer )
```

**描述**

为数据库注册观察者。当分布式数据库中的数据发生更改时，将调用回调。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| type | 表示在[Rdb_SubscribeType](#rdb_subscribetype)中定义的订阅类型。 |
| observer | 数据库中更改事件的观察者[Rdb_DataObserver](_rdb___data_observer.md)。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_DataObserver](_rdb___data_observer.md).


### OH_Rdb_SubscribeAutoSyncProgress()

```
int OH_Rdb_SubscribeAutoSyncProgress (OH_Rdb_Store *store, const Rdb_ProgressObserver *observer )
```

**描述**

订阅RDB存储的自动同步进度。当收到自动同步进度的通知时，将调用回调。RDB_OK表示成功。RDB_E_INVALID_ARGS表示无效参数。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向目标[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| observer | 用于自动同步进度的观察者[Rdb_ProgressObserver](_rdb___progress_observer.md)。表示调用返回自动同步进度的回调。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_ProgressObserver](_rdb___progress_observer.md).

### OH_Rdb_UnlockRow()

```
int OH_Rdb_UnlockRow (OH_Rdb_Store *store, OH_Predicates *predicates )
```

**描述**

根据指定的条件锁解锁数据库中的数据。

**起始版本：** 12

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定解锁条件。 |

**返回：**

返回解锁结果。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).

### OH_Rdb_Unsubscribe()

```
int OH_Rdb_Unsubscribe (OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer )
```

**描述**

从数据库中删除指定类型的指定观察者。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| type | 表示在[Rdb_SubscribeType](#rdb_subscribetype)中定义的订阅类型。 |
| observer | 数据库中更改事件的观察者[Rdb_DataObserver](_rdb___data_observer.md)。如果这是nullptr，表示删除该类型的所有观察者。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_DataObserver](_rdb___data_observer.md).


### OH_Rdb_UnsubscribeAutoSyncProgress()

```
int OH_Rdb_UnsubscribeAutoSyncProgress (OH_Rdb_Store *store, const Rdb_ProgressObserver *observer )
```

**描述**

取消订阅RDB存储的自动同步进程。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向目标[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| observer | 表示自动同步进度的观察者[Rdb_ProgressObserver](_rdb___progress_observer.md)。如果是空指针，则自动同步进程的所有回调都将被取消注册。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

RDB_OK 表示成功。

RDB_E_INVALID_ARGS 表示无效参数。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_ProgressObserver](_rdb___progress_observer.md).


### OH_Rdb_Update()

```
int OH_Rdb_Update (OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates )
```

**描述**

根据指定的条件更新数据库中的数据。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| store | 表示指向[OH_Rdb_Store](_o_h___rdb___store.md)实例的指针。 |
| valuesBucket | 表示要更新到表中的数据行[OH_VBucket](_o_h___v_bucket.md)。 |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针，指定更新条件。 |

**返回：**

如果更新成功，返回更新的行数，否则返回的结果小于0。

**参见：**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Bucket](_o_h___v_bucket.md), [OH_Predicates](_o_h___predicates.md).


### OH_VBucket_PutAsset()

```
int OH_VBucket_PutAsset (OH_VBucket *bucket, const char *field, OH_Asset *value )
```

**描述**

将**OH_Asset** 类型的对象放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### OH_VBucket_PutAssets()

```
int OH_VBucket_PutAssets (OH_VBucket *bucket, const char *field, OH_Asset **value, int count )
```

**描述**

将**OH_Asset** 类型的对象数组放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |
| count | 表示传入的**OH_Asset**对象数组元素的个数。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).

## 变量说明


### andOperate

```
OH_Predicates *(*andOperate) (OH_Predicates *predicates)
```

**描述**

函数指针，向谓词添加和条件。

该方法等同于SQL语句中的“AND”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回：**

返回带有和条件的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### area

```
int OH_Rdb_Config::area
```

**描述**

设置数据库安全区域等级[Rdb_SecurityArea](#rdb_securityarea)。

**起始版本：** 11


### beginWrap

```
OH_Predicates *(*beginWrap) (OH_Predicates *predicates)
```

**描述**

函数指针，向谓词添加左括号。

该方法等同于SQL语句中的“(”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回：**

返回带有左括号的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### between

```
OH_Predicates *(*between) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，将谓词配置为匹配数据字段为field且其值在给定范围内的指定字段。

该方法等同于SQL语句中的“BETWEEN”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### briefObserver

```
Rdb_BriefObserver Rdb_SubscribeCallback::briefObserver
```

**描述**

端云数据更改事件的回调函数。


### bundleName

```
const char* OH_Rdb_Config::bundleName
```

**描述**

应用包名。


### callback [1/2]

```
Rdb_SubscribeCallback Rdb_DataObserver::callback
```

**描述**

数据观察者的回调。


### callback [2/2]

```
Rdb_ProgressCallback Rdb_ProgressObserver::callback
```

**描述**

端云同步进度观察者的回调函数。


### capability

```
uint16_t OH_VBucket::capability
```

**描述**

表示结构体的存储键值对的数量。


### ChangeType

```
int Rdb_ChangeInfo::ChangeType
```

**描述**

表示发生变化的数据的类型，数据或者资产附件发生变化。


### clear [1/2]

```
OH_Predicates *(*clear) (OH_Predicates *predicates)
```

**描述**

函数指针，清空谓词。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回：**

返回清空后的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### clear [2/2]

```
int(*clear) (OH_VBucket *bucket)
```

**描述**

清空[OH_VBucket](_o_h___v_bucket.md)对象。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### code

```
int Rdb_ProgressDetails::code
```

**描述**

表示端云同步过程的状态。


### context [1/2]

```
void* Rdb_DataObserver::context
```

**描述**

表示数据观察者的上下文。


### context [2/2]

```
void* Rdb_ProgressObserver::context
```

**描述**

端云同步进度观察者的上下文。


### count

```
int Rdb_KeyInfo::count
```

**描述**

表示发生变化的主键或者行号的数量。


### dataBaseDir

```
const char* OH_Rdb_Config::dataBaseDir
```

**描述**

数据库文件路径。


### deleted

```
Rdb_KeyInfo Rdb_ChangeInfo::deleted
```

**描述**

记录删除数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示删除数据的行号。


### destroy [1/4]

```
int(*destroy) (OH_Cursor *cursor)
```

**描述**

函数指针，关闭结果集。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### destroy [2/4]

```
int(*destroy) (OH_Predicates *predicates)
```

**描述**

销毁[OH_Predicates](_o_h___predicates.md)对象，并回收该对象占用的内存。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### destroy [3/4]

```
int(*destroy) (OH_VBucket *bucket)
```

**描述**

销毁[OH_VBucket](_o_h___v_bucket.md)对象，并回收该对象占用的内存。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### destroy [4/4]

```
int(*destroy) (OH_VObject *valueObject)
```

**描述**

销毁[OH_VObject](_o_h___v_object.md)对象，并回收该对象占用的内存。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VObject](_o_h___v_object.md).


### detailsObserver

```
Rdb_DetailsObserver Rdb_SubscribeCallback::detailsObserver
```

**描述**

端云数据更改事件的细节的回调函数。


### distinct

```
OH_Predicates *(*distinct) (OH_Predicates *predicates)
```

**描述**

函数指针，配置谓词以过滤重复记录并仅保留其中一个。

该方法等同于SQL语句中的“DISTINCT”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回：**

返回可用于过滤重复记录的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### download

```
Rdb_Statistic Rdb_TableDetails::download
```

**描述**

表示数据库表中端云同步下载过程的统计信息。


### endWrap

```
OH_Predicates *(*endWrap) (OH_Predicates *predicates)
```

**描述**

函数指针，向谓词添加右括号。

该方法等同于SQL语句中的“)”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回：**

返回带有右括号的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### equalTo

```
OH_Predicates *(*equalTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段等于指定值的字段。

该方法等同于SQL语句中的“=”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### failed

```
int Rdb_Statistic::failed
```

**描述**

表示数据库表中端云同步失败的行数。


### getAsset

```
int(*getAsset) (OH_Cursor *cursor, int32_t columnIndex, Data_Asset *value)
```

**描述**

函数指针，以资产的形式获取当前行中指定列的值。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| value | 该参数是输出参数，结果集中指定列的值会以资产形式写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getAssets

```
int(*getAssets) (OH_Cursor *cursor, int32_t columnIndex, Data_Asset **value, uint32_t length)
```

**描述**

函数指针，以资产数组的形式获取当前行中指定列的值。

**起始版本：** 11

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| value | 该参数是输出参数，结果集中指定列的值会以资产数组形式写入该变量。 |
| length | 既是入参又是出参：作为入参，需要开发者传入一个uint32_t类型的变量，表示输入缓冲区的大小；作为出参，表示函数执行后，length指向的变量会被更新为实际返回的资产数组的长度。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getBlob

```
int(*getBlob) (OH_Cursor *cursor, int32_t columnIndex, unsigned char *value, int length)
```

**描述**

函数指针，以字节数组的形式获取当前行中指定列的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| value | 该参数是输出参数，结果集中指定列的值会以字节数组形式写入该变量。 |
| length | 该参数为输入参数，表示传入的value的长度，该值可通过getSize获取。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getColumnCount

```
int(*getColumnCount) (OH_Cursor *cursor, int *count)
```

**描述**

函数指针，获取结果集中的列数。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| count | 该参数是输出参数，结果集中的列数会写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getColumnIndex

```
int(*getColumnIndex) (OH_Cursor *cursor, const char *name, int *columnIndex)
```

**描述**

函数指针，根据指定的列名获取列索引。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| name | 表示结果集中指定列的名称。 |
| columnIndex | 该参数是输出参数，结果集中指定列的索引会写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getColumnName

```
int(*getColumnName) (OH_Cursor *cursor, int32_t columnIndex, char *name, int length)
```

**描述**

函数指针，根据指定的列索引获取列名。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| name | 该参数是输出参数，结果集中指定列的名称会写入该变量。 |
| length | 该参数为输入参数，表示开发者传入的包括终止符在内的列名字符串的总长度。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getColumnType

```
int(*getColumnType) (OH_Cursor *cursor, int32_t columnIndex, OH_ColumnType *columnType)
```

**描述**

函数指针，根据指定的列索引获取列类型。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| columnType | 该参数是输出参数，结果集中指定列的数据类型[OH_ColumnType](#oh_columntype)会写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md), [OH_ColumnType](#oh_columntype).


### getInt64

```
int(*getInt64) (OH_Cursor *cursor, int32_t columnIndex, int64_t *value)
```

**描述**

函数指针，以int64_t形式获取当前行中指定列的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| value | 该参数是输出参数，结果集中指定列的值会以int64_t形式写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getReal

```
int(*getReal) (OH_Cursor *cursor, int32_t columnIndex, double *value)
```

**描述**

函数指针，以double形式获取当前行中指定列的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| value | 该参数是输出参数，结果集中指定列的值会以double形式写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getRowCount

```
int(*getRowCount) (OH_Cursor *cursor, int *count)
```

**描述**

函数指针，获取结果集中的行数。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| count | 该参数是输出参数，结果集中的行数会写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getSize

```
int(*getSize) (OH_Cursor *cursor, int32_t columnIndex, size_t *size)
```

**描述**

函数指针，当结果集中列的数据类型是BLOB或者TEXT时，获取其值所需的内存。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| size | 该参数是输出参数，BLOB或者TEXT数据所需内存大小会写入该变量。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### getText

```
int(*getText) (OH_Cursor *cursor, int32_t columnIndex, char *value, int length)
```

**描述**

函数指针，以字符串形式获取当前行中指定列的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| value | 该参数是输出参数，结果集中指定列的值会以字符串形式写入该变量。 |
| length | 该参数是输入参数，表示value的长度，该值可通过getSize获取。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### goToNextRow

```
int(*goToNextRow) (OH_Cursor *cursor)
```

**描述**

函数指针，转到结果集的下一行。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### greaterThan

```
OH_Predicates *(*greaterThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段为field且值大于指定值valueObject的字段。

该方法等同于SQL语句中的“&gt;”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### greaterThanOrEqualTo

```
OH_Predicates *(*greaterThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段为field且值大于或等于指定值valueObject的字段。

该方法等同于SQL语句中的“&gt;=”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### groupBy

```
OH_Predicates *(*groupBy) (OH_Predicates *predicates, char const *const *fields, int length)
```

**描述**

函数指针，配置R谓词按指定列分组查询结果。

该方法等同于SQL语句中的“GROUP BY”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| fields | 指定分组依赖的列名。 |
| length | 该参数为输入参数，表示开发者传入的fields数值的长度。 |

**返回：**

返回分组查询列的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### id [1/5]

```
int64_t OH_Cursor::id
```

**描述**

OH_Cursor结构体的唯一标识符。


### id [2/5]

```
int64_t OH_Predicates::id
```

**描述**

OH_Predicates结构体的唯一标识符。


### id [3/5]

```
int64_t OH_VObject::id
```

**描述**

OH_VObject结构体的唯一标识符。


### id [4/5]

```
int64_t OH_VBucket::id
```

**描述**

OH_VBucket结构体的唯一标识符。


### id [5/5]

```
int64_t OH_Rdb_Store::id
```

**描述**

OH_Rdb_Store结构体的唯一标识符。


### in

```
OH_Predicates *(*in) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段为field且值在给定范围内的指定字段。

该方法等同于SQL语句中的“IN”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 表示数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### inserted

```
Rdb_KeyInfo Rdb_ChangeInfo::inserted
```

**描述**

记录插入数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示插入数据的行号。


### integer

```
uint64_t Rdb_KeyInfo::Rdb_KeyData::integer
```

**描述**

存放uint64_t类型的数据。


### isAutoSync

```
bool Rdb_DistributedConfig::isAutoSync
```

**描述**

表示该表是否支持自动同步。


### isEncrypt

```
bool OH_Rdb_Config::isEncrypt
```

**描述**

指定数据库是否加密。


### isNotNull

```
OH_Predicates *(*isNotNull) (OH_Predicates *predicates, const char *field)
```

**描述**

函数指针，配置谓词以匹配值不为null的指定字段。

该方法等同于SQL语句中的“IS NOT NULL”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### isNull [1/2]

```
int(*isNull) (OH_Cursor *cursor, int32_t columnIndex, bool *isNull)
```

**描述**

函数指针，检查当前行中指定列的值是否为null。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| cursor | 表示指向[OH_Cursor](_o_h___cursor.md)实例的指针。 |
| columnIndex | 表示结果集中指定列的索引，索引值从0开始。 |
| isNull | 该参数是输出参数，如果当前行中指定列的值为null，该值为true，否则为false。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_Cursor](_o_h___cursor.md).


### isNull [2/2]

```
OH_Predicates *(*isNull) (OH_Predicates *predicates, const char *field)
```

**描述**

函数指针，配置谓词以匹配值为null的字段。

该方法等同于SQL语句中的“IS NULL”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### lessThan

```
OH_Predicates *(*lessThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段为field且值小于指定值valueObject的字段。

该方法等同于SQL语句中的“&lt;”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### lessThanOrEqualTo

```
OH_Predicates *(*lessThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段为field且值小于或等于指定值valueObject的字段。

该方法等同于SQL语句中的“&lt;=”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### like

```
OH_Predicates *(*like) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段为field且值类似于指定字符串的字段。

该方法等同于SQL语句中的“LIKE”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### limit

```
OH_Predicates *(*limit) (OH_Predicates *predicates, unsigned int value)
```

**描述**

函数指针，设置最大数据记录数的谓词。

该方法等同于SQL语句中的“LIMIT”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| value | 表示最大数据记录数。 |

**返回：**

返回可用于设置最大数据记录数的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### moduleName

```
const char* OH_Rdb_Config::moduleName
```

**描述**

应用模块名。


### notBetween

```
OH_Predicates *(*notBetween) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，将谓词配置为匹配数据字段为field且其值超出给定范围内的指定字段。

该方法等同于SQL语句中的“NOT BETWEEN”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notEqualTo

```
OH_Predicates *(*notEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段不等于指定值的字段。

该方法等同于SQL语句中的“!=”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notIn

```
OH_Predicates *(*notIn) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**描述**

函数指针，配置谓词以匹配数据字段为field且值超出给定范围内的指定字段。

该方法等同于SQL语句中的“NOT IN”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 表示数据库表中的列名。 |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针，指示要与谓词匹配的值。 |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### offset

```
OH_Predicates *(*offset) (OH_Predicates *predicates, unsigned int rowOffset)
```

**描述**

函数指针，配置谓词以指定返回结果的起始位置。

该方法等同于SQL语句中的“OFFSET”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| rowOffset | 返回结果的起始位置，取值为正整数。 |

**返回：**

返回具有指定返回结果起始位置的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### orderBy

```
OH_Predicates *(*orderBy) (OH_Predicates *predicates, const char *field, OH_OrderType type)
```

**描述**

函数指针，配置谓词以匹配其值按升序或降序排序的列。

该方法等同于SQL语句中的“ORDER BY”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |
| field | 数据库表中的列名。 |
| type | 表示排序类型 [OH_OrderType](#oh_ordertype). |

**返回：**

返回与指定字段匹配的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md), [OH_OrderType](#oh_ordertype).


### orOperate

```
OH_Predicates *(*orOperate) (OH_Predicates *predicates)
```

**描述**

函数指针，将或条件添加到谓词中。

该方法等同于SQL语句中的“OR”。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| predicates | 表示指向[OH_Predicates](_o_h___predicates.md)实例的指针。 |

**返回：**

返回带有或条件的谓词。

**参见：**

[OH_Predicates](_o_h___predicates.md).


### putBlob

```
int(*putBlob) (OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)
```

**描述**

将const uint8_t \*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |
| size | 表示value的长度。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### putDouble

```
int(*putDouble) (OH_VObject *valueObject, double *value, uint32_t count)
```

**描述**

将double类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示指向double类型的单个参数或者数组的指针。 |
| count | 如果value是指向单个数值的指针，则count = 1；如果value是指向数组的指针，则count是数组的长度。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VObject](_o_h___v_object.md).


### putInt64 [1/2]

```
int(*putInt64) (OH_VBucket *bucket, const char *field, int64_t value)
```

**描述**

将int64_t值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### putInt64 [2/2]

```
int(*putInt64) (OH_VObject *valueObject, int64_t *value, uint32_t count)
```

**描述**

将int64类型的单个参数或者数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示指向int64_t类型的单个参数或者数组的指针。 |
| count | 如果value是指向单个数值的指针，则count = 1；如果value是指向数组的指针，则count是数组的长度。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VObject](_o_h___v_object.md).


### putNull

```
int(*putNull) (OH_VBucket *bucket, const char *field)
```

**描述**

将NULL值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### putReal

```
int(*putReal) (OH_VBucket *bucket, const char *field, double value)
```

**描述**

将double值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### putText [1/2]

```
int(*putText) (OH_VBucket *bucket, const char *field, const char *value)
```

**描述**

将char\*值放入给定列名的[OH_VBucket](_o_h___v_bucket.md)对象中。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| bucket | 表示指向[OH_VBucket](_o_h___v_bucket.md)实例的指针。 |
| field | 数据库表中的列名。 |
| value | 数据库表中指定列名对应的值。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VBucket](_o_h___v_bucket.md).


### putText [2/2]

```
int(*putText) (OH_VObject *valueObject, const char *value)
```

**描述**

将char \*类型的字符数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示字符数组参数。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VObject](_o_h___v_object.md).


### putTexts

```
int(*putTexts) (OH_VObject *valueObject, const char **value, uint32_t count)
```

**描述**

将char \*类型的字符串数组转换为[OH_VObject](_o_h___v_object.md)类型的值。

**起始版本：** 10

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| valueObject | 表示指向[OH_VObject](_o_h___v_object.md)实例的指针。 |
| value | 表示字符串数组参数。 |
| count | 表示字符串数组参数value的长度。 |

**返回：**

返回操作是否成功，出错时返回对应的错误码。

**参见：**

[OH_VObject](_o_h___v_object.md).


### real

```
double Rdb_KeyInfo::Rdb_KeyData::real
```

**描述**

存放double类型的数据。


### remained

```
int Rdb_Statistic::remained
```

**描述**

表示数据库表中端云同步剩余未执行的行数。


### schedule

```
int Rdb_ProgressDetails::schedule
```

**描述**

表示端云同步过程。


### securityLevel

```
int OH_Rdb_Config::securityLevel
```

**描述**

设置数据库安全级别[OH_Rdb_SecurityLevel](#oh_rdb_securitylevel)。


### selfSize

```
int OH_Rdb_Config::selfSize
```

**描述**

该结构体的大小。


### storeName

```
const char* OH_Rdb_Config::storeName
```

**描述**

数据库名称。


### successful

```
int Rdb_Statistic::successful
```

**描述**

表示数据库表中端云同步成功的行数。


### table

```
const char* Rdb_TableDetails::table
```

**描述**

数据库表名。


### tableLength

```
int32_t Rdb_ProgressDetails::tableLength
```

**描述**

表示端云同步的表的数量。


### tableName

```
const char* Rdb_ChangeInfo::tableName
```

**描述**

表示发生变化的表的名称。


### text

```
const char* Rdb_KeyInfo::Rdb_KeyData::text
```

**描述**

存放char \*类型的数据。


### total

```
int Rdb_Statistic::total
```

**描述**

表示数据库表中需要端云同步的总行数。


### type

```
int Rdb_KeyInfo::type
```

**描述**

表示主键的类型[OH_ColumnType](#oh_columntype)。


### updated

```
Rdb_KeyInfo Rdb_ChangeInfo::updated
```

**描述**

记录更新数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示更新数据的行号。


### upload

```
Rdb_Statistic Rdb_TableDetails::upload
```

**描述**

表示数据库表中端云同步上传过程的统计信息。


### version [1/3]

```
int Rdb_DistributedConfig::version
```

**描述**

用于唯一标识Rdb_DistributedConfig结构的版本。


### version [2/3]

```
int Rdb_ChangeInfo::version
```

**描述**

用于唯一标识Rdb_DistributedConfig结构的版本。


### version [3/3]

```
int Rdb_ProgressDetails::version
```

**描述**

用于唯一标识OH_TableDetails结构的版本。
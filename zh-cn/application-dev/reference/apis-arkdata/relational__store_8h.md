# relational_store.h


## 概述

提供管理关系数据库（RDB）方法的接口，未标注支持向量数据库的接口仅支持关系型数据库。

**引用文件：** <database/rdb/relational_store.h>

**库：** libnative_rdb_ndk.z.so

**起始版本：** 10

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_Config](_o_h___rdb___config.md) | 管理关系数据库配置。 |
| [OH_Rdb_Store](_o_h___rdb___store.md) | 表示数据库类型。 |
| [Rdb_DistributedConfig](_rdb___distributed_config.md) | 记录表的分布式配置信息。 |
| [Rdb_KeyInfo](_rdb___key_info.md) | 描述发生变化的行的主键或者行号。 |
| [Rdb_KeyInfo::Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) | 存放变化的具体数据 |
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
| [DISTRIBUTED_CONFIG_VERSION](_r_d_b.md#distributed_config_version)&nbsp;&nbsp;&nbsp;1 | 描述[Rdb_DistributedConfig](_rdb___distributed_config.md)的版本。 |
| [DISTRIBUTED_CHANGE_INFO_VERSION](_r_d_b.md#distributed_change_info_version)&nbsp;&nbsp;&nbsp;1 | 描述[Rdb_ChangeInfo](_rdb___change_info.md)的版本。 |
| [DISTRIBUTED_PROGRESS_DETAIL_VERSION](_r_d_b.md#distributed_progress_detail_version)&nbsp;&nbsp;&nbsp;1 | 描述[Rdb_ProgressDetails](_rdb___progress_details.md)的版本。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel) | 数据库的安全级别枚举。 |
| [Rdb_SecurityArea](_r_d_b.md#rdb_securityarea) | 描述数据库的安全区域等级。 |
| typedef struct [OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) [OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) | 管理关系数据库配置，与[OH_Rdb_Config](_o_h___rdb___config.md)的区别是该结构体成员变量不对外暴露，使用一系列方法配置该结构体的属性，支持向量数据库。 |
| typedef enum [Rdb_DBType](_r_d_b.md#rdb_dbtype) [Rdb_DBType](_r_d_b.md#rdb_dbtype) | 描述数据库的内核类型。 |
| [Rdb_DistributedType](_r_d_b.md#rdb_distributedtype) | 描述表的分布式类型的枚举。 |
| [Rdb_DistributedConfig](_r_d_b.md#rdb_distributedconfig) | 记录表的分布式配置信息。 |
| [Rdb_ChangeType](_r_d_b.md#rdb_changetype) | 描述数据变更类型。 |
| [Rdb_KeyInfo](_r_d_b.md#rdb_keyinfo) | 描述发生变化的行的主键或者行号。 |
| [Rdb_ChangeInfo](_r_d_b.md#rdb_changeinfo) | 记录端云同步过程详情。 |
| [Rdb_SubscribeType](_r_d_b.md#rdb_subscribetype) | 描述订阅类型。 |
| [Rdb_BriefObserver](_r_d_b.md#rdb_briefobserver) | 端云数据更改事件的回调函数。 |
| [Rdb_DetailsObserver](_r_d_b.md#rdb_detailsobserver) | 端云数据更改事件的细节的回调函数。 |
| [Rdb_SubscribeCallback](union_rdb___subscribe_callback.md) | 表示回调函数。 |
| [Rdb_DataObserver](_rdb___data_observer.md) | 表示数据观察者。 |
| [Rdb_SyncMode](_r_d_b.md#rdb_syncmode) | 表示数据库的同步模式 |
| [Rdb_Statistic](_r_d_b.md#rdb_statistic) | 描述数据库表的端云同步过程的统计信息。 |
| [Rdb_TableDetails](_r_d_b.md#rdb_tabledetails) | 描述数据库表执行端云同步任务上传和下载的统计信息。 |
| [Rdb_Progress](_r_d_b.md#rdb_progress) | 描述端云同步过程。 |
| [Rdb_ProgressCode](_r_d_b.md#rdb_progresscode) | 表示端云同步过程的状态。 |
| [Rdb_ProgressDetails](_r_d_b.md#rdb_progressdetails) | 描述数据库整体执行端云同步任务上传和下载的统计信息。 |
| [Rdb_ProgressCallback](_r_d_b.md#rdb_progresscallback) | 端云同步进度的回调函数。 |
| [Rdb_SyncCallback](_r_d_b.md#rdb_synccallback) | 数据库端云同步的回调函数。 |
| [Rdb_ProgressObserver](_r_d_b.md#rdb_progressobserver) | 端云同步进度观察者。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel-1) { S1 = 1, S2, S3, S4} | 数据库的安全级别枚举。 |
| [Rdb_SecurityArea](_r_d_b.md#rdb_securityarea-1) { RDB_SECURITY_AREA_EL1 = 1, RDB_SECURITY_AREA_EL2, RDB_SECURITY_AREA_EL3, RDB_SECURITY_AREA_EL4 } | 描述数据库的安全区域等级。 |
| [Rdb_DBType](_r_d_b.md#rdb_dbtype-1) { RDB_SQLITE = 1, RDB_CAYLEY = 2, DBTYPE_BUTT = 64 } | 描述数据库的内核类型。 |
| [Rdb_DistributedType](_r_d_b.md#rdb_distributedtype-1) { RDB_DISTRIBUTED_CLOUD } | 描述表的分布式类型的枚举。 |
| [Rdb_ChangeType](_r_d_b.md#rdb_changetype-1) { RDB_DATA_CHANGE, RDB_ASSET_CHANGE } | 描述数据变更类型。 |
| [Rdb_SubscribeType](_r_d_b.md#rdb_subscribetype-1) { RDB_SUBSCRIBE_TYPE_CLOUD, RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS, RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS } | 描述订阅类型。 |
| [Rdb_SyncMode](_r_d_b.md#rdb_syncmode-1) { RDB_SYNC_MODE_TIME_FIRST, RDB_SYNC_MODE_NATIVE_FIRST, RDB_SYNC_MODE_CLOUD_FIRST } | 表示数据库的同步模式 |
| [Rdb_Progress](_r_d_b.md#rdb_progress-1) { RDB_SYNC_BEGIN, RDB_SYNC_IN_PROGRESS, RDB_SYNC_FINISH } | 描述端云同步过程。 |
| [Rdb_ProgressCode](_r_d_b.md#rdb_progresscode-1) {<br/>RDB_SUCCESS, RDB_UNKNOWN_ERROR, RDB_NETWORK_ERROR, RDB_CLOUD_DISABLED,<br/>RDB_LOCKED_BY_OTHERS, RDB_RECORD_LIMIT_EXCEEDED, RDB_NO_SPACE_FOR_ASSET<br/>} | 表示端云同步过程的状态。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| int [OH_Rdb_CreateTransaction](_r_d_b.md#oh_rdb_createtransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) \*options, [OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*\*trans) | 创建一个事务对象。 |
| int [OH_Rdb_ExecuteV2](_r_d_b.md#oh_rdb_executev2) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql, const [OH_Data_Values](_r_d_b.md#oh_data_values) \*args, [OH_Data_Value](_r_d_b.md#oh_data_value) \*\*result) | 执行有返回值的SQL语句，支持向量数据库。 |
| [OH_Cursor](_o_h___cursor.md) \* [OH_Rdb_ExecuteQueryV2](_r_d_b.md#oh_rdb_executequeryv2) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql, const [OH_Data_Values](_r_d_b.md#oh_data_values) \*args) | 根据指定SQL语句查询数据库中的数据，支持向量数据库。 |
| int [OH_Rdb_IsTokenizerSupported](_r_d_b.md#oh_rdb_istokenizersupported) ([Rdb_Tokenizer](_r_d_b.md#rdb_tokenizer) tokenizer, bool \*isSupported) | 判断当前平台是否支持传入的分词器。 |
| int [OH_Rdb_SetTokenizer](_r_d_b.md#oh_rdb_settokenizer) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, [Rdb_Tokenizer](_r_d_b.md#rdb_tokenizer) tokenizer) | 给指定的数据库文件配置设置分词器类型。 |
| [OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \* [OH_Rdb_CreateConfig](_r_d_b.md#oh_rdb_createconfig) () | 创建一个[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)实例，并返回指向该实例的指针。 |
| int [OH_Rdb_DestroyConfig](_r_d_b.md#oh_rdb_destroyconfig) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config) | 销毁由[OH_Rdb_CreateConfig](_r_d_b.md#oh_rdb_createconfig)创建的[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)对象。 |
| int [OH_Rdb_SetDatabaseDir](_r_d_b.md#oh_rdb_setdatabasedir) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, const char \*databaseDir) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置数据库文件路径。 |
| int [OH_Rdb_SetStoreName](_r_d_b.md#oh_rdb_setstorename) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, const char \*storeName) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置数据库名称。 |
| int [OH_Rdb_SetBundleName](_r_d_b.md#oh_rdb_setbundlename) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, const char \*bundleName) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置应用包名。 |
| int [OH_Rdb_SetModuleName](_r_d_b.md#oh_rdb_setmodulename) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, const char \*moduleName) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置应用模块名。 |
| int [OH_Rdb_SetEncrypted](_r_d_b.md#oh_rdb_setencrypted) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, bool isEncrypted) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置数据库是否加密。 |
| int [OH_Rdb_SetSecurityLevel](_r_d_b.md#oh_rdb_setsecuritylevel) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, int securityLevel) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置数据库安全级别[OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel)。 |
| int [OH_Rdb_SetArea](_r_d_b.md#oh_rdb_setarea) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, int area) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置数据库安全区域等级[Rdb_SecurityArea](_r_d_b.md#rdb_securityarea)。 |
| int [OH_Rdb_SetDbType](_r_d_b.md#oh_rdb_setdbtype) ([OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, int dbType) | 给指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)，设置数据库类型[Rdb_DBType](_r_d_b.md#rdb_dbtype)。 |
| const int \* [OH_Rdb_GetSupportedDbType](_r_d_b.md#oh_rdb_getsupporteddbtype) (int \*typeCount) | 获得支持的数据库类型[Rdb_DBType](_r_d_b.md#rdb_dbtype)。 |
| [OH_Rdb_Store](_o_h___rdb___store.md) \* [OH_Rdb_CreateOrOpen](_r_d_b.md#oh_rdb_createoropen) (const [OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config, int \*errCode) | 使用指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2), 获得一个对应的[OH_Rdb_Store](_o_h___rdb___store.md)实例，用来操作关系型数据库。 |
| int [OH_Rdb_ExecuteByTrxId](_r_d_b.md#oh_rdb_executebytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId, const char \*sql) | 使用指定的事务ID执行无返回值的SQL语句，支持向量数据库。 |
| int [OH_Rdb_BeginTransWithTrxId](_r_d_b.md#oh_rdb_begintranswithtrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t \*trxId) | 在开始执行SQL语句之前，开始事务, 并获得该事务的ID，支持向量数据库。 |
| int [OH_Rdb_RollBackByTrxId](_r_d_b.md#oh_rdb_rollbackbytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId) | 使用指定的事务ID, 回滚已经执行的SQL语句，支持向量数据库。 |
| int [OH_Rdb_CommitByTrxId](_r_d_b.md#oh_rdb_commitbytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId) | 使用指定的事务ID, 提交已经执行的SQL语句，支持向量数据库。 |
| [OH_Rdb_CreateValueObject](_r_d_b.md#oh_rdb_createvalueobject) (void) | 创建[OH_VObject](_o_h___v_object.md)实例。 |
| [OH_Rdb_CreateValuesBucket](_r_d_b.md#oh_rdb_createvaluesbucket) (void) | 创建[OH_VBucket](_o_h___v_bucket.md)实例。 |
| [OH_Rdb_CreatePredicates](_r_d_b.md#oh_rdb_createpredicates) (const char \*table) | 创建[OH_Predicates](_o_h___predicates.md)实例。 |
| [OH_Rdb_GetOrOpen](_r_d_b.md#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | 获得一个相关的[OH_Rdb_Store](_o_h___rdb___store.md)实例，操作关系型数据库。 |
| [OH_Rdb_CloseStore](_r_d_b.md#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 销毁[OH_Rdb_Store](_o_h___rdb___store.md)对象，并回收该对象占用的内存。 |
| [OH_Rdb_DeleteStore](_r_d_b.md#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | 使用指定的数据库文件配置删除数据库。 |
| int [OH_Rdb_DeleteStoreV2](_r_d_b.md#oh_rdb_deletestorev2) (const [OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2) \*config) | 使用指定的数据库文件配置[OH_Rdb_ConfigV2](_r_d_b.md#oh_rdb_configv2)删除数据库。当使用向量数据库时，在调用接口前，应当确保向量数据库已经被正确关闭。 |
| [OH_Rdb_Insert](_r_d_b.md#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | 向目标表中插入一行数据。 |
| [OH_Rdb_Update](_r_d_b.md#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件更新数据库中的数据。 |
| [OH_Rdb_Delete](_r_d_b.md#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件删除数据库中的数据。 |
| [OH_Rdb_Query](_r_d_b.md#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | 根据指定条件查询数据库中的数据 |
| [OH_Rdb_Execute](_r_d_b.md#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | 执行无返回值的SQL语句。 |
| [OH_Rdb_ExecuteQuery](_r_d_b.md#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | 根据指定SQL语句查询数据库中的数据，支持向量数据库。 |
| [OH_Rdb_BeginTransaction](_r_d_b.md#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 在开始执行SQL语句之前，开始事务。 |
| [OH_Rdb_RollBack](_r_d_b.md#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 回滚已经执行的SQL语句。 |
| [OH_Rdb_Commit](_r_d_b.md#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 提交已执行的SQL语句 |
| [OH_Rdb_Backup](_r_d_b.md#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | 以指定路径备份数据库，支持向量数据库。 |
| [OH_Rdb_Restore](_r_d_b.md#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | 从指定的数据库备份文件恢复数据库，支持向量数据库。 |
| [OH_Rdb_GetVersion](_r_d_b.md#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | 获取数据库版本。 |
| [OH_Rdb_SetVersion](_r_d_b.md#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | 设置数据库版本。 |
| [OH_Rdb_SetDistributedTables](_r_d_b.md#oh_rdb_setdistributedtables) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tables[], uint32_t count, [Rdb_DistributedType](_r_d_b.md#rdb_distributedtype) type, const [Rdb_DistributedConfig](_rdb___distributed_config.md) \*config) | 设置分布式数据库表。 |
| [OH_Rdb_FindModifyTime](_r_d_b.md#oh_rdb_findmodifytime) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tableName, const char \*columnName, [OH_VObject](_o_h___v_object.md) \*values) | 获取数据库表中数据的最后修改时间。 |
| [OH_Rdb_Subscribe](_r_d_b.md#oh_rdb_subscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](_r_d_b.md#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | 为数据库注册观察者。当分布式数据库中的数据发生更改时，将调用回调。 |
| [OH_Rdb_Unsubscribe](_r_d_b.md#oh_rdb_unsubscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](_r_d_b.md#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | 从数据库中删除指定类型的指定观察者。 |
| [OH_Rdb_GetTableDetails](_r_d_b.md#oh_rdb_gettabledetails) ([Rdb_ProgressDetails](_rdb___progress_details.md) \*progress, int32_t version) | 从端云同步任务的统计信息中获取数据库表的统计信息。 |
| [OH_Rdb_CloudSync](_r_d_b.md#oh_rdb_cloudsync) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SyncMode](_r_d_b.md#rdb_syncmode) mode, const char \*tables, int count, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | 进行端云同步。 |
| [OH_Rdb_SubscribeAutoSyncProgress](_r_d_b.md#oh_rdb_subscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | 订阅RDB存储的自动同步进度。 当收到自动同步进度的通知时，将调用回调。 |
| [OH_Rdb_UnsubscribeAutoSyncProgress](_r_d_b.md#oh_rdb_unsubscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | 取消订阅RDB存储的自动同步进程。 |
| int [OH_Rdb_LockRow](_r_d_b.md#oh_rdb_lockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件锁定数据库中的数据，锁定数据不执行端云同步。 |
| int [OH_Rdb_UnlockRow](_r_d_b.md#oh_rdb_unlockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件锁解锁数据库中的数据。 |
| [OH_Cursor](_o_h___cursor.md) \* [OH_Rdb_QueryLockedRow](_r_d_b.md#oh_rdb_querylockedrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | 根据指定条件查询数据库中锁定的数据。 |
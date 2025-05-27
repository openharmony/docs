# relational_store.h

## 概述

提供管理关系数据库（RDB）方法的接口，未标注支持向量数据库的接口仅支持关系型数据库。

**引用文件：** <database/rdb/relational_store.h>

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 10

**相关模块：** [RDB](capi-rdb.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述                                                                      |
| -- | -- |-------------------------------------------------------------------------|
| [OH_Rdb_Config](capi-oh-rdb-config.md) | - | 管理关系数据库配置。                                                              |
| [OH_Rdb_Store](capi-oh-rdb-store.md) | OH_Rdb_Store | 表示数据库类型。                                                                |
| [Rdb_DistributedConfig](capi-rdb-distributedconfig.md) | Rdb_DistributedConfig | 记录表的分布式配置信息。                                                            |
| [Rdb_KeyInfo](capi-rdb-keyinfo.md) | Rdb_KeyInfo | 描述发生变化的行的主键或者行号。                                                        |
| [Rdb_KeyData](capi-rdb-keydata.md) | - | 存放变化的具体数据。                                                              |
| [Rdb_ChangeInfo](capi-rdb-changeinfo.md) | Rdb_ChangeInfo | 记录端云同步过程详情。                                                             |
| [Rdb_SubscribeCallback](capi-rdb-subscribecallback.md) | Rdb_SubscribeCallback | 表示回调函数。                                                                 |
| [Rdb_DataObserver](capi-rdb-dataobserver.md) | Rdb_DataObserver | 表示数据观察者。                                                                |
| [Rdb_Statistic](capi-rdb-statistic.md) | Rdb_Statistic | 描述数据库表的端云同步过程的统计信息。                                                     |
| [Rdb_TableDetails](capi-rdb-tabledetails.md) | Rdb_TableDetails | 描述数据库表执行端云同步任务上传和下载的统计信息。                                               |
| [Rdb_ProgressDetails](capi-rdb-progressdetails.md) | Rdb_ProgressDetails | 描述数据库整体执行端云同步任务上传和下载的统计信息。                                              |
| [Rdb_ProgressObserver](capi-rdb-progressobserver.md) | Rdb_ProgressObserver | 端云同步进度观察者。                                                              |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) | OH_Rdb_ConfigV2 | 管理关系数据库配置，与[OH_Rdb_Config](capi-oh-rdb-config.md)的区别是该结构体成员变量不对外暴露，使用一系列方法配置该结构体的属性，支持向量数据库。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) | OH_Rdb_SecurityLevel | 数据库的安全级别枚举。 |
| [Rdb_SecurityArea](#rdb_securityarea) | Rdb_SecurityArea | 描述数据库的安全区域等级。 |
| [Rdb_DBType](#rdb_dbtype) | Rdb_DBType | 描述数据库的内核类型。 |
| [Rdb_Tokenizer](#rdb_tokenizer) | Rdb_Tokenizer | 描述数据库的分词器类型。 |
| [Rdb_DistributedType](#rdb_distributedtype) | Rdb_DistributedType | 描述表的分布式类型的枚举。 |
| [Rdb_ChangeType](#rdb_changetype) | Rdb_ChangeType | 描述数据变更类型。 |
| [Rdb_SubscribeType](#rdb_subscribetype) | Rdb_SubscribeType | 描述订阅类型。 |
| [Rdb_SyncMode](#rdb_syncmode) | Rdb_SyncMode | 表示数据库的同步模式 |
| [Rdb_Progress](#rdb_progress) | Rdb_Progress | 描述端云同步过程。 |
| [Rdb_ProgressCode](#rdb_progresscode) | Rdb_ProgressCode | 表示端云同步过程的状态。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig()](#oh_rdb_createconfig) | - | 创建一个[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)实例，并返回指向该实例的指针。 |
| [int OH_Rdb_DestroyConfig(OH_Rdb_ConfigV2 *config)](#oh_rdb_destroyconfig) | - | 销毁由[OH_Rdb_CreateConfig](capi-relational-store-h.md#oh_rdb_createconfig)创建的[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象。 |
| [int OH_Rdb_SetDatabaseDir(OH_Rdb_ConfigV2 *config, const char *databaseDir)](#oh_rdb_setdatabasedir) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库文件路径。 |
| [int OH_Rdb_SetStoreName(OH_Rdb_ConfigV2 *config, const char *storeName)](#oh_rdb_setstorename) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库名称。 |
| [int OH_Rdb_SetBundleName(OH_Rdb_ConfigV2 *config, const char *bundleName)](#oh_rdb_setbundlename) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置应用包名。 |
| [int OH_Rdb_SetModuleName(OH_Rdb_ConfigV2 *config, const char *moduleName)](#oh_rdb_setmodulename) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置应用模块名。 |
| [int OH_Rdb_SetEncrypted(OH_Rdb_ConfigV2 *config, bool isEncrypted)](#oh_rdb_setencrypted) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库是否加密。 |
| [int OH_Rdb_SetSecurityLevel(OH_Rdb_ConfigV2 *config, int securityLevel)](#oh_rdb_setsecuritylevel) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库安全级别[OH_Rdb_SecurityLevel](capi-relational-store-h.md#oh_rdb_securitylevel)。 |
| [int OH_Rdb_SetArea(OH_Rdb_ConfigV2 *config, int area)](#oh_rdb_setarea) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库安全区域等级[Rdb_SecurityArea](capi-relational-store-h.md#rdb_securityarea)。 |
| [int OH_Rdb_SetDbType(OH_Rdb_ConfigV2 *config, int dbType)](#oh_rdb_setdbtype) | - | 给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库类型[Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)。 |
| [int OH_Rdb_SetCustomDir(OH_Rdb_ConfigV2 *config, const char *customDir)](#oh_rdb_setcustomdir) | - | 设置数据库的自定义目录。 |
| [int OH_Rdb_SetReadOnly(OH_Rdb_ConfigV2 *config, bool readOnly)](#oh_rdb_setreadonly) | - | 设置关系型数据库是否为只读模式。 |
| [int OH_Rdb_SetPlugins(OH_Rdb_ConfigV2 *config, const char **plugins, int32_t length)](#oh_rdb_setplugins) | - | 设置具有特定功能（如全文检索）的动态库。 |
| [int OH_Rdb_SetCryptoParam(OH_Rdb_ConfigV2 *config, const OH_Rdb_CryptoParam *cryptoParam)](#oh_rdb_setcryptoparam) | - | 设置自定义加密参数。 |
| [int OH_Rdb_IsTokenizerSupported(Rdb_Tokenizer tokenizer, bool *isSupported)](#oh_rdb_istokenizersupported) | - | 判断当前平台是否支持传入的分词器。 |
| [int OH_Rdb_SetTokenizer(OH_Rdb_ConfigV2 *config, Rdb_Tokenizer tokenizer)](#oh_rdb_settokenizer) | - | 给指定的数据库文件配置设置分词器类型。 |
| [int OH_Rdb_SetPersistent(OH_Rdb_ConfigV2 *config, bool isPersistent)](#oh_rdb_setpersistent) | - | 指定数据库是否需要持久化。 |
| [const int *OH_Rdb_GetSupportedDbType(int *typeCount)](#oh_rdb_getsupporteddbtype) | - | 获得支持的数据库类型[Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)。 |
| [OH_VObject *OH_Rdb_CreateValueObject()](#oh_rdb_createvalueobject) | - | 创建[OH_VObject](capi-oh-vobject.md)实例。 |
| [OH_VBucket *OH_Rdb_CreateValuesBucket()](#oh_rdb_createvaluesbucket) | - | 创建[OH_VBucket](capi-oh-vbucket.md)实例。 |
| [OH_Predicates *OH_Rdb_CreatePredicates(const char *table)](#oh_rdb_createpredicates) | - | 创建[OH_Predicates](capi-oh-predicates.md)实例。 |
| [OH_Rdb_Store *OH_Rdb_GetOrOpen(const OH_Rdb_Config *config, int *errCode)](#oh_rdb_getoropen) | - | 获得一个相关的[OH_Rdb_Store](capi-oh-rdb-store.md)实例，操作关系型数据库。 |
| [OH_Rdb_Store *OH_Rdb_CreateOrOpen(const OH_Rdb_ConfigV2 *config, int *errCode)](#oh_rdb_createoropen) | - | 使用指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，获得一个对应的[OH_Rdb_Store](capi-oh-rdb-store.md)实例，用来操作关系型数据库。 |
| [int OH_Rdb_CloseStore(OH_Rdb_Store *store)](#oh_rdb_closestore) | - | 销毁[OH_Rdb_Store](capi-oh-rdb-store.md)对象，并回收该对象占用的内存。 |
| [int OH_Rdb_DeleteStore(const OH_Rdb_Config *config)](#oh_rdb_deletestore) | - | 使用指定的数据库文件配置删除数据库。 |
| [int OH_Rdb_DeleteStoreV2(const OH_Rdb_ConfigV2 *config)](#oh_rdb_deletestorev2) | - | 使用指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)删除数据库。<br>当使用向量数据库时，在调用接口前，应当确保向量数据库已经被正确关闭。 |
| [int OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket)](#oh_rdb_insert) | - | 向目标表中插入一行数据。 |
| [int OH_Rdb_InsertWithConflictResolution(OH_Rdb_Store *store, const char *table, OH_VBucket *row,Rdb_ConflictResolution resolution, int64_t *rowId)](#oh_rdb_insertwithconflictresolution) | - | 向目标表中插入一行数据，并支持冲突解决。 |
| [int OH_Rdb_BatchInsert(OH_Rdb_Store *store, const char *table,const OH_Data_VBuckets *rows, Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdb_batchinsert) | - | 将一批数据插入到目标表中。 |
| [int OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates)](#oh_rdb_update) | - | 根据指定的条件更新数据库中的数据。 |
| [int OH_Rdb_UpdateWithConflictResolution(OH_Rdb_Store *store, OH_VBucket *row, OH_Predicates *predicates,Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdb_updatewithconflictresolution) | - | 根据指定条件更新数据库中的数据，并支持冲突解决。 |
| [int OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates)](#oh_rdb_delete) | - | 根据指定的条件删除数据库中的数据。 |
| [OH_Cursor *OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length)](#oh_rdb_query) | - | 根据指定条件查询数据库中的数据 |
| [int OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql)](#oh_rdb_execute) | - | 执行无返回值的SQL语句。 |
| [int OH_Rdb_ExecuteV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args, OH_Data_Value **result)](#oh_rdb_executev2) | - | 执行有返回值的SQL语句，支持向量数据库。 |
| [int OH_Rdb_ExecuteByTrxId(OH_Rdb_Store *store, int64_t trxId, const char *sql)](#oh_rdb_executebytrxid) | - | 使用指定的事务ID执行无返回值的SQL语句，仅支持向量数据库。 |
| [OH_Cursor *OH_Rdb_ExecuteQuery(OH_Rdb_Store *store, const char *sql)](#oh_rdb_executequery) | - | 根据指定SQL语句查询数据库中的数据，支持向量数据库。 |
| [OH_Cursor *OH_Rdb_ExecuteQueryV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args)](#oh_rdb_executequeryv2) | - | 根据指定SQL语句查询数据库中的数据，支持向量数据库。 |
| [int OH_Rdb_BeginTransaction(OH_Rdb_Store *store)](#oh_rdb_begintransaction) | - | 在开始执行SQL语句之前，开始事务。 |
| [int OH_Rdb_RollBack(OH_Rdb_Store *store)](#oh_rdb_rollback) | - | 回滚已经执行的SQL语句。 |
| [int OH_Rdb_Commit(OH_Rdb_Store *store)](#oh_rdb_commit) | - | 提交已执行的SQL语句 |
| [int OH_Rdb_BeginTransWithTrxId(OH_Rdb_Store *store, int64_t *trxId)](#oh_rdb_begintranswithtrxid) | - | 在开始执行SQL语句之前，开始事务，并获得该事务的ID，仅支持向量数据库。 |
| [int OH_Rdb_RollBackByTrxId(OH_Rdb_Store *store, int64_t trxId)](#oh_rdb_rollbackbytrxid) | - | 使用指定的事务ID, 回滚已经执行的SQL语句，仅支持向量数据库。 |
| [int OH_Rdb_CommitByTrxId(OH_Rdb_Store *store, int64_t trxId)](#oh_rdb_commitbytrxid) | - | 使用指定的事务ID, 提交已经执行的SQL语句，仅支持向量数据库。 |
| [int OH_Rdb_Backup(OH_Rdb_Store *store, const char *databasePath)](#oh_rdb_backup) | - | 以指定路径备份数据库，支持向量数据库。 |
| [int OH_Rdb_Restore(OH_Rdb_Store *store, const char *databasePath)](#oh_rdb_restore) | - | 从指定的数据库备份文件恢复数据库，支持向量数据库。 |
| [int OH_Rdb_GetVersion(OH_Rdb_Store *store, int *version)](#oh_rdb_getversion) | - | 获取数据库版本。 |
| [int OH_Rdb_SetVersion(OH_Rdb_Store *store, int version)](#oh_rdb_setversion) | - | 设置数据库版本。 |
| [int OH_Rdb_SetDistributedTables(OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type,const Rdb_DistributedConfig *config)](#oh_rdb_setdistributedtables) | - | 设置分布式数据库表。 |
| [OH_Cursor *OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName,OH_VObject *values)](#oh_rdb_findmodifytime) | - | 获取数据库表中数据的最后修改时间。 |
| [typedef void (\*Rdb_BriefObserver)(void *context, const char *values[], uint32_t count)](#rdb_briefobserver) | Rdb_BriefObserver | 端云数据更改事件的回调函数。 |
| [typedef void (\*Rdb_DetailsObserver)(void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)](#rdb_detailsobserver) | Rdb_DetailsObserver | 端云数据更改事件的细节的回调函数。 |
| [int OH_Rdb_Subscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer)](#oh_rdb_subscribe) | - | 为数据库注册观察者。当分布式数据库或本地数据库中的数据发生更改时，将调用回调。 |
| [int OH_Rdb_Unsubscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer)](#oh_rdb_unsubscribe) | - | 从数据库中删除指定类型的指定观察者。 |
| [Rdb_TableDetails *OH_Rdb_GetTableDetails(Rdb_ProgressDetails *progress, int32_t version)](#oh_rdb_gettabledetails) | - | 从端云同步任务的统计信息中获取数据库表的统计信息。 |
| [typedef void (\*Rdb_ProgressCallback)(void *context, Rdb_ProgressDetails *progressDetails)](#rdb_progresscallback) | Rdb_ProgressCallback | 端云同步进度的回调函数。 |
| [typedef void (\*Rdb_SyncCallback)(Rdb_ProgressDetails *progressDetails)](#rdb_synccallback) | Rdb_SyncCallback | 数据库端云同步的回调函数。 |
| [int OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count,const Rdb_ProgressObserver *observer)](#oh_rdb_cloudsync) | - | 进行端云同步。 |
| [int OH_Rdb_SubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer)](#oh_rdb_subscribeautosyncprogress) | - | 订阅RDB存储的自动同步进度。<br>当收到自动同步进度的通知时，将调用回调。 |
| [int OH_Rdb_UnsubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer)](#oh_rdb_unsubscribeautosyncprogress) | - | 取消订阅RDB存储的自动同步进程。 |
| [int OH_Rdb_LockRow(OH_Rdb_Store *store, OH_Predicates *predicates)](#oh_rdb_lockrow) | - | 根据指定的条件锁定数据库中的数据，锁定数据不执行端云同步。 |
| [int OH_Rdb_UnlockRow(OH_Rdb_Store *store, OH_Predicates *predicates)](#oh_rdb_unlockrow) | - | 根据指定的条件锁解锁数据库中的数据。 |
| [OH_Cursor *OH_Rdb_QueryLockedRow(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length)](#oh_rdb_querylockedrow) | - | 根据指定条件查询数据库中锁定的数据。 |
| [int OH_Rdb_CreateTransaction(OH_Rdb_Store *store, const OH_RDB_TransOptions *options, OH_Rdb_Transaction **trans)](#oh_rdb_createtransaction) | - | 创建一个事务对象。 |
| [int OH_Rdb_Attach(OH_Rdb_Store *store, const OH_Rdb_ConfigV2 *config, const char *attachName, int64_t waitTime,size_t *attachedNumber)](#oh_rdb_attach) | - | 将数据库文件附加到当前连接的数据库。 |
| [int OH_Rdb_Detach(OH_Rdb_Store *store, const char *attachName, int64_t waitTime, size_t *attachedNumber)](#oh_rdb_detach) | - | 从当前数据库中分离指定的数据库。 |
| [int OH_Rdb_SetLocale(OH_Rdb_Store *store, const char *locale)](#oh_rdb_setlocale) | - | 支持不同语言的排序规则。 |

## 枚举类型说明

### OH_Rdb_SecurityLevel

```
enum OH_Rdb_SecurityLevel
```

**描述**

数据库的安全级别枚举。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| S1 = 1 | S1: 表示数据库的安全级别为低级别。当数据泄露时会产生较低影响。 |
| S2 | S2: 表示数据库的安全级别为中级别。当数据泄露时会产生较大影响。 |
| S3 | S3: 表示数据库的安全级别为高级别。当数据泄露时会产生重大影响。 |
| S4 | S4: 表示数据库的安全级别为关键级别。当数据泄露时会产生严重影响。 |

### Rdb_SecurityArea

```
enum Rdb_SecurityArea
```

**描述**

描述数据库的安全区域等级。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| RDB_SECURITY_AREA_EL1 = 1 | 安全区域等级为1。 |
| RDB_SECURITY_AREA_EL2 | 安全区域等级为2。 |
| RDB_SECURITY_AREA_EL3 | 安全区域等级为3。 |
| RDB_SECURITY_AREA_EL4 | 安全区域等级为4。 |
| RDB_SECURITY_AREA_EL5 | 安全区域等级为5。<br>**起始版本：** 12 |

### Rdb_DBType

```
enum Rdb_DBType
```

**描述**

描述数据库的内核类型。

**起始版本：** 14

| 枚举项 | 描述 |
| -- | -- |
| RDB_SQLITE = 1 | 表示使用sqlite作为数据库内核。 |
| RDB_CAYLEY = 2 | 表示使用凯莱数据库作为数据库内核。 |
| DBTYPE_BUTT = 64 | 表示内核类型枚举值允许取值的最大值，这是一个非法值。 |

### Rdb_Tokenizer

```
enum Rdb_Tokenizer
```

**描述**

描述数据库的分词器类型。

**起始版本：** 17

| 枚举项 | 描述 |
| -- | -- |
| RDB_NONE_TOKENIZER = 1 | 表示不使用分词器。 |
| RDB_ICU_TOKENIZER = 2 | 表示使用原生ICU分词器。 |
| RDB_CUSTOM_TOKENIZER = 3 | 表示使用CUSTOM分词器。	<br>**起始版本：** 18 |

### Rdb_DistributedType

```
enum Rdb_DistributedType
```

**描述**

描述表的分布式类型的枚举。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| RDB_DISTRIBUTED_CLOUD | 表示在设备和云端之间分布式的数据库表。 |

### Rdb_ChangeType

```
enum Rdb_ChangeType
```

**描述**

描述数据变更类型。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| RDB_DATA_CHANGE | 表示是数据发生变更。 |
| RDB_ASSET_CHANGE | 表示是资产附件发生了变更。 |

### Rdb_SubscribeType

```
enum Rdb_SubscribeType
```

**描述**

描述订阅类型。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| RDB_SUBSCRIBE_TYPE_CLOUD | 订阅云端数据更改。 |
| RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS | 订阅云端数据更改详情。 |
| RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS | 订阅本地数据更改详情。 |

### Rdb_SyncMode

```
enum Rdb_SyncMode
```

**描述**

表示数据库的同步模式

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| RDB_SYNC_MODE_TIME_FIRST | 表示数据从修改时间较近的一端同步到修改时间较远的一端。 |
| RDB_SYNC_MODE_NATIVE_FIRST | 表示数据从本地设备同步到云端。 |
| RDB_SYNC_MODE_CLOUD_FIRST | 表示数据从云端同步到本地设备。 |

### Rdb_Progress

```
enum Rdb_Progress
```

**描述**

| 枚举项 | 描述 |
| -- | -- |
| RDB_SYNC_BEGIN | 表示端云同步过程开始。 |
| RDB_SYNC_IN_PROGRESS | 表示正在端云同步过程中。 |
| RDB_SYNC_FINISH | 表示端云同步过程已完成。 |

### Rdb_ProgressCode

```
enum Rdb_ProgressCode
```

**描述**

| 枚举项 | 描述 |
| -- | -- |
| RDB_SUCCESS | 表示端云同步过程成功。 |
| RDB_UNKNOWN_ERROR | 表示端云同步过程遇到未知错误。 |
| RDB_NETWORK_ERROR | 表示端云同步过程遇到网络错误。 |
| RDB_CLOUD_DISABLED | 表示云端不可用。 |
| RDB_LOCKED_BY_OTHERS | 表示有其他设备正在端云同步，本设备无法进行端云同步。 |
| RDB_RECORD_LIMIT_EXCEEDED | 表示本次端云同步需要同步的条目或大小超出最大值。由云端配置最大值。 |
| RDB_NO_SPACE_FOR_ASSET | 表示云空间剩余空间小于待同步的资产大小。 |


## 函数说明

### OH_Rdb_CreateConfig()

```
OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig()
```

**描述**

创建一个[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)实例，并返回指向该实例的指针。

**起始版本：** 14

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) | 返回一个指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)实例的指针。 |

**参考：**

OH_Rdb_ConfigV2

### OH_Rdb_DestroyConfig()

```
int OH_Rdb_DestroyConfig(OH_Rdb_ConfigV2 *config)
```

**描述**

销毁由[OH_Rdb_CreateConfig](capi-relational-store-h.md#oh_rdb_createconfig)创建的[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetDatabaseDir()

```
int OH_Rdb_SetDatabaseDir(OH_Rdb_ConfigV2 *config, const char *databaseDir)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库文件路径。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| const char *dataBaseDir |  表示数据库文件路径。包含数据库名称在内的全路径长度不超过1024个字符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetStoreName()

```
int OH_Rdb_SetStoreName(OH_Rdb_ConfigV2 *config, const char *storeName)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库名称。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| const char *storeName | 表示数据库名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetBundleName()

```
int OH_Rdb_SetBundleName(OH_Rdb_ConfigV2 *config, const char *bundleName)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置应用包名。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| const char *bundleName | 表示数据库应用包名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetModuleName()

```
int OH_Rdb_SetModuleName(OH_Rdb_ConfigV2 *config, const char *moduleName)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置应用模块名。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| const char *moduleName | 表示数据库应用模块名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetEncrypted()

```
int OH_Rdb_SetEncrypted(OH_Rdb_ConfigV2 *config, bool isEncrypted)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库是否加密。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| bool isEncrypted | 表示数据库是否加密。true表示加密，false表示不加密。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetSecurityLevel()

```
int OH_Rdb_SetSecurityLevel(OH_Rdb_ConfigV2 *config, int securityLevel)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库安全级别[OH_Rdb_SecurityLevel](capi-relational-store-h.md#oh_rdb_securitylevel)。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| int securityLevel | 表示数据库安全级别[OH_Rdb_SecurityLevel](capi-relational-store-h.md#oh_rdb_securitylevel)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetArea()

```
int OH_Rdb_SetArea(OH_Rdb_ConfigV2 *config, int area)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库安全区域等级[Rdb_SecurityArea](capi-relational-store-h.md#rdb_securityarea)。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| int area | 表示数据库安全区域等级[Rdb_SecurityArea](capi-relational-store-h.md#rdb_securityarea)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Rdb_SetDbType()

```
int OH_Rdb_SetDbType(OH_Rdb_ConfigV2 *config, int dbType)
```

**描述**

给指定的数据库文件配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)，设置数据库类型[Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)。

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示指向[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)对象的指针，即与此RDB存储相关的数据库配置。 |
| int dbType | 表示数据库的数据库类型[Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。<br>RDB_E_NOT_SUPPORTED表示不支持当前操作。 |

### OH_Rdb_SetCustomDir()

```
int OH_Rdb_SetCustomDir(OH_Rdb_ConfigV2 *config, const char *customDir)
```

**描述**

设置数据库的自定义目录。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示此关系型数据库相关的数据库配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)的指针。 |
| const char *customDir | 表示数据库的自定义目录，目录长度不能超过128字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行结果。<br>返回RDB_OK表示执行成功。<br>返回RDB_E_INVALID_ARGS表示输入参数无效。 |

### OH_Rdb_SetReadOnly()

```
int OH_Rdb_SetReadOnly(OH_Rdb_ConfigV2 *config, bool readOnly)
```

**描述**

设置关系型数据库是否为只读模式。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示此关系型数据库相关的数据库配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)的指针。 |
| bool readOnly | 表示关系型数据库存储是否为只读模式，true表示设置为只读模式，false表示设置为读写模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行结果。<br>返回RDB_OK表示执行成功。<br>返回RDB_E_INVALID_ARGS表示输入参数无效。 |

### OH_Rdb_SetPlugins()

```
int OH_Rdb_SetPlugins(OH_Rdb_ConfigV2 *config, const char **plugins, int32_t length)
```

**描述**

设置具有特定功能（如全文检索）的动态库。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示此关系型数据库相关的数据库配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)的指针。 |
| const char **plugins | 表示动态库的名称数组。 |
| int32_t length | 表示插件数组的大小，最大值为16。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行结果。<br>返回RDB_OK表示执行成功。<br>返回RDB_E_INVALID_ARGS表示输入参数无效。 |

### OH_Rdb_SetCryptoParam()

```
int OH_Rdb_SetCryptoParam(OH_Rdb_ConfigV2 *config, const OH_Rdb_CryptoParam *cryptoParam)
```

**描述**

设置自定义加密参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md) *config | 表示此关系型数据库相关的数据库配置[OH_Rdb_ConfigV2](capi-oh-rdb-configv2.md)的指针。 |
| const [OH_Rdb_CryptoParam](capi-oh-rdb-cryptoparam.md) *cryptoParam | 表示自定义加密参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回执行结果。<br>返回RDB_OK表示执行成功。<br>返回RDB_E_INVALID_ARGS表示输入参数无效。 |

### OH_Rdb_IsTokenizerSupported()

```
int OH_Rdb_IsTokenizerSupported(Rdb_Tokenizer tokenizer, bool *isSupported)
```

**描述**

判断当前平台是否支持传入的分词器。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Rdb_Tokenizer](#rdb_tokenizer) tokenizer | 要校验是否支持的分词器。 |
| bool *isSupported | 校验结果的指针，作为出参使用。true表示当前平台支持当前校验的分词器，false表示当前平台不支持当前校验的分词器。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回接口操作执行的状态码。<br>RDB_OK表示成功。<br>RDB_E_INVALID_ARGS表示无效参数。 |

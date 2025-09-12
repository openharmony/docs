# relational_store.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Provides APIs for managing data in an RDB store. The APIs not marked as supporting vector stores are available only to RDB stores.

**File to include**: <database/rdb/relational_store.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                                                     | typedef Keyword| Description                                                                     |
|---------------------------------------------------------| -- |-------------------------------------------------------------------------|
| [OH_Rdb_Config](capi-rdb-oh-rdb-config.md)              | - | Defines the configuration of an RDB store.                                                             |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md)                | OH_Rdb_Store | Defines the RDB store type.                                                               |
| [Rdb_DistributedConfig](capi-rdb-rdb-distributedconfig.md) | Rdb_DistributedConfig | Defines a struct for distributed configuration of a table.                                                           |
| [Rdb_KeyInfo](capi-rdb-rdb-keyinfo.md)                      | Rdb_KeyInfo | Defines a struct for the primary key or number of the row that changes.                                                       |
| [Rdb_KeyData](capi-rdb-rdb-keydata.md)                      | - | Holds the changed data.                                                             |
| [Rdb_ChangeInfo](capi-rdb-rdb-changeinfo.md)                | Rdb_ChangeInfo | Defines a struct for the details about the device-cloud sync process.                                                            |
| [Rdb_SubscribeCallback](capi-rdb-rdb-subscribecallback.md)  | Rdb_SubscribeCallback | Defines a callback used to return the subscribed event.                                                                |
| [Rdb_DataObserver](capi-rdb-rdb-dataobserver.md)            | Rdb_DataObserver | Defines a struct for the data observer.                                                               |
| [Rdb_Statistic](capi-rdb-rdb-statistic.md)                  | Rdb_Statistic | Defines a struct for the device-cloud sync statistics of a database table.                                                    |
| [Rdb_TableDetails](capi-rdb-rdb-tabledetails.md)            | Rdb_TableDetails | Defines a struct for statistics of device-cloud upload and download tasks of a database table.                                              |
| [Rdb_ProgressDetails](capi-rdb-rdb-progressdetails.md)      | Rdb_ProgressDetails | Defines a struct for statistics of the overall device-cloud sync (upload and download) tasks of an RDB store.                                             |
| [Rdb_ProgressObserver](capi-rdb-rdb-progressobserver.md)    | Rdb_ProgressObserver | Defines the observer of the device-cloud sync progress.                                                             |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md)          | OH_Rdb_ConfigV2 | Defines a struct for the RDB store configuration. Different from [OH_Rdb_Config](capi-rdb-oh-rdb-config.md), this struct does not expose its member variables externally. Methods are used to configure the properties of this struct. It supports vector stores.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) | OH_Rdb_SecurityLevel | Enumerates the RDB store security levels.|
| [Rdb_SecurityArea](#rdb_securityarea) | Rdb_SecurityArea | Enumerates the encryption levels of database files.|
| [Rdb_DBType](#rdb_dbtype) | Rdb_DBType | Enumerates the database kernel types.|
| [Rdb_Tokenizer](#rdb_tokenizer) | Rdb_Tokenizer | Enumerates the database tokenizer types.|
| [Rdb_DistributedType](#rdb_distributedtype) | Rdb_DistributedType | Enumerates the distributed types.|
| [Rdb_ChangeType](#rdb_changetype) | Rdb_ChangeType | Enumerates the data change types.|
| [Rdb_SubscribeType](#rdb_subscribetype) | Rdb_SubscribeType | Enumerates the subscription types.|
| [Rdb_SyncMode](#rdb_syncmode) | Rdb_SyncMode | Enumerates the RDB sync modes.|
| [Rdb_Progress](#rdb_progress) | Rdb_Progress | Enumerates the device-cloud sync progress states.|
| [Rdb_ProgressCode](#rdb_progresscode) | Rdb_ProgressCode | Enumerates the device-cloud sync states.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig()](#oh_rdb_createconfig) | - | Creates an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_DestroyConfig(OH_Rdb_ConfigV2 *config)](#oh_rdb_destroyconfig) | - | Destroys an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance created by [OH_Rdb_CreateConfig](capi-relational-store-h.md#oh_rdb_createconfig).|
| [int OH_Rdb_SetDatabaseDir(OH_Rdb_ConfigV2 *config, const char *databaseDir)](#oh_rdb_setdatabasedir) | - | Sets the database file path for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetStoreName(OH_Rdb_ConfigV2 *config, const char *storeName)](#oh_rdb_setstorename) | - | Sets the database name for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetBundleName(OH_Rdb_ConfigV2 *config, const char *bundleName)](#oh_rdb_setbundlename) | - | Sets the bundle name for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetModuleName(OH_Rdb_ConfigV2 *config, const char *moduleName)](#oh_rdb_setmodulename) | - | Sets the module name for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetEncrypted(OH_Rdb_ConfigV2 *config, bool isEncrypted)](#oh_rdb_setencrypted) | - | Sets whether to encrypt the database for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetSecurityLevel(OH_Rdb_ConfigV2 *config, int securityLevel)](#oh_rdb_setsecuritylevel) | - | Sets the database security level ([OH_Rdb_SecurityLevel](capi-relational-store-h.md#oh_rdb_securitylevel)) for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetArea(OH_Rdb_ConfigV2 *config, int area)](#oh_rdb_setarea) | - | Sets the security area level ([Rdb_SecurityArea](capi-relational-store-h.md#rdb_securityarea)) for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetDbType(OH_Rdb_ConfigV2 *config, int dbType)](#oh_rdb_setdbtype) | - | Sets the database type ([Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)) for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| [int OH_Rdb_SetCustomDir(OH_Rdb_ConfigV2 *config, const char *customDir)](#oh_rdb_setcustomdir) | - | Sets the custom directory of the database.|
| [int OH_Rdb_SetReadOnly(OH_Rdb_ConfigV2 *config, bool readOnly)](#oh_rdb_setreadonly) | - | Sets whether the RDB store is in read-only mode.|
| [int OH_Rdb_SetPlugins(OH_Rdb_ConfigV2 *config, const char **plugins, int32_t length)](#oh_rdb_setplugins) | - | Sets the dynamic library with specific capabilities (such as full-text search).|
| [int OH_Rdb_SetCryptoParam(OH_Rdb_ConfigV2 *config, const OH_Rdb_CryptoParam *cryptoParam)](#oh_rdb_setcryptoparam) | - | Sets custom encryption parameters.|
| [int OH_Rdb_IsTokenizerSupported(Rdb_Tokenizer tokenizer, bool *isSupported)](#oh_rdb_istokenizersupported) | - | Checks whether the specified tokenizer is supported.|
| [int OH_Rdb_SetTokenizer(OH_Rdb_ConfigV2 *config, Rdb_Tokenizer tokenizer)](#oh_rdb_settokenizer) | - | Sets the tokenizer type.|
| [int OH_Rdb_SetPersistent(OH_Rdb_ConfigV2 *config, bool isPersistent)](#oh_rdb_setpersistent) | - | Sets whether to persist an RDB store.|
| [const int *OH_Rdb_GetSupportedDbType(int *typeCount)](#oh_rdb_getsupporteddbtype) | - | Obtains the supported database type ([Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)).|
| [OH_VObject *OH_Rdb_CreateValueObject()](#oh_rdb_createvalueobject) | - | Creates an [OH_VObject](capi-rdb-oh-vobject.md) instance.|
| [OH_VBucket *OH_Rdb_CreateValuesBucket()](#oh_rdb_createvaluesbucket) | - | Creates an [OH_VBucket](capi-rdb-oh-vbucket.md) instance.|
| [OH_Predicates *OH_Rdb_CreatePredicates(const char *table)](#oh_rdb_createpredicates) | - | Creates an [OH_Predicates](capi-rdb-oh-predicates.md) instance.|
| [OH_Rdb_Store *OH_Rdb_GetOrOpen(const OH_Rdb_Config *config, int *errCode)](#oh_rdb_getoropen) | - | Obtains a related [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance to operate the RDB store.|
| [OH_Rdb_Store *OH_Rdb_CreateOrOpen(const OH_Rdb_ConfigV2 *config, int *errCode)](#oh_rdb_createoropen) | - | Creates or opens an [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance based on the given [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md).|
| [int OH_Rdb_CloseStore(OH_Rdb_Store *store)](#oh_rdb_closestore) | - | Closes an [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) object and reclaims the memory occupied by the object.|
| [int OH_Rdb_DeleteStore(const OH_Rdb_Config *config)](#oh_rdb_deletestore) | - | Deletes a graph store.|
| [int OH_Rdb_DeleteStoreV2(const OH_Rdb_ConfigV2 *config)](#oh_rdb_deletestorev2) | - | Deletes an RDB store based on the given [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md).<br>Before calling **DeleteStoreV2**, ensure that the **OH_Rdb_Store** and **OH_Cursor** of the vector store have been closed.|
| [int OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket)](#oh_rdb_insert) | - | Inserts a row of data into a table.|
| [int OH_Rdb_InsertWithConflictResolution(OH_Rdb_Store *store, const char *table, OH_VBucket *row,Rdb_ConflictResolution resolution, int64_t *rowId)](#oh_rdb_insertwithconflictresolution) | - | Inserts a row of data into the target table and supports conflict resolution.|
| [int OH_Rdb_BatchInsert(OH_Rdb_Store *store, const char *table,const OH_Data_VBuckets *rows, Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdb_batchinsert) | - | Inserts a batch of data into a table.|
| [int OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates)](#oh_rdb_update) | - | Updates data in an RDB store based on specified conditions.|
| [int OH_Rdb_UpdateWithConflictResolution(OH_Rdb_Store *store, OH_VBucket *row, OH_Predicates *predicates,Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdb_updatewithconflictresolution) | - | Updates data in the database based on specified conditions and supports conflict resolution.|
| [int OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates)](#oh_rdb_delete) | - | Deletes data from an RDB store based on specified conditions.|
| [OH_Cursor *OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length)](#oh_rdb_query) | - | Queries data in an RDB store based on specified conditions.|
| [int OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql)](#oh_rdb_execute) | - | Executes an SQL statement that returns no value.|
| [int OH_Rdb_ExecuteV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args, OH_Data_Value **result)](#oh_rdb_executev2) | - | Executes an SQL statement with a return value. This API supports vector stores.|
| [int OH_Rdb_ExecuteByTrxId(OH_Rdb_Store *store, int64_t trxId, const char *sql)](#oh_rdb_executebytrxid) | - | Executes an SQL statement that returns no value based on the specified transaction ID. This API supports only vector stores.|
| [OH_Cursor *OH_Rdb_ExecuteQuery(OH_Rdb_Store *store, const char *sql)](#oh_rdb_executequery) | - | Queries data in the database using the specified SQL statement. This API supports vector stores.|
| [OH_Cursor *OH_Rdb_ExecuteQueryV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args)](#oh_rdb_executequeryv2) | - | Queries data in the database using the specified SQL statement. This API supports vector stores.|
| [int OH_Rdb_BeginTransaction(OH_Rdb_Store *store)](#oh_rdb_begintransaction) | - | Begins the transaction before executing SQL statements.|
| [int OH_Rdb_RollBack(OH_Rdb_Store *store)](#oh_rdb_rollback) | - | Rolls back the SQL statements executed.|
| [int OH_Rdb_Commit(OH_Rdb_Store *store)](#oh_rdb_commit) | - | Commits the executed SQL statements.|
| [int OH_Rdb_BeginTransWithTrxId(OH_Rdb_Store *store, int64_t *trxId)](#oh_rdb_begintranswithtrxid) | - | Begins a transaction. This API returns a transaction ID API and supports only vector stores.|
| [int OH_Rdb_RollBackByTrxId(OH_Rdb_Store *store, int64_t trxId)](#oh_rdb_rollbackbytrxid) | - | Rolls back the executed SQL statements based on the specified transaction ID. This API supports only vector stores.|
| [int OH_Rdb_CommitByTrxId(OH_Rdb_Store *store, int64_t trxId)](#oh_rdb_commitbytrxid) | - | Commits the executed SQL statements based on the specified transaction ID. This API supports only vector stores.|
| [int OH_Rdb_Backup(OH_Rdb_Store *store, const char *databasePath)](#oh_rdb_backup) | - | Backs up an RDB store using the backup file of the specified path. This API supports vector stores.|
| [int OH_Rdb_Restore(OH_Rdb_Store *store, const char *databasePath)](#oh_rdb_restore) | - | Restores a database from a specified database backup file. This API supports vector stores.|
| [int OH_Rdb_GetVersion(OH_Rdb_Store *store, int *version)](#oh_rdb_getversion) | - | Obtains the RDB store version.|
| [int OH_Rdb_SetVersion(OH_Rdb_Store *store, int version)](#oh_rdb_setversion) | - | Sets the RDB store version.|
| [int OH_Rdb_SetDistributedTables(OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type,const Rdb_DistributedConfig *config)](#oh_rdb_setdistributedtables) | - | Sets distributed database tables.|
| [OH_Cursor *OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName,OH_VObject *values)](#oh_rdb_findmodifytime) | - | Obtains the last modification time of a table in an RDB store.|
| [typedef void (\*Rdb_BriefObserver)(void *context, const char *values[], uint32_t count)](#rdb_briefobserver) | Rdb_BriefObserver | Defines a callback used to return the device-cloud data change event.|
| [typedef void (\*Rdb_DetailsObserver)(void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)](#rdb_detailsobserver) | Rdb_DetailsObserver | Defines a callback used to return the details about the device-cloud data change.|
| [int OH_Rdb_Subscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer)](#oh_rdb_subscribe) | - | Registers an observer for an RDB store. The registered callback will be invoked when data in a distributed or local RDB store changes.|
| [int OH_Rdb_Unsubscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer)](#oh_rdb_unsubscribe) | - | Unregisters the observer of the specified type.|
| [Rdb_TableDetails *OH_Rdb_GetTableDetails(Rdb_ProgressDetails *progress, int32_t version)](#oh_rdb_gettabledetails) | - | Obtains the device-cloud sync statistics of a table.|
| [typedef void (\*Rdb_ProgressCallback)(void *context, Rdb_ProgressDetails *progressDetails)](#rdb_progresscallback) | Rdb_ProgressCallback | Defines a callback used to return the device-cloud sync progress.|
| [typedef void (\*Rdb_SyncCallback)(Rdb_ProgressDetails *progressDetails)](#rdb_synccallback) | Rdb_SyncCallback | Defines a callback for device-cloud sync.|
| [int OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count,const Rdb_ProgressObserver *observer)](#oh_rdb_cloudsync) | - | Performs device-cloud sync.|
| [int OH_Rdb_SubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer)](#oh_rdb_subscribeautosyncprogress) | - | Subscribes to the auto sync progress of an RDB store.<br>The registered callback will be invoked to return the auto sync progress.|
| [int OH_Rdb_UnsubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer)](#oh_rdb_unsubscribeautosyncprogress) | - | Unsubscribes from the auto sync process of an RDB store.|
| [int OH_Rdb_LockRow(OH_Rdb_Store *store, OH_Predicates *predicates)](#oh_rdb_lockrow) | - | Locks data in an RDB store based on specified conditions. The locked data will be blocked from the device-cloud sync.|
| [int OH_Rdb_UnlockRow(OH_Rdb_Store *store, OH_Predicates *predicates)](#oh_rdb_unlockrow) | - | Unlocks data in an RDB store based on the specified conditions.|
| [OH_Cursor *OH_Rdb_QueryLockedRow(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length)](#oh_rdb_querylockedrow) | - | Queries the locked data in an RDB store.|
| [int OH_Rdb_CreateTransaction(OH_Rdb_Store *store, const OH_RDB_TransOptions *options, OH_Rdb_Transaction **trans)](#oh_rdb_createtransaction) | - | Creates a transaction object.|
| [int OH_Rdb_Attach(OH_Rdb_Store *store, const OH_Rdb_ConfigV2 *config, const char *attachName, int64_t waitTime,size_t *attachedNumber)](#oh_rdb_attach) | - | Attaches a database file to the database that is currently connected.|
| [int OH_Rdb_Detach(OH_Rdb_Store *store, const char *attachName, int64_t waitTime, size_t *attachedNumber)](#oh_rdb_detach) | - | Detaches a specified store from the current database.|
| [int OH_Rdb_SetLocale(OH_Rdb_Store *store, const char *locale)](#oh_rdb_setlocale) | - | Sets locale.|
| [int OH_Rdb_SetSemanticIndex(OH_Rdb_ConfigV2 *config, bool enabled)](#oh_rdb_setsemanticindex) | - | Sets whether to enable knowledge processing based on semantic indexes.|

## Enum Description

### OH_Rdb_SecurityLevel

```
enum OH_Rdb_SecurityLevel
```

**Description**

Enumerates the RDB store security levels.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| S1 = 1 | Low security level. If data leakage occurs, minor impact will be caused.|
| S2 | Medium security level. If data leakage occurs, moderate impact will be caused.|
| S3 | High security level. If data leakage occurs, major impact will be caused.|
| S4 | Critical security level. If data leakage occurs, critical impact will be caused.|

### Rdb_SecurityArea

```
enum Rdb_SecurityArea
```

**Description**

Enumerates the encryption levels of database files.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| RDB_SECURITY_AREA_EL1 = 1 | Encryption level 1.|
| RDB_SECURITY_AREA_EL2 | Encryption level 2.|
| RDB_SECURITY_AREA_EL3 | Encryption level 3.|
| RDB_SECURITY_AREA_EL4 | Encryption level 4.|
| RDB_SECURITY_AREA_EL5 | Encryption level 5.<br>**Since**: 12|

### Rdb_DBType

```
enum Rdb_DBType
```

**Description**

Enumerates the database kernel types.

**Since**: 14

| Enum Item| Description|
| -- | -- |
| RDB_SQLITE = 1 | SQLite is used as the database kernel.|
| RDB_CAYLEY = 2 | Cayley is used as the database kernel.|
| DBTYPE_BUTT = 64 | Maximum value of the database kernel type, which is an invalid value.|

### Rdb_Tokenizer

```
enum Rdb_Tokenizer
```

**Description**

Enumerates the database tokenizer types.

**Since**: 17

| Enum Item| Description|
| -- | -- |
| RDB_NONE_TOKENIZER = 1 | No tokenizer is used.|
| RDB_ICU_TOKENIZER = 2 | ICU tokenizer.|
| RDB_CUSTOM_TOKENIZER = 3 | Custom tokenizer.	<br>**Since**: 18|

### Rdb_DistributedType

```
enum Rdb_DistributedType
```

**Description**

Enumerates the distributed types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| RDB_DISTRIBUTED_CLOUD | Distributed database tables for device-cloud sync.|

### Rdb_ChangeType

```
enum Rdb_ChangeType
```

**Description**

Enumerates the data change types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| RDB_DATA_CHANGE | Data change.|
| RDB_ASSET_CHANGE | Asset change.|

### Rdb_SubscribeType

```
enum Rdb_SubscribeType
```

**Description**

Enumerates the subscription types.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| RDB_SUBSCRIBE_TYPE_CLOUD | Subscribe to cloud data changes.|
| RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS | Subscribe to details of the cloud data change.|
| RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS | Subscribe to details of the local data change.|

### Rdb_SyncMode

```
enum Rdb_SyncMode
```

**Description**

Enumerates the RDB sync modes.

**Since**: 11

| Enum Item| Description|
| -- | -- |
| RDB_SYNC_MODE_TIME_FIRST | Synchronize with the data with the latest modification time.|
| RDB_SYNC_MODE_NATIVE_FIRST | Synchronize data from a local device to the cloud.|
| RDB_SYNC_MODE_CLOUD_FIRST | Synchronize data from the cloud to a local device.|

### Rdb_Progress

```
enum Rdb_Progress
```

**Description**

| Enum Item| Description|
| -- | -- |
| RDB_SYNC_BEGIN | The device-cloud sync starts.|
| RDB_SYNC_IN_PROGRESS | The device-cloud sync is in progress.|
| RDB_SYNC_FINISH | The device-cloud sync is finished.|

### Rdb_ProgressCode

```
enum Rdb_ProgressCode
```

**Description**

| Enum Item| Description|
| -- | -- |
| RDB_SUCCESS | The device-cloud sync is successful.|
| RDB_UNKNOWN_ERROR | An unknown error occurs during the device-cloud sync.|
| RDB_NETWORK_ERROR | A network error occurs during the device-cloud sync.|
| RDB_CLOUD_DISABLED | The cloud is unavailable.|
| RDB_LOCKED_BY_OTHERS | The device-cloud sync of another device is being performed.|
| RDB_RECORD_LIMIT_EXCEEDED | The number of records or size of the data to be synced exceeds the maximum. The maximum value is configured on the cloud.|
| RDB_NO_SPACE_FOR_ASSET | The remaining cloud space is less than the size of the data to be synced.|


## Function Description

### OH_Rdb_SetSemanticIndex()

```
int OH_Rdb_SetSemanticIndex(OH_Rdb_ConfigV2 *config, bool enabled)
```

**Description**

Sets whether to enable knowledge processing based on semantic indexes.

**Since**: 20

**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| bool enabled | Whether to enable knowledge processing based on semantic indexes.<br>The value **true** indicates that the function is enabled; the value **false** indicates the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns an error code. For details about the error code, see [OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode).<br>**ERR_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_CreateConfig()

```
OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig()
```

**Description**

Creates an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14

**Returns**

| Type| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|

**See**

OH_Rdb_ConfigV2

### OH_Rdb_DestroyConfig()

```
int OH_Rdb_DestroyConfig(OH_Rdb_ConfigV2 *config)
```

**Description**

Destroys an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance created by [OH_Rdb_CreateConfig](capi-relational-store-h.md#oh_rdb_createconfig).

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetDatabaseDir()

```
int OH_Rdb_SetDatabaseDir(OH_Rdb_ConfigV2 *config, const char *databaseDir)
```

**Description**

Sets the database file path for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| const char *dataBaseDir |  Pointer to the database file path to set. The full path, including the RDB store name, cannot exceed a maximum of 1024 characters.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetStoreName()

```
int OH_Rdb_SetStoreName(OH_Rdb_ConfigV2 *config, const char *storeName)
```

**Description**

Sets the database name for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| const char *storeName | Pointer to the RDB store name to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetBundleName()

```
int OH_Rdb_SetBundleName(OH_Rdb_ConfigV2 *config, const char *bundleName)
```

**Description**

Sets the bundle name for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| const char *bundleName | Pointer to the application bundle name to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetModuleName()

```
int OH_Rdb_SetModuleName(OH_Rdb_ConfigV2 *config, const char *moduleName)
```

**Description**

Sets the module name for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| const char *moduleName | Pointer to the module name to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetEncrypted()

```
int OH_Rdb_SetEncrypted(OH_Rdb_ConfigV2 *config, bool isEncrypted)
```

**Description**

Sets whether to encrypt the database for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| bool isEncrypted | Whether to encrypt the RDB store. The value **true** means to encrypt the database; the value **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetSecurityLevel()

```
int OH_Rdb_SetSecurityLevel(OH_Rdb_ConfigV2 *config, int securityLevel)
```

**Description**

Sets the database security level ([OH_Rdb_SecurityLevel](capi-relational-store-h.md#oh_rdb_securitylevel)) for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| int securityLevel | Database security level ([OH_Rdb_SecurityLevel](capi-relational-store-h.md#oh_rdb_securitylevel)).|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetArea()

```
int OH_Rdb_SetArea(OH_Rdb_ConfigV2 *config, int area)
```

**Description**

Sets the security area level ([Rdb_SecurityArea](capi-relational-store-h.md#rdb_securityarea)) for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| int area | Database security area level ([Rdb_SecurityArea](capi-relational-store-h.md#rdb_securityarea)).|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetDbType()

```
int OH_Rdb_SetDbType(OH_Rdb_ConfigV2 *config, int dbType)
```

**Description**

Sets the database type ([Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)) for an [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| int dbType | Database type ([Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)).|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.|

### OH_Rdb_SetCustomDir()

```
int OH_Rdb_SetCustomDir(OH_Rdb_ConfigV2 *config, const char *customDir)
```

**Description**

Sets the custom directory of the database.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| const char *customDir | Custom directory of the database, with a maximum length of 128 bytes.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetReadOnly()

```
int OH_Rdb_SetReadOnly(OH_Rdb_ConfigV2 *config, bool readOnly)
```

**Description**

Sets whether the RDB store is in read-only mode.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| bool readOnly | Whether the RDB store is in read-only mode. The value **true** indicates that the RDB store is in read-only mode; the value **false** indicates that the RDB store is in read/write mode.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetPlugins()

```
int OH_Rdb_SetPlugins(OH_Rdb_ConfigV2 *config, const char **plugins, int32_t length)
```

**Description**

Sets the dynamic library with specific capabilities (such as full-text search).

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| const char **plugins | Name array of the dynamic library.|
| int32_t length | Size of the plugin array. The maximum value is **16**.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetCryptoParam()

```
int OH_Rdb_SetCryptoParam(OH_Rdb_ConfigV2 *config, const OH_Rdb_CryptoParam *cryptoParam)
```

**Description**

Sets custom encryption parameters.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| const [OH_Rdb_CryptoParam](capi-rdb-oh-rdb-cryptoparam.md) *cryptoParam | Custom encryption parameters.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_IsTokenizerSupported()

```
int OH_Rdb_IsTokenizerSupported(Rdb_Tokenizer tokenizer, bool *isSupported)
```

**Description**

Checks whether the specified tokenizer is supported.

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [Rdb_Tokenizer](#rdb_tokenizer) tokenizer | Tokenizer to check.|
| bool *isSupported | Pointer to the check result. The value **true** means the tokenizer is supported; the value **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns operation status code.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetTokenizer()

```
int OH_Rdb_SetTokenizer(OH_Rdb_ConfigV2 *config, Rdb_Tokenizer tokenizer)
```

**Description**

Sets the tokenizer type.

**Since**: 17


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the target database configuration.|
| [Rdb_Tokenizer](#rdb_tokenizer) tokenizer | Tokenizer type to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns operation status code.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.|

### OH_Rdb_SetPersistent()

```
int OH_Rdb_SetPersistent(OH_Rdb_ConfigV2 *config, bool isPersistent)
```

**Description**

Sets whether to persist an RDB store.

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.<br>which specifies the database configuration.|
| bool isPersistent | Whether to persist the database data.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns operation status code.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_GetSupportedDbType()

```
const int *OH_Rdb_GetSupportedDbType(int *typeCount)
```

**Description**

Obtains the supported database type ([Rdb_DBType](capi-relational-store-h.md#rdb_dbtype)).

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| int *typeCount | Pointer to the length of the array of the supported database types obtained.|

**Returns**

| Type        | Description|
|------------| -- |
| const int * | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_CreateValueObject()

```
OH_VObject *OH_Rdb_CreateValueObject()
```

**Description**

Creates an [OH_VObject](capi-rdb-oh-vobject.md) instance.

**Since**: 10

**Returns**

| Type| Description|
| -- | -- |
| [OH_VObject](capi-rdb-oh-vobject.md) | Returns the pointer to the [OH_VObject](capi-rdb-oh-vobject.md) instance created if the operation is successful; returns null otherwise.|

**See**

OH_VObject

### OH_Rdb_CreateValuesBucket()

```
OH_VBucket *OH_Rdb_CreateValuesBucket()
```

**Description**

Creates an [OH_VBucket](capi-rdb-oh-vbucket.md) instance.

**Since**: 10

**Returns**

| Type| Description|
| -- | -- |
| [OH_VBucket](capi-rdb-oh-vbucket.md) | Returns the pointer to the [OH_VBucket](capi-rdb-oh-vbucket.md) instance created if the operation is successful; returns null otherwise.|

**See**

OH_VBucket

### OH_Rdb_CreatePredicates()

```
OH_Predicates *OH_Rdb_CreatePredicates(const char *table)
```

**Description**

Creates an [OH_Predicates](capi-rdb-oh-predicates.md) instance.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| const char *table | Pointer to the name of the database table.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Predicates](capi-rdb-oh-predicates.md) | Returns the pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance created if the operation is successful; returns null otherwise.|

**See**

OH_Predicates

### OH_Rdb_GetOrOpen()

```
OH_Rdb_Store *OH_Rdb_GetOrOpen(const OH_Rdb_Config *config, int *errCode)
```

**Description**

Obtains a related [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance to operate the RDB store.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| const [OH_Rdb_Config](capi-rdb-oh-rdb-config.md) *config | Pointer to the [OH_Rdb_Config](capi-rdb-oh-rdb-config.md) instance, which is the configuration of the RDB store.|
| int *errCode | Pointer to the execution result of this API.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) | Returns the pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance created if the operation is successful; returns null otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_CreateOrOpen()

```
OH_Rdb_Store *OH_Rdb_CreateOrOpen(const OH_Rdb_ConfigV2 *config, int *errCode)
```

**Description**

Creates or opens an [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance based on the given [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md).

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance, which is the configuration of the RDB store.|
| int *errCode | Pointer to the execution result of this API.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) | Returns the pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance created if the operation is successful; returns null otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_CloseStore()

```
int OH_Rdb_CloseStore(OH_Rdb_Store *store)
```

**Description**

Closes an [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) object and reclaims the memory occupied by the object.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_DeleteStore()

```
int OH_Rdb_DeleteStore(const OH_Rdb_Config *config)
```

**Description**

Deletes an RDB store with the specified configuration.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| const [OH_Rdb_Config](capi-rdb-oh-rdb-config.md) *config | Pointer to the database configuration.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_DeleteStoreV2()

```
int OH_Rdb_DeleteStoreV2(const OH_Rdb_ConfigV2 *config)
```

**Description**

Deletes an RDB store based on the given [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md).<br>Before calling **DeleteStoreV2**, ensure that the **OH_Rdb_Store** and **OH_Cursor** of the vector store have been closed.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the database configuration.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_Insert()

```
int OH_Rdb_Insert(OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket)
```

**Description**

Inserts a row of data into a table.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *table | Pointer to the target table.|
| [OH_VBucket](capi-rdb-oh-vbucket.md) *valuesBucket | Pointer to the data [OH_VBucket](capi-rdb-oh-vbucket.md) to insert.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **rowID** if the operation is successful; returns a number less than **0** otherwise.<br>**RDB_ERR** indicates that the operation fails.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_InsertWithConflictResolution()

```
int OH_Rdb_InsertWithConflictResolution(OH_Rdb_Store *store, const char *table, OH_VBucket *row,Rdb_ConflictResolution resolution, int64_t *rowId)
```

**Description**

Inserts a row of data into the target table and supports conflict resolution.

**Since**: 20


**Parameters**

| Parameter                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store                                        | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *table                                                                  | Name of the target table.|
| [OH_VBucket](capi-rdb-oh-vbucket.md) *row                                              | Pointer to the row of data to insert.|
| [Rdb_ConflictResolution](capi-oh-rdb-types-h.md#rdb_conflictresolution) resolution | Policy used to resolve file conflicts.|
| int64_t *rowId                                                                     | Pointer to the row number returned.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_Rdb_BatchInsert()

```
int OH_Rdb_BatchInsert(OH_Rdb_Store *store, const char *table,const OH_Data_VBuckets *rows, Rdb_ConflictResolution resolution, int64_t *changes)
```

**Description**

Inserts a batch of data into a table.

**Since**: 18


**Parameters**

| Parameter                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store                                        | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *tables                                                                 |  Pointer to the names of the distributed tables to set.|
| const [OH_Data_VBuckets *rows](capi-rdb-oh-data-vbuckets.md)                           | An array of data to insert.|
| [Rdb_ConflictResolution](capi-oh-rdb-types-h.md#rdb_conflictresolution) resolution | Policy used to resolve file conflicts.|
| int64_t *changes                                                                   | Pointer to the number of successful insertions.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_Rdb_Update()

```
int OH_Rdb_Update(OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates)
```

**Description**

Updates data in an RDB store based on specified conditions.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [OH_VBucket](capi-rdb-oh-vbucket.md) *valuesBucket | Pointer to the data [OH_VBucket](capi-rdb-oh-vbucket.md) to update.|
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the update conditions.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the number of updated rows if the operation is successful; returns a number less than **0** otherwise.<br>**RDB_ERR** indicates that the operation fails.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_UpdateWithConflictResolution()

```
int OH_Rdb_UpdateWithConflictResolution(OH_Rdb_Store *store, OH_VBucket *row, OH_Predicates *predicates,Rdb_ConflictResolution resolution, int64_t *changes)
```

**Description**

Updates data in the database based on specified conditions and supports conflict resolution.

**Since**: 20


**Parameters**

| Parameter                                                                               | Description|
|------------------------------------------------------------------------------------| -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store                                        | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [OH_VBucket](capi-rdb-oh-vbucket.md) *row                                              | Pointer to the row of data to update.|
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates                                 | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the update conditions.|
| [Rdb_ConflictResolution](capi-oh-rdb-types-h.md#rdb_conflictresolution) resolution | Policy used to resolve file conflicts.|
| int64_t *changes                                                                   | Pointer to the number of rows that are successfully updated.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_Rdb_Delete()

```
int OH_Rdb_Delete(OH_Rdb_Store *store, OH_Predicates *predicates)
```

**Description**

Deletes data from an RDB store based on specified conditions.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the deletion conditions.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the number of deleted rows if the operation is successful; returns a number less than **0** otherwise.<br>**RDB_ERR** indicates that the operation fails.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_Query()

```
OH_Cursor *OH_Rdb_Query(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length)
```

**Description**

Queries data in an RDB store based on specified conditions.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the query conditions.|
| const char *const *columnNames | Columns to query. If this parameter is not specified, the query applies to all columns.|
| int length | Length of **columnNames**. If **length** is greater than the length of **columnNames** array, out-of-bounds access occurs.|

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| [OH_Cursor](capi-rdb-oh-cursor.md) * | Returns the pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance if the operation is successful; returns null otherwise.|

### OH_Rdb_Execute()

```
int OH_Rdb_Execute(OH_Rdb_Store *store, const char *sql)
```

**Description**

Executes an SQL statement that returns no value.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *sql | SQL statement to run.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

**See**

OH_Rdb_Store

### OH_Rdb_ExecuteV2()

```
int OH_Rdb_ExecuteV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args, OH_Data_Value **result)
```

**Description**

Executes an SQL statement with a return value. This API supports vector stores.

**Since**: 18


**Parameters**

| Parameter                                                 | Description                                                                                                                                     |
|------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store          | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.                                                                                         |
| const char *sql                                      | SQL statement to run.                                                                                                                           |
| const [OH_Data_Values](capi-rdb-oh-data-values.md) *args | (Optional) Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.                                                                                                  |
| [OH_Data_Value](capi-rdb-oh-data-value.md) **result                           | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance when the execution is successful. Use [OH_Value_Destroy](capi-oh-data-value-h.md#oh_value_destroy) to release the memory in time.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.|

**See**

OH_Value_Destroy

### OH_Rdb_ExecuteByTrxId()

```
int OH_Rdb_ExecuteByTrxId(OH_Rdb_Store *store, int64_t trxId, const char *sql)
```

**Description**

Executes an SQL statement that returns no value based on the specified transaction ID. This API supports only vector stores.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| int64_t trxId | Transaction ID returned by [OH_Rdb_BeginTransWithTrxId](capi-relational-store-h.md#oh_rdb_begintranswithtrxid). The value **0** indicates that no transaction is enabled.|
| const char *sql | SQL statement to run.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters. The possible causes are as follows:<br>The input parameter is a null pointer.<br>The current transaction ID is not obtained by calling [OH_Rdb_BeginTransWithTrxId](capi-relational-store-h.md#oh_rdb_begintranswithtrxid).<br>The current transaction ID has been submitted by calling [OH_Rdb_CommitByTrxId](capi-relational-store-h.md#oh_rdb_commitbytrxid).<br>The current transaction ID has been rolled back by calling [OH_Rdb_RollBackByTrxId](capi-relational-store-h.md#oh_rdb_rollbackbytrxid).<br>**store** or **sql** is **NULL**.<br>**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.|

**See**

OH_Rdb_Store

### OH_Rdb_ExecuteQuery()

```
OH_Cursor *OH_Rdb_ExecuteQuery(OH_Rdb_Store *store, const char *sql)
```

**Description**

Queries data in the database using the specified SQL statement. This API supports vector stores.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *sql | SQL statement to run.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Cursor](capi-rdb-oh-cursor.md) | Returns the pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance if the operation is successful; returns null otherwise.|

**See**

OH_Rdb_Store

### OH_Rdb_ExecuteQueryV2()

```
OH_Cursor *OH_Rdb_ExecuteQueryV2(OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args)
```

**Description**

Queries data in the database using the specified SQL statement. This API supports vector stores.

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *sql | SQL statement to run.|
| const OH_Data_Values *args | (Optional) Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|

**Returns**

| Type                            | Description                                                        |
| -------------------------------- | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) * | Returns a pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance if the operation is successful. The [OH_Cursor](capi-rdb-oh-cursor.md) instance is released if it is no longer required in time.<br>Returns **NULL** if the SQL statement is invalid or the memory allocation fails.|

**See**

OH_Rdb_Store

### OH_Rdb_BeginTransaction()

```
int OH_Rdb_BeginTransaction(OH_Rdb_Store *store)
```

**Description**

Begins the transaction before executing SQL statements.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_RollBack()

```
int OH_Rdb_RollBack(OH_Rdb_Store *store)
```

**Description**

Rolls back the SQL statements executed.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_Commit()

```
int OH_Rdb_Commit(OH_Rdb_Store *store)
```

**Description**

Commits the executed SQL statement.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_BeginTransWithTrxId()

```
int OH_Rdb_BeginTransWithTrxId(OH_Rdb_Store *store, int64_t *trxId)
```

**Description**

Begins a transaction. This API returns a transaction ID and supports only vector stores.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| int64_t *trxId | Pointer to the transaction ID returned.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.|

### OH_Rdb_RollBackByTrxId()

```
int OH_Rdb_RollBackByTrxId(OH_Rdb_Store *store, int64_t trxId)
```

**Description**

Rolls back the executed SQL statements based on the specified transaction ID. This API supports only vector stores.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| int64_t trxId | ID of the transaction to be rolled back.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters. The possible causes are as follows:<br>The input parameter is a null pointer.<br>The current transaction ID is not obtained by calling [OH_Rdb_BeginTransWithTrxId](capi-relational-store-h.md#oh_rdb_begintranswithtrxid).<br>The current transaction ID has been submitted by calling [OH_Rdb_CommitByTrxId](capi-relational-store-h.md#oh_rdb_commitbytrxid).<br>The current transaction ID has been rolled back by calling [OH_Rdb_RollBackByTrxId](capi-relational-store-h.md#oh_rdb_rollbackbytrxid).<br>**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.|

### OH_Rdb_CommitByTrxId()

```
int OH_Rdb_CommitByTrxId(OH_Rdb_Store *store, int64_t trxId)
```

**Description**

Commits the executed SQL statements based on the specified transaction ID. This API supports only vector stores.

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| int64_t trxId | Transaction ID.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters. The possible causes are as follows:<br>The input parameter is a null pointer.<br>The current transaction ID is not obtained by calling [OH_Rdb_BeginTransWithTrxId](capi-relational-store-h.md#oh_rdb_begintranswithtrxid).<br>The current transaction ID has been submitted by calling [OH_Rdb_CommitByTrxId](capi-relational-store-h.md#oh_rdb_commitbytrxid).<br>The current transaction ID has been rolled back by calling [OH_Rdb_RollBackByTrxId](capi-relational-store-h.md#oh_rdb_rollbackbytrxid).<br>**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.|

**See**

OH_Rdb_Store

### OH_Rdb_Backup()

```
int OH_Rdb_Backup(OH_Rdb_Store *store, const char *databasePath)
```

**Description**

Backs up an RDB store using the backup file of the specified path. This API supports vector stores.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *databasePath | Pointer to the destination directory in which the RDB store is backed up.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

**See**

OH_Rdb_Store

### OH_Rdb_Restore()

```
int OH_Rdb_Restore(OH_Rdb_Store *store, const char *databasePath)
```

**Description**

Restores a database from a specified database backup file. This API supports vector stores.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *databasePath | Pointer to the destination directory in which the RDB store is backed up.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_GetVersion()

```
int OH_Rdb_GetVersion(OH_Rdb_Store *store, int *version)
```

**Description**

Obtains the RDB store version.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| int *version | Pointer to the version number.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SetVersion()

```
int OH_Rdb_SetVersion(OH_Rdb_Store *store, int version)
```

**Description**

Sets the RDB store version.

**Since**: 10


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| int version | Version to set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

**See**

OH_Rdb_Store

### OH_Rdb_SetDistributedTables()

```
int OH_Rdb_SetDistributedTables(OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type,const Rdb_DistributedConfig *config)
```

**Description**

Sets distributed database tables.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *tables[] |  Pointer to the names of the distributed tables to set.|
| uint32_t count | Number of distributed database tables to be set.|
| [Rdb_DistributedType](#rdb_distributedtype) type | [Rdb_DistributedType](capi-relational-store-h.md#rdb_distributedtype) of the table.|
| const [Rdb_DistributedConfig](capi-rdb-rdb-distributedconfig.md) *config | Distributed configuration information of a table ([Rdb_DistributedConfig](capi-rdb-rdb-distributedconfig.md)).|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

**See**

OH_Rdb_Store

### OH_Rdb_FindModifyTime()

```
OH_Cursor *OH_Rdb_FindModifyTime(OH_Rdb_Store *store, const char *tableName, const char *columnName,OH_VObject *values)
```

**Description**

Obtains the last modification time of a table in an RDB store.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *tableName | Pointer to the target distributed database table name.|
| const char *columnName | Pointer to the column name of the database table to query.|
| [OH_VObject](capi-rdb-oh-vobject.md) *values | Pointer to the primary keys of the rows to query. If the database table has no primary key, **rowid** must be passed in through **columnName**. In this case, **values** specifies the row number of the database table to query.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Cursor](capi-rdb-oh-cursor.md) | Returns the pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance created if the operation is successful; returns null otherwise.|

### Rdb_BriefObserver()

```
typedef void (*Rdb_BriefObserver)(void *context, const char *values[], uint32_t count)
```

**Description**

Callback used to return the device-cloud data change event.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| void *context | Pointer to the context of the data observer.|
| const char *values[] |  Pointer to the accounts whose device-cloud data is changed.|
| uint32_t count | Number of accounts whose device-cloud data is changed.|

### Rdb_DetailsObserver()

```
typedef void (*Rdb_DetailsObserver)(void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)
```

**Description**

Callback used to return the details about the device-cloud data change.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| void *context | Pointer to the context of the data observer.|
|  const [Rdb_ChangeInfo](capi-rdb-rdb-changeinfo.md) **changeInfo | Information about the changed table ([Rdb_ChangeInfo](capi-rdb-rdb-changeinfo.md)).|
|  uint32_t count | Number of changed tables.|

### OH_Rdb_Subscribe()

```
int OH_Rdb_Subscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer)
```

**Description**

Registers an observer for an RDB store. The registered callback will be called when data in a distributed or local RDB store changes.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [Rdb_SubscribeType](#rdb_subscribetype) type | Subscription type ([Rdb_SubscribeType](capi-relational-store-h.md#rdb_subscribetype)). If the value is **RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS**, the callback is called when the data in the local RDB store changes.|
| const [Rdb_DataObserver](capi-rdb-rdb-dataobserver.md) *observer | Pointer to the [Rdb_DataObserver](capi-rdb-rdb-dataobserver.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_Unsubscribe()

```
int OH_Rdb_Unsubscribe(OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer)
```

**Description**

Unregisters the observer of the specified type.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [Rdb_SubscribeType](#rdb_subscribetype) type | Subscription type ([Rdb_SubscribeType](capi-relational-store-h.md#rdb_subscribetype)).|
| const [Rdb_DataObserver](capi-rdb-rdb-dataobserver.md) *observer | Pointer to the [Rdb_DataObserver](capi-rdb-rdb-dataobserver.md) instance. If this parameter is **nullptr**, all observers of this type will be unregistered.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_GetTableDetails()

```
Rdb_TableDetails *OH_Rdb_GetTableDetails(Rdb_ProgressDetails *progress, int32_t version)
```

**Description**

Obtains the device-cloud sync statistics of a table.

**Since**: 11


**Parameters**

| Parameter| Description                                                        |
| -- |------------------------------------------------------------|
| [Rdb_ProgressDetails](capi-rdb-rdb-progressdetails.md) *progress | Pointer to the [OH_ProgressDetails](capi-rdb-rdb-progressdetails.md) instance.                          |
| int32_t version | Version of the current [Rdb_ProgressDetails](capi-rdb-rdb-progressdetails.md).|

**Returns**

| Type| Description|
| -- | -- |
| [Rdb_TableDetails](capi-rdb-rdb-tabledetails.md) | Returns a pointer to [Rdb_TableDetails](capi-rdb-rdb-tabledetails.md) if the operation is successful; returns null otherwise.|

**See**

Rdb_TableDetails

### Rdb_ProgressCallback()

```
typedef void (*Rdb_ProgressCallback)(void *context, Rdb_ProgressDetails *progressDetails)
```

**Description**

Defines a callback used to return the device-cloud sync progress.

**Since**: 11


**Parameters**

| Parameter              | Description          |
|-------------------|--------------|
| void *context     |              |
| [Rdb_ProgressDetails](capi-rdb-rdb-progressdetails.md) *progressDetails | Details about the device-cloud sync progress.|

### Rdb_SyncCallback()

```
typedef void (*Rdb_SyncCallback)(Rdb_ProgressDetails *progressDetails)
```

**Description**

Defines a callback for device-cloud sync.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [Rdb_ProgressDetails](capi-rdb-rdb-progressdetails.md) *progressDetails | Statistics of device-cloud sync.|

### OH_Rdb_CloudSync()

```
int OH_Rdb_CloudSync(OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables[], uint32_t count,const Rdb_ProgressObserver *observer)
```

**Description**

Performs device-cloud sync.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [Rdb_SyncMode](#rdb_syncmode) mode | Type of the sync process ([Rdb_SyncMode](capi-relational-store-h.md#rdb_syncmode)).|
| const char *tables[] |  Pointer to the names of the tables to be synced.|
| uint32_t count | Number of tables to sync. If the value is **0**, all tables in the RDB store are synced.|
| const [Rdb_ProgressObserver](capi-rdb-rdb-progressobserver.md) *observer | Pointer to the [Rdb_ProgressObserver](capi-rdb-rdb-progressobserver.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_SubscribeAutoSyncProgress()

```
int OH_Rdb_SubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer)
```

**Description**

Subscribes to the auto sync progress of an RDB store.<br>The registered callback will be invoked to return the auto sync progress.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the target [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const [Rdb_ProgressObserver](capi-rdb-rdb-progressobserver.md) *observer | Pointer to the [Rdb_ProgressObserver](capi-rdb-rdb-progressobserver.md) instance, which invokes the callback to return the automatic sync progress.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_UnsubscribeAutoSyncProgress()

```
int OH_Rdb_UnsubscribeAutoSyncProgress(OH_Rdb_Store *store, const Rdb_ProgressObserver *observer)
```

**Description**

Unsubscribes from the auto sync process of an RDB store.

**Since**: 11


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the target [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const [Rdb_ProgressObserver](capi-rdb-rdb-progressobserver.md) *observer | Pointer to the [Rdb_ProgressObserver](capi-rdb-rdb-progressobserver.md) instance. If the pointer is null, all callbacks for the auto sync process will be unregistered.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_LockRow()

```
int OH_Rdb_LockRow(OH_Rdb_Store *store, OH_Predicates *predicates)
```

**Description**

Locks data in an RDB store based on specified conditions. The locked data will be blocked from the device-cloud sync.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the lock conditions.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the operation result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_UnlockRow()

```
int OH_Rdb_UnlockRow(OH_Rdb_Store *store, OH_Predicates *predicates)
```

**Description**

Unlocks data in an RDB store based on the specified conditions.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the unlock conditions.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the operation result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Rdb_QueryLockedRow()

```
OH_Cursor *OH_Rdb_QueryLockedRow(OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length)
```

**Description**

Queries the locked data in an RDB store.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the query conditions.|
| const char *const *columnNames | Columns to query. If this parameter is not specified, the query applies to all columns.|
| int length | Length of **columnNames**. If **length** is greater than the length of **columnNames** array, out-of-bounds access occurs.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_Cursor](capi-rdb-oh-cursor.md) | Returns the pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance if the operation is successful; returns null otherwise.|

### OH_Rdb_CreateTransaction()

```
int OH_Rdb_CreateTransaction(OH_Rdb_Store *store, const OH_RDB_TransOptions *options, OH_Rdb_Transaction **trans)
```

**Description**

Creates a transaction object.

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) *options | Pointer to the [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) instance.|
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) **trans | Double pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance if the operation is successful; otherwise, **nullptr** is returned.<br>Release the memory using [OH_RdbTrans_Destroy](capi-oh-rdb-transaction-h.md#oh_rdbtrans_destroy) if the created transaction is used.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_DATABASE_BUSY** indicates that the database does not respond.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_CANT_OPEN** indicates an SQLite error: unable to open the database file.|

### OH_Rdb_Attach()

```
int OH_Rdb_Attach(OH_Rdb_Store *store, const OH_Rdb_ConfigV2 *config, const char *attachName, int64_t waitTime,size_t *attachedNumber)
```

**Description**

Attaches a database file to the database that is currently connected.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) *config | Pointer to the [OH_Rdb_ConfigV2](capi-rdb-oh-rdb-configv2.md) instance.|
| const char *attachName | Pointer to the alias of the database.|
| int64_t waitTime | Maximum duration for attaching a database, in seconds. The value ranges from 1 to 300.|
| size_t *attachedNumber | Pointer to the number of attached databases.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_NOT_SUPPORTED** indicates that the operation is not supported.<br>**RDB_E_DATABASE_BUSY** indicates that the database does not respond.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_Rdb_Detach()

```
int OH_Rdb_Detach(OH_Rdb_Store *store, const char *attachName, int64_t waitTime, size_t *attachedNumber)
```

**Description**

Detaches a specified store from the current database.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *attachName | Pointer to the alias of the database.|
| int64_t waitTime | Maximum duration for detaching a database, in seconds. The value ranges from 1 to 300.|
| size_t *attachedNumber | Pointer to the number of attached databases.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_NOT_SUPPORTED** indicates that the operation is not supported.<br>**RDB_E_DATABASE_BUSY** indicates that the database does not respond.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_Rdb_SetLocale()

```
int OH_Rdb_SetLocale(OH_Rdb_Store *store, const char *locale)
```

**Description**

Sets locale.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) *store | Pointer to the [OH_Rdb_Store](capi-rdb-oh-rdb-store.md) instance.|
| const char *locale | Pointer to the locale to set, for example, zh. The value must comply with the ISO 639 standard.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_ERR** indicates that the execute function is abnormal.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.|

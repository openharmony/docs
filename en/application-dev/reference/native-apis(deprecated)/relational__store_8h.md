# relational_store.h


## Overview

Provides APIs to manage a relational database (RDB) store.

**Library**: libnative_rdb_ndk.z.so

**Since**: 10

**Related modules**: [RDB](_r_d_b.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [OH_Rdb_Config](_o_h___rdb___config.md) | Defines the RDB store configuration.|
| [OH_Rdb_Store](_o_h___rdb___store.md) | Defines the RDB store type.|
| [Rdb_DistributedConfig](_rdb___distributed_config.md) | Defines the distributed configuration of a table.|
| [Rdb_KeyInfo](_rdb___key_info.md) | Defines the primary key or row number of the row that changes.|
| [Rdb_KeyInfo::Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) | Defines the changed data.|
| [Rdb_ChangeInfo](_rdb___change_info.md) | Defines the details about the device-cloud synchronization process.|
| [Rdb_Statistic](_rdb___statistic.md) | Defines the device-cloud synchronization statistics of a database table.|
| [Rdb_TableDetails](_rdb___table_details.md) | Defines the statistics of device-cloud upload and download tasks of a database table.|
| [Rdb_ProgressDetails](_rdb___progress_details.md) | Defines the statistics of the overall device-cloud upload and download tasks of an RDB store.|


### Macros

| Name| Description|
| -------- | -------- |
| [DISTRIBUTED_CONFIG_VERSION](_r_d_b.md#distributed_config_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_DistributedConfig](_rdb___distributed_config.md).|
| [DISTRIBUTED_CHANGE_INFO_VERSION](_r_d_b.md#distributed_change_info_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_ChangeInfo](_rdb___change_info.md).|
| [DISTRIBUTED_PROGRESS_DETAIL_VERSION](_r_d_b.md#distributed_progress_detail_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_ProgressDetails](_rdb___progress_details.md).|


### Types

| Name| Description|
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel) | Defines an enum for RDB store security levels.|
| [Rdb_SecurityArea](_r_d_b.md#rdb_securityarea) | Defines an enum for security area levels of an RDB store.|
| [Rdb_DistributedType](_r_d_b.md#rdb_distributedtype) | Defines an enum for distributed types.|
| [Rdb_DistributedConfig](_r_d_b.md#rdb_distributedconfig) | Defines a struct for the distributed configuration of a table.|
| [Rdb_ChangeType](_r_d_b.md#rdb_changetype) | Defines an enum for data change types.|
| [Rdb_KeyInfo](_r_d_b.md#rdb_keyinfo) | Defines a struct for the primary key or row number of the row that changes.|
| [Rdb_ChangeInfo](_r_d_b.md#rdb_changeinfo) | Defines a struct for details about the device-cloud synchronization process.|
| [Rdb_SubscribeType](_r_d_b.md#rdb_subscribetype) | Defines an enum for subscription types.|
| [Rdb_SyncMode](_r_d_b.md#rdb_syncmode) | Defines an enum for RDB synchronization modes.|
| [Rdb_Statistic](_r_d_b.md#rdb_statistic) | Defines a struct for device-cloud synchronization statistics of a database table.|
| [Rdb_TableDetails](_r_d_b.md#rdb_tabledetails) | Defines a struct for statistics of device-cloud upload and download tasks of a database table.|
| [Rdb_Progress](_r_d_b.md#rdb_progress) | Defines an enum for device-cloud synchronization progresses.|
| [Rdb_ProgressCode](_r_d_b.md#rdb_progresscode) | Defines an enum for states in the device-cloud synchronization process.|
| [Rdb_ProgressDetails](_r_d_b.md#rdb_progressdetails) | Defines a struct for statistics of the overall device-cloud upload and download tasks of an RDB store.|
| [Rdb_SyncCallback](_r_d_b.md#rdb_synccallback) | Defines a callback to be invoked in device-cloud synchronization.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel) { S1 = 1, S2, S3, S4} | Enumerates the RDB store security levels.|
| [Rdb_SecurityArea](_r_d_b.md#rdb_securityarea) { RDB_SECURITY_AREA_EL1 = 1, RDB_SECURITY_AREA_EL2, RDB_SECURITY_AREA_EL3, RDB_SECURITY_AREA_EL4 } | Enumerates the security area levels of an RDB store.|
| [Rdb_DistributedType](_r_d_b.md#rdb_distributedtype) { RDB_DISTRIBUTED_CLOUD } | Enumerates the distributed types.|
| [Rdb_ChangeType](_r_d_b.md#rdb_changetype) { RDB_DATA_CHANGE, RDB_ASSET_CHANGE } | Enumerates the data change types.|
| [Rdb_SubscribeType](_r_d_b.md#rdb_subscribetype) { RDB_SUBSCRIBE_TYPE_CLOUD, RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS } | Enumerates the subscription types.|
| [Rdb_SyncMode](_r_d_b.md#rdb_syncmode) { RDB_SYNC_MODE_TIME_FIRST, RDB_SYNC_MODE_NATIVE_FIRST, RDB_SYNC_MODE_CLOUD_FIRST } | Enumerates the RDB synchronization modes.|
| [Rdb_Progress](_r_d_b.md#rdb_progress) { RDB_SYNC_BEGIN, RDB_SYNC_IN_PROGRESS, RDB_SYNC_FINISH } | Enumerates the device-cloud synchronization progresses.|
| [Rdb_ProgressCode](_r_d_b.md#rdb_progresscode) {<br>RDB_SUCCESS, RDB_UNKNOWN_ERROR, RDB_NETWORK_ERROR, RDB_CLOUD_DISABLED,<br>RDB_LOCKED_BY_OTHERS, RDB_RECORD_LIMIT_EXCEEDED, RDB_NO_SPACE_FOR_ASSET<br>} | Enumerates the states in the device-cloud synchronization process.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Rdb_CreateValueObject](_r_d_b.md#oh_rdb_createvalueobject) (void) | Creates an [OH_VObject](_o_h___v_object.md) instance.|
| [OH_Rdb_CreateValuesBucket](_r_d_b.md#oh_rdb_createvaluesbucket) (void) | Creates an [OH_VBucket](_o_h___v_bucket.md) instance.|
| [OH_Rdb_CreatePredicates](_r_d_b.md#oh_rdb_createpredicates) (const char \*table) | Creates an [OH_Predicates](_o_h___predicates.md) instance.|
| [OH_Rdb_GetOrOpen](_r_d_b.md#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | Obtains an [OH_Rdb_Store](_o_h___rdb___store.md) instance for RDB store operations.|
| [OH_Rdb_CloseStore](_r_d_b.md#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Destroys an [OH_Rdb_Store](_o_h___rdb___store.md) object and reclaims the memory occupied by the object.|
| [OH_Rdb_DeleteStore](_r_d_b.md#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | Deletes an RDB store with the specified database file configuration.|
| [OH_Rdb_Insert](_r_d_b.md#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | Inserts a row of data into a table.|
| [OH_Rdb_Update](_r_d_b.md#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | Updates data in an RDB store based on specified conditions.|
| [OH_Rdb_Delete](_r_d_b.md#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Deletes data from an RDB store based on specified conditions.|
| [OH_Rdb_Query](_r_d_b.md#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | Queries data in an RDB store based on specified conditions.|
| [OH_Rdb_Execute](_r_d_b.md#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Executes the SQL statement that returns no value.|
| [OH_Rdb_ExecuteQuery](_r_d_b.md#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Queries data in an RDB store based on the SQL statements executed.|
| [OH_Rdb_BeginTransaction](_r_d_b.md#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Starts the transaction before executing the SQL statements.|
| [OH_Rdb_RollBack](_r_d_b.md#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Rolls back the SQL statements that have been executed.|
| [OH_Rdb_Commit](_r_d_b.md#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Commits the executed SQL statements.|
| [OH_Rdb_Backup](_r_d_b.md#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Backs up the RDB store in the specified path.|
| [OH_Rdb_Restore](_r_d_b.md#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Restores an RDB store from the specified database backup file.|
| [OH_Rdb_GetVersion](_r_d_b.md#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | Obtains the RDB store version.|
| [OH_Rdb_SetVersion](_r_d_b.md#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | Sets the RDB store version.|
| [OH_Rdb_SetDistributedTables](_r_d_b.md#oh_rdb_setdistributedtables) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tables[], uint32_t count, [Rdb_DistributedType](_r_d_b.md#rdb_distributedtype) type, const [Rdb_DistributedConfig](_rdb___distributed_config.md) \*config) | Sets distributed database tables.|
| [OH_Rdb_FindModifyTime](_r_d_b.md#oh_rdb_findmodifytime) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tableName, const char \*columnName, [OH_VObject](_o_h___v_object.md) \*values) | Obtains the last modification time of a table in an RDB store.|
| [OH_Rdb_GetTableDetails](_r_d_b.md#oh_rdb_gettabledetails) ([Rdb_ProgressDetails](_rdb___progress_details.md) \*progress, int32_t version) | Obtains the device-cloud synchronization statistics of a table.|
| [OH_Rdb_CloudSync](_r_d_b.md#oh_rdb_cloudsync) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SyncMode](_r_d_b.md#rdb_syncmode) mode, const char \*tables, int count, [Rdb_SyncCallback](_r_d_b.md#rdb_synccallback) \*progress) | Performs device-cloud synchronization.|

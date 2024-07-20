# RDB


## Overview

The relational database (RDB) store manages data based on relational models. The RDB store provides a complete mechanism for managing local databases based on the underlying SQLite. It provides a series of methods for performing operations, such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements to satisfy different needs in complicated scenarios.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 10


## Summary


### Files

| Name | Description |
| -------- | -------- |
| [oh_cursor.h](oh__cursor_8h.md) | Defines APIs for accessing the result set obtained by querying the RDB store.<br>**File to include**: <database/rdb/oh_cursor.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_predicates.h](oh__predicates_8h.md) | Defines the predicates for RDB stores.<br>**File to include**: <database/rdb/oh_predicates.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_value_object.h](oh__value__object_8h.md) | Defines the APIs for type conversion.<br>**File to include**: <database/rdb/oh_value_object.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_values_bucket.h](oh__values__bucket_8h.md) | Defines the types of the key and value in a key-value (KV) pair.<br>**File to include**: <database/rdb/oh_values_bucket.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [relational_store.h](relational__store_8h.md) | Defines APIs for managing an RDB store.<br>**File to include**: <database/rdb/relational_store.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [relational_store_error_code.h](relational__store__error__code_8h.md) | Defines the error codes used for RDB stores.<br>**File to include**: <database/rdb/relational_store_error_code.h><br>**Library**: libnative_rdb_ndk.z.so |


### Structs

| Name | Description |
| -------- | -------- |
| [OH_Cursor](_o_h___cursor.md) | Defines a result set. | 
| [OH_Predicates](_o_h___predicates.md) | Defines a **predicates** object. | 
| [OH_VObject](_o_h___v_object.md) | Defines the allowed data field types. | 
| [OH_VBucket](_o_h___v_bucket.md) | Defines the types of the key and value in a KV pair. | 
| [OH_Rdb_Config](_o_h___rdb___config.md) | Defines the RDB store configuration. | 
| [OH_Rdb_Store](_o_h___rdb___store.md) | Defines the RDB store type. | 
| [Rdb_DistributedConfig](_rdb___distributed_config.md) | Defines the distributed configuration of a table. | 
| [Rdb_KeyInfo](_rdb___key_info.md) | Defines the primary key or row number of the row that changes. | 
| [Rdb_KeyInfo::Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) | Defines the changed data. | 
| [Rdb_ChangeInfo](_rdb___change_info.md) | Defines the details about the device-cloud sync process. | 
| [Rdb_SubscribeCallback](union_rdb___subscribe_callback.md) | Defines a callback used to return the subscribed event. | 
| [Rdb_DataObserver](_rdb___data_observer.md) | Defines the data observer. | 
| [Rdb_Statistic](_rdb___statistic.md) | Defines the device-cloud sync statistics of a database table. | 
| [Rdb_TableDetails](_rdb___table_details.md) | Defines the statistics of device-cloud upload and download tasks of a database table. | 
| [Rdb_ProgressDetails](_rdb___progress_details.md) | Defines the statistics of the overall device-cloud sync (upload and download) tasks of an RDB store. | 
| [Rdb_ProgressObserver](_rdb___progress_observer.md) | Defines the observer of the device-cloud sync progress. | 


### Macros

| Name | Description |
| -------- | -------- |
| [DISTRIBUTED_CONFIG_VERSION](#distributed_config_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_DistributedConfig](_rdb___distributed_config.md). |
| [DISTRIBUTED_CHANGE_INFO_VERSION](#distributed_change_info_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_ChangeInfo](_rdb___change_info.md). |
| [DISTRIBUTED_PROGRESS_DETAIL_VERSION](#distributed_progress_detail_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_ProgressDetails](_rdb___progress_details.md). |


### Types

| Name | Description |
| -------- | -------- |
| [OH_ColumnType](#oh_columntype) | Defines an enum for the field types in an RDB store. | 
| [OH_Cursor](#oh_cursor) | Defines a struct for a result set. | 
| [OH_OrderType](#oh_ordertype) | Defines an enum for sorting types. | 
| [OH_Predicates](#oh_predicates) | Defines a **predicates** object. | 
| [OH_VObject](#oh_vobject) | Defines a struct for allowed data field types. | 
| [OH_VBucket](#oh_vbucket) | Defines a struct for the types of the key and value in a KV pair. | 
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) | Defines an enum for RDB store security levels. | 
| [Rdb_SecurityArea](#rdb_securityarea) | Defines an enum for security area levels of an RDB store. | 
| [Rdb_DistributedType](#rdb_distributedtype) | Defines an enum for distributed types. | 
| [Rdb_DistributedConfig](#rdb_distributedconfig) | Defines a struct for distributed configuration of a table. | 
| [Rdb_ChangeType](#rdb_changetype) | Defines an enum for data change types. | 
| [Rdb_KeyInfo](#rdb_keyinfo) | Defines a struct for the primary key or row number of the row that changes. | 
| [Rdb_ChangeInfo](#rdb_changeinfo) | Defines a struct for the details about the device-cloud sync process. | 
| [Rdb_SubscribeType](#rdb_subscribetype) | Defines an enum for subscription types. | 
| [Rdb_BriefObserver](#rdb_briefobserver) | Defines a callback used to return the device-cloud data change event. | 
| [Rdb_DetailsObserver](#rdb_detailsobserver) | Defines a callback used to return the details about the device-cloud data change. | 
| [Rdb_SubscribeCallback](#rdb_subscribecallback) | Defines a callback used to return the subscribed event. | 
| [Rdb_DataObserver](#rdb_dataobserver) | Defines a struct for the data observer. | 
| [Rdb_SyncMode](#rdb_syncmode) | Defines an enum for RDB store sync modes. | 
| [Rdb_Statistic](#rdb_statistic) | Defines a struct for the device-cloud sync statistics of a database table. | 
| [Rdb_TableDetails](#rdb_tabledetails) | Defines a struct for statistics of device-cloud upload and download tasks of a database table. | 
| [Rdb_Progress](#rdb_progress) | Defines an enum for device-cloud sync progresses. | 
| [Rdb_ProgressCode](#rdb_progresscode) | Defines an enum for device-cloud sync states. | 
| [Rdb_ProgressDetails](#rdb_progressdetails) | Defines a struct for statistics of the overall device-cloud sync (upload and download) tasks of an RDB store. | 
| [Rdb_ProgressCallback](#rdb_progresscallback) | Defines a callback used to return the device-cloud sync progress. | 
| [Rdb_SyncCallback](#rdb_synccallback) | Defines a callback for device-cloud sync. | 
| [Rdb_ProgressObserver](#rdb_progressobserver) | Defines the observer of the device-cloud sync progress. | 
| [OH_Rdb_ErrCode](#oh_rdb_errcode) | Defines an enum for error codes. | 


### Enums

| Name | Description |
| -------- | -------- |
| [OH_ColumnType](#oh_columntype-1) {<br>TYPE_NULL = 0, TYPE_INT64, TYPE_REAL, TYPE_TEXT,<br>TYPE_BLOB, TYPE_ASSET, TYPE_ASSETS<br>} | Enumerates the types of the fields in an RDB store. |
| [OH_OrderType](#oh_ordertype-1) { ASC = 0, DESC = 1 } | Enumerates the sorting types. |
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel-1) { S1 = 1, S2, S3, S4 } | Enumerates  the RDB store security levels. |
| [Rdb_SecurityArea](#rdb_securityarea-1) { RDB_SECURITY_AREA_EL1 = 1, RDB_SECURITY_AREA_EL2, RDB_SECURITY_AREA_EL3, RDB_SECURITY_AREA_EL4 } | Enumerates the security area levels of an RDB store. |
| [Rdb_DistributedType](#rdb_distributedtype-1) { RDB_DISTRIBUTED_CLOUD } | Enumerates the distributed types. |
| [Rdb_ChangeType](#rdb_changetype-1) { RDB_DATA_CHANGE, RDB_ASSET_CHANGE } | Enumerates the data change types. |
| [Rdb_SubscribeType](#rdb_subscribetype-1) { RDB_SUBSCRIBE_TYPE_CLOUD, RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS, RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS } | Enumerates the subscription types. |
| [Rdb_SyncMode](#rdb_syncmode-1) { RDB_SYNC_MODE_TIME_FIRST, RDB_SYNC_MODE_NATIVE_FIRST, RDB_SYNC_MODE_CLOUD_FIRST } | Enumerates the RDB sync modes. |
| [Rdb_Progress](#rdb_progress-1) { RDB_SYNC_BEGIN, RDB_SYNC_IN_PROGRESS, RDB_SYNC_FINISH } | Enumerates the device-cloud sync progresses. |
| [Rdb_ProgressCode](#rdb_progresscode-1) {<br>RDB_SUCCESS, RDB_UNKNOWN_ERROR, RDB_NETWORK_ERROR, RDB_CLOUD_DISABLED,<br>RDB_LOCKED_BY_OTHERS, RDB_RECORD_LIMIT_EXCEEDED, RDB_NO_SPACE_FOR_ASSET<br>} | Enumerates the device-cloud sync states. |
| [OH_Rdb_ErrCode](#oh_rdb_errcode-1) {<br>RDB_ERR = -1, RDB_OK = 0, E_BASE = 14800000, RDB_E_NOT_SUPPORTED = 801,<br>RDB_E_ERROR = E_BASE, RDB_E_INVALID_ARGS = (E_BASE + 1), RDB_E_CANNOT_UPDATE_READONLY = (E_BASE + 2), RDB_E_REMOVE_FILE = (E_BASE + 3),<br>RDB_E_EMPTY_TABLE_NAME = (E_BASE + 5), RDB_E_EMPTY_VALUES_BUCKET = (E_BASE + 6), RDB_E_EXECUTE_IN_STEP_QUERY = (E_BASE + 7), RDB_E_INVALID_COLUMN_INDEX = (E_BASE + 8),<br>RDB_E_INVALID_COLUMN_TYPE = (E_BASE + 9), RDB_E_EMPTY_FILE_NAME = (E_BASE + 10), RDB_E_INVALID_FILE_PATH = (E_BASE + 11), RDB_E_TRANSACTION_IN_EXECUTE = (E_BASE + 12),<br>RDB_E_INVALID_STATEMENT = (E_BASE + 13), RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION = (E_BASE + 14), RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION = (E_BASE + 15), RDB_E_NO_TRANSACTION_IN_SESSION = (E_BASE + 16),<br>RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION = (E_BASE + 17), RDB_E_NO_ROW_IN_QUERY = (E_BASE + 18), RDB_E_INVALID_BIND_ARGS_COUNT = (E_BASE + 19), RDB_E_INVALID_OBJECT_TYPE = (E_BASE + 20),<br>RDB_E_INVALID_CONFLICT_FLAG = (E_BASE + 21), RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY = (E_BASE + 22), RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET = (E_BASE + 23), RDB_E_STEP_RESULT_SET_CROSS_THREADS = (E_BASE + 24),<br>RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED = (E_BASE + 25), RDB_E_STEP_RESULT_IS_AFTER_LAST = (E_BASE + 26), RDB_E_STEP_RESULT_QUERY_EXCEEDED = (E_BASE + 27), RDB_E_STATEMENT_NOT_PREPARED = (E_BASE + 28),<br>RDB_E_EXECUTE_RESULT_INCORRECT = (E_BASE + 29), RDB_E_STEP_RESULT_CLOSED = (E_BASE + 30), RDB_E_RELATIVE_PATH = (E_BASE + 31), RDB_E_EMPTY_NEW_ENCRYPT_KEY = (E_BASE + 32),<br>RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED = (E_BASE + 33), RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY = (E_BASE + 34), RDB_E_STEP_STATEMENT_NOT_INIT = (E_BASE + 35), RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE = (E_BASE + 36),<br>RDB_E_CREATE_FOLDER_FAIL = (E_BASE + 37), RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL = (E_BASE + 38), RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY = (E_BASE + 39), RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION = (E_BASE + 40),<br>RDB_E_NOT_SUPPORT = (E_BASE + 41), RDB_E_INVALID_PARCEL = (E_BASE + 42), RDB_E_QUERY_IN_EXECUTE = (E_BASE + 43), RDB_E_SET_PERSIST_WAL = (E_BASE + 44),<br>RDB_E_DB_NOT_EXIST = (E_BASE + 45), RDB_E_ARGS_READ_CON_OVERLOAD = (E_BASE + 46), RDB_E_WAL_SIZE_OVER_LIMIT = (E_BASE + 47), RDB_E_CON_OVER_LIMIT = (E_BASE + 48)<br>} | Enumerates the RDB store error codes. |


### Functions

| Name | Description |
| -------- | -------- |
| [OH_VBucket_PutAsset](#oh_vbucket_putasset) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*value) | Puts an **OH_Asset** object into the [OH_VBucket](_o_h___v_bucket.md) object with the given column name. | 
| [OH_VBucket_PutAssets](#oh_vbucket_putassets) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*\*value, int count) | Puts an array of **OH_Asset** objects into the [OH_VBucket](_o_h___v_bucket.md) object with the given column name. | 
| [OH_Rdb_CreateValueObject](#oh_rdb_createvalueobject) () | Creates an [OH_VObject](_o_h___v_object.md) instance. | 
| [OH_Rdb_CreateValuesBucket](#oh_rdb_createvaluesbucket) () | Creates an [OH_VBucket](_o_h___v_bucket.md) instance. | 
| [OH_Rdb_CreatePredicates](#oh_rdb_createpredicates) (const char \*table) | Creates an [OH_Predicates](_o_h___predicates.md) instance. | 
| [OH_Rdb_GetOrOpen](#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | Obtains an [OH_Rdb_Store](_o_h___rdb___store.md) instance for RDB store operations. | 
| [OH_Rdb_CloseStore](#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Closes an [OH_Rdb_Store](_o_h___rdb___store.md) object to reclaim the memory occupied. | 
| [OH_Rdb_DeleteStore](#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | Deletes an RDB store with the specified database file configuration. | 
| [OH_Rdb_Insert](#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | Inserts a row of data into a table. | 
| [OH_Rdb_Update](#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | Updates data in an RDB store based on specified conditions. | 
| [OH_Rdb_Delete](#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Deletes data from an RDB store based on specified conditions. | 
| [OH_Rdb_Query](#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | Queries data in an RDB store based on specified conditions. | 
| [OH_Rdb_Execute](#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Executes an SQL statement but returns no value. | 
| [OH_Rdb_ExecuteQuery](#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Executes the SQL statement to query data in an RDB store. | 
| [OH_Rdb_BeginTransaction](#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Starts the transaction before executing the SQL statement. | 
| [OH_Rdb_RollBack](#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Rolls back the SQL statements executed. | 
| [OH_Rdb_Commit](#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Commits the executed SQL statements. | 
| [OH_Rdb_Backup](#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Backs up an RDB store in the specified directory. | 
| [OH_Rdb_Restore](#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Restores an RDB store from the specified database backup file. | 
| [OH_Rdb_GetVersion](#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | Obtains the RDB store version. | 
| [OH_Rdb_SetVersion](#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | Sets the RDB store version. | 
| [OH_Rdb_SetDistributedTables](#oh_rdb_setdistributedtables) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tables[], uint32_t count, [Rdb_DistributedType](#rdb_distributedtype) type, const [Rdb_DistributedConfig](_rdb___distributed_config.md) \*config) | Sets distributed database tables. | 
| [OH_Rdb_FindModifyTime](#oh_rdb_findmodifytime) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tableName, const char \*columnName, [OH_VObject](_o_h___v_object.md) \*values) | Obtains the last modification time of a table in an RDB store. | 
| [OH_Rdb_Subscribe](#oh_rdb_subscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | Registers an observer for an RDB store. When data in the RDB store changes, a callback will be invoked to return the data changes. | 
| [OH_Rdb_Unsubscribe](#oh_rdb_unsubscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | Unregisters the observer of the specified type. | 
| [OH_Rdb_GetTableDetails](#oh_rdb_gettabledetails) ([Rdb_ProgressDetails](_rdb___progress_details.md) \*progress, int32_t version) | Obtains the device-cloud sync statistics of a table. | 
| [OH_Rdb_CloudSync](#oh_rdb_cloudsync) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SyncMode](#rdb_syncmode) mode, const char \*tables, int count, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | Performs device-cloud sync. | 
| [OH_Rdb_SubscribeAutoSyncProgress](#oh_rdb_subscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | Subscribes to the automatic sync progress of an RDB store. The registered callback will be invoked to return the automatic sync progress. | 
| [OH_Rdb_UnsubscribeAutoSyncProgress](#oh_rdb_unsubscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | Unsubscribes from the automatic sync process of an RDB store. | 
| int [OH_Rdb_LockRow](#oh_rdb_lockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Locks data in an RDB store based on specified conditions. The locked data will be blocked from the device-cloud sync. | 
| int [OH_Rdb_UnlockRow](#oh_rdb_unlockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Unlocks data in an RDB store based on the specified conditions. | 
| [OH_Cursor](_o_h___cursor.md) \* [OH_Rdb_QueryLockedRow](#oh_rdb_querylockedrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | Queries the locked data in an RDB store. | 

### Variables

| Name | Description |
| -------- | -------- |
| [OH_Cursor::id](#id-15) | Unique identifier of the **OH_Cursor** struct. | 
| [OH_Cursor::getColumnCount](#getcolumncount) | Pointer to the function used to obtain the number of columns in the result set. | 
| [OH_Cursor::getColumnType](#getcolumntype) | Pointer to the function used to obtain the column type based on the specified column index. | 
| [OH_Cursor::getColumnIndex](#getcolumnindex) | Pointer to the function used to obtain the column index based on the specified column name. | 
| [OH_Cursor::getColumnName](#getcolumnname) | Pointer to the function used to obtain the column name based on the specified column index. | 
| [OH_Cursor::getRowCount](#getrowcount) | Pointer to the function used to obtain the number of rows in the result set. | 
| [OH_Cursor::goToNextRow](#gotonextrow) | Pointer to the function used to go to the next row of the result set. | 
| [OH_Cursor::getSize](#getsize) | Pointer to the function used to obtain information about the memory required when the column data type in the result set is **BLOB** or **TEXT**. | 
| [OH_Cursor::getText](#gettext) | Pointer to the function used to obtain the value of the string type based on the specified column and the current row. | 
| [OH_Cursor::getInt64](#getint64) | Pointer to the function used to obtain the value of the int64_t type based on the specified column and the current row. | 
| [OH_Cursor::getReal](#getreal) | Pointer to the function used to obtain the value of the double type based on the specified column and the current row. | 
| [OH_Cursor::getBlob](#getblob) | Pointer to the function used to obtain the values in the form of a byte array based on the specified column and the current row. | 
| [OH_Cursor::isNull](#isnull-12) | Pointer to the function used to check whether the value in the specified column is null. | 
| [OH_Cursor::destroy](#destroy-14) | Pointer to the function used to destroy a result set. | 
| [OH_Cursor::getAsset](#getasset) | Pointer to the function used to obtain the value of the asset type based on the specified column and the current row. | 
| [OH_Cursor::getAssets](#getassets) | Pointer to the function used to obtain the values in the form of an asset array based on the specified column and the current row. | 
| [OH_Predicates::id](#id-25) | Unique identifier of the **OH_Predicates** struct. | 
| [OH_Predicates::equalTo](#equalto) | Pointer to the function used to set a predicates object to match the field whose value is equal to the specified value. | 
| [OH_Predicates::notEqualTo](#notequalto) | Pointer to the function used to set a predicates object to match the field whose value is not equal to the specified value. | 
| [OH_Predicates::beginWrap](#beginwrap) | Pointer to the function used to add a left parenthesis to the predicates. | 
| [OH_Predicates::endWrap](#endwrap) | Pointer to the function used to add a right parenthesis to the predicates. | 
| [OH_Predicates::orOperate](#oroperate) | Pointer to the function used to add the OR operator to the predicates. | 
| [OH_Predicates::andOperate](#andoperate) | Pointer to the function used to add the AND operator to the predicates. | 
| [OH_Predicates::isNull](#isnull-22) | Pointer to the function used to set a predicates object to match the field whose value is null. | 
| [OH_Predicates::isNotNull](#isnotnull) | Pointer to the function used to set a predicates object to match the field whose value is not null. | 
| [OH_Predicates::like](#like) | Pointer to the function used to set a predicates object to match a string that is similar to the specified value. | 
| [OH_Predicates::between](#between) | Pointer to the function used to set a predicates object to match the field whose value is within the specified range. | 
| [OH_Predicates::notBetween](#notbetween) | Pointer to the function used to set a predicates object to match the field whose value is out of the specified range. | 
| [OH_Predicates::greaterThan](#greaterthan) | Pointer to the function used to set a predicates object to match the field with value greater than the specified value. | 
| [OH_Predicates::lessThan](#lessthan) | Pointer to the function used to set a predicates object to match the field with value less than the specified value. | 
| [OH_Predicates::greaterThanOrEqualTo](#greaterthanorequalto) | Pointer to the function used to set a predicates object to match the field with value greater than or equal to the specified value. | 
| [OH_Predicates::lessThanOrEqualTo](#lessthanorequalto) | Pointer to the function used to set a predicates object to match the field with value less than or equal to the specified value. | 
| [OH_Predicates::orderBy](#orderby) | Pointer to the function used to set a predicates object to sort the values in a column in ascending or descending order. | 
| [OH_Predicates::distinct](#distinct) | Pointer to the function used to set a predicates object to filter out duplicate records. | 
| [OH_Predicates::limit](#limit) | Pointer to the function used to set a predicates object to specify the maximum number of records. | 
| [OH_Predicates::offset](#offset) | Pointer to the function used to set a predicates object to specify the start position of the returned result. | 
| [OH_Predicates::groupBy](#groupby) | Pointer to the function used to set a predicates object to group rows that have the same value into summary rows. | 
| [OH_Predicates::in](#in) | Pointer to the function used to set a predicates object to match the field with the value within the specified range. | 
| [OH_Predicates::notIn](#notin) | Pointer to the function used to set a predicates object to match the field with the value out of the specified range. | 
| [OH_Predicates::clear](#clear-12) | Pointer to the function used to clear a predicates instance. | 
| [OH_Predicates::destroy](#destroy-24) | Pointer to the function used to destroy an [OH_Predicates](_o_h___predicates.md) object to reclaim the memory occupied. | 
| [OH_VObject::id](#id-35) | Unique identifier of the **OH_VObject** struct. | 
| [OH_VObject::putInt64](#putint64-22) | Pointer to the function used to convert a single parameter or an array of the int64 type into a value of the [OH_VObject](_o_h___v_object.md) type. | 
| [OH_VObject::putDouble](#putdouble) | Pointer to the function used to convert a single parameter or an array of the double type into a value of the [OH_VObject](_o_h___v_object.md) type. | 
| [OH_VObject::putText](#puttext-22) | Pointer to the function used to convert a character array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type. | 
| [OH_VObject::putTexts](#puttexts) | Pointer to the function used to convert a string array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type. | 
| [OH_VObject::destroy](#destroy-44) | Pointer to the function used to destroy an [OH_VObject](_o_h___v_object.md) object to reclaim the memory occupied. | 
| [OH_VBucket::id](#id-45) | Unique identifier of the **OH_VBucket** struct. | 
| [OH_VBucket::capability](#capability) | Number of the KV pairs in the struct. | 
| [OH_VBucket::putText](#puttext-12) | Pointer to the function used to put a char value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column. | 
| [OH_VBucket::putInt64](#putint64-12) | Pointer to the function used to put an int64_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column. | 
| [OH_VBucket::putReal](#putreal) | Pointer to the function used to put a double value into the {OH_VBucket} object in the given column.|
| [OH_VBucket::putBlob](#putblob) | Pointer to the function used to put a const uint8_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column. | 
| [OH_VBucket::putNull](#putnull) | Pointer to the function used to put a null value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column. | 
| [OH_VBucket::clear](#clear-22) | Pointer to the function used to clear an [OH_VBucket](_o_h___v_bucket.md) object. | 
| [OH_VBucket::destroy](#destroy-34) | Pointer to the function used to destroy an [OH_VBucket](_o_h___v_bucket.md) object to reclaim the memory occupied. | 
| [OH_Rdb_Config::selfSize](#selfsize) | Size of the struct. | 
| [OH_Rdb_Config::dataBaseDir](#databasedir) | Path of the database file. | 
| [OH_Rdb_Config::storeName](#storename) | Name of the RDB store. | 
| [OH_Rdb_Config::bundleName](#bundlename) | Bundle name. | 
| [OH_Rdb_Config::moduleName](#modulename) | Module name.  | 
| [OH_Rdb_Config::isEncrypt](#isencrypt) | Whether to encrypt the RDB store. | 
| [OH_Rdb_Config::securityLevel](#securitylevel) | RDB store security level. For details, see [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel). | 
| [OH_Rdb_Config::area](#area) | Security area level. For details, see [Rdb_SecurityArea](#rdb_securityarea). | 
| [OH_Rdb_Store::id](#id-55) | Unique identifier of the **OH_Rdb_Store** struct. | 
| [Rdb_DistributedConfig::version](#version-13) | Version of the **Rdb_DistributedConfig** struct. | 
| [Rdb_DistributedConfig::isAutoSync](#isautosync) | Whether the table supports automatic sync. | 
| [Rdb_KeyInfo::count](#count) | Number of the changed primary keys or row numbers. | 
| [Rdb_KeyInfo::type](#type) | Type ([OH_ColumnType](#oh_columntype)) of the primary key. | 
| [Rdb_KeyInfo::Rdb_KeyData::integer](#integer) | Data of the uint64_t type. | 
| [Rdb_KeyInfo::Rdb_KeyData::real](#real) | Data of the double type. | 
| [Rdb_KeyInfo::Rdb_KeyData::text](#text) | Data of the char \* type. | 
| [Rdb_KeyInfo::data](_rdb___key_info.md#member-variables) | Changed data. | 
| [Rdb_ChangeInfo::version](#version-23) | Version of the **Rdb_DistributedConfig** struct. | 
| [Rdb_ChangeInfo::tableName](#tablename) | Name of the table with data changes. | 
| [Rdb_ChangeInfo::ChangeType](#changetype) | Type of the data changed, which can be data or asset. | 
| [Rdb_ChangeInfo::inserted](#inserted) | Location where data is inserted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the inserted data. | 
| [Rdb_ChangeInfo::updated](#updated) | Location where data is updated. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the updated data. | 
| [Rdb_ChangeInfo::deleted](#deleted) | Location where data is deleted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the deleted data. | 
| [Rdb_SubscribeCallback::detailsObserver](#detailsobserver) | Callback used to return the details about the device-cloud data change. | 
| [Rdb_SubscribeCallback::briefObserver](#briefobserver) | Callback used to return the device-cloud data change event. | 
| [Rdb_DataObserver::context](#context-12) | Context of the data observer. | 
| [Rdb_DataObserver::callback](#callback-12) | Callback used to return the result.|
| [Rdb_Statistic::total](#total) | Total number of rows to be synchronized between the device and cloud in the database table. | 
| [Rdb_Statistic::successful](#successful) | Number of rows that are successfully synchronized between the device and cloud in the database table. | 
| [Rdb_Statistic::failed](#failed) | Number of rows that failed to be synchronized between the device and cloud in the database table. | 
| [Rdb_Statistic::remained](#remained) | Number of rows that are not executed for device-cloud sync in the database table. | 
| [Rdb_TableDetails::table](#table) | Database table name. | 
| [Rdb_TableDetails::upload](#upload) | Statistics of the device-cloud upload tasks. | 
| [Rdb_TableDetails::download](#download) | Statistics of the device-cloud download tasks. | 
| [Rdb_ProgressDetails::version](#version-33) | Version of the **OH_TableDetails** struct. | 
| [Rdb_ProgressDetails::schedule](#schedule) | Device-cloud sync process. | 
| [Rdb_ProgressDetails::code](#code) | Device-cloud sync state. | 
| [Rdb_ProgressDetails::tableLength](#tablelength) | Number of the tables synchronized between the device and cloud. | 
| [Rdb_ProgressObserver::context](#context-22) | Context of the device-cloud sync progress observer. | 
| [Rdb_ProgressObserver::callback](#callback-22) | Callback used to return the device-cloud sync progress.|


## Macro Description


### DISTRIBUTED_CHANGE_INFO_VERSION

```
#define DISTRIBUTED_CHANGE_INFO_VERSION   1
```

**Description**

Version of [Rdb_ChangeInfo](_rdb___change_info.md).

**Since**: 11


### DISTRIBUTED_CONFIG_VERSION

```
#define DISTRIBUTED_CONFIG_VERSION   1
```

**Description**

Version of [Rdb_DistributedConfig](_rdb___distributed_config.md).

**Since**: 11


### DISTRIBUTED_PROGRESS_DETAIL_VERSION

```
#define DISTRIBUTED_PROGRESS_DETAIL_VERSION   1
```

**Description**

Version of **OH_ProgressDetails**.

**Since**: 11


## Type Description


### OH_ColumnType

```
typedef enum OH_ColumnType OH_ColumnType
```

**Description**

Defines an enum for the types of the fields in an RDB store.

**Since**: 10


### OH_Cursor

```
typedef struct OH_Cursor OH_Cursor
```

**Description**

Defines a struct for a result set.

APIs are provided to access the result set obtained by querying the RDB store.

**Since**: 10


### OH_OrderType

```
typedef enum OH_OrderType OH_OrderType
```

**Description**

Defines an enum for sorting types.

**Since**: 10


### OH_Predicates

```
typedef struct OH_Predicates OH_Predicates
```

**Description**

Defines a **predicates** object.

**Since**: 10


### OH_Rdb_ErrCode

```
typedef enum OH_Rdb_ErrCode OH_Rdb_ErrCode
```

**Description**

Defines an enum for error codes.

**Since**: 10


### OH_Rdb_SecurityLevel

```
typedef enum OH_Rdb_SecurityLevel OH_Rdb_SecurityLevel
```

**Description**

Defines an enum for RDB store security levels.

**Since**: 10


### OH_VBucket

```
typedef struct OH_VBucket OH_VBucket
```

**Description**

Defines a struct for the types of the key and value in a KV pair.

**Since**: 10


### OH_VObject

```
typedef struct OH_VObject OH_VObject
```

**Description**

Defines a struct for allowed data types.

**Since**: 10


### Rdb_BriefObserver

```
typedef void(* Rdb_BriefObserver) (void *context, const char *values[], uint32_t count)
```

**Description**

Defines a callback used to return the device-cloud data change event.

**Since**: 11

**Parameters**

| Name | Description | 
| -------- | -------- |
| context | Pointer to the context of the data observer. | 
| values | Pointer to the accounts whose device-cloud data is changed.|
| count | Number of accounts whose device-cloud data is changed.|


### Rdb_ChangeInfo

```
typedef struct Rdb_ChangeInfo Rdb_ChangeInfo
```

**Description**

Defines a struct for the details about the device-cloud sync process.

**Since**: 11


### Rdb_ChangeType

```
typedef enum Rdb_ChangeType Rdb_ChangeType
```

**Description**

Defines an enum for data change types.

**Since**: 11


### Rdb_DataObserver

```
typedef struct Rdb_DataObserver Rdb_DataObserver
```

**Description**

Defines a struct for the data observer.

**Since**: 11


### Rdb_DetailsObserver

```
typedef void(* Rdb_DetailsObserver) (void *context, const Rdb_ChangeInfo **changeInfo, uint32_t count)
```

**Description**

Defines a callback used to return the details about the device-cloud data change.

**Since**: 11

**Parameters**

| Name | Description | 
| -------- | -------- |
| context | Pointer to the context of the data observer. | 
| changeInfo | Pointer to [Rdb_ChangeInfo](_rdb___change_info.md). | 
| count | Number of changed tables. | 

**See**

[Rdb_ChangeInfo](_rdb___change_info.md).


### Rdb_DistributedConfig

```
typedef struct Rdb_DistributedConfig Rdb_DistributedConfig
```

**Description**

Defines a struct for distributed configuration of a table.

**Since**: 11


### Rdb_DistributedType

```
typedef enum Rdb_DistributedType Rdb_DistributedType
```

**Description**

Defines an enum for distributed types.

**Since**: 11


### Rdb_KeyInfo

```
typedef struct Rdb_KeyInfo Rdb_KeyInfo
```

**Description**

Defines a struct for the primary key or row number of the row that changes.

**Since**: 11


### Rdb_Progress

```
typedef enum Rdb_Progress Rdb_Progress
```

**Description**

Defines an enum for device-cloud sync progresses.

**Since**: 11


### Rdb_ProgressCallback

```
typedef void(* Rdb_ProgressCallback) (void *context, Rdb_ProgressDetails *progressDetails)
```

**Description**

Defines a callback used to return the device-cloud sync progress.

**Since**: 11

**Parameters**

| Name | Description | 
| -------- | -------- |
| progressDetails | Details about the device-cloud sync progress. | 

**See**

[Rdb_ProgressDetails](_rdb___progress_details.md).


### Rdb_ProgressCode

```
typedef enum Rdb_ProgressCode Rdb_ProgressCode
```

**Description**

Defines an enum for device-cloud sync states.

**Since**: 11


### Rdb_ProgressDetails

```
typedef struct Rdb_ProgressDetails Rdb_ProgressDetails
```

**Description**

Defines a struct for statistics of the overall device-cloud sync (upload and download) tasks of an RDB store.

**Since**: 11


### Rdb_ProgressObserver

```
typedef struct Rdb_ProgressObserver Rdb_ProgressObserver
```

**Description**

Defines a struct for the observer for the device-cloud sync progress.

**Since**: 11


### Rdb_SecurityArea

```
typedef enum Rdb_SecurityArea Rdb_SecurityArea
```

**Description**

Defines an enum for security area levels of an RDB store.

**Since**: 11


### Rdb_Statistic

```
typedef struct Rdb_Statistic Rdb_Statistic
```

**Description**

Defines a struct for the device-cloud sync statistics of a database table.

**Since**: 11


### Rdb_SubscribeCallback

```
typedef union Rdb_SubscribeCallback Rdb_SubscribeCallback
```

**Description**

Defines a callback used to return the subscribed event.

**Since**: 11


### Rdb_SubscribeType

```
typedef enum Rdb_SubscribeType Rdb_SubscribeType
```

**Description**

Defines an enum for subscription types.

**Since**: 11


### Rdb_SyncCallback

```
typedef void(* Rdb_SyncCallback) (Rdb_ProgressDetails *progressDetails)
```

**Description**

Defines a callback for device-cloud sync.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| progressDetails | Statistics of device-cloud sync. |

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### Rdb_SyncMode

```
typedef enum Rdb_SyncMode Rdb_SyncMode
```

**Description**

Defines an enum for RDB sync modes.

**Since**: 11


### Rdb_TableDetails

```
typedef struct Rdb_TableDetails Rdb_TableDetails
```

**Description**

Defines a struct for statistics of device-cloud upload and download tasks of a database table.

**Since**: 11

## Enum Description


### OH_ColumnType

```
enum OH_ColumnType
```

**Description**

Enumerates the field types in an RDB store.

**Since**: 10

| Value | Description |
| -------- | -------- |
| TYPE_NULL | Null. |
| TYPE_INT64 | INT64. |
| TYPE_REAL | REAL. |
| TYPE_TEXT | TEXT. |
| TYPE_BLOB | BLOB. |
| TYPE_ASSET<sup>11+</sup> | ASSET (asset attachment).<br>This value is supported since API version 11. |
| TYPE_ASSETS<sup>11+</sup> | ASSETS (multiple asset attachments).<br>This value is supported since API version 11. |


### OH_OrderType

```
enum OH_OrderType
```

**Description**

Enumerates the sorting types.

**Since**: 10

| Value | Description |
| -------- | -------- |
| ASC | Ascending order. |
| DESC | Descending order. |


### OH_Rdb_ErrCode

```
enum OH_Rdb_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 10

| Value | Description |
| -------- | -------- |
| RDB_ERR | Execution failed. |
| RDB_OK | Execution successful. |
| E_BASE | Base of the error code. |
| RDB_E_NOT_SUPPORTED | The RDB store does not have this capability. |
| RDB_E_ERROR | Common exception. |
| RDB_E_INVALID_ARGS | Invalid parameter. |
| RDB_E_CANNOT_UPDATE_READONLY | Failed to update data because the RDB store is read-only. |
| RDB_E_REMOVE_FILE | Failed to delete the file. |
| RDB_E_EMPTY_TABLE_NAME | The table name is empty. |
| RDB_E_EMPTY_VALUES_BUCKET | The content of the KV pair is empty. |
| RDB_E_EXECUTE_IN_STEP_QUERY | The SQL statement executed during the query is incorrect. |
| RDB_E_INVALID_COLUMN_INDEX | The column index is invalid. |
| RDB_E_INVALID_COLUMN_TYPE | The column type is invalid. |
| RDB_E_EMPTY_FILE_NAME | The file name is empty. |
| RDB_E_INVALID_FILE_PATH | The file path is invalid. |
| RDB_E_TRANSACTION_IN_EXECUTE | Failed to start the transaction. |
| RDB_E_INVALID_STATEMENT | Failed to precompile the SQL statements. |
| RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION | Failed to perform a write operation in a read connection. |
| RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION | Failed to start the transaction in a read connection. |
| RDB_E_NO_TRANSACTION_IN_SESSION | The transaction to start does not exist in the database session. |
| RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION | Multiple queries are executed in a database session. |
| RDB_E_NO_ROW_IN_QUERY | The result set does not contain any record. |
| RDB_E_INVALID_BIND_ARGS_COUNT | The number of parameters bound in the SQL statement is invalid. |
| RDB_E_INVALID_OBJECT_TYPE | The object type is invalid. |
| RDB_E_INVALID_CONFLICT_FLAG | The conflict resolution type is invalid. |
| RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY | The HAVING keyword can be used only after GROUP BY. |
| RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET | The result set by step is not supported. |
| RDB_E_STEP_RESULT_SET_CROSS_THREADS | Failed to obtain the result set. |
| RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED | The result set query statement is not executed. |
| RDB_E_STEP_RESULT_IS_AFTER_LAST | The cursor of the result set is already in the last row. |
| RDB_E_STEP_RESULT_QUERY_EXCEEDED | The number of result set query times exceeds the limit. |
| RDB_E_STATEMENT_NOT_PREPARED | The SQL statement is not precompiled. |
| RDB_E_EXECUTE_RESULT_INCORRECT | The database execution result is incorrect. |
| RDB_E_STEP_RESULT_CLOSED | The result set has been closed. |
| RDB_E_RELATIVE_PATH | The file path is a relative path. |
| RDB_E_EMPTY_NEW_ENCRYPT_KEY | The new encrypt key is empty. |
| RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED | The RDB store is non-encrypted and cannot be changed. |
| RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY | The database does not respond when the database key is updated. |
| RDB_E_STEP_STATEMENT_NOT_INIT | The precompiled SQL statement is not initialized. |
| RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE | The WAL mode does not support the ATTACH operation. |
| RDB_E_CREATE_FOLDER_FAIL | Failed to create the folder. |
| RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL | Failed to build the SQL statement. |
| RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY | The database session does not provide a connection. |
| RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION | The transaction does not exist in the database session. |
| RDB_E_NOT_SUPPORT | The current operation is not supported. |
| RDB_E_INVALID_PARCEL | The current PARCEL is invalid. |
| RDB_E_QUERY_IN_EXECUTE | Failed to execute query. |
| RDB_E_SET_PERSIST_WAL | Failed to set the persistence of the database file in WAL mode. |
| RDB_E_DB_NOT_EXIST | The database does not exist. |
| RDB_E_ARGS_READ_CON_OVERLOAD | The number of read connections to set is greater than the limit. |
| RDB_E_WAL_SIZE_OVER_LIMIT | The WAL log file size exceeds the default value. |
| RDB_E_CON_OVER_LIMIT | The number of database connections has reached the limit. |


### OH_Rdb_SecurityLevel

```
enum OH_Rdb_SecurityLevel
```

**Description**

Enumerates the RDB store security levels.

**Since**: 10

| Value | Description |
| -------- | -------- |
| S1 | The security level of the RDB store is low.<br>If data leakage occurs, minor impact will be caused. |
| S2 | The security level of the RDB store is medium.<br>If data leakage occurs, moderate impact will be caused. |
| S3 | The security level of the RDB store is high.<br>If data leakage occurs, major impact will be caused. |
| S4 | The security level of the RDB store is critical.<br>If data leakage occurs, critical impact will be caused. |


### Rdb_ChangeType

```
enum Rdb_ChangeType
```

**Description**

Enumerates the data change types.

**Since**: 11

| Value | Description |
| -------- | -------- |
| RDB_DATA_CHANGE | Data change. |
| RDB_ASSET_CHANGE | Asset change. |


### Rdb_DistributedType

```
enum Rdb_DistributedType
```

**Description**

Enumerates the distributed types.

**Since**: 11

| Value | Description |
| -------- | -------- |
| RDB_DISTRIBUTED_CLOUD | Distributed database tables for device-cloud sync. |


### Rdb_Progress

```
enum Rdb_Progress
```

**Description**

Enumerates the device-cloud sync progresses.

**Since**: 11

| Value | Description |
| -------- | -------- |
| RDB_SYNC_BEGIN | The device-cloud sync starts. |
| RDB_SYNC_IN_PROGRESS | The device-cloud sync is in progress. |
| RDB_SYNC_FINISH | The device-cloud sync is finished. |


### Rdb_ProgressCode

```
enum Rdb_ProgressCode
```

**Description**

Enumerates the device-cloud sync states.

**Since**: 11

| Value | Description |
| -------- | -------- |
| RDB_SUCCESS | The device-cloud sync is successful. |
| RDB_UNKNOWN_ERROR | An unknown error occurs during the device-cloud sync. |
| RDB_NETWORK_ERROR | A network error occurs during the device-cloud sync. |
| RDB_CLOUD_DISABLED | The cloud is unavailable. |
| RDB_LOCKED_BY_OTHERS | The device-cloud sync of another device is being performed. |
| RDB_RECORD_LIMIT_EXCEEDED | The number of records or size of the data to be synchronized exceeds the maximum. The maximum value is configured on the cloud. |
| RDB_NO_SPACE_FOR_ASSET | The remaining cloud space is less than the size of the data to be synchronized. |


### Rdb_SecurityArea

```
enum Rdb_SecurityArea
```

**Description**

Enumerates the security area levels of an RDB store.

**Since**: 11

| Value | Description |
| -------- | -------- |
| RDB_SECURITY_AREA_EL1 | Security area level 1. |
| RDB_SECURITY_AREA_EL2 | Security area level 2. |
| RDB_SECURITY_AREA_EL3 | Security area level 3. |
| RDB_SECURITY_AREA_EL4 | Security area level 4. |


### Rdb_SubscribeType

```
enum Rdb_SubscribeType
```

**Description**

Enumerates the subscription types.

**Since**: 11

| Value | Description |
| -------- | -------- |
| RDB_SUBSCRIBE_TYPE_CLOUD | Subscription of cloud data changes. |
| RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS | Subscription of cloud data change details. |
| RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS<sup>12+</sup>  | Subscribe to details of the local data change. This value is available since API version 12. |


### Rdb_SyncMode

```
enum Rdb_SyncMode
```

**Description**

Enumerates the RDB sync modes.

**Since**: 11

| Value | Description |
| -------- | -------- |
| RDB_SYNC_MODE_TIME_FIRST | Synchronize with the data with the latest modification time. |
| RDB_SYNC_MODE_NATIVE_FIRST | Synchronize data from a local device to the cloud. |
| RDB_SYNC_MODE_CLOUD_FIRST | Synchronize data from the cloud to a local device. |


## Function Description


### OH_Rdb_Backup()

```
int OH_Rdb_Backup (OH_Rdb_Store *store, const char *databasePath )
```

**Description**

Backs up an RDB store in the specified directory.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| databasePath | Pointer to the destination directory in which the RDB store is backed up. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_BeginTransaction()

```
int OH_Rdb_BeginTransaction (OH_Rdb_Store *store)
```

**Description**

Starts the transaction before executing the SQL statement.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CloseStore()

```
int OH_Rdb_CloseStore (OH_Rdb_Store *store)
```

**Description**

Closes an [OH_Rdb_Store](_o_h___rdb___store.md) object to reclaim the memory occupied.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CloudSync()

```
int OH_Rdb_CloudSync (OH_Rdb_Store *store, Rdb_SyncMode mode, const char *tables, int count, const Rdb_ProgressObserver *observer )
```

**Description**

Performs device-cloud sync.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| mode | Sync mode [Rdb_SyncMode](#rdb_syncmode).|
| tables | Pointer to the names of the tables to be synchronized. | 
| count | Number of tables to synchronize. If the value is **0**, all tables in the database are synchronized. | 
| observer | Observer [Rdb_ProgressObserver](_rdb___progress_observer.md) of the device-cloud sync progress. | 

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Commit()

```
int OH_Rdb_Commit (OH_Rdb_Store *store)
```

**Description**

Commits the executed SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CreatePredicates()

```
OH_Predicates* OH_Rdb_CreatePredicates (const char *table)
```

**Description**

Creates an [OH_Predicates](_o_h___predicates.md) instance.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| table | Pointer to the name of the database table. |

**Returns**

Returns the pointer to the [OH_Predicates](_o_h___predicates.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_Predicates](_o_h___predicates.md).


### OH_Rdb_CreateValueObject()

```
OH_VObject* OH_Rdb_CreateValueObject ()
```

**Description**

Creates an [OH_VObject](_o_h___v_object.md) instance.

**Since**: 10

**Returns**

Returns the pointer to the [OH_VObject](_o_h___v_object.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### OH_Rdb_CreateValuesBucket()

```
OH_VBucket* OH_Rdb_CreateValuesBucket ()
```

**Description**

Creates an [OH_VBucket](_o_h___v_bucket.md) instance.

**Since**: 10

**Returns**

Returns the pointer to the [OH_VBucket](_o_h___v_bucket.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### OH_Rdb_Delete()

```
int OH_Rdb_Delete (OH_Rdb_Store *store, OH_Predicates *predicates )
```

**Description**

Deletes data from an RDB store based on specified conditions.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the deletion conditions. |

**Returns**

Returns the number of affected rows if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).


### OH_Rdb_DeleteStore()

```
int OH_Rdb_DeleteStore (const OH_Rdb_Config *config)
```

**Description**

Deletes an RDB store with the specified database file configuration.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| config | Pointer to the configuration of the database. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.


### OH_Rdb_Execute()

```
int OH_Rdb_Execute (OH_Rdb_Store *store, const char *sql )
```

**Description**

Executes an SQL statement but returns no value.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| sql | Pointer to the SQL statement to execute. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_ExecuteQuery()

```
OH_Cursor* OH_Rdb_ExecuteQuery (OH_Rdb_Store *store, const char *sql )
```

**Description**

Executes the SQL statement to query data in an RDB store.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| sql | Pointer to the SQL statement to execute. |

**Returns**

Returns the pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_FindModifyTime()

```
OH_Cursor* OH_Rdb_FindModifyTime (OH_Rdb_Store *store, const char *tableName, const char *columnName, OH_VObject *values )
```

**Description**

Obtains the last modification time of a table in an RDB store.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| tableName | Pointer to the target distributed database table. |
| columnName | Pointer to the column of the database table to query. |
| values | Pointer to the primary keys of the rows to query. If the database table has no primary key, **rowid** must be passed in through **columnName**. In this case, **values** specifies the row number of the database table to query. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetOrOpen()

```
OH_Rdb_Store* OH_Rdb_GetOrOpen (const OH_Rdb_Config *config, int *errCode )
```

**Description**

Obtains an [OH_Rdb_Store](_o_h___rdb___store.md) instance for RDB store operations.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| config | Pointer to the [OH_Rdb_Config](_o_h___rdb___config.md) instance, which specifies the database configuration. |
| errCode | Function execution status. |

**Returns**

Returns the pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Config](_o_h___rdb___config.md), [OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetTableDetails()

```
Rdb_TableDetails* OH_Rdb_GetTableDetails (Rdb_ProgressDetails *progress, int32_t version )
```

**Description**

Obtains the device-cloud sync statistics of a table.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| progress | Pointer to the **OH_ProgressDetails** instance. |
| version | Version of [Rdb_ProgressDetails](_rdb___progress_details.md). |

**Returns**

Returns a pointer to [Rdb_TableDetails](_rdb___table_details.md) if the operation is successful; returns null otherwise.

**See**

[Rdb_ProgressDetails](_rdb___progress_details.md)

[Rdb_TableDetails](_rdb___table_details.md)


### OH_Rdb_GetVersion()

```
int OH_Rdb_GetVersion (OH_Rdb_Store *store, int *version )
```

**Description**

Obtains the RDB store version.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| version |  Pointer to the version obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Insert()

```
int OH_Rdb_Insert (OH_Rdb_Store *store, const char *table, OH_VBucket *valuesBucket )
```

**Description**

Inserts a row of data into a table.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| table | Pointer to the target table. |
| valuesBucket | Pointer to the data [OH_VBucket](_o_h___v_bucket.md) to insert. |

**Returns**

Returns the row ID if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_VBucket](_o_h___v_bucket.md).

### OH_Rdb_LockRow()

```
int OH_Rdb_LockRow (OH_Rdb_Store *store, OH_Predicates *predicates )
```

**Description**

Locks data in an RDB store based on specified conditions. The locked data will be blocked from the device-cloud sync.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the lock conditions. | 

**Returns**

Result of the lock operation.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).

### OH_Rdb_Query()

```
OH_Cursor* OH_Rdb_Query (OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length )
```

**Description**

Queries data in an RDB store based on specified conditions.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the query conditions. |
| columnNames | Pointer to the columns to query. If this parameter is not specified, data of columns will be queried. |
| length | Length of the **columnNames** array. If <b>length</b> is greater than the length of <b>columnNames</b> array, out-of-bounds access occurs. |

**Returns**

Returns the pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md), [OH_Cursor](_o_h___cursor.md).

### OH_Rdb_QueryLockedRow()

```
OH_Cursor *OH_Rdb_QueryLockedRow (OH_Rdb_Store *store, OH_Predicates *predicates, const char *const *columnNames, int length )
```

**Description**

Queries the locked data in an RDB store.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the query conditions. | 
| columnNames | Pointer to the columns to query. If this parameter is not specified, data of columns will be queried. | 
| length | Length of the **columnNames** array. If <b>length</b> is greater than the length of <b>columnNames</b> array, out-of-bounds access occurs. | 

**Returns**

Returns the pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md), [OH_Cursor](_o_h___cursor.md).

### OH_Rdb_Restore()

```
int OH_Rdb_Restore (OH_Rdb_Store *store, const char *databasePath )
```

**Description**

Restores an RDB store from the specified database backup file.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| databasePath | Pointer to the destination directory in which the RDB store is backed up. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_RollBack()

```
int OH_Rdb_RollBack (OH_Rdb_Store *store)
```

**Description**

Rolls back the SQL statements executed.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetDistributedTables()

```
int OH_Rdb_SetDistributedTables (OH_Rdb_Store *store, const char *tables[], uint32_t count, Rdb_DistributedType type, const Rdb_DistributedConfig * config )
```

**Description**

Sets distributed database tables.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| tables | Pointer to the names of the distributed tables to set. |
| count | Number of distributed database tables to be set. |
| type | [Rdb_DistributedType](#rdb_distributedtype). |
| config | Configuration of the distributed mode. For details, see [Rdb_DistributedConfig](_rdb___distributed_config.md). |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetVersion()

```
int OH_Rdb_SetVersion (OH_Rdb_Store *store, int version )
```

**Description**

Sets the RDB store version.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| version | Version to set. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Subscribe()

```
int OH_Rdb_Subscribe (OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer )
```

**Description**

Registers an observer for an RDB store. When data in the RDB store changes, a callback will be invoked to return the data changes.

**Since**: 11

**Parameters**

| Name | Description | 
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| type | Subscription type defined in [Rdb_SubscribeType](#rdb_subscribetype). | 
| observer | Pointer to the [Rdb_DataObserver](_rdb___data_observer.md) instance. | 

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_DataObserver](_rdb___data_observer.md).


### OH_Rdb_SubscribeAutoSyncProgress()

```
int OH_Rdb_SubscribeAutoSyncProgress (OH_Rdb_Store *store, const Rdb_ProgressObserver *observer )
```

**Description**

Subscribes to the automatic sync progress of an RDB store. The registered callback will be invoked to return the automatic sync progress.

**Since**: 11

**Parameters**

| Name | Description | 
| -------- | -------- |
| store | Pointer to the target [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| observer | Pointer to the [Rdb_ProgressObserver](_rdb___progress_observer.md) instance, which invokes the callback to return the automatic sync progress. | 

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_ProgressObserver](_rdb___progress_observer.md).

### OH_Rdb_UnlockRow()

```
int OH_Rdb_UnlockRow (OH_Rdb_Store *store, OH_Predicates *predicates )
```

**Description**

Unlocks data in an RDB store based on the specified conditions.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the unlock conditions. | 

**Returns**

Result of the unlock operation.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).

### OH_Rdb_Unsubscribe()

```
int OH_Rdb_Unsubscribe (OH_Rdb_Store *store, Rdb_SubscribeType type, const Rdb_DataObserver *observer )
```

**Description**

Unregisters the observer of the specified type.

**Since**: 11

**Parameters**

| Name | Description | 
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| type | Subscription type defined in [Rdb_SubscribeType](#rdb_subscribetype). | 
| observer | Pointer to the [Rdb_DataObserver](_rdb___data_observer.md) instance. If this parameter is **nullptr**, all observers of this type will be unregistered. | 

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_DataObserver](_rdb___data_observer.md).


### OH_Rdb_UnsubscribeAutoSyncProgress()

```
int OH_Rdb_UnsubscribeAutoSyncProgress (OH_Rdb_Store *store, const Rdb_ProgressObserver *observer )
```

**Description**

Unsubscribes from the automatic sync process of an RDB store.

**Since**: 11

**Parameters**

| Name | Description | 
| -------- | -------- |
| store | Pointer to the target [OH_Rdb_Store](_o_h___rdb___store.md) instance. | 
| observer | Pointer to [Rdb_ProgressObserver](_rdb___progress_observer.md). If the pointer is null, all callbacks for the automatic sync process will be unregistered. | 

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_ProgressObserver](_rdb___progress_observer.md).


### OH_Rdb_Update()

```
int OH_Rdb_Update (OH_Rdb_Store *store, OH_VBucket *valuesBucket, OH_Predicates *predicates )
```

**Description**

Updates data in an RDB store based on specified conditions.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance. |
| valuesBucket | Pointer to the new data [OH_VBucket](_o_h___v_bucket.md) to be updated to the table. |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, specifying the update conditions. |

**Returns**

Returns the number of affected rows if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Bucket](_o_h___v_bucket.md), [OH_Predicates](_o_h___predicates.md).


### OH_VBucket_PutAsset()

```
int OH_VBucket_PutAsset (OH_VBucket *bucket, const char *field, OH_Asset *value )
```

**Description**

Puts an **OH_Asset** object into the [OH_VBucket](_o_h___v_bucket.md) object with the given column name.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |
| field | Pointer to the column name in the database table. |
| value | Pointer to the value to put. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### OH_VBucket_PutAssets()

```
int OH_VBucket_PutAssets (OH_VBucket *bucket, const char *field, OH_Asset **value, int count )
```

**Description**

Puts an array of **OH_Asset** objects into the [OH_VBucket](_o_h___v_bucket.md) object with the given column name.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |
| field | Pointer to the column name in the database table. |
| value | Pointer to the value to put. |
| count | Number of elements in the **OH_Asset** object array. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).

## Variable Description


### andOperate

```
OH_Predicates *(*andOperate) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add the AND operator to the predicates.

This method is equivalent to **AND** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |

**Returns**

Returns the predicates with the AND operator.

**See**

[OH_Predicates](_o_h___predicates.md).


### area

```
int OH_Rdb_Config::area
```

**Description**

Pointer to the function used to set [Rdb_SecurityArea](#rdb_securityarea).

**Since**: 11


### beginWrap

```
OH_Predicates *(*beginWrap) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add a left parenthesis to the predicates.

This method is equivalent to "(" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |

**Returns**

Returns the predicates with a left parenthesis.

**See**

[OH_Predicates](_o_h___predicates.md).


### between

```
OH_Predicates *(*between) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is within the specified range.

This method is equivalent to **BETWEEN** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values. |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### briefObserver

```
Rdb_BriefObserver Rdb_SubscribeCallback::briefObserver
```

**Description**

Callback used to return the device-cloud data change event.


### bundleName

```
const char* OH_Rdb_Config::bundleName
```

**Description**

Bundle name.


### callback [1/2]

```
Rdb_SubscribeCallback Rdb_DataObserver::callback
```

**Description**

Callback of the data observer.


### callback [2/2]

```
Rdb_ProgressCallback Rdb_ProgressObserver::callback
```

**Description**

Callback used to return the device-cloud sync progress.


### capability

```
uint16_t OH_VBucket::capability
```

**Description**

Number of the KV pairs in the struct.


### ChangeType

```
int Rdb_ChangeInfo::ChangeType
```

**Description**

Type of the data changed, which can be data or asset.


### clear [1/2]

```
OH_Predicates *(*clear) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to clear a predicates instance.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |

**Returns**

Returns the cleared predicates.

**See**

[OH_Predicates](_o_h___predicates.md).


### clear [2/2]

```
int(*clear) (OH_VBucket *bucket)
```

**Description**

Pointer to the function used to clear an [OH_VBucket](_o_h___v_bucket.md) object.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### code

```
int Rdb_ProgressDetails::code
```

**Description**

Device-cloud sync state.


### context [1/2]

```
void* Rdb_DataObserver::context
```

**Description**

Context of the data observer.


### context [2/2]

```
void* Rdb_ProgressObserver::context
```

**Description**

Context of the device-cloud sync progress observer.


### count

```
int Rdb_KeyInfo::count
```

**Description**

Number of changed primary keys or row numbers.


### dataBaseDir

```
const char* OH_Rdb_Config::dataBaseDir
```

**Description**

Path of the database file.


### deleted

```
Rdb_KeyInfo Rdb_ChangeInfo::deleted
```

**Description**

Location where data is deleted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the deleted data.


### destroy [1/4]

```
int(*destroy) (OH_Cursor *cursor)
```

**Description**

Pointer to the function used to destroy a result set.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### destroy [2/4]

```
int(*destroy) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to destroy an [OH_Predicates](_o_h___predicates.md) object to reclaim the memory occupied.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Predicates](_o_h___predicates.md).


### destroy [3/4]

```
int(*destroy) (OH_VBucket *bucket)
```

**Description**

Pointer to the function used to destroy an [OH_VBucket](_o_h___v_bucket.md) object to reclaim the memory occupied.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### destroy [4/4]

```
int(*destroy) (OH_VObject *valueObject)
```

**Description**

Pointer to the function used to destroy an [OH_VObject](_o_h___v_object.md) object to reclaim the memory occupied.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### detailsObserver

```
Rdb_DetailsObserver Rdb_SubscribeCallback::detailsObserver
```

**Description**

Callback used to return the details about the device-cloud data change.


### distinct

```
OH_Predicates *(*distinct) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to set a predicates object to filter out duplicate records.

This method is equivalent to **DISTINCT** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### download

```
Rdb_Statistic Rdb_TableDetails::download
```

**Description**

Statistics of the device-cloud download tasks.


### endWrap

```
OH_Predicates *(*endWrap) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add a right parenthesis to the predicates.

This method is equivalent to ")" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |

**Returns**

Returns the predicates object with a right parenthesis.

**See**

[OH_Predicates](_o_h___predicates.md).


### equalTo

```
OH_Predicates *(*equalTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is equal to the specified value.

This method is equivalent to "=" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### failed

```
int Rdb_Statistic::failed
```

**Description**

Number of rows that failed to be synchronized between the device and cloud in the database table.


### getAsset

```
int(*getAsset) (OH_Cursor *cursor, int32_t columnIndex, Data_Asset *value)
```

**Description**

Pointer to the function used to obtain the value of the asset type based on the specified column and the current row.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| value | Pointer to the value obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getAssets

```
int(*getAssets) (OH_Cursor *cursor, int32_t columnIndex, Data_Asset **value, uint32_t length)
```

**Description**

Pointer to the function used to obtain the values in the form of an asset array based on the specified column and the current row.

**Since**: 11

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| value | Pointer to the value obtained. |
| length | Length of an asset array. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getBlob

```
int(*getBlob) (OH_Cursor *cursor, int32_t columnIndex, unsigned char *value, int length)
```

**Description**

Pointer to the function used to obtain the values in the form of a byte array based on the specified column and the current row.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| value | Pointer to the values in the form of a byte array obtained. |
| length | Length of the value, which can be obtained by **getSize()**. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getColumnCount

```
int(*getColumnCount) (OH_Cursor *cursor, int *count)
```

**Description**

Pointer to the function used to obtain the number of columns in the result set.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| count | Pointer to the number of columns in the result set obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getColumnIndex

```
int(*getColumnIndex) (OH_Cursor *cursor, const char *name, int *columnIndex)
```

**Description**

Pointer to the function used to obtain the column index based on the specified column name.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| name | Pointer to the column name in the result set. |
| columnIndex | Pointer to the column index obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getColumnName

```
int(*getColumnName) (OH_Cursor *cursor, int32_t columnIndex, char *name, int length)
```

**Description**

Pointer to the function used to obtain the column name based on the specified column index.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| name | Pointer to the column name obtained. |
| length | Length of a column name. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getColumnType

```
int(*getColumnType) (OH_Cursor *cursor, int32_t columnIndex, OH_ColumnType *columnType)
```

**Description**

Pointer to the function used to obtain the column type based on the specified column index.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| columnType | Pointer to the [OH_ColumnType](#oh_columntype) obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md), [OH_ColumnType](#oh_columntype).


### getInt64

```
int(*getInt64) (OH_Cursor *cursor, int32_t columnIndex, int64_t *value)
```

**Description**

Pointer to the function used to obtain the value of the int64_t type based on the specified column and the current row.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| value | Pointer to the value obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getReal

```
int(*getReal) (OH_Cursor *cursor, int32_t columnIndex, double *value)
```

**Description**

Pointer to the function used to obtain the value of the double type based on the specified column and the current row.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| value | Pointer to the value obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getRowCount

```
int(*getRowCount) (OH_Cursor *cursor, int *count)
```

**Description**

Pointer to the function used to obtain the number of rows in the result set.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| count | Pointer to the number of columns in the result set obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getSize

```
int(*getSize) (OH_Cursor *cursor, int32_t columnIndex, size_t *size)
```

**Description**

Pointer to the function used to obtain information about the memory required when the column data type in the result set is **BLOB** or **TEXT**.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| size | Pointer to the memory size obtained. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getText

```
int(*getText) (OH_Cursor *cursor, int32_t columnIndex, char *value, int length)
```

**Description**

Pointer to the function used to obtain the value of the string type based on the specified column and the current row.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| value | Pointer to the value of the string type obtained. |
| length | Length of the value, which can be obtained by **getSize()**. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### goToNextRow

```
int(*goToNextRow) (OH_Cursor *cursor)
```

**Description**

Pointer to the function used to go to the next row of the result set.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### greaterThan

```
OH_Predicates *(*greaterThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value greater than the specified value.

This method is equivalent to "&gt;" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### greaterThanOrEqualTo

```
OH_Predicates *(*greaterThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value greater than or equal to the specified value.

This method is equivalent to "&gt;=" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### groupBy

```
OH_Predicates *(*groupBy) (OH_Predicates *predicates, char const *const *fields, int length)
```

**Description**

Pointer to the function used to set a predicates object to group rows that have the same value into summary rows.

This method is equivalent to **GROUP BY** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| fields | Pointer to the names of the columns by which the records are grouped. |
| length | Length of the **fields** value. |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### id [1/5]

```
int64_t OH_Cursor::id
```

**Description**

Unique identifier of the **OH_Cursor** struct.


### id [2/5]

```
int64_t OH_Predicates::id
```

**Description**

Unique identifier of the **OH_Predicates** struct.


### id [3/5]

```
int64_t OH_VObject::id
```

**Description**

Unique identifier of the **OH_VObject** struct.


### id [4/5]

```
int64_t OH_VBucket::id
```

**Description**

Unique identifier of the **OH_VBucket** struct.


### id [5/5]

```
int64_t OH_Rdb_Store::id
```

**Description**

Unique identifier of the **OH_Rdb_Store** struct.


### in

```
OH_Predicates *(*in) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with the value within the specified range.

This method is equivalent to **IN** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value range.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### inserted

```
Rdb_KeyInfo Rdb_ChangeInfo::inserted
```

**Description**

Location where data is inserted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the inserted data.


### integer

```
uint64_t Rdb_KeyInfo::Rdb_KeyData::integer
```

**Description**

Data of the uint64_t type.


### isAutoSync

```
bool Rdb_DistributedConfig::isAutoSync
```

**Description**

Whether the table supports automatic sync.


### isEncrypt

```
bool OH_Rdb_Config::isEncrypt
```

**Description**

Whether to encrypt the RDB store.


### isNotNull

```
OH_Predicates *(*isNotNull) (OH_Predicates *predicates, const char *field)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is not null.

This method is equivalent to **IS NOT NULL** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### isNull [1/2]

```
int(*isNull) (OH_Cursor *cursor, int32_t columnIndex, bool *isNull)
```

**Description**

Pointer to the function used to check whether the value in the specified column is null.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance. |
| columnIndex | Index of the column. The index value starts from **0**. |
| isNull | Pointer to the value returned. The value **true** means the value is null; the value **false** means the opposite. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### isNull [2/2]

```
OH_Predicates *(*isNull) (OH_Predicates *predicates, const char *field)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is null.

This method is equivalent to **IS NULL** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### lessThan

```
OH_Predicates *(*lessThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value less than the specified value.

This method is equivalent to "&lt;" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### lessThanOrEqualTo

```
OH_Predicates *(*lessThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value less than or equal to the specified value.

This method is equivalent to "&lt;=" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### like

```
OH_Predicates *(*like) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match a string that is similar to the specified value.

This method is equivalent to **LIKE** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### limit

```
OH_Predicates *(*limit) (OH_Predicates *predicates, unsigned int value)
```

**Description**

Pointer to the function used to set a predicates object to specify the maximum number of records.

This method is equivalent to **LIMIT** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| value | Maximum number of data records. |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### moduleName

```
const char* OH_Rdb_Config::moduleName
```

**Description**

Module name. 


### notBetween

```
OH_Predicates *(*notBetween) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is out of the specified range.

This method is equivalent to **NOT BETWEEN** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notEqualTo

```
OH_Predicates *(*notEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is not equal to the specified value.

This method is equivalent to "!=" in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notIn

```
OH_Predicates *(*notIn) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with the value out of the specified range.

This method is equivalent to **NOT IN** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value range to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### offset

```
OH_Predicates *(*offset) (OH_Predicates *predicates, unsigned int rowOffset)
```

**Description**

Pointer to the function used to set a predicates object to specify the start position of the returned result.

This method is equivalent to **OFFSET** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| rowOffset | Start position of the returned result. The value is a positive integer. |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### orderBy

```
OH_Predicates *(*orderBy) (OH_Predicates *predicates, const char *field, OH_OrderType type)
```

**Description**

Pointer to the function used to set a predicates object to sort the values in a column in ascending or descending order.

This method is equivalent to **ORDER BY** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |
| field | Pointer to the column name in the database table. |
| type | Sorting type [OH_OrderType](#oh_ordertype). |

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_OrderType](#oh_ordertype).


### orOperate

```
OH_Predicates *(*orOperate) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add the OR operator to the predicates.

This method is equivalent to **OR** in SQL statements.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance. |

**Returns**

Returns the predicates with the OR operator.

**See**

[OH_Predicates](_o_h___predicates.md).


### putBlob

```
int(*putBlob) (OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)
```

**Description**

Pointer to the function used to put a const uint8_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |
| field | Pointer to the column name in the database table. |
| value | Pointer to the value to put. |
| size | Length of the value. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### putDouble

```
int(*putDouble) (OH_VObject *valueObject, double *value, uint32_t count)
```

**Description**

Pointer to the function used to convert a single parameter or an array of the double type into a value of the [OH_VObject](_o_h___v_object.md) type.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance. |
| value | Pointer to the data to covert. |
| count | If **value** points to a single parameter, **count** is **1**. If **value** points to an array, **count** specifies the length of the array. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### putInt64 [1/2]

```
int(*putInt64) (OH_VBucket *bucket, const char *field, int64_t value)
```

**Description**

Pointer to the function used to put an int64_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |
| field | Pointer to the column name in the database table. |
| value | Value to put.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### putInt64 [2/2]

```
int(*putInt64) (OH_VObject *valueObject, int64_t *value, uint32_t count)
```

**Description**

Pointer to the function used to convert a single parameter or an array of the int64 type into a value of the [OH_VObject](_o_h___v_object.md) type.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance. |
| value | Pointer to the data to covert. |
| count | If **value** points to a single parameter, **count** is **1**. If **value** points to an array, **count** specifies the length of the array. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### putNull

```
int(*putNull) (OH_VBucket *bucket, const char *field)
```

**Description**

Pointer to the function used to put a null value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |
| field | Pointer to the column name in the database table. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### putReal

```
int(*putReal) (OH_VBucket *bucket, const char *field, double value)
```

**Description**

Pointer to the function used to put a double value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |
| field | Pointer to the column name in the database table. |
| value | Value to put.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### putText [1/2]

```
int(*putText) (OH_VBucket *bucket, const char *field, const char *value)
```

**Description**

Pointer to the function used to put a char value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance. |
| field | Pointer to the column name in the database table. |
| value | Pointer to the value to put. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### putText [2/2]

```
int(*putText) (OH_VObject *valueObject, const char *value)
```

**Description**

Pointer to the function used to convert a character array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance. |
| value | Pointer to the character array to convert. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### putTexts

```
int(*putTexts) (OH_VObject *valueObject, const char **value, uint32_t count)
```

**Description**

Pointer to the function used to convert a string array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.

**Since**: 10

**Parameters**

| Name | Description |
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance. |
| value | Pointer to the string array to convert. |
| count | Length of the string array to convert. |

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### real

```
double Rdb_KeyInfo::Rdb_KeyData::real
```

**Description**

Data of the double type.


### remained

```
int Rdb_Statistic::remained
```

**Description**

Number of rows that are not executed for device-cloud sync in the database table.


### schedule

```
int Rdb_ProgressDetails::schedule
```

**Description**

Device-cloud sync process.


### securityLevel

```
int OH_Rdb_Config::securityLevel
```

**Description**

RDB store security level. For details, see [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel).


### selfSize

```
int OH_Rdb_Config::selfSize
```

**Description**

Size of the struct.


### storeName

```
const char* OH_Rdb_Config::storeName
```

**Description**

Name of the RDB store.


### successful

```
int Rdb_Statistic::successful
```

**Description**

Number of rows that are successfully synchronized between the device and cloud in the database table.


### table

```
const char* Rdb_TableDetails::table
```

**Description**

Database table name.


### tableLength

```
int32_t Rdb_ProgressDetails::tableLength
```

**Description**

Number of the tables synchronized between the device and cloud.


### tableName

```
const char* Rdb_ChangeInfo::tableName
```

**Description**

Name of the table with data changes.


### text

```
const char* Rdb_KeyInfo::Rdb_KeyData::text
```

**Description**

Data of the char \* type.


### total

```
int Rdb_Statistic::total
```

**Description**

Total number of rows to be synchronized between the device and cloud in the database table.


### type

```
int Rdb_KeyInfo::type
```

**Description**

Type ([OH_ColumnType](#oh_columntype)) of the primary key.


### updated

```
Rdb_KeyInfo Rdb_ChangeInfo::updated
```

**Description**

Location where data is updated. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the updated data.


### upload

```
Rdb_Statistic Rdb_TableDetails::upload
```

**Description**

Statistics of the device-cloud upload tasks.


### version [1/3]

```
int Rdb_DistributedConfig::version
```

**Description**

Version of the **Rdb_DistributedConfig** struct.


### version [2/3]

```
int Rdb_ChangeInfo::version
```

**Description**

Version of the **Rdb_DistributedConfig** struct.


### version [3/3]

```
int Rdb_ProgressDetails::version
```

**Description**

Version of the **OH_TableDetails** struct.

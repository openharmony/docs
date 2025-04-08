# RDB


## Overview

The relational database (RDB) store manages data based on relational models. The system provides mechanisms for local database management based on the underlying SQLite. You can use the APIs to perform operations, such as adding, deleting, modifying, and querying data, and directly executing SQL statements to satisfy different needs in complicated scenarios.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 10


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_cursor.h](oh__cursor_8h.md) | Defines APIs for accessing the result set obtained by querying an RDB store.<br>**File to include**: <database/rdb/oh_cursor.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_data_value.h](oh__data__value_8h.md) | Defines APIs and enums related to a single data value.<br>Since API version 18, **OH_ColumnType** is moved from **oh_cursor.h** to this file. This type is supported in versions earlier than API version 18 and can be used in all versions.<br>**File to include**: <database/rdb/oh_data_value.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_data_values.h](oh__data__values_8h.md) | Defines APIs and enums related to multiple data values.<br>**File to include**: <database/rdb/oh_data_values.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_data_values_buckets.h](oh__data__values__buckets_8h.md) | Defines structs, APIs, and enums related to stored data values.<br>**File to include**: <database/rdb/oh_data_values_buckets.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_predicates.h](oh__predicates_8h.md) | Defines the predicates for RDB store operations.<br>**File to include**: <database/rdb/oh_predicates.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_rdb_transaction.h](oh__rdb__transaction_8h.md) | Defines APIs and enums related to transactions.<br>**File to include**: <database/rdb/oh_rdb_transaction.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_rdb_types.h](oh__rdb__types_8h.md) | Defines types related to data values.<br>**File to include**: <database/rdb/oh_rdb_types.h><br>**Library**: libnative_rdb_ndk.z.so<br>| 
| [oh_value_object.h](oh__value__object_8h.md) | Defines the APIs for type conversion.<br>**File to include**: <database/rdb/oh_value_object.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [oh_values_bucket.h](oh__values__bucket_8h.md) | Defines the types of the key and value in a key-value (KV) pair.<br>**File to include**: <database/rdb/oh_values_bucket.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [relational_store.h](relational__store_8h.md) | Provides APIs for managing data in an RDB store. The APIs not marked as supporting vector stores are available only to RDB stores.<br>**File to include**: <database/rdb/relational_store.h><br>**Library**: libnative_rdb_ndk.z.so<br>|
| [relational_store_error_code.h](relational__store__error__code_8h.md) | Defines the error codes used for RDB stores.<br>**File to include**: <database/rdb/relational_store_error_code.h><br>**Library**: libnative_rdb_ndk.z.so|


### Structs

| Name| Description|
| -------- | -------- |
| [OH_Cursor](_o_h___cursor.md) | Defines a result set.|
| [OH_Predicates](_o_h___predicates.md) | Defines a **predicates** object.|
| [OH_VObject](_o_h___v_object.md) | Defines the allowed data types of the fields.|
| [OH_VBucket](_o_h___v_bucket.md) | Defines the types of the key and value in a KV pair.|
| [OH_Rdb_Config](_o_h___rdb___config.md) | Defines the configuration of an RDB store.|
| [OH_Rdb_Store](_o_h___rdb___store.md) | Defines the RDB store type.|
| [Rdb_DistributedConfig](_rdb___distributed_config.md) | Defines the distributed configuration of a table.|
| [Rdb_KeyInfo](_rdb___key_info.md) | Defines the primary key or number of the row changed.|
| [Rdb_KeyInfo::Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) | Defines the changed data.|
| [Rdb_ChangeInfo](_rdb___change_info.md) | Defines the details about the device-cloud sync process.|
| [Rdb_SubscribeCallback](union_rdb___subscribe_callback.md) | Defines a callback used to return the subscribed event.|
| [Rdb_DataObserver](_rdb___data_observer.md) | Defines the data observer.|
| [Rdb_Statistic](_rdb___statistic.md) | Defines the device-cloud sync statistics of a table.|
| [Rdb_TableDetails](_rdb___table_details.md) | Defines the statistics of device-cloud upload and download tasks of a table.|
| [Rdb_ProgressDetails](_rdb___progress_details.md) | Defines the statistics of the overall device-cloud sync (upload and download) tasks of an RDB store.|
| [Rdb_ProgressObserver](_rdb___progress_observer.md) | Defines the observer of the device-cloud sync progress.|


### Macros

| Name| Description|
| -------- | -------- |
| [DISTRIBUTED_CONFIG_VERSION](#distributed_config_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_DistributedConfig](_rdb___distributed_config.md).|
| [DISTRIBUTED_CHANGE_INFO_VERSION](#distributed_change_info_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_ChangeInfo](_rdb___change_info.md).|
| [DISTRIBUTED_PROGRESS_DETAIL_VERSION](#distributed_progress_detail_version)&nbsp;&nbsp;&nbsp;1 | Version of [Rdb_ProgressDetails](_rdb___progress_details.md).|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [Rdb_ConflictResolution](#rdb_conflictresolution) [Rdb_ConflictResolution](#rdb_conflictresolution) | Defines an enum for conflict resolution policies.|
| typedef struct [OH_Rdb_ConfigV2](#oh_rdb_configv2) [OH_Rdb_ConfigV2](#oh_rdb_configv2) | Defines a struct for the RDB store configuration. Different from [OH_Rdb_Config](_o_h___rdb___config.md), this struct does not expose its member variables externally. Methods are used to configure the properties of this struct. It supports vector stores.|
| typedef enum [Rdb_DBType](#rdb_dbtype) [Rdb_DBType](#rdb_dbtype) | Defines an enum for database kernel types.|
| typedef enum [Rdb_Tokenizer](#rdb_tokenizer) [Rdb_Tokenizer](#rdb_tokenizer) | Defines an enum for database tokenizer types.|
| typedef enum [OH_ColumnType](#oh_columntype) [OH_ColumnType](#oh_columntype) | Defines an enum for column types.|
| typedef struct [OH_Data_Value](#oh_data_value) [OH_Data_Value](#oh_data_value) | Defines the [OH_Data_Value](#oh_data_value) struct.|
| typedef struct [OH_Data_Values](#oh_data_values) [OH_Data_Values](#oh_data_values) | Defines the [OH_Data_Values](#oh_data_values) struct.|
| typedef struct [OH_Data_VBuckets](#oh_data_vbuckets) [OH_Data_VBuckets](#oh_data_vbuckets) | Defines the **OH_Data_VBuckets** struct.|
| typedef enum [OH_RDB_TransType](#oh_rdb_transtype) [OH_RDB_TransType](#oh_rdb_transtype) | Defines an enum for transaction types of an RDB store.|
| typedef struct [OH_RDB_TransOptions](#oh_rdb_transoptions) [OH_RDB_TransOptions](#oh_rdb_transoptions) | Defines the [OH_RDB_TransOptions](#oh_rdb_transoptions) struct.|
| typedef struct [OH_Rdb_Transaction](#oh_rdb_transaction) [OH_Rdb_Transaction](#oh_rdb_transaction) | Defines the [OH_Rdb_Transaction](#oh_rdb_transaction) struct.|
| [OH_Cursor](#oh_cursor) | Defines a struct for a result set.|
| [OH_OrderType](#oh_ordertype) | Defines an enum for sorting types.|
| [OH_Predicates](#oh_predicates) | Defines a **predicates** object.|
| [OH_VObject](#oh_vobject) | Defines a struct for allowed data field types.|
| [OH_VBucket](#oh_vbucket) | Defines a struct for the types of the key and value in a KV pair.|
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) | Defines an enum for RDB store security levels.|
| [Rdb_SecurityArea](#rdb_securityarea) | Defines an enum for encryption levels of database files.|
| [Rdb_DistributedType](#rdb_distributedtype) | Defines an enum for distributed types.|
| [Rdb_DistributedConfig](#rdb_distributedconfig) | Defines a struct for distributed configuration of a table.|
| [Rdb_ChangeType](#rdb_changetype) | Defines an enum for data change types.|
| [Rdb_KeyInfo](#rdb_keyinfo) | Defines a struct for the primary key or number of the row that changes.|
| [Rdb_ChangeInfo](#rdb_changeinfo) | Defines a struct for the details about the device-cloud sync process.|
| [Rdb_SubscribeType](#rdb_subscribetype) | Defines an enum for subscription types.|
| [Rdb_BriefObserver](#rdb_briefobserver) | Defines a callback used to return the device-cloud data change event.|
| [Rdb_DetailsObserver](#rdb_detailsobserver) | Defines a callback used to return the details about the device-cloud data change.|
| [Rdb_SubscribeCallback](#rdb_subscribecallback) | Defines a callback used to return the subscribed event.|
| [Rdb_DataObserver](#rdb_dataobserver) | Defines a struct for the data observer.|
| [Rdb_SyncMode](#rdb_syncmode) | Defines an enum for RDB store sync modes.|
| [Rdb_Statistic](#rdb_statistic) | Defines a struct for the device-cloud sync statistics of a database table.|
| [Rdb_TableDetails](#rdb_tabledetails) | Defines a struct for statistics of device-cloud upload and download tasks of a database table.|
| [Rdb_Progress](#rdb_progress) | Defines an enum for device-cloud sync progress states.|
| [Rdb_ProgressCode](#rdb_progresscode) | Defines an enum for device-cloud sync states.|
| [Rdb_ProgressDetails](#rdb_progressdetails) | Defines a struct for statistics of the overall device-cloud sync (upload and download) tasks of an RDB store.|
| [Rdb_ProgressCallback](#rdb_progresscallback) | Defines a callback used to return the device-cloud sync progress.|
| [Rdb_SyncCallback](#rdb_synccallback) | Defines a callback for device-cloud sync.|
| [Rdb_ProgressObserver](#rdb_progressobserver) | Defines the observer of the device-cloud sync progress.|
| [OH_Rdb_ErrCode](#oh_rdb_errcode) | Defines an enum for error codes.|


### Enums

| Name| Description|
| -------- | -------- |
| [Rdb_DBType](#rdb_dbtype-1) { RDB_SQLITE = 1, RDB_CAYLEY = 2, DBTYPE_BUTT = 64 } | Enumerates the database kernel types.|
| [OH_OrderType](#oh_ordertype-1) { ASC = 0, DESC = 1 } | Enumerates the sorting types.|
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel-1) { S1 = 1, S2, S3, S4 } | Enumerates the RDB store security levels.|
| [Rdb_SecurityArea](#rdb_securityarea-1) { RDB_SECURITY_AREA_EL1 = 1, RDB_SECURITY_AREA_EL2, RDB_SECURITY_AREA_EL3, RDB_SECURITY_AREA_EL4 } | Enumerates the encryption levels of database files.|
| [Rdb_DistributedType](#rdb_distributedtype-1) { RDB_DISTRIBUTED_CLOUD } | Enumerates the distributed types.|
| [Rdb_ChangeType](#rdb_changetype-1) { RDB_DATA_CHANGE, RDB_ASSET_CHANGE } | Enumerates the data change types.|
| [Rdb_SubscribeType](#rdb_subscribetype-1) { RDB_SUBSCRIBE_TYPE_CLOUD, RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS, RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS } | Enumerates the subscription types.|
| [Rdb_SyncMode](#rdb_syncmode-1) { RDB_SYNC_MODE_TIME_FIRST, RDB_SYNC_MODE_NATIVE_FIRST, RDB_SYNC_MODE_CLOUD_FIRST } | Enumerates the RDB store sync modes.|
| [Rdb_Progress](#rdb_progress-1) { RDB_SYNC_BEGIN, RDB_SYNC_IN_PROGRESS, RDB_SYNC_FINISH } | Enumerates the device-cloud sync progresses.|
| [Rdb_ProgressCode](#rdb_progresscode-1) {<br>RDB_SUCCESS, RDB_UNKNOWN_ERROR, RDB_NETWORK_ERROR, RDB_CLOUD_DISABLED,<br>RDB_LOCKED_BY_OTHERS, RDB_RECORD_LIMIT_EXCEEDED, RDB_NO_SPACE_FOR_ASSET<br>} | Enumerates the device-cloud sync states.|
| [OH_ColumnType](#oh_columntype-1) {<br>TYPE_NULL = 0, TYPE_INT64, TYPE_REAL, TYPE_TEXT,<br>TYPE_BLOB, TYPE_ASSET, TYPE_ASSETS, TYPE_FLOAT_VECTOR,<br>TYPE_UNLIMITED_INT<br>} | Enumerates the column types.|
| [OH_RDB_TransType](#oh_rdb_transtype-1) { RDB_TRANS_DEFERRED = 0, RDB_TRANS_IMMEDIATE, RDB_TRANS_EXCLUSIVE, RDB_TRANS_BUTT } | Enumerates the transaction types of an RDB store.|
| [Rdb_Tokenizer](#rdb_tokenizer-1) { RDB_NONE_TOKENIZER = 1, RDB_ICU_TOKENIZER = 2, RDB_CUSTOM_TOKENIZER = 3 } | Enumerates the database tokenizer types.|
| [Rdb_ConflictResolution](#rdb_conflictresolution-1) {<br>RDB_CONFLICT_NONE = 1, RDB_CONFLICT_ROLLBACK, RDB_CONFLICT_ABORT, RDB_CONFLICT_FAIL,<br>RDB_CONFLICT_IGNORE, RDB_CONFLICT_REPLACE<br>} | Enumerates the conflict resolution policies.| 
| [OH_Rdb_ErrCode](#oh_rdb_errcode-1) {<br>RDB_ERR = -1, RDB_OK = 0, E_BASE = 14800000, RDB_E_NOT_SUPPORTED = 801,<br>RDB_E_ERROR = E_BASE, RDB_E_INVALID_ARGS = (E_BASE + 1), RDB_E_CANNOT_UPDATE_READONLY = (E_BASE + 2), RDB_E_REMOVE_FILE = (E_BASE + 3),<br>RDB_E_EMPTY_TABLE_NAME = (E_BASE + 5), RDB_E_EMPTY_VALUES_BUCKET = (E_BASE + 6), RDB_E_EXECUTE_IN_STEP_QUERY = (E_BASE + 7), RDB_E_INVALID_COLUMN_INDEX = (E_BASE + 8),<br>RDB_E_INVALID_COLUMN_TYPE = (E_BASE + 9), RDB_E_EMPTY_FILE_NAME = (E_BASE + 10), RDB_E_INVALID_FILE_PATH = (E_BASE + 11), RDB_E_TRANSACTION_IN_EXECUTE = (E_BASE + 12),<br>RDB_E_INVALID_STATEMENT = (E_BASE + 13), RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION = (E_BASE + 14), RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION = (E_BASE + 15), RDB_E_NO_TRANSACTION_IN_SESSION = (E_BASE + 16),<br>RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION = (E_BASE + 17), RDB_E_NO_ROW_IN_QUERY = (E_BASE + 18), RDB_E_INVALID_BIND_ARGS_COUNT = (E_BASE + 19), RDB_E_INVALID_OBJECT_TYPE = (E_BASE + 20),<br>RDB_E_INVALID_CONFLICT_FLAG = (E_BASE + 21), RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY = (E_BASE + 22), RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET = (E_BASE + 23), RDB_E_STEP_RESULT_SET_CROSS_THREADS = (E_BASE + 24),<br>RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED = (E_BASE + 25), RDB_E_STEP_RESULT_IS_AFTER_LAST = (E_BASE + 26), RDB_E_STEP_RESULT_QUERY_EXCEEDED = (E_BASE + 27), RDB_E_STATEMENT_NOT_PREPARED = (E_BASE + 28),<br>RDB_E_EXECUTE_RESULT_INCORRECT = (E_BASE + 29), RDB_E_STEP_RESULT_CLOSED = (E_BASE + 30), RDB_E_RELATIVE_PATH = (E_BASE + 31), RDB_E_EMPTY_NEW_ENCRYPT_KEY = (E_BASE + 32),<br>RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED = (E_BASE + 33), RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY = (E_BASE + 34), RDB_E_STEP_STATEMENT_NOT_INIT = (E_BASE + 35), RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE = (E_BASE + 36),<br>RDB_E_CREATE_FOLDER_FAIL = (E_BASE + 37), RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL = (E_BASE + 38), RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY = (E_BASE + 39), RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION = (E_BASE + 40),<br>RDB_E_NOT_SUPPORT = (E_BASE + 41), RDB_E_INVALID_PARCEL = (E_BASE + 42), RDB_E_QUERY_IN_EXECUTE = (E_BASE + 43), RDB_E_SET_PERSIST_WAL = (E_BASE + 44),<br>RDB_E_DB_NOT_EXIST = (E_BASE + 45), RDB_E_ARGS_READ_CON_OVERLOAD = (E_BASE + 46), RDB_E_WAL_SIZE_OVER_LIMIT = (E_BASE + 47), RDB_E_CON_OVER_LIMIT = (E_BASE + 48),<br>RDB_E_ALREADY_CLOSED = (E_BASE + 50), RDB_E_DATABASE_BUSY = (E_BASE + 51), RDB_E_SQLITE_CORRUPT = (E_BASE + 52), RDB_E_SQLITE_PERM = (E_BASE + 53),<br>RDB_E_SQLITE_BUSY = (E_BASE + 54), RDB_E_SQLITE_LOCKED = (E_BASE + 55), RDB_E_SQLITE_NOMEM = (E_BASE + 56), RDB_E_SQLITE_READONLY = (E_BASE + 57),<br>RDB_E_SQLITE_IOERR = (E_BASE + 58), RDB_E_SQLITE_FULL = (E_BASE + 59), RDB_E_SQLITE_CANT_OPEN = (E_BASE + 60), RDB_E_SQLITE_TOO_BIG = (E_BASE + 61),<br>RDB_E_SQLITE_MISMATCH = (E_BASE + 62), RDB_E_DATA_TYPE_NULL = (E_BASE + 63), RDB_E_TYPE_MISMATCH = (E_BASE + 64), RDB_E_SQLITE_CONSTRAINT = (E_BASE + 65)<br>} | Enumerates the RDB store error codes.| 


### Functions

| Name| Description|
| -------- | -------- |
| int [OH_RdbTrans_BatchInsert](#oh_rdbtrans_batchinsert) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*table, const [OH_Data_VBuckets](#oh_data_vbuckets) \*rows, [Rdb_ConflictResolution](#rdb_conflictresolution) resolution, int64_t \*changes) | Inserts a batch of data into a table.| 
| int [OH_Rdb_BatchInsert](#oh_rdb_batchinsert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, const [OH_Data_VBuckets](#oh_data_vbuckets) \*rows, [Rdb_ConflictResolution](#rdb_conflictresolution) resolution, int64_t \*changes) | Inserts a batch of data into a table.| 
| int [OH_Rdb_SetPersistent](#oh_rdb_setpersistent) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, bool isPersistent) | Sets whether to persist an RDB store.| 
| int [OH_Rdb_IsTokenizerSupported](#oh_rdb_istokenizersupported) ([Rdb_Tokenizer](#rdb_tokenizer) tokenizer, bool \*isSupported) | Checks whether the specified tokenizer is supported.|
| int [OH_Rdb_SetTokenizer](#oh_rdb_settokenizer) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, [Rdb_Tokenizer](#rdb_tokenizer) tokenizer) | Sets the tokenizer type.|
| int [OH_Cursor_GetFloatVectorCount](#oh_cursor_getfloatvectorcount) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, size_t \*length) | Obtains the length of the float array in the specified column of the current row.|
| int [OH_Cursor_GetFloatVector](#oh_cursor_getfloatvector) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, float \*val, size_t inLen, size_t \*outLen) | Obtains the value in a specified column of the current row in the form of a float array.|
| int [OH_Rdb_ExecuteV2](#oh_rdb_executev2) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args, [OH_Data_Value](#oh_data_value) \*\*result) | Executes an SQL statement with a return value. This API supports vector stores.|
| [OH_Cursor](_o_h___cursor.md) \* [OH_Rdb_ExecuteQueryV2](#oh_rdb_executequeryv2) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args) | Queries data in the database using the specified SQL statement. This API supports vector stores.|
| [OH_Data_Value](#oh_data_value) \* [OH_Value_Create](#oh_value_create) (void) | Creates an [OH_Data_Value](#oh_data_value) instance to store a single KV pair.|
| int [OH_Value_Destroy](#oh_value_destroy) ([OH_Data_Value](#oh_data_value) \*value) | Destroys an [OH_Data_Value](#oh_data_value) instance.|
| int [OH_Value_PutNull](#oh_value_putnull) ([OH_Data_Value](#oh_data_value) \*value) | Adds empty data to an **OH_Data_Value** instance.|
| int [OH_Value_PutInt](#oh_value_putint) ([OH_Data_Value](#oh_data_value) \*value, int64_t val) | Adds an integer to an **OH_Data_Value** instance.|
| int [OH_Value_PutReal](#oh_value_putreal) ([OH_Data_Value](#oh_data_value) \*value, double val) | Adds REAL data to an **OH_Data_Value** instance.|
| int [OH_Value_PutText](#oh_value_puttext) ([OH_Data_Value](#oh_data_value) \*value, const char \*val) | Adds a string to an **OH_Data_Value** instance.|
| int [OH_Value_PutBlob](#oh_value_putblob) ([OH_Data_Value](#oh_data_value) \*value, const unsigned char \*val, size_t length) | Adds BLOB data to an **OH_Data_Value** instance.|
| int [OH_Value_PutAsset](#oh_value_putasset) ([OH_Data_Value](#oh_data_value) \*value, const Data_Asset \*val) | Adds an asset to an **OH_Data_Value** instance.|
| int [OH_Value_PutAssets](#oh_value_putassets) ([OH_Data_Value](#oh_data_value) \*value, const Data_Asset \*const \*val, size_t length) | Adds assets to an **OH_Data_Value** instance.|
| int [OH_Value_PutFloatVector](#oh_value_putfloatvector) ([OH_Data_Value](#oh_data_value) \*value, const float \*val, size_t length) | Adds a float array to an **OH_Data_Value** instance.|
| int [OH_Value_PutUnlimitedInt](#oh_value_putunlimitedint) ([OH_Data_Value](#oh_data_value) \*value, int sign, const uint64_t \*trueForm, size_t length) | Adds an integer array of any length to an **OH_Data_Value** instance.|
| int [OH_Value_GetType](#oh_value_gettype) ([OH_Data_Value](#oh_data_value) \*value, [OH_ColumnType](#oh_columntype) \*type) | Obtains the data type.|
| int [OH_Value_IsNull](#oh_value_isnull) ([OH_Data_Value](#oh_data_value) \*value, bool \*val) | Checks whether a value is null.|
| int [OH_Value_GetInt](#oh_value_getint) ([OH_Data_Value](#oh_data_value) \*value, int64_t \*val) | Obtains the integer from an **OH_Data_Value** instance.|
| int [OH_Value_GetReal](#oh_value_getreal) ([OH_Data_Value](#oh_data_value) \*value, double \*val) | Obtains the REAL data from an **OH_Data_Value** instance.|
| int [OH_Value_GetText](#oh_value_gettext) ([OH_Data_Value](#oh_data_value) \*value, const char \*\*val) | Obtains the string from an **OH_Data_Value** instance.|
| int [OH_Value_GetBlob](#oh_value_getblob) ([OH_Data_Value](#oh_data_value) \*value, const uint8_t \*\*val, size_t \*length) | Obtains the BLOB data from an **OH_Data_Value** instance.|
| int [OH_Value_GetAsset](#oh_value_getasset) ([OH_Data_Value](#oh_data_value) \*value, Data_Asset \*val) | Obtains the asset from an **OH_Data_Value** instance.|
| int [OH_Value_GetAssetsCount](#oh_value_getassetscount) ([OH_Data_Value](#oh_data_value) \*value, size_t \*length) | Obtains the length of the asset in an **OH_Data_Value** instance.|
| int [OH_Value_GetAssets](#oh_value_getassets) ([OH_Data_Value](#oh_data_value) \*value, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | Obtains the assets from an **OH_Data_Value** instance.|
| int [OH_Value_GetFloatVectorCount](#oh_value_getfloatvectorcount) ([OH_Data_Value](#oh_data_value) \*value, size_t \*length) | Obtains the length of the float array in an **OH_Data_Value** instance.|
| int [OH_Value_GetFloatVector](#oh_value_getfloatvector) ([OH_Data_Value](#oh_data_value) \*value, float \*val, size_t inLen, size_t \*outLen) | Obtains the float array from an **OH_Data_Value** instance.|
| int [OH_Value_GetUnlimitedIntBand](#oh_value_getunlimitedintband) ([OH_Data_Value](#oh_data_value) \*value, size_t \*length) | Obtains the length of the unlimited integer from an **OH_Data_Value** instance.|
| int [OH_Value_GetUnlimitedInt](#oh_value_getunlimitedint) ([OH_Data_Value](#oh_data_value) \*value, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | Obtains the unlimited integer from an **OH_Data_Value** instance.|
| [OH_Data_Values](#oh_data_values) \* [OH_Values_Create](#oh_values_create) (void) | Creates an [OH_Data_Values](#oh_data_values) instance to store multiple KV pairs.|
| int [OH_Values_Destroy](#oh_values_destroy) ([OH_Data_Values](#oh_data_values) \*values) | Destroys an [OH_Data_Values](#oh_data_values) instance.|
| int [OH_Values_Put](#oh_values_put) ([OH_Data_Values](#oh_data_values) \*values, const [OH_Data_Value](#oh_data_value) \*val) | Adds data of the **OH_Data_Value** type to an **OH_Data_Values** instance.|
| int [OH_Values_PutNull](#oh_values_putnull) ([OH_Data_Values](#oh_data_values) \*values) | Adds empty data to an **OH_Data_Values** instance.|
| int [OH_Values_PutInt](#oh_values_putint) ([OH_Data_Values](#oh_data_values) \*values, int64_t val) | Adds an integer to an **OH_Data_Values** instance.|
| int [OH_Values_PutReal](#oh_values_putreal) ([OH_Data_Values](#oh_data_values) \*values, double val) | Adds REAL data to an **OH_Data_Values** instance.|
| int [OH_Values_PutText](#oh_values_puttext) ([OH_Data_Values](#oh_data_values) \*values, const char \*val) | Adds a string to an **OH_Data_Values** instance.|
| int [OH_Values_PutBlob](#oh_values_putblob) ([OH_Data_Values](#oh_data_values) \*values, const unsigned char \*val, size_t length) | Adds BLOB data to an **OH_Data_Values** instance.|
| int [OH_Values_PutAsset](#oh_values_putasset) ([OH_Data_Values](#oh_data_values) \*values, const Data_Asset \*val) | Adds an asset to an **OH_Data_Values** instance.|
| int [OH_Values_PutAssets](#oh_values_putassets) ([OH_Data_Values](#oh_data_values) \*values, const Data_Asset \*const \*val, size_t length) | Adds assets to an **OH_Data_Values** instance.|
| int [OH_Values_PutFloatVector](#oh_values_putfloatvector) ([OH_Data_Values](#oh_data_values) \*values, const float \*val, size_t length) | Adds a float array to an **OH_Data_Values** instance.|
| int [OH_Values_PutUnlimitedInt](#oh_values_putunlimitedint) ([OH_Data_Values](#oh_data_values) \*values, int sign, const uint64_t \*trueForm, size_t length) | Adds an integer array of any length to an **OH_Data_Values** instance.|
| int [OH_Values_Count](#oh_values_count) ([OH_Data_Values](#oh_data_values) \*values, size_t \*count) | Obtains the number of values in an **OH_Data_Values** instance.|
| int [OH_Values_GetType](#oh_values_gettype) ([OH_Data_Values](#oh_data_values) \*values, int index, [OH_ColumnType](#oh_columntype) \*type) | Obtains the type of a value in an **OH_Data_Values** instance.|
| int [OH_Values_Get](#oh_values_get) ([OH_Data_Values](#oh_data_values) \*values, int index, [OH_Data_Value](#oh_data_value) \*\*val) | Obtains data of the **OH_Data_Value** type.|
| int [OH_Values_IsNull](#oh_values_isnull) ([OH_Data_Values](#oh_data_values) \*values, int index, bool \*val) | Checks whether a value is null.|
| int [OH_Values_GetInt](#oh_values_getint) ([OH_Data_Values](#oh_data_values) \*values, int index, int64_t \*val) | Obtains the integer from an **OH_Data_Values** instance.|
| int [OH_Values_GetReal](#oh_values_getreal) ([OH_Data_Values](#oh_data_values) \*values, int index, double \*val) | Obtains the REAL data from an **OH_Data_Values** instance.|
| int [OH_Values_GetText](#oh_values_gettext) ([OH_Data_Values](#oh_data_values) \*values, int index, const char \*\*val) | Obtains the string from an **OH_Data_Values** instance.|
| int [OH_Values_GetBlob](#oh_values_getblob) ([OH_Data_Values](#oh_data_values) \*values, int index, const uint8_t \*\*val, size_t \*length) | Obtains the BLOB data from an **OH_Data_Values** instance.|
| int [OH_Values_GetAsset](#oh_values_getasset) ([OH_Data_Values](#oh_data_values) \*values, int index, Data_Asset \*val) | Obtains the asset from an **OH_Data_Values** instance.|
| int [OH_Values_GetAssetsCount](#oh_values_getassetscount) ([OH_Data_Values](#oh_data_values) \*values, int index, size_t \*length) | Obtains the length of the asset in an **OH_Data_Values** instance.|
| int [OH_Values_GetAssets](#oh_values_getassets) ([OH_Data_Values](#oh_data_values) \*values, int index, Data_Asset \*\*val, size_t inLen, size_t \*outLen) | Obtains the assets from an **OH_Data_Values** instance.|
| int [OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount) ([OH_Data_Values](#oh_data_values) \*values, int index, size_t \*length) | Obtains the length of the float array in an **OH_Data_Values** instance.|
| int [OH_Values_GetFloatVector](#oh_values_getfloatvector) ([OH_Data_Values](#oh_data_values) \*values, int index, float \*val, size_t inLen, size_t \*outLen) | Obtains the float array from an **OH_Data_Values** instance.|
| int [OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband) ([OH_Data_Values](#oh_data_values) \*values, int index, size_t \*length) | Obtains the length of the unlimited integer from an **OH_Data_Values** instance.|
| int [OH_Values_GetUnlimitedInt](#oh_values_getunlimitedint) ([OH_Data_Values](#oh_data_values) \*values, int index, int \*sign, uint64_t \*trueForm, size_t inLen, size_t \*outLen) | Obtains the unlimited integer from an **OH_Data_Values** instance.|
| [OH_Data_VBuckets](#oh_data_vbuckets) \* [OH_VBuckets_Create](#oh_vbuckets_create) (void) | Creates an **OH_Data_VBuckets** instance.|
| int [OH_VBuckets_Destroy](#oh_vbuckets_destroy) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets) | Destroys an **OH_Data_VBuckets** instance.|
| int [OH_VBuckets_PutRow](#oh_vbuckets_putrow) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets, const [OH_VBucket](_o_h___v_bucket.md) \*row) | Adds data of the **OH_VBucket** type to an **OH_Data_VBuckets** instance.|
| int [OH_VBuckets_PutRows](#oh_vbuckets_putrows) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets, const [OH_Data_VBuckets](#oh_data_vbuckets) \*rows) | Adds data of the **OH_Data_VBuckets** type to an **OH_Data_VBuckets** instance.|
| int [OH_VBuckets_RowCount](#oh_vbuckets_rowcount) ([OH_Data_VBuckets](#oh_data_vbuckets) \*buckets, size_t \*count) | Obtains the number **OH_VBucket**s in an **OH_Data_VBuckets** instance.|
| [OH_RDB_TransOptions](#oh_rdb_transoptions) \* [OH_RdbTrans_CreateOptions](#oh_rdbtrans_createoptions) (void) | Creates a **TransOptions** instance.|
| int [OH_RdbTrans_DestroyOptions](#oh_rdbtrans_destroyoptions) ([OH_RDB_TransOptions](#oh_rdb_transoptions) \*opitons) | Destroys a **TransOptions** instance.|
| int [OH_RdbTransOption_SetType](#oh_rdbtransoption_settype) ([OH_RDB_TransOptions](#oh_rdb_transoptions) \*opitons, [OH_RDB_TransType](#oh_rdb_transtype) type) | Sets the transaction type of an RDB store.|
| int [OH_RdbTrans_Commit](#oh_rdbtrans_commit) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans) | Commits a transaction.|
| int [OH_RdbTrans_Rollback](#oh_rdbtrans_rollback) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans) | Rolls back a transaction.|
| int [OH_RdbTrans_Insert](#oh_rdbtrans_insert) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*table, const [OH_VBucket](_o_h___v_bucket.md) \*row, int64_t \*rowId) | Inserts a row of data into a table.|
| int [OH_RdbTrans_Update](#oh_rdbtrans_update) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const [OH_VBucket](_o_h___v_bucket.md) \*row, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | Updates data in an RDB store based on specified conditions.|
| int [OH_RdbTrans_Delete](#oh_rdbtrans_delete) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | Deletes data from the database based on the specified conditions.|
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_Query](#oh_rdbtrans_query) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*columns[], int len) | Queries data in the database based on specified conditions.|
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_QuerySql](#oh_rdbtrans_querysql) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args) | Queries data in the database using the specified SQL statement.|
| int [OH_RdbTrans_Execute](#oh_rdbtrans_execute) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](#oh_data_values) \*args, [OH_Data_Value](#oh_data_value) \*\*result) | Executes an SQL statement that contains specified parameters.|
| int [OH_RdbTrans_Destroy](#oh_rdbtrans_destroy) ([OH_Rdb_Transaction](#oh_rdb_transaction) \*trans) | Destroys a transaction object.|
| int [OH_VBucket_PutFloatVector](#oh_vbucket_putfloatvector) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, const float \*vec, size_t len) | Puts a float array into an [OH_VBucket](_o_h___v_bucket.md) instance in the given column.|
| int [OH_VBucket_PutUnlimitedInt](#oh_vbucket_putunlimitedint) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, int sign, const uint64_t \*trueForm, size_t len) | Puts an integer of any length into an [OH_VBucket](_o_h___v_bucket.md) instance in the given column.|
| [OH_Rdb_ConfigV2](#oh_rdb_configv2) \* [OH_Rdb_CreateConfig](#oh_rdb_createconfig) () | Creates an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_DestroyConfig](#oh_rdb_destroyconfig) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config) | Destroys an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetDatabaseDir](#oh_rdb_setdatabasedir) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*databaseDir) | Sets the database file path for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetStoreName](#oh_rdb_setstorename) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*storeName) | Sets the RDB store name for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetBundleName](#oh_rdb_setbundlename) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*bundleName) | Sets the application bundle name for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetModuleName](#oh_rdb_setmodulename) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, const char \*moduleName) | Sets the module name for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetEncrypted](#oh_rdb_setencrypted) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, bool isEncrypted) | Sets whether to encrypt the database for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetSecurityLevel](#oh_rdb_setsecuritylevel) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int securityLevel) | Sets the [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetArea](#oh_rdb_setarea) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int area) | Sets the [Rdb_SecurityArea](#rdb_securityarea) for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| int [OH_Rdb_SetDbType](#oh_rdb_setdbtype) ([OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int dbType) | Sets the [Rdb_DBType](#rdb_dbtype) for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.|
| const int \* [OH_Rdb_GetSupportedDbType](#oh_rdb_getsupporteddbtype) (int \*typeCount) | Obtains the supported database types ([Rdb_DBType](#rdb_dbtype)).|
| [OH_Rdb_Store](_o_h___rdb___store.md) \* [OH_Rdb_CreateOrOpen](#oh_rdb_createoropen) (const [OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config, int \*errCode) | Creates or opens an [OH_Rdb_Store](_o_h___rdb___store.md) instance based on the given [OH_Rdb_ConfigV2](#oh_rdb_configv2).|
| int [OH_Rdb_DeleteStoreV2](#oh_rdb_deletestorev2) (const [OH_Rdb_ConfigV2](#oh_rdb_configv2) \*config) | Deletes an RDB store based on the given [OH_Rdb_ConfigV2](#oh_rdb_configv2). For a vector store, ensure that the vector store is correctly closed before calling this API.|
| int [OH_Rdb_ExecuteByTrxId](#oh_rdb_executebytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId, const char \*sql) | Executes an SQL statement that returns no value based on the specified transaction ID. This API supports only vector stores.|
| int [OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t \*trxId) | Begins a transaction. This API returns a transaction ID. This API supports only vector stores.|
| int [OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId) | Rolls back the executed SQL statements based on the specified transaction ID. This API supports only vector stores.|
| int [OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int64_t trxId) | Commits the executed SQL statements based on the specified transaction ID. This API supports only vector stores.|
| [OH_VBucket_PutAsset](#oh_vbucket_putasset) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*value) | Puts an **OH_Asset** object into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket_PutAssets](#oh_vbucket_putassets) ([OH_VBucket](_o_h___v_bucket.md) \*bucket, const char \*field, OH_Asset \*\*value, int count) | Puts an array of **OH_Asset** objects into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_Rdb_CreateValueObject](#oh_rdb_createvalueobject) () | Creates an [OH_VObject](_o_h___v_object.md) instance.|
| [OH_Rdb_CreateValuesBucket](#oh_rdb_createvaluesbucket) () | Creates an [OH_VBucket](_o_h___v_bucket.md) instance.|
| [OH_Rdb_CreatePredicates](#oh_rdb_createpredicates) (const char \*table) | Creates an [OH_Predicates](_o_h___predicates.md) instance.|
| [OH_Rdb_GetOrOpen](#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | Obtains an [OH_Rdb_Store](_o_h___rdb___store.md) instance for RDB store operations.|
| [OH_Rdb_CloseStore](#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Closes an [OH_Rdb_Store](_o_h___rdb___store.md) object to reclaim the memory occupied.|
| [OH_Rdb_DeleteStore](#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | Deletes an RDB store with the specified configuration.|
| [OH_Rdb_Insert](#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | Inserts a row of data into a table.|
| [OH_Rdb_Update](#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | Updates data in an RDB store based on specified conditions.|
| [OH_Rdb_Delete](#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Deletes data from an RDB store based on specified conditions.|
| [OH_Rdb_Query](#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | Queries data in an RDB store based on specified conditions.|
| [OH_Rdb_Execute](#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Executes an SQL statement that returns no value.|
| [OH_Rdb_ExecuteQuery](#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Queries data in the database using the specified SQL statement. This API supports vector stores.|
| [OH_Rdb_BeginTransaction](#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Begins the transaction before executing SQL statements.|
| [OH_Rdb_RollBack](#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Rolls back the SQL statements executed.|
| [OH_Rdb_Commit](#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Commits the executed SQL statements.|
| [OH_Rdb_Backup](#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Backs up an RDB store using the backup file of the specified path. This API supports vector stores.|
| [OH_Rdb_Restore](#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Restores a database from a specified database backup file. This API supports vector stores.|
| [OH_Rdb_GetVersion](#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | Obtains the RDB store version.|
| [OH_Rdb_SetVersion](#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | Sets the RDB store version.|
| [OH_Rdb_SetDistributedTables](#oh_rdb_setdistributedtables) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tables[], uint32_t count, [Rdb_DistributedType](#rdb_distributedtype) type, const [Rdb_DistributedConfig](_rdb___distributed_config.md) \*config) | Sets distributed database tables.|
| [OH_Rdb_FindModifyTime](#oh_rdb_findmodifytime) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*tableName, const char \*columnName, [OH_VObject](_o_h___v_object.md) \*values) | Obtains the last modification time of a table in an RDB store.|
| [OH_Rdb_Subscribe](#oh_rdb_subscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | Registers an observer for an RDB store. When data in the RDB store changes, a callback will be invoked to return the data changes.|
| [OH_Rdb_Unsubscribe](#oh_rdb_unsubscribe) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SubscribeType](#rdb_subscribetype) type, const [Rdb_DataObserver](_rdb___data_observer.md) \*observer) | Unregisters the observer of the specified type.|
| [OH_Rdb_GetTableDetails](#oh_rdb_gettabledetails) ([Rdb_ProgressDetails](_rdb___progress_details.md) \*progress, int32_t version) | Obtains the device-cloud sync statistics of a table.|
| [OH_Rdb_CloudSync](#oh_rdb_cloudsync) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [Rdb_SyncMode](#rdb_syncmode) mode, const char \*tables, int count, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | Performs device-cloud sync.|
| [OH_Rdb_SubscribeAutoSyncProgress](#oh_rdb_subscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | Subscribes to the auto sync progress of an RDB store. The registered callback will be invoked to return the auto sync progress.|
| [OH_Rdb_UnsubscribeAutoSyncProgress](#oh_rdb_unsubscribeautosyncprogress) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const [Rdb_ProgressObserver](_rdb___progress_observer.md) \*observer) | Unsubscribes from the auto sync process of an RDB store.|
| int [OH_Rdb_LockRow](#oh_rdb_lockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Locks data in an RDB store based on specified conditions. The locked data will be blocked from the device-cloud sync.|
| int [OH_Rdb_UnlockRow](#oh_rdb_unlockrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Unlocks data in an RDB store based on the specified conditions.|
| [OH_Cursor](_o_h___cursor.md) \* [OH_Rdb_QueryLockedRow](#oh_rdb_querylockedrow) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | Queries the locked data in an RDB store.|

### Variables

| Name| Description|
| -------- | -------- |
| [OH_Cursor::id](#id-15) | Unique identifier of the **OH_Cursor** struct.|
| [OH_Cursor::getColumnCount](#getcolumncount) | Pointer to the function used to obtain the number of columns in the result set.|
| [OH_Cursor::getColumnType](#getcolumntype) | Pointer to the function used to obtain the column type based on the specified column index.|
| [OH_Cursor::getColumnIndex](#getcolumnindex) | Pointer to the function used to obtain the column index based on the specified column name.|
| [OH_Cursor::getColumnName](#getcolumnname) | Pointer to the function used to obtain the column name based on the specified column index.|
| [OH_Cursor::getRowCount](#getrowcount) | Pointer to the function used to obtain the number of rows in the result set.|
| [OH_Cursor::goToNextRow](#gotonextrow) | Pointer to the function used to go to the next row of the result set.|
| [OH_Cursor::getSize](#getsize) | Pointer to the function used to obtain information about the memory required when the column data type in the result set is **BLOB** or **TEXT**.|
| [OH_Cursor::getText](#gettext) | Pointer to the function used to obtain the value of the string type based on the specified column and the current row.|
| [OH_Cursor::getInt64](#getint64) | Pointer to the function used to obtain the value of the int64_t type based on the specified column and the current row.|
| [OH_Cursor::getReal](#getreal) | Pointer to the function used to obtain the value of the double type based on the specified column and the current row.|
| [OH_Cursor::getBlob](#getblob) | Pointer to the function used to obtain the values in the form of a byte array based on the specified column and the current row.|
| [OH_Cursor::isNull](#isnull-12) | Pointer to the function used to check whether the value in the specified column is null.|
| [OH_Cursor::destroy](#destroy-14) | Pointer to the function used to destroy a result set.|
| [OH_Cursor::getAsset](#getasset) | Pointer to the function used to obtain the value of the asset type based on the specified column and the current row.|
| [OH_Cursor::getAssets](#getassets) | Pointer to the function used to obtain the values in the form of an asset array based on the specified column and the current row.|
| [OH_Predicates::id](#id-25) | Unique identifier of the **OH_Predicates** struct.|
| [OH_Predicates::equalTo](#equalto) | Pointer to the function used to create a predicates object to search for the field values that are equal to the specified value.|
| [OH_Predicates::notEqualTo](#notequalto) | Pointer to the function used to create a predicates object to search for the field values that are not equal to the specified value.|
| [OH_Predicates::beginWrap](#beginwrap) | Pointer to the function used to add a left parenthesis to the predicates.|
| [OH_Predicates::endWrap](#endwrap) | Pointer to the function used to add a right parenthesis to the predicates.|
| [OH_Predicates::orOperate](#oroperate) | Pointer to the function used to add the OR operator to the predicates.|
| [OH_Predicates::andOperate](#andoperate) | Pointer to the function used to add the AND operator to the predicates.|
| [OH_Predicates::isNull](#isnull-22) | Pointer to the function used to create a predicates object to search for the field values that are null.|
| [OH_Predicates::isNotNull](#isnotnull) | Pointer to the function used to create a predicates object to search for the field values that are not null.|
| [OH_Predicates::like](#like) | Pointer to the function used to create a predicates object to search for the field values that are similar to the specified string.|
| [OH_Predicates::between](#between) | Pointer to the function used to create a predicates object to search for the field values that are within the specified range.|
| [OH_Predicates::notBetween](#notbetween) | Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.|
| [OH_Predicates::greaterThan](#greaterthan) | Pointer to the function used to create a predicates object to search for the field values that are greater than the specified value.|
| [OH_Predicates::lessThan](#lessthan) | Pointer to the function used to create a predicates object to search for the field values that are less than the specified value.|
| [OH_Predicates::greaterThanOrEqualTo](#greaterthanorequalto) | Pointer to the function used to create a predicates object to search for the field values that are greater than or equal to the specified value.|
| [OH_Predicates::lessThanOrEqualTo](#lessthanorequalto) | Pointer to the function used to create a predicates object to search for the field values that are less than or equal to the specified value.|
| [OH_Predicates::orderBy](#orderby) | Pointer to the function used to create a predicates object to sort the values in the specified column in ascending or descending order.|
| [OH_Predicates::distinct](#distinct) | Pointer to the function used to create a predicates object to filter out duplicate records.|
| [OH_Predicates::limit](#limit) | Pointer to the function used to create a predicates object to specify the maximum number of records.|
| [OH_Predicates::offset](#offset) | Pointer to the function used to create a predicates object to specify the start position of the query result.|
| [OH_Predicates::groupBy](#groupby) | Pointer to the function used to create a predicates object to group the results by the specified columns.|
| [OH_Predicates::in](#in) | Pointer to the function used to create a predicates object to search for the field values that are within the specified range.|
| [OH_Predicates::notIn](#notin) | Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.|
| [OH_Predicates::clear](#clear-12) | Pointer to the function used to clear a predicates instance.|
| [OH_Predicates::destroy](#destroy-24) | Pointer to the function used to destroy an [OH_Predicates](_o_h___predicates.md) object to reclaim the memory occupied.|
| [OH_VObject::id](#id-35) | Unique identifier of the **OH_VObject** struct.|
| [OH_VObject::putInt64](#putint64-22) | Pointer to the function used to convert a single parameter or an array of the int64 type into a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::putDouble](#putdouble) | Pointer to the function used to convert a single parameter or an array of the double type into a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::putText](#puttext-22) | Pointer to the function used to convert a character array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::putTexts](#puttexts) | Pointer to the function used to convert a string array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::destroy](#destroy-44) | Pointer to the function used to destroy an [OH_VObject](_o_h___v_object.md) object to reclaim the memory occupied.|
| [OH_VBucket::id](#id-45) | Unique identifier of the **OH_VBucket** struct.|
| [OH_VBucket::capability](#capability) | Number of the KV pairs in an **OH_VBucket** instance.|
| [OH_VBucket::putText](#puttext-12) | Pointer to the function used to put a char value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::putInt64](#putint64-12) | Pointer to the function used to put an int64_t value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::putReal](#putreal) | Pointer to the function used to put a double value into the **OH_VBucket** object in the given column.|
| [OH_VBucket::putBlob](#putblob) | Pointer to the function used to put a const uint8_t value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::putNull](#putnull) | Pointer to the function used to put a null value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::clear](#clear-22) | Pointer to the function used to clear an [OH_VBucket](_o_h___v_bucket.md) object.|
| [OH_VBucket::destroy](#destroy-34) | Pointer to the function used to destroy an [OH_VBucket](_o_h___v_bucket.md) object to reclaim the memory occupied.|
| [OH_Rdb_Config::selfSize](#selfsize) | Size of the struct.|
| [OH_Rdb_Config::dataBaseDir](#databasedir) | Path of the database file.|
| [OH_Rdb_Config::storeName](#storename) | Name of the RDB store.|
| [OH_Rdb_Config::bundleName](#bundlename) | Bundle name.|
| [OH_Rdb_Config::moduleName](#modulename) | Module name. |
| [OH_Rdb_Config::isEncrypt](#isencrypt) | Whether to encrypt the RDB store.|
| [OH_Rdb_Config::securityLevel](#securitylevel) | RDB store security level. For details, see [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel).|
| [OH_Rdb_Config::area](#area) | Database file encryption level. For details, see [Rdb_SecurityArea](#rdb_securityarea).|
| [OH_Rdb_Store::id](#id-55) | Unique identifier of the **OH_Rdb_Store** struct.|
| [Rdb_DistributedConfig::version](#version-13) | Version of the **Rdb_DistributedConfig** struct.|
| [Rdb_DistributedConfig::isAutoSync](#isautosync) | Whether the table supports auto sync.|
| [Rdb_KeyInfo::count](#count) | Number of the changed primary keys or row numbers.|
| [Rdb_KeyInfo::type](#type) | [OH_ColumnType](#oh_columntype) of the primary key.|
| [Rdb_KeyInfo::Rdb_KeyData::integer](#integer) | Data of the uint64_t type.|
| [Rdb_KeyInfo::Rdb_KeyData::real](#real) | Data of the double type.|
| [Rdb_KeyInfo::Rdb_KeyData::text](#text) | Data of the char \* type.|
| [Rdb_KeyInfo::data](_rdb___key_info.md#member-variables)| Changed data.|
| [Rdb_ChangeInfo::version](#version-23) | Version of the **Rdb_DistributedConfig** struct.|
| [Rdb_ChangeInfo::tableName](#tablename) | Name of the table with data changes.|
| [Rdb_ChangeInfo::ChangeType](#changetype) | Type of the data changed, which can be data or asset.|
| [Rdb_ChangeInfo::inserted](#inserted) | Location where data is inserted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the inserted data.|
| [Rdb_ChangeInfo::updated](#updated) | Location where data is updated. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the updated data.|
| [Rdb_ChangeInfo::deleted](#deleted) | Location where data is deleted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the deleted data.|
| [Rdb_SubscribeCallback::detailsObserver](#detailsobserver) | Callback used to return the details about the device-cloud data change.|
| [Rdb_SubscribeCallback::briefObserver](#briefobserver) | Callback used to return the device-cloud data change event.|
| [Rdb_DataObserver::context](#context-12) | Context of the data observer.|
| [Rdb_DataObserver::callback](#callback-12) | Callback used to return the result.|
| [Rdb_Statistic::total](#total) | Total number of rows to be synced between the device and cloud in the database table.|
| [Rdb_Statistic::successful](#successful) | Number of rows that are successfully synced between the device and cloud in the database table.|
| [Rdb_Statistic::failed](#failed) | Number of rows that failed to be synced between the device and cloud in the database table.|
| [Rdb_Statistic::remained](#remained) | Number of rows that are not executed for device-cloud sync in the database table.|
| [Rdb_TableDetails::table](#table) | Database table name.|
| [Rdb_TableDetails::upload](#upload) | Statistics of the device-cloud upload tasks.|
| [Rdb_TableDetails::download](#download) | Statistics of the device-cloud download tasks.|
| [Rdb_ProgressDetails::version](#version-33) | Version of the **OH_TableDetails** struct.|
| [Rdb_ProgressDetails::schedule](#schedule) | Device-cloud sync process.|
| [Rdb_ProgressDetails::code](#code) | Device-cloud sync state.|
| [Rdb_ProgressDetails::tableLength](#tablelength) | Number of the tables synced between the device and cloud.|
| [Rdb_ProgressObserver::context](#context-22) | Context of the device-cloud sync progress observer.|
| [Rdb_ProgressObserver::callback](#callback-22) | Callback used to return the device-cloud sync progress.|


## Macro Description


### DISTRIBUTED_CHANGE_INFO_VERSION

```
#define DISTRIBUTED_CHANGE_INFO_VERSION   1
```

**Description**

Indicates the version of [Rdb_ChangeInfo](_rdb___change_info.md).

**Since**: 11


### DISTRIBUTED_CONFIG_VERSION

```
#define DISTRIBUTED_CONFIG_VERSION   1
```

**Description**

Indicates the version of [Rdb_DistributedConfig](_rdb___distributed_config.md).

**Since**: 11


### DISTRIBUTED_PROGRESS_DETAIL_VERSION

```
#define DISTRIBUTED_PROGRESS_DETAIL_VERSION   1
```

**Description**

Indicates the version of **OH_ProgressDetails**.

**Since**: 11


## Type Description

### Rdb_ConflictResolution

```
typedef enum Rdb_ConflictResolution Rdb_ConflictResolution
```

**Description**

Defines an enum for conflict resolution policies.

**Since**: 18

### OH_ColumnType

```
typedef enum OH_ColumnType OH_ColumnType
```

**Description**

Defines an enum for column types.

**Since**: 10

### OH_Data_Value

```
typedef struct OH_Data_Value OH_Data_Value
```

**Description**

Defines the [OH_Data_Value](#oh_data_value) struct.

**Since**: 18


### OH_Data_Values

```
typedef struct OH_Data_Values OH_Data_Values
```

**Description**

Defines the [OH_Data_Values](#oh_data_values) struct.

**Since**: 18


### OH_Data_VBuckets

```
typedef struct OH_Data_VBuckets OH_Data_VBuckets
```

**Description**

Defines the **OH_Data_VBuckets** struct.

**Since**: 18

### OH_Rdb_Transaction

```
typedef struct OH_Rdb_Transaction OH_Rdb_Transaction
```

**Description**

Defines the [OH_Rdb_Transaction](#oh_rdb_transaction) struct.

**Since**: 18


### OH_RDB_TransOptions

```
typedef struct OH_RDB_TransOptions OH_RDB_TransOptions
```

**Description**

Defines the [OH_RDB_TransOptions](#oh_rdb_transoptions) struct.

**Since**: 18


### OH_RDB_TransType

```
typedef enum OH_RDB_TransType OH_RDB_TransType
```

**Description**

Defines an enum for transaction types of an RDB store.

**Since**: 18

### Rdb_Tokenizer

```
typedef enum Rdb_Tokenizer Rdb_Tokenizer
```

**Description**

Defines an enum for database tokenizer types.

**Since**: 18

### OH_Rdb_ConfigV2

```
typedef struct OH_Rdb_ConfigV2 OH_Rdb_ConfigV2
```

**Description**

Defines a struct for the RDB store configuration. Different from [OH_Rdb_Config](_o_h___rdb___config.md), this struct does not expose its member variables externally. Methods are used to configure the properties of this struct.

**Since**: 14


### Rdb_DBType

```
typedef enum Rdb_DBType Rdb_DBType
```

**Description**

Defines an enum for database kernel types.

**Since**: 14

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

| Name| Description|
| -------- | -------- |
| context | Pointer to the context of the data observer.|
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

| Name| Description|
| -------- | -------- |
| context | Pointer to the context of the data observer.|
| changeInfo | Double pointer to [Rdb_ChangeInfo](_rdb___change_info.md).|
| count | Number of changed tables.|

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

Defines a struct for the primary key or number of the row that changes.

**Since**: 11


### Rdb_Progress

```
typedef enum Rdb_Progress Rdb_Progress
```

**Description**

Defines an enum for device-cloud sync progress states.

**Since**: 11


### Rdb_ProgressCallback

```
typedef void(* Rdb_ProgressCallback) (void *context, Rdb_ProgressDetails *progressDetails)
```

**Description**

Defines a callback used to return the device-cloud sync progress.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| progressDetails | Details about the device-cloud sync progress.|

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

Defines an enum for encryption levels of database files.

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

| Name| Description|
| -------- | -------- |
| progressDetails | Statistics of device-cloud sync.|

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### Rdb_SyncMode

```
typedef enum Rdb_SyncMode Rdb_SyncMode
```

**Description**

Defines an enum for RDB store sync modes.

**Since**: 11


### Rdb_TableDetails

```
typedef struct Rdb_TableDetails Rdb_TableDetails
```

**Description**

Defines a struct for statistics of device-cloud upload and download tasks of a database table.

**Since**: 11

## Enum Description

### Rdb_ConflictResolution

```
enum Rdb_ConflictResolution
```

**Description**

Enumerates the conflict resolution policies.

**Since**: 18

| Value| Description| 
| -------- | -------- |
| RDB_CONFLICT_NONE | No operation is performed when a conflict occurs.| 
| RDB_CONFLICT_ROLLBACK | Throw an error and roll back the transaction.| 
| RDB_CONFLICT_ABORT | Throw an error and roll back the current change.| 
| RDB_CONFLICT_FAIL | Throw an error and abort the current change without rolling back the modifications before the conflict.| 
| RDB_CONFLICT_IGNORE | Ignore the conflicted data and resolve the conflict later.| 
| RDB_CONFLICT_REPLACE | Delete the data and then insert the data. If the conflict persists, apply **RDB_CONFLICT_ABORT**.| 

### OH_Rdb_ErrCode

```
enum OH_Rdb_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 10

| Value| Description| 
| -------- | -------- |
| RDB_ERR | Execution failed.| 
| RDB_OK | Execution successful.| 
| E_BASE | Base of the error code.| 
| RDB_E_NOT_SUPPORTED | The RDB store does not have this capability.| 
| RDB_E_ERROR | Common exception.| 
| RDB_E_INVALID_ARGS | Invalid parameter.| 
| RDB_E_CANNOT_UPDATE_READONLY | Failed to update data because the RDB store is read-only.| 
| RDB_E_REMOVE_FILE | Failed to delete the file.| 
| RDB_E_EMPTY_TABLE_NAME | The table name is empty.| 
| RDB_E_EMPTY_VALUES_BUCKET | The content of the KV pair is empty.| 
| RDB_E_EXECUTE_IN_STEP_QUERY | The SQL statement executed during the query is incorrect.| 
| RDB_E_INVALID_COLUMN_INDEX | The column index is invalid.| 
| RDB_E_INVALID_COLUMN_TYPE | The column type is invalid.| 
| RDB_E_EMPTY_FILE_NAME | The file name is empty.| 
| RDB_E_INVALID_FILE_PATH | The file path is invalid.| 
| RDB_E_TRANSACTION_IN_EXECUTE | Failed to start the transaction.| 
| RDB_E_INVALID_STATEMENT | Failed to precompile the SQL statements.| 
| RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION | Failed to perform a write operation in a read connection.| 
| RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION | Failed to start the transaction in a read connection.| 
| RDB_E_NO_TRANSACTION_IN_SESSION | The transaction to start does not exist in the database session.| 
| RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION | Multiple queries are executed in a database session.| 
| RDB_E_NO_ROW_IN_QUERY | The result set does not contain any record.| 
| RDB_E_INVALID_BIND_ARGS_COUNT | The number of parameters bound in the SQL statement is invalid.| 
| RDB_E_INVALID_OBJECT_TYPE | The object type is invalid.| 
| RDB_E_INVALID_CONFLICT_FLAG | The conflict resolution type is invalid.| 
| RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY | The **HAVING** keyword can be used only after **GROUP BY**.| 
| RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET | The result set by step is not supported.| 
| RDB_E_STEP_RESULT_SET_CROSS_THREADS | Failed to obtain the result set.| 
| RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED | The result set query statement is not executed.| 
| RDB_E_STEP_RESULT_IS_AFTER_LAST | The pointer of the result set is already in the last row.| 
| RDB_E_STEP_RESULT_QUERY_EXCEEDED | The number of result set query times exceeds the limit.| 
| RDB_E_STATEMENT_NOT_PREPARED | The SQL statement is not precompiled.| 
| RDB_E_EXECUTE_RESULT_INCORRECT | The database execution result is incorrect.| 
| RDB_E_STEP_RESULT_CLOSED | The result set has been closed.| 
| RDB_E_RELATIVE_PATH | The file path is a relative path.| 
| RDB_E_EMPTY_NEW_ENCRYPT_KEY | The new encrypt key is empty.| 
| RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED | The RDB store is non-encrypted and cannot be changed.| 
| RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY | The database does not respond when the database key is updated.| 
| RDB_E_STEP_STATEMENT_NOT_INIT | The precompiled SQL statement is not initialized.| 
| RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE | The WAL mode does not support the ATTACH operation.| 
| RDB_E_CREATE_FOLDER_FAIL | Failed to create the folder.| 
| RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL | Failed to build the SQL statement.| 
| RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY | The database session does not provide a connection.| 
| RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION | The transaction does not exist in the database session.| 
| RDB_E_NOT_SUPPORT | The current operation is not supported.| 
| RDB_E_INVALID_PARCEL | The current PARCEL is invalid.| 
| RDB_E_QUERY_IN_EXECUTE | Failed to execute query.| 
| RDB_E_SET_PERSIST_WAL | Failed to set the persistence of the database file in WAL mode.| 
| RDB_E_DB_NOT_EXIST | The database does not exist.| 
| RDB_E_ARGS_READ_CON_OVERLOAD | The number of read connections to set is greater than the limit.| 
| RDB_E_WAL_SIZE_OVER_LIMIT | The WAL log file size exceeds the default value.| 
| RDB_E_CON_OVER_LIMIT | The number of database connections has reached the limit.| 
| RDB_E_ALREADY_CLOSED<sup>18+</sup> | The RDB store is already closed.| 
| RDB_E_DATABASE_BUSY<sup>18+</sup> | The database does not respond.| 
| RDB_E_SQLITE_CORRUPT<sup>18+</sup> | The database is corrupted.| 
| RDB_E_SQLITE_PERM<sup>18+</sup> | SQLite: access denied.| 
| RDB_E_SQLITE_BUSY<sup>18+</sup> | SQLite: database file locked.| 
| RDB_E_SQLITE_LOCKED<sup>18+</sup> | SQLite: database table locked.| 
| RDB_E_SQLITE_NOMEM<sup>18+</sup> | SQLite: insufficient database memory.| 
| RDB_E_SQLITE_READONLY<sup>18+</sup> | SQLite: attempt to write a read-only database.| 
| RDB_E_SQLITE_IOERR<sup>18+</sup> | SQLite: disk I/O error.| 
| RDB_E_SQLITE_FULL<sup>18+</sup> | SQLite: database is full.| 
| RDB_E_SQLITE_CANT_OPEN<sup>18+</sup> | SQLite: unable to open the database file.| 
| RDB_E_SQLITE_TOO_BIG<sup>18+</sup> | SQLite: TEXT or BLOB exceeds the limit.| 
| RDB_E_SQLITE_MISMATCH<sup>18+</sup> | SQLite: data types mismatch.| 
| RDB_E_DATA_TYPE_NULL<sup>18+</sup> | The data to be stored is empty.| 
| RDB_E_TYPE_MISMATCH<sup>18+</sup> | The data type is incorrect.| 
| RDB_E_SQLITE_CONSTRAINT<sup>18+</sup> | SQLite error code: SQLite constraint.| 

### OH_ColumnType

```
enum OH_ColumnType
```

**Description**

Enumerates the column data types.

**Since**: 10

| Value| Description|
| -------- | -------- |
| TYPE_NULL | NULL.|
| TYPE_INT64 | INT64.|
| TYPE_REAL | REAL.|
| TYPE_TEXT | TEXT.|
| TYPE_BLOB | BLOB.|
| TYPE_ASSET<sup>11+</sup> | ASSET (asset attachment).|
| TYPE_ASSETS<sup>11+</sup> | ASSETS (multiple asset attachments).|
| TYPE_FLOAT_VECTOR<sup>18+</sup> | FLOAT VECTOR.|
| TYPE_UNLIMITED_INT<sup>18+</sup> | Number longer than 64 digits.|

### OH_RDB_TransType

```
enum OH_RDB_TransType
```

**Description**

Enumerates the transaction types of an RDB store.

**Since**: 18

| Value| Description|
| -------- | -------- |
| RDB_TRANS_DEFERRED | Do not start any transaction before the database is accessed for the first time.|
| RDB_TRANS_IMMEDIATE | Start new writes without waiting for the write statement once the database is connected.|
| RDB_TRANS_EXCLUSIVE | Start the write transaction immediately, similar to **RDB_TRANS_IMMEDIATE**. In WAL mode, **RDB_TRANS_EXCLUSIVE** is the same as **RDB_TRANS_IMMEDIATE**. In other log modes, **RDB_TRANS_EXCLUSIVE** prevents other database connections when the transaction is reading the database.|
| RDB_TRANS_BUTT | Maximum value of the RDB transaction type.|

### Rdb_Tokenizer

```
enum Rdb_Tokenizer
```

**Description**

Enumerates the database tokenizer types.

**Since**: 18

| Value| Description|
| -------- | -------- |
| RDB_NONE_TOKENIZER | No tokenizer is used.|
| RDB_ICU_TOKENIZER | Native ICU tokenizer.|
| RDB_CUSTOM_TOKENIZER | Custom tokenizer.|

### Rdb_DBType

```
enum Rdb_DBType
```

**Description**

Enumerates the database kernel types.

**Since**: 14

| Value| Description|
| -------- | -------- |
| RDB_SQLITE | SQLite is used as the database kernel.|
| RDB_CAYLEY | Cayley is used as the database kernel.|
| DBTYPE_BUTT | Maximum value of the database kernel type, which is an invalid value.|

### OH_Rdb_SecurityLevel

```
enum OH_Rdb_SecurityLevel
```

**Description**

Enumerates the RDB store security levels.

**Since**: 10

| Value| Description|
| -------- | -------- |
| S1 | Low security level.<br>If data leakage occurs, minor impact will be caused.|
| S2 | Medium security level.<br>If data leakage occurs, moderate impact will be caused.|
| S3 | High security level.<br>If data leakage occurs, major impact will be caused.|
| S4 | Critical security level.<br>If data leakage occurs, critical impact will be caused.|


### Rdb_ChangeType

```
enum Rdb_ChangeType
```

**Description**

Enumerates the data change types.

**Since**: 11

| Value| Description|
| -------- | -------- |
| RDB_DATA_CHANGE | Data change.|
| RDB_ASSET_CHANGE | Asset change.|


### Rdb_DistributedType

```
enum Rdb_DistributedType
```

**Description**

Enumerates the distributed types.

**Since**: 11

| Value| Description|
| -------- | -------- |
| RDB_DISTRIBUTED_CLOUD | Distributed database tables for device-cloud sync.|


### Rdb_Progress

```
enum Rdb_Progress
```

**Description**

Enumerates the device-cloud sync progress states.

**Since**: 11

| Value| Description|
| -------- | -------- |
| RDB_SYNC_BEGIN | The device-cloud sync starts.|
| RDB_SYNC_IN_PROGRESS | The device-cloud sync is in progress.|
| RDB_SYNC_FINISH | The device-cloud sync is finished.|


### Rdb_ProgressCode

```
enum Rdb_ProgressCode
```

**Description**

Enumerates the device-cloud sync state codes.

**Since**: 11

| Value| Description|
| -------- | -------- |
| RDB_SUCCESS | The device-cloud sync is successful.|
| RDB_UNKNOWN_ERROR | An unknown error occurs during the device-cloud sync.|
| RDB_NETWORK_ERROR | A network error occurs during the device-cloud sync.|
| RDB_CLOUD_DISABLED | The cloud is unavailable.|
| RDB_LOCKED_BY_OTHERS | The device-cloud sync of another device is being performed.|
| RDB_RECORD_LIMIT_EXCEEDED | The number of records or size of the data to be synced exceeds the maximum. The maximum value is configured on the cloud.|
| RDB_NO_SPACE_FOR_ASSET | The remaining cloud space is less than the size of the data to be synced.|


### Rdb_SecurityArea

```
enum Rdb_SecurityArea
```

**Description**

Enumerates the encryption levels of database files.

**Since**: 11

| Value| Description|
| -------- | -------- |
| RDB_SECURITY_AREA_EL1 | Encryption level 1.|
| RDB_SECURITY_AREA_EL2 | Encryption level 2.|
| RDB_SECURITY_AREA_EL3 | Encryption level 3.|
| RDB_SECURITY_AREA_EL4 | Encryption level 4.|


### Rdb_SubscribeType

```
enum Rdb_SubscribeType
```

**Description**

Enumerates the subscription types.

**Since**: 11

| Value| Description|
| -------- | -------- |
| RDB_SUBSCRIBE_TYPE_CLOUD | Subscribe to cloud data changes.|
| RDB_SUBSCRIBE_TYPE_CLOUD_DETAILS | Subscribe to cloud data change details.|
| RDB_SUBSCRIBE_TYPE_LOCAL_DETAILS<sup>12+</sup>  | Subscribe to details of the local data change. This value is available since API version 12.|


### Rdb_SyncMode

```
enum Rdb_SyncMode
```

**Description**

Enumerates the RDB store sync modes.

**Since**: 11

| Value| Description|
| -------- | -------- |
| RDB_SYNC_MODE_TIME_FIRST | Synchronize with the data with the latest modification time.|
| RDB_SYNC_MODE_NATIVE_FIRST | Synchronize data from a local device to the cloud.|
| RDB_SYNC_MODE_CLOUD_FIRST | Synchronize data from the cloud to a local device.|


## Function Description

### OH_RdbTrans_BatchInsert()

```
int OH_RdbTrans_BatchInsert (OH_Rdb_Transaction *trans, const char *table, const OH_Data_VBuckets *rows, Rdb_ConflictResolution resolution, int64_t *changes)
```

**Description**

Inserts a batch of data into a table.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance.| 
| table | Pointer to the target table.| 
| rows | Pointer to the rows of data to insert.| 
| resolution | Policy used to resolve file conflicts.| 
| changes | Pointer to the number of successful insertions.| 

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.


### OH_Rdb_BatchInsert()

```
int OH_Rdb_BatchInsert (OH_Rdb_Store *store, const char *table, const OH_Data_VBuckets *rows, Rdb_ConflictResolution resolution, int64_t *changes )
```

**Description**

Inserts a batch of data into a table.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.| 
| tables | Pointer to the names of the distributed tables to set.| 
| rows | Pointer to the rows of data to insert.| 
| resolution | Policy used to resolve file conflicts.| 
| changes | Pointer to the number of successful insertions.| 

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.


### OH_Rdb_SetPersistent()

```
int OH_Rdb_SetPersistent (OH_Rdb_ConfigV2 *config, bool isPersistent )
```

**Description**

Sets whether to persist an RDB store.

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to the target **OH_Rdb_ConfigV2** instance, which specifies the database configuration.|
| isPersistent | Whether to persist the database data.|

**Returns**

Returns the status code of the execution. 

**RDB_OK** indicates that the operation is successful. 

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified. 

### OH_Cursor_GetFloatVector()

```
int OH_Cursor_GetFloatVector (OH_Cursor *cursor, int32_t columnIndex, float *val, size_t inLen, size_t *outLen )
```

**Description**

Obtains the value in a specified column of the current row in the form of a float array.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| val | Ponter to the value obtained, in a float array. The caller needs to apply for the memory.|
| inLen | Length of the float array requested.|
| outLen | Pointer to the length of the value obtained.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_STEP_RESULT_CLOSED** indicates the result set is closed.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit. 

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

**See**

[OH_Cursor_GetFloatVectorCount](#oh_cursor_getfloatvectorcount).


### OH_Cursor_GetFloatVectorCount()

```
int OH_Cursor_GetFloatVectorCount (OH_Cursor *cursor, int32_t columnIndex, size_t *length )
```

**Description**

Obtains the length of the float array in the specified column of the current row.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| length | Pointer to the length of the float array obtained.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_STEP_RESULT_CLOSED** indicates the result set is closed.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

### OH_Rdb_CreateTransaction()

```
int OH_Rdb_CreateTransaction (OH_Rdb_Store *store, const OH_RDB_TransOptions *options, OH_Rdb_Transaction **trans )
```

**Description**

Creates a transaction object.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| options | Pointer to the [OH_RDB_TransOptions](#oh_rdb_transoptions) instance for the transaction instance to create.|
| trans | Double pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance created if the operation is successful. If the operation fails, **nullptr** is returned. Call [OH_RdbTrans_Destroy](#oh_rdbtrans_destroy) to release the transaction instance that is no longer required.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_DATABASE_BUSY** indicates the database does not respond.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_CANT_OPEN** indicates an SQLite error: unable to open the database file.

**See**

[OH_RdbTrans_Destroy](#oh_rdbtrans_destroy).


### OH_Rdb_ExecuteQueryV2()

```
OH_Cursor *OH_Rdb_ExecuteQueryV2 (OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args )
```

**Description**

Queries data in the database using the specified SQL statement. This API supports vector stores.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| sql | Pointer to the SQL statement to execute.|
| args | Pointer to the **OH_Data_Values** instance. This parameter is optional.|

**Returns**

Returns a pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful. Release the [OH_Cursor](_o_h___cursor.md) instance that is no longer required in time. 

Returns **NULL** if the SQL statement is invalid or the memory allocation fails.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_ExecuteV2()

```
int OH_Rdb_ExecuteV2 (OH_Rdb_Store *store, const char *sql, const OH_Data_Values *args, OH_Data_Value **result )
```

**Description**

Executes an SQL statement with a return value. This API supports vector stores.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| sql | Pointer to the SQL statement to execute.|
| args | Pointer to the **OH_Data_Values** instance. This parameter is optional.|
| result | Double pointer to the [OH_Data_Value](#oh_data_value) instance returned if the operation is successful.<br>Use [OH_Value_Destroy](#oh_value_destroy) to release the memory in time.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

**See**

[OH_Value_Destroy](#oh_value_destroy).


### OH_Rdb_IsTokenizerSupported()

```
int OH_Rdb_IsTokenizerSupported (Rdb_Tokenizer tokenizer, bool *isSupported )
```

**Description**

Checks whether the specified tokenizer is supported.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| tokenizer | Tokenizer to check.|
| isSupported | Pointer to the check result.<br>The value **true** means the tokenizer is supported; the value **false** means the opposite.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_SetTokenizer()

```
int OH_Rdb_SetTokenizer (OH_Rdb_ConfigV2 *config, Rdb_Tokenizer tokenizer )
```

**Description**

Sets the tokenizer type.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the target database configuration.|
| tokenizer | tokenizer type to set.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.

### OH_RdbTrans_Commit()

```
int OH_RdbTrans_Commit (OH_Rdb_Transaction *trans)
```

**Description**

Commits a transaction.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance to commit.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

### OH_RdbTrans_Delete()

```
int OH_RdbTrans_Delete (OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes )
```

**Description**

Deletes data from the database based on the specified conditions.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance.|
| predicates | Pointer to the conditions specified by [OH_Predicates](_o_h___predicates.md).|
| changes | Pointer to the number of successful deletions.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

### OH_RdbTrans_CreateOptions()

```
OH_RDB_TransOptions* OH_RdbTrans_CreateOptions (void )
```

**Description**

Creates a transaction configuration object.

**Since**: 18

**Returns**

Returns the pointer to the [OH_RDB_TransOptions](#oh_rdb_transoptions) instance created if the operation is successful. Returns **nullptr** otherwise. Use [OH_RdbTrans_DestroyOptions](#oh_rdbtrans_destroyoptions) to release the memory in time.

**See**

[OH_RdbTrans_DestroyOptions](#oh_rdbtrans_destroyoptions).

### OH_RdbTrans_Destroy()

```
int OH_RdbTrans_Destroy (OH_Rdb_Transaction *trans)
```

**Description**

Destroys a transaction object.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance to destroy.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_RdbTrans_DestroyOptions()

```
int OH_RdbTrans_DestroyOptions (OH_RDB_TransOptions *opitons)
```

**Description**

Destroys a **TransOptions** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| opitons | Pointer to the [OH_RDB_TransOptions](#oh_rdb_transoptions) instance to destroy.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_RdbTrans_Execute()

```
int OH_RdbTrans_Execute (OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result )
```

**Description**

Executes an SQL statement that contains specified parameters.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance.|
| sql | Pointer to the SQL statement to execute.|
| args | Pointer to the parameters contained in the SQL statement.|
| result | Pointer to the [OH_Data_Value](#oh_data_value) instance created if the execution is successful. Use [OH_Value_Destroy](#oh_value_destroy) to release the memory in time.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

**See**

[OH_Value_Destroy](#oh_value_destroy).


### OH_RdbTrans_Insert()

```
int OH_RdbTrans_Insert (OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId )
```

**Description**

Inserts a row of data into a table.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance.|
| table | Pointer to the target table.|
| row | Pointer to the row of data to insert.|
| rowId | Pointer to the row number returned.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

### OH_RdbTrans_Query()

```
OH_Cursor* OH_RdbTrans_Query (OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[], int len )
```

**Description**

Queries data in the database based on specified conditions.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance.|
| predicates | Pointer to the query conditions specified by [OH_Predicates](_o_h___predicates.md).|
| columns | Pointer to the column to be queried. If the value is not specified, the query applies to all columns.|
| len | Number of elements in a column.|

**Returns**

Returns a pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful. Returns null if the database is closed or does not respond.


### OH_RdbTrans_QuerySql()

```
OH_Cursor* OH_RdbTrans_QuerySql (OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args )
```

**Description**

Queries data in the database using the specified SQL statement.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance.|
| sql | Pointer to the SQL statement to execute.|
| args | Pointer to [OH_Data_Values](#oh_data_values).|

**Returns**

Returns a pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful. Returns null if the database is closed or does not respond.


### OH_RdbTrans_Rollback()

```
int OH_RdbTrans_Rollback (OH_Rdb_Transaction *trans)
```

**Description**

Rolls back a transaction.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance to roll back.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.


### OH_RdbTrans_Update()

```
int OH_RdbTrans_Update (OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates, int64_t *changes )
```

**Description**

Updates data in an RDB store based on specified conditions.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| trans | Pointer to the [OH_Rdb_Transaction](#oh_rdb_transaction) instance.|
| row | Pointer to the row of data to update.|
| predicates | Pointer to the update condition specified by [OH_Predicates](_o_h___predicates.md).|
| changes | Pointer to the number of successful updates.|

**Returns**

Returns the execution result.

**RDB_OK** indicates that the operation is successful.

**RDB_E_ERROR** indicates a common database error.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.

**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.

**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.

**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.

**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.

**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.

**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.

**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.

**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.

**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.

**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.

**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.

### OH_RdbTransOption_SetType()

```
int OH_RdbTransOption_SetType (OH_RDB_TransOptions *opitons, OH_RDB_TransType type )
```

**Description**

Sets the transaction type of an RDB store.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| opitons | Pointer to the [OH_RDB_TransOptions](#oh_rdb_transoptions) instance.|
| type | Transaction type to set.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_Create()

```
OH_Data_Value* OH_Value_Create (void )
```

**Description**

Creates an [OH_Data_Value](#oh_data_value) instance to store a single KV pair.

**Since**: 18

**Returns**

Returns the pointer to the [OH_Data_Value](#oh_data_value) instance created if the operation is successful; returns **nullptr** otherwise. Use [OH_Value_Destroy](#oh_value_destroy) to release the memory in time.

**See**

[OH_Value_Destroy](#oh_value_destroy).


### OH_Value_Destroy()

```
int OH_Value_Destroy (OH_Data_Value *value)
```

**Description**

Destroys an [OH_Data_Value](#oh_data_value) instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the [OH_Data_Value](#oh_data_value) instance to destroy.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_GetAsset()

```
int OH_Value_GetAsset (OH_Data_Value *value, Data_Asset *val )
```

**Description**

Obtains the asset from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the **Data_Asset** object obtained if the operation is successful. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

### OH_Value_GetAssets()

```
int OH_Value_GetAssets (OH_Data_Value *value, Data_Asset **val, size_t inLen, size_t *outLen )
```

**Description**

Obtains the assets from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Double pointer to the **Data_Asset** object obtained if the operation is successful. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|
| inLen | Size of **val**, which can be obtained by [OH_Values_GetAssetsCount](#oh_values_getassetscount).|
| outLen | Pointer to the size of the obtained data.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

**See**

[OH_Value_GetAssetsCount](#oh_value_getassetscount).


### OH_Value_GetAssetsCount()

```
int OH_Value_GetAssetsCount (OH_Data_Value *value, size_t *length )
```

**Description**

Obtains the length of the asset in an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| length | Pointer to the ASSETS data length obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Value_GetBlob()

```
int OH_Value_GetBlob (OH_Data_Value *value, const uint8_t **val, size_t *length )
```

**Description**

Obtains the BLOB data from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Double pointer to the BLOB data obtained. You do not need to apply for or release memory for it. The lifecycle of **val** complies with the value of **index** in **value**.|
| length | Pointer to the length of the BLOB data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Value_GetFloatVector()

```
int OH_Value_GetFloatVector (OH_Data_Value *value, float *val, size_t inLen, size_t *outLen )
```

**Description**

Obtains the float array from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the float array obtained. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|
| inLen | Size of **val**, which can be obtained by using [OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount).|
| outLen | Pointer to the length of the obtained data.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

**See**

[OH_Value_GetFloatVectorCount](#oh_value_getfloatvectorcount).


### OH_Value_GetFloatVectorCount()

```
int OH_Value_GetFloatVectorCount (OH_Data_Value *value, size_t *length )
```

**Description**

Obtains the length of a float array.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| length | Pointer to the length of the float data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Value_GetInt()

```
int OH_Value_GetInt (OH_Data_Value *value, int64_t *val )
```

**Description**

Obtains the integer from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the integer data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Value_GetReal()

```
int OH_Value_GetReal (OH_Data_Value *value, double *val )
```

**Description**

Obtains the REAL data from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the REAL data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Value_GetText()

```
int OH_Value_GetText (OH_Data_Value *value, const char **val )
```

**Description**

Obtains the string from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Double pointer to the string obtained. You do not need to apply for or release memory for it. The lifecycle of **val** complies with the value of **index** in **value**.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

### OH_Value_GetType()

```
int OH_Value_GetType (OH_Data_Value *value, OH_ColumnType *type )
```

**Description**

Obtains the data type.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| type | Pointer to the data type obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_GetUnlimitedInt()

```
int OH_Value_GetUnlimitedInt (OH_Data_Value *value, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen )
```

**Description**

Obtains the unlimited integer from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| sign | Pointer to the sign notation of the data obtained. The value **0** indicates a positive integer, and **1** indicates a negative integer.|
| trueForm | Pointer to the integer array obtained. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|
| inLen | **trueForm** length, which can be obtained by using [OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband).|
| outLen | Pointer to the length of the obtained data.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

**See**

[OH_Value_GetUnlimitedIntBand](#oh_value_getunlimitedintband).


### OH_Value_GetUnlimitedIntBand()

```
int OH_Value_GetUnlimitedIntBand (OH_Data_Value *value, size_t *length )
```

**Description**

Obtains the length of the unlimited integer from an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| length | Pointer to the length of the integer obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

### OH_Value_IsNull()

```
int OH_Value_IsNull (OH_Data_Value *value, bool *val )
```

**Description**

Checks whether a value is null.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to a boolean value, which indicates whether the data is null. The value **true** means the data is null; the value **false** means the opposite.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutAsset()

```
int OH_Value_PutAsset (OH_Data_Value *value, const Data_Asset *val )
```

**Description**

Adds an asset to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the **Data_Asset** object to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutAssets()

```
int OH_Value_PutAssets (OH_Data_Value *value, const Data_Asset * const * val, size_t length )
```

**Description**

Adds assets to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the **Data_Asset** object to add.|
| length | Number of elements in the **Data_Asset** array.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutBlob()

```
int OH_Value_PutBlob (OH_Data_Value *value, const unsigned char *val, size_t length )
```

**Description**

Adds BLOB data to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the BLOB data to add.|
| length | Length of the BLOB data to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutFloatVector()

```
int OH_Value_PutFloatVector (OH_Data_Value *value, const float *val, size_t length )
```

**Description**

Adds a float array to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the float array to add.|
| length | Length of the float array to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

### OH_Value_PutInt()

```
int OH_Value_PutInt (OH_Data_Value *value, int64_t val )
```

**Description**

Add integer data.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the integer data to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutNull()

```
int OH_Value_PutNull (OH_Data_Value *value)
```

**Description**

Adds empty data to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutReal()

```
int OH_Value_PutReal (OH_Data_Value *value, double val )
```

**Description**

Adds REAL data to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the REAL data to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutText()

```
int OH_Value_PutText (OH_Data_Value *value, const char *val )
```

**Description**

Adds a string to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| val | Pointer to the string to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Value_PutUnlimitedInt()

```
int OH_Value_PutUnlimitedInt (OH_Data_Value *value, int sign, const uint64_t *trueForm, size_t length )
```

**Description**

Adds an integer array of any length to an **OH_Data_Value** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| value | Pointer to the target [OH_Data_Value](#oh_data_value) instance.|
| sign | Sign notation of the integer array to add. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.|
| trueForm | Pointer to the integer array to add.|
| length | Length of the integer array to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

### OH_Values_Count()

```
int OH_Values_Count (OH_Data_Values *values, size_t *count )
```

**Description**

Obtains the number of records in an [OH_Data_Values](#oh_data_values) instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| count | Pointer to the number of records obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_Create()

```
OH_Data_Values* OH_Values_Create (void )
```

**Description**

Creates an [OH_Data_Values](#oh_data_values) instance to store multiple KV pairs.

**Since**: 18

**Returns**

Returns the pointer to the [OH_Data_Values](#oh_data_values) instance if the operation is successful; returns **nullptr** otherwise. Use [OH_Values_Destroy](#oh_values_destroy) to release the memory in time.

**See**

[OH_Values_Destroy](#oh_values_destroy).


### OH_Values_Destroy()

```
int OH_Values_Destroy (OH_Data_Values *values)
```

**Description**

Destroys an [OH_Data_Values](#oh_data_values) instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the [OH_Data_Values](#oh_data_values) instance to destroy.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_Get()

```
int OH_Values_Get (OH_Data_Values *values, int index, OH_Data_Value **val )
```

**Description**

Obtains data of the **OH_Data_Value** type.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Double pointer to the [OH_Data_Value](#oh_data_value) instance obtained. You do not need to apply for or release memory for it.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

### OH_Values_GetAsset()

```
int OH_Values_GetAsset (OH_Data_Values *values, int index, Data_Asset *val )
```

**Description**

Obtains the asset from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Pointer to the **Data_Asset** object obtained if the operation is successful. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Values_GetAssets()

```
int OH_Values_GetAssets (OH_Data_Values *values, int index, Data_Asset **val, size_t inLen, size_t *outLen )
```

**Description**

Obtains the assets from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Double pointer to the **Data_Asset** object obtained if the operation is successful. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|
| inLen | Size of **val**, which can be obtained by [OH_Values_GetAssetsCount](#oh_values_getassetscount).|
| outLen | Pointer to the length of the obtained data.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

**See**

[OH_Values_GetAssetsCount](#oh_values_getassetscount).


### OH_Values_GetAssetsCount()

```
int OH_Values_GetAssetsCount (OH_Data_Values *values, int index, size_t *length )
```

**Description**

Obtains the length of the asset in an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance. Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| length | Pointer to the length of the ASSETS data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Values_GetBlob()

```
int OH_Values_GetBlob (OH_Data_Values *values, int index, const uint8_t **val, size_t *length )
```

**Description**

Obtains the BLOB data from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Double pointer to the BLOB data obtained. You do not need to apply for or release memory for it. The lifecycle of **val** complies with the value of **index** in **values**.|
| length | Pointer to the length of the BLOB data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

### OH_Values_GetFloatVector()

```
int OH_Values_GetFloatVector (OH_Data_Values *values, int index, float *val, size_t inLen, size_t *outLen )
```

**Description**

Obtains the float array from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Pointer to the float array obtained. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|
| inLen | Size of **val**, which can be obtained by using [OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount).|
| outLen | Pointer to the length of the obtained data.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

**See**

[OH_Values_GetFloatVectorCount](#oh_values_getfloatvectorcount).


### OH_Values_GetFloatVectorCount()

```
int OH_Values_GetFloatVectorCount (OH_Data_Values *values, int index, size_t *length )
```

**Description**

Obtains the length of the float array in an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| length | Pointer to the length of the float data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Values_GetInt()

```
int OH_Values_GetInt (OH_Data_Values *values, int index, int64_t *val )
```

**Description**

Obtains the integer from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Pointer to the integer data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

### OH_Values_GetReal()

```
int OH_Values_GetReal (OH_Data_Values *values, int index, double *val )
```

**Description**

Obtains the REAL data from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Pointer to the REAL data obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Values_GetText()

```
int OH_Values_GetText (OH_Data_Values *values, int index, const char **val )
```

**Description**

Obtains the string from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| val | Double pointer to the string obtained. You do not need to apply for or release memory for it. The lifecycle of **val** complies with the value of **index** in **values**.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Values_GetType()

```
int OH_Values_GetType (OH_Data_Values *values, int index, OH_ColumnType *type )
```

**Description**

Obtains the data type.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| type | Pointer to the data type obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_GetUnlimitedInt()

```
int OH_Values_GetUnlimitedInt (OH_Data_Values *values, int index, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen )
```

**Description**

Obtains the unlimited integer from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| sign | Pointer to the sign notation of the data obtained. The value **0** indicates a positive integer, and **1** indicates a negative integer.|
| trueForm | Pointer to the integer array obtained. You need to apply for memory for it. This function is used to fill in data only. Otherwise, the operation fails.|
| inLen | **trueForm** length, which can be obtained by using [OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband).|
| outLen | Pointer to the length of the obtained data.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.

**See**

[OH_Values_GetUnlimitedIntBand](#oh_values_getunlimitedintband).


### OH_Values_GetUnlimitedIntBand()

```
int OH_Values_GetUnlimitedIntBand (OH_Data_Values *values, int index, size_t *length )
```

**Description**

Obtains the length of the unlimited integer from an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to obtain, which starts from 0 in **values**.|
| length | Pointer to the length of the integer obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.

**RDB_E_TYPE_MISMATCH** indicates the data types do not match.


### OH_Values_IsNull()

```
int OH_Values_IsNull (OH_Data_Values *values, int index, bool *val )
```

**Description**

Checks whether a value is null.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| index | Index of the value to check, which starts from 0 in **values**.|
| val | Pointer to a boolean value, which indicates whether the data is null. The value **true** means the data is null; the value **false** means the opposite.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

### OH_Values_Put()

```
int OH_Values_Put (OH_Data_Values *values, const OH_Data_Value *val )
```

**Description**

Adds data of the **OH_Data_Value** type to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the [OH_Data_Value](#oh_data_value) object to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutAsset()

```
int OH_Values_PutAsset (OH_Data_Values *values, const Data_Asset *val )
```

**Description**

Adds an asset to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the **Data_Asset** object to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutAssets()

```
int OH_Values_PutAssets (OH_Data_Values *values, const Data_Asset * const * val, size_t length )
```

**Description**

Adds assets to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the **Data_Asset** object to add.|
| length | Number of elements in the **Data_Asset** object to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutBlob()

```
int OH_Values_PutBlob (OH_Data_Values *values, const unsigned char *val, size_t length )
```

**Description**

Adds BLOB data to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the BLOB data to add.|
| length | Length of the BLOB data to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutFloatVector()

```
int OH_Values_PutFloatVector (OH_Data_Values *values, const float *val, size_t length )
```

**Description**

Adds a float array to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the float array to add.|
| length | Length of the float array to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutInt()

```
int OH_Values_PutInt (OH_Data_Values *values, int64_t val )
```

**Description**

Adds an integer to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the integer to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutNull()

```
int OH_Values_PutNull (OH_Data_Values *values)
```

**Description**

Adds empty data to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutReal()

```
int OH_Values_PutReal (OH_Data_Values *values, double val )
```

**Description**

Adds REAL data to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the REAL data to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutText()

```
int OH_Values_PutText (OH_Data_Values *values, const char *val )
```

**Description**

Adds a string to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| val | Pointer to the string to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Values_PutUnlimitedInt()

```
int OH_Values_PutUnlimitedInt (OH_Data_Values *values, int sign, const uint64_t *trueForm, size_t length )
```

**Description**

Adds an integer array of any length to an **OH_Data_Values** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| values | Pointer to the target [OH_Data_Values](#oh_data_values) instance.|
| sign | Sign notation of the integer array to add. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.|
| trueForm | Pointer to the integer array to add.|
| length | Length of the integer array to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

### OH_VBucket_PutFloatVector()

```
int OH_VBucket_PutFloatVector (OH_VBucket *bucket, const char *field, const float *vec, size_t len )
```

**Description**

Puts a float array into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| vec | Pointer to the float array to put.|
| len | Length of the float array to put.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### OH_VBucket_PutUnlimitedInt()

```
int OH_VBucket_PutUnlimitedInt (OH_VBucket *bucket, const char *field, int sign, const uint64_t *trueForm, size_t len )
```

**Description**

Puts an integer of any length into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| sign | Sing notation of the integer object. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.|
| trueForm | Pointer to the integer object to put.|
| len | Length of the integer object to put.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### OH_VBuckets_Create()

```
OH_Data_VBuckets* OH_VBuckets_Create (void)
```

**Description**

Creates an **OH_Data_VBuckets** instance.

**Since**: 18

**Returns**

Returns the pointer to the [OH_Data_VBuckets](#oh_data_vbuckets) instance if the operation is successful; returns **nullptr** otherwise. Use [OH_VBuckets_Destroy](#oh_vbuckets_destroy) to release the memory in time.

**See**

[OH_VBuckets_Destroy](#oh_vbuckets_destroy).


### OH_VBuckets_Destroy()

```
int OH_VBuckets_Destroy (OH_Data_VBuckets *buckets)
```

**Description**

Destroys an **OH_Data_VBuckets** instance.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| buckets | Pointer to the [OH_Data_VBuckets](#oh_data_vbuckets) instance to destroy.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_VBuckets_PutRow()

```
int OH_VBuckets_PutRow (OH_Data_VBuckets *buckets, const OH_VBucket *row )
```

**Description**

Adds data of the **OH_VBucket** type.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| buckets | Pointer to the target [OH_Data_VBuckets](#oh_data_vbuckets) instance.|
| row | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_VBuckets_PutRows()

```
int OH_VBuckets_PutRows (OH_Data_VBuckets *buckets, const OH_Data_VBuckets *rows )
```

**Description**

Adds data of the **OH_Data_VBuckets** type.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| buckets | Pointer to the target [OH_Data_VBuckets](#oh_data_vbuckets) instance.|
| rows | Pointer to the [OH_Data_VBuckets](#oh_data_vbuckets) instance to add.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_VBuckets_RowCount()

```
int OH_VBuckets_RowCount (OH_Data_VBuckets *buckets, size_t *count )
```

**Description**

Obtains the number of **OH_VBuckets** in **OH_Data_VBuckets**.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| buckets | Pointer to the target [OH_Data_VBuckets](#oh_data_vbuckets) instance.|
| count | Pointer to the number of [OH_VBuckets](_o_h___v_bucket.md) in [OH_Data_VBuckets](#oh_data_vbuckets) obtained.|

**Returns**

Returns the operation status code.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

### OH_Rdb_CreateOrOpen()

```
OH_Rdb_Store *OH_Rdb_CreateOrOpen (const OH_Rdb_ConfigV2 *config, int *errCode )
```

**Description**

Creates or opens an [OH_Rdb_Store](_o_h___rdb___store.md) instance based on the given [OH_Rdb_ConfigV2](#oh_rdb_configv2).

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| errCode | Pointer to the execution result of this API. **RDB_OK** indicates that the operation is successful. <br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

**Returns**

Returns the pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_ConfigV2](#oh_rdb_configv2), [OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_BeginTransWithTrxId()

```
int OH_Rdb_BeginTransWithTrxId (OH_Rdb_Store *store, int64_t *trxId )
```

**Description**

Begins a transaction. This API returns a transaction ID. This API supports only vector stores.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| trxId | Pointer to the transaction ID returned.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CommitByTrxId()

```
int OH_Rdb_CommitByTrxId (OH_Rdb_Store *store, int64_t trxId )
```

**Description**

Commits the executed SQL statements based on the specified transaction ID. This API supports only vector stores.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| trxId | Transaction ID.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful. 

**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>Possible causes: A null pointer is passed in; the transaction ID is not obtained by [OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid); the transaction ID has been used by [OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid); the transaction ID has been used by [OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid).

**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CreateConfig()

```
OH_Rdb_ConfigV2 *OH_Rdb_CreateConfig ()
```

**Description**

Creates an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Returns**

Returns a pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance created.

**See**

[OH_Rdb_ConfigV2](#oh_rdb_configv2)



### OH_Rdb_DeleteStoreV2()

```
int OH_Rdb_DeleteStoreV2 (const OH_Rdb_ConfigV2 *config)
```

**Description**

Deletes an RDB store based on the given [OH_Rdb_ConfigV2](#oh_rdb_configv2). For a vector store, ensure that the vector store is correctly closed before calling this API.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the database configuration.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**See**

OH_Rdb_ErrCode.


### OH_Rdb_DestroyConfig()

```
int OH_Rdb_DestroyConfig (OH_Rdb_ConfigV2 *config)
```

**Description**

Destroys an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_ExecuteByTrxId()

```
int OH_Rdb_ExecuteByTrxId (OH_Rdb_Store *store, int64_t trxId, const char *sql )
```

**Description**

Executes an SQL statement that returns no value based on the specified transaction ID. This API supports only vector stores.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| trxId | Transaction ID returned by [OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid). The value **0** indicates that no transaction is enabled.|
| sql | Pointer to the SQL statement to execute.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>Possible causes: A null pointer is passed in; the transaction ID is not obtained by [OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid); the transaction ID has been used by [OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid); the transaction ID has been used by [OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid); **store** or **sql** is **NULL**.

**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetSupportedDbType()

```
const int *OH_Rdb_GetSupportedDbType (int *typeCount)
```

**Description**

Obtains the supported database types.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| typeCount | Pointer to the length of the array of the supported database types obtained.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_RollBackByTrxId()

```
int OH_Rdb_RollBackByTrxId (OH_Rdb_Store *store, int64_t trxId )
```

**Description**

Rolls back the executed SQL statements based on the specified transaction ID. This API supports only vector stores.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| trxId | ID of the transaction to be rolled back.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>Possible causes: A null pointer is passed in; the transaction ID is not obtained by [OH_Rdb_BeginTransWithTrxId](#oh_rdb_begintranswithtrxid); the transaction ID has been used by [OH_Rdb_CommitByTrxId](#oh_rdb_commitbytrxid); the transaction ID has been used by [OH_Rdb_RollBackByTrxId](#oh_rdb_rollbackbytrxid).

**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetArea()

```
int OH_Rdb_SetArea (OH_Rdb_ConfigV2 *config, int area )
```

**Description**

Sets the [Rdb_SecurityArea](#rdb_securityarea) for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| area | Database file encryption level to set. For details, see [Rdb_SecurityArea](#rdb_securityarea).|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_SetBundleName()

```
int OH_Rdb_SetBundleName (OH_Rdb_ConfigV2 *config, const char *bundleName )
```

**Description**

Sets the application bundle name for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| bundleName | Pointer to the application bundle name to set.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_SetDatabaseDir()

```
int OH_Rdb_SetDatabaseDir (OH_Rdb_ConfigV2 *config, const char *databaseDir )
```

**Description**

Sets the database file path for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| dataBaseDir | Pointer to the database file path to set. The full path, including the RDB store name, cannot exceed a maximum of 1024 characters.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_SetDbType()

```
int OH_Rdb_SetDbType (OH_Rdb_ConfigV2 *config, int dbType )
```

**Description**

Sets the [Rdb_DBType](#rdb_dbtype) for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| dbType | Database type to set. For details, see [Rdb_DBType](#rdb_dbtype).|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**RDB_E_NOT_SUPPORTED** indicates that the current operation is not supported.


### OH_Rdb_SetEncrypted()

```
int OH_Rdb_SetEncrypted (OH_Rdb_ConfigV2 *config, bool isEncrypted )
```

**Description**

Sets whether to encrypt the RDB store for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| isEncrypted | Whether to encrypt the RDB store. The value **true** means to encrypt the database, the value **false** means the opposite.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_SetModuleName()

```
int OH_Rdb_SetModuleName (OH_Rdb_ConfigV2 *config, const char *moduleName )
```

**Description**

Sets the module name for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| moduleName | Pointer to the module name to set.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_SetSecurityLevel()

```
int OH_Rdb_SetSecurityLevel (OH_Rdb_ConfigV2 *config, int securityLevel )
```

**Description**

Sets the [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| securityLevel | RDB store security level to set. For details, see [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel).|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.


### OH_Rdb_SetStoreName()

```
int OH_Rdb_SetStoreName (OH_Rdb_ConfigV2 *config, const char *storeName )
```

**Description**

Sets the RDB store name for an [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance.

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_ConfigV2](#oh_rdb_configv2) instance, which is the configuration of the RDB store.|
| storeName | Pointer to the RDB store name to set.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

### OH_Rdb_Backup()

```
int OH_Rdb_Backup (OH_Rdb_Store *store, const char *databasePath )
```

**Description**

Backs up an RDB store using the backup file of the specified path. This API supports vector stores.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| databasePath | Pointer to the destination directory, in which the RDB store is backed up.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_BeginTransaction()

```
int OH_Rdb_BeginTransaction (OH_Rdb_Store *store)
```

**Description**

Begins the transaction before executing SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance to close.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| mode | Sync mode [Rdb_SyncMode](#rdb_syncmode).|
| tables | Pointer to the tables to sync.|
| count | Number of tables to sync. If the value is **0**, all tables in the RDB store are synced.|
| observer | [Rdb_ProgressObserver](_rdb___progress_observer.md) of the device-cloud sync progress.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| table | Pointer to the name of the database table.|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the deletion conditions.|

**Returns**

Returns the number of deleted rows if the operation is successful; returns a number less than <b>0</b> otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).


### OH_Rdb_DeleteStore()

```
int OH_Rdb_DeleteStore (const OH_Rdb_Config *config)
```

**Description**

Deletes an RDB store with the specified configuration.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the database configuration.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.


### OH_Rdb_Execute()

```
int OH_Rdb_Execute (OH_Rdb_Store *store, const char *sql )
```

**Description**

Executes an SQL statement that returns no value.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| sql | Pointer to the SQL statement to execute.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_ExecuteQuery()

```
OH_Cursor* OH_Rdb_ExecuteQuery (OH_Rdb_Store *store, const char *sql )
```

**Description**

Queries data in the database using the specified SQL statement. This API supports vector stores.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| sql | Pointer to the SQL statement to execute.|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| tableName | Pointer to the target distributed database table.|
| columnName | Pointer to the column of the database table to query.|
| values | Pointer to the primary keys of the rows to query. If the database table has no primary key, **rowid** must be passed in through **columnName**. In this case, **values** specifies the row number of the database table to query.|

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

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_Config](_o_h___rdb___config.md) instance, which specifies the database configuration.|
| errCode | Function execution status.|

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

| Name| Description|
| -------- | -------- |
| progress | Pointer to the **OH_ProgressDetails** instance.|
| version | Version of [Rdb_ProgressDetails](_rdb___progress_details.md).|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| version |  Pointer to the version obtained.|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| table | Pointer to the target table.|
| valuesBucket | Pointer to the data [OH_VBucket](_o_h___v_bucket.md) to insert.|

**Returns**

Returns **rowID** if the operation is successful; returns a number less than **0** otherwise.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the lock conditions.|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the query conditions.|
| columnNames | Pointer to the columns to query. If this parameter is not specified, data of columns will be queried.|
| length | Length of **columnNames**. If <b>length</b> is greater than the length of <b>columnNames</b> array, out-of-bounds access occurs.|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the query conditions.|
| columnNames | Pointer to the columns to query. If this parameter is not specified, data of columns will be queried.|
| length | Length of **columnNames**. If <b>length</b> is greater than the length of <b>columnNames</b> array, out-of-bounds access occurs.|

**Returns**

Returns the pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md), [OH_Cursor](_o_h___cursor.md).

### OH_Rdb_Restore()

```
int OH_Rdb_Restore (OH_Rdb_Store *store, const char *databasePath )
```

**Description**

Restores a database from a specified database backup file. This API supports vector stores.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| databasePath | Pointer to the destination directory in which the RDB store is backed up.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| tables | Pointer to the names of the distributed tables to set.|
| count | Number of distributed database tables to set.|
| type | [Rdb_DistributedType](#rdb_distributedtype).|
| config | Configuration of the distributed mode. For details, see [Rdb_DistributedConfig](_rdb___distributed_config.md).|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| version | Version to set.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| type | Subscription type defined in [Rdb_SubscribeType](#rdb_subscribetype).|
| observer | Pointer to the [Rdb_DataObserver](_rdb___data_observer.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_DataObserver](_rdb___data_observer.md).


### OH_Rdb_SubscribeAutoSyncProgress()

```
int OH_Rdb_SubscribeAutoSyncProgress (OH_Rdb_Store *store, const Rdb_ProgressObserver *observer )
```

**Description**

Subscribes to the auto sync progress of an RDB store. The registered callback will be invoked to return the auto sync progress. **RDB_OK** indicates that the operation is successful. <br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the target [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| observer | Pointer to the [Rdb_ProgressObserver](_rdb___progress_observer.md) instance, which invokes the callback to return the automatic sync progress.|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the unlock conditions.|

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| type | Subscription type defined in [Rdb_SubscribeType](#rdb_subscribetype).|
| observer | Pointer to the [Rdb_DataObserver](_rdb___data_observer.md) instance to unregister. If this parameter is **nullptr**, all observers of this type will be unregistered.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).

[Rdb_DataObserver](_rdb___data_observer.md).


### OH_Rdb_UnsubscribeAutoSyncProgress()

```
int OH_Rdb_UnsubscribeAutoSyncProgress (OH_Rdb_Store *store, const Rdb_ProgressObserver *observer )
```

**Description**

Unsubscribes from the auto sync process of an RDB store.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the target [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| observer | Pointer to [Rdb_ProgressObserver](_rdb___progress_observer.md) to unregister. If the pointer is null, all callbacks for the auto sync process will be unregistered.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**RDB_OK** indicates that the operation is successful.

**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.

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

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| valuesBucket | Pointer to the new [OH_VBucket](_o_h___v_bucket.md) to be inserted to the table.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, specifying the update conditions.|

**Returns**

Returns the number of updated rows if the operation is successful; returns a number less than **0** otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Bucket](_o_h___v_bucket.md), [OH_Predicates](_o_h___predicates.md).


### OH_VBucket_PutAsset()

```
int OH_VBucket_PutAsset (OH_VBucket *bucket, const char *field, OH_Asset *value )
```

**Description**

Puts an **OH_Asset** object into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| value | Pointer to the data to put.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### OH_VBucket_PutAssets()

```
int OH_VBucket_PutAssets (OH_VBucket *bucket, const char *field, OH_Asset **value, int count )
```

**Description**

Puts an array of **OH_Asset** objects into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| value | Double pointer to the data to put.|
| count | Number of elements in the **OH_Asset** array.|

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

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

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

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

**Returns**

Returns the predicates with a left parenthesis.

**See**

[OH_Predicates](_o_h___predicates.md).


### between

```
OH_Predicates *(*between) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are within the specified range.

This method is equivalent to **BETWEEN** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

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

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

**Returns**

Cleared predicates.

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

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|

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

Number of the changed primary keys or row numbers.


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

Location where data is deleted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, the value is the row number of the deleted data.


### destroy [1/4]

```
int(*destroy) (OH_Cursor *cursor)
```

**Description**

Pointer to the function used to destroy a result set.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|

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

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

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

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|

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

| Name| Description|
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance.|

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

Pointer to the function used to create a predicates object to filter out duplicate records.

This method is equivalent to **DISTINCT** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

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

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

**Returns**

Returns the predicates object with a right parenthesis.

**See**

[OH_Predicates](_o_h___predicates.md).


### equalTo

```
OH_Predicates *(*equalTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are equal to the specified value.

This method is equivalent to "=" in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### failed

```
int Rdb_Statistic::failed
```

**Description**

Number of rows that failed to be synced between the device and cloud in the database table.


### getAsset

```
int(*getAsset) (OH_Cursor *cursor, int32_t columnIndex, Data_Asset *value)
```

**Description**

Pointer to the function used to obtain the value of the asset type based on the specified column and the current row.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| value | Pointer to the value obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| value | Double pointer to the value obtained.|
| length | Length of the buffer, which is a variable of the uint32_t type passed in. After the API is executed, the variable is updated to the length of the returned asset array.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| value | Pointer to the values in the form of a byte array obtained.|
| length | Length of **value**, obtained by using **getSize**.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| count | Pointer to the number of columns in the result set obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| name | Pointer to the column name in the result set.|
| columnIndex | Pointer to the column index obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| name | Pointer to the column name obtained.|
| length | Total length of the column name obtained, including the terminator.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| columnType | Pointer to the [OH_ColumnType](#oh_columntype) obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| value | Pointer to the value obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| value | Pointer to the value obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| count | Pointer to the number of columns in the result set obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| size | Pointer to the memory size obtained.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| value | Pointer to the value of the string type obtained.|
| length | Length of **value**, obtained by using **getSize**.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### greaterThan

```
OH_Predicates *(*greaterThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are greater than the specified value.

This method is equivalent to "&gt;" in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### greaterThanOrEqualTo

```
OH_Predicates *(*greaterThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are greater than or equal to the specified value.

This method is equivalent to "&gt;=" in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### groupBy

```
OH_Predicates *(*groupBy) (OH_Predicates *predicates, char const *const *fields, int length)
```

**Description**

Pointer to the function used to create a predicates object to group the results by the specified columns.

This method is equivalent to **GROUP BY** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| fields | Pointer to the names of the columns by which the records are grouped.|
| length | Length of **fields**.|

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

Pointer to the function used to create a predicates object to search for the field values that are within the specified range.

This method is equivalent to **IN** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### inserted

```
Rdb_KeyInfo Rdb_ChangeInfo::inserted
```

**Description**

Location where data is inserted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, the value is the row number of the inserted data.


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

Whether the table supports auto sync.


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

Pointer to the function used to create a predicates object to search for the field values that are not null.

This method is equivalent to **IS NOT NULL** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|

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

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Index of the column, which starts from **0**.|
| isNull | Pointer to the value returned. The value **true** means the value is null; the value **false** means the opposite.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### isNull [2/2]

```
OH_Predicates *(*isNull) (OH_Predicates *predicates, const char *field)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are null.

This method is equivalent to **IS NULL** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### lessThan

```
OH_Predicates *(*lessThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the records that are less than the given value in the specified field.

This method is equivalent to "&lt;" in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### lessThanOrEqualTo

```
OH_Predicates *(*lessThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the records that are less than or equal to the specified **valueObject** in the specified field.

This method is equivalent to "&lt;=" in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### like

```
OH_Predicates *(*like) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are similar to the specified string.

This method is equivalent to **LIKE** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### limit

```
OH_Predicates *(*limit) (OH_Predicates *predicates, unsigned int value)
```

**Description**

Pointer to the function used to create a predicates object to specify the maximum number of records.

This method is equivalent to **LIMIT** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| value | Maximum number of data records.|

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

Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.

This method is equivalent to **NOT BETWEEN** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notEqualTo

```
OH_Predicates *(*notEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are not equal to the specified value.

This method is equivalent to "!=" in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notIn

```
OH_Predicates *(*notIn) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.

This method is equivalent to **NOT IN** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the start and end values.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### offset

```
OH_Predicates *(*offset) (OH_Predicates *predicates, unsigned int rowOffset)
```

**Description**

Pointer to the function used to create a predicates object to specify the start position of the query result.

This method is equivalent to **OFFSET** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| rowOffset | Start position of the returned result. The value is a positive integer.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### orderBy

```
OH_Predicates *(*orderBy) (OH_Predicates *predicates, const char *field, OH_OrderType type)
```

**Description**

Pointer to the function used to create a predicates object to sort the values in the specified column in ascending or descending order.

This method is equivalent to **ORDER BY** in SQL statements.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| type | Sorting type [OH_OrderType](#oh_ordertype).|

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

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

**Returns**

Returns the predicates with the OR operator.

**See**

[OH_Predicates](_o_h___predicates.md).


### putBlob

```
int(*putBlob) (OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)
```

**Description**

Pointer to the function used to put a const uint8_t value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| value | Pointer to the value to put.|
| size | Length of the value.|

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

| Name| Description|
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance.|
| value | Pointer to the data to covert.|
| count | If **value** points to a single parameter, **count** is **1**. If **value** points to an array, **count** specifies the length of the array.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### putInt64 [1/2]

```
int(*putInt64) (OH_VBucket *bucket, const char *field, int64_t value)
```

**Description**

Pointer to the function used to put an int64_t value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| value | Pointer to the value to put.|

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

| Name| Description|
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance.|
| value | Pointer to the data to covert.|
| count | If **value** points to a single parameter, **count** is **1**. If **value** points to an array, **count** specifies the length of the array.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### putNull

```
int(*putNull) (OH_VBucket *bucket, const char *field)
```

**Description**

Pointer to the function used to put a null value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### putReal

```
int(*putReal) (OH_VBucket *bucket, const char *field, double value)
```

**Description**

Pointer to the function used to put a double value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| value | Pointer to the value to put.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### putText [1/2]

```
int(*putText) (OH_VBucket *bucket, const char *field, const char *value)
```

**Description**

Pointer to the function used to put a char value into an [OH_VBucket](_o_h___v_bucket.md) object in the given column.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|
| field | Pointer to the column name in the database table.|
| value | Pointer to the value to put.|

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

| Name| Description|
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance.|
| value | Pointer to the character array to convert.|

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

| Name| Description|
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance.|
| value | Double pointer to the string array to convert.|
| count | Length of the string array to convert.|

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

Number of rows that are successfully synced between the device and cloud in the database table.


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

Number of the tables synced between the device and cloud.


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

Total number of rows to be synced between the device and cloud in the database table.


### type

```
int Rdb_KeyInfo::type
```

**Description**

[OH_ColumnType](#oh_columntype) of the primary key.


### updated

```
Rdb_KeyInfo Rdb_ChangeInfo::updated
```

**Description**

Location where data is updated. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, the value is the row number of the updated data.


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

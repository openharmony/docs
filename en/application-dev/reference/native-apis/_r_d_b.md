# RDB


## Overview

The relational database (RDB) store manages data based on relational models. The RDB store provides a complete mechanism for managing local databases based on the underlying SQLite. It provides a series of methods for performing operations, such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements to satisfy different needs in complicated scenarios.

\@SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**

10


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_cursor.h](oh__cursor_8h.md) | Provides APIs to access the result set obtained by querying the RDB store.<br>**File to include**: \<database/rdb/oh_cursor.h><br> **Library**: libnative_rdb_ndk.z.so|
| [oh_predicates.h](oh__predicates_8h.md) | Defines the predicates for RDB stores.<br>**File to include**: \<database/rdb/oh_predicates.h><br> **Library**: libnative_rdb_ndk.z.so|
| [oh_value_object.h](oh__value__object_8h.md) | Provides type conversion methods.<br>**File to include**: \<database/rdb/oh_value_object.h><br> **Library**: libnative_rdb_ndk.z.so|
| [oh_values_bucket.h](oh__values__bucket_8h.md) | Defines the types of the key and value in a key-value (KV) pair.<br>**File to include**: \<database/rdb/oh_values_bucket.h><br> **Library**: libnative_rdb_ndk.z.so|
| [relational_store.h](relational__store_8h.md) | Provides APIs to manage an RDB store.<br>**File to include**: \<database/rdb/relational_store.h><br> **Library**: libnative_rdb_ndk.z.so|
| [relational_store_error_code.h](relational__store__error__code_8h.md) | Defines the error codes used for RDB stores.<br>**File to include**: \<database/rdb/relational_error_code.h><br> **Library**: libnative_rdb_ndk.z.so|


### Structs

| Name| Description|
| -------- | -------- |
| [OH_Cursor](_o_h___cursor.md) | Defines a result set.|
| [OH_Predicates](_o_h___predicates.md) | Defines a **predicates** object.|
| [OH_VObject](_o_h___v_object.md) | Defines the allowed data field types.|
| [OH_VBucket](_o_h___v_bucket.md) | Defines the types of the key and value in a KV pair.|
| [OH_Rdb_Config](_o_h___rdb___config.md) | Defines the RDB store configuration.|
| [OH_Rdb_Store](_o_h___rdb___store.md) | Defines the RDB store type.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_ColumnType](#oh_columntype) | Defines an enum for the types of the fields in an RDB store.|
| [OH_Cursor](#oh_cursor) | Defines a struct for a result set.|
| [OH_OrderType](#oh_ordertype) | Defines an enum for sorting types.|
| [OH_Predicates](#oh_predicates) | Defines a **predicates** object.|
| [OH_VObject](#oh_vobject) | Defines a struct for allowed data field types.|
| [OH_VBucket](#oh_vbucket) | Defines a struct for the types of the key and value in a KV pair.|
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) | Defines an enum for RDB store security levels.|
| [OH_Rdb_ErrCode](#oh_rdb_errcode) | Defines an enum for error codes.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_ColumnType](#oh_columntype) {<br>TYPE_NULL = 0, TYPE_INT64, TYPE_REAL, TYPE_TEXT,<br>TYPE_BLOB<br>} | Enumerates the types of the fields in an RDB store.|
| [OH_OrderType](#oh_ordertype) { ASC = 0, DESC = 1 } | Enumerates the sorting types.|
| [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel) { S1 = 1, S2, S3, S4 } | Enumerates the RDB store security levels.|
| [OH_Rdb_ErrCode](#oh_rdb_errcode) {<br>RDB_ERR = -1, RDB_OK = 0, E_BASE = 14800000, RDB_E_NOT_SUPPORTED = 801,<br>RDB_E_ERROR = E_BASE, RDB_E_INVALID_ARGS = (E_BASE + 1), RDB_E_CANNOT_UPDATE_READONLY = (E_BASE + 2), RDB_E_REMOVE_FILE = (E_BASE + 3),<br>RDB_E_EMPTY_TABLE_NAME = (E_BASE + 5), RDB_E_EMPTY_VALUES_BUCKET = (E_BASE + 6), RDB_E_EXECUTE_IN_STEP_QUERY = (E_BASE + 7), RDB_E_INVALID_COLUMN_INDEX = (E_BASE + 8),<br>RDB_E_INVALID_COLUMN_TYPE = (E_BASE + 9), RDB_E_EMPTY_FILE_NAME = (E_BASE + 10), RDB_E_INVALID_FILE_PATH = (E_BASE + 11), RDB_E_TRANSACTION_IN_EXECUTE = (E_BASE + 12),<br>RDB_E_INVALID_STATEMENT = (E_BASE + 13), RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION = (E_BASE + 14), RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION = (E_BASE + 15), RDB_E_NO_TRANSACTION_IN_SESSION = (E_BASE + 16),<br>RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION = (E_BASE + 17), RDB_E_NO_ROW_IN_QUERY = (E_BASE + 18), RDB_E_INVALID_BIND_ARGS_COUNT = (E_BASE + 19), RDB_E_INVALID_OBJECT_TYPE = (E_BASE + 20),<br>RDB_E_INVALID_CONFLICT_FLAG = (E_BASE + 21), RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY = (E_BASE + 22), RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET = (E_BASE + 23), RDB_E_STEP_RESULT_SET_CROSS_THREADS = (E_BASE + 24),<br>RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED = (E_BASE + 25), RDB_E_STEP_RESULT_IS_AFTER_LAST = (E_BASE + 26), RDB_E_STEP_RESULT_QUERY_EXCEEDED = (E_BASE + 27), RDB_E_STATEMENT_NOT_PREPARED = (E_BASE + 28),<br>RDB_E_EXECUTE_RESULT_INCORRECT = (E_BASE + 29), RDB_E_STEP_RESULT_CLOSED = (E_BASE + 30), RDB_E_RELATIVE_PATH = (E_BASE + 31), RDB_E_EMPTY_NEW_ENCRYPT_KEY = (E_BASE + 32),<br>RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED = (E_BASE + 33), RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY = (E_BASE + 34), RDB_E_STEP_STATEMENT_NOT_INIT = (E_BASE + 35), RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE = (E_BASE + 36),<br>RDB_E_CREATE_FOLDER_FAIL = (E_BASE + 37), RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL = (E_BASE + 38), RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY = (E_BASE + 39), RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION = (E_BASE + 40),<br>RDB_E_NOT_SUPPORT = (E_BASE + 41), RDB_E_INVALID_PARCEL = (E_BASE + 42), RDB_E_QUERY_IN_EXECUTE = (E_BASE + 43), RDB_E_SET_PERSIST_WAL = (E_BASE + 44),<br>RDB_E_DB_NOT_EXIST = (E_BASE + 45), RDB_E_ARGS_READ_CON_OVERLOAD = (E_BASE + 46), RDB_E_WAL_SIZE_OVER_LIMIT = (E_BASE + 47), RDB_E_CON_OVER_LIMIT = (E_BASE + 48)<br>} | Enumerates the RDB store error codes.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Rdb_CreateValueObject](#oh_rdb_createvalueobject) (void) | Creates an [OH_VObject](_o_h___v_object.md) instance.|
| [OH_Rdb_CreateValuesBucket](#oh_rdb_createvaluesbucket) (void) | Creates an [OH_VBucket](_o_h___v_bucket.md) instance.|
| [OH_Rdb_CreatePredicates](#oh_rdb_createpredicates) (const char \*table) | Creates an [OH_Predicates](_o_h___predicates.md) instance.|
| [OH_Rdb_GetOrOpen](#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | Obtains an [OH_Rdb_Store](_o_h___rdb___store.md) instance for RDB store operations.|
| [OH_Rdb_CloseStore](#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Destroys an [OH_Rdb_Store](_o_h___rdb___store.md) object to reclaim the memory occupied.|
| [OH_Rdb_DeleteStore](#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | Deletes an RDB store with the specified database file configuration.|
| [OH_Rdb_Insert](#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | Inserts a row of data into a table.|
| [OH_Rdb_Update](#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | Updates data in an RDB store based on specified conditions.|
| [OH_Rdb_Delete](#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Deletes data from an RDB store based on specified conditions.|
| [OH_Rdb_Query](#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | Queries data in an RDB store based on specified conditions.|
| [OH_Rdb_Execute](#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Executes an SQL statement but returns no value.|
| [OH_Rdb_ExecuteQuery](#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Executes the SQL statement to query data in an RDB store.|
| [OH_Rdb_BeginTransaction](#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Starts the transaction before executing the SQL statement.|
| [OH_Rdb_RollBack](#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Rolls back the SQL statements executed.|
| [OH_Rdb_Commit](#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Commits the executed SQL statements.|
| [OH_Rdb_Backup](#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Backs up an RDB store in the specified directory.|
| [OH_Rdb_Restore](#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Restores an RDB store from the specified database backup file.|
| [OH_Rdb_GetVersion](#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | Obtains the RDB store version.|
| [OH_Rdb_SetVersion](#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | Sets the RDB store version.|


### Variables

| Name| Description|
| -------- | -------- |
| OH_Cursor::id | Unique identifier of the **OH_Cursor** struct.|
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
| [OH_Predicates::id](#id-14) | Unique identifier of the **OH_Predicates** struct.|
| [OH_Predicates::equalTo](#equalto) | Pointer to the function used to set a predicates object to match the field whose value is equal to the specified value.|
| [OH_Predicates::notEqualTo](#notequalto) | Pointer to the function used to set a predicates object to match the field whose value is not equal to the specified value.|
| [OH_Predicates::beginWrap](#beginwrap) | Pointer to the function used to add a left parenthesis to the predicates.|
| [OH_Predicates::endWrap](#endwrap) | Pointer to the function used to add a right parenthesis to the predicates.|
| [OH_Predicates::orOperate](#oroperate) | Pointer to the function used to add the OR operator to the predicates.|
| [OH_Predicates::andOperate](#andoperate) | Pointer to the function used to add the AND operator to the predicates.|
| [OH_Predicates::isNull](#isnull-22) | Pointer to the function used to set a predicates object to match the field whose value is null.|
| [OH_Predicates::isNotNull](#isnotnull) | Pointer to the function used to set a predicates object to match the field whose value is not null.|
| [OH_Predicates::like](#like) | Pointer to the function used to set a predicates object to match a string that is similar to the specified value.|
| [OH_Predicates::between](#between) | Pointer to the function used to set a predicates object to match the field whose value is within the specified range.|
| [OH_Predicates::notBetween](#notbetween) | Pointer to the function used to set a predicates object to match the field whose value is out of the specified range.|
| [OH_Predicates::greaterThan](#greaterthan) | Pointer to the function used to set a predicates object to match the field with value greater than the specified value.|
| [OH_Predicates::lessThan](#lessthan) | Pointer to the function used to set a predicates object to match the field with value less than the specified value.|
| [OH_Predicates::greaterThanOrEqualTo](#greaterthanorequalto) | Pointer to the function used to set a predicates object to match the field with value greater than or equal to the specified value.|
| [OH_Predicates::lessThanOrEqualTo](#lessthanorequalto) | Pointer to the function used to set a predicates object to match the field with value less than or equal to the specified value.|
| [OH_Predicates::orderBy](#orderby) | Pointer to the function used to set a predicates object to sort the values in a column in ascending or descending order.|
| [OH_Predicates::distinct](#distinct) | Pointer to the function used to set a predicates object to filter out duplicate records.|
| [OH_Predicates::limit](#limit) | Pointer to the function used to set a predicates object to specify the maximum number of records.|
| [OH_Predicates::offset](#offset) | Pointer to the function used to set a predicates object to specify the start position of the returned result.|
| [OH_Predicates::groupBy](#groupby) | Pointer to the function used to set a predicates object to group rows that have the same value into summary rows.|
| [OH_Predicates::in](#in) | Pointer to the function used to set a predicates object to match the field with the value within the specified range.|
| [OH_Predicates::notIn](#notin) | Pointer to the function used to set a predicates object to match the field with the value out of the specified range.|
| [OH_Predicates::clear](#clear-12) | Pointer to the function used to clear a predicates instance.|
| [OH_Predicates::destroy](#destroy-24) | Pointer to the function used to destroy an [OH_Predicates](_o_h___predicates.md) object to reclaim the memory occupied.|
| [OH_VObject::id](#id-24) | Unique identifier of the **OH_VObject** struct.|
| [OH_VObject::putInt64](#putint64-22) | Pointer to the function used to convert a single parameter or an array of the int64 type into a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::putDouble](#putdouble) | Pointer to the function used to convert a single parameter or an array of the double type into a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::putText](#puttext-22) | Pointer to the function used to convert a character array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::putTexts](#puttexts) | Pointer to the function used to convert a string array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.|
| [OH_VObject::destroy](#destroy-44) | Pointer to the function used to destroy an [OH_VObject](_o_h___v_object.md) object to reclaim the memory occupied.|
| [OH_VBucket::id](#id-34) | Unique identifier of the **OH_VBucket** struct.|
| [OH_VBucket::capability](#capability) | Number of the KV pairs in the struct.|
| [OH_VBucket::putText](#puttext-12) | Pointer to the function used to put a char value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::putInt64](#putint64-12) | Pointer to the function used to put an int64_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::putReal](#putreal) | Pointer to the function used to put a double value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::putBlob](#putblob) | Pointer to the function used to put a const uint8_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::putNull](#putnull) | Pointer to the function used to put a null value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.|
| [OH_VBucket::clear](#clear-22) | Pointer to the function used to clear an [OH_VBucket](_o_h___v_bucket.md) object.|
| [OH_VBucket::destroy](#destroy-34) | Pointer to the function used to destroy an [OH_VBucket](_o_h___v_bucket.md) object to reclaim the memory occupied.|
| [OH_Rdb_Config::selfSize](#selfsize) | Size of the struct.|
| [OH_Rdb_Config::dataBaseDir](#databasedir) | Path of the database file.|
| [OH_Rdb_Config::storeName](#storename) | Name of the RDB store.|
| [OH_Rdb_Config::bundleName](#bundlename) | Bundle name.|
| [OH_Rdb_Config::moduleName](#modulename) | Module name. |
| [OH_Rdb_Config::isEncrypt](#isencrypt) | Whether to encrypt the RDB store.|
| [OH_Rdb_Config::securityLevel](#securitylevel) | RDB store security level. For details, see [OH_Rdb_SecurityLevel](#oh_rdb_securitylevel).|
| [OH_Rdb_Store::id](#id-44) | Unique identifier of the **OH_Rdb_Store** struct.|


## Type Description


### OH_ColumnType

```
typedef enum OH_ColumnType OH_ColumnType
```

**Description**

Defines an enum for the types of the fields in an RDB store.


### OH_Cursor

```
typedef struct OH_Cursor OH_Cursor
```

**Description**

Defines a struct for a result set.

APIs are provided to access the result set obtained by querying the RDB store.


### OH_OrderType

```
typedef enum OH_OrderType OH_OrderType
```

**Description**

Defines an enum for sorting types.


### OH_Predicates

```
typedef struct OH_Predicates OH_Predicates
```

**Description**

Defines a **predicates** object.


### OH_Rdb_ErrCode

```
typedef enum OH_Rdb_ErrCode OH_Rdb_ErrCode
```

**Description**

Defines an enum for error codes.


### OH_Rdb_SecurityLevel

```
typedef enum OH_Rdb_SecurityLevel OH_Rdb_SecurityLevel
```

**Description**

Defines an enum for RDB store security levels.


### OH_VBucket

```
typedef struct OH_VBucket OH_VBucket
```

**Description**

Defines a struct for the types of the key and value in a KV pair.


### OH_VObject

```
typedef struct OH_VObject OH_VObject
```

**Description**

Defines a struct for allowed data field types.


## Enum Description


### OH_ColumnType

```
enum OH_ColumnType
```

**Description**

Enumerates the field types in an RDB store.

| Value| Description|
| -------- | -------- |
| TYPE_NULL | NULL.|
| TYPE_INT64 | INT64.|
| TYPE_REAL | REAL.|
| TYPE_TEXT | TEXT.|
| TYPE_BLOB | BLOB.|


### OH_OrderType

```
enum OH_OrderType
```

**Description**

Enumerates the sorting types.

| Value| Description|
| -------- | -------- |
| ASC | Ascending order.|
| DESC | Descending order.|


### OH_Rdb_ErrCode

```
enum OH_Rdb_ErrCode
```

**Description**

Enumerates the error codes.

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
| RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY | The HAVING keyword can be used only after GROUP BY.|
| RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET | The result set by step is not supported.|
| RDB_E_STEP_RESULT_SET_CROSS_THREADS | Failed to obtain the result set.|
| RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED | The result set query statement is not executed.|
| RDB_E_STEP_RESULT_IS_AFTER_LAST | The cursor of the result set is already in the last row.|
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


### OH_Rdb_SecurityLevel

```
enum OH_Rdb_SecurityLevel
```

**Description**

Enumerates the RDB store security levels.

| Value| Description|
| -------- | -------- |
| S1 | The security level of the RDB store is low.<br>If data leakage occurs, minor impact will be caused.|
| S2 | The security level of the RDB store is medium.<br>If data leakage occurs, moderate impact will be caused.|
| S3 | The security level of the RDB store is high.<br>If data leakage occurs, major impact will be caused.|
| S4 | The security level of the RDB store is critical.<br>If data leakage occurs, critical impact will be caused.|


## Function Description


### OH_Rdb_Backup()

```
int OH_Rdb_Backup (OH_Rdb_Store * store, const char * databasePath )
```

**Description**

Backs up an RDB store in the specified directory.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| databasePath | Pointer to the destination directory in which the RDB store is backed up.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_BeginTransaction()

```
int OH_Rdb_BeginTransaction (OH_Rdb_Store * store)
```

**Description**

Starts the transaction before executing the SQL statement.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CloseStore()

```
int OH_Rdb_CloseStore (OH_Rdb_Store * store)
```

**Description**

Destroys an [OH_Rdb_Store](_o_h___rdb___store.md) object to reclaim the memory occupied.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Commit()

```
int OH_Rdb_Commit (OH_Rdb_Store * store)
```

**Description**

Commits the executed SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_CreatePredicates()

```
OH_Predicates* OH_Rdb_CreatePredicates (const char * table)
```

**Description**

Creates an [OH_Predicates](_o_h___predicates.md) instance.

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
OH_VObject* OH_Rdb_CreateValueObject (void)
```

**Description**

Creates an [OH_VObject](_o_h___v_object.md) instance.

**Returns**

Returns the pointer to the [OH_VObject](_o_h___v_object.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### OH_Rdb_CreateValuesBucket()

```
OH_VBucket* OH_Rdb_CreateValuesBucket (void)
```

**Description**

Creates an [OH_VBucket](_o_h___v_bucket.md) instance.

**Returns**

Returns the pointer to the [OH_VBucket](_o_h___v_bucket.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### OH_Rdb_Delete()

```
int OH_Rdb_Delete (OH_Rdb_Store * store, OH_Predicates * predicates )
```

**Description**

Deletes data from an RDB store based on specified conditions.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the deletion conditions.|

**Returns**

Returns the number of affected rows if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md).


### OH_Rdb_DeleteStore()

```
int OH_Rdb_DeleteStore (const OH_Rdb_Config * config)
```

**Description**

Deletes an RDB store with the specified database file configuration.

**Parameters**

| Name| Description|
| -------- | -------- |
| path | Pointer to the database path.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.


### OH_Rdb_Execute()

```
int OH_Rdb_Execute (OH_Rdb_Store * store, const char * sql )
```

**Description**

Executes an SQL statement but returns no value.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| sql | Pointer to the SQL statement to execute.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_ExecuteQuery()

```
OH_Cursor* OH_Rdb_ExecuteQuery (OH_Rdb_Store * store, const char * sql )
```

**Description**

Executes the SQL statement to query data in an RDB store.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| sql | Pointer to the SQL statement to execute.|

**Returns**

Returns the pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetOrOpen()

```
OH_Rdb_Store* OH_Rdb_GetOrOpen (const OH_Rdb_Config * config, int * errCode )
```

**Description**

Obtains an [OH_Rdb_Store](_o_h___rdb___store.md) instance for RDB store operations.

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the [OH_Rdb_Config](_o_h___rdb___config.md) instance, which specifies the database configuration.|
| errCode | Function execution status.|

**Returns**

Returns the pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance created if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Config](_o_h___rdb___config.md), [OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_GetVersion()

```
int OH_Rdb_GetVersion (OH_Rdb_Store * store, int * version )
```

**Description**

Obtains the RDB store version.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| version | Pointer to the version number.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Insert()

```
int OH_Rdb_Insert (OH_Rdb_Store * store, const char * table, OH_VBucket * valuesBucket )
```

**Description**

Inserts a row of data into a table.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| table | Pointer to the target table.|
| valuesBucket | Pointer to the data [OH_VBucket](_o_h___v_bucket.md) to insert.|

**Returns**

Returns the row ID if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_VBucket](_o_h___v_bucket.md).


### OH_Rdb_Query()

```
OH_Cursor* OH_Rdb_Query (OH_Rdb_Store * store, OH_Predicates * predicates, const char *const * columnNames, int length )
```

**Description**

Queries data in an RDB store based on specified conditions.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, which specifies the query conditions.|
| columnNames | Pointer to the columns to query. If this parameter is not specified, data of columns will be queried.|
| length | Length of the **columnNames** array. If <b>length</b> is greater than the length of <b>columnNames</b> array, out-of-bounds access occurs.|

**Returns**

Returns the pointer to the [OH_Cursor](_o_h___cursor.md) instance if the operation is successful; returns null otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), [OH_Predicates](_o_h___predicates.md), [OH_Cursor](_o_h___cursor.md).


### OH_Rdb_Restore()

```
int OH_Rdb_Restore (OH_Rdb_Store * store, const char * databasePath )
```

**Description**

Restores an RDB store from the specified database backup file.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| databasePath | Pointer to the destination directory in which the RDB store is backed up.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_RollBack()

```
int OH_Rdb_RollBack (OH_Rdb_Store * store)
```

**Description**

Rolls back the SQL statements executed.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_SetVersion()

```
int OH_Rdb_SetVersion (OH_Rdb_Store * store, int version )
```

**Description**

Sets the RDB store version.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| version | Version number to set.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md).


### OH_Rdb_Update()

```
int OH_Rdb_Update (OH_Rdb_Store * store, OH_VBucket * valuesBucket, OH_Predicates * predicates )
```

**Description**

Updates data in an RDB store based on specified conditions.

**Parameters**

| Name| Description|
| -------- | -------- |
| store | Pointer to the [OH_Rdb_Store](_o_h___rdb___store.md) instance.|
| valuesBucket | Pointer to the new data [OH_VBucket](_o_h___v_bucket.md) to be updated to the table.|
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance, specifying the update conditions.|

**Returns**

Returns the number of affected rows if the operation is successful; returns an error code otherwise.

**See**

[OH_Rdb_Store](_o_h___rdb___store.md), OH_Bucket, [OH_Predicates](_o_h___predicates.md).


## Variable Description


### andOperate

```
OH_Predicates*(* OH_Predicates::andOperate) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add the AND operator to the predicates.

This method is equivalent to **AND** in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

**Returns**

Returns the predicates with the AND operator.

**See**

[OH_Predicates](_o_h___predicates.md).


### beginWrap

```
OH_Predicates*(* OH_Predicates::beginWrap) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add a left parenthesis to the predicates.

This method is equivalent to "(" in SQL statements.

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
OH_Predicates*(* OH_Predicates::between) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is within the specified range.

This method is equivalent to **BETWEEN** in SQL statements.

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

### storeName

```
const char* OH_Rdb_Config::storeName
```

**Description**

Name of the RDB store.

### bundleName

```
const char* OH_Rdb_Config::bundleName
```

**Description**

Bundle name.


### capability

```
uint16_t OH_VBucket::capability
```

**Description**

Number of the KV pairs in the struct.


### clear [1/2]

```
OH_Predicates*(* OH_Predicates::clear) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to clear a predicates instance.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

**Returns**

Returns the cleared predicates.

**See**

[OH_Predicates](_o_h___predicates.md).


### clear [2/2]

```
int(* OH_VBucket::clear) (OH_VBucket *bucket)
```

**Description**

Pointer to the function used to clear an [OH_VBucket](_o_h___v_bucket.md) object.

**Parameters**

| Name| Description|
| -------- | -------- |
| bucket | Pointer to the [OH_VBucket](_o_h___v_bucket.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VBucket](_o_h___v_bucket.md).


### dataBaseDir

```
const char* OH_Rdb_Config::dataBaseDir
```

**Description**

Path of the database file.


### destroy [1/4]

```
int(* OH_Cursor::destroy) (OH_Cursor *cursor)
```

**Description**

Pointer to the function used to destroy a result set.

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
int(* OH_Predicates::destroy) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to destroy an [OH_Predicates](_o_h___predicates.md) object to reclaim the memory occupied.

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
int(* OH_VBucket::destroy) (OH_VBucket *bucket)
```

**Description**

Pointer to the function used to destroy an [OH_VBucket](_o_h___v_bucket.md) object to reclaim the memory occupied.

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
int(* OH_VObject::destroy) (OH_VObject *valueObject)
```

**Description**

Pointer to the function used to destroy an [OH_VObject](_o_h___v_object.md) object to reclaim the memory occupied.

**Parameters**

| Name| Description|
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


### distinct

```
OH_Predicates*(* OH_Predicates::distinct) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to set a predicates object to filter out duplicate records.

This method is equivalent to **DISTINCT** in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### endWrap

```
OH_Predicates*(* OH_Predicates::endWrap) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add a right parenthesis to the predicates.

This method is equivalent to ")" in SQL statements.

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
OH_Predicates*(* OH_Predicates::equalTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is equal to the specified value.

This method is equivalent to "=" in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### getBlob

```
int(* OH_Cursor::getBlob) (OH_Cursor *cursor, int32_t columnIndex, unsigned char *value, int length)
```

**Description**

Pointer to the function used to obtain the values in the form of a byte array based on the specified column and the current row.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| value | Pointer to the values in the form of a byte array obtained.|
| length | Length of the value, which can be obtained by **getSize()**.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getColumnCount

```
int(* OH_Cursor::getColumnCount) (OH_Cursor *cursor, int *count)
```

**Description**

Pointer to the function used to obtain the number of columns in the result set.

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
int(* OH_Cursor::getColumnIndex) (OH_Cursor *cursor, const char *name, int *columnIndex)
```

**Description**

Pointer to the function used to obtain the column index based on the specified column name.

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
int(* OH_Cursor::getColumnName) (OH_Cursor *cursor, int32_t columnIndex, char *name, int length)
```

**Description**

Pointer to the function used to obtain the column name based on the specified column index.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| name | Pointer to the column name obtained.|
| length | Length of a column name.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getColumnType

```
int(* OH_Cursor::getColumnType) (OH_Cursor *cursor, int32_t columnIndex, OH_ColumnType *columnType)
```

**Description**

Pointer to the function used to obtain the column type based on the specified column index.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| columnType | Pointer to the [OH_ColumnType](#oh_columntype) obtained.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md), [OH_ColumnType](#oh_columntype).


### getInt64

```
int(* OH_Cursor::getInt64) (OH_Cursor *cursor, int32_t columnIndex, int64_t *value)
```

**Description**

Pointer to the function used to obtain the value of the int64_t type based on the specified column and the current row.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| value | Pointer to the value obtained.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getReal

```
int(* OH_Cursor::getReal) (OH_Cursor *cursor, int32_t columnIndex, double *value)
```

**Description**

Pointer to the function used to obtain the value of the double type based on the specified column and the current row.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| value | Pointer to the value obtained.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getRowCount

```
int(* OH_Cursor::getRowCount) (OH_Cursor *cursor, int *count)
```

**Description**

Pointer to the function used to obtain the number of rows in the result set.

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
int(* OH_Cursor::getSize) (OH_Cursor *cursor, int32_t columnIndex, size_t *size)
```

**Description**

Pointer to the function used to obtain information about the memory required when the column data type in the result set is **BLOB** or **TEXT**.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| size | Pointer to the memory size obtained.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### getText

```
int(* OH_Cursor::getText) (OH_Cursor *cursor, int32_t columnIndex, char *value, int length)
```

**Description**

Pointer to the function used to obtain the value of the string type based on the specified column and the current row.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| value | Pointer to the value of the string type obtained.|
| length | Length of the value, which can be obtained by **getSize()**.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### goToNextRow

```
int(* OH_Cursor::goToNextRow) (OH_Cursor *cursor)
```

**Description**

Pointer to the function used to go to the next row of the result set.

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
OH_Predicates*(* OH_Predicates::greaterThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value greater than the specified value.

This method is equivalent to "&gt;" in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### greaterThanOrEqualTo

```
OH_Predicates*(* OH_Predicates::greaterThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value greater than or equal to the specified value.

This method is equivalent to "&gt;=" in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### groupBy

```
OH_Predicates*(* OH_Predicates::groupBy) (OH_Predicates *predicates, char const *const *fields, int length)
```

**Description**

Pointer to the function used to set a predicates object to group rows that have the same value into summary rows.

This method is equivalent to **GROUP BY** in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| fields | Pointer to the names of the columns by which the records are grouped.|
| length | Length of the **fields** value.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md).


### id [1/4]

```
int64_t OH_Predicates::id
```

**Description**

Unique identifier of the **OH_Predicates** struct.


### id [2/4]

```
int64_t OH_VObject::id
```

**Description**

Unique identifier of the **OH_VObject** struct.


### id [3/4]

```
int64_t OH_VBucket::id
```

**Description**

Unique identifier of the **OH_VBucket** struct.


### id [4/4]

```
int64_t OH_Rdb_Store::id
```

**Description**

Unique identifier of the **OH_Rdb_Store** struct.


### in

```
OH_Predicates*(* OH_Predicates::in) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with the value within the specified range.

This method is equivalent to **IN** in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value range.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### isEncrypt

```
bool OH_Rdb_Config::isEncrypt
```

**Description**

Whether to encrypt the RDB store.


### isNotNull

```
OH_Predicates*(* OH_Predicates::isNotNull) (OH_Predicates *predicates, const char *field)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is not null.

This method is equivalent to **IS NOT NULL** in SQL statements.

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
int(* OH_Cursor::isNull) (OH_Cursor *cursor, int32_t columnIndex, bool *isNull)
```

**Description**

Pointer to the function used to check whether the value in the specified column is null.

**Parameters**

| Name| Description|
| -------- | -------- |
| cursor | Pointer to the [OH_Cursor](_o_h___cursor.md) instance.|
| columnIndex | Column index.|
| isNull | Pointer to the value returned. The value **true** means the value is null; the value **false** means the opposite.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_Cursor](_o_h___cursor.md).


### isNull [2/2]

```
OH_Predicates*(* OH_Predicates::isNull) (OH_Predicates *predicates, const char *field)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is null.

This method is equivalent to **IS NULL** in SQL statements.

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
OH_Predicates*(* OH_Predicates::lessThan) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value less than the specified value.

This method is equivalent to "&lt;" in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### lessThanOrEqualTo

```
OH_Predicates*(* OH_Predicates::lessThanOrEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with value less than or equal to the specified value.

This method is equivalent to "&lt;=" in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### like

```
OH_Predicates*(* OH_Predicates::like) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match a string that is similar to the specified value.

This method is equivalent to **LIKE** in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### limit

```
OH_Predicates*(* OH_Predicates::limit) (OH_Predicates *predicates, unsigned int value)
```

**Description**

Pointer to the function used to set a predicates object to specify the maximum number of records.

This method is equivalent to **LIMIT** in SQL statements.

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
OH_Predicates*(* OH_Predicates::notBetween) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is out of the specified range.

This method is equivalent to **NOT BETWEEN** in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notEqualTo

```
OH_Predicates*(* OH_Predicates::notEqualTo) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field whose value is not equal to the specified value.

This method is equivalent to "!=" in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### notIn

```
OH_Predicates*(* OH_Predicates::notIn) (OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to set a predicates object to match the field with the value out of the specified range.

This method is equivalent to **NOT IN** in SQL statements.

**Parameters**

| Name| Description|
| -------- | -------- |
| predicates | Pointer to the [OH_Predicates](_o_h___predicates.md) instance.|
| field | Pointer to the column name in the database table.|
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance, which specifies the value range to match.|

**Returns**

Returns the predicates created.

**See**

[OH_Predicates](_o_h___predicates.md), [OH_VObject](_o_h___v_object.md).


### offset

```
OH_Predicates*(* OH_Predicates::offset) (OH_Predicates *predicates, unsigned int rowOffset)
```

**Description**

Pointer to the function used to set a predicates object to specify the start position of the returned result.

This method is equivalent to **OFFSET** in SQL statements.

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
OH_Predicates*(* OH_Predicates::orderBy) (OH_Predicates *predicates, const char *field, OH_OrderType type)
```

**Description**

Pointer to the function used to set a predicates object to sort the values in a column in ascending or descending order.

This method is equivalent to **ORDER BY** in SQL statements.

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
OH_Predicates*(* OH_Predicates::orOperate) (OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add the OR operator to the predicates.

This method is equivalent to **OR** in SQL statements.

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
int(* OH_VBucket::putBlob) (OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)
```

**Description**

Pointer to the function used to put a const uint8_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

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
int(* OH_VObject::putDouble) (OH_VObject *valueObject, double *value, uint32_t count)
```

**Description**

Pointer to the function used to convert a single parameter or an array of the double type into a value of the [OH_VObject](_o_h___v_object.md) type.

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
int(* OH_VBucket::putInt64) (OH_VBucket *bucket, const char *field, int64_t value)
```

**Description**

Pointer to the function used to put an int64_t value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

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
int(* OH_VObject::putInt64) (OH_VObject *valueObject, int64_t *value, uint32_t count)
```

**Description**

Pointer to the function used to convert a single parameter or an array of the int64 type into a value of the [OH_VObject](_o_h___v_object.md) type.

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
int(* OH_VBucket::putNull) (OH_VBucket *bucket, const char *field)
```

**Description**

Pointer to the function used to put a null value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

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
int(* OH_VBucket::putReal) (OH_VBucket *bucket, const char *field, double value)
```

**Description**

Puts a double value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

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
int(* OH_VBucket::putText) (OH_VBucket *bucket, const char *field, const char *value)
```

**Description**

Pointer to the function used to put a char value into the [OH_VBucket](_o_h___v_bucket.md) object in the given column.

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
int(* OH_VObject::putText) (OH_VObject *valueObject, const char *value)
```

**Description**

Pointer to the function used to convert a character array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.

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
int(* OH_VObject::putTexts) (OH_VObject *valueObject, const char **value, uint32_t count)
```

**Description**

Pointer to the function used to convert a string array of the char type to a value of the [OH_VObject](_o_h___v_object.md) type.

**Parameters**

| Name| Description|
| -------- | -------- |
| valueObject | Pointer to the [OH_VObject](_o_h___v_object.md) instance.|
| value | Pointer to the string array to convert.|
| count | Length of the string array to convert.|

**Returns**

Returns **RDB_OK** if the operation is successful; returns an error code otherwise.

**See**

[OH_VObject](_o_h___v_object.md).


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

# oh_rdb_transaction.h

## Overview

Defines APIs and enums related to transactions.

**File to include**: <database/rdb/oh_rdb_transaction.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 18

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                                              | typedef Keyword      | Description                                                        |
| -------------------------------------------------- | ------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) | OH_RDB_TransOptions | Defines the [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) struct.|
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)   | OH_Rdb_Transaction  | Defines the [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) struct.|

### Enums

| Name                                 | typedef Keyword   | Description                      |
| ------------------------------------- | ---------------- | -------------------------- |
| [OH_RDB_TransType](#oh_rdb_transtype) | OH_RDB_TransType | Enumerates the transaction types of an RDB store.|

### Functions

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_RDB_TransOptions *OH_RdbTrans_CreateOptions(void)](#oh_rdbtrans_createoptions) | Creates a **TransOptions** instance.                         |
| [int OH_RdbTrans_DestroyOptions(OH_RDB_TransOptions *options)](#oh_rdbtrans_destroyoptions) | Destroys a **TransOptions** instance.                        |
| [int OH_RdbTransOption_SetType(OH_RDB_TransOptions *options, OH_RDB_TransType type)](#oh_rdbtransoption_settype) | Sets the transaction type of an RDB store.                   |
| [int OH_RdbTrans_Commit(OH_Rdb_Transaction *trans)](#oh_rdbtrans_commit) | Commits a transaction.                                       |
| [int OH_RdbTrans_Rollback(OH_Rdb_Transaction *trans)](#oh_rdbtrans_rollback) | Rolls back a transaction.                                    |
| [int OH_RdbTrans_Insert(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId)](#oh_rdbtrans_insert) | Inserts a row of data into a table.                          |
| [int OH_RdbTrans_InsertWithConflictResolution(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row,Rdb_ConflictResolution resolution, int64_t *rowId)](#oh_rdbtrans_insertwithconflictresolution) | Inserts a row of data into a table with conflict resolutions. |
| [int OH_RdbTrans_BatchInsert(OH_Rdb_Transaction *trans, const char *table, const OH_Data_VBuckets *rows,Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdbtrans_batchinsert) | Inserts a batch of data into a table.                        |
| [int OH_RdbTrans_Update(OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates,int64_t *changes)](#oh_rdbtrans_update) | Updates data in an RDB store based on specified conditions.  |
| [int OH_RdbTrans_UpdateWithConflictResolution(OH_Rdb_Transaction *trans, const OH_VBucket *row,const OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdbtrans_updatewithconflictresolution) | Updates data in the database based on specified conditions and supports conflict resolution. |
| [int OH_RdbTrans_Delete(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes)](#oh_rdbtrans_delete) | Deletes data from the database based on the specified conditions. |
| [OH_Cursor *OH_RdbTrans_Query(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[],int len)](#oh_rdbtrans_query) | Queries data in the database based on specified conditions.  |
| [OH_Cursor *OH_RdbTrans_QuerySql(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args)](#oh_rdbtrans_querysql) | Queries data in the database using the specified SQL statement. |
| [int OH_RdbTrans_Execute(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result)](#oh_rdbtrans_execute) | Executes an SQL statement that contains specified parameters. |
| [int OH_RdbTrans_Destroy(OH_Rdb_Transaction *trans)](#oh_rdbtrans_destroy) | Destroys a transaction object.                               |

## Enum Description

### OH_RDB_TransType

```
enum OH_RDB_TransType
```

**Description**

Enumerates the transaction types of an RDB store.

**Since**: 18

| Enum Item                | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| RDB_TRANS_DEFERRED = 0 | Do not start any transaction before the database is accessed for the first time.                |
| RDB_TRANS_IMMEDIATE    | Start new writes without waiting for the write statement once the database is connected.            |
| RDB_TRANS_EXCLUSIVE    | Start the write transaction immediately, similar to **RDB_TRANS_IMMEDIATE**.<br>In WAL mode, **RDB_TRANS_EXCLUSIVE** is the same as **RDB_TRANS_IMMEDIATE**. In other log modes, **RDB_TRANS_EXCLUSIVE** prevents other database connections when the transaction is reading the database.|
| RDB_TRANS_BUTT         | Maximum value of the RDB transaction type.                                       |


## Function Description

### OH_RdbTrans_CreateOptions()

```
OH_RDB_TransOptions *OH_RdbTrans_CreateOptions(void)
```

**Description**

Creates a transaction configuration object.

**Since**: 18

**Returns**

| Type                                              | Description                                                        |
| -------------------------------------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) | Returns a pointer to the [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) instance if the operation is successful; returns **nullptr** otherwise.<br>Use [OH_RdbTrans_DestroyOptions](capi-oh-rdb-transaction-h.md#oh_rdbtrans_destroyoptions) to release the memory in time.|

### OH_RdbTrans_DestroyOptions()

```
int OH_RdbTrans_DestroyOptions(OH_RDB_TransOptions *options)
```

**Description**

Destroys a **TransOptions** instance.

**Since**: 18


**Parameters**

| Name                                                     | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) *options | Pointer to the [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_RdbTransOption_SetType()

```
int OH_RdbTransOption_SetType(OH_RDB_TransOptions *options, OH_RDB_TransType type)
```

**Description**

Sets the transaction type of an RDB store.

**Since**: 18


**Parameters**

| Name                                                     | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) *options | Pointer to the [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) instance.|
| [OH_RDB_TransType](#oh_rdb_transtype) type                  | Transaction type to set.                                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_RdbTrans_Commit()

```
int OH_RdbTrans_Commit(OH_Rdb_Transaction *trans)
```

**Description**

Commits a transaction.

**Since**: 18


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.|

### OH_RdbTrans_Rollback()

```
int OH_RdbTrans_Rollback(OH_Rdb_Transaction *trans)
```

**Description**

Rolls back a transaction.

**Since**: 18


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.|

### OH_RdbTrans_Insert()

```
int OH_RdbTrans_Insert(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId)
```

**Description**

Inserts a row of data into a table.

**Since**: 18


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const char *table                                       | Pointer to the target table.                                                |
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row             | Row of data to insert.                                  |
| int64_t *rowId                                          | Pointer to the row number returned.                            |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.|

### OH_RdbTrans_InsertWithConflictResolution()

```
int OH_RdbTrans_InsertWithConflictResolution(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row,Rdb_ConflictResolution resolution, int64_t *rowId)
```

**Description**

Inserts a row of data into a table with conflict resolutions.

**Since**: 20


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const char *table                                       | Name of the target table.                                            |
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row             | Pointer to the row of data to insert.                                    |
| Rdb_ConflictResolution resolution                       | Policy used to resolve file conflicts.                                  |
| int64_t *rowId                                          | Pointer to the row number returned.                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_RdbTrans_BatchInsert()

```
int OH_RdbTrans_BatchInsert(OH_Rdb_Transaction *trans, const char *table, const OH_Data_VBuckets *rows,Rdb_ConflictResolution resolution, int64_t *changes)
```

**Description**

Inserts a batch of data into a table.

**Since**: 18


**Parameters**

| Name                                                  | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const char *table                                        | Pointer to the target table.                                                |
| const [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *rows | An array of data to insert.                                |
| Rdb_ConflictResolution resolution                        | Policy used to resolve file conflicts.                                  |
| int64_t *changes                                         | Pointer to the number of successful insertions.                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_RdbTrans_Update()

```
int OH_RdbTrans_Update(OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates,int64_t *changes)
```

**Description**

Updates data in an RDB store based on specified conditions.

**Since**: 18


**Parameters**

| Name                                                  | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row              | Pointer to the row of data to update.                                  |
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the update conditions.  |
| int64_t *changes                                         | Pointer to the number of successful updates.                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.|

### OH_RdbTrans_UpdateWithConflictResolution()

```
int OH_RdbTrans_UpdateWithConflictResolution(OH_Rdb_Transaction *trans, const OH_VBucket *row,const OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes)
```

**Description**

Updates data in the database based on specified conditions and supports conflict resolution.

**Since**: 20


**Parameters**

| Name                                                  | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row              | Pointer to the row of data to update.                                    |
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the update conditions.  |
| Rdb_ConflictResolution resolution                        | Policy used to resolve file conflicts.                                  |
| int64_t *changes                                         | Pointer to the number of successful updates.                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.<br>**RDB_E_SQLITE_CONSTRAINT** indicates an SQLite error code: SQLite constraint.|

### OH_RdbTrans_Delete()

```
int OH_RdbTrans_Delete(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes)
```

**Description**

Deletes data from the database based on the specified conditions.

**Since**: 18


**Parameters**

| Name                                                  | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the deletion conditions.  |
| int64_t *changes                                         | Pointer to the number of successful deletions.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.|

### OH_RdbTrans_Query()

```
OH_Cursor *OH_RdbTrans_Query(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[],int len)
```

**Description**

Queries data in the database based on specified conditions.

**Since**: 18


**Parameters**

| Name                                                  | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance, specifying the query conditions.  |
| columns                                                  | Pointer to the column to be queried. If the value is not specified, the query applies to all columns.          |
| int len                                                  | Number of elements in a column.                                        |

**Returns**

| Type                          | Description                                                        |
| ------------------------------ | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) | Returns a pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance if the operation is successful; returns null if the database is closed or does not respond.|

### OH_RdbTrans_QuerySql()

```
OH_Cursor *OH_RdbTrans_QuerySql(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args)
```

**Description**

Queries data in the database using the specified SQL statement.

**Since**: 18


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const char *sql                                         | Pointer to the SQL statement to execute.                                       |
| const [OH_Data_Values](capi-rdb-oh-data-values.md) *args    | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.    |

**Returns**

| Type                          | Description                                                        |
| ------------------------------ | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) | Returns a pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance if the operation is successful; returns null if the database is closed or does not respond.|

### OH_RdbTrans_Execute()

```
int OH_RdbTrans_Execute(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result)
```

**Description**

Executes an SQL statement that contains specified parameters.

**Since**: 18


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|
| const char *sql                                         | Pointer to the SQL statement to execute.                                       |
| const [OH_Data_Values](capi-rdb-oh-data-values.md) *args    | Pointer to the parameters contained in the SQL statement.                                       |
| OH_Data_Value **result                                  | Double pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance. After the execution is complete, you must release the memory by calling [OH_Value_Destroy](capi-oh-data-value-h.md#oh_value_destroy).|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns the execution result.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_WAL_SIZE_OVER_LIMIT** indicates that the size of the WAL log file exceeds the default value.<br>**RDB_E_SQLITE_FULL** indicates an SQLite error: the database is full.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_READONLY** indicates an SQLite error: attempt to write a read-only database.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.|

### OH_RdbTrans_Destroy()

```
int OH_RdbTrans_Destroy(OH_Rdb_Transaction *trans)
```

**Description**

Destroys a transaction object.

**Since**: 18


**Parameters**

| Name                                                 | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | Pointer to the [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

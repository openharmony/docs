# relational_store_error_code.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Declares the error codes used for relational database (RDB) stores.

**File to include**: <database/rdb/relational_store_error_code.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

## Summary

### Enums

| Name                             | typedef Keyword | Description            |
| --------------------------------- | -------------- | ---------------- |
| [OH_Rdb_ErrCode](#oh_rdb_errcode) | OH_Rdb_ErrCode | Enumerates the RDB store error codes.|

## Enum Description

### OH_Rdb_ErrCode

```
enum OH_Rdb_ErrCode
```

**Description**

Enumerates the RDB store error codes.

**Since**: 10

| Enum Item                                                      | Description                                                       |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| RDB_ERR = -1                                                 | Execution failed.                                                 |
| RDB_OK = 0                                                   | Execution successful.                                                 |
| E_BASE = 14800000                                            | Base of the error code.                                       |
| RDB_E_NOT_SUPPORTED = 801                                    | The RDB store does not have this capability.                                          |
| RDB_E_ERROR = E_BASE                                         | Common exception.                                       |
| RDB_E_INVALID_ARGS = (E_BASE + 1)                            | Invalid parameter.                                                 |
| RDB_E_CANNOT_UPDATE_READONLY = (E_BASE + 2)                  | Failed to update data because the RDB store is read-only.                                           |
| RDB_E_REMOVE_FILE = (E_BASE + 3)                             | Failed to delete the file.                                             |
| RDB_E_EMPTY_TABLE_NAME = (E_BASE + 5)                        | The table name is empty.                                                 |
| RDB_E_EMPTY_VALUES_BUCKET = (E_BASE + 6)                     | The content of the KV pair is empty.                                           |
| RDB_E_EXECUTE_IN_STEP_QUERY = (E_BASE + 7)                   | The SQL statement executed during the query is incorrect.                                  |
| RDB_E_INVALID_COLUMN_INDEX = (E_BASE + 8)                    | The column index is invalid.                                               |
| RDB_E_INVALID_COLUMN_TYPE = (E_BASE + 9)                     | The column type is invalid.                                               |
| RDB_E_EMPTY_FILE_NAME = (E_BASE + 10)                        | The file name is empty.                                             |
| RDB_E_INVALID_FILE_PATH = (E_BASE + 11)                      | The file path is invalid.                                             |
| RDB_E_TRANSACTION_IN_EXECUTE = (E_BASE + 12)                 | Failed to start the transaction.                                         |
| RDB_E_INVALID_STATEMENT = (E_BASE + 13)                      | Failed to precompile the SQL statements.                                        |
| RDB_E_EXECUTE_WRITE_IN_READ_CONNECTION = (E_BASE + 14)       | Failed to perform a write operation in a read connection.                                     |
| RDB_E_BEGIN_TRANSACTION_IN_READ_CONNECTION = (E_BASE + 15)   | Failed to start the transaction in a read connection.                                       |
| RDB_E_NO_TRANSACTION_IN_SESSION = (E_BASE + 16)              | The transaction to start does not exist in the database session.                           |
| RDB_E_MORE_STEP_QUERY_IN_ONE_SESSION = (E_BASE + 17)         | Multiple queries are executed in a database session.                           |
| RDB_E_NO_ROW_IN_QUERY = (E_BASE + 18)                        | The result set does not contain any record.                           |
| RDB_E_INVALID_BIND_ARGS_COUNT = (E_BASE + 19)                | The number of parameters bound in the SQL statement is invalid.                              |
| RDB_E_INVALID_OBJECT_TYPE = (E_BASE + 20)                    | The object type is invalid.                                             |
| RDB_E_INVALID_CONFLICT_FLAG = (E_BASE + 21)                  | The conflict resolution type is invalid.                                         |
| RDB_E_HAVING_CLAUSE_NOT_IN_GROUP_BY = (E_BASE + 22)          | The **HAVING** keyword can be used only after **GROUP BY**.                          |
| RDB_E_NOT_SUPPORTED_BY_STEP_RESULT_SET = (E_BASE + 23)       | The result set by step is not supported.                               |
| RDB_E_STEP_RESULT_SET_CROSS_THREADS = (E_BASE + 24)          | Failed to obtain the result set.                                           |
| RDB_E_STEP_RESULT_QUERY_NOT_EXECUTED = (E_BASE + 25)         | The result set query statement is not executed.                                   |
| RDB_E_STEP_RESULT_IS_AFTER_LAST = (E_BASE + 26)              | The pointer of the result set is already in the last row.                             |
| RDB_E_STEP_RESULT_QUERY_EXCEEDED = (E_BASE + 27)             | The number of result set query times exceeds the limit.                               |
| RDB_E_STATEMENT_NOT_PREPARED = (E_BASE + 28)                 | The SQL statement is not precompiled.                                        |
| RDB_E_EXECUTE_RESULT_INCORRECT = (E_BASE + 29)               | The database execution result is incorrect.                                       |
| RDB_E_STEP_RESULT_CLOSED = (E_BASE + 30)                     | The result set has been closed.                                           |
| RDB_E_RELATIVE_PATH = (E_BASE + 31)                          | The file path is a relative path.                                                 |
| RDB_E_EMPTY_NEW_ENCRYPT_KEY = (E_BASE + 32)                  | The new encrypt key is empty.                                         |
| RDB_E_CHANGE_UNENCRYPTED_TO_ENCRYPTED = (E_BASE + 33)        | The RDB store is non-encrypted and cannot be changed.                         |
| RDB_E_CHANGE_ENCRYPT_KEY_IN_BUSY = (E_BASE + 34)             | The database does not respond when the database key is updated.                             |
| RDB_E_STEP_STATEMENT_NOT_INIT = (E_BASE + 35)                | The precompiled SQL statement is not initialized.                                |
| RDB_E_NOT_SUPPORTED_ATTACH_IN_WAL_MODE = (E_BASE + 36)       | The WAL mode does not support the ATTACH operation.                          |
| RDB_E_CREATE_FOLDER_FAIL = (E_BASE + 37)                     | Failed to create the folder.                                           |
| RDB_E_SQLITE_SQL_BUILDER_NORMALIZE_FAIL = (E_BASE + 38)      | Failed to build the SQL statement.                                          |
| RDB_E_STORE_SESSION_NOT_GIVE_CONNECTION_TEMPORARILY = (E_BASE + 39) | The database session does not provide a connection.                                   |
| RDB_E_STORE_SESSION_NO_CURRENT_TRANSACTION = (E_BASE + 40)   | The transaction does not exist in the database session.                               |
| RDB_E_NOT_SUPPORT = (E_BASE + 41)                            | The current operation is not supported.                                           |
| RDB_E_INVALID_PARCEL = (E_BASE + 42)                         | The current PARCEL is invalid.                                           |
| RDB_E_QUERY_IN_EXECUTE = (E_BASE + 43)                       | Failed to execute query.                                        |
| RDB_E_SET_PERSIST_WAL = (E_BASE + 44)                        | Failed to set the persistence of the database file in WAL mode.                    |
| RDB_E_DB_NOT_EXIST = (E_BASE + 45)                           | The database does not exist.                                             |
| RDB_E_ARGS_READ_CON_OVERLOAD = (E_BASE + 46)                 | The number of read connections to set is greater than the limit.                                   |
| RDB_E_WAL_SIZE_OVER_LIMIT = (E_BASE + 47)                    | The WAL log file size exceeds the default value.                                |
| RDB_E_CON_OVER_LIMIT = (E_BASE + 48)                         | The number of database connections has reached the limit.                                       |
| RDB_E_ALREADY_CLOSED = (E_BASE + 50)                         | The RDB store is already closed.<br>**Since**: 18                        |
| RDB_E_DATABASE_BUSY = (E_BASE + 51)                          | The database does not respond.<br>**Since**: 18                        |
| RDB_E_SQLITE_CORRUPT = (E_BASE + 52)                         | The database is corrupted.<br>**Since**: 18                          |
| RDB_E_SQLITE_PERM = (E_BASE + 53)                            | SQLite: access denied.<br>**Since**: 18        |
| RDB_E_SQLITE_BUSY = (E_BASE + 54)                            | SQLite: database file locked.<br>**Since**: 18      |
| RDB_E_SQLITE_LOCKED = (E_BASE + 55)                          | SQLite: database table locked.<br>**Since**: 18    |
| RDB_E_SQLITE_NOMEM = (E_BASE + 56)                           | SQLite: insufficient database memory.<br>**Since**: 18        |
| RDB_E_SQLITE_READONLY = (E_BASE + 57)                        | SQLite: attempt to write a read-only database.<br>**Since**: 18    |
| RDB_E_SQLITE_IOERR = (E_BASE + 58)                           | SQLite: disk I/O error.<br>**Since**: 18           |
| RDB_E_SQLITE_FULL = (E_BASE + 59)                            | SQLite: database is full.<br>**Since**: 18            |
| RDB_E_SQLITE_CANT_OPEN = (E_BASE + 60)                       | SQLite: unable to open the database file.<br>**Since**: 18    |
| RDB_E_SQLITE_TOO_BIG = (E_BASE + 61)                         | SQLite: TEXT or BLOB exceeds the limit.<br>**Since**: 18|
| RDB_E_SQLITE_MISMATCH = (E_BASE + 62)                        | SQLite: data types mismatch.<br>**Since**: 18        |
| RDB_E_DATA_TYPE_NULL = (E_BASE + 63)                         | The data to be stored is empty.<br>**Since**: 18                    |
| RDB_E_TYPE_MISMATCH = (E_BASE + 64)                          | The data type is incorrect.<br>**Since**: 18                  |
| RDB_E_SQLITE_CONSTRAINT = (E_BASE + 65)                      | SQLite error code: SQLite constraint.<br>**Since**: 18        |

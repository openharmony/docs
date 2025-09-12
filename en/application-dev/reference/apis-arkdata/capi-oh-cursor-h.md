# oh_cursor.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Provides APIs to access the result set obtained by querying the RDB store. A result set is a set of results returned by **query()**.

**File to include**: <database/rdb/oh_cursor.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                          | typedef Keyword| Description                                                        |
| ------------------------------ | ------------- | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) | OH_Cursor     | Provides APIs to access the result set obtained by querying the RDB store. A result set is a set of results returned by **query()**.|

### Functions

| Name                                                        | Description                                      |
| ------------------------------------------------------------ | ------------------------------------------ |
| [int OH_Cursor_GetFloatVectorCount(OH_Cursor *cursor, int32_t columnIndex, size_t *length)](#oh_cursor_getfloatvectorcount) | Obtains the length of a floating-point array in the specified column of the current row.      |
| [int OH_Cursor_GetFloatVector(OH_Cursor *cursor, int32_t columnIndex, float *val, size_t inLen, size_t *outLen)](#oh_cursor_getfloatvector) | Obtains the value in the specified column of the current row in the form of a floating-point array.|

## Function Description

### OH_Cursor_GetFloatVectorCount()

```
int OH_Cursor_GetFloatVectorCount(OH_Cursor *cursor, int32_t columnIndex, size_t *length)
```

**Description**

Obtains the length of a floating-point array in the specified column of the current row.

**Since**: 18


**Parameters**

| Parameter                                | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) *cursor | Pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance.          |
| int32_t columnIndex                    | Index of the column, which starts from **0**.                   |
| size_t *length                         | Pointer to the length of the float array obtained.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_STEP_RESULT_CLOSED** indicates the result set is closed.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.|

### OH_Cursor_GetFloatVector()

```
int OH_Cursor_GetFloatVector(OH_Cursor *cursor, int32_t columnIndex, float *val, size_t inLen, size_t *outLen)
```

**Description**

Obtains the value in the specified column of the current row in the form of a floating-point array.

**Since**: 18


**Parameters**

| Parameter                                | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) *cursor | Pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance.          |
| int32_t columnIndex                    | Index of the column, which starts from **0**.                   |
| float *val                             | Ponter to the value obtained, in a float array. The caller needs to apply for the memory.|
| size_t inLen                           | Length of the float array requested.                                  |
| size_t *outLen                         | Pointer to the actual length of the float array.                |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_ERROR** indicates a common database error.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_SQLITE_CORRUPT** indicates that the database is corrupted.<br>**RDB_E_STEP_RESULT_CLOSED** indicates the result set is closed.<br>**RDB_E_ALREADY_CLOSED** indicates that the database is already closed.<br>**RDB_E_SQLITE_PERM** indicates an SQLite error: access denied.<br>**RDB_E_SQLITE_BUSY** indicates an SQLite error: database file locked.<br>**RDB_E_SQLITE_LOCKED** indicates an SQLite error: database table locked.<br>**RDB_E_SQLITE_NOMEM** indicates an SQLite: insufficient database memory.<br>**RDB_E_SQLITE_IOERR** indicates an SQLite: disk I/O error.<br>**RDB_E_SQLITE_TOO_BIG** indicates an SQLite error: TEXT or BLOB exceeds the limit.<br>**RDB_E_SQLITE_MISMATCH** indicates an SQLite error: data types mismatch.|

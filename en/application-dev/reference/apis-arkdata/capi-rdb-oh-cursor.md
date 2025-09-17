# OH_Cursor
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a struct for a result set. Provides APIs to access the result set obtained by querying the RDB store.

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

**Header file**: [oh_cursor.h](capi-oh-cursor-h.md)

### Member Variables

| Name      | Description                         |
| ---------- | ----------------------------- |
| int64_t id | Unique identifier of the **OH_Cursor** struct.|


### Member Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [int (*getColumnCount)(OH_Cursor *cursor, int *count)](#getcolumncount) | Pointer to the function used to obtain the number of columns in the result set.                              |
| [int (*getColumnType)(OH_Cursor *cursor, int32_t columnIndex, OH_ColumnType *columnType)](#getcolumntype) | Pointer to the function used to obtain the column type based on the specified column index.                      |
| [int (*getColumnIndex)(OH_Cursor *cursor, const char *name, int *columnIndex)](#getcolumnindex) | Pointer to the function used to obtain the column index based on the specified column name.                        |
| [int (*getColumnName)(OH_Cursor *cursor, int32_t columnIndex, char *name, int length)](#getcolumnname) | Pointer to the function used to obtain the column name based on the specified column index.                        |
| [int (*getRowCount)(OH_Cursor *cursor, int *count)](#getrowcount) | Pointer to the function used to obtain the number of rows in the result set.                              |
| [int (*goToNextRow)(OH_Cursor *cursor)](#gotonextrow)        | Pointer to the function used to go to the next row of the result set.                              |
| [int (*getSize)(OH_Cursor *cursor, int32_t columnIndex, size_t *size)](#getsize) | Pointer to the function used to obtain information about the memory required when the column data type in the result set is **BLOB** or **TEXT**.|
| [int (*getText)(OH_Cursor *cursor, int32_t columnIndex, char *value, int length)](#gettext) | Pointer to the function used to obtain the value of the string type based on the specified column and the current row.              |
| [int (*getInt64)(OH_Cursor *cursor, int32_t columnIndex, int64_t *value)](#getint64) | Pointer to the function used to obtain the value of the int64_t type based on the specified column and the current row.             |
| [int (*getReal)(OH_Cursor *cursor, int32_t columnIndex, double *value)](#getreal) | Pointer to the function used to obtain the value of the double type based on the specified column and the current row.              |
| [int (*getBlob)(OH_Cursor *cursor, int32_t columnIndex, unsigned char *value, int length)](#getblob) | Pointer to the function used to obtain the values in the form of a byte array based on the specified column and the current row.          |
| [int (*isNull)(OH_Cursor *cursor, int32_t columnIndex, bool *isNull)](#isnull) | Pointer to the function used to check whether the value in the specified column is null.                |
| [int (*destroy)(OH_Cursor *cursor)](#destroy)                | Pointer to the function used to destroy a result set.                                      |
| [int (*getAsset)(OH_Cursor *cursor, int32_t columnIndex, Data_Asset *value)](#getasset) | Pointer to the function used to obtain the value of the asset type based on the specified column and the current row.              |
| [int (*getAssets)(OH_Cursor *cursor, int32_t columnIndex, Data_Asset **value, uint32_t length)](#getassets) | Pointer to the function used to obtain the values in the form of an asset array based on the specified column and the current row.          |


## Member Function Description

### getColumnCount()

```
int (*getColumnCount)(OH_Cursor *cursor, int *count)
```

**Description**

Pointer to the function used to obtain the number of columns in the result set.

**Since**: 10


**Parameters**

| Name           | Description                                        |
| ----------------- | -------------------------------------------- |
| OH_Cursor *cursor | Pointer to the **OH_Cursor** instance.                 |
| int *count        | Pointer to the number of columns in the result set obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getColumnType()

```
int (*getColumnType)(OH_Cursor *cursor, int32_t columnIndex, OH_ColumnType *columnType)
```

**Description**

Pointer to the function used to obtain the column type based on the specified column index.

**Since**: 10


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Cursor *cursor                                            | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex                                          | Index of the column, which starts from **0**.                   |
| [OH_ColumnType](capi-oh-data-value-h.md#oh_columntype) *columnType | Pointer to [OH_ColumnType](capi-oh-data-value-h.md#oh_columntype) of columns in the result set obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getColumnIndex()

```
int (*getColumnIndex)(OH_Cursor *cursor, const char *name, int *columnIndex)
```

**Description**

Pointer to the function used to obtain the column index based on the specified column name.

**Since**: 10


**Parameters**

| Name           | Description                                                |
| ----------------- | ---------------------------------------------------- |
| OH_Cursor *cursor | Pointer to the **OH_Cursor** instance.                         |
| const char *name  | Column name.                          |
| int *columnIndex  | Pointer to the column index obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getColumnName()

```
 int (*getColumnName)(OH_Cursor *cursor, int32_t columnIndex, char *name, int length)
```

**Description**

Pointer to the function used to obtain the column name based on the specified column index.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex | Index of the column, which starts from **0**.                   |
| char *name          | Pointer to the column name obtained.        |
| int length          | Total length of the column name obtained, including the terminator.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getRowCount()

```
int (*getRowCount)(OH_Cursor *cursor, int *count)
```

**Description**

Pointer to the function used to obtain the number of rows in the result set.

**Since**: 10


**Parameters**

| Name           | Description                                        |
| ----------------- | -------------------------------------------- |
| OH_Cursor *cursor | Pointer to the **OH_Cursor** instance.                 |
| int *count        | Pointer to the number of columns in the result set obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### goToNextRow()

```
 int (*goToNextRow)(OH_Cursor *cursor)
```

**Description**

Pointer to the function used to go to the next row of the result set.

**Since**: 10


**Parameters**

| Name           | Description                       |
| ----------------- | --------------------------- |
| OH_Cursor *cursor | Pointer to the **OH_Cursor** instance.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getSize()

```
int (*getSize)(OH_Cursor *cursor, int32_t columnIndex, size_t *size)
```

**Description**

Pointer to the function used to obtain information about the memory required when the column data type in the result set is **BLOB** or **TEXT**.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                               |
| int32_t columnIndex | Index of the column, which starts from **0**.                   |
| size_t *size        | Pointer to the memory size obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getText()

```
int (*getText)(OH_Cursor *cursor, int32_t columnIndex, char *value, int length)
```

**Description**

Pointer to the function used to obtain the value of the string type based on the specified column and the current row.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex | Index of the column, which starts from **0**.                 |
| char *value         | Pointer to the value of the string type obtained.|
| int length          | Length of **value**, obtained by using **getSize**.  |

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getInt64()

```
int (*getInt64)(OH_Cursor *cursor, int32_t columnIndex, int64_t *value)
```

**Description**

Pointer to the function used to obtain the value of the int64_t type based on the specified column and the current row.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex | Index of the column, which starts from **0**.                   |
| int64_t *value      | Pointer to the value obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getReal()

```
int (*getReal)(OH_Cursor *cursor, int32_t columnIndex, double *value)
```

**Description**

Pointer to the function used to obtain the value of the double type based on the specified column and the current row.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex | Index of the column, which starts from **0**.                   |
| double *value       | Pointer to the value obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getBlob()

```
int (*getBlob)(OH_Cursor *cursor, int32_t columnIndex, unsigned char *value, int length)
```

**Description**

Pointer to the function used to obtain the values in the form of a byte array based on the specified column and the current row.

**Since**: 10


**Parameters**

| Name              | Description                                                        |
| -------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor    | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex  | Index of the column, which starts from **0**.                   |
| unsigned char *value | Pointer to the values in the form of a byte array obtained.|
| int length           | Length of **value**, obtained by using **getSize**.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### isNull()

```
int (*isNull)(OH_Cursor *cursor, int32_t columnIndex, bool *isNull)
```

**Description**

Pointer to the function used to check whether the value in the specified column is null.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex | Index of the column, which starts from **0**.                   |
| bool *isNull        | Pointer to the value returned. The value **true** means the value is null; the value **false** means the opposite.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### destroy()

```
int (*destroy)(OH_Cursor *cursor)
```

**Description**

Pointer to the function used to destroy a result set.

**Since**: 10


**Parameters**

| Name           | Description                       |
| ----------------- | --------------------------- |
| OH_Cursor *cursor | Pointer to the **OH_Cursor** instance.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getAsset()

```
int (*getAsset)(OH_Cursor *cursor, int32_t columnIndex, Data_Asset *value)
```

**Description**

Pointer to the function used to obtain the value of the asset type based on the specified column and the current row.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex | Index of the column, which starts from **0**.                   |
| Data_Asset *value   | Pointer to the value obtained.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### getAssets()

```
int (*getAssets)(OH_Cursor *cursor, int32_t columnIndex, Data_Asset **value, uint32_t length)
```

**Description**

Pointer to the function used to obtain the values in the form of an asset array based on the specified column and the current row.

**Since**: 10


**Parameters**

| Name             | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| OH_Cursor *cursor   | Pointer to the **OH_Cursor** instance.                                 |
| int32_t columnIndex | Index of the column, which starts from **0**.                   |
| Data_Asset **value  | Double pointer to the value obtained.|
| uint32_t length     | Length of the buffer, which is a variable of the uint32_t type passed in. After the API is executed, the variable is updated to the length of the returned asset array.|


**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

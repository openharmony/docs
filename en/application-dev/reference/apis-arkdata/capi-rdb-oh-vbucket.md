# OH_VBucket

## Overview

Defines a struct for the types of the key and value in a KV pair.

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

**Header file**: [oh_values_bucket.h](capi-oh-values-bucket-h.md)

### Member Variables

| Name               | Description                          |
| ------------------- | ------------------------------ |
| int64_t id          | Unique identifier of the **OH_VBucket** struct.|
| uint16_t capability | Number of the KV pairs in the struct.|


### Member Functions

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [int (*putText)(OH_VBucket *bucket, const char *field, const char *value)](#puttext) | Puts a char * value into the **OH_VBucket** object in the given column. |
| [int (*putInt64)(OH_VBucket *bucket, const char *field, int64_t value)](#putint64) | Puts an int64_t value into the **OH_VBucket** object in the given column. |
| [int (*putReal)(OH_VBucket *bucket, const char *field, double value)](#putreal) | Puts a double value into the **OH_VBucket** object in the given column. |
| [int (*putBlob)(OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)](#putblob) | Puts a const uint8_t * value into the **OH_VBucket** object in the given column. |
| [int (*putNull)(OH_VBucket *bucket, const char *field)](#putnull) | Puts a null value into the **OH_VBucket** object in the given column. |
| [int (*clear)(OH_VBucket *bucket)](#clear)                   | Clears an **OH_VBucket** object.                             |
| [int (*destroy)(OH_VBucket *bucket)](#destroy)               | Destroys an **OH_VBucket** object and reclaims the memory occupied. |


### Member Function Description

### putText()

```
int (*putText)(OH_VBucket *bucket, const char *field, const char *value)
```

**Description**

Puts a char value into the **OH_VBucket** object in the given column.

**Since**: 10

**Parameters**

| Name            | Description                          |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | Pointer to the **OH_VBucket** instance.|
| const char *field  | Pointer to the column name in the database table.              |
| const char *value  | Pointer to the value to put.  |

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### putInt64()

```
int (*putInt64)(OH_VBucket *bucket, const char *field, int64_t value)
```

**Description**

Puts an int64_t value into the **OH_VBucket** object in the given column.

**Since**: 10

**Parameters**

| Name            | Description                          |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | Pointer to the **OH_VBucket** instance.|
| const char *field  | Pointer to the column name in the database table.              |
| const char *value  | Pointer to the value to put.  |

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### putReal()

```
int (*putReal)(OH_VBucket *bucket, const char *field, double value)
```

**Description**

Puts a double value into the **OH_VBucket** object in the given column.

**Since**: 10

**Parameters**

| Name            | Description                          |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | Pointer to the **OH_VBucket** instance.|
| const char *field  | Pointer to the column name in the database table.              |
| double value       | Pointer to the value to put.  |

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### putBlob()

```
int (*putBlob)(OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)
```

**Description**

Puts a const uint8_t * value into the **OH_VBucket** object in the given column.

**Since**: 10

**Parameters**

| Name            | Description                          |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | Pointer to the **OH_VBucket** instance.|
| const char *field  | Pointer to the column name in the database table.              |
| const char *value  | Pointer to the value to put.  |
| uint32_t size      | Value length.             |

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### putNull()

```
int (*putNull)(OH_VBucket *bucket, const char *field)
```

**Description**

Puts a null value into the **OH_VBucket** object in the given column.

**Since**: 10

**Parameters**

| Name            | Description                          |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | Pointer to the **OH_VBucket** instance.|
| const char *field  | Pointer to the column name in the database table.              |

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### clear()

```
int (*clear)(OH_VBucket *bucket)
```

**Description**

Puts a char * value into the **OH_VBucket** object in the given column.

**Since**: 10

**Parameters**

| Name            | Description                          |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | Pointer to the **OH_VBucket** instance.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### destroy()

```
int (*destroy)(OH_VBucket *bucket)
```

**Description**

Puts a char value into the **OH_VBucket** object in the given column.

**Since**: 10

**Parameters**

| Name            | Description                          |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | Pointer to the **OH_VBucket** instance.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

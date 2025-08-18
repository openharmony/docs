# oh_values_bucket.h

## Overview

Defines the types of the key and value in a KV pair.

**File to include**: <database/rdb/oh_values_bucket.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                            | typedef Keyword| Description                  |
| -------------------------------- | ------------- | ---------------------- |
| [OH_VBucket](capi-rdb-oh-vbucket.md) | OH_VBucket    | Defines a struct for the types of the key and value in a KV pair.|

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [int OH_VBucket_PutAsset(OH_VBucket *bucket, const char *field, Data_Asset *value)](#oh_vbucket_putasset) | Puts a [Data_Asset](capi-rdb-data-asset.md) object into the [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.|
| [int OH_VBucket_PutAssets(OH_VBucket *bucket, const char *field, Data_Asset **value, uint32_t count)](#oh_vbucket_putassets) | Puts an array of [Data_Asset](capi-rdb-data-asset.md) objects into the [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.|
| [int OH_VBucket_PutFloatVector(OH_VBucket *bucket, const char *field, const float *vec, size_t len)](#oh_vbucket_putfloatvector) | Puts a float array into an [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.|
| [int OH_VBucket_PutUnlimitedInt(OH_VBucket *bucket, const char *field, int sign, const uint64_t *trueForm, size_t len)](#oh_vbucket_putunlimitedint) | Puts an integer of any length into an [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.|

## Function Description

### OH_VBucket_PutAsset()

```
int OH_VBucket_PutAsset(OH_VBucket *bucket, const char *field, Data_Asset *value)
```

**Description**

Puts a [Data_Asset](capi-rdb-data-asset.md) object into the [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.

**Since**: 11


**Parameters**

| Name                                  | Description                                                |
| ---------------------------------------- | ---------------------------------------------------- |
| [OH_VBucket](capi-rdb-oh-vbucket.md) *bucket | Pointer to the [OH_VBucket](capi-rdb-oh-vbucket.md) instance.|
| const char *field                        | Pointer to the column name in the database table.                                  |
| [Data_Asset](capi-rdb-data-asset.md) *value  | Pointer to the value to put.                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.|

### OH_VBucket_PutAssets()

```
int OH_VBucket_PutAssets(OH_VBucket *bucket, const char *field, Data_Asset **value, uint32_t count)
```

**Description**

Puts an array of [Data_Asset](capi-rdb-data-asset.md) objects into the [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.

**Since**: 11


**Parameters**

| Name                                  | Description                                                        |
| ---------------------------------------- | ------------------------------------------------------------ |
| [OH_VBucket](capi-rdb-oh-vbucket.md) *bucket | Pointer to the [OH_VBucket](capi-rdb-oh-vbucket.md) instance.        |
| const char *field                        | Pointer to the column name in the database table.                                          |
| [Data_Asset](capi-rdb-data-asset.md) **value | Double pointer to the value to put.                                |
| uint32_t count                           | Number of elements in the [Data_Asset](capi-rdb-data-asset.md) object to put.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.|

**See**

OH_VBucket

### OH_VBucket_PutFloatVector()

```
int OH_VBucket_PutFloatVector(OH_VBucket *bucket, const char *field, const float *vec, size_t len)
```

**Description**

Puts a float array into an [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.

**Since**: 18


**Parameters**

| Name                                  | Description                                                |
| ---------------------------------------- | ---------------------------------------------------- |
| [OH_VBucket](capi-rdb-oh-vbucket.md) *bucket | Pointer to the [OH_VBucket](capi-rdb-oh-vbucket.md) instance.|
| const char *field                        | Pointer to the column name in the database table.                                  |
| const float *vec                         | Pointer to the float array to put.                           |
| size_t len                               | Length of the float array to put.                               |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.|

**See**

OH_VBucket

### OH_VBucket_PutUnlimitedInt()

```
int OH_VBucket_PutUnlimitedInt(OH_VBucket *bucket, const char *field, int sign, const uint64_t *trueForm, size_t len)
```

**Description**

Puts an integer of any length into an [OH_VBucket](capi-rdb-oh-vbucket.md) object in the given column.

**Since**: 18


**Parameters**

| Name                                  | Description                                                  |
| ---------------------------------------- | ------------------------------------------------------ |
| [OH_VBucket](capi-rdb-oh-vbucket.md) *bucket | Pointer to the [OH_VBucket](capi-rdb-oh-vbucket.md) instance.  |
| const char *field                        | Pointer to the column name in the database table.                                    |
| int sign                                 | Sign notation of the integer object. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.|
| const uint64_t *trueForm                 | Pointer to the integer object to put.                          |
| size_t len                               | Length of the integer object to put.                                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.<br>**RDB_OK** indicates that the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.|

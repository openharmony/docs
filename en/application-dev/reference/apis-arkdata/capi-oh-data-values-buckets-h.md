# oh_data_values_buckets.h

## Overview

Defines structs, APIs, and enums related to stored data values.

**File to include**: <database/rdb/oh_data_values_buckets.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 18

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                                        | typedef Keyword   | Description                          |
| -------------------------------------------- | ---------------- | ------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) | OH_Data_VBuckets | Defines the **OH_Data_VBuckets** struct.|

### Functions

| Name                                                        | Description                                    |
| ------------------------------------------------------------ | ---------------------------------------- |
| [OH_Data_VBuckets *OH_VBuckets_Create(void)](#oh_vbuckets_create) | Creates an **OH_Data_VBuckets** instance.              |
| [int OH_VBuckets_Destroy(OH_Data_VBuckets *buckets)](#oh_vbuckets_destroy) | Destroys an **OH_Data_VBuckets** instance.              |
| [int OH_VBuckets_PutRow(OH_Data_VBuckets *buckets, const OH_VBucket *row)](#oh_vbuckets_putrow) | Adds data of the **OH_VBucket** type to an **OH_Data_VBuckets** instance.                |
| [int OH_VBuckets_PutRows(OH_Data_VBuckets *buckets, const OH_Data_VBuckets *rows)](#oh_vbuckets_putrows) | Adds data of the **OH_Data_VBuckets** type to an **OH_Data_VBuckets** instance.          |
| [int OH_VBuckets_RowCount(OH_Data_VBuckets *buckets, size_t *count)](#oh_vbuckets_rowcount) | Obtains the number of **OH_VBucket**s in an **OH_Data_VBuckets** instance.|

## Function Description

### OH_VBuckets_Create()

```
OH_Data_VBuckets *OH_VBuckets_Create(void)
```

**Description**

Creates an **OH_Data_VBuckets** instance.

**Since**: 18

**Returns**

| Type                                        | Description                                                        |
| -------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) | Returns a pointer to the [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) instance if the operation is successful; returns **nullptr** otherwise.<br>Use [OH_VBuckets_Destroy](capi-oh-data-values-buckets-h.md#oh_vbuckets_destroy) to release the memory in time.|

### OH_VBuckets_Destroy()

```
int OH_VBuckets_Destroy(OH_Data_VBuckets *buckets)
```

**Description**

Destroys an **OH_Data_VBuckets** instance.

**Since**: 18


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets | Pointer to the [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_VBuckets_PutRow()

```
int OH_VBuckets_PutRow(OH_Data_VBuckets *buckets, const OH_VBucket *row)
```

**Description**

Adds data of the **OH_VBucket** type to an **OH_Data_VBuckets** instance.

**Since**: 18


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets | Pointer to the [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) instance.|
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row           | Pointer to the [OH_VBucket](capi-rdb-oh-vbucket.md) instance.        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_VBuckets_PutRows()

```
int OH_VBuckets_PutRows(OH_Data_VBuckets *buckets, const OH_Data_VBuckets *rows)
```

**Description**

Adds data of the **OH_Data_VBuckets** type to an **OH_Data_VBuckets** instance.

**Since**: 18


**Parameters**

| Name                                                  | Description                                                        |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets    | Pointer to the [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) instance.|
| const [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *rows | Pointer to the [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_VBuckets_RowCount()

```
int OH_VBuckets_RowCount(OH_Data_VBuckets *buckets, size_t *count)
```

**Description**

Obtains the number of **OH_VBucket**s in an **OH_Data_VBuckets** instance.

**Since**: 18


**Parameters**

| Name                                               | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets | Pointer to the [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) instance.|
| size_t *count                                         | Pointer to the number of [OH_VBucket](capi-rdb-oh-vbucket.md)s in an [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

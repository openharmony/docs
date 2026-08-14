# oh_rdb_types.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines types related to data values.

**File to include**: <database/rdb/oh_rdb_types.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 18

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) | OH_RDB_ReturningContext | Context of the returning-related APIs.|

### Enums

| Name                                             | typedef Keyword         | Description                    |
| ------------------------------------------------- | ---------------------- | ------------------------ |
| [Rdb_ConflictResolution](#rdb_conflictresolution) | Rdb_ConflictResolution | Enumerates the conflict resolution policies.|

### Functions

| Name| Description|
| -- | -- |
| [OH_RDB_ReturningContext *OH_RDB_CreateReturningContext(void)](#oh_rdb_createreturningcontext) | Creates an [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.|
| [void OH_RDB_DestroyReturningContext(OH_RDB_ReturningContext *context)](#oh_rdb_destroyreturningcontext) | Destroys an [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.|
| [int OH_RDB_SetReturningFields(OH_RDB_ReturningContext *context, const char *const fields[], int32_t len)](#oh_rdb_setreturningfields) | Sets the fields returned in the result set.|
| [int OH_RDB_SetMaxReturningCount(OH_RDB_ReturningContext *context, int32_t count)](#oh_rdb_setmaxreturningcount) | Sets the maximum number of rows for the returned result set.|
| [OH_Cursor *OH_RDB_GetReturningValues(OH_RDB_ReturningContext *context)](#oh_rdb_getreturningvalues) | Obtains the cursor of data changes, which contains 1,024 rows by default.|
| [int64_t OH_RDB_GetChangedCount(OH_RDB_ReturningContext *context)](#oh_rdb_getchangedcount) | Obtains the number of data rows affected by the operation.|

## Enum Description

### Rdb_ConflictResolution

```c
enum Rdb_ConflictResolution
```

**Description**

Enumerates the conflict resolution policies.

**Since**: 18

| Enum Item               | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| RDB_CONFLICT_NONE = 1 | No operation is performed when a conflict occurs.                                  |
| RDB_CONFLICT_ROLLBACK | Throws an error and rolls back the transaction.                      |
| RDB_CONFLICT_ABORT    | Throws an error and rolls back the current change.                      |
| RDB_CONFLICT_FAIL     | Throws an error and aborts the current change without rolling back the modifications before the conflict.    |
| RDB_CONFLICT_IGNORE   | Ignores the conflicted data and resolves the conflict later.                |
| RDB_CONFLICT_REPLACE  | Deletes the data and then inserts the data. If the conflict persists, applies **RDB_CONFLICT_ABORT**.|

## Function Description

### OH_RDB_CreateReturningContext()

```c
OH_RDB_ReturningContext *OH_RDB_CreateReturningContext(void)
```

**Description**

Creates an [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.

**Since**: 23

**Returns**

| Type| Description|
| -- | -- |
| [OH_RDB_ReturningContext *](capi-rdb-oh-rdb-returningcontext.md) | Returns a pointer to the [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance if the operation is successful; returns **nullptr** otherwise. You must release the memory via the [OH_RDB_DestroyReturningContext](capi-oh-rdb-types-h.md#oh_rdb_destroyreturningcontext) API after use.|

### OH_RDB_DestroyReturningContext()

```c
void OH_RDB_DestroyReturningContext(OH_RDB_ReturningContext *context)
```

**Description**

Destroys an [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) *context | Pointer to the [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.|

### OH_RDB_SetReturningFields()

```c
int OH_RDB_SetReturningFields(OH_RDB_ReturningContext *context, const char *const fields[], int32_t len)
```

**Description**

Sets the fields returned in the result set.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) *context | Pointer to the [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.|
| const char *const fields[] | Names of the columns to be returned.|
| int32_t len | Field length.|

**Returns**

| Type| Description|
| -- | -- |
| int | Check result.<br>Returns **RDB_OK** if the operation is successful; returns **RDB_E_INVALID_ARGS** if the input parameters are invalid.|

### OH_RDB_SetMaxReturningCount()

```c
int OH_RDB_SetMaxReturningCount(OH_RDB_ReturningContext *context, int32_t count)
```

**Description**

Sets the maximum number of rows for the returned result set.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) *context | Pointer to the [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.|
| int32_t count | Maximum number of rows for the returned result set.|

**Returns**

| Type| Description|
| -- | -- |
| int | Check result.<br>Returns **RDB_OK** if the operation is successful; returns **RDB_E_INVALID_ARGS** if the input parameters are invalid.|

### OH_RDB_GetReturningValues()

```c
OH_Cursor *OH_RDB_GetReturningValues(OH_RDB_ReturningContext *context)
```

**Description**

Obtains the cursor of data changes, which contains 1,024 rows by default.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) *context | Pointer to the [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_Cursor * | Returns a pointer to the [OH_Cursor](capi-rdb-oh-cursor.md) instance if the operation is successful; returns **nullptr** otherwise.<br>The cursor is destroyed when the [OH_RDB_DestroyReturningContext](capi-oh-rdb-types-h.md#oh_rdb_destroyreturningcontext) API is called to release memory, and no separate release is required for the cursor.|

### OH_RDB_GetChangedCount()

```c
int64_t OH_RDB_GetChangedCount(OH_RDB_ReturningContext *context)
```

**Description**

Obtains the number of data rows affected by the operation.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) *context | Pointer to the [OH_RDB_ReturningContext](capi-rdb-oh-rdb-returningcontext.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int64_t | Returns the number of changed data rows. If the changed rows fail to be obtained, **-1** is returned.|

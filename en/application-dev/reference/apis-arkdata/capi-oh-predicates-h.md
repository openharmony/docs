# oh_predicates.h

## Overview

Defines the predicates for an RDB store.

**File to include**: <database/rdb/oh_predicates.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                                  | typedef Keyword| Description      |
| -------------------------------------- | ------------- | ---------- |
| [OH_Predicates](capi-rdb-oh-predicates.md) | OH_Predicates | Defines a **predicates** object.|

### Enums

| Name                         | typedef Keyword| Description      |
| ----------------------------- | ------------- | ---------- |
| [OH_OrderType](#oh_ordertype) | OH_OrderType  | Enumerates the sorting types.|

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [int OH_Predicates_NotLike(OH_Predicates *predicates, const char *field, const char *pattern)](#oh_predicates_notlike) | Sets an **OH_Predicates** object to match a string that is not similar to the specified value.<br>This API is similar to the SQL **Not like** statement.|
| [int OH_Predicates_Glob(OH_Predicates *predicates, const char *field, const char *pattern)](#oh_predicates_glob) | Sets an **OH_Predicates** object to match a string containing a wildcard.<br>Different from **like**, the input parameters of this API are case-sensitive.|
| [int OH_Predicates_NotGlob(OH_Predicates *predicates, const char *field, const char *pattern)](#oh_predicates_notglob) | Sets an **OH_Predicates** object to not match a string containing a wildcard.<br>Different from **Not Like**, the input parameters of this API are case-sensitive.|
| [int OH_Predicates_Having(OH_Predicates *predicates, const char *conditions, const OH_Data_Values *values)](#oh_predicates_having) | Sets an **OH_Predicates** object to filter grouped results by specified conditions.|

## Enum Description

### OH_OrderType

```
enum OH_OrderType
```

**Description**

Enumerates the sorting types.

**Since**: 10

| Enum Item  | Description      |
| -------- | ---------- |
| ASC = 0  | Ascending order.|
| DESC = 1 | Descending order.|


## Function Description

### OH_Predicates_NotLike()

```
int OH_Predicates_NotLike(OH_Predicates *predicates, const char *field, const char *pattern)
```

**Description**

Sets an **OH_Predicates** object to match a string that is not similar to the specified value.<br>This API is similar to the SQL **Not like** statement.

**Since**: 20


**Parameters**

| Name                                            | Description                                                      |
| -------------------------------------------------- | ---------------------------------------------------------- |
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance.|
| const char *field                                  | Pointer to the column name in the database table.                                    |
| const char *pattern                                | Pointer to the pattern used.                                    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Predicates_Glob()

```
int OH_Predicates_Glob(OH_Predicates *predicates, const char *field, const char *pattern)
```

**Description**

Sets an **OH_Predicates** object to match a string containing a wildcard.<br>Different from **like**, the input parameters of this API are case-sensitive.

**Since**: 20


**Parameters**

| Name                                            | Description                                                      |
| -------------------------------------------------- | ---------------------------------------------------------- |
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance.|
| const char *field                                  | Pointer to the column name in the database table.                                    |
| const char *pattern                                | Pointer to the pattern used.                                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Predicates_NotGlob()

```
int OH_Predicates_NotGlob(OH_Predicates *predicates, const char *field, const char *pattern)
```

**Description**

Sets an **OH_Predicates** object to not match a string containing a wildcard.<br>Different from **Not Like**, the input parameters of this API are case-sensitive.

**Since**: 20


**Parameters**

| Name                                            | Description                                                      |
| -------------------------------------------------- | ---------------------------------------------------------- |
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance.|
| const char *field                                  | Pointer to the column name in the database table.                                    |
| const char *pattern                                | Pointer to the pattern used.                                    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Predicates_Having()

```
int OH_Predicates_Having(OH_Predicates *predicates, const char *conditions, const OH_Data_Values *values)
```

**Description**

Sets an **OH_Predicates** object to filter grouped results by specified conditions.

**Since**: 20


**Parameters**

| Name                                                | Description                                                        |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Predicates](capi-rdb-oh-predicates.md) *predicates     | Pointer to the [OH_Predicates](capi-rdb-oh-predicates.md) instance.  |
| const char *conditions                                 | Pointer to the filter condition specified in the HAVING clause.                                |
| const [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an execution result.<br>**RDB_OK** indicates that the execution is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

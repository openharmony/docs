# oh_data_value.h

## Overview

Defines APIs and enums related to a single data value.<br>Since API version 18, **OH_ColumnType** is moved from **oh_cursor.h** to this file. This type is supported in versions earlier than API version 18 and can be used in all versions.

**File to include**: <database/rdb/oh_data_value.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 18

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                                  | typedef Keyword| Description                                                |
| -------------------------------------- | ------------- | ---------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) | OH_Data_Value | Defines the [OH_Data_Value](capi-rdb-oh-data-value.md) struct.|

### Enums

| Name                           | typedef Keyword| Description          |
| ------------------------------- | ------------- | -------------- |
| [OH_ColumnType](#oh_columntype) | OH_ColumnType | Enumerates the column types.|

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Value *OH_Value_Create(void)](#oh_value_create)     | Creates an [OH_Data_Values](capi-rdb-oh-data-values.md) instance to store a single KV pair.|
| [int OH_Value_Destroy(OH_Data_Value *value)](#oh_value_destroy) | Destroys an [OH_Data_Value](capi-rdb-oh-data-value.md) instance.            |
| [int OH_Value_PutNull(OH_Data_Value *value)](#oh_value_putnull) | Adds empty data to an **OH_Data_Value** instance.                                                |
| [int OH_Value_PutInt(OH_Data_Value *value, int64_t val)](#oh_value_putint) | Adds an integer to an **OH_Data_Value** instance.                                              |
| [int OH_Value_PutReal(OH_Data_Value *value, double val)](#oh_value_putreal) | Adds REAL data to an **OH_Data_Value** instance.                                          |
| [int OH_Value_PutText(OH_Data_Value *value, const char *val)](#oh_value_puttext) | Adds a string to an **OH_Data_Value** instance.                                        |
| [int OH_Value_PutBlob(OH_Data_Value *value, const unsigned char *val, size_t length)](#oh_value_putblob) | Adds BLOB data to an **OH_Data_Value** instance.                                          |
| [int OH_Value_PutAsset(OH_Data_Value *value, const Data_Asset *val)](#oh_value_putasset) | Adds an asset to an **OH_Data_Value** instance.                                         |
| [int OH_Value_PutAssets(OH_Data_Value *value, const Data_Asset * const * val, size_t length)](#oh_value_putassets) | Adds assets to an **OH_Data_Value** instance.                                        |
| [int OH_Value_PutFloatVector(OH_Data_Value *value, const float *val, size_t length)](#oh_value_putfloatvector) | Adds a float array to an **OH_Data_Value** instance.                                     |
| [int OH_Value_PutUnlimitedInt(OH_Data_Value *value, int sign, const uint64_t *trueForm, size_t length)](#oh_value_putunlimitedint) | Adds an integer array of any length to an **OH_Data_Value** instance.                                |
| [int OH_Value_GetType(OH_Data_Value *value, OH_ColumnType *type)](#oh_value_gettype) | Obtains the type of a value in an **OH_Data_Values** instance.                                              |
| [int OH_Value_IsNull(OH_Data_Value *value, bool *val)](#oh_value_isnull) | Checks whether a value is null.                                          |
| [int OH_Value_GetInt(OH_Data_Value *value, int64_t *val)](#oh_value_getint) | Obtains the integer from an **OH_Data_Value** instance.                                              |
| [int OH_Value_GetReal(OH_Data_Value *value, double *val)](#oh_value_getreal) | Obtains the REAL data from an **OH_Data_Value** instance.                                          |
| [int OH_Value_GetText(OH_Data_Value *value, const char **val)](#oh_value_gettext) | Obtains the string from an **OH_Data_Value** instance.                                        |
| [int OH_Value_GetBlob(OH_Data_Value *value, const uint8_t **val, size_t *length)](#oh_value_getblob) | Obtains the BLOB data from an **OH_Data_Value** instance.                                          |
| [int OH_Value_GetAsset(OH_Data_Value *value, Data_Asset *val)](#oh_value_getasset) | Obtains the asset from an **OH_Data_Value** instance.                                         |
| [int OH_Value_GetAssetsCount(OH_Data_Value *value, size_t *length)](#oh_value_getassetscount) | Obtains the length of the assets in an **OH_Data_Value** instance.                                  |
| [int OH_Value_GetAssets(OH_Data_Value *value, Data_Asset **val, size_t inLen, size_t *outLen)](#oh_value_getassets) | Obtains the assets from an **OH_Data_Value** instance.                                        |
| [int OH_Value_GetFloatVectorCount(OH_Data_Value *value, size_t *length)](#oh_value_getfloatvectorcount) | Obtains the length of the float array in an **OH_Data_Values** instance.                               |
| [int OH_Value_GetFloatVector(OH_Data_Value *value, float *val, size_t inLen, size_t *outLen)](#oh_value_getfloatvector) | Obtains the float array from an **OH_Data_Values** instance.                                     |
| [int OH_Value_GetUnlimitedIntBand(OH_Data_Value *value, size_t *length)](#oh_value_getunlimitedintband) | Obtains the length of the unlimited integer from an **OH_Data_Value** instance.                              |
| [int OH_Value_GetUnlimitedInt(OH_Data_Value *value, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen)](#oh_value_getunlimitedint) | Obtains the unlimited integer from an **OH_Data_Value** instance.                                    |

## Enum Description

### OH_ColumnType

```
enum OH_ColumnType
```

**Description**

Enumerates the column types.

**Since**: 10

| Enum Item            | Description                                                     |
| ------------------ | --------------------------------------------------------- |
| TYPE_NULL = 0      | NULL.                                           |
| TYPE_INT64         | INT64.                                      |
| TYPE_REAL          | REAL.                                       |
| TYPE_TEXT          | TEXT.                                       |
| TYPE_BLOB          | BLOB.                                       |
| TYPE_ASSET         | ASSET (asset attachment).<br>**Since**: 11     |
| TYPE_ASSETS        | ASSETS (multiple asset attachments).<br>**Since**: 11|
| TYPE_FLOAT_VECTOR  | FLOAT VECTOR.<br>**Since**: 18          |
| TYPE_UNLIMITED_INT | Number longer than 64 digits.<br>**Since**: 18    |


## Function Description

### OH_Value_Create()

```
OH_Data_Value *OH_Value_Create(void)
```

**Description**

Creates an [OH_Data_Values](capi-rdb-oh-data-values.md) instance to store a single KV pair.

**Since**: 18

**Returns**

| Type                                  | Description                                                        |
| -------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) | Returns a pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance if the operation is successful; returns **nullptr** otherwise.<br>Use [OH_Value_Destroy](capi-oh-data-value-h.md#oh_value_destroy) to release the memory in time.|

### OH_Value_Destroy()

```
int OH_Value_Destroy(OH_Data_Value *value)
```

**Description**

Destroys an [OH_Data_Value](capi-rdb-oh-data-value.md) instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutNull()

```
int OH_Value_PutNull(OH_Data_Value *value)
```

**Description**

Adds empty data to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutInt()

```
int OH_Value_PutInt(OH_Data_Value *value, int64_t val)
```

**Description**

Adds an integer to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| int64_t val                                   | Integer to add.                                            |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutReal()

```
int OH_Value_PutReal(OH_Data_Value *value, double val)
```

**Description**

Adds REAL data to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| double val                                    | REAL data to add.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutText()

```
int OH_Value_PutText(OH_Data_Value *value, const char *val)
```

**Description**

Adds a string to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| const char *val                               | Pointer to the string to add.                                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutBlob()

```
int OH_Value_PutBlob(OH_Data_Value *value, const unsigned char *val, size_t length)
```

**Description**

Adds BLOB data to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| const unsigned char *val                      | Pointer to the BLOB data to add.                                        |
| size_t length                                 | Length of the BLOB data to add.    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutAsset()

```
int OH_Value_PutAsset(OH_Data_Value *value, const Data_Asset *val)
```

**Description**

Adds an asset to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| const [Data_Asset](capi-rdb-data-asset.md) *val   | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutAssets()

```
int OH_Value_PutAssets(OH_Data_Value *value, const Data_Asset * const * val, size_t length)
```

**Description**

Adds assets to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value        | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |
| const [Data_Asset](capi-rdb-data-asset.md) * const * val | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.        |
| size_t length                                        | Number of elements in the [Data_Asset](capi-rdb-data-asset.md) object to add.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutFloatVector()

```
int OH_Value_PutFloatVector(OH_Data_Value *value, const float *val, size_t length)
```

**Description**

Adds a float array to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| const float *val                              | Pointer to the float array to add.                             |
| size_t length                                 | Length of the float array to add.   |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_PutUnlimitedInt()

```
int OH_Value_PutUnlimitedInt(OH_Data_Value *value, int sign, const uint64_t *trueForm, size_t length)
```

**Description**

Adds an integer array of any length to an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| int sign                                      | Sign notation of the integer array to add. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.                    |
| const uint64_t *trueForm                      | Pointer to the integer array to add.                                  |
| size_t length                                 | Length of the integer array to add.    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_GetType()

```
int OH_Value_GetType(OH_Data_Value *value, OH_ColumnType *type)
```

**Description**

Obtains the data type.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| [OH_ColumnType](#oh_columntype) *type         | Pointer to the data type obtained.                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_IsNull()

```
int OH_Value_IsNull(OH_Data_Value *value, bool *val)
```

**Description**

Checks whether a value is null.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| bool *val                                     | Pointer to the check result. The value **true** means the value is null, and the value **false** means the opposite.               |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Value_GetInt()

```
int OH_Value_GetInt(OH_Data_Value *value, int64_t *val)
```

**Description**

Obtains the integer from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| int64_t *val                                  | Pointer to the integer data obtained.                    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetReal()

```
int OH_Value_GetReal(OH_Data_Value *value, double *val)
```

**Description**

Obtains the REAL data from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| double *val                                   | Pointer to the REAL data obtained.                |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetText()

```
int OH_Value_GetText(OH_Data_Value *value, const char **val)
```

**Description**

Obtains the string from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |
| const char **val                              | Double pointer to the string obtained.<br>You do not need to apply for or release memory for it.<br>The lifecycle of **val** complies with the value of **index** in **value**.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetBlob()

```
int OH_Value_GetBlob(OH_Data_Value *value, const uint8_t **val, size_t *length)
```

**Description**

Obtains the BLOB data from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |
| const uint8_t **val                           | Double pointer to the BLOB data obtained.<br>You do not need to apply for or release memory for it.<br>The lifecycle of **val** complies with the value of **index** in **value**.|
| size_t *length                                | Pointer to the length of the BLOB data obtained.                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetAsset()

```
int OH_Value_GetAsset(OH_Data_Value *value, Data_Asset *val)
```

**Description**

Obtains the asset from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |
| [Data_Asset](capi-rdb-data-asset.md) *val         | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the operation fails.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetAssetsCount()

```
int OH_Value_GetAssetsCount(OH_Data_Value *value, size_t *length)
```

**Description**

Obtains the length of the assets in an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| size_t *length                                | Pointer to the length of the ASSETS data obtained.              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetAssets()

```
int OH_Value_GetAssets(OH_Data_Value *value, Data_Asset **val, size_t inLen, size_t *outLen)
```

**Description**

Obtains the assets from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |
| [Data_Asset](capi-rdb-data-asset.md) **val        | Double pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the operation fails.|
| size_t inLen                                  | Size of **val**, which can be obtained using [OH_Values_GetAssetsCount](capi-oh-data-values-h.md#oh_values_getassetscount).|
| size_t *outLen                                | Pointer to the actual length of the data obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetFloatVectorCount()

```
int OH_Value_GetFloatVectorCount(OH_Data_Value *value, size_t *length)
```

**Description**

Obtains the length of the float array in an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| size_t *length                                | Pointer to the length of the float data obtained.           |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetFloatVector()

```
int OH_Value_GetFloatVector(OH_Data_Value *value, float *val, size_t inLen, size_t *outLen)
```

**Description**

Obtains the float array from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |
| float *val                                    | Pointer to the float array obtained.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the operation fails.|
| size_t inLen                                  | Size of **val**, which can be obtained using [OH_Values_GetFloatVectorCount](capi-oh-data-values-h.md#oh_values_getfloatvectorcount).|
| size_t *outLen                                | Pointer to the actual length of the data obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetUnlimitedIntBand()

```
int OH_Value_GetUnlimitedIntBand(OH_Data_Value *value, size_t *length)
```

**Description**

Obtains the length of the unlimited integer from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                      |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.|
| size_t *length                                | Pointer to the length of the integer obtained.                    |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Value_GetUnlimitedInt()

```
int OH_Value_GetUnlimitedInt(OH_Data_Value *value, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen)
```

**Description**

Obtains the unlimited integer from an **OH_Data_Value** instance.

**Since**: 18


**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |
| int *sign                                     | Pointer to the sign notation of the integer obtained. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.        |
| uint64_t *trueForm                            | Pointer to the integer array obtained.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the operation fails.|
| size_t inLen                                  | **trueForm** length, which can be obtained using [OH_Values_GetUnlimitedIntBand](capi-oh-data-values-h.md#oh_values_getunlimitedintband).|
| size_t *outLen                                | Pointer to the actual length of the data obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

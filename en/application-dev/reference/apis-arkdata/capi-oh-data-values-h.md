# oh_data_values.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines APIs and enums related to multiple data values.

**File to include**: <database/rdb/oh_data_values.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 18

**Related module**: [RDB](capi-rdb.md)

## Summary

### Structs

| Name                                    | typedef Keyword | Description                                |
| ---------------------------------------- | -------------- | ------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) | OH_Data_Values | Defines the **OH_Data_Values** struct.|

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values *OH_Values_Create(void)](#oh_values_create)  | Creates an [OH_Data_Values](capi-rdb-oh-data-values.md) instance to store multiple KV pairs.|
| [int OH_Values_Destroy(OH_Data_Values *values)](#oh_values_destroy) | Destroys an [OH_Data_Values](capi-rdb-oh-data-values.md) instance.          |
| [int OH_Values_Put(OH_Data_Values *values, const OH_Data_Value *val)](#oh_values_put) | Adds data of the **OH_Data_Value** type to an **OH_Data_Values** instance.             |
| [int OH_Values_PutNull(OH_Data_Values *values)](#oh_values_putnull) | Adds empty data to an **OH_Data_Values** instance.                            |
| [int OH_Values_PutInt(OH_Data_Values *values, int64_t val)](#oh_values_putint) | Adds an integer to an **OH_Data_Values** instance.                          |
| [int OH_Values_PutReal(OH_Data_Values *values, double val)](#oh_values_putreal) | Adds REAL data to an **OH_Data_Values** instance.                      |
| [int OH_Values_PutText(OH_Data_Values *values, const char *val)](#oh_values_puttext) | Adds a string to an **OH_Data_Values** instance.                    |
| [int OH_Values_PutBlob(OH_Data_Values *values, const unsigned char *val, size_t length)](#oh_values_putblob) | Adds BLOB data to an **OH_Data_Values** instance.                      |
| [int OH_Values_PutAsset(OH_Data_Values *values, const Data_Asset *val)](#oh_values_putasset) | Adds an asset to an **OH_Data_Values** instance.                     |
| [int OH_Values_PutAssets(OH_Data_Values *values, const Data_Asset * const * val, size_t length)](#oh_values_putassets) | Adds assets to an **OH_Data_Values** instance.                    |
| [int OH_Values_PutFloatVector(OH_Data_Values *values, const float *val, size_t length)](#oh_values_putfloatvector) | Adds a float array to an **OH_Data_Values** instance.                 |
| [int OH_Values_PutUnlimitedInt(OH_Data_Values *values, int sign, const uint64_t *trueForm, size_t length)](#oh_values_putunlimitedint) | Adds an integer array of any length to an **OH_Data_Values** instance.            |
| [int OH_Values_Count(OH_Data_Values *values, size_t *count)](#oh_values_count) | Obtains the number of values in an **OH_Data_Values** instance.                                              |
| [int OH_Values_GetType(OH_Data_Values *values, int index, OH_ColumnType *type)](#oh_values_gettype) | Obtains the type of a value in an **OH_Data_Values** instance.                                              |
| [int OH_Values_Get(OH_Data_Values *values, int index, OH_Data_Value **val)](#oh_values_get) | Obtains data of the **OH_Data_Value** type.                                 |
| [int OH_Values_IsNull(OH_Data_Values *values, int index, bool *val)](#oh_values_isnull) | Checks whether a value is null.                                          |
| [int OH_Values_GetInt(OH_Data_Values *values, int index, int64_t *val)](#oh_values_getint) | Obtains the integer from an **OH_Data_Values** instance.                                              |
| [int OH_Values_GetReal(OH_Data_Values *values, int index, double *val)](#oh_values_getreal) | Obtains the REAL data from an **OH_Data_Values** instance.                                          |
| [int OH_Values_GetText(OH_Data_Values *values, int index, const char **val)](#oh_values_gettext) | Obtains the string from an **OH_Data_Values** instance.                                        |
| [int OH_Values_GetBlob(OH_Data_Values *values, int index, const uint8_t **val, size_t *length)](#oh_values_getblob) | Obtains the BLOB data from an **OH_Data_Values** instance.                                          |
| [int OH_Values_GetAsset(OH_Data_Values *values, int index, Data_Asset *val)](#oh_values_getasset) | Obtains the asset from an **OH_Data_Values** instance.                                         |
| [int OH_Values_GetAssetsCount(OH_Data_Values *values, int index, size_t *length)](#oh_values_getassetscount) | Obtains the length of the asset in an **OH_Data_Values** instance.                                  |
| [int OH_Values_GetAssets(OH_Data_Values *values, int index, Data_Asset **val, size_t inLen, size_t *outLen)](#oh_values_getassets) | Obtains the assets from an **OH_Data_Values** instance.                                        |
| [int OH_Values_GetFloatVectorCount(OH_Data_Values *values, int index, size_t *length)](#oh_values_getfloatvectorcount) | Obtains the length of the float array in an **OH_Data_Values** instance.                               |
| [int OH_Values_GetFloatVector(OH_Data_Values *values, int index, float *val, size_t inLen, size_t *outLen)](#oh_values_getfloatvector) | Obtains the float array from an **OH_Data_Values** instance.                                     |
| [int OH_Values_GetUnlimitedIntBand(OH_Data_Values *values, int index, size_t *length)](#oh_values_getunlimitedintband) | Obtains the length of the unlimited integer from an **OH_Data_Values** instance.                              |
| [int OH_Values_GetUnlimitedInt(OH_Data_Values *values, int index, int *sign, uint64_t *trueForm, size_t inLen,size_t *outLen)](#oh_values_getunlimitedint) | Obtains the unlimited integer from an **OH_Data_Values** instance.                                    |

## Function Description

### OH_Values_Create()

```
OH_Data_Values *OH_Values_Create(void)
```

**Description**

Creates an [OH_Data_Values](capi-rdb-oh-data-values.md) instance to store multiple KV pairs.

**Since**: 18

**Returns**

| Type                                    | Description                                                        |
| ---------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) | Returns a pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance created if the operation is successful; returns **nullptr** otherwise.<br>Use [OH_Values_Destroy](capi-oh-data-values-h.md#oh_values_destroy) to release the memory in time.|

### OH_Values_Destroy()

```
int OH_Values_Destroy(OH_Data_Values *values)
```

**Description**

Destroys an [OH_Data_Values](capi-rdb-oh-data-values.md) instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_Put()

```
int OH_Values_Put(OH_Data_Values *values, const OH_Data_Value *val)
```

**Description**

Adds data of the **OH_Data_Value** type to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                           | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values  | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| const [OH_Data_Value](capi-rdb-oh-data-value.md) *val | Pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutNull()

```
int OH_Values_PutNull(OH_Data_Values *values)
```

**Description**

Adds empty data to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutInt()

```
int OH_Values_PutInt(OH_Data_Values *values, int64_t val)
```

**Description**

Adds an integer to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int64_t val                                      | Pointer to the integer to add.                                              |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutReal()

```
int OH_Values_PutReal(OH_Data_Values *values, double val)
```

**Description**

Adds REAL data to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| double val                                       | Pointer to the REAL data to add.                                          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutText()

```
int OH_Values_PutText(OH_Data_Values *values, const char *val)
```

**Description**

Adds a string to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| const char *val                                  | Pointer to the string to add.                                        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutBlob()

```
int OH_Values_PutBlob(OH_Data_Values *values, const unsigned char *val, size_t length)
```

**Description**

Adds BLOB data to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| const unsigned char *val                         | Pointer to the BLOB data to add.                                          |
| size_t length                                    | Length of the BLOB data to add.      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutAsset()

```
int OH_Values_PutAsset(OH_Data_Values *values, const Data_Asset *val)
```

**Description**

Adds an asset to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| const [Data_Asset](capi-rdb-data-asset.md) *val      | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.        |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutAssets()

```
int OH_Values_PutAssets(OH_Data_Values *values, const Data_Asset * const * val, size_t length)
```

**Description**

Adds assets to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                              | Description                                                        |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values     | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| const [Data_Asset](capi-rdb-data-asset.md) * const * val | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.        |
| size_t length                                        | Number of elements in the [Data_Asset](capi-rdb-data-asset.md) object to add.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutFloatVector()

```
int OH_Values_PutFloatVector(OH_Data_Values *values, const float *val, size_t length)
```

**Description**

Adds a float array to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| const float *val                                 | Pointer to the float array to add.                               |
| size_t length                                    | Length of the float array to add.         |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_PutUnlimitedInt()

```
int OH_Values_PutUnlimitedInt(OH_Data_Values *values, int sign, const uint64_t *trueForm, size_t length)
```

**Description**

Adds an integer array of any length to an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int sign                                         | Sign notation of the integer array to add. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.                      |
| const uint64_t *trueForm                         | Pointer to the integer array to add.                                    |
| size_t length                                    | Length of the integer array to add.          |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_Count()

```
int OH_Values_Count(OH_Data_Values *values, size_t *count)
```

**Description**

Obtains the number of records in an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| size_t *count                                    | Pointer to the number of values contained in **values** obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_GetType()

```
int OH_Values_GetType(OH_Data_Values *values, int index, OH_ColumnType *type)
```

**Description**

Obtains the data type.

**Since**: 18


**Parameters**

| Name                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values             | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                                    | Index of the value to check, which starts from 0 in **values**.                      |
| [OH_ColumnType](capi-oh-data-value-h.md#oh_columntype) *type | Pointer to the data type obtained.                                |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_Get()

```
int OH_Values_Get(OH_Data_Values *values, int index, OH_Data_Value **val)
```

**Description**

Obtains data of the **OH_Data_Value** type.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| [OH_Data_Value](capi-rdb-oh-data-value.md) **val     | Double pointer to the [OH_Data_Value](capi-rdb-oh-data-value.md) instance.<br>You do not need to apply for or release memory for it.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_IsNull()

```
int OH_Values_IsNull(OH_Data_Values *values, int index, bool *val)
```

**Description**

Checks whether a value is null.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| bool *val                                        | Pointer to the check result. The value **true** means the value is empty, and the value **false** means the opposite.                 |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates that invalid parameters are specified.|

### OH_Values_GetInt()

```
int OH_Values_GetInt(OH_Data_Values *values, int index, int64_t *val)
```

**Description**

Obtains the integer from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| int64_t *val                                     | Pointer to the integer data obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetReal()

```
int OH_Values_GetReal(OH_Data_Values *values, int index, double *val)
```

**Description**

Obtains the REAL data from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| double *val                                      | Pointer to the REAL data obtained.                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetText()

```
int OH_Values_GetText(OH_Data_Values *values, int index, const char **val)
```

**Description**

Obtains the string from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| const char **val                                 | Pointer to the string obtained.<br>You do not need to apply for or release memory for it.<br>The lifecycle of **val** complies with the value of **index** in **values**.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetBlob()

```
int OH_Values_GetBlob(OH_Data_Values *values, int index, const uint8_t **val, size_t *length)
```

**Description**

Obtains the BLOB data from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| const uint8_t **val                              | Double pointer to the BLOB data obtained.<br>You do not need to apply for or release memory for it.<br>The lifecycle of **val** complies with the value of **index** in **values**.|
| size_t *length                                   | Pointer to the length of the BLOB data obtained.                  |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetAsset()

```
int OH_Values_GetAsset(OH_Data_Values *values, int index, Data_Asset *val)
```

**Description**

Obtains the asset from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| [Data_Asset](capi-rdb-data-asset.md) *val            | Pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the execution fails.|

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetAssetsCount()

```
int OH_Values_GetAssetsCount(OH_Data_Values *values, int index, size_t *length)
```

**Description**

Obtains the length of the asset in an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance. Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| size_t *length                                   | Pointer to the length of the ASSETS data obtained.                |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetAssets()

```
int OH_Values_GetAssets(OH_Data_Values *values, int index, Data_Asset **val, size_t inLen, size_t *outLen)
```

**Description**

Obtains the assets from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| [Data_Asset](capi-rdb-data-asset.md) **val           | Double pointer to the [Data_Asset](capi-rdb-data-asset.md) instance.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the execution fails.|
| size_t inLen                                     | Size of **val**, which can be obtained using [OH_Values_GetAssetsCount](capi-oh-data-values-h.md#oh_values_getassetscount).|
| size_t *outLen                                   | Pointer to the actual length of the data obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetFloatVectorCount()

```
int OH_Values_GetFloatVectorCount(OH_Data_Values *values, int index, size_t *length)
```

**Description**

Obtains the length of the float array in an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| size_t *length                                   | Pointer to the length of the float data obtained.             |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetFloatVector()

```
int OH_Values_GetFloatVector(OH_Data_Values *values, int index, float *val, size_t inLen, size_t *outLen)
```

**Description**

Obtains the float array from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| float *val                                       | Pointer to the float array obtained.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the execution fails.|
| size_t inLen                                     | Size of **val**, which can be obtained using [OH_Values_GetFloatVectorCount](capi-oh-data-values-h.md#oh_values_getfloatvectorcount).|
| size_t *outLen                                   | Pointer to the actual length of the data obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetUnlimitedIntBand()

```
int OH_Values_GetUnlimitedIntBand(OH_Data_Values *values, int index, size_t *length)
```

**Description**

Obtains the length of the unlimited integer from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| size_t *length                                   | Pointer to the length of the integer obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

### OH_Values_GetUnlimitedInt()

```
int OH_Values_GetUnlimitedInt(OH_Data_Values *values, int index, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen)
```

**Description**

Obtains the unlimited integer from an **OH_Data_Values** instance.

**Since**: 18


**Parameters**

| Name                                          | Description                                                        |
| ------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Values](capi-rdb-oh-data-values.md) *values | Pointer to the [OH_Data_Values](capi-rdb-oh-data-values.md) instance.|
| int index                                        | Index of the value to check, which starts from 0 in **values**.                      |
| int *sign                                        | Pointer to the sign notation of the integer obtained. The value **0** indicates a positive integer, and the value **1** indicates a negative integer.        |
| uint64_t *trueForm                               | Pointer to the integer array obtained.<br>You need to apply for memory for it.<br>This function is used to fill in data only. Otherwise, the execution fails.|
| size_t inLen                                     | **trueForm** length, which can be obtained using [OH_Values_GetUnlimitedIntBand](capi-oh-data-values-h.md#oh_values_getunlimitedintband).|
| size_t *outLen                                   | Pointer to the actual length of the data obtained.                      |

**Returns**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| int  | Returns an error code.<br>**RDB_OK** indicates the operation is successful.<br>**RDB_E_INVALID_ARGS** indicates invalid parameters are specified.<br>**RDB_E_DATA_TYPE_NULL** indicates the stored data is empty.<br>**RDB_E_TYPE_MISMATCH** indicates the data types do not match.|

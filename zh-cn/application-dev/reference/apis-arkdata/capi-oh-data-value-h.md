# oh_data_value.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## 概述

提供与单条数据值相关的函数和枚举。<br>从API version 18开始，OH_ColumnType从oh_cursor.h移动至此头文件呈现，对于此类型，API version 18之前即支持使用，各版本均可正常使用。

**引用文件：** <database/rdb/oh_data_value.h>

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 18

**相关模块：** [RDB](capi-rdb.md)

## 汇总

### 结构体

| 名称                                   | typedef关键字 | 描述                                                 |
| -------------------------------------- | ------------- | ---------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) | OH_Data_Value | 定义[OH_Data_Value](capi-rdb-oh-data-value.md)结构类型。 |

### 枚举

| 名称                            | typedef关键字 | 描述           |
| ------------------------------- | ------------- | -------------- |
| [OH_ColumnType](#oh_columntype) | OH_ColumnType | 表示列的类型。 |

### 函数

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Data_Value *OH_Value_Create(void)](#oh_value_create)     | 创建[OH_Data_Value](capi-rdb-oh-data-value.md)实例，用于储存单条键值对数据。 |
| [int OH_Value_Destroy(OH_Data_Value *value)](#oh_value_destroy) | 销毁[OH_Data_Value](capi-rdb-oh-data-value.md)对象。             |
| [int OH_Value_PutNull(OH_Data_Value *value)](#oh_value_putnull) | 添加空数据。                                                 |
| [int OH_Value_PutInt(OH_Data_Value *value, int64_t val)](#oh_value_putint) | 添加整型数据。                                               |
| [int OH_Value_PutReal(OH_Data_Value *value, double val)](#oh_value_putreal) | 添加REAL类型数据。                                           |
| [int OH_Value_PutText(OH_Data_Value *value, const char *val)](#oh_value_puttext) | 添加字符串类型数据。                                         |
| [int OH_Value_PutBlob(OH_Data_Value *value, const unsigned char *val, size_t length)](#oh_value_putblob) | 添加BLOB类型数据。                                           |
| [int OH_Value_PutAsset(OH_Data_Value *value, const Data_Asset *val)](#oh_value_putasset) | 添加ASSET类型数据。                                          |
| [int OH_Value_PutAssets(OH_Data_Value *value, const Data_Asset * const * val, size_t length)](#oh_value_putassets) | 添加ASSETS类型数据。                                         |
| [int OH_Value_PutFloatVector(OH_Data_Value *value, const float *val, size_t length)](#oh_value_putfloatvector) | 添加float数组类型数据。                                      |
| [int OH_Value_PutUnlimitedInt(OH_Data_Value *value, int sign, const uint64_t *trueForm, size_t length)](#oh_value_putunlimitedint) | 添加任意长度的整型数组数据。                                 |
| [int OH_Value_GetType(OH_Data_Value *value, OH_ColumnType *type)](#oh_value_gettype) | 获取数据类型。                                               |
| [int OH_Value_IsNull(OH_Data_Value *value, bool *val)](#oh_value_isnull) | 检查数据是否为空。                                           |
| [int OH_Value_GetInt(OH_Data_Value *value, int64_t *val)](#oh_value_getint) | 获取整型数据。                                               |
| [int OH_Value_GetReal(OH_Data_Value *value, double *val)](#oh_value_getreal) | 获取REAL类型数据。                                           |
| [int OH_Value_GetText(OH_Data_Value *value, const char **val)](#oh_value_gettext) | 获取字符串类型数据。                                         |
| [int OH_Value_GetBlob(OH_Data_Value *value, const uint8_t **val, size_t *length)](#oh_value_getblob) | 获取BLOB类型数据。                                           |
| [int OH_Value_GetAsset(OH_Data_Value *value, Data_Asset *val)](#oh_value_getasset) | 获取ASSET类型数据。                                          |
| [int OH_Value_GetAssetsCount(OH_Data_Value *value, size_t *length)](#oh_value_getassetscount) | 获取ASSETS类型数据的大小。                                   |
| [int OH_Value_GetAssets(OH_Data_Value *value, Data_Asset **val, size_t inLen, size_t *outLen)](#oh_value_getassets) | 获取ASSETS类型数据。                                         |
| [int OH_Value_GetFloatVectorCount(OH_Data_Value *value, size_t *length)](#oh_value_getfloatvectorcount) | 获取float数组类型数据的大小。                                |
| [int OH_Value_GetFloatVector(OH_Data_Value *value, float *val, size_t inLen, size_t *outLen)](#oh_value_getfloatvector) | 获取float数组类型数据。                                      |
| [int OH_Value_GetUnlimitedIntBand(OH_Data_Value *value, size_t *length)](#oh_value_getunlimitedintband) | 获取任意长度的整型数据的大小。                               |
| [int OH_Value_GetUnlimitedInt(OH_Data_Value *value, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen)](#oh_value_getunlimitedint) | 获取任意长度的整型数据。                                     |

## 枚举类型说明

### OH_ColumnType

```
enum OH_ColumnType
```

**描述**

表示列的类型。

**起始版本：** 10

| 枚举项             | 描述                                                      |
| ------------------ | --------------------------------------------------------- |
| TYPE_NULL = 0      | 表示NULL类型。                                            |
| TYPE_INT64         | 表示INT64数据类型。                                       |
| TYPE_REAL          | 表示REAL数据类型。                                        |
| TYPE_TEXT          | 表示TEXT数据类型。                                        |
| TYPE_BLOB          | 表示BLOB数据类型。                                        |
| TYPE_ASSET         | 表示ASSET（资产附件）数据类型。<br>**起始版本：** 11      |
| TYPE_ASSETS        | 表示ASSETS（多个资产附件）数据类型。<br>**起始版本：** 11 |
| TYPE_FLOAT_VECTOR  | 表示FLOAT VECTOR数据类型。<br>**起始版本：** 18           |
| TYPE_UNLIMITED_INT | 表示列类型为长度大于64位的数字。<br>**起始版本：** 18     |


## 函数说明

### OH_Value_Create()

```
OH_Data_Value *OH_Value_Create(void)
```

**描述**

创建[OH_Data_Value](capi-rdb-oh-data-value.md)实例，用于储存单条键值对数据。

**起始版本：** 18

**返回：**

| 类型                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) | 执行成功时返回指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。否则返回nullptr。<br>使用完成后，必须通过[OH_Value_Destroy](capi-oh-data-value-h.md#oh_value_destroy)接口释放内存。 |

### OH_Value_Destroy()

```
int OH_Value_Destroy(OH_Data_Value *value)
```

**描述**

销毁[OH_Data_Value](capi-rdb-oh-data-value.md)对象。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutNull()

```
int OH_Value_PutNull(OH_Data_Value *value)
```

**描述**

添加空数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutInt()

```
int OH_Value_PutInt(OH_Data_Value *value, int64_t val)
```

**描述**

添加整型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| int64_t val                                   | 表示整型数据。                                             |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutReal()

```
int OH_Value_PutReal(OH_Data_Value *value, double val)
```

**描述**

添加REAL类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| double val                                    | 表示REAL类型数据。                                         |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutText()

```
int OH_Value_PutText(OH_Data_Value *value, const char *val)
```

**描述**

添加字符串类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| const char *val                               | 表示字符串类型数据。                                       |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutBlob()

```
int OH_Value_PutBlob(OH_Data_Value *value, const unsigned char *val, size_t length)
```

**描述**

添加BLOB类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| const unsigned char *val                      | 表示BLOB类型数据。                                         |
| size_t length                                 | 该参数是输入参数，表示开发者传入的BLOB类型数据的大小。     |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutAsset()

```
int OH_Value_PutAsset(OH_Data_Value *value, const Data_Asset *val)
```

**描述**

添加ASSET类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| const [Data_Asset](capi-rdb-data-asset.md) *val   | 表示指向[Data_Asset](capi-rdb-data-asset.md)对象的指针。       |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutAssets()

```
int OH_Value_PutAssets(OH_Data_Value *value, const Data_Asset * const * val, size_t length)
```

**描述**

添加ASSETS类型数据。

**起始版本：** 18


**参数：**

| 参数项                                               | 描述                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value        | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。   |
| const [Data_Asset](capi-rdb-data-asset.md) * const * val | 表示指向[Data_Asset](capi-rdb-data-asset.md)对象的指针。         |
| size_t length                                        | 该参数是输入参数，表示开发者传入的[Data_Asset](capi-rdb-data-asset.md)对象数组元素的个数。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutFloatVector()

```
int OH_Value_PutFloatVector(OH_Data_Value *value, const float *val, size_t length)
```

**描述**

添加float数组类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| const float *val                              | 表示指向float数组对象的指针。                              |
| size_t length                                 | 该参数是输入参数，表示开发者传入的表示float数组的大小。    |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_PutUnlimitedInt()

```
int OH_Value_PutUnlimitedInt(OH_Data_Value *value, int sign, const uint64_t *trueForm, size_t length)
```

**描述**

添加任意长度的整型数组数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| int sign                                      | 表示正负数，0表示正整数，1表示负整数。                     |
| const uint64_t *trueForm                      | 表示指向整型数组的指针。                                   |
| size_t length                                 | 该参数是输入参数，表示开发者传入的表示整型数组的大小。     |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_GetType()

```
int OH_Value_GetType(OH_Data_Value *value, OH_ColumnType *type)
```

**描述**

获取数据类型。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| [OH_ColumnType](#oh_columntype) *type         | 一个输出参数，表示数据类型。                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_IsNull()

```
int OH_Value_IsNull(OH_Data_Value *value, bool *val)
```

**描述**

检查数据是否为空。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| bool *val                                     | 一个输出参数，ture表示空，false表示不为空。                |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_Value_GetInt()

```
int OH_Value_GetInt(OH_Data_Value *value, int64_t *val)
```

**描述**

获取整型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| int64_t *val                                  | 一个输出参数，表示指向整型数据的指针。                     |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetReal()

```
int OH_Value_GetReal(OH_Data_Value *value, double *val)
```

**描述**

获取REAL类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| double *val                                   | 一个输出参数，表示指向REAL类型数据的指针。                 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetText()

```
int OH_Value_GetText(OH_Data_Value *value, const char **val)
```

**描述**

获取字符串类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。   |
| const char **val                              | 一个输出参数，表示指向字符串类型数据的指针。<br>无需申请内存和释放内存。<br>val的生命周期遵循value中index的值。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetBlob()

```
int OH_Value_GetBlob(OH_Data_Value *value, const uint8_t **val, size_t *length)
```

**描述**

获取BLOB类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。   |
| const uint8_t **val                           | 一个输出参数，表示指向BLOB类型数据的指针。<br>无需申请内存和释放内存。<br>val的生命周期遵循value中index的值。 |
| size_t *length                                | 该参数是输出参数，表示BLOB类型数组的大小。                   |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetAsset()

```
int OH_Value_GetAsset(OH_Data_Value *value, Data_Asset *val)
```

**描述**

获取ASSET类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。   |
| [Data_Asset](capi-rdb-data-asset.md) *val         | 表示指向[Data_Asset](capi-rdb-data-asset.md)对象的指针。<br>需要申请数据内存。<br>此函数仅填充数据。否则执行失败。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetAssetsCount()

```
int OH_Value_GetAssetsCount(OH_Data_Value *value, size_t *length)
```

**描述**

获取ASSETS类型数据的大小。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| size_t *length                                | 该参数是输出参数，表示ASSETS类型数据的大小。               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetAssets()

```
int OH_Value_GetAssets(OH_Data_Value *value, Data_Asset **val, size_t inLen, size_t *outLen)
```

**描述**

获取ASSETS类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。   |
| [Data_Asset](capi-rdb-data-asset.md) **val        | 表示指向[Data_Asset](capi-rdb-data-asset.md)对象的指针。<br>需要申请数据内存。<br>此函数仅填充数据。否则执行失败。 |
| size_t inLen                                  | 表示val的大小。可以通过[OH_Values_GetAssetsCount](capi-oh-data-values-h.md#oh_values_getassetscount)获取。 |
| size_t *outLen                                | 一个输出参数，表示实际获取的数据大小。                       |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetFloatVectorCount()

```
int OH_Value_GetFloatVectorCount(OH_Data_Value *value, size_t *length)
```

**描述**

获取float数组类型数据的大小。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| size_t *length                                | 该参数是输出参数，表示float数组类型数据的大小。            |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS返回。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetFloatVector()

```
int OH_Value_GetFloatVector(OH_Data_Value *value, float *val, size_t inLen, size_t *outLen)
```

**描述**

获取float数组类型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。   |
| float *val                                    | 表示指向float数组的指针。<br>需要申请数据内存。<br>此函数仅填充数据。否则执行失败。 |
| size_t inLen                                  | 表示val的大小。可以通过[OH_Values_GetFloatVectorCount](capi-oh-data-values-h.md#oh_values_getfloatvectorcount)获取。 |
| size_t *outLen                                | 一个输出参数，表示实际获取的数据大小。                       |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetUnlimitedIntBand()

```
int OH_Value_GetUnlimitedIntBand(OH_Data_Value *value, size_t *length)
```

**描述**

获取任意长度的整型数据的大小。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                       |
| --------------------------------------------- | ---------------------------------------------------------- |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。 |
| size_t *length                                | 该参数是输出参数，表示整型数组的大小。                     |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |

### OH_Value_GetUnlimitedInt()

```
int OH_Value_GetUnlimitedInt(OH_Data_Value *value, int *sign, uint64_t *trueForm, size_t inLen, size_t *outLen)
```

**描述**

获取任意长度的整型数据。

**起始版本：** 18


**参数：**

| 参数项                                        | 描述                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_Value](capi-rdb-oh-data-value.md) *value | 表示指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。   |
| int *sign                                     | 一个输出参数，表示正负数，0表示正整数，1表示负整数。         |
| uint64_t *trueForm                            | 表示指向整型数组的指针。<br>需要申请数据内存。<br>此函数仅填充数据。否则执行失败。 |
| size_t inLen                                  | 表示trueForm的大小。可以通过[OH_Values_GetUnlimitedIntBand](capi-oh-data-values-h.md#oh_values_getunlimitedintband)获取。 |
| size_t *outLen                                | 一个输出参数，表示实际获取的数据大小。                       |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_DATA_TYPE_NULL表示存储数据为空。<br>返回RDB_E_TYPE_MISMATCH表示数据类型不匹配。 |




# oh_data_values_buckets.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## 概述

提供与存储数据值相关的结构定义、函数和枚举。

**引用文件：** <database/rdb/oh_data_values_buckets.h>

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 18

**相关模块：** [RDB](capi-rdb.md)

## 汇总

### 结构体

| 名称                                         | typedef关键字    | 描述                           |
| -------------------------------------------- | ---------------- | ------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) | OH_Data_VBuckets | 定义OH_Data_VBuckets结构类型。 |

### 函数

| 名称                                                         | 描述                                     |
| ------------------------------------------------------------ | ---------------------------------------- |
| [OH_Data_VBuckets *OH_VBuckets_Create(void)](#oh_vbuckets_create) | 创建OH_Data_VBuckets实例。               |
| [int OH_VBuckets_Destroy(OH_Data_VBuckets *buckets)](#oh_vbuckets_destroy) | 销毁OH_Data_VBuckets对象。               |
| [int OH_VBuckets_PutRow(OH_Data_VBuckets *buckets, const OH_VBucket *row)](#oh_vbuckets_putrow) | 添加OH_VBucket类型数据。                 |
| [int OH_VBuckets_PutRows(OH_Data_VBuckets *buckets, const OH_Data_VBuckets *rows)](#oh_vbuckets_putrows) | 添加OH_Data_VBuckets类型数据。           |
| [int OH_VBuckets_RowCount(OH_Data_VBuckets *buckets, size_t *count)](#oh_vbuckets_rowcount) | 获取OH_Data_VBuckets中OH_VBucket的行数。 |

## 函数说明

### OH_VBuckets_Create()

```
OH_Data_VBuckets *OH_VBuckets_Create(void)
```

**描述**

创建OH_Data_VBuckets实例。

**起始版本：** 18

**返回：**

| 类型                                         | 说明                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) | 执行成功时返回指向[OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md)实例的指针。否则返回nullptr。<br>使用完成后，必须通过[OH_VBuckets_Destroy](capi-oh-data-values-buckets-h.md#oh_vbuckets_destroy)接口释放内存。 |

### OH_VBuckets_Destroy()

```
int OH_VBuckets_Destroy(OH_Data_VBuckets *buckets)
```

**描述**

销毁OH_Data_VBuckets对象。

**起始版本：** 18


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets | 表示指向[OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_VBuckets_PutRow()

```
int OH_VBuckets_PutRow(OH_Data_VBuckets *buckets, const OH_VBucket *row)
```

**描述**

添加OH_VBucket类型数据。

**起始版本：** 18


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets | 表示指向[OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md)实例的指针。 |
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row           | 表示指向[OH_VBucket](capi-rdb-oh-vbucket.md)实例的指针。         |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_VBuckets_PutRows()

```
int OH_VBuckets_PutRows(OH_Data_VBuckets *buckets, const OH_Data_VBuckets *rows)
```

**描述**

添加OH_Data_VBuckets类型数据。

**起始版本：** 18


**参数：**

| 参数项                                                   | 描述                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets    | 表示指向[OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md)实例的指针。 |
| const [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *rows | 表示指向[OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_VBuckets_RowCount()

```
int OH_VBuckets_RowCount(OH_Data_VBuckets *buckets, size_t *count)
```

**描述**

获取OH_Data_VBuckets中OH_VBucket的行数。

**起始版本：** 18


**参数：**

| 参数项                                                | 描述                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *buckets | 表示指向[OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md)实例的指针。 |
| size_t *count                                         | 一个输出参数，表示[OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md)中[OH_VBucket](capi-rdb-oh-vbucket.md)的个数。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |


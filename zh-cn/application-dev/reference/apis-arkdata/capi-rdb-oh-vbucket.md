# OH_VBucket
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @htt1997-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

```c
typedef struct {...} OH_VBucket
```

## 概述

用于存储键值对的类型。

**起始版本：** 10

**相关模块：** [RDB](capi-rdb.md)

**所在头文件：** [oh_values_bucket.h](capi-oh-values-bucket-h.md)

### 成员变量

| 名称                | 描述                           |
| ------------------- | ------------------------------ |
| int64_t id          | OH_VBucket结构体的唯一标识符。 |
| uint16_t capability | 表示结构体的存储键值对的容量。 |


### 成员函数

| 名称                                                         | 描述                                                |
| ------------------------------------------------------------ | --------------------------------------------------- |
| [int (*putText)(OH_VBucket *bucket, const char *field, const char *value)](#puttext) | 将char*值放入给定列名的OH_VBucket对象中。           |
| [int (*putInt64)(OH_VBucket *bucket, const char *field, int64_t value)](#putint64) | 将int64_t值放入给定列名的OH_VBucket对象中。         |
| [int (*putReal)(OH_VBucket *bucket, const char *field, double value)](#putreal) | 将double值放入给定列名的OH_VBucket对象中。          |
| [int (*putBlob)(OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)](#putblob) | 将const uint8_t *值放入给定列名的OH_VBucket对象中。 |
| [int (*putNull)(OH_VBucket *bucket, const char *field)](#putnull) | 将NULL值放入给定列名的OH_VBucket对象中。            |
| [int (*clear)(OH_VBucket *bucket)](#clear)                   | 清空OH_VBucket对象。                                |
| [int (*destroy)(OH_VBucket *bucket)](#destroy)               | 销毁OH_VBucket对象，并回收该对象占用的内存。        |


## 成员函数说明

### putText()

```c
int (*putText)(OH_VBucket *bucket, const char *field, const char *value)
```

**描述**

将char*值放入给定列名的OH_VBucket对象中。

**起始版本：** 10

**参数：**

| 参数项             | 描述                           |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | 表示指向OH_VBucket实例的指针。 |
| const char *field  | 数据库表中的列名，不能为空指针。               |
| const char *value  | 数据库表中指定列名对应的值。   |

**返回：**

| 类型 | 说明                                       |
| ---- | ------------------------------------------ |
| int  | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK 表示成功。<br>RDB_E_INVALID_ARGS 表示无效参数。详细信息请参阅[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |

### putInt64()

```c
int (*putInt64)(OH_VBucket *bucket, const char *field, int64_t value)
```

**描述**

将int64_t值放入给定列名的OH_VBucket对象中。

**起始版本：** 10

**参数：**

| 参数项             | 描述                           |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | 表示指向OH_VBucket实例的指针。 |
| const char *field  | 数据库表中的列名，不能为空指针。               |
| int64_t value      | 数据库表中指定列名对应的值。   |

**返回：**

| 类型 | 说明                                       |
| ---- | ------------------------------------------ |
| int  | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK 表示成功。<br>RDB_E_INVALID_ARGS 表示无效参数。详细信息请参阅[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |

### putReal()

```c
int (*putReal)(OH_VBucket *bucket, const char *field, double value)
```

**描述**

将double值放入给定列名的OH_VBucket对象中。

**起始版本：** 10

**参数：**

| 参数项             | 描述                           |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | 表示指向OH_VBucket实例的指针。 |
| const char *field  | 数据库表中的列名，不能为空指针。               |
| double value       | 数据库表中指定列名对应的值。   |

**返回：**

| 类型 | 说明                                       |
| ---- | ------------------------------------------ |
| int  | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK 表示成功。<br>RDB_E_INVALID_ARGS 表示无效参数。详细信息请参阅[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |

### putBlob()

```c
int (*putBlob)(OH_VBucket *bucket, const char *field, const uint8_t *value, uint32_t size)
```

**描述**

将const uint8_t *值放入给定列名的OH_VBucket对象中。

**起始版本：** 10

**参数：**

| 参数项             | 描述                           |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | 表示指向OH_VBucket实例的指针。 |
| const char *field  | 数据库表中的列名，不能为空指针。               |
| const uint8_t *value | 数据库表中指定列名对应的值。 |
| uint32_t size      | 表示value的长度。              |

**返回：**

| 类型 | 说明                                       |
| ---- | ------------------------------------------ |
| int  | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK 表示成功。<br>RDB_E_INVALID_ARGS 表示无效参数。详细信息请参阅[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |

### putNull()

```c
int (*putNull)(OH_VBucket *bucket, const char *field)
```

**描述**

将NULL值放入给定列名的OH_VBucket对象中。

**起始版本：** 10

**参数：**

| 参数项             | 描述                           |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | 表示指向OH_VBucket实例的指针。 |
| const char *field  | 数据库表中的列名，不能为空指针。               |

**返回：**

| 类型 | 说明                                       |
| ---- | ------------------------------------------ |
| int  | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK 表示成功。<br>RDB_E_INVALID_ARGS 表示无效参数。详细信息请参阅[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |

### clear()

```c
int (*clear)(OH_VBucket *bucket)
```

**描述**

清空[OH_VBucket](capi-rdb-oh-vbucket.md)对象。

**起始版本：** 10

**参数：**

| 参数项             | 描述                           |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | 表示指向OH_VBucket实例的指针。 |

**返回：**

| 类型 | 说明                                       |
| ---- | ------------------------------------------ |
| int  | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK 表示成功。<br>RDB_E_INVALID_ARGS 表示无效参数。详细信息请参阅[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |

### destroy()

```c
int (*destroy)(OH_VBucket *bucket)
```

**描述**

销毁[OH_VBucket](capi-rdb-oh-vbucket.md)对象，并回收该对象占用的内存。

**起始版本：** 10

**参数：**

| 参数项             | 描述                           |
| ------------------ | ------------------------------ |
| OH_VBucket *bucket | 表示指向OH_VBucket实例的指针。 |

**返回：**

| 类型 | 说明                                       |
| ---- | ------------------------------------------ |
| int  | 返回操作是否成功，出错时返回对应的错误码。<br>RDB_OK 表示成功。<br>RDB_E_INVALID_ARGS 表示无效参数。详细信息请参阅[OH_Rdb_ErrCode](capi-relational-store-error-code-h.md#oh_rdb_errcode)。 |


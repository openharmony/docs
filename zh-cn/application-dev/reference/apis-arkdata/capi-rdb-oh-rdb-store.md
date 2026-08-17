# OH_Rdb_Store
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @htt1997-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

```c
typedef struct {...} OH_Rdb_Store
```

## 概述

表示数据库实例。需通过[OH_Rdb_GetOrOpen](capi-relational-store-h.md#oh_rdb_getoropen)或[OH_Rdb_CreateOrOpen](capi-relational-store-h.md#oh_rdb_createoropen)等函数获得。

**起始版本：** 10

**相关模块：** [RDB](capi-rdb.md)

**所在头文件：** [relational_store.h](capi-relational-store-h.md)

## 汇总

### 成员变量

| 名称       | 描述                             |
| ---------- | -------------------------------- |
| int64_t id | OH_Rdb_Store结构体的唯一标识符。 |


# Rdb_KeyInfo
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--SE: @widecode; @htt1997-->
<!--TSE: @yippo; @logic42-->

## 概述

描述发生变化的行的主键或者行号。

**起始版本：** 11

**相关模块：** [RDB](capi-rdb.md)

**所在头文件：** [relational_store.h](capi-relational-store-h.md)

## 汇总

### 成员变量

| 名称                                     | 描述                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| int count                                | 表示发生变化的主键或者行号的数量。                           |
| int type                                 | 表示主键的类型[OH_ColumnType](capi-oh-data-value-h.md#oh_columntype)。 |
| [Rdb_KeyData](capi-rdb-rdb-keydata.md)* data | 存放变化的具体数据                                           |


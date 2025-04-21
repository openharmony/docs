# Rdb_KeyInfo


## 概述

描述发生变化的行的主键或者行号。

**起始版本：** 11

**相关模块：**[RDB](_r_d_b.md)

**所在头文件：**[relational_store.h](relational__store_8h.md)

## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) | 存放变化的具体数据。 |


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [count](_r_d_b.md#count) | 表示发生变化的主键或者行号的数量。 |
| [type](_r_d_b.md#type) | 表示主键的类型[OH_ColumnType](_r_d_b.md#oh_columntype)。 |
| **data** | 存放变化的具体数据[Rdb_KeyInfo::Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md)。 |

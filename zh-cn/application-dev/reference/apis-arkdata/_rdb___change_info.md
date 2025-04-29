# Rdb_ChangeInfo


## 概述

记录端云同步过程详情。

**起始版本：** 11

**相关模块：**[RDB](_r_d_b.md)

**所在头文件：**[relational_store.h](relational__store_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [version](_r_d_b.md#version-23) | 用于唯一标识Rdb_DistributedConfig结构的版本。 |
| [tableName](_r_d_b.md#tablename) | 表示发生变化的表的名称。 |
| [ChangeType](_r_d_b.md#changetype) | 表示发生变化的数据的类型，数据或者资产附件发生变化。 |
| [inserted](_r_d_b.md#inserted) | 记录插入数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示插入数据的行号。 |
| [updated](_r_d_b.md#updated) | 记录更新数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示更新数据的行号。 |
| [deleted](_r_d_b.md#deleted) | 记录删除数据的位置，如果该表的主键是string类型，该值是主键的值，否则该值表示删除数据的行号。 |

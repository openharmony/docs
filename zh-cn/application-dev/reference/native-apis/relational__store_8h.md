# relational_store.h


## 概述

提供管理关系数据库（RDB）方法的接口。

**引用文件：** <database/rdb/relational_store.h>

**库：** libnative_rdb_ndk.z.so
**起始版本：**

10

**相关模块：**

[RDB](_r_d_b.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_Config](_o_h___rdb___config.md) | 管理关系数据库配置。 |
| [OH_Rdb_Store](_o_h___rdb___store.md) | 表示数据库类型。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel) | 数据库的安全级别枚举。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel-1) { S1 = 1, S2, S3, S4 } | 数据库的安全级别枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_CreateValueObject](_r_d_b.md#oh_rdb_createvalueobject) (void) | 创建[OH_VObject](_o_h___v_object.md)实例。 |
| [OH_Rdb_CreateValuesBucket](_r_d_b.md#oh_rdb_createvaluesbucket) (void) | 创建[OH_VBucket](_o_h___v_bucket.md)实例。 |
| [OH_Rdb_CreatePredicates](_r_d_b.md#oh_rdb_createpredicates) (const char \*table) | 创建[OH_Predicates](_o_h___predicates.md)实例。 |
| [OH_Rdb_GetOrOpen](_r_d_b.md#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | 获得一个相关的[OH_Rdb_Store](_o_h___rdb___store.md)实例，操作关系型数据库。 |
| [OH_Rdb_CloseStore](_r_d_b.md#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 销毁[OH_Rdb_Store](_o_h___rdb___store.md)对象，并回收该对象占用的内存。 |
| [OH_Rdb_DeleteStore](_r_d_b.md#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | 使用指定的数据库文件配置删除数据库。 |
| [OH_Rdb_Insert](_r_d_b.md#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | 向目标表中插入一行数据。 |
| [OH_Rdb_Update](_r_d_b.md#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件更新数据库中的数据。 |
| [OH_Rdb_Delete](_r_d_b.md#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | 根据指定的条件删除数据库中的数据。 |
| [OH_Rdb_Query](_r_d_b.md#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | 根据指定条件查询数据库中的数据 |
| [OH_Rdb_Execute](_r_d_b.md#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | 执行无返回值的SQL语句。 |
| [OH_Rdb_ExecuteQuery](_r_d_b.md#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | 根据指定SQL语句查询数据库中的数据。 |
| [OH_Rdb_BeginTransaction](_r_d_b.md#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 在开始执行SQL语句之前，开始事务。 |
| [OH_Rdb_RollBack](_r_d_b.md#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 回滚已经执行的SQL语句。 |
| [OH_Rdb_Commit](_r_d_b.md#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | 提交已执行的SQL语句 |
| [OH_Rdb_Backup](_r_d_b.md#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | 以指定路径备份数据库。 |
| [OH_Rdb_Restore](_r_d_b.md#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | 从指定的数据库备份文件恢复数据库。 |
| [OH_Rdb_GetVersion](_r_d_b.md#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | 获取数据库版本。 |
| [OH_Rdb_SetVersion](_r_d_b.md#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | 设置数据库版本。 |

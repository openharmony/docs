# relation_store.h


## 概述

提供管理关系数据库（RDB）方法的接口。

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


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel)&nbsp;{&nbsp;S1&nbsp;=&nbsp;1,&nbsp;S2,&nbsp;S3,&nbsp;S4&nbsp;} | 数据库的安全级别枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Rdb_CreateValueObject](_r_d_b.md#oh_rdb_createvalueobject)&nbsp;() | 创建[OH_VObject](_o_h___v_object.md)实例。 |
| [OH_Rdb_CreateValuesBucket](_r_d_b.md#oh_rdb_createvaluesbucket)&nbsp;() | 创建[OH_VBucket](_o_h___v_bucket.md)实例。 |
| [OH_Rdb_CreatePredicates](_r_d_b.md#oh_rdb_createpredicates)&nbsp;(const&nbsp;char&nbsp;\*table) | 创建[OH_Predicates](_o_h___predicates.md)实例。 |
| [OH_Rdb_GetOrOpen](_r_d_b.md#oh_rdb_getoropen)&nbsp;(const&nbsp;[OH_Rdb_Config](_o_h___rdb___config.md)&nbsp;\*config,&nbsp;int&nbsp;\*errCode) | 获得一个相关的[OH_Rdb_Store](_o_h___rdb___store.md)实例，操作关系型数据库。 |
| [OH_Rdb_CloseStore](_r_d_b.md#oh_rdb_closestore)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 销毁[OH_Rdb_Store](_o_h___rdb___store.md)对象，并回收该对象占用的内存。 |
| [OH_Rdb_DeleteStore](_r_d_b.md#oh_rdb_deletestore)&nbsp;(const&nbsp;char&nbsp;\*path) | 使用指定的数据库文件配置删除数据库。 |
| [OH_Rdb_Insert](_r_d_b.md#oh_rdb_insert)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*table,&nbsp;[OH_VBucket](_o_h___v_bucket.md)&nbsp;\*valuesBucket) | 向目标表中插入一行数据。 |
| [OH_Rdb_Update](_r_d_b.md#oh_rdb_update)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;[OH_VBucket](_o_h___v_bucket.md)&nbsp;\*valuesBucket,&nbsp;[OH_Predicates](_o_h___predicates.md)&nbsp;\*predicates) | 根据指定的条件更新数据库中的数据。 |
| [OH_Rdb_Delete](_r_d_b.md#oh_rdb_delete)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;[OH_Predicates](_o_h___predicates.md)&nbsp;\*predicates) | 根据指定的条件删除数据库中的数据。 |
| [OH_Rdb_Query](_r_d_b.md#oh_rdb_query)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;[OH_Predicates](_o_h___predicates.md)&nbsp;\*predicates,&nbsp;const&nbsp;char&nbsp;\*const&nbsp;\*columnNames,&nbsp;int&nbsp;length) | 根据指定条件查询数据库中的数据 |
| [OH_Rdb_Execute](_r_d_b.md#oh_rdb_execute)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*sql) | 执行无返回值的SQL语句。 |
| [OH_Rdb_ExecuteQuery](_r_d_b.md#oh_rdb_executequery)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*sql) | 根据指定SQL语句查询数据库中的数据。 |
| [OH_Rdb_BeginTransaction](_r_d_b.md#oh_rdb_begintransaction)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 在开始执行SQL语句之前，开始事务。 |
| [OH_Rdb_RollBack](_r_d_b.md#oh_rdb_rollback)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 回滚已经执行的SQL语句。 |
| [OH_Rdb_Commit](_r_d_b.md#oh_rdb_commit)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store) | 提交已执行的SQL语句 |
| [OH_Rdb_Backup](_r_d_b.md#oh_rdb_backup)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*databasePath) | 以指定路径备份数据库。 |
| [OH_Rdb_Restore](_r_d_b.md#oh_rdb_restore)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;const&nbsp;char&nbsp;\*databasePath) | 从指定的数据库备份文件恢复数据库。 |
| [OH_Rdb_GetVersion](_r_d_b.md#oh_rdb_getversion)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;int&nbsp;\*version) | 获取数据库版本。 |
| [OH_Rdb_SetVersion](_r_d_b.md#oh_rdb_setversion)&nbsp;([OH_Rdb_Store](_o_h___rdb___store.md)&nbsp;\*store,&nbsp;int&nbsp;version) | 设置数据库版本。 |

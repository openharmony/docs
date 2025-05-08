# oh_rdb_transaction.h


## 概述

提供与数据库事务相关的函数和枚举。

**引用文件：**&lt;database/rdb/oh_rdb_transaction.h&gt;

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 18

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype) [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype) | 表示关系型数据库事务类型。 | 
| typedef struct [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) | 定义[OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions)结构类型。 | 
| typedef struct [OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) [OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) | 定义[OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction)结构类型。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype-1) { RDB_TRANS_DEFERRED = 0, RDB_TRANS_IMMEDIATE, RDB_TRANS_EXCLUSIVE, RDB_TRANS_BUTT } | 表示关系型数据库事务类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) \* [OH_RdbTrans_CreateOptions](_r_d_b.md#oh_rdbtrans_createoptions) (void) | 创建事务配置对象。 | 
| int [OH_RdbTrans_DestroyOptions](_r_d_b.md#oh_rdbtrans_destroyoptions) ([OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) \*opitons) | 销毁事务配置对象。 | 
| int [OH_RdbTransOption_SetType](_r_d_b.md#oh_rdbtransoption_settype) ([OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) \*opitons, [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype) type) | 设置关系型数据库事务类型。 | 
| int [OH_RdbTrans_Commit](_r_d_b.md#oh_rdbtrans_commit) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans) | 提交事务。 | 
| int [OH_RdbTrans_Rollback](_r_d_b.md#oh_rdbtrans_rollback) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans) | 回滚事务。 | 
| int [OH_RdbTrans_Insert](_r_d_b.md#oh_rdbtrans_insert) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*table, const [OH_VBucket](_o_h___v_bucket.md) \*row, int64_t \*rowId) | 将一行数据插入到目标表中。 | 
| int [OH_RdbTrans_BatchInsert](_r_d_b.md#oh_rdbtrans_batchinsert) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*table, const [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*rows, [Rdb_ConflictResolution](_r_d_b.md#rdb_conflictresolution) resolution, int64_t \*changes) | 将一组数据批量插入到目标表中。  | 
| int [OH_RdbTrans_Update](_r_d_b.md#oh_rdbtrans_update) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const [OH_VBucket](_o_h___v_bucket.md) \*row, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | 根据指定的条件更新数据库中的数据。 | 
| int [OH_RdbTrans_Delete](_r_d_b.md#oh_rdbtrans_delete) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | 根据指定条件从数据库中删除数据。 | 
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_Query](_r_d_b.md#oh_rdbtrans_query) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*columns[], int len) | 根据指定的条件查询数据库中的数据。 | 
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_QuerySql](_r_d_b.md#oh_rdbtrans_querysql) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](_r_d_b.md#oh_data_values) \*args) | 根据SQL语句查询数据库中的数据。 | 
| int [OH_RdbTrans_Execute](_r_d_b.md#oh_rdbtrans_execute) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](_r_d_b.md#oh_data_values) \*args, [OH_Data_Value](_r_d_b.md#oh_data_value) \*\*result) | 执行包含指定参数的SQL语句。 | 
| int [OH_RdbTrans_Destroy](_r_d_b.md#oh_rdbtrans_destroy) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans) | 销毁事务对象。 | 

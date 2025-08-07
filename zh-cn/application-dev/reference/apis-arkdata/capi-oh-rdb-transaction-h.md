# oh_rdb_transaction.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--SE: @widecode; @htt1997-->
<!--TSE: @yippo; @logic42-->

## 概述

提供与数据库事务相关的函数和枚举。

**引用文件：** <database/rdb/oh_rdb_transaction.h>

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 18

**相关模块：** [RDB](capi-rdb.md)

## 汇总

### 结构体

| 名称                                               | typedef关键字       | 描述                                                         |
| -------------------------------------------------- | ------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) | OH_RDB_TransOptions | 定义[OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md)结构类型。 |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)   | OH_Rdb_Transaction  | 定义[OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md)结构类型。 |

### 枚举

| 名称                                  | typedef关键字    | 描述                       |
| ------------------------------------- | ---------------- | -------------------------- |
| [OH_RDB_TransType](#oh_rdb_transtype) | OH_RDB_TransType | 表示关系型数据库事务类型。 |

### 函数

| 名称                                                         | 描述                                             |
| ------------------------------------------------------------ | ------------------------------------------------ |
| [OH_RDB_TransOptions *OH_RdbTrans_CreateOptions(void)](#oh_rdbtrans_createoptions) | 创建事务配置对象。                               |
| [int OH_RdbTrans_DestroyOptions(OH_RDB_TransOptions *options)](#oh_rdbtrans_destroyoptions) | 销毁事务配置对象。                               |
| [int OH_RdbTransOption_SetType(OH_RDB_TransOptions *options, OH_RDB_TransType type)](#oh_rdbtransoption_settype) | 设置关系型数据库事务类型。                       |
| [int OH_RdbTrans_Commit(OH_Rdb_Transaction *trans)](#oh_rdbtrans_commit) | 提交事务。                                       |
| [int OH_RdbTrans_Rollback(OH_Rdb_Transaction *trans)](#oh_rdbtrans_rollback) | 回滚事务。                                       |
| [int OH_RdbTrans_Insert(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId)](#oh_rdbtrans_insert) | 将一行数据插入到目标表中。                       |
| [int OH_RdbTrans_InsertWithConflictResolution(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row,Rdb_ConflictResolution resolution, int64_t *rowId)](#oh_rdbtrans_insertwithconflictresolution) | 将一行数据插入到目标表中，支持冲突解决。         |
| [int OH_RdbTrans_BatchInsert(OH_Rdb_Transaction *trans, const char *table, const OH_Data_VBuckets *rows,Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdbtrans_batchinsert) | 将一组数据批量插入到目标表中。                   |
| [int OH_RdbTrans_Update(OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates,int64_t *changes)](#oh_rdbtrans_update) | 根据指定的条件更新数据库中的数据。               |
| [int OH_RdbTrans_UpdateWithConflictResolution(OH_Rdb_Transaction *trans, const OH_VBucket *row,const OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes)](#oh_rdbtrans_updatewithconflictresolution) | 根据指定条件更新数据库中的数据，并支持冲突解决。 |
| [int OH_RdbTrans_Delete(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes)](#oh_rdbtrans_delete) | 根据指定条件从数据库中删除数据。                 |
| [OH_Cursor *OH_RdbTrans_Query(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[],int len)](#oh_rdbtrans_query) | 根据指定的条件查询数据库中的数据。               |
| [OH_Cursor *OH_RdbTrans_QuerySql(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args)](#oh_rdbtrans_querysql) | 根据SQL语句查询数据库中的数据。                  |
| [int OH_RdbTrans_Execute(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result)](#oh_rdbtrans_execute) | 执行包含指定参数的SQL语句。                      |
| [int OH_RdbTrans_Destroy(OH_Rdb_Transaction *trans)](#oh_rdbtrans_destroy) | 销毁事务对象。                                   |

## 枚举类型说明

### OH_RDB_TransType

```
enum OH_RDB_TransType
```

**描述**

表示关系型数据库事务类型。

**起始版本：** 18

| 枚举项                 | 描述                                                         |
| ---------------------- | ------------------------------------------------------------ |
| RDB_TRANS_DEFERRED = 0 | 在首次访问数据库之前，事务默认设置不会启动。                 |
| RDB_TRANS_IMMEDIATE    | 数据库连接立即开始新的写入，而无需等待写入语句。             |
| RDB_TRANS_EXCLUSIVE    | 与RDB_TRANS_IMMEDIATE类型相似，写事务会立即启动。<br>RDB_TRANS_EXCLUSIVE和RDB_TRANS_IMMEDIATE类型在WAL模式下相同，但在其他日志模式下，RDB_TRANS_EXCLUSIVE会阻止其他数据库连接在事务进行时读取数据库。 |
| RDB_TRANS_BUTT         | RDB事务类型的最大值。                                        |


## 函数说明

### OH_RdbTrans_CreateOptions()

```
OH_RDB_TransOptions *OH_RdbTrans_CreateOptions(void)
```

**描述**

创建事务配置对象。

**起始版本：** 18

**返回：**

| 类型                                               | 说明                                                         |
| -------------------------------------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) | 执行成功时返回指向[OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md)实例的指针。否则返回nullptr。<br>使用完成后，必须通过[OH_RdbTrans_DestroyOptions](capi-oh-rdb-transaction-h.md#oh_rdbtrans_destroyoptions)接口释放内存。 |

### OH_RdbTrans_DestroyOptions()

```
int OH_RdbTrans_DestroyOptions(OH_RDB_TransOptions *options)
```

**描述**

销毁事务配置对象。

**起始版本：** 18


**参数：**

| 参数项                                                      | 描述                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) *options | 表示指向[OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_RdbTransOption_SetType()

```
int OH_RdbTransOption_SetType(OH_RDB_TransOptions *options, OH_RDB_TransType type)
```

**描述**

设置关系型数据库事务类型。

**起始版本：** 18


**参数：**

| 参数项                                                      | 描述                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md) *options | 表示指向[OH_RDB_TransOptions](capi-rdb-oh-rdb-transoptions.md)实例的指针。 |
| [OH_RDB_TransType](#oh_rdb_transtype) type                  | 表示关系型数据库事务类型。                                   |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |

### OH_RdbTrans_Commit()

```
int OH_RdbTrans_Commit(OH_Rdb_Transaction *trans)
```

**描述**

提交事务。

**起始版本：** 18


**参数：**

| 参数项                                                  | 描述                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。 |

### OH_RdbTrans_Rollback()

```
int OH_RdbTrans_Rollback(OH_Rdb_Transaction *trans)
```

**描述**

回滚事务。

**起始版本：** 18


**参数：**

| 参数项                                                  | 描述                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。 |

### OH_RdbTrans_Insert()

```
int OH_RdbTrans_Insert(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row, int64_t *rowId)
```

**描述**

将一行数据插入到目标表中。

**起始版本：** 18


**参数：**

| 参数项                                                  | 描述                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const char *table                                       | 表示目标表。                                                 |
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row             | 表示要插入到表中的数据行。                                   |
| int64_t *rowId                                          | 输出参数，表示插入后返回的行号。                             |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。<br>返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。<br>返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。<br>返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。 |

### OH_RdbTrans_InsertWithConflictResolution()

```
int OH_RdbTrans_InsertWithConflictResolution(OH_Rdb_Transaction *trans, const char *table, const OH_VBucket *row,Rdb_ConflictResolution resolution, int64_t *rowId)
```

**描述**

将一行数据插入到目标表中，支持冲突解决。

**起始版本：** 20


**参数：**

| 参数项                                                  | 描述                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const char *table                                       | 表示目标表名称。                                             |
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row             | 表示要插入到表中的数据。                                     |
| Rdb_ConflictResolution resolution                       | 表示发生冲突时的解决策略。                                   |
| int64_t *rowId                                          | 输出参数，表示插入成功后返回的行号。                         |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示输入参数无效。<br>返回RDB_E_ALREADY_CLOSED表示数据库已关闭。<br>返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。<br>返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。<br>返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。<br>返回RDB_E_SQLITE_CONSTRAINT表示SQLite错误码：违反约束导致操作中止。 |

### OH_RdbTrans_BatchInsert()

```
int OH_RdbTrans_BatchInsert(OH_Rdb_Transaction *trans, const char *table, const OH_Data_VBuckets *rows,Rdb_ConflictResolution resolution, int64_t *changes)
```

**描述**

将一组数据批量插入到目标表中。

**起始版本：** 18


**参数：**

| 参数项                                                   | 描述                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const char *table                                        | 表示目标表。                                                 |
| const [OH_Data_VBuckets](capi-rdb-oh-data-vbuckets.md) *rows | 表示要插入到表中的一组数据。                                 |
| Rdb_ConflictResolution resolution                        | 表示发生冲突时的解决策略。                                   |
| int64_t *changes                                         | 输出参数，表示插入成功的次数。                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。<br>返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。<br>返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。<br>返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。<br>返回RDB_E_SQLITE_CONSTRAINT表示SQLite错误码：SQLite约束。 |

### OH_RdbTrans_Update()

```
int OH_RdbTrans_Update(OH_Rdb_Transaction *trans, const OH_VBucket *row, const OH_Predicates *predicates,int64_t *changes)
```

**描述**

根据指定的条件更新数据库中的数据。

**起始版本：** 18


**参数：**

| 参数项                                                   | 描述                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row              | 表示要更新到表中的数据行。                                   |
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | 表示[OH_Predicates](capi-rdb-oh-predicates.md)指定的更新条件。   |
| int64_t *changes                                         | 输出参数，表示更新成功的次数。                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。<br>返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。<br>返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。<br>返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。 |

### OH_RdbTrans_UpdateWithConflictResolution()

```
int OH_RdbTrans_UpdateWithConflictResolution(OH_Rdb_Transaction *trans, const OH_VBucket *row,const OH_Predicates *predicates, Rdb_ConflictResolution resolution, int64_t *changes)
```

**描述**

根据指定条件更新数据库中的数据，并支持冲突解决。

**起始版本：** 20


**参数：**

| 参数项                                                   | 描述                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const [OH_VBucket](capi-rdb-oh-vbucket.md) *row              | 表示要更新到表中的数据。                                     |
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | 表示[OH_Predicates](capi-rdb-oh-predicates.md)指定的更新条件。   |
| Rdb_ConflictResolution resolution                        | 表示发生冲突时的解决策略。                                   |
| int64_t *changes                                         | 输出参数，表示更新成功的行数。                               |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示输入参数无效。<br>返回RDB_E_ALREADY_CLOSED表示数据库已关闭。<br>返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。<br>返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。<br>返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。<br>返回RDB_E_SQLITE_CONSTRAINT表示SQLite错误码：违反约束导致操作中止。 |

### OH_RdbTrans_Delete()

```
int OH_RdbTrans_Delete(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, int64_t *changes)
```

**描述**

根据指定条件从数据库中删除数据。

**起始版本：** 18


**参数：**

| 参数项                                                   | 描述                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | 表示[OH_Predicates](capi-rdb-oh-predicates.md)指定的删除条件。   |
| int64_t *changes                                         | 表示删除成功的次数。                                         |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。<br>返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。<br>返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。<br>返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。 |

### OH_RdbTrans_Query()

```
OH_Cursor *OH_RdbTrans_Query(OH_Rdb_Transaction *trans, const OH_Predicates *predicates, const char *columns[],int len)
```

**描述**

根据指定的条件查询数据库中的数据。

**起始版本：** 18


**参数：**

| 参数项                                                   | 描述                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans  | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const [OH_Predicates](capi-rdb-oh-predicates.md) *predicates | 表示[OH_Predicates](capi-rdb-oh-predicates.md)指定的查询条件。   |
| columns                                                  | 表示要查询的列，如果传入空值，则查询适用于所有列。           |
| int len                                                  | 表示列中元素的个数。                                         |

**返回：**

| 类型                           | 说明                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) | 如果执行成功，则返回指向[OH_Cursor](capi-rdb-oh-cursor.md)实例的指针。如果数据库已关闭或数据库没有响应，则返回空。 |

### OH_RdbTrans_QuerySql()

```
OH_Cursor *OH_RdbTrans_QuerySql(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args)
```

**描述**

根据SQL语句查询数据库中的数据。

**起始版本：** 18


**参数：**

| 参数项                                                  | 描述                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const char *sql                                         | 表示要执行的SQL语句。                                        |
| const [OH_Data_Values](capi-rdb-oh-data-values.md) *args    | 表示指向[OH_Data_Values](capi-rdb-oh-data-values.md)的指针。     |

**返回：**

| 类型                           | 说明                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| [OH_Cursor](capi-rdb-oh-cursor.md) | 如果执行成功，则返回指向[OH_Cursor](capi-rdb-oh-cursor.md)实例的指针。如果数据库已关闭或数据库没有响应，则返回空。 |

### OH_RdbTrans_Execute()

```
int OH_RdbTrans_Execute(OH_Rdb_Transaction *trans, const char *sql, const OH_Data_Values *args, OH_Data_Value **result)
```

**描述**

执行包含指定参数的SQL语句。

**起始版本：** 18


**参数：**

| 参数项                                                  | 描述                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |
| const char *sql                                         | 表示要执行的SQL语句。                                        |
| const [OH_Data_Values](capi-rdb-oh-data-values.md) *args    | SQL语句中包含的参数。                                        |
| OH_Data_Value **result                                  | 执行成功时指向[OH_Data_Value](capi-rdb-oh-data-value.md)实例的指针。使用完成后，必须通过[OH_Value_Destroy](capi-oh-data-value-h.md#oh_value_destroy)接口释放内存。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回执行结果。<br>返回RDB_OK表示成功。<br>返回RDB_E_ERROR表示数据库常见错误。<br>返回RDB_E_INVALID_ARGS表示无效参数。<br>返回RDB_E_ALREADY_CLOSED表示数据库已经关闭。<br>返回RDB_E_WAL_SIZE_OVER_LIMIT表示WAL日志文件大小超过默认值。<br>返回RDB_E_SQLITE_FULL表示SQLite错误码：数据库已满。<br>返回RDB_E_SQLITE_CORRUPT表示数据库损坏。<br>返回RDB_E_SQLITE_PERM表示SQLite错误码：访问权限被拒绝。<br>返回RDB_E_SQLITE_BUSY表示SQLite错误码：数据库文件被锁定。<br>返回RDB_E_SQLITE_LOCKED表示SQLite错误码：数据库中的表被锁定。<br>返回RDB_E_SQLITE_NOMEM表示SQLite错误码：数据库内存不足。<br>返回RDB_E_SQLITE_READONLY表示SQLite错误码：尝试写入只读数据库。<br>返回RDB_E_SQLITE_IOERR表示SQLite错误码：磁盘I/O错误。<br>返回RDB_E_SQLITE_TOO_BIG表示SQLite错误码：TEXT或BLOB超出大小限制。<br>返回RDB_E_SQLITE_MISMATCH表示SQLite错误码：数据类型不匹配。 |

### OH_RdbTrans_Destroy()

```
int OH_RdbTrans_Destroy(OH_Rdb_Transaction *trans)
```

**描述**

销毁事务对象。

**起始版本：** 18


**参数：**

| 参数项                                                  | 描述                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md) *trans | 表示指向[OH_Rdb_Transaction](capi-rdb-oh-rdb-transaction.md)实例的指针。 |

**返回：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| int  | 返回错误码。<br>返回RDB_OK表示成功。<br>返回RDB_E_INVALID_ARGS表示无效参数。 |


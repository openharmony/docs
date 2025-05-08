# oh_rdb_types.h


## 概述

提供与数据值相关的类型定义。

**库：** libnative_rdb_ndk.z.so

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**起始版本：** 18

**相关模块：**[RDB](_r_d_b.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Rdb_ConflictResolution](_r_d_b.md#rdb_conflictresolution) [Rdb_ConflictResolution](_r_d_b.md#rdb_conflictresolution) | 表示冲突解决策略的枚举。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Rdb_ConflictResolution](_r_d_b.md#rdb_conflictresolution-1) {<br/>RDB_CONFLICT_NONE = 1, RDB_CONFLICT_ROLLBACK, RDB_CONFLICT_ABORT, RDB_CONFLICT_FAIL,<br/>RDB_CONFLICT_IGNORE, RDB_CONFLICT_REPLACE<br/>} | 表示冲突解决策略的枚举。  | 

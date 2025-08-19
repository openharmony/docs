# Rdb_TableDetails
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## 概述

描述数据库表执行端云同步任务上传和下载的统计信息。

**起始版本：** 11

**相关模块：** [RDB](capi-rdb.md)

**所在头文件：** [relational_store.h](capi-relational-store-h.md)

## 汇总

### 成员变量

| 名称                                            | 描述                                       |
| ----------------------------------------------- | ------------------------------------------ |
| const char* table                               | 数据库表名。                               |
| [Rdb_Statistic](capi-rdb-rdb-statistic.md) upload   | 表示数据库表中端云同步上传过程的统计信息。 |
| [Rdb_Statistic](capi-rdb-rdb-statistic.md) download | 表示数据库表中端云同步下载过程的统计信息。 |


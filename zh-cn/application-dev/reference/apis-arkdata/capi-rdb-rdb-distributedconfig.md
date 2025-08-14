# Rdb_DistributedConfig
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--SE: @widecode; @htt1997-->
<!--TSE: @yippo; @logic42-->

## 概述

记录表的分布式配置信息。

**起始版本：** 11

**相关模块：** [RDB](capi-rdb.md)

**所在头文件：** [relational_store.h](capi-relational-store-h.md)

## 汇总

### 成员变量

| 名称            | 描述                                          |
| --------------- | --------------------------------------------- |
| int version     | 用于唯一标识Rdb_DistributedConfig结构的版本。 |
| bool isAutoSync | 表示该表是否支持自动同步。                    |


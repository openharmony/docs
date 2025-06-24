# Rdb_DataObserver

## 概述

表示数据观察者。

**起始版本：** 11

**相关模块：** [RDB](capi-rdb.md)

**所在头文件：** [relational_store.h](capi-relational-store-h.md)

## 汇总

### 成员变量

| 名称                                                         | 描述                     |
| ------------------------------------------------------------ | ------------------------ |
| void* context                                                | 表示数据观察者的上下文。 |
| [Rdb_SubscribeCallback](capi-rdb-rdb-subscribecallback.md) callback | 数据观察者的回调。       |


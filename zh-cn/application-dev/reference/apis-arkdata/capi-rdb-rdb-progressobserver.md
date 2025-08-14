# Rdb_ProgressObserver
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--SE: @widecode; @htt1997-->
<!--TSE: @yippo; @logic42-->

## 概述

端云同步进度观察者。

**起始版本：** 11

**相关模块：** [RDB](capi-rdb.md)

**所在头文件：** [relational_store.h](capi-relational-store-h.md)

## 汇总

### 成员变量

| 名称                                                         | 描述                           |
| ------------------------------------------------------------ | ------------------------------ |
| void* context                                                | 端云同步进度观察者的上下文。   |
| [Rdb_ProgressCallback](capi-relational-store-h.md#rdb_progresscallback) callback | 端云同步进度观察者的回调函数。 |


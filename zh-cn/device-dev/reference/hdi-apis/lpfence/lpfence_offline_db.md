# OfflineDb


## 概述

定义下发基站离线数据库的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [times](#times) | 当前数据包的序号，从1开始。 | 
| unsigned int [totalTimes](#totaltimes) | 此次下发基站离线数据库的总包数。 | 
| unsigned char[] [dbs](#dbs) | 基站离线数据库数据。 | 


## 类成员变量说明


### dbs

```
unsigned char [] OfflineDb::dbs
```

**描述**


基站离线数据库数据。


### times

```
unsigned int OfflineDb::times
```

**描述**


当前数据包的序号，从1开始。


### totalTimes

```
unsigned int OfflineDb::totalTimes
```

**描述**


此次下发基站离线数据库的总包数。

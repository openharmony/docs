# AGnssRefInfo


## 概述

定义AGNSS参考信息结构体。

**起始版本：** 3.2

**相关模块：**[HdiAGnss](_hdi_a_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum AGnssRefInfoType [type](#type) | 参考信息类型 | 
| struct [AGnssRefCellId](_a_gnss_ref_cell_id.md)[cellId](#cellid) | 小区ID | 
| struct [AGnssRefMac](_a_gnss_ref_mac.md)[mac](#mac) | MAC地址 | 


## 类成员变量说明


### cellId

```
struct AGnssRefCellId AGnssRefInfo::cellId
```

**描述**


小区ID


### mac

```
struct AGnssRefMac AGnssRefInfo::mac
```

**描述**


MAC地址


### type

```
enum AGnssRefInfoType AGnssRefInfo::type
```

**描述**


参考信息类型

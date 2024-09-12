# AGnssRefCellId


## 概述

定义AGNSS参考信息中cellId的结构体。

**起始版本：** 3.2

**相关模块：**[HdiAGnss](_hdi_a_gnss.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum CellIdType [type](#type) | 小区ID类型 | 
| unsigned short [mcc](#mcc) | 移动设备国家码 | 
| unsigned short [mnc](#mnc) | 移动设备网络码 | 
| unsigned short [lac](#lac) | 位置区域码 | 
| unsigned int [cid](#cid) | 小区ID | 
| unsigned short [tac](#tac) | 跟踪区域码 | 
| unsigned short [pcid](#pcid) | 物理小区ID | 
| unsigned int [nci](#nci) | NR的小区ID | 


## 类成员变量说明


### cid

```
unsigned int AGnssRefCellId::cid
```

**描述**


小区ID


### lac

```
unsigned short AGnssRefCellId::lac
```

**描述**


位置区域码


### mcc

```
unsigned short AGnssRefCellId::mcc
```

**描述**


移动设备国家码


### mnc

```
unsigned short AGnssRefCellId::mnc
```

**描述**


移动设备网络码


### nci

```
unsigned int AGnssRefCellId::nci
```

**描述**


NR的小区ID


### pcid

```
unsigned short AGnssRefCellId::pcid
```

**描述**


物理小区ID


### tac

```
unsigned short AGnssRefCellId::tac
```

**描述**


跟踪区域码


### type

```
enum CellIdType AGnssRefCellId::type
```

**描述**


小区ID类型

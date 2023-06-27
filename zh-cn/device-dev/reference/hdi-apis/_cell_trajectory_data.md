# CellTrajectoryData


## 概述

定义上报的基站轨迹数据的数据结构。

**Since:**

4.0

**相关模块:**

[HdiLpfenceCellbatching](_hdi_lpfence_cellbatching.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [timeStampLow](#timestamplow) | unsigned&nbsp;int<br/>时间戳的低32位 | 
| [timeStampHigh](#timestamphigh) | unsigned&nbsp;int<br/>时间戳的高32位 | 
| [cid](#cid) | unsigned&nbsp;lone<br/>基站号 | 
| [lac](#lac) | unsigned&nbsp;int<br/>小区号 | 
| [rssi](#rssi) | unsigned&nbsp;short<br/>信号接收强度 | 
| [mcc](#mcc) | unsigned&nbsp;short<br/>移动国家码 | 
| [mnc](#mnc) | unsigned&nbsp;short<br/>移动网络码 | 


## 类成员变量说明


### cid

  
```
unsigned lone CellTrajectoryData::cid
```

**描述:**

基站号


### lac

  
```
unsigned int CellTrajectoryData::lac
```

**描述:**

小区号


### mcc

  
```
unsigned short CellTrajectoryData::mcc
```

**描述:**

移动国家码


### mnc

  
```
unsigned short CellTrajectoryData::mnc
```

**描述:**

移动网络码


### rssi

  
```
unsigned short CellTrajectoryData::rssi
```

**描述:**

信号接收强度


### timeStampHigh

  
```
unsigned int CellTrajectoryData::timeStampHigh
```

**描述:**

时间戳的高32位


### timeStampLow

  
```
unsigned int CellTrajectoryData::timeStampLow
```

**描述:**

时间戳的低32位

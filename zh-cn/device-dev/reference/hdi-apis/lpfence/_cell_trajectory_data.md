# CellTrajectoryData


## 概述

定义上报的基站轨迹数据的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellbatching](_hdi_lpfence_cellbatching.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [timeStampLow](#timestamplow) | 时间戳的低32位  | 
| unsigned int [timeStampHigh](#timestamphigh) | 时间戳的高32位  | 
| unsigned lone [cid](#cid) | 基站号  | 
| unsigned int [lac](#lac) | 小区号  | 
| unsigned short [rssi](#rssi) | 信号接收强度  | 
| unsigned short [mcc](#mcc) | 移动国家码  | 
| unsigned short [mnc](#mnc) | 移动网络码  | 


## 类成员变量说明


### cid

```
unsigned lone CellTrajectoryData::cid
```
**描述**

基站号


### lac

```
unsigned int CellTrajectoryData::lac
```
**描述**

小区号


### mcc

```
unsigned short CellTrajectoryData::mcc
```
**描述**

移动国家码


### mnc

```
unsigned short CellTrajectoryData::mnc
```
**描述**

移动网络码


### rssi

```
unsigned short CellTrajectoryData::rssi
```
**描述**

信号接收强度


### timeStampHigh

```
unsigned int CellTrajectoryData::timeStampHigh
```
**描述**

时间戳的高32位


### timeStampLow

```
unsigned int CellTrajectoryData::timeStampLow
```
**描述**

时间戳的低32位

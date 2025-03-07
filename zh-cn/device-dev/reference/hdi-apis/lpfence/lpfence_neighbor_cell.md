# NeighborCell


## 概述

定义设备驻留的基站邻区信息的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [physicalId](#physicalid) | 邻区ID号 | 
| unsigned short [mcc](#mcc) | 移动国家码 | 
| unsigned short [mnc](#mnc) | 移动网络码 | 
| short [rssi](#rssi) | 信号接收强度 | 
| unsigned short [rat](#rat) | 网络制式 | 
| unsigned int [pci](#pci) | 物理小区识别码 | 


## 类成员变量说明


### mcc

```
unsigned short NeighborCell::mcc
```

**描述**


移动国家码


### mnc

```
unsigned short NeighborCell::mnc
```

**描述**


移动网络码


### pci

```
unsigned int NeighborCell::pci
```

**描述**


物理小区识别码


### physicalId

```
int NeighborCell::physicalId
```

**描述**


邻区ID号


### rat

```
unsigned short NeighborCell::rat
```

**描述**


网络制式


### rssi

```
short NeighborCell::rssi
```

**描述**


信号接收强度

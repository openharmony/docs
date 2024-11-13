# CurrentCell


## 概述

定义设备驻留的基站主区信息的数据结构。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceGeofence](_hdi_lpfence_geofence.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [cellId](#cellid) | 小区号 | 
| int [lac](#lac) | 基站号 | 
| unsigned short [mcc](#mcc) | 移动国家码 | 
| unsigned short [mnc](#mnc) | 移动网络码 | 
| short [rssi](#rssi) | 信号接收强度 | 
| unsigned short [rat](#rat) | 网络制式，1代表GSM，2代表WCDMA或TD-CDMA，3代表LTE，4代表5G NR。 | 
| unsigned int [pci](#pci) | 物理小区识别码 | 
| int [bootTimeLow](#boottimelow) | 时间戳的低32位 | 
| int [bootTimeHigh](#boottimehigh) | 时间戳的高32位 | 


## 类成员变量说明


### bootTimeHigh

```
int CurrentCell::bootTimeHigh
```

**描述**


时间戳的高32位


### bootTimeLow

```
int CurrentCell::bootTimeLow
```

**描述**


时间戳的低32位


### cellId

```
long CurrentCell::cellId
```

**描述**


小区号


### lac

```
int CurrentCell::lac
```

**描述**


基站号


### mcc

```
unsigned short CurrentCell::mcc
```

**描述**


移动国家码


### mnc

```
unsigned short CurrentCell::mnc
```

**描述**


移动网络码


### pci

```
unsigned int CurrentCell::pci
```

**描述**


物理小区识别码


### rat

```
unsigned short CurrentCell::rat
```

**描述**


网络制式，1代表GSM，2代表WCDMA或TD-CDMA，3代表LTE，4代表5G NR。


### rssi

```
short CurrentCell::rssi
```

**描述**


信号接收强度

# PhysicalChannelConfig


## 概述

物理通道配置。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [RilCellConnectionStatus](_ril_v11.md#rilcellconnectionstatus)[cellConnStatus](#cellconnstatus) | 连接状态  | 
| enum [RilRadioTech](_ril_v11.md#rilradiotech)[ratType](#rattype) | 语音接入技术类型，具体查看[RilRadioTech](_ril_v11.md#rilradiotech) | 
| int [cellBandwidthDownlinkKhz](#cellbandwidthdownlinkkhz) | 下行带宽，单位为kHz  | 
| int [cellBandwidthUplinkKhz](#cellbandwidthuplinkkhz) | 上行带宽，单位为kHz  | 
| int [freqRange](#freqrange) | 频率范围  | 
| int [downlinkChannelNum](#downlinkchannelnum) | 下行信道号  | 
| int [uplinkChannelNum](#uplinkchannelnum) | 上行信道号  | 
| int [physicalCellId](#physicalcellid) | 物理小区标识  | 
| int [contextIdNum](#contextidnum) | 逻辑设备编号  | 
| List&lt; int &gt; [contextIds](#contextids) | 上行信道号  | 


## 类成员变量说明


### cellBandwidthDownlinkKhz

```
int PhysicalChannelConfig::cellBandwidthDownlinkKhz
```
**描述**

下行带宽，单位为kHz


### cellBandwidthUplinkKhz

```
int PhysicalChannelConfig::cellBandwidthUplinkKhz
```
**描述**

上行带宽，单位为kHz


### cellConnStatus

```
enum RilCellConnectionStatus PhysicalChannelConfig::cellConnStatus
```
**描述**

连接状态


### contextIdNum

```
int PhysicalChannelConfig::contextIdNum
```
**描述**

逻辑设备编号


### contextIds

```
List<int> PhysicalChannelConfig::contextIds
```
**描述**

上行信道号


### downlinkChannelNum

```
int PhysicalChannelConfig::downlinkChannelNum
```
**描述**

下行信道号


### freqRange

```
int PhysicalChannelConfig::freqRange
```
**描述**

频率范围


### physicalCellId

```
int PhysicalChannelConfig::physicalCellId
```
**描述**

物理小区标识


### ratType

```
enum RilRadioTech PhysicalChannelConfig::ratType
```
**描述**

语音接入技术类型，具体查看[RilRadioTech](_ril_v11.md#rilradiotech)


### uplinkChannelNum

```
int PhysicalChannelConfig::uplinkChannelNum
```
**描述**

上行信道号

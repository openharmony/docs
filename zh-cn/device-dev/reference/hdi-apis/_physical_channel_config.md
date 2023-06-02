# PhysicalChannelConfig


## 概述

物理通道配置。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [cellConnStatus](#cellconnstatus) | enum&nbsp;[RilCellConnectionStatus](_ril.md#rilcellconnectionstatus)<br/>连接状态&nbsp; | 
| [ratType](#rattype) | enum&nbsp;[RilRadioTech](_ril.md#rilradiotech)<br/>语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech) | 
| [cellBandwidthDownlinkKhz](#cellbandwidthdownlinkkhz) | int<br/>下行带宽，单位为kHz&nbsp; | 
| [cellBandwidthUplinkKhz](#cellbandwidthuplinkkhz) | int<br/>上行带宽，单位为kHz&nbsp; | 
| [freqRange](#freqrange) | int<br/>频率范围&nbsp; | 
| [downlinkChannelNum](#downlinkchannelnum) | int<br/>下行信道号&nbsp; | 
| [uplinkChannelNum](#uplinkchannelnum) | int<br/>上行信道号&nbsp; | 
| [physicalCellId](#physicalcellid) | int<br/>物理小区标识&nbsp; | 
| [contextIdNum](#contextidnum) | int<br/>逻辑设备编号&nbsp; | 
| [contextIds](#contextids) | List&lt;&nbsp;int&nbsp;&gt;<br/>上行信道号&nbsp; | 


## 类成员变量说明


### cellBandwidthDownlinkKhz

  
```
int PhysicalChannelConfig::cellBandwidthDownlinkKhz
```
**描述:**
下行带宽，单位为kHz


### cellBandwidthUplinkKhz

  
```
int PhysicalChannelConfig::cellBandwidthUplinkKhz
```
**描述:**
上行带宽，单位为kHz


### cellConnStatus

  
```
enum RilCellConnectionStatus PhysicalChannelConfig::cellConnStatus
```
**描述:**
连接状态


### contextIdNum

  
```
int PhysicalChannelConfig::contextIdNum
```
**描述:**
逻辑设备编号


### contextIds

  
```
List<int> PhysicalChannelConfig::contextIds
```
**描述:**
上行信道号


### downlinkChannelNum

  
```
int PhysicalChannelConfig::downlinkChannelNum
```
**描述:**
下行信道号


### freqRange

  
```
int PhysicalChannelConfig::freqRange
```
**描述:**
频率范围


### physicalCellId

  
```
int PhysicalChannelConfig::physicalCellId
```
**描述:**
物理小区标识


### ratType

  
```
enum RilRadioTech PhysicalChannelConfig::ratType
```
**描述:**
语音接入技术类型，具体查看[RilRadioTech](_ril.md#rilradiotech)


### uplinkChannelNum

  
```
int PhysicalChannelConfig::uplinkChannelNum
```
**描述:**
上行信道号

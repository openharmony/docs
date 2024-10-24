# DataLinkBandwidthReportingRule


## 概述

网络频率上报规则。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [rat](#rat) | 无线接入技术，具体查看[RilRadioTech](_ril_v11.md#rilradiotech) | 
| int [delayMs](#delayms) | 迟滞时间  | 
| int [delayUplinkKbps](#delayuplinkkbps) | 上行迟滞  | 
| int [delayDownlinkKbps](#delaydownlinkkbps) | 下行迟滞  | 
| int [maximumUplinkKbpsSize](#maximumuplinkkbpssize) | 最大上行参数数量  | 
| int [maximumDownlinkKbpsSize](#maximumdownlinkkbpssize) | 最大下行参数数量  | 
| List&lt; int &gt; [maximumUplinkKbps](#maximumuplinkkbps) | 最大上行参数列表  | 
| List&lt; int &gt; [maximumDownlinkKbps](#maximumdownlinkkbps) | 最大下行参数列表  | 


## 类成员变量说明


### delayDownlinkKbps

```
int DataLinkBandwidthReportingRule::delayDownlinkKbps
```
**描述**

下行迟滞


### delayMs

```
int DataLinkBandwidthReportingRule::delayMs
```
**描述**

迟滞时间


### delayUplinkKbps

```
int DataLinkBandwidthReportingRule::delayUplinkKbps
```
**描述**

上行迟滞


### maximumDownlinkKbps

```
List<int> DataLinkBandwidthReportingRule::maximumDownlinkKbps
```
**描述**

最大下行参数列表


### maximumDownlinkKbpsSize

```
int DataLinkBandwidthReportingRule::maximumDownlinkKbpsSize
```
**描述**

最大下行参数数量


### maximumUplinkKbps

```
List<int> DataLinkBandwidthReportingRule::maximumUplinkKbps
```
**描述**

最大上行参数列表


### maximumUplinkKbpsSize

```
int DataLinkBandwidthReportingRule::maximumUplinkKbpsSize
```
**描述**

最大上行参数数量


### rat

```
int DataLinkBandwidthReportingRule::rat
```
**描述**

无线接入技术，具体查看[RilRadioTech](_ril_v11.md#rilradiotech)


### serial

```
int DataLinkBandwidthReportingRule::serial
```
**描述**

请求的序列号

# DataLinkBandwidthReportingRule


## 概述

网络频率上报规则。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [rat](#rat) | int<br/>无线接入技术，具体查看[RilRadioTech](_ril.md#rilradiotech) | 
| [delayMs](#delayms) | int<br/>迟滞时间&nbsp; | 
| [delayUplinkKbps](#delayuplinkkbps) | int<br/>上行迟滞&nbsp; | 
| [delayDownlinkKbps](#delaydownlinkkbps) | int<br/>下行迟滞&nbsp; | 
| [maximumUplinkKbpsSize](#maximumuplinkkbpssize) | int<br/>最大上行参数数量&nbsp; | 
| [maximumDownlinkKbpsSize](#maximumdownlinkkbpssize) | int<br/>最大下行参数数量&nbsp; | 
| [maximumUplinkKbps](#maximumuplinkkbps) | List&lt;&nbsp;int&nbsp;&gt;<br/>最大上行参数列表&nbsp; | 
| [maximumDownlinkKbps](#maximumdownlinkkbps) | List&lt;&nbsp;int&nbsp;&gt;<br/>最大下行参数列表&nbsp; | 


## 类成员变量说明


### delayDownlinkKbps

  
```
int DataLinkBandwidthReportingRule::delayDownlinkKbps
```
**描述:**
下行迟滞


### delayMs

  
```
int DataLinkBandwidthReportingRule::delayMs
```
**描述:**
迟滞时间


### delayUplinkKbps

  
```
int DataLinkBandwidthReportingRule::delayUplinkKbps
```
**描述:**
上行迟滞


### maximumDownlinkKbps

  
```
List<int> DataLinkBandwidthReportingRule::maximumDownlinkKbps
```
**描述:**
最大下行参数列表


### maximumDownlinkKbpsSize

  
```
int DataLinkBandwidthReportingRule::maximumDownlinkKbpsSize
```
**描述:**
最大下行参数数量


### maximumUplinkKbps

  
```
List<int> DataLinkBandwidthReportingRule::maximumUplinkKbps
```
**描述:**
最大上行参数列表


### maximumUplinkKbpsSize

  
```
int DataLinkBandwidthReportingRule::maximumUplinkKbpsSize
```
**描述:**
最大上行参数数量


### rat

  
```
int DataLinkBandwidthReportingRule::rat
```
**描述:**
无线接入技术，具体查看[RilRadioTech](_ril.md#rilradiotech)


### serial

  
```
int DataLinkBandwidthReportingRule::serial
```
**描述:**
请求的序列号

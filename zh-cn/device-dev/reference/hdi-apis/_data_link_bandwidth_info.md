# DataLinkBandwidthInfo


## 概述

网络频率信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [serial](#serial) | int<br/>请求的序列号&nbsp; | 
| [cid](#cid) | int<br/>PDP上下文标识符&nbsp; | 
| [qi](#qi) | int<br/>服务质量(QoS)类别指示&nbsp; | 
| [dlGfbr](#dlgfbr) | int<br/>下行方向保证比特速率(GBR)&nbsp; | 
| [ulGfbr](#ulgfbr) | int<br/>上行方向GBR&nbsp; | 
| [dlMfbr](#dlmfbr) | int<br/>下行方向最大比特速率(MBR)&nbsp; | 
| [ulMfbr](#ulmfbr) | int<br/>上行方向MBR&nbsp; | 
| [ulSambr](#ulsambr) | int<br/>上行方向聚合最大比特速率(AMBR)&nbsp; | 
| [dlSambr](#dlsambr) | int<br/>下行方向AMBR&nbsp; | 
| [averagingWindow](#averagingwindow) | int<br/>时间单位&nbsp; | 


## 类成员变量说明


### averagingWindow

  
```
int DataLinkBandwidthInfo::averagingWindow
```
**描述:**
时间单位


### cid

  
```
int DataLinkBandwidthInfo::cid
```
**描述:**
PDP上下文标识符


### dlGfbr

  
```
int DataLinkBandwidthInfo::dlGfbr
```
**描述:**
下行方向保证比特速率(GBR)


### dlMfbr

  
```
int DataLinkBandwidthInfo::dlMfbr
```
**描述:**
下行方向最大比特速率(MBR)


### dlSambr

  
```
int DataLinkBandwidthInfo::dlSambr
```
**描述:**
下行方向AMBR


### qi

  
```
int DataLinkBandwidthInfo::qi
```
**描述:**
服务质量(QoS)类别指示


### serial

  
```
int DataLinkBandwidthInfo::serial
```
**描述:**
请求的序列号


### ulGfbr

  
```
int DataLinkBandwidthInfo::ulGfbr
```
**描述:**
上行方向GBR


### ulMfbr

  
```
int DataLinkBandwidthInfo::ulMfbr
```
**描述:**
上行方向MBR


### ulSambr

  
```
int DataLinkBandwidthInfo::ulSambr
```
**描述:**
上行方向聚合最大比特速率(AMBR)

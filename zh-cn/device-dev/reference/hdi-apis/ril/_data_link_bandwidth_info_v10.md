# DataLinkBandwidthInfo


## 概述

网络频率信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [cid](#cid) | PDP上下文标识符  | 
| int [qi](#qi) | 服务质量(QoS)类别指示  | 
| int [dlGfbr](#dlgfbr) | 下行方向保证比特速率(GBR)  | 
| int [ulGfbr](#ulgfbr) | 上行方向GBR  | 
| int [dlMfbr](#dlmfbr) | 下行方向最大比特速率(MBR)  | 
| int [ulMfbr](#ulmfbr) | 上行方向MBR  | 
| int [ulSambr](#ulsambr) | 上行方向聚合最大比特速率(AMBR)  | 
| int [dlSambr](#dlsambr) | 下行方向AMBR  | 
| int [averagingWindow](#averagingwindow) | 时间单位  | 


## 类成员变量说明


### averagingWindow

```
int DataLinkBandwidthInfo::averagingWindow
```
**描述**

时间单位


### cid

```
int DataLinkBandwidthInfo::cid
```
**描述**

PDP上下文标识符


### dlGfbr

```
int DataLinkBandwidthInfo::dlGfbr
```
**描述**

下行方向保证比特速率(GBR)


### dlMfbr

```
int DataLinkBandwidthInfo::dlMfbr
```
**描述**

下行方向最大比特速率(MBR)


### dlSambr

```
int DataLinkBandwidthInfo::dlSambr
```
**描述**

下行方向AMBR


### qi

```
int DataLinkBandwidthInfo::qi
```
**描述**

服务质量(QoS)类别指示


### serial

```
int DataLinkBandwidthInfo::serial
```
**描述**

请求的序列号


### ulGfbr

```
int DataLinkBandwidthInfo::ulGfbr
```
**描述**

上行方向GBR


### ulMfbr

```
int DataLinkBandwidthInfo::ulMfbr
```
**描述**

上行方向MBR


### ulSambr

```
int DataLinkBandwidthInfo::ulSambr
```
**描述**

上行方向聚合最大比特速率(AMBR)

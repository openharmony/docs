# ApduSimIORequestInfo


## 概述

APDU数据传输请求信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [serial](#serial) | 请求的序列号  | 
| int [channelId](#channelid) | 通道ID  | 
| int [type](#type) | APDU指令类型，参考ETSI 102 221 [55]  | 
| int [instruction](#instruction) | APDU指令，参考ETSI 102 221 [55]  | 
| int [p1](#p1) | SIM数据请求命令参数，参考3GPP TS 51.011[28]  | 
| int [p2](#p2) | SIM数据请求命令参数2，参考3GPP TS 51.011[28]  | 
| int [p3](#p3) | SIM数据请求命令参数3，参考3GPP TS 51.011[28] 如果p3为负值，则会向SIM发送一个4字节的APDU  | 
| String [data](#data) | 请求传输的数据信息  | 


## 类成员变量说明


### channelId

```
int ApduSimIORequestInfo::channelId
```
**描述**

通道ID


### data

```
String ApduSimIORequestInfo::data
```
**描述**

请求传输的数据信息


### instruction

```
int ApduSimIORequestInfo::instruction
```
**描述**

APDU指令，参考ETSI 102 221 [55]


### p1

```
int ApduSimIORequestInfo::p1
```
**描述**

SIM数据请求命令参数，参考3GPP TS 51.011[28]


### p2

```
int ApduSimIORequestInfo::p2
```
**描述**

SIM数据请求命令参数2，参考3GPP TS 51.011[28]


### p3

```
int ApduSimIORequestInfo::p3
```
**描述**

SIM数据请求命令参数3，参考3GPP TS 51.011[28] 如果p3为负值，则会向SIM发送一个4字节的APDU


### serial

```
int ApduSimIORequestInfo::serial
```
**描述**

请求的序列号


### type

```
int ApduSimIORequestInfo::type
```
**描述**

APDU指令类型，参考ETSI 102 221 [55]

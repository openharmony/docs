# OpenLogicalChannelResponse


## 概述

APDU打开逻辑通道响应信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [sw1](#sw1) | SIM卡状态字1，命令执行后SIM卡返回的响应  | 
| int [sw2](#sw2) | SIM卡状态字2，命令执行后SIM卡返回的响应  | 
| int [channelId](#channelid) | 打开的逻辑通道ID  | 
| String [response](#response) | 响应信息  | 


## 类成员变量说明


### channelId

```
int OpenLogicalChannelResponse::channelId
```
**描述**

打开的逻辑通道ID


### response

```
String OpenLogicalChannelResponse::response
```
**描述**

响应信息


### sw1

```
int OpenLogicalChannelResponse::sw1
```
**描述**

SIM卡状态字1，命令执行后SIM卡返回的响应


### sw2

```
int OpenLogicalChannelResponse::sw2
```
**描述**

SIM卡状态字2，命令执行后SIM卡返回的响应

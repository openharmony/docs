# DtmfInfo


## 概述

发送双音多频(DTMF)信息。

**起始版本：** 3.2

**相关模块：**[Ril](_ril_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [callId](#callid) | 呼叫 ID  | 
| int [onLength](#onlength) | DTMF音播放的时长  | 
| int [offLength](#offlength) | DTMF发送的间隔  | 
| int [stringLength](#stringlength) | DTMF字符串长度  | 
| String [dtmfKey](#dtmfkey) | DTMF关键字  | 


## 类成员变量说明


### callId

```
int DtmfInfo::callId
```
**描述**

呼叫 ID


### dtmfKey

```
String DtmfInfo::dtmfKey
```
**描述**

DTMF关键字


### offLength

```
int DtmfInfo::offLength
```
**描述**

DTMF发送的间隔


### onLength

```
int DtmfInfo::onLength
```
**描述**

DTMF音播放的时长


### stringLength

```
int DtmfInfo::stringLength
```
**描述**

DTMF字符串长度

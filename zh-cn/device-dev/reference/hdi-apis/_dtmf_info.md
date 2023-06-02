# DtmfInfo


## 概述

发送双音多频(DTMF)信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [callId](#callid) | int<br/>呼叫&nbsp;ID&nbsp; | 
| [onLength](#onlength) | int<br/>DTMF音播放的时长&nbsp; | 
| [offLength](#offlength) | int<br/>DTMF发送的间隔&nbsp; | 
| [stringLength](#stringlength) | int<br/>DTMF字符串长度&nbsp; | 
| [dtmfKey](#dtmfkey) | String<br/>DTMF关键字&nbsp; | 


## 类成员变量说明


### callId

  
```
int DtmfInfo::callId
```
**描述:**
呼叫 ID


### dtmfKey

  
```
String DtmfInfo::dtmfKey
```
**描述:**
DTMF关键字


### offLength

  
```
int DtmfInfo::offLength
```
**描述:**
DTMF发送的间隔


### onLength

  
```
int DtmfInfo::onLength
```
**描述:**
DTMF音播放的时长


### stringLength

  
```
int DtmfInfo::stringLength
```
**描述:**
DTMF字符串长度

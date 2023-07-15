# CallInfo


## 概述

通话状态信息。

**相关模块:**

[Ril](_ril.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [index](#index) | int<br/>呼叫标识&nbsp; | 
| [dir](#dir) | int<br/>呼叫方向，0表示主叫，1表示被叫&nbsp; | 
| [state](#state) | int<br/>呼叫状态 | 
| [mode](#mode) | int<br/>呼叫模式 | 
| [mpty](#mpty) | int<br/>多方通话状态 | 
| [voiceDomain](#voicedomain) | int<br/>语音电话的呼叫域 | 
| [callType](#calltype) | int<br/>通话类型，当前仅可为0，表示语音呼叫&nbsp; | 
| [type](#type) | int<br/>码地址类型 | 
| [number](#number) | String<br/>电话号码&nbsp; | 
| [alpha](#alpha) | String<br/>号码在电话本中对应的姓名&nbsp; | 


## 类成员变量说明


### alpha

  
```
String CallInfo::alpha
```
**描述:**
号码在电话本中对应的姓名


### callType

  
```
int CallInfo::callType
```
**描述:**
通话类型，当前仅可为0，表示语音呼叫


### dir

  
```
int CallInfo::dir
```
**描述:**
呼叫方向，0表示主叫，1表示被叫


### index

  
```
int CallInfo::index
```
**描述:**
呼叫标识


### mode

  
```
int CallInfo::mode
```
**描述:**
呼叫模式

- 0：语音呼叫

- 1：数据呼叫

- 2：传真 


### mpty

  
```
int CallInfo::mpty
```
**描述:**
多方通话状态

- 0：不在多方通话中

- 1：在多方通话中 


### number

  
```
String CallInfo::number
```
**描述:**
电话号码


### state

  
```
int CallInfo::state
```
**描述:**
呼叫状态

- 0：激活状态

- 1：呼叫保持状态

- 2：主叫,拨号状态

- 3：主叫,回铃音状态

- 4：被叫,来电状态

- 5：被叫,呼叫等待状态

- 6：挂断状态

- 7：正在挂断状态

- 8：空闲状态 


### type

  
```
int CallInfo::type
```
**描述:**
码地址类型

- 129：普通号码

- 145：国际号码 


### voiceDomain

  
```
int CallInfo::voiceDomain
```
**描述:**
语音电话的呼叫域

- 0：CS域电话

- 1：IP多媒体系统(IMS)域电话 

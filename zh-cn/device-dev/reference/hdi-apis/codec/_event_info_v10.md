# EventInfo


## 概述

定义事件上报信息。

**起始版本：** 3.2

**相关模块：**[Codec](_codec_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [appData](#appdata) | 设置回调时给入的上层实例。  | 
| unsigned int [data1](#data1) | Error类型,可能是portIndex或者其它数据。  | 
| unsigned int [data2](#data2) | 事件上报携带的数据2。  | 
| byte[] [eventData](#eventdata) | 事件上报携带的数据信息。  | 


## 类成员变量说明


### appData

```
long EventInfo::appData
```
**描述**

设置回调时给入的上层实例。


### data1

```
unsigned int EventInfo::data1
```
**描述**

Error类型,可能是portIndex或者其它数据。


### data2

```
unsigned int EventInfo::data2
```
**描述**

事件上报携带的数据2。


### eventData

```
byte [] EventInfo::eventData
```
**描述**

事件上报携带的数据信息。

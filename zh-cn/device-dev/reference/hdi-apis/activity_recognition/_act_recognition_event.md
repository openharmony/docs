# ActRecognitionEvent

## 概述

定义行为事件上报的数据结构。

**起始版本：** 3.2

**相关模块：**[HdiActivityRecognition](_hdi_activity_recognition.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [activity](#activity) | 行为类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。  | 
| int [eventType](#eventtype) | 事件类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。  | 
| long [timestamp](#timestamp) | 时间戳  | 
| int [confidence](#confidence) | 置信度，100为最可信，0为最不可信，-1为该行为不支持置信度的计算。  | 


## 类成员变量说明


### activity

```
int ActRecognitionEvent::activity
```
**描述**

行为类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。


### confidence

```
int ActRecognitionEvent::confidence
```
**描述**

置信度，100为最可信，0为最不可信，-1为该行为不支持置信度的计算。


### eventType

```
int ActRecognitionEvent::eventType
```
**描述**

事件类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。


### timestamp

```
long ActRecognitionEvent::timestamp
```
**描述**

时间戳

# ActRecognitionEvent


## 概述

定义行为事件上报的数据结构。

**Since:**

3.2

**相关模块:**

[HdiActivityRecognition](_hdi_activity_recognition.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [activity](#activity) | int<br/>行为类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。 | 
| [eventType](#eventtype) | int<br/>事件类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。 | 
| [timestamp](#timestamp) | long<br/>时间戳 | 
| [confidence](#confidence) | int<br/>置信度，100为最可信，0为最不可信，-1为该行为不支持置信度的计算。 | 


## 类成员变量说明


### activity

  
```
int ActRecognitionEvent::activity
```

**描述:**

行为类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。


### confidence

  
```
int ActRecognitionEvent::confidence
```

**描述:**

置信度，100为最可信，0为最不可信，-1为该行为不支持置信度的计算。


### eventType

  
```
int ActRecognitionEvent::eventType
```

**描述:**

事件类型，详见[ActRecognitionEventType](_hdi_activity_recognition.md#actrecognitioneventtype)。


### timestamp

  
```
long ActRecognitionEvent::timestamp
```

**描述:**

时间戳

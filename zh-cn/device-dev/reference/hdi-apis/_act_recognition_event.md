# ActRecognitionEvent


## **概述**

定义行为识别模块使用的数据类型。

**Since**:

3.2

**Version**:

1.0

**相关模块:**

[HdiActivityRecognition](activity_recognition.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [activity](#activity) | 行为类型 | 
| [eventType](#eventtype) | 事件类型 | 
| [timestamp](#timestamp) | 时间戳 | 
| [confidence](#confidence) | 置信度 | 


## **类成员变量说明**


### activity

  
```
int ActRecognitionEvent::activity
```

**描述：**

行为类型，详见[ActRecognitionEventType](activity_recognition.md#actrecognitioneventtype)。


### confidence

  
```
int ActRecognitionEvent::confidence
```

**描述：**

置信度，100为最可信，0为最不可信，-1为该行为不支持置信度的计算。


### eventType

  
```
int ActRecognitionEvent::eventType
```

**描述：**

事件类型，详见[ActRecognitionEventType](activity_recognition.md#actrecognitioneventtype)。


### timestamp

  
```
long ActRecognitionEvent::timestamp
```

**描述：**

时间戳。

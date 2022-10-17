# ActivityRecognitionTypes.idl


## **概述**

定义行为识别模块使用的数据类型。

**Since**:

3.2

**Version**:

1.0

**相关模块:**

[HdiActivityRecognition](activity_recognition.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ActRecognitionEvent](_act_recognition_event.md) | 定义行为事件上报的数据结构。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [ActRecognitionEventType](activity_recognition.md#actrecognitioneventtype)&nbsp;{&nbsp;ACT_RECOGNITION_EVENT_ENTER&nbsp;=&nbsp;0x01,&nbsp;ACT_RECOGNITION_EVENT_EXIT&nbsp;=&nbsp;0x02&nbsp;} | 枚举行为事件的类型。 | 
| [ActRecognitionPowerMode](activity_recognition.md#actrecognitionpowermode)&nbsp;{&nbsp;ACT_RECOGNITION_NORMAL_MODE&nbsp;=&nbsp;0,&nbsp;ACT_RECOGNITION_LOW_POWER_MODE&nbsp;=&nbsp;1&nbsp;} | 枚举功耗模式的类型。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.activity_recognition.v1_0 | 行为识别模块接口的包路径。 | 

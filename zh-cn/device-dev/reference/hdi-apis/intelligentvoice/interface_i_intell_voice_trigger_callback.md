# IIntellVoiceTriggerCallback


## 概述

IntelligentVoiceTrigger模块向上层服务提供了智能语音触发器回调接口。

上层服务开发人员可根据IntelligentVoiceTrigger模块提供的向上智能语音触发器回调接口实现通知上层识别事件等功能。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceTrigger](_intelligent_voice_trigger.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnRecognitionHdiEvent](#onrecognitionhdievent) ([in] struct [IntellVoiceRecognitionEvent](_intell_voice_recognition_event.md) event, [in] int cookie) | 识别事件上报  | 


## 成员函数说明


### OnRecognitionHdiEvent()

```
IIntellVoiceTriggerCallback::OnRecognitionHdiEvent ([in] struct IntellVoiceRecognitionEvent event, [in] int cookie )
```
**描述**

识别事件上报

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 智能语音识别事件信息，信息包含识别状态、智能语音触发器模型类型、智能语音触发器模型句柄，具体参考[IntellVoiceRecognitionEvent](_intell_voice_recognition_event.md)。  | 
| cookie | 上层调用者标识。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

# IntellVoiceTriggerTypes.idl


## 概述

IntelligentVoiceTrigger模块接口定义中使用的数据类型，包括智能语音触发器模型类型、识别状态、触发器适配器描述符、驱动属性、模型信息、识别事件信息等。

模块包路径：ohos.hdi.intelligent_voice.trigger.v1_0

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceTrigger](_intelligent_voice_trigger.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[IntellVoiceTriggerAdapterDsecriptor](_intell_voice_trigger_adapter_dsecriptor.md) | 智能语音触发器适配器描述符。 | 
| struct&nbsp;&nbsp;[IntellVoiceTriggerProperties](_intell_voice_trigger_properties.md) | 智能语音触发器属性。 | 
| struct&nbsp;&nbsp;[IntellVoiceTriggerModel](_intell_voice_trigger_model.md) | 智能语音触发器模型信息。 | 
| struct&nbsp;&nbsp;[IntellVoiceRecognitionEvent](_intell_voice_recognition_event.md) | 智能语音识别事件信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [IntellVoiceTriggerModelType](_intelligent_voice_trigger.md#intellvoicetriggermodeltype) { UNKNOWN = -1 , DEFAULT = 1 } | 智能语音触发器模型类型。 | 
| [RecognitionStatus](_intelligent_voice_trigger.md#recognitionstatus) { SUCCESS = 0 , ABORT = 1 , FAILURE = 2 } | 识别状态。 | 

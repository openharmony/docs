# IntelligentVoiceTrigger


## 概述

IntelligentVoiceTrigger模块向上层服务提供了统一接口。

上层服务开发人员可根据IntelligentVoiceTrigger模块提供的向上统一接口获取如下能力：触发器适配器加载卸载、智能语音触发器模型加载卸载、底层唤醒业务启动停止等。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IIntellVoiceTriggerAdapter.idl](_i_intell_voice_trigger_adapter_8idl.md) | IntelligentVoiceTrigger模块触发器适配器接口，包括获取智能语音触发器属性、加载卸载智能语音触发器模型、启动停止底层唤醒业务等。 | 
| [IIntellVoiceTriggerCallback.idl](_i_intell_voice_trigger_callback_8idl.md) | IntelligentVoiceTrigger模块触发器回调接口，包括识别事件上报等。 | 
| [IIntellVoiceTriggerManager.idl](_i_intell_voice_trigger_manager_8idl.md) | IntelligentVoiceTrigger模块触发器管理接口，包括触发器适配器加载、触发器适配器卸载等。 | 
| [IntellVoiceTriggerTypes.idl](_intell_voice_trigger_types_8idl.md) | IntelligentVoiceTrigger模块接口定义中使用的数据类型，包括智能语音触发器模型类型、识别状态、触发器适配器描述符、驱动属性、模型信息、识别事件信息等。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IIntellVoiceTriggerAdapter](interface_i_intell_voice_trigger_adapter.md) | IntelligentVoiceTrigger模块向上层服务提供了智能语音触发器适配器接口。 | 
| interface&nbsp;&nbsp;[IIntellVoiceTriggerCallback](interface_i_intell_voice_trigger_callback.md) | IntelligentVoiceTrigger模块向上层服务提供了智能语音触发器回调接口。 | 
| interface&nbsp;&nbsp;[IIntellVoiceTriggerManager](interface_i_intell_voice_trigger_manager.md) | IntelligentVoiceTrigger模块向上层服务提供了智能语音触发器管理接口。 | 
| struct&nbsp;&nbsp;[IntellVoiceTriggerAdapterDsecriptor](_intell_voice_trigger_adapter_dsecriptor.md) | 智能语音触发器适配器描述符。 | 
| struct&nbsp;&nbsp;[IntellVoiceTriggerProperties](_intell_voice_trigger_properties.md) | 智能语音触发器属性。 | 
| struct&nbsp;&nbsp;[IntellVoiceTriggerModel](_intell_voice_trigger_model.md) | 智能语音触发器模型信息。 | 
| struct&nbsp;&nbsp;[IntellVoiceRecognitionEvent](_intell_voice_recognition_event.md) | 智能语音识别事件信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [IntellVoiceTriggerModelType](#intellvoicetriggermodeltype) { UNKNOWN = -1 , DEFAULT = 1 } | 智能语音触发器模型类型。 | 
| [RecognitionStatus](#recognitionstatus) { SUCCESS = 0 , ABORT = 1 , FAILURE = 2 } | 识别状态。 | 


## 枚举类型说明


### IntellVoiceTriggerModelType

```
enum IntellVoiceTriggerModelType
```

**描述**


智能语音触发器模型类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| UNKNOWN | 未知模型 | 
| DEFAULT | 默认模型 | 


### RecognitionStatus

```
enum RecognitionStatus
```

**描述**


识别状态。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| SUCCESS | 识别成功 | 
| ABORT | 识别中止 | 
| FAILURE | 识别失败 | 

# IntellVoiceEngineTypes.idl


## 概述

IntelligentVoiceEngine模块接口定义中使用的数据类型，包括引擎适配器类型、数据类型、回调消息类型、回调消息错误码、引擎适配器描述、回调事件信息等。

模块包路径：ohos.hdi.intelligent_voice.engine.v1_0

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceEngine](_intelligent_voice_engine.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md) | 智能语音引擎适配器描述符。 | 
| struct&nbsp;&nbsp;[IntellVoiceEngineAdapterInfo](_intell_voice_engine_adapter_info.md) | 智能语音引擎适配器信息。 | 
| struct&nbsp;&nbsp;[StartInfo](_start_info.md) | 智能语音引擎启动信息。 | 
| struct&nbsp;&nbsp;[IntellVoiceEngineCallBackEvent](_intell_voice_engine_call_back_event.md) | 智能语音引擎回调事件信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [IntellVoiceEngineAdapterType](_intelligent_voice_engine.md#intellvoiceengineadaptertype) { ENROLL_ADAPTER_TYPE = 0 , WAKEUP_ADAPTER_TYPE = 1 , UPDATE_ADAPTER_TYPE = 2 , ADAPTER_TYPE_BUT } | 智能语音引擎适配器类型。 | 
| [ContentType](_intelligent_voice_engine.md#contenttype) { DSP_MODLE = 0 , CONTENT_TYPE_BUT } | 数据类型。 | 
| [IntellVoiceEngineMessageType](_intelligent_voice_engine.md#intellvoiceenginemessagetype) {<br/>INTELL_VOICE_ENGINE_MSG_NONE = 0 , INTELL_VOICE_ENGINE_MSG_INIT_DONE = 1 , INTELL_VOICE_ENGINE_MSG_ENROLL_COMPLETE = 2 , INTELL_VOICE_ENGINE_MSG_COMMIT_ENROLL_COMPLETE = 3 , INTELL_VOICE_ENGINE_MSG_RECOGNIZE_COMPLETE = 4<br/>} | 回调消息类型。 | 
| [IntellVoiceEngineErrors](_intelligent_voice_engine.md#intellvoiceengineerrors) {<br/>INTELL_VOICE_ENGINE_OK = 0 , INTELL_VOICE_ENGINE_ERROR_OFFSET = -100 , INTELL_VOICE_ENGINE_INVALID_PARAMS = -101 , INTELL_VOICE_ENGINE_INIT_FAILED = -102 , INTELL_VOICE_ENGINE_ENROLL_FAILED = -103 , INTELL_VOICE_ENGINE_COMMIT_ENROLL_FAILED = -104 , INTELL_VOICE_ENGINE_WAKEUP_FAILED = -105<br/>} | 回调消息错误码。 | 

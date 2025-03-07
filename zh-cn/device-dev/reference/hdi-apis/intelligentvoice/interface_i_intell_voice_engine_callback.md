# IIntellVoiceEngineCallback


## 概述

IntelligentVoiceEngine模块向上层服务提供了智能语音引擎回调接口。

上层服务开发人员可根据IntelligentVoiceEngine模块提供的向上智能语音引擎回调接口实现底层事件上报的功能。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceEngine](_intelligent_voice_engine.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnIntellVoiceHdiEvent](#onintellvoicehdievent) ([in] struct [IntellVoiceEngineCallBackEvent](_intell_voice_engine_call_back_event.md) event) | 引擎回调函数。  | 


## 成员函数说明


### OnIntellVoiceHdiEvent()

```
IIntellVoiceEngineCallback::OnIntellVoiceHdiEvent ([in] struct IntellVoiceEngineCallBackEvent event)
```
**描述**

引擎回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 智能语音引擎回调事件信息，具体参考[IntellVoiceEngineCallBackEvent](_intell_voice_engine_call_back_event.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

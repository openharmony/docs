# IntellVoiceEngineCallBackEvent


## 概述

智能语音引擎回调事件信息。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceEngine](_intelligent_voice_engine.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [IntellVoiceEngineMessageType](_intelligent_voice_engine.md#intellvoiceenginemessagetype) [msgId](#msgid) | 回调消息类型。  | 
| enum [IntellVoiceEngineErrors](_intelligent_voice_engine.md#intellvoiceengineerrors) [result](#result) | 回调消息结果。  | 
| String [info](#info) | 回调消息内容。  | 


## 类成员变量说明


### info

```
String IntellVoiceEngineCallBackEvent::info
```
**描述**

回调消息内容。


### msgId

```
enum IntellVoiceEngineMessageType IntellVoiceEngineCallBackEvent::msgId
```
**描述**

回调消息类型。


### result

```
enum IntellVoiceEngineErrors IntellVoiceEngineCallBackEvent::result
```
**描述**

回调消息结果。

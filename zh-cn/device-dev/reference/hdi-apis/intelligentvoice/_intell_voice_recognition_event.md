# IntellVoiceRecognitionEvent


## 概述

智能语音识别事件信息。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceTrigger](_intelligent_voice_trigger.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [RecognitionStatus](_intelligent_voice_trigger.md#recognitionstatus)[status](#status) | 识别状态  | 
| enum [IntellVoiceTriggerModelType](_intelligent_voice_trigger.md#intellvoicetriggermodeltype)[type](#type) | 智能语音触发器模型类型  | 
| int [modelHandle](#modelhandle) | 智能语音触发器模型句柄  | 


## 类成员变量说明


### modelHandle

```
int IntellVoiceRecognitionEvent::modelHandle
```
**描述**

智能语音触发器模型句柄


### status

```
enum RecognitionStatus IntellVoiceRecognitionEvent::status
```
**描述**

识别状态


### type

```
enum IntellVoiceTriggerModelType IntellVoiceRecognitionEvent::type
```
**描述**

智能语音触发器模型类型

# IIntellVoiceTriggerAdapter


## 概述

IntelligentVoiceTrigger模块向上层服务提供了智能语音触发器适配器接口。

上层服务开发人员可根据IntelligentVoiceTrigger模块提供的向上智能语音触发器适配器接口实现获取智能语音触发器属性、加载卸载智能语音触发器模型、启动停止底层唤醒业务等功能。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceTrigger](_intelligent_voice_trigger.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetProperties](#getproperties) ([out] struct [IntellVoiceTriggerProperties](_intell_voice_trigger_properties.md) properties) | 获取智能语音触发器属性。  | 
| [LoadModel](#loadmodel) ([in] struct [IntellVoiceTriggerModel](_intell_voice_trigger_model.md) model, [in] [IIntellVoiceTriggerCallback](interface_i_intell_voice_trigger_callback.md) triggerCallback, [in] int cookie, [out] int handle) | 加载模型。  | 
| [UnloadModel](#unloadmodel) ([in] int handle) | 卸载模型。  | 
| [Start](#start) ([in] int handle) | 启动底层唤醒算法。  | 
| [Stop](#stop) ([in] int handle) | 停止底层唤醒算法。  | 


## 成员函数说明


### GetProperties()

```
IIntellVoiceTriggerAdapter::GetProperties ([out] struct IntellVoiceTriggerProperties properties)
```
**描述**

获取智能语音触发器属性。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| properties | 智能语音触发器属性，信息包含触发器名称、描述、版本、支持最大模型数，具体参考[IntellVoiceTriggerProperties](_intell_voice_trigger_properties.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### LoadModel()

```
IIntellVoiceTriggerAdapter::LoadModel ([in] struct IntellVoiceTriggerModel model, [in] IIntellVoiceTriggerCallback triggerCallback, [in] int cookie, [out] int handle )
```
**描述**

加载模型。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 智能语音触发器模型信息，信息包含类型、标识、内容，具体参考[IntellVoiceTriggerModel](_intell_voice_trigger_model.md)。  | 
| triggerCallback | 触发器回调接口，具体参考[IIntellVoiceTriggerCallback](interface_i_intell_voice_trigger_callback.md)。  | 
| cookie | 上层调用者标识。  | 
| handle | 返回给上层的模型句柄。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Start()

```
IIntellVoiceTriggerAdapter::Start ([in] int handle)
```
**描述**

启动底层唤醒算法。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 智能语音触发器模型句柄。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Stop()

```
IIntellVoiceTriggerAdapter::Stop ([in] int handle)
```
**描述**

停止底层唤醒算法。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 智能语音触发器模型句柄。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### UnloadModel()

```
IIntellVoiceTriggerAdapter::UnloadModel ([in] int handle)
```
**描述**

卸载模型。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 智能语音触发器模型句柄。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

# IIntellVoiceEngineManager


## 概述

IntelligentVoiceEngine模块向上层服务提供了智能语音引擎管理接口。

上层服务开发人员可根据IntelligentVoiceEngine模块提供的向上智能语音引擎管理接口实现获取引擎适配器描述符、创建引擎适配器、释放引擎适配器等功能。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceEngine](_intelligent_voice_engine.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetAdapterDescriptors](#getadapterdescriptors) ([out] List&lt; struct [IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md) &gt; descs) | 上层服务查询智能语音引擎适配器描述符。  | 
| [CreateAdapter](#createadapter) ([in] struct [IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md) descriptor, [out] [IIntellVoiceEngineAdapter](interface_i_intell_voice_engine_adapter.md) adapter) | 上层服务创建智能语音引擎适配器。  | 
| [ReleaseAdapter](#releaseadapter) ([in] struct [IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md) descriptor) | 上层服务释放智能语音引擎适配器。  | 


## 成员函数说明


### CreateAdapter()

```
IIntellVoiceEngineManager::CreateAdapter ([in] struct IntellVoiceEngineAdapterDescriptor descriptor, [out] IIntellVoiceEngineAdapter adapter )
```
**描述**

上层服务创建智能语音引擎适配器。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descriptor | 智能语音引擎适配器描述符，信息包含智能语音引擎适配器类型，具体参考[IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md)。  | 
| adapter | 智能语音引擎适配器，具体参考[IIntellVoiceEngineAdapter](interface_i_intell_voice_engine_adapter.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetAdapterDescriptors()

```
IIntellVoiceEngineManager::GetAdapterDescriptors ([out] List< struct IntellVoiceEngineAdapterDescriptor > descs)
```
**描述**

上层服务查询智能语音引擎适配器描述符。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descs | 存放智能语音引擎适配器描述符的数组，信息包含智能语音引擎适配器类型，具体参考[IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### ReleaseAdapter()

```
IIntellVoiceEngineManager::ReleaseAdapter ([in] struct IntellVoiceEngineAdapterDescriptor descriptor)
```
**描述**

上层服务释放智能语音引擎适配器。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descriptor | 智能语音引擎适配器描述符，信息包含智能语音引擎适配器类型，具体参考[IntellVoiceEngineAdapterDescriptor](_intell_voice_engine_adapter_descriptor.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

# IIntellVoiceEngineAdapter


## 概述

IntelligentVoiceEngine模块向上层服务提供了智能语音引擎适配器接口。

上层服务开发人员可根据IntelligentVoiceEngine模块提供的向上智能语音引擎适配器接口实现设置回调、加载唤醒算法引擎、卸载唤醒算法引擎、设置唤醒算法参数、获取唤醒算法参数、启动唤醒算法引擎、停止唤醒算法引擎、读写数据等功能。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceEngine](_intelligent_voice_engine.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetCallback](#setcallback) ([in] [IIntellVoiceEngineCallback](interface_i_intell_voice_engine_callback.md) engineCallback) | 上层服务设置回调接口。  | 
| [Attach](#attach) ([in] struct [IntellVoiceEngineAdapterInfo](_intell_voice_engine_adapter_info.md) info) | 加载唤醒算法引擎。  | 
| [Detach](#detach) () | 卸载唤醒算法引擎。  | 
| [SetParameter](#setparameter) ([in] String keyValueList) | 设置唤醒算法参数。  | 
| [GetParameter](#getparameter) ([in] String keyList, [out] String valueList) | 获取唤醒算法参数。  | 
| [Start](#start) ([in] struct [StartInfo](_start_info.md) info) | 启动唤醒算法引擎。  | 
| [Stop](#stop) () | 停止唤醒算法引擎。  | 
| [WriteAudio](#writeaudio) ([in] List&lt; unsigned char &gt; buffer) | 写语音数据。  | 
| [Read](#read) ([in] enum [ContentType](_intelligent_voice_engine.md#contenttype) type, [out] Ashmem buffer) | 读数据。  | 


## 成员函数说明


### Attach()

```
IIntellVoiceEngineAdapter::Attach ([in] struct IntellVoiceEngineAdapterInfo info)
```
**描述**

加载唤醒算法引擎。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 智能语音唤醒算法引擎适配器信息，具体参考[IntellVoiceEngineAdapterInfo](_intell_voice_engine_adapter_info.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Detach()

```
IIntellVoiceEngineAdapter::Detach ()
```
**描述**

卸载唤醒算法引擎。

**起始版本：** 4.0

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetParameter()

```
IIntellVoiceEngineAdapter::GetParameter ([in] String keyList, [out] String valueList )
```
**描述**

获取唤醒算法参数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyList | 键列表，多个键之间通过分号分割，key和value的具体值由开发者自定义。  | 
| valueList | 返回值列表，多个返回值之间通过分号分割。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Read()

```
IIntellVoiceEngineAdapter::Read ([in] enum ContentType type, [out] Ashmem buffer )
```
**描述**

读数据。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 数据类型，具体参考[ContentType](_intelligent_voice_engine.md#contenttype)。  | 
| buffer | 数据内容。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetCallback()

```
IIntellVoiceEngineAdapter::SetCallback ([in] IIntellVoiceEngineCallback engineCallback)
```
**描述**

上层服务设置回调接口。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| engineCallback | 回调接口，具体参考[IIntellVoiceEngineCallback](interface_i_intell_voice_engine_callback.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetParameter()

```
IIntellVoiceEngineAdapter::SetParameter ([in] String keyValueList)
```
**描述**

设置唤醒算法参数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyValueList | 键值对列表，键值对的格式为"key=value"，多个键值对之间通过分号分割，key和value的具体值由开发者自定义。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Start()

```
IIntellVoiceEngineAdapter::Start ([in] struct StartInfo info)
```
**描述**

启动唤醒算法引擎。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 启动信息，具体参考[StartInfo](_start_info.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Stop()

```
IIntellVoiceEngineAdapter::Stop ()
```
**描述**

停止唤醒算法引擎。

**起始版本：** 4.0

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### WriteAudio()

```
IIntellVoiceEngineAdapter::WriteAudio ([in] List< unsigned char > buffer)
```
**描述**

写语音数据。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 语音数据，语音数据大小由开发者指定，默认是20ms语音数据。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

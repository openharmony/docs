# IIntellVoiceTriggerManager


## 概述

IntelligentVoiceTrigger模块向上层服务提供了智能语音触发器管理接口。

上层服务开发人员可根据IntelligentVoiceTrigger模块提供的向上智能语音触发器管理接口实现驱动适配器加载、驱动适配器卸载等功能。

**起始版本：** 4.0

**相关模块：**[IntelligentVoiceTrigger](_intelligent_voice_trigger.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [LoadAdapter](#loadadapter) ([in] struct [IntellVoiceTriggerAdapterDsecriptor](_intell_voice_trigger_adapter_dsecriptor.md) descriptor, [out] [IIntellVoiceTriggerAdapter](interface_i_intell_voice_trigger_adapter.md) adapter) | 加载一个触发器适配器。  | 
| [UnloadAdapter](#unloadadapter) ([in] struct [IntellVoiceTriggerAdapterDsecriptor](_intell_voice_trigger_adapter_dsecriptor.md) descriptor) | 卸载一个触发器适配器。  | 


## 成员函数说明


### LoadAdapter()

```
IIntellVoiceTriggerManager::LoadAdapter ([in] struct IntellVoiceTriggerAdapterDsecriptor descriptor, [out] IIntellVoiceTriggerAdapter adapter )
```
**描述**

加载一个触发器适配器。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descriptor | 智能语音触发器适配器描述符，信息包含适配器名称，具体参考[IntellVoiceTriggerAdapterDsecriptor](_intell_voice_trigger_adapter_dsecriptor.md)。  | 
| adapter | 智能语音触发器适配器，具体参考[IIntellVoiceTriggerAdapter](interface_i_intell_voice_trigger_adapter.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### UnloadAdapter()

```
IIntellVoiceTriggerManager::UnloadAdapter ([in] struct IntellVoiceTriggerAdapterDsecriptor descriptor)
```
**描述**

卸载一个触发器适配器。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descriptor | 智能语音触发器适配器描述符，信息包含适配器名称，具体参考[IntellVoiceTriggerAdapterDsecriptor](_intell_voice_trigger_adapter_dsecriptor.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

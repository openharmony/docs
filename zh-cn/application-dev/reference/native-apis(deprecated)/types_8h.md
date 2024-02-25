# types.h


## 概述

提供了MindSpore Lite支持的模型文件类型和设备类型。

**库：** libmindspore_lite_ndk.so

**起始版本：** 9

**相关模块：**[MindSpore](_mind_spore.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) | 模型文件的类型。 |
| [OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) | 设备类型信息，包含了目前支持的设备类型。 |
| [OH_AI_NNRTDeviceType](_mind_spore.md#oh_ai_nnrtdevicetype) | NNRT管理的硬件设备类型。 |
| [OH_AI_PerformanceMode](_mind_spore.md#oh_ai_performancemode) | NNRT硬件的工作性能模式。 |
| [OH_AI_Priority](_mind_spore.md#oh_ai_priority) | NNRT推理任务优先级。 |
| [OH_AI_OptimizationLevel](_mind_spore.md#oh_ai_optimizationlevel) | 训练优化等级。 |
| [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) | 量化类型信息。 |
| [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) | NNRT设备信息描述，包含设备ID，设备名称等信息。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) {<br/>OH_AI_MODELTYPE_MINDIR = 0,<br/>OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF<br/>} | 模型文件的类型。 |
| [OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) {<br/>OH_AI_DEVICETYPE_CPU = 0,<br/>OH_AI_DEVICETYPE_GPU,<br/>OH_AI_DEVICETYPE_KIRIN_NPU,<br/>OH_AI_DEVICETYPE_NNRT = 60,<br/>OH_AI_DEVICETYPE_INVALID = 100<br/>} | 设备类型信息，包含了目前支持的设备类型。 |
| [OH_AI_NNRTDeviceType](_mind_spore.md#oh_ai_nnrtdevicetype) {<br/>OH_AI_NNRTDEVICE_OTHERS = 0,<br/>OH_AI_NNRTDEVICE_CPU = 1,<br/>OH_AI_NNRTDEVICE_GPU = 2,<br/>OH_AI_NNRTDEVICE_ACCELERATOR = 3<br/>} | NNRT管理的硬件设备类型。 |
| [OH_AI_PerformanceMode](_mind_spore.md#oh_ai_performancemode) {<br/>OH_AI_PERFORMANCE_NONE = 0,<br/>OH_AI_PERFORMANCE_LOW = 1,<br/>OH_AI_PERFORMANCE_MEDIUM = 2,<br/>OH_AI_PERFORMANCE_HIGH = 3,<br/>OH_AI_PERFORMANCE_EXTREME = 4<br/>} | NNRT硬件的工作性能模式。 |
| [OH_AI_Priority](_mind_spore.md#oh_ai_priority) {<br/>OH_AI_PRIORITY_NONE = 0,<br/>OH_AI_PRIORITY_LOW = 1,<br/>OH_AI_PRIORITY_MEDIUM = 2,<br/>OH_AI_PRIORITY_HIGH = 3<br/>} | NNRT推理任务优先级。 |
| [OH_AI_OptimizationLevel](_mind_spore.md#oh_ai_optimizationlevel) {<br/>OH_AI_KO0 = 0,<br/>OH_AI_KO2 = 2,<br/>OH_AI_KO3 = 3,<br/>OH_AI_KAUTO = 4,<br/>OH_AI_KOPTIMIZATIONTYPE = 0xFFFFFFFF<br/>} | 训练优化等级。 |
| [OH_AI_QuantizationType](_mind_spore.md#oh_ai_quantizationtype) {<br/>OH_AI_NO_QUANT = 0,<br/>OH_AI_WEIGHT_QUANT = 1,<br/>OH_AI_FULL_QUANT = 2,<br/>OH_AI_UNKNOWN_QUANT_TYPE = 0xFFFFFFFF } | 量化类型信息。 |

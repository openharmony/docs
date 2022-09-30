# types.h


## 概述

提供了MindSpore Lite支持的模型文件类型和设备类型。

**自从：**

9

**相关模块：**

[MindSpore](_mind_spore.md)


## 汇总


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) | 模型文件的类型。 |
| [OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) | 设备类型信息，包含了目前支持的设备类型。 |


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [OH_AI_ModelType](_mind_spore.md#oh_ai_modeltype) { <br/>OH_AI_MODELTYPE_MINDIR = 0, <br/>OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF } | 模型文件的类型。 |
| [OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) { <br/>OH_AI_DEVICETYPE_CPU = 0,<br/>OH_AI_DEVICETYPE_KIRIN_NPU, <br/>OH_AI_DEVICETYPE_INVALID = 100 } | 设备类型信息，包含了目前支持的设备类型。 |

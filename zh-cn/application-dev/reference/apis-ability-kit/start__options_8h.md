# start_options.h


## 概述

声明StartOptions结构体以及结构体相关函数。

**引用文件**：<AbilityKit/ability_runtime/start_options.h>

**库**：libability_runtime.so

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**起始版本**：16

**相关模块**：[AbilityRuntime](_ability_runtime.md)

## 汇总

### 文件

| 名称                                                | 描述                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ |
| [start_options.h](start__options_8h.md) | 声明StartOptions结构体。<br/>**引用文件**：<AbilityKit/ability_runtime/start_options.h><br/>**库**：libability_runtime.so |

### 结构体

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions)  | StartOptions数据结构。 |

### 函数

| 名称                                                         | 描述                         |
| ------------------------------------------------------------ | ---------------------------- |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_SetStartOptionsStartVisibility](_ability_runtime.md#oh_abilityruntime_setstartoptionsstartability)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](_ability_runtime.md#abilityruntime_startvisibility) startVisibility) | 设置StartOptions结构体的startVisibility。 |
| [AbilityRuntime_ErrorCode](_ability_runtime.md#abilityruntime_errorcode) [OH_AbilityRuntime_GetStartOptionsStartVisibility](_ability_runtime.md#oh_abilityruntime_getstartoptionsstartability)([AbilityRuntime_StartOptions](_ability_runtime.md#abilityruntime_startoptions) *startOptions, [AbilityRuntime_StartVisibility](_ability_runtime.md#abilityruntime_startvisibility) &startVisibility) | 获取StartOptions结构体的startVisibility。 |
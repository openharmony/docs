# @ohos.application.AbilityConstant (AbilityConstant)

AbilityConstant是启动参数的接口。

AbilityConstant提供启动参数的接口的能力，包括设置初次开始原因的类型、上次退出原因的类型、继续结果的类型。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.AbilityConstant](js-apis-app-ability-abilityConstant.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import AbilityConstant from '@ohos.application.AbilityConstant';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| launchReason | LaunchReason| 是 | 是 | 指示启动原因。 | 
| lastExitReason | LastExitReason | 是 | 是 | 表示最后退出原因。 | 

## AbilityConstant.LaunchReason

初次开始原因的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知的状态。 |
| START_ABILITY          | 1    | 启动能力。 |
| CALL | 2    | 呼叫。 |
| CONTINUATION           | 3    | 继续。 |
| APP_RECOVERY           | 4    | 状态恢复。 |


## AbilityConstant.LastExitReason

上次退出原因的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知的状态。 |
| ABILITY_NOT_RESPONDING          | 1    | 能力没有反应 |
| NORMAL | 2    | 正常的状态。 |


## AbilityConstant.OnContinueResult 

继续结果的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | 同意。 |
| REJECT           | 1    | 拒绝。 |
| MISMATCH  | 2    | 不匹配。|

## AbilityConstant.WindowMode

启动Ability时的窗口模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                        | 值 | 说明                 |
| ---                         | --- | ---                  |
| WINDOW_MODE_UNDEFINED       | 0   | 未定义窗口模式。       |
| WINDOW_MODE_FULLSCREEN      | 1   | 全屏模式。            |
| WINDOW_MODE_SPLIT_PRIMARY   | 100 | 分屏多窗口主要模式。   |
| WINDOW_MODE_SPLIT_SECONDARY | 101 | 分屏多窗口次要模式。   |
| WINDOW_MODE_FLOATING        | 102 | 自由悬浮形式窗口模式。 |

## AbilityConstant.MemoryLevel

内存级别的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                         | 值 | 说明                |
| ---                         | --- | ---                  |
| MEMORY_LEVEL_MODERATE       | 0   | 内存占用适中。       |
| MEMORY_LEVEL_LOW            | 1   | 内存占用低。            |
| MEMORY_LEVEL_CRITICAL       | 2   | 内存占用高。   |

## AbilityConstant.OnSaveResult

保存应用数据的结果类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALL_AGREE           | 0    | 同意保存状态。 |
| CONTINUATION_REJECT           | 1    | 拒绝迁移保存状态。 |
| CONTINUATION_MISMATCH  | 2    | 迁移不匹配。|
| RECOVERY_AGREE           | 3    | 同意恢复保存状态。 |
| RECOVERY_REJECT  | 4    | 拒绝恢复保存状态。|
| ALL_REJECT  | 5    | 拒绝保存状态。|

## AbilityConstant.StateType

保存应用数据场景原因类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| CONTINUATION           | 0    | 迁移保存状态。 |
| APP_RECOVERY           | 1    | 应用恢复保存状态。 |

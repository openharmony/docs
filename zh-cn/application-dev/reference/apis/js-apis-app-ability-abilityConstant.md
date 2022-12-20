# @ohos.app.ability.AbilityConstant (AbilityConstant)

AbilityConstant提供Ability相关的枚举，包括设置初次启动原因、上次退出原因、迁移结果、窗口类型等。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| launchReason | [LaunchReason](#abilityconstantlaunchreason)| 是 | 是 | 枚举类型，表示启动原因。 |
| lastExitReason | [LastExitReason](#abilityconstantlastexitreason) | 是 | 是 | 枚举类型，表示最后退出原因。 |

## AbilityConstant.LaunchReason

初次启动原因，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate)方法根据launchParam.launchReason的不同类型执行相应操作。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知原因。 |
| START_ABILITY          | 1    | 通过[startAbility](js-apis-ability-context.md#abilitycontextstartability)接口启动ability。 |
| CALL | 2    | 通过[startAbilityByCall](js-apis-ability-context.md#abilitycontextstartabilitybycall)接口启动ability。 |
| CONTINUATION           | 3    | 跨端设备迁移启动ability。 |
| APP_RECOVERY           | 4    | 设置应用恢复后，应用故障时自动恢复启动ability。 |


## AbilityConstant.LastExitReason

上次退出原因，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate)方法根据launchParam.lastExitReason的不同类型执行相应操作。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知原因。 |
| ABILITY_NOT_RESPONDING          | 1    | ability未响应。 |
| NORMAL | 2    | 正常退出。 |


## AbilityConstant.OnContinueResult 

迁移结果，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onContinue(wantParam)](js-apis-app-ability-uiAbility.md#uiabilityoncontinue)方法进完成相应的返回。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | 同意。 |
| REJECT           | 1    | 拒绝。 |
| MISMATCH  | 2    | 不匹配。|

## AbilityConstant.WindowMode

启动Ability时的窗口模式，该类型为枚举，可配合startAbility使用指定启动Ability的窗口模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                        | 值 | 说明                 |
| ---                         | --- | ---                  |
| WINDOW_MODE_UNDEFINED       | 0   | 未定义窗口模式。       |
| WINDOW_MODE_FULLSCREEN      | 1   | 全屏模式。            |
| WINDOW_MODE_SPLIT_PRIMARY   | 100 | 分屏多窗口主要模式。   |
| WINDOW_MODE_SPLIT_SECONDARY | 101 | 分屏多窗口次要模式。   |
| WINDOW_MODE_FLOATING        | 102 | 自由悬浮形式窗口模式。 |

## AbilityConstant.MemoryLevel

内存级别，该类型为枚举，可配合[Ability](js-apis-app-ability-ability.md)的[onMemoryLevel(level)](js-apis-app-ability-ability.md#abilityonmemorylevel)方法根据level执行不同内存级别的相应操作。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                         | 值 | 说明                |
| ---                         | --- | ---                  |
| MEMORY_LEVEL_MODERATE       | 0   | 内存占用适中。       |
| MEMORY_LEVEL_LOW            | 1   | 内存占用低。            |
| MEMORY_LEVEL_CRITICAL       | 2   | 内存占用高。   |

## AbilityConstant.OnSaveResult

保存应用数据的结果，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate)方法完成相应的返回。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALL_AGREE           | 0    | 总是同意保存状态。 |
| CONTINUATION_REJECT           | 1    | 拒绝迁移保存状态。 |
| CONTINUATION_MISMATCH  | 2    | 迁移不匹配。|
| RECOVERY_AGREE           | 3    | 同意恢复保存状态。 |
| RECOVERY_REJECT  | 4    | 拒绝恢复保存状态。|
| ALL_REJECT  | 5    | 总是拒绝保存状态。|

## AbilityConstant.StateType

保存应用数据场景原因，该类型为枚举，可配合[Ability](js-apis-app-ability-uiAbility.md)的[onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate)方法根据reason的不同类型执行相应操作。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| CONTINUATION           | 0    | 迁移保存状态。 |
| APP_RECOVERY           | 1    | 应用恢复保存状态。 |

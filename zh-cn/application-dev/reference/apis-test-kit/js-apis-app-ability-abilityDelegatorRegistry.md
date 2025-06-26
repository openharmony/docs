# @ohos.app.ability.abilityDelegatorRegistry (AbilityDelegatorRegistry)

AbilityDelegatorRegistry是自动化测试框架使用指南模块，该模块用于获取[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)和[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象，其中[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象提供添加用于监视指定ability的生命周期状态更改的[AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor)对象的能力，[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象提供获取当前测试参数的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在<!--RP1-->[自动化测试框架arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->中使用。

## 导入模块

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## AbilityLifecycleState

Ability生命周期状态，该类型为枚举，可配合[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)的[getAbilityState(ability)](js-apis-inner-application-abilityDelegator.md#getabilitystate9)方法返回不同ability生命周期。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力** ：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称          | 值   | 说明                        |
| ------------- | ---- | --------------------------- |
| UNINITIALIZED | 0    | 表示Ability处于无效状态。   |
| CREATE        | 1    | 表示Ability处于已创建状态。 |
| FOREGROUND    | 2    | 表示Ability处于前台状态。   |
| BACKGROUND    | 3    | 表示Ability处于后台状态。   |
| DESTROY       | 4    | 表示Ability处于已销毁状态。 |

## abilityDelegatorRegistry.getAbilityDelegator

getAbilityDelegator(): AbilityDelegator

获取应用程序的[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象，该对象能够使用调度测试框架的相关功能。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegator](js-apis-inner-application-abilityDelegator.md) | [AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象。可以用来调度测试框架相关功能。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { Want } from '@kit.AbilityKit';

let abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

abilityDelegator.startAbility(want, (err) => {
  if (err) {
    console.error(`Failed start ability, error: ${JSON.stringify(err)}`);
  } else {
    console.log('Success start ability.');
  }
});
```

## abilityDelegatorRegistry.getArguments

getArguments(): AbilityDelegatorArgs

获取单元测试参数[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) | [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象。可以用来获取测试参数。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let args = abilityDelegatorRegistry.getArguments();
console.info(`getArguments bundleName: ${args.bundleName}`);
console.info(`getArguments parameters: ${JSON.stringify(args.parameters)}`);
console.info(`getArguments testCaseNames: ${args.testCaseNames}`);
console.info(`getArguments testRunnerClassName: ${args.testRunnerClassName}`);
```

## AbilityDelegator

type AbilityDelegator = _AbilityDelegator

AbilityDelegator模块。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityDelegator](js-apis-inner-application-abilityDelegator.md) | AbilityDelegator模块。 |

## AbilityDelegatorArgs

type AbilityDelegatorArgs = _AbilityDelegatorArgs

AbilityDelegatorArgs模块。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) | AbilityDelegatorArgs模块。 |

## AbilityMonitor

type AbilityMonitor = _AbilityMonitor

AbilityMonitor模块。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md) | AbilityMonitor模块。 |

## ShellCmdResult

type ShellCmdResult = _ShellCmdResult

ShellCmdResult模块。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_ShellCmdResult](js-apis-inner-application-shellCmdResult.md) | ShellCmdResult模块。 |

## AbilityStageMonitor<sup>14+</sup>

type AbilityStageMonitor = _AbilityStageMonitor

AbilityStageMonitor模块。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | AbilityStageMonitor模块。 |

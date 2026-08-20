# @ohos.app.ability.abilityDelegatorRegistry (AbilityDelegatorRegistry)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @li-weifeng2024; @xuzhihao666-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

AbilityDelegatorRegistry是自动化测试框架的注册模块，用于获取[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)和[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象。通过该模块，开发者可以利用[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象添加[AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)对象，实现对指定Ability生命周期状态变化的监视；同时，借助[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象便捷地读取当前运行的测试参数。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口仅可在<!--RP1-->[单元测试框架](../../application-test/unittest-guidelines.md)<!--RP1End-->中使用。

## 导入模块

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## AbilityLifecycleState

Ability生命周期状态，可配合[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)的[getAbilityState](js-apis-inner-application-abilityDelegator.md#getabilitystate)方法返回对应Ability的生命周期状态。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 名称          | 值   | 说明                        |
| ------------- | ---- | --------------------------- |
| UNINITIALIZED | 0    | 表示Ability处于无效状态。   |
| CREATE        | 1    | 表示Ability处于已创建状态。 |
| FOREGROUND    | 2    | 表示Ability处于前台状态。   |
| BACKGROUND    | 3    | 表示Ability处于后台状态。   |
| DESTROY       | 4    | 表示Ability处于已销毁状态。 |

## abilityDelegatorRegistry.getAbilityDelegator

getAbilityDelegator(): AbilityDelegator

获取应用程序的[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象，该对象可用于调度测试框架，执行相关测试功能。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegator](js-apis-inner-application-abilityDelegator.md) | 用来调度测试框架相关功能。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 获取应用程序的AbilityDelegator对象
let abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
// 构造Want参数，指定目标Ability
let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

// 启动指定Ability
abilityDelegator.startAbility(want, (err: BusinessError) => {
  if (err) {
    console.error(`Failed start ability. code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Success start ability.');
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

// 获取单元测试参数AbilityDelegatorArgs对象
let args = abilityDelegatorRegistry.getArguments();
// 打印测试参数信息
console.info(`getArguments bundleName: ${args.bundleName}`);
console.info(`getArguments parameters: ${JSON.stringify(args.parameters)}`);
console.info(`getArguments testCaseNames: ${args.testCaseNames}`);
console.info(`getArguments testRunnerClassName: ${args.testRunnerClassName}`);
```

## AbilityDelegator

type AbilityDelegator = _AbilityDelegator

提供通过[AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md)实例来监听和管理[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)生命周期变化的能力。例如获取UIAbility当前状态（如是否已创建/是否在前台等）、查询当前获焦的UIAbility、等待UIAbility进入某个生命周期节点（如等待UIAbility进入onForeground）、启动指定UIAbility、设置超时机制等功能。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityDelegator](js-apis-inner-application-abilityDelegator.md) | AbilityDelegator模块。 |

## AbilityDelegatorArgs

type AbilityDelegatorArgs = _AbilityDelegatorArgs

提供在应用程序执行测试用例期间，获取测试用例参数AbilityDelegatorArgs对象的能力。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) | AbilityDelegatorArgs模块。 |

## AbilityMonitor

type AbilityMonitor = _AbilityMonitor

作为[addAbilityMonitor](../apis-test-kit/js-apis-inner-application-abilityDelegator.md#addabilitymonitor)的入参，用于监听指定UIAbility的生命周期变化。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityMonitor](../apis-ability-kit/js-apis-inner-application-abilityMonitor.md) | AbilityMonitor模块。 |

## ShellCmdResult

type ShellCmdResult = _ShellCmdResult

提供获取Shell命令执行结果的能力，可用于在自动化测试中执行Shell命令并获取命令的返回结果，包括命令的返回码和标准输出内容等信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_ShellCmdResult](js-apis-inner-application-shellCmdResult.md) | ShellCmdResult模块。 |

## AbilityStageMonitor<sup>14+</sup>

type AbilityStageMonitor = _AbilityStageMonitor

提供监听指定[AbilityStage](../apis-ability-kit/js-apis-app-ability-abilityStage.md)对象的能力。开发者可以将AbilityStageMonitor作为[abilityDelegator.waitAbilityStageMonitor](../apis-test-kit/js-apis-inner-application-abilityDelegator.md#waitabilitystagemonitor)的入参来注册监听。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityStageMonitor](../apis-ability-kit/js-apis-inner-application-abilityStageMonitor.md) | AbilityStageMonitor模块。 |

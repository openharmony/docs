# @ohos.app.ability.abilityDelegatorRegistry (AbilityDelegatorRegistry)

AbilityDelegatorRegistry模块提供用于存储已注册的[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)和[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象的全局寄存器的能力，包括获取应用程序的[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象、获取单元测试参数[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry'
```

## AbilityLifecycleState

Ability生命周期状态，该类型为枚举，可配合[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)的[getAbilityState(ability)](js-apis-inner-application-abilityDelegator.md#getabilitystate9)方法返回不同ability生命周期。

**系统能力** ：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称          | 值   | 说明                        |
| ------------- | ---- | --------------------------- |
| UNINITIALIZED | 0    | 表示无效状态。              |
| CREATE        | 1    | 表示Ability处于已创建状态。 |
| FOREGROUND    | 2    | 表示Ability处于前台状态。   |
| BACKGROUND    | 3    | 表示Ability处于后台状态。   |
| DESTROY       | 4    | 表示Ability处于已销毁状态。 |

## AbilityDelegatorRegistry.getAbilityDelegator

getAbilityDelegator(): [AbilityDelegator](js-apis-inner-application-abilityDelegator.md)

获取应用程序的[AbilityDelegator](js-apis-inner-application-abilityDelegator.md)对象。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegator](js-apis-inner-application-abilityDelegator.md#AbilityDelegator) | [AbilityDelegator](js-apis-inner-application-abilityDelegator.md#AbilityDelegator)对象。可以用来调度测试框架相关功能。 |

**示例：**

```ts
var abilityDelegator;
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();

let want = {
    bundleName: "com.ohos.example",
    abilityName: "MainAbility"
}
abilityDelegator.startAbility(want, (err, data)=>{
    console.log("startAbility callback err: " + JSON.stringify(err) + " data: " + JSON.stringify(data));
})
```

## AbilityDelegatorRegistry.getArguments

getArguments(): [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)

获取单元测试参数[AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) | [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md)对象。可以用来获取测试参数。 |

**示例：**

```ts
var args = AbilityDelegatorRegistry.getArguments();
console.info("getArguments bundleName:" + args.bundleName);
console.info("getArguments testCaseNames:" + args.testCaseNames);
console.info("getArguments testRunnerClassName:" + args.testRunnerClassName);
```

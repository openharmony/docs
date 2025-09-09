# @ohos.app.ability.Ability (Ability基类)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

Ability类是应用生命周期调度的基本单元，是[UIAbility](js-apis-app-ability-uiAbility.md)和[ExtensionAbility](js-apis-app-ability-extensionAbility.md)的基类，提供系统配置更新回调和系统内存级别变化回调能力。该基类不支持开发者直接继承，开发者应根据具体的业务场景选择使用[UIAbility](js-apis-app-ability-uiAbility.md)或[ExtensionAbility](js-apis-app-ability-extensionAbility.md)，相关指南参见[Ability Kit简介](../../application-models/abilitykit-overview.md)。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { Ability } from '@kit.AbilityKit';
```

## Ability的继承关系说明

Ability基类及其子类的继承关系如下图所示。

> **说明：**
>
> 部分ExtensionAbility组件（例如[FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md)、[InputMethodExtensionAbility](../apis-ime-kit/js-apis-inputmethod-extension-ability.md)等）与下图中的ExtensionAbility基类不存在继承关系，均未在图中列出。

![ability-inheritance](../figures/image-ability-ability-inheritance.png)

## Ability.onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void

当系统环境变量发生变化时，系统会触发该回调。开发者可以重写该回调实现对系统环境变量变化时的响应，例如当系统语言类型发生变化时，应用可以在回调中进行定制化的处理等。

> **说明：**
>
> 该回调方法在实际触发时存在一定限制。如果开发者通过[setLanguage](../apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetlanguage11)接口设置应用的语言，即便系统语言发生变化，系统也不再触发onConfigurationUpdate回调。详见[使用场景](../../application-models/subscribe-system-environment-variable-changes.md#使用场景)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](js-apis-app-ability-configuration.md) | 是 | 表示更新后的配置信息。 |

**示例：**

```ts
// Ability是顶层基类，不支持开发者直接继承。故以派生类UIAbility举例说明。
import { UIAbility, Configuration } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onConfigurationUpdate(config: Configuration) {
    console.info(`onConfigurationUpdate, config: ${JSON.stringify(config)}`);
  }
}
```

## Ability.onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void

当整机可用内存变化到指定程度时，系统会触发该回调。开发者可以重写该回调实现对内存级别变化的响应，例如释放缓存数据等。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#memorylevel) | 是 | 整机可用内存变化到的级别。<br>**说明：**<br>不同产品的触发条件可能存在差异。以12G内存的标准设备为例：<br>- 当整机可用内存下降至1700M~1800M时，会触发MEMORY_LEVEL_MODERATE类型(整机可用内存适中)的onMemoryLevel回调。<br>- 当整机可用内存下降至1600M~1700M时，会触发MEMORY_LEVEL_LOW类型(整机可用内存低)的onMemoryLevel回调。<br>- 当整机可用内存下降至1600M以下时，会触发MEMORY_LEVEL_CRITICAL类型(整机可用内存极低)的onMemoryLevel回调。|

**示例：**

```ts
// Ability是顶层基类，不支持开发者直接继承。故以派生类UIAbility举例说明。
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  onMemoryLevel(level: AbilityConstant.MemoryLevel) {
    console.info(`onMemoryLevel, level: ${JSON.stringify(level)}`);
  }
}
```

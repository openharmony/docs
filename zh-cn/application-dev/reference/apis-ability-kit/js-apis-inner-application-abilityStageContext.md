# AbilityStageContext

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

AbilityStageContext是AbilityStage的上下文环境，继承自[Context](js-apis-inner-application-context.md)。

AbilityStageContext提供允许访问特定于abilityStage的资源的能力，包括获取AbilityStage对应的ModuleInfo对象、环境变化对象。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | 否 | 否 | AbilityStage对应的ModuleInfo对象。 |
| config | [Configuration](js-apis-app-ability-configuration.md) | 否 | 否 | 环境变量。 |

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    let abilityStageContext = this.context;
    // 获取当前模块名
    let name = abilityStageContext.currentHapModuleInfo.name;
    // 获取当前模块语言
    let language = abilityStageContext.config.language;
  }
}
```
# AbilityStageContext

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

## 使用说明

通过AbilityStage实例来获取。

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    let abilityStageContext = this.context;
  }
}
```

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | 是 | 否 | AbilityStage对应的ModuleInfo对象。 |
| config | [Configuration](js-apis-app-ability-configuration.md) | 是 | 否 | 环境变化对象。 |

# AbilityStageContext

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

AbilityStageContext是AbilityStage的上下文环境，继承自[Context](js-apis-inner-application-context.md)。AbilityStageContext提供访问特定于AbilityStage的资源的能力，适用于需要在AbilityStage生命周期中访问模块信息和环境配置的场景，可帮助开发者快速获取模块信息和环境配置。

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
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | 否 | 否 | AbilityStage对应的HapModuleInfo对象，可用来获取当前模块的名称、路径等信息。 |
| config | [Configuration](js-apis-app-ability-configuration.md) | 否 | 否 | 环境配置对象。 |
| launchElement<sup>24+</sup> | [ElementName](js-apis-bundleManager-elementName.md) | 否 | 是 | 创建AbilityStage时的元素名称信息。<br>**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。 |

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    // 获取AbilityStageContext上下文
    let abilityStageContext = this.context;
    // 获取当前模块名
    let name = abilityStageContext.currentHapModuleInfo.name;
    // 获取当前模块语言
    let language = abilityStageContext.config.language;
    // 获取创建AbilityStage时的ElementName
    let elementName = abilityStageContext.launchElement;
    if (elementName) {
      hilog.info(0x0000, 'testTag', 'bundleName: %{public}s', elementName.bundleName);
      hilog.info(0x0000, 'testTag', 'moduleName: %{public}s', elementName.moduleName);
      hilog.info(0x0000, 'testTag', 'abilityName: %{public}s', elementName.abilityName);
    }
  }
}
```
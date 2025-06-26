# EmbeddableUIAbilityContext

EmbeddableUIAbilityContext是需要保存状态的[EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md)所对应的context，继承自[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)。

> **说明：**
>
>  - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口需要在主线程中使用，不要在Worker、TaskPool等子线程中使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## EmbeddableUIAbilityContext 

EmbeddableUIAbilityContext是需要保存状态的[EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md)所对应的context，继承自[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)。

EmbeddableUIAbilityContext提供EmbeddableUIAbility的相关配置信息以及操作EmbeddableUIAbility和ServiceExtensionAbility的方法，如启动EmbeddableUIAbility，停止当前EmbeddableUIAbilityContext所属的EmbeddableUIAbility，启动、停止、连接、断开连接ServiceExtensionAbility等。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

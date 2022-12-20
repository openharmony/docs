# @ohos.app.ability.ExtensionAbility (扩展能力基类)

ExtensionAbility是特定场景扩展能力的基类，提供系统配置更新回调和系统内存调整回调。。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import ExtensionAbility from '@ohos.app.ability.ExtensionAbility';
```

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

  ```ts
  class MyExtensionAbility extends ExtensionAbility {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, config:' + JSON.stringify(config));
      }

      onMemoryLevel(level) {
          console.log('onMemoryLevel, level:' + JSON.stringify(level));
      }
  }
  ```


# AbilityStageMonitor

提供用于匹配满足指定条件的受监视的AbilityStage对象的方法。最近匹配的AbilityStage对象将保存在AbilityStageMonitor对象中。 

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明  |
| ---- | ---- | ---- | ---- | ---- |
| moduleName | string | 否   | 否   | 要监视的abilityStage的模块名。 |
| srcEntrance | string | 否   | 否   | 要监视的abilityStage的源路径。 |

**示例：**
```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor({
  moduleName: 'feature_as1',
  srcEntrance: './ets/Application/MyAbilityStage.ts',
}, (error, data) => {
  if (error) {
    console.error(`waitAbilityStageMonitor fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`waitAbilityStageMonitor success, data: ${JSON.stringify(data)}`);
  }
});
```
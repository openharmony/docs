# AbilityStageMonitor

提供用于匹配满足指定条件的受监视的AbilityStage对象的方法。最近匹配的AbilityStage对象将保存在AbilityStageMonitor对象中。  

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                                                         | 类型     | 可读 | 可写 | 说明                                                         |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| moduleName<sup>9+</sup>                                                 | string   | 是   | 是   | 要监视的abilityStage的模块名。 |
| srcEntrance<sup>9+</sup> | string | 是   | 是   | 要监视的abilityStage的源路径。 |

**示例：**
```ts
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'

let monitor = {
    moduleName: "feature_as1",
    srcEntrance: "./ets/Application/MyAbilityStage.ts",
};

let abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor(monitor, (error, data) => {
    console.info("stageMonitor waitAbilityStageMonitor, abilityStage = " + JSON.stringify(data));
});
```
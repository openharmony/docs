# AbilityStageMonitor

The **AbilityStageMonitor** module provides conditions for matching **AbilityStage** instances. The most recently matched **AbilityStage** instance is saved in an **AbilityStageMonitor** instance.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                                                        | Type    | Readable| Writable| Description                                                        |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| moduleName                                                 | string   | Yes  | Yes  | Module name of the **AbilityStage** instance.|
| srcEntrance | string | Yes  | Yes  | Source path of the **AbilityStage** instance.|

**Example**
```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';

let monitor = {
    moduleName: 'feature_as1',
    srcEntrance: './ets/Application/MyAbilityStage.ts',
};

let abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor(monitor, (error, data) => {
    if (error) {
        console.error('waitAbilityStageMonitor fail, error: ${JSON.stringify(error)}');
    } else {
        console.log('waitAbilityStageMonitor success, data: ${JSON.stringify(data)}');
    }
});
```

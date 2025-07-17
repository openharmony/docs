# AbilityStageMonitor

The module provides conditions for matching AbilityStage instances. The most recently matched AbilityStage instance is saved in an AbilityStageMonitor instance.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description |
| ---- | ---- | ---- | ---- | ---- |
| moduleName | string | No  | No  | Module name of the AbilityStage instance.|
| srcEntrance | string | No  | No  | Source path of the AbilityStage instance.|

**Example**
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

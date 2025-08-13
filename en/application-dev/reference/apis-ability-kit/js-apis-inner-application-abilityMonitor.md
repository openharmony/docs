# AbilityMonitor

The AbilityMonitor module provides monitors for abilities that meet specified conditions. The latest matched abilities are stored in an AbilityMonitor object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## Usage

AbilityMonitor can be used as an input parameter of [addAbilityMonitor](../apis-test-kit/js-apis-inner-application-abilityDelegator.md#addabilitymonitor9) in **abilityDelegator** to listen for lifecycle changes of an ability.

## AbilityMonitor

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                                                        | Type    | Read Only| Optional| Description                                                        |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | No  | No  | Name of the ability bound to the ability monitor.|
| moduleName                                                  | string   | No  | Yes  | Name of the module bound to the ability monitor.|
| onAbilityCreate | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | No  | Yes  | Called when the ability is created.<br>If this property is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityForeground | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | No  | Yes  | Called when the ability starts to run in the foreground.<br>If this property is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityBackground | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | No  | Yes  | Called when the ability starts to run in the background.<br>If this property is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityDestroy | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | No  | Yes  | Called when the ability is destroyed.<br>If this property is not set, the corresponding lifecycle callback cannot be received.|
| onWindowStageCreate | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | No  | Yes  | Called when the window stage is created.<br>If this property is not set, the corresponding lifecycle callback cannot be received.|
| onWindowStageRestore | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | No  | Yes  | Called when the window stage is restored.<br>If this property is not set, the corresponding lifecycle callback cannot be received.|
| onWindowStageDestroy | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | No  | Yes  | Called when the window stage is destroyed.<br>If this property is not set, the corresponding lifecycle callback cannot be received.|

**Example**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function onAbilityCreateCallback(data: UIAbility) {
  console.info(`onAbilityCreateCallback, data: ${JSON.stringify(data)}`);
}

let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  moduleName: "moduleName",
  onAbilityCreate: onAbilityCreateCallback
}

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor, (error: BusinessError) => {
  if (error) {
    console.error(`addAbilityMonitor fail, error: ${JSON.stringify(error)}`);
  }
});
```

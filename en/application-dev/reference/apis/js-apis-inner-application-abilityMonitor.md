# AbilityMonitor

The **AbilityMonitor** module provides monitors for abilities that meet specified conditions. The latest matched abilities are stored in an **AbilityMonitor** object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Usage

The ability monitor can be set by calling **addAbilityMonitor** in **abilityDelegator**.

## AbilityMonitor

Describes an ability monitor.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                                                        | Type    | Readable| Writable| Description                                                        |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | Yes  | Yes  | Name of the ability bound to the ability monitor.|
| onAbilityCreate?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityForeground?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability starts to run in the foreground.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityBackground?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability starts to run in the background.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityDestroy?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|
| onWindowStageCreate?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the window stage is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|
| onWindowStageRestore?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the window stage is restored.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|
| onWindowStageDestroy?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the window stage is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|

**Example**

```ts
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor, (err : any) => {
    console.info("addAbilityMonitor callback");
});
```

# AbilityMonitor

The **AbilityMonitor** module provides monitors for abilities that meet specified conditions. The latest matched abilities are stored in an **AbilityMonitor** object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';
```

## Usage

**AbilityMonitor** can be used as an input parameter of [addAbilityMonitor](js-apis-inner-application-abilityDelegator.md#addabilitymonitor9) in **abilityDelegator** to listen for lifecycle changes of an ability.

## AbilityMonitor

Describes an ability monitor.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                                                        | Type    | Readable| Writable| Description                                                        |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | Yes  | Yes  | Name of the ability bound to the ability monitor.|
| moduleName?                                                  | string   | Yes  | Yes  | Name of the module bound to the ability monitor.|
| onAbilityCreate?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityForeground?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability starts to run in the foreground.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityBackground?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability starts to run in the background.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityDestroy?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the ability is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|
| onWindowStageCreate?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the window stage is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|
| onWindowStageRestore?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the window stage is restored.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|
| onWindowStageDestroy?:(data: [UIAbility](js-apis-app-ability-uiAbility.md)) | function | Yes  | Yes  | Called when the window stage is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>|

**Example**

```ts
function onAbilityCreateCallback(data) {
    console.info('onAbilityCreateCallback');
}

let monitor = {
    abilityName: 'abilityname',
    moduleName: "moduleName",
    onAbilityCreate: onAbilityCreateCallback
};

let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor, (error : any) => {
    if (error && error.code !== 0) {
        console.error('addAbilityMonitor fail, error: ${JSON.stringify(error)}');
    }
});
```



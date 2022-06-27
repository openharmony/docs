# AbilityMonitor

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```

## AbilityMonitor

Describes an ability monitor.

| Name                                                        | Type    | Readable| Writable| Description                                                        |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | Yes  | Yes  | Name of the ability bound to the ability monitor.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| onAbilityCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | Yes  | Yes  | Called when the ability is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| onAbilityForeground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | Yes  | Yes  | Called when the ability starts to run in the foreground.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| onAbilityBackground?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | Yes  | Yes  | Called when the ability starts to run in the background.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| onAbilityDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | Yes  | Yes  | Called when the ability is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| onWindowStageCreate?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | Yes  | Yes  | Called when the window stage is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| onWindowStageRestore?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | Yes  | Yes  | Called when the window stage is restored.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| onWindowStageDestroy?:(data: [Ability](js-apis-application-ability.md#Ability)) | function | Yes  | Yes  | Called when the window stage is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|

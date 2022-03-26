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

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                | Type    | Readable| Writable| Description                                                        |
| -------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName          | string   | Yes  | Yes  | Name of the ability bound to the ability monitor.                       |
| onAbilityCreate      | function | Yes  | Yes  | Called when the ability is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityForeground  | function | Yes  | Yes  | Called when the ability starts to run in the foreground.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityBackground  | function | Yes  | Yes  | Called when the ability starts to run in the background.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onAbilityDestroy     | function | Yes  | Yes  | Called when the ability is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onWindowStageCreate  | function | Yes  | Yes  | Called when the window stage is created.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onWindowStageRestore | function | Yes  | Yes  | Called when the window stage is restored.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|
| onWindowStageDestroy | function | Yes  | Yes  | Called when the window stage is destroyed.<br>If this attribute is not set, the corresponding lifecycle callback cannot be received.|

# AbilityResult

The **AbilityResult** module defines the result code and data returned when an ability is terminated after being started. You can use [startAbilityForResult](js-apis-ability-featureAbility.md#featureabilitystartabilityforresult7) to obtain the **AbilityResult** object returned after the started ability is terminated. The started ability returns the **AbilityResult** object by calling [terminateSelfWithResult](js-apis-ability-featureAbility.md#featureabilityterminateselfwithresult7).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityBase

| Name       |  Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| resultCode  | number               | Yes  | Result code returned after the started ability is terminated.                               |
| want  | [Want](./js-apis-app-ability-want.md)               | No  | Data returned after the started ability is terminated.|

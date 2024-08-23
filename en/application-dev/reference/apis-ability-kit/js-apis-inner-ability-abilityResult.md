# AbilityResult

The **AbilityResult** module defines the result code and data returned when an ability is terminated after being started.

In the stage model, you can use [startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilityforresult) to obtain the **AbilityResult** object returned after the started ability is terminated by calling [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult).

In the FA model, you can use [startAbilityForResult](js-apis-ability-featureAbility.md#featureabilitystartabilityforresult7) to obtain the **AbilityResult** object returned after the started ability is terminated by calling [terminateSelfWithResult](js-apis-ability-featureAbility.md#featureabilityterminateselfwithresult7).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

Stage model:
```ts
import { common } from '@kit.AbilityKit';
```

FA model:
```ts
import ability from '@ohos.ability.ability';
```

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityBase

| Name       |  Type                | Read-only| Optional| Description                                                        |
| ----------- | -------------------- | ---- | ---- | ------------------------------------------------------------ |
| resultCode  | number               | No  | No  | Result code returned after the started ability is terminated.                               |
| want  | [Want](js-apis-app-ability-want.md) | No  | Yes  | Data returned after the started ability is terminated.|

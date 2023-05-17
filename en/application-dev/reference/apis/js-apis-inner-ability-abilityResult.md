# AbilityResult

The **AbilityResult** module defines the result code and data returned when an ability is terminated after being started. You can use [startAbilityForResult](js-apis-ability-featureAbility.md#featureabilitystartabilityforresult7) to obtain the **AbilityResult** object returned after the started ability is terminated. The startedability returns the **AbilityResult** object by calling [terminateSelfWithResult](js-apis-ability-featureAbility.md#featureabilityterminateselfwithresult7).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Readable   | Writable    | Type                | Mandatory| Description                                                        |
| ----------- | -------- |-------- | -------------------- | ---- | ------------------------------------------------------------ |
| resultCode    | Yes   | Yes     | number               | Yes  | Result code returned after the started ability is terminated.                              |
| want   | Yes   | Yes     | [Want](./js-apis-app-ability-want.md)               | No  | Data returned after the started ability is terminated. |

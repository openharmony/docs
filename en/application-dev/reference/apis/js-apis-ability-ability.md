# @ohos.ability.ability (Ability)

The **Ability** module provides all level-2 module APIs for developers to export.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

## Attributes

| Name        | Type                | Description                                                        |
| ----------- | -------------------- | ------------------------------------------------------------ |
| DataAbilityHelper    | [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md)               | Level-2 module **DataAbilityHelper**.<br>SystemCapability.Ability.AbilityRuntime.FAModel |
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)               | Level-2 module **PacMap**.<br>SystemCapability.Ability.AbilityRuntime.FAModel |
| DataAbilityOperation   | [DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)               | Level-2 module **DataAbilityOperation**.<br>SystemCapability.Ability.AbilityRuntime.FAModel |
| DataAbilityResult   | [DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)               | Level-2 module **DataAbilityResult**.<br>SystemCapability.Ability.AbilityRuntime.FAModel |
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)               | Level-2 module **AbilityResult**.<br>SystemCapability.Ability.AbilityBase |
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)               | Level-2 module **ConnectOptions**.<br>SystemCapability.Ability.AbilityRuntime.Core |
| StartAbilityParameter   | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md)               | Level-2 module **StartAbilityParameter**.<br>ystemCapability.Ability.AbilityRuntime.FAModel |

**Example**
```ts
import ability from '@ohos.ability.ability';

let dataAbilityHelper: ability.DataAbilityHelper;
let pacMap: ability.PacMap;
let dataAbilityOperation: ability.DataAbilityOperation;
let dataAbilityResult: ability.DataAbilityResult;
let abilityResult: ability.AbilityResult;
let connectOptions: ability.ConnectOptions;  
let startAbilityParameter: ability.StartAbilityParameter;
```

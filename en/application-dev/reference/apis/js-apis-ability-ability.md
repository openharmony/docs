# @ohos.ability.ability

The **Ability** module provides all level-2 module APIs for developers to export.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import ability from '@ohos.ability.ability'
```

**System capability**: SystemCapability.Ability.AbilityBase

| Name        | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| DataAbilityHelper    | [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md)               | No  | Level-2 module **DataAbilityHelper**.                               |
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#PacMap)               | No  | Level-2 module **PacMap**.|
| DataAbilityOperation   | [DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)               | No  | Level-2 module **DataAbilityOperation**.|
| DataAbilityResult   | [DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)               | No  | Level-2 module **DataAbilityResult**.|
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)               | No  | Level-2 module **AbilityResult**.|
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)               | No  | Level-2 module **ConnectOptions**.|
| StartAbilityParameter   | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md)               | No  | Level-2 module **StartAbilityParameter**.|

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

# @ohos.ability.ability (Ability)

The **Ability** module provides all level-2 module APIs for developers to export.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { ability } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read Only| Optional| Description      |
| ---- | ---- | --- | ---- | --------- |
| DataAbilityHelper    | [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md)  | No| No| Level-2 module **DataAbilityHelper**.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel<br>**Model restriction**: This API can be used only in the FA model.|
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)  | No| No| Level-2 module **PacMap**.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel|
| DataAbilityOperation   | [DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)  | No| No| Level-2 module **DataAbilityOperation**.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel<br>**Model restriction**: This API can be used only in the FA model.|
| DataAbilityResult   | [DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)  | No| No| Level-2 module **DataAbilityResult**.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel<br>**Model restriction**: This API can be used only in the FA model.|
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)  | No| No| Level-2 module **AbilityResult**.<br>**System capability**: SystemCapability.Ability.AbilityBase<br>**Model restriction**: This API can be used only in the FA model.|
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)  | No| No| Level-2 module **ConnectOptions**.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core<br>**Model restriction**: This API can be used only in the FA model.|
| StartAbilityParameter   | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md)  | No| No| Level-2 module **StartAbilityParameter**.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel<br>**Model restriction**: This API can be used only in the FA model.|

**Example**
```ts
import { ability } from '@kit.AbilityKit';

let dataAbilityHelper: ability.DataAbilityHelper;
let pacMap: ability.PacMap;
let dataAbilityOperation: ability.DataAbilityOperation;
let dataAbilityResult: ability.DataAbilityResult;
let abilityResult: ability.AbilityResult;
let connectOptions: ability.ConnectOptions;  
let startAbilityParameter: ability.StartAbilityParameter;
```

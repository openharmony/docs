# @ohos.ability.ability (Ability)

Ability模块将二级模块API组织在一起方便开发者进行导出。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在FA模型下使用

## 导入模块

```ts
import ability from '@ohos.ability.ability'
```

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称         | 类型                 | 必填 | 描述                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| DataAbilityHelper    | [DataAbilityHelper](js-apis-inner-ability-dataAbilityHelper.md)               | 否   | DataAbilityHelper二级模块。                                |
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#PacMap)               | 否   | PacMap二级模块。 |
| DataAbilityOperation   | [DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)               | 否   | DataAbilityOperation二级模块。 |
| DataAbilityResult   | [DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)               | 否   | DataAbilityResult二级模块。 |
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)               | 否   | AbilityResult二级模块。 |
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)               | 否   | ConnectOptions二级模块。 |
| StartAbilityParameter   | [StartAbilityParameter](js-apis-inner-ability-startAbilityParameter.md)               | 否   | StartAbilityParameter二级模块。 |

**示例：**
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
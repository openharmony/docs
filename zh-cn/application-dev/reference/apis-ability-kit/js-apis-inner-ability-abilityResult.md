# AbilityResult

定义Ability被拉起并退出后返回的结果码和数据。
Stage模型下，可以通过[startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilityforresult)获取被拉起Ability退出后返回的AbilityResult对象，被startAbilityForResult拉起的Ability对象可以通过[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult)返回AbilityResult对象。
FA模型下，可以通过[startAbilityForResult](js-apis-ability-featureAbility.md#featureabilitystartabilityforresult7)获取被拉起Ability退出后返回的AbilityResult对象，被startAbilityForResult拉起的Ability对象可以通过[terminateSelfWithResult](js-apis-ability-featureAbility.md#featureabilityterminateselfwithresult7)返回AbilityResult对象。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

Stage模型下：
```ts
import { common } from '@kit.AbilityKit';
```

FA模型下：
```ts
import ability from '@ohos.ability.ability';
```

## 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称        |  类型                 | 只读 | 可选 | 说明                                                         |
| ----------- | -------------------- | ---- | ---- | ------------------------------------------------------------ |
| resultCode  | number               | 否   | 否   | 表示Ability被拉起并退出后返回的结果码。                                |
| want  | [Want](js-apis-app-ability-want.md) | 否   | 是   | 表示Ability被拉起并退出后返回的数据。 |


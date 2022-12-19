# AbilityResult<sup>7+</sup>

定义Ability拉起、销毁之后返回的结果码和数据，可以通过[startAbilityForResult](js-apis-ability-context.md#abilitycontextstartabilityforresult)获取对端Ability销毁后返回的AbilityResult对象，被startAbilityForResult拉起的Ability对象可以通过[terminateSelfWithResult](js-apis-ability-context.md#abilitycontextterminateselfwithresult)返回AbilityResult对象。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称        | 可读    | 可写     | 类型                 | 必填 | 说明                                                         |
| ----------- | -------- |-------- | -------------------- | ---- | ------------------------------------------------------------ |
| resultCode    | 是    | 否      | number               | 否   | 表示ability拉起、销毁之后返回的结果码。                                |
| want   | 是    | 否      | [Want](./js-apis-app-ability-want.md)               | 否   | 表示ability销毁之后返回的数据。 |


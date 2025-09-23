# AbilityResult
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

定义UIAbility被拉起并退出后返回给调用方的结果码和数据。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

[Stage模型](../../application-models/ability-terminology.md#stage模型)下：
```ts
import { common } from '@kit.AbilityKit';
```

[FA模型](../../application-models/ability-terminology.md#fa模型)下：
```ts
import ability from '@ohos.ability.ability';
```

## 使用说明

Stage模型下：可以通过[startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#startabilityforresult)获取被拉起的UIAbility退出后返回的AbilityResult对象，被startAbilityForResult拉起的UIAbility对象可以通过[terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult)返回AbilityResult对象。

FA模型下：可以通过[startAbilityForResult](js-apis-ability-featureAbility.md#featureabilitystartabilityforresult7)获取被拉起的UIAbility退出后返回的AbilityResult对象，被startAbilityForResult拉起的UIAbility对象可以通过[terminateSelfWithResult](js-apis-ability-featureAbility.md#featureabilityterminateselfwithresult7)返回AbilityResult对象。

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityBase

| 名称        |  类型                 | 只读 | 可选 | 说明                                                         |
| ----------- | -------------------- | ---- | ---- | ------------------------------------------------------------ |
| resultCode  | number               | 否   | 否   | 目标方的UIAbility被拉起并退出后，目标方返回给拉起方的结果码。<br/>-&nbsp;正常情况下，返回目标方传递的结果码。<br/>-&nbsp;异常情况下，返回-1。                                |
| want  | [Want](js-apis-app-ability-want.md) | 否   | 是   | 表示UIAbility被拉起并退出后返回的数据。 |

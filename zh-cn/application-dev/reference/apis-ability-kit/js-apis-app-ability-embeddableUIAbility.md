# @ohos.app.ability.EmbeddableUIAbility (可嵌入式UIAbility组件)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

EmbeddableUIAbility组件是为原子化服务提供可嵌入式的UIAbility组件，继承自[UIAbility](js-apis-app-ability-uiAbility.md)。

开发者通过实现EmbeddableUIAbility，为其他应用提供跳出式启动和嵌入式启动原子化服务方式。

各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { EmbeddableUIAbility } from '@kit.AbilityKit';
```

## EmbeddableUIAbility

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md) | 否 | 否 | EmbeddableUIAbility组件的上下文。 |

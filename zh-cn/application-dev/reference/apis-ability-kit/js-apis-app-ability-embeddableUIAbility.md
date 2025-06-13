# @ohos.app.ability.EmbeddableUIAbility (可嵌入式UIAbility)

EmbeddableUIAbility是为原子化服务提供可以嵌入式启动的UIAbility，继承自[UIAbility](js-apis-app-ability-uiAbility.md)，同时具备跳转启动和嵌入式启动两种启动方式。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { EmbeddableUIAbility } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md) | 否 | 否 | 上下文。 |

# @ohos.app.ability.ShareExtensionAbility (分享详情页扩展能力)

ShareExtensionAbility继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，为开发者提供分享详情页扩展能力。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 场景介绍

以分享文本为例。用户选择一段文本，拉起要分享应用，此时被分享拉起的应用会根据分享信息将分享模板拉起，并将数据按分享模板内容显示。

## 导入模块

```ts
import { ShareExtensionAbility } from '@kit.AbilityKit';
```

## ShareExtensionAbility

ShareExtensionAbility继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，为开发者提供分享详情页扩展能力。

该模块支持开发者创建接收分享内容的分享详情页面，将应用入口展示于系统分享面板的推荐应用区域。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

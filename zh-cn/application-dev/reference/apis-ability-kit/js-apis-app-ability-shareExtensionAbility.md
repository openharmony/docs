# @ohos.app.ability.ShareExtensionAbility (支持分享详情页接入的ExtensionAbility组件)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

ShareExtensionAbility继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，为开发者提供接入分享详情页能力。

开发者通过实现ShareExtensionAbility，可实现作为一个选项出现在系统分享面板的分享方式区域。以分享文本为例，用户选中文本并分享后，系统将拉起目标应用。目标应用接收并解析分享数据，展示文本分享页面。

各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { ShareExtensionAbility } from '@kit.AbilityKit';
```

## ShareExtensionAbility

ShareExtensionAbility继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，为开发者提供分享详情页扩展能力。

该模块支持开发者创建接收分享内容的分享详情页面，将应用入口展示于系统分享面板的推荐应用区域。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

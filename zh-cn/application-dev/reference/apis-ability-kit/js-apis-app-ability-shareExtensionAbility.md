# @ohos.app.ability.ShareExtensionAbility (支持分享详情页接入的ExtensionAbility组件)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

ShareExtensionAbility继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，为开发者提供接入分享详情页能力。

开发者通过实现ShareExtensionAbility，可具备接收分享数据的能力，在系统分享面板中作为一个可选项出现。以分享文本为例，用户选中文本并选择分享后，系统会自动检测所有已声明此能力的应用，并将其列在分享面板中。当用户选择该应用时，系统会将其拉起，并由其接收、解析分享的文本数据，最终展示出相应的分享界面。

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

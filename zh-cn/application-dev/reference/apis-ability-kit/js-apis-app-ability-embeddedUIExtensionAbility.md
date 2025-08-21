# @ohos.app.ability.EmbeddedUIExtensionAbility (跨进程界面嵌入扩展能力)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo-->
<!--Designer: @zhangyafei-echo-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

EmbeddedUIExtensionAbility为开发者提供了跨进程界面嵌入的能力，继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { EmbeddedUIExtensionAbility } from '@kit.AbilityKit';
```

## EmbeddedUIExtensionAbility

EmbeddedUIExtensionAbility为开发者提供了跨进程界面嵌入的能力，继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)。

目前EmbeddedUIExtensionAbility只能被同应用的UIAbility拉起，并且仅在2in1和Tablet设备上生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

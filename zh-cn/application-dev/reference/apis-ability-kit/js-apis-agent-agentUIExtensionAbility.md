# @ohos.app.ability.AgentUIExtensionAbility (带界面的智能体扩展组件)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

AgentUIExtensionAbility继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，为开发者提供接入端侧Agent UI界面显示能力。

[AgentExtensionAbility](./js-apis-app-agent-agentExtensionAbility.md)提供智能体扩展能力，AgentUIExtensionAbility必须与AgentExtensionAbility共进程运行，不支持独立运行。

各类Ability的继承关系详见[继承关系说明](./js-apis-app-ability-ability.md#ability的继承关系说明)。

> **说明：**
>
> 本模块首批接口从API version 24 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口不支持在[har](../../quick-start/har-package.md)包中使用。

## 约束限制

- 同一个拉起方在同一时间内最多只能拉起来自同一个提供方的5个AgentUIExtensionAbility实例。
- AgentUIExtensionAbility内的窗口和ArkUI组件均不允许创建子窗口，也不支持在子窗口中显示。

## 导入模块

```ts
import { AgentUIExtensionAbility } from '@kit.AbilityKit';
```

## AgentUIExtensionAbility

AgentUIExtensionAbility继承自[UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md)，为开发者提供接入端侧Agent UI界面显示能力。例如，当Agent开发者希望在其他应用中显示Agent返回的结果时，可以通过接入AgentUIExtensionAbility提供展示嵌入式弹窗的能力。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

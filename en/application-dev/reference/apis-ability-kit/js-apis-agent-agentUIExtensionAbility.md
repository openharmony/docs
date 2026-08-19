# @ohos.app.ability.AgentUIExtensionAbility (UI-Enabled Agent Extension Component)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e01350d88b673bbd3dab4c76e0fbd0aea5a52870 translatedAt=2026-08-13T13:21:19.319Z pushedAt=2026-08-14T08:28:39.276Z -->

AgentUIExtensionAbility inherits from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md) and provides developers with the capability to display the on-device Agent UI.

[AgentExtensionAbility](./js-apis-app-agent-agentExtensionAbility.md) provides the agent extension capability. AgentUIExtensionAbility must run in the same process as AgentExtensionAbility and does not support running independently.

For details about the inheritance relationships of various abilities, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module are not supported in [HAR](../../quick-start/har-package.md) packages.

## Constraints

- A caller can start a maximum of five AgentUIExtensionAbility instances from the same provider at the same time.

- Neither the windows nor the ArkUI components in AgentUIExtensionAbility are allowed to create subwindows, nor are they supported for display in subwindows.

## Modules to Import

```ts
import { AgentUIExtensionAbility } from '@kit.AbilityKit';
```

## AgentUIExtensionAbility

AgentUIExtensionAbility inherits from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md) and provides developers with the capability to display on-device Agent UI. For example, when an Agent developer wants to display the result returned by the Agent in another app, they can integrate AgentUIExtensionAbility to provide the capability of displaying an embedded pop-up window.

**System capability:** SystemCapability.Ability.AgentRuntime.Core
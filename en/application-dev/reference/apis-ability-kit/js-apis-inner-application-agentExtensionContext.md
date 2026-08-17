# AgentExtensionContext

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=8655fb8063e6fdd51b952cca96b6d4464851a91d translatedAt=2026-08-13T13:21:22.768Z pushedAt=2026-08-17T03:46:40.820Z -->

The AgentExtensionContext module is the context environment of [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) and inherits from [ExtensionContext](js-apis-inner-application-extensionContext.md).

AgentExtensionContext provides developers with the capability to access the [AgentCard](js-apis-inner-application-AgentCard.md) information configured for the agent of the current [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in the stage model.
> - In the examples in this document, `this.context` is used to obtain `AgentExtensionContext`, where `this` represents an instance inherited from `AgentExtensionAbility`.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## AgentExtensionContext

### Attributes

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| agentCard | [AgentCard](js-apis-inner-application-AgentCard.md) | No | No | Information about the [AgentCard](js-apis-inner-application-AgentCard.md#agentcard-1) configured for the current [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) agent. |

**Example**

```ts
import { AgentExtensionAbility, common } from '@kit.AbilityKit';

export default class AgentExtension extends AgentExtensionAbility {
  onCreate(): void {
    let tmpContext: common.AgentExtensionContext = this.context; // Obtain the AgentExtensionContext.
    console.info(`agentCard info data: ${JSON.stringify(tmpContext.agentCard)}.`);
  }
}
```
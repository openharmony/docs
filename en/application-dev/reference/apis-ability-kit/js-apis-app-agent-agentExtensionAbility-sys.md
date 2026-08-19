# @ohos.app.agent.AgentExtensionAbility (Agent Extension Component)(System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=249c9154cca3bfd8d247bc281ba57ee999bfbe43 translatedAt=2026-08-13T13:17:48.732Z pushedAt=2026-08-14T10:45:44.727Z -->

AgentExtensionAbility inherits from [ExtensionAbility](js-apis-app-ability-extensionAbility.md) and provides agent extension capabilities. This module provides the callback interface invoked when an Agent of the [LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype) type is called, which is used to perform initialization operations (such as downloading resources from the cloud and loading configurations).

**Since**: 26.0.0

> **NOTE**
>
> This page contains only the system APIs of this module. For details about other public APIs, see [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md).

## Modules to Import

```ts
import { AgentExtensionAbility } from '@kit.AbilityKit';
```

## AgentExtensionAbility

### onAgentInvoked

onAgentInvoked(agentId: string): void

Triggered when an Agent of the [LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype) type is successfully invoked, to perform initialization operations (such as downloading resources from the cloud and loading configurations).

**Since**: 26.0.0

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| agentId | string | Yes | ID of the low-code Agent. |

**Example**

```ts
import { AgentExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AgentExtensionAbility]';

export default class AgentExt extends AgentExtensionAbility {
  onAgentInvoked(agentId: string) {
    hilog.info(0x0000, TAG, `onAgentInvoked, agentId: ${agentId}`);
  }
}
```
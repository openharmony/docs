# @ohos.app.agent.agentConstant (Agent Constants)(System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yangxuguang-huawei-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=6220cd4e91cf6679984142cec02ee693a831956f translatedAt=2026-08-13T13:17:50.511Z pushedAt=2026-08-14T10:42:09.016Z -->

The agentConstant module provides constants related to Agent.

**Since**: 26.0.0

> **NOTE**
>
> This page contains only the system APIs of this module. For details about other public APIs, see [@ohos.app.agent.agentConstant (Agent Constants)](js-apis-app-agent-agentConstant.md).

## Modules to Import

```ts
import { agentConstant } from '@kit.AbilityKit';
```

## agentConstant.AgentCardType

Enumerates the types of Agent cards.

**Atomic service API**: This enum can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

| Name      | Value   | Description                   |
| --------- | ---- | ---------------------- |
| LOW_CODE  | 2    | Low-code Agent card, available only to system apps. It applies to the agent capabilities provided by system apps for quick construction and deployment, and supports quickly creating an agent through visual configuration or simple scripts without writing complete code, lowering the barrier to agent development.     |
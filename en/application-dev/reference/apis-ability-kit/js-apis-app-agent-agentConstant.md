# @ohos.app.agent.agentConstant (Agent Constants)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yangxuguang-huawei-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=f2d5a877661a70cec29604daef41ec07f3f83de1 translatedAt=2026-08-13T13:17:21.473Z pushedAt=2026-08-14T10:43:22.466Z -->

This module provides constants related to Agent.

**Since**: 26.0.0

## Modules to Import

```ts
import { agentConstant } from '@kit.AbilityKit';
```

## agentConstant.AgentCardType

Enumerates the types of Agent cards.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This enum can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

| Name      | Value   | Description                   |
| --------- | ---- | ---------------------- |
| APP       | 0    | App-type Agent card, applicable to traditional installed apps. The Agent capability is installed and uninstalled together with the app, and can be used only after the user proactively installs the app.  |
| ATOMIC_SERVICE | 1 | Atomic-service-type Agent card, applicable to installation-free atomic services. The Agent capability can be used on demand without pre-installation, supporting quick experience and sharing. |
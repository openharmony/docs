# ToolEventCallback (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=ed83ee0d0bd44264cdd70409e27a4742e13aa7d6 translatedAt=2026-08-13T13:22:26.310Z pushedAt=2026-08-17T07:17:36.950Z -->

ToolEventCallback is used to receive session events generated during the running of a CLI tool process.

**Since**: 26.0.0

> **NOTE**
>
> The APIs of this module are system APIs.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## ToolEventCallback

Callback interface for session events generated during the running of a CLI tool process.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**Model restriction**: This API can be used only in the Stage model.

| Name    | Type                                                 | Read-Only | Optional | Description                      |
| ------- | ---------------------------------------------------- | ---- | ---- | ------------------------- |
| onEvent | (event: [CliToolEvent](js-apis-inner-application-cliToolEvent-sys.md#clitoolevent)) => void | No   | No   | Callback for the CLI tool session event. |

**Example**

```ts
import { common } from '@kit.AbilityKit';

let callback: common.ToolEventCallback = {
  onEvent: (event: common.CliToolEvent) => {
    console.info('tool event type: ' + event.toolEventType + ', data: ' + event.data);
  }
};
```
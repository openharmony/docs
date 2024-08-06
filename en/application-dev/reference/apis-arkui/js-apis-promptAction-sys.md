# @ohos.promptAction (Prompt) (System API)

The **PromptAction** module provides APIs for creating and showing toasts, dialog boxes, and action menus.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.promptAction (Prompt)](js-apis-promptAction.md).

## Modules to Import

```ts
import { promptAction } from '@kit.ArkUI';
```

### ToastShowMode

Describes the mode in which the toast is shown.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Value  | Description                  |
| -------- | ---- | ---------------------- |
| SYSTEM_TOP_MOST | 2    | The toast is displayed in a window of the TYPE_SYSTEM_TOAST type. |

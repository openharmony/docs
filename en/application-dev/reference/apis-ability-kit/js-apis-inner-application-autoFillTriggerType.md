# AutoFillTriggerType

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=8655fb8063e6fdd51b952cca96b6d4464851a91d translatedAt=2026-08-13T13:21:51.422Z pushedAt=2026-08-17T07:06:13.727Z -->

Enumerates the trigger types of the auto-fill service. Different trigger modes of the auto-fill service are selected through user gestures.

**Since**: 26.0.0

## Modules to Import

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## AutoFillTriggerType

Enumerates the trigger types of the auto-fill service. Three trigger modes are defined: AUTO_REQUEST, MANUAL_REQUEST, and PASTE_REQUEST. AutoFillTriggerType is the enum type of [FillRequest.triggerType](./js-apis-inner-application-autoFillRequest.md#fillrequest).

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction:** This API can be used only in the stage model.

| Name           | Value | Description                               |
| -------------- | ----- | --------------------------------- |
| AUTO_REQUEST   | 0 | The auto-fill service is triggered automatically after a [TextInput](../../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md) component gains focus. |
| MANUAL_REQUEST | 1 | The auto-fill service is triggered manually. You can touch and hold any input component to display the secondary menu, and select auto-fill to trigger the auto-fill service. |
| PASTE_REQUEST  | 2 | The auto-fill service is triggered by paste. It is triggered only when you touch and hold a username or password in the password vault to copy it securely, and then touch and hold any input component to display the secondary menu and select paste. |
# @ohos.app.ability.hyperSnapManager (Quick Launch Management)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @jsjzju-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:24:34.517Z pushedAt=2026-08-14T08:54:44.198Z -->

The initialization process during app startup can be performed in advance as quick launch initialization, so that apps started via Quick Launch do not repeat the initialization process, thereby accelerating startup. The hyperSnapManager module provides Quick Launch management capabilities, including enabling or disabling the Quick Launch feature of an app and requesting re-initialization of Quick Launch.

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Implementation Principle

Quick Launch initializes an app only once, which saves the time required for app initialization and AbilityStage creation during Quick Launch startup.

**Figure 1** Quick Launch startup process


## Modules to Import

```ts
import { hyperSnapManager } from '@kit.AbilityKit';
```

## hyperSnapManager.setHyperSnapEnabled

setHyperSnapEnabled(enableFlag: boolean): void

Enables or disables the Quick Launch feature of an app.

> **NOTE**
>
> - When this API is used to enable the Quick Launch feature, the system ultimately decides whether to create or use Quick Launch based on app compatibility, resource availability, and system policies. When this API is used to disable the Quick Launch feature, it is guaranteed that the system will not create Quick Launch.
> - The configured value persists after a restart.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| enableFlag | boolean | Yes | Whether to enable the Quick Launch feature. <br>- `true`: enables the Quick Launch feature (the system makes the final decision on whether to create a quick launch). <br>- `false`: disables the Quick Launch feature.|

Error codes

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| ------- | -------- |
| 16000150 | Failed to send request to system service. |

**Example**

```ts
import { hyperSnapManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Enable the Quick Launch feature.
  hyperSnapManager.setHyperSnapEnabled(true);
  console.info('Hyper Snap enabled successfully.');
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Failed to enable Hyper Snap. Code: ${code}, Message: ${message}`);
}
```

## hyperSnapManager.requestRebuildHyperSnap

requestRebuildHyperSnap(): void

Requests re-initialization of Quick Launch.

This method destroys the Quick Launch data that has been initialized in the current process, and the system will re-initialize Quick Launch at an appropriate time.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| ------- | -------- |
| 16000150 | Failed to send request to system service. |

**Example**

```ts
import { hyperSnapManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Request to reinitialize Quick Launch.
  hyperSnapManager.requestRebuildHyperSnap();
  console.info('Requested to rebuild Hyper Snap successfully.');
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Failed to request Hyper Snap rebuild. Code: ${code}, Message: ${message}`);
}
```
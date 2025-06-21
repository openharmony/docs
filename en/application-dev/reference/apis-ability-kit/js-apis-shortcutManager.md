# @ohos.bundle.shortcutManager (shortcutManager)

The shortcutManager module provides APIs to manage shortcuts, including whether to display shortcuts.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { shortcutManager } from '@kit.AbilityKit';
```

## shortcutManager.setShortcutVisibleForSelf

setShortcutVisibleForSelf(id: string, visible: boolean) : Promise\<void>

Sets whether to display the shortcut with the specified ID for the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| id         | string | Yes  | Shortcut ID, which is the value of the **shortcutId** field under the **shortcuts** tag in the [module.json5 file](../../quick-start/module-configuration-file.md). The value is a string of up to 63 bytes.|
| visible    | boolean| Yes  | Whether to display the shortcut. The value **true** means to display the shortcut, and **false** means the opposite.|

**Return value**

| Type            | Description             |
| -------------- | --------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 17700070 | The specified shortcut id is not exist. |

**Example**

```ts
import { shortcutManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Replace it with the shortcutId field under the shortcuts tag of the module.json5 file.
shortcutManager.setShortcutVisibleForSelf("shortcut_id", false)
  .then(() => {
    console.log("setShortcutVisibleForSelf success");
  }).catch((err: BusinessError) => {
  console.error(`setShortcutVisibleForSelf errData is errCode:${err.code}  message:${err.message}`);
});
```

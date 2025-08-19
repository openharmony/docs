# @ohos.bundle.shortcutManager (shortcutManager) (System API)

The module allows system applications to add, delete, and query shortcuts, including [ShortcutInfo](js-apis-bundleManager-shortcutInfo.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { shortcutManager } from '@kit.AbilityKit';
```


## shortcutManager.addDesktopShortcutInfo<sup>12+</sup>

addDesktopShortcutInfo(shortcutInfo: [ShortcutInfo](js-apis-bundleManager-shortcutInfo.md), userId: number) : Promise\<void>

Adds a shortcut for the given user.

**Required permissions**: ohos.permission.MANAGE_SHORTCUTS

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| shortcutInfo | [ShortcutInfo](js-apis-bundleManager-shortcutInfo.md) | Yes  | Shortcut information.|
| userId     | number | Yes  | User ID.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700001 | The specified bundle name is not found.  |
| 17700004 | The specified user ID is not found.      |
| 17700026 | The specified bundle is disabled. |
| 17700061 | The specified app index is invalid. |
| 17700070 | The specified shortcut id is illegal. |

**Example**

```ts
import { shortcutManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct ShortcutExample {
  build() {
    Column({ space: 20 }) {
      Row({ space: 20 }) {
        Button('add').onClick(() => {
          let data: shortcutManager.ShortcutInfo = {
            id: "test1",
            bundleName: "com.example.myapplication",
            moduleName: "hello",
            hostAbility: "hello",
            icon: "hello",
            iconId: 1,
            label: "hello",
            labelId: 1,
            wants: [],
            appIndex: 0,
            sourceType: 0,
          }
          try {
            shortcutManager.addDesktopShortcutInfo(data, 100)
              .then(() => {
                console.info("addDesktopShortcutInfo success");
              }).catch((err: BusinessError) => {
              console.error(`addDesktopShortcutInfo errData is errCode:${err.code}  message:${err.message}`);
            });
          } catch (error) {
            let code = (error as BusinessError).code;
            let message = (error as BusinessError).message;
            console.error(`addDesktopShortcutInfo error is errCode:${code}  message:${message}`);
          }
        })
      }
    }
  }
}
```

## shortcutManager.deleteDesktopShortcutInfo<sup>12+</sup>

deleteDesktopShortcutInfo(shortcutInfo: [ShortcutInfo](js-apis-bundleManager-shortcutInfo.md), userId: number) : Promise\<void>

Deletes a shortcut for the given user.

**Required permissions**: ohos.permission.MANAGE_SHORTCUTS

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| shortcutInfo | [ShortcutInfo](js-apis-bundleManager-shortcutInfo.md) | Yes  | Shortcut information.|
| userId     | number | Yes  | User ID.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found.       |

**Example**

```ts
import { shortcutManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct ShortcutExample {
  build() {
    Column({ space: 20 }) {
      Row({ space: 20 }) {
        Button('delete').onClick(() => {
          let data: shortcutManager.ShortcutInfo = {
            id: "test1",
            bundleName: "com.example.myapplication",
            moduleName: "",
            hostAbility: "",
            icon: "",
            iconId: 1,
            label: "hello",
            labelId: 1,
            wants: [],
            appIndex: 0,
            sourceType: 0,
          }
          try {
            shortcutManager.deleteDesktopShortcutInfo(data, 100)
              .then(() => {
                console.info("deleteDesktopShortcutInfo success");
              }).catch((err: BusinessError) => {
              console.error(`deleteDesktopShortcutInfo errData is errCode:${err.code}  message:${err.message}`);
            });
          } catch (error) {
            let code = (error as BusinessError).code;
            let message = (error as BusinessError).message;
            console.error(`deleteDesktopShortcutInfo error is errCode:${code}  message:${message}`);
          }
        })
      }
    }
  }
}
```

## shortcutManager.getAllDesktopShortcutInfo<sup>12+</sup>

getAllDesktopShortcutInfo(userId: number) : Promise<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>>

Obtains the information about all shortcuts of the given user.

**Required permissions**: ohos.permission.MANAGE_SHORTCUTS

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Launcher

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | -------------- |
| userId     | number | Yes  | User ID.|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise<Array\<[ShortcutInfo](js-apis-bundleManager-shortcutInfo.md)>> | Promise that returns the shortcut information defined in the application configuration file.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bundle Error Codes](errorcode-bundle.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|
| 17700004 | The specified user ID is not found.       |

**Example**

```ts
import { shortcutManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct ShortcutExample {
  build() {
    Column({ space: 20 }) {
      Row({ space: 20 }) {
        Button('getall').onClick(() => {
          try {
            shortcutManager.getAllDesktopShortcutInfo(100)
              .then((data: shortcutManager.ShortcutInfo[]) => {
                console.info("Shortcut data is " + JSON.stringify(data));
              }).catch((err: BusinessError) => {
              console.error(`getAllDesktopShortcutInfo errData is errCode:${err.code}  message:${err.message}`);
            });
          } catch (error) {
            let code = (error as BusinessError).code;
            let message = (error as BusinessError).message;
            console.error(`getAllDesktopShortcutInfo error is errCode:${code}  message:${message}`);
          }
        })
      }
    }
  }
}
```

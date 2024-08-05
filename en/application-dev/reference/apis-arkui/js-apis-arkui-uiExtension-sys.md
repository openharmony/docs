# @ohos.arkui.uiExtension (uiExtension) (System API)

The **uiExtension** module provides APIs for the EmbeddedUIExtensionAbility (or UIExtensionAbility) to obtain the host application window information or the information about the corresponding **\<EmbeddedComponent>** (or **\<UIExtensionComponent>**).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.arkui.uiExtension (uiExtension)](js-apis-arkui-uiExtension.md).

## Modules to Import

```
import { uiExtension } from '@kit.ArkUI'
```

## WindowProxy

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise\<void>

Sets whether to hide insecure windows.

> **NOTE**
>
> Insecure windows refer to the windows that may block the **EmbeddedComponent** (or **UIExtensionComponent**), such as global floating windows, host subwindows, and dialog box windows created by the host application, excluding the aforementioned types of windows created by system applications. When the **\<EmbeddedComponent>** (or **\<UIExtensionComponent>**) is used to present important information, you can hide insecure windows to prevent such information from being blocked. When the **\<EmbeddedComponent>** (or **\<UIExtensionComponent>**) is not displayed or is destroyed, you must unhide the insecure windows. The **UIExtensionComponent** created using the **CreateModalUIExtension** API will hide insecure windows by default, which cannot be changed manually.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                     | Mandatory | Description      |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | Yes  | Whether to hide insecure windows. The value **true** means to hide insecure windows, and **false** means the opposite. |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes** 

| ID | Error Message                         |
| -------- | --------------------------------- |
| 401      | Parameter error. Possible causes: |

**Example**

```ts
// ExtensionProvider.ts

import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Hide insecure windows.
    extensionHostWindow.hideNonSecureWindows(true).then(()=> {
      console.log(`Succeeded in hiding the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(`Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Unhide insecure windows.
    extensionHostWindow.hideNonSecureWindows(false).then(()=> {
      console.log(`Succeeded in showing the non-secure windows.`);
    }).catch((err: BusinessError)=> {
      console.log(`Failed to show the non-secure windows. Cause:${JSON.stringify(err)}`);
    })
  }
}
```

### setWaterMarkFlag

setWaterMarkFlag(enable: boolean): Promise&lt;void&gt;

Adds or deletes the watermark flag for this window. This API uses a promise to return the result.
> **NOTE**
>
> With the watermark flag added, the watermark is applied on the full screen when the window is in the foreground, regardless of whether the window is displayed in full screen, floating, and split screen mode.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name | Type    | Mandatory | Description                                           |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | Yes  | Whether to add or delete the flag. The value **true** means to add the watermark flag, and **false** means to delete the watermark flag. |

**Return value** 

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

| ID | Error Message |
| ------- | ---------------------------------------------- |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The operation is on invalid display. |

**Example** 

```ts
// ExtensionProvider.ts
import { UIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Add the watermark flag.
    extensionHostWindow.setWaterMarkFlag(true).then(() => {
      console.log(`Succeeded in setting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.log(`Failed to setting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    const extensionHostWindow = session.getUIExtensionHostWindowProxy();
    // Delete the watermark flag.
    extensionHostWindow.setWaterMarkFlag(false).then(() => {
      console.log(`Succeeded in deleting water mark flag of window.`);
    }).catch((err: BusinessError) => {
      console.log(`Failed to deleting water mark flag of window. Cause:${JSON.stringify(err)}`);
    })
  }
}
```

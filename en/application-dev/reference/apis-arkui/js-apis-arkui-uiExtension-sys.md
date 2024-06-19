# @ohos.arkui.uiExtension (uiExtension) (System API)

The **uiExtension** module provides APIs for the EmbeddedUIExtensionAbility (or UIExtensionAbility) to obtain the host application window information or the information about the corresponding **\<EmbeddedComponent>** (or **\<UIExtensionComponent>**).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.arkui.uiExtension (uiExtension)](js-apis-arkui-uiExtension.md).

## Modules to Import

```
import uiExtension from '@ohos.arkui.uiExtension'
```

## WindowProxy

### hideNonSecureWindows

hideNonSecureWindows(shouldHide: boolean): Promise\<void>

Sets whether to hide insecure windows.

> **NOTE**
>
> Insecure windows refer to the windows that may block the **\<EmbeddedComponent>** (or **\<UIExtensionComponent>**), such as non-system global floating windows and host subwindows. When the **\<EmbeddedComponent>** (or **\<UIExtensionComponent>**) is used to present important information, you can hide insecure windows to prevent such information from being blocked. When the **\<EmbeddedComponent>** (or **\<UIExtensionComponent>**) is not displayed or is destroyed, you must unhide the insecure windows.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | Yes  | Whether to hide insecure windows. The value **true** means to hide insecure windows, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
import uiExtension from '@ohos.arkui.uiExtension';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

// When 'onSessionCreate' of EmbeddedUIExtensionAbility is executed, the UIExtensionContentSession instance is stored in storage.
session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
// Obtain the WindowProxy instance of the current EmbeddedUIExtensionAbility from the session.
extensionWindow: uiExtension.WindowProxy | undefined = this.session?.getUIExtensionWindowProxy();
// Hide insecure windows.
let promise = this.extensionWindow?.hideNonSecureWindows(true);
promise?.then(()=> {
  console.log(`Succeeded in hiding the non-secure windows.`);
}).catch((err: BusinessError)=> {
  console.log(`Failed to hide the non-secure windows. Cause:${JSON.stringify(err)}`);
})
// Unhide insecure windows.
let promise = this.extensionWindow?.hideNonSecureWindows(false);
promise?.then(()=> {
  console.log(`Succeeded in showing the non-secure windows.`);
}).catch((err: BusinessError)=> {
  console.log(`Failed to show the non-secure windows. Cause:${JSON.stringify(err)}`);
})
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

| Name| Type    | Mandatory| Description                                           |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | Yes  | Whether to add or delete the flag. The value **true** means to add the watermark flag, and **false** means to delete the watermark flag.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | ---------------------------------------------- |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |

**Example**

```ts
import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
import uiExtension from '@ohos.arkui.uiExtension';
import window from '@ohos.window';
import { BusinessError } from '@ohos.base';

// When 'onSessionCreate' of EmbeddedUIExtensionAbility is executed, the UIExtensionContentSession instance is stored in storage.
session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
// Obtain the WindowProxy instance of the current EmbeddedUIExtensionAbility from the session.
extensionWindow: uiExtension.WindowProxy | undefined = this.session?.getUIExtensionWindowProxy();
// Add the watermark flag.
let promise = this.extensionWindow?.setWaterMarkFlag(true);
promise?.then(() => {
  console.log(`Succeeded in setting water mark flag of window.`);
}).catch((err: BusinessError) => {
  console.log(`Failed to setting water mark flag of window. Cause:${JSON.stringify(err)}`);
})
// Delete the watermark flag.
let promise = this.extensionWindow?.setWaterMarkFlag(false);
promise?.then(() => {
  console.log(`Succeeded in deleting water mark flag of window.`);
}).catch((err: BusinessError) => {
  console.log(`Failed to deleting water mark flag of window. Cause:${JSON.stringify(err)}`);
})
```

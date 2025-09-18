# @ohos.display (Display) (System API)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk; @logn-->
<!--Designer: @hejunfei1991-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

The Display module provides APIs for managing displays, such as obtaining information about the default display, obtaining information about all displays, and listening for the addition and removal of displays.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.display (Display)](js-apis-display.md).

## Modules to Import

```ts
import { display } from '@kit.ArkUI';
```

## display.hasPrivateWindow<sup>9+</sup>

hasPrivateWindow(displayId: number): boolean

Checks whether there is a visible privacy window on a display. The privacy window can be set by calling [setWindowPrivacyMode()](arkts-apis-window-Window.md#setwindowprivacymode9). The content in the privacy window cannot be captured or recorded.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- |----------|
| displayId    | number                    | Yes  | ID of the display. The value must be an integer greater than or equal to 0.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- |-----------------------------------------------------------------------|
|boolean | Whether there is a visible privacy window on the display. **true** if yes, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
try {
  displayClass = display.getDefaultDisplaySync();

  let ret: boolean = true;
  try {
    ret = display.hasPrivateWindow(displayClass.id);
  } catch (exception) {
    console.error(`Failed to check has privateWindow or not. Code: ${exception.code} , message : ${exception.message}`);
  }
  if (ret == undefined) {
    console.error("Failed to check has privateWindow or not.");
  }
  if (ret) {
    console.info("There has privateWindow.");
  } else if (!ret) {
    console.info("There has no privateWindow.");
  }
} catch (exception) {
  console.error(`Failed to obtain the default display object. Code: ${exception.code} , message : ${exception.message}`);
}
```

## display.on('privateModeChange')<sup>10+</sup>

on(type: 'privateModeChange', callback: Callback&lt;boolean&gt;): void

Subscribes to privacy mode changes of this display. When there is a privacy window in the foreground of the display, the display is in privacy mode, and the content in the privacy window cannot be captured or recorded.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The value is fixed at **'privateModeChange'**, indicating that the privacy mode of the display is changed.|
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return whether the privacy mode of the display is changed. **true** if changed, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
import { Callback } from '@kit.BasicServicesKit';

let callback: Callback<boolean> = (data: boolean) => {
  console.info(`Listening enabled. Data: ${data}`);
};
try {
  display.on("privateModeChange", callback);
} catch (exception) {
  console.error(`Failed to register callback. Code: ${exception.code} , message : ${exception.message}`);
}
```

## display.off('privateModeChange')<sup>10+</sup>

off(type: 'privateModeChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from privacy mode changes of this display. When there is a privacy window in the foreground of the display, the display is in privacy mode, and the content in the privacy window cannot be captured or recorded.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The value is fixed at **'privateModeChange'**, indicating that the privacy mode of the display is changed.|
| callback | Callback&lt;boolean&gt; | No  | Callback used to return whether the privacy mode of the display is changed. **true** if changed, **false** otherwise. If this parameter is not specified, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|

**Example**

```ts
try {
  display.off("privateModeChange");
} catch (exception) {
  console.error(`Failed to unregister callback. Code: ${exception.code} , message : ${exception.message}`);
}
```

## display.setFoldDisplayMode<sup>10+</sup>
setFoldDisplayMode(mode: FoldDisplayMode): void

Sets the display mode of the foldable device.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API has no effect and does not report errors for 2-in-1 devices. For other devices, this API can be called properly.

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| mode     | [FoldDisplayMode](js-apis-display.md#folddisplaymode10)    | Yes  | Display mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

try {
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_FULL;
  display.setFoldDisplayMode(mode);
} catch (exception) {
  console.error(`Failed to change the fold display mode. Code: ${exception.code} , message : ${exception.message}`);
}
```

## display.setFoldDisplayMode<sup>19+</sup>
setFoldDisplayMode(mode: FoldDisplayMode, reason: string): void

Sets the display mode of the foldable device, with the reason for the change specified. This API is unavailable for 2-in-1 devices.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| mode     | [FoldDisplayMode](js-apis-display.md#folddisplaymode10)    | Yes  | Display mode.|
| reason     | string    | Yes  | Reason for changing the display mode. If this parameter is not set, an empty string is used by default.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

try {
  let mode: display.FoldDisplayMode = display.FoldDisplayMode.FOLD_DISPLAY_MODE_MAIN;
  display.setFoldDisplayMode(mode, 'backSelfie');
} catch (exception) {
  console.error(`Failed to change the fold display mode. Code: ${exception}`);
}
```

## display.setFoldStatusLocked<sup>11+</sup>
setFoldStatusLocked(locked: boolean): void

Sets whether to lock the current fold status of the foldable device.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| locked     | boolean    | Yes  | Whether to lock the current fold status of the foldable device. **true** to lock, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.|
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';

try {
  let locked: boolean = false;
  display.setFoldStatusLocked(locked);
} catch (exception) {
  console.error(`Failed to change the fold status locked mode. Code: ${exception.code} , message : ${exception.message}`);
}
```

## display.addVirtualScreenBlocklist<sup>18+</sup>
addVirtualScreenBlocklist(windowIds: Array\<number>): Promise\<void>

Adds windows to the list of windows that are not allowed to be displayed during casting. This API takes effect only for the main window of an application or system windows. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| windowIds     | Array\<number>    | Yes  | List of window IDs. If a child window ID is passed in, it will not take effect. The window ID is an integer greater than 0. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.|
| 801     | Capability not supported.Function addVirtualScreenBlocklist can not work correctly due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display, window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    let windowId = windowStage.getMainWindowSync().getWindowProperties().id;
    let windowIds = [windowId];

    let promise = display.addVirtualScreenBlocklist(windowIds);
    promise.then(() => {
      console.info('Succeeded in adding virtual screen blocklist.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to add virtual screen blocklist. Code: ${err.code} , message : ${err.message}`);
    })
  }
}
```

## display.removeVirtualScreenBlocklist<sup>18+</sup>
removeVirtualScreenBlocklist(windowIds: Array\<number>): Promise\<void>

Removes windows from the list of windows that are not allowed to be displayed during casting. This API takes effect only for the main window of an application or system windows. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| windowIds     | Array\<number>    | Yes  | List of window IDs. If a child window ID is passed in, it will not take effect. The window ID is an integer greater than 0. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.|
| 801     | Capability not supported.Function removeVirtualScreenBlocklist can not work correctly due to limited device capabilities. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display, window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    let windowId = windowStage.getMainWindowSync().getWindowProperties().id;
    let windowIds = [windowId];

    let promise = display.addVirtualScreenBlocklist(windowIds);
    promise.then(() => {
      console.info('Succeeded in adding virtual screen blocklist.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to add virtual screen blocklist. Code: ${err.code} , message : ${err.message}`);
    })

    promise = display.removeVirtualScreenBlocklist(windowIds);
    promise.then(() => {
      console.info('Succeeded in removing virtual screen blocklist.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to remove virtual screen blocklist. Code: ${err.code} , message: ${err.message}`);
    })
  }
}
```

## Display
Implements a Display instance, with properties and APIs defined.

Before calling any API in Display, you must use [getAllDisplays()](js-apis-display.md#displaygetalldisplays9) or [getDefaultDisplaySync()](js-apis-display.md#displaygetdefaultdisplaysync9) to obtain a Display instance.

### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this display contains an immersive window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;boolean&gt;   | Yes  | Callback used to return the result. **true** if the display contains an immersive window, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
displayClass.hasImmersiveWindow((err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to check whether there is immersive window. Code: ${err.code} , message : ${err.message}`);
      return;
    }
    console.info(`Succeeded in checking whether there is immersive window. data: ${data}`);
});
```
### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(): Promise&lt;boolean&gt;

Checks whether this display contains an immersive window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. **true** if the display contains an immersive window, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { display } from '@kit.ArkUI';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
let promise = displayClass.hasImmersiveWindow();
promise.then((data) => {
  console.info(`Succeeded in checking whether there is immersive window. data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether there is immersive window. Code: ${err.code} , message: ${err.message}`);
})
```

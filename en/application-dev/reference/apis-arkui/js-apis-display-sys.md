# @ohos.display (Display) (System API)

The Display module provides APIs for managing displays, such as obtaining information about the default display, obtaining information about all displays, and listening for the addition and removal of displays.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohso.display (Display)](js-apis-display.md).

## Modules to Import

```ts
import { display } from '@kit.ArkUI';
```

## display.hasPrivateWindow<sup>9+</sup>

hasPrivateWindow(displayId: number): boolean

Checks whether there is a visible privacy window on a display. The privacy window can be set by calling [setWindowPrivacyMode()](js-apis-window.md#setwindowprivacymode9). The content in the privacy window cannot be captured or recorded.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- |----------|
| id     | number                    | Yes  | ID of the display. The value must be an integer greater than or equal to 0.|

**Return value**

| Type                            | Description                                                                   |
| -------------------------------- |-----------------------------------------------------------------------|
|boolean | Whether there is a visible privacy window on the display.<br>The value **true** means that there is a visible privacy window on the display, and **false** means the opposite.<br>|

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
    console.error('Failed to check has privateWindow or not. Code: ' + JSON.stringify(exception));
  }
  if (ret == undefined) {
    console.log("Failed to check has privateWindow or not.");
  }
  if (ret) {
    console.log("There has privateWindow.");
  } else if (!ret) {
    console.log("There has no privateWindow.");
  }
} catch (exception) {
  console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
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
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return whether the privacy mode of the display is changed. The value **true** means that the display changes to the privacy mode, and **false** means the opposite.|

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
  console.info('Listening enabled. Data: ' + JSON.stringify(data));
};
try {
  display.on("privateModeChange", callback);
} catch (exception) {
  console.error('Failed to register callback. Code: ' + JSON.stringify(exception));
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
| callback | Callback&lt;boolean&gt; | No  | Callback used to return whether the privacy mode of the display is changed. The value **true** means that the display changes to the privacy mode, and **false** means the opposite.|

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
  console.error('Failed to unregister callback. Code: ' + JSON.stringify(exception));
}
```

## display.setFoldDisplayMode<sup>10+</sup>
setFoldDisplayMode(mode: FoldDisplayMode): void

Sets the display mode of the foldable device.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

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
  console.error('Failed to change the fold display mode. Code: ' + JSON.stringify(exception));
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
| locked     | boolean    | Yes  | Whether to lock the current fold status of the foldable device. The value **true** means to lock the current fold status, and **false** means the opposite.|

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
  console.error('Failed to change the fold status locked mode. Code: ' + JSON.stringify(exception));
}
```

## Display
Implements a **Display** instance, with properties and APIs defined.

Before calling any API in **Display**, you must use [getAllDisplays()](js-apis-display.md#displaygetalldisplays9) or [getDefaultDisplaySync()](js-apis-display.md#displaygetdefaultdisplaysync9) to obtain a **Display** instance.

### hasImmersiveWindow<sup>11+</sup>
hasImmersiveWindow(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this display contains an immersive window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                       | Mandatory| Description                                                        |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback    | AsyncCallback&lt;boolean&gt;   | Yes  | Callback used to return the result. The value **true** means that the display contains an immersive window, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 801 | Capability not supported on this device. |
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
      console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
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
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the display contains an immersive window, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Display Error Codes](errorcode-display.md).

| ID| Error Message|
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.|
| 801 | Capability not supported on this device. |
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
  console.info('Succeeded in checking whether there is immersive window. data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error('Failed to check whether there is immersive window. Code: ' + JSON.stringify(err));
})
```

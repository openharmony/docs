# @ohos.window (Window) (System API)

The Window module provides basic window management capabilities, such as creating and destroying the current window, setting properties for the current window, and managing and scheduling windows.

This module provides the following common window-related functions:

- [Window](#window): window instance, which is the basic unit managed by the window manager.
- [WindowStage](#windowstage9): window manager that manages windows.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.window (Window)](js-apis-window.md).

## Modules to Import

```ts
import { window } from '@kit.ArkUI';
```

## WindowType<sup>7+</sup>


Enumerates the window types.


| Name                                 | Value| Description                                                                                    |
|-------------------------------------| ------ |----------------------------------------------------------------------------------------|
| TYPE_INPUT_METHOD<sup>(deprecated)</sup>      | 2      | Input method window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**NOTE**: This API is supported since API version 9 and deprecated since API version 13. There is no alternative window type. To control the input method, call [Input method framework APIs](../../inputmethod/inputmethod-application-guide.md).<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_STATUS_BAR<sup>9+</sup>        | 3      | Status bar.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_PANEL<sup>9+</sup>             | 4      | Notification panel.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_KEYGUARD<sup>9+</sup>          | 5      | Lock screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_VOLUME_OVERLAY<sup>9+</sup>    | 6      | Volume bar.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_NAVIGATION_BAR<sup>9+</sup>    | 7      | Navigation bar.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_WALLPAPER<sup>9+</sup>         | 9      | Wallpaper.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_DESKTOP<sup>9+</sup>           | 10      | Home screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_LAUNCHER_RECENT<sup>9+</sup>   | 11      | Recent tasks screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_LAUNCHER_DOCK<sup>9+</sup>     | 12      | Dock bar on the home screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_VOICE_INTERACTION<sup>9+</sup> | 13      | Voice assistant.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_POINTER<sup>9+</sup>           | 14      | Mouse.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_FLOAT_CAMERA<sup>9+</sup>      | 15      | Floating camera window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_SCREENSHOT<sup>9+</sup>        | 17      | Screenshot window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_SYSTEM_TOAST<sup>11+</sup>     | 18      | Toast displayed at the top.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_DIVIDER<sup>11+</sup>          | 19      | Divider.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_GLOBAL_SEARCH<sup>11+</sup>    | 20      | Window used for global search.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| TYPE_HANDWRITE<sup>12+</sup>        | 21      | Stylus window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|

## WindowMode<sup>7+</sup>

Enumerates the window modes.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 1    | The window mode is not defined by the application.      |
| FULLSCREEN | 2    | The application is displayed in full screen.            |
| PRIMARY    | 3    | The application is displayed in the primary window in split-screen mode.  |
| SECONDARY  | 4    | The application is displayed in the secondary window in split-screen mode.  |
| FLOATING   | 5    | The application is displayed in a floating window.|

## WindowLayoutMode<sup>9+</sup>

Enumerates the window layout modes.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| WINDOW_LAYOUT_MODE_CASCADE  | 0    | Cascade mode.      |
| WINDOW_LAYOUT_MODE_TILE | 1    | Tile mode.            |


## BlurStyle<sup>9+</sup>

Enumerates the window blur styles.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name   | Value  | Description                |
| ------- | ---- | -------------------- |
| OFF     | 0    | Blur disabled.      |
| THIN    | 1    | Thin blur.|
| REGULAR | 2    | Regular blur.|
| THICK   | 3    | Thick blur.|

## SystemBarRegionTint<sup>8+</sup>

Describes the callback for a single system bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name           | Type                 | Readable| Writable| Description                                                        |
| --------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type            | [WindowType](#windowtype7) | Yes  | No  | Type of the system bar whose properties are changed. Only the status bar and navigation bar are supported.|
| isEnable        | boolean                   | Yes  | No  | Whether the system bar is displayed. The value **true** means that the system bar is displayed, and **false** means the opposite.|
| region          | [Rect](js-apis-window.md#rect7)             | Yes  | No  | Current position and size of the system bar.                                    |
| backgroundColor | string                    | Yes  | No  | Background color of the system bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**.|
| contentColor    | string                    | Yes  | No  | Color of the text on the system bar.                                            |

## SystemBarTintState<sup>8+</sup>

Describes the callback for the current system bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Type                                           | Readable| Writable| Description                        |
| ---------- | --------------------------------------------------- | ---- | ---- | ---------------------------- |
| displayId  | number                                              | Yes  | No  | ID of the current physical screen. The value must be an integer.            |
| regionTint | Array<[SystemBarRegionTint](#systembarregiontint8)> | Yes  | No  | All system bar information that has been changed.|

## ScaleOptions<sup>9+</sup>

Describes the scale parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Read Only| Mandatory| Description                                        |
| ------ | -------- | ---- | ---- | --------------------------------------------|
| x      | number   | No  | No  | Scale factor along the x-axis. The value is a floating point number, and the default value is **1.0**.                  |
| y      | number   | No  | No  | Scale factor along the y-axis. The value is a floating point number, and the default value is **1.0**.                  |
| pivotX | number   | No  | No  | X coordinate of the scale center. The value is a floating point number in the range [0.0, 1.0], and the default value is **0.5**.|
| pivotY | number   | No  | No  | Y coordinate of the scale center. The value is a floating point number in the range [0.0, 1.0], and the default value is **0.5**.|

## RotateOptions<sup>9+</sup>

Describes the rotation parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Read Only| Mandatory| Description                                         |
| ------ | -------- | ---- |---- |---------------------------------------------|
| x      | number   | No  | No | Rotation angle around the x-axis. The value is a floating point number, and the default value is **0.0**.                  |
| y      | number   | No  | No | Rotation angle around the y-axis. The value is a floating point number, and the default value is **0.0**.                  |
| z      | number   | No  | No | Rotation angle around the z-axis. The value is a floating point number, and the default value is **0.0**.                  |
| pivotX | number   | No  | No | X coordinate of the rotation center. The value is a floating point number in the range [0.0, 1.0], and the default value is **0.5**.|
| pivotY | number   | No  | No | Y coordinate of the rotation center. The value is a floating point number in the range [0.0, 1.0], and the default value is **0.5**. |

## TranslateOptions<sup>9+</sup>

Describes the translation parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Read Only| Mandatory| Description                        |
| ---- | -------- | ---- | ---- | ---------------------------- |
| x    | number   | No  | No | Distance to translate along the x-axis. The value is a floating point number, the default value is 0.0, and the unit is px.|
| y    | number   | No  | No | Distance to translate along the y-axis. The value is a floating point number, the default value is 0.0, and the unit is px.|
| z    | number   | No  | No | Distance to translate along the z-axis. The value is a floating point number, the default value is 0.0, and the unit is px.|

## WindowInfo<sup>12+</sup>

Describes the window information.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| rect  | [Rect](js-apis-window.md#rect7)   | Yes  | No  | Size of the rectangle that can be drawn in the window. The upper boundary and left boundary are calculated relative to the window.|
| bundleName  | string   | Yes  | No  | Bundle name.         |
| abilityName | string   | Yes  | No  | Ability name.              |
| windowId | number | Yes  | No  | Window ID.  |
| windowStatusType | [WindowStatusType](js-apis-window.md#windowstatustype11) | Yes  | No  | Window mode.  |

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

Minimizes all windows on a display. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | Yes  | ID of the [display](js-apis-display.md#display). The value must be an integer.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();

try {
  window.minimizeAll(displayClass.id, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to minimize all windows. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in minimizing all windows.');
  });
} catch (exception) {
  console.error(`Failed to minimize all windows. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number): Promise&lt;void&gt;

Minimizes all windows on a display. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | Yes  | ID of the [display](js-apis-display.md#display). The value must be an integer.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { display } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();

try {
  let promise = window.minimizeAll(displayClass.id);
  promise.then(() => {
    console.info('Succeeded in minimizing all windows.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to minimize all windows. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to minimize all windows. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.toggleShownStateForAllAppWindows<sup>9+</sup>
toggleShownStateForAllAppWindows(callback: AsyncCallback&lt;void&gt;): void

Hides or restores the application's windows during quick multi-window switching. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

window.toggleShownStateForAllAppWindows((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to toggle shown state for all app windows. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in toggling shown state for all app windows.');
});
```

## window.toggleShownStateForAllAppWindows<sup>9+</sup>
toggleShownStateForAllAppWindows(): Promise&lt;void&gt;

Hides or restores the application's windows during quick multi-window switching. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = window.toggleShownStateForAllAppWindows();
promise.then(() => {
  console.info('Succeeded in toggling shown state for all app windows.');
}).catch((err: BusinessError) => {
  console.error(`Failed to toggle shown state for all app windows. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback&lt;void&gt;): void

Sets the window layout mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                  | Yes  | Window layout mode to set.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set window layout mode. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting window layout mode.');
  });
} catch (exception) {
  console.error(`Failed to set window layout mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode): Promise&lt;void&gt;

Sets the window layout mode. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                    | Yes  | Window layout mode to set.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE);
  promise.then(() => {
    console.info('Succeeded in setting window layout mode.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window layout mode. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set window layout mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('systemBarTintChange')<sup>8+</sup>

on(type: 'systemBarTintChange', callback: Callback&lt;SystemBarTintState&gt;): void

Subscribes to the property change event of the status bar and navigation bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | Yes  | Event type. The value is fixed at **'systemBarTintChange'**, indicating the property change event of the status bar and navigation bar.|
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | Yes  | Callback used to return the properties of the status bar and navigation bar.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |

**Example**

```ts
try {
  window.on('systemBarTintChange', (data) => {
    console.info('Succeeded in enabling the listener for systemBarTint changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for systemBarTint changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.off('systemBarTintChange')<sup>8+</sup>

off(type: 'systemBarTintChange', callback?: Callback&lt;SystemBarTintState &gt;): void

Unsubscribes from the property change event of the status bar and navigation bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | Yes  | Event type. The value is fixed at **'systemBarTintChange'**, indicating the property change event of the status bar and navigation bar.|
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | No  | Callback used to return the properties of the status bar and navigation bar. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed.              |

**Example**

```ts
const callback = (systemBarTintState: window.SystemBarTintState) => {
  // ...
}
try {
  window.on('systemBarTintChange', callback);

  window.off('systemBarTintChange', callback);
  // Unregister all the callbacks that have been registered through on().
  window.off('systemBarTintChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for systemBarTint changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('gestureNavigationEnabledChange')<sup>10+</sup>

on(type: 'gestureNavigationEnabledChange', callback: Callback&lt;boolean&gt;): void

Subscribes to the gesture navigation status change event.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                                         |
| -------- | ----------------------- | ---- | ----------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The value is fixed at **'gestureNavigationEnabledChange'**, indicating the gesture navigation status change event.   |
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return the gesture navigation status. The value **true** means that the gesture navigation status is changed to enabled, and **false** means that the gesture navigation status is changed to disabled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
try {
  window.on('gestureNavigationEnabledChange', (data) => {
    console.info('Succeeded in enabling the listener for gesture navigation status changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for gesture navigation status changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.off('gestureNavigationEnabledChange')<sup>10+</sup>

off(type: 'gestureNavigationEnabledChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the gesture navigation status change event.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                       |
| -------- | ----------------------- | -- | ------------------------------------------------------------ |
| type     | string                  | Yes| Event type. The value is fixed at **'gestureNavigationEnabledChange'**, indicating the gesture navigation status change event.|
| callback | Callback&lt;boolean&gt; | No| Callback function that has been used for the subscription. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  window.on('gestureNavigationEnabledChange', callback);
  window.off('gestureNavigationEnabledChange', callback);
  // Unregister all the callbacks that have been registered through on().
  window.off('gestureNavigationEnabledChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for gesture navigation status changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('waterMarkFlagChange')<sup>10+</sup>

on(type: 'waterMarkFlagChange', callback: Callback&lt;boolean&gt;): void

Subscribes to the watermark status change event.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                                         |
| -------- | ----------------------- | ---- | ----------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The value is fixed at **'waterMarkFlagChange'**, indicating the watermark status change event.   |
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return the watermark status. The value **true** means that the watermark feature is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
try {
  window.on('waterMarkFlagChange', (data) => {
    console.info('Succeeded in enabling the listener for watermark flag changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for watermark flag changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.off('waterMarkFlagChange')<sup>10+</sup>

off(type: 'waterMarkFlagChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the watermark status change event.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                       |
| -------- | ----------------------- | -- | ------------------------------------------------------------ |
| type     | string                  | Yes| Event type. The value is fixed at **'waterMarkFlagChange'**, indicating the watermark status change event.|
| callback | Callback&lt;boolean&gt; | No| Callback function that has been used for the subscription. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  window.on('waterMarkFlagChange', callback);
  window.off('waterMarkFlagChange', callback);
  // Unregister all the callbacks that have been registered through on().
  window.off('waterMarkFlagChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for watermark flag changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setGestureNavigationEnabled<sup>10+</sup>
setGestureNavigationEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Enables or disables gesture navigation. This API uses an asynchronous callback to return the result.

For security purposes, the system does not interfere with the disabling and enabling of gesture navigation. If an application exits abnormally after it disables gesture navigation and wants to restore gesture navigation, it must implement automatic launch and call this API again to enable gesture navigation.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| enable   | boolean                  | Yes  | Whether to enable gesture navigation. The value **true** means to enable gesture navigation, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  window.setGestureNavigationEnabled(true, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set gesture navigation enabled. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting gesture navigation enabled.');
  });
} catch (exception) {
  console.error(`Failed to set gesture navigation enabled. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setGestureNavigationEnabled<sup>10+</sup>
setGestureNavigationEnabled(enable: boolean): Promise&lt;void&gt;

Enables or disables gesture navigation. This API uses a promise to return the result.

For security purposes, the system does not interfere with the disabling and enabling of gesture navigation. If an application exits abnormally after it disables gesture navigation and wants to restore gesture navigation, it must implement automatic launch and call this API again to enable gesture navigation.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type    | Mandatory | Description                |
| ------ | ------- | ---- | -------------------- |
| enable | boolean | Yes  | Whether to enable gesture navigation. The value **true** means to enable gesture navigation, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = window.setGestureNavigationEnabled(true);
  promise.then(() => {
    console.info('Succeeded in setting gesture navigation enabled.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set gesture navigation enabled. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set gesture navigation enabled. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setWaterMarkImage<sup>10+</sup>
setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the watermark image display status. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes| Watermark image.|
| enable   | boolean                  | Yes  | Whether to display the watermark image. The value **true** means to display the watermark image, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;
let color: ArrayBuffer = new ArrayBuffer(0);
let initializationOptions: image.InitializationOptions = {
  size: {
    height: 100,
    width: 100
  }
};
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelmap.');
  try {
    window.setWaterMarkImage(pixelMap, enable, (err: BusinessError) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to show watermark image. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in showing watermark image.');
    });
  } catch (exception) {
    console.error(`Failed to show watermark image. Cause code: ${exception.code}, message: ${exception.message}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to create PixelMap. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.setWaterMarkImage<sup>10+</sup>
setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean): Promise&lt;void&gt;

Sets the watermark image display status. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                       | Mandatory | Description                |
| ------ | --------------------------- | ---- | -------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes| Watermark image.|
| enable   | boolean                  | Yes  | Whether to display the watermark image. The value **true** means to display the watermark image, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;
let color: ArrayBuffer = new ArrayBuffer(0);
let initializationOptions: image.InitializationOptions = {
  size: {
    height: 100,
    width: 100
  }
};
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelmap.');
  try {
    let promise = window.setWaterMarkImage(pixelMap, enable);
    promise.then(() => {
      console.info('Succeeded in showing watermark image.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to show watermark image. Cause code: ${err.code}, message: ${err.message}`);
    });
  } catch (exception) {
    console.error(`Failed to show watermark image. Cause code: ${exception.code}, message: ${exception.message}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to create PixelMap. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.getSnapshot<sup>12+</sup>

getSnapshot(windowId: number): Promise<image.PixelMap>

Captures a window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
| Name  | Type  | Mandatory | Description        |
| -------- | ------ | ----- | ------------ |
| windowId | number | Yes   | Window ID. You can call [getWindowProperties](js-apis-window.md#getwindowproperties9) to obtain the window properties, in which **id** is the window ID.|

**Return value**
| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Promise<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | Promise used to return the window screenshot.|

**Error codes**
For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |
| 1300004  | This operation is not accessible.             |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

try {
  // This is only an example. Use getWindowProperties to obtain the window ID.
  let windowId: number = 40;
  let promise = window.getSnapshot(windowId);
  promise.then((pixelMap: image.PixelMap) => {
    console.info('Succeeded in getting snapshot window. Pixel bytes number:' + pixelMap.getPixelBytesNumber());
    pixelMap.release();
  }).catch((err: BusinessError) =>{
    console.error(`Failed to get snapshot. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to get snapshot. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getVisibleWindowInfo<sup>12+</sup>

getVisibleWindowInfo(): Promise&lt;Array&lt;WindowInfo&gt;&gt;

Obtains information about visible windows on the current screen. Visible windows are windows that are not returned to the background.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager


**Return value**

| Type| Description|
| ------------------- | ----------------------- |
| Promise&lt;[WindowInfo](#windowinfo12)&gt; | Promise used to return the information about visible windows.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let promise = window.getVisibleWindowInfo();
promise.then((data) => {
  data.forEach(windowInfo=>{
    console.info(`left:${windowInfo.rect.left}`);
    console.info(`top:${windowInfo.rect.top}`);
    console.info(`width:${windowInfo.rect.width}`);
    console.info(`height:${windowInfo.rect.height}`);
    console.info(`windowId:${windowInfo.windowId}`);
    console.info(`windowStatusType:${windowInfo.windowStatusType}`);
    console.info(`abilityName:${windowInfo.abilityName}`);
    console.info(`bundleName:${windowInfo.bundleName}`);
  })
}).catch((err: BusinessError) => {
  console.error('Failed to getWindowInfo. Cause: ' + JSON.stringify(err));
});
```

## Window

Represents a window instance, which is the basic unit managed by the window manager.

In the following API examples, you must use [getLastWindow()](js-apis-window.md#windowgetlastwindow9), [createWindow()](js-apis-window.md#windowcreatewindow9), or [findWindow()](js-apis-window.md#windowfindwindow9) to obtain a **Window** instance (named windowClass in this example) and then call a method in this instance.

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

Hides this window. This API uses an asynchronous callback to return the result. This API takes effect only for a system window or an application subwindow.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.hide((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to hide the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in hiding the window.');
});
```

### hide<sup>7+</sup>

hide(): Promise&lt;void&gt;

Hides this window. This API uses a promise to return the result. This API takes effect only for a system window or an application subwindow.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.hide();
promise.then(() => {
  console.info('Succeeded in hiding the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(callback: AsyncCallback&lt;void&gt;): void

Hides this window and plays an animation during the process. This API uses an asynchronous callback to return the result. This API takes effect only for a system window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.hideWithAnimation((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to hide the window with animation. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in hiding the window with animation.');
});
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(): Promise&lt;void&gt;

Hides this window and plays an animation during the process. This API uses a promise to return the result. This API takes effect only for a system window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.hideWithAnimation();
promise.then(() => {
  console.info('Succeeded in hiding the window with animation.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide the window with animation. Cause code: ${err.code}, message: ${err.message}`);
});
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(callback: AsyncCallback&lt;void&gt;): void

Shows this window and plays an animation during the process. This API uses an asynchronous callback to return the result. This API takes effect only for a system window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.showWithAnimation((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to show the window with animation. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in showing the window with animation.');
});
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(): Promise&lt;void&gt;

Shows this window and plays an animation during the process. This API uses a promise to return the result. This API takes effect only for a system window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.showWithAnimation();
promise.then(() => {
  console.info('Succeeded in showing the window with animation.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show the window with animation. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setWindowMode<sup>9+</sup>

setWindowMode(mode: WindowMode, callback: AsyncCallback&lt;void&gt;): void

Sets the mode of the main window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------- | -- | --------- |
| mode     | [WindowMode](#windowmode7) | Yes| Window mode to set.|
| callback | AsyncCallback&lt;void&gt;  | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let mode = window.WindowMode.FULLSCREEN;
      try {
        windowClass.setWindowMode(mode, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the window mode. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the window mode.');
        });
      } catch (exception) {
        console.error(`Failed to set the window mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowMode<sup>9+</sup>

setWindowMode(mode: WindowMode): Promise&lt;void&gt;

Sets the mode of the main window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------- | -- | --------- |
| mode     | [WindowMode](#windowmode7) | Yes| Window mode to set.|

**Return value**

| Type| Description|
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let mode = window.WindowMode.FULLSCREEN;
      try {
        let promise = windowClass.setWindowMode(mode);
        promise.then(() => {
          console.info('Succeeded in setting the window mode.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window mode. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the window mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;, callback: AsyncCallback&lt;void&gt;): void

Binds the modal window to the target window, and adds a callback to listen for modal window destruction events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                     | Mandatory| Description                 |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) | Yes  | Token of the target window.|
| deathCallback | Callback&lt;void&gt;        | Yes  | Callback used to listen for modal window destruction events.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyDeathRecipient {
  onRemoteDied() {
    console.log('server died');
  }
}

class TestRemoteObject extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }

  addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  isObjectDead(): boolean {
    return false;
  }
}

let token: TestRemoteObject = new TestRemoteObject('testObject');
let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = { name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context };
try {
  window.createWindow(config, (err: BusinessError, data) => {
    let errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    windowClass = data;
  });
  windowClass.bindDialogTarget(token, () => {
    console.info('Dialog Window Need Destroy.');
  }, (err: BusinessError) => {
    let errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in binding dialog target.');
  });
} catch (exception) {
  console.error(`Failed to bind dialog target. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;): Promise&lt;void&gt;

Binds the modal window to the target window, and adds a callback to listen for modal window destruction events. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                     | Mandatory| Description                 |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) | Yes  | Token of the target window.|
| deathCallback | Callback&lt;void&gt;        | Yes  | Callback used to listen for modal window destruction events.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyDeathRecipient {
  onRemoteDied() {
    console.log('server died');
  }
}

class TestRemoteObject extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }

  addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
    return true;
  }

  isObjectDead(): boolean {
    return false;
  }
}

let token: TestRemoteObject = new TestRemoteObject('testObject');
let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "test",
  windowType: window.WindowType.TYPE_DIALOG,
  ctx: this.context
};
try {
  window.createWindow(config, (err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    windowClass = data;
  });
  let promise = windowClass.bindDialogTarget(token, () => {
    console.info('Dialog Window Need Destroy.');
  });
  promise.then(() => {
    console.info('Succeeded in binding dialog target.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to bind dialog target. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback&lt;void&gt;, callback: AsyncCallback&lt;void&gt;): void

Binds the modal window to the target window, and adds a callback to listen for modal window destruction events. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                     | Mandatory| Description                 |
| ----------- | ------------------------- | ---- | -------------------- |
| requestInfo | [dialogRequest.RequestInfo](../apis-ability-kit/js-apis-app-ability-dialogRequest.md#requestinfo) | Yes  | **RequestInfo** of the target window.|
| deathCallback | Callback&lt;void&gt;    | Yes  | Callback used to listen for modal window destruction events.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { dialogRequest, Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest');
    let windowClass: window.Window | undefined = undefined;
    let config: window.Configuration = {
      name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
      });
      let requestInfo = dialogRequest.getRequestInfo(want)
      windowClass.bindDialogTarget(requestInfo, () => {
        console.info('Dialog Window Need Destroy.');
      }, (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in binding dialog target.');
      });
    } catch (err) {
      console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`)
    }
  }
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback&lt;void&gt;): Promise&lt;void&gt;

Binds the modal window to the target window, and adds a callback to listen for modal window destruction events. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                     | Mandatory| Description                 |
| ----------- | ------------------------- | ---- | -------------------- |
| requestInfo | [dialogRequest.RequestInfo](../apis-ability-kit/js-apis-app-ability-dialogRequest.md#requestinfo) | Yes  | **RequestInfo** of the target window.|
| deathCallback | Callback&lt;void&gt;    | Yes  | Callback used to listen for modal window destruction events.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { dialogRequest, Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest');
    let windowClass: window.Window | undefined = undefined;
    let config: window.Configuration = {
      name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
      });
      let requestInfo = dialogRequest.getRequestInfo(want)
      let promise = windowClass.bindDialogTarget(requestInfo, () => {
        console.info('Dialog Window Need Destroy.');
      });
      promise.then(() => {
        console.info('Succeeded in binding dialog target.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (err) {
      console.error(`Failed to bind dialog target. Cause code: ${err.code}, message: ${err.message}`)
    }
  }
}
```

### setWakeUpScreen<sup>9+</sup>

setWakeUpScreen(wakeUp: boolean): void

Wakes up the screen.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| wakeUp           | boolean | Yes  | Whether to wake up the screen. The value **true** means to wake up the screen, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
let wakeUp: boolean = true;
try {
  windowClass.setWakeUpScreen(wakeUp);
} catch (exception) {
  console.error(`Failed to wake up the screen. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setSnapshotSkip<sup>9+</sup>
setSnapshotSkip(isSkip: boolean): void

Sets whether to ignore this window during screen capturing or recording. This API is generally used in scenarios where screen capture or recording is disabled.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type   | Mandatory| Description                |
| ------------- | ------- | ---- | -------------------- |
| isSkip | boolean | Yes  | Whether to ignore the window. The default value is **false**.<br>The value **true** means that the window is ignored, and **false** means the opposite.<br>|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

```ts
let isSkip: boolean = true;
try {
  windowClass.setSnapshotSkip(isSkip);
} catch (exception) {
  console.error(`Failed to Skip. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the main window is forbidden to move in split-screen mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                     | Mandatory| Description                |
| ----------- | ------------------------- | ---- | -------------------- |
| isForbidSplitMove | boolean                   | Yes  | Whether the window is forbidden to move in split-screen mode. The value **true** means the window is forbidden to move in split-screen mode, and **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isForbidSplitMove: boolean = true;
      try {
        windowClass.setForbidSplitMove(isForbidSplitMove, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to forbid window moving in split screen mode. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in forbidding window moving in split screen mode.');
        });
      } catch (exception) {
        console.error(`Failed to forbid window moving in split screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean): Promise&lt;void&gt;

Sets whether the main window is forbidden to move in split-screen mode. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type   | Mandatory| Description                |
| ----------- | ------- | ---- | -------------------- |
| isForbidSplitMove | boolean | Yes  | Whether the window is forbidden to move in split-screen mode. The value **true** means the window is forbidden to move in split-screen mode, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let isForbidSplitMove: boolean = true;
      try {
        let promise = windowClass.setForbidSplitMove(isForbidSplitMove);
        promise.then(() => {
          console.info('Succeeded in forbidding window moving in split screen mode.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to forbid window moving in split screen mode. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to forbid window moving in split screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### opacity<sup>9+</sup>

opacity(opacity: number): void

Sets the opacity for this window. This API can be used only when you [customize an animation to be played during the display or hiding of a system window](../../windowmanager/system-window-stage.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window).

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                |
| ------- | ------ | ---- |----------------------------------------------------|
| opacity | number | Yes  | Opacity. The value is a floating point number in the range [0.0, 1.0]. The value **0.0** means completely transparent, and **1.0** means completely opaque.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
try {
  windowClass.opacity(0.5);
} catch (exception) {
  console.error(`Failed to opacity. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### scale<sup>9+</sup>

scale(scaleOptions: ScaleOptions): void

Sets the scale parameters for this window. This API can be used only when you [customize an animation to be played during the display or hiding of a system window](../../windowmanager/system-window-stage.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window).

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                          | Mandatory| Description      |
| ------------ | ------------------------------ | ---- | ---------- |
| scaleOptions | [ScaleOptions](#scaleoptions9) | Yes  | Scale parameters to set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
let obj: window.ScaleOptions = {
  x: 2.0,
  y: 1.0,
  pivotX: 0.5,
  pivotY: 0.5
};
try {
  windowClass.scale(obj);
} catch (exception) {
  console.error(`Failed to scale. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### rotate<sup>9+</sup>

rotate(rotateOptions: RotateOptions): void

Sets the rotation parameters for this window. This API can be used only when you [customize an animation to be played during the display or hiding of a system window](../../windowmanager/system-window-stage.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window).

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type                            | Mandatory| Description      |
| ------------- | -------------------------------- | ---- | ---------- |
| rotateOptions | [RotateOptions](#rotateoptions9) | Yes  | Rotation parameters to set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
let obj: window.RotateOptions = {
  x: 1.0,
  y: 1.0,
  z: 45.0,
  pivotX: 0.5,
  pivotY: 0.5
};
try {
  windowClass.rotate(obj);
} catch (exception) {
  console.error(`Failed to rotate. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### translate<sup>9+</sup>

translate(translateOptions: TranslateOptions): void

Sets the translation parameters for this window. This API can be used only when you [customize an animation to be played during the display or hiding of a system window](../../windowmanager/system-window-stage.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window).

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type                                  | Mandatory| Description                |
| ---------------- | -------------------------------------- | ---- | -------------------- |
| translateOptions | [TranslateOptions](#translateoptions9) | Yes  | Translation parameters. The unit is px.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
let obj: window.TranslateOptions = {
  x: 100.0,
  y: 0.0,
  z: 0.0
};
try {
  windowClass.translate(obj);
} catch (exception) {
  console.error(`Failed to translate. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getTransitionController<sup>9+</sup>

 getTransitionController(): TransitionController

Obtains the transition animation controller.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                          | Description            |
| ---------------------------------------------- | ---------------- |
| [TransitionController](#transitioncontroller9) | Transition animation controller.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
let controller = windowClass.getTransitionController(); // Obtain the transition animation controller.
```

### setBlur<sup>9+</sup>

setBlur(radius: number): void

Blurs this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                              |
| ------ | ------ | ---- |--------------------------------------------------|
| radius | number | Yes  | Radius of the blur. The value is a floating point number greater than or equal to 0.0, in px. The value **0.0** means that the blur is disabled for the window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
try {
  windowClass.setBlur(4.0);
} catch (exception) {
  console.error(`Failed to set blur. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setBackdropBlur<sup>9+</sup>

setBackdropBlur(radius: number): void

Blurs the background of this window.

The window background refers to the lower-layer area covered by the window, which is the same as the window size.

To make the blur effect visible, you must set the window background transparent by calling [setWindowBackgroundColor](js-apis-window.md#setwindowbackgroundcolor9).

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                   |
| ------ | ------ | ---- |-------------------------------------------------------|
| radius | number | Yes  | Radius of the blur. The value is a floating point number greater than or equal to 0.0, in px. The value **0.0** means that the blur is disabled for the background of the window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
try {
  windowClass.setWindowBackgroundColor('#00FFFFFF');
  windowClass.setBackdropBlur(4.0);
} catch (exception) {
  console.error(`Failed to set backdrop blur. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setBackdropBlurStyle<sup>9+</sup>

setBackdropBlurStyle(blurStyle: BlurStyle): void

Sets the blur style for the background of this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type     | Mandatory| Description                  |
| --------- | --------- | ---- | ---------------------- |
| blurStyle | [BlurStyle](#blurstyle9) | Yes  | Blur style to set for the background of the window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
try {
  windowClass.setBackdropBlurStyle(window.BlurStyle.THIN);
} catch (exception) {
  console.error(`Failed to set backdrop blur style. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setShadow<sup>9+</sup>

setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void

Sets the shadow for the window borders.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                         |
| ------- | ------ | ---- |-------------------------------------------------------------|
| radius  | number | Yes  | Radius of the shadow. The value is a floating point number greater than or equal to 0.0, in px. The value **0.0** means that the shadow is disabled for the window borders.    |
| color   | string | No  | Color of the shadow. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**.|
| offsetX | number | No  | Offset of the shadow along the x-axis, in px. The value is a floating point number.                             |
| offsetY | number | No  | Offset of the shadow along the y-axis, in px. The value is a floating point number.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
try {
  windowClass.setShadow(4.0, '#FF00FF00', 2, 3);
} catch (exception) {
  console.error(`Failed to set shadow. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setCornerRadius<sup>9+</sup>

setCornerRadius(cornerRadius: number): void

Sets the radius of the rounded corners for this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                                |
| ----------- | ------- | ---- |----------------------------------------------------|
| cornerRadius | number | Yes  | Radius of the rounded corners. The value is a floating point number greater than or equal to 0.0, in px. The value **0.0** means that the window does not use rounded corners.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**Example**

```ts
try {
  windowClass.setCornerRadius(4.0);
} catch (exception) {
  console.error(`Failed to set corner radius. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTouchableAreas<sup>12+</sup>

setTouchableAreas(rects: Array&lt;Rect&gt;): void

Sets the touchable areas for this window. By default, the entire window is touchable. If a touchable area is set, touch events outside this area are transparently transmitted. The setting becomes invalid after the window rectangle changes.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| rects | Array<[Rect](js-apis-window.md#rect7)> | Yes  | Touchable areas. The maximum number of touchable areas cannot exceed 10, and each touchable area cannot exceed the window area.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |                       |

**Example**

```ts
try {
  windowClass.setTouchableAreas([{left: 100, top: 100, width: 200, height:200},
    {left: 400, top: 100, width: 200, height:200}]);
} catch (exception) {
  console.error(`Failed to set touchable areas. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### raiseToAppTop<sup>10+</sup>

raiseToAppTop(callback: AsyncCallback&lt;void&gt;): void

Raises the application subwindow to the top layer of the application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.raiseToAppTop((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to raise the window to app top. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in raising the window to app top.');
});
```

### raiseToAppTop<sup>10+</sup>

raiseToAppTop(): Promise&lt;void&gt;

Raises the application subwindow to the top layer of the application. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.raiseToAppTop();
promise.then(() => {
  console.info('Succeeded in raising the window to app top.');
}).catch((err: BusinessError) => {
  console.error(`Failed to raise the window to app top. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setWaterMarkFlag<sup>10+</sup>

setWaterMarkFlag(enable: boolean): Promise&lt;void&gt;

Adds or deletes the watermark flag for this window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type    | Mandatory| Description                                           |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | Yes  | Whether to add or delete the flag. The value **true** means to add the flag and **false** means to delete the flag.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enable = true;
  let promise = windowClass.setWaterMarkFlag(enable);
  promise.then(() => {
    console.info('Succeeded in setting water mark flag of window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set water mark flag of window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set water mark flag of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWaterMarkFlag<sup>10+</sup>

setWaterMarkFlag(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Adds or deletes the watermark flag for this window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                      | Mandatory| Description                                             |
| -------- | ------------------------- | ---  | ----------------------------------------------- |
| enable   | boolean                   | Yes  | Whether to add or delete the flag. The value **true** means to add the flag and **false** means to delete the flag.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enable: boolean = true;
  windowClass.setWaterMarkFlag(enable, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set water mark flag of window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting water mark flag of window.');
  });
} catch (exception) {
  console.error(`Failed to set water mark flag of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setHandwritingFlag<sup>12+</sup>

setHandwritingFlag(enable: boolean): Promise&lt;void&gt;

Adds or deletes the handwriting flag for this window. After this flag is added, the window responds to stylus events but not touch events. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type    | Mandatory| Description                                           |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | Yes  | Whether to add or delete the flag. The value **true** means to add the flag and **false** means to delete the flag.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enable = true;
  let promise = windowClass.setHandwritingFlag(enable);
  promise.then(() => {
    console.info('Succeeded in setting handwriting flag of window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set handwriting flag of window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set handwriting flag of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### raiseAboveTarget<sup>10+</sup>

raiseAboveTarget(windowId: number, callback: AsyncCallback&lt;void&gt;): void

Raises a subwindow above a target subwindow. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | Yes  | ID of the target subwindow, which is the value of **properties.id** in [properties](js-apis-window.md#windowproperties) obtained through [getWindowProperties](js-apis-window.md#getwindowproperties9).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Mandatory parameters are left unspecified. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // Create a subwindow.
    try {
      let subWindow = windowStage.createSubWindow("testSubWindow");
      subWindow.then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        // The windowClass must be obtained above the targetWindow.
        let targetWindow: window.Window = windowClass;
        let properties = targetWindow.getWindowProperties();
        let targetId = properties.id;
        windowClass.raiseAboveTarget(targetId, (err) => {
          if (err.code) {
            console.error(`Failed to raise the subWindow to target subWindow top. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in raising the subWindow to target subWindow top.');
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### raiseAboveTarget<sup>10+</sup>

raiseAboveTarget(windowId: number): Promise&lt;void&gt;

Raises a subwindow above a target subwindow. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | Yes  | ID of the target subwindow, which is the value of **properties.id** in [properties](js-apis-window.md#windowproperties) obtained through [getWindowProperties](js-apis-window.md#getwindowproperties9).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Mandatory parameters are left unspecified. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // Create a subwindow.
    try {
      let subWindow = windowStage.createSubWindow("testSubWindow");
      subWindow.then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        // The windowClass must be obtained above the targetWindow.
        let targetWindow: window.Window = windowClass;
        let properties = targetWindow.getWindowProperties();
        let targetId = properties.id;
        let promise = windowClass.raiseAboveTarget(targetId);
        promise.then(()=> {
          console.info('Succeeded in raising the subWindow to target subWindow top.');
        }).catch((err: BusinessError)=>{
          console.error(`Failed to raise the subWindow to target subWindow top. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setRaiseByClickEnabled<sup>10+</sup>

setRaiseByClickEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable a subwindow to raise itself by click. This API uses an asynchronous callback to return the result.

Generally, when a user clicks a subwindow, the subwindow is displayed on the top. If the **enable** parameter is set to **false**, the subwindow is not displayed on the top when being clicked.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | Yes  | Whether to enable a subwindow to raise itself by click. The value **true** means to enable the subwindow to raise itself by click, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // Create a subwindow.
    try {
      let subWindow = windowStage.createSubWindow("testSubWindow");
      subWindow.then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        let enabled = false;
        windowClass.setRaiseByClickEnabled(enabled, (err) => {
          if (err.code) {
            console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in disabling the raise-by-click function.');
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setRaiseByClickEnabled<sup>10+</sup>

setRaiseByClickEnabled(enable: boolean): Promise&lt;void&gt;

Sets whether to enable a subwindow to raise itself by click. This API uses a promise to return the result.

Generally, when a user clicks a subwindow, the subwindow is displayed on the top. If the **enable** parameter is set to **false**, the subwindow is not displayed on the top when being clicked.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | Yes  | Whether to enable a subwindow to raise itself by click. The value **true** means to enable the subwindow to raise itself by click, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // Create a subwindow.
    try {
      let subWindow = windowStage.createSubWindow("testSubWindow");
      subWindow.then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        let enabled = false;
        let promise = windowClass.setRaiseByClickEnabled(enabled);
        promise.then(()=> {
          console.info('Succeeded in disabling the raise-by-click function.');
        }).catch((err: BusinessError)=>{
          console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### enableDrag<sup>13+</sup>

enableDrag(enable: boolean): Promise&lt;void&gt;

Enables or disables window dragging. This API uses a promise to return the result.

After window dragging is enabled, the window can be resized using the mouse.

This API takes effect only for the system window on 2-in-1 devices. If this API is called for other device types, an error is reported.

**System capability**: SystemCapability.Window.SessionManager

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------- | -- | --------- |
| enable| boolean | Yes| Whether to enable dragging.<br>The value **true** means to enable dragging, and **false** means the opposite.<br>|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.   |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.enableDrag(true).then(() => { 
    console.info('succeeded in setting window draggable');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window draggable. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set window draggable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### hideNonSystemFloatingWindows<sup>11+</sup>

hideNonSystemFloatingWindows(shouldHide: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to hide non-system floating windows. This API uses an asynchronous callback to return the result.

A non-system floating window is a floating window created by a non-system application. By default, the main window of a system application can be displayed together with a non-system floating window. This means that the main window may be blocked by an upper-layer non-system floating window. If the **shouldHide** parameter is set to **true**, all non-system floating windows are hidden, so that the main window will never be blocked by a non-system floating window.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | Yes  | Whether to hide non-system floating windows. The value **true** means to hide the floating windows, and **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Load the page corresponding to the main window.
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });

    // Obtain the main window.
    let mainWindow: window.Window | undefined = undefined;
    windowStage.getMainWindow((err, data) => {
      if (err.code) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      mainWindow = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));

      let shouldHide = true;
      // Call hideNonSystemFloatingWindows with the callback parameter.
      mainWindow.hideNonSystemFloatingWindows(shouldHide, (err) => {
        if (err.code) {
          console.error(`Failed to hide the non-system floating windows. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in hiding the non-system floating windows.');
      });
    });
  }
}
```

### hideNonSystemFloatingWindows<sup>11+</sup>

hideNonSystemFloatingWindows(shouldHide: boolean): Promise&lt;void&gt;

Sets whether to hide non-system floating windows. This API uses an asynchronous callback to return the result.

A non-system floating window is a floating window created by a non-system application. By default, the main window of a system application can be displayed together with a non-system floating window. This means that the main window may be blocked by an upper-layer non-system floating window. If the **shouldHide** parameter is set to **true**, all non-system floating windows are hidden, so that the main window will never be blocked by a non-system floating window.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | Yes  | Whether to hide non-system floating windows. The value **true** means to hide the floating windows, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Load the page corresponding to the main window.
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });

    // Obtain the main window.
    let mainWindow: window.Window | undefined = undefined;
    windowStage.getMainWindow((err, data) => {
      if (err.code) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      mainWindow = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));

      let shouldHide = true;
      // Call hideNonSystemFloatingWindows to obtain a promise object.
      let promise = mainWindow.hideNonSystemFloatingWindows(shouldHide);
      promise.then(()=> {
        console.info('Succeeded in hiding the non-system floating windows.');
      }).catch((err: BusinessError)=>{
        console.error(`Failed to hide the non-system floating windows. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### setTopmost<sup>12+</sup>

setTopmost(isTopmost: boolean): Promise&lt;void&gt;

Called by the main window to place the window above all the other windows. This API uses a promise to return the result.

This parameter is valid only when the main window is a floating window in 2-in-1 devices.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| isTopmost | boolean | Yes  | Whether to pin the main window on top. The value **true** means to pin the main window on top, and **false** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // ...
    windowStage.getMainWindow().then((window) => {
      let isTopmost: boolean = true;
      let promise = window.setTopmost(isTopmost);
      promise.then(() => {
        console.info('Succeeded in setting the main window to be topmost.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the main window to be topmost. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### setSingleFrameComposerEnabled<sup>11+</sup>

setSingleFrameComposerEnabled(enable: boolean): Promise&lt;void&gt;

Enables or disables the single-frame composer. This API uses a promise to return the result.

The single-frame composer is mainly used in scenarios that requires extremely low interaction latency. It reduces the screen display latency of the rendering node.  

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | Yes  | Whether to enable the single-frame composer. The value **true** means to enable the single-frame composer, and false means to disable it.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let enable = true;
let promise = windowClass.setSingleFrameComposerEnabled(enable);
promise.then(()=> {
    console.info('Succeeded in enabling the single-frame-composer function.');
}).catch((err: BusinessError)=>{
    console.error(`Failed to enable the single-frame-composer function. code:${err.code}, message:${err.message}.`);
});
```

### setTitleButtonVisible<sup>12+</sup>

setTitleButtonVisible(isMaximizeVisible: boolean, isMinimizeVisible: boolean, isSplitVisible: boolean): void

Shows or hides the maximize, minimize, and split-screen buttons on the title bar of the main window.

This API is valid only for 2-in-1 devices and takes effect only for the title bar buttons (maximize, minimize, and split-screen) that are available in the current scenario.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type   | Mandatory| Description                                         |
| --------- | ------- | ---- | --------------------------------------------- |
| isMaximizeVisible | boolean | Yes  | Whether to show the maximize button. The value **true** means to show the button, and **false** means to hide it.|
| isMinimizeVisible | boolean | Yes  | Whether to show the minimize button. The value **true** means to show the button, and **false** means to hide it.|
| isSplitVisible | boolean | Yes  | Whether to show the split-screen button. The value **true** means to show the button, and **false** means to hide it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300004  | Unauthorized operation. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Load the page corresponding to the main window.
    windowStage.loadContent('pages/Index', (err) => {
      let mainWindow: window.Window | undefined = undefined;
      // Obtain the main window.
      windowStage.getMainWindow().then(
        data => {
          mainWindow = data;
          console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
          // Call setTitleButtonVisible to hide the maximize, minimize, and split-screen buttons on the title bar of the main window.
          mainWindow.setTitleButtonVisible(false, false, false);
        }
      ).catch((err: BusinessError) => {
          if(err.code){
            console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          }
      });
    });
  }
}
```

### setWindowType<sup>(deprecated)</sup>

setWindowType(type: WindowType, callback: AsyncCallback&lt;void&gt;): void

Sets the type of this window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| type     | [WindowType](#windowtype7) | Yes  | Window type.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.WindowType.TYPE_SYSTEM_ALERT;
windowClass.setWindowType(type, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window type. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the window type.');
});
```

### setWindowType<sup>(deprecated)</sup>

setWindowType(type: WindowType): Promise&lt;void&gt;

Sets the type of this window. This API uses a promise to return the result.

**System API**: This is a system API.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| type   | [WindowType](#windowtype7) | Yes  | Window type.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.WindowType.TYPE_SYSTEM_ALERT;
let promise = windowClass.setWindowType(type);
promise.then(() => {
  console.info('Succeeded in setting the window type.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window type. Cause code: ${err.code}, message: ${err.message}`);
});
```

### requestFocus<sup>13+</sup>

requestFocus(isFocused: boolean): Promise&lt;void&gt;

Allows this window to proactively request to gain or lose focus. This API uses a promise to return the result. A value is returned as long as the API is successfully called. The return value does not indicate that the window has gained or lost focus. You can use [on('windowEvent')](js-apis-window.md#onwindowevent10) to listen for the focus status of the window.

When a focus request is sent, whether the window can successfully gain focus depends on its capability of being focused and its current visibility. To gain focus, the window must be capable of receiving focus and in a visible state (actively displayed and not hidden or destroyed).

Conversely, once a blur request is sent, the window will lose focus without any conditions.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| isFocused | boolean | Yes  | Whether to gain or lose focus. The value **true** means to gain focus, and **false** means to lose focus.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocused: boolean = true;
let promise = windowClass.requestFocus(isFocused);
promise.then(() => {
  console.info('Succeeded in requesting focus.');
}).catch((err: BusinessError) => {
  console.error(`Failed to request focus. Cause code: ${err.code}, message: ${err.message}`);
});
```

## SubWindowOptions<sup>11+</sup>

Describes the parameters used for creating a subwindow.

**System capability**: SystemCapability.Window.SessionManager

| Name     | Type | Read Only| Optional| Description        |
| ---------- | ---- | ---- | ---- | ----------- |
| isTopmost<sup>12+</sup>  | boolean | No| Yes| Whether the subwindow is topmost. The value **true** means that the subwindow is topmost, and **false** means the opposite. The default value is **false**.      |

## WindowStage<sup>9+</sup>

Implements a window manager, which manages each basic window unit, that is, [Window](#window) instance.

Before calling any of the following APIs, you must use [onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate) to create a **WindowStage** instance.

### disableWindowDecor<sup>9+</sup>

disableWindowDecor(): void

Disables window decorators.

When window decorators are disabled and the main window transitions into full-screen mode, hovering the cursor over the hot zone of the top window's title bar will cause a floating title bar to appear. To prevent the floating title bar from appearing, call [setTitleAndDockHoverShown()](./js-apis-window.md#settitleanddockhovershown14).

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('disableWindowDecor');
    windowStage.disableWindowDecor();
  }
};
```

### setShowOnLockScreen<sup>9+</sup>

setShowOnLockScreen(showOnLockScreen: boolean): void

Sets whether to display the window of the application on the lock screen.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| showOnLockScreen | boolean | Yes  | Whether to display the window on the lock screen. The value **true** means to display the window on the lock screen, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.setShowOnLockScreen(true);
    } catch (exception) {
      console.error(`Failed to show on lockscreen. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

## TransitionContext<sup>9+</sup>

Provides the context for the transition animation.

**System API**: This is a system API.

### Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                 | Type         | Readable| Writable| Description            |
| --------------------- | ----------------- | ---- | ---- | ---------------- |
| toWindow<sup>9+</sup> | [Window](#window) | Yes  | Yes  | Target window to display the animation.|

### completeTransition<sup>9+</sup>

completeTransition(isCompleted: boolean): void

Completes the transition. This API can be called only after [animateTo()](arkui-ts/ts-explicit-animation.md) is executed.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isCompleted | boolean | Yes  | Whether the transition is complete. The value **true** means that the transition is complete, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**Example**

```ts
(context: window.TransitionContext) => {
  let toWindow: window.Window = context.toWindow;
  animateTo({
    duration: 1000, // Animation duration.
    tempo: 0.5, // Playback speed.
    curve: Curve.EaseInOut, // Animation curve.
    delay: 0, // Animation delay.
    iterations: 1, // Number of playback times.
    playMode: PlayMode.Normal // Animation playback mode.
  }, () => {
    let obj: window.TranslateOptions = {
      x: 100.0,
      y: 0.0,
      z: 0.0
    };
    toWindow.translate(obj);
    console.info('toWindow translate end');
  }
  );
  try {
    context.completeTransition(true)
  } catch (exception) {
    console.error(`toWindow translate fail. Cause code: ${exception.code}, message: ${exception.message}`);
  }
  console.info('complete transition end');
};
```

## TransitionController<sup>9+</sup>

Implements the transition animation controller. Before calling any API, you must create a system window. For details, see the sample code.

**System API**: This is a system API.

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "systemTypeWindow",
  windowType: window.WindowType.TYPE_PANEL, // Select a system window type as required.
  ctx: this.context
};
let promise = window.createWindow(config);
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to create the Window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### animationForShown<sup>9+</sup>

animationForShown(context: TransitionContext): void

Customizes the animation for the scenario when the window is shown.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                                    | Mandatory| Description                |
| ------- | ---------------------------------------- | ---- | -------------------- |
| context | [TransitionContext](#transitioncontext9) | Yes  | Context of the transition animation.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**Example**

```ts
// xxx.ts
export class AnimationConfig {
  private animationForShownCallFunc_: Function = undefined;
  ShowWindowWithCustomAnimation(windowClass: window.Window, callback) {
    if (!windowClass) {
      console.error('windowClass is undefined');
      return false;
    }
    this.animationForShownCallFunc_ = callback;
    let controller: window.TransitionController = windowClass.getTransitionController();
    controller.animationForShown = (context : window.TransitionContext)=> {
      this.animationForShownCallFunc_(context);
    };
    windowClass.showWithAnimation(()=>{
      console.info('Show with animation success');
    });
  }
}
```

```ts
// xxx.ets
let animationConfig = new AnimationConfig();
let systemTypeWindow = window.findWindow("systemTypeWindow"); // Obtain a system window.
try {
  animationConfig?.ShowWindowWithCustomAnimation(systemTypeWindow, (context : window.TransitionContext)=>{
    console.info('complete transition end');
    let toWindow = context.toWindow;
    animateTo({
      duration: 1000, // Animation duration.
      tempo: 0.5, // Playback speed.
      curve: Curve.EaseInOut, // Animation curve.
      delay: 0, // Animation delay.
      iterations: 1, // Number of playback times.
      playMode: PlayMode.Normal // Animation playback mode.
      onFinish: () => {
        console.info('onFinish in animation');
        context.completeTransition(true)
      }
    }, () => {
      let obj : window.TranslateOptions = {
        x : 100.0,
        y : 0.0,
        z : 0.0
      };
      toWindow.translate(obj); // Set the transition animation.
      console.info('toWindow translate end in animation');
    });
    console.info('complete transition end');
  });
} catch (error) {
  console.error(`ShowWindowWithCustomAnimation error code: ${error.code}, message: ${error.message}`);
}
```

### animationForHidden<sup>9+</sup>

animationForHidden(context: TransitionContext): void

Customizes the animation for the scenario when the window is hidden.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                                    | Mandatory| Description                |
| ------- | ---------------------------------------- | ---- | -------------------- |
| context | [TransitionContext](#transitioncontext9) | Yes  | Context of the transition animation.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**Example**

```ts
// xxx.ts
export class AnimationConfig {
  private animationForHiddenCallFunc_: Function = undefined;
  HideWindowWithCustomAnimation(windowClass: window.Window, callback) {
    if (!windowClass) {
      console.error('windowClass is undefined');
      return false;
    }
    this.animationForHiddenCallFunc_ = callback;
    let controller: window.TransitionController = windowClass.getTransitionController();
    controller.animationForHidden = (context : window.TransitionContext)=> {
      this.animationForHiddenCallFunc_(context);
    };
    windowClass.hideWithAnimation(()=>{
      console.info('hide with animation success');
    });
  }
}
```

```ts
// xxx.ets
let animationConfig = new AnimationConfig();
let systemTypeWindow = window.findWindow("systemTypeWindow"); // Obtain a system window.
try {
  animationConfig?.HideWindowWithCustomAnimation(systemTypeWindow, (context : window.TransitionContext)=>{
    console.info('complete transition end');
    let toWindow = context.toWindow;
    animateTo({
      duration: 1000, // Animation duration.
      tempo: 0.5, // Playback speed.
      curve: Curve.EaseInOut, // Animation curve.
      delay: 0, // Animation delay.
      iterations: 1, // Number of playback times.
      playMode: PlayMode.Normal // Animation playback mode.
      onFinish: () => {
        console.info('onFinish in animation');
        context.completeTransition(true)
      }
    }, () => {
      let obj : window.TranslateOptions = {
        x : 100.0,
        y : 0.0,
        z : 0.0
      };
      toWindow.translate(obj); // Set the transition animation.
      console.info('toWindow translate end in animation');
    });
    console.info('complete transition end');
  });
} catch (error) {
  console.error(`HideWindowWithCustomAnimation error code: ${error.code}, message: ${error.message}` );
}
```

## ExtensionWindowAttribute<sup>14+</sup>

Enumerates the attributes of a window for a UI ServiceExtensionAbility.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name     | Value| Description        |
| ---------- | ----- | ----------- |
| SYSTEM_WINDOW  | 0 | System window|
| SUB_WINDOW  | 1 | Subwindow.|

## SystemWindowOptions<sup>14+</sup>

Describes the parameters for creating a system window.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type                     | Read Only |Optional| Description      |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowType   | [WindowType](#windowtype7) | No  | No  | Window type. There is no default value. If null is passed in, the window fails to be created. **TYPE_DIALOG** is not supported.|

## ExtensionWindowConfig<sup>14+</sup>

Describes the parameters for creating a window for a UI ServiceExtensionAbility.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type                     | Read Only |Optional| Description      |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowName   | string | No| No | Window name.|
| windowAttribute   | [ExtensionWindowAttribute](#extensionwindowattribute14) | No| No  | Window attribute. It specifies whether the created window is a subwindow or a system window. When **windowAttribute** is set to **SUB_WINDOW**, **subWindowOptions** is mandatory. When **windowAttribute** is set to **SYSTEM_WINDOW**, **systemWindowOptions** is mandatory. Otherwise, the window fails to be created.|
| windowRect   | [Rect](js-apis-window.md#rect7) | No| No  | Rectangular area of the window.|
| subWindowOptions   | [SubWindowOptions](js-apis-window.md#subwindowoptions12) | No| Yes| Parameters used for creating a subwindow. There is no default value. This parameter is mandatory when **windowAttribute** is set to **SUB_WINDOW**. Otherwise, the window fails to be created.|
| systemWindowOptions   | [SystemWindowOptions](#systemwindowoptions14) | No| Yes| Parameters for creating a system window. There is no default value. This parameter is mandatory when **windowAttribute** is set to **SYSTEM_WINDOW**. Otherwise, the window fails to be created.|

 <!--no_check--> 
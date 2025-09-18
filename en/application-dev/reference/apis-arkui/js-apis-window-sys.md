# @ohos.window (Window) (System API)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

The Window module provides basic window management capabilities, such as creating and destroying the current window, setting properties for the current window, and managing and scheduling windows.

This module provides the following common window-related functions:

- [Window](arkts-apis-window-Window.md): window instance, which is the basic unit managed by the window manager.
- [WindowStage](#windowstage9): window manager that manages windows.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.window (Window)](arkts-apis-window.md).

## Modules to Import

```ts
import { window } from '@kit.ArkUI';
```

## WindowType<sup>7+</sup>


Enumerates the window types.


| Name                                 | Value| Description                                                                                    |
|-------------------------------------| ------ |----------------------------------------------------------------------------------------|
| TYPE_INPUT_METHOD<sup>(deprecated)</sup>      | 2      | Input method window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>Note: This API is supported since API version 9 and deprecated since API version 13. There is no alternative window type. To control the input method, call [Input method framework APIs](../../inputmethod/inputmethod-application-guide.md).<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
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
| TYPE_WALLET_SWIPE_CARD<sup>15+</sup>| 22      | Wallet swipe card window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|
| TYPE_SCREEN_CONTROL<sup>15+</sup>   | 23      | Top-level window used for locking touch input, which intercepts screen touch and click events.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|
| TYPE_FLOAT_NAVIGATION<sup>17+</sup> | 24      | Floating window with a three-button navigation bar.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|
| TYPE_DYNAMIC<sup>20+</sup> | 25      | System window that allows for adjustable z-levels.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|
| TYPE_MUTISCREEN_COLLABORATION<sup>20+</sup> | 26      | Window for multi-screen collaboration.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|

## Configuration<sup>9+</sup>

Defines the parameters for creating a child window or system window.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type| Read-Only| Optional| Description                      |
| ---------- | --------- | ---- | ---- |-------------- |
| zIndex<sup>20+</sup>       | number | No| Yes| Z-level of the system window. This parameter is valid only when [WindowType](#windowtype7) is set to **TYPE_DYNAMIC**.|
| defaultDensityEnabled<sup>20+</sup> | boolean| No| Yes|Whether the window should use the default density of the system. If the default density is used, the window does not re-layout when the system display size changes.<br>If this parameter is set to **true** for a system window, the window uses the default density and is not affected by [setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12) or [setCustomDensity()](arkts-apis-window-WindowStage.md#setcustomdensity15) settings for the main window or [setDefaultDensityEnabled()](#setdefaultdensityenabled20) settings for the current window.<br>If this parameter is set to **false**, the window does not use the default density and is affected by those settings.<br>The default value is **false**.|

## WindowMode<sup>7+</sup>

Enumerates the window modes.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 1    | The window mode is not defined by the application.      |
| FULLSCREEN | 2    | The application is displayed in full screen.            |
| PRIMARY    | 3    | The application is displayed in the primary window in split-screen mode. In top-bottom splits, the top screen is primary; in left-right splits, the left screen is primary. |
| SECONDARY  | 4    | The application is displayed in the secondary window in split-screen mode. In top-bottom splits, the top screen is secondary; in left-right splits, the left screen is secondary. |
| FLOATING   | 5    | The application is displayed in a floating window.|

## WindowLayoutMode<sup>9+</sup>

Enumerates the window layout modes.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| WINDOW_LAYOUT_MODE_CASCADE  | 0    | Cascade mode. In this mode, freeform windows are stacked with Z-order arrangement.    |
| WINDOW_LAYOUT_MODE_TILE | 1    | Tile mode. In this mode, newly opened application windows appear on the rightmost.          |


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

## AnimationType<sup>20+</sup>

Enumerates the types of window animations.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name   | Value  | Description                      |
| ------- | ---- | -------------------------- |
| FADE_IN | 1    | Fade-in animation, which takes effect during window display.|

## SystemBarRegionTint<sup>8+</sup>

Describes the callback for a single system bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name           | Type                 | Read-Only| Optional| Description                                                        |
| --------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type            | [WindowType](#windowtype7) | No  | No  | Type of the system bar whose properties are changed. Only the status bar and navigation bar are supported.|
| isEnable        | boolean                   | No  | Yes  | Whether the system bar is displayed. **true** if displayed, **false** otherwise. The default value is **true**.|
| region          | [Rect](arkts-apis-window-i.md#rect7)             | No  | Yes  | Current position and size of the system bar. The default value is {0,0,0,0}.                          |
| backgroundColor | string                    | No  | Yes  | Background color of the system bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. The default value is **'0x66000000'**.|
| contentColor    | string                    | No  | Yes  | Color of the text on the system bar. The default value is **'0xE5FFFFFF'**.               |

## SystemBarTintState<sup>8+</sup>

Describes the callback for the current system bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Type                                           | Read-Only| Optional| Description                        |
| ---------- | --------------------------------------------------- | ---- | ---- | ---------------------------- |
| displayId  | number                                              | No  | No  | ID of the screen where the window is located. The value must be an integer.            |
| regionTint | Array<[SystemBarRegionTint](#systembarregiontint8)> | No  | No  | All system bar information that has been changed.|

## ScaleOptions<sup>9+</sup>

Describes the scale parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Read-Only| Optional| Description                                        |
| ------ | -------- | ---- | ---- | --------------------------------------------|
| x      | number   | No  | Yes  | Scale factor along the x-axis. The value is a floating-point number, and the default value is **1.0**.                  |
| y      | number   | No  | Yes  | Scale factor along the y-axis. The value is a floating-point number, and the default value is **1.0**.                  |
| pivotX | number   | No  | Yes  | X coordinate of the scale center. The value is a floating-point number in the range [0.0, 1.0], and the default value is **0.5**.|
| pivotY | number   | No  | Yes  | Y coordinate of the scale center. The value is a floating-point number in the range [0.0, 1.0], and the default value is **0.5**.|

## RotateOptions<sup>9+</sup>

Describes the rotation parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Read-Only| Optional| Description                                         |
| ------ | -------- | ---- |---- |---------------------------------------------|
| x      | number   | No  | Yes | Rotation angle around the x-axis. The value is a floating-point number, and the default value is **0.0**.                  |
| y      | number   | No  | Yes | Rotation angle around the y-axis. The value is a floating-point number, and the default value is **0.0**.                  |
| z      | number   | No  | Yes | Rotation angle around the z-axis. The value is a floating-point number, and the default value is **0.0**.                  |
| pivotX | number   | No  | Yes | X coordinate of the rotation center. The value is a floating-point number in the range [0.0, 1.0], and the default value is **0.5**.|
| pivotY | number   | No  | Yes | Y coordinate of the rotation center. The value is a floating-point number in the range [0.0, 1.0], and the default value is **0.5**. |

## TranslateOptions<sup>9+</sup>

Describes the translation parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Read-Only| Optional| Description                        |
| ---- | -------- | ---- | ---- | ---------------------------- |
| x    | number   | No  | Yes | Distance to translate along the x-axis. The value is a floating-point number, the default value is 0.0, and the unit is px.|
| y    | number   | No  | Yes | Distance to translate along the y-axis. The value is a floating-point number, the default value is 0.0, and the unit is px.|
| z    | number   | No  | Yes | Distance to translate along the z-axis. The value is a floating-point number, the default value is 0.0, and the unit is px.|


## StartAnimationSystemParams<sup>20+</sup>

Start animation configuration. This API works only for full-screen applications.

The configuration does not take effect for inter-application transitions, where the default animation of the system is used.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on tablets in non-[free windows mode](../../windowmanager/window-terminology.md#free-windows) and phones. If it is called on other device types, it has no effect and does not report errors.

| Name            | Type                                                                    | Read-Only| Optional| Description                                                        |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type             | [AnimationType](#animationtype20)                 | No  | No  | Type of the window animation.|
| animationConfig  | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20) | No  | Yes  | Configuration for the window animation. The default animation curve is **WindowAnimationCurve.LINEAR**, and the duration is **0**.         |

## WindowCreateParams<sup>20+</sup>

Describes the window parameters during application startup.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager
| Name            | Type                                                                    | Read-Only| Optional| Description                                                        |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| systemAnimationParams             | [StartAnimationSystemParams](#startanimationsystemparams20)                 | No  | Yes  | Parameters for the startup animation. The default value is **undefined**. If this parameter is not set, the default animation of the system is used.|

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

Minimizes all windows on a display. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: When this API is called on phones, error code 801 is returned. However, it can be called properly on other devices.

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
  if (!displayClass) {
    console.error('displayClass is null');
  } else {
    window.minimizeAll(displayClass.id, (err: BusinessError) => {
      const errCode: number = err?.code;
      if (errCode) {
        console.error(`Failed to minimize all windows. Cause code: ${err?.code}, message: ${err?.message}`);
        return;
      }
      console.info('Succeeded in minimizing all windows.');
    });
  }
} catch (exception) {
  console.error(`Failed to minimize all windows. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number): Promise&lt;void&gt;

Minimizes all windows on a display. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: When this API is called on phones, error code 801 is returned. However, it can be called properly on other devices.

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
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return the gesture navigation status. **true** if enabled, **false** otherwise.|

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
    console.info(`Succeeded in enabling the listener for gesture navigation status changes. Data: ${data}`);
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
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return the watermark status. **true** if enabled, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
try {
  window.on('waterMarkFlagChange', (data) => {
    console.info(`Succeeded in enabling the listener for watermark flag changes. Data: ${data}`);
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
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
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
| enable   | boolean                  | Yes  | Whether to enable gesture navigation. **true** to enable, **false** otherwise. Currently, only the pull-down gesture is disabled. Other gestures remain enabled.|
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
| enable | boolean | Yes  | Whether to enable gesture navigation. **true** to enable, **false** otherwise.|

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

Controls whether a watermark image is displayed on the screen. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes| Watermark image, which can be obtained by calling [createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8).|
| enable   | boolean                  | Yes  | Whether to display the watermark image. **true** to display, **false** otherwise. After the watermark image is displayed, you need to set this parameter to **false** to disable the watermark display.|
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

Controls whether a watermark image is displayed on the screen. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                       | Mandatory | Description                |
| ------ | --------------------------- | ---- | -------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes| Watermark image, which can be obtained by calling [createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8).|
| enable   | boolean                  | Yes  | Whether to display the watermark image. **true** to display, **false** otherwise. After the watermark image is displayed, you need to set this parameter to **false** to disable the watermark display.|

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

Obtains a snapshot of the same size as the specified window. This API uses a promise to return the result. If privacy mode is enabled for the current window (using [setWindowPrivacyMode](arkts-apis-window-Window.md#setwindowprivacymode9)), taking a screenshot will result in a blank screen.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**
| Name  | Type  | Mandatory | Description        |
| -------- | ------ | ----- | ------------ |
| windowId | number | Yes   | Window ID. You can call [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window properties, in which **id** is the window ID.|

**Return value**
| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Promise<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)> | Promise used to return the window screenshot.|

**Error codes**
For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
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

## window.notifyScreenshotEvent<sup>20+</sup>

notifyScreenshotEvent(eventType: ScreenshotEventType): Promise&lt;void&gt;

Notifies a screenshot event. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type  | Mandatory | Description        |
| -------- | ------ | ----- | ------------ |
| eventType | [ScreenshotEventType](arkts-apis-window-e.md#screenshoteventtype20) | Yes   | Type of the screenshot event.|

**Return value**

| Type                   | Description                           |
| ----------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300003  | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let eventType: window.ScreenshotEventType = window.ScreenshotEventType.SYSTEM_SCREENSHOT;
  let promise = window.notifyScreenshotEvent(eventType);
  promise.then(() => {
    console.info(`Succeeded in notifying screenshot event type.`);
  }).catch((err: BusinessError) =>{
    console.error(`Failed to notify screenshot event type. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to notify screenshot event type. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getTopNavDestinationName<sup>20+</sup>

getTopNavDestinationName(windowId: number): Promise&lt;string&gt;

Obtains the name of [NavDestination](arkui-ts/ts-basic-components-navdestination.md) in the current top-level [Navigation](arkui-ts/ts-basic-components-navigation.md) component of the specified foreground window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type  | Mandatory| Description                                                                       |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| windowId   | number| Yes | ID of the window to query. This parameter must be an integer greater than 0. If it is less than or equal to 0, error code 1300016 is returned. If the specified window does not exist or is not in the foreground, error code 1300002 is returned.|

**Return value**

| Type                            | Description                     |
| -------------------------------- |-------------------------|
| Promise&lt;string&gt; | Promise used to return the [NavDestination](arkui-ts/ts-basic-components-navdestination.md) name obtained.<br>If there are nested [Navigation](arkui-ts/ts-basic-components-navigation.md) components or multiple [Navigation](arkui-ts/ts-basic-components-navigation.md) components on the current page, the information of the most recently created [Navigation](arkui-ts/ts-basic-components-navigation.md) component is queried.<br>If the page does not have the [Navigation](arkui-ts/ts-basic-components-navigation.md) component or the [Navigation](arkui-ts/ts-basic-components-navigation.md) component does not have [NavDestination](arkui-ts/ts-basic-components-navdestination.md), an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID   | Error Message|
|----------| ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**Example**
```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowId = 10;
  let promise = window.getTopNavDestinationName(windowId);
  promise.then((data) => {
    console.info(`Succeeded, data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed, cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed, exception code: ${exception.code}, message: ${exception.message}`);
}
```

## Window

Represents a window instance, which is the basic unit managed by the window manager.

In the following API examples, you must use [getLastWindow()](arkts-apis-window-f.md#windowgetlastwindow9), [createWindow()](arkts-apis-window-f.md#windowcreatewindow9), or [findWindow()](arkts-apis-window-f.md#windowfindwindow9) to obtain a Window instance (named windowClass in this example) and then call a method in this instance.

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

Hides this window. This API uses an asynchronous callback to return the result. This API takes effect only for a system window or an application child window.

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

Hides this window. This API uses a promise to return the result. This API takes effect only for a system window or an application child window.

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
import { ServiceExtensionAbility } from '@kit.AbilityKit';

class MyDeathRecipient {
  onRemoteDied() {
    console.info('server died');
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

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let token: TestRemoteObject = new TestRemoteObject('testObject');
    let config: window.Configuration = { name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        let errCode: number = err?.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err?.code}, message: ${err?.message}`);
          return;
        }
        if (!data) {
          console.error('data is null');
          return;
        }
        data.bindDialogTarget(token, () => {
          console.info('Dialog Window Need Destroy.');
          }, (err: BusinessError) => {
          let errCode: number = err?.code;
          if (errCode) {
            console.error(`Failed to bind dialog target. Error code: ${err?.code}, message: ${err?.message}`);
            return;
          }
          console.info('Succeeded in binding dialog target.');
        });
      });
    } catch (exception) {
      console.error(`Failed to bind dialog target. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
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
import { ServiceExtensionAbility } from '@kit.AbilityKit';

class MyDeathRecipient {
  onRemoteDied() {
    console.info('server died');
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

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let token: TestRemoteObject = new TestRemoteObject('testObject');
    let config: window.Configuration = {
      name: "test",
      windowType: window.WindowType.TYPE_DIALOG,
      ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        const errCode: number = err?.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err?.code}, message: ${err?.message}`);
          return;
        }
        if (!data) {
          console.error('data is null');
          return;
        }
        let promise = data.bindDialogTarget(token, () => {
          console.info('Dialog Window Need Destroy.');
        });
        promise.then(() => {
          console.info('Succeeded in binding dialog target.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to bind dialog target. Error code: ${err?.code}, message: ${err?.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to bind dialog target. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
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
    let config: window.Configuration = {
      name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        let errCode: number = err?.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err?.code}, message: ${err?.message}`);
          return;
        }
        if (!data) {
          console.error('data is null');
          return;
        }
        let requestInfo = dialogRequest.getRequestInfo(want);
        data.bindDialogTarget(requestInfo, () => {
          console.info('Dialog Window Need Destroy.');
          }, (err: BusinessError) => {
          let errCode: number = err?.code;
          if (errCode) {
            console.error(`Failed to bind dialog target. Cause code: ${err?.code}, message: ${err?.message}`);
            return;
          }
          console.info('Succeeded in binding dialog target.');
        });
      });
    } catch (err) {
      console.error(`Failed to bind dialog target. Cause code: ${err?.code}, message: ${err?.message}`)
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
    let config: window.Configuration = {
      name: "test", windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
    };
    try {
      window.createWindow(config, (err: BusinessError, data) => {
        const errCode: number = err?.code;
        if (errCode) {
          console.error(`Failed to create the window. Cause code: ${err?.code}, message: ${err?.message}`);
          return;
        }
        if (!data) {
          console.error('data is null');
          return;
        }
        let requestInfo = dialogRequest.getRequestInfo(want);
        let promise = data.bindDialogTarget(requestInfo, () => {
          console.info('Dialog Window Need Destroy.');
        });
        promise.then(() => {
          console.info('Succeeded in binding dialog target.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to bind dialog target. Cause code: ${err?.code}, message: ${err?.message}`);
        });
      });
    } catch (err) {
      console.error(`Failed to bind dialog target. Cause code: ${err?.code}, message: ${err?.message}`)
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
| wakeUp           | boolean | Yes  | Whether to wake up the screen. **true** to wake up, **false** otherwise. |

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

Sets whether to ignore this window during screen capture, recording, or casting. This API is typically used in situations where you want to prevent screen capture, recording, or casting.

If you want the window to always be ignored during screen capture, recording, or casting while it is in the foreground, listen for window lifecycle changes using [on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10). Set **isSkip** to **false** when the window is in the background and **true** when it is in the foreground.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type   | Mandatory| Description                |
| ------------- | ------- | ---- | -------------------- |
| isSkip | boolean | Yes  | Whether to ignore the window. The default value is **false**. **true** to ignore, **false** otherwise.<br>|

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
| isForbidSplitMove | boolean                   | Yes  | Whether the window is forbidden to move in split-screen mode. **true** if forbidden, **false** otherwise.|
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
| isForbidSplitMove | boolean | Yes  | Whether the window is forbidden to move in split-screen mode. **true** if forbidden, **false** otherwise.|

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
| opacity | number | Yes  | Opacity. The value is a floating-point number in the range [0.0, 1.0]. The value **0.0** means completely transparent, and **1.0** means completely opaque.|

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
| radius | number | Yes  | Radius of the blur. The value is a floating-point number greater than or equal to 0.0, in px. The value **0.0** means that the blur is disabled for the window.|

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

To make the blur effect visible, you must set the window background transparent by calling [setWindowBackgroundColor](arkts-apis-window-Window.md#setwindowbackgroundcolor9).

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                   |
| ------ | ------ | ---- |-------------------------------------------------------|
| radius | number | Yes  | Radius of the blur. The value is a floating-point number greater than or equal to 0.0, in px. The value **0.0** means that the blur is disabled for the background of the window.|

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
| radius  | number | Yes  | Radius of the shadow. The value is a floating-point number greater than or equal to 0.0, in px. The value **0.0** means that the shadow is disabled for the window borders.    |
| color   | string | No  | Color of the shadow. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**.|
| offsetX | number | No  | Offset of the shadow along the x-axis, in px. The value is a floating-point number.                             |
| offsetY | number | No  | Offset of the shadow along the y-axis, in px. The value is a floating-point number.                             |

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
| cornerRadius | number | Yes  | Radius of the rounded corners. The value is a floating-point number greater than or equal to 0.0, in px. The value **0.0** means that the window does not use rounded corners.|

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
| rects | Array<[Rect](arkts-apis-window-i.md#rect7)> | Yes  | Touchable areas. The maximum number of touchable areas cannot exceed 10, and each touchable area cannot exceed the window area.|

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

Raises the application child window to the top layer of the application. This API uses an asynchronous callback to return the result.

Before calling this API, ensure that the child window has been created and [showWindow()](arkts-apis-window-Window.md#showwindow9) has been successfully executed.

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
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    // Create a child window.
    windowStage.createSubWindow('testSubWindow').then((subWindow) => {
      if (subWindow == null) {
        console.error('Failed to create the subWindow. Cause: The data is empty');
        return;
      }
      subWindow.showWindow().then(() => {
        subWindow.raiseToAppTop((err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to raise the window to app top. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in raising the window to app top.');
        });
      });
    });
  }
}
```

### setWaterMarkFlag<sup>10+</sup>

setWaterMarkFlag(enable: boolean): Promise&lt;void&gt;

Adds or deletes the watermark flag for this window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type    | Mandatory| Description                                           |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | Yes  | Whether to add or delete the flag. **true** to add, **false** otherwise.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
| enable   | boolean                   | Yes  | Whether to add or delete the flag. **true** to add, **false** otherwise.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
| enable | boolean | Yes  | Whether to add or delete the flag. **true** to add, **false** otherwise.|

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

Raises a child window above a target child window. This API uses an asynchronous callback to return the result.

Before calling this API, ensure that the child window to raise and the target child window have been created and [showWindow()](arkts-apis-window-Window.md#showwindow9) has been successfully executed for each.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | Yes  | ID of the target child window, which is the value of **properties.id** in [properties](arkts-apis-window-i.md#windowproperties) obtained through [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9).|
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
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window;
    // Create a child window.
    try {
      windowStage.createSubWindow("testSubWindow").then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        windowClass.showWindow().then(() => {
          // The windowClass must be obtained above the targetWindow.
          let targetWindow: window.Window = windowClass;
          let properties = targetWindow.getWindowProperties();
          let targetId = properties.id;
          windowClass.raiseAboveTarget(targetId, (err: BusinessError) => {
            if (err.code) {
              console.error(`Failed to raise the subWindow to target subWindow top. Cause code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info('Succeeded in raising the subWindow to target subWindow top.');
          });
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

Raises a child window above a target child window. This API uses a promise to return the result.

Before calling this API, ensure that the child window to raise and the target child window have been created and [showWindow()](arkts-apis-window-Window.md#showwindow9) has been successfully executed for each.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | Yes  | ID of the target child window, which is the value of **properties.id** in [properties](arkts-apis-window-i.md#windowproperties) obtained through [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9).|

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
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window;
    // Create a child window.
    try {
      windowStage.createSubWindow("testSubWindow").then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        windowClass.showWindow().then(() => {
          // The windowClass must be obtained above the targetWindow.
          let targetWindow: window.Window = windowClass;
          let properties = targetWindow.getWindowProperties();
          let targetId = properties.id;
          windowClass.raiseAboveTarget(targetId).then(()=> {
            console.info('Succeeded in raising the subWindow to target subWindow top.');
          }).catch((err: BusinessError)=>{
            console.error(`Failed to raise the subWindow to target subWindow top. Cause code: ${err.code}, message: ${err.message}`);
          });
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### raiseMainWindowAboveTarget<sup>20+</sup>

raiseMainWindowAboveTarget(windowId: number): Promise&lt;void&gt;

Moves the main window above another main window within the same application, with child windows following their parents' layer change. This API works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode. This API uses a promise to return the result.

This API can be called only by the main window of a system application.

You need to pass the ID of the target main window. Both the calling window and the target window must be in the same application process, displayed on the same physical screen, below the lock screen layer, not topmost, not modal, and have no application-modal child windows.

- If the application's main window or its child windows currently have focus, calling this API to lower the layer will cause the window to lose focus automatically, and the highest-layered application window will gain focus.

- If the main window calls this API to move above the current focused window, the highest-layered window among the raised main window and its child windows will gain focus. If the main window calls this API without moving above the current focused window, the focus remains unchanged.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | Yes  | ID of the target main window. The value is an integer. It is the value of **properties.id** in [properties](arkts-apis-window-i.md#windowproperties) obtained through [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300016 | Parameter error. Possible cause: 1. Invalid Parameter range. 2. Invalid parameter length. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility, Want, StartOptions, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}.`);
        return;
      }
      console.info('Succeeded in loading the content.');
      try {
        let want: Want = {
          abilityName: "RaiseMainWindowAbility",
          bundleName: "com.example.myapplication"
        };
        let options: StartOptions = {
          windowMode: AbilityConstant.WindowMode.WINDOW_MODE_FLOATING
        };
        this.context.startAbility(want, options);
      } catch (err) {
        console.error(`Failed to start the ability. Cause code: ${err.code}, message: ${err.message}.`);
      }
      setTimeout(async () => {
        let mainWindow: window.Window | null | undefined = windowStage.getMainWindowSync();
        let targetId: number | null | undefined = AppStorage.get('higher_window_id');
        mainWindow.raiseMainWindowAboveTarget(targetId).then(() => {
          console.info('Succeeded in raising main window above target.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to raise main window above target. Cause code: ${err.code}, message: ${err.message}.`)
        });
      }, 3000)
    });
  }
}
```
```ts
// Create the RaiseMainWindowAbility.ets file in src/main/ets/raisemainwindowability.
import { UIAbility } from '@kit.AbilityKit';

export default class RaiseMainWindowAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    AppStorage.setOrCreate('higher_window_id', windowStage.getMainWindowSync().getWindowProperties().id);
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}.`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });
  }
}
```
```json5
//module.json5
{
  "module": {
    "name": "entry",
    "type": "entry",
    "description": "$string:module_desc",
    "mainElement": "EntryAbility",
    "deviceTypes": [
      "phone",
      "tablet",
      "2in1"
    ],
    "deliveryWithInstall": true,
    "installationFree": false,
    "pages": "$profile:main_pages",
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:layered_image",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:startIcon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      },
      {
        "name": "RaiseMainWindowAbility",
        "launchType": "multiton",
        "srcEntry": "./ets/entryability/EntryAbility.ets",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:layered_image",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:startIcon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ]
      }
    ]
  }
}
```

### setRaiseByClickEnabled<sup>10+</sup>

setRaiseByClickEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable a child window to raise itself by click. This API uses an asynchronous callback to return the result.

Generally, when a user clicks a child window, the child window is displayed on the top. If the **enable** parameter is set to **false**, the child window is not displayed on the top when being clicked.

Before calling this API, ensure that the child window has been created and [showWindow()](arkts-apis-window-Window.md#showwindow9) has been successfully executed.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | Yes  | Whether to enable a child window to raise itself by click. **true** to enable, **false** otherwise.|
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
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    // Create a child window.
    windowStage.createSubWindow("testSubWindow").then((subWindow) => {
      if (subWindow == null) {
        console.error('Failed to create the subWindow. Cause: The data is empty');
        return;
      }
      subWindow.showWindow().then(() => {
        try {
          let enabled = false;
          subWindow.setRaiseByClickEnabled(enabled, (err) => {
          if (err.code) {
            console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in disabling the raise-by-click function.');
          });
        } catch (err) {
          console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
        }
      });
    });
  }
}
```

### hideNonSystemFloatingWindows<sup>11+</sup>

hideNonSystemFloatingWindows(shouldHide: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to hide non-system floating windows (where [windowType](arkts-apis-window-e.md#windowtype7) is **TYPE_FLOAT**). This API uses an asynchronous callback to return the result.

A non-system floating window is a floating window created by a non-system application. By default, the main window of a system application can be displayed together with a non-system floating window. This means that the main window may be blocked by an upper-layer non-system floating window. If the **shouldHide** parameter is set to **true**, all non-system floating windows are hidden, so that the main window will never be blocked by a non-system floating window.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API has no effect and does not report errors for 2-in-1 devices. For other devices, this API can be called properly.

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | Yes  | Whether to hide non-system floating windows. **true** to hide, **false** otherwise.|
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
      try {
        // Call hideNonSystemFloatingWindows with the callback parameter.
        mainWindow.hideNonSystemFloatingWindows(shouldHide, (err) => {
          if (err.code) {
            console.error(`Failed to hide the non-system floating windows. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in hiding the non-system floating windows.');
        });
      } catch (exception) {
        console.error(`Failed to hide the non-system floating windows. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### hideNonSystemFloatingWindows<sup>11+</sup>

hideNonSystemFloatingWindows(shouldHide: boolean): Promise&lt;void&gt;

Sets whether to hide non-system floating windows (where [windowType](arkts-apis-window-e.md#windowtype7) is **TYPE_FLOAT**). This API uses a promise to return the result.

A non-system floating window is a floating window created by a non-system application. By default, the main window of a system application can be displayed together with a non-system floating window. This means that the main window may be blocked by an upper-layer non-system floating window. If the **shouldHide** parameter is set to **true**, all non-system floating windows are hidden, so that the main window will never be blocked by a non-system floating window.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API has no effect and does not report errors for 2-in-1 devices. For other devices, this API can be called properly.

**Parameters**

| Name     | Type                     | Mandatory| Description      |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | Yes  | Whether to hide non-system floating windows. **true** to hide, **false** otherwise.|

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
      try {
        // Call hideNonSystemFloatingWindows to obtain a promise object.
        let promise = mainWindow.hideNonSystemFloatingWindows(shouldHide);
        promise.then(()=> {
          console.info('Succeeded in hiding the non-system floating windows.');
        }).catch((err: BusinessError)=>{
          console.error(`Failed to hide the non-system floating windows. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to hide the non-system floating windows. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setDefaultDensityEnabled<sup>20+</sup>

setDefaultDensityEnabled(enabled: boolean): void

Sets whether the window uses the default density of the current screen. In the stage model, you need to call this API after [loadContent()](arkts-apis-window-Window.md#loadcontent9) or [setUIContent()](arkts-apis-window-Window.md#setuicontent9).

If this API is not called, the default density is not used.

If this API, [setDefaultDensityEnabled(true)](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12), and [setCustomDensity](arkts-apis-window-WindowStage.md#setcustomdensity15) are all called, the setting from the last called API will be applied.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| enabled | boolean | Yes  | Whether to use the default density of the system. **true** to enable, **false** otherwise. When the default density is enabled, the window layout does not change with the system display size.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
try {
  windowClass.setDefaultDensityEnabled(true);
  console.info(`Succeeded in setting default density enabled`);
} catch (exception) {
  console.error(`Failed to set default density enabled. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### isMainWindowFullScreenAcrossDisplays<sup>20+</sup>

isMainWindowFullScreenAcrossDisplays(): Promise&lt;boolean&gt;

Checks whether the main window is in full-screen mode across multiple displays. This API uses a promise to return the result. It takes effect only for the main window and child windows.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result indicating whether the main window is in full-screen mode across multiple displays. **true** if yes, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.isMainWindowFullScreenAcrossDisplays();
  promise.then((data: boolean)=> {
      console.info(`Succeeded in using isMainWindowFullScreenAcrossDisplays function. Data: ${data}`);
  }).catch((err: BusinessError)=>{
      console.error(`Failed to use isMainWindowFullScreenAcrossDisplays function. code:${err.code}, message:${err.message}.`);
  });
} catch (exception) {
  console.error(`Failed to use isMainWindowFullScreenAcrossDisplays function. Cause code: ${exception.code}, message: ${exception.message}.`);
}
```

### on('mainWindowFullScreenAcrossDisplaysChanged')<sup>20+</sup>

on(type: 'mainWindowFullScreenAcrossDisplaysChanged', callback: Callback&lt;boolean&gt;): void

Subscribes to events indicating whether the main window is in full-screen mode across multiple displays.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'mainWindowFullScreenAcrossDisplaysChanged'**, indicating changes in whether the main window is in full-screen mode across multiple displays.|
| callback | Callback&lt;boolean&gt;   | Yes  | Callback used to return the result indicating whether the main window is in full-screen mode across multiple displays. **true** if yes, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**Example**

```ts
const callback = (mainWindowFullScreenAcrossDisplaysChanged: boolean) => {
  console.info(`main window across displays changed. Data: ${mainWindowFullScreenAcrossDisplaysChanged}`);
}
try {
  windowClass.on('mainWindowFullScreenAcrossDisplaysChanged', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
### off('mainWindowFullScreenAcrossDisplaysChanged')<sup>20+</sup>

off(type: 'mainWindowFullScreenAcrossDisplaysChanged', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from events indicating whether the main window is in full-screen mode across multiple displays.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                    | Yes  | Event type. The value is fixed at **'mainWindowFullScreenAcrossDisplaysChanged'**, indicating changes in whether the main window is in full-screen mode across multiple displays.|
| callback | Callback&lt;boolean&gt;    | No  | Callback used to return the result indicating whether the main window is in full-screen mode across multiple displays. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**Example**

```ts
const callback = (mainWindowFullScreenAcrossDisplaysChanged: boolean) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('mainWindowFullScreenAcrossDisplaysChanged', callback);
  // Disable the listening of a specified callback.
  windowClass.off('mainWindowFullScreenAcrossDisplaysChanged', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('mainWindowFullScreenAcrossDisplaysChanged');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowContainerModalColor<sup>20+</sup>

setWindowContainerModalColor(activeColor: string, inactiveColor: string): void

Sets the background color of the main window container for both when it has focus and when it does not. In the stage model, you need to call this API after [loadContent()](arkts-apis-window-Window.md#loadcontent9) or [setUIContent()](arkts-apis-window-Window.md#setuicontent9).

The background color you set here covers the entire window, including both the title bar and the content area. If you also use [setWindowBackgroundColor()](arkts-apis-window-Window.md#setwindowbackgroundcolor9), the content area shows the window background color, whereas the title bar shows the container background color.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| activeColor | string | Yes| Background color of the window container when it is focused. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**.|
| inactiveColor | string | Yes| Background color of the window container when it is not focused. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.                      |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent("pages/page2", (err: BusinessError) => {
      let errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
      // Obtain the main window.
      let windowClass: window.Window | undefined = undefined;
      windowStage.getMainWindow((err: BusinessError, data) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        let activeColor: string = '#00000000';
        let inactiveColor: string = '#FF000000';
        try {
          windowClass.setWindowContainerModalColor(activeColor, inactiveColor);
          console.info('Succeeded in setting window container color.');
        } catch (exception) {
          console.error(`Failed to set the window container color. Cause code: ${exception.code}, message: ${exception.message}`);
        };
      });
    });
  }
}
```

### setTopmost<sup>12+</sup>

setTopmost(isTopmost: boolean): Promise&lt;void&gt;

Called by the main window to place the window above all the other windows. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| isTopmost | boolean | Yes  | Whether to pin the main window on top. **true** to pin, **false** otherwise.|

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
    windowStage.getMainWindow().then((mainWindow) => {
      let isTopmost: boolean = true;
      mainWindow.setTopmost(isTopmost).then(() => {
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

The single-frame composer is mainly used in scenarios that require extremely low interaction latency. It reduces the screen display latency of the rendering node.  

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | Yes  | Whether to enable the single-frame composer. **true** to enable, **false** otherwise.|

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
try {
  let promise = windowClass.setSingleFrameComposerEnabled(enable);
  promise.then(()=> {
      console.info('Succeeded in enabling the single-frame-composer function.');
  }).catch((err: BusinessError)=>{
      console.error(`Failed to enable the single-frame-composer function. code:${err.code}, message:${err.message}.`);
  });
} catch (exception) {
  console.error(`Failed to enable the single-frame-composer function. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTitleButtonVisible<sup>12+</sup>

setTitleButtonVisible(isMaximizeVisible: boolean, isMinimizeVisible: boolean, isSplitVisible: boolean): void

Shows or hides the maximize, minimize, and split-screen buttons on the title bar of the main window. This API works only in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode.

This API takes effect only for the title bar buttons (maximize, minimize, and split-screen) that are available in the current scenario.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on 2-in-1 devices and tablets. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name   | Type   | Mandatory| Description                                         |
| --------- | ------- | ---- | --------------------------------------------- |
| isMaximizeVisible | boolean | Yes  | Whether to show the maximize button. **true** to show, **false** otherwise.|
| isMinimizeVisible | boolean | Yes  | Whether to show the minimize button. **true** to show, **false** otherwise.|
| isSplitVisible | boolean | Yes  | Whether to show the split-screen button. **true** to show, **false** otherwise.|

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
      if (err?.code) {
        console.error(`Failed to load content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      let mainWindow: window.Window | undefined = undefined;
      // Obtain the main window.
      windowStage.getMainWindow().then(
        data => {
          if (!data) {
            console.error('Failed to get main window.');
            return;
          }
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

Allows this window to proactively request to gain or lose focus. This API uses a promise to return the result. A value is returned as long as the API is successfully called. The return value does not indicate that the window has gained or lost focus. You can use [on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10) to listen for the focus status of the window.

When a focus request is sent, whether the window can successfully gain focus depends on its capability of being focused and its current visibility. To gain focus, the window must be capable of receiving focus and in a visible state (actively displayed and not hidden or destroyed).

Conversely, once a blur request is sent, the window will lose focus without any conditions.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| isFocused | boolean | Yes  | Whether to gain or lose focus. **true** to gain focus, **false** otherwise.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
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

Describes the parameters used for creating a child window.

| Name     | Type | Read-Only| Optional| Description        |
| ---------- | ---- | ---- | ---- | ----------- |
| isTopmost<sup>12+</sup>  | boolean | No| Yes| Whether the child window is topmost. **true** if topmost, **false** otherwise. The default value is **false**.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|

## WindowStage<sup>9+</sup>

Implements a window manager, which manages each basic window unit, that is, [Window](arkts-apis-window-Window.md) instance.

Before calling any of the following APIs, you must use [onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate) to create a WindowStage instance.

### disableWindowDecor<sup>9+</sup>

disableWindowDecor(): void

Disables window decorators.

When window decorators are disabled and the main window transitions into full-screen mode, hovering the cursor over the hot zone of the top window's title bar will cause a floating title bar to appear. To prevent the floating title bar from appearing, call [setTitleAndDockHoverShown()](arkts-apis-window-Window.md#settitleanddockhovershown14).

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
    console.info('disableWindowDecor');
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
| showOnLockScreen | boolean | Yes  | Whether to display the window on the lock screen. **true** to display, **false** otherwise.|

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
    console.info('onWindowStageCreate');
    try {
      windowStage.setShowOnLockScreen(true);
    } catch (exception) {
      console.error(`Failed to show on lockscreen. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### setImageForRecent<sup>19+</sup>

setImageForRecent(imgResourceId: number, value: ImageFit): Promise&lt;void&gt;

Sets the image displayed in the multitasking window. This API uses a promise to return the result.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| imgResourceId | number | Yes  | Resource ID of the custom image. The image must be stored in the **resources/base/media** directory and its resource ID can be obtained using the **$r** resource access mode. For example, to obtain the resource ID of the startIcon image, use the following: $r("app.media.startIcon").id.|
| value | [ImageFit](arkui-ts/ts-appendix-enums.md#imagefit) | Yes| Fill mode of the custom image.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. 2. Invalid parameter length. 3. Incorrect parameter format. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    let imgResourceId = $r("app.media.startIcon").id
    try {
      let promise = windowStage.setImageForRecent(imgResourceId, ImageFit.Fill);
      promise.then(() => {
        console.info(`Succeeded in setting image for recent`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to set image for recent. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set image for recent.`);
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

| Name                 | Type         | Read-Only| Optional| Description            |
| --------------------- | ----------------- | ---- | ---- | ---------------- |
| toWindow<sup>9+</sup> | [Window](arkts-apis-window-Window.md) | No  | No  | Target window to display the animation.|

### completeTransition<sup>9+</sup>

completeTransition(isCompleted: boolean): void

Completes the transition. This API can be called only after [animateTo()](arkui-ts/ts-explicit-animation.md) is executed.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isCompleted | boolean | Yes  | Whether the transition is complete. **true** if complete, **false** otherwise.|

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
  this.getUIContext()?.animateTo({
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
    toWindow?.translate(obj);
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
  private animationForShownCallFunc_: ((context : window.TransitionContext) => void) | undefined = undefined;
  ShowWindowWithCustomAnimation(windowClass: window.Window, callback: (context : window.TransitionContext) => void) {
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
    this.getUIContext()?.animateTo({
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
      toWindow?.translate(obj); // Set the transition animation.
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
  private animationForHiddenCallFunc_: ((context : window.TransitionContext) => void) | undefined = undefined;
  HideWindowWithCustomAnimation(windowClass: window.Window, callback: (context : window.TransitionContext) => void) {
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
    this.getUIContext()?.animateTo({
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
      toWindow?.translate(obj); // Set the transition animation.
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
| SUB_WINDOW  | 1 | child window.|

## SystemWindowOptions<sup>14+</sup>

Describes the parameters for creating a system window.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type                     | Read-Only |Optional| Description      |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowType   | [WindowType](#windowtype7) | No  | No  | Window type. There is no default value. If null is passed in, the window fails to be created. **TYPE_DIALOG** is not supported.|

## ExtensionWindowConfig<sup>14+</sup>

Describes the parameters for creating a window for a UI ServiceExtensionAbility.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name| Type                     | Read-Only |Optional| Description      |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowName   | string | No| No | Window name.|
| windowAttribute   | [ExtensionWindowAttribute](#extensionwindowattribute14) | No| No  | Window attribute. It specifies whether the created window is a child window or a system window. When **windowAttribute** is set to **SUB_WINDOW**, **subWindowOptions** is mandatory. When **windowAttribute** is set to **SYSTEM_WINDOW**, **systemWindowOptions** is mandatory. Otherwise, the window fails to be created.|
| windowRect   | [Rect](arkts-apis-window-i.md#rect7) | No| No  | Rectangular area of the window.|
| subWindowOptions   | [SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11) | No| Yes| Parameters used for creating a child window. There is no default value. This parameter is mandatory when **windowAttribute** is set to **SUB_WINDOW**. Otherwise, the window fails to be created.|
| systemWindowOptions   | [SystemWindowOptions](#systemwindowoptions14) | No| Yes| Parameters for creating a system window. There is no default value. This parameter is mandatory when **windowAttribute** is set to **SYSTEM_WINDOW**. Otherwise, the window fails to be created.|

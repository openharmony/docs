# @ohos.window (Window) (System API)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
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
>
> - For the system capability SystemCapability.Window.SessionManager, use [canIUse()](../common/js-apis-syscap.md#caniuse) to check whether the device supports this system capability and the corresponding APIs.

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
| TYPE_DYNAMIC<sup>20+</sup> | 25      | System window that allows for adjustable z-levels.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager<br>**Device behavior differences**: This API can be properly called on phones, PCs/2-in-1 devices, and tablets, but does not take effect or report errors when being called on other devices.|
| TYPE_MUTISCREEN_COLLABORATION<sup>20+</sup> | 26      | Window for multi-screen collaboration.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|

## Configuration<sup>9+</sup>

Defines the parameters for creating a child window or system window.

**System API**: This is a system API.

| Name| Type| Read-Only| Optional| Description                      |
| ---------- | --------- | ---- | ---- |-------------- |
| zIndex<sup>20+</sup>       | number | No| Yes| Z-level of the system window. This parameter is valid only when [WindowType](#windowtype7) is set to **TYPE_DYNAMIC**. If this parameter is not passed, the default level is used.<br>**System capability**: SystemCapability.Window.SessionManager|
| defaultDensityEnabled<sup>20+</sup> | boolean| No| Yes|Whether the window should use the default density of the system. If the default density is used, the window does not re-layout when the system display size changes.<br>If this parameter is set to **true** for a system window, the window uses the default density and is not affected by [setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12) or [setCustomDensity()](arkts-apis-window-WindowStage.md#setcustomdensity15) settings for the main window or [setDefaultDensityEnabled()](#setdefaultdensityenabled20) settings for the current window.<br>If this parameter is set to **false**, the window does not use the default density and is affected by those settings.<br>The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|

## WindowMode<sup>7+</sup>

Enumerates the window modes.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 1    | The window mode is not defined by the application.      |
| FULLSCREEN | 2    | The application is displayed in full screen.            |
| PRIMARY    | 3    | The application is displayed in the primary window in split-screen mode. In top-bottom splits, the top screen is primary; in left-right splits, the left screen is primary. |
| SECONDARY  | 4    | The application is displayed in the secondary window in split-screen mode. In top-bottom splits, the bottom screen is secondary; in left-right splits, the right screen is secondary. |
| FLOATING   | 5    | The application is displayed in a floating window.|

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

Describes the start animation configuration. This API works only for full-screen applications.

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
| isWindowLimitsForcible | boolean | No| Yes| Whether the dimensions of the main window of an application can exceed the default system limit. This parameter takes effect only when the started application is a system application. Otherwise, this parameter does not take effect and no error is reported.<br> - **true**: The default system limit can be exceeded. During the calculation of the window dimensions limit, the default system limit is ignored. The final effective result is still calculated based on the intersection of each source, and the priority remains unchanged. For details, see [WindowLimits](arkts-apis-window-i.md#windowlimits11).<br> - **false**: The default system limit cannot be exceeded. The window dimensions limit is calculated based on the default rules (including the default system limit).<br>The default value is **false**.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## WindowAnchorInfo<sup>24+</sup>

Describes the anchor point information used to maintain the relative position between the level-1 child window and the main window.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

| Name            | Type                                                                    | Read-Only| Optional| Description                                                        |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| anchorType             | [WindowAnchor](arkts-apis-window-e.md#windowanchor20)                 | No  | No  | Type of the anchor point used to maintain the relative position.|
| offsetX             |     number           | No  | Yes  | X-axis offset between the anchor points of the child window and the main window, in px. The value must be an integer. Floating-point numbers are rounded down. The default value is **0**.|
| offsetY             |     number           | No  | Yes  | Y-axis offset between the anchor points of the child window and the main window, in px. The value must be an integer. Floating-point numbers are rounded down. The default value is **0**.|

## SubWindowAttachOptions<sup>24+</sup>

Describes the parameters used to maintain the relative position between the child window and the main window.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

| Name            | Type                                                                    | Read-Only| Optional| Description                                                        |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| currentLayoutMode             | string               | No  | Yes  | Current layout mode of the child window, which is used to control the UI effect customized by the application. If this parameter is not passed, the default value is an empty string.|
| parentWindowSizeChangeCallback             |     Callback&lt;[Size](arkts-apis-window-i.md#size7)&gt;           | No  | Yes  | Callback triggered when the parent window size changes. The callback is triggered immediately after the binding, and notifications are sent when the parent window size changes. By default, this parameter is not passed, and notifications about the parent window size changes cannot be received.|
| parentWindowStatusChangeCallback             |     Callback&lt;[WindowStatusType](arkts-apis-window-e.md#windowstatustype11)&gt;           | No  | Yes  | Callback triggered when the parent window mode changes. The callback is triggered immediately after the binding, and notifications are sent when the parent window mode changes. By default, this parameter is not passed, and notifications about the parent window mode changes cannot be received.|
| isIntersectedWidthLimit | boolean | No| Yes| Whether the width of the child window is mutually restricted with that of the bound main window.<br>The value **true** indicates that the width of the child window and that of the bound main window cannot exceed the intersection of the width limits of the two windows. If there is no intersection between the width limits of the two windows, they do not restrict each other. When this parameter is set to **true** for multiple child windows at the same time, the width of all windows (including the main window) involved in mutual restriction is restricted by the intersection of the width limits of all windows.<br>The value **false** indicates that the width of the child window is not mutually restricted with that of the bound main window.<br>The default value is **false**.<br>**Since**: 26.0.0|
| isIntersectedHeightLimit | boolean | No| Yes| Whether the height of the child window is mutually restricted with that of the bound main window.<br>The value **true** indicates that the height of the child window and that of the bound main window cannot exceed the intersection of the height limits of the two windows. If there is no intersection between the height limits of the two windows, they do not restrict each other. When this parameter is set to **true** for multiple child windows at the same time, the height of all windows (including the main window) involved in mutual restriction is restricted by the intersection of the height limits of all windows.<br>The value **false** indicates that the height of the child window is not mutually restricted with that of the bound main window.<br>The default value is **false**.<br>**Since**: 26.0.0|

## WindowLayoutMode<sup>(deprecated)</sup>

Enumerates the window layout modes.

> **NOTE**
>
> <!--RP4--><!--RP4End-->This API is supported since API version 9 and deprecated since API version 26.0.0. No substitute is provided.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| WINDOW_LAYOUT_MODE_CASCADE<sup>(deprecated)</sup>  | 0    | Cascade mode. In this mode, freeform windows are stacked with Z-order arrangement.<br>Note: <!--RP4--><!--RP4End-->This enumerated value is supported since API version 9 and deprecated since API version 26.0.0. No substitute is provided.|
| WINDOW_LAYOUT_MODE_TILE<sup>(deprecated)</sup> | 1    | Tile mode. In this mode, newly opened application windows appear on the rightmost.<br>Note: <!--RP4--><!--RP4End-->This enumerated value is supported since API version 9 and deprecated since API version 26.0.0. No substitute is provided.|

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

Minimizes all main windows on a display.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: <!--RP1-->This API can be properly called on phones. If it is called on other device types, error code 801 is returned.<!--RP1End-->

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | Yes  | ID of the [display](js-apis-display.md#display). The value must be an integer.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If all main windows on the specified display are minimized successfully, the value of **err** is **undefined**. Otherwise, the value is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br>Applicable versions: 12+|
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

Minimizes all main windows on a display. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: <!--RP1-->This API can be properly called on phones. If it is called on other device types, error code 801 is returned.<!--RP1End-->

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br>Applicable versions: 12+|
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

## window.minimizeAllWithExclusion<sup>23+</sup>
minimizeAllWithExclusion(displayId: number, excludeWindowId: number): Promise&lt;void&gt;

Minimizes all main windows on a display while keeping one window open. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Device behavior differences**: This API can be properly called on phones. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| displayId| number                    | Yes  | Display ID. The value must be an integer. Non-integer values are rounded down.|
| excludeWindowId | number              | Yes  | Window ID. You can call [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window properties, in which **id** is the window ID. If the window ID is less than or equal to 0, or the window ID is null or undefined, error code 401 is thrown. If the window ID is greater than 0 but the window does not exist, error code 1300002 is thrown. If the window ID is greater than 0 but the window exists on another display, all main windows on the specified display are minimized. The value must be an integer. Floating-point numbers are rounded down.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. Possible cause: 1.Window is nullptr; 2. Failed to find specified window by id. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { display, window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let displayClass: display.Display | null = null;
displayClass = display.getDefaultDisplaySync();
let excludeWindowId = 1;

try {
  let promise = window.minimizeAllWithExclusion(displayClass.id, excludeWindowId);
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
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. When the application window is successfully hidden or restored, the value of **err** is **undefined**. Otherwise, the value is an error object.  |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br>Applicable versions: 12+|
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br>Applicable versions: 12+|
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

Sets whether to enable gesture navigation for the current application. This API uses an asynchronous callback to return the result. For security purposes, the system does not interfere with the disabling and enabling of gesture navigation. If an application exits abnormally after it disables gesture navigation and wants to restore gesture navigation, it must implement automatic launch and call this API again to enable gesture navigation.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| enable   | boolean                  | Yes  | Whether to enable gesture navigation for the current application. **true** to enable, **false** otherwise. After gesture navigation is disabled, only the pull-down gesture from the top of the screen is disabled. Other gestures are not affected.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. When the enabled state of the gesture navigation is set successfully, the value of **err** is **undefined**. Otherwise, the value is an error object.|

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

Sets whether to enable gesture navigation for the current application. This API uses a promise to return the result. For security purposes, the system does not interfere with the disabling and enabling of gesture navigation. If an application exits abnormally after it disables gesture navigation and wants to restore gesture navigation, it must implement automatic launch and call this API again to enable gesture navigation.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type    | Mandatory | Description                |
| ------ | ------- | ---- | -------------------- |
| enable | boolean | Yes  | Whether to enable gesture navigation for the current application. **true** to enable, **false** otherwise. After gesture navigation is disabled, only the pull-down gesture from the top of the screen is disabled. Other gestures are not affected.|

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
| enable   | boolean                  | Yes  | Whether to display the watermark image. **true** means that the watermark image is displayed, and **false** means the opposite. After the watermark is set to display, you need to set this parameter to **false** to close the watermark.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. When the watermark display state is set successfully, the value of **err** is **undefined**. Otherwise, the value is an error object.|

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
let color: ArrayBuffer = new ArrayBuffer(40000);
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
| enable   | boolean                  | Yes  | Whether to display the watermark image. **true** means that the watermark image is displayed, and **false** means the opposite. After the watermark image is displayed, you need to set this parameter to **false** to disable the watermark display.|

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
let color: ArrayBuffer = new ArrayBuffer(40000);
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

## window.setWaterMarkImage
setWaterMarkImage(pixelMap: image.PixelMap, enable: boolean, priority: number): Promise&lt;void&gt;

Sets the display status of a watermark image on the screen and the watermark priority. This API uses a promise to return the result. When **priority** is set to 0, this API is equivalent to [setWaterMarkImage](#windowsetwatermarkimage10).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                       | Mandatory | Description                |
| ------ | --------------------------- | ---- | -------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | Yes| Watermark image, which can be obtained by calling [createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8).|
| enable   | boolean                  | Yes  | Whether to display the watermark image. **true** means that the watermark image is displayed, and **false** means the opposite. After the watermark image is displayed, you need to set this parameter to **false** to disable the watermark display.|
| priority   | number                  | Yes  | Watermark priority. A smaller value indicates a higher priority. The value must be greater than or equal to 0. If the value is less than 0, error code 1300016 is returned. If the input priority in this watermark setting is lower than the previous setting, the current setting does not take effect.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: Invalid parameter range. |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;
let color: ArrayBuffer = new ArrayBuffer(40000);
let initializationOptions: image.InitializationOptions = {
  size: {
    height: 100,
    width: 100
  }
};
image.createPixelMap(color, initializationOptions).then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelmap.');
  try {
    window.setWaterMarkImage(pixelMap, enable, 0).then(() => {
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
| 1300002  | This window state is abnormal. Possible cause: Internal task error. |
| 1300003  | This window manager service works abnormally. |

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

## window.setSpecificSystemWindowZIndex<sup>23+</sup>
setSpecificSystemWindowZIndex(windowType: WindowType, zIndex: number): Promise&lt;void&gt;

Adjusts the display level (z-index) of system windows of a specified type. A larger value indicates that the window is closer to the top. This API uses a promise to return the result.

- This API affects only the overall level range of windows of the same type. The relative order of windows of this type and the currently focused window remain unchanged.

- If the specified **zIndex** conflicts with an existing window (which has been occupied by another type), the relative levels of the conflicting windows remain unchanged, and the system automatically coordinates the levels based on internal rules.

- After the application exits, the level of the specified window type is automatically restored to the default value.

- You are advised to assign different **zIndex** values to different types of windows to avoid conflicts and achieve a clearer and more controllable level effect.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on phones, PCs/2-in-1 devices, and tablets, but does not take effect or report errors when being called on other devices.

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| windowType | [WindowType](#windowtype7) | Yes   | Window type. Only the following types are supported: **TYPE_WALLET_SWIPE_CARD**, **TYPE_VOICE_INTERACTION**, **TYPE_SCREENSHOT**, **TYPE_SCREEN_CONTROL**, **TYPE_FLOAT_NAVIGATION**, and **TYPE_MUTISCREEN_COLLABORATION**.|
| zIndex | number | Yes   | Z-level of the system window. The value must be an integer. The value range is (-∞, +∞). If a floating-point number is entered, it will be rounded down. The value **0** or a negative number will place the window below the home screen.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. |

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
try {
  window.setSpecificSystemWindowZIndex(window.WindowType.TYPE_WALLET_SWIPE_CARD, 200).then(() => {
    console.info('Succeeded in setting zIndex');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set zIndex. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set zIndex. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.createSubWindowAndBindParent

createSubWindowAndBindParent(name: string, parentId: number, ctx: BaseContext, parentWindowEventListener: WindowEventListener): Promise\<Window\>

Creates a subwindow and binds it to the parent window. This API uses a promise to return the result.

Only the main window can be bound as the parent window.

The subwindow is displayed or hidden along with the parent window, but is not destroyed when the parent window is destroyed. The subwindow listens to the lifecycle changes of the parent window through a callback function.

It is recommended that you destroy the created subwindow after the parent window is destroyed.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                    | Mandatory| Description                                               |
| -------- | ----------------------- | -- |---------------------------------------------------|
| name | string | Yes| Window name.|
| parentId | number | Yes| Parent window ID. You are advised to call [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) to obtain the window ID.|
| ctx | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes| Current application context.|
| parentWindowEventListener | [WindowEventListener](arkts-apis-window-t.md#windoweventlistener) | Yes| Callback used to return the lifecycle changes of the bound parent window.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise used to return the child window created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. This cannot work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. Possible cause: The window has been created and cannot be created again. |
| 1300002 | This window state is abnormal. Possible cause: 1. Internal task error. 2. The number of windows has reached the limit. |
| 1300003 | This window manager service works abnormally. |
| 1300009 | The parent window is invalid. Possible cause: 1. The parent window does not exist or has been destroyed. 2. Invalid window type. Only main windows are supported.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    let windowClass: window.Window | undefined = undefined;
    const parentWindowEventListener = (windowId: number, event: window.WindowEventType) => {
      // ...
    }
    try {
      // It is recommended that parentId be obtained using the getWindowProperties API. The following is only an example.
      let promise = window.createSubWindowAndBindParent('test', 100, this.context, parentWindowEventListener);
      promise.then((data) => {
        console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
        windowClass = data;
      }).catch((err: BusinessError) => {
        console.error(`Failed to create the Window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.moveMainWindowToTargetDisplay
moveMainWindowToTargetDisplay(displayId: number, windowId: number): Promise&lt;void&gt;

Moves the specified main window to the specified display. This API uses a promise to return the result.

- For window movement between the displays of a [main screen](../../displaymanager/display-terminology.md#main-screen) or an [extended screen](../../displaymanager/display-terminology.md#extended-screen) and a [virtual screen](../../displaymanager/display-terminology.md#virtual-screen), or of virtual screens, only the main window, child windows, and modal windows are moved to the corresponding display and raised. If there are child windows, the topmost child window that can obtain focus will obtain the focus; otherwise, the main window will obtain the focus.
- For window movement between the displays of a main screen and an extended screen, only the main window is moved to the corresponding display and raised.

<!--RP3--><!--RP3End-->

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| displayId | number | Yes   | ID of the display to which the window is moved. The value must be a non-negative integer. You can obtain the value by calling [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9) to obtain [properties](arkts-apis-window-i.md#windowproperties) and then using **properties.displayId**. You can also obtain the value by using [id](js-apis-display.md#attributes) of the [Display](js-apis-display.md#display) object.|
| windowId | number | Yes   | ID of the window to be moved. The value must be an integer greater than 0. You can obtain the value by calling [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9) to obtain [properties](arkts-apis-window-i.md#windowproperties) and then using **properties.id**.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300008 | The display device is abnormal.           |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { display, window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.loadContent('pages/Index', (err: BusinessError) => {
      if (err.code) {
        console.error(`Failed to load content for main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      let displayClass: display.Display | null = null;
      displayClass = display.getDefaultDisplaySync();
      let mainWindow = windowStage.getMainWindowSync();
      try {
        window.moveMainWindowToTargetDisplay(displayClass.id, mainWindow.getWindowProperties().id).then(() => {
          console.info(`Succeeded in moving window id: ${mainWindow.getWindowProperties().id} to target display id: ${mainWindow.getWindowProperties().displayId}`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to move window to target display. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to move window to target display. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

## window.setWindowLayoutMode<sup>(deprecated)</sup>
setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback&lt;void&gt;): void

Sets the window layout mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> <!--RP4--><!--RP4End-->This API is supported since API version 9 and deprecated since API version 26.0.0. No substitute is provided.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmodedeprecated)                  | Yes  | Window layout mode to set.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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

## window.setWindowLayoutMode<sup>(deprecated)</sup>
setWindowLayoutMode(mode: WindowLayoutMode): Promise&lt;void&gt;

Sets the window layout mode. This API uses a promise to return the result.

> **NOTE**
>
> <!--RP4--><!--RP4End-->This API is supported since API version 9 and deprecated since API version 26.0.0. No substitute is provided.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmodedeprecated)                  | Yes  | Window layout mode to set.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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

Hides this window and plays an animation during the process. This API uses an asynchronous callback to return the result. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Hides this window and plays an animation during the process. This API uses a promise to return the result. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Shows this window and plays an animation during the process. This API uses an asynchronous callback to return the result. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Shows this window and plays an animation during the process. This API uses a promise to return the result. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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

### attachLayoutToParentWindow<sup>24+</sup>

attachLayoutToParentWindow(anchorInfo?: WindowAnchorInfo, attachOptions?: SubWindowAttachOptions): Promise&lt;void&gt;

Attaches a first-level child window to the main window to maintain a fixed relative position. This API uses a promise to return the result.

The relative position is represented by the anchor point offset between the child window and the parent window. The child window and the parent window use the same window anchor point.

This API can be called by non-[independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window). When this API is called by [independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window), error code 1300004 will be returned.

> **NOTE**
>
> - Only first-level child windows can call this API. The child window must be in floating window mode (that is, the window mode is **window.WindowStatusType.FLOATING**).
>
> - After the child window calls this API, the display position of the child window immediately follows the main window and the relative position remains unchanged. In addition, the size and mode changes of the main window can be listened to. The effect will persist unless the [detachLayoutToParentWindow()](#detachlayouttoparentwindow24) API is called for detaching.
>
> - After the child window calls this API, calling APIs such as [moveWindowTo()](arkts-apis-window-Window.md#movewindowto9), [maximize()](arkts-apis-window-Window.md#maximize12), and [setFollowParentWindowLayoutEnabled()](arkts-apis-window-Window.md#setfollowparentwindowlayoutenabled17) to change the window position, or dragging and moving or dragging and resizing the child window through mouse or touch operations will not take effect.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be called properly on a device that supports [freeform windows](../../windowmanager/window-terminology.md#freeform-window) and is in the freeform window state. If the device supports freeform windows but is not in the freeform window state, no error is thrown and this API does not take effect until the device is in the freeform window state. If the device does not support freeform windows, this API does not take effect and no error is reported.

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| anchorInfo       | [WindowAnchorInfo](#windowanchorinfo24)                    | No  | Anchor point information used to attach the first-level child window to the main window to maintain the fixed relative position. If this parameter is not passed, the default logic is the same as that of [WindowAnchorInfo](#windowanchorinfo24).|
| attachOptions       | [SubWindowAttachOptions](#subwindowattachoptions24)                    | No  | Additional parameters for setting the child window layout. If this parameter is not passed, the default logic is the same as that of [SubWindowAttachOptions](#subwindowattachoptions24).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function attachLayoutToParentWindow can not work correctly due to limited device capabilities.|
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally.|
| 1300004 | Unauthorized operation. Possible cause: 1. Invalid window type. Only subwindows are supported; 2. The current window's parent window is not a main window; 3. Only level-1 subwindows are supported.|
| 1300010 | The operation in the current window status is invalid. Possible cause: 1. The subwindow is following its parent window's layout. 2. The subwindow is not in floating mode.|

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (loadError: BusinessError) => {
      if (loadError.code) {
        console.error(`Failed to load the content. Cause code: ${loadError.code}, message: ${loadError.message}`);
        return;
      }
      console.info("Succeeded in loading the content.");
      windowStage.createSubWindow("subWindow").then((subWindow: window.Window) => {
        if (subWindow == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        let anchorInfo : window.WindowAnchorInfo = {
          anchorType: window.WindowAnchor.TOP_START,
          offsetX: 0,
          offsetY: 0
        };
        let attachOptions: window.SubWindowAttachOptions = {
          parentWindowSizeChangeCallback:(data: window.Size) => {
            console.info(`Successfully accepted parentWindow size change, width: ${data.width}, height: ${data.height}`);
          },
          parentWindowStatusChangeCallback:(type: window.WindowStatusType) => {
            console.info(`Successfully accepted parentWindow status change, statusType: ${type}`);
          },
          isIntersectedWidthLimit: true,
          isIntersectedHeightLimit: true
        }
        subWindow.attachLayoutToParentWindow(anchorInfo, attachOptions).then(() => {
          console.info("Succeeded in attaching to the main window");
        }).catch((error: BusinessError) => {
          console.error(`attachLayoutToParentWindow failed. ${error.code} ${error.message}`);
        })
      }).catch((error: BusinessError) => {
        console.error(`createSubWindow failed. ${error.code} ${error.message}`);
      })
    });
  }
}
```

### detachLayoutToParentWindow<sup>24+</sup>

detachLayoutToParentWindow(): Promise&lt;void&gt;

Detach a first-level child window from the main window to cancel a fixed relative position. This API uses a promise to return the result.

This API can be called by non-[independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window). When this API is called by [independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window), error code 1300004 will be returned.

> **NOTE**
>
> - When the child window calls this API, the child window must be in the attached state.
>
> - After detached by calling this API, the child window retains its position during attaching. You can drag the child window to change its size and position.
>
> - After the detaching, calling APIs such as [moveWindowTo()](arkts-apis-window-Window.md#movewindowto9), [maximize()](arkts-apis-window-Window.md#maximize12), and [setFollowParentWindowLayoutEnabled()](arkts-apis-window-Window.md#setfollowparentwindowlayoutenabled17) to change the window position, or dragging and moving or dragging and resizing the child window through mouse or touch operations will take effect.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be called properly on a device that supports [freeform windows](../../windowmanager/window-terminology.md#freeform-window) and is in the freeform window state. If the device supports freeform windows but is not in the freeform window state, no error is thrown and this API does not take effect until the device is in the freeform window state. If the device does not support freeform windows, this API does not take effect and no error is reported.

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function detachLayoutToParentWindow can not work correctly due to limited device capabilities.|
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally.|
| 1300004 | Unauthorized operation. Possible cause: 1. Invalid window type. Only subwindows are supported; 2. Only level-1 subwindows are supported.|
| 1300010 | The operation in the current window status is invalid. Possible cause: The subwindow is not attached to the main window.|

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (loadError: BusinessError) => {
      if (loadError.code) {
        console.error(`Failed to load the content. Cause code: ${loadError.code}, message: ${loadError.message}`);
        return;
      }
      console.info("Succeeded in loading the content.");
      windowStage.createSubWindow("subWindow").then((subWindow: window.Window) => {
        if (subWindow == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        subWindow.detachLayoutToParentWindow().then(() => {
          console.info("Succeeded in detaching to the main window");
        }).catch((error: BusinessError) => {
          console.error(`detachLayoutToParentWindow failed. ${error.code} ${error.message}`);
        })
      }).catch((error: BusinessError) => {
        console.error(`createSubWindow failed. ${error.code} ${error.message}`);
      })
    });
  }
}
```

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;, callback: AsyncCallback&lt;void&gt;): void

Binds the modal window to the target window. After the binding is successful, the target window cannot respond to user operations. In addition, a callback used to listen for modal window destruction events is added. This API uses an asynchronous callback to return the result.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { rpc } from '@kit.IPCKit';
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class Property {
  public value: Object

  constructor(value: Object) {
    this.value = value
  }
}

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest');
    let config: window.Configuration = {
      name: 'test',
      windowType: window.WindowType.TYPE_DIALOG,
      ctx: this.context
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
        let token = want.parameters?.['ohos.ability.params.request.token'] as Property;
        let value = token.value as rpc.RemoteObject;
        data.bindDialogTarget(value, () => {
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

bindDialogTarget(token: rpc.RemoteObject, deathCallback: Callback&lt;void&gt;): Promise&lt;void&gt;

Binds the modal window to the target window. After the binding is successful, the target window cannot respond to user operations. In addition, a callback used to listen for modal window destruction events is added. This API uses a promise to return the result.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { rpc } from '@kit.IPCKit';
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class Property {
  public value: Object

  constructor(value: Object) {
    this.value = value
  }
}

export default class ServiceExtAbility extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest');
    let config: window.Configuration = {
      name: 'test',
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
        let token = want.parameters?.['ohos.ability.params.request.token'] as Property;
        let value = token.value as rpc.RemoteObject;
        let promise = data.bindDialogTarget(value, () => {
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

### bindDialogTarget<sup>9+</sup>

bindDialogTarget(requestInfo: dialogRequest.RequestInfo, deathCallback: Callback&lt;void&gt;, callback: AsyncCallback&lt;void&gt;): void

Binds the modal window to the target window. After the binding is successful, the target window cannot respond to user operations. In addition, a callback used to listen for modal window destruction events is added. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                     | Mandatory| Description                 |
| ----------- | ------------------------- | ---- | -------------------- |
| requestInfo | [dialogRequest.RequestInfo](../apis-ability-kit/js-apis-app-ability-dialogRequest.md#requestinfo) | Yes  | Request information of the target window.|
| deathCallback | Callback&lt;void&gt;    | Yes  | Callback used to listen for modal window destruction events.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
      name: 'test', windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
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

Binds the modal window to the target window. After the binding is successful, the target window cannot respond to user operations. In addition, a callback used to listen for modal window destruction events is added. This API uses a promise to return the result.

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
      name: 'test', windowType: window.WindowType.TYPE_DIALOG, ctx: this.context
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
| isSkip | boolean | Yes  | Whether to ignore the window. The default value is **false**.<br>**true** to ignore, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
let isSkip: boolean = true;
try {
  windowClass.setSnapshotSkip(isSkip);
} catch (exception) {
  console.error(`Failed to Skip. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### opacity<sup>9+</sup>

opacity(opacity: number): void

Sets the opacity for this window. This API can be used only when you [customize an animation to be played during the display or hiding](../../windowmanager/system-window-stage-sys.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window) of a system window, global floating window, and modal window.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Sets the scale parameters for this window. This API can be used only when you [customize an animation to be played during the display or hiding](../../windowmanager/system-window-stage-sys.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window) of a system window, global floating window, and modal window.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Sets the rotation parameters for this window. This API can be used only when you [customize an animation to be played during the display or hiding](../../windowmanager/system-window-stage-sys.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window) of a system window, global floating window, and modal window.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Sets the translation parameters for this window. This API can be used only when you [customize an animation to be played during the display or hiding](../../windowmanager/system-window-stage-sys.md#customizing-an-animation-to-be-played-during-the-display-or-hiding-of-a-system-window) of a system window, global floating window, and modal window.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Obtains the transition animation controller. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

**Example**

```ts
let controller = windowClass.getTransitionController(); // Obtain the transition animation controller.
```

### setBlur<sup>9+</sup>

setBlur(radius: number): void

Blurs this window. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Blurs the background of this window. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Sets the blur style for the background of this window. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, and modal windows are supported. |

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

Sets the shadow for the window borders. This API can be used only for system windows, application subwindows, global floating windows, and modal windows.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type  | Mandatory| Description                                                                      |
| ------- | ------ | ---- |--------------------------------------------------------------------------|
| radius  | number | Yes  | Radius of the shadow. The value is a floating-point number greater than or equal to 0.0, in px. The value **0.0** means that the shadow is disabled for the window borders.           |
| color   | string | No  | Color of the shadow. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**. The default value is **'#000000'**.|
| offsetX | number | No  | Offset of the shadow along the x-axis, in px. The value is a floating-point number, in px. The default value is **0.0**.                                   |
| offsetY | number | No  | Offset of the shadow along the y-axis, in px. The value is a floating-point number, in px. The default value is **0.0**.                                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300004 | Unauthorized operation. Invalid window type. Only system windows, global floating windows, modal windows and subwindows are supported. |

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

Sets the radius of the rounded corners for this window. This API can be used only for system windows, global floating windows, and modal windows.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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

### raiseToAppTop<sup>10+</sup>

raiseToAppTop(callback: AsyncCallback&lt;void&gt;): void

Raises the application child window to the top layer of the application. This API uses an asynchronous callback to return the result.

Before calling this API, ensure that the child window has been created and [showWindow()](arkts-apis-window-Window.md#showwindow9) has been successfully executed.

This API can be called by non-[independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window). This API does not take effect and no error is reported when it is called by [independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window).

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
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. The window is not shown. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows are supported. |
| 1300009 | The parent window is invalid. Possible cause: The parent window does not exist or has been destroyed. |

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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

Application scenario: This API is used in scenarios where the system needs to respond to stylus input, such as handwriting note-taking, drawing, and electronic whiteboard applications.

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

This API can be called by non-[independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window). This API does not take effect and no error is reported when it is called by [independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window).

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
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. The window or target window is not shown. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows are supported. |
| 1300009 | The parent window is invalid. Possible cause: The parent window does not exist or has been destroyed. |

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

This API can be called by non-[independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window). This API does not take effect and no error is reported when it is called by [independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window).

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
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. The window or target window is not shown. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows are supported. |
| 1300009 | The parent window is invalid. Possible cause: The parent window does not exist or has been destroyed. |

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
          windowClass.raiseAboveTarget(targetId).then(() => {
            console.info('Succeeded in raising the subWindow to target subWindow top.');
          }).catch((err: BusinessError) => {
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

Moves the main window above another main window within the same application, with child windows following their parents' layer change. This API uses a promise to return the result.

This API can be called only by the main window of a system application.

You need to pass the ID of the target main window. Both the calling window and the target window must be in the same application process, displayed on the same physical screen, below the lock screen layer, not topmost, not modal, and have no application-modal child windows.

- If the application's main window or its child windows currently have focus, calling this API to lower the layer will cause the window to lose focus automatically, and the highest-layered application window will gain focus.

- If the main window calls this API to move above the current focused window, the highest-layered window among the raised main window and its child windows will gain focus. If the main window calls this API without moving above the current focused window, the focus remains unchanged.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be called properly on a device that supports [freeform windows](../../windowmanager/window-terminology.md#freeform-window) and is in the freeform window state. On a device that supports freeform windows but is not in the freeform window state, or on a device that does not support freeform windows, this API returns error code 801.

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | Yes  | ID of the target main window. The value is an integer. It is the value of **properties.id** in [properties](arkts-apis-window-i.md#windowproperties) obtained through [getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9). If the window ID is less than or equal to 0, or the window ID is null or undefined, error code 1300016 is thrown. If the window ID is greater than 0 but the window does not exist, error code 1300002 is thrown.|

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
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported, and target must not be modal or topmost. |
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
// module.json5
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
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. The window is not shown. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only subwindows are supported. |
| 1300009 | The parent window is invalid. Possible cause: The parent window does not exist or has been destroyed. |

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

### setMainWindowRaiseByClickEnabled<sup>23+</sup>

setMainWindowRaiseByClickEnabled(enable: boolean): Promise&lt;void&gt;

Sets whether to enable the main window to raise itself by click. This API uses a promise to return the result.

By default, clicking the main window raises both the main window and its associated child windows. Disabling this feature (by passing **false**) prevents the main window and its child windows from being raised when the main window is clicked, preserving their current state. However, clicking on a child window still raises both the child window and the main window together.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | Yes  | Whether to enable the main window to raise itself by click. **true** to enable, **false** otherwise.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. The window is not shown. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.getMainWindow().then((window: window.Window) => {
      // Load the page corresponding to the main window.
      windowStage.loadContent('pages/Index', (err) => {
        if (err.code) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
        try {
          let raiseEnabled: boolean = false;
          let promise = window.setMainWindowRaiseByClickEnabled(raiseEnabled);
          promise.then(() => {
            console.info('Succeeded in disabling the raise-by-click function.');
          })
        } catch(err) {
          console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
        };
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

**Device behavior differences**: This API has no effect and does not report errors when being called in PCs/2-in-1 devices and other devices in Desktop mode. For other devices and modes, this API can be called properly.

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
import { UIAbility } from '@kit.AbilityKit';

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

**Device behavior differences**: This API has no effect and does not report errors when being called in PCs/2-in-1 devices and other devices in Desktop mode. For other devices and modes, this API can be called properly.

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
import { UIAbility } from '@kit.AbilityKit';
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
        promise.then(() => {
          console.info('Succeeded in hiding the non-system floating windows.');
        }).catch((err: BusinessError) => {
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

If this API, [setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12), and [setCustomDensity](arkts-apis-window-WindowStage.md#setcustomdensity15) are all called, the setting from the last called API will be applied.

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
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

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
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.isMainWindowFullScreenAcrossDisplays();
  promise.then((data: boolean) => {
      console.info(`Succeeded in using isMainWindowFullScreenAcrossDisplays function. Data: ${data}`);
  }).catch((err: BusinessError) => {
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
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows and subwindows are supported. |

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
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows and subwindows are supported. |

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

### setTopmost<sup>12+</sup>

setTopmost(isTopmost: boolean): Promise&lt;void&gt;

Called by the main window to place the window above all the other windows. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**

In versions earlier than <!--RP2-->OpenHarmony 6.1<!--RP2End-->, this API can be called properly on PCs/2-in-1 devices but returns error code 801 on other devices.

Since <!--RP2-->OpenHarmony 6.1<!--RP2End-->, this API can be called properly on a device that supports [freeform windows](../../windowmanager/window-terminology.md#freeform-window) and is in the freeform window state. If the device supports freeform windows but is not in the freeform window state, or if the device does not support freeform windows, this API returns error code 801 when called.

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
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only main windows are supported. |

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

Enables or disables the single-frame composer for a render node. This API uses a promise to return the result.

The single-frame composer is mainly used in scenarios that require extremely low interaction latency. It reduces the screen display latency of the rendering node. If **enable** is set to **true** using **setSingleFrameComposerEnabled**, the single-frame composer is enabled for the render node. Otherwise, the single-frame composer is disabled.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | Yes  | Whether to enable the single-frame composer for a render node. The value **true** means to enable, and **false** means the opposite.|

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
  promise.then(() => {
      console.info('Succeeded in enabling the single-frame-composer function.');
  }).catch((err: BusinessError) => {
      console.error(`Failed to enable the single-frame-composer function. code:${err.code}, message:${err.message}.`);
  });
} catch (exception) {
  console.error(`Failed to enable the single-frame-composer function. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTitleButtonVisible<sup>12+</sup>

setTitleButtonVisible(isMaximizeVisible: boolean, isMinimizeVisible: boolean, isSplitVisible: boolean): void

Sets the visibility of the maximize, minimize, and split-screen buttons on the title bar.

This API can be called only by the main window and [independent child windows](../../windowmanager/window-type-overview.md#auxiliary-window). When this API is called by other windows, error code 1300004 will be returned.

This API takes effect only for the buttons that are available in the current scenario.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be called properly on a device that supports [freeform windows](../../windowmanager/window-terminology.md#freeform-window) and is in the freeform window state. On a device that supports freeform windows but is not in the freeform window state, or on a device that does not support freeform windows, this API returns error code 801.

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
          if (err.code) {
            console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
          }
      });
    });
  }
}
```

### setRotationLocked<sup>22+</sup>

setRotationLocked(locked: boolean): Promise&lt;void&gt;

Allows a [system window](../../windowmanager/window-type-overview.md#system-window) to lock or unlock its own screen-rotation behavior. When locked, the window's orientation remains unchanged. When unlocked, the window's orientation follows the main window's orientation, the system rotation-lock button, and the device's physical rotation sensor. If this API is called by a non-system window, error code 1300029 is thrown. This API uses a promise to return the result.

> **NOTE**
>
> - If the main window sets the display orientation via [setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9) while rotation is locked, the window restores the last orientation request when brought to the foreground after unlocking.
>
> - If the system window sets the display orientation via [setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9) while rotation is locked, the window restores the last orientation request when brought to the foreground with the highest level after unlocking. The rotation lock set by a lower-level window using **setRotationLocked** does not hinder the system window at a higher level to set the display orientation by calling [setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9).
>
> - If the sensor orientation changes while rotation is locked, the last sensor orientation is restored after unlocking.
>
> - If the application calls [setOrientation()](./js-apis-screen-sys.md#setorientation) to set the screen orientation while rotation is locked, that screen‑orientation setting is ignored.
>
> - When rotation is unlocked, the application's display orientation is determined based on the main window's display orientation set via [setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9), the sensor orientation, and more. For details, see [Window Rotation Overview](../../windowmanager/window-rotation.md#overview).
>
> - The API does not affect the launch orientation set by the **orientation** under [**abilities** in the module.json5 file](../../quick-start/module-configuration-file.md#abilities) of the application.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on phones, tablets, and 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| locked | boolean | Yes  | Whether to lock the rotation. **true** to lock, **false** otherwise.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Function setRotationLocked can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300029 | This window type is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let locked: boolean = true;
let promise = windowClass.setRotationLocked(locked);
promise.then(() => {
  console.info('set rotation locked success.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set rotation locked. Cause code: ${err.code}, message: ${err.message}`);
});
```

### getRotationLocked<sup>22+</sup>

getRotationLocked(): boolean

Checks whether the [system window](../../windowmanager/window-type-overview.md#system-window) has its screen rotation locked. If this API is called by a non-system window, error code 1300029 is thrown.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: This API can be properly called on phones, tablets, and 2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| boolean | Check result for whether rotation is currently locked for this system window. **true** if locked, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Function setRotationLocked can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300029 | This window type is invalid. |

**Example**

```ts
try {
  let locked = windowClass.getRotationLocked();
  console.info('Succeeded in getting rotation locked.');
} catch (exception) {
  console.error(`Failed to get rotation locked. Cause code: ${exception.code}, message: ${exception.message}`);
};
```

### requestFocus<sup>13+</sup>

requestFocus(isFocused: boolean): Promise&lt;void&gt;

Requests the current window to gain or lose focus. This API uses a promise to return the result. The return value does not represent the final result. You can use [on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10) to listen for the focus status of the window.

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
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |
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

### setForbidSplitMove<sup>(deprecated)</sup>

setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the main window is forbidden to move in split-screen mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> <!--RP4--><!--RP4End-->This API is supported since API version 9 and deprecated since API version 26.0.0. No substitute is provided.

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

### setForbidSplitMove<sup>(deprecated)</sup>

setForbidSplitMove(isForbidSplitMove: boolean): Promise&lt;void&gt;

Sets whether the main window is forbidden to move in split-screen mode. This API uses a promise to return the result.

> **NOTE**
>
> <!--RP4--><!--RP4End-->This API is supported since API version 9 and deprecated since API version 26.0.0. No substitute is provided.

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

### startMovingWithOptions

startMovingWithOptions(startMovingOptions?: StartMovingOptions): Promise&lt;void&gt;

Starts moving a window. This API uses a promise to return the result.

The window moves along with the cursor or touch point only when this API is called in the callback function of [onTouch](arkui-ts/ts-universal-events-touch.md#ontouch), where the event type is **TouchType.Down**.

In click-and-drag scenarios, if you do not want the drag to start as soon as you press down, you can call this API to start the moving effect when a [TouchType.Move](./arkui-ts/ts-appendix-enums.md#touchtype) event occurs (as long as **TouchType.Down** has already been triggered).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

**Device behavior differences**: On a device that supports [freeform windows](../../windowmanager/window-terminology.md#freeform-window) and in the freeform window state, this API takes effect for system windows, application main windows, application subwindows, global floating windows, and modal windows. On a device that supports freeform windows but is not in the freeform window state, or on a device that does not support freeform windows, this API takes effect only for system windows, application subwindows, global floating windows, and modal windows. If this API is called for an application main window, error code 801 or 1300004 is returned.

**Parameters**

| Name| Type | Mandatory| Description|
| ----- | ---------------------------- | -- | --------------------------------- |
| startMovingOptions  | [StartMovingOptions](#startmovingoptions) | No| Options for starting window movement.|

**Return value**

| Type                | Description                  |
| ------------------- | ---------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type, main windows are not supported in non-free window mode. |
| 1300016 | Parameter error. Possible cause: Invalid parameter range. |

**Example**

```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Red)
          .onTouch((event: TouchEvent) => {
            if (event.type == TouchType.Down) {
              let options: window.StartMovingOptions = {
                needFocused: true,
                avoidRect: {
                  left: 0,
                  top: 0,
                  width: 200,
                  height: 200
                }
              };
              try {
                windowClass.startMovingWithOptions(options)
                  .then(() => {
                    console.info('Succeeded in starting moving window.');
                  })
                  .catch((err: BusinessError) => {
                    console.error(`Failed to start moving. Cause code: ${err.code}, message: ${err.message}`);
                  });
              } catch (exception) {
                console.error(`Failed to start moving. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            }
          })
      }
      .width('100%')
    }
    .height('100%')
    .width('100%')
  }
}
```

## SubWindowOptions<sup>11+</sup>

Describes the parameters used for creating a child window.

| Name     | Type | Read-Only| Optional| Description        |
| ---------- | ---- | ---- | ---- | ----------- |
| isTopmost<sup>12+</sup>  | boolean | No| Yes| Whether the child window is topmost. **true** if topmost, **false** otherwise. The default value is **false**. This parameter must be used together with **isModal**. The setting of **isTopmost** takes effect only when **isModal** is set to **true**. If **isModal** is set to **false** and **isTopmost** is set to **true**, error code 401 is returned.<br>**System API**: This is a system API.<br>**System capability**: SystemCapability.Window.SessionManager|

## WindowStage<sup>9+</sup>

Implements a window manager, which manages each basic window unit, that is, [Window](arkts-apis-window-Window.md) instance.

Before calling any of the following APIs, you must use [onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate) to create a WindowStage instance.

### disableWindowDecor<sup>9+</sup>

disableWindowDecor(): void

Disables window decorators.

After the window decorators are disabled, when the main window enters the full-screen immersive state, hovering the cursor over the hot zone of the title bar at the top will display a floating title bar. To disable the floating title bar, call the [setTitleAndDockHoverShown()](arkts-apis-window-Window.md#settitleanddockhovershown14) API.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. <br>Applicable versions: 12+|
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

Sets whether to display the window on the lock screen.

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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

Sets the image displayed in the multitasking view. This API uses a promise to return the result.

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
    let imgResourceId = $r("app.media.startIcon").id;
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
| toWindow | [Window](arkts-apis-window-Window.md) | No  | No  | Target window to display the animation.|

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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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
| 202     | Permission verification failed. A non-system application calls a system API.<br>Applicable versions: 12+|
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

## StartMovingOptions

Defines the options for window movement.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Window.SessionManager

| Name    | Type     | Read-Only| Optional| Description              |
| -------- | -------- | ---- | ---- | ------------------ |
| needFocused | boolean  | No  | Yes  | Whether a window can be moved only when it is focused. The default value is **true**.<br>- **true**: A window can be moved only when it is focused.<br>- **false**: A window can be moved even when it is not focused.|
| avoidRect | [Rect](arkts-apis-window-i.md#rect7) | No| Yes| Avoid area when a window is moved. The upper left corner of the window is used as the origin, and it moves with the window. The system restricts the window position based on the minimum bounding rectangle area formed by the window area and the avoid area. If the minimum bounding rectangle area cannot be completely accommodated within the available area of the corresponding screen, the avoid area is considered invalid and avoidance correction is not performed. Otherwise, the system adjusts the window position based on the following rules:<br>- In single-screen movement scenarios, ensure that the avoid area is completely within the available area of the current screen.<br>- In cross-screen movement scenarios, ensure that the avoid area is completely within the available area of the current screen before the movement and that the window is displayed only on the current screen. After the movement, ensure that the avoid area is completely within the available area of the target screen and that the window is displayed only on the target screen. During the entire movement process, the window is displayed only on one screen and is not partially displayed on other screens.|

# Window

The `Window` module provides basic window management capabilities, such as creating and destroying the current window, setting properties for the current window, and managing and scheduling windows.

This module provides the following common window-related functions:

- [Window](#window): the current window instance, which is the basic unit managed by the window manager.
- [WindowStage](#windowstage9): window manager that manages windows.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import window from '@ohos.window';
```

## WindowType<sup>7+</sup>

Enumerates the window types.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name             | Value| Description              |
| ----------------- | ------ | ------------------ |
| TYPE_APP          | 0      | Application subwindow. This type can be used only in the FA model.|
| TYPE_SYSTEM_ALERT | 1      | System alert window.|
| TYPE_INPUT_METHOD<sup>9+</sup> | 2      | Input method window. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_STATUS_BAR<sup>9+</sup>   | 3      | Status bar. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_PANEL<sup>9+</sup>        | 4      | Notification panel. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_KEYGUARD<sup>9+</sup>     | 5      | Lock screen. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_VOLUME_OVERLAY<sup>9+</sup> | 6      | Volume bar. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_NAVIGATION_BAR<sup>9+</sup> | 7      | Navigation bar. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_FLOAT<sup>9+</sup> | 8      | Floating window. This type can be used only in the stage model.<br>**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW|
| TYPE_WALLPAPER<sup>9+</sup> | 9      | Wallpaper. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_DESKTOP<sup>9+</sup> | 10      | Home screen. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_LAUNCHER_RECENT<sup>9+</sup> | 11      | Recent tasks screen. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_LAUNCHER_DOCK<sup>9+</sup> | 12      | Dock bar on the home screen. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_VOICE_INTERACTION<sup>9+</sup> | 13      | Voice assistant. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|
| TYPE_POINTER<sup>9+</sup> | 14      | Mouse. This type can be used only in the stage model.<br>This is a system API and cannot be called by third-party applications.|

## AvoidAreaType<sup>7+</sup>

Enumerates the types of the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                              | Value | Description             |
|----------------------------------|-----| ----------------- |
| TYPE_SYSTEM                      | 0   | Default area of the system.|
| TYPE_CUTOUT                      | 1   | Notch. |
| TYPE_SYSTEM_GESTURE<sup>9+</sup> | 2   | Gesture area.   |
| TYPE_KEYBOARD<sup>9+</sup>       | 3   | Soft keyboard area. |

## WindowMode<sup>7+</sup>

Enumerates the window modes.

This is a system API and cannot be called by third-party applications.

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

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| WINDOW_LAYOUT_MODE_CASCADE  | 0    | Cascade mode.      |
| WINDOW_LAYOUT_MODE_TILE | 1    | Tile mode.            |

## SystemBarProperties

Describes the properties of the status bar and navigation bar.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                                  | Type| Readable| Writable| Description                                                        |
| -------------------------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   | Yes  | Yes  | Background color of the status bar. The value is a hexadecimal RGB or aRGB color value and is case insensitive, for example, `#00FF00` or `#FF00FF00`.|
| isStatusBarLightIcon<sup>7+</sup>      | boolean  | No  | Yes  | Whether any icon on the status bar is highlighted.                                  |
| statusBarContentColor<sup>8+</sup>     | string   | No  | Yes  | Color of the text on the status bar.                                            |
| navigationBarColor                     | string   | Yes  | Yes  | Background color of the navigation bar. The value is a hexadecimal RGB or aRGB color value and is case insensitive, for example, `#00FF00` or `#FF00FF00`.|
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  | No  | No  | Whether any icon on the navigation bar is highlighted.                                  |
| navigationBarContentColor<sup>8+</sup> | string   | No  | Yes  | Color of the text on the navigation bar.                                            |

## Orientation<sup>9+</sup>

Enumerates the window orientations.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                                 | Value  | Description                         |
| ------------------------------------- | ---- | ----------------------------- |
| UNSPECIFIED                           | 0    | Unspecified. The orientation is determined by the system.|
| PORTRAIT                              | 1    | Portrait.            |
| LANDSCAPE                             | 2    | Landscape.  |
| PORTRAIT_INVERTED                     | 3    | Reverse portrait.  |
| LANDSCAPE_INVERTED                    | 4    | Reverse landscape.|
| AUTO_ROTATION                         | 5    | Auto rotation.|
| AUTO_ROTATION_PORTRAIT                | 6    | Auto rotation in the vertical direction.|
| AUTO_ROTATION_LANDSCAPE               | 7    | Auto rotation in the horizontal direction.|
| AUTO_ROTATION_RESTRICTED              | 8    | Switched-determined auto rotation.|
| AUTO_ROTATION_PORTRAIT_RESTRICTED     | 9    | Switched-determined auto rotation in the vertical direction.|
| AUTO_ROTATION_LANDSCAPE_RESTRICTED    | 10   | Switched-determined auto rotation in the horizontal direction.|
| LOCKED                                | 11   | Locked.|

## SystemBarRegionTint<sup>8+</sup>

Describes the callback for a single system bar.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name           | Type                 | Readable| Writable| Description                                                        |
| --------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type            | [WindowType](#windowtype) | Yes  | Yes  | Type of the system bar whose properties are changed. Only the status bar and navigation bar are supported.|
| isEnable        | boolean                   | Yes  | Yes  | Whether the system bar is displayed.                                        |
| region          | [Rect](#rect)             | Yes  | Yes  | Current position and size of the system bar.                                    |
| backgroundColor | string                    | Yes  | Yes  | Background color of the system bar. The value is a hexadecimal RGB or aRGB color value and is case insensitive, for example, `#00FF00` or `#FF00FF00`.|
| contentColor    | string                    | Yes  | Yes  | Color of the text on the system bar.                                            |

## SystemBarTintState<sup>8+</sup>

Describes the callback for the current system bar.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Type                                           | Readable| Writable| Description                        |
| ---------- | --------------------------------------------------- | ---- | ---- | ---------------------------- |
| displayId  | number                                              | Yes  | No  | ID of the current physical screen.            |
| regionTint | Array<[SystemBarRegionTint](#systembarregiontint8)> | Yes  | Yes  | All system bar information that has been changed.|

## Rect<sup>7+</sup>

Describes the rectangular area of the window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Readable| Writable| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | Yes  | Yes  | Left boundary of the rectangle.|
| top    | number   | Yes  | Yes  | Top boundary of the rectangle.|
| width  | number   | Yes  | Yes  | Width of the rectangle.  |
| height | number   | Yes  | Yes  | Height of the rectangle.  |

## AvoidArea<sup>7+</sup>

Describes the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Type     | Readable| Writable| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| visible<sup>9+</sup>    | boolean       | Yes  | Yes  | Whether the area is visible.|
| leftRect   | [Rect](#rect) | Yes  | Yes  | Rectangle on the left of the screen.|
| topRect    | [Rect](#rect) | Yes  | Yes  | Rectangle at the top of the screen.|
| rightRect  | [Rect](#rect) | Yes  | Yes  | Rectangle on the right of the screen.|
| bottomRect | [Rect](#rect) | Yes  | Yes  | Rectangle at the bottom of the screen.|

## Size<sup>7+</sup>

Describes the window size.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Readable| Writable| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | Yes  | Yes  | Window width.|
| height | number   | Yes  | Yes  | Window height.|

## WindowProperties

Describes the window properties.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                           | Type                 | Readable| Writable| Description                                        |
| ------------------------------- | ------------------------- | ---- | ---- | -------------------------------------------- |
| windowRect<sup>7+</sup>         | [Rect](#rect)             | Yes  | Yes  | Window size.                                  |
| type<sup>7+</sup>               | [WindowType](#windowtype) | Yes  | Yes  | Window type.                                  |
| isFullScreen                    | boolean                   | Yes  | Yes  | Whether the window is displayed in full screen mode. The default value is `false`.                     |
| isLayoutFullScreen<sup>7+</sup> | boolean                   | Yes  | Yes  | Whether the window layout is in full-screen mode (whether the window is immersive). The default value is `false`.             |
| focusable<sup>7+</sup>          | boolean                   | Yes  | No  | Whether the window can gain focus. The default value is `true`.                |
| touchable<sup>7+</sup>          | boolean                   | Yes  | No  | Whether the window is touchable. The default value is `true`.                |
| brightness                      | number                    | Yes  | Yes  | Screen brightness. The value ranges from 0 to 1. The value `1` indicates the maximum brightness. |
| dimBehindValue<sup>(deprecated)</sup>     | number                    | Yes  | Yes  | Dimness of the window that is not on top. The value ranges from 0 to 1. The value `1` indicates the maximum dimness.<br>**NOTE**<br>This attribute is deprecated since API version 9.<br> |
| isKeepScreenOn                  | boolean                   | Yes  | Yes  | Whether the screen is always on. The default value is `false`.                 |
| isPrivacyMode<sup>7+</sup>      | boolean                   | Yes  | Yes  | Whether the window is in privacy mode. The default value is `false`.                     |
| isRoundCorner<sup>7+</sup>      | boolean                   | Yes  | Yes  | Whether the window has rounded corners. The default value is `false`.               |
| isTransparent<sup>7+</sup>      | boolean                   | Yes  | Yes  | Whether the window is transparent. The default value is `false`.                 |

## ColorSpace<sup>8+</sup>

Describes the color gamut mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Default Value | Description          |
| ---------- | ------ | -------------- |
| DEFAULT    | 0      | Default color gamut mode.|
| WIDE_GAMUT | 1      | Wide color gamut mode.  |

## window.create<sup>7+</sup>

create(id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow. This API uses an asynchronous callback to return the result.

This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | Yes  | Window ID.                            |
| type     | [WindowType](#windowtype)              | Yes  | Window type.                          |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the subwindow created.|

**Example**

```js
var windowClass = null;
 let promise = window.create("first", window.WindowType.TYPE_APP);
 promise.then((data)=> {
 	windowClass = data;
    console.info('SubWindow created. Data: ' + JSON.stringify(data));
 }).catch((err)=>{
    console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
 });
```

## window.create<sup>7+</sup>

create(id: string, type: WindowType): Promise&lt;Window&gt;

Creates a subwindow. This API uses a promise to return the result.

This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| id     | string                    | Yes  | Window ID.  |
| type   | [WindowType](#windowtype) | Yes  | Window type.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow created.|

**Example**

```js
var windowClass = null;
let promise = window.create("first", window.WindowType.TYPE_APP);
promise.then((data)=> {
    windowClass = data;
    console.info('SubWindow created. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
});
```

## window.create<sup>8+</sup>

create(ctx: Context, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow (in API version 8) or a system window (from API version 9). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | Context                                | Yes  | Current application context.<br>For the definition of `Context` of API version 8, see [Context](js-apis-Context.md).<br>For the definition of `Context` of API version 9, see [ServiceExtensionContext](js-apis-service-extension-context.md).|
| id       | string                                 | Yes  | Window ID.                                                    |
| type     | [WindowType](#windowtype)              | Yes  | Window type.                                                  |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the window created.                        |

**Example**

```js
var windowClass = null;
 window.create(this.context, "alertWindow", window.WindowType.TYPE_SYSTEM_ALERT, (err, data) => {
    if (err.code) {
        console.error('Failed to create the Window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Window created. Data: ' + JSON.stringify(data));
    windowClass.resetSize(500, 1000);
});
```

## window.create<sup>8+</sup>

create(ctx: Context, id: string, type: WindowType): Promise&lt;Window&gt;

Creates a subwindow (in API version 8) or a system window (from API version 9). This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| ctx    | Context                   | Yes  | Current application context.<br>For the definition of `Context` of API version 8, see [Context](js-apis-Context.md).<br>For the definition of `Context` of API version 9, see [ServiceExtensionContext](js-apis-service-extension-context.md).|
| id     | string                    | Yes  | Window ID.                                                    |
| type   | [WindowType](#windowtype) | Yes  | Window type.                                                  |

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the window created. |

**Example**

```js
var windowClass = null;
let promise = window.create(this.context, "alertWindow", window.WindowType.TYPE_SYSTEM_ALERT);
promise.then((data)=> {
 	windowClass = data;
    console.info('Window created. Data:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to create the Window. Cause:' + JSON.stringify(err));
});
```

## window.find<sup>7+</sup>

find(id: string, callback: AsyncCallback&lt;Window&gt;): void

Finds a window based on the ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | Yes  | Window ID.                            |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the window found.|

**Example**

```js
var windowClass = null;
 window.find("alertWindow", (err, data) => {
   if (err.code) {
       console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
       return;
   }
   windowClass = data;
   console.info('window found. Data: ' + JSON.stringify(data));
});
```

## window.find<sup>7+</sup>

find(id: string): Promise&lt;Window&gt;

Finds a window based on the ID. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| id     | string | Yes  | Window ID.|

**Return value**

| Type                            | Description                                 |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the window found.|

**Example**

```js
var windowClass = null;
let promise = window.find("alertWindow");
promise.then((data)=> {
 	windowClass = data;
    console.info('window found. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
});
```

## window.getTopWindow

getTopWindow(callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result.

This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                        |
| -------- | -------------------------------------- | ---- | -------------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the top window obtained.|

**Example**

```js
var windowClass = null;
window.getTopWindow((err, data) => {
    if (err.code) {
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
});
```

## window.getTopWindow

getTopWindow(): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result.

This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                            | Description                                           |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the top window obtained.|

**Example**

```js
var windowClass = null;
let promise = window.getTopWindow();
promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
})
```

## window.getTopWindow<sup>8+</sup>

getTopWindow(ctx: Context, callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | Context                                | Yes  | Current application context.<br>For the definition of `Context` of API version 8, see [Context](js-apis-Context.md).<br>For the definition of `Context` of API version 9, see [AbilityContext](js-apis-ability-context.md).|
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the top window obtained.                |

**Example**

```js
var windowClass = null;
window.getTopWindow(this.context, (err, data) => {
    if (err.code) {
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
});
```

## window.getTopWindow<sup>8+</sup>

getTopWindow(ctx: Context): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| ctx    | Context | Yes  | Current application context.<br>For the definition of `Context` of API version 8, see [Context](js-apis-Context.md).<br>For the definition of `Context` of API version 9, see [AbilityContext](js-apis-ability-context.md).|

**Return value**

| Type                            | Description                                           |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the top window obtained.|

**Example**

```js
var windowClass = null;
let promise = window.getTopWindow(this.context);
promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
})
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

Minimizes all windows on a display. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | Yes  | ID of the [display](js-apis-display.md#display). |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Example**

```js
import display from '@ohos.display'
import window from '@ohos.window'

var displayClass = null;
display.getDefaultDisplay((err, data) => {
    if(err.code) {
        return;
    }
    displayClass = data;
    window.minimizeAll(displayClass.id, (err, data) => {
        if(err.code) {
            console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in minimizing all windows.');
    });
});
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number): Promise&lt;void&gt;

Minimizes all windows on a display. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | Yes  | ID of the [display](js-apis-display.md#display).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
import display from '@ohos.display'
import window from '@ohos.window'

var displayClass = null;
display.getDefaultDisplay((err, data) => {
    if(err.code) {
        return;
    }
    displayClass = data;
    let promise = window.minimizeAll(displayClass.id);
    promise.then((data)=> {
        console.info('Succeeded in minimizing all windows.');
    }).catch((err)=>{
        console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));
    })
});
```

## window.toggleShownStateForAllAppWindows<sup>9+</sup>
toggleShownStateForAllAppWindows(callback: AsyncCallback&lt;void&gt;): void

Hides or restores the application's windows during quick multi-window switching. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Example**

```js
window.toggleShownStateForAllAppWindows((err, data) => {
    if (err.code) {
        console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in toggling shown state for all app windows.');
})
```

## window.toggleShownStateForAllAppWindows<sup>9+</sup>
toggleShownStateForAllAppWindows(): Promise&lt;void&gt;

Hides or restores the application's windows during quick multi-window switching. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = window.toggleShownStateForAllAppWindows();
promise.then((data)=> {
    console.info('Succeeded in toggling shown state for all app windows. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));
})
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode, callback: AsyncCallback&lt;void&gt;): void

Sets the window layout mode. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                  | Yes  | Window layout mode to set.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Example**

```js
window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE, (data) => {
    console.info('Succeeded in setting window layout mode. Data: ' + JSON.stringify(data));
});
```

## window.setWindowLayoutMode<sup>9+</sup>
setWindowLayoutMode(mode: WindowLayoutMode): Promise&lt;void&gt;

Sets the window layout mode. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmode9)                    | Yes  | Window layout mode to set.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE);
promise.then((data)=> {
    console.info('Succeeded in setting window layout mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(err));
})
```

## on('systemBarTintChange')<sup>8+</sup>

on(type: 'systemBarTintChange', callback: Callback&lt;SystemBarTintState&gt;): void

Enables listening for properties changes of the status bar and navigation bar.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Event type. The value is fixed at `systemBarTintChange`, indicating the property change event of the status bar and navigation bar.|
| callback | Callback&lt;[SystemBarTintState](#systembartintstate)&gt; | Yes  | Callback used to return the properties of the status bar and navigation bar.                |

**Example**

```js
window.on('systemBarTintChange', (data) => {
    console.info('Succeeded in enabling the listener for systemBarTint changes. Data: ' + JSON.stringify(data));
});
```

## off('systemBarTintChange')<sup>8+</sup>

off(type: 'systemBarTintChange', callback?: Callback&lt;SystemBarTintState &gt;): void

Disables listening for properties changes of the status bar and navigation bar.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                    | Yes  | Event type. The value is fixed at `systemBarTintChange`, indicating the property change event of the status bar and navigation bar.|
| callback | Callback&lt;[SystemBarTintState](#systembartintstate)&gt; | No  | Callback used to return the properties of the status bar and navigation bar.                |

**Example**

```js
window.off('systemBarTintChange');
```

## Window

Represents the current window instance, which is the basic unit managed by the window manager.

In the following API examples, you must use [getTopWindow()](#windowgettopwindow), [create()](#windowcreate7), or [find()](#windowfind7) to obtain a `Window` instance and then call a method in this instance.

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

Hides this window. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
windowClass.hide((err, data) => {
    if (err.code) {
        console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('window hidden. data: ' + JSON.stringify(data));
})
```

### hide<sup>7+</sup>

hide(): Promise&lt;void&gt;

Hides this window. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.hide();
promise.then((data)=> {
    console.info('window hidden. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
})
```

### show<sup>7+</sup>

show(callback: AsyncCallback&lt;void&gt;): void

Shows this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
windowClass.show((err, data) => {
    if (err.code) {
        console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window. Data: ' + JSON.stringify(data));
})
```

### show<sup>7+</sup>

show(): Promise&lt;void&gt;

Shows this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.show();
promise.then((data)=> {
    console.info('Succeeded in showing the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
})
```

### destroy<sup>7+</sup>

destroy(callback: AsyncCallback&lt;void&gt;): void

Destroys this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
windowClass.destroy((err, data) => {
    if (err.code) {
        console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data));
})
```

### destroy<sup>7+</sup>

destroy(): Promise&lt;void&gt;

Destroys this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.destroy();
promise.then((data)=> {
    console.info('Succeeded in destroying the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
})
```

### moveTo<sup>7+</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

Moves this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                             |
| -------- | ------------------------- | ---- | ------------------------------------------------- |
| x        | number                    | Yes  | Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right.|
| y        | number                    | Yes  | Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                       |

**Example**

```js
windowClass.moveTo(300, 300, (err, data)=>{
    if (err.code) {
        console.error('Failed to move the window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Window moved. Data: ' + JSON.stringify(data));

});
```

### moveTo<sup>7+</sup>

moveTo(x: number, y: number): Promise&lt;void&gt;

Moves this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                             |
| ------ | ------ | ---- | ------------------------------------------------- |
| x      | number | Yes  | Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right.|
| y      | number | Yes  | Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.moveTo(300, 300);
promise.then((data)=> {
    console.info('Window moved. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to move the window. Cause: ' + JSON.stringify(err));
})
```

### resetSize<sup>7+</sup>

resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

Changes the size of this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                      |
| -------- | ------------------------- | ---- | -------------------------- |
| width    | number                    | Yes  | New width of the window, in px.|
| height   | number                    | Yes  | New height of the window, in px.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                |

**Example**

```js
windowClass.resetSize(500, 1000, (err, data) => {
    if (err.code) {
        console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Window size changed. Data: ' + JSON.stringify(data));
});
```

### resetSize<sup>7+</sup>

resetSize(width: number, height: number): Promise&lt;void&gt;

Changes the size of this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| width  | number | Yes  | New width of the window, in px.|
| height | number | Yes  | New height of the window, in px.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.resetSize(500, 1000);
promise.then((data)=> {
    console.info('Window size changed. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));
});
```

### setWindowType<sup>7+</sup>

setWindowType(type: WindowType, callback: AsyncCallback&lt;void&gt;): void

Sets the type of this window. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| type     | [WindowType](#windowtype) | Yes  | Window type.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

```js
var type = window.WindowType.TYPE_APP;
windowClass.setWindowType(type, (err, data) => {
  if (err.code) {
      console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
      return;
  }
  console.info('Succeeded in setting the window type. Data: ' + JSON.stringify(data));
});
```

### setWindowType<sup>7+</sup>

setWindowType(type: WindowType): Promise&lt;void&gt;

Sets the type of this window. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| type   | [WindowType](#windowtype) | Yes  | Window type.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var type = window.WindowType.TYPE_APP;
let promise = windowClass.setWindowType(type);
promise.then((data)=> {
    console.info('Succeeded in setting the window type. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
});
```

### getProperties

getProperties(callback: AsyncCallback&lt;WindowProperties&gt;): void

Obtains the properties of this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                      | Mandatory| Description                        |
| -------- | ---------------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;[WindowProperties](#windowproperties)&gt; | Yes  | Callback used to return the window properties.|

**Example**

```js
windowClass.getProperties((err, data) => {
    if (err.code) {
        console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
});
```

### getProperties

getProperties(): Promise&lt;WindowProperties&gt;

Obtains the properties of this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                                | Description                           |
| ---------------------------------------------------- | ------------------------------- |
| Promise&lt;[WindowProperties](#windowproperties)&gt; | Promise used to return the window properties.|

**Example**

```js
let promise = windowClass.getProperties();
promise.then((data)=> {
    console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
});
```

### getAvoidArea<sup>7+</sup>

getAvoidArea(type: [AvoidAreaType](#avoidareatype7), callback: AsyncCallback&lt;[AvoidArea](#avoidarea7)&gt;): void

Obtains the area where this window cannot be displayed, for example, the system bar area and notch. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- |-----------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | [AvoidAreaType](#avoidareatype7)              | Yes  | Type of the area. `TYPE_SYSTEM` indicates the default area of the system. `TYPE_CUTOUT` indicates the notch. **TYPE_SYSTEM_GESTURE** indicates the gesture area. **TYPE_KEYBOARD** indicates the soft keyboard area.|
| callback | AsyncCallback&lt;[AvoidArea](#avoidarea7)&gt; | Yes  | Callback used to return the area.                            |

**Example**

```js
var type = window.AvoidAreaType.TYPE_SYSTEM;
windowClass.getAvoidArea(type, (err, data) => {
    if (err.code) {
        console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
});
```

### getAvoidArea<sup>7+</sup>

getAvoidArea(type: [AvoidAreaType](#avoidareatype7)): Promise&lt;[AvoidArea](#avoidarea7)&gt;

Obtains the area where this window cannot be displayed, for example, the system bar area and notch. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                              | Mandatory| Description                                                        |
| ------ |----------------------------------| ---- | ------------------------------------------------------------ |
| type   | [AvoidAreaType](#avoidareatype7) | Yes  | Type of the area. `TYPE_SYSTEM` indicates the default area of the system. `TYPE_CUTOUT` indicates the notch. **TYPE_SYSTEM_GESTURE** indicates the gesture area. **TYPE_KEYBOARD** indicates the soft keyboard area.|

**Return value**

| Type                                     | Description                               |
|-----------------------------------------| ----------------------------------- |
| Promise&lt;[AvoidArea](#avoidarea7)&gt; | Promise used to return the area.|

**Example**

```js
let promise = windowClass.getAvoidArea();
promise.then((data)=> {
    console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
});
```

### setFullScreen

setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the full-screen mode for this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                     | Mandatory| Description                                          |
| ------------ | ------------------------- | ---- | ---------------------------------------------- |
| isFullScreen | boolean                   | Yes  | Whether to enable the full-screen mode, in which the status bar and navigation bar are hidden.|
| callback     | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                    |

**Example**

```js
var isFullScreen = true;
windowClass.setFullScreen(isFullScreen, (err, data) => {
    if (err.code) {
        console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
});
```

### setFullScreen

setFullScreen(isFullScreen: boolean): Promise&lt;void&gt;

Sets whether to enable the full-screen mode for this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type   | Mandatory| Description                                          |
| ------------ | ------- | ---- | ---------------------------------------------- |
| isFullScreen | boolean | Yes  | Whether to enable the full-screen mode, in which the status bar and navigation bar are hidden.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var isFullScreen = true;
let promise = windowClass.setFullScreen(isFullScreen);
promise.then((data)=> {
    console.info('Succeeded in enabling the full-screen mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
});
```

### setLayoutFullScreen<sup>7+</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the full-screen mode for the window layout. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name            | Type                     | Mandatory| Description                                                        |
| ------------------ | ------------------------- | ---- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | Yes  | Whether to enable the full-screen mode for the window layout, in which the status bar and navigation bar are displayed.|
| callback           | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```js
var isLayoutFullScreen= true;
windowClass.setLayoutFullScreen(isLayoutFullScreen, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window layout to full-screen mode. Data: ' + JSON.stringify(data));
});
```

### setLayoutFullScreen<sup>7+</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

Sets whether to enable the full-screen mode for the window layout. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name            | Type   | Mandatory| Description                                                        |
| ------------------ | ------- | ---- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean | Yes  | Whether to enable the full-screen mode for the window layout, in which the status bar and navigation bar are displayed.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var isLayoutFullScreen = true;
let promise = windowClass.setLayoutFullScreen(isLayoutFullScreen);
promise.then((data)=> {
    console.info('Succeeded in setting the window layout to full-screen mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
});
```

### setSystemBarEnable<sup>7+</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

Sets whether to display the status bar and navigation bar in this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| names    | Array                     | Yes  | Whether to display the status bar and navigation bar.<br>For example, to display the status bar and navigation bar, set this parameter to `["status", "navigation"]`. By default, they are not displayed.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```js
var names = ["status", "navigation"];
windowClass.setSystemBarEnable(names, (err, data) => {
    if (err.code) {
        console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the system bar to be visible. Data: ' + JSON.stringify(data));
});
```

### setSystemBarEnable<sup>7+</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

Sets whether to display the status bar and navigation bar in this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type | Mandatory| Description                                                        |
| ------ | ----- | ---- | ------------------------------------------------------------ |
| names  | Array | Yes  | Whether to display the status bar and navigation bar.<br>For example, to display the status bar and navigation bar, set this parameter to `["status", "navigation"]`. By default, they are not displayed.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var names = ["status", "navigation"];
let promise = windowClass.setSystemBarEnable(names);
promise.then((data)=> {
    console.info('Succeeded in setting the system bar to be visible. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the system bar to be visible. Cause:' + JSON.stringify(err));
});
```

### setSystemBarProperties

setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

Sets the properties of the status bar and navigation bar in this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| SystemBarProperties | [SystemBarProperties](#systembarproperties) | Yes  | Properties of the status bar and navigation bar.|
| callback            | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result.            |

**Example**

```js
var SystemBarProperties={
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    // The following properties are supported since API version 7.
    isStatusBarLightIcon: true,
    isNavigationBarLightIcon:false,
    // The following properties are supported since API version 8.
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
windowClass.setSystemBarProperties(SystemBarProperties, (err, data) => {
    if (err.code) {
        console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the system bar properties. Data: ' + JSON.stringify(data));
});
```

### setSystemBarProperties

setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

Sets the properties of the status bar and navigation bar in this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| SystemBarProperties | [SystemBarProperties](#systembarproperties) | Yes  | Properties of the status bar and navigation bar.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var SystemBarProperties={
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    // The following properties are supported since API version 7.
    isStatusBarLightIcon: true,
    isNavigationBarLightIcon:false,
    // The following properties are supported since API version 8.
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
let promise = windowClass.setSystemBarProperties(SystemBarProperties);
promise.then((data)=> {
    console.info('Succeeded in setting the system bar properties. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
});
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

Sets the preferred orientation for this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| Orientation         | [Orientation](#orientation9)                | Yes  | Orientation to set.        |
| callback            | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result.            |

**Example**

```js
var orientation = window.Orientation.AUTO_ROTATION;
windowClass.setPreferredOrientation(orientation, (err, data) => {
    if (err.code) {
        console.error('Failed to set window orientation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting window orientation. Data: ' + JSON.stringify(data));
});
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation): Promise&lt;void&gt;

Sets the preferred orientation for this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| Orientation         | [Orientation](#orientation9)                | Yes  | Orientation to set.      |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var orientation = window.Orientation.AUTO_ROTATION;
let promise = windowClass.setPreferredOrientation(orientation);
promise.then((data)=> {
    console.info('Succeeded in setting the window orientation. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window orientation. Cause: ' + JSON.stringify(err));
});
```

### loadContent<sup>7+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page to this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| path     | string                    | Yes  | Path of the page from which the content will be loaded.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Example**

```js
windowClass.loadContent("pages/page2/page2", (err, data) => {
   if (err.code) {
         console.error('Failed to load the content. Cause:' + JSON.stringify(err));
         return;
   }
  console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
});
```

### loadContent<sup>7+</sup>

loadContent(path: string): Promise&lt;void&gt;

Loads content from a page to this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| path   | string | Yes  | Path of the page from which the content will be loaded.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.loadContent("pages/page2/page2");
promise.then((data)=> {
    console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
});
```
### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page associated with a local storage to this window. This API uses an asynchronous callback to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | Yes  | Path of the page from which the content will be loaded.                                        |
| storage  | LocalStorage | Yes  | A storage unit, which provides storage for variable state properties and non-variable state properties of an application.|
| callback | AsyncCallback&lt;void&gt;                       | Yes  | Callback used to return the result.                                                  |

**Example**

```ts
class myAbility extends Ability {
    storage : LocalStorage  
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate("storageSimpleProp",121);
        console.log('onWindowStageCreate');
        windowStage.loadContent("pages/page2",this.storage,(err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage): Promise&lt;void&gt;

Loads content from a page associated with a local storage to this window. This API uses a promise to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                                           | Mandatory| Description                                                        |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | Yes  | Path of the page from which the content will be loaded.                                        |
| storage | LocalStorage | Yes  | A storage unit, which provides storage for variable state properties and non-variable state properties of an application.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
class myAbility extends Ability {
    storage : LocalStorage 
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate("storageSimpleProp",121);
        console.log('onWindowStageCreate');
        var windowClass = null;
        let promise = windowStage.loadContent("pages/page2",this.storage);
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        })
    }
}
```
### isShowing<sup>7+</sup>

isShowing(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this window is displayed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value `true` means that this window is displayed, and `false` means the opposite.|

**Example**

```js
windowClass.isShowing((err, data) => {
    if (err.code) {
        console.error('Failed to check whether the window is showing. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
});
```

### isShowing<sup>7+</sup>

isShowing(): Promise&lt;boolean&gt;

Checks whether this window is displayed. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value `true` means that this window is displayed, and `false` means the opposite.|

**Example**

```js
let promise = windowClass.isShowing();
promise.then((data)=> {
    console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(err));
});
```

### on('windowSizeChange')<sup>7+</sup>

on(type:  'windowSizeChange', callback: Callback&lt;Size&gt;): void

Enables listening for window size changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at `windowSizeChange`, indicating the window size change event.|
| callback | Callback&lt;[Size](#size7)&gt; | Yes  | Callback used to return the window size.                          |

**Example**

```js
windowClass.on('windowSizeChange', (data) => {
    console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
});
```

### off('windowSizeChange')<sup>7+</sup>

off(type: 'windowSizeChange', callback?: Callback&lt;Size &gt;): void

Disables listening for window size changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                         | Mandatory| Description                                                    |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | Yes  | Event type. The value is fixed at `windowSizeChange`, indicating the window size change event.|
| callback | Callback&lt;[Size](#size)&gt; | No  | Callback used to return the window size.                          |

**Example**

```js
windowClass.off('windowSizeChange');
```

### on('systemAvoidAreaChange')<sup>(deprecated)</sup>

on(type: 'systemAvoidAreaChange', callback: Callback&lt;[AvoidArea](#avoidarea7)&gt;): void

Enables listening for changes to the area where the window cannot be displayed.
> **NOTE**
>
>   This API is deprecated since API version 9. Use [on('avoidAreaChange')](#onavoidareachange9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The value is fixed at `systemAvoidAreaChange`, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;[AvoidArea](#avoidarea7)&gt; | Yes  | Callback used to return the area.                            |

**Example**

```js
windowClass.on('systemAvoidAreaChange', (data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. Data: ' + JSON.stringify(data));
});
```

### off('systemAvoidAreaChange')<sup>(deprecated)</sup>

off(type: 'systemAvoidAreaChange', callback?: Callback&lt;[AvoidArea](#avoidarea7)&gt;): void

Disables listening for changes to the area where the window cannot be displayed.
> **NOTE**
>
>  This API is deprecated since API version 9. Use [off('avoidAreaChange')](#offavoidareachange9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                   |
| -------- |------------------------------------------| ---- | ------------------------------------------------------- |
| type     | string                                   | Yes  | Event type. The value is fixed at `systemAvoidAreaChange`, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;[AvoidArea](#avoidarea7)&gt; | No  | Callback used to return the area.                           |

**Example**

```js
windowClass.off('systemAvoidAreaChange');
```


### on('avoidAreaChange')<sup>9+</sup>

on(type: 'avoidAreaChange', callback: Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt;): void

Enables listening for changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                              | Mandatory| Description                                  |
| -------- |------------------------------------------------------------------| ---- |--------------------------------------|
| type     | string                                                           | Yes  | Event type. The value is fixed at `avoidAreaChange`, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt; | Yes  | Callback used to return the area and area type.|

**Example**

```js
windowClass.on('avoidAreaChange', (type, data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. type:'  + JSON.stringify(type) + 'Data: ' + JSON.stringify(data));
});
```

### off('avoidAreaChange')<sup>9+</sup>

off(type: 'avoidAreaChange', callback: Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt;): void

Disables listening for changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                                         | Mandatory | Description                                |
| -------- |-----------------------------------------------------------------------------|-----|------------------------------------|
| type     | string                                                                      | Yes  | Event type. The value is fixed at `avoidAreaChange`, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt; | No  | Callback used to return the area and area type.|

**Example**

```js
windowClass.off('avoidAreaChange');
```

### on('keyboardHeightChange')<sup>7+</sup>

on(type: 'keyboardHeightChange', callback: Callback&lt;number&gt;): void

Enables listening for keyboard height changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type               | Mandatory| Description                                                        |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at `keyboardHeightChange`, indicating the keyboard height change event.|
| callback | Callback<number&gt; | Yes  | Callback used to return the current keyboard height.                              |

**Example**

```js
windowClass.on('keyboardHeightChange', (data) => {
    console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));
});
```

### off('keyboardHeightChange')<sup>7+</sup>

off(type: 'keyboardHeightChange', callback?: Callback&lt;number&gt;): void

Disables listening for keyboard height changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at `keyboardHeightChange`, indicating the keyboard height change event.|
| callback | Callback&lt;number&gt; | No  | Callback used to return the current keyboard height.                              |

**Example**

```js
windowClass.off('keyboardHeightChange');
```

### on('touchOutside')<sup>9+</sup>

on(type: 'touchOutside', callback: Callback&lt;void&gt;): void

Enables listening for click events outside this window.
This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type               | Mandatory| Description                                                        |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at `touchOutside`, indicating the click event outside this window.|
| callback | Callback<void&gt; | Yes  | Callback used to Callback used to return the click event outside this window.                              |

**Example**

```js
windowClass.on('touchOutside', () => {
    console.info('touch outside');
});
```

### off('touchOutside')<sup>9+</sup>

off(type: 'touchOutside', callback?: Callback&lt;void&gt;): void

Disables listening for click events outside this window.
This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at `touchOutside`, indicating the click event outside this window.|
| callback | Callback&lt;number&gt; | No  | Callback used to Callback used to return the click event outside this window.                              |

**Example**

```js
windowClass.off('touchOutside');
```

### isSupportWideGamut<sup>8+</sup>

isSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this window supports the wide color gamut mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value `true` means that the wide color gamut mode is supported, and `false` means the opposite.|

**Example**

```js
windowClass.isSupportWideGamut((err, data) => {
    if (err.code) {
        console.error('Failed to check whether the window support WideGamut. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));
})
```

### isSupportWideGamut<sup>8+</sup>

isSupportWideGamut(): Promise&lt;boolean&gt;

Checks whether this window supports the wide color gamut mode. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value `true` means that the wide color gamut mode is supported, and `false` means the opposite.|

**Example**

```js
let promise = windowClass.isSupportWideGamut();
promise.then((data)=> {
    console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to check whether the window support WideGamut. Cause: ' + JSON.stringify(err));
});
```

### setColorSpace<sup>8+</sup>

setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

Sets this window to the wide or default color gamut mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type                     | Mandatory| Description        |
| ---------- | ------------------------- | ---- | ------------ |
| colorSpace | [ColorSpace](#colorspace) | Yes  | Color gamut mode.|
| callback   | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.  |

**Example**

```js
windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT, (err, data) => {
    if (err.code) {
        console.error('Failed to set window colorspace. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting window colorspace. Data: ' + JSON.stringify(data));
})
```

### setColorSpace<sup>8+</sup>

setColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

Sets this window to the wide or default color gamut mode. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type                     | Mandatory| Description          |
| ---------- | ------------------------- | ---- | -------------- |
| colorSpace | [ColorSpace](#colorspace) | Yes  | Color gamut mode.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT);
promise.then((data)=> {
    console.info('Succeeded in setting window colorspace. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set window colorspace. Cause: ' + JSON.stringify(err));
});
```

### getColorSpace<sup>8+</sup>

getColorSpace(callback: AsyncCallback&lt;ColorSpace&gt;): void

Obtains the color gamut mode of this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                          | Mandatory| Description                                                      |
| -------- | ---------------------------------------------- | ---- | ---------------------------------------------------------- |
| callback | AsyncCallback&lt;[ColorSpace](#colorspace)&gt; | Yes  | Callback used to return the result. When the color gamut mode is obtained successfully, `err` is `undefined`, and `data` is the current color gamut mode.|

**Example**

```js
windowClass.getColorSpace((err, data) => {
    if (err.code) {
        console.error('Failed to get window colorspace. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in getting window colorspace. Cause:' + JSON.stringify(data));
})
```

### getColorSpace<sup>8+</sup>

getColorSpace(): Promise&lt;ColorSpace&gt;

Obtains the color gamut mode of this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                    | Description                           |
| ---------------------------------------- | ------------------------------- |
| Promise&lt;[ColorSpace](#colorspace)&gt; | Promise used to return the current color gamut mode.|

**Example**

```js
let promise = windowClass.getColorSpace();
promise.then((data)=> {
    console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to get window colorspace. Cause: ' + JSON.stringify(err));
});
```

### setBackgroundColor

setBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void

Sets the background color for this window. This API uses an asynchronous callback to return the result. In the stage model, this API must be used after [loadContent](#loadcontent9).

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| color    | string                    | Yes  | Background color to set. The value is a hexadecimal color value and is case insensitive, for example, `#00FF00` or `#FF00FF00`.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                  |

**Example**

```js
var color = '#00ff33';
windowClass.setBackgroundColor(color, (err, data) => {
    if (err.code) {
        console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the background color. Data: ' + JSON.stringify(data));
});
```

### setBackgroundColor

setBackgroundColor(color: string): Promise&lt;void&gt;

Sets the background color for this window. This API uses a promise to return the result. In the stage model, this API must be used after [loadContent](#loadcontent9).

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| color  | string | Yes  | Background color to set. The value is a hexadecimal color value and is case insensitive, for example, `#00FF00` or `#FF00FF00`.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var color = '#00ff33';
let promise = windowClass.setBackgroundColor(color);
promise.then((data)=> {
    console.info('Succeeded in setting the background color. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
});
```

### setBrightness

setBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

Sets the screen brightness for this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type                     | Mandatory| Description                                |
| ---------- | ------------------------- | ---- | ------------------------------------ |
| brightness | number                    | Yes  | Brightness to set, which ranges from 0 to 1. The value `1` indicates the brightest.|
| callback   | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                          |

**Example**

```js
var brightness = 1;
windowClass.setBrightness(brightness, (err, data) => {
    if (err.code) {
        console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the brightness. Data: ' + JSON.stringify(data));
});
```

### setBrightness

setBrightness(brightness: number): Promise&lt;void&gt;

Sets the screen brightness for this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type  | Mandatory| Description                                |
| ---------- | ------ | ---- | ------------------------------------ |
| brightness | number | Yes  | Brightness to set, which ranges from 0 to 1. The value `1` indicates the brightest.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var brightness = 1;
let promise = windowClass.setBrightness(brightness);
promise.then((data)=> {
    console.info('Succeeded in setting the brightness. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
});
```

### setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number, callback: AsyncCallback&lt;void&gt;): void

Sets the dimness of the window that is not on top. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
>  This API is deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type                     | Mandatory| Description                                              |
| -------------- | ------------------------- | ---- | -------------------------------------------------- |
| dimBehindValue | number                    | Yes  | Dimness of the window to set. The value ranges from 0 to 1. The value `1` indicates the dimmest.|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                        |

**Example**

```js
windowClass.setDimBehind(0.5, (err, data) => {
    if (err.code) {
        console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the dimness. Data:' + JSON.stringify(data));
});
```

### setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number): Promise&lt;void&gt;

Sets the dimness of the window that is not on top. This API uses a promise to return the result.

> **NOTE**
> 
>  This API is deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type  | Mandatory| Description                                              |
| -------------- | ------ | ---- | -------------------------------------------------- |
| dimBehindValue | number | Yes  | Dimness of the window to set. The value ranges from 0 to 1. The value `1` indicates the dimmest.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.setDimBehind(0.5);
promise.then((data)=> {
    console.info('Succeeded in setting the dimness. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
});
```

### setFocusable<sup>7+</sup>

setFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window can gain focus. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                     | Mandatory| Description                        |
| ----------- | ------------------------- | ---- | ---------------------------- |
| isFocusable | boolean                   | Yes  | Whether the window can gain focus.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                  |

**Example**

```js
var isFocusable= true;
windowClass.setFocusable(isFocusable, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to be focusable. Data: ' + JSON.stringify(data));
});
```

### setFocusable<sup>7+</sup>

setFocusable(isFocusable: boolean): Promise&lt;void&gt;

Sets whether this window can gain focus. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type   | Mandatory| Description                        |
| ----------- | ------- | ---- | ---------------------------- |
| isFocusable | boolean | Yes  | Whether the window can gain focus.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var isFocusable= true;
let promise = windowClass.setFocusable(isFocusable);
promise.then((data)=> {
    console.info('Succeeded in setting the window to be focusable. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window to be focusable. Cause: ' + JSON.stringify(err));
});
```

### setKeepScreenOn

setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to keep the screen always on. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type                     | Mandatory| Description                    |
| -------------- | ------------------------- | ---- | ------------------------ |
| isKeepScreenOn | boolean                   | Yes  | Whether to keep the screen always on.|
| callback       | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.              |

**Example**

```js
var isKeepScreenOn = true;
windowClass.setKeepScreenOn(isKeepScreenOn, (err, data) => {
    if (err.code) {
        console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the screen to be always on. Data: ' + JSON.stringify(data));
});
```

### setKeepScreenOn

setKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

Sets whether to keep the screen always on. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type   | Mandatory| Description                    |
| -------------- | ------- | ---- | ------------------------ |
| isKeepScreenOn | boolean | Yes  | Whether to keep the screen always on.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var isKeepScreenOn = true;
let promise = windowClass.setKeepScreenOn(isKeepScreenOn);
promise.then((data) => {
    console.info('Succeeded in setting the screen to be always on. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.info('Failed to set the screen to be always on. Cause:  ' + JSON.stringify(err)); 
});
```

### setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the area outside the subwindow is touchable. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
>  This API is deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type                     | Mandatory| Description            |
| --------- | ------------------------- | ---- | ---------------- |
| touchable | boolean                   | Yes  | Whether the area outside the subwindow is touchable. The value `true` means that such an area is touchable, and `false` means the opposite.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.      |

**Example**

```js
windowClass.setOutsideTouchable(true, (err, data) => {
    if (err.code) {
        console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the area to be touchable. Data: ' + JSON.stringify(data));
})
```

### setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean): Promise&lt;void&gt;

Sets whether the area outside the subwindow is touchable. This API uses a promise to return the result.

> **NOTE**
> 
>  This API is deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type   | Mandatory| Description            |
| --------- | ------- | ---- | ---------------- |
| touchable | boolean | Yes  | Whether the area outside the subwindow is touchable. The value `true` means that such an area is touchable, and `false` means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = windowClass.setOutsideTouchable(true);
promise.then((data)=> {
    console.info('Succeeded in setting the area to be touchable. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
});
```

### setPrivacyMode<sup>7+</sup>

setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is in privacy mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type                     | Mandatory| Description                |
| ------------- | ------------------------- | ---- | -------------------- |
| isPrivacyMode | boolean                   | Yes  | Whether the window is in privacy mode.|
| callback      | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Example**

```js
var isPrivacyMode = true;
windowClass.setPrivacyMode(isPrivacyMode, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to privacy mode. Data:' + JSON.stringify(data));

});
```

### setPrivacyMode<sup>7+</sup>

setPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

Sets whether this window is in privacy mode. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type   | Mandatory| Description                |
| ------------- | ------- | ---- | -------------------- |
| isPrivacyMode | boolean | Yes  | Whether the window is in privacy mode.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var isPrivacyMode = true;
let promise = windowClass.setPrivacyMode(isPrivacyMode);
promise.then((data)=> {
    console.info('Succeeded in setting the window to privacy mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window to privacy mode. Cause: ' + JSON.stringify(err));
});
```

### setTouchable<sup>7+</sup>

setTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is touchable. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                     | Mandatory| Description                |
| ----------- | ------------------------- | ---- | -------------------- |
| isTouchable | boolean                   | Yes  | Whether the window is touchable.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Example**

```js
var isTouchable = true;
windowClass.setTouchable(isTouchable, (err, data) => {
    if (err.code) {
        console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to be touchable. Data:' + JSON.stringify(data));

});
```

### setTouchable<sup>7+</sup>

setTouchable(isTouchable: boolean): Promise&lt;void&gt;

Sets whether this window is touchable. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type   | Mandatory| Description                |
| ----------- | ------- | ---- | -------------------- |
| isTouchable | boolean | Yes  | Whether the window is touchable.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var isTouchable = true;
let promise = windowClass.setTouchable(isTouchable);
promise.then((data)=> {
    console.info('Succeeded in setting the window to be touchable. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to set the window to be touchable. Cause: ' + JSON.stringify(err));
});
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is forbidden to move in split-screen mode. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                     | Mandatory| Description                |
| ----------- | ------------------------- | ---- | -------------------- |
| isForbidSplitMove | boolean                   | Yes  | Whether the window is forbidden to move in split-screen mode.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Example**

```js
var isForbidSplitMove = true;
windowClass.setForbidSplitMove(isForbidSplitMove, (err, data) => {
    if (err.code) {
        console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in forbidding window moving in split screen mode. Data:' + JSON.stringify(data));

});
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean): Promise&lt;void&gt;

Sets whether this window is forbidden to move in split-screen mode. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type   | Mandatory| Description                |
| ----------- | ------- | ---- | -------------------- |
| isForbidSplitMove | boolean | Yes  | Whether the window is forbidden to move in split-screen mode.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
var isForbidSplitMove = true;
let promise = windowClass.setForbidSplitMove(isForbidSplitMove);
promise.then((data)=> {
    console.info('Succeeded in forbidding window moving in split screen mode. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to forbidd window moving in split screen mode. Cause: ' + JSON.stringify(err));
});
```

## WindowStageEventType<sup>9+</sup>

Describes the lifecycle of a window stage.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Default Value | Description      |
| ---------- | ------ | ---------- |
| FOREGROUND | 1      | The window stage is running in the foreground.|
| ACTIVE     | 2      | The window stage gains focus.|
| INACTIVE   | 3      | The window stage loses focus.|
| BACKGROUND | 4      | The window stage is running in the background.|

## WindowStage<sup>9+</sup>

Implements a window manager, which manages each basic window unit, that is, [Window](#window) instance.

Before calling any of the following APIs, you must use `[onWindowStageCreate()](js-apis-application-ability.md#abilityonwindowstagecreate)` to create a `WindowStage` instance.

### getMainWindow<sup>9+</sup>

getMainWindow(callback: AsyncCallback&lt;Window&gt;): void

Obtains the main window of this window stage. This API uses an asynchronous callback to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                         |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the main window.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        var windowClass = null;
        windowStage.getMainWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        });
    }
}
```
### getMainWindow<sup>9+</sup>

getMainWindow(): Promise&lt;Window&gt;

Obtains the main window of this window stage. This API uses a promise to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](#window)&gt; | Promise used to return the main window.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        var windowClass = null;
        let promise = windowStage.getMainWindow();
        promise.then((data)=> {
        windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        });
    }
}
```
### createSubWindow<sup>9+</sup>

createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow for this window stage. This API uses an asynchronous callback to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                         |
| -------- | -------------------------------------- | ---- | --------------------------------------------- |
| name     | String                                 | Yes  | Name of the subwindow.                               |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the subwindow.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        var windowClass = null;
        windowStage.createSubWindow("mySubWindow", (err, data) => {
            if (err.code) {
                console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
            windowClass.resetSize(500, 1000);
        });
    }
}
```
### createSubWindow<sup>9+</sup>

createSubWindow(name: string): Promise&lt;Window&gt;

Creates a subwindow for this window stage. This API uses a promise to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| name   | String | Yes  | Name of the subwindow.|

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        var windowClass = null;
        let promise = windowStage.createSubWindow("mySubWindow");
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
        })
    }
}
```
### getSubWindow<sup>9+</sup>

getSubWindow(callback: AsyncCallback&lt;Array&lt;Window&gt;&gt;): void

Obtains all the subwindows of this window stage. This API uses an asynchronous callback to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                                             |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Window](#window)&gt;&gt; | Yes  | Callback used to return all the subwindows.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        var windowClass = null;
        windowStage.getSubWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
        });
    }
}
```
### getSubWindow<sup>9+</sup>

getSubWindow(): Promise&lt;Array&lt;Window&gt;&gt;

Obtains all the subwindows of this window stage. This API uses a promise to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                         | Description                                                |
| --------------------------------------------- | ---------------------------------------------------- |
| Promise&lt;Array&lt;[Window](#window)&gt;&gt; | Promise used to return all the subwindows.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        var windowClass = null;
        let promise = windowStage.getSubWindow();
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
        })
    }
}
```
### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page associated with a local storage to the main window in this window stage. This API uses an asynchronous callback to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | Yes  | Path of the page from which the content will be loaded.                                        |
| storage  | LocalStorage | Yes  | A storage unit, which provides storage for variable state properties and non-variable state properties of an application.|
| callback | AsyncCallback&lt;void&gt;                       | Yes  | Callback used to return the result.                                                  |

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    storage : LocalStorage  
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate("storageSimpleProp",121);
        console.log('onWindowStageCreate');
        windowStage.loadContent("pages/page2",this.storage,(err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage?: LocalStorage): Promise&lt;void&gt;

Loads content from a page associated with a local storage to the main window in this window stage. This API uses a promise to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                                           | Mandatory| Description                                                        |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | Yes  | Path of the page from which the content will be loaded.                                        |
| storage | LocalStorage | No  | A storage unit, which provides storage for variable state properties and non-variable state properties of an application.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    storage : LocalStorage 
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate("storageSimpleProp",121);
        console.log('onWindowStageCreate');
        var windowClass = null;
        let promise = windowStage.loadContent("pages/page2",this.storage);
        promise.then((data)=> {
            windowClass = data;
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        }).catch((err)=>{
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
        })
    }
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page to this window stage. This API uses an asynchronous callback to return the result.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| path     | string                    | Yes  | Path of the page from which the content will be loaded.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.loadContent("pages/page2", (err, data) => {
            if (err.code) {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in loading the content. Data: ' + JSON.stringify(data));
        });
    }
}
```

### on('windowStageEvent')<sup>9+</sup>

on(eventType: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void

Enables listening for window stage lifecycle changes.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at `windowStageEvent`, indicating the window stage lifecycle change event.|
| callback | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | Yes  | Callback used to return the window stage lifecycle state.               |

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.on('windowStageEvent', (data) => {
            console.info('Succeeded in enabling the listener for window stage event changes. Data: ' + JSON.stringify(data));
        });
    }
}
```

### off('windowStageEvent')<sup>9+</sup>

off(eventType: 'windowStageEvent', callback?: Callback&lt;WindowStageEventType&gt;): void

Disables listening for window stage lifecycle changes.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is fixed at `windowStageEvent`, indicating the window stage lifecycle change event.|
| callback | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | No  | Callback used to return the window stage lifecycle state.               |

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.off('windowStageEvent');
    }
}
```

### disableWindowDecor()<sup>9+</sup>

disableWindowDecor(): void

Disables window decorators.

This type can be used only in the stage model.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('disableWindowDecor');
        windowStage.disableWindowDecor();
    }
}
```

### setShowOnLockScreen()<sup>9+</sup>

setShowOnLockScreen(showOnLockScreen: boolean): void

Sets whether to display the window of the application on the lock screen.

This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| showOnLockScreen | boolean | Yes  | Whether to display the window on the lock screen.|

**Example**

```ts
import Ability from '@ohos.application.Ability';
class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        windowStage.setShowOnLockScreen(true);
    }
}
```

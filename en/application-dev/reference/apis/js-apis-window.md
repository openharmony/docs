# @ohos.window

The **Window** module provides basic window management capabilities, such as creating and destroying the current window, setting properties for the current window, and managing and scheduling windows.

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
| TYPE_APP          | 0      | Application subwindow.<br>**Model restriction**: This API can be used only in the FA model.|
| TYPE_SYSTEM_ALERT | 1      | System alert window.|
| TYPE_INPUT_METHOD<sup>9+</sup> | 2      | Input method window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_STATUS_BAR<sup>9+</sup>   | 3      | Status bar.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_PANEL<sup>9+</sup>        | 4      | Notification panel.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_KEYGUARD<sup>9+</sup>     | 5      | Lock screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_VOLUME_OVERLAY<sup>9+</sup> | 6      | Volume bar.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_NAVIGATION_BAR<sup>9+</sup> | 7      | Navigation bar.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_FLOAT<sup>9+</sup> | 8      | Floating window.<br>**Model restriction**: This API can be used only in the stage model.<br>**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW|
| TYPE_WALLPAPER<sup>9+</sup> | 9      | Wallpaper.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_DESKTOP<sup>9+</sup> | 10      | Home screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_LAUNCHER_RECENT<sup>9+</sup> | 11      | Recent tasks screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_LAUNCHER_DOCK<sup>9+</sup> | 12      | Dock bar on the home screen.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_VOICE_INTERACTION<sup>9+</sup> | 13      | Voice assistant.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_POINTER<sup>9+</sup> | 14      | Mouse.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_FLOAT_CAMERA<sup>9+</sup> | 15      | Floating camera window.<br>**Model restriction**: This API can be used only in the stage model.<br>**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW|
| TYPE_DIALOG<sup>9+</sup>  | 16      | Modal window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| TYPE_SCREENSHOT<sup>9+</sup>  | 17      | Screenshot window.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|

## Configuration<sup>9+</sup>

Defines the parameters for creating a subwindow or system window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Mandatory| Description|
| ---------- | -------------------------- | -- | ----------------------------------- |
| name       | string                     | Yes| Name of the window.                        |
| windowType | [WindowType](#windowtype7) | Yes| Type of the window.                        |
| ctx        | BaseContext                | No| Current application context.<br>For details about the context in the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the context in the stage model, see [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md). If this parameter is not set, no context is used.<br>A system window is created when **Context** is [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md).|
| displayId  | number                     | No| ID of the current physical screen. If this parameter is not set, the default value **-1** is used.|
| parentId   | number                     | No| ID of the parent window. If this parameter is not set, the default value **-1** is used.     |

## AvoidAreaType<sup>7+</sup>

Enumerates the types of the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                            | Value  | Description                                                        |
| -------------------------------- | ---- | ------------------------------------------------------------ |
| TYPE_SYSTEM                      | 0    | Default area of the system. Generally, the status bar, navigation bar, and Dock bar are included. The default area may vary according to the device in use.|
| TYPE_CUTOUT                      | 1    | Notch.                                            |
| TYPE_SYSTEM_GESTURE<sup>9+</sup> | 2    | Gesture area.                                              |
| TYPE_KEYBOARD<sup>9+</sup>       | 3    | Soft keyboard area.                                            |

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

## SystemBarProperties

Describes the properties of the status bar and navigation bar.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                                  | Type|  Mandatory| Description                                                        |
| -------------------------------------- | -------- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   |  No  | Background color of the status bar. The value is a hexadecimal RGB or aRGB color value and is case insensitive, for example, **#00FF00** or **#FF00FF00**. The default value is **#0x66000000**.|
| isStatusBarLightIcon<sup>7+</sup>      | boolean  |  No  | Whether any icon on the status bar is highlighted. The value **true** means that the icon is highlighted, and **false** means the opposite. The default value is **false**.|
| statusBarContentColor<sup>8+</sup>     | string   |  No  | Color of the text on the status bar. After this property is set, the setting of **isStatusBarLightIcon** is invalid. The default value is **0xE5FFFFFF**.|
| navigationBarColor                     | string   |  No  | Background color of the navigation bar. The value is a hexadecimal RGB or aRGB color value and is case insensitive, for example, **#00FF00** or **#FF00FF00**. The default value is **#0x66000000**.|
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  |  No  | Whether any icon on the navigation bar is highlighted. The value **true** means that the icon is highlighted, and **false** means the opposite. The default value is **false**.|
| navigationBarContentColor<sup>8+</sup> | string   |  No  | Color of the text on the navigation bar. After this property is set, the setting of **isNavigationBarLightIcon** is invalid. The default value is **0xE5FFFFFF**.|

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
| region          | [Rect](#rect7)             | Yes  | No  | Current position and size of the system bar.                                    |
| backgroundColor | string                    | Yes  | No  | Background color of the system bar. The value is a hexadecimal RGB or aRGB color value and is case insensitive, for example, **#00FF00** or **#FF00FF00**.|
| contentColor    | string                    | Yes  | No  | Color of the text on the system bar.                                            |

## SystemBarTintState<sup>8+</sup>

Describes the callback for the current system bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Type                                           | Readable| Writable| Description                        |
| ---------- | --------------------------------------------------- | ---- | ---- | ---------------------------- |
| displayId  | number                                              | Yes  | No  | ID of the current physical screen.            |
| regionTint | Array<[SystemBarRegionTint](#systembarregiontint8)> | Yes  | No  | All system bar information that has been changed.|

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
| visible<sup>9+</sup>    | boolean       | Yes  | Yes  | Whether the window can be displayed in the area. The value **true** means that the window can be displayed in the area, and **false** means the opposite.|
| leftRect   | [Rect](#rect7) | Yes  | Yes  | Rectangle on the left of the screen.|
| topRect    | [Rect](#rect7) | Yes  | Yes  | Rectangle at the top of the screen.|
| rightRect  | [Rect](#rect7) | Yes  | Yes  | Rectangle on the right of the screen.|
| bottomRect | [Rect](#rect7) | Yes  | Yes  | Rectangle at the bottom of the screen.|

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

| Name                                 | Type                 | Readable| Writable| Description                                                        |
| ------------------------------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| windowRect<sup>7+</sup>               | [Rect](#rect7)             | Yes  | Yes  | Window size.                                                  |
| type<sup>7+</sup>                     | [WindowType](#windowtype7) | Yes  | Yes  | Window type.                                                  |
| isFullScreen                          | boolean                   | Yes  | Yes  | Whether the window is displayed in full screen mode. The default value is **false**. The value **true** means that the window is displayed in full screen mode, and **false** means the opposite.|
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | Yes  | Yes  | Whether the window layout is in full-screen mode (whether the window is immersive). The default value is **false**. The value **true** means that the window is immersive, and **false** means the opposite.|
| focusable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window can gain focus. The default value is **true**. The value **true** means that the window can gain focus, and **false** means the opposite.|
| touchable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window is touchable. The default value is **true**. The value **true** means that the window is touchable, and **false** means the opposite.|
| brightness                            | number                    | Yes  | Yes  | Screen brightness. The value ranges from 0 to 1. The value **1** indicates the maximum brightness.                 |
| dimBehindValue<sup>(deprecated)</sup> | number                    | Yes  | Yes  | Dimness of the window that is not on top. The value ranges from 0 to 1. The value **1** indicates the maximum dimness.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9.<br> |
| isKeepScreenOn                        | boolean                   | Yes  | Yes  | Whether the screen is always on. The default value is **false**. The value **true** means that the screen is always on, and **false** means the opposite.|
| isPrivacyMode<sup>7+</sup>            | boolean                   | Yes  | Yes  | Whether the window is in privacy mode. The default value is **false**. The value **true** means that the window is in privacy mode, and **false** means the opposite.|
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | Yes  | Yes  | Whether the window has rounded corners. The default value is **false**. The value **true** means that the window has rounded corners, and **false** means the opposite.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9.<br> |
| isTransparent<sup>7+</sup>            | boolean                   | Yes  | Yes  | Whether the window is transparent. The default value is **false**. The value **true** means that the window is transparent, and **false** means the opposite.|
| id<sup>9+</sup>                       | number                    | Yes  | No  | Window ID. The default value is **0.0**.                                                 |

## ColorSpace<sup>8+</sup>

Enumerates the color spaces.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value| Description          |
| ---------- | ------ | -------------- |
| DEFAULT    | 0      | Default gamut.|
| WIDE_GAMUT | 1      | Wide-gamut.  |

## ScaleOptions<sup>9+</sup>

Describes the scale parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Readable| Writable| Description                                              |
| ------ | -------- | ---- | ---- | -------------------------------------------------- |
| x      | number   | No  | Yes  | Scale factor along the x-axis. The default value is **1.0**.                      |
| y      | number   | No  | Yes  | Scale factor along the y-axis. The default value is **1.0**.                      |
| pivotX | number   | No  | Yes  | X coordinate of the scale center. The value ranges from 0.0 to 1.0, and the default value is **0.5**.|
| pivotY | number   | No  | Yes  | Y coordinate of the scale center. The value ranges from 0.0 to 1.0, and the default value is **0.5**.|

## RotateOptions<sup>9+</sup>

Describes the rotation parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Readable| Writable| Description                                              |
| ------ | -------- | ---- | ---- | -------------------------------------------------- |
| x      | number   | No  | Yes  | Rotation angle around the x-axis. The default value is **0.0**.                    |
| y      | number   | No  | Yes  | Rotation angle around the y-axis. The default value is **0.0**.                    |
| z      | number   | No  | Yes  | Rotation angle around the z-xis. The default value is **0.0**.                    |
| pivotX | number   | No  | Yes  | X coordinate of the rotation center. The value ranges from 0.0 to 1.0, and the default value is **0.5**.|
| pivotY | number   | No  | Yes  | Y coordinate of the rotation center. The value ranges from 0.0 to 1.0, and the default value is **0.5**.|

## TranslateOptions<sup>9+</sup>

Describes the translation parameters.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Readable| Writable| Description                        |
| ---- | -------- | ---- | ---- | ---------------------------- |
| x    | number   | No  | Yes  | Distance to translate along the x-axis. The default value is **0.0**.|
| y    | number   | No  | Yes  | Distance to translate along the y-axis. The default value is **0.0**.|
| z    | number   | No  | Yes  | Distance to translate along the z-axis. The default value is **0.0**.|

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow or system window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------------------- | -- | --------------------------------- |
| config   | [Configuration](#configuration9)       | Yes| Parameters used for creating the window.  |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes| Callback used to return the window created.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 1300001 | Repeated operation. |
| 1300006 | This window context is abnormal. |

**Example**

```js
let windowClass = null;
let config = {name: "alertWindow", windowType: window.WindowType.TYPE_SYSTEM_ALERT, ctx: this.context};
try {
    window.createWindow(config, (err, data) => {
        if (err.code) {
            console.error('Failed to create the window. Cause: ' + JSON.stringify(err));
            return;
        }
        windowClass = data;
        console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));
        windowClass.resetSize(500, 1000);
    });
} catch (exception) {
    console.error('Failed to create the window. Cause: ' + JSON.stringify(exception));
}
```

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration): Promise&lt;Window&gt;

Creates a subwindow or system window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------------------------------- | -- | ------------------ |
| config | [Configuration](#configuration9) | Yes| Parameters used for creating the window.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------ |
| Promise&lt;[Window](#window)&gt; | Promise used to return the window created.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 1300001 | Repeated operation. |
| 1300006 | This window context is abnormal. |

**Example**

```js
let windowClass = null;
let config = {name: "alertWindow", windowType: window.WindowType.TYPE_SYSTEM_ALERT, ctx: this.context};
try {
    let promise = window.createWindow(config);
    promise.then((data)=> {
        windowClass = data;
        console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
    }).catch((err)=>{
        console.error('Failed to create the Window. Cause:' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to create the window. Cause: ' + JSON.stringify(exception));
}
```

## window.findWindow<sup>9+</sup>

findWindow(name: string): Window

Finds a window based on the name.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| name   | string | Yes  | Window ID.|

**Return value**

| Type| Description|
| ----------------- | ------------------- |
| [Window](#window) | Window found.|

**Example**

```js
let windowClass = null;
try {
    windowClass = window.findWindow('alertWindow');
} catch (exception) {
    console.error('Failed to find the Window. Cause: ' + JSON.stringify(exception));
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext, callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------------------- | -- | ---------------------------------------- |
| ctx      | BaseContext                            | Yes| Current application context.<br>For details about the context in the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the context in the stage model, see [Context](js-apis-ability-context.md).|
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes| Callback used to return the top window obtained.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 1300002 | This window state is abnormal.   |
| 1300006 | This window context is abnormal. |

**Example**

```js
let windowClass = null;
try {
    window.getLastWindow(this.context, (err, data) => {
        if (err.code) {
            console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
            return;
        }
        windowClass = data;
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(exception));
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | BaseContext | Yes  | Current application context.<br>For details about the context in the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the context in the stage model, see [Context](js-apis-ability-context.md).|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the top window obtained.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 1300002 | This window state is abnormal.   |
| 1300006 | This window context is abnormal. |

**Example**

```js
let windowClass = null;
try {
    let promise = window.getLastWindow(this.context);
    promise.then((data)=> {
        windowClass = data;
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
    }).catch((err)=>{
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(exception));
}
```

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

Minimizes all windows on a display. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | Yes  | ID of the [display](js-apis-display.md#display).|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
import display from '@ohos.display'

let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();

    try {
        window.minimizeAll(displayClass.id, (err) => {
            if(err.code) {
                console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));
                return;
            }
            console.info('Succeeded in minimizing all windows.');
        });
    } catch (exception) {
        console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(exception));
    }
} catch (exception) {
    console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
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
| id       | number                    | Yes  | ID of the [display](js-apis-display.md#display).|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
import display from '@ohos.display'

let displayClass = null;
try {
    displayClass = display.getDefaultDisplaySync();

    try {
        let promise = window.minimizeAll(displayClass.id);
        promise.then(()=> {
            console.info('Succeeded in minimizing all windows.');
        }).catch((err)=>{
            console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(err));
        });
    } catch (exception) {
        console.error('Failed to minimize all windows. Cause: ' + JSON.stringify(exception));
    }
} catch (exception) {
    console.error('Failed to obtain the default display object. Code: ' + JSON.stringify(exception));
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

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
window.toggleShownStateForAllAppWindows((err) => {
    if (err.code) {
        console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));
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

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let promise = window.toggleShownStateForAllAppWindows();
promise.then(()=> {
    console.info('Succeeded in toggling shown state for all app windows.');
}).catch((err)=>{
    console.error('Failed to toggle shown state for all app windows. Cause: ' + JSON.stringify(err));
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

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE, (err) => {
        if(err.code) {
            console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting window layout mode.');
    });
} catch (exception) {
    console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(exception));
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

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    let promise = window.setWindowLayoutMode(window.WindowLayoutMode.WINDOW_LAYOUT_MODE_CASCADE);
    promise.then(()=> {
        console.info('Succeeded in setting window layout mode.');
    }).catch((err)=>{
        console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set window layout mode. Cause: ' + JSON.stringify(exception));
}
```

## window.on('systemBarTintChange')<sup>8+</sup>

on(type: 'systemBarTintChange', callback: Callback&lt;SystemBarTintState&gt;): void

Enables listening for properties changes of the status bar and navigation bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | Yes  | Event type. The value is fixed at **'systemBarTintChange'**, indicating the property change event of the status bar and navigation bar.|
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | Yes  | Callback used to return the properties of the status bar and navigation bar.                |

**Example**

```js
try {
    window.on('systemBarTintChange', (data) => {
        console.info('Succeeded in enabling the listener for systemBarTint changes. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to enable the listener for systemBarTint changes. Cause: ' + JSON.stringify(exception));
}
```

## window.off('systemBarTintChange')<sup>8+</sup>

off(type: 'systemBarTintChange', callback?: Callback&lt;SystemBarTintState &gt;): void

Disables listening for properties changes of the status bar and navigation bar.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | Yes  | Event type. The value is fixed at **'systemBarTintChange'**, indicating the property change event of the status bar and navigation bar.|
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | No  | Callback used to return the properties of the status bar and navigation bar.                |

**Example**

```js
try {
    window.off('systemBarTintChange');
} catch (exception) {
    console.error('Failed to disable the listener for systemBarTint changes. Cause: ' + JSON.stringify(exception));
}
```

## window.create<sup>(deprecated)</sup>

create(id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | Yes  | Window ID.                            |
| type     | [WindowType](#windowtype7)              | Yes  | Window type.                          |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the subwindow created.|

**Example**

```js
let windowClass = null;
window.create('first', window.WindowType.TYPE_APP,(err,data) => {
    if(err.code){
        console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));
});
```

## window.create<sup>(deprecated)</sup>

create(id: string, type: WindowType): Promise&lt;Window&gt;

Creates a subwindow. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9-1) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description      |
| ------ | ------------------------- | ---- | ---------- |
| id     | string                    | Yes  | Window ID.  |
| type   | [WindowType](#windowtype7) | Yes  | Window type.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow created.|

**Example**

```js
let windowClass = null;
let promise = window.create('first', window.WindowType.TYPE_APP);
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to create the subWindow. Cause: ' + JSON.stringify(err));
});
```

## window.create<sup>(deprecated)</sup>

create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow (in API version 8) or a system window (from API version 9). This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | BaseContext                            | Yes  | Current application context.<br>For details about the context in the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the context in the stage model, see [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md).|
| id       | string                                 | Yes  | Window ID.                                                    |
| type     | [WindowType](#windowtype7)              | Yes  | Window type.                                                  |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the subwindow created.                        |

**Example**

```js
let windowClass = null;
window.create(this.context, 'alertWindow', window.WindowType.TYPE_SYSTEM_ALERT, (err, data) => {
    if (err.code) {
        console.error('Failed to create the window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));
    windowClass.resetSize(500, 1000);
});
```

## window.create<sup>(deprecated)</sup>

create(ctx: BaseContext, id: string, type: WindowType): Promise&lt;Window&gt;

Creates a subwindow (in API version 8) or a system window (from API version 9). This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| ctx    | BaseContext               | Yes  | Current application context.<br>For details about the context in the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the context in the stage model, see [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md).|
| id     | string                    | Yes  | Window ID.                                                    |
| type   | [WindowType](#windowtype7) | Yes  | Window type.                                                  |

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow created.|

**Example**

```js
let windowClass = null;
let promise = window.create(this.context, 'alertWindow', window.WindowType.TYPE_SYSTEM_ALERT);
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to create the Window. Cause:' + JSON.stringify(err));
});
```

## window.find<sup>(deprecated)</sup>

find(id: string, callback: AsyncCallback&lt;Window&gt;): void

Finds a window based on the ID. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [findWindow()](#windowfindwindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                |
| -------- | -------------------------------------- | ---- | ------------------------------------ |
| id       | string                                 | Yes  | Window ID.                            |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the window found.|

**Example**

```js
let windowClass = null;
window.find('alertWindow', (err, data) => {
    if (err.code) {
        console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));
});
```

## window.find<sup>(deprecated)</sup>

find(id: string): Promise&lt;Window&gt;

Finds a window based on the ID. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [findWindow()](#windowfindwindow9) instead.

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
let windowClass = null;
let promise = window.find('alertWindow');
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to find the Window. Cause: ' + JSON.stringify(err));
});
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                        |
| -------- | -------------------------------------- | ---- | -------------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the top window obtained.|

**Example**

```js
let windowClass = null;
window.getTopWindow((err, data) => {
    if (err.code) {
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
});
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9-1) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                            | Description                                           |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the top window obtained.|

**Example**

```js
let windowClass = null;
let promise = window.getTopWindow();
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
});
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(ctx: BaseContext, callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| ctx      | BaseContext                            | Yes  | Current application context.<br>For details about the context in the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the context in the stage model, see [Context](js-apis-ability-context.md).|
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the top window obtained.                |

**Example**

```js
let windowClass = null;
window.getTopWindow(this.context, (err, data) => {
    if (err.code) {
        console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
        return;
    }
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
});
```

## window.getTopWindow<sup>(deprecated)</sup>

getTopWindow(ctx: BaseContext): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result.

> **NOTE**
> 
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getLastWindow()](#windowgetlastwindow9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | BaseContext | Yes  | Current application context.<br>For details about the context in the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the context in the stage model, see [Context](js-apis-ability-context.md).|

**Return value**

| Type                            | Description                                           |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the top window obtained.|

**Example**

```js
let windowClass = null;
let promise = window.getTopWindow(this.context);
promise.then((data)=> {
 	windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the top window. Cause: ' + JSON.stringify(err));
});
```

## Window

Represents the current window instance, which is the basic unit managed by the window manager.

In the following API examples, you must use [getLastWindow()](#windowgetlastwindow9), [createWindow()](#windowcreatewindow9), or [findWindow()](#windowfindwindow9) to obtain a **Window** instance and then call a method in this instance.

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

Hides this window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
windowClass.hide((err) => {
    if (err.code) {
        console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in hiding the window.');
});
```

### hide<sup>7+</sup>

hide(): Promise&lt;void&gt;

Hides this window. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let promise = windowClass.hide();
promise.then(()=> {
    console.info('Succeeded in hiding the window.');
}).catch((err)=>{
    console.error('Failed to hide the window. Cause: ' + JSON.stringify(err));
});
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(callback: AsyncCallback&lt;void&gt;): void

Hides this window and plays an animation during the process. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```js
windowClass.hideWithAnimation((err) => {
    if (err.code) {
        console.error('Failed to hide the window with animation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in hiding the window with animation.');
});
```

### hideWithAnimation<sup>9+</sup>

hideWithAnimation(): Promise&lt;void&gt;

Hides this window and plays an animation during the process. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```js
let promise = windowClass.hideWithAnimation();
promise.then(()=> {
    console.info('Succeeded in hiding the window with animation.');
}).catch((err)=>{
    console.error('Failed to hide the window with animation. Cause: ' + JSON.stringify(err));
});
```

### showWindow<sup>9+</sup>

showWindow(callback: AsyncCallback&lt;void&gt;): void

Shows this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
windowClass.showWindow((err) => {
    if (err.code) {
        console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window.');
});
```

### showWindow<sup>9+</sup>

showWindow(): Promise&lt;void&gt;

Shows this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let promise = windowClass.showWindow();
promise.then(()=> {
    console.info('Succeeded in showing the window.');
}).catch((err)=>{
    console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
});
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(callback: AsyncCallback&lt;void&gt;): void

Shows this window and plays an animation during the process. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```js
windowClass.showWithAnimation((err) => {
    if (err.code) {
        console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window with animation.');
});
```

### showWithAnimation<sup>9+</sup>

showWithAnimation(): Promise&lt;void&gt;

Shows this window and plays an animation during the process. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```js
let promise = windowClass.showWithAnimation();
promise.then(()=> {
    console.info('Succeeded in showing the window with animation.');
}).catch((err)=>{
    console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));
});
```

### destroyWindow<sup>9+</sup>

destroyWindow(callback: AsyncCallback&lt;void&gt;): void

Destroys this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
windowClass.destroyWindow((err) => {
    if (err.code) {
        console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in destroying the window.');
});
```

### destroyWindow<sup>9+</sup>

destroyWindow(): Promise&lt;void&gt;

Destroys this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let promise = windowClass.destroyWindow();
promise.then(()=> {
    console.info('Succeeded in destroying the window.');
}).catch((err)=>{
    console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
});
```

### moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

Moves this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | --------------------------------------------- |
| x        | number                    | Yes| Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right.|
| y        | number                    | Yes| Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                    |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    windowClass.moveWindowTo(300, 300, (err)=>{
        if (err.code) {
            console.error('Failed to move the window. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in moving the window.');
    });
} catch (exception) {
    console.error('Failed to move the window. Cause:' + JSON.stringify(exception));
}
```

### moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number): Promise&lt;void&gt;

Moves this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right.|
| y | number | Yes| Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    let promise = windowClass.moveWindowTo(300, 300);
    promise.then(()=> {
        console.info('Succeeded in moving the window.');
    }).catch((err)=>{
        console.error('Failed to move the window. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to move the window. Cause:' + JSON.stringify(exception));
}
```

### resize<sup>9+</sup>

resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

Changes the size of this window. This API uses an asynchronous callback to return the result.

The main window and subwindow have the following size limits: [320, 2560] in width and [240, 2560] in height, both in units of vp.

The system window has the following size limits: [0, 2560] in width and [0, 2560] in height, both in units of vp.

The new width and height you set must meet the limits.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | ------------------------ |
| width    | number                    | Yes| New width of the window, in px.|
| height   | number                    | Yes| New height of the window, in px.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.               |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    windowClass.resize(500, 1000, (err) => {
        if (err.code) {
            console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in changing the window size.');
    });
} catch (exception) {
    console.error('Failed to change the window size. Cause:' + JSON.stringify(exception));
}
```

### resize<sup>9+</sup>

resize(width: number, height: number): Promise&lt;void&gt;

Changes the size of this window. This API uses a promise to return the result.

The main window and subwindow have the following size limits: [320, 2560] in width and [240, 2560] in height, both in units of vp.

The system window has the following size limits: [0, 2560] in width and [0, 2560] in height, both in units of vp.

The new width and height you set must meet the limits.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | -- | ------------------------ |
| width  | number | Yes| New width of the window, in px.|
| height | number | Yes| New height of the window, in px.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    let promise = windowClass.resize(500, 1000);
    promise.then(()=> {
        console.info('Succeeded in changing the window size.');
    }).catch((err)=>{
        console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to change the window size. Cause: ' + JSON.stringify(exception));
}
```

### setWindowMode<sup>9+</sup>

setWindowMode(mode: WindowMode, callback: AsyncCallback&lt;void&gt;): void

Sets the mode of this window. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------- | -- | --------- |
| mode     | [WindowMode](#windowmode7) | Yes| Window mode to set.|
| callback | AsyncCallback&lt;void&gt;  | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let mode = window.WindowMode.FULLSCREEN;
try {
    windowClass.setWindowMode(mode, (err) => {
    if (err.code) {
        console.error('Failed to set the window mode. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window mode.');
    });
} catch (exception) {
    console.error('Failed to set the window mode. Cause: ' + JSON.stringify(exception));
}
```

### setWindowMode<sup>9+</sup>

setWindowMode(mode: WindowMode): Promise&lt;void&gt;

Sets the type of this window. This API uses a promise to return the result.

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

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let mode = window.WindowMode.FULLSCREEN;
try {
    let promise = windowClass.setWindowMode(mode);
    promise.then(()=> {
        console.info('Succeeded in setting the window mode.');
    }).catch((err)=>{
        console.error('Failed to set the window mode. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the window mode. Cause: ' + JSON.stringify(exception));
}
```

### getWindowProperties<sup>9+</sup>

getWindowProperties(): WindowProperties

Obtains the properties of this window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ------------------------------------- | ------------- |
| [WindowProperties](#windowproperties) | Window properties obtained.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
try {
    let properties = windowClass.getWindowProperties();
} catch (exception) {
    console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(exception));
}
```

### getWindowAvoidArea<sup>9+</sup>

getWindowAvoidArea(type: AvoidAreaType): AvoidArea

Obtains the area where this window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- |----------------------------------| -- | ------------------------------------------------------------ |
| type | [AvoidAreaType](#avoidareatype7) | Yes| Type of the area. **TYPE_SYSTEM** indicates the default area of the system. **TYPE_CUTOUT** indicates the notch. **TYPE_SYSTEM_GESTURE** indicates the gesture area. **TYPE_KEYBOARD** indicates the soft keyboard area.|

**Return value**

| Type| Description|
|--------------------------| ----------------- |
| [AvoidArea](#avoidarea7) | Area where the window cannot be displayed.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let type = window.AvoidAreaType.TYPE_SYSTEM;
try {
    let avoidArea = windowClass.getWindowAvoidArea(type);
} catch (exception) {
    console.error('Failed to obtain the area. Cause:' + JSON.stringify(exception));
}
```

### setWindowLayoutFullScreen<sup>9+</sup>

setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the full-screen mode for the window layout. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------------------ | ------------------------- | -- | --------- |
| isLayoutFullScreen | boolean                   | Yes| Whether to enable the full-screen mode for the window layout, in which the status bar and navigation bar are displayed. The value **true** means to enable the full-screen mode for the window layout, and **false** means the opposite.|
| callback           | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isLayoutFullScreen= true;
try {
    windowClass.setWindowLayoutFullScreen(isLayoutFullScreen, (err) => {
        if (err.code) {
            console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window layout to full-screen mode.');
    });
} catch (exception) {
    console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(exception));
}
```

### setWindowLayoutFullScreen<sup>9+</sup>

setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

Sets whether to enable the full-screen mode for the window layout. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------------------ | ------- | -- | ------------------------------------------------------------------------------------------------ |
| isLayoutFullScreen | boolean | Yes| Whether to enable the full-screen mode for the window layout, in which the status bar and navigation bar are displayed. The value **true** means to enable the full-screen mode for the window layout, and **false** means the opposite.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isLayoutFullScreen = true;
try {
    let promise = windowClass.setWindowLayoutFullScreen(isLayoutFullScreen);
    promise.then(()=> {
        console.info('Succeeded in setting the window layout to full-screen mode.');
    }).catch((err)=>{
        console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(exception));
}
```

### setWindowSystemBarEnable<sup>9+</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

Sets whether to display the status bar and navigation bar in this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------- | -- | --------- |
| names    | Array<'status'\|'navigation'> | Yes| Whether to display the status bar and navigation bar.<br>For example, to display the status bar and navigation bar, set this parameter to **['status', 'navigation']**. By default, they are not displayed.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
// In this example, the status bar and navigation bar are not displayed.
let names = [];
try {
    windowClass.setWindowSystemBarEnable(names, (err) => {
        if (err.code) {
            console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the system bar to be invisible.');
    });
} catch (exception) {
    console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(exception));
}
```

### setWindowSystemBarEnable<sup>9+</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

Sets whether to display the status bar and navigation bar in this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type | Mandatory| Description|
| ----- | ---------------------------- | -- | --------------------------------- |
| names | Array<'status'\|'navigation'> | Yes| Whether to display the status bar and navigation bar.<br>For example, to display the status bar and navigation bar, set this parameter to **['status', 'navigation']**. By default, they are not displayed.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
// In this example, the status bar and navigation bar are not displayed.
let names = [];
try {
    let promise = windowClass.setWindowSystemBarEnable(names);
    promise.then(()=> {
        console.info('Succeeded in setting the system bar to be invisible.');
    }).catch((err)=>{
        console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(exception));
}
```

### setWindowSystemBarProperties<sup>9+</sup>

setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

Sets the properties of the status bar and navigation bar in this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| SystemBarProperties | [SystemBarProperties](#systembarproperties) | Yes  | Properties of the status bar and navigation bar.|
| callback            | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result.            |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let SystemBarProperties = {
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    // The following properties are supported since API version 8.
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
try {
    windowClass.setWindowSystemBarProperties(SystemBarProperties, (err) => {
        if (err.code) {
            console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the system bar properties.');
    });
} catch (exception) {
    console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(exception));
}
```

### setWindowSystemBarProperties<sup>9+</sup>

setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

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

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let SystemBarProperties = {
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    // The following properties are supported since API version 8.
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
try {
    let promise = windowClass.setWindowSystemBarProperties(SystemBarProperties);
    promise.then(()=> {
        console.info('Succeeded in setting the system bar properties.');
    }).catch((err)=>{
        console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(exception));
}
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

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let orientation = window.Orientation.AUTO_ROTATION;
try {
    windowClass.setPreferredOrientation(orientation, (err) => {
        if (err.code) {
            console.error('Failed to set window orientation. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting window orientation.');
    });
} catch (exception) {
    console.error('Failed to set window orientation. Cause: ' + JSON.stringify(exception));
}
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

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let orientation = window.Orientation.AUTO_ROTATION;
try {
    let promise = windowClass.setPreferredOrientation(orientation);
    promise.then(()=> {
        console.info('Succeeded in setting the window orientation.');
    }).catch((err)=>{
        console.error('Failed to set the window orientation. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set window orientation. Cause: ' + JSON.stringify(exception));
}
```

### setUIContent<sup>9+</sup>

setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page to this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | -------------------- |
| path     | string                    | Yes| Path of the page from which the content will be loaded.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.         |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    windowClass.setUIContent('pages/page2/page2', (err) => {
    if (err.code) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
    }
    console.info('Succeeded in loading the content.');
    });
} catch (exception) {
    console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
}
```

### setUIContent<sup>9+</sup>

setUIContent(path: string): Promise&lt;void&gt;

Loads content from a page to this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | -- | ------------------ |
| path | string | Yes| Path of the page from which the content will be loaded.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
try {
    let promise = windowClass.setUIContent('pages/page2/page2');
    promise.then(()=> {
        console.info('Succeeded in loading the content.');
    }).catch((err)=>{
        console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to load the content. Cause: ' + JSON.stringify(exception));
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page associated with a local storage to this window. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | Yes  | Path of the page from which the content will be loaded.                                        |
| storage  | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | Yes  | A storage unit, which provides storage for variable state properties and non-variable state properties of an application.|
| callback | AsyncCallback&lt;void&gt;                       | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
console.log('onWindowStageCreate');
try {
    windowClass.loadContent('pages/page2', storage, (err) => {
        if (err.code) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in loading the content.');
    });
} catch (exception) {
    console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage): Promise&lt;void&gt;

Loads content from a page associated with a local storage to this window. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                                           | Mandatory| Description                                                        |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | Yes  | Path of the page from which the content will be loaded.                                        |
| storage | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | Yes  | A storage unit, which provides storage for variable state properties and non-variable state properties of an application.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
console.log('onWindowStageCreate');
try {
    let promise = windowClass.loadContent('pages/page2', storage);
    promise.then(() => {
        console.info('Succeeded in loading the content.');
    }).catch((err) => {
        console.error('Failed to load the content. Cause:' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
}
```

### isWindowShowing<sup>9+</sup>

isWindowShowing(): boolean

Checks whether this window is displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ------- | ------------------------------------------------------------------ |
| boolean | Whether the window is displayed. The value **true** means that the window is displayed, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
try {
    let data = windowClass.isWindowShowing();
    console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
} catch (exception) {
    console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(exception));
}
```

### on('windowSizeChange')<sup>7+</sup>

on(type:  'windowSizeChange', callback: Callback&lt;Size&gt;): void

Enables listening for window size changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | Callback&lt;[Size](#size7)&gt; | Yes  | Callback used to return the window size.                          |

**Example**

```js
try {
    windowClass.on('windowSizeChange', (data) => {
        console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to enable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

### off('windowSizeChange')<sup>7+</sup>

off(type: 'windowSizeChange', callback?: Callback&lt;Size&gt;): void

Disables listening for window size changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                         | Mandatory| Description                                                    |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | Callback&lt;[Size](#size)&gt; | No  | Callback used to return the window size.                          |

**Example**

```js
try {
    windowClass.off('windowSizeChange');
} catch (exception) {
    console.error('Failed to disable the listener for window size changes. Cause: ' + JSON.stringify(exception));
}
```

### on('avoidAreaChange')<sup>9+</sup>

on(type: 'avoidAreaChange', callback: Callback&lt;{AvoidAreaType, AvoidArea}&gt;): void

Enables listening for changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                              | Mandatory| Description                                  |
| -------- |------------------------------------------------------------------| ---- |--------------------------------------|
| type     | string                                                           | Yes  | Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt; | Yes  | Callback used to return the area and area type.|

**Example**

```js
try {
    windowClass.on('avoidAreaChange', (data) => {
        console.info('Succeeded in enabling the listener for system avoid area changes. type:' +
            JSON.stringify(data.type) + ', area: ' + JSON.stringify(data.area));
    });
} catch (exception) {
    console.error('Failed to enable the listener for system avoid area changes. Cause: ' + JSON.stringify(exception));
}
```

### off('avoidAreaChange')<sup>9+</sup>

off(type: 'avoidAreaChange', callback: Callback&lt;{AvoidAreaType, AvoidArea}&gt;): void

Disables listening for changes to the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                                         | Mandatory | Description                                |
| -------- |-----------------------------------------------------------------------------|-----|------------------------------------|
| type     | string                                                                      | Yes  | Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;{[AvoidAreaType](#avoidareatype7), [AvoidArea](#avoidarea7)}&gt; | No  | Callback used to return the area and area type.|

**Example**

```js
try {
    windowClass.off('avoidAreaChange');
} catch (exception) {
    console.error('Failed to disable the listener for system avoid area changes. Cause: ' + JSON.stringify(exception));
}
```

### on('keyboardHeightChange')<sup>7+</sup>

on(type: 'keyboardHeightChange', callback: Callback&lt;number&gt;): void

Enables listening for keyboard height changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type               | Mandatory| Description                                                        |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'keyboardHeightChange'**, indicating the keyboard height change event.|
| callback | Callback&lt;number&gt; | Yes  | Callback used to return the current keyboard height.                              |

**Example**

```js
try {
    windowClass.on('keyboardHeightChange', (data) => {
        console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to enable the listener for keyboard height changes. Cause: ' + JSON.stringify(exception));
}
```

### off('keyboardHeightChange')<sup>7+</sup>

off(type: 'keyboardHeightChange', callback?: Callback&lt;number&gt;): void

Disables listening for keyboard height changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'keyboardHeightChange'**, indicating the keyboard height change event.|
| callback | Callback&lt;number&gt; | No  | Callback used to return the current keyboard height.                              |

**Example**

```js
try {
    windowClass.off('keyboardHeightChange');
} catch (exception) {
    console.error('Failed to disable the listener for keyboard height changes. Cause: ' + JSON.stringify(exception));
}
```

### on('touchOutside')<sup>9+</sup>

on(type: 'touchOutside', callback: Callback&lt;void&gt;): void

Enables listening for click events outside this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type               | Mandatory| Description                                                        |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'touchOutside'**, indicating the click event outside this window.|
| callback | Callback&lt;void&gt; | Yes  | Callback used to return the click event outside this window.                              |

**Example**

```js
try {
    windowClass.on('touchOutside', () => {
        console.info('touch outside');
    });
} catch (exception) {
    console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));
}
```

### off('touchOutside')<sup>9+</sup>

off(type: 'touchOutside', callback?: Callback&lt;void&gt;): void

Disables listening for click events outside this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'touchOutside'**, indicating the click event outside this window.|
| callback | Callback&lt;number&gt; | No  | Callback used to return the click event outside this window.                              |

**Example**

```js
try {
    windowClass.off('touchOutside');
} catch (exception) {
    console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));
}
```

### on('screenshot')<sup>9+</sup>

on(type: 'screenshot', callback: Callback&lt;void&gt;): void

Subscribes to screenshot events.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type               | Mandatory| Description                                                        |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'screenshot'**, indicating the screenshot event.|
| callback | Callback&lt;void&gt; | Yes  | Callback invoked when a screenshot event occurs.                              |

**Example**

```js
try {
    windowClass.on('screenshot', () => {
        console.info('screenshot happened');
    });
} catch (exception) {
    console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));
}
```

### off('screenshot')<sup>9+</sup>

off(type: 'screenshot', callback?: Callback&lt;void&gt;): void

Unsubscribes from screenshot events.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'screenshot'**, indicating the screenshot event.|
| callback | Callback&lt;void&gt; | No  | Callback invoked when a screenshot event occurs.|

**Example**

```js
let callback = () => {
    console.info('screenshot happened');
};
try {
    windowClass.on('screenshot', callback);
} catch (exception) {
    console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));
}
try {
    windowClass.off('screenshot', callback);
    // If multiple callbacks are enabled in on(), they will all be disabled.
    windowClass.off('screenshot');
} catch (exception) {
    console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));
}
```

### on('dialogTargetTouch')<sup>9+</sup>

on(type: 'dialogTargetTouch', callback: Callback&lt;void&gt;): void

Subscribes to click events of the target window in the modal window mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'dialogTargetTouch'**, indicating the click event of the target window in the modal window mode.|
| callback | Callback&lt;void&gt;| Yes  | Callback invoked when the click event occurs in the target window of the modal window mode.|

**Example**

```js
try {
    windowClass.on('dialogTargetTouch', () => {
        console.info('touch dialog target');
    });
} catch (exception) {
    console.error('Failed to register callback. Cause: ' + JSON.stringify(exception));
}
```

### off('dialogTargetTouch')<sup>9+</sup>

off(type: 'dialogTargetTouch', callback?: Callback&lt;void&gt;): void

Unsubscribes from click events of the target window in the modal window mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'dialogTargetTouch'**, indicating the click event of the target window in the modal window mode.|
| callback | Callback&lt;void&gt;      | No  | Callback invoked when the click event occurs in the target window of the modal window mode.|

**Example**

```js
try {
    windowClass.off('dialogTargetTouch');
} catch (exception) {
    console.error('Failed to unregister callback. Cause: ' + JSON.stringify(exception));
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
| token       | [rpc.RemoteObject](js-apis-rpc.md#remoteobject) | Yes  | Token of the target window.|
| deathCallback | Callback&lt;void&gt;        | Yes  | Callback used to listen for modal window destruction events.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
import rpc from '@ohos.rpc';

class MyDeathRecipient {
    onRemoteDied() {
        console.log('server died');
    }
}
class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor) {
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

let token = new TestRemoteObject('testObject');
try {
    windowClass.bindDialogTarget(token, () => {
        console.info('Dialog Window Need Destroy.');
    }, (err) => {
        if (err.code) {
            console.error('Failed to bind dialog target. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in binding dialog target.');
    });
} catch (exception) {
    console.error('Failed to bind dialog target. Cause:' + JSON.stringify(exception));
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
| token       | [rpc.RemoteObject](js-apis-rpc.md#remoteobject) | Yes  | Token of the target window.|
| deathCallback | Callback&lt;void&gt;        | Yes  | Callback used to listen for modal window destruction events.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
import rpc from '@ohos.rpc';

class MyDeathRecipient {
    onRemoteDied() {
        console.log('server died');
    }
}
class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor) {
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

let token = new TestRemoteObject('testObject');
try {
    let promise = windowClass.bindDialogTarget(token, () => {
        console.info('Dialog Window Need Destroy.');
    });
    promise.then(()=> {
        console.info('Succeeded in binding dialog target.');
    }).catch((err)=>{
            console.error('Failed to bind dialog target. Cause:' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to bind dialog target. Cause:' + JSON.stringify(exception));
}
```

### isWindowSupportWideGamut<sup>9+</sup>

isWindowSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this window supports the wide-gamut color space. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------- | -- | -------------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** means that the wide-gamut color space is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
windowClass.isWindowSupportWideGamut((err, data) => {
    if (err.code) {
        console.error('Failed to check whether the window support WideGamut. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));
});
```

### isWindowSupportWideGamut<sup>9+</sup>

isWindowSupportWideGamut(): Promise&lt;boolean&gt;

Checks whether this window supports the wide-gamut color space. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ---------------------- | ------------------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the wide-gamut color space is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let promise = windowClass.isWindowSupportWideGamut();
promise.then((data)=> {
    console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to check whether the window support WideGamut. Cause: ' + JSON.stringify(err));
});
```

### setWindowColorSpace<sup>9+</sup>

setWindowColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

Sets a color space for this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------------------------- | -- | ----------- |
| colorSpace | [ColorSpace](#colorspace) | Yes| Color space to set.|
| callback   | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
try {
    windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT, (err) => {
        if (err.code) {
            console.error('Failed to set window colorspace. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting window colorspace.');
    });
} catch (exception) {
    console.error('Failed to set window colorspace. Cause:' + JSON.stringify(exception));
}
```

### setWindowColorSpace<sup>9+</sup>

setWindowColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

Sets a color space for this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------------------------- | -- | ------------- |
| colorSpace | [ColorSpace](#colorspace) | Yes| Color space to set.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
try {
    let promise = windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT);
    promise.then(()=> {
        console.info('Succeeded in setting window colorspace.');
    }).catch((err)=>{
        console.error('Failed to set window colorspace. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set window colorspace. Cause:' + JSON.stringify(exception));
}
```

### getWindowColorSpace<sup>9+</sup>

getWindowColorSpace(): ColorSpace

Obtains the color space of this window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ------------------------- | ------------- |
| [ColorSpace](#colorspace) | Color space obtained.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let colorSpace = windowClass.getWindowColorSpace();
```

### setWindowBackgroundColor<sup>9+</sup>

setWindowBackgroundColor(color: string): void

Sets the background color for this window. In the stage model, this API must be used after [loadContent](#loadcontent9).

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| color | string | Yes| Background color to set. The value is a hexadecimal color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let color = '#00ff33';
try {
    windowClass.setWindowBackgroundColor(color);
} catch (exception) {
    console.error('Failed to set the background color. Cause: ' + JSON.stringify(exception));
}
```

### setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

Sets the screen brightness for this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------------------------- | -- | --------------------------------- |
| brightness | number                    | Yes| Brightness to set, which ranges from 0 to 1. The value **1** indicates the brightest.|
| callback   | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                        |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let brightness = 1;
try {
    windowClass.setWindowBrightness(brightness, (err) => {
        if (err.code) {
            console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the brightness.');
    });
} catch (exception) {
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(exception));
}
```

### setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number): Promise&lt;void&gt;

Sets the screen brightness for this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------ | -- | --------------------------------- |
| brightness | number | Yes| Brightness to set, which ranges from 0 to 1. The value **1** indicates the brightest.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let brightness = 1;
try {
    let promise = windowClass.setWindowBrightness(brightness);
    promise.then(()=> {
        console.info('Succeeded in setting the brightness.');
    }).catch((err)=>{
        console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(exception));
}
```

### setWindowFocusable<sup>9+</sup>

setWindowFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window can gain focus. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------------------------- | -- | ------------------------------------------------------- |
| isFocusable | boolean                   | Yes| Whether the window can gain focus. The value **true** means that the window can gain focus, and **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                              |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isFocusable = true;
try {
    windowClass.setWindowFocusable(isFocusable, (err) => {
        if (err.code) {
            console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window to be focusable.');
    });
} catch (exception) {
    console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(exception));
}
```

### setWindowFocusable<sup>9+</sup>

setWindowFocusable(isFocusable: boolean): Promise&lt;void&gt;

Sets whether this window can gain focus. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------- | -- | -------------------------------------------------------- |
| isFocusable | boolean | Yes| Whether the window can gain focus. The value **true** means that the window can gain focus, and **false** means the opposite. |

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isFocusable = true;
try {
    let promise = windowClass.setWindowFocusable(isFocusable);
    promise.then(()=> {
        console.info('Succeeded in setting the window to be focusable.');
    }).catch((err)=>{
        console.error('Failed to set the window to be focusable. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(exception));
}
```

### setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to keep the screen always on. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------------- | ------------------------- | -- | ---------------------------------------------------- |
| isKeepScreenOn | boolean                   | Yes| Whether to keep the screen always on. The value **true** means to keep the screen always on, and **false** means the opposite. |
| callback       | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                           |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isKeepScreenOn = true;
try {
    windowClass.setWindowKeepScreenOn(isKeepScreenOn, (err) => {
        if (err.code) {
            console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the screen to be always on.');
    });
} catch (exception) {
    console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));
}
```

### setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

Sets whether to keep the screen always on. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------------- | ------- | -- | --------------------------------------------------- |
| isKeepScreenOn | boolean | Yes| Whether to keep the screen always on. The value **true** means to keep the screen always on, and **false** means the opposite.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isKeepScreenOn = true;
try {
    let promise = windowClass.setWindowKeepScreenOn(isKeepScreenOn);
    promise.then(() => {
        console.info('Succeeded in setting the screen to be always on.');
    }).catch((err)=>{
        console.info('Failed to set the screen to be always on. Cause:  ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(exception));
}
```

### setWakeUpScreen()<sup>9+</sup>

setWakeUpScreen(wakeUp: boolean): void

Wakes up the screen.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type   | Mandatory| Description                        |
| ---------------- | ------- | ---- | ---------------------------- |
| wakeUp           | boolean | Yes  | Whether to wake up the screen. The value **true** means to wake up the screen, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let wakeUp = true;
try {
    windowClass.setWakeUpScreen(wakeUp);
} catch (exception) {
    console.error('Failed to wake up the screen. Cause: ' + JSON.stringify(exception));
}
```

### setWindowPrivacyMode<sup>9+</sup>

setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is in privacy mode. This API uses an asynchronous callback to return the result. When in privacy mode, the window content cannot be captured or recorded.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**Parameters**

| Name| Type| Mandatory| Description|
| ------------- | ------------------------- | -- | ------------------------------------------------------ |
| isPrivacyMode | boolean                   | Yes| Whether the window is in privacy mode. The value **true** means that the window is in privacy mode, and **false** means the opposite. |
| callback      | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                             |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let isPrivacyMode = true;
try {
    windowClass.setWindowPrivacyMode(isPrivacyMode, (err) => {
        if (err.code) {
            console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window to privacy mode.');
    });
} catch (exception) {
    console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(exception));
}
```

### setWindowPrivacyMode<sup>9+</sup>

setWindowPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

Sets whether this window is in privacy mode. This API uses a promise to return the result. When in privacy mode, the window content cannot be captured or recorded.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**Parameters**

| Name| Type| Mandatory| Description|
| ------------- | ------- | -- | ----------------------------------------------------- |
| isPrivacyMode | boolean | Yes| Whether the window is in privacy mode. The value **true** means that the window is in privacy mode, and **false** means the opposite.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let isPrivacyMode = true;
try {
    let promise = windowClass.setWindowPrivacyMode(isPrivacyMode);
    promise.then(()=> {
        console.info('Succeeded in setting the window to privacy mode.');
    }).catch((err)=>{
        console.error('Failed to set the window to privacy mode. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(exception));
}
```

### setSnapshotSkip<sup>9+</sup>
setSnapshotSkip(isSkip: boolean): void

Sets whether to ignore this window during screen capturing or recording.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type   | Mandatory| Description                |
| ------------- | ------- | ---- | -------------------- |
| isSkip | boolean | Yes  | Whether to ignore the window. The default value is **false**.<br>The value **true** means that the window is ignored, and **false** means the opposite.<br>|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

```js
let isSkip = true;
try {
    windowClass.setSnapshotSkip(isSkip);
} catch (exception) {
    console.error('Failed to Skip. Cause: ' + JSON.stringify(exception));
};
```

### setWindowTouchable<sup>9+</sup>

setWindowTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is touchable. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------------------------- | -- | ----------------------------------------------- |
| isTouchable | boolean                   | Yes| Whether the window is touchable. The value **true** means that the window is touchable, and **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                       |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isTouchable = true;
try {
    windowClass.setWindowTouchable(isTouchable, (err) => {
        if (err.code) {
            console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the window to be touchable.');
    });
} catch (exception) {
    console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(exception));
}
```

### setWindowTouchable<sup>9+</sup>

setWindowTouchable(isTouchable: boolean): Promise&lt;void&gt;

Sets whether this window is touchable. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------- | -- | ----------------------------------------------- |
| isTouchable | boolean | Yes| Whether the window is touchable. The value **true** means that the window is touchable, and **false** means the opposite.|

**Return value**

| Type| Description|
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isTouchable = true;
try {
    let promise = windowClass.setWindowTouchable(isTouchable);
    promise.then(()=> {
        console.info('Succeeded in setting the window to be touchable.');
    }).catch((err)=>{
        console.error('Failed to set the window to be touchable. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(exception));
}
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is forbidden to move in split-screen mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                     | Mandatory| Description                |
| ----------- | ------------------------- | ---- | -------------------- |
| isForbidSplitMove | boolean                   | Yes  | Whether the window is forbidden to move in split-screen mode. The value **true** means the window is forbidden to move in split-screen mode, and **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isForbidSplitMove = true;
try {
    windowClass.setForbidSplitMove(isForbidSplitMove, (err) => {
        if (err.code) {
            console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in forbidding window moving in split screen mode.');
    });
} catch (exception) {
    console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(exception));
}
```

### setForbidSplitMove<sup>9+</sup>

setForbidSplitMove(isForbidSplitMove: boolean): Promise&lt;void&gt;

Sets whether this window is forbidden to move in split-screen mode. This API uses a promise to return the result.

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

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```js
let isForbidSplitMove = true;
try {
    let promise = windowClass.setForbidSplitMove(isForbidSplitMove);
    promise.then(()=> {
        console.info('Succeeded in forbidding window moving in split screen mode.');
    }).catch((err)=>{
        console.error('Failed to forbid window moving in split screen mode. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to forbid window moving in split screen mode. Cause:' + JSON.stringify(exception));
}
```

### snapshot<sup>9+</sup>

snapshot(): Promise&lt;image.PixelMap&gt;

Captures this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                                        | Description                                   |
| ----------------------------------------------------------- | --------------------------------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise used to return the window screenshot. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```js
let promise = windowClass.snapshot();
promise.then((pixelMap)=> {
    console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
    pixelMap.release(); // Release the memory in time after the PixelMap is used.
}).catch((err)=>{
    console.error('Failed to snapshot window. Cause:' + JSON.stringify(err));
});
```

### opacity<sup>9+</sup>

opacity(opacity: number): void

Sets the opacity for this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type   | Mandatory | Description                                       |
| ------- | ------ | --------- | ------------------------------------------------- |
| opacity | number | Yes       | Opacity to set. The value ranges from 0.0 to 1.0. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
try {
    windowClass.opacity(0.5);
} catch (exception) {
    console.error('Failed to opacity. Cause: ' + JSON.stringify(exception));
}
```

### scale<sup>9+</sup>

scale(scaleOptions: ScaleOptions): void

Sets the scale parameters for this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name         | Type                           | Mandatory | Description              |
| ------------ | ------------------------------ | --------- | ------------------------ |
| scaleOptions | [ScaleOptions](#scaleoptions9) | Yes       | Scale parameters to set. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
let obj : window.ScaleOptions = {
  x : 2.0,
  y : 1.0,
  pivotX : 0.5,
  pivotY : 0.5
};
try {
    windowClass.scale(obj);
} catch (exception) {
    console.error('Failed to scale. Cause: ' + JSON.stringify(exception));
}
```

### rotate<sup>9+</sup>

rotate(rotateOptions: RotateOptions): void

Sets the rotation parameters for this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type                             | Mandatory | Description                 |
| ------------- | -------------------------------- | --------- | --------------------------- |
| rotateOptions | [RotateOptions](#rotateoptions9) | Yes       | Rotation parameters to set. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
let obj : window.RotateOptions = {
  x : 1.0,
  y : 1.0,
  z : 45.0,
  pivotX : 0.5,
  pivotY : 0.5
};
try {
    windowClass.rotate(obj);
} catch (exception) {
    console.error('Failed to rotate. Cause: ' + JSON.stringify(exception));
}
```

### translate<sup>9+</sup>

translate(translateOptions: TranslateOptions): void

Sets the translation parameters for this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name             | Type                                   | Mandatory | Description                    |
| ---------------- | -------------------------------------- | --------- | ------------------------------ |
| translateOptions | [TranslateOptions](#translateoptions9) | Yes       | Translation parameters to set. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
let obj : window.TranslateOptions = {
  x : 100.0,
  y : 0.0,
  z : 0.0
};
try {
    windowClass.translate(obj);
} catch (exception) {
    console.error('Failed to translate. Cause: ' + JSON.stringify(exception));
}
```

###  getTransitionController<sup>9+</sup>

 getTransitionController(): TransitionController

Obtains the transition animation controller.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                           | Description                      |
| ---------------------------------------------- | -------------------------------- |
| [TransitionController](#transitioncontroller9) | Transition animation controller. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
let controller = windowClass.getTransitionController(); // Obtain the transition animation controller.
controller.animationForHidden = (context : window.TransitionContext) => {
	let toWindow = context.toWindow;
 	animateTo({
    	duration: 1000, // Animation duration.
        tempo: 0.5, // Playback speed.
        curve: Curve.EaseInOut, // Animation curve.
        delay: 0, // Animation delay.
        iterations: 1, // Number of playback times.
        playMode: PlayMode.Normal // Animation playback mode.
        onFinish: ()=> {
            context.completeTransition(true)
        }    
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        };
        toWindow.translate(obj); // Set the transition animation.
        console.info('toWindow translate end');
      }
    );
    console.info('complete transition end');
};
windowClass.hideWithAnimation((err, data) => {
    if (err.code) {
        console.error('Failed to show the window with animation. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window with animation. Data: ' + JSON.stringify(data));
});
```

### setBlur<sup>9+</sup>

setBlur(radius: number): void

Blurs this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| ------ | ------ | --------- | ------------------------------------------------------------ |
| radius | number | Yes       | Radius of the blur. The value is greater than or equal to 0. The value **0** means that the blur is disabled for the window. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
try {
    windowClass.setBlur(4.0);
} catch (exception) {
    console.error('Failed to set blur. Cause: ' + JSON.stringify(exception));
}
```

### setBackdropBlur<sup>9+</sup>

setBackdropBlur(radius: number): void

Blurs the background of this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| ------ | ------ | --------- | ------------------------------------------------------------ |
| radius | number | Yes       | Radius of the blur. The value is greater than or equal to 0. The value **0** means that the blur is disabled for the background of the window. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
try {
    windowClass.setBackdropBlur(4.0);
} catch (exception) {
    console.error('Failed to set backdrop blur. Cause: ' + JSON.stringify(exception));
}
```

### setBackdropBlurStyle<sup>9+</sup>

setBackdropBlurStyle(blurStyle: BlurStyle): void

Sets the blur style for the background of this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                     | Mandatory | Description                                         |
| --------- | ------------------------ | --------- | --------------------------------------------------- |
| blurStyle | [BlurStyle](#blurstyle9) | Yes       | Blur style to set for the background of the window. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
try {
    windowClass.setBackdropBlurStyle(window.BlurStyle.THIN);
} catch (exception) {
    console.error('Failed to set backdrop blur style. Cause: ' + JSON.stringify(exception));
}

```

### setShadow<sup>9+</sup>

setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void

Sets the shadow for the window borders.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type   | Mandatory | Description                                                  |
| ------- | ------ | --------- | ------------------------------------------------------------ |
| radius  | number | Yes       | Radius of the shadow. The value is greater than or equal to 0. The value **0** means that the shadow is disabled for the window borders. |
| color   | string | No        | Color of the shadow. The value is a hexadecimal color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**. |
| offsetX | number | No        | Offset of the shadow along the x-axis, in pixels.            |
| offsetY | number | No        | Offset of the shadow along the y-axis, in pixels.            |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
try {
    windowClass.setShadow(4.0, '#FF00FF00', 2, 3);
} catch (exception) {
    console.error('Failed to set shadow. Cause: ' + JSON.stringify(exception));
}

```

### setCornerRadius<sup>9+</sup>

setCornerRadius(cornerRadius: number): void

Sets the radius of the rounded corners for this window.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| ------ | ------ | --------- | ------------------------------------------------------------ |
| radius | number | Yes       | Radius of the rounded corners. The value is greater than or equal to 0. The value **0** means that the window does not use rounded corners. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**

```js
try {
    windowClass.setCornerRadius(4.0);
} catch (exception) {
    console.error('Failed to set corner radius. Cause: ' + JSON.stringify(exception));
}

```

### show<sup>(deprecated)</sup>

show(callback: AsyncCallback&lt;void&gt;): void

Shows this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [showWindow()](#showwindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                         |
| -------- | ------------------------- | --------- | ----------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Example**

```js
windowClass.show((err) => {
    if (err.code) {
        console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in showing the window.');
});

```

### show<sup>(deprecated)</sup>

show(): Promise&lt;void&gt;

Shows this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [showWindow()](#showwindow9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.show();
promise.then(()=> {
    console.info('Succeeded in showing the window.');
}).catch((err)=>{
    console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
});

```

### destroy<sup>(deprecated)</sup>

destroy(callback: AsyncCallback&lt;void&gt;): void

Destroys this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [destroyWindow()](#destroywindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                         |
| -------- | ------------------------- | --------- | ----------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Example**

```js
windowClass.destroy((err) => {
    if (err.code) {
        console.error('Failed to destroy the window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in destroying the window.');
});

```

### destroy<sup>(deprecated)</sup>

destroy(): Promise&lt;void&gt;

Destroys this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [destroyWindow()](#destroywindow9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.destroy();
promise.then(()=> {
    console.info('Succeeded in destroying the window.');
}).catch((err)=>{
    console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
});

```

### moveTo<sup>(deprecated)</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

Moves this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [moveWindowTo()](#movewindowto9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| x        | number                    | Yes       | Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. |
| y        | number                    | Yes       | Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
windowClass.moveTo(300, 300, (err)=>{
    if (err.code) {
        console.error('Failed to move the window. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in moving the window.');
});

```

### moveTo<sup>(deprecated)</sup>

moveTo(x: number, y: number): Promise&lt;void&gt;

Moves this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [moveWindowTo()](#movewindowto9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type   | Mandatory | Description                                                  |
| ---- | ------ | --------- | ------------------------------------------------------------ |
| x    | number | Yes       | Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. |
| y    | number | Yes       | Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.moveTo(300, 300);
promise.then(()=> {
    console.info('Succeeded in moving the window.');
}).catch((err)=>{
    console.error('Failed to move the window. Cause: ' + JSON.stringify(err));
});

```

### resetSize<sup>(deprecated)</sup>

resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

Changes the size of this window. This API uses an asynchronous callback to return the result.

The main window and subwindow have the following size limits: [320, 2560] in width and [240, 2560] in height, both in units of vp.

The system window has the following size limits: [0, 2560] in width and [0, 2560] in height, both in units of vp.

The new width and height you set must meet the limits.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [resize()](#resize9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                         |
| -------- | ------------------------- | --------- | ----------------------------------- |
| width    | number                    | Yes       | New width of the window, in px.     |
| height   | number                    | Yes       | New height of the window, in px.    |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Example**

```js
windowClass.resetSize(500, 1000, (err) => {
    if (err.code) {
        console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in changing the window size.');
});

```

### resetSize<sup>(deprecated)</sup>

resetSize(width: number, height: number): Promise&lt;void&gt;

Changes the size of this window. This API uses a promise to return the result.

The main window and subwindow have the following size limits: [320, 2560] in width and [240, 2560] in height, both in units of vp.

The system window has the following size limits: [0, 2560] in width and [0, 2560] in height, both in units of vp.

The new width and height you set must meet the limits.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [resize()](#resize9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type   | Mandatory | Description                      |
| ------ | ------ | --------- | -------------------------------- |
| width  | number | Yes       | New width of the window, in px.  |
| height | number | Yes       | New height of the window, in px. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.resetSize(500, 1000);
promise.then(()=> {
    console.info('Succeeded in changing the window size.');
}).catch((err)=>{
    console.error('Failed to change the window size. Cause: ' + JSON.stringify(err));
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

| Name     | Type                       | Mandatory | Description                         |
| -------- | -------------------------- | --------- | ----------------------------------- |
| type     | [WindowType](#windowtype7) | Yes       | Window type.                        |
| callback | AsyncCallback&lt;void&gt;  | Yes       | Callback used to return the result. |

**Example**

```js
let type = window.WindowType.TYPE_APP;
windowClass.setWindowType(type, (err) => {
  if (err.code) {
      console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
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

| Name | Type                       | Mandatory | Description  |
| ---- | -------------------------- | --------- | ------------ |
| type | [WindowType](#windowtype7) | Yes       | Window type. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let type = window.WindowType.TYPE_APP;
let promise = windowClass.setWindowType(type);
promise.then(()=> {
    console.info('Succeeded in setting the window type.');
}).catch((err)=>{
    console.error('Failed to set the window type. Cause: ' + JSON.stringify(err));
});

```

### getProperties<sup>(deprecated)</sup>

getProperties(callback: AsyncCallback&lt;WindowProperties&gt;): void

Obtains the properties of this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getWindowProperties()](#getwindowproperties9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                                       | Mandatory | Description                                    |
| -------- | ---------------------------------------------------------- | --------- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[WindowProperties](#windowproperties)&gt; | Yes       | Callback used to return the window properties. |

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

### getProperties<sup>(deprecated)</sup>

getProperties(): Promise&lt;WindowProperties&gt;

Obtains the properties of this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getWindowProperties()](#getwindowproperties9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                                 | Description                                   |
| ---------------------------------------------------- | --------------------------------------------- |
| Promise&lt;[WindowProperties](#windowproperties)&gt; | Promise used to return the window properties. |

**Example**

```js
let promise = windowClass.getProperties();
promise.then((data)=> {
    console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the window properties. Cause: ' + JSON.stringify(err));
});

```

### getAvoidArea<sup>(deprecated)</sup>

getAvoidArea(type: [AvoidAreaType](#avoidareatype7), callback: AsyncCallback&lt;[AvoidArea](#avoidarea7)&gt;): void

Obtains the area where this window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getWindowAvoidArea()](#getwindowavoidarea9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                          | Mandatory | Description                                                  |
| -------- | --------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [AvoidAreaType](#avoidareatype7)              | Yes       | Type of the area. **TYPE_SYSTEM** indicates the default area of the system. **TYPE_CUTOUT** indicates the notch. **TYPE_SYSTEM_GESTURE** indicates the gesture area. **TYPE_KEYBOARD** indicates the soft keyboard area. |
| callback | AsyncCallback&lt;[AvoidArea](#avoidarea7)&gt; | Yes       | Callback used to return the area.                            |

**Example**

```js
let type = window.AvoidAreaType.TYPE_SYSTEM;
windowClass.getAvoidArea(type, (err, data) => {
    if (err.code) {
        console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
});

```

### getAvoidArea<sup>(deprecated)</sup>

getAvoidArea(type: [AvoidAreaType](#avoidareatype7)): Promise&lt;[AvoidArea](#avoidarea7)&gt;

Obtains the area where this window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getWindowAvoidArea()](#getwindowavoidarea9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                             | Mandatory | Description                                                  |
| ---- | -------------------------------- | --------- | ------------------------------------------------------------ |
| type | [AvoidAreaType](#avoidareatype7) | Yes       | Type of the area. **TYPE_SYSTEM** indicates the default area of the system. **TYPE_CUTOUT** indicates the notch. **TYPE_SYSTEM_GESTURE** indicates the gesture area. **TYPE_KEYBOARD** indicates the soft keyboard area. |

**Return value**

| Type                                    | Description                      |
| --------------------------------------- | -------------------------------- |
| Promise&lt;[AvoidArea](#avoidarea7)&gt; | Promise used to return the area. |

**Example**

```js
let type = window.AvoidAreaType.TYPE_SYSTEM;
let promise = windowClass.getAvoidArea(type);
promise.then((data)=> {
    console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to obtain the area. Cause:' + JSON.stringify(err));
});

```

### setFullScreen<sup>(deprecated)</sup>

setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the full-screen mode for this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name         | Type                      | Mandatory | Description                                                  |
| ------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isFullScreen | boolean                   | Yes       | Whether to enable the full-screen mode, in which the status bar and navigation bar are hidden. The value **true** means to enable the full-screen mode, and **false** means the opposite. |
| callback     | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let isFullScreen = true;
windowClass.setFullScreen(isFullScreen, (err) => {
    if (err.code) {
        console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in enabling the full-screen mode.');
});

```

### setFullScreen<sup>(deprecated)</sup>

setFullScreen(isFullScreen: boolean): Promise&lt;void&gt;

Sets whether to enable the full-screen mode for this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name         | Type    | Mandatory | Description                                                  |
| ------------ | ------- | --------- | ------------------------------------------------------------ |
| isFullScreen | boolean | Yes       | Whether to enable the full-screen mode, in which the status bar and navigation bar are hidden. The value **true** means to enable the full-screen mode, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let isFullScreen = true;
let promise = windowClass.setFullScreen(isFullScreen);
promise.then(()=> {
    console.info('Succeeded in enabling the full-screen mode.');
}).catch((err)=>{
    console.error('Failed to enable the full-screen mode. Cause: ' + JSON.stringify(err));
});

```

### setLayoutFullScreen<sup>(deprecated)</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the full-screen mode for the window layout. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name               | Type                      | Mandatory | Description                                                  |
| ------------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | Yes       | Whether to enable the full-screen mode for the window layout, in which the status bar and navigation bar are displayed. The value **true** means to enable the full-screen mode for the window layout, and **false** means the opposite. |
| callback           | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let isLayoutFullScreen= true;
windowClass.setLayoutFullScreen(isLayoutFullScreen, (err) => {
    if (err.code) {
        console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window layout to full-screen mode.');
});

```

### setLayoutFullScreen<sup>(deprecated)</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

Sets whether to enable the full-screen mode for the window layout. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name               | Type    | Mandatory | Description                                                  |
| ------------------ | ------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean | Yes       | Whether to enable the full-screen mode for the window layout, in which the status bar and navigation bar are displayed. The value **true** means to enable the full-screen mode for the window layout, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let isLayoutFullScreen = true;
let promise = windowClass.setLayoutFullScreen(isLayoutFullScreen);
promise.then(()=> {
    console.info('Succeeded in setting the window layout to full-screen mode.');
}).catch((err)=>{
    console.error('Failed to set the window layout to full-screen mode. Cause:' + JSON.stringify(err));
});

```

### setSystemBarEnable<sup>(deprecated)</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

Sets whether to display the status bar and navigation bar in this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                                                  |
| -------- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names    | Array<'status'\|'navigation'> | Yes       | Whether to display the status bar and navigation bar.<br>For example, to display the status bar and navigation bar, set this parameter to **['status', 'navigation']**. By default, they are not displayed. |
| callback | AsyncCallback&lt;void&gt;     | Yes       | Callback used to return the result.                          |

**Example**

```js
// In this example, the status bar and navigation bar are not displayed.
let names = [];
windowClass.setSystemBarEnable(names, (err) => {
    if (err.code) {
        console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the system bar to be invisible.');
});

```

### setSystemBarEnable<sup>(deprecated)</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

Sets whether to display the status bar and navigation bar in this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                          | Mandatory | Description                                                  |
| ----- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names | Array<'status'\|'navigation'> | Yes       | Whether to display the status bar and navigation bar.<br>For example, to display the status bar and navigation bar, set this parameter to **['status', 'navigation']**. By default, they are not displayed. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
// In this example, the status bar and navigation bar are not displayed.
let names = [];
let promise = windowClass.setSystemBarEnable(names);
promise.then(()=> {
    console.info('Succeeded in setting the system bar to be invisible.');
}).catch((err)=>{
    console.error('Failed to set the system bar to be invisible. Cause:' + JSON.stringify(err));
});

```

### setSystemBarProperties<sup>(deprecated)</sup>

setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

Sets the properties of the status bar and navigation bar in this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarProperties()](#setwindowsystembarproperties9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name                | Type                                        | Mandatory | Description                                      |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------ |
| SystemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the status bar and navigation bar. |
| callback            | AsyncCallback&lt;void&gt;                   | Yes       | Callback used to return the result.              |

**Example**

```js
let SystemBarProperties={
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    // The following properties are supported since API version 8.
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
windowClass.setSystemBarProperties(SystemBarProperties, (err) => {
    if (err.code) {
        console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the system bar properties.');
});

```

### setSystemBarProperties<sup>(deprecated)</sup>

setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

Sets the properties of the status bar and navigation bar in this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarProperties()](#setwindowsystembarproperties9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name                | Type                                        | Mandatory | Description                                      |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------ |
| SystemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the status bar and navigation bar. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let SystemBarProperties={
    statusBarColor: '#ff00ff',
    navigationBarColor: '#00ff00',
    // The following properties are supported since API version 8.
    statusBarContentColor:'#ffffff',
    navigationBarContentColor:'#00ffff'
};
let promise = windowClass.setSystemBarProperties(SystemBarProperties);
promise.then(()=> {
    console.info('Succeeded in setting the system bar properties.');
}).catch((err)=>{
    console.error('Failed to set the system bar properties. Cause: ' + JSON.stringify(err));
});

```

### loadContent<sup>(deprecated)</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page to this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setUIContent()](#setuicontent9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                             |
| -------- | ------------------------- | --------- | ------------------------------------------------------- |
| path     | string                    | Yes       | Path of the page from which the content will be loaded. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                     |

**Example**

```js
windowClass.loadContent('pages/page2/page2', (err) => {
   if (err.code) {
         console.error('Failed to load the content. Cause:' + JSON.stringify(err));
         return;
   }
  console.info('Succeeded in loading the content.');
});

```

### loadContent<sup>(deprecated)</sup>

loadContent(path: string): Promise&lt;void&gt;

Loads content from a page to this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setUIContent()](#setuicontent9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type   | Mandatory | Description                                             |
| ---- | ------ | --------- | ------------------------------------------------------- |
| path | string | Yes       | Path of the page from which the content will be loaded. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.loadContent('pages/page2/page2');
promise.then(()=> {
    console.info('Succeeded in loading the content.');
}).catch((err)=>{
    console.error('Failed to load the content. Cause: ' + JSON.stringify(err));
});

```

### isShowing<sup>(deprecated)</sup>

isShowing(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this window is displayed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isWindowShowing()](#iswindowshowing9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                         | Mandatory | Description                                                  |
| -------- | ---------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes       | Callback used to return the result. The value **true** means that the window is displayed, and **false** means the opposite. |

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

### isShowing<sup>(deprecated)</sup>

isShowing(): Promise&lt;boolean&gt;

Checks whether this window is displayed. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isWindowShowing()](#iswindowshowing9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the window is displayed, and **false** means the opposite. |

**Example**

```js
let promise = windowClass.isShowing();
promise.then((data)=> {
    console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to check whether the window is showing. Cause: ' + JSON.stringify(err));
});

```

### on('systemAvoidAreaChange')<sup>(deprecated)</sup>

on(type: 'systemAvoidAreaChange', callback: Callback&lt;AvoidArea&gt;): void

Enables listening for changes to the area where the window cannot be displayed.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [on('avoidAreaChange')](#onavoidareachange9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                     | Mandatory | Description                                                  |
| -------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                   | Yes       | Event type. The value is fixed at **'systemAvoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed. |
| callback | Callback&lt;[AvoidArea](#avoidarea7)&gt; | Yes       | Callback used to return the area.                            |

**Example**

```js
windowClass.on('systemAvoidAreaChange', (data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. Data: ' + JSON.stringify(data));
});

```

### off('systemAvoidAreaChange')<sup>(deprecated)</sup>

off(type: 'systemAvoidAreaChange', callback?: Callback&lt;AvoidArea&gt;): void

Disables listening for changes to the area where the window cannot be displayed.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [off('avoidAreaChange')](#offavoidareachange9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                     | Mandatory | Description                                                  |
| -------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                   | Yes       | Event type. The value is fixed at **'systemAvoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed. |
| callback | Callback&lt;[AvoidArea](#avoidarea7)&gt; | No        | Callback used to return the area.                            |

**Example**

```js
windowClass.off('systemAvoidAreaChange');

```

### isSupportWideGamut<sup>(deprecated)</sup>

isSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this window supports the wide-gamut color space. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [isWindowSupportWideGamut()](#iswindowsupportwidegamut9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                         | Mandatory | Description                                                  |
| -------- | ---------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes       | Callback used to return the result. The value **true** means that the wide-gamut color space is supported, and **false** means the opposite. |

**Example**

```js
windowClass.isSupportWideGamut((err, data) => {
    if (err.code) {
        console.error('Failed to check whether the window support WideGamut. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));
});

```

### isSupportWideGamut<sup>(deprecated)</sup>

isSupportWideGamut(): Promise&lt;boolean&gt;

Checks whether this window supports the wide-gamut color space. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [isWindowSupportWideGamut()](#iswindowsupportwidegamut9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the wide-gamut color space is supported, and **false** means the opposite. |

**Example**

```js
let promise = windowClass.isSupportWideGamut();
promise.then((data)=> {
    console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to check whether the window support WideGamut. Cause: ' + JSON.stringify(err));
});

```

### setColorSpace<sup>(deprecated)</sup>

setColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

Sets a color space for this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setWindowColorSpace()](#setwindowcolorspace9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type                      | Mandatory | Description                         |
| ---------- | ------------------------- | --------- | ----------------------------------- |
| colorSpace | [ColorSpace](#colorspace) | Yes       | Color space to set.                 |
| callback   | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Example**

```js
windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT, (err) => {
    if (err.code) {
        console.error('Failed to set window colorspace. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting window colorspace.');
});

```

### setColorSpace<sup>(deprecated)</sup>

setColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

Sets a color space for this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setWindowColorSpace()](#setwindowcolorspace9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type                      | Mandatory | Description         |
| ---------- | ------------------------- | --------- | ------------------- |
| colorSpace | [ColorSpace](#colorspace) | Yes       | Color space to set. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT);
promise.then(()=> {
    console.info('Succeeded in setting window colorspace.');
}).catch((err)=>{
    console.error('Failed to set window colorspace. Cause: ' + JSON.stringify(err));
});

```

### getColorSpace<sup>(deprecated)</sup>

getColorSpace(callback: AsyncCallback&lt;ColorSpace&gt;): void

Obtains the color space of this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getWindowColorSpace()](#getwindowcolorspace9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                           | Mandatory | Description                                                  |
| -------- | ---------------------------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[ColorSpace](#colorspace)&gt; | Yes       | Callback used to return the result. When the color space is obtained successfully, **err** is **undefined**, and **data** is the current color space. |

**Example**

```js
windowClass.getColorSpace((err, data) => {
    if (err.code) {
        console.error('Failed to get window colorspace. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in getting window colorspace. Cause:' + JSON.stringify(data));
});

```

### getColorSpace<sup>(deprecated)</sup>

getColorSpace(): Promise&lt;ColorSpace&gt;

Obtains the color space of this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getWindowColorSpace()](#getwindowcolorspace9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                     | Description                                     |
| ---------------------------------------- | ----------------------------------------------- |
| Promise&lt;[ColorSpace](#colorspace)&gt; | Promise used to return the current color space. |

**Example**

```js
let promise = windowClass.getColorSpace();
promise.then((data)=> {
    console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data));
}).catch((err)=>{
    console.error('Failed to get window colorspace. Cause: ' + JSON.stringify(err));
});

```

### setBackgroundColor<sup>(deprecated)</sup>

setBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void

Sets the background color for this window. This API uses an asynchronous callback to return the result. In the stage model, this API must be used after [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9).

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBackgroundColor()](#setwindowbackgroundcolor9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| color    | string                    | Yes       | Background color to set. The value is a hexadecimal color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let color = '#00ff33';
windowClass.setBackgroundColor(color, (err) => {
    if (err.code) {
        console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the background color.');
});

```

### setBackgroundColor<sup>(deprecated)</sup>

setBackgroundColor(color: string): Promise&lt;void&gt;

Sets the background color for this window. This API uses a promise to return the result. In the stage model, this API must be used after [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9).

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBackgroundColor()](#setwindowbackgroundcolor9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type   | Mandatory | Description                                                  |
| ----- | ------ | --------- | ------------------------------------------------------------ |
| color | string | Yes       | Background color to set. The value is a hexadecimal color code and is case insensitive, for example, **#00FF00** or **#FF00FF00**. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let color = '#00ff33';
let promise = windowClass.setBackgroundColor(color);
promise.then(()=> {
    console.info('Succeeded in setting the background color.');
}).catch((err)=>{
    console.error('Failed to set the background color. Cause: ' + JSON.stringify(err));
});

```

### setBrightness<sup>(deprecated)</sup>

setBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

Sets the screen brightness for this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBrightness()](#setwindowbrightness9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type                      | Mandatory | Description                                                  |
| ---------- | ------------------------- | --------- | ------------------------------------------------------------ |
| brightness | number                    | Yes       | Brightness to set, which ranges from 0 to 1. The value **1** indicates the brightest. |
| callback   | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let brightness = 1;
windowClass.setBrightness(brightness, (err) => {
    if (err.code) {
        console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the brightness.');
});

```

### setBrightness<sup>(deprecated)</sup>

setBrightness(brightness: number): Promise&lt;void&gt;

Sets the screen brightness for this window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBrightness()](#setwindowbrightness9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type   | Mandatory | Description                                                  |
| ---------- | ------ | --------- | ------------------------------------------------------------ |
| brightness | number | Yes       | Brightness to set, which ranges from 0 to 1. The value **1** indicates the brightest. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let brightness = 1;
let promise = windowClass.setBrightness(brightness);
promise.then(()=> {
    console.info('Succeeded in setting the brightness.');
}).catch((err)=>{
    console.error('Failed to set the brightness. Cause: ' + JSON.stringify(err));
});

```

### setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number, callback: AsyncCallback&lt;void&gt;): void

Sets the dimness of the window that is not on top. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API cannot be used. This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name           | Type                      | Mandatory | Description                                                  |
| -------------- | ------------------------- | --------- | ------------------------------------------------------------ |
| dimBehindValue | number                    | Yes       | Dimness of the window to set. The value ranges from 0 to 1. The value **1** indicates the dimmest. |
| callback       | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
windowClass.setDimBehind(0.5, (err) => {
    if (err.code) {
        console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the dimness.');
});

```

### setDimBehind<sup>(deprecated)</sup>

setDimBehind(dimBehindValue: number): Promise&lt;void&gt;

Sets the dimness of the window that is not on top. This API uses a promise to return the result.

> **NOTE**
>
> This API cannot be used. This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name           | Type   | Mandatory | Description                                                  |
| -------------- | ------ | --------- | ------------------------------------------------------------ |
| dimBehindValue | number | Yes       | Dimness of the window to set. The value ranges from 0 to 1. The value **1** indicates the dimmest. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.setDimBehind(0.5);
promise.then(()=> {
    console.info('Succeeded in setting the dimness.');
}).catch((err)=>{
    console.error('Failed to set the dimness. Cause: ' + JSON.stringify(err));
});

```

### setFocusable<sup>(deprecated)</sup>

setFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window can gain focus. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowFocusable()](#setwindowfocusable9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type                      | Mandatory | Description                                                  |
| ----------- | ------------------------- | --------- | ------------------------------------------------------------ |
| isFocusable | boolean                   | Yes       | Whether the window can gain focus. The value **true** means that the window can gain focus, and **false** means the opposite. |
| callback    | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let isFocusable= true;
windowClass.setFocusable(isFocusable, (err) => {
    if (err.code) {
        console.error('Failed to set the window to be focusable. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to be focusable.');
});

```

### setFocusable<sup>(deprecated)</sup>

setFocusable(isFocusable: boolean): Promise&lt;void&gt;

Sets whether this window can gain focus. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowFocusable()](#setwindowfocusable9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type    | Mandatory | Description                                                  |
| ----------- | ------- | --------- | ------------------------------------------------------------ |
| isFocusable | boolean | Yes       | Whether the window can gain focus. The value **true** means that the window can gain focus, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let isFocusable= true;
let promise = windowClass.setFocusable(isFocusable);
promise.then(()=> {
    console.info('Succeeded in setting the window to be focusable.');
}).catch((err)=>{
    console.error('Failed to set the window to be focusable. Cause: ' + JSON.stringify(err));
});

```

### setKeepScreenOn<sup>(deprecated)</sup>

setKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to keep the screen always on. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowKeepScreenOn()](#setwindowkeepscreenon9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name           | Type                      | Mandatory | Description                                                  |
| -------------- | ------------------------- | --------- | ------------------------------------------------------------ |
| isKeepScreenOn | boolean                   | Yes       | Whether to keep the screen always on. The value **true** means to keep the screen always on, and **false** means the opposite. |
| callback       | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let isKeepScreenOn = true;
windowClass.setKeepScreenOn(isKeepScreenOn, (err) => {
    if (err.code) {
        console.error('Failed to set the screen to be always on. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the screen to be always on.');
});

```

### setKeepScreenOn<sup>(deprecated)</sup>

setKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

Sets whether to keep the screen always on. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowKeepScreenOn()](#setwindowkeepscreenon9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name           | Type    | Mandatory | Description                                                  |
| -------------- | ------- | --------- | ------------------------------------------------------------ |
| isKeepScreenOn | boolean | Yes       | Whether to keep the screen always on. The value **true** means to keep the screen always on, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let isKeepScreenOn = true;
let promise = windowClass.setKeepScreenOn(isKeepScreenOn);
promise.then(() => {
    console.info('Succeeded in setting the screen to be always on.');
}).catch((err)=>{
    console.info('Failed to set the screen to be always on. Cause:  ' + JSON.stringify(err));
});

```

### setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the area outside the subwindow is touchable. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API cannot be used. This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                      | Mandatory | Description                                                  |
| --------- | ------------------------- | --------- | ------------------------------------------------------------ |
| touchable | boolean                   | Yes       | Whether the area outside the subwindow is touchable. The value **true** means the area outside the subwindow is touchable, and **false** means the opposite. |
| callback  | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
windowClass.setOutsideTouchable(true, (err) => {
    if (err.code) {
        console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the area to be touchable.');
});

```

### setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean): Promise&lt;void&gt;

Sets whether the area outside the subwindow is touchable. This API uses a promise to return the result.

> **NOTE**
>
> This API cannot be used. This API is supported since API version 7 and deprecated since API version 9.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type    | Mandatory | Description                                                  |
| --------- | ------- | --------- | ------------------------------------------------------------ |
| touchable | boolean | Yes       | Whether the area outside the subwindow is touchable. The value **true** means the area outside the subwindow is touchable, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let promise = windowClass.setOutsideTouchable(true);
promise.then(()=> {
    console.info('Succeeded in setting the area to be touchable.');
}).catch((err)=>{
    console.error('Failed to set the area to be touchable. Cause: ' + JSON.stringify(err));
});

```

### setPrivacyMode<sup>(deprecated)</sup>

setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is in privacy mode. This API uses an asynchronous callback to return the result. When in privacy mode, the window content cannot be captured or recorded.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowPrivacyMode()](#setwindowprivacymode9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type                      | Mandatory | Description                                                  |
| ------------- | ------------------------- | --------- | ------------------------------------------------------------ |
| isPrivacyMode | boolean                   | Yes       | Whether the window is in privacy mode. The value **true** means that the window is in privacy mode, and **false** means the opposite. |
| callback      | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let isPrivacyMode = true;
windowClass.setPrivacyMode(isPrivacyMode, (err) => {
    if (err.code) {
        console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to privacy mode.');
});

```

### setPrivacyMode<sup>(deprecated)</sup>

setPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

Sets whether this window is in privacy mode. This API uses a promise to return the result. When in privacy mode, the window content cannot be captured or recorded.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowPrivacyMode()](#setwindowprivacymode9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name          | Type    | Mandatory | Description                                                  |
| ------------- | ------- | --------- | ------------------------------------------------------------ |
| isPrivacyMode | boolean | Yes       | Whether the window is in privacy mode. The value **true** means that the window is in privacy mode, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let isPrivacyMode = true;
let promise = windowClass.setPrivacyMode(isPrivacyMode);
promise.then(()=> {
    console.info('Succeeded in setting the window to privacy mode.');
}).catch((err)=>{
    console.error('Failed to set the window to privacy mode. Cause: ' + JSON.stringify(err));
});

```

### setTouchable<sup>(deprecated)</sup>

setTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is touchable. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowTouchable()](#setwindowtouchable9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type                      | Mandatory | Description                                                  |
| ----------- | ------------------------- | --------- | ------------------------------------------------------------ |
| isTouchable | boolean                   | Yes       | Whether the window is touchable. The value **true** means that the window is touchable, and **false** means the opposite. |
| callback    | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```js
let isTouchable = true;
windowClass.setTouchable(isTouchable, (err) => {
    if (err.code) {
        console.error('Failed to set the window to be touchable. Cause:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in setting the window to be touchable.');
});

```

### setTouchable<sup>(deprecated)</sup>

setTouchable(isTouchable: boolean): Promise&lt;void&gt;

Sets whether this window is touchable. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowTouchable()](#setwindowtouchable9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type    | Mandatory | Description                                                  |
| ----------- | ------- | --------- | ------------------------------------------------------------ |
| isTouchable | boolean | Yes       | Whether the window is touchable. The value **true** means that the window is touchable, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```js
let isTouchable = true;
let promise = windowClass.setTouchable(isTouchable);
promise.then(()=> {
    console.info('Succeeded in setting the window to be touchable.');
}).catch((err)=>{
    console.error('Failed to set the window to be touchable. Cause: ' + JSON.stringify(err));
});

```

## WindowStageEventType<sup>9+</sup>

Describes the lifecycle of a window stage.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name       | Value | Description                                    |
| ---------- | ----- | ---------------------------------------------- |
| FOREGROUND | 1     | The window stage is running in the foreground. |
| ACTIVE     | 2     | The window stage gains focus.                  |
| INACTIVE   | 3     | The window stage loses focus.                  |
| BACKGROUND | 4     | The window stage is running in the background. |

## WindowStage<sup>9+</sup>

Implements a window manager, which manages each basic window unit, that is, [Window](#window) instance.

Before calling any of the following APIs, you must use [onWindowStageCreate()](js-apis-application-ability.md#abilityonwindowstagecreate) to create a **WindowStage** instance.

### getMainWindow<sup>9+</sup>

getMainWindow(callback: AsyncCallback&lt;Window&gt;): void

Obtains the main window of this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                   | Mandatory | Description                              |
| -------- | -------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes       | Callback used to return the main window. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        windowStage.getMainWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        });
    }
};

```

### getMainWindow<sup>9+</sup>

getMainWindow(): Promise&lt;Window&gt;

Obtains the main window of this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                             | Description                             |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the main window. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        let promise = windowStage.getMainWindow();
        promise.then((data) => {
        windowClass = data;
            console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        }).catch((err) => {
            console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(err));
        });
    }
};

```

### getMainWindowSync<sup>9+</sup>

getMainWindowSync(): Window

Obtains the main window of this window stage.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type              | Description             |
| ----------------- | ----------------------- |
| [Window](#window) | return the main window. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        try {
            let windowClass = windowStage.getMainWindowSync();
        } catch (exception) {
            console.error('Failed to obtain the main window. Cause: ' + JSON.stringify(exception));
        };
    }
};

```

### createSubWindow<sup>9+</sup>

createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow for this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                   | Mandatory | Description                            |
| -------- | -------------------------------------- | --------- | -------------------------------------- |
| name     | string                                 | Yes       | Name of the subwindow.                 |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes       | Callback used to return the subwindow. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        try {
            windowStage.createSubWindow('mySubWindow', (err, data) => {
                if (err.code) {
                    console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
                    return;
                }
                windowClass = data;
                console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
                windowClass.resetSize(500, 1000);
            });
        } catch (exception) {
            console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(exception));
        };
    }
};

```

### createSubWindow<sup>9+</sup>

createSubWindow(name: string): Promise&lt;Window&gt;

Creates a subwindow for this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type   | Mandatory | Description            |
| ---- | ------ | --------- | ---------------------- |
| name | string | Yes       | Name of the subwindow. |

**Return value**

| Type                             | Description                           |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        try {
            let promise = windowStage.createSubWindow('mySubWindow');
            promise.then((data) => {
                windowClass = data;
                console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
            }).catch((err) => {
                console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
            });
        } catch (exception) {
            console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(exception));
        };
    }
};

```

### getSubWindow<sup>9+</sup>

getSubWindow(callback: AsyncCallback&lt;Array&lt;Window&gt;&gt;): void

Obtains all the subwindows of this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                                | Mandatory | Description                                 |
| -------- | --------------------------------------------------- | --------- | ------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Window](#window)&gt;&gt; | Yes       | Callback used to return all the subwindows. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        windowStage.getSubWindow((err, data) => {
            if (err.code) {
                console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
                return;
            }
            windowClass = data;
            console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
        });
    }
};

```

### getSubWindow<sup>9+</sup>

getSubWindow(): Promise&lt;Array&lt;Window&gt;&gt;

Obtains all the subwindows of this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                          | Description                                |
| --------------------------------------------- | ------------------------------------------ |
| Promise&lt;Array&lt;[Window](#window)&gt;&gt; | Promise used to return all the subwindows. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let windowClass = null;
        let promise = windowStage.getSubWindow();
        promise.then((data) => {
            windowClass = data;
            console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
        }).catch((err) => {
            console.error('Failed to obtain the subwindow. Cause: ' + JSON.stringify(err));
        })
    }
};

```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page associated with a local storage to the main window in this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| path     | string                                                       | Yes       | Path of the page from which the content will be loaded.      |
| storage  | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | Yes       | A storage unit, which provides storage for variable state properties and non-variable state properties of an application. |
| callback | AsyncCallback&lt;void&gt;                                    | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    storage : LocalStorage
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate('storageSimpleProp',121);
        console.log('onWindowStageCreate');
        try {
            windowStage.loadContent('pages/page2',this.storage,(err) => {
                if (err.code) {
                    console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in loading the content.');
            });
        } catch (exception) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
        };
    }
};

```

### loadContent<sup>9+</sup>

loadContent(path: string, storage?: LocalStorage): Promise&lt;void&gt;

Loads content from a page associated with a local storage to the main window in this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type                                                         | Mandatory | Description                                                  |
| ------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| path    | string                                                       | Yes       | Path of the page from which the content will be loaded.      |
| storage | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | No        | A storage unit, which provides storage for variable state properties and non-variable state properties of an application. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    storage : LocalStorage
    onWindowStageCreate(windowStage) {
        this.storage = new LocalStorage();
        this.storage.setOrCreate('storageSimpleProp',121);
        console.log('onWindowStageCreate');
        try {
            let promise = windowStage.loadContent('pages/page2',this.storage);
            promise.then(() => {
                console.info('Succeeded in loading the content.');
            }).catch((err) => {
                console.error('Failed to load the content. Cause:' + JSON.stringify(err));
            });
        } catch (exception) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
        };
    }
};

```

### loadContent<sup>9+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page to this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                             |
| -------- | ------------------------- | --------- | ------------------------------------------------------- |
| path     | string                    | Yes       | Path of the page from which the content will be loaded. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                     |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        try {
            windowStage.loadContent('pages/page2', (err) => {
                if (err.code) {
                    console.error('Failed to load the content. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in loading the content.');
            });
        } catch (exception) {
            console.error('Failed to load the content. Cause:' + JSON.stringify(exception));
        };
    }
};

```

### on('windowStageEvent')<sup>9+</sup>

on(eventType: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void

Enables listening for window stage lifecycle changes.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'windowStageEvent'**, indicating the window stage lifecycle change event. |
| callback | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | Yes       | Callback used to return the window stage lifecycle state.    |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        try {
            windowStage.on('windowStageEvent', (data) => {
                console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
                    JSON.stringify(data));
            });
        } catch (exception) {
            console.error('Failed to enable the listener for window stage event changes. Cause:' +
                JSON.stringify(exception));
        };
    }
};

```

### off('windowStageEvent')<sup>9+</sup>

off(eventType: 'windowStageEvent', callback?: Callback&lt;WindowStageEventType&gt;): void

Disables listening for window stage lifecycle changes.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | string                                                       | Yes       | Event type. The value is fixed at **'windowStageEvent'**, indicating the window stage lifecycle change event. |
| callback | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | No        | Callback used to return the window stage lifecycle state.    |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        try {
            windowStage.off('windowStageEvent');
        } catch (exception) {
            console.error('Failed to disable the listener for window stage event changes. Cause:' +
                JSON.stringify(exception));
        };
    }
};

```

### disableWindowDecor()<sup>9+</sup>

disableWindowDecor(): void

Disables window decorators.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('disableWindowDecor');
        windowStage.disableWindowDecor();
    }
};

```

### setShowOnLockScreen()<sup>9+</sup>

setShowOnLockScreen(showOnLockScreen: boolean): void

Sets whether to display the window of the application on the lock screen.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name             | Type    | Mandatory | Description                                                  |
| ---------------- | ------- | --------- | ------------------------------------------------------------ |
| showOnLockScreen | boolean | Yes       | Whether to display the window on the lock screen. The value **true** means to display the window on the lock screen, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Window Error Codes](../errorcodes/errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        try {
            windowStage.setShowOnLockScreen(true);
        } catch (exception) {
            console.error('Failed to show on lockscreen. Cause:' + JSON.stringify(exception));
        };
    }
};

```

## TransitionContext<sup>9+</sup>

Provides the context for the transition animation.

### Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                  | Type              | Readable | Writable | Description                             |
| --------------------- | ----------------- | -------- | -------- | --------------------------------------- |
| toWindow<sup>9+</sup> | [Window](#window) | Yes      | Yes      | Target window to display the animation. |

### completeTransition<sup>9+</sup>

completeTransition(isCompleted: boolean): void

Completes the transition. This API can be called only after [animateTo()](../arkui-ts/ts-explicit-animation.md) is executed.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name        | Type    | Mandatory | Description                                                  |
| ----------- | ------- | --------- | ------------------------------------------------------------ |
| isCompleted | boolean | Yes       | Whether the transition is complete. The value **true** means that the transition is complete, and **false** means the opposite. |

**Example**

```js
let controller = windowClass.getTransitionController();
controller.animationForShown = (context : window.TransitionContext) => {
	let toWindow = context.toWindow;
 	animateTo({
    	duration: 1000, // Animation duration.
        tempo: 0.5, // Playback speed.
        curve: Curve.EaseInOut, // Animation curve.
        delay: 0, // Animation delay.
        iterations: 1, // Number of playback times.
        playMode: PlayMode.Normal // Animation playback mode.
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        };
        toWindow.translate(obj);
        console.info('toWindow translate end');
      }
    );
    try {
        context.completeTransition(true)
    } catch (exception) {
        console.info('toWindow translate fail. Cause: ' + JSON.stringify(exception));
    }
    console.info('complete transition end');
};

```

## TransitionController<sup>9+</sup>

Implements the transition animation controller.

### animationForShown<sup>9+</sup>

animationForShown(context: TransitionContext): void

Customizes the animation for the scenario when the window is shown.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type                                     | Mandatory | Description                          |
| ------- | ---------------------------------------- | --------- | ------------------------------------ |
| context | [TransitionContext](#transitioncontext9) | Yes       | Context of the transition animation. |

**Example**

```js
let controller = windowClass.getTransitionController();
controller.animationForShown = (context : window.TransitionContext) => {
	let toWindow = context.toWindow;
 	animateTo({
    	duration: 1000, // Animation duration.
        tempo: 0.5, // Playback speed.
        curve: Curve.EaseInOut, // Animation curve.
        delay: 0, // Animation delay.
        iterations: 1, // Number of playback times.
        playMode: PlayMode.Normal // Animation playback mode.
        onFinish: ()=> {
            context.completeTransition(true)
        }  
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        };
        toWindow.translate(obj);
        console.info('toWindow translate end');
      }
    );
    console.info('complete transition end');
};
```

### animationForHidden<sup>9+</sup>

animationForHidden(context: TransitionContext): void

Customizes the animation for the scenario when the window is hidden.

**System API**: This is a system API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name    | Type                                     | Mandatory | Description                          |
| ------- | ---------------------------------------- | --------- | ------------------------------------ |
| context | [TransitionContext](#transitioncontext9) | Yes       | Context of the transition animation. |

**Example**

```js
let controller = windowClass.getTransitionController();
controller.animationForHidden = (context : window.TransitionContext) => {
	let toWindow = context.toWindow;
 	animateTo({
    	duration: 1000, // Animation duration.
        tempo: 0.5, // Playback speed.
        curve: Curve.EaseInOut, // Animation curve.
        delay: 0, // Animation delay.
        iterations: 1, // Number of playback times.
        playMode: PlayMode.Normal // Animation playback mode.
        onFinish: ()=> {
            context.completeTransition(true)
        }  
      }, () => {
        let obj : window.TranslateOptions = {
          x : 100.0,
          y : 0.0,
          z : 0.0
        };
        toWindow.translate(obj);
        console.info('toWindow translate end');
      }
    )
    console.info('complete transition end');
};
```


# @ohos.window (Window)

The **Window** module provides basic window management capabilities, such as creating and destroying the current window, setting properties for the current window, and managing and scheduling windows.

This module provides the following common window-related functions:

- [Window](#window): window instance, which is the basic unit managed by the window manager.
- [WindowStage](#windowstage9): window manager that manages windows.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { window } from '@kit.ArkUI';
```

## WindowType<sup>7+</sup>

Enumerates the window types.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                                 | Value| Description                                                                                    |
|-------------------------------------| ------ |----------------------------------------------------------------------------------------|
| TYPE_APP                            | 0      | Application subwindow.<br>**Model restriction**: This API can be used only in the FA model.                                                  |
| TYPE_SYSTEM_ALERT                   | 1      | System alert window.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 11.                               |
| TYPE_FLOAT<sup>9+</sup>             | 8      | Floating window.<br>**Model restriction**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| TYPE_DIALOG<sup>10+</sup>           | 16      | Modal window.<br>**Model restriction**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## Configuration<sup>9+</sup>

Defines the parameters for creating a subwindow or system window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Mandatory| Description                                                                         |
| ---------- | -------------------------- | -- |-----------------------------------------------------------------------------|
| name       | string                     | Yes| Name of the window.                                                                      |
| windowType | [WindowType](#windowtype7) | Yes| Window type.                                                                      |
| ctx        | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | No| Current application context. If no value is passed, no context is used.<br>In the FA model, do not pass in this parameter when creating a subwindow. Otherwise, an error is reported.<br>In the stage model, you must pass in this parameter when creating a floating window, modal window, or system window.|
| displayId  | number                     | No| ID of the current physical screen. If no value is passed, the default value **-1** is used. The value must be an integer.                                            |
| parentId   | number                     | No| ID of the parent window. If no value is passed, the default value **-1** is used. The value must be an integer.                                                          |
| decorEnabled<sup>12+</sup> | boolean | No| Whether the window decoration is enabled. This parameter is valid only when **windowType** is set to **TYPE_DIALOG**. The value **true** means that the window decoration is enabled, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|
| title<sup>12+</sup> | string| No| Title of the window when **decorEnabled** is set to **true**. If this parameter is not set, an empty string is used by default.<br>**System capability**: SystemCapability.Window.SessionManager|

## AvoidAreaType<sup>7+</sup>

Enumerates the types of the area where the window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name                            | Value  | Description                                                        |
| -------------------------------- | ---- | ------------------------------------------------------------ |
| TYPE_SYSTEM                      | 0    | Default area of the system. Generally, the status bar and navigation bar are included. The default area may vary according to the device in use.|
| TYPE_CUTOUT                      | 1    | Notch.                                            |
| TYPE_SYSTEM_GESTURE<sup>9+</sup> | 2    | Gesture area.                                              |
| TYPE_KEYBOARD<sup>9+</sup>       | 3    | Soft keyboard area.                                            |
| TYPE_NAVIGATION_INDICATOR<sup>11+</sup> | 4    | Navigation bar area.                                     |


## SystemBarProperties

Describes the properties of the status bar and navigation bar. These properties are valid for the window-level status bar and navigation bar.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                                  | Type|  Mandatory| Description                                                        |
| -------------------------------------- | -------- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   |  No  | Background color of the status bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. The default value is **'#0x66000000'**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isStatusBarLightIcon<sup>7+</sup>      | boolean  |  No  | Whether any icon on the status bar is highlighted. The value **true** means that the icon is highlighted, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| statusBarContentColor<sup>8+</sup>     | string   |  No  | Color of the text on the status bar. After this property is set, the setting of **isStatusBarLightIcon** is invalid. The default value is **'#0xE5FFFFFF'**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| navigationBarColor                     | string   |  No  | Background color of the navigation bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. The default value is **'#0x66000000'**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  |  No  | Whether any icon on the navigation bar is highlighted. The value **true** means that the icon is highlighted, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| navigationBarContentColor<sup>8+</sup> | string   |  No  | Color of the text on the navigation bar. After this property is set, the setting of **isNavigationBarLightIcon** is invalid. The default value is **'#0xE5FFFFFF'**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| enableStatusBarAnimation<sup>12+</sup> | boolean   |  No  | Whether to enable animation for a status bar property change. The value **true** means to enable animation, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|
| enableNavigationBarAnimation<sup>12+</sup> | boolean   |  No  | Whether to enable animation for a navigation bar property change. The value **true** means to enable animation, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|

## SystemBarStyle<sup>12+</sup>

Describes the properties of the status bar. These properties are valid for the page-level status bar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Read Only| Optional| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| statusBarContentColor   | string   | Yes  | Yes  | Color of the text on the status bar. The default value is **'#0xE5FFFFFF'**.|

## Orientation<sup>9+</sup>

Enumerates the window orientations.

| Name                                 | Value  | Description                         |
| ------------------------------------- | ---- | ----------------------------- |
| UNSPECIFIED                           | 0    | Unspecified. The orientation is determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| PORTRAIT                              | 1    | Portrait.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| LANDSCAPE                             | 2    | Landscape.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| PORTRAIT_INVERTED                     | 3    | Reverse portrait.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| LANDSCAPE_INVERTED                    | 4    | Reverse landscape.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| AUTO_ROTATION                         | 5    | Automatically rotates with the sensor. The orientation can be portrait, landscape, reverse portrait, or reverse landscape.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_ROTATION_PORTRAIT                | 6    | Automatically rotates with the sensor in the vertical direction. The orientation can be portrait or reverse portrait.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_LANDSCAPE               | 7    | Automatically rotates with the sensor in the horizontal direction. The orientation can be landscape or reverse landscape.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| AUTO_ROTATION_RESTRICTED              | 8    | Automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation can be portrait, landscape, reverse portrait, or reverse landscape.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| AUTO_ROTATION_PORTRAIT_RESTRICTED     | 9    | Automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation can be portrait or reverse portrait.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_LANDSCAPE_RESTRICTED    | 10   | Automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation can be landscape or reverse landscape.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| LOCKED                                | 11   | Locked.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_UNSPECIFIED<sup>12+</sup>        | 12   | Automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation that can be rotated to is determined by the system. For example, the window can rotate to portrait, landscape, or reverse landscape, but not reverse portrait, on a certain device.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Window.SessionManager|
| USER_ROTATION_PORTRAIT<sup>12+</sup>           | 13   | Temporarily rotates to portrait mode, and then automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation that can be rotated to is determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Window.SessionManager|
| USER_ROTATION_LANDSCAPE<sup>12+</sup>          | 14   | Temporarily rotates to landscape mode, and then automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation that can be rotated to is determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Window.SessionManager|
| USER_ROTATION_PORTRAIT_INVERTED<sup>12+</sup>  | 15   | Temporarily rotates to reverse portrait mode, and then automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation that can be rotated to is determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Window.SessionManager|
| USER_ROTATION_LANDSCAPE_INVERTED<sup>12+</sup> | 16   | Temporarily rotates to reverse landscape mode, and then automatically rotates with the sensor, under the restriction of the rotation switch in the Control Panel. The orientation that can be rotated to is determined by the system.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Window.SessionManager|
| FOLLOW_DESKTOP<sup>12+</sup>                   | 17   | Follows the orientation of the home screen.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.Window.SessionManager|

## Rect<sup>7+</sup>

Describes the rectangular area of the window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type| Readable| Writable| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | Yes  | Yes  | Left boundary of the rectangle, in px. The value must be an integer.|
| top    | number   | Yes  | Yes  | Top boundary of the rectangle, in px. The value must be an integer.|
| width  | number   | Yes  | Yes  | Width of the rectangle, in px. The value must be an integer.|
| height | number   | Yes  | Yes  | Height of the rectangle, in px. The value must be an integer.|

## AvoidArea<sup>7+</sup>

Describes the area where the window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area. Touch events will not be responded in this area.

Pay attention to the following restrictions on this area:

- The non-navigation bar area in the gesture area at the bottom supports transparent transmission of touch events, touch and hold events, but not drag events.

- The gesture area on the left and right sides supports transparent transmission of touch events, touch and hold events, and swipe up and down events, but not drag events.

- The navigation bar area supports responding to touch events, touch and hold events, and drag events. However, it does not support transparent transmission of events.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

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

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type| Readable| Writable| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | Yes  | Yes  | Window width, in px. The value must be an integer.|
| height | number   | Yes  | Yes  | Window height, in px. The value must be an integer.|

## RectChangeReason<sup>12+</sup>

Enumerates the reasons for window rectangle (position and size) changes.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                 | Value  | Description                                                        |
| --------------------- | ---- | ------------------------------------------------------------ |
| UNDEFINED                 | 0    | Default value.                                                  |
| MAXIMIZE                | 1    | The window is maximized.                                                  |
| RECOVER              | 2    | The window is restored to the previous state.                                                  |
| MOVE | 3    | The window is moved.|
| DRAG  | 4    | The window is zoomed in or out by dragging.|
| DRAG_START  | 5    | The window starts zooming in or out.|
| DRAG_END  | 6    | The window finishes zooming in or out.|

## RectChangeOptions<sup>12+</sup>

Describes the value and reason returned upon a window rectangle (position and size) change.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type     | Readable| Writable| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| rect   | [Rect](#rect7) | Yes  | Yes  | New value of the window rectangle.|
| reason    | [RectChangeReason](#rectchangereason12) | Yes  | Yes  | Reason for the window rectangle change.|

## AvoidAreaOptions<sup>12+</sup>

Describes the new area where the window cannot be displayed. The new area is returned when the corresponding event is triggered.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type     | Readable| Writable| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| type   | [AvoidAreaType](#avoidareatype7) | Yes  | Yes  | Type of the new area returned.|
| area   | [AvoidArea](#avoidarea7)         | Yes  | Yes  | New area returned.|

## WindowProperties

Describes the window properties.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                                 | Type                 | Read Only| Optional| Description                                                                                                    |
| ------------------------------------- | ------------------------- | ---- | ---- |--------------------------------------------------------------------------------------------------------|
| windowRect<sup>7+</sup>               | [Rect](#rect7)             | No  | No  | Window size.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                 |
| drawableRect<sup>11+</sup>            | [Rect](#rect7)             | No  | No  | Size of the rectangle that can be drawn in the window. The upper boundary and left boundary are calculated relative to the window.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                 |
| type<sup>7+</sup>                     | [WindowType](#windowtype7) | No  | No  | Window type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                 |
| isFullScreen                          | boolean                   | No  | No  | Whether the window is displayed in full-screen mode. The default value is **false**. The value **true** means that the window is displayed in full-screen mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                 |
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | No  | No  | Whether the window layout is in full-screen mode (whether the window is immersive). The default value is **false**. The value **true** means that the window is immersive, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                           |
| focusable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window can gain focus. The default value is **true**. The value **true** means that the window can gain focus, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                               |
| touchable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window is touchable. The default value is **true**. The value **true** means that the window is touchable, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                |
| brightness                            | number                    | No  | No  | Screen brightness. The value is a floating point number in the range [0.0, 1.0], and the value **1.0** means the brightest. If no value is passed, the brightness follows the system. In this case, the obtained brightness value is **-1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                     |
| dimBehindValue<sup>(deprecated)</sup> | number                    | No  | No  | Dimness of the window that is not on top. The value is a floating point number in the range [0.0, 1.0], and the value **1.0** means the dimmest.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9. |
| isKeepScreenOn                        | boolean                   | No  | No  | Whether the screen is always on. The default value is **false**. The value **true** means that the screen is always on, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                  |
| isPrivacyMode<sup>7+</sup>            | boolean                   | No  | No  | Whether the window is in privacy mode. The default value is **false**. The value **true** means that the window is in privacy mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                 |
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | No  | No  | Whether the window has rounded corners. The default value is **false**. The value **true** means that the window has rounded corners, and **false** means the opposite.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9.      |
| isTransparent<sup>7+</sup>            | boolean                   | No  | No  | Whether the window is transparent. The default value is **false**. The value **true** means that the window is transparent, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                  |
| id<sup>9+</sup>                       | number                    | Yes  | No  | Window ID. The default value is **0**. The value must be an integer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                   |
| displayId<sup>12+</sup>               | number                    | Yes  | Yes  | ID of the screen where the window is located. By default, the ID of the main screen is returned. The value must be an integer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## ColorSpace<sup>8+</sup>

Enumerates the color spaces.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name      | Value| Description          |
| ---------- | ------ | -------------- |
| DEFAULT    | 0      | Default SRGB gamut.|
| WIDE_GAMUT | 1      | Wide-gamut.  |

## WindowEventType<sup>10+</sup>

Enumerates the window lifecycle states.

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name      | Value| Description      |
| ---------- | ------ | ---------- |
| WINDOW_SHOWN      | 1      | The window is running in the foreground.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_ACTIVE     | 2      | The window gains focus.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_INACTIVE   | 3      | The window loses focus.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_HIDDEN     | 4      | The window is running in the background.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_DESTROYED<sup>11+</sup>  | 7      | The window is destroyed.<br>**System capability**: SystemCapability.Window.SessionManager|

## WindowLimits<sup>11+</sup>

Defines the window size limits. You can call [setWindowLimits](#setwindowlimits11) to set the window size limits and call [getWindowLimits](#getwindowlimits11) to obtain the current window size limits.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name     | Type  | Readable| Writable| Description                                                        |
| :-------- | :----- | :--- | :--- | :----------------------------------------------------------- |
| maxWidth  | number | Yes  | Yes  | Maximum window width, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the maximum width specified by the system. |
| maxHeight | number | Yes  | Yes  | Maximum window height, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the maximum height specified by the system. |
| minWidth  | number | Yes  | Yes  | Minimum window width, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the minimum width specified by the system. |
| minHeight | number | Yes  | Yes  | Minimum window height, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the minimum height specified by the system. |

## WindowStatusType<sup>11+</sup>

Enumerates the window modes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 0    | The window mode is not defined by the application.      |
| FULL_SCREEN | 1    | The application is displayed in full screen.            |
| MAXIMIZE    | 2    | The application window is maximized.  |
| MINIMIZE    | 3    | The application window is minimized.  |
| FLOATING    | 4    | The application is displayed in a floating window.  |
| SPLIT_SCREEN  | 5    | The application is displayed in split-screen mode.  |

## TitleButtonRect<sup>11+</sup>

Defines the rectangle used to hold the minimize, maximize, and close buttons on the title bar. This rectangle is located in the upper right corner of the window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Readable| Writable| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| right  | number | Yes  | Yes  | Right boundary of the rectangle, in vp. The value must be an integer.|
| top    | number | Yes  | Yes  | Top boundary of the rectangle, in vp. The value must be an integer.|
| width  | number | Yes  | Yes  | Width of the rectangle, in vp. The value must be an integer.  |
| height | number | Yes  | Yes  | Height of the rectangle, in vp. The value must be an integer.  |

## MaximizePresentation<sup>12+</sup>

Enumerates the layout when the window is maximized.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| FOLLOW_APP_IMMERSIVE_SETTING  | 0    | The window, when maximized, follows the immersive layout of the application.      |
| EXIT_IMMERSIVE | 1    | The window, when maximized, exits the immersive layout.            |
| ENTER_IMMERSIVE    | 2    | The window, when maximized, enters the immersive layout.  |

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow or system window. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW (required when the window type is **window.WindowType.TYPE_FLOAT**)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------------------- | -- | --------------------------------- |
| config   | [Configuration](#configuration9)       | Yes| Parameters used for creating the window.  |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes| Callback used to return the window created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300008 | The display device is abnormal. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));
    windowClass.resize(500, 1000);
  });
} catch (exception) {
  console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration): Promise&lt;Window&gt;

Creates a subwindow or system window. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW (required when the window type is **window.WindowType.TYPE_FLOAT**)

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300008 | The display device is abnormal. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "test",
  windowType: window.WindowType.TYPE_DIALOG,
  ctx: this.context
};
try {
  let promise = window.createWindow(config);
  promise.then((data) => {
    windowClass = data;
    console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the Window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.findWindow<sup>9+</sup>

findWindow(name: string): Window

Finds a window based on the name.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| name   | string | Yes  | Window name, that is, the value of **name** in [Configuration](#configuration9).|

**Return value**

| Type| Description|
| ----------------- | ------------------- |
| [Window](#window) | Window found.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
let windowClass: window.Window | undefined = undefined;
try {
  windowClass = window.findWindow('test');
} catch (exception) {
  console.error(`Failed to find the Window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext, callback: AsyncCallback&lt;Window&gt;): void

Obtains the top window of the current application. This API uses an asynchronous callback to return the result. If no subwindow is available, the main window of the application is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------------------- | -- | ---------------------------------------- |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes| Current application context.|
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes| Callback used to return the top window obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.   |
| 1300006 | This window context is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      window.getLastWindow(this.context, (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
      });
    } catch (exception) {
      console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext): Promise&lt;Window&gt;

Obtains the top window of the current application. This API uses a promise to return the result. If no subwindow is available, the main window of the application is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the top window obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.   |
| 1300006 | This window context is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      let promise = window.getLastWindow(this.context);
      promise.then((data) => {
        windowClass = data;
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.shiftAppWindowFocus<sup>11+</sup>
shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise&lt;void&gt;

Shifts the window focus from the source window to the target window in the same application. The window focus can be shifted between the main window and a subwindow.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | Yes   | ID of the source window, which is having the focus.|
| targetWindowId | number | Yes   | ID of the target window.            |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| ------- | --------------------------------------------- |
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
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    let subWindowClass: window.Window | undefined = undefined;
    let windowClassId: number = -1;
    let subWindowClassId: number = -1;

    try {
      // Obtain the main window and ID of the application.
      let promise = windowStage.getMainWindow();
      promise.then((data) => {
        if (data == null) {
          console.error("Failed to obtaining the window. Cause: The data is empty");
          return;
        }
        windowClass = data;
        windowClass.setUIContent("pages/Index");
        windowClassId = windowClass.getWindowProperties().id;
        console.info('Succeeded in obtaining the window')
      }).catch((err: BusinessError) => {
        console.error(`Failed to obtaining the window. Cause code: ${err.code}, message: ${err.message}`);
      });

      // Create or obtain a subwindow and its ID. In this case, the subwindow has focus.
      let promiseSub = windowStage.createSubWindow("testSubWindow");
      promiseSub.then((data) => {
        if (data == null) {
          console.error("Failed to obtaining the window. Cause: The data is empty");
          return;
        }
        subWindowClass = data;
        subWindowClassId = subWindowClass.getWindowProperties().id;
        subWindowClass.resize(500, 500);
        subWindowClass.setUIContent("pages/Index2");
        subWindowClass.showWindow();

        // Listen for the window status and ensure that the window is ready.
        subWindowClass.on("windowEvent", (windowEvent) => {
          if (windowEvent == window.WindowEventType.WINDOW_ACTIVE) {
            // Switch the focus.
            let promise = window.shiftAppWindowFocus(subWindowClassId, windowClassId);
            promise.then(() => {
              console.info('Succeeded in shifting app window focus');
            }).catch((err: BusinessError) => {
              console.error(`Failed to shift app window focus. Cause code: ${err.code}, message: ${err.message}`);
            });
          }
        });
      });
    } catch (exception) {
      console.error(`Failed to shift app focus. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
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
| id       | string                                 | Yes  | Window name, that is, the value of **name** in [Configuration](#configuration9).|
| type     | [WindowType](#windowtype7)              | Yes  | Window type.                          |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the subwindow created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.create('test', window.WindowType.TYPE_APP, (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to create the subWindow. Cause code: ${err.code}, message: ${err.message}`);
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
| id     | string                    | Yes  | Window name, that is, the value of **name** in [Configuration](#configuration9).  |
| type   | [WindowType](#windowtype7) | Yes  | Window type.|

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.create('test', window.WindowType.TYPE_APP);
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in creating the subWindow. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to create the subWindow. Cause code: ${err.code}, message: ${err.message}`);
});
```

## window.create<sup>(deprecated)</sup>

create(ctx: BaseContext, id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a system window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------ |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.                |
| id       | string                                                  | Yes  | Window name, that is, the value of **name** in [Configuration](#configuration9).  |
| type     | [WindowType](#windowtype7)                              | Yes  | Window type.                          |
| callback | AsyncCallback&lt;[Window](#window)&gt;                  | Yes  | Callback used to return the subwindow created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.create('test', window.WindowType.TYPE_SYSTEM_ALERT, (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  windowClass = data;
  console.info('Succeeded in creating the window. Data: ' + JSON.stringify(data));
  windowClass.resetSize(500, 1000);
});
```

## window.create<sup>(deprecated)</sup>

create(ctx: BaseContext, id: string, type: WindowType): Promise&lt;Window&gt;

Creates a system window. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createWindow()](#windowcreatewindow9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.|
| id     | string                    | Yes  | Window name, that is, the value of **name** in [Configuration](#configuration9).|
| type   | [WindowType](#windowtype7) | Yes  | Window type.                                                  |

**Return value**

| Type                            | Description                                   |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow created.|


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.create('test', window.WindowType.TYPE_SYSTEM_ALERT);
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in creating the window. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to create the Window. Cause code: ${err.code}, message: ${err.message}`);
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
| id       | string                                 | Yes  | Window name, that is, the value of **name** in [Configuration](#configuration9).|
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the window found.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.find('test', (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to find the Window. Cause code: ${err.code}, message: ${err.message}`);
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
| id     | string | Yes  | Window name, that is, the value of **name** in [Configuration](#configuration9).|

**Return value**

| Type                            | Description                                 |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the window found.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.find('test');
promise.then((data) => {
  windowClass = data;
  console.info('Succeeded in finding the window. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to find the Window. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
window.getTopWindow((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let promise = window.getTopWindow();
promise.then((data)=> {
    windowClass = data;
    console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError)=>{
    console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
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
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md)                            | Yes  | Current application context.|
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the top window obtained.                |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage:window.WindowStage){
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      window.getTopWindow(this.context, (err: BusinessError, data) => {
        const errCode: number = err.code;
        if(errCode){
          console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
          return ;
        }
        windowClass = data;
        console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
      });
    } catch(error){
      console.error(`Failed to obtain the top window. Cause code: ${error.code}, message: ${error.message}`);
    }
  }
}
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
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.|

**Return value**

| Type                            | Description                                           |
| -------------------------------- | ----------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the top window obtained.|

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage:window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    let promise = window.getTopWindow(this.context);
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the top window. Data: ' + JSON.stringify(data));
    }).catch((error: BusinessError) => {
      console.error(`Failed to obtain the top window. Cause code: ${error.code}, message: ${error.message}`);
    });
  }
}
```

## SpecificSystemBar<sup>11+</sup>

type SpecificSystemBar = 'status' \| 'navigation' \| 'navigationIndicator'

Enumerates the types of system bars that can be displayed or hidden.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type      | Description    |
|------------|--------|
| 'status'   | Status bar.  |
| 'navigation'   | Three-button navigation bar.  |
| 'navigationIndicator'   | Bottom navigation bar.|

## Window

Represents a window instance, which is the basic unit managed by the window manager.

In the following API examples, you must use [getLastWindow()](#windowgetlastwindow9), [createWindow()](#windowcreatewindow9), or [findWindow()](#windowfindwindow9) to obtain a **Window** instance (named windowClass in this example) and then call a method in this instance.

### showWindow<sup>9+</sup>

showWindow(callback: AsyncCallback&lt;void&gt;): void

Shows this window. This API uses an asynchronous callback to return the result. This API takes effect only for a system window or an application subwindow. For the main window of an application, this API moves it at the top when the main window is already displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.showWindow((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to show the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in showing the window.');
});
```

### showWindow<sup>9+</sup>

showWindow(): Promise&lt;void&gt;

Shows this window. This API uses a promise to return the result. This API takes effect only for a system window or an application subwindow. For the main window of an application, this API moves it at the top when the main window is already displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type| Description|
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.showWindow();
promise.then(() => {
  console.info('Succeeded in showing the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### destroyWindow<sup>9+</sup>

destroyWindow(callback: AsyncCallback&lt;void&gt;): void

Destroys this window. This API uses an asynchronous callback to return the result. This API takes effect only for a system window or an application subwindow.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | --------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.destroyWindow((err) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in destroying the window.');
});
```

### destroyWindow<sup>9+</sup>

destroyWindow(): Promise&lt;void&gt;

Destroys this window. This API uses a promise to return the result. This API takes effect only for a system window or an application subwindow.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.destroyWindow();
promise.then(() => {
  console.info('Succeeded in destroying the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

Moves this window. This API uses an asynchronous callback to return the result.

<!--RP4-->
In full-screen mode, this API takes effect only on 2-in-1 devices.<!--RP4End-->

On a 2-in-1 device, the window moves relative to the screen. On other devices, the window moves relative to the parent window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | --------------------------------------------- |
| x        | number                    | Yes| Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. The value must be an integer. If a floating point number is passed in, the value is rounded down.|
| y        | number                    | Yes| Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. The value must be an integer. If a floating point number is passed in, the value is rounded down.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.moveWindowTo(300, 300, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in moving the window.');
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### moveWindowTo<sup>9+</sup>

moveWindowTo(x: number, y: number): Promise&lt;void&gt;

Moves this window. This API uses a promise to return the result. The result is returned once the API is called successfully. However, the final effect cannot be obtained immediately after the result is returned. To obtain the final effect immediately, call [moveWindowToAsync()](#movewindowtoasync12).

<!--RP4-->
In full-screen mode, this API takes effect only on 2-in-1 devices.<!--RP4End-->

On a 2-in-1 device, the window moves relative to the screen. On other devices, the window moves relative to the parent window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. The value must be an integer. If a floating point number is passed in, the value is rounded down.|
| y | number | Yes| Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. The value must be an integer. If a floating point number is passed in, the value is rounded down.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.moveWindowTo(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### moveWindowToAsync<sup>12+</sup>

moveWindowToAsync(x: number, y: number): Promise&lt;void&gt;

Moves this window. This API uses a promise to return the result.

The result is returned once the API is called successfully. However, the final effect cannot be obtained immediately after the result is returned. To obtain the final effect immediately, call **getWindowProperties** (see the code snippet below).

This operation is not supported in a window in full-screen mode.

On a 2-in-1 device, the window moves relative to the screen. On other devices, the window moves relative to the parent window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. The value must be an integer. If a floating point number is passed in, the value is rounded down.|
| y | number | Yes| Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. The value must be an integer. If a floating point number is passed in, the value is rounded down.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation is not supported in full-screen mode. |

**Example**

```ts
import { window } from '@kit.ARKUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';

// EntryAbility.ets
export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      let options : window.SubWindowOptions = {
        title: 'title',
        decorEnabled: true
      };
      let promise = windowStage.createSubWindowWithOptions('mySubWindow', options);
      promise.then((data) => {
        windowClass = data;
        try {
          let promise = windowClass.moveWindowToAsync(300,300);
          promise.then(() => {
            console.info('Succeeded in moving the window.');
            let rect = windowClass.getWindowProperties().windowRect;
            console.info(`Get window rect: ` + JSON.stringify(rect));
          }).catch((err: BusinessError) => {
            console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
          });
        } catch (exception) {
          console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
        }
        console.info('Succeeded in creating the subwindow.Data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### resize<sup>9+</sup>

resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

Changes the size of this window. This API uses an asynchronous callback to return the result.

The main window and subwindow have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.

The minimum width and height of the main window and subwindow of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: [0, 1920] in width and [0, 1920] in height, both in units of vp.

The window width and height you set must meet the limits. The rules are as follows:
- If the window width or height you set is less than the minimum width or height limit, then the minimum width or height limit takes effect.
- If the window width or height you set is greater than the maximum width or height limit, then the maximum width or height limit takes effect.

This operation is not supported in a window in full-screen mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | ------------------------ |
| width    | number                    | Yes| New width of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid.|
| height   | number                    | Yes| New height of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.resize(500, 1000, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in changing the window size.');
  });
} catch (exception) {
  console.error(`Failed to change the window size. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### resize<sup>9+</sup>

resize(width: number, height: number): Promise&lt;void&gt;

Changes the size of this window. This API uses a promise to return the result.

The result is returned once the API is called successfully. However, the final effect cannot be obtained immediately after the result is returned. To obtain the final effect immediately, call [resizeAsync()](#resizeasync12).

The main window and subwindow have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.

The minimum width and height of the main window and subwindow of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: [0, 1920] in width and [0, 1920] in height, both in units of vp.

The window width and height you set must meet the limits. The rules are as follows:
- If the window width or height you set is less than the minimum width or height limit, then the minimum width or height limit takes effect.
- If the window width or height you set is greater than the maximum width or height limit, then the maximum width or height limit takes effect.

This operation is not supported in a window in full-screen mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | -- | ------------------------ |
| width  | number | Yes| New width of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid.|
| height | number | Yes| New height of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.resize(500, 1000);
  promise.then(() => {
    console.info('Succeeded in changing the window size.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to change the window size. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### resizeAsync<sup>12+</sup>

resizeAsync(width: number, height: number): Promise&lt;void&gt;

Changes the size of this window. This API uses a promise to return the result.

 The result is returned once the API is called successfully. However, the final effect cannot be obtained immediately after the result is returned. To obtain the final effect immediately, call **getWindowProperties** (see the code snippet below).

The main window and subwindow have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.

The minimum width and height of the main window and subwindow of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: [0, 1920] in width and [0, 1920] in height, both in units of vp.

The window width and height you set must meet the limits. The rules are as follows:

- If the window width or height you set is less than the minimum width or height limit, then the minimum width or height limit takes effect.
- If the window width or height you set is greater than the maximum width or height limit, then the maximum width or height limit takes effect.

This operation is not supported in a window in full-screen mode.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | -- | ------------------------ |
| width  | number | Yes| New width of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid.|
| height | number | Yes| New height of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300010 | The operation is not supported in full-screen mode. |

**Example**

```ts
import { window } from '@kit.ARKUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';

// EntryAbility.ets
export default class EntryAbility extends UIAbility {
  // ...
    onWindowStageCreate(windowStage:window.WindowStage) {
      console.info('onWindowStageCreate');
      let windowClass: window.Window | undefined = undefined;
      try {
        let options : window.SubWindowOptions = {
          title: 'title',
          decorEnabled: true
        };
        let promise = windowStage.createSubWindowWithOptions('mySubWindow', options);
        promise.then((data) => {
          windowClass = data;
          try {
            let promise = windowClass.resizeAsync(500, 1000);
            promise.then(() => {
              console.info('Succeeded in changing the window size.');
              let rect = windowClass.getWindowProperties().windowRect;
              console.info(`Get window rect: ` + JSON.stringify(rect));
            }).catch((err: BusinessError) => {
              console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
            });
          } catch (exception) {
            console.error(`Failed to change the window size. Cause code: ${exception.code}, message: ${exception.message}`);
          }
          console.info('Succeeded in creating the subwindow.Data: ' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
          console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### getWindowProperties<sup>9+</sup>

getWindowProperties(): WindowProperties

Obtains the properties of this window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type| Description|
| ------------------------------------- | ------------- |
| [WindowProperties](#windowproperties) | Window properties obtained.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
try {
  let properties = windowClass.getWindowProperties();
} catch (exception) {
  console.error(`Failed to obtain the window properties. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getWindowAvoidArea<sup>9+</sup>

getWindowAvoidArea(type: AvoidAreaType): AvoidArea

Obtains the area where this window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area.

This API can be used in the **onWindowStageCreate** callback to obtain the avoid area in the initial layout during application startup. It can also be used when a subwindow requires temporary display, necessitating the avoidance of the layout for the existing content.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- |----------------------------------| -- | ------------------------------------------------------------ |
| type | [AvoidAreaType](#avoidareatype7) | Yes| Type of the area.|

**Return value**

| Type| Description|
|--------------------------| ----------------- |
| [AvoidArea](#avoidarea7) | Area where the window cannot be displayed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
let type = window.AvoidAreaType.TYPE_SYSTEM;
try {
  let avoidArea = windowClass.getWindowAvoidArea(type);
} catch (exception) {
  console.error(`Failed to obtain the area. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowLayoutFullScreen<sup>9+</sup>

setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

Sets whether the main window layout or the subwindow layout is immersive. This API uses a promise to return the result.
- An immersive layout means that the layout does not avoid the status bar and navigation bar, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and navigation bar, and components do not overlap with them.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------------ | ------- | -- | ------------------------------------------------------------------------------------------------ |
| isLayoutFullScreen | boolean | Yes| Whether the window layout is immersive. (The status bar and navigation bar of the immersive layout are still displayed.) The value **true** means that the window layout is immersive, and **false** means the opposite.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
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
      let isLayoutFullScreen = true;
      try {
        let promise = windowClass.setWindowLayoutFullScreen(isLayoutFullScreen);
        promise.then(() => {
          console.info('Succeeded in setting the window layout to full-screen mode.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the window layout to full-screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setImmersiveModeEnabledState<sup>12+</sup>

setImmersiveModeEnabledState(enabled: boolean): void

Sets whether to enable the immersive layout for the main window. This API does not change the window mode or size.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| enabled    | boolean | Yes  | Whether to enable the immersive layout.<br>The value **true** means to enable the immersive layout, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                |

**Example**

```ts
try {
  let enabled = false;
  windowClass.setImmersiveModeEnabledState(enabled);
} catch (exception) {
  console.error(`Failed to set the window immersive mode enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getImmersiveModeEnabledState<sup>12+</sup>

getImmersiveModeEnabledState(): boolean

Checks whether the immersive layout is enabled for this window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**
| Type    | Description                                                                                |
| ------- | ------------------------------------------------------------------------------------ |
| boolean | Result indicating whether the immersive layout is enabled.<br>The value **true** means that the immersive layout is enabled, and **false** means the opposite.<br>|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| -------- | -------------------------------------------- |
| 1300002  | This window state is abnormal.               |
| 1300003  | This window manager service works abnormally. |
| 1300004  | Unauthorized operation.               |

**Example**

```ts
try {
  let isEnabled = windowClass.getImmersiveModeEnabledState();
} catch (exception) {
  console.error(`Failed to get the window immersive mode enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowSystemBarEnable<sup>9+</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

Sets whether to show the three-button navigation bar, status bar, and bottom navigation bar of the main window. This API uses a promise to return the result. The display of the status bar and bottom navigation bar is controlled by **status**, and that of the three-button navigation bar is controlled by **navigation**. From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type | Mandatory| Description|
| ----- | ---------------------------- | -- | --------------------------------- |
| names | Array<'status'\|'navigation'> | Yes| Whether to show the three-button navigation bar, status bar, and bottom navigation bar of the window in full-screen mode.<br>For example, to show all of them, set this parameter to **['status', 'navigation']**. By default, they are not displayed.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// In this example, the three-button navigation bar, status bar, and bottom navigation bar are not displayed.
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
      let names: Array<'status' | 'navigation'> = [];
      try {
        let promise = windowClass.setWindowSystemBarEnable(names);
        promise.then(() => {
          console.info('Succeeded in setting the system bar to be invisible.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setSpecificSystemBarEnabled<sup>11+</sup>

setSpecificSystemBarEnabled(name: SpecificSystemBar, enable: boolean, enableAnimation?: boolean): Promise&lt;void&gt;

Sets whether to show the three-button navigation bar, status bar, and bottom navigation bar of the main window. This API uses a promise to return the result. From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type | Mandatory| Description|
| ----- | ---------------------------- | -- | --------------------------------- |
| name  | [SpecificSystemBar](#specificsystembar11) | Yes| Type of the system bar to be shown or hidden.|
| enable  | boolean | Yes| Whether to show the three-button navigation bar, status bar, and bottom navigation bar. The value **true** means to show them, and **false** means to hide them.|
| enableAnimation<sup>12+</sup>  | boolean | No| Whether to enable animation when the three-button navigation bar, status bar, and bottom navigation bar status changes. The value **true** means to enable animation, and **false** means the opposite. The default value is **false**.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// Hide the bottom navigation bar.
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
      try {
        let promise = windowClass.setSpecificSystemBarEnabled('navigationIndicator', false);
        promise.then(() => {
          console.info('Succeeded in setting the system bar to be invisible.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowSystemBarProperties<sup>9+</sup>

setWindowSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

Sets the properties of the three-button navigation bar and status bar of the main window. This API uses a promise to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes  | Properties of the three-button navigation bar and status bar.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
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
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // The following properties are supported since API version 8.
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      try {
        let promise = windowClass.setWindowSystemBarProperties(SystemBarProperties);
        promise.then(() => {
          console.info('Succeeded in setting the system bar properties.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the system bar properties. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### getWindowSystemBarProperties<sup>12+</sup>

getWindowSystemBarProperties(): SystemBarProperties

Obtains the properties of the three-button navigation bar and status bar of the main window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type| Description|
| ------------------------------------- | ------------- |
| [SystemBarProperties](#systembarproperties) | Properties of the three-button navigation bar and status bar.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |


**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let systemBarProperty = windowClass.getWindowSystemBarProperties();
        console.info('Success in obtaining system bar properties. Property: ' + JSON.stringify(systemBarProperty));
      } catch (err) {
        console.error(`Failed to get system bar properties. Code: ${err.code}, message: ${err.message}`);
      }
    });
  }
};
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

Sets the preferred orientation for the main window. This API uses an asynchronous callback to return the result. This API takes effect only on the device that supports rotation with the sensor. It does not take effect after it is called by the subwindow.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| orientation         | [Orientation](#orientation9)                | Yes  | Orientation to set.        |
| callback            | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result.            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |

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
      let orientation = window.Orientation.AUTO_ROTATION;
      try {
        windowClass.setPreferredOrientation(orientation, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set window orientation. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting window orientation.');
        });
      } catch (exception) {
        console.error(`Failed to set window orientation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation): Promise&lt;void&gt;

Sets the preferred orientation for the main window. This API uses a promise to return the result. This API takes effect only on the device that supports rotation with the sensor. It does not take effect after it is called by the subwindow.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| orientation         | [Orientation](#orientation9)                | Yes  | Orientation to set.      |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |

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
      let orientation = window.Orientation.AUTO_ROTATION;
      try {
        let promise = windowClass.setPreferredOrientation(orientation);
        promise.then(() => {
          console.info('Succeeded in setting the window orientation.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the window orientation. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set window orientation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### getPreferredOrientation<sup>12+</sup>

getPreferredOrientation(): Orientation

Obtains the orientation of the main window. This API can be called only by the main window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type| Description|
|------------------------------| ------------------ |
| [Orientation](#orientation9) | Orientation.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      try {
        let orientation = windowClass.getPreferredOrientation();
      } catch (exception) {
        console.error(`Failed to get window orientation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
};
```

### getUIContext<sup>10+</sup>

getUIContext(): UIContext

Obtain a **UIContext** instance.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type      | Description                  |
| ---------- | ---------------------- |
| [UIContext](js-apis-arkui-UIContext.md#uicontext) | **UIContext** instance obtained.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window, UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // Load content for the main window.
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
        console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
        // Obtain a UIContext instance.
        let uiContext: UIContext | null = null;
        uiContext = windowClass.getUIContext();
      });
    });
  }
};
```

### setUIContent<sup>9+</sup>

setUIContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a page, with its path in the current project specified, to this window. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | -------------------- |
| path     | string                    | Yes| Path of the page from which the content will be loaded. In the stage model, the path is configured in the **main_pages.json** file of the project. In the FA model, the path is configured in the **config.json** file of the project.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.setUIContent('pages/page2/page3', (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in loading the content.');
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setUIContent<sup>9+</sup>

setUIContent(path: string): Promise&lt;void&gt;

Loads the content of a page, with its path in the current project specified, to this window. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ------ | -- | ------------------ |
| path | string | Yes| Path of the page from which the content will be loaded. In the stage model, the path is configured in the **main_pages.json** file of the project. In the FA model, the path is configured in the **config.json** file of the project.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.setUIContent('pages/page2/page3');
  promise.then(() => {
    console.info('Succeeded in loading the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a page, with its path in the current project specified, to this window, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | Yes  | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project.|
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|
| callback | AsyncCallback&lt;void&gt;                       | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent('pages/page2', storage, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in loading the content.');
});
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage): Promise&lt;void&gt;

Loads the content of a page, with its path in the current project specified, to this window, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type                                           | Mandatory| Description                                                        |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | Yes  | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project.|
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
let promise = windowClass.loadContent('pages/page2', storage);
promise.then(() => {
  console.info('Succeeded in loading the content.');
}).catch((err: BusinessError) => {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
});
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name     | string                                                  | Yes  | Name of the named route page.                                            |
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|
| callback | AsyncCallback&lt;void&gt;                               | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**Example**
<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

console.info('onWindowStageCreate');
let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
try {
  (windowClass as window.Window).loadContentByName(Index.entryName, storage, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in loading the content.');
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
@Component
export struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                     | Mandatory| Description            |
| -------- | ------------------------- | ---- | ---------------- |
| name     | string                    | Yes  | Name of the named route page.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**Example**
<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

try {
  (windowClass as window.Window).loadContentByName(Index.entryName, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in loading the content.');
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName})
@Component
export struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage?: LocalStorage): Promise&lt;void&gt;

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name    | string                                                  | Yes  | Name of the named route page.                                            |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | No  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                |
| 1300003  | This window manager service works abnormally. |

**Example**
<!--code_no_check-->
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
try {
  let promise = (windowClass as window.Window).loadContentByName(Index.entryName, storage);
  promise.then(() => {
    console.info('Succeeded in loading the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
@Component
export struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### isWindowShowing<sup>9+</sup>

isWindowShowing(): boolean

Checks whether this window is displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type| Description|
| ------- | ------------------------------------------------------------------ |
| boolean | Whether the window is displayed. The value **true** means that the window is displayed, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
try {
  let data = windowClass.isWindowShowing();
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
} catch (exception) {
  console.error(`Failed to check whether the window is showing. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('windowSizeChange')<sup>7+</sup>

on(type:  'windowSizeChange', callback: Callback&lt;Size&gt;): void

Subscribes to the window size change event.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | Callback&lt;[Size](#size7)&gt; | Yes  | Callback used to return the window size.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
try {
  windowClass.on('windowSizeChange', (data) => {
    console.info('Succeeded in enabling the listener for window size changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('windowSizeChange')<sup>7+</sup>

off(type: 'windowSizeChange', callback?: Callback&lt;Size&gt;): void

Unsubscribes from the window size change event.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                         | Mandatory| Description                                                    |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | Yes  | Event type. The value is fixed at **'windowSizeChange'**, indicating the window size change event.|
| callback | Callback&lt;[Size](#size7)&gt; | No  | Callback used to return the window size. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
const callback = (size: window.Size) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('windowSizeChange', callback);
  // Disable the listening of a specified callback.
  windowClass.off('windowSizeChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('windowSizeChange');
} catch (exception) {
  console.error(`Failed to disable the listener for window size changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('avoidAreaChange')<sup>9+</sup>

on(type: 'avoidAreaChange', callback: Callback&lt;AvoidAreaOptions&gt;): void

Subscribes to the event indicating changes to the area where this window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                             | Mandatory| Description                                 |
| -------- |----------------------------------| ---- |--------------------------------------|
| type     | string                           | Yes  | Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;[AvoidAreaOptions](#avoidareaoptions12)&gt; | Yes  | Callback used to return the area and area type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
try {
  windowClass.on('avoidAreaChange', (data) => {
    console.info('Succeeded in enabling the listener for system avoid area changes. type:' +
    JSON.stringify(data.type) + ', area: ' + JSON.stringify(data.area));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for system avoid area changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('avoidAreaChange')<sup>9+</sup>

off(type: 'avoidAreaChange', callback?: Callback&lt;AvoidAreaOptions&gt;): void

Unsubscribes from the event indicating changes to the area where this window cannot be displayed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                             | Mandatory| Description                               |
| -------- |----------------------------------|------|------------------------------------|
| type     | string                           | Yes  | Event type. The value is fixed at **'avoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed.|
| callback | Callback&lt;[AvoidAreaOptions](#avoidareaoptions12)&gt; | No  | Callback used to return the area and area type. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
interface Param {
  type: window.AvoidAreaType,
  area: window.AvoidArea
}
const callback = (data: Param) => {
  // ...
}
try {
  windowClass.on('avoidAreaChange', callback);

  windowClass.off('avoidAreaChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('avoidAreaChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for system avoid area changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('keyboardHeightChange')<sup>7+</sup>

on(type: 'keyboardHeightChange', callback: Callback&lt;number&gt;): void

Subscribes to the event indicating soft keyboard height changes in fixed state.

The system notifies the keyboard height change when the soft keyboard is invoked by the window and overlaps with the window.

Since API version 10, the soft keyboard can be set to the fixed or floating state. For details, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type               | Mandatory| Description                                       |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | Yes  | Event type. The value is fixed at **'keyboardHeightChange'**, indicating the keyboard height change event.|
| callback | Callback&lt;number&gt; | Yes  | Callback used to return the current keyboard height, which is an integer, in px.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.on('keyboardHeightChange', (data) => {
    console.info('Succeeded in enabling the listener for keyboard height changes. Data: ' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to enable the listener for keyboard height changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('keyboardHeightChange')<sup>7+</sup>

off(type: 'keyboardHeightChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from the event indicating soft keyboard height changes in fixed state.

Since API version 10, the soft keyboard can be set to the fixed or floating state. For details, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'keyboardHeightChange'**, indicating the keyboard height change event.|
| callback | Callback&lt;number&gt; | No  | Callback used to return the current keyboard height, which is an integer, in px. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (height: number) => {
  // ...
}
try {
  windowClass.on('keyboardHeightChange', callback);

  windowClass.off('keyboardHeightChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('keyboardHeightChange');
} catch (exception) {
  console.error(`Failed to disable the listener for keyboard height changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('touchOutside')<sup>11+</sup>

on(type: 'touchOutside', callback: Callback&lt;void&gt;): void

Subscribes to the touch event outside this window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type               | Mandatory| Description                                                        |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'touchOutside'**, indicating the touch event outside this window.|
| callback | Callback&lt;void&gt; | Yes  | Callback used to return the touch event outside this window.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
try {
  windowClass.on('touchOutside', () => {
    console.info('touch outside');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('touchOutside')<sup>11+</sup>

off(type: 'touchOutside', callback?: Callback&lt;void&gt;): void

Unsubscribes from the touch event outside this window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- |----------------------| ---- |--------------------------------------|
| type     | string               | Yes  | Event type. The value is fixed at **'touchOutside'**, indicating the touch event outside this window.|
| callback | Callback&lt;void&gt; | No  | Callback used to return the touch event outside this window. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
const callback = () => {
  // ...
}
try {
  windowClass.on('touchOutside', callback);
  windowClass.off('touchOutside', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('touchOutside');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('screenshot')<sup>9+</sup>

on(type: 'screenshot', callback: Callback&lt;void&gt;): void

Subscribes to the screenshot event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type               | Mandatory| Description                                                        |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'screenshot'**, indicating the screenshot event, which can be initiated from the Control Panel, by running hdc commands, or by calling the screenshot interfaces.|
| callback | Callback&lt;void&gt; | Yes  | Callback invoked when a screenshot event occurs.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
try {
  windowClass.on('screenshot', () => {
    console.info('screenshot happened');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('screenshot')<sup>9+</sup>

off(type: 'screenshot', callback?: Callback&lt;void&gt;): void

Unsubscribes from the screenshot event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'screenshot'**, indicating the screenshot event.|
| callback | Callback&lt;void&gt; | No  | Callback invoked when a screenshot event occurs. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
let callback = () => {
  console.info('screenshot happened');
};
try {
  windowClass.on('screenshot', callback);
  windowClass.off('screenshot', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('screenshot');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('dialogTargetTouch')<sup>10+</sup>

on(type: 'dialogTargetTouch', callback: Callback&lt;void&gt;): void

Subscribes to click or touch events in a window covered by a modal window. This API takes effect only when it is called by a modal window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                         |
| -------- | ------------------- | ---- | ------------------------------------------------------------ |
| type     | string              | Yes  | Event type. The value is fixed at **'dialogTargetTouch'**, indicating the click or touch event in a window covered by a modal window.|
| callback | Callback&lt;void&gt;| Yes  | Callback invoked when a click or touch event occurs in the window covered by the modal window.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
try {
  windowClass.on('dialogTargetTouch', () => {
    console.info('touch dialog target');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('dialogTargetTouch')<sup>10+</sup>

off(type: 'dialogTargetTouch', callback?: Callback&lt;void&gt;): void

Unsubscribes from the touch event of the target window in the modal window mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'dialogTargetTouch'**, indicating the touch event of the target window in the modal window mode.|
| callback | Callback&lt;void&gt;      | No  | Callback invoked when the touch event occurs in the target window of the modal window mode. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
const callback = () => {
  // ...
}
try {
  windowClass.on('dialogTargetTouch', callback);
  windowClass.off('dialogTargetTouch', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('dialogTargetTouch');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('windowEvent')<sup>10+</sup>

on(type: 'windowEvent', callback: Callback&lt;WindowEventType&gt;): void

Subscribes to the window lifecycle change event.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | Yes  | Event type. The value is fixed at **'windowEvent'**, indicating the window lifecycle change event.|
| callback | Callback&lt;[WindowEventType](#windoweventtype10)&gt; | Yes  | Callback used to return the window lifecycle state.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
try {
  windowClass.on('windowEvent', (data) => {
    console.info('Window event happened. Event:' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('windowEvent')<sup>10+</sup>

off(type: 'windowEvent', callback?: Callback&lt;WindowEventType&gt;): void

Unsubscribes from the window lifecycle change event.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | Yes  | Event type. The value is fixed at **'windowEvent'**, indicating the window lifecycle change event.|
| callback | Callback&lt;[WindowEventType](#windoweventtype10)&gt; | No  | Callback used to return the window lifecycle state. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |

**Example**

```ts
const callback = (windowEventType: window.WindowEventType) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('windowEvent', callback);
  // Disable the listening of a specified callback.
  windowClass.off('windowEvent', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('windowEvent');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('windowVisibilityChange')<sup>11+</sup>

on(type: 'windowVisibilityChange', callback: Callback&lt;boolean&gt;): void

Subscribes to the visibility status change event of this window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'windowVisibilityChange'**, indicating the visibility status change event.|
| callback | Callback&lt;boolean&gt;   | Yes  | Callback used to return the visibility status of the window, which is a Boolean value. The value **true** means that the window is visible, and **false** means the opposite.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
try {
  windowClass.on('windowVisibilityChange', (boolean) => {
    console.info('Window visibility changed, isVisible=' + boolean);
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('windowVisibilityChange')<sup>11+</sup>

off(type: 'windowVisibilityChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the visibility status change event of this window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | Yes  | Event type. The value is fixed at **'windowVisibilityChange'**, indicating the visibility status change event.|
| callback | Callback&lt;boolean&gt;    | No  | Callback used to return the visibility status of the window. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('windowVisibilityChange', callback);
  // Disable the listening of a specified callback.
  windowClass.off('windowVisibilityChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('windowVisibilityChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('noInteractionDetected')<sup>12+</sup>

on(type: 'noInteractionDetected', timeout: number, callback: Callback&lt;void&gt;): void

Subscribes to non-interaction events in a window within the specified period.

Interaction events include physical keyboard input events and screen touch/click events, but not soft keyboard input events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'noInteractionDetected'**, indicating that there is no interaction event in the window within the specified period.|
| timeout     | number                    | Yes  | Period during which no interaction is performed, in seconds. The value must be an integer. Negative numbers and decimals are invalid.|
| callback | Callback&lt;void&gt;      | Yes  | Callback invoked when there is no interaction event in the current window within the specified period. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
try {
  windowClass.on('noInteractionDetected', 60, () => {
    console.info('no interaction in 60s');
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('noInteractionDetected')<sup>12+</sup>

off(type: 'noInteractionDetected', callback?: Callback&lt;void&gt;): void

Unsubscribes from non-interaction events in a window within the specified period.

Interaction events include physical keyboard input events and screen touch/click events, but not soft keyboard input events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | Yes  | Event type. The value is fixed at **'noInteractionDetected'**, indicating that there is no interaction event in the window within the specified period.|
| callback | Callback&lt;void&gt;    | No  | Callback invoked when there is no interaction event in the current window within the specified period. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
const callback = () => {
  // ...
}
try {
  windowClass.on('noInteractionDetected', 60, callback);
  windowClass.off('noInteractionDetected', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('noInteractionDetected');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('windowStatusChange')<sup>11+</sup>

on(type:  'windowStatusChange', callback: Callback&lt;WindowStatusType&gt;): void

Subscribes to the window status change event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowStatusChange'**, indicating the window status change event.|
| callback | Callback&lt;[WindowStatusType](#windowstatustype11)&gt; | Yes  | Callback used to return the window status.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
try {
    windowClass.on('windowStatusChange', (WindowStatusType) => {
        console.info('Succeeded in enabling the listener for window status changes. Data: ' + JSON.stringify(WindowStatusType));
    });
} catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('windowStatusChange')<sup>11+</sup>

off(type: 'windowStatusChange', callback?: Callback&lt;WindowStatusType&gt;): void

Unsubscribes from the window status change event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                         | Mandatory| Description                                                    |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | Yes  | Event type. The value is fixed at **'windowStatusChange'**, indicating the window status change event.|
| callback | Callback&lt;[WindowStatusType](#windowstatustype11)&gt; | No  | Callback used to return the window status. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
const callback = (windowStatusType: window.WindowStatusType) => {
    // ...
}
try {
    windowClass.on('windowStatusChange', callback);
    windowClass.off('windowStatusChange', callback);
    // Unregister all the callbacks that have been registered through on().
    windowClass.off('windowStatusChange');
} catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowGrayScale<sup>12+</sup>

setWindowGrayScale(grayScale: number): Promise&lt;void&gt;

Sets the grayscale effect for this window. This API uses a promise to return the result. This API can be called only after [loadContent()](#loadcontent9) or [setUIContent()](#setuicontent9) is called.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description                                    |
| --------- | ------ | -- | ---------------------------------------- |
| grayScale | number | Yes| Grayscale of the window. The value is a floating point number in the range [0.0, 1.0], The value **0.0** means that the window image does not change, and **1.0** means that the window image is completely turned into grayscale. The effect changes linearly between 0.0 and 1.0.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | --------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass?.setUIContent('pages/Index', (error: BusinessError) => {
  if (error.code) {
    console.error(`Failed to set the content. Cause code: ${error.code}`);
    return;
  }
  console.info('Succeeded in setting the content.');
  let grayScale: number = 0.5;
  try {
    if (canIUse("SystemCapability.Window.SessionManager")) {
      let promise = windowClass?.setWindowGrayScale(grayScale);
      promise?.then(() => {
        console.info('Succeeded in setting the grayScale.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the grayScale. Cause code: ${err.code}, message: ${err.message}`);
      });
    }
  } catch (exception) {
    console.error(`Failed to set the grayScale. Cause code: ${exception.code}, message: ${exception.message}`);
  }
});
```

### on('windowTitleButtonRectChange')<sup>11+</sup>

on(type: 'windowTitleButtonRectChange', callback: Callback&lt;TitleButtonRect&gt;): void

Subscribes to the change event of the rectangle that holds the minimize, maximize, and close buttons on the title bar of the window. This API takes effect for the window that has a title bar or a three-button area on 2-in-1 devices. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is fixed at **'windowTitleButtonRectChange'**, indicating that the change event of the rectangle that holds the minimize, maximize, and close buttons.|
| callback | Callback&lt;[TitleButtonRect](#titlebuttonrect11)&gt; | Yes  | Callback used to return the new rectangle.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |

**Example**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
  try {
    windowClass?.on('windowTitleButtonRectChange', (titleButtonRect) => {
      console.info('Succeeded in enabling the listener for window title buttons area changes. Data: ' + JSON.stringify(titleButtonRect));
    });
  } catch (exception) {
    console.error(`Failed to enable the listener for window title buttons area changes. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

### off('windowTitleButtonRectChange')<sup>11+</sup>

off(type: 'windowTitleButtonRectChange', callback?: Callback&lt;TitleButtonRect&gt;): void

Unsubscribes from the change event of the rectangle that holds the minimize, maximize, and close buttons on the title bar of the window. This API takes effect for the window that has a title bar or a three-button area on 2-in-1 devices. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                | Yes  | Event type. The value is fixed at **'windowTitleButtonRectChange'**, indicating that the change event of the rectangle that holds the minimize, maximize, and close buttons.|
| callback | Callback&lt;[TitleButtonRect](#titlebuttonrect11)&gt; | No  | Callback used to return the new rectangle. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |

**Example**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
	const callback = (titleButtonRect: window.TitleButtonRect) => {
		// ...
	}
  try {
    // Enable listening through the on API.
    windowClass?.on('windowTitleButtonRectChange', callback);
    // Disable the listening of a specified callback.
    windowClass?.off('windowTitleButtonRectChange', callback);
    // Unregister all the callbacks that have been registered through on().
    windowClass?.off('windowTitleButtonRectChange');
  } catch (exception) {
    console.error(`Failed to disable the listener for window title buttons area changes. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

### on('windowRectChange')<sup>12+</sup>

on(type:  'windowRectChange', callback: Callback&lt;RectChangeOptions&gt;): void

Subscribes to window rectangle (position and size) change events.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowRectChange'**, indicating the window rectangle change event.|
| callback | Callback&lt;[RectChangeOptions](#rectchangeoptions12)&gt; | Yes  | Callback used to return the value and reason of the window rectangle change.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
windowClass.on('windowRectChange', (data: window.RectChangeOptions) => {
    console.info('Succeeded window rect changes. Data: ' + JSON.stringify(data));
});
```

### off('windowRectChange')<sup>12+</sup>

off(type: 'windowRectChange', callback?: Callback&lt;RectChangeOptions&gt;): void

Unsubscribes from window rectangle (position and size) change events.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                          | Mandatory| Description                                                        |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowRectChange'**, indicating the window rectangle change event.    |
| callback | Callback&lt;[RectChangeOptions](#rectchangeoptions12)&gt; | No  | Callback used to return the value and reason of the window rectangle change. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
const callback = (rectChangeOptions: window.RectChangeOptions) => {
  // ...
}
windowClass.on('windowRectChange', callback);
windowClass.off('windowRectChange', callback);
// Unregister all the callbacks that have been registered through on().
windowClass.off('windowRectChange');
```

### on('subWindowClose')<sup>12+</sup>

on(type:  'subWindowClose', callback: Callback&lt;void&gt;): void

Subscribes to the event indicating that the subwindow is closed. This event is triggered only when the user touches the close button in the upper right corner provided by the system to close the subwindow. It is not triggered when the subwindow is closed in other ways.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'subWindowClose'**, indicating the subwindow close event.|
| callback | Callback&lt;void&gt; | Yes  | Callback invoked when the close button in the upper right corner of the subwindow is touched. It does not return any parameter. The internal logic of the callback function requires a return value of the Boolean type. The return value determines whether to continue to close the subwindow. The value **true** means not to close the subwindow, and **false** means to continue to close the subwindow.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |

**Example**

```ts
const callback = () => {
  // ...
  return true;
}
try {
  windowClass.on('subWindowClose', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('subWindowClose')<sup>12+</sup>

off(type: 'subWindowClose', callback?: Callback&lt;void&gt;): void

Unsubscribes from the event indicating that the subwindow is closed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                        |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | Yes  | Event type. The value is fixed at **'subWindowClose'**, indicating the subwindow close event.    |
| callback | Callback&lt;void&gt; | No  | Callback invoked when the close button in the upper right corner of the subwindow is touched. It does not return any parameter. The internal logic of the callback function requires a return value of the Boolean type. The return value determines whether to continue to close the subwindow. The value **true** means not to close the subwindow, and **false** means to continue to close the subwindow. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |

**Example**

```ts
const callback = () => {
  // ...
  return true;
}
try {
  windowClass.on('subWindowClose', callback);
  windowClass.off('subWindowClose', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('subWindowClose');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### isWindowSupportWideGamut<sup>9+</sup>

isWindowSupportWideGamut(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this window supports the wide-gamut color space. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------- | -- | -------------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** means that the wide-gamut color space is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.isWindowSupportWideGamut((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in checking whether the window support WideGamut Data: ' + JSON.stringify(data));
});
```

### isWindowSupportWideGamut<sup>9+</sup>

isWindowSupportWideGamut(): Promise&lt;boolean&gt;

Checks whether this window supports the wide-gamut color space. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ---------------------- | ------------------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the wide-gamut color space is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.isWindowSupportWideGamut();
promise.then((data) => {
  console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setWindowColorSpace<sup>9+</sup>

setWindowColorSpace(colorSpace:ColorSpace, callback: AsyncCallback&lt;void&gt;): void

Sets a color space for this window. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------------------------- | -- | ----------- |
| colorSpace | [ColorSpace](#colorspace8) | Yes| Color space to set.|
| callback   | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting window colorspace.');
  });
} catch (exception) {
  console.error(`Failed to set window colorspace. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowColorSpace<sup>9+</sup>

setWindowColorSpace(colorSpace:ColorSpace): Promise&lt;void&gt;

Sets a color space for this window. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------------------------- | -- | ------------- |
| colorSpace | [ColorSpace](#colorspace8) | Yes| Color space to set.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.setWindowColorSpace(window.ColorSpace.WIDE_GAMUT);
  promise.then(() => {
    console.info('Succeeded in setting window colorspace.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set window colorspace. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getWindowColorSpace<sup>9+</sup>

getWindowColorSpace(): ColorSpace

Obtains the color space of this window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type| Description|
| ------------------------- | ------------- |
| [ColorSpace](#colorspace8) | Color space obtained.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
let colorSpace = windowClass.getWindowColorSpace();
```

### setWindowBackgroundColor<sup>9+</sup>

setWindowBackgroundColor(color: string): void

Sets the background color for this window. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| color | string | Yes| Background color to set. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

private SetUIContent(windowClass: window.Window) {
    windowClass.setUIContent("pages/ButtonWindow",(err: BusinessError) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
      let color: string = '#00ff33';
      try {
        windowClass.setWindowBackgroundColor(color);
      } catch (exception) {
        console.error(`Failed to set the background color. Cause code: ${exception.code}, message: ${exception.message}`);
      };
    });
}
```

### setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

Sets the screen brightness for the main window. This API uses an asynchronous callback to return the result.

When the screen brightness setting for the window takes effect, Control Panel cannot adjust the system screen brightness. It can do so only after the window screen brightness is restored to the default value.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description                                       |
| ---------- | ------------------------- | -- |-------------------------------------------|
| brightness | number                    | Yes| Brightness to set. The value is a floating point number in the range [0.0, 1.0] or **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness.|
| callback   | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
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
      let brightness: number = 1;
      try {
        windowClass.setWindowBrightness(brightness, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the brightness.');
        });
      } catch (exception) {
        console.error(`Failed to set the brightness. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number): Promise&lt;void&gt;

Sets the screen brightness for the main window. This API uses a promise to return the result.

When the screen brightness setting for the window takes effect, Control Panel cannot adjust the system screen brightness. It can do so only after the window screen brightness is restored to the default value.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description                                    |
| ---------- | ------ | -- |----------------------------------------|
| brightness | number | Yes| Brightness to set. The value is a floating point number in the range [0.0, 1.0] or **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
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
      let brightness: number = 1;
      try {
        let promise = windowClass.setWindowBrightness(brightness);
        promise.then(() => {
          console.info('Succeeded in setting the brightness.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the brightness. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowFocusable<sup>9+</sup>

setWindowFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is focusable, that is, whether the window can gain focus after it is being clicked or using other methods. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------------------------- | -- | ------------------------------------------------------- |
| isFocusable | boolean                   | Yes| Whether the window can gain focus. The value **true** means that the window can gain focus, and **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
try {
  windowClass.setWindowFocusable(isFocusable, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the window to be focusable.');
  });
} catch (exception) {
  console.error(`Failed to set the window to be focusable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowFocusable<sup>9+</sup>

setWindowFocusable(isFocusable: boolean): Promise&lt;void&gt;

Sets whether this window is focusable, that is, whether the window can gain focus after it is being clicked or using other methods. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
try {
  let promise = windowClass.setWindowFocusable(isFocusable);
  promise.then(() => {
    console.info('Succeeded in setting the window to be focusable.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to be focusable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to keep the screen always on. This API uses an asynchronous callback to return the result.

Set **isKeepScreenOn** to **true** only in necessary scenarios (such as navigation, video playback, drawing, and gaming scenarios). After exiting these scenarios, set the parameter to **false**. Do not use this API in other scenarios (such as no screen interaction or audio playback). When the system detects that the API is used in a non-standard manner, automatic screen-off may be invoked.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------------- | ------------------------- | -- | ---------------------------------------------------- |
| isKeepScreenOn | boolean                   | Yes| Whether to keep the screen always on. The value **true** means to keep the screen always on, and **false** means the opposite. |
| callback       | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
try {
  windowClass.setWindowKeepScreenOn(isKeepScreenOn, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the screen to be always on.');
  });
} catch (exception) {
  console.error(`Failed to set the screen to be always on. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowKeepScreenOn<sup>9+</sup>

setWindowKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt;

Sets whether to keep the screen always on. This API uses a promise to return the result.

Set **isKeepScreenOn** to **true** only in necessary scenarios (such as navigation, video playback, drawing, and gaming scenarios). After exiting these scenarios, set the parameter to **false**. Do not use this API in other scenarios (such as no screen interaction or audio playback). When the system detects that the API is used in a non-standard manner, automatic screen-off may be invoked.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------------- | ------- | -- | --------------------------------------------------- |
| isKeepScreenOn | boolean | Yes| Whether to keep the screen always on. The value **true** means to keep the screen always on, and **false** means the opposite.|

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
try {
  let promise = windowClass.setWindowKeepScreenOn(isKeepScreenOn);
  promise.then(() => {
    console.info('Succeeded in setting the screen to be always on.');
  }).catch((err: BusinessError) => {
    console.info(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the screen to be always on. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowPrivacyMode<sup>9+</sup>

setWindowPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is in privacy mode. This API uses an asynchronous callback to return the result.

A window in privacy mode cannot be captured or recorded. This API can be used in scenarios where screen capture or recording is disabled.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**Parameters**

| Name| Type| Mandatory| Description|
| ------------- | ------------------------- | -- | ------------------------------------------------------ |
| isPrivacyMode | boolean                   | Yes| Whether the window is in privacy mode. The value **true** means that the window is in privacy mode, and **false** means the opposite. |
| callback      | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
try {
  windowClass.setWindowPrivacyMode(isPrivacyMode, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the window to privacy mode.');
  });
} catch (exception) {
  console.error(`Failed to set the window to privacy mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowPrivacyMode<sup>9+</sup>

setWindowPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

Sets whether this window is in privacy mode. This API uses a promise to return the result.

A window in privacy mode cannot be captured or recorded. This API can be used in scenarios where screen capture or recording is disabled.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
try {
  let promise = windowClass.setWindowPrivacyMode(isPrivacyMode);
  promise.then(() => {
    console.info('Succeeded in setting the window to privacy mode.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to privacy mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowTouchable<sup>9+</sup>

setWindowTouchable(isTouchable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is touchable. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------------------------- | -- | ----------------------------------------------- |
| isTouchable | boolean                   | Yes| Whether the window is touchable. The value **true** means that the window is touchable, and **false** means the opposite.|
| callback    | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.                                       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable = true;
try {
  windowClass.setWindowTouchable(isTouchable, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the window to be touchable.');
  });
} catch (exception) {
  console.error(`Failed to set the window to be touchable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowTouchable<sup>9+</sup>

setWindowTouchable(isTouchable: boolean): Promise&lt;void&gt;

Sets whether this window is touchable. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable: boolean = true;
try {
  let promise = windowClass.setWindowTouchable(isTouchable);
  promise.then(() => {
    console.info('Succeeded in setting the window to be touchable.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to be touchable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### snapshot<sup>9+</sup>

snapshot(callback: AsyncCallback&lt;image.PixelMap&gt;): void

Captures this window. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                                         | Mandatory | Description                         |
| -------- | ------------------------------------------------------------ | --------- | ----------------------------------- |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Yes       | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

windowClass.snapshot((err: BusinessError, pixelMap: image.PixelMap) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to snapshot window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
  pixelMap.release(); // Release the memory in time after the PixelMap is used.
});
```

### snapshot<sup>9+</sup>

snapshot(): Promise&lt;image.PixelMap&gt;

Captures this window. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                                                         | Description                                   |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Promise used to return the window screenshot. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let promise = windowClass.snapshot();
promise.then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in snapshotting window. Pixel bytes number: ' + pixelMap.getPixelBytesNumber());
  pixelMap.release(); // Release the memory in time after the PixelMap is used.
}).catch((err: BusinessError) => {
  console.error(`Failed to snapshot window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setAspectRatio<sup>10+</sup>

setAspectRatio(ratio: number): Promise&lt;void&gt;

Sets the aspect ratio of the window content layout. This API uses a promise to return the result.

This API can be called only for the main window and the setting takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode). The aspect ratio is saved persistently, which means that the setting is valid even after the application is closed or the device is restarted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type   | Mandatory | Description                                                  |
| ----- | ------ | --------- | ------------------------------------------------------------ |
| ratio | number | Yes       | Aspect ratio of the window content layout except border decoration. The value is a floating point number and is restricted by the maximum and minimum sizes of the window. The minimum ratio is the value of minimum width divided by the maximum height, and the maximum ratio is the maximum width divided by the minimum height. The maximum and minimum sizes of the window are determined by the intersection of the setting of [WindowLimits](#windowlimits11) and the system limit. The system limit takes precedence over [WindowLimits](#windowlimits11). |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // Obtain the main window of the application.
    if (!windowClass) {
      console.info('windowClass is null');
    }
    try {
      let ratio = 1.0;
      let promise = windowClass.setAspectRatio(ratio);
      promise.then(() => {
        console.info('Succeeded in setting aspect ratio of window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setAspectRatio<sup>10+</sup>

setAspectRatio(ratio: number, callback: AsyncCallback&lt;void&gt;): void

Sets the aspect ratio of the window content layout. This API uses an asynchronous callback to return the result.

This API can be called only for the main window and the setting takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode). The aspect ratio is saved persistently, which means that the setting is valid even after the application is closed or the device is restarted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| ratio    | number                    | Yes       | Aspect ratio of the window content layout except border decoration. The value is a floating point number and is restricted by the maximum and minimum sizes of the window. The minimum ratio is the value of minimum width divided by the maximum height, and the maximum ratio is the maximum width divided by the minimum height. The maximum and minimum sizes of the window are determined by the intersection of the setting of [WindowLimits](#windowlimits11) and the system limit. The system limit takes precedence over [WindowLimits](#windowlimits11). |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // Obtain the main window of the application.
    if (!windowClass) {
      console.info('Failed to load the content. Cause: windowClass is null');
    }
    try {
      let ratio = 1.0;
      windowClass.setAspectRatio(ratio, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the aspect ratio of window.');
      });
    } catch (exception) {
      console.error(`Failed to set the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}

```

### resetAspectRatio<sup>10+</sup>

resetAspectRatio(): Promise&lt;void&gt;

Resets the aspect ratio of the window content layout. This API uses a promise to return the result.

This API can be called only for the main window and the setting takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode). After this API is called, the persistently stored aspect ratio is cleared.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // Obtain the main window of the application.
    if (!windowClass) {
      console.info('Failed to load the content. Cause: windowClass is null');
    }
    try {
      let promise = windowClass.resetAspectRatio();
      promise.then(() => {
        console.info('Succeeded in resetting aspect ratio of window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to reset the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to reset the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### resetAspectRatio<sup>10+</sup>

resetAspectRatio(callback: AsyncCallback&lt;void&gt;): void

Resets the aspect ratio of the window content layout. This API uses an asynchronous callback to return the result.

This API can be called only for the main window and the setting takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode). After this API is called, the persistently stored aspect ratio is cleared.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                         |
| -------- | ------------------------- | --------- | ----------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.        |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {

  // ...
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window = windowStage.getMainWindowSync(); // Obtain the main window of the application.
    if (!windowClass) {
      console.info('Failed to load the content. Cause: windowClass is null');
    }
    try {
      windowClass.resetAspectRatio((err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to reset the aspect ratio of window. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in resetting aspect ratio of window.');
      });
    } catch (exception) {
      console.error(`Failed to reset the aspect ratio of window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### minimize<sup>11+</sup>

minimize(callback: AsyncCallback&lt;void&gt;): void

Implements different functionalities based on the caller:

Minimizes the main window if the caller is the main window. The main window can be restored in the dock bar.

Hides the subwindow if the caller is a subwindow. The subwindow cannot be restored in the dock bar.

This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                      | Mandatory | Description                         |
| -------- | ------------------------- | --------- | ----------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.minimize((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to minimize the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in minimizing the window.');
});
```

### minimize<sup>11+</sup>

minimize(): Promise&lt;void&gt;

Implements different functionalities based on the caller:

Minimizes the main window if the caller is the main window. The main window can be restored in the dock bar.

Hides the subwindow if the caller is a subwindow. The subwindow cannot be restored in the dock bar.

This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.minimize();
promise.then(() => {
  console.info('Succeeded in minimizing the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to minimize the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### maximize<sup>12+</sup>
maximize(presentation?: MaximizePresentation): Promise&lt;void&gt;

Maximizes the main window. This API uses a promise to return the result. It can be used only on 2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                                            | Mandatory | Description                                                  |
| ------------ | ----------------------------------------------- | --------- | ------------------------------------------------------------ |
| presentation | [MaximizePresentation](#maximizepresentation12) | No        | Layout when the window is maximized. The default value is **window.MaximizePresentation.ENTER_IMMERSIVE**, indicating that the window enters the immersive layout when maximized. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      windowClass = data;
      let promise = windowClass.maximize();
      // let promise = windowClass.maximize(window.MaximizePresentation.ENTER_IMMERSIVE);
      promise.then(() => {
        console.info('Succeeded in maximizing the window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to maximize the window. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
};
```

### recover<sup>11+</sup>

recover(): Promise&lt;void&gt;

Restores the main window from the full-screen, maximized, or split-screen mode to a floating window, and restores the window size and position to those before the full-screen, maximized, or split-screen mode is entered. If the main window is already in the floating window mode, nothing will happen. This API uses a promise to return the result. It takes effect only in the multi-window cascade layout. It can be used only on 2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation.                                          |
| 1300002 | This window state is abnormal.                               |

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
      let promise = windowClass.recover();
      promise.then(() => {
        console.info('Succeeded in recovering the window.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to recover the window. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### getWindowLimits<sup>11+</sup>

getWindowLimits(): WindowLimits

Obtains the size limits of this application window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                            | Description         |
| ------------------------------- | ------------------- |
| [WindowLimits](#windowlimits11) | Window size limits. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| :------ | :----------------------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
try {
  let windowLimits = windowClass.getWindowLimits();
} catch (exception) {
  console.error(`Failed to obtain the window limits of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowLimits<sup>11+</sup>

setWindowLimits(windowLimits: WindowLimits): Promise&lt;WindowLimits&gt;

Sets the size limits for this application window. This API uses a promise to return the result.
By default, system size limits are provided. They are determined by the product configuration and cannot be modified. If **setWindowLimits** has not been called, you can call [getWindowLimits](#getwindowlimits11) to obtain the system size limits.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                            | Mandatory | Description                |
| :----------- | :------------------------------ | :-------- | :------------------------- |
| windowLimits | [WindowLimits](#windowlimits11) | Yes       | Target size limits, in px. |

**Return value**

| Type                                           | Description                                                  |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[WindowLimits](#windowlimits11)&gt; | Promise used to return the final size limits, which are the intersection between the passed-in size limits and the system size limits. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| :------ | :----------------------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let windowLimits: window.WindowLimits = {
    maxWidth: 1500,
    maxHeight: 1000,
    minWidth: 500,
    minHeight: 400
  };
  let promise = windowClass.setWindowLimits(windowLimits);
    promise.then((data) => {
    console.info('Succeeded in changing the window limits. Cause:' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to change the window limits. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to change the window limits. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowMask<sup>12+</sup>

setWindowMask(windowMask: Array&lt;Array&lt;number&gt;&gt;): Promise&lt;void&gt;;

Sets a mask for this window to get an irregularly shaped window. This API uses a promise to return the result.

The mask is used to describe the shape of the irregularly shaped window.

This API is available only for subwindows and global floating windows in 2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name       | Type                             | Mandatory | Description                                                  |
| :--------- | :------------------------------- | :-------- | :----------------------------------------------------------- |
| windowMask | Array&lt;Array&lt;number&gt;&gt; | Yes       | Mask. The value can only be a two-dimensional array containing the window size in pixels, with each element in the array set to either **0** or **1**. The value **0** indicates that the pixel is transparent, and **1** indicates that the pixel is opaque. If the passed-in pixel array does not match the window size or the value of any element in the array is not **0** or **1**, the value is invalid. |

**Return value**

| Type                | Description                    |
| :------------------ | :----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| :------ | :----------------------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let windowMask: Array<Array<number>> = [
      [0, 0, 0, 1, 0, 0, 0],
      [0, 0, 1, 1, 1, 0, 0],
      [0, 1, 1, 0, 1, 1, 0],
      [1, 1, 0, 0, 0, 1, 1]
    ];
  let promise = windowClass.setWindowMask(windowMask);
    promise.then(() => {
    console.info('Succeeded in setting the window mask.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window mask. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window mask. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### keepKeyboardOnFocus<sup>11+</sup>

keepKeyboardOnFocus(keepKeyboardFlag: boolean): void

Sets whether to keep the soft keyboard created by others when a window has focus. This API can be called only by a system window or an application subwindow.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name             | Type    | Mandatory | Description                                                  |
| ---------------- | ------- | --------- | ------------------------------------------------------------ |
| keepKeyboardFlag | boolean | Yes       | Whether to keep the soft keyboard created by others. The value **true** means to keep the soft keyboard, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
try {
  windowClass.keepKeyboardOnFocus(true);
} catch (exception) {
  console.error(`Failed to keep keyboard onFocus. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowDecorVisible<sup>11+</sup>

setWindowDecorVisible(isVisible: boolean): void

Sets whether the title bar is visible in the window. This API takes effect for the window that has a title bar or a three-button area on 2-in-1 devices. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name      | Type    | Mandatory | Description                                                  |
| --------- | ------- | --------- | ------------------------------------------------------------ |
| isVisible | boolean | Yes       | Whether the title bar is visible. The value **true** means that the title bar is visible and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in loading the content.');
  let isVisible = false;
  // Call setWindowDecorVisible.
  try {
      windowClass?.setWindowDecorVisible(isVisible);
  } catch (exception) {
      console.error(`Failed to set the visibility of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
  }
});
```

### setSubWindowModal<sup>12+</sup>

setSubWindowModal(isModal: boolean): Promise&lt;void&gt;

Enables the modal property of the subwindow. This API uses a promise to return the result.

This API can be called only by a subwindow. Otherwise, an error is reported.

After the modal property is enabled, the parent window cannot respond to user operations until the subwindow is closed or the modal property is disabled.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| isModal | boolean | Yes       | Whether to enable the modal property of the subwindow. The value **true** means to enable the modal property, and **false** means the opposite. |


**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

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
        let promise = windowClass.setSubWindowModal(true);
        promise.then(() => {
          console.info('Succeeded in setting subwindow modal');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set subwindow modal. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setWindowDecorHeight<sup>11+</sup>

setWindowDecorHeight(height: number): void

<!--RP1-->
Sets the height of the title bar of this window. This API takes effect for the window that has a title bar or a three-button area on 2-in-1 devices. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.
<!--RP1End-->

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| ------ | ------ | --------- | ------------------------------------------------------------ |
| height | number | Yes       | Height of the title bar. It takes effect only for the window with the title bar. The value is an integer in the range [37,112]. The unit is vp. If a floating point number is passed in, the value is rounded down. A value outside the range is invalid. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
  let height: number = 50;
  try {
    windowClass?.setWindowDecorHeight(height);
    console.info(`Succeeded in setting the height of window decor: ${height}`);
  } catch (exception) {
    console.error(`Failed to set the height of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

### getWindowDecorHeight<sup>11+</sup>

getWindowDecorHeight(): number

<!--RP2-->
Obtains the height of the title bar of this window. This API takes effect for the window that has a title bar or a three-button area on 2-in-1 devices. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.
<!--RP2End-->

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| number | Height of the title bar. The value is an integer in the range [37,112]. The unit is vp. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
windowClass.setUIContent('pages/WindowPage').then(() => {
  try {
    let height = windowClass?.getWindowDecorHeight();
    console.info(`Succeeded in getting the height of window decor: ${height}`);
  } catch (exception) {
    console.error(`Failed to get the height of window decor. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

### getTitleButtonRect<sup>11+</sup>

getTitleButtonRect(): TitleButtonRect

<!--RP3-->Obtains the rectangle that holds the minimize, maximize, and close buttons on the title bar of the main window or the decorated subwindow. This API can be used only on 2-in-1 devices.<!--RP3End-->

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                                  | Description                                                  |
| ------------------------------------- | ------------------------------------------------------------ |
| [TitleButtonRect](#titlebuttonrect11) | Rectangle obtained, which is located in the upper right corner of the window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

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
      try {
        let titleButtonArea = windowClass.getTitleButtonRect();
        console.info('Succeeded in obtaining the area of title buttons. Data: ' + JSON.stringify(titleButtonArea));
      } catch (exception) {
        console.error(`Failed to get the area of title buttons. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### getWindowStatus<sup>12+</sup>

getWindowStatus(): WindowStatusType

Obtains the mode of this window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Type                                    | Description  |
| --------------------------------------- | ------------ |
| [WindowStatusType](#windowstatustype11) | Window mode. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
try {
  let windowStatusType = windowClass.getWindowStatus();
} catch (exception) {
  console.error(`Failed to obtain the window status of window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### isFocused<sup>12+</sup>

isFocused(): boolean

Checks whether this window is focused.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | Result indicating whether the window is focused. The value **true** means that the window is focused, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

**Example**

```ts
try {
  let focus = windowClass.isFocused();
  console.info('Succeeded in checking whether the window is focused. Data: ' + JSON.stringify(focus));
} catch (exception) {
  console.error(`Failed to check whether the window is focused. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### createSubWindowWithOptions<sup>12+</sup>

createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise&lt;Window&gt;

Creates a subwindow under the main window or another subwindow. This API uses a promise to return the result. It takes effect only on 2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name    | Type                                    | Mandatory | Description                                 |
| ------- | --------------------------------------- | --------- | ------------------------------------------- |
| name    | string                                  | Yes       | Name of the subwindow.                      |
| options | [SubWindowOptions](#subwindowoptions11) | Yes       | Parameters used for creating the subwindow. |

**Return value**

| Type                             | Description                                           |
| -------------------------------- | ----------------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to used to return the subwindow created. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: Incorrect parameter types.  |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let options : window.SubWindowOptions = {
    title: 'title',
    decorEnabled: true,
    isModal: true
  };
  let promise = windowClass.createSubWindowWithOptions('mySubWindow', options);
  promise.then((data) => {
    console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### enableLandscapeMultiWindow<sup>12+</sup>

enableLandscapeMultiWindow(): Promise&lt;void&gt;

Enables the landscape multi-window mode for the UI page that supports the horizontal layout. You are not advised to call this API for the UI page that adopts the vertical layout.

This API takes effect only for the main window of the application. In addition, **preferMultiWindowOrientation** must be set to **landscape_auto** in the [abilities](../../quick-start/module-configuration-file.md#abilities) tag in the **module.json5** file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                 |
| ------- | --------------------------------------------- |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

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
      let promise = windowClass.enableLandscapeMultiWindow();
      promise.then(() => {
        console.info('Succeeded in making multi-window become landscape.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to make multi-window become landscape. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### disableLandscapeMultiWindow<sup>12+</sup>

disableLandscapeMultiWindow(): Promise&lt;void&gt;

Disables the landscape multi-window mode for the UI page that supports the horizontal layout.

This API takes effect only for the main window of the application. In addition, **preferMultiWindowOrientation** must be set to **landscape_auto** in the [abilities](../../quick-start/module-configuration-file.md#abilities) tag in the **module.json5** file.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                 |
| ------- | --------------------------------------------- |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

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
      let promise = windowClass.disableLandscapeMultiWindow();
      promise.then(() => {
        console.info('Succeeded in making multi-window become not landscape.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to make multi-window become not landscape. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### setDialogBackGestureEnabled<sup>12+</sup>

setDialogBackGestureEnabled(enabled: boolean): Promise&lt;void&gt;

Sets whether the modal window responds to the back gesture event. An error code is returned if this API is called for a non-modal window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| enabled | boolean | Yes       | Whether to respond to the back gesture event.<br>The value **true** means to respond to the back gesture event and trigger the **onBackPress** callback, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
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
        windowClass.setUIContent("pages/Index");
        let enabled = true;
        let promise = windowClass.setDialogBackGestureEnabled(enabled);
        promise.then(() => {
          console.info('Succeeded in setting dialog window to respond back gesture.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set dialog window to respond back gesture. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (exception) {
      console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

```ts
// ets/pages/Index.ets
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
    .height('100%')
    .width('100%')
  }

  onBackPress(): boolean | void {
    console.info('Succeeded in setting dialog window to respond back gesture.');
    return true;
  }
}
```

### setWindowSystemBarProperties<sup>(deprecated)</sup>

setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

Sets the properties of the three-button navigation bar and status bar of the main window. This API uses an asynchronous callback to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setWindowSystemBarProperties](#setwindowsystembarproperties9) in promise mode instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name                | Type                                        | Mandatory | Description                                                  |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the three-button navigation bar and status bar. |
| callback            | AsyncCallback&lt;void&gt;                   | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

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
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // The following properties are supported since API version 8.
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      try {
        windowClass.setWindowSystemBarProperties(SystemBarProperties, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the system bar properties.');
        });
      } catch (exception) {
        console.error(`Failed to set the system bar properties. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowSystemBarEnable<sup>(deprecated)</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

Sets whether to show the three-button navigation bar, status bar, and bottom navigation bar of the main window. This API uses an asynchronous callback to return the result. The display of the status bar and bottom navigation bar is controlled by **status**, and that of the three-button navigation bar is controlled by **navigation**. From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setWindowSystemBarEnable](#setwindowsystembarenable9) in promise mode instead.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                                                  |
| -------- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names    | Array<'status'\|'navigation'> | Yes       | Whether to show the three-button navigation bar, status bar, and bottom navigation bar of the window in full-screen mode.<br>For example, to show all of them, set this parameter to **['status', 'navigation']**. By default, they are not displayed. |
| callback | AsyncCallback&lt;void&gt;     | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

**Example**

```ts
// In this example, the three-button navigation bar, status bar, and bottom navigation bar are not displayed.
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
      let names: Array<'status' | 'navigation'> = [];
      try {
        windowClass.setWindowSystemBarEnable(names, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the system bar to be invisible.');
        });
      } catch (exception) {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowLayoutFullScreen<sup>(deprecated)</sup>

setWindowLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the main window layout or the subwindow layout is immersive. This API uses an asynchronous callback to return the result.
- An immersive layout means that the layout does not avoid the status bar and navigation bar, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and navigation bar, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setWindowLayoutFullScreen](#setwindowlayoutfullscreen9) in promise mode instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name               | Type                      | Mandatory | Description                                                  |
| ------------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | Yes       | Whether the window layout is immersive. (The status bar and navigation bar of the immersive layout are still displayed.) The value **true** means that the window layout is immersive, and **false** means the opposite. |
| callback           | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

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
      let isLayoutFullScreen = true;
      try {
        windowClass.setWindowLayoutFullScreen(isLayoutFullScreen, (err: BusinessError) => {
          const errCode: number = err.code;
          if (errCode) {
            console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
            return;
          }
          console.info('Succeeded in setting the window layout to full-screen mode.');
        });
      } catch (exception) {
        console.error(`Failed to set the window layout to full-screen mode. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.show((err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to show the window. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.show();
promise.then(() => {
  console.info('Succeeded in showing the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show the window. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.destroy((err: BusinessError) => {
  const errCode: number = err.code;
  if (err.code) {
    console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.destroy();
promise.then(() => {
  console.info('Succeeded in destroying the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to destroy the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### moveTo<sup>(deprecated)</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt;): void

Moves this window. This API uses an asynchronous callback to return the result.

This operation is not supported in a window in full-screen mode.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [moveWindowTo()](#movewindowto9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| x        | number                    | Yes       | Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. The value must be an integer. If a floating point number is passed in, the value is rounded down. |
| y        | number                    | Yes       | Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. The value must be an integer. If a floating point number is passed in, the value is rounded down. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.moveTo(300, 300, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in moving the window.');
});
```

### moveTo<sup>(deprecated)</sup>

moveTo(x: number, y: number): Promise&lt;void&gt;

Moves this window. This API uses a promise to return the result.

This operation is not supported in a window in full-screen mode.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [moveWindowTo()](#movewindowto9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type   | Mandatory | Description                                                  |
| ---- | ------ | --------- | ------------------------------------------------------------ |
| x    | number | Yes       | Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. The value must be an integer. If a floating point number is passed in, the value is rounded down. |
| y    | number | Yes       | Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. The value must be an integer. If a floating point number is passed in, the value is rounded down. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.moveTo(300, 300);
promise.then(() => {
  console.info('Succeeded in moving the window.');
}).catch((err: BusinessError) => {
  console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
});
```

### resetSize<sup>(deprecated)</sup>

resetSize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

Changes the size of this window. This API uses an asynchronous callback to return the result.

The main window and subwindow have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.
The minimum width and height of the main window and subwindow of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: [0, 1920] in width and [0, 1920] in height, both in units of vp.

The window width and height you set must meet the limits. The rules are as follows:
- If the window width or height you set is less than the minimum width or height limit, then the minimum width or height limit takes effect.
- If the window width or height you set is greater than the maximum width or height limit, then the maximum width or height limit takes effect.

This operation is not supported in a window in full-screen mode.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [resize()](#resize9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| width    | number                    | Yes       | New width of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid. |
| height   | number                    | Yes       | New height of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.resetSize(500, 1000, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in changing the window size.');
});
```

### resetSize<sup>(deprecated)</sup>

resetSize(width: number, height: number): Promise&lt;void&gt;

Changes the size of this window. This API uses a promise to return the result.

The main window and subwindow have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.
The minimum width and height of the main window and subwindow of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: [0, 1920] in width and [0, 1920] in height, both in units of vp.

The window width and height you set must meet the limits. The rules are as follows:
- If the window width or height you set is less than the minimum width or height limit, then the minimum width or height limit takes effect.
- If the window width or height you set is greater than the maximum width or height limit, then the maximum width or height limit takes effect.

This operation is not supported in a window in full-screen mode.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [resize()](#resize9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| ------ | ------ | --------- | ------------------------------------------------------------ |
| width  | number | Yes       | New width of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid. |
| height | number | Yes       | New height of the window, in px. The value must be an integer. If a floating point number is passed in, the value is rounded down. A negative value is invalid. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.resetSize(500, 1000);
promise.then(() => {
  console.info('Succeeded in changing the window size.');
}).catch((err: BusinessError) => {
  console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.getProperties((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the window properties. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.getProperties();
promise.then((data) => {
  console.info('Succeeded in obtaining the window properties. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the window properties. Cause code: ${err.code}, message: ${err.message}`);
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

| Name     | Type                                          | Mandatory | Description                       |
| -------- | --------------------------------------------- | --------- | --------------------------------- |
| type     | [AvoidAreaType](#avoidareatype7)              | Yes       | Type of the area.                 |
| callback | AsyncCallback&lt;[AvoidArea](#avoidarea7)&gt; | Yes       | Callback used to return the area. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.AvoidAreaType.TYPE_SYSTEM;
windowClass.getAvoidArea(type, (err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to obtain the area. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
});
```

### getAvoidArea<sup>(deprecated)</sup>

getAvoidArea(type: [AvoidAreaType](#avoidareatype7)): Promise&lt;[AvoidArea](#avoidarea7)&gt;

Obtains the area where this window cannot be displayed, for example, the system bar area, notch, gesture area, and soft keyboard area. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getWindowAvoidArea()](#getwindowavoidarea9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name | Type                             | Mandatory | Description       |
| ---- | -------------------------------- | --------- | ----------------- |
| type | [AvoidAreaType](#avoidareatype7) | Yes       | Type of the area. |

**Return value**

| Type                                    | Description                      |
| --------------------------------------- | -------------------------------- |
| Promise&lt;[AvoidArea](#avoidarea7)&gt; | Promise used to return the area. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let type = window.AvoidAreaType.TYPE_SYSTEM;
let promise = windowClass.getAvoidArea(type);
promise.then((data) => {
  console.info('Succeeded in obtaining the area. Data:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the area. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setFullScreen<sup>(deprecated)</sup>

setFullScreen(isFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the main window or the subwindow is in full-screen mode. This API uses an asynchronous callback to return the result.
- In full-screen mode, the layout does not avoid the status bar and navigation bar, and components may overlap with them.
- In non-full-screen mode, the layout avoids the status bar and navigation bar, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9) and [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9) to implement the full-screen mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name         | Type                      | Mandatory | Description                                                  |
| ------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isFullScreen | boolean                   | Yes       | Whether to set full-screen mode. This setting affects the display of the status bar and navigation bar. The value **true** means to set full-screen mode, and **false** means the opposite. |
| callback     | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

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
      let isFullScreen: boolean = true;
      windowClass.setFullScreen(isFullScreen, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to enable the full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in enabling the full-screen mode.');
      });
    });
  }
}
```

### setFullScreen<sup>(deprecated)</sup>

setFullScreen(isFullScreen: boolean): Promise&lt;void&gt;

Sets whether the main window or the subwindow is in full-screen mode. This API uses a promise to return the result.
- In full-screen mode, the layout does not avoid the status bar and navigation bar, and components may overlap with them.
- In non-full-screen mode, the layout avoids the status bar and navigation bar, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9-1) and [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9-1) to implement the full-screen mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name         | Type    | Mandatory | Description                                                  |
| ------------ | ------- | --------- | ------------------------------------------------------------ |
| isFullScreen | boolean | Yes       | Whether to set full-screen mode. This setting affects the display of the status bar and navigation bar. The value **true** means to set full-screen mode, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

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
      let isFullScreen: boolean = true;
      let promise = windowClass.setFullScreen(isFullScreen);
      promise.then(() => {
        console.info('Succeeded in enabling the full-screen mode.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to enable the full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### setLayoutFullScreen<sup>(deprecated)</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the main window layout or the subwindow layout is immersive. This API uses an asynchronous callback to return the result.
- An immersive layout means that the layout does not avoid the status bar and navigation bar, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and navigation bar, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name               | Type                      | Mandatory | Description                                                  |
| ------------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | Yes       | Whether the window layout is immersive. This setting does not affect the display of the status bar and navigation bar. The value **true** means that the window layout is immersive, and **false** means the opposite. |
| callback           | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

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
      let isLayoutFullScreen: boolean = true;
      windowClass.setLayoutFullScreen(isLayoutFullScreen, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the window layout to full-screen mode.');
      });
    });
  }
}
```

### setLayoutFullScreen<sup>(deprecated)</sup>

setLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

Sets whether the main window layout or the subwindow layout is immersive. This API uses a promise to return the result.
- An immersive layout means that the layout does not avoid the status bar and navigation bar, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and navigation bar, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name               | Type    | Mandatory | Description                                                  |
| ------------------ | ------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean | Yes       | Whether the window layout is immersive. This setting does not affect the display of the status bar and navigation bar. The value **true** means that the window layout is immersive, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

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
      let isLayoutFullScreen: boolean = true;
      let promise = windowClass.setLayoutFullScreen(isLayoutFullScreen);
      promise.then(() => {
        console.info('Succeeded in setting the window layout to full-screen mode.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the window layout to full-screen mode. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### setSystemBarEnable<sup>(deprecated)</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

Sets whether to show the three-button navigation bar, status bar, and bottom navigation bar of the main window. This API uses an asynchronous callback to return the result. The display of the status bar and bottom navigation bar is controlled by **status**, and that of the three-button navigation bar is controlled by **navigation**. From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                                                  |
| -------- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names    | Array<'status'\|'navigation'> | Yes       | Whether to show the three-button navigation bar, status bar, and bottom navigation bar of the window in full-screen mode.<br>For example, to show all of them, set this parameter to **['status', 'navigation']**. By default, they are not displayed. |
| callback | AsyncCallback&lt;void&gt;     | Yes       | Callback used to return the result.                          |


**Example**

```ts
// In this example, the three-button navigation bar, status bar, and bottom navigation bar are not displayed.
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
      let names: Array<'status' | 'navigation'> = [];
      windowClass.setSystemBarEnable(names, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the system bar to be invisible.');
      });
    });
  }
}
```

### setSystemBarEnable<sup>(deprecated)</sup>

setSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

Sets whether to show the three-button navigation bar, status bar, and bottom navigation bar of the main window. This API uses a promise to return the result. The display of the status bar and bottom navigation bar is controlled by **status**, and that of the three-button navigation bar is controlled by **navigation**. From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                          | Mandatory | Description                                                  |
| ----- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names | Array<'status'\|'navigation'> | Yes       | Whether to show the three-button navigation bar, status bar, and bottom navigation bar of the window in full-screen mode.<br>For example, to show all of them, set this parameter to **['status', 'navigation']**. By default, they are not displayed. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |


**Example**

```ts
// In this example, the three-button navigation bar, status bar, and bottom navigation bar are not displayed.
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
      let names: Array<'status' | 'navigation'> = [];
      let promise = windowClass.setSystemBarEnable(names);
      promise.then(() => {
        console.info('Succeeded in setting the system bar to be invisible.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### setSystemBarProperties<sup>(deprecated)</sup>

setSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

Sets the properties of the three-button navigation bar and status bar of the main window. This API uses an asynchronous callback to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarProperties()](#setwindowsystembarproperties9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name                | Type                                        | Mandatory | Description                                                  |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the three-button navigation bar and status bar. |
| callback            | AsyncCallback&lt;void&gt;                   | Yes       | Callback used to return the result.                          |

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
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // The following properties are supported since API version 8.
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      windowClass.setSystemBarProperties(SystemBarProperties, (err) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in setting the system bar properties.');
      });
    });
  }
}
```

### setSystemBarProperties<sup>(deprecated)</sup>

setSystemBarProperties(systemBarProperties: SystemBarProperties): Promise&lt;void&gt;

Sets the properties of the three-button navigation bar and status bar of the main window. This API uses a promise to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a subwindow.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarProperties()](#setwindowsystembarproperties9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name                | Type                                        | Mandatory | Description                                                  |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the three-button navigation bar and status bar. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

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
      let SystemBarProperties: window.SystemBarProperties = {
        statusBarColor: '#ff00ff',
        navigationBarColor: '#00ff00',
        // The following properties are supported since API version 8.
        statusBarContentColor: '#ffffff',
        navigationBarContentColor: '#00ffff'
      };
      let promise = windowClass.setSystemBarProperties(SystemBarProperties);
      promise.then(() => {
        console.info('Succeeded in setting the system bar properties.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
      });
    });
  }
}
```

### loadContent<sup>(deprecated)</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page to this window. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setUIContent()](#setuicontent9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| path     | string                    | Yes       | Path of the page from which the content will be loaded. In the stage model, the path is configured in the **main_pages.json** file of the project. In the FA model, the path is configured in the **config.json** file of the project. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.loadContent('pages/page2/page3', (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
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

| Name | Type   | Mandatory | Description                                                  |
| ---- | ------ | --------- | ------------------------------------------------------------ |
| path | string | Yes       | Path of the page from which the content will be loaded. In the stage model, the path is configured in the **main_pages.json** file of the project. In the FA model, the path is configured in the **config.json** file of the project. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.loadContent('pages/page2/page3');
promise.then(() => {
  console.info('Succeeded in loading the content.');
}).catch((err: BusinessError) => {
  console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.isShowing((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to check whether the window is showing. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.isShowing();
promise.then((data) => {
  console.info('Succeeded in checking whether the window is showing. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the window is showing. Cause code: ${err.code}, message: ${err.message}`);
});
```

### on('systemAvoidAreaChange')<sup>(deprecated)</sup>

on(type: 'systemAvoidAreaChange', callback: Callback&lt;AvoidArea&gt;): void

Subscribes to the event indicating changes to the area where this window cannot be displayed.

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

```ts
windowClass.on('systemAvoidAreaChange', (data) => {
  console.info('Succeeded in enabling the listener for system avoid area changes. Data: ' + JSON.stringify(data));
});
```

### off('systemAvoidAreaChange')<sup>(deprecated)</sup>

off(type: 'systemAvoidAreaChange', callback?: Callback&lt;AvoidArea&gt;): void

Unsubscribes from the event indicating changes to the area where this window cannot be displayed.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [off('avoidAreaChange')](#offavoidareachange9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                                     | Mandatory | Description                                                  |
| -------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | string                                   | Yes       | Event type. The value is fixed at **'systemAvoidAreaChange'**, indicating the event of changes to the area where the window cannot be displayed. |
| callback | Callback&lt;[AvoidArea](#avoidarea7)&gt; | No        | Callback used to return the area. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled. |

**Example**

```ts
const callback = (avoidArea: window.AvoidArea) => {
  // ...
}
windowClass.on('systemAvoidAreaChange', callback);
windowClass.off('systemAvoidAreaChange', callback);
// Unregister all the callbacks that have been registered through on().
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.isSupportWideGamut((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.isSupportWideGamut();
promise.then((data) => {
  console.info('Succeeded in checking whether the window support WideGamut. Data: ' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the window support WideGamut. Cause code: ${err.code}, message: ${err.message}`);
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

| Name       | Type                       | Mandatory | Description                         |
| ---------- | -------------------------- | --------- | ----------------------------------- |
| colorSpace | [ColorSpace](#colorspace8) | Yes       | Color space to set.                 |
| callback   | AsyncCallback&lt;void&gt;  | Yes       | Callback used to return the result. |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
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

| Name       | Type                       | Mandatory | Description         |
| ---------- | -------------------------- | --------- | ------------------- |
| colorSpace | [ColorSpace](#colorspace8) | Yes       | Color space to set. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.setColorSpace(window.ColorSpace.WIDE_GAMUT);
promise.then(() => {
  console.info('Succeeded in setting window colorspace.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set window colorspace. Cause code: ${err.code}, message: ${err.message}`);
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

| Name     | Type                                            | Mandatory | Description                                                  |
| -------- | ----------------------------------------------- | --------- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[ColorSpace](#colorspace8)&gt; | Yes       | Callback used to return the result. When the color space is obtained successfully, **err** is **undefined**, and **data** is the current color space. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.getColorSpace((err: BusinessError, data) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get window colorspace. Cause code: ${err.code}, message: ${err.message}`);
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

| Type                                      | Description                                     |
| ----------------------------------------- | ----------------------------------------------- |
| Promise&lt;[ColorSpace](#colorspace8)&gt; | Promise used to return the current color space. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.getColorSpace();
promise.then((data) => {
  console.info('Succeeded in getting window color space. Cause:' + JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.error(`Failed to get window colorspace. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setBackgroundColor<sup>(deprecated)</sup>

setBackgroundColor(color: string, callback: AsyncCallback&lt;void&gt;): void

Sets the background color for this window. This API uses an asynchronous callback to return the result. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBackgroundColor()](#setwindowbackgroundcolor9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| color    | string                    | Yes       | Background color to set. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let color: string = '#00ff33';
windowClass.setBackgroundColor(color, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the background color. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the background color.');
});
```

### setBackgroundColor<sup>(deprecated)</sup>

setBackgroundColor(color: string): Promise&lt;void&gt;

Sets the background color for this window. This API uses a promise to return the result. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBackgroundColor()](#setwindowbackgroundcolor9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type   | Mandatory | Description                                                  |
| ----- | ------ | --------- | ------------------------------------------------------------ |
| color | string | Yes       | Background color to set. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |


**Example**

```ts
import { window } from '@kit.ARKUI';
import { BusinessError } from '@kit.BasicServicesKit';

private SetUIContent(windowClass: window.Window) {
  windowClass.SetUIContent("pages/ButtonWindow",(err: BusinessError) => {
    if (err.code) {
      console.error(`Failed to load the content. Cause code: ${err.code}), message: ${err.message}`);
      return;
    }
    console.info('Succeeded in loading the content.');
    let color: string = '#00ff33';
    try {
      windowClass.SetWindowBackgroundColor(color);
    } catch (exception) {
      console.error(`Failed to set the background color. Cause code: ${exception.code}), message: ${exception.message}`);
    };
  });
}
```

### setBrightness<sup>(deprecated)</sup>

setBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

Sets the screen brightness for this window. This API uses an asynchronous callback to return the result.

When the screen brightness setting for the window takes effect, Control Panel cannot adjust the system screen brightness. It can do so only after the window screen brightness is restored to the default value.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBrightness()](#setwindowbrightness9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type                      | Mandatory | Description                                                  |
| ---------- | ------------------------- | --------- | ------------------------------------------------------------ |
| brightness | number                    | Yes       | Brightness to set. The value is a floating point number in the range [0.0, 1.0] or **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness. |
| callback   | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let brightness: number = 1;
windowClass.setBrightness(brightness, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the brightness.');
});
```

### setBrightness<sup>(deprecated)</sup>

setBrightness(brightness: number): Promise&lt;void&gt;

Sets the screen brightness for this window. This API uses a promise to return the result.

When the screen brightness setting for the window takes effect, Control Panel cannot adjust the system screen brightness. It can do so only after the window screen brightness is restored to the default value.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowBrightness()](#setwindowbrightness9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name       | Type   | Mandatory | Description                                                  |
| ---------- | ------ | --------- | ------------------------------------------------------------ |
| brightness | number | Yes       | Brightness to set. The value is a floating point number in the range [0.0, 1.0] or **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let brightness: number = 1;
let promise = windowClass.setBrightness(brightness);
promise.then(() => {
  console.info('Succeeded in setting the brightness.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the brightness. Cause code: ${err.code}, message: ${err.message}`);
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
| dimBehindValue | number                    | Yes       | Dimness of the window to set. The value range is [0.0, 1.0], and the value **1.0** means the dimmest. |
| callback       | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.setDimBehind(0.5, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the dimness. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.setDimBehind(0.5);
promise.then(() => {
  console.info('Succeeded in setting the dimness.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the dimness. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setFocusable<sup>(deprecated)</sup>

setFocusable(isFocusable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is focusable, that is, whether the window can gain focus after it is being clicked or using other methods. This API uses an asynchronous callback to return the result.

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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
windowClass.setFocusable(isFocusable, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the window to be focusable.');
});
```

### setFocusable<sup>(deprecated)</sup>

setFocusable(isFocusable: boolean): Promise&lt;void&gt;

Sets whether this window is focusable, that is, whether the window can gain focus after it is being clicked or using other methods. This API uses a promise to return the result.

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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isFocusable: boolean = true;
let promise = windowClass.setFocusable(isFocusable);
promise.then(() => {
  console.info('Succeeded in setting the window to be focusable.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window to be focusable. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
windowClass.setKeepScreenOn(isKeepScreenOn, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isKeepScreenOn: boolean = true;
let promise = windowClass.setKeepScreenOn(isKeepScreenOn);
promise.then(() => {
  console.info('Succeeded in setting the screen to be always on.');
}).catch((err: BusinessError) => {
  console.info(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setOutsideTouchable<sup>(deprecated)</sup>

setOutsideTouchable(touchable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether the area outside the subwindow is touchable. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
>
> Since API version 9, the area outside the subwindow is touchable by default. This API is no longer supported and no substitute API is provided.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                      | Mandatory | Description                                                  |
| --------- | ------------------------- | --------- | ------------------------------------------------------------ |
| touchable | boolean                   | Yes       | Whether the area outside the subwindow is touchable. The value **true** means the area outside the subwindow is touchable, and **false** means the opposite. |
| callback  | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

windowClass.setOutsideTouchable(true, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the area to be touchable. Cause code: ${err.code}, message: ${err.message}`);
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
> This API is supported since API version 7 and deprecated since API version 9.
>
> Since API version 9, the area outside the subwindow is touchable by default. This API is no longer supported and no substitute API is provided.

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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = windowClass.setOutsideTouchable(true);
promise.then(() => {
  console.info('Succeeded in setting the area to be touchable.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the area to be touchable. Cause code: ${err.code}, message: ${err.message}`);
});
```

### setPrivacyMode<sup>(deprecated)</sup>

setPrivacyMode(isPrivacyMode: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether this window is in privacy mode. This API uses an asynchronous callback to return the result.

A window in privacy mode cannot be captured or recorded. This API can be used in scenarios where screen capture or recording is disabled.

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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
windowClass.setPrivacyMode(isPrivacyMode, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the window to privacy mode.');
});
```

### setPrivacyMode<sup>(deprecated)</sup>

setPrivacyMode(isPrivacyMode: boolean): Promise&lt;void&gt;

Sets whether this window is in privacy mode. This API uses a promise to return the result.

A window in privacy mode cannot be captured or recorded. This API can be used in scenarios where screen capture or recording is disabled.

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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isPrivacyMode: boolean = true;
let promise = windowClass.setPrivacyMode(isPrivacyMode);
promise.then(() => {
  console.info('Succeeded in setting the window to privacy mode.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window to privacy mode. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable = true;
windowClass.setTouchable(isTouchable, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isTouchable = true;
let promise = windowClass.setTouchable(isTouchable);
promise.then(() => {
  console.info('Succeeded in setting the window to be touchable.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the window to be touchable. Cause code: ${err.code}, message: ${err.message}`);
});
```

## WindowStageEventType<sup>9+</sup>

Describes the lifecycle of a window stage.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name                  | Value | Description                                                  |
| --------------------- | ----- | ------------------------------------------------------------ |
| SHOWN                 | 1     | The window stage is running in the foreground.               |
| ACTIVE                | 2     | The window stage gains focus.                                |
| INACTIVE              | 3     | The window stage loses focus.                                |
| HIDDEN                | 4     | The window stage is running in the background.               |
| RESUMED<sup>11+</sup> | 5     | The window stage is interactive in the foreground, for example, when the user touches the application icon on the recent tasks screen to open the application again. |
| PAUSED<sup>11+</sup>  | 6     | The window stage is non-interactive in the foreground, for example, when the user swipes up from the bottom of the screen and hold to access the recent tasks screen. |

## SubWindowOptions<sup>11+</sup>

Describes the parameters used for creating a subwindow.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name                  | Type    | Read Only | Optional | Description                                                  |
| --------------------- | ------- | --------- | -------- | ------------------------------------------------------------ |
| title                 | string  | No        | No       | Title of the subwindow.                                      |
| decorEnabled          | boolean | No        | No       | Whether decorations are displayed in the subwindow. The value **true** means that decorations are displayed, and **false** means the opposite. |
| isModal<sup>12+</sup> | boolean | No        | Yes      | Whether the modal property is enabled for the subwindow. The value **true** means that modal property is enabled, and **false** means the opposite. When the modal property is enabled, the parent window cannot respond to user operations. The default value is **false**. |

## WindowStage<sup>9+</sup>

Implements a window manager, which manages each basic window unit, that is, [Window](#window) instance.

Before calling any of the following APIs, you must use [onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate) to create a **WindowStage** instance.

### getMainWindow<sup>9+</sup>

getMainWindow(callback: AsyncCallback&lt;Window&gt;): void

Obtains the main window of this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                   | Mandatory | Description                              |
| -------- | -------------------------------------- | --------- | ---------------------------------------- |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes       | Callback used to return the main window. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    windowStage.getMainWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                             | Description                             |
| -------------------------------- | --------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the main window. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    let promise = windowStage.getMainWindow();
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
    });
  }
};
```

### getMainWindowSync<sup>9+</sup>

getMainWindowSync(): Window

Obtains the main window of this window stage.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type              | Description  |
| ----------------- | ------------ |
| [Window](#window) | Main window. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      let windowClass = windowStage.getMainWindowSync();
    } catch (exception) {
      console.error(`Failed to obtain the main window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### createSubWindow<sup>9+</sup>

createSubWindow(name: string, callback: AsyncCallback&lt;Window&gt;): void

Creates a subwindow for this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                   | Mandatory | Description                            |
| -------- | -------------------------------------- | --------- | -------------------------------------- |
| name     | string                                 | Yes       | Name of the subwindow.                 |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes       | Callback used to return the subwindow. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                               |
| ------- | ----------------------------------------------------------- |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.                              |
| 1300005 | This window stage is abnormal.                              |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      windowStage.createSubWindow('mySubWindow', (err: BusinessError, data) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        if (!windowClass) {
          console.info('Failed to load the content. Cause: windowClass is null');
        }
        else {
          (windowClass as window.Window).resize(500, 1000);
        }
      });
    } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### createSubWindow<sup>9+</sup>

createSubWindow(name: string): Promise&lt;Window&gt;

Creates a subwindow for this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type   | Mandatory | Description            |
| ---- | ------ | --------- | ---------------------- |
| name | string | Yes       | Name of the subwindow. |

**Return value**

| Type                             | Description                           |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                               |
| ------- | ----------------------------------------------------------- |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.                              |
| 1300005 | This window stage is abnormal.                              |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      let promise = windowStage.createSubWindow('mySubWindow');
      promise.then((data) => {
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### createSubWindowWithOptions<sup>11+</sup>

createSubWindowWithOptions(name: string, options: SubWindowOptions): Promise&lt;Window&gt;

Creates a subwindow for this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type                                    | Mandatory | Description                                 |
| ------- | --------------------------------------- | --------- | ------------------------------------------- |
| name    | string                                  | Yes       | Name of the subwindow.                      |
| options | [SubWindowOptions](#subwindowoptions11) | Yes       | Parameters used for creating the subwindow. |

**Return value**

| Type                             | Description                                   |
| -------------------------------- | --------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the subwindow created. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: Incorrect parameter types.  |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    try {
      let options : window.SubWindowOptions = {
        title: 'title',
        decorEnabled: true
      };
      let promise = windowStage.createSubWindowWithOptions('mySubWindow', options);
      promise.then((data) => {
        windowClass = data;
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.error(`Failed to create the subwindow. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the subwindow. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### getSubWindow<sup>9+</sup>

getSubWindow(callback: AsyncCallback&lt;Array&lt;Window&gt;&gt;): void

Obtains all the subwindows of this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                                | Mandatory | Description                                 |
| -------- | --------------------------------------------------- | --------- | ------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Window](#window)&gt;&gt; | Yes       | Callback used to return all the subwindows. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300005 | This window stage is abnormal. |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window[] = [];
    windowStage.getSubWindow((err: BusinessError, data) => {
      const errCode: number = err.code;
      if (errCode) {
        console.error(`Failed to obtain the subwindow. Cause code: ${err.code}, message: ${err.message}`);
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                                          | Description                                |
| --------------------------------------------- | ------------------------------------------ |
| Promise&lt;Array&lt;[Window](#window)&gt;&gt; | Promise used to return all the subwindows. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300005 | This window stage is abnormal. |

**Example**
<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    let windowClass: window.Window[] = [];
    let promise = windowStage.getSubWindow();
    promise.then((data) => {
      windowClass = data;
      console.info('Succeeded in obtaining the subwindow. Data: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain the subwindow. Cause code: ${err.code}, message: ${err.message}`);
    });
  }
};
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a page, with its path in the current project specified, to the main window of this window stage, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| path     | string                                                  | Yes       | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project. |
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | Yes       | Page-level UI state storage unit, which is used to transfer the state attribute for the page. |
| callback | AsyncCallback&lt;void&gt;                               | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    this.storage.setOrCreate('storageSimpleProp', 121);
    console.log('onWindowStageCreate');
    try {
      windowStage.loadContent('pages/page2', this.storage, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### loadContent<sup>9+</sup>

loadContent(path: string, storage?: LocalStorage): Promise&lt;void&gt;

Loads the content of a page, with its path in the current project specified, to the main window of this window stage, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name    | Type                                                    | Mandatory | Description                                                  |
| ------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| path    | string                                                  | Yes       | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project. |
| storage | [LocalStorage](../../quick-start/arkts-localstorage.md) | No        | Page-level UI state storage unit, which is used to transfer the state attribute for the page. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    this.storage.setOrCreate('storageSimpleProp', 121);
    console.log('onWindowStageCreate');
    try {
      let promise = windowStage.loadContent('pages/page2', this.storage);
      promise.then(() => {
        console.info('Succeeded in loading the content.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
    ;
  }
};
```

### loadContent<sup>9+</sup>

loadContent(path: string, callback: AsyncCallback&lt;void&gt;): void

Loads content from a page to this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| path     | string                    | Yes       | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.loadContent('pages/page2', (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window stage, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| name     | string                                                  | Yes       | Name of the named route page.                                |
| storage  | [LocalStorage](../../quick-start/arkts-localstorage.md) | Yes       | Page-level UI state storage unit, which is used to transfer the state attribute for the page. |
| callback | AsyncCallback&lt;void&gt;                               | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    this.storage.setOrCreate('storageSimpleProp', 121);
    try {
      windowStage.loadContentByName(Index.entryName, this.storage, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
@Component
export struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, callback: AsyncCallback&lt;void&gt;): void

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                      | Mandatory | Description                         |
| -------- | ------------------------- | --------- | ----------------------------------- |
| name     | string                    | Yes       | Name of the named route page.       |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.loadContentByName(Index.entryName, (err: BusinessError) => {
        const errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('Succeeded in loading the content.');
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName})
@Component
export struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### loadContentByName<sup>11+</sup>

loadContentByName(name: string, storage?: LocalStorage): Promise&lt;void&gt;;

Loads the content a [named route](../../ui/arkts-routing.md#named-route) page to this window stage, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name    | Type         | Mandatory | Description                                                  |
| ------- | ------------ | --------- | ------------------------------------------------------------ |
| name    | string       | Yes       | Name of the named route page.                                |
| storage | LocalStorage | No        | Page-level UI state storage unit, which is used to transfer the state attribute for the page. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |

**Example**

<!--code_no_check-->
```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import * as Index from '../pages/Index'; // Import the named route page.

export default class EntryAbility extends UIAbility {
  // ...

  storage: LocalStorage = new LocalStorage();

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    this.storage.setOrCreate('storageSimpleProp', 121);
    try {
      let promise = windowStage.loadContentByName(Index.entryName, this.storage);
      promise.then(() => {
        console.info('Succeeded in loading the content.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to load the content. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
<!--code_no_check-->
```ts
// ets/pages/Index.ets
export const entryName : string = 'Index';
@Entry({routeName: entryName, storage : LocalStorage.getShared()})
@Component
export struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### on('windowStageEvent')<sup>9+</sup>

on(eventType: 'windowStageEvent', callback: Callback&lt;WindowStageEventType&gt;): void

Subscribes to the window stage lifecycle change event.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name      | Type                                                         | Mandatory | Description                                                  |
| --------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| eventType | string                                                       | Yes       | Event type. The value is fixed at **'windowStageEvent'**, indicating the window stage lifecycle change event. |
| callback  | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | Yes       | Callback used to return the window stage lifecycle state.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.                               |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.on('windowStageEvent', (data) => {
        console.info('Succeeded in enabling the listener for window stage event changes. Data: ' +
        JSON.stringify(data));
      });
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### off('windowStageEvent')<sup>9+</sup>

off(eventType: 'windowStageEvent', callback?: Callback&lt;WindowStageEventType&gt;): void

Unsubscribes from the window stage lifecycle change event.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name      | Type                                                         | Mandatory | Description                                                  |
| --------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| eventType | string                                                       | Yes       | Event type. The value is fixed at **'windowStageEvent'**, indicating the window stage lifecycle change event. |
| callback  | Callback&lt;[WindowStageEventType](#windowstageeventtype9)&gt; | No        | Callback used to return the window stage lifecycle state. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 1300002 | This window state is abnormal.                               |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    const callback = (windowStageEventType: window.WindowStageEventType) => {
      // ...
    }
    try {
      windowStage.on('windowStageEvent', callback);
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
    try {
      windowStage.off('windowStageEvent', callback);
      // Unregister all the callbacks that have been registered through on().
      windowStage.off('windowStageEvent');
    } catch (exception) {
      console.error(`Failed to disable the listener for window stage event changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### setDefaultDensityEnabled<sup>12+</sup>

setDefaultDensityEnabled(enabled: boolean): void

Enables the system's default density.

By default, the system's default density is not used, and the window layout changes with the system display size.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| enabled | boolean | Yes       | Whether to enable the system's default density. The value **true** means to enable the system's default density, and **false** means the opposite. When the system's default density is enabled, the window layout does not change with the system display size. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.log('onWindowStageCreate');
    try {
      windowStage.setDefaultDensityEnabled(true);
    } catch (exception) {
      console.error(`Failed to set default density enabled. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```
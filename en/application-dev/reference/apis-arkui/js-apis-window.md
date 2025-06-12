# @ohos.window (Window)

The Window module provides basic window management capabilities, such as creating and destroying the current window, setting properties for the current window, and managing and scheduling windows.

This module provides the following common window-related functionalities:

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
| TYPE_APP                            | 0      | Child window of an application.<br>**Model restriction**: This API can be used only in the FA model.                                                  |
| TYPE_SYSTEM_ALERT                   | 1      | System alert window.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 11.                               |
| TYPE_FLOAT<sup>9+</sup>             | 8      | Floating window.<br>**Model restriction**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| TYPE_DIALOG<sup>10+</sup>           | 16      | Modal window.<br>**Model restriction**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| TYPE_MAIN<sup>18+</sup>             | 32      | Main window of an application.<br>This window type cannot be used when creating a window. It is only for reading purposes in the return value of the **getWindowProperties** API.                              |

## Configuration<sup>9+</sup>

Describes the parameters for creating a child window or system window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Mandatory| Description                                                                         |
| ---------- | -------------------------- | -- |-----------------------------------------------------------------------------|
| name       | string                     | Yes| Name of the window.                                                                      |
| windowType | [WindowType](#windowtype7) | Yes| Window type.                                                                      |
| ctx        | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | No| Current application context. If no value is passed, no context is used.<br>In the FA model, do not pass in this parameter when creating a child window. Otherwise, an error is reported.<br>In the stage model, you must pass in this parameter when creating a floating window, modal window, or system window.|
| displayId  | number                     | No| ID of the current physical screen. If no value is passed, the default value **-1** is used. The value must be an integer.                                            |
| parentId   | number                     | No| ID of the parent window. If no value is passed, the default value **-1** is used. The value must be an integer.                                                          |
| decorEnabled<sup>12+</sup> | boolean | No| Whether the window decoration is enabled. This parameter is valid only when **windowType** is set to **TYPE_DIALOG**. The value **true** means that the window decoration is enabled, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|
| title<sup>12+</sup> | string| No| Title of the window when **decorEnabled** is set to **true**. The title display area should not go past the left side of the three-button area of the system. Any part that goes beyond will show as an ellipsis. If this parameter is not set, an empty string is used.<br>**System capability**: SystemCapability.Window.SessionManager|
| defaultDensityEnabled<sup>20+</sup> | boolean| No| Whether the window should use the default density of the system. If the default density is used, the window does not change layout when the system display size changes.<br>If this parameter is set to **true** for a system window, the window uses the default density and is not affected by [setDefaultDensityEnabled()](#setdefaultdensityenabled12) or [setCustomDensity()](#setcustomdensity15) settings for the main window.<br>If this parameter is set to **false**, the window does not use the default density and is affected by those settings.<br>The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|

## AvoidAreaType<sup>7+</sup>

Enumerates the types of areas that window content should avoid.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name                            | Value  | Description                                                        |
| -------------------------------- | ---- | ------------------------------------------------------------ |
| TYPE_SYSTEM                      | 0    | Default area of the system. <!--RP11-->It contains the status bar and three-button navigation bar.<!--RP11End-->       |
| TYPE_CUTOUT                      | 1    | Notch area.                                                             |
| TYPE_SYSTEM_GESTURE<sup>9+</sup> | 2    | Gesture area. Currently, no device has this type of avoid area.                                   |
| TYPE_KEYBOARD<sup>9+</sup>       | 3    | Soft keyboard area.                                                             |
| TYPE_NAVIGATION_INDICATOR<sup>11+</sup> | 4    | Bottom navigation bar. <!--RP12-->OpenHarmony devices do not support this capability.<!--RP12End-->                             |


## SystemBarProperties

Describes the properties of the status bar<!--Del--> and three-button navigation bar<!--DelEnd-->. It is used to set the window-level status bar<!--Del--> and three-button navigation bar<!--DelEnd--> properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                                  | Type|  Mandatory| Description                                                        |
| -------------------------------------- | -------- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   |  No  | Background color of the status bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. The default value is **'#66000000'**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isStatusBarLightIcon<sup>7+</sup>      | boolean  |  No  | Whether any icon on the status bar is highlighted. The value **true** means that the icon is highlighted, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| statusBarContentColor<sup>8+</sup>     | string   |  No  | Color of the text on the status bar. After this property is set, the setting of **isStatusBarLightIcon** is invalid. The default value is **'#E5FFFFFF'**.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| navigationBarColor                     | string   |  No  | Background color of the three-button navigation bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. The default value is **'#66000000'**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  |  No  | Whether any icon on the three-button navigation bar is highlighted. The value **true** means that the icon is highlighted, and **false** means the opposite. The default value is **false**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| navigationBarContentColor<sup>8+</sup> | string   |  No  | Color of the text on the three-button navigation bar. After this property is set, the setting of **isNavigationBarLightIcon** is invalid. The default value is **'#E5FFFFFF'**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| enableStatusBarAnimation<sup>12+</sup> | boolean   |  No  | Whether to enable animation for a status bar property change. The value **true** means to enable animation, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|
| enableNavigationBarAnimation<sup>12+</sup> | boolean   |  No  | Whether to enable animation for a three-button navigation bar property change. The value **true** means to enable animation, and **false** means the opposite. The default value is **false**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.Window.SessionManager|

## StatusBarProperty<sup>18+</sup>

Describes the properties of the status bar. These properties are returned when you query the status bar's configuration details.

**Atomic service API**: This API can be used in atomic services since API version 18.

| Name                                  | Type|  Mandatory| Description|
| ------------------------------------- | -------- | ---- |------- |
| contentColor     | string   |  Yes  | Color of the text on the status bar. The value is in ARGB format, for example, **#E5FFFFFF**.<br>**System capability**: SystemCapability.Window.SessionManager|

## SystemBarStyle<sup>12+</sup>

Describes the properties of the status bar. These properties are valid for the page-level status bar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Read-Only| Optional| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| statusBarContentColor   | string   | Yes  | Yes  | Color of the text on the status bar. The default value is **'#E5FFFFFF'**.|

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

- The bottom gesture area, apart from the bottom navigation bar area, supports transparent transmission of touch events, and touch and hold events, but not drag events.

- The gesture area on the left and right sides supports transparent transmission of touch events, touch and hold events, and swipe up and down events, but not drag events.

- The bottom navigation bar area supports responding to touch events, touch and hold events, and drag events. However, it does not support transparent transmission of events.

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

| Name                                 | Type                 | Read-Only| Optional| Description                                                                                                    |
| ------------------------------------- | ------------------------- | ---- | ---- |--------------------------------------------------------------------------------------------------------|
| windowRect<sup>7+</sup>               | [Rect](#rect7)             | No  | No  | Window size, which can be obtained from the page lifecycle [onPageShow](./arkui-ts/ts-custom-component-lifecycle.md#onpageshow) or the application lifecycle [onForeground](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground).<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                 |
| drawableRect<sup>11+</sup>            | [Rect](#rect7)             | No  | No  | Size of the rectangle that can be drawn in the window. The upper boundary and left boundary are calculated relative to the window. In the stage model, this API must be used after [loadContent()](#loadcontent9) or [setUIContent()](#setuicontent9) is called to load the page content.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                 |
| type<sup>7+</sup>                     | [WindowType](#windowtype7) | No  | No  | Window type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                 |
| isFullScreen                          | boolean                   | No  | No  | Whether the window is displayed in full-screen mode. The default value is **false**. The value **true** means that the window is displayed in full-screen mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                 |
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | No  | No  | Whether the window is immersive and in full-screen mode (not in floating window or split-screen scenarios). The default value is **false**. The value **true** means that the window is immersive and in full-screen mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                           |
| focusable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window can gain focus. The default value is **true**. The value **true** means that the window can gain focus, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                               |
| touchable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window is touchable. The default value is **true**. The value **true** means that the window is touchable, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                |
| brightness                            | number                    | No  | No  | Screen brightness. The value is a floating point number in the range [0.0, 1.0], and the value **1.0** means the brightest. If no value is passed, the brightness follows the system. In this case, the obtained brightness value is **-1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                     |
| dimBehindValue<sup>(deprecated)</sup> | number                    | No  | No  | Dimness of the window that is not on top. The value is a floating point number in the range [0.0, 1.0], and the value **1.0** means the dimmest.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9.<br>Currently, no substitute is available.|
| isKeepScreenOn                        | boolean                   | No  | No  | Whether the screen is always on. The default value is **false**. The value **true** means that the screen is always on, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                  |
| isPrivacyMode<sup>7+</sup>            | boolean                   | No  | No  | Whether the window is in privacy mode. The default value is **false**. The value **true** means that the window is in privacy mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                 |
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | No  | No  | Whether the window has rounded corners. The default value is **false**. The value **true** means that the window has rounded corners, and **false** means the opposite.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9.<br>Currently, no substitute is available.|
| isTransparent<sup>7+</sup>            | boolean                   | No  | No  | Whether the window background is transparent. The default value is **false**. The value **true** means that the window is transparent, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                  |
| id<sup>9+</sup>                       | number                    | Yes  | No  | Window ID. The default value is **0**. The value must be an integer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                   |
| displayId<sup>12+</sup>               | number                    | Yes  | Yes  | ID of the screen where the window is located. By default, the ID of the main screen is returned. The value must be an integer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| name<sup>18+</sup>               | string                    | Yes  | Yes  | Window name. The default value is an empty string.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## DecorButtonStyle<sup>14+</sup>

Describes the button style of the system decoration bar.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

| Name      | Type     | Readable| Writable| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| colorMode   | [ConfigurationConstant.ColorMode](../apis-ability-kit/js-apis-app-ability-configurationConstant.md#colormode) | Yes  | Yes  | Color mode. Buttons automatically adapt to light colors in dark mode and to dark colors in light mode. If this parameter is not set, they will automatically match the system color mode.|
| buttonBackgroundSize   | number        | Yes  | Yes  | Size of the button when it is highlighted. The value ranges from 20 vp to 40 vp. The default value is 28 vp.|
| spacingBetweenButtons  | number        | Yes  | Yes  | Spacing between buttons. The value ranges from 8 vp to 24 vp. The default value is 12 vp.|
| closeButtonRightMargin | number        | Yes  | Yes  | Margin between the rightmost edge of the close button and the window. The value ranges from 6 vp to 22 vp. The default value is 20 vp.|
| buttonIconSize<sup>20+</sup> | number        | Yes  | Yes  | Size of the button icon. The value ranges from 16 vp to 24 vp. The default value is 20 vp.|
| buttonBackgroundCornerRadius<sup>20+</sup> | number        | Yes  | Yes  | Radius of the button background rounded corner. The value ranges from 4 vp to 8 vp. The default value is 4 vp.|

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

Describes the window size limits. You can call [setWindowLimits](#setwindowlimits11) to set the window size limits and call [getWindowLimits](#getwindowlimits11) to obtain the current window size limits.

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

Describes the rectangle used to hold the minimize, maximize, and close buttons on the title bar. This rectangle is located in the upper right corner of the window.

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

**System capability**: SystemCapability.Window.SessionManager

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| FOLLOW_APP_IMMERSIVE_SETTING  | 0    | The window, when maximized, follows the immersive layout of the application.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| EXIT_IMMERSIVE | 1    | The window, when maximized, exits the immersive layout.<br>**Atomic service API**: This API can be used in atomic services since API version 12.            |
| ENTER_IMMERSIVE    | 2    | The window, when maximized, transitions into the immersive layout, and the window title bar and dock bar are displayed when the cursor hovers over the hot zone.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  |
| ENTER_IMMERSIVE_DISABLE_TITLE_AND_DOCK_HOVER<sup>14+</sup>    | 3    | The window, when maximized, transitions into the immersive layout, and the window title bar and dock bar are not displayed when the cursor hovers over the hot zone.<br>**Atomic service API**: This API can be used in atomic services since API version 14.  |

## MoveConfiguration<sup>15+</sup>

Describes the window movement configuration.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Mandatory| Description                                      |
| ------ | ------ | ---- | ------------------------------------------ |
| displayId | number | No| Target display ID. The value must be an integer. If a non-integer is passed in, the value is rounded down. If this parameter is passed in, the window is positioned relative to the upper left corner of the target display. If this parameter is left empty or the target display ID does not exist, the window is positioned relative to the upper left corner of the current display.|

## WindowDensityInfo<sup>15+</sup>

Describes the information about the display density of the screen where the window is located and the window's custom display density. It is a scale factor independent of pixel units, that is, a factor for scaling display size.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Readable| Writable| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| systemDensity  | number   | Yes  | No  | System's display size scale factor for the screen where the window is located. The value ranges from 0.5 to 4.0 and varies according to user settings.|
| defaultDensity | number   | Yes  | No  | Default display size scale factor for the screen where the window is located. The value ranges from 0.5 to 4.0 and varies with the screen.|
| customDensity | number   | Yes  | No  | Custom display size scale factor of the window. The value ranges from 0.5 to 4.0. If this parameter is left unspecified, the system's display size scale factor is used.|

## WindowLayoutInfo<sup>15+</sup>

Describes the information about the window layout.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Mandatory| Description                                      |
| ------ | ------ | ---- | ------------------------------------------ |
| windowRect<sup>15+</sup> | [Rect](#rect7)  | Yes| Window rectangle, that is, the position and size of the window on the display.|

## KeyboardInfo<sup>18+</sup>

Describes the information about the soft keyboard window.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Mandatory| Description                                      |
| ------ | ------ | ---- | ------------------------------------------ |
| beginRect | [Rect](#rect7)  | Yes| Position and size of the soft keyboard before the animation starts.|
| endRect | [Rect](#rect7)  | Yes| Position and size of the soft keyboard before the animation ends.|
| animated<sup>20+</sup> | boolean  | No| Whether there is a show/hide animation. The value **true** means that there is a show/hide animation, and **false** means the opposite.|
| config<sup>20+</sup> | [WindowAnimationConfig](#windowanimationconfig20)  | No| Animation configuration.|

## ShowWindowOptions<sup>20+</sup>

Describes the parameters for displaying a child window or system window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name  | Type  | Mandatory| Description                                      |
| ------ | ------ | ---- | ------------------------------------------ |
| focusOnShow | boolean  | No| Whether the window automatically gains focus when [showWindow()](#showwindow20) is called. The default is **true**. This parameter does not take effect for the main window, modal window, and dialog boxes.|

## WindowAnimationCurve<sup>20+</sup>

Enumerates the types of window animation curves.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name               | Value  | Description                                                        |
| ------------------- | ---- | ------------------------------------------------------------ |
| LINEAR              | 0    | The animation speed is constant from start to finish.<br>When this curve type is used, **duration** in [WindowAnimationConfig](#windowanimationconfig20) is mandatory.<br>When this curve type is used, **param** in [WindowAnimationConfig](#windowanimationconfig20) is optional and does not take effect.|
| INTERPOLATION_SPRING | 1    | Interpolator spring curve, an animation curve from 0 to 1, where the actual animation values are interpolated based on the curve. The animation duration is subject to the curve parameters, rather than the **duration** parameter in [WindowAnimationConfig](#windowanimationconfig20).<br>When this curve type is used, **duration** in [WindowAnimationConfig](#windowanimationconfig20) is optional and does not take effect.<br>When this curve type is used, **param** in [WindowAnimationConfig](#windowanimationconfig20) is mandatory.|

## WindowAnimationConfig<sup>20+</sup>

Describes the configuration for window animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name    | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| curve    | [WindowAnimationCurve](#windowanimationcurve20)           | Yes  | Type of animation curve.                                              |
| duration | number                                                    | No  | Duration for playing the animation, in milliseconds (ms).<br>The default value is 0, and the maximum value is 3000.<br>Whether it is required depends on the animation curve type.|
| param    | [WindowAnimationCurveParam](#windowanimationcurveparam20) | No  | Parameters for the animation curve. Whether it is required depends on the animation curve type.                |

## WindowAnimationCurveParam<sup>20+</sup>

type WindowAnimationCurveParam = Array&lt;number&gt;

Defines the parameters for the animation curve. The meaning of **WindowAnimationCurveParam** varies depending on the type of [WindowAnimationCurve](#windowanimationcurve20).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

When the curve type is **LINEAR**, **WindowAnimationCurveParam** is optional and have no effect.

When the curve type is **INTERPOLATION_SPRING**, **WindowAnimationCurveParam** must be set as an array of length 4: [velocity,mass,stiffness,damping].

- **velocity**: initial velocity, which is of the number type. This parameter is mandatory.

  It describes the impact of external factors to the spring animation, designed to help ensure smooth transition from the previous motion state. This is a normalized velocity, and it is calculated as the actual initial velocity divided by the change in the animation property.

- **mass**: mass, which is of the number type. This parameter is mandatory. The value range is (0, +∞). If the value is less than or equal to 0, the value **1** is used.

  It describes the inertia of the object in the elastic system, affecting the amplitude of oscillation and the speed of return to equilibrium. The greater the mass, the greater the amplitude of the oscillation, and the slower the speed of restoring to the equilibrium position.

- **stiffness**: stiffness, which is of the number type. This parameter is mandatory. The value range is (0, +∞). If the value is less than or equal to 0, the value **1** is used.

  It describes the degree to which an object deforms by resisting the force applied. In an elastic system, the greater the stiffness, the stronger the capability to resist deformation, and the faster the speed of restoring to the equilibrium position.

- **damping**: damping, which is of the number type. This parameter is mandatory. The value range is (0, +∞). If the value is less than or equal to 0, the value **1** is used.

  It is used to describe the oscillation and attenuation of the system after being disturbed. The larger the damping, the smaller the number of oscillations of elastic motion, and the smaller the oscillation amplitude.


## WindowInfo<sup>18+</sup>

Describes the window information.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| rect  | [Rect](js-apis-window.md#rect7)   | Yes  | No  | Window size.|
| bundleName  | string   | Yes  | No  | Bundle name of the application.         |
| abilityName | string   | Yes  | No  | Ability name.              |
| windowId | number | Yes  | No  | Window ID.  |
| windowStatusType | [WindowStatusType](js-apis-window.md#windowstatustype11) | Yes  | No  | Window mode.  |
| isFocused | boolean | Yes  | Yes  | Whether the window gains focus. The value **true** means that the window gains focus, and **false** means the opposite.  |

## WindowTransitionType<sup>20+</sup>

Enumerates the types of window transition animations.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name   | Value  | Description                      |
| ------- | ---- | -------------------------- |
| DESTROY | 0    | Transition animation when the window is destroyed.|

## TransitionAnimation<sup>20+</sup>

Describes the window transition animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name   | Type                                             | Mandatory| Description                                                        |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| config  | [WindowAnimationConfig](#windowanimationconfig20) | Yes  | Transition animation configuration.                                          |
| opacity | number                                            | No  | Opacity of the window during the transition animation. If this parameter is set to **0**, the window is completely transparent. When the animation type is **WindowTransitionType.DESTROY**, this represents the opacity at the end of the animation. The value ranges from 0 to 1. The value is reset to **1** when the animation ends.|

## WindowAnchor<sup>20+</sup>

Enumerates the window anchor points.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name      | Value  | Description                         |
| ---------- | ---- | ----------------------------- |
| TOP_START  | 0    | Top left corner of the window.|
| TOP  | 1    | Horizontal center point along the top edge of the window.|
| TOP_END  | 2    | Top right corner of the window.|
| START  | 3    | Vertical center point along the left edge of the window.|
| CENTER  | 4    | Center point of the window, both horizontally and vertically.|
| END  | 5    | Vertical center point along the right edge of the window.|
| BOTTOM_START  | 6    | Bottom left corner of the window.|
| BOTTOM  | 7    | Horizontal center point along the bottom edge of the window.|
| BOTTOM_END  | 8    | Bottom right corner of the window.|

## Callback<sup>15+</sup>

### (data: T)<sup>15+</sup>

(data: T): V;

Describes a generic callback function.

You can set **data** to customize the parameter type of the information returned by the callback.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | -------------------------- |
| data | T    | Yes  | Parameter of type T that needs to be passed when the callback function is called.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------ |
| V | Value of type V.|

## RotationChangeType<sup>19+</sup>

Enumerates the types of window rotation events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

| Name  |  Value| Description                  |
| ------ | ---- | --------------------- |
| WINDOW_WILL_ROTATE| 0 | The window is about to rotate.|
| WINDOW_DID_ROTATE | 1 | The window has finished rotating.|

## RectType<sup>19+</sup>

Enumerates the types of window rectangle coordinate systems.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Value| Description                  |
| ------ | ---- | --------------------- |
| RELATIVE_TO_SCREEN | 0 | The window rectangle is relative to the screen coordinate system.|
| RELATIVE_TO_PARENT_WINDOW | 1 | The window rectangle is relative to the parent window coordinate system.|

## RotationChangeInfo<sup>19+</sup>

Describes the window information obtained during window rotation changes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| type | [RotationChangeType](#rotationchangetype19) | Yes| No| Type of window rotation event.|
| orientation | number | Yes| No| Display orientation of the window.<br>- **0**: portrait.<br>- **1**: reverse landscape.<br>- **2**: reverse portrait.<br>- **3**: landscape.<br>Note that the orientation here is different from the orientation property of the display object.|
| displayId | number | Yes| No| ID of the screen where the window is located.|
| displayRect | [Rect](#rect7) | Yes| No| Size of the rectangle after the screen where the window is located is rotated.|

## RotationChangeResult<sup>19+</sup>

Describes the information returned by the application during window rotation changes.

The system uses the information to adjust the size of the current window rectangle. If the returned information is about the rotation change of the main window, the system does not change the size of the main window.

There are limitations on the size of application windows and system windows. For details about specific restrictions and rules, see [resize](#resize9).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| rectType | [RectType](#recttype19) | No| No| Type of window rectangle coordinate system.|
| windowRect | [Rect](#rect7) | No| No| Information about the window's rectangle relative to the screen or parent window coordinate system.|

## RotationChangeCallback<sup>19+</sup>

### (info: T)<sup>19+</sup>

(info: T): U;

Describes a generic callback function for rotation event notifications.

In this callback function, the parameter type is [RotationChangeInfo](#rotationchangeinfo19), and the return value type is [RotationChangeResult](#rotationchangeresult19)\|void.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | -------------------------- |
| info | T    | Yes  | Parameter of type [RotationChangeInfo](#rotationchangeinfo19) passed by the system when the callback function is called.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------ |
| U | Value of type [RotationChangeResult](#rotationchangeresult19)\|void.| |

## GlobalWindowMode<sup>20+</sup>

Enumerates the window modes.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Value| Type | Description                   |
| ------ | --- | --- | ------------------------ |
| FULLSCREEN | 1 | number | Full-screen window.|
| SPLIT  | 1 << 1 | number | Split-screen window.|
| FLOAT   | 1 << 2  | number | Floating window.|
| PIP   | 1 << 3  | number | PiP.|

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration, callback: AsyncCallback&lt;Window&gt;): void

Creates a child window or system window. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW (required only when the window type is **window.WindowType.TYPE_FLOAT**.)

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
| 801     | Capability not supported. createWindow can not work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
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
  }
}
```

## window.createWindow<sup>9+</sup>

createWindow(config: Configuration): Promise&lt;Window&gt;

Creates a child window or system window. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SYSTEM_FLOAT_WINDOW (required only when the window type is **window.WindowType.TYPE_FLOAT**.)

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
| 801     | Capability not supported. createWindow can not work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300006 | This window context is abnormal. |
| 1300009 | The parent window is invalid. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    let config: window.Configuration = {
      name: "test",
      windowType: window.WindowType.TYPE_DIALOG,
      ctx: this.context,
      defaultDensityEnabled: true
    };
    try {
      window.createWindow(config).then((value:window.Window) => {
        console.info('Succeeded in creating the window. Data: ' + JSON.stringify(value));
        value.resize(500, 1000);
      }).catch((err:BusinessError)=> {
        console.error(`Failed to create the window. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to create the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
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

Obtains the topmost layer child window of the current application. This API uses an asynchronous callback to return the result.

If no child window exists or the child window is not displayed by calling [showWindow()](#showwindow9), the main window of the application is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------------------------- | -- | ---------------------------------------- |
| ctx      | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes| Current application context.|
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes| Callback used to return the topmost layer window obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Top window or main window is null or destroyed.  |
| 1300006 | This window context is abnormal. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.createSubWindow('TestSubWindow').then((subWindow) => {
      subWindow.showWindow().then(() => {
        try {
          window.getLastWindow(this.context, (err: BusinessError, topWindow) => {
            const errCode: number = err.code;
            if (errCode) {
              console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
              return;
            }
            console.info(`Succeeded in obtaining the top window. Window id: ${topWindow.getWindowProperties().id}`);
          });
        } catch (exception) {
          console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`);
        }
      });
    });
  }
  //...
}
```

## window.getLastWindow<sup>9+</sup>

getLastWindow(ctx: BaseContext): Promise&lt;Window&gt;

Obtains the topmost layer child window of the current application. This API uses a promise to return the result.

If no child window exists or the child window is not displayed by calling [showWindow()](#showwindow9), the main window of the application is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ----------- | ---- | ------------------------------------------------------------ |
| ctx    | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current application context.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the topmost layer window obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. Top window or main window is null or destroyed.   |
| 1300006 | This window context is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    windowStage.createSubWindow('TestSubWindow').then((subWindow) => {
      subWindow.showWindow().then(() => {
        try {
          window.getLastWindow(this.context).then((topWindow) => {
            console.info(`Succeeded in obtaining the top window. Window id: ${topWindow.getWindowProperties().id}`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
          });
        } catch (exception) {
          console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`);
        }
      });
    });
  }
  //...
}
```

## window.shiftAppWindowFocus<sup>11+</sup>
shiftAppWindowFocus(sourceWindowId: number, targetWindowId: number): Promise&lt;void&gt;

Shifts the window focus from the source window to the target window in the same application. The window focus can be shifted between the main window and a child window.

Ensure that the focusable property of the target window is **true** (see [setWindowFocusable()](#setwindowfocusable9)) and that [showWindow()](#showwindow9) is successfully executed.

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
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // ...
    console.info('onWindowStageCreate');
    let mainWindow: window.Window | undefined = undefined;
    let subWindow: window.Window | undefined = undefined;
    let mainWindowId: number = -1;
    let subWindowId: number = -1;

    try {
      // Obtain the main window and ID of the application.
      windowStage.getMainWindow().then((data) => {
        if (data == null) {
          console.error('Failed to obtain the main window. Cause: The data is empty');
          return;
        }
        mainWindow = data;
        mainWindowId = mainWindow.getWindowProperties().id;
        console.info('Succeeded in obtaining the main window');
      }).catch((err: BusinessError) => {
        console.error(`Failed to obtain the main window. Cause code: ${err.code}, message: ${err.message}`);
      });

      // Create or obtain a child window and its ID. In this case, the child window has focus.
      windowStage.createSubWindow('testSubWindow').then((data) => {
        if (data == null) {
          console.error('Failed to obtain the sub window. Cause: The data is empty');
          return;
        }
        subWindow = data;
        subWindowId = subWindow.getWindowProperties().id;
        subWindow.resize(500, 500);
        subWindow.showWindow();

        // Listen for the window status and ensure that the window is ready.
        subWindow.on("windowEvent", (windowEvent) => {
          if (windowEvent == window.WindowEventType.WINDOW_ACTIVE) {
            // Switch the focus.
            window.shiftAppWindowFocus(subWindowId, mainWindowId).then(() => {
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

## window.shiftAppWindowPointerEvent<sup>15+</sup>
shiftAppWindowPointerEvent(sourceWindowId: number, targetWindowId: number): Promise&lt;void&gt;

Transfers an input event from one window to another within the same application, particularly in split-window scenarios. This API uses a promise to return the result. It takes effect only for the main window and its child windows on 2-in-1 devices.

On 2-in-1 devices, the source window must be in a mouse-down state for this API to work; otherwise, the call does not take effect. After the input event is transferred, a mouse-up event is sent to the source window, and a mouse-down event is sent to the target window.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | Yes   | ID of the source window. You are advised to call [getWindowProperties()](#getwindowproperties9) to obtain the window ID.           |
| targetWindowId | number | Yes   | ID of the target window. You are advised to call [getWindowProperties()](#getwindowproperties9) to obtain the window ID.            |

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
// ets/pages/Index.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
struct Index {
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Blue)
          .onTouch((event: TouchEvent) => {
            if (event.type === TouchType.Down) {
              try {
                let sourceWindowId = 1;
                let targetWindowId = 2;
                let promise = window.shiftAppWindowPointerEvent(sourceWindowId, targetWindowId);
                promise.then(() => {
                  console.info('Succeeded in shifting app window pointer event');
                }).catch((err: BusinessError) => {
                  console.error(`Failed to shift app window pointer event. Cause code: ${err.code}, message: ${err.message}`);
                });
              } catch (exception) {
                console.error(`Failed to shift app pointer event. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

## window.shiftAppWindowTouchEvent<sup>20+</sup>
shiftAppWindowTouchEvent(sourceWindowId: number, targetWindowId: number, fingerId: number): Promise&lt;void&gt;

Moves touch screen input events from one window to another in scenarios where windows within the same application are being split or merged. This API uses a promise to return the result. It takes effect only for the main window and its child windows on 2-in-1 devices.

On 2-in-1 devices, to transfer touch screen input events, the source window must call this API within the callback of the [onTouch](arkui-ts/ts-universal-events-touch.md#touchevent) event (the event type must be **TouchType.Down**). After a successful call, the system sends a touch-up event to the source window and a touch-down event to the target window.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type  | Mandatory | Description                   |
| -------------- | ------ | ----- | ----------------------- |
| sourceWindowId | number | Yes   | ID of the source window. You are advised to call [getWindowProperties()](#getwindowproperties9) to obtain the window ID.           |
| targetWindowId | number | Yes   | ID of the target window. You are advised to call [getWindowProperties()](#getwindowproperties9) to obtain the window ID.            |
| fingerId | number | Yes   | Finger ID of the touch event. You are advised to use the [touches](arkui-ts/ts-universal-events-touch.md#touchobject) property in the [touchEvent](arkui-ts/ts-universal-events-touch.md#touchevent) event to obtain the ID.            |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| ------- | --------------------------------------------- |
| 801     | Capability not supported. Function shiftAppWindowTouchEvent can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range.|

**Example**

```ts
// ets/pages/Index.ets
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
struct Index {
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Blue)
          .onTouch((event: TouchEvent) => {
            // The source window touch event type must be TouchType.Down.
            if (event.type === TouchType.Down) {
              try {
                let sourceWindowId = 1;
                let targetWindowId = 2;
                let promise = window.shiftAppWindowTouchEvent(sourceWindowId, targetWindowId, event.touches[0].id);
                promise.then(() => {
                  console.info(`Succeeded in shifting app window touch event`);
                }).catch((err: BusinessError) => {
                  console.error(`Failed to shift app window touch event. Cause code: ${err.code}, message: ${err.message}`);
                });
              } catch (exception) {
                console.error(`Failed to shift app touch event. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

## window.getWindowsByCoordinate<sup>14+</sup>

getWindowsByCoordinate(displayId: number, windowNumber?: number, x?: number, y?: number): Promise&lt;Array&lt;Window&gt;&gt;

Obtains visible windows at the specified coordinates within the current application, sorted by their current layer order. The window at the topmost layer corresponds to index 0 of the array. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type  | Mandatory| Description                                                                       |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| displayId   | number| Yes | ID of the display where the windows are located. The value must be an integer and can be obtained from [WindowProperties](#windowproperties).|
| windowNumber    | number| No | Number of windows to obtain. The value must be an integer greater than 0. If this parameter is not set or is less than or equal to 0, all windows that meet the conditions are returned.                                 |
| x    | number | No | X coordinate. The value must be a non-negative integer. If this parameter is not set or is less than 0, all visible windows are returned.                                        |
| y    | number| No | Y coordinate. The value must be a non-negative integer. If this parameter is not set or is less than 0, all visible windows are returned.                                        |

**Return value**

| Type                            | Description                     |
| -------------------------------- |-------------------------|
| Promise&lt;Array&lt;[Window](#window)&gt;&gt; | Promise used to return an array of window objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID   | Error Message|
|----------| ------------------------------ |
| 401      | Parameter error. Possible cause: Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      let windowClass = windowStage.getMainWindowSync();
      let properties = windowClass.getWindowProperties();
      window.getWindowsByCoordinate(properties.displayId).then((data) => {
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        for (let window of data) {
          // do something with window
        }
      }).catch((err: BusinessError) => {
        console.error(`Failed to get window from point. Cause code: ${err.code}, message: ${err.message}`);
      });
      window.getWindowsByCoordinate(properties.displayId, 2, 500, 500).then((data) => {
        console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
        for (let window of data) {
          // do something with window
        }
      }).catch((err: BusinessError) => {
        console.error(`Failed to get window from point. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to get window from point. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

## window.getAllWindowLayoutInfo<sup>15+</sup>

getAllWindowLayoutInfo(displayId: number): Promise&lt;Array&lt;WindowLayoutInfo&gt;&gt;

Obtains the layout information array of all windows visible on a display. The layout information is arranged based on the current window stacking order, and the topmost window in the hierarchy is at index 0 of the array. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type  | Mandatory| Description                                                                       |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| displayId   | number| Yes | ID of the display where the windows are located. The value must be an integer and can be obtained from [WindowProperties](#windowproperties).|

**Return value**

| Type                            | Description                     |
| -------------------------------- |-------------------------|
| Promise&lt;Array&lt;[WindowLayoutInfo](#windowlayoutinfo15)&gt;&gt; | Promise used to return an array of window layout information objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID   | Error Message|
|----------| ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|
| 801      | Capability not supported. function getAllWindowLayoutInfo can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let displayId = 0;
  let promise = window.getAllWindowLayoutInfo(displayId);
  promise.then((data) => {
    console.info('Succeeded in obtaining all window layout info. Data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain all window layout info. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to obtain all window layout info. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.getGlobalWindowMode<sup>20+</sup>

getGlobalWindowMode(displayId?: number): Promise&lt;number&gt;

Obtains the window mode of the window that is in the foreground lifecycle on the specified screen. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type  | Mandatory| Description                                                                       |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| displayId   | number| No | Optional display ID, which is used to obtain the window mode information on the corresponding screen. This parameter must be an integer greater than or equal to 0. If it is less than 0, error code 1300016 is returned. If this parameter is not passed or is set to null or undefined, all screens are queried. If the specified screen does not exist, the return value is 0.|

**Return value**

| Type                            | Description                     |
| -------------------------------- |-------------------------|
| Promise&lt;number&gt; | Promise used to return the window mode. Each binary bit represents a window mode. For details about the supported window modes, see [GlobalWindowMode](#globalwindowmode20). The return value is the result of a bitwise OR operation on the corresponding window mode values. For example, if there are full-screen, floating, and PiP windows on the specified screen, the return value is `0b1\|0b100\|0b1000 = 13`.| | |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID   | Error Message|
|----------| ------------------------------ |
| 801      | Capability not supported. function getGlobalWindowMode can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

```ts
import { window } from '@ohos.window';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let displayId = 0;
  let promise = window.getGlobalWindowMode(displayId);
  promise.then((data) => {
    console.info(`Succeeded in obtaining global window mode. Data: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain global window mode. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to obtain global window mode. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.create<sup>(deprecated)</sup>

create(id: string, type: WindowType, callback: AsyncCallback&lt;Window&gt;): void

Creates a child window. This API uses an asynchronous callback to return the result.

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
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes  | Callback used to return the child window created.|


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

Creates a child window. This API uses a promise to return the result.

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
| Promise&lt;[Window](#window)&gt; | Promise used to return the child window created.|


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
| callback | AsyncCallback&lt;[Window](#window)&gt;                  | Yes  | Callback used to return the child window created.|


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
| Promise&lt;[Window](#window)&gt; | Promise used to return the child window created.|


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

## window.getVisibleWindowInfo<sup>18+</sup>

getVisibleWindowInfo(): Promise&lt;Array&lt;WindowInfo&gt;&gt;

Obtains information about visible main windows on the current screen. Visible main windows are main windows that are not returned to the background. This API uses a promise to return the result.

**System capability**: SystemCapability.Window.SessionManager

**Required permissions**: ohos.permission.VISIBLE_WINDOW_INFO

**Return value**

| Type| Description|
| ------------------- | ----------------------- |
| Promise&lt;Array&lt;[WindowInfo](#windowinfo18)&gt;&gt; | Promise used to return the information about visible windows.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 801     | Capability not supported. Function getVisibleWindowInfo can not work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
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
      console.info(`isFocused:${windowInfo.isFocused}`);
    })
  }).catch((err: BusinessError) => {
    console.error('Failed to getWindowInfo. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error(`Failed to get visible window info. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## SpecificSystemBar<sup>11+</sup>

type SpecificSystemBar = 'status' \| 'navigation' \| 'navigationIndicator'

Defines the type of system bar that can be displayed or hidden.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 11.

| Type      | Description    |
|------------|--------|
| 'status'   | Status bar.  |
| 'navigation'   | <!--RP13--><!--RP13End-->Three-button navigation bar.  |
| 'navigationIndicator'   | Bottom navigation bar. <!--RP12-->OpenHarmony devices do not support this capability.<!--RP12End--> |

## Window

Represents a window instance, which is the basic unit managed by the window manager.

In the following API examples, you must use [getLastWindow()](#windowgetlastwindow9), [createWindow()](#windowcreatewindow9), or [findWindow()](#windowfindwindow9) to obtain a **Window** instance (named windowClass in this example) and then call a method in this instance.

### showWindow<sup>9+</sup>

showWindow(callback: AsyncCallback&lt;void&gt;): void

Shows this window. This API uses an asynchronous callback to return the result. This API takes effect only for a system window or an application child window. For the main window of an application, this API moves it at the top when the main window is already displayed.

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

Shows this window. This API uses a promise to return the result. This API takes effect only for a system window or an application child window. For the main window of an application, this API moves it at the top when the main window is already displayed.

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

### showWindow<sup>20+</sup>

showWindow(options: ShowWindowOptions): Promise&lt;void&gt;

Shows this window. This API uses a promise to return the result. This API takes effect only for a system window or an application child window. For the main window of an application, this API moves it at the top when the main window is already displayed. You can pass parameters to control the window display behavior.

**System capability**: SystemCapability.WindowManager.WindowManager 

**Atomic service API**: This API can be used in atomic services since API version 20.

**Return value**

| Type| Description|
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Function showWindow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |
| 1300016     | Parameter validation error. Possible cause: 1. The value of the parameter is out of the allowed range; 2. The length of the parameter exceeds the allowed length; 3. The parameter format is incorrect. |

**Example**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    // Create a child window.
    try {
      windowStage.createSubWindow('subWindow').then((data) => {
        if (data == null) {
          console.error('Failed to create the sub window. Cause: The data is empty');
          return;
        }
        let options: window.ShowWindowOptions = {
          focusOnShow: false
        };
        try {
          data.showWindow(options).then(() => {
            console.info('Succeeded in showing window');
          }).catch((err: BusinessError) => {
            console.error(`Failed to show window. Cause code: ${err.code}, message: ${err.message}`);
          });
        } catch (exception) {
          console.error(`Failed to show window. Cause code: ${exception.code}, message: ${exception.message}`);
        }
      });
    } catch (exception) {
      console.error(`Failed to create the sub window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### destroyWindow<sup>9+</sup>

destroyWindow(callback: AsyncCallback&lt;void&gt;): void

Destroys this window. This API uses an asynchronous callback to return the result. This API takes effect only for a system window or an application child window.

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

Destroys this window. This API uses a promise to return the result. This API takes effect only for a system window or an application child window.

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

On 2-in-1 devices, the window moves relative to the display. On other devices, the window moves relative to the parent window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------- | -- | --------------------------------------------- |
| x        | number                    | Yes| Coordinate position along the x-axis to which the window is moved, measured in px. A positive value means the position is to the right of the x-axis origin; a negative value means it is to the left; the value **0** means it is at the x-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| y        | number                    | Yes| Coordinate position along the y-axis to which the window is moved, measured in px. A positive value means the position is below the y-axis origin; a negative value means it is above; the value **0** means it is at the y-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
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

Moves this window. This API uses a promise to return the result. A value is returned once the API is called successfully. However, the final effect cannot be obtained immediately from the return value. To obtain the final effect immediately, call [moveWindowToAsync()](#movewindowtoasync12).

<!--RP4-->
In full-screen mode, this API takes effect only on 2-in-1 devices.<!--RP4End-->

For this API, the window moves relative to the display on 2-in-1 devices and to the parent window on other devices. If you want to move the window relative to the display on non-2-in-1 devices, use the [moveWindowToGlobal()](#movewindowtoglobal15) API.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Coordinate position along the x-axis to which the window is moved, measured in px. A positive value means the position is to the right of the x-axis origin; a negative value means it is to the left; the value **0** means it is at the x-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| y | number | Yes| Coordinate position along the y-axis to which the window is moved, measured in px. A positive value means the position is below the y-axis origin; a negative value means it is above; the value **0** means it is at the y-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down.|

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

A value is returned once the call takes effect. You can use [getWindowProperties()](#getwindowproperties9) in the callback (see the code snippet below) to obtain the final effect immediately.

This API takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode).

On 2-in-1 devices, the window moves relative to the display. On other devices, the window moves relative to the parent window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Coordinate position along the x-axis to which the window is moved, measured in px. A positive value means the position is to the right of the x-axis origin; a negative value means it is to the left; the value **0** means it is at the x-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| y | number | Yes| Coordinate position along the y-axis to which the window is moved, measured in px. A positive value means the position is below the y-axis origin; a negative value means it is above; the value **0** means it is at the y-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down.|

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
| 1300010 | The operation in the current window status is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.moveWindowToAsync(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### moveWindowToAsync<sup>15+</sup>

moveWindowToAsync(x: number, y: number, moveConfiguration?: MoveConfiguration): Promise&lt;void&gt;

Moves this window. This API uses a promise to return the result. A value is returned once the call takes effect. You can use [getWindowProperties()](#getwindowproperties9) in the callback (see the code snippet below) to obtain the final effect immediately.

This API takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode).

On 2-in-1 devices, the window moves relative to the display. On other devices, the window moves relative to the parent window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 15.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Distance that the window moves along the x-axis, in px. A positive value indicates that the window moves to the right. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| y | number | Yes| Distance that the window moves along the y-axis, in px. A positive value indicates that the window moves downwards. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| moveConfiguration | [MoveConfiguration](#moveconfiguration15) | No| Window movement configuration. If this parameter is not set, the window will stay on the current display.|

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
| 1300010 | The operation in the current window status is invalid. |

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let moveConfiguration: window.MoveConfiguration = {
    displayId: 0
  };
  let promise = windowClass.moveWindowToAsync(300, 300, moveConfiguration);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### moveWindowToGlobal<sup>13+</sup>

moveWindowToGlobal(x: number, y: number): Promise&lt;void&gt;

Moves this window based on the coordinates. This API uses a promise to return the result. A value is returned once the call takes effect. You can use [getWindowProperties()](#getwindowproperties9) in the callback (see the code snippet below) to obtain the final effect immediately.

This operation is not supported in a window in full-screen mode.

On non-2-in-1 devices, the child window moves along with the main window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 13.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Distance that the window moves along the x-axis, in px, with the upper left corner of the display used as the origin. A positive value indicates that the window moves to the right, and a negative value indicates that the window moves to the left. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| y | number | Yes| Distance that the window moves along the y-axis, in px, with the upper left corner of the display used as the origin. A positive value indicates that the window moves downwards, and a negative value indicates that the window moves upwards. The value must be an integer. If a non-integer is passed in, the value is rounded down.|

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
| 1300010 | The operation in the current window status is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.moveWindowToGlobal(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### moveWindowToGlobal<sup>15+</sup>

moveWindowToGlobal(x: number, y: number, moveConfiguration?: MoveConfiguration): Promise&lt;void&gt;

Moves this window based on the coordinates. This API uses a promise to return the result. A value is returned once the call takes effect. You can use [getWindowProperties()](#getwindowproperties9) in the callback (see the code snippet below) to obtain the final effect immediately.

This operation is not supported in a window in full-screen mode.

On non-2-in-1 devices, the child window moves along with the main window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 15.

**Parameters**

| Name| Type| Mandatory| Description|
| -- | ----- | -- | --------------------------------------------- |
| x | number | Yes| Distance that the window moves along the x-axis, in px, with the upper left corner of the target display used as the origin. A positive value indicates that the window moves to the right, and a negative value indicates that the window moves to the left. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| y | number | Yes| Distance that the window moves along the y-axis, in px, with the upper left corner of the target display used as the origin. A positive value indicates that the window moves downwards, and a negative value indicates that the window moves upwards. The value must be an integer. If a non-integer is passed in, the value is rounded down.|
| moveConfiguration | [MoveConfiguration](#moveconfiguration15) | No| Window movement configuration. If this parameter is not set, the window will stay on the current display.|

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
| 1300010 | The operation in the current window status is invalid. |

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let moveConfiguration: window.MoveConfiguration = {
    displayId: 0
  };
  let promise = windowClass.moveWindowToGlobal(300, 300, moveConfiguration);
  promise.then(() => {
    console.info('Succeeded in moving the window.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to move the window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to move the window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### resize<sup>9+</sup>

resize(width: number, height: number, callback: AsyncCallback&lt;void&gt;): void

Changes the size of this window. This API uses an asynchronous callback to return the result.

The main window and child window have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.

The minimum width and height of the main window and child window of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: (0, 1920] in width and (0, 1920] in height, both in units of vp.

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

A value is returned once the API is called successfully. However, the final effect cannot be obtained immediately from the return value. To obtain the final effect immediately, call [resizeAsync()](#resizeasync12).

The main window and child window have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.

The minimum width and height of the main window and child window of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: (0, 1920] in width and (0, 1920] in height, both in units of vp.

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

A value is returned once the call takes effect. You can use [getWindowProperties()](#getwindowproperties9) in the callback (see the code snippet below) to obtain the final effect immediately.

The main window and child window have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.

The minimum width and height of the main window and child window of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: (0, 1920] in width and (0, 1920] in height, both in units of vp.

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
| 1300010 | The operation in the current window status is invalid. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let promise = windowClass.resizeAsync(500, 1000);
  promise.then(() => {
    console.info('Succeeded in changing the window size.');
    let rect = windowClass?.getWindowProperties().windowRect;
    console.info(`Get window rect: ` + JSON.stringify(rect));
  }).catch((err: BusinessError) => {
    console.error(`Failed to change the window size. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to change the window size. Cause code: ${exception.code}, message: ${exception.message}`);
}
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

### getWindowDensityInfo<sup>15+</sup>

getWindowDensityInfo(): WindowDensityInfo

Obtains the display density information of this window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 15.

**Return value**

| Type| Description|
| ------------------------------------- | ------------- |
| [WindowDensityInfo](#windowdensityinfo15) | Display density information of the window. If the return value is [-1, -1, -1], the current device does not support this API.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
try {
  let densityInfo = windowClass.getWindowDensityInfo();
} catch (exception) {
  console.error(`Failed to obtain the window densityInfo. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getGlobalRect<sup>13+</sup>

getGlobalRect(): Rect

Obtains the actual display area of this window on the screen. This API returns the result synchronously.

This API can determine the actual on-screen location and size of a window that has been resized on certain devices.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 13.

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| [Rect](#rect7) | A set of four values, which indicates the horizontal distance from the screen's top-left corner to the window's left edge, the vertical distance from the screen's top-left corner to the window's top edge, the width of the window after scaling, and the height of the window after scaling.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
try {
  let rect = windowClass.getGlobalRect();
  console.info(`Succeeded in getting window rect: ` + JSON.stringify(rect));
} catch (exception) {
  console.error(`Failed to get window rect. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getWindowAvoidArea<sup>9+</sup>

getWindowAvoidArea(type: AvoidAreaType): AvoidArea

Obtains the avoid area of this application window, for example, the system bar area, notch, gesture area, and soft keyboard area.

This API is typically used in three scenarios: 1. In the **onWindowStageCreate** callback, this API can be used to obtain the avoid area in the initial layout during application startup. 2. When a child window needs to be temporarily displayed and requires layout adjustments for the content, this API can be used. 3. After you create a floating window, modal window, or system window (**WindowType** is a system window) and call [setSystemAvoidAreaEnabled](#setsystemavoidareaenabled18) to enable the such window to access the avoid area, this API can be used.

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

### setSystemAvoidAreaEnabled<sup>18+</sup>

setSystemAvoidAreaEnabled(enabled: boolean): Promise&lt;void&gt;

Enables the window to access the [avoid area](#avoidarea7) when you create a floating window, modal window, or system window (**WindowType** is a system window).

This API is particularly useful in the following scenario: After creating the aforementioned types of windows, you should call this API to enable the window to access the avoid area before calling [getWindowAvoidArea()](#getwindowavoidarea9) or [on('avoidAreaChange')](#onavoidareachange9) to obtain the avoid area or listen for changes in the avoid area.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name| Type| Mandatory| Description|
| ---- |----------------------------------| -- | ------------------------------------------------------------ |
| enabled | boolean | Yes| Whether the window is enabled to access the avoid area.<br>The value **true** means to enable the window to access the avoid area, and **false** means the opposite. The default value is **false**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "test",
  windowType: window.WindowType.TYPE_DIALOG,
  decorEnabled: true,
  ctx: this.context
};
try {
  window.createWindow(config, (err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to create the system window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    windowClass = data;
    windowClass.setUIContent("pages/Test");
    let enabled = true;
    let promise = windowClass.setSystemAvoidAreaEnabled(enabled);
    promise.then(() => {
      let type = window.AvoidAreaType.TYPE_SYSTEM;
      let avoidArea = windowClass?.getWindowAvoidArea(type);
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain the system window avoid area. Cause code: ${err.code}, message: ${err.message}`);
    });
  });
} catch (exception) {
  console.error(`Failed to create the system window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### isSystemAvoidAreaEnabled<sup>18+</sup>

isSystemAvoidAreaEnabled(): boolean

Checks whether a floating window, modal window, or system window (**WindowType** is a system window) is enabled to access the [avoid area](#avoidarea7).

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 18.

**Return value**

| Type| Description|
| ------------------------------------- | ------------- |
| boolean | Check result.<br>The value **true** means that the window is enabled to access the avoid area, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "test",
  windowType: window.WindowType.TYPE_DIALOG,
  decorEnabled: true,
  ctx: this.context
};
try {
  window.createWindow(config, (err: BusinessError, data) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to create the system window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    windowClass = data;
    windowClass.setUIContent("pages/Test");
    let enabled = true;
    let promise = windowClass.setSystemAvoidAreaEnabled(enabled);
    promise.then(() => {
      let enable = windowClass?.isSystemAvoidAreaEnabled();
    }).catch((err: BusinessError) => {
      console.error(`Failed to obtain whether the system window can get avoid area. Cause code: ${err.code}, message: ${err.message}`);
    });
  });
} catch (exception) {
  console.error(`Failed to create the system window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTitleAndDockHoverShown<sup>14+</sup>

setTitleAndDockHoverShown(isTitleHoverShown?: boolean, isDockHoverShown?: boolean): Promise&lt;void&gt;

Sets whether to show the window title bar and dock bar when the cursor hovers over the hot zone while the main window is in full-screen mode. This API uses a promise to return the result. It can be used only on 2-in-1 devices.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isTitleHoverShown    | boolean | No  | Whether to show the window title bar.<br>The value **true** means to show the window title bar, and **false** means the opposite. The default value is **true**.<br>|
| isDockHoverShown    | boolean | No  | Whether to show the dock bar.<br>The value **true** means to show the dock bar, and **false** means the opposite. The default value is **true**.<br>|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Load the page corresponding to the main window.
    windowStage.loadContent('pages/Index', (err) => {
      let mainWindow: window.Window | undefined = undefined;
      // Obtain the main window.
      windowStage.getMainWindow().then(
        data => {
          mainWindow = data;
          console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
          // Call maximize to enable the full-screen mode for the window.
          mainWindow.maximize(window.MaximizePresentation.ENTER_IMMERSIVE);
          // Call setTitleAndDockHoverShown to hide the window title bar and dock bar.
          mainWindow.setTitleAndDockHoverShown(false, false);
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

### setWindowLayoutFullScreen<sup>9+</sup>

setWindowLayoutFullScreen(isLayoutFullScreen: boolean): Promise&lt;void&gt;

Sets whether the main window layout or the child window layout is immersive. This API uses a promise to return the result. <!--RP8-->From API version 14, this API does not take effect on 2-in-1 devices.<!--RP8End-->
- An immersive layout means that the layout does not avoid the status bar or <!--RP15-->three-button navigation bar<!--RP15End-->, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->, and components do not overlap with them.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------------ | ------- | -- | ------------------------------------------------------------------------------------------------ |
| isLayoutFullScreen | boolean | Yes| Whether the layout of the window is immersive. (In immersive layout mode, the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> remain visible.) The value **true** means that the window layout is immersive, and **false** means the opposite.|

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

Sets whether to enable the immersive layout for the main window. This API does not change the window mode or size. <!--RP8-->From API version 14, this API does not take effect on 2-in-1 devices.<!--RP8End-->

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| enabled    | boolean | Yes  | Whether to enable the immersive layout.<br>The value **true** means to enable the immersive layout, and **false** means the opposite.|

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
| boolean | Result indicating whether the immersive layout is enabled.<br>The value **true** means that the immersive layout is enabled, and **false** means the opposite.|

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

### setWindowDelayRaiseOnDrag<sup>19+</sup>

setWindowDelayRaiseOnDrag(isEnabled: boolean): void

Sets whether to enable delayed raising for the window. This parameter takes effect only for the main window and child windows.

If this API is not called or **false** is passed, the main window and child windows are raised immediately upon a left mouse button press by default.

When this API is called to enable delayed raising, in cross-window drag-and-drop situations, the window that contains the draggable component does not raise until the left mouse button is released, rather than raising immediately when the button is pressed.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 19.

**Parameters**

| Name     | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isEnabled    | boolean | Yes  | Whether to enable delayed raising.<br>The value **true** means to enable delayed raising, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported.function setWindowDelayRaiseOnDrag can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
try {
  windowClass.setWindowDelayRaiseOnDrag(true);
} catch (exception) {
  console.error(`Failed to set window delay raise. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowSystemBarEnable<sup>9+</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>): Promise&lt;void&gt;

<!--RP14-->Sets whether to show the status bar and three-button navigation bar in the main window. The visibility of the status bar and three-button navigation bar is controlled by **status** and **navigation**, respectively.<!--RP14End--> This API uses a promise to return the result.<br>From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

The return value does not indicate that the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> are shown or hidden. This API does not take effect when it is called by a child window. The configuration does not take effect in non-full-screen mode (such as floating window or split-screen mode).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type | Mandatory| Description|
| ----- | ---------------------------- | -- | --------------------------------- |
| names | Array<'status'\|'navigation'> | Yes| Whether to show the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> in full-screen mode.<br>For example, to show all of them, set this parameter to **['status',&nbsp;'navigation']**. If this parameter is set to [], they are hidden.|

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
// The following assumes that all of them are hidden.
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

Sets whether to show the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> of the main window. This API uses a promise to return the result.<br>From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

The return value does not indicate that the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> are shown or hidden. This API does not take effect when it is called by a child window. The configuration does not take effect in non-full-screen mode (such as floating window or split-screen mode).

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type | Mandatory| Description|
| ----- | ---------------------------- | -- | --------------------------------- |
| name  | [SpecificSystemBar](#specificsystembar11) | Yes| Type of the system bar to be shown or hidden.|
| enable  | boolean | Yes| Whether to show the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> in full-screen mode. The value **true** means to show them, and **false** means the opposite.|
| enableAnimation<sup>12+</sup>  | boolean | No| Whether to enable animation when the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> status changes. The value **true** means to enable animation, and **false** means the opposite. The default value is **false**.|

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
// Here, the status bar is hidden.
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
        let promise = windowClass.setSpecificSystemBarEnabled('status', false);
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

Sets the properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar of the main window. This API uses a promise to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a child window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes  | Properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar.|

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

Obtains the properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar in the main window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type| Description|
| ------------------------------------- | ------------- |
| [SystemBarProperties](#systembarproperties) | Properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar.|

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

### setStatusBarColor<sup>18+</sup>

setStatusBarColor(color: ColorMetrics): Promise&lt;void&gt;

Sets the text color of the status bar in the main window. This API uses a promise to return the result.

Setting the status bar text color is not supported for child windows. Calling this API on a child window will have no effect. This API has no effect on 2-in-1 devices.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| color | [ColorMetrics](js-apis-arkui-graphics.md#colormetrics12) | Yes  | Text color of the status bar.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported on this device. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics, window } from '@kit.ArkUI';

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
        let promise = windowClass.setStatusBarColor(ColorMetrics.numeric(0x112233));
        promise.then(() => {
          console.info('Succeeded in setting the status bar color.');
        }).catch((err: BusinessError) => {
          console.error(`Set the status bar color failed. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to set the status bar color. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### getStatusBarProperty<sup>18+</sup>

getStatusBarProperty(): StatusBarProperty

Obtains the properties (for example, text color) of the status bar in the main window.

Calling this API is not supported for child window and will cause error code 1300002.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 18.

**Return value**

| Type| Description|
| ------------------------------------- | ------------- |
| [StatusBarProperty](#statusbarproperty18) | Status bar properties, such as its color.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801 | Capability not supported on this device. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

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
        let statusBarProperty = windowClass.getStatusBarProperty();
        console.info('Succeeded in obtaining system bar properties. Property: ' + JSON.stringify(statusBarProperty));
      } catch (err) {
        console.error(`Failed to get system bar properties. Code: ${err.code}, message: ${err.message}`);
      }
    });
  }
};
```

### setPreferredOrientation<sup>9+</sup>

setPreferredOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

Sets the preferred orientation for the main window. This API uses an asynchronous callback to return the result. <!--RP9-->This API takes effect only on devices that support rotation with the sensor. It does not take effect on 2-in-1 devices or in the child window mode.<!--RP9End-->

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name             | Type                                       | Mandatory| Description                  |
| ------------------- | ------------------------------------------- | ---- | ---------------------- |
| orientation         | [Orientation](#orientation9)                | Yes  | Orientation to set.        |
| callback            | AsyncCallback&lt;void&gt;                   | Yes  | Callback used to return the result. The callback indicates the API call result. It does not mean that the application rotation animation ends.|

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

Sets the preferred orientation for the main window. This API uses a promise to return the result. <!--RP9-->This API takes effect only on devices that support rotation with the sensor. It does not take effect on 2-in-1 devices or in the child window mode.<!--RP9End-->

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

Loads the content of a page, with its path in the current project specified, to this window, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path     | string                                          | Yes  | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project.|
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|
| callback | AsyncCallback&lt;void&gt;                       | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter.|
| 1300002 | This window state is abnormal.               |

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

Loads the content of a page, with its path in the current project specified, to this window, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type                                           | Mandatory| Description                                                        |
| ------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| path    | string                                          | Yes  | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project.|
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter.|
| 1300002 | This window state is abnormal.               |

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

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name     | string                                                  | Yes  | Name of the named route page.                                            |
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | Yes  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|
| callback | AsyncCallback&lt;void&gt;                               | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002  | This window state is abnormal.                |

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
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
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

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

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

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| name    | string                                                  | Yes  | Name of the named route page.                                            |
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | No  | Page-level UI state storage unit, which is used to transfer the state attribute for the page.|

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
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
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
<!--RP7-->Common scenarios for triggering this event are as follows: transitions between full-screen mode, floating mode, and split-screen mode of the application window; rotation of the application window; transitions between folded and unfolded states of a foldable device; transfer of the application window between multiple devices.<!--RP7End-->

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

Subscribes to the event indicating soft keyboard height changes in the fixed state.

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

Unsubscribes from the event indicating soft keyboard height changes in the fixed state so that the application does not receive notifications of soft keyboard height changes.

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

### on('keyboardWillShow')<sup>20+</sup>

on(type: 'keyboardWillShow', callback: Callback&lt;KeyboardInfo&gt;): void

Subscribes to the event indicating that the soft keyboard in the fixed state is about to show, or the soft keyboard is transitioning from the floating state to the fixed state.

For details about the APIs used to set the soft keyboard to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type               | Mandatory| Description                                       |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | Yes  | Event type. The value is fixed at **'keyboardWillShow'**, indicating the soft keyboard in the fixed state is about to show.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | Yes  | Callback used to return the information about the soft keyboard.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will show animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillShow', callback);
  console.info(`Register keyboard will show animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('keyboardWillShow')<sup>20</sup>

off(type: 'keyboardWillShow', callback?: Callback&lt;KeyboardInfo&gt;): void

Unsubscribes from the event indicating that the soft keyboard in the fixed state is about to show. For details about the APIs used to set the input method panel to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'keyboardWillShow'**, indicating the soft keyboard in the fixed state is about to show.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | No  |  Callback used to return the information about the soft keyboard. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will show animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillShow', callback);
  windowClass.off('keyboardWillShow', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('keyboardWillShow');
  console.info(`Unregister keyboard will show animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('keyboardWillHide')<sup>20+</sup>

on(type: 'keyboardWillHide', callback: Callback&lt;KeyboardInfo&gt;): void

Subscribes to the event indicating that the soft keyboard in the fixed state is about to hide, or the soft keyboard is transitioning from the fixed state to the floating state.

For details about the APIs used to set the soft keyboard to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type               | Mandatory| Description                                       |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | Yes  | Event type. The value is fixed at **'keyboardWillHide'**, indicating the soft keyboard in the fixed state is about to hide.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | Yes  | Callback used to return the information about the soft keyboard.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will hide animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillHide', callback);
  console.info(`Register keyboard will hide animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('keyboardWillHide')<sup>20+</sup>

off(type: 'keyboardWillHide', callback?: Callback&lt;KeyboardInfo&gt;): void

Unsubscribes from the event indicating that the soft keyboard in the fixed state is about to hide. For details about the APIs used to set the input method panel to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'keyboardWillHide'**, indicating the soft keyboard in the fixed state is about to hide.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | No  |  Callback used to return the information about the soft keyboard. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardWillHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  console.info(`Keyboard will hide animation. keyboardInfo: ` + JSON.stringify(keyboardInfo));
}
try {
  windowClass.on('keyboardWillHide', callback);
  windowClass.off('keyboardWillHide', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('keyboardWillHide');
  console.info(`Unregister keyboard will hide animation success`);
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('keyboardDidShow')<sup>18+</sup>

on(type: 'keyboardDidShow', callback: Callback&lt;KeyboardInfo&gt;): void

Subscribes to the event indicating that the show animation of the soft keyboard in the fixed state is completed, or when the soft keyboard finishes transitioning from the floating state to the fixed state.

For details about the APIs used to set the soft keyboard to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type               | Mandatory| Description                                       |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | Yes  | Event type. The value is fixed at **'keyboardDidShow'**, indicating the show animation of the soft keyboard in the fixed state is completed.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | Yes  | Callback used to return the information about the soft keyboard.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.on('keyboardDidShow', (keyboardInfo) => {
    console.info('keyboard show animation completion. keyboardInfo: ' + JSON.stringify(keyboardInfo));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('keyboardDidShow')<sup>18+</sup>

off(type: 'keyboardDidShow', callback?: Callback&lt;KeyboardInfo&gt;): void

Unsubscribes from the event indicating that the show animation of the soft keyboard in the fixed state is completed, For details about the APIs used to set the input method panel to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'keyboardDidShow'**, indicating the show animation of the soft keyboard in the fixed state is completed.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | No  |  Callback used to return the information about the soft keyboard. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidShow can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  // ...
}
try {
  windowClass.on('keyboardDidShow', callback);
  windowClass.off('keyboardDidShow', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('keyboardDidShow');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('keyboardDidHide')<sup>18+</sup>

on(type: 'keyboardDidHide', callback: Callback&lt;KeyboardInfo&gt;): void

Subscribes to the event indicating that the hide animation of the soft keyboard in the fixed state is completed, or when the soft keyboard finishes transitioning from the fixed state to the floating state.

For details about the APIs used to set the soft keyboard to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type               | Mandatory| Description                                       |
| -------- | ------------------- | ---- |-------------------------------------------|
| type     | string              | Yes  | Event type. The value is fixed at **'keyboardDidHide'**, indicating the hide animation of the soft keyboard in the fixed state is completed.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | Yes  | Callback used to return the information about the soft keyboard.                   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  windowClass.on('keyboardDidHide', (keyboardInfo) => {
    console.info('keyboard hide animation completion. keyboardInfo: ' + JSON.stringify(keyboardInfo));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('keyboardDidHide')<sup>18+</sup>

off(type: 'keyboardDidHide', callback?: Callback&lt;KeyboardInfo&gt;): void

Unsubscribes from the event indicating that the hide animation of the soft keyboard in the fixed state is completed, For details about the APIs used to set the input method panel to the fixed or floating state, see [Input Method Service](../apis-ime-kit/js-apis-inputmethodengine.md#changeflag10).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'keyboardDidHide'**, indicating the hide animation of the soft keyboard in the fixed state is completed.|
| callback | Callback&lt;[KeyboardInfo](#keyboardinfo18)&gt; | No  |  Callback used to return the information about the soft keyboard. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function keyboardDidHide can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const callback = (keyboardInfo: window.KeyboardInfo) => {
  // ...
}
try {
  windowClass.on('keyboardDidHide', callback);
  windowClass.off('keyboardDidHide', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('keyboardDidHide');
} catch (exception) {
  console.error(`Failed to register or unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
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

### on('displayIdChange')<sup>14+</sup>

on(type: 'displayIdChange', callback: Callback&lt;number&gt;): void

Subscribes to the display change event of this window. For example, this event is triggered when the window is moved to a different display.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'displayIdChange'**, indicating the display change event.|
| callback | Callback&lt;number&gt;   | Yes  | Callback invoked when the display where the window is located changes. The callback contains a parameter of the number type, indicating the new display ID.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**Example**

```ts
try {
  windowClass.on('displayIdChange', (data) => {
    console.info('Window displayId changed, displayId=' + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
### off('displayIdChange')<sup>14+</sup>

off(type: 'displayIdChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from the display change event of this window.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | Yes  | Event type. The value is fixed at **'displayIdChange'**, indicating the display change event.|
| callback | Callback&lt;number&gt;    | No  | Callback invoked when the display where the window is located changes. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**Example**

```ts
const callback = (displayId: number) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('displayIdChange', callback);
  // Disable the listening of a specified callback.
  windowClass.off('displayIdChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('displayIdChange');
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

### on('systemDensityChange')<sup>15+</sup>

on(type: 'systemDensityChange', callback: Callback&lt;number&gt;): void

Subscribes to the system density change event, which is triggered when the system's display size scale factor changes for the screen where the window is located.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | Yes  | Event type. The value is fixed at **'systemDensityChange'**, indicating the system density change event.|
| callback | Callback&lt;number&gt;   | Yes  | Callback invoked when the system's display size scale factor changes. The callback contains a parameter of the number type, indicating the new scale factor.                              |

**Error codes**


For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**Example**

```ts
const callback = (density: number) => {
  console.info('System density changed, density=' + JSON.stringify(density));
}
try {
  windowClass.on('systemDensityChange', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```
### off('systemDensityChange')<sup>15+</sup>

off(type: 'systemDensityChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from the system density change event.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                     | Yes  | Event type. The value is fixed at **'systemDensityChange'**, indicating the system density change event.|
| callback | Callback&lt;number&gt;    | No  | Callback invoked when the system's display size scale factor changes. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |

**Example**

```ts
const callback = (density: number) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('systemDensityChange', callback);
  // Disable the listening of a specified callback.
  windowClass.off('systemDensityChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('systemDensityChange');
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

Subscribes to the window status change event. A notification is sent when the window status changes (the window properties may not be updated).

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

### on('windowStatusDidChange')<sup>20+</sup>

on(type: 'windowStatusDidChange', callback: Callback&lt;WindowStatusType&gt;): void

Subscribes to the event indicating that the window status has changed (the [Rect](#rect7) property of the window has been updated).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowStatusDidChange'**, indicating that the window status has changed.|
| callback | Callback&lt;[WindowStatusType](#windowstatustype11)&gt; | Yes  | Callback used to return the window status.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
try {
    windowClass.on('windowStatusDidChange', (WindowStatusType) => {
        console.info(`Succeeded in enabling the listener for window status changes. Data: ${JSON.stringify(WindowStatusType)}`);
    });
} catch (exception) {
    console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('windowStatusDidChange')<sup>20+</sup>

off(type: 'windowStatusDidChange', callback?: Callback&lt;WindowStatusType&gt;): void

Unsubscribes from the event indicating that the window status has changed.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                         | Mandatory| Description                                                    |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| type     | string                        | Yes  | Event type. The value is fixed at **'windowStatusDidChange'**, indicating that the window status has changed.|
| callback | Callback&lt;[WindowStatusType](#windowstatustype11)&gt; | No  | Callback used to return the window status. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
const callback = (windowStatusType: window.WindowStatusType) => {
    // ...
}
try {
    windowClass.on('windowStatusDidChange', callback);
    windowClass.off('windowStatusDidChange', callback);
    // Unregister all the callbacks that have been registered through on().
    windowClass.off('windowStatusDidChange');
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
| grayScale | number | Yes| Grayscale of the window. The value is a floating point number in the range [0.0, 1.0]. The value **0.0** means that the window image does not change, and **1.0** means that the window image is completely turned into grayscale. The effect changes linearly between 0.0 and 1.0.|

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

Subscribes to the change event of the rectangle that holds the minimize, maximize, and close buttons on the title bar of the window. This API takes effect for the window that has a title bar or a three-button area. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

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

Unsubscribes from the change event of the rectangle that holds the minimize, maximize, and close buttons on the title bar of the window. This API takes effect for the window that has a title bar or a three-button area. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

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
try {
  windowClass.on('windowRectChange', (data: window.RectChangeOptions) => {
      console.info(`Succeeded window rect changes. Data: ` + JSON.stringify(data));
  });
} catch (exception) {
  console.error(`Failed to disable the listener for window rect changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
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

try {
  windowClass.on('windowRectChange', callback);
  windowClass.off('windowRectChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('windowRectChange');
} catch (exception) {
  console.error(`Failed to disable the listener for window rect changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('subWindowClose')<sup>12+</sup>

on(type:  'subWindowClose', callback: Callback&lt;void&gt;): void

Subscribes to the event indicating that the child window is closed. This event is triggered only when the user clicks the system-provided close button in the upper right corner to close the child window. It is not triggered when the child window is closed in other ways.

If the event is subscribed to multiple times, only the most recently subscribed-to event takes effect.

The callback function in this API is executed synchronously. For asynchronous close events of child windows, refer to [on('windowWillClose')](#onwindowwillclose15).

If there is an existing event subscribed to by calling [on('windowWillClose')](#onwindowwillclose15), only the [on('windowWillClose')](#onwindowwillclose15) API will be responded to.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'subWindowClose'**, indicating the child window close event.|
| callback | Callback&lt;void&gt; | Yes  | Callback invoked when the close button in the upper right corner of the child window is clicked. It does not return any parameter. The return value of the internal logic of the callback function determines whether to continue to close the child window. If **true** of the Boolean type is returned, the child window is not closed. If **false** or other non-Boolean types are returned, the child window is closed.  |

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

Unsubscribes from the event indicating that the child window is closed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                        |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | Yes  | Event type. The value is fixed at **'subWindowClose'**, indicating the child window close event.    |
| callback | Callback&lt;void&gt; | No  | Callback invoked when the close button in the upper right corner of the child window is clicked. It does not return any parameter. The return value of the internal logic of the callback function determines whether to continue to close the child window. If **true** of the Boolean type is returned, the child window is not closed. If **false** or other non-Boolean types are returned, the child window is closed. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

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

### on('windowWillClose')<sup>15+</sup>

on(type: 'windowWillClose', callback: Callback&lt;void, Promise&lt;boolean&gt;&gt;): void

Subscribes to the event indicating that the main window or child window will be closed. This event is triggered only when the user clicks the close button in the system-provided title bar to close the window. It is not triggered when the window is closed in other ways.

The callback function in this API is executed synchronously. For synchronous close events of child windows, refer to [on('subWindowClose')](#onsubwindowclose12). For synchronous close events of the main window, refer to [on('windowStageClose')](#onwindowstageclose14).

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->  <br>

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowWillClose'**, indicating the window close event.|
| callback | Callback&lt;void, Promise&lt;boolean&gt;&gt; | Yes  | Callback invoked when the close button in the upper right corner of the window is clicked. It does not return any parameter. The internal logic of the callback function requires a return value of the Promise&lt;boolean&gt; type. In the returned Promise function, **resolve(true)** means not to close the window, and **resolve(false)** or **reject** means to continue to close the window.|

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
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = () => {
      // ...
      return new Promise<boolean>((resolve, reject) => {
        // Whether to close the window.
        let result: boolean = true;
        resolve(result);
      });
    }
    try {
      let windowClass = windowStage.getMainWindowSync();
      windowClass.on('windowWillClose', callback);
    } catch (exception) {
      console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### off('windowWillClose')<sup>15+</sup>

off(type: 'windowWillClose', callback?: Callback&lt;void, Promise&lt;boolean&gt;&gt;): void

Unsubscribes from the event indicating that the main window or child window will be closed.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End--> <br>

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowWillClose'**, indicating the window close event.|
| callback | Callback&lt;void, Promise&lt;boolean&gt;&gt; | No  | Callback invoked when the close button in the upper right corner of the window is clicked. It does not return any parameter. The internal logic of the callback function requires a return value of the Promise&lt;boolean&gt; type. In the returned Promise function, **resolve(true)** means not to close the window, and **resolve(false)** or **reject** means to continue to close the window.|

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
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      const callback = () => {
        // ...
        return new Promise<boolean>((resolve, reject) => {
          // Whether to close the window.
          let result: boolean = true;
          resolve(result);
        });
      }
      let windowClass = windowStage.getMainWindowSync();
      windowClass.on('windowWillClose', callback);
      windowClass.off('windowWillClose', callback);
      // Unregister all the callbacks that have been registered through on().
      windowClass.off('windowWillClose');
    } catch (exception) {
      console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### on('windowHighlightChange')<sup>15+</sup>

on(type: 'windowHighlightChange', callback: Callback&lt;boolean&gt;): void

Subscribes to the highlighted state change event of the window.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowHighlightChange'**, indicating the window highlighted state change event.|
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return the highlighted state of the window. which is a Boolean value. The value **true** means that the window is highlighted, and **false** means the opposite.  |

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
try {
  windowClass.on('windowHighlightChange', (data: boolean) => {
    console.info(`Window highlight Change: ${data}`);
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('windowHighlightChange')<sup>15+</sup>

off(type: 'windowHighlightChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the highlighted state change event of the window.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                        |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | Yes  | Event type. The value is fixed at **'windowHighlightChange'**, indicating the window highlighted state change event.    |
| callback | Callback&lt;boolean&gt; | No  | Callback used to return the highlighted state of the window. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

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
const callback = (data: boolean) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('windowHighlightChange', callback);
  // Disable the listening of a specified callback.
  windowClass.off('windowHighlightChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('windowHighlightChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('rotationChange')<sup>19+</sup>

on(type: 'rotationChange', callback: RotationChangeCallback&lt;RotationChangeInfo, RotationChangeResult | void&gt;): void

Subscribes to the window rotation change event. If the window rotation event type in [RotationChangeInfo](#rotationchangeinfo19) is **WINDOW_WILL_ROTATE**, [RotationChangeResult](#rotationchangeresult19) must be returned. If the window rotation event type is **WINDOW_DID_ROTATE**, [RotationChangeResult](#rotationchangeresult19) does not take effect.

If a window registers multiple callbacks of the same type, only the return value of the most recently registered callback will be effective. The system provides a timeout protection mechanism. If the window does not return [RotationChangeResult](#rotationchangeresult19) within 20 ms, the system does not process the return value.

<!--RP10-->This API has no effect on 2-in-1 devices.<!--RP10End-->

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'rotationChange'**, indicating the window rotation change event.|
| callback | RotationChangeCallback&lt;[RotationChangeInfo](#rotationchangeinfo19), [RotationChangeResult](#rotationchangeresult19) \| void&gt; | Yes| Callback used to return [RotationChangeInfo](#rotationchangeinfo19) and [RotationChangeResult](#rotationchangeresult19).  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
function calculateRect(info: window.RotationChangeInfo): window.Rect {
    // calculate result with info
    let rect : window.Rect = {
      left: 0,
      top: 0,
      width: 500,
      height: 600,
    }
    return rect;
}

const callback = (info: window.RotationChangeInfo): window.RotationChangeResult | void => {
  let result: window.RotationChangeResult = {
    rectType: window.RectType.RELATIVE_TO_SCREEN,
    windowRect: {
      left: 0,
      top: 0,
      width: 0,
      height: 0,
    }
  };
  if (info.type === window.RotationChangeType.WINDOW_WILL_ROTATE) {
      result.rectType = window.RectType.RELATIVE_TO_SCREEN;
      result.windowRect = calculateRect(info);
      return result;
  } else {
      // do something after rotate
      return;
  }
}

try {
  windowClass.on('rotationChange', callback);
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('rotationChange')<sup>19+</sup>

off(type: 'rotationChange', callback?: RotationChangeCallback&lt;RotationChangeInfo, RotationChangeResult | void&gt;): void

Unsubscribes from the window rotation change event.

<!--RP10-->This API has no effect on 2-in-1 devices.<!--RP10End-->

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                        |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | Yes  | Event type. The value is fixed at **'rotationChange'**, indicating the window rotation change event.    |
| callback | RotationChangeCallback&lt;info: [RotationChangeInfo](#rotationchangeinfo19), [RotationChangeResult](#rotationchangeresult19) \| void&gt; | No  | Callback used to return the result. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
const callback = (info: window.RotationChangeInfo): window.RotationChangeResult | void => {
  // ...
  return;
}
try {
  windowClass.off('rotationChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('rotationChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### on('uiExtensionSecureLimitChange')<sup>20+</sup>

on(type: 'uiExtensionSecureLimitChange', callback: Callback&lt;boolean&gt;): void

Subscribes to the event indicating changes in the security restrictions of the UIExtensionAbility within the window. You are advised to initiate the subscription right after the window is created.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                    |
| -------- | ------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                         | Yes  | Event type. The value is fixed at **'uiExtensionSecureLimitChange'**, indicating that the UIExtensionAbility security restrictions in the window changes.|
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that at least one UIExtensionAbility within the window has enabled the hiding of unsafe windows, and **false** means that all UIExtensionAbilities within the window have disabled the hiding of unsafe windows.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported.Function on('uiExtensionSecureLimitChange') can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
try {
  windowClass.on('uiExtensionSecureLimitChange', (data: boolean) => {
    console.info(`Window secure limit Change: ${data}`);
  });
} catch (exception) {
  console.error(`Failed to register callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### off('uiExtensionSecureLimitChange')<sup>20+</sup>

off(type: 'uiExtensionSecureLimitChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the event indicating changes in the security restrictions of the UIExtensionAbility within the window.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                          | Mandatory| Description                                                        |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                         | Yes  | Event type. The value is fixed at **'uiExtensionSecureLimitChange'**, indicating that the UIExtensionAbility security restrictions in the window changes.    |
| callback | Callback&lt;boolean&gt; | No  | Callback used to return the result. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported.Function off('uiExtensionSecureLimitChange') can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**Example**

```ts
const callback = (data: boolean) => {
  // ...
}
try {
  // Enable listening through the on API.
  windowClass.on('uiExtensionSecureLimitChange', callback);
  // Disable the listening of a specified callback.
  windowClass.off('uiExtensionSecureLimitChange', callback);
  // Unregister all the callbacks that have been registered through on().
  windowClass.off('uiExtensionSecureLimitChange');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
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
  console.info(`Succeeded in checking whether the window support WideGamut Data: ${data}`);
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
  console.info(`Succeeded in checking whether the window support WideGamut. Data: ${data}`);
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
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let colorSpace = windowClass.getWindowColorSpace();
  console.info(`Succeeded in getting the window color space. ColorSpace: ${colorSpace}`);
} catch (exception) {
  console.error(`Failed to set the window to be focusable. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowBackgroundColor<sup>9+</sup>

setWindowBackgroundColor(color: string | ColorMetrics): void

Sets the background color for this window. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | -- | ----------------------------------------------------------------------- |
| color | string \| [ColorMetrics](js-apis-arkui-graphics.md#colormetrics12)<sup>18+</sup> | Yes| Background color to set. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**.<br>Since API version 18, this parameter supports the ColorMetrics type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | ------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics } from '@kit.ArkUI';

let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
windowClass.loadContent("pages/page2", storage, (err: BusinessError) => {
  let errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in loading the content.');
  let color1: string = '#00ff33';
  let color2: ColorMetrics = ColorMetrics.numeric(0xff112233);
  try {
    windowClass?.setWindowBackgroundColor(color1);
    windowClass?.setWindowBackgroundColor(color2);
  } catch (exception) {
    console.error(`Failed to set the background color. Cause code: ${exception.code}, message: ${exception.message}`);
  };
});
```

### setWindowBrightness<sup>9+</sup>

setWindowBrightness(brightness: number, callback: AsyncCallback&lt;void&gt;): void

Sets the screen brightness for the main window. This API uses an asynchronous callback to return the result.

- For non-2-in-1 devices, when the screen brightness setting for the window by this API takes effect, Control Panel cannot adjust the overall system screen brightness. It can do so only after the window-specific screen brightness is restored to the default value.
- For 2-in-1 devices, Control Panel has the same priority as this API. Event if this API is called to set the window-specific screen brightness, Control Panel can adjust the overall system screen brightness.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description                                       |
| ---------- | ------------------------- | -- |-------------------------------------------|
| brightness | number                    | Yes| Brightness to set. The value is a floating point number in the range [0.0, 1.0] or is set to **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness.|
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
      let brightness: number = 1.0;
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

- For non-2-in-1 devices, when the screen brightness setting for the window by this API takes effect, Control Panel cannot adjust the overall system screen brightness. It can do so only after the window-specific screen brightness is restored to the default value.
- For 2-in-1 devices, Control Panel has the same priority as this API. Event if this API is called to set the window-specific screen brightness, Control Panel can adjust the overall system screen brightness.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description                                    |
| ---------- | ------ | -- |----------------------------------------|
| brightness | number | Yes| Brightness to set. The value is a floating point number in the range [0.0, 1.0] or is set to **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness.|

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
      let brightness: number = 1.0;
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

Sets whether this window is focusable. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------------------------- | -- | ------------------------------------------------------- |
| isFocusable | boolean                   | Yes| Whether the window is focusable. The value **true** means that the window is focusable, and **false** means the opposite.|
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

Sets whether this window is focusable. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------- | -- | -------------------------------------------------------- |
| isFocusable | boolean | Yes| Whether the window is focusable. The value **true** means that the window is focusable, and **false** means the opposite. |

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

### setStartWindowBackgroundColor<sup>20+</sup>

setStartWindowBackgroundColor(moduleName: string, abilityName: string, color: ColorMetrics): Promise&lt;void&gt;

Sets the background color of the splash screen of the UIAbility based on the specified module name and ability name in the same application. This API uses a promise to return the result.

This API takes effect for all processes of the same application, for example, in multi-instance or clone scenarios.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name  | Type                         | Mandatory| Description                                                    |
| -------- | ----------------------------- | ---- | -------------------------------------------------------- |
| moduleName     | string                        | Yes  | Module name of the UIAbility. The value is a string of 0 to 200 characters. Only the module names within the same application can be set.|
| abilityName     | string                        | Yes  | Name of the UIAbility. The value is a string of 0 to 200 characters. Only the ability names within the same application can be set.|
| color | [ColorMetrics](js-apis-arkui-graphics.md#colormetrics12) | Yes  | Background color of the splash screen.                      |

**Return value**

| Type| Description|
| ------------------- | ------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID| Error Message|
| ------- | -------------------------------------------- |
| 801     | Capability not supported.function setStartWindowBackgroundColor can not to work correctly due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { ColorMetrics, window } from '@kit.ArkUI';

try {
  let promise =
    window.setStartWindowBackgroundColor("entry", "EntryAbility", ColorMetrics.numeric(0xff000000));
  promise.then(() => {
    console.log('Succeeded in setting the starting window color.');
  }).catch((err: BusinessError) => {
    console.error(`Set the starting window color failed. Cause code: ${err.code}, message:  ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the starting window color. Cause code: ${exception.code}, message:  ${exception.message}`);
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
    console.error(`Failed to set the screen to be always on. Cause code: ${err.code}, message: ${err.message}`);
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

Captures this window. This API uses an asynchronous callback to return the result. If privacy mode is enabled for the current window (using [setWindowPrivacyMode](#setwindowprivacymode9)), taking a screenshot will result in a blank screen.

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

Captures this window. If privacy mode is enabled for the current window (using [setWindowPrivacyMode](#setwindowprivacymode9)), taking a screenshot will result in a blank screen.

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

### snapshotIgnorePrivacy<sup>18+</sup>

snapshotIgnorePrivacy(): Promise&lt;image.PixelMap&gt;

Captures this window. This API can be called to obtain the screenshot of the current window even if privacy mode is enabled for the current window (using [setWindowPrivacyMode](#setwindowprivacymode9)).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                                                         | Description                                   |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Promise used to return the window screenshot. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Function snapshotIgnorePrivacy can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

let promise = windowClass.snapshotIgnorePrivacy();
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

When the window size is set by using other APIs such as [resize](#resize9) and [resizeAsync](#resizeasync12), the window size is not restricted by **ratio**.

This API can be called only for the main window and the setting takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode). The aspect ratio is saved persistently, which means that the setting is valid even after the application is closed or the device is restarted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type   | Mandatory | Description                                                  |
| ----- | ------ | --------- | ------------------------------------------------------------ |
| ratio | number | Yes       | Aspect ratio of the window content layout except border decoration. The value is a floating point number and is restricted by the maximum and minimum sizes of the window. The minimum ratio is the value of minimum width divided by the maximum height, and the maximum ratio is the maximum width divided by the minimum height. The maximum and minimum sizes of the window are determined by the intersection of the setting of [WindowLimits](#windowlimits11) and the system limit. The system limit takes precedence over [WindowLimits](#windowlimits11). The valid range of **ratio** varies with [WindowLimits](#windowlimits11). If [WindowLimits](#windowlimits11) is set prior to **ratio**, any conflict will result in an error code when setting **ratio**. Conversely, if **ratio** is set before and then conflicts arise with the subsequently configured [WindowLimits](#windowlimits11), the window's aspect ratio may not adhere to the initially configured value of **ratio**. |

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

When the window size is set by using other APIs such as [resize](#resize9) and [resizeAsync](#resizeasync12), the window size is not restricted by **ratio**.

This API can be called only for the main window and the setting takes effect only in floating window mode (**window.WindowStatusType.FLOATING** mode). The aspect ratio is saved persistently, which means that the setting is valid even after the application is closed or the device is restarted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| ratio    | number                    | Yes       | Aspect ratio of the window content layout except border decoration. The value is a floating point number and is restricted by the maximum and minimum sizes of the window. The minimum ratio is the value of minimum width divided by the maximum height, and the maximum ratio is the maximum width divided by the minimum height. The maximum and minimum sizes of the window are determined by the intersection of the setting of [WindowLimits](#windowlimits11) and the system limit. The system limit takes precedence over [WindowLimits](#windowlimits11). The valid range of **ratio** varies with [WindowLimits](#windowlimits11). If [WindowLimits](#windowlimits11) is set prior to **ratio**, any conflict will result in an error code when setting **ratio**. Conversely, if **ratio** is set before and then conflicts arise with the subsequently configured [WindowLimits](#windowlimits11), the window's aspect ratio may not adhere to the initially configured value of **ratio**. |
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

The behavior of this API varies based on the caller:

- Minimizes the main window if the caller is the main window. The main window can be restored in the dock bar. For 2-in-1 devices, it can be restored by calling [restore()](#restore14).

- Hides the child window or floating window if the caller is a child window. The child window or floating window cannot be restored in the dock bar. It can be made visible again by calling [showWindow()](#showwindow9).

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

The behavior of this API varies based on the caller:

- Minimizes the main window if the caller is the main window. The main window can be restored in the dock bar. For 2-in-1 devices, it can be restored by calling [restore()](#restore14).

- Hides the child window or floating window if the caller is a child window. The child window or floating window cannot be restored in the dock bar. It can be made visible again by calling [showWindow()](#showwindow9).

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

Maximizes the window. The main window can use this API to maximize. For child windows, you need to set **maximizeSupported** to **true** when creating the window and then call this API to maximize. This API uses a promise to return the result.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                                            | Mandatory | Description                                                  |
| ------------ | ----------------------------------------------- | --------- | ------------------------------------------------------------ |
| presentation | [MaximizePresentation](#maximizepresentation12) | No        | Layout of the main window or child window when maximized. The default value is **window.MaximizePresentation.ENTER_IMMERSIVE**, indicating that the window enters the immersive layout when maximized. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Function maximize can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

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

### setResizeByDragEnabled<sup>14+</sup>
setResizeByDragEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable the main window or child window with decorations to resize itself by dragging. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name     | Type                      | Mandatory | Description                                                  |
| -------- | ------------------------- | --------- | ------------------------------------------------------------ |
| enable   | boolean                   | Yes       | Whether to enable the window to resize itself by dragging. The value **true** means to enable the window to resize itself by dragging, and **false** means the opposite. |
| callback | AsyncCallback&lt;void&gt; | Yes       | Callback used to return the result.                          |

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
try {
  let enabled = false;
  windowClass.setResizeByDragEnabled(enabled, (err) => {
    if (err.code) {
      console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info(`Succeeded in setting the function of disabling the resize by drag window.`);
  });
} catch (exception) {
  console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setResizeByDragEnabled<sup>14+</sup>
setResizeByDragEnabled(enable: boolean): Promise&lt;void&gt;

Sets whether to enable the main window or child window with decorations to resize itself by dragging. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type    | Mandatory | Description                                                  |
| ------ | ------- | --------- | ------------------------------------------------------------ |
| enable | boolean | Yes       | Whether to enable the window to resize itself by dragging. The value **true** means to enable the window to resize itself by dragging, and **false** means the opposite. |

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

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let enabled = false;
  let promise = windowClass.setResizeByDragEnabled(enabled);
  promise.then(() => {
    console.info(`Succeeded in setting the function of disabling the resize by drag window.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the function of disabling the resize by drag window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### recover<sup>11+</sup>

recover(): Promise&lt;void&gt;

Restores the main window from the full-screen, maximized, or split-screen mode to a floating window, and restores the window size and position to those before the full-screen, maximized, or split-screen mode is entered. If the main window is already in the floating window mode, nothing will happen. This API uses a promise to return the result. It takes effect only in the multi-window stack layout.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

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

### restore<sup>14+</sup>

restore(): Promise&lt;void&gt;

Restores the main window from minimization to the foreground, returning it to its size and position before it is minimized. This API uses a promise to return the result.

This API takes effect only in the multi-window stack layout when the main window is minimized and the UIAbility is in the **onForeground** state.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| **ID**  | **Error Message**                                            |
| ------- | ------------------------------------------------------------ |
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
    try {
      let windowClass = windowStage.getMainWindowSync();
      // Call minimize() to minimize the main window.
      windowClass.minimize();
      // Set the delay function to restore the main window after a delay of 5 seconds.
      setTimeout(()=>{
        // Call restore() to restore the main window.
        let promise = windowClass.restore();
        promise.then(() => {
          console.info('Succeeded in restoring the window.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to restore the window. Cause code: ${err.code}, message: ${err.message}`);
        });
      }, 5000);
    } catch (exception) {
      console.error(`Failed to restore the window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
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

### setWindowLimits<sup>15+</sup>

setWindowLimits(windowLimits: WindowLimits, isForcible: boolean): Promise&lt;WindowLimits&gt;

Sets the size limits for this application window. This API uses a promise to return the result.

By default, system size limits are provided. They are determined by the product configuration and cannot be modified. If **setWindowLimits** has not been called, you can call [getWindowLimits](#getwindowlimits11) to obtain the system size limits.

This API can be used only on 2-in-1 devices.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                            | Mandatory | Description                                                  |
| :----------- | :------------------------------ | :-------- | :----------------------------------------------------------- |
| windowLimits | [WindowLimits](#windowlimits11) | Yes       | Target size limits, in px.                                   |
| isForcible   | boolean                         | Yes       | Whether to forcibly set the window size limits.<br>If this parameter is set to **true**, the minimum width and height of the window are determined by the lower value between the system size limits and 40 vp, and the maximum width and height depend on the system size limits.<br>If this parameter is set to **false**, the minimum and maximum window width and height are restricted by the system size limits. |

**Return value**

| Type                                           | Description                                                  |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[WindowLimits](#windowlimits11)&gt; | Promise used to return the new window size limits. Depending on the value of **isForcible**, the return value represents the intersection between the value passed and the system size limits. |

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
    minWidth: 100,
    minHeight: 100
  };
  let promise = windowClass.setWindowLimits(windowLimits, true);
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

This API is available only for child windows and global floating windows.

When the size of an irregularly shaped window changes, the actual display content is the intersection of the mask size and the window size.

Error code 1300002 may be returned only when multiple threads operate the same window. Error code 401 is returned when the window is destroyed.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

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

Sets whether to keep the soft keyboard created by others when a window has focus. This API can be called only by a system window or an application child window.

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

When the window title bar is hidden and the main window transitions into full-screen mode, hovering the cursor over the hot zone of the top window's title bar will cause a floating title bar to appear. To prevent the floating title bar from appearing, call [setTitleAndDockHoverShown()](#settitleanddockhovershown14).

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

### getWindowDecorVisible<sup>18+</sup>

getWindowDecorVisible(): boolean

Checks whether the title bar of this window is visible. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | Check result. The value **true** means that the title bar is visible, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
let isVisible: boolean | undefined = undefined;
windowClass.setUIContent('pages/WindowPage').then(() => {
  try {
    isVisible = windowClass?.getWindowDecorVisible();
  } catch (exception) {
    console.error(`Failed to get the window decor visibility. Cause code: ${exception.code}, message: ${exception.message}`);
  }
})
```

### setWindowTitle<sup>15+</sup>

setWindowTitle(titleName: string): Promise&lt;void&gt;

Sets the window title. This API uses a promise to return the result. The setting takes effect for a window with a title bar. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

This API can be used only 2-in-1 devices and tablets.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name      | Type   | Mandatory | Description                                                  |
| --------- | ------ | --------- | ------------------------------------------------------------ |
| titleName | string | Yes       | Window title. The title display area should not go past the left side of the three-button area of the system. Any part that goes beyond will show as an ellipsis. |

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

**Example**

```ts
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
try {
  let promise = window.getLastWindow(this.context);
  promise.then((data) => {
    windowClass = data;
    let title = "title";
    windowClass.setWindowTitle(title).then(() => {
      console.info('Succeeded in setting the window title.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to set the window title. Cause code: ${err.code}, message: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain the top window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowTitleMoveEnabled<sup>14+</sup>

setWindowTitleMoveEnabled(enabled: boolean): void

Enables or disables the capability to move the window (either main window or child window) by dragging its title bar and to maximize the window with a double-click. When this capability is disabled, you can use [startMoving()](#startmoving14) to move the window by dragging in the application's hot zone and use [maximize()](#maximize12) to maximize the window. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| enabled | boolean | Yes       | Whether to enable the capability to move the window by dragging the title bar and to maximize the window with a double-click. The value **true** means to enable the capability, and **false** means the opposite. |

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

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      windowStage.loadContent("pages/Index").then(() =>{
        let windowClass = windowStage.getMainWindowSync();
        let enabled = false;
        windowClass.setWindowTitleMoveEnabled(enabled);
        console.info(`Succeeded in setting the the window title move enabled: ${enabled}`);
      });
    } catch (exception) {
      console.error(`Failed to set the window title move enabled. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setSubWindowModal<sup>12+</sup>

setSubWindowModal(isModal: boolean): Promise&lt;void&gt;

Enables the modal property of the child window. This API uses a promise to return the result.

This API must be called by a child window and the setting takes effect for the child window.

After the modal property is enabled, the parent window does not respond to user interactions until the child window is closed or the child window's modal property is disabled.

If this API is called by a main window, an error is reported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| isModal | boolean | Yes       | Whether to enable the modal property of the child window. The value **true** means to enable the modal property, and **false** means the opposite. |


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
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // Create a child window.
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

### setSubWindowModal<sup>14+</sup>

setSubWindowModal(isModal: boolean, modalityType: ModalityType): Promise&lt;void&gt;

Sets the modality type of the child window. This API uses a promise to return the result.

When the child window is of the window-modal type, its parent window does not respond to user interactions until the child window is closed or the child window's modal property is disabled.

When the child window is of the application-modal type, its parent window and the windows from other instances of the application do not respond to user interactions until the child window is closed or the child window's modal property is disabled.

This API is used to set the modality type. To disable the modal property, you are advised to use [setSubWindowModal<sup>12+</sup>](#setsubwindowmodal12).

If this API is called by a main window, an error is reported.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name         | Type                            | Mandatory | Description                                                  |
| ------------ | ------------------------------- | --------- | ------------------------------------------------------------ |
| isModal      | boolean                         | Yes       | Whether to enable the modal property of the child window. The value **true** means to enable the modal property, and **false** means the opposite. Currently, this parameter can only be set to **true**. |
| modalityType | [ModalityType](#modalitytype14) | Yes       | Modality type of the child window.                           |

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
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let windowClass: window.Window | undefined = undefined;
    // Create a child window.
    try {
      let subWindow = windowStage.createSubWindow("testSubWindow");
      subWindow.then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        let promise = windowClass.setSubWindowModal(true, window.ModalityType.WINDOW_MODALITY);
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

When the main window transitions into full-screen mode, hovering the mouse over the hot zone of the window's title bar region will cause a floating title bar to appear, with a fixed height of 37 vp.

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

### setDecorButtonStyle<sup>14+</sup>

setDecorButtonStyle(dectorStyle: DecorButtonStyle): void

Sets the button style of the decoration bar. The setting takes effect only for the main window and child windows. In the stage model, this API must be used after the call of [loadContent](#loadcontent9) or [setUIContent()](#setuicontent9) takes effect.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name        | Type                                    | Mandatory | Description                         |
| ----------- | --------------------------------------- | --------- | ----------------------------------- |
| dectorStyle | [DecorButtonStyle](#decorbuttonstyle14) | Yes       | Button style of the decoration bar. |

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
import { ConfigurationConstant } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    try {
      windowStage.loadContent("pages/Index").then(() =>{
        let windowClass = windowStage.getMainWindowSync();
        let colorMode : ConfigurationConstant.ColorMode = ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT;
        let style: window.DecorButtonStyle = {
          colorMode: colorMode,
          buttonBackgroundSize: 28,
          spacingBetweenButtons: 12,
          closeButtonRightMargin: 20,
          buttonIconSize: 20,
          buttonBackgroundCornerRadius: 4
        };
        windowClass.setDecorButtonStyle(style);
        console.info('Succeeded in setting the style of button. Data: ' + JSON.stringify(style));
      });
    } catch (exception) {
      console.error(`Failed to set the style of button. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### getDecorButtonStyle<sup>14+</sup>

getDecorButtonStyle(): DecorButtonStyle

Obtains the button style of the decoration bar. The setting takes effect only for the main window and child windows.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                                    | Description                                                  |
| --------------------------------------- | ------------------------------------------------------------ |
| [DecorButtonStyle](#decorbuttonstyle14) | Button style on the decoration bar of the current window. The decoration button area is located in the upper right corner of the window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
try {
  let decorButtonStyle = windowClass.getDecorButtonStyle();
  console.info('Succeeded in getting the style of button. Data: ' + JSON.stringify(decorButtonStyle));
} catch (exception) {
  console.error(`Failed to get the style of button. Cause code: ${exception.code}, message: ${exception.message}`);
}
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

Obtains the rectangle that holds the minimize, maximize, and close buttons on the title bar of the main window or the decorated child window.

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

**Return value**

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

Creates a child window under the main window, another child window, or floating window. This API uses a promise to return the result.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name    | Type                                    | Mandatory | Description                                    |
| ------- | --------------------------------------- | --------- | ---------------------------------------------- |
| name    | string                                  | Yes       | Name of the child window.                      |
| options | [SubWindowOptions](#subwindowoptions11) | Yes       | Parameters used for creating the child window. |

**Return value**

| Type                             | Description                                              |
| -------------------------------- | -------------------------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to used to return the child window created. |

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

### setParentWindow<sup>19+</sup>

setParentWindow(windowId: number): Promise&lt;void&gt;

Sets a new parent window for this child window. The new parent window can be a main window, another child window, or a floating window. This API uses a promise to return the result.

If the child window is focused and the new parent window is in the foreground, the new parent window will be raised.

If the child window is focused and the new parent window has a modal child window with a higher level, the focus will be transferred to that modal child window.

This API can be used only on 2-in-1 devices.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 19.

**Parameters**

| Name     | Type   | Mandatory | Description                                                  |
| -------- | ------ | --------- | ------------------------------------------------------------ |
| windowId | number | Yes       | Parent window ID, which must be an integer. You are advised to call [getWindowProperties()](#getwindowproperties9) to obtain the parent window ID. |

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
| 1300009 | The parent window is invaild.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowClass: window.Window = window.findWindow("subWindow");
  let newParentWindow: window.Window = window.findWindow("newParentWindow");
  let newParentWindowId: number = newParentWindow.getWindowProperties().id;
  let promise = windowClass.setParentWindow(newParentWindowId);
  promise.then(() => {
    console.info('Succeeded in setting the new parent window.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the new parent window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the new parent window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### getParentWindow<sup>19+</sup>

getParentWindow(): Window

Obtains the parent window of this child window.

This API can be used only on 2-in-1 devices.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 19.

**Return value**

| Type              | Description    |
| ----------------- | -------------- |
| [Window](#window) | Parent window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |
| 1300009 | The parent window is invaild.                                |

**Example**

```ts
try {
  let windowClass: window.Window = window.findWindow("subWindow");
  let parentWindow: window.Window = windowClass.getParentWindow();
  let properties = parentWindow.getWindowProperties();
  console.info('Succeeded in obtaining parent window properties. Property: ' + JSON.stringify(properties));
} catch (exception) {
  console.error(`Failed to get the parent window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowTitleButtonVisible<sup>14+</sup>

setWindowTitleButtonVisible(isMaximizeButtonVisible: boolean, isMinimizeButtonVisible: boolean, isCloseButtonVisible?: boolean): void

Shows or hides the maximize, minimize, and close buttons on the title bar of the main window.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name                    | Type    | Mandatory | Description                                                  |
| ----------------------- | ------- | --------- | ------------------------------------------------------------ |
| isMaximizeButtonVisible | boolean | Yes       | Whether to show the maximize button. The value **true** means to show the button, and **false** means the opposite. If the maximize button is hidden, the corresponding restore button is also hidden in the maximize scenario. |
| isMinimizeButtonVisible | boolean | Yes       | Whether to show the minimize button. The value **true** means to show the button, and **false** means the opposite. |
| isCloseButtonVisible    | boolean | No        | Whether to show the close button. The value **true** means to show the button, and **false** means the opposite. |

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
import { window } from '@kit.ArkUI';

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
          // Call setWindowTitleButtonVisible to hide the maximize, minimize, and close buttons on the title bar of the main window.
          mainWindow.setWindowTitleButtonVisible(false, false, false);
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

### setWindowTopmost<sup>14+</sup>

setWindowTopmost(isWindowTopmost: boolean): Promise&lt;void&gt;

Places the main window above all the other windows of the application. This API uses a promise to return the result.

Applications use custom shortcut keys to pin or unpin the main window.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Required permissions**: ohos.permission.WINDOW_TOPMOST

**Parameters**

| Name            | Type    | Mandatory | Description                                                  |
| --------------- | ------- | --------- | ------------------------------------------------------------ |
| isWindowTopmost | boolean | Yes       | Whether to pin the main window on top. The value **true** means to pin the main window on top, and **false** means the opposite. |


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 201     | Permission verification failed. The application does not have the permission required to call the API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
// ets/pages/Index.ets
import { window } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined;
let keyUpEventAry: string[] = [];

@Entry
@Component
struct Index {
  private context = (this.getUIContext()?.getHostContext() as common.UIAbilityContext);

  build() {
    RelativeContainer() {
      Button("Pin")
        .onClick(() => {
          try {
            let promiseCtx = window.getLastWindow(this.context);
            promiseCtx.then((data) => {
              windowClass = data;
              // The value true means to pin the window on top, and false means to unpin the window.
              let isWindowTopmost: boolean = true;
              let promiseTopmost = windowClass.setWindowTopmost(isWindowTopmost);
              promiseTopmost.then(() => {
                console.info('Succeeded in setting the main window to be topmost.');
              }).catch((err: BusinessError) => {
                console.error(`Failed to set the main window to be topmost. Cause code: ${err.code}, message: ${err.message}`);
              });
            })
          } catch (exception) {
            console.error(`Failed to obtain the top window. Cause code: ${exception.code}, message: ${exception.message}`)
          }
        })
    }
    .height('100%')
    .width('100%')
    .onKeyEvent((event) => {
      if(event) {
        if(event.type === KeyType.Down) {
          keyUpEventAry = [];
        }
        if(event.type === KeyType.Up) {
          keyUpEventAry.push(event.keyText);
          // Press Ctrl+T to pin or unpin the main window.
          if(windowClass && keyUpEventAry.includes('KEYCODE_CTRL_LEFT') && keyUpEventAry.includes('KEYCODE_T')) {
            let isWindowTopmost: boolean = false;
            windowClass.setWindowTopmost(isWindowTopmost);
          }
        }
      }
    })
  }
}
```

### raiseToAppTop<sup>14+</sup>

raiseToAppTop(): Promise&lt;void&gt;

Brings a child window to the top. This action is limited to child windows of the same type under the same parent window within the current application. For child windows with a custom zLevel property, it only applies to child windows with the same zLevel value under the same parent window within the current application. This API uses a promise to return the result.

Before calling this API, ensure that the child window has been created and [showWindow()](#showwindow9) has been successfully executed.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                 |
| ------- | --------------------------------------------- |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |
| 1300009 | The parent window is invalid.                 |

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
        subWindow.raiseToAppTop().then(() => {
          console.info('Succeeded in raising window to app top');
        }).catch((err: BusinessError)=>{
          console.error(`Failed to raise window to app top. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    });
  }
}
```

### setRaiseByClickEnabled<sup>14+</sup>

setRaiseByClickEnabled(enable: boolean): Promise&lt;void&gt;

Sets whether to enable a child window to raise itself by click. This API uses a promise to return the result.

Generally, when a child window is clicked, it is brought to the forefront among sibling child windows of the same type that share the same parent window within the application. If the **enable** parameter is set to **false**, when the child window is clicked, it still stays in its existing position.

Before calling this API, ensure that the child window has been created and [showWindow()](#showwindow9) has been successfully executed.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name   | Type    | Mandatory | Description                                                  |
| ------ | ------- | --------- | ------------------------------------------------------------ |
| enable | boolean | Yes       | Whether a child window can be raised by clicking. The value **true** means that the child window can be raised by clicking, and **false** means the opposite. |

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
| 1300009 | The parent window is invalid.                                |

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
          subWindow.setRaiseByClickEnabled(enabled).then(() => {
            console.info('Succeeded in disabling the raise-by-click function.');
          }).catch((err: BusinessError) => {
            console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
          });
        } catch (err) {
          console.error(`Failed to disable the raise-by-click function. Cause code: ${err.code}, message: ${err.message}`);
        }
      });
    });
  }
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
| enabled | boolean | Yes       | Whether to respond to the back gesture event.<br>The value **true** means to respond to the back gesture event and trigger the **onBackPress** callback, and **false** means the opposite.<br> |

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

### startMoving<sup>14+</sup>

startMoving(): Promise&lt;void&gt;

Starts moving this window. This API uses a promise to return the result.

The window moves along with the cursor or touch point only when this API is called in the callback function of [onTouch](./arkui-ts/ts-universal-events-touch.md#touchevent), where the event type is **TouchType.Down**.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

This API takes effect only for the main window, child window, and system window. If it is called for other device types or window types, an error is reported.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

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
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
// ets/pages/Index.ets
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Blue)
          .onTouch((event: TouchEvent) => {
            if (event.type === TouchType.Down) {
              try {
                let windowClass: window.Window = window.findWindow("subWindow");
                windowClass.startMoving().then(() => {
                  console.info('Succeeded in starting moving window.')
                }).catch((err: BusinessError) => {
                  console.error(`Failed to start moving. Cause code: ${err.code}, message: ${err.message}`);
                });
              } catch (exception) {
                console.error(`Failed to start moving window. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

### startMoving<sup>15+</sup>

startMoving(offsetX: number, offsetY: number): Promise&lt;void&gt;

Specifies the cursor position within the window and moves the window. This API uses a promise to return the result.

When windows within the same application are split or merged, and the mouse is pressed down to move the new window directly, the cursor may move outside the window if it moves too quickly. This API allows you to set the cursor position within the window during movement. It first adjusts the window to the cursor position before starting to move the window.

The window moves along with the cursor only when this API is called in the callback function of [onTouch](./arkui-ts/ts-universal-events-touch.md#touchevent), where the event type is **TouchType.Down**.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 15.

**Parameters**

| Name    | Type   | Mandatory | Description                                                  |
| ------- | ------ | --------- | ------------------------------------------------------------ |
| offsetX | number | Yes       | X-axis offset of the cursor position relative to the upper left corner of the window during movement, measured in px. This parameter only accepts integer values; any floating-point input will be rounded down. Negative values or values exceeding the window width are invalid. The window width can be obtained from [WindowProperties](#windowproperties). |
| offsetY | number | Yes       | Y-axis offset of the cursor position relative to the upper left corner of the window during movement, measured in px. This parameter only accepts integer values; any floating-point input will be rounded down. Negative values or values exceeding the window height are invalid. The window height can be obtained from [WindowProperties](#windowproperties). |

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
| 1300001 | Repeated operation.                                          |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
// ets/pages/Index.ets
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Blank('160')
          .color(Color.Blue)
          .onTouch((event: TouchEvent) => {
            if (event.type === TouchType.Down) {
              try {
                let windowClass: window.Window = window.findWindow("subWindow");
                windowClass.startMoving(100, 50).then(() => {
                  console.info('Succeeded in starting moving window.')
                }).catch((err: BusinessError) => {
                  console.error(`Failed to start moving. Cause code: ${err.code}, message: ${err.message}`);
                });
              } catch (exception) {
                console.error(`Failed to start moving window. Cause code: ${exception.code}, message: ${exception.message}`);
              }
            }
          })
      }.width('100%')
    }.height('100%').width('100%')
  }
}
```

### stopMoving<sup>15+</sup>

stopMoving(): Promise&lt;void&gt;

Stops window movement when a window is being dragged. This API uses a promise to return the result.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 15.

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

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage) {
    try {
      let windowClass = windowStage.getMainWindowSync();
      windowClass.on('windowRectChange', (data: window.RectChangeOptions) => {
        if (data.reason === window.RectChangeReason.MOVE) {
          windowClass.stopMoving().then(() => {
            console.info('Succeeded in stopping moving window.')
          }).catch((err: BusinessError) => {
            console.error(`Failed to stop moving. Cause code: ${err.code}, message: ${err.message}`);
          });
        }
      });
    } catch (exception) {
      console.error(`Failed to stop moving window. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setGestureBackEnabled<sup>13+<sup>

setGestureBackEnabled(enabled: boolean): Promise&lt;void&gt;

Sets whether to enable the back gesture feature in this window. This API takes effect only in full-screen mode of the main window and cannot be used on 2-in-1 devices.

When the back gesture feature is disabled, the application does not recognize the gesture hot zone for back redirection, causing the side-swipe gesture non-functional. However, after you switch to another application or return to the home screen, the gesture hot zone functions normally and the side-swipe gesture works properly.

When the back gesture feature is enabled, the application recognizes the gesture hot zone for back redirection, allowing the side-swipe gesture to function as expected.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 13.

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| enabled | boolean | Yes       | Whether to enable the back gesture feature. The value **true** means to enable the feature, and **false** means the opposite. |

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

      // Disable the back gesture feature in the current window.
      try {
        let gestureBackEnabled: boolean = false;
        let promise = windowClass.setGestureBackEnabled(gestureBackEnabled);
        promise.then(() => {
          console.info(`Succeeded in setting gesture back disabled`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to set gesture back disabled, Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch(exception) {
        console.error(`Failed to set gesture back disabled, Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### isGestureBackEnabled<sup>13+<sup>

isGestureBackEnabled(): boolean

Checks whether the back gesture feature is enabled in this window. This API takes effect only in full-screen mode of the main window and cannot be used on 2-in-1 devices.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 13.

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | Whether the back gesture feature is enabled. The value **true** means that the back gesture feature is enabled, and **false** means that it is disabled. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

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

      // Check whether the back gesture feature is enabled in the current window.
      try {
        let gestureBackEnabled: boolean = windowClass.isGestureBackEnabled();
        console.info(`Succeeded in obtaining gesture back enabled status: ${gestureBackEnabled}`);
      } catch (exception) {
        console.error(`Failed to get gesture back enabled status. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
}
```

### setWindowShadowRadius<sup>17+</sup>

setWindowShadowRadius(radius: number): void

Sets the blur radius of the shadow on the edges of a child window or floating window. This API can be used only on 2-in-1 devices or tablets.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 17.

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| ------ | ------ | --------- | ------------------------------------------------------------ |
| radius | number | Yes       | Radius of the shadow, measured in px. The value is a floating point number greater than or equal to 0.0, and the value **0.0** means that the shadow is disabled for the window borders. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
try {
  windowClass.setWindowShadowRadius(4.0);
} catch (exception) {
  console.error(`Failed to set shadow. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowCornerRadius<sup>17+</sup>

setWindowCornerRadius(cornerRadius: number): Promise&lt;void&gt;

Sets the radius of the rounded corners for a child window or floating window. This API uses a promise to return the result.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

If the radius of the rounded corner is too large, it may cause the three buttons (maximize, minimize, and close) to be clipped and make their hotspots less recognizable. Set an appropriate radius based on the window size.

Before calling this API, you can call [getWindowCornerRadius()](#getwindowcornerradius17) to obtain the default radius of rounded corners of the window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 17.

**Parameters**

| Name         | Type   | Mandatory | Description                                                  |
| ------------ | ------ | --------- | ------------------------------------------------------------ |
| cornerRadius | number | Yes       | Radius of the rounded corners, measured in vp. The value is a floating point number greater than or equal to 0.0. The value **0.0** means that the window does not use rounded corners. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try{
  let promise = windowClass.setWindowCornerRadius(1.0);
  promise.then(() => {
    console.info('Succeeded in setting window corner radius.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set window corner radius. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set corner radius. Cause code: ${exception.code}, message: ${exception.message}`);
}

```

### getWindowCornerRadius<sup>17+</sup>

getWindowCornerRadius(): number

Obtains the radius of rounded corners of a child window or floating window. If [setWindowCornerRadius()](#setwindowcornerradius17) is not called to set the radius of rounded corners, this API returns the default radius of rounded corners.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 17.

**Return value**

| Type   | Description                                                  |
| ------ | ------------------------------------------------------------ |
| number | Radius of the rounded corner of the child window or floating window, measured in vp. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
try {
  let cornerRadius = windowClass.getWindowCornerRadius();
} catch (exception) {
  console.error(`Failed to get corner radius. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setExclusivelyHighlighted<sup>15+<sup>

setExclusivelyHighlighted(exclusivelyHighlighted: boolean): Promise&lt;void&gt;

Sets the exclusive highlight property for the window. When a window set to exclusive highlight gains focus, other windows in the current parent-child window chain that are in the highlighted state will lose their highlighted state. This API uses a promise to return the result.

This API does not take effect for the main window, modal window, and dialog boxes.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 15.

**Parameters**

| Name                   | Type    | Mandatory | Description                                                  |
| ---------------------- | ------- | --------- | ------------------------------------------------------------ |
| exclusivelyHighlighted | boolean | Yes       | Whether to set exclusive highlight for the window. The value **true** means to set exclusive highlight for the window, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let exclusivelyHighlighted: boolean = true;
try {
  let promise = windowClass.setExclusivelyHighlighted(exclusivelyHighlighted);
  promise.then(() => {
    console.info('Succeeded in setting the window to be exclusively highlight.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the window to be exclusively highlight. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the window to be exclusively highlight. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### isWindowHighlighted<sup>18+<sup>

isWindowHighlighted(): boolean

Checks whether the window is active. To obtain the active state, call this API when the [WindowEventType](#windoweventtype10) lifecycle is **WINDOW_ACTIVE**.

You can use [on('windowHighlightChange')](#onwindowhighlightchange15) to listen for status changes and then execute the corresponding service.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 18.

**Return value**

| Type    | Description                                                  |
| ------- | ------------------------------------------------------------ |
| boolean | Check result. The value **true** means that the window is active, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isHighlighted = windowClass.isWindowHighlighted();
  console.info(`Succeeded in getting the window highlight status: ${isHighlighted}`);
} catch (exception) {
  console.error(`Failed to get the window highlight status.. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setFollowParentMultiScreenPolicy<sup>17+<sup>

setFollowParentMultiScreenPolicy(enabled: boolean): Promise&lt;void&gt;

Sets whether a child window can span multiple screens and be simultaneously displayed while its parent window is being dragged or resized. This API uses a promise to return the result.

By default, when a child window follows its parent window's layout changes (by using [moveWindowTo()](#movewindowto9)), it does not support spanning multiple screens and being simultaneously displayed.

However, calling this API on the child window enables it to span multiple screens and be simultaneously displayed during the layout adjustment process.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 17.

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| enabled | boolean | Yes       | Whether the child window can span multiple screens and be simultaneously displayed while its parent window is being dragged or resized. The value **true** means that the child window can span multiple screens and be simultaneously displayed while its parent window is being dragged or resized, and **false** means the opposite. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported.Function setFollowParentMultiScreenPolicy can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowClass: window.Window = window.findWindow("subWindow");
  let enabled: boolean = true;
  let promise = windowClass?.setFollowParentMultiScreenPolicy(enabled);
  promise.then(() => {
    console.info('Succeeded in setting the sub window supports multi-screen simultaneous display')
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the sub window supports multi-screen simultaneous display. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the sub window supports multi-screen simultaneous display. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setFollowParentWindowLayoutEnabled<sup>17+</sup>

setFollowParentWindowLayoutEnabled(enabled: boolean): Promise&lt;void&gt;

Sets whether the layout information (position and size) of a child window or modal window (a window with **WindowType** set to **TYPE_DIALOG**) follows the main window. This API uses a promise to return the result.

1. This API applies only to first-level child windows or modal windows of the main window.

2. Once this API is called on a child window or modal window, its layout information will immediately match the main window and remain synchronized. This effect will persist until this API is called again with **false**.

3. If this API is called on a child window or modal window, subsequent calls to APIs like **moveTo** or **resize** to modify the layout information will not take effect.

4. When a child window or modal window stops using this functionality, its layout information (position and size) may not be a specific value. The application needs to reset it.

Once this API is successfully called, the [setRelativePositionToParentWindowEnabled()](#setrelativepositiontoparentwindowenabled20) API will no longer take effect.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 17.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| enabled | boolean | Yes       | Whether to follow the layout of the main window. The value **true** means to follow the layout of the main window, and **false** means the opposite. |

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
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (loadError) => {
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
        subWindow.setFollowParentWindowLayoutEnabled(true).then(() => {
          console.info("after set follow parent window layout")
        }).catch((error: BusinessError) => {
          console.error(`setFollowParentWindowLayoutEnabled failed. ${error.code} ${error.message}`);
        })
      }).catch((error: BusinessError) => {
        console.error(`createSubWindow failed. ${error.code} ${error.message}`);
      })
    });
  }
}
```

### setRelativePositionToParentWindowEnabled<sup>20+<sup>

setRelativePositionToParentWindowEnabled(enabled: boolean, anchor?: WindowAnchor, offsetX?: number, offsetY?: number): Promise&lt;void&gt;

Sets whether a first-level child window can maintain a fixed relative position to the main window. This API uses a promise to return the result.

The relative position is defined by the offset between the anchor points of the child window and the main window. Both the child window and the main window use the same type of anchor point.

1. This API applies only to level-1 child windows that are not maximized.

2. Once this API is called on a child window, its display position will immediately follow the main window and maintain a fixed relative position. This effect will persist until this API is called again with **false**.

3. If this API is called on a child window, subsequent calls to APIs like [moveWindowTo()](#movewindowto9) or [maximize()](#maximize12) to modify the window's position or size will not take effect.

Once this API is successfully called, the [setFollowParentWindowLayoutEnabled()](#setfollowparentwindowlayoutenabled17) API will no longer take effect.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name    | Type                            | Mandatory | Description                                                  |
| ------- | ------------------------------- | --------- | ------------------------------------------------------------ |
| enabled | boolean                         | Yes       | Whether to maintain a fixed relative position to the main window. The value **true** means to maintain a fixed relative position to the main window, and **false** means the opposite. |
| anchor  | [WindowAnchor](#windowanchor20) | No        | Type of anchor point used to maintain the relative position. This parameter takes effect only when **enabled** is set to **true**. The default value is **window.WindowAnchor.TopStart**, indicating that the default anchor point is the top-left corner of the window. |
| offsetX | number                          | No        | X-axis offset between the anchor points of the child window and the main window, in px. This parameter takes effect only when **enabled** is set to **true**. Only integer values are supported, and floating-point numbers are rounded down. The default value is **0**. |
| offsetY | number                          | No        | Y-axis offset between the anchor points of the child window and the main window, in px. This parameter takes effect only when **enabled** is set to **true**. Only integer values are supported, and floating-point numbers are rounded down. The default value is **0**. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported.Function setRelativePositionToParentWindowEnabled can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowClass: window.Window = window.findWindow("subWindow");
  let enabled: boolean = true;
  let promise = windowClass?.setRelativePositionToParentWindowEnabled(enabled);
  promise.then(() => {
    console.info('Succeeded in setting the sub window supports relative position to parent window.')
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the sub window supports relative position to parent window. Cause code: ${err.code}, message: ${err.message}`);
  });
} catch (exception) {
  console.error(`Failed to set the sub window supports relative position to parent window. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setWindowTransitionAnimation<sup>20+</sup>

setWindowTransitionAnimation(transitionType: WindowTransitionType, animation: TransitionAnimation): Promise&lt;void&gt;

Adds a transition animation to windows in specific scenarios.

Currently, this API can be used only on the main window of an application.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name           | Type                                            | Mandatory | Description                                                  |
| -------------- | ----------------------------------------------- | --------- | ------------------------------------------------------------ |
| transitionType | [WindowTransitionType](#windowtransitiontype20) | Yes       | Scene of the transition animation. Currently, only the destruction scene is supported. |
| animation      | [TransitionAnimation](#transitionanimation20)   | Yes       | Configuration of the transition animation.                   |

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
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range; 2. Invalid parameter length. |

**Example**

```typescript
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';
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
      try {
        const animationConfig: window.WindowAnimationConfig = {
          duration: 1000,
          curve: window.WindowAnimationCurve.LINEAR,
        };
        const transitionAnimation: window.TransitionAnimation = {
          opacity: 0.5,
          config: animationConfig
        };
        let promise = windowClass.setWindowTransitionAnimation(window.WindowTransitionType.DESTROY, transitionAnimation);
        promise.then((data) => {
          console.info('Succeeded in setting window transition animation. Cause:' + JSON.stringify(data));
        }).catch((err: BusinessError) => {
          console.error(`Failed to set window transition animation. Cause code: ${err.code}, message: ${err.message}`);
        });
      } catch (exception) {
        console.error(`Failed to obtain the window status of window. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    })
  }
}
```

### getWindowTransitionAnimation<sup>20+</sup>

getWindowTransitionAnimation(transitionType: WindowTransitionType): TransitionAnimation | undefined

Obtains the window transition animation configuration in a specific scenario.

Currently, this API can be used only on the main window of an application.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name           | Type                                            | Mandatory | Description                                                  |
| -------------- | ----------------------------------------------- | --------- | ------------------------------------------------------------ |
| transitionType | [WindowTransitionType](#windowtransitiontype20) | Yes       | Scene of the transition animation. Currently, only the destruction scene is supported. |

**Return value**

| Type                                                       | Description                                                  |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| [TransitionAnimation](#transitionanimation20) \| undefined | Transition animation configuration in the corresponding scene. If the [setWindowTransitionAnimation](#setwindowtransitionanimation20) API is not used, undefined is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range; 2. Invalid parameter length. |

**Example**

```typescript
// EntryAbility.ets
import { BusinessError } from '@kit.BasicServicesKit';
import { UIAbility } from '@kit.AbilityKit';
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
      try {
        let transitionAnimationResult = windowClass.getWindowTransitionAnimation(window.WindowTransitionType.DESTROY);
        console.info('Succeeded in getting window transition animation: ' + JSON.stringify(transitionAnimationResult));
      } catch (exception) {
        console.error(`Failed to obtain the window transition animation. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    })
  }
}
```

### setWindowSystemBarProperties<sup>(deprecated)</sup>

setWindowSystemBarProperties(systemBarProperties: SystemBarProperties, callback: AsyncCallback&lt;void&gt;): void

Sets the properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar of the main window. This API uses an asynchronous callback to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a child window.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setWindowSystemBarProperties](#setwindowsystembarproperties9) in promise mode instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name                | Type                                        | Mandatory | Description                                                  |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar. |
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

### setSubWindowZLevel<sup>18+</sup>

setSubWindowZLevel(zLevel: number): Promise&lt;void&gt;

Sets the z-level of the current child window. Child windows with modal properties are not supported. This API uses a promise to return the result.

Changing the z-level of a child window using this API will not cause a focus switch. You are advised to use [shiftAppWindowFocus()](#windowshiftappwindowfocus11) for focus switching.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name   | Type   | Mandatory | Description                                                  |
| :----- | :----- | :-------- | :----------------------------------------------------------- |
| zLevel | number | Yes       | Z-level of the child window. The default value is 0, and the value range is [–10000, 10000]. Only integers are supported, and floating-point numbers will be rounded down. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Function setSubWindowZLevel can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager service works abnormally.                |
| 1300004 | Unauthorized operation.                                      |
| 1300009 | The parent window is invalid.                                |

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
    let zLevel: number = 1;
    // Create a child window.
    try {
      windowStage.createSubWindow('testSubWindow').then((subWindow) => {
        if (subWindow == null) {
          console.error('Failed to create the sub window. Cause: The sub window is null');
          return;
        }
        subWindow.setSubWindowZLevel(zLevel).then(() => {
          console.info('Succeeded in setting sub window zLevel.');
        }).catch((err: BusinessError) => {
          console.error(`Failed to set sub window zLevel. Cause code: ${err.code}, message: ${err.message}`);
        });
      });
    } catch (err) {
      console.error(`Failed to create the sub window or set zLevel. Cause code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

### getSubWindowZLevel<sup>18+</sup>

getSubWindowZLevel(): number

Obtains the z-level of the current child window. This API cannot be called by the main window or system window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 18.

**Return value**

| Type   | Description                  |
| ------ | ---------------------------- |
| number | Z-level of the child window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Function getSubWindowZLevel can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300004 | Unauthorized operation.                                      |

**Example**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    let subWindowZLevel = -1;
    // Create a child window.
    windowStage.createSubWindow('testSubWindow').then((subWindow) => {
      if (subWindow == null) {
        console.error('Failed to create the sub window. Cause: The sub window is null');
        return;
      }
      try {
        subWindowZLevel = subWindow.getSubWindowZLevel();
        console.info(`Succeeded in obtaining sub window zLevel: ${subWindowZLevel}`);
      } catch (err) {
        console.error(`Failed to obtain the sub window zLevel. Cause code: ${err.code}, message: ${err.message}`);
      }
    });
  }
}
```

### setWindowSystemBarEnable<sup>(deprecated)</sup>

setWindowSystemBarEnable(names: Array<'status' | 'navigation'>, callback: AsyncCallback&lt;void&gt;): void

<!--RP14-->Sets whether to show the status bar and three-button navigation bar in the main window. The visibility of the status bar and three-button navigation bar is controlled by **status** and **navigation**, respectively.<!--RP14End--> This API uses an asynchronous callback to return the result.<br>From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

The return value does not indicate that the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> are shown or hidden. This API does not take effect when it is called by a child window. The configuration does not take effect in non-full-screen mode (such as floating window or split-screen mode).

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setWindowSystemBarEnable](#setwindowsystembarenable9) in promise mode instead.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                                                  |
| -------- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names    | Array<'status'\|'navigation'> | Yes       | Whether to show the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> in full-screen mode.<br>For example, to show all of them, set this parameter to **['status',&nbsp;'navigation']**. If this parameter is set to [], they are hidden. |
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
// The following assumes that all of them are hidden.
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

Sets whether the main window layout or the child window layout is immersive. This API uses an asynchronous callback to return the result.
- An immersive layout means that the layout does not avoid the status bar or <!--RP15-->three-button navigation bar<!--RP15End-->, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [setWindowLayoutFullScreen](#setwindowlayoutfullscreen9) in promise mode instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name               | Type                      | Mandatory | Description                                                  |
| ------------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | Yes       | Whether the layout of the window is immersive. (In immersive layout mode, the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> remain visible.) The value **true** means that the window layout is immersive, and **false** means the opposite. |
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
| x        | number                    | Yes       | Coordinate position along the x-axis to which the window is moved, measured in px. A positive value means the position is to the right of the x-axis origin; a negative value means it is to the left; the value **0** means it is at the x-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down. |
| y        | number                    | Yes       | Coordinate position along the y-axis to which the window is moved, measured in px. A positive value means the position is below the y-axis origin; a negative value means it is above; the value **0** means it is at the y-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down. |
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
| x    | number | Yes       | Coordinate position along the x-axis to which the window is moved, measured in px. A positive value means the position is to the right of the x-axis origin; a negative value means it is to the left; the value **0** means it is at the x-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down. |
| y    | number | Yes       | Coordinate position along the y-axis to which the window is moved, measured in px. A positive value means the position is below the y-axis origin; a negative value means it is above; the value **0** means it is at the y-axis origin. The value must be an integer. If a non-integer is passed in, the value is rounded down. |

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

- The main window and child window have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.
- The minimum width and height of the main window and child window of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: (0, 1920] in width and (0, 1920] in height, both in units of vp.

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

- The main window and child window have the following default size limits: [320, 1920] in width and [240, 1920] in height, both in units of vp.
- The minimum width and height of the main window and child window of the application depends on the configuration on the product side. You can call [getWindowLimits](#getwindowlimits11) to obtain size limits.

The system window has the following size limits: (0, 1920] in width and (0, 1920] in height, both in units of vp.

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

Sets whether the main window or the child window is in full-screen mode. This API uses an asynchronous callback to return the result.
- Full-screen mode means that the layout does not avoid the status bar or <!--RP15-->three-button navigation bar<!--RP15End-->, and components may overlap with them.
- Non-full-screen mode means that the layout avoids the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9) and [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9) to implement the full-screen mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name         | Type                      | Mandatory | Description                                                  |
| ------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isFullScreen | boolean                   | Yes       | Whether to set full-screen mode (full-screen mode affects the display of the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->). The value **true** means to set full-screen mode, and **false** means the opposite. |
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

Sets whether the main window or the child window is in full-screen mode. This API uses a promise to return the result.
- Full-screen mode means that the layout does not avoid the status bar or <!--RP15-->three-button navigation bar<!--RP15End-->, and components may overlap with them.
- Non-full-screen mode means that the layout avoids the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9-1) and [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9-1) to implement the full-screen mode.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name         | Type    | Mandatory | Description                                                  |
| ------------ | ------- | --------- | ------------------------------------------------------------ |
| isFullScreen | boolean | Yes       | Whether to set full-screen mode (full-screen mode affects the display of the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->). The value **true** means to set full-screen mode, and **false** means the opposite. |

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

Sets whether the main window layout or the child window layout is immersive. This API uses an asynchronous callback to return the result.
- An immersive layout means that the layout does not avoid the status bar or <!--RP15-->three-button navigation bar<!--RP15End-->, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name               | Type                      | Mandatory | Description                                                  |
| ------------------ | ------------------------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean                   | Yes       | Whether the layout of the window is immersive. (Immersive layout mode does not affect the display of the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->.) The value **true** means that the window layout is immersive, and **false** means the opposite. |
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

Sets whether the main window layout or the child window layout is immersive. This API uses a promise to return the result.
- An immersive layout means that the layout does not avoid the status bar or <!--RP15-->three-button navigation bar<!--RP15End-->, and components may overlap with them.
- A non-immersive layout means that the layout avoids the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->, and components do not overlap with them.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowLayoutFullScreen()](#setwindowlayoutfullscreen9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name               | Type    | Mandatory | Description                                                  |
| ------------------ | ------- | --------- | ------------------------------------------------------------ |
| isLayoutFullScreen | boolean | Yes       | Whether the layout of the window is immersive. (Immersive layout mode does not affect the display of the status bar and <!--RP15-->three-button navigation bar<!--RP15End-->.) The value **true** means that the window layout is immersive, and **false** means the opposite. |

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

<!--RP14-->Sets whether to show the status bar and three-button navigation bar in the main window. The visibility of the status bar and three-button navigation bar is controlled by **status** and **navigation**, respectively.<!--RP14End--> This API uses an asynchronous callback to return the result.<br>From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

The return value does not indicate that the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> are shown or hidden. This API does not take effect when it is called by a child window. The configuration does not take effect in non-full-screen mode (such as floating window or split-screen mode).

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                                                  |
| -------- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names    | Array<'status'\|'navigation'> | Yes       | Whether to show the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> in full-screen mode.<br>For example, to show all of them, set this parameter to **['status',&nbsp;'navigation']**. If this parameter is set to [], they are hidden. |
| callback | AsyncCallback&lt;void&gt;     | Yes       | Callback used to return the result.                          |


**Example**

```ts
// The following assumes that all of them are hidden.
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

<!--RP14-->Sets whether to show the status bar and three-button navigation bar in the main window. The visibility of the status bar and three-button navigation bar is controlled by **status** and **navigation**, respectively.<!--RP14End--> This API uses a promise to return the result.<br>From API version 12, <!--RP5-->this API does not take effect on 2-in-1 devices.<!--RP5End-->

The return value does not indicate that the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> are shown or hidden. This API does not take effect when it is called by a child window. The configuration does not take effect in non-full-screen mode (such as floating window or split-screen mode).

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setWindowSystemBarEnable()](#setwindowsystembarenable9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name  | Type                          | Mandatory | Description                                                  |
| ----- | ----------------------------- | --------- | ------------------------------------------------------------ |
| names | Array<'status'\|'navigation'> | Yes       | Whether to show the status bar and <!--RP15-->three-button navigation bar<!--RP15End--> in full-screen mode.<br>For example, to show all of them, set this parameter to **['status',&nbsp;'navigation']**. If this parameter is set to [], they are hidden. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |


**Example**

```ts
// The following assumes that all of them are hidden.
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

Sets the properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar of the main window. This API uses an asynchronous callback to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a child window. The configuration does not take effect in non-full-screen mode (such as floating window or split-screen mode).

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarProperties()](#setwindowsystembarproperties9) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name                | Type                                        | Mandatory | Description                                                  |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar. |
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

Sets the properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar of the main window. This API uses a promise to return the result. <!--RP5-->This API does not take effect on 2-in-1 devices.<!--RP5End-->

This API does not take effect when it is called by a child window.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setWindowSystemBarProperties()](#setwindowsystembarproperties9-1) instead.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name                | Type                                        | Mandatory | Description                                                  |
| ------------------- | ------------------------------------------- | --------- | ------------------------------------------------------------ |
| systemBarProperties | [SystemBarProperties](#systembarproperties) | Yes       | Properties of the <!--Del-->three-button navigation bar and <!--DelEnd-->status bar. |

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

Loads content from a page to this window. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called multiple times, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

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

Loads content from a page to this window. This API uses a promise to return the result. You are advised to call this API during UIAbility startup. If called multiple times, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

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
import { BusinessError } from '@kit.BasicServicesKit';

let color: string = '#00ff33';
let promise = windowClass.setBackgroundColor(color);
promise.then(() => {
  console.info('Succeeded in setting the background color.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the background color. Cause code: ${err.code}, message: ${err.message}`);
});
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
| brightness | number                    | Yes       | Brightness to set. The value is a floating point number in the range [0.0, 1.0] or is set to **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness. |
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
| brightness | number | Yes       | Brightness to set. The value is a floating point number in the range [0.0, 1.0] or is set to **-1.0**. The value **1.0** means the brightest, and **-1.0** means the default brightness. |

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

Sets whether this window is focusable, that is, whether the window can gain focus after it is being operated or using other methods. This API uses an asynchronous callback to return the result.

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

Sets whether the area outside the child window is touchable. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
>
> Since API version 9, the area outside the child window is touchable by default. This API is no longer supported and no substitute API is provided.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type                      | Mandatory | Description                                                  |
| --------- | ------------------------- | --------- | ------------------------------------------------------------ |
| touchable | boolean                   | Yes       | Whether the area outside the child window is touchable. The value **true** means the area outside the child window is touchable, and **false** means the opposite. |
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

Sets whether the area outside the child window is touchable. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
>
> Since API version 9, the area outside the child window is touchable by default. This API is no longer supported and no substitute API is provided.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name      | Type    | Mandatory | Description                                                  |
| --------- | ------- | --------- | ------------------------------------------------------------ |
| touchable | boolean | Yes       | Whether the area outside the child window is touchable. The value **true** means the area outside the child window is touchable, and **false** means the opposite. |

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

Enumerates the lifecycle states of a window stage.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name                  | Value | Description                                                  |
| --------------------- | ----- | ------------------------------------------------------------ |
| SHOWN                 | 1     | The window stage is shown in the foreground, for example, when launching from the application icon, triggered whether it is the first launch or resuming from the background. |
| ACTIVE                | 2     | The window stage gains focus, for example, the state of the application window after handling a click event, or the state after the application is launched. |
| INACTIVE              | 3     | The window stage loses focus, for example, the state of the window that was in focus when a new application is opened or another window is clicked. |
| HIDDEN                | 4     | The window stage is running in the background, for example, when the application exists after swiping up or the application window is closed. |
| RESUMED<sup>11+</sup> | 5     | The window stage is interactive in the foreground, for example, when an application is opened and can interact with the user. |
| PAUSED<sup>11+</sup>  | 6     | The window stage is non-interactive in the foreground, for example, when the application enters the recent tasks screen after swiping up from the bottom of the screen. |

## ModalityType<sup>14+</sup>

Enumerates the modality types of the child window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

| Name                 | Value | Description                                                  |
| -------------------- | ----- | ------------------------------------------------------------ |
| WINDOW_MODALITY      | 0     | Window-modal. Select this value when you want the parent window not to respond to user interactions. |
| APPLICATION_MODALITY | 1     | Application-modal. Select this value when you want both the parent window and all windows of other instances of the application not to respond to user interactions.<br> This API can be used only on 2-in-1 devices. |

## SubWindowOptions<sup>11+</sup>

Describes the parameters used for creating a child window.

**System capability**: SystemCapability.Window.SessionManager

| Name                            | Type                            | Read-Only | Optional | Description                                                  |
| ------------------------------- | ------------------------------- | --------- | -------- | ------------------------------------------------------------ |
| title<sup>11+</sup>             | string                          | No        | No       | Title of the child window. The title display area should not go past the left side of the three-button area of the system. Any part that goes beyond will show as an ellipsis.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| decorEnabled<sup>11+</sup>      | boolean                         | No        | No       | Whether decorations are displayed in the child window. The value **true** means that decorations are displayed, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| isModal<sup>12+</sup>           | boolean                         | No        | Yes      | Whether the modal property is enabled for the child window. The value** true** means that the modal property is enabled for the child window, and **false** means to disable it. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |
| modalityType<sup>14+</sup>      | [ModalityType](#modalitytype14) | No        | Yes      | Modality type of the child window. This parameter takes effect only when the modal property is enabled for the child window. **WINDOW_MODALITY** means window-modal, and **APPLICATION_MODALITY** means application-modal. The default value is **WINDOW_MODALITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 14. |
| windowRect<sup>18+</sup>        | [Rect](#rect7)                  | No        | Yes      | Rectangle of the child window, and the size of the child window is limited. For details, see [resize()](#resize9). If this parameter is not specified, the window is displayed in full screen by default.<br>**Atomic service API**: This API can be used in atomic services since API version 18. |
| zLevel<sup>18+</sup>            | number                          | No        | Yes      | Z-level of the child window. This parameter is valid only when the modal property is not enabled for the child window, that is, **isModal** is not set. The value is an integer in the range [-10000, 10000]. Floating-point numbers will be rounded down. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 18. |
| maximizeSupported<sup>19+</sup> | boolean                         | No        | Yes      | Whether the child window supports maximization. <!--RP6-->This API can be used only on 2-in-1 devices. <!--RP6End-->The value **true** means that the child window supports maximization, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 19. |
| outlineEnabled<sup>20+</sup>    | boolean                         | No        | Yes      | Whether the child window displays an outline. <!--RP6-->This API can be used only on 2-in-1 devices. <!--RP6End-->The value **true** means that the child window displays an outline, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 20. |

## WindowStage<sup>9+</sup>

Implements a window manager, which manages each basic window unit, that is, [Window](#window) instance.

Before calling any of the following APIs, you must use [onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate) to create a **WindowStage** instance.

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
    console.info('onWindowStageCreate');
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
    console.info('onWindowStageCreate');
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
    console.info('onWindowStageCreate');
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

Creates a child window for this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                   | Mandatory | Description                               |
| -------- | -------------------------------------- | --------- | ----------------------------------------- |
| name     | string                                 | Yes       | Name of the child window.                 |
| callback | AsyncCallback&lt;[Window](#window)&gt; | Yes       | Callback used to return the child window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                               |
| ------- | ----------------------------------------------------------- |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.                              |

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

Creates a child window for this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type   | Mandatory | Description               |
| ---- | ------ | --------- | ------------------------- |
| name | string | Yes       | Name of the child window. |

**Return value**

| Type                             | Description                              |
| -------------------------------- | ---------------------------------------- |
| Promise&lt;[Window](#window)&gt; | Promise used to return the child window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                               |
| ------- | ----------------------------------------------------------- |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.                              |

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

Creates a child window for this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type                                    | Mandatory | Description                                    |
| ------- | --------------------------------------- | --------- | ---------------------------------------------- |
| name    | string                                  | Yes       | Name of the child window.                      |
| options | [SubWindowOptions](#subwindowoptions11) | Yes       | Parameters used for creating the child window. |

**Return value**

| Type                             | Description                                      |
| -------------------------------- | ------------------------------------------------ |
| Promise&lt;[Window](#window)&gt; | Promise used to return the child window created. |

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

Obtains all the child windows of this window stage. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                                | Mandatory | Description                                    |
| -------- | --------------------------------------------------- | --------- | ---------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Window](#window)&gt;&gt; | Yes       | Callback used to return all the child windows. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

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

Obtains all the child windows of this window stage. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type                                          | Description                                   |
| --------------------------------------------- | --------------------------------------------- |
| Promise&lt;Array&lt;[Window](#window)&gt;&gt; | Promise used to return all the child windows. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                  |
| ------- | ------------------------------ |
| 1300002 | This window state is abnormal. |

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

Loads the content of a page, with its path in the current project specified, to the main window of this window stage, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| path     | string                                                       | Yes       | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project. |
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | Yes       | Page-level UI state storage unit, which is used to transfer the state attribute for the page. |
| callback | AsyncCallback&lt;void&gt;                                    | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter. |
| 1300002 | This window state is abnormal.                               |

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
    console.info('onWindowStageCreate');
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

Loads the content of a page, with its path in the current project specified, to the main window of this window stage, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name    | Type                                                         | Mandatory | Description                                                  |
| ------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| path    | string                                                       | Yes       | Path of the page from which the content will be loaded. The path is configured in the **main_pages.json** file of the project. |
| storage | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | No        | Page-level UI state storage unit, which is used to transfer the state attribute for the page. |

**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter. |
| 1300002 | This window state is abnormal.                               |

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
    console.info('onWindowStageCreate');
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

Loads the content of a page, with its path in the current project specified, to the main window of this window stage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

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
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Invalid path parameter. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
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

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window stage, and transfers the state attribute to the page through a local storage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| name     | string                                                       | Yes       | Name of the named route page.                                |
| storage  | [LocalStorage](../../ui/state-management/arkts-localstorage.md) | Yes       | Page-level UI state storage unit, which is used to transfer the state attribute for the page. |
| callback | AsyncCallback&lt;void&gt;                                    | Yes       | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                               |

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
    console.info('onWindowStageCreate');
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
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
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

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window stage. This API uses an asynchronous callback to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

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
    console.info('onWindowStageCreate');
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

Loads the content of a [named route](../../ui/arkts-routing.md#named-route) page to this window stage, and transfers the state attribute to the page through a local storage. This API uses a promise to return the result. You are advised to call this API during UIAbility startup. If called repeatedly, this API will destroy the existing page content (UIContent) before loading the new content. Exercise caution when using it.

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
    console.info('onWindowStageCreate');
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
@Entry({routeName: entryName, useSharedStorage: true})
@Component
export struct Index {
  @State message: string = 'Hello World'
  @LocalStorageLink('storageSimpleProp') storageSimpleProp: number = 1;
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
    console.info('onWindowStageCreate');
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
    console.info('onWindowStageCreate');
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

### on('windowStageClose')<sup>14+</sup>

on(eventType: 'windowStageClose', callback: Callback&lt;void&gt;): void

Subscribes to the click event on the close button in the three-button navigation bar of the main window. This event is triggered when the close button in the three-button navigation bar of the main window is clicked. The registered lifecycle callback function [UIAbility.onPrepareToTerminate](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onpreparetoterminate10) is not executed.

If the event is subscribed to multiple times, only the most recently subscribed-to event takes effect.

The callback function in this API is executed synchronously. For asynchronous close events of the main window, refer to [on('windowWillClose')](#onwindowwillclose15).

If there is an existing event subscribed to by calling [on('windowWillClose')](#onwindowwillclose15), only the [on('windowWillClose')](#onwindowwillclose15) API will be responded to.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

**Parameters**

| Name      | Type                 | Mandatory | Description                                                  |
| --------- | -------------------- | --------- | ------------------------------------------------------------ |
| eventType | string               | Yes       | Event type. The value is fixed at **'windowStageClose'**, indicating that the close button in the three-button navigation bar of the main window is clicked |
| callback  | Callback&lt;void&gt; | Yes       | Callback invoked when the close button in the upper right corner of the main window is clicked. It does not return any parameter. The internal logic of the callback function requires a return value of the Boolean type. The return value determines whether to continue to close the main window. The value **true** means not to close the main window, and **false** means to continue to close the main window. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    try {
      windowStage.on('windowStageClose', () => {
        console.info('Succeeded in enabling the listener for window stage close event.');
        return false;
      });
    } catch (exception) {
      console.error(`Failed to enable the listener for window stage close event. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### off('windowStageClose')<sup>14+</sup>

off(eventType: 'windowStageClose', callback?: Callback&lt;void&gt;): void

Unsubscribes from the event indicating that the main window is closed.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 14.

**Parameters**

| Name      | Type                 | Mandatory | Description                                                  |
| --------- | -------------------- | --------- | ------------------------------------------------------------ |
| eventType | string               | Yes       | Event type. The value is fixed at **'windowStageClose'**, indicating that the close button in the three-button navigation bar of the main window is clicked. |
| callback  | Callback&lt;void&gt; | No        | Callback invoked when the close button in the upper right corner of the main window is clicked. It does not return any parameter. The internal logic of the callback function requires a return value of the Boolean type. The return value determines whether to continue to close the main window. The value **true** means not to close the main window, and **false** means to continue to close the main window. If a value is passed in, the corresponding subscription is canceled. If no value is passed in, all subscriptions to the specified event are canceled. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    const callback = () => {
      // ...
      return false;
    }
    try {
      windowStage.on('windowStageClose', callback);
      windowStage.off('windowStageClose', callback);
      windowStage.off('windowStageClose');
    } catch (exception) {
      console.error(`Failed to disable the listener for window stage close changes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### setDefaultDensityEnabled<sup>12+</sup>

setDefaultDensityEnabled(enabled: boolean): void

Sets whether the main window of the application uses the system's default density. Child windows and system windows will follow the main window's setting. Before calling this API, call [WindowStage.loadContent()](#loadcontent9-2) to initialize the layout to ensure the correct call sequence.

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
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit'

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
      windowStage.loadContent("pages/page2", (err: BusinessError) => {
        let errCode: number = err.code;
        if (errCode) {
          console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
          return;
        }
        console.info('onWindowStageCreate');
      try {
        windowStage.setDefaultDensityEnabled(true);
        console.info('Succeeded in loading the content.');
      } catch (exception) {
        console.error(`Failed to set default density enabled. Cause code: ${exception.code}, message: ${exception.message}`);
      }
    });
  }
};
```

### setCustomDensity<sup>15+</sup>

setCustomDensity(density: number): void

Allows the main window of the application to customize its display size scale factor. Child windows and system windows will follow the main window's setting. If both this API and [setDefaultDensityEnabled(true)](#setdefaultdensityenabled12) are called to set a display size scale factor, the setting from the last called API will be applied.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type   | Mandatory | Description                                                  |
| ------- | ------ | --------- | ------------------------------------------------------------ |
| density | number | Yes       | Custom display size scale factor. The value is a floating point number in the range [0.5, 4.0] or is set to **-1.0**. The value **4.0** indicates the largest permissible display size scale factor for the window, and **-1.0** means that the window uses the system's default display size scale factor. |

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
    console.info('onWindowStageCreate');
    try {
      windowStage.setCustomDensity(-1.0);
    } catch (exception) {
      console.error(`Failed to set custom density. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
};
```

### setWindowModal<sup>14+</sup>

setWindowModal(isModal: boolean): Promise&lt;void&gt;

Enables the modal property of the main window. This API uses a promise to return the result.

This API must be called by the main window and the setting takes effect for the main window. After the modal property of the main window is enabled, other main windows in the same application process and their child windows do not respond to user interactions until the main window is closed or the main window's modal property is disabled.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| isModal | boolean | Yes       | Whether to enable the modal property of the main window. The value **true** means to enable the modal property, and **false** means the opposite. |


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
| 1300005 | This window stage is abnormal.                               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setWindowModal(true);
      promise.then(() => {
        console.info('Succeeded in setting window modal');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window modal. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window modal. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### removeStartingWindow<sup>14+</sup>

removeStartingWindow(): Promise&lt;void&gt;

Allows the application to control the time when the launch page disappears.

This API takes effect only for the application main window when **enable.remove.starting.window** under **metadata** in [abilities](../../quick-start/module-configuration-file.md#abilities) in the **module.json5** file is set to **true**.

If the tag is set to **true**, the system provides timeout protection for the launch page. If this API is not called within 5 seconds, the system automatically removes the launch page.

If the tag is set to **false** or is not configured, this API does not take effect. The launch page will be automatically removed after the first frame of the application is rendered.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

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
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('onWindowStageCreate');
    windowStage.removeStartingWindow().then(() => {
      console.info('Succeeded in removing starting window.');
    }).catch((err: BusinessError) => {
        console.error(`Failed to remove starting window. Cause code: ${err.code}, message: ${err.message}`);
    });
  }
};
```

### setWindowRectAutoSave<sup>14+</sup>

setWindowRectAutoSave(enabled: boolean): Promise&lt;void&gt;

Enables or disables the auto-save feature for the size of the last closed main window. This API uses a promise to return the result. It takes effect only on 2-in-1 devices.

When the auto-save feature is enabled, within the same UIAbility, the size of the last closed main window is remembered. When this main window is restarted, it will open at the remembered size according to the rules.

The following rules apply in stacking scenarios:

1. If the current instance is a free-form window, the next opened window will adopt the same size when stacked.
2. If the current instance is maximized or in full-screen mode, the next opened window will maintain the maximized state when stacked.

The following table describes the memory rules:

| Last Window State   | Memorizing Rule                                              |
| ------------------- | ------------------------------------------------------------ |
| Free-form window    | Retains the size/position of the free-form window, rebound if exceeding the workspace. |
| Split-screen window | Retains the size and position of the free-form window before screen splitting. |
| Maximized window    | Retains the maximized state.                                 |
| Immersive window    | Retains the size and position of the free-form window before immersive mode. |
| Minimized window    | Retains the size and position of the free-form window before minimization. |

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name    | Type    | Mandatory | Description                                                  |
| ------- | ------- | --------- | ------------------------------------------------------------ |
| enabled | boolean | Yes       | Whether to enable the auto-save feature. The value **true** means to enable it, and **false** means to disable it. |


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

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setWindowRectAutoSave(true);
      promise.then(() => {
        console.info('Succeeded in setting window rect auto-save');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window rect auto-save. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window rect auto-save. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setWindowRectAutoSave<sup>17+</sup>

setWindowRectAutoSave(enabled: boolean, isSaveBySpecifiedFlag: boolean): Promise&lt;void&gt;

Enables or disables the auto-save feature for the size of the main window. This API uses a promise to return the result. It takes effect only on 2-in-1 devices.

Within the same UIAbility, you can remember the size of the last closed main window, or you can remember the size of each main window individually. The individual auto-save feature for each main window size is only available when the UIAbility launch mode is set to **specified** and the **isSaveBySpecifiedFlag** parameter is set to **true**.

When the auto-save feature is enabled, the size of the main window when it is closed is remembered. When the main window is restarted, it will open at the remembered size according to the rules.

The following table describes the memory rules:

| Last Window State   | Memorizing Rule                                              |
| ------------------- | ------------------------------------------------------------ |
| Free-form window    | Retains the size/position of the free-form window, rebound if exceeding the workspace. |
| Split-screen window | Retains the size and position of the free-form window before screen splitting. |
| Maximized window    | Retains the maximized state.                                 |
| Immersive window    | Retains the size and position of the free-form window before immersive mode. |
| Minimized window    | Retains the size and position of the free-form window before minimization. |

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 17.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name                  | Type    | Mandatory | Description                                                  |
| --------------------- | ------- | --------- | ------------------------------------------------------------ |
| enabled               | boolean | Yes       | Whether to enable the auto-save feature. The value **true** means to enable it, and **false** means to disable it. |
| isSaveBySpecifiedFlag | boolean | Yes       | Whether to enable the individual auto-save feature when the UIAbility launch mode is set to **specified**. The value **true** means to enable it, and **false** means to disable it. |


**Return value**

| Type                | Description                    |
| ------------------- | ------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Function setWindowRectAutoSave can not work correctly due to limited device capabilities. |
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
    try {
      let promise = windowStage.setWindowRectAutoSave(true, true);
      promise.then(() => {
        console.info('Succeeded in setting window rect auto-save');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window rect auto-save. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window rect auto-save. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### isWindowRectAutoSave<sup>14+</sup>

isWindowRectAutoSave(): Promise&lt;boolean&gt;

Checks whether the auto-save feature is enabled for the main window's size. This API uses a promise to return the result. It takes effect only on 2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Window.SessionManager

**Return value**

| Type                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the auto-save feature is enabled, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Window Error Codes](errorcode-window.md).

| ID      | Error Message                                                |
| ------- | ------------------------------------------------------------ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                               |
| 1300003 | This window manager services works abnormally.               |

**Example**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.isWindowRectAutoSave();
      promise.then((data) => {
        console.info(`Succeeded in checking whether the window support the rect auto-save. Data: ${data}`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to check whether the window support the rect auto-save. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to check whether the window support the rect auto-save. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```

### setSupportedWindowModes<sup>15+</sup>

setSupportedWindowModes(supportedWindowModes: Array<bundleManager.SupportWindowMode>): Promise&lt;void&gt;

Sets the supported window modes of the main window. This API uses a promise to return the result.

<!--RP6-->This API can be used only on 2-in-1 devices.<!--RP6End-->

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name                 | Type                                                         | Mandatory | Description                                                  |
| -------------------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| supportedWindowModes | Array&lt;[bundleManager.SupportWindowMode](../apis-ability-kit/js-apis-bundleManager.md#supportwindowmode)&gt; | Yes       | Supported window modes.<br>- **FULL_SCREEN**: full-screen mode.<br>- **FLOATING**: floating window mode.<br>- **SPLIT**: split-screen mode. **FULL_SCREEN** or **FLOATING** must be used together. Configuring only **SPLIT** is not supported.<br>Note: The values of the **SupportWindowMode** field in the array should not conflict with the values of the **supportWindowMode** field under [abilities](../../quick-start/module-configuration-file.md#abilities) of the [module.json5 file](../../quick-start/module-configuration-file.md) corresponding to this UIAbility, or with the values of the **supportWindowModes** field in [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions). In case of a conflict, the window support mode set by this parameter will take precedence. |

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

**Example**

```ts
// EntryAbility.ets
import { UIAbility, bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    try {
      let promise = windowStage.setSupportedWindowModes([
        bundleManager.SupportWindowMode.FULL_SCREEN,
        bundleManager.SupportWindowMode.SPLIT,
        bundleManager.SupportWindowMode.FLOATING
      ]);
      promise.then(() => {
        console.info('Succeeded in setting window support modes');
      }).catch((err: BusinessError) => {
        console.error(`Failed to set window support modes. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      console.error(`Failed to set window support modes. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
}
```
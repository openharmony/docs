# Interfaces (Others)

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Configuration<sup>9+</sup>

Describes the parameters for creating a child window or system window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name| Type| Mandatory| Description                                                                         |
| ---------- | -------------------------- | -- |-----------------------------------------------------------------------------|
| name       | string                     | Yes| Name of the window.                                                                      |
| windowType | [WindowType](arkts-apis-window-e.md#windowtype7) | Yes| Window type.                                                                      |
| ctx        | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | No| Current application context. If no value is passed, no context is used.<br>In the FA model, do not pass in this parameter when creating a child window. Otherwise, an error is reported.<br>In the stage model, you must pass in this parameter when creating a floating window, modal window, or system window.|
| displayId  | number                     | No| ID of the current physical screen. If no value is passed, the default value **-1** is used. The value must be an integer.                                            |
| parentId   | number                     | No| ID of the parent window. If no value is passed, the default value **-1** is used. The value must be an integer.                                                          |
| decorEnabled<sup>12+</sup> | boolean | No| Whether the window decoration is enabled. This parameter is valid only when **windowType** is set to **TYPE_DIALOG**. The value **true** means that the window decoration is enabled, and **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|
| title<sup>12+</sup> | string| No| Title of the window when **decorEnabled** is set to **true**. The title display area should not go past the left side of the three-button area of the system. Any part that goes beyond will show as an ellipsis. If this parameter is not set, an empty string is used.<br>**System capability**: SystemCapability.Window.SessionManager|
| defaultDensityEnabled<sup>20+</sup> | boolean| No| Whether the window should use the default density of the system. If the default density is used, the window does not change layout when the system display size changes.<br>If this parameter is set to **true** for a system window, the window uses the default density and is not affected by [setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12) or [setCustomDensity()](arkts-apis-window-WindowStage.md#setcustomdensity15) settings for the main window.<br>If this parameter is set to **false**, the window does not use the default density and is affected by those settings.<br>The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|

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
| leftRect   | [Rect](arkts-apis-window-i.md#rect7) | Yes  | Yes  | Rectangle on the left of the screen.|
| topRect    | [Rect](arkts-apis-window-i.md#rect7) | Yes  | Yes  | Rectangle at the top of the screen.|
| rightRect  | [Rect](arkts-apis-window-i.md#rect7) | Yes  | Yes  | Rectangle on the right of the screen.|
| bottomRect | [Rect](arkts-apis-window-i.md#rect7) | Yes  | Yes  | Rectangle at the bottom of the screen.|

## Size<sup>7+</sup>

Describes the window size.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type| Readable| Writable| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | Yes  | Yes  | Window width, in px. The value must be an integer.|
| height | number   | Yes  | Yes  | Window height, in px. The value must be an integer.|

## RectChangeOptions<sup>12+</sup>

Describes the value and reason returned upon a window rectangle (position and size) change.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type     | Readable| Writable| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| rect   | [Rect](arkts-apis-window-i.md#rect7) | Yes  | Yes  | New value of the window rectangle.|
| reason    | [RectChangeReason](arkts-apis-window-e.md#rectchangereason12) | Yes  | Yes  | Reason for the window rectangle change.|

## AvoidAreaOptions<sup>12+</sup>

Describes the new area where the window cannot be displayed. The new area is returned when the corresponding event is triggered.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type     | Readable| Writable| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| type   | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | Yes  | Yes  | Type of the new area returned.|
| area   | [AvoidArea](arkts-apis-window-i.md#avoidarea7)         | Yes  | Yes  | New area returned.|

## WindowProperties

Describes the window properties.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name                                 | Type                 | Read-Only| Optional| Description                                                                                                    |
| ------------------------------------- | ------------------------- | ---- | ---- |--------------------------------------------------------------------------------------------------------|
| windowRect<sup>7+</sup>               | [Rect](arkts-apis-window-i.md#rect7)             | No  | No  | Window size, which can be obtained from the page lifecycle [onPageShow](./arkui-ts/ts-custom-component-lifecycle.md#onpageshow) or the application lifecycle [onForeground](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground).<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                                                 |
| drawableRect<sup>11+</sup>            | [Rect](arkts-apis-window-i.md#rect7)             | No  | No  | Size of the rectangle that can be drawn in the window. The upper boundary and left boundary are calculated relative to the window. In the stage model, this API must be used after [loadContent()](arkts-apis-window-Window.md#loadcontent9) or [setUIContent()](arkts-apis-window-Window.md#setuicontent9) is called to load the page content.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                 |
| type<sup>7+</sup>                     | [WindowType](arkts-apis-window-e.md#windowtype7) | No  | No  | Window type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                 |
| isFullScreen                          | boolean                   | No  | No  | Whether the window is displayed in full-screen mode. The default value is **false**. The value **true** means that the window is displayed in full-screen mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                                 |
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | No  | No  | Whether the window is immersive and in full-screen mode (not in floating window or split-screen scenarios). The default value is **false**. The value **true** means that the window is immersive and in full-screen mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                                                                                                           |
| focusable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window can gain focus. The default value is **true**. The value **true** means that the window can gain focus, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                               |
| touchable<sup>7+</sup>                | boolean                   | Yes  | No  | Whether the window is touchable. The default value is **true**. The value **true** means that the window is touchable, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                |
| brightness                            | number                    | No  | No  | Screen brightness. The value is a floating point number in the range [0.0, 1.0], and the value **1.0** means the brightest. If no value is passed, the brightness follows the system. In this case, the obtained brightness value is **-1**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                     |
| dimBehindValue<sup>(deprecated)</sup> | number                    | No  | No  | Dimness of the window that is not on top. The value is a floating point number in the range [0.0, 1.0], and the value **1.0** means the dimmest.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9.<br>Currently, no substitute is available.|
| isKeepScreenOn                        | boolean                   | No  | No  | Whether the screen is always on. The default value is **false**. The value **true** means that the screen is always on, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                                                                  |
| isPrivacyMode<sup>7+</sup>            | boolean                   | No  | No  | Whether the window is in privacy mode. The default value is **false**. The value **true** means that the window is in privacy mode, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                 |
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | No  | No  | Whether the window has rounded corners. The default value is **false**. The value **true** means that the window has rounded corners, and **false** means the opposite.<br>**NOTE**<br>This property is supported since API version 7 and deprecated since API version 9.<br>Currently, no substitute is available.|
| isTransparent<sup>7+</sup>            | boolean                   | No  | No  | Whether the window background is transparent. The default value is **false**. The value **true** means that the window background is transparent, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                                                                  |
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

## WindowLimits<sup>11+</sup>

Describes the window size limits. You can call [setWindowLimits](arkts-apis-window-Window.md#setwindowlimits11) to set the window size limits and call [getWindowLimits](arkts-apis-window-Window.md#getwindowlimits11) to obtain the current window size limits.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name     | Type  | Readable| Writable| Description                                                        |
| :-------- | :----- | :--- | :--- | :----------------------------------------------------------- |
| maxWidth  | number | Yes  | Yes  | Maximum window width, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the maximum width specified by the system. |
| maxHeight | number | Yes  | Yes  | Maximum window height, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the maximum height specified by the system. |
| minWidth  | number | Yes  | Yes  | Minimum window width, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the minimum width specified by the system. |
| minHeight | number | Yes  | Yes  | Minimum window height, in px. The value must be an integer. The default value is **0**, indicating that the property does not change. The lower limit is **0**, and the upper limit is the minimum height specified by the system. |

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
| windowRect<sup>15+</sup> | [Rect](arkts-apis-window-i.md#rect7)  | Yes| Window rectangle, that is, the position and size of the window on the display.|

## KeyboardInfo<sup>18+</sup>

Describes the information about the soft keyboard window.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Mandatory| Description                                      |
| ------ | ------ | ---- | ------------------------------------------ |
| beginRect | [Rect](arkts-apis-window-i.md#rect7)  | Yes| Position and size of the soft keyboard before the animation starts.|
| endRect | [Rect](arkts-apis-window-i.md#rect7)  | Yes| Position and size of the soft keyboard before the animation ends.|
| animated<sup>20+</sup> | boolean  | No| Whether there is a show/hide animation. The value **true** means that there is a show/hide animation, and **false** means the opposite.|
| config<sup>20+</sup> | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)  | No| Animation configuration.|

## ShowWindowOptions<sup>20+</sup>

Describes the parameters for displaying a child window or system window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name  | Type  | Mandatory| Description                                      |
| ------ | ------ | ---- | ------------------------------------------ |
| focusOnShow | boolean  | No| Whether the window automatically gains focus when [showWindow()](arkts-apis-window-Window.md#showwindow20) is called. The default is **true**. This parameter does not take effect for the main window, modal window, and dialog boxes.|

## WindowAnimationConfig<sup>20+</sup>

Describes the configuration for window animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name    | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| curve    | [WindowAnimationCurve](arkts-apis-window-e.md#windowanimationcurve20)           | Yes  | Type of animation curve.                                              |
| duration | number                                                    | No  | Duration for playing the animation, in milliseconds (ms).<br>The default value is 0, and the maximum value is 3000.<br>Whether it is required depends on the animation curve type.|
| param    | [WindowAnimationCurveParam](arkts-apis-window-i.md#windowanimationcurveparam20) | No  | Parameters for the animation curve. Whether it is required depends on the animation curve type.                |

## WindowInfo<sup>18+</sup>

Describes the window information.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| rect  | [Rect](arkts-apis-window-i.md#rect7)   | Yes  | No  | Window size.|
| bundleName  | string   | Yes  | No  | Bundle name of the application.         |
| abilityName | string   | Yes  | No  | Ability name.              |
| windowId | number | Yes  | No  | Window ID.  |
| windowStatusType | [WindowStatusType](arkts-apis-window-e.md#windowstatustype11) | Yes  | No  | Window mode.  |
| isFocused | boolean | Yes  | Yes  | Whether the window gains focus. The value **true** means that the window gains focus, and **false** means the opposite.  |

## TransitionAnimation<sup>20+</sup>

Describes the window transition animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name   | Type                                             | Mandatory| Description                                                        |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| config  | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20) | Yes  | Transition animation configuration.                                          |
| opacity | number                                            | No  | Opacity of the window during the transition animation. If this parameter is set to **0**, the window is completely transparent. When the animation type is **WindowTransitionType.DESTROY**, this represents the opacity at the end of the animation. The value ranges from 0 to 1. The value is reset to **1** when the animation ends.|

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

## RotationChangeInfo<sup>19+</sup>

Describes the window information obtained during window rotation changes.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| type | [RotationChangeType](arkts-apis-window-e.md#rotationchangetype19) | No| No| Type of window rotation event.|
| orientation | number | No| No| Display orientation of the window.<br>- **0**: portrait.<br>- **1**: reverse landscape.<br>- **2**: reverse portrait.<br>- **3**: landscape.<br>Note that the orientation here is different from the orientation property of the display object.|
| displayId | number | No| No| ID of the screen where the window is located.|
| displayRect | [Rect](arkts-apis-window-i.md#rect7) | No| No| Size of the rectangle after the screen where the window is located is rotated.|

## RotationChangeResult<sup>19+</sup>

Describes the information returned by the application during window rotation changes. 

The system uses the information to adjust the size of the current window rectangle. If the returned information is about the rotation change of the main window, the system does not change the size of the main window.

There are limitations on the size of application windows and system windows. For details about specific restrictions and rules, see [resize](arkts-apis-window-Window.md#resize9).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| rectType | [RectType](arkts-apis-window-e.md#recttype19) | No| No| Type of window rectangle coordinate system.|
| windowRect | [Rect](arkts-apis-window-i.md#rect7) | No| No| Information about the window's rectangle relative to the screen or parent window coordinate system.|

## RotationChangeCallback<sup>19+</sup>

### (info: T)<sup>19+</sup>

(info: T): U;

Describes a generic callback function for rotation event notifications.

In this callback function, the parameter type is [RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19), and the return value type is [RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)\|void.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | -------------------------- |
| info | T    | Yes  | Parameter of type [RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19) passed by the system when the callback function is called.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------ |
| U | Value of type [RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)\|void.| |

## SubWindowOptions<sup>11+</sup>

Describes the parameters used for creating a child window.

**System capability**: SystemCapability.Window.SessionManager

| Name     | Type | Read-Only| Optional| Description        |
| ---------- | ---- | ---- | ---- | ----------- |
| title<sup>11+</sup>    | string | No| No| Title of the child window. The title display area should not go past the left side of the three-button area of the system. Any part that goes beyond will show as an ellipsis.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| decorEnabled<sup>11+</sup> | boolean | No| No| Whether decorations are displayed in the child window. The value **true** means that decorations are displayed, and **false** means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| isModal<sup>12+</sup>    | boolean | No| Yes| Whether the modal property is enabled for the child window. The value** true** means that the modal property is enabled for the child window, and **false** means to disable it. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| modalityType<sup>14+</sup>    | [ModalityType](arkts-apis-window-e.md#modalitytype14) | No| Yes| Modality type of the child window. This parameter takes effect only when the modal property is enabled for the child window. **WINDOW_MODALITY** means window-modal, and **APPLICATION_MODALITY** means application-modal. The default value is **WINDOW_MODALITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 14.      |
| windowRect<sup>18+</sup>    | [Rect](arkts-apis-window-i.md#rect7) | No| Yes| Rectangle of the child window, and the size of the child window is limited. For details, see [resize()](arkts-apis-window-Window.md#resize9). If this parameter is not specified, the window is displayed in full screen by default.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| zLevel<sup>18+</sup>    | number | No| Yes| Z-level of the child window. This parameter is valid only when the modal property is not enabled for the child window, that is, **isModal** is not set. The value is an integer in the range [-10000, 10000]. Floating-point numbers will be rounded down. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| maximizeSupported<sup>19+</sup>    | boolean | No| Yes| Whether the child window supports maximization. <!--RP6-->This API can be used only on 2-in-1 devices. <!--RP6End-->The value **true** means that the child window supports maximization, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| outlineEnabled<sup>20+</sup>    | boolean | No| Yes| Whether the child window displays an outline. <!--RP6-->This API can be used only on 2-in-1 devices. <!--RP6End-->The value **true** means that the child window displays an outline, and **false** means the opposite. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

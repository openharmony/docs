# Interfaces (Others)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - For the system capability SystemCapability.Window.SessionManager, use [canIUse()](../common/js-apis-syscap.md#caniuse) to check whether the device supports this system capability and the corresponding APIs.

## Configuration<sup>9+</sup>

Describes the parameters for creating a child window or system window.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Type| Read-Only| Optional| Description                                                                         |
| ---------- | -------------------------- | -- | -- |-----------------------------------------------------------------------------|
| name       | string                     | No| No| Window name.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core                                              |
| windowType | [WindowType](arkts-apis-window-e.md#windowtype7) | No| No| Window type.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core                       |
| ctx        | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | No| Yes| Current application context. If no value is passed, no context is used.<br>In the FA model, do not pass in this parameter when creating a child window. Otherwise, an error is reported.<br>In the stage model, you must pass in this parameter when creating a floating window, modal window, or system window.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| displayId  | number                     | No| Yes| Screen ID of the current window. If it is not set, the screen ID of the parent window is used by default.<br>The value is a non-negative integer and must correspond to an existing screen.<br>In scenarios involving extended screens or heterogeneous virtual screens, a global floating window can be displayed on a specified screen by setting the screen ID.<br>For modal windows and system windows, this parameter takes no effect, and the parent window's screen ID is used by default.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core    |
| parentId   | number                     | No| Yes| ID of the parent window. If this parameter is not set, the default value **-1** is used. The default parent window is the main window corresponding to the current application context.<br>In the FA model, the parameter value must be a non-negative integer and must correspond to an existing parent window.<br>This parameter is invalid in the stage model.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core                                              |
| decorEnabled<sup>12+</sup> | boolean | No| Yes| Whether the window decoration is enabled. This parameter is valid only when **windowType** is set to **TYPE_DIALOG**. **true** if enabled, **false** otherwise. The default value is **false**.<br>**System capability**: SystemCapability.Window.SessionManager|
| title<sup>12+</sup> | string| No| Yes| Title of the window when **decorEnabled** is set to **true**. The title display area should not go past the left side of the three-button area of the system. Any part that goes beyond will show as an ellipsis. If this parameter is not set, an empty string is used.<br>**System capability**: SystemCapability.Window.SessionManager|

## SystemBarProperties

Describes the properties of the status bar<!--Del--> and three-button navigation bar<!--DelEnd-->.

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                                  | Type| Read-Only| Optional| Description                                                        |
| -------------------------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   |  No |  Yes  | Background color of the status bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. The default value is **'#66000000'**.<br> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isStatusBarLightIcon<sup>7+</sup>      | boolean  |  No |  Yes  | Whether any icon on the status bar is highlighted. **true** if highlighted, **false** otherwise. The default value is **false**.<br> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| statusBarContentColor<sup>8+</sup>     | string   |  No |  Yes  | Color of the text on the status bar. After this property is set, the setting of **isStatusBarLightIcon** is invalid. The default value is **'#E5FFFFFF'**.<br> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| navigationBarColor                     | string   |  No |  Yes  | Background color of the three-button navigation bar. The value is a hexadecimal RGB or ARGB color code and is case insensitive, for example, **'#00FF00'** or **'#FF00FF00'**. The default value is **'#66000000'**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  |  No |  Yes  | Whether any icon on the three-button navigation bar is highlighted. **true** if highlighted, **false** otherwise. The default value is **false**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| navigationBarContentColor<sup>8+</sup> | string   |  No |  Yes  | Color of the text on the three-button navigation bar. After this property is set, the setting of **isNavigationBarLightIcon** is invalid. The default value is **'#E5FFFFFF'**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.WindowManager.WindowManager.Core|
| enableStatusBarAnimation<sup>12+</sup> | boolean  |  No |  Yes  | Whether to enable animation for a status bar property change. **true** to enable, **false** otherwise. The default value is **false**.<br> **System capability**: SystemCapability.Window.SessionManager|
| enableNavigationBarAnimation<sup>12+</sup> | boolean   |  No |  Yes  | Whether to enable animation for a three-button navigation bar property change. **true** to enable, **false** otherwise. The default value is **false**.<br><!--RP13--><!--RP13End--> **System capability**: SystemCapability.Window.SessionManager|

## StatusBarProperty<sup>18+</sup>

Describes the properties of the status bar. These properties are returned when you query the status bar's configuration details.

**Atomic service API**: This API can be used in atomic services since API version 18.

| Name                                  | Type|  Read-Only|   Optional | Description|
| ------------------------------------- | -------- | ---- | ---- | ------- |
| contentColor     | string   |  No |  No  | Color of the text on the status bar. The value is in ARGB format, for example, **#E5FFFFFF**.<br> **System capability**: SystemCapability.Window.SessionManager|

## SystemBarStyle<sup>12+</sup>

Describes the properties of the status bar. These properties are valid for the page-level status bar.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

| Name  | Type| Read-Only| Optional| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| statusBarContentColor   | string   | No  | Yes  | Color of the text on the status bar. The default value is **'#E5FFFFFF'**.|

## FrameMetrics<sup>22+</sup>

Enumerates the metrics for frame performance.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only| Optional| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| firstDrawFrame   | boolean   | No  | No  | Whether the frame is the first frame. **true** for first frame, **false** otherwise.|
| inputHandlingDuration    | number   | No  | No  | Duration of gesture handling in a frame, in nanoseconds.|
| layoutMeasureDuration  | number   | No  | No  | Duration of layout measurement in a frame, in nanoseconds.|
| vsyncTimestamp | number   | No  | No  | Timestamp marking the start of the current frame, in nanoseconds.|

## Rect<sup>7+</sup>

Describes the rectangular area of the window.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type| Read-Only| Optional| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | No  | No  | Left boundary of the rectangle, in px. The value must be an integer.|
| top    | number   | No  | No  | Top boundary of the rectangle, in px. The value must be an integer.|
| width  | number   | No  | No  | Width of the rectangle, in px. The value must be an integer.|
| height | number   | No  | No  | Height of the rectangle, in px. The value must be an integer.|

## RectInVP<sup>23+</sup>

Describes the rectangular area of the window, in vp.

**Model constraint**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only| Optional| Description              |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | No  | No  | Left boundary of the rectangle, in vp.|
| top    | number   | No  | No  | Top boundary of the rectangle, in vp.|
| width  | number   | No  | No  | Width of the rectangle, in vp.|
| height | number   | No  | No  | Height of the rectangle, in vp.|

## AvoidArea<sup>7+</sup>

Describes the area to avoid for window content.

When adapting window content for an [immersive layout](../../windowmanager/window-terminology.md#immersive-layout), you should adjust the content based on the corresponding **AvoidArea** specified by [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7).

In the avoid area, the application window content is obscured and does not respond to user click events.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name      | Type     | Read-Only| Optional| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| visible<sup>9+</sup>    | boolean       | No  | No  | Whether the avoid area is visible. **true** if visible, **false** otherwise.|
| leftRect   | [Rect](arkts-apis-window-i.md#rect7) | No  | No  | Rectangle centered to the left of the window's two diagonals.|
| topRect    | [Rect](arkts-apis-window-i.md#rect7) | No  | No  | Rectangle centered at the top of the window's two diagonals.|
| rightRect  | [Rect](arkts-apis-window-i.md#rect7) | No  | No  | Rectangle centered to the right of the window's two diagonals.|
| bottomRect | [Rect](arkts-apis-window-i.md#rect7) | No  | No  | Rectangle centered at the bottom of the window's two diagonals.|

> **NOTE**
>
> The figure below shows the meanings of **leftRect**, **topRect**, **rightRect**, and **bottomRect**.
>
>  ![avoidArea](figures/avoidArea.png)

## UIEnvAvoidAreaVP<sup>23+</sup>

Describes the information about the window avoidance area in units of vp, which requires careful attention during [immersive layout](../../windowmanager/window-terminology.md#immersive-layout) adaptation.

**System capability**: SystemCapability.Window.SessionManager

| Name      | Type     | Read-Only| Optional| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| visible    | boolean       | No  | No  | Whether the avoid area is visible. **true** if visible, **false** otherwise.|
| leftRect   | [RectInVP](#rectinvp23) | No  | No  | Rectangle centered to the left of the window's two diagonals, in vp.|
| topRect    | [RectInVP](#rectinvp23) | No  | No  | Rectangle centered at the top of the window's two diagonals, in vp.|
| rightRect  | [RectInVP](#rectinvp23) | No  | No  | Rectangle centered to the right of the window's two diagonals, in vp.|
| bottomRect | [RectInVP](#rectinvp23) | No  | No  | Rectangle centered at the bottom of the window's two diagonals, in vp.|

## UIEnvWindowAvoidAreaInfoPX<sup>23+</sup>

Describes [environment variable](../../ui/arkts-env-system-property.md) data types for window avoidance areas of different types. All types of window avoidance areas are measured in px.

**System capability**: SystemCapability.Window.SessionManager

| Name      | Type     | Read-Only| Optional| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| statusBar            | [AvoidArea](#avoidarea7) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_SYSTEM** type, in px.|
| cutout               | [AvoidArea](#avoidarea7) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_CUTOUT** type, in px.|
| keyboard             | [AvoidArea](#avoidarea7) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_KEYBOARD** type, in px.|
| navigationIndicator  | [AvoidArea](#avoidarea7) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_NAVIGATION_INDICATOR** type, in px.|

## UIEnvWindowAvoidAreaInfoVP<sup>23+</sup>

Describes [environment variable](../../ui/arkts-env-system-property.md) data types for window avoidance areas of different types. All types of window avoidance areas are measured in vp.

**System capability**: SystemCapability.Window.SessionManager

| Name      | Type     | Read-Only| Optional| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| statusBar            | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_SYSTEM** type, in vp.|
| cutout               | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_CUTOUT** type, in vp.|
| keyboard             | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_KEYBOARD** type, in vp.|
| navigationIndicator  | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | No  | No  | Avoidance area whose [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) is **TYPE_NAVIGATION_INDICATOR** type, in vp.|

## Size<sup>7+</sup>

Describes the window size, in px.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name  | Type| Read-Only| Optional| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | No  | No  | Window width, in px. The value must be an integer.|
| height | number   | No  | No  | Window height, in px. The value must be an integer.|

## SizeInVP<sup>23+</sup>

Describes the window size, in vp.

**Model constraint**: This API can be used only in the stage model.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only| Optional| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | No  | No  | Window width, in vp. The value is a floating-point number.|
| height | number   | No  | No  | Window height, in vp. The value is a floating-point number.|

## Position<sup>20+</sup>

Describes the position of the window or component.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only| Optional| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| x      | number   | No  | No  | X coordinate, in px. The value must be an integer.|
| y      | number   | No  | No  | Y coordinate, in px. The value must be an integer.|

## RectChangeOptions<sup>12+</sup>

Describes the value and reason returned upon a window rectangle (position and size) change.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type     | Read-Only| Optional| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| rect   | [Rect](arkts-apis-window-i.md#rect7) | No  | No  | New value of the window rectangle.|
| reason    | [RectChangeReason](arkts-apis-window-e.md#rectchangereason12) | No  | No  | Reason for the window rectangle change.|

## AvoidAreaOptions<sup>12+</sup>

Returns the new avoid area and its type after the system avoid area changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name      | Type     | Read-Only| Optional| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| type   | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | No  | No  | Type of the new avoid area returned after the system avoid area changes.|
| area   | [AvoidArea](arkts-apis-window-i.md#avoidarea7)         | No  | No  | New avoid area returned after the system avoid area changes.|

## WindowProperties

Describes the window properties.

| Name                                 | Type                 | Read-Only| Optional| Description                                                                                                    |
| ------------------------------------- | ------------------------- | ---- | ---- |--------------------------------------------------------------------------------------------------------|
| windowRect<sup>7+</sup>               | [Rect](arkts-apis-window-i.md#rect7)             | No  | No  | Window size, which can be obtained via [onPageShow](./arkui-ts/ts-custom-component-lifecycle.md#onpageshow) or [onForeground](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground). Note that the left and top boundaries of the window are calculated relative to the top-left corner of the screen where the window is located.<br> **Atomic service API**: This API can be used in atomic services since API version 11.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| drawableRect<sup>11+</sup>            | [Rect](arkts-apis-window-i.md#rect7)             | No  | No  | Size of the rectangle that can be drawn in the window. The upper boundary and left boundary are calculated relative to the top-left vertex of the window. In the stage model, this property should be obtained after [loadContent()](arkts-apis-window-Window.md#loadcontent9) or [setUIContent()](arkts-apis-window-Window.md#setuicontent9) is called to load the page content.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| type<sup>7+</sup>                     | [WindowType](arkts-apis-window-e.md#windowtype7) | No  | No  | Window type.<br>Currently, the type returned by the [getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9) API called by the main window may be inaccurate. The window type has been specified during window creation, so you do not need to obtain the window type again using the **getWindowProperties()** API.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isFullScreen                          | boolean                   | No  | No  |Whether the status bar is hidden when **isLayoutFullScreen** is set to **true**. If the status bar is hidden, the return value is **true**. In other cases, the return value is **false**.<br> **Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | No  | No  | Whether an [immersive layout](../../windowmanager/window-terminology.md#immersive-layout) is set for a child window. If an immersive-layout is set for the child window, the return value is **true**.<br>Whether an [immersive layout](../../windowmanager/window-terminology.md#immersive-layout) is set for the main window and the main window is in full-screen mode. If an immersive-layout is set for the main window and the main window is in full-screen mode, the return value is **true**.<br>In other cases, the return value is **false**.<br> **Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| focusable<sup>7+</sup>                | boolean                   | No  | No  | Whether the window is focusable. **true** if focusable, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| touchable<sup>7+</sup>                | boolean                   | No  | No  | Whether the window is touchable. **true** if touchable, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| brightness                            | number                    | No  | No  | Screen brightness of the window. The brightness can be set by calling [setWindowBrightness()](arkts-apis-window-Window.md#setwindowbrightness9). The value is a floating-point number. Valid values are in the range [0.0, 1.0] (where **1.0** means the brightest) or the special value **-1.0** (which means that the brightness follows the system). If no value is passed, the brightness follows the system. In this case, the obtained brightness value is **-1.0**.<br> **Atomic service API**: This API can be used in atomic services since API version 11.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| dimBehindValue<sup>(deprecated)</sup> | number                    | No  | No  | Dimness of the window that is not on top. The value is a floating-point number in the range [0.0, 1.0], and the value **1.0** means the dimmest.<br>Note: This property is supported since API version 7 and deprecated since API version 9. Currently, no substitute is available.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isKeepScreenOn                        | boolean                   | No  | No  | Whether the screen is always on. **true** if always on, **false** otherwise.<br> **Atomic service API**: This API can be used in atomic services since API version 11.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isPrivacyMode<sup>7+</sup>            | boolean                   | No  | No  | Whether the window is in privacy mode. **true** if the window is in privacy mode, **false** otherwise. You can call [setWindowPrivacyMode()](arkts-apis-window-Window.md#setwindowprivacymode9) to set the privacy mode of the window.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | No  | No  | Whether the window has rounded corners. **true** if the window has rounded corners; **false** otherwise.<br>Note: This property is supported since API version 7 and deprecated since API version 9. Currently, no substitute is available.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| isTransparent<sup>7+</sup>            | boolean                   | No  | No  | Whether the window background is transparent. **true** if transparent, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| id<sup>9+</sup>                       | number                    | No  | No  | Window ID. The value is an integer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| displayId<sup>12+</sup>               | number                    | No  | Yes  | ID of the screen where the window is located. By default, the ID of the main screen is returned. The value is an integer.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| name<sup>18+</sup>               | string                    | No  | Yes  | Window name. The default value is an empty string.<br>**Atomic service API**: This API can be used in atomic services since API version 18.<br>**System capability**: SystemCapability.WindowManager.WindowManager.Core|
| globalDisplayRect<sup>20+</sup> | [Rect](arkts-apis-window-i.md#rect7)   | No  | Yes  | Window size in the global coordinate system. In extended screen scenarios, the top-left corner of the primary screen is used as the coordinate origin. In virtual screen scenarios, the top-left corner of the virtual screen is used as the coordinate origin. The default value is [0, 0, 0, 0].<br>**System capability**: SystemCapability.Window.SessionManager|

## DecorButtonStyle<sup>14+</sup>

Describes the button style of the system decoration bar.

**System capability**: SystemCapability.Window.SessionManager

| Name      | Type     | Read-Only| Optional| Description              |
| ---------- | ------------- | ---- | ---- | ------------------ |
| colorMode   | [ConfigurationConstant.ColorMode](../apis-ability-kit/js-apis-app-ability-configurationConstant.md#colormode) | No  | Yes  | Color mode. Buttons automatically adapt to light colors in dark mode and to dark colors in light mode. If this parameter is not set, they will automatically match the system color mode.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| buttonBackgroundSize   | number        | No  | Yes  | Size of the button when it is highlighted. The value ranges from 20 vp to 40 vp. The default value is 28 vp.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| spacingBetweenButtons  | number        | No  | Yes  | Spacing between buttons. The value ranges from 8 vp to 24 vp. The default value is 12 vp.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| closeButtonRightMargin | number        | No  | Yes  | Margin between the rightmost edge of the close button and the window. The value ranges from 6 vp to 22 vp. The default value is 20 vp.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| buttonIconSize<sup>20+</sup> | number        | No  | Yes  | Size of the button icon. The value ranges from 16 vp to 24 vp. The default value is 20 vp.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| buttonBackgroundCornerRadius<sup>20+</sup> | number        | No  | Yes  | Radius of the button background rounded corner. The value ranges from 4 vp to 8 vp. The default value is 4 vp.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## WindowLimits<sup>11+</sup>

Describes the parameters for window size limits. Applications can obtain the current window size limits (in px) via [getWindowLimits](arkts-apis-window-Window.md#getwindowlimits11). Starting from API version 22, they can also be obtained via [getWindowLimitsVP](arkts-apis-window-Window.md#getwindowlimitsvp22) (in vp).

The actual window size limits applied are determined by the intersection of the default system limits, application configurations, and runtime settings, with the priority (from highest to lowest) as follows:

1. Window size limits configured by the application via [setWindowLimits](arkts-apis-window-Window.md#setwindowlimits11).
2. Window size limits specified by the application via [StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions) when the application starts the window through [startAbility](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability-2). (This approach is supported since API version 17.)
3. Window size limits configured by the application in [abilities in the module.json5 file](../../quick-start/module-configuration-file.md#abilities).
4. Default system limits (which vary depending on the product and window type).

**System capability**: SystemCapability.Window.SessionManager

> **NOTE**
>
> For the **maxWidth**, **maxHeight**, **minWidth**, and **minHeight** properties:
>
> - The default unit is px. Starting from API version 22, the unit can be px or vp, depending on the setting of **pixelUnit**.
> - The value is an integer. Floating-point values will be rounded down.
> - The default value is **0**, indicating that the property does not change.
> - The lower bound of the effective range is the minimum height/width limited by the system.
> - The upper bound of the effective range is the maximum height/width limited by the system.

| Name     | Type  | Read-Only| Optional| Description                                                         |
| :-------- | :----- | :--- | :--- | :----------------------------------------------------------- |
| maxWidth  | number | No  | Yes  | Maximum window width.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| maxHeight | number | No  | Yes  | Maximum window height.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| minWidth  | number | No  | Yes  | Minimum window width.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| minHeight | number | No  | Yes  | Minimum window height.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| pixelUnit<sup>22+</sup> | [PixelUnit](arkts-apis-window-e.md#pixelunit22) | No| Yes| Unit of the window size limits. The default value is **px**. The value can be **px** or **vp**.|

## TitleButtonRect<sup>11+</sup>

Describes the rectangle used to hold the minimize, maximize, and close buttons on the title bar. This rectangle is located in the top-right corner of the window.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| right  | number | No  | No  | Right boundary of the rectangle, in vp. The value must be an integer.|
| top    | number | No  | No  | Top boundary of the rectangle, in vp. The value must be an integer.|
| width  | number | No  | No  | Width of the rectangle, in vp. The value must be an integer.  |
| height | number | No  | No  | Height of the rectangle, in vp. The value must be an integer.  |

## MoveConfiguration<sup>15+</sup>

Describes the window movement configuration.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| displayId | number | No| Yes|Target display ID. The value must be an integer. If a non-integer is passed in, the value is rounded down. The default value is **undefined**. If this parameter is passed in, the window is positioned relative to the top-left corner of the target display. If this parameter is left empty or set to **undefined**, or the target display ID does not exist, the window is positioned relative to the top-left corner of the current display.|

## WindowDensityInfo<sup>15+</sup>

Describes the information about the display density of the screen where the window is located and the window's custom display density. It is a scale factor independent of pixel units, that is, a factor for scaling display size.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only| Optional| Description      |
| ------ | -------- | ---- | ---- | ---------- |
| systemDensity  | number   | No  | No  | System's display size scale factor for the screen where the window is located. The value ranges from 0.5 to 4.0 and varies according to user settings.|
| defaultDensity | number   | No  | No  | Default display size scale factor for the screen where the window is located. The value ranges from 0.5 to 4.0 and varies with the screen.|
| customDensity | number   | No  | No  | Custom display size scale factor of the window. The value ranges from 0.5 to 4.0. If this parameter is left unspecified, the system's display size scale factor is used. This parameter takes effect only for the main window. For the child window or system window, it is equivalent to the system's display size scale factor (**systemDensity**).|

## WindowInfoOptions
Describes the window layout information filtering options.

**Since**: 26.0.0

**Model constraint**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| excludeSystemWindows | boolean | No| Yes| Whether to exclude system windows. The value **true** indicates yes and the value **false** indicates no. The default value is **false**.|
| foregroundAboveWindow | number  | No| Yes| ID of a window. Windows whose level is not higher than that of this window will be filtered out. Only information about windows whose level is higher than that of this window will be returned. The default value is **0**, indicating that this option is ignored. If the passed value is less than 0, error code 1300016 will be returned. A non-existent window ID is treated as **0**.|
| foregroundBelowWindow | number  | No| Yes| ID of a window. Windows whose level is not lower than that of this window will be filtered out. Only information about windows whose level is lower than that of this window will be returned. The default value is **0**, indicating that this option is ignored. If the passed value is less than 0, error code 1300016 will be returned. A non-existent window ID is treated as **0**. If both **foregroundBelowWindow** and **foregroundAboveWindow** are set to a valid value but the level of the window specified by **foregroundBelowWindow** is not higher than that of the window specified by **foregroundAboveWindow**, an empty array will be returned.|

## WindowLayoutInfo<sup>15+</sup>

Describes the information about the window layout.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| windowRect | [Rect](arkts-apis-window-i.md#rect7)  | No| No| Window rectangle, that is, the position and size of the window on the display.<br> **Atomic service API**: This API can be used in atomic services since API version 15.|
| windowAlpha | number  | No| Yes| Window opacity. The value range is [0.0, 1.0], where **0.0** indicates completely transparent, and **1.0** indicates completely opaque. The default value is **-1.0**, indicating that the window opacity is not obtained or the query fails.<br>**Since**: 26.0.0<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>**Model constraint**: This API can be used only in the stage model.|

## KeyboardInfo<sup>18+</sup>

Describes the information about the soft keyboard window.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| beginRect | [Rect](arkts-apis-window-i.md#rect7)  |  No |  No  | Position and size of the soft keyboard before the animation starts.<br> **Atomic service API**: This API can be used in atomic services since API version 18.|
| endRect | [Rect](arkts-apis-window-i.md#rect7)  |  No |  No  | Position and size of the soft keyboard after the animation ends.<br> **Atomic service API**: This API can be used in atomic services since API version 18.|
| animated<sup>20+</sup> | boolean  |  No |  Yes  | Whether there is a show/hide animation. **true** if there is a show/hide animation, **false** otherwise.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|
| config<sup>20+</sup> | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)  |  No |  Yes | Animation configuration.<br> **Atomic service API**: This API can be used in atomic services since API version 20.|

## ShowWindowOptions<sup>20+</sup>

Describes the parameters for displaying a child window or system window.

**System capability**: SystemCapability.Window.SessionManager

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| focusOnShow | boolean  |  No |  Yes | Whether the window automatically gains focus when [showWindow()](arkts-apis-window-Window.md#showwindow20) is called. The default value is **true**. This parameter does not take effect for the main window, modal window, and dialog boxes.|

## WindowAnimationConfig<sup>20+</sup>

Describes the configuration for window animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name    | Type                                                     | Read-Only| Optional| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ---- |------------------------------------------------------------ |
| curve    | [WindowAnimationCurve](arkts-apis-window-e.md#windowanimationcurve20)           |  No |  No  | Type of animation curve.                                              |
| duration | number                                                    |  No |  Yes  | Duration for playing the animation, in milliseconds (ms).<br>The default value is 0, and the maximum value is 3000.<br>Whether it is required depends on the animation curve type.|
| param    | [WindowAnimationCurveParam](arkts-apis-window-t.md#windowanimationcurveparam20) |  No |  Yes  | Parameters for the animation curve. Whether it is required depends on the animation curve type.                |

## WindowInfo<sup>18+</sup>

Describes the window information.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type  | Read-Only| Optional| Description                                      |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| rect  | [Rect](arkts-apis-window-i.md#rect7)   | No  | No  | Window size.|
| bundleName  | string   | No  | No  | Bundle name of the application.         |
| abilityName | string   | No  | No  | Ability name.              |
| windowId | number | No  | No  | Window ID.  |
| windowStatusType | [WindowStatusType](arkts-apis-window-e.md#windowstatustype11) | No  | No  | Window mode.  |
| isFocused | boolean | No  | Yes  | Whether the window gains focus. **true** if the window gains focus, **false** otherwise. The return value is the same as that of the [isFocused()](arkts-apis-window-Window.md#isfocused12) API.  |
| globalDisplayRect<sup>20+</sup> | [Rect](arkts-apis-window-i.md#rect7)   | No  | Yes  | Window size in the global coordinate system. In extended screen scenarios, the top-left corner of the primary screen is used as the coordinate origin. In virtual screen scenarios, the top-left corner of the virtual screen is used as the coordinate origin. The default value is [0, 0, 0, 0].|
| displayId | number | No| Yes| ID of the screen where the window is located. By default, the ID of the main screen is returned. The value is an integer.<br>**Since**: 26.0.0<br> **Model constraint**: This API can be used only in the stage model.|
| globalRect | [Rect](arkts-apis-window-i.md#rect7) | No| Yes| Actual display area of the window on the physical screen. If the window has been resized, the actual on-screen location and size of the window after resizing are returned. The default value is [0, 0, 0, 0].<br>**Since**: 26.0.0<br> **Model constraint**: This API can be used only in the stage model.|

## TransitionAnimation<sup>20+</sup>

Describes the window transition animation.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Window.SessionManager

| Name   | Type                                             | Read-Only| Optional| Description                                                        |
| ------- | ------------------------------------------------- | ---- | ---- |------------------------------------------------------------ |
| config  | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20) |  No |  No  | Transition animation configuration.                                          |
| opacity | number                                            |  No |  Yes  | Opacity of the window during the transition animation. If this parameter is set to **0**, the window is completely transparent. The default value is **1.0**. When the animation type is **WindowTransitionType.DESTROY**, this represents the opacity at the end of the animation. The value ranges from 0 to 1.0. The value is reset to **1.0** when the animation ends.|

## StartAnimationParams<sup>20+</sup>

Describes the parameters for the startup animation.

The configuration is valid only for transitions between different abilities within the same application.

The configuration is valid only full-screen applications.

**Device behavior differences**: The API can be called properly on phones that are not working in [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode and tablets that are working in neither freeform window nor desktop mode. On phones and tablets in freeform window or desktop mode and other devices, calls to this API do not take effect or return an error.

**System capability**: SystemCapability.Window.SessionManager
| Name            | Type                                                                    | Read-Only| Optional| Description                                                        |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type             | [AnimationType](arkts-apis-window-e.md#animationtype20)                 | No  | No  | Type of the window animation.|

## WindowCreateParams<sup>20+</sup>

Describes the window parameters during application startup.

**System capability**: SystemCapability.Window.SessionManager
| Name            | Type                                                                    | Read-Only| Optional| Description                                                        |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| animationParams             | [StartAnimationParams](arkts-apis-window-i.md#startanimationparams20)                 | No  | Yes  | Parameters for the startup animation. The default value is **undefined**. If this parameter is not set, the default animation of the system is used.|
| needAnimation<sup>23+</sup> | boolean | No| Yes| Whether to enable the window creation animation.<br>If this parameter is set to **true**, the system's default animation will be used. If this parameter is set to **false**, the window creation animation is disabled. This value takes effect for [freeform windows](../../windowmanager/window-terminology.md#freeform-window) only.<br>If this parameter is not set, it defaults to **undefined** and the system's default animation will be used.<br> **Model constraint**: This API can be used only in the stage model.|

## Callback<sup>15+</sup>

### (data: T)<sup>15+</sup>

(data: T): V

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

Describes the information returned by the application during window rotation changes. The system uses the information to adjust the size of the current window rectangle. If the returned information is about the rotation change of the main window, the system does not change the size of the main window.

There are limitations on the size of application windows and system windows. For details about specific restrictions and rules, see [resize](arkts-apis-window-Window.md#resize9).

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| rectType | [RectType](arkts-apis-window-e.md#recttype19) | No| No| Type of window rectangle coordinate system.|
| windowRect | [Rect](arkts-apis-window-i.md#rect7) | No| No| Information about the window's rectangle relative to the screen or parent window coordinate system.|

## OrientationResult

Enumerates the result of setting the window display orientation.

**Since**: 26.0.0

**Model constraint**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| executionResult | [OrientationExecutionResult](arkts-apis-window-e.md#orientationexecutionresult) | No| No| Result of setting the window display orientation.|

## SubWindowOptions<sup>11+</sup>

Describes the parameters used for creating a child window.

**System capability**: SystemCapability.Window.SessionManager

| Name     | Type | Read-Only| Optional| Description        |
| ---------- | ---- | ---- | ---- | ----------- |
| title<sup>11+</sup>    | string | No| No| Title of the child window. The title display area should not go past the left side of the three-button area of the system. Any part that goes beyond will show as an ellipsis.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| decorEnabled<sup>11+</sup> | boolean | No| No| Whether decorations are displayed in the child window. **true** if displayed, **false** otherwise.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| isModal<sup>12+</sup>    | boolean | No| Yes| Whether the modal property is enabled for the child window. **true** if enabled, **false** otherwise. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| modalityType<sup>14+</sup>    | [ModalityType](arkts-apis-window-e.md#modalitytype14) | No| Yes| Modality type of the child window. This parameter takes effect only when the modal property is enabled for the child window. The default value is **WINDOW_MODALITY**.<br>**Atomic service API**: This API can be used in atomic services since API version 14.      |
| windowRect<sup>18+</sup>    | [Rect](arkts-apis-window-i.md#rect7) | No| Yes| Rectangle of the child window, and the size of the child window is limited. For details, see [resize()](arkts-apis-window-Window.md#resize9). If this parameter is not set and [showWindow()](arkts-apis-window-Window.md#showwindow9) is not called, the default value {left: 0, top: 0, width: 0, height: 0} is used. For details, see [Setting an App Subwindow](../../windowmanager/application-window-stage.md#setting-an-app-subwindow).<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| zLevel<sup>18+</sup>    | number | No| Yes| Z-level of the child window. This parameter is valid only when the modal property is not enabled for the child window, that is, **isModal** is not set. The value is an integer in the range [-10000, 10000]. Floating-point numbers will be rounded down. The default value is **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| maximizeSupported<sup>19+</sup>    | boolean | No| Yes| Whether the child window supports maximization. **true** if supported, **false** otherwise. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 19.<br> **Device behavior differences**: This parameter can be used properly on devices that support the [freeform window](../../windowmanager/window-terminology.md#freeform-window) mode and are currently in that mode. On devices that do not support the freeform window mode, the API call will neither take effect nor report an error when this parameter is used as an input. On devices that support the freeform window mode but are not currently in that mode, the API call will neither take effect nor report an error when this parameter is used as an input. The setting will take effect after the devices switch to that mode.|
| outlineEnabled<sup>20+</sup>    | boolean | No| Yes| Whether the child window displays an outline. **true** if displayed, **false** otherwise. The default value is **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 20.<br> **Device behavior differences**: This parameter works properly on 2-in-1 devices, and on other devices in desktop mode. If it is used as an input parameter in other scenarios, the corresponding API neither takes effect nor reports an error.|

## KeyFramePolicy<sup>20+</sup>

Describes the configuration for keyframe policies.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| enable | boolean | No| No| Whether to enable keyframes. **true** to enable, **false** otherwise.|
| interval | number | No| Yes| Time interval for triggering keyframe layout changes via dragging, in ms. The default value is **1000**. The value is a positive integer. Floating-point values are rounded down. It works with **distance** using an OR condition. If either of them is met, the layout change starts.|
| distance | number | No| Yes| Distance interval for triggering keyframe layout changes via dragging, in px. The default value is **1000**. The value is **0** or a positive integer. Floating-point values are rounded down. If the value is 0, the drag distance is ignored. It works with **interval** using an OR condition. If either of them is met, the layout change starts.|
| animationDuration | number | No| Yes| Duration of the animation for keyframe layout changes, in ms. The default value is **100**. The value is **0** or a positive integer. Floating-point values are rounded down.|
| animationDelay | number | No| Yes| Delay before the animation for keyframe layout changes starts, in ms. The default value is **100**. The value is **0** or a positive integer. Floating-point values are rounded down.|

## MainWindowInfo<sup>21+</sup>

Describes the main window information.

**System capability**: SystemCapability.Window.SessionManager

| Name  | Type| Read-Only | Optional| Description                   |
| ------ | ---- | ----- | ---- | ----------------------- |
| displayId | number  | No| No| ID of the display to which the main window belongs.|
| windowId  | number  | No| No| ID of the main window.|
| showing   | boolean | No| No| Foreground/Background status of the main window. **true** if the main window is in the foreground, **false** otherwise.|
| label     | string  | No| No| Task name of the main window.|

## WindowSnapshotConfiguration<sup>21+</sup>

Describes the configuration of the main window screenshot.

**System capability**: SystemCapability.Window.SessionManager

| Name    | Type     | Read-Only| Optional| Description              |
| -------- | -------- | ---- | ---- | ------------------ |
| useCache | boolean  | No  | Yes  | Whether the existing screenshot of the main window should be used. The default value is **true**. When it is set to **true**, the system uses the existing screenshot of the main window, or captures the latest screenshot if no existing screenshot is saved. When it is set to **false**, the system captures the latest screenshot of the main window.|

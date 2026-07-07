# Enums
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 针对系统能力SystemCapability.Window.SessionManager，请先使用[canIUse()](../common/js-apis-syscap.md#caniuse)接口判断当前设备是否支持此syscap及对应接口。

## WindowType<sup>7+</sup>

窗口类型枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                  | 值 | 说明                                                                                     |
|-------------------------------------| ------ |----------------------------------------------------------------------------------------|
| TYPE_APP                            | 0      | 表示应用子窗口。<br>**模型约束：** 此接口仅可在FA模型下使用。                                                   |
| TYPE_SYSTEM_ALERT<sup>(deprecated)</sup>               | 1     | 表示系统告警窗口。<br>**说明：** 从API version 11开始废弃。<br>从API version 7开始支持。                           |
| TYPE_FLOAT<sup>9+</sup>             | 8      | 表示全局悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| TYPE_DIALOG<sup>10+</sup>           | 16      | 表示模态窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| TYPE_MAIN<sup>18+</sup>             | 32      | 表示应用主窗口。<br>此窗口类型不支持在创建窗口时使用。                               |

## WindowPostureMode

窗口姿态模式枚举。

**系统能力：** SystemCapability.Window.SessionManager

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

| 名称 | 值 | 说明 |
| ---- | ---- | ---- |
| DESKTOP_MODE | 0 | 桌面模式。当满足以下条件时处于桌面模式：<br>1. 窗口所在屏幕折叠状态为半折叠状态（[FoldStatus.FOLD_STATUS_HALF_FOLDED](js-apis-display.md#foldstatus10)）；<br>2. 通过[getLiveCreaseRegion()](js-apis-display.md#getlivecreaseregion20)获取的creaseRects宽度大于高度；<br>3. 窗口模式为全屏模式（[WindowStatusType.FULL_SCREEN](#windowstatustype11)）且窗口尺寸与屏幕尺寸相同。 |

## AvoidAreaType<sup>7+</sup>

窗口内容的避让区域的类型枚举。

窗口内容做[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)适配时，需要按照AvoidAreaType对应的[AvoidArea](arkts-apis-window-i.md#avoidarea7)做窗口内容避让。

| 名称                             | 值   | 说明                                                         |
| -------------------------------- | ---- | ------------------------------------------------------------ |
| TYPE_SYSTEM                      | 0    | 表示系统默认区域。<!--RP11-->包含状态栏和三键导航栏区域。<!--RP11End--> <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core <br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| TYPE_CUTOUT                      | 1    | 表示挖孔区域。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core <br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| TYPE_SYSTEM_GESTURE<sup>9+</sup> | 2    | 表示侧边返回手势区域。当前所有设备均无此类型避让区域。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| TYPE_KEYBOARD<sup>9+</sup>       | 3    | 表示固定态软键盘区域。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core <br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| TYPE_NAVIGATION_INDICATOR<sup>11+</sup> | 4    | 表示底部导航区域。当三键导航显示时，底部导航避让区域始终存在。<!--Del-->OpenHarmony各设备不支持此能力。<!--DelEnd--> <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core <br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| TYPE_FLOAT_NAVIGATION | 5    | 表示三键导航区域。<!--RP12-->OpenHarmony各设备不支持此能力。<!--RP12End--> <br>**系统能力：** SystemCapability.Window.SessionManager<br> **起始版本：** 26.0.0<br> **模型约束：** 此接口仅可在Stage模型下使用。<br> **原子化服务API：** 从API version 26.0.0开始，该接口支持在原子化服务中使用。|

## SplitRatioPreference

窗口分屏比例的类型枚举。

<!--Del-->当前OpenHarmony各设备不支持此接口。<!--DelEnd-->

<!--RP1--><!--RP1End-->

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                             | 值   | 说明                                                         |
| -------------------------------- | ---- | ------------------------------------------------------------ |
| EQUAL                            | 0    | 表示系统为主分屏和次分屏窗口分配同样大小的窗口比例。<br>未指定字段值时该字段为默认值。 |
| PRIMARY_DOMINANT                 | 1    | 表示系统为主分屏窗口分配当前设备所允许的较大可用比例。 |
| SECONDARY_DOMINANT               | 2    | 表示系统为次分屏窗口分配当前设备所允许的较大可用比例。 |

<!--RP13-->

<!--RP13End-->

## Orientation<sup>9+</sup>

窗口显示方向类型枚举。<!--Del-->不同枚举值之间的区别可查询[窗口Orientation枚举值8\~10或12和枚举值13\~16的区别(API9)](../../faqs/faqs-window-manager.md#窗口orientation枚举值810或12和枚举值1316的区别api9)。<!--DelEnd-->

| 名称                                  | 值   | 说明                          |
| ------------------------------------- | ---- | ----------------------------- |
| UNSPECIFIED                           | 0    | 表示未定义方向模式，由系统判定。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| PORTRAIT                              | 1    | 表示竖屏显示模式。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| LANDSCAPE                             | 2    | 表示横屏显示模式。<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| PORTRAIT_INVERTED                     | 3    | 表示反向竖屏显示模式。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| LANDSCAPE_INVERTED                    | 4    | 表示反向横屏显示模式。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION                         | 5    | 跟随传感器自动旋转，可以旋转到竖屏、横屏、反向竖屏、反向横屏四个方向，且不受控制中心的旋转开关控制。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION_PORTRAIT                | 6    | 跟随传感器自动竖向旋转，可以旋转到竖屏、反向竖屏，无法旋转到横屏、反向横屏，且不受控制中心的旋转开关控制。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_LANDSCAPE               | 7    | 跟随传感器自动横向旋转，可以旋转到横屏、反向横屏，无法旋转到竖屏、反向竖屏，且不受控制中心的旋转开关控制。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core。<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION_RESTRICTED              | 8    | 跟随传感器自动旋转，可以旋转到竖屏、横屏、反向竖屏、反向横屏四个方向，且受控制中心的旋转开关控制。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| AUTO_ROTATION_PORTRAIT_RESTRICTED     | 9    | 跟随传感器自动竖向旋转，可以旋转到竖屏、反向竖屏，无法旋转到横屏、反向横屏，且受控制中心的旋转开关控制。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_LANDSCAPE_RESTRICTED    | 10   | 跟随传感器自动横向旋转，可以旋转到横屏、反向横屏，无法旋转到竖屏、反向竖屏，且受控制中心的旋转开关控制。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| LOCKED                                | 11   | 表示锁定模式，窗口显示方向与屏幕当前方向一致。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| AUTO_ROTATION_UNSPECIFIED<sup>12+</sup>        | 12   | 跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定（如在某种设备，可以旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_PORTRAIT<sup>12+</sup>           | 13   | 调用时临时旋转到竖屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定（如在某种设备，可以旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_LANDSCAPE<sup>12+</sup>          | 14   | 调用时临时旋转到横屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定（如在某种设备，可以旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_PORTRAIT_INVERTED<sup>12+</sup>  | 15   | 调用时临时旋转到反向竖屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定（如在某种设备，可以旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| USER_ROTATION_LANDSCAPE_INVERTED<sup>12+</sup> | 16   | 调用时临时旋转到反向横屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定（如在某种设备，可以旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏）。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|
| FOLLOW_DESKTOP<sup>12+</sup>                   | 17   | 表示跟随桌面的旋转模式，如果桌面可以旋转则可旋转，桌面不可旋转则不可旋转。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br> **系统能力：** SystemCapability.Window.SessionManager|

## RectChangeReason<sup>12+</sup>

窗口矩形（窗口位置及窗口大小）变化的原因。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称                  | 值   | 说明                                                         |
| --------------------- | ---- | ------------------------------------------------------------ |
| UNDEFINED                 | 0    | 默认值，表示窗口矩形变化的原因未定义。      |
| MAXIMIZE                | 1    | 窗口最大化。 |
| RECOVER              | 2    | 窗口恢复到上一次的状态。                                                   |
| MOVE | 3    | 窗口拖拽移动。 |
| DRAG  | 4    | 窗口拖拽缩放。 |
| DRAG_START  | 5    | 窗口开始拖拽缩放。 |
| DRAG_END  | 6    | 窗口结束拖拽缩放。 |

## ColorSpace<sup>8+</sup>

色域模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 值 | 说明           |
| ---------- | ------ | -------------- |
| DEFAULT    | 0      | 默认SRGB色域模式。 |
| WIDE_GAMUT | 1      | 广色域模式。   |

## WindowEventType<sup>10+</sup>

窗口生命周期。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称       | 值 | 说明       |
| ---------- | ------ | ---------- |
| WINDOW_SHOWN      | 1      | 切到前台。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_ACTIVE     | 2      | 获焦状态。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_INACTIVE   | 3      | 失焦状态。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_HIDDEN     | 4      | 切到后台。<br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| WINDOW_DESTROYED<sup>11+</sup>  | 7      | 窗口销毁。<br> **系统能力：** SystemCapability.Window.SessionManager|

## WindowStatusType<sup>11+</sup>

窗口模式枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 0    | 表示APP未定义窗口模式。       |
| FULL_SCREEN | 1    | 表示APP全屏模式。<br>[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，窗口铺满整个屏幕，默认无dock栏、标题栏和状态栏显示。<br>可通过[maximize()](arkts-apis-window-Window.md#maximize12)和[setTitleAndDockHoverShown()](arkts-apis-window-Window.md#settitleanddockhovershown14)配置，当hover到热区时是否显示标题栏和dock栏。<br>当maximize()和setTitleAndDockHoverShown()接口都调用时，以最后调用设置的效果为准。<br>非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，窗口铺满整个屏幕，无标题栏和dock栏显示。可通过[setSpecificSystemBarEnabled()](arkts-apis-window-Window.md#setspecificsystembarenabled11)配置是否显示状态栏。|
| MAXIMIZE    | 2    | 表示APP窗口最大化模式，[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，窗口铺满整个屏幕，不需要hover就可以显示dock栏、状态栏和标题栏。非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下，不存在该状态。|
| MINIMIZE    | 3    | 表示APP窗口最小化模式。 |
| FLOATING    | 4    |表示APP自由悬浮形式窗口模式，窗口可以自由移动和缩放，适用于需要多窗口同时使用的场景。   |
| SPLIT_SCREEN  | 5    | 表示APP分屏模式，屏幕同时显示两个应用窗口，每个窗口占据屏幕的一半空间，适用于多任务并行处理的场景。   |

## PixelUnit<sup>22+</sup>

像素单位枚举。

物理像素单位和虚拟像素单位换算可使用[px2vp](./arkts-apis-uicontext-uicontext.md#px2vp12)和[vp2px](./arkts-apis-uicontext-uicontext.md#vp2px12)。

**系统能力：** SystemCapability.Window.SessionManager

| 名称    | 值   | 说明   |
| ------- | ---- | ----- |
| PX | 0  | 物理像素单位（px）。  |
| VP | 1  | 虚拟像素单位（vp）。  |

## MaximizePresentation<sup>12+</sup>

窗口最大化时的布局枚举。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| FOLLOW_APP_IMMERSIVE_SETTING  | 0    | 最大化时，跟随应用app当前设置的全屏模式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。       |
| EXIT_IMMERSIVE | 1    | 最大化时，如果当前窗口设置了全屏模式会退出全屏模式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。             |
| ENTER_IMMERSIVE    | 2    | 最大化时，进入全屏模式，鼠标Hover在热区上显示窗口标题栏和dock栏。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。   |
| ENTER_IMMERSIVE_DISABLE_TITLE_AND_DOCK_HOVER<sup>14+</sup>    | 3    | 最大化时，进入全屏模式，鼠标Hover在热区上不显示窗口标题栏和dock栏。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。   |

## AcrossDisplayPresentation

折叠屏的跨屏策略枚举，用于控制折叠2in1设备在悬停态下主窗口最大化时的瀑布流模式行为。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| FOLLOW_ACROSS_DISPLAY_SETTING  | 0    | 跟随当前跨屏策略设置。若未设置过跨屏策略，则使用系统默认策略：设备悬停态下，窗口进入单屏最大化（即窗口最大化时只在上半屏或下半屏显示）；展开态下，窗口最大化并在折回悬停态时保持瀑布流模式（即窗口跨上下两半屏显示）。     |
| ENTER_ACROSS_DISPLAY_MODE | 1    | 设备悬停态下，窗口直接进入瀑布流模式；展开态下，窗口最大化并在折回悬停态时保持瀑布流模式。             |
| EXIT_ACROSS_DISPLAY_MODE    | 2    | 设备悬停态下，窗口退出瀑布流模式，进入单屏最大化；展开态下，窗口最大化并在折回悬停态时退出瀑布流模式。   |

## WindowAnimationCurve<sup>20+</sup>

窗口动画曲线类型。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称                | 值   | 说明                                                         |
| ------------------- | ---- | ------------------------------------------------------------ |
| LINEAR              | 0    | 表示动画从头到尾的速度都是相同的。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中duration必填。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中param选填，且不生效。 |
| INTERPOLATION_SPRING | 1    | 表示插值器弹簧曲线，一条从0到1的动画曲线，实际动画值根据曲线进行插值计算。动画时间由曲线参数决定，不受[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中的duration参数控制。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中duration选填，且不生效。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中param必填。 |
| CUBIC_BEZIER | 2 | 表示贝塞尔曲线。<br/>使用该曲线类型时[WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)中的param和duration为必填项。 |

## WindowTransitionType<sup>20+</sup>

窗口转场动画类型枚举。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称    | 值   | 说明                       |
| ------- | ---- | -------------------------- |
| DESTROY | 0    | 表示窗口销毁时的转场动画。 |

## AnimationType<sup>20+</sup>

窗口动画类型枚举。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称    | 值   | 说明                       |
| ------- | ---- | -------------------------- |
| FADE_IN_OUT | 0    | 表示窗口动画类型为淡入淡出。淡入动画在窗口显示过程中生效，淡出动画在窗口隐藏过程中生效。 |

## WindowAnchor<sup>20+</sup>

窗口锚点枚举。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| TOP_START  | 0    | 窗口左上角。|
| TOP  | 1    | 窗口上边界横向居中点。|
| TOP_END  | 2    | 窗口右上角。|
| START  | 3    | 窗口左边界纵向居中点。|
| CENTER  | 4    | 窗口横向和纵向居中点。|
| END  | 5    | 窗口右边界纵向居中点。|
| BOTTOM_START  | 6    | 窗口左下角。|
| BOTTOM  | 7    | 窗口下边界横向居中点。|
| BOTTOM_END  | 8    | 窗口右下角。|

## RotationChangeType<sup>19+</sup>

窗口旋转事件类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   |  值 | 说明                   |
| ------ | ---- | --------------------- |
| WINDOW_WILL_ROTATE| 0 | 窗口即将旋转。 |
| WINDOW_DID_ROTATE | 1 | 窗口旋转结束。 |

## RectType<sup>19+</sup>

窗口矩形区域坐标系类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 值 | 说明                   |
| ------ | ---- | --------------------- |
| RELATIVE_TO_SCREEN | 0 | 窗口矩形区域相对于屏幕坐标系。 |
| RELATIVE_TO_PARENT_WINDOW | 1 | 窗口矩形区域相对于父窗口坐标系。 |

## GlobalWindowMode<sup>20+</sup>

窗口模式。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 值 | 说明                    |
| ------ | --- | ------------------------ |
| FULLSCREEN | 1 | 全屏窗口，二进制从右往左，第一个二进制位为1。  |
| SPLIT  | 1 << 1 | 分屏窗口，二进制从右往左，第二个二进制位为1。 |
| FLOAT   | 1 << 2  | 自由悬浮窗口，二进制从右往左，第三个二进制位为1。 |
| PIP   | 1 << 3  | 画中画，二进制从右往左，第四个二进制位为1。 |

## OcclusionState<sup>22+</sup>

窗口可见性状态枚举。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 值 | 说明                   |
| ------ | ---- | --------------------- |
| NO_OCCLUSION | 0 | 窗口完全可见（没有任何部分被其他非透明窗口遮挡）。|
| PARTIAL_OCCLUSION | 1 | 窗口部分可见（部分被其他非透明窗口遮挡）。|
| FULL_OCCLUSION | 2 | 窗口完全不可见（完全被其他非透明窗口遮挡，或窗口最小化，或窗口隐藏）。|

## WindowStageEventType<sup>9+</sup>

WindowStage生命周期状态枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称       | 值 | 说明       |
| ---------- | ------ | ---------- |
| SHOWN      | 1      | 前台状态，例如点击应用图标启动，无论是首次启动还是从后台启动均会触发。 |
| ACTIVE     | 2      | 获焦状态，例如应用窗口处理点击事件后的状态、应用启动后的状态。 |
| INACTIVE   | 3      | 失焦状态，例如打开新应用或点击其他窗口后，原获焦窗口的状态。 |
| HIDDEN     | 4      | 后台状态，例如应用上滑退出、应用窗口关闭。 |
| RESUMED<sup>11+</sup> | 5      | 前台可交互状态，例如打开应用后，应用处于前台，且可以与用户交互的状态。 |
| PAUSED<sup>11+</sup>  | 6      | 前台不可交互状态，例如应用在前台时，进入多任务界面，应用依然处于前台但不可以与用户交互的状态。 |

## WindowStageLifecycleEventType<sup>20+</sup>

WindowStage生命周期的状态类型枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 值 | 说明       |
| ---------- | ------ | ---------- |
| SHOWN      | 1      | 切到前台，例如点击应用图标启动，无论是首次启动还是从后台启动均会触发。 |
| RESUMED    | 2      | 前台可交互状态，例如打开应用后，应用处于前台，且可以与用户交互的状态。 |
| PAUSED     | 3      | 前台不可交互状态，例如应用在前台时，进入多任务界面，应用依然处于前台但不可以与用户交互的状态。 |
| HIDDEN     | 4      | 切到后台，例如应用上滑退出、应用窗口关闭。 |

## ModalityType<sup>14+</sup>

子窗口模态类型枚举。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

| 名称                 | 值      | 说明       |
| -------------------- | ------ | ---------- |
| WINDOW_MODALITY      | 0      | 当仅需要其父级窗口不响应用户操作时，可选此参数。 |
| APPLICATION_MODALITY | 1      |  除其父级窗口外还需要该应用其他实例的窗口不响应用户操作时，可选此参数。<br> **设备行为差异：** 该枚举在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。 |

## ScreenshotEventType<sup>20+</sup>

截屏事件类型枚举。

**系统能力：**  SystemCapability.WindowManager.WindowManager.Core

| 名称   | 值 | 说明                   |
| ------ | ---- | --------------------- |
| SYSTEM_SCREENSHOT | 0 | 系统截屏成功。 |
| SYSTEM_SCREENSHOT_ABORT | 1 | 系统截屏中止。 |
| SCROLL_SHOT_START | 2 | 滚动截屏开始。 |
| SCROLL_SHOT_END | 3 | 滚动截屏结束。 |
| SCROLL_SHOT_ABORT | 4 | 滚动截屏中止。 |

## OrientationExecutionResult

窗口显示方向的执行结果枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   |  值 | 说明                   |
| ------ | ---- | --------------------- |
| ORIENTATION_APPLIED | 0 | 设置的方向已生效。 |
| ORIENTATION_IGNORED | 1 | 设置的方向不生效。 |
| ORIENTATION_PENDING | 2 | 设置的方向被挂起，等系统动画结束后，将生效。 |

## RotationInfoType<sup>23+</sup>

旋转信息类型枚举。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 值     | 说明       |
| ---------- | ------ | ---------- |
| WINDOW_ORIENTATION  | 0      | 窗口所在屏幕的显示方向，以窗口模块对横竖屏的定义方式表示。<br>开发者在使用时，需要注意该方向表示[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19)中的orientation参数。 |
| DISPLAY_ORIENTATION | 1      | 屏幕显示方向，以屏幕模块对横竖屏的定义方式表示。<br>开发者在使用时，需要注意该方向表示[display](js-apis-display.md#display)对象的orientation属性。 |
| DISPLAY_ROTATION    | 2      | 设备的屏幕顺时针旋转角度。<br>开发者在使用时，需要注意该方向表示[display](js-apis-display.md#display)对象的rotation属性。 |
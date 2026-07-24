# @ohos.window (窗口)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

窗口提供管理窗口的一些基础能力，包括对当前窗口的创建、销毁、各属性设置，以及对各窗口间的管理调度。

该模块提供以下窗口相关的常用功能：

- [Window](arkts-apis-window-Window.md)：当前窗口实例，窗口管理器管理的基本单元。
- [WindowStage](#windowstage9)：窗口管理器。管理各个基本窗口单元。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.window (窗口)](arkts-apis-window.md)。
>
> - 针对系统能力SystemCapability.Window.SessionManager，请先使用[canIUse()](../common/js-apis-syscap.md#caniuse)接口判断当前设备是否支持此syscap及对应接口。

## 导入模块

```ts
import { window } from '@kit.ArkUI';
```

## WindowType<sup>7+</sup>


窗口类型枚举。


| 名称                                  | 值 | 说明                                                                                     |
|-------------------------------------| ------ |----------------------------------------------------------------------------------------|
| TYPE_INPUT_METHOD<sup>(deprecated)</sup>      | 2      | 表示输入法窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**说明：** 从API version 9开始支持，从API version 13开始废弃，无替代窗口类型，输入法相关控制都请调用[输入法框架侧接口](../../inputmethod/inputmethod-application-guide.md)执行。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_STATUS_BAR<sup>9+</sup>        | 3      | 表示状态栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_PANEL<sup>9+</sup>             | 4      | 表示通知栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_KEYGUARD<sup>9+</sup>          | 5      | 表示锁屏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_VOLUME_OVERLAY<sup>9+</sup>    | 6      | 表示音量条。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_NAVIGATION_BAR<sup>9+</sup>    | 7      | 表示导航栏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_WALLPAPER<sup>9+</sup>         | 9      | 表示壁纸。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_DESKTOP<sup>9+</sup>           | 10      | 表示桌面。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_LAUNCHER_RECENT<sup>9+</sup>   | 11      | 表示多任务中心。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_LAUNCHER_DOCK<sup>9+</sup>     | 12      | 表示桌面Dock栏。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_VOICE_INTERACTION<sup>9+</sup> | 13      | 表示智慧语音。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_POINTER<sup>9+</sup>           | 14      | 表示鼠标。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_FLOAT_CAMERA<sup>9+</sup>      | 15      | 表示相机类型悬浮窗。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_SCREENSHOT<sup>9+</sup>        | 17      | 表示截屏窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_SYSTEM_TOAST<sup>11+</sup>     | 18      | 表示顶层提示窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_DIVIDER<sup>11+</sup>          | 19      | 表示分屏条。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_GLOBAL_SEARCH<sup>11+</sup>    | 20      | 表示全局搜索窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core |
| TYPE_HANDWRITE<sup>12+</sup>        | 21      | 表示手写笔窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_WALLET_SWIPE_CARD<sup>15+</sup>| 22      | 表示钱包刷卡窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_SCREEN_CONTROL<sup>15+</sup>   | 23      | 表示锁定触控的顶层窗口，用于拦截屏幕触摸和点击事件。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_FLOAT_NAVIGATION<sup>17+</sup> | 24      | 表示悬浮的三键导航窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |
| TYPE_DYNAMIC<sup>20+</sup> | 25      | 表示可设置窗口层级的系统窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager<br>**设备行为差异**：该接口仅在Phone、PC/2in1、Tablet设备中可正常调用，在其他设备中不生效也不报错。 |
| TYPE_MUTISCREEN_COLLABORATION<sup>20+</sup> | 26      | 表示多屏协同窗口。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |

## Configuration<sup>9+</sup>

创建子窗口或系统窗口时的参数。

**系统接口：** 此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明                       |
| ---------- | --------- | ---- | ---- |-------------- |
| zIndex<sup>20+</sup>       | number | 否 | 是 | 当前系统窗口的层级，仅在[WindowType](#windowtype7)为TYPE_DYNAMIC时生效。<br>**系统能力：** SystemCapability.Window.SessionManager|
| defaultDensityEnabled<sup>20+</sup> | boolean| 否 | 是 |是否使用系统默认Density，使用系统默认Density之后，窗口不会跟随系统显示大小变化重新布局。<br>当创建的系统窗口设置此参数为true时，表示当前窗口使用系统默认Density，且不会受到[setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12)和[setCustomDensity()](arkts-apis-window-WindowStage.md#setcustomdensity15)设置的主窗口以及[setDefaultDensityEnabled()](#setdefaultdensityenabled20)设置的本窗口的相关影响。<br>当创建的系统窗口设置此参数为false时，表示当前窗口不使用系统默认Density，且会受到[setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12)和[setCustomDensity()](arkts-apis-window-WindowStage.md#setcustomdensity15)设置的主窗口以及[setDefaultDensityEnabled()](#setdefaultdensityenabled20)设置的本窗口的相关影响。<br>默认为false。<br>**系统能力：** SystemCapability.Window.SessionManager|

## WindowMode<sup>7+</sup>

窗口模式枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| UNDEFINED  | 1    | 表示APP未定义窗口模式。       |
| FULLSCREEN | 2    | 表示APP全屏模式。             |
| PRIMARY    | 3    | 表示APP分屏多窗口主要模式。上下分屏时，上分屏为主要模式。左右分屏时，左分屏为主要模式。  |
| SECONDARY  | 4    | 表示APP分屏多窗口次要模式。上下分屏时，下分屏为次要模式。左右分屏时，右分屏为次要模式。  |
| FLOATING   | 5    | 表示APP自由悬浮形式窗口模式。 |

## BlurStyle<sup>9+</sup>

窗口模糊类型枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称    | 值   | 说明                 |
| ------- | ---- | -------------------- |
| OFF     | 0    | 表示关闭模糊。       |
| THIN    | 1    | 表示较薄的模糊类型。 |
| REGULAR | 2    | 表示适中的模糊类型。 |
| THICK   | 3    | 表示较厚的模糊类型。 |

## AnimationType<sup>20+</sup>

窗口动画类型枚举。

**系统接口：** 此接口为系统接口。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称    | 值   | 说明                       |
| ------- | ---- | -------------------------- |
| FADE_IN | 1    | 表示窗口动画类型为淡入。淡入动画在窗口显示过程中生效。 |

## SystemBarRegionTint<sup>8+</sup>

单个导航栏或状态栏回调信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称            | 类型                  | 只读 | 可选 | 说明                                                         |
| --------------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type            | [WindowType](#windowtype7) | 否   | 否   | 当前属性改变的系统栏类型，仅支持类型为导航栏、状态栏的系统栏。 |
| isEnable        | boolean                   | 否   | 是   | 当前系统栏是否显示。true表示显示；false表示不显示。默认值为true。 |
| region          | [Rect](arkts-apis-window-i.md#rect7)             | 否   | 是   | 当前系统栏的位置及大小。默认值为{0,0,0,0}。                           |
| backgroundColor | string                    | 否   | 是   | 系统栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如'#00FF00'或'#FF00FF00'。 默认值为'0x66000000'。|
| contentColor    | string                    | 否   | 是   | 系统栏文字颜色。 默认值为'0xE5FFFFFF'。                |

## SystemBarTintState<sup>8+</sup>

当前系统栏回调信息集合。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 类型                                            | 只读 | 可选 | 说明                         |
| ---------- | --------------------------------------------------- | ---- | ---- | ---------------------------- |
| displayId  | number                                              | 否   | 否   | 当前窗口所在屏幕id，该参数应为整数。             |
| regionTint | Array<[SystemBarRegionTint](#systembarregiontint8)> | 否   | 否   | 当前已改变的所有系统栏信息。 |

## ScaleOptions<sup>9+</sup>

缩放参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 只读 | 可选 | 说明                                         |
| ------ | -------- | ---- | ---- | --------------------------------------------|
| x      | number   | 否   | 是   | X轴的缩放参数。该参数为浮点数，默认值为1.0。                   |
| y      | number   | 否   | 是   | Y轴的缩放参数。该参数为浮点数，默认值为1.0。                   |
| pivotX | number   | 否   | 是   | 缩放中心点X轴坐标。该参数为浮点数，默认值为0.5， 取值范围[0.0, 1.0]。 |
| pivotY | number   | 否   | 是   | 缩放中心点Y轴坐标。该参数为浮点数，默认值为0.5， 取值范围[0.0, 1.0]。 |

## RotateOptions<sup>9+</sup>

旋转参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 只读 | 可选 | 说明                                          |
| ------ | -------- | ---- |---- |---------------------------------------------|
| x      | number   | 否   | 是  | 绕X轴的旋转角度。该参数为浮点数，默认值为0.0。                   |
| y      | number   | 否   | 是  | 绕Y轴的旋转角度。该参数为浮点数，默认值为0.0。                   |
| z      | number   | 否   | 是  | 绕Z轴的旋转角度。该参数为浮点数，默认值为0.0。                   |
| pivotX | number   | 否   | 是  | 旋转中心点X轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。 |
| pivotY | number   | 否   | 是  | 旋转中心点Y轴坐标。该参数为浮点数，默认值为0.5， 取值范围为[0.0, 1.0]。  |

## TranslateOptions<sup>9+</sup>

平移参数。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型 | 只读 | 可选 | 说明                         |
| ---- | -------- | ---- | ---- | ---------------------------- |
| x    | number   | 否   | 是  | X轴的平移参数。该参数为浮点数，默认值为0.0，单位为px。 |
| y    | number   | 否   | 是  | Y轴的平移参数。该参数为浮点数，默认值为0.0，单位为px。 |
| z    | number   | 否   | 是  | Z轴的平移参数。该参数为浮点数，默认值为0.0，单位为px。 |


## StartAnimationSystemParams<sup>20+</sup>

启动动画配置，仅对全屏应用生效。

不同应用间跳转场景不生效，仍保持系统默认动效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、非[自由多窗模式](../../windowmanager/window-terminology.md#free-multi-window-mode自由多窗模式)的Tablet设备中可正常调用，在其他设备中不生效也不报错。

| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type             | [AnimationType](#animationtype20)                 | 否   | 否   | 窗口动画类型。|
| animationConfig  | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20) | 否   | 是   | 窗口动画参数配置。默认动画曲线为WindowAnimationCurve.LINEAR，duration为0。          |

## WindowCreateParams<sup>20+</sup>

应用启动时的窗口参数配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager
| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| systemAnimationParams             | [StartAnimationSystemParams](#startanimationsystemparams20)                 | 否   | 是   | 启动动画参数配置。默认值为undefined，若不配置将保持系统默认动效。|
| isWindowLimitsForcible | boolean | 否 | 是 | 应用主窗窗口尺寸限制是否可突破系统默认限制。仅当被启动应用为系统应用时生效，否则不生效也不报错。<br> - true: 允许突破系统默认限制。在窗口尺寸限制计算过程中，将忽略系统默认限制，最终生效结果仍按各来源取交集计算，且优先级保持不变。 详细说明可参考[WindowLimits](arkts-apis-window-i.md#windowlimits11)。<br> - false: 不允许突破系统默认限制，窗口尺寸限制按照默认规则计算（包含系统默认限制）。<br>默认值为false。<br>**起始版本：** 26.0.0 <br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## WindowAnchorInfo<sup>24+</sup>

一级子窗与主窗保持相对位置的窗口锚点参数信息。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| anchorType             | [WindowAnchor](arkts-apis-window-e.md#windowanchor20)                 | 否   | 否   | 一级子窗与主窗保持相对位置不变时的窗口锚点枚举。|
| offsetX             |     number           | 否   | 是   | 一级子窗锚点与主窗锚点位置的X轴偏移量，单位为px。仅支持整数输入，浮点数向下取整，默认值为0。|
| offsetY             |     number           | 否   | 是   | 一级子窗锚点与主窗锚点位置的Y轴偏移量，单位为px。仅支持整数输入，浮点数向下取整，默认值为0。|

## SubWindowAttachOptions<sup>24+</sup>

子窗与主窗保持相对位置不变时的参数。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| currentLayoutMode             | string               | 否   | 是   | 子窗当前布局模式，用于控制应用定制的UI效果。若不传，则默认为空字符串。|
| parentWindowSizeChangeCallback             |     Callback&lt;[Size](arkts-apis-window-i.md#size7)&gt;           | 否   | 是   | 父窗大小变化的回调。绑定后立即回调一次，后续父窗大小变化时通知。默认不传，无法收到父窗大小变化通知。|
| parentWindowStatusChangeCallback             |     Callback&lt;[WindowStatusType](arkts-apis-window-e.md#windowstatustype11)&gt;           | 否   | 是   | 父窗模式变化的回调。绑定后立即回调一次，后续父窗模式变化时通知。默认不传，无法收到父窗模式变化通知。|
| isIntersectedWidthLimit | boolean | 否 | 是 | 子窗与绑定主窗的宽度是否互相限制。<br>true表示子窗与绑定主窗的宽度不能超过两个窗口宽度限制的交集；若两者宽度限制无交集，则不互相限制。当多个子窗同时设置此参数为true时，所有参与互限的窗口（包括主窗）的宽度受全部窗口宽度限制的交集约束。<br>false表示子窗与绑定主窗的宽度不会互相限制。<br>默认为false。<br>**起始版本：** 26.0.0 |
| isIntersectedHeightLimit | boolean | 否 | 是 | 子窗与绑定主窗的高度是否互相限制。<br>true表示子窗与绑定主窗的高度不能超过两个窗口高度限制的交集；若两者高度限制无交集，则不互相限制。当多个子窗同时设置此参数为true时，所有参与互限的窗口（包括主窗）的高度受全部窗口高度限制的交集约束。<br>false表示子窗与绑定主窗的高度不会互相限制。<br>默认为false。<br>**起始版本：** 26.0.0 |

## WindowLayoutMode<sup>(deprecated)</sup>

窗口布局模式枚举。

> **说明：**
>
> <!--RP4--><!--RP4End-->从API version 9开始支持，从API version 26.0.0开始废弃，无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称       | 值   | 说明                          |
| ---------- | ---- | ----------------------------- |
| WINDOW_LAYOUT_MODE_CASCADE<sup>(deprecated)</sup>  | 0    | 表示使用层叠布局模式。层叠布局下，多个自由窗口层叠放置，以Z轴次序区分。<br>**说明：** <!--RP4--><!--RP4End-->从API version 9开始支持，从API version 26.0.0开始废弃，无替代枚举。|
| WINDOW_LAYOUT_MODE_TILE<sup>(deprecated)</sup> | 1    | 表示使用平铺布局模式。平铺布局下，新打开的应用窗口出现在最右侧。<br>**说明：** <!--RP4--><!--RP4End-->从API version 9开始支持，从API version 26.0.0开始废弃，无替代枚举。|

## window.minimizeAll<sup>9+</sup>
minimizeAll(id: number, callback: AsyncCallback&lt;void&gt;): void

最小化指定ID的屏幕中的所有主窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：** <!--RP1-->该接口在Phone设备中可正常调用，在其他设备中返回801错误码。<!--RP1End-->

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | 是   | 显示设备[Display](js-apis-display.md#display)的ID号，该参数仅支持整数输入。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br/>适用版本：12+ |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

最小化指定ID的屏幕中的所有主窗口，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：** <!--RP1-->该接口在Phone设备中可正常调用，在其他设备中返回801错误码。<!--RP1End-->

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| id       | number                    | 是   | 显示设备[Display](js-apis-display.md#display)的ID号，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br/>适用版本：12+ |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

最小化指定ID的屏幕中除指定窗口之外的所有主窗口，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：** 该接口在Phone设备中可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| displayId| number                    | 是   | 屏幕ID，该参数仅支持整数输入，输入浮点数会向下取整。 |
| excludeWindowId | number              | 是   | 窗口ID。可通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到相关窗口属性，其中属性id即对应为窗口ID。窗口ID小于等于0，或窗口ID为null或者undefined时，会抛出401错误码；窗口ID大于0但是不存在会抛出1300002错误码；窗口ID大于0且窗口存在但是不在该屏幕，最小化指定屏幕上的所有主窗口。该参数仅支持整数输入，输入浮点数会向下取整。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. Possible cause: 1.Window is nullptr; 2. Failed to find specified window by id. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

多窗口快速切换时隐藏或者恢复应用窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。     |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br/>适用版本：12+ |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

多窗口快速切换时隐藏或者恢复应用窗口，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities.<br/>适用版本：12+ |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

开启状态栏、导航栏属性变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | 是   | 回调函数。返回当前的状态栏、导航栏信息集合。                 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |

**示例：**

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

关闭状态栏、导航栏属性变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 监听事件，固定为'systemBarTintChange'，即导航栏、状态栏属性变化事件。 |
| callback | Callback&lt;[SystemBarTintState](#systembartintstate8)&gt; | 否   | 回调函数。返回当前的状态栏、导航栏信息集合。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有状态栏、导航栏属性变化的监听。                |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed.              |

**示例：**

```ts
const callback = (systemBarTintState: window.SystemBarTintState) => {
  // ...
}
try {
  window.on('systemBarTintChange', callback);

  window.off('systemBarTintChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  window.off('systemBarTintChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for systemBarTint changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('gestureNavigationEnabledChange')<sup>10+</sup>

on(type: 'gestureNavigationEnabledChange', callback: Callback&lt;boolean&gt;): void

添加手势导航启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                          |
| -------- | ----------------------- | ---- | ----------------------------------------------------------------------------- |
| type     | string                  | 是   | 监听事件，固定为'gestureNavigationEnabledChange'，即手势导航启用状态变化事件。    |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。返回当前手势导航的启用状态。true表示手势导航状态变化为启用；false表示手势导航状态变化为禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

移除手势导航启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                        |
| -------- | ----------------------- | -- | ------------------------------------------------------------ |
| type     | string                  | 是 | 监听事件，固定为'gestureNavigationEnabledChange'，即手势导航启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 否 | 已注册的回调函数。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有手势导航启用状态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  window.on('gestureNavigationEnabledChange', callback);
  window.off('gestureNavigationEnabledChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  window.off('gestureNavigationEnabledChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for gesture navigation status changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.on('waterMarkFlagChange')<sup>10+</sup>

on(type: 'waterMarkFlagChange', callback: Callback&lt;boolean&gt;): void

添加水印启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                          |
| -------- | ----------------------- | ---- | ----------------------------------------------------------------------------- |
| type     | string                  | 是   | 监听事件，固定为'waterMarkFlagChange'，即水印启用状态变化事件。    |
| callback | Callback&lt;boolean&gt; | 是   | 回调函数。返回当前水印的启用状态。true表示当前已启用水印；false表示当前未启用水印。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.               |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

移除水印启用状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                        |
| -------- | ----------------------- | -- | ------------------------------------------------------------ |
| type     | string                  | 是 | 监听事件，固定为'waterMarkFlagChange'，即水印启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 否 | 已注册的回调函数。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有水印启用状态变化的监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Incorrect parameter types; 2. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |

**示例：**

```ts
const callback = (bool: boolean) => {
  // ...
}
try {
  window.on('waterMarkFlagChange', callback);
  window.off('waterMarkFlagChange', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  window.off('waterMarkFlagChange');
} catch (exception) {
  console.error(`Failed to enable or disable the listener for watermark flag changes. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

## window.setGestureNavigationEnabled<sup>10+</sup>
setGestureNavigationEnabled(enable: boolean, callback: AsyncCallback&lt;void&gt;): void

设置手势导航启用状态。使用callback异步回调。系统出于安全的考虑，不会干预手势的禁用和恢复。应用调用本接口禁用手势后异常退出的情况下，如果想要恢复手势，需自行实现自动拉起机制并再次调用本接口恢复手势。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| enable   | boolean                  | 是   | 设置手势导航启用状态。true表示启用手势导航；false表示禁用手势导航。当前仅禁用从屏幕下拉的手势，其他手势未禁用。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置手势导航启用状态。使用Promise异步回调。系统出于安全的考虑，不会干预手势的禁用和恢复。应用调用本接口禁用手势后异常退出的情况下，如果想要恢复手势，需自行实现自动拉起机制并再次调用本接口恢复手势。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型     | 必填  | 说明                 |
| ------ | ------- | ---- | -------------------- |
| enable | boolean | 是   | 设置手势导航启用状态。true表示启用手势导航；false表示禁用手势导航。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置屏幕水印图片显示状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | 水印图片。可通过[createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8)接口获取。|
| enable   | boolean                  | 是   | 设置是否显示水印图片。true显示水印图片；false表示不显示水印图片。设置显示水印后需主动设置为false才能关闭水印图片显示。|
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置屏幕水印图片显示状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                        | 必填  | 说明                 |
| ------ | --------------------------- | ---- | -------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | 水印图片。可通过[createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8)接口获取。|
| enable   | boolean                  | 是   | 设置是否显示水印图片。true显示水印图片；false表示不显示水印图片。设置显示水印后需主动设置为false才能关闭水印图片显示。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置屏幕水印图片的显示状态，并设定水印的优先级。使用Promise异步回调。当priority等于0时，当前接口与[setWaterMarkImage](#windowsetwatermarkimage10)等价。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                        | 必填  | 说明                 |
| ------ | --------------------------- | ---- | -------------------- |
| pixelMap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | 水印图片。可通过[createPixelMap](../apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8)接口获取。|
| enable   | boolean                  | 是   | 设置是否显示水印图片。true表示显示水印图片；false表示不显示水印图片。设置显示水印后需主动设置为false才能关闭水印图片显示。|
| priority   | number                  | 是   | 水印设置优先级。数值越小表示优先级越高，需大于等于0，小于0时返回1300016错误码。设置水印时，如果传入的优先级比上一次设置的低，则本次设置不会生效。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: Invalid parameter range. |

**示例：**

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

获取指定窗口相同尺寸截图，使用Promise异步回调。若当前窗口设置为隐私模式（可通过[setWindowPrivacyMode](arkts-apis-window-Window.md#setwindowprivacymode9)接口设置），截图结果为白屏。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**
| 参数名   | 类型   | 必填  | 说明         |
| -------- | ------ | ----- | ------------ |
| windowId | number | 是    | 窗口Id。可通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到相关窗口属性，其中属性id即对应为窗口ID。 |

**返回值：**
| 类型                    | 说明                            |
| ----------------------- | ------------------------------- |
| Promise<[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)> | Promise对象。返回指定窗口截图。 |

**错误码：**
以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1300002  | This window state is abnormal. Possible cause: Internal task error. |
| 1300003  | This window manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

try {
  // 此处仅示意，请使用getWindowProperties获取对应窗口ID再进行使用
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

通知屏幕截屏的事件类型，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型   | 必填  | 说明         |
| -------- | ------ | ----- | ------------ |
| eventType | [ScreenshotEventType](arkts-apis-window-e.md#screenshoteventtype20) | 是    | 截屏事件类型。 |

**返回值：**

| 类型                    | 说明                            |
| ----------------------- | ------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300003  | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

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

获取指定的前台窗口当前栈顶[Navigation](arkui-ts/ts-basic-components-navigation.md)中的[NavDestination](arkui-ts/ts-basic-components-navdestination.md)名称，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                                        |
| ------ | ---------- |----|---------------------------------------------------------------------------|
| windowId   | number| 是  | 窗口Id，用于指定要查询的窗口。该参数应为大于0的整数，小于等于0时会返回错误码1300016，如果指定的窗口不存在或生命周期不在前台，返回错误码为1300002。|

**返回值：**

| 类型                             | 说明                      |
| -------------------------------- |-------------------------|
| Promise&lt;string&gt; | Promise对象。返回获取到的[NavDestination](arkui-ts/ts-basic-components-navdestination.md)名称。<br>对于[Navigation](arkui-ts/ts-basic-components-navigation.md)嵌套以及当前页面存在多个[Navigation](arkui-ts/ts-basic-components-navigation.md)的场景，查询的是后创建的[Navigation](arkui-ts/ts-basic-components-navigation.md)的信息。<br>如果页面没有[Navigation](arkui-ts/ts-basic-components-navigation.md)或者[Navigation](arkui-ts/ts-basic-components-navigation.md)中没有[NavDestination](arkui-ts/ts-basic-components-navdestination.md)，返回空字符串。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID    | 错误信息 |
|----------| ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**
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

设置系统窗口的窗口层级。使用Promise异步回调。

将所有该类型系统窗口zIndex调整为所设置的值，调整前后，该类型窗口之间相对层级保持不变，焦点窗口不发生变化。当应用关闭之后该类型窗口层级恢复默认值。

推荐不同类型窗口设置不同的zIndex，如果已经存在相同zIndex的窗口，设置前后，窗口之间的相对层级保持不变。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异**：该接口仅在Phone、PC/2in1、Tablet设备中可正常调用，在其他设备中不生效也不报错。

**参数：**

| 参数名          | 类型   | 必填  | 说明                    |
| -------------- | ------ | ----- | ----------------------- |
| windowType | [WindowType](#windowtype7) | 是    | 窗口类型。仅支持TYPE_WALLET_SWIPE_CARD、TYPE_VOICE_INTERACTION、TYPE_SCREENSHOT、TYPE_SCREEN_CONTROL、TYPE_FLOAT_NAVIGATION和TYPE_MUTISCREEN_COLLABORATION。 |
| zIndex | number | 是    | 系统窗口的层级。该参数仅支持整数输入，浮点数输入将向下取整。0和负数会使窗口在桌面以下。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Possible cause: Invalid window type. |

**示例：**

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

创建一个子窗，并绑定父窗。使用Promise异步回调。

仅支持主窗口作为绑定的父窗。

子窗跟随父窗显示/隐藏，但并不跟随父窗销毁，子窗通过回调函数监听父窗生命周期变化。

建议在父窗销毁后主动销毁创建的子窗。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                |
| -------- | ----------------------- | -- |---------------------------------------------------|
| name | string | 是 | 窗口名称。|
| parentId | number | 是 | 指定父窗口ID。推荐使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)方法获取窗口ID属性。|
| ctx | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是 | 当前应用上下文信息。|
| parentWindowEventListener | [WindowEventListener](arkts-apis-window-t.md#windoweventlistener) | 是 | 回调函数。返回绑定父窗的生命周期变化。|

**返回值：**

| 类型 | 说明 |
| -------------------------------- | ------------------------------------ |
| Promise&lt;[Window](arkts-apis-window-Window.md)&gt; | Promise对象。返回当前创建的子窗口对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. This can not work correctly due to limited device capabilities. |
| 1300001 | Repeated operation. Possible cause: The window has been created and can not be created again. |
| 1300002 | This window state is abnormal. Possible cause: 1. Internal task error. 2. The number of windows has reached the limit. |
| 1300003 | This window manager service works abnormally. |
| 1300009 | The parent window is invalid. Possible cause: 1. The parent window does not exist or has been destroyed. 2. Invalid window type. Only main windows are supported.|

**示例：**

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

将指定的主窗口迁移到指定的屏幕上。使用Promise异步回调。

- 对于[主屏](../../displaymanager/display-terminology.md#主屏)/[扩展屏](../../displaymanager/display-terminology.md#扩展屏)与[虚拟屏](../../displaymanager/display-terminology.md#虚拟屏)之间以及虚拟屏与虚拟屏之间的窗口迁移，仅主窗及其子窗会一起被迁移到对应屏幕上且被抬升，如果存在子窗，最上层可获焦子窗会获取焦点，否则主窗口获焦。
- 对于主屏与扩展屏之间的窗口迁移，只会将主窗口迁移到对应屏幕并抬升层级。

<!--RP3--><!--RP3End-->

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名          | 类型   | 必填  | 说明                    |
| -------------- | ------ | ----- | ----------------------- |
| displayId | number | 是    | 目标屏幕的ID，用于指定要迁移到的屏幕。该参数应为非负整数，可通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到[properties](arkts-apis-window-i.md#windowproperties)后，再通过properties.displayId获取；也可通过获取[Display](js-apis-display.md#display)对象的[id](js-apis-display.md#属性)属性获取此参数。 |
| windowId | number | 是    | 目标主窗口的ID，用于指定要迁移的窗口。该参数应为大于0的整数，通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到[properties](arkts-apis-window-i.md#windowproperties)后，再通过properties.id获取。|

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                                      |
| ------- | --------------------------------------------- |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300008 | The display device is abnormal.           |

**示例：**

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

设置窗口布局模式，使用callback异步回调。

> **说明：**
>
> <!--RP4--><!--RP4End-->从API version 9开始支持，从API version 26.0.0开始废弃，无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmodedeprecated)                  | 是   | 设置的窗口布局模式。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调信息。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置窗口布局模式，使用Promise异步回调。

> **说明：**
>
> <!--RP4--><!--RP4End-->从API version 9开始支持，从API version 26.0.0开始废弃，无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| mode       | [WindowLayoutMode](#windowlayoutmodedeprecated)                  | 是   | 设置的窗口布局模式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

当前窗口实例，窗口管理器管理的基本单元。

下列API示例中都需先使用[getLastWindow()](arkts-apis-window-f.md#windowgetlastwindow9)、[createWindow()](arkts-apis-window-f.md#windowcreatewindow9)、[findWindow()](arkts-apis-window-f.md#windowfindwindow9)中的任一方法获取到Window实例（windowClass），再通过此实例调用对应方法。

### hide<sup>7+</sup>

hide (callback: AsyncCallback&lt;void&gt;): void

隐藏当前窗口，使用callback异步回调，仅支持系统窗口与应用子窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 1300002 | This window state is abnormal. |

**示例：**

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

隐藏当前窗口，使用Promise异步回调，仅支持系统窗口与应用子窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 1300002 | This window state is abnormal. |

**示例：**

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

隐藏当前窗口，过程中播放动画，使用callback异步回调。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows are supported. |

**示例：**

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

隐藏当前窗口，过程中播放动画，使用Promise异步回调。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows are supported. |

**示例：**

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

显示当前窗口，过程中播放动画，使用callback异步回调。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows are supported. |

**示例：**

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

显示当前窗口，过程中播放动画，使用Promise异步回调。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type. Only system windows are supported. |

**示例：**

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

设置主窗口模式，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------------------------- | -- | --------- |
| mode     | [WindowMode](#windowmode7) | 是 | 窗口模式。 |
| callback | AsyncCallback&lt;void&gt;  | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置主窗口模式，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------------------------- | -- | --------- |
| mode     | [WindowMode](#windowmode7) | 是 | 窗口模式。 |

**返回值：**

| 类型 | 说明 |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置一级子窗与主窗保持相对位置不变。使用Promise异步回调。

该相对位置通过子窗与主窗之间的锚点偏移量表示，子窗和主窗使用的窗口锚点相同。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用此接口时，将返回1300004错误码。

> **说明：**
>
> - 只支持一级子窗调用该接口，子窗需处于自由悬浮窗口模式（即窗口模式为window.WindowStatusType.FLOATING）。
>
> - 当子窗调用该接口后，立即使其显示位置跟随主窗并保持相对位置不变，并且可以监听主窗大小及模式切换。除非调用[detachLayoutToParentWindow()](#detachlayouttoparentwindow24)接口解绑，否则效果将持续。
>
> - 当子窗调用该接口后，再调用[moveWindowTo()](arkts-apis-window-Window.md#movewindowto9)、[maximize()](arkts-apis-window-Window.md#maximize12)、[setFollowParentWindowLayoutEnabled()](arkts-apis-window-Window.md#setfollowparentwindowlayoutenabled17)等修改窗口位置的接口，或通过鼠标/触摸操作对子窗进行拖拽移动、拖拽缩放时将不生效。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)的设备上正常调用并生效；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)的设备上调用不生效不报错，设备切换到自由窗口状态生效；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)的设备上调用不生效不报错。

**参数：**

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------------- |
| anchorInfo       | [WindowAnchorInfo](#windowanchorinfo24)                    | 否   | 一级子窗与主窗保持相对位置不变时的锚点参数。若不传，默认逻辑参考[WindowAnchorInfo](#windowanchorinfo24)。 |
| attachOptions       | [SubWindowAttachOptions](#subwindowattachoptions24)                    | 否   | 设置子窗布局的附加参数。若不传，默认逻辑参考[SubWindowAttachOptions](#subwindowattachoptions24)。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function attachLayoutToParentWindow can not work correctly due to limited device capabilities.|
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally.|
| 1300004 | Unauthorized operation. Possible cause: 1. Invalid window type. Only subwindows are supported; 2. The current window's parent window is not a main window; 3. Only level-1 subwindows are supported.|
| 1300010 | The operation in the current window status is invalid. Possible cause: 1. The subwindow is following its parent window's layout. 2. The subwindow is not in floating mode.|

**示例：**

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

解除一级子窗与主窗保持相对位置不变的协同关系。使用Promise异步回调。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用此接口时，将返回1300004错误码。

> **说明：**
>
> - 子窗调用接口时需保持子窗处于协同状态。
>
> - 调用接口解除协同后，子窗将保持协同时的位置，可对子窗进行拖拽以修改子窗大小和位置。
>
> - 解除协同后，调用[moveWindowTo()](arkts-apis-window-Window.md#movewindowto9)、[maximize()](arkts-apis-window-Window.md#maximize12)、[setFollowParentWindowLayoutEnabled()](arkts-apis-window-Window.md#setfollowparentwindowlayoutenabled17)修改窗口位置的接口，或通过鼠标/触摸操作对子窗进行拖拽移动、拖拽缩放时将生效。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)的设备上正常调用并生效；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)的设备上调用不生效不报错，设备切换到自由窗口状态生效；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)的设备上调用不生效不报错。

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 801     | Capability not supported. Function detachLayoutToParentWindow can not work correctly due to limited device capabilities.|
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally.|
| 1300004 | Unauthorized operation. Possible cause: 1. Invalid window type. Only subwindows are supported; 2. Only level-1 subwindows are supported.|
| 1300010 | The operation in the current window status is invalid. Possible cause: The subwindow is not attached to the main window.|

**示例：**

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

绑定模态窗口与目标窗口，成功绑定后，目标窗口不能响应用户操作。同时添加目标窗口销毁监听，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) | 是   | 目标窗口token值。 |
| deathCallback | Callback&lt;void&gt;        | 是   | 目标窗口销毁监听。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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
      name: "test",
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

绑定模态窗口与目标窗口，成功绑定后，目标窗口不能响应用户操作。同时添加目标窗口销毁监听，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| token       | [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) | 是   | 目标窗口token值。 |
| deathCallback | Callback&lt;void&gt;        | 是   | 目标窗口销毁监听。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

绑定模态窗口与目标窗口，成功绑定后，目标窗口不能响应用户操作。同时添加目标窗口销毁监听，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| requestInfo | [dialogRequest.RequestInfo](../apis-ability-kit/js-apis-app-ability-dialogRequest.md#requestinfo) | 是   | 目标窗口RequestInfo值。 |
| deathCallback | Callback&lt;void&gt;    | 是   | 目标窗口销毁监听。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

绑定模态窗口与目标窗口，成功绑定后，目标窗口不能响应用户操作。同时添加目标窗口销毁监听，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                      | 必填 | 说明                  |
| ----------- | ------------------------- | ---- | -------------------- |
| requestInfo | [dialogRequest.RequestInfo](../apis-ability-kit/js-apis-app-ability-dialogRequest.md#requestinfo) | 是   | 目标窗口RequestInfo值。 |
| deathCallback | Callback&lt;void&gt;    | 是   | 目标窗口销毁监听。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

唤醒屏幕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型    | 必填 | 说明                         |
| ---------------- | ------- | ---- | ---------------------------- |
| wakeUp           | boolean | 是   | 是否设置唤醒屏幕。true表示唤醒；false表示不唤醒。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

截屏、录屏或投屏是否忽略当前窗口。此接口一般用于禁止截屏、录屏或投屏的场景。

若要实现窗口始终在前台忽略截屏、录屏或投屏，在窗口从后台回到前台时，需要通过[on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10)监听窗口生命周期变化，在后台状态时设置为false，而在前台状态时设置为true。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型    | 必填 | 说明                 |
| ------------- | ------- | ---- | -------------------- |
| isSkip | boolean | 是   | 截屏、录屏或投屏是否忽略当前窗口，默认为false。<br>true表示忽略当前窗口，false表示不忽略当前窗口。</br> |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |

**示例：**

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

设置窗口不透明度。仅支持在系统窗口、全局悬浮窗和模态窗口的[自定义显示与隐藏动画](../../windowmanager/system-window-stage-sys.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                 |
| ------- | ------ | ---- |----------------------------------------------------|
| opacity | number | 是   | 不透明度。该参数为浮点数，取值范围为[0.0, 1.0]。0.0表示完全透明，1.0表示完全不透明。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.opacity(0.5);
} catch (exception) {
  console.error(`Failed to opacity. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### scale<sup>9+</sup>

scale(scaleOptions: ScaleOptions): void

设置窗口缩放参数。仅支持在系统窗口、全局悬浮窗和模态窗口的[自定义显示与隐藏动画](../../windowmanager/system-window-stage-sys.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                           | 必填 | 说明       |
| ------------ | ------------------------------ | ---- | ---------- |
| scaleOptions | [ScaleOptions](#scaleoptions9) | 是   | 缩放参数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

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

设置窗口旋转参数。仅支持在系统窗口、全局悬浮窗和模态窗口的[自定义显示与隐藏动画](../../windowmanager/system-window-stage-sys.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名        | 类型                             | 必填 | 说明       |
| ------------- | -------------------------------- | ---- | ---------- |
| rotateOptions | [RotateOptions](#rotateoptions9) | 是   | 旋转参数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

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

设置窗口平移参数。仅支持在系统窗口、全局悬浮窗和模态窗口的[自定义显示与隐藏动画](../../windowmanager/system-window-stage-sys.md#自定义系统窗口的显示与隐藏动画)中使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型                                   | 必填 | 说明                 |
| ---------------- | -------------------------------------- | ---- | -------------------- |
| translateOptions | [TranslateOptions](#translateoptions9) | 是   | 平移参数，单位为px。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

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

获取窗口属性转换控制器。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                                           | 说明             |
| ---------------------------------------------- | ---------------- |
| [TransitionController](#transitioncontroller9) | 属性转换控制器。 |

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
let controller = windowClass.getTransitionController(); // 获取属性转换控制器
```

### setBlur<sup>9+</sup>

setBlur(radius: number): void

设置窗口模糊。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                               |
| ------ | ------ | ---- |--------------------------------------------------|
| radius | number | 是   | 表示窗口模糊的半径值。该参数为浮点数，单位为px，取值范围为[0, +∞)，取值为0.0时表示关闭窗口模糊。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setBlur(4.0);
} catch (exception) {
  console.error(`Failed to set blur. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setBackdropBlur<sup>9+</sup>

setBackdropBlur(radius: number): void

设置窗口背景模糊。仅支持系统窗口、全局悬浮窗和模态窗口使用。

窗口背景是指窗口覆盖的下层区域，与窗口大小相同。

需要通过[setWindowBackgroundColor](arkts-apis-window-Window.md#setwindowbackgroundcolor9)将窗口内容背景设置成透明，否则无法看到模糊效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                    |
| ------ | ------ | ---- |-------------------------------------------------------|
| radius | number | 是   | 表示窗口背景模糊的半径值。该参数为浮点数，单位为px，取值范围为[0.0, +∞)，取值为0.0表示关闭窗口背景模糊。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

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

设置窗口背景模糊类型。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型      | 必填 | 说明                   |
| --------- | --------- | ---- | ---------------------- |
| blurStyle | [BlurStyle](#blurstyle9) | 是   | 表示窗口背景模糊类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setBackdropBlurStyle(window.BlurStyle.THIN);
} catch (exception) {
  console.error(`Failed to set backdrop blur style. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setShadow<sup>9+</sup>

setShadow(radius: number, color?: string, offsetX?: number, offsetY?: number): void

设置窗口边缘阴影。仅支持系统窗口、应用子窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                                       |
| ------- | ------ | ---- |--------------------------------------------------------------------------|
| radius  | number | 是   | 表示窗口边缘阴影的模糊半径。该参数为浮点数，单位为px，取值范围为[0.0, +∞)，取值为0.0时表示关闭窗口边缘阴影。            |
| color   | string | 否   | 表示窗口边缘阴影的颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`#00FF00`或`#FF00FF00`，默认值为'#000000'。 |
| offsetX | number | 否   | 表示窗口边缘阴影的X轴的偏移量。该参数为浮点数，单位为px，默认值为0.0。                                    |
| offsetY | number | 否   | 表示窗口边缘阴影的Y轴的偏移量。该参数为浮点数，单位为px，默认值为0.0。                                    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setShadow(4.0, '#FF00FF00', 2, 3);
} catch (exception) {
  console.error(`Failed to set shadow. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setCornerRadius<sup>9+</sup>

setCornerRadius(cornerRadius: number): void

设置窗口圆角半径。仅支持系统窗口、全局悬浮窗和模态窗口使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                 |
| ----------- | ------- | ---- |----------------------------------------------------|
| cornerRadius | number | 是   | 表示窗口圆角的半径值。该参数为浮点数，单位为px，取值范围为[0.0, +∞)，取值为0.0时表示没有窗口圆角。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 1300002 | This window state is abnormal. |
| 1300004 | Unauthorized operation.  |

**示例：**

```ts
try {
  windowClass.setCornerRadius(4.0);
} catch (exception) {
  console.error(`Failed to set corner radius. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### raiseToAppTop<sup>10+</sup>

raiseToAppTop(callback: AsyncCallback&lt;void&gt;): void

提升应用子窗口到应用顶层。使用callback异步回调。

使用该接口需要先创建子窗口，并确保该子窗口调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    // 创建子窗
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

为当前窗口添加或删除安全水印标志，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型     | 必填 | 说明                                            |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | 是   | 是否对窗口添加标志位。true表示添加，false表示删除。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal.           |

**示例：**

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

为当前窗口添加或删除安全水印标志，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                              |
| -------- | ------------------------- | ---  | ----------------------------------------------- |
| enable   | boolean                   | 是   | 是否对窗口添加标志位。true表示添加，false表示删除。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br/>适用版本：12+ |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |
| 1300008 | The display device is abnormal.           |

**示例：**

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

为当前窗口添加或移除手写标志，添加该标志后窗口只响应手写笔事件，不响应触屏事件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型     | 必填 | 说明                                            |
| ------ | ------- | --- | ------------------------------------------------ |
| enable | boolean | 是   | 是否对窗口添加标志位。true表示添加，false表示移除。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                 |
| 1300003 | This window manager service works abnormally.  |

**示例：**

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

将同一个主窗口下的子窗口抬升到目标子窗口之上。使用callback异步回调。

使用该接口需要确保要抬升的子窗口和目标子窗口都已创建完成，分别调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | 是   | 目标子窗口的id，通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到[properties](arkts-apis-window-i.md#windowproperties)后，再通过properties.id获取。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Mandatory parameters are left unspecified. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**示例：**

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
    // 创建子窗
    try {
      windowStage.createSubWindow("testSubWindow").then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        windowClass.showWindow().then(() => {
          // windowClass的获取需放在targetWindow之上
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

将同一个主窗下的子窗口提升到目标子窗口之上。使用Promise异步回调。

使用该接口需要确保要抬升的子窗口和目标子窗口都已创建完成，分别调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

非[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)支持调用。[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用该接口不生效也不报错。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | 是   | 目标子窗口的id，通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到[properties](arkts-apis-window-i.md#windowproperties)后，再通过properties.id获取。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: Mandatory parameters are left unspecified. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**示例：**

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
    // 创建子窗
    try {
      windowStage.createSubWindow("testSubWindow").then((data) => {
        if (data == null) {
          console.error("Failed to create the subWindow. Cause: The data is empty");
          return;
        }
        windowClass = data;
        windowClass.showWindow().then(() => {
          // windowClass的获取需放在targetWindow之上
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

将主窗口的层级调整至同应用下的另一个主窗口之上，子窗口的层级会跟随所属主窗口变动。使用Promise异步回调。

仅支持系统应用主窗口调用。

传入目标主窗口的id，调用窗口和目标窗口需满足：同应用进程、显示在同一物理屏、层级低于锁屏、非置顶主窗、非模态主窗且无模应用子窗。

- 应用主窗口或者它的子窗口如果是焦点窗口，此主窗口调用该接口降低层级后则自动失焦，由当前层级最高的应用窗口获焦。

- 应用主窗口调用该接口调整层级后超过当前焦点窗口，则被抬升主窗口及其子窗口中，层级最高的窗口自动获焦；应用主窗口调用该接口调整层级后未超过当前焦点窗口，则焦点不做转移。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| windowId | number                    | 是   | 目标主窗口的id，该参数为整数，通过[getWindowProperties](arkts-apis-window-Window.md#getwindowproperties9)接口获取到[properties](arkts-apis-window-i.md#windowproperties)后，再通过properties.id获取。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300016 | Parameter error. Possible cause: 1. Invalid Parameter range. 2. Invalid parameter length. |

**示例：**

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
// 新建文件src/main/ets/raisemainwindowability/RaiseMainWindowAbility.ets
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

禁止/使能子窗口点击抬升功能。使用callback异步回调。

通常来说，点击一个子窗口，会将该子窗口显示到最上方，如果设置为false，那么点击子窗口的时候，不会将该子窗口显示到最上方，而是保持不变。

使用该接口需要先创建子窗口，并确保该子窗口调用[showWindow()](arkts-apis-window-Window.md#showwindow9)并执行完毕。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | 是   | 设置子窗口点击抬升功能是否使能，true表示使能，false表示禁止。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |
| 1300009 | The parent window is invalid. |

**示例：**

```ts
// EntryAbility.ets
import { window } from '@kit.ArkUI';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...
  onWindowStageCreate(windowStage: window.WindowStage): void {
    console.info('onWindowStageCreate');
    // 创建子窗
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

禁止/使能主窗口点击抬升功能。使用Promise异步回调。

点击主窗口时，默认会抬升主窗口及其子窗口。调用此接口禁止主窗口点击抬升后（即传入false），点击主窗口时不会将其及子窗口进行抬升，保持原有状态不变；点击子窗口时，主窗口会连同子窗口一起被抬升。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | 是   | 设置主窗口点击抬升功能是否使能，true表示使能，false表示禁止。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.getMainWindow().then((window: window.Window) => {
      // 加载主窗口对应的页面
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

设置是否隐藏非系统级悬浮窗口（[windowType](arkts-apis-window-e.md#windowtype7)类型为TYPE_FLOAT），使用callback异步回调。

非系统级悬浮窗口是指非系统应用创建的悬浮窗口。默认情况下，一个系统应用主窗口可以与非系统级悬浮窗口共同显示，即该主窗口可以被上层的非系统级悬浮窗口遮挡，如果设置为true，则所有的非系统级悬浮窗口都会被隐藏，此时该主窗口就不会被上层的非系统级悬浮窗口遮挡。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在PC/2in1设备、其他设备的电脑模式中调用不生效也不报错，在其他设备和其他模式中可正常调用。

**参数：**

| 参数名      | 类型                      | 必填 | 说明       |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | 是   | 指示是否隐藏非系统级的悬浮窗口，true表示隐藏，false表示不隐藏。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 加载主窗口对应的页面
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });

    // 获取应用主窗口。
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
        // 调用带callback参数的hideNonSystemFloatingWindows接口
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

设置是否隐藏非系统级悬浮窗口（[windowType](arkts-apis-window-e.md#windowtype7)类型为TYPE_FLOAT），使用Promise异步回调。

非系统级悬浮窗口是指非系统应用创建的悬浮窗口。默认情况下，一个系统应用主窗口可以与非系统级悬浮窗口共同显示，即该主窗口可以被上层的非系统级悬浮窗口遮挡，如果设置为true，则所有的非系统级悬浮窗口都会被隐藏，此时该主窗口就不会被上层的非系统级悬浮窗口遮挡。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在PC/2in1设备、其他设备的电脑模式中调用不生效也不报错，在其他设备和其他模式中可正常调用。

**参数：**

| 参数名      | 类型                      | 必填 | 说明       |
| ----------- | ------------------------- | ---- | ---------- |
| shouldHide  | boolean                   | 是   | 指示是否隐藏非系统级的悬浮窗口，true表示隐藏，false表示不隐藏。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    // 加载主窗口对应的页面
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        console.error(`Failed to load the content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info('Succeeded in loading the content.');
    });

    // 获取应用主窗口。
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
        // 调用hideNonSystemFloatingWindows接口，获取promise对象
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

设置窗口是否使用所在屏幕的系统默认Density。Stage模型下，该接口需要在[loadContent()](arkts-apis-window-Window.md#loadcontent9)或[setUIContent()](arkts-apis-window-Window.md#setuicontent9)调用生效后使用。

不调用此接口进行设置，则表示不使用系统默认Density。

当存在同时使用该接口、[setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12)和[setCustomDensity](arkts-apis-window-WindowStage.md#setcustomdensity15)时，以最后调用的设置效果为准。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名           | 类型    | 必填 | 说明                         |
| ---------------- | ------- | ---- | ---------------------------- |
| enabled | boolean | 是   | 设置是否使用系统默认Density。true表示使用系统默认Density，窗口不跟随系统显示大小变化重新布局；false表示不使用系统默认Density，窗口跟随系统显示大小变化重新布局。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: The window is not created or destroyed. |

**示例：**

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

判断当前窗口的主窗口是否是跨多块屏幕使用全屏模式显示，使用Promise异步回调，仅支持主窗口与应用子窗口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前窗口的主窗口跨多块屏幕使用全屏模式显示，返回false表示当前窗口的主窗口未跨多块屏幕使用全屏模式显示。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. |

**示例：**

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

监听本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | --------------------------| ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'mainWindowFullScreenAcrossDisplaysChanged'，即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化。 |
| callback | Callback&lt;boolean&gt;   | 是   | 回调函数。即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化回调。true表示主窗口进入跨多块屏幕使用全屏模式显示状态，false表示主窗口退出跨多块屏幕使用全屏模式显示状态。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error.|
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows and subwindows are supported. |

**示例：**

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

取消监听本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- |----------------------------| ---- |--------------------------------------|
| type     | string                    | 是   | 监听事件，固定为'mainWindowFullScreenAcrossDisplaysChanged'，即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化。 |
| callback | Callback&lt;boolean&gt;    | 否   | 回调函数。即本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化回调。如果传入参数，则关闭该监听。如果未传入参数，则关闭所有本窗口的主窗口跨多块屏幕使用全屏模式显示的状态变化回调。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed; 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004  | Unauthorized operation. Possible cause: Invalid window type. Only main windows and subwindows are supported. |

**示例：**

```ts
const callback = (mainWindowFullScreenAcrossDisplaysChanged: boolean) => {
  // ...
}
try {
  // 通过on接口开启监听
  windowClass.on('mainWindowFullScreenAcrossDisplaysChanged', callback);
  // 关闭指定callback的监听
  windowClass.off('mainWindowFullScreenAcrossDisplaysChanged', callback);
  // 如果通过on开启多个callback进行监听，同时关闭所有监听：
  windowClass.off('mainWindowFullScreenAcrossDisplaysChanged');
} catch (exception) {
  console.error(`Failed to unregister callback. Cause code: ${exception.code}, message: ${exception.message}`);
}
```

### setTopmost<sup>12+</sup>

setTopmost(isTopmost: boolean): Promise&lt;void&gt;

系统应用主窗口调用，实现将窗口置于所有应用窗口之上不被遮挡，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：**

在<!--RP2-->OpenHarmony 6.1<!--RP2End-->之前，该接口在PC/2in1设备中可正常调用，在其他设备中返回801错误码。

从<!--RP2-->OpenHarmony 6.1<!--RP2End-->开始，该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| isTopmost | boolean | 是   | 是否将系统应用主窗口置顶，true表示置顶，false表示取消置顶。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation.                       |

**示例：**

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

禁止/使能单帧合成渲染节点的功能。使用Promise异步回调。

单帧合成渲染节点的功能主要用于跟手性要求较高的场景，使能该功能之后可以降低渲染节点的上屏延时。通过setSingleFrameComposerEnabled接口，如果enable设置为true，则使能单帧合成渲染节点的功能，否则禁止单帧合成渲染节点的功能。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| enable   | boolean                   | 是   | 设置单帧合成渲染节点的功能是否使能，true表示使能，false表示禁止。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |

**示例：**

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

设置标题栏上的最大化、最小化、分屏按钮是否可见。

仅支持主窗和[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)调用此接口，其他窗口调用时将返回1300004错误码。

仅对在当前场景下可见的标题栏按钮（最大化、最小化、分屏）生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上调用返回801错误码。

**参数：**

| 参数名    | 类型    | 必填 | 说明                                          |
| --------- | ------- | ---- | --------------------------------------------- |
| isMaximizeVisible | boolean | 是   | 设置最大化按钮是否可见，true为可见，false为隐藏。 |
| isMinimizeVisible | boolean | 是   | 设置最小化按钮是否可见，true为可见，false为隐藏。 |
| isSplitVisible | boolean | 是   | 设置分屏按钮是否可见，true为可见，false为隐藏。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002  | This window state is abnormal. |
| 1300004  | Unauthorized operation. |

**示例：**

```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    // 加载主窗口对应的页面
    windowStage.loadContent('pages/Index', (err) => {
      if (err?.code) {
        console.error(`Failed to load content. Cause code: ${err.code}, message: ${err.message}`);
        return;
      }
      let mainWindow: window.Window | undefined = undefined;
      // 获取应用主窗口。
      windowStage.getMainWindow().then(
        data => {
          if (!data) {
            console.error('Failed to get main window.');
            return;
          }
          mainWindow = data;
          console.info('Succeeded in obtaining the main window. Data: ' + JSON.stringify(data));
          // 调用setTitleButtonVisible接口，隐藏主窗标题栏最大化、最小化、分屏按钮。
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

### setRotationLocked<sup>22+</sup>

setRotationLocked(locked: boolean): Promise&lt;void&gt;

仅支持[系统窗口](../../windowmanager/window-type-overview.md#系统窗口)设置旋转锁定，锁定后系统窗口显示方向不变，未锁定时系统窗口显示方向受主窗口显示方向、旋转锁定按钮、sensor旋转影响。非系统窗口调用返回1300029错误码。使用Promise异步回调。

> **说明：**
>
> - 如果在锁定期间主窗口通过[setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9)设置显示方向属性，则解除旋转锁定后该窗口在前台还原最后一次的方向请求。
>
> - 如果在锁定期间系统窗口通过[setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9)设置显示方向属性，则解除旋转锁定后该窗口在前台且层级最高时还原最后一次的方向请求。低层级窗口通过setRotationLocked设置旋转锁定不会影响高层级系统窗口调用[setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9)设置显示方向。
>
> - 如果在锁定期间sensor方向发生了变化，则解除旋转锁定后还原到最后一次的sensor方向。
>
> - 如果在锁定期间应用调用[setOrientation()](./js-apis-screen-sys.md#setorientation)设置屏幕方向，忽略该次屏幕方向设置。
>
> - 解除锁定时，根据主窗口的显示方向属性[setPreferredOrientation()](./arkts-apis-window-Window.md#setpreferredorientation9)、sensor方向等决定应用显示方向，具体见[窗口旋转简介](../../windowmanager/window-rotation.md#窗口旋转简介)。
>
> - 不影响应用[module.json5配置文件中的abilities标签](../../quick-start/module-configuration-file.md#abilities标签)orientation属性设置的启动方向。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和2in1设备中可正常调用，在其他设备中返回801错误码。

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| locked | boolean | 是   | 设置是否锁定旋转，true表示锁定旋转，false表示解除锁定。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Function setRotationLocked can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300029 | This window type is invalid. |

**示例：**

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

仅支持[系统窗口](../../windowmanager/window-type-overview.md#系统窗口)获取当前旋转锁定状态。非系统窗口调用返回1300029错误码。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、Tablet设备和2in1设备中可正常调用，在其他设备中返回801错误码。

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| boolean | 当前系统窗是否设置旋转锁定。true表示当前系统窗已锁定旋转；false表示当前系统窗未锁定旋转。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 801     | Capability not supported. Function setRotationLocked can not work correctly due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |
| 1300029 | This window type is invalid. |

**示例：**

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

支持当前窗口主动请求获焦/失焦，使用Promise异步回调。调用成功即返回，该接口返回值不代表最终获焦/失焦生效结果。可使用[on('windowEvent')](arkts-apis-window-Window.md#onwindowevent10)监听窗口获焦/失焦状态。

获焦请求发送后，窗口获焦结果受到窗口可获焦属性及窗口可见状态的限制。获焦成功的窗口需满足以下约束：1.窗口支持获焦；2.窗口可见（窗口已显示，未销毁且未退至后台）。

失焦请求发送后，窗口无条件失焦。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| isFocused | boolean | 是   | 是否获取焦点，true表示请求获焦，false表示请求失焦。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed, non-system application uses system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal.                |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置窗口类型，使用callback异步回调。

**系统接口：** 此接口为系统接口。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| type     | [WindowType](#windowtype7) | 是   | 窗口类型。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。 |

**示例：**

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

设置窗口类型，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明       |
| ------ | ------------------------- | ---- | ---------- |
| type   | [WindowType](#windowtype7) | 是   | 窗口类型。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

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

设置主窗口在分屏模式下是否被禁止移动，使用callback异步回调。

> **说明：**
>
> <!--RP4--><!--RP4End-->从API version 9开始支持，从API version 26.0.0开始废弃，无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型                      | 必填 | 说明                 |
| ----------- | ------------------------- | ---- | -------------------- |
| isForbidSplitMove | boolean                   | 是   | 窗口在分屏模式下是否被禁止移动。true表示禁止；false表示不禁止。 |
| callback    | AsyncCallback&lt;void&gt; | 是   | 回调函数。           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

设置主窗口在分屏模式下是否被禁止移动，使用Promise异步回调。

> **说明：**
>
> <!--RP4--><!--RP4End-->从API version 9开始支持，从API version 26.0.0开始废弃，无替代接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                 |
| ----------- | ------- | ---- | -------------------- |
| isForbidSplitMove | boolean | 是   | 窗口在分屏模式下是否被禁止移动。true表示禁止；false表示不禁止。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal.               |
| 1300003 | This window manager service works abnormally. |

**示例：**

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

开始移动窗口，使用Promise异步回调。

仅在[onTouch](arkui-ts/ts-universal-events-touch.md#ontouch)事件（其中，事件类型必须为TouchType.Down）的回调方法中调用此接口才会有移动效果，成功调用此接口后，窗口将跟随鼠标或触摸点移动。

在点击拖拽场景下，若不期望在按下时触发拖拽事件，则可以在事件类型为[TouchType.Move](./arkui-ts/ts-appendix-enums.md#touchtype)（需要保证当前行为已经触发TouchType.Down事件）时调用此接口，触发移动效果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上，对系统窗口、应用主窗口、应用子窗口、全局悬浮窗和模态窗口生效；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备及不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上，仅对系统窗口、应用子窗口、全局悬浮窗和模态窗口生效，应用主窗口调用该接口返回801或1300004错误码。

**参数：**

| 参数名 | 类型  | 必填 | 说明 |
| ----- | ---------------------------- | -- | --------------------------------- |
| startMovingOptions  | [StartMovingOptions](#startmovingoptions) | 否 | 窗口拖拽移动的配置项。 |

**返回值：**

| 类型                 | 说明                   |
| ------------------- | ---------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300001 | Repeated operation. |
| 1300002 | This window state is abnormal. Possible cause: 1. The window is not created or destroyed. 2. Internal task error. |
| 1300003 | This window manager service works abnormally. |
| 1300004 | Unauthorized operation. Possible cause: Invalid window type, main windows are not supported in non-free window mode. |
| 1300016 | Parameter error. Possible cause: Invalid parameter range. |

**示例：**

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

子窗口创建参数。

| 名称      | 类型  | 只读 | 可选 | 说明         |
| ---------- | ---- | ---- | ---- | ----------- |
| isTopmost<sup>12+</sup>  | boolean | 否 | 是 | 子窗口是否启用置顶属性。true表示子窗口置顶，false表示子窗口不置顶。不设置，则默认为false。需要配合isModal使用，当isModal设置为true时设置子窗isTopmost才生效；当isModal设置为false时设置子窗isTopmost为true返回401错误码。 <br>**系统接口：** 此接口为系统接口。<br>**系统能力：** SystemCapability.Window.SessionManager |

## WindowStage<sup>9+</sup>

窗口管理器。管理各个基本窗口单元，即[Window](arkts-apis-window-Window.md)实例。

下列API示例中都需在[onWindowStageCreate()](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate)函数中使用WindowStage的实例调用对应方法。

### disableWindowDecor<sup>9+</sup>

disableWindowDecor(): void

禁止窗口装饰。

禁止窗口装饰后，当主窗口进入全屏沉浸状态时，此时鼠标Hover到上方窗口标题栏热区上会显示悬浮标题栏。若想禁用悬浮标题栏显示，请使用[setTitleAndDockHoverShown()](arkts-apis-window-Window.md#settitleanddockhovershown14)接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**错误码：**

以下错误码的详细介绍请参见[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. <br>适用版本：12+ |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**示例：**

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

设置应用显示在锁屏之上。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名           | 类型    | 必填 | 说明                         |
| ---------------- | ------- | ---- | ---------------------------- |
| showOnLockScreen | boolean | 是   | 是否设置应用显示在锁屏之上。true表示显示在锁屏之上；false表示不显示在锁屏之上。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 1300002 | This window state is abnormal. |
| 1300005 | This window stage is abnormal. |

**示例：**

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

设置应用在多任务中显示的图片，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| imgResourceId | number | 是   | 应用自定义图片的资源id，图片资源需放在resources/base/media目录下，通过`$r`资源访问方式获取对应图片的资源id，这里以获取startIcon图片的资源id为例给出示意：`$r("app.media.startIcon").id`。|
| value | [ImageFit](arkui-ts/ts-appendix-enums.md#imagefit) | 是 | 应用自定义图片的填充方式。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[窗口错误码](errorcode-window.md)。

| 错误码ID | 错误信息 |
| ------- | ------------------------------ |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1300002 | This window state is abnormal. |
| 1300003 | This window manager service works abnormally. |
| 1300016 | Parameter error. Possible cause: 1. Invalid parameter range. 2. Invalid parameter length. 3. Incorrect parameter format. |

**示例：**

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

属性转换的上下文信息。

**系统接口：** 此接口为系统接口。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

| 名称                  | 类型          | 只读 | 可选 | 说明             |
| --------------------- | ----------------- | ---- | ---- | ---------------- |
| toWindow | [Window](arkts-apis-window-Window.md) | 否   | 否   | 动画的目标窗口。 |

### completeTransition<sup>9+</sup>

completeTransition(isCompleted: boolean): void

设置属性转换的最终完成状态。该函数需要在动画函数[animateTo()](arkui-ts/ts-explicit-animation.md)执行后设置。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                                         |
| ----------- | ------- | ---- | ------------------------------------------------------------ |
| isCompleted | boolean | 是   | 窗口属性转换是否完成。true表示完成本次转换；false表示撤销本次转换。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**示例：**

```ts
(context: window.TransitionContext) => {
  let toWindow: window.Window = context.toWindow;
  this.getUIContext()?.animateTo({
    duration: 1000, // 动画时长
    tempo: 0.5, // 播放速率
    curve: Curve.EaseInOut, // 动画曲线
    delay: 0, // 动画延迟
    iterations: 1, // 播放次数
    playMode: PlayMode.Normal, // 动画模式
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

属性转换控制器。使用其子接口之前得先创建系统窗口，参照示例代码。

**系统接口：** 此接口为系统接口。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowClass: window.Window | undefined = undefined;
let config: window.Configuration = {
  name: "systemTypeWindow",
  windowType: window.WindowType.TYPE_PANEL, // 根据需要自选系统窗口类型
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

窗口显示时的自定义动画配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                 |
| ------- | ---------------------------------------- | ---- | -------------------- |
| context | [TransitionContext](#transitioncontext9) | 是   | 属性转换时的上下文。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**示例：**

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
let systemTypeWindow = window.findWindow("systemTypeWindow"); // 此处需要获取一个系统类型窗口。
try {
  animationConfig?.ShowWindowWithCustomAnimation(systemTypeWindow, (context : window.TransitionContext)=>{
    console.info('complete transition end');
    let toWindow = context.toWindow;
    this.getUIContext()?.animateTo({
      duration: 1000, // 动画时长
      tempo: 0.5, // 播放速率
      curve: Curve.EaseInOut, // 动画曲线
      delay: 0, // 动画延迟
      iterations: 1, // 播放次数
      playMode: PlayMode.Normal, // 动画模式
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
      toWindow?.translate(obj); // 设置动画过程中的属性转换
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

窗口隐藏时的自定义动画配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                 |
| ------- | ---------------------------------------- | ---- | -------------------- |
| context | [TransitionContext](#transitioncontext9) | 是   | 属性转换时的上下文。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API.<br>适用版本：12+ |
| 401     | Parameter error. Possible cause: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.               |

**示例：**

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
let systemTypeWindow = window.findWindow("systemTypeWindow"); // 此处需要获取一个系统类型窗口。
try {
  animationConfig?.HideWindowWithCustomAnimation(systemTypeWindow, (context : window.TransitionContext)=>{
    console.info('complete transition end');
    let toWindow = context.toWindow;
    this.getUIContext()?.animateTo({
      duration: 1000, // 动画时长
      tempo: 0.5, // 播放速率
      curve: Curve.EaseInOut, // 动画曲线
      delay: 0, // 动画延迟
      iterations: 1, // 播放次数
      playMode: PlayMode.Normal, // 动画模式
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
      toWindow?.translate(obj); // 设置动画过程中的属性转换
      console.info('toWindow translate end in animation');
    });
    console.info('complete transition end');
  });
} catch (error) {
  console.error(`HideWindowWithCustomAnimation error code: ${error.code}, message: ${error.message}` );
}
```

## ExtensionWindowAttribute<sup>14+</sup>

扩展窗口的属性枚举。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称      | 值 | 说明         |
| ---------- | ----- | ----------- |
| SYSTEM_WINDOW  | 0 | 系统窗口。|
| SUB_WINDOW  | 1 | 子窗口。|

## SystemWindowOptions<sup>14+</sup>

系统窗口的创建参数。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型                      | 只读  |可选 | 说明       |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowType   | [WindowType](#windowtype7) | 否   | 否   | 窗口类型。无默认类型，不配置会导致窗口创建失败。不支持TYPE_DIALOG类型。 |

## ExtensionWindowConfig<sup>14+</sup>

创建扩展窗口时需要配置的参数。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称 | 类型                      | 只读  |可选 | 说明       |
| ------ | ------------------------- | ---- | ---- |---------- |
| windowName   | string | 否 | 否  | 窗口名。 |
| windowAttribute   | [ExtensionWindowAttribute](#extensionwindowattribute14) | 否 | 否   | 窗口的属性。用于配置创建的窗口是子窗口还是系统窗口。当windowAttribute配置为SUB_WINDOW时须配置subWindowOptions，当windowAttribute配置为SYSTEM_WINDOW时须配置systemWindowOptions，否则创建窗口失败。|
| windowRect   | [Rect](arkts-apis-window-i.md#rect7) | 否 | 否   | 窗口矩形区域。 |
| subWindowOptions   | [SubWindowOptions](arkts-apis-window-i.md#subwindowoptions11) | 否 | 是 | 创建子窗口的参数。无默认参数，当windowAttribute配置为SUB_WINDOW时必选，否则会导致窗口创建失败。 |
| systemWindowOptions   | [SystemWindowOptions](#systemwindowoptions14) | 否 | 是 | 创建系统窗口的参数。无默认参数，当windowAttribute配置为SYSTEM_WINDOW时必选，否则会导致窗口创建失败。 |

## StartMovingOptions

窗口拖拽移动的配置项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

| 名称     | 类型      | 只读 | 可选 | 说明               |
| -------- | -------- | ---- | ---- | ------------------ |
| needFocused | boolean  | 否   | 是   | 表示窗口是否必须处于获焦状态才能开始拖拽移动。默认值为true。<br/>- true：窗口处于获焦状态才能开始拖拽移动。<br/>- false：窗口无需处于获焦状态即可开始拖拽移动。|
| avoidRect | [Rect](arkts-apis-window-i.md#rect7) | 否 | 是 | 表示窗口拖拽移动时的避让区域，以窗口左上角为原点，并随窗口移动而同步移动。系统会根据窗口区域与避让区域共同组成的最小外接矩形区域对窗口位置进行约束。若该最小外接矩形区域无法完全容纳于对应屏幕的可用区域内，则认为避让区域无效，不执行避让修正。否则，系统按以下规则调整窗口位置：<br/>- 单屏拖拽场景下，确保避让区域完全位于当前屏幕的可用区域内；<br/>- 跨屏拖拽场景下，在跨屏前确保避让区域完全位于当前屏幕的可用区域内，且窗口仅显示在当前屏幕上；跨屏后，确保避让区域完全位于目标屏幕的可用区域内，且窗口仅显示在目标屏幕上；整个拖拽过程中，窗口只会显示在一个屏幕上，不会部分显示到其他屏幕。|

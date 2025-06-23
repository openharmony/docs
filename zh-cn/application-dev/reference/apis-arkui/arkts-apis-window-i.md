# Interfaces (其他)

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## Configuration<sup>9+</sup>

创建子窗口或系统窗口时的参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称 | 类型 | 必填 | 说明                                                                          |
| ---------- | -------------------------- | -- |-----------------------------------------------------------------------------|
| name       | string                     | 是 | 窗口名字。                                                                       |
| windowType | [WindowType](arkts-apis-window-e.md#windowtype7) | 是 | 窗口类型。                                                                       |
| ctx        | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 否 | 当前应用上下文信息。不设置，则默认为空。<br>FA模型下不需要使用该参数，即可创建子窗口，使用该参数时会报错。<br>Stage模型必须使用该参数，用于创建悬浮窗、模态窗或系统窗口。 |
| displayId  | number                     | 否 | 当前物理屏幕id。不设置，则默认为-1，该参数应为整数。                                             |
| parentId   | number                     | 否 | 父窗口id。不设置，则默认为-1，该参数应为整数。                                                           |
| decorEnabled<sup>12+</sup> | boolean | 否 | 是否显示窗口装饰，仅在windowType为TYPE_DIALOG时生效。true表示显示，false表示不显示。此参数默认值为false。<br>**系统能力：** SystemCapability.Window.SessionManager |
| title<sup>12+</sup> | string| 否 | `decorEnabled`属性设置为true时，窗口的标题内容。标题显示区域最右端不超过系统三键区域最左端，超过部分以省略号表示。不设置，则默认为空字符串。 <br>**系统能力：** SystemCapability.Window.SessionManager |
| defaultDensityEnabled<sup>20+</sup> | boolean| 否 | 是否使用系统默认Density，使用系统默认Density之后，窗口不会跟随系统显示大小变化重新布局。<br>当创建的系统窗口设置此参数为true时，表示当前窗口使用系统默认Density，且不受[setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12)和[setCustomDensity()](arkts-apis-window-WindowStage.md#setcustomdensity15)设置的主窗口的相关影响。<br>当创建的系统窗口设置此参数为false时，表示当前窗口不使用系统默认Density，且会受到[setDefaultDensityEnabled()](arkts-apis-window-WindowStage.md#setdefaultdensityenabled12)和[setCustomDensity()](arkts-apis-window-WindowStage.md#setcustomdensity15)设置的主窗口的相关影响。<br>默认为false。<br>**系统能力：** SystemCapability.Window.SessionManager |

## SystemBarProperties

状态栏<!--Del-->、三键导航栏的<!--DelEnd-->属性。在设置窗口级状态栏<!--Del-->、三键导航栏<!--DelEnd-->属性时使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称                                   | 类型 |  必填 | 说明                                                         |
| -------------------------------------- | -------- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   |  否   | 状态栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。默认值：`'#66000000'`。 <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isStatusBarLightIcon<sup>7+</sup>      | boolean  |  否   | 状态栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| statusBarContentColor<sup>8+</sup>     | string   |  否   | 状态栏文字颜色。当设置此属性后，`isStatusBarLightIcon`属性设置无效。默认值：`'#E5FFFFFF'`。 <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| navigationBarColor                     | string   |  否   | 三键导航栏背景颜色，为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`。默认值：`'#66000000'`。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  |  否   | 三键导航栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| navigationBarContentColor<sup>8+</sup> | string   |  否   | 三键导航栏文字颜色。当设置此属性后，`isNavigationBarLightIcon`属性设置无效。默认值：`'#E5FFFFFF'`。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| enableStatusBarAnimation<sup>12+</sup> | boolean   |  否   | 是否使能状态栏属性变化时动画效果。true表示变化时使能动画效果；false表示没有使能动画效果。默认值：false。 <br> **系统能力：** SystemCapability.Window.SessionManager|
| enableNavigationBarAnimation<sup>12+</sup> | boolean   |  否   | 是否使能三键导航栏属性变化时动画效果。true表示变化时使能动画效果；false表示没有使能动画效果。默认值：false。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.Window.SessionManager|

## StatusBarProperty<sup>18+</sup>

状态栏的属性。在获取状态栏属性信息时返回。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

| 名称                                   | 类型 |  必填 | 说明 |
| ------------------------------------- | -------- | ---- |------- |
| contentColor     | string   |  是   | 状态栏文字颜色，固定为ARGB格式, 如：`#E5FFFFFF`。 <br> **系统能力：** SystemCapability.Window.SessionManager。|

## SystemBarStyle<sup>12+</sup>

状态栏的属性。在设置页面级状态栏属性时使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 只读 | 可选 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| statusBarContentColor   | string   | 是   | 是   | 状态栏文字颜色。默认值：`'#E5FFFFFF'`。|

## Rect<sup>7+</sup>

窗口矩形区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称   | 类型 | 可读 | 可写 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 是   | 是   | 矩形区域的左边界，单位为px，该参数为整数。 |
| top    | number   | 是   | 是   | 矩形区域的上边界，单位为px，该参数应为整数。 |
| width  | number   | 是   | 是   | 矩形区域的宽度，单位为px，该参数应为整数。 |
| height | number   | 是   | 是   | 矩形区域的高度，单位为px，该参数应为整数。 |

## AvoidArea<sup>7+</sup>

窗口内容规避区域。如系统栏区域、刘海屏区域、手势区域、软键盘区域等与窗口内容重叠时，需要窗口内容避让的区域。在规避区无法响应用户点击事件。

除此之外还需注意规避区域的如下约束，具体为：

- 底部手势区域中非底部导航条区域支持点击、长按事件透传，不支持拖入。

- 左右侧边手势区域支持点击、长按以及上下滑动事件透传，不支持拖入。

- 底部导航条区域支持长按、点击、拖入事件响应，不支持事件向下透传。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称       | 类型      | 可读 | 可写 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| visible<sup>9+</sup>    | boolean       | 是   | 是   | 规避区域是否可见。true表示可见；false表示不可见。 |
| leftRect   | [Rect](arkts-apis-window-i.md#rect7) | 是   | 是   | 屏幕左侧的矩形区。 |
| topRect    | [Rect](arkts-apis-window-i.md#rect7) | 是   | 是   | 屏幕顶部的矩形区。 |
| rightRect  | [Rect](arkts-apis-window-i.md#rect7) | 是   | 是   | 屏幕右侧的矩形区。 |
| bottomRect | [Rect](arkts-apis-window-i.md#rect7) | 是   | 是   | 屏幕底部的矩形区。 |

## Size<sup>7+</sup>

窗口大小。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称   | 类型 | 可读 | 可写 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | 是   | 是   | 窗口宽度，单位为px，该参数应为整数。 |
| height | number   | 是   | 是   | 窗口高度，单位为px，该参数应为整数。 |

## RectChangeOptions<sup>12+</sup>

窗口矩形（窗口位置及窗口大小）变化返回的值及变化原因。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称       | 类型      | 可读 | 可写 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| rect   | [Rect](arkts-apis-window-i.md#rect7) | 是   | 是   | 窗口矩形变化后的值。 |
| reason    | [RectChangeReason](arkts-apis-window-e.md#rectchangereason12) | 是   | 是   | 窗口矩形变化的原因。 |

## AvoidAreaOptions<sup>12+</sup>

系统规避区变化后返回当前规避区域以及规避区域类型。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称       | 类型      | 可读 | 可写 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| type   | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | 是   | 是   | 系统规避区变化后返回的规避区域类型。 |
| area   | [AvoidArea](arkts-apis-window-i.md#avoidarea7)         | 是   | 是   | 系统规避区变化后返回的规避区域。 |

## WindowProperties

窗口属性。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称                                  | 类型                  | 只读 | 可选 | 说明                                                                                                     |
| ------------------------------------- | ------------------------- | ---- | ---- |--------------------------------------------------------------------------------------------------------|
| windowRect<sup>7+</sup>               | [Rect](arkts-apis-window-i.md#rect7)             | 否   | 否   | 窗口尺寸，可在页面生命周期[onPageShow](./arkui-ts/ts-custom-component-lifecycle.md#onpageshow)或应用生命周期[onForeground](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground)阶段获取。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                                                  |
| drawableRect<sup>11+</sup>            | [Rect](arkts-apis-window-i.md#rect7)             | 否   | 否   | 窗口内的可绘制区域尺寸，其中左边界上边界是相对于窗口计算。在Stage模型下，需要在调用[loadContent()](arkts-apis-window-Window.md#loadcontent9)或[setUIContent()](arkts-apis-window-Window.md#setuicontent9)加载页面内容后使用该接口。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                  |
| type<sup>7+</sup>                     | [WindowType](arkts-apis-window-e.md#windowtype7) | 否   | 否   | 窗口类型。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                  |
| isFullScreen                          | boolean                   | 否   | 否   | 是否全屏，默认为false。true表示全屏；false表示非全屏。<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                  |
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | 否   | 否   | 窗口是否为沉浸式且处于全屏模式（不在悬浮窗、分屏等场景下），默认为false。true表示沉浸式且处于全屏模式；false表示非沉浸式或非全屏模式。<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                            |
| focusable<sup>7+</sup>                | boolean                   | 是   | 否   | 窗口是否可聚焦，默认为true。true表示可聚焦；false表示不可聚焦。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                |
| touchable<sup>7+</sup>                | boolean                   | 是   | 否   | 窗口是否可触摸，默认为true。true表示可触摸；false表示不可触摸。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                 |
| brightness                            | number                    | 否   | 否   | 屏幕亮度。该参数为浮点数，可设置的亮度范围为[0.0, 1.0]，其取1.0时表示最大亮度值。如果窗口没有设置亮度值，表示亮度跟随系统，此时获取到的亮度值为-1。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                      |
| dimBehindValue<sup>(deprecated)</sup> | number                    | 否   | 否   | 靠后窗口的暗度值。该参数为浮点数，取值范围为[0.0, 1.0]，其取1.0表示最暗。<br>- **说明：** 从API version 9开始废弃。<br>- 从API version 7开始支持。当前无可替代接口。|
| isKeepScreenOn                        | boolean                   | 否   | 否   | 屏幕是否常亮，默认为false。true表示常亮；false表示不常亮。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                                                                   |
| isPrivacyMode<sup>7+</sup>            | boolean                   | 否   | 否   | 隐私模式，默认为false。true表示模式开启；false表示模式关闭。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                  |
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | 否   | 否   | 窗口是否为圆角。默认为false。true表示圆角；false表示非圆角。<br>- **说明：** 从API version 9开始废弃。<br/>- 从API version 7开始支持。当前无可替代接口。|
| isTransparent<sup>7+</sup>            | boolean                   | 否   | 否   | 窗口背景是否透明。默认为false。true表示透明；false表示不透明。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                   |
| id<sup>9+</sup>                       | number                    | 是   | 否   | 窗口ID，默认值为0，该参数应为整数。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                                                    |
| displayId<sup>12+</sup>               | number                    | 是   | 是   | 窗口所在屏幕ID，默认返回主屏幕ID,该参数应为整数。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| name<sup>18+</sup>               | string                    | 是   | 是   | 窗口名字，默认为空字符串。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |

## DecorButtonStyle<sup>14+</sup>

系统装饰栏按钮样式。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

| 名称       | 类型      | 可读 | 可写 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| colorMode   | [ConfigurationConstant.ColorMode](../apis-ability-kit/js-apis-app-ability-configurationConstant.md#colormode) | 是   | 是   | 颜色模式。深色模式下按钮颜色适配为浅色，浅色模式下按钮颜色适配为深色。未设置则默认跟随系统颜色模式。 |
| buttonBackgroundSize   | number        | 是   | 是   | 按钮高亮显示时的大小，取值范围20vp-40vp，默认值28vp。 |
| spacingBetweenButtons  | number        | 是   | 是   | 按钮间距，取值范围8vp-24vp，默认值12vp。 |
| closeButtonRightMargin | number        | 是   | 是   | 关闭按钮右侧距窗口边距，取值范围6vp-22vp，默认值20vp。 |
| buttonIconSize<sup>20+</sup> | number        | 是   | 是   | 按键icon的大小，取值范围16vp-24vp，默认值20vp。 |
| buttonBackgroundCornerRadius<sup>20+</sup> | number        | 是   | 是   | 按键背板圆角半径，取值范围4vp-8vp，默认值4vp。 |

## WindowLimits<sup>11+</sup>

窗口尺寸限制参数。可以通过[setWindowLimits](arkts-apis-window-Window.md#setwindowlimits11)设置窗口尺寸限制，并且可以通过[getWindowLimits](arkts-apis-window-Window.md#getwindowlimits11)获得当前的窗口尺寸限制。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称      | 类型   | 可读 | 可写 | 说明                                                         |
| :-------- | :----- | :--- | :--- | :----------------------------------------------------------- |
| maxWidth  | number | 是   | 是   | 窗口的最大宽度。单位为px，该参数为整数。值默认为0，表示该属性不发生变化。下限值为0，上限值为系统限定的最大宽度。  |
| maxHeight | number | 是   | 是   | 窗口的最大高度。单位为px，该参数为整数。值默认为0，表示该属性不发生变化。下限值为0，上限值为系统限定的最大高度。  |
| minWidth  | number | 是   | 是   | 窗口的最小宽度。单位为px，该参数为整数。值默认为0，表示该属性不发生变化。下限值为0，上限值为系统限定的最小宽度。  |
| minHeight | number | 是   | 是   | 窗口的最小高度。单位为px，该参数为整数。值默认为0，表示该属性不发生变化。下限值为0，上限值为系统限定的最小高度。  |

## TitleButtonRect<sup>11+</sup>

标题栏上的最小化、最大化、关闭按钮矩形区域，该区域位置坐标相对窗口右上角。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 可读 | 可写 | 说明                                       |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| right  | number | 是   | 是   | 矩形区域的右边界，单位为vp，该参数为整数。 |
| top    | number | 是   | 是   | 矩形区域的上边界，单位为vp，该参数为整数。 |
| width  | number | 是   | 是   | 矩形区域的宽度，单位为vp，该参数为整数。   |
| height | number | 是   | 是   | 矩形区域的高度，单位为vp，该参数为整数。   |

## MoveConfiguration<sup>15+</sup>

窗口移动选项。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| displayId | number | 否 | 目标屏幕ID，该参数应为整数，输入非整数时将向下取整。填入该参数时，将移动到相对于目标屏幕左上角的指定位置。此参数不填或传入目标屏幕ID不存在时，将移动到相对于当前屏幕左上角的指定位置。 |

## WindowDensityInfo<sup>15+</sup>

窗口所在显示设备和窗口自定义的显示密度信息，是与像素单位无关的缩放系数，即显示大小缩放系数。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 可读 | 可写 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| systemDensity  | number   | 是   | 否   | 窗口所在屏幕的系统显示大小缩放系数，跟随用户设置变化，该参数变化范围为0.5-4.0。 |
| defaultDensity | number   | 是   | 否   | 窗口所在屏幕的系统默认显示大小缩放系数，跟随窗口所在屏幕变化，该参数变化范围为0.5-4.0。 |
| customDensity | number   | 是   | 否   | 窗口自定义设置的显示大小缩放系数，该参数取值范围为0.5-4.0。未设置该参数时，将跟随系统显示大小缩放系数变化。 |

## WindowLayoutInfo<sup>15+</sup>

窗口布局信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| windowRect<sup>15+</sup> | [Rect](arkts-apis-window-i.md#rect7)  | 是 | 窗口尺寸，窗口在屏幕上的实际位置和大小。 |

## KeyboardInfo<sup>18+</sup>

软键盘窗口信息。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| beginRect<sup>18+</sup> | [Rect](arkts-apis-window-i.md#rect7)  | 是 | 动画开始前软键盘的位置和大小。<br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| endRect<sup>18+</sup> | [Rect](arkts-apis-window-i.md#rect7)  | 是 | 动画结束后软键盘的位置和大小。<br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| animated<sup>20+</sup> | boolean  | 否 | 当前是否有显示/隐藏动画，true表示有动画，false表示没有。<br> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| config<sup>20+</sup> | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)  | 否 | 动画配置信息。<br> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## ShowWindowOptions<sup>20+</sup>

显示子窗口或系统窗口时的参数。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

| 名称   | 类型   | 必填 | 说明                                       |
| ------ | ------ | ---- | ------------------------------------------ |
| focusOnShow | boolean  | 否 | 窗口调用[showWindow()](arkts-apis-window-Window.md#showwindow20)显示时是否自动获焦，默认为true。该参数对主窗、模态窗、dialog窗口不生效。|

## WindowAnimationConfig<sup>20+</sup>

窗口动画参数配置。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称     | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| curve    | [WindowAnimationCurve](arkts-apis-window-e.md#windowanimationcurve20)           | 是   | 动画曲线类型。                                               |
| duration | number                                                    | 否   | 动画播放的时长，单位毫秒（ms）。<br/>默认值：0，最大值：3000。<br/>根据动画曲线类型决定是否必填。 |
| param    | [WindowAnimationCurveParam](arkts-apis-window-t.md#windowanimationcurveparam20) | 否   | 动画曲线参数，根据动画曲线类型决定是否必填。                 |

## WindowInfo<sup>18+</sup>

当前窗口的详细信息。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| rect  | [Rect](arkts-apis-window-i.md#rect7)   | 是   | 否   | 窗口尺寸。 |
| bundleName  | string   | 是   | 否   | 应用Bundle的名称。          |
| abilityName | string   | 是   | 否   | Ability的名称。               |
| windowId | number | 是   | 否   | 窗口ID。   |
| windowStatusType | [WindowStatusType](arkts-apis-window-e.md#windowstatustype11) | 是   | 否   | 窗口模式枚举。   |
| isFocused | boolean | 是   | 是   | 窗口是否获焦。true表示窗口获焦；false表示窗口未获焦。   |

## TransitionAnimation<sup>20+</sup>

窗口转场动画配置。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称    | 类型                                              | 必填 | 说明                                                         |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| config  | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20) | 是   | 本次转场动画配置。                                           |
| opacity | number                                            | 否   | 不透明度，转场动画作用的窗口属性，值为0时窗口完全透明。当动画类型为WindowTransitionType.DESTROY时，代表动画终点的不透明度。取值范围0~1，在动画结束时恢复为1。 |

## StartAnimationOptions<sup>20+</sup>

启动动画配置。

仅对同应用的不同ability间跳转生效。

仅在手机设备或平板设备的非自由多窗模式下生效。

仅对全屏应用生效。

**系统能力：** SystemCapability.Window.SessionManager
| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type             | [AnimationType](arkts-apis-window-e.md#animationtype20)                 | 否   | 否   | 窗口动画类型。淡入动画在应用启动时生效，淡出动画仅在应用启动被侧滑、上滑等手势打断时生效，非打断场景依然走默认系统动效。|

## Callback<sup>15+</sup>

### (data: T)<sup>15+</sup>

(data: T): V;

通用回调函数。

开发者在使用时，可自定义data的参数类型，回调函数返回对应类型的信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | -------------------------- |
| data | T    | 是   | 回调函数调用时需要传入T类型的参数。 |

**返回值：**

| 类型 | 说明 |
| -------------------------------- | ------------------------------------ |
| V | 回调函数需要返回V类型的返回值。 |

## RotationChangeInfo<sup>19+</sup>

窗口旋转变化时的窗口信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读  | 可选 | 说明                    |
| ------ | ---- | ----- | ---- | ----------------------- |
| type | [RotationChangeType](arkts-apis-window-e.md#rotationchangetype19) | 否 | 否 | 窗口旋转事件类型。 |
| orientation | number | 否 | 否 | 窗口显示方向。<br>- 0表示竖屏。<br>- 1表示反向横屏。<br>- 2表示反向竖屏。<br>- 3表示横屏。<br>开发者在使用时，需要注意该方向与display对象的属性orientation含义不一致。 |
| displayId | number | 否 | 否 | 窗口所在屏幕Id。 |
| displayRect | [Rect](arkts-apis-window-i.md#rect7) | 否 | 否 | 窗口所在屏幕旋转后的矩形区域大小。 |

## RotationChangeResult<sup>19+</sup>

应用在窗口旋转变化时返回的信息，系统会根据此信息改变当前窗口矩形区域大小。当返回主窗口旋转变化的信息时，系统不改变主窗口的大小。
应用窗口与系统窗口大小存在限制，具体限制与相关规则可见[resize](arkts-apis-window-Window.md#resize9)。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读  | 可选 | 说明                    |
| ------ | ---- | ----- | ---- | ----------------------- |
| rectType | [RectType](arkts-apis-window-e.md#recttype19) | 否 | 否 | 窗口矩形区域坐标系类型。 |
| windowRect | [Rect](arkts-apis-window-i.md#rect7) | 否 | 否 | 相对于屏幕或父窗坐标系的窗口矩形区域信息。|

## RotationChangeCallback<sup>19+</sup>

### (info: T)<sup>19+</sup>

(info: T): U;

旋转事件通知通用回调函数。

开发者在使用时，回调函数参数类型为[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19)，返回值类型为[RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)\|void。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | -------------------------- |
| info | T    | 是   | 回调函数调用时系统传入[RotationChangeInfo](arkts-apis-window-i.md#rotationchangeinfo19)类型的参数。 |

**返回值：**

| 类型 | 说明 |
| -------------------------------- | ------------------------------------ |
| U | 回调函数需要返回[RotationChangeResult](arkts-apis-window-i.md#rotationchangeresult19)\|void类型的返回值。 |

## SubWindowOptions<sup>11+</sup>

子窗口创建参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称      | 类型  | 只读 | 可选 | 说明         |
| ---------- | ---- | ---- | ---- | ----------- |
| title<sup>11+</sup>    | string | 否 | 否 | 子窗口标题。标题显示区域最右端不超过系统三键区域最左端，超过部分以省略号表示。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| decorEnabled<sup>11+</sup> | boolean | 否 | 否 | 子窗口是否显示装饰。true表示子窗口显示装饰，false表示子窗口不显示装饰。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。       |
| isModal<sup>12+</sup>    | boolean | 否 | 是 | 子窗口是否启用模态属性。true表示子窗口启用模态属性，false表示子窗口禁用模态属性。不设置，则默认为false。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| modalityType<sup>14+</sup>    | [ModalityType](arkts-apis-window-e.md#modalitytype14) | 否 | 是 | 子窗口模态类型，仅当子窗口启用模态属性时生效。WINDOW_MODALITY表示子窗口模态类型为模窗口子窗，APPLICATION_MODALITY表示子窗口模态类型为模应用子窗。不设置，则默认为WINDOW_MODALITY。<br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。       |
| windowRect<sup>18+</sup>    | [Rect](arkts-apis-window-i.md#rect7) | 否 | 是 | 子窗口矩形区域，其中子窗存在大小限制，具体参考[resize()](arkts-apis-window-Window.md#resize9)方法。不设置，此窗口在显示时默认为全屏大小。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|
| zLevel<sup>18+</sup>    | number | 否 | 是 | 子窗口层级级别，仅当子窗口未启用模态属性，即未设置isModal时生效。该参数是整数，取值范围为[-10000, 10000]，浮点数输入将向下取整。不设置，则默认为0。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|
| maximizeSupported<sup>19+</sup>    | boolean | 否 | 是 | 子窗口是否支持最大化特性。<!--RP6-->此接口仅可在2in1设备下使用。<!--RP6End-->true表示子窗口支持最大化，false表示子窗口不支持最大化。不设置，则默认为false。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。|
| outlineEnabled<sup>20+</sup>    | boolean | 否 | 是 | 子窗口是否显示描边。<!--RP6-->此接口仅可在2in1设备下使用。<!--RP6End-->true表示子窗口显示描边，false表示子窗口不显示描边。不设置，则默认为false。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

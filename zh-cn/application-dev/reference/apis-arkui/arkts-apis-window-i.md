# Interfaces (其他)
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

## Configuration<sup>9+</sup>

创建子窗口或系统窗口时的参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 只读 | 可选 | 说明                                                                          |
| ---------- | -------------------------- | -- | -- |-----------------------------------------------------------------------------|
| name       | string                     | 否 | 否 | 窗口名称。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core                                               |
| windowType | [WindowType](arkts-apis-window-e.md#windowtype7) | 否 | 否 | 窗口类型。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core                        |
| ctx        | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 否 | 是 | 当前应用上下文信息。不设置，则默认为空。<br>FA模型下不需要使用该参数，即可创建子窗口，使用该参数时会报错。<br>Stage模型必须使用该参数，用于创建全局悬浮窗、模态窗或系统窗口。 <br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| displayId  | number                     | 否 | 是 | 当前屏幕ID。不设置，则默认为父窗口屏幕ID。<br>该参数应为非负整数，且对应屏幕ID存在。<br>扩展屏、异源虚拟屏场景下，全局悬浮窗可通过设置屏幕ID显示在指定屏幕上。<br>模态窗、系统窗设置屏幕ID无效，默认为父窗口屏幕ID。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core     |
| parentId   | number                     | 否 | 是 | 父窗口ID。不设置，则默认为-1，默认父窗为当前应用上下文对应主窗。<br>FA模型下，该参数应为非负整数，且对应父窗口ID存在。<br>Stage模型下，该参数设置无效。<br>**系统能力：** SystemCapability.WindowManager.WindowManager.Core                                               |
| decorEnabled<sup>12+</sup> | boolean | 否 | 是 | 是否显示窗口标题栏，仅在windowType为TYPE_DIALOG时生效。true表示显示，false表示不显示。此参数默认值为false。<br>**系统能力：** SystemCapability.Window.SessionManager |
| title<sup>12+</sup> | string| 否 | 是 | `decorEnabled`属性设置为true时，窗口的标题内容。标题显示区域最右端不超过系统三键区域最左端，超过部分以省略号表示。不设置，则默认为空字符串。 <br>**系统能力：** SystemCapability.Window.SessionManager |

## SystemBarProperties

状态栏<!--Del-->、三键导航栏的<!--DelEnd-->属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称                                   | 类型 | 只读 | 可选 | 说明                                                         |
| -------------------------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| statusBarColor                         | string   |  否  |  是   | 状态栏背景颜色。作为入参时格式为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`；作为返回值时格式固定为ARGB颜色，如`'#FF00FF00'`，默认值为系统配置的颜色。 <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isStatusBarLightIcon<sup>7+</sup>      | boolean  |  否  |  是   | 状态栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| statusBarContentColor<sup>8+</sup>     | string   |  否  |  是   | 状态栏文字颜色。当设置此属性后，`isStatusBarLightIcon`属性设置无效。默认值：`'#E5FFFFFF'`。 <br> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| navigationBarColor                     | string   |  否  |  是   | 三键导航栏背景颜色。作为入参时格式为十六进制RGB或ARGB颜色，不区分大小写，例如`'#00FF00'`或`'#FF00FF00'`；作为返回值时格式固定为ARGB颜色，如`'#FF00FF00'`，默认值为系统配置的颜色。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isNavigationBarLightIcon<sup>7+</sup>  | boolean  |  否  |  是   | 三键导航栏图标是否为高亮状态。true表示高亮；false表示不高亮。默认值：false。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| navigationBarContentColor<sup>8+</sup> | string   |  否  |  是   | 三键导航栏文字颜色。当设置此属性后，`isNavigationBarLightIcon`属性设置无效。默认值：`'#E5FFFFFF'`。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| enableStatusBarAnimation<sup>12+</sup> | boolean  |  否  |  是   | 是否启用状态栏属性变化时的动画效果。true表示启用；false表示不启用。默认值：false。 <br> **系统能力：** SystemCapability.Window.SessionManager|
| enableNavigationBarAnimation<sup>12+</sup> | boolean   |  否  |  是   | 是否启用三键导航栏属性变化时的动画效果。true表示启用；false表示不启用。默认值：false。 <br><!--RP13--><!--RP13End--> **系统能力：** SystemCapability.Window.SessionManager|

## StatusBarProperty<sup>18+</sup>

状态栏的属性。在获取状态栏属性信息时返回。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

| 名称                                   | 类型 |  只读 |   可选  | 说明 |
| ------------------------------------- | -------- | ---- | ---- | ------- |
| contentColor     | string   |  否  |  否   | 状态栏文字颜色，固定为ARGB格式，如：`#E5FFFFFF`。 <br> **系统能力：** SystemCapability.Window.SessionManager|

## SystemBarStyle<sup>12+</sup>

状态栏的属性。在设置页面级状态栏属性时使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称   | 类型 | 只读 | 可选 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| statusBarContentColor   | string   | 否   | 是   | 状态栏文字颜色。默认值：`'#E5FFFFFF'`。|

## FrameMetrics<sup>22+</sup>

帧率指标。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读 | 可选 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| firstDrawFrame   | boolean   | 否   | 否   | 是否是首帧。true表示首帧，false表示非首帧。 |
| inputHandlingDuration    | number   | 否   | 否   | 一帧中的手势处理耗时（单位：纳秒）。 |
| layoutMeasureDuration  | number   | 否   | 否   | 一帧中的布局测量耗时（单位：纳秒）。 |
| vsyncTimestamp | number   | 否   | 否   | 当前帧的开始时间戳（单位：纳秒）。 |

## Rect<sup>7+</sup>

窗口矩形区域。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

> **说明：** 

> 与[RectInVP](#rectinvp23)相比，Rect使用像素（px）作为单位，适用于需要精确控制像素的场景；RectInVP使用虚拟像素作为单位，能够自动适配不同屏幕密度，更推荐在大多数UI场景中使用。

| 名称   | 类型 | 只读 | 可选 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 否   | 否   | 矩形区域的左边界，单位为px，该参数为整数。 |
| top    | number   | 否   | 否   | 矩形区域的上边界，单位为px，该参数应为整数。 |
| width  | number   | 否   | 否   | 矩形区域的宽度，单位为px，该参数应为整数。 |
| height | number   | 否   | 否   | 矩形区域的高度，单位为px，该参数应为整数。 |

## RectInVP<sup>23+</sup>

窗口矩形区域，单位为vp。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读 | 可选 | 说明               |
| ------ | -------- | ---- | ---- | ------------------ |
| left   | number   | 否   | 否   | 矩形区域的左边界值，单位为vp。 |
| top    | number   | 否   | 否   | 矩形区域的上边界值，单位为vp。 |
| width  | number   | 否   | 否   | 矩形区域的宽度，单位为vp。 |
| height | number   | 否   | 否   | 矩形区域的高度，单位为vp。 |

## AvoidArea<sup>7+</sup>

窗口内容的避让区域。

窗口内容做[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)适配时，需要按照[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)对应的AvoidArea做窗口内容避让。

在避让区域内，应用窗口内容被遮挡且无法响应用户点击事件。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称       | 类型      | 只读 | 可选 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| visible<sup>9+</sup>    | boolean       | 否   | 否   | 无实际意义，暂不支持使用。 |
| leftRect   | [Rect](arkts-apis-window-i.md#rect7) | 否   | 否   | 中心位于窗口的两条对角线的左侧的矩形区。 |
| topRect    | [Rect](arkts-apis-window-i.md#rect7) | 否   | 否   | 中心位于窗口的两条对角线的顶部的矩形区。 |
| rightRect  | [Rect](arkts-apis-window-i.md#rect7) | 否   | 否   | 中心位于窗口的两条对角线的右侧的矩形区。 |
| bottomRect | [Rect](arkts-apis-window-i.md#rect7) | 否   | 否   | 中心位于窗口的两条对角线的底部的矩形区。 |

> **说明：**
>
> 示意图展示了leftRect、topRect、rightRect、bottomRect的含义。
>
>  ![avoidArea](figures/avoidArea.png)

## UIEnvAvoidAreaVP<sup>23+</sup>

以vp为单位表示的窗口避让区域信息，在进行[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)适配时需关注。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 类型      | 只读 | 可选 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| visible    | boolean       | 否   | 否   | 无实际意义，暂不支持使用。 |
| leftRect   | [RectInVP](#rectinvp23) | 否   | 否   | 中心位于窗口的两条对角线的左侧的矩形区，单位为vp。 |
| topRect    | [RectInVP](#rectinvp23) | 否   | 否   | 中心位于窗口的两条对角线的顶部的矩形区，单位为vp。 |
| rightRect  | [RectInVP](#rectinvp23) | 否   | 否   | 中心位于窗口的两条对角线的右侧的矩形区，单位为vp。 |
| bottomRect | [RectInVP](#rectinvp23) | 否   | 否   | 中心位于窗口的两条对角线的底部的矩形区，单位为vp。 |

## UIEnvWindowAvoidAreaInfoPX<sup>23+</sup>

窗口不同类型避让区域信息组成的[环境变量](../../ui/arkts-env-system-property.md)数据类型，每种类型避让区域单位为px。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 类型      | 只读 | 可选 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| statusBar            | [AvoidArea](#avoidarea7) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_SYSTEM类型的避让区域，单位为px。 |
| cutout               | [AvoidArea](#avoidarea7) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_CUTOUT类型的避让区域，单位为px。 |
| keyboard             | [AvoidArea](#avoidarea7) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_KEYBOARD类型的避让区域，单位为px。 |
| navigationIndicator  | [AvoidArea](#avoidarea7) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_NAVIGATION_INDICATOR类型的避让区域，单位为px。 |

## UIEnvWindowAvoidAreaInfoVP<sup>23+</sup>

窗口不同类型避让区域信息组成的[环境变量](../../ui/arkts-env-system-property.md)数据类型，每种类型避让区域单位为vp。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 类型      | 只读 | 可选 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| statusBar            | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_SYSTEM类型的避让区域，单位为vp。 |
| cutout               | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_CUTOUT类型的避让区域，单位为vp。 |
| keyboard             | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_KEYBOARD类型的避让区域，单位为vp。 |
| navigationIndicator  | [UIEnvAvoidAreaVP](#uienvavoidareavp23) | 否   | 否   | 表示[AvoidAreaType](arkts-apis-window-e.md#avoidareatype7)为TYPE_NAVIGATION_INDICATOR类型的避让区域，单位为vp。 |

## Size<sup>7+</sup>

窗口大小，单位为px。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称   | 类型 | 只读 | 可选 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | 否   | 否   | 窗口宽度，单位为px，该参数应为整数。 |
| height | number   | 否   | 否   | 窗口高度，单位为px，该参数应为整数。 |

## SizeInVP<sup>23+</sup>

窗口大小，单位为vp。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读 | 可选 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| width  | number   | 否   | 否   | 窗口宽度，单位为vp，该参数为浮点数。 |
| height | number   | 否   | 否   | 窗口高度，单位为vp，该参数为浮点数。 |

## Position<sup>20+</sup>

窗口或组件的位置。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读 | 可选 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| x      | number   | 否   | 否   | x坐标，单位为px，该参数应为整数。 |
| y      | number   | 否   | 否   | y坐标，单位为px，该参数应为整数。 |

## RectChangeOptions<sup>12+</sup>

窗口矩形（窗口位置及窗口大小）变化返回的值及变化原因。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称       | 类型      | 只读 | 可选 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| rect   | [Rect](arkts-apis-window-i.md#rect7) | 否   | 否   | 窗口矩形变化后的值。 |
| reason    | [RectChangeReason](arkts-apis-window-e.md#rectchangereason12) | 否   | 否   | 窗口矩形变化的原因。 |

## AvoidAreaOptions<sup>12+</sup>

系统避让区变化后返回当前避让区域以及避让区域类型。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称       | 类型      | 只读 | 可选 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| type   | [AvoidAreaType](arkts-apis-window-e.md#avoidareatype7) | 否   | 否   | 系统避让区变化后返回的避让区域类型。 |
| area   | [AvoidArea](arkts-apis-window-i.md#avoidarea7)         | 否   | 否   | 系统避让区变化后返回的避让区域。 |

## WindowProperties

窗口属性。

| 名称                                  | 类型                  | 只读 | 可选 | 说明                                                                                                     |
| ------------------------------------- | ------------------------- | ---- | ---- |--------------------------------------------------------------------------------------------------------|
| windowRect<sup>7+</sup>               | [Rect](arkts-apis-window-i.md#rect7)             | 否   | 否   | 窗口尺寸，其中左边界上边界是相对于窗口所在屏幕左上顶点计算，可在页面生命周期[onPageShow](./arkui-ts/ts-custom-component-lifecycle.md#onpageshow)或应用生命周期[onForeground](../apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground)阶段获取。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| drawableRect<sup>11+</sup>            | [Rect](arkts-apis-window-i.md#rect7)             | 否   | 否   | 窗口内的可绘制区域尺寸，其中左边界上边界是相对于窗口左上顶点计算。在Stage模型下，需要在调用[loadContent()](arkts-apis-window-Window.md#loadcontent9)或[setUIContent()](arkts-apis-window-Window.md#setuicontent9)加载页面内容后获取该属性。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| type<sup>(deprecated)</sup>                     | [WindowType](arkts-apis-window-e.md#windowtype7) | 否   | 否   | 窗口类型。<br/>当前存在主窗使用[getWindowProperties()](arkts-apis-window-Window.md#getwindowproperties9)接口返回type不准确的问题，从API版本26.0.0开始废弃，可使用[windowType](#windowproperties)字段代替。<br/>**起始版本：** 7 <br/>**废弃版本：** 26.0.0 <br/>**替代接口：** [windowType](#windowproperties) <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| windowType | [WindowType](arkts-apis-window-e.md#windowtype7) | 否   | 是   | 窗口类型，默认值是[TYPE_MAIN](arkts-apis-window-e.md#windowtype7)。<br/>**起始版本：** 26.0.0 <br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br/>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isFullScreen                          | boolean                   | 否   | 否   |在满足isLayoutFullScreen为true的条件下如果隐藏了状态栏，返回值为true，其他情况下均返回false。<br> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isLayoutFullScreen<sup>7+</sup>       | boolean                   | 否   | 否   | 对于子窗，如果设置了[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)，返回值为true。<br/>对于主窗，如果设置了[沉浸式布局](../../windowmanager/immersive-window-feature.md#沉浸式布局)且处于全屏模式，返回值为true。<br/>其他情况下均返回false<br/> **原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| focusable<sup>7+</sup>                | boolean                   | 否   | 否   | 窗口是否可获焦。true表示可获焦；false表示不可获焦。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| touchable<sup>7+</sup>                | boolean                   | 否   | 否   | 窗口是否可触摸。true表示可触摸；false表示不可触摸。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 <br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| brightness                            | number                    | 否   | 否   | 窗口亮度。通过[setWindowBrightness()](arkts-apis-window-Window.md#setwindowbrightness9)设置窗口的亮度值。该参数为浮点数，可设置的亮度范围为[0.0, 1.0]或-1.0，其取值1.0时表示最大亮度，取值-1.0时，表示亮度跟随系统。如果窗口没有设置亮度值，表示亮度跟随系统，此时获取到的亮度值为-1.0。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| dimBehindValue<sup>(deprecated)</sup> | number                    | 否   | 否   | 下层窗口的暗度值。该参数为浮点数，取值范围为[0.0, 1.0]，其取1.0表示最暗。<br>**说明：** 从API version 7开始支持，从API version 9开始废弃，当前无可替代接口。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isKeepScreenOn                        | boolean                   | 否   | 否   | 屏幕是否常亮。true表示常亮；false表示不常亮。<br> **原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 <br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isPrivacyMode<sup>7+</sup>            | boolean                   | 否   | 否   | 窗口是否为隐私模式。true表示窗口为隐私模式；false表示窗口为非隐私模式。可通过[setWindowPrivacyMode()](arkts-apis-window-Window.md#setwindowprivacymode9)设置窗口的隐私模式。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isRoundCorner<sup>(deprecated)</sup>  | boolean                   | 否   | 否   | 窗口是否为圆角。true表示窗口为圆角；false表示窗口为非圆角。<br>**说明：** 从API version 7开始支持，从API version 9开始废弃，当前无可替代接口。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| isTransparent<sup>7+</sup>            | boolean                   | 否   | 否   | 窗口背景是否透明。true表示透明；false表示不透明。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| id<sup>9+</sup>                       | number                    | 否   | 否   | 窗口ID，该参数为整数。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| displayId<sup>12+</sup>               | number                    | 否   | 是   | 窗口所在屏幕ID，默认返回主屏幕ID，该参数为整数。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| name<sup>18+</sup>               | string                    | 否   | 是   | 窗口名称，默认为空字符串。<br/>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。<br/>**系统能力：** SystemCapability.WindowManager.WindowManager.Core|
| globalDisplayRect<sup>20+</sup> | [Rect](arkts-apis-window-i.md#rect7)   | 否   | 是   | 全局坐标系下的窗口尺寸。扩展屏场景下以主屏左上角为坐标原点，虚拟屏场景下以虚拟屏左上角为坐标原点。默认值：[0, 0, 0, 0]。<br/>**系统能力：**  SystemCapability.Window.SessionManager |

## DecorButtonStyle<sup>14+</sup>

系统标题栏按钮样式。

**系统能力：** SystemCapability.Window.SessionManager

| 名称       | 类型      | 只读 | 可选 | 说明               |
| ---------- | ------------- | ---- | ---- | ------------------ |
| colorMode   | [ConfigurationConstant.ColorMode](../apis-ability-kit/js-apis-app-ability-configurationConstant.md#colormode) | 否   | 是   | 颜色模式。深色模式下按钮颜色适配为浅色，浅色模式下按钮颜色适配为深色。未设置则默认跟随系统颜色模式。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| buttonBackgroundSize   | number        | 否   | 是   | 按钮高亮显示时的大小，单位为vp，取值范围为[20, 40]，默认值为28。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| spacingBetweenButtons  | number        | 否   | 是   | 按钮间距，单位为vp，取值范围为[8, 24]，默认值为12。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| closeButtonRightMargin | number        | 否   | 是   | 关闭按钮右侧距窗口边距，单位为vp，取值范围为[6, 22]，默认值为20。<br/>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| buttonIconSize<sup>20+</sup> | number        | 否   | 是   | 按钮icon的大小，单位为vp，取值范围为[16, 24]，默认值为20。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| buttonBackgroundCornerRadius<sup>20+</sup> | number        | 否   | 是   | 按钮背板圆角半径，单位为vp，取值范围为[4, 8]，默认值为4。<br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## WindowLimits<sup>11+</sup>

窗口尺寸限制参数，应用可以通过[getWindowLimits](arkts-apis-window-Window.md#getwindowlimits11)获得当前窗口的尺寸限制（单位为px）；从API version 22开始，还可以通过[getWindowLimitsVP](arkts-apis-window-Window.md#getwindowlimitsvp22)获取窗口尺寸限制（单位为vp）。

窗口尺寸限制的最终生效结果由默认系统限制、应用配置和运行时设置的数据取交集得到，优先级从高到低依次为：

1. 应用通过[setWindowLimits](arkts-apis-window-Window.md#setwindowlimits11)设置窗口尺寸限制。
2. 应用在[startAbility](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability-2)拉起窗口时通过[StartOptions](../apis-ability-kit/js-apis-app-ability-startOptions.md#startoptions)指定窗口尺寸限制（API version 17开始支持）。
3. 应用在[module.json5配置文件中的abilities标签](../../quick-start/module-configuration-file.md#abilities标签)中配置windowLimits。
4. 默认系统限制（基于不同产品和窗口类型，其windowLimits系统默认限制存在差异）。

**系统能力：** SystemCapability.Window.SessionManager

> **说明：**
>
> 针对maxWidth、maxHeight、minWidth、minHeight属性：
>
> - 默认单位为px，从API version 22开始支持通过pixelUnit设置单位为px或vp。
> - 参数为整数，浮点数会向下取整。
> - 默认值为0，表示属性不发生变化。
> - 可生效范围下限值：系统限定的最小高度/宽度。
> - 可生效范围上限值：系统限定的最大高度/宽度。

| 名称      | 类型   | 只读 | 可选 | 说明                                                          |
| :-------- | :----- | :--- | :--- | :----------------------------------------------------------- |
| maxWidth  | number | 否   | 是   | 窗口的最大宽度。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| maxHeight | number | 否   | 是   | 窗口的最大高度。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| minWidth  | number | 否   | 是   | 窗口的最小宽度。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| minHeight | number | 否   | 是   | 窗口的最小高度。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| pixelUnit<sup>22+</sup> | [PixelUnit](arkts-apis-window-e.md#pixelunit22) | 否 | 是 | 窗口尺寸限制的单位，默认为px。可显式设置为px或vp。 |

## TitleButtonRect<sup>11+</sup>

标题栏上的最小化、最大化、关闭按钮矩形区域，该区域位置坐标相对窗口右上角。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| right  | number | 否   | 否   | 矩形区域的右边界，单位为vp，该参数为整数。 |
| top    | number | 否   | 否   | 矩形区域的上边界，单位为vp，该参数为整数。 |
| width  | number | 否   | 否   | 矩形区域的宽度，单位为vp，该参数为整数。   |
| height | number | 否   | 否   | 矩形区域的高度，单位为vp，该参数为整数。   |

## MoveConfiguration<sup>15+</sup>

窗口移动选项。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| displayId | number | 否 | 是 |目标屏幕ID，该参数应为整数，输入非整数时将向下取整。默认值为undefined。填入该参数时，将移动到相对于目标屏幕左上角的指定位置。仅支持主屏和扩展屏。此参数不传、传undefined或传入目标屏幕ID不存在时，将移动到相对于当前屏幕左上角的指定位置。|

## WindowDensityInfo<sup>15+</sup>

窗口所在显示设备和窗口自定义的显示密度信息，是与像素单位无关的缩放系数，即显示大小缩放系数。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读 | 可选 | 说明       |
| ------ | -------- | ---- | ---- | ---------- |
| systemDensity  | number   | 否   | 否   | 窗口所在屏幕的系统显示大小缩放系数，跟随用户设置变化，该参数变化范围为0.5-4.0。 |
| defaultDensity | number   | 否   | 否   | 窗口所在屏幕的系统默认显示大小缩放系数，跟随窗口所在屏幕变化，该参数变化范围为0.5-4.0。 |
| customDensity | number   | 否   | 否   | 窗口自定义设置的显示大小缩放系数，该参数取值范围为0.5-4.0。未设置该参数时，将跟随系统显示大小缩放系数变化。该参数仅主窗口生效，在子窗、模态窗、全局悬浮窗或系统窗口上等于系统显示大小缩放系数(systemDensity)。 |

## WindowInfoOptions
窗口布局信息过滤选项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| excludeSystemWindows | boolean | 否 | 是 | 是否排除系统窗口。true表示需要排除，false表示不排除，默认为false。|
| foregroundAboveWindow | number  | 否 | 是 | 需要过滤掉的不高于此窗口层级的窗口的ID。表示只返回层级高于这个窗口的窗口信息。默认值是0，表示忽略本选项；如果值小于0，返回1300016错误码；如果指定的窗口不存在，则与设置为0等价。|
| foregroundBelowWindow | number  | 否 | 是 | 需要过滤掉的不低于此窗口层级的窗口的ID。表示只返回层级低于这个窗口的窗口信息。默认值是0，表示忽略本选项；如果值小于0，返回1300016错误码；如果指定的窗口不存在，则与设置为0等价。若同时指定foregroundBelowWindow和foregroundAboveWindow，且两者都是有效的窗口ID，但foregroundBelowWindow指定的窗口的层级未高于foregroundAboveWindow指定的窗口，则返回空数组。|

## WindowLayoutInfo<sup>15+</sup>

窗口布局信息。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| windowRect | [Rect](arkts-apis-window-i.md#rect7)  | 否 | 否 | 窗口尺寸，窗口在屏幕上的实际位置和大小。<br/> **原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。|
| windowAlpha | number  | 否 | 是 | 窗口透明度。有效值范围为[0.0, 1.0]，0.0表示完全透明，1.0表示完全不透明。默认值是-1.0，表示未查询到窗口透明度或者查询失败。<br/>说明：本透明度非窗口背景色透明度（可通过[setWindowBackgroundColor](arkts-apis-window-Window.md#setwindowbackgroundcolor9)接口设置）。<br/>**起始版本：** 26.0.0 <br/>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 <br/>**模型约束：** 此接口仅可在Stage模型下使用。|

## KeyboardInfo<sup>18+</sup>

软键盘窗口信息。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| beginRect | [Rect](arkts-apis-window-i.md#rect7)  |  否  |  否   | 动画开始前软键盘的位置和大小。<br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| endRect | [Rect](arkts-apis-window-i.md#rect7)  |  否  |  否   | 动画结束后软键盘的位置和大小。<br> **原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| animated<sup>20+</sup> | boolean  |  否  |  是   | 当前是否有显示/隐藏动画，true表示有动画，false表示没有。<br> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| config<sup>20+</sup> | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20)  |  否  |  是  | 动画配置信息。<br> **原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## ShowWindowOptions<sup>20+</sup>

显示子窗口或系统窗口时的参数。

**系统能力：** SystemCapability.Window.SessionManager

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| focusOnShow | boolean  |  否  |  是  | 窗口调用[showWindow()](arkts-apis-window-Window.md#showwindow20)显示时是否自动获焦，默认为true。该参数对主窗、模态窗、dialog窗口不生效。|

## WindowAnimationConfig<sup>20+</sup>

窗口动画参数配置。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称     | 类型                                                      | 只读 | 可选 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ---- |------------------------------------------------------------ |
| curve    | [WindowAnimationCurve](arkts-apis-window-e.md#windowanimationcurve20)           |  否  |  否   | 动画曲线类型。                                               |
| duration | number                                                    |  否  |  是   | 动画播放的时长，单位毫秒（ms）。<br/>默认值：0，最大值：3000。<br/>根据动画曲线类型决定是否必填。 |
| param    | [WindowAnimationCurveParam](arkts-apis-window-t.md#windowanimationcurveparam20) |  否  |  是   | 动画曲线参数，根据动画曲线类型决定是否必填。                 |

## WindowSnapshotAnimationConfig

窗口截图动画配置，仅支持在调用[maximizeWithOptions()](arkts-apis-window-Window.md#maximizewithoptions)或[recover()](arkts-apis-window-Window.md#recover)接口时配置。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| duration |  number  |  否  |  是  | 截图淡出动画执行时长，单位为ms，取值为非负整数，输入浮点数会向下取整。不指定时使用系统默认值：全屏模式和自由悬浮窗口模式互相切换场景下截图淡出动画执行时长默认值为400，其他场景默认值为250。取值范围为[0, 400]，超出取值范围会报错。|
| delay |  number  |  否  |  是  | 截图淡出动画延迟时长，单位为ms，取值为非负整数，输入浮点数会向下取整。不指定时使用系统默认值：全屏模式和自由悬浮窗口模式互相切换场景下截图淡出动画延迟时长默认值为350，其他场景默认值为50。取值范围为[0, 350]，超出取值范围会报错。|

## MaximizeOptions

最大化配置选项。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- |------------------------------------------ |
| maximizePresentation | [MaximizePresentation](arkts-apis-window-e.md#maximizepresentation12)  |  否  |  是  | 最大化时的布局方式，默认值为[MaximizePresentation](arkts-apis-window-e.md#maximizepresentation12).ENTER_IMMERSIVE。|
| acrossDisplayPresentation | [AcrossDisplayPresentation](arkts-apis-window-e.md#acrossdisplaypresentation)  |  否  |  是  | 折叠屏跨屏策略，默认值为[AcrossDisplayPresentation](arkts-apis-window-e.md#acrossdisplaypresentation).FOLLOW_ACROSS_DISPLAY_SETTING。仅主窗口可设置，非主窗口调用时返回错误码1300004。**设备行为差异：** 仅在具备折叠功能的2in1设备可正常调用；在其他设备上调用不生效。|
| snapshotAnimationConfig | [WindowSnapshotAnimationConfig](#windowsnapshotanimationconfig)  |  否  |  是  | 截图动画配置。在窗口最大化和窗口恢复[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)过程中，系统会通过截图动画遮盖应用布局变化的跳变，可通过此属性指定截图淡出动画延迟和淡出动画执行时长。仅主窗口可设置，主窗口不指定时使用系统默认动画；子窗默认无截图动画，即截图动画参数duration和delay均为0，传入其他动画参数返回1300004错误码。当duration为0时，表示取消截图动画。|

## WindowInfo<sup>18+</sup>

当前窗口的详细信息。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型   | 只读 | 可选 | 说明                                       |
| ------ | ------ | ---- | ---- | ------------------------------------------ |
| rect  | [Rect](arkts-apis-window-i.md#rect7)   | 否   | 否   | 窗口尺寸。 |
| bundleName  | string   | 否   | 否   | 应用Bundle的名称。          |
| abilityName | string   | 否   | 否   | Ability的名称。               |
| windowId | number | 否   | 否   | 窗口ID。   |
| windowStatusType | [WindowStatusType](arkts-apis-window-e.md#windowstatustype11) | 否   | 否   | 窗口模式枚举。   |
| isFocused | boolean | 否   | 是   | 窗口是否获焦。true表示窗口获焦；false表示窗口未获焦。返回值与[isFocused()](arkts-apis-window-Window.md#isfocused12)接口一致。   |
| globalDisplayRect<sup>20+</sup> | [Rect](arkts-apis-window-i.md#rect7)   | 否   | 是   | 全局坐标系下的窗口尺寸，其中的宽高是未经缩放计算过的原始值。扩展屏场景下以主屏左上角为坐标原点，虚拟屏场景下以虚拟屏左上角为坐标原点。默认值：[0, 0, 0, 0]。|
| displayId | number | 否 | 是 | 窗口所在屏幕的ID。默认返回主屏幕ID，该参数为整数。<br>**起始版本：** 26.0.0 <br> **模型约束：** 此接口仅可在Stage模型下使用。 |
| globalRect | [Rect](arkts-apis-window-i.md#rect7) | 否 | 是 | 窗口所在物理屏幕上的真实显示区域，以所在屏幕的左上角为坐标原点。若窗口显示时经过了缩放，获取到的是缩放后窗口在屏幕上的真实位置和大小。默认值：[0, 0, 0, 0]。<br>**起始版本：** 26.0.0 <br> **模型约束：** 此接口仅可在Stage模型下使用。 |

## TransitionAnimation<sup>20+</sup>

窗口转场动画配置。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Window.SessionManager

| 名称    | 类型                                              | 只读 | 可选 | 说明                                                         |
| ------- | ------------------------------------------------- | ---- | ---- |------------------------------------------------------------ |
| config  | [WindowAnimationConfig](arkts-apis-window-i.md#windowanimationconfig20) |  否  |  否   | 本次转场动画配置。                                           |
| opacity | number                                            |  否  |  是   | 不透明度，转场动画作用的窗口属性，值为0时窗口完全透明，默认值为1.0。当动画类型为WindowTransitionType.DESTROY时，代表动画终点的不透明度。取值范围0~1.0，在动画结束时恢复为1.0。 |

## StartAnimationParams<sup>20+</sup>

启动动画配置。

仅对同应用的不同ability间跳转生效。

仅对全屏应用生效。

**设备行为差异：** 该接口在Phone设备的非[自由多窗模式](../../windowmanager/window-terminology.md#free-multi-window-mode自由多窗模式)、Tablet设备的非[自由多窗模式](../../windowmanager/window-terminology.md#free-multi-window-mode自由多窗模式)且非电脑模式下可正常调用，在其他设备、[自由多窗模式](../../windowmanager/window-terminology.md#free-multi-window-mode自由多窗模式)或电脑模式下调用不生效也不报错。

**系统能力：** SystemCapability.Window.SessionManager
| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type             | [AnimationType](arkts-apis-window-e.md#animationtype20)                 | 否   | 否   | 窗口动画类型。|

## WindowCreateParams<sup>20+</sup>

应用启动时的窗口参数配置。

**系统能力：** SystemCapability.Window.SessionManager
| 名称             | 类型                                                                     | 只读 | 可选 | 说明                                                         |
| ---------------- | ----------------------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| animationParams             | [StartAnimationParams](arkts-apis-window-i.md#startanimationparams20)                 | 否   | 是   | 启动动画参数配置。默认值为undefined，若不配置将保持系统默认动效。 |
| needAnimation<sup>23+</sup> | boolean | 否 | 是 | 是否启用窗口创建动效。<br>传入true时，跟随系统默认动效。传入false时，表示关闭窗口创建动效，仅在[自由窗口状态](../../windowmanager/window-terminology.md#freeform-window自由窗口)的情况下生效。<br>此参数不填时，默认为undefined，跟随系统默认动效。<br> **模型约束：** 此接口仅可在Stage模型下使用。 |

## Callback<sup>15+</sup>

### (data: T)<sup>15+</sup>

(data: T): V

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

## OrientationResult

设置窗口显示方向的执行结果。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：**  SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读  | 可选 | 说明                    |
| ------ | ---- | ----- | ---- | ----------------------- |
| executionResult | [OrientationExecutionResult](arkts-apis-window-e.md#orientationexecutionresult) | 否 | 否 | 窗口显示方向的执行结果枚举。|

## SubWindowOptions<sup>11+</sup>

子窗口创建参数。

**系统能力：** SystemCapability.Window.SessionManager

| 名称      | 类型  | 只读 | 可选 | 说明         |
| ---------- | ---- | ---- | ---- | ----------- |
| title<sup>11+</sup>    | string | 否 | 否 | 子窗口标题。标题显示区域最右端不超过系统三键区域最左端，超过部分以省略号表示。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| decorEnabled<sup>11+</sup> | boolean | 否 | 否 | 子窗口是否显示标题栏。true表示子窗口显示标题栏，false表示子窗口不显示标题栏。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。       |
| isModal<sup>12+</sup>    | boolean | 否 | 是 | 子窗口是否启用模态属性。true表示子窗口启用模态属性，false表示子窗口禁用模态属性。不设置，则默认为false。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| modalityType<sup>14+</sup>    | [ModalityType](arkts-apis-window-e.md#modalitytype14) | 否 | 是 | 子窗口模态类型，仅当子窗口启用模态属性时生效。不设置，则默认为WINDOW_MODALITY。<br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。       |
| windowRect<sup>18+</sup>    | [Rect](arkts-apis-window-i.md#rect7) | 否 | 是 | 子窗口矩形区域，其中子窗口存在大小限制，具体参考[resize()](arkts-apis-window-Window.md#resize9)方法。不设置且未调用[showWindow()](arkts-apis-window-Window.md#showwindow9)显示前，则默认为{left: 0, top: 0, width: 0, height: 0}。具体参考[子窗口开发指导](../../windowmanager/subwindow-guide.md)。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|
| zLevel<sup>18+</sup>    | number | 否 | 是 | 子窗口层级级别，仅当子窗口未启用模态属性，即未设置isModal时生效。该参数是整数，取值范围为[-10000, 10000]，浮点数输入将向下取整。不设置，则默认为0。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。|
| maximizeSupported<sup>19+</sup>    | boolean | 否 | 是 | 子窗口是否支持最大化特性。true表示子窗口支持最大化，false表示子窗口不支持最大化。不设置，则默认为false。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。<br> **设备行为差异：** 该参数在支持并处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上可正常调用；在不支持[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上，作为入参使用时，对应接口不生效不报错；在支持但不处于[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态的设备上，作为入参使用时，对应接口不生效不报错，切换到[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态后生效。|
| outlineEnabled<sup>20+</sup>    | boolean | 否 | 是 | 子窗口是否显示描边。true表示子窗口显示描边，false表示子窗口不显示描边。不设置，则默认为false。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。<br> **设备行为差异：** 该参数在PC/2in1设备、其他设备的电脑模式中可正常调用，在其他设备和其他模式中作为入参使用时，对应接口不生效不报错。|
| zLevelAboveParentLoosened | boolean | 否 | 是 | 子窗是否是[独立子窗](../../windowmanager/window-type-overview.md#辅助窗口)。true表示子窗是独立子窗，false表示子窗不是独立子窗。不设置，则默认为false。<br>**起始版本：** 26.0.0 <br>**原子化服务API：** 从API version 26.0.0开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## KeyFramePolicy<sup>20+</sup>

关键帧的策略配置。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读  | 可选 | 说明                    |
| ------ | ---- | ----- | ---- | ----------------------- |
| enable | boolean | 否 | 否 | 是否开启关键帧。true表示开启关键帧策略，在拖拽窗口时会按照关键帧布局进行切换；false表示关闭关键帧策略，窗口拖拽时平滑过渡。 |
| interval | number | 否 | 是 | 设置关键帧布局切换的拖拽时间间隔，单位为毫秒，默认值为1000。表示拖拽持续该时间后将触发布局切换，值越大需要拖拽越久才会切换。取值为正整数，浮点数向下取整。与distance判断为或的关系：满足其一即开始布局切换。 |
| distance | number | 否 | 是 | 设置关键帧布局切换的拖拽距离间隔，单位为px，默认值为1000。表示拖拽距离达到该值后将触发布局切换，值越大需要拖拽越远才会切换。取值为0或正整数，浮点数向下取整。设置为0时，忽略拖拽距离因素，仅通过interval判断是否切换。与interval判断为或的关系：满足其一即开始布局切换。|
| animationDuration | number | 否 | 是 | 设置关键帧布局的动效切换时间，单位为毫秒，默认值为100。取值为0或正整数，浮点数向下取整。 |
| animationDelay | number | 否 | 是 | 设置关键帧布局切换动效延迟时间，单位为毫秒，默认值为100。取值为0或正整数，浮点数向下取整。 |

## MainWindowInfo<sup>21+</sup>

主窗口信息。

**系统能力：** SystemCapability.Window.SessionManager

| 名称   | 类型 | 只读  | 可选 | 说明                    |
| ------ | ---- | ----- | ---- | ----------------------- |
| displayId | number  | 否 | 否 | 主窗口所在的屏幕ID。 |
| windowId  | number  | 否 | 否 | 主窗口ID。 |
| showing   | boolean | 否 | 否 | 主窗口的前后台状态。true表示主窗口在前台，false表示主窗口不在前台。|
| label     | string  | 否 | 否 | 主窗口的任务名称。 |

## WindowSnapshotConfiguration<sup>21+</sup>

主窗口截图的配置项。

**系统能力：** SystemCapability.Window.SessionManager

| 名称     | 类型      | 只读 | 可选 | 说明               |
| -------- | -------- | ---- | ---- | ------------------ |
| useCache | boolean  | 否   | 是   | 是否使用主窗口的已有截图。默认值为true。 true表示使用主窗口的已有截图，若主窗口无保存的截图，则使用主窗口的最新截图。false表示使用主窗口的最新截图。|

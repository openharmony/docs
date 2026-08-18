# ArcList

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @wind_-->
<!--Designer: @yangcan18-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->

弧形列表由沿弧形排列的一系列列表项组成，适用于圆形屏幕设备。适合连续、多行呈现同类数据，例如图片和文本。

> **说明：**
>
> - 该组件从API version 18开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 该组件支持在Phone、PC/2in1、Tablet、TV、Wearable设备上使用。API version 22及以前版本，在Phone、PC/2in1、Tablet、TV上使用会编译告警，但可以正常运行。


## 导入模块

> **说明：**
>
> - ArcListAttribute是用于配置ArcList组件属性的关键接口。API version 21及之前版本，导入ArcList组件后需要开发者手动导入ArcListAttribute，否则会编译报错。从API version 22开始，编译工具链识别到导入ArcList组件后，会自动导入ArcListAttribute，无需开发者手动导入ArcListAttribute。
>
> - 如果开发者手动导入ArcListAttribute，DevEco Studio会显示置灰，API version 21及之前版本删除会编译报错，从API version 22开始，删除对功能无影响。


API version 21及之前版本：

```ts
import { ArcList, ArcListAttribute } from '@kit.ArkUI';
```

API version 22及之后版本：

```ts
import { ArcList } from '@kit.ArkUI';
```

## 子组件

仅支持[ArcListItem](ts-container-arclistitem.md)和自定义组件。自定义组件在ArcList下使用时，请使用ArcListItem作为自定义组件的顶层组件，请勿直接给自定义组件设置属性和事件方法，因为ArcList通过ArcListItem管理子组件的布局和事件处理，直接设置可能导致部分功能无法正常生效。

> **说明：**
>
> ArcList的子组件索引值计算规则：
>
> - 按子组件的顺序依次递增。
>
> - [if/else](../../../ui/rendering-control/arkts-rendering-control-ifelse.md)语句中，只有条件成立的分支内的子组件会参与索引值计算，条件不成立的分支内子组件不计算索引值。
>
> - [ForEach](../../../ui/rendering-control/arkts-rendering-control-foreach.md)/[LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md)语句中，会计算展开所有子组件索引值。
>
> - [if/else](../../../ui/rendering-control/arkts-rendering-control-ifelse.md)、[ForEach](../../../ui/rendering-control/arkts-rendering-control-foreach.md)和[LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md)发生变化以后，会更新子组件索引值。
>
> - ArcList子组件[visibility](ts-universal-attributes-visibility.md#visibility)属性设置为Hidden或None依然会计算索引值。


## 接口

ArcList(options?: ArkListOptions)

创建弧形列表实例，传入弧形列表配置项参数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                  | 必填 | 说明                |
| ------- | ----------------------------------------- | ---- | ----------------------- |
| options | [ArkListOptions](#arklistoptions) | 否   | 弧形列表的配置项，用于设置初始加载位置、滚动控制器和头部组件。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### digitalCrownSensitivity

digitalCrownSensitivity(sensitivity: Optional\<CrownSensitivity>)

设置表冠响应灵敏度。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sensitivity | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[CrownSensitivity](ts-appendix-enums.md#crownsensitivity18)&gt; | 是   | 表冠响应灵敏度。<br>默认值：CrownSensitivity.MEDIUM，响应速度适中。 |

### space

space(space: Optional\<LengthMetrics>)

设置列表子项之间的间距。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                               |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------- |
| space  | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)&gt; | 是   | 列表子项之间的间距。<br>默认值：LengthMetrics.vp(0)<br>ArcList子组件的[visibility](ts-universal-attributes-visibility.md#visibility)属性设置为None时不显示，但该子组件上下的space还会生效。 |

### scrollBar

scrollBar(status: Optional\<BarState>)

设置滚动条状态。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型                                                 | 必填 | 说明                                     |
| ------ | ---------------------------------------------------- | ---- | ---------------------------------------- |
| status | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[BarState](ts-appendix-enums.md#barstate)&gt; | 是   | 滚动条状态。<br>默认值：BarState.Auto |

### cachedCount

cachedCount(count: Optional\<number>)

设置列表中ArcListItem的预加载数量，懒加载场景只会预加载ArcList显示区域外上下各cachedCount行的ArcListItem，非懒加载场景会全部加载。懒加载、非懒加载都只布局ArcList显示区域+ArcList显示区域外上下各cachedCount行的ArcListItem。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型              | 必填 | 说明                                       |
| ------ | ----------------- | ---- | ------------------------------------------ |
| count  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<number> | 是   | ArcListItem的预加载数量。<br>默认值：根据屏幕内显示的节点个数设置，最大值为16。<br>取值范围：[0, +∞)<br>设置为负数时，按1处理。 |

### chainAnimation

chainAnimation(enable: Optional\<boolean>)

设置当前ArcList是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。

链式联动效果：ArcList内的ArcListItem间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。

链式动效生效需要满足前提条件：ArcList边缘效果为[EdgeEffect.Spring](ts-appendix-enums.md#edgeeffect)类型。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型               | 必填 | 说明                                                         |
| ------ | ------------------ | ---- | ------------------------------------------------------------ |
| enable | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 是否启用链式联动动效。仅当边缘效果为[EdgeEffect.Spring](ts-appendix-enums.md#edgeeffect)时，链式联动动效才会生效。<br>默认值：false，不启用链式联动。true，启用链式联动。 |

### enableScrollInteraction

enableScrollInteraction(enable: Optional\<boolean>)

设置是否支持滚动手势。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型               | 必填 | 说明                                |
| ------ | ------------------ | ---- | ----------------------------------- |
| enable | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是   | 是否支持滚动手势。设置为true时可以通过手指或者鼠标滚动，设置为false时无法通过手指或者鼠标滚动，但不影响控制器[Scroller](ts-container-scroll.md#scroller)的滚动接口。<br>默认值：true |

### fadingEdge

fadingEdge(enable: Optional&lt;boolean&gt;)

设置是否开启边缘渐隐效果。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                              | 必填 | 说明                                                         |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| enable | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;boolean&gt;                           | 是   | fadingEdge生效时，会覆盖原组件的`.overlay()`属性。<br>fadingEdge生效时，建议不在该组件上设置background相关属性，会影响渐隐的显示效果。<br>fadingEdge生效时，组件会裁剪到边界，设置组件的[clip](ts-universal-attributes-sharp-clipping.md#clip12)属性为false不生效。<br>设置为true时开启边缘渐隐效果，设置为false时不开启边缘渐隐效果。<br>默认值：false |

### friction

friction(friction: Optional\<number>)

设置摩擦系数，手动滑动滚动区域时生效，仅影响惯性滚动过程。设置为小于等于0的值时，按默认值处理。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名   | 类型              | 必填 | 说明                         |
| -------- | ----------------- | ---- | ---------------------------- |
| friction | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<number> | 是   | 摩擦系数，手动滑动滚动区域时生效，仅影响惯性滚动过程。设置为小于等于0的值时，按默认值处理。<br>默认值：0.8<br>取值范围：(0, +∞) |

### scrollBarWidth

scrollBarWidth(width: Optional\<LengthMetrics>)

设置ArcList滚动条在按压态下的宽度。未设置时，按压态宽度为LengthMetrics.vp(24)。非按压态宽度固定为LengthMetrics.vp(4)，不受该属性影响。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                                        |
| ------ | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| width  | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)&gt; | 是   | ArcList滚动条在按压态下的宽度。<br>默认值：LengthMetrics.vp(24)<br>非按压态宽度：LengthMetrics.vp(4)<br>设置为负值、undefined等异常值时，按滚动条的普通态宽度处理。<br>单位：vp |

### scrollBarColor

scrollBarColor(color: Optional\<ColorMetrics>)

设置滚动条的颜色。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                                     |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------- |
| color  | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)&gt; | 是   | 设置滚动条颜色。<br>默认值：ColorMetrics.numeric(0xA9FFFFFF)<br>异常值undefined和null按照无效值处理，本次设置不生效。 |

### flingSpeedLimit

flingSpeedLimit(speed: Optional\<number>)

限制跟手滑动结束后，惯性滚动动效开始时的最大初始速度。设置为小于等于0的值时，按默认值处理。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型              | 必填 | 说明                            |
| ------ | ----------------- | ---- | ------------------------------- |
| speed  | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<number> | 是   | 惯性滚动动效开始时的最大初始速度。设置为小于等于0的值时，按默认值处理。<br>默认值：9000<br>单位：vp/s<br>取值范围：(0, +∞)<br>异常值undefined和null按照无效值处理，本次设置不生效。 |

### childrenMainSize

childrenMainSize(size: Optional\<ChildrenMainSize>)

设置ArcList组件的子组件在主轴方向的大小信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

<!--Table: 10%; auto; 10%; auto-->
| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size   | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[ChildrenMainSize](ts-container-scrollable-common.md#childrenmainsize12对象说明)&gt; | 是   | 通过[ChildrenMainSize](ts-container-scrollable-common.md#childrenmainsize12对象说明)对象向ArcList组件精确提供所有子组件在主轴方向的大小信息，能够确保ArcList组件在子组件主轴尺寸不统一、子组件的增删变动、以及使用[scrollToIndex](ts-container-scroll.md#scrolltoindex)等场景时，仍能保持其滑动位置的准确性。进而保证了[scrollTo](ts-container-scroll.md#scrollto)能够精准跳转至指定位置，[currentOffset](ts-container-scroll.md#currentoffset)或[offset](ts-container-scroll.md#offset23)准确反映当前的滑动位置，且内置滚动条能够实现平滑移动，避免任何跳跃或突变。从API version 23开始，新增offset接口。<br> **说明：** <br>提供的主轴方向大小必须与子组件实际在主轴方向的大小一致，否则可能导致ArcList组件显示异常。子组件在主轴方向大小发生变化或进行增删操作时，必须通过调用ChildrenMainSize对象的方法在变更后通知ArcList组件，否则可能导致ArcList组件显示异常。 |

## 事件

### onScrollIndex

onScrollIndex(handler: Optional\<ArcScrollIndexHandler>)

当子组件划入或划出ArcList的显示区域时，将触发此事件。在ArcList初始化时，此事件会被触发一次。当ArcList显示区域内的首个或末个子组件的索引值发生变化，或是显示区域中心的子组件发生变动时，同样会触发此事件。

ArcList的边缘效果为弹簧效果时，在ArcList滑动到边缘后继续滑动以及松手回弹的过程中，不会触发onScrollIndex事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                            |
| ------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| handler | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[ArcScrollIndexHandler](#arcscrollindexhandler)&gt; | 是   | 有子组件划入或划出ArcList显示区域时触发该回调。 |

### onReachStart

onReachStart(handler: Optional\<VoidCallback>)

列表到达起始位置时触发。

当ArcList进行初始化时，若[initialIndex](#arklistoptions)设定为0，将触发一次事件。当ArcList滚动至起始位置，亦会触发一次事件。在ArcList的边缘效果设置为弹簧效果时，滑动经过起始位置时会触发一次事件，而在回弹返回起始位置时，将再次触发一次事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                     |
| ------- | ------------------------------------------------ | ---- | ------------------------ |
| handler | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[VoidCallback](ts-types.md#voidcallback12)&gt; | 是   | 列表到达起始位置时触发。 |

### onReachEnd

onReachEnd(handler: Optional\<VoidCallback>)

列表到达末尾位置时触发。

ArcList边缘效果为弹簧效果时，滑动经过末尾位置时触发一次该事件，回弹返回末尾位置时再触发一次该事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                     |
| ------- | ------------------------------------------------ | ---- | ------------------------ |
| handler | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[VoidCallback](ts-types.md#voidcallback12)&gt; | 是   | 列表到达末尾位置时触发。 |

### onScrollStart

onScrollStart(handler: Optional\<VoidCallback>)

列表滑动开始时触发。手指拖动列表或列表的滚动条触发的滑动开始时，会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画开始时会触发该事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                 |
| ------- | ------------------------------------------------ | ---- | -------------------- |
| handler | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[VoidCallback](ts-types.md#voidcallback12)&gt; | 是   | 列表滑动开始时触发。 |

### onScrollStop

onScrollStop(handler: Optional\<VoidCallback>)

列表滑动停止时触发。手指拖动列表或列表的滚动条触发的滑动，手指离开屏幕后滑动停止时会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画停止会触发该事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                             | 必填 | 说明                 |
| ------- | ------------------------------------------------ | ---- | -------------------- |
| handler | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[VoidCallback](ts-types.md#voidcallback12)&gt; | 是   | 列表滑动停止时触发。 |

### onWillScroll

onWillScroll(handler: Optional\<OnWillScrollCallback>)

列表滑动时每帧开始前触发，返回当前帧将要滑动的偏移量和当前滑动状态。返回的偏移量为计算得到的将要滑动的偏移量值，并非最终实际滑动偏移。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| handler | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[OnWillScrollCallback](ts-container-scrollable-common.md#onwillscrollcallback12)&gt; | 是 | 列表滑动时每帧开始前触发的回调。 |

> **说明：**
>
> 调用[scrollEdge](ts-container-scroll.md#scrolledge)和不带动画的[scrollToIndex](ts-container-scroll.md#scrolltoindex)时，不触发onWillScroll。

### onDidScroll

onDidScroll(handler: Optional\<OnScrollCallback>)

列表滑动时触发，返回当前帧滑动的偏移量和当前滑动状态。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| handler | [Optional](ts-universal-attributes-custom-property.md#optionalt)&lt;[OnScrollCallback](ts-container-scrollable-common.md#onscrollcallback12)&gt; | 是 | 列表滑动时触发的回调。 |

## ArkListOptions

包含创建ArcList组件的基础参数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称       | 类型                                    | 只读 | 可选 | 说明                                                     |
| ------------ | ------------------------------------------- | ---- | --- | ------------------------------------------------------------ |
| initialIndex | number                                      | 否   | 是 | 设置当前ArcList初次加载时视窗起始位置显示的item的索引值。<br>默认值：0<br>**说明：** <br>设置为负数或超过了当前ArcList最后一个item的索引值时视为无效取值，无效取值按默认值显示。 |
| scroller     | [Scroller](ts-container-scroll.md#scroller) | 否   | 是 | 可滚动组件的控制器。与ArcList绑定后，可以通过它控制ArcList的滚动。不设置时不绑定滚动控制器。<br>**说明：** <br>不允许和其他滚动类组件，如：[List](ts-container-list.md)、[Grid](ts-container-grid.md)、[Scroll](ts-container-scroll.md)和[WaterFlow](ts-container-waterflow.md)绑定同一个滚动控制对象。 |
| header       | [ComponentContent](../js-apis-arkui-ComponentContent.md)                            | 否   | 是 | ArcList的头部组件，用于在列表顶部显示标题或自定义内容。不设置时不显示头部组件。                                               |

## ArcScrollIndexHandler

type ArcScrollIndexHandler = (start: number, end: number, center: number) => void

有子组件划入或划出ArcList显示区域时触发的回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| start  | number | 是   | ArcList显示区域内第一个子组件的索引值。   |
| end    | number | 是   | ArcList显示区域内最后一个子组件的索引值。 |
| center | number | 是   | ArcList显示区域内中间位置子组件的索引值。 |

## 示例

该示例增加了ArcList支持标题栏设置的效果，子项自动缩放显示。

```ts
// xxx.ets
import { ComponentContent, LengthMetrics, UIContext, CircleShape } from '@kit.ArkUI';
// 从API version 22开始，无需手动导入ArcListAttribute和ArcListItemAttribute。具体请参考ArcList、ArcListItem的导入模块说明。
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@kit.ArkUI';

@Builder
function buildText() {
  Column() {
    Text('header')
      .fontSize('60px')
      .fontWeight(FontWeight.Bold)
      .fontColor(Color.Black)
  }.margin(0)
}

@Entry
@Component
struct Index {
  @State private numItems: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  private watchSize: string = '466px'; // Wearable默认宽高：466*466
  private listSize: string = '414px'; // item宽度

  context: UIContext = this.getUIContext();
  headerContent: ComponentContent<Object> = new ComponentContent(this.context, wrapBuilder(buildText));

  @Builder
  buildList() {
    Stack() {
      Column() {
      }
      .justifyContent(FlexAlign.Center)
      .width(this.watchSize)
      .height(this.watchSize)
      .clipShape(new CircleShape({ width: '100%', height: '100%' }))
      .backgroundColor(Color.White)

      ArcList({ initialIndex: 0, header: this.headerContent }) {
        ForEach(this.numItems, (item: number, index: number) => {
          ArcListItem() {
            Button('' + item, { type: ButtonType.Capsule })
              .width(this.listSize)
              .height('100px')
              .fontSize('40px')
              .focusable(true)
              .focusOnTouch(true)
              .backgroundColor(0x17A98D)
          }.align(Alignment.Center)
        }, (item: number, index: number) => (item + index).toString())
      }
      .space(LengthMetrics.px(10))
      .borderRadius(this.watchSize)
      .focusable(true)
      .focusOnTouch(true)
      .defaultFocus(true)
    }
    .align(Alignment.Center)
    .width(this.watchSize)
    .height(this.watchSize)
    .border({color: Color.Black, width: 1})
    .borderRadius(this.watchSize)
  }

  build() {
    Column() {
      this.buildList()
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
    .justifyContent(FlexAlign.Center)
  }
}
```

![arkts-arclist](figures/arkts-arclist.png)
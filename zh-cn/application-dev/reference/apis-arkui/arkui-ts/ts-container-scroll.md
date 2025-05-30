# Scroll

可滚动的容器组件，当子组件的布局尺寸超过父组件的尺寸时，内容可以滚动。

>  **说明：**
>  - 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 该组件嵌套List子组件滚动时，若List不设置宽高，则默认全部加载，在对性能有要求的场景下建议指定List的宽高。
>  - 该组件滚动的前提是主轴方向大小小于内容大小。
>  - Scroll组件[通用属性clip](ts-universal-attributes-sharp-clipping.md)的默认值为true。


## 子组件

支持单个子组件。


## 接口

Scroll(scroller?: Scroller)

创建Scroll滚动容器。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| scroller | [Scroller](#scroller) | 否 | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/>**说明：** <br/>不允许和其他滚动类组件，如：[ArcList](ts-container-arclist.md)、[List](ts-container-list.md)、[Grid](ts-container-grid.md)、[Scroll](ts-container-scroll.md)和[WaterFlow](ts-container-waterflow.md)绑定同一个滚动控制对象。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)和[滚动组件通用属性](ts-container-scrollable-common.md#属性)外，还支持以下属性：

### scrollable

scrollable(value: ScrollDirection)

设置滚动方向。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                        | 必填 | 说明                                            |
| ------ | ------------------------------------------- | ---- | ----------------------------------------------- |
| value  | [ScrollDirection](#scrolldirection枚举说明) | 是   | 滚动方向。<br/>默认值：ScrollDirection.Vertical |

### scrollBar

scrollBar(barState: BarState)

设置滚动条状态。如果容器组件无法滚动，则滚动条不显示。如果容器组件的子组件大小为无穷大，则滚动条不支持拖动和伴随滚动。

从API version 10开始，当滚动组件存在圆角时，为避免滚动条被圆角截断，滚动条会自动计算距顶部和底部的避让距离。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型                                      | 必填 | 说明                                   |
| -------- | ----------------------------------------- | ---- | -------------------------------------- |
| barState | [BarState](ts-appendix-enums.md#barstate) | 是   | 滚动条状态。<br/>默认值：BarState.Auto |

### scrollBarColor

scrollBarColor(color: Color | number | string)

设置滚动条的颜色。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明           |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| color  | [Color](ts-appendix-enums.md#color)&nbsp;\|&nbsp;number&nbsp;\|&nbsp;string | 是   | 滚动条的颜色。<br/>默认值：'\#182431'（40%不透明度）<br/>number为HEX格式颜色，支持rgb或者argb，示例：0xffffff。string为rgb或者argb格式颜色，示例：'#ffffff'。   |

### scrollBarWidth

scrollBarWidth(value: number | string)

设置滚动条的宽度，不支持百分比设置。宽度设置后，滚动条正常状态和按压状态宽度均为滚动条的宽度值。如果滚动条的宽度超过Scroll组件主轴方向的高度，则滚动条的宽度会变为默认值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                       | 必填 | 说明                                      |
| ------ | -------------------------- | ---- | ----------------------------------------- |
| value  | number&nbsp;\|&nbsp;string | 是   | 滚动条的宽度。<br/>默认值：4<br/>单位：vp <br/>取值范围：设置为小于0的值时，按默认值处理。设置为0时，不显示滚动条。|

### scrollSnap<sup>10+</sup>

scrollSnap(value: ScrollSnapOptions)

设置Scroll组件的限位滚动模式。

限位动画期间onWillScroll事件上报的滚动操作来源类型为ScrollSource.FLING。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 说明                       |
| ------ | ----------------------------------------- | ---- | -------------------------- |
| value  | [ScrollSnapOptions](#scrollsnapoptions10对象说明) | 是   | Scroll组件的限位滚动模式。 |

### edgeEffect

edgeEffect(edgeEffect: EdgeEffect, options?: EdgeEffectOptions)

设置边缘滑动效果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名                | 类型                                              | 必填 | 说明                                                         |
| --------------------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| edgeEffect            | [EdgeEffect](ts-appendix-enums.md#edgeeffect)     | 是   | Scroll组件的边缘滑动效果，支持弹簧效果和阴影效果。<br/>默认值：EdgeEffect.None |
| options<sup>11+</sup> | [EdgeEffectOptions](ts-container-scrollable-common.md#edgeeffectoptions11对象说明) | 否   | 组件内容大小小于组件自身时，是否开启滑动效果。设置为{ alwaysEnabled: true }会开启滑动效果，{ alwaysEnabled: false }不开启。<br/>默认值：{ alwaysEnabled: true } |

### enableScrollInteraction<sup>10+</sup>

enableScrollInteraction(value: boolean)

设置是否支持滚动手势。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                |
| ------ | ------- | ---- | ----------------------------------- |
| value  | boolean | 是   | 是否支持滚动手势。设置为true时可以通过手指或者鼠标滚动，设置为false时无法通过手指或者鼠标滚动，但不影响控制器[Scroller](ts-container-scroll.md#scroller)的滚动接口。<br/>默认值：true |

### nestedScroll<sup>10+</sup>

nestedScroll(value: NestedScrollOptions)

设置前后两个方向的嵌套滚动模式，实现与父组件的滚动联动。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                  | 必填 | 说明           |
| ------ | ----------------------------------------------------- | ---- | -------------- |
| value  | [NestedScrollOptions](ts-container-scrollable-common.md#nestedscrolloptions10对象说明) | 是   | 嵌套滚动选项。<br/>默认值：{ scrollForward: NestedScrollMode.SELF_ONLY, scrollBackward: NestedScrollMode.SELF_ONLY }|

### friction<sup>10+</sup>

friction(value: number | Resource)

设置摩擦系数，手动划动滚动区域时生效，仅影响惯性滚动过程，对惯性滚动过程中的链式效果有间接影响。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                                      |
| ------ | ---------------------------------------------------- | ---- | --------------------------------------------------------- |
| value  | number&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 摩擦系数。<br/>默认值：非可穿戴设备为0.6，可穿戴设备为0.9。<br/>从API version 11开始，非可穿戴设备默认值为0.7。<br/>从API version 12开始，非可穿戴设备默认值为0.75。<br/>取值范围：(0, +∞)，设置为小于等于0的值时，按默认值处理。 |

### enablePaging<sup>11+</sup>

enablePaging(value: boolean)

设置是否支持划动翻页。如果同时设置了划动翻页enablePaging和限位滚动scrollSnap，则scrollSnap优先生效，enablePaging不生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                  |
| ------ | ------- | ---- | ------------------------------------- |
| value  | boolean | 是   | 是否支持划动翻页。设置为true支持滑动翻页，false不支持。 <br/>默认值：false |

### initialOffset<sup>12+</sup>

initialOffset(value: OffsetOptions)

设置初始滚动偏移量。只在首次布局时生效，后续动态修改该属性值不生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                  |
| ------ | ------- | ---- | ------------------------------------- |
| value  | [OffsetOptions](#offsetoptions12对象说明)  | 是   |当输入的大小为百分比时，初始滚动偏移量为Scroll组件主轴方向大小与百分比数值之积。|

## ScrollDirection枚举说明

滚动方向枚举。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 说明                   |
| ---------- | ------------------------ |
| Horizontal | 仅支持水平方向滚动。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Vertical   | 仅支持竖直方向滚动。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| None       | 不可滚动。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| Free<sup>(deprecated) </sup> | 支持竖直或水平方向滚动<br/> 从API version 9开始废弃。|

## ScrollSnapOptions<sup>10+</sup>对象说明

限位滚动模式对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称       | 类型    | 必填   | 说明       |
| ---------- | --------------------|-------------------- | -------- |
| snapAlign  | [ScrollSnapAlign](ts-container-list.md#scrollsnapalign10枚举说明)   | 是 | 设置Scroll组件限位滚动时的对齐方式。<br/>**说明：** <br/>1.该属性默认值为ScrollSnapAlign.NONE。 |
| snapPagination | [Dimension](ts-types.md#dimension10)&nbsp;\|&nbsp;Array\<Dimension\> | 否 | 设置Scroll组件限位滚动时的分页点。<br/>**说明：** <br/>1.当属性为Dimension时，Dimension表示每页的大小，系统按照该大小进行分页。<br/>2.当属性为Array\<Dimension\>时，每个Dimension表示分页点，系统按照分页点进行分页。每个Dimension的范围为[0,可滑动距离]。<br/>3.当该属性不填或者Dimension为小于等于0的输入时，按异常值，无限位滚动处理。当该属性值为Array\<Dimension\>数组时，数组中的数值必须为单调递增。<br/>4.当输入为百分比时，实际的大小为Scroll组件的视口与百分比数值之积。 |
| enableSnapToStart | boolean   | 否 | 在Scroll组件限位滚动模式下，该属性设置为true后，不允许Scroll在开头和第一页间自由滑动，该属性设置为false后，允许Scroll在开头和第一页间自由滑动。<br/>**说明：** <br/>1.该属性值默认为true。<br/>2.该属性仅当snapPagination属性为Array\<Dimension\>时生效，不支持Dimension。 |
| enableSnapToEnd | boolean   | 否 | 在Scroll组件限位滚动模式下，该属性设置为true后，不允许Scroll在最后一页和末尾间自由滑动，该属性设置为false后，允许Scroll在最后一页和末尾间自由滑动。<br/>**说明：** <br/>1.该属性值默认为true。<br/>2.该属性仅当snapPagination属性为Array\<Dimension\>时生效，不支持Dimension。 |

## 事件

除支持[通用事件](ts-component-general-events.md)和[滚动组件通用事件](ts-container-scrollable-common.md#事件)外，还支持以下事件：
>  **说明：**
>
>  不支持滚动组件通用事件中的[onWillScroll](ts-container-scrollable-common.md#onwillscroll12)、[onDidScroll](ts-container-scrollable-common.md#ondidscroll12)事件。

### onScrollFrameBegin<sup>9+</sup>

onScrollFrameBegin(event: OnScrollFrameBeginCallback)

每帧开始滚动时触发，事件参数传入即将发生的滚动量，事件处理函数中可根据应用场景计算实际需要的滚动量并作为事件处理函数的返回值返回，Scroll将按照返回值的实际滚动量进行滚动。

支持offsetRemain为负值。

若通过onScrollFrameBegin事件和scrollBy方法实现容器嵌套滚动，需设置子滚动节点的EdgeEffect为None。如Scroll嵌套List滚动时，List组件的edgeEffect属性需设置为EdgeEffect.None。

触发该事件的条件：

1、滚动组件触发滚动时触发，包括键鼠操作等其他触发滚动的输入设置。<br/>2、调用除fling接口外的其他滚动控制接口时不触发。<br/>3、越界回弹不触发。<br/>4、拖动滚动条不触发。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                              | 必填 | 说明               |
| ------ | --------------------------------- | ---- | ------------------ |
| event   | [OnScrollFrameBeginCallback](#onscrollframebegincallback18) | 是   | 每帧滚动开始回调函数。 |

### onScroll<sup>(deprecated)</sup>

onScroll(event: (xOffset: number, yOffset: number) => void)

滚动事件回调，返回滚动时水平、竖直方向偏移量，单位vp。

触发该事件的条件：

1、滚动组件触发滚动时触发，支持键鼠操作等其他触发滚动的输入设置。

2、通过滚动控制器API接口调用。

3、越界回弹。

从API version 12开始废弃不再使用，推荐使用[onWillScroll](#onwillscroll12)事件替代。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                      | 必填 | 说明                   |
| ------- | --------------------------------------------------------- | ---- | ---------------------- |
| xOffset     | number                                                  | 是   | 每帧滚动时水平方向的偏移量，Scroll的内容向左滚动时偏移量为正，向右滚动时偏移量为负。<br/>单位vp。 |
| yOffset     | number                                                  | 是   | 每帧滚动时竖直方向的偏移量，Scroll的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>单位vp。 |

### onWillScroll<sup>12+</sup>

onWillScroll(handler: ScrollOnWillScrollCallback)

滚动事件回调，Scroll滚动前触发。

回调当前帧将要滚动的偏移量和当前滚动状态和滚动操作来源，其中回调的偏移量为计算得到的将要滚动的偏移量值，并非最终实际滚动偏移。可以通过该回调返回值指定Scroll将要滚动的偏移。

触发该事件的条件：

1、滚动组件触发滚动时触发，支持键鼠操作等其他触发滚动的输入设置。

2、通过滚动控制器API接口调用。

3、越界回弹。 

>  **说明：**
>
>  滚动事件的回调函数在滚动过程中会被频繁触发，因此应避免在该回调函数中执行耗时操作，以防止应用出现卡顿和丢帧的问题。最佳实践请参考[主线程耗时操作优化指导-高频回调场景](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-time-optimization-of-the-main-thread#section10112623611)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                      | 必填 | 说明                   |
| ------- | --------------------------------------------------------- | ---- | ---------------------- |
| handler | [ScrollOnWillScrollCallback](#scrollonwillscrollcallback12) | 是   | Scroll滚动前触发的回调。 |

### onDidScroll<sup>12+</sup>

onDidScroll(handler: ScrollOnScrollCallback)

滚动事件回调，Scroll滚动时触发。

返回当前帧滚动的偏移量和当前滚动状态。

触发该事件的条件：

1、滚动组件触发滚动时触发，支持键鼠操作等其他触发滚动的输入设置。

2、通过滚动控制器API接口调用。

3、越界回弹。 

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                                      | 必填 | 说明                   |
| ------- | --------------------------------------------------------- | ---- | ---------------------- |
| handler | [ScrollOnScrollCallback](#scrollonscrollcallback12) | 是   | Scroll滚动时触发的回调。 |

### onScrollEdge

onScrollEdge(event: OnScrollEdgeCallback)

滚动到边缘事件回调。

触发该事件的条件：

1、滚动组件滚动到边缘时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用。<br/>3、越界回弹。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明               |
| ------ | --------------------------------- | ---- | ------------------ |
| event   | [OnScrollEdgeCallback](#onscrolledgecallback18) | 是   | 滚动到的边缘位置。 |

### onScrollEnd<sup>(deprecated) </sup>

onScrollEnd(event: () => void)

滚动停止事件回调。

触发该事件的条件：

1、滚动组件触发滚动后停止，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用后停止，带过渡动效。

该事件从API version 9开始废弃，使用onScrollStop事件替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onScrollStart<sup>9+</sup>

onScrollStart(event: VoidCallback)

滚动开始时触发。手指拖动Scroll或拖动Scroll的滚动条触发的滚动开始时，会触发该事件。使用[Scroller](#scroller)滚动控制器触发的带动画的滚动，动画开始时会触发该事件。

触发该事件的条件：

1、滚动组件开始滚动时触发，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用后开始，带过渡动效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                              | 必填 | 说明               |
| ------ | --------------------------------- | ---- | ------------------ |
| event   | [VoidCallback](ts-types.md#voidcallback12) | 是   | 滚动开始回调。 |

### onScrollStop<sup>9+</sup>

onScrollStop(event: VoidCallback)

滚动停止时触发。手拖动Scroll或拖动Scroll的滚动条触发的滚动，手离开屏幕并且滚动停止时会触发该事件。使用[Scroller](#scroller)滚动控制器触发的带动画的滚动，动画停止时会触发该事件。

触发该事件的条件：

1、滚动组件触发滚动后停止，支持键鼠操作等其他触发滚动的输入设置。<br/>2、通过滚动控制器API接口调用后开始，带过渡动效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                              | 必填 | 说明               |
| ------ | --------------------------------- | ---- | ------------------ |
| event   | [VoidCallback](ts-types.md#voidcallback12) | 是   | 滚动停止回调。 |

## ScrollOnScrollCallback<sup>12+</sup>

type ScrollOnScrollCallback = (xOffset: number, yOffset: number, scrollState: ScrollState) => void

Scroll滚动时触发的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名      | 类型                                                    | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| xOffset     | number                                                  | 是   | 每帧滚动时水平方向的偏移量，Scroll中的内容向左滚动时偏移量为正，向右滚动时偏移量为负。<br/>单位vp。 |
| yOffset     | number                                                  | 是   | 每帧滚动时竖直方向的偏移量，Scroll中的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>单位vp。 |
| scrollState | [ScrollState](ts-container-list.md#scrollstate枚举说明) | 是  | 当前滚动状态。                                               |

>  **说明：**
>
>  若通过onScrollFrameBegin事件和scrollBy方法实现容器嵌套滚动，需设置子滚动节点的EdgeEffect为None。如Scroll嵌套List滚动时，List组件的edgeEffect属性需设置为EdgeEffect.None。

## ScrollOnWillScrollCallback<sup>12+</sup>

type ScrollOnWillScrollCallback = (xOffset: number, yOffset: number, scrollState: ScrollState, scrollSource: ScrollSource) => void | OffsetResult

Scroll滚动前触发的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名      | 类型                                                    | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| xOffset     | number                                                  | 是   | 每帧滚动时水平方向的偏移量，Scroll中的内容向左滚动时偏移量为正，向右滚动时偏移量为负。<br/>单位vp。 |
| yOffset     | number                                                  | 是   | 每帧滚动时竖直方向的偏移量，Scroll中的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>单位vp。 |
| scrollState | [ScrollState](ts-container-list.md#scrollstate枚举说明) | 是  | 当前滚动状态。                                               |
| scrollSource | [ScrollSource](ts-appendix-enums.md#scrollsource12) | 是 | 当前滚动操作的来源。 |

**返回值：** 

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| void \| [OffsetResult](#offsetresult11对象说明) |  返回OffsetResult时按照开发者指定的偏移量滚动；不返回时按回调参数(xOffset，yOffset)滚动。 |

## OnScrollEdgeCallback<sup>18+</sup>

type OnScrollEdgeCallback = (side: Edge) => void

滚动到边缘时触发的回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名  | 类型   | 必填 | 说明    |
| ------- | ----- | ---- | ------ |
| side    | [Edge](ts-appendix-enums.md#edge)  | 是   | 滚动到的边缘位置。 |

## OnScrollFrameBeginCallback<sup>18+</sup>

type OnScrollFrameBeginCallback = (offset: number, state: ScrollState) => OnScrollFrameBeginHandlerResult;

Scroll每帧滚动前触发的回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                    | 必填 | 说明                       |
| ------ | ------------------------------------------------------- | ---- | -------------------------- |
| offset | number                                                  | 是   | 即将发生的滑动量，单位vp。 |
| state  | [ScrollState](ts-container-list.md#scrollstate枚举说明) | 是   | 当前滑动状态。             |

**返回值：** 

| 类型                     | 说明                 |
| ------------------------ | -------------------- |
| [OnScrollFrameBeginHandlerResult](#onscrollframebeginhandlerresult18对象说明) | 返回实际滑动量。 |

## OnScrollFrameBeginHandlerResult<sup>18+</sup>对象说明

[OnScrollFrameBeginCallback](#onscrollframebegincallback18)返回的实际滚动偏移量。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型  | 必填 | 说明  |
| ----- | ------ | ---- | ----- |
| offsetRemain<sup>9+</sup>     | number | 是   | 实际滚动偏移量。<br/>单位vp。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |

## Scroller

可滚动容器组件的控制器，可以将此组件绑定至容器组件，然后通过它控制容器组件的滚动。同一个控制器不可以控制多个容器组件，目前支持绑定到ArcList、ArcScrollBar、List、Scroll、ScrollBar、Grid、WaterFlow上。

>**说明：**
>
>1、Scroller控制器与滚动容器组件的绑定发生在组件创建阶段。<br/>
>2、Scroller控制器与滚动容器组件绑定后才可以正常调用Scroller方法，否则根据调用接口不同会不生效或者抛异常。<br/>
>3、以[aboutToAppear](ts-custom-component-lifecycle.md#abouttoappear)为例，aboutToAppear在创建自定义组件的新实例后，在执行其build()方法之前执行。因此如果滚动组件在自定义组件build内，在该自定义组件aboutToAppear执行时，内部滚动组件还没有创建，是不能正常调用上述Scroller方法的。<br/>
>4、以[onAppear](ts-universal-events-show-hide.md#onappear)为例，组件挂载显示后触发此回调。因此在滚动组件的onAppear回调执行时，滚动组件已经创建并已经和Scroller绑定成功，是可以正常调用Scroller方法的。

### 导入对象

```
scroller: Scroller = new Scroller();
```

### constructor

constructor()

Scroller的构造函数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### scrollTo

scrollTo(options: [ScrollOptions](#scrolloptions18对象说明))


滑动到指定位置。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名   | 类型 | 必填   | 说明      |
| ----- | ---- | ---- | --------- |
| options | [ScrollOptions](#scrolloptions18对象说明) | 是    | 滑动到指定位置的参数。 

### scrollEdge

scrollEdge(value: Edge, options?: ScrollEdgeOptions)

滚动到容器边缘，不区分滚动轴方向，Edge.Top和Edge.Start表现相同，Edge.Bottom和Edge.End表现相同。
Scroll组件默认有动画，Grid、List、WaterFlow组件默认无动画。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型 | 必填   | 说明      |
| ----- | ---- | ---- | --------- |
| value | [Edge](ts-appendix-enums.md#edge) | 是    | 滚动到的边缘位置。 <br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| options<sup>12+</sup>&nbsp; | [ScrollEdgeOptions](#scrolledgeoptions12对象说明) | 否    | 设置滚动到边缘位置的模式。 <br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

### fling<sup>12+</sup>

fling(velocity: number): void


滚动类组件根据传入的初始速度进行惯性滚动。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型 | 必填 | 说明                                                     |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| velocity | number   | 是   | 惯性滚动的初始速度值。单位：vp/s<br/>**说明：**<br/>velocity值设置为0，视为异常值，本次滚动不生效。如果值为正数，则向顶部滚动；如果值为负数，则向底部滚动。 <br/>取值范围：(-∞, +∞)|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)和[滚动类组件错误码](../errorcode-scroll.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100004   | Controller not bound to component.                               |

### scrollPage<sup>9+</sup>

scrollPage(value:   ScrollPageOptions)

滚动到下一页或者上一页。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                           | 必填 | 说明       |
| ------ | -------------------------------------------------- | ---- | -------------- |
| value  | [ScrollPageOptions](#scrollpageoptions14对象说明) | 是   | 设置翻页模式。 |

### scrollPage<sup>(deprecated)</sup>

scrollPage(value: { next: boolean, direction?: Axis })

滚动到下一页或者上一页。从API version 9开始，该接口不再维护，推荐使用[scrollPage<sup>9+</sup>](#scrollpage9)。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型    | 必填   | 说明                           |
| --------- | ------- | ---- | ------------------------------ |
| next      | boolean | 是    | 是否向下翻页。true表示向下翻页，false表示向上翻页。 |
| direction | [Axis](ts-appendix-enums.md#axis)    | 否    | 设置滚动方向为水平或竖直方向。               |

### currentOffset

currentOffset(): OffsetResult

获取当前的滚动偏移量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型  | 描述 |
| -------- | -------- |
|  [OffsetResult<sup>11+</sup>](#offsetresult11对象说明) | 返回当前的滚动偏移量。<br/>**说明：**<br/>当scroller控制器未绑定容器组件或者容器组件被异常释放时，currentOffset的返回值为空。|

### scrollToIndex

scrollToIndex(value: number, smooth?: boolean, align?: ScrollAlign, options?: ScrollToIndexOptions)

滑动到指定Index，支持设置滑动额外偏移量。

开启smooth动效时，会对经过的所有item进行加载和布局计算，当大量加载item时会导致性能问题，建议先调用scrollToIndex不带动画跳转到目标附近位置，再调用scrollToIndex带动画滚动到目标位置。


>  **说明：**
>
>  仅支持ArcList、Grid、List、WaterFlow组件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                | 类型 | 必填 | 说明                                                     |
| --------------------- | -------- | ---- | ------------------------------------------------------------ |
| value | number   | 是   | 要滑动到的目标元素在当前容器中的索引值。      <br/>**说明：** <br/>value值设置成负值或者大于当前容器子组件的最大索引值，视为异常值，本次跳转不生效。                     |
| smooth | boolean  | 否   | 设置滑动到列表项在列表中的索引值时是否有动效，true表示有动效，false表示没有动效。<br/>默认值：false。|
| align | [ScrollAlign](#scrollalign10枚举说明)  | 否   | 指定滑动到的元素与当前容器的对齐方式。<br/>List中的默认值为：ScrollAlign.START。Grid中默认值为：ScrollAlign.AUTO。WaterFlow中的默认值为：ScrollAlign.START。<br/>**说明：** <br/>仅List、Grid、WaterFlow组件支持该参数。 |
| options<sup>12+</sup> | [ScrollToIndexOptions](#scrolltoindexoptions12对象说明)  | 否   | 设置滑动到指定Index的选项，如额外偏移量。<br/>默认值：0，单位：vp。 |

### scrollBy<sup>9+</sup>

scrollBy(dx: Length, dy: Length)


滑动指定距离。


>  **说明：**
>
>  支持ArcList、Scroll、List、Grid、WaterFlow组件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填   | 说明              |
| ----- | ------ | ---- | ----------------- |
| dx |  [Length](ts-types.md#length) | 是    | 水平方向滚动距离，不支持百分比形式。 <br/>取值范围：(-∞, +∞) |
| dy |  [Length](ts-types.md#length) | 是    | 竖直方向滚动距离，不支持百分比形式。 <br/>取值范围：(-∞, +∞) |

### isAtEnd<sup>10+</sup>

isAtEnd(): boolean

查询组件是否滚动到底部。

>  **说明：**
>
>  支持ArcList、Scroll、List、Grid、WaterFlow组件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值**

| 类型         | 描述          |
| ------- | -------- |
| boolean | true表示组件已经滚动到底部，false表示组件还没滚动到底部。 |

### getItemRect<sup>11+</sup>

getItemRect(index: number): RectResult

获取子组件的大小及相对容器组件的位置。

>  **说明：**
>
>  支持ArcList、Scroll、List、Grid、WaterFlow组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填   | 说明              |
| ----- | ------ | ---- | ----------------- |
| index | number | 是    | 子组件的索引值。 |

> **说明：**
>
> - index必须是当前显示区域显示的子组件的索引值，否则视为非法值。
> - 非法值返回的大小和位置均为0。

**返回值：**

| 类型       | 说明       |
| -------------------  | -------- |
| [RectResult](ts-types.md#rectresult10) | 子组件的大小和相对于组件的位置。<br/>单位：vp。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)和[滚动类组件错误码](../errorcode-scroll.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100004   | Controller not bound to component.                               |
### getItemIndex<sup>14+</sup>

getItemIndex(x: number, y: number): number

通过坐标获取子组件的索引。

>  **说明：**
>
>  支持List、Grid、WaterFlow组件。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填   | 说明              |
| ----- | ------ | ---- | ----------------- |
| x | number | 是    | x轴坐标，单位为vp。 |
| y | number | 是 | y轴坐标，单位为vp。 |

> **说明：**
>
> 非法值返回的索引为-1。

**返回值：**

| 类型       | 说明       |
| -------------------  | -------- |
| number | 返回子组件的索引。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)和[滚动类组件错误码](../errorcode-scroll.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100004   |The controller not bound to component.                              |

## OffsetResult<sup>11+</sup>对象说明

滑动偏移量对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型   | 只读 | 可选 | 说明                             |
| ------- |------- | ---- | ---- | -------------------------------- |
| xOffset | number |  否  |  否  | 水平滑动偏移。<br/>返回值单位为vp。 |
| yOffset | number |  否  |  否  | 竖直滑动偏移。<br/>返回值单位为vp。 |

## ScrollAnimationOptions<sup>12+</sup>对象说明

自定义滚动动效的参数选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型   | 必填   | 说明              |
| ----- | ------ | ------ | ----------------- |
| duration | number | 否 | 设置滚动时长。<br/>默认值：1000<br/>**说明：** <br/>设置为小于0的值时，按默认值显示。 |
| curve | [Curve](ts-appendix-enums.md#curve) \| [ICurve](../js-apis-curve.md#icurve9) | 否 | 设置滚动曲线。<br/>默认值：Curve.Ease |
| canOverScroll | boolean | 否 | 设置滚动动画滚动到边界后，是否转换成越界回弹动画。<br/>默认值：false<br/>**说明：** <br/> 仅在设置为true，且组件的edgeEffect设置为[EdgeEffect.Spring](ts-appendix-enums.md#edgeeffect)时，使用动画滚动到边界会转换为越界回弹动画，设置为false时，滚动到边界会直接停止动画，不会转换为越界回弹动画。 <br>从API version 20开始，如果[ScrollOptions](#scrolloptions18对象说明)中的canOverScroll设置为true，表示滚动可以停留在过界位置，滚动动画过界后不会转换为回弹动画。|

## ScrollAlign<sup>10+</sup>枚举说明

对齐方式枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 说明                           |
| ------ | ------------------------------ |
| START   | 首部对齐。指定item首部与List首部对齐。  |
| CENTER | 居中对齐。指定item主轴方向居中对齐于List。        |
| END  | 尾部对齐。指定item尾部与List尾部对齐。 |
| AUTO  | 自动对齐。<br/>若指定item完全处于显示区，不做调整。否则依照滑动距离最短的原则，将指定item首部对齐或尾部对齐于List，使指定item完全处于显示区。|

## ScrollToIndexOptions<sup>12+</sup>对象说明

滑动到指定Index的参数选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型  | 必填 | 说明              |
| ----- | ------ | ------ | ----------------- |
| extraOffset | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 滑动到指定Index的额外偏移量。 |

## ScrollPageOptions<sup>14+</sup>对象说明

翻页模式的参数选项。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型 | 必填 | 说明                                                     |
| --------- | -------- | ---- | ------------------------------------------------------------ |
| next      | boolean  | 是   | 是否向下翻页。true表示向下翻页，false表示向上翻页。          |
| animation | boolean  | 否   | 是否开启翻页动画效果。true有动画，false无动画。<br />默认值：false。 |

## OffsetOptions<sup>12+</sup>对象说明

初始滚动偏移量的参数选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型  | 必填 | 说明              |
| ----- | ------| ------- | ----------------- |
| xOffset | [Dimension](ts-types.md#dimension10) | 否 |水平滚动偏移。<br/>默认值：0 |
| yOffset | [Dimension](ts-types.md#dimension10) | 否 |垂直滚动偏移。<br/>默认值：0|

## ScrollEdgeOptions<sup>12+</sup>对象说明

滚动到边缘位置的参数选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型 | 必填 | 说明                                                   |
| --------- | -------- | ---- | ------------------------------------------------------------ |
| velocity      | number  | 否   | 设置滚动到容器边缘的固定速度。如果设置小于等于0的值，参数不生效。<br/>默认值：0<br/>  单位： vp/s          |

## ScrollOptions<sup>18+</sup>对象说明

滚动到指定位置的参数选项。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                                                     | 必填 | 说明                                                     |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| xOffset<sup>10+</sup>   | number&nbsp;\|&nbsp;string                                   | 是   | 水平滚动偏移。<br/>**说明：** <br/>该参数值不支持设置百分比。<br/>仅滚动轴为x轴时生效。<br/>取值范围：当值小于0时，不带动画的滚动，按0处理。带动画的滚动，默认滚动到起始位置后停止，可通过设置animation参数，使滚动在越界时启动回弹动画。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| yOffset<sup>10+</sup>   | number&nbsp;\|&nbsp;string                                   | 是   | 垂直滚动偏移。<br/>**说明：** <br/>该参数值不支持设置百分比。<br/>仅滚动轴为y轴时生效。<br/>取值范围：当值小于0时，不带动画的滚动，按0处理。带动画的滚动，默认滚动到起始位置后停止，可通过设置animation参数，使滚动在越界时启动回弹动画。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| animation<sup>10+</sup> | [ScrollAnimationOptions](#scrollanimationoptions12对象说明)&nbsp;\|&nbsp;boolean | 否   | 动画配置。<br/>- ScrollAnimationOptions:&nbsp; 自定义滚动动效。 <br/>- boolean:&nbsp;使能默认弹簧动效。<br/>默认值：<br/>ScrollAnimationOptions: { duration: 1000, curve: Curve.Ease, canOverScroll: false } <br/>boolean:&nbsp;false<br/>**说明：** <br/>当前List、Scroll、Grid、WaterFlow均支持boolean类型和ICurve曲线。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| canOverScroll<sup>20+</sup>   | boolean                                   | 否   | 滚动目标位置是否可以超出边界停留。<br/>设置为true时滚动可以在过界后停留，设置为false时滚动无法在过界后停留。<br/>默认值：false <br/>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|

## UIScrollEvent<sup>19+</sup>
frameNode中[getEvent('Scroll')](../js-apis-arkui-frameNode.md#geteventscroll19)方法的返回值，可用于给Scroll节点设置滚动事件。

UIScrollEvent继承于[UIScrollableCommonEvent](./ts-container-scrollable-common.md#uiscrollablecommonevent19)。

### setOnWillScroll<sup>19+</sup>

setOnWillScroll(callback:  ScrollOnWillScrollCallback | undefined): void

设置[onWillScroll](#onwillscroll12)事件的回调。

方法入参为undefined时，会重置事件回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [ScrollOnWillScrollCallback](./ts-container-scroll.md#scrollonwillscrollcallback12)&nbsp;\|&nbsp;undefined | 是   | onWillScroll事件的回调函数。 |

### setOnDidScroll<sup>19+</sup>

setOnDidScroll(callback: ScrollOnScrollCallback | undefined): void

设置[onDidScroll](#ondidscroll12)事件的回调。

方法入参为undefined时，会重置事件回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| callback  | [ScrollOnScrollCallback](./ts-container-scroll.md#scrollonscrollcallback12)&nbsp;\|&nbsp;undefined | 是   | onDidScroll事件的回调函数。 |

## 示例
### 示例1（设置scroller控制器）
该示例展示了Scroll组件部分属性和scroller控制器的使用。

```ts
// xxx.ets
import { curves } from '@kit.ArkUI';

@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: string) => item)
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)
      .onWillScroll((xOffset: number, yOffset: number, scrollState: ScrollState) => {
        console.info(xOffset + ' ' + yOffset);
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge');
      })
      .onScrollStop(() => {
        console.info('Scroll Stop');
      })

      Button('scroll 150')
        .height('5%')
        .onClick(() => { // 点击后下滑指定距离150.0vp
          this.scroller.scrollBy(0, 150);
        })
        .margin({ top: 10, left: 20 })
      Button('scroll 100')
        .height('5%')
        .onClick(() => { // 点击后滑动到指定位置，即下滑100.0vp的距离
          const yOffset: number = this.scroller.currentOffset().yOffset;
          this.scroller.scrollTo({ xOffset: 0, yOffset: yOffset + 100 });
        })
        .margin({ top: 60, left: 20 })
      Button('scroll 100')
        .height('5%')
        .onClick(() => { // 点击后滑动到指定位置，即下滑100.0vp的距离，滑动过程配置有动画
          let curve = curves.interpolatingSpring(10, 1, 228, 30); //创建一个阶梯曲线
          const yOffset: number = this.scroller.currentOffset().yOffset;
          this.scroller.scrollTo({ xOffset: 0, yOffset: yOffset + 100, animation: { duration: 1000, curve: curve } });
        })
        .margin({ top: 110, left: 20 })
      Button('back top')
        .height('5%')
        .onClick(() => { // 点击后回到顶部
          this.scroller.scrollEdge(Edge.Top);
        })
        .margin({ top: 160, left: 20 })
      Button('next page')
        .height('5%')
        .onClick(() => { // 点击后滑到下一页
          this.scroller.scrollPage({ next: true ,animation: true });
        })
        .margin({ top: 210, left: 20 })
      Button('fling -3000')
        .height('5%')
        .onClick(() => { // 点击后触发初始速度为-3000vp/s的惯性滚动
          this.scroller.fling(-3000);
        })
        .margin({ top: 260, left: 20 })
      Button('scroll to bottom 700')
        .height('5%')
        .onClick(() => { // 点击后滑到下边缘，速度值是700vp/s
          this.scroller.scrollEdge(Edge.Bottom, { velocity: 700 });
        })
        .margin({ top: 310, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![zh-cn_image_0000001174104386](figures/scroll_scroller.gif)

### 示例2（嵌套滚动实现方式一）
该示例使用onScrollFrameBegin事件实现了内层List组件和外层Scroll组件的嵌套滚动。
```ts
import { LengthMetrics } from '@kit.ArkUI';

@Entry
@Component
struct NestedScroll {
  @State listPosition: number = 0; // 0代表滚动到List顶部，1代表中间值，2代表滚动到List底部。
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  private scrollerForScroll: Scroller = new Scroller();
  private scrollerForList: Scroller = new Scroller();

  build() {
    Flex() {
      Scroll(this.scrollerForScroll) {
        Column() {
          Text("Scroll Area")
            .width("100%")
            .height("40%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)
            .onClick(() => {
              this.scrollerForList.scrollToIndex(5, false, ScrollAlign.START, { extraOffset: LengthMetrics.vp(5) });
            })

          List({ space: 20, scroller: this.scrollerForList }) {
            ForEach(this.arr, (item: number) => {
              ListItem() {
                Text("ListItem" + item)
                  .width("100%")
                  .height("100%")
                  .borderRadius(15)
                  .fontSize(16)
                  .textAlign(TextAlign.Center)
                  .backgroundColor(Color.White)
              }.width("100%").height(100)
            }, (item: string) => item)
          }
          .width("100%")
          .height("50%")
          .edgeEffect(EdgeEffect.None)
          .friction(0.6)
          .onReachStart(() => {
            this.listPosition = 0;
          })
          .onReachEnd(() => {
            this.listPosition = 2;
          })
          .onScrollFrameBegin((offset: number) => {
            if ((this.listPosition == 0 && offset <= 0) || (this.listPosition == 2 && offset >= 0)) {
              this.scrollerForScroll.scrollBy(0, offset);
              return { offsetRemain: 0 };
            }
            this.listPosition = 1;
            return { offsetRemain: offset };
          })

          Text("Scroll Area")
            .width("100%")
            .height("40%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)
        }
      }
      .width("100%").height("100%")
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding(20)
  }
}
```

![NestedScroll](figures/NestedScroll.gif)

### 示例3（嵌套滚动实现方式二）
该示例使用nestedScroll属性实现了内层List组件和外层Scroll组件的嵌套滚动。
```ts
@Entry
@Component
struct StickyNestedScroll {
  @State arr: number[] = [];

  @Styles
  listCard() {
    .backgroundColor(Color.White)
    .height(72)
    .width("100%")
    .borderRadius(12)
  }

  build() {
    Scroll() {
      Column() {
        Text("Scroll Area")
          .width("100%")
          .height("40%")
          .backgroundColor('#0080DC')
          .textAlign(TextAlign.Center)
        Tabs({ barPosition: BarPosition.Start }) {
          TabContent() {
            List({ space: 10 }) {
              ForEach(this.arr, (item: number) => {
                ListItem() {
                  Text("item" + item)
                    .fontSize(16)
                }.listCard()
              }, (item: string) => item)
            }.width("100%")
            .edgeEffect(EdgeEffect.Spring)
            .nestedScroll({
              scrollForward: NestedScrollMode.PARENT_FIRST,
              scrollBackward: NestedScrollMode.SELF_FIRST
            })
          }.tabBar("Tab1")

          TabContent() {
          }.tabBar("Tab2")
        }
        .vertical(false)
        .height("100%")
      }.width("100%")
    }
    .edgeEffect(EdgeEffect.Spring)
    .friction(0.6)
    .backgroundColor('#DCDCDC')
    .scrollBar(BarState.Off)
    .width('100%')
    .height('100%')
  }

  aboutToAppear() {
    for (let i = 0; i < 30; i++) {
      this.arr.push(i);
    }
  }
}
```
![NestedScroll2](figures/NestedScroll2.gif)
### 示例4（嵌套滚动父组件向子组件传递滚动）
该示例使用enableScrollInteraction属性和onScrollFrameBegin事件实现了父组件向子组件传递滚动。
```ts
@Entry
@Component
struct NestedScroll {
  private headerHeight: number = 0;
  private arr: number[] = [];
  private scrollerForParent: Scroller = new Scroller();
  private scrollerForChild: Scroller = new Scroller();

  aboutToAppear(): void {
    for (let i = 0; i < 10; i++) {
      this.arr.push(i);
    }
  }

  build() {
    Scroll(this.scrollerForParent) {
      Column() {
        Text("Scroll Area")
          .width("100%")
          .height("40%")
          .backgroundColor(0X330000FF)
          .fontSize(16)
          .textAlign(TextAlign.Center)
          .onClick(() => {
            this.scrollerForChild.scrollToIndex(5);
          })
          .onSizeChange((oldValue: SizeOptions, newValue: SizeOptions) => {
            this.headerHeight = newValue.height! as number;
          })
        List({ space: 20, scroller: this.scrollerForChild }) {
          ForEach(this.arr, (item: number) => {
            ListItem() {
              Text("ListItem" + item)
                .width("100%")
                .height("100%")
                .borderRadius(15)
                .fontSize(16)
                .textAlign(TextAlign.Center)
                .backgroundColor(Color.White)
            }.width("100%").height(100)
          }, (item: string) => item)
        }
        .width("100%")
        .height("100%")
        .edgeEffect(EdgeEffect.None)
        .scrollBar(BarState.Off)
        .enableScrollInteraction(false)

        Text("Scroll Area")
          .width("100%")
          .height("40%")
          .backgroundColor(0X330000FF)
          .fontSize(16)
          .textAlign(TextAlign.Center)
      }
    }
    .scrollBar(BarState.Off)
    .edgeEffect(EdgeEffect.Spring)
    .onScrollFrameBegin((offset: number, state: ScrollState) => {
      let retOffset = offset;
      let currOffset = this.scrollerForParent.currentOffset().yOffset;
      let newOffset = currOffset + offset;
      if (offset > 0) {
        if (this.scrollerForChild.isAtEnd()) {
          return { offsetRemain: offset };
        }
        if (newOffset > this.headerHeight) {
          retOffset = this.headerHeight - currOffset;
        }
        this.scrollerForChild.scrollBy(0, offset - retOffset);
      } else {
        if (this.scrollerForChild.currentOffset().yOffset <= 0) {
          return { offsetRemain: offset };
        }
        if (newOffset < this.headerHeight) {
          retOffset = this.headerHeight - currOffset;
        }
        this.scrollerForChild.scrollBy(0, offset - retOffset);
      }
      return { offsetRemain: retOffset };
    })
    .width("100%")
    .height("100%")
    .backgroundColor(0xDCDCDC)
  }
}
```
![NestedScroll3](figures/NestedScroll3.gif)
### 示例5（设置限位滚动）
该示例实现了Scroll组件的限位滚动。
```ts
@Entry
@Component
struct Index {
  scroller: Scroller = new Scroller;
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];
  build() {
    Scroll(this.scroller) {
      Column() {
        ForEach(this.arr, (item: number) => {
          Text(item.toString())
            .width('90%')
            .height(200)
            .backgroundColor(0xFFFFFF)
            .borderWidth(1)
            .borderColor(Color.Black)
            .borderRadius(15)
            .fontSize(16)
            .textAlign(TextAlign.Center)
        }, (item: string) => item)
      }.width('100%').backgroundColor(0xDCDCDC)
    }
    .backgroundColor(Color.Yellow)
    .height('100%')
    .edgeEffect(EdgeEffect.Spring)
    .scrollSnap({snapAlign:ScrollSnapAlign.START, snapPagination:400, enableSnapToStart:true, enableSnapToEnd:true})
  }
}
```
![NestedScrollSnap](figures/NestedScrollSnap.gif)

### 示例6（获取子组件索引）
该示例展示了如何获得List组件的子组件索引。

```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [];
  private scroller: ListScroller = new ListScroller();
  @State listSpace: number = 10;
  @State listChildrenSize: ChildrenMainSize = new ChildrenMainSize(100);
  @State listIndex: number = -1;
  @State mess:string = "null";
  @State itemBackgroundColorArr: boolean[] = [false];
  aboutToAppear(){
    // 初始化数据源。
    for (let i = 0; i < 10; i++) {
      this.arr.push(i);
    }
    this.listChildrenSize.splice(0, 5, [100, 100, 100, 100, 100]);
  }
  build() {
    Column() {
      List({ space: this.listSpace, initialIndex: 4, scroller: this.scroller }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text('item-' + item)
              .height( item < 5 ? 100 : this.listChildrenSize.childDefaultSize)
              .width('90%')
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor( this.itemBackgroundColorArr[item] ? 0x68B4FF: 0xFFFFFF)
          }
        }, (item: string) => item)
      }
      .backgroundColor(Color.Gray)
      .layoutWeight(1)
      .scrollBar(BarState.On)
      .childrenMainSize(this.listChildrenSize)
      .alignListItem(ListItemAlign.Center)
      .gesture(
        PanGesture()
          .onActionUpdate((event: GestureEvent) => {
            if (event.fingerList[0] != undefined && event.fingerList[0].localX != undefined && event.fingerList[0].localY != undefined) {
              this.listIndex = this.scroller.getItemIndex(event.fingerList[0].localX, event.fingerList[0].localY);
              this.itemBackgroundColorArr[this.listIndex] = true;
            }
          })
      )
      .gesture(
        TapGesture({ count: 1 })
          .onAction((event: GestureEvent) => {
            if (event) {
              this.itemBackgroundColorArr.splice(0,this.itemBackgroundColorArr.length);
            }
          })
      )

      Text('您当前位置Item索引为：'+ this.listIndex)
        .fontColor(Color.Red)
        .height(50)
    }
  }
}
```

![ScrollEdgeAtVelocity](figures/getItemIndex_list.gif)

### 示例7（设置边缘渐隐）
该示例实现了Scroll组件开启边缘渐隐效果并设置边缘渐隐长度。

```ts
// xxx.ets
import { LengthMetrics } from '@kit.ArkUI';
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: string) => item)
        }.width('100%')
      }
      .fadingEdge(true,{fadingEdgeLength:LengthMetrics.vp(80)})



    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![fadingEdge_scroll](figures/fadingEdge_scroll.gif)

### 示例8（单边边缘效果）

该示例通过edgeEffect接口，实现了Scroll组件设置单边边缘效果。

```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: string) => item)
        }.width('100%')
      }
      .edgeEffect(EdgeEffect.Spring,{alwaysEnabled:true,effectEdge:EffectEdge.START})
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![edgeEffect_scroll](figures/edgeEffect_scroll.gif)
# ArcList

弧形列表包含一系列列表项。适合连续、多行呈现同类数据，例如图片和文本。

> **说明：**
>
> - 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>


## 子组件

仅支持[ArcListItem](ts-container-arclistitem.md)子组件。

> **说明：**
>
> ArcList的子组件的索引值计算规则：
>
> 按子组件的顺序依次递增。
>
> if/else语句中，只有条件成立的分支内的子组件会参与索引值计算，条件不成立的分支内子组件不计算索引值。
>
> ForEach/LazyForEach语句中，会计算展开所有子节点索引值。
>
> [if/else](../../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)发生变化以后，会更新子节点索引值。
>
> ArcList子组件visibility属性设置为Hidden或None依然会计算索引值。
>
> ArcList子组件的visibility属性设置为None时不显示，但该子组件上下的space还会生效。


## 接口

ArcList(options?: ArkListOptions)

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 参数类型                                  | 必填 | 参数描述                                                     |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ArkListOptions](#ArkListOptions对象说明) | 否   | 为ArcList提供可选参数, 该对象内含有initialIndex、scroller、header等参数 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### digitalCrownSensitivity

digitalCrownSensitivity(sensitivity: Optional\<CrownSensitivity>)

设置表冠响应事件灵敏度。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名      | 类型                             | 必填 | 说明                                                         |
| ----------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| sensitivity | Optional&lt;CrownSensitivity&gt; | 否   | 表冠响应灵敏度。<br/>默认值：CrownSensitivity.MEDIUM，响应速度适中<br/>其他支持值：<br/>CrownSensitivity.LOW，响应速度较慢<br/>CrownSensitivity.HIGH，响应速度较快 |

### space

space(space: Optional\<LengthMetrics>))

设置列表子项之间的距离。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                       | 必填 | 说明                           |
| ------ | ---------------------------------------------------------- | ---- | ------------------------------ |
| space  | [Optional&lt;LengthMetrics&gt;](ts-types.md#LengthMetrics) | 否   | 子项之间的间距。<br/>默认值：0 |

### scrollBar

status: Optional\<BarState>

设置滚动条状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                   |
| ------ | ---------------------------------------------------- | ---- | -------------------------------------- |
| status | [Optional\<BarState>](ts-appendix-enums.md#barstate) | 否   | 滚动条状态。<br/>默认值：BarState.Auto |

### cachedCount

count: Optional\<number>

设置列表中ArcArcListItem的预加载数量，只在[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)中生效。

在ArcList显示的ArcArcListItem前后各缓存cachedCount个ArcArcListItem。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型              | 必填 | 说明                                       |
| ------ | ----------------- | ---- | ------------------------------------------ |
| value  | Optional\<number> | 否   | ArcArcListItem的预加载数量。<br/>默认值：1 |

### chainAnimation

chainAnimation(enable: Optional\<boolean>)

设置当前ArcList是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。

链式联动效果：ArcList内的arclist-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。

链式动效生效需要满足以下前提条件：

 1、ArcList边缘效果为Spring类型。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型               | 必填 | 说明                                                         |
| ------ | ------------------ | ---- | ------------------------------------------------------------ |
| enable | Optional\<boolean> | 否   | 是否启用链式联动动效。<br/>默认值：false，不启用链式联动。true，启用链式联动。 |

### enableScrollInteraction

enableScrollInteraction(enable: Optional\<boolean>)

设置是否支持滚动手势，当设置为false时，无法通过手指或者鼠标滚动，但不影响控制器的滚动接口。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型               | 必填 | 说明                                |
| ------ | ------------------ | ---- | ----------------------------------- |
| enable | Optional\<boolean> | 否   | 是否支持滚动手势。<br/>默认值：true |

### friction

friction(friction: Optional\<number>)

设置摩擦系数，手动划动滚动区域时生效，只对惯性滚动过程有影响，对惯性滚动过程中的链式效果有间接影响。设置为小于等于0的值时，按默认值处理。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名   | 类型              | 必填 | 说明                         |
| -------- | ----------------- | ---- | ---------------------------- |
| friction | Optional\<number> | 否   | 摩擦系数。<br/>默认值：0.8。 |

### scrollBarWidth

scrollBarWidth(width: Optional\<LengthMetrics>)

设置滚动条的宽度，不支持百分比设置。宽度设置后，滚动条正常状态和按压状态宽度均为滚动条的宽度值。如果滚动条的宽度超过ArcList组件主轴方向的高度，则滚动条的宽度会变为默认值。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                       | 必填 | 说明                                      |
| ------ | ---------------------------------------------------------- | ---- | ----------------------------------------- |
| width  | [Optional&lt;LengthMetrics&gt;](ts-types.md#LengthMetrics) | 否   | 滚动条的宽度。<br/>默认值：4<br/>单位：vp |

### scrollBarColor

scrollBarColor(color: Optional\<ColorMetrics>)

设置滚动条的颜色。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                    | 必填 | 说明           |
| ------ | ----------------------- | ---- | -------------- |
| color  | Optional\<ColorMetrics> | 否   | 滚动条的颜色。 |

### flingSpeedLimit

flingSpeedLimit(speed: Optional\<number>)

限制跟手滑动结束后，Fling动效开始时的最大初始速度。单位是vp/s。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型              | 必填 | 说明                            |
| ------ | ----------------- | ---- | ------------------------------- |
| speed  | Optional\<number> | 否   | Fling动效开始时的最大初始速度。 |

### childrenMainSize

childrenMainSize(size: Optional\<ChildrenMainSize>)

设置ArcList组件的子组件在主轴方向的大小信息。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                     | 必填 | 说明                                                         |
| ------ | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| size   | [Optional\<ChildrenMainSize>](#ChildrenMainSize对象说明) | 否   | 1. 作用：<br/>通过ChildrenMainSize对象向ArcList组件准确提供所有子组件在主轴方向的大小信息，能够使ArcList组件在子组件的主轴大小不一致、增删子组件、使用[scrollToIndex](ts-container-scroll.md#scrolltoindex)等场景也能维护自己准确的滑动位置，进而使[scrollTo](ts-container-scroll.md#scrollto)能跳转到准确的指定位置，[currentOffset](ts-container-scroll.md#currentoffset)能够获取到当前准确的滑动位置，内置滚动条能够平滑移动无跳变。<br/>2.使用约束：<br/>（1）提供的主轴方向大小必须与子组件实际在主轴方向的大小一致，子组件在主轴方向大小变化或者增删子组件时都必须通过ChildrenMainSize对象方法通知ArcList组件。 |

## 事件

### onScrollIndex

onScrollIndex(handler: Optional\<ArcScrollIndexHandler>)

有子组件划入或划出ArcList显示区域时触发。

ArcList的边缘效果为弹簧效果时，在ArcList划动到边缘继续划动和松手回弹过程不会触发onScrollIndex事件。

触发该事件的条件：列表初始化时会触发一次，ArcList显示区域内第一个子组件的索引值或最后一个子组件的索引值有变化时会触发。

ArcList显示区域中间位置子组件变化时也会触发该事件。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                          |
| ------- | ------------------------------------------------------------ | ---- | --------------------------------------------- |
| handler | [Optional\<ArcScrollIndexHandler>](#ArcScrollIndexHandler对象说明) | 否   | 有子组件划入或划出ArcList显示区域时触发该回调 |

### onReachStart

onReachStart(handler: Optional\<VoidCallback>)

列表到达起始位置时触发。

ArcList初始化时如果initialIndex为0会触发一次，ArcList滚动到起始位置时触发一次。ArcList边缘效果为弹簧效果时，划动经过起始位置时触发一次，回弹回起始位置时再触发一次。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明                   |
| ------- | ------------------------------------------------ | ---- | ---------------------- |
| handler | [Optional\<VoidCallback>](#VoidCallback对象说明) | 否   | 列表到达起始位置时触发 |

### onReachEnd

onReachEnd(handler: Optional\<VoidCallback>)

列表到底末尾位置时触发。

ArcList边缘效果为弹簧效果时，划动经过末尾位置时触发一次，回弹回末尾位置时再触发一次。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明                   |
| ------- | ------------------------------------------------ | ---- | ---------------------- |
| handler | [Optional\<VoidCallback>](#VoidCallback对象说明) | 否   | 列表到底末尾位置时触发 |

### onScrollStart

onScrollStart(handler: Optional\<VoidCallback>)

列表滑动开始时触发。手指拖动列表或列表的滚动条触发的滑动开始时，会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画开始时会触发该事件

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明               |
| ------- | ------------------------------------------------ | ---- | ------------------ |
| handler | [Optional\<VoidCallback>](#VoidCallback对象说明) | 否   | 列表滑动开始时触发 |

### onScrollStop

onScrollStop(handler: Optional\<VoidCallback>)

列表滑动停止时触发。手拖动列表或列表的滚动条触发的滑动，手离开屏幕并且滑动停止时会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画停止会触发该事件。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明               |
| ------- | ------------------------------------------------ | ---- | ------------------ |
| handler | [Optional\<VoidCallback>](#VoidCallback对象说明) | 否   | 列表滑动停止时触发 |

### onWillScroll

onWillScroll(handler: Optional\<OnWillScrollCallback>)

列表滑动前触发。返回当前帧将要滑动的偏移量和当前滑动状态。返回的偏移量为计算得到的将要滑动的偏移量值，并非最终实际滑动偏移。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| handler | [Optional\<OnWillScrollCallback>](#OnWillScrollCallback对象说明) | 否 | 列表滑动时触发的回调。 |

> **说明：** 
> 
> 调用ScrollEdge和不带动画的ScrollToIndex时,不触发onWillScroll。

### onDidScroll
onDidScroll(handler: Optional\<OnScrollCallback>)

列表滑动时触发，返回当前帧滑动的偏移量和当前滑动状态。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| handler | [Optional\<OnScrollCallback>](#onscrollcallback对象说明) | 否 | 列表滑动时触发的回调。 |

## ArkListOptions对象说明

**参数：**

| 参数名       | 参数类型                                    | 必填 | 参数描述                                                     |
| ------------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| initialIndex | number                                      | 否   | 设置当前ArcList初次加载时视口起始位置显示的item的索引值。<br/>默认值：0<br/>**说明：** <br/>设置为负数或超过了当前ArcList最后一个item的索引值时视为无效取值，无效取值按默认值显示。 |
| scroller     | [Scroller](ts-container-scroll.md#scroller) | 否   | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/>**说明：** <br/>不允许和其他滚动类组件绑定同一个滚动控制对象。 |
| header       | ComponentContent                            | 否   | 支持标题设置。                                               |

## VoidCallback对象说明

该对象参数及返回值均为空

## ArcScrollIndexHandler对象说明

有子组件划入或划出ArcList显示区域时触发的回调

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| start  | number | 是   | ArcList显示区域内第一个子组件的索引值     |
| end    | number | 是   | ArcList显示区域内最后一个子组件的索引值。 |
| center | number | 是   | ArcList显示区域内中间位置子组件的索引值。 |

## OnScrollCallback对象说明

列表滑动时触发的回调  

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| scrollOffset | number | 是 | 每帧滚动的偏移量，ArcList的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>单位vp。 |
| scrollState | [ScrollState](ts-container-arclist.md#scrollstate枚举说明) | 是 | 当前滑动状态。 |

## ScrollState枚举说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 名称     |  枚举值  | 描述                                       |
| ------ | ------ | ---------------------------------------- |
| Idle   |  0  | 空闲状态。使用控制器提供的方法控制滚动时触发，拖动滚动条滚动时触发。<br/>**说明：** <br/> 从API version 10开始，调整为滚动状态回归空闲时触发， <br/>控制器提供的无动画方法控制滚动时触发。 |
| Scroll |  1  | 滚动状态。使用手指拖动ArcList滚动时触发。<br/>**说明：** <br/> 从API version 10开始，拖动滚动条滚动和滚动鼠标滚轮时也会触发。 |
| Fling  |  2  | 惯性滚动状态。快速划动松手后进行惯性滚动和划动到边缘回弹时触发。<br/>**说明：** <br/> 从API version 10开始，由动画控制的滚动都触发。包括快速划动松手后的惯性滚动， <br/>划动到边缘回弹的滚动，快速拖动内置滚动条松手后的惯性滚动， <br/>使用滚动控制器提供的带动画的方法控制的滚动。 |

ScrollState枚举变更如下。

| 场景            | API version 9及以下 | API version 10开始 |
| ------------- | ---------------- | ---------------- |
| 手指拖动滑动        | Scroll           | Scroll           |
| 惯性滚动          | Fling            | Fling            |
| 过界回弹          | Fling            | Fling            |
| 鼠标滚轮滚动        | Idle             | Scroll           |
| 拖动滚动条         | Idle             | Scroll           |
| 滚动控制器滚动（带动画）  | Idle             | Fling            |
| 滚动控制器滚动（不带动画） | Idle             | Idle             |

## ChildrenMainSize对象说明

维护ArcList组件的子组件在主轴方向的大小信息，仅支持一对一绑定到ArcList组件。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

### constructor

constructor(childDefaultSize: number): void

ChildrenMainSize有参构造函数。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 名称   | 类型                            | 必填   | 描述                   |
| ---- | ----------------------------- | ---- | -------------------- |
| childDefaultSize | number | 是    | 子组件在主轴方向的默认大小。<br/>单位：vp<br/>**说明：** <br/>必须是有限的非负数值，否则抛出异常。|


### childDefaultSize

set childDefaultSize(value: number): void

修改子组件在主轴方向的默认大小。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 名称   | 类型                            | 必填   | 描述                   |
| ---- | ----------------------------- | ---- | -------------------- |
| value | number | 是    | 子组件在主轴方向的默认大小。<br/>单位：vp<br/>**说明：** <br/>必须是有限的非负数值，否则抛出异常。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

get childDefaultSize(): number

获取子组件在主轴方向的默认大小。

**返回值：** 

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| number | 子组件在主轴方向的默认大小。<br/>单位：vp |

### splice

splice(start: number, deleteCount?: number, childrenSize?: Array\<number>): void

批量增删改子组件在主轴方向的大小信息。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 名称   | 类型                            | 必填   | 描述                   |
| ---- | ----------------------------- | ---- | -------------------- |
| start | number | 是    | 从0开始计算的索引值，表示要开始修改子组件在主轴方向大小信息的位置。<br/>**说明：** <br/>1. 必须是有限的非负数值，否则抛出异常。<br/>2. 非整数会被截断为整数。<br/>3. 超过最大索引值不生效。 |
| deleteCount | number | 否    | 从start开始删除的大小信息的数量。<br/>**说明：** <br/>1.  必须是有限的非负数值，否则处理为0。<br/>2. 非整数会被截断为整数。<br/>3. start + deleteCount - 1可以超过最大索引值，会删除索引值start开始之后的所有子组件的大小信息。 |
| childrenSize | Array\<number > | 否    | 要在start位置插入的所有子组件的主轴方向的大小。<br/>Array中各个数值单位：vp <br/>**说明：** <br/>1.数组中数值如果是有限的非负值，则认为是指定的大小，后续不随默认大小的变化而变化。<br/>2. 数组中数值如果不是有限的非负值，会被处理成默认大小，后续会随默认大小的变化而变化。  |


**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |


> **说明：**
>
> - 如果仅使用start参数，表示删除索引值start及之后的子组件的大小信息。
> - 如果仅使用start和deleteCount参数，表示删除索引值start开始的deleteCount数量的子组件的大小信息。一般在删除子组件时使用。
> - 如果使用3个参数，表示删除索引值start开始的deleteCount数量的子组件的大小信息，再在start位置插入childrenSize中所有的大小信息。一般在增加子组件或者批量更新子组件主轴方向大小的时候使用，如果仅是增加子组件，deleteCount为0，childrenSize的元素数量和增加子组件的个数应该相等；如果仅是批量更新子组件主轴方向的大小，childrenSize的元素数量应该和deleteCount相等，即为批量更新的数量。
> - 如果想要通知某个子组件的大小为默认大小，childrenSize中对应的值不应该给一个有限的非负值，而应该给NaN，任意负值等能被处理成默认大小的值。

### update

update(index: number, childSize: number): void

修改指定索引值对应的子组件的主轴方向的大小信息。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**参数：**

| 名称   | 类型                            | 必填   | 描述                   |
| ---- | ----------------------------- | ---- | -------------------- |
| start | number | 是    | 从0开始计算的索引值，表示要开始修改子组件在主轴方向大小信息的位置。<br/>**说明：** <br/>1. 必须是有限的非负数值，否则抛出异常。<br/>2. 非整数会被截断为整数。<br/>3. 超过最大索引值不生效。 |
| childSize | number | 是    | 要更新成的大小。<br/>单位：vp <br/>**说明：** <br/>1.数值如果是有限的非负值，则认为是指定的大小，后续不随默认大小的变化而变化。<br/>2. 数值如果不是有限的非负值，会被处理成默认大小，后续会随默认大小的变化而变化。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3. Parameter verification failed.   |

## 示例

### 示例1
该示例实现了设置纵向列表，并在当前显示界面发生改变时回调索引。
```ts
// xxx.ets
import { LengthMetrics } from "@ohos.arkui.node";
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@ohos.arkui.ArcList';
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      ArcList({ initialIndex: 0 }) {
        ForEach(this.arr, (item: number) => {
          ArcListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }
      .space(LengthMetrics.px(20))
      .scrollBar(BarState.Off)
      .friction(0.6)
      .onScrollIndex((firstIndex: number, lastIndex: number, centerIndex: number) => {
        console.info('first' + firstIndex)
        console.info('last' + lastIndex)
        console.info('center' + centerIndex)
      })
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        console.info(`onScroll scrollState = ScrollState` + scrollState + `, scrollOffset = ` + scrollOffset)
      })
      .width('90%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }
}
```

### 示例2

该示例增加了ArcList支持标题栏设置的效果。

```ts
// xxx.ets
import { ComponentContent, LengthMetrics } from "@ohos.arkui.node";
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@ohos.arkui.ArcList';
@Builder
function buildText() {
  Stack() {
    Text("header")
      .fontSize(80)
      .padding(0)
      .backgroundColor(0xF9CF93)
      .border({ width: '1px', color: Color.Black })
  }
  .alignContent(Alignment.Bottom)
}
@Entry
@Component
struct ListExample {
  private arr: number[] = []
  private scrollerForList: Scroller = new Scroller()

  private context: UIContext = this.getUIContext()
  private header: ComponentContent<Object> = new ComponentContent(this.context, wrapBuilder(buildText));

  aboutToAppear() {
    for (let i = 0; i < 20; i++) {
      this.arr.push(i)
    }
  }
  build() {
    Column() {
      Row() {
        ArcList({ initialIndex: 3, scroller: this.scrollerForList, header: this.header }) {
          ForEach(this.arr, (item: number) => {
            ArcListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center)
            }
            .borderRadius(10).backgroundColor(0xFFFFFF)
            .width('60%')
            .height('80%')
          }, (item: number) => JSON.stringify(item))
        }
        .space(LengthMetrics.px(20))
        .chainAnimation(true)
        .height('100%')
        .width('100%')
        .borderRadius(10)
        .backgroundColor(0xDCDCDC)
      }
      .width('100%')
      .height('100%')
      .backgroundColor(0xDCDCDC)
      .padding({ top: 10 })
    }
  }
}
```

### 示例3
该示例通过设置childrenMainSize属性，实现了ArcList在子组件高度不一致时调用scrollTo接口也可以跳转准确。
```ts
// xxx.ets
import { LengthMetrics } from "@ohos.arkui.node";
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@ohos.arkui.ArcList';
@Entry
@Component
struct ListExample {
  private arr: number[] = []
  private scroller: ListScroller = new ListScroller()
  @State listSpace: number = 10
  @State listChildrenSize: ChildrenMainSize = new ChildrenMainSize(100)
  aboutToAppear(){
    // 初始化数据源。
    for (let i = 0; i < 10; i++) {
      this.arr.push(i)
    }
    // 前5个item的主轴大小不是默认大小100，因此需要通过ChildrenMainSize通知ArcList。
    this.listChildrenSize.splice(0, 5, [300, 300, 300, 300, 300])
  }
  build() {
    Column() {
      ArcList({ initialIndex: 4, scroller: this.scroller }) {
        ForEach(this.arr, (item: number) => {
          ArcListItem() {
            Text('item-' + item)
              .height( item < 5 ? 300 : this.listChildrenSize.childDefaultSize)
              .width('90%')
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }
      .space(LengthMetrics.px(this.listSpace))
      .backgroundColor(Color.Gray)
      .layoutWeight(1)
      .scrollBar(BarState.On)
      .childrenMainSize(this.listChildrenSize)
      Row(){
        Button() { Text('item size + 50') }.onClick(()=>{
          this.listChildrenSize.childDefaultSize += 50
        }).height('50%').width('30%')
        Button() { Text('item size - 50') }.onClick(()=>{
          if (this.listChildrenSize.childDefaultSize === 0) {
            return
          }
          this.listChildrenSize.childDefaultSize -= 50
        }).height('50%').width('30%')
        Button() { Text('scrollTo (0, 310)') }.onClick(()=>{
          // 310: 跳转到item 1顶部与ArcList顶部平齐的位置。
          // 如果不设置childrenMainSize，item高度不一致时scrollTo会不准确。
          this.scroller.scrollTo({xOffset: 0, yOffset: 310})
        }).height('50%').width('30%')
      }.height('20%')
    }
  }
}
```

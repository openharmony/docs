# ArcList

弧形列表包含一系列列表项。适合连续、多行呈现同类数据，例如图片和文本。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>

## 导入模块

```ts
import { ArcList, ArcListAttribute } from '@kit.ArkUI';
```

## 子组件

仅支持[ArcListItem](ts-container-arclistitem.md)子组件。

> **说明：**
>
> ArcList的子组件的索引值计算规则：
>
> - 按子组件的顺序依次递增。  
>
> - if/else语句中，只有条件成立的分支内的子组件会参与索引值计算，条件不成立的分支内子组件不计算索引值。  
>
> - ForEach/LazyForEach语句中，会计算展开所有子节点索引值。  
>
> - [if/else](../../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)发生变化以后，会更新子节点索引值。  
>
> - ArcList子组件visibility属性设置为Hidden或None依然会计算索引值。  
>
> - ArcList子组件的visibility属性设置为None时不显示，但该子组件上下的space还会生效。  


## 接口

ArcList(options?: ArkListOptions)

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 参数类型                                  | 必填 | 参数描述                                                     |
| ------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| options | [ArkListOptions](#arklistoptions对象说明) | 否   | 为ArcList提供可选参数, 该对象内含有initialIndex、scroller、header等参数。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### digitalCrownSensitivity

digitalCrownSensitivity(sensitivity: Optional\<CrownSensitivity>)

设置表冠响应事件灵敏度。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名      | 类型                                                         | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| sensitivity | [Optional&lt;CrownSensitivity&gt;](ts-appendix-enums.md#crownsensitivity) | 是   | 表冠响应灵敏度。<br/>默认值：CrownSensitivity.MEDIUM，响应速度适中。 |

### space

space(space: Optional\<LengthMetrics>)

设置列表子项之间的距离。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                           |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------ |
| space  | [Optional&lt;LengthMetrics&gt;](ts-types.md#lengthmetrics12) | 否   | 子项之间的间距。<br/>默认值：0 |

### scrollBar

scrollBar(status: Optional\<BarState>)

设置滚动条状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                     |
| ------ | ---------------------------------------------------- | ---- | ---------------------------------------- |
| status | [Optional\<BarState>](ts-appendix-enums.md#barstate) | 否   | 滚动条状态。<br/>默认值：BarState.Auto。 |

### cachedCount

cachedCount(count: Optional\<number>)

设置列表中ArcArcListItem的预加载数量，只在[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)中生效。

在ArcList显示的ArcArcListItem前后各缓存cachedCount个ArcArcListItem。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型              | 必填 | 说明                                       |
| ------ | ----------------- | ---- | ------------------------------------------ |
| value  | Optional\<number> | 是   | ArcArcListItem的预加载数量。<br/>默认值：1 |

### chainAnimation

chainAnimation(enable: Optional\<boolean>)

设置当前ArcList是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。

链式联动效果：ArcList内的arclist-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。

链式动效生效需要满足前提条件：ArcList边缘效果为Spring类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型               | 必填 | 说明                                                         |
| ------ | ------------------ | ---- | ------------------------------------------------------------ |
| enable | Optional\<boolean> | 是   | 是否启用链式联动动效。<br/>默认值：false，不启用链式联动。true，启用链式联动。 |

### enableScrollInteraction

enableScrollInteraction(enable: Optional\<boolean>)

设置是否支持滚动手势，当设置为false时，无法通过手指或者鼠标滚动，但不影响控制器的滚动接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型               | 必填 | 说明                                |
| ------ | ------------------ | ---- | ----------------------------------- |
| enable | Optional\<boolean> | 是   | 是否支持滚动手势。<br/>默认值：true |

### friction

friction(friction: Optional\<number>)

设置摩擦系数，手动划动滚动区域时生效，只对惯性滚动过程有影响，对惯性滚动过程中的链式效果有间接影响。设置为小于等于0的值时，按默认值处理。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名   | 类型              | 必填 | 说明                         |
| -------- | ----------------- | ---- | ---------------------------- |
| friction | Optional\<number> | 否   | 摩擦系数。<br/>默认值：0.8。 |

### scrollBarWidth

scrollBarWidth(width: Optional\<LengthMetrics>)

设置滚动条的宽度，不支持百分比设置。宽度设置后，滚动条正常状态和按压状态宽度均为滚动条的宽度值。如果滚动条的宽度超过ArcList组件主轴方向的高度，则滚动条的宽度会变为默认值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------- |
| width  | [Optional&lt;LengthMetrics&gt;](ts-types.md#lengthmetrics12) | 是   | 滚动条的宽度。<br/>默认值：4<br/>单位：vp。 |

### scrollBarColor

scrollBarColor(color: Optional\<ColorMetrics>)

设置滚动条的颜色。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明           |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| color  | [Optional\<ColorMetrics>](../js-apis-arkui-graphics.md#colormetrics12) | 是   | 滚动条的颜色。 |

### flingSpeedLimit

flingSpeedLimit(speed: Optional\<number>)

限制跟手滑动结束后，Fling动效开始时的最大初始速度。单位是vp/s。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型              | 必填 | 说明                            |
| ------ | ----------------- | ---- | ------------------------------- |
| speed  | Optional\<number> | 是   | Fling动效开始时的最大初始速度。 |

### childrenMainSize

childrenMainSize(size: Optional\<ChildrenMainSize>)

设置ArcList组件的子组件在主轴方向的大小信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size   | [Optional\<ChildrenMainSize>](ts-container-list.md#childrenmainsize对象说明12) | 是   | 通过ChildrenMainSize对象向ArcList组件准确提供所有子组件在主轴方向的大小信息，能够使ArcList组件在子组件的主轴大小不一致、增删子组件、使用[scrollToIndex](ts-container-scroll.md#scrolltoindex)等场景也能维护自己准确的滑动位置，进而使[scrollTo](ts-container-scroll.md#scrollto)能跳转到准确的指定位置，[currentOffset](ts-container-scroll.md#currentoffset)能够获取到当前准确的滑动位置，内置滚动条能够平滑移动无跳变。<br/>说明：<br/>提供的主轴方向大小必须与子组件实际在主轴方向的大小一致，子组件在主轴方向大小变化或者增删子组件时都必须通过ChildrenMainSize对象方法通知ArcList组件。 |

## 事件

### onScrollIndex

onScrollIndex(handler: Optional\<ArcScrollIndexHandler>)

有子组件划入或划出ArcList显示区域时触发。

ArcList的边缘效果为弹簧效果时，在ArcList划动到边缘继续划动和松手回弹过程不会触发onScrollIndex事件。

触发该事件的条件：列表初始化时会触发一次，ArcList显示区域内第一个子组件的索引值或最后一个子组件的索引值有变化时会触发。

ArcList显示区域中间位置子组件变化时也会触发该事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                            |
| ------- | ------------------------------------------------------------ | ---- | ----------------------------------------------- |
| handler | [Optional\<ArcScrollIndexHandler>](#arcscrollindexhandler对象说明) | 是   | 有子组件划入或划出ArcList显示区域时触发该回调。 |

### onReachStart

onReachStart(handler: Optional\<VoidCallback>)

列表到达起始位置时触发。

ArcList初始化时如果initialIndex为0会触发一次，ArcList滚动到起始位置时触发一次。ArcList边缘效果为弹簧效果时，划动经过起始位置时触发一次，回弹回起始位置时再触发一次。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明                     |
| ------- | ------------------------------------------------ | ---- | ------------------------ |
| handler | [Optional\<VoidCallback>](#voidcallback对象说明) | 是   | 列表到达起始位置时触发。 |

### onReachEnd

onReachEnd(handler: Optional\<VoidCallback>)

列表到底末尾位置时触发。

ArcList边缘效果为弹簧效果时，划动经过末尾位置时触发一次，回弹回末尾位置时再触发一次。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明                     |
| ------- | ------------------------------------------------ | ---- | ------------------------ |
| handler | [Optional\<VoidCallback>](#voidcallback对象说明) | 是   | 列表到底末尾位置时触发。 |

### onScrollStart

onScrollStart(handler: Optional\<VoidCallback>)

列表滑动开始时触发。手指拖动列表或列表的滚动条触发的滑动开始时，会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画开始时会触发该事件

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明                 |
| ------- | ------------------------------------------------ | ---- | -------------------- |
| handler | [Optional\<VoidCallback>](#voidcallback对象说明) | 是   | 列表滑动开始时触发。 |

### onScrollStop

onScrollStop(handler: Optional\<VoidCallback>)

列表滑动停止时触发。手拖动列表或列表的滚动条触发的滑动，手离开屏幕并且滑动停止时会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画停止会触发该事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名  | 类型                                             | 必填 | 说明                 |
| ------- | ------------------------------------------------ | ---- | -------------------- |
| handler | [Optional\<VoidCallback>](#voidcallback对象说明) | 是   | 列表滑动停止时触发。 |

### onWillScroll

onWillScroll(handler: Optional\<OnWillScrollCallback>)

列表滑动前触发。返回当前帧将要滑动的偏移量和当前滑动状态。返回的偏移量为计算得到的将要滑动的偏移量值，并非最终实际滑动偏移。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| handler | [Optional\<OnWillScrollCallback>](#onwillscrollcallback对象说明) | 是 | 列表滑动时触发的回调。 |

> **说明：** 
> 
> 调用ScrollEdge和不带动画的ScrollToIndex时,不触发onWillScroll。

### onDidScroll
onDidScroll(handler: Optional\<OnScrollCallback>)

列表滑动时触发，返回当前帧滑动的偏移量和当前滑动状态。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| handler | [Optional\<OnScrollCallback>](ts-container-list.md#onscrollcallback对象说明) | 是 | 列表滑动时触发的回调。 |

## ArkListOptions对象说明

包含创建ArcList组件的基础参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名       | 参数类型                                    | 必填 | 参数描述                                                     |
| ------------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| initialIndex | number                                      | 否   | 设置当前ArcList初次加载时视口起始位置显示的item的索引值。<br/>默认值：0<br/>**说明：** <br/>设置为负数或超过了当前ArcList最后一个item的索引值时视为无效取值，无效取值按默认值显示。 |
| scroller     | [Scroller](ts-container-scroll.md#scroller) | 否   | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/>**说明：** <br/>不允许和其他滚动类组件绑定同一个滚动控制对象。 |
| header       | [ComponentContent](../js-apis-arkui-ComponentContent.md)                            | 否   | 支持标题设置。                                               |

## VoidCallback对象说明

该对象参数及返回值均为空。

## ArcScrollIndexHandler对象说明

有子组件划入或划出ArcList显示区域时触发的回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| start  | number | 是   | ArcList显示区域内第一个子组件的索引值。   |
| end    | number | 是   | ArcList显示区域内最后一个子组件的索引值。 |
| center | number | 是   | ArcList显示区域内中间位置子组件的索引值。 |

## OnWillScrollCallback对象说明

列表滑动前触发。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| scrollOffset | number                                                  | 是   | 每帧滚动的偏移量，ArcList的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>单位vp。 |
| scrollState  | [ScrollState](ts-container-list.md#scrollstate枚举说明) | 是   | 当前滑动状态。                                               |
| scrollSource | ScrollSource                                            | 是   | 当前滑动来源。                                               |

## 示例

该示例增加了ArcList支持标题栏设置的效果，子项自动缩放显示。

```ts
// xxx.ets
import { ComponentContent, LengthMetrics } from "@ohos.arkui.node";
import { UIContext } from '@ohos.arkui.UIContext';
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@kit.ArkUI';

@Builder
function buildText() {
  Column() {
    Text("header")
      .fontSize('60px')
      .fontWeight(FontWeight.Bold)
      .border({ width: '2px', color: Color.Black })
  }.margin(0)
}

@Entry
@Component
struct Index {
  @State  private numItems: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  private watchSize: string = '466px' // 手表默认宽高：466*466

  context: UIContext = this.getUIContext()
  tabBar1: ComponentContent<Object> = new ComponentContent(this.context, wrapBuilder(buildText));

  @Builder
  buildList2() {
    Stack() {
      Column() {
      }
      .justifyContent(FlexAlign.Center)
      .width(this.watchSize)
      .height(this.watchSize)
      .clip(new Circle({ width: '100%', height: '100%' }))
      .backgroundColor(0x707070)

      ArcList({ initialIndex: 0, header: this.tabBar1 }) {
        ForEach(this.numItems, (item: number, index: number) => {
          ArcListItem() {
            Button('' + item, { type: ButtonType.Capsule })
              .width('100%')
              .height('100px')
              .fontSize('40px')
              .focusable(true)
              .focusOnTouch(true)
              .backgroundColor(0x17A98D)
          }.align(Alignment.Center)
        }, (item: string, index: number) => item + index)
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
  }

  build() {
    Column() {
      this.buildList2()
    }
    .width('100%')
    .height('100%')
    .alignItems(HorizontalAlign.Center)
    .justifyContent(FlexAlign.Center)
  }
}
```

![arkts-arclist](figures/arkts-arclist.png)
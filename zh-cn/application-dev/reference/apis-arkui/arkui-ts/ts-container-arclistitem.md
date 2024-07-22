# ArcListItem

用来展示列表具体item，必须配合ArcList来使用。

> **说明：**
>
> - 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 该组件的父组件只能是[ArcList](ts-container-arclist.md)。
> - 当ArcListItem配合LazyForEach使用时，ArcListItem子组件在ArcListItem创建时创建。配合if/else、ForEach使用时，或父组件为ArcList时，ArcListItem子组件在ArcListItem布局时创建。

## 子组件

可以包含单个子组件。

## 接口

### ArcListItem

ArcListItem()

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**无

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### autoScale

autoScale(enable: Optional\<boolean>)

用于设置ArcListItem是否支持自动缩放显示。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型               | 必填 | 说明                                        |
| ------ | ------------------ | ---- | ------------------------------------------- |
| enable | Optional\<boolean> | 否   | item是否支持自动缩放显示。<br/>默认值：true |

### swipeAction

swipeAction(options: Optional\<SwipeActionOptions>)

用于设置ArcListItem的划出组件。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                    |
| ------- | ------------------------------------------------------------ | ---- | ----------------------- |
| options | [Optional\<SwipeActionOptions>](#swipeactionoptions对象说明) | 否   | ArcListItem的划出组件。 |

## SwipeActionOptions对象说明

start和end对应的@builder函数中顶层必须是单个组件，不能是if/else、ForEach、LazyForEach语句。

滑动手势只在ArcListItem区域上，如果子组件划出ArcListItem区域外，在ArcListItem以外部分不会响应划动手势。

| 名称           | 类型                                                         | 必填 | 描述                                  |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------- |
| start          | [CustomBuilder](ts-types.md#custombuilder8)&nbsp;\|&nbsp;[SwipeActionItem](#swipeactionitem对象说明) | 否   | ArcListItem向右划动时item左边的组件。 |
| end            | [CustomBuilder](ts-types.md#custombuilder8)&nbsp;\|&nbsp;[SwipeActionItem](#swipeactionitem对象说明) | 否   | ArcListItem向左划动时item右边的组件。 |
| edgeEffect     | [SwipeEdgeEffect](#swipeedgeeffect枚举说明)                  | 否   | 滑动效果。                            |
| onOffsetChange | (offset: number) => void                                     | 否   | 滑动操作偏移量更改时调用。            |

## SwipeEdgeEffect枚举说明

| 名称   | 枚举值 | 描述                                                         |
| ------ | ------ | ------------------------------------------------------------ |
| Spring | 0      | ArcListItem划动距离超过划出组件大小后可以继续划动。<br>如果设置了删除区域，ArcListItem划动距离超过删除阈值后可以继续划动，<br/>松手后按照弹簧阻尼曲线回弹。 |
| None   | 1      | ArcListItem划动距离不能超过划出组件大小。<br>如果设置了删除区域，ArcListItem划动距离不能超过删除阈值，<br/>并且在设置删除回调的情况下，达到删除阈值后松手触发删除回调。 |

## SwipeActionItem对象说明

ArcListItem向右滑动，item左边的长距离滑动删除选项或向左滑动时，item右边的长距离滑动删除选项。

| 名称                 | 参数类型                                                     | 必填 | 描述                                                         |
| -------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| actionAreaDistance | [Length](ts-types.md#length) | 否 | 设置组件长距离滑动删除距离阈值。<br/>默认值：56vp <br/>**说明：** <br/>不支持设置百分比。<br/>删除距离阈值大于item宽度减去划出组件宽度，或删除距离阈值小于等于0就不会设置删除区域。 |
| onAction | () => void | 否 | 组件进入长距删除区后删除ArcListItem时调用，进入长距删除区后抬手时触发。<br/>**说明：** <br/>滑动后松手的位置超过或等于设置的距离阈值，并且设置的距离阈值有效时才会触发。 |
| onEnterActionArea | () => void | 否 | 在滑动条目进入删除区域时调用，只触发一次，当再次进入时仍触发。 |
| onExitActionArea | () => void | 否 |当滑动条目退出删除区域时调用，只触发一次，当再次退出时仍触发。 |
| builder |  [CustomBuilder](ts-types.md#custombuilder8) | 否 |当列表项向左或向右滑动时显示的操作项。 |
| onStateChange | (swipeActionState) => void | 否 |当列表项滑动状态变化时候触发。|
## SwipeActionState枚举说明

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

| 名称      | 枚举值     | 描述                                                         |
| --------- | --------- | ------------------------------------------------------------ |
| COLLAPSED | 0 | 收起状态，当ArcListItem向左或向右滑动（当列表方向为“垂直”时）时操作项处于隐藏状态。 |
| EXPANDED  | 1 | 展开状态，当ArcListItem向左或向右滑动时操作项处于显示状态。<br/>**说明：**<br/>需要ArcListItem设置向左或向右滑动时显示的操作项。 |
| ACTIONING | 2 | 长距离状态，当ArcListItem进入长距删除区后删除ArcListItem的状态。<br/>**说明**:<br/>滑动后松手的位置超过或等于设置的距离阈值，并且设置的距离阈值有效时才能进入该状态。 |

## 示例

### 示例1 

```ts
// xxx.ets
import { LengthMetrics } from "@ohos.arkui.node";
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@ohos.arkui.ArcList';

@Entry
@Component
struct ArcListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      ArcList({ initialIndex: 0 }) {
        ForEach(this.arr, (item: number) => {
          ArcListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }.autoScale(false)
        }, (item: string) => item)
      }.width('90%')
      .space(LengthMetrics.px(20))
      .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

### 示例2


```ts
// xxx.ets
import { LengthMetrics } from "@ohos.arkui.node";
import { ArcList, ArcListItem, ArcListAttribute, ArcListItemAttribute } from '@ohos.arkui.ArcList';
@Entry
@Component
struct ArcListItemExample2 {
  @State arr: number[] = [0, 1, 2, 3, 4]
  @State enterEndDeleteAreaString: string = "not enterEndDeleteArea"
  @State exitEndDeleteAreaString: string = "not exitEndDeleteArea"

  @Builder itemEnd() {
    Row() {
      Button("Delete").margin("4vp")
      Button("Set").margin("4vp")
    }.padding("4vp").justifyContent(FlexAlign.SpaceEvenly)
  }

  build() {
    Column() {
      ArcList() {
        ForEach(this.arr, (item: number) => {
          ArcListItem() {
            Text("item" + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
          .transition({ type: TransitionType.Delete, opacity: 0 })
          .swipeAction({
            end: {
              builder: () => { this.itemEnd() },
              onAction: () => {
                animateTo({ duration: 1000 }, () => {
                  let index = this.arr.indexOf(item)
                  this.arr.splice(index, 1)
                })
              },
              actionAreaDistance: 56,
              onEnterActionArea: () => {
                this.enterEndDeleteAreaString = "enterEndDeleteArea"
                this.exitEndDeleteAreaString = "not exitEndDeleteArea"
              },
              onExitActionArea: () => {
                this.enterEndDeleteAreaString = "not enterEndDeleteArea"
                this.exitEndDeleteAreaString = "exitEndDeleteArea"
              }
            }
          })
        }, (item: string) => item)
      }
      .space(LengthMetrics.px(10))
      Text(this.enterEndDeleteAreaString).fontSize(20)
      Text(this.exitEndDeleteAreaString).fontSize(20)
    }
    .padding(10)
    .backgroundColor(0xDCDCDC)
    .width('100%')
    .height('100%')
  }
}
```
# Scroll

>  **说明：**
> 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


可滚动的容器组件，当子组件的布局尺寸超过父组件的视口时，内容可以滚动。


## 权限列表

无


## 子组件

支持单个子组件。


## 接口

Scroll(scroller?: Scroller)


## 属性

| 名称             | 参数类型                                     | 默认值                      | 描述        |
| -------------- | ---------------------------------------- | ------------------------ | --------- |
| scrollable     | ScrollDirection                          | ScrollDirection.Vertical | 设置滚动方法。   |
| scrollBar      | [BarState](ts-appendix-enums.md#barstate枚举说明) | ScrollDirection.Auto     | 设置滚动条状态。  |
| scrollBarColor | Color                                    | -                        | 设置滚动条的颜色。 |
| scrollBarWidth | Length                                   | -                        | 设置滚动条的宽度。 |

- ScrollDirection枚举说明
  | 名称         | 描述         |
  | ---------- | ---------- |
  | Horizontal | 仅支持水平方向滚动。 |
  | Vertical   | 仅支持竖直方向滚动。 |
  | None       | 不可滚动。      |

## 事件

| 名称                                       | 功能描述                          |
| ---------------------------------------- | ----------------------------- |
| onScroll(xOffset:&nbsp;number,&nbsp;yOffset:&nbsp;number)&nbsp;=&gt;&nbsp;void | 滚动事件回调,&nbsp;返回滚动时水平、竖直方向偏移量。 |
| onScrollEdge(side:&nbsp;Edge)&nbsp;=&gt;&nbsp;void | 滚动到边缘事件回调。                    |
| onScrollEnd()&nbsp;=&gt;&nbsp;void       | 滚动停止事件回调。                     |

## Scroller

可滚动容器组件的控制器，可以将此组件绑定至容器组件，然后通过它控制容器组件的滚动，目前支持绑定到List和Scroll组件上。


### 导入对象

```
scroller: Scroller = new Scroller()
```


### scrollTo

scrollTo(value: { xOffset: number | string, yOffset: number | string, animation?: { duration: number, curve: Curve } }): void


滑动到指定位置。


- 参数
  | 参数名       | 参数类型                                     | 必填   | 默认值  | 参数描述                                     |
  | --------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
  | xOffset   | Length                                   | 是    | -    | 水平滑动偏移。                                  |
  | yOffset   | Length                                   | 是    | -    | 竖直滑动偏移。                                  |
  | animation | {<br/>duration:&nbsp;number,<br/>curve:&nbsp;[Curve](ts-animatorproperty.md)&nbsp;\|<br/>CubicBezier&nbsp;\|<br/>SpringCurve<br/>} | 否    |      | 动画配置：<br/>-&nbsp;duration:&nbsp;滚动时长设置。<br/>-&nbsp;curve:&nbsp;滚动曲线设置。 |


### scrollEdge

scrollEdge(value: Edge): void


滚动到容器边缘。


- 参数
  | 参数名   | 参数类型 | 必填   | 默认值  | 参数描述      |
  | ----- | ---- | ---- | ---- | --------- |
  | value | Edge | 是    | -    | 滚动到的边缘位置。 |


### scrollPage

scrollPage(value: { next: boolean, direction?: Axis }): void

滚动到下一页或者上一页。

- 参数
  | 参数名       | 参数类型    | 必填   | 默认值  | 参数描述                           |
  | --------- | ------- | ---- | ---- | ------------------------------ |
  | next      | boolean | 是    | -    | 是否向下翻页。true表示向下翻页，false表示向上翻页。 |
  | direction | Axis    | 否    | -    | 设置滚动方向为水平或竖直方向。                |


### currentOffset

scroller.currentOffset(): Object


返回当前的滚动偏移量。


- 返回值
  | 类型                                       | 描述                                       |
  | ---------------------------------------- | ---------------------------------------- |
  | {<br/>xOffset:&nbsp;number,<br/>yOffset:&nbsp;number<br/>} | xOffset:&nbsp;水平滑动偏移;<br/>yOffset:&nbsp;竖直滑动偏移。 |


### scrollToIndex

scroller.scrollToIndex(value: number): void


滑动到指定Index。


>  **说明：**
> 仅支持list组件。


- 参数
  | 参数名   | 参数类型   | 必填   | 默认值  | 参数描述              |
  | ----- | ------ | ---- | ---- | ----------------- |
  | value | number | 是    | -    | 要滑动到的列表项在列表中的索引值。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller()
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item) => {
            Text(item.toString())
              .width('90%').height(150).backgroundColor(0xFFFFFF)
              .borderRadius(15).fontSize(16).textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, item => item)
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical).scrollBar(BarState.On)
      .scrollBarColor(Color.Gray).scrollBarWidth(30)
      .onScroll((xOffset: number, yOffset: number) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
      .onScrollEnd(() => {
        console.info('Scroll Stop')
      })

      Button('scroll 100')
        .onClick(() => { // 点击后下滑100.0距离
          this.scroller.scrollTo({ xOffset: 0, yOffset: this.scroller.currentOffset().yOffset + 100 })
        })
        .margin({ top: 10, left: 20 })
      Button('back top')
        .onClick(() => { // 点击后回到顶部
          this.scroller.scrollEdge(Edge.Top)
        })
        .margin({ top: 60, left: 20 })
      Button('next page')
        .onClick(() => { // 点击后下滑到底部
          this.scroller.scrollPage({ next: true })
        })
        .margin({ top: 110, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![zh-cn_image_0000001174104386](figures/zh-cn_image_0000001174104386.gif)

# Scroll

可滑动的容器组件，当子组件的布局尺寸超过父组件的视口时，内容可以滑动。

>  **说明：**
>
>  - 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  - 该组件回弹的前提是要有滑动。内容小于一屏时，没有回弹效果。


## 子组件

支持单个子组件。


## 接口

Scroll(scroller?: Scroller)


## 属性

| 名称           | 参数类型                                      | 描述                                                         |
| -------------- | --------------------------------------------- | ------------------------------------------------------------ |
| scrollable     | ScrollDirection                               | 设置滑动方法。<br/>默认值：ScrollDirection.Vertical          |
| scrollBar      | [BarState](ts-appendix-enums.md#barstate)     | 设置滑动条状态。<br/>默认值：BarState.Off                    |
| scrollBarColor | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Color | 设置滑动条的颜色。                                           |
| scrollBarWidth | string&nbsp;\|&nbsp;number                    | 设置滑动条的宽度。                                           |
| edgeEffect     | [EdgeEffect](ts-appendix-enums.md#edgeeffect) | 设置滑动效果，目前支持的滑动效果参见EdgeEffect的枚举说明。<br/>默认值：EdgeEffect.None |

## ScrollDirection枚举说明

| 名称         | 描述           |
| ---------- | ------------ |
| Horizontal | 仅支持水平方向滚动。   |
| Vertical   | 仅支持竖直方向滚动。   |
| None       | 不可滚动。        |
| Free       | 支持竖直或水平方向滚动。 |

## 事件

| 名称                                       | 功能描述                          |
| ---------------------------------------- | ----------------------------- |
| onScroll(event: (xOffset: number, yOffset: number) => void) | 滚动事件回调,&nbsp;返回滚动时水平、竖直方向偏移量。 |
| onScrollEdge(event: (side: Edge) => void) | 滚动到边缘事件回调。                    |
| onScrollEnd(event: () => void)           | 滚动停止事件回调。                     |

## Scroller

可滑动容器组件的控制器，可以将此组件绑定至容器组件，然后通过它控制容器组件的滑动，目前支持绑定到List、Scroll、ScrollBar上。


### 导入对象

```
scroller: Scroller = new Scroller()
```


### scrollTo

scrollTo(value: { xOffset: number | string, yOffset: number | string, animation?: { duration: number, curve: Curve } }): void


滑动到指定位置。

**参数：**

| 参数名       | 参数类型                                     | 必填   | 参数描述                                     |
| --------- | ---------------------------------------- | ---- | ---------------------------------------- |
| xOffset   | number&nbsp;\|&nbsp;string               | 是    | 水平滑动偏移。                                  |
| yOffset   | number&nbsp;\|&nbsp;string               | 是    | 竖直滑动偏移。                                  |
| animation | {<br/>duration:&nbsp;number,<br/>curve:&nbsp;[Curve](ts-appendix-enums.md#curve)&nbsp;<br/>} | 否    | 动画配置：<br/>-&nbsp;duration:&nbsp;滑动时长设置。<br/>-&nbsp;curve:&nbsp;滑动曲线设置。 |

### scrollEdge

scrollEdge(value: [Edge](ts-appendix-enums.md#edge)): void


滑动到容器边缘。

### scrollPage

scrollPage(value: { next: boolean, direction?: Axis }): void

滑动到下一页或者上一页。

**参数：**

| 参数名       | 参数类型                              | 必填   | 参数描述                           |
| --------- | --------------------------------- | ---- | ------------------------------ |
| next      | boolean                           | 是    | 是否向下翻页。true表示向下翻页，false表示向上翻页。 |
| direction | [Axis](ts-appendix-enums.md#axis) | 否    | 设置滑动方向为水平或竖直方向。                |

### currentOffset

currentOffset()


返回当前的滑动偏移量。

### scrollToIndex

scrollToIndex(value: number): void


滑动到指定Index。


>  **说明：**
>  仅支持list组件。

**参数：**

| 参数名   | 参数类型   | 必填   | 参数描述              |
| ----- | ------ | ---- | ----------------- |
| value | number | 是    | 要滑动到的列表项在列表中的索引值。 |

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
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, item => item)
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Gray)
      .scrollBarWidth(30)
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

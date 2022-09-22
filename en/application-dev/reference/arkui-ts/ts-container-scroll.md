# Scroll


The **\<Scroll>** component scrolls the content when the layout size of a component exceeds the viewport of its parent component.


> **NOTE**
>  - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>  - This component can produce a bounce effect only when there is more than one screen of content.


## Required Permissions

None


## Child Components

This component supports only one child component.


## APIs

Scroll(scroller?: Scroller)


## Attributes

| Name       | Type      | Default Value      | Description |
| -------- | -------- | -------- | -------- |
| scrollable     | ScrollDirection   | ScrollDirection.Vertical | Scroll method. |
| scrollBar      | [BarState](ts-appendix-enums.md#barstate) | BarState.Off | Scrollbar status. |
| scrollBarColor | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Color | - | Color of the scrollbar. |
| scrollBarWidth | string&nbsp;\|&nbsp;number | - | Width of the scrollbar. |
| edgeEffect | [EdgeEffect](ts-appendix-enums.md#edgeeffect) | EdgeEffect.Spring | Scroll effect. For details, see **EdgeEffect**. |

## ScrollDirection
| Name       | Description |
| -------- | -------- |
| Horizontal | Only horizontal scrolling is supported. |
| Vertical | Only vertical scrolling is supported. |
| None     | Scrolling is disabled. |
| Free       | Both horizontal scrolling and vertical scrolling are supported. |

## Events

| Name | Description |
| -------- | -------- |
| onScroll(event: (xOffset: number, yOffset: number) => void) | Invoked when scrolling starts. It returns the horizontal and vertical offsets. |
| onScrollEdge(event: (side: Edge) => void) | Invoked when scrolling reaches the edge. |
| onScrollEnd(event: () => void) | Invoked when scrolling stops. |


## Scroller

Controller of the scrollable container component. You can bind this component to the container component and use it to control the scrolling of the container component. Currently, this component can be bound to the **\<List>** and **\<Scroll>** components.


### Objects to Import


```
scroller: Scroller = new Scroller()
```


### scrollTo

scrollTo(value: { xOffset: number | string, yOffset: number | string, animation?: { duration: number, curve: Curve } }): void


Scrolls to the specified position.

**Parameters**

| Name | Type | Mandatory | Default Value | Description |
| -------- | -------- | -------- | -------- | -------- |
| xOffset | number&nbsp;\|&nbsp;string | Yes | - | Horizontal scrolling offset. |
| yOffset | number&nbsp;\|&nbsp;string | Yes | - | Vertical scrolling offset. |
| animation | {<br/>duration:&nbsp;number,<br/>curve:&nbsp;[Curve](ts-animatorproperty.md)&nbsp;<br/>} | No |  | Animation configuration, which includes the following:<br/>- **duration**: scrolling duration.<br/>- **curve**: scrolling curve. |


### scrollEdge

scrollEdge(value: [Edge](ts-appendix-enums.md#edge)): void


Scrolls to the edge of the container.

### scrollPage

scrollPage(value: { next: boolean, direction?: Axis }): void

Scrolls to the next or previous page.

**Parameters**

| Name | Type | Mandatory | Default Value | Description |
| -------- | -------- | -------- | -------- | -------- |
| next | boolean | Yes | - | Whether to turn to the next page. The value **true** means to scroll to the next page, and the value **false** means to scroll to the previous page. |
| direction | [Axis](ts-appendix-enums.md#axis) | No | - | Scrolling direction: horizontal or vertical. |


### currentOffset

currentOffset()


Obtains the scrolling offset.

### scrollToIndex

scrollToIndex(value: number): void


Scrolls to the specified index.


> **NOTE**
>
> Only the **\<List>** component is supported.


- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Index of the item to be scrolled to in the list. |



## Example


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
        .onClick(() => {// Click to scroll down 100.0.
          this.scroller.scrollTo({ xOffset: 0, yOffset: this.scroller.currentOffset().yOffset + 100 })
        })
        .margin({ top: 10, left: 20 })
      Button('back top')
        .onClick(() => {// Click to go back to the top.
          this.scroller.scrollEdge(Edge.Top)
        })
        .margin({ top: 60, left: 20 })
      Button('next page')
        .onClick(() => {// Click to scroll down to the bottom.
          this.scroller.scrollPage({ next: true })
        })
        .margin({ top: 110, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![en-us_image_0000001256978363](figures/en-us_image_0000001256978363.gif)

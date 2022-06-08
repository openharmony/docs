# Scroll


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Scroll&gt;** component scrolls the content when the layout size of a component exceeds the viewport of its parent component.


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
| scrollBar      | [BarState](ts-appendix-enums.md#barstate-enums) | Auto | Scroll bar status. |
| scrollBarColor | Color | - | Color of the scroll bar. |
| scrollBarWidth | Length | - | Width of the scrollbar. |

- ScrollDirection
  | Name       | Description |
  | -------- | -------- |
  | Horizontal | Only horizontal scrolling is supported. |
  | Vertical | Only vertical scrolling is supported. |
  | None     | Scrolling is disabled. |


## Scroller

Controller of the scrollable container component. You can bind this component to the container component and use it to control the scrolling of the container component. Currently, this component can be bound to the **&lt;List&gt;** and **&lt;Scroll&gt;** components.


### Objects to Import


```
scroller: Scroller = new Scroller()
```


### scroller.scrollTo

scrollTo(value: { xOffset: number | string, yOffset: number | string, animation?: { duration: number, curve: Curve } }): void


Scrolls to the specified position.


- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | xOffset | Length | Yes | - | Horizontal scrolling offset. |
  | yOffset | Length | Yes | - | Vertical scrolling offset. |
  | animation | {<br/>duration: number,<br/>curve: Curve \|<br/>CubicBezier \|<br/>SpringCurve<br/>} | No |  | Animation configuration, which includes the following:<br/>- **duration**: scrolling duration.<br/>- **curve**: scrolling curve. |


### scroller.scrollEdge

scrollEdge(value: Edge): void


Scrolls to the edge of the container.


- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | Edge | Yes | - | Edge position to scroll to. |


### scroller.scrollPage

scrollPage(value: { next: boolean, direction?: Axis }): void

Scrolls to the next or previous page.

- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | next | boolean | Yes | - | Whether to turn to the next page. The value **true** means to scroll to the next page, and the value **false** means to scroll to the previous page. |


### scroller.currentOffset

scroller.currentOffset(): Object


Obtains the scrolling offset.


- Return value
    | Type | Description |
  | -------- | -------- |
  | {<br/>xOffset: number,<br/>yOffset: number<br/>} | **xOffset**: horizontal scrolling offset.<br/>**yOffset**: vertical scrolling offset. |


### scroller.scrollToIndex

scroller.scrollToIndex(value: number): void


Scrolls to the specified index.


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> Only the **&lt;List&gt;** component is supported.


- Parameters
    | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Index of the item to be scrolled to in the list. |


## Events

| Name | Description |
| -------- | -------- |
| onScroll(xOffset: number, yOffset: number) =&gt; void | Invoked to return the horizontal and vertical offsets during scrolling when the specified scroll event occurs. |
| onScrollEdge(side: Edge) =&gt; void | Callback for the event of scrolling to the edge. |
| onScrollEnd() =&gt; void | Invoked when scrolling stops. |


## Example


```
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

# Scroll

The **\<Scroll>** component scrolls the content when the layout size of a component exceeds the size of its parent component.

>  **NOTE**
>  - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>  - The prerequisite for the component to rebound is that the component is scrolled.


## Child Components

This component supports only one child component.


## APIs

Scroll(scroller?: Scroller)

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name            | Type                                    | Description       |
| -------------- | ---------------------------------------- | --------- |
| scrollable     | ScrollDirection                          | Scroll direction.<br>Default value: **ScrollDirection.Vertical**|
| scrollBar      | [BarState](ts-appendix-enums.md#barstate) | Scrollbar status.<br>Default value: **BarState.Off**|
| scrollBarColor | string \| number \| Color   | Color of the scrollbar.|
| scrollBarWidth | string \| number         | Width of the scrollbar.|
| edgeEffect     | [EdgeEffect](ts-appendix-enums.md#edgeeffect)            | Scroll effect. For details, see **EdgeEffect**.<br>Default value: **EdgeEffect.Spring**|

## ScrollDirection
| Name      | Description                    |
| ---------- | ------------------------ |
| Horizontal | Only horizontal scrolling is supported.    |
| Vertical   | Only vertical scrolling is supported.    |
| None       | Scrolling is disabled.              |
| Free<sup>(deprecated) </sup> | Vertical or horizontal scrolling is supported.<br> This API is deprecated since API version 9.|

## Events

| Name                                                        | Description                                                  |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| onScroll(event: (xOffset: number, yOffset: number) => void) | Invoked to return the horizontal and vertical offsets during scrolling when the specified scroll event occurs. |
| onScrollEdge(event: (side: Edge) => void)                   | Invoked when scrolling reaches the edge.                     |
| onScrollEnd(event: () => void)                              | Invoked when scrolling stops.                                |

## Scroller

Implements a controller for a scrollable container component. You can bind this component to a container component and use it to control the scrolling of that component. Currently, this controller can be bound to the **\<List>**, **\<Scroll>** and **\<ScrollBar>** components. One controller can control only one container component.


### Objects to Import

```
scroller: Scroller = new Scroller()
```


### scrollTo

scrollTo(value: { xOffset: number | string, yOffset: number | string, animation?: { duration: number, curve: Curve } }): void


Scrolls to the specified position.

**Parameters**

| Name   | Type                                                    | Mandatory| Description                                                    |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| xOffset   | number \| string                                                       | Yes  | Horizontal scrolling offset.                                              |
| yOffset   | number \| string                                                       | Yes  | Vertical scrolling offset.                                              |
| animation | {<br>duration: number,<br>curve: [Curve](ts-appendix-enums.md#curve)<br>} | No  | Animation configuration, which includes the following:<br>- **duration**: scrolling duration.<br>- **curve**: scrolling curve.|


### scrollEdge

scrollEdge(value: [Edge](ts-appendix-enums.md#edge)): void


Scrolls to the edge of the container.


### scrollPage

scrollPage(value: { next: boolean, direction?: Axis }): void

Scrolls to the next or previous page.

**Parameters**

| Name      | Type   | Mandatory  | Description                          |
| --------- | ------- | ---- | ------------------------------ |
| next      | boolean | Yes   | Whether to turn to the next page. The value **true** means to scroll to the next page, and **false** means to scroll to the previous page.|
| direction | [Axis](ts-appendix-enums.md#axis)    | No   | Scrolling direction: horizontal or vertical.               |


### currentOffset

currentOffset()


Obtains the scrolling offset.

### scrollToIndex

scrollToIndex(value: number): void


Scrolls to the item with the specified index.


>  **NOTE**
>
>  Only the **\<List>** component is supported.

**Parameters**

| Name| Type| Mandatory| Description                          |
| ------ | -------- | ---- | ---------------------------------- |
| value  | number   | Yes  | Index of the item to be scrolled to in the list.|


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
        .onClick(() => { // Click to scroll down by 100.0 vp.
          this.scroller.scrollTo({ xOffset: 0, yOffset: this.scroller.currentOffset().yOffset + 100 })
        })
        .margin({ top: 10, left: 20 })
      Button('back top')
        .onClick(() => { // Click to go back to the top.
          this.scroller.scrollEdge(Edge.Top)
        })
        .margin({ top: 60, left: 20 })
      Button('next page')
        .onClick(() => { // Click to go to the next page.
          this.scroller.scrollPage({ next: true })
        })
        .margin({ top: 110, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![en-us_image_0000001256978363](figures/en-us_image_0000001256978363.gif)

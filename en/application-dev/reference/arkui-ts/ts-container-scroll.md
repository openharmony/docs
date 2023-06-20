# Scroll

The **\<Scroll>** component scrolls the content when the layout size of a component exceeds the size of its parent component.

>  **NOTE**
>  - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>  - When nesting a **\<List>** within this component, specify the width and height for the **\<List>** under scenarios where consistently high performance is required. If the width and height are not specified, this component will load all content of the **\<List>**.
>  - This component can scroll only when the size on the main axis is less than the content size.
>  - This component can produce a bounce effect only when there is more than one screen of content.


## Child Components

This component supports only one child component.


## APIs

Scroll(scroller?: Scroller)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| scroller | [Scroller](#scroller) | No| Scroller, which can be bound to scrollable components.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name            | Type                                    | Description       |
| -------------- | ---------------------------------------- | --------- |
| scrollable     | [ScrollDirection](#scrolldirection)                        | Scroll direction.<br>Default value: **ScrollDirection.Vertical**|
| scrollBar      | [BarState](ts-appendix-enums.md#barstate) | Scrollbar status.<br>Default value: **BarState.Auto**<br>**NOTE**<br>If the container component cannot be scrolled, the scrollbar is not displayed. If the size of a child component of a container component is infinite, the scrollbar cannot be dragged or scrolled with the child component.|
| scrollBarColor | string \| number \| [Color](ts-appendix-enums.md#color)   | Color of the scrollbar.|
| scrollBarWidth | string \| number         | Width of the scrollbar. This attribute cannot be set in percentage.<br>Default value: **4**<br>Unit: vp<br>**NOTE**<br>If the width of the scrollbar exceeds its height, it will change to the default value.|
| edgeEffect     | [EdgeEffect](ts-appendix-enums.md#edgeeffect)            | Scroll effect. For details, see **EdgeEffect**.<br>Default value: **EdgeEffect.None**|

## ScrollDirection
| Name      | Description                    |
| ---------- | ------------------------ |
| Horizontal | Only horizontal scrolling is supported.    |
| Vertical   | Only vertical scrolling is supported.    |
| None       | Scrolling is disabled.              |
| Free<sup>(deprecated)</sup> | Vertical or horizontal scrolling is supported.<br>This API is deprecated since API version 9.|

## Events

| Name                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onScrollFrameBegin<sup>9+</sup>(event: (offset: number, state: ScrollState) => { offsetRemain }) | Triggered when each frame scrolling starts. The input parameters indicate the amount by which the **\<Scroll>** component will scroll. The event handler then works out the amount by which the component needs to scroll based on the real-world situation and returns the result.<br>\- **offset**: amount to scroll by.<br>\- **state**: current scrolling status.<br>- **offsetRemain**: actual amount by which the component scrolls.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is not triggered when the controller API is called.<br>3. No out-of-bounds bounce effect is triggered.<br>**NOTE**<br>The value of **offsetRemain** can be a negative value.<br>If the **onScrollFrameBegine** event and **scrollBy** method are used to implement nested scrolling, set the **edgeEffect** attribute of the scrollable child component to **None**. For example, if a **\<List>** is nested in the **\<Scroll>** component, **edgeEffect** of the **\<List>** must be set to **EdgeEffect.None**.|
| onScroll(event: (xOffset: number, yOffset: number) => void)  | Triggered to return the horizontal and vertical offsets during scrolling when the specified scroll event occurs.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. The out-of-bounds bounce effect is triggered.|
| onScrollEdge(event: (side: Edge) => void)                    | Triggered when scrolling reaches the edge.<br>**NOTE**<br>1. This event is triggered when scrolling reaches the edge after being started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called.<br>3. The out-of-bounds bounce effect is triggered.|
| onScrollEnd<sup>(deprecated) </sup>(event: () => void)       | Triggered when scrolling stops.<br>This event is deprecated since API version 9. Use the **onScrollStop** event instead.<br>**NOTE**<br>1. This event is triggered when scrolling is stopped by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called, accompanied by a transition animation.|
| onScrollStart<sup>9+</sup>(event: () => void)                | Triggered when scrolling starts and is initiated by the user's finger dragging the **\<Scroll>** component or its scrollbar. This event is also triggered when the animation contained in the scrolling triggered by [Scroller](#scroller) starts.<br>**NOTE**<br>1. This event is triggered when scrolling is started by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called, accompanied by a transition animation.|
| onScrollStop<sup>9+</sup>(event: () => void)                 | Triggered when scrolling stops after the user's finger leaves the screen. This event is also triggered when the animation contained in the scrolling triggered by [Scroller](#scroller) stops.<br>**NOTE**<br>1. This event is triggered when scrolling is stopped by the **\<Scroll>** component or other input settings, such as keyboard and mouse operations.<br>2. This event is triggered when the controller API is called, accompanied by a transition animation.|

>  **NOTE**
>
>  If the **onScrollFrameBegin** event and **scrollBy** method are used to implement nested scrolling, set the **edgeEffect** attribute of the scrollable child component to **None**. For example, if a **\<List>** is nested in the **\<Scroll>** component, **edgeEffect** of the **\<List>** must be set to **EdgeEffect.None**.

## Scroller

Implements a controller for a scrollable container component. You can bind this component to a container component and use it to control the scrolling of that component. One controller can control only one container component. The supported container components are **\<List>**, **\<Scroll>**, **\<ScrollBar>**, **\<Grid>**, and **\<WaterFlow>**.


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
| xOffset   | number \| string                                   | Yes  | Horizontal scrolling offset.<br>**NOTE**<br>This parameter cannot be set in percentage.<br>This parameter is valid only when the scroll axis is the x-axis.|
| yOffset   | number \| string                                   | Yes  | Vertical scrolling offset.<br>**NOTE**<br>This parameter cannot be set in percentage.<br>This parameter is valid only when the scroll axis is the y-axis.|
| animation | {<br>duration: number,<br>curve: [Curve](ts-appendix-enums.md#curve)<br>} | No  | Animation configuration, which includes the following:<br>- **duration**: scrolling duration.<br>- **curve**: scrolling curve.<br>Default value:<br>{<br>duration: 0,<br>curve: Curve.Ease<br>}<br>**NOTE**<br>A value less than 0 evaluates to the default value.|


### scrollEdge

scrollEdge(value: Edge): void


Scrolls to the edge of the container, regardless of the scroll axis direction. **Edge.Top** and **Edge.Start** produce the same effect, and **Edge.Bottom** and **Edge.End** produce the same effect.

**Parameters**

| Name  | Type| Mandatory  | Description     |
| ----- | ---- | ---- | --------- |
| value | [Edge](ts-appendix-enums.md#edge) | Yes   | Edge position to scroll to.|


### scrollPage

scrollPage(value: { next: boolean, direction?: Axis }): void

Scrolls to the next or previous page.

**Parameters**

| Name      | Type   | Mandatory  | Description                          |
| --------- | ------- | ---- | ------------------------------ |
| next      | boolean | Yes   | Whether to turn to the next page. The value **true** means to scroll to the next page, and **false** means to scroll to the previous page.|
| direction<sup>(deprecated)</sup> | [Axis](ts-appendix-enums.md#axis)    | No   | Scrolling direction: horizontal or vertical.<br>This API is deprecated since API version 9.               |


### currentOffset

currentOffset(): { xOffset: number, yOffset: number }


Obtains the scrolling offset.

**Return value**

| Type                                                      | Description                                                        |
| ---------------------------------------------------------- | ------------------------------------------------------------ |
| {<br>xOffset: number,<br>yOffset: number<br>} | **xOffset**: horizontal scrolling offset.<br>**yOffset**: vertical scrolling offset.<br>**NOTE**<br>The unit of the return value is vp.|


### scrollToIndex

scrollToIndex(value: number): void


Scrolls to the item with the specified index.


>  **NOTE**
>
>  Only the **\<Grid>**, **\<List>**, and **\<WaterFlow>** components are supported.

**Parameters**

| Name| Type| Mandatory| Description                          |
| ------ | -------- | ---- | ---------------------------------- |
| value  | number   | Yes  | Index of the item to be scrolled to in the list.|


### scrollBy<sup>9+</sup>

scrollBy(dx: Length, dy: Length): void


Scrolls by the specified amount.


>  **NOTE**
>
>  Only the **\<Scroll>**, **\<ScrollBar>**, **\<Grid>**, and **\<List>** components are supported.

**Parameters**

| Name  | Type  | Mandatory  | Description             |
| ----- | ------ | ---- | ----------------- |
| dx | Length | Yes   | Amount to scroll by in the horizontal direction. The percentage format is not supported.|
| dy | Length | Yes   | Amount to scroll by in the vertical direction. The percentage format is not supported.|


## Example
### Example 1

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
      .scrollable(ScrollDirection.Vertical)  // The scrollbar scrolls in the vertical direction.
      .scrollBar(BarState.On)  // The scrollbar is always displayed.
      .scrollBarColor(Color.Gray)  // Color of the scrollbar.
      .scrollBarWidth(10) // The scrollbar width is 10.
      .edgeEffect(EdgeEffect.None)
      .onScroll((xOffset: number, yOffset: number) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
      .onScrollEnd(() => {
        console.info('Scroll Stop')
      })

      Button('scroll 150')
        .height('5%')
        .onClick(() => { // Click to scroll down to 150.0 vp.
          this.scroller.scrollBy(0,150)
        })
        .margin({ top: 10, left: 20 })
      Button('scroll 100')
        .height('5%')
        .onClick(() => { // Click to scroll down by 100.0 vp.
          this.scroller.scrollTo({ xOffset: 0, yOffset: this.scroller.currentOffset().yOffset + 100 })
        })
        .margin({ top: 60, left: 20 })
      Button('back top')
        .height('5%')
        .onClick(() => { // Click to go back to the top.
          this.scroller.scrollEdge(Edge.Top)
        })
        .margin({ top: 110, left: 20 })
      Button('next page')
        .height('5%')
        .onClick(() => { // Click to go to the next page.
          this.scroller.scrollPage({ next: true })
        })
        .margin({ top: 170, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![en-us_image_0000001256978363](figures/en-us_image_0000001256978363.gif)

### Example 2
```ts
@Entry
@Component
struct NestedScroll {
  @State listPosition: number = 0; // 0 indicates scrolling to the top of the list, 1 indicates scrolling to the middle of the list, and 2 indicates scrolling to the bottom of the list.
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  private scrollerForScroll: Scroller = new Scroller()
  private scrollerForList: Scroller = new Scroller()

  build() {
    Flex() {
      Scroll(this.scrollerForScroll) {
        Column() {
          Text("Scroll Area")
            .width("100%").height("40%").backgroundColor(0X330000FF)
            .fontSize(16).textAlign(TextAlign.Center)
            .onClick(() => {
              this.scrollerForList.scrollToIndex(5)
            })

          List({ space: 20, scroller: this.scrollerForList }) {
            ForEach(this.arr, (item) => {
              ListItem() {
                Text("ListItem" + item)
                  .width("100%").height("100%").borderRadius(15)
                  .fontSize(16).textAlign(TextAlign.Center).backgroundColor(Color.White)
              }.width("100%").height(100)
            }, item => item)
          }
          .width("100%")
          .height("50%")
          .edgeEffect(EdgeEffect.None)
          .onReachStart(() => {
            this.listPosition = 0
          })
          .onReachEnd(() => {
            this.listPosition = 2
          })
          .onScrollFrameBegin((offset: number) => {
            if ((this.listPosition == 0 && offset <= 0) || (this.listPosition == 2 && offset >= 0)) {
              this.scrollerForScroll.scrollBy(0, offset)
              return { offsetRemain: 0 }
            }
            this.listPosition = 1
            return { offsetRemain: offset };
          })

          Text("Scroll Area")
            .width("100%").height("40%").backgroundColor(0X330000FF)
            .fontSize(16).textAlign(TextAlign.Center)
        }
      }
      .width("100%").height("100%")
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding(20)
  }
}
```

![NestedScroll](figures/NestedScroll.gif)

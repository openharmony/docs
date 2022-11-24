# ScrollBar

The **\<ScrollBar>** is used together with scrollable components, such as **\<List>**, **\<Grid>**, and **\<Scroll>**.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component can contain a single child component.


## APIs

ScrollBar(value: { scroller: Scroller, direction?: ScrollBarDirection, state?: BarState })

**Parameters**

| Name| Type| Mandatory| Default Value | Description|
| -------- | -------- | -------- | -------- | -------- |
| scroller | [Scroller](ts-container-scroll.md#scroller) | Yes| - | Scroller, which can be bound to scrollable components.|
| direction | ScrollBarDirection | No| ScrollBarDirection.Vertical | Scrollbar direction in which scrollable components scroll. |
| state | [BarState](ts-appendix-enums.md#barstate) | No| BarState.Auto | Scrollbar state. |

>  **NOTE**
>
>  The **\<ScrollBar>** component defines the behavior style of the scrollable area, and its subnodes define the behavior style of the scrollbar.
>
>  This component is bound to a scrollable component through **scroller**, and can be used to scroll the scrollable component only when their directions are the same. The **\<ScrollBar>** component can be bound to only one scrollable component, and vice versa.

## ScrollBarDirection

| Name| Description|
| -------- | -------- |
| Vertical | Vertical scrollbar.|
| Horizontal | Horizontal scrollbar.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct ScrollBarExample {
  private scroller: Scroller = new Scroller()
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      Stack({ alignContent: Alignment.End }) {
        Scroll(this.scroller) {
          Flex({ direction: FlexDirection.Column }) {
            ForEach(this.arr, (item) => {
              Row() {
                Text(item.toString())
                  .width('90%')
                  .height(100)
                  .backgroundColor('#3366CC')
                  .borderRadius(15)
                  .fontSize(16)
                  .textAlign(TextAlign.Center)
                  .margin({ top: 5 })
              }
            }, item => item)
          }.margin({ left: 52 })
        }
        .scrollBar(BarState.Off)
        .scrollable(ScrollDirection.Vertical)
        ScrollBar({ scroller: this.scroller, direction: ScrollBarDirection.Vertical,state: BarState.Auto }) {
          Text()
            .width(30)
            .height(100)
            .borderRadius(10)
            .backgroundColor('#C0C0C0')
        }.width(30).backgroundColor('#ededed')
      }
    }
  }
}
```


![en-us_image_0000001256978369](figures/en-us_image_0000001256978369.gif)

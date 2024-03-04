# ScrollBar

The **\<ScrollBar>** is used together with scrollable components, such as **\<List>**, **\<Grid>**, and **\<Scroll>**.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component can contain a single child component.


## APIs

ScrollBar(value: ScrollBarOptions)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value |  [ScrollBarOptions](#scrollbaroptions)| Yes| Scrollbar settings.|

## ScrollBarOptions

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| scroller | [Scroller](ts-container-scroll.md#scroller) | Yes| Scroller, which can be bound to scrollable components.|
| direction | [ScrollBarDirection](#scrollbardirection) | No| Scrollbar direction in which scrollable components scroll.<br>Default value: **ScrollBarDirection.Vertical**|
| state | [BarState](ts-appendix-enums.md#barstate) | No| Scrollbar state.<br>Default value: **BarState.Auto**|

>  **NOTE**
>
> The **\<ScrollBar>** component defines the behavior style of the scrollable area, and its subnodes define the behavior style of the scrollbar.
> 
> This component is bound to a scrollable component through **scroller**, and can be used to scroll the scrollable component only when their directions are the same. The **\<ScrollBar>** component can be bound to only one scrollable component, and vice versa.

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
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

  build() {
    Column() {
      Stack({ alignContent: Alignment.End }) {
        Scroll(this.scroller) {
          Flex({ direction: FlexDirection.Column }) {
            ForEach(this.arr, (item: number) => {
              Row() {
                Text(item.toString())
                  .width('80%')
                  .height(60)
                  .backgroundColor('#3366CC')
                  .borderRadius(15)
                  .fontSize(16)
                  .textAlign(TextAlign.Center)
                  .margin({ top: 5 })
              }
            }, (item:number) => item.toString())
          }.margin({ right: 15 })
        }
        .width('90%')
        .scrollBar(BarState.Off)
        .scrollable(ScrollDirection.Vertical)
        ScrollBar({ scroller: this.scroller, direction: ScrollBarDirection.Vertical,state: BarState.Auto }) {
          Text()
            .width(20)
            .height(100)
            .borderRadius(10)
            .backgroundColor('#C0C0C0')
        }.width(20).backgroundColor('#ededed')
      }
    }
  }
}
```


![en-us_image_0000001232775585](figures/en-us_image_0000001232775585.gif)

# List

The **\<list>** component provides a list container that presents a series of list items arranged in a column with the same width. It supports presentations of the same type of data in a multiple and coherent row style, for example, images or text.

> **NOTE**
>
> - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
> - This component can produce a bounce effect only when there is more than one screen of content.


## Child Components

This component supports the [\<ListItem>](ts-container-listitem.md) child components.


## APIs

List(value?:{space?: number | string, initialIndex?: number, scroller?: Scroller})

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| space | number \| string | No| Spacing between list items.<br>Default value: **0**|
| initialIndex | number | No| Item displayed at the beginning of the viewport when the current list is loaded for the first time, that is, the first item to be displayed. If the value set is greater than the sequence number of the last item, the setting does not take effect.<br>Default value: **0**|
| scroller | [Scroller](ts-container-scroll.md#scroller) | No| Controller bound to the list to control the scrolling.|

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| listDirection | [Axis](ts-appendix-enums.md#axis) | Direction in which the list items are arranged.<br>Default value: **Axis.Vertical**|
| divider                      | {<br>strokeWidth: [Length](ts-types.md#length),<br>color?:[ResourceColor](ts-types.md#resourcecolor8),<br>startMargin?: [Length](ts-types.md#length),<br>endMargin?: [Length](ts-types.md#length)<br>} \| null | Style of the divider for the list items. By default, there is no divider.<br>- **strokeWidth**: stroke width of the divider.<br>- **color**: color of the divider.<br>- **startMargin**: distance between the divider and the start edge of the list.<br>- **endMargin**: distance between the divider and the end edge of the list.|
| scrollBar      | [BarState](ts-appendix-enums.md#barstate) | Scrollbar status.<br>Default value: **BarState.Off**|
| cachedCount | number                                   | Number of list items to be preloaded. For details, see [Minimizing White Blocks During Swiping](../../ui/ts-performance-improvement-recommendation.md#minimizing-white-blocks-during-swiping).<br>Default value: **1**|
| editMode | boolean | Whether to enter editing mode.<br>Default value: **false**|
| edgeEffect | [EdgeEffect](ts-appendix-enums.md#edgeeffect) | Scroll effect.<br>Default value: **EdgeEffect.Spring**|
| chainAnimation | boolean | Whether to display chained animations on this list when it slides or its top or bottom is dragged. The list items are separated with even space, and one item animation starts after the previous animation during basic sliding interactions. The chained animation effect is similar with spring physics.<br>Default value: **false**<br>- **false**: No chained animations are displayed.<br>- **true**: Chained animations are displayed.|
| multiSelectable<sup>8+</sup> | boolean | Whether to enable mouse frame selection.<br>Default value: **false**<br>- **false**: The mouse frame selection is disabled.<br>- **true**: The mouse frame selection is enabled.|

## Events

| Name| Description|
| -------- | -------- |
| onItemDelete(event: (index: number) => boolean) | Triggered when a list item is deleted.<br>- **index**: index of the deleted list item.|
| onScroll(event: (scrollOffset: number, scrollState: ScrollState) => void) | Triggered when the list scrolls.<br>- **scrollOffset**: scroll offset.<br>- **scrollState**: current scroll state. |
| onScrollIndex(event: (start: number, end: number) => void) | Triggered when scrolling starts.<br>- **start**: index of the scroll start position.<br>- **end**: index of the scroll end position. |
| onReachStart(event: () => void) | Triggered when the list reaches the start position.|
| onReachEnd(event: () => void) | Triggered when the list reaches the end position.|
| onScrollStop(event: () => void) | Triggered when the list stops scrolling.|
| onItemMove(event: (from: number, to: number) => boolean) | Triggered when a list item moves.<br>- **from**: index of the item before moving.<br>- **to**: index of the item after moving.|
| onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => ((() => any) \| void) | Triggered when a list element starts to be dragged.<br>- **event**: See [ItemDragInfo](ts-container-grid.md#itemdraginfo).<br>- **itemIndex**: index of the dragged list element.|
| onItemDragEnter(event: (event: ItemDragInfo) => void) | Triggered when the dragged item enters the drop target of the list.<br>- **event**: See [ItemDragInfo](ts-container-grid.md#itemdraginfo).|
| onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void) | Triggered when the dragged item moves over the drop target of the list.<br>- **event**: See [ItemDragInfo](ts-container-grid.md#itemdraginfo).<br>- **itemIndex**: initial position of the dragged item.<br>- **insertIndex**: index of the position to which the dragged item will be dropped.|
| onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void) | Triggered when the dragged item exits the drop target of the list.<br>- **event**: See [ItemDragInfo](ts-container-grid.md#itemdraginfo).<br>- **itemIndex**: index of the list item.|
| onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void) | Triggered when the dragged item is dropped on the drop target of the list.<br>- **event**: See [ItemDragInfo](ts-container-grid.md#itemdraginfo).<br>- **itemIndex**: initial position of the dragged item.<br>- **insertIndex**: index of the position to which the dragged item will be dropped.<br>- **isSuccess**: whether the dragged item is successfully dropped.|

## ScrollState

| Name    | Description                    |
| ------ | ------------------------- |
| Idle    | Not scrolling.          |
| Scroll   | Inertial scrolling.         |
| Fling   | Finger dragging.          |

>  **NOTE**
>
>  To enable the editable mode for a list, the following conditions must be met:
>
>  - **editMode** is set to **true**.
>
>  - The list is bound to the **onItemDelete** event and the event returns **true** in the event callback.
>
>  - The **editable** attribute of **ListItem** is set to **true**.
>
>  To enable dragging for a list item, the following conditions must be met:
>
>  - **editMode** is set to **true**.
>
>  - The list item is bound to the **onDragStart** event and the event returns a floating UI during event callback.


## Example

```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical) // Arrangement direction
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // Divider
        .edgeEffect(EdgeEffect.None) // No effect when the list scrolls to the edge.
        .chainAnimation(false) // Chained animations are disabled.
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
        .editMode(this.editFlag)
        .onItemDelete((index: number) => {
          console.info(this.arr[index] + 'Delete')
          this.arr.splice(index, 1)
          console.info(JSON.stringify(this.arr))
          this.editFlag = false
          return true
        }).width('90%')
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![en-us_image_0000001256978357](figures/en-us_image_0000001256978357.gif)

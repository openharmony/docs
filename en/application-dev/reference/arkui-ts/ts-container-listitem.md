# ListItem

The **\<ListItem>** component displays specific items in the list. It must be used together with **\<List>**.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component can contain a single child component.


## APIs

ListItem(value?: string)

Since API version 9, this API is supported in ArkTS widgets.

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| sticky<sup>(deprecated)</sup> | [Sticky](#stickydeprecated) | Sticky effect of the list item.<br>Default value: **Sticky.None**<br>This API is deprecated since API version 9. You are advised to use **sticky** of the [\<List>](ts-container-list.md#attributes) component.|
| editable<sup>(deprecated)</sup>  | boolean \| [EditMode](#editmode) | Whether to enter editing mode, where the list item can be deleted or moved.<br>This API is deprecated since API version 9.<br>Default value: **false**|
| selectable<sup>8+</sup> | boolean | Whether the current list item is selectable by mouse drag.<br>**NOTE**<br>This attribute takes effect only when mouse frame selection is enabled for the parent **\<List>** container.<br>Default value: **true**|
| swipeAction<sup>9+</sup> | {<br>start?: CustomBuilder,<br>end?:CustomBuilder,<br>edgeEffect?: [SwipeEdgeEffect](#swipeedgeeffect9),<br>} | Component displayed when the list item is swiped out from the screen edge.<br>- **start**: component on the left of the list item when the item is swiped to the right (in vertical list layout) or component above the list item when the item is swiped down (in horizontal list layout).<br>- **end**: component on the right of the list item when the item is swiped to the left (in vertical list layout) or component below the list item when the item is swiped up (in horizontal list layout).<br>- **edgeEffect**: scroll effect.<br>**NOTE**<br>The top level of the **@builder** function corresponding to **start** and **end** must be a single component and cannot be an **if/else**, **ForEach**, or **LazyForEach** statement.|

## Sticky<sup>(deprecated)</sup>
This API is deprecated since API version 9. You are advised to use [stickyStyle](ts-container-list.md#stickystyle9) of the **\<List>** component.
| Name| Description|
| -------- | -------- |
| None | The list item is not sticky.|
| Normal | The list item is sticky with no special effects.|
| Opacity | The list item is sticky with opacity changes.|

## EditMode

| Name    | Description       |
| ------ | --------- |
| None   | The editing operation is not restricted.   |
| Deletable | The list item can be deleted.|
| Movable | The list item can be moved.|

## SwipeEdgeEffect<sup>9+</sup>
| Name| Description|
| -------- | -------- |
| Spring | When the list item scrolls to the edge of the list, it can continue to scroll for a distance and rebound after being released.|
| None | The list item cannot scroll beyond the edge of the list|

## Events

| Name| Description|
| -------- | -------- |
| onSelect(event: (isSelected: boolean) =&gt; void)<sup>8+</sup> | Triggered when the selected state of the **\<ListItem>** changes.<br>**isSelected**: Returns **true** if the **\<ListItem>** is selected by mouse drag; returns **false** otherwise.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct ListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }
        }, item => item)
      }.width('90%')
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![en-us_image_0000001219864159](figures/en-us_image_0000001219864159.gif)

```ts
// xxx.ets
@Entry
@Component
struct ListItemExample2 {
  @State message: string = 'Hello World'

  @Builder itemEnd() {
    Row () {
      Button("Del").margin("4vp")
      Button("Set").margin("4vp")
    }.padding("4vp").justifyContent(FlexAlign.SpaceEvenly)
  }

  build() {
    Column() {
      List({space:10}) {
        ListItem() {
          Text(this.message)
          .width('100%')
          .height(100)
          .fontSize(16)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0xFFFFFF)
        }
        .swipeAction({ end:this.itemEnd})

        ListItem() {
          Text(this.message)
          .width('100%')
          .height(100)
          .fontSize(16)
          .textAlign(TextAlign.Center)
          .borderRadius(10)
          .backgroundColor(0xFFFFFF)
        }
        .swipeAction({ start:this.itemEnd})
      }
    }
    .padding(10)
    .backgroundColor(0xDCDCDC)
    .width('100%')
    .height('100%')
  }
}
```
![en-us_image_1501929990650](figures/en-us_image_1501929990650.jpg)

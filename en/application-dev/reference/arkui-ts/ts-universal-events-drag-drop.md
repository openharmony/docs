# Drag Event

A drag event is triggered when a component is dragged.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Events

| Name                                      | Bubbling Supported| Description                                    |
| ---------------------------------------- | ---- | ---------------------------------------- |
| onDragStart(event: (event: DragEvent, extraParams?: string) =&gt;  [CustomBuilder](ts-types.md#custombuilder8) \| DragItemInfo) | No   | Triggered when the component bound to the event is dragged for the first time.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see extraParam.<br>Return value: object being dragged, which is used for prompts displayed when the object is dragged.<br>A drag event can be triggered by a 150 ms long press. If the duration of a long-press gesture is set to less than or equal to 150 ms, the callback for the long-press gesture takes precedence. Otherwise, the callback for the drag event takes precedence.|
| onDragEnter(event: (event: DragEvent, extraParams?: string) =&gt; void) | No   | Triggered when the dragged item enters a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see extraParam.<br>This event is valid only when the **onDrop** event is listened to.|
| onDragMove(event: (event: DragEvent, extraParams?: string) =&gt; void) | No   | Triggered when the dragged item moves in a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see extraParam.<br>This event is valid only when the **onDrop** event is listened to.|
| onDragLeave(event: (event: DragEvent, extraParams?: string) =&gt; void) | No   | Triggered when the dragged item leaves a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see extraParam.<br>This event is valid only when the **onDrop** event is listened to.|
| onDrop(event: (event: DragEvent, extraParams?: string) =&gt; void) | No   | Triggered when the dragged item is dropped on a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see extraParam.|

## DragItemInfo

| Name     | Type                                    | Mandatory  | Description                               |
| --------- | ---------------------------------------- | ---- | --------------------------------- |
| pixelMap  | [PixelMap](../apis/js-apis-image.md#pixelmap7) | No   | Image to be displayed during dragging.                    |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | No   | Custom building for drawing. If **pixelMap** is set, this attribute is ignored.|
| extraInfo | string                                   | No   | Extra information of the dragged item.                          |


## extraParam

Provides additional information required for dragging an item.

**extraParam** is a string converted from a JSON object. You can obtain the following attributes using the JSON object converted from **Json.parse**.

| Name         | Type  | Description                                      |
| ------------- | ------ | ---------------------------------------- |
| selectedIndex | number | Index of the dragged item in the parent container. The value of **selectedindex** starts from **0**.<br>This attribute is valid only in the **ListItem** component.|
| insertIndex   | number | Index of the element into which the dragged item is dropped in the **List** component. The value of **insertIndex** starts from **0**.<br>This attribute is valid only in the drag event of the **List** component.|

## DragEvent

| Sample Code    | Return Value Type | Description            |
| ------ | ------ | ---------------- |
| getX() | number | X-coordinate of the item that is being dragged, in vp.|
| getY() | number | Y-coordinate of the item that is being dragged, in vp.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct DragExample {
  @State numbers: string[] = ['one', 'two', 'three', 'four', 'five', 'six']
  @State text: string = ''
  @State bool: boolean = false
  @State bool1: boolean = false
  @State size: string = ''
  @State appleVisible: Visibility = Visibility.Visible
  @State orangeVisible: Visibility = Visibility.Visible
  @State bananaVisible: Visibility = Visibility.Visible
  @State select: number = 0
  @State currentIndex: number = 0

  @Builder pixelMapBuilder() {
    Column() {
      Text(this.text)
        .width('50%').height(60).fontSize(16).borderRadius(10)
        .textAlign(TextAlign.Center).backgroundColor(Color.Yellow)
    }
  }

  build() {
    Column() {
      Text('There are three Text elements here')
        .fontSize(12).fontColor(0xCCCCCC).width('90%')
        .textAlign(TextAlign.Start).margin(5)
      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceAround }) {
        Text('apple').width('25%').height(35).fontSize(16)
          .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          .visibility(this.appleVisible)
          .onDragStart(() => {
            this.bool = true
            this.text = 'apple'
            this.appleVisible = Visibility.Hidden
            return this.pixelMapBuilder
          })
        Text('orange').width('25%').height(35).fontSize(16)
          .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          .visibility(this.orangeVisible)
          .onDragStart(() => {
            this.bool = true
            this.text = 'orange'
            this.orangeVisible = Visibility.Hidden
            return this.pixelMapBuilder
          })
        Text('banana').width('25%').height(35).fontSize(16)
          .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          .visibility(this.bananaVisible)
          .onDragStart((event: DragEvent, extraParams: string) => {
            console.log('Text onDragStarts, ' + extraParams)
            this.bool = true
            this.text = 'banana'
            this.bananaVisible = Visibility.Hidden
            return this.pixelMapBuilder
          })
      }.border({ width: 1 }).width('90%').padding({ top: 10, bottom: 10 }).margin(10)

      Text('This is a List element').fontSize(12)
        .fontColor(0xCCCCCC).width('90%')
        .textAlign(TextAlign.Start).margin(15)
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.numbers, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(80).fontSize(16).borderRadius(10)
              .textAlign(TextAlign.Center).backgroundColor(0xAFEEEE)
          }
          .onDragStart((event: DragEvent, extraParams: string) => {
            console.log('ListItem onDragStarts, ' + extraParams)
            var jsonString = JSON.parse(extraParams)
            this.bool1 = true
            this.text = this.numbers[jsonString.selectedIndex]
            this.select = jsonString.selectedIndex
            return this.pixelMapBuilder
          })
        }, item => item)
      }
      .editMode(true)
      .height('50%').width('90%').border({ width: 1 })
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onDragEnter((event: DragEvent, extraParams: string) => {
        console.log('List onDragEnter, ' + extraParams)
      })
      .onDragMove((event: DragEvent, extraParams: string) => {
        console.log('List onDragMove, ' + extraParams)
      })
      .onDragLeave((event: DragEvent, extraParams: string) => {
        console.log('List onDragLeave, ' + extraParams)
      })
      .onDrop((event: DragEvent, extraParams: string) => {
        var jsonString = JSON.parse(extraParams)
        if (this.bool) {
          this.numbers.splice(jsonString.insertIndex, 0, this.text)
          this.bool = false
        } else if (this.bool1) {
          this.numbers.splice(jsonString.selectedIndex, 1)
          this.numbers.splice(jsonString.insertIndex, 0, this.text)
          this.bool = false
          this.bool1 = false
        }
      })
    }.width('100%').height('100%').padding({ top: 20 }).margin({ top: 20 })
  }
}
```

![en-us_image_0000001212218450](figures/en-us_image_0000001212218450.gif)

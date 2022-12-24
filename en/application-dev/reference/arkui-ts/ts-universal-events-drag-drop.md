# Drag Event

A drag event is triggered when a component is dragged.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Events

| Name                                      | Bubbling Supported| Description                                    |
| ---------------------------------------- | ---- | ---------------------------------------- |
| onDragStart(event: (event: [DragEvent](#dragevent), extraParams?: string) =&gt;  [CustomBuilder](ts-types.md#custombuilder8) \| [DragItemInfo](#dragiteminfo) | No   | Triggered when the component bound to the event is dragged for the first time.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>Return value: object being dragged, which is used for prompts displayed when the object is dragged.<br>A drag event can be triggered by a 150 ms long press. If the duration of a long-press gesture is set to less than or equal to 150 ms, the callback for the long-press gesture takes precedence. Otherwise, the callback for the drag event takes precedence.|
| onDragEnter(event: (event: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No   | Triggered when the dragged item enters a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>This event is valid only when the **onDrop** event is listened to.|
| onDragMove(event: (event: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No   | Triggered when the dragged item moves in a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>This event is valid only when the **onDrop** event is listened to.|
| onDragLeave(event: (event: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No   | Triggered when the dragged item leaves a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>This event is valid only when the **onDrop** event is listened to.|
| onDrop(event: (event: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No   | Triggered when the dragged item is dropped on a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.|

## DragItemInfo

| Name     | Type                                    | Mandatory  | Description                               |
| --------- | ---------------------------------------- | ---- | --------------------------------- |
| pixelMap  | [PixelMap](../apis/js-apis-image.md#pixelmap7) | No   | Image to be displayed during dragging.                    |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | No   | Custom component to display during dragging. If **pixelMap** is set, this attribute is ignored.|
| extraInfo | string                                   | No   | Extra information of the dragged item.                          |


## extraParams

Provides additional information required for dragging an item.

**extraParams** is a string converted from a JSON object. You can obtain the following attributes using the JSON object converted from **Json.parse**.

| Name         | Type  | Description                                      |
| ------------- | ------ | ---------------------------------------- |
| selectedIndex | number | Index of the dragged item in the parent container. The value of **selectedindex** starts from **0**.<br>This attribute is valid only in the drag event of the **\<ListItem>** component.|
| insertIndex   | number | Index of the element into which the dragged item is dropped in the **List** component. The value of **insertIndex** starts from **0**.<br>This attribute is valid only in the drag event of the **\<List>** component.|

### DragEvent

| Name    | Type | Description            |
| ------ | ------ | ---------------- |
| getX() | number | X-coordinate of the item that is being dragged, in vp.|
| getY() | number | Y-coordinate of the item that is being dragged, in vp.|

## Example

```ts
// xxx.ets
@Extend(Text) function textStyle () {
  .width('25%')
  .height(35)
  .fontSize(16)
  .textAlign(TextAlign.Center)
  .backgroundColor(0xAFEEEE)
}

@Entry
@Component
struct DragExample {
  @State numbers: string[] = ['one', 'two', 'three', 'four', 'five', 'six']
  @State text: string = ''
  @State bool: boolean = true
  @State eventType: string = ''
  @State appleVisible: Visibility = Visibility.Visible
  @State orangeVisible: Visibility = Visibility.Visible
  @State bananaVisible: Visibility = Visibility.Visible
  private dragList: string[] = ['apple', 'orange', 'banana']
  @State fruitVisible: Visibility[] = [Visibility.Visible, Visibility.Visible, Visibility.Visible]
  @State index: number = 0

  // Customize the content displayed during dragging.
  @Builder pixelMapBuilder() {
    Column() {
      Text(this.text)
        .width('50%')
        .height(60)
        .fontSize(16)
        .borderRadius(10)
        .textAlign(TextAlign.Center)
        .backgroundColor(Color.Yellow)
    }
  }

  build() {
    Column() {
      Text('There are three Text elements here')
        .fontSize(12)
        .fontColor(0xCCCCCC)
        .width('90%')
        .textAlign(TextAlign.Start)
        .margin(5)
      Row({ space: 15 }) {
        ForEach(this.dragList, (item, index) => {
          Text(item)
            .textStyle()
            .visibility(this.fruitVisible[index])
            .onDragStart(() => {
              this.bool = true
              this.text = item
              this.fruitVisible[index] = Visibility.None
              return this.pixelMapBuilder
            })
            .onTouch((event: TouchEvent) => {
              if (event.type === TouchType.Down) {
                this.eventType = 'Down'
                this.index = index
              }
              if (event.type === TouchType.Up) {
                this.eventType = 'Up'
                if (this.bool) {
                  this.fruitVisible[index] = Visibility.Visible
                }
              }
            })
        })
      }.padding({ top: 10, bottom: 10 }).margin(10)

      Text('This is a List element')
        .fontSize(12)
        .fontColor(0xCCCCCC)
        .width('90%')
        .textAlign(TextAlign.Start)
        .margin(15)
      List({ space: 20 }) {
        ForEach(this.numbers, (item) => {
          ListItem() {
            Text(item)
              .width('100%')
              .height(80)
              .fontSize(16)
              .borderRadius(10)
              .textAlign(TextAlign.Center)
              .backgroundColor(0xAFEEEE)
          }
        }, item => item)
      }
      .editMode(true)
      .height('50%')
      .width('90%')
      .border({ width: 1 })
      .padding(15)
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onDragEnter((event: DragEvent, extraParams: string) => {
        console.log('List onDragEnter, ' + extraParams + 'X:' + event.getX() + 'Y:' + event.getY())
      })
      .onDragMove((event: DragEvent, extraParams: string) => {
        console.log('List onDragMove, ' + extraParams + 'X:' + event.getX() + 'Y:' + event.getY())
      })
      .onDragLeave((event: DragEvent, extraParams: string) => {
        console.log('List onDragLeave, ' + extraParams + 'X:' + event.getX() + 'Y:' + event.getY())
      })
      .onDrop((event: DragEvent, extraParams: string) => {
        let jsonString = JSON.parse(extraParams);
        if (this.bool) {
          // Insert an element using the splice method.
          this.numbers.splice(jsonString.insertIndex, 0, this.text)
          this.bool = false
        }
        this.fruitVisible[this.index] = Visibility.None
      })
    }.width('100%').height('100%').padding({ top: 20 }).margin({ top: 20 })
  }
}
```

![en-us_image_0000001252667389](figures/en-us_image_0000001252667389.gif)

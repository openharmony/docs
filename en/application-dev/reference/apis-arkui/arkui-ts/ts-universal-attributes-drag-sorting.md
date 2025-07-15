# Drag-and-Drop Sorting

By using **ForEach**, **LazyForEach**, or **Repeat** within a **List** component and setting up the **onMove** event, you can implement drag-and-drop sorting. When the drag-and-drop gesture is released, if any item's position changes, the **onMove** event is triggered, which reports the original index and target index of the relocated item. In the **onMove** event, the data source must be updated based on the reported start index and target index. Ensure that only the order of the data changes so that the drop animation can be executed properly.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## onMove

onMove(handler: Optional\<OnMoveHandler\>)

Invoked when data is moved during drag-and-drop sorting. This callback is effective only when the parent container component is [List](./ts-container-list.md) and each iteration of **ForEach**, **LazyForEach**, or **Repeat** generates a **ListItem** component. It allows you to define custom drag actions and handle various drag events.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| handler  | Optional\<[OnMoveHandler](#onmovehandler)\> | Yes  | Drag operation.|

## onMove<sup>20+</sup>

onMove(handler: Optional\<OnMoveHandler\>, eventHandler: ItemDragEventHandler)

Invoked when data is moved during drag-and-drop sorting. This callback is effective only when the parent container component is [List](./ts-container-list.md) and each iteration of **ForEach**, **LazyForEach**, or **Repeat** generates a **ListItem** component. It allows you to define custom drag actions and handle various drag events.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| handler  | Optional\<[OnMoveHandler](#onmovehandler)\> | Yes  | Drag operation.|
| eventHandler  | [ItemDragEventHandler](#itemdrageventhandler20) | Yes  | Callback invoked when the drag occurs.|

## OnMoveHandler

type OnMoveHandler = (from: number, to: number) => void

Defines the callback triggered when data is moved during drag-and-drop sorting.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| from  | number | Yes  | Start index of the drag operation. The value range is [0, data source length - 1].|
| to  | number | Yes  | End index of the drag operation. The value range is [0, data source length - 1].|

## ItemDragEventHandler<sup>20+</sup>

Defines callbacks for drag events on a data source, allowing you to respond to different drag operations.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| onLongPress  |  [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | No | Callback triggered when an item is long-pressed.<br>- **index**: index of the target when the long press occurs.|
| onDragStart  | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | No  | Callback triggered when dragging starts.<br>- **index**: index of the target when dragging starts.|
| onMoveThrough  | [OnMoveHandler](#onmovehandler) | No  | Callback triggered when the dragged item moves over other items.|
| onDrop  | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | No  | Callback triggered when dragging ends.<br>- **index**: index of the target when dragging ends.|

## Example

### Example 1: Using onMove for Drag and Drop Operations

This example demonstrates how to use **onMove** for drag and drop with **ForEach** in a **List** component.

```ts
@Entry
@Component
struct ForEachSort {
  @State arr: Array<string> = [];

  build() {
    Row() {
      List() {
        ForEach(this.arr, (item: string) => {
          ListItem() {
            Text(item.toString())
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .size({height: 100, width: '100%'})
          }.margin(10)
          .borderRadius(10)
          .backgroundColor('#FFFFFFFF')
        }, (item: string) => item)
          .onMove((from:number, to:number) => {
            let tmp = this.arr.splice(from, 1);
            this.arr.splice(to, 0, tmp[0]);
          })
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#FFDCDCDC')
    }
  }
  aboutToAppear(): void {
    for (let i = 0; i < 100; i++) {
      this.arr.push(i.toString());
    }
  }
}
```

### Example 2: Using onMove with Drag Event Callbacks

This example demonstrates how to use **onMove** with additional drag event callbacks when **ForEach** is used in a **List** component.

```ts
// xxx.ets
@Entry
@Component
struct ListOnMoveExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6];

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text('First list' + item)
              .width('100%')
              .height(80)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
          .onMove((from: number, to: number) => {
            let tmp = this.arr.splice(from, 1);
            this.arr.splice(to, 0, tmp[0]);
            console.log('List onMove From: ' + from);
            console.log('List onMove To: ' + to);
          },
            {
              onLongPress: (index: number) => {
                console.log('List onLongPress: ' + index);
              },
              onDrop: (index: number) => {
                console.log('List onDrop: ' + index);
              },
              onDragStart: (index: number) => {
                console.log('List onDragStart: ' + index);
              },
              onMoveThrough: (from: number, to: number) => {
                console.log('List onMoveThrough From: ' + from);
                console.log('List onMoveThrough To: ' + to);
              }
            }
          )
      }.width('90%')
        .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

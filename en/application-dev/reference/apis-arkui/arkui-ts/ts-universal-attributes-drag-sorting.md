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

## OnMoveHandler

type OnMoveHandler = (from: number, to: number) => void;

Defines the callback triggered when data is moved during drag-and-drop sorting.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| from  | number | Yes  | Start index of the drag operation. The value range is [0, data source length - 1].|
| to  | number | Yes  | End index of the drag operation. The value range is [0, data source length - 1].|

## Example

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

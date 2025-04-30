# ForEach

**ForEach** enables rendering of repeated content based on array type data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

For details about the development, see [ForEach: Rendering Repeated Content](../../../quick-start/arkts-rendering-control-foreach.md).

## APIs

ForEach(arr: Array\<any\>,itemGenerator: (item: any, index: number) => void,keyGenerator?: (item: any, index: number) => string,)

**ForEach** enables rendering of repeated content based on array type data. It must be used in a container component, and the component it returns must be one allowed inside the container component. For example, for rendering of list items, **ForEach** must be used in the [List](../../../reference/apis-arkui/arkui-ts/ts-container-list.md) component.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                   | Mandatory| Description                                                        |
| ------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| arr           | Array\<Object\>                         | Yes  | Data source, which is an array.<br>**NOTE**<br>- You can set this parameter to an empty array. In this case, no child component is created.<br>- You can also set this parameter to a function whose return value is an array, for example, **arr.slice (1, 3)**. However, the set function cannot change any state variables including the array itself. For example, **Array.splice**, **Array.sort**, and **Array.reverse** functions are not allowed, as they may change the array.|
| itemGenerator | (item: Object, index: number) => void   | Yes  | Component generator.<br>- It generates a component for each data item in an array. <br>- **item**: data item in the **arr** array.<br>- (Optional) **index**: index of the data item in the **arr** array.<br>**NOTE**<br>- The type of the created component must be the one allowed inside the parent container component of **ForEach**. For example, a **ListItem** component is allowed only when the parent container component of **ForEach** is **List**.|
| keyGenerator  | (item: Object, index: number) => string | No  | Key generator.<br>- It generates a unique and persistent key for each array item of the data source **arr**. The return value is the key generation rule you customize.<br>- **item**: data item in the **arr** array.<br>- (Optional) **index**: index of the data item in the **arr** array.<br>**NOTE**<br>- If this function is not specified, the default key generator of the framework is used: **(item: T, index: number) => { return index + '__' + JSON.stringify(item); }**.<br>- The key generator should not change any component state.|

> **NOTE**
>
> - The **itemGenerator** function can contain an **if/else** statement, and an **if/else** statement can contain **ForEach**.
> - On initial rendering, **ForEach** loads all data of the data source, creates a component for each data item, and mounts the created components to the render tree. If the data source contains a large number of items or performance is a critical concern, you are advised to use **LazyForEach**.

## Properties

Inherited from [DynamicNode](#dynamicnode12).

## DynamicNode<sup>12+</sup>

Defines a node.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onMove<sup>12+</sup>

onMove(handler: Optional\<OnMoveHandler\>): T;

Invoked when data is moved during drag and drop sorting. This callback is only applicable in a **List** component where each **ForEach** iteration generates a **ListItem** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| handler  | Optional\<[OnMoveHandler](#onmovehandler)\> | Yes  | Drag operation.|

### onMove<sup>20+</sup>

onMove(handler: Optional\<OnMoveHandler\>, eventHandler: ItemDragEventHandler): T

Invoked when data is moved during drag and drop sorting. This callback is only applicable in a **List** component where each **ForEach** iteration generates a **ListItem** component. It allows you to define custom drag actions and handle various drag events.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| handler  | Optional\<[OnMoveHandler](#onmovehandler)\> | Yes  | Drag operation.|
| eventHandler  | [ItemDragEventHandler](#itemdrageventhandler20) | Yes  | Callback invoked when the drag occurs.|

### ItemDragEventHandler<sup>20+</sup>

Defines callbacks for drag events on a data source, allowing you to respond to different drag operations.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| onLongPress  |  [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | Yes  | Callback triggered when an item is long-pressed.<br>- **Index**: index of the long-pressed item.|
| onDragStart  | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | Yes  | Callback triggered when dragging starts.<br>- **Index**: index of the current item when the dragging starts.|
| onMoveThrough  | [OnMoveHandler](#onmovehandler) | Yes  | Callback triggered when the dragged item moves over other items.|
| onDrop  | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<number\> | Yes  | Callback triggered when dragging ends.<br>- **Index**: index of the current item when the dragging ends.|

### OnMoveHandler

type OnMoveHandler = (from: number, to: number) => void

Defines the callback triggered when data is moved during drag and drop sorting.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| from  | number | Yes  | Start index of the data before movement.|
| to  | number | Yes  | Target index of the data after movement.|

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
              .size({height: 100, width: "100%"})
          }.margin(10)
          .borderRadius(10)
          .backgroundColor("#FFFFFFFF")
        }, (item: string) => item)
          .onMove((from:number, to:number) => {
            let tmp = this.arr.splice(from, 1);
            this.arr.splice(to, 0, tmp[0]);
          })
      }
      .width('100%')
      .height('100%')
      .backgroundColor("#FFDCDCDC")
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
              onMoveThrough: (from: number, Through: number) => {
                console.log('List onMoveThrough From: ' + from);
                console.log('List onMoveThrough To: ' + Through);
              }
            }
          )
      }.width('90%')
        .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

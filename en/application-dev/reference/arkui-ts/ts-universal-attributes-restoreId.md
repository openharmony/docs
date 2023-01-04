# restoreId

The **restoreId** attribute identifies a component in distributed migration scenarios. It can be used to restore the component to a specific state on a remote device.

>  **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| restoreId | number | ID of the component used for device matching during distributed migration. This ID must be unique within an application.|

## Components with Distributed Migration Support

| Name| Initial API Version| Migration Status|
| -------- | -------- | -------- |
| List      | 8 | The index of the list item displayed at the top of the list on the current device will be migrated to the remote device. After the migration, the list item that matches the index is displayed at the top of the list on the remote device.|
| Grid      | 9 | The index of the grid item displayed at the top of the grid on the current device will be migrated to the remote device. After the migration, the grid item that matches the index is displayed at the top of the grid on the remote device. The position of the scrollbar cannot be migrated.|
| Scroll    | 9 | The absolute distance with the top edge for scrolling will be migrated. Due to layout inconsistency resulting from differences in the display specifications between devices, the migration effect may be affected.|
| TextArea  | 9 | The text content and the position of the caret will be migrated.|
| TextInput | 9 | The text content and the position of the caret will be migrated.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct RestoreIdExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  build() {
    Column() {
      List({ space: 20 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(Color.Pink)
          }
        }, item => item)
      }
      .restoreId(1)
    }
  }
}
```

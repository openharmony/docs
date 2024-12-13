# restoreId

The **restoreId** attribute identifies a component in hopping scenarios. It can be used to restore the component to a specific state on a remote device.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## restoreId

restoreId(value: number)

Sets the ID of the component used for device matching during hopping.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | ID of the component used for device matching during hopping. This ID must be unique within an application.|

## Components with Hopping Support

| Name     | Initial API Version| Description                                    |
| --------- | ---- | ---------------------------------------- |
| List      | 8    | The index of the top list item on the current device is migrated to the remote device. After the migration, the corresponding list item is pinned to the top on the remote device.|
| Grid      | 9    | The index of the top grid item on the current device is migrated to the remote device. After the migration, the corresponding grid item is pinned to the top on the remote device. Note that the position of the scrollbar cannot be migrated.|
| Scroll    | 9    | The absolute scroll distance from the top edge is migrated. Be aware that layout differences between devices may affect hopping results.|
| WaterFlow | 11   | The index of the top water flow item on the current device is migrated to the remote device. After the migration, the corresponding water flow item is pinned to the top on the remote device. The offset (in vp) of the top water flow item relative to the **WaterFlow** component along the main axis is also migrated.|

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
        ForEach(this.arr, (item:number) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(Color.Pink)
          }
        }, (item:number) => (item.toString()))
      }
      .restoreId(1)
    }
  }
}
```

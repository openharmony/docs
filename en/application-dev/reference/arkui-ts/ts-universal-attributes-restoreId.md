# restoreId

The **restoreId** attribute identifies a component in distributed migration scenarios. It can be used to restore the component to a specific state on a remote device.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## restoreId

restoreId(value: number)

ID of the component used for device matching during distributed migration.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | ID of the component used for device matching during distributed migration. This ID must be unique within an application.|

## Components with Distributed Migration Support

| Name     | Initial API Version| Description                                    |
| --------- | ---- | ---------------------------------------- |
| List      | 8    | The index of the list item displayed at the top of the list on the current device will be migrated to the remote device. After the migration, the list item that matches the index is displayed at the top of the list on the remote device.|
| Grid      | 9    | The index of the grid item displayed at the top of the grid on the current device will be migrated to the remote device. After the migration, the grid item that matches the index is displayed at the top of the grid on the remote device. The position of the scrollbar cannot be migrated.|
| Scroll    | 9    | The absolute distance with the top edge for scrolling will be migrated. The migration effect may be affected by the layout inconsistency resulting from differences in the display specifications between devices.|
| WaterFlow | 11   | The index of the **\<FlowItem>** component (child) displayed at the top of the **\<WaterFlow>** component (parent) on the current device, along with the offset (in vp) of the child relative to the main axis of the parent, will be migrated to the remote device. After the migration, the **\<FlowItem>** component that matches the migrated index is displayed on the top of the **\<WaterFlow>** component on the remote device.|

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

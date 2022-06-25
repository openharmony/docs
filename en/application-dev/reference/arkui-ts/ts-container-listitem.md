# ListItem


> **NOTE**<br>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;ListItem&gt;** component displays specific items in the list. Its width occupies the **&lt;List&gt;** component by default and must be used together with **&lt;List&gt;**.


## Required Permissions

None


## Child Components

This component can contain a single child component.


## APIs

ListItem()


## Attributes

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| sticky | Sticky | Sticky.None | Sticky effect of the list item. For details, see **Sticky** enums. |
| editable | boolean | false | Whether the list item is editable. A list item can be deleted in editing mode. |
| selectable<sup>8+</sup> | boolean | true | Whether the current **ListItem;** is selectable by the mouse.<br/>**NOTE**<br/>This attribute takes effect only when mouse frame selection is enabled for the parent **&lt;List&gt;** container. |

- Sticky enums
  | Name | Description | 
  | -------- | -------- |
  | None | No sticky. | 
  | Normal | The list item is sticky. | 


## Events

| Name | Description | 
| -------- | -------- |
| onSelect(callback: (isSelected: boolean) =&gt; any)<sup>8+</sup> | Triggered when the selected state of the **&lt;ListItem&gt;** changes.<br/>**isSelected**: Returns **true** if the **&lt;ListItem&gt;** is selected by the mouse; returns **false** otherwise. | 


## Example


```
@Entry
@Component
struct ListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Text('sticky:Normal , click me edit list')
            .width('100%').height(40).fontSize(12).fontColor(0xFFFFFF)
            .textAlign(TextAlign.Center).backgroundColor(0x696969)
            .onClick(() => {
              this.editFlag = !this.editFlag
            })
        }.sticky(Sticky.Normal)

        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }.editable(this.editFlag)
        }, item => item)
      }
      .editMode(true)
      .onItemDelete((index: number) => {
        console.info(this.arr[index - 1] + 'Delete')
        this.arr.splice(index - 1,1)
        this.editFlag = false
        return true
      }).width('90%')
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![en-us_image_0000001257138339](figures/en-us_image_0000001257138339.gif)

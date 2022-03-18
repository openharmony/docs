# ListItem


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;ListItem&gt;** component displays specific items in the list. Its width occupies the **&lt;List&gt;** component by default and must be used together with **&lt;List&gt;**.


## Required Permissions

None


## Child Components

This component can contain a single child component.


## APIs

ListItem()


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| sticky | Sticky | Sticky.None | Sticky&nbsp;effect&nbsp;of&nbsp;the&nbsp;list&nbsp;item.&nbsp;For&nbsp;details,&nbsp;see Sticky enums. |
| editable | boolean | false | Whether&nbsp;the&nbsp;list&nbsp;item&nbsp;is&nbsp;editable.&nbsp;A&nbsp;list&nbsp;item&nbsp;can&nbsp;be&nbsp;deleted&nbsp;in&nbsp;editing&nbsp;mode. |
| selectable<sup>8+</sup> | boolean | true | Whether&nbsp;the&nbsp;current&nbsp;**&lt;ListItem&gt;**&nbsp;is&nbsp;selectable&nbsp;by&nbsp;the&nbsp;mouse.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;attribute&nbsp;takes&nbsp;effect&nbsp;only&nbsp;when&nbsp;mouse&nbsp;frame&nbsp;selection&nbsp;is&nbsp;enabled&nbsp;for&nbsp;the&nbsp;parent&nbsp;**&lt;List&gt;**&nbsp;container. |

- Sticky enums
    | Name | Description | 
  | -------- | -------- |
  | None | No&nbsp;sticky. | 
  | Normal | The&nbsp;list&nbsp;item&nbsp;is&nbsp;sticky. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onSelect(callback:&nbsp;(isSelected:&nbsp;boolean)&nbsp;=&gt;&nbsp;any)<sup>8+</sup> | Triggered&nbsp;when&nbsp;the&nbsp;selected&nbsp;state&nbsp;of&nbsp;the&nbsp;**&lt;ListItem&gt;**&nbsp;changes.<br/>**isSelected**:&nbsp;Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;**&lt;ListItem&gt;**&nbsp;is&nbsp;selected&nbsp;by&nbsp;the&nbsp;mouse;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 


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

# List


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;List&gt;** component provides a list container that presents a series of list items arranged in a column with the same width. It supports presentations of the same type of data in a multiple and coherent row style, for example, images or text.


## Required Permissions

None


## Child Components

This component contains the child component [<ListItem>](../reference/arkui-ts/ts-container-listitem.md).


## APIs

List(value:{space?: number, initialIndex?: number})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | space | number | No | 0 | Spacing&nbsp;between&nbsp;list&nbsp;items. | 
  | initialIndex | number | No | 0 | Item&nbsp;displayed&nbsp;at&nbsp;the&nbsp;beginning&nbsp;of&nbsp;the&nbsp;component&nbsp;when&nbsp;the&nbsp;current&nbsp;list&nbsp;is&nbsp;loaded&nbsp;for&nbsp;the&nbsp;first&nbsp;time,&nbsp;that&nbsp;is,&nbsp;the&nbsp;first&nbsp;item&nbsp;to&nbsp;be&nbsp;displayed.&nbsp;If&nbsp;the&nbsp;configured&nbsp;sequence&nbsp;number&nbsp;is&nbsp;greater&nbsp;than&nbsp;the&nbsp;sequence&nbsp;number&nbsp;of&nbsp;the&nbsp;last&nbsp;item,&nbsp;the&nbsp;setting&nbsp;does&nbsp;not&nbsp;take&nbsp;effect. | 


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| listDirection | [Axis](ts-appendix-enums.md#axis-enums) | Vertical | Direction&nbsp;in&nbsp;which&nbsp;the&nbsp;list&nbsp;items&nbsp;are&nbsp;arranged.&nbsp;For&nbsp;details,&nbsp;see&nbsp;**Axis**&nbsp;enums. |
| divider | {<br/>strokeWidth:&nbsp;Length,<br/>color?:Color,<br/>startMargin?:&nbsp;Length,<br/>endMargin?:&nbsp;Length<br/>} | - | Style&nbsp;of&nbsp;the&nbsp;divider&nbsp;for&nbsp;the&nbsp;list&nbsp;items.&nbsp;By&nbsp;default,&nbsp;there&nbsp;is&nbsp;no&nbsp;divider.<br/>**strokeWidth**:&nbsp;stroke&nbsp;width&nbsp;of&nbsp;the&nbsp;divider.<br/>**color**:&nbsp;color&nbsp;of&nbsp;the&nbsp;divider.<br/>**startMargin**:&nbsp;distance&nbsp;between&nbsp;the&nbsp;divider&nbsp;and&nbsp;the&nbsp;start&nbsp;of&nbsp;the&nbsp;list.<br/>**endMargin**:&nbsp;distance&nbsp;between&nbsp;the&nbsp;divider&nbsp;and&nbsp;the&nbsp;end&nbsp;of&nbsp;the&nbsp;list. |
| editMode | boolean | false | Whether&nbsp;the&nbsp;**&lt;List&gt;**&nbsp;component&nbsp;is&nbsp;in&nbsp;editable&nbsp;mode. |
| edgeEffect | EdgeEffect | EdgeEffect.Spring | Sliding&nbsp;effect.&nbsp;For&nbsp;details,&nbsp;see&nbsp;EdgeEffect&nbsp;enums. |
| chainAnimation | boolean | false | Whether&nbsp;to&nbsp;display&nbsp;chained&nbsp;animations&nbsp;on&nbsp;this&nbsp;list&nbsp;when&nbsp;it&nbsp;slides&nbsp;or&nbsp;its&nbsp;top&nbsp;and&nbsp;bottom&nbsp;are&nbsp;dragged.&nbsp;The&nbsp;list&nbsp;items&nbsp;are&nbsp;separated&nbsp;with&nbsp;even&nbsp;space,&nbsp;and&nbsp;one&nbsp;item&nbsp;animation&nbsp;starts&nbsp;after&nbsp;the&nbsp;previous&nbsp;animation&nbsp;during&nbsp;basic&nbsp;sliding&nbsp;interactions.&nbsp;The&nbsp;chained&nbsp;animation&nbsp;effect&nbsp;is&nbsp;similar&nbsp;with&nbsp;spring&nbsp;physics.<br/>-&nbsp;**false**:&nbsp;No&nbsp;chained&nbsp;animations&nbsp;are&nbsp;displayed.<br/>-&nbsp;**true**:&nbsp;Chained&nbsp;animations&nbsp;are&nbsp;displayed. |
| multiSelectable<sup>8+</sup> | boolean | false | Whether&nbsp;to&nbsp;enable&nbsp;mouse&nbsp;frame&nbsp;selection.<br/>-&nbsp;**false**:&nbsp;The&nbsp;mouse&nbsp;frame&nbsp;selection&nbsp;is&nbsp;disabled.<br/>-&nbsp;**true**:&nbsp;The&nbsp;mouse&nbsp;frame&nbsp;selection&nbsp;is&nbsp;disabled. |
| restoreId<sup>8+</sup> | number | - | Migration&nbsp;ID&nbsp;of&nbsp;the&nbsp;component.&nbsp;During&nbsp;application&nbsp;migration,&nbsp;the&nbsp;status&nbsp;of&nbsp;the&nbsp;component&nbsp;is&nbsp;migrated&nbsp;to&nbsp;the&nbsp;component&nbsp;with&nbsp;the&nbsp;same&nbsp;migration&nbsp;ID&nbsp;on&nbsp;the&nbsp;peer&nbsp;end.<br/>For&nbsp;a&nbsp;**&lt;List&gt;**&nbsp;component,&nbsp;the&nbsp;status&nbsp;includes&nbsp;the&nbsp;item&nbsp;serial&nbsp;number&nbsp;displayed&nbsp;at&nbsp;the&nbsp;start&nbsp;position. |

- EdgeEffect enums
    | Name | Description | 
  | -------- | -------- |
  | Spring | Similar&nbsp;to&nbsp;the&nbsp;physical&nbsp;dynamic&nbsp;effect&nbsp;of&nbsp;a&nbsp;spring.&nbsp;After&nbsp;scrolling&nbsp;to&nbsp;the&nbsp;edge,&nbsp;you&nbsp;can&nbsp;continue&nbsp;to&nbsp;scroll&nbsp;for&nbsp;a&nbsp;distance&nbsp;based&nbsp;on&nbsp;the&nbsp;initial&nbsp;speed&nbsp;or&nbsp;by&nbsp;touching&nbsp;the&nbsp;knob&nbsp;of&nbsp;the&nbsp;scrollbar.&nbsp;After&nbsp;you&nbsp;release&nbsp;your&nbsp;hand,&nbsp;the&nbsp;knob&nbsp;is&nbsp;rebounded. | 
  | None | No&nbsp;effect&nbsp;after&nbsp;the&nbsp;scroll&nbsp;bar&nbsp;is&nbsp;moved&nbsp;to&nbsp;the&nbsp;edge. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onItemDelete(index:&nbsp;number)&nbsp;=&gt;&nbsp;boolean | Triggered&nbsp;when&nbsp;a&nbsp;list&nbsp;item&nbsp;is&nbsp;deleted. | 
| onScrollIndex(firstIndex:&nbsp;number,&nbsp;lastIndex:&nbsp;number)&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;start&nbsp;position&nbsp;and&nbsp;end&nbsp;position&nbsp;of&nbsp;the&nbsp;current&nbsp;list&nbsp;are&nbsp;changed. | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> To enable the editable mode for a list, the following conditions must be met:
> 
> - **editMode** is set to **true**.
> 
> - The list is bound to the **onItemDelete** event and the event returns **true** during event callback.
> 
> - The **editable** attribute of **ListItem** is set to **true**.
> 
> To enable dragging for a list item, the following conditions must be met:
> 
> - **editMode** is set to **true**.
> 
> - The list item is bound to the **onDragStart** event and the event returns a floating UI during event callback.


## Example


```
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical) // Arrangement direction
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // Divider line
        .edgeEffect(EdgeEffect.None) // No effect when sliding to the edge
        .chainAnimation(false) // Chained animations are disabled.
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
        .editMode(this.editFlag)
        .onItemDelete((index: number) => {
          console.info(this.arr[index] + 'Delete')
          this.arr.splice(index, 1)
          console.info(JSON.stringify(this.arr))
          this.editFlag = false
          return true
        }).width('90%')
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![en-us_image_0000001256978357](figures/en-us_image_0000001256978357.gif)

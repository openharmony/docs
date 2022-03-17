# GridItem


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;GridItem&gt;** component provides a single item in a grid.


## Required Permissions

None


## Child Component

This component can contain child components.


## APIs

GridItem()


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| rowStart | number | - | Start&nbsp;row&nbsp;number&nbsp;of&nbsp;the&nbsp;component. | 
| rowEnd | number | - | End&nbsp;row&nbsp;number&nbsp;of&nbsp;the&nbsp;component. | 
| columnStart | number | - | Start&nbsp;column&nbsp;number&nbsp;of&nbsp;the&nbsp;component. | 
| columnEnd | number | - | End&nbsp;column&nbsp;number&nbsp;of&nbsp;the&nbsp;component. | 
| forceRebuild | boolean | false | Whether&nbsp;to&nbsp;re-create&nbsp;this&nbsp;node&nbsp;when&nbsp;the&nbsp;component&nbsp;is&nbsp;being&nbsp;built. | 
| selectable<sup>8+</sup> | boolean | true | Whether&nbsp;the&nbsp;current&nbsp;**&lt;GridItem&gt;**&nbsp;is&nbsp;selectable&nbsp;by&nbsp;the&nbsp;mouse.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;attribute&nbsp;takes&nbsp;effect&nbsp;only&nbsp;when&nbsp;mouse&nbsp;frame&nbsp;selection&nbsp;is&nbsp;enabled&nbsp;for&nbsp;the&nbsp;parent&nbsp;**&lt;Grid&gt;**&nbsp;container. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onSelect(callback:&nbsp;(isSelected:&nbsp;boolean)&nbsp;=&gt;&nbsp;any)<sup>8+</sup> | Triggered&nbsp;when&nbsp;the&nbsp;selected&nbsp;state&nbsp;of&nbsp;the&nbsp;**&lt;GridItem&gt;**&nbsp;changes.<br/>**isSelected**:&nbsp;Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;**&lt;GridItem&gt;**&nbsp;is&nbsp;selected&nbsp;by&nbsp;the&nbsp;mouse;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 


## Example

  
```
@Entry
@Component
struct GridItemExample {
  @State numbers: string[] = Array.apply(null, Array(16)).map(function (item, i) { return i.toString() })

  build() {
    Column() {
      Grid() {
        GridItem() {
          Text('4')
            .fontSize(16).backgroundColor(0xFAEEE0)
            .width('100%').height('100%').textAlign(TextAlign.Center)
        }.rowStart(1).rowEnd(4)

        ForEach(this.numbers, (item) => {
          GridItem() {
            Text(item)
              .fontSize(16).backgroundColor(0xF9CF93)
              .width('100%').height('100%').textAlign(TextAlign.Center)
          }.forceRebuild(false)
        }, item => item)

        GridItem() {
          Text('5')
            .fontSize(16).backgroundColor(0xDBD0C0)
            .width('100%').height('100%').textAlign(TextAlign.Center)
        }.columnStart(1).columnEnd(5)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .width('90%').height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001256858433](figures/en-us_image_0000001256858433.gif)

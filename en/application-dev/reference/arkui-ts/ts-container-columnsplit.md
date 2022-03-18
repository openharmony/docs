# ColumnSplit


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;ColumnSplit&gt;** lays out child components vertically and inserts a horizontal divider between every two child components.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

ColumnSplit()


## Attributes

  | Name | Type | Description | 
| -------- | -------- | -------- |
| resizeable | boolean | Whether&nbsp;the&nbsp;divider&nbsp;can&nbsp;be&nbsp;dragged.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**false**. | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> Similar to **&lt;RowSplit&gt;**, the divider of **&lt;ColumnSplit&gt;** can be dragged to a position that just fully holds a component.


## Example

  
```
@Entry
@Component
struct ColumnSplitExample {
  build() {
    Column(){
      Text('The secant line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')
      ColumnSplit() {
        Text('1').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('2').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('3').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('4').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('5').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }
      .resizeable(true)
      .width('90%').height('60%')
    }.width('100%')
  }
}
```

![en-us_image_0000001212378422](figures/en-us_image_0000001212378422.gif)

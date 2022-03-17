# Size


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| width | Length | - | Width&nbsp;of&nbsp;a&nbsp;component.&nbsp;By&nbsp;default,&nbsp;the&nbsp;width&nbsp;required&nbsp;to&nbsp;fully&nbsp;hold&nbsp;the&nbsp;component&nbsp;content&nbsp;is&nbsp;used. | 
| height | Length | - | Height&nbsp;of&nbsp;the&nbsp;component.&nbsp;By&nbsp;default,&nbsp;the&nbsp;height&nbsp;required&nbsp;to&nbsp;fully&nbsp;hold&nbsp;the&nbsp;component&nbsp;content&nbsp;is&nbsp;used. | 
| size | {<br/>width?:&nbsp;Length,<br/>height?:&nbsp;Length<br/>} | - | Height&nbsp;and&nbsp;width&nbsp;of&nbsp;the&nbsp;component. | 
| padding | {<br/>top?:&nbsp;Length,<br/>right?:&nbsp;Length,<br/>bottom?:&nbsp;Length,<br/>left?:&nbsp;Length<br/>}&nbsp;\|&nbsp;Length | 0 | Padding&nbsp;of&nbsp;the&nbsp;component.<br/>When&nbsp;the&nbsp;parameter&nbsp;is&nbsp;of&nbsp;the&nbsp;**Length**&nbsp;type,&nbsp;the&nbsp;four&nbsp;paddings&nbsp;take&nbsp;effect. | 
| margin | {<br/>top?:&nbsp;Length,<br/>right?:&nbsp;Length,<br/>bottom?:&nbsp;Length,<br/>left?:&nbsp;Length<br/>}<br/>\|&nbsp;Length | 0 | Margin&nbsp;of&nbsp;the&nbsp;component.&nbsp;<br/>When&nbsp;the&nbsp;parameter&nbsp;is&nbsp;of&nbsp;the&nbsp;**Length**&nbsp;type,&nbsp;the&nbsp;four&nbsp;margins&nbsp;take&nbsp;effect. | 
| constraintSize | {<br/>minWidth?:&nbsp;Length,<br/>maxWidth?:&nbsp;Length,<br/>minHeight?:&nbsp;Length,<br/>maxHeight?:&nbsp;Length<br/>} | {<br/>minWidth:&nbsp;0,<br/>maxWidth:&nbsp;Infinity,<br/>minHeight:&nbsp;0,<br/>maxHeight:&nbsp;Infinity<br/>} | Constraint&nbsp;size&nbsp;of&nbsp;the&nbsp;component,&nbsp;which&nbsp;is&nbsp;used&nbsp;to&nbsp;limit&nbsp;the&nbsp;size&nbsp;range&nbsp;during&nbsp;component&nbsp;layout. |
| layoutWeight | number | 0 | Weight&nbsp;of&nbsp;the&nbsp;component&nbsp;during&nbsp;layout.&nbsp;When&nbsp;the&nbsp;container&nbsp;size&nbsp;is&nbsp;determined,&nbsp;the&nbsp;layout&nbsp;of&nbsp;the&nbsp;component&nbsp;and&nbsp;sibling&nbsp;components&nbsp;is&nbsp;allocated&nbsp;based&nbsp;on&nbsp;the&nbsp;weight&nbsp;along&nbsp;the&nbsp;main&nbsp;axis.&nbsp;The&nbsp;component&nbsp;size&nbsp;setting&nbsp;is&nbsp;ignored.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;attribute&nbsp;is&nbsp;valid&nbsp;only&nbsp;for&nbsp;the&nbsp;**Row**,&nbsp;**Column**,&nbsp;and&nbsp;**Flex**&nbsp;layouts. | 


## Example

```
@Entry
@Component
struct SizeExample {
  build() {
    Column({ space: 10 }) {
      Text('margin and padding:').fontSize(12).fontColor(0xCCCCCC).width('90%')
      // The width is 80, the height is 80, the padding is 20, and the margin is 20.
      Row() {
        Row() {
          Row().size({ width: '100%', height: '100%' }).backgroundColor(0xAFEEEE)
        }.width(80).height(80).padding(20).margin(20).backgroundColor(0xFDF5E6)
      }.backgroundColor(0xFFA500)

      Text('layoutWeight').fontSize(12).fontColor(0xCCCCCC).width('90%')
      // When the container size is determined, the layout of the component and slibing components is allocated based on the weight along the main axis. The component size setting is ignored.
      Row() {
        // Weight 1
        Text('layoutWeight(1)')
          .size({ width: '30%', height: 110 }).backgroundColor(0xFFEFD5).textAlign(TextAlign.Center)
          .layoutWeight(1)
       // Weight 0
        Text('layoutWeight(2)')
          .size({ width: '30%', height: 110 }).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
          .layoutWeight(2)
        // The default weight is 0.
        Text('no layoutWeight')
          .size({ width: '30%', height: 110 }).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
      }.size({ width: '90%', height: 140 }).backgroundColor(0xAFEEEE)
    }.width('100%').margin({ top: 5 })
  }}
```

![en-us_image_0000001257138367](figures/en-us_image_0000001257138367.gif)

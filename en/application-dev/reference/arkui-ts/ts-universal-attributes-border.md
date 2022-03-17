# Border


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes described in this topic are used to set border styles.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| border | {<br/>width?:&nbsp;Length,<br/>color?:&nbsp;Color,<br/>radius?:&nbsp;Length,<br/>style?:&nbsp;BorderStyle<br/>} | - | Sets&nbsp;a&nbsp;unified&nbsp;border&nbsp;style. | 
| borderStyle | BorderStyle | BorderStyle.Solid | Sets&nbsp;the&nbsp;border&nbsp;style&nbsp;of&nbsp;an&nbsp;element. | 
| borderWidth | Length | 0 | Sets&nbsp;the&nbsp;border&nbsp;width&nbsp;of&nbsp;an&nbsp;element. | 
| borderColor | Color | - | Sets&nbsp;the&nbsp;border&nbsp;color&nbsp;of&nbsp;an&nbsp;element. | 
| borderRadius | Length | 0 | Sets&nbsp;the&nbsp;border&nbsp;radius&nbsp;of&nbsp;an&nbsp;element. | 


- BorderStyle enums
    | Name | Description | 
  | -------- | -------- |
  | Dotted | Dotted&nbsp;border.&nbsp;The&nbsp;radius&nbsp;of&nbsp;a&nbsp;dot&nbsp;is&nbsp;half&nbsp;of&nbsp;**borderWidth**. | 
  | Dashed | Dashed&nbsp;border. | 
  | Solid | Solid&nbsp;border. | 


## Example

  
```
@Entry
@Component
struct BorderExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
      // Line segment
      Text('dashed')
        .borderStyle(BorderStyle.Dashed).borderWidth(5).borderColor(0xAFEEEE).borderRadius(10)
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
      // Dotted line
      Text('dotted')
        .border({ width: 5, color: 0x317AF7, radius: 10, style: BorderStyle.Dotted })
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
    }.width('100%').height(150)
  }
}
```

![en-us_image_0000001211898466](figures/en-us_image_0000001211898466.gif)

# Border


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes described in this topic are used to set border styles.


## Required Permissions

None


## Attributes


  | Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| border | {<br/>width?: Length,<br/>color?: Color,<br/>radius?: Length,<br/>style?: BorderStyle<br/>} | - | Sets a unified border style. | 
| borderStyle | BorderStyle | BorderStyle.Solid | Sets the border style of an element. | 
| borderWidth | Length | 0 | Sets the border width of an element. | 
| borderColor | Color | - | Sets the border color of an element. | 
| borderRadius | Length | 0 | Sets the border radius of an element. | 


- BorderStyle enums
    | Name | Description | 
  | -------- | -------- |
  | Dotted | Dotted border. The radius of a dot is half of **borderWidth**. | 
  | Dashed | Dashed border. | 
  | Solid | Solid border. | 


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

# Text Style


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes described in this topic are used to set the text style for a component that contains text.


## Required Permissions

None


## Attributes


  | Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| fontColor | Color | - | Text color. | 
| fontSize | Length | - | Text size. If the value is of the number type, the unit fp is used. | 
| fontStyle | FontStyle | FontStyle.Normal | Font style of the text. | 
| fontWeight | number \| FontWeight | FontWeight.Normal | Font weight. For the number type, the value ranges from 100 to 900, at an interval of 100. The default value is **400**. A larger value indicates a larger font weight.<br/>For common values of the **FontWeight** type, see **FontWeight** enums. | 
| fontFamily | string | - | Font family of the text. Use commas (,) to separate multiple fonts. The priority the fonts is the sequence in which they are placed. An example value is **Arial, sans-serif**. | 


- FontStyle enums
    | Name | Description | 
  | -------- | -------- |
  | Normal | Standard font style. | 
  | Italic | Italic font style. | 


- FontWeight enums
    | Name | Description | 
  | -------- | -------- |
  | Lighter | The font weight is lighter. | 
  | Normal | The font weight is normal. | 
  | Regular | The font weight is regular. | 
  | Medium | The font weight is medium. | 
  | Bold | The font weight is bold. | 
  | Bolder | The font weight is bolder. | 


## Example

  
```
@Entry
@Component
struct TextStyleExample {
  build() {
    Column({ space: 5 }) {
      Text('default text')

      Text('text font color red')
        .fontColor(Color.Red)

      Text('text font size 20')
        .fontSize(20)

      Text('text font style Italic')
        .fontStyle(FontStyle.Italic)

      Text('text fontWeight bold')
        .fontWeight(700)

      Text('text fontFamily sans-serif')
        .fontFamily('sans-serif')

      Text('red 20 Italic bold cursive text')
        .fontColor(Color.Red)
        .fontSize(20)
        .fontStyle(FontStyle.Italic)
        .fontWeight(700)
        .fontFamily('cursive')
        .textAlign(TextAlign.Center)
        .width('90%')

      Text('Orange 18 Normal source-sans-pro text')
        .fontColor(Color.Orange)
        .fontSize(18)
        .fontStyle(FontStyle.Normal)
        .fontWeight(400)
        .fontFamily('source-sans-pro,cursive,sans-serif')
    }.width('100%')
  }
}
```

![en-us_image_0000001256978333](figures/en-us_image_0000001256978333.png)

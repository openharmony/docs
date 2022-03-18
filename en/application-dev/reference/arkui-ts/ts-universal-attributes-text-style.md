# Text Style


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes described in this topic are used to set the text style for a component that contains text.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| fontColor | Color | - | Text&nbsp;color. | 
| fontSize | Length | - | Text&nbsp;size.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;unit&nbsp;fp&nbsp;is&nbsp;used. | 
| fontStyle | FontStyle | FontStyle.Normal | Font&nbsp;style&nbsp;of&nbsp;the&nbsp;text. | 
| fontWeight | number&nbsp;\|&nbsp;FontWeight | FontWeight.Normal | Font&nbsp;weight.&nbsp;For&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;value&nbsp;ranges&nbsp;from&nbsp;100&nbsp;to&nbsp;900,&nbsp;at&nbsp;an&nbsp;interval&nbsp;of&nbsp;100.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**400**.&nbsp;A&nbsp;larger&nbsp;value&nbsp;indicates&nbsp;a&nbsp;larger&nbsp;font&nbsp;weight.<br/>For&nbsp;common&nbsp;values&nbsp;of&nbsp;the&nbsp;**FontWeight**&nbsp;type,&nbsp;see&nbsp;**FontWeight**&nbsp;enums. | 
| fontFamily | string | - | Font&nbsp;family&nbsp;of&nbsp;the&nbsp;text.&nbsp;Use&nbsp;commas&nbsp;(,)&nbsp;to&nbsp;separate&nbsp;multiple&nbsp;fonts.&nbsp;The&nbsp;priority&nbsp;the&nbsp;fonts&nbsp;is&nbsp;the&nbsp;sequence&nbsp;in&nbsp;which&nbsp;they&nbsp;are&nbsp;placed.&nbsp;An&nbsp;example&nbsp;value&nbsp;is&nbsp;**Arial,&nbsp;sans-serif**. | 


- FontStyle enums
    | Name | Description | 
  | -------- | -------- |
  | Normal | Standard&nbsp;font&nbsp;style. | 
  | Italic | Italic&nbsp;font&nbsp;style. | 


- FontWeight enums
    | Name | Description | 
  | -------- | -------- |
  | Lighter | The&nbsp;font&nbsp;weight&nbsp;is&nbsp;lighter. | 
  | Normal | The&nbsp;font&nbsp;weight&nbsp;is&nbsp;normal. | 
  | Regular | The&nbsp;font&nbsp;weight&nbsp;is&nbsp;regular. | 
  | Medium | The&nbsp;font&nbsp;weight&nbsp;is&nbsp;medium. | 
  | Bold | The&nbsp;font&nbsp;weight&nbsp;is&nbsp;bold. | 
  | Bolder | The&nbsp;font&nbsp;weight&nbsp;is&nbsp;bolder. | 


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

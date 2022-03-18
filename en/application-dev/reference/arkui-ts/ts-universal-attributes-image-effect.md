# Image Effect Configuration


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| blur | number | - | Adds&nbsp;the&nbsp;content&nbsp;blurring&nbsp;for&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;the&nbsp;blur&nbsp;radius.&nbsp;The&nbsp;larger&nbsp;the&nbsp;radius&nbsp;is,&nbsp;the&nbsp;more&nbsp;blurred&nbsp;the&nbsp;content&nbsp;is.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**0**,&nbsp;the&nbsp;content&nbsp;is&nbsp;not&nbsp;blurred. | 
| backdropBlur | number | - | Adds&nbsp;the&nbsp;background&nbsp;blur&nbsp;effect&nbsp;for&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;the&nbsp;blur&nbsp;radius.&nbsp;The&nbsp;larger&nbsp;the&nbsp;radius&nbsp;is,&nbsp;the&nbsp;more&nbsp;blurred&nbsp;the&nbsp;background&nbsp;is.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**0**,&nbsp;the&nbsp;background&nbsp;is&nbsp;not&nbsp;blurred. |
| shadow | {<br/>radius:&nbsp;number,<br/>color?:&nbsp;Color,<br/>offsetX?:&nbsp;number,<br/>offsetY?:&nbsp;number<br/>} | - | Adds&nbsp;the&nbsp;shadow&nbsp;effect&nbsp;to&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameters&nbsp;are&nbsp;the&nbsp;fuzzy&nbsp;radius&nbsp;(mandatory),&nbsp;shadow&nbsp;color&nbsp;(optional;&nbsp;gray&nbsp;by&nbsp;default),&nbsp;X-axis&nbsp;offset&nbsp;(optional&nbsp;and&nbsp;0&nbsp;by&nbsp;default),&nbsp;and&nbsp;Y-axis&nbsp;offset&nbsp;(optional;&nbsp;0&nbsp;by&nbsp;default).&nbsp;The&nbsp;offset&nbsp;unit&nbsp;is&nbsp;px. | 
| grayscale | number | 0.0 | The&nbsp;value&nbsp;indicates&nbsp;the&nbsp;grayscale&nbsp;conversion&nbsp;ratio.&nbsp;If&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;**1.0**,&nbsp;the&nbsp;image&nbsp;is&nbsp;converted&nbsp;into&nbsp;a&nbsp;grayscale&nbsp;image.&nbsp;If&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;**0.0**,&nbsp;the&nbsp;image&nbsp;does&nbsp;not&nbsp;change.&nbsp;If&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;between&nbsp;**0.0**&nbsp;and&nbsp;**1.0**,&nbsp;the&nbsp;effect&nbsp;changes&nbsp;in&nbsp;linear&nbsp;mode.&nbsp;The&nbsp;unit&nbsp;is&nbsp;percentage.&nbsp;The&nbsp;unit&nbsp;is&nbsp;percentage. | 
| brightness | number | 1.0 | Adds&nbsp;a&nbsp;brightness&nbsp;to&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;a&nbsp;brightness&nbsp;ratio.&nbsp;The&nbsp;value&nbsp;**1**&nbsp;indicates&nbsp;no&nbsp;effects.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;indicates&nbsp;the&nbsp;complete&nbsp;darkness.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;**1**,&nbsp;the&nbsp;brightness&nbsp;decreases.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;**1**,&nbsp;the&nbsp;brightness&nbsp;increases.&nbsp;A&nbsp;larger&nbsp;value&nbsp;indicates&nbsp;a&nbsp;higher&nbsp;brightness. | 
| saturate | number | 1.0 | Adds&nbsp;the&nbsp;saturation&nbsp;effect&nbsp;to&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;saturation&nbsp;is&nbsp;the&nbsp;ratio&nbsp;of&nbsp;the&nbsp;chromatic&nbsp;component&nbsp;to&nbsp;the&nbsp;achromatic&nbsp;component&nbsp;(gray)&nbsp;in&nbsp;a&nbsp;color.&nbsp;When&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;**1**,&nbsp;the&nbsp;source&nbsp;image&nbsp;is&nbsp;displayed.&nbsp;When&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;**1**,&nbsp;a&nbsp;higher&nbsp;percentage&nbsp;of&nbsp;the&nbsp;chromatic&nbsp;component&nbsp;indicates&nbsp;a&nbsp;higher&nbsp;saturation.&nbsp;When&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;**1**,&nbsp;a&nbsp;higher&nbsp;percentage&nbsp;of&nbsp;the&nbsp;achromatic&nbsp;component&nbsp;indicates&nbsp;a&nbsp;lower&nbsp;saturation.&nbsp;The&nbsp;unit&nbsp;is&nbsp;percentage. | 
| contrast | number | 1.0 | Adds&nbsp;the&nbsp;contrast&nbsp;effect&nbsp;to&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;a&nbsp;contrast&nbsp;value.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**1**,&nbsp;the&nbsp;source&nbsp;image&nbsp;is&nbsp;displayed.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;greater&nbsp;than&nbsp;**1**,&nbsp;a&nbsp;larger&nbsp;value&nbsp;indicates&nbsp;a&nbsp;higher&nbsp;contrast&nbsp;and&nbsp;a&nbsp;clearer&nbsp;image.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;less&nbsp;than&nbsp;**1**,&nbsp;a&nbsp;smaller&nbsp;value&nbsp;indicates&nbsp;a&nbsp;lower&nbsp;contrast&nbsp;is.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;**0**,&nbsp;the&nbsp;image&nbsp;becomes&nbsp;all&nbsp;gray.&nbsp;The&nbsp;unit&nbsp;is&nbsp;percentage. | 
| invert | number | 0 | Inverts&nbsp;the&nbsp;input&nbsp;image.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;an&nbsp;image&nbsp;inversion&nbsp;ratio.&nbsp;The&nbsp;value&nbsp;**1**&nbsp;indicates&nbsp;complete&nbsp;inversion.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;image&nbsp;does&nbsp;not&nbsp;change.&nbsp;The&nbsp;unit&nbsp;is&nbsp;percentage. | 
| colorBlend&nbsp;<sup>8+</sup> | Color | - | Adds&nbsp;the&nbsp;color&nbsp;blend&nbsp;effect&nbsp;to&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;the&nbsp;blended&nbsp;color. | 
| sepia | number | 0 | Converts&nbsp;the&nbsp;image&nbsp;color&nbsp;to&nbsp;sepia.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;an&nbsp;image&nbsp;inversion&nbsp;ratio.&nbsp;The&nbsp;value&nbsp;**1**&nbsp;indicates&nbsp;the&nbsp;image&nbsp;is&nbsp;completely&nbsp;sepia.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;indicates&nbsp;that&nbsp;the&nbsp;image&nbsp;does&nbsp;not&nbsp;change.&nbsp;The&nbsp;unit&nbsp;is&nbsp;percentage. | 
| hueRotate | Angle | 0deg | Adds&nbsp;the&nbsp;hue&nbsp;rotation&nbsp;effect&nbsp;to&nbsp;the&nbsp;current&nbsp;component.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;a&nbsp;rotation&nbsp;angle.&nbsp;If&nbsp;the&nbsp;input&nbsp;value&nbsp;is&nbsp;**0deg**,&nbsp;the&nbsp;image&nbsp;does&nbsp;not&nbsp;change&nbsp;(because&nbsp;the&nbsp;default&nbsp;rotation&nbsp;angle&nbsp;is&nbsp;**0deg**).&nbsp;The&nbsp;input&nbsp;parameter&nbsp;does&nbsp;not&nbsp;have&nbsp;the&nbsp;maximum&nbsp;value.&nbsp;If&nbsp;the&nbsp;value&nbsp;exceeds&nbsp;**360deg**,&nbsp;the&nbsp;image&nbsp;is&nbsp;rotated&nbsp;one&nbsp;ore&nbsp;more&nbsp;circles. |


## Example


```
@Entry
@Component
struct ImageEffectsExample {
  build() {
Column({space: 10}) {
      // Blur the font.
      Text('font blur').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Text('text').blur(3).width('90%').height(40)
        .fontSize(16).backgroundColor(0xF9CF93).padding({ left: 5 })

      // Blur the background.
      Text('backdropBlur').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Text().width('90%').height(40).fontSize(16).backdropBlur(3)
        .backgroundImage('/comment/bg.jpg')
        .backgroundImageSize({ width: 1200, height: 160 })

      Text('shadow').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40)
        .shadow({ radius: 10, color: Color.Gray, offsetX: 5, offsetY: 5 })

      Text('grayscale').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).grayscale(0.6)

      Text('brightness').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).brightness(2.0)

      Text('saturate').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).saturate(2.0)

      Text('contrast').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).contrast(2.0)

      Text('invert').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).invert(1)

      Text('hueRotate').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.bg')).width('90%').height(40).hueRotate(90)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218448](figures/en-us_image_0000001212218448.png)

# Opacity


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes described in this topic are used to set the opacity of a component.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| opacity | number | 1 | Opacity&nbsp;of&nbsp;a&nbsp;component.&nbsp;The&nbsp;value&nbsp;ranges&nbsp;from&nbsp;**0**&nbsp;to&nbsp;**1**.&nbsp;The&nbsp;value&nbsp;**1**&nbsp;means&nbsp;opaque,&nbsp;and&nbsp;**0**&nbsp;means&nbsp;completely&nbsp;transparent. | 


## Example

  
```
@Entry
@Component
struct OpacityExample {
  build() {
    Column({ space: 5 }) {
      Text('opacity(1)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(1).backgroundColor(0xAFEEEE)
      Text('opacity(0.7)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0.7).backgroundColor(0xAFEEEE)
      Text('opacity(0.4)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0.4).backgroundColor(0xAFEEEE)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![en-us_image_0000001256858385](figures/en-us_image_0000001256858385.gif)

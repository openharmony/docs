# Transformation


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| rotate | {<br/>x?:&nbsp;number,<br/>y?:&nbsp;number,<br/>z?:&nbsp;number,<br/>angle?:&nbsp;Angle,<br/>centerX?:&nbsp;Length,<br/>centerY?:&nbsp;Length<br/>} | {<br/>x:&nbsp;0,<br/>y:&nbsp;0,<br/>z:&nbsp;0,<br/>angle:&nbsp;0,<br/>centerX:&nbsp;'50%',<br/>centerY:&nbsp;'50%'<br/>} | The&nbsp;vector&nbsp;(x,&nbsp;y,&nbsp;z)&nbsp;specifies&nbsp;a&nbsp;rotation&nbsp;axis.&nbsp;A&nbsp;positive&nbsp;angle&nbsp;indicates&nbsp;a&nbsp;clockwise&nbsp;rotation,&nbsp;and&nbsp;a&nbsp;negative&nbsp;angle&nbsp;indicates&nbsp;a&nbsp;counterclockwise&nbsp;rotation.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**0**.&nbsp;**centerX**&nbsp;and&nbsp;**centerY**&nbsp;are&nbsp;used&nbsp;to&nbsp;set&nbsp;the&nbsp;rotation&nbsp;center&nbsp;point. | 
| translate | {<br/>x?:&nbsp;Length,<br/>y?:&nbsp;Length,<br/>z?&nbsp;:&nbsp;Length<br/>} | {<br/>x:&nbsp;0,<br/>y:&nbsp;0,<br/>z:&nbsp;0<br/>} | Translation&nbsp;distance&nbsp;along&nbsp;the&nbsp;x-,&nbsp;y-,&nbsp;and&nbsp;z-axis.&nbsp;The&nbsp;translation&nbsp;direction&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;positive&nbsp;and&nbsp;negative&nbsp;values.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**0**. | 
| scale | {<br/>x?:&nbsp;number,<br/>y?:&nbsp;number,<br/>z?:&nbsp;number,<br/>centerX?:&nbsp;Length,<br/>centerY?:&nbsp;Length<br/>} | {<br/>x:&nbsp;1,<br/>y:&nbsp;1,<br/>z:&nbsp;1,<br/>centerX:'50%',<br/>centerY:'50%'<br/>} | Scale&nbsp;ratio&nbsp;of&nbsp;the&nbsp;x-,&nbsp;y-,&nbsp;and&nbsp;z-axis.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**1**.&nbsp;**centerX**&nbsp;and&nbsp;**centerY**&nbsp;are&nbsp;used&nbsp;to&nbsp;set&nbsp;the&nbsp;scale&nbsp;center&nbsp;point. | 
| transform | matrix:&nbsp;Matrix4 | - | Transformation&nbsp;matrix&nbsp;of&nbsp;the&nbsp;component. | 


## Example

  
```
import Matrix4 from '@ohos.matrix4'

@Entry
@Component
struct TransformExample {
  build() {
    Column() {
      Text('rotate').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(30)
      Row()
        .rotate({
          x: 1,
          y: 1,
          z: 1,
          centerX: '50%',
          centerY: '50%',
          angle: 300
        }) // The component rotates around the center point of the rotation axis (1,1,1) clockwise by 300 degrees.
        .width(100).height(100).backgroundColor(0xAFEEEE)

      Text('translate').width('90%').fontColor(0xCCCCCC).padding(10).fontSize(30)
      Row()
        .translate({ x: 100, y: 5 }) // The component translates by 100 along the x-axis and by 5 along the y-axis.
        .width(100).height(100).backgroundColor(0xAFEEEE).margin({bottom:10})

      Text('scale').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(30)
      Row()
        .scale({ x: 2, y: 0.5}) // The height and width are doubled. The z-axis has no effect in 2D mode.
        .width(100).height(100).backgroundColor(0xAFEEEE)

      Text('Matrix4').width('90%').fontColor(0xCCCCCC).padding(15).fontSize(30)
      Row()
        .width(100).height(100).backgroundColor(0xAFEEEE)
        .transform(Matrix4.identity().translate({ x: 100, y: 100, z: 30 }))
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001257058401](figures/en-us_image_0000001257058401.png)

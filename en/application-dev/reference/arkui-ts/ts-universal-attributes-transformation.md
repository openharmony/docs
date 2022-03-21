# Transformation


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


  | Name | Type | Default Value | Description | 
| -------- | -------- | -------- | -------- |
| rotate | {<br/>x?: number,<br/>y?: number,<br/>z?: number,<br/>angle?: Angle,<br/>centerX?: Length,<br/>centerY?: Length<br/>} | {<br/>x: 0,<br/>y: 0,<br/>z: 0,<br/>angle: 0,<br/>centerX: '50%',<br/>centerY: '50%'<br/>} | The vector (x, y, z) specifies a rotation axis. A positive angle indicates a clockwise rotation, and a negative angle indicates a counterclockwise rotation. The default value is **0**. **centerX** and **centerY** are used to set the rotation center point. | 
| translate | {<br/>x?: Length,<br/>y?: Length,<br/>z? : Length<br/>} | {<br/>x: 0,<br/>y: 0,<br/>z: 0<br/>} | Translation distance along the x-, y-, and z-axis. The translation direction is determined by the positive and negative values. The default value is **0**. | 
| scale | {<br/>x?: number,<br/>y?: number,<br/>z?: number,<br/>centerX?: Length,<br/>centerY?: Length<br/>} | {<br/>x: 1,<br/>y: 1,<br/>z: 1,<br/>centerX:'50%',<br/>centerY:'50%'<br/>} | Scale ratio of the x-, y-, and z-axis. The default value is **1**. **centerX** and **centerY** are used to set the scale center point. | 
| transform | matrix: Matrix4 | - | Transformation matrix of the component. | 


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

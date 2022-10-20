# Transformation

Transformation attributes allow you to rotate, translate, scale, or transform a component.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes


| Name       | Type                                                          | Description                                      |
| --------- | ------------------------------------------------------------------------ | ---------------------------------------- |
| rotate    | {<br/>x?: number,<br/>y?: number,<br/>z?: number,<br/>angle?: number \| string,<br/>centerX?: number \| string,<br/>centerY?: number \| string<br/>} | Rotation axis. A positive angle indicates a clockwise rotation, and a negative angle indicates a counterclockwise rotation. The default value is **0**. **centerX** and **centerY** are used to set the rotation center point.<br>Default value:<br>**{<br>x: 0,<br>y: 0,<br>z: 0,<br>angle: 0,<br>centerX: '50%',<br>centerY: '50%'<br>}** |
| translate | {<br/>x?: number \| string,<br/>y?: number \| string,<br/>z? : number \| string<br/>}  | Translation distance along the x-, y-, and z-axis. The translation direction is determined by the positive and negative values. The value cannot be a percentage.<br>Default value:<br>**{<br>x: 0,<br>y: 0,<br>z: 0<br>}** |
| scale     | {<br/>x?: number,<br/>y?: number,<br/>z?: number,<br/>centerX?: number \| string,<br/>centerY?: number \| string<br/>} | Scale ratio of the x-, y-, and z-axis. The default value is **1**. **centerX** and **centerY** are used to set the scale center point.<br>Default value:<br>**{<br>x: 1,<br>y: 1,<br>z: 1,<br>centerX:'50%',<br>centerY:'50%'<br>}** |
| transform | matrix: Matrix4                                                 | Transformation matrix of the component.                            |


## Example

```ts
// xxx.ets
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

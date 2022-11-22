# Image Effects

Image effects include background blur, content blur, grayscale, and much more.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


| Name                         | Type                                                    | Default Value| Description                                                        |
| ----------------------------- | ------------------------------------------------------------ | ------ | ------------------------------------------------------------ |
| blur                          | number                                                       | -      | Adds the content blur effect to the current component. The input parameter is the blur radius. The larger the radius is, the more blurred the content is. If the value is **0**, the content is not blurred. |
| backdropBlur                  | number                                                       | -      | Adds the background blur effect to the current component. The input parameter is the blur radius. The larger the radius is, the more blurred the background is. If the value is **0**, the background is not blurred. |
| shadow                        | {<br>radius: number \| [Resource](ts-types.md#resource),<br>color?: Color \| string \| Resource,<br>offsetX?: number \| Resource,<br>offsetY?: number \| Resource<br>} | -      | Adds the shadow effect to the current component. The input parameters are the fuzzy radius (mandatory), shadow color (optional; gray by default), x-axis offset (optional; 0 by default), and y-axis offset (optional; 0 by default). The offset unit is px.|
| grayscale                     | number                                                       | 0.0    | Converts the input image to grayscale. The value indicates the grayscale conversion ratio. If the input value is **1.0**, the image is converted into a grayscale image. If the input value is **0.0**, the image does not change. If the input value is between **0.0** and **1.0**, the effect changes in linear mode. The unit is percentage.|
| brightness                    | number                                                       | 1.0    | Adds a brightness to the current component. The input parameter is a brightness ratio. The value **1** indicates no effects. The value **0** indicates the complete darkness. If the value is less than **1**, the brightness decreases. If the value is greater than **1**, the brightness increases. A larger value indicates a higher brightness.|
| saturate                      | number                                                       | 1.0    | Adds the saturation effect to the current component. The saturation is the ratio of the chromatic component to the achromatic component (gray) in a color. When the input value is **1**, the source image is displayed. When the input value is greater than **1**, a higher percentage of the chromatic component indicates a higher saturation. When the input value is less than **1**, a higher percentage of the achromatic component indicates a lower saturation. The unit is percentage.|
| contrast                      | number                                                       | 1.0    | Adds the contrast effect to the current component. The input parameter is a contrast value. If the value is **1**, the source image is displayed. If the value is greater than **1**, a larger value indicates a higher contrast and a clearer image. If the value is less than **1**, a smaller value indicates a lower contrast is. If the value is **0**, the image becomes all gray. The unit is percentage.|
| invert                        | number                                                       | 0      | Inverts the input image. The input parameter is an image inversion ratio. The value **1** indicates complete inversion. The value **0** indicates that the image does not change. The unit is percentage.|
| colorBlend <sup>8+</sup> | Color \| string \| [Resource](ts-types.md#resource) | -      | Adds the color blend effect to the current component. The input parameter is the blended color.                                                           |
| sepia                         | number                                                       | 0      | Converts the image color to sepia. The input parameter is an image inversion ratio. The value **1** indicates the image is completely sepia. The value **0** indicates that the image does not change. The unit is percentage.|
| hueRotate                     | number\|string                                               | '0deg' | Adds the hue rotation effect to the current component. The input parameter is a rotation angle.                          |

## Example

You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.

```ts
// xxx.ets
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

![](figures/image-effect.png)

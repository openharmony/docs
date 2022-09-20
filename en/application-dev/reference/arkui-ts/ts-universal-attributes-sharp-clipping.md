# Shape Clipping


> **NOTE**
>
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| clip | Shape \| boolean | false | Clip mode. The value **Shape** indicates that the current component is cropped based on the specified shape. The value **boolean** specifies whether to clip the component based on the edge outline. |
| mask | Shape | - | Mask of the specified shape for the current component. |


## Example


```ts
// xxx.ets
@Entry
@Component
struct ClipAndMaskExample {
  build() {
    Column({ space: 5 }) {
      Text('clip').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // Clip the image by using a circle with a diameter of 280px.
      Image($r('app.media.example'))
        .clip(new Circle({ width: 80, height: 80 }))
        .width('500px').height('280px')

      Row() {
        Image($r('app.media.example')).width('500px').height('280px')
      }
      .clip(true)
      .borderRadius(20)

      Text('mask').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // Add a 500 px x 280 px mask to the image.
      Image($r('app.media.example'))
        .mask(new Rect({ width: '500px', height: '280px' }).fill(Color.Gray))
        .width('500px').height('280px')

      // Add a 280 px x 280 px circle mask to the image.
      Image($r('app.media.example'))
        .mask(new Circle({ width: '280px', height: '280px' }).fill(Color.Gray))
        .width('500px').height('281px')
    }
    .width('100%')
    .margin({ top: 5 })
  }
}
```

![en-us_image_0000001212218452](figures/en-us_image_0000001212218452.png)

# Pixel Stretch Effect

You can apply a pixel stretch effect to a component.

>  **NOTE**
>
>  This attribute is supported since API Version 10. Updates will be marked with a superscript to indicate their earliest API version. This is a system API.

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| pixelStretchEffect | [PixelStretchEffectOptions](ts-types.md#pixelstretcheffectoptions10) | Pixel stretch effect options.<br>The **options** parameter includes the length by which a pixel is stretched toward the four edges.<br>**NOTE**<br>1. If the length is a positive value, the original image is stretched, and the image size increases. The edge pixels grow by the set length toward the top, bottom, left, and right edges.<br>2. If the length is a negative value, the original image shrinks as follows, but the image size remains unchanged:<br> (1) The image shrinks from the four edges by the absolute value of length set through **options**. (2) The image is stretched back to the original size with edge pixels.<br>3. Constraints on **options**:<br>(1) The length values for the four edges must be all postive or all negative. That is, the four edges are stretched or shrink at the same time in the same direction. 2. The length values must all be a percentage or a specific value. Combined use of the percentage and specific value is not allowed. 3. If the input value is invalid, the image is displayed as {0, 0, 0, 0}, that is, the image is the same as the original image.|

## Example

### Example 1

```ts
// xxx.ets
@Entry
@Component
struct PixelStretchExample {
  build() {
    Stack() {
      Text('This is the text content with letterSpacing 0.')
        .letterSpacing(0)
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)
        .width('50%')
        .pixelStretchEffect({top:10,left:10,right:10,bottom:10 })
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}

```
Below is how the component looks with the pixel stretch effect applied:

![textPixelStretch1](figures/textPixelStretch1.png)

Below is how the component looks without the pixel stretch effect applied:

![textPixelStretch2](figures/textPixelStretch2.png)

A comparison of the preceding two figures shows that, if the length values are positive, the original image is stretched.

### Example 2

Based on Example 1, change the length values of the pixel stretch effect to negative:

```ts
// xxx.ets
@Entry
@Component
struct PixelStretchExample {
  build() {
    Stack() {
      Text('This is the text content with letterSpacing 0.')
        .letterSpacing(0)
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)
        .width('50%')
        .pixelStretchEffect({top:-10,left:-10,right:-10,bottom:-10 })
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}
```
Below is how the component looks:

![textPixelStretch3](figures/textPixelStretch3.png)

Compared with the original image, the effect drawing is implemented in two steps:

1. The image size is reduced. The resultant size is the originial image size minus the lengths by which the pixels shrink. For example, if the original image size is 100 x 100 and **pixelStretchEffect({top:-10,left:-10,right:-10,bottom:-10})** is set, the resultant size is (100-10-10) x (100-10-10), that is, 8080. 

2. Edge pixels are stretched to restore the image to its original size.
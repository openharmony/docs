# Image Effects

Image effects include blur, shadow, spherical effect, and much more.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## blur

blur(value: number, options?: BlurOptions)

Applies a foreground blur effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name               | Type                                             | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value                 | number                                            | Yes  | Foreground blur effect to apply to the component. The input parameter is the blur radius. The larger the radius is, the more blurred the content is. If the value is **0**, the content is not blurred.|
| options<sup>11+</sup> | [BlurOptions](ts-appendix-enums.md#bluroptions11) | No  | Grayscale parameters.                                                |

## backdropBlur

backdropBlur(value: number, options?: BlurOptions)

Applies a background blur effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name               | Type                                             | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value                 | number                                            | Yes  | Background blur effect to apply to the component. The input parameter is the blur radius. The larger the radius is, the more blurred the background is. If the value is **0**, the background is not blurred.|
| options<sup>11+</sup> | [BlurOptions](ts-appendix-enums.md#bluroptions11) | No  | Grayscale parameters.                                                |

## shadow

shadow(value: ShadowOptions | ShadowStyle)

Applies a shadow effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets, though the [ShadowStyle](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-universal-attributes-image-effect.md#shadowstyle10) is not supported.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ShadowOptions](#shadowoptions) \| [ShadowStyle](#shadowstyle10)<sup>10+</sup> | Yes  | Shadow of the component.<br>When the value type is **ShadowOptions**, the blur radius, shadow color, and offset along the x-axis and y-axis can be specified.<br>When the value type is **ShadowStyle**, the shadow style can be specified.|

## grayscale

grayscale(value: number)

Applies a grayscale effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Grayscale conversion ratio of the component. If the value is **1.0**, the component is completely converted to grayscale. If the value is **0.0**, the component remains unchanged. Between 0 and 1, the value applies a linear multiplier on the grayscale effect. The unit is percentage.<br>Default value: **0.0**<br>Value range: [0, 1]<br>**NOTE**<br>A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**.|

## brightness

brightness(value: number)

Applies a brightness effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Brightness of the component. The value **1** indicates no effects. The value **0** indicates the complete darkness. If the value is less than 1, the brightness decreases. If the value is greater than 1, the brightness increases. A larger value indicates a higher brightness. However, if the value is greater than 2, the brightness does not change significantly with the value.<br>Default value: **1.0**<br>Recommended value range: [0, 2]<br>**NOTE**<br>A value less than 0 evaluates to the value **0**.<br>Since API version 9, this API is supported in ArkTS widgets.|

## saturate

saturate(value: number)

Applies a saturation effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Saturation of the component. The saturation is the ratio of the chromatic component to the achromatic component (gray) in a color. If the value is **1**, the original image is displayed. If the value is greater than **1**, a higher percentage of the chromatic component indicates a higher saturation. If the value is less than **1**, a higher percentage of the achromatic component indicates a lower saturation. The unit is percentage.<br>Default value: **1.0**<br>Value range: [0, +∞)<br>**NOTE**<br>A value less than 0 evaluates to the value **0**.|

## contrast

contrast(value: number)

Applies a contrast effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Contrast of the component. The input parameter is a contrast value. If the value is **1**, the source image is displayed. If the value is greater than 1, a larger value indicates a higher contrast and a clearer image. If the value is less than 1, a smaller value indicates a lower contrast is. If the value is **0**, the image becomes all gray. The unit is percentage.<br>Default value: **1.0**<br>Value range: [0, +∞)<br>**NOTE**<br>A value less than 0 evaluates to the value **0**.|

## invert

invert(value: number | InvertOptions)

Inverts the image.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | number \| [InvertOptions](#invertoptions11)<sup>11+</sup> | Yes  | How the image is inverted.<br>If the value is of the number type, it indicates the inversion ratio. If the value is **1**, the image is completely inverted. If the value is **0**, the image remains unchanged. The unit is percentage.<br>Value range: [0, 1]<br>A value less than 0 evaluates to the value **0**.<br>If the value is of the InvertOptions type, the background color is compared with the threshold. If the grayscale value of the background color is greater than the threshold, the **high** value is used. If the grayscale value of the background color is less than the threshold, the **low** value is used.|

## sepia

sepia(value: number)

Sepia conversion ratio of the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Sepia conversion ratio of the component. If the value is **1**, the image is completely sepia. If the value is **0**, the component remains unchanged. The unit is percentage.|

## hueRotate

hueRotate(value: number | string)

Rotates the hue of the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                                                        |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number \| string | Yes  | Hue rotation angle of the component.<br>Default value: **'0deg'**<br>Value range: (-∞, +∞)<br>**NOTE**<br>A rotation of 360 degrees leaves the color unchanged. A rotation of 180 degrees and then -180 degrees also leaves the color unchanged. When the data type is number, the value **90** is equivalent to **'90deg'**.|

## colorBlend<sup>8+</sup>

colorBlend(value: Color | string | Resource)

Applies a color blend effect to the component.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                          |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| value  | [Color](ts-appendix-enums.md#color) \| string \| [Resource](ts-types.md#resource) | Yes  | Color to blend with the component.|

## sphericalEffect<sup>10+</sup>

sphericalEffect(value: number)

Spherical degree of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Spherical degree of the component.<br>The value ranges from 0 to 1.<br>**NOTE**<br>1. If the value is **0**, the component remains unchanged. If the value is **1**, the component is completely spherical. Between 0 and 1, a larger value indicates a higher spherical degree.<br>A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**.<br>2. If a component image is loaded asynchronously, the spherical effect is not supported. For example, the **\<Image>** component uses asynchronous loading by default, which means that **syncLoad** must be set to **true** to apply the spherical effect. However, this setting is not recommended. Asynchronous loading is also used for **backgroundImage**. Therefore, if **backgroundImage** is set, the spherical effect is not supported.<br>3. If the shadow effect is set for a component, the spherical effect is not supported.|

## lightUpEffect<sup>10+</sup> 

lightUpEffect(value: number)

Light up degree of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API.

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Light up degree of the component.<br>The value ranges from 0 to 1.<br>If the value is **0**, the component is dark. If the value is **1**, the component is fully illuminated. Between 0 and 1, a larger value indicates higher luminance. A value less than 0 evaluates to the value **0**. A value greater than 1 evaluates to the value **1**.|

## pixelStretchEffect<sup>10+</sup> 

pixelStretchEffect(options: PixelStretchEffectOptions)

Pixel stretch effect options.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**System API**: This is a system API.

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| options | [PixelStretchEffectOptions](ts-types.md#pixelstretcheffectoptions10) | Yes  | Pixel stretch effect options.<br>The **options** parameter includes the length by which a pixel is stretched toward the four edges.<br>**NOTE**<br>\1. If the length is a positive value, the original image is stretched, and the image size increases. The edge pixels grow by the set length toward the top, bottom, left, and right edges.<br>\2. 2. If the length is a negative value, the original image shrinks as follows, but the image size remains unchanged:<br> <br>(1) The image shrinks from the four edges by the absolute value of length set through **options**.<br>(2) The image is stretched back to the original size with edge pixels.<br>\3. Constraints on **options**:<br>(1) The length values for the four edges must be all positive or all negative. That is, the four edges are stretched or shrink at the same time in the same direction.<br>(2) The length values must all be a percentage or a specific value. Combined use of the percentage and specific value is not allowed.<br>(3) If the input value is invalid, the image is displayed as {0, 0, 0, 0}, that is, the image is the same as the original image.|

## linearGradientBlur<sup>10+</sup> 

linearGradientBlur(value: number, options: LinearGradientBlurOptions)

Applies a linear gradient foreground blur effect to the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | number                                                       | Yes  | Blur radius. A larger value indicates a higher blur degree. If the value is 0, the content is not blurred.<br>Value range: [0, 60]<br>Linear gradient blur consists of two parts: **fractionStops** and **direction**.|
| options | [LinearGradientBlurOptions](#lineargradientbluroptions10) | Yes  | Linear gradient blur effect.                                      |

## renderGroup<sup>10+</sup>

renderGroup(value: boolean)

Whether the component and its child components are rendered off the screen and then drawn together with its parent.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether the component and its child components are rendered off the screen and then drawn together with its parent. If the opacity of the component is not 1, the drawing effect may vary depending on the value.<br>Default value: **false**|

## blendMode<sup>11+</sup> 

blendMode(value: BlendMode)

Blends the component's background with the content of the component's child node.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                           | Mandatory| Description                                                        |
| ------ | ------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [BlendMode](#blendmode) | Yes  | How the component's background blends with the content of the component's child node.<br>Default value: **BlendMode.NORMAL**<br>**NOTE**<br>Different blend modes produce different effects. The default value is **BlendMode.NORMAL**.<br>**Precautions:**<br>1. Use only one blend mode. Nested blend modes are not recommended, because they may reduce the performance and result in display errors.<br>2. The **SOURCE_IN** and **DESTINATION_IN** blend modes apply only to the images that contain an alpha channel, that is, images that contain opacity information.  |

## useShadowBatching<sup>11+</sup> 

useShadowBatching(value: boolean)

Sets whether to draw shadows of child nodes in the component at the same layer, so that the shadows of elements at the same layer overlap.

**Widget capability**: Since API version 11, this feature is supported in ArkTS widgets.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to draw shadows of child nodes in the component at the same layer, so that the shadows of elements at the same layer overlap.<br>Default value: **false**<br>**NOTE**<br>\1. This feature is disabled by default. In this case, if the shadow radius of a child node is large, the shadows of the child nodes may overlap. When feature is enabled, the shadows of elements do not overlap.<br>\2. Avoid nesting **useShadowBatching**. When used in nested mode, **useShadowBatching** takes effect for the current child node only and cannot be recursively used.|

## ShadowOptions

Provides the shadow attributes, including the blur radius, color, and offset along the x-axis and y-axis.

Since API version 9, this API is supported in ArkTS widgets.

| Name     | Type                                      | Mandatory  | Description                                      |
| ------- | ---------------------------------------- | ---- | ---------------------------------------- |
| radius  | number \| [Resource](ts-types.md#resource) | Yes   | Blur radius of the shadow.<br>Value range: [0, +∞)<br>**NOTE**<br>A value less than 0 evaluates to the value **0**.|
| type<sup>10+</sup> | [ShadowType<sup>10+</sup>](ts-appendix-enums.md#shadowtype10)  |      No   | Shadow type.<br>Default value: **COLOR**       |
| color   | [Color](ts-appendix-enums.md#color) \| string \| [Resource](ts-types.md#resource)\| [ColoringStrategy<sup>10+</sup> ](ts-types.md#coloringstrategy10) | No   | Color of the shadow.<br>The default color is black.<br>**NOTE**<br>Since API version 11, this API supports [ColoringStrategy<sup>10+</sup>](ts-types.md#coloringstrategy10), which cannot be used with ArkTS widgets or the [textShadow](ts-basic-components-text.md#attributes) attribute.<br>With **ColoringStrategy**, the average color or primary color can be obtained, and the obtained color is applied to the shadow drawing area.<br>The **'average'** string can be used to trigger the mode for obtaining the average color, and the **'primary'** string for obtaining the primary color.                      |
| offsetX | number \| [Resource](ts-types.md#resource) | No   | Offset of the shadow along the x-axis.<br>The default value is **0**.                     |
| offsetY | number \| [Resource](ts-types.md#resource) | No   | Offset of the shadow along the y-axis.<br>The default value is **0**.                     |
| fill<sup>11+</sup>     | boolean                                    | No   | Whether to fill the inside of the component with shadow.<br>The default value is **false**.<br>**NOTE**<br>This attribute does not take effect in [textShadow](ts-basic-components-text.md#attributes).                |

## ShadowStyle<sup>10+</sup>

| Name               | Description    |
| ----------------- | ------ |
| OUTER_DEFAULT_XS  | Mini shadow. |
| OUTER_DEFAULT_SM  | Small shadow.  |
| OUTER_DEFAULT_MD  | Medium shadow.  |
| OUTER_DEFAULT_LG  | Large shadow.  |
| OUTER_FLOATING_SM | Floating small shadow.|
| OUTER_FLOATING_MD | Floating medium shadow.|

## BlendMode

| Name          | Description                                                             |
| ---------------| ------                                                            |
| NORMAL         | The top image is superimposed on the bottom image without any blending.                 |
| SOURCE_IN      |The following formula is used for blending: r = s x da. The colors of the top and bottom images are blended, with the opacity of the top image as the weight.|
| DESTINATION_IN |The following formula is used for blending: r = d x sa. The colors of the top and bottom images are blended, with the opacity of the bottom image as the weight.|

## LinearGradientBlurOptions<sup>10+</sup>

| Name         | Type                                                       | Description                                                        |
| ------------- | ----------------------------------------------------------- | ------------------------------------------------------------ |
| fractionStops | Array\<FractionStop>                                    | Gradient blur stops. The value is a set of binary arrays, each of which indicates [blur degree, blur position] and consists of numbers ranging from 0 to 1 (those less than 0 evaluate to **0**, and those greater than 1 evaluate to **1**). The blur positions in the arrays must be in strict ascending order. Noncompliance will be logged. For the blur settings to take effect, the number of binary arrays must be greater than or equal to 2.|
| direction     | [GradientDirection](ts-appendix-enums.md#gradientdirection) | Gradient blur direction.<br>Default value:<br>[GradientDirection](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-appendix-enums.md#gradientdirection).Bottom |

## InvertOptions<sup>11+</sup>

Describes the options for inverting the foreground color.

| Name           |  Type | Mandatory | Description                                      |
| -------------- | ------ | ----- | ------------------------------------------ |
| low            | number | Yes   | Value when the background color is less than the binary interpolation threshold.                 |
| high           | number | Yes   | Value when the background color is greater than or equal to the binary interpolation threshold.             |
| threshold      | number | Yes   | Binary interpolation threshold.                                 |
| thresholdRange | number | Yes   | Binary interpolation threshold range.<br>**NOTE**<br>If the binary interpolation is beyond the threshold range, the average color value is used as the new threshold.|

## Example

### Example 1
Use **blur** to apply a foreground blur effect and **backdropBlur** to apply a background blur effect.
```ts
// xxx.ets
@Entry
@Component
struct BlurEffectsExample {
  build() {
    Column({ space: 10 }) {
      // Blur the font.
      Text('font blur').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Flex({ alignItems: ItemAlign.Center }) {
        Text('original text').margin(10)
        Text('blur text')
          .blur(1).margin(10)
        Text('blur text')
          .blur(2).margin(10)
        Text('blur text')
          .blur(3).margin(10)
      }.width('90%').height(40)
      .backgroundColor(0xF9CF93)


      // Blur the background.
      Text('backdropBlur').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Text()
        .width('90%')
        .height(40)
        .fontSize(16)
        .backdropBlur(3)
        .backgroundImage('/pages/attrs/image/image.jpg')
        .backgroundImageSize({ width: 1200, height: 160 })
    }.width('100%').margin({ top: 5 })
  }
}
```

![textblur](figures/textblur.png)

### Example 2
Apply different image effects.
```ts
// xxx.ets
@Entry
@Component
struct ImageEffectsExample {
  build() {
    Column({ space: 5 }) {
      // Apply the shadow effect.
      Text('shadow').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image'))
        .width('90%')
        .height(30)
        .shadow({ radius: 10, color: Color.Green, offsetX: 20, offsetY: 20 })

      // Add the internal shadow effect.
      Text('shadow').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image'))
        .width('90%')
        .height(30)
        .shadow({ radius: 5, color: Color.Green, offsetX: 20, offsetY: 20,fill:true }).opacity(0.5)

      // Apply the grayscale effect. The grayscale value ranges from 0 to 1. The closer the grayscale value is to 1, the more obvious the grayscale effect is.
      Text('grayscale').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).grayscale(0.3)
      Image($r('app.media.image')).width('90%').height(30).grayscale(0.8)

      // Apply the brightness effect. The value 1 indicates no effects. If the value is less than 1, the brightness decreases. If the value is greater than 1, the brightness increases.
      Text('brightness').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).brightness(1.2)

      // Apply the saturation effect. If the value is 1, the source image is displayed.
      Text('saturate').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).saturate(2.0)
      Image($r('app.media.image')).width('90%').height(30).saturate(0.7)

      // Apply the contrast effect. If the value is 1, the source image is displayed. If the value is greater than 1, a larger value indicates a higher contrast and a clearer image. If the value is less than 1, a smaller value indicates a lower contrast is.
      Text('contrast').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).contrast(2.0)
      Image($r('app.media.image')).width('90%').height(30).contrast(0.8)

      // Invert the image.
      Text('invert').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).invert(0.2)
      Image($r('app.media.image')).width('90%').height(30).invert(0.8)

      // Apply the color blend effect.
      Text('colorBlend').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).colorBlend(Color.Green)
      Image($r('app.media.image')).width('90%').height(30).colorBlend(Color.Blue)

      // Convert the image color to sepia.
      Text('sepia').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).sepia(0.8)

      // Apply the hue rotation effect.
      Text('hueRotate').fontSize(15).fontColor(0xCCCCCC).width('90%')
      Image($r('app.media.image')).width('90%').height(30).hueRotate(90)
    }.width('100%').margin({ top: 5 })
  }
}
```

![imageeffect](figures/imageeffect.png)

### Example 3

Apply a spherical effect to a component to make it appear spherized.

```ts
// xxx.ets
@Entry
@Component
struct SphericalEffectExample {
  build() {
    Stack() {
      TextInput({placeholder: "Enter a percentage."})
        .width('50%')
        .height(35)
        .type(InputType.Number)
        .enterKeyType(EnterKeyType.Done)
        .caretColor(Color.Red)
        .placeholderColor(Color.Blue)
        .placeholderFont({
          size: 20,
          style: FontStyle.Italic,
          weight: FontWeight.Bold
        })
        .sphericalEffect(0.5)
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}

```

Below is how the component looks with the spherical effect applied:

![textInputSpherical1](figures/textInputSpherical1.png)

Below is how the component looks without the spherical effect applied:

![textInputSpherical2](figures/textInputSpherical2.png)

### Example 4

Apply a light up effect to a component.

```ts
// xxx.ets
@Entry
@Component
struct LightUpExample {
  build() {
    Stack() {
      Text('This is the text content with letterSpacing 0.')
        .letterSpacing(0)
        .fontSize(12)
        .border({ width: 1 })
        .padding(10)
        .width('50%')
        .lightUpEffect(0.6)
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}

```

Below is how the component looks with **lightUpEffect** set to **0.6**:

![textLightUp3](figures/textLightUp3.png)

Below is how the component looks with **lightUpEffect** set to **0.2**:

![textLightUp2](figures/textLightUp2.png)

Below is how the component looks without the light up effect applied:

![textLightUp1](figures/textLightUp1.png)

### Example 5

```ts
// xxx.ets
@Entry
@Component
struct LightUpExample {
  @State isLunar: boolean = false
  private selectedDate: Date = new Date('2028-08-08')
  build() {
    Stack() {
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate
      })
        .lunar(this.isLunar)
        .onDateChange((value: Date) => {
          this.selectedDate = value
          console.info('select current date is: ' + value.toString())
        })
        .lightUpEffect(0.6)

    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}
```

![datePickerLightUp2](figures/datePickerLightUp2.png)

Below is how the component looks without the light up effect applied:

![datePickerLightUp1](figures/datePickerLightUp1.png)

### Example 6

You can apply a pixel stretch effect to a component.

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
        .clip(false)
        .width('50%')
        .pixelStretchEffect({top:10,left:10,right:10,bottom:10 })
    }.alignContent(Alignment.Center).width("100%").height("100%")
  }
}

```

Below is how the component looks with **lightUpEffect** set to **0.6**:

![textPixelStretch1](figures/textPixelStretch1.png)

Below is how the component looks without the pixel stretch effect applied:

![textPixelStretch2](figures/textPixelStretch2.png)

### Example 7

Based on Example 6, change the length values of the pixel stretch effect to negative:

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

Compared with the original image, the effect drawing is implemented in two steps:<br>1. The image size is reduced. The resultant size is the original image size minus
the lengths by which the pixels shrink. For example, if the original image size is 100 x 100 and **pixelStretchEffect({top:-10,left:-10,**
**right:-10,bottom:-10})** is set, the resultant size is (100-10-10) x (100-10-10), that is, 8080.<br>2. Edge pixels are stretched to restore the image to its original size.

### Example 8

Apply a linear gradient blur effect to a component.

```ts
// xxx.ets
@Entry
@Component
struct ImageExample1 {
  private_resource1:Resource = $r('app.media.testlinearGradientBlurOrigin')
  @State image_src: Resource = this.private_resource1
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row({ space: 5 }) {
          Image(this.image_src)
            .linearGradientBlur(60, { fractionStops: [[0,0],[0,0.33],[1,0.66],[1,1]], direction: GradientDirection.Bottom })
        }
      }
    }
  }
}

```

![testlinearGradientBlur](figures/testlinearGradientBlur.png)

### Example 9
Example of using **renderGroup**:
```ts
// xxx.ets
@Component
struct Component1 {
  @Prop renderGroupValue: boolean;
  build() {
    Row() {
      Row() {
        Row()
          .backgroundColor(Color.Black)
          .width(100)
          .height(100)
          .opacity(1)
      }
      .backgroundColor(Color.White)
      .width(150)
      .height(150)
      .justifyContent(FlexAlign.Center)
      .opacity(0.6)
      .renderGroup(this.renderGroupValue)
    }
    .backgroundColor(Color.Black)
    .width(200)
    .height(200)
    .justifyContent(FlexAlign.Center)
    .opacity(1)
  }
}
@Entry
@Component
struct RenderGroupExample {
  build() {
    Column() {
      Component1({renderGroupValue: true})
        .margin(20)
      Component1({renderGroupValue: false})
        .margin(20)
    }
    .width("100%")
    .height("100%")
    .alignItems(HorizontalAlign.Center)
  }
}
```

![renderGroup](figures/renderGroup.png)

### Example 10
Example of using **blendMode** alone:
```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Text("test")
        .fontSize(144)
        .fontWeight(FontWeight.Bold)
        .fontColor('#ffff0101')
    }
    .blendMode(BlendMode.NORMAL)
    .height('100%')
    .width('100%')
    .backgroundColor('#ff08ff00')
  }
}
```
BlendMode.NORMAL<br>
![testNormal](figures/testNormal.jpeg)
<br>BlendMode.SOURCE_IN<br>
![testSourceIn](figures/testSourceIn.jpeg)
<br>BlendMode.DESTINATION_IN<br>
![testDestinationIn](figures/testDestinationIn.jpeg)
<br>The current control has multiple subnodes. (All subnodes are drawn in an off-screen buffer, and the drawing result is blended.)

### Example 11
Example of using **blendMode** with **backgroundEffect** to implement the gradient effect of text and images:

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State shColor: Color = Color.White;
  @State sizeDate: number = 20;
  @State rVal: number = 255;
  @State gVal: number = 255;
  @State bVal: number = 255;
  @State aVal: number = 0.1;
  @State rad: number = 40;
  @State satVal: number = 0.8;
  @State briVal: number = 1.5;
  build() {
    Stack() {
      Image($r('app.media.lock'))
      Column() {
        Column({ space: 0}) {
          Text('11')
            .fontSize(144)
            .fontWeight(FontWeight.Bold)
            .fontColor('rgba(255,255,255,1)')
            .fontFamily('HarmonyOS-Sans-Digit')
            .maxLines(1)
            .lineHeight(120*1.25)
            .height(120*1.25)
            .letterSpacing(4*1.25)
          Text('42')
            .fontSize(144)
            .fontWeight(FontWeight.Bold)
            .fontColor('rgba(255,255,255,1)')
            .fontFamily('HarmonyOS-Sans-Digit')
            .maxLines(1)
            .lineHeight(120*1.25)
            .height(120*1.25)
            .letterSpacing(4*1.25)
            .shadow({
              color: 'rgba(0,0,0,0)',
              radius: 20,
              offsetX: 0,
              offsetY: 0
            })
          Row() {
            Text ('October 16')
              .fontSize(this.sizeDate)
              .height(22)
              .fontWeight('medium')
              .fontColor('rgba(255,255,255,1)')
            Text('Monday')
              .fontSize(this.sizeDate)
              .height(22)
              .fontWeight('medium')
              .fontColor('rgba(255,255,255,1)')
          }
        }
        .blendMode(BlendMode.DESTINATION_IN)
        // @ts-ignore
        .backgroundEffect({
          radius: this.rad,
          saturation: this.satVal,
          brightness: this.briVal,
          color: this.getVolumeDialogWindowColor()
        })
        .justifyContent(FlexAlign.Center)
      }
    }
  }
  getVolumeDialogWindowColor(): ResourceColor|string {
    return `rgba(${this.rVal.toFixed(0)}, ${this.gVal.toFixed(0)}, ${this.bVal.toFixed(0)}, ${this.gVal.toFixed(0)})`;
  }
}

```

![testDestinationIn_lockDemo](figures/testDestinationIn_lockDemo.jpeg)

### Example 12
Example of using **InvertOptions**:
```ts
// xxx.ets
 @Entry
 @Component
 struct Index {
   build() {
    Stack() {
      Column()
        Stack(){
          Image($r('app.media.r')).width('100%')
         Column(){
           Column().width("100%").height(30).invert({
             low:0,
             high:1,
             threshold:0.5,
             thresholdRange:0.2
           })
           Column().width("100%").height(30).invert({
             low:0.2,
             high:0.5,
             threshold:0.3,
             thresholdRange:0.2
           })
         }
        }
        .width('100%')
        .height('100%')
    }
  }
 }

```

![testDestinationIn_lockDemo](figures/testInvertOptions.png)

### Example 13
Example of using **UseShadowBatching** with **shadow** to ensure that shadows at the same layer do not overlap:
```ts
// xxx.ets
@Entry
@Component
struct UseShadowBatchingExample {
  build() {
    Column() {
      Column({ space: 10 }) {
        Stack() {

        }.width('90%').height(50).margin({ top: 5 }).backgroundColor(0xFFE4C4)
        .shadow({ radius: 120, color: Color.Green, offsetX: 0, offsetY: 0 })
        .align(Alignment.TopStart).shadow({ radius: 120, color: Color.Green, offsetX: 0, offsetY: 0 })

        Stack() {

        }.width('90%').height(50).margin({ top: 5 }).backgroundColor(0xFFE4C4)
        .align(Alignment.TopStart).shadow({ radius: 120, color: Color.Red, offsetX: 0, offsetY: 0 })
        .width('90%')
        .backgroundColor(Color.White)

        Column() {
          Text()
            .fontWeight(FontWeight.Bold)
            .fontSize(20)
            .fontColor(Color.White)
        }
        .justifyContent(FlexAlign.Center)
        .width(150)
        .height(150)
        .borderRadius(10)
        .backgroundColor(0xf56c6c)
        .shadow({ radius: 300, color: Color.Yellow, offsetX: 0, offsetY: 0 })

        Column() {
          Text()
            .fontWeight(FontWeight.Bold)
            .fontSize(20)
            .fontColor(Color.White)
        }
        .justifyContent(FlexAlign.Center)
        .width(150)
        .height(150)
        .backgroundColor(0x67C23A)
        .borderRadius(10)
        .translate({ y: -50})
        .shadow({ radius: 220, color: Color.Blue, offsetX: 0, offsetY: 0 })
      }
      .useShadowBatching(true)
    }
    .width('100%').margin({ top: 5 })
  }
}
```

![testUseShadowBatchingDemo](figures/testUseShadowBatching.png)

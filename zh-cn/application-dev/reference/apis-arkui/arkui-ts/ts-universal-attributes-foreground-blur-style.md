# 组件内容模糊
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

为当前组件添加内容模糊效果。

>  **说明：**
>
> - 从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - foregroundBlurStyle接口为实时模糊接口，每帧执行实时渲染，性能负载较大。当模糊内容与模糊半径均无需变动时，推荐采用静态模糊接口[blur](../../apis-arkgraphics2d/js-apis-effectKit.md#blur)。最佳实践请参考：[图像模糊动效优化-使用场景](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-fuzzy-scene-performance-optimization#section4945532519)。

## foregroundBlurStyle

foregroundBlurStyle(value: BlurStyle, options?: ForegroundBlurStyleOptions): T

为当前组件提供内容模糊能力。

>**说明：**
>
> 从API version 18开始，该接口支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                     |
| ------- | ------------------------------------------------------------ | ---- | ------------------------ |
| value   | [BlurStyle](ts-universal-attributes-background.md#blurstyle9) | 是   | 内容模糊样式。           |
| options | [ForegroundBlurStyleOptions](#foregroundblurstyleoptions对象说明) | 否   | 内容模糊选项。不传入时使用系统默认模糊效果配置，默认值请参考[ForegroundBlurStyleOptions](#foregroundblurstyleoptions对象说明)。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件，用于链式调用。 |

## foregroundBlurStyle<sup>18+</sup>

foregroundBlurStyle(style: Optional\<BlurStyle>, options?: ForegroundBlurStyleOptions): T

为当前组件提供内容模糊能力。与[foregroundBlurStyle](#foregroundblurstyle)相比，style参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| style   | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[BlurStyle](ts-universal-attributes-background.md#blurstyle9)> | 是   | 内容模糊样式。<br>当style的值为undefined时，恢复为无模糊的内容，此时options参数不生效。 |
| options | [ForegroundBlurStyleOptions](#foregroundblurstyleoptions对象说明) | 否   | 内容模糊选项。不传入时使用系统默认模糊效果配置，默认值请参考[ForegroundBlurStyleOptions](#foregroundblurstyleoptions对象说明)。                                   |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件，用于链式调用。 |

## foregroundBlurStyle<sup>19+</sup>

foregroundBlurStyle(style: Optional\<BlurStyle>, options?: ForegroundBlurStyleOptions, sysOptions?: SystemAdaptiveOptions): T

为当前组件提供内容模糊能力。与[foregroundBlurStyle<sup>18+</sup>](#foregroundblurstyle18)相比，新增了sysOptions参数，即支持系统自适应调节参数，系统可根据设备性能或显示策略等条件自动调节前景模糊的渲染效果。

>  **说明：**
>
>  foregroundBlurStyle接口为实时模糊接口，每帧执行实时渲染，性能负载高于静态模糊接口。当模糊内容与模糊半径均无需变动时，推荐采用静态模糊接口[blur](../../apis-arkgraphics2d/js-apis-effectKit.md#blur)。最佳实践请参考：[图像模糊动效优化-使用场景](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-fuzzy-scene-performance-optimization#section4945532519)。


**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| style   | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[BlurStyle](ts-universal-attributes-background.md#blurstyle9)> | 是   | 内容模糊样式。<br>当style的值为undefined时，恢复为无模糊的内容。 |
| options | [ForegroundBlurStyleOptions](#foregroundblurstyleoptions对象说明) | 否 | 内容模糊选项。不传入时使用系统默认模糊效果配置，默认值请参考[ForegroundBlurStyleOptions](#foregroundblurstyleoptions对象说明)。                                   |
| sysOptions   |  [SystemAdaptiveOptions](ts-universal-attributes-background.md#systemadaptiveoptions19)    |   否   |  系统自适应调节参数，用于控制是否启用系统对模糊效果的自适应调整。<br>默认值：{ disableSystemAdaptation: false }    |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| T | 返回当前组件，用于链式调用。 |

## ForegroundBlurStyleOptions对象说明

继承自[BlurStyleOptions](#blurstyleoptions)，内容模糊样式选项。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## BlurStyleOptions

模糊样式选项，用于配置模糊效果的深浅色模式、取色模式、灰阶模糊参数和模糊程度。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                        | 类型                                                | 只读 | 可选 | 说明                                                         |
| --------------------------- | ------------------------------------------------------- | ---- | ---- |------------------------------------------------------------ |
| colorMode     | [ThemeColorMode](#themecolormode枚举说明) | 否 | 是  | 内容模糊效果使用的深浅色模式。<br>默认值：ThemeColorMode.SYSTEM<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| adaptiveColor | [AdaptiveColor](#adaptivecolor枚举说明)   | 否 | 是   | 内容模糊效果使用的自适应取色模式。<br>默认值：AdaptiveColor.DEFAULT<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| blurOptions<sup>11+</sup> | [BlurOptions](#bluroptions11)         | 否 | 是    | 灰阶模糊参数，仅对图像中的黑白色生效，对彩色无效果。<br>默认值：grayscale: [0,0] <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| scale<sup>12+</sup> | number   | 否 | 是  | 内容模糊效果程度。<br>默认值：1.0 <br>取值范围：[0.0, 1.0] <br>1.0表示模糊程度最高。 <br>0.0表示模糊程度最低。<br>超出取值范围时，按边界值自动修正。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|

## ThemeColorMode枚举说明

设置颜色模式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值 | 说明       |
| ------ | --- | ------- |
| SYSTEM | 0 | 跟随系统深浅色模式。 |
| LIGHT  | 1 | 固定使用浅色模式。  |
| DARK   | 2 | 固定使用深色模式。  |

## AdaptiveColor枚举说明

取色模式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 值 | 说明                        |
| ------- | ---- | --------------------- |
| DEFAULT | 0 | 不使用取色模糊。使用系统预设颜色作为蒙版颜色。采用非DEFAULT方式的取色计算耗时高于DEFAULT方式。    |
| AVERAGE | 1 | 使用取色模糊。将取色区域的颜色平均值作为蒙版颜色。采用AVERAGE方式较DEFAULT方式耗时，在性能敏感场景建议使用DEFAULT。 |

## BlurOptions<sup>11+</sup>
灰阶模糊参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        |   类型   |   只读 | 可选 | 说明                        |
| ----        |  ----   |   ---- | ------- | -------------------  |
| grayscale   |  [number, number]   |   否 | 否   |  灰阶模糊参数，两参数取值范围均为[0,127]。对图像中的黑白色进行色阶调整，使其趋于灰色，视觉过渡更加柔和，对图像中的彩色调整没有效果。参数一表示对黑色的提亮程度，参数二表示对白色的压暗程度，参数值越大调整效果越明显（黑白色变得越灰）。例如：设置参数为（20，20），图片中的黑色像素RGB：[0, 0, 0]会调整为[20, 20, 20]，白色像素RGB：[255, 255, 255]会调整为[235, 235, 235]（255-20），图像中的彩色像素维持不变。 |


## 示例

该示例主要演示通过foregroundBlurStyle为图片设置内容模糊效果。

```ts
// xxx.ets
@Entry
@Component
struct ForegroundBlurStyleDemo {
  build() {
    Column() {
      Text('Thin Material').fontSize(30).fontColor(0xCCCCCC)
      // $r("app.media.bg")需要替换为开发者所需的图像资源文件。
      Image($r('app.media.bg'))
        .width(300)
        .height(350)
        .foregroundBlurStyle(BlurStyle.Thin,
          { colorMode: ThemeColorMode.LIGHT, adaptiveColor: AdaptiveColor.DEFAULT, scale: 1.0 })
    }
    .height('100%')
    .width('100%')
  }
}
```

![zh-cn_image_background_blur_style](figures/image-foreground-blur_style.png)

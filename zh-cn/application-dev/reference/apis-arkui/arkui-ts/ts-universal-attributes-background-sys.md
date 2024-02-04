# 背景设置(系统接口)

设置组件的背景样式。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  当前页面仅包含本模块的系统接口，其他公开接口参见[背景设置](ts-universal-attributes-background.md)。

## backgroundBrightness<sup>11+</sup> 

backgroundBrightness(params: BackgroundBrightnessOptions)

设置组件背景提亮效果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口

**参数：** 

| 参数名            | 类型                                     | 必填   | 说明                                       |
| ------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| params        | [BackgroundBrightnessOptions](#backgroundbrightnessoptions11对象说明) | 是    |  设置组件背景提亮效果，包括：亮度变化速率，提亮程度。      |

## BackgroundBlurStyleOptions<sup>10+</sup>对象说明

继承自[BlurStyleOptions](ts-universal-attributes-foreground-blur-style-sys.md)

## BackgroundBrightnessOptions<sup>11+</sup>对象说明

**系统接口：** 此接口为系统接口

| 名称            | 参数类型                                     | 必填   | 描述                                       |
| ------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| rate          | number | 是    | 亮度变化速率。亮度变化速率越大，亮度下降速度越快，亮度提升程度越低。<br/>默认值：0.0 <br/>取值范围：(0.0, +∞)<br/> |
| lightUpDegree | number | 是    | 提亮程度。提亮程度越大，亮度提升程度越大。<br/> 默认值：0.0 <br/>取值范围：[-1.0, 1.0]<br/> |

## 示例

设置组件背景提亮效果。

```ts
// xxx.ets
@Entry
@Component
struct BackgroundBrightnessDemo {
  build() {
    Column() {
      Row() {
        Text("BackgroundBrightness")
      }
      .width(200)
      .height(100)
      .position({ x: 100, y: 100 })
      .backgroundBlurStyle(BlurStyle.Thin, { colorMode: ThemeColorMode.LIGHT, adaptiveColor: AdaptiveColor.DEFAULT, scale: 1.0 })
      .backgroundBrightness({rate:0.5,lightUpDegree:0.5}) // 背景提亮效果
    }
    .width('100%')
    .height('100%')
    .backgroundImage($r('app.media.image'))
    .backgroundImageSize(ImageSize.Cover)
  }
}
```

效果图如下：

rate和lightUpDegree参数值为0.5,0.5：

![zh-cn_image_background_brightness1](figures/zh-cn_image_background_brightness1.png)

修改rate和lightUpDegree参数值为0.5,-0.1：

![zh-cn_image_background_brightness2](figures/zh-cn_image_background_brightness2.png)

去掉backgroundBrightness的设置，效果如下：

![zh-cn_image_background_brightness3](figures/zh-cn_image_background_brightness3.png)
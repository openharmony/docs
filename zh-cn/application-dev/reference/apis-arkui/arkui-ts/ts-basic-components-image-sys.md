# Image (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyujie43-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @HelloCrease-->

Image为图片组件，常用于在应用中显示图片。

> **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[Image](ts-basic-components-image.md)。

## 属性

### analyzerConfig<sup>11+</sup>

analyzerConfig(config: ImageAnalyzerConfig)

设置AI分析类型，包括主体识别和文字识别功能，默认全部开启。分析类型不支持动态修改。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明         |
| ------ | --------------------------------------------- | ---- | ------------ |
| config | [ImageAnalyzerConfig](ts-image-common.md#imageanalyzerconfig12) | 是   | AI分析类型。 |

### edgeAntialiasing<sup>11+</sup>

edgeAntialiasing(value: number)

设置SVG图源抗锯齿效果，仅对SVG图源生效。取值范围为$(0.333, 1.333]$，有效数字保留小数点后3位。

适用于超低分辨率设备（PPI低于200的设备）的SVG图源的锯齿优化，存在一定的性能影响，请谨慎使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                |
| ------ | ------ | ---- | ----------------------------------- |
| value  | number | 是   | SVG图源抗锯齿效果。<br/>默认值：0.0 |

### pointLight<sup>11+</sup>

pointLight(value: PointLightStyle)

设置点光源样式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明         |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| value  | [PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle) | 是   | 点光源样式。 |

### enhancedImageQuality<sup>12+</sup>

enhancedImageQuality(imageQuality: ResolutionQuality)

设置图像解码时的图像解码分辨率选项。

该属性不支持 svg、[PixelMap](../../apis-image-kit/arkts-apis-image-PixelMap.md)和[DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor) 等非解码图片类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                    | 必填 | 说明                             |
| ------ | --------------------------------------- | ---- | -------------------------------- |
| imageQuality | [ResolutionQuality](#resolutionquality12) | 是   | 图像解码分辨率质量。 |

## ResolutionQuality<sup>12+</sup>

图像解码时的图像解码分辨率选项。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值                     | 说明                    |
| ------ | --------------------------  | --------------------------  |
| Low   | 1  | 低图像分辨率，解码时间适中。   |
| Medium | 2 | 中等图像分辨率，解码时间适中。  |
| High   | 3   | 高图像分辨率，解码时间长。    |

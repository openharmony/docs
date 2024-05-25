# Image (系统接口)

Image为图片组件，常用于在应用中显示图片。

> **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[Image](ts-basic-components-image.md)。


## 属性

| 名称                             | 参数类型                                                | 描述                                                         |
| -------------------------------- | ------------------------------------------------------- | ------------------------------------------------------------ |
| analyzerConfig<sup>11+</sup> | [ImageAnalyzerConfig](#imageanalyzerconfig11)                                                 | 设置AI分析类型，包括主体识别和文字识别功能，默认全部开启。<br>**说明：**<br /> 分析类型不支持动态修改。<br>**系统接口：**<br /> 此接口为系统接口。|
| edgeAntialiasing<sup>11+</sup> | number                                                 | 设置SVG图源抗锯齿效果，仅对svg图源生效。<br/>取值范围：$[0.333, 1.333]$，有效数字保留小数点后3位。<br/>默认值：$0$。<br>**说明：**<br />适用于超低分辨率设备（PPI低于200的设备）的SVG图源的锯齿优化，存在一定的性能影响，请谨慎使用。 <br>**系统接口：**<br /> 此接口为系统接口。|

## pointLight<sup>11+</sup>

pointLight(value: PointLightStyle)

设置点光源样式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明         |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| value  | [PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle) | 是   | 点光源样式。 |

## ImageAnalyzerConfig<sup>11+</sup>

从API version 11开始，该接口支持在ArkTS卡片中使用。

图片AI分析类型配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 描述           |
| -------- | -------------- |
| SUBJECT | 主体识别功能。 |
| TEXT | 文字识别功能。 |

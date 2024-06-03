# Image (System API)

The **\<Image>** component is usually used to display images in applications.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [Image](ts-basic-components-image.md).

## Attributes

### analyzerConfig<sup>11+</sup>

analyzerConfig(config: ImageAnalyzerConfig)

Sets the type of the AI analyzer, including subject recognition and character recognition. By default, all types are supported. The type of the AI analyzer cannot be dynamically modified.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                         | Mandatory| Description        |
| ------ | --------------------------------------------- | ---- | ------------ |
| config | [ImageAnalyzerConfig](#imageanalyzerconfig11) | Yes  | Type of the AI analyzer.|

### edgeAntialiasing<sup>11+</sup>

edgeAntialiasing(value: number)

Sets the edge antialiasing for the image. This attribute applies only to an SVG image. The value range is $[0.333, 1.333]$. The value is valid up to three decimal places.

This attribute can be used to fix aliasing in SVG images on devices with PPI lower than 200, but it may compromise the performance. Exercise caution when using this attribute.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                               |
| ------ | ------ | ---- | ----------------------------------- |
| value  | number | Yes  | Edge antialiasing of the image.<br>Default value: **$0$**|

## ImageAnalyzerConfig<sup>11+</sup>

Since API version 11, this API is supported in ArkTS widgets.

Describes the type of the AI analyzer.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Description          |
| -------- | -------------- |
| SUBJECT | Object recognition.|
| TEXT | Text recognition.|

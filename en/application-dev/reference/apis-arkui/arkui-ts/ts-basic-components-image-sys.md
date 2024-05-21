# Image (System API)

The **\<Image>** component is usually used to display images in applications.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [Image](ts-basic-components-image.md).


## Attributes

| Name                            | Type                                               | Description                                                        |
| -------------------------------- | ------------------------------------------------------- | ------------------------------------------------------------ |
| analyzerConfig<sup>11+</sup> | [ImageAnalyzerConfig](#imageanalyzerconfig11)                                                 | Type of the AI analyzer, including subject recognition and character recognition. By default, all types are supported.<br>**NOTE**<br> The type of the AI analyzer cannot be dynamically modified.<br>**System API**:<br> This is a system API.|
| edgeAntialiasing<sup>11+</sup> | number                                                 | Edge antialiasing of the image. This attribute applies only to an SVG image.<br>Value range: $[0.333, 1.333]$. The value is valid up to three decimal places.<br>Default value: **$0$**<br>**NOTE**<br>This attribute can be used to fix aliasing in SVG images on devices with PPI lower than 200, but it may compromise the performance. Exercise caution when using this attribute.<br>**System API**:<br> This is a system API.|

## ImageAnalyzerConfig<sup>11+</sup>

This API can be used in ArkTS widgets since API version 11.

Describes the type of the AI analyzer.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Description          |
| -------- | -------------- |
| SUBJECT | Object recognition.|
| TEXT | Text recognition.|

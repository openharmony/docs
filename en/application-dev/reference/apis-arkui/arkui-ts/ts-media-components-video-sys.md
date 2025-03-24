# Video (System API)

The **Video** component is used to play a video and control its playback.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [Video](ts-media-components-video.md).

## Attributes

### surfaceBackgroundColor<sup>15+</sup>

surfaceBackgroundColor(color: ColorMetrics)

Sets the background color of the **SurfaceNode** in the **Video** component.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name|       Type   | Mandatory|           Description               |
| ------ | ------------ | ---- | ---------------------------- |
| color  | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | Yes  | Background color of the **SurfaceNode** in the **Video** component. Only black and transparent colors are supported. Any other color will default to black.<br>Default value: **Color.Black**|

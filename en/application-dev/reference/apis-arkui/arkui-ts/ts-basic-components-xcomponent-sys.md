# XComponent

**XComponent** provides a surface for graphics rendering and media data input into your view. You can customize the position and size of the surface as needed.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [XComponent](ts-basic-components-xcomponent.md).

## Attributes

### hdrBrightness<sup>14+</sup>

hdrBrightness(brightness: number)

Sets the brightness of HDR video playback for the component.

**System API**: This attribute can be used in system APIs since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                  |
| -------- | ------- | ---- | ---------------------- |
| brightness | number | Yes  | Brightness of HDR video playback.<br>Value range: 0.0 to 1.0.<br>Values less than 0 are equivalent to 0, and values greater than 1 are equivalent to 1.<br>**0** indicates the brightness of the SDR video, and **1** indicates the brightness of the HDR video.|

  > **NOTE**
  >
  > This attribute is effective only when **type** is set to **SURFACE**.
  >
  > It is not supported for **XComponent** components created using the [ArkUI NDK API](../../../ui/ndk-build-ui-overview.md).

### enableTransparentLayer<sup>18+</sup>

enableTransparentLayer(enabled: boolean)

Sets whether to enable an independent layer for the **XComponent** component when its background is transparent.

**System API**: This attribute can be used in system APIs since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type    | Mandatory| Description                  |
| ------- | ------- | ---- | ---------------------- |
| enabled | boolean | Yes  | Whether to enable an independent layer for the **XComponent** component when its background is transparent.|

  > **NOTE**
  >
  > This attribute is effective only when **type** is set to **SURFACE**.
  >
  > It is not supported for **XComponent** components created using the [ArkUI NDK API](../../../ui/ndk-build-ui-overview.md).

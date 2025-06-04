# XComponent

**XComponent** provides a surface for graphics rendering and media data input into your view. You can customize the position and size of the surface as needed.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [XComponent](ts-basic-components-xcomponent.md).

## APIs

### XComponentOptions<sup>12+</sup>

Defines the options of the **XComponent**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                  |
| -------- | ------- | ---- | ---------------------- |
| screenId<sup>17+</sup> | number | No| Associated screen ID of the component. The component can display the image of the associated screen. **System API**: This is a system API.|

  > **NOTE**
  >
  > This attribute is effective only when **type** is set to **SURFACE**.
  >
  > It is not supported for **XComponent** components created using the [ArkUI NDK API](../../../ui/ndk-build-ui-overview.md).

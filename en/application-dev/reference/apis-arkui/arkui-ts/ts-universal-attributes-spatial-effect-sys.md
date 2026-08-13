# Spatial Effect (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=d2c50a60c602f7446ec67ad08cb4d81ecd2717cf translatedAt=2026-08-11T01:48:50.246Z pushedAt=2026-08-13T10:56:45.538Z -->

Used to set spatial effect parameters for a component.

> **NOTE**
>
> - The spatial effect only applies to child components of [DepthComponent](./ts-basic-components-depthcomponent-sys.md), and takes effect only when the related parameters of **DepthComponent** are correctly set.
>
> - The spatial effect does not support the following components: [Web](../../../web/web-component-overview.md), [XComponent](./ts-basic-components-xcomponent.md), [RichEditor](./ts-basic-components-richeditor.md), [RichText](./ts-basic-components-richtext.md), [Video](./ts-media-components-video.md), [Component3D](./ts-basic-components-component3d.md), and [EmbeddedComponent](./ts-container-embedded-component.md).
>
> - The APIs provided by this module are system APIs.

**Since:** 26.0.0

## spatialEffect

spatialEffect(params: SpatialEffectParams | undefined): T

Sets the spatial effect for the component.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System API**: This is a system API.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| params | [SpatialEffectParams](#spatialeffectparams) \| undefined | Yes | Spatial effect parameters. When the parameter is **undefined**, the spatial effect is removed. |

**Return value**

| Type | Description |
| -------- | -------- |
| T | Current component. |

## SpatialEffectParams

Defines the spatial effect parameters.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System API**: This is a system API.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| position | [SpatialPosition](#spatialposition) \| number | No | No | Spatial position of the component. Supports depth information of struct type or numeric type.<br/> The struct type [SpatialPosition](#spatialposition) defines the spatial position by four corners. <br/> The numeric type defines the component's spatial depth information.|
| occlusionWeight | number | No | Yes | Occlusion weight of the spatial effect. Value range: [0, 1], default value: **0**.<br>**0** indicates no occlusion, **1** indicates complete occlusion, and intermediate values indicate partial occlusion. |

## SpatialPosition

Defines the four corner positions in 3D space.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System API**: This is a system API.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| leftTop | [DepthVector3](#depthvector3) | No | No | Position of the upper left corner in 3D space. Unitless; its value indicates the coordinates in 3D space. |
| rightTop | [DepthVector3](#depthvector3) | No | No | Position of the upper right corner in 3D space. Unitless; its value indicates the coordinates in 3D space. |
| leftBottom | [DepthVector3](#depthvector3) | No | No | Position of the lower left corner in 3D space. Unitless; its value indicates the coordinates in 3D space. |
| rightBottom | [DepthVector3](#depthvector3) | No | No | Position of the lower right corner in 3D space. Unitless; its value indicates the coordinates in 3D space. |
| positionMode | [SpatialPositionMode](#spatialpositionmode) | No | Yes | Coordinate mode of the corner positions. Default value: **SpatialPositionMode.WORLD_XYZ**. |

## DepthVector3

Defines a 3D vector in the depth of field space.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System API**: This is a system API.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| x | number | No | No | X component. Unitless; its value indicates the coordinate in the 3D space. |
| y | number | No | No | Y component. Unitless; its value indicates the coordinate in the 3D space. |
| z | number | No | No | Z component. Unitless; its value indicates the coordinate in the 3D space. |

## SpatialPositionMode

Defines the spatial position mode, which indicates the coordinate system used for corner positions.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System API**: This is a system API.

| Name | Value | Description |
| -------- | -------- | -------- |
| WORLD_XYZ | 0 | World XYZ coordinate mode. The X, Y, and Z components are all world coordinates. |
| NDC_XY_WORLD_Z | 1 | NDC XY and world Z coordinate mode. The X and Y components use NDC (normalized device coordinates), and the Z component uses world coordinates. |

## DepthVector4

Defines a 4D vector in the depth of field space.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System API**: This is a system API.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| x | number | No | No | X component. Unitless; its value indicates the coordinate in 3D space. |
| y | number | No | No | Y component. Unitless; its value indicates the coordinate in 3D space. |
| z | number | No | No | Z component. Unitless; its value indicates the coordinate in 3D space. |
| w | number | No | No | W component. Unitless; its value indicates the coordinate in 3D space. |

## DepthColorRGB

Defines the RGB color in the depth of field space.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System API**: This is a system API.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| red | number | No | No | Red component. Value range: [0, 255]. |
| green | number | No | No | Green component. Value range: [0, 255]. |
| blue | number | No | No | Blue component. Value range: [0, 255]. |

## Example

See DepthComponent [example](./ts-basic-components-depthcomponent-sys.md#examples).
<!--no_check-->
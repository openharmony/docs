# Types

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=62f43af624b3dd8e087aab6967d3e43810260062 translatedAt=2026-08-03T03:57:18.253Z pushedAt=2026-08-04T03:49:34.427Z -->

This module defines type aliases related to image processing, primarily including value types for PixelMap HDR metadata. These aliases are used in conjunction with the HdrMetadataKey keys to standardize the expression and transmission of metadata in HDR image processing.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## HdrMetadataValue<sup>12+</sup>

type HdrMetadataValue = HdrMetadataType | HdrStaticMetadata | ArrayBuffer | HdrGainmapMetadata

HDR metadata value type used by a PixelMap, which corresponds to the [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12) key.

**System capability**: SystemCapability.Multimedia.Image.Core

| Type               | Description                                           |
| ------------------- | ----------------------------------------------- |
| [HdrMetadataType](arkts-apis-image-e.md#hdrmetadatatype12) | Metadata value type corresponding to the HDR_METADATA_TYPE key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12), used to represent the type of HDR metadata. Different values correspond to different types of HDR metadata. The appropriate value must be selected based on the actual metadata type of the HDR image, and the corresponding metadata member fields must be populated. |
| [HdrStaticMetadata](arkts-apis-image-i.md#hdrstaticmetadata12) | Metadata value type corresponding to the HDR_STATIC_METADATA key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12), used to store HDR static metadata. |
| ArrayBuffer | Metadata value type corresponding to the HDR_DYNAMIC_METADATA key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12), used to store HDR dynamic metadata. The format follows relevant HDR dynamic metadata standards. |
| [HdrGainmapMetadata](arkts-apis-image-i.md#hdrgainmapmetadata12) | Metadata value type corresponding to the HDR_GAINMAP_METADATA key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12), used to store HDR gain map metadata. For details, see ISO 21496-1. |
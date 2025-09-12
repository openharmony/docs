# Types
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## HdrMetadataValue<sup>12+</sup>

type HdrMetadataValue = HdrMetadataType | HdrStaticMetadata | ArrayBuffer | HdrGainmapMetadata

Describes the HDR metadata values used by a PixelMap, which corresponds to the values available for [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12).

**System capability**: SystemCapability.Multimedia.Image.Core

| Type               | Description                                           |
| ------------------- | ----------------------------------------------- |
| [HdrMetadataType](arkts-apis-image-e.md#hdrmetadatatype12) | Metadata value corresponding to the **HDR_GAINMAP_METADATA** key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12).|
| [HdrStaticMetadata](arkts-apis-image-i.md#hdrstaticmetadata12) | Metadata value corresponding to the **HDR_STATIC_METADATA** key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12).|
| ArrayBuffer | Metadata value corresponding to the **HDR_DYNAMIC_METADATA** key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12).|
| [HdrGainmapMetadata](arkts-apis-image-i.md#hdrgainmapmetadata12) | Metadata value corresponding to the **HDR_GAINMAP_METADATA** key in [HdrMetadataKey](arkts-apis-image-e.md#hdrmetadatakey12).|

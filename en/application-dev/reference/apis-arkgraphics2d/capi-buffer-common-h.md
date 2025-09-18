# buffer_common.h

## Overview

Declares the common types used in the NativeBuffer module.<br>From API version 12, some type definitions are moved from native_buffer.h to this header file. These types can be used in versions earlier than API version 12.

**File to import**: <native_buffer/buffer_common.h>

**Library**: libnative_buffer.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Related module**: [OH_NativeBuffer](capi-oh-nativebuffer.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeBuffer_ColorXY](capi-oh-nativebuffer-oh-nativebuffer-colorxy.md) | OH_NativeBuffer_ColorXY | Describes the X and Y coordinates of the primary color.|
| [OH_NativeBuffer_Smpte2086](capi-oh-nativebuffer-oh-nativebuffer-smpte2086.md) | OH_NativeBuffer_Smpte2086 | Describes the SMPTE ST 2086 static metadata.|
| [OH_NativeBuffer_Cta861](capi-oh-nativebuffer-oh-nativebuffer-cta861.md) | OH_NativeBuffer_Cta861 | Describes the CTA-861.3 static metadata.|
| [OH_NativeBuffer_StaticMetadata](capi-oh-nativebuffer-oh-nativebuffer-staticmetadata.md) | OH_NativeBuffer_StaticMetadata | Describes the HDR static metadata.|

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) | OH_NativeBuffer_ColorSpace | Defines an enum for the color spaces of an **OH_NativeBuffer** instance. It is relocated from **native_buffer.h** to this header file for a more cohesive presentation.|
| [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype) | OH_NativeBuffer_MetadataType | Defines an enum for the **OH_NativeBuffer** image standards.|
| [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) | OH_NativeBuffer_MetadataKey | Defines an enum for the keys that specify the HDR metadata of an **OH_NativeBuffer** instance.|

## Enum Description

### OH_NativeBuffer_ColorSpace

```
enum OH_NativeBuffer_ColorSpace
```

**Description**

Defines an enum for the color spaces of an **OH_NativeBuffer** instance. Moved from native_buffer.h to this header file.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 11

| Value| Description|
| -- | -- |
| OH_COLORSPACE_NONE | No color space is available.|
| OH_COLORSPACE_BT601_EBU_FULL | The color gamut is BT601_P, the transfer function is BT709, the conversion matrix is BT601_P, and the data range is RANGE_FULL.|
| OH_COLORSPACE_BT601_SMPTE_C_FULL | The color gamut is BT601_N, the transfer function is BT709, the conversion matrix is BT601_N, and the data range is RANGE_FULL.|
| OH_COLORSPACE_BT709_FULL | The color gamut is BT709, the transfer function is BT709, the conversion matrix is BT709, and the data range is RANGE_FULL.|
| OH_COLORSPACE_BT2020_HLG_FULL | The color gamut is BT2020, the transfer function is HLG, the conversion matrix is BT2020, and the data range is RANGE_FULL.|
| OH_COLORSPACE_BT2020_PQ_FULL | The color gamut is BT2020, the transfer function is PQ, the conversion matrix is BT2020, and the data range is RANGE_FULL.|
| OH_COLORSPACE_BT601_EBU_LIMIT | The color gamut is BT601_P, the transfer function is BT709, the conversion matrix is BT601_P, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_BT601_SMPTE_C_LIMIT | The color gamut is BT601_N, the transfer function is BT709, the conversion matrix is BT601_N, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_BT709_LIMIT | The color gamut is BT709, the transfer function is BT709, the conversion matrix is BT709, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_BT2020_HLG_LIMIT | The color gamut is BT2020, the transfer function is HLG, the conversion matrix is BT2020, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_BT2020_PQ_LIMIT | The color gamut is BT2020, the transfer function is PQ, the conversion matrix is BT2020, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_SRGB_FULL | The color gamut is SRGB, the transfer function is SRGB, the conversion matrix is BT601_N, and the data range is RANGE_FULL.|
| OH_COLORSPACE_P3_FULL | The color gamut is P3_D65, the transfer function is SRGB, the conversion matrix is P3, and the data range is RANGE_FULL.|
| OH_COLORSPACE_P3_HLG_FULL | The color gamut is P3_D65, the transfer function is HLG, the conversion matrix is P3, and the data range is RANGE_FULL.|
| OH_COLORSPACE_P3_PQ_FULL | The color gamut is P3_D65, the transfer function is PQ, the conversion matrix is P3, and the data range is RANGE_FULL.|
| OH_COLORSPACE_ADOBERGB_FULL | The color gamut is ADOBERGB, the transfer function is ADOBERGB, the conversion matrix is ADOBERGB, and the data range is RANGE_FULL.|
| OH_COLORSPACE_SRGB_LIMIT | The color gamut is SRGB, the transfer function is SRGB, the conversion matrix is BT601_N, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_P3_LIMIT | The color gamut is P3_D65, the transfer function is SRGB, the conversion matrix is P3, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_P3_HLG_LIMIT | The color gamut is P3_D65, the transfer function is HLG, the conversion matrix is P3, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_P3_PQ_LIMIT | The color gamut is P3_D65, the transfer function is PQ, the conversion matrix is P3, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_ADOBERGB_LIMIT | The color gamut is ADOBERGB, the transfer function is ADOBERGB, the conversion matrix is ADOBERGB, and the data range is RANGE_LIMITED.|
| OH_COLORSPACE_LINEAR_SRGB | The color gamut is SRGB, and the transfer function is LINEAR.|
| OH_COLORSPACE_LINEAR_BT709 | Equivalent to OH_COLORSPACE_LINEAR_SRGB.|
| OH_COLORSPACE_LINEAR_P3 | The color gamut is P3_D65, and the transfer function is LINEAR.|
| OH_COLORSPACE_LINEAR_BT2020 | The color gamut is BT2020, and the transfer function is LINEAR.|
| OH_COLORSPACE_DISPLAY_SRGB | It is equivalent to **OH_COLORSPACE_SRGB_FULL**.|
| OH_COLORSPACE_DISPLAY_P3_SRGB | It is equivalent to **OH_COLORSPACE_P3_FULL**.|
| OH_COLORSPACE_DISPLAY_P3_HLG | It is equivalent to **OH_COLORSPACE_P3_HLG_FULL**.|
| OH_COLORSPACE_DISPLAY_P3_PQ | It is equivalent to **OH_COLORSPACE_P3_PQ_FULL**.|
| OH_COLORSPACE_DISPLAY_BT2020_SRGB | The color gamut is BT2020, the transfer function is SRGB, the conversion matrix is BT2020, and the data range is RANGE_FULL.|
| OH_COLORSPACE_DISPLAY_BT2020_HLG | Equivalent to OH_COLORSPACE_BT2020_HLG_FULL.|
| OH_COLORSPACE_DISPLAY_BT2020_PQ | It is equivalent to **OH_COLORSPACE_BT2020_PQ_FULL**.|

### OH_NativeBuffer_MetadataType

```
enum OH_NativeBuffer_MetadataType
```

**Description**

Defines an enum for the **OH_NativeBuffer** image standards.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

| Value| Description|
| -- | -- |
| OH_VIDEO_HDR_HLG | Video HLG.|
| OH_VIDEO_HDR_HDR10 | Video HDR10.|
| OH_VIDEO_HDR_VIVID | Video HDR Vivid.|
| OH_VIDEO_NONE = -1 |  No metadata.<br>**Since**: 13|

### OH_NativeBuffer_MetadataKey

```
enum OH_NativeBuffer_MetadataKey
```

**Description**

Defines an enum for the keys that specify the HDR metadata of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

| Value| Description|
| -- | -- |
| OH_HDR_METADATA_TYPE | Metadata type. For details about the value, see [OH_NativeBuffer_MetadataType](capi-buffer-common-h.md#oh_nativebuffer_metadatatype). The size is the size of OH_NativeBuffer_MetadataType.|
| OH_HDR_STATIC_METADATA | Static metadata. For details about the value, see [OH_NativeBuffer_StaticMetadata](capi-oh-nativebuffer-oh-nativebuffer-staticmetadata.md). The size is the size of OH_NativeBuffer_StaticMetadata.|
| OH_HDR_DYNAMIC_METADATA | Dynamic metadata. For details about the available options, see the SEI byte stream in the video stream. The value range of **size** is 1-3000.|

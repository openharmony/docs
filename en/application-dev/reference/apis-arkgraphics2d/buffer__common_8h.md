# buffer_common.h


## Overview

The **buffer_common.h** file declares the common types used in the NativeBuffer module.

Certain type definitions have been relocated from **native_buffer.h** to this header file for a more cohesive presentation. These types were available prior to API version 12 and can be used seamlessly across all versions.

**Library**: libnative_buffer.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Related module**: [OH_NativeBuffer](_o_h___native_buffer.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| struct  [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md) | Describes the X and Y coordinates of the primary color. |
| struct  [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md) | Describes the SMPTE ST 2086 static metadata. |
| struct  [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md) | Describes the CTA-861.3 static metadata. |
| struct  [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md) | Describes the HDR static metadata. |


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace)  [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) | Defines an enum for the color spaces of an **OH_NativeBuffer** instance. It is relocated from **native_buffer.h** to this header file for a more cohesive presentation. |
| typedef enum [OH_NativeBuffer_MetadataType](_o_h___native_buffer.md#oh_nativebuffer_metadatatype)  [OH_NativeBuffer_MetadataType](_o_h___native_buffer.md#oh_nativebuffer_metadatatype) | Defines an enum for the **OH_NativeBuffer** image standards. |
| typedef struct [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md)  [OH_NativeBuffer_ColorXY](_o_h___native_buffer.md#oh_nativebuffer_colorxy) | Defines a struct for the X and Y coordinates of the primary color. |
| typedef struct [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md)  [OH_NativeBuffer_Smpte2086](_o_h___native_buffer.md#oh_nativebuffer_smpte2086) | Defines a struct for the SMPTE ST 2086 static metadata. |
| typedef struct [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md)  [OH_NativeBuffer_Cta861](_o_h___native_buffer.md#oh_nativebuffer_cta861) | Defines a struct for the CTA-861.3 static metadata. |
| typedef struct [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md)  [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer.md#oh_nativebuffer_staticmetadata) | Defines a struct for the HDR static metadata. |
| typedef enum [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey)  [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) | Defines an enum for the keys that specify the HDR metadata of an **OH_NativeBuffer** instance. |


### Enums

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace-1) {<br>OH_COLORSPACE_NONE, OH_COLORSPACE_BT601_EBU_FULL, OH_COLORSPACE_BT601_SMPTE_C_FULL, OH_COLORSPACE_BT709_FULL,<br>OH_COLORSPACE_BT2020_HLG_FULL, OH_COLORSPACE_BT2020_PQ_FULL, OH_COLORSPACE_BT601_EBU_LIMIT, OH_COLORSPACE_BT601_SMPTE_C_LIMIT,<br>OH_COLORSPACE_BT709_LIMIT, OH_COLORSPACE_BT2020_HLG_LIMIT, OH_COLORSPACE_BT2020_PQ_LIMIT, OH_COLORSPACE_SRGB_FULL,<br>OH_COLORSPACE_P3_FULL, OH_COLORSPACE_P3_HLG_FULL, OH_COLORSPACE_P3_PQ_FULL, OH_COLORSPACE_ADOBERGB_FULL,<br>OH_COLORSPACE_SRGB_LIMIT, OH_COLORSPACE_P3_LIMIT, OH_COLORSPACE_P3_HLG_LIMIT, OH_COLORSPACE_P3_PQ_LIMIT,<br>OH_COLORSPACE_ADOBERGB_LIMIT, OH_COLORSPACE_LINEAR_SRGB, OH_COLORSPACE_LINEAR_BT709, OH_COLORSPACE_LINEAR_P3,<br>OH_COLORSPACE_LINEAR_BT2020, OH_COLORSPACE_DISPLAY_SRGB, OH_COLORSPACE_DISPLAY_P3_SRGB, OH_COLORSPACE_DISPLAY_P3_HLG,<br>OH_COLORSPACE_DISPLAY_P3_PQ, OH_COLORSPACE_DISPLAY_BT2020_SRGB, OH_COLORSPACE_DISPLAY_BT2020_HLG, OH_COLORSPACE_DISPLAY_BT2020_PQ<br>} | Enumerates the color spaces of an **OH_NativeBuffer** instance. It is relocated from **native_buffer.h** to this header file for a more cohesive presentation. |
| [OH_NativeBuffer_MetadataType](_o_h___native_buffer.md#oh_nativebuffer_metadatatype-1) { OH_VIDEO_HDR_HLG, OH_VIDEO_HDR_HDR10, OH_VIDEO_HDR_VIVID, OH_VIDEO_NONE = -1 } | Enumerates the **OH_NativeBuffer** image standards. |
| [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey-1) { OH_HDR_METADATA_TYPE, OH_HDR_STATIC_METADATA, OH_HDR_DYNAMIC_METADATA } | Enumerates the keys that specify the HDR metadata of an **OH_NativeBuffer** instance. |

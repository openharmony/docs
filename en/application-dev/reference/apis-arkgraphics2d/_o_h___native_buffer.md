# OH_NativeBuffer

## Overview

The **OH_NativeBuffer** module provides the capabilities of **NativeBuffer**. Using the functions provided by this module, you can apply for, use, and release the shared memory, and query its attributes.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_buffer.h](native__buffer_8h.md) | Declares the functions for obtaining and using **NativeBuffer**.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | Describes the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.| 
| struct  [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md) | Describes the plane information of an image.| 
| struct  [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md) | Describes the plane information of images in an **OH_NativeBuffer** instance.| 
| struct  [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md) | Describes the X and Y coordinates of the primary color.| 
| struct  [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md) | Describes the SMPTE ST 2086 static metadata.| 
| struct  [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md) | Describes the CTA-861.3 static metadata.| 
| struct  [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md) | Describes the HDR static metadata.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_NativeBuffer](#oh_nativebuffer)  [OH_NativeBuffer](#oh_nativebuffer) | Provides the declaration of an **OH_NativeBuffer** struct.| 
| typedef enum [OH_NativeBuffer_Usage](#oh_nativebuffer_usage)  [OH_NativeBuffer_Usage](#oh_nativebuffer_usage) | Defines an enum for the **OH_NativeBuffer** usages.| 
| typedef enum [OH_NativeBuffer_Format](#oh_nativebuffer_format)  [OH_NativeBuffer_Format](#oh_nativebuffer_format) | Defines an enum for the **OH_NativeBuffer** formats.| 
| typedef enum [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace)  [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) | Defines an enum for the color spaces of an **OH_NativeBuffer** instance.| 
| typedef enum [OH_NativeBuffer_TransformType](#oh_nativebuffer_transformtype)  [OH_NativeBuffer_TransformType](#oh_nativebuffer_transformtype) | Defines an enum for the transform types of an **OH_NativeBuffer** instance.| 
| typedef enum [OH_NativeBuffer_ColorGamut](#oh_nativebuffer_colorgamut)  [OH_NativeBuffer_ColorGamut](#oh_nativebuffer_colorgamut) | Defines an enum for the color gamuts of an **OH_NativeBuffer** instance.| 
| typedef enum [OHNativeErrorCode](_native_window.md#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | Defines an enum for the error codes.| 
| typedef struct [OH_NativeBuffer_Config](_o_h___native_buffer___config.md)  [OH_NativeBuffer_Config](#oh_nativebuffer_config) | Defines the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.| 
| typedef struct [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md)  [OH_NativeBuffer_Plane](#oh_nativebuffer_plane) | Defines a struct for the plane information of an image.| 
| typedef struct [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md)  [OH_NativeBuffer_Planes](#oh_nativebuffer_planes) | Defines a struct for the plane information of images in an **OH_NativeBuffer** instance.| 
| typedef enum [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype)  [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype) | Defines an enum for the **OH_NativeBuffer** image standards.| 
| typedef struct [OH_NativeBuffer_ColorXY](_o_h___native_buffer___color_x_y.md)  [OH_NativeBuffer_ColorXY](#oh_nativebuffer_colorxy) | Defines a struct for the X and Y coordinates of the primary color.| 
| typedef struct [OH_NativeBuffer_Smpte2086](_o_h___native_buffer___smpte2086.md)  [OH_NativeBuffer_Smpte2086](#oh_nativebuffer_smpte2086) | Defines a struct for the SMPTE ST 2086 static metadata.| 
| typedef struct [OH_NativeBuffer_Cta861](_o_h___native_buffer___cta861.md)  [OH_NativeBuffer_Cta861](#oh_nativebuffer_cta861) | Defines a struct for the CTA-861.3 static metadata.| 
| typedef struct [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md)  [OH_NativeBuffer_StaticMetadata](#oh_nativebuffer_staticmetadata) | Defines a struct for the HDR static metadata.| 
| typedef enum [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey)  [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) | Defines an enum for the keys that specify the HDR metadata of an **OH_NativeBuffer** instance.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_NativeBuffer_Usage](#oh_nativebuffer_usage-1) {<br>NATIVEBUFFER_USAGE_CPU_READ = (1ULL &lt;&lt; 0), NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL &lt;&lt; 1), NATIVEBUFFER_USAGE_MEM_DMA = (1ULL &lt;&lt; 3), NATIVEBUFFER_USAGE_HW_RENDER = (1ULL &lt;&lt; 8),<br>NATIVEBUFFER_USAGE_HW_TEXTURE = (1ULL &lt;&lt; 9), NATIVEBUFFER_USAGE_CPU_READ_OFTEN = (1ULL &lt;&lt; 16), NATIVEBUFFER_USAGE_ALIGNMENT_512 = (1ULL &lt;&lt; 18)<br>} | Enumerates the **OH_NativeBuffer** usages.| 
| [OH_NativeBuffer_Format](#oh_nativebuffer_format-1) {<br>NATIVEBUFFER_PIXEL_FMT_CLUT8 = 0, NATIVEBUFFER_PIXEL_FMT_CLUT1, NATIVEBUFFER_PIXEL_FMT_CLUT4, NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3,<br>NATIVEBUFFER_PIXEL_FMT_RGBA_5658, NATIVEBUFFER_PIXEL_FMT_RGBX_4444, NATIVEBUFFER_PIXEL_FMT_RGBA_4444, NATIVEBUFFER_PIXEL_FMT_RGB_444,<br>NATIVEBUFFER_PIXEL_FMT_RGBX_5551, NATIVEBUFFER_PIXEL_FMT_RGBA_5551, NATIVEBUFFER_PIXEL_FMT_RGB_555, NATIVEBUFFER_PIXEL_FMT_RGBX_8888,<br>NATIVEBUFFER_PIXEL_FMT_RGBA_8888, NATIVEBUFFER_PIXEL_FMT_RGB_888, NATIVEBUFFER_PIXEL_FMT_BGR_565, NATIVEBUFFER_PIXEL_FMT_BGRX_4444,<br>NATIVEBUFFER_PIXEL_FMT_BGRA_4444, NATIVEBUFFER_PIXEL_FMT_BGRX_5551, NATIVEBUFFER_PIXEL_FMT_BGRA_5551, NATIVEBUFFER_PIXEL_FMT_BGRX_8888,<br>NATIVEBUFFER_PIXEL_FMT_BGRA_8888, NATIVEBUFFER_PIXEL_FMT_YUV_422_I, NATIVEBUFFER_PIXEL_FMT_YCBCR_422_SP, NATIVEBUFFER_PIXEL_FMT_YCRCB_422_SP,<br>NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP, NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP, NATIVEBUFFER_PIXEL_FMT_YCBCR_422_P, NATIVEBUFFER_PIXEL_FMT_YCRCB_422_P,<br>NATIVEBUFFER_PIXEL_FMT_YCBCR_420_P, NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P, NATIVEBUFFER_PIXEL_FMT_YUYV_422_PKG, NATIVEBUFFER_PIXEL_FMT_UYVY_422_PKG,<br>NATIVEBUFFER_PIXEL_FMT_YVYU_422_PKG, NATIVEBUFFER_PIXEL_FMT_VYUY_422_PKG, NATIVEBUFFER_PIXEL_FMT_RGBA_1010102, NATIVEBUFFER_PIXEL_FMT_YCBCR_P010,<br>NATIVEBUFFER_PIXEL_FMT_YCRCB_P010, NATIVEBUFFER_PIXEL_FMT_RAW10, NATIVEBUFFER_PIXEL_FMT_VENDER_MASK = 0X7FFF0000, NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF<br>} | Enumerates the **OH_NativeBuffer** formats.| 
| [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace-1) {<br>OH_COLORSPACE_NONE, OH_COLORSPACE_BT601_EBU_FULL, OH_COLORSPACE_BT601_SMPTE_C_FULL, OH_COLORSPACE_BT709_FULL,<br>OH_COLORSPACE_BT2020_HLG_FULL, OH_COLORSPACE_BT2020_PQ_FULL, OH_COLORSPACE_BT601_EBU_LIMIT, OH_COLORSPACE_BT601_SMPTE_C_LIMIT,<br>OH_COLORSPACE_BT709_LIMIT, OH_COLORSPACE_BT2020_HLG_LIMIT, OH_COLORSPACE_BT2020_PQ_LIMIT, OH_COLORSPACE_SRGB_FULL,<br>OH_COLORSPACE_P3_FULL, OH_COLORSPACE_P3_HLG_FULL, OH_COLORSPACE_P3_PQ_FULL, OH_COLORSPACE_ADOBERGB_FULL,<br>OH_COLORSPACE_SRGB_LIMIT, OH_COLORSPACE_P3_LIMIT, OH_COLORSPACE_P3_HLG_LIMIT, OH_COLORSPACE_P3_PQ_LIMIT,<br>OH_COLORSPACE_ADOBERGB_LIMIT, OH_COLORSPACE_LINEAR_SRGB, OH_COLORSPACE_LINEAR_BT709, OH_COLORSPACE_LINEAR_P3,<br>OH_COLORSPACE_LINEAR_BT2020, OH_COLORSPACE_DISPLAY_SRGB, OH_COLORSPACE_DISPLAY_P3_SRGB, OH_COLORSPACE_DISPLAY_P3_HLG,<br>OH_COLORSPACE_DISPLAY_P3_PQ, OH_COLORSPACE_DISPLAY_BT2020_SRGB, OH_COLORSPACE_DISPLAY_BT2020_HLG, OH_COLORSPACE_DISPLAY_BT2020_PQ<br>} | Enumerates the color spaces of an **OH_NativeBuffer** instance.| 
| [OH_NativeBuffer_TransformType](#oh_nativebuffer_transformtype-1) {<br>NATIVEBUFFER_ROTATE_NONE = 0, NATIVEBUFFER_ROTATE_90, NATIVEBUFFER_ROTATE_180, NATIVEBUFFER_ROTATE_270,<br>NATIVEBUFFER_FLIP_H, NATIVEBUFFER_FLIP_V, NATIVEBUFFER_FLIP_H_ROT90, NATIVEBUFFER_FLIP_V_ROT90,<br>NATIVEBUFFER_FLIP_H_ROT180, NATIVEBUFFER_FLIP_V_ROT180, NATIVEBUFFER_FLIP_H_ROT270, NATIVEBUFFER_FLIP_V_ROT270<br>} | Enumerates the transform types of an **OH_NativeBuffer** instance.| 
| [OH_NativeBuffer_ColorGamut](#oh_nativebuffer_colorgamut-1) {<br>NATIVEBUFFER_COLOR_GAMUT_NATIVE = 0, NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT601 = 1, NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT709 = 2, NATIVEBUFFER_COLOR_GAMUT_DCI_P3 = 3,<br>NATIVEBUFFER_COLOR_GAMUT_SRGB = 4, NATIVEBUFFER_COLOR_GAMUT_ADOBE_RGB = 5, NATIVEBUFFER_COLOR_GAMUT_DISPLAY_P3 = 6, NATIVEBUFFER_COLOR_GAMUT_BT2020 = 7,<br>NATIVEBUFFER_COLOR_GAMUT_BT2100_PQ = 8, NATIVEBUFFER_COLOR_GAMUT_BT2100_HLG = 9, NATIVEBUFFER_COLOR_GAMUT_DISPLAY_BT2020 = 10<br>} | Enumerates the color gamuts of an **OH_NativeBuffer** instance.| 
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br>NATIVE_ERROR_UNKNOWN = 50002000,NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. | 
| [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype-1) { OH_VIDEO_HDR_HLG, OH_VIDEO_HDR_HDR10, OH_VIDEO_HDR_VIVID } | Enumerates the **OH_NativeBuffer** image standards.| 
| [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey-1) { OH_HDR_METADATA_TYPE, OH_HDR_STATIC_METADATA, OH_HDR_DYNAMIC_METADATA } | Enumerates the keys that specify the HDR metadata of an **OH_NativeBuffer** instance.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) \* [OH_NativeBuffer_Alloc](#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.| 
| int32_t [OH_NativeBuffer_Reference](#oh_nativebuffer_reference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.| 
| int32_t [OH_NativeBuffer_Unreference](#oh_nativebuffer_unreference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.| 
| void [OH_NativeBuffer_GetConfig](#oh_nativebuffer_getconfig) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Obtains the attributes of an **OH_NativeBuffer** instance.| 
| int32_t [OH_NativeBuffer_Map](#oh_nativebuffer_map) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, void \*\*virAddr) | Maps the ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.| 
| int32_t [OH_NativeBuffer_Unmap](#oh_nativebuffer_unmap) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Unmaps the ION memory corresponding to an **OH_NativeBuffer** instance from the process address space.| 
| uint32_t [OH_NativeBuffer_GetSeqNum](#oh_nativebuffer_getseqnum) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Obtains the sequence number of an **OH_NativeBuffer** instance.| 
| int32_t [OH_NativeBuffer_SetColorSpace](#oh_nativebuffer_setcolorspace) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) colorSpace) | Sets the color space for an **OH_NativeBuffer** instance.| 
| int32_t [OH_NativeBuffer_MapPlanes](#oh_nativebuffer_mapplanes) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, void \*\*virAddr, [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md) \*outPlanes) | Maps the multi-channel ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.| 
| int32_t [OH_NativeBuffer_FromNativeWindowBuffer](#oh_nativebuffer_fromnativewindowbuffer) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*nativeWindowBuffer, [OH_NativeBuffer](#oh_nativebuffer) \*\*buffer) | Converts an **OHNativeWindowBuffer** instance to an **OH_NativeBuffer** instance.| 
| int32_t [OH_NativeBuffer_GetColorSpace](#oh_nativebuffer_getcolorspace) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace) \*colorSpace) | Obtains the color space of an **OH_NativeBuffer** instance.| 
| int32_t [OH_NativeBuffer_SetMetadataValue](#oh_nativebuffer_setmetadatavalue) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) metadataKey, int32_t size, uint8_t \*metaData) | Sets a metadata value for an **OH_NativeBuffer** instance.| 
| int32_t [OH_NativeBuffer_GetMetadataValue](#oh_nativebuffer_getmetadatavalue) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey) metadataKey, int32_t \*size, uint8_t \*\*metaData) | Obtains the metadata value of an **OH_NativeBuffer** instance.| 


## Type Description


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**Description**

Provides the declaration of an **OH_NativeBuffer** struct.

**Since**: 9


### OH_NativeBuffer_ColorGamut

```
typedef enum OH_NativeBuffer_ColorGamut OH_NativeBuffer_ColorGamut
```

**Description**

Defines an enum for the color gamuts of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_ColorSpace

```
typedef enum OH_NativeBuffer_ColorSpace OH_NativeBuffer_ColorSpace
```

**Description**

Defines an enum for the color spaces of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 11


### OH_NativeBuffer_ColorXY

```
typedef struct OH_NativeBuffer_ColorXY OH_NativeBuffer_ColorXY
```

**Description**

Defines a struct for the X and Y coordinates of the primary color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_Config

```
typedef struct OH_NativeBuffer_Config OH_NativeBuffer_Config
```

**Description**

Defines the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9


### OH_NativeBuffer_Cta861

```
typedef struct OH_NativeBuffer_Cta861 OH_NativeBuffer_Cta861
```

**Description**

Defines a struct for the CTA-861.3 static metadata.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_Format

```
typedef enum OH_NativeBuffer_Format OH_NativeBuffer_Format
```

**Description**

Defines an enum for the **OH_NativeBuffer** formats.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 10


### OH_NativeBuffer_MetadataKey

```
typedef enum OH_NativeBuffer_MetadataKey OH_NativeBuffer_MetadataKey
```

**Description**

Defines an enum for the keys that specify the HDR metadata of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_MetadataType

```
typedef enum OH_NativeBuffer_MetadataType OH_NativeBuffer_MetadataType
```

**Description**

Defines an enum for the **OH_NativeBuffer** image standards.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_Plane

```
typedef struct OH_NativeBuffer_Plane OH_NativeBuffer_Plane
```

**Description**

Defines a struct for the plane information of an image.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_Planes

```
typedef struct OH_NativeBuffer_Planes OH_NativeBuffer_Planes
```

**Description**

Defines a struct for the plane information of images in an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_Smpte2086

```
typedef struct OH_NativeBuffer_Smpte2086 OH_NativeBuffer_Smpte2086
```

**Description**

Defines a struct for the SMPTE ST 2086 static metadata.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_StaticMetadata

```
typedef struct OH_NativeBuffer_StaticMetadata OH_NativeBuffer_StaticMetadata
```

**Description**

Defines a struct for the HDR static metadata.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_TransformType

```
typedef enum OH_NativeBuffer_TransformType OH_NativeBuffer_TransformType
```

**Description**

Defines an enum for the transform types of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12


### OH_NativeBuffer_Usage

```
typedef enum OH_NativeBuffer_Usage OH_NativeBuffer_Usage
```

**Description**

Defines an enum for the **OH_NativeBuffer** usages.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 10


### OHNativeErrorCode

```
typedef enum OHNativeErrorCodeOHNativeErrorCode
```

**Description**

Defines an enum for the error codes.

**Since**: 12


## Enum Description


### OH_NativeBuffer_ColorGamut

```
enum OH_NativeBuffer_ColorGamut
```

**Description**

Enumerates the color gamuts of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NATIVEBUFFER_COLOR_GAMUT_NATIVE | Default gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT601 | Standard BT.601 color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT709 | Standard BT.709 color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_DCI_P3 | DCI P3 color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_SRGB | SRGB color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_ADOBE_RGB | Adobe RGB color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_DISPLAY_P3 | Display P3 color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_BT2020 | BT.2020 color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_BT2100_PQ | BT.2100 PQ color gamut.| 
| NATIVEBUFFER_COLOR_GAMUT_BT2100_HLG | BT.2100 HLG color gamut format| 
| NATIVEBUFFER_COLOR_GAMUT_DISPLAY_BT2020 | Display BT.2020 color gamut.| 


### OH_NativeBuffer_ColorSpace

```
enum OH_NativeBuffer_ColorSpace
```

**Description**

Enumerates the color spaces of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 11

| Value| Description| 
| -------- | -------- |
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
| OH_COLORSPACE_LINEAR_BT709 | It is equivalent to **OH_COLORSPACE_LINEAR_SRGB**.| 
| OH_COLORSPACE_LINEAR_P3 | The color gamut is P3_D65, and the transfer function is LINEAR.| 
| OH_COLORSPACE_LINEAR_BT2020 | The color gamut is BT2020, and the transfer function is LINEAR.| 
| OH_COLORSPACE_DISPLAY_SRGB | It is equivalent to **OH_COLORSPACE_SRGB_FULL**.| 
| OH_COLORSPACE_DISPLAY_P3_SRGB | It is equivalent to **OH_COLORSPACE_P3_FULL**.| 
| OH_COLORSPACE_DISPLAY_P3_HLG | It is equivalent to **OH_COLORSPACE_P3_HLG_FULL**.| 
| OH_COLORSPACE_DISPLAY_P3_PQ | It is equivalent to **OH_COLORSPACE_P3_PQ_FULL**.| 
| OH_COLORSPACE_DISPLAY_BT2020_SRGB | The color gamut is BT2020, the transfer function is SRGB, the conversion matrix is BT2020, and the data range is RANGE_FULL.| 
| OH_COLORSPACE_DISPLAY_BT2020_HLG | It is equivalent to **OH_COLORSPACE_BT2020_HLG_FULL**.| 
| OH_COLORSPACE_DISPLAY_BT2020_PQ | It is equivalent to **OH_COLORSPACE_BT2020_PQ_FULL**.| 


### OH_NativeBuffer_Format

```
enum OH_NativeBuffer_Format
```

**Description**

Enumerates the **OH_NativeBuffer** formats.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 10

| Value| Description| 
| -------- | -------- |
| NATIVEBUFFER_PIXEL_FMT_CLUT8<sup>12+</sup> | CLUT8.| 
| NATIVEBUFFER_PIXEL_FMT_CLUT1<sup>12+</sup> | CLUT1.| 
| NATIVEBUFFER_PIXEL_FMT_CLUT4<sup>12+</sup> | CLUT4.| 
| NATIVEBUFFER_PIXEL_FMT_RGB_565 | RGB565.| 
| NATIVEBUFFER_PIXEL_FMT_RGBA_5658 | RGBA5658.| 
| NATIVEBUFFER_PIXEL_FMT_RGBX_4444 | RGBX4444.| 
| NATIVEBUFFER_PIXEL_FMT_RGBA_4444 | RGBA4444.| 
| NATIVEBUFFER_PIXEL_FMT_RGB_444 | RGB444.| 
| NATIVEBUFFER_PIXEL_FMT_RGBX_5551 | RGBX5551.| 
| NATIVEBUFFER_PIXEL_FMT_RGBA_5551 | RGBA5551.| 
| NATIVEBUFFER_PIXEL_FMT_RGB_555 | RGB555.| 
| NATIVEBUFFER_PIXEL_FMT_RGBX_8888 | RGBX8888.| 
| NATIVEBUFFER_PIXEL_FMT_RGBA_8888 | RGBA8888.| 
| NATIVEBUFFER_PIXEL_FMT_RGB_888 | RGB888.| 
| NATIVEBUFFER_PIXEL_FMT_BGR_565 | BGR565.| 
| NATIVEBUFFER_PIXEL_FMT_BGRX_4444 | BGRX4444.| 
| NATIVEBUFFER_PIXEL_FMT_BGRA_4444 | BGRA4444.| 
| NATIVEBUFFER_PIXEL_FMT_BGRX_5551 | BGRX5551.| 
| NATIVEBUFFER_PIXEL_FMT_BGRA_5551 | BGRA5551.| 
| NATIVEBUFFER_PIXEL_FMT_BGRX_8888 | BGRX8888.| 
| NATIVEBUFFER_PIXEL_FMT_BGRA_8888 | BGRA8888.| 
| NATIVEBUFFER_PIXEL_FMT_YUV_422_I<sup>12+</sup> | YUV422 interleaved.| 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_422_SP<sup>12+</sup> | YCbCr422 semi-planar.| 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_422_SP<sup>12+</sup> | YCrCb422 semi-planar.| 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP<sup>12+</sup> | YCbCr420 semi-planar.| 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP<sup>12+</sup> | YCrCb420 semi-planar.| 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_422_P<sup>12+</sup> | YCbCr422 planar.| 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_422_P<sup>12+</sup> | YCrCb422 planar.| 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_420_P<sup>12+</sup> | YCbCr420 planar.| 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P<sup>12+</sup> | YCrCb420 planar.| 
| NATIVEBUFFER_PIXEL_FMT_YUYV_422_PKG<sup>12+</sup> | YUYV422 packed.| 
| NATIVEBUFFER_PIXEL_FMT_UYVY_422_PKG<sup>12+</sup> | UYVY422 packed.| 
| NATIVEBUFFER_PIXEL_FMT_YVYU_422_PKG<sup>12+</sup> | YVYU422 packed.| 
| NATIVEBUFFER_PIXEL_FMT_VYUY_422_PKG<sup>12+</sup> | VYUY422 packed.| 
| NATIVEBUFFER_PIXEL_FMT_RGBA_1010102<sup>12+</sup> | RGBA_1010102 packed.| 
| NATIVEBUFFER_PIXEL_FMT_YCBCR_P010<sup>12+</sup> | YCBCR420 semi-planar 10-bit packed.| 
| NATIVEBUFFER_PIXEL_FMT_YCRCB_P010<sup>12+</sup> | YCRCB420 semi-planar 10-bit packed.| 
| NATIVEBUFFER_PIXEL_FMT_RAW10<sup>12+</sup> | Raw 10-bit packed.| 
| NATIVEBUFFER_PIXEL_FMT_VENDER_MASK<sup>12+</sup> | Vender mask.| 
| NATIVEBUFFER_PIXEL_FMT_BUTT | Invalid format.| 


### OH_NativeBuffer_MetadataKey

```
enum OH_NativeBuffer_MetadataKey
```

**Description**

Enumerates the keys that specify the HDR metadata of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_HDR_METADATA_TYPE | Metadata type. For details about the available options, see [OH_NativeBuffer_MetadataType](#oh_nativebuffer_metadatatype). **size** indicates the size of **OH_NativeBuffer_MetadataType**.| 
| OH_HDR_STATIC_METADATA | Static metadata. For details about the available options, see [OH_NativeBuffer_StaticMetadata](_o_h___native_buffer___static_metadata.md). **size** indicates the size of **OH_NativeBuffer_StaticMetadata**.| 
| OH_HDR_DYNAMIC_METADATA | Dynamic metadata. For details about the available options, see the SEI byte stream in the video stream. The value range of **size** is 1-3000.| 


### OH_NativeBuffer_MetadataType

```
enum OH_NativeBuffer_MetadataType
```

**Description**

Enumerates the **OH_NativeBuffer** image standards.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_VIDEO_HDR_HLG | Video HLG.| 
| OH_VIDEO_HDR_HDR10 | Video HDR10.| 
| OH_VIDEO_HDR_VIVID | Video HDR Vivid.| 


### OH_NativeBuffer_TransformType

```
enum OH_NativeBuffer_TransformType
```

**Description**

Enumerates the transform types of an **OH_NativeBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NATIVEBUFFER_ROTATE_NONE | No rotation.| 
| NATIVEBUFFER_ROTATE_90 | Rotates by 90 degrees.| 
| NATIVEBUFFER_ROTATE_180 | Rotates by 180 degrees.| 
| NATIVEBUFFER_ROTATE_270 | Rotates by 270 degrees.| 
| NATIVEBUFFER_FLIP_H | Flips horizontally.| 
| NATIVEBUFFER_FLIP_V | Flips vertically.| 
| NATIVEBUFFER_FLIP_H_ROT90 | Flips horizontally and rotates by 90 degrees.| 
| NATIVEBUFFER_FLIP_V_ROT90 | Flips vertically and rotates by 90 degrees.| 
| NATIVEBUFFER_FLIP_H_ROT180 | Flips horizontally and rotates by 180 degrees.| 
| NATIVEBUFFER_FLIP_V_ROT180 | Flips vertically and rotates by 180 degrees.| 
| NATIVEBUFFER_FLIP_H_ROT270 | Flips horizontally and rotates by 270 degrees.| 
| NATIVEBUFFER_FLIP_V_ROT270 | Flips vertically and rotates by 270 degrees.| 


### OH_NativeBuffer_Usage

```
enum OH_NativeBuffer_Usage
```

**Description**

Enumerates the **OH_NativeBuffer** usages.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 10

| Value| Description| 
| -------- | -------- |
| NATIVEBUFFER_USAGE_CPU_READ | CPU readable.| 
| NATIVEBUFFER_USAGE_CPU_WRITE | CPU writable.| 
| NATIVEBUFFER_USAGE_MEM_DMA | Direct memory access to the buffer.| 
| NATIVEBUFFER_USAGE_HW_RENDER<sup>12+</sup> | GPU writable.| 
| NATIVEBUFFER_USAGE_HW_TEXTURE<sup>12+</sup> | GPU readable.| 
| NATIVEBUFFER_USAGE_CPU_READ_OFTEN<sup>12+</sup> | Direct mapping of CPU.| 
| NATIVEBUFFER_USAGE_ALIGNMENT_512<sup>12+</sup> | 512-byte alignment.| 


### OHNativeErrorCode

```
enum OHNativeErrorCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NATIVE_ERROR_OK | The operation is successful.| 
| NATIVE_ERROR_INVALID_ARGUMENTS | An input parameter is invalid.| 
| NATIVE_ERROR_NO_PERMISSION | You do not have the permission to perform the operation.| 
| NATIVE_ERROR_NO_BUFFER | No buffer is available.| 
| NATIVE_ERROR_NO_CONSUMER | The consumer does not exist.| 
| NATIVE_ERROR_NOT_INIT | Not initialized.| 
| NATIVE_ERROR_CONSUMER_CONNECTED | The consumer is connected.| 
| NATIVE_ERROR_BUFFER_STATE_INVALID | The buffer status does not meet the expectation.| 
| NATIVE_ERROR_BUFFER_IN_CACHE | The buffer is already in the buffer queue.| 
| NATIVE_ERROR_BUFFER_QUEUE_FULL | The queue is full.| 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE | The buffer is not in the buffer queue.|
| NATIVE_ERROR_CONSUMER_DISCONNECTED | The consumer is disconnected.|
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | No listener is registered on the consumer side.|
| NATIVE_ERROR_UNSUPPORTED | The device or platform does not support the operation.| 
| NATIVE_ERROR_UNKNOWN | Unknown error. Check the log.| 
| NATIVE_ERROR_HDI_ERROR  | Failed to call the HDI.  | 
| NATIVE_ERROR_BINDER_ERROR  | Cross-process communication failed.  | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN | The EGL environment is abnormal.| 
| NATIVE_ERROR_EGL_API_FAILED | Failed to call the EGL APIs.| 


## Function Description


### OH_NativeBuffer_Alloc()

```
OH_NativeBuffer* OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config* config)
```

**Description**

Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.

This function must be used in pair with **OH_NativeBuffer_Unreference**. Otherwise, memory leak occurs.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| config | Pointer to an **OH_NativeBuffer_Config** instance.| 

**Returns**

Returns the pointer to the **OH_NativeBuffer** instance created if the operation is successful; returns **NULL** otherwise.


### OH_NativeBuffer_FromNativeWindowBuffer()

```
int32_t OH_NativeBuffer_FromNativeWindowBuffer (OHNativeWindowBuffer *nativeWindowBuffer, OH_NativeBuffer **buffer )
```

**Description**

Converts an **OHNativeWindowBuffer** instance to an **OH_NativeBuffer** instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| nativeWindowBuffer | Pointer to an **OHNativeWindowBuffer** instance.| 
| buffer | Pointer to an **OH_NativeBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_GetColorSpace()

```
int32_t OH_NativeBuffer_GetColorSpace (OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace *colorSpace )
```

**Description**

Obtains the color space of an **OH_NativeBuffer** instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 
| colorSpace | Pointer to the color space. For details about the available options, see [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace).| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_GetConfig()

```
void OH_NativeBuffer_GetConfig (OH_NativeBuffer *buffer, OH_NativeBuffer_Config* config )
```

**Description**

Obtains the attributes of an **OH_NativeBuffer** instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 
| config | Pointer to an **OH_NativeBuffer_Config** instance, which is used to receive the attributes of **OH_NativeBuffer**.| 


### OH_NativeBuffer_GetMetadataValue()

```
int32_t OH_NativeBuffer_GetMetadataValue (OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey, int32_t *size, uint8_t **metaData )
```

**Description**

Obtains the metadata value of an **OH_NativeBuffer** instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 
| metadataKey | Key of the metadata. For details about the available options, see [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey).| 
| size | Pointer to the size of the uint8_t vector. For details about the available options, see [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey).| 
| metaData | Double pointer to the uint8_t vector.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_GetSeqNum()

```
uint32_t OH_NativeBuffer_GetSeqNum (OH_NativeBuffer *buffer)
```

**Description**

Obtains the sequence number of an **OH_NativeBuffer** instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 

**Returns**

Returns the unique sequence number of the **OH_NativeBuffer** instance.


### OH_NativeBuffer_Map()

```
int32_t OH_NativeBuffer_Map (OH_NativeBuffer *buffer, void **virAddr )
```

**Description**

Maps the ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.

This function must be used in pair with **OH_NativeBuffer_Unmap**.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 
| virAddr | Double pointer to the address of the virtual memory.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_MapPlanes()

```
int32_t OH_NativeBuffer_MapPlanes (OH_NativeBuffer *buffer, void **virAddr, OH_NativeBuffer_Planes *outPlanes )
```

**Description**

Maps the multi-channel ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 
| virAddr | Double pointer to the address of the virtual memory.| 
| outPlanes | Pointer to the plane information of all images.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_Reference()

```
int32_t OH_NativeBuffer_Reference (OH_NativeBuffer *buffer)
```

**Description**

Increases the reference count of an **OH_NativeBuffer** instance by 1.

This function must be used in pair with **OH_NativeBuffer_Unreference**. Otherwise, memory leak occurs.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_SetColorSpace()

```
int32_t OH_NativeBuffer_SetColorSpace (OH_NativeBuffer *buffer, OH_NativeBuffer_ColorSpace colorSpace )
```

**Description**

Sets the color space for an **OH_NativeBuffer** instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 
| colorSpace | Color space. For details about the available options, see [OH_NativeBuffer_ColorSpace](#oh_nativebuffer_colorspace).| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_SetMetadataValue()

```
int32_t OH_NativeBuffer_SetMetadataValue (OH_NativeBuffer *buffer, OH_NativeBuffer_MetadataKey metadataKey, int32_t size, uint8_t *metaData )
```

**Description**

Sets a metadata value for an **OH_NativeBuffer** instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 
| metadataKey | Key of the metadata. For details about the available options, see [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey).| 
| size | Size of the uint8_t vector. For details about the available options, see [OH_NativeBuffer_MetadataKey](#oh_nativebuffer_metadatakey).| 
| metaDate | Pointer to the uint8_t vector.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_Unmap()

```
int32_t OH_NativeBuffer_Unmap (OH_NativeBuffer *buffer)
```

**Description**

Unmaps the ION memory corresponding to an **OH_NativeBuffer** instance from the process address space.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeBuffer_Unreference()

```
int32_t OH_NativeBuffer_Unreference (OH_NativeBuffer *buffer)
```

**Description**

Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.

This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.

# native_buffer.h

## Overview

The **native_buffer.h** file declares the functions for obtaining and using **NativeBuffer**.

**File to include**: &lt;native_buffer/native_buffer.h&gt;

**Library**: libnative_buffer.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**: 9

**Related module**: [OH_NativeBuffer](_o_h___native_buffer.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| struct  [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | Describes the **OH_NativeBuffer** property configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the properties of an existing instance. |
| struct  [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md) | Describes the plane information of an image. |
| struct  [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md) | Describes the plane information of images in an **OH_NativeBuffer** instance. |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer)  [OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) | Provides the declaration of an **OH_NativeBuffer** struct. |
| typedef enum [OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage)  [OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage) | Defines an enum for the **OH_NativeBuffer** usages. |
| typedef enum [OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format)  [OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format) | Defines an enum for the **OH_NativeBuffer** formats. |
| typedef enum [OH_NativeBuffer_TransformType](_o_h___native_buffer.md#oh_nativebuffer_transformtype)  [OH_NativeBuffer_TransformType](_o_h___native_buffer.md#oh_nativebuffer_transformtype) | Defines an enum for the transform types of an **OH_NativeBuffer** instance. |
| typedef enum [OH_NativeBuffer_ColorGamut](_o_h___native_buffer.md#oh_nativebuffer_colorgamut)  [OH_NativeBuffer_ColorGamut](_o_h___native_buffer.md#oh_nativebuffer_colorgamut) | Defines an enum for the color gamuts of an **OH_NativeBuffer** instance. |
| typedef enum [OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode)  [OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode) | Defines an enum for the error codes. |
| typedef struct [OH_NativeBuffer_Config](_o_h___native_buffer___config.md)  [OH_NativeBuffer_Config](_o_h___native_buffer.md#oh_nativebuffer_config) | Defines the **OH_NativeBuffer** property configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the properties of an existing instance. |
| typedef struct [OH_NativeBuffer_Plane](_o_h___native_buffer___plane.md)  [OH_NativeBuffer_Plane](_o_h___native_buffer.md#oh_nativebuffer_plane) | Defines a struct for the plane information of an image. |
| typedef struct [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md)  [OH_NativeBuffer_Planes](_o_h___native_buffer.md#oh_nativebuffer_planes) | Defines a struct for the plane information of images in an **OH_NativeBuffer** instance. |


### Enums

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage-1) {<br>NATIVEBUFFER_USAGE_CPU_READ = (1ULL &lt;&lt; 0), NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL &lt;&lt; 1), NATIVEBUFFER_USAGE_MEM_DMA = (1ULL &lt;&lt; 3), NATIVEBUFFER_USAGE_HW_RENDER = (1ULL &lt;&lt; 8),<br>NATIVEBUFFER_USAGE_HW_TEXTURE = (1ULL &lt;&lt; 9), NATIVEBUFFER_USAGE_CPU_READ_OFTEN = (1ULL &lt;&lt; 16), NATIVEBUFFER_USAGE_ALIGNMENT_512 = (1ULL &lt;&lt; 18)<br>} | Enumerates the **OH_NativeBuffer** usages. |
| [OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format-1) {<br>NATIVEBUFFER_PIXEL_FMT_CLUT8 = 0, NATIVEBUFFER_PIXEL_FMT_CLUT1, NATIVEBUFFER_PIXEL_FMT_CLUT4, NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3,<br>NATIVEBUFFER_PIXEL_FMT_RGBA_5658, NATIVEBUFFER_PIXEL_FMT_RGBX_4444, NATIVEBUFFER_PIXEL_FMT_RGBA_4444, NATIVEBUFFER_PIXEL_FMT_RGB_444,<br>NATIVEBUFFER_PIXEL_FMT_RGBX_5551, NATIVEBUFFER_PIXEL_FMT_RGBA_5551, NATIVEBUFFER_PIXEL_FMT_RGB_555, NATIVEBUFFER_PIXEL_FMT_RGBX_8888,<br>NATIVEBUFFER_PIXEL_FMT_RGBA_8888, NATIVEBUFFER_PIXEL_FMT_RGB_888, NATIVEBUFFER_PIXEL_FMT_BGR_565, NATIVEBUFFER_PIXEL_FMT_BGRX_4444,<br>NATIVEBUFFER_PIXEL_FMT_BGRA_4444, NATIVEBUFFER_PIXEL_FMT_BGRX_5551, NATIVEBUFFER_PIXEL_FMT_BGRA_5551, NATIVEBUFFER_PIXEL_FMT_BGRX_8888,<br>NATIVEBUFFER_PIXEL_FMT_BGRA_8888, NATIVEBUFFER_PIXEL_FMT_YUV_422_I, NATIVEBUFFER_PIXEL_FMT_YCBCR_422_SP, NATIVEBUFFER_PIXEL_FMT_YCRCB_422_SP,<br>NATIVEBUFFER_PIXEL_FMT_YCBCR_420_SP, NATIVEBUFFER_PIXEL_FMT_YCRCB_420_SP, NATIVEBUFFER_PIXEL_FMT_YCBCR_422_P, NATIVEBUFFER_PIXEL_FMT_YCRCB_422_P,<br>NATIVEBUFFER_PIXEL_FMT_YCBCR_420_P, NATIVEBUFFER_PIXEL_FMT_YCRCB_420_P, NATIVEBUFFER_PIXEL_FMT_YUYV_422_PKG, NATIVEBUFFER_PIXEL_FMT_UYVY_422_PKG,<br>NATIVEBUFFER_PIXEL_FMT_YVYU_422_PKG, NATIVEBUFFER_PIXEL_FMT_VYUY_422_PKG, NATIVEBUFFER_PIXEL_FMT_RGBA_1010102, NATIVEBUFFER_PIXEL_FMT_YCBCR_P010,<br>NATIVEBUFFER_PIXEL_FMT_YCRCB_P010, NATIVEBUFFER_PIXEL_FMT_RAW10, NATIVEBUFFER_PIXEL_FMT_BLOB, NATIVEBUFFER_PIXEL_FMT_RGBA16_FLOAT,<br>NATIVEBUFFER_PIXEL_FMT_VENDER_MASK = 0X7FFF0000, NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF<br>} | Enumerates the **OH_NativeBuffer** formats. |
| [OH_NativeBuffer_TransformType](_o_h___native_buffer.md#oh_nativebuffer_transformtype-1) {<br>NATIVEBUFFER_ROTATE_NONE = 0, NATIVEBUFFER_ROTATE_90, NATIVEBUFFER_ROTATE_180, NATIVEBUFFER_ROTATE_270,<br>NATIVEBUFFER_FLIP_H, NATIVEBUFFER_FLIP_V, NATIVEBUFFER_FLIP_H_ROT90, NATIVEBUFFER_FLIP_V_ROT90,<br>NATIVEBUFFER_FLIP_H_ROT180, NATIVEBUFFER_FLIP_V_ROT180, NATIVEBUFFER_FLIP_H_ROT270, NATIVEBUFFER_FLIP_V_ROT270<br>} | Enumerates the transform types of an **OH_NativeBuffer** instance. |
| [OH_NativeBuffer_ColorGamut](_o_h___native_buffer.md#oh_nativebuffer_colorgamut-1) {<br>NATIVEBUFFER_COLOR_GAMUT_NATIVE = 0, NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT601 = 1, NATIVEBUFFER_COLOR_GAMUT_STANDARD_BT709 = 2, NATIVEBUFFER_COLOR_GAMUT_DCI_P3 = 3,<br>NATIVEBUFFER_COLOR_GAMUT_SRGB = 4, NATIVEBUFFER_COLOR_GAMUT_ADOBE_RGB = 5, NATIVEBUFFER_COLOR_GAMUT_DISPLAY_P3 = 6, NATIVEBUFFER_COLOR_GAMUT_BT2020 = 7,<br>NATIVEBUFFER_COLOR_GAMUT_BT2100_PQ = 8, NATIVEBUFFER_COLOR_GAMUT_BT2100_HLG = 9, NATIVEBUFFER_COLOR_GAMUT_DISPLAY_BT2020 = 10<br>} | Enumerates the color gamuts of an **OH_NativeBuffer** instance. |
| [OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000,<br>NATIVE_ERROR_NO_BUFFER = 40601000, NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000,<br>NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000, NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,<br>NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000, NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000, NATIVE_ERROR_UNKNOWN = 50002000,<br>NATIVE_ERROR_HDI_ERROR = 50007000, NATIVE_ERROR_BINDER_ERROR = 50401000, NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \* [OH_NativeBuffer_Alloc](_o_h___native_buffer.md#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.<br>This function must be used in pair with [OH_NativeBuffer_Unreference](_o_h___native_buffer.md#oh_nativebuffer_unreference). Otherwise, memory leak occurs.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_Reference](_o_h___native_buffer.md#oh_nativebuffer_reference) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.<br>This function must be used in pair with [OH_NativeBuffer_Unreference](_o_h___native_buffer.md#oh_nativebuffer_unreference). Otherwise, memory leak occurs.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_Unreference](_o_h___native_buffer.md#oh_nativebuffer_unreference) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.<br>This function is not thread-safe.|
| void [OH_NativeBuffer_GetConfig](_o_h___native_buffer.md#oh_nativebuffer_getconfig) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Obtains the properties of an **OH_NativeBuffer** instance.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_Map](_o_h___native_buffer.md#oh_nativebuffer_map) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, void \*\*virAddr) | Maps the ION memory allocated to an **OH_NativeBuffer** instance to the process address space.<br>This function must be used in pair with [OH_NativeBuffer_Unmap](_o_h___native_buffer.md#oh_nativebuffer_unmap).<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_Unmap](_o_h___native_buffer.md#oh_nativebuffer_unmap) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Unmaps the ION memory allocated to an **OH_NativeBuffer** instance from the process address space.<br>This function is not thread-safe.|
| uint32_t [OH_NativeBuffer_GetSeqNum](_o_h___native_buffer.md#oh_nativebuffer_getseqnum) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Obtains the sequence number of an **OH_NativeBuffer** instance.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_SetColorSpace](_o_h___native_buffer.md#oh_nativebuffer_setcolorspace) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) colorSpace) | Sets the color space for an **OH_NativeBuffer** instance.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_MapPlanes](_o_h___native_buffer.md#oh_nativebuffer_mapplanes) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, void \*\*virAddr, [OH_NativeBuffer_Planes](_o_h___native_buffer___planes.md) \*outPlanes) | Maps the multi-channel ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_FromNativeWindowBuffer](_o_h___native_buffer.md#oh_nativebuffer_fromnativewindowbuffer) (OHNativeWindowBuffer \*nativeWindowBuffer, [OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*\*buffer) | Converts an **OHNativeWindowBuffer** instance to an **OH_NativeBuffer** instance.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_GetColorSpace](_o_h___native_buffer.md#oh_nativebuffer_getcolorspace) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) \*colorSpace) | Obtains the color space of an **OH_NativeBuffer** instance.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_SetMetadataValue](_o_h___native_buffer.md#oh_nativebuffer_setmetadatavalue) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t size, uint8_t \*metaData) | Sets a metadata value for an **OH_NativeBuffer** instance.<br>This function is not thread-safe.|
| int32_t [OH_NativeBuffer_GetMetadataValue](_o_h___native_buffer.md#oh_nativebuffer_getmetadatavalue) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t \*size, uint8_t \*\*metaData) | Obtains the metadata value of an **OH_NativeBuffer** instance.<br>This function is not thread-safe.|

# NativeWindow


## Overview

The **NativeWindow** module provides the **NativeWindow** capability for connection to the EGL.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [external_window.h](external__window_8h.md) | Declares the functions for obtaining and using **NativeWindow**.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [Region](_region.md) | Describes the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.| 
| struct  [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | Describes the HDR metadata.<br>**Deprecated**: This struct is deprecated since API version 10. No substitute is provided.| 
| struct  [OHExtDataHandle](_o_h_ext_data_handle.md) | Describes the extended data handle.<br>**Deprecated**: This struct is deprecated since API version 10. No substitute is provided.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OHIPCParcel](#ohipcparcel) [OHIPCParcel](#ohipcparcel) | Provides access to **OHIPCParcel**, which is an IPC parcelable object.| 
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | Provides the capability of accessing the **OHNativeWindow**.| 
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](#ohnativewindowbuffer) | Provides the capability of accessing the **OHNativeWindowBuffer**.| 
| typedef struct [Region](_region.md)  [Region](#region) | Defines a struct for the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.| 
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | Defines an enum for the error codes. | 
| typedef enum [NativeWindowOperation](#nativewindowoperation)  [NativeWindowOperation](#nativewindowoperation) | Defines an enum for the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function. | 
| typedef enum [OHScalingModeV2](#ohscalingmodev2)  [OHScalingModeV2](#ohscalingmodev2) | Defines an enum for the rendering scaling modes. | 
| typedef enum [OHSurfaceSource](#ohsurfacesource)  [OHSurfaceSource](#ohsurfacesource) | Defines an enum for the sources of content displayed in the local window.| 

### Enums

| Name| Description| 
| -------- | -------- |
| [NativeWindowOperation](#nativewindowoperation-1) {<br>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,<br>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br>SET_UI_TIMESTAMP, GET_BUFFERQUEUE_SIZE<br>SET_HDR_WHITE_POINT_BRIGHTNESS, SET_SDR_WHITE_POINT_BRIGHTNESS, SET_SOURCE_TYPE,GET_SOURCE_TYPE,SET_APP_FRAMEWORK_TYPE,GET_APP_FRAMEWORK_TYPE<br>} | Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.|
| [OHScalingMode](#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | Enumerates the scaling modes.<br>**Deprecated**: This enum is deprecated since API version 10. No substitute is provided.| 
| [OHScalingModeV2](#ohscalingmodev2-1) {<br>OH_SCALING_MODE_FREEZE_V2 = 0, OH_SCALING_MODE_SCALE_TO_WINDOW_V2, OH_SCALING_MODE_SCALE_CROP_V2, OH_SCALING_MODE_NO_SCALE_CROP_V2,<br>OH_SCALING_MODE_SCALE_FIT_V2<br>} | Enumerates the rendering scaling modes. | 
| [OHHDRMetadataKey](#ohhdrmetadatakey) {<br>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br>} | Enumerates the HDR metadata keys.<br>**Deprecated**: This enum is deprecated since API version 10. No substitute is provided.| 
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000,NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br>} | Enumerates the error codes. | 
| [OHSurfaceSource](#ohsurfacesource-1) {<br>OH_SURFACE_SOURCE_DEFAULT = 0, OH_SURFACE_SOURCE_UI, OH_SURFACE_SOURCE_GAME, OH_SURFACE_SOURCE_CAMERA,OH_SURFACE_SOURCE_VIDEO<br>} | Enumerates the sources of content displayed in the local window.| 

### Functions

| Name| Description| 
| -------- | -------- |
| [OHNativeWindow](#ohnativewindow) \* [OH_NativeWindow_CreateNativeWindow](#oh_nativewindow_createnativewindow) (void \*pSurface) | Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called. If this function is unavailable, you can create an **OHNativeWindow** instance by calling **OH_NativeImage_AcquireNativeWindow** or through the **XComponent**.| 
| void [OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow) ([OHNativeWindow](#ohnativewindow) \*window) | Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.| 
| [OHNativeWindowBuffer](#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called. This function is deprecated since API version 12 and replaced by [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer).| 
| [OHNativeWindowBuffer](#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer) (OH_NativeBuffer \*nativeBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.| 
| void [OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer) ([OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.| 
| int32_t [OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.| 
| int32_t [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer, int fenceFd, [Region](_region.md) region) | Flushes the **OHNativeWindowBuffer** filled with the produced content to the buffer queue through an **OHNativeWindow** instance for content consumption.| 
| int32_t [OH_NativeWindow_GetLastFlushedBuffer](#oh_nativewindow_getlastflushedbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*\*buffer, int \*fenceFd, float matrix[16]) | Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_NativeWindowAbortBuffer](#oh_nativewindow_nativewindowabortbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.| 
| int32_t [OH_NativeWindow_NativeWindowHandleOpt](#oh_nativewindow_nativewindowhandleopt) ([OHNativeWindow](#ohnativewindow) \*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow** instance, including the width, height, and content format.| 
| BufferHandle \* [OH_NativeWindow_GetBufferHandleFromNative](#oh_nativewindow_getbufferhandlefromnative) ([OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.| 
| int32_t [OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference) (void \*obj) | Adds the reference count of a native object.| 
| int32_t [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference) (void \*obj) | Decreases the reference count of a native object and, when the reference count reaches 0, destroys this object.| 
| int32_t [OH_NativeWindow_GetNativeObjectMagic](#oh_nativewindow_getnativeobjectmagic) (void \*obj) | Obtains the magic ID of a native object.| 
| int32_t [OH_NativeWindow_NativeWindowSetScalingMode](#oh_nativewindow_nativewindowsetscalingmode) ([OHNativeWindow](#ohnativewindow) \*window, uint32_t sequence, [OHScalingMode](#ohscalingmode) scalingMode) | Sets a scaling mode for an **OHNativeWindow**.<br>**Deprecated**: This function is deprecated since API version 10. No substitute is provided.| 
| int32_t [OH_NativeWindow_NativeWindowSetMetaData](#oh_nativewindow_nativewindowsetmetadata) ([OHNativeWindow](#ohnativewindow) \*window, uint32_t sequence, int32_t size, const [OHHDRMetaData](_o_h_h_d_r_meta_data.md) \*metaData) | Sets metadata for an **OHNativeWindow**.<br>**Deprecated**: This function is deprecated since API version 10. No substitute is provided.| 
| int32_t [OH_NativeWindow_NativeWindowSetMetaDataSet](#oh_nativewindow_nativewindowsetmetadataset) ([OHNativeWindow](#ohnativewindow) \*window, uint32_t sequence, [OHHDRMetadataKey](#ohhdrmetadatakey) key, int32_t size, const uint8_t \*metaData) | Sets a metadata set for an **OHNativeWindow**.<br>**Deprecated**: This function is deprecated since API version 10. No substitute is provided.| 
| int32_t [OH_NativeWindow_NativeWindowSetTunnelHandle](#oh_nativewindow_nativewindowsettunnelhandle) ([OHNativeWindow](#ohnativewindow) \*window, const [OHExtDataHandle](_o_h_ext_data_handle.md) \*handle) | Sets a tunnel handle to an **OHNativeWindow**.<br>**Deprecated**: This function is deprecated since API version 10. No substitute is provided.| 
| int32_t [OH_NativeWindow_NativeWindowAttachBuffer](#oh_nativewindow_nativewindowattachbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | Attaches an **OHNativeWindowBuffer** to an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_NativeWindowDetachBuffer](#oh_nativewindow_nativewindowdetachbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | Detaches an **OHNativeWindowBuffer** from an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_GetSurfaceId](#oh_nativewindow_getsurfaceid) ([OHNativeWindow](#ohnativewindow) \*window, uint64_t \*surfaceId) | Obtains a surface ID through an **OHNativeWindow**.| 
| int32_t [OH_NativeWindow_CreateNativeWindowFromSurfaceId](#oh_nativewindow_createnativewindowfromsurfaceid) (uint64_t surfaceId, [OHNativeWindow](#ohnativewindow) \*\*window) | Creates an **OHNativeWindow** instance based on a surface ID.| 
| int32_t [OH_NativeWindow_NativeWindowSetScalingModeV2](#oh_nativewindow_nativewindowsetscalingmodev2)  ([OHNativeWindow](#ohnativewindow) \*window, [OHScalingModeV2](#ohscalingmodev2) scalingMode) | Sets a rendering scaling mode for an **OHNativeWindow** instance. |
| int32_t [OH_NativeWindow_GetLastFlushedBufferV2](#oh_nativewindow_getlastflushedbufferv2) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*\*buffer, int \*fenceFd, float matrix[16]) | Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance. The difference between this function and **OH_NativeWindow_GetLastFlushedBuffer** lies in the matrix. | 
| void [OH_NativeWindow_SetBufferHold](#oh_nativewindow_setbufferhold) ([OHNativeWindow](#ohnativewindow) \*window) | Buffers a frame in advance and holds it for the interval of a frame to offset the possible loss of subsequent oversized frames. | 
| int32_t [OH_NativeWindow_WriteToParcel](#oh_nativewindow_writetoparcel) ([OHNativeWindow](#ohnativewindow) \*window, [OHIPCParcel](#ohipcparcel) \*parcel) | Writes an **OHNativeWindow** instance to an **OHIPCParcel** instance.| 
| int32_t [OH_NativeWindow_ReadFromParcel](#oh_nativewindow_readfromparcel) ([OHIPCParcel](#ohipcparcel) \*parcel, [OHNativeWindow](#ohnativewindow) \*\*window) | Reads an **OHNativeWindow** instance from an **OHIPCParcel** instance.| 
| int32_t [OH_NativeWindow_SetColorSpace](#oh_nativewindow_setcolorspace) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) colorSpace) | Sets the color space for an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_GetColorSpace](#oh_nativewindow_getcolorspace) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) \*colorSpace) | Obtains the color space of an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_SetMetadataValue](#oh_nativewindow_setmetadatavalue) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t size, uint8_t \*metaData) | Sets a metadata value for an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_GetMetadataValue](#oh_nativewindow_getmetadatavalue) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t \*size, uint8_t \*\*metaData) | Obtains the metadata value of an **OHNativeWindow** instance.| 

## Type Description

### OHSurfaceSource

```
typedef enum OHSurfaceSource OHSurfaceSource
```

**Description**

Defines an enum for the sources of content displayed in the local window.

**Since**: 12

### OHIPCParcel

```
typedef struct OHIPCParcel OHIPCParcel
```

**Description**

Provides access to **OHIPCParcel**, which is an IPC parcelable object.

**Since**: 12

### NativeWindowOperation

```
typedef enum NativeWindowOperation NativeWindowOperation
```

**Description**

Defines an enum for the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.

**Since**: 8

### OHNativeErrorCode

```
typedef enum OHNativeErrorCode OHNativeErrorCode
```

**Description**

Defines an enum for the error codes.

**Since**: 12


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**Description**

Provides the capability of accessing the **OHNativeWindow**.

**Since**: 8


### OHNativeWindowBuffer

```
typedef struct NativeWindowBuffer OHNativeWindowBuffer
```

**Description**

Provides the capability of accessing the **OHNativeWindowBuffer**.

**Since**: 8

### OHScalingModeV2

```
typedef enum OHScalingModeV2 OHScalingModeV2
```
**Description**

Defines an enum for the rendering scaling modes.

**Since**: 12



### Region

```
typedef struct Region Region
```

**Description**

Defines the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.

**Since**: 8


## Enum Description

### OHSurfaceSource

```
enum OHSurfaceSource
```

**Description**

Enumerates the sources of content displayed in the local window.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_SURFACE_SOURCE_DEFAULT | Default source.| 
| OH_SURFACE_SOURCE_UI | The window content comes from UIs.|
| OH_SURFACE_SOURCE_GAME | The window content comes from games.|
| OH_SURFACE_SOURCE_CAMERA | The window content comes from cameras.|
| OH_SURFACE_SOURCE_VIDEO | The window content comes from videos.|

### OHNativeErrorCode

```
enum OHNativeErrorCode
```
**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| NATIVE_ERROR_OK  | The operation is successful.  | 
| NATIVE_ERROR_INVALID_ARGUMENTS  | An input parameter is invalid.  | 
| NATIVE_ERROR_NO_PERMISSION  | You do not have the permission to perform the operation.  | 
| NATIVE_ERROR_NO_BUFFER  | No buffer is available.  | 
| NATIVE_ERROR_NO_CONSUMER  | The consumer does not exist.  | 
| NATIVE_ERROR_NOT_INIT  | Not initialized.  | 
| NATIVE_ERROR_CONSUMER_CONNECTED  | The consumer is connected.  | 
| NATIVE_ERROR_BUFFER_STATE_INVALID  | The buffer status does not meet the expectation.  | 
| NATIVE_ERROR_BUFFER_IN_CACHE  | The buffer is already in the buffer queue.  | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL  | The queue is full.  | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE  | The buffer is not in the buffer queue.  | 
| NATIVE_ERROR_CONSUMER_DISCONNECTED | The consumer is disconnected.|
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | No listener is registered on the consumer side.|
| NATIVE_ERROR_UNSUPPORTED  | The device or platform does not support the operation.  | 
| NATIVE_ERROR_UNKNOWN  | Unknown error. Check the log.  | 
| NATIVE_ERROR_HDI_ERROR  | Failed to call the HDI.  | 
| NATIVE_ERROR_BINDER_ERROR  | Cross-process communication failed.  | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | The EGL environment is abnormal.  | 
| NATIVE_ERROR_EGL_API_FAILED  | Failed to call the EGL APIs.  | 

### NativeWindowOperation

```
enum NativeWindowOperation
```

**Description**

Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| SET_BUFFER_GEOMETRY | Setting the geometry for the local window buffer.<br>Variable arguments in the function: [Input] int32_t width and [Input] int32_t height.| 
| GET_BUFFER_GEOMETRY | Obtaining the geometry of the local window buffer.<br>Variable arguments in the function: [Output] int32_t *height and [Output] int32_t *width.| 
| GET_FORMAT | Obtaining the format of the local window buffer.<br>Variable argument in the function: [Output] int32_t *format.| 
| SET_FORMAT | Setting the format for the local window buffer.<br>Variable argument in the function: [Input] int32_t format.| 
| GET_USAGE | Obtaining the usage mode of the local window buffer.<br>Variable argument in the function: [Output] uint64_t \*usage.| 
| SET_USAGE | Setting the usage mode for the local window buffer.<br>Variable argument in the function: [Input] uint64_t usage.| 
| SET_STRIDE | Setting the stride for the local window buffer.<br>Variable argument in the function: [Input] int32_t stride.| 
| GET_STRIDE | Obtaining the stride of the local window buffer.<br>Variable argument in the function: [Output] int32_t *stride.| 
| SET_SWAP_INTERVAL | Setting the swap interval for the local window buffer.<br>Variable argument in the function: [Input] int32_t interval.| 
| GET_SWAP_INTERVAL | Obtaining the swap interval of the local window buffer.<br>Variable argument in the function: [Output] int32_t *interval.| 
| SET_TIMEOUT | Setting the timeout duration for requesting the local window buffer.<br>Variable argument in the function: [Input] int32_t timeout.| 
| GET_TIMEOUT | Obtaining the timeout duration for requesting the local window buffer.<br>Variable argument in the function: [Output] int32_t *timeout.| 
| SET_COLOR_GAMUT | Setting the color gamut for the local window buffer.<br>Variable argument in the function: [Input] int32_t colorGamut.| 
| GET_COLOR_GAMUT | Obtaining the color gamut of the local window buffer.<br>Variable argument in the function: [Output] int32_t *colorGamut.| 
| SET_TRANSFORM | Setting the transform for the local window buffer.<br>Variable argument in the function: [Input] int32_t transform.| 
| GET_TRANSFORM | Obtaining the transform of the local window buffer.<br>Variable argument in the function: [Output] int32_t *transform.| 
| SET_UI_TIMESTAMP | Setting the UI timestamp for the local window buffer.<br>Variable argument in the function: [Input] uint64_t uiTimestamp.| 
| GET_BUFFERQUEUE_SIZE<sup>12+</sup> | Obtaining the memory queue size.<br>Variable argument in the function: [Output] int32_t \*size.<br>This value is supported since API version 12.| 
| SET_HDR_WHITE_POINT_BRIGHTNESS<sup>12+</sup> | Setting the brightness of HDR white points.<br>Variable arguments in the function: [Input] float brightness. The value range is [0.0f, 1.0f].| 
| SET_SDR_WHITE_POINT_BRIGHTNESS<sup>12+</sup> | Setting the brightness of SDR white points.<br>Variable arguments in the function: [Input] float brightness. The value range is [0.0f, 1.0f].| 
| SET_SOURCE_TYPE<sup>12+</sup> | Setting the source of content displayed in the local window.<br>Variable argument in the function: [Input] int32_t sourceType. For details about the available options, see [OHSurfaceSource](#ohsurfacesource-1).|
| GET_SOURCE_TYPE<sup>12+</sup> | Obtaining the source of content displayed in the local window.<br>Variable argument in the function: [Output] int32_t \*sourceType. For details about the available options, see [OHSurfaceSource](#ohsurfacesource-1).|
| SET_APP_FRAMEWORK_TYPE<sup>12+</sup> | Setting the application framework name of the local window.<br>Variable argument in the function: [Input] char\* frameworkType. A maximum of 64 bytes are supported.|
| GET_APP_FRAMEWORK_TYPE<sup>12+</sup> | Obtaining the application framework name of the local window.<br>Variable argument in the function: [Output] char\* frameworkType.|

### OHHDRMetadataKey

```
enum OHHDRMetadataKey
```

**Description**

Enumerates the HDR metadata keys.

**Since**: 9

**Deprecated**: This enum is deprecated since API version 10. No substitute is provided.

| Value| Description| 
| -------- | -------- |
| OH_METAKEY_RED_PRIMARY_X | X coordinate of the red primary color.| 
| OH_METAKEY_RED_PRIMARY_Y | Y coordinate of the red primary color.| 
| OH_METAKEY_GREEN_PRIMARY_X | X coordinate of the green primary color.| 
| OH_METAKEY_GREEN_PRIMARY_Y | Y coordinate of the green primary color.| 
| OH_METAKEY_BLUE_PRIMARY_X | X coordinate of the blue primary color.| 
| OH_METAKEY_BLUE_PRIMARY_Y | Y coordinate of the blue primary color.| 
| OH_METAKEY_WHITE_PRIMARY_X | X coordinate of the white point.| 
| OH_METAKEY_WHITE_PRIMARY_Y | Y coordinate of the white point.| 
| OH_METAKEY_MAX_LUMINANCE | Maximum luminance.| 
| OH_METAKEY_MIN_LUMINANCE | Minimum luminance.| 
| OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL | Maximum content light level (MaxCLL).| 
| OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL | Maximum frame average light level (MaxFALLL).| 
| OH_METAKEY_HDR10_PLUS | HDR10 Plus.| 
| OH_METAKEY_HDR_VIVID | Vivid.| 


### OHScalingMode

```
enum OHScalingMode
```

**Description**

Enumerates the scaling modes.

**Since**: 9

**Deprecated**: This enum is deprecated since API version 10. No substitute is provided.

| Value| Description| 
| -------- | -------- |
| OH_SCALING_MODE_FREEZE | The window content cannot be updated before the buffer of the window size is received.| 
| OH_SCALING_MODE_SCALE_TO_WINDOW | The buffer is scaled in two dimensions to match the window size.| 
| OH_SCALING_MODE_SCALE_CROP | The buffer is scaled uniformly so that its smaller size can match the window size.| 
| OH_SCALING_MODE_NO_SCALE_CROP | The window is cropped to the size of the buffer's cropping rectangle. Pixels outside the cropping rectangle are considered completely transparent.| 


### OHScalingModeV2

```
enum OHScalingModeV2
```
**Description**

Enumerates the rendering scaling modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_SCALING_MODE_FREEZE_V2  | Freezes the window. The window content is not updated until a buffer with the same size as the window is received.| 
| OH_SCALING_MODE_SCALE_TO_WINDOW_V2  | Scales the buffer to match the window size.| 
| OH_SCALING_MODE_SCALE_CROP_V2  | Scales the buffer at the original aspect ratio to enable the smaller side of the buffer to match the window, while making the excess part transparent.| 
| OH_SCALING_MODE_NO_SCALE_CROP_V2  | Crops the buffer by window size. Pixels outside the cropping rectangle are considered completely transparent.| 
| OH_SCALING_MODE_SCALE_FIT_V2  | Scales the buffer at the original aspect ratio to fully display the buffer content, while filling the unfilled area of the window with the background color. This mode is not available for the<!--Del--> development board and<!--DelEnd--> emulator.| 


## Function Description

### OH_NativeWindow_SetColorSpace()

```
int32_t OH_NativeWindow_SetColorSpace (OHNativeWindow *window, OH_NativeBuffer_ColorSpace colorSpace )
```

**Description**

Sets the color space for an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an [OHNativeWindow](#ohnativewindow) instance.| 
| colorSpace | Color space. For details about the available options, see [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace).| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode) otherwise.


### OH_NativeWindow_SetMetadataValue()

```
int32_t OH_NativeWindow_SetMetadataValue (OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey, int32_t size, uint8_t * metaData )
```

**Description**

Sets a metadata value for an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an [OHNativeWindow](#ohnativewindow) instance.| 
| metadataKey | Key of the metadata. For details about the available options, see [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey).| 
| size | Size of the uint8_t vector. For details about the available options, see [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey).| 
| metaData| Pointer to the uint8_t vector.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode) otherwise.

### OH_NativeWindow_GetColorSpace()

```
int32_t OH_NativeWindow_GetColorSpace (OHNativeWindow *window, OH_NativeBuffer_ColorSpace *colorSpace )
```

**Description**

Obtains the color space of an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an [OHNativeWindow](#ohnativewindow) instance.| 
| colorSpace | Pointer to the color space. For details about the available options, see [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace).| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode) otherwise.


### OH_NativeWindow_GetMetadataValue()

```
int32_t OH_NativeWindow_GetMetadataValue (OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey, int32_t *size, uint8_t **metaData )
```

**Description**

Obtains the metadata value of an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an [OHNativeWindow](#ohnativewindow) instance.| 
| metadataKey | Key of the metadata. For details about the available options, see [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey).| 
| size | Pointer to the size of the uint8_t vector. For details about the available options, see [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey).| 
| metaData| Double pointer to the uint8_t vector.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode) otherwise.


### OH_NativeWindow_WriteToParcel()

```
int32_t OH_NativeWindow_WriteToParcel (OHNativeWindow *window, OHIPCParcel *parcel )
```

**Description**

Writes an **OHNativeWindow** instance to an **OHIPCParcel** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an [OHNativeWindow](#ohnativewindow) instance.| 
| parcel | Pointer to an [OHIPCParcel](#ohipcparcel) instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_ReadFromParcel()

```
int32_t OH_NativeWindow_ReadFromParcel (OHIPCParcel *parcel, OHNativeWindow **window )
```

**Description**

Reads an **OHNativeWindow** instance from an **OHIPCParcel** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to an [OHIPCParcel](#ohipcparcel) instance.| 
| window | Double pointer to an [OHNativeWindow](#ohnativewindow) instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.



### OH_NativeWindow_GetLastFlushedBufferV2()

```
int32_t OH_NativeWindow_GetLastFlushedBufferV2 (OHNativeWindow *window, OHNativeWindowBuffer **buffer, int *fenceFd, float matrix[16] )
```

**Description**

Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance. The difference between this function and **OH_NativeWindow_GetLastFlushedBuffer** lies in the matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance. | 
| buffer | Double pointer to an **OHNativeWindowBuffer** instance. | 
| fenceFd | Pointer to a file descriptor. | 
| matrix | Retrieved 4*4 transformation matrix. | 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.



### OH_NativeWindow_SetBufferHold()

```
void OH_NativeWindow_SetBufferHold (OHNativeWindow *window)
```
**Description**
Buffers a frame in advance and holds it for the interval of a frame to offset the possible loss of subsequent oversized frames.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an [OHNativeWindow](_o_h___native_image.md#ohnativewindow) instance. | 



### OH_NativeWindow_CreateNativeWindow()

```
OHNativeWindow* OH_NativeWindow_CreateNativeWindow (void* pSurface)
```

**Description**

Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called. If this function is unavailable, you can create an **OHNativeWindow** instance by calling **OH_NativeImage_AcquireNativeWindow** or through the **XComponent**.

**Deprecated from**: 12

**Substitute**: No substitute is provided.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| pSurface | Pointer to a **ProduceSurface**. The type is **sptr&lt;OHOS::Surface&gt;**.| 

**Returns**

Returns the pointer to the **OHNativeWindow** instance created.


### OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer (OH_NativeBuffer* nativeBuffer)
```

**Description**

Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| nativeBuffer | Pointer to an **OH_NativeBuffer** instance.| 

**Returns**

Returns the pointer to the **OHNativeWindowBuffer** instance created.


### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void* pSurfaceBuffer)
```

**Description**

Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.

**Deprecated from**: 12

**Substitute**: [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer)

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| pSurfaceBuffer | Pointer to a **ProduceSurfaceBuffer**. The type is **sptr&lt;OHOS::SurfaceBuffer&gt;**.| 

**Returns**

Returns the pointer to the **OHNativeWindowBuffer** instance created.


### OH_NativeWindow_CreateNativeWindowFromSurfaceId()

```
int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId (uint64_t surfaceId, OHNativeWindow **window )
```

**Description**

Creates an **OHNativeWindow** instance based on a surface ID.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| surfaceId | Surface ID.| 
| window | Double pointer to an **OHNativeWindow** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_DestroyNativeWindow()

```
void OH_NativeWindow_DestroyNativeWindow (OHNativeWindow* window)
```

**Description**

Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 


### OH_NativeWindow_DestroyNativeWindowBuffer()

```
void OH_NativeWindow_DestroyNativeWindowBuffer (OHNativeWindowBuffer* buffer)
```

**Description**

Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OHNativeWindowBuffer** instance.| 


### OH_NativeWindow_GetBufferHandleFromNative()

```
BufferHandle* OH_NativeWindow_GetBufferHandleFromNative (OHNativeWindowBuffer* buffer)
```

**Description**

Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OHNativeWindowBuffer** instance.| 

**Returns**

Returns the pointer to the **BufferHandle** instance obtained.


### OH_NativeWindow_GetLastFlushedBuffer()

```
int32_t OH_NativeWindow_GetLastFlushedBuffer (OHNativeWindow *window, OHNativeWindowBuffer **buffer, int *fenceFd, float matrix[16] )
```

**Description**

Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance.

**Deprecated from**: 12

**Substitute**: [OH_NativeWindow_GetLastFlushedBufferV2](#oh_nativewindow_getlastflushedbufferv2)

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| buffer | Double pointer to an **OHNativeWindowBuffer** instance.| 
| fenceFd | Pointer to a file descriptor.| 
| matrix | Retrieved 4*4 transformation matrix.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_GetNativeObjectMagic()

```
int32_t OH_NativeWindow_GetNativeObjectMagic (void *obj)
```

**Description**

Obtains the magic ID of a native object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.| 

**Returns**

Returns the magic ID, which is unique for each native object.


### OH_NativeWindow_GetSurfaceId()

```
int32_t OH_NativeWindow_GetSurfaceId (OHNativeWindow *window, uint64_t *surfaceId )
```

**Description**

Obtains a surface ID through an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| surfaceId | Pointer to the surface ID.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeObjectReference()

```
int32_t OH_NativeWindow_NativeObjectReference (void *obj)
```

**Description**

Adds the reference count of a native object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeObjectUnreference()

```
int32_t OH_NativeWindow_NativeObjectUnreference (void *obj)
```

**Description**

Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowAbortBuffer()

```
int32_t OH_NativeWindow_NativeWindowAbortBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer )
```

**Description**

Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| buffer | Pointer to an **OHNativeWindowBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.

### OH_NativeWindow_NativeWindowAttachBuffer()

```
int32_t OH_NativeWindow_NativeWindowAttachBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer )
```

**Description**

Attaches an **OHNativeWindowBuffer** to an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| buffer | Pointer to an **OHNativeWindowBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowDetachBuffer()

```
int32_t OH_NativeWindow_NativeWindowDetachBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer )
```

**Description**

Detaches an **OHNativeWindowBuffer** from an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| buffer | Pointer to an **OHNativeWindowBuffer** instance.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowFlushBuffer()

```
int32_t OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer, int fenceFd, Region region )
```

**Description**

Flushes the **OHNativeWindowBuffer** filled with the produced content to the buffer queue through an **OHNativeWindow** instance for content consumption.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| buffer | Pointer to an **OHNativeWindowBuffer** instance.| 
| fenceFd | File descriptor handle, which is used for timing synchronization.| 
| region | Dirty region where content is updated.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowHandleOpt()

```
int32_t OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow *window, int code,  ... )
```

**Description**

Sets or obtains the attributes of an **OHNativeWindow** instance, including the width, height, and content format.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| code | Operation code. For details, see [NativeWindowOperation](#nativewindowoperation).| 
| ... | Variable argument, which must correspond to the operation code.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowRequestBuffer()

```
int32_t OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow *window, OHNativeWindowBuffer **buffer, int *fenceFd )
```

**Description**

Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| buffer | Double pointer to an **OHNativeWindowBuffer** instance.| 
| fenceFd | Pointer to a file descriptor handle.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowSetMetaData()

```
int32_t OH_NativeWindow_NativeWindowSetMetaData (OHNativeWindow *window, uint32_t sequence, int32_t size, const OHHDRMetaData *metaData )
```

**Description**

Sets metadata for an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated**: This function is deprecated since API version 10. No substitute is provided.

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| sequence | Sequence of the producer buffer.| 
| size | Size of the **OHHDRMetaData** array.| 
| metaData| Pointer to the **OHHDRMetaData** array.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowSetMetaDataSet()

```
int32_t OH_NativeWindow_NativeWindowSetMetaDataSet (OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t *metaData )
```

**Description**

Sets a metadata set for an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated**: This function is deprecated since API version 10. No substitute is provided.

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| sequence | Sequence of the producer buffer.| 
| key | Metadata key. For details, see [OHHDRMetadataKey](#ohhdrmetadatakey).| 
| size | Size of the uint8_t vector.| 
| metaData| Pointer to the uint8_t vector.| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowSetScalingMode()

```
int32_t OH_NativeWindow_NativeWindowSetScalingMode (OHNativeWindow *window, uint32_t sequence, OHScalingMode scalingMode )
```

**Description**

Sets a scaling mode for an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated**: This function is deprecated since API version 10. No substitute is provided.

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| sequence | Sequence of the producer buffer.| 
| scalingMode | Scaling mode to set. For details, see [OHScalingMode](#ohscalingmode).| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.


### OH_NativeWindow_NativeWindowSetScalingModeV2()

```
int32_t OH_NativeWindow_NativeWindowSetScalingModeV2 (OHNativeWindow* window, OHScalingModeV2 scalingMode )
```
**Description**
Sets a rendering scaling mode for an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance. | 
| scalingMode | Scaling mode. For details about the available options, see **OHScalingModeV2**. | 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.

### OH_NativeWindow_NativeWindowSetTunnelHandle()

```
int32_t OH_NativeWindow_NativeWindowSetTunnelHandle (OHNativeWindow *window, const OHExtDataHandle *handle )
```

**Description**

Sets a tunnel handle to an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated**: This function is deprecated since API version 10. No substitute is provided.

**Parameters**

| Name| Description| 
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.| 
| handle | Pointer to an [OHExtDataHandle](_o_h_ext_data_handle.md).| 

**Returns**

Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](#ohnativeerrorcode) otherwise.

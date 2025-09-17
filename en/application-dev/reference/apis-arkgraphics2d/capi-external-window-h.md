# external_window.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Flix-fangyang; @li_hui180; @ding-panyun-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## Overview

This file declares the functions for obtaining and using **NativeWindow**.

<!--RP1-->
**Sample**: [NDKNativeWindow](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeWindow)<!--RP1End-->

**File to include**: <native_window/external_window.h>

**Library**: libnative_window.so

**Since**: 8

**Related module**: [NativeWindow](capi-nativewindow.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Region](capi-nativewindow-region.md) | Region | Describes the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.|
| [Rect](capi-nativewindow-rect.md) | - | If **rects** is a null pointer, the buffer size is the same as the size of the dirty region by default.|
| [OHHDRMetaData](capi-nativewindow-ohhdrmetadata.md) | OHHDRMetaData | Describes the HDR metadata.|
| [OHExtDataHandle](capi-nativewindow-ohextdatahandle.md) | OHExtDataHandle | Describes the extended data handle.|
| [OHIPCParcel](capi-nativewindow-ohipcparcel.md) | OHIPCParcel | Provides access to **OHIPCParcel**, which is an IPC parcelable object.|
| [NativeWindow](capi-nativewindow-nativewindow.md) | OHNativeWindow | Provides the capability of accessing the **OHNativeWindow**.|
| [NativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) | OHNativeWindowBuffer | Provides the capability of accessing the **OHNativeWindowBuffer**.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NativeWindowOperation](#nativewindowoperation) | NativeWindowOperation | Defines an enum for the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.|
| [OHScalingMode](#ohscalingmode) | OHScalingMode | Enumerates the scaling modes.|
| [OHScalingModeV2](#ohscalingmodev2) | OHScalingModeV2 | Defines an enum for the rendering scaling modes.|
| [OHHDRMetadataKey](#ohhdrmetadatakey) | OHHDRMetadataKey | Enumerates the HDR metadata keys.|
| [OHSurfaceSource](#ohsurfacesource) | OHSurfaceSource | Defines an enum for the sources of content displayed in the local window.|

### Functions

| Name| Description|
| -- | -- |
| [OHNativeWindow* OH_NativeWindow_CreateNativeWindow(void* pSurface)](#oh_nativewindow_createnativewindow) | Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called.<br>Note: If this API is unavailable, you can use **OH_NativeImage_AcquireNativeWindow** or XComponent as a substitute.|
| [void OH_NativeWindow_DestroyNativeWindow(OHNativeWindow* window)](#oh_nativewindow_destroynativewindow) | Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.<br>This function is not thread-safe.|
| [OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer(void* pSurfaceBuffer)](#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.<br>Note: If this function is unavailable, you can use **OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer** as a substitute.|
| [OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(OH_NativeBuffer* nativeBuffer)](#oh_nativewindow_createnativewindowbufferfromnativebuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.<br>This function must be used in pair with [OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer). Otherwise, memory leak occurs.<br>This function is not thread-safe.|
| [void OH_NativeWindow_DestroyNativeWindowBuffer(OHNativeWindowBuffer* buffer)](#oh_nativewindow_destroynativewindowbuffer) | Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_NativeWindowRequestBuffer(OHNativeWindow *window,OHNativeWindowBuffer **buffer, int *fenceFd)](#oh_nativewindow_nativewindowrequestbuffer) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.<br>Before calling this function, you must call [SET_BUFFER_GEOMETRY](#nativewindowoperation) to set the width and height of **OHNativeWindow**.<br>This function must be used in pair with [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer). Otherwise, memory leak occurs.<br>When **fenceFd** is used up, you must close it.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_NativeWindowFlushBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer,int fenceFd, Region region)](#oh_nativewindow_nativewindowflushbuffer) | Flushes the **OHNativeWindowBuffer** filled with the produced content to the buffer queue through an **OHNativeWindow** instance for content consumption.<br>The system will close **fenceFd**. You do not need to close it.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_GetLastFlushedBuffer(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])](#oh_nativewindow_getlastflushedbuffer) | Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance.|
| [int32_t OH_NativeWindow_NativeWindowAbortBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)](#oh_nativewindow_nativewindowabortbuffer) | Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_NativeWindowHandleOpt(OHNativeWindow *window, int code, ...)](#oh_nativewindow_nativewindowhandleopt) | Sets or obtains the attributes of an **OHNativeWindow** instance, including the width, height, and content format.<br>This function is not thread-safe.|
| [BufferHandle *OH_NativeWindow_GetBufferHandleFromNative(OHNativeWindowBuffer *buffer)](#oh_nativewindow_getbufferhandlefromnative) | Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_NativeObjectReference(void *obj)](#oh_nativewindow_nativeobjectreference) | Adds the reference count of a native object.<br>This function must be used in pair with [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference). Otherwise, memory leak occurs.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)](#oh_nativewindow_nativeobjectunreference) | Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_GetNativeObjectMagic(void *obj)](#oh_nativewindow_getnativeobjectmagic) | Obtains the magic ID of a native object.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_NativeWindowSetScalingMode(OHNativeWindow *window, uint32_t sequence,OHScalingMode scalingMode)](#oh_nativewindow_nativewindowsetscalingmode) | Sets a scaling mode for an **OHNativeWindow**.|
| [int32_t OH_NativeWindow_NativeWindowSetMetaData(OHNativeWindow *window, uint32_t sequence, int32_t size,const OHHDRMetaData *metaData)](#oh_nativewindow_nativewindowsetmetadata) | Sets metadata for an **OHNativeWindow**.|
| [int32_t OH_NativeWindow_NativeWindowSetMetaDataSet(OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key,int32_t size, const uint8_t *metaData)](#oh_nativewindow_nativewindowsetmetadataset) | Sets a metadata set for an **OHNativeWindow**.|
| [int32_t OH_NativeWindow_NativeWindowSetTunnelHandle(OHNativeWindow *window, const OHExtDataHandle *handle)](#oh_nativewindow_nativewindowsettunnelhandle) | Sets a tunnel handle to an **OHNativeWindow**.|
| [int32_t OH_NativeWindow_NativeWindowAttachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)](#oh_nativewindow_nativewindowattachbuffer) | Attaches an **OHNativeWindowBuffer** to an **OHNativeWindow** instance.<br>This function must be used in pair with [OH_NativeWindow_NativeWindowDetachBuffer](#oh_nativewindow_nativewindowdetachbuffer). Otherwise, memory management disorder may occur.<br>This function is not thread-safe.<br>|
| [int32_t OH_NativeWindow_NativeWindowDetachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)](#oh_nativewindow_nativewindowdetachbuffer) | Detaches an **OHNativeWindowBuffer** from an **OHNativeWindow** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_GetSurfaceId(OHNativeWindow *window, uint64_t *surfaceId)](#oh_nativewindow_getsurfaceid) | Obtains a surface ID through an **OHNativeWindow**.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId(uint64_t surfaceId, OHNativeWindow **window)](#oh_nativewindow_createnativewindowfromsurfaceid) | Creates an **OHNativeWindow** instance based on a surface ID.<br>This function must be used in pair with [OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow). Otherwise, memory leak occurs.<br>If **OHNativeWindow** instances are released concurrently, call [OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference) and [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference) to increase and decrease the reference count of **OHNativeWindow**.<br>The surface obtained by using the surface ID must be created in the current process, but not in a different process.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_NativeWindowSetScalingModeV2(OHNativeWindow* window, OHScalingModeV2 scalingMode)](#oh_nativewindow_nativewindowsetscalingmodev2) | Sets a rendering scaling mode for an **OHNativeWindow** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_GetLastFlushedBufferV2(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])](#oh_nativewindow_getlastflushedbufferv2) | Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance. The difference between this function and **OH_NativeWindow_GetLastFlushedBuffer** lies in the matrix.<br>This function must be used in pair with [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference). Otherwise, memory leak occurs.<br>This function is not thread-safe.|
| [void OH_NativeWindow_SetBufferHold(OHNativeWindow *window)](#oh_nativewindow_setbufferhold) | Buffers a frame in advance and holds it for the interval of a frame to offset the possible loss of subsequent oversized frames.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_WriteToParcel(OHNativeWindow *window, OHIPCParcel *parcel)](#oh_nativewindow_writetoparcel) | Writes an **OHNativeWindow** instance to an **OHIPCParcel** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_ReadFromParcel(OHIPCParcel *parcel, OHNativeWindow **window)](#oh_nativewindow_readfromparcel) | Reads an **OHNativeWindow** instance from an **OHIPCParcel** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_SetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace colorSpace)](#oh_nativewindow_setcolorspace) | Sets the color space for an **OHNativeWindow** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_GetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace *colorSpace)](#oh_nativewindow_getcolorspace) | Obtains the color space of an **OHNativeWindow** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_SetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t size, uint8_t *metadata)](#oh_nativewindow_setmetadatavalue) | Sets a metadata value for an **OHNativeWindow** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_GetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t *size, uint8_t **metadata)](#oh_nativewindow_getmetadatavalue) | Obtains the metadata value of an **OHNativeWindow** instance.<br>This function is not thread-safe.|
| [int32_t OH_NativeWindow_CleanCache(OHNativeWindow *window)](#oh_nativewindow_cleancache) | Clears the **OHNativeWindowBuffer** cache in **OHNativeWindow**.<br>Ensure that **OHNativeWindowBuffer** has been successfully allocated by calling [OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer).<br>This function is not thread-safe.|

## Enum Description

### NativeWindowOperation

```
enum NativeWindowOperation
```

**Description**

Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.

**Since**: 8

| Enum| Description|
| -- | -- |
| SET_BUFFER_GEOMETRY | Sets the geometry for the local window buffer.<br>Variable arguments in the function: [Input] int32_t width and [Input] int32_t height.|
| GET_BUFFER_GEOMETRY | Obtains the geometry of the local window buffer.<br>Variable arguments in the function: [Output] int32_t height and [Output] int32_t width.|
| GET_FORMAT | Obtains the format of the local window buffer.<br>Variable arguments in the function: [Output] int32_tformat. For details about the available options, see [OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format).|
| SET_FORMAT | Sets the format of the local window buffer.<br>Variable arguments in the function: [Input] int32_t format. For details about the available options, see [OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format).|
| GET_USAGE | Obtains the read/write mode of the local window.<br>Variable arguments in the function: [Output] uint64_tusage. For details about the available options, see [OH_NativeBuffer_Usage](capi-native-buffer-h.md#oh_nativebuffer_usage).|
| SET_USAGE | Sets the usage mode for the local window buffer.<br>Variable argument in the function: [Input] uint64_t usage.<br>For details about the available options, see [OH_NativeBuffer_Usage](capi-native-buffer-h.md#oh_nativebuffer_usage).|
| SET_STRIDE | Sets the stride for the local window buffer.<br>Variable argument in the function: [Input] int32_t stride.<br>**Deprecated from**: 16|
| GET_STRIDE | Obtains the stride of the local window buffer.<br>Variable argument in the function: [Output] int32_t *stride.<br>**Deprecated from**: 16<br>**Substitute**: Use [OH_NativeWindow_GetBufferHandleFromNative](#oh_nativewindow_getbufferhandlefromnative) to obtain a [BufferHandle](capi-nativewindow-bufferhandle.md) instance, and obtain the stride from this instance.|
| SET_SWAP_INTERVAL | Sets the swap interval for the local window buffer.<br>Variable argument in the function: [Input] int32_t interval.|
| GET_SWAP_INTERVAL | Obtains the swap interval of the local window buffer.<br>Variable argument in the function: [Output] int32_tinterval.|
| SET_TIMEOUT | Sets the timeout duration for requesting the local window buffer, in ms.<br>Default value: 3000 ms.<br>Variable argument in the function: [Input] int32_t timeout.|
| GET_TIMEOUT | Obtains the timeout duration for requesting the local window buffer, in ms.<br>Default value: 3000 ms.<br>Variable argument in the function: [Output] int32_t timeout.|
| SET_COLOR_GAMUT | Sets the color gamut for the local window buffer.<br>Variable argument in the function: [Input] int32_t colorGamut.<br>For details about the available options, see [OH_NativeBuffer_ColorGamut](capi-native-buffer-h.md#oh_nativebuffer_colorgamut).|
| GET_COLOR_GAMUT | Obtains the color gamut of the local window buffer.<br>Variable arguments in the function: [Output] int32_tcolorGamut. For details about the available options, see [OH_NativeBuffer_ColorGamut](capi-native-buffer-h.md#oh_nativebuffer_colorgamut).|
| SET_TRANSFORM | Sets the transform for the local window buffer.<br>Variable argument in the function: [Input] int32_t transform.<br>For details about the available options, see [OH_NativeBuffer_TransformType](capi-native-buffer-h.md#oh_nativebuffer_transformtype).|
| GET_TRANSFORM | Sets the transform for the local window buffer.<br>Variable argument in the function: [Output] int32_t transform.<br>For details about the available options, see [OH_NativeBuffer_TransformType](capi-native-buffer-h.md#oh_nativebuffer_transformtype).|
| SET_UI_TIMESTAMP | Sets the UI timestamp for the local window buffer.<br>Variable argument in the function: [Input] uint64_t uiTimestamp.|
| GET_BUFFERQUEUE_SIZE | Obtains the memory queue size.<br>Variable argument in the function: [Output] int32_t \*size.<br>**Since**: 12|
| SET_SOURCE_TYPE | Sets the source of content displayed in the local window.<br>Variable argument in the function: [Input] int32_t sourceType. For details about the available options, see [OHSurfaceSource](#ohsurfacesource).<br>**Since**: 12|
| GET_SOURCE_TYPE | Obtains the source of content displayed in the local window.<br>Variable argument in the function: [Output] int32_t *sourceType. For details about the available options, see [OHSurfaceSource](#ohsurfacesource).<br>**Since**: 12|
| SET_APP_FRAMEWORK_TYPE | Sets the application framework name of the local window.<br>Variable argument in the function: [Input] char* frameworkType. A maximum of 64 bytes are supported.<br>**Since**: 12|
| GET_APP_FRAMEWORK_TYPE | Obtains the application framework name of the local window.<br>Variable argument in the function: [Output] char* frameworkType.<br>**Since**: 12|
| SET_HDR_WHITE_POINT_BRIGHTNESS | Sets the brightness of HDR white points.<br>Variable arguments in the function: [Input] float brightness. The value range is [0.0f, 1.0f].<br>**Since**: 12|
| SET_SDR_WHITE_POINT_BRIGHTNESS | Sets the brightness of SDR white points.<br>Variable arguments in the function: [Input] float brightness. The value range is [0.0f, 1.0f].<br>**Since**: 12|
| SET_DESIRED_PRESENT_TIMESTAMP = 24 | Sets a timestamp indicating when the local window buffer is expected to show on the screen.<br> The timestamp takes effect only when RenderService is the consumer of the local window<br>and after [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer) is called.<br>The next buffer added to the queue by the producer is consumed by RenderService and displayed on the screen only after the expected on-screen time arrives.<br>If there are multiple buffers in the queue from various producers, all of them have set **desiredPresentTimestamp**, and the desired time arrives, the buffer that was enqueued earliest will be pushed back into the queue by the consumer.<br>If the expected on-screen time exceeds the time provided by the consumer by over 1 second, the expected timestamp is ignored.<br> Variable argument in the function: [Input] int64_t desiredPresentTimestamp. The value must be greater than 0 and should be generated by the standard library std::chrono::steady_clock, in nanoseconds.<br>**Since**: 13|

### OHScalingMode

```
enum OHScalingMode
```

**Description**

Enumerates the scaling modes.

**Since**: 9

**Deprecated from**: 10

**Substitute API**: [OHScalingModeV2](#ohscalingmodev2)

| Enum| Description|
| -- | -- |
| OH_SCALING_MODE_FREEZE = 0 | The window content cannot be updated before the buffer of the window size is received.|
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

| Enum| Description|
| -- | -- |
| OH_SCALING_MODE_FREEZE_V2 = 0 | Freezes the window. The window content is not updated until a buffer with the same size as the window is received.|
| OH_SCALING_MODE_SCALE_TO_WINDOW_V2 | Scales the buffer to match the window size.|
| OH_SCALING_MODE_SCALE_CROP_V2 | Scales the buffer at the original aspect ratio to enable the smaller side of the buffer to match the window, while making the excess part transparent.|
| OH_SCALING_MODE_NO_SCALE_CROP_V2 | Crops the buffer by window size. Pixels outside the cropping rectangle are considered completely transparent.|
| OH_SCALING_MODE_SCALE_FIT_V2 | Scales the buffer at the original aspect ratio to fully display the buffer content, while filling the unfilled area of the window with the background color.<br>This mode is not available for the development board and emulator.|

### OHHDRMetadataKey

```
enum OHHDRMetadataKey
```

**Description**

Enumerates the HDR metadata keys.

**Since**: 9

**Deprecated from**: 10

| Enum| Description|
| -- | -- |
| OH_METAKEY_RED_PRIMARY_X = 0 | X coordinate of the red primary color.|
| OH_METAKEY_RED_PRIMARY_Y = 1, | Y coordinate of the red primary color.|
| OH_METAKEY_GREEN_PRIMARY_X = 2, | X coordinate of the green primary color.|
| OH_METAKEY_GREEN_PRIMARY_Y = 3, | Y coordinate of the green primary color.|
| OH_METAKEY_BLUE_PRIMARY_X = 4, | X coordinate of the blue primary color.|
| OH_METAKEY_BLUE_PRIMARY_Y = 5, | Y coordinate of the blue primary color.|
| OH_METAKEY_WHITE_PRIMARY_X = 6, | X coordinate of the white point.|
| OH_METAKEY_WHITE_PRIMARY_Y = 7, | Y coordinate of the white point.|
| OH_METAKEY_MAX_LUMINANCE = 8, | Maximum luminance.|
| OH_METAKEY_MIN_LUMINANCE = 9, | Minimum luminance.|
| OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, | Maximum content light level (MaxCLL).|
| OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11, | Maximum frame average light level.|
| OH_METAKEY_HDR10_PLUS = 12, | HDR10 Plus.|
| OH_METAKEY_HDR_VIVID = 13, | Vivid.|

### OHSurfaceSource

```
enum OHSurfaceSource
```

**Description**

Defines an enum for the sources of content displayed in the local window.

**Since**: 12

| Enum| Description|
| -- | -- |
| OH_SURFACE_SOURCE_DEFAULT = 0 | Default source.|
| OH_SURFACE_SOURCE_UI | The window content comes from UIs.|
| OH_SURFACE_SOURCE_GAME | The window content comes from games.|
| OH_SURFACE_SOURCE_CAMERA | The window content comes from cameras.|
| OH_SURFACE_SOURCE_VIDEO | The window content comes from videos.|


## Function Description

### OH_NativeWindow_CreateNativeWindow()

```
OHNativeWindow* OH_NativeWindow_CreateNativeWindow(void* pSurface)
```

**Description**

Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called.<br>Note: If this API is unavailable, you can use [OH_NativeImage_AcquireNativeWindow](capi-native-image-h.md#oh_nativeimage_acquirenativewindow) or XComponent as a substitute.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Deprecated from**: 12

**Parameters**

| Name| Description|
| -- | -- |
| void* pSurface | Pointer to a **ProduceSurface**. The type is **sptr\<OHOS::Surface>**.|

**Returns**

| Type| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md)* | Returns the pointer to the **OHNativeWindow** instance created.|

### OH_NativeWindow_DestroyNativeWindow()

```
void OH_NativeWindow_DestroyNativeWindow(OHNativeWindow* window)
```

**Description**

Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md)* window | Pointer to an **OHNativeWindow** instance.|

### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer(void* pSurfaceBuffer)
```

**Description**

Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.<br>Note: If this API is unavailable, you can use [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer) as a substitute.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8

**Deprecated from**: 12

**Substitute**: [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer)


**Parameters**

| Name| Description|
| -- | -- |
| void* pSurfaceBuffer | Pointer to a **ProduceSurfaceBuffer**. The type is **sptr<OHOS::SurfaceBuffer>**.|

**Returns**

| Type| Description|
| -- | -- |
| OHNativeWindowBuffer* | Returns the pointer to the **OHNativeWindowBuffer** instance created.|

### OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(OH_NativeBuffer* nativeBuffer)
```

**Description**

Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.<br>This function must be used in pair with [OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer). Otherwise, memory leak occurs.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| OH_NativeBuffer* nativeBuffer | Pointer to an **OH_NativeBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| OHNativeWindowBuffer* | Returns the pointer to the **OHNativeWindowBuffer** instance created.|

### OH_NativeWindow_DestroyNativeWindowBuffer()

```
void OH_NativeWindow_DestroyNativeWindowBuffer(OHNativeWindowBuffer* buffer)
```

**Description**

Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md)* buffer | Pointer to an **OHNativeWindowBuffer** instance.|

### OH_NativeWindow_NativeWindowRequestBuffer()

```
int32_t OH_NativeWindow_NativeWindowRequestBuffer(OHNativeWindow *window,OHNativeWindowBuffer **buffer, int *fenceFd)
```

**Description**

Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.<br>Before calling this function, you must call [SET_BUFFER_GEOMETRY](#nativewindowoperation) to set the width and height of **OHNativeWindow**.<br>This function must be used in pair with [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer). Otherwise, memory leak occurs.<br>When **fenceFd** is used up, you must close it.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) **buffer | Double pointer to an **OHNativeWindowBuffer** instance.<br>You can obtain the **BufferHandle** struct by calling **OH_NativeWindow_GetBufferHandleFromNative** to access the buffer memory.|
| int *fenceFd | File descriptor handle, used for GPU/CPU sync. The returns are as follows:<br>- ≥0: The buffer is being used by the GPU. You need to wait until the file descriptor is ready.<br>- -1: The buffer can be used directly.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_NativeWindowFlushBuffer()

```
int32_t OH_NativeWindow_NativeWindowFlushBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer,int fenceFd, Region region)
```

**Description**

Flushes the **OHNativeWindowBuffer** filled with the produced content to the buffer queue through an **OHNativeWindow** instance for content consumption.<br>The system will close **fenceFd**. You do not need to close it.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) *buffer | Pointer to an **OHNativeWindowBuffer** instance.|
| int fenceFd | File descriptor handle, which is used for timing synchronization. The options are as follows:<br>- -1: The CPU rendering is complete, and no timing synchronization is required.<br>- ≥0: The handle is converted from a GPU synchronization object (for example, **eglDupNativeFenceFDANDROID** of EGL). The peer end needs to synchronize timing through fenceFd.|
| [Region](capi-nativewindow-region.md) region | Region struct, which indicates a dirty region where content is updated.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_GetLastFlushedBuffer()

```
int32_t OH_NativeWindow_GetLastFlushedBuffer(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])
```

**Description**

Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 11

**Deprecated from**: 12

**Substitute**: [OH_NativeWindow_GetLastFlushedBufferV2](#oh_nativewindow_getlastflushedbufferv2)


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) **buffer | Double pointer to an **OHNativeWindowBuffer** instance.|
| int *fenceFd | Pointer to a file descriptor.|
| matrix |  Retrieved 4*4 transformation matrix.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_NativeWindowAbortBuffer()

```
int32_t OH_NativeWindow_NativeWindowAbortBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)
```

**Description**

Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) *buffer | Pointer to an **OHNativeWindowBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_NativeWindowHandleOpt()

```
int32_t OH_NativeWindow_NativeWindowHandleOpt(OHNativeWindow *window, int code, ...)
```

**Description**

Sets or obtains the attributes of an **OHNativeWindow** instance, including the width, height, and content format.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| int code | Operation code. For details, see [NativeWindowOperation](#nativewindowoperation).|
| ... |  Variable argument, which must be the same as the data type corresponding to the operation code. The number of input parameters must be the same as that of the operation code. Otherwise, undefined behavior may occur.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_GetBufferHandleFromNative()

```
BufferHandle *OH_NativeWindow_GetBufferHandleFromNative(OHNativeWindowBuffer *buffer)
```

**Description**

Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) *buffer | Pointer to an **OHNativeWindowBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [BufferHandle](capi-nativewindow-bufferhandle.md) | Returns the pointer to the [BufferHandle](capi-nativewindow-bufferhandle.md) instance obtained.|

### OH_NativeWindow_NativeObjectReference()

```
int32_t OH_NativeWindow_NativeObjectReference(void *obj)
```

**Description**

Adds the reference count of a native object.<br>This function must be used in pair with [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference). Otherwise, memory leak occurs.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| void *obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_NativeObjectUnreference()

```
int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)
```

**Description**

Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| void *obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_GetNativeObjectMagic()

```
int32_t OH_NativeWindow_GetNativeObjectMagic(void *obj)
```

**Description**

Obtains the magic ID of a native object.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| void *obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns the magic ID, which is unique for each native object.|

### OH_NativeWindow_NativeWindowSetScalingMode()

```
int32_t OH_NativeWindow_NativeWindowSetScalingMode(OHNativeWindow *window, uint32_t sequence,OHScalingMode scalingMode)
```

**Description**

Sets a scaling mode for an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated from**: 10

**Substitute**: [OH_NativeWindow_NativeWindowSetScalingModeV2](#oh_nativewindow_nativewindowsetscalingmodev2)


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| uint32_t sequence | Sequence of the producer buffer.|
| [OHScalingMode](#ohscalingmode) scalingMode | Scaling mode to set. For details, see [OHScalingMode](#ohscalingmode).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** if the operation is successful.|

### OH_NativeWindow_NativeWindowSetMetaData()

```
int32_t OH_NativeWindow_NativeWindowSetMetaData(OHNativeWindow *window, uint32_t sequence, int32_t size,const OHHDRMetaData *metaData)
```

**Description**

Sets metadata for an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated from**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| uint32_t sequence | Sequence of the producer buffer.|
| int32_t size | Size of the **OHHDRMetaData** array.|
| metaData |  Pointer to the **OHHDRMetaData** array.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** if the operation is successful.|

### OH_NativeWindow_NativeWindowSetMetaDataSet()

```
int32_t OH_NativeWindow_NativeWindowSetMetaDataSet(OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key,int32_t size, const uint8_t *metaData)
```

**Description**

Sets a metadata set for an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated from**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| uint32_t sequence | Sequence of the producer buffer.|
| [OHHDRMetadataKey](#ohhdrmetadatakey) key | Metadata key. For details, see [OHHDRMetadataKey](#ohhdrmetadatakey).|
| int32_t size | Size of the uint8_t vector.|
| metaDate |  Pointer to the uint8_t vector.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** if the operation is successful.|

### OH_NativeWindow_NativeWindowSetTunnelHandle()

```
int32_t OH_NativeWindow_NativeWindowSetTunnelHandle(OHNativeWindow *window, const OHExtDataHandle *handle)
```

**Description**

Sets a tunnel handle to an **OHNativeWindow**.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 9

**Deprecated from**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| const [OHExtDataHandle](capi-nativewindow-ohextdatahandle.md) *handle | Pointer to an **OHExtDataHandle** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | **0** if the operation is successful.|

### OH_NativeWindow_NativeWindowAttachBuffer()

```
int32_t OH_NativeWindow_NativeWindowAttachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)
```

**Description**

Attaches an **OHNativeWindowBuffer** to an **OHNativeWindow** instance.<br>This function must be used in pair with [OH_NativeWindow_NativeWindowDetachBuffer](#oh_nativewindow_nativewindowdetachbuffer). Otherwise, memory management disorder may occur.<br>This function is not thread-safe.<br>

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) *buffer | Pointer to an **OHNativeWindowBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_NativeWindowDetachBuffer()

```
int32_t OH_NativeWindow_NativeWindowDetachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)
```

**Description**

Detaches an **OHNativeWindowBuffer** from an **OHNativeWindow** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) *buffer | Pointer to an **OHNativeWindowBuffer** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_GetSurfaceId()

```
int32_t OH_NativeWindow_GetSurfaceId(OHNativeWindow *window, uint64_t *surfaceId)
```

**Description**

Obtains a surface ID through an **OHNativeWindow**.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| uint64_t *surfaceId | Pointer to the surface ID.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_CreateNativeWindowFromSurfaceId()

```
int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId(uint64_t surfaceId, OHNativeWindow **window)
```

**Description**

Creates an **OHNativeWindow** instance based on a surface ID.<br>This function must be used in pair with [OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow). Otherwise, memory leak occurs.<br>If **OHNativeWindow** instances are released concurrently, call [OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference) and [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference) to increase and decrease the reference count of **OHNativeWindow**.<br>The surface obtained by using the surface ID must be created in the current process, but not in a different process.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t surfaceId | Surface ID.|
| [OHNativeWindow](capi-nativewindow-nativewindow.md) **window | Double pointer to an **OHNativeWindow** instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_NativeWindowSetScalingModeV2()

```
int32_t OH_NativeWindow_NativeWindowSetScalingModeV2(OHNativeWindow* window, OHScalingModeV2 scalingMode)
```

**Description**

Sets a rendering scaling mode for an **OHNativeWindow** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md)* window | Pointer to an **OHNativeWindow** instance.|
| [OHScalingModeV2](#ohscalingmodev2) scalingMode | Scaling mode. For details about the available options, see **OHScalingModeV2**.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_GetLastFlushedBufferV2()

```
int32_t OH_NativeWindow_GetLastFlushedBufferV2(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])
```

**Description**

Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance. The difference between this function and **OH_NativeWindow_GetLastFlushedBuffer** lies in the matrix.<br>This function must be used in pair with [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference). Otherwise, memory leak occurs.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an **OHNativeWindow** instance.|
| [OHNativeWindowBuffer](capi-nativewindow-nativewindowbuffer.md) **buffer | Double pointer to an **OHNativeWindowBuffer** instance.|
| int *fenceFd | Pointer to a file descriptor.|
| matrix |  Retrieved 4*4 transformation matrix.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_SetBufferHold()

```
void OH_NativeWindow_SetBufferHold(OHNativeWindow *window)
```

**Description**

Buffers a frame in advance and holds it for the interval of a frame to offset the possible loss of subsequent oversized frames.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|

### OH_NativeWindow_WriteToParcel()

```
int32_t OH_NativeWindow_WriteToParcel(OHNativeWindow *window, OHIPCParcel *parcel)
```

**Description**

Writes an **OHNativeWindow** instance to an **OHIPCParcel** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|
| [OHIPCParcel](capi-nativewindow-ohipcparcel.md) *parcel | Pointer to an [OHIPCParcel](capi-nativewindow-ohipcparcel.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_ReadFromParcel()

```
int32_t OH_NativeWindow_ReadFromParcel(OHIPCParcel *parcel, OHNativeWindow **window)
```

**Description**

Reads an **OHNativeWindow** instance from an **OHIPCParcel** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHIPCParcel](capi-nativewindow-ohipcparcel.md) *parcel | Pointer to an [OHIPCParcel](capi-nativewindow-ohipcparcel.md) instance.|
| [OHNativeWindow](capi-nativewindow-nativewindow.md) **window | Double pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_SetColorSpace()

```
int32_t OH_NativeWindow_SetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace colorSpace)
```

**Description**

Sets the color space for an **OHNativeWindow** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|
| [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace) colorSpace | Pointer to the color space. For details about the available options, see [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_GetColorSpace()

```
int32_t OH_NativeWindow_GetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace *colorSpace)
```

**Description**

Obtains the color space of an **OHNativeWindow** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|
| [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace) *colorSpace | Pointer to the color space. For details about the available options, see [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace).|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_SetMetadataValue()

```
int32_t OH_NativeWindow_SetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t size, uint8_t *metadata)
```

**Description**

Sets a metadata value for an **OHNativeWindow** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|
| [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey) metadataKey | Metadata type of the window. The value is obtained from [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey).|
| int32_t size | Size of the uint8_t vector. For details about the value range, see [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey).|
| metaDate |  Pointer to the uint8_t vector.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_GetMetadataValue()

```
int32_t OH_NativeWindow_GetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t *size, uint8_t **metadata)
```

**Description**

Obtains the metadata value of an **OHNativeWindow** instance.<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|
| [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey) metadataKey | Metadata type of the window. The value is obtained from [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey).|
| int32_t *size | Size of the uint8_t vector. For details about the value range, see [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey).|
| metaDate |  Double pointer to the uint8_t vector.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

### OH_NativeWindow_CleanCache()

```
int32_t OH_NativeWindow_CleanCache(OHNativeWindow *window)
```

**Description**

Clears the **OHNativeWindowBuffer** cache in **OHNativeWindow**.<br>Ensure that **OHNativeWindowBuffer** has been successfully allocated by calling [OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer).<br>This function is not thread-safe.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [OHNativeWindow](capi-nativewindow-nativewindow.md) *window | Pointer to an [OHNativeWindow](capi-nativewindow-nativewindow.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Returns **0** if the operation is successful; returns an error code defined in [OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode) otherwise.|

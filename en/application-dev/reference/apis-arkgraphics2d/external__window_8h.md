# external_window.h


## Overview

The **external_window.h** file declares the functions for obtaining and using **NativeWindow**.

**File to include**: &lt;native_window/external_window.h&gt;

**Library**: libnative_window.so

**Since**: 8

**Related module**: [NativeWindow](_native_window.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [Region](_region.md) | Describes the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.| 
| struct  [Region::Rect](_rect.md) | Describes a rectangle.| 
| struct  [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | Describes the HDR metadata.| 
| struct  [OHExtDataHandle](_o_h_ext_data_handle.md) | Describes the extended data handle.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct NativeWindow [OHNativeWindow](_native_window.md#ohnativewindow) | Provides the capability of accessing the **OHNativeWindow**.| 
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) | Provides the capability of accessing the **OHNativeWindowBuffer**.| 
| typedef struct [Region](_region.md)  [Region](_native_window.md#region) | Defines a struct that describes the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [NativeWindowOperation](_native_window.md#nativewindowoperation) {<br>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br>SET_UI_TIMESTAMP, GET_BUFFERQUEUE_SIZE<br>} | Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.| 
| [OHScalingMode](_native_window.md#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | Enumerates the scaling modes.| 
| [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) {<br>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br>} | Enumerates the HDR metadata keys.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OHNativeWindow](_native_window.md#ohnativewindow) \* [OH_NativeWindow_CreateNativeWindow](_native_window.md#oh_nativewindow_createnativewindow) (void \*pSurface) | Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called. If this function is unavailable, you can create an **OHNativeWindow** instance by calling **OH_NativeImage_AcquireNativeWindow** or through the **<XComponent>**.| 
| void [OH_NativeWindow_DestroyNativeWindow](_native_window.md#oh_nativewindow_destroynativewindow) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window) | Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.| 
| [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called. If this function is unavailable, you can create an **OHNativeWindowBuffer** instance by calling [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromnativebuffer).| 
| [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromnativebuffer) (OH_NativeBuffer \*nativeBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.| 
| void [OH_NativeWindow_DestroyNativeWindowBuffer](_native_window.md#oh_nativewindow_destroynativewindowbuffer) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.| 
| int32_t [OH_NativeWindow_NativeWindowRequestBuffer](_native_window.md#oh_nativewindow_nativewindowrequestbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.| 
| int32_t [OH_NativeWindow_NativeWindowFlushBuffer](_native_window.md#oh_nativewindow_nativewindowflushbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer, int fenceFd, [Region](_region.md) region) | Flushes the **OHNativeWindowBuffer** filled with the produced content to the buffer queue through an **OHNativeWindow** instance for content consumption.| 
| int32_t [OH_NativeWindow_GetLastFlushedBuffer](_native_window.md#oh_nativewindow_getlastflushedbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*buffer, int \*fenceFd, float matrix[16]) | Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_NativeWindowAbortBuffer](_native_window.md#oh_nativewindow_nativewindowabortbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.| 
| int32_t [OH_NativeWindow_NativeWindowHandleOpt](_native_window.md#oh_nativewindow_nativewindowhandleopt) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow** instance, including the width, height, and content format.| 
| BufferHandle \* [OH_NativeWindow_GetBufferHandleFromNative](_native_window.md#oh_nativewindow_getbufferhandlefromnative) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.| 
| int32_t [OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference) (void \*obj) | Adds the reference count of a native object.| 
| int32_t [OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference) (void \*obj) | Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.| 
| int32_t [OH_NativeWindow_GetNativeObjectMagic](_native_window.md#oh_nativewindow_getnativeobjectmagic) (void \*obj) | Obtains the magic ID of a native object.| 
| int32_t [OH_NativeWindow_NativeWindowSetScalingMode](_native_window.md#oh_nativewindow_nativewindowsetscalingmode) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHScalingMode](_native_window.md#ohscalingmode) scalingMode) | Sets a scaling mode for an **OHNativeWindow**.| 
| int32_t [OH_NativeWindow_NativeWindowSetMetaData](_native_window.md#oh_nativewindow_nativewindowsetmetadata) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, int32_t size, const [OHHDRMetaData](_o_h_h_d_r_meta_data.md) \*metaData) | Sets metadata for an **OHNativeWindow**.| 
| int32_t [OH_NativeWindow_NativeWindowSetMetaDataSet](_native_window.md#oh_nativewindow_nativewindowsetmetadataset) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) key, int32_t size, const uint8_t \*metaData) | Sets a metadata set for an **OHNativeWindow**.| 
| int32_t [OH_NativeWindow_NativeWindowSetTunnelHandle](_native_window.md#oh_nativewindow_nativewindowsettunnelhandle) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, const [OHExtDataHandle](_o_h_ext_data_handle.md) \*handle) | Sets a tunnel handle to an **OHNativeWindow**.| 
| int32_t [OH_NativeWindow_NativeWindowAttachBuffer](_native_window.md#oh_nativewindow_nativewindowattachbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Attaches an **OHNativeWindowBuffer** to an **OHNativeWindow** instance.| 
| int32_t [OH_NativeWindow_NativeWindowDetachBuffer](_native_window.md#oh_nativewindow_nativewindowdetachbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Detaches an **OHNativeWindowBuffer** from an **OHNativeWindow** instance.|
| int32_t [OH_NativeWindow_GetSurfaceId](_native_window.md#oh_nativewindow_getsurfaceid) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint64_t \*surfaceId) | Obtains a surface ID through an **OHNativeWindow**.| 
| int32_t [OH_NativeWindow_CreateNativeWindowFromSurfaceId](_native_window.md#oh_nativewindow_createnativewindowfromsurfaceid) (uint64_t surfaceId, [OHNativeWindow](_native_window.md#ohnativewindow) \*\*window) | Creates an **OHNativeWindow** instance based on a surface ID.| 

# external_window.h


## Overview

The **external_window.h** file declares the functions for obtaining and using **NativeWindow**.

**Library**: libnative_window.so

**Since**: 8

**Related module**: [NativeWindow](_native_window.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [Region](_region.md) | Defines the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.|
| [Region::Rect](_rect.md) | Describes a rectangle on the display.|
| [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | Defines the HDR metadata.|
| [OHExtDataHandle](_o_h_ext_data_handle.md) | Defines the extended data handle.|


### Types

| Name| Description|
| -------- | -------- |
| [OHNativeWindow](_native_window.md#ohnativewindow) | Provides the capability of accessing the **OHNativeWindow**.|
| [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) | Provides the capability of accessing the **OHNativeWindowBuffer**.|
| [Region](_native_window.md#region) | Defines the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.|


### Enums

| Name| Description|
| -------- | -------- |
| [NativeWindowOperation](_native_window.md#nativewindowoperation) {<br>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,<br>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br>SET_UI_TIMESTAMP<br>} | Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.|
| [OHScalingMode](_native_window.md#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | Enumerates the scaling modes.|
| [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) {<br>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br>} | Enumerates the HDR metadata keys.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindow](_native_window.md#oh_nativewindow_createnativewindow) (void \*pSurface) | Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called.|
| [OH_NativeWindow_DestroyNativeWindow](_native_window.md#oh_nativewindow_destroynativewindow) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window) | Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.|
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.|
| [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromnativebuffer) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*nativeBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.|
| [OH_NativeWindow_DestroyNativeWindowBuffer](_native_window.md#oh_nativewindow_destroynativewindowbuffer) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.|
| [OH_NativeWindow_NativeWindowRequestBuffer](_native_window.md#oh_nativewindow_nativewindowrequestbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.|
| [OH_NativeWindow_NativeWindowFlushBuffer](_native_window.md#oh_nativewindow_nativewindowflushbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer, int fenceFd, [Region](_region.md) region) | Flushes the **OHNativeWindowBuffer** filled with the content to the buffer queue through an **OHNativeWindow** instance for content consumption.|
| [OH_NativeWindow_GetLastFlushedBuffer](_native_window.md#oh_nativewindow_getlastflushedbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Obtains the **OHNativeWindowBuffer** that was flushed to the buffer queue last time through an **OHNativeWindow** instance.|
| [OH_NativeWindow_NativeWindowAbortBuffer](_native_window.md#oh_nativewindow_nativewindowabortbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.|
| [OH_NativeWindow_NativeWindowHandleOpt](_native_window.md#oh_nativewindow_nativewindowhandleopt) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow**, including the width, height, and content format.|
| [OH_NativeWindow_GetBufferHandleFromNative](_native_window.md#oh_nativewindow_getbufferhandlefromnative) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.|
| [OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference) (void \*obj) | Adds the reference count of a native object.|
| [OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference) (void \*obj) | Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.|
| [OH_NativeWindow_GetNativeObjectMagic](_native_window.md#oh_nativewindow_getnativeobjectmagic) (void \*obj) | Obtains the magic ID of a native object.|
| [OH_NativeWindow_NativeWindowSetScalingMode](_native_window.md#oh_nativewindow_nativewindowsetscalingmode) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHScalingMode](_native_window.md#ohscalingmode) scalingMode) | Sets a scaling mode for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetMetaData](_native_window.md#oh_nativewindow_nativewindowsetmetadata) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, int32_t size, const [OHHDRMetaData](_o_h_h_d_r_meta_data.md) \*metaData) | Sets metadata for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetMetaDataSet](_native_window.md#oh_nativewindow_nativewindowsetmetadataset) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) key, int32_t size, const uint8_t \*metaData) | Sets a metadata set for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetTunnelHandle](_native_window.md#oh_nativewindow_nativewindowsettunnelhandle) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, const [OHExtDataHandle](_o_h_ext_data_handle.md) \*handle) | Sets a tunnel handle to an **OHNativeWindow**.|

# external_window.h


## Overview

The **external_window.h** file declares the functions for obtaining and using **NativeWindow**.

**Since**

8

**Related Modules**

[NativeWindow](_native_window.md)


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
| [NativeWindowOperation](_native_window.md#nativewindowoperation) {<br>[SET_BUFFER_GEOMETRY](_native_window.md), [GET_BUFFER_GEOMETRY](_native_window.md), [GET_FORMAT](_native_window.md), [SET_FORMAT](_native_window.md),<br>[GET_USAGE](_native_window.md), [SET_USAGE](_native_window.md), [SET_STRIDE](_native_window.md), [GET_STRIDE](_native_window.md),<br>[SET_SWAP_INTERVAL](_native_window.md), [GET_SWAP_INTERVAL](_native_window.md), [SET_TIMEOUT](_native_window.md), [GET_TIMEOUT](_native_window.md),<br>[SET_COLOR_GAMUT](_native_window.md), [GET_COLOR_GAMUT](_native_window.md), [SET_TRANSFORM](_native_window.md), [GET_TRANSFORM](_native_window.md),<br>[SET_UI_TIMESTAMP](_native_window.md)<br>} | Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.|
| [OHScalingMode](_native_window.md#ohscalingmode) { [OH_SCALING_MODE_FREEZE](_native_window.md) = 0, [OH_SCALING_MODE_SCALE_TO_WINDOW](_native_window.md), [OH_SCALING_MODE_SCALE_CROP](_native_window.md), [OH_SCALING_MODE_NO_SCALE_CROP](_native_window.md) } | Enumerates the scaling modes.|
| [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) {<br>[OH_METAKEY_RED_PRIMARY_X](_native_window.md) = 0, [OH_METAKEY_RED_PRIMARY_Y](_native_window.md) = 1, [OH_METAKEY_GREEN_PRIMARY_X](_native_window.md) = 2, [OH_METAKEY_GREEN_PRIMARY_Y](_native_window.md) = 3,<br>[OH_METAKEY_BLUE_PRIMARY_X](_native_window.md) = 4, [OH_METAKEY_BLUE_PRIMARY_Y](_native_window.md) = 5, [OH_METAKEY_WHITE_PRIMARY_X](_native_window.md) = 6, [OH_METAKEY_WHITE_PRIMARY_Y](_native_window.md) = 7,<br>[OH_METAKEY_MAX_LUMINANCE](_native_window.md) = 8, [OH_METAKEY_MIN_LUMINANCE](_native_window.md) = 9, [OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL](_native_window.md) = 10, [OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL](_native_window.md) = 11,<br>[OH_METAKEY_HDR10_PLUS](_native_window.md) = 12, [OH_METAKEY_HDR_VIVID](_native_window.md) = 13<br>} | Enumerates the HDR metadata keys.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindow](_native_window.md#oh_nativewindow_createnativewindow) (void \*pSurface) | Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called.|
| [OH_NativeWindow_DestroyNativeWindow](_native_window.md#oh_nativewindow_destroynativewindow) (OHNativeWindow \*window) | Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.|
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.|
| [OH_NativeWindow_DestroyNativeWindowBuffer](_native_window.md#oh_nativewindow_destroynativewindowbuffer) (OHNativeWindowBuffer \*buffer) | Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.|
| [OH_NativeWindow_NativeWindowRequestBuffer](_native_window.md#oh_nativewindow_nativewindowrequestbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.|
| [OH_NativeWindow_NativeWindowFlushBuffer](_native_window.md#oh_nativewindow_nativewindowflushbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | Flushes the **OHNativeWindowBuffer** filled with the content to the buffer queue through an **OHNativeWindow** instance for content consumption.|
| [OH_NativeWindow_NativeWindowAbortBuffer](_native_window.md#oh_nativewindow_nativewindowabortbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer) | Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.|
| [OH_NativeWindow_NativeWindowHandleOpt](_native_window.md#oh_nativewindow_nativewindowhandleopt) (OHNativeWindow*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow**, including the width, height, and content format.|
| [OH_NativeWindow_GetBufferHandleFromNative](_native_window.md#oh_nativewindow_getbufferhandlefromnative) (OHNativeWindowBuffer \*buffer) | Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.|
| [OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference) (void \*obj) | Adds the reference count of a native object.|
| [OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference) (void \*obj) | Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.|
| [OH_NativeWindow_GetNativeObjectMagic](_native_window.md#oh_nativewindow_getnativeobjectmagic) (void \*obj) | Obtains the magic ID of a native object.|
| [OH_NativeWindow_NativeWindowSetScalingMode](_native_window.md#oh_nativewindow_nativewindowsetscalingmode) (OHNativeWindownative_window.md#ohscalingmode) scalingMode) | Sets a scaling mode for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetMetaData](_native_window.md#oh_nativewindow_nativewindowsetmetadata) (OHNativeWindow \*window, uint32_t sequence, int32_t size, const OHHDRMetaData \*metaData) | Sets metadata for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetMetaDataSet](_native_window.md#oh_nativewindow_nativewindowsetmetadataset) (OHNativeWindow \*window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t \*metaData) | Sets a metadata set for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetTunnelHandle](_native_window.md#oh_nativewindow_nativewindowsettunnelhandle) (OHNativeWindow \*window, const OHExtDataHandle \*handle) | Sets a tunnel handle to an **OHNativeWindow**.|

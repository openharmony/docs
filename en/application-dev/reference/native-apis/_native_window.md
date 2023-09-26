# NativeWindow


## Overview

The **NativeWindow** module provides the **NativeWindow** capability for connection to the EGL.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Since**

8


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [external_window.h](external__window_8h.md) | Declares the functions for obtaining and using **NativeWindow**.<br>File to include: &lt;native_window/external_window.h&gt; |


### Structs

| Name| Description|
| -------- | -------- |
| [Region](_region.md) | Defines the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.|
| [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | Defines the HDR metadata.|
| [OHExtDataHandle](_o_h_ext_data_handle.md) | Defines the extended data handle.|


### Types

| Name| Description|
| -------- | -------- |
| [OHNativeWindow](#ohnativewindow) | Provides the capability of accessing the **OHNativeWindow**.|
| [OHNativeWindowBuffer](#ohnativewindowbuffer) | Provides the capability of accessing the **OHNativeWindowBuffer**.|
| [Region](#region) | Defines the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.|


### Enums

| Name| Description|
| -------- | -------- |
| [NativeWindowOperation](#nativewindowoperation) {<br>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,<br>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br>SET_UI_TIMESTAMP<br>} | Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.|
| [OHScalingMode](#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | Enumerates the scaling modes.|
| [OHHDRMetadataKey](#ohhdrmetadatakey) {<br>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br>} | Enumerates the HDR metadata keys.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindow](#oh_nativewindow_createnativewindow) (void \*pSurface) | Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called.|
| [OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow) (OHNativeWindow \*window) | Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.|
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.|
| [OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer) (OHNativeWindowBuffer \*buffer) | Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.|
| [OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.|
| [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | Flushes the **OHNativeWindowBuffer** filled with the content to the buffer queue through an **OHNativeWindow** instance for content consumption.|
| [OH_NativeWindow_NativeWindowAbortBuffer](#oh_nativewindow_nativewindowabortbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer) | Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.|
| [OH_NativeWindow_NativeWindowHandleOpt](#oh_nativewindow_nativewindowhandleopt) (OHNativeWindow \*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow**, including the width, height, and content format.|
| [OH_NativeWindow_GetBufferHandleFromNative](#oh_nativewindow_getbufferhandlefromnative) (OHNativeWindowBuffer \*buffer) | Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.|
| [OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference) (void \*obj) | Adds the reference count of a native object.|
| [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference) (void \*obj) | Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.|
| [OH_NativeWindow_GetNativeObjectMagic](#oh_nativewindow_getnativeobjectmagic) (void \*obj) | Obtains the magic ID of a native object.|
| [OH_NativeWindow_NativeWindowSetScalingMode](#oh_nativewindow_nativewindowsetscalingmode) (OHNativeWindow \*window, uint32_t sequence, OHScalingMode scalingMode) | Sets a scaling mode for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetMetaData](#oh_nativewindow_nativewindowsetmetadata) (OHNativeWindow \*window, uint32_t sequence, int32_t size, const OHHDRMetaData \*metaData) | Sets metadata for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetMetaDataSet](#oh_nativewindow_nativewindowsetmetadataset) (OHNativeWindow*window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t \*metaData) | Sets a metadata set for an **OHNativeWindow**.|
| [OH_NativeWindow_NativeWindowSetTunnelHandle](#oh_nativewindow_nativewindowsettunnelhandle) (OHNativeWindow \*window, const OHExtDataHandle \*handle) | Sets a tunnel handle to an **OHNativeWindow**.|


## Type Description


### OHNativeWindow


```
typedef struct NativeWindow OHNativeWindow
```

**Description**

Provides the capability of accessing the **OHNativeWindow**.


### OHNativeWindowBuffer


```
typedef struct NativeWindowBuffer OHNativeWindowBuffer
```

**Description**

Provides the capability of accessing the **OHNativeWindowBuffer**.


### Region


```
typedef struct Region Region
```

**Description**

Defines the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.


## Enum Description


### NativeWindowOperation


```
enum NativeWindowOperation
```

**Description**

Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.

| Value| Description|
| -------- | -------- |
| SET_BUFFER_GEOMETRY | Setting the geometry for the local window buffer.<br>Variable arguments in the function: [Input] int32_t height and [Input] int32_t width.|
| GET_BUFFER_GEOMETRY | Obtaining the geometry of the local window buffer.<br>Variable arguments in the function: [Output] int32_t *height and [Output] int32_t *width.|
| GET_FORMAT | Obtaining the format of the local window buffer.<br>Variable argument in the function: [Output] int32_t *format.|
| SET_FORMAT | Setting the format for the local window buffer.<br>Variable argument in the function: [Input] int32_t format.|
| GET_USAGE | Obtaining the usage mode of the local window buffer.<br>Variable argument in the function: [Output] int32_t *usage.|
| SET_USAGE | Setting the usage mode for the local window buffer.<br>Variable argument in the function: [Input] int32_t usage.|
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


### OHHDRMetadataKey


```
enum OHHDRMetadataKey
```

**Description**

Enumerates the HDR metadata keys.

**Since**

9

**Deprecated**

This enum is deprecated since API version 10. No substitute enum is provided.

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
| OH_METAKEY_HDR10_PLUS | HDR10 Plus |
| OH_METAKEY_HDR_VIVID | Vivid |


### OHScalingMode


```
enum OHScalingMode
```

**Description**

Enumerates the scaling modes.

**Since**

9

**Deprecated**

This enum is deprecated since API version 10. No substitute enum is provided.

| Value| Description|
| -------- | -------- |
| OH_SCALING_MODE_FREEZE | The window content cannot be updated before the buffer of the window size is received.|
| OH_SCALING_MODE_SCALE_TO_WINDOW | The buffer is scaled in two dimensions to match the window size.|
| OH_SCALING_MODE_SCALE_CROP | The buffer is scaled uniformly so that its smaller size can match the window size.|
| OH_SCALING_MODE_NO_SCALE_CROP | The window is cropped to the size of the buffer's cropping rectangle. Pixels outside the cropping rectangle are considered completely transparent.|


## Function Description


### OH_NativeWindow_CreateNativeWindow()


```
OHNativeWindow* OH_NativeWindow_CreateNativeWindow (void * pSurface)
```

**Description**

Creates an **OHNativeWindow** instance. A new **OHNativeWindow** instance is created each time this function is called.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| pSurface | Pointer to a **ProduceSurface**. The type is **sptr&lt;OHOS::Surface&gt;**.|

**Returns**

Returns the pointer to the **OHNativeWindow** instance created.


### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()


```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void * pSurfaceBuffer)
```

**Description**

Creates an **OHNativeWindowBuffer** instance. A new **OHNativeWindowBuffer** instance is created each time this function is called.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| pSurfaceBuffer | Pointer to a **ProduceSurfaceBuffer**. The type is **sptr&lt;OHOS::SurfaceBuffer&gt;**.|

**Returns**

Returns the pointer to the **OHNativeWindowBuffer** instance created.


### OH_NativeWindow_DestroyNativeWindow()


```
void OH_NativeWindow_DestroyNativeWindow (OHNativeWindow *  window)
```

**Description**

Decreases the reference count of an **OHNativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|


### OH_NativeWindow_DestroyNativeWindowBuffer()


```
void OH_NativeWindow_DestroyNativeWindowBuffer (OHNativeWindowBuffer *  buffer)
```

**Description**

Decreases the reference count of an **OHNativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OHNativeWindowBuffer** instance.|


### OH_NativeWindow_GetBufferHandleFromNative()


```
BufferHandle* OH_NativeWindow_GetBufferHandleFromNative (OHNativeWindowBuffer *  buffer)
```

**Description**

Obtains the pointer to a **BufferHandle** of an **OHNativeWindowBuffer** instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OHNativeWindowBuffer** instance.|

**Returns**

Returns the pointer to the **BufferHandle** instance obtained.


### OH_NativeWindow_GetNativeObjectMagic()


```
int32_t OH_NativeWindow_GetNativeObjectMagic (void * obj)
```

**Description**

Obtains the magic ID of a native object.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.|

**Returns**

Returns the magic ID, which is unique for each native object.


### OH_NativeWindow_NativeObjectReference()


```
int32_t OH_NativeWindow_NativeObjectReference (void * obj)
```

**Description**

Adds the reference count of a native object.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeWindow_NativeObjectUnreference()


```
int32_t OH_NativeWindow_NativeObjectUnreference (void * obj)
```

**Description**

Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| obj | Pointer to an **OHNativeWindow** or **OHNativeWindowBuffer** instance.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeWindow_NativeWindowAbortBuffer()


```
int32_t OH_NativeWindow_NativeWindowAbortBuffer (OHNativeWindow *  window, OHNativeWindowBuffer *  buffer )
```

**Description**

Returns the **OHNativeWindowBuffer** to the buffer queue through an **OHNativeWindow** instance, without filling in any content. The **OHNativeWindowBuffer** can be used for a new request.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| buffer | Pointer to an **OHNativeWindowBuffer** instance.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeWindow_NativeWindowFlushBuffer()


```
int32_t OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow *  window, OHNativeWindowBuffer *  buffer, int fenceFd, Region region )
```

**Description**

Flushes the **OHNativeWindowBuffer** filled with the content to the buffer queue through an **OHNativeWindow** instance for content consumption.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| buffer | Pointer to an **OHNativeWindowBuffer** instance.|
| fenceFd | File descriptor handle, which is used for timing synchronization.|
| region | Dirty region where content is updated.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeWindow_NativeWindowHandleOpt()


```
int32_t OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow *  window, int code,  ... )
```

**Description**

Sets or obtains the attributes of an **OHNativeWindow**, including the width, height, and content format.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| code | Operation code. For details, see [NativeWindowOperation](#nativewindowoperation).|
| ... | Variable argument, which must correspond to the operation code.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeWindow_NativeWindowRequestBuffer()


```
int32_t OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow *  window, OHNativeWindowBuffer **  buffer, int * fenceFd )
```

**Description**

Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| buffer | Double pointer to an **OHNativeWindowBuffer** instance.|
| fenceFd | Pointer to a file descriptor handle.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeWindow_NativeWindowSetMetaData()


```
int32_t OH_NativeWindow_NativeWindowSetMetaData (OHNativeWindow *  window, uint32_t sequence, int32_t size, const OHHDRMetaData *  metaData )
```

**Description**

Sets metadata for an **OHNativeWindow**.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| sequence | Sequence of the producer buffer.|
| size | Size of the **OHHDRMetaData** array.|
| metaData| Pointer to the **OHHDRMetaData** array.|

**Returns**

Returns **0** if the operation is successful.

**Since**

9

**Deprecated**

This function is deprecated since API version 10. No substitute function is provided.


### OH_NativeWindow_NativeWindowSetMetaDataSet()


```
int32_t OH_NativeWindow_NativeWindowSetMetaDataSet (OHNativeWindow *  window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t * metaData )
```

**Description**

Sets a metadata set for an **OHNativeWindow**.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| sequence | Sequence of the producer buffer.|
| key | Metadata key. For details, see [OHHDRMetadataKey](#ohhdrmetadatakey).|
| size | Size of the uint8_t vector.|
| metaData| Pointer to the uint8_t vector.|

**Returns**

Returns **0** if the operation is successful.

**Since**

9

**Deprecated**

This function is deprecated since API version 10. No substitute function is provided.


### OH_NativeWindow_NativeWindowSetScalingMode()


```
int32_t OH_NativeWindow_NativeWindowSetScalingMode (OHNativeWindow *  window, uint32_t sequence, OHScalingMode scalingMode )
```

**Description**

Sets a scaling mode for an **OHNativeWindow**.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| sequence | Sequence of the producer buffer.|
| scalingMode | Scaling mode to set. For details, see [OHScalingMode](#ohscalingmode).|

**Returns**

Returns **0** if the operation is successful.

**Since**

9

**Deprecated**

This function is deprecated since API version 10. No substitute function is provided.


### OH_NativeWindow_NativeWindowSetTunnelHandle()


```
int32_t OH_NativeWindow_NativeWindowSetTunnelHandle (OHNativeWindow *  window, const OHExtDataHandle *  handle )
```

**Description**

Sets a tunnel handle to an **OHNativeWindow**.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Parameters**

| Name| Description|
| -------- | -------- |
| window | Pointer to an **OHNativeWindow** instance.|
| handle | Pointer to an [OHExtDataHandle](_o_h_ext_data_handle.md).|

**Returns**

Returns **0** if the operation is successful.

**Since**

9

**Deprecated**

This function is deprecated since API version 10. No substitute function is provided.

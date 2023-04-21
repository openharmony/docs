# NativeWindow


## Overview

Provides the native window capability for connection to the EGL.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**Since:**
8


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [external_window.h](external__window_8h.md) | Defines the functions for obtaining and using a native window. <br>File to Include: <native_window/external_window.h> | 


### Structs

| Name | Description | 
| -------- | -------- |
| [Region](_region.md) | Defines the rectangle (dirty region) where the content is to be updated in the local native window.  | 
| [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | Defines the HDR metadata.  | 
| [OHExtDataHandle](_o_h_ext_data_handle.md) | Defines the extended data handle.  | 


### Types

| Name | Description | 
| -------- | -------- |
| OHNativeWindow  | Provides the function of accessing the **NativeWindow**.  | 
| OHNativeWindowBuffer  | Provides the function of accessing the **NativeWindowBuffer**.  | 
| Region  | Defines the rectangle (dirty region) where the content is to be updated in the local native window.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| [NativeWindowOperation](#nativewindowoperation) {<br/>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,<br/>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br/>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br/>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br/>SET_UI_TIMESTAMP<br/>} | Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.  | 
| [OHScalingMode](#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | Enumerates the scaling modes.  | 
| [OHHDRMetadataKey](#ohhdrmetadatakey) {<br/>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br/>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br/>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br/>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br/>} | Enumerates the HDR metadata keys.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindow](#oh_nativewindow_createnativewindow) (void \*pSurface) | Creates a **NativeWindow** instance. A new **NativeWindow** instance is created each time this function is called.  | 
| [OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow) (OHNativeWindow \*window) | Decreases the reference count of a **NativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.  | 
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | Creates a **NativeWindowBuffer** instance. A new **NativeWindowBuffer** instance is created each time this function is called.  | 
| [OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer) (OHNativeWindowBuffer \*buffer) | Decreases the reference count of a **NativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.  | 
| [OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests a **NativeWindowBuffer** through a **NativeWindow** instance for content production.  | 
| [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, [Region](_region.md) region) | Flushes the **NativeWindowBuffer** filled with the content to the buffer queue through a **NativeWindow** instance for content consumption.  | 
| [OH_NativeWindow_NativeWindowAbortBuffer](#oh_nativewindow_nativewindowabortbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer) | Returns the **NativeWindowBuffer** to the buffer queue through a **NativeWindow** instance, without filling in any content. The **NativeWindowBuffer** can be used for another request.  | 
| [OH_NativeWindow_NativeWindowHandleOpt](#oh_nativewindow_nativewindowhandleopt) (OHNativeWindow \*window, int code,...) | Sets or obtains the attributes of a native window, including the width, height, and content format.  | 
| [OH_NativeWindow_GetBufferHandleFromNative](#oh_nativewindow_getbufferhandlefromnative) (OHNativeWindowBuffer \*buffer) | Obtains the pointer to a **BufferHandle** of a **NativeWindowBuffer** instance.  | 
| [OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference) (void \*obj) | Adds the reference count of a native object.  | 
| [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference) (void \*obj) | Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.  | 
| [OH_NativeWindow_GetNativeObjectMagic](#oh_nativewindow_getnativeobjectmagic) (void \*obj) | Obtains the magic ID of a native object.  | 
| [OH_NativeWindow_NativeWindowSetScalingMode](#oh_nativewindow_nativewindowsetscalingmode) (OHNativeWindow \*window, uint32_t sequence, [OHScalingMode](#ohscalingmode) scalingMode) | Sets the scaling mode for a native window.  | 
| [OH_NativeWindow_NativeWindowSetMetaData](#oh_nativewindow_nativewindowsetmetadata) (OHNativeWindow \*window, uint32_t sequence, int32_t size, const [OHHDRMetaData](_o_h_h_d_r_meta_data.md) \*metaData) | Sets the metadata for a native window.  | 
| [OH_NativeWindow_NativeWindowSetMetaDataSet](#oh_nativewindow_nativewindowsetmetadataset) (OHNativeWindow \*window, uint32_t sequence, [OHHDRMetadataKey](#ohhdrmetadatakey) key, int32_t size, const uint8_t \*metaData) | Sets the metadata set for a native window.  | 
| [OH_NativeWindow_NativeWindowSetTunnelHandle](#oh_nativewindow_nativewindowsettunnelhandle) (OHNativeWindow \*window, const [OHExtDataHandle](_o_h_ext_data_handle.md) \*handle) | Sets a tunnel handle for a native window.  | 


## Enum Description


### NativeWindowOperation

  
```
enum NativeWindowOperation
```
**Description**<br>
Enumerates the operation codes in the **OH_NativeWindow_NativeWindowHandleOpt** function.

| Name | Description | 
| -------- | -------- |
| SET_BUFFER_GEOMETRY  | Setting the geometry for the local window buffer. Variable arguments in the function: [Input] int32_t height and [Input] int32_t width. | 
| GET_BUFFER_GEOMETRY  | Obtaining the geometry of the local window buffer. Variable arguments in the function: [Output] int32_t \*height and [Output] int32_t \*width. | 
| GET_FORMAT  | Obtaining the format of the local window buffer. Variable argument in the function: [Output] int32_t \*format. | 
| SET_FORMAT  | Setting the format for the local window buffer. Variable argument in the function: [Input] int32_t format. | 
| GET_USAGE  | Obtaining the usage mode of the local window buffer. Variable argument in the function: [Output] int32_t \*usage. | 
| SET_USAGE  | Setting the usage mode for the local window buffer. Variable argument in the function: [Input] int32_t usage. | 
| SET_STRIDE  | Setting the stride for the local window buffer. Variable argument in the function: [Input] int32_t stride. | 
| GET_STRIDE  | Obtaining the stride of the local window buffer. Variable argument in the function: [Output] int32_t \*stride. | 
| SET_SWAP_INTERVAL  | Setting the swap interval for the local window buffer. Variable argument in the function: [Input] int32_t interval. | 
| GET_SWAP_INTERVAL  | Obtaining the swap interval of the local window buffer. Variable argument in the function: [Output] int32_t \*interval. | 
| SET_TIMEOUT  | Setting the timeout duration for requesting the local window buffer. Variable argument in the function: [Input] int32_t timeout. | 
| GET_TIMEOUT  | Obtaining the timeout duration for requesting the local window buffer. Variable argument in the function: [Output] int32_t \*timeout. | 
| SET_COLOR_GAMUT  | Setting the color gamut for the local window buffer. Variable argument in the function: [Input] int32_t colorGamut. | 
| GET_COLOR_GAMUT  | Obtaining the color gamut of the local window buffer. Variable argument in the function: [out int32_t \*colorGamut]. | 
| SET_TRANSFORM  | Setting the transform for the local window buffer. Variable argument in the function: [Input] int32_t transform. | 
| GET_TRANSFORM  | Obtaining the transform of the local window buffer. Variable argument in the function: [Output] int32_t \*transform. | 
| SET_UI_TIMESTAMP  | Setting the UI timestamp for the local window buffer. Variable argument in the function: [Input] uint64_t uiTimestamp. | 


### OHHDRMetadataKey

  
```
enum OHHDRMetadataKey
```
**Description**<br>
Enumerates the HDR metadata keys.

| Name | Description | 
| -------- | -------- |
| OH_METAKEY_RED_PRIMARY_X  | X coordinate of the red primary color. | 
| OH_METAKEY_RED_PRIMARY_Y  | Y coordinate of the red primary color. | 
| OH_METAKEY_GREEN_PRIMARY_X  | X coordinate of the green primary color. | 
| OH_METAKEY_GREEN_PRIMARY_Y  | Y coordinate of the green primary color. | 
| OH_METAKEY_BLUE_PRIMARY_X  | X coordinate of the blue primary color. | 
| OH_METAKEY_BLUE_PRIMARY_Y  | Y coordinate of the blue primary color. | 
| OH_METAKEY_WHITE_PRIMARY_X  | X coordinate of the white point. | 
| OH_METAKEY_WHITE_PRIMARY_Y  | Y coordinate of the white point. | 
| OH_METAKEY_MAX_LUMINANCE  | Maximum luminance. | 
| OH_METAKEY_MIN_LUMINANCE  | Minimum luminance. | 
| OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL  | Maximum content light level (MaxCLL). | 
| OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL  | Maximum frame average light level (MaxFALLL). | 
| OH_METAKEY_HDR10_PLUS  | HDR10+. | 
| OH_METAKEY_HDR_VIVID  | Vivid. | 


### OHScalingMode

  
```
enum OHScalingMode
```
**Description**<br>
Enumerates the scaling modes.

| Name | Description | 
| -------- | -------- |
| OH_SCALING_MODE_FREEZE  | The window content cannot be updated before the buffer of the window size is received. | 
| OH_SCALING_MODE_SCALE_TO_WINDOW  | The buffer is scaled in two dimensions to match the window size. | 
| OH_SCALING_MODE_SCALE_CROP  | The buffer is scaled uniformly so that its smaller size can match the window size. | 
| OH_SCALING_MODE_NO_SCALE_CROP  | The window is cropped to the size of the buffer's cropping rectangle. Pixels outside the cropping rectangle are considered completely transparent. | 


## Function Description


### OH_NativeWindow_CreateNativeWindow()

  
```
OHNativeWindow* OH_NativeWindow_CreateNativeWindow (void * pSurface)
```
**Description**<br>
Creates a **NativeWindow** instance. A new **NativeWindow** instance is created each time this function is called.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| pSurface | Indicates the pointer to a **ProduceSurface**. The type is **sptr&lt;OHOS::Surface&gt;**.  | 

**Returns**

Returns the pointer to the **NativeWindow** instance created.


### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()

  
```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void * pSurfaceBuffer)
```
**Description**<br>
Creates a **NativeWindowBuffer** instance. A new **NativeWindowBuffer** instance is created each time this function is called.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| pSurfaceBuffer | Indicates the pointer to a produce buffer. The type is **sptr&lt;OHOS::SurfaceBuffer&gt;**.  | 

**Returns**

Returns the pointer to the **NativeWindowBuffer** instance created.


### OH_NativeWindow_DestroyNativeWindow()

  
```
void OH_NativeWindow_DestroyNativeWindow (OHNativeWindow * window)
```
**Description**<br>
Decreases the reference count of a **NativeWindow** instance by 1 and when the reference count reaches 0, destroys the instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 


### OH_NativeWindow_DestroyNativeWindowBuffer()

  
```
void OH_NativeWindow_DestroyNativeWindowBuffer (OHNativeWindowBuffer * buffer)
```
**Description**<br>
Decreases the reference count of a **NativeWindowBuffer** instance by 1 and when the reference count reaches 0, destroys the instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| buffer | Indicates the pointer to a **NativeWindowBuffer** instance.  | 


### OH_NativeWindow_GetBufferHandleFromNative()

  
```
BufferHandle* OH_NativeWindow_GetBufferHandleFromNative (OHNativeWindowBuffer * buffer)
```
**Description**<br>
Obtains the pointer to a **BufferHandle** of a **NativeWindowBuffer** instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| buffer | Indicates the pointer to a **NativeWindowBuffer** instance.  | 

**Returns**

Returns the pointer to the **BufferHandle** instance obtained.


### OH_NativeWindow_GetNativeObjectMagic()

  
```
int32_t OH_NativeWindow_GetNativeObjectMagic (void * obj)
```
**Description**<br>
Obtains the magic ID of a native object.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| obj | Indicates the pointer to a **NativeWindow** or **NativeWindowBuffer** instance.  | 

**Returns**

Returns the magic ID, which is unique for each native object.


### OH_NativeWindow_NativeObjectReference()

  
```
int32_t OH_NativeWindow_NativeObjectReference (void * obj)
```
**Description**<br>
Adds the reference count of a native object.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| obj | Indicates the pointer to a **NativeWindow** or **NativeWindowBuffer** instance.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeObjectUnreference()

  
```
int32_t OH_NativeWindow_NativeObjectUnreference (void * obj)
```
**Description**<br>
Decreases the reference count of a native object and when the reference count reaches 0, destroys this object.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| obj | Indicates the pointer to a **NativeWindow** or **NativeWindowBuffer** instance.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowAbortBuffer()

  
```
int32_t OH_NativeWindow_NativeWindowAbortBuffer (OHNativeWindow * window, OHNativeWindowBuffer * buffer )
```
**Description**<br>
Returns the **NativeWindowBuffer** to the buffer queue through a **NativeWindow** instance, without filling in any content. The **NativeWindowBuffer** can be used for another request.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| buffer | Indicates the pointer to a **NativeWindowBuffer** instance.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowFlushBuffer()

  
```
int32_t OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow * window, OHNativeWindowBuffer * buffer, int fenceFd, Region region )
```
**Description**<br>
Flushes the **NativeWindowBuffer** filled with the content to the buffer queue through a **NativeWindow** instance for content consumption.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| buffer | Indicates the pointer to a **NativeWindowBuffer** instance.  | 
| fenceFd | Indicates a file descriptor handle, which is used for timing synchronization.  | 
| region | Indicates a dirty region where content is updated.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowHandleOpt()

  
```
int32_t OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow * window, int code,  ... )
```
**Description**<br>
Sets or obtains the attributes of a native window, including the width, height, and content format.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| code | Indicates the operation code. For details, see [NativeWindowOperation](#nativewindowoperation).  | 
| ... | Indicates the variable argument, which must correspond to the operation code.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowRequestBuffer()

  
```
int32_t OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow * window, OHNativeWindowBuffer ** buffer, int * fenceFd )
```
**Description**<br>
Requests a **NativeWindowBuffer** through a **NativeWindow** instance for content production.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| buffer | Indicates the double pointer to a **NativeWindowBuffer** instance.  | 
| fenceFd | Indicates the pointer to a file descriptor handle.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowSetMetaData()

  
```
int32_t OH_NativeWindow_NativeWindowSetMetaData (OHNativeWindow * window, uint32_t sequence, int32_t size, const OHHDRMetaData * metaData )
```
**Description**<br>
Sets the metadata for a native window.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| sequence | Indicates the sequence of the producer buffer.  | 
| size | Indicates the size of the **[OHHDRMetaData](_o_h_h_d_r_meta_data.md)** array.  | 
| metaData | Indicates the pointer to the **[OHHDRMetaData](_o_h_h_d_r_meta_data.md)** array.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowSetMetaDataSet()

  
```
int32_t OH_NativeWindow_NativeWindowSetMetaDataSet (OHNativeWindow * window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t * metaData )
```
**Description**<br>
Sets the metadata set for a native window.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| sequence | Indicates the sequence of the producer buffer.  | 
| key | Indicates a metadata key. For details, see **OHHDRMetadataKey**.  | 
| size | Indicates the size of the uint8_t vector.  | 
| metaData | Indicates the pointer to the uint8_t vector.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowSetScalingMode()

  
```
int32_t OH_NativeWindow_NativeWindowSetScalingMode (OHNativeWindow * window, uint32_t sequence, OHScalingMode scalingMode )
```
**Description**<br>
Sets the scaling mode for a native window.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| sequence | Indicates the sequence of the producer buffer.  | 
| scalingMode | Indicates the scaling mode to set. For details, see **OHScalingMode**.  | 

**Returns**

Returns an error code defined in **GSError**.


### OH_NativeWindow_NativeWindowSetTunnelHandle()

  
```
int32_t OH_NativeWindow_NativeWindowSetTunnelHandle (OHNativeWindow * window, const OHExtDataHandle * handle )
```
**Description**<br>
Sets a tunnel handle for a native window.

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

 **Parameters**

| Name | Description | 
| -------- | -------- |
| window | Indicates the pointer to a **NativeWindow** instance.  | 
| handle | Indicates the pointer to an **[OHExtDataHandle](_o_h_ext_data_handle.md)**.  | 

**Returns**

Returns an error code defined in **GSError**.

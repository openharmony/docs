# external_window.h


## 概述

定义获取和使用NativeWindow的相关函数。

**引用文件：**&lt;native_window/external_window.h&gt;

**库：** libnative_window.so

**起始版本：** 8

**相关模块：**[NativeWindow](_native_window.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Region](_region.md) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。 | 
| struct  [Region::Rect](_rect.md) | 矩形区域。 | 
| struct  [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | HDR元数据结构体定义。 | 
| struct  [OHExtDataHandle](_o_h_ext_data_handle.md) | 扩展数据句柄结构体定义。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OHIPCParcel](_native_window.md#ohipcparcel)  [OHIPCParcel](_native_window.md#ohipcparcel) | 提供对IPC序列化对象的访问功能。 | 
| typedef struct NativeWindow [OHNativeWindow](_native_window.md#ohnativewindow) | 提供对OHNativeWindow的访问功能。 | 
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) | 提供对OHNativeWindowBuffer的访问功能。 | 
| typedef struct [Region](_region.md)  [Region](_native_window.md#region) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。 | 
| typedef enum [OHNativeErrorCode](_native_window.md#ohnativeerrorcode)  [OHNativeErrorCode](_native_window.md#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 
| typedef enum [NativeWindowOperation](_native_window.md#nativewindowoperation)  [NativeWindowOperation](_native_window.md#nativewindowoperation) | OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。  | 
| typedef enum [OHScalingModeV2](_native_window.md#ohscalingmodev2)  [OHScalingModeV2](_native_window.md#ohscalingmodev2) | 渲染缩放模式枚举。 | 
| typedef enum [OHSurfaceSource](_native_window.md#ohsurfacesource)  [OHSurfaceSource](_native_window.md#ohsurfacesource) | 本地窗口内容来源类型枚举。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeErrorCode](_native_window.md#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000,NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 
| [NativeWindowOperation](_native_window.md#nativewindowoperation-1) {<br/>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT],<br/>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br/>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br/>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br/>SET_UI_TIMESTAMP, GET_BUFFERQUEUE_SIZE, SET_SOURCE_TYPE, GET_SOURCE_TYPE,<br/>SET_APP_FRAMEWORK_TYPE, GET_APP_FRAMEWORK_TYPE, SET_HDR_WHITE_POINT_BRIGHTNESS, SET_SDR_WHITE_POINT_BRIGHTNESS,<br/>SET_DESIRED_PRESENT_TIMESTAMP = 24<br/>} | OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。 |
| [OHScalingMode](_native_window.md#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | 缩放模式 Scaling Mode。 | 
| [OHScalingModeV2](_native_window.md#ohscalingmodev2-1) {<br/>OH_SCALING_MODE_FREEZE_V2 = 0, OH_SCALING_MODE_SCALE_TO_WINDOW_V2, OH_SCALING_MODE_SCALE_CROP_V2, OH_SCALING_MODE_NO_SCALE_CROP_V2,<br/>OH_SCALING_MODE_SCALE_FIT_V2<br/>} | 渲染缩放模式枚举。 | 
| [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) {<br/>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br/>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br/>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br/>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br/>} | 枚举HDR元数据关键字。 | 
| [OHSurfaceSource](_native_window.md#ohsurfacesource-1) {<br/>OH_SURFACE_SOURCE_DEFAULT = 0, OH_SURFACE_SOURCE_UI, OH_SURFACE_SOURCE_GAME, OH_SURFACE_SOURCE_CAMERA,OH_SURFACE_SOURCE_VIDEO<br/>} | 本地窗口内容来源类型枚举。 | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeWindow](_native_window.md#ohnativewindow) \* [OH_NativeWindow_CreateNativeWindow](_native_window.md#oh_nativewindow_createnativewindow) (void \*pSurface) | 创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例。 说明：此接口不可用，可通过**OH_NativeImage_AcquireNativeWindow**创建，或通过XComponent创建。 | 
| void [OH_NativeWindow_DestroyNativeWindow](_native_window.md#oh_nativewindow_destroynativewindow) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window) | 将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉。 | 
| [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。 此接口从API version 12开始废弃，使用[OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromnativebuffer)替代。 | 
| [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromnativebuffer) (OH_NativeBuffer \*nativeBuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。 | 
| void [OH_NativeWindow_DestroyNativeWindowBuffer](_native_window.md#oh_nativewindow_destroynativewindowbuffer) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉。 | 
| int32_t [OH_NativeWindow_NativeWindowRequestBuffer](_native_window.md#oh_nativewindow_nativewindowrequestbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*buffer, int \*fenceFd) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。 | 
| int32_t [OH_NativeWindow_NativeWindowFlushBuffer](_native_window.md#oh_nativewindow_nativewindowflushbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer, int fenceFd, [Region](_region.md) region) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。 | 
| int32_t [OH_NativeWindow_GetLastFlushedBuffer](_native_window.md#oh_nativewindow_getlastflushedbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*buffer, int \*fenceFd, float matrix[16]) | 从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer。 | 
| int32_t [OH_NativeWindow_NativeWindowAbortBuffer](_native_window.md#oh_nativewindow_nativewindowabortbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请。 | 
| int32_t [OH_NativeWindow_NativeWindowHandleOpt](_native_window.md#oh_nativewindow_nativewindowhandleopt) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, int code,...) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。 | 
| BufferHandle \* [OH_NativeWindow_GetBufferHandleFromNative](_native_window.md#oh_nativewindow_getbufferhandlefromnative) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 通过OHNativeWindowBuffer获取该buffer的BufferHandle指针。 | 
| int32_t [OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference) (void \*obj) | 增加一个NativeObject的引用计数。 | 
| int32_t [OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference) (void \*obj) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉。 | 
| int32_t [OH_NativeWindow_GetNativeObjectMagic](_native_window.md#oh_nativewindow_getnativeobjectmagic) (void \*obj) | 获取NativeObject的MagicId。 | 
| int32_t [OH_NativeWindow_NativeWindowSetScalingMode](_native_window.md#oh_nativewindow_nativewindowsetscalingmode) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHScalingMode](_native_window.md#ohscalingmode) scalingMode) | 设置OHNativeWindow的ScalingMode。 | 
| int32_t [OH_NativeWindow_NativeWindowSetMetaData](_native_window.md#oh_nativewindow_nativewindowsetmetadata) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, int32_t size, const [OHHDRMetaData](_o_h_h_d_r_meta_data.md) \*metaData) | 设置OHNativeWindow的元数据。 | 
| int32_t [OH_NativeWindow_NativeWindowSetMetaDataSet](_native_window.md#oh_nativewindow_nativewindowsetmetadataset) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) key, int32_t size, const uint8_t \*metaData) | 设置OHNativeWindow的元数据集。 | 
| int32_t [OH_NativeWindow_NativeWindowSetTunnelHandle](_native_window.md#oh_nativewindow_nativewindowsettunnelhandle) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, const [OHExtDataHandle](_o_h_ext_data_handle.md) \*handle) | 设置OHNativeWindow的TunnelHandle。 | 
| int32_t [OH_NativeWindow_NativeWindowAttachBuffer](_native_window.md#oh_nativewindow_nativewindowattachbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 将OHNativeWindowBuffer添加进OHNativeWindow中。 | 
| int32_t [OH_NativeWindow_NativeWindowDetachBuffer](_native_window.md#oh_nativewindow_nativewindowdetachbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 将OHNativeWindowBuffer从OHNativeWindow中分离。 |
| int32_t [OH_NativeWindow_GetSurfaceId](_native_window.md#oh_nativewindow_getsurfaceid) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint64_t \*surfaceId) | 通过OHNativeWindow获取对应的surfaceId。 | 
| int32_t [OH_NativeWindow_CreateNativeWindowFromSurfaceId](_native_window.md#oh_nativewindow_createnativewindowfromsurfaceid) (uint64_t surfaceId, [OHNativeWindow](_native_window.md#ohnativewindow) \*\*window) | 通过surfaceId创建对应的OHNativeWindow。 | 
| int32_t [OH_NativeWindow_NativeWindowSetScalingModeV2](_native_window.md#oh_nativewindow_nativewindowsetscalingmodev2) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHScalingModeV2](_native_window.md#ohscalingmodev2) scalingMode) | 设置OHNativeWindow的渲染缩放模式。 |
| int32_t [OH_NativeWindow_GetLastFlushedBufferV2](_native_window.md#oh_nativewindow_getlastflushedbufferv2) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*buffer, int \*fenceFd, float matrix[16]) | 从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer, 与OH_NativeWindow_GetLastFlushedBuffer的差异在于matrix不同。  | 
| void [OH_NativeWindow_SetBufferHold](_native_window.md#oh_nativewindow_setbufferhold) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window) | 提前缓存一帧buffer，且缓存的这一帧延迟一帧上屏显示，以此抵消后续一次超长帧丢帧。  |
| int32_t [OH_NativeWindow_WriteToParcel](_native_window.md#oh_nativewindow_writetoparcel) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHIPCParcel](_native_window.md#ohipcparcel) \*parcel) | 将窗口对象写入IPC序列化对象中。 | 
| int32_t [OH_NativeWindow_ReadFromParcel](_native_window.md#oh_nativewindow_readfromparcel) ([OHIPCParcel](_native_window.md#ohipcparcel) \*parcel, [OHNativeWindow](_native_window.md#ohnativewindow) \*\*window) | 从IPC序列化对象中读取窗口对象。 |
| int32_t [OH_NativeWindow_SetColorSpace](_native_window.md#oh_nativewindow_setcolorspace) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) colorSpace) | 为OHNativeWindow设置颜色空间属性。 | 
| int32_t [OH_NativeWindow_GetColorSpace](_native_window.md#oh_nativewindow_getcolorspace) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) \*colorSpace) | 获取OHNativeWindow颜色空间属性。 | 
| int32_t [OH_NativeWindow_SetMetadataValue](_native_window.md#oh_nativewindow_setmetadatavalue) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t size, uint8_t \*metaData) | 为OHNativeWindow设置元数据属性值。 | 
| int32_t [OH_NativeWindow_GetMetadataValue](_native_window.md#oh_nativewindow_getmetadatavalue) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t \*size, uint8_t \*\*metaData) | 获取OHNativeWindow元数据属性值。 |   
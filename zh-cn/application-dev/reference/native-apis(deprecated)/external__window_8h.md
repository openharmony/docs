# external_window.h


## 概述

定义获取和使用NativeWindow的相关函数

**库：** libnative_window.so

**起始版本：** 8

**相关模块：**[NativeWindow](_native_window.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Region](_region.md) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区） |
| [Region::Rect](_rect.md) | 矩形区域 |
| [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | HDR元数据结构体定义 |
| [OHExtDataHandle](_o_h_ext_data_handle.md) | 扩展数据句柄结构体定义 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OHNativeWindow](_native_window.md#ohnativewindow) | 提供对OHNativeWindow的访问功能 |
| [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) | 提供对OHNativeWindowBuffer的访问功能 |
| [Region](_native_window.md#region) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区） |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [NativeWindowOperation](_native_window.md#nativewindowoperation) {<br/>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,<br/>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br/>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br/>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br/>SET_UI_TIMESTAMP<br/>} | OH_NativeWindow_NativeWindowHandleOpt函数中的操作码 |
| [OHScalingMode](_native_window.md#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | 缩放模式 Scaling Mode |
| [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) {<br/>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br/>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br/>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br/>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br/>} | 枚举HDR元数据关键字 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindow](_native_window.md#oh_nativewindow_createnativewindow) (void \*pSurface) | 创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例 |
| [OH_NativeWindow_DestroyNativeWindow](_native_window.md#oh_nativewindow_destroynativewindow) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window) | 将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉 |
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例 |
| [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](_native_window.md#oh_nativewindow_createnativewindowbufferfromnativebuffer) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*nativeBuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例 |
| [OH_NativeWindow_DestroyNativeWindowBuffer](_native_window.md#oh_nativewindow_destroynativewindowbuffer) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉 |
| [OH_NativeWindow_NativeWindowRequestBuffer](_native_window.md#oh_nativewindow_nativewindowrequestbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*\*buffer, int \*fenceFd) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产 |
| [OH_NativeWindow_NativeWindowFlushBuffer](_native_window.md#oh_nativewindow_nativewindowflushbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer, int fenceFd, [Region](_region.md) region) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费 |
| [OH_NativeWindow_GetLastFlushedBuffer](_native_window.md#oh_nativewindow_getlastflushedbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \**buffer, int \*fenceFd, float matrix[16]) | 从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer |
| [OH_NativeWindow_NativeWindowAbortBuffer](_native_window.md#oh_nativewindow_nativewindowabortbuffer) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, [OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请 |
| [OH_NativeWindow_NativeWindowHandleOpt](_native_window.md#oh_nativewindow_nativewindowhandleopt) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, int code,...) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等 |
| [OH_NativeWindow_GetBufferHandleFromNative](_native_window.md#oh_nativewindow_getbufferhandlefromnative) ([OHNativeWindowBuffer](_native_window.md#ohnativewindowbuffer) \*buffer) | 通过OHNativeWindowBuffer获取该buffer的BufferHandle指针 |
| [OH_NativeWindow_NativeObjectReference](_native_window.md#oh_nativewindow_nativeobjectreference) (void \*obj) | 增加一个NativeObject的引用计数 |
| [OH_NativeWindow_NativeObjectUnreference](_native_window.md#oh_nativewindow_nativeobjectunreference) (void \*obj) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉 |
| [OH_NativeWindow_GetNativeObjectMagic](_native_window.md#oh_nativewindow_getnativeobjectmagic) (void \*obj) | 获取NativeObject的MagicId |
| [OH_NativeWindow_NativeWindowSetScalingMode](_native_window.md#oh_nativewindow_nativewindowsetscalingmode) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHScalingMode](_native_window.md#ohscalingmode) scalingMode) | 设置OHNativeWindow的ScalingMode |
| [OH_NativeWindow_NativeWindowSetMetaData](_native_window.md#oh_nativewindow_nativewindowsetmetadata) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, int32_t size, const [OHHDRMetaData](_o_h_h_d_r_meta_data.md) \*metaData) | 设置OHNativeWindow的元数据 |
| [OH_NativeWindow_NativeWindowSetMetaDataSet](_native_window.md#oh_nativewindow_nativewindowsetmetadataset) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, uint32_t sequence, [OHHDRMetadataKey](_native_window.md#ohhdrmetadatakey) key, int32_t size, const uint8_t \*metaData) | 设置OHNativeWindow的元数据集。 |
| [OH_NativeWindow_NativeWindowSetTunnelHandle](_native_window.md#oh_nativewindow_nativewindowsettunnelhandle) ([OHNativeWindow](_native_window.md#ohnativewindow) \*window, const [OHExtDataHandle](_o_h_ext_data_handle.md) \*handle) | 设置OHNativeWindow的TunnelHandle。 |

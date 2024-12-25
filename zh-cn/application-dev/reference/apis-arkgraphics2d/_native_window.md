# NativeWindow


## 概述

提供NativeWindow功能，作为数据生产者，可用来和egl对接。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [external_window.h](external__window_8h.md) | 定义获取和使用NativeWindow的相关函数。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Region](_region.md) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。 | 
| struct  [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | HDR元数据结构体定义。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 
| struct  [OHExtDataHandle](_o_h_ext_data_handle.md) | 扩展数据句柄结构体定义。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OHIPCParcel](#ohipcparcel) [OHIPCParcel](#ohipcparcel) | 提供对IPC序列化对象的访问功能。 | 
| typedef struct NativeWindow [OHNativeWindow](#ohnativewindow) | 提供对OHNativeWindow的访问功能。 | 
| typedef struct NativeWindowBuffer [OHNativeWindowBuffer](#ohnativewindowbuffer) | 提供对OHNativeWindowBuffer的访问功能。 | 
| typedef struct [Region](_region.md)  [Region](#region) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。 | 
| typedef enum [OHNativeErrorCode](#ohnativeerrorcode)  [OHNativeErrorCode](#ohnativeerrorcode) | 接口错误码说明（仅用于查询）。  | 
| typedef enum [NativeWindowOperation](#nativewindowoperation)  [NativeWindowOperation](#nativewindowoperation) | OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。  | 
| typedef enum [OHScalingModeV2](#ohscalingmodev2)  [OHScalingModeV2](#ohscalingmodev2) | 渲染缩放模式枚举。  | 
| typedef enum [OHSurfaceSource](#ohsurfacesource)  [OHSurfaceSource](#ohsurfacesource) | 本地窗口内容来源类型枚举。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NativeWindowOperation](#nativewindowoperation-1) {<br/>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,<br/>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br/>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br/>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br/>SET_UI_TIMESTAMP, GET_BUFFERQUEUE_SIZE, SET_SOURCE_TYPE, GET_SOURCE_TYPE,<br/>SET_APP_FRAMEWORK_TYPE, GET_APP_FRAMEWORK_TYPE, SET_HDR_WHITE_POINT_BRIGHTNESS, SET_SDR_WHITE_POINT_BRIGHTNESS,<br/>SET_DESIRED_PRESENT_TIMESTAMP = 24<br/>} | OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。 |
| [OHScalingMode](#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | 缩放模式Scaling Mode。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 
| [OHScalingModeV2](#ohscalingmodev2-1) {<br/>OH_SCALING_MODE_FREEZE_V2 = 0, OH_SCALING_MODE_SCALE_TO_WINDOW_V2, OH_SCALING_MODE_SCALE_CROP_V2, OH_SCALING_MODE_NO_SCALE_CROP_V2,<br/>OH_SCALING_MODE_SCALE_FIT_V2<br/>} | 渲染缩放模式枚举。  | 
| [OHHDRMetadataKey](#ohhdrmetadatakey) {<br/>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br/>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br/>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br/>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br/>} | 枚举HDR元数据关键字。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 
| [OHNativeErrorCode](#ohnativeerrorcode-1) {<br/>NATIVE_ERROR_OK = 0, NATIVE_ERROR_MEM_OPERATION_ERROR = 30001000, NATIVE_ERROR_INVALID_ARGUMENTS = 40001000, NATIVE_ERROR_NO_PERMISSION = 40301000, NATIVE_ERROR_NO_BUFFER = 40601000,<br/>NATIVE_ERROR_NO_CONSUMER = 41202000, NATIVE_ERROR_NOT_INIT = 41203000, NATIVE_ERROR_CONSUMER_CONNECTED = 41206000, NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,<br/>NATIVE_ERROR_BUFFER_IN_CACHE = 41208000, NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000, NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000, NATIVE_ERROR_UNSUPPORTED = 50102000,<br/>NATIVE_ERROR_UNKNOWN = 50002000, NATIVE_ERROR_HDI_ERROR = 50007000,NATIVE_ERROR_BINDER_ERROR = 50401000,NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000, NATIVE_ERROR_EGL_API_FAILED = 60002000<br/>} | 接口错误码说明（仅用于查询）。  | 
| [OHSurfaceSource](#ohsurfacesource-1) {<br/>OH_SURFACE_SOURCE_DEFAULT = 0, OH_SURFACE_SOURCE_UI, OH_SURFACE_SOURCE_GAME, OH_SURFACE_SOURCE_CAMERA,OH_SURFACE_SOURCE_VIDEO<br/>} | 本地窗口内容来源类型枚举。 | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OHNativeWindow](#ohnativewindow) \* [OH_NativeWindow_CreateNativeWindow](#oh_nativewindow_createnativewindow) (void \*pSurface) | 创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例。 说明：此接口不可用，可通过**OH_NativeImage_AcquireNativeWindow**创建，或通过XComponent创建。 | 
| void [OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow) ([OHNativeWindow](#ohnativewindow) \*window) | 将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉。 | 
| [OHNativeWindowBuffer](#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。 此接口从API version 12开始废弃，使用[OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer)替代。 | 
| [OHNativeWindowBuffer](#ohnativewindowbuffer) \* [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer) (OH_NativeBuffer \*nativeBuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。 | 
| void [OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer) ([OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | 将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉。 | 
| int32_t [OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*\*buffer, int \*fenceFd) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。 | 
| int32_t [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer, int fenceFd, [Region](_region.md) region) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。 | 
| int32_t [OH_NativeWindow_GetLastFlushedBuffer](#oh_nativewindow_getlastflushedbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*\*buffer, int \*fenceFd, float matrix[16]) | 从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer。 | 
| int32_t [OH_NativeWindow_NativeWindowAbortBuffer](#oh_nativewindow_nativewindowabortbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | 通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请。 | 
| int32_t [OH_NativeWindow_NativeWindowHandleOpt](#oh_nativewindow_nativewindowhandleopt) ([OHNativeWindow](#ohnativewindow) \*window, int code,...) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。 | 
| BufferHandle \* [OH_NativeWindow_GetBufferHandleFromNative](#oh_nativewindow_getbufferhandlefromnative) ([OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | 通过OHNativeWindowBuffer获取该buffer的BufferHandle指针。 | 
| int32_t [OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference) (void \*obj) | 增加一个NativeObject的引用计数。 | 
| int32_t [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference) (void \*obj) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉。 | 
| int32_t [OH_NativeWindow_GetNativeObjectMagic](#oh_nativewindow_getnativeobjectmagic) (void \*obj) | 获取NativeObject的MagicId。 | 
| int32_t [OH_NativeWindow_NativeWindowSetScalingMode](#oh_nativewindow_nativewindowsetscalingmode) ([OHNativeWindow](#ohnativewindow) \*window, uint32_t sequence, [OHScalingMode](#ohscalingmode) scalingMode) | 设置OHNativeWindow的ScalingMode。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 
| int32_t [OH_NativeWindow_NativeWindowSetMetaData](#oh_nativewindow_nativewindowsetmetadata) ([OHNativeWindow](#ohnativewindow) \*window, uint32_t sequence, int32_t size, const [OHHDRMetaData](_o_h_h_d_r_meta_data.md) \*metaData) | 设置OHNativeWindow的元数据。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 
| int32_t [OH_NativeWindow_NativeWindowSetMetaDataSet](#oh_nativewindow_nativewindowsetmetadataset) ([OHNativeWindow](#ohnativewindow) \*window, uint32_t sequence, [OHHDRMetadataKey](#ohhdrmetadatakey) key, int32_t size, const uint8_t \*metaData) | 设置OHNativeWindow的元数据集。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 
| int32_t [OH_NativeWindow_NativeWindowSetTunnelHandle](#oh_nativewindow_nativewindowsettunnelhandle) ([OHNativeWindow](#ohnativewindow) \*window, const [OHExtDataHandle](_o_h_ext_data_handle.md) \*handle) | 设置OHNativeWindow的TunnelHandle。<br/>**弃用：** 从API version 10开始废弃，不再提供替代接口。 | 
| int32_t [OH_NativeWindow_NativeWindowAttachBuffer](#oh_nativewindow_nativewindowattachbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | 将OHNativeWindowBuffer添加进OHNativeWindow中。 | 
| int32_t [OH_NativeWindow_NativeWindowDetachBuffer](#oh_nativewindow_nativewindowdetachbuffer) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*buffer) | 将OHNativeWindowBuffer从OHNativeWindow中分离。 | 
| int32_t [OH_NativeWindow_GetSurfaceId](#oh_nativewindow_getsurfaceid) ([OHNativeWindow](#ohnativewindow) \*window, uint64_t \*surfaceId) | 通过OHNativeWindow获取对应的surfaceId。 | 
| int32_t [OH_NativeWindow_CreateNativeWindowFromSurfaceId](#oh_nativewindow_createnativewindowfromsurfaceid) (uint64_t surfaceId, [OHNativeWindow](#ohnativewindow) \*\*window) | 通过surfaceId创建对应的OHNativeWindow。 | 
| int32_t [OH_NativeWindow_NativeWindowSetScalingModeV2](#oh_nativewindow_nativewindowsetscalingmodev2)  ([OHNativeWindow](#ohnativewindow) \*window, [OHScalingModeV2](#ohscalingmodev2) scalingMode) | 设置OHNativeWindow的渲染缩放模式。  |
| int32_t [OH_NativeWindow_GetLastFlushedBufferV2](#oh_nativewindow_getlastflushedbufferv2) ([OHNativeWindow](#ohnativewindow) \*window, [OHNativeWindowBuffer](#ohnativewindowbuffer) \*\*buffer, int \*fenceFd, float matrix[16]) | 从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer, 与OH_NativeWindow_GetLastFlushedBuffer的差异在于matrix不同。  | 
| void [OH_NativeWindow_SetBufferHold](#oh_nativewindow_setbufferhold) ([OHNativeWindow](#ohnativewindow) \*window) | 提前缓存一帧buffer，且缓存的这一帧延迟一帧上屏显示，以此抵消后续一次超长帧丢帧。  | 
| int32_t [OH_NativeWindow_WriteToParcel](#oh_nativewindow_writetoparcel) ([OHNativeWindow](#ohnativewindow) \*window, [OHIPCParcel](#ohipcparcel) \*parcel) | 将窗口对象写入IPC序列化对象中。 | 
| int32_t [OH_NativeWindow_ReadFromParcel](#oh_nativewindow_readfromparcel) ([OHIPCParcel](#ohipcparcel) \*parcel, [OHNativeWindow](#ohnativewindow) \*\*window) | 从IPC序列化对象中读取窗口对象。 | 
| int32_t [OH_NativeWindow_SetColorSpace](#oh_nativewindow_setcolorspace) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) colorSpace) | 为OHNativeWindow设置颜色空间属性。 | 
| int32_t [OH_NativeWindow_GetColorSpace](#oh_nativewindow_getcolorspace) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) \*colorSpace) | 获取OHNativeWindow颜色空间属性。 | 
| int32_t [OH_NativeWindow_SetMetadataValue](#oh_nativewindow_setmetadatavalue) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t size, uint8_t \*metaData) | 为OHNativeWindow设置元数据属性值。 | 
| int32_t [OH_NativeWindow_GetMetadataValue](#oh_nativewindow_getmetadatavalue) ([OHNativeWindow](#ohnativewindow) \*window, [OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey) metadataKey, int32_t \*size, uint8_t \*\*metaData) | 获取OHNativeWindow元数据属性值。 | 

## 类型定义说明

### OHSurfaceSource

```
typedef enum OHSurfaceSource OHSurfaceSource
```

**描述**

本地窗口内容来源类型枚举。

**起始版本：** 12

### OHIPCParcel

```
typedef struct OHIPCParcel OHIPCParcel
```

**描述**

提供对IPC序列化对象的访问功能。

**起始版本：** 12

### NativeWindowOperation

```
typedef enum NativeWindowOperation NativeWindowOperation
```

**描述**

OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。

**起始版本：** 8

### OHNativeErrorCode

```
typedef enum OHNativeErrorCode OHNativeErrorCode
```

**描述**

接口错误码说明（仅用于查询）。

**起始版本：** 12


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**描述**

提供对OHNativeWindow的访问功能。

**起始版本：** 8


### OHNativeWindowBuffer

```
typedef struct NativeWindowBuffer OHNativeWindowBuffer
```

**描述**

提供对OHNativeWindowBuffer的访问功能。

**起始版本：** 8

### OHScalingModeV2

```
typedef enum OHScalingModeV2 OHScalingModeV2
```
**描述**

渲染缩放模式枚举。

**起始版本：** 12



### Region

```
typedef struct Region Region
```

**描述**

表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。

**起始版本：** 8


## 枚举类型说明

### OHSurfaceSource

```
enum OHSurfaceSource
```

**描述**

本地窗口内容来源类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SURFACE_SOURCE_DEFAULT | 窗口内容默认来源。 | 
| OH_SURFACE_SOURCE_UI | 窗口内容来自于UI。 |
| OH_SURFACE_SOURCE_GAME | 窗口内容来自于游戏。 |
| OH_SURFACE_SOURCE_CAMERA | 窗口内容来自于相机。 |
| OH_SURFACE_SOURCE_VIDEO | 窗口内容来自于视频。 |

### OHNativeErrorCode

```
enum OHNativeErrorCode
```
**描述**

接口错误码说明（仅用于查询）。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| NATIVE_ERROR_OK  | 成功   | 
| NATIVE_ERROR_MEM_OPERATION_ERROR<sup>14+</sup> | 内存操作错误 | 
| NATIVE_ERROR_INVALID_ARGUMENTS  | 入参无效   | 
| NATIVE_ERROR_NO_PERMISSION  | 无权限操作   | 
| NATIVE_ERROR_NO_BUFFER  | 无空闲可用的buffer   | 
| NATIVE_ERROR_NO_CONSUMER  | 消费端不存在   | 
| NATIVE_ERROR_NOT_INIT  | 未初始化   | 
| NATIVE_ERROR_CONSUMER_CONNECTED  | 消费端已经被连接   | 
| NATIVE_ERROR_BUFFER_STATE_INVALID  | buffer状态不符合预期   | 
| NATIVE_ERROR_BUFFER_IN_CACHE  | buffer已在缓存队列中   | 
| NATIVE_ERROR_BUFFER_QUEUE_FULL  | 队列已满   | 
| NATIVE_ERROR_BUFFER_NOT_IN_CACHE  | buffer不在缓存队列中   | 
| NATIVE_ERROR_CONSUMER_DISCONNECTED | 消费端已经被断开连接 |
| NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED | 消费端未注册listener回调函数 |
| NATIVE_ERROR_UNSUPPORTED  | 当前设备或平台不支持   | 
| NATIVE_ERROR_UNKNOWN  | 未知错误，请查看日志   | 
| NATIVE_ERROR_HDI_ERROR  | HDI接口调用失败   | 
| NATIVE_ERROR_BINDER_ERROR  | 跨进程通信失败   | 
| NATIVE_ERROR_EGL_STATE_UNKNOWN  | egl环境状态异常   | 
| NATIVE_ERROR_EGL_API_FAILED  | egl接口调用失败   | 


### NativeWindowOperation

```
enum NativeWindowOperation
```

**描述**

OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| SET_BUFFER_GEOMETRY | 设置本地窗口缓冲区几何图形， 函数中的可变参数是 [输入] int32_t width，[输入] int32_t height。 | 
| GET_BUFFER_GEOMETRY | 获取本地窗口缓冲区几何图形， 函数中的可变参数是 [输出] int32_t \*height， [输出] int32_t \*width。 | 
| GET_FORMAT | 获取本地窗口缓冲区格式， 函数中的可变参数是 [输出] int32_t \*format，取值具体可见[OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format-1)枚举值。 | 
| SET_FORMAT | 设置本地窗口缓冲区格式， 函数中的可变参数是 [输入] int32_t format，取值具体可见[OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format-1)枚举值。 | 
| GET_USAGE | 获取本地窗口读写方式， 函数中的可变参数是 [输出] uint64_t \*usage，取值具体可见[OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage-1)枚举值。 | 
| SET_USAGE | 设置本地窗口缓冲区读写方式， 函数中的可变参数是 [输入] uint64_t usage，取值具体可见[OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage-1)枚举值。 | 
| SET_STRIDE | 设置本地窗口缓冲区步幅， 函数中的可变参数是 [输入] int32_t stride，单位为Byte。 | 
| GET_STRIDE | 获取本地窗口缓冲区步幅， 函数中的可变参数是 [输出] int32_t \*stride，单位为Byte。 | 
| SET_SWAP_INTERVAL | 设置本地窗口缓冲区交换间隔， 函数中的可变参数是 [输入] int32_t interval。 | 
| GET_SWAP_INTERVAL | 获取本地窗口缓冲区交换间隔， 函数中的可变参数是 [输出] int32_t \*interval。 | 
| SET_TIMEOUT | 设置请求本地窗口请求缓冲区的超时等待时间，未手动设置时默认值为3000毫秒，函数中的可变参数是 [输入] int32_t timeout，单位为毫秒。 | 
| GET_TIMEOUT | 获取请求本地窗口请求缓冲区的超时等待时间，未手动设置时默认值为3000毫秒，函数中的可变参数是 [输出] int32_t \*timeout，单位为毫秒。 | 
| SET_COLOR_GAMUT | 设置本地窗口缓冲区色彩空间， 函数中的可变参数是 [输入] int32_t colorGamut，取值具体可见[OH_NativeBuffer_ColorGamut](_o_h___native_buffer.md#oh_nativebuffer_colorgamut-1)枚举值。 | 
| GET_COLOR_GAMUT | 获取本地窗口缓冲区色彩空间， 函数中的可变参数是 [out int32_t \*colorGamut]，取值具体可见[OH_NativeBuffer_ColorGamut](_o_h___native_buffer.md#oh_nativebuffer_colorgamut-1)枚举值。 | 
| SET_TRANSFORM | 设置本地窗口缓冲区变换， 函数中的可变参数是 [输入] int32_t transform，取值具体可见[OH_NativeBuffer_TransformType](_o_h___native_buffer.md#oh_nativebuffer_transformtype-1)枚举值。  | 
| GET_TRANSFORM | 获取本地窗口缓冲区变换， 函数中的可变参数是 [输出] int32_t \*transform，取值具体可见[OH_NativeBuffer_TransformType](_o_h___native_buffer.md#oh_nativebuffer_transformtype-1)枚举值。  | 
| SET_UI_TIMESTAMP | 设置本地窗口缓冲区UI时间戳， 函数中的可变参数是 [输入] uint64_t uiTimestamp。 | 
| GET_BUFFERQUEUE_SIZE<sup>12+</sup> | 获取内存队列大小, 函数中的可变参数是 [输出] int32_t \*size. | 
| SET_SOURCE_TYPE<sup>12+</sup> | 设置本地窗口内容来源, 函数中的可变参数是 [输入] int32_t sourceType， 取值具体可见[OHSurfaceSource](#ohsurfacesource)枚举值。 | 
| GET_SOURCE_TYPE<sup>12+</sup> | 获取本地窗口内容来源, 函数中的可变参数是 [输出] int32_t \*sourceType， 取值具体可见[OHSurfaceSource](#ohsurfacesource)枚举值。 | 
| SET_APP_FRAMEWORK_TYPE<sup>12+</sup> | 设置本地窗口应用框架名称, 函数中的可变参数是 [输入] char\* frameworkType， 最大支持64字节。 | 
| GET_APP_FRAMEWORK_TYPE<sup>12+</sup> | 获取本地窗口应用框架名称, 函数中的可变参数是 [输出] char\* frameworkType。 | 
| SET_HDR_WHITE_POINT_BRIGHTNESS<sup>12+</sup> | 设置HDR白点亮度, 函数中的可变参数是 [输入] float brightness. 取值范围为[0.0f, 1.0f]。 | 
| SET_SDR_WHITE_POINT_BRIGHTNESS<sup>12+</sup> | 设置SDR白点亮度, 函数中的可变参数是 [输入] float brightness. 取值范围为[0.0f, 1.0f]。 | 
| SET_DESIRED_PRESENT_TIMESTAMP<sup>13+</sup> | 设置本地窗口缓冲区期望上屏时间的时间戳。 当且仅当RenderService为本地窗口的消费者时，该时间戳生效。 本操作执行后需要配合调用[OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer)生效。 生产者下一次放入队列的buffer，达到该期望上屏时间后，才会被RenderService消费并上屏。 如果buffer队列中存在多个生产者放入的buffer，都设置了desiredPresentTimestamp并已达到期望上屏时间，则较早入队的buffer将被消费者丢弃回队列。 如果期望上屏时间大于消费者提供的时间 1 秒以上，则该期望上屏时间戳将被忽略。 函数中的可变参数是 [输入] int64_t desiredPresentTimestamp，取值范围大于0，应由std::chrono::steady_clock标准库时钟生成，且单位为纳秒。 | 

### OHHDRMetadataKey

```
enum OHHDRMetadataKey
```

**描述**

枚举HDR元数据关键字。

**起始版本：** 9

**弃用：** 从API version 10开始废弃，不再提供替代接口。

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_METAKEY_RED_PRIMARY_X | 红基色X坐标。 | 
| OH_METAKEY_RED_PRIMARY_Y | 红基色Y坐标。 | 
| OH_METAKEY_GREEN_PRIMARY_X | 绿基色X坐标。 | 
| OH_METAKEY_GREEN_PRIMARY_Y | 绿基色Y坐标。 | 
| OH_METAKEY_BLUE_PRIMARY_X | 蓝基色X坐标。 | 
| OH_METAKEY_BLUE_PRIMARY_Y | 蓝基色Y坐标。 | 
| OH_METAKEY_WHITE_PRIMARY_X | 白点X坐标。 | 
| OH_METAKEY_WHITE_PRIMARY_Y | 白点Y坐标。 | 
| OH_METAKEY_MAX_LUMINANCE | 最大的光亮度。 | 
| OH_METAKEY_MIN_LUMINANCE | 最小的光亮度。 | 
| OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL | 最大的内容亮度水平。 | 
| OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL | 最大的帧平均亮度水平。 | 
| OH_METAKEY_HDR10_PLUS | HDR10 Plus。 | 
| OH_METAKEY_HDR_VIVID | Vivid。 | 


### OHScalingMode

```
enum OHScalingMode
```

**描述**

缩放模式 Scaling Mode。

**起始版本：** 9

**弃用：** 从API version 10开始废弃，不再提供替代接口。

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SCALING_MODE_FREEZE | 在接收到窗口大小的缓冲区之前，不可以更新窗口内容。 | 
| OH_SCALING_MODE_SCALE_TO_WINDOW | 缓冲区在二维中缩放以匹配窗口大小。 | 
| OH_SCALING_MODE_SCALE_CROP | 缓冲区被统一缩放，使得缓冲区的较小尺寸与窗口大小匹配。 | 
| OH_SCALING_MODE_NO_SCALE_CROP | 窗口被裁剪为缓冲区裁剪矩形的大小，裁剪矩形之外的像素被视为完全透明。 | 


### OHScalingModeV2

```
enum OHScalingModeV2
```
**描述**
渲染缩放模式枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SCALING_MODE_FREEZE_V2  | 冻结窗口，在接收到和窗口大小相等的缓冲区之前，窗口内容不进行更新。 | 
| OH_SCALING_MODE_SCALE_TO_WINDOW_V2  | 缓冲区进行拉伸缩放以匹配窗口大小。| 
| OH_SCALING_MODE_SCALE_CROP_V2  | 缓冲区按原比例缩放，使得缓冲区的较小边与窗口匹配， 较长边超出窗口部分被视为透明。 | 
| OH_SCALING_MODE_NO_SCALE_CROP_V2  | 按窗口大小将缓冲区裁剪，裁剪矩形之外的像素被视为完全透明。 | 
| OH_SCALING_MODE_SCALE_FIT_V2  | 缓冲区按原比例缩放。优先显示所有缓冲区内容。 如果比例与窗口比例不同，用背景颜色填充窗口的未填充区域。<!--Del-->开发板和<!--DelEnd-->模拟器不支持该模式。| 


## 函数说明

### OH_NativeWindow_SetColorSpace()

```
int32_t OH_NativeWindow_SetColorSpace (OHNativeWindow *window, OH_NativeBuffer_ColorSpace colorSpace )
```

**描述**

为OHNativeWindow设置颜色空间属性。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个指向[OHNativeWindow](#ohnativewindow)的结构体实例的指针。 | 
| colorSpace | 为OHNativeWindow设置的颜色空间，其值从[OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace)获取。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode)。


### OH_NativeWindow_SetMetadataValue()

```
int32_t OH_NativeWindow_SetMetadataValue (OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey, int32_t size, uint8_t * metaData )
```

**描述**

为OHNativeWindow设置元数据属性值。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个指向[OHNativeWindow](#ohnativewindow)的结构体实例的指针。 | 
| metadataKey | OHNativeWindow的元数据类型，其值从[OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey)获取。 | 
| size | uint8_t向量的大小，其取值范围见[OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey)。 | 
| metaDate | 指向uint8_t向量的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode)。

### OH_NativeWindow_GetColorSpace()

```
int32_t OH_NativeWindow_GetColorSpace (OHNativeWindow *window, OH_NativeBuffer_ColorSpace *colorSpace )
```

**描述**

获取OHNativeWindow颜色空间属性。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个指向[OHNativeWindow](#ohnativewindow)的结构体实例的指针。 | 
| colorSpace | 为OHNativeWindow设置的颜色空间，其值从[OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace)获取。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode)。


### OH_NativeWindow_GetMetadataValue()

```
int32_t OH_NativeWindow_GetMetadataValue (OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey, int32_t *size, uint8_t **metaData )
```

**描述**

获取OHNativeWindow元数据属性值。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个指向[OHNativeWindow](#ohnativewindow)的结构体实例的指针。 | 
| metadataKey | OHNativeWindow的元数据类型，其值从[OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey)获取。 | 
| size | uint8_t向量的大小，其取值范围见[OH_NativeBuffer_MetadataKey](_o_h___native_buffer.md#oh_nativebuffer_metadatakey)。 | 
| metaDate | 指向uint8_t向量的二级指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](_o_h___native_buffer.md#ohnativeerrorcode)。


### OH_NativeWindow_WriteToParcel()

```
int32_t OH_NativeWindow_WriteToParcel (OHNativeWindow *window, OHIPCParcel *parcel )
```

**描述**

将窗口对象写入IPC序列化对象中。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个指向[OHNativeWindow](#ohnativewindow)的结构体实例的指针。 | 
| parcel | 一个指向[OHIPCParcel](#ohipcparcel)的结构体实例的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_ReadFromParcel()

```
int32_t OH_NativeWindow_ReadFromParcel (OHIPCParcel *parcel, OHNativeWindow **window )
```

**描述**

从IPC序列化对象中读取窗口对象。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | 一个指向[OHIPCParcel](#ohipcparcel)的结构体实例的指针。 | 
| window | 一个指向[OHNativeWindow](#ohnativewindow)的结构体实例的二级指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。



### OH_NativeWindow_GetLastFlushedBufferV2()

```
int32_t OH_NativeWindow_GetLastFlushedBufferV2 (OHNativeWindow *window, OHNativeWindowBuffer **buffer, int *fenceFd, float matrix[16] )
```

**描述**

从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer, 与OH_NativeWindow_GetLastFlushedBuffer的差异在于matrix不同。
本接口需要与OH_NativeWindow_NativeObjectUnreference接口配合使用，否则会存在内存泄露。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。  | 
| buffer | 一个OHNativeWindowBuffer结构体指针的指针。  | 
| fenceFd | 一个文件描述符的指针。  | 
| matrix | 表示检索到的4\*4变换矩阵。  | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。



### OH_NativeWindow_SetBufferHold()

```
void OH_NativeWindow_SetBufferHold (OHNativeWindow *window)
```
**描述**
提前缓存一帧buffer，且缓存的这一帧延迟一帧上屏显示，以此抵消后续一次超长帧丢帧。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个[OHNativeWindow](_o_h___native_image.md#ohnativewindow)的结构体实例的指针。  | 



### OH_NativeWindow_CreateNativeWindow()

```
OHNativeWindow* OH_NativeWindow_CreateNativeWindow (void* pSurface)
```

**描述**

创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例。 说明：此接口不可用，可通过**OH_NativeImage_AcquireNativeWindow**创建，或通过XComponent创建。

**废弃版本：** 12

**替代接口：** 不再提供替代接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pSurface | 一个指向生产者ProduceSurface的指针，类型为sptr&lt;OHOS::Surface&gt;。 | 

**返回：**

返回一个指针，指向OHNativeWindow的结构体实例。


### OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer (OH_NativeBuffer* nativeBuffer)
```

**描述**

创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。
本接口需要与OH_NativeWindow_DestroyNativeWindowBuffer接口配合使用，否则会存在内存泄露。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| nativeBuffer | 一个指向OH_NativeBuffer的指针。 | 

**返回：**

返回一个指针，指向OHNativeWindowBuffer的结构体实例。


### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void* pSurfaceBuffer)
```

**描述**

创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。

**废弃版本：** 12

**替代接口：** [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer)

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pSurfaceBuffer | 一个指向生产者buffer的指针，类型为sptr&lt;OHOS::SurfaceBuffer&gt;。 | 

**返回：**

返回一个指针，指向OHNativeWindowBuffer的结构体实例。


### OH_NativeWindow_CreateNativeWindowFromSurfaceId()

```
int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId (uint64_t surfaceId, OHNativeWindow **window )
```

**描述**

通过surfaceId创建对应的OHNativeWindow。
本接口需要与OH_NativeWindow_DestroyNativeWindow接口配合使用，否则会存在内存泄露。
如果存在并发释放OHNativeWindow的情况，需要通过OH_NativeWindow_NativeObjectReference和
OH_NativeWindow_NativeObjectUnreference对OHNativeWindow进行引用计数加一和减一。
通过surfaceId获取的surface需要是在本进程中创建的，不能跨进程获取surface。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| surfaceId | 一个surface对应的ID。 | 
| window | 一个OHNativeWindow的结构体实例的二级指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_DestroyNativeWindow()

```
void OH_NativeWindow_DestroyNativeWindow (OHNativeWindow* window)
```

**描述**

将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 


### OH_NativeWindow_DestroyNativeWindowBuffer()

```
void OH_NativeWindow_DestroyNativeWindowBuffer (OHNativeWindowBuffer* buffer)
```

**描述**

将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 | 


### OH_NativeWindow_GetBufferHandleFromNative()

```
BufferHandle* OH_NativeWindow_GetBufferHandleFromNative (OHNativeWindowBuffer* buffer)
```

**描述**

通过OHNativeWindowBuffer获取该buffer的BufferHandle指针。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 | 

**返回：**

BufferHandle 返回一个指针，指向BufferHandle的结构体实例。


### OH_NativeWindow_GetLastFlushedBuffer()

```
int32_t OH_NativeWindow_GetLastFlushedBuffer (OHNativeWindow *window, OHNativeWindowBuffer **buffer, int *fenceFd, float matrix[16] )
```

**描述**

从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer。

**废弃版本：** 12

**替代接口：** [OH_NativeWindow_GetLastFlushedBufferV2](#oh_nativewindow_getlastflushedbufferv2)

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| buffer | 一个OHNativeWindowBuffer结构体指针的指针。 | 
| fenceFd | 一个文件描述符的指针。 | 
| matrix | 表示检索到的4\*4变换矩阵。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_GetNativeObjectMagic()

```
int32_t OH_NativeWindow_GetNativeObjectMagic (void *obj)
```

**描述**

获取NativeObject的MagicId。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针。 | 

**返回：**

MagicId 返回值为魔鬼数字，每个NativeObject唯一。


### OH_NativeWindow_GetSurfaceId()

```
int32_t OH_NativeWindow_GetSurfaceId (OHNativeWindow *window, uint64_t *surfaceId )
```

**描述**

通过OHNativeWindow获取对应的surfaceId。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| surfaceId | 一个surface对应ID的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeObjectReference()

```
int32_t OH_NativeWindow_NativeObjectReference (void *obj)
```

**描述**

增加一个NativeObject的引用计数。
本接口需要与OH_NativeWindow_NativeObjectUnreference接口配合使用，否则会存在内存泄露。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeObjectUnreference()

```
int32_t OH_NativeWindow_NativeObjectUnreference (void *obj)
```

**描述**

减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowAbortBuffer()

```
int32_t OH_NativeWindow_NativeWindowAbortBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer )
```

**描述**

通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。

### OH_NativeWindow_NativeWindowAttachBuffer()

```
int32_t OH_NativeWindow_NativeWindowAttachBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer )
```

**描述**

将OHNativeWindowBuffer添加进OHNativeWindow中。
本接口需要与OH_NativeWindow_NativeWindowDetachBuffer接口配合使用，否则会存在内存管理混乱问题。
本接口为非线程安全类型接口

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowDetachBuffer()

```
int32_t OH_NativeWindow_NativeWindowDetachBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer )
```

**描述**

将OHNativeWindowBuffer从OHNativeWindow中分离。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowFlushBuffer()

```
int32_t OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow *window, OHNativeWindowBuffer *buffer, int fenceFd, Region region )
```

**描述**

通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。
系统会将fenFd关闭，无需用户close。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 | 
| fenceFd | 一个文件描述符句柄，用以同步时序。 | 
| region | 表示一块脏区域，该区域有内容更新。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowHandleOpt()

```
int32_t OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow *window, int code,  ... )
```

**描述**

设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| code | 表示操作码，详见[NativeWindowOperation](#nativewindowoperation)。 | 
| ... | 可变参数，必须与操作码对应的数据类型保持一致，且入参数量严格按照操作码提示传入，否则会存在未定义行为。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowRequestBuffer()

```
int32_t OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow *window, OHNativeWindowBuffer **buffer, int *fenceFd )
```

**描述**

通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。
在调用本接口前，需要通过SET_BUFFER_GEOMETRY对OHNativeWindow设置宽高。
本接口需要与OH_NativeWindow_NativeWindowFlushBuffer接口配合使用，否则内存会耗尽。
当fenceFd使用完，用户需要将其close。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| buffer | 一个OHNativeWindowBuffer的结构体实例的二级指针。 | 
| fenceFd | 一个文件描述符句柄。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowSetMetaData()

```
int32_t OH_NativeWindow_NativeWindowSetMetaData (OHNativeWindow *window, uint32_t sequence, int32_t size, const OHHDRMetaData *metaData )
```

**描述**

设置OHNativeWindow的元数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**弃用：** 从API version 10开始废弃，不再提供替代接口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| sequence | 生产缓冲区的序列。 | 
| size | OHHDRMetaData数组的大小。 | 
| metaDate | 指向OHHDRMetaData数组的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowSetMetaDataSet()

```
int32_t OH_NativeWindow_NativeWindowSetMetaDataSet (OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t *metaData )
```

**描述**

设置OHNativeWindow的元数据集。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**弃用：** 从API version 10开始废弃，不再提供替代接口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| sequence | 生产缓冲区的序列。 | 
| key | 枚举值OHHDRMetadataKey。 | 
| size | uint8_t向量的大小。 | 
| metaDate | 指向uint8_t向量的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowSetScalingMode()

```
int32_t OH_NativeWindow_NativeWindowSetScalingMode (OHNativeWindow *window, uint32_t sequence, OHScalingMode scalingMode )
```

**描述**

设置OHNativeWindow的ScalingMode。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**弃用：** 从API version 10开始废弃，不再提供替代接口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| sequence | 生产缓冲区的序列。 | 
| scalingMode | 枚举值OHScalingMode。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。


### OH_NativeWindow_NativeWindowSetScalingModeV2()

```
int32_t OH_NativeWindow_NativeWindowSetScalingModeV2 (OHNativeWindow* window, OHScalingModeV2 scalingMode )
```
**描述**
设置OHNativeWindow的渲染缩放模式。
本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。  | 
| scalingMode | 一个OHScalingModeV2类型的枚举值。  | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。

### OH_NativeWindow_NativeWindowSetTunnelHandle()

```
int32_t OH_NativeWindow_NativeWindowSetTunnelHandle (OHNativeWindow *window, const OHExtDataHandle *handle )
```

**描述**

设置OHNativeWindow的TunnelHandle。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**弃用：** 从API version 10开始废弃，不再提供替代接口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 | 
| handle | 指向OHExtDataHandle的指针。 | 

**返回：**

返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](#ohnativeerrorcode)。

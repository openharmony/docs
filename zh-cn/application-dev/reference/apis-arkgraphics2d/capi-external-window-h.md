# external_window.h

## 概述

定义获取和使用NativeWindow的相关函数。

<!--RP1-->
**相关示例：** [NDKNativeWindow](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeWindow)<!--RP1End-->

**引用文件：** <native_window/external_window.h>

**库：** libnative_window.so

**起始版本：** 8

**相关模块：** [NativeWindow](capi-nativewindow.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Region](capi-region.md) | Region | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。 |
| [Rect](capi-rect.md) | - | 如果rects是空指针nullptr，默认Buffer大小为脏区。 |
| [OHHDRMetaData](capi-ohhdrmetadata.md) | OHHDRMetaData | HDR元数据结构体定义。 |
| [OHExtDataHandle](capi-ohextdatahandle.md) | OHExtDataHandle | 扩展数据句柄结构体定义。 |
| [OHIPCParcel](capi-ohipcparcel.md) | OHIPCParcel | 提供对IPC序列化对象的访问功能。 |
| [NativeWindow](capi-nativewindow.md) | OHNativeWindow | 提供对OHNativeWindow的访问功能。 |
| [NativeWindowBuffer](capi-nativewindowbuffer.md) | OHNativeWindowBuffer | 提供对OHNativeWindowBuffer的访问功能。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [NativeWindowOperation](#nativewindowoperation) | NativeWindowOperation | OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。 |
| [OHScalingMode](#ohscalingmode) | OHScalingMode | 缩放模式Scaling Mode。 |
| [OHScalingModeV2](#ohscalingmodev2) | OHScalingModeV2 | 渲染缩放模式枚举。 |
| [OHHDRMetadataKey](#ohhdrmetadatakey) | OHHDRMetadataKey | 枚举HDR元数据关键字。 |
| [OHSurfaceSource](#ohsurfacesource) | OHSurfaceSource | 本地窗口内容来源类型枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OHNativeWindow* OH_NativeWindow_CreateNativeWindow(void* pSurface)](#oh_nativewindow_createnativewindow) | 创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例。<br>说明：此接口不可用，可通过OH_NativeImage_AcquireNativeWindow创建，或通过XComponent创建。 |
| [void OH_NativeWindow_DestroyNativeWindow(OHNativeWindow* window)](#oh_nativewindow_destroynativewindow) | 将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉。<br>本接口为非线程安全类型接口。 |
| [OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer(void* pSurfaceBuffer)](#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。<br>说明：此接口不可用，使用OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer替代。 |
| [OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(OH_NativeBuffer* nativeBuffer)](#oh_nativewindow_createnativewindowbufferfromnativebuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。<br>本接口需要与[OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。 |
| [void OH_NativeWindow_DestroyNativeWindowBuffer(OHNativeWindowBuffer* buffer)](#oh_nativewindow_destroynativewindowbuffer) | 将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_NativeWindowRequestBuffer(OHNativeWindow *window,OHNativeWindowBuffer **buffer, int *fenceFd)](#oh_nativewindow_nativewindowrequestbuffer) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。<br>在调用本接口前，需要通过[SET_BUFFER_GEOMETRY](#nativewindowoperation)对OHNativeWindow设置宽高。<br>本接口需要与[OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer)接口配合使用，否则内存会耗尽。<br>当fenceFd使用完，用户需要将其close。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_NativeWindowFlushBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer,int fenceFd, Region region)](#oh_nativewindow_nativewindowflushbuffer) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。<br>系统会将fenceFd关闭，无需用户close。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_GetLastFlushedBuffer(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])](#oh_nativewindow_getlastflushedbuffer) | 从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer。 |
| [int32_t OH_NativeWindow_NativeWindowAbortBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)](#oh_nativewindow_nativewindowabortbuffer) | 通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_NativeWindowHandleOpt(OHNativeWindow *window, int code, ...)](#oh_nativewindow_nativewindowhandleopt) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。<br>本接口为非线程安全类型接口。 |
| [BufferHandle *OH_NativeWindow_GetBufferHandleFromNative(OHNativeWindowBuffer *buffer)](#oh_nativewindow_getbufferhandlefromnative) | 通过OHNativeWindowBuffer获取该buffer的BufferHandle指针。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_NativeObjectReference(void *obj)](#oh_nativewindow_nativeobjectreference) | 增加一个NativeObject的引用计数。<br>本接口需要与[OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)](#oh_nativewindow_nativeobjectunreference) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_GetNativeObjectMagic(void *obj)](#oh_nativewindow_getnativeobjectmagic) | 获取NativeObject的MagicId。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_NativeWindowSetScalingMode(OHNativeWindow *window, uint32_t sequence,OHScalingMode scalingMode)](#oh_nativewindow_nativewindowsetscalingmode) | 设置OHNativeWindow的ScalingMode。 |
| [int32_t OH_NativeWindow_NativeWindowSetMetaData(OHNativeWindow *window, uint32_t sequence, int32_t size,const OHHDRMetaData *metaData)](#oh_nativewindow_nativewindowsetmetadata) | 设置OHNativeWindow的元数据。 |
| [int32_t OH_NativeWindow_NativeWindowSetMetaDataSet(OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key,int32_t size, const uint8_t *metaData)](#oh_nativewindow_nativewindowsetmetadataset) | 设置OHNativeWindow的元数据集。 |
| [int32_t OH_NativeWindow_NativeWindowSetTunnelHandle(OHNativeWindow *window, const OHExtDataHandle *handle)](#oh_nativewindow_nativewindowsettunnelhandle) | 设置OHNativeWindow的TunnelHandle。 |
| [int32_t OH_NativeWindow_NativeWindowAttachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)](#oh_nativewindow_nativewindowattachbuffer) | 将OHNativeWindowBuffer添加进OHNativeWindow中。<br>本接口需要与[OH_NativeWindow_NativeWindowDetachBuffer](#oh_nativewindow_nativewindowdetachbuffer)接口配合使用，否则会存在内存管理混乱问题。<br>本接口为非线程安全类型接口。<br> |
| [int32_t OH_NativeWindow_NativeWindowDetachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)](#oh_nativewindow_nativewindowdetachbuffer) | 将OHNativeWindowBuffer从OHNativeWindow中分离。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_GetSurfaceId(OHNativeWindow *window, uint64_t *surfaceId)](#oh_nativewindow_getsurfaceid) | 通过OHNativeWindow获取对应的surfaceId。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId(uint64_t surfaceId, OHNativeWindow **window)](#oh_nativewindow_createnativewindowfromsurfaceid) | 通过surfaceId创建对应的OHNativeWindow。<br>本接口需要与[OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow)接口配合使用，否则会存在内存泄露。<br>如果存在并发释放OHNativeWindow的情况，需要通过[OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference)和[OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference)对OHNativeWindow进行引用计数加一和减一。<br>通过surfaceId获取的surface需要是在本进程中创建的，不能跨进程获取surface。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_NativeWindowSetScalingModeV2(OHNativeWindow* window, OHScalingModeV2 scalingMode)](#oh_nativewindow_nativewindowsetscalingmodev2) | 设置OHNativeWindow的渲染缩放模式。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_GetLastFlushedBufferV2(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])](#oh_nativewindow_getlastflushedbufferv2) | 从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer,与OH_NativeWindow_GetLastFlushedBuffer的差异在于matrix不同。<br>本接口需要与[OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。 |
| [void OH_NativeWindow_SetBufferHold(OHNativeWindow *window)](#oh_nativewindow_setbufferhold) | 提前缓存一帧buffer，且缓存的这一帧延迟一帧上屏显示，以此抵消后续一次超长帧丢帧。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_WriteToParcel(OHNativeWindow *window, OHIPCParcel *parcel)](#oh_nativewindow_writetoparcel) | 将窗口对象写入IPC序列化对象中。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_ReadFromParcel(OHIPCParcel *parcel, OHNativeWindow **window)](#oh_nativewindow_readfromparcel) | 从IPC序列化对象中读取窗口对象。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_SetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace colorSpace)](#oh_nativewindow_setcolorspace) | 为OHNativeWindow设置颜色空间属性。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_GetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace *colorSpace)](#oh_nativewindow_getcolorspace) | 获取OHNativeWindow颜色空间属性。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_SetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t size, uint8_t *metadata)](#oh_nativewindow_setmetadatavalue) | 为OHNativeWindow设置元数据属性值。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_GetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t *size, uint8_t **metadata)](#oh_nativewindow_getmetadatavalue) | 获取OHNativeWindow元数据属性值。<br>本接口为非线程安全类型接口。 |
| [int32_t OH_NativeWindow_CleanCache(OHNativeWindow *window)](#oh_nativewindow_cleancache) | 清理OHNativeWindow中的OHNativeWindowBuffer缓存。<br>使用该接口清理缓存前，需确保已通过[OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer)接口成功申请OHNativeWindowBuffer。<br>本接口为非线程安全类型接口。 |

## 枚举类型说明

### NativeWindowOperation

```
enum NativeWindowOperation
```

**描述**

OH_NativeWindow_NativeWindowHandleOpt函数中的操作码。

**起始版本：** 8

| 枚举项 | 描述 |
| -- | -- |
| SET_BUFFER_GEOMETRY | 设置本地窗口缓冲区几何图形，函数中的可变参数是[输入] int32_t width，[输入] int32_t height。 |
| GET_BUFFER_GEOMETRY | 获取本地窗口缓冲区几何图形，函数中的可变参数是[输出] int32_theight，[输入] int32_twidth。 |
| GET_FORMAT | 获取本地窗口缓冲区格式，函数中的可变参数是[输出] int32_tformat，取值具体可见[OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format)枚举值。 |
| SET_FORMAT | 设置本地窗口缓冲区格式，函数中的可变参数是[输入] int32_t format，取值具体可见[OH_NativeBuffer_Format](capi-native-buffer-h.md#oh_nativebuffer_format)枚举值。 |
| GET_USAGE | 获取本地窗口读写方式，函数中的可变参数是[输出] uint64_tusage，取值具体可见[OH_NativeBuffer_Usage](capi-native-buffer-h.md#oh_nativebuffer_usage)枚举值。 |
| SET_USAGE | 设置本地窗口缓冲区读写方式，函数中的可变参数是[输入] uint64_t usage，取值具体可见[OH_NativeBuffer_Usage](capi-native-buffer-h.md#oh_nativebuffer_usage)枚举值。 |
| SET_STRIDE | 设置本地窗口缓冲区步幅，函数中的可变参数是[输入] int32_t stride。<br/>**废弃版本：** 16 |
| GET_STRIDE | 获取本地窗口缓冲区步幅，函数中的可变参数是[输出] int32_t *stride。<br/>**废弃版本：** 16<br/>**替代方案：** 使用[OH_NativeWindow_GetBufferHandleFromNative](#oh_nativewindow_getbufferhandlefromnative)接口获取BufferHandle实例，从[BufferHandle](capi-bufferhandle.md)实例中获取stride值。 |
| SET_SWAP_INTERVAL | 设置本地窗口缓冲区交换间隔，函数中的可变参数是[输入] int32_t interval。 |
| GET_SWAP_INTERVAL | 获取本地窗口缓冲区交换间隔，函数中的可变参数是[输出] int32_tinterval。 |
| SET_TIMEOUT | 设置请求本地窗口请求缓冲区的超时等待时间，未手动设置时默认值为3000毫秒，函数中的可变参数是[输入] int32_t timeout, 单位为毫秒。 |
| GET_TIMEOUT | 获取请求本地窗口请求缓冲区的超时等待时间，未手动设置时默认值为3000毫秒，函数中的可变参数是[输出] int32_ttimeout，单位为毫秒。 |
| SET_COLOR_GAMUT | 设置本地窗口缓冲区色彩空间，函数中的可变参数是[输入] int32_t colorGamut，取值具体可见[OH_NativeBuffer_ColorGamut](capi-native-buffer-h.md#oh_nativebuffer_colorgamut)枚举值。 |
| GET_COLOR_GAMUT | 获取本地窗口缓冲区色彩空间，函数中的可变参数是[输出] int32_tcolorGamut，取值具体可见[OH_NativeBuffer_ColorGamut](capi-native-buffer-h.md#oh_nativebuffer_colorgamut)枚举值。 |
| SET_TRANSFORM | 设置本地窗口缓冲区变换，函数中的可变参数是[输入] int32_t transform，取值具体可见[OH_NativeBuffer_TransformType](capi-native-buffer-h.md#oh_nativebuffer_transformtype)枚举值。 |
| GET_TRANSFORM | 获取本地窗口缓冲区变换，函数中的可变参数是[输出] int32_ttransform，取值具体可见[OH_NativeBuffer_TransformType](capi-native-buffer-h.md#oh_nativebuffer_transformtype)枚举值。 |
| SET_UI_TIMESTAMP | 设置本地窗口缓冲区UI时间戳，函数中的可变参数是[输入] uint64_t uiTimestamp。 |
| GET_BUFFERQUEUE_SIZE | 获取内存队列大小，函数中的可变参数是[输出] int32_t \*size。<br/>**起始版本：** 12 |
| SET_SOURCE_TYPE | 设置本地窗口内容来源，函数中的可变参数是[输入] int32_t sourceType，取值具体可见[OHSurfaceSource](#ohsurfacesource)枚举值。<br/>**起始版本：** 12 |
| GET_SOURCE_TYPE | 获取本地窗口内容来源，函数中的可变参数是[输出] int32_t *sourceType，取值具体可见[OHSurfaceSource](#ohsurfacesource)枚举值。<br/>**起始版本：** 12 |
| SET_APP_FRAMEWORK_TYPE | 设置本地窗口应用框架名称，函数中的可变参数是[输入] char* frameworkType，最大支持64字节。<br/>**起始版本：** 12 |
| GET_APP_FRAMEWORK_TYPE | 获取本地窗口应用框架名称，函数中的可变参数是[输出] char* frameworkType。<br/>**起始版本：** 12 |
| SET_HDR_WHITE_POINT_BRIGHTNESS | 设置HDR白点亮度，函数中的可变参数是[输入] float brightness。取值范围为[0.0f, 1.0f]。<br/>**起始版本：** 12 |
| SET_SDR_WHITE_POINT_BRIGHTNESS | 设置SDR白点亮度，函数中的可变参数是[输入] float brightness。取值范围为[0.0f, 1.0f]。<br/>**起始版本：** 12 |
| SET_DESIRED_PRESENT_TIMESTAMP = 24 | 设置本地窗口缓冲区期望上屏时间的时间戳。<br/> 当且仅当RenderService为本地窗口的消费者时，该时间戳生效<br/>本操作执行后需要配合调用[OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer)生效。<br/>生产者下一次放入队列的buffer，达到该期望上屏时间后，才会被RenderService消费并上屏。<br/>如果buffer队列中存在多个生产者放入的buffer，都设置了desiredPresentTimestamp并已达到期望上屏时间，则较早入队的buffer将被消费者丢弃回队列。<br/>如果期望上屏时间大于消费者提供的时间 1 秒以上，则该期望上屏时间戳将被忽略。<br/> 函数中的可变参数是[输入] int64_t desiredPresentTimestamp，取值范围大于0，应由std::chrono::steady_clock标准库时钟生成，且单位为纳秒。<br/>**起始版本：** 13 |

### OHScalingMode

```
enum OHScalingMode
```

**描述**

缩放模式Scaling Mode。

**起始版本：** 9

**废弃版本：** 10

**替代接口：** [OHScalingModeV2](#ohscalingmodev2)

| 枚举项 | 描述 |
| -- | -- |
| OH_SCALING_MODE_FREEZE = 0 | 在接收到窗口大小的缓冲区之前，不可以更新窗口内容。 |
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

| 枚举项 | 描述 |
| -- | -- |
| OH_SCALING_MODE_FREEZE_V2 = 0 | 冻结窗口，在接收到和窗口大小相等的缓冲区之前，窗口内容不进行更新。 |
| OH_SCALING_MODE_SCALE_TO_WINDOW_V2 | 缓冲区进行拉伸缩放以匹配窗口大小。 |
| OH_SCALING_MODE_SCALE_CROP_V2 | 缓冲区按原比例缩放，使得缓冲区的较小边与窗口匹配，较长边超出窗口部分被视为透明。 |
| OH_SCALING_MODE_NO_SCALE_CROP_V2 | 按窗口大小将缓冲区裁剪，裁剪矩形之外的像素被视为完全透明。 |
| OH_SCALING_MODE_SCALE_FIT_V2 | 缓冲区按原比例缩放。优先显示所有缓冲区内容。如果比例与窗口比例不同，用背景颜色填充窗口的未填充区域。<br>开发板和模拟器不支持该模式。 |

### OHHDRMetadataKey

```
enum OHHDRMetadataKey
```

**描述**

枚举HDR元数据关键字。

**起始版本：** 9

**废弃版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_METAKEY_RED_PRIMARY_X = 0 | 红基色X坐标。 |
| OH_METAKEY_RED_PRIMARY_Y = 1, | 红基色Y坐标。 |
| OH_METAKEY_GREEN_PRIMARY_X = 2, | 绿基色X坐标。 |
| OH_METAKEY_GREEN_PRIMARY_Y = 3, | 绿基色Y坐标。 |
| OH_METAKEY_BLUE_PRIMARY_X = 4, | 蓝基色X坐标。 |
| OH_METAKEY_BLUE_PRIMARY_Y = 5, | 蓝基色Y坐标。 |
| OH_METAKEY_WHITE_PRIMARY_X = 6, | 白点X坐标。 |
| OH_METAKEY_WHITE_PRIMARY_Y = 7, | 白点Y坐标。 |
| OH_METAKEY_MAX_LUMINANCE = 8, | 最大的光亮度。 |
| OH_METAKEY_MIN_LUMINANCE = 9, | 最小的光亮度。 |
| OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, | 最大的内容亮度水平。 |
| OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11, | 最大的帧平均亮度水平。 |
| OH_METAKEY_HDR10_PLUS = 12, | HDR10 Plus。 |
| OH_METAKEY_HDR_VIVID = 13, | Vivid。 |

### OHSurfaceSource

```
enum OHSurfaceSource
```

**描述**

本地窗口内容来源类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_SURFACE_SOURCE_DEFAULT = 0 | 窗口内容默认来源。 |
| OH_SURFACE_SOURCE_UI | 窗口内容来自于UI。 |
| OH_SURFACE_SOURCE_GAME | 窗口内容来自于游戏。 |
| OH_SURFACE_SOURCE_CAMERA | 窗口内容来自于相机。 |
| OH_SURFACE_SOURCE_VIDEO | 窗口内容来自于视频。 |


## 函数说明

### OH_NativeWindow_CreateNativeWindow()

```
OHNativeWindow* OH_NativeWindow_CreateNativeWindow(void* pSurface)
```

**描述**

创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例。<br>说明：此接口不可用，可通过[OH_NativeImage_AcquireNativeWindow](capi-native-image-h.md#oh_nativeimage_acquirenativewindow)创建，或通过XComponent创建。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**废弃版本：** 从API version 12开始废弃，不再提供替代接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* pSurface | 一个指向生产者ProduceSurface的指针，类型为sptr\<OHOS::Surface>。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md)* | 返回一个指针，指向OHNativeWindow的结构体实例。 |

### OH_NativeWindow_DestroyNativeWindow()

```
void OH_NativeWindow_DestroyNativeWindow(OHNativeWindow* window)
```

**描述**

将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md)* window | 一个OHNativeWindow的结构体实例的指针。 |

### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer(void* pSurfaceBuffer)
```

**描述**

创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。<br>说明：此接口不可用，使用[OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer)替代。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8

**废弃版本：** 12

**替代接口：** [OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer](#oh_nativewindow_createnativewindowbufferfromnativebuffer)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| void* pSurfaceBuffer | 一个指向生产者buffer的指针，类型为sptr<OHOS::SurfaceBuffer>。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OHNativeWindowBuffer* | 返回一个指针，指向OHNativeWindowBuffer的结构体实例。 |

### OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer()

```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromNativeBuffer(OH_NativeBuffer* nativeBuffer)
```

**描述**

创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例。<br>本接口需要与[OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_NativeBuffer* nativeBuffer | 一个指向OH_NativeBuffer的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OHNativeWindowBuffer* | 返回一个指针，指向OHNativeWindowBuffer的结构体实例。 |

### OH_NativeWindow_DestroyNativeWindowBuffer()

```
void OH_NativeWindow_DestroyNativeWindowBuffer(OHNativeWindowBuffer* buffer)
```

**描述**

将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md)* buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 |

### OH_NativeWindow_NativeWindowRequestBuffer()

```
int32_t OH_NativeWindow_NativeWindowRequestBuffer(OHNativeWindow *window,OHNativeWindowBuffer **buffer, int *fenceFd)
```

**描述**

通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。<br>在调用本接口前，需要通过[SET_BUFFER_GEOMETRY](#nativewindowoperation)对OHNativeWindow设置宽高。<br>本接口需要与[OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer)接口配合使用，否则内存会耗尽。<br>当fenceFd使用完，用户需要将其close。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) **buffer | 一个指向OHNativeWindowBuffer指针的指针（二级指针）。<br>通过OH_NativeWindow_GetBufferHandleFromNative可获取BufferHandle结构体，访问缓冲区内存。 |
| int *fenceFd | 一个文件描述符句柄，用于GPU/CPU同步：不同取值及含义如下：<br>- 返回≥0：缓冲区正被GPU使用，需要等待文件描述符fenceFd就绪。<br>- 返回-1：缓冲区可直接使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_NativeWindowFlushBuffer()

```
int32_t OH_NativeWindow_NativeWindowFlushBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer,int fenceFd, Region region)
```

**描述**

通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。<br>系统会将fenceFd关闭，无需用户close。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) *buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 |
| int fenceFd | 一个文件描述符句柄，用以同步时序。不同取值及含义如下：<br>- -1：CPU渲染完成，无需同步时序。<br>- ≥0：从GPU同步对象转换（如EGL的eglDupNativeFenceFDANDROID），对端需要通过此fenceFd同步时序。 |
| [Region](capi-region.md) region | 一个Region结构体，表示一块脏区域，该区域有内容更新。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_GetLastFlushedBuffer()

```
int32_t OH_NativeWindow_GetLastFlushedBuffer(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])
```

**描述**

从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 11

**废弃版本：** 从API version 12开始废弃。

**替代接口：** [OH_NativeWindow_GetLastFlushedBufferV2](#oh_nativewindow_getlastflushedbufferv2)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) **buffer | 一个OHNativeWindowBuffer结构体指针的指针。 |
| int *fenceFd | 一个文件描述符的指针。 |
| matrix |  表示检索到的44变换矩阵。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_NativeWindowAbortBuffer()

```
int32_t OH_NativeWindow_NativeWindowAbortBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)
```

**描述**

通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) *buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_NativeWindowHandleOpt()

```
int32_t OH_NativeWindow_NativeWindowHandleOpt(OHNativeWindow *window, int code, ...)
```

**描述**

设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| int code | 表示操作码，详见[NativeWindowOperation](#nativewindowoperation)。 |
| ... |  可变参数，必须与操作码对应的数据类型保持一致，且入参数量严格按照操作码提示传入，否则会存在未定义行为。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_GetBufferHandleFromNative()

```
BufferHandle *OH_NativeWindow_GetBufferHandleFromNative(OHNativeWindowBuffer *buffer)
```

**描述**

通过OHNativeWindowBuffer获取该buffer的BufferHandle指针。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) *buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [BufferHandle](capi-bufferhandle.md) | BufferHandle 返回一个指针，指向[BufferHandle](capi-bufferhandle.md)的结构体实例。 |

### OH_NativeWindow_NativeObjectReference()

```
int32_t OH_NativeWindow_NativeObjectReference(void *obj)
```

**描述**

增加一个NativeObject的引用计数。<br>本接口需要与[OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| void *obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_NativeObjectUnreference()

```
int32_t OH_NativeWindow_NativeObjectUnreference(void *obj)
```

**描述**

减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| void *obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_GetNativeObjectMagic()

```
int32_t OH_NativeWindow_GetNativeObjectMagic(void *obj)
```

**描述**

获取NativeObject的MagicId。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| void *obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | MagicId 返回值为魔鬼数字，每个NativeObject唯一。 |

### OH_NativeWindow_NativeWindowSetScalingMode()

```
int32_t OH_NativeWindow_NativeWindowSetScalingMode(OHNativeWindow *window, uint32_t sequence,OHScalingMode scalingMode)
```

**描述**

设置OHNativeWindow的ScalingMode。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**废弃版本：** 从API version 10开始废弃。

**替代接口：** [OH_NativeWindow_NativeWindowSetScalingModeV2](#oh_nativewindow_nativewindowsetscalingmodev2)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| uint32_t sequence | 生产缓冲区的序列。 |
| [OHScalingMode](#ohscalingmode) scalingMode | 枚举值OHScalingMode。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功。 |

### OH_NativeWindow_NativeWindowSetMetaData()

```
int32_t OH_NativeWindow_NativeWindowSetMetaData(OHNativeWindow *window, uint32_t sequence, int32_t size,const OHHDRMetaData *metaData)
```

**描述**

设置OHNativeWindow的元数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**废弃版本：** 从API version 10开始废弃，不再提供替代接口。


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| uint32_t sequence | 生产缓冲区的序列。 |
| int32_t size | OHHDRMetaData数组的大小。 |
| metaDate |  指向OHHDRMetaData数组的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功。 |

### OH_NativeWindow_NativeWindowSetMetaDataSet()

```
int32_t OH_NativeWindow_NativeWindowSetMetaDataSet(OHNativeWindow *window, uint32_t sequence, OHHDRMetadataKey key,int32_t size, const uint8_t *metaData)
```

**描述**

设置OHNativeWindow的元数据集。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**废弃版本：** 从API version 10开始废弃，不再提供替代接口。


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| uint32_t sequence | 生产缓冲区的序列。 |
| [OHHDRMetadataKey](#ohhdrmetadatakey) key | 枚举值OHHDRMetadataKey。 |
| int32_t size | uint8_t向量的大小。 |
| metaDate |  指向uint8_t向量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功。 |

### OH_NativeWindow_NativeWindowSetTunnelHandle()

```
int32_t OH_NativeWindow_NativeWindowSetTunnelHandle(OHNativeWindow *window, const OHExtDataHandle *handle)
```

**描述**

设置OHNativeWindow的TunnelHandle。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 9

**废弃版本：** 从API version 10开始废弃，不再提供替代接口。


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| const [OHExtDataHandle](capi-ohextdatahandle.md) *handle | 指向OHExtDataHandle的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功。 |

### OH_NativeWindow_NativeWindowAttachBuffer()

```
int32_t OH_NativeWindow_NativeWindowAttachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)
```

**描述**

将OHNativeWindowBuffer添加进OHNativeWindow中。<br>本接口需要与[OH_NativeWindow_NativeWindowDetachBuffer](#oh_nativewindow_nativewindowdetachbuffer)接口配合使用，否则会存在内存管理混乱问题。<br>本接口为非线程安全类型接口。<br>

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) *buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_NativeWindowDetachBuffer()

```
int32_t OH_NativeWindow_NativeWindowDetachBuffer(OHNativeWindow *window, OHNativeWindowBuffer *buffer)
```

**描述**

将OHNativeWindowBuffer从OHNativeWindow中分离。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) *buffer | 一个OHNativeWindowBuffer的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_GetSurfaceId()

```
int32_t OH_NativeWindow_GetSurfaceId(OHNativeWindow *window, uint64_t *surfaceId)
```

**描述**

通过OHNativeWindow获取对应的surfaceId。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| uint64_t *surfaceId | 一个surface对应ID的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_CreateNativeWindowFromSurfaceId()

```
int32_t OH_NativeWindow_CreateNativeWindowFromSurfaceId(uint64_t surfaceId, OHNativeWindow **window)
```

**描述**

通过surfaceId创建对应的OHNativeWindow。<br>本接口需要与[OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow)接口配合使用，否则会存在内存泄露。<br>如果存在并发释放OHNativeWindow的情况，需要通过[OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference)和[OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference)对OHNativeWindow进行引用计数加一和减一。<br>通过surfaceId获取的surface需要是在本进程中创建的，不能跨进程获取surface。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint64_t surfaceId | 一个surface对应的ID。 |
| [OHNativeWindow](capi-nativewindow.md) **window | 一个OHNativeWindow的结构体实例的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_NativeWindowSetScalingModeV2()

```
int32_t OH_NativeWindow_NativeWindowSetScalingModeV2(OHNativeWindow* window, OHScalingModeV2 scalingMode)
```

**描述**

设置OHNativeWindow的渲染缩放模式。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md)* window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHScalingModeV2](#ohscalingmodev2) scalingMode | 一个OHScalingModeV2类型的枚举值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_GetLastFlushedBufferV2()

```
int32_t OH_NativeWindow_GetLastFlushedBufferV2(OHNativeWindow *window, OHNativeWindowBuffer **buffer,int *fenceFd, float matrix[16])
```

**描述**

从OHNativeWindow获取上次送回到buffer队列中的OHNativeWindowBuffer,与OH_NativeWindow_GetLastFlushedBuffer的差异在于matrix不同。<br>本接口需要与[OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference)接口配合使用，否则会存在内存泄露。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个OHNativeWindow的结构体实例的指针。 |
| [OHNativeWindowBuffer](capi-nativewindowbuffer.md) **buffer | 一个OHNativeWindowBuffer结构体指针的指针。 |
| int *fenceFd | 一个文件描述符的指针。 |
| matrix |  表示检索到的44变换矩阵。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_SetBufferHold()

```
void OH_NativeWindow_SetBufferHold(OHNativeWindow *window)
```

**描述**

提前缓存一帧buffer，且缓存的这一帧延迟一帧上屏显示，以此抵消后续一次超长帧丢帧。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个[OHNativeWindow](capi-nativewindow.md)的结构体实例的指针。 |

### OH_NativeWindow_WriteToParcel()

```
int32_t OH_NativeWindow_WriteToParcel(OHNativeWindow *window, OHIPCParcel *parcel)
```

**描述**

将窗口对象写入IPC序列化对象中。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个指向[OHNativeWindow](capi-nativewindow.md)的结构体实例的指针。 |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | 一个指向[OHIPCParcel](capi-ohipcparcel.md)的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_ReadFromParcel()

```
int32_t OH_NativeWindow_ReadFromParcel(OHIPCParcel *parcel, OHNativeWindow **window)
```

**描述**

从IPC序列化对象中读取窗口对象。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | 一个指向[OHIPCParcel](capi-ohipcparcel.md)的结构体实例的指针。 |
| [OHNativeWindow](capi-nativewindow.md) **window | 一个指向[OHNativeWindow](capi-nativewindow.md)的结构体实例的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_SetColorSpace()

```
int32_t OH_NativeWindow_SetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace colorSpace)
```

**描述**

为OHNativeWindow设置颜色空间属性。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个指向[OHNativeWindow](capi-nativewindow.md)的结构体实例的指针。 |
| [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace) colorSpace | 为OHNativeWindow设置的颜色空间，其值从[OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_GetColorSpace()

```
int32_t OH_NativeWindow_GetColorSpace(OHNativeWindow *window, OH_NativeBuffer_ColorSpace *colorSpace)
```

**描述**

获取OHNativeWindow颜色空间属性。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个指向[OHNativeWindow](capi-nativewindow.md)的结构体实例的指针。 |
| [OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace) *colorSpace | 为OHNativeWindow设置的颜色空间，其值从[OH_NativeBuffer_ColorSpace](capi-buffer-common-h.md#oh_nativebuffer_colorspace)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_SetMetadataValue()

```
int32_t OH_NativeWindow_SetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t size, uint8_t *metadata)
```

**描述**

为OHNativeWindow设置元数据属性值。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个指向[OHNativeWindow](capi-nativewindow.md)的结构体实例的指针。 |
| [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey) metadataKey | Window的元数据类型，其值从[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)获取。 |
| int32_t size | uint8_t向量的大小，其取值范围见[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)。 |
| metaDate |  指向uint8_t向量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_GetMetadataValue()

```
int32_t OH_NativeWindow_GetMetadataValue(OHNativeWindow *window, OH_NativeBuffer_MetadataKey metadataKey,int32_t *size, uint8_t **metadata)
```

**描述**

获取OHNativeWindow元数据属性值。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个指向[OHNativeWindow](capi-nativewindow.md)的结构体实例的指针。 |
| [OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey) metadataKey | Window的元数据类型，其值从[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)获取。 |
| int32_t *size | uint8_t向量的大小，其取值范围见[OH_NativeBuffer_MetadataKey](capi-buffer-common-h.md#oh_nativebuffer_metadatakey)。 |
| metaDate |  指向uint8_t向量的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |

### OH_NativeWindow_CleanCache()

```
int32_t OH_NativeWindow_CleanCache(OHNativeWindow *window)
```

**描述**

清理OHNativeWindow中的OHNativeWindowBuffer缓存。<br>使用该接口清理缓存前，需确保已通过[OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer)接口成功申请OHNativeWindowBuffer。<br>本接口为非线程安全类型接口。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OHNativeWindow](capi-nativewindow.md) *window | 一个指向[OHNativeWindow](capi-nativewindow.md)的结构体实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回值为0表示执行成功，其他返回值可参考[OHNativeErrorCode](capi-graphic-error-code-h.md#ohnativeerrorcode)。 |



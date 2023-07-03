# NativeWindow


## 概述

提供NativeWindow功能，作为数据生产者，可用来和egl对接

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**起始版本:**

8


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [external_window.h](external__window_8h.md) | 定义获取和使用NativeWindow的相关函数<br/>引用文件：&lt;native_window/external_window.h&gt; |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [Region](_region.md) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区） |
| [OHHDRMetaData](_o_h_h_d_r_meta_data.md) | HDR元数据结构体定义 |
| [OHExtDataHandle](_o_h_ext_data_handle.md) | 扩展数据句柄结构体定义 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OHNativeWindow](#ohnativewindow) | 提供对OHNativeWindow的访问功能 |
| [OHNativeWindowBuffer](#ohnativewindowbuffer) | 提供对OHNativeWindowBuffer的访问功能 |
| [Region](#region) | 表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区） |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [NativeWindowOperation](#nativewindowoperation) {<br/>SET_BUFFER_GEOMETRY, GET_BUFFER_GEOMETRY, GET_FORMAT, SET_FORMAT,<br/>GET_USAGE, SET_USAGE, SET_STRIDE, GET_STRIDE,<br/>SET_SWAP_INTERVAL, GET_SWAP_INTERVAL, SET_TIMEOUT, GET_TIMEOUT,<br/>SET_COLOR_GAMUT, GET_COLOR_GAMUT, SET_TRANSFORM, GET_TRANSFORM,<br/>SET_UI_TIMESTAMP<br/>} | OH_NativeWindow_NativeWindowHandleOpt函数中的操作码 |
| [OHScalingMode](#ohscalingmode) { OH_SCALING_MODE_FREEZE = 0, OH_SCALING_MODE_SCALE_TO_WINDOW, OH_SCALING_MODE_SCALE_CROP, OH_SCALING_MODE_NO_SCALE_CROP } | 缩放模式 Scaling Mode |
| [OHHDRMetadataKey](#ohhdrmetadatakey) {<br/>OH_METAKEY_RED_PRIMARY_X = 0, OH_METAKEY_RED_PRIMARY_Y = 1, OH_METAKEY_GREEN_PRIMARY_X = 2, OH_METAKEY_GREEN_PRIMARY_Y = 3,<br/>OH_METAKEY_BLUE_PRIMARY_X = 4, OH_METAKEY_BLUE_PRIMARY_Y = 5, OH_METAKEY_WHITE_PRIMARY_X = 6, OH_METAKEY_WHITE_PRIMARY_Y = 7,<br/>OH_METAKEY_MAX_LUMINANCE = 8, OH_METAKEY_MIN_LUMINANCE = 9, OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL = 10, OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL = 11,<br/>OH_METAKEY_HDR10_PLUS = 12, OH_METAKEY_HDR_VIVID = 13<br/>} | 枚举HDR元数据关键字 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeWindow_CreateNativeWindow](#oh_nativewindow_createnativewindow) (void \*pSurface) | 创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例 |
| [OH_NativeWindow_DestroyNativeWindow](#oh_nativewindow_destroynativewindow) (OHNativeWindow \*window) | 将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉 |
| [OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer](#oh_nativewindow_createnativewindowbufferfromsurfacebuffer) (void \*pSurfaceBuffer) | 创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例 |
| [OH_NativeWindow_DestroyNativeWindowBuffer](#oh_nativewindow_destroynativewindowbuffer) (OHNativeWindowBuffer \*buffer) | 将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉 |
| [OH_NativeWindow_NativeWindowRequestBuffer](#oh_nativewindow_nativewindowrequestbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产 |
| [OH_NativeWindow_NativeWindowFlushBuffer](#oh_nativewindow_nativewindowflushbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费 |
| [OH_NativeWindow_NativeWindowAbortBuffer](#oh_nativewindow_nativewindowabortbuffer) (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer) | 通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请 |
| [OH_NativeWindow_NativeWindowHandleOpt](#oh_nativewindow_nativewindowhandleopt) (OHNativeWindow \*window, int code,...) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等 |
| [OH_NativeWindow_GetBufferHandleFromNative](#oh_nativewindow_getbufferhandlefromnative) (OHNativeWindowBuffer \*buffer) | 通过OHNativeWindowBuffer获取该buffer的BufferHandle指针 |
| [OH_NativeWindow_NativeObjectReference](#oh_nativewindow_nativeobjectreference) (void \*obj) | 增加一个NativeObject的引用计数 |
| [OH_NativeWindow_NativeObjectUnreference](#oh_nativewindow_nativeobjectunreference) (void \*obj) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉 |
| [OH_NativeWindow_GetNativeObjectMagic](#oh_nativewindow_getnativeobjectmagic) (void \*obj) | 获取NativeObject的MagicId |
| [OH_NativeWindow_NativeWindowSetScalingMode](#oh_nativewindow_nativewindowsetscalingmode) (OHNativeWindow \*window, uint32_t sequence, OHScalingMode scalingMode) | 设置OHNativeWindow的ScalingMode |
| [OH_NativeWindow_NativeWindowSetMetaData](#oh_nativewindow_nativewindowsetmetadata) (OHNativeWindow \*window, uint32_t sequence, int32_t size, const OHHDRMetaData \*metaData) | 设置OHNativeWindow的元数据 |
| [OH_NativeWindow_NativeWindowSetMetaDataSet](#oh_nativewindow_nativewindowsetmetadataset) (OHNativeWindow*window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t \*metaData) | 设置OHNativeWindow的元数据集。 |
| [OH_NativeWindow_NativeWindowSetTunnelHandle](#oh_nativewindow_nativewindowsettunnelhandle) (OHNativeWindow \*window, const OHExtDataHandle \*handle) | 设置OHNativeWindow的TunnelHandle。 |


## 类型定义说明


### OHNativeWindow


```
typedef struct NativeWindow OHNativeWindow
```

**描述:**

提供对OHNativeWindow的访问功能


### OHNativeWindowBuffer


```
typedef struct NativeWindowBuffer OHNativeWindowBuffer
```

**描述:**

提供对OHNativeWindowBuffer的访问功能


### Region


```
typedef struct Region Region
```

**描述:**

表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）


## 枚举类型说明


### NativeWindowOperation


```
enum NativeWindowOperation
```

**描述:**

OH_NativeWindow_NativeWindowHandleOpt函数中的操作码

| 枚举值 | 描述 |
| -------- | -------- |
| SET_BUFFER_GEOMETRY | 设置本地窗口缓冲区几何图形， 函数中的可变参数是 [输入] int32_t height，[输入] int32_t width。 |
| GET_BUFFER_GEOMETRY | 获取本地窗口缓冲区几何图形， 函数中的可变参数是 [输出] int32_t \*height， [输出] int32_t \*width。 |
| GET_FORMAT | 获取本地窗口缓冲区格式， 函数中的可变参数是 [输出] int32_t \*format。 |
| SET_FORMAT | 设置本地窗口缓冲区格式， 函数中的可变参数是 [输入] int32_t format。 |
| GET_USAGE | 获取本地窗口读写方式， 函数中的可变参数是 [输出] int32_t \*usage。 |
| SET_USAGE | 设置本地窗口缓冲区读写方式， 函数中的可变参数是 [输入] int32_t usage。 |
| SET_STRIDE | 设置本地窗口缓冲区步幅， 函数中的可变参数是 [输入] int32_t stride。 |
| GET_STRIDE | 获取本地窗口缓冲区步幅， 函数中的可变参数是 [输出] int32_t \*stride。 |
| SET_SWAP_INTERVAL | 设置本地窗口缓冲区交换间隔， 函数中的可变参数是 [输入] int32_t interval。 |
| GET_SWAP_INTERVAL | 获取本地窗口缓冲区交换间隔， 函数中的可变参数是 [输出] int32_t \*interval。 |
| SET_TIMEOUT | 设置请求本地窗口缓冲区的超时等待时间， 函数中的可变参数是 [输入] int32_t timeout。 |
| GET_TIMEOUT | 获取请求本地窗口缓冲区的超时等待时间， 函数中的可变参数是 [输出] int32_t \*timeout。 |
| SET_COLOR_GAMUT | 设置本地窗口缓冲区色彩空间， 函数中的可变参数是 [输入] int32_t colorGamut。 |
| GET_COLOR_GAMUT | 获取本地窗口缓冲区色彩空间， 函数中的可变参数是 [out int32_t \*colorGamut]。 |
| SET_TRANSFORM | 设置本地窗口缓冲区变换， 函数中的可变参数是 [输入] int32_t transform。 |
| GET_TRANSFORM | 获取本地窗口缓冲区变换， 函数中的可变参数是 [输出] int32_t \*transform。 |
| SET_UI_TIMESTAMP | 设置本地窗口缓冲区UI时间戳， 函数中的可变参数是 [输入] uint64_t uiTimestamp。 |


### OHHDRMetadataKey


```
enum OHHDRMetadataKey
```

**描述:**

枚举HDR元数据关键字

**起始版本:**

9


| 枚举值 | 描述 |
| -------- | -------- |
| OH_METAKEY_RED_PRIMARY_X | 红基色X坐标 |
| OH_METAKEY_RED_PRIMARY_Y | 红基色Y坐标 |
| OH_METAKEY_GREEN_PRIMARY_X | 绿基色X坐标 |
| OH_METAKEY_GREEN_PRIMARY_Y | 绿基色Y坐标 |
| OH_METAKEY_BLUE_PRIMARY_X | 蓝基色X坐标 |
| OH_METAKEY_BLUE_PRIMARY_Y | 蓝基色Y坐标 |
| OH_METAKEY_WHITE_PRIMARY_X | 白点X坐标 |
| OH_METAKEY_WHITE_PRIMARY_Y | 白点Y坐标 |
| OH_METAKEY_MAX_LUMINANCE | 最大的光亮度 |
| OH_METAKEY_MIN_LUMINANCE | 最小的光亮度 |
| OH_METAKEY_MAX_CONTENT_LIGHT_LEVEL | 最大的内容亮度水平 |
| OH_METAKEY_MAX_FRAME_AVERAGE_LIGHT_LEVEL | 最大的帧平均亮度水平 |
| OH_METAKEY_HDR10_PLUS | HDR10 Plus |
| OH_METAKEY_HDR_VIVID | Vivid |


### OHScalingMode


```
enum OHScalingMode
```

**描述:**

缩放模式 Scaling Mode

**起始版本:**

9


| 枚举值 | 描述 |
| -------- | -------- |
| OH_SCALING_MODE_FREEZE | 在接收到窗口大小的缓冲区之前，不可以更新窗口内容 |
| OH_SCALING_MODE_SCALE_TO_WINDOW | 缓冲区在二维中缩放以匹配窗口大小 |
| OH_SCALING_MODE_SCALE_CROP | 缓冲区被统一缩放，使得缓冲区的较小尺寸与窗口大小匹配 |
| OH_SCALING_MODE_NO_SCALE_CROP | 窗口被裁剪为缓冲区裁剪矩形的大小，裁剪矩形之外的像素被视为完全透明 |


## 函数说明


### OH_NativeWindow_CreateNativeWindow()


```
OHNativeWindow* OH_NativeWindow_CreateNativeWindow (void * pSurface)
```

**描述:**

创建OHNativeWindow实例，每次调用都会产生一个新的OHNativeWindow实例

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pSurface | 一个指向生产者ProduceSurface的指针，类型为sptr&lt;OHOS::Surface&gt; |

**返回:**

返回一个指针，指向OHNativeWindow的结构体实例


### OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer()


```
OHNativeWindowBuffer* OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void * pSurfaceBuffer)
```

**描述:**

创建OHNativeWindowBuffer实例，每次调用都会产生一个新的OHNativeWindowBuffer实例

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| pSurfaceBuffer | 一个指向生产者buffer的指针，类型为sptr&lt;OHOS::SurfaceBuffer&gt; |

**返回:**

返回一个指针，指向OHNativeWindowBuffer的结构体实例


### OH_NativeWindow_DestroyNativeWindow()


```
void OH_NativeWindow_DestroyNativeWindow (OHNativeWindow *  window)
```

**描述:**

将OHNativeWindow对象的引用计数减1，当引用计数为0的时候，该OHNativeWindow对象会被析构掉

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |


### OH_NativeWindow_DestroyNativeWindowBuffer()


```
void OH_NativeWindow_DestroyNativeWindowBuffer (OHNativeWindowBuffer *  buffer)
```

**描述:**

将OHNativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该OHNativeWindowBuffer对象会被析构掉

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针 |


### OH_NativeWindow_GetBufferHandleFromNative()


```
BufferHandle* OH_NativeWindow_GetBufferHandleFromNative (OHNativeWindowBuffer *  buffer)
```

**描述:**

通过OHNativeWindowBuffer获取该buffer的BufferHandle指针

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针 |

**返回:**

BufferHandle 返回一个指针，指向BufferHandle的结构体实例


### OH_NativeWindow_GetNativeObjectMagic()


```
int32_t OH_NativeWindow_GetNativeObjectMagic (void * obj)
```

**描述:**

获取NativeObject的MagicId

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针 |

**返回:**

MagicId 返回值为魔鬼数字，每个NativeObject唯一


### OH_NativeWindow_NativeObjectReference()


```
int32_t OH_NativeWindow_NativeObjectReference (void * obj)
```

**描述:**

增加一个NativeObject的引用计数

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针 |

**返回:**

返回值为0表示执行成功


### OH_NativeWindow_NativeObjectUnreference()


```
int32_t OH_NativeWindow_NativeObjectUnreference (void * obj)
```

**描述:**

减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| obj | 一个OHNativeWindow或者OHNativeWindowBuffer的结构体实例的指针 |

**返回:**

返回值为0表示执行成功


### OH_NativeWindow_NativeWindowAbortBuffer()


```
int32_t OH_NativeWindow_NativeWindowAbortBuffer (OHNativeWindow *  window, OHNativeWindowBuffer *  buffer )
```

**描述:**

通过OHNativeWindow将之前申请出来的OHNativeWindowBuffer返还到Buffer队列中，供下次再申请

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针 |

**返回:**

返回值为0表示执行成功


### OH_NativeWindow_NativeWindowFlushBuffer()


```
int32_t OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow *  window, OHNativeWindowBuffer *  buffer, int fenceFd, Region region )
```

**描述:**

通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |
| buffer | 一个OHNativeWindowBuffer的结构体实例的指针 |
| fenceFd | 一个文件描述符句柄，用以同步时序 |
| region | 表示一块脏区域，该区域有内容更新 |

**返回:**

返回值为0表示执行成功


### OH_NativeWindow_NativeWindowHandleOpt()


```
int32_t OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow *  window, int code,  ... )
```

**描述:**

设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |
| code | 表示操作码，详见[NativeWindowOperation](#nativewindowoperation) |
| ... | 可变参数，必须与操作码一一对应 |

**返回:**

返回值为0表示执行成功


### OH_NativeWindow_NativeWindowRequestBuffer()


```
int32_t OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow *  window, OHNativeWindowBuffer **  buffer, int * fenceFd )
```

**描述:**

通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |
| buffer | 一个OHNativeWindowBuffer的结构体实例的二级指针 |
| fenceFd | 一个文件描述符句柄 |

**返回:**

返回值为0表示执行成功


### OH_NativeWindow_NativeWindowSetMetaData()


```
int32_t OH_NativeWindow_NativeWindowSetMetaData (OHNativeWindow *  window, uint32_t sequence, int32_t size, const OHHDRMetaData *  metaData )
```

**描述:**

设置OHNativeWindow的元数据

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |
| sequence | 生产缓冲区的序列 |
| size | OHHDRMetaData数组的大小 |
| metaDate | 指向OHHDRMetaData数组的指针 |

**返回:**

返回值为0表示执行成功

**起始版本:**

9



### OH_NativeWindow_NativeWindowSetMetaDataSet()


```
int32_t OH_NativeWindow_NativeWindowSetMetaDataSet (OHNativeWindow *  window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t * metaData )
```

**描述:**

设置OHNativeWindow的元数据集。

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针。 |
| sequence | 生产缓冲区的序列。 |
| key | 枚举值OHHDRMetadataKey |
| size | uint8_t向量的大小 |
| metaDate | 指向uint8_t向量的指针 |

**返回:**

返回值为0表示执行成功

**起始版本:**

9



### OH_NativeWindow_NativeWindowSetScalingMode()


```
int32_t OH_NativeWindow_NativeWindowSetScalingMode (OHNativeWindow *  window, uint32_t sequence, OHScalingMode scalingMode )
```

**描述:**

设置OHNativeWindow的ScalingMode

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |
| sequence | 生产缓冲区的序列 |
| scalingMode | 枚举值OHScalingMode |

**返回:**

返回值为0表示执行成功

**起始版本:**

9


### OH_NativeWindow_NativeWindowSetTunnelHandle()


```
int32_t OH_NativeWindow_NativeWindowSetTunnelHandle (OHNativeWindow *  window, const OHExtDataHandle *  handle )
```

**描述:**

设置OHNativeWindow的TunnelHandle。

\@syscap SystemCapability.Graphic.Graphic2D.NativeWindow

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| window | 一个OHNativeWindow的结构体实例的指针 |
| handle | 指向OHExtDataHandle的指针 |

**返回:**

返回值为0表示执行成功

**起始版本:**

9


# OH_NativeBuffer


## 概述

提供NativeBuffer功能，通过提供的接口，可以实现共享内存的申请、使用、属性查询、释放等操作。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**起始版本:**

9


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_buffer.h](native__buffer_8h.md) | 定义获取和使用NativeBuffer的相关函数。<br/>**引用文件：** &lt;native_buffer/native_buffer.h&gt; <br/>**库：** libnative_buffer.so|


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) | 提供OH_NativeBuffer结构体声明。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Usage](#oh_nativebuffer_usage) { NATIVEBUFFER_USAGE_CPU_READ = (1ULL &lt;&lt; 0), NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL &lt;&lt; 1), NATIVEBUFFER_USAGE_MEM_DMA = (1ULL &lt;&lt; 3) } | OH_NativeBuffer的用途。 |
| [OH_NativeBuffer_Format](#oh_nativebuffer_format) {<br/>NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3, NATIVEBUFFER_PIXEL_FMT_RGBA_5658, NATIVEBUFFER_PIXEL_FMT_RGBX_4444, NATIVEBUFFER_PIXEL_FMT_RGBA_4444,<br/>NATIVEBUFFER_PIXEL_FMT_RGB_444, NATIVEBUFFER_PIXEL_FMT_RGBX_5551, NATIVEBUFFER_PIXEL_FMT_RGBA_5551, NATIVEBUFFER_PIXEL_FMT_RGB_555,<br/>NATIVEBUFFER_PIXEL_FMT_RGBX_8888, NATIVEBUFFER_PIXEL_FMT_RGBA_8888, NATIVEBUFFER_PIXEL_FMT_RGB_888, NATIVEBUFFER_PIXEL_FMT_BGR_565,<br/>NATIVEBUFFER_PIXEL_FMT_BGRX_4444, NATIVEBUFFER_PIXEL_FMT_BGRA_4444, NATIVEBUFFER_PIXEL_FMT_BGRX_5551, NATIVEBUFFER_PIXEL_FMT_BGRA_5551,<br/>NATIVEBUFFER_PIXEL_FMT_BGRX_8888, NATIVEBUFFER_PIXEL_FMT_BGRA_8888, NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF<br/>} | OH_NativeBuffer的格式。 |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Alloc](#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | 通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。 |
| [OH_NativeBuffer_Reference](#oh_nativebuffer_reference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 将OH_NativeBuffer对象的引用计数加1。 |
| [OH_NativeBuffer_Unreference](#oh_nativebuffer_unreference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉。 |
| [OH_NativeBuffer_GetConfig](#oh_nativebuffer_getconfig) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | 用于获取OH_NativeBuffer的属性。 |
| [OH_NativeBuffer_Map](#oh_nativebuffer_map) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, void \*\*virAddr) | 将OH_NativeBuffer对应的ION内存映射到进程空间。 |
| [OH_NativeBuffer_Unmap](#oh_nativebuffer_unmap) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 将OH_NativeBuffer对应的ION内存从进程空间移除。 |
| [OH_NativeBuffer_GetSeqNum](#oh_nativebuffer_getseqnum) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | 获取OH_NativeBuffer的序列号。 |


## 类型定义说明


### OH_NativeBuffer


```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**描述:**

提供OH_NativeBuffer结构体声明。

## 枚举类型说明


### OH_NativeBuffer_Format

```
enum OH_NativeBuffer_Format
```

**描述:**

OH_NativeBuffer的格式。

\@SysCap SystemCapability.Graphic.Graphic2D.NativeBuffer

| 枚举值 | 描述 |
| -------- | -------- |
| NATIVEBUFFER_PIXEL_FMT_RGB_565 | RGB565格式 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_5658 | RGBA5658格式 |
| NATIVEBUFFER_PIXEL_FMT_RGBX_4444 | RGBX4444格式 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_4444 | RGBA4444格式 |
| NATIVEBUFFER_PIXEL_FMT_RGB_444 | RGB444格式 |
| NATIVEBUFFER_PIXEL_FMT_RGBX_5551 | RGBX5551格式 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_5551 | RGBA5551格式 |
| NATIVEBUFFER_PIXEL_FMT_RGB_555 | RGB555格式 |
| NATIVEBUFFER_PIXEL_FMT_RGBX_8888 | RGBX8888格式 |
| NATIVEBUFFER_PIXEL_FMT_RGBA_8888 | RGBA8888格式 |
| NATIVEBUFFER_PIXEL_FMT_RGB_888 | RGB888格式 |
| NATIVEBUFFER_PIXEL_FMT_BGR_565 | BGR565格式 |
| NATIVEBUFFER_PIXEL_FMT_BGRX_4444 | BGRX4444格式 |
| NATIVEBUFFER_PIXEL_FMT_BGRA_4444 | BGRA4444格式 |
| NATIVEBUFFER_PIXEL_FMT_BGRX_5551 | BGRX5551格式 |
| NATIVEBUFFER_PIXEL_FMT_BGRA_5551 | BGRA5551格式 |
| NATIVEBUFFER_PIXEL_FMT_BGRX_8888 | BGRX8888格式 |
| NATIVEBUFFER_PIXEL_FMT_BGRA_8888 | BGRA8888格式 |
| NATIVEBUFFER_PIXEL_FMT_BUTT | 无效格式 |

**起始版本：**

10


### OH_NativeBuffer_Usage

```
enum OH_NativeBuffer_Usage
```

**描述:**

OH_NativeBuffer的用途。

\@SysCap SystemCapability.Graphic.Graphic2D.NativeBuffer

| 枚举值 | 描述 |
| -------- | -------- |
| NATIVEBUFFER_USAGE_CPU_READ | CPU可读 |
| NATIVEBUFFER_USAGE_CPU_WRITE | CPU可写 |
| NATIVEBUFFER_USAGE_MEM_DMA | 直接内存访问缓冲区 |

**起始版本：**

10


## 函数说明


### OH_NativeBuffer_Alloc()


```
OH_NativeBuffer* OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config * config)
```

**描述:**

通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| config | 一个指向OH_NativeBuffer_Config类型的指针。 |

**返回:**

创建成功则返回一个指向OH_NativeBuffer结构体实例的指针，否则返回NULL。


### OH_NativeBuffer_GetConfig()


```
void OH_NativeBuffer_GetConfig (OH_NativeBuffer * buffer, OH_NativeBuffer_Config * config )
```

**描述:**

用于获取OH_NativeBuffer的属性。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 |
| config | 一个指向OH_NativeBuffer_Config的指针，用于接收OH_NativeBuffer的属性。 |


### OH_NativeBuffer_GetSeqNum()


```
uint32_t OH_NativeBuffer_GetSeqNum (OH_NativeBuffer * buffer)
```

**描述:**

获取OH_NativeBuffer的序列号。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回:**

返回对应OH_NativeBuffer的唯一序列号。


### OH_NativeBuffer_Map()


```
int32_t OH_NativeBuffer_Map (OH_NativeBuffer * buffer, void ** virAddr )
```

**描述:**

将OH_NativeBuffer对应的ION内存映射到进程空间。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 |
| virAddr | 一个二级指针，二级指针指向映射到当前进程的虚拟内存的地址。 |

**返回:**

返回值为0表示执行成功。


### OH_NativeBuffer_Reference()


```
int32_t OH_NativeBuffer_Reference (OH_NativeBuffer * buffer)
```

**描述:**

将OH_NativeBuffer对象的引用计数加1。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回:**

返回值为0表示执行成功。


### OH_NativeBuffer_Unmap()


```
int32_t OH_NativeBuffer_Unmap (OH_NativeBuffer * buffer)
```

**描述:**

将OH_NativeBuffer对应的ION内存从进程空间移除。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回:**

返回值为0表示执行成功。


### OH_NativeBuffer_Unreference()


```
int32_t OH_NativeBuffer_Unreference (OH_NativeBuffer * buffer)
```

**描述:**

将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉。

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回:**

返回值为0表示执行成功。

# OH_NativeBuffer


## 概述

提供NativeBuffer功能，通过提供的接口，可以实现共享内存的申请、使用、属性查询、释放等操作。

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**起始版本:**

9


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [native_buffer.h](native__buffer_8h.md) | 定义获取和使用NativeBuffer的相关函数。<br/>引用文件：&lt;native_buffer/native_buffer.h&gt; |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) | 提供OH_NativeBuffer结构体声明。 |


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


## 函数说明


### OH_NativeBuffer_Alloc()


```
OH_NativeBuffer* OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config * config)
```

**描述:**

通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| buffer | 一个指向OH_NativeBuffer实例的指针。 |

**返回:**

返回值为0表示执行成功。

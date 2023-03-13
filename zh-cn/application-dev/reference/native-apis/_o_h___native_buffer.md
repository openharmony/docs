# OH_NativeBuffer


提供NativeBuffer功能


@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer


**起始版本：**


9


## 汇总


### 文件

| 文件名称 | 描述 |
| -------- | -------- |
| [native_buffer.h](native__buffer_8h.md) | 定义获取和使用NativeBuffer的相关函数<br>引用文件：<native_buffer/native_buffer.h> |


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | OH_NativeBuffer的属性配置，用于申请新的OH_NativeBuffer实例或查询现有实例的相关属性 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeBuffer_Alloc](#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | 通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例 |
| [OH_NativeBuffer_Reference](#oh_nativebuffer_reference) (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数加1 |
| [OH_NativeBuffer_Unreference](#oh_nativebuffer_unreference) (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉 |
| [OH_NativeBuffer_GetConfig](#oh_nativebuffer_getconfig) (OH_NativeBuffer \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | 用于获取OH_NativeBuffer的属性 |
| [OH_NativeBuffer_Map](#oh_nativebuffer_map) (OH_NativeBuffer \*buffer, void \*\*virAddr) | 将OH_NativeBuffer对应的ION内存映射到进程空间 |
| [OH_NativeBuffer_Unmap](#oh_nativebuffer_unmap) (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对应的ION内存从进程空间移除 |
| [OH_NativeBuffer_GetSeqNum](#oh_nativebuffer_getseqnum) (OH_NativeBuffer \*buffer) | 获取OH_NativeBuffer的序列号 |


## 详细描述


## 函数说明


### OH_NativeBuffer_Alloc()


```
OH_NativeBuffer* OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config * config)
```

**描述：**

通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例

@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数：**

| Name | 描述 |
| -------- | -------- |
| config | 参数是一个指向OH_NativeBuffer属性的指针，类型为OH_NativeBuffer_Config |

**返回：**

创建成功则返回一个指向OH_NativeBuffer结构体实例的指针，否则返回NULL

**起始版本：**

9


### OH_NativeBuffer_GetConfig()


```
void OH_NativeBuffer_GetConfig (OH_NativeBuffer * buffer, OH_NativeBuffer_Config * config )
```

**描述：**

用于获取OH_NativeBuffer的属性

@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个指向OH_NativeBuffer实例的指针 |
| config | 参数是一个指向OH_NativeBuffer_Config的指针，用于接收OH_NativeBuffer的属性 |

**起始版本：**

9


### OH_NativeBuffer_GetSeqNum()


```
uint32_t OH_NativeBuffer_GetSeqNum (OH_NativeBuffer * buffer)
```

**描述：**

获取OH_NativeBuffer的序列号

@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个指向OH_NativeBuffer实例的指针 |

**返回：**

返回对应OH_NativeBuffer的唯一序列号

**起始版本：**

9


### OH_NativeBuffer_Map()


```
int32_t OH_NativeBuffer_Map (OH_NativeBuffer * buffer, void ** virAddr )
```

**描述：**

将OH_NativeBuffer对应的ION内存映射到进程空间

@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个指向OH_NativeBuffer实例的指针 |
| virAddr | 参数是一个二级指针，二级指针指向虚拟内存的地址 |

**返回：**

返回一个由GSError定义的int32_t类型的错误码

**起始版本：**

9


### OH_NativeBuffer_Reference()


```
int32_t OH_NativeBuffer_Reference (OH_NativeBuffer * buffer)
```

**描述：**

将OH_NativeBuffer对象的引用计数加1

@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个指向OH_NativeBuffer实例的指针 |

**返回：**

返回一个由GSError定义的int32_t类型的错误码

**起始版本：**

9


### OH_NativeBuffer_Unmap()


```
int32_t OH_NativeBuffer_Unmap (OH_NativeBuffer * buffer)
```

**描述：**

将OH_NativeBuffer对应的ION内存从进程空间移除

@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个指向OH_NativeBuffer实例的指针 |

**返回：**

返回一个由GSError定义的int32_t类型的错误码

**起始版本：**

9


### OH_NativeBuffer_Unreference()


```
int32_t OH_NativeBuffer_Unreference (OH_NativeBuffer * buffer)
```

**描述：**

将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉

@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**参数：**

| Name | 描述 |
| -------- | -------- |
| buffer | 参数是一个指向OH_NativeBuffer实例的指针 |

**返回：**

返回一个由GSError定义的int32_t类型的错误码

**起始版本：**

9

# drawing_memory_stream.h

## 概述

文件中定义了与内存流相关的功能函数。

**引用文件：** <native_drawing/drawing_memory_stream.h>

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_MemoryStream* OH_Drawing_MemoryStreamCreate(const void* data, size_t length, bool copyData)](#oh_drawing_memorystreamcreate) | 创建一个内存流对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>data为NULL或者length等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_MemoryStreamDestroy(OH_Drawing_MemoryStream* memoryStream)](#oh_drawing_memorystreamdestroy) | 销毁内存流对象并回收该对象占有内存。 |

## 函数说明

### OH_Drawing_MemoryStreamCreate()

```
OH_Drawing_MemoryStream* OH_Drawing_MemoryStreamCreate(const void* data, size_t length, bool copyData)
```

**描述**

创建一个内存流对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>data为NULL或者length等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const void* data | 数据段。 |
| size_t length | 数据段长度。 |
| bool copyData | 是否拷贝数据。true表示内存流对象会拷贝一份数据段数据，false表示内存流对象直接使用数据段数据，不拷贝。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_MemoryStream](capi-oh-drawing-memorystream.md)* | 函数会返回一个指针，指针指向创建的内存流对象[OH_Drawing_MemoryStream](capi-oh-drawing-memorystream.md)。 |

### OH_Drawing_MemoryStreamDestroy()

```
void OH_Drawing_MemoryStreamDestroy(OH_Drawing_MemoryStream* memoryStream)
```

**描述**

销毁内存流对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_MemoryStream](capi-oh-drawing-memorystream.md)* memoryStream | 指向内存流对象[OH_Drawing_MemoryStream](capi-oh-drawing-memorystream.md)的指针。 |



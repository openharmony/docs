# drawing_path_iterator.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

声明与路径操作迭代器对象相关的函数。路径操作迭代器用于遍历路径中的操作指令（如移动、连线、贝塞尔曲线、闭合等），迭代器从路径起始位置依次遍历各操作指令，内部维护当前遍历位置。支持创建和销毁迭代器、判断是否还有下一个操作、读取下一个操作并将迭代器前移、查看下一个操作但不移动迭代器。通过迭代器可在不修改原始路径的情况下逐条读取路径操作信息。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** \<native_drawing/drawing_path_iterator.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 23

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_PathIteratorVerb](#oh_drawing_pathiteratorverb) | OH_Drawing_PathIteratorVerb | 迭代器包含的路径操作类型枚举，可用于读取路径的操作指令。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_ErrorCode OH_Drawing_PathIteratorCreate(const OH_Drawing_Path* path, OH_Drawing_PathIterator** pathIterator)](#oh_drawing_pathiteratorcreate) | 创建路径操作迭代器对象。使用完毕后，必须调用[OH_Drawing_PathIteratorDestroy](#oh_drawing_pathiteratordestroy)销毁迭代器对象并释放内存，否则会导致内存泄漏。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIteratorDestroy(OH_Drawing_PathIterator* pathIterator)](#oh_drawing_pathiteratordestroy) | 销毁路径操作迭代器对象并回收该对象占用的内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIteratorHasNext(const OH_Drawing_PathIterator* pathIterator, bool* hasNext)](#oh_drawing_pathiteratorhasnext) | 判断路径操作迭代器中是否还有下一个操作。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIteratorNext(OH_Drawing_PathIterator* pathIterator, OH_Drawing_Point2D* points, uint32_t count, uint32_t offset, OH_Drawing_PathIteratorVerb* verb)](#oh_drawing_pathiteratornext) | 返回当前路径的下一个操作，并将迭代器置于该操作。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIteratorPeek(const OH_Drawing_PathIterator* pathIterator, OH_Drawing_PathIteratorVerb* verb)](#oh_drawing_pathiteratorpeek) | 返回当前路径的下一个操作，迭代器保持在原操作。 |

## 枚举类型说明

### OH_Drawing_PathIteratorVerb

```c
enum OH_Drawing_PathIteratorVerb
```

**描述**

迭代器包含的路径操作类型枚举，可用于读取路径的操作指令。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| MOVE = 0 | 设置路径的起始点。 |
| LINE = 1 | 添加线段。 |
| QUAD = 2 | 添加二阶贝塞尔曲线。 |
| CONIC = 3 | 添加圆锥曲线。 |
| CUBIC = 4 | 添加三阶贝塞尔曲线。 |
| CLOSE = 5 | 闭合路径。 |
| DONE = CLOSE + 1  | 表示路径操作迭代结束。 |


## 函数说明

### OH_Drawing_PathIteratorCreate()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIteratorCreate(const OH_Drawing_Path* path, OH_Drawing_PathIterator** pathIterator)
```

**描述**

创建路径操作迭代器对象。使用完毕后，必须调用[OH_Drawing_PathIteratorDestroy](#oh_drawing_pathiteratordestroy)销毁迭代器对象并释放内存，否则会导致内存泄漏。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)** pathIterator | 指向路径操作迭代器对象[OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)的二级指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示path或pathIterator是空指针。 |

### OH_Drawing_PathIteratorDestroy()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIteratorDestroy(OH_Drawing_PathIterator* pathIterator)
```

**描述**

销毁路径操作迭代器对象并回收该对象占用的内存。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)* pathIterator | 指向需要销毁的路径操作迭代器对象[OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示pathIterator是空指针。 |

### OH_Drawing_PathIteratorHasNext()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIteratorHasNext(const OH_Drawing_PathIterator* pathIterator, bool* hasNext)
```

**描述**

判断路径操作迭代器中是否还有下一个操作。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)* pathIterator | 指向路径操作迭代器对象[OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)的指针，用于判断是否还有下一个操作。 |
| bool* hasNext | 表示路径操作迭代器中是否还有下一个操作。作为出参使用。true表示还有下一个操作，false表示没有下一个操作。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示pathIterator或hasNext是空指针。 |

### OH_Drawing_PathIteratorNext()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIteratorNext(OH_Drawing_PathIterator* pathIterator, OH_Drawing_Point2D* points, uint32_t count, uint32_t offset, OH_Drawing_PathIteratorVerb* verb)
```

**描述**

返回当前路径的下一个操作，并将迭代器置于该操作。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)* pathIterator | 指向路径操作迭代器对象[OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)的指针，调用后迭代器将前移到该操作位置。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* points | 表示坐标点数组，作为出参使用，用于接收下一个操作对应的坐标点，坐标点从数组的offset位置开始写入。调用者需预先分配大小不小于count的内存空间，否则可能导致内存越界写入。 |
| uint32_t count | 表示坐标点数组的元素个数。 |
| uint32_t offset | 表示数组中写入坐标点的起始位置相对数组起始位置（索引0）的偏移量，取值范围为[0, count-4]。 |
| [OH_Drawing_PathIteratorVerb](#oh_drawing_pathiteratorverb)* verb | 表示当前路径的下一个操作。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示pathIterator或points或verb是空指针。<br>返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示count小于offset + 4。 |

### OH_Drawing_PathIteratorPeek()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIteratorPeek(const OH_Drawing_PathIterator* pathIterator, OH_Drawing_PathIteratorVerb* verb)
```

**描述**

返回当前路径的下一个操作，迭代器保持在原操作。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [const OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)* pathIterator | 指向路径操作迭代器对象[OH_Drawing_PathIterator](capi-drawing-oh-drawing-pathiterator.md)的指针。 |
| [OH_Drawing_PathIteratorVerb](#oh_drawing_pathiteratorverb)* verb | 表示当前路径的下一个操作。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示pathIterator或verb是空指针。 |
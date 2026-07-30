# drawing_gpu_context.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

声明与绘图模块中的图形处理器上下文对象相关的函数，用于创建、配置和销毁图形处理器上下文对象，为绘图模块提供图形处理器加速渲染所需的上下文环境。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** \<native_drawing/drawing_gpu_context.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_GpuContextOptions](capi-drawing-oh-drawing-gpucontextoptions.md) | OH_Drawing_GpuContextOptions | 定义有关图形处理器上下文的选项。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_GpuContext* OH_Drawing_GpuContextCreateFromGL(OH_Drawing_GpuContextOptions gpuContextOptions)](#oh_drawing_gpucontextcreatefromgl) | 用于创建一个使用OpenGL作为后端接口的图形处理器上下文对象。创建的图形处理器上下文对象使用完毕后，需要调用[OH_Drawing_GpuContextDestroy](#oh_drawing_gpucontextdestroy)销毁并回收内存。 |
| [OH_Drawing_GpuContext* OH_Drawing_GpuContextCreate(void)](#oh_drawing_gpucontextcreate) | 用于创建一个图形处理器上下文对象，使用的后端类型取决于运行设备。创建的图形处理器上下文对象使用完毕后，需要调用[OH_Drawing_GpuContextDestroy](#oh_drawing_gpucontextdestroy)销毁并回收内存。 |
| [void OH_Drawing_GpuContextDestroy(OH_Drawing_GpuContext* gpuContext)](#oh_drawing_gpucontextdestroy) | 用于销毁图形处理器上下文对象并回收该对象占用的内存。调用后该图形处理器上下文对象指针失效，不可再次使用或重复调用。 |

## 函数说明

### OH_Drawing_GpuContextCreateFromGL()

```c
OH_Drawing_GpuContext* OH_Drawing_GpuContextCreateFromGL(OH_Drawing_GpuContextOptions gpuContextOptions)
```

**描述**

用于创建一个使用OpenGL作为后端接口的图形处理器上下文对象。创建的图形处理器上下文对象使用完毕后，需要调用[OH_Drawing_GpuContextDestroy](#oh_drawing_gpucontextdestroy)销毁并回收内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**废弃版本：** 18

**替代接口：** [OH_Drawing_GpuContextCreate](capi-drawing-gpu-context-h.md#oh_drawing_gpucontextcreate)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_GpuContextOptions](capi-drawing-oh-drawing-gpucontextoptions.md) gpuContextOptions | 图形处理器上下文选项[OH_Drawing_GpuContextOptions](capi-drawing-oh-drawing-gpucontextoptions.md)，用于配置所创建的图形处理器上下文对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)* | 返回指向创建的图形处理器上下文对象[OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)的指针。 |

### OH_Drawing_GpuContextCreate()

```c
OH_Drawing_GpuContext* OH_Drawing_GpuContextCreate(void)
```

**描述**

用于创建一个图形处理器上下文对象，使用的后端类型取决于运行设备。创建的图形处理器上下文对象使用完毕后，需要调用[OH_Drawing_GpuContextDestroy](#oh_drawing_gpucontextdestroy)销毁并回收内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 16

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)* | 返回指向创建的图形处理器上下文对象[OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)的指针。 |

### OH_Drawing_GpuContextDestroy()

```c
void OH_Drawing_GpuContextDestroy(OH_Drawing_GpuContext* gpuContext)
```

**描述**

用于销毁图形处理器上下文对象并回收该对象占用的内存。调用后该图形处理器上下文对象指针失效，不可再次使用或重复调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)* gpuContext | 指向图形处理器上下文对象的指针。调用后该指针失效，不可再次使用，否则可能导致未定义行为或程序崩溃。 |




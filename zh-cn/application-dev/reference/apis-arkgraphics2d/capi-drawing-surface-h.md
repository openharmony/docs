# drawing_surface.h

## 概述

文件中定义与surface相关的功能函数，包括surface的创建、销毁和使用等。

**引用文件：** <native_drawing/drawing_surface.h>

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Surface* OH_Drawing_SurfaceCreateFromGpuContext(OH_Drawing_GpuContext* gpuContext, bool flag, OH_Drawing_Image_Info imageInfo)](#oh_drawing_surfacecreatefromgpucontext) | 使用图形处理器上下文创建一个surface对象，用于管理画布绘制的内容。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>gpuContext为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_Surface* OH_Drawing_SurfaceCreateOnScreen(OH_Drawing_GpuContext* gpuContext, OH_Drawing_Image_Info imageInfo, void* window)](#oh_drawing_surfacecreateonscreen) | 使用图形处理器上下文创建一个与屏幕窗口绑定的surface对象，用于管理画布绘制的内容。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>gpuContext或window为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_Canvas* OH_Drawing_SurfaceGetCanvas(OH_Drawing_Surface* surface)](#oh_drawing_surfacegetcanvas) | 通过surface对象获取画布对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>surface为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_SurfaceFlush(OH_Drawing_Surface* surface)](#oh_drawing_surfaceflush) | 将surface对象上的画布绘制内容提交给GPU处理，完成绘制内容上屏显示。 |
| [void OH_Drawing_SurfaceDestroy(OH_Drawing_Surface* surface)](#oh_drawing_surfacedestroy) | 销毁surface对象并回收该对象占用的内存。 |

## 函数说明

### OH_Drawing_SurfaceCreateFromGpuContext()

```
OH_Drawing_Surface* OH_Drawing_SurfaceCreateFromGpuContext(OH_Drawing_GpuContext* gpuContext, bool flag, OH_Drawing_Image_Info imageInfo)
```

**描述**

使用图形处理器上下文创建一个surface对象，用于管理画布绘制的内容。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>gpuContext为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)* gpuContext | 指向图形处理器上下文对象的指针[OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)。 |
| bool flag | 用于控制内存分配是否计入缓存预算。true则计入高速缓存预算，false则不计入高速缓存预算。 |
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md) imageInfo | 图片信息[OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)结构体。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)* | 返回一个指针，指针指向创建的surface对象[OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)。 |

### OH_Drawing_SurfaceCreateOnScreen()

```
OH_Drawing_Surface* OH_Drawing_SurfaceCreateOnScreen(OH_Drawing_GpuContext* gpuContext, OH_Drawing_Image_Info imageInfo, void* window)
```

**描述**

使用图形处理器上下文创建一个与屏幕窗口绑定的surface对象，用于管理画布绘制的内容。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>gpuContext或window为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 16


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)* gpuContext | 指向图形处理器上下文对象的指针[OH_Drawing_GpuContext](capi-drawing-oh-drawing-gpucontext.md)。<br>该图形处理器上下文对象必须由[OH_Drawing_GpuContextCreate](capi-drawing-gpu-context-h.md#oh_drawing_gpucontextcreate)创建，否则surface对象会创建失败。 |
| [OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md) imageInfo | 图片信息[OH_Drawing_Image_Info](capi-drawing-oh-drawing-image-info.md)结构体。 |
| void* window | 指向屏幕窗口对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)* | 返回一个指针，指针指向创建的surface对象[OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)。 |

### OH_Drawing_SurfaceGetCanvas()

```
OH_Drawing_Canvas* OH_Drawing_SurfaceGetCanvas(OH_Drawing_Surface* surface)
```

**描述**

通过surface对象获取画布对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>surface为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)* surface | 指向创建的surface对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)* | 返回一个指针，指针指向创建的画布对象[OH_Drawing_Canvas](capi-drawing-oh-drawing-canvas.md)。返回的指针不需要由调用者管理。 |

### OH_Drawing_SurfaceFlush()

```
OH_Drawing_ErrorCode OH_Drawing_SurfaceFlush(OH_Drawing_Surface* surface)
```

**描述**

将surface对象上的画布绘制内容提交给GPU处理，完成绘制内容上屏显示。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 16


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)* surface | 指向创建的surface对象的指针[OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)。该surface对象必须由[OH_Drawing_SurfaceCreateOnScreen](capi-drawing-surface-h.md#oh_drawing_surfacecreateonscreen)创建，否则该接口调用将没有任何效果。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数surface为空。 |

### OH_Drawing_SurfaceDestroy()

```
void OH_Drawing_SurfaceDestroy(OH_Drawing_Surface* surface)
```

**描述**

销毁surface对象并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Surface](capi-drawing-oh-drawing-surface.md)* surface | 指向创建的surface对象的指针。 |



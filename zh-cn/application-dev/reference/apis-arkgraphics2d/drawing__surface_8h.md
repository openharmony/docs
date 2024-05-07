# drawing_surface.h


## 概述

文件中定义与surface相关的功能函数，包括surface的创建、销毁和使用等。

**引用文件：**&lt;native_drawing/drawing_surface.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Surface](_drawing.md#oh_drawing_surface) \* [OH_Drawing_SurfaceCreateFromGpuContext](_drawing.md#oh_drawing_surfacecreatefromgpucontext) ([OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \*, bool budgeted, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)) | 使用图形处理器上下文创建一个surface对象，用于管理画布绘制的内容。 | 
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \* [OH_Drawing_SurfaceGetCanvas](_drawing.md#oh_drawing_surfacegetcanvas) ([OH_Drawing_Surface](_drawing.md#oh_drawing_surface) \*) | 通过surface对象获取画布对象。 | 
| void [OH_Drawing_SurfaceDestroy](_drawing.md#oh_drawing_surfacedestroy) ([OH_Drawing_Surface](_drawing.md#oh_drawing_surface) \*) | 销毁surface对象并回收该对象占用的内存。 | 

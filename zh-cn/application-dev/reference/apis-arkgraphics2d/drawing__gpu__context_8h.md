# drawing_gpu_context.h


## 概述

声明与绘图模块中的图形处理器上下文对象相关的函数。

**引用文件：**&lt;native_drawing/drawing_gpu_context.h&gt;

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md) | 定义有关图形处理器上下文的选项。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)  [OH_Drawing_GpuContextOptions](_drawing.md#oh_drawing_gpucontextoptions) | 定义有关图形处理器上下文的选项。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \* [OH_Drawing_GpuContextCreateFromGL](_drawing.md#oh_drawing_gpucontextcreatefromgl) ([OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)) | 用于创建一个使用OpenGL作为后端接口的图形处理器上下文对象。 | 
| [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \* [OH_Drawing_GpuContextCreate](_drawing.md#oh_drawing_gpucontextcreate) (void) | 用于创建一个图形处理器上下文对象, 使用的后端类型取决于运行设备。  | 
| void [OH_Drawing_GpuContextDestroy](_drawing.md#oh_drawing_gpucontextdestroy) ([OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \*) | 用于销毁图形处理器上下文对象并回收该对象占用的内存。 | 

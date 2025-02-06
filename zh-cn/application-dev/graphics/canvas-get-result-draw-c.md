# 画布的获取与绘制结果的显示（C/C++）


## 场景介绍

Canvas即画布，提供绘制基本图形的能力，用于在屏幕上绘制图形和处理图形。开发者可以通过Canvas实现自定义的绘图效果，增强应用的用户体验。

Canvas是图形绘制的核心，本章中提到的所有绘制操作（包括基本图形的绘制、文字的绘制、图片的绘制、图形变换等）都是基于Canvas的。

目前C/C++有两种获取Canvas的方式：获取可直接上屏显示的Canvas、获取离屏的Canvas，前者在调用绘制接口之后无需进行额外的操作即可完成绘制结果的上屏显示，而后者需要依靠已有的显示手段来显示绘制结果。


## 接口说明

创建Canvas常用接口如下表所示，详细的使用和参数说明请见[drawing_canvas.h](../reference/apis-arkgraphics2d/drawing__canvas_8h.md)。

| 接口 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas\* OH_Drawing_CanvasCreate (void) | 用于创建一个画布对象。 |
| void OH_Drawing_CanvasBind (OH_Drawing_Canvas\*, OH_Drawing_Bitmap\*) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中。 |
| OH_Drawing_Canvas\* OH_Drawing_SurfaceGetCanvas (OH_Drawing_Surface \*) | 通过surface对象获取画布对象。 |


## 获取可直接显示的Canvas画布

通过XComponent获取可直接显示的Canvas画布。

1. 从XComponent对应的NativeWindow中获取BufferHandle对象。NativeWindow相关的API请参考[_native_window](../reference/apis-arkgraphics2d/_native_window.md)。

   ```c++
   uint64_t widht, height;
   OHNativeWindow *nativeWindow;    // NativeWindow及其宽高需要从XComponent获取
   int32_t usage = NATIVEBUFFER_USAGE_CPU_READ | NATIVEBUFFER_USAGE_CPU_WRITE | NATIVEBUFFER_USAGE_MEM_DMA;
   int ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, SET_USAGE, usage);
   if (ret != 0) {
       return;
   }
   
   struct NativeWindowBuffer *buffer = nullptr;
   int fenceFd = 0;
   ret = OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &fenceFd);
   if (ret != 0) {
       return;
   }
   
   BufferHandle* bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
   ```

2. 从BufferHandle中获取对应的内存地址。

   ```c++
   uint32_t* mappedAddr = static_cast<uint32_t *>(mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0));
   ```

3. 创建窗口画布。

   ```c++
   OH_Drawing_Image_Info screenImageInfo = {static_cast<int32_t>(width), static_cast<int32_t>(height), COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUE};
   OH_Drawing_Bitmap* screenBitmap = OH_Drawing_BitmapCreateFromPixels(&screenImageInfo, mappedAddr, bufferHandle->stride);
   OH_Drawing_Canvas* screenCanvas = OH_Drawing_CanvasCreate();
   OH_Drawing_CanvasBind(screenCanvas, screenBitmap);
   ```

4. 利用上一步中得到的Canvas进行自定义的绘制操作，即本章下文中的内容。

5. 利用XComponent完成显示。

   ```c++
   Region region {nullptr, 0};
   OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
   ```


## 离屏Canvas画布的获取与显示

目前有两种创建离屏Canvas的方式：创建CPU后端Canvas、创建GPU后端Canvas，这两种Canvas都需要依靠XComponent来完成绘制结果的上屏显示。由于历史原因，早期的Canvas都是CPU后端Canvas。目前已经支持GPU后端Canvas，GPU的并行计算能力更强，更适合图形绘制。但GPU后端Canvas对部分场景的支持还有欠缺，比如复杂的路径，对于简短文字的绘制性能也比不上CPU后端Canvas。


### CPU后端Canvas的创建与显示

目前C/C++接口的绘制需要依赖于NativeWindow，CPU后端Canvas需要先离屏绘制，生成位图（Bitmap），再借助XComponent将位图上屏。


1. 导入依赖的相关头文件。

   ```c++
   #include <native_drawing/drawing_canvas.h>
   #include <native_drawing/drawing_bitmap.h>
   ```

2. 创建基于CPU的Canvas。需要通过OH_Drawing_BitmapCreate()接口创建一个位图对象（具体可参考[图片绘制](pixelmap-drawing-c.md)），并通过OH_Drawing_CanvasBind()接口将位图绑定到Canvas中，从而使得Canvas绘制的内容可以输出到位图中。

   ```c++
   // 创建一个位图对象
   OH_Drawing_Bitmap* bitmap = OH_Drawing_BitmapCreate();
   OH_Drawing_BitmapFormat cFormat{COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_PREMUL};
   // 设置位图长宽（按需设置）
   uint32_t width = 800;
   uint32_t height = 800;
   // 初始化位图
   OH_Drawing_BitmapBuild(bitmap, width, height, &cFormat);
   // 创建一个Canvas对象
   OH_Drawing_Canvas* bitmapCanvas = OH_Drawing_CanvasCreate();
   // 将Canvas与bitmap绑定，Canvas绘制的内容会输出到绑定的bitmap内存中
   OH_Drawing_CanvasBind(bitmapCanvas, bitmap);
   ```

   如果需要将背景设置为白色，需要执行以下步骤：

   ```c++
   OH_Drawing_CanvasClear(bitmapCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```

3. 将上一步中创建的位图绘制到[窗口画布](#获取可直接显示的canvas画布)上。

   ```c++
   OH_Drawing_CanvasDrawBitmap(screenCanvas, bitmap, 0, 0);
   ```


### GPU后端Canvas的创建与显示

GPU后端Canvas指画布是基于GPU进行绘制的，GPU的并行计算能力优于CPU，适用于绘制图片或区域相对大的场景，但目前GPU后端的Canvas针对绘制复杂路径的能力还有欠缺。同CPU后端Canvas，目前C/C++接口的绘制需要依赖于XComponent，GPU后端Canvas需要先离屏绘制再借助XComponent上屏。

1. 导入依赖的头文件。

   ```c++
   #include <native_drawing/drawing_gpu_context.h>
   #include <native_drawing/drawing_surface.h>
   ```

2. 创建GPU后端Cnavas。GPU后端Canvas需要借助Surface对象来获取，需先创建surface，surface的API请参考[drawing_surface.h](../reference/apis-arkgraphics2d/drawing__surface_8h.md)。目前drawing支持基于OpenGL的GPU后端绘制，所以需要先通过OH_Drawing_GpuContextCreateFromGL接口创建绘图上下文，再将这个上下文作为参数创建surface，最后通过OH_Drawing_SurfaceGetCanvas接口从surface中获取到canvas。

   ```c++
   // 设置宽高（按需设定）
   int32_t cWidth = 800;
   int32_t cHeight = 800;
   // 设置图像，包括宽度、高度、颜色格式和透明度格式
   OH_Drawing_Image_Info imageInfo = {cWidth, cHeight, COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_PREMUL};
   // GPU上下文的选项
   OH_Drawing_GpuContextOptions options{false};
   // 创建一个使用OpenGL（GL）作为其GPU后端的绘图上下文
   OH_Drawing_GpuContext *gpuContext = OH_Drawing_GpuContextCreateFromGL(options);
   // 创建surface对象
   OH_Drawing_Surface *surface = OH_Drawing_SurfaceCreateFromGpuContext(gpuContext, true, imageInfo);
   // 创建一个canvas对象
   OH_Drawing_Canvas* gpuCanvas = OH_Drawing_SurfaceGetCanvas(surface);
   ```

   如果需要将背景设置为白色，需要执行以下步骤：

   ```c++
   OH_Drawing_CanvasClear(gpuCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```

3. 将上一步中的绘制结果拷贝到[窗口画布](#获取可直接显示的canvas画布)上。

   ```c++
   void* dstPixels = malloc(cWidth * cHeight * 4); // 4 for rgba
   OH_Drawing_CanvasReadPixels(gpuCanvas, &imageInfo, dstPixels, 4 * cWidth, 0, 0);
   OH_Drawing_Bitmap* bitmap = OH_Drawing_BitmapCreateFromPixels(&imageInfo, dstPixels, 4 * cWidth);
   OH_Drawing_CanvasDrawBitmap(screenCanvas, bitmap, 0, 0);
   ```

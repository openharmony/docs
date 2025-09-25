# 画布的获取与绘制结果的显示（C/C++）

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 场景介绍

Canvas即画布，提供绘制基本图形的能力，用于在屏幕上绘制图形和处理图形。开发者可以通过Canvas实现自定义的绘图效果，增强应用的用户体验。

Canvas是图形绘制的核心，本章中提到的所有绘制操作（包括基本图形的绘制、文字的绘制、图片的绘制、图形变换等）都是基于Canvas的。

目前C/C++有两种获取Canvas的方式：获取可直接上屏显示的Canvas、获取离屏的Canvas，前者在调用绘制接口之后无需进行额外的操作即可完成绘制结果的上屏显示，而后者需要依靠已有的显示手段来显示绘制结果。


## 接口说明

创建Canvas常用接口如下表所示，详细的使用和参数说明请见[drawing_canvas.h](../reference/apis-arkgraphics2d/capi-drawing-canvas-h.md)。

| 接口 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas\* OH_Drawing_CanvasCreate (void) | 用于创建一个画布对象。 |
| void OH_Drawing_CanvasBind (OH_Drawing_Canvas\*, OH_Drawing_Bitmap\*) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中。 |
| OH_Drawing_Canvas\* OH_Drawing_SurfaceGetCanvas (OH_Drawing_Surface \*) | 通过surface对象获取画布对象。 |


## 获取可直接显示的Canvas画布

通过XComponent获取可直接显示的Canvas画布。

1. 添加链接库。

   在Native工程的src/main/cpp/CMakeLists.txt，添加如下链接库：

   ```c++
   target_link_libraries(entry PUBLIC libnative_drawing.so)
   ```
   <!-- [ndk_graphics_draw_cmake_drawing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/CMakeLists.txt) -->

2. 导入依赖的相关头文件。

   ```c++
   #include <native_drawing/drawing_canvas.h>
   ```
   <!-- [ndk_graphics_draw_include_native_drawing_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

   ```c++
   #include <native_drawing/drawing_surface.h>
   ```
   <!-- [ndk_graphics_draw_include_native_drawing_surface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

3. 从XComponent对应的NativeWindow中获取BufferHandle对象。NativeWindow相关的API请参考[_native_window](../reference/apis-arkgraphics2d/capi-nativewindow.md)。

   ```c++
   uint64_t width, height;
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
   <!-- [ndk_graphics_draw_get_buffer_handle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

4. 从BufferHandle中获取对应的内存地址。

   ```c++
   uint32_t* mappedAddr = static_cast<uint32_t *>(mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0));
   ```
   <!-- [ndk_graphics_draw_get_mapped_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

5. 创建窗口画布。

   ```c++
   // 创建bitmap的方式一：使用OH_Drawing_BitmapCreateFromPixels创建OH_Drawing_Bitmap*类型的cScreenBitmap_
   // OH_Drawing_Image_Info screenImageInfo = {static_cast<int32_t>(width), static_cast<int32_t>(height), COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUE};
   // OH_Drawing_Bitmap* cScreenBitmap_ = OH_Drawing_BitmapCreateFromPixels(&screenImageInfo, mappedAddr, bufferHandle->stride); 
   // 创建bitmap的方式二：使用OH_Drawing_BitmapCreate创建OH_Drawing_Bitmap*类型的cScreenBitmap_
   cScreenBitmap_ = OH_Drawing_BitmapCreate();
   // 定义bitmap的像素格式
   OH_Drawing_BitmapFormat cFormat{COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUE};
   // 构造对应格式的bitmap
   uint32_t width = static_cast<uint32_t>(bufferHandle_->stride / 4);
   OH_Drawing_BitmapBuild(cScreenBitmap_, width, height_, &cFormat);
   OH_Drawing_Canvas* screenCanvas = OH_Drawing_CanvasCreate();
   OH_Drawing_CanvasBind(screenCanvas, cScreenBitmap_);
   ```
   <!-- [ndk_graphics_draw_create_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

6. 利用上一步中得到的Canvas进行自定义的绘制操作，即本章下文中的内容。

7. 利用XComponent完成显示。

   ```c++
   Region region {nullptr, 0};
   OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
   ```
   <!-- [ndk_graphics_draw_native_window_flush_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->


## 离屏Canvas画布的获取与显示

目前有两种创建离屏Canvas的方式：创建CPU后端Canvas、创建GPU后端Canvas，这两种Canvas都需要依靠XComponent来完成绘制结果的上屏显示。由于历史原因，早期的Canvas都是CPU后端Canvas。目前已经支持GPU后端Canvas，GPU的并行计算能力更强，更适合图形绘制。但GPU后端Canvas对部分场景的支持还有欠缺，比如复杂的路径，对于简短文字的绘制性能也比不上CPU后端Canvas。


### CPU后端Canvas的创建与显示

目前C/C++接口的绘制需要依赖于NativeWindow，CPU后端Canvas需要先离屏绘制，生成位图或像素图（从API Version 20开始支持），再借助XComponent上屏。


方式一：通过绑定位图（Bitmap）的方式创建Canvas。
1. 导入依赖的相关头文件。

   ```c++
   #include <native_drawing/drawing_canvas.h>
   #include <native_drawing/drawing_bitmap.h>
   ```
   <!-- [ndk_graphics_draw_include_native_drawing_canvas_and_bitmap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

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
   <!-- [ndk_graphics_draw_create_canvas_by_cpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   如果需要将背景设置为白色，需要执行以下步骤：

   ```c++
   OH_Drawing_CanvasClear(bitmapCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```
   <!-- [ndk_graphics_draw_clear_canvas_cpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

3. 将上一步中创建的位图绘制到[窗口画布](#获取可直接显示的canvas画布)上。

   ```c++
   OH_Drawing_CanvasDrawBitmap(screenCanvas, bitmap, 0, 0);
   ```
   <!-- [ndk_graphics_draw_drawing_to_window_canvas_cpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->



方式二：通过像素图（PixelMap）创建Canvas。从API Version 20开始，支持使用此种方式创建Canvas。
像素图是系统中用来表示图片的统一的数据结构，相比于drawing模块中提供的位图，像素图具备通用性，并且能够更好地发挥系统的能力。

1. 添加链接库。

   在Native工程的src/main/cpp/CMakeLists.txt，添加如下链接库：

   ```c++
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)
   ```
   <!-- [ndk_graphics_draw_cmake_pixelmap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/CMakeLists.txt) -->

2. 导入依赖的相关头文件。

   ```c++
   #include <multimedia/image_framework/image/pixelmap_native.h>
   ```
   <!-- [ndk_graphics_draw_include_pixelmap_native](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ```c++
   #include <native_drawing/drawing_pixel_map.h>
   ```
   <!-- [ndk_graphics_draw_include_drawing_pixel_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->


3. 需要通过OH_Drawing_PixelMapGetFromOhPixelMapNative()接口创建一个像素图对象（具体可参考[图片绘制](pixelmap-drawing-c.md)），并通过OH_Drawing_CanvasCreateWithPixelMap()接口借助像素图对象创建Canvas。

   ```c++
   // 图片宽高
   uint32_t width = 600;
   uint32_t height = 400;
   // 设置位图格式（长、宽、颜色类型、透明度类型）
   OH_Pixelmap_InitializationOptions *createOps = nullptr;
   OH_PixelmapInitializationOptions_Create(&createOps);
   OH_PixelmapInitializationOptions_SetWidth(createOps, width);
   OH_PixelmapInitializationOptions_SetHeight(createOps, height);
   OH_PixelmapInitializationOptions_SetPixelFormat(createOps, PIXEL_FORMAT_RGBA_8888);
   OH_PixelmapInitializationOptions_SetAlphaType(createOps, PIXELMAP_ALPHA_TYPE_UNKNOWN);
   // 字节长度，RGBA_8888每个像素占4字节
   size_t bufferSize = width * height * 4;
   void *buffer = malloc(bufferSize);
   // 创建OH_PixelmapNative对象
   OH_PixelmapNative *pixelMapNative = nullptr;
   OH_PixelmapNative_CreatePixelmap(static_cast<uint8_t *>(buffer), bufferSize, createOps, &pixelMapNative);
   // 创建Pixelmap对象
   OH_Drawing_PixelMap *pixelMap = OH_Drawing_PixelMapGetFromOhPixelMapNative(pixelMapNative);
   // 创建Canvas对象
   OH_Drawing_Canvas* pixelmapCanvas = OH_Drawing_CanvasCreateWithPixelMap(pixelMap);
   ```
   <!-- [ndk_graphics_draw_image](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   如果需要将背景设置为白色，需要执行以下步骤：

   ```c++
   OH_Drawing_CanvasClear(pixelmapCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```

4. 将上一步中创建的像素图绘制到[窗口画布](#获取可直接显示的canvas画布)上。

   ```c++
   // PixelMap中像素的截取区域
   OH_Drawing_Rect *src = OH_Drawing_RectCreate(0, 0, width, height);
   // 画布中显示的区域
   OH_Drawing_Rect *dst = OH_Drawing_RectCreate(0, 0, width, height);
   // 采样选项对象
   OH_Drawing_SamplingOptions* samplingOptions = OH_Drawing_SamplingOptionsCreate(
       OH_Drawing_FilterMode::FILTER_MODE_LINEAR, OH_Drawing_MipmapMode::MIPMAP_MODE_LINEAR);
   // 绘制PixelMap
   OH_Drawing_CanvasDrawPixelMapRect(screenCanvas, pixelMap, src, dst, samplingOptions);
   ```
   <!-- [ndk_graphics_draw_image_to_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->


### GPU后端Canvas的创建与显示

GPU后端Canvas指画布是基于GPU进行绘制的，GPU的并行计算能力优于CPU，适用于绘制图片或区域相对大的场景，但目前GPU后端的Canvas针对绘制复杂路径的能力还有欠缺。同CPU后端Canvas，目前C/C++接口的绘制需要依赖于XComponent，GPU后端Canvas需要先离屏绘制再借助XComponent上屏。

1. 当前创建GPU后端的Canvas依赖EGL的能力，需要在CMakeList.txt中添加EGL的动态依赖库。

   ```c++
   libEGL.so
   ```
   <!-- [ndk_graphics_draw_cmake_EGL](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/CMakeLists.txt) -->

2. 导入依赖的头文件。

   ```c++
   #include <EGL/egl.h>
   #include <EGL/eglext.h>
   ```
   <!-- [ndk_graphics_draw_include_egl_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

   ```c++
   #include <native_drawing/drawing_gpu_context.h>
   #include <native_drawing/drawing_surface.h>
   ```
   <!-- [ndk_graphics_draw_include_native_drawing_surface_and_gpu_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

3. 初始化EGL上下文。

   ```c++
   // 初始化上下文相关参数
   EGLDisplay mEGLDisplay = EGL_NO_DISPLAY;
   EGLConfig mEGLConfig = nullptr;
   EGLContext mEGLContext = EGL_NO_CONTEXT;
   EGLSurface mEGLSurface = nullptr;
   ```
   <!-- [ndk_graphics_draw_initialize_egl_context_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

   ```c++
   // 初始化上下文相关配置
   EGLConfig getConfig(int version, EGLDisplay eglDisplay)
   {
      int attribList[] = {EGL_SURFACE_TYPE,
                           EGL_WINDOW_BIT,
                           EGL_RED_SIZE,
                           8,
                           EGL_GREEN_SIZE,
                           8,
                           EGL_BLUE_SIZE,
                           8,
                           EGL_ALPHA_SIZE,
                           8,
                           EGL_RENDERABLE_TYPE,
                           EGL_OPENGL_ES2_BIT,
                           EGL_NONE};
      EGLConfig configs = NULL;
      int configsNum;

      if (!eglChooseConfig(eglDisplay, attribList, &configs, 1, &configsNum)) {
         return NULL;
      }

      return configs;
   }

   // 在需要初始化EGL上下文处调用InitializeEglContext
   int32_t InitializeEglContext(EGLDisplay mEGLDisplay, EGLConfig mEGLConfig,
      EGLContext mEGLContext, EGLSurface mEGLSurface)
   {
      mEGLDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
      if (mEGLDisplay == EGL_NO_DISPLAY) {
         return -1;
      }

      EGLint eglMajVers;
      EGLint eglMinVers;
      if (!eglInitialize(mEGLDisplay, &eglMajVers, &eglMinVers)) {
         mEGLDisplay = EGL_NO_DISPLAY;
         return -1;
      }

      int version = 3;
      mEGLConfig = getConfig(version, mEGLDisplay);
      if (mEGLConfig == nullptr) {
         return -1;
      }

      int attribList[] = {EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE};

      mEGLContext = eglCreateContext(mEGLDisplay, mEGLConfig, EGL_NO_CONTEXT, attribList);

      EGLint attribs[] = {EGL_WIDTH, 1, EGL_HEIGHT, 1, EGL_NONE};
      mEGLSurface = eglCreatePbufferSurface(mEGLDisplay, mEGLConfig, attribs);
      if (!eglMakeCurrent(mEGLDisplay, mEGLSurface, mEGLSurface, mEGLContext)) {
         return -1;
      }
      
      return 0;
   }
   ```
   <!-- [ndk_graphics_draw_initialize_egl_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

4. 创建GPU后端Canvas。GPU后端Canvas需要借助Surface对象来获取，需先创建surface，surface的API请参考[drawing_surface.h](../reference/apis-arkgraphics2d/capi-drawing-surface-h.md)。通过OH_Drawing_GpuContextCreateFromGL接口创建绘图上下文，再将这个上下文作为参数创建surface，最后通过OH_Drawing_SurfaceGetCanvas接口从surface中获取到canvas。

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
   <!-- [ndk_graphics_draw_create_canvas_by_gpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   如果需要将背景设置为白色，需要执行以下步骤：

   ```c++
   OH_Drawing_CanvasClear(gpuCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```
   <!-- [ndk_graphics_draw_clear_canvas_gpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

5. 将上一步中的绘制结果拷贝到[窗口画布](#获取可直接显示的canvas画布)上。

   ```c++
   void* dstPixels = malloc(cWidth * cHeight * 4); // 4 for rgba
   OH_Drawing_CanvasReadPixels(gpuCanvas, &imageInfo, dstPixels, 4 * cWidth, 0, 0);
   OH_Drawing_Bitmap* bitmap = OH_Drawing_BitmapCreateFromPixels(&imageInfo, dstPixels, 4 * cWidth);
   OH_Drawing_CanvasDrawBitmap(screenCanvas, bitmap, 0, 0);
   ```
   <!-- [ndk_graphics_draw_drawing_to_window_canvas_gpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

6. 使用完之后需要将EGL上下文销毁。

   ```c++
   // 在需要销毁处调用DeInitializeEglContext销毁EGL上下文。
   void DeInitializeEglContext(EGLDisplay mEGLDisplay, EGLContext mEGLContext, EGLSurface mEGLSurface)
   {
      // 以下三个方法都有返回值判断是否销毁成功，必要时可进行调试。
      eglDestroySurface(mEGLDisplay, mEGLSurface);
      eglDestroyContext(mEGLDisplay, mEGLContext);
      eglTerminate(mEGLDisplay);

      mEGLSurface = NULL;
      mEGLContext = NULL;
      mEGLDisplay = NULL;
   }
   ```
   <!-- [ndk_graphics_draw_deinitialize_egl_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

<!--RP1-->
## 相关实例

针对Drawing(C/C++)的开发，有以下相关实例可供参考：

- [NDKGraphicsDraw (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKGraphicsDraw)
<!--RP1End-->
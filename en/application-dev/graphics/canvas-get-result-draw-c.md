# Obtaining a Canvas and Displaying Drawing Results (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=740dcdea7b2e0f63c4b99baa0eb4f2e92e763430 translatedAt=2026-08-03T11:15:03.127Z pushedAt=2026-08-04T02:17:12.059Z -->

## Overview

Canvas provides the capability of drawing and processing basic graphics on the screen. You can use Canvas to implement custom drawing effects to enhance user experience.

Canvas is the core of graphics drawing. All drawing operations mentioned in this topic (including drawing basic graphics, text, and images, and performing graphic transformation) are based on Canvas.

In C/C++, you can obtain a canvas in either of the following ways: obtaining a canvas that can be directly displayed; or obtaining an offscreen canvas. The former does not require additional operations after the drawing API is called, and the latter requires existing display approaches to display the drawing result.

## Available APIs

The following table lists the APIs for creating a canvas. For details, see [drawing_canvas.h](../reference/apis-arkgraphics2d/capi-drawing-canvas-h.md).

| API| Description|
| -------- | -------- |
| OH_Drawing_Canvas\* OH_Drawing_CanvasCreate (void) | Creates a canvas object.|
| void OH_Drawing_CanvasBind (OH_Drawing_Canvas\*, OH_Drawing_Bitmap\*) | Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap.|
| OH_Drawing_Canvas\* OH_Drawing_SurfaceGetCanvas (OH_Drawing_Surface \*) | Obtains a canvas from a surface object.|

## Obtaining a Canvas That Can Be Directly Displayed

You can obtain a canvas that can be directly displayed via XComponent.

1. Add link libraries.

   Add the following link libraries to **src/main/cpp/CMakeLists.txt** of the Native project.

   ```c++
   // CMakeLists.txt
   target_link_libraries(entry PUBLIC libnative_drawing.so)
   ```

2. Import the required header files.

   <!-- @[ndk_graphics_draw_include_native_drawing_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

   ``` C
   #include <native_drawing/drawing_canvas.h>
   ```

   <!-- @[ndk_graphics_draw_include_native_drawing_surface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   #include <native_drawing/drawing_surface.h>
   ```

3. Obtain the BufferHandle object from the NativeWindow corresponding to the XComponent. For NativeWindow-related APIs, see [NativeWindow](../reference/apis-arkgraphics2d/capi-nativewindow.md).

   <!-- @[ndk_graphics_draw_get_buffer_handle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Obtain an OHNativeWindowBuffer instance by calling OH_NativeWindow_NativeWindowRequestBuffer.
   int ret = OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow_, &buffer_, &fenceFd_);
   SAMPLE_LOGI("request buffer ret = %{public}d", ret);
   // Obtain the buffer handle by calling OH_NativeWindow_GetBufferHandleFromNative.
   bufferHandle_ = OH_NativeWindow_GetBufferHandleFromNative(buffer_);
   ```

4. Obtain the corresponding memory address from the buffer handle.

   <!-- @[ndk_graphics_draw_get_mapped_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Use mmap() to obtain the memory virtual address of buffer handle.
   mappedAddr_ = static_cast<uint32_t *>(
       mmap(bufferHandle_->virAddr, bufferHandle_->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle_->fd, 0));
   if (mappedAddr_ == MAP_FAILED) {
       SAMPLE_LOGE("mmap failed");
   }
   ```

5. Create a window canvas.

   <!-- @[ndk_graphics_draw_create_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Create a bitmap object.
   cScreenBitmap_ = OH_Drawing_BitmapCreate();
   // Define the pixel format of the bitmap.
   OH_Drawing_BitmapFormat cFormat{COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUE};
   // Set the pixel format for the bitmap.
   OH_Drawing_BitmapBuild(cScreenBitmap_, width, height_, &cFormat);
   
   // Create a canvas object.
   cScreenCanvas_ = OH_Drawing_CanvasCreate();
   // Bind the bitmap to the canvas. The content drawn on the canvas will be output to the bound bitmap memory.
   OH_Drawing_CanvasBind(cScreenCanvas_, cScreenBitmap_);
   ```

6. Use the canvas obtained in the previous step to perform custom drawing operations.

7. Use XComponent to complete the display.

   <!-- @[ndk_graphics_draw_native_window_flush_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Set the refresh region. If Rect in Region is a null pointer or rectNumber is 0, all contents in the OHNativeWindowBuffer are changed.
   Region region{nullptr, 0};
   // Flush the buffer to the consumer through OH_NativeWindow_NativeWindowFlushBuffer, for example, by displaying it on the screen.
   OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, buffer_, fenceFd_, region);
   ```

## Obtaining and Displaying an Offscreen Canvas

There are two types of offscreen canvas: CPU backend canvas and GPU backend canvas, both of which rely on XComponent to display the drawing result on the screen. Due to historical reasons, early canvases are all CPU backend canvases. Currently, GPU backend canvases are supported. The parallel computing capability of the GPU is stronger and more suitable for graphics drawing. However, the GPU backend canvas does not support some scenarios, for example, complex paths. The drawing performance of short texts is also inferior to that of the CPU backend canvas.

### Creating and Displaying a CPU Backend Canvas

Currently, the drawing of C/C++ APIs depends on **NativeWindow**. The CPU backend canvas needs to be drawn offscreen first to generate a bitmap or pixel map (supported since API version 20), and then displayed on the screen through XComponent.

Method 1: Create a canvas by binding a bitmap.

1. Import the required header files.

   <!-- @[ndk_graphics_draw_include_native_drawing_canvas_and_bitmap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

   ``` C
   #include <native_drawing/drawing_bitmap.h>
   // ...
   #include <native_drawing/drawing_canvas.h>
   ```

2. Create a canvas based on the CPU. You need to create a bitmap object by calling **OH_Drawing_BitmapCreate()** (for details, see [Drawing Images](pixelmap-drawing-c.md)) and bind the bitmap to the canvas by calling **OH_Drawing_CanvasBind()**. In this way, the content drawn on the canvas can be output to the bitmap.

   <!-- @[ndk_graphics_draw_create_canvas_by_cpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Create an offscreen bitmap object.
   cOffScreenBitmap_ = OH_Drawing_BitmapCreate();
   // Set bitmap attributes.
   OH_Drawing_BitmapFormat cFormat{COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_PREMUL};
   // Set the bitmap width and height as required.
   uint32_t width = 800;
   uint32_t height = 800;
   // Initialize the bitmap.
   OH_Drawing_BitmapBuild(cOffScreenBitmap_, width, height, &cFormat);
   // Create an offscreen canvas object.
   cCPUCanvas_ = OH_Drawing_CanvasCreate();
   // Bind the offscreen canvas to the offscreen bitmap. The content drawn on the offscreen canvas is output to the memory of the offscreen bitmap.
   OH_Drawing_CanvasBind(cCPUCanvas_, cOffScreenBitmap_);
   ```

   To set the background to white, perform the following steps:

   <!-- @[ndk_graphics_draw_clear_canvas_cpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Set the background to white.
   OH_Drawing_CanvasClear(cCPUCanvas_, OH_Drawing_ColorSetArgb(RGBA_MAX, RGBA_MAX, RGBA_MAX, 0xFF));
   ```

3. Draw the bitmap created in the previous step to the [canvas](#obtaining-a-canvas-that-can-be-directly-displayed).

   <!-- @[ndk_graphics_draw_drawing_to_window_canvas_cpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Draw the content in the offscreen bitmap to the screen canvas.
   OH_Drawing_CanvasDrawBitmap(cScreenCanvas_, cOffScreenBitmap_, 0, 0);
   ```

Method 2: Create a canvas using a pixel map. This method is supported since API version 20.

A pixel map is a unified data structure used to represent images in the system. Compared with bitmaps provided by the drawing module, pixel maps are more universal and can better leverage the system capabilities.

1. Add link libraries.

   Add the following link libraries to **src/main/cpp/CMakeLists.txt** of the Native project.

   ```c++
   // CMakeLists.txt
   target_link_libraries(entry PUBLIC libhilog_ndk.z.so libpixelmap.so)
   ```

2. Import the required header files.

   <!-- @[ndk_graphics_draw_include_pixelmap_native](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   #include <multimedia/image_framework/image/pixelmap_native.h>
   ```

   <!-- @[ndk_graphics_draw_include_drawing_pixel_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   #include <native_drawing/drawing_pixel_map.h>
   ```

3. You need to create a pixel map object by calling **OH_Drawing_PixelMapGetFromOhPixelMapNative()** (for details, see [Drawing Images](pixelmap-drawing-c.md)), and create a canvas by calling **OH_Drawing_CanvasCreateWithPixelMap()** based on the pixel map object.

   <!-- @[ndk_graphics_draw_image](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // The image width x height is 600 x 400.
   uint32_t width = 600;
   uint32_t height = 400;
   // Byte length. Each RGBA_8888 pixel occupies 4 bytes.
   size_t bufferSize = width * height * 4;
   uint8_t *pixels = new uint8_t[bufferSize];
   for (uint32_t i = 0; i < width * height; ++i) {
       // Traverse and edit each pixel to form red, green, and blue stripes.
       uint32_t n = i / 20 % 3;
       pixels[i * RGBA_SIZE] = RGBA_MIN; // Red channel.
       pixels[i * RGBA_SIZE + 1] = RGBA_MIN; // Green channel.
       pixels[i * RGBA_SIZE + 2] = RGBA_MIN; // Blue channel.
       pixels[i * RGBA_SIZE + 3] = 0xFF; // Opacity channel.
       if (n == 0) {
           pixels[i * RGBA_SIZE] = 0xFF; // Assign a value to the red channel. The color is displayed in red.
       } else if (n == 1) {
           pixels[i * RGBA_SIZE + 1] = 0xFF; // Assign a value to the green channel while keeping other channels at 0. The color is displayed in green.
       } else {
           pixels[i * RGBA_SIZE + 2] = 0xFF; // Assign a value to the blue channel while keeping other channels at 0. The color is displayed in blue.
       }
   }
   // Set the pixel map format (length, width, color type, and alpha type).
   OH_Pixelmap_InitializationOptions *createOps = nullptr;
   OH_PixelmapInitializationOptions_Create(&createOps);
   OH_PixelmapInitializationOptions_SetWidth(createOps, width);
   OH_PixelmapInitializationOptions_SetHeight(createOps, height);
   OH_PixelmapInitializationOptions_SetPixelFormat(createOps, PIXEL_FORMAT_RGBA_8888);
   OH_PixelmapInitializationOptions_SetAlphaType(createOps, PIXELMAP_ALPHA_TYPE_UNKNOWN);
   // Create an OH_PixelmapNative object.
   OH_PixelmapNative *pixelMapNative = nullptr;
   OH_PixelmapNative_CreatePixelmap(pixels, bufferSize, createOps, &pixelMapNative);
   OH_Drawing_PixelMap *pixelMap = OH_Drawing_PixelMapGetFromOhPixelMapNative(pixelMapNative);
   // Cropping area of the pixels in the pixel map.
   OH_Drawing_Rect *src = OH_Drawing_RectCreate(0, 0, 600, 400);
   // Area displayed on the canvas.
   OH_Drawing_Rect *dst = OH_Drawing_RectCreate(value200_, value200_, value800_, value600_);
   // Sampling option object.
   OH_Drawing_SamplingOptions* samplingOptions = OH_Drawing_SamplingOptionsCreate(
       OH_Drawing_FilterMode::FILTER_MODE_LINEAR, OH_Drawing_MipmapMode::MIPMAP_MODE_LINEAR);
   // Draw the pixel map.
   OH_Drawing_CanvasDrawPixelMapRect(canvas, pixelMap, src, dst, samplingOptions);
   OH_PixelmapNative_Release(pixelMapNative);
   delete[] pixels;
   ```

   To set the background to white, perform the following steps:

   ```c++
   OH_Drawing_CanvasClear(pixelmapCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```

4. Draw the pixel map created in the previous step to the [canvas](#obtaining-a-canvas-that-can-be-directly-displayed).

   <!-- @[ndk_graphics_draw_image_to_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Cropping area of the pixels in the pixel map.
   OH_Drawing_Rect *src = OH_Drawing_RectCreate(0, 0, 600, 400);
   // Area displayed on the canvas.
   OH_Drawing_Rect *dst = OH_Drawing_RectCreate(value200_, value200_, value800_, value600_);
   // Sampling option object.
   OH_Drawing_SamplingOptions* samplingOptions = OH_Drawing_SamplingOptionsCreate(
       OH_Drawing_FilterMode::FILTER_MODE_LINEAR, OH_Drawing_MipmapMode::MIPMAP_MODE_LINEAR);
   // Draw the pixel map.
   OH_Drawing_CanvasDrawPixelMapRect(canvas, pixelMap, src, dst, samplingOptions);
   ```

### Creating and Displaying a GPU Backend Canvas

A GPU backend canvas is a canvas that is drawn based on the GPU. The parallel computing capability of the GPU is better than that of the CPU. It is applicable to scenarios where images or large areas are drawn. However, the GPU backend canvas currently cannot draw complex paths. Similar to the CPU backend canvas, drawing using the C/C++ APIs depends on XComponent. The GPU backend canvas needs to be drawn offscreen and then displayed on the screen through XComponent.

1. Currently, the creation of the GPU backend canvas depends on the EGL capability. You need to add the dynamic dependency library of the EGL to the **CMakeLists.txt** file.

   ```c++
   // CMakeLists.txt
   libEGL.so
   ```

2. Import the required header files.

   <!-- @[ndk_graphics_draw_include_egl_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

   ``` C
   #include <EGL/egl.h>
   #include <EGL/eglext.h>
   ```

   <!-- @[ndk_graphics_draw_include_native_drawing_surface_and_gpu_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   #include <native_drawing/drawing_gpu_context.h>
   #include <native_drawing/drawing_surface.h>
   ```

3. Initialize the EGL context.

   Initialize context-related parameters:

   <!-- @[ndk_graphics_draw_initialize_egl_context_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.h) -->

   ``` C
   EGLDisplay EGLDisplay_ = EGL_NO_DISPLAY;
   EGLConfig EGLConfig_ = nullptr;
   EGLContext EGLContext_ = EGL_NO_CONTEXT;
   EGLSurface EGLSurface_ = nullptr;
   ```

   Initialize context-related configurations.

   <!-- @[ndk_graphics_draw_initialize_egl_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
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
           SAMPLE_LOGE("eglChooseConfig ERROR");
           return NULL;
       }
   
       return configs;
   }
   
   int32_t SampleGraphics::InitializeEglContext()
   {
       EGLDisplay_ = eglGetDisplay(EGL_DEFAULT_DISPLAY);
       if (EGLDisplay_ == EGL_NO_DISPLAY) {
           SAMPLE_LOGE("unable to get EGL display.");
           return -1;
       }
   
       EGLint eglMajVers;
       EGLint eglMinVers;
       if (!eglInitialize(EGLDisplay_, &eglMajVers, &eglMinVers)) {
           EGLDisplay_ = EGL_NO_DISPLAY;
           SAMPLE_LOGE("unable to initialize display");
           return -1;
       }
   
       int version = 3;
       EGLConfig_ = getConfig(version, EGLDisplay_);
       if (EGLConfig_ == nullptr) {
           SAMPLE_LOGE("GLContextInit config ERROR");
           return -1;
       }
   
       /* Create EGLContext from */
       int attribList[] = {EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE}; // 2 size
   
       EGLContext_ = eglCreateContext(EGLDisplay_, EGLConfig_, EGL_NO_CONTEXT, attribList);
   
       EGLint attribs[] = {EGL_WIDTH, 1, EGL_HEIGHT, 1, EGL_NONE};
       EGLSurface_ = eglCreatePbufferSurface(EGLDisplay_, EGLConfig_, attribs);
       if (!eglMakeCurrent(EGLDisplay_, EGLSurface_, EGLSurface_, EGLContext_)) {
           SAMPLE_LOGE("eglMakeCurrent error = %{public}d", eglGetError());
           return -1;
       }
   
       SAMPLE_LOGE("Init success.");
       return 0;
   }
   ```

4. Create a GPU backend canvas. The GPU backend canvas needs to be obtained using the surface object. You need to create a surface object first. For details about the surface APIs, see [drawing_surface.h](../reference/apis-arkgraphics2d/capi-drawing-surface-h.md). Create a drawing context by calling **OH_Drawing_GpuContextCreateFromGL**, create a surface object by passing the context as a parameter, and obtain the canvas from the surface by calling **OH_Drawing_SurfaceGetCanvas**.

   <!-- @[ndk_graphics_draw_create_canvas_by_gpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Set the width and height as required.
   int32_t cWidth = 800;
   int32_t cHeight = 800;
   // Set the image, including the width, height, color format, and alpha format.
   OH_Drawing_Image_Info imageInfo = {cWidth, cHeight, COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_PREMUL};
   // GPU context options.
   OH_Drawing_GpuContextOptions options{true};
       
   // Create a drawing context that uses OpenGL (GL) as its GPU backend.
   OH_Drawing_GpuContext *gpuContext = OH_Drawing_GpuContextCreateFromGL(options);
   // Create a surface object.
   OH_Drawing_Surface *surface = OH_Drawing_SurfaceCreateFromGpuContext(gpuContext, true, imageInfo);
   // Create a canvas object.
   cGPUCanvas_ = OH_Drawing_SurfaceGetCanvas(surface);
   ```

   To set the background to white, perform the following steps:

   <!-- @[ndk_graphics_draw_clear_canvas_gpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Set the background to white.
   OH_Drawing_CanvasClear(cGPUCanvas_, OH_Drawing_ColorSetArgb(RGBA_MAX, RGBA_MAX, RGBA_MAX, 0xFF));
   ```

5. Copy the drawing result in the previous step to the [canvas](#obtaining-a-canvas-that-can-be-directly-displayed).

   <!-- @[ndk_graphics_draw_drawing_to_window_canvas_gpu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   void* dstPixels = malloc(cWidth * cHeight * RGBA_SIZE); // 4 for rgba
   OH_Drawing_CanvasReadPixels(cGPUCanvas_, &imageInfo, dstPixels, RGBA_SIZE * cWidth, 0, 0);
   OH_Drawing_Bitmap* cOffScreenBitmap_ = OH_Drawing_BitmapCreateFromPixels(&imageInfo, dstPixels,
       RGBA_SIZE * cWidth);
   OH_Drawing_CanvasDrawBitmap(cScreenCanvas_, cOffScreenBitmap_, 0, 0);
   ```

6. Destroy the EGL context after using it.

   <!-- @[ndk_graphics_draw_deinitialize_egl_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   void SampleGraphics::DeInitializeEglContext()
   {
       EGLBoolean ret = eglDestroySurface(EGLDisplay_, EGLSurface_);
       if (!ret) {
           SAMPLE_LOGE("eglDestroySurface failure.");
       }
   
       ret = eglDestroyContext(EGLDisplay_, EGLContext_);
       if (!ret) {
           SAMPLE_LOGE("eglDestroyContext failure.");
       }
   
       ret = eglTerminate(EGLDisplay_);
       if (!ret) {
           SAMPLE_LOGE("eglTerminate failure.");
       }
   
       EGLSurface_ = NULL;
       EGLContext_ = NULL;
       EGLDisplay_ = NULL;
   }
   ```

<!--RP1-->

## Samples

The following samples are provided to help you better understand how to use the **Drawing** APIs (C/C++) for development:

- [NDKGraphicsDraw (API20)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw)

<!--RP1End-->
# Obtaining a Canvas and Displaying Drawing Results (C/C++)


## When to Use

Canvas provides the capability of drawing basic graphics on the screen. You can use Canvas to customize drawing effects to enhance user experience.

Canvas is the core of graphics drawing. All drawing operations (including basic graphics drawing, text drawing, image drawing, and image transformation) mentioned in this chapter are based on Canvas.

Currently, C/C++ can obtain Canvas in either of the following ways: Obtains the canvas that can be directly displayed on the screen and the canvas that can be directly displayed off the screen. The former can display the drawing result on the screen without additional operations after the drawing API is called, while the latter can display the drawing result by using the existing display method.


## Available APIs

The following table lists the common APIs for creating a Canvas. For details, see [drawing_canvas.h](../reference/apis-arkgraphics2d/drawing__canvas_8h.md).

| Interface| Description|
| -------- | -------- |
| OH_Drawing_Canvas\* OH_Drawing_CanvasCreate (void) | Creates an **OH_Drawing_Canvas** object.|
| void OH_Drawing_CanvasBind (OH_Drawing_Canvas\*, OH_Drawing_Bitmap\*) | Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.)|
| OH_Drawing_Canvas\* OH_Drawing_SurfaceGetCanvas (OH_Drawing_Surface \*) | Obtains a canvas from an **OH_Drawing_Surface** object.|


## Obtaining the Canvas That Can Be Directly Displayed

Obtains the canvas that can be directly displayed by using the XComponent.

1. Obtains the BufferHandle object from the NativeWindow corresponding to the XComponent. For details about APIs related to NativeWindow, see [_native_window](../reference/apis-arkgraphics2d/_native_window.md).

   ```c++
   uint64_t width, height;
   OHNativeWindow *nativeWindow; // The NativeWindow and its width and height need to be obtained from the XComponent.
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

2. Obtains the corresponding memory address from BufferHandle.

   ```c++
   uint32_t* mappedAddr = static_cast<uint32_t *>(mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0));
   ```

3. Create a window canvas.

   ```c++
   OH_Drawing_Image_Info screenImageInfo = {static_cast<int32_t>(width), static_cast<int32_t>(height), COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_OPAQUE};
   OH_Drawing_Bitmap* screenBitmap = OH_Drawing_BitmapCreateFromPixels(&screenImageInfo, mappedAddr, bufferHandle->stride);
   OH_Drawing_Canvas* screenCanvas = OH_Drawing_CanvasCreate();
   OH_Drawing_CanvasBind(screenCanvas, screenBitmap);
   ```

4. Use the canvas obtained in the previous step to perform customized drawing operations, that is, the following content in this chapter.

5. Use XComponent to complete the display.

   ```c++
   Region region {nullptr, 0};
   OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
   ```


## Obtaining and Displaying the Off-Screen Canvas

Currently, there are two methods of creating an off-screen Canvas: creating a CPU backend Canvas and creating a GPU backend Canvas. Both canvases depend on the XComponent to display the drawing result on the screen. Due to historical reasons, early Canvas is the CPU backend Canvas. Currently, the GPU backend Canvas is supported. The GPU has a stronger parallel computing capability and is more suitable for graphics drawing. However, the GPU backend Canvas does not support some scenarios. For example, in complex paths, the performance of drawing short texts is lower than that of the CPU backend Canvas.


### Creating and Displaying a CPU Backend Canvas

Currently, the drawing of C/C++ APIs depends on NativeWindow. The CPU backend Canvas needs to be drawn off the screen to generate a bitmap, and then the bitmap is displayed on the screen by using XComponent.


1. Import the dependent header files.

   ```c++
   #include <native_drawing/drawing_canvas.h>
   #include <native_drawing/drawing_bitmap.h>
   ```

2. Create a CPU-based Canvas. You need to create a bitmap object by calling OH_Drawing_BitmapCreate(). For details, see [PixelMap Drawing](pixelmap-drawing-c.md). Bind the bitmap to the Canvas by calling OH_Drawing_CanvasBind() so that the content drawn by the Canvas can be output to the bitmap.

   ```c++
   Creates an **OH_Drawing_Bitmap** object.
   OH_Drawing_Bitmap* bitmap = OH_Drawing_BitmapCreate();
   OH_Drawing_BitmapFormat cFormat{COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_PREMUL};
   // Set the bitmap length and width as required.
   uint32_t width = 800;
   uint32_t height = 800;
   // Initialize the bitmap.
   OH_Drawing_BitmapBuild(bitmap, width, height, &cFormat);
   // Create a Buffer object.
   OH_Drawing_Canvas* bitmapCanvas = OH_Drawing_CanvasCreate();
   // Bind the canvas to the bitmap. The content drawn by the canvas is output to the bound bitmap memory.
   OH_Drawing_CanvasBind(bitmapCanvas, bitmap);
   ```

   To set the background color to white, perform the following steps:

   ```c++
   OH_Drawing_CanvasClear(bitmapCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```

3. Draw the bitmap created in the previous step to the [window canvas](#obtaining-the-canvas-that-can-be-directly-displayed).

   ```c++
   OH_Drawing_CanvasDrawBitmap(screenCanvas, bitmap, 0, 0);
   ```


### Creating and Displaying a GPU Backend Canvas

The GPU backend Canvas indicates that the canvas is drawn based on the GPU. The parallel computing capability of the GPU is better than that of the CPU. The GPU backend Canvas is applicable to scenarios where images or areas are large. However, the GPU backend Canvas has a weak capability in drawing complex paths. Similar to the CPU backend Canvas. Currently, the drawing of the C/C++ interface depends on the XComponent. The GPU backend Canvas needs to be drawn off the screen and then displayed on the screen using the XComponent.

1. To create a GPU backend canvas, you need to add the dynamic library for EGL in the **CMakeList.txt** file:

   ```c++
   libEGL.so
   ```

2. Import the dependent header files.

   ```c++
   #include <EGL/egl.h>
   #include <EGL/eglext.h>
   #include <native_drawing/drawing_gpu_context.h>
   #include <native_drawing/drawing_surface.h>
   ```
3. Initialize the EGL context.

   ```c++
   // Initialize context-related parameters.
   EGLDisplay mEGLDisplay = EGL_NO_DISPLAY;
   EGLConfig mEGLConfig = nullptr;
   EGLContext mEGLContext = EGL_NO_CONTEXT;
   EGLSurface mEGLSurface = nullptr;
   ```

   ```c++
   // Function used to obtain EGL configuration.
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

   // Call InitializeEglContext where you need to initialize the EGL context.
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

4. Create a GPU backend Canvas. The GPU backend Canvas needs to be obtained by using the Surface object. Therefore, you need to create a surface first. For details about the surface API, see [drawing_surface.h](../reference/apis-arkgraphics2d/drawing__surface_8h.md). Currently, drawing supports GPU backend drawing based on OpenGL. Therefore, you need to create a drawing context by calling OH_Drawing_GpuContextCreateFromGL, and then use the context as a parameter to create a surface, obtain the canvas from the surface by calling OH_Drawing_SurfaceGetCanvas.

   ```c++
   // Set the width and height as required.
   int32_t cWidth = 800;
   int32_t cHeight = 800;
   // Set the image, including the width, height, color format, and transparency format.
   OH_Drawing_Image_Info imageInfo = {cWidth, cHeight, COLOR_FORMAT_RGBA_8888, ALPHA_FORMAT_PREMUL};
   // GPU context options
   OH_Drawing_GpuContextOptions options{false};
   // Create a drawing context that uses OpenGL (GL) as the GPU backend.
   OH_Drawing_GpuContext *gpuContext = OH_Drawing_GpuContextCreateFromGL(options);
   // Create a surface object.
   OH_Drawing_Surface *surface = OH_Drawing_SurfaceCreateFromGpuContext(gpuContext, true, imageInfo);
   // Create a canvas object.
   OH_Drawing_Canvas* gpuCanvas = OH_Drawing_SurfaceGetCanvas(surface);
   ```

   To set the background color to white, perform the following steps:

   ```c++
   OH_Drawing_CanvasClear(gpuCanvas, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0xFF, 0xFF));
   ```

5. Copy the drawing result in the previous step to the [window canvas](#obtaining-the-canvas-that-can-be-directly-displayed).

   ```c++
   void* dstPixels = malloc(cWidth * cHeight * 4); // 4 for rgba
   OH_Drawing_CanvasReadPixels(gpuCanvas, &imageInfo, dstPixels, 4 * cWidth, 0, 0);
   OH_Drawing_Bitmap* bitmap = OH_Drawing_BitmapCreateFromPixels(&imageInfo, dstPixels, 4 * cWidth);
   OH_Drawing_CanvasDrawBitmap(screenCanvas, bitmap, 0, 0);
   ```

6. Destroy the EGL context after use.

   ```c++
   // Call DeInitializeEglContext to destroy the EGL context.
   void DeInitializeEglContext(EGLDisplay mEGLDisplay, EGLContext mEGLContext, EGLSurface mEGLSurface)
   {
      // Each of these functions returns a value indicating success or failure, which can be useful for debugging.
      eglDestroySurface(mEGLDisplay, mEGLSurface);
      eglDestroyContext(mEGLDisplay, mEGLContext);
      eglTerminate(mEGLDisplay);

      mEGLSurface = NULL;
      mEGLContext = NULL;
      mEGLDisplay = NULL;
   }
   ```

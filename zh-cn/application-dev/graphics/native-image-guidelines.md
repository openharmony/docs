# NativeImage开发指导 (C/C++)

## 场景介绍

NativeImage是提供**Surface关联OpenGL外部纹理**的模块，表示图形队列的消费者端。开发者可以通过`NativeImage`接口接收和使用`Buffer`，并将`Buffer`关联输出到OpenGL外部纹理。
针对NativeImage，常见的开发场景如下：

* 通过`NativeImage`提供的Native API接口创建`NativeImage`实例作为消费者端，获取与该实例对应的`NativeWindow`作为生产者端。`NativeWindow`相关接口可用于填充`Buffer`内容并提交，`NativeImage`将`Buffer`内容更新到OpenGL外部纹理上。本模块需要配合NativeWindow、NativeBuffer、EGL、GLES3模块一起使用。

## 接口说明

| 接口名                                                       | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_NativeImage_Create (uint32_t textureId, uint32_t textureTarget) | 创建一个OH_NativeImage实例，该实例与OpenGL ES的纹理ID和纹理目标相关联。本接口需要与OH_NativeImage_Destroy接口配合使用，否则会存在内存泄露。 |
| OH_NativeImage_AcquireNativeWindow (OH_NativeImage \*image)  | 获取与OH_NativeImage相关联的OHNativeWindow指针，该OHNativeWindow在调用OH_NativeImage_Destroy时会将其释放，不需要调用OH_NativeWindow_DestroyNativeWindow释放，否则会出现访问已释放内存错误，可能会导致崩溃。 |
| OH_NativeImage_AttachContext (OH_NativeImage \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文，且该OpenGL ES纹理会绑定到 GL_TEXTURE_EXTERNAL_OES，并通过OH_NativeImage进行更新。 |
| OH_NativeImage_DetachContext (OH_NativeImage \*image)        | 将OH_NativeImage实例从当前OpenGL ES上下文分离。              |
| OH_NativeImage_UpdateSurfaceImage (OH_NativeImage \*image)   | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理。      |
| OH_NativeImage_GetTimestamp (OH_NativeImage \*image)         | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳。 |
| OH_NativeImage_GetTransformMatrix (OH_NativeImage \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。 |
| OH_NativeImage_Destroy (OH_NativeImage \*\*image)            | 销毁通过OH_NativeImage_Create创建的OH_NativeImage实例，销毁后该OH_NativeImage指针会被赋值为空。 |

详细的接口说明请参考[native_image](../reference/apis-arkgraphics2d/_o_h___native_image.md)。

## 开发步骤

以下步骤描述了如何使用`NativeImage`提供的Native API接口，创建`OH_NativeImage`实例作为消费者端，将数据内容更新到OpenGL外部纹理上。

**添加动态链接库**

CMakeLists.txt中添加以下lib。

```txt
libEGL.so
libGLESv3.so
libnative_image.so
libnative_window.so
libnative_buffer.so
```

**头文件**

```c++
#include <iostream>
#include <string>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#include <sys/mman.h>
#include <native_image/native_image.h>
#include <native_window/external_window.h>
#include <native_buffer/native_buffer.h>
```

1. **初始化EGL环境**。

   这里提供一份初始化EGL环境的代码示例。XComponent模块的具体使用方法请参考[XComponent开发指导](../ui/napi-xcomponent-guidelines.md)。
   ```c++   
   using GetPlatformDisplayExt = PFNEGLGETPLATFORMDISPLAYEXTPROC;
   constexpr const char *EGL_EXT_PLATFORM_WAYLAND = "EGL_EXT_platform_wayland";
   constexpr const char *EGL_KHR_PLATFORM_WAYLAND = "EGL_KHR_platform_wayland";
   constexpr int32_t EGL_CONTEXT_CLIENT_VERSION_NUM = 2;
   constexpr char CHARACTER_WHITESPACE = ' ';
   constexpr const char *CHARACTER_STRING_WHITESPACE = " ";
   constexpr const char *EGL_GET_PLATFORM_DISPLAY_EXT = "eglGetPlatformDisplayEXT";
   EGLContext eglContext_ = EGL_NO_CONTEXT;
   EGLDisplay eglDisplay_ = EGL_NO_DISPLAY;
   static inline EGLConfig config_;
   static inline EGLSurface eglSurface_;
   // 从XComponent中获取到的OHNativeWindow
   OHNativeWindow *eglNativeWindow_;
   
   // 检查egl扩展
   static bool CheckEglExtension(const char *extensions, const char *extension) {
       size_t extlen = strlen(extension);
       const char *end = extensions + strlen(extensions);
   
       while (extensions < end) {
           size_t n = 0;
           if (*extensions == CHARACTER_WHITESPACE) {
               extensions++;
               continue;
           }
           n = strcspn(extensions, CHARACTER_STRING_WHITESPACE);
           if (n == extlen && strncmp(extension, extensions, n) == 0) {
               return true;
           }
           extensions += n;
       }
       return false;
   }
   
   // 获取当前的显示设备
   static EGLDisplay GetPlatformEglDisplay(EGLenum platform, void *native_display, const EGLint *attrib_list) {
       static GetPlatformDisplayExt eglGetPlatformDisplayExt = NULL;
   
       if (!eglGetPlatformDisplayExt) {
           const char *extensions = eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS);
           if (extensions && (CheckEglExtension(extensions, EGL_EXT_PLATFORM_WAYLAND) ||
                              CheckEglExtension(extensions, EGL_KHR_PLATFORM_WAYLAND))) {
               eglGetPlatformDisplayExt = (GetPlatformDisplayExt)eglGetProcAddress(EGL_GET_PLATFORM_DISPLAY_EXT);
           }
       }
   
       if (eglGetPlatformDisplayExt) {
           return eglGetPlatformDisplayExt(platform, native_display, attrib_list);
       }
   
       return eglGetDisplay((EGLNativeDisplayType)native_display);
   }
   
   static void InitEGLEnv() {
       // 获取当前的显示设备
       eglDisplay_ = GetPlatformEglDisplay(EGL_PLATFORM_OHOS_KHR, EGL_DEFAULT_DISPLAY, NULL);
       if (eglDisplay_ == EGL_NO_DISPLAY) {
           std::cout << "Failed to create EGLDisplay gl errno : " << eglGetError() << std::endl;
       }
   
       EGLint major, minor;
       // 初始化EGLDisplay
       if (eglInitialize(eglDisplay_, &major, &minor) == EGL_FALSE) {
           std::cout << "Failed to initialize EGLDisplay" << std::endl;
       }
   
       // 绑定图形绘制的API为OpenGLES
       if (eglBindAPI(EGL_OPENGL_ES_API) == EGL_FALSE) {
           std::cout << "Failed to bind OpenGL ES API" << std::endl;
       }
   
       unsigned int glRet;
       EGLint count;
       EGLint config_attribs[] = {EGL_SURFACE_TYPE,
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
                                  EGL_OPENGL_ES3_BIT,
                                  EGL_NONE};
   
       // 获取一个有效的系统配置信息
       glRet = eglChooseConfig(eglDisplay_, config_attribs, &config_, 1, &count);
       if (!(glRet && static_cast<unsigned int>(count) >= 1)) {
           std::cout << "Failed to eglChooseConfig" << std::endl;
       }
   
       static const EGLint context_attribs[] = {EGL_CONTEXT_CLIENT_VERSION, EGL_CONTEXT_CLIENT_VERSION_NUM, EGL_NONE};
   
       // 创建上下文
       eglContext_ = eglCreateContext(eglDisplay_, config_, EGL_NO_CONTEXT, context_attribs);
       if (eglContext_ == EGL_NO_CONTEXT) {
           std::cout << "Failed to create egl context, error:" << eglGetError() << std::endl;
       }
   
       // 创建eglSurface
       eglSurface_ = eglCreateWindowSurface(eglDisplay_, config_, reinterpret_cast<EGLNativeWindowType>(eglNativeWindow_), context_attribs);
       if (eglSurface_ == EGL_NO_SURFACE) {
           std::cout << "Failed to create egl surface, error:" << eglGetError() << std::endl;
       }
   
       // 关联上下文
       eglMakeCurrent(eglDisplay_, eglSurface_, eglSurface_, eglContext_);
   
       // EGL环境初始化完成
       std::cout << "Create EGL context successfully, version" << major << "." << minor << std::endl;
   }
   ```

2. **创建OH_NativeImage实例**。
   
   ```c++
   // 创建 OpenGL 纹理
   GLuint textureId;
   glGenTextures(1, &textureId);
   // 创建 NativeImage 实例，关联 OpenGL 纹理
   OH_NativeImage* image = OH_NativeImage_Create(textureId, GL_TEXTURE_EXTERNAL_OES);
   ```
   
3. **获取对应的数据生产者端NativeWindow**。

   ```c++
   // 获取生产者NativeWindow
   OHNativeWindow* nativeWindow = OH_NativeImage_AcquireNativeWindow(image);
   ```

4. **设置NativeWindow的宽高**。

   ```c++
   int code = SET_BUFFER_GEOMETRY;
   int32_t width = 800;
   int32_t height = 600;
   int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
   ```

5. **将生产的内容写入OHNativeWindowBuffer**。

   1. 从NativeWindow中获取OHNativeWindowBuffer。

      ```c++
      OHNativeWindowBuffer *buffer = nullptr;
      int fenceFd;
      // 通过 OH_NativeWindow_NativeWindowRequestBuffer 获取 OHNativeWindowBuffer 实例
      OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &fenceFd);
       
      BufferHandle *handle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
      ```

   2. 将生产的内容写入OHNativeWindowBuffer。

      ```c++
      // 使用系统mmap接口拿到bufferHandle的内存虚拟地址
      void *mappedAddr = mmap(handle->virAddr, handle->size, PROT_READ | PROT_WRITE, MAP_SHARED, handle->fd, 0);
      if (mappedAddr == MAP_FAILED) {
          // mmap failed
      }
      static uint32_t value = 0x00;
      value++;
      uint32_t *pixel = static_cast<uint32_t *>(mappedAddr);
      for (uint32_t x = 0; x < width; x++) {
          for (uint32_t y = 0; y < height; y++) {
              *pixel++ = value;
          }
      }
      // 内存使用完记得去掉内存映射
      int result = munmap(mappedAddr, handle->size);
      if (result == -1) {
          // munmap failed
      }
      ```

   3. 将OHNativeWindowBuffer提交到NativeWindow。

      ```c++
      // 设置刷新区域，如果Region中的Rect数组为nullptr,或者rectNumber为0，则认为OHNativeWindowBuffer全部内容有更改。
      Region region{nullptr, 0};
      // 通过OH_NativeWindow_NativeWindowFlushBuffer 提交给消费者使用，例如：显示在屏幕上。
      OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
      ```

   4. 用完需要销毁NativeWindow。

      ```c++
      OH_NativeWindow_DestroyNativeWindow(nativeWindow);
      ```

6. **更新内容到OpenGL纹理**。

   ```c++
   // 更新内容到OpenGL纹理。
   ret = OH_NativeImage_UpdateSurfaceImage(image);
   if (ret != 0) {
       std::cout << "OH_NativeImage_UpdateSurfaceImage failed" << std::endl;
   }
   // 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的时间戳和变化矩阵。
   int64_t timeStamp = OH_NativeImage_GetTimestamp(image);
   float matrix[16];
   ret = OH_NativeImage_GetTransformMatrix(image, matrix);
   if (ret != 0) {
       std::cout << "OH_NativeImage_GetTransformMatrix failed" << std::endl;
   }
   
   // 对update绑定到对应textureId的纹理做对应的opengl后处理后，将纹理上屏
   EGLBoolean eglRet = eglSwapBuffers(eglDisplay_, eglSurface_);
   if (eglRet == EGL_FALSE) {
       std::cout << "eglSwapBuffers failed" << std::endl;
   }
   ```

7. **解绑OpenGL纹理，绑定到新的外部纹理上**。

   ```c++
   // 将OH_NativeImage实例从当前OpenGL ES上下文分离
   ret = OH_NativeImage_DetachContext(image);
   if (ret != 0) {
       std::cout << "OH_NativeImage_DetachContext failed" << std::endl;
   }
   // 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到 GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新
   GLuint textureId2;
   glGenTextures(1, &textureId2);
   ret = OH_NativeImage_AttachContext(image, textureId2);
   ```

8. **OH_NativeImage实例使用完需要销毁掉**。

   ```c++
   // 销毁OH_NativeImage实例
   OH_NativeImage_Destroy(&image);
   ```

## 相关实例

针对NativeImage的开发，有以下相关实例可供参考：

- [Native Window（API11）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeWindow)
- [基于NdkNativeImage的平滑渐变动画效果（API12）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeImage)
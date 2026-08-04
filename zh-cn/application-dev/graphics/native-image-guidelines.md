# NativeImage开发指导 (C/C++)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 场景介绍

NativeImage是提供**Surface与OpenGL外部纹理相互绑定**的模块，表示图形队列的消费者端。开发者可以通过`NativeImage`接口接收和使用`Buffer`，并将`Buffer`关联输出到绑定的OpenGL外部纹理。

NativeImage常见的开发场景如下：

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
| OH_NativeImage_GetTransformMatrixV2 (OH_NativeImage \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。 |
| OH_NativeImage_Destroy (OH_NativeImage \*\*image)            | 销毁通过OH_NativeImage_Create创建的OH_NativeImage实例，销毁后该OH_NativeImage指针会被赋值为空。 |

详细的接口说明请参考[native_image](../reference/apis-arkgraphics2d/capi-oh-nativeimage.md)。

## 开发步骤

以下步骤描述了如何使用`NativeImage`提供的Native API接口，创建`OH_NativeImage`实例作为消费者端，将数据内容更新到OpenGL外部纹理上。

**添加动态链接库**

CMakeLists.txt中添加以下库文件。

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

    这里提供初始化EGL环境的代码示例。XComponent模块的详细使用方法，请参阅[XComponent开发指导](../ui/napi-xcomponent-guidelines.md)。
    <!-- @[init_egl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/image_render.cpp) -->
    
    ``` C++
    bool ImageRender::InitEGL(EGLNativeWindowType window, uint64_t width, uint64_t height)
    {
        window_ = window;
        width_ = width;
        height_ = height;
    
        if (!InitializeEGLDisplay() || !ChooseEGLConfig() || !CreateEGLContext() || !CreateEGLSurface()) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to initialize EGL");
            return false;
        }
    
        if (!MakeCurrentContext()) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to make EGL context current");
            return false;
        }
    
        if (!CompileAndLinkShaders()) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to compile and link shaders");
            return false;
        }
    
        UpdateViewport();
    
        return true;
    }
    
    // ...
    bool ImageRender::InitializeEGLDisplay()
    {
        display_ = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (display_ == EGL_NO_DISPLAY) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to get EGL display");
            return false;
        }
    
        if (!eglInitialize(display_, nullptr, nullptr)) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to initialize EGL");
            return false;
        }
    
        return true;
    }
    
    bool ImageRender::ChooseEGLConfig()
    {
        const EGLint attribs[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_NONE
        };
    
        EGLint numConfigs;
        if (!eglChooseConfig(display_, attribs, &config_, 1, &numConfigs) || numConfigs == 0) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to choose EGL config");
            return false;
        }
        return true;
    }
    
    bool ImageRender::CreateEGLContext()
    {
        const EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
        context_ = eglCreateContext(display_, config_, EGL_NO_CONTEXT, contextAttribs);
        if (context_ == EGL_NO_CONTEXT) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to create EGL context");
            return false;
        }
        return true;
    }
    
    bool ImageRender::CreateEGLSurface()
    {
        surface_ = eglCreateWindowSurface(display_, config_, window_, nullptr);
        if (surface_ == EGL_NO_SURFACE) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to create EGL surface");
            return false;
        }
        return true;
    }
    
    bool ImageRender::MakeCurrentContext()
    {
        if (!eglMakeCurrent(display_, surface_, surface_, context_)) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "ImageRender", "Failed to make EGL context current");
            return false;
        }
        return true;
    }
    
    void ImageRender::UpdateViewport()
    {
        glViewport(0, 0, static_cast<GLsizei>(width_), static_cast<GLsizei>(height_));
        OH_LOG_Print(LOG_APP, LOG_INFO, LOG_PRINT_DOMAIN, "ImageRender",
                     "Viewport updated to %{public}llu x %{public}llu", width_, height_);
    }
    
    bool ImageRender::CompileAndLinkShaders()
    {
        GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, g_vertexShaderSource);
        if (vertexShader == 0) {
            return false;
        }
    
        GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, g_fragmentShaderSource);
        if (fragmentShader == 0) {
            glDeleteShader(vertexShader);
            return false;
        }
    
        shaderProgram_ = glCreateProgram();
        glAttachShader(shaderProgram_, vertexShader);
        glAttachShader(shaderProgram_, fragmentShader);
        glLinkProgram(shaderProgram_);
    
        GLint linked;
        glGetProgramiv(shaderProgram_, GL_LINK_STATUS, &linked);
        if (!linked) {
            PrintProgramLinkError(shaderProgram_);
            glDeleteProgram(shaderProgram_);
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
            return false;
        }
    
        glUseProgram(shaderProgram_);
    
        positionAttrib_ = glGetAttribLocation(shaderProgram_, "aPosition");
        texCoordAttrib_ = glGetAttribLocation(shaderProgram_, "aTexCoord");
        textureUniform_ = glGetUniformLocation(shaderProgram_, "uTexture");
    
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    
        return true;
    }
    
    void ImageRender::PrintProgramLinkError(GLuint program)
    {
        GLint infoLen = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen > 1) {
            std::unique_ptr<char[]> infoLog = std::make_unique<char[]>(infoLen);
            glGetProgramInfoLog(program, infoLen, nullptr, infoLog.get());
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN,
                         "ImageRender", "Error linking program: %{public}s", infoLog.get());
        }
    }
    ```


2. **创建OH_NativeImage实例**。
    <!-- @[nativeimage_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->
    
    ``` C++
    glGenTextures(1, &nativeImageTexId_);
    // ...
    nativeImage_ = OH_NativeImage_Create(nativeImageTexId_, GL_TEXTURE_EXTERNAL_OES);
    ```

3. **获取对应的数据生产者端NativeWindow**。
    <!-- @[nativeimage_acquire_nativewindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->
    
    ``` C++
    nativeWindow_ = OH_NativeImage_AcquireNativeWindow(image);
    ```

4. **设置NativeWindow的宽高**。
    <!-- @[set_buffer_geometry](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->
    
    ``` C++
    int32_t result = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_BUFFER_GEOMETRY,
        static_cast<int32_t>(width_), static_cast<int32_t>(height_));
    if (result != SUCCESS) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "OHNativeRender", "Failed to set buffer geometry.");
        return false;
    }
    ```

5. **将生产的内容写入OHNativeWindowBuffer**。

    1. 从NativeWindow中获取OHNativeWindowBuffer。
        <!-- @[nativewindow_request_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->
        
        ``` C++
        OHNativeWindowBuffer *buffer = nullptr;
        int releaseFenceFd = INVALID_FD;
        int32_t result = OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow_, &buffer, &releaseFenceFd);
        if (result != SUCCESS || buffer == nullptr) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN,
                         "OHNativeRender", "Failed to request buffer, ret : %{public}d.", result);
            return;
        }
        // ...
        BufferHandle *handle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
        ```

    2. 将生产的内容写入OHNativeWindowBuffer。
        <!-- @[write_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->
        
        ``` C++
        // 使用 mmap 获取虚拟地址
        void *mappedAddr = mmap(nullptr, handle->size, PROT_READ | PROT_WRITE, MAP_SHARED, handle->fd, 0);
        if (mappedAddr == MAP_FAILED) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "OHNativeRender", "Failed to mmap buffer.");
            return;
        }
    
        // 获取像素指针
        uint32_t *pixel = static_cast<uint32_t *>(mappedAddr);
    
        // 调用封装的函数来绘制渐变
        DrawGradient(pixel, handle->stride / BYTES_PER_PIXEL, height_);
    
        // 解除内存映射
        result = munmap(mappedAddr, handle->size);
        if (result == FAILURE) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "OHNativeRender", "Failed to munmap buffer.");
        }
        // ...
        void OHNativeRender::DrawGradient(uint32_t* pixel, uint64_t width, uint64_t height)
        {
            static double time = 0.0;
            time += ANIMATION_SPEED_INCREMENT;
            double offset = (sin(time) + MAX_INTENSITY) / INTENSITY_MULTIPLIER;
        
            // 箭头参数
            const int arrowSize = std::min(width, height) / ARROW_SIZE_DIVISOR;
            const int arrowX = width / ARROW_SIZE_DIVISOR;
            const int arrowY = height / ARROW_SIZE_DIVISOR;
            const int stemWidth = arrowSize / STEM_WIDTH_DIVISOR;
            const int headWidth = arrowSize / HEAD_WIDTH_DIVISOR;
            const int headLength = arrowSize / HEAD_LENGTH_DIVISOR;
            const int stemStart = arrowX - arrowSize / ARROW_SIZE_DIVISOR;
            const int stemEnd = arrowX + arrowSize / ARROW_SIZE_DIVISOR - headLength;
        
            for (uint64_t y = 0; y < height; y++) {
                for (uint64_t x = 0; x < width; x++) {
                    double normalizedX = static_cast<double>(x) / static_cast<double>(width - 1);
                    bool isArrow = false;
        
                    if ((x >= stemStart && x <= stemEnd && y >= arrowY - stemWidth * HEAD_SLOPE_MULTIPLIER &&
                        y <= arrowY + stemWidth * HEAD_SLOPE_MULTIPLIER) || (x >= stemEnd && x <= stemEnd + headLength &&
                        fabs(static_cast<int>(y - arrowY)) <= (headWidth * HEAD_SLOPE_MULTIPLIER) *
                        (1.0 - static_cast<double>(x - stemEnd) / headLength))) {
                        isArrow = true;
                    }
        
                    uint8_t red = static_cast<uint8_t>((1.0 - normalizedX) * MAX_COLOR_VALUE);
                    uint8_t blue = static_cast<uint8_t>(normalizedX * MAX_COLOR_VALUE);
                    uint8_t green = 0;
                    uint8_t alpha = MAX_COLOR_VALUE;
                    if (isArrow) {
                        red = green = blue = MAX_COLOR_VALUE;
                    }
                    double intensity = fabs(normalizedX - offset);
                    intensity = MAX_INTENSITY - std::min(INTENSITY_MULTIPLIER * intensity, INTENSITY_LIMIT);
                    intensity = std::max(intensity, MIN_INTENSITY);
        
                    red = static_cast<uint8_t>(red * intensity);
                    green = static_cast<uint8_t>(green * intensity);
                    blue = static_cast<uint8_t>(blue * intensity);
        
                    *pixel++ = (static_cast<uint32_t>(alpha) << ALPHA_SHIFT) | (static_cast<uint32_t>(red) << RED_SHIFT) |
                        (static_cast<uint32_t>(green) << GREEN_SHIFT) | (static_cast<uint32_t>(blue) << BLUE_SHIFT);
                }
            }
        }
        ```

        
    3. 将OHNativeWindowBuffer提交到NativeWindow。
        <!-- @[flush_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->
        
        ``` C++
        // 设置刷新区域
        Region region{nullptr, 0};
        // 提交给消费者
        result = OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, buffer, NO_FENCE, region);
        if (result != SUCCESS) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN,
                         "OHNativeRender", "Failed to flush buffer, result : %{public}d.", result);
        }
        ```


6. **更新内容到OpenGL纹理**。
   <!-- @[update_surfaceimage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->
   
   ``` C++
       int32_t ret = OH_NativeImage_UpdateSurfaceImage(nativeImage_);
       if (ret != 0) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "RenderEngine",
                        "OH_NativeImage_UpdateSurfaceImage failed, ret: %{public}d, texId: %{public}u",
                        ret, nativeImageTexId_);
           return;
       }
   
       UpdateTextureMatrix();
       if (imageRender_) {
           imageRender_->Render();
       } else {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "RenderEngine", "ImageRender is null");
       }
       // ...
   
   void RenderEngine::UpdateTextureMatrix()
   {
       float matrix[16];
       int32_t ret = OH_NativeImage_GetTransformMatrixV2(nativeImage_, matrix);
       if (ret != 0) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "RenderEngine",
                        "OH_NativeImage_GetTransformMatrixV2 failed, ret: %{public}d", ret);
           return;
       }
       imageRender_->SetTransformMatrix(matrix);
   }
   ```


7. **解绑OpenGL纹理，绑定到新的外部纹理上**。
   <!-- @[nativeimage_change_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->
   
   ``` C++
   // 将OH_NativeImage实例从当前OpenGL ES上下文分离
   OH_NativeImage_DetachContext(nativeImage_);
   glGenTextures(1, &nativeImageTexId_);
   glBindTexture(GL_TEXTURE_EXTERNAL_OES, nativeImageTexId_);
   // ...
   int ret = OH_NativeImage_AttachContext(nativeImage_, nativeImageTexId_);
   ```


8. **OH_NativeImage实例使用完需要销毁掉**。
   <!-- @[destroy_nativeimage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->
   
   ``` C++
   OH_NativeImage_Destroy(&nativeImage_);
   ```


## 相关实例

针对NativeImage的开发，有以下相关实例可供参考：

- [Native Window（API12）](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow)
- [基于NdkNativeImage的平滑渐变动画效果（API12）](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage)
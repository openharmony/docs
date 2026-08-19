# NativeImage Development (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=ccef03d6ee99dcba5b0a6890aa3d1cd03c3eb62f translatedAt=2026-08-15T01:51:33.958Z pushedAt=2026-08-15T08:27:28.220Z -->

## Overview

The NativeImage module is used for associating a surface with an OpenGL external texture. It functions as the consumer of a graphics queue. You can use the APIs of this module to obtain and use a buffer, and output the buffer content to the associated OpenGL external texture.

The following scenario is common for NativeImage development:

* Use the NativeImage APIs to create an **OH_NativeImage** instance as the consumer and obtain the corresponding **OHNativeWindow** instance (functioning as the producer). Use the native window APIs to fill in and flush the buffer, and then use the NativeImage APIs to update the buffer content to an OpenGL ES texture. The NativeImage module must be used together with the native window, native buffer, EGL, and GLES3 modules.

## Available APIs

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_NativeImage_Create (uint32_t textureId, uint32_t textureTarget) | Creates an **OH_NativeImage** instance to be associated with the specified OpenGL ES texture ID and target. This function must be used in pair with **OH_NativeImage_Destroy**. Otherwise, memory leak occurs. |
| OH_NativeImage_AcquireNativeWindow (OH_NativeImage \*image)  | Obtains an **OHNativeWindow** instance associated with an **OH_NativeImage** instance. It is unnecessary to manually release this **OHNativeWindow** with **OH_NativeWindow_DestroyNativeWindow** as it will be automatically freed upon calling **OH_NativeImage_Destroy**. Failing to do so could result in memory access violations after the memory has been freed, which might cause the application to crash.|
| OH_NativeImage_AttachContext (OH_NativeImage \*image, uint32_t textureId) | Attaches an **OH_NativeImage** instance to the current OpenGL ES context. The OpenGL ES texture will be bound to a **GL_TEXTURE_EXTERNAL_OES** instance and updated through the **OH_NativeImage** instance.|
| OH_NativeImage_DetachContext (OH_NativeImage \*image)        | Detaches an **OH_NativeImage** instance from the current OpenGL ES context.             |
| OH_NativeImage_UpdateSurfaceImage (OH_NativeImage \*image)   | Updates the OpenGL ES texture associated with the latest frame through an **OH_NativeImage** instance.     |
| OH_NativeImage_GetTimestamp (OH_NativeImage \*image)         | Obtains the timestamp of the texture image for which **OH_NativeImage_UpdateSurfaceImage** was recently called.|
| OH_NativeImage_GetTransformMatrixV2 (OH_NativeImage \*image, float matrix[16]) | Obtains the transformation matrix of the texture image for which **OH_NativeImage_UpdateSurfaceImage** was recently called. |
| OH_NativeImage_Destroy (OH_NativeImage \*\*image)            | Destroys an **OH_NativeImage** instance created by calling **OH_NativeImage_Create**. After the instance is destroyed, the pointer to it is assigned **NULL**.|

For details about the APIs, see [OH_NativeImage](../reference/apis-arkgraphics2d/capi-oh-nativeimage.md).

## How to Develop

The following steps describe how to use the NativeImage APIs to create an **OH_NativeImage** instance as the consumer and update the data to an OpenGL external texture.

**Adding Dynamic Link Libraries**

Add the following library file to the **CMakeLists.txt** file.

```txt
libEGL.so
libGLESv3.so
libnative_image.so
libnative_window.so
libnative_buffer.so
```

**Including Header Files**

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

1. Initialize the EGL environment.

    Refer to the code snippet below. For details about how to use the XComponent, see [XComponent Development](../ui/napi-xcomponent-guidelines.md).

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

2. Create an **OH_NativeImage** instance.

    <!-- @[nativeimage_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->

    ``` C++
    glGenTextures(1, &nativeImageTexId_);
    // ...
    nativeImage_ = OH_NativeImage_Create(nativeImageTexId_, GL_TEXTURE_EXTERNAL_OES);
    ```

3. Obtain the **OHNativeWindow** instance that functions as the producer.

    <!-- @[nativeimage_acquire_nativewindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->

    ``` C++
    nativeWindow_ = OH_NativeImage_AcquireNativeWindow(image);
    ```

4. Set the width and height of the **OHNativeWindow** instance.

    <!-- @[set_buffer_geometry](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->

    ``` C++
    int32_t result = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_BUFFER_GEOMETRY,
        static_cast<int32_t>(width_), static_cast<int32_t>(height_));
    if (result != SUCCESS) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "OHNativeRender", "Failed to set buffer geometry.");
        return false;
    }
    ```

5. Write the produced content to the **OHNativeWindowBuffer**.

    1. Obtain an **OHNativeWindowBuffer** instance from the **NativeWindow** instance.

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

    2. Write the produced content to the **OHNativeWindowBuffer**.

        <!-- @[write_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->

        ``` C++
        // Use mmap to obtain the virtual address.
        void *mappedAddr = mmap(nullptr, handle->size, PROT_READ | PROT_WRITE, MAP_SHARED, handle->fd, 0);
        if (mappedAddr == MAP_FAILED) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN, "OHNativeRender", "Failed to mmap buffer.");
            return;
        }

        // Obtain the pixel pointer.
        uint32_t *pixel = static_cast<uint32_t *>(mappedAddr);

        // Call the encapsulated function to draw gradients.
        DrawGradient(pixel, handle->stride / BYTES_PER_PIXEL, height_);

        // Unmap the memory.
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

            // Arrow parameters.
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

    3. Flush the **OHNativeWindowBuffer** to the **NativeWindow**.

        <!-- @[flush_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/native_render.cpp) -->

        ``` C++
        // Set the dirty region.
        Region region{nullptr, 0};
        // Submit to the consumer.
        result = OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, buffer, NO_FENCE, region);
        if (result != SUCCESS) {
            OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_PRINT_DOMAIN,
                         "OHNativeRender", "Failed to flush buffer, result : %{public}d.", result);
        }
        ```

6. Update the content to the OpenGL texture.

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

7. Detach the **OH_NativeImage** from the current OpenGL texture and attach it to a new external texture.

   <!-- @[nativeimage_change_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->

   ``` C++
   // Detach the OH_NativeImage instance from the current OpenGL ES context.
   OH_NativeImage_DetachContext(nativeImage_);
   glGenTextures(1, &nativeImageTexId_);
   glBindTexture(GL_TEXTURE_EXTERNAL_OES, nativeImageTexId_);
   // ...
   int ret = OH_NativeImage_AttachContext(nativeImage_, nativeImageTexId_);
   ```

8. Destroy the **OH_NativeImage** instance when it is no longer needed.

   <!-- @[destroy_nativeimage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->

   ``` C++
   OH_NativeImage_Destroy(&nativeImage_);
   ```

## Samples

The following samples are provided to help you better understand how to use the NativeImage module for development:

- [Native Window (API12)](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow)

- [Smooth Gradient Animation Effect Based on NdkNativeImage (API12)](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage)
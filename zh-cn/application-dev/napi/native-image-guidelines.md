# NativeImage 开发指导

## 场景介绍

NativeImage是`OpenHarmony`提供**Surface关联OpenGL外部纹理**的模块，表示图形队列的消费者端。开发者可以通过`NativeImage`接口接收和使用`Buffer`，并将`Buffer`关联输出到OpenGL外部纹理。
针对NativeImage，常见的开发场景如下：

* 通过`NativeImage`提供的`NAPI`接口创建`NativeImage`实例作为消费者端，获取与该实例对应的`NativeWindow`作为生产者端。`NativeWindow`相关接口可用于填充`Buffer`内容并提交，`NativeImage`将`Buffer`内容更新到OpenGL外部纹理上。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeImage_Create (uint32_t textureId, uint32_t textureTarget) | 创建一个OH_NativeImage实例，该实例与OpenGL ES的纹理ID和纹理目标相关联。 | 
| OH_NativeImage_AcquireNativeWindow (OH_NativeImage \*image) | 获取与OH_NativeImage相关联的OHNativeWindow指针，该OHNativeWindow后续不再需要时需要调用 OH_NativeWindow_DestroyNativeWindow释放。 | 
| OH_NativeImage_AttachContext (OH_NativeImage \*image, uint32_t textureId) | 将OH_NativeImage实例附加到当前OpenGL ES上下文，且该OpenGL ES纹理会绑定到 GL_TEXTURE_EXTERNAL_OES，并通过OH_NativeImage进行更新。 | 
| OH_NativeImage_DetachContext (OH_NativeImage \*image) | 将OH_NativeImage实例从当前OpenGL ES上下文分离。 | 
| OH_NativeImage_UpdateSurfaceImage (OH_NativeImage \*image) | 通过OH_NativeImage获取最新帧更新相关联的OpenGL ES纹理。 | 
| OH_NativeImage_GetTimestamp (OH_NativeImage \*image) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的相关时间戳。 | 
| OH_NativeImage_GetTransformMatrix (OH_NativeImage \*image, float matrix[16]) | 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的变化矩阵。 | 
| OH_NativeImage_Destroy (OH_NativeImage \*\*image) | 销毁通过OH_NativeImage_Create创建的OH_NativeImage实例，销毁后该OH_NativeImage指针会被赋值为空。 | 

详细的接口说明请参考[native_image](../reference/native-apis/_o_h___native_image.md)。

## 开发步骤

以下步骤描述了在**OpenHarmony**中如何使用`NativeImage`提供的`NAPI`接口，创建`NativeImage`实例作为消费者端，将数据内容更新到OpenGL外部纹理上。

1. **初始化EGL环境**。
    ```c++
    EGLDisplay = GetPlatformEglDisplay(EGL_PLATFORM_OHOS_KHR, EGL_DEFAULT_DISPLAY, NULL);
    if (eglDisplay_ == EGL_NO_DISPLAY) {
        std::cout << "Failed to create EGLDisplay gl errno : " << eglGetError() << std::endl;
        return;
    }

    EGLint major, minor;
    if (eglInitialize(eglDisplay_, &major, &minor) == EGL_FALSE) {
        std::cout << "Failed to initialize EGLDisplay" << std::endl;
        return;
    }

    if (eglBindAPI(EGL_OPENGL_ES_API) == EGL_FALSE) {
        std::cout << "Failed to bind OpenGL ES API" << std::endl;
        return;
    }

    unsigned int ret;
    EGLint count;
    EGLint config_attribs[] = { EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_RED_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8, EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_NONE };

    ret = eglChooseConfig(eglDisplay_, config_attribs, &config_, 1, &count);
    if (!(ret && static_cast<unsigned int>(count) >= 1)) {
        std::cout << "Failed to eglChooseConfig" << std::endl;
        return;
    }

    static const EGLint context_attribs[] = { EGL_CONTEXT_CLIENT_VERSION, EGL_CONTEXT_CLIENT_VERSION_NUM, EGL_NONE };

    eglContext_ = eglCreateContext(eglDisplay_, config_, EGL_NO_CONTEXT, context_attribs);
    if (eglContext_ == EGL_NO_CONTEXT) {
        std::cout << "Failed to create egl context %{public}x, error:" << eglGetError() << std::endl;
        return;
    }

    eglMakeCurrent(eglDisplay_, EGL_NO_SURFACE, EGL_NO_SURFACE, eglContext_);

    std::cout << "Create EGL context successfully, version" << major << "." << minor << std::endl;
    ```
   
2. **创建NativeImage实例**。
    ```c++
    // 创建 OpenGL 纹理
    GLuint textureId;
    glGenTextures(1, &textureId);
    // 创建 NativeImage 实例，关联 OpenGL 纹理
    OH_NativeImage* image = OH_NativeImage_Create(textureId, GL_TEXTURE_2D);
    ```

3. **获取对应的数据生产者端NativeWindow**。
    ```c++
    // 获取生产者NativeWindow
    OHNativeWindow* nativeWindow = OH_NativeImage_AcquireNativeWindow(image);
    // 通过 OH_NativeWindow_NativeWindowRequestBuffer 获取 NativeWindowBuffer 实例
    OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow_, &buffer, &fenceFd);
    // 通过 OH_NativeWindow_GetNativeBufferHandleFromNative 获取 buffer 的 handle
    BufferHandle* bufferHandle = OH_NativeWindow_GetNativeBufferHandleFromNative(buffer);
    ```

4. **将生产的内容写入NativeWindowBuffer**。
    1. 设置NativeWindowBuffer的属性
    ```c++
    // 设置 NativeWindowBuffer 的读写场景
    int code = SET_USAGE;
    int32_t usage = BUFFER_USAGE_CPU_READ | BUFFER_USAGE_CPU_WRITE | BUFFER_USAGE_MEM_DMA;
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, usage);
    // 设置 NativeWindowBuffer 的宽高
    code = SET_BUFFER_GEOMETRY;
    int32_t width = 0x100;
    int32_t height = 0x100;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
    // 设置 NativeWindowBuffer 的步长
    code = SET_STRIDE;
    int32_t stride = 0x8;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, stride);
    // 设置 NativeWindowBuffer 的格式
    code = SET_FORMAT;
    int32_t format = PIXEL_FMT_RGBA_8888;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, format);
    ```
    2. 从图形队列申请NativeWindowBuffer
    ```c++
    struct NativeWindowBuffer* buffer = nullptr;
    int fenceFd;
    // 通过 OH_NativeWindow_NativeWindowRequestBuffer 获取 NativeWindowBuffer 实例
    OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &fenceFd);
    // 通过 OH_NativeWindow_GetNativeBufferHandleFromNative 获取 buffer 的 handle
    BufferHandle* bufferHandle = OH_NativeWindow_GetNativeBufferHandleFromNative(buffer);
    ```
    3. 将生产的内容写入NativeWindowBuffer
    ```c++
    auto data = static_cast<uint8_t *>(buffer->sfbuffer->GetVirAddr());
    static uint32_t value = 0x00;
    value++;

    uint32_t *pixel = static_cast<uint32_t *>(data);
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0;  y < height; y++) {
            *pixel++ = value;
        }
    }
    ```
    4. 提交NativeWindowBuffer到图形队列
    ```c++
    // 设置刷新区域，如果Region中的Rect为nullptr,或者rectNumber为0，则认为NativeWindowBuffer全部有内容更改。
    Region region{nullptr, 0};
    // 通过OH_NativeWindow_NativeWindowFlushBuffer 提交给消费者使用，例如：显示在屏幕上。
    OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
    ```

5. **更新内容到OpenGL纹理**。
    ```c++
    // 更新内容到OpenGL纹理。
    int32_t ret = OH_NativeImage_UpdateSurfaceImage(image);
    if (ret != SURFACE_ERROR_OK) {
        std::cout << "OH_NativeImage_UpdateSurfaceImage failed" << std::endl;
        return -1;
    }
    // 获取最近调用OH_NativeImage_UpdateSurfaceImage的纹理图像的时间戳和变化矩阵。
    int64_t timeStamp = OH_NativeImage_GetTimestamp(image);
    if (timeStamp == SURFACE_ERROR_ERROR) {
        std::cout << "OH_NativeImage_GetTimestamp failed" << std::endl;
        return -1;
    }
    float matrix[16];
    ret = OH_NativeImage_GetTransformMatrix(image, matrix);
    if (ret != SURFACE_ERROR_OK) {
        std::cout << "OH_NativeImage_GetTransformMatrix failed" << std::endl;
        return -1;
    }
    ```

6. **解绑OpenGL纹理，绑定到新的外部纹理上**。
    ```c++
    // 将OH_NativeImage实例从当前OpenGL ES上下文分离
    ret = OH_NativeImage_DetachContext(image);
    if (ret != SURFACE_ERROR_OK) {
        std::cout << "OH_NativeImage_DetachContext failed" << std::endl;
        return -1;
    }
    // 将OH_NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到 GL_TEXTURE_EXTERNAL_OES, 并通过OH_NativeImage进行更新
    GLuint textureId2;
    glGenTextures(1, &textureId2);
    ret = OH_NativeImage_AttachContext(image, textureId2);
    ```

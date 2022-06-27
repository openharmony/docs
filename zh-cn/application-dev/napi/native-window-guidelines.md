# NativeWindow 开发指导

## 场景介绍

NativeWindow是`OpenHarmony`**本地平台化窗口**，包括从`Surface`构建`NativeWindow`，从`SurfaceBuffer`构建出`NativeWindowBuffer`的能力，开发者可以通过`NativeWindow`接口进行申请和提交`Buffer`。
针对NativeWindow，常见的开发场景如下：

* 通过`Native C++`代码绘制内容并显示在屏幕上
* 在适配EGL层的`eglswapbuffer`接口时，进行提交和申请`Buffer`

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeWindow_CreateNativeWindowFromSurface (void \*pSurface) | 创建NativeWindow实例，每次调用都会产生一个新的NativeWindow实例。 | 
| OH_NativeWindow_DestroyNativeWindow (struct NativeWindow \*window) | 将NativeWindow对象的引用计数减1，当引用计数为0的时候，该NativeWindow对象会被析构掉。 | 
| OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void \*pSurfaceBuffer) | 创建NativeWindowBuffer实例，每次调用都会产生一个新的NativeWindowBuffer实例。 | 
| OH_NativeWindow_DestroyNativeWindowBuffer (struct NativeWindowBuffer \*buffer) | 将NativeWindowBuffer对象的引用计数减1，当引用计数为0的时候，该NativeWindowBuffer对象会被析构掉。 | 
| OH_NativeWindow_NativeWindowRequestBuffer (struct NativeWindow \*window struct NativeWindowBuffer \*\*buffer, int \*fenceFd) | 通过NativeWindow对象申请一块NativeWindowBuffer，用以内容生产。 | 
| OH_NativeWindow_NativeWindowFlushBuffer (struct NativeWindow \*window, struct NativeWindowBuffer \*buffer, int fenceFd, Region region) | 通过NativeWindow将生产好内容的NativeWindowBuffer放回到Buffer队列中，用以内容消费。 | 
| OH_NativeWindow_NativeWindowCancelBuffer (struct NativeWindow \*window, struct NativeWindowBuffer \*buffer) | 通过NativeWindow将之前申请出来的NativeWindowBuffer返还到Buffer队列中，供下次再申请。 | 
| OH_NativeWindow_NativeWindowHandleOpt (struct NativeWindow \*window, int code,...) | 设置/获取NativeWindow的属性，包括设置/获取宽高、内容格式等。 | 
| OH_NativeWindow_GetBufferHandleFromNative (struct NativeWindowBuffer \*buffer) | 通过NativeWindowBuffer获取该buffer的BufferHandle指针。 | 
| OH_NativeWindow_NativeObjectReference (void \*obj) | 增加一个NativeObject的引用计数。 | 
| OH_NativeWindow_NativeObjectUnreference (void \*obj) | 减少一个NativeObject的引用计数，当引用计数减少为0时，该NativeObject将被析构掉。 | 
| OH_NativeWindow_GetNativeObjectMagic (void \*obj) | 获取NativeObject的MagicId。 | 

详细的接口说明请参考[native_window](../reference/native-apis/_native_window.md)。

## 开发步骤

以下步骤描述了在**OpenHarmony**中如何利用`OH_NativeXComponent`通过`Native C++`代码绘制内容并显示在屏幕上。

1. **在页面中定义XComponent组件**，在`index.ets`中定义一个`texture`类型的`XComponent`，用于显示内容。
   ```js
    XComponent({ id: 'xcomponentId', type: 'texture', libraryname: 'nativerender'})
        .borderColor(Color.Red)
        .borderWidth(5)
        .onLoad(() => {})
        .onDestroy(() => {})
   ```

2. **获取OH_NativeXComponent实例**。使用 `napi_get_named_property` 接口获取一个`OH_NativeXComponent`实例 `nativeXComponent`，通过注册该实例的回调接口获取`NativeWindow`实例。

    ```c++
    // 定义 napi instance
    napi_value exportInstance = nullptr;
    // 定义一个 OH_NativeXComponent 实例
    OH_NativeXComponent *nativeXComponent = nullptr;
    // 通过 OH_NATIVE_XCOMPONENT_OBJ export 实例
    napi_getname_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
    // 将 napi instance 转化为 OH_NativeXComponent 实例
    napi_unwarp(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));
    ```

3. **定义回调函数OnSurfaceCreated**。用于在`Surface`创建时，通过回调函数初始化开发者的渲染环境，例如`Skia`渲染环境。并将要显示的内容写入`NativeWindow`：

    ```c++
    void OnSufaceCreatedCB(NativeXComponent* component, void* window) {
        //获取 native window 的宽高
        uint64_t width_ = 0, height_ = 0;
        OH_NativeXComponent_GetXComponentSize(nativeXComponent, window, &width_, &height_);
        // 将void* 转换为 NativeWindow 实例，NativeWindow 定义在 native_window/external_window.h 中
        NativeWindow* nativeWindow_ = (NativeWindow*)(window);

        // 通过 OH_NativeWindow_NativeWindowHandleOpt 设置或者获取NativeWindow的属性
        // 1.通过 SET_USAGE 设置 Native Window 的 usage 属性, 例如：HBM_USE_CPU_READ
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_USAGE, HBM_USE_CPU_READ | HBM_USE_CPU_WRITE |HBM_USE_MEM_DMA);
        // 2.通过 SET_BUFFER_GEOMETRY 设置 Native Window 的 宽高属性
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_BUFFER_GEOMETRY, width_, height_);
        // 3.通过 SET_FORMAT 设置 Native Window 的 format 属性, 例如：PIXEL_FMT_RGBA_8888
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, PIXEL_FMT_RGBA_8888);
        // 4.通过 SET_STRIDE 设置 Native Window 的 stride 属性
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_STRIDE, 0x8);

        // 通过 OH_NativeWindow_NativeWindowRequestBuffer 获取 NativeWindowBuffer 实例
        struct NativeWindowBuffer* buffer = nullptr;
        int fenceFd;
        OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow_, &buffer, &fenceFd);

        // 通过 OH_NativeWindow_GetNativeBufferHandleFromNative 获取 buffer handle
        BufferHandle* bufferHandle = OH_NativeWindow_GetNativeBufferHandleFromNative(buffer);

        // 通过 BufferHandle 创建Skia Bitmap
        SkBitmap bitmap;
        SkImageInfo imageInfo = ...
        bitmap.setInfo(imageInfo, bufferHandle->stride);
        bitmap.setPixels(bufferHandle->virAddr);
        //创建 Skia Canvas 并将内容写入naitve window
        ...

        //写入完成后，通过OH_NativeWindwo_NativeWindowFlushBuffer 提交给消费者使用，例如：显示在屏幕上
        Regoin region{nullptr, 0};
        OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, buffer, fenceFd, region)
    }
    ```

4. **注册回调函数OnSurfaceCreated等**。使用 `OH_NativeXComponent_RegisterCallback` 接口注册上一步中创建的回调函数。

    ```c++
    OH_NativeXComponent_Callback &callback_;
    callback_->OnSurfaceCreated = OnSufaceCreatedCB;
    callback_->OnSurfaceChanged = OnSufaceChangedCB;
    callback_->OnSurfaceDestoryed = OnSufaceDestoryedCB;
    callback_->DispatchTouchEvent = DispatchTouchEventCB;
    OH_NativeXComponent_RegisterCallback(nativeXComponent, callback_)
    ```

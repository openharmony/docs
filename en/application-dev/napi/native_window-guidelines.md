# NativeWindow Development

## When to Use

`NativeWindow` is a local platform window of OpenHarmony. It provides APIs for you to create a native window from `Surface`, create a native window buffer from `SurfaceBuffer`, and request and flush a buffer.
The following scenarios are common for native window development:

* Drawing content using native C++ code and displaying the content on the screen
* Requesting and flushing a buffer when adapting to EGL `eglswapbuffer`

## Available APIs

| API| Description|
| -------- | -------- |
| OH_NativeWindow_CreateNativeWindowFromSurface (void \*pSurface) | Creates a `NativeWindow` instance. A new `NativeWindow` instance is created each time this function is called.|
| OH_NativeWindow_DestroyNativeWindow (struct NativeWindow \*window) | Decreases the reference count of a `NativeWindow` instance by 1 and, when the reference count reaches 0, destroys the instance.|
| OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void \*pSurfaceBuffer) | Creates a `NativeWindowBuffer` instance. A new `NativeWindowBuffer` instance is created each time this function is called.|
| OH_NativeWindow_DestroyNativeWindowBuffer (struct NativeWindowBuffer \*buffer) | Decreases the reference count of a `NativeWindowBuffer` instance by 1 and, when the reference count reaches 0, destroys the instance.|
| OH_NativeWindow_NativeWindowRequestBuffer (struct NativeWindow \*window struct NativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests a `NativeWindowBuffer` through a `NativeWindow` instance for content production.|
| OH_NativeWindow_NativeWindowFlushBuffer (struct NativeWindow \*window, struct NativeWindowBuffer \*buffer, int fenceFd, Region region) | Flushes the `NativeWindowBuffer` filled with the content to the buffer queue through a `NativeWindow` instance for content consumption.|
| OH_NativeWindow_NativeWindowCancelBuffer (struct NativeWindow \*window, struct NativeWindowBuffer \*buffer) | Returns the `NativeWindowBuffer` to the buffer queue through a `NativeWindow` instance, without filling in any content. The `NativeWindowBuffer` can be used for another request.|
| OH_NativeWindow_NativeWindowHandleOpt (struct NativeWindow \*window, int code,...) | Sets or obtains the attributes of a native window, including the width, height, and content format.|
| OH_NativeWindow_GetBufferHandleFromNative (struct NativeWindowBuffer \*buffer) | Obtains the pointer to a `BufferHandle` of a `NativeWindowBuffer` instance.|
| OH_NativeWindow_NativeObjectReference (void \*obj) | Adds the reference count of a native object.|
| OH_NativeWindow_NativeObjectUnreference (void \*obj) | Decreases the reference count of a native object and, when the reference count reaches 0, destroys this object.|
| OH_NativeWindow_GetNativeObjectMagic (void \*obj) | Obtains the magic ID of a native object.|



## How to Develop

The following steps describe how to use `OH_NativeXComponent` in OpenHarmony to draw content using native C++ code and display the content on the screen.

1. Define an `XComponent` of the `texture` type in `index.ets` for content display.
   ```js
    XComponent({ id: 'xcomponentId', type: 'texture', libraryname: 'nativerender'})
        .borderColor(Color.Red)
        .borderWidth(5)
        .onLoad(() => {})
        .onDestroy(() => {})
   ```

2. Obtain an `OH_NativeXComponent` instance (named `nativeXComponent` in this example) by calling `napi_get_named_property`, and obtain a `NativeWindow` instance by registering the callback of the `OH_NativeXComponent` instance.

    ```c++
    // Define a NAPI instance.
    napi_value exportInstance = nullptr;
    // Define an OH_NativeXComponent instance.
    OH_NativeXComponent *nativeXComponent = nullptr;
    // Use the OH_NATIVE_XCOMPONENT_OBJ export instance.
    napi_getname_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
    // Convert the NAPI instance to the OH_NativeXComponent instance.
    napi_unwarp(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));
    ```

3. Define the callback `OnSurfaceCreated`. During the creation of a `Surface`, the callback is used to initialize the rendering environment, for example, the `Skia` rendering environment, and write the content to be displayed to `NativeWindow`.

    ```c++
    void OnSufaceCreatedCB(NativeXComponent* component, void* window) {
        // Obtain the width and height of the native window.
        uint64_t width_ = 0, height_ = 0;
        OH_NativeXComponent_GetXComponentSize(nativeXComponent, window, &width_, &height_);
        // Convert void* into a NativeWindow instance. NativeWindow is defined in native_window/external_window.h.
        NativeWindow* nativeWindow_ = (NativeWindow*)(window);

        // Set or obtain the NativeWindow attributes by calling OH_NativeWindow_NativeWindowHandleOpt.
        // 1. Use SET_USAGE to set the usage attribute of the native window, for example, to HBM_USE_CPU_READ.
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_USAGE, HBM_USE_CPU_READ | HBM_USE_CPU_WRITE |HBM_USE_MEM_DMA);
        // 2. Use SET_BUFFER_GEOMETRY to set the width and height attributes of the native window.
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_BUFFER_GEOMETRY, width_, height_);
        // 3. Use SET_FORMAT to set the format attribute of the native window, for example, to PIXEL_FMT_RGBA_8888.
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, PIXEL_FMT_RGBA_8888);
        // 4. Use SET_STRIDE to set the stride attribute of the native window.
        OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, SET_STRIDE, 0x8);

        // Obtain the NativeWindowBuffer instance by calling OH_NativeWindow_NativeWindowRequestBuffer.
        struct NativeWindowBuffer* buffer = nullptr;
        int fenceFd;
        OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow_, &buffer, &fenceFd);

        // Obtain the buffer handle by calling OH_NativeWindow_GetNativeBufferHandleFromNative.
        BufferHandle* bufferHandle = OH_NativeWindow_GetNativeBufferHandleFromNative(buffer);

        // Create a Skia bitmap using BufferHandle.
        SkBitmap bitmap;
        SkImageInfo imageInfo = ...
        bitmap.setInfo(imageInfo, bufferHandle->stride);
        bitmap.setPixels(bufferHandle->virAddr);
        // Create Skia Canvas and write the content to the native window.
        ...

        // After the write operation is complete, flush the buffer by using OH_NativeWindwo_NativeWindowFlushBuffer so that the data is displayed on the screen.
        Regoin region{nullptr, 0};
        OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, buffer, fenceFd, region)
    }
    ```

4. Register the callback `OnSurfaceCreated` by using `OH_NativeXComponent_RegisterCallback`.

    ```c++
    OH_NativeXComponent_Callback &callback_;
    callback_->OnSurfaceCreated = OnSufaceCreatedCB;
    callback_->OnSurfaceChanged = OnSufaceChangedCB;
    callback_->OnSurfaceDestoryed = OnSufaceDestoryedCB;
    callback_->DispatchTouchEvent = DispatchTouchEventCB;
    OH_NativeXComponent_RegisterCallback(nativeXComponent, callback_)
    ```

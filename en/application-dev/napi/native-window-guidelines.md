# Native Window Development

## When to Use

**NativeWindow** is a local platform-based window of OpenHarmony that represents the producer of a graphics queue. It provides APIs for you to create a native window from **Surface**, create a native window buffer from **SurfaceBuffer**, and request and flush a buffer.
The following scenarios are common for native window development:

* Request a graphics buffer by using the NAPI provided by **NativeWindow**, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.
* Request and flush a buffer when adapting to the **eglswapbuffer** interface at the EGL.

## Available APIs

| API| Description|
| -------- | -------- |
| OH_NativeWindow_CreateNativeWindowFromSurface (void \*pSurface) | Creates a **NativeWindow** instance. A new **NativeWindow** instance is created each time this function is called.|
| OH_NativeWindow_DestroyNativeWindow (OHNativeWindow \*window) | Decreases the reference count of a **NativeWindow** instance by 1 and, when the reference count reaches 0, destroys the instance.|
| OH_NativeWindow_CreateNativeWindowBufferFromSurfaceBuffer (void \*pSurfaceBuffer) | Creates a **NativeWindowBuffer** instance. A new **NativeWindowBuffer** instance is created each time this function is called.|
| OH_NativeWindow_DestroyNativeWindowBuffer (OHNativeWindowBuffer \*buffer) | Decreases the reference count of a **NativeWindowBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.|
| OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests a **NativeWindowBuffer** through a **NativeWindow** instance for content production.|
| OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | Flushes the **NativeWindowBuffer** filled with the content to the buffer queue through a **NativeWindow** instance for content consumption.|
| OH_NativeWindow_NativeWindowAbortBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer) | Returns the **NativeWindowBuffer** to the buffer queue through a **NativeWindow** instance, without filling in any content. The **NativeWindowBuffer** can be used for another request.|
| OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow \*window, int code,...) | Sets or obtains the attributes of a native window, including the width, height, and content format.|
| OH_NativeWindow_GetBufferHandleFromNative (OHNativeWindowBuffer \*buffer) | Obtains the pointer to a **BufferHandle** of a **NativeWindowBuffer** instance.|
| OH_NativeWindow_NativeObjectReference (void \*obj) | Adds the reference count of a native object.|
| OH_NativeWindow_NativeObjectUnreference (void \*obj) | Decreases the reference count of a native object and, when the reference count reaches 0, destroys this object.|
| OH_NativeWindow_GetNativeObjectMagic (void \*obj) | Obtains the magic ID of a native object.|
| OH_NativeWindow_NativeWindowSetScalingMode (OHNativeWindow \*window, uint32_t sequence, OHScalingMode scalingMode) | Sets the scaling mode of the native window.|
| OH_NativeWindow_NativeWindowSetMetaData(OHNativeWindow \*window, uint32_t sequence, int32_t size, const OHHDRMetaData \*metaData) | Sets the HDR static metadata of the native window.|
| OH_NativeWindow_NativeWindowSetMetaDataSet(OHNativeWindow \*window, uint32_t sequence, OHHDRMetadataKey key, int32_t size, const uint8_t \*metaData) | Sets the HDR static metadata set of the native window.|
| OH_NativeWindow_NativeWindowSetTunnelHandle(OHNativeWindow \*window, const OHExtDataHandle \*handle) | Sets the tunnel handle to the native window.|


## How to Develop

The following describes how to use the NAPI provided by **NativeWindow** to request a graphics buffer, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.

1. Obtain a **NativeWindow** instance. For example, use **Surface** to create a **NativeWindow** instance.
    ```c++
    sptr<OHOS::Surface> cSurface = Surface::CreateSurfaceAsConsumer();
    sptr<IBufferConsumerListener> listener = new BufferConsumerListenerTest();
    cSurface->RegisterConsumerListener(listener);
    sptr<OHOS::IBufferProducer> producer = cSurface->GetProducer();
    sptr<OHOS::Surface> pSurface = Surface::CreateSurfaceAsProducer(producer);
    OHNativeWindow* nativeWindow = OH_NativeWindow_CreateNativeWindow(&pSurface);
    ```

2. Set the attributes of a native window buffer by using **OH_NativeWindow_NativeWindowHandleOpt**.
    ```c++
    // Set the read and write scenarios of the native window buffer.
    int code = SET_USAGE;
    int32_t usage = BUFFER_USAGE_CPU_READ | BUFFER_USAGE_CPU_WRITE | BUFFER_USAGE_MEM_DMA;
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, usage);
    // Set the width and height of the native window buffer.
    code = SET_BUFFER_GEOMETRY;
    int32_t width = 0x100;
    int32_t height = 0x100;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
    // Set the step of the native window buffer.
    code = SET_STRIDE;
    int32_t stride = 0x8;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, stride);
    // Set the format of the native window buffer.
    code = SET_FORMAT;
    int32_t format = PIXEL_FMT_RGBA_8888;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, format);
    ```

3. Request a native window buffer from the graphics queue.
    ```c++
    struct NativeWindowBuffer* buffer = nullptr;
    int fenceFd;
    // Obtain the NativeWindowBuffer instance by calling OH_NativeWindow_NativeWindowRequestBuffer.
    OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow_, &buffer, &fenceFd);
    // Obtain the buffer handle by calling OH_NativeWindow_GetNativeBufferHandleFromNative.
    BufferHandle* bufferHandle = OH_NativeWindow_GetNativeBufferHandleFromNative(buffer);
    ```

4. Write the produced content to the native window buffer.
    ```c++
    auto image = static_cast<uint8_t *>(buffer->sfbuffer->GetVirAddr());
    static uint32_t value = 0x00;
    value++;

    uint32_t *pixel = static_cast<uint32_t *>(image);
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0;  y < height; y++) {
            *pixel++ = value;
        }
    }
    ```

5. Flush the native window buffer to the graphics queue.

    ```c++
    // Set the refresh region. If Rect in Region is a null pointer or rectNumber is 0, all contents in the native window buffer are changed.
    Region region{nullptr, 0};
    // Flush the buffer to the consumer through OH_NativeWindow_NativeWindowFlushBuffer, for example, by displaying it on the screen.
    OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, buffer, fenceFd, region);
    ```

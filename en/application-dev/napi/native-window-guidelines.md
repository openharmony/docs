# NativeWindow Development

## When to Use

**NativeWindow** is a local platform-based window of OpenHarmony that represents the producer of a graphics queue. It provides APIs for you to request and flush a buffer and configure buffer attributes.

The following scenarios are common for NativeWindow development:

* Request a graphics buffer by using the native API provided by **NativeWindow**, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.
* Request and flush a buffer when adapting to the **eglswapbuffer** interface at the EGL.

## Available APIs

| API| Description|
| -------- | -------- |
| OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.|
| OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | Flushes the **OHNativeWindowBuffer** filled with the content to the buffer queue through an **OHNativeWindow** instance for content consumption.|
| OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow \*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow**, including the width, height, and content format.|

For details about the APIs, see [native_window](../reference/native-apis/_native_window.md).

## How to Develop

The following describes how to use the native APIs provided by **NativeWindow** to request a graphics buffer, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.

**Header File**
```c++
#include <native_window/external_window.h>
```

1. Obtain an **OHNativeWindow** instance, which can be obtained by running the APIs provided by [OH_NativeXComponent_Callback](../reference/native-apis/_o_h___native_x_component___callback.md).
   1. Define **XComponent** in an .ets file.
        ```ts
        XComponent({ id: 'xcomponentId', type: 'surface', libraryname: 'nativerender'})
            .onLoad((context) => {
                this.context = context;
            })
            .onDestroy(() => {
            })
        ```
   2. Obtain **NativeXComponent** at the native C++ layer.
       ```c++
       napi_value exportInstance = nullptr;
       napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);

       OH_NativeXComponent *nativeXComponent = nullptr;
       napi_unwrap(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));

       char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = { };
       uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
       OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize);
       ```
   3. Define **OH_NativeXComponent_Callback**.
       ```c++
       // Define the callback.
       void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
       {
           // Obtain an OHNativeWindow instance.
           OHNativeWindow* nativeWindow = window;
           // ...
       }
       void OnSurfaceChangedCB(OH_NativeXComponent* component, void* window)
       {
           // Obtain an OHNativeWindow instance.
           OHNativeWindow* nativeWindow = window;
           // ...
       }
       void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
       {
           // Obtain an OHNativeWindow instance.
           OHNativeWindow* nativeWindow = window;
           // ...
       }
       void DispatchTouchEventCB(OH_NativeXComponent* component, void* window)
       {
           // Obtain an OHNativeWindow instance.
           OHNativeWindow* nativeWindow = window;
           // ...
       }
       ```
       ```c++
       // Initialize OH_NativeXComponent_Callback.
       OH_NativeXComponent_Callback callback_;
       callback_->OnSurfaceCreated = OnSurfaceCreatedCB;
       callback_->OnSurfaceChanged = OnSurfaceChangedCB;
       callback_->OnSurfaceDestroyed = OnSurfaceDestroyedCB;
       callback_->DispatchTouchEvent = DispatchTouchEventCB;
       ```
   4. Register **OH_NativeXComponent_Callback** with **NativeXComponent**.
       ```c++
       OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback_);
       ```

2. Set the attributes of an **OHNativeWindowBuffer** by using **OH_NativeWindow_NativeWindowHandleOpt**.
    ```c++
    // Set the width and height of the OHNativeWindowBuffer.
    code = SET_BUFFER_GEOMETRY;
    int32_t width = 0x100;
    int32_t height = 0x100;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
    // Set the step of the OHNativeWindowBuffer.
    code = SET_STRIDE;
    int32_t stride = 0x8;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, stride);
    ```

3. Request an **OHNativeWindowBuffer** from the graphics queue.
    ```c++
    OHNativeWindowBuffer* buffer = nullptr;
    int fenceFd;
    // Obtain the OHNativeWindowBuffer instance by calling OH_NativeWindow_NativeWindowRequestBuffer.
    OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow_, &buffer, &fenceFd);
    // Obtain the buffer handle by calling OH_NativeWindow_GetNativeBufferHandleFromNative.
    BufferHandle* bufferHandle = OH_NativeWindow_GetNativeBufferHandleFromNative(buffer);
    ```

4. Write the produced content to the **OHNativeWindowBuffer**.
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

5. Flush the **OHNativeWindowBuffer** to the graphics queue.
    ```c++
    // Set the refresh region. If Rect in Region is a null pointer or rectNumber is 0, all contents in the OHNativeWindowBuffer are changed.
    Region region{nullptr, 0};
    // Flush the buffer to the consumer through OH_NativeWindow_NativeWindowFlushBuffer, for example, by displaying it on the screen.
    OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow_, buffer, fenceFd, region);
    ```

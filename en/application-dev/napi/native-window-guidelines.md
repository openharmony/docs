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

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**:
```txt
libace_ndk.z.so
libnative_window.so
```

**Header File**
```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <native_window/external_window.h>
```

1. Obtain an **OHNativeWindow** instance. 

    You can call the APIs provided by [OH_NativeXComponent_Callback](../reference/native-apis/_o_h___native_x_component___callback.md) to obtain an **OHNativeWindow** instance. An example code snippet is provided below. For details about how to use the **\<XComponent>**, see [XComponent](../ui/arkts-common-components-xcomponent.md).
    1. Add an **\<XComponent>** to the .ets file.
        ```ts
        XComponent({ id: 'xcomponentId', type: 'surface', libraryname: 'entry'})
            .width(360)
            .height(360)
        ```
    2. Obtain **NativeXComponent** at the native C++ layer.
        ```c++
        napi_value exportInstance = nullptr;
        // Parse the attribute of the wrapped NativeXComponent pointer.
        napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
        OH_NativeXComponent *nativeXComponent = nullptr;
        // Use the napi_unwrap API to parse the NativeXComponent instance pointer.
        napi_unwrap(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));
        ```
    3. Define **OH_NativeXComponent_Callback**.
        ```c++
        // Define the callback.
        void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
        {
            // Obtain an OHNativeWindow instance.
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }
        void OnSurfaceChangedCB(OH_NativeXComponent* component, void* window)
        {
            // Obtain an OHNativeWindow instance.
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }
        void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
        {
            // Obtain an OHNativeWindow instance.
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }
        void DispatchTouchEventCB(OH_NativeXComponent* component, void* window)
        {
            // Obtain an OHNativeWindow instance.
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }
        ```
        ```c++
        // Initialize OH_NativeXComponent_Callback.
        OH_NativeXComponent_Callback callback;
        callback.OnSurfaceCreated = OnSurfaceCreatedCB;
        callback.OnSurfaceChanged = OnSurfaceChangedCB;
        callback.OnSurfaceDestroyed = OnSurfaceDestroyedCB;
        callback.DispatchTouchEvent = DispatchTouchEventCB;
        ```
   4. Register **OH_NativeXComponent_Callback** with **NativeXComponent**.
        ```c++
        // Register the callback.
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback);
        ```

2. Set the attributes of an **OHNativeWindowBuffer** by using **OH_NativeWindow_NativeWindowHandleOpt**.
    ```c++
    // Set the width and height of the OHNativeWindowBuffer.
    int32_t code = SET_BUFFER_GEOMETRY;
    int32_t width = 0x100;
    int32_t height = 0x100;
    // The nativeWindow instance is obtained from the callback in the previous step.
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
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
    OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &fenceFd);
    // Obtain the buffer handle by calling OH_NativeWindow_GetBufferHandleFromNative.
    BufferHandle* bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
    ```

4. Map memory.
    ```c++
    #include <sys/mman.h>

    // Use mmap() to obtain the memory virtual address of buffer handle.
    void* mappedAddr = mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0);
    if (mappedAddr == MAP_FAILED) {
        // mmap failed
    }
    ```

5. Write the produced content to the **OHNativeWindowBuffer**.
    ```c++
    static uint32_t value = 0x00;
    value++;
    uint32_t *pixel = static_cast<uint32_t *>(mappedAddr); // Use the address obtained by mmap() to access the memory.
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
    OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
    ```
6. Unmap memory.
    ```c++
    // Unmap the memory when the memory is no longer required.
    int result = munmap(mappedAddr, bufferHandle->size);
    if (result == -1) {
        // munmap failed
    }
    ```

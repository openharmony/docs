# Native Window Development (C/C++)

## When to Use

The native window module is a local platform-based window that represents the producer of a graphics queue. It provides APIs for you to request and flush a buffer and configure buffer attributes.

The following scenarios are common for native window development:

* Request a graphics buffer by using the native window API, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.
* Request and flush a buffer when adapting to the **eglswapbuffer** interface at the EGL.

## Available APIs

| API| Description| 
| -------- | -------- |
| OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.| 
| OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | Flushes the **OHNativeWindowBuffer** filled with the produced content to the buffer queue through an **OHNativeWindow** instance for content consumption.| 
| OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow \*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow** instance, including the width, height, and content format.| 

For details about the APIs, see [native_window](../reference/apis-arkgraphics2d/_native_window.md).

## How to Develop

The following describes how to use the native window APIs to request a graphics buffer, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.

**Adding Dynamic Link Libraries**

Add the following libraries to **CMakeLists.txt**:
```txt
libace_ndk.z.so
libnative_window.so
```

**Including Header Files**
```c++
#include <sys/poll.h>
#include <sys/mman.h>
#include <unistd.h>
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <native_window/external_window.h>
```

1. Obtain an **OHNativeWindow** instance.

    You can call the APIs provided by [OH_NativeXComponent_Callback](../reference/apis-arkui/_o_h___native_x_component___callback.md) to obtain an **OHNativeWindow** instance. An example code snippet is provided below. For details about how to use the **XComponent**, see [XComponent Development](../ui/napi-xcomponent-guidelines.md).
    1. Add an **XComponent** to the .ets file.
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
        // Obtain the XComponent ID.
        char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
        uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
        OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize);
        ```
    3. Define **OH_NativeXComponent_Callback**.
        ```c++
        // Define the callback.
        void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
        {
            // Obtain an OHNativeWindow instance.
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // After this callback is triggered, the reference count for the window is initialized to 1. If the window-related APIs and XComponent destructor are concurrently used,
            // you must manually adjust the reference count by using OH_NativeWindow_NativeObjectReference to increase it and OH_NativeWindow_NativeObjectUnreference to decrease it.
            // This manual management of the reference count by 1 helps to avoid issues with dangling or null pointers that could occur during concurrent calls to window APIs following the destruction of an XComponent.
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
            // After this callback is triggered, the reference count for the window is decremented by 1. When the reference count reaches 0, the window is destructed.
            // Once the window is destructed, no further API calls should be made through the window. This operation results in a crash caused by dangling or null pointers.
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
    ```

3. Request an **OHNativeWindowBuffer** from the graphics queue.
    ```c++
    OHNativeWindowBuffer* buffer = nullptr;
    int releaseFenceFd = -1;
    // Obtain the OHNativeWindowBuffer instance by calling OH_NativeWindow_NativeWindowRequestBuffer.
    ret = OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &releaseFenceFd);
    if (ret != 0 || buffer == nullptr) {
        return;
    }
    // Obtain the buffer handle by calling OH_NativeWindow_GetBufferHandleFromNative.
    BufferHandle* bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
    ```

4. Map memory.
    ```c++
    #include <sys/mman.h>

    // Use mmap() to map the shared memory allocated to the buffer handle to the user space. Image data can be written to the buffer handle by using the obtained virtual address.
    // bufferHandle->virAddr indicates the start address of the buffer handle in the shared memory, and bufferHandle->size indicates the memory usage of the buffer handle in the shared memory.
    void* mappedAddr = mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0);
    if (mappedAddr == MAP_FAILED) {
        // mmap failed
    }
    ```

5. Write the produced content to the **OHNativeWindowBuffer**.

   Before this operation, wait until **releaseFenceFd** is available. (Note that **poll** needs to be called only when **releaseFenceFd** is not **-1**.) If no data waiting for **releaseFenceFd** is available (POLLIN), problems such as artifacts, cracks, and High Efficiency Bandwidth Compression (HEBC) faults may occur. **releaseFenceFd** is a file handle created by the consumer process to indicate that the consumer has consumed the buffer, the buffer is readable, and the producer can start to fill in the buffer.
    ```c++
    int retCode = -1;
    uint32_t timeout = 3000;
    if (releaseFenceFd != -1) {
        struct pollfd pollfds = {0};
        pollfds.fd = releaseFenceFd;
        pollfds.events = POLLIN;
        do {
            retCode = poll(&pollfds, 1, timeout);
        } while (retCode == -1 && (errno == EINTR || errno == EAGAIN));
        close(releaseFenceFd); // Prevent FD leakage.
    }

    static uint32_t value = 0x00;
    value++;
    uint32_t *pixel = static_cast<uint32_t *>(mappedAddr); // Use the address obtained by mmap() to access the memory.
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0;  y < height; y++) {
            *pixel++ = value;
        }
    }
    ```

6. Flush the **OHNativeWindowBuffer** to the graphics queue.

   Note that **acquireFenceFd** of **OH_NativeWindow_NativeWindowFlushBuffer** cannot be the same as **releaseFenceFd** obtained by **OH_NativeWindow_NativeWindowRequestBuffer**. **acquireFenceFd** is the file handle passed in by the producer, and the default value **-1** can be passed. Based on **acquireFenceFd**, the consumer, after obtaining the buffer, determines when to render and display the buffered content.
    ```c++
    // Set the refresh region. If Rect in Region is a null pointer or rectNumber is 0, all contents in the OHNativeWindowBuffer are changed.
    Region region{nullptr, 0};
    int acquireFenceFd = -1;
    // Flush the buffer to the consumer through OH_NativeWindow_NativeWindowFlushBuffer, for example, by displaying it on the screen.
    OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, acquireFenceFd, region);
    ```
7. Unmap memory.
    ```c++
    // Unmap the memory when the memory is no longer required.
    int result = munmap(mappedAddr, bufferHandle->size);
    if (result == -1) {
        // munmap failed
    }
    ```


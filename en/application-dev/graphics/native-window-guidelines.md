# NativeWindow Development (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=1f370dd3425411b659f906071e53860b94f0e2f1 translatedAt=2026-08-15T01:51:39.173Z pushedAt=2026-08-15T08:28:49.622Z -->

## Overview

NativeWindow is a **local platform window** that represents the producer end of a graphics queue. It is primarily used in scenarios that require efficient graphics data processing. When you develop graphics-intensive apps such as video playback, camera preview, and game rendering, you need to efficiently write and submit graphics data in graphics buffers. In such cases, you can use **NativeWindow** APIs to request and submit **Buffer** objects and configure **Buffer** attribute information.

The following scenarios are common for NativeWindow development:

* Request a graphics buffer by using the NativeWindow API, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.

* Request and flush a buffer when adapting to the **eglswapbuffer** interface at the EGL.

## Available APIs

| API| Description| 
| -------- | -------- |
| OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | Requests an **OHNativeWindowBuffer** through an **OHNativeWindow** instance for content production.| 
| OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | Flushes the **OHNativeWindowBuffer** filled with the produced content to the buffer queue through an **OHNativeWindow** instance for content consumption.| 
| OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow \*window, int code,...) | Sets or obtains the attributes of an **OHNativeWindow** instance, including the width, height, and content format.| 

For detailed interface descriptions, see [NativeWindow](../reference/apis-arkgraphics2d/capi-nativewindow.md).

## How to Develop

Request a graphics buffer by using the NativeWindow API, write the produced graphics content to the buffer, and flush the buffer to the graphics queue.

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

    You can obtain the **OHNativeWindow** instance via the [`OH_NativeXComponent_Callback`](../reference/apis-arkui/capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-callback.md) API. The sample code is as follows. For details about how to use the **XComponent** module, see [XComponent Development Guidelines](../ui/napi-xcomponent-guidelines.md).

    1. Add an **XComponent** to the .ets file.

        <!-- @[create_native_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/ets/pages/Index.ets) -->

        ``` TypeScript
        XComponent({ id: 'xcomponentId', type: 'texture', libraryname: 'nativerender' })
          .margin({ bottom: 26 })
          .onLoad((nativeWindowContext) => {
            this.nativeWindowContext = nativeWindowContext as NativeWindowContext;
          })
        ```

    2. Obtain **NativeXComponent** at the native C++ layer.

        <!-- @[get_native_xcomponent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

        ``` C++
        napi_value exportInstance = nullptr;
        OH_NativeXComponent *nativeXComponent = nullptr;
        int32_t ret;
        char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
        uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;

        status = napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
        if (status != napi_ok) {
            return false;
        }

        status = napi_unwrap(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));
        if (status != napi_ok) {
            return false;
        }

        ret = OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize);
        if (ret != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
            return false;
        }
        ```

    3. Define **OH_NativeXComponent_Callback**.

        <!-- @[xcomponent_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

        ``` C++
        void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
        {
            // ...
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }

        void OnSurfaceChangedCB(OH_NativeXComponent* component, void* window)
        {
            // ...
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }

        void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
        {
            // ...
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }

        void DispatchTouchEventCB(OH_NativeXComponent* component, void* window)
        {
            // ...
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
        }
        // ...
        callback_.OnSurfaceCreated = OnSurfaceCreatedCB;
        callback_.OnSurfaceChanged = OnSurfaceChangedCB;
        callback_.OnSurfaceDestroyed = OnSurfaceDestroyedCB;
        callback_.DispatchTouchEvent = DispatchTouchEventCB;
        ```

    4. Register **OH_NativeXComponent_Callback** with **NativeXComponent**.

        <!-- @[register_xcomponent_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

        ``` C++
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback_);
        ```

2. Set the attributes of an `OHNativeWindowBuffer` by using `OH_NativeWindow_NativeWindowHandleOpt`. By default, the `NATIVEBUFFER_USAGE_CPU_READ` usage parameter is carried. If the CPU is not used to read and write data, you are advised to remove the `NATIVEBUFFER_USAGE_CPU_READ` usage parameter. For details, see [How do I proactively disable CPU access to window buffers to reduce power consumption?](https://developer.huawei.com/consumer/en/doc/harmonyos-faqs/faqs-arkgraphics-2d-14).

    <!-- @[set_buffer_geometry](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    int code = SET_BUFFER_GEOMETRY;
    int32_t bufferHeight = static_cast<int32_t>(height_ / 4);
    int32_t bufferWidth = static_cast<int32_t>(width_ / 2);
    OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, code, bufferWidth, bufferHeight);
    ```

3. Request an **OHNativeWindowBuffer** from the graphics queue.

    <!-- @[request_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    int releaseFenceFd = -1;
    OHNativeWindowBuffer *nativeWindowBuffer = nullptr;
    ret = OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &nativeWindowBuffer, &releaseFenceFd);
    if (ret != 0 || nativeWindowBuffer == nullptr) {
        return;
    }
    BufferHandle *bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(nativeWindowBuffer);
    ```

4. Map memory.

    <!-- @[map_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    void *mappedAddr =
        mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0);
    ```

5. Write the produced content to the **OHNativeWindowBuffer**. Before this operation, wait until **releaseFenceFd** is available. Note that **poll** needs to be called only when **releaseFenceFd** is not **-1**. If no data is available for the **releaseFenceFd** event (POLLIN), problems such as artifacts, cracks, and High Efficiency Bandwidth Compression (HEBC) faults may occur. **releaseFenceFd** is a file handle created by the consumer process to indicate that the consumer has consumed the buffer, the buffer is readable, and the producer can start to fill in the buffer.

    <!-- @[write_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    int retCode = -1;
    uint32_t timeout = 3000;
    if (releaseFenceFd != -1) {
        struct pollfd pollfds = {0};
        pollfds.fd = releaseFenceFd;
        pollfds.events = POLLIN;
        do {
            retCode = poll(&pollfds, 1, timeout);
        } while (retCode == -1 && (errno == EINTR || errno == EAGAIN));
        close(releaseFenceFd);
    }
    uint32_t *pixel = static_cast<uint32_t *>(mappedAddr);
    uint32_t value = flag_ ? 0xfff0000f : 0xff00ffff;
    for (uint64_t x = 0; x < bufferHandle->width; x++) {
        for (uint64_t y = 0; y < bufferHandle->height; y++) {
            *pixel++ = value;
        }
    }
    ```

6. Flush the **OHNativeWindowBuffer** to the graphics queue. Note that **acquireFenceFd** of **OH_NativeWindow_NativeWindowFlushBuffer** cannot be the same as **releaseFenceFd** obtained by **OH_NativeWindow_NativeWindowRequestBuffer**. **acquireFenceFd** is the file handle passed in by the producer, and the default value **-1** can be passed. Based on **acquireFenceFd**, the consumer, after obtaining the buffer, determines when to render and display the buffered content.

    <!-- @[flush_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    struct Region region = {0};
    int acquireFenceFd = -1;
    ret = OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, nativeWindowBuffer, acquireFenceFd, region);
    if (ret != NATIVE_ERROR_OK) {
        LOGE("flush failed");
        (void)OH_NativeWindow_NativeWindowAbortBuffer(nativeWindow, nativeWindowBuffer);
        return;
    }
    ```

7. Use **munmap** to cancel memory mapping.

    <!-- @[munmap_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    if (munmap(mappedAddr, bufferHandle->size) < 0) {
        OH_NativeWindow_DestroyNativeWindow(nativeWindow);
        LOGE("munmap failed");
        return;
    }
    ```

## Samples

The following samples are provided to help you better understand how to use the NativeWindow module for development:

- [NativeWindow (API12)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow)
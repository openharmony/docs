# NativeBuffer Development (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=740dcdea7b2e0f63c4b99baa0eb4f2e92e763430 translatedAt=2026-08-03T11:21:04.697Z pushedAt=2026-08-04T06:48:11.525Z -->

## Overview

The NativeBuffer module provides the **shared memory** feature, supporting memory application, use, query, and release.

Common use cases of NativeBuffer include image data processing, video encoding/decoding, and cross-process memory sharing. The typical development process involves creating an **OH_NativeBuffer** instance, obtaining memory properties, and mapping ION memory to the process address space.

## Available APIs

| API| Description|
| -------- | -------- |
| OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config \*config) | Creates an **OH_NativeBuffer** instance based on **OH_NativeBuffer_Config**. Each call generates a new **OH_NativeBuffer** instance. This API must be used together with **OH_NativeBuffer_Unreference**; otherwise, memory leaks may occur. |
| OH_NativeBuffer_Reference (OH_NativeBuffer \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.|
| OH_NativeBuffer_Unreference (OH_NativeBuffer \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.|
| OH_NativeBuffer_GetConfig (OH_NativeBuffer \*buffer, OH_NativeBuffer_Config \*config) | Obtains the properties of an **OH_NativeBuffer** instance.|
| OH_NativeBuffer_Map (OH_NativeBuffer \*buffer, void \*\*virAddr) | Maps the ION memory allocated to an **OH_NativeBuffer** instance to the process address space.|
| OH_NativeBuffer_Unmap (OH_NativeBuffer \*buffer) | Unmaps the ION memory allocated to an **OH_NativeBuffer** instance from the process address space.|
| OH_NativeBuffer_GetSeqNum (OH_NativeBuffer \*buffer) | Obtains the sequence number of an **OH_NativeBuffer** instance.|

For detailed API descriptions, see [OH_NativeBuffer](../reference/apis-arkgraphics2d/capi-oh-nativebuffer.md).

## How to Develop

The following describes how to use the aforementioned APIs to create an **OH_NativeBuffer** instance, obtain memory properties, and map the ION memory to the process address space.

**Adding Dynamic Link Libraries**

Add the following library to **CMakeLists.txt**:

```txt
libnative_buffer.so
```

**Including Header Files**

```c++
#include <native_buffer/native_buffer.h>
```

1. Create an **OH_NativeBuffer** instance.

    <!-- @[nativebuffer_alloc](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    OH_NativeBuffer_Config config {
        .width = 0x100,
        .height = 0x100,
        .format = NATIVEBUFFER_PIXEL_FMT_RGBA_8888,
        .usage = NATIVEBUFFER_USAGE_CPU_READ | NATIVEBUFFER_USAGE_CPU_WRITE | NATIVEBUFFER_USAGE_MEM_DMA,
    };

    OH_NativeBuffer *nativeBuffer = OH_NativeBuffer_Alloc(&config);
    if (nativeBuffer == nullptr) {
        LOGE("OH_NativeBuffer_Alloc fail, nativeBuffer is null");
    }
    ```

2. Map the ION memory allocated to an **OH_NativeBuffer** instance to the process address space.

    Call **OH_NativeBuffer_Map** if the application needs to access the memory space of the buffer.

    <!-- @[nativebuffer_map](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    void* virAddr = nullptr;
    int32_t ret = OH_NativeBuffer_Map(nativeBuffer, &virAddr);
    if (ret != 0) {
        LOGE("OH_NativeBuffer_Map Failed");
    }
    // ...
    ret = OH_NativeBuffer_Unmap(nativeBuffer);
    if (ret != 0) {
        LOGE("OH_NativeBuffer_Unmap Failed");
    }
    ```

3. Obtain the memory properties.

    <!-- @[nativebuffer_getconfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    OH_NativeBuffer_Config config2 = {};
    OH_NativeBuffer_GetConfig(nativeBuffer, &config2);
    uint32_t hwBufferID = OH_NativeBuffer_GetSeqNum(nativeBuffer);
    ```

4. Destroy the **OH_NativeBuffer** instance.

    <!-- @[nativebuffer_unreference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->

    ``` C++
    OH_NativeBuffer_Unreference(nativeBuffer);
    nativeBuffer = nullptr;
    ```

## Samples

The following sample is available for NativeBuffer development:

- [Native Window (API12)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow)
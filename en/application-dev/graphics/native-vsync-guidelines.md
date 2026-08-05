# NativeVSync Development (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @BruceXu; @alexci-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=c28b0de2e8d0853a87b71fa336ae431e4ce25640 translatedAt=2026-08-03T11:21:30.590Z pushedAt=2026-08-04T07:01:48.054Z -->

## Overview

The NativeVSync module is used to obtain the system VSync signal, create and destroy an **OH_NativeVSync** instance, and set the VSync callback function. When the VSync signal is triggered, the callback function is called.

## Available APIs

| API| Description|
| -------- | -------- |
| OH_NativeVSync_Create (const char \*name, unsigned int length) | Creates an **OH_NativeVSync** instance. Each call creates a new instance and a vsync thread to receive and process callbacks. This API must be used together with **OH_NativeVSync_Destroy**; otherwise, memory leaks may occur. |
| OH_NativeVSync_Destroy (OH_NativeVSync \*nativeVsync) | Destroys an **OH_NativeVSync** instance.|
| OH_NativeVSync_FrameCallback (long long timestamp, void \*data) | Defines the callback function signature. **timestamp** indicates the timestamp, and **data** is the input parameter of the callback function. The callback is processed in the thread created during vsync initialization. |
| OH_NativeVSync_RequestFrame (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | Requests the next VSync signal. When the signal arrives, a callback function is invoked.|

For details about the APIs, see [native_vsync](../reference/apis-arkgraphics2d/capi-nativevsync.md).

## How to Develop

The following steps describe how to use the native APIs provided by NativeVSync to create and destroy an **OH_NativeVSync** instance and set the VSync callback function.

**Adding Dynamic Link Libraries**

Add the following library file to the **CMakeLists.txt** file.

```txt
libnative_vsync.so
```

**Including Header Files**

```c++
#include <native_vsync/native_vsync.h>
```

1. Define a VSync callback function.

    <!-- @[vsync_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->

    ``` C++
    void RenderEngine::OnVsync(long long timestamp, void *data)
    {
        OH_LOG_Print(LOG_APP, LOG_DEBUG, LOG_PRINT_DOMAIN, "RenderEngine", "OnVsync %{public}lld.", timestamp);
        auto renderEngine = reinterpret_cast<RenderEngine *>(data);
        if (renderEngine == nullptr) {
            return;
        }

        renderEngine->vSyncCnt_++;
        renderEngine->wakeUpCond_.notify_one();
    }
    ```

2. Create an **OH_NativeVSync** instance.

    <!-- @[create_vsync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->

    ``` C++
    const char* demoName = "NativeImageSample";
    nativeVsync_ = OH_NativeVSync_Create(demoName, strlen(demoName));
    ```

3. Set the VSync callback function through the **OH_NativeVSync** instance.

    <!-- @[request_vsync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->

    ``` C++
    wakeUpCond_.wait(lock, [this]() { return wakeUp_ || vSyncCnt_ > 0; });
    wakeUp_ = false;
    if (vSyncCnt_ > 0) {
        vSyncCnt_--;
        (void)OH_NativeVSync_RequestFrame(nativeVsync_, &RenderEngine::OnVsync, this);
        OH_NativeVSync_GetPeriod(nativeVsync_, &period);
    }
    ```

4. Destroy the **OH_NativeVSync** instance.

    <!-- @[destroy_vsync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->

    ``` C++
    OH_NativeVSync_Destroy(nativeVsync_);
    nativeVsync_ = nullptr;
    ```

## Samples

The following sample is available for NativeVSync development:

- [Smooth Gradient Animation Based on NdkNativeImage (API12)](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage)
# NativeVSync开发指导 (C/C++)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @BruceXu; @alexci-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 场景介绍

NativeVSync模块用于获取系统VSync信号，提供OH_NativeVSync实例的创建、销毁及设置VSync回调函数的功能。VSync信号触发时，将调用已设置的回调函数。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeVSync_Create (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例并创建一个vsync线程接收处理回调。本接口需要与OH_NativeVSync_Destroy接口配合使用，否则会存在内存泄漏。 |
| OH_NativeVSync_Destroy (OH_NativeVSync \*nativeVsync) | 销毁OH_NativeVSync实例。 | 
| OH_NativeVSync_FrameCallback (long long timestamp, void \*data) | 回调函数的形式，timestamp表示时间戳，data为回调函数入参。回调的处理在vsync初始化时创建的线程内。 | 
| OH_NativeVSync_RequestFrame (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | 请求下一次VSync信号，当信号到来时，调用回调函数callback。 | 

详细的接口说明请参考[native_vsync](../reference/apis-arkgraphics2d/capi-nativevsync.md)。

## 开发步骤

以下步骤描述如何使用NativeVSync提供的Native API接口创建和销毁OH_NativeVSync实例，以及如何设置VSync回调函数。

**添加动态链接库**

CMakeLists.txt中添加以下库文件。
```txt
libnative_vsync.so
```

**头文件**
```c++
#include <native_vsync/native_vsync.h>
```

1. **首先需要定义一个VSync回调函数**。
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

2. **创建OH_NativeVSync实例**。
    <!-- @[create_vsync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->
    
    ``` C++
    const char* demoName = "NativeImageSample";
    nativeVsync_ = OH_NativeVSync_Create(demoName, strlen(demoName));
    ```

3. **通过OH_NativeVSync实例设置VSync回调函数**。
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


4. **销毁OH_NativeVSync实例**。
    <!-- @[destroy_vsync](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage/entry/src/main/cpp/render/render_engine.cpp) -->
    
    ``` C++
    OH_NativeVSync_Destroy(nativeVsync_);
    nativeVsync_ = nullptr;
    ```

## 相关实例

针对NativeVSync的开发，有以下相关实例可供参考：

- [基于NdkNativeImage的平滑渐变动画效果（API12）](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeImage)
# NativeWindow开发指导 (C/C++)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 场景介绍

NativeWindow是**本地平台化窗口**，表示图形队列的生产者端，主要用于需要高效图形数据处理的场景。当开发者开发视频播放、相机预览、游戏渲染等图形密集型应用时，需要在图形缓冲区中高效地写入和提交图形数据。此时，开发者可以通过`NativeWindow`接口进行申请和提交`Buffer`，配置`Buffer`属性信息。

针对NativeWindow，常见的开发场景如下：

* 通过`NativeWindow`提供的Native API接口申请图形`Buffer`，并将生成的图形内容写入图形`Buffer`，最终提交`Buffer`到图形队列。
* 在适配EGL层的`eglswapbuffer`接口时，进行申请和提交`Buffer`。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。 | 
| OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。 | 
| OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow \*window, int code,...) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。 | 

详细的接口说明请参考[NativeWindow](../reference/apis-arkgraphics2d/capi-nativewindow.md)。

## 开发步骤

以下步骤描述了如何使用`NativeWindow`提供的Native API接口申请图形`Buffer`，写入图形内容，并提交`Buffer`到图形队列。

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libace_ndk.z.so
libnative_window.so
```

**头文件**
```c++
#include <sys/poll.h>
#include <sys/mman.h>
#include <unistd.h>
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <native_window/external_window.h>
```

1. 获取OHNativeWindow实例。

    可通过[`OH_NativeXComponent_Callback`](../reference/apis-arkui/capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-callback.md)接口获取OHNativeWindow。代码示例如下。关于XComponent模块的使用方法，详见[XComponent开发指导](../ui/napi-xcomponent-guidelines.md)。

    1. 在xxx.ets中添加一个XComponent组件。
        <!-- @[create_native_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/ets/pages/Index.ets) -->
        
        ``` TypeScript
        XComponent({ id: 'xcomponentId', type: 'texture', libraryname: 'nativerender' })
          .margin({ bottom: 26 })
          .onLoad((nativeWindowContext) => {
            this.nativeWindowContext = nativeWindowContext as NativeWindowContext;
          })
        ```


    2. 在 native c++ 层获取 NativeXComponent。
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

        
    3. 定义 OH_NativeXComponent_Callback。
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

       
    4. 将OH_NativeXComponent_Callback 注册给 NativeXComponent。
        <!-- @[register_xcomponent_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->
        
        ``` C++
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback_);
        ```


2. 设置OHNativeWindowBuffer的属性。使用`OH_NativeWindow_NativeWindowHandleOpt`设置`OHNativeWindowBuffer`的属性（默认携带NATIVEBUFFER_USAGE_CPU_READ usage参数，如果不使用CPU读写数据，建议去除NATIVEBUFFER_USAGE_CPU_READ usage参数，具体可见[关闭CPU访问窗口缓冲区数据](https://developer.huawei.com/consumer/cn/doc/harmonyos-faqs/faqs-arkgraphics-2d-14)）。
    <!-- @[set_buffer_geometry](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->
    
    ``` C++
    int code = SET_BUFFER_GEOMETRY;
    int32_t bufferHeight = static_cast<int32_t>(height_ / 4);
    int32_t bufferWidth = static_cast<int32_t>(width_ / 2);
    OH_NativeWindow_NativeWindowHandleOpt(nativeWindow_, code, bufferWidth, bufferHeight);
    ```


3. 从图形队列申请OHNativeWindowBuffer。
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


4. 内存映射mmap。
    <!-- @[map_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->
    
    ``` C++
    void *mappedAddr =
        mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0);
    ```


5. 将生产的内容写入OHNativeWindowBuffer，在这之前需要等待releaseFenceFd可用（注意releaseFenceFd不等于-1才需要调用poll）。如果没有等待releaseFenceFd事件的数据可用（POLLIN），则可能造成花屏、裂屏、HEBC（High Efficiency Bandwidth Compression，高效带宽压缩） fault等问题。releaseFenceFd是消费者进程创建的一个文件句柄，代表消费者消费buffer完毕，buffer可读，生产者可以开始填充buffer内容。
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
    for (uint64_t x = 0; x < bufferHandle->width; x++) {
        for (uint64_t y = 0; y < bufferHandle->height; y++) {
            *pixel++ = value;
        }
    }
    ```


6. 提交OHNativeWindowBuffer到图形队列。请注意OH_NativeWindow_NativeWindowFlushBuffer接口的acquireFenceFd不可以和OH_NativeWindow_NativeWindowRequestBuffer接口获取的releaseFenceFd相同，acquireFenceFd可传入默认值-1。acquireFenceFd是生产者需要传入的文件句柄，消费者获取到buffer后可根据生产者传入的acquireFenceFd决定何时去渲染并上屏buffer内容。
    <!-- @[flush_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->
    
    ``` C++
    struct Region *region = new Region();
    int acquireFenceFd = -1;
    ret = OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, nativeWindowBuffer, acquireFenceFd, *region);
    if (ret != NATIVE_ERROR_OK) {
        LOGE("flush failed");
        (void)OH_NativeWindow_NativeWindowAbortBuffer(nativeWindow, nativeWindowBuffer);
        return;
    }
    ```


7. 使用munmap取消内存映射。
    <!-- @[munmap_addr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->
    
    ``` C++
    if (munmap(mappedAddr, bufferHandle->size) < 0) {
        OH_NativeWindow_DestroyNativeWindow(nativeWindow);
        LOGE("munmap failed");
        return;
    }
    ```


## 相关实例

针对NativeWindow的开发，有以下相关实例可供参考：

- [NativeWindow（API12）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow)
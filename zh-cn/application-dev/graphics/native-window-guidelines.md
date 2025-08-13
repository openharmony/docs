# NativeWindow开发指导 (C/C++)

## 场景介绍

NativeWindow是**本地平台化窗口**，表示图形队列的生产者端。开发者可以通过`NativeWindow`接口进行申请和提交`Buffer`，配置`Buffer`属性信息。
针对NativeWindow，常见的开发场景如下：

* 通过`NativeWindow`提供的Native API接口申请图形`Buffer`，并将生产图形内容写入图形`Buffer`，最终提交`Buffer`到图形队列。
* 在适配EGL层的`eglswapbuffer`接口时，进行申请和提交`Buffer`。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。 | 
| OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。 | 
| OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow \*window, int code,...) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。 | 

详细的接口说明请参考[native_window](../reference/apis-arkgraphics2d/capi-nativewindow.md)。

## 开发步骤

以下步骤描述了如何使用`NativeWindow`提供的Native API接口，申请图形`Buffer`，并将生产图形内容写入图形`Buffer`后，最终提交`Buffer`到图形队列。

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

    可在[`OH_NativeXComponent_Callback`](../reference/apis-arkui/capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-callback.md)提供的接口中获取OHNativeWindow，下面提供一份代码示例。XComponent模块的具体使用方法请参考[XComponent开发指导](../ui/napi-xcomponent-guidelines.md)。

    1. 在xxx.ets中添加一个XComponent组件。

        ```ts
        XComponent({ id: 'xcomponentId', type: XComponentType.SURFACE, libraryname: 'entry'})
            .width(360)
            .height(360)
        ```
    2. 在 native c++ 层获取 NativeXComponent。

        ```c++
        napi_value exportInstance = nullptr;
        // 用来解析出被wrap了NativeXComponent指针的属性
        napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
        OH_NativeXComponent *nativeXComponent = nullptr;
        // 通过napi_unwrap接口，解析出NativeXComponent的实例指针
        napi_unwrap(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));
        // 获取XComponentId
        char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
        uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
        OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize);
        ```
    3. 定义 OH_NativeXComponent_Callback。

        ```c++
        // 定义回调函数
        void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
        {
            // 可获取 OHNativeWindow 实例
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // 此回调触发后，window默认引用计数会设置为1，若存在并发使用了window相关的接口和xcomponent析构的情况，
            // 则需要通过OH_NativeWindow_NativeObjectReference和OH_NativeWindow_NativeObjectUnreference对window进行
            // 手动引用计数加1和减1，防止xcomponent析构后，并发调用window相关接口触发野指针或空指针的崩溃。
        }
        void OnSurfaceChangedCB(OH_NativeXComponent* component, void* window)
        {
            // 可获取 OHNativeWindow 实例
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }
        void OnSurfaceDestroyedCB(OH_NativeXComponent* component, void* window)
        {
            // 可获取 OHNativeWindow 实例
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // 此回调触发后，会将window进行引用计数减1的操作，当window的应用计数为0后，会触发window的析构，
            // window析构后，不可再通过window进行接口调用，否则可能会触发野指针或空指针的崩溃。
        }
        void DispatchTouchEventCB(OH_NativeXComponent* component, void* window)
        {
            // 可获取 OHNativeWindow 实例
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
        }
        ```

        ```c++
        // 初始化 OH_NativeXComponent_Callback
        OH_NativeXComponent_Callback callback;
        callback.OnSurfaceCreated = OnSurfaceCreatedCB;
        callback.OnSurfaceChanged = OnSurfaceChangedCB;
        callback.OnSurfaceDestroyed = OnSurfaceDestroyedCB;
        callback.DispatchTouchEvent = DispatchTouchEventCB;
        ```

   4. 将OH_NativeXComponent_Callback 注册给 NativeXComponent。

        ```c++
        // 注册回调函数
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback);
        ```

2. 设置OHNativeWindowBuffer的属性。使用`OH_NativeWindow_NativeWindowHandleOpt`设置`OHNativeWindowBuffer`的属性。

    ```c++
    // 设置 OHNativeWindowBuffer 的宽高
    int32_t code = SET_BUFFER_GEOMETRY;
    int32_t width = 0x100;
    int32_t height = 0x100;
    // 这里的nativeWindow是从上一步骤中的回调函数中获得的
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
    ```

3. 从图形队列申请OHNativeWindowBuffer。

    ```c++
    OHNativeWindowBuffer* buffer = nullptr;
    int releaseFenceFd = -1;
    // 通过 OH_NativeWindow_NativeWindowRequestBuffer 获取 OHNativeWindowBuffer 实例
    ret = OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &releaseFenceFd);
    if (ret != 0 || buffer == nullptr) {
        return;
    }
    // 通过 OH_NativeWindow_GetBufferHandleFromNative 获取 buffer 的 handle
    BufferHandle* bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
    ```

4. 内存映射mmap。

    ```c++
    #include <sys/mman.h>

    // 使用内存映射函数mmap将bufferHandle对应的共享内存映射到用户空间，可以通过映射出来的虚拟地址向bufferHandle中写入图像数据
    // bufferHandle->virAddr是bufferHandle在共享内存中的起始地址，bufferHandle->size是bufferHandle在共享内存中的内存占用大小
    void* mappedAddr = mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0);
    if (mappedAddr == MAP_FAILED) {
        // mmap failed
    }
    ```

5. 将生产的内容写入OHNativeWindowBuffer，在这之前需要等待releaseFenceFd可用（注意releaseFenceFd不等于-1才需要调用poll）。如果没有等待releaseFenceFd事件的数据可用（POLLIN），则可能造成花屏、裂屏、HEBC（High Efficiency Bandwidth Compression，高效带宽压缩） fault等问题。releaseFenceFd是消费者进程创建的一个文件句柄，代表消费者消费buffer完毕，buffer可读，生产者可以开始填充buffer内容。

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
        close(releaseFenceFd); // 防止fd泄漏
    }

    static uint32_t value = 0x00;
    value++;
    uint32_t *pixel = static_cast<uint32_t *>(mappedAddr); // 使用mmap获取到的地址来访问内存
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0;  y < height; y++) {
            *pixel++ = value;
        }
    }
    ```

6. 提交OHNativeWindowBuffer到图形队列。请注意OH_NativeWindow_NativeWindowFlushBuffer接口的acquireFenceFd不可以和OH_NativeWindow_NativeWindowRequestBuffer接口获取的releaseFenceFd相同，acquireFenceFd可传入默认值-1。acquireFenceFd是生产者需要传入的文件句柄，消费者获取到buffer后可根据生产者传入的acquireFenceFd决定何时去渲染并上屏buffer内容。

    ```c++
    // 设置刷新区域，如果Region中的Rect为nullptr,或者rectNumber为0，则认为OHNativeWindowBuffer全部有内容更改。
    Region region{nullptr, 0};
    int acquireFenceFd = -1;
    // 通过OH_NativeWindow_NativeWindowFlushBuffer 提交给消费者使用，例如：显示在屏幕上。
    OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, acquireFenceFd, region);
    ```

7. 取消内存映射munmap。

    ```c++
    // 内存使用完记得去掉内存映射
    int result = munmap(mappedAddr, bufferHandle->size);
    if (result == -1) {
        // munmap failed
    }
    ```

## 相关实例

针对NativeWindow的开发，有以下相关实例可供参考：

- [NativeWindow（API11）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/NdkNativeWindow)
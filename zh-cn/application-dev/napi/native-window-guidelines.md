# NativeWindow开发指导

## 场景介绍

NativeWindow是`OpenHarmony`**本地平台化窗口**，表示图形队列的生产者端。开发者可以通过`NativeWindow`接口进行申请和提交`Buffer`，配置`Buffer`属性信息。
针对NativeWindow，常见的开发场景如下：

* 通过`NativeWindow`提供的Native API接口申请图形`Buffer`，并将生产图形内容写入图形`Buffer`，最终提交`Buffer`到图形队列
* 在适配EGL层的`eglswapbuffer`接口时，进行申请和提交`Buffer`

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeWindow_NativeWindowRequestBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*\*buffer, int \*fenceFd) | 通过OHNativeWindow对象申请一块OHNativeWindowBuffer，用以内容生产。 | 
| OH_NativeWindow_NativeWindowFlushBuffer (OHNativeWindow \*window, OHNativeWindowBuffer \*buffer, int fenceFd, Region region) | 通过OHNativeWindow将生产好内容的OHNativeWindowBuffer放回到Buffer队列中，用以内容消费。 | 
| OH_NativeWindow_NativeWindowHandleOpt (OHNativeWindow \*window, int code,...) | 设置/获取OHNativeWindow的属性，包括设置/获取宽高、内容格式等。 | 

详细的接口说明请参考[native_window](../reference/native-apis/_native_window.md)。

## 开发步骤

以下步骤描述了在**OpenHarmony**中如何使用`NativeWindow`提供的Native API接口，申请图形`Buffer`，并将生产图形内容写入图形`Buffer`后，最终提交`Buffer`到图形队列。

**添加动态链接库**
CMakeLists.txt中添加以下lib。
```txt
libace_ndk.z.so
libnative_window.so
```

**头文件**
```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <native_window/external_window.h>
```

1. **获取OHNativeWindow实例**。

    可在[`OH_NativeXComponent_Callback`](../reference/native-apis/_o_h___native_x_component___callback.md)提供的接口中获取OHNativeWindow，下面提供一份代码示例。XComponent模块的具体使用方法请参考[XComponent](../ui/arkts-common-components-xcomponent.md)。
    1. 在xxx.ets中添加一个XComponent组件。
        ```ts
        XComponent({ id: 'xcomponentId', type: 'surface', libraryname: 'entry'})
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
        ```
    3. 定义 OH_NativeXComponent_Callback。
        ```c++
        // 定义回调函数
        void OnSurfaceCreatedCB(OH_NativeXComponent* component, void* window)
        {
            // 可获取 OHNativeWindow 实例
            OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
            // ...
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
            // ...
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
   4. 将 OH_NativeXComponent_Callback 注册给 NativeXComponent。
        ```c++
        // 注册回调函数
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback);
        ```

2. **设置OHNativeWindowBuffer的属性**。使用`OH_NativeWindow_NativeWindowHandleOpt`设置`OHNativeWindowBuffer`的属性。
    ```c++
    // 设置 OHNativeWindowBuffer 的宽高
    int32_t code = SET_BUFFER_GEOMETRY;
    int32_t width = 0x100;
    int32_t height = 0x100;
    // 这里的nativeWindow是从上一步骤中的回调函数中获得的
    int32_t ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
    // 设置 OHNativeWindowBuffer 的步长
    code = SET_STRIDE;
    int32_t stride = 0x8;
    ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, stride);
    ```

3. **从图形队列申请OHNativeWindowBuffer**。
    ```c++
    OHNativeWindowBuffer* buffer = nullptr;
    int fenceFd;
    // 通过 OH_NativeWindow_NativeWindowRequestBuffer 获取 OHNativeWindowBuffer 实例
    OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &fenceFd);
    // 通过 OH_NativeWindow_GetBufferHandleFromNative 获取 buffer 的 handle
    BufferHandle* bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
    ```

4. **内存映射mmap**。
    ```c++
    #include <sys/mman.h>

    // 使用系统mmap接口拿到bufferHandle的内存虚拟地址
    void* mappedAddr = mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0);
    if (mappedAddr == MAP_FAILED) {
        // mmap failed
    }
    ```

5. **将生产的内容写入OHNativeWindowBuffer**。
    ```c++
    static uint32_t value = 0x00;
    value++;
    uint32_t *pixel = static_cast<uint32_t *>(mappedAddr); // 使用mmap获取到的地址来访问内存
    for (uint32_t x = 0; x < width; x++) {
        for (uint32_t y = 0;  y < height; y++) {
            *pixel++ = value;
        }
    }
    ```

5. **提交OHNativeWindowBuffer到图形队列**。
    ```c++
    // 设置刷新区域，如果Region中的Rect为nullptr,或者rectNumber为0，则认为OHNativeWindowBuffer全部有内容更改。
    Region region{nullptr, 0};
    // 通过OH_NativeWindow_NativeWindowFlushBuffer 提交给消费者使用，例如：显示在屏幕上。
    OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
    ```
6. **取消内存映射munmap**。
    ```c++
    // 内存使用完记得去掉内存映射
    int result = munmap(mappedAddr, bufferHandle->size);
    if (result == -1) {
        // munmap failed
    }
    ```

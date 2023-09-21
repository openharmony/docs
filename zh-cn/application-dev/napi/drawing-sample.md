# 图形绘制与显示实例

## 前言
在[Drawing开发指导](drawing-guidelines.md)中介绍了怎么通过调用`NativeDrawing`提供的接口绘制出一个2D图形，本文档将会介绍如何把绘制出的2D图形显示在屏幕上，主要利用`NativeWindow`和`XComponent`模块提供的能力将图形显示在屏幕上。

## 开发步骤

以下步骤描述了在**OpenHarmony**中如何使用`NativeDrawing`模块的画布画笔绘制一个基本的2D图形，并将图形内容写入`NativeWindow`提供的图形`Buffer`，提交`Buffer`到图形队列，并利用`XComponent`将C++代码层与ArkTS层对接，实现在ArkTS层调用绘制和显示逻辑，最终能在应用上显示图形。

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libace_napi.z.so
libace_ndk.z.so
libnative_window.so
libnative_drawing.so
```

**头文件**
```c++
#include <ace/xcomponent/native_interface_xcomponent.h>
#include "napi/native_api.h"
#include <native_window/external_window.h>
#include <native_drawing/drawing_bitmap.h>
#include <native_drawing/drawing_color.h>
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_pen.h>
#include <native_drawing/drawing_brush.h>
#include <native_drawing/drawing_path.h>
#include <cmath>
#include <algorithm>
#include <stdint.h>
#include <sys/mman.h>
```

1. **获取OHNativeWindow实例，作为图形显示的载体**。

    1. 在xxx.ets中添加一个XComponent组件。
        ```ts
        XComponent({ id: 'xcomponentId', type: 'surface', libraryname: 'entry'})
        ```
    2. 在native c++层获取NativeXComponent。
        ```c++
        // 获取XComponent的id
        char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {};
        uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
        napi_value exportInstance = nullptr;
        // 用来解析出被wrap了NativeXComponent指针的属性
        napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance);
        OH_NativeXComponent *nativeXComponent = nullptr;
        // 通过napi_unwrap接口，解析出NativeXComponent的实例指针
        napi_unwrap(env, exportInstance, reinterpret_cast<void**>(&nativeXComponent));
        ```
     3. 定义OH_NativeXComponent_Callback。
        ```c++
        // 声明一个XComponent的Callback
        OH_NativeXComponent_Callback callback;
        // 注册OnSurfaceCreated的回调函数
        callback.OnSurfaceCreated = OnSurfaceCreatedCB;
        ```
     4. 将OH_NativeXComponent_Callback注册给NativeXComponent。
        ```c++
        // 注册回调函数，在回调函数实现绘制显示逻辑，当用户在ArkTS层调用XComponent时就能通过回调函数调用到此段逻辑
        OH_NativeXComponent_RegisterCallback(nativeXComponent, &callback);
        ```

2. **获取OHNativeWindow实例，用于提供图形显示的载体**。
    1. 设置OHNativeWindowBuffer的属性。使用`OH_NativeWindow_NativeWindowHandleOpt`设置`OHNativeWindowBuffer`的属性。
        ```c++
        // 获取 OHNativeWindow 实例
        OHNativeWindow* nativeWindow = static_cast<OHNativeWindow*>(window);
    
        // 设置 OHNativeWindowBuffer 的宽高
        int32_t code = SET_BUFFER_GEOMETRY;
        uint64_t width;
        uint64_t height;
        int32_t ret = OH_NativeXComponent_GetXComponentSize(component, window, &width, &height);
        // 这里的nativeWindow是从上一步骤中的回调函数中获得的
        ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, width, height);
        // 设置 OHNativeWindowBuffer 的步长
        code = SET_STRIDE;
        int32_t stride = 0x8;
    
        ret = OH_NativeWindow_NativeWindowHandleOpt(nativeWindow, code, stride);
        ```
    2. 从图形队列申请OHNativeWindowBuffer。
        ```c++
        OHNativeWindowBuffer* buffer = nullptr;
        int fenceFd;
        // 通过 OH_NativeWindow_NativeWindowRequestBuffer 获取 OHNativeWindowBuffer 实例
        OH_NativeWindow_NativeWindowRequestBuffer(nativeWindow, &buffer, &fenceFd);
        // 通过 OH_NativeWindow_GetBufferHandleFromNative 获取 buffer 的 handle
        BufferHandle* bufferHandle = OH_NativeWindow_GetBufferHandleFromNative(buffer);
        ```
    3. 内存映射mmap，获取bufferHandle的内存虚拟地址。
        ```c++
        // 使用系统mmap接口拿到bufferHandle的内存虚拟地址
        uint8_t *mappedAddr = static_cast<uint8_t *>(mmap(bufferHandle->virAddr, bufferHandle->size, PROT_READ | PROT_WRITE, MAP_SHARED, bufferHandle->fd, 0));
        if (mappedAddr == MAP_FAILED) {
            // mmap failed
        }
        ```
3. **使用 Native Drawing 提供的API接口绘制一个五角星形状的2D图形**。详细代码见[Drawing开发指导](drawing-guidelines.md)。

4. **将上一步绘制出的2D图形通过NativeWindow显示在屏幕上**。
    1. 将Drawing绘制的图形内容写入OHNativeWindowBuffer。
        ```c++
        uint8_t *bitmapAddr = static_cast<uint8_t *>(OH_Drawing_BitmapGetPixels(cBitmap));
        std::copy(bitmapAddr, bitmapAddr + (width * height * 4), mappedAddr);
        ```
    2. 提交OHNativeWindowBuffer到图形队列。
        ```c++
        // 设置刷新区域，如果Region中的Rect为nullptr,或者rectNumber为0，则认为OHNativeWindowBuffer全部有内容更改。
        Region region{nullptr, 0};
        // 通过OH_NativeWindow_NativeWindowFlushBuffer 提交给消费者使用，例如：显示在屏幕上。
        OH_NativeWindow_NativeWindowFlushBuffer(nativeWindow, buffer, fenceFd, region);
        ```
    3. 取消内存映射munmap。
        ```c++
        // 内存使用完记得去掉内存映射
        int result = munmap(mappedAddr, bufferHandle->size);
        if (result == -1) {
            // munmap failed
        }
        ```

5. **绘制显示效果示意图**。

    ![Drawing](figures/drawing.png)
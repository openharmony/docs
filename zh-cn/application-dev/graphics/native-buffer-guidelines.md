# NativeBuffer开发指导 (C/C++)
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 场景介绍

NativeBuffer模块提供**共享内存**功能，支持内存的申请、使用、查询和释放等操作。

NativeBuffer的常见应用场景包括：图像数据处理、视频编解码、跨进程内存共享等。开发流程通常包括：申请OH_NativeBuffer实例、获取内存属性和将ION内存映射到进程空间。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config \*config) | 通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。本接口需要与OH_NativeBuffer_Unreference接口配合使用，否则会存在内存泄漏。 |
| OH_NativeBuffer_Reference (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数增加1。 | 
| OH_NativeBuffer_Unreference (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉。 | 
| OH_NativeBuffer_GetConfig (OH_NativeBuffer \*buffer, OH_NativeBuffer_Config \*config) | 用于获取OH_NativeBuffer的属性。 | 
| OH_NativeBuffer_Map (OH_NativeBuffer \*buffer, void \*\*virAddr) | 将OH_NativeBuffer对应的ION内存映射到进程空间。 | 
| OH_NativeBuffer_Unmap (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对应的ION内存从进程空间解除映射。 | 
| OH_NativeBuffer_GetSeqNum (OH_NativeBuffer \*buffer) | 获取OH_NativeBuffer的序列号。 | 

详细的接口说明请参考[OH_NativeBuffer](../reference/apis-arkgraphics2d/capi-oh-nativebuffer.md)。

## 开发步骤

以下步骤描述了如何使用`NativeBuffer`提供的Native API接口创建`OH_NativeBuffer`实例，获取内存属性信息，并将ION内存映射到进程空间。

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libnative_buffer.so
```

**头文件**
```c++
#include <native_buffer/native_buffer.h>
```

1. **创建OH_NativeBuffer实例**。
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


2. **将OH_NativeBuffer对应的ION内存映射到进程空间**。

    应用如需访问buffer内存空间，可通过OH_NativeBuffer_Map接口将ION内存映射到进程空间。
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


3. **获取内存的属性信息**。
    <!-- @[nativebuffer_getconfig](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->
    
    ``` C++
    OH_NativeBuffer_Config config2 = {};
    OH_NativeBuffer_GetConfig(nativeBuffer, &config2);
    uint32_t hwBufferID = OH_NativeBuffer_GetSeqNum(nativeBuffer);
    ```

4. **销毁OH_NativeBuffer**。
    <!-- @[nativebuffer_unreference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow/entry/src/main/cpp/NativeRender.cpp) -->
    
    ``` C++
    OH_NativeBuffer_Unreference(nativeBuffer);
    nativeBuffer = nullptr;
    ```

## 相关实例

针对NativeBuffer的开发，有以下相关实例可供参考：

- [Native Window（API12）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/NdkNativeWindow)
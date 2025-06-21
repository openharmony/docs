# NativeBuffer开发指导 (C/C++)

## 场景介绍

NativeBuffer是提供**共享内存**的模块。开发者可以通过`NativeBuffer`接口实现共享内存的申请、使用、属性查询、释放等操作。
针对NativeBuffer，常见的开发场景如下：

* 通过`NativeBuffer`提供的Native API接口申请`OH_NativeBuffer`实例，获取内存的属性信息，把对应的ION内存映射到进程空间。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config \*config) | 通过OH_NativeBuffer_Config创建OH_NativeBuffer实例，每次调用都会产生一个新的OH_NativeBuffer实例。本接口需要与OH_NativeBuffer_Unreference接口配合使用，否则会存在内存泄露。 |
| OH_NativeBuffer_Reference (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数增加1。 | 
| OH_NativeBuffer_Unreference (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对象的引用计数减1，当引用计数为0的时候，该NativeBuffer对象会被析构掉。 | 
| OH_NativeBuffer_GetConfig (OH_NativeBuffer \*buffer, OH_NativeBuffer_Config \*config) | 用于获取OH_NativeBuffer的属性。 | 
| OH_NativeBuffer_Map (OH_NativeBuffer \*buffer, void \*\*virAddr) | 将OH_NativeBuffer对应的ION内存映射到进程空间。 | 
| OH_NativeBuffer_Unmap (OH_NativeBuffer \*buffer) | 将OH_NativeBuffer对应的ION内存从进程空间移除。 | 
| OH_NativeBuffer_GetSeqNum (OH_NativeBuffer \*buffer) | 获取OH_NativeBuffer的序列号。 | 

详细的接口说明请参考[native_buffer](../reference/apis-arkgraphics2d/capi-oh-nativebuffer.md)。

## 开发步骤

以下步骤描述了如何使用`NativeBuffer`提供的Native API接口，创建`OH_NativeBuffer`实例获取内存的属性信息，并把对应的ION内存映射到进程空间。

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
    ```c++
    #include <iostream>

    OH_NativeBuffer_Config config {
        .width = 0x100,
        .height = 0x100,
    };
    OH_NativeBuffer* buffer = OH_NativeBuffer_Alloc(&config);
    if (buffer == nullptr) {
        std::cout << "OH_NativeBuffer_Alloc Failed" << std::endl;
    }
    ```
   
2. **将OH_NativeBuffer对应的ION内存映射到进程空间**。
    应用如需要访问这块buffer的内存空间，需要通过OH_NativeBuffer_Map接口将buffer对应的ION内存映射到进程空间。
    ```c++
    // 将ION内存映射到进程空间
    void* virAddr = nullptr;
    int32_t ret = OH_NativeBuffer_Map(buffer, &virAddr); // 映射后通过第二个参数virAddr返回内存的首地址
    if (ret != 0) {
        std::cout << "OH_NativeBuffer_Map Failed" << std::endl;
    }

    // 使用后请及时将OH_NativeBuffer对应的ION内存从进程空间移除
    ret = OH_NativeBuffer_Unmap(buffer);
    if (ret != 0) {
        std::cout << "OH_NativeBuffer_Unmap Failed" << std::endl;
    }
    ```

3. **获取内存的属性信息**。
    ```c++
    // 获取OH_NativeBuffer的属性
    OH_NativeBuffer_Config config2 = {};
    OH_NativeBuffer_GetConfig(buffer, &config2);
    // 获取OH_NativeBuffer的序列号
     uint32_t hwBufferID = OH_NativeBuffer_GetSeqNum(buffer);
    ```

4. **销毁OH_NativeBuffer**。
    ```c++
    // 调用OH_NativeBuffer_Unreference引用计数减1，之后buffer的引用计数为0，buffer会销毁
    ret = OH_NativeBuffer_Unreference(buffer);
    if (ret != 0) {
        std::cout << "OH_NativeBuffer_Unreference Failed" << std::endl;
    }
    ```
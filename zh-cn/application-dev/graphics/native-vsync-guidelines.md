# NativeVSync开发指导 (C/C++)

## 场景介绍

NativeVSync模块用来获取系统VSync信号，提供了OH_NativeVSync实例的创建、销毁以及设置VSync回调函数的能力，VSync信号到来时会调用已设置的VSync回调函数。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeVSync_Create (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例。本接口需要与OH_NativeVSync_Destroy接口配合使用，否则会存在内存泄露。 |
| OH_NativeVSync_Destroy (OH_NativeVSync \*nativeVsync) | 销毁OH_NativeVSync实例。 | 
| OH_NativeVSync_FrameCallback (long long timestamp, void \*data) | 回调函数的形式，timestamp表示时间戳，data为回调函数入参。 | 
| OH_NativeVSync_RequestFrame (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | 请求下一次VSync信号，当信号到来时，调用回调函数callback。 | 

详细的接口说明请参考[native_vsync](../reference/apis-arkgraphics2d/_native_vsync.md)。

## 开发步骤

以下步骤描述了如何使用`NativeVSync`提供的Native API接口，创建和销毁`OH_NativeVSync`实例，以及如何设置VSync回调函数。

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libnative_vsync.so
```

**头文件**
```c++
#include <native_vsync/native_vsync.h>
```

1. **首先需要准备一个VSync回调函数**。
    ```c++
    #include <iostream>

    static bool flag = false;
    static void OnVSync(long long timestamp, void* data)
    {
        flag = true;
        std::cout << "OnVSync: " << timestamp << std::endl;
    }
    OH_NativeVSync_FrameCallback callback = OnVSync; // 回调函数必须是OH_NativeVSync_FrameCallback类型
     ```
2. **创建OH_NativeVSync实例**。
    ```c++
    char name[] = "hello_vsync";
    OH_NativeVSync* nativeVSync = OH_NativeVSync_Create(name, strlen(name));
     ```

3. **通过OH_NativeVSync实例设置VSync回调函数**。
    ```c++
    #include <unistd.h>
    #include <iostream>

    OH_NativeVSync_RequestFrame(nativeVSync, callback, nullptr);
    while (!flag) { // 判断flag值，上面的VSync回调函数被执行后才会跳出while循环，表示已经接收到VSync信号
        std::cout << "wait for vsync!\n";
        sleep(1);
    }
    std::cout << "vsync come, end this thread\n";
    ```

4. **销毁OH_NativeVSync实例**。
    ```c++
    OH_NativeVSync_Destroy(nativeVSync); // 如不需要接收VSync信号，请及时销毁OH_NativeVSync实例
    ```
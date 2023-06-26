# NativeVsync 开发指导

## 场景介绍

NativeVsync模块用来获取系统VSync信号，提供了OH_NativeVSync实例的创建、销毁，以及VSync信号到来时调用设置的调用回调函数能力。

## 接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| OH_NativeVSync_Create (const char \*name, unsigned int length) | 创建一个OH_NativeVSync实例，每次调用都会产生一个新的实例。 | 
| OH_NativeVSync_Destroy (OH_NativeVSync \*nativeVsync) | 销毁OH_NativeVSync实例。 | 
| OH_NativeVSync_FrameCallback (long long timestamp, void \*data) | 回调函数的形式，timestamp表示时间戳，data为回调函数入参。 | 
| OH_NativeVSync_RequestFrame (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | 请求下一次VSync信号，当信号到来时，调用回调函数callback。 | 

详细的接口说明请参考[native_vsync](../reference/native-apis/_native_vsync.md)。

## 开发步骤

以下步骤描述了在**OpenHarmony**中如何使用`NativeVsync`提供的`NAPI`接口，创建和销毁`NativeVsync`实例，以及如何设置VSync信号到来时想要调用的回调函数。

1. **获取NativeVsync实例**。
    ```c++
    char name[] = "hello_vsync";
    OH_NativeVSync* nativeVSync = OH_NativeVSync_Create(name, strlen(name));
     ```

2. **设置VSync信号到来时想要调用的回调函数**。
    ```c++
    static bool flag = false;
    static void OnVSync(long long timestamp, void* data)
    {
        flag = true;
        std::cout << "OnVSync: " << timestamp << std::endl;
    }
    OH_NativeVSync_FrameCallback callback = OnVSync;
    OH_NativeVSync_RequestFrame(nativeVSync, callback, nullptr);
    while (!flag) {
        std::cout << "wait for vsync!\n";
        sleep(1);
    }
    std::cout << "vsync come, end this thread\n";
    ```

3. **销毁NativeVsync实例**。
    ```c++
    OH_NativeVSync_Destroy(nativeVSync);
    ```
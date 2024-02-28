# Native VSync Development (C/C++)

## When to Use

The **NativeVSync** module is used to obtain virtual synchronization (VSync) signals from the system. It provides APIs for creating and destroying an **OH_NativeVSync** instance and setting the VSync callback function, which is triggered when a VSync signal arrives.

## Available APIs

| API| Description| 
| -------- | -------- |
| OH_NativeVSync_Create (const char \*name, unsigned int length) | Creates an **OH_NativeVSync** instance. A new **OH_NativeVSync** instance is created each time this API is called.| 
| OH_NativeVSync_Destroy (OH_NativeVSync \*nativeVsync) | Destroys an **OH_NativeVSync** instance.| 
| OH_NativeVSync_FrameCallback (long long timestamp, void \*data) | Sets a callback function. **timestamp** indicates the timestamp, and **data** indicates a pointer to the input parameters of the callback function.| 
| OH_NativeVSync_RequestFrame (OH_NativeVSync \*nativeVsync, OH_NativeVSync_FrameCallback callback, void \*data) | Requests the next VSync signal. When the signal arrives, a callback function is invoked.| 

For details about the APIs, see [native_vsync](../reference/apis-arkgraphics2d/_native_vsync.md).

## How to Develop

The following steps describe how to use the native APIs provided by **NativeVSync** to create and destroy an **OH_NativeVSync** instance and set the VSync callback function.

**Adding Dynamic Link Libraries**

Add the following library to **CMakeLists.txt**:
```txt
libnative_vsync.so
```

**Including Header Files**
```c++
#include <native_vsync/native_vsync.h>
```

1. Implement a VSync callback function.
    ```c++
    #include <iostream>

    static bool flag = false;
    static void OnVSync(long long timestamp, void* data)
    {
        flag = true;
        std::cout << "OnVSync: " << timestamp << std::endl;
    }
    OH_NativeVSync_FrameCallback callback = OnVSync; // The callback function must be of the OH_NativeVSync_FrameCallback type.
     ```
2. Create an **OH_NativeVSync** instance.
    ```c++
    char name[] = "hello_vsync";
    OH_NativeVSync* nativeVSync = OH_NativeVSync_Create(name, strlen(name));
     ```

3. Set the VSync callback function through the **OH_NativeVSync** instance.
    ```c++
    #include <unistd.h>
    #include <iostream>

    OH_NativeVSync_RequestFrame(nativeVSync, callback, nullptr);
    while (!flag) { // Check the flag value. The while loop exits only after the VSync callback function is executed, indicating that a VSync signal is received.
        std::cout << "wait for vsync!\n";
        sleep(1);
    }
    std::cout << "vsync come, end this thread\n";
    ```

4. Destroy the **OH_NativeVSync** instance.
    ```c++
    OH_NativeVSync_Destroy(nativeVSync); // Destroy the OH_NativeVSync instance when the application does not need to receive VSync signals.
    ```

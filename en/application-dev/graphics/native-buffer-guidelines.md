# Native Buffer Development (C/C++)

## When to Use

The native buffer module provides APIs that you can use to apply for, use, and release the shared memory, and query memory properties.

The following scenario is common for native buffer development:

Use the native buffer APIs to create an **OH_NativeBuffer** instance, obtain memory properties, and map the corresponding ION memory to the process address space.

## Available APIs

| API| Description| 
| -------- | -------- |
| OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config \*config) | Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called. This function must be used in pair with **OH_NativeBuffer_Unreference**. Otherwise, memory leak occurs.|
| OH_NativeBuffer_Reference (OH_NativeBuffer \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.| 
| OH_NativeBuffer_Unreference (OH_NativeBuffer \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.| 
| OH_NativeBuffer_GetConfig (OH_NativeBuffer \*buffer, OH_NativeBuffer_Config \*config) | Obtains the properties of an **OH_NativeBuffer** instance.| 
| OH_NativeBuffer_Map (OH_NativeBuffer \*buffer, void \*\*virAddr) | Maps the ION memory allocated to an **OH_NativeBuffer** instance to the process address space.| 
| OH_NativeBuffer_Unmap (OH_NativeBuffer \*buffer) | Unmaps the ION memory allocated to an **OH_NativeBuffer** instance from the process address space.| 
| OH_NativeBuffer_GetSeqNum (OH_NativeBuffer \*buffer) | Obtains the sequence number of an **OH_NativeBuffer** instance.| 

For details about the APIs, see [native_buffer](../reference/apis-arkgraphics2d/_o_h___native_buffer.md).

## How to Develop

The following describes how to use the aforementioned APIs to create an **OH_NativeBuffer** instance, obtain memory properties, and map the corresponding ION memory to the process address space.

**Adding Dynamic Link Libraries**

Add the following library to **CMakeLists.txt**:
```txt
libnative_buffer.so
```

**Including Header Files**
```c++
#include <native_buffer/native_buffer.h>
```

1. Create an **OH_NativeBuffer** instance.
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
   
2. If the application needs to access the memory space of the **OH_NativeBuffer** instance, map the ION memory allocated to the instance to the process address space by calling **OH_NativeBuffer_Map**.
    ```c++
    // Map the ION memory to the process address space.
    void* virAddr = nullptr;
    int32_t ret = OH_NativeBuffer_Map(buffer, &virAddr); // After mapping, the start address of the memory is returned through the parameter virAddr.
    if (ret != 0) {
        std::cout << "OH_NativeBuffer_Map Failed" << std::endl;
    }

    // Unmap the ION memory from the process address space when it is no longer needed.
    ret = OH_NativeBuffer_Unmap(buffer);
    if (ret != 0) {
        std::cout << "OH_NativeBuffer_Unmap Failed" << std::endl;
    }
    ```

3. Obtain the memory properties.
    ```c++
    // Obtain the properties of the OH_NativeBuffer instance.
    OH_NativeBuffer_Config config2 = {};
    OH_NativeBuffer_GetConfig(buffer, &config2);
    // Obtain the sequence number of the OH_NativeBuffer instance.
     uint32_t hwBufferID = OH_NativeBuffer_GetSeqNum(buffer);
    ```

4. Destroy the **OH_NativeBuffer** instance.
    ```c++
    // Call OH_NativeBuffer_Unreference to decrease the reference count by 1. When the reference count reaches 0, the instance is destroyed.
    ret = OH_NativeBuffer_Unreference(buffer);
    if (ret != 0) {
        std::cout << "OH_NativeBuffer_Unreference Failed" << std::endl;
    }
    ```

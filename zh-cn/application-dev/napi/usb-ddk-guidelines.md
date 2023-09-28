# USB DDK开发指导

## 场景介绍

USB DDK（USB Driver Develop Kit）是为开发者提供的USB驱动程序开发套件，支持开发者基于用户态，在应用层开发USB设备驱动。提供了一系列主机侧访问设备的接口，包括主机侧打开和关闭接口、管道同步异步读写通信、控制传输、中断传输等。

## 接口说明

| 名称 | 描述 |
| -------- | -------- |
| OH_Usb_Init(void) | 初始化DDK。 |
| OH_Usb_Release(void) | 释放DDK。 |
| OH_Usb_GetDeviceDescriptor(uint64_t deviceId, struct UsbDeviceDescriptor *desc) | 获取设备描述符。 |
| OH_Usb_GetConfigDescriptor(uint64_t deviceId, uint8_t configIndex, struct UsbDdkConfigDescriptor **const config) | 获取配置描述符。请在描述符使用完后使用OH_Usb_FreeConfigDescriptor()释放描述符，否则会造成内存泄露。 |
| OH_Usb_FreeConfigDescriptor(const struct UsbDdkConfigDescriptor *const config) | 释放配置描述符，请在描述符使用完后释放描述符，否则会造成内存泄露。 |
| OH_Usb_ClaimInterface(uint64_t deviceId, uint8_t interfaceIndex, uint64_t *interfaceHandle) | 声明接口。 |
| OH_Usb_ReleaseInterface(uint64_t interfaceHandle) | 释放接口。 |
| OH_Usb_SendPipeRequest(const struct UsbRequestPipe *pipe, UsbDeviceMemMap *devMmap) | 发送管道请求，该接口为同步接口。中断传输和批量传输都使用该接口发送请求。 |
| OH_Usb_CreateDeviceMemMap(uint64_t deviceId, size_t size, UsbDeviceMemMap **devMmap) | 创建缓冲区。请在缓冲区使用完后，调用OH_Usb_DestroyDeviceMemMap()销毁缓冲区，否则会造成资源泄露。 |
| OH_Usb_DestroyDeviceMemMap(UsbDeviceMemMap *devMmap) | 销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。 |

详细的接口说明请参考[USB DDK](../reference/native-apis/_usb_ddk.md)。

## USB DDK开发步骤

以下步骤描述了如何使用 **USB DDK**开发USB驱动：

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libusb_ndk.z.so
```

**头文件**
```c++
#include <usb/usb_ddk_api.h>
#include <usb/usb_ddk_types.h>
```

1. **获取设备描述符**。使用 **usb_ddk_api.h** 的 **OH_Usb_Init** 接口初始化DDK，并使用 **OH_Usb_GetDeviceDescriptor**获取到设备描述符。

    ```c++
    // 初始化USB DDK
    OH_Usb_Init();
    struct UsbDeviceDescriptor devDesc;
    uint64_t deviceId = 0;
    // 获取设备描述符
    OH_Usb_GetDeviceDescriptor(deviceId, &devDesc);
    ```

2. **获取配置描述符及声明接口**。使用 **usb_ddk_api.h** 的 **OH_Usb_GetConfigDescriptor** 接口获取配置描述符 **config**，并使用 **OH_Usb_ClaimInterface** 声明接口。

    ```c++
    struct UsbDdkConfigDescriptor *config = nullptr;
    // 获取配置描述符
    OH_Usb_GetConfigDescriptor(deviceId, 1, &config);
    // 根据配置描述符,找到所需要通信的interfaceIndex
    uint8_t interfaceIndex = 0;
    // 声明接口
    uint64_t interfaceHandle = 0;
    OH_Usb_ClaimInterface(deviceId, interfaceIndex, &interfaceHandle);
    // 释放配置描述符
    OH_Usb_FreeConfigDescriptor(config);
    ```

3. **创建内存映射缓冲区及发送请求**。使用 **usb_ddk_api.h** 的**OH_Usb_CreateDeviceMemMap**接口创建内存映射缓冲区**devMmap**，并使用**OH_Usb_SendPipeRequest**发送请求。

    ```c++
    struct UsbDeviceMemMap *devMmap = nullptr;
    // 创建用于存放数据的缓冲区
    size_t bufferLen = 10;
    OH_Usb_CreateDeviceMemMap(deviceId, bufferLen, &devMmap);
    struct UsbRequestPipe pipe;
    pipe.interfaceHandle = interfaceHandle;
    // 根据配置描述符找到所要通信的端点
    pipe.endpoint = 128;
    pipe.timeout = UINT32_MAX;
    // 发送请求
    OH_Usb_SendPipeRequest(&pipe, devMmap);
    ```

4. **释放资源**。在所有请求处理完毕，程序退出前，使用 **usb_ddk_api.h** 的 **OH_Usb_DestroyDeviceMemMap** 接口销毁缓冲区。使用**OH_Usb_ReleaseInterface**释放接口。使用**OH_Usb_Release**释放USB DDK。

    ```c++
    // 销毁缓冲区
    OH_Usb_DestroyDeviceMemMap(devMmap);
    // 释放接口
    OH_Usb_ReleaseInterface(interfaceHandle);
    // 释放USB DDK
    OH_Usb_Release();
    ```
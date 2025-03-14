# 开发适用HID协议的设备驱动

## 简介

HID DDK（HID Driver Develop Kit）是为开发者提供的HID设备驱动程序开发套件，支持开发者基于用户态，在应用层开发HID设备驱动。提供了一系列主机侧访问设备的接口，包括创建设备、向设备发送事件、销毁设备、打开关闭设备、读取写入报告、获取设备信息等。

凡是采用USB总线，通过HID协议传输数据的设备，或者通过扩展外设驱动创建虚拟设备，来实现与非标设备的信息交互都可以使用HID DDK开发设备驱动。

### 基本概念

在进行HID DDK开发前，开发者应了解以下基本概念：

- **HID**

  HID（Human Interface Device），中文意思是“人机接口设备”。它是一类用于实现人与计算机或其他电子设备交互的硬件设备。HID 设备的主要功能是将用户的输入（如按键、点击、移动等）转换为数据信号，并将这些信号发送给主机设备（如计算机、平板电脑、游戏机等），从而实现用户对设备的控制和操作。

- **DDK**

  DDK（Driver Develop Kit）是OpenHarmony基于扩展外设框架，为开发者提供的驱动应用开发的工具包，可针对非标USB串口设备，开发对应的驱动。

### 实现原理

非标外设应用通过扩展外设管理服务获取HID设备的ID，通过RPC将ID和要操作的动作下发给HID设备驱动应用，驱动应用通过调用HID DDK接口可创建、销毁HID设备，以及对HID设备发送事件，获取HID报文，解析报文等，DDK接口使用HDI服务将指令下发至内核驱动，内核驱动使用指令与设备通信。

**图1** HID DDK调用原理

![HID_DDK原理图](figures/ddk-schematic-diagram.png)

## 约束与限制

* HID DDK开放API支持非标HID类外设扩展驱动开发场景。

* HID DDK开放API仅允许DriverExtensionAbilit生命周期内使用。

* 使用HID DDK开放API需要在module.json5中声明匹配的ACL权限，例如ohos.permission.ACCESS_DDK_HID。

## 接口说明

| 名称 | 描述 |
| -------- | -------- |
| OH_Hid_CreateDevice(Hid_Device *hidDevice, Hid_EventProperties *hidEventProperties) | 创建HID设备。请在设备使用完后使用OH_Hid_DestroyDevice销毁设备。 |
| OH_Hid_EmitEvent(int32_t deviceId, const Hid_EmitItem items[], uint16_t length) | 向指定deviceId的HID设备发送事件。 |
| OH_Hid_DestroyDevice(int32_t deviceId) | 销毁指定deviceId的HID设备。 |
| int32_t OH_Hid_Init(void) | 初始化HID DDK。 |
| int32_t OH_Hid_Release(void) | 释放HID DDK。 |
| int32_t OH_Hid_Open(uint64_t deviceId, uint8_t interfaceIndex, Hid_DeviceHandle **dev) | 打开deviceId和interfaceIndex指定的设备。 |
| int32_t OH_Hid_Close(Hid_DeviceHandle **dev) | 关闭设备。 |
| int32_t OH_Hid_Write(Hid_DeviceHandle *dev, uint8_t *data, uint32_t length, uint32_t *bytesWritten) | 向设备写入报告。 |
| int32_t OH_Hid_ReadTimeout(Hid_DeviceHandle *dev, uint8_t *data, uint32_t buffSize, int timeout, uint32_t *bytesRead) | 在指定的超时时间内从设备读取报告。 |
| int32_t OH_Hid_Read(Hid_DeviceHandle *dev, uint8_t *data, uint32_t buffSize, uint32_t *bytesRead) | 从设备读取报告，默认为阻塞模式（阻塞等待直到有数据可读取），可以调用OH_Hid_SetNonBlocking改变模式。 |
| int32_t OH_Hid_SetNonBlocking(Hid_DeviceHandle *dev, int nonblock) | 设置设备读取模式为非阻塞。 |
| int32_t OH_Hid_GetRawInfo(Hid_DeviceHandle *dev, Hid_RawDevInfo *rawDevInfo) | 获取设备原始信息。 |
| int32_t OH_Hid_GetRawName(Hid_DeviceHandle *dev, char *data, uint32_t buffSize) | 获取设备原始名称。 |
| int32_t OH_Hid_GetPhysicalAddress(Hid_DeviceHandle *dev, char *data, uint32_t buffSize) | 获取设备物理地址。 |
| int32_t OH_Hid_GetRawUniqueId(Hid_DeviceHandle *dev, uint8_t *data, uint32_t buffSize) | 获取设备原始唯一标识符。 |
| int32_t OH_Hid_SendReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, const uint8_t *data, uint32_t length) | 向设备发送报告。 |
| int32_t OH_Hid_GetReport(Hid_DeviceHandle *dev, Hid_ReportType reportType, uint8_t *data, uint32_t buffSize) | 获取设备报告。 |
| int32_t OH_Hid_GetReportDescriptor(Hid_DeviceHandle *dev, uint8_t *buf, uint32_t buffSize, uint32_t *bytesRead) | 获取设备报告描述符。 |

详细的接口说明请参考[HID DDK](../../reference/apis-driverdevelopment-kit/_hid_ddk.md)。

## 开发步骤

### HID基础驱动能力开发

以下步骤描述了如何使用 **HID DDK**开发HID设备驱动：

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libhid.z.so
```

**头文件**
```c++
#include <hid/hid_ddk_api.h>
#include <hid/hid_ddk_types.h>
```

1. 创建设备。

    使用 **hid_ddk_api.h** 的 **OH_Hid_CreateDevice** 接口创建HID设备，成功返回设备deviceId，失败返回[错误码](../../reference/apis-driverdevelopment-kit/_hid_ddk.md#hid_ddkerrcode)。

    ```c++
    // 构建HID设备属性
    std::vector<Hid_DeviceProp> deviceProp = {HID_PROP_DIRECT}; //需要引入vector头文件
    std::string deviceName = "keyboard";
    Hid_Device hidDevice = {
        .deviceName = deviceName.c_str(), 
        .vendorId = 0x6006, 
        .productId = 0x6006, 
        .version = 1, 
        .bustype = 3,
        .properties = deviceProp.data(),
        .propLength = (uint16_t)deviceProp.size()
    };
    // 构建HID设备关注的事件属性
    std::vector<Hid_EventType> eventType = {HID_EV_ABS, HID_EV_KEY, HID_EV_SYN, HID_EV_MSC};
    Hid_EventTypeArray eventTypeArray = {.hidEventType = eventType.data(), .length = (uint16_t)eventType.size()};
    std::vector<Hid_KeyCode> keyCode = {HID_BTN_TOOL_PEN, HID_BTN_TOOL_RUBBER, HID_BTN_TOUCH, HID_BTN_STYLUS, HID_BTN_RIGHT};
    Hid_KeyCodeArray keyCodeArray = {.hidKeyCode = keyCode.data(), .length = (uint16_t)keyCode.size()};
    std::vector<Hid_MscEvent> mscEvent = {HID_MSC_SCAN};
    Hid_MscEventArray mscEventArray = {.hidMscEvent = mscEvent.data(), .length = (uint16_t)mscEvent.size()};
    std::vector<Hid_AbsAxes> absAxes = {HID_ABS_X, HID_ABS_Y, HID_ABS_PRESSURE};
    Hid_AbsAxesArray absAxesArray = {.hidAbsAxes = absAxes.data(), .length = (uint16_t)absAxes.size()};
    Hid_EventProperties hidEventProp = {
        .hidEventTypes = eventTypeArray,
        .hidKeys = keyCodeArray,
        .hidAbs = absAxesArray,
        .hidMiscellaneous = mscEventArray
        };
        // 创建设备并获取到deviceId
        int32_t deviceId = OH_Hid_CreateDevice(&hidDevice, &hidEventProp);
    ```

2. 向指定deviceId的HID设备发送事件。

    使用 **hid_ddk_api.h** 的 **OH_Hid_EmitEvent** 向指定的deviceId的设备发送事件。

    ```c++
    // 构建需要发送事件
    Hid_EmitItem event = {.type = HID_EV_MSC, .code = HID_MSC_SCAN, .value = 0x000d0042};
    std::vector<Hid_EmitItem> itemVec;
    itemVec.push_back(event);
    // 向指定deviceId的HID设备发送事件
    int32_t ret = OH_Hid_EmitEvent(deviceId, itemVec.data(), (uint16_t)itemVec.size());
    ```

3. 释放资源。

    在所有请求处理完毕，程序退出前，使用 **hid_ddk_api.h** 的 **OH_Hid_DestroyDevice** 接口销毁HID设备。

    ```c++
    // 销毁HID设备
    int32_t ret = OH_Hid_DestroyDevice(deviceId);
    ```

### HID报文通信驱动能力开发

以下步骤描述了如何使用 **HID DDK** 开发HID报文通信驱动：

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libhid.z.so
```

**头文件**
```c++
#include <hid/hid_ddk_api.h>
#include <hid/hid_ddk_types.h>
```

1. 初始化DDK。

    使用 **hid_ddk_api.h** 的 **OH_Hid_Init** 初始化HID DDK。

    ```c++
    // 初始化HID DDK
    OH_Hid_Init();
    ```

2. 打开设备。

    初始化HID DDK后，使用 **hid_ddk_api.h** 的 **OH_Hid_Open** 打开HID设备。

    ```c++
    uint64_t deviceId = 0x100000003;
    uint8_t interfaceIndex1 = 0;
    uint8_t interfaceIndex2 = 1;
    Hid_DeviceHandle *dev = NULL;
    Hid_DeviceHandle *devFeature = NULL;
    // 打开deviceId和interfaceIndex1指定的HID设备（一般为/dev/hidraw0设备文件）
    OH_Hid_Open(deviceId, interfaceIndex1, &dev);
    // 打开deviceId和interfaceIndex2指定的HID设备（一般为/dev/hidraw1设备文件）
    OH_Hid_Open(deviceId, interfaceIndex2, &devFeature);
    ```

3. 向HID设备写入/发送报告（HID设备与主机之间交换的数据包）。
    - 当报告类型为HID_OUTPUT_REPORT（输出报告）时，支持如下两种写入/发送方式。
        - 使用 **hid_ddk_api.h** 的 **OH_Hid_Write** 向HID设备写入一个输出报告。

            ```c++
            uint8_t data[] = {0x02, 0x02};
            uint32_t bytesWritten = 0;
            // 写入报告
            int32_t ret = OH_Hid_Write(dev, data, sizeof(data), &bytesWritten);
            ```

        - 使用 **hid_ddk_api.h** 的 **OH_Hid_SendReport** 向HID设备发送一个输出报告。

            ```c++
            uint8_t data1[2] = {0x00};
            // 指定报告编号
            data1[0] = 0x02;
            // 设置报告数据
            data1[1] = 0x02;

            // 发送输出报告
            int32_t ret = OH_Hid_SendReport(dev, HID_OUTPUT_REPORT, data1, sizeof(data1));
            ```

    - 当报告类型为HID_FEATURE_REPORT（特性报告）时，使用 **hid_ddk_api.h** 的 **OH_Hid_SendReport** 向HID设备发送一个特性报告。

        ```c++
        uint8_t data2[2] = {0x00};
        // 指定报告编号
        data2[0] = 0x02;
        // 设置报告数据
        data2[1] = 0x02;

        // 发送特性报告
        int32_t ret = OH_Hid_SendReport(devFeature, HID_FEATURE_REPORT, data2, sizeof(data2));
        ```

4. 从HID设备读取报告。
    - 当报告类型为HID_INPUT_REPORT（输入报告）时，支持如下三种读取方式。
        - 使用 **hid_ddk_api.h** 的 **OH_Hid_Read** 或者 **OH_Hid_ReadTimeout** 以阻塞模式从HID设备读取一个输入报告。

            ```c++
            uint8_t data3[9] = {0x00};
            uint32_t bytesRead = 0;
            // 从HID设备读取报告
            int32_t ret = OH_Hid_Read(dev, data3, sizeof(data3), &bytesRead);

            uint8_t data4[9] = {0x00};
            uint32_t bytesRead = 0;
            // 在指定的超时时间内从HID设备读取报告
            ret = OH_Hid_ReadTimeout(dev, data4, sizeof(data4), 10000, &bytesRead);
            ```

        - 使用 **hid_ddk_api.h** 的 **OH_Hid_SetNonBlocking** 和 **OH_Hid_Read** 以非阻塞模式从HID设备读取一个输入报告。

            ```c++
            // 1启用非阻塞，0禁用非阻塞
            int32_t ret = OH_Hid_SetNonBlocking(dev, 1);

            // 本示例执行时，设备可能没有数据，因此需要等待用户输入
            sleep(1);
            uint8_t data5[9] = {0};
            uint32_t bytesRead = 0;
            // 从HID设备读取报告
            ret = OH_Hid_Read(dev, data5, sizeof(data5), &bytesRead);
            ```

        - 使用 **hid_ddk_api.h** 的 **OH_Hid_GetReport** 从HID设备读取一个输入报告。

            ```c++
            uint8_t data6[9] = {0};
            // 指定报告编号
            data6[0] = 0x00;

            // 读取输入报告
            int32_t ret = OH_Hid_GetReport(dev, HID_INPUT_REPORT, data6, sizeof(data6));
            ```

    - 当报告类型为HID_FEATURE_REPORT（特性报告）时，使用 **hid_ddk_api.h** 的 **OH_Hid_GetReport** 从HID设备读取一个特性报告。

        ```c++
        uint8_t data7[8] = {0};
        // 指定报告编号
        data7[0] = 0x07;

        // 读取特性报告
        int32_t ret = OH_Hid_GetReport(devFeature, HID_FEATURE_REPORT, data7, sizeof(data7));
        ```

5. 获取设备原始信息、原始名称、物理地址、原始唯一标识符。

    使用 **hid_ddk_api.h** 的 **OH_Hid_GetRawInfo** 获取HID设备原始信息，使用 **OH_Hid_GetRawName** 获取HID设备原始名称，使用 **OH_Hid_GetPhysicalAddress** 获取HID设备物理地址，使用 **OH_Hid_GetRawUniqueId** 获取HID设备原始唯一标识符。这些信息可被上层应用引用，例如在界面中展示设备信息等。

    ```c++
    struct Hid_RawDevInfo rawDevInfo;
    int32_t ret = OH_Hid_GetRawInfo(dev, &rawDevInfo);

    char rawName[1024] = {0};
    ret = OH_Hid_GetRawName(dev, rawName, sizeof(rawName));

    char physicalAddress[1024] = {0};
    ret = OH_Hid_GetPhysicalAddress(dev, physicalAddress, sizeof(physicalAddress));

    uint8_t uniqueIdData[64] = {0};
    ret = OH_Hid_GetRawUniqueId(dev, uniqueIdData, sizeof(uniqueIdData));
    ```

6. 获取报告描述符。

    使用 **hid_ddk_api.h** 的 **OH_Hid_GetReportDescriptor** 获取HID设备报告描述符。

    ```c++
    uint8_t desData[1024] = {0};
    uint32_t bytesRead = 0;
    int32_t ret = OH_Hid_GetReportDescriptor(dev, desData, sizeof(desData), &bytesRead);
    ```

7. 关闭设备。

    在所有请求处理完毕后，使用 **hid_ddk_api.h** 的 **OH_Hid_Close** 关闭设备。

    ```c++
    // 关闭设备
    OH_Hid_Close(&dev);
    OH_Hid_Close(&devFeature);
    ```

8. 释放DDK。

    在关闭HID设备后，使用 **hid_ddk_api.h** 的 **OH_Hid_Release** 释放HID DDK。

    ```c++
    // 释放HID DDK
    OH_Hid_Release();
    ```
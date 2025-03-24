# 开发适用串口协议的设备驱动

## 简介

在工业用途场景中和一些陈旧设备上，都有对非标串口设备的使用需求，例如：温湿度测量计、特殊身份读卡器等，当系统中没有适配该设备的驱动时，会导致设备接入后无法使用。USB Serial DDK（USB Serial Driver Develop Kit）是为开发者提供的USB串口驱动程序开发套件，支持开发者基于用户态，在应用层开发USB串口设备驱动。USB Serial DDK提供了一系列主机侧访问设备的接口，包括主机侧打开和关闭接口、串口读写通信等。依赖OH提供相应的驱动开发接口，支持该类三方生态外设接入鸿蒙生态，满足鸿蒙生态安全加密场景应用需求。

### 基本概念

在进行USB Serial DDK开发前，开发者应了解以下基本概念：

- **USB 串口**

    USB 串口（USB-to-Serial）是指一种接口转换技术，它允许通过 USB（通用串行总线）接口实现与传统串行端口（如 RS-232、RS-485 等）之间的数据通信。这种技术通常通过专门的硬件适配器或特定的内置芯片来实现。

- **AMS**

    AMS（Ability Manager Service）用于协调各Ability运行关系、及对生命周期进行调度的系统服务。在驱动开发过程中用于拉起和关闭扩展驱动能力DriverExtensionAbility。

- **BMS**

    BMS（Bundle Manager Service）在OpenHarmony上主要负责应用的安装、卸载和数据管理。

- **DDK**

    DDK（Driver Develop Kit）是OpenHarmony基于扩展外设框架，为开发者提供的驱动应用开发的工具包，可针对非标USB串口设备，开发对应的驱动。

- **非标外设**

    非标外设（也称为自定义外设或专有外设）是指不遵循通用标准或专门为特定应用场景定制设计的外围设备。这类设备往往需要专门的软件支持或者特殊的接口来实现与主机系统的通信。

- **标准外设**

    标准外设指的是遵循行业广泛接受的标准规范设计的外围设备（USB 键盘、鼠标）。这些设备通常具有统一的接口协议、物理尺寸和电气特性，使得其可以在不同的系统之间互换使用。

### 实现原理

非标外设应用通过扩展外设管理服务获取USB串口设备的ID，通过RPC将ID和要操作的动作下发给USB串口驱动应用，USB串口驱动应用通过调用USB Serial DDK接口可设置串口属性（波特率、数据位、校验位等），读取串口数据，DDK接口使用HDI服务将指令下发至内核驱动，内核驱动使用指令与设备通信。

**图1** USB Serial DDK调用原理

![USBSerial_DDK原理图](figures/ddk-schematic-diagram.png)

### 约束与限制

- USB Serial DDK开放API支持USB串口接口非标外设扩展驱动开发场景。

- USB Serial DDK开放API使用范围内仅允许DriverExtensionAbilit生命周期内使用。

- 使用USB Serial DDK开放API需要在module.json5中声明匹配的ACL权限，例如ohos.permission.ACCESS_DDK_USB_SERIAL。

## 环境搭建

请参考[环境准备](environmental-preparation.md)完成开发前的准备工作。

## 开发指导

### 接口说明

| 名称 | 描述 |
| -------- | -------- |
| OH_UsbSerial_Init(void) | 初始化USB Serial DDK。 |
| OH_UsbSerial_Release(void) | 释放USB Serial DDK。 |
| OH_UsbSerial_Open(uint64_t deviceId, uint8_t interfaceIndex, UsbSerial_Device **dev) | 通过deviceId和interfaceIndex打开USB串口设备。请在设备使用完后调用OH_UsbSerial_Close()关闭设备，否则会造成内存泄漏。 |
| OH_UsbSerial_Close(UsbSerial_Device **dev) | 关闭USB串口设备，请在设备使用完后关闭设备，否则会造成内存泄露。 |
| OH_UsbSerial_Read(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesRead) | 从USB串口设备读取数据到缓冲区。 |
| OH_UsbSerial_Write(UsbSerial_Device *dev, uint8_t *buff, uint32_t bufferSize, uint32_t *bytesWritten) | 将buff中的数据写入USB串口设备。 |
| OH_UsbSerial_SetBaudRate(UsbSerial_DeviceHandle *dev, uint32_t baudRate) | 设置USB串口设备的波特率。如果串口的数据位为8，停止位为1，不校验，则调用该接口。 |
| OH_UsbSerial_SetParams(UsbSerial_Device *dev, UsbSerial_Params *params) | 设置USB串口设备的参数，包含波特率、数据传输位、停止位、校验设置。 |
| OH_UsbSerial_SetTimeout(UsbSerial_Device *dev, int timeout) | 设置读取USB串口设备上报数据的超时时间，默认时间为0。 |
| OH_UsbSerial_SetFlowControl(UsbSerial_Device *dev, UsbSerial_FlowControl flowControl) | 设置流控参数。 |
| OH_UsbSerial_Flush(UsbSerial_Device *dev) | 写入完成后清空输入和输出缓冲区。 |
| OH_UsbSerial_FlushInput(UsbSerial_Device *dev) | 刷新输入缓冲区，缓冲区中的数据会被立刻清空。 |
| OH_UsbSerial_FlushOutput(UsbSerial_Device *dev) | 刷新输出缓冲区，缓冲区中的数据会被立刻清空。 |

详细的接口说明请参考[USB Serial DDK](../../reference/apis-driverdevelopment-kit/_serial_ddk.md)。

### 开发步骤

以下步骤描述了如何使用 **USB Serial DDK**开发USB串口驱动：

**添加动态链接库**

CMakeLists.txt中添加以下lib。
```txt
libusb_serial_ndk.z.so
```

**头文件**
```c++
#include <serial/usb_serial_api.h>
#include <serial/usb_serial_types.h>
```

1. 初始化DDK。

    使用 **usb_serial_api.h** 的 **OH_UsbSerial_Init** 初始化DDK。

    ```c++
    // 初始化USB Serial DDK
    OH_UsbSerial_Init();
    ```

2. 打开USB串口设备。

    使用 **usb_serial_api.h** 的 **OH_UsbSerial_Open** 打开设备。

    ```c++
    UsbSerial_Device *dev = NULL;
    uint64_t deviceId = 1688858450198529;
    uint8_t interfaceIndex = 0;
    // 打开deviceId和interfaceIndex指定的USB串口设备
    OH_UsbSerial_Open(deviceId, interfaceIndex, &dev);
    ```

3. 设置USB串口设备的参数。

    使用 **usb_serial_api.h** 的 **OH_UsbSerial_SetParams** 接口设置串口参数，或者直接调用 **OH_UsbSerial_SetBaudRate** 设置波特率，使用 **OH_UsbSerial_SetTimeout** 设置读取数据的超时时间。

    ```c++
    UsbSerial_Params params;
    params.baudRate = 9600;
    params.nDataBits = 8;
    params.nStopBits = 1;
    params.parity = 0;
    // 设置串口参数
    OH_UsbSerial_SetParams(dev, &params);

    // 设置波特率
    uint32_t baudRate = 9600;
    OH_UsbSerial_SetBaudRate(dev, baudRate);

    // 设置超时时间
    int timeout = 500;
    OH_UsbSerial_SetTimeout(dev, timeout);
    ```

4. 设置流控、清空缓冲区。

    使用 **usb_serial_api.h** 的 **OH_UsbSerial_SetFlowControl** 设置流控方式，使用 **OH_UsbSerial_Flush** 清空缓冲区，使用 **OH_UsbSerial_FlushInput** 清空输入缓冲区，使用 **OH_UsbSerial_FlushOutput** 清空输出缓冲区。

    ```c++
    // 设置软件流控
    OH_UsbSerial_SetFlowControl(dev, USB_SERIAL_SOFTWARE_FLOW_CONTROL);

    // 清空缓冲区
    OH_UsbSerial_Flush(dev);

    // 清空输入缓冲区
    OH_UsbSerial_FlushInput(dev);

    // 清空输出缓冲区
    OH_UsbSerial_FlushOutput(dev);
    ```
5. 向USB串口设备写入/读取数据。

    使用 **usb_serial_api.h** 的 **OH_UsbSerial_Write** 给设备发送数据，并使用 **OH_UsbSerial_Read** 读取设备发送过来的数据。

    ```c++
    uint32_t bytesWritten = 0;
    // 测试设备读取指令，具体指令根据设备协议而定
    uint8_t writeBuff[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0xA};
    // 发送数据
    OH_UsbSerial_Write(dev, writeBuff, sizeof(writeBuff), &bytesWritten);

    // 接收数据
    uint8_t readBuff[100];
    uint32_t bytesRead = 0;
    OH_UsbSerial_Read(dev, readBuff, sizeof(readBuff), &bytesRead);
    ```

6. 关闭USB串口设备。

    在所有请求处理完毕，程序退出前，使用 **usb_serial_api.h** 的 **OH_UsbSerial_Close** 关闭设备。
    ```c++
    // 关闭设备
    OH_UsbSerial_Close(&dev);
    ```

7. 释放DDK。

    在关闭USB串口设备后，使用 **usb_serial_api.h** 的 **OH_UsbSerial_Release** 释放DDK。

    ```c++
    // 释放USB Serial DDK
    OH_UsbSerial_Release();
    ```

### 调测验证

驱动应用侧开发完成后，可在Openahrmony设备上安装应用，测试步骤如下：

1. 在设备上点击驱动应用，应用在设备上被拉起。
2. 点击波特率等设置按钮，可以设置串口属性。
3. 点击数据读取按钮，可以读取到串口设备数据。

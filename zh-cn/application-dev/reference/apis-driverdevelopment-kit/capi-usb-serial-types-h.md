# usb_serial_types.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## 概述

提供USB SERIAL DDK中的枚举变量、结构体定义与宏定义。

**引用文件：** <usb_serial/usb_serial_types.h>

**库：** libusb_serial.z.so

**系统能力：** SystemCapability.Driver.UsbSerial.Extension

**起始版本：** 18

**相关模块：** [SerialDdk](capi-serialddk.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [UsbSerial_Params](capi-serialddk-usbserial-params.md) | __attribute__((aligned(8))) UsbSerial_Params | 定义USB SERIAL DDK使用的USB串口参数. |
| [UsbSerial_DeviceHandle](capi-serialddk-usbserial-devicehandle.md) | UsbSerial_DeviceHandle | USB串口设备数据结构（不透明）。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [UsbSerial_DdkRetCode](#usbserial_ddkretcode) | UsbSerial_DdkRetCode | 定义USB SERIAL DDK使用的返回码。 |
| [UsbSerial_FlowControl](#usbserial_flowcontrol) | UsbSerial_FlowControl | 定义USB SERIAL DDK中的流量控制。 |
| [UsbSerial_Parity](#usbserial_parity) | UsbSerial_Parity | 定义USB SERIAL DDK使用的校验参数枚举。 |

## 枚举类型说明

### UsbSerial_DdkRetCode

```
enum UsbSerial_DdkRetCode
```

**描述**

定义USB SERIAL DDK使用的返回码。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| USB_SERIAL_DDK_NO_PERM = 201 | 权限被拒绝。 |
| USB_SERIAL_DDK_INVALID_PARAMETER = 401 | 无效参数。 |
| USB_SERIAL_DDK_SUCCESS = 31600000 | 操作成功。 |
| USB_SERIAL_DDK_INVALID_OPERATION = 31600001 | 无效操作。 |
| USB_SERIAL_DDK_INIT_ERROR = 31600002 | 初始化失败。 |
| USB_SERIAL_DDK_SERVICE_ERROR = 31600003 | 服务错误。 |
| USB_SERIAL_DDK_MEMORY_ERROR = 31600004 | 内存相关错误，例如内存不足、内存数据复制失败或内存应用程序故障。 |
| USB_SERIAL_DDK_IO_ERROR = 31600005 | I/O 错误。 |
| USB_SERIAL_DDK_DEVICE_NOT_FOUND = 31600006 | 未找到设备。 |

### UsbSerial_FlowControl

```
enum UsbSerial_FlowControl
```

**描述**

定义USB SERIAL DDK中的流量控制。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| USB_SERIAL_NO_FLOW_CONTROL = 0 | 无流量控制。 |
| USB_SERIAL_SOFTWARE_FLOW_CONTROL = 1 | 软件流控。 |
| USB_SERIAL_HARDWARE_FLOW_CONTROL = 2 | 硬件流控。 |

### UsbSerial_Parity

```
enum UsbSerial_Parity
```

**描述**

定义USB SERIAL DDK使用的校验参数枚举。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| USB_SERIAL_PARITY_NONE = 0 | 无校验。 |
| USB_SERIAL_PARITY_ODD = 1 | 奇校验。 |
| USB_SERIAL_PARITY_EVEN = 2 | 偶校验。 |



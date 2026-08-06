# UsbRequestPipe
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct UsbRequestPipe {...} __attribute__((aligned(8))) UsbRequestPipe
```

## 概述

请求管道，是USB数据传输请求的抽象，用于描述USB数据传输的基本配置参数，包括接口句柄、端点地址和超时时间。适用于需要进行USB数据传输的场景。

**起始版本：** 10

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint64_t interfaceHandle | 接口操作句柄，用于标识USB设备上的接口，由[OH_Usb_ClaimInterface](capi-usb-ddk-api-h.md#oh_usb_claiminterface)接口获取。 |
| uint32_t timeout | 超时时间，单位：毫秒。值为0表示等待直到操作完成；非0值表示在指定毫秒数内未完成则超时。 |
| uint8_t endpoint | 要通信的端点的地址。 |



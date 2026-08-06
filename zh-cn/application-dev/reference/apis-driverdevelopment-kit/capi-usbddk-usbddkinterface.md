# UsbDdkInterface
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct UsbDdkInterface {...} UsbDdkInterface
```

## 概述

USB接口，是特定接口下备用设置的集合。

**起始版本：** 10

**相关模块：** [UsbDdk](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t numAltsetting | USB接口的备用设置数量。 |
| [struct UsbDdkInterfaceDescriptor](capi-usbddk-usbddkinterfacedescriptor.md)* altsetting | USB接口的备用设置数组的指针，数组的长度由numAltsetting指定。 |



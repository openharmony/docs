# Hid_DeviceHandle
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Hid_DeviceHandle Hid_DeviceHandle
```

## 概述

不透明的USB HID设备结构，用于标识和操作HID设备实例。开发者通过该句柄进行HID设备的打开、关闭、读写等操作。

**起始版本：** 18

**相关模块：** [HidDdk](capi-hidddk.md)

**所在头文件：** [hid_ddk_types.h](capi-hid-ddk-types-h.md)


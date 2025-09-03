# UsbControlRequestSetup
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## 概述

控制传输setup包，对应USB协议中的Setup Data。

**起始版本：** 10

**相关模块：** [UsbDDK](capi-usbddk.md)

**所在头文件：** [usb_ddk_types.h](capi-usb-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint8_t bmRequestType | 请求类型。 |
| uint8_t bRequest | 具体的请求。 |
| uint16_t wValue | 具体的请求不同，其代表的含义不一样。 |
| uint16_t wIndex | 具体的请求不同，其代表的含义不一样，通常用来传递索引或者偏移量。 |
| uint16_t wLength | 如果有数据阶段的传输，其代表传输的字节个数。 |



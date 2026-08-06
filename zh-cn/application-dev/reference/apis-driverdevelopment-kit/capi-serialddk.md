# USBSerialDDK
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供USB Serial DDK（USB串口驱动开发工具包）接口，包括枚举类型和USB Serial DDK API使用的数据结构。串口通信常见于工业用途及一些老旧设备，如：发卡机、身份证读卡器等。开发者通过使用USB Serial DDK，可以开发USB串口外设扩展驱动。

**系统能力：** SystemCapability.Driver.UsbSerial.Extension

**起始版本：** 18

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [usb_serial_api.h](capi-usb-serial-api-h.md) | 声明用于主机侧通过USB接口访问串口设备的USB Serial DDK接口，提供串口读写操作和参数配置的能力，适用于工业控制、嵌入式设备通信等需要通过USB访问串口设备的场景。 |
| [usb_serial_types.h](capi-usb-serial-types-h.md) | 提供USB Serial DDK中的枚举类型与结构体的定义，用于USB串口驱动开发，简化串口设备参数配置、返回码处理和流量控制等操作，提升驱动开发效率。 |

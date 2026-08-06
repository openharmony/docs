# HidDdk
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

## 概述

提供HID DDK接口，包括创建设备、发送事件、销毁设备等功能，用于HID设备的驱动开发。

**系统能力：** SystemCapability.Driver.HID.Extension

**起始版本：** 11

## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [hid_ddk_api.h](capi-hid-ddk-api-h.md) | 声明主机侧访问输入设备的HID DDK（Driver Development Kit，驱动开发工具包）接口。该模块提供了创建、打开、读写HID设备的能力，支持设备管理和事件注入，适用于需要模拟或管理HID输入设备的场景。 |
| [hid_ddk_types.h](capi-hid-ddk-types-h.md) | 提供HID DDK中的枚举变量与结构体定义，支持开发者在驱动开发中定义和操作HID设备，适用于与鼠标、键盘、触摸屏等输入设备交互的场景，提供了设备特性、事件类型、键值编码、坐标轴等完整定义，帮助开发者快速实现HID设备的驱动开发。 |

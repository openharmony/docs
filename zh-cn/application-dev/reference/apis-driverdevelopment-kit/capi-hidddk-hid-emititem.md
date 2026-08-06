# Hid_EmitItem
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Hid_EmitItem {...} Hid_EmitItem
```

## 概述

表示HID事件信息结构体，包含事件类型、事件编码和事件值，用于描述输入设备的上报事件。在驱动开发场景中，该结构体用于传递和识别各类HID设备产生的事件。

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

**所在头文件：** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint16_t type | HID事件类型，用于标识事件类别，如按键、移动等。取值范围参考HID协议规范。 |
| uint16_t code | HID事件编码，用于标识具体的HID事件。取值范围参考HID协议规范。 |
| uint32_t value | HID事件值，表示事件的参数或状态，具体含义取决于事件类型和编码。例如：对于按键事件，表示按键状态；对于移动事件，表示移动距离等。 |



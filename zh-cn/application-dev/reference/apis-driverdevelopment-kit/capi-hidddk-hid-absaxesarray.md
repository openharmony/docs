# Hid_AbsAxesArray
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Hid_AbsAxesArray {...} Hid_AbsAxesArray
```

## 概述

绝对坐标属性数组，用于存储HID设备的多个绝对坐标轴的属性信息，支持描述如触摸屏、游戏摇杆等输入设备的坐标特征，适用于需要精确读取和处理多维输入数据的驱动开发场景，例如在手柄、触摸板等输入设备中记录轴位数据。

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

**所在头文件：** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [Hid_AbsAxes](capi-hid-ddk-types-h.md#hid_absaxes)* hidAbsAxes | 指向绝对坐标属性编码数组首元素的指针。需与length配合使用，指针需有效且不为 NULL。 |
| uint16_t length | 数组的有效长度，表示hidAbsAxes指针指向的有效元素个数。取值范围：0~65535。 |



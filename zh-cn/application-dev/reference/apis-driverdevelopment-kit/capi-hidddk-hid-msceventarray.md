# Hid_MscEventArray
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Hid_MscEventArray {...} Hid_MscEventArray
```

## 概述

其他特殊事件属性数组，用于存储HID设备支持的特殊事件信息。

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

**所在头文件：** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [Hid_MscEvent](capi-hid-ddk-types-h.md#hid_mscevent)* hidMscEvent | 其他特殊事件属性编码数组的指针，指向调用方预先分配的数组（不允许为空指针），数组大小不小于length。 |
| uint16_t length | 数组的有效长度，不超过hidMscEvent数组的实际长度。 |



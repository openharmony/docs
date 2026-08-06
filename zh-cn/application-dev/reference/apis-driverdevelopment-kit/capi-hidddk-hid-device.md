# Hid_Device
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Hid_Device {...} Hid_Device
```

## 概述

设备基本信息，用于表示HID设备的名称、厂商ID、产品ID等基本属性，在创建和操作HID设备时作为设备标识使用。

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

**所在头文件：** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const char* deviceName | 设备名称，最大长度128字符，不能为NULL。超出长度或为NULL时返回错误。 |
| uint16_t vendorId | 厂商ID。 |
| uint16_t productId | 产品ID。 |
| uint16_t version | 版本号。 |
| uint16_t bustype | 总线类型，取值含义参考标准HID协议的总线类型定义。 |
| Hid_DeviceProp* properties | 设备特性。使用前应检查指针是否为空；该指针仅在Hid_Device对象有效期间有效，不应手动释放。 |
| uint16_t propLength | 设备特性数量，表示properties数组的有效元素个数。注意：遍历数组时应以该值为边界条件；该值可能为0。 |



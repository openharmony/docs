# UsbDdkInterface


## 概述

USB接口，是特定接口下备用设置的集合。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)

**所在头文件：** [usb_ddk_types.h](usb__ddk__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [numAltsetting](#numaltsetting) | 接口的备用设置数量。 |
| [altsetting](#altsetting) | 接口的备用设置。 |


## 结构体成员变量说明


### altsetting


```
struct UsbDdkInterfaceDescriptor* UsbDdkInterface::altsetting
```

**描述:**

接口的备用设置。


### numAltsetting


```
uint8_t UsbDdkInterface::numAltsetting
```

**描述:**

接口的备用设置数量。

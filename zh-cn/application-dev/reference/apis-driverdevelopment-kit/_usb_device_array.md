# Usb_DeviceArray


## 概述

设备ID清单，用于存放[OH_Usb_GetDevices()](_usb_ddk.md#oh_usb_getdevices)接口获取到的设备ID列表和设备数量。

**起始版本：**

18

**相关模块:**

[USB DDK](_usb_ddk.md)

**所在头文件：** [usb_ddk_types.h](usb__ddk__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [deviceIds](#deviceids) | 开发者申请好的设备数组首地址。 |
| [num](#num) | 实际返回的设备数量。 |

## 结构体成员变量说明


### deviceIds


```
uint64_t* Usb_DeviceArray::deviceIds
```

**描述:**

开发者申请好的设备数组首地址，申请的大小不超过128个设备ID。
### num


```
uint32_t Usb_DeviceArray::num
```

**描述:**

实际返回的设备数量，根据数量遍历deviceIds获得设备ID。当该值为0时，表示不存在USB设备。
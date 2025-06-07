# UsbDeviceMemMap


## 概述

设备内存映射，通过[OH_Usb_CreateDeviceMemMap()](_usb_ddk.md#oh_usb_createdevicememmap)创建设备内存映射，使用内存映射后的缓冲区，获得更好的性能。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)

**所在头文件：** [usb_ddk_types.h](usb__ddk__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [address](#address) | 映射后的缓冲区地址。 |
| [size](#size) | 缓冲区大小。 |
| [offset](#offset) | 所使用的缓冲区的偏移量，默认为0，表示没有偏移，从address开始。 |
| [bufferLength](#bufferlength) | 所使用的缓冲区的长度，默认等于size，表示使用全部的缓冲区。 |
| [transferedLength](#transferedlength) | 实际传输的数据的长度。 |


## 结构体成员变量说明


### address


```
uint8_t* const UsbDeviceMemMap::address
```

**描述:**

映射后的缓冲区地址。


### bufferLength


```
uint32_t UsbDeviceMemMap::bufferLength
```

**描述:**

所使用的缓冲区的长度，默认等于size，表示使用全部的缓冲区。


### offset


```
uint32_t UsbDeviceMemMap::offset
```

**描述:**

所使用的缓冲区的偏移量，默认为0，表示没有偏移，从address开始。


### size


```
const size_t UsbDeviceMemMap::size
```

**描述:**

缓冲区大小。


### transferedLength


```
uint32_t UsbDeviceMemMap::transferedLength
```

**描述:**

实际传输的数据的长度。

# UsbDdkInterfaceDescriptor


## 概述

接口描述符。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)

**所在头文件：** [usb_ddk_types.h](usb__ddk__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [interfaceDescriptor](#interfacedescriptor) | 标准接口描述符。 |
| [endPoint](#endpoint) | 该接口所包含的端点描述符。 |
| [extra](#extra) | 未做解析的描述符，包含特定于类或供应商的描述符。 |
| [extraLength](#extralength) | 未做解析的描述符长度。 |


## 结构体成员变量说明


### endPoint


```
struct UsbDdkEndpointDescriptor* UsbDdkInterfaceDescriptor::endPoint
```

**描述:**

该接口所包含的端点描述符。


### extra


```
const uint8_t* UsbDdkInterfaceDescriptor::extra
```

**描述:**

未做解析的描述符，包含特定于类或供应商的描述符。


### extraLength


```
uint32_t UsbDdkInterfaceDescriptor::extraLength
```

**描述:**

未做解析的描述符长度。


### interfaceDescriptor


```
struct UsbInterfaceDescriptor UsbDdkInterfaceDescriptor::interfaceDescriptor
```

**描述:**

标准接口描述符。

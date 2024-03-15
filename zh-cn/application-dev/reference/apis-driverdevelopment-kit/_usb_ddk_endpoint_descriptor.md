# UsbDdkEndpointDescriptor


## 概述

端点描述符。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [endpointDescriptor](#endpointdescriptor) | 标准端点描述符。 |
| [extra](#extra) | 未做解析的描述符，包含特定于类或供应商的描述符。 |
| [extraLength](#extralength) | 未做解析的描述符长度。 |


## 结构体成员变量说明


### endpointDescriptor


```
struct UsbEndpointDescriptor UsbDdkEndpointDescriptor::endpointDescriptor
```

**描述:**

标准端点描述符。


### extra


```
const uint8_t* UsbDdkEndpointDescriptor::extra
```

**描述:**

未做解析的描述符，包含特定于类或供应商的描述符。


### extraLength


```
uint32_t UsbDdkEndpointDescriptor::extraLength
```

**描述:**

未做解析的描述符长度。

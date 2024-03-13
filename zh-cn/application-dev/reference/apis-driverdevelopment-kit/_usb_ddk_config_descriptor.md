# UsbDdkConfigDescriptor


## 概述

配置描述符。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [configDescriptor](#configdescriptor) | 标准配置描述符。 |
| [interface](#interface) | 该配置所包含的接口。 |
| [extra](#extra) | 未做解析的描述符，包含特定于类或供应商的描述符。 |
| [extraLength](#extralength) | 未做解析的描述符长度。 |


## 结构体成员变量说明


### configDescriptor


```
struct UsbConfigDescriptor UsbDdkConfigDescriptor::configDescriptor
```

**描述:**

标准配置描述符。


### extra


```
const uint8_t* UsbDdkConfigDescriptor::extra
```

**描述:**

未做解析的描述符，包含特定于类或供应商的描述符。


### extraLength


```
uint32_t UsbDdkConfigDescriptor::extraLength
```

**描述:**

未做解析的描述符长度。


### interface


```
struct UsbDdkInterface* UsbDdkConfigDescriptor::interface
```

**描述:**

该配置所包含的接口。

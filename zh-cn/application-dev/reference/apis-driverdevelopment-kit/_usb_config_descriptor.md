# UsbConfigDescriptor


## 概述

标准配置描述符，对应USB协议中Standard Configuration Descriptor。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [bLength](#blength) | 该描述符的大小，单位为字节。 |
| [bDescriptorType](#bdescriptortype) | 描述符类型。 |
| [wTotalLength](#wtotallength) | 该配置描述符的总长度，包含配置、接口、端点和特定于类或供应商的描述符。 |
| [bNumInterfaces](#bnuminterfaces) | 该配置所支持的接口数量。 |
| [bConfigurationValue](#bconfigurationvalue) | 设置配置所需要的参数，用来选择当前配置。 |
| [iConfiguration](#iconfiguration) | 描述该配置的字符串描述符的索引。 |
| [bmAttributes](#bmattributes) | 配置属性，包含供电模式、远程唤醒等配置。 |
| [bMaxPower](#bmaxpower) | 总线供电的USB设备的最大功耗，以2mA为单位。 |


## 结构体成员变量说明


### bConfigurationValue


```
uint8_t UsbConfigDescriptor::bConfigurationValue
```

**描述:**

设置配置所需要的参数，用来选择当前配置。


### bDescriptorType


```
uint8_t UsbConfigDescriptor::bDescriptorType
```

**描述:**

描述符类型。


### bLength


```
uint8_t UsbConfigDescriptor::bLength
```

**描述:**

该描述符的大小，单位为字节。


### bmAttributes


```
uint8_t UsbConfigDescriptor::bmAttributes
```

**描述:**

配置属性，包含供电模式、远程唤醒等配置。


### bMaxPower


```
uint8_t UsbConfigDescriptor::bMaxPower
```

**描述:**

总线供电的USB设备的最大功耗，以2mA为单位。


### bNumInterfaces


```
uint8_t UsbConfigDescriptor::bNumInterfaces
```

**描述:**

该配置所支持的接口数量。


### iConfiguration


```
uint8_t UsbConfigDescriptor::iConfiguration
```

**描述:**

描述该配置的字符串描述符的索引。


### wTotalLength


```
uint16_t UsbConfigDescriptor::wTotalLength
```

**描述:**

该配置描述符的总长度，包含配置、接口、端点和特定于类或供应商的描述符。

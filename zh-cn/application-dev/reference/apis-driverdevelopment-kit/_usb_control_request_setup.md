# UsbControlRequestSetup


## 概述

控制传输setup包，对应USB协议中的Setup Data。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [bmRequestType](#bmrequesttype) | 请求类型。 |
| [bRequest](#brequest) | 具体的请求，其代表的含义不一样。 |
| [wValue](#wvalue) | 具体的请求不同。 |
| [wIndex](#windex) | 具体的请求不同，其代表的含义不一样，通常用来传递索引或者偏移量。 |
| [wLength](#wlength) | 如果有数据阶段的传输，其代表传输的字节个数。 |


## 结构体成员变量说明


### wIndex


```
uint16_t UsbControlRequestSetup::wIndex
```

**描述:**

具体的请求不同，其代表的含义不一样，通常用来传递索引或者偏移量。


### wLength


```
uint16_t UsbControlRequestSetup::wLength
```

**描述:**

如果有数据阶段的传输，其代表传输的字节个数。


### bRequest


```
uint8_t UsbControlRequestSetup::bRequest
```

**描述:**

具体的请求。


### bmRequestType


```
uint8_t UsbControlRequestSetup::bmRequestType
```

**描述:**

请求类型。


### wValue


```
uint16_t UsbControlRequestSetup::wValue
```

**描述:**

具体的请求不同，其代表的含义不一样。

# UsbRequestPipe


## 概述

请求管道。

**起始版本：**

10

**相关模块:**

[USB DDK](_usb_ddk.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [interfaceHandle](#interfacehandle) | 接口操作句柄。 |
| [endpoint](#endpoint) | 要通信的端点的地址。 |
| [timeout](#timeout) | 超时时间，单位是毫秒。 |


## 结构体成员变量说明


### endpoint


```
uint8_t UsbRequestPipe::endpoint
```

**描述:**

要通信的端点的地址。


### interfaceHandle


```
uint64_t UsbRequestPipe::interfaceHandle
```

**描述:**

接口操作句柄。


### timeout


```
uint32_t UsbRequestPipe::timeout
```

**描述:**

超时时间，单位是毫秒。

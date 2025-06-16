# ArkWeb_WebMessageAPI


## 概述

Post Message数据相关的Native API结构体。在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| size_t size | 结构体的大小。 |


### 成员函数

| 名称                                                                                           | 描述                                                                     |
|----------------------------------------------------------------------------------------------|------------------------------------------------------------------------|
| [ArkWeb_WebMessagePtr (\*createWebMessage)()](#createwebmessage)                             | 创建消息。                                                    |
| [void (\*destroyWebMessage)(ArkWeb_WebMessagePtr* webMessage)](#destroywebmessage)           | 销毁消息。                                        |
| [void (\*setType)(ArkWeb_WebMessagePtr webMessage, ArkWeb_WebMessageType type)](#settype)    | 设置消息类型。                     |
| [ArkWeb_WebMessageType (\*getType)(ArkWeb_WebMessagePtr webMessage)](#gettype)               | 获取消息类型。                         |
| [void (\*setData)(ArkWeb_WebMessagePtr webMessage, void* data, size_t dataLength)](#setdata) | 设置数据。 |
| [void* (*getData)(ArkWeb_WebMessagePtr webMessage, size_t* dataLength)](#getdata)            | 获取数据。                                                                  |

## 成员函数说明

### createWebMessage()

```
ArkWeb_WebMessagePtr (*createWebMessage)()
```

**描述**

创建消息。

**返回：**

| 类型                       | 说明 |
|--------------------------|----|
| [ArkWeb_WebMessagePtr](capi-arkweb-webmessage8h.md) | 消息结构体。   |

### destroyWebMessage()

```
void (*destroyWebMessage)(ArkWeb_WebMessagePtr* webMessage)
```

**描述**

销毁消息。

### setType()

```
void (*setType)(ArkWeb_WebMessagePtr webMessage, ArkWeb_WebMessageType type)
```

**描述**

设置消息类型。@param webMessage 消息结构体指针。@param type 消息类型。

**参数：**

| 参数项                                                                       | 描述 |
|---------------------------------------------------------------------------|----|
| [ArkWeb_WebMessagePtr](capi-arkweb-webmessage8h.md) webMessage            | 消息结构体指针。   |
| [ArkWeb_WebMessageType](capi-arkweb-type-h.md#arkweb_webmessagetype) type | 消息类型。   |

### getType()

```
ArkWeb_WebMessageType (*getType)(ArkWeb_WebMessagePtr webMessage)
```

**描述**

获取消息类型。

**参数：**

| 参数项                                 | 描述 |
|-------------------------------------|----|
| [ArkWeb_WebMessagePtr](capi-arkweb-webmessage8h.md) webMessage | 消息结构体指针。   |

### setData()

```
void (*setData)(ArkWeb_WebMessagePtr webMessage, void* data, size_t dataLength)
```

**描述**

设置数据。

**参数：**

| 参数项                                                            | 描述       |
|----------------------------------------------------------------|----------|
| [ArkWeb_WebMessagePtr](capi-arkweb-webmessage8h.md) webMessage | 消息结构体指针。 |
|  void* data                                                              | 数据指针。         |
|  size_t dataLength                                                              | 数据长度。         |


### getData()

```
void* (*getData)(ArkWeb_WebMessagePtr webMessage, size_t* dataLength)
```

**描述**

获取数据。

**参数：**

| 参数项                  | 描述       |
|----------------------|----------|
| [ArkWeb_WebMessagePtr](capi-arkweb-webmessage8h.md) webMessage | 消息结构体指针。 |
| size_t* dataLength   | 出参，数据长度。         |

**返回：**

| 类型 | 说明    |
|----|-------|
| void*   | 数据指针。 |
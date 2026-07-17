# ArkWeb_WebMessageAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_WebMessageAPI
```

## 概述

ArkWeb_WebMessageAPI是Web消息相关Native API结构体。该结构体提供了创建和销毁消息、设置和获取消息类型、管理消息数据缓冲区等函数。此API是postMessage桥接的一部分，支持Native代码与HTML页面之间的双向通信。

Web消息相关接口需在UI线程中调用OH_ArkWeb_GetNativeAPI方法获取，调用前建议通过[ARKWEB_MEMBER_MISSING](capi-arkweb-type-h.md#宏定义)校验函数指针的可用性，避免SDK与设备ROM不匹配导致崩溃。

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
| [void* (\*getData)(ArkWeb_WebMessagePtr webMessage, size_t* dataLength)](#getdata)           | 获取数据。                         |

## 成员函数说明

### createWebMessage()

```c
ArkWeb_WebMessagePtr (*createWebMessage)()
```

**描述**

创建消息。用于在Native代码与HTML页面之间进行postMessage通信前，创建待发送的消息对象。调用createWebMessage()后，必须在使用完毕后调用destroyWebMessage()释放消息资源，未调用destroyWebMessage()会导致消息资源泄漏，影响系统内存管理。

**返回：**

| 类型                       | 说明 |
|--------------------------|----|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) | 消息结构体指针。   |

### destroyWebMessage()

```c
void (*destroyWebMessage)(ArkWeb_WebMessagePtr* webMessage)
```

**描述**

销毁消息，并释放消息对象占用的内存。必须与createWebMessage()成对使用，在使用完消息后调用此方法释放资源。调用后webMessage指针将变为无效，不应再被使用。

**参数：**

| 参数项                                                                       | 描述 |
|---------------------------------------------------------------------------|----|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md)* webMessage            | 需要销毁的消息。   |

### setType()

```c
void (*setType)(ArkWeb_WebMessagePtr webMessage, ArkWeb_WebMessageType type)
```

**描述**

设置消息类型。

**参数：**

| 参数项                                                                       | 描述 |
|---------------------------------------------------------------------------|----|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage            | 消息结构体指针。   |
| [ArkWeb_WebMessageType](capi-arkweb-type-h.md#arkweb_webmessagetype) type | 消息类型。   |

### getType()

```c
ArkWeb_WebMessageType (*getType)(ArkWeb_WebMessagePtr webMessage)
```

**描述**

获取消息类型。用于区分不同类型的通信消息，如文本消息、JSON消息、二进制消息等。

**参数：**

| 参数项                                 | 描述 |
|-------------------------------------|----|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage | 消息结构体指针。   |

**返回：**

| 类型 | 说明    |
|----|-------|
| [ArkWeb_WebMessageType](capi-arkweb-type-h.md#arkweb_webmessagetype)   | 返回消息的类型枚举值，如ARKWEB_WEB_MESSAGE_TYPE_STRING或ARKWEB_WEB_MESSAGE_TYPE_ARRAY_BUFFER等。   |

### setData()

```c
void (*setData)(ArkWeb_WebMessagePtr webMessage, void* data, size_t dataLength)
```

**描述**

设置数据。用于设置消息的具体内容，支持从Native代码向HTML页面传递文本、JSON或二进制数据。

**参数：**

| 参数项                                                            | 描述       |
|----------------------------------------------------------------|----------|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage | 消息结构体指针。 |
|  void* data                                                              | 数据指针。由调用方负责内存管理，函数内部不释放该内存，数据所有权不转移。         |
|  size_t dataLength                                                              | 数据长度。         |


### getData()

```c
void* (*getData)(ArkWeb_WebMessagePtr webMessage, size_t* dataLength)
```

**描述**

获取数据。用于获取消息的具体内容，支持从HTML页面接收文本、JSON或二进制数据并在Native代码中处理。

**调用顺序：**
- 必须先调用setData()设置数据，然后才能调用getData()获取数据。
- 如果未调用setData()就调用getData()，将返回NULL，且dataLength为0。

**参数：**

| 参数项                  | 描述       |
|----------------------|----------|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage | 消息结构体指针。 |
| size_t* dataLength   | 出参，数据长度。         |

**返回：**

| 类型 | 说明    |
|----|-------|
| void*   | 指向消息数据的指针，数据长度由dataLength出参返回。返回指针的生命周期与消息对象绑定，消息销毁后指针失效，调用方不应释放该内存。 |
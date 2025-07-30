# ArkWeb_WebMessageAPI


## Overview

Defines a native API for the post message. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| size_t size | Size of the struct.|


### Member Functions

| Name                                                                                          | Description                                                                    |
|----------------------------------------------------------------------------------------------|------------------------------------------------------------------------|
| [ArkWeb_WebMessagePtr (\*createWebMessage)()](#createwebmessage)                             | Creates a message.                                                   |
| [void (\*destroyWebMessage)(ArkWeb_WebMessagePtr* webMessage)](#destroywebmessage)           | Destroys a message.                                       |
| [void (\*setType)(ArkWeb_WebMessagePtr webMessage, ArkWeb_WebMessageType type)](#settype)    | Sets the message type.                    |
| [ArkWeb_WebMessageType (\*getType)(ArkWeb_WebMessagePtr webMessage)](#gettype)               | Obtains the message type.                        |
| [void (\*setData)(ArkWeb_WebMessagePtr webMessage, void* data, size_t dataLength)](#setdata) | Sets data.|
| [void* (*getData)(ArkWeb_WebMessagePtr webMessage, size_t* dataLength)](#getdata)            | Obtains data.                                                                 |

## Member Function Description

### createWebMessage()

```
ArkWeb_WebMessagePtr (*createWebMessage)()
```

**Description**

Creates a message.

**Returns**

| Type                      | Description|
|--------------------------|----|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) | Message struct.  |

### destroyWebMessage()

```
void (*destroyWebMessage)(ArkWeb_WebMessagePtr* webMessage)
```

**Description**

Destroys a message.

### setType()

```
void (*setType)(ArkWeb_WebMessagePtr webMessage, ArkWeb_WebMessageType type)
```

**Description**

Sets the message type. @param webMessage Pointer to the message struct. @param type Message type.

**Parameters**

| Name                                                                      | Description|
|---------------------------------------------------------------------------|----|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage            | Pointer to the message struct.  |
| [ArkWeb_WebMessageType](capi-arkweb-type-h.md#arkweb_webmessagetype) type | Message type.  |

### getType()

```
ArkWeb_WebMessageType (*getType)(ArkWeb_WebMessagePtr webMessage)
```

**Description**

Obtains the message type.

**Parameters**

| Name                                | Description|
|-------------------------------------|----|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage | Pointer to the message struct.  |

### setData()

```
void (*setData)(ArkWeb_WebMessagePtr webMessage, void* data, size_t dataLength)
```

**Description**

Sets data.

**Parameters**

| Name                                                           | Description      |
|----------------------------------------------------------------|----------|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage | Pointer to the message struct.|
|  void* data                                                              | Pointer to the data.        |
|  size_t dataLength                                                              | Data length.        |


### getData()

```
void* (*getData)(ArkWeb_WebMessagePtr webMessage, size_t* dataLength)
```

**Description**

Obtains data.

**Parameters**

| Name                 | Description      |
|----------------------|----------|
| [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage | Pointer to the message struct.|
| size_t* dataLength   | Data length, which is an output parameter.        |

**Returns**

| Type| Description   |
|----|-------|
| void*   | Pointer to the data.|

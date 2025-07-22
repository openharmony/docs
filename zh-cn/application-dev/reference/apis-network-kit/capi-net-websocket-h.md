# net_websocket.h

## 概述

定义websocket客户端模块的接口。

**引用文件：** <network/netstack/net_websocket.h>

**库：** libnet_websocket.so

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**相关模块：** [netstack](capi-netstack.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [struct WebSocket *OH_WebSocketClient_Constructor(WebSocket_OnOpenCallback onOpen, WebSocket_OnMessageCallback onMessage,WebSocket_OnErrorCallback onError, WebSocket_OnCloseCallback onclose)](#oh_websocketclient_constructor) | websocket客户端的构造函数。 |
| [int OH_WebSocketClient_AddHeader(struct WebSocket *client, struct WebSocket_Header header)](#oh_websocketclient_addheader) | 将header头信息添加到client客户端request中。 |
| [int OH_WebSocketClient_Connect(struct WebSocket *client, const char *url, struct WebSocket_RequestOptions options)](#oh_websocketclient_connect) | 客户端连接服务端。 |
| [int OH_WebSocketClient_Send(struct WebSocket *client, char *data, size_t length)](#oh_websocketclient_send) | 客户端向服务端发送数据。 |
| [int OH_WebSocketClient_Close(struct WebSocket *client, struct WebSocket_CloseOption options)](#oh_websocketclient_close) | 客户端主动关闭webSocket连接。 |
| [int OH_WebSocketClient_Destroy(struct WebSocket *client)](#oh_websocketclient_destroy) | 释放websocket连接上下文和资源。 |

## 函数说明

### OH_WebSocketClient_Constructor()

```
struct WebSocket *OH_WebSocketClient_Constructor(WebSocket_OnOpenCallback onOpen, WebSocket_OnMessageCallback onMessage,WebSocket_OnErrorCallback onError, WebSocket_OnCloseCallback onclose)
```

**描述**

websocket客户端的构造函数。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [WebSocket_OnOpenCallback](capi-net-websocket-type-h.md#websocket_onopencallback) onOpen |    客户端定义的建立连接消息的回调函数。 |
| [WebSocket_OnMessageCallback](capi-net-websocket-type-h.md#websocket_onmessagecallback) onMessage | 客户端定义的接收消息的回调函数。 |
| [WebSocket_OnErrorCallback](capi-net-websocket-type-h.md#websocket_onerrorcallback) onError |   客户端定义的错误消息的回调函数。 |
| [WebSocket_OnCloseCallback](capi-net-websocket-type-h.md#websocket_onclosecallback) onclose |   客户端定义的关闭消息的回调函数。 |

**返回：**

| 类型                     | 说明 |
|------------------------| -- |
| [struct WebSocket](capi-netstack-websocket.md) * | 成功返回客户端指针，失败返回为NULL。 |

### OH_WebSocketClient_AddHeader()

```
int OH_WebSocketClient_AddHeader(struct WebSocket *client, struct WebSocket_Header header)
```

**描述**

将header头信息添加到client客户端request中。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | 客户端指针。 |
| [struct WebSocket_Header](capi-netstack-websocket-header.md) header | Header头信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回值为0表示执行成功，返回值不为0表示失败。返回值详细信息可以查看OH_Websocket_ErrCode。 |

### OH_WebSocketClient_Connect()

```
int OH_WebSocketClient_Connect(struct WebSocket *client, const char *url, struct WebSocket_RequestOptions options)
```

**描述**

客户端连接服务端。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | 客户端指针。 |
| const char *url | 客户端要连接到服务端的地址。 |
| [struct WebSocket_RequestOptions](capi-netstack-websocket-requestoptions.md) options | 发起连接的可选参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回值为0表示执行成功，返回值不为0表示失败。返回值详细信息可以查看OH_Websocket_ErrCode。 |

### OH_WebSocketClient_Send()

```
int OH_WebSocketClient_Send(struct WebSocket *client, char *data, size_t length)
```

**描述**

客户端向服务端发送数据。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | 客户端。 |
| char *data |   客户端发送的数据。 |
| size_t length | 客户端发送的数据长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回值为0表示执行成功，返回值不为0表示失败。返回值详细信息可以查看OH_Websocket_ErrCode。 |

### OH_WebSocketClient_Close()

```
int OH_WebSocketClient_Close(struct WebSocket *client, struct WebSocket_CloseOption options)
```

**描述**

客户端主动关闭webSocket连接。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | 客户端。 |
| [struct WebSocket_CloseOption](capi-netstack-websocket-closeoption.md) options | 发起关闭连接的可选参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回值为0表示执行成功，返回值不为0表示失败。返回值详细信息可以查看OH_Websocket_ErrCode。 |

### OH_WebSocketClient_Destroy()

```
int OH_WebSocketClient_Destroy(struct WebSocket *client)
```

**描述**

释放websocket连接上下文和资源。

**系统能力：** SystemCapability.Communication.NetStack

**需要权限：** ohos.permission.INTERNET

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | 客户端。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回值为0表示执行成功，返回值不为0表示失败。返回值详细信息可以查看OH_Websocket_ErrCode。 |


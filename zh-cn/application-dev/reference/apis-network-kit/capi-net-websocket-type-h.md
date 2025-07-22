# net_websocket_type.h

## 概述

定义websocket客户端模块的C接口需要的数据结构。

**引用文件：** <network/netstack/net_websocket_type.h>

**库：** libnet_websocket.so

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**相关模块：** [netstack](capi-netstack.md)

## 汇总

### 结构体

| 名称 | 描述 |
| -- | -- |
| [WebSocket_CloseResult](capi-netstack-websocket-closeresult.md) | websocket客户端来自服务端关闭的参数。 |
| [WebSocket_CloseOption](capi-netstack-websocket-closeoption.md) | websocket客户端主动关闭的参数。 |
| [WebSocket_ErrorResult](capi-netstack-websocket-errorresult.md) | websocket客户端来自服务端连接错误的参数。 |
| [WebSocket_OpenResult](capi-netstack-websocket-openresult.md) | websocket客户端来自服务端连接成功的参数。 |
| [WebSocket_Header](capi-netstack-websocket-header.md) | websocket客户端增加header头的链表节点。 |
| [WebSocket_RequestOptions](capi-netstack-websocket-requestoptions.md) | webSocket客户端和服务端建立连接的参数。 |
| [WebSocket](capi-netstack-websocket.md) | webSocket客户端结构体。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*WebSocket_OnOpenCallback)(struct WebSocket *client, WebSocket_OpenResult openResult)](#websocket_onopencallback) | WebSocket_OnOpenCallback | websocket客户端接收open消息的回调函数定义。 |
| [typedef void (\*WebSocket_OnMessageCallback)(struct WebSocket *client, char *data, uint32_t length)](#websocket_onmessagecallback) | WebSocket_OnMessageCallback | websocket客户端接收数据的回调函数定义。 |
| [typedef void (\*WebSocket_OnErrorCallback)(struct WebSocket *client, WebSocket_ErrorResult errorResult)](#websocket_onerrorcallback) | WebSocket_OnErrorCallback | websocket客户端接收error错误消息的回调函数定义。 |
| [typedef void (\*WebSocket_OnCloseCallback)(struct WebSocket *client, WebSocket_CloseResult closeResult)](#websocket_onclosecallback) | WebSocket_OnCloseCallback | webSocket客户端接收close消息的回调函数定义。 |


## 函数说明

### WebSocket_OnOpenCallback()

```
typedef void (*WebSocket_OnOpenCallback)(struct WebSocket *client, WebSocket_OpenResult openResult)
```

**描述**

websocket客户端接收open消息的回调函数定义。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | websocket客户端。 |
| [ WebSocket_OpenResult](capi-netstack-websocket-openresult.md) openResult |   websocket客户端接收建立连接消息的内容。 |

### WebSocket_OnMessageCallback()

```
typedef void (*WebSocket_OnMessageCallback)(struct WebSocket *client, char *data, uint32_t length)
```

**描述**

websocket客户端接收数据的回调函数定义。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | websocket客户端。 |
|  char *data |   websocket客户端接收的数据。 |
|  uint32_t length | websocket客户端接收的数据长度。 |

### WebSocket_OnErrorCallback()

```
typedef void (*WebSocket_OnErrorCallback)(struct WebSocket *client, WebSocket_ErrorResult errorResult)
```

**描述**

websocket客户端接收error错误消息的回调函数定义。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | websocket客户端。 |
| [ WebSocket_ErrorResult](capi-netstack-websocket-errorresult.md) errorResult |   websocket客户端接收连接错误消息的内容。 |

### WebSocket_OnCloseCallback()

```
typedef void (*WebSocket_OnCloseCallback)(struct WebSocket *client, WebSocket_CloseResult closeResult)
```

**描述**

webSocket客户端接收close消息的回调函数定义。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | websocket客户端。 |
| [ WebSocket_CloseResult](capi-netstack-websocket-closeresult.md) closeResult |   webSocket客户端接收关闭消息的内容。 |


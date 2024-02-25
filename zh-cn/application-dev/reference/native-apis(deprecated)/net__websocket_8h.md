# net_websocket.h


## 概述

为websocket客户端模块定义C接口。

**库：** libnet_websocket.so

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**相关模块：**[Netstack](netstack.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_WebSocketClient_Constructor](netstack.md#oh_websocketclient_constructor) ([WebSocket_OnOpenCallback](netstack.md#websocket_onopencallback) onOpen, [WebSocket_OnMessageCallback](netstack.md#websocket_onmessagecallback) onMessage, [WebSocket_OnErrorCallback](netstack.md#websocket_onerrorcallback) onError, [WebSocket_OnCloseCallback](netstack.md#websocket_onclosecallback) onclose) | Client客户端的构造函数。  | 
| [OH_WebSocketClient_AddHeader](netstack.md#oh_websocketclient_addheader) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_Header](_web_socket___header.md) header) | 将header头信息添加到client客户端request中。  | 
| [OH_WebSocketClient_Connect](netstack.md#oh_websocketclient_connect) (struct [WebSocket](_web_socket.md) \*client, const char \*url, struct [WebSocket_RequestOptions](_web_socket___request_options.md) options) | 客户端连接服务端。  | 
| [OH_WebSocketClient_Send](netstack.md#oh_websocketclient_send) (struct [WebSocket](_web_socket.md) \*client, char \*data, size_t length) | 客户端向服务端发送数据。  | 
| [OH_WebSocketClient_Close](netstack.md#oh_websocketclient_close) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_CloseOption](_web_socket___close_option.md) options) | 客户端主动关闭websocket连接。  | 
| [OH_WebSocketClient_Destroy](netstack.md#oh_websocketclient_destroy) (struct [WebSocket](_web_socket.md) \*client) | 释放websocket连接上下文和资源。  | 
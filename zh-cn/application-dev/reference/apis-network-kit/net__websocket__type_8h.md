# net_websocket_type.h


## 概述

定义websocket客户端模块的C接口需要的数据结构。

**库：** libnet_websocket.so

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**相关模块：**[Netstack](netstack.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [WebSocket_CloseResult](_web_socket___close_result.md) | websocket客户端来自服务端关闭的参数。  | 
| [WebSocket_CloseOption](_web_socket___close_option.md) | websocket客户端主动关闭的参数。  | 
| [WebSocket_ErrorResult](_web_socket___error_result.md) | websocket客户端来自服务端连接错误的参数。  | 
| [WebSocket_OpenResult](_web_socket___open_result.md) | websocket客户端来自服务端连接成功的参数。  | 
| [WebSocket_Header](_web_socket___header.md) | websocket客户端增加header头的链表节点。  | 
| [WebSocket_RequestOptions](_web_socket___request_options.md) | websocket客户端和服务端建立连接的参数。  | 
| [WebSocket](_web_socket.md) | websocket客户端结构体。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| (\* [WebSocket_OnOpenCallback](netstack.md#websocket_onopencallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_OpenResult](_web_socket___open_result.md) openResult) | websocket客户端接收open消息的回调函数定义。  | 
| (\* [WebSocket_OnMessageCallback](netstack.md#websocket_onmessagecallback)) (struct [WebSocket](_web_socket.md) \*client, char \*data, uint32_t length) | websocket客户端接收数据的回调函数定义。  | 
| (\* [WebSocket_OnErrorCallback](netstack.md#websocket_onerrorcallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_ErrorResult](_web_socket___error_result.md) errorResult) | websocket客户端接收error错误消息的回调函数定义。  | 
| (\* [WebSocket_OnCloseCallback](netstack.md#websocket_onclosecallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_CloseResult](_web_socket___close_result.md) closeResult) | websocket客户端接收close消息的回调函数定义。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [WebSocket_ErrCode](netstack.md#websocket_errcode) {<br/>[WEBSOCKET_OK](netstack.md) = 0, <br/>[E_BASE](netstack.md) = 1000, <br/>[WEBSOCKET_CLIENT_NULL](netstack.md) = (E_BASE + 1), <br/>[WEBSOCKET_CLIENT_NOT_CREATED](netstack.md) = (E_BASE + 2),<br/>[WEBSOCKET_CONNECTION_ERROR](netstack.md) = (E_BASE + 3), <br/>[WEBSOCKET_CONNECTION_PARSE_URL_ERROR](netstack.md) = (E_BASE + 5), <br/>[WEBSOCKET_CONNECTION_NO_MEMORY](netstack.md) = (E_BASE + 6), <br/>[WEBSOCKET_CONNECTION_CLOSED_BY_PEER](netstack.md) = (E_BASE + 7),<br/>[WEBSOCKET_DESTROYED](netstack.md) = (E_BASE + 8), <br/>[WEBSOCKET_PROTOCOL_ERROR](netstack.md) = (E_BASE + 9),<br/> [WEBSOCKET_SEND_NO_MEMORY](netstack.md) = (E_BASE + 10), <br/>[WEBSOCKET_SEND_DATA_NULL](netstack.md) = (E_BASE + 11),<br/>[WEBSOCKET_DATA_LENGTH_EXCEEDED](netstack.md) = (E_BASE + 12), <br/>[WEBSOCKET_QUEUE_LENGTH_EXCEEDED](netstack.md) = (E_BASE + 13), <br/>[WEBSOCKET_NO_CLIENT_CONTEXT](netstack.md) = (E_BASE + 14), <br/>[WEBSOCKET_NO_HEADER_CONTEXT](netstack.md) = (E_BASE + 15),<br/>[WEBSOCKET_HEADER_EXCEEDED](netstack.md) = (E_BASE + 16), <br/>[WEBSOCKET_NO_CONNECTION](netstack.md) = (E_BASE + 17), <br/>[WEBSOCKET_NO_CONNECTION_CONTEXT](netstack.md) = (E_BASE + 18)<br/>} | websocket错误码。  | 
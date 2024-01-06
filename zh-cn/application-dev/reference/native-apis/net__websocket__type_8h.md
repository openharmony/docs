# net_websocket_type.h


## 概述

定义websocket客户端模块的C接口需要的数据结构。

**库：** libnet_websocket.so

**系统能力：** SystemCapability.Communication.Netstack

**起始版本：** 11

**相关模块：**[Netstack](netstack.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NetStack_WebsocketClient_CloseResult](_o_h___net_stack___websocket_client___close_result.md) | websocket客户端来自服务端关闭的参数。 | 
| [OH_NetStack_WebsocketClient_CloseOption](_o_h___net_stack___websocket_client___close_option.md) | websocket客户端主动关闭的参数。 | 
| [OH_NetStack_WebsocketClient_ErrorResult](_o_h___net_stack___websocket_client___error_result.md) | websocket客户端来自服务端连接错误的参数。 | 
| [OH_NetStack_WebsocketClient_OpenResult](_o_h___net_stack___websocket_client___open_result.md) | websocket客户端来自服务端连接成功的参数。 | 
| [OH_NetStack_WebsocketClient_Slist](_o_h___net_stack___websocket_client___slist.md) | websocket客户端增加header头的链表节点。 | 
| [OH_NetStack_WebsocketClient_RequestOptions](h___net_stack___websocket_client___request_options.md) | websocket客户端和服务端建立连接的参数。 | 
| [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) | websocket客户端结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_NetStack_WebsocketClient_OnOpenCallback](netstack.md#oh_netstack_websocketclient_onopencallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, [OH_NetStack_WebsocketClient_OpenResult](_o_h___net_stack___websocket_client___open_result.md) openResult) | websocket客户端接收open消息的回调函数定义。 | 
| (\*[OH_NetStack_WebsocketClient_OnMessageCallback](netstack.md#oh_netstack_websocketclient_onmessagecallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, char \*data, uint32_t length) | websocket客户端接收数据的回调函数定义。 | 
| (\*[OH_NetStack_WebsocketClient_OnErrorCallback](netstack.md#oh_netstack_websocketclient_onerrorcallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, [OH_NetStack_WebsocketClient_ErrorResult](_o_h___net_stack___websocket_client___error_result.md) errorResult) | websocket客户端接收error错误消息的回调函数定义。 | 
| (\*[OH_NetStack_WebsocketClient_OnCloseCallback](netstack.md#oh_netstack_websocketclient_onclosecallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, [OH_NetStack_WebsocketClient_CloseResult](_o_h___net_stack___websocket_client___close_result.md) closeResult) | websocket客户端接收close消息的回调函数定义。 | 



### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Websocket_ErrCode](netstack.md#oh_websocket_errcode) {<br/>[Websocket_OK](netstack.md) = 0,<br/> [E_BASE](netstack.md) = 1000, <br/>[WEBSOCKET_CLIENT_IS_NULL](netstack.md) = (E_BASE + 1), <br/>[WEBSOCKET_CLIENT_IS_NOT_CREAT](netstack.md) = (E_BASE + 2),<br/>[WEBSOCKET_CONNECTION_ERROR](netstack.md) = (E_BASE + 3), <br/>[WEBSOCKET_CONNECTION_PARSEURL_ERROR](netstack.md) = (E_BASE + 5), <br/>[WEBSOCKET_CONNECTION_NO_MEMOERY](netstack.md) = (E_BASE + 6), <br/>[WEBSOCKET_PEER_INITIATED_CLOSE](netstack.md) = (E_BASE + 7),<br/>[WEBSOCKET_DESTROY](netstack.md) = (E_BASE + 8), <br/>[WEBSOCKET_PROTOCOL_ERROR](netstack.md) = (E_BASE + 9), <br/>[WEBSOCKET_SEND_NO_MEMOERY_ERROR](netstack.md) = (E_BASE + 10), <br/>[WEBSOCKET_SEND_DATA_NULL](netstack.md) = (E_BASE + 11),<br/>[WEBSOCKET_DATA_LENGTH_EXCEEDS](netstack.md) = (E_BASE + 12), <br/>[WEBSOCKET_QUEUE_LENGTH_EXCEEDS](netstack.md) = (E_BASE + 13), <br/>[WEBSOCKET_ERROR_NO_CLIENTCONTEX](netstack.md) = (E_BASE + 14), <br/>[WEBSOCKET_ERROR_NO_HEADR_CONTEXT](netstack.md) = (E_BASE + 15),<br/>[WEBSOCKET_ERROR_NO_HEADR_EXCEEDS](netstack.md) = (E_BASE + 16), <br/>[WEBSOCKET_ERROR_HAVE_NO_CONNECT](netstack.md) = (E_BASE + 17), <br/>[WEBSOCKET_ERROR_HAVE_NO_CONNECT_CONTEXT](netstack.md) = (E_BASE + 18)<br/>} | 错误码枚举。 | 

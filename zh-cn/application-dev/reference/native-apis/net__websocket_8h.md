# net_websocket.h


## 概述

为websocket客户端模块定义C接口。

**库：** libnet_websocket.so

**系统能力：** SystemCapability.Communication.Netstack

**起始版本：** 11

**相关模块：**[Netstack](netstack.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NetStack_WebsocketClient_Construct](netstack.md#oh_netstack_websocketclient_construct) ([OH_NetStack_WebsocketClient_OnOpenCallback](netstack.md#oh_netstack_websocketclient_onopencallback) OnOpen, [OH_NetStack_WebsocketClient_OnMessageCallback](netstack.md#oh_netstack_websocketclient_onmessagecallback) onMessage, [OH_NetStack_WebsocketClient_OnErrorCallback](netstack.md#oh_netstack_websocketclient_onerrorcallback) OnError, [OH_NetStack_WebsocketClient_OnCloseCallback](netstack.md#oh_netstack_websocketclient_onclosecallback) onclose) | OH_NetStack_WebsocketClient客户端的构造函数。 | 
| [OH_NetStack_WebSocketClient_AddHeader](netstack.md#oh_netstack_websocketclient_addheader) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, struct [OH_NetStack_WebsocketClient_Slist](_o_h___net_stack___websocket_client___slist.md) header) | 将header头信息添加到client客户端request中。 | 
| [OH_NetStack_WebSocketClient_Connet](netstack.md#oh_netstack_websocketclient_connet) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, const char \*url, struct [OH_NetStack_WebsocketClient_RequestOptions](h___net_stack___websocket_client___request_options.md) options) | 客户端连接服务端。 | 
| [OH_NetStack_WebSocketClient_Send](netstack.md#oh_netstack_websocketclient_send) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, char \*data, size_t length) | 客户端向服务端发送数据。 | 
| [OH_NetStack_WebSocketClient_Close](netstack.md#oh_netstack_websocketclient_close) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, struct [OH_NetStack_WebsocketClient_CloseOption](_o_h___net_stack___websocket_client___close_option.md) options) | 客户端主动关闭websocket连接。 | 
| [OH_NetStack_WebsocketClient_Destroy](netstack.md#oh_netstack_websocketclient_destroy) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client) | 释放websocket连接上下文和资源。 | 

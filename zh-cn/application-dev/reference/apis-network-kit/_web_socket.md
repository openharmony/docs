# WebSocket


## 概述

websocket客户端结构体。

**起始版本：** 11

**相关模块：**[Netstack](netstack.md)

**所在头文件：** [net_websocket_type.h](net__websocket__type_8h.md#net_websocket_typeh)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [WebSocket_OnOpenCallback](netstack.md#websocket_onopencallback) [onOpen](netstack.md#onopen) |客户端接收连接消息的回调指针。 | 
| [WebSocket_OnMessageCallback](netstack.md#websocket_onmessagecallback) [onMessage](netstack.md#onmessage) | 客户端接收消息的回调指针。 | 
| [WebSocket_OnErrorCallback](netstack.md#websocket_onerrorcallback) [onError](netstack.md#onerror) | 客户端接收错误消息的回调指针。 | 
| [WebSocket_OnCloseCallback](netstack.md#websocket_onclosecallback) [onClose](netstack.md#onclose) | 客户端接收关闭消息的回调指针。 | 
| [WebSocket_RequestOptions](_web_socket___request_options.md) [requestOptions](netstack.md#requestoptions) |客户端建立连接请求内容。 | 

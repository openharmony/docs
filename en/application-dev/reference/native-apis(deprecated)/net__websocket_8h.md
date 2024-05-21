# net_websocket.h


## Overview

Defines C APIs for the WebSocket client module.

**Library**: libnet_websocket.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [Netstack](netstack.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_WebSocketClient_Constructor](netstack.md#oh_websocketclient_constructor) ([WebSocket_OnOpenCallback](netstack.md#websocket_onopencallback) onOpen, [WebSocket_OnMessageCallback](netstack.md#websocket_onmessagecallback) onMessage, [WebSocket_OnErrorCallback](netstack.md#websocket_onerrorcallback) onError, [WebSocket_OnCloseCallback](netstack.md#websocket_onclosecallback) onclose) | Constructor used to create a **WebSocketClient** instance. | 
| [OH_WebSocketClient_AddHeader](netstack.md#oh_websocketclient_addheader) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_Header](_web_socket___header.md) header) | Adds the header information to the client request. | 
| [OH_WebSocketClient_Connect](netstack.md#oh_websocketclient_connect) (struct [WebSocket](_web_socket.md) \*client, const char \*url, struct [WebSocket_RequestOptions](_web_socket___request_options.md) options) | Connects the WebSocket client to the server. | 
| [OH_WebSocketClient_Send](netstack.md#oh_websocketclient_send) (struct [WebSocket](_web_socket.md) \*client, char \*data, size_t length) | Sends data from the WebSocket client to the server. | 
| [OH_WebSocketClient_Close](netstack.md#oh_websocketclient_close) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_CloseOption](_web_socket___close_option.md) options) | Lets the WebSocket client proactively close the connection. | 
| [OH_WebSocketClient_Destroy](netstack.md#oh_websocketclient_destroy) (struct [WebSocket](_web_socket.md) \*client) | Releases the context and resources of the WebSocket connection. | 

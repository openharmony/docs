# WebSocket


## Overview

Defines the WebSocket client structure.

**Since**: 11

**Related module**: [Netstack](netstack.md)

**Header file**: [net_websocket_type.h](net__websocket__type_8h.md#net_websocket_typeh)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [WebSocket_OnOpenCallback](netstack.md#websocket_onopencallback) [onOpen](netstack.md#onopen) |Pointer to the callback invoked when the WebSocket client receives a connection message.| 
| [WebSocket_OnMessageCallback](netstack.md#websocket_onmessagecallback) [onMessage](netstack.md#onmessage) | Pointer to the callback invoked when the WebSocket client receives a message.| 
| [WebSocket_OnErrorCallback](netstack.md#websocket_onerrorcallback) [onError](netstack.md#onerror) | Pointer to the callback invoked when the WebSocket client receives an error message.| 
| [WebSocket_OnCloseCallback](netstack.md#websocket_onclosecallback) [onClose](netstack.md#onclose) | Pointer to the callback invoked when the WebSocket client receives a **close** message.| 
| [WebSocket_RequestOptions](_web_socket___request_options.md) [requestOptions](netstack.md#requestoptions) |Options of the connection request.| 

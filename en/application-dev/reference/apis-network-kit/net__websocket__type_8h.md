# net_websocket_type.h


## Overview

Defines data structures for the C APIs of the WebSocket client module.

**Library**: libnet_websocket.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [Netstack](netstack.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [WebSocket_CloseResult](_web_socket___close_result.md) | Parameters for connection closure by the server. | 
| [WebSocket_CloseOption](_web_socket___close_option.md) | Parameters for proactive connection closure by the client. | 
| [WebSocket_ErrorResult](_web_socket___error_result.md) | Parameters for the connection error reported by the server. | 
| [WebSocket_OpenResult](_web_socket___open_result.md) | Parameters for the connection success reported by the server. | 
| [WebSocket_Header](_web_socket___header.md) | Header linked list added to the WebSocket client. | 
| [WebSocket_RequestOptions](_web_socket___request_options.md) | Parameters for the connection between the WebSocket client and server. | 
| [WebSocket](_web_socket.md) | WebSocket client structure. | 


### Types

| Name| Description| 
| -------- | -------- |
| (\* [WebSocket_OnOpenCallback](netstack.md#websocket_onopencallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_OpenResult](_web_socket___open_result.md) openResult) | Callback invoked when the WebSocket client receives an **open** message. | 
| (\* [WebSocket_OnMessageCallback](netstack.md#websocket_onmessagecallback)) (struct [WebSocket](_web_socket.md) \*client, char \*data, uint32_t length) | Callback invoked when the WebSocket client receives data. | 
| (\* [WebSocket_OnErrorCallback](netstack.md#websocket_onerrorcallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_ErrorResult](_web_socket___error_result.md) errorResult) | Callback invoked when the WebSocket client receives an error message. | 
| (\* [WebSocket_OnCloseCallback](netstack.md#websocket_onclosecallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_CloseResult](_web_socket___close_result.md) closeResult) | Callback invoked when the WebSocket client receives a **close** message. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [WebSocket_ErrCode](netstack.md#websocket_errcode) {<br>[WEBSOCKET_OK](netstack.md) = 0, <br>[E_BASE](netstack.md) = 1000, <br>[WEBSOCKET_CLIENT_NULL](netstack.md) = (E_BASE + 1), <br>[WEBSOCKET_CLIENT_NOT_CREATED](netstack.md) = (E_BASE + 2),<br>[WEBSOCKET_CONNECTION_ERROR](netstack.md) = (E_BASE + 3), <br>[WEBSOCKET_CONNECTION_PARSE_URL_ERROR](netstack.md) = (E_BASE + 5), <br>[WEBSOCKET_CONNECTION_NO_MEMORY](netstack.md) = (E_BASE + 6), <br>[WEBSOCKET_CONNECTION_CLOSED_BY_PEER](netstack.md) = (E_BASE + 7),<br>[WEBSOCKET_DESTROYED](netstack.md) = (E_BASE + 8), <br>[WEBSOCKET_PROTOCOL_ERROR](netstack.md) = (E_BASE + 9),<br> [WEBSOCKET_SEND_NO_MEMORY](netstack.md) = (E_BASE + 10), <br>[WEBSOCKET_SEND_DATA_NULL](netstack.md) = (E_BASE + 11),<br>[WEBSOCKET_DATA_LENGTH_EXCEEDED](netstack.md) = (E_BASE + 12), <br>[WEBSOCKET_QUEUE_LENGTH_EXCEEDED](netstack.md) = (E_BASE + 13), <br>[WEBSOCKET_NO_CLIENT_CONTEXT](netstack.md) = (E_BASE + 14), <br>[WEBSOCKET_NO_HEADER_CONTEXT](netstack.md) = (E_BASE + 15),<br>[WEBSOCKET_HEADER_EXCEEDED](netstack.md) = (E_BASE + 16), <br>[WEBSOCKET_NO_CONNECTION](netstack.md) = (E_BASE + 17), <br>[WEBSOCKET_NO_CONNECTION_CONTEXT](netstack.md) = (E_BASE + 18)<br>} | WebSocket error codes. | 

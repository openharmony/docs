# WebSocket

## Overview

Defines the WebSocket client structure.

**Since**: 11

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_websocket_type.h](capi-net-websocket-type-h.md)

## Summary

### Member Variables

| Name                                                                                               | Description|
|---------------------------------------------------------------------------------------------------| -- |
| [WebSocket_OnOpenCallback](capi-net-websocket-type-h.md#websocket_onopencallback) onOpen          | Pointer to the callback invoked when the WebSocket client receives a connection message.|
| [WebSocket_OnMessageCallback](capi-net-websocket-type-h.md#websocket_onmessagecallback) onMessage | Pointer to the callback invoked when the WebSocket client receives a message.|
| [WebSocket_OnErrorCallback](capi-net-websocket-type-h.md#websocket_onerrorcallback) onError       | Pointer to the callback invoked when the WebSocket client receives an error message.|
| [WebSocket_OnCloseCallback](capi-net-websocket-type-h.md#websocket_onclosecallback) onClose       | Pointer to the callback invoked when the WebSocket client receives a **close** message.|
| [WebSocket_RequestOptions](capi-netstack-websocket-requestoptions.md) requestOptions              | Options of the connection request.|

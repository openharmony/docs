# net_websocket_type.h

## Overview

Defines data structures for the C APIs of the WebSocket client module.

**File to include**: <network/netstack/net_websocket_type.h>

**Library**: libnet_websocket.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [netstack](capi-netstack.md)

## Summary

### Structs

| Name| Description|
| -- | -- |
| [WebSocket_CloseResult](capi-netstack-websocket-closeresult.md) | Parameters for the **Close** message sent from the WebSocket server to client.|
| [WebSocket_CloseOption](capi-netstack-websocket-closeoption.md) | Parameters for the connection closure initiated by the WebSocket client.|
| [WebSocket_ErrorResult](capi-netstack-websocket-errorresult.md) | Parameters for the **Error** message sent from the WebSocket server to client.|
| [WebSocket_OpenResult](capi-netstack-websocket-openresult.md) | Parameters for the **Open** message sent from the WebSocket server to client.|
| [WebSocket_Header](capi-netstack-websocket-header.md) | Header linked list added to the WebSocket client.|
| [WebSocket_RequestOptions](capi-netstack-websocket-requestoptions.md) | Parameters of the request for connection between the WebSocket client and server.|
| [WebSocket](capi-netstack-websocket.md) | WebSocket client structure.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*WebSocket_OnOpenCallback)(struct WebSocket *client, WebSocket_OpenResult openResult)](#websocket_onopencallback) | WebSocket_OnOpenCallback | Callback invoked when the WebSocket client receives an **Open** message.|
| [typedef void (\*WebSocket_OnMessageCallback)(struct WebSocket *client, char *data, uint32_t length)](#websocket_onmessagecallback) | WebSocket_OnMessageCallback | Callback invoked when the WebSocket client receives data.|
| [typedef void (\*WebSocket_OnErrorCallback)(struct WebSocket *client, WebSocket_ErrorResult errorResult)](#websocket_onerrorcallback) | WebSocket_OnErrorCallback | Callback invoked when the WebSocket client receives an **Error** message.|
| [typedef void (\*WebSocket_OnCloseCallback)(struct WebSocket *client, WebSocket_CloseResult closeResult)](#websocket_onclosecallback) | WebSocket_OnCloseCallback | Callback invoked when the WebSocket client receives a **Close** message.|


## Function Description

### WebSocket_OnOpenCallback()

```
typedef void (*WebSocket_OnOpenCallback)(struct WebSocket *client, WebSocket_OpenResult openResult)
```

**Description**

Callback invoked when the WebSocket client receives an **Open** message.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | WebSocket client.|
| [ WebSocket_OpenResult](capi-netstack-websocket-openresult.md) openResult |   Content of the **Open** message sent from the WebSocket server to client.|

### WebSocket_OnMessageCallback()

```
typedef void (*WebSocket_OnMessageCallback)(struct WebSocket *client, char *data, uint32_t length)
```

**Description**

Callback invoked when the WebSocket client receives a **Message** message.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | WebSocket client.|
|  char *data |   Data received by the WebSocket client.|
|  uint32_t length | Length of the data received by the WebSocket client.|

### WebSocket_OnErrorCallback()

```
typedef void (*WebSocket_OnErrorCallback)(struct WebSocket *client, WebSocket_ErrorResult errorResult)
```

**Description**

Callback invoked when the WebSocket client receives an **Error** message.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | WebSocket client.|
| [ WebSocket_ErrorResult](capi-netstack-websocket-errorresult.md) errorResult |   Content of the **Error** message sent from the WebSocket server to client.|

### WebSocket_OnCloseCallback()

```
typedef void (*WebSocket_OnCloseCallback)(struct WebSocket *client, WebSocket_CloseResult closeResult)
```

**Description**

Callback invoked when the WebSocket client receives a **Close** message.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | WebSocket client.|
| [ WebSocket_CloseResult](capi-netstack-websocket-closeresult.md) closeResult |   Content of the **Close** message sent from the WebSocket server to client.|

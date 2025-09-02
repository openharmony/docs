# net_websocket.h

## Overview

Defines the WebSocket client module APIs.

**File to include**: <network/netstack/net_websocket.h>

**Library**: libnet_websocket.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Related module**: [netstack](capi-netstack.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [struct WebSocket *OH_WebSocketClient_Constructor(WebSocket_OnOpenCallback onOpen, WebSocket_OnMessageCallback onMessage,WebSocket_OnErrorCallback onError, WebSocket_OnCloseCallback onclose)](#oh_websocketclient_constructor) | Constructor used to create a WebSocket client.|
| [int OH_WebSocketClient_AddHeader(struct WebSocket *client, struct WebSocket_Header header)](#oh_websocketclient_addheader) | Adds the header information to the client request.|
| [int OH_WebSocketClient_Connect(struct WebSocket *client, const char *url, struct WebSocket_RequestOptions options)](#oh_websocketclient_connect) | Connects the WebSocket client to the server.|
| [int OH_WebSocketClient_Send(struct WebSocket *client, char *data, size_t length)](#oh_websocketclient_send) | Sends data from the WebSocket client to the server.|
| [int OH_WebSocketClient_Close(struct WebSocket *client, struct WebSocket_CloseOption options)](#oh_websocketclient_close) | Closes the connection on the WebSocket client.|
| [int OH_WebSocketClient_Destroy(struct WebSocket *client)](#oh_websocketclient_destroy) | Destorys the WebSocket client and releases the context and resources of the WebSocket connection.|

## Function Description

### OH_WebSocketClient_Constructor()

```
struct WebSocket *OH_WebSocketClient_Constructor(WebSocket_OnOpenCallback onOpen, WebSocket_OnMessageCallback onMessage,WebSocket_OnErrorCallback onError, WebSocket_OnCloseCallback onclose)
```

**Description**

Constructor used to create a WebSocket client.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [WebSocket_OnOpenCallback](capi-net-websocket-type-h.md#websocket_onopencallback) onOpen |    Callback invoked when the WebSocket client receives an **open** message.|
| [WebSocket_OnMessageCallback](capi-net-websocket-type-h.md#websocket_onmessagecallback) onMessage | Callback invoked when the WebSocket client receives a **Message** message.|
| [WebSocket_OnErrorCallback](capi-net-websocket-type-h.md#websocket_onerrorcallback) onError |   Callback invoked when the WebSocket client receives an **error** message.|
| [WebSocket_OnCloseCallback](capi-net-websocket-type-h.md#websocket_onclosecallback) onclose |   Callback invoked when the WebSocket client receives a **close** message.|

**Returns**

| Type                    | Description|
|------------------------| -- |
| [struct WebSocket](capi-netstack-websocket.md) * | Pointer to the WebSocket client if the operation is successful; **NULL** otherwise.|

### OH_WebSocketClient_AddHeader()

```
int OH_WebSocketClient_AddHeader(struct WebSocket *client, struct WebSocket_Header header)
```

**Description**

Adds the header information to the client request.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | Pointer to the WebSocket client.|
| [struct WebSocket_Header](capi-netstack-websocket-header.md) header | Header information.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** if the operation is successful; a non-0 value otherwise. For details about the return values, see **OH_Websocket_ErrCode**.|

### OH_WebSocketClient_Connect()

```
int OH_WebSocketClient_Connect(struct WebSocket *client, const char *url, struct WebSocket_RequestOptions options)
```

**Description**

Connects the WebSocket client to the server.

**System capability**: SystemCapability.Communication.NetStack

**Required permission**: ohos.permission.INTERNET

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | Pointer to the WebSocket client.|
| const char *url | IP address for the WebSocket client to connect to the server.|
| [struct WebSocket_RequestOptions](capi-netstack-websocket-requestoptions.md) options | Optional parameters for connection establishment.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** if the operation is successful; a non-0 value otherwise. For details about the return values, see **OH_Websocket_ErrCode**.|

### OH_WebSocketClient_Send()

```
int OH_WebSocketClient_Send(struct WebSocket *client, char *data, size_t length)
```

**Description**

Sends data from the WebSocket client to the server.

**System capability**: SystemCapability.Communication.NetStack

**Required permission**: ohos.permission.INTERNET

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | WebSocket client.|
| char *data |   Data sent by the WebSocket client.|
| size_t length | Length of the data sent by the WebSocket client.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** if the operation is successful; a non-0 value otherwise. For details about the return values, see **OH_Websocket_ErrCode**.|

### OH_WebSocketClient_Close()

```
int OH_WebSocketClient_Close(struct WebSocket *client, struct WebSocket_CloseOption options)
```

**Description**

Lets the WebSocket client proactively close the connection.

**System capability**: SystemCapability.Communication.NetStack

**Required permission**: ohos.permission.INTERNET

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | WebSocket client.|
| [struct WebSocket_CloseOption](capi-netstack-websocket-closeoption.md) options | Optional parameters for connection closure.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** if the operation is successful; a non-0 value otherwise. For details about the return values, see **OH_Websocket_ErrCode**.|

### OH_WebSocketClient_Destroy()

```
int OH_WebSocketClient_Destroy(struct WebSocket *client)
```

**Description**

Destorys the WebSocket client and releases the context and resources of the WebSocket connection.

**System capability**: SystemCapability.Communication.NetStack

**Required permission**: ohos.permission.INTERNET

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [struct WebSocket](capi-netstack-websocket.md) *client | WebSocket client.|

**Returns**

| Type| Description|
| -- | -- |
| int | **0** if the operation is successful; a non-0 value otherwise. For details about the return values, see **OH_Websocket_ErrCode**.|

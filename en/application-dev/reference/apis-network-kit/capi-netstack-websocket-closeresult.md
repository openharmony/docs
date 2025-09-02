# WebSocket_CloseResult

## Overview

Defines the parameters for the connection closure received by the WebSocket client.

**Since**: 11

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_websocket_type.h](capi-net-websocket-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t code | Error code.|
| const char *reason | Error cause.|

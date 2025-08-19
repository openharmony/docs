# WebSocket_OpenResult

## 概述

websocket客户端来自服务端连接成功的参数。

**起始版本：** 11

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_websocket_type.h](capi-net-websocket-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t code | websocket客户端连接成功码。 |
| const char *reason | websocket客户端连接成功原因。 |

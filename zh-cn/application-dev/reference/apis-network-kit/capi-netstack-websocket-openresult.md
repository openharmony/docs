# WebSocket_OpenResult

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

```c
struct WebSocket_OpenResult {...}
```

## 概述

WebSocket客户端来自服务端连接成功的参数。

**起始版本：** 11

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_websocket_type.h](capi-net-websocket-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t code | WebSocket客户端连接成功码。 |
| const char *reason | WebSocket客户端连接成功原因。 |

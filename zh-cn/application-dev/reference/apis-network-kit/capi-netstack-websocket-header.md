# WebSocket_Header

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

```c
struct WebSocket_Header {...}
```

## 概述

WebSocket客户端增加header的链表节点。

**起始版本：** 11

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_websocket_type.h](capi-net-websocket-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const char *fieldName | header的字段名。 |
| const char *fieldValue | header的字段内容。 |
| struct [WebSocket_Header](capi-netstack-websocket-header.md) *next | header链表的next指针。 |

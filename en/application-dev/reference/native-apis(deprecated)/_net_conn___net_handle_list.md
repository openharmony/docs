# NetConn_NetHandleList


## Overview

Network list.

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)


## Summary


### Member Variables

| Name| Description.| 
| -------- | -------- |
| [netHandles](#nethandles) [NETCONN_MAX_NET_SIZE] | Network handle list.| 
| [netHandleListSize](#nethandlelistsize) | Actual size of the network handle list.| 


## Member Variable Description


### netHandleListSize

```
int32_t NetConn_NetHandleList::netHandleListSize
```

**Description**

Actual size of the network handle list.


### netHandles

```
NetConn_NetHandle NetConn_NetHandleList::netHandles[NETCONN_MAX_NET_SIZE]
```

**Description**

Network handle list.

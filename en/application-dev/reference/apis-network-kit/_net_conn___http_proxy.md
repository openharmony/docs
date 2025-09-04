# NetConn_HttpProxy


## Overview

Defines the proxy configuration.

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)

**Header file**: [net_connection_type.h](net__connection__type_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [host](#host) [[NETCONN_MAX_STR_LEN]](_net_connection.md#macros)| Host name.| 
| [exclusionList](#exclusionlist) [[NETCONN_MAX_EXCLUSION_SIZE]](_net_connection.md#macros)[[NETCONN_MAX_STR_LEN]](_net_connection.md#macros)| Exclusion list of proxy servers.| 
| [exclusionListSize](#exclusionlistsize) | Actual size of the exclusion list.| 
| [port](#port) | Port number.| 


## Member Variable Description


### exclusionList

```
char NetConn_HttpProxy::exclusionList[NETCONN_MAX_EXCLUSION_SIZE][NETCONN_MAX_STR_LEN]
```

**Description**

Exclusion list of proxy servers.


### exclusionListSize

```
int32_t NetConn_HttpProxy::exclusionListSize
```

**Description**

Actual size of the exclusion list.


### host

```
char NetConn_HttpProxy::host[NETCONN_MAX_STR_LEN]
```

**Description**

The host name.


### port

```
uint16_t NetConn_HttpProxy::port
```

**Description**

Port number.

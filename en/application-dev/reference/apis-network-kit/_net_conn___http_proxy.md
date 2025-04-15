# NetConn_HttpProxy


## Overview

Defines proxy configuration information.

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)

**Header file**: [net_connection_type.h](net__connection__type_8h.md#net_connection_typeh)

## Summary


### Member Variables

| Name| Description.| 
| -------- | -------- |
| [host](#host) [NETCONN_MAX_STR_LEN] | Host name.| 
| [exclusionList](#exclusionlist) [NETCONN_MAX_EXCLUSION_SIZE][NETCONN_MAX_STR_LEN] | Exclusion list of proxy servers.| 
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

Host name.


### port

```
uint16_t NetConn_HttpProxy::port
```

**Description**

Port number.

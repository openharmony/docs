# NetConn_NetAddr


## Overview

Defines network addresses.

**Since**: 11

**Related module**: [NetConnection](_net_connection.md)


## Summary


### Member Variables

| Name| Use guide| 
| -------- | -------- |
| [family](#family) | Network address family.| 
| [prefixlen](#prefixlen) | Prefix length.| 
| [port](#port) | Port number.| 
| [address](#address) [NETCONN_MAX_STR_LEN] | Network address.| 


## Member Variable Description


### address

```
char NetConn_NetAddr::address[NETCONN_MAX_STR_LEN]
```

**Description**

Network address.


### family

```
uint8_t NetConn_NetAddr::family
```

**Description**

Network address family.


### port

```
uint8_t NetConn_NetAddr::port
```

**Description**

Port number.


### prefixlen

```
uint8_t NetConn_NetAddr::prefixlen
```

**Description**

Prefix length.

# Ethernet_NetAddrList

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3d09eabcbe5b86693232592574cc8cf36bd3b609 translatedAt=2026-08-14T10:24:30.051Z pushedAt=2026-08-17T08:57:35.009Z -->

```c
typedef struct Ethernet_NetAddrList {...} Ethernet_NetAddrList
```

## Overview

Defines the Ethernet network address list.

**Since:** 26.0.0

**Related module:** [NetEthernet](capi-netethernet.md)

**Header file:** [net_ethernet_type.h](capi-net-ethernet-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [Ethernet_NetAddrInfo](capi-netethernet-ethernet-netaddrinfo.md) netAddrList[ETHERNET_MAX_NET_SIZE] | Ethernet network address list. |
| int32_t netAddrListSize | Actual size of **netAddrList**. |
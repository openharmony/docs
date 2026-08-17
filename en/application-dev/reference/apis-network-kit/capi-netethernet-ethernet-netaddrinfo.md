# Ethernet_NetAddrInfo

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=ea20c67f47e9f615187fedf4e8eee13c9ce145a6 translatedAt=2026-08-14T10:24:19.202Z pushedAt=2026-08-17T08:57:35.006Z -->

```c
typedef struct Ethernet_NetAddrInfo {...} Ethernet_NetAddrInfo
```

## Overview

Defines the network address information of an Ethernet NIC, including the NIC name and network address information.

**Since:** 26.0.0

**Related module:** [NetEthernet](capi-netethernet.md)

**Header file:** [net_ethernet_type.h](capi-net-ethernet-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| char ifaceName[ETHERNET_MAX_STR_LEN] | Name of the Ethernet NIC. |
| [Ethernet_NetAddr](capi-netethernet-ethernet-netaddr.md) netAddrInfo[ETHERNET_MAX_NET_SIZE] | Network address. |
| int32_t netAddrInfoSize | Actual size of the network address array. |
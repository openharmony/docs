# Ethernet_MacAddrInfoList

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=76c20a91a7be893df6b5eba06b60b3ba304e0c02 translatedAt=2026-08-14T10:24:07.457Z pushedAt=2026-08-17T08:57:35.002Z -->

```c
typedef struct Ethernet_MacAddrInfoList {...} Ethernet_MacAddrInfoList
```

## Overview

Defines the Ethernet NIC MAC address information list.

**Since:** 26.0.0

**Related module:** [NetEthernet](capi-netethernet.md)

**File to include:** [net_ethernet_type.h](capi-net-ethernet-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [Ethernet_MacAddressInfo](capi-netethernet-ethernet-macaddressinfo.md) macInfoList[ETHERNET_MAX_NET_SIZE] | List of MAC addresses of the Ethernet NIC. |
| int32_t macInfoListSize | Actual size of the **macInfoList** array. |
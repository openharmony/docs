# Ethernet_MacAddressInfo

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=735909cba2548e8007b5ee94447be626a6f6a67a translatedAt=2026-08-14T10:23:43.396Z pushedAt=2026-08-17T08:57:34.998Z -->

```c
typedef struct Ethernet_MacAddressInfo {...} Ethernet_MacAddressInfo
```

## Overview

Defines the MAC address information of an Ethernet NIC.

**Since:** 26.0.0

**Related module:** [NetEthernet](capi-netethernet.md)

**File to include:** [net_ethernet_type.h](capi-net-ethernet-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| char ifaceName[ETHERNET_MAX_STR_LEN] | Name of the Ethernet NIC. |
| char macAddr[ETHERNET_MAX_STR_LEN] | MAC address of the Ethernet NIC. |
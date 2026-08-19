# Ethernet_NetAddr

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=b690fcd1052fc4c8786058e729856734102bd99a translatedAt=2026-08-14T10:24:19.847Z pushedAt=2026-08-17T08:57:35.008Z -->

```c
typedef struct Ethernet_NetAddr {...} Ethernet_NetAddr
```

## Overview

Defines the Network address.

**Since:** 26.0.0

**Related module:** [NetEthernet](capi-netethernet.md)

**Header file:** [net_ethernet_type.h](capi-net-ethernet-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint8_t family | Address family. IPv4 = 1, IPv6 = 2. |
| uint8_t prefixlen | Prefix length. |
| uint16_t port | Port number. |
| char address[ETHERNET_MAX_STR_LEN] | IP address. |
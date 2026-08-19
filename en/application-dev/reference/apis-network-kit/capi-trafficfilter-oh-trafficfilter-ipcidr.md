# OH_TrafficFilter_IPCidr

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:24:58.441Z pushedAt=2026-08-17T08:57:35.015Z -->

```c
typedef struct OH_TrafficFilter_IPCidr {...} OH_TrafficFilter_IPCidr
```

## Overview

Defines the IP match value for Classless Inter-Domain Routing (CIDR) matching.

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**File to include:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [OH_TrafficFilter_IPAddress](capi-trafficfilter-oh-trafficfilter-ipaddress.md) base | Base IP address of the CIDR block.<br>**Since:** 26.0.0 |
| uint8_t prefixLen | CIDR prefix length, which indicates the number of leading 1 bits in the network mask (for example, **24** indicates the subnet mask 255.255.255.0).<br>**Since:** 26.0.0 |
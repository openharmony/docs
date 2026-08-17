# OH_TrafficFilter_IPAddress

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:24:48.915Z pushedAt=2026-08-17T08:57:35.012Z -->

```c
typedef struct OH_TrafficFilter_IPAddress {...} OH_TrafficFilter_IPAddress
```

## Overview

Defines an IP address in binary form, supporting both IPv4 and IPv6.

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**File to include:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| [OH_TrafficFilter_IPFamily](capi-net-trafficfilter-type-h.md#oh_trafficfilter_ipfamily) family | Address family. If **OH_TRAFFICFILTER_IP_FAMILY_UNSPEC** is specified, IPv4 is used by default.<br>**Since:** 26.0.0 |
| uint8_t addr[OH_TRAFFICFILTER_IP_ADDRLEN] | IP address bytes. The bytes must be stored in network byte order. For IPv4, [addr](#member-variables)[0] to [addr](#member-variables)[3] store the IPv4 address, and [addr](#member-variables)[4] to [addr](#member-variables)[15] must be set to **0**. For IPv6, [addr](#member-variables)[0] to [addr](#member-variables)[15] store the IPv6 address. If the bytes do not match the address layout required by [family](#member-variables), the interface that uses this struct returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode).<br>**Since:** 26.0.0 |
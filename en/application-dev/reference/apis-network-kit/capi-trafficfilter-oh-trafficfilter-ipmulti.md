# OH_TrafficFilter_IPMulti

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:25:10.550Z pushedAt=2026-08-17T08:57:35.017Z -->

```c
typedef struct OH_TrafficFilter_IPMulti {...} OH_TrafficFilter_IPMulti
```

## Overview

Defines the IP match value for multi-IP matching.

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**Header file:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint32_t ipCount | Number of IP addresses in the array.<br>**Since:** 26.0.0 |
| [OH_TrafficFilter_IPAddress](capi-trafficfilter-oh-trafficfilter-ipaddress.md) ips[OH_TRAFFICFILTER_MAX_MULTI_IP_COUNT] | Array of IP addresses.<br>**Since:** 26.0.0 |
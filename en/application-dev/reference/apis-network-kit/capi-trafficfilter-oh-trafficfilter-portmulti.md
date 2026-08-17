# OH_TrafficFilter_PortMulti

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:25:23.952Z pushedAt=2026-08-17T08:57:35.020Z -->

```c
typedef struct OH_TrafficFilter_PortMulti {...} OH_TrafficFilter_PortMulti
```

## Overview

Defines the port matching value for multi-port matching.

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**Header file:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint32_t portCount | Number of ports in the array.<br>**Since:** 26.0.0 |
| uint16_t ports[OH_TRAFFICFILTER_MAX_MULTI_PORT_COUNT] | Port array.<br>**Since:** 26.0.0 |
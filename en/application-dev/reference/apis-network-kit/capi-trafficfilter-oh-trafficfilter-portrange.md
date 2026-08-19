# OH_TrafficFilter_PortRange

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:25:29.425Z pushedAt=2026-08-17T08:57:35.022Z -->

```c
typedef struct OH_TrafficFilter_PortRange {...} OH_TrafficFilter_PortRange
```

## Overview

Defines the port matching value for range matching.

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**File to include:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint16_t startPort | Start port of the range.<br>**Since:** 26.0.0 |
| uint16_t endPort | End port of the range.<br>**Since:** 26.0.0 |
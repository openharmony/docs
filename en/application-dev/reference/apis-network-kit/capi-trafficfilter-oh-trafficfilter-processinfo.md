# OH_TrafficFilter_ProcessInfo

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:25:40.160Z pushedAt=2026-08-17T08:57:35.024Z -->

```c
typedef struct OH_TrafficFilter_ProcessInfo {...} OH_TrafficFilter_ProcessInfo
```

## Overview

Defines the process information struct. Stores the process information returned by [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess).

Initialization rule: Before calling [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess), the caller must clear this struct to zero (for example, using memset), and then set [size](#member-variables) to the actual size of the struct allocated by the caller, which is usually **sizeof(OH_TrafficFilter_ProcessInfo)**.

Binary compatibility rule (ABI, that is, Application Binary Interface, which ensures that code compiled by old and new versions can recognize each other's struct layout): The system uses [size](#member-variables) to determine which output fields can be safely written. Only fields fully covered by [size](#member-variables) are written by the system. If [size](#member-variables) is smaller than the minimum size required to read the [size](#member-variables) field itself, the API returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). If [size](#member-variables) is larger than the size known to the system, the extra fields are ignored.

Output validity rule: When [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess) returns [OH_TRAFFICFILTER_OK](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode), the fields covered by [size](#member-variables) contain valid output values. When the API returns an error, the caller must not rely on the values of output fields other than [size](#member-variables).

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**File to include:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint32_t size | Actual size of the struct allocated by the caller.<br>**Since:** 26.0.0 |
| uint32_t pid | Process ID.<br>**Since:** 26.0.0 |
| uint32_t uid | App UID.<br>**Since:** 26.0.0 |
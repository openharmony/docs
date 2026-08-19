# OH_TrafficFilter_InterfaceMatch

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:24:51.660Z pushedAt=2026-08-17T08:57:35.013Z -->

```c
typedef struct OH_TrafficFilter_InterfaceMatch {...} OH_TrafficFilter_InterfaceMatch
```

## Overview

Defines the interface match condition.

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**File to include:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| bool enabled | Whether to enable interface match. The value **true** means to enable interface match, and **false** means not to enable interface match.<br>**Since:** 26.0.0 |
| bool invert | Whether to invert the match result. The value **true** means to invert the match result, and **false** means not to invert the match result.<br>**Since:** 26.0.0 |
| bool isPrefix | Whether to match the interface name by prefix. The value **true** means to match by prefix, and **false** means not to match by prefix.<br>**Since:** 26.0.0 |
| char ifName[OH_TRAFFICFILTER_IFNAMSIZ] | Interface name. The string must be UTF-8 encoded and NULL-terminated. The buffer capacity is [OH_TRAFFICFILTER_IFNAMSIZ](capi-net-trafficfilter-type-h.md#macros) bytes, including the terminating NULL character. Therefore, the maximum length of the interface name is [OH_TRAFFICFILTER_IFNAMSIZ](capi-net-trafficfilter-type-h.md#macros) - 1 bytes, excluding the terminating NULL character. If [enabled](#member-variables) is **true**, the string cannot be empty. If the string is not NULL-terminated within [OH_TRAFFICFILTER_IFNAMSIZ](capi-net-trafficfilter-type-h.md#macros) bytes, or its length exceeds [OH_TRAFFICFILTER_IFNAMSIZ](capi-net-trafficfilter-type-h.md#macros) - 1 bytes, the API that uses this struct returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). If [enabled](#member-variables) is **false**, this field is ignored. It is recommended to set the entire buffer to zero when interface match is disabled.<br>**Since:** 26.0.0 |
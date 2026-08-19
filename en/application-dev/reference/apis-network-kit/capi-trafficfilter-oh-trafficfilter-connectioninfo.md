# OH_TrafficFilter_ConnectionInfo

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=e4860fc95c8d8b95b77255afd3be962b586518ba translatedAt=2026-08-14T10:24:43.185Z pushedAt=2026-08-17T08:57:35.011Z -->

```c
typedef struct OH_TrafficFilter_ConnectionInfo {...} OH_TrafficFilter_ConnectionInfo
```

## Overview

Defines the connection information struct. It describes the five-tuple information of a network connection (source IP, destination IP, source port, destination port, and protocol type), which is used to query the process that initiates the connection.

Initialization rule: Before calling [OH_TrafficFilter_QueryProcess](capi-net-trafficfilter-h.md#oh_trafficfilter_queryprocess), the caller must clear this struct to zero (for example, using **memset**), and then set [size](#member-variables) to the actual size of the struct allocated by the caller, which is usually **sizeof(OH_TrafficFilter_ConnectionInfo)**.

Binary compatibility rule (ABI, that is, Application Binary Interface, which ensures that code compiled by old and new versions can recognize each other's struct layout): The system determines which fields can be safely read based on [size](#member-variables). If [size](#member-variables) is smaller than the minimum size required by the current interface, the interface returns [OH_TRAFFICFILTER_ERROR_INVALID_PARAM](capi-net-trafficfilter-type-h.md#oh_trafficfilter_errcode). If [size](#member-variables) is larger than the size known to the system, the extra fields are ignored.

**Since:** 26.0.0

**Related module:** [TrafficFilter](capi-trafficfilter.md)

**File to include:** [net_trafficfilter_type.h](capi-net-trafficfilter-type-h.md)

## Summary

### Member Variables

| Name | Description |
| -- | -- |
| uint32_t size | Actual size of the structure allocated by the caller.<br>**Since:** 26.0.0 |
| [OH_TrafficFilter_IPAddress](capi-trafficfilter-oh-trafficfilter-ipaddress.md) srcIp | Source IP address, which supports IPv4 and IPv6.<br>**Since:** 26.0.0 |
| uint16_t srcPort | Source port. The value 0 indicates any source port.<br>**Since:** 26.0.0 |
| [OH_TrafficFilter_IPAddress](capi-trafficfilter-oh-trafficfilter-ipaddress.md) dstIp | Destination IP address, which supports IPv4 and IPv6 and must use the same address family as the source IP address.<br>**Since:** 26.0.0 |
| uint16_t dstPort | Destination port. The value **0** indicates any destination port.<br>**Since:** 26.0.0 |
| uint8_t protocol | Protocol type. Supported values: - OH_TRAFFICFILTER_PROTO_TCP (6)- OH_TRAFFICFILTER_PROTO_UDP (17)<br>**Since:** 26.0.0 |
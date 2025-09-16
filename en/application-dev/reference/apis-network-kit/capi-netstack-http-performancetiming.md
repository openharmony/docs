# Http_PerformanceTiming
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the HTTP response timing information, which will be collected via {@link Http_Response.performanceTiming}.

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_http_type.h](capi-net-http-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| double dnsTiming | Duration from the time when the request is initiated to the time when the DNS resolution is complete.|
| double tcpTiming | Duration from the time when the request is initiated to the time when the TCP connection is complete.|
| double tlsTiming | Duration from the time when the request is initiated to the time when the TLS connection is complete.|
| double firstSendTiming | Duration from the time when the request is initiated to the time when the first byte is sent.|
| double firstReceiveTiming | Duration from the time when the request is initiated to the time when the first byte is received.|
| double totalFinishTiming | Duration from the time when the request is initiated to the time when the request is complete.|
| double redirectTiming | Duration from the time when the request is initiated to the time when all redirection steps are complete.|

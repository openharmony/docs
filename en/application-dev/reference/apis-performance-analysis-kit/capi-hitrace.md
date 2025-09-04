# HiTrace

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--SE: @MontSaintMichel-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

HiTraceChain provides APIs for cross-thread and cross-process distributed tracing. HiTraceChain generates a unique chain ID for a service process and passes it to various information (including application events, system events, and logs) specific to the service process. During debugging and fault locating, you can use the unique chain ID to quickly correlate various information related to the service process.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 10
## Files

| Name| Description|
| -- | -- |
| [trace.h](capi-trace-h.md) | Defines APIs of the HiTraceMeter module for performance trace. The vertical bar `|` is used as the separator in user-mode trace format.|Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.<br> The maximum length of a user-mode trace is 512 characters. Excess characters will be truncated.<br>|

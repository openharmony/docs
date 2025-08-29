# HiDebug_NativeMemInfo

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the struct for the local memory information of the application process.

**Since**: 12

**Related module**: [HiDebug](capi-hidebug.md)

**Header file**: [hidebug_type.h](capi-hidebug-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t pss | Proportional set size, in KB.|
| uint32_t vss | Virtual memory size, in KB.|
| uint32_t rss | Resident set size, in KB.|
| uint32_t sharedDirty | Size of the shared dirty memory, in KB.|
| uint32_t privateDirty | Size of the private dirty memory, in KB.|
| uint32_t sharedClean | Size of the shared clean memory, in KB.|
| uint32_t privateClean | Size of the private clean memory, in KB.|

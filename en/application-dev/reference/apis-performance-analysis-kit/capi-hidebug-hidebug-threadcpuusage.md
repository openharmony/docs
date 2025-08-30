# HiDebug_ThreadCpuUsage

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the struct for the CPU usage of all threads of an application.

**Since**: 12

**Related module**: [HiDebug](capi-hidebug.md)

**Header file**: [hidebug_type.h](capi-hidebug-type-h.md)

## Summary

### Member Variables

| Name                                     | Description|
|-----------------------------------------| -- |
| uint32_t threadId                       | Thread ID.|
| double cpuUsage                         | Thread CPU usage, in percentage.|
| struct [HiDebug_ThreadCpuUsage](capi-hidebug-hidebug-threadcpuusage.md) *next | Pointer to the CPU usage of the next thread.|

# HiTraceId

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--SE: @MontSaintMichel-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines a **HiTraceId** instance.

**Since**: 12

**Related module**: [Hitrace](capi-hitrace.md)

**Header file**: [trace.h](capi-trace-h.md)

## Summary

### Member Variables

A little-endian **HiTraceId** consists of the following fields in sequence: 

| Field| Number of Bits| Description| 
| -------- | -------- | -------- |
| uint64_t valid | 1 | Whether a **HiTraceId** instance is valid.| 
| uint64_t ver | 3 | Version number of **HiTraceId**.| 
| uint64_t chainId | 60 | Chain ID of **HiTraceId**.| 
| uint64_t flags | 12 | Flag of **HiTraceId**.| 
| uint64_t spanId | 26 | Span ID of **HiTraceId**.| 
| uint64_t parentSpanId | 26 | Parent span ID of **HiTraceId**.| 

A big-endian **HiTraceId** consists of the following fields in sequence:

| Field| Number of Bits| Description| 
| -------- | -------- | -------- |
| uint64_t chainId | 60 | Chain ID of **HiTraceId**.| 
| uint64_t ver | 3 | Version number of **HiTraceId**.| 
| uint64_t valid | 1 | Whether a **HiTraceId** instance is valid.| 
| uint64_t parentSpanId | 26 | Parent span ID of **HiTraceId**.| 
| uint64_t spanId | 26 | Span ID of **HiTraceId**.| 
| uint64_t flags | 12 | Flag of **HiTraceId**.| 

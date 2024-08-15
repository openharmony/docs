# HiTraceId


## Overview

Defines a struct for **HiTraceId**.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

**Related module**: [Hitrace](_hitrace.md)


## Summary


### Member Variables

A little-endian **HiTraceId** consists of the following fields in sequence: 

| Field| Number of Bits| Description| 
| -------- | -------- | -------- |
| uint64_t [valid](_hitrace.md#valid) | 1 | Whether **HiTraceId** is valid. | 
| uint64_t [ver](_hitrace.md#ver) | 3 | Version number of **HiTraceId**. | 
| uint64_t [chainId](_hitrace.md#chainid) | 60 | Chain ID of **HiTraceId**. | 
| uint64_t [flags](_hitrace.md#flags) | 12 | Flag of **HiTraceId**. | 
| uint64_t [spanId](_hitrace.md#spanid) | 26 | Span ID of **HiTraceId**. | 
| uint64_t [parentSpanId](_hitrace.md#parentspanid) | 26 | Parent span ID of **HiTraceId**. | 

A big-endian **HiTraceId** consists of the following fields in sequence: 

| Field| Number of Bits| Description| 
| -------- | -------- | -------- |
| uint64_t [chainId](_hitrace.md#chainid) | 60 | Chain ID of **HiTraceId**. | 
| uint64_t [ver](_hitrace.md#ver) | 3 | Version number of **HiTraceId**. | 
| uint64_t [valid](_hitrace.md#valid) | 1 | Whether **HiTraceId** is valid. | 
| uint64_t [parentSpanId](_hitrace.md#parentspanid) | 26 | Parent span ID of **HiTraceId**. | 
| uint64_t [spanId](_hitrace.md#spanid) | 26 | Span ID of **HiTraceId**. | 
| uint64_t [flags](_hitrace.md#flags) | 12 | Flag of **HiTraceId**. | 

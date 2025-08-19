# ffrt_rwlock_t

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The **ffrt_rwlock_t** struct describes an FFRT read-write lock.

**Since**: 18

**Related module**: [FFRT](capi-ffrt.md)

**Header file**: [type_def.h](capi-type-def-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t storage[(ffrt_rwlock_storage_size + sizeof(uint32_t) - 1) / sizeof(uint32_t)] | Storage size of a read-write lock.|

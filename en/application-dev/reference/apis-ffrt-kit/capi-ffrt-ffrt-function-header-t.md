# ffrt_function_header_t

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The **ffrt_function_header_t** struct describes a task execution function.

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

**Header file**: [type_def.h](capi-type-def-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| ffrt_function_t exec | Function used to execute a task.|
| ffrt_function_t destroy | Function used to destroy a task.|
| uint64_t reserve[2] | Reserved bit, which must be set to **0**.|

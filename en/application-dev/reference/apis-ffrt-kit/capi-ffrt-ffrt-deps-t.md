# ffrt_deps_t

<!--Kit: Function Flow Runtime Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @chuchihtung; @yanleo-->
<!--SE: @geoffrey_guo; @huangyouzhong-->
<!--TSE: @lotsof; @sunxuhao-->

## Overview

The **ffrt_deps_t** struct describes dependencies.

**Since**: 10

**Related module**: [FFRT](capi-ffrt.md)

**Header file**: [type_def.h](capi-type-def-h.md)

## Summary

### Member Variables

| Name                                | Description|
|------------------------------------| -- |
| uint32_t len                       | Number of dependencies.|
| const [ffrt_dependence_t](capi-ffrt-ffrt-dependence-t.md)* items | Dependency data.|

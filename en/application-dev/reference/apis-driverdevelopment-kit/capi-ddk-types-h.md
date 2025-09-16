# ddk_types.h
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Provides BASE DDK types and declares the macros, enums, and data structures required by the BASE DDK APIs.

**Header file:** <ddk/ddk_types.h>

**Library**: libddk_base.z.so

**System capability**: SystemCapability.Driver.DDK.Extension

**Since**: 12

**Related module**: [BaseDdk](capi-baseddk.md)

## Summary

### Structs

| Name                                      | typedef Keyword| Description|
|------------------------------------------| -- | -- |
| [DDK_Ashmem](capi-baseddk-ddk-ashmem.md) | DDK_Ashmem | Device memory map created by calling **OH_DDK_CreateAshmem**. A buffer using the device memory map can provide better performance.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [DDK_RetCode](#ddk_retcode) | DDK_RetCode | Enumerates error codes used in the BASE DDK.|

## Enum Description

### DDK_RetCode

```
enum DDK_RetCode
```

**Description**

Enumerates the error codes used in the basic DDK.

**Since**: 12

| Enum| Description|
| -- | -- |
| DDK_SUCCESS = 0 | Operation success.|
| DDK_FAILURE = 28600001 | Operation failed.|
| DDK_INVALID_PARAMETER = 28600002 | Invalid parameter.|
| DDK_INVALID_OPERATION = 28600003 | Invalid operation.|
| DDK_NULL_PTR = 28600004 | Null pointer.|

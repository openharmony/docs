# HiDebug_NativeStackFrame

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the native stack frame content.

**Since**: 20

**Related module**: [HiDebug](capi-hidebug.md)

**Header file**: [hidebug_type.h](capi-hidebug-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint64_t relativePc | Relative PC address, which is the offset of the current PC relative to the start address of its mapping area (such as an executable file or shared library).|
| uint64_t funcOffset | Offset of the function corresponding to the current stack frame in its mapping area (such as an executable file or shared library).|
| const char* mapName | Name of the mapping area to which the current stack frame belongs.|
| const char* functionName | Name of the function corresponding to the current stack frame.|
| const char* buildId | Build ID that uniquely identifies the current mapping area (such as an executable file or shared library). During debugging and symbol parsing, **buildId** ensures that the symbol file version matches the actual binary file version.|
| const char* reserved | Reserved field for future extension.|

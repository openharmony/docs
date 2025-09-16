# HiDebug_JsStackFrame

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the JS stack frame content.

**Since**: 20

**Related module**: [HiDebug](capi-hidebug.md)

**Header file**: [hidebug_type.h](capi-hidebug-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint64_t relativePc | Relative PC address, which is the offset of the current PC relative to the start address of its mapping area (such as an executable file or shared library).|
| int32_t line | Line number of the code corresponding to the current stack frame.|
| int32_t column | Column number of the code corresponding to the current stack frame.|
| const char* mapName | Name of the mapping area to which the current stack frame belongs.|
| const char* functionName | Name of the function corresponding to the current stack frame.|
| const char* url | URL of the code file corresponding to the current stack frame. It can be used to find the corresponding code file in the local path or on the remote server.|
| const char* packageName | Name of the package to which the code corresponding to the current stack frame belongs.|

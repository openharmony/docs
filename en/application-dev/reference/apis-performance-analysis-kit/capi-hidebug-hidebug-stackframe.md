# HiDebug_StackFrame

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the stack frame content.

**Since**: 20

**Related module**: [HiDebug](capi-hidebug.md)

**Header file**: [hidebug_type.h](capi-hidebug-type-h.md)

## Summary

### Member Variables

| Name                                                                          | Description                                             |
|------------------------------------------------------------------------------|-------------------------------------------------|
| [HiDebug_StackFrameType](capi-hidebug-type-h.md#hidebug_stackframetype) type | Type of the current stack.                                        |
| struct [HiDebug_JsStackFrame](capi-hidebug-hidebug-jsstackframe.md) js       | JS stack frame content defined by [HiDebug_JsStackFrame](capi-hidebug-hidebug-jsstackframe.md).        |
| struct [HiDebug_NativeStackFrame](capi-hidebug-hidebug-nativestackframe.md) native                                   | Native stack frame content defined by [HiDebug_NativeStackFrame](capi-hidebug-hidebug-nativestackframe.md).|

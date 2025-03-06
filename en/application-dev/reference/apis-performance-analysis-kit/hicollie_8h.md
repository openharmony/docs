# hicollie.h

## Overview

Defines APIs of the HiCollie module.

**Library**: libohhicollie.so

**System capability**: SystemCapability.HiviewDFX.HiCollie

**File to include**: <hicollie/hicollie.h>

**Since**: 12

**Related module**: [HiCollie](_hi_hicollie.md)

## Summary

### Functions

| Name| Description|
| -------- | -------- |
| HiCollie_ErrorCode [OH_HiCollie_Init_StuckDetection](_hi_hicollie.md#oh_hicollie_init_stuckdetection)(OH_HiCollie_Task task) | Registers a callback to periodically detect service thread stuck events. |
| HiCollie_ErrorCode [OH_HiCollie_Init_JankDetection](_hi_hicollie.md#oh_hicollie_init_jankdetection)(OH_HiCollie_BeginFunc\* beginFunc, OH_HiCollie_EndFunc\* endFunc, HiCollie_DetectionParam param) | Registers a callback to detect service thread jank events. To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  |
| HiCollie_ErrorCode [OH_HiCollie_Report](_hi_hicollie.md#oh_hicollie_report)(bool\* isSixSecond) | Reports a service thread stuck event and generates timeout logs to help locate application timeout events.  |

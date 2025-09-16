# HiCollie_SetTimerParam

## Overview

Defines the input parameters of the **OH_HiCollie_SetTimer** function.

**Since**: 18

**Related module**: [HiCollie](capi-hicollie.md)

**Header file**: [hicollie.h](capi-hicollie-h.md)

## Summary

### Member Variables

| Name                                                                  | Description|
|----------------------------------------------------------------------| -- |
| const char *name                                                     | Timer task name.|
| unsigned int timeout                                                 | Task timeout threshold, in seconds.|
| [OH_HiCollie_Callback](capi-hicollie-h.md#oh_hicollie_callback) func | Callback executed when a timeout occurs.|
| void *arg                                                            | Parameters of the callback.|
| [HiCollie_Flag](capi-hicollie-h.md#hicollie_flag) flag               | Action performed when a timeout occurs. For details, see [HiCollie_Flag](capi-hicollie-h.md#hicollie_flag).|

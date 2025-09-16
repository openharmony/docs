# HiAppEvent_AppEventInfo

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format.

**Since**: 12

**Related Module**: [HiAppEvent](capi-hiappevent.md)

**Header File**: [hiappevent.h](capi-hiappevent-h.md)

## Summary

### Member Variables

| Name                                                   | Description|
|-------------------------------------------------------| -- |
| const char* domain                                    | Pointer to the event domain.|
| const char* name                                      | Pointer to the event name.|
| enum [EventType](capi-hiappevent-h.md#eventtype) type | Event type.|
| const char* params                                    | Event parameter list in JSON format.|

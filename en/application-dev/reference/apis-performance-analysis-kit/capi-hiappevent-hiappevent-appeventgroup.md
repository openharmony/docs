# HiAppEvent_AppEventGroup

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the information of an event group, including its name, the array of event information grouped by name, and the length of the event array.

**Since**: 12

**Related Module**: [HiAppEvent](capi-hiappevent.md)

**Header File**: [hiappevent.h](capi-hiappevent-h.md)

## Summary

### Member Variables

| Name                                                     | Description|
|---------------------------------------------------------| -- |
| const char* name                                        | Pointer to the event name.|
| const struct [HiAppEvent_AppEventInfo](capi-hiappevent-hiappevent-appeventinfo.md)* appEventInfos | Pointer to the array of events with the same event name.|
| uint32_t infoLen                                        | Length of the event array.|

# oh_location.h


## Overview

Defines APIs for querying the location switch status, and starting and stopping location.

\@kit LocationKit

**Library**: liblocation_ndk.so

**System capability**: SystemCapability.Location.Location.Core

**Since**: 13

**Related module**: [Location](_location.md)


## Summary


### Callback

| Name| Description| 
| -------- | -------- |
| [Location_ResultCode](_location.md#location_resultcode) [OH_Location_IsLocatingEnabled](_location.md#oh_location_islocatingenabled) (bool \*enabled) | Checks whether the location switch is enabled. | 
| [Location_ResultCode](_location.md#location_resultcode) [OH_Location_StartLocating](_location.md#oh_location_startlocating) (const [Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig) | Starts locating and subscribes to location changes. | 
| [Location_ResultCode](_location.md#location_resultcode) [OH_Location_StopLocating](_location.md#oh_location_stoplocating) (const [Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig) | Stops locating and unsubscribes from location changes. | 

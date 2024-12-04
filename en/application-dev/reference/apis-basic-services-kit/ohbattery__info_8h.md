# ohbattery_info.h


## Overview

Declares the battery APIs that are used to obtain the current battery capacity and power supply type and define common battery events.

**Library**: libohbattery_info.so

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Since**: 13

**Related module**: [OH_BatteryInfo](oh__batteryinfo.md)


## Summary


### Enums

| Name| Description| 
| -------- | -------- |
| [BatteryInfo_BatteryPluggedType](oh__batteryinfo.md#batteryinfo_batterypluggedtype) {<br>PLUGGED_TYPE_NONE , PLUGGED_TYPE_AC , PLUGGED_TYPE_USB , PLUGGED_TYPE_WIRELESS , PLUGGED_TYPE_BUTT } | Defines the plug type.| 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_BatteryInfo_GetCapacity](oh__batteryinfo.md#oh_batteryinfo_getcapacity) () | Obtains the current battery capacity.| 
| [BatteryInfo_BatteryPluggedType](oh__batteryinfo.md#batteryinfo_batterypluggedtype)[OH_BatteryInfo_GetPluggedType](oh__batteryinfo.md#oh_batteryinfo_getpluggedtype) () | Obtains the plug type.| 


### Variables

| Name| Description| 
| -------- | -------- |
| static const char\* [COMMON_EVENT_KEY_CAPACITY](oh__batteryinfo.md#common_event_key_capacity) = "soc" | Common event indicating a battery capacity change.| 
| static const char\* [COMMON_EVENT_KEY_CHARGE_STATE](oh__batteryinfo.md#common_event_key_charge_state) = "chargeState" | Common event indicating a charging status change.| 
| static const char\* [COMMON_EVENT_KEY_PLUGGED_TYPE](oh__batteryinfo.md#common_event_key_plugged_type) = "pluggedType" | Common event indicating a plug type change.| 

# OH_BatteryInfo

## Overview

Provides APIs for the BatteryInfo module to obtain battery information.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Since**: 13


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [ohbattery_info.h](ohbattery__info_8h.md) | Declares the battery APIs that are used to obtain the current battery capacity and power supply type and define common battery events.<br>**Library**: libohbattery_info.so| 


### Enums

| Name| Description| 
| -------- | -------- |
| [BatteryInfo_BatteryPluggedType](#batteryinfo_batterypluggedtype) {<br>PLUGGED_TYPE_NONE , PLUGGED_TYPE_AC , PLUGGED_TYPE_USB , PLUGGED_TYPE_WIRELESS , PLUGGED_TYPE_BUTT } | Defines the plug type.| 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_BatteryInfo_GetCapacity](#oh_batteryinfo_getcapacity) () | Obtains the current battery capacity.| 
| [BatteryInfo_BatteryPluggedType](#batteryinfo_batterypluggedtype) [OH_BatteryInfo_GetPluggedType](#oh_batteryinfo_getpluggedtype) () | Obtains the plug type.| 


### Variables

| Name| Description| 
| -------- | -------- |
| static const char\* [COMMON_EVENT_KEY_CAPACITY](#common_event_key_capacity) = "soc" | Common event indicating a battery capacity change.| 
| static const char\* [COMMON_EVENT_KEY_CHARGE_STATE](#common_event_key_charge_state) = "chargeState" | Common event indicating a charging status change.| 
| static const char\* [COMMON_EVENT_KEY_PLUGGED_TYPE](#common_event_key_plugged_type) = "pluggedType" | Common event indicating a plug type change.| 


## Enum Description


### BatteryInfo_BatteryPluggedType

```
enum BatteryInfo_BatteryPluggedType
```

**Description**

Defines the plug type.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| PLUGGED_TYPE_NONE | No power supply.| 
| PLUGGED_TYPE_AC | AC charging.| 
| PLUGGED_TYPE_USB | USB DC charging.| 
| PLUGGED_TYPE_WIRELESS | Wireless charging.| 
| PLUGGED_TYPE_BUTT | Reserved.| 


## Function Description


### OH_BatteryInfo_GetCapacity()

```
int32_t OH_BatteryInfo_GetCapacity ()
```

**Description**

Obtains the current battery capacity.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Since**: 13

**Returns**

A number in the range from 0 to 100.


### OH_BatteryInfo_GetPluggedType()

```
BatteryInfo_BatteryPluggedType OH_BatteryInfo_GetPluggedType ()
```

**Description**

Obtains the plug type.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Since**: 13

**Returns**

PLUGGED_TYPE_NONE: No power supply.

PLUGGED_TYPE_AC: AC charging.

PLUGGED_TYPE_USB: USB DC charging.

PLUGGED_TYPE_WIRELESS: wireless charging.

PLUGGED_TYPE_BUTT: unknown plug type.


## Variable Description


### COMMON_EVENT_KEY_CAPACITY

```
const char* COMMON_EVENT_KEY_CAPACITY = "soc"
```

**Description**

Defines the common event indicating a battery capacity change.

**Since**: 13


### COMMON_EVENT_KEY_CHARGE_STATE

```
const char* COMMON_EVENT_KEY_CHARGE_STATE = "chargeState"
```

**Description**

Defines the common event indicating a charging status change.

**Since**: 13


### COMMON_EVENT_KEY_PLUGGED_TYPE

```
const char* COMMON_EVENT_KEY_PLUGGED_TYPE = "pluggedType"
```

**Description**

Defines the common event indicating a plug type change.

**Since**: 13

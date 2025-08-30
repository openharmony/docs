# ohbattery_info.h

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

## Overview

Declares the battery APIs that are used to obtain the current battery capacity and power supply type and define common battery events.

**Library**: libohbattery_info.so

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Since**: 13

**Related modules**: [OH_BatteryInfo](capi-oh-batteryinfo.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [BatteryInfo_BatteryPluggedType](#batteryinfo_batterypluggedtype) | BatteryInfo_BatteryPluggedType | Enumerates the battery plugged types.|

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_BatteryInfo_GetCapacity()](#oh_batteryinfo_getcapacity) | Obtains the current battery capacity.|
| [BatteryInfo_BatteryPluggedType OH_BatteryInfo_GetPluggedType()](#oh_batteryinfo_getpluggedtype) | Obtains the battery plugged type.|

### Variables

| Name| Description|
| -- | -- |
| static const char * COMMON_EVENT_KEY_CAPACITY = "soc" | Defines the common event indicating a battery capacity change.<br>**Since**: 13<br>**System capability**: SystemCapability.PowerManager.BatteryManager.Core|
| static const char * COMMON_EVENT_KEY_CHARGE_STATE = "chargeState" | Defines the common event indicating a charging status change.<br>**Since**: 13|
| static const char * COMMON_EVENT_KEY_PLUGGED_TYPE = "pluggedType" | Defines the common event indicating a battery plugged type change.<br>**Since**: 13|

## Enum Description

### BatteryInfo_BatteryPluggedType

```
enum BatteryInfo_BatteryPluggedType
```

**Description**

Enumerates the battery plugged types.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| PLUGGED_TYPE_NONE | No power supply.|
| PLUGGED_TYPE_AC | AC charging.|
| PLUGGED_TYPE_USB | USB DC charging.|
| PLUGGED_TYPE_WIRELESS | Wireless charging.|
| PLUGGED_TYPE_BUTT | Reserved.|


## Function Description

### OH_BatteryInfo_GetCapacity()

```
int32_t OH_BatteryInfo_GetCapacity()
```

**Description**

Obtains the current battery capacity.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| int32_t | A number in the range from 0 to 100.|

### OH_BatteryInfo_GetPluggedType()

```
BatteryInfo_BatteryPluggedType OH_BatteryInfo_GetPluggedType()
```

**Description**

Obtains the battery plugged type.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [BatteryInfo_BatteryPluggedType](#batteryinfo_batterypluggedtype) | Returns {@link BatteryInfo_BatteryPluggedType#PLUGGED_TYPE_NONE} if there is no power supply;<br>returns [PLUGGED_TYPE_AC](capi-ohbattery-info-h.md#batteryinfo_batterypluggedtype) if the power supply is in AC charging mode;<br>returns [PLUGGED_TYPE_USB](capi-ohbattery-info-h.md#batteryinfo_batterypluggedtype) if the power supply is in USB DC charging mode;<br>returns [PLUGGED_TYPE_WIRELESS](capi-ohbattery-info-h.md#batteryinfo_batterypluggedtype) if the power supply is in wireless charging mode;<br>returns [PLUGGED_TYPE_BUTT](capi-ohbattery-info-h.md#batteryinfo_batterypluggedtype) if the battery plugged type is unknown. |

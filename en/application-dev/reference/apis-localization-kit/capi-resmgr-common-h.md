# resmgr_common.h

## Overview

Provides the enum types and structures for resource manager APIs.

**File to include**: <resourcemanager/resmgr_common.h>

**Library**: libohresmgr.so

**System capability**: SystemCapability.Global.ResourceManager

**Since**: 12

**Related module**: [resourcemanager](capi-resourcemanager.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ResourceManager_Configuration](capi-resourcemanager-resourcemanager-configuration.md) | ResourceManager_Configuration | Enumerates device states.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ResourceManager_ErrorCode](#resourcemanager_errorcode) | - | Enumerates resource manager error codes.|
| [ScreenDensity](#screendensity) | - | Enumerates screen density types.|
| [ResourceManager_Direction](#resourcemanager_direction) | ResourceManager_Direction | Enumerates screen orientations.|
| [ResourceManager_ColorMode](#resourcemanager_colormode) | ResourceManager_ColorMode | Enumerates color modes.|
| [ResourceManager_DeviceType](#resourcemanager_devicetype) | ResourceManager_DeviceType | Enumerates device types.|

## Enum Description

### ResourceManager_ErrorCode

```
enum ResourceManager_ErrorCode
```

**Description**

Enumerates resource manager error codes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| SUCCESS = 0 | Operation successful.|
| ERROR_CODE_INVALID_INPUT_PARAMETER = 401 | Invalid input parameter.|
| ERROR_CODE_RES_ID_NOT_FOUND = 9001001 | Invalid resource ID.|
| ERROR_CODE_RES_NOT_FOUND_BY_ID = 9001002 | Invalid resource name.|
| ERROR_CODE_RES_NAME_NOT_FOUND = 9001003 | No matching resource found based on the resource ID.|
| ERROR_CODE_RES_NOT_FOUND_BY_NAME = 9001004 | No matching resource found based on the resource name.|
| ERROR_CODE_RES_PATH_INVALID = 9001005 | Invalid relative path.|
| ERROR_CODE_RES_REF_TOO_MUCH = 9001006 | Resource referenced cyclically.|
| ERROR_CODE_RES_ID_FORMAT_ERROR = 9001007 | Failed to format the resource obtained based on the specified resource ID.|
| ERROR_CODE_RES_NAME_FORMAT_ERROR = 9001008 | Failed to format the resource obtained based on the specified resource name.|
| ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED = 9001009 | Failed to access system resources.|
| ERROR_CODE_OVERLAY_RES_PATH_INVALID = 9001010 | Invalid overlay path.|
| ERROR_CODE_OUT_OF_MEMORY = 9001100 | A memory overflow occurs.|

### ScreenDensity

```
enum ScreenDensity
```

**Description**

Enumerates screen density types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| SCREEN_SDPI = 120 | Screen density with small-scale dots per inch (SDPI).|
| SCREEN_MDPI = 160 | Screen density with medium-scale dots per inch (MDPI).|
| SCREEN_LDPI = 240 | Screen density with large-scale dots per inch (LDPI).|
| SCREEN_XLDPI = 320 | Screen density with extra-large-scale dots per inch (XLDPI).|
| SCREEN_XXLDPI = 480 | Screen density with extra-extra-large-scale dots per inch (XXLDPI).|
| SCREEN_XXXLDPI = 640 | Screen density with extra-extra-extra-large-scale dots per inch (XXXLDPI).|

### ResourceManager_Direction

```
enum ResourceManager_Direction
```

**Description**

Enumerates screen orientations.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DIRECTION_VERTICAL = 0 | Vertical direction.|
| DIRECTION_HORIZONTAL = 1 | Horizontal direction.|

### ResourceManager_ColorMode

```
enum ResourceManager_ColorMode
```

**Description**

Enumerates color modes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DARK = 0 | Dark mode.|
| LIGHT = 1 | Light mode.|

### ResourceManager_DeviceType

```
enum ResourceManager_DeviceType
```

**Description**

Enumerates device types.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DEVICE_TYPE_PHONE = 0X00 | Smartphone|
| DEVICE_TYPE_TABLET = 0x01 | Tablet|
| DEVICE_TYPE_CAR = 0x02 | Automobile|
| DEVICE_TYPE_PC = 0x03 | Computer|
| DEVICE_TYPE_TV = 0x04 | TV.|
| DEVICE_TYPE_WEARABLE = 0x06 | Wearable|
| DEVICE_TYPE_2IN1 = 0x07 | 2-in-1 device|

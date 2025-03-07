# resmgr_common.h


## Overview

Provides the enum types and structures for resource manager APIs.

**System capability**: SystemCapability.Global.ResourceManager

**Library**: libohresmgr.so

**Since**: 12

**Related module**: [Resourcemanager](resourcemanager.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ResourceManager_Configuration](_resource_manager___configuration.md) | Enumerates device states. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) | Enumerates screen orientations. | 
| typedef enum [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) | Enumerates color modes. | 
| typedef enum [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) | Enumerates device types. | 
| typedef struct [ResourceManager_Configuration](_resource_manager___configuration.md) [ResourceManager_Configuration](resourcemanager.md#resourcemanager_configuration) | Enumerates device states. | 


### Enumerated value

| Name| Description| 
| -------- | -------- |
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode) {<br>[SUCCESS](resourcemanager.md) = 0, [ERROR_CODE_INVALID_INPUT_PARAMETER](resourcemanager.md) = 401, [ERROR_CODE_RES_ID_NOT_FOUND](resourcemanager.md) = 9001001, [ERROR_CODE_RES_NOT_FOUND_BY_ID](resourcemanager.md) = 9001002,<br>[ERROR_CODE_RES_NAME_NOT_FOUND](resourcemanager.md) = 9001003, [ERROR_CODE_RES_NOT_FOUND_BY_NAME](resourcemanager.md) = 9001004, [ERROR_CODE_RES_PATH_INVALID](resourcemanager.md) = 9001005, [ERROR_CODE_RES_REF_TOO_MUCH](resourcemanager.md) = 9001006,<br>[ERROR_CODE_RES_ID_FORMAT_ERROR](resourcemanager.md) = 9001007, [ERROR_CODE_RES_NAME_FORMAT_ERROR](resourcemanager.md) = 9001008, [ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED](resourcemanager.md) = 9001009, [ERROR_CODE_OVERLAY_RES_PATH_INVALID](resourcemanager.md) = 9001010,<br>[ERROR_CODE_OUT_OF_MEMORY](resourcemanager.md) = 9001100<br>} | Enumerates resource manager error codes. | 
| [ScreenDensity](resourcemanager.md#screendensity) {<br>[SCREEN_SDPI](resourcemanager.md) = 120, [SCREEN_MDPI](resourcemanager.md) = 160, [SCREEN_LDPI](resourcemanager.md) = 240, [SCREEN_XLDPI](resourcemanager.md) = 320,<br>[SCREEN_XXLDPI](resourcemanager.md) = 480, [SCREEN_XXXLDPI](resourcemanager.md) = 640<br>} | Enumerates screen density types. | 
| [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) { [DIRECTION_VERTICAL](resourcemanager.md) = 0, [DIRECTION_HORIZONTAL](resourcemanager.md) = 1 } | Enumerates screen orientations. | 
| [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) { [DARK](resourcemanager.md) = 0, [LIGHT](resourcemanager.md) = 1 } | Enumerates color modes. | 
| [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) {<br>[DEVICE_TYPE_PHONE](resourcemanager.md) = 0X00, [DEVICE_TYPE_TABLET](resourcemanager.md) = 0x01, [DEVICE_TYPE_CAR](resourcemanager.md) = 0x02, [DEVICE_TYPE_PC](resourcemanager.md) = 0x03,<br>[DEVICE_TYPE_TV](resourcemanager.md) = 0x04, [DEVICE_TYPE_WEARABLE](resourcemanager.md) = 0x06, [DEVICE_TYPE_2IN1](resourcemanager.md) = 0x07<br>} | Enumerates device types. | 

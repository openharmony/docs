# resmgr_common.h


## 概述

提供接口所需要的枚举类型和结构体。

**系统能力：** SystemCapability.Global.ResourceManager

**库：** libohresmgr.so

**起始版本：** 12

**相关模块：**[Resourcemanager](resourcemanager.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ResourceManager_Configuration](_resource_manager___configuration.md) | 设备状态的枚举。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) | 屏幕方向的枚举。  | 
| typedef enum [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) | 颜色模式的枚举。  | 
| typedef enum [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) | 设备类型的枚举。  | 
| typedef struct [ResourceManager_Configuration](_resource_manager___configuration.md) [ResourceManager_Configuration](resourcemanager.md#resourcemanager_configuration) | 设备状态的枚举。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ResourceManager_ErrorCode](resourcemanager.md#resourcemanager_errorcode) {<br/>[SUCCESS](resourcemanager.md) = 0, [ERROR_CODE_INVALID_INPUT_PARAMETER](resourcemanager.md) = 401, [ERROR_CODE_RES_ID_NOT_FOUND](resourcemanager.md) = 9001001, [ERROR_CODE_RES_NOT_FOUND_BY_ID](resourcemanager.md) = 9001002,<br/>[ERROR_CODE_RES_NAME_NOT_FOUND](resourcemanager.md) = 9001003, [ERROR_CODE_RES_NOT_FOUND_BY_NAME](resourcemanager.md) = 9001004, [ERROR_CODE_RES_PATH_INVALID](resourcemanager.md) = 9001005, [ERROR_CODE_RES_REF_TOO_MUCH](resourcemanager.md) = 9001006,<br/>[ERROR_CODE_RES_ID_FORMAT_ERROR](resourcemanager.md) = 9001007, [ERROR_CODE_RES_NAME_FORMAT_ERROR](resourcemanager.md) = 9001008, [ERROR_CODE_SYSTEM_RES_MANAGER_GET_FAILED](resourcemanager.md) = 9001009, [ERROR_CODE_OVERLAY_RES_PATH_INVALID](resourcemanager.md) = 9001010,<br/>[ERROR_CODE_OUT_OF_MEMORY](resourcemanager.md) = 9001100<br/>} | 资源管理错误码。  | 
| [ScreenDensity](resourcemanager.md#screendensity) {<br/>[SCREEN_SDPI](resourcemanager.md) = 120, [SCREEN_MDPI](resourcemanager.md) = 160, [SCREEN_LDPI](resourcemanager.md) = 240, [SCREEN_XLDPI](resourcemanager.md) = 320,<br/>[SCREEN_XXLDPI](resourcemanager.md) = 480, [SCREEN_XXXLDPI](resourcemanager.md) = 640<br/>} | 屏幕密度类型的枚举。  | 
| [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) { [DIRECTION_VERTICAL](resourcemanager.md) = 0, [DIRECTION_HORIZONTAL](resourcemanager.md) = 1 } | 屏幕方向的枚举。  | 
| [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) { [COLOR_MODE_DARK](resourcemanager.md) = 0, [COLOR_MODE_LIGHT](resourcemanager.md) = 1 } | 颜色模式的枚举。  | 
| [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) {<br/>[DEVICE_TYPE_PHONE](resourcemanager.md) = 0X00, [DEVICE_TYPE_TABLET](resourcemanager.md) = 0x01, [DEVICE_TYPE_CAR](resourcemanager.md) = 0x02, [DEVICE_TYPE_PC](resourcemanager.md) = 0x03,<br/>[DEVICE_TYPE_TV](resourcemanager.md) = 0x04, [DEVICE_TYPE_WEARABLE](resourcemanager.md) = 0x06, [DEVICE_TYPE_2IN1](resourcemanager.md) = 0x07<br/>} | 设备类型的枚举。  | 

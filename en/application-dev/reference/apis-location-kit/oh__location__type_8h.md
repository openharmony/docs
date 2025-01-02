# oh_location_type.h


## Overview

Defines common attributes of the location service.

\@kit LocationKit

**Library**: libohlocation.so

**System capability**: SystemCapability.Location.Location.Core

**Since**: 13

**Related module**: [Location](_location.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[Location_BasicInfo](_location___basic_info.md) | Defines the struct for the basic location information. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Location_ResultCode](_location.md#location_resultcode-1) [Location_ResultCode](_location.md#location_resultcode) | Enumerates error codes of the location service. | 
| typedef enum [Location_UseScene](_location.md#location_usescene-1) [Location_UseScene](_location.md#location_usescene) | Enumerates use scenes in a location request. | 
| typedef enum [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene-1) [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene) | Enumerates power consumption scenarios in a location request. | 
| typedef enum [Location_SourceType](_location.md#location_sourcetype-1) [Location_SourceType](_location.md#location_sourcetype) | Defines the source of location information. | 
| typedef struct [Location_BasicInfo](_location___basic_info.md) [Location_BasicInfo](_location.md#location_basicinfo) | Defines the struct for the basic location information. | 
| typedef struct [Location_Info](_location.md#location_info) [Location_Info](_location.md#location_info) | Defines the struct for the location information. | 
| typedef void(\* [Location_InfoCallback](_location.md#location_infocallback)) ([Location_Info](_location.md#location_info) \*location, void \*userData) | Defines the callback for receiving reported location information. | 
| typedef struct [Location_RequestConfig](_location.md#location_requestconfig) [Location_RequestConfig](_location.md#location_requestconfig) | Defines the struct for the location request configuration. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [Location_ResultCode](_location.md#location_resultcode) {<br>[LOCATION_SUCCESS](_location.md) = 0, [LOCATION_PERMISSION_DENIED](_location.md) = 201, [LOCATION_INVALID_PARAM](_location.md) = 401, [LOCATION_NOT_SUPPORTED](_location.md) = 801,<br>[LOCATION_SERVICE_UNAVAILABLE](_location.md) = 3301000, [LOCATION_SWITCH_OFF](_location.md) = 3301100<br>} | Enumerates error codes of the location service. | 
| [Location_UseScene](_location.md#location_usescene) { [LOCATION_USE_SCENE_NAVIGATION](_location.md) = 0x0401, [LOCATION_USE_SCENE_SPORT](_location.md) = 0x0402, [LOCATION_USE_SCENE_TRANSPORT](_location.md) = 0x0403, [LOCATION_USE_SCENE_DAILY_LIFE_SERVICE](_location.md) = 0x0404 } | Enumerates use scenes in a location request. | 
| [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene) { [LOCATION_HIGH_POWER_CONSUMPTION](_location.md) = 0x0601, [LOCATION_LOW_POWER_CONSUMPTION](_location.md) = 0x0602, [LOCATION_NO_POWER_CONSUMPTION](_location.md) = 0x0603 } | Enumerates power consumption scenarios in a location request. | 
| [Location_SourceType](_location.md#location_sourcetype) { [LOCATION_SOURCE_TYPE_GNSS](_location.md) = 1, [LOCATION_SOURCE_TYPE_NETWORK](_location.md) = 2, [LOCATION_SOURCE_TYPE_INDOOR](_location.md) = 3, [LOCATION_SOURCE_TYPE_RTK](_location.md) = 4 } | Defines the source of location information. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Location_BasicInfo](_location___basic_info.md) [OH_LocationInfo_GetBasicInfo](_location.md#oh_locationinfo_getbasicinfo) ([Location_Info](_location.md#location_info) \*location) | Obtains basic location information. | 
| [Location_ResultCode](_location.md#location_resultcode) [OH_LocationInfo_GetAdditionalInfo](_location.md#oh_locationinfo_getadditionalinfo) ([Location_Info](_location.md#location_info) \*location, char \*additionalInfo, uint32_t length) | Obtains the additional information in the location information. | 
| [Location_RequestConfig](_location.md#location_requestconfig) \* [OH_Location_CreateRequestConfig](_location.md#oh_location_createrequestconfig) (void) | Creates a **Location_RequestConfig** instance. | 
| void [OH_Location_DestroyRequestConfig](_location.md#oh_location_destroyrequestconfig) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig) | Destroys the **Location_RequestConfig** instance and reclaims the memory. | 
| void [OH_LocationRequestConfig_SetUseScene](_location.md#oh_locationrequestconfig_setusescene) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, [Location_UseScene](_location.md#location_usescene) useScene) | Sets the use scene in the location request configuration.<br>**useScene** takes precedence over **powerConsumptionScene** in [Location_RequestConfig](_location.md#location_requestconfig).<br>If **useScene** is set, **powerConsumptionScene** is invalid.<br>Otherwise, **powerConsumptionScene** takes effect.<br>If neither of the two parameters is set, **useScene** is set to [LOCATION_USE_SCENE_DAILY_LIFE_SERVICE](_location.md) by default,<br>and **powerConsumptionScene** is invalid.| 
| void [OH_LocationRequestConfig_SetPowerConsumptionScene](_location.md#oh_locationrequestconfig_setpowerconsumptionscene) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene) powerConsumptionScene) | Sets the power consumption scene in the location request configuration. | 
| void [OH_LocationRequestConfig_SetInterval](_location.md#oh_locationrequestconfig_setinterval) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, int interval) | Sets the location reporting interval in the location request configuration. | 
| void [OH_LocationRequestConfig_SetCallback](_location.md#oh_locationrequestconfig_setcallback) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, [Location_InfoCallback](_location.md#location_infocallback) callback, void \*userData) | Sets the callback function. | 

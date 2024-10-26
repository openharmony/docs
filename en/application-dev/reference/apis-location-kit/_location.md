# Location


## Overview

Provides APIs for querying the location switch status, and starting and stopping location.

**Since**: 13


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [oh_location.h](oh__location_8h.md) | Defines APIs for querying the location switch status, and starting and stopping location. | 
| [oh_location_type.h](oh__location__type_8h.md) | Defines common attributes of the location service. | 


### Structs

| Name| Description| 
| -------- | -------- |
| struct [Location_BasicInfo](_location___basic_info.md) | Struct for the basic location information. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Location_ResultCode](#location_resultcode-1) [Location_ResultCode](#location_resultcode) | Enumerates error codes of the location service. | 
| typedef enum [Location_UseScene](#location_usescene-1) [Location_UseScene](#location_usescene) | Enumerates use scenes in a location request. | 
| typedef enum [Location_PowerConsumptionScene](#location_powerconsumptionscene-1) [Location_PowerConsumptionScene](#location_powerconsumptionscene) | Enumerates power consumption scenarios in a location request. | 
| typedef enum [Location_SourceType](#location_sourcetype-1) [Location_SourceType](#location_sourcetype) | Defines the source of location information. | 
| typedef struct [Location_BasicInfo](_location___basic_info.md) [Location_BasicInfo](#location_basicinfo) | Defines the struct for the basic location information. | 
| typedef struct [Location_Info](#location_info) [Location_Info](#location_info) | Defines the struct for the location information. | 
| typedef void(\* [Location_InfoCallback](#location_infocallback)) ([Location_Info](#location_info) \*location, void \*userData) | Defines the callback for receiving reported location information. | 
| typedef struct [Location_RequestConfig](#location_requestconfig) [Location_RequestConfig](#location_requestconfig) | Defines the struct for the location request configuration. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [Location_ResultCode](#location_resultcode-1) {<br>LOCATION_SUCCESS = 0, LOCATION_PERMISSION_DENIED = 201, LOCATION_INVALID_PARAM = 401, LOCATION_NOT_SUPPORTED = 801,<br>LOCATION_SERVICE_UNAVAILABLE = 3301000, LOCATION_SWITCH_OFF = 3301100<br>} | Enumerates error codes of the location service. | 
| [Location_UseScene](#location_usescene-1) { LOCATION_USE_SCENE_NAVIGATION = 0x0401, LOCATION_USE_SCENE_SPORT = 0x0402, LOCATION_USE_SCENE_TRANSPORT = 0x0403, LOCATION_USE_SCENE_DAILY_LIFE_SERVICE = 0x0404 } | Enumerates use scenes in a location request. | 
| [Location_PowerConsumptionScene](#location_powerconsumptionscene-1) { LOCATION_HIGH_POWER_CONSUMPTION = 0x0601, LOCATION_LOW_POWER_CONSUMPTION = 0x0602, LOCATION_NO_POWER_CONSUMPTION = 0x0603 } | Enumerates power consumption scenarios in a location request. | 
| [Location_SourceType](#location_sourcetype-1) { LOCATION_SOURCE_TYPE_GNSS = 1, LOCATION_SOURCE_TYPE_NETWORK = 2, LOCATION_SOURCE_TYPE_INDOOR = 3, LOCATION_SOURCE_TYPE_RTK = 4 } | Defines the source of location information. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Location_ResultCode](#location_resultcode-1) [OH_Location_IsLocatingEnabled](#oh_location_islocatingenabled) (bool \*enabled) | Checks whether the location switch is enabled. | 
| [Location_ResultCode](#location_resultcode-1) [OH_Location_StartLocating](#oh_location_startlocating) (const [Location_RequestConfig](#location_requestconfig) \*requestConfig) | Starts locating and subscribes to location changes. | 
| [Location_ResultCode](#location_resultcode-1) [OH_Location_StopLocating](#oh_location_stoplocating) (const [Location_RequestConfig](#location_requestconfig) \*requestConfig) | Stops locating and unsubscribes from location changes. | 
| [Location_BasicInfo](_location___basic_info.md) [OH_LocationInfo_GetBasicInfo](#oh_locationinfo_getbasicinfo) ([Location_Info](#location_info) \*location) | Obtains basic location information. | 
| [Location_ResultCode](#location_resultcode-1) [OH_LocationInfo_GetAdditionalInfo](#oh_locationinfo_getadditionalinfo) ([Location_Info](#location_info) \*location, char \*additionalInfo, uint32_t length) | Obtains the additional information in the location information. | 
| [Location_RequestConfig](#location_requestconfig) \* [OH_Location_CreateRequestConfig](#oh_location_createrequestconfig) (void) | Creates a **Location_RequestConfig** instance. | 
| void [OH_Location_DestroyRequestConfig](#oh_location_destroyrequestconfig) ([Location_RequestConfig](#location_requestconfig) \*requestConfig) | Destroys the **Location_RequestConfig** instance and reclaims the memory. | 
| void [OH_LocationRequestConfig_SetUseScene](#oh_locationrequestconfig_setusescene) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, [Location_UseScene](#location_usescene) useScene) | Sets the use scene in the location request configuration.<br>**useScene** takes precedence over **powerConsumptionScene** in [Location_RequestConfig](#location_requestconfig).<br>If **useScene** is set, **powerConsumptionScene** is invalid.<br>Otherwise, **powerConsumptionScene** takes effect.<br>If neither of the two parameters is set, **useScene** is set to **LOCATION_USE_SCENE_DAILY_LIFE_SERVICE** by default,<br>and **powerConsumptionScene** is invalid.| 
| void [OH_LocationRequestConfig_SetPowerConsumptionScene](#oh_locationrequestconfig_setpowerconsumptionscene) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, [Location_PowerConsumptionScene](#location_powerconsumptionscene) powerConsumptionScene) | Sets the power consumption scene in the location request configuration. | 
| void [OH_LocationRequestConfig_SetInterval](#oh_locationrequestconfig_setinterval) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, int interval) | Sets the location reporting interval in the location request configuration. | 
| void [OH_LocationRequestConfig_SetCallback](#oh_locationrequestconfig_setcallback) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, [Location_InfoCallback](#location_infocallback) callback, void \*userData) | Sets the callback function. | 


## Type Description


### Location_BasicInfo

```
typedef struct Location_BasicInfo Location_BasicInfo
```
**Description**
Defines the struct for the basic location information.

**Since**: 13


### Location_Info

```
typedef struct Location_Info Location_Info
```
**Description**
Defines the struct for the location information.

**Since**: 13


### Location_InfoCallback

```
typedef void(* Location_InfoCallback) (Location_Info *location, void *userData)
```
**Description**
Defines the callback for receiving reported location information.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| location | Pointer to the [Location_Info](#location_info) instance, which carries the latest location information.<br>The memory occupied by the instance will be reclaimed when [Location_InfoCallback](#location_infocallback) is complete.<br>Before calling this API, call APIs such as [OH_LocationInfo_GetBasicInfo](#oh_locationinfo_getbasicinfo) to obtain the location information.| 
| userData | Pointer to the **userData** struct or object. This parameter is passed in through [OH_LocationRequestConfig_SetCallback](#oh_locationrequestconfig_setcallback).| 


### Location_PowerConsumptionScene

```
typedef enum Location_PowerConsumptionScene Location_PowerConsumptionScene
```
**Description**
Enumerates power consumption scenarios in a location request.

**Since**: 13


### Location_RequestConfig

```
typedef struct Location_RequestConfig Location_RequestConfig
```
**Description**
Defines the struct for the location request configuration.

**Since**: 13


### Location_ResultCode

```
typedef enum Location_ResultCode Location_ResultCode
```
**Description**
Enumerates error codes of the location service.

**Since**: 13


### Location_SourceType

```
typedef enum Location_SourceType Location_SourceType
```
**Description**
Defines the source of location information.

**Since**: 13


### Location_UseScene

```
typedef enum Location_UseScene Location_UseScene
```
**Description**
Enumerates use scenes in a location request.

**Since**: 13


## Enum Description


### Location_PowerConsumptionScene

```
enum Location_PowerConsumptionScene
```
**Description**
Enumerates power consumption scenarios in a location request.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| LOCATION_HIGH_POWER_CONSUMPTION  | High power consumption.<br>The mode mainly uses the GNSS positioning technology. The system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results.<br>During the continuous location process, the network positioning technology is used if the GNSS location result cannot be obtained within 30 seconds.<br>This policy can lead to significant hardware resource consumption and power consumption.| 
| LOCATION_LOW_POWER_CONSUMPTION  | Low power consumption.<br>This mode is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>It mainly uses the network positioning technology and therefore the power consumption is relatively low.| 
| LOCATION_NO_POWER_CONSUMPTION  | No power consumption.<br>Your application does not proactively start the location service. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. | 


### Location_ResultCode

```
enum Location_ResultCode
```
**Description**
Enumerates error codes of the location service.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| LOCATION_SUCCESS  | Operation succeeded.  | 
| LOCATION_PERMISSION_DENIED  | Permission verification has failed.  | 
| LOCATION_INVALID_PARAM  | Parameter error.<br>Possible causes: 1. The input parameter is a null pointer. 2. The parameter value is out of the value range.| 
| LOCATION_NOT_SUPPORTED  | Function not supported due to limited device capabilities.  | 
| LOCATION_SERVICE_UNAVAILABLE  | Location service unavailable.  | 
| LOCATION_SWITCH_OFF  | Location switch disabled.  | 


### Location_SourceType

```
enum Location_SourceType
```
**Description**
Defines the source of location information.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| LOCATION_SOURCE_TYPE_GNSS  | GNSS positioning technology.  | 
| LOCATION_SOURCE_TYPE_NETWORK  | Network positioning technology.  | 
| LOCATION_SOURCE_TYPE_INDOOR  | Indoor high-precision positioning technology.  | 
| LOCATION_SOURCE_TYPE_RTK  | Outdoor high-precision positioning technology.  | 


### Location_UseScene

```
enum Location_UseScene
```
**Description**
Enumerates use scenes in a location request.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| LOCATION_USE_SCENE_NAVIGATION  | Navigation scenario.<br>This option is applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.| 
| LOCATION_USE_SCENE_SPORT  | Sport scenario.<br>This option is applicable when your application needs to record user trajectories, for example, the track recording function of sports applications.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.| 
| LOCATION_USE_SCENE_TRANSPORT  | Travel scenario.<br>This option is applicable to user travel scenarios, such as taxi hailing and public transportation.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.| 
| LOCATION_USE_SCENE_DAILY_LIFE_SERVICE  | Daily life services.<br>This option is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>It mainly uses the network positioning technology and therefore the power consumption is relatively low.| 


## Function Description


### OH_Location_CreateRequestConfig()

```
Location_RequestConfig* OH_Location_CreateRequestConfig (void )
```
**Description**
Creates a **Location_RequestConfig** instance.

**Since**: 13

**Returns**

Pointer to the [Location_RequestConfig](#location_requestconfig) instance.

If **NULL** is returned, the operation has failed. The probable cause is that the application address space is full.


### OH_Location_DestroyRequestConfig()

```
void OH_Location_DestroyRequestConfig (Location_RequestConfig * requestConfig)
```
**Description**
Destroys the **Location_RequestConfig** instance and reclaims the memory.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestConfig | Pointer to the [Location_RequestConfig](#location_requestconfig) instance.<br>The instance is created by [OH_Location_CreateRequestConfig](#oh_location_createrequestconfig).| 


### OH_Location_IsLocatingEnabled()

```
Location_ResultCode OH_Location_IsLocatingEnabled (bool * enabled)
```
**Description**
Checks whether the location switch is enabled.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| enabled | Pointer of the bool type, which is used to receive the location switch status.<br>If the value is **true**, the location switch is enabled. If the value is **false**, the location switch is disabled.<br>A non-null pointer must be passed in. Otherwise, an error is returned.| 

**Returns**

Operation result. For details, see [Location_ResultCode](#location_resultcode).

**LOCAION_SUCCESS**: The location switch status is successfully queried.

**LOCATION_INVALID_PARAM**: The input parameter is a null pointer.

**LOCATION_SERVICE_UNAVAILABLE**: The location switch status fails to be queried because the location service is abnormal.


### OH_Location_StartLocating()

```
Location_ResultCode OH_Location_StartLocating (const Location_RequestConfig * requestConfig)
```
**Description**
Starts locating and subscribes to location changes.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestConfig | Pointer to the **Location_RequestConfig** instance. This parameter is used to specify the location scene and location reporting interval.<br>For details, see [Location_RequestConfig](#location_requestconfig). You can use [OH_Location_CreateRequ·estConfig](#oh_location_createrequestconfig) to create a **Location_RequestConfig** instance.| 

**Returns**

Operation result. For details, see [Location_ResultCode](#location_resultcode).

**LOCAION_SUCCESS**: The location function is started successfully.

**LOCATION_INVALID_PARAM**: The input parameter **requestConfig** is a null pointer.

**LOCATION_PERMISSION_DENIED**: Permission verification has failed.

**LOCATION_NOT_SUPPORTED**: The device does not support the location function.

**LOCATION_SERVICE_UNAVAILABLE**: The location service is abnormal.

**LOCATION_SWITCH_OFF**: The location function fails to be started because the location switch is disabled.

**Required Permissions**

ohos.permission.APPROXIMATELY_LOCATION


### OH_Location_StopLocating()

```
Location_ResultCode OH_Location_StopLocating (const Location_RequestConfig * requestConfig)
```
**Description**
Stops locating and unsubscribes from location changes.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestConfig | Pointer to the **Location_RequestConfig** instance.<br>This parameter must be the same as the pointer to **requestConfig** in [OH_Location_StartLocating](#oh_location_startlocating).<br>For details, see [Location_RequestConfig](#location_requestconfig).<br>A non-null pointer must be passed in. Otherwise, an error is returned.| 

**Returns**

Operation result. For details, see [Location_ResultCode](#location_resultcode).

**LOCAION_SUCCESS**: The location function is stopped successfully.

LOCATION_INVALID_PARAM:
- The input parameter is a null pointer.

- The input pointer is not the same as the pointer to **requestConfig** in [OH_Location_StartLocating](#oh_location_startlocating).

   **LOCATION_PERMISSION_DENIED**: Permission verification has failed.

   **LOCATION_NOT_SUPPORTED**: The device does not support the location function.

   **LOCATION_SERVICE_UNAVAILABLE**: The location service is abnormal.

   **LOCATION_SWITCH_OFF**: The location switch is disabled.

**Required Permissions**

ohos.permission.APPROXIMATELY_LOCATION


### OH_LocationInfo_GetAdditionalInfo()

```
Location_ResultCode OH_LocationInfo_GetAdditionalInfo (Location_Info * location, char * additionalInfo, uint32_t length )
```
**Description**
Obtains the additional information in the location information.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| location | Pointer to the [Location_Info](#location_info) instance.<br>A non-null pointer needs to be passed in. This pointer can be obtained from [Location_InfoCallback](#location_infocallback).| 
| additionalInfo | Non-null pointer of the char type. This variable is used to store the additional location information in JSON format.<br>The pointer and the corresponding memory are created by the caller. It is recommended that the memory be greater than or equal to 256 bytes.<br>If a null pointer is passed in, an error code is returned.| 
| length | Memory size of **additionalInfo**. | 

**Returns**

Operation result. For details, see [Location_ResultCode](#location_resultcode).

**LOCAION_SUCCESS**: The additional location information is successfully obtained.

LOCATION_INVALID_PARAM:
- The input parameter **location** or **additionalInfo** is a null pointer.

- The value of the input parameter **length** is too small, that is, the memory size of **additionalInfo** is too small, which is unable to save the complete additional information.


### OH_LocationInfo_GetBasicInfo()

```
Location_BasicInfo OH_LocationInfo_GetBasicInfo (Location_Info * location)
```
**Description**
Obtains basic location information.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| location | Pointer to the [Location_Info](#location_info) instance.<br>A non-null pointer needs to be passed in. This pointer can be obtained from [Location_InfoCallback](#location_infocallback).| 

**Returns**

Struct for the basic location information. For details, see [Location_BasicInfo](_location___basic_info.md).


### OH_LocationRequestConfig_SetCallback()

```
void OH_LocationRequestConfig_SetCallback (Location_RequestConfig * requestConfig, Location_InfoCallback callback, void * userData )
```
**Description**
Sets the callback function.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestConfig | Pointer to the [Location_RequestConfig](#location_requestconfig) instance.<br>The instance is created by [OH_Location_CreateRequestConfig](#oh_location_createrequestconfig).| 
| callback | Pointer to the callback function, which is used to receive location information changes.<br>For details, see [Location_InfoCallback](#location_infocallback).| 
| userData | Pointer to the **userData** instance. This pointer is returned to the caller as an input parameter when the callback function is executed.| 


### OH_LocationRequestConfig_SetInterval()

```
void OH_LocationRequestConfig_SetInterval (Location_RequestConfig * requestConfig, int interval )
```
**Description**
Sets the location reporting interval in the location request configuration.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestConfig | Pointer to the [Location_RequestConfig](#location_requestconfig) instance.<br>The instance is created by [OH_Location_CreateRequestConfig](#oh_location_createrequestconfig).| 
| interval | Location reporting interval, in seconds. The value must be greater than or equal to **1**. The default value is **1**. | 


### OH_LocationRequestConfig_SetPowerConsumptionScene()

```
void OH_LocationRequestConfig_SetPowerConsumptionScene (Location_RequestConfig * requestConfig, Location_PowerConsumptionScene powerConsumptionScene )
```
**Description**
Sets the power consumption scene in the location request configuration.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestConfig | Pointer to the [Location_RequestConfig](#location_requestconfig) instance.<br>The instance is created by [OH_Location_CreateRequestConfig](#oh_location_createrequestconfig).| 
| powerConsumptionScene | Power consumption scene in the location request.<br>The default value is **LOCATION_LOW_POWER_CONSUMPTION**.<br>For details, see [Location_PowerConsumptionScene](#location_powerconsumptionscene).| 


### OH_LocationRequestConfig_SetUseScene()

```
void OH_LocationRequestConfig_SetUseScene (Location_RequestConfig * requestConfig, Location_UseScene useScene )
```
**Description**
Sets the use scene in the location request configuration.

**useScene** takes precedence over other parameters in [Location_RequestConfig](#location_requestconfig).

If **useScene** is set, **powerConsumptionScene** is invalid.

Otherwise, **powerConsumptionScene** takes effect.

If neither of the two parameters is set, **useScene** is set to LOCATION_USE_SCENE_DAILY_LIFE_SERVICE by default,

and **powerConsumptionScene** is invalid.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestConfig | Pointer to the [Location_RequestConfig](#location_requestconfig) instance.<br>The instance is created by [OH_Location_CreateRequestConfig](#oh_location_createrequestconfig).| 
| useScene | Use scene in the location request.<br>The default value is **LOCATION_USE_SCENE_DAILY_LIFE_SERVICE**.<br>For details, see [Location_UseScene](#location_usescene).| 

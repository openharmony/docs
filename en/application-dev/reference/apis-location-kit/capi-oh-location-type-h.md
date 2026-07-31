# oh_location_type.h

<!--Kit: Location Kit-->
<!--Subsystem: Location-->
<!--Owner: @liu-binjun-->
<!--Designer: @liu-binjun-->
<!--Tester: @mhy123456789-->
<!--Adviser: @RayShih-->
<!-- md-trans-meta sourceCommit=0a518b37f78bdd259be3f4c562486aca296b2ff8 translatedAt=2026-07-31T06:40:51.513Z pushedAt=2026-07-31T07:55:06.921Z -->

## Overview

Defines common attributes of the location service.

**Reference file**: <LocationKit/oh_location_type.h>

**Library**: liblocation_ndk.so

**System capability**: SystemCapability.Location.Location.Core

**Since**: 13

**Related module**: [Location](capi-location.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Location_BasicInfo](capi-location-location-basicinfo.md) | Location_BasicInfo | Defines the struct for the basic location information.|
| [Location_Info](capi-location-location-info.md) | Location_Info | Defines the struct for the location information.|
| [Location_RequestConfig](capi-location-location-requestconfig.md) | Location_RequestConfig | Defines the struct for the location request configuration.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Location_ResultCode](#location_resultcode) | Location_ResultCode | Enumerates error codes of the location service.|
| [Location_UseScene](#location_usescene) | Location_UseScene | Enumerates use scenes in a location request.|
| [Location_PowerConsumptionScene](#location_powerconsumptionscene) | Location_PowerConsumptionScene | Enumerates power consumption scenarios in a location request.|
| [Location_SourceType](#location_sourcetype) | Location_SourceType | Defines the source of location information.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [bool OH_LocationInfo_IsFromMock(Location_Info* location)](#oh_locationinfo_isfrommock) | - | Checks whether the location information is from the mock location feature.<br />**Since:** 26.0.0 |
| [Location_BasicInfo OH_LocationInfo_GetBasicInfo(Location_Info* location)](#oh_locationinfo_getbasicinfo) | - | Obtains basic location information.|
| [Location_ResultCode OH_LocationInfo_GetAdditionalInfo(Location_Info* location, char* additionalInfo, uint32_t length)](#oh_locationinfo_getadditionalinfo) | - | Obtains the additional information in the location information.|
| [typedef void (\*Location_InfoCallback)(Location_Info* location, void* userData)](#location_infocallback) | Location_InfoCallback | Defines the callback for receiving reported location information.|
| [Location_RequestConfig* OH_Location_CreateRequestConfig(void)](#oh_location_createrequestconfig) | - | Creates a **Location_RequestConfig** instance.|
| [void OH_Location_DestroyRequestConfig(Location_RequestConfig* requestConfig)](#oh_location_destroyrequestconfig) | - | Destroys the **Location_RequestConfig** instance and reclaims the memory.|
| [void OH_LocationRequestConfig_SetUseScene(Location_RequestConfig* requestConfig, Location_UseScene useScene)](#oh_locationrequestconfig_setusescene) | - | Sets the use scene in the location request configuration.<br> **useScene** takes precedence over **powerConsumptionScene** in [Location_RequestConfig](capi-location-location-requestconfig.md).<br> If **useScene** is set, **powerConsumptionScene** is invalid.<br> Otherwise, **powerConsumptionScene** takes effect.<br> If neither of the two parameters is set, the default value of **useScene** is [LOCATION_USE_SCENE_DAILY_LIFE_SERVICE](capi-oh-location-type-h.md#location_usescene) and **powerConsumptionScene** is invalid.<br>|
| [void OH_LocationRequestConfig_SetPowerConsumptionScene(Location_RequestConfig* requestConfig, Location_PowerConsumptionScene powerConsumptionScene)](#oh_locationrequestconfig_setpowerconsumptionscene) | - | Sets the power consumption scene in the location request configuration.|
| [void OH_LocationRequestConfig_SetInterval(Location_RequestConfig* requestConfig, int interval)](#oh_locationrequestconfig_setinterval) | - | Sets the location reporting interval in the location request configuration.|
| [void OH_LocationRequestConfig_SetCallback(Location_RequestConfig* requestConfig, Location_InfoCallback callback, void* userData)](#oh_locationrequestconfig_setcallback) | - | Sets the callback function.|

## Enum Description

### Location_ResultCode

```c
enum Location_ResultCode
```

**Description**

Enumerates error codes of the location service.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| LOCATION_SUCCESS = 0 | Operation success.|
| LOCATION_PERMISSION_DENIED = 201 | Permission denied.|
| LOCATION_INVALID_PARAM = 401 | The parameter is invalid.<br> Possible causes: 1. The input parameter is a null pointer. 2. The parameter value is out of the value range.|
| LOCATION_NOT_SUPPORTED = 801 | Function not supported due to limited device capabilities.|
| LOCATION_SERVICE_UNAVAILABLE = 3301000 | Location service unavailable.|
| LOCATION_SWITCH_OFF = 3301100 | Location switch disabled.|

### Location_UseScene

```c
enum Location_UseScene
```

**Description**

Enumerates use scenes in a location request.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| LOCATION_USE_SCENE_NAVIGATION = 0x0401 | Navigation scenario.<br> This option is applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking.<br> This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| LOCATION_USE_SCENE_SPORT = 0x0402 | Sport scenario.<br> Applicable when your application needs to record user trajectories, for example, the track recording function of sports applications.<br> This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| LOCATION_USE_SCENE_TRANSPORT = 0x0403 | Travel scenario.<br> This option is applicable to user travel scenarios, such as taxi hailing and public transportation.<br> This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| LOCATION_USE_SCENE_DAILY_LIFE_SERVICE = 0x0404 | Daily life services.<br> This option is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br> It mainly uses the network positioning technology and therefore the power consumption is relatively low.|

### Location_PowerConsumptionScene

```c
enum Location_PowerConsumptionScene
```

**Description**

Enumerates power consumption scenarios in a location request.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| LOCATION_HIGH_POWER_CONSUMPTION = 0x0601 | High power consumption.<br> The mode mainly uses the GNSS positioning technology. The system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results.<br> During the continuous location process, the network positioning technology is used if the GNSS location result cannot be obtained within 30 seconds.<br> This policy can lead to significant hardware resource consumption and power consumption.|
| LOCATION_LOW_POWER_CONSUMPTION = 0x0602 | Low power consumption.<br> This mode is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br> It mainly uses the network positioning technology and therefore the power consumption is relatively low.|
| LOCATION_NO_POWER_CONSUMPTION = 0x0603 | No power consumption.<br> Your application does not proactively start the location service. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. |

### Location_SourceType

```c
enum Location_SourceType
```

**Description**

Defines the source of location information.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| LOCATION_SOURCE_TYPE_GNSS = 1 | GNSS positioning technology.|
| LOCATION_SOURCE_TYPE_NETWORK = 2 | Network positioning technology.|
| LOCATION_SOURCE_TYPE_INDOOR = 3 | Indoor high-precision positioning technology.|
| LOCATION_SOURCE_TYPE_RTK = 4 | Outdoor high-precision positioning technology.|

## Function Description

### OH_LocationInfo_IsFromMock()

```c
bool OH_LocationInfo_IsFromMock(Location_Info* location)
```

**Description**

Checks whether the location information is from the mock location feature.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [Location_Info](capi-location-location-info.md)* location | Pointer to the location information struct.<br> A non-null pointer must be passed in, which can be obtained in [Location_InfoCallback](capi-oh-location-type-h.md#location_infocallback). |

**Returns**

| Type | Description |
| -- | -- |
| bool | Whether the location is from the mock location feature.<br> The value **true** indicates that the location is from the mock location feature, and **false** indicates that the location is from the real system location result.<br> |

### OH_LocationInfo_GetBasicInfo()

```c
Location_BasicInfo OH_LocationInfo_GetBasicInfo(Location_Info* location)
```

**Description**

Obtains basic location information.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_Info](capi-location-location-info.md)* location | Pointer to the location information struct.<br> A non-null pointer must be passed. The pointer can be obtained from [Location_InfoCallback](capi-oh-location-type-h.md#location_infocallback).|

**Returns**

| Type| Description|
| -- | -- |
| [Location_BasicInfo](capi-location-location-basicinfo.md) | Struct for the basic location information. For details, see [Location_BasicInfo](capi-location-location-basicinfo.md).|

### OH_LocationInfo_GetAdditionalInfo()

```c
Location_ResultCode OH_LocationInfo_GetAdditionalInfo(Location_Info* location, char* additionalInfo, uint32_t length)
```

**Description**

Obtains the additional information in the location information.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_Info](capi-location-location-info.md)* location | Pointer to the location information struct.<br> A non-null pointer needs to be passed in. This pointer can be obtained from [Location_InfoCallback](capi-oh-location-type-h.md#location_infocallback).|
| char* additionalInfo | Non-null pointer of the char type. This variable is used to store the additional location information in JSON format.<br> The pointer and the corresponding memory are created by the caller. It is recommended that the memory be greater than or equal to 256 bytes.<br> If a null pointer is passed in, an error code is returned.|
| uint32_t length | Memory size of **additionalInfo**.|

**Returns**

| Type| Description|
| -- | -- |
| [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode) | Operation result. For details, see [Location_ResultCode](capi-oh-location-type-h.md#location_resultcode).<br>     [LOCATION_SUCCESS](capi-oh-location-type-h.md#location_resultcode) if additional information obtained successfully;<br>     [LOCATION_INVALID_PARAM](capi-oh-location-type-h.md#location_resultcode) if the input **location** or **additionalInfo** is a null pointer,<br>         2. or the value of the input **length** is too small, that is, the memory size of **additionalInfo** is too small, which is unable to save the complete additional information.|

### Location_InfoCallback()

```c
typedef void (*Location_InfoCallback)(Location_Info* location, void* userData)
```

**Description**

Defines the callback for receiving reported location information.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_Info](capi-location-location-info.md)* location | Pointer to the [Location_Info](capi-location-location-info.md) instance, which carries the latest location information.<br> The memory occupied by the instance will be reclaimed when [Location_InfoCallback](capi-oh-location-type-h.md#location_infocallback) is complete. Before that, call APIs such as [OH_LocationInfo_GetBasicInfo](capi-oh-location-type-h.md#oh_locationinfo_getbasicinfo) to obtain the location information.|
|  void* userData | Pointer to the **userData** struct or object. This parameter is passed in through [OH_LocationRequestConfig_SetCallback](capi-oh-location-type-h.md#oh_locationrequestconfig_setcallback).|

### OH_Location_CreateRequestConfig()

```c
Location_RequestConfig* OH_Location_CreateRequestConfig(void)
```

**Description**

Creates a **Location_RequestConfig** instance.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [Location_RequestConfig*](capi-location-location-requestconfig.md) | Pointer to the [Location_RequestConfig](capi-location-location-requestconfig.md) instance.<br> If **NULL** is returned, the operation has failed. The probable cause is that the application address space is full.|

### OH_Location_DestroyRequestConfig()

```c
void OH_Location_DestroyRequestConfig(Location_RequestConfig* requestConfig)
```

**Description**

Destroys the **Location_RequestConfig** instance and reclaims the memory.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_RequestConfig](capi-location-location-requestconfig.md)* requestConfig | Pointer to the [Location_RequestConfig](capi-location-location-requestconfig.md) instance,<br> which is created using [OH_Location_CreateRequestConfig](capi-oh-location-type-h.md#oh_location_createrequestconfig).|

### OH_LocationRequestConfig_SetUseScene()

```c
void OH_LocationRequestConfig_SetUseScene(Location_RequestConfig* requestConfig, Location_UseScene useScene)
```

**Description**

Sets the use scene in the location request configuration.<br> **useScene** takes precedence over **powerConsumptionScene** in [Location_RequestConfig](capi-location-location-requestconfig.md).<br> If **useScene** is set, **powerConsumptionScene** is invalid.<br> Otherwise, **powerConsumptionScene** takes effect.<br> If neither of the two parameters is set, the default value of **useScene** is [LOCATION_USE_SCENE_DAILY_LIFE_SERVICE](capi-oh-location-type-h.md#location_usescene) and **powerConsumptionScene** is invalid.<br>

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_RequestConfig](capi-location-location-requestconfig.md)* requestConfig | Pointer to the [Location_RequestConfig](capi-location-location-requestconfig.md) instance,<br> which is created using [OH_Location_CreateRequestConfig](capi-oh-location-type-h.md#oh_location_createrequestconfig).|
| [Location_UseScene](capi-oh-location-type-h.md#location_usescene) useScene | Use scene in the location request.<br> The default value is [LOCATION_USE_SCENE_DAILY_LIFE_SERVICE](capi-oh-location-type-h.md#location_usescene).<br> For details, see [Location_UseScene](capi-oh-location-type-h.md#location_usescene).|

### OH_LocationRequestConfig_SetPowerConsumptionScene()

```c
void OH_LocationRequestConfig_SetPowerConsumptionScene(Location_RequestConfig* requestConfig, Location_PowerConsumptionScene powerConsumptionScene)
```

**Description**

Sets the power consumption scene in the location request configuration.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_RequestConfig](capi-location-location-requestconfig.md)* requestConfig | Pointer to the [Location_RequestConfig](capi-location-location-requestconfig.md) instance,<br> which is created using [OH_Location_CreateRequestConfig](capi-oh-location-type-h.md#oh_location_createrequestconfig).|
| [Location_PowerConsumptionScene](capi-oh-location-type-h.md#location_powerconsumptionscene) powerConsumptionScene | Power consumption scene in the location request.<br> The default value is [LOCATION_LOW_POWER_CONSUMPTION](capi-oh-location-type-h.md#location_powerconsumptionscene).<br> For details, see [Location_PowerConsumptionScene](capi-oh-location-type-h.md#location_powerconsumptionscene).|

### OH_LocationRequestConfig_SetInterval()

```c
void OH_LocationRequestConfig_SetInterval(Location_RequestConfig* requestConfig, int interval)
```

**Description**

Sets the location reporting interval in the location request configuration.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_RequestConfig](capi-location-location-requestconfig.md)* requestConfig | Pointer to the [Location_RequestConfig](capi-location-location-requestconfig.md) instance,<br> which is created using [OH_Location_CreateRequestConfig](capi-oh-location-type-h.md#oh_location_createrequestconfig).|
| int interval | Location reporting interval, in seconds. The value must be greater than or equal to **1**. The default value is **1**.|

### OH_LocationRequestConfig_SetCallback()

```c
void OH_LocationRequestConfig_SetCallback(Location_RequestConfig* requestConfig, Location_InfoCallback callback, void* userData)
```

**Description**

Sets a callback for sign generation.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [Location_RequestConfig](capi-location-location-requestconfig.md)* requestConfig | Pointer to the [Location_RequestConfig](capi-location-location-requestconfig.md) instance,<br> which is created using [OH_Location_CreateRequestConfig](capi-oh-location-type-h.md#oh_location_createrequestconfig).|
| [Location_InfoCallback](capi-oh-location-type-h.md#location_infocallback) callback | Pointer to the callback function, which is used to receive location information changes.<br> For details, see [Location_InfoCallback](capi-oh-location-type-h.md#location_infocallback).|
| void* userData | Pointer to the **userData** struct or object. This pointer is returned to the caller as an input parameter when the callback function is executed.|
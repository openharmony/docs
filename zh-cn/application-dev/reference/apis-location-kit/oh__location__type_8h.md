# oh_location_type.h
<!--Kit: Location Kit-->
<!--Subsystem: Location-->
<!--Owner: @liu-binjun-->
<!--Designer: @liu-binjun-->
<!--Tester: @mhy123456789-->
<!--Adviser: @RayShih-->

## 概述

定义位置服务常用的属性。

\@kit LocationKit

**库：** liblocation_ndk.so

**系统能力：** SystemCapability.Location.Location.Core

**起始版本：** 13

**相关模块：**[Location](_location.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Location_BasicInfo](_location___basic_info.md) | 定义位置基本信息的结构体。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Location_ResultCode](_location.md#location_resultcode-1) [Location_ResultCode](_location.md#location_resultcode) | 定义位置服务的错误码。  | 
| typedef enum [Location_UseScene](_location.md#location_usescene-1) [Location_UseScene](_location.md#location_usescene) | 定义位置请求中的用户活动场景类型。  | 
| typedef enum [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene-1) [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene) | 定义位置请求中的功耗场景类型。  | 
| typedef enum [Location_SourceType](_location.md#location_sourcetype-1) [Location_SourceType](_location.md#location_sourcetype) | 定义位置信息的来源。  | 
| typedef struct [Location_BasicInfo](_location___basic_info.md) [Location_BasicInfo](_location.md#location_basicinfo) | 定义位置基本信息的结构体。  | 
| typedef struct [Location_Info](_location.md#location_info) [Location_Info](_location.md#location_info) | 定义位置信息的结构体。  | 
| typedef void(\* [Location_InfoCallback](_location.md#location_infocallback)) ([Location_Info](_location.md#location_info) \*location, void \*userData) | 用于接收位置上报的回调函数。  | 
| typedef struct [Location_RequestConfig](_location.md#location_requestconfig) [Location_RequestConfig](_location.md#location_requestconfig) | 定义位置请求参数的结构体。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Location_ResultCode](_location.md#location_resultcode) {<br/>[LOCATION_SUCCESS](_location.md) = 0, [LOCATION_PERMISSION_DENIED](_location.md) = 201, [LOCATION_INVALID_PARAM](_location.md) = 401, [LOCATION_NOT_SUPPORTED](_location.md) = 801,<br/>[LOCATION_SERVICE_UNAVAILABLE](_location.md) = 3301000, [LOCATION_SWITCH_OFF](_location.md) = 3301100<br/>} | 定义位置服务的错误码。  | 
| [Location_UseScene](_location.md#location_usescene) { [LOCATION_USE_SCENE_NAVIGATION](_location.md) = 0x0401, [LOCATION_USE_SCENE_SPORT](_location.md) = 0x0402, [LOCATION_USE_SCENE_TRANSPORT](_location.md) = 0x0403, [LOCATION_USE_SCENE_DAILY_LIFE_SERVICE](_location.md) = 0x0404 } | 定义位置请求中的用户活动场景类型。  | 
| [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene) { [LOCATION_HIGH_POWER_CONSUMPTION](_location.md) = 0x0601, [LOCATION_LOW_POWER_CONSUMPTION](_location.md) = 0x0602, [LOCATION_NO_POWER_CONSUMPTION](_location.md) = 0x0603 } | 定义位置请求中的功耗场景类型。  | 
| [Location_SourceType](_location.md#location_sourcetype) { [LOCATION_SOURCE_TYPE_GNSS](_location.md) = 1, [LOCATION_SOURCE_TYPE_NETWORK](_location.md) = 2, [LOCATION_SOURCE_TYPE_INDOOR](_location.md) = 3, [LOCATION_SOURCE_TYPE_RTK](_location.md) = 4 } | 定义位置信息的来源。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Location_BasicInfo](_location___basic_info.md) [OH_LocationInfo_GetBasicInfo](_location.md#oh_locationinfo_getbasicinfo) ([Location_Info](_location.md#location_info) \*location) | 获取位置基本信息。  | 
| [Location_ResultCode](_location.md#location_resultcode) [OH_LocationInfo_GetAdditionalInfo](_location.md#oh_locationinfo_getadditionalinfo) ([Location_Info](_location.md#location_info) \*location, char \*additionalInfo, uint32_t length) | 获取位置信息中的附加信息。  | 
| [Location_RequestConfig](_location.md#location_requestconfig) \* [OH_Location_CreateRequestConfig](_location.md#oh_location_createrequestconfig) (void) | 创建一个位置请求参数结构体实例。  | 
| void [OH_Location_DestroyRequestConfig](_location.md#oh_location_destroyrequestconfig) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig) | 销毁位置请求参数实例并回收内存。  | 
| void [OH_LocationRequestConfig_SetUseScene](_location.md#oh_locationrequestconfig_setusescene) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, [Location_UseScene](_location.md#location_usescene) useScene) | 设置位置请求参数中的用户活动场景。<br/>位置请求参数[Location_RequestConfig](_location.md#location_requestconfig)中以useScene优先。<br/>如果设置了useScene，则powerConsumptionScene参数无效。<br/>如果未设置useScene，设置了powerConsumptionScene则该参数生效。<br/>如果两个参数都未设置，则默认useScene为[LOCATION_USE_SCENE_DAILY_LIFE_SERVICE](_location.md)，<br/>powerConsumptionScene参数无效。 | 
| void [OH_LocationRequestConfig_SetPowerConsumptionScene](_location.md#oh_locationrequestconfig_setpowerconsumptionscene) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, [Location_PowerConsumptionScene](_location.md#location_powerconsumptionscene) powerConsumptionScene) | 设置位置请求参数中的功耗场景。  | 
| void [OH_LocationRequestConfig_SetInterval](_location.md#oh_locationrequestconfig_setinterval) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, int interval) | 设置位置请求参数中的位置上报间隔。  | 
| void [OH_LocationRequestConfig_SetCallback](_location.md#oh_locationrequestconfig_setcallback) ([Location_RequestConfig](_location.md#location_requestconfig) \*requestConfig, [Location_InfoCallback](_location.md#location_infocallback) callback, void \*userData) | 设置回调函数。  | 

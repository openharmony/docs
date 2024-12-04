# Location


## 概述

提供用于查询位置开关状态、启动和停止定位的功能。

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_location.h](oh__location_8h.md) | 定义查询位置开关状态、启动定位、停止定位的接口。  | 
| [oh_location_type.h](oh__location__type_8h.md) | 定义位置服务常用的属性。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct [Location_BasicInfo](_location___basic_info.md) | 定义位置基本信息的结构体。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Location_ResultCode](#location_resultcode-1) [Location_ResultCode](#location_resultcode) | 定义位置服务的错误码。  | 
| typedef enum [Location_UseScene](#location_usescene-1) [Location_UseScene](#location_usescene) | 定义位置请求中的用户活动场景类型。  | 
| typedef enum [Location_PowerConsumptionScene](#location_powerconsumptionscene-1) [Location_PowerConsumptionScene](#location_powerconsumptionscene) | 定义位置请求中的功耗场景类型。  | 
| typedef enum [Location_SourceType](#location_sourcetype-1) [Location_SourceType](#location_sourcetype) | 定义位置信息的来源。  | 
| typedef struct [Location_BasicInfo](_location___basic_info.md) [Location_BasicInfo](#location_basicinfo) | 定义位置基本信息的结构体。  | 
| typedef struct [Location_Info](#location_info) [Location_Info](#location_info) | 定义位置信息的结构体。  | 
| typedef void(\* [Location_InfoCallback](#location_infocallback)) ([Location_Info](#location_info) \*location, void \*userData) | 用于接收位置上报的回调函数。  | 
| typedef struct [Location_RequestConfig](#location_requestconfig) [Location_RequestConfig](#location_requestconfig) | 定义位置请求参数的结构体。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Location_ResultCode](#location_resultcode-1) {<br/>LOCATION_SUCCESS = 0, LOCATION_PERMISSION_DENIED = 201, LOCATION_INVALID_PARAM = 401, LOCATION_NOT_SUPPORTED = 801,<br/>LOCATION_SERVICE_UNAVAILABLE = 3301000, LOCATION_SWITCH_OFF = 3301100<br/>} | 定义位置服务的错误码。  | 
| [Location_UseScene](#location_usescene-1) { LOCATION_USE_SCENE_NAVIGATION = 0x0401, LOCATION_USE_SCENE_SPORT = 0x0402, LOCATION_USE_SCENE_TRANSPORT = 0x0403, LOCATION_USE_SCENE_DAILY_LIFE_SERVICE = 0x0404 } | 定义位置请求中的用户活动场景类型。  | 
| [Location_PowerConsumptionScene](#location_powerconsumptionscene-1) { LOCATION_HIGH_POWER_CONSUMPTION = 0x0601, LOCATION_LOW_POWER_CONSUMPTION = 0x0602, LOCATION_NO_POWER_CONSUMPTION = 0x0603 } | 定义位置请求中的功耗场景类型。  | 
| [Location_SourceType](#location_sourcetype-1) { LOCATION_SOURCE_TYPE_GNSS = 1, LOCATION_SOURCE_TYPE_NETWORK = 2, LOCATION_SOURCE_TYPE_INDOOR = 3, LOCATION_SOURCE_TYPE_RTK = 4 } | 定义位置信息的来源。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Location_ResultCode](#location_resultcode-1) [OH_Location_IsLocatingEnabled](#oh_location_islocatingenabled) (bool \*enabled) | 查询位置开关是否开启。  | 
| [Location_ResultCode](#location_resultcode-1) [OH_Location_StartLocating](#oh_location_startlocating) (const [Location_RequestConfig](#location_requestconfig) \*requestConfig) | 启动定位并订阅位置变化。  | 
| [Location_ResultCode](#location_resultcode-1) [OH_Location_StopLocating](#oh_location_stoplocating) (const [Location_RequestConfig](#location_requestconfig) \*requestConfig) | 停止定位并取消订阅位置变化。  | 
| [Location_BasicInfo](_location___basic_info.md) [OH_LocationInfo_GetBasicInfo](#oh_locationinfo_getbasicinfo) ([Location_Info](#location_info) \*location) | 获取位置基本信息。  | 
| [Location_ResultCode](#location_resultcode-1) [OH_LocationInfo_GetAdditionalInfo](#oh_locationinfo_getadditionalinfo) ([Location_Info](#location_info) \*location, char \*additionalInfo, uint32_t length) | 获取位置信息中的附加信息。  | 
| [Location_RequestConfig](#location_requestconfig) \* [OH_Location_CreateRequestConfig](#oh_location_createrequestconfig) (void) | 创建一个位置请求参数结构体实例。  | 
| void [OH_Location_DestroyRequestConfig](#oh_location_destroyrequestconfig) ([Location_RequestConfig](#location_requestconfig) \*requestConfig) | 销毁位置请求参数实例并回收内存。  | 
| void [OH_LocationRequestConfig_SetUseScene](#oh_locationrequestconfig_setusescene) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, [Location_UseScene](#location_usescene) useScene) | 设置位置请求参数中的用户活动场景。<br/>位置请求参数[Location_RequestConfig](#location_requestconfig)中以useScene优先。<br/>如果设置了useScene，则powerConsumptionScene参数无效。<br/>如果未设置useScene，设置了powerConsumptionScene则该参数生效。<br/>如果两个参数都未设置，则默认useScene为LOCATION_USE_SCENE_DAILY_LIFE_SERVICE，<br/>powerConsumptionScene参数无效。 | 
| void [OH_LocationRequestConfig_SetPowerConsumptionScene](#oh_locationrequestconfig_setpowerconsumptionscene) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, [Location_PowerConsumptionScene](#location_powerconsumptionscene) powerConsumptionScene) | 设置位置请求参数中的功耗场景。  | 
| void [OH_LocationRequestConfig_SetInterval](#oh_locationrequestconfig_setinterval) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, int interval) | 设置位置请求参数中的位置上报间隔。  | 
| void [OH_LocationRequestConfig_SetCallback](#oh_locationrequestconfig_setcallback) ([Location_RequestConfig](#location_requestconfig) \*requestConfig, [Location_InfoCallback](#location_infocallback) callback, void \*userData) | 设置回调函数。  | 


## 类型定义说明


### Location_BasicInfo

```
typedef struct Location_BasicInfo Location_BasicInfo
```
**描述**
定义位置基本信息的结构体。

**起始版本：** 13


### Location_Info

```
typedef struct Location_Info Location_Info
```
**描述**
定义位置信息的结构体。

**起始版本：** 13


### Location_InfoCallback

```
typedef void(* Location_InfoCallback) (Location_Info *location, void *userData)
```
**描述**
用于接收位置上报的回调函数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| location | - 指向[Location_Info](#location_info)实例的指针，携带最新的位置信息。<br/>location实例的内存会在[Location_InfoCallback](#location_infocallback)结束时回收，<br/>请在此之前调用[OH_LocationInfo_GetBasicInfo](#oh_locationinfo_getbasicinfo)等接口获取位置信息。 | 
| userData | - 指向调用者数据结构或对象的指针，该参数是通过[OH_LocationRequestConfig_SetCallback](#oh_locationrequestconfig_setcallback)传入的。 | 


### Location_PowerConsumptionScene

```
typedef enum Location_PowerConsumptionScene Location_PowerConsumptionScene
```
**描述**
定义位置请求中的功耗场景类型。

**起始版本：** 13


### Location_RequestConfig

```
typedef struct Location_RequestConfig Location_RequestConfig
```
**描述**
定义位置请求参数的结构体。

**起始版本：** 13


### Location_ResultCode

```
typedef enum Location_ResultCode Location_ResultCode
```
**描述**
定义位置服务的错误码。

**起始版本：** 13


### Location_SourceType

```
typedef enum Location_SourceType Location_SourceType
```
**描述**
定义位置信息的来源。

**起始版本：** 13


### Location_UseScene

```
typedef enum Location_UseScene Location_UseScene
```
**描述**
定义位置请求中的用户活动场景类型。

**起始版本：** 13


## 枚举类型说明


### Location_PowerConsumptionScene

```
enum Location_PowerConsumptionScene
```
**描述**
定义位置请求中的功耗场景类型。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCATION_HIGH_POWER_CONSUMPTION  | 高功耗。<br/>以GNSS定位技术为主。在GNSS提供稳定位置结果之前会使用网络定位技术提供服务；<br/>在持续定位时，如果超过30秒无法获取GNSS定位结果则会使用网络定位技术获取位置。<br/>对设备的硬件资源消耗较大，功耗较大。 | 
| LOCATION_LOW_POWER_CONSUMPTION  | 低功耗。<br/>适用于对用户位置精度要求不高的使用场景，如新闻资讯、网购、点餐类应用。<br/>该场景仅使用网络定位技术提供定位服务，功耗较低。 | 
| LOCATION_NO_POWER_CONSUMPTION  | 无功耗。<br/>这种场景下不会主动触发定位，会在其他应用定位时，才给当前应用返回位置。 | 


### Location_ResultCode

```
enum Location_ResultCode
```
**描述**
定义位置服务的错误码。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCATION_SUCCESS  | 操作成功。   | 
| LOCATION_PERMISSION_DENIED  | 权限校验失败。   | 
| LOCATION_INVALID_PARAM  | 参数错误。<br/>可能原因：1.输入参数为空指针；2.参数数值超出定义范围。 | 
| LOCATION_NOT_SUPPORTED  | 该功能不支持。由于设备能力有限，无法调用该函数。   | 
| LOCATION_SERVICE_UNAVAILABLE  | 位置服务不可用。   | 
| LOCATION_SWITCH_OFF  | 位置开关处于关闭状态。   | 


### Location_SourceType

```
enum Location_SourceType
```
**描述**
定义位置信息的来源。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCATION_SOURCE_TYPE_GNSS  | 表示定位结果来自于GNSS定位技术。   | 
| LOCATION_SOURCE_TYPE_NETWORK  | 表示定位结果来自于网络定位技术。   | 
| LOCATION_SOURCE_TYPE_INDOOR  | 表示定位结果来自于室内高精度定位技术。   | 
| LOCATION_SOURCE_TYPE_RTK  | 表示定位结果来自于室外高精度定位技术。   | 


### Location_UseScene

```
enum Location_UseScene
```
**描述**
定义位置请求中的用户活动场景类型。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| LOCATION_USE_SCENE_NAVIGATION  | 导航场景。<br/>适用于在户外获取设备实时位置的场景，如车载、步行导航。<br/>主要使用GNSS定位技术提供定位服务，功耗较高。 | 
| LOCATION_USE_SCENE_SPORT  | 表示运动场景。<br/>适用于记录用户位置轨迹的场景，如运动类应用记录轨迹功能。<br/>主要使用GNSS定位技术提供定位服务，功耗较高。 | 
| LOCATION_USE_SCENE_TRANSPORT  | 表示出行场景。<br/>适用于用户出行场景，如打车、乘坐公共交通等场景。<br/>主要使用GNSS定位技术提供定位服务，功耗较高。 | 
| LOCATION_USE_SCENE_DAILY_LIFE_SERVICE  | 表示日常服务使用场景。<br/>适用于不需要定位用户精确位置的使用场景，如新闻资讯、网购、点餐类应用。<br/>该场景仅使用网络定位技术提供定位服务，功耗较低。 | 


## 函数说明


### OH_Location_CreateRequestConfig()

```
Location_RequestConfig* OH_Location_CreateRequestConfig (void )
```
**描述**
创建一个位置请求参数结构体实例。

**起始版本：** 13

**返回：**

返回指向[Location_RequestConfig](#location_requestconfig)实例的指针。

如果返回NULL表示创建失败，可能的原因是应用地址空间满，导致空间分配不出来。


### OH_Location_DestroyRequestConfig()

```
void OH_Location_DestroyRequestConfig (Location_RequestConfig * requestConfig)
```
**描述**
销毁位置请求参数实例并回收内存。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestConfig | - 指向[Location_RequestConfig](#location_requestconfig)实例的指针。<br/>该实例是由[OH_Location_CreateRequestConfig](#oh_location_createrequestconfig)创建的。 | 


### OH_Location_IsLocatingEnabled()

```
Location_ResultCode OH_Location_IsLocatingEnabled (bool * enabled)
```
**描述**
查询位置开关是否开启。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| enabled | - bool类型的指针，用于接收位置开关状态值。<br/>等于true表示位置开关开启，false表示位置开关关闭。<br/>需要传入非空指针，否则会返回错误。 | 

**返回：**

返回操作结果，详细定义参见[Location_ResultCode](#location_resultcode)。

**LOCAION_SUCCESS** 查询位置开关状态成功。

LOCATION_INVALID_PARAM 入参是空指针。

LOCATION_SERVICE_UNAVAILABLE 位置服务运行异常导致查询位置开关状态失败。


### OH_Location_StartLocating()

```
Location_ResultCode OH_Location_StartLocating (const Location_RequestConfig * requestConfig)
```
**描述**
启动定位并订阅位置变化。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestConfig | - 指向定位请求参数的指针，该参数用于指定发起定位的场景信息和位置上报间隔。<br/>详细定义请参考[Location_RequestConfig](#location_requestconfig)，可以使用[OH_Location_CreateRequestConfig](#oh_location_createrequestconfig)创建。 | 

**返回：**

返回操作结果，详细定义参见[Location_ResultCode](#location_resultcode)。

LOCAION_SUCCESS 启动定位成功。

LOCATION_INVALID_PARAM 入参requestConfig为空指针。

LOCATION_PERMISSION_DENIED 权限校验失败。

LOCATION_NOT_SUPPORTED 当前设备不支持该功能。

LOCATION_SERVICE_UNAVAILABLE 位置服务运行异常。

LOCATION_SWITCH_OFF 位置开关未打开导致无法启动定位。

**Permission：**

ohos.permission.APPROXIMATELY_LOCATION


### OH_Location_StopLocating()

```
Location_ResultCode OH_Location_StopLocating (const Location_RequestConfig * requestConfig)
```
**描述**
停止定位并取消订阅位置变化。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestConfig | - 指向定位请求参数的指针。<br/>该参数需要与[OH_Location_StartLocating](#oh_location_startlocating)中的requestConfig是同一个指针。<br/>详细定义请参考[Location_RequestConfig](#location_requestconfig)。<br/>需要传入非空指针，否则会返回错误。 | 

**返回：**

返回操作结果，详细定义参见[Location_ResultCode](#location_resultcode)。

LOCAION_SUCCESS 停止定位成功。

LOCATION_INVALID_PARAM 入参为空指针或入参与[OH_Location_StartLocating](#oh_location_startlocating)的requestConfig指针不同。

LOCATION_PERMISSION_DENIED 权限校验失败。

LOCATION_NOT_SUPPORTED 当前设备不支持该功能。

LOCATION_SERVICE_UNAVAILABLE 位置服务运行异常。

LOCATION_SWITCH_OFF 位置开关未打开。

**Permission：**

ohos.permission.APPROXIMATELY_LOCATION


### OH_LocationInfo_GetAdditionalInfo()

```
Location_ResultCode OH_LocationInfo_GetAdditionalInfo (Location_Info * location, char * additionalInfo, uint32_t length )
```
**描述**
获取位置信息中的附加信息。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| location | - 指向位置信息结构体的指针。<br/>需要传入非空指针，该指针可以在[Location_InfoCallback](#location_infocallback)中获取。 | 
| additionalInfo | - char类型的非空指针；该变量用于保存附加信息字符串，该字符串是JSON格式。<br/>该指针和对应的内存由调用者创建，建议申请大于等于256字节的内存。<br/>如果传入空指针，会返回错误码。 | 
| length | - 表示additionalInfo的内存大小。  | 

**返回：**

返回操作结果，详细定义参见[Location_ResultCode](#location_resultcode)。

**LOCAION_SUCCESS** 获取附加信息成功。

LOCATION_INVALID_PARAM 1. 入参location或additionalInfo是空指针。

1. 入参length太小，也就是additionalInfo指向的内存太小导致无法保存完整的附加信息字符串。


### OH_LocationInfo_GetBasicInfo()

```
Location_BasicInfo OH_LocationInfo_GetBasicInfo (Location_Info * location)
```
**描述**
获取位置基本信息。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| location | - 指向位置信息结构体的指针。<br/>需要传入非空指针，该指针可以在[Location_InfoCallback](#location_infocallback)中获取。 | 

**返回：**

返回位置基本信息结构体。详细定义请参考[Location_BasicInfo](_location___basic_info.md)。


### OH_LocationRequestConfig_SetCallback()

```
void OH_LocationRequestConfig_SetCallback (Location_RequestConfig * requestConfig, Location_InfoCallback callback, void * userData )
```
**描述**
设置回调函数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestConfig | - 指向[Location_RequestConfig](#location_requestconfig)实例的指针。<br/>该实例是由[OH_Location_CreateRequestConfig](#oh_location_createrequestconfig)创建的。 | 
| callback | - 指向回调函数的指针，该回调函数用于接收位置信息变化。<br/>详细定义请参考[Location_InfoCallback](#location_infocallback)。 | 
| userData | - 指向调用者数据结构或对象的指针。这个指针会在回调函数执行时作为入参回传给调用者。 | 


### OH_LocationRequestConfig_SetInterval()

```
void OH_LocationRequestConfig_SetInterval (Location_RequestConfig * requestConfig, int interval )
```
**描述**
设置位置请求参数中的位置上报间隔。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestConfig | - 指向[Location_RequestConfig](#location_requestconfig)实例的指针。<br/>该实例是由[OH_Location_CreateRequestConfig](#oh_location_createrequestconfig)创建的。 | 
| interval | - 表示位置上报时间间隔，单位是“秒”。取值范围为大于等于1，默认值为1。  | 


### OH_LocationRequestConfig_SetPowerConsumptionScene()

```
void OH_LocationRequestConfig_SetPowerConsumptionScene (Location_RequestConfig * requestConfig, Location_PowerConsumptionScene powerConsumptionScene )
```
**描述**
设置位置请求参数中的功耗场景。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestConfig | - 指向[Location_RequestConfig](#location_requestconfig)实例的指针。<br/>该实例是由[OH_Location_CreateRequestConfig](#oh_location_createrequestconfig)创建的。 | 
| powerConsumptionScene | - 表示位置请求的功耗场景。<br/>默认值是LOCATION_LOW_POWER_CONSUMPTION。<br/>详细定义见[Location_PowerConsumptionScene](#location_powerconsumptionscene)。 | 


### OH_LocationRequestConfig_SetUseScene()

```
void OH_LocationRequestConfig_SetUseScene (Location_RequestConfig * requestConfig, Location_UseScene useScene )
```
**描述**
设置位置请求参数中的用户活动场景。

位置请求参数[Location_RequestConfig](#location_requestconfig)中以useScene优先。

如果设置了useScene，则powerConsumptionScene参数无效。

如果未设置useScene，设置了powerConsumptionScene则该参数生效。

如果两个参数都未设置，则默认useScene为LOCATION_USE_SCENE_DAILY_LIFE_SERVICE，

powerConsumptionScene参数无效。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestConfig | - 指向[Location_RequestConfig](#location_requestconfig)实例的指针。<br/>该实例是由[OH_Location_CreateRequestConfig](#oh_location_createrequestconfig)创建的。 | 
| useScene | - 表示位置请求时的用户活动场景。<br/>默认值是LOCATION_USE_SCENE_DAILY_LIFE_SERVICE。<br/>详细定义见[Location_UseScene](#location_usescene)。 | 

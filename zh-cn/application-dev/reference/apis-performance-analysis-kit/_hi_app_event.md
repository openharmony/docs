# HiAppEvent


## 概述

HiAppEvent模块提供应用事件打点功能。

为应用程序提供事件打点功能，记录运行过程中上报的故障事件、统计事件、安全事件和用户行为事件。基于事件信息，开发者可以分析应用的运行状态。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 8


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [hiappevent.h](hiappevent_8h.md) | HiAppEvent模块的应用事件打点函数定义。<br/>**引用文件**：<hiappevent/hiappevent.h><br/>**库**：libhiappevent_ndk.z.so | 
| [hiappevent_cfg.h](hiappevent__cfg_8h.md) | 定义事件打点配置函数的所有配置项名称。<br/>**引用文件**：<hiappevent/hiappevent_event.h><br/>**库**：libhiappevent_ndk.z.so | 
| [hiappevent_event.h](hiappevent__event_8h.md) | 定义所有预定义事件的事件名称。<br/>**引用文件**：<hiappevent/hiappevent_param.h><br/>**库**：libhiappevent_ndk.z.so | 
| [hiappevent_param.h](hiappevent__param_8h.md) | 定义所有预定义事件的参数名称。<br/>**引用文件**：<hiappevent/hiappevent_cfg.h><br/>**库**：libhiappevent_ndk.z.so | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) | 单个事件信息，包含事件领域，事件名称，事件类型和json格式字符串表示的事件中携带的自定义参数列表。  | 
| struct&nbsp;&nbsp;[HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) | 具有相同事件名称的事件组。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [DISABLE](#disable)&nbsp;&nbsp;&nbsp;"disable" | 事件打点开关。默认值为false。true：关闭打点功能，false：不关闭打点功能。  | 
| [MAX_STORAGE](#max_storage)&nbsp;&nbsp;&nbsp;"max_storage" | 事件文件目录存储配额大小。默认值为“10M”。  | 
| [EVENT_USER_LOGIN](#event_user_login)&nbsp;&nbsp;&nbsp;"hiappevent.user_login" | 用户登录事件。  | 
| [EVENT_USER_LOGOUT](#event_user_logout)&nbsp;&nbsp;&nbsp;"hiappevent.user_logout" | 用户登出事件。  | 
| [EVENT_DISTRIBUTED_SERVICE_START](#event_distributed_service_start)&nbsp;&nbsp;&nbsp;"hiappevent.distributed_service_start" | 分布式服务事件。  | 
| [EVENT_APP_CRASH](#event_app_crash)&nbsp;&nbsp;&nbsp;"APP_CRASH" | 应用崩溃事件。  | 
| [EVENT_APP_FREEZE](#event_app_freeze)&nbsp;&nbsp;&nbsp;"APP_FREEZE" | 应用卡顿事件。  | 
| [EVENT_APP_LAUNCH](#event_app_launch)&nbsp;&nbsp;&nbsp;"APP_LAUNCH" | 应用加载事件。  | 
| [EVENT_SCROLL_JANK](#event_scroll_jank)&nbsp;&nbsp;&nbsp;"SCROLL_JANK" | 应用滑动卡顿事件。  | 
| [EVENT_CPU_USAGE_HIGH](#event_cpu_usage_high)&nbsp;&nbsp;&nbsp;"CPU_USAGE_HIGH" | 应用CPU资源占用高事件。  | 
| [EVENT_BATTERY_USAGE](#event_battery_usage)&nbsp;&nbsp;&nbsp;"BATTERY_USAGE" | 应用电源使用率事件。  | 
| [EVENT_RESOURCE_OVERLIMIT](#event_resource_overlimit)&nbsp;&nbsp;&nbsp;"RESOURCE_OVERLIMIT" | 应用资源超限事件。  | 
| [DOMAIN_OS](#domain_os)&nbsp;&nbsp;&nbsp;"OS" | OS作用域。  | 
| [PARAM_USER_ID](#param_user_id)&nbsp;&nbsp;&nbsp;"user_id" | 用户ID。  | 
| [PARAM_DISTRIBUTED_SERVICE_NAME](#param_distributed_service_name)&nbsp;&nbsp;&nbsp;"ds_name" | 分布式服务名称。  | 
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](#param_distributed_service_instance_id)&nbsp;&nbsp;&nbsp;"ds_instance_id" | 分布式服务实例ID。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) [HiAppEvent_AppEventInfo](#hiappevent_appeventinfo) | 单个事件信息，包含事件领域，事件名称，事件类型和json格式字符串表示的事件中携带的自定义参数列表。  | 
| typedef struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) [HiAppEvent_AppEventGroup](#hiappevent_appeventgroup) | 具有相同事件名称的事件组。  | 
| typedef struct ParamListNode \* [ParamList](#paramlist) | 事件参数列表节点。  | 
| typedef struct [HiAppEvent_Watcher](#hiappevent_watcher) [HiAppEvent_Watcher](#hiappevent_watcher) | 用于接收app事件的监听器。  | 
| typedef struct [HiAppEvent_Processor](#hiappevent_processor) [HiAppEvent_Processor](#hiappevent_processor) | 用于处理app事件上报的处理者。  | 
| typedef struct [HiAppEvent_Config](#hiappevent_config) [HiAppEvent_Config](#hiappevent_config) | 用于设置系统事件触发条件的配置对象。  | 
| typedef void(\* [OH_HiAppEvent_OnReceive](#oh_hiappevent_onreceive)) (const char \*domain, const struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) \*appEventGroups, uint32_t groupLen) | 监听器接收到事件后，将触发该回调，将事件内容传递给调用方。  | 
| typedef void(\* [OH_HiAppEvent_OnTrigger](#oh_hiappevent_ontrigger)) (int row, int size) | 监听器收到事件后，若监听器中未设置OH_HiAppEvent_OnReceive回调，将保存该事件。当保存的事件满足通过 OH_HiAppEvent_SetTriggerCondition设定的条件后，将触发该回调。回调结束后，当新保存的事件消息再次满足设定的条件后，将再次进行回调。  | 
| typedef void(\* [OH_HiAppEvent_OnTake](#oh_hiappevent_ontake)) (const char \*const \*events, uint32_t eventLen) | 使用OH_HiAppEvent_TakeWatcherData获取监听器接收到的事件时，监听器接收到的事件将通过该回调函数传递给调用者。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiAppEvent_ErrorCode](#hiappevent_errorcode) {<br/>HIAPPEVENT_SUCCESS = 0, HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH = 4, HIAPPEVENT_PROCESSOR_IS_NULL = -7, HIAPPEVENT_PROCESSOR_NOT_FOUND = -8,<br/>HIAPPEVENT_INVALID_PARAM_VALUE = -9, HIAPPEVENT_EVENT_CONFIG_IS_NULL = -10, HIAPPEVENT_OPERATE_FAILED = -100, HIAPPEVENT_INVALID_UID = -200<br/>} | 错误码定义。  | 
| [EventType](#eventtype) { FAULT = 1, STATISTIC = 2, SECURITY = 3, BEHAVIOR = 4 } | 事件类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ParamList](#paramlist) [OH_HiAppEvent_CreateParamList](#oh_hiappevent_createparamlist) (void) | 创建一个指向参数列表对象的指针。  | 
| void [OH_HiAppEvent_DestroyParamList](#oh_hiappevent_destroyparamlist) ([ParamList](#paramlist) list) | 销毁一个指向参数列表对象的指针，释放其分配内存。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolParam](#oh_hiappevent_addboolparam) ([ParamList](#paramlist) list, const char \*name, bool boolean) | 添加一个布尔参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolArrayParam](#oh_hiappevent_addboolarrayparam) ([ParamList](#paramlist) list, const char \*name, const bool \*booleans, int arrSize) | 添加一个布尔数组参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8Param](#oh_hiappevent_addint8param) ([ParamList](#paramlist) list, const char \*name, int8_t num) | 添加一个int8_t参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8ArrayParam](#oh_hiappevent_addint8arrayparam) ([ParamList](#paramlist) list, const char \*name, const int8_t \*nums, int arrSize) | 添加一个int8_t数组参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16Param](#oh_hiappevent_addint16param) ([ParamList](#paramlist) list, const char \*name, int16_t num) | 添加一个int16_t参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16ArrayParam](#oh_hiappevent_addint16arrayparam) ([ParamList](#paramlist) list, const char \*name, const int16_t \*nums, int arrSize) | 添加一个int16_t数组参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32Param](#oh_hiappevent_addint32param) ([ParamList](#paramlist) list, const char \*name, int32_t num) | 添加一个int32_t参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32ArrayParam](#oh_hiappevent_addint32arrayparam) ([ParamList](#paramlist) list, const char \*name, const int32_t \*nums, int arrSize) | 添加一个int32_t数组参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64Param](#oh_hiappevent_addint64param) ([ParamList](#paramlist) list, const char \*name, int64_t num) | 添加一个int64_t参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64ArrayParam](#oh_hiappevent_addint64arrayparam) ([ParamList](#paramlist) list, const char \*name, const int64_t \*nums, int arrSize) | 添加一个int64_t数组参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatParam](#oh_hiappevent_addfloatparam) ([ParamList](#paramlist) list, const char \*name, float num) | 添加一个float参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatArrayParam](#oh_hiappevent_addfloatarrayparam) ([ParamList](#paramlist) list, const char \*name, const float \*nums, int arrSize) | 添加一个float数组参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleParam](#oh_hiappevent_adddoubleparam) ([ParamList](#paramlist) list, const char \*name, double num) | 添加一个double参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleArrayParam](#oh_hiappevent_adddoublearrayparam) ([ParamList](#paramlist) list, const char \*name, const double \*nums, int arrSize) | 添加一个double数组参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringParam](#oh_hiappevent_addstringparam) ([ParamList](#paramlist) list, const char \*name, const char \*str) | 添加一个字符串参数到参数列表中。  | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringArrayParam](#oh_hiappevent_addstringarrayparam) ([ParamList](#paramlist) list, const char \*name, const char \*const \*strs, int arrSize) | 添加一个字符串数组参数到参数列表中。  | 
| int [OH_HiAppEvent_Write](#oh_hiappevent_write) (const char \*domain, const char \*name, enum [EventType](#eventtype) type, const [ParamList](#paramlist) list) | 实现对参数为列表类型的应用事件打点。  | 
| bool [OH_HiAppEvent_Configure](#oh_hiappevent_configure) (const char \*name, const char \*value) | 实现应用事件打点的配置功能。  | 
| [HiAppEvent_Watcher](#hiappevent_watcher) \* [OH_HiAppEvent_CreateWatcher](#oh_hiappevent_createwatcher) (const char \*name) | 创建一个用于监听app事件的监听器。  | 
| void [OH_HiAppEvent_DestroyWatcher](#oh_hiappevent_destroywatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | 销毁已创建的监听器。  | 
| int [OH_HiAppEvent_SetTriggerCondition](#oh_hiappevent_settriggercondition) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, int row, int size, int timeOut) | 用于设置监听器OH_HiAppEvent_OnTrigger回调的触发条件，分别可以从监视器新接收事件数量、新接收事件大小、onTrigger触发超时时间，设置触发条件。调用方应至少保证从一个方面设置触发条件。  | 
| int [OH_HiAppEvent_SetAppEventFilter](#oh_hiappevent_setappeventfilter) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, const char \*domain, uint8_t eventTypes, const char \*const \*names, int namesLen) | 用于设置监听器需要监听的事件的类型。  | 
| int [OH_HiAppEvent_SetWatcherOnTrigger](#oh_hiappevent_setwatcherontrigger) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnTrigger](#oh_hiappevent_ontrigger) onTrigger) | 用于设置监听器onTrigger回调的接口。  | 
| int [OH_HiAppEvent_SetWatcherOnReceive](#oh_hiappevent_setwatcheronreceive) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnReceive](#oh_hiappevent_onreceive) onReceive) | 用于设置监听器onReceive回调函数的接口。当监听器监听到相应事件后，onReceive回调函数将被调用。  | 
| int [OH_HiAppEvent_TakeWatcherData](#oh_hiappevent_takewatcherdata) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, uint32_t eventNum, [OH_HiAppEvent_OnTake](#oh_hiappevent_ontake) onTake) | 用于获取监听器收到后保存的事件。  | 
| int [OH_HiAppEvent_AddWatcher](#oh_hiappevent_addwatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | 添加监听器的接口，监听器开始监听系统消息。  | 
| int [OH_HiAppEvent_RemoveWatcher](#oh_hiappevent_removewatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | 移除监听器的接口，监听器停止监听系统消息。  | 
| void [OH_HiAppEvent_ClearData](#oh_hiappevent_cleardata) (void) | 清除所有监视器保存的所有事件。  | 
| [HiAppEvent_Processor](#hiappevent_processor) \* [OH_HiAppEvent_CreateProcessor](#oh_hiappevent_createprocessor) (const char \*name) | 创建一个用于处理app事件上报的处理者。  | 
| int [OH_HiAppEvent_SetReportRoute](#oh_hiappevent_setreportroute) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*appId, const char \*routeInfo) | 设置处理者事件上报路由的接口。  | 
| int [OH_HiAppEvent_SetReportPolicy](#oh_hiappevent_setreportpolicy) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, int periodReport, int batchReport, bool onStartReport, bool onBackgroundReport) | 设置处理者事件上报策略的接口。  | 
| int [OH_HiAppEvent_SetReportEvent](#oh_hiappevent_setreportevent) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*domain, const char \*name, bool isRealTime) | 设置处理者上报事件的接口。  | 
| int [OH_HiAppEvent_SetCustomConfig](#oh_hiappevent_setcustomconfig) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*key, const char \*value) | 设置处理者自定义扩展参数的接口。  | 
| int [OH_HiAppEvent_SetConfigId](#oh_hiappevent_setconfigid) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, int configId) | 设置处理者配置id的接口。  | 
| int [OH_HiAppEvent_SetReportUserId](#oh_hiappevent_setreportuserid) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*const \*userIdNames, int size) | 设置处理者用户ID的接口。  | 
| int [OH_HiAppEvent_SetReportUserProperty](#oh_hiappevent_setreportuserproperty) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*const \*userPropertyNames, int size) | 设置处理者用户属性的接口。  | 
| int64_t [OH_HiAppEvent_AddProcessor](#oh_hiappevent_addprocessor) ([HiAppEvent_Processor](#hiappevent_processor) \*processor) | 添加数据处理者的接口。开发者可添加数据处理者，用于提供事件上云功能。数据处理者的实现可预置在设备中，开发者可根据数据处理者的约束设置属性。  | 
| void [OH_HiAppEvent_DestroyProcessor](#oh_hiappevent_destroyprocessor) ([HiAppEvent_Processor](#hiappevent_processor) \*processor) | 销毁已创建的数据处理者。  | 
| int [OH_HiAppEvent_RemoveProcessor](#oh_hiappevent_removeprocessor) (int64_t processorId) | 移除数据处理者的接口，处理者停止上报事件。  | 
| [HiAppEvent_Config](#hiappevent_config) \* [OH_HiAppEvent_CreateConfig](#oh_hiappevent_createconfig) (void) | 创建一个指向设置系统事件触发条件的配置对象的指针。  | 
| void [OH_HiAppEvent_DestroyConfig](#oh_hiappevent_destroyconfig) ([HiAppEvent_Config](#hiappevent_config) \*config) | 销毁已创建的配置对象。  | 
| int [OH_HiAppEvent_SetConfigItem](#oh_hiappevent_setconfigitem) ([HiAppEvent_Config](#hiappevent_config) \*config, const char \*itemName, const char \*itemValue) | 设置配置对象中的配置项。  | 
| int [OH_HiAppEvent_SetEventConfig](#oh_hiappevent_seteventconfig) (const char \*name, [HiAppEvent_Config](#hiappevent_config) \*config) | 设定系统事件订阅触发条件。  | 


## 宏定义说明


### DISABLE

```
#define DISABLE   "disable"
```
**描述**
事件打点开关。默认值为false。true：关闭打点功能，false：不关闭打点功能。

**起始版本：** 8


### DOMAIN_OS

```
#define DOMAIN_OS   "OS"
```
**描述**
OS作用域。

**起始版本：** 12


### EVENT_APP_CRASH

```
#define EVENT_APP_CRASH   "APP_CRASH"
```
**描述**
应用崩溃事件。

**起始版本：** 12


### EVENT_APP_FREEZE

```
#define EVENT_APP_FREEZE   "APP_FREEZE"
```
**描述**
应用卡顿事件。

**起始版本：** 12


### EVENT_APP_LAUNCH

```
#define EVENT_APP_LAUNCH   "APP_LAUNCH"
```
**描述**
应用加载事件。

**起始版本：** 12


### EVENT_BATTERY_USAGE

```
#define EVENT_BATTERY_USAGE   "BATTERY_USAGE"
```
**描述**
应用电源使用率事件。

**起始版本：** 12


### EVENT_CPU_USAGE_HIGH

```
#define EVENT_CPU_USAGE_HIGH   "CPU_USAGE_HIGH"
```
**描述**
应用CPU资源占用高事件。

**起始版本：** 12


### EVENT_DISTRIBUTED_SERVICE_START

```
#define EVENT_DISTRIBUTED_SERVICE_START   "hiappevent.distributed_service_start"
```
**描述**
分布式服务事件。

**起始版本：** 8


### EVENT_RESOURCE_OVERLIMIT

```
#define EVENT_RESOURCE_OVERLIMIT   "RESOURCE_OVERLIMIT"
```
**描述**
应用资源超限事件。

**起始版本：** 12


### EVENT_SCROLL_JANK

```
#define EVENT_SCROLL_JANK   "SCROLL_JANK"
```
**描述**
应用滑动卡顿事件。

**起始版本：** 12


### EVENT_USER_LOGIN

```
#define EVENT_USER_LOGIN   "hiappevent.user_login"
```
**描述**
用户登录事件。

**起始版本：** 8


### EVENT_USER_LOGOUT

```
#define EVENT_USER_LOGOUT   "hiappevent.user_logout"
```
**描述**
用户登出事件。

**起始版本：** 8


### MAX_STORAGE

```
#define MAX_STORAGE   "max_storage"
```
**描述**
事件文件目录存储配额大小。默认值为“10M”。

**起始版本：** 8


### PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID

```
#define PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID   "ds_instance_id"
```
**描述**
分布式服务实例ID。

**起始版本：** 8


### PARAM_DISTRIBUTED_SERVICE_NAME

```
#define PARAM_DISTRIBUTED_SERVICE_NAME   "ds_name"
```
**描述**
分布式服务名称。

**起始版本：** 8


### PARAM_USER_ID

```
#define PARAM_USER_ID   "user_id"
```
**描述**
用户ID。

**起始版本：** 8


## 类型定义说明


### HiAppEvent_AppEventGroup

```
typedef struct HiAppEvent_AppEventGroupHiAppEvent_AppEventGroup
```
**描述**
具有相同事件名称的事件组。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12


### HiAppEvent_AppEventInfo

```
typedef struct HiAppEvent_AppEventInfoHiAppEvent_AppEventInfo
```
**描述**
单个事件信息，包含事件领域，事件名称，事件类型和json格式字符串表示的事件中携带的自定义参数列表。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12


### HiAppEvent_Config

```
typedef struct HiAppEvent_ConfigHiAppEvent_Config
```
**描述**
用于设置系统事件触发条件的配置对象。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 15


### HiAppEvent_Processor

```
typedef struct HiAppEvent_ProcessorHiAppEvent_Processor
```
**描述**
用于处理app事件上报的处理者。

**起始版本：** 18


### HiAppEvent_Watcher

```
typedef struct HiAppEvent_WatcherHiAppEvent_Watcher
```
**描述**
用于接收app事件的监听器。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12


### OH_HiAppEvent_OnReceive

```
typedef void(* OH_HiAppEvent_OnReceive) (const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen)
```
**描述**
监听器接收到事件后，将触发该回调，将事件内容传递给调用方。

注意：回调中的指针所指对象的生命周期仅限于该回调函数内，请勿在该回调函数外直接使用该指针，若需缓存该信息，请对指针指向的内容进行深拷贝。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| domain | 接收到的app事件的领域。  | 
| appEventGroups | 按照不同事件名称分组的事件组数组。  | 
| groupLen | 事件组数组的长度。  | 


### OH_HiAppEvent_OnTake

```
typedef void(* OH_HiAppEvent_OnTake) (const char *const *events, uint32_t eventLen)
```
**描述**
使用OH_HiAppEvent_TakeWatcherData获取监听器接收到的事件时，监听器接收到的事件将通过该回调函数传递给调用者。

注意：回调中的指针所指对象的生命周期仅限于该回调函数内，请勿在该回调函数外直接使用该指针。若需缓存该信息，请对指针指向的内容进行深拷贝。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| events | json字符串格式的事件数组。  | 
| eventLen | 事件数组大小。  | 


### OH_HiAppEvent_OnTrigger

```
typedef void(* OH_HiAppEvent_OnTrigger) (int row, int size)
```
**描述**
监听器收到事件后，若监听器中未设置OH_HiAppEvent_OnReceive回调，将保存该事件。当保存的事件满足通过OH_HiAppEvent_SetTriggerCondition设定的条件后，将触发该回调。回调结束后，当新保存的事件消息再次满足设定的条件后，将再次进行回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| row | 监听器新接收到的事件消息的数量。  | 
| size | 监听器新接收的事件消息的大小总和(单个事件大小计算方式为：将消息转换为json字符串后，字符串的长度)。  | 


### ParamList

```
typedef struct ParamListNode* ParamList
```
**描述**
事件参数列表节点。

**起始版本：** 8


## 枚举类型说明


### EventType

```
enum EventType
```
**描述**
事件类型。

建议开发者根据不同的使用场景选择不同的事件类型。

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| FAULT  | 故障事件类型。&nbsp;&nbsp; | 
| STATISTIC  | 统计事件类型。&nbsp;&nbsp; | 
| SECURITY  | 安全事件类型。&nbsp;&nbsp; | 
| BEHAVIOR  | 行为事件类型。&nbsp;&nbsp; | 


### HiAppEvent_ErrorCode

```
enum HiAppEvent_ErrorCode
```
**描述**
错误码定义。

**起始版本：** 15

| 枚举值 | 描述 | 
| -------- | -------- |
| HIAPPEVENT_SUCCESS  | 操作成功。&nbsp;&nbsp; | 
| HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH  | 参数值长度无效。&nbsp;&nbsp; | 
| HIAPPEVENT_PROCESSOR_IS_NULL  | 事件处理者为空。&nbsp;&nbsp; | 
| HIAPPEVENT_PROCESSOR_NOT_FOUND  | 事件处理者不存在。&nbsp;&nbsp; | 
| HIAPPEVENT_INVALID_PARAM_VALUE  | 参数值无效。&nbsp;&nbsp; | 
| HIAPPEVENT_EVENT_CONFIG_IS_NULL  | 事件配置为空。&nbsp;&nbsp; | 
| HIAPPEVENT_OPERATE_FAILED  | 操作失败。&nbsp;&nbsp; | 
| HIAPPEVENT_INVALID_UID  | 用户标识为空。&nbsp;&nbsp; | 


## 函数说明


### OH_HiAppEvent_AddBoolArrayParam()

```
ParamList OH_HiAppEvent_AddBoolArrayParam (ParamList list, const char * name, const bool * booleans, int arrSize )
```
**描述**
添加一个布尔数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| booleans | 需要添加的布尔数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddBoolParam()

```
ParamList OH_HiAppEvent_AddBoolParam (ParamList list, const char * name, bool boolean )
```
**描述**
添加一个布尔参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| boolean | 需要添加的布尔参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddDoubleArrayParam()

```
ParamList OH_HiAppEvent_AddDoubleArrayParam (ParamList list, const char * name, const double * nums, int arrSize )
```
**描述**
添加一个double数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| nums | 需要添加的double数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddDoubleParam()

```
ParamList OH_HiAppEvent_AddDoubleParam (ParamList list, const char * name, double num )
```
**描述**
添加一个double参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| num | 需要添加的double参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddFloatArrayParam()

```
ParamList OH_HiAppEvent_AddFloatArrayParam (ParamList list, const char * name, const float * nums, int arrSize )
```
**描述**
添加一个float数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| nums | 需要添加的float数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddFloatParam()

```
ParamList OH_HiAppEvent_AddFloatParam (ParamList list, const char * name, float num )
```
**描述**
添加一个float参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| num | 需要添加的float参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt16ArrayParam()

```
ParamList OH_HiAppEvent_AddInt16ArrayParam (ParamList list, const char * name, const int16_t * nums, int arrSize )
```
**描述**
添加一个int16_t数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| nums | 需要添加的int16_t数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt16Param()

```
ParamList OH_HiAppEvent_AddInt16Param (ParamList list, const char * name, int16_t num )
```
**描述**
添加一个int16_t参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| num | 需要添加的int16_t参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt32ArrayParam()

```
ParamList OH_HiAppEvent_AddInt32ArrayParam (ParamList list, const char * name, const int32_t * nums, int arrSize )
```
**描述**
添加一个int32_t数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| nums | 需要添加的int32_t数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt32Param()

```
ParamList OH_HiAppEvent_AddInt32Param (ParamList list, const char * name, int32_t num )
```
**描述**
添加一个int32_t参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| num | 需要添加的int32_t参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt64ArrayParam()

```
ParamList OH_HiAppEvent_AddInt64ArrayParam (ParamList list, const char * name, const int64_t * nums, int arrSize )
```
**描述**
添加一个int64_t数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| nums | 需要添加的int64_t数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt64Param()

```
ParamList OH_HiAppEvent_AddInt64Param (ParamList list, const char * name, int64_t num )
```
**描述**
添加一个int64_t参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| num | 需要添加的int64_t参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt8ArrayParam()

```
ParamList OH_HiAppEvent_AddInt8ArrayParam (ParamList list, const char * name, const int8_t * nums, int arrSize )
```
**描述**
添加一个int8_t数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| nums | 需要添加的int8_t数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddInt8Param()

```
ParamList OH_HiAppEvent_AddInt8Param (ParamList list, const char * name, int8_t num )
```
**描述**
添加一个int8_t参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| num | 需要添加的int8_t参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddProcessor()

```
int64_t OH_HiAppEvent_AddProcessor (HiAppEvent_Processor * processor)
```
**描述**
添加数据处理者的接口。开发者可添加数据处理者，用于提供事件上云功能。数据处理者的实现可预置在设备中，开发者可根据数据处理者的约束设置属性。

注意：Processor的配置信息需要由数据处理者提供，目前设备内暂未预置可供交互的数据处理者，因此当前事件上云功能不可用。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 

**返回：**

调用成功时返回处理者唯一ID，大于0；-7：processor入参为空；-9：参数值无效；-200：用户标识无效。


### OH_HiAppEvent_AddStringArrayParam()

```
ParamList OH_HiAppEvent_AddStringArrayParam (ParamList list, const char * name, const char *const * strs, int arrSize )
```
**描述**
添加一个字符串数组参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| strs | 需要添加的字符串数组参数值。  | 
| arrSize | 需要添加的参数数组大小。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddStringParam()

```
ParamList OH_HiAppEvent_AddStringParam (ParamList list, const char * name, const char * str )
```
**描述**
添加一个字符串参数到参数列表中。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 需要添加参数的参数列表指针。  | 
| name | 需要添加的参数名称。  | 
| str | 需要添加的字符串参数值。  | 

**返回：**

添加参数后的参数列表指针。


### OH_HiAppEvent_AddWatcher()

```
int OH_HiAppEvent_AddWatcher (HiAppEvent_Watcher * watcher)
```
**描述**
添加监听器的接口，监听器开始监听系统消息。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 

**返回：**

0：接口调用成功；-5：watcher入参空指针。


### OH_HiAppEvent_ClearData()

```
void OH_HiAppEvent_ClearData (void )
```
**描述**
清除所有监视器保存的所有事件。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12


### OH_HiAppEvent_Configure()

```
bool OH_HiAppEvent_Configure (const char * name, const char * value )
```
**描述**
实现应用事件打点的配置功能。

应用事件打点配置接口，用于配置事件打点开关、事件文件目录存储配额大小等功能。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 配置项名称。名称可填[DISABLE](#disable)和[MAX_STORAGE](#max_storage)。  | 
| value | 配置项值。如果配置项名称是[DISABLE](#disable)，值可以填“true”或者“false”；如果配置项名称是[MAX_STORAGE](#max_storage)，配额值字符串只由数字字符和大小单位字符（单位字符支持[b\|k\|kb\|m\|mb\|g\|gb\|t\|tb]，不区分大小写）构成，配额值字符串必须以数字开头，后面可以选择不传单位字符（默认使用byte作为单位），或者以单位字符结尾。  | 

**返回：**

配置结果。如果配置成功，则返回true；如果配置失败则返回false。


### OH_HiAppEvent_CreateConfig()

```
HiAppEvent_Config* OH_HiAppEvent_CreateConfig (void )
```
**描述**
创建一个指向设置系统事件触发条件的配置对象的指针。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 15

**返回：**

指向设置系统事件触发条件的配置对象的指针。


### OH_HiAppEvent_CreateParamList()

```
ParamList OH_HiAppEvent_CreateParamList (void )
```
**描述**
创建一个指向参数列表对象的指针。

**起始版本：** 8

**返回：**

指向参数列表对象的指针。


### OH_HiAppEvent_CreateProcessor()

```
HiAppEvent_Processor* OH_HiAppEvent_CreateProcessor (const char * name)
```
**描述**
创建一个用于处理app事件上报的处理者。

注意：创建的处理者不再使用后必须通过调用OH_HiAppEvent_DestroyProcessor接口进行销毁。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 处理者名称，只能包含大小写字母、数字、下划线和$，不能以数字开头，长度非空且不超过256个字符。  | 

**返回：**

接口调用成功时返回指向的新建处理者的指针，name参数异常时返回nullptr。


### OH_HiAppEvent_CreateWatcher()

```
HiAppEvent_Watcher* OH_HiAppEvent_CreateWatcher (const char * name)
```
**描述**
创建一个用于监听app事件的监听器。

注意：创建的监听器不再使用后必须通过调用OH_HiAppEvent_DestroyWatcher接口进行销毁。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 监听器名称。  | 

**返回：**

接口调用成功时返回指向的新建监听器的指针，name参数异常时返回nullptr。


### OH_HiAppEvent_DestroyConfig()

```
void OH_HiAppEvent_DestroyConfig (HiAppEvent_Config * config)
```
**描述**
销毁已创建的配置对象。

注意：已创建的配置对象不再使用后，需要将其销毁，释放内存，防止内存泄漏，销毁后需要将对应指针置空。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向配置对象的指针（即OH_HiAppEvent_CreateConfig接口返回的指针）。  | 


### OH_HiAppEvent_DestroyParamList()

```
void OH_HiAppEvent_DestroyParamList (ParamList list)
```
**描述**
销毁一个指向参数列表对象的指针，释放其分配内存。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| list | 参数列表对象指针。  | 


### OH_HiAppEvent_DestroyProcessor()

```
void OH_HiAppEvent_DestroyProcessor (HiAppEvent_Processor * processor)
```
**描述**
销毁已创建的数据处理者。

注意：已创建的处理者不再使用后，需要将其销毁，释放内存，防止内存泄漏，销毁后需将对应指针置空。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 


### OH_HiAppEvent_DestroyWatcher()

```
void OH_HiAppEvent_DestroyWatcher (HiAppEvent_Watcher * watcher)
```
**描述**
销毁已创建的监听器。

注意：已创建的监听器不再使用后，需要将其销毁，释放内存，防止内存泄漏，销毁后需将对应指针置空。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 


### OH_HiAppEvent_RemoveProcessor()

```
int OH_HiAppEvent_RemoveProcessor (int64_t processorId)
```
**描述**
移除数据处理者的接口，处理者停止上报事件。

注意：该接口仅仅使处理者停止上报事件，并未销毁该处理者，该处理者依然常驻内存，直至调用OH_HiAppEvent_DestroyProcessor接口，内存才会释放。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processorId | 处理者唯一ID。  | 

**返回：**

0：接口调用成功；-8：事件处理者不存在；-100：操作失败；-200：用户标识无效。


### OH_HiAppEvent_RemoveWatcher()

```
int OH_HiAppEvent_RemoveWatcher (HiAppEvent_Watcher * watcher)
```
**描述**
移除监听器的接口，监听器停止监听系统消息。

注意：该接口仅仅使监听器停止监听系统消息，并未销毁该监听器，该监听器依然常驻内存，直至调用OH_HiAppEvent_DestroyWatcher接口，内存才会释放。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 

**返回：**

0：接口调用成功；-5：watcher入参空指针；-6：还未调用OH_HiAppEvent_AddWatcher，操作顺序有误。


### OH_HiAppEvent_SetAppEventFilter()

```
int OH_HiAppEvent_SetAppEventFilter (HiAppEvent_Watcher * watcher, const char * domain, uint8_t eventTypes, const char *const * names, int namesLen )
```
**描述**
用于设置监听器需要监听的事件的类型。

该函数可以重复调用，可添加多个过滤规则，而非替换，监听器将收到满足任一过滤规则的事件的通知。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 
| domain | 需要监听事件的领域。  | 
| eventTypes | 需要监听事件的事件类型。使用按位与方式进行匹配，可支持监听多种类型的事件。第一位为1（数值为1）表示支持监听故障类型的事件；第二位为1（数值为2）表示支持监听统计类型的事件；<br/>第三位为1（数值为4）表示支持监听安全类型的事件；第四位为1（数值为8）表示支持监听行为类型的事件。<br/>都为1（数值为15）或者都为0（数值为0）表示支持所有类型事件。 | 
| names | 需要监听的事件名称数组。  | 
| namesLen | 监听的事件名称的数组长度。  | 

**返回：**

0：接口调用成功；-1：names参数异常；-4：domain参数异常；-5：watcher入参空指针。


### OH_HiAppEvent_SetConfigId()

```
int OH_HiAppEvent_SetConfigId (HiAppEvent_Processor * processor, int configId )
```
**描述**
设置处理者配置id的接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 
| configId | 数据处理者配置id，自然数。  | 

**返回：**

0：接口调用成功；-7：processor入参为空；-9：参数值无效；-200：用户标识无效。


### OH_HiAppEvent_SetConfigItem()

```
int OH_HiAppEvent_SetConfigItem (HiAppEvent_Config * config, const char * itemName, const char * itemValue )
```
**描述**
设置配置对象中的配置项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 指向配置对象的指针（即OH_HiAppEvent_CreateConfig接口返回的指针）。  | 
| itemName | 待设定配置项的名称。  | 
| itemValue | 待设定配置项的值。  | 

**返回：**

0：接口调用成功；-9：设定的配置项无效；-10：传入的指向配置对象的指针为空。


### OH_HiAppEvent_SetCustomConfig()

```
int OH_HiAppEvent_SetCustomConfig (HiAppEvent_Processor * processor, const char * key, const char * value )
```
**描述**
设置处理者自定义扩展参数的接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 
| key | 参数名，长度不超过32个字符。  | 
| value | 参数值，长度不超过1024个字符。  | 

**返回：**

0：接口调用成功；-7：processor入参为空；-9：参数值无效；-200：用户标识无效；4：参数值长度无效。


### OH_HiAppEvent_SetEventConfig()

```
int OH_HiAppEvent_SetEventConfig (const char * name, HiAppEvent_Config * config )
```
**描述**
设定系统事件订阅触发条件。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 系统事件的名称。  | 
| config | 指向配置对象的指针（即OH_HiAppEvent_CreateConfig接口返回的指针）。  | 

**返回：**

0：接口调用成功；-9：设置的参数无效。


### OH_HiAppEvent_SetReportEvent()

```
int OH_HiAppEvent_SetReportEvent (HiAppEvent_Processor * processor, const char * domain, const char * name, bool isRealTime )
```
**描述**
设置处理者上报事件的接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 
| domain | 上报事件的领域。  | 
| name | 上报事件的名称。  | 
| isRealTime | 是否实时上报。  | 

**返回：**

0：接口调用成功；-7：processor入参为空；-9：参数值无效；-200：用户标识无效。


### OH_HiAppEvent_SetReportPolicy()

```
int OH_HiAppEvent_SetReportPolicy (HiAppEvent_Processor * processor, int periodReport, int batchReport, bool onStartReport, bool onBackgroundReport )
```
**描述**
设置处理者事件上报策略的接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 
| periodReport | 事件定时上报周期，单位为秒。  | 
| batchReport | 事件上报阈值，当事件条数达到阈值时上报事件。  | 
| onStartReport | 数据处理者在启动时是否上报事件，默认值为false。  | 
| onBackgroundReport | 应用程序进入后台时，是否上报事件，默认值为false。  | 

**返回：**

0：接口调用成功；-7：processor入参为空；-9：参数值无效；-200：用户标识无效。


### OH_HiAppEvent_SetReportRoute()

```
int OH_HiAppEvent_SetReportRoute (HiAppEvent_Processor * processor, const char * appId, const char * routeInfo )
```
**描述**
设置处理者事件上报路由的接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 
| appId | 处理者的应用ID。  | 
| routeInfo | 服务器位置信息，默认为空字符串。传入字符串长度不能超8KB，超过时会被置为默认值。  | 

**返回：**

0：接口调用成功；-7：processor入参为空；-9：参数值无效；-200：用户标识无效；4：参数值长度无效。


### OH_HiAppEvent_SetReportUserId()

```
int OH_HiAppEvent_SetReportUserId (HiAppEvent_Processor * processor, const char *const * userIdNames, int size )
```
**描述**
设置处理者用户ID的接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 
| userIdNames | 处理者可以上报的用户ID的name数组。  | 
| size | 用户ID的name数组长度。  | 

**返回：**

0：接口调用成功；-7：processor入参为空；-9：参数值无效；-200：用户标识无效；4：参数值长度无效。


### OH_HiAppEvent_SetReportUserProperty()

```
int OH_HiAppEvent_SetReportUserProperty (HiAppEvent_Processor * processor, const char *const * userPropertyNames, int size )
```
**描述**
设置处理者用户属性的接口。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| processor | 指向处理者的指针（即OH_HiAppEvent_CreateProcessor接口返回的指针）。  | 
| userPropertyNames | 处理者可以上报的用户属性数组。  | 
| size | 用户属性数组的长度。  | 

**返回：**

0：接口调用成功；-7：processor入参为空；-9：参数值无效；-200：用户标识无效；4：参数值长度无效。


### OH_HiAppEvent_SetTriggerCondition()

```
int OH_HiAppEvent_SetTriggerCondition (HiAppEvent_Watcher * watcher, int row, int size, int timeOut )
```
**描述**
用于设置监听器OH_HiAppEvent_OnTrigger回调的触发条件，分别可以从监视器新接收事件数量、新接收事件大小、onTrigger触发超时时间，设置触发条件。调用方应至少保证从一个方面设置触发条件。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 
| row | 当输入值大于0，且新接收事件的数量大于等于该值时，将调用设置的onTrigger回调函数；当输入值小于等于0时，不再以接收数量多少为维度 来触发onTrigger回调。  | 
| size | 当输入值大于0，且新接收事件的大小(单个事件大小计算方式为，将事件转换为json字符串后，字符串的长度)大于等于该值时，将调用设置的 onTrigger回调函数；当输入值小于等于0时，不再以新接收事件大小为维度触发onTrigger回调。  | 
| timeOut | 单位秒，当输入值大于0，每经过timeout秒，将检查监视器是否存在新接收到的事件，如果存在将触发onTrigger回调。触发onTrigger 后，经过timeOut秒后将再次检查是否存在新接收到的事件。当输入值小于等于0，不以超时时间为维度触发onTrigger回调。  | 

**返回：**

0：接口调用成功；-5：watcher入参空指针。


### OH_HiAppEvent_SetWatcherOnReceive()

```
int OH_HiAppEvent_SetWatcherOnReceive (HiAppEvent_Watcher * watcher, OH_HiAppEvent_OnReceive onReceive )
```
**描述**
用于设置监听器onReceive回调函数的接口。当监听器监听到相应事件后，onReceive回调函数将被调用。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 
| onReceive | 回调函数的函数指针。  | 

**返回：**

0：接口调用成功；-5：watcher入参空指针。


### OH_HiAppEvent_SetWatcherOnTrigger()

```
int OH_HiAppEvent_SetWatcherOnTrigger (HiAppEvent_Watcher * watcher, OH_HiAppEvent_OnTrigger onTrigger )
```
**描述**
用于设置监听器onTrigger回调的接口。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 
| onTrigger | 需要设置的回调。  | 

**返回：**

0：接口调用成功；-5：watcher入参空指针。


### OH_HiAppEvent_TakeWatcherData()

```
int OH_HiAppEvent_TakeWatcherData (HiAppEvent_Watcher * watcher, uint32_t eventNum, OH_HiAppEvent_OnTake onTake )
```
**描述**
用于获取监听器收到后保存的事件。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| watcher | 指向监听器的指针（即OH_HiAppEvent_CreateWatcher接口返回的指针）。  | 
| eventNum | 当输入值小于等于0时，取全部已保存事件；当输入值大于0时，按照事件发生时间倒序排列，取指定数量的已保存事件。  | 
| onTake | 回调函数指针，事件通过调用该函数返回事件信息。  | 

**返回：**

0：接口调用成功；-5：watcher入参空指针；-6：还未调用OH_HiAppEvent_AddWatcher，操作顺序有误。


### OH_HiAppEvent_Write()

```
int OH_HiAppEvent_Write (const char * domain, const char * name, enum EventType type, const ParamList list )
```
**描述**
实现对参数为列表类型的应用事件打点。

在应用事件打点前，该接口会先对该事件的参数进行校验。如果校验成功，则接口会将事件写入事件文件。

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| domain | 事件领域。开发者可以根据需要自定义事件领域。事件领域名称支持数字、字母、下划线字符，需要以字母开头且不能以下划线结尾，长度非空且不超过32个字符。  | 
| name | 事件名称。开发者可以根据需要自定义事件名称。首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过48个字符。  | 
| type | 事件类型，在[EventType](#eventtype)中定义。  | 
| list | 事件参数列表，每个参数由参数名和参数值组成，其规格定义如下：<br/>1、参数名为字符串类型，首字符必须为字母字符或$字符，中间字符必须为数字字符、字母字符或下划线字符，结尾字符必须为数字字符或字母字符，长度非空且不超过32个字符。<br/>2、参数值支持字符串、数值、布尔、数组类型，字符串类型参数长度需在8\*1024个字符以内，超出会做丢弃处理；数组类型参数中的元素类型只能为字符串、数值、布尔中的一种，且元素个数需在100以内，超出会做丢弃处理。<br/>3、参数个数需在32个以内，超出的参数会做丢弃处理。 | 

**返回：**

如果事件参数校验成功，则返回0，将事件写入事件文件；如果事件中存在无效参数，则返回正值，丢弃 无效参数后将事件写入事件文件；如果事件参数校验失败，则返回负值，并且事件将不会写入事件文件。
0  事件参数校验成功。-1  非法的事件名称。-4  非法的事件领域名称。-99  打点功能被关闭。1  非法的事件参数名称。4  非法的事件参数字符串长度。5  非法的事件参数数量。6  非法的事件参数数组长度。8  重复的事件参数名称。 

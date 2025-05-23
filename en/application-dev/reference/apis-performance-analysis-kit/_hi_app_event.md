# HiAppEvent


## Overview

Provides APIs for implementing the application event logging function.

This function allows your application to record fault events, statistics events, security events, and user behavior events reported during system running. Based on the event information, you can analyze the operating status of your application.

  

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 8


## Summary


### File

| Name| Description|
| -------- | -------- |
| [hiappevent.h](hiappevent_8h.md) | Defines the application event logging functions of the HiAppEvent module.<br>**File to include**: <hiappevent/hiappevent.h><br>**Library**: libhiappevent_ndk.z.so|
| [hiappevent_cfg.h](hiappevent__cfg_8h.md) | Defines the configuration items of the event logging configuration function.<br>**File to include**: <hiappevent/hiappevent_cfg.h><br>**Library**: libhiappevent_ndk.z.so|
| [hiappevent_event.h](hiappevent__event_8h.md) | Defines the names of all predefined events.<br>**File to include**: <hiappevent/hiappevent_event.h><br>**Library**: libhiappevent_ndk.z.so|
| [hiappevent_param.h](hiappevent__param_8h.md) | Defines the names of all predefined event parameters.<br>**File to include**: <hiappevent/hiappevent_param.h><br>**Library**: libhiappevent_ndk.z.so|


### Structs

| Name| Description|
| -------- | -------- |
| struct&nbsp;&nbsp;[HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) | Defines the information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format. |
| struct&nbsp;&nbsp;[HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) | Defines the information about an event group, including its name, the array of event information grouped by name, and the length of the event array. |


### Macros

| Name| Description|
| -------- | -------- |
| [DISABLE](#disable)&nbsp;&nbsp;&nbsp;"disable" | Whether to disable event logging. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite. |
| [MAX_STORAGE](#max_storage)&nbsp;&nbsp;&nbsp;"max_storage" | Storage quota of the event file directory. The default value is **10M**. |
| [EVENT_USER_LOGIN](#event_user_login)&nbsp;&nbsp;&nbsp;"hiappevent.user_login" | User login event. |
| [EVENT_USER_LOGOUT](#event_user_logout)&nbsp;&nbsp;&nbsp;"hiappevent.user_logout" | User logout event. |
| [EVENT_DISTRIBUTED_SERVICE_START](#event_distributed_service_start)&nbsp;&nbsp;&nbsp;"hiappevent.distributed_service_start" | Distributed service event. |
| [EVENT_APP_CRASH](#event_app_crash)&nbsp;&nbsp;&nbsp;"APP_CRASH" | Application crash event. |
| [EVENT_APP_FREEZE](#event_app_freeze)&nbsp;&nbsp;&nbsp;"APP_FREEZE" | Application freeze event. |
| [EVENT_APP_LAUNCH](#event_app_launch)&nbsp;&nbsp;&nbsp;"APP_LAUNCH" | Application loading event. |
| [EVENT_SCROLL_JANK](#event_scroll_jank)&nbsp;&nbsp;&nbsp;"SCROLL_JANK" | Event indicating application freeze during swiping. |
| [EVENT_CPU_USAGE_HIGH](#event_cpu_usage_high)&nbsp;&nbsp;&nbsp;"CPU_USAGE_HIGH" | Event indicating high CPU usage of an application. |
| [EVENT_BATTERY_USAGE](#event_battery_usage)&nbsp;&nbsp;&nbsp;"BATTERY_USAGE" | Application power usage event. |
| [EVENT_RESOURCE_OVERLIMIT](#event_resource_overlimit)&nbsp;&nbsp;&nbsp;"RESOURCE_OVERLIMIT" | Application resource threshold-crossing event. |
| [EVENT_ADDRESS_SANITIZER](#event_address_sanitizer)&nbsp;&nbsp;&nbsp;"ADDRESS_SANITIZER" | Address sanitizer event. |
| [EVENT_MAIN_THREAD_JANK](#event_main_thread_jank)&nbsp;&nbsp;&nbsp;"MAIN_THREAD_JANK" | Main thread jank event. |
| [EVENT_APP_HICOLLIE](#event_app_hicollie)&nbsp;&nbsp;&nbsp;"APP_HICOLLIE" | Task execution timeout event. |
| [DOMAIN_OS](#domain_os)&nbsp;&nbsp;&nbsp;"OS" | OS scope. |
| [PARAM_USER_ID](#param_user_id)&nbsp;&nbsp;&nbsp;"user_id" | User ID. |
| [PARAM_DISTRIBUTED_SERVICE_NAME](#param_distributed_service_name)&nbsp;&nbsp;&nbsp;"ds_name" | Distributed service name. |
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](#param_distributed_service_instance_id)&nbsp;&nbsp;&nbsp;"ds_instance_id" | Distributed service instance ID. |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) [HiAppEvent_AppEventInfo](#hiappevent_appeventinfo) | Defines a struct for the information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format. |
| typedef struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) [HiAppEvent_AppEventGroup](#hiappevent_appeventgroup) | Defines a struct for the information about an event group, including its name, the array of event information grouped by name, and the length of the event array. |
| typedef struct ParamListNode \* [ParamList](#paramlist) | Defines a struct for the event parameter list node. |
| typedef struct [HiAppEvent_Watcher](#hiappevent_watcher) [HiAppEvent_Watcher](#hiappevent_watcher) | Defines a struct for the watcher for application events. |
| typedef struct [HiAppEvent_Processor](#hiappevent_processor) [HiAppEvent_Processor](#hiappevent_processor) | Defines a struct for the processor for application events. |
| typedef struct [HiAppEvent_Config](#hiappevent_config) [HiAppEvent_Config](#hiappevent_config) | Defines a struct for the configuration object used to set the conditions for triggering system events. |
| typedef void(\* [OH_HiAppEvent_OnReceive](#oh_hiappevent_onreceive)) (const char \*domain, const struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) \*appEventGroups, uint32_t groupLen) | Defines a callback invoked to pass event content to the caller. |
| typedef void(\* [OH_HiAppEvent_OnTrigger](#oh_hiappevent_ontrigger)) (int row, int size) | Defines a callback invoked if the event received by the watcher meets the conditions specified by **OH_HiAppEvent_SetTriggerCondition**. When the **OH_HiAppEvent_OnReceive** callback is not set in the watcher, the event received by the watcher will be saved.<br> After the callback is complete, if a newly saved event meets the specified condition, the callback is invoked again.|
| typedef void(\* [OH_HiAppEvent_OnTake](#oh_hiappevent_ontake)) (const char \*const \*events, uint32_t eventLen) | Defines a callback invoked to pass the events received by the watcher to the caller when **OH_HiAppEvent_TakeWatcherData** is used to obtain the events. |


### Enums

| Name| Description|
| -------- | -------- |
| [HiAppEvent_ErrorCode](#hiappevent_errorcode) {<br>HIAPPEVENT_SUCCESS = 0, <br>HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH = 4, <br>HIAPPEVENT_PROCESSOR_IS_NULL = -7, <br>HIAPPEVENT_PROCESSOR_NOT_FOUND = -8,<br>HIAPPEVENT_INVALID_PARAM_VALUE = -9, <br>HIAPPEVENT_EVENT_CONFIG_IS_NULL = -10, <br>HIAPPEVENT_OPERATE_FAILED = -100, <br>HIAPPEVENT_INVALID_UID = -200<br>} | Enumerates the error codes used in the HiAppEvent module. |
| [EventType](#eventtype) {<br>FAULT = 1, <br>STATISTIC = 2, <br>SECURITY = 3, <br>BEHAVIOR = 4 <br>} | Enumerates the event types. |


### Functions

| Name| Description|
| -------- | -------- |
| [ParamList](#paramlist) [OH_HiAppEvent_CreateParamList](#oh_hiappevent_createparamlist) (void) | Creates a pointer to a parameter list object. |
| void [OH_HiAppEvent_DestroyParamList](#oh_hiappevent_destroyparamlist) ([ParamList](#paramlist) list) | Destroys a pointer to a parameter list object and releases its allocated memory. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolParam](#oh_hiappevent_addboolparam) ([ParamList](#paramlist) list, const char \*name, bool boolean) | Adds an event parameter of the Boolean type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolArrayParam](#oh_hiappevent_addboolarrayparam) ([ParamList](#paramlist) list, const char \*name, const bool \*booleans, int arrSize) | Adds an event parameter of the Boolean array type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8Param](#oh_hiappevent_addint8param) ([ParamList](#paramlist) list, const char \*name, int8_t num) | Adds an event parameter of the int8_t type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8ArrayParam](#oh_hiappevent_addint8arrayparam) ([ParamList](#paramlist) list, const char \*name, const int8_t \*nums, int arrSize) | Adds an event parameter of the int8_t array type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16Param](#oh_hiappevent_addint16param) ([ParamList](#paramlist) list, const char \*name, int16_t num) | Adds an event parameter of the int16_t type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16ArrayParam](#oh_hiappevent_addint16arrayparam) ([ParamList](#paramlist) list, const char \*name, const int16_t \*nums, int arrSize) | Adds an event parameter of the int16_t array type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32Param](#oh_hiappevent_addint32param) ([ParamList](#paramlist) list, const char \*name, int32_t num) | Adds an event parameter of the int32_t type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32ArrayParam](#oh_hiappevent_addint32arrayparam) ([ParamList](#paramlist) list, const char \*name, const int32_t \*nums, int arrSize) | Adds an event parameter of the int32_t array type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64Param](#oh_hiappevent_addint64param) ([ParamList](#paramlist) list, const char \*name, int64_t num) | Adds an event parameter of the int64_t type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64ArrayParam](#oh_hiappevent_addint64arrayparam) ([ParamList](#paramlist) list, const char \*name, const int64_t \*nums, int arrSize) | Adds an event parameter of the int64_t array type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatParam](#oh_hiappevent_addfloatparam) ([ParamList](#paramlist) list, const char \*name, float num) | Adds an event parameter of the float type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatArrayParam](#oh_hiappevent_addfloatarrayparam) ([ParamList](#paramlist) list, const char \*name, const float \*nums, int arrSize) | Adds an event parameter of the float array type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleParam](#oh_hiappevent_adddoubleparam) ([ParamList](#paramlist) list, const char \*name, double num) | Adds an event parameter of the Double type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleArrayParam](#oh_hiappevent_adddoublearrayparam) ([ParamList](#paramlist) list, const char \*name, const double \*nums, int arrSize) | Adds an event parameter of the double array type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringParam](#oh_hiappevent_addstringparam) ([ParamList](#paramlist) list, const char \*name, const char \*str) | Adds a parameter of the string type to the parameter list. |
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringArrayParam](#oh_hiappevent_addstringarrayparam) ([ParamList](#paramlist) list, const char \*name, const char \*const \*strs, int arrSize) | Adds a parameter of the string array type to the parameter list. |
| int [OH_HiAppEvent_Write](#oh_hiappevent_write) (const char \*domain, const char \*name, enum [EventType](#eventtype) type, const [ParamList](#paramlist) list) | Logs application events whose parameters are of the list type. |
| bool [OH_HiAppEvent_Configure](#oh_hiappevent_configure) (const char \*name, const char \*value) | Configures the application event logging function. |
| [HiAppEvent_Watcher](#hiappevent_watcher) \* [OH_HiAppEvent_CreateWatcher](#oh_hiappevent_createwatcher) (const char \*name) | Creates a watcher for application events. |
| void [OH_HiAppEvent_DestroyWatcher](#oh_hiappevent_destroywatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | Destroys a created watcher. |
| int [OH_HiAppEvent_SetTriggerCondition](#oh_hiappevent_settriggercondition) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, int row, int size, int timeOut) | Sets the trigger condition of the **OH_HiAppEvent_OnTrigger** callback.<br>You can set the trigger condition by the number and size of new events received by the watcher, and **onTrigger** timeout interval. Ensure that at least one of the trigger conditions is set on the caller side.|
| int [OH_HiAppEvent_SetAppEventFilter](#oh_hiappevent_setappeventfilter) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, const char \*domain, uint8_t eventTypes, const char \*const \*names, int namesLen) | Sets the type of events to listen for. |
| int [OH_HiAppEvent_SetWatcherOnTrigger](#oh_hiappevent_setwatcherontrigger) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnTrigger](#oh_hiappevent_ontrigger) onTrigger) | Sets the **onTrigger** callback.<br>If **OnReceive** is not set or is set to **nullptr**, the application events received by the watcher will be saved. If the saved application events meet the trigger conditions of the **onTrigger** callback, the **onTrigger** callback will be called.|
| int [OH_HiAppEvent_SetWatcherOnReceive](#oh_hiappevent_setwatcheronreceive) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnReceive](#oh_hiappevent_onreceive) onReceive) | Sets the **onReceive** callback. When the listener detects the corresponding event, the onReceive callback is called. |
| int [OH_HiAppEvent_TakeWatcherData](#oh_hiappevent_takewatcherdata) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, uint32_t eventNum, [OH_HiAppEvent_OnTake](#oh_hiappevent_ontake) onTake) | Obtains the event saved by the watcher. |
| int [OH_HiAppEvent_AddWatcher](#oh_hiappevent_addwatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | Adds a watcher. Once a watcher is added, it starts to listen for system messages. |
| int [OH_HiAppEvent_RemoveWatcher](#oh_hiappevent_removewatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | Removes a watcher. Once a watcher is removed, it stops listening for system messages. |
| void [OH_HiAppEvent_ClearData](#oh_hiappevent_cleardata) () | Clears the events saved by all watchers. |
| [HiAppEvent_Processor](#hiappevent_processor) \* [OH_HiAppEvent_CreateProcessor](#oh_hiappevent_createprocessor) (const char \*name) | Creates a processor for application events. |
| int [OH_HiAppEvent_SetReportRoute](#oh_hiappevent_setreportroute) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*appId, const char \*routeInfo) | Sets the report route for the processor. |
| int [OH_HiAppEvent_SetReportPolicy](#oh_hiappevent_setreportpolicy) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, int periodReport, int batchReport, bool onStartReport, bool onBackgroundReport) | Sets the report policy for the processor. |
| int [OH_HiAppEvent_SetReportEvent](#oh_hiappevent_setreportevent) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*domain, const char \*name, bool isRealTime) | Sets the report event for the processor. |
| int [OH_HiAppEvent_SetCustomConfig](#oh_hiappevent_setcustomconfig) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*key, const char \*value) | Sets the custom extension parameters of the processor. |
| int [OH_HiAppEvent_SetConfigId](#oh_hiappevent_setconfigid) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, int configId) | Sets the configuration ID of the processor. |
| int [OH_HiAppEvent_SetReportUserId](#oh_hiappevent_setreportuserid) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*const \*userIdNames, int size) | Sets the report user ID of the processor. |
| int [OH_HiAppEvent_SetReportUserProperty](#oh_hiappevent_setreportuserproperty) ([HiAppEvent_Processor](#hiappevent_processor) \*processor, const char \*const \*userPropertyNames, int size) | Sets the report user property of the processor. |
| int64_t [OH_HiAppEvent_AddProcessor](#oh_hiappevent_addprocessor) ([HiAppEvent_Processor](#hiappevent_processor) \*processor) | Adds a processor. You can add a processor to migrate event data to the cloud. You can preset the implementation of the processor on the device and set its properties based on its constraints. |
| void [OH_HiAppEvent_DestroyProcessor](#oh_hiappevent_destroyprocessor) ([HiAppEvent_Processor](#hiappevent_processor) \*processor) | Destroys a processor. |
| int [OH_HiAppEvent_RemoveProcessor](#oh_hiappevent_removeprocessor) (int64_t processorId) | Removes a processor. Once a processor is removed, it stops reporting events. |
| [HiAppEvent_Config](#hiappevent_config) \* [OH_HiAppEvent_CreateConfig](#oh_hiappevent_createconfig) (void) | Creates a pointer to the configuration object that sets the conditions for triggering system events. |
| void [OH_HiAppEvent_DestroyConfig](#oh_hiappevent_destroyconfig) ([HiAppEvent_Config](#hiappevent_config) \*config) | Destroys a configuration object. |
| int [OH_HiAppEvent_SetConfigItem](#oh_hiappevent_setconfigitem) ([HiAppEvent_Config](#hiappevent_config) \*config, const char \*itemName, const char \*itemValue) | Sets the items in the configuration object. |
| int [OH_HiAppEvent_SetEventConfig](#oh_hiappevent_seteventconfig) (const char \*name, [HiAppEvent_Config](#hiappevent_config) \*config) | Sets the conditions for triggering system event subscription. |


## Macro Description


### DISABLE

```
#define DISABLE   "disable"
```
**Description**
Whether to disable event logging. The default value is **false**. The value **true** means to disable the event logging function, and the value **false** means the opposite.

**Since**: 8


### DOMAIN_OS

```
#define DOMAIN_OS   "OS"
```
**Description**
OS scope.

**Since**: 12


### EVENT_ADDRESS_SANITIZER

```
#define EVENT_ADDRESS_SANITIZER   "ADDRESS_SANITIZER"
```
**Description**
Address sanitizer event.

**Since**: 12


### EVENT_APP_CRASH

```
#define EVENT_APP_CRASH   "APP_CRASH"
```
**Description**
Application crash event.

**Since**: 12


### EVENT_APP_FREEZE

```
#define EVENT_APP_FREEZE   "APP_FREEZE"
```
**Description**
Application freeze event.

**Since**: 12


### EVENT_APP_HICOLLIE

```
#define EVENT_APP_HICOLLIE   "APP_HICOLLIE"
```
**Description**
Task execution timeout event.

**Since**: 18


### EVENT_APP_LAUNCH

```
#define EVENT_APP_LAUNCH   "APP_LAUNCH"
```
**Description**
Application loading event.

**Since**: 12


### EVENT_BATTERY_USAGE

```
#define EVENT_BATTERY_USAGE   "BATTERY_USAGE"
```
**Description**
Application power usage event.

**Since**: 12


### EVENT_CPU_USAGE_HIGH

```
#define EVENT_CPU_USAGE_HIGH   "CPU_USAGE_HIGH"
```
**Description**
Event indicating high CPU usage of an application.

**Since**: 12


### EVENT_DISTRIBUTED_SERVICE_START

```
#define EVENT_DISTRIBUTED_SERVICE_START   "hiappevent.distributed_service_start"
```
**Description**
Distributed service event.

**Since**: 8


### EVENT_MAIN_THREAD_JANK

```
#define EVENT_MAIN_THREAD_JANK   "MAIN_THREAD_JANK"
```
**Description**
Main thread jank event.

**Since**: 12


### EVENT_RESOURCE_OVERLIMIT

```
#define EVENT_RESOURCE_OVERLIMIT   "RESOURCE_OVERLIMIT"
```
**Description**
Application resource threshold-crossing event.

**Since**: 12


### EVENT_SCROLL_JANK

```
#define EVENT_SCROLL_JANK   "SCROLL_JANK"
```
**Description**
Event indicating application freeze during swiping.

**Since**: 12


### EVENT_USER_LOGIN

```
#define EVENT_USER_LOGIN   "hiappevent.user_login"
```
**Description**
User login event.

**Since**: 8


### EVENT_USER_LOGOUT

```
#define EVENT_USER_LOGOUT   "hiappevent.user_logout"
```
**Description**
User logout event.

**Since**: 8


### MAX_STORAGE

```
#define MAX_STORAGE   "max_storage"
```
**Description**
Storage quota of the event file directory. The default value is **10M**.

**Since**: 8


### PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID

```
#define PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID   "ds_instance_id"
```
**Description**
Distributed service instance ID.

**Since**: 8


### PARAM_DISTRIBUTED_SERVICE_NAME

```
#define PARAM_DISTRIBUTED_SERVICE_NAME   "ds_name"
```
**Description**
Distributed service name.

**Since**: 8


### PARAM_USER_ID

```
#define PARAM_USER_ID   "user_id"
```
**Description**
User ID.

**Since**: 8


## Type Description


### HiAppEvent_AppEventGroup

```
typedef struct HiAppEvent_AppEventGroupHiAppEvent_AppEventGroup
```
**Description**
Defines the information of an event group, including its name, the array of event information grouped by name, and the length of the event array.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12


### HiAppEvent_AppEventInfo

```
typedef struct HiAppEvent_AppEventInfoHiAppEvent_AppEventInfo
```
**Description**
Defines a struct for the information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format.

**Since**: 12


### HiAppEvent_Config

```
typedef struct HiAppEvent_ConfigHiAppEvent_Config
```
**Description**
Defines a struct for the configuration object used to set the conditions for triggering system events.

**Since**: 15


### HiAppEvent_Processor

```
typedef struct HiAppEvent_ProcessorHiAppEvent_Processor
```
**Description**
Defines a struct for the processor for application events.

**Since**: 18


### HiAppEvent_Watcher

```
typedef struct HiAppEvent_WatcherHiAppEvent_Watcher
```
**Description**
Defines a struct for the watcher for application events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12


### OH_HiAppEvent_OnReceive

```
typedef void(* OH_HiAppEvent_OnReceive) (const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen)
```
**Description**
Defines a callback invoked to pass event content to the caller.

Note: The lifecycle of the object pointed by the pointer in the callback is limited to the callback function. Do not use the pointer outside of the callback function. If the information needs to be cached, perform a deep copy of the content pointed by the pointer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| domain | Domain of the received application event. |
| appEventGroups | Event group array. |
| groupLen | Length of the event group array. |


### OH_HiAppEvent_OnTake

```
typedef void(* OH_HiAppEvent_OnTake) (const char *const *events, uint32_t eventLen)
```
**Description**
Defines a callback invoked to pass the events received by the watcher to the caller when OH_HiAppEvent_TakeWatcherData is used to obtain the events.

Note: The lifecycle of the object pointed by the pointer in the callback is limited to the callback function. Do not use the pointer outside of the callback function. If the information needs to be cached, perform a deep copy of the content pointed by the pointer.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| events | Event array in JSON string format. |
| eventLen | Size of the event array. |


### OH_HiAppEvent_OnTrigger

```
typedef void(* OH_HiAppEvent_OnTrigger) (int row, int size)
```
**Description**
Defines a callback invoked if the event received by the watcher meets the conditions specified by **OH_HiAppEvent_SetTriggerCondition**. When the **OH_HiAppEvent_OnReceive** callback is not set in the watcher, the event received by the watcher will be saved.

 After the callback is complete, if a newly saved event meets the specified condition, the callback is invoked again.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| row | Number of events newly received by the watcher. |
| size | Total size of events newly received by the watcher. The size of a single event is the length of the JSON string converted from the event. |


### ParamList

```
typedef struct ParamListNode* ParamList
```
**Description**
Defines a struct for the event parameter list node.

**Since**: 8


## Enum Description


### EventType

```
enum EventType
```
**Description**
Enumerates the event types.

You are advised to select an event type based on the application scenario.

**Since**: 8

| Value| Description|
| -------- | -------- |
| FAULT  | Fault event.&nbsp;&nbsp; |
| STATISTIC  | Statistics event.&nbsp;&nbsp; |
| SECURITY  | Security event.&nbsp;&nbsp; |
| BEHAVIOR  | Behavior event.&nbsp;&nbsp; |


### HiAppEvent_ErrorCode

```
enum HiAppEvent_ErrorCode
```
**Description**
Enumerates the error codes used in the HiAppEvent module.

**Since**: 15

| Value| Description|
| -------- | -------- |
| HIAPPEVENT_SUCCESS  | The operation is successful.&nbsp;&nbsp; |
| HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH  | The parameter value length is invalid.<br>**Since**: 18|
| HIAPPEVENT_PROCESSOR_IS_NULL  | The processor is null.<br>**Since**: 18|
| HIAPPEVENT_PROCESSOR_NOT_FOUND  | The processor is not found. <br/**Since**: 18|
| HIAPPEVENT_INVALID_PARAM_VALUE  | The parameter value is invalid.&nbsp;&nbsp; |
| HIAPPEVENT_EVENT_CONFIG_IS_NULL  | The event configuration is null.&nbsp;&nbsp; |
| HIAPPEVENT_OPERATE_FAILED  | The operation failed.<br>**Since**: 18|
| HIAPPEVENT_INVALID_UID  | The user ID is invalid.<br>**Since**: 18|


## Function Description


### OH_HiAppEvent_AddBoolArrayParam()

```
ParamList OH_HiAppEvent_AddBoolArrayParam (ParamList list, const char * name, const bool * booleans, int arrSize )
```
**Description**
Adds an event parameter of the Boolean array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| booleans | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddBoolParam()

```
ParamList OH_HiAppEvent_AddBoolParam (ParamList list, const char * name, bool boolean )
```
**Description**
Adds an event parameter of the Boolean type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| boolean | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddDoubleArrayParam()

```
ParamList OH_HiAppEvent_AddDoubleArrayParam (ParamList list, const char * name, const double * nums, int arrSize )
```
**Description**
Adds an event parameter of the double array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| nums | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddDoubleParam()

```
ParamList OH_HiAppEvent_AddDoubleParam (ParamList list, const char * name, double num )
```
**Description**
Adds an event parameter of the Double type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| num | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddFloatArrayParam()

```
ParamList OH_HiAppEvent_AddFloatArrayParam (ParamList list, const char * name, const float * nums, int arrSize )
```
**Description**
Adds an event parameter of the float array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| nums | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddFloatParam()

```
ParamList OH_HiAppEvent_AddFloatParam (ParamList list, const char * name, float num )
```
**Description**
Adds an event parameter of the float type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| num | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt16ArrayParam()

```
ParamList OH_HiAppEvent_AddInt16ArrayParam (ParamList list, const char * name, const int16_t * nums, int arrSize )
```
**Description**
Adds an event parameter of the int16_t array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| nums | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt16Param()

```
ParamList OH_HiAppEvent_AddInt16Param (ParamList list, const char * name, int16_t num )
```
**Description**
Adds an event parameter of the int16_t type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| num | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt32ArrayParam()

```
ParamList OH_HiAppEvent_AddInt32ArrayParam (ParamList list, const char * name, const int32_t * nums, int arrSize )
```
**Description**
Adds an event parameter of the int32_t array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| nums | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt32Param()

```
ParamList OH_HiAppEvent_AddInt32Param (ParamList list, const char * name, int32_t num )
```
**Description**
Adds an event parameter of the int32_t type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| num | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt64ArrayParam()

```
ParamList OH_HiAppEvent_AddInt64ArrayParam (ParamList list, const char * name, const int64_t * nums, int arrSize )
```
**Description**
Adds an event parameter of the int64_t array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| nums | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt64Param()

```
ParamList OH_HiAppEvent_AddInt64Param (ParamList list, const char * name, int64_t num )
```
**Description**
Adds an event parameter of the int64_t type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| num | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt8ArrayParam()

```
ParamList OH_HiAppEvent_AddInt8ArrayParam (ParamList list, const char * name, const int8_t * nums, int arrSize )
```
**Description**
Adds an event parameter of the int8_t array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| nums | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddInt8Param()

```
ParamList OH_HiAppEvent_AddInt8Param (ParamList list, const char * name, int8_t num )
```
**Description**
Adds an event parameter of the int8_t type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| num | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddProcessor()

```
int64_t OH_HiAppEvent_AddProcessor (HiAppEvent_Processor * processor)
```
**Description**
Adds a processor. You can add a processor to migrate event data to the cloud. You can preset the implementation of the processor on the device and set its properties based on its constraints.

Note that the configuration information of **Processor** must be provided by the data processor. Yet, as no data processor is preset in the device for interaction for the moment, migrating events to the cloud is unavailable.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |

**Returns**

Unique ID of the processor is returned when the API is successfully called. The value is greater than 0.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_OPERATE_FAILED** is returned when the data processor name is not found or fails to be registered.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_AddStringArrayParam()

```
ParamList OH_HiAppEvent_AddStringArrayParam (ParamList list, const char * name, const char *const * strs, int arrSize )
```
**Description**
Adds a parameter of the string array type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| strs | Value of the parameter to be added. |
| arrSize | Size of the parameter array to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddStringParam()

```
ParamList OH_HiAppEvent_AddStringParam (ParamList list, const char * name, const char * str )
```
**Description**
Adds a parameter of the string type to the parameter list.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list to which parameters need to be added. |
| name | Name of the parameter to be added. |
| str | Value of the parameter to be added. |

**Returns**

Pointer to the parameter list that contains the parameters added.


### OH_HiAppEvent_AddWatcher()

```
int OH_HiAppEvent_AddWatcher (HiAppEvent_Watcher * watcher)
```
**Description**
Adds a watcher. Once a watcher is added, it starts to listen for system messages.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |

**Returns**

**0** if the API is called successfully; **-5** if the pointer to an input parameter is null.


### OH_HiAppEvent_ClearData()

```
void OH_HiAppEvent_ClearData ()
```
**Description**
Clears the events saved by all watchers.

**Since**: 12


### OH_HiAppEvent_Configure()

```
bool OH_HiAppEvent_Configure (const char * name, const char * value )
```
**Description**
Configures the application event logging function.

This function is used to configure the event logging function and the storage quota of the event file directory.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Configuration item name. The value can be set to [DISABLE](#disable) or [MAX_STORAGE](#max_storage). |
| value | Configuration item value. If the configuration item name is [DISABLE](#disable), the value can be **true** or **false**.<br>If the configuration item name is [MAX_STORAGE](#max_storage), the quota value can contain only digits and the unit character. The unit character can be **b**\|**k**\|**kb**\|**m**\|**mb**\|**g**\|**gb**\|**t**\|**tb**, which is case insensitive.<br>The quota value must start with a digit. You can determine whether to pass the unit. If the unit is left empty, **b** (that is, byte) is used by default.|

**Returns**

Configuration result. The value **true** indicates that the configuration is successful, and the value **false** indicates the opposite.


### OH_HiAppEvent_CreateConfig()

```
HiAppEvent_Config* OH_HiAppEvent_CreateConfig (void )
```
**Description**
Creates a pointer to the configuration object that sets the conditions for triggering system events.

**Since**: 15

**Returns**

Pointer to the configuration object that sets the conditions for triggering system events.


### OH_HiAppEvent_CreateParamList()

```
ParamList OH_HiAppEvent_CreateParamList (void )
```
**Description**
Creates a pointer to a parameter list object.

**Since**: 8

**Returns**

Pointer to the parameter list object.


### OH_HiAppEvent_CreateProcessor()

```
HiAppEvent_Processor* OH_HiAppEvent_CreateProcessor (const char * name)
```
**Description**
Creates a processor for application events.

Note: If a processor is no longer used, call **OH_HiAppEvent_DestroyProcessor** to destroy it.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Processor name, which can contain only letters, digits, underscores (_), and dollar signs ($). It cannot start with a digit and cannot exceed 256 characters. |

**Returns**

Pointer to the new processor if the API is called successfully; **nullptr** if the **name** parameter is invalid.


### OH_HiAppEvent_CreateWatcher()

```
HiAppEvent_Watcher* OH_HiAppEvent_CreateWatcher (const char * name)
```
**Description**
Creates a watcher for application events.

Note: If a created watcher is no longer used, you are required to destroy it by calling OH_HiAppEvent_DestroyWatcher.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Watcher name. |

**Returns**

Pointer to the new watcher if the API is called successfully; **nullptr** if the **name** parameter is invalid.


### OH_HiAppEvent_DestroyConfig()

```
void OH_HiAppEvent_DestroyConfig (HiAppEvent_Config * config)
```
**Description**
Destroys a configuration object.

Note: If a configuration object is no longer used, destroy it to release memory to prevent memory leaks. After the object is destroyed, set its pointer to null.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the configuration object, that is, the pointer returned by the **OH_HiAppEvent_CreateConfig** API. |


### OH_HiAppEvent_DestroyParamList()

```
void OH_HiAppEvent_DestroyParamList (ParamList list)
```
**Description**
Destroys a pointer to a parameter list object and releases its allocated memory.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| list | Pointer to the parameter list object. |


### OH_HiAppEvent_DestroyProcessor()

```
void OH_HiAppEvent_DestroyProcessor (HiAppEvent_Processor * processor)
```
**Description**
Destroys a processor.

Note: If a processor is no longer used, destroy it to release memory to prevent memory leaks. After the processor is destroyed, set its pointer to null.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |


### OH_HiAppEvent_DestroyWatcher()

```
void OH_HiAppEvent_DestroyWatcher (HiAppEvent_Watcher * watcher)
```
**Description**
Destroys a created watcher.

Note: If a created watcher is no longer used, destroy it to release memory to prevent memory leaks. After the watcher is destroyed, set its pointer to null.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |


### OH_HiAppEvent_RemoveProcessor()

```
int OH_HiAppEvent_RemoveProcessor (int64_t processorId)
```
**Description**
Removes a processor. Once a processor is removed, it stops reporting events.

Note: This API only stops the processor reporting events but does not destroy the processor. You can call **OH_HiAppEvent_DestroyProcessor** to destroy the processor and release the memory.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processorId | Unique ID of a processor. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_NOT_FOUND**: The processor is not found.

**HIAPPEVENT_OPERATE_FAILED**: The operation fails.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_RemoveWatcher()

```
int OH_HiAppEvent_RemoveWatcher (HiAppEvent_Watcher * watcher)
```
**Description**
Removes a watcher. Once a watcher is removed, it stops listening for system messages.

Note: This API only enables the watcher to stop listening for system messages. It does not destroy the watcher. The watcher still resides in the memory until the OH_HiAppEvent_DestroyWatcher API is called.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |

**Returns**

**0** if the API is called successfully; **-5** if the pointer to an input parameter is null; **-6** if **OH_HiAppEvent_AddWatcher** has not been called to add a watcher.


### OH_HiAppEvent_SetAppEventFilter()

```
int OH_HiAppEvent_SetAppEventFilter (HiAppEvent_Watcher * watcher, const char * domain, uint8_t eventTypes, const char *const * names, int namesLen )
```
**Description**
Sets the type of events to listen for.

This function can be called repeatedly. You can add multiple filtering conditions instead of replacing them. The watcher will receive notifications of events that meet any of the filtering conditions.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |
| domain | Domain of events to be listened for. |
| eventTypes | Types of events to be listened for. The bitwise AND matching mode is used. Multiple types of events can be listened for. If the first bit is **1** (the value is **1**), fault events can be listened for.<br>If the second bit is **1** (the value is **2**), statistics events can be listened for.<br>If the third bit is **1** (the value is **4**), security events can be listened for.<br>If the fourth digit is **1** (the value is **8**), events of the listening behavior type can be listened for.<br>If four digits are **1** (the value is **15**) or 0 (the value is **0**), events of all types can be listened for.|
| names | Array of the event names. |
| namesLen | Length of the event name array. |

**Returns**

**0** if the API is called successfully; **-1** if the **names** parameter is invalid; **-4** if the **domain** parameter is invalid; **-5** if the pointer to an input parameter is null.


### OH_HiAppEvent_SetConfigId()

```
int OH_HiAppEvent_SetConfigId (HiAppEvent_Processor * processor, int configId )
```
**Description**
Sets the configuration ID of the processor.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |
| configId | Configuration ID of the processor, which is a natural number. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetConfigItem()

```
int OH_HiAppEvent_SetConfigItem (HiAppEvent_Config * config, const char * itemName, const char * itemValue )
```
**Description**
Sets the items in the configuration object.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to the configuration object, that is, the pointer returned by the **OH_HiAppEvent_CreateConfig** API. |
| itemName | Name of the configuration item. |
| itemValue | Value of the configuration item. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_EVENT_CONFIG_IS_NULL**: The pointer to the configuration object is null.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The configuration item is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetCustomConfig()

```
int OH_HiAppEvent_SetCustomConfig (HiAppEvent_Processor * processor, const char * key, const char * value )
```
**Description**
Sets the custom extension parameters of the processor.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |
| key | Parameter name, which contains a maximum of 32 characters. |
| value | Parameter value, which contains a maximum of 1024 characters. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

**HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH**: The parameter value length is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetEventConfig()

```
int OH_HiAppEvent_SetEventConfig (const char * name, HiAppEvent_Config * config )
```
**Description**
Sets the conditions for triggering system event subscription.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Name of the system event. |
| config | Pointer to the configuration object, that is, the pointer returned by the **OH_HiAppEvent_CreateConfig** API. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetReportEvent()

```
int OH_HiAppEvent_SetReportEvent (HiAppEvent_Processor * processor, const char * domain, const char * name, bool isRealTime )
```
**Description**
Sets the report event for the processor.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |
| domain | Domain of the report event. |
| name | Name of the report event. |
| isRealTime | Whether to report events in real time. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetReportPolicy()

```
int OH_HiAppEvent_SetReportPolicy (HiAppEvent_Processor * processor, int periodReport, int batchReport, bool onStartReport, bool onBackgroundReport )
```
**Description**
Sets the report policy for the processor.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |
| periodReport | Period for reporting events, in seconds. |
| batchReport | Threshold for reporting events. When the number of events reaches the threshold, an event is reported. |
| onStartReport | Whether to report an event when the processor is started. The default value is **false**. |
| onBackgroundReport | Whether to report an event when an application enters the background. The default value is **false**. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetReportRoute()

```
int OH_HiAppEvent_SetReportRoute (HiAppEvent_Processor * processor, const char * appId, const char * routeInfo )
```
**Description**
Sets the report route for the processor.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |
| appId | Application ID of the processor. |
| routeInfo | Server location information. The default value is an empty string. The string length cannot exceed 8 KB. Otherwise, the default value is used. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

**HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH**: The parameter value length is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetReportUserId()

```
int OH_HiAppEvent_SetReportUserId (HiAppEvent_Processor * processor, const char *const * userIdNames, int size )
```
**Description**
Sets the report user ID of the processor.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |
| userIdNames | Name array of user IDs that can be reported by the processor. |
| size | Length of the name array of user IDs. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

**HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH**: The parameter value length is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetReportUserProperty()

```
int OH_HiAppEvent_SetReportUserProperty (HiAppEvent_Processor * processor, const char *const * userPropertyNames, int size )
```
**Description**
Sets the report user property of the processor.

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| processor | Pointer to the processor, that is, the pointer returned by **OH_HiAppEvent_CreateProcessor**. |
| userPropertyNames | Name array of user properties that can be reported by the processor. |
| size | Length of the name array of user properties. |

**Returns**

**HIAPPEVENT_SUCCESS**: The API is successfully called.

**HIAPPEVENT_PROCESSOR_IS_NULL**: The input parameter of the processor is empty.

**HIAPPEVENT_INVALID_PARAM_VALUE**: The parameter value is invalid.

**HIAPPEVENT_INVALID_UID**: The user ID is invalid.

**HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH**: The parameter value length is invalid.

For details, see [HiAppEvent_ErrorCode](#hiappevent_errorcode).


### OH_HiAppEvent_SetTriggerCondition()

```
int OH_HiAppEvent_SetTriggerCondition (HiAppEvent_Watcher * watcher, int row, int size, int timeOut )
```
**Description**
Sets the trigger condition of the **OH_HiAppEvent_OnTrigger** callback.

You can set the trigger condition by the number and size of new events received by the watcher, and **onTrigger** timeout interval. Ensure that at least one of the trigger conditions is set on the caller side.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |
| row | Row count. If the input value is greater than 0 and the number of newly received events is greater than or equal to the value of this parameter, the configured **onTrigger** callback is called.<br>If the input value is less than or equal to 0, the number of received events is not used as the condition to trigger the **onTrigger** callback.|
| size | Size value. If the input value is greater than 0 and the size of the newly received event is greater than or equal to the value of this parameter, the configured **onTrigger** callback is called. The size of a single event is the length of the JSON string converted from the event. <br>If the input value is less than or equal to 0, the size of received events is not used as the condition to trigger the **onTrigger** callback.|
| timeOut | Timeout value, in seconds. If the input value is greater than 0, the system checks the watcher for newly received events based on the timeout interval. If there are any newly received events, the configured onTrigger callback is triggered.<br>After the callback is complete, the system checks the watcher for newly received events when the timeout value expires.<br>If the input value is less than or equal to 0, the timeout interval is not used as the condition to trigger the onTrigger callback.|

**Returns**

**0** if the API is called successfully; **-5** if the pointer to an input parameter is null.


### OH_HiAppEvent_SetWatcherOnReceive()

```
int OH_HiAppEvent_SetWatcherOnReceive (HiAppEvent_Watcher * watcher, OH_HiAppEvent_OnReceive onReceive )
```
**Description**
Sets the **onReceive** callback. When the listener detects the corresponding event, the onReceive callback is called.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |
| onReceive | Pointer to the callback function. |

**Returns**

**0** if the API is called successfully; **-5** if the pointer to an input parameter is null.


### OH_HiAppEvent_SetWatcherOnTrigger()

```
int OH_HiAppEvent_SetWatcherOnTrigger (HiAppEvent_Watcher * watcher, OH_HiAppEvent_OnTrigger onTrigger )
```
**Description**
Sets the **onTrigger** callback.

If **OnReceive** is not set or is set to **nullptr**, the application events received by the watcher will be saved. If the saved application events meet the trigger conditions of the **onTrigger** callback, the **onTrigger** callback will be called.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |
| onTrigger | Callback to be set. |

**Returns**

**0** if the API is called successfully; **-5** if the pointer to an input parameter is null.


### OH_HiAppEvent_TakeWatcherData()

```
int OH_HiAppEvent_TakeWatcherData (HiAppEvent_Watcher * watcher, uint32_t eventNum, OH_HiAppEvent_OnTake onTake )
```
**Description**
Obtains the event saved by the watcher.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). |
| eventNum | If the input value is less than or equal to **0**, all saved events are obtained. If the input value is greater than **0**, events are sorted by time in descending order and a specified number of saved events are obtained. |
| onTake | Pointer to the callback. The event information is returned through this callback. |

**Returns**

**0** if the API is called successfully; **-5** if the pointer to an input parameter is null; **-6** if **OH_HiAppEvent_AddWatcher** has not been called to add a watcher.


### OH_HiAppEvent_Write()

```
int OH_HiAppEvent_Write (const char * domain, const char * name, enum EventType type, const ParamList list )
```
**Description**
Logs application events whose parameters are of the list type.

Before application event logging, use this API to verify parameters of the events. If the verification is successful, the API writes the events to the event file.

**Since**: 8

**Parameters**

| Name| Description|
| -------- | -------- |
| domain | Event domain. You can customize event domains as required.<br>The value is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), and underscore (\_). It must start with a letter and cannot end with an underscore (\_).|
| name | Event name. You can customize event names as required.<br>The value is a string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), underscore (\_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter. |
| type | Event type, which is defined in [EventType](#eventtype). |
| list | List of event parameters, each of which consists of a parameter name and a parameter value. The specifications are as follows:<br>1.<br>The value is a string that contains a maximum of 32 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign (`$`). It must start with a letter or dollar sign (`$`) and end with a digit or letter.<br>2. The parameter value can be a string, number, Boolean, or array. The length of a string must be less than 8 × 1024 characters. If this limit is exceeded, excess characters will be discarded.<br>The element type of an array parameter can only be a string, number, or Boolean, and the number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.<br>3. The maximum number of parameters is 32. If this limit is exceeded, excess parameters will be discarded.|

**Returns**

If the event parameters are successfully verified, **0** is returned and the event is written into the event file.

If an event contains invalid parameters, a positive value is returned. The event is written into the event file after the invalid parameters are discarded.

If the event parameter fails to be verified, a negative value is returned and the event is not written to the event file.
**0**: The event parameter is valid. **-1**: The event name is invalid. **-4**: The event domain name is invalid. **-99**: The application event logging is disabled. **1**: The event parameter name is invalid. **4**: The length of the event parameter string is invalid. **5**: The number of event parameters is invalid. **6**: The length of the event parameter array is invalid. **8**: The event parameter name is duplicate.

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
| [hiappevent_cfg.h](hiappevent__cfg_8h.md) | Defines the configuration items of the event logging configuration function.<br>**File to include**: <hiappevent/hiappevent_event.h><br>**Library**: libhiappevent_ndk.z.so| 
| [hiappevent_event.h](hiappevent__event_8h.md) | Defines the names of all predefined events.<br>**File to include**: <hiappevent/hiappevent_param.h><br>**Library**: libhiappevent_ndk.z.so| 
| [hiappevent_param.h](hiappevent__param_8h.md) | Defines the names of all predefined event parameters.<br>**File to include**: <hiappevent/hiappevent_cfg.h><br>**Library**: libhiappevent_ndk.z.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) | Defines information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format. | 
| struct&nbsp;&nbsp;[HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) | Event array with the same event name. | 


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
| [DOMAIN_OS](#domain_os)&nbsp;&nbsp;&nbsp;"OS" | OS scope. | 
| [PARAM_USER_ID](#param_user_id)&nbsp;&nbsp;&nbsp;"user_id" | User ID. | 
| [PARAM_DISTRIBUTED_SERVICE_NAME](#param_distributed_service_name)&nbsp;&nbsp;&nbsp;"ds_name" | Distributed service name. | 
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](#param_distributed_service_instance_id)&nbsp;&nbsp;&nbsp;"ds_instance_id" | Distributed service instance ID. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) [HiAppEvent_AppEventInfo](#hiappevent_appeventinfo) | Information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format. | 
| typedef struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) [HiAppEvent_AppEventGroup](#hiappevent_appeventgroup) | Event array with the same event name. | 
| typedef struct ParamListNode \* [ParamList](#paramlist) | Event parameter list node. | 
| typedef struct [HiAppEvent_Watcher](#hiappevent_watcher) [HiAppEvent_Watcher](#hiappevent_watcher) | Watcher for application events. | 
| typedef void(\* [OH_HiAppEvent_OnReceive](#oh_hiappevent_onreceive)) (const char \*domain, const struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) \*appEventGroups, uint32_t groupLen) | Callback invoked to pass event content to the caller. | 
| typedef void(\* [OH_HiAppEvent_OnTrigger](#oh_hiappevent_ontrigger)) (int row, int size) | Callback invoked if the event received by the watcher meets the conditions specified by **OH_HiAppEvent_SetTriggerCondition**. Specifically, if the **OH_HiAppEvent_OnReceive** callback is not set in the watcher, the event received by the watcher will be saved. If the saved event meets the conditions specified by OH_HiAppEvent_SetTriggerCondition, the callback is invoked. After the callback is complete, if a newly saved event meets the specified condition, the callback is invoked again. | 
| typedef void(\* [OH_HiAppEvent_OnTake](#oh_hiappevent_ontake)) (const char \*const \*events, uint32_t eventLen) | Callback invoked to pass the events received by the watcher to the caller when OH_HiAppEvent_TakeWatcherData is used to obtain the events. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [EventType](#eventtype) { **FAULT** = 1, **STATISTIC** = 2, **SECURITY** = 3, **BEHAVIOR** = 4 } | Event type. | 


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
| int [OH_HiAppEvent_SetTriggerCondition](#oh_hiappevent_settriggercondition) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, int row, int size, int timeOut) | Sets the conditions for triggering the **OH_HiAppEvent_OnTrigger** callback, including the number and size of newly received events and the timeout interval for triggering **onTrigger**. Ensure that at least one of the trigger conditions is set on the caller side. | 
| int [OH_HiAppEvent_SetAppEventFilter](#oh_hiappevent_setappeventfilter) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, const char \*domain, uint8_t eventTypes, const char \*const \*names, int namesLen) | Sets the type of events to listen for. | 
| int [OH_HiAppEvent_SetWatcherOnTrigger](#oh_hiappevent_setwatcherontrigger) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnTrigger](#oh_hiappevent_ontrigger) onTrigger) | Sets the **onTrigger** callback. | 
| int [OH_HiAppEvent_SetWatcherOnReceive](#oh_hiappevent_setwatcheronreceive) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnReceive](#oh_hiappevent_onreceive) onReceive) | Sets the **onReceive** callback. When the listener detects the corresponding event, the onReceive callback is called. | 
| int [OH_HiAppEvent_TakeWatcherData](#oh_hiappevent_takewatcherdata) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher, uint32_t eventNum, [OH_HiAppEvent_OnTake](#oh_hiappevent_ontake) onTake) | Obtains the event saved by the watcher. | 
| int [OH_HiAppEvent_AddWatcher](#oh_hiappevent_addwatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | Adds a watcher. Once a watcher is added, it starts to listen for system messages. | 
| int [OH_HiAppEvent_RemoveWatcher](#oh_hiappevent_removewatcher) ([HiAppEvent_Watcher](#hiappevent_watcher) \*watcher) | Removes a watcher. Once a watcher is removed, it stops listening for system messages. | 
| void [OH_HiAppEvent_ClearData](#oh_hiappevent_cleardata) (void) | Clears the events saved by all watchers. | 


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


### EVENT_APP_CRASH

```
#define EVENT_APP_CRASH   "APP_CRASH"
```
**Description**
Defines an application crash event.

**Since**: 12


### EVENT_APP_FREEZE

```
#define EVENT_APP_FREEZE   "APP_FREEZE"
```
**Description**
Defines an application freeze event.

**Since**: 12


### EVENT_APP_LAUNCH

```
#define EVENT_APP_LAUNCH   "APP_LAUNCH"
```
**Description**
Defines an application loading event.

**Since**: 12


### EVENT_BATTERY_USAGE

```
#define EVENT_BATTERY_USAGE   "BATTERY_USAGE"
```
**Description**
Defines an application power usage event.

**Since**: 12


### EVENT_CPU_USAGE_HIGH

```
#define EVENT_CPU_USAGE_HIGH   "CPU_USAGE_HIGH"
```
**Description**
Defines an event indicating high CPU usage of an application.

**Since**: 12


### EVENT_DISTRIBUTED_SERVICE_START

```
#define EVENT_DISTRIBUTED_SERVICE_START   "hiappevent.distributed_service_start"
```
**Description**
Distributed service event.

**Since**: 8


### EVENT_RESOURCE_OVERLIMIT

```
#define EVENT_RESOURCE_OVERLIMIT   "RESOURCE_OVERLIMIT"
```
**Description**
Defines an application resource threshold-crossing event.

**Since**: 12


### EVENT_SCROLL_JANK

```
#define EVENT_SCROLL_JANK   "SCROLL_JANK"
```
**Description**
Defines an event indicating application freeze during swiping.

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
Defines an event array with the same event name.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12


### HiAppEvent_AppEventInfo

```
typedef struct HiAppEvent_AppEventInfoHiAppEvent_AppEventInfo
```
**Description**
Defines information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12


### HiAppEvent_Watcher

```
typedef struct HiAppEvent_WatcherHiAppEvent_Watcher
```
**Description**
Defines the watcher for application events.

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12


### OH_HiAppEvent_OnReceive

```
typedef void(* OH_HiAppEvent_OnReceive) (const char *domain, const struct HiAppEvent_AppEventGroup *appEventGroups, uint32_t groupLen)
```
**Description**
Defines the callback invoked to pass event content to the caller.

Note: The lifecycle of the object pointed by the pointer in the callback is limited to the callback function. Do not use the pointer outside of the callback function. If the information needs to be cached, perform a deep copy of the content pointed by the pointer.

\@SystemCapability.HiviewDFX.HiAppEvent

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
Defines the callback invoked to pass the events received by the watcher to the caller when OH_HiAppEvent_TakeWatcherData is used to obtain the events.

Note: The lifecycle of the object pointed by the pointer in the callback is limited to the callback function. Do not use the pointer outside of the callback function. If the information needs to be cached, perform a deep copy of the content pointed by the pointer.

\@SystemCapability.HiviewDFX.HiAppEvent

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
Defines the callback invoked if the event received by the watcher meets the conditions specified by **OH_HiAppEvent_SetTriggerCondition**. Specifically, if the **OH_HiAppEvent_OnReceive** callback is not set in the watcher, the event received by the watcher will be saved. If the saved event meets the conditions specified by OH_HiAppEvent_SetTriggerCondition, the callback is invoked. After the callback is complete, if a newly saved event meets the specified condition, the callback is invoked again.

\@SystemCapability.HiviewDFX.HiAppEvent

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
Event parameter list node.

**Since**: 8


## Enum Description


### EventType

```
enum EventType
```
**Description**
Enumerates the event types.

You are advised to select different event types based on application scenarios.

**Since**: 8

| Value| Description| 
| -------- | -------- |
| FAULT | Fault event.| 
| STATISTIC | Statistics event.| 
| SECURITY | Security event.| 
| BEHAVIOR | Behavior event.| 


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

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 

**Returns**

**0** if the API is called successfully; **-5** if the pointer of an input parameter is null.


### OH_HiAppEvent_ClearData()

```
void OH_HiAppEvent_ClearData (void )
```
**Description**
Clears the events saved by all watchers.

\@SystemCapability.HiviewDFX.HiAppEvent

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
| value | Configuration item value. If the configuration item name is [DISABLE](#disable), the value can be **true** or **false**. If the configuration item name is [MAX_STORAGE](#max_storage), the quota value can contain only digits and a unit, which can be one of [b\|k\|kb\|m\|mb\|g\|gb\|t\|tb] and is case insensitive. The quota value string must start with a digit and can end with or without a unit. If no unit is specified, byte is used by default. | 

**Returns**

Configuration result. The value **true** indicates that the configuration is successful, and the value **false** indicates the opposite.


### OH_HiAppEvent_CreateParamList()

```
ParamList OH_HiAppEvent_CreateParamList (void )
```
**Description**
Creates a pointer to a parameter list object.

**Since**: 8

**Returns**

Pointer to the parameter list object.


### OH_HiAppEvent_CreateWatcher()

```
HiAppEvent_Watcher* OH_HiAppEvent_CreateWatcher (const char * name)
```
**Description**
Creates a watcher for application events.

Note: If a created watcher is no longer used, you are required to destroy it by calling OH_HiAppEvent_DestroyWatcher.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Watcher name. | 

**Returns**

Pointer to the new watcher if the API is called successfully; **nullptr** if the **name** parameter is invalid.


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


### OH_HiAppEvent_DestroyWatcher()

```
void OH_HiAppEvent_DestroyWatcher (HiAppEvent_Watcher * watcher)
```
**Description**
Destroys a created watcher.

Note: If a created watcher is no longer used, destroy it to release memory to prevent memory leakage. After the watcher is destroyed, set its pointer to null.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 


### OH_HiAppEvent_RemoveWatcher()

```
int OH_HiAppEvent_RemoveWatcher (HiAppEvent_Watcher * watcher)
```
**Description**
Removes a watcher. Once a watcher is removed, it stops listening for system messages.

Note: This API only enables the watcher to stop listening for system messages. It does not destroy the watcher. The watcher still resides in the memory until the OH_HiAppEvent_DestroyWatcher API is called.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 

**Returns**

**0** if the API is called successfully; **-5** if the pointer of an input parameter is null; **-6** if **OH_HiAppEvent_AddWatcher** has not been called to add a watcher.


### OH_HiAppEvent_SetAppEventFilter()

```
int OH_HiAppEvent_SetAppEventFilter (HiAppEvent_Watcher * watcher, const char * domain, uint8_t eventTypes, const char *const * names, int namesLen )
```
**Description**
Sets the type of events to listen for.

This function can be called repeatedly. You can add multiple filtering conditions instead of replacing them. The watcher will receive notifications of events that meet any of the filtering conditions.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 
| domain | Domain of events to be listened for. | 
| eventTypes | Types of events to be listened for. The bitwise AND matching mode is used. Multiple types of events can be intercepted. If the first bit is 1 (the value is 1), fault events can be intercepted. If the second bit is 1 (the value is 2), statistics events can be intercepted. If the third bit is 1 (the value is 4), security events can be intercepted, if the fourth digit is 1 (the value is 8), events of the listening behavior type are supported. If the fourth digit is 1 (the value is 15) or 0 (the value is 0), events of all types are supported. | 
| names | Array of the event names. | 
| namesLen | Length of the event name array. | 

**Returns**

**0** if the API is called successfully; **-1** if the **names** parameter is invalid; **-4** if the **domain** parameter is invalid; **-5** if the pointer of an input parameter is null.


### OH_HiAppEvent_SetTriggerCondition()

```
int OH_HiAppEvent_SetTriggerCondition (HiAppEvent_Watcher * watcher, int row, int size, int timeOut )
```
**Description**
Sets the conditions for triggering the **OH_HiAppEvent_OnTrigger** callback, including the number and size of newly received events and the timeout interval for triggering **onTrigger**. Ensure that at least one of the trigger conditions is set on the caller side.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 
| row | Row count. If the input value is greater than 0 and the number of newly received events is greater than or equal to the value of this parameter, the configured onTrigger callback is called. If the input value is less than or equal to 0, the number of received events is not used as the condition to trigger the onTrigger callback. | 
| size | Size value. If the input value is greater than 0 and the size of the newly received event is greater than or equal to the value of this parameter, the configured onTrigger callback is called. The size of a single event is the length of the JSON string converted from the event. If the input value is less than or equal to 0, the size of received events is not used as the condition to trigger the onTrigger callback. | 
| timeOut | Timeout value, in seconds. If the input value is greater than 0, the system checks the watcher for newly received events based on the timeout interval. If there are any newly received events, the configured onTrigger callback is triggered. After the callback is complete, the system checks the watcher for newly received events when the timeout value expires. If the input value is less than or equal to 0, the timeout interval is not used as the condition to trigger the onTrigger callback. | 

**Returns**

**0** if the API is called successfully; **-5** if the pointer of an input parameter is null.


### OH_HiAppEvent_SetWatcherOnReceive()

```
int OH_HiAppEvent_SetWatcherOnReceive (HiAppEvent_Watcher * watcher, OH_HiAppEvent_OnReceive onReceive )
```
**Description**
Sets the **onReceive** callback. When the listener detects the corresponding event, the onReceive callback is called.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 
| onReceive | Pointer to the callback function. | 

**Returns**

**0** if the API is called successfully; **-5** if the pointer of an input parameter is null.


### OH_HiAppEvent_SetWatcherOnTrigger()

```
int OH_HiAppEvent_SetWatcherOnTrigger (HiAppEvent_Watcher * watcher, OH_HiAppEvent_OnTrigger onTrigger )
```
**Description**
Sets the **onTrigger** callback.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 
| onTrigger | Callback to be set. | 

**Returns**

**0** if the API is called successfully; **-5** if the pointer of an input parameter is null.


### OH_HiAppEvent_TakeWatcherData()

```
int OH_HiAppEvent_TakeWatcherData (HiAppEvent_Watcher * watcher, uint32_t eventNum, OH_HiAppEvent_OnTake onTake )
```
**Description**
Obtains the event saved by the watcher.

\@SystemCapability.HiviewDFX.HiAppEvent

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| watcher | Pointer to the watcher (that is, the pointer returned by OH_HiAppEvent_CreateWatcher). | 
| eventNum | If the input value is less than or equal to **0**, all saved events are obtained. If the input value is greater than **0**, events are sorted by time in descending order and a specified number of saved events are obtained. | 
| onTake | Pointer to the callback. The event information is returned through this callback. | 

**Returns**

**0** if the API is called successfully; **-5** if the pointer of an input parameter is null; **-6** if **OH_HiAppEvent_AddWatcher** has not been called to add a watcher.


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
| domain | Event domain. You can customize event domains as required. The value is a string of up to 32 characters, including digits (0 to 9), letters (a to z), and underscores (\_). It must start with a letter and cannot end with an underscore (_). | 
| name | Event name. You can customize event names as required. The value is string that contains a maximum of 48 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must start with a letter or dollar sign ($) and end with a digit or letter. | 
| type | Event type, which is defined in [EventType](#eventtype). | 
| list | List of event parameters, each of which consists of a parameter name and a parameter value. The specifications are as follows:<br>1. A parameter name is a string that contains a maximum of 16 characters, including digits (0 to 9), letters (a to z), underscore (_), and dollar sign ($). It must start with a letter or dollar sign ($) and end with a digit or letter.<br>2. The parameter value can be string, number, Boolean, or array. The length of a parameter of the string type must be less than 8 × 1024 characters. If this limit is exceeded, the parameter will be discarded. The element type of an array parameter can only be string, number, or Boolean, and the number of elements must be less than 100. If this limit is exceeded, excess elements will be discarded.<br>3. The maximum number of parameters is 32. If this limit is exceeded, excess parameters will be discarded.| 

**Returns**

The value **0** indicates that the event parameter is valid, and the event will be written to the event file asynchronously. A value greater than **0** indicates that invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored. A value smaller than **0** indicates that the event parameter verification fails, and the event will not be written to the event file. 0 The event parameter is valid. -1 The event name is invalid. -4 The event domain name is invalid. -99 The application event logging is disabled. 1 The event parameter name is invalid. 4 The length of the event parameter string is invalid. 5 The number of event parameters is invalid. 6 The length of the event parameter array is invalid. 8 The event parameter name is duplicate.

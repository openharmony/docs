# hiappevent.h


## Overview

Defines the application event logging functions of the HiAppEvent module.

Before performing application event logging, you must construct a parameter list object to store the input event parameters and specify the event domain, event name, and event type.

Event domain: domain associated with the application event.

Event name: name of the application event.

Event type: fault, statistics, security, or behavior.

Parameter list: a linked list used to store event parameters. Each parameter consists of a parameter name and a parameter value.

Example:

1. Import the header file.
   ```
   #include "hiappevent/hiappevent.h"
   ```

2. Create a parameter list pointer.
   ```
   ParamList list = OH_HiAppEvent_CreateParamList();
   ```

3. Add parameters to the parameter list.
   ```
   bool boolean = true;
   OH_HiAppEvent_AddBoolParam(list, "bool_key", boolean);
   int32_t nums[] = {1, 2, 3};
   OH_HiAppEvent_AddInt32ArrayParam(list, "int32_arr_key", nums, sizeof(nums) / sizeof(nums[0]));
   ```

4. Perform event logging.
   ```
   int res = OH_HiAppEvent_Write("test_domain", "test_event", BEHAVIOR, list);
   ```

5. Destroy the parameter list pointer and release its allocated memory.
   ```
   OH_HiAppEvent_DestroyParamList(list);
   ```

**File to include**: <hiappevent/hiappevent.h>

**Library**: libhiappevent_ndk.z.so

**System capability**: SystemCapability.HiviewDFX.HiAppEvent

**Since**: 8

**Related module**: [HiAppEvent](_hi_app_event.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) | Defines the information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format. | 
| struct&nbsp;&nbsp;[HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) | Defines the information about an event group, including its name, the array of event information grouped by name, and the length of the event array. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) [HiAppEvent_AppEventInfo](_hi_app_event.md#hiappevent_appeventinfo) | Defines a struct for the information about a single event, including the event domain, event name, event type, and custom parameter list in JSON string format. | 
| typedef struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) [HiAppEvent_AppEventGroup](_hi_app_event.md#hiappevent_appeventgroup) | Defines a struct for the information about an event group, including its name, the array of event information grouped by name, and the length of the event array. | 
| typedef struct ParamListNode \* [ParamList](_hi_app_event.md#paramlist) | Defines a struct for the event parameter list node. | 
| typedef struct [HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) [HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) | Defines a struct for the watcher for application events. | 
| typedef struct [HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) [HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) | Defines a struct for the processor for application events. | 
| typedef struct [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) | Defines a struct for the configuration object used to set the conditions for triggering system events. | 
| typedef void(\* [OH_HiAppEvent_OnReceive](_hi_app_event.md#oh_hiappevent_onreceive)) (const char \*domain, const struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) \*appEventGroups, uint32_t groupLen) | Defines a callback invoked to pass event content to the caller. | 
| typedef void(\* [OH_HiAppEvent_OnTrigger](_hi_app_event.md#oh_hiappevent_ontrigger)) (int row, int size) | Defines a callback invoked if the event received by the watcher meets the conditions specified by **OH_HiAppEvent_SetTriggerCondition**. When the **OH_HiAppEvent_OnReceive** callback is not set in the watcher, the event received by the watcher will be saved.<br>If the saved event meets the conditions specified by **OH_HiAppEvent_SetTriggerCondition**, the callback is triggered. After the callback is complete, if a newly saved event meets the specified condition, the callback is invoked again.| 
| typedef void(\* [OH_HiAppEvent_OnTake](_hi_app_event.md#oh_hiappevent_ontake)) (const char \*const \*events, uint32_t eventLen) | Defines a callback invoked to pass the events received by the watcher to the caller when **OH_HiAppEvent_TakeWatcherData** is used to obtain the events. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [HiAppEvent_ErrorCode](_hi_app_event.md#hiappevent_errorcode) {<br>HIAPPEVENT_SUCCESS = 0, <br>HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH = 4, <br>HIAPPEVENT_PROCESSOR_IS_NULL = -7, <br>HIAPPEVENT_PROCESSOR_NOT_FOUND = -8,<br>HIAPPEVENT_INVALID_PARAM_VALUE = -9, <br>HIAPPEVENT_EVENT_CONFIG_IS_NULL = -10, <br>HIAPPEVENT_OPERATE_FAILED = -100, <br>HIAPPEVENT_INVALID_UID = -200<br>} | Enumerates the error codes used in the HiAppEvent module. | 
| [EventType](_hi_app_event.md#eventtype)  {<br>FAULT = 1, <br>STATISTIC = 2, <br>SECURITY = 3, <br>BEHAVIOR = 4<br>} | Enumerates the event types. | 


### Callback

| Name| Description| 
| -------- | -------- |
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_CreateParamList](_hi_app_event.md#oh_hiappevent_createparamlist) (void) | Creates a pointer to a parameter list object. | 
| void [OH_HiAppEvent_DestroyParamList](_hi_app_event.md#oh_hiappevent_destroyparamlist) ([ParamList](_hi_app_event.md#paramlist) list) | Destroys a pointer to a parameter list object and releases its allocated memory. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddBoolParam](_hi_app_event.md#oh_hiappevent_addboolparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, bool boolean) | Adds an event parameter of the Boolean type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddBoolArrayParam](_hi_app_event.md#oh_hiappevent_addboolarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const bool \*booleans, int arrSize) | Adds an event parameter of the Boolean array type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt8Param](_hi_app_event.md#oh_hiappevent_addint8param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int8_t num) | Adds an event parameter of the int8_t type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt8ArrayParam](_hi_app_event.md#oh_hiappevent_addint8arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int8_t \*nums, int arrSize) | Adds an event parameter of the int8_t array type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt16Param](_hi_app_event.md#oh_hiappevent_addint16param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int16_t num) | Adds an event parameter of the int16_t type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt16ArrayParam](_hi_app_event.md#oh_hiappevent_addint16arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int16_t \*nums, int arrSize) | Adds an event parameter of the int16_t array type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt32Param](_hi_app_event.md#oh_hiappevent_addint32param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int32_t num) | Adds an event parameter of the int32_t type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt32ArrayParam](_hi_app_event.md#oh_hiappevent_addint32arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int32_t \*nums, int arrSize) | Adds an event parameter of the int32_t array type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt64Param](_hi_app_event.md#oh_hiappevent_addint64param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int64_t num) | Adds an event parameter of the int64_t type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt64ArrayParam](_hi_app_event.md#oh_hiappevent_addint64arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int64_t \*nums, int arrSize) | Adds an event parameter of the int64_t array type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddFloatParam](_hi_app_event.md#oh_hiappevent_addfloatparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, float num) | Adds an event parameter of the float type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddFloatArrayParam](_hi_app_event.md#oh_hiappevent_addfloatarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const float \*nums, int arrSize) | Adds an event parameter of the float array type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddDoubleParam](_hi_app_event.md#oh_hiappevent_adddoubleparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, double num) | Adds an event parameter of the Double type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddDoubleArrayParam](_hi_app_event.md#oh_hiappevent_adddoublearrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const double \*nums, int arrSize) | Adds an event parameter of the double array type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddStringParam](_hi_app_event.md#oh_hiappevent_addstringparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const char \*str) | Adds a parameter of the string type to the parameter list. | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddStringArrayParam](_hi_app_event.md#oh_hiappevent_addstringarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const char \*const \*strs, int arrSize) | Adds a parameter of the string array type to the parameter list. | 
| int [OH_HiAppEvent_Write](_hi_app_event.md#oh_hiappevent_write) (const char \*domain, const char \*name, enum [EventType](_hi_app_event.md#eventtype) type, const [ParamList](_hi_app_event.md#paramlist) list) | Logs application events whose parameters are of the list type. | 
| bool [OH_HiAppEvent_Configure](_hi_app_event.md#oh_hiappevent_configure) (const char \*name, const char \*value) | Configures the application event logging function. | 
| [HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \* [OH_HiAppEvent_CreateWatcher](_hi_app_event.md#oh_hiappevent_createwatcher) (const char \*name) | Creates a watcher for application events. | 
| void [OH_HiAppEvent_DestroyWatcher](_hi_app_event.md#oh_hiappevent_destroywatcher) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher) | Destroys a created watcher. | 
| int [OH_HiAppEvent_SetTriggerCondition](_hi_app_event.md#oh_hiappevent_settriggercondition) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, int row, int size, int timeOut) | Sets the trigger condition of the **OH_HiAppEvent_OnTrigger** callback.<br>You can set the trigger condition by the number and size of new events received by the watcher, and **onTrigger** timeout interval. Ensure that at least one of the trigger conditions is set on the caller side.| 
| int [OH_HiAppEvent_SetAppEventFilter](_hi_app_event.md#oh_hiappevent_setappeventfilter) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, const char \*domain, uint8_t eventTypes, const char \*const \*names, int namesLen) | Sets the type of events to listen for. | 
| int [OH_HiAppEvent_SetWatcherOnTrigger](_hi_app_event.md#oh_hiappevent_setwatcherontrigger) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnTrigger](_hi_app_event.md#oh_hiappevent_ontrigger) onTrigger) | Sets the **onTrigger** callback.<br>If **OnReceive** is not set or is set to **nullptr**, the application events received by the watcher will be saved. If the saved application events meet the trigger conditions of the **onTrigger** callback, the **onTrigger** callback will be called.| 
| int [OH_HiAppEvent_SetWatcherOnReceive](_hi_app_event.md#oh_hiappevent_setwatcheronreceive) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnReceive](_hi_app_event.md#oh_hiappevent_onreceive) onReceive) | Sets the **onReceive** callback. When the watcher detects the corresponding event, the **onReceive** callback is called. | 
| int [OH_HiAppEvent_TakeWatcherData](_hi_app_event.md#oh_hiappevent_takewatcherdata) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, uint32_t eventNum, [OH_HiAppEvent_OnTake](_hi_app_event.md#oh_hiappevent_ontake) onTake) | Obtains the event saved by the watcher. | 
| int [OH_HiAppEvent_AddWatcher](_hi_app_event.md#oh_hiappevent_addwatcher) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher) | Adds a watcher. Once a watcher is added, it starts to listen for system messages. | 
| int [OH_HiAppEvent_RemoveWatcher](_hi_app_event.md#oh_hiappevent_removewatcher) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher) | Removes a watcher. Once a watcher is removed, it stops listening for system messages. | 
| void [OH_HiAppEvent_ClearData](_hi_app_event.md#oh_hiappevent_cleardata) () | Clears the events saved by all watchers. | 
| [HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \* [OH_HiAppEvent_CreateProcessor](_hi_app_event.md#oh_hiappevent_createprocessor) (const char \*name) | Creates a processor for application events. | 
| int [OH_HiAppEvent_SetReportRoute](_hi_app_event.md#oh_hiappevent_setreportroute) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*appId, const char \*routeInfo) | Sets the report route for a processor. | 
| int [OH_HiAppEvent_SetReportPolicy](_hi_app_event.md#oh_hiappevent_setreportpolicy) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, int periodReport, int batchReport, bool onStartReport, bool onBackgroundReport) | Sets the report policy for a processor. | 
| int [OH_HiAppEvent_SetReportEvent](_hi_app_event.md#oh_hiappevent_setreportevent) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*domain, const char \*name, bool isRealTime) | Sets the report event for a processor. | 
| int [OH_HiAppEvent_SetCustomConfig](_hi_app_event.md#oh_hiappevent_setcustomconfig) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*key, const char \*value) | Sets the custom extension parameters of a processor. | 
| int [OH_HiAppEvent_SetConfigId](_hi_app_event.md#oh_hiappevent_setconfigid) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, int configId) | Sets the configuration ID of a processor. | 
| int [OH_HiAppEvent_SetReportUserId](_hi_app_event.md#oh_hiappevent_setreportuserid) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*const \*userIdNames, int size) | Sets the report user ID of a processor. | 
| int [OH_HiAppEvent_SetReportUserProperty](_hi_app_event.md#oh_hiappevent_setreportuserproperty) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*const \*userPropertyNames, int size) | Sets the report user property of the processor. | 
| int64_t [OH_HiAppEvent_AddProcessor](_hi_app_event.md#oh_hiappevent_addprocessor) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor) | Adds a processor. You can add a processor to migrate event data to the cloud. You can preset the implementation of the processor on the device and set its properties based on its constraints. | 
| void [OH_HiAppEvent_DestroyProcessor](_hi_app_event.md#oh_hiappevent_destroyprocessor) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor) | Destroys a processor. | 
| int [OH_HiAppEvent_RemoveProcessor](_hi_app_event.md#oh_hiappevent_removeprocessor) (int64_t processorId) | Removes a processor. Once a processor is removed, it stops reporting events. | 
| [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \* [OH_HiAppEvent_CreateConfig](_hi_app_event.md#oh_hiappevent_createconfig) (void) | Creates a pointer to the configuration object that sets the conditions for triggering system events. | 
| void [OH_HiAppEvent_DestroyConfig](_hi_app_event.md#oh_hiappevent_destroyconfig) ([HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \*config) | Destroys a configuration object. | 
| int [OH_HiAppEvent_SetConfigItem](_hi_app_event.md#oh_hiappevent_setconfigitem) ([HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \*config, const char \*itemName, const char \*itemValue) | Sets the items in the configuration object. | 
| int [OH_HiAppEvent_SetEventConfig](_hi_app_event.md#oh_hiappevent_seteventconfig) (const char \*name, [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \*config) | Sets the conditions for triggering system event subscription. | 

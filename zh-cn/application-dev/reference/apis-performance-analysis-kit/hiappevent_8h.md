# hiappevent.h


## 概述

HiAppEvent模块的应用事件打点函数定义。

在执行应用事件打点之前，您必须先构造一个参数列表对象来存储输入的事件参数，并指定事件领域、事件名称和事件类型。

事件领域：用于标识事件打点的领域的字符串。

事件名称：用于标识事件打点的名称的字符串。

事件类型：故障、统计、安全、行为。

参数列表：用于存储事件参数的链表，每个参数由参数名和参数值组成。

示例代码：

1. 引入头文件：
   ```
   #include "hiappevent/hiappevent.h"
   ```

2. 创建一个参数列表指针：
   ```
   ParamList list = OH_HiAppEvent_CreateParamList();
   ```

3. 添加参数到参数列表中：
   ```
   bool boolean = true;
   OH_HiAppEvent_AddBoolParam(list, "bool_key", boolean);
   int32_t nums[] = {1, 2, 3};
   OH_HiAppEvent_AddInt32ArrayParam(list, "int32_arr_key", nums, sizeof(nums) / sizeof(nums[0]));
   ```

4. 执行事件打点：
   ```
   int res = OH_HiAppEvent_Write("test_domain", "test_event", BEHAVIOR, list);
   ```

5. 销毁参数列表指针，释放其分配内存：
   ```
   OH_HiAppEvent_DestroyParamList(list);
   ```

**引用文件：** &lt;hiappevent/hiappevent.h&gt;

**库：** libhiappevent_ndk.z.so

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**起始版本：** 8

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) | 单个事件信息，包含事件领域，事件名称，事件类型和json格式字符串表示的事件中携带的自定义参数列表。  | 
| struct&nbsp;&nbsp;[HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) | 一组事件信息，包含事件组的名称，按名称分组的单个事件信息数组，事件数组的长度。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [HiAppEvent_AppEventInfo](_hi_app_event___app_event_info.md) [HiAppEvent_AppEventInfo](_hi_app_event.md#hiappevent_appeventinfo) | 单个事件信息，包含事件领域，事件名称，事件类型和json格式字符串表示的事件中携带的自定义参数列表。  | 
| typedef struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) [HiAppEvent_AppEventGroup](_hi_app_event.md#hiappevent_appeventgroup) | 一组事件信息，包含事件组的名称，按名称分组的单个事件信息数组，事件数组的长度。  | 
| typedef struct ParamListNode \* [ParamList](_hi_app_event.md#paramlist) | 事件参数列表节点。  | 
| typedef struct [HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) [HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) | 用于接收app事件的监听器。  | 
| typedef struct [HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) [HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) | 用于处理app事件上报的处理者。  | 
| typedef struct [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) | 用于设置系统事件触发条件的配置对象。  | 
| typedef void(\* [OH_HiAppEvent_OnReceive](_hi_app_event.md#oh_hiappevent_onreceive)) (const char \*domain, const struct [HiAppEvent_AppEventGroup](_hi_app_event___app_event_group.md) \*appEventGroups, uint32_t groupLen) | 监听器接收到事件后，将触发该回调，将事件内容传递给调用方。  | 
| typedef void(\* [OH_HiAppEvent_OnTrigger](_hi_app_event.md#oh_hiappevent_ontrigger)) (int row, int size) | 监听器收到事件后，若监听器中未设置OH_HiAppEvent_OnReceive回调，将保存该事件。<br/>当保存的事件满足通过OH_HiAppEvent_SetTriggerCondition设定的条件后，将触发该回调。回调结束后，当新保存的事件消息再次满足设定的条件后，将再次进行回调。 | 
| typedef void(\* [OH_HiAppEvent_OnTake](_hi_app_event.md#oh_hiappevent_ontake)) (const char \*const \*events, uint32_t eventLen) | 使用OH_HiAppEvent_TakeWatcherData获取监听器接收到的事件时，监听器接收到的事件将通过该回调函数传递给调用者。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiAppEvent_ErrorCode](_hi_app_event.md#hiappevent_errorcode) {<br/>HIAPPEVENT_SUCCESS = 0, <br/>HIAPPEVENT_INVALID_PARAM_VALUE_LENGTH = 4, <br/>HIAPPEVENT_PROCESSOR_IS_NULL = -7, <br/>HIAPPEVENT_PROCESSOR_NOT_FOUND = -8,<br/>HIAPPEVENT_INVALID_PARAM_VALUE = -9, <br/>HIAPPEVENT_EVENT_CONFIG_IS_NULL = -10, <br/>HIAPPEVENT_OPERATE_FAILED = -100, <br/>HIAPPEVENT_INVALID_UID = -200<br/>} | 错误码定义。  | 
| [EventType](_hi_app_event.md#eventtype)  {<br/>FAULT = 1, <br/>STATISTIC = 2, <br/>SECURITY = 3, <br/>BEHAVIOR = 4<br/>} | 事件类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_CreateParamList](_hi_app_event.md#oh_hiappevent_createparamlist) (void) | 创建一个指向参数列表对象的指针。  | 
| void [OH_HiAppEvent_DestroyParamList](_hi_app_event.md#oh_hiappevent_destroyparamlist) ([ParamList](_hi_app_event.md#paramlist) list) | 销毁一个指向参数列表对象的指针，释放其分配内存。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddBoolParam](_hi_app_event.md#oh_hiappevent_addboolparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, bool boolean) | 添加一个布尔参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddBoolArrayParam](_hi_app_event.md#oh_hiappevent_addboolarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const bool \*booleans, int arrSize) | 添加一个布尔数组参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt8Param](_hi_app_event.md#oh_hiappevent_addint8param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int8_t num) | 添加一个int8_t参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt8ArrayParam](_hi_app_event.md#oh_hiappevent_addint8arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int8_t \*nums, int arrSize) | 添加一个int8_t数组参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt16Param](_hi_app_event.md#oh_hiappevent_addint16param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int16_t num) | 添加一个int16_t参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt16ArrayParam](_hi_app_event.md#oh_hiappevent_addint16arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int16_t \*nums, int arrSize) | 添加一个int16_t数组参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt32Param](_hi_app_event.md#oh_hiappevent_addint32param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int32_t num) | 添加一个int32_t参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt32ArrayParam](_hi_app_event.md#oh_hiappevent_addint32arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int32_t \*nums, int arrSize) | 添加一个int32_t数组参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt64Param](_hi_app_event.md#oh_hiappevent_addint64param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int64_t num) | 添加一个int64_t参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt64ArrayParam](_hi_app_event.md#oh_hiappevent_addint64arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int64_t \*nums, int arrSize) | 添加一个int64_t数组参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddFloatParam](_hi_app_event.md#oh_hiappevent_addfloatparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, float num) | 添加一个float参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddFloatArrayParam](_hi_app_event.md#oh_hiappevent_addfloatarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const float \*nums, int arrSize) | 添加一个float数组参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddDoubleParam](_hi_app_event.md#oh_hiappevent_adddoubleparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, double num) | 添加一个double参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddDoubleArrayParam](_hi_app_event.md#oh_hiappevent_adddoublearrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const double \*nums, int arrSize) | 添加一个double数组参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddStringParam](_hi_app_event.md#oh_hiappevent_addstringparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const char \*str) | 添加一个字符串参数到参数列表中。  | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddStringArrayParam](_hi_app_event.md#oh_hiappevent_addstringarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const char \*const \*strs, int arrSize) | 添加一个字符串数组参数到参数列表中。  | 
| int [OH_HiAppEvent_Write](_hi_app_event.md#oh_hiappevent_write) (const char \*domain, const char \*name, enum [EventType](_hi_app_event.md#eventtype) type, const [ParamList](_hi_app_event.md#paramlist) list) | 实现对参数为列表类型的应用事件打点。  | 
| bool [OH_HiAppEvent_Configure](_hi_app_event.md#oh_hiappevent_configure) (const char \*name, const char \*value) | 实现应用事件打点的配置功能。  | 
| [HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \* [OH_HiAppEvent_CreateWatcher](_hi_app_event.md#oh_hiappevent_createwatcher) (const char \*name) | 创建一个用于监听app事件的监听器。  | 
| void [OH_HiAppEvent_DestroyWatcher](_hi_app_event.md#oh_hiappevent_destroywatcher) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher) | 销毁已创建的监听器。  | 
| int [OH_HiAppEvent_SetTriggerCondition](_hi_app_event.md#oh_hiappevent_settriggercondition) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, int row, int size, int timeOut) | 用于设置监听器OH_HiAppEvent_OnTrigger回调的触发条件。<br/>分别可以从监视器新接收事件数量、新接收事件大小、onTrigger触发超时时间，设置触发条件。调用方应至少保证从一个方面设置触发条件。 | 
| int [OH_HiAppEvent_SetAppEventFilter](_hi_app_event.md#oh_hiappevent_setappeventfilter) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, const char \*domain, uint8_t eventTypes, const char \*const \*names, int namesLen) | 用于设置监听器需要监听的事件的类型。  | 
| int [OH_HiAppEvent_SetWatcherOnTrigger](_hi_app_event.md#oh_hiappevent_setwatcherontrigger) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnTrigger](_hi_app_event.md#oh_hiappevent_ontrigger) onTrigger) | 用于设置监听器onTrigger回调的接口。<br/>如果未设置OnReceive回调或已将其设置为nullptr，则将保存观察者接收到的应用事件。当保存的应用事件满足onTrigger回调的触发条件时，将调用onTrigger回调。 | 
| int [OH_HiAppEvent_SetWatcherOnReceive](_hi_app_event.md#oh_hiappevent_setwatcheronreceive) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, [OH_HiAppEvent_OnReceive](_hi_app_event.md#oh_hiappevent_onreceive) onReceive) | 用于设置监听器onReceive回调函数的接口。当监听器监听到相应事件后，onReceive回调函数将被调用。  | 
| int [OH_HiAppEvent_TakeWatcherData](_hi_app_event.md#oh_hiappevent_takewatcherdata) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher, uint32_t eventNum, [OH_HiAppEvent_OnTake](_hi_app_event.md#oh_hiappevent_ontake) onTake) | 用于获取监听器收到后保存的事件。  | 
| int [OH_HiAppEvent_AddWatcher](_hi_app_event.md#oh_hiappevent_addwatcher) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher) | 添加监听器的接口，监听器开始监听系统消息。  | 
| int [OH_HiAppEvent_RemoveWatcher](_hi_app_event.md#oh_hiappevent_removewatcher) ([HiAppEvent_Watcher](_hi_app_event.md#hiappevent_watcher) \*watcher) | 移除监听器的接口，监听器停止监听系统消息。  | 
| void [OH_HiAppEvent_ClearData](_hi_app_event.md#oh_hiappevent_cleardata) () | 清除所有监视器保存的所有事件。  | 
| [HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \* [OH_HiAppEvent_CreateProcessor](_hi_app_event.md#oh_hiappevent_createprocessor) (const char \*name) | 创建一个用于处理app事件上报的处理者。  | 
| int [OH_HiAppEvent_SetReportRoute](_hi_app_event.md#oh_hiappevent_setreportroute) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*appId, const char \*routeInfo) | 设置处理者事件上报路由的接口。  | 
| int [OH_HiAppEvent_SetReportPolicy](_hi_app_event.md#oh_hiappevent_setreportpolicy) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, int periodReport, int batchReport, bool onStartReport, bool onBackgroundReport) | 设置处理者事件上报策略的接口。  | 
| int [OH_HiAppEvent_SetReportEvent](_hi_app_event.md#oh_hiappevent_setreportevent) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*domain, const char \*name, bool isRealTime) | 设置处理者上报事件的接口。  | 
| int [OH_HiAppEvent_SetCustomConfig](_hi_app_event.md#oh_hiappevent_setcustomconfig) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*key, const char \*value) | 设置处理者自定义扩展参数的接口。  | 
| int [OH_HiAppEvent_SetConfigId](_hi_app_event.md#oh_hiappevent_setconfigid) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, int configId) | 设置处理者配置id的接口。  | 
| int [OH_HiAppEvent_SetReportUserId](_hi_app_event.md#oh_hiappevent_setreportuserid) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*const \*userIdNames, int size) | 设置处理者用户ID的接口。  | 
| int [OH_HiAppEvent_SetReportUserProperty](_hi_app_event.md#oh_hiappevent_setreportuserproperty) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor, const char \*const \*userPropertyNames, int size) | 设置处理者用户属性的接口。  | 
| int64_t [OH_HiAppEvent_AddProcessor](_hi_app_event.md#oh_hiappevent_addprocessor) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor) | 添加数据处理者的接口。开发者可添加数据处理者，用于提供事件上云功能。数据处理者的实现可预置在设备中，开发者可根据数据处理者的约束设置属性。  | 
| void [OH_HiAppEvent_DestroyProcessor](_hi_app_event.md#oh_hiappevent_destroyprocessor) ([HiAppEvent_Processor](_hi_app_event.md#hiappevent_processor) \*processor) | 销毁已创建的数据处理者。  | 
| int [OH_HiAppEvent_RemoveProcessor](_hi_app_event.md#oh_hiappevent_removeprocessor) (int64_t processorId) | 移除数据处理者的接口，处理者停止上报事件。  | 
| [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \* [OH_HiAppEvent_CreateConfig](_hi_app_event.md#oh_hiappevent_createconfig) (void) | 创建一个指向设置系统事件触发条件的配置对象的指针。  | 
| void [OH_HiAppEvent_DestroyConfig](_hi_app_event.md#oh_hiappevent_destroyconfig) ([HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \*config) | 销毁已创建的配置对象。  | 
| int [OH_HiAppEvent_SetConfigItem](_hi_app_event.md#oh_hiappevent_setconfigitem) ([HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \*config, const char \*itemName, const char \*itemValue) | 设置配置对象中的配置项。  | 
| int [OH_HiAppEvent_SetEventConfig](_hi_app_event.md#oh_hiappevent_seteventconfig) (const char \*name, [HiAppEvent_Config](_hi_app_event.md#hiappevent_config) \*config) | 设定系统事件订阅触发条件。  | 

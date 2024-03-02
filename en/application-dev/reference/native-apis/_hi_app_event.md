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


### Macros

| Name| Description| 
| -------- | -------- |
| [DISABLE](#disable)   "disable" | Whether to disable event logging.| 
| [MAX_STORAGE](#max_storage)   "max_storage" | Storage quota of the event file directory.| 
| [EVENT_USER_LOGIN](#event_user_login)   "hiappevent.user_login" | User login event.| 
| [EVENT_USER_LOGOUT](#event_user_logout)   "hiappevent.user_logout" | User logout event.| 
| [EVENT_DISTRIBUTED_SERVICE_START](#event_distributed_service_start)   "hiappevent.distributed_service_start" | Distributed service event.| 
| [PARAM_USER_ID](#param_user_id)   "user_id" | User ID.| 
| [PARAM_DISTRIBUTED_SERVICE_NAME](#param_distributed_service_name)   "ds_name" | Distributed service name.| 
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](#param_distributed_service_instance_id)   "ds_instance_id" | Distributed service instance ID.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct ParamListNode \* [ParamList](#paramlist) | Event parameter list node.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [EventType](#eventtype) { FAULT = 1, STATISTIC = 2, SECURITY = 3, BEHAVIOR = 4 } | Event type.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [ParamList](#paramlist) [OH_HiAppEvent_CreateParamList](#oh_hiappevent_createparamlist) (void) | Creates a pointer to a parameter list object.| 
| void [OH_HiAppEvent_DestroyParamList](#oh_hiappevent_destroyparamlist) ([ParamList](#paramlist) list) | Destroys a pointer to a parameter list object and releases its allocated memory.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolParam](#oh_hiappevent_addboolparam) ([ParamList](#paramlist) list, const char \*name, bool boolean) | Adds an event parameter of the Boolean type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolArrayParam](#oh_hiappevent_addboolarrayparam) ([ParamList](#paramlist) list, const char \*name, const bool \*booleans, int arrSize) | Adds an event parameter of the Boolean array type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8Param](#oh_hiappevent_addint8param) ([ParamList](#paramlist) list, const char \*name, int8_t num) | Adds an event parameter of the int8_t type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8ArrayParam](#oh_hiappevent_addint8arrayparam) ([ParamList](#paramlist) list, const char \*name, const int8_t \*nums, int arrSize) | Adds an event parameter of the int8_t array type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16Param](#oh_hiappevent_addint16param) ([ParamList](#paramlist) list, const char \*name, int16_t num) | Adds an event parameter of the int16_t type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16ArrayParam](#oh_hiappevent_addint16arrayparam) ([ParamList](#paramlist) list, const char \*name, const int16_t \*nums, int arrSize) | Adds an event parameter of the int16_t array type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32Param](#oh_hiappevent_addint32param) ([ParamList](#paramlist) list, const char \*name, int32_t num) | Adds an event parameter of the int32_t type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32ArrayParam](#oh_hiappevent_addint32arrayparam) ([ParamList](#paramlist) list, const char \*name, const int32_t \*nums, int arrSize) | Adds an event parameter of the int32_t array type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64Param](#oh_hiappevent_addint64param) ([ParamList](#paramlist) list, const char \*name, int64_t num) | Adds an event parameter of the int64_t type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64ArrayParam](#oh_hiappevent_addint64arrayparam) ([ParamList](#paramlist) list, const char \*name, const int64_t \*nums, int arrSize) | Adds an event parameter of the int64_t array type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatParam](#oh_hiappevent_addfloatparam) ([ParamList](#paramlist) list, const char \*name, float num) | Adds an event parameter of the float type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatArrayParam](#oh_hiappevent_addfloatarrayparam) ([ParamList](#paramlist) list, const char \*name, const float \*nums, int arrSize) | Adds an event parameter of the float array type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleParam](#oh_hiappevent_adddoubleparam) ([ParamList](#paramlist) list, const char \*name, double num) | Adds an event parameter of the Double type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleArrayParam](#oh_hiappevent_adddoublearrayparam) ([ParamList](#paramlist) list, const char \*name, const double \*nums, int arrSize) | Adds an event parameter of the double array type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringParam](#oh_hiappevent_addstringparam) ([ParamList](#paramlist) list, const char \*name, const char \*str) | Adds a parameter of the string type to the parameter list.| 
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringArrayParam](#oh_hiappevent_addstringarrayparam) ([ParamList](#paramlist) list, const char \*name, const char \*const \*strs, int arrSize) | Adds a parameter of the string array type to the parameter list.| 
| int [OH_HiAppEvent_Write](#oh_hiappevent_write) (const char \*domain, const char \*name, enum [EventType](#eventtype) type, const [ParamList](#paramlist) list) | Logs application events whose parameters are of the list type.| 
| bool [OH_HiAppEvent_Configure](#oh_hiappevent_configure) (const char \*name, const char \*value) | Configures the application event logging function.| 


## Macro Description


### DISABLE

```
#define DISABLE   "disable"
```

**Description**

Whether to disable event logging.

**Since**: 8


### EVENT_DISTRIBUTED_SERVICE_START

```
#define EVENT_DISTRIBUTED_SERVICE_START   "hiappevent.distributed_service_start"
```

**Description**

Distributed service event.

**Since**: 8


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

Storage quota of the event file directory.

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| booleans | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| boolean | Value of the parameter to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| nums | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| num | Value of the parameter to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| nums | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| num | Value of the parameter to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| nums | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| num | Value of the parameter to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| nums | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| num | Value of the parameter to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| nums | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| num | Value of the parameter to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| nums | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| num | Value of the parameter to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| strs | Value of the parameter to be added.| 
| arrSize | Size of the parameter array to be added.| 

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
| list | Pointer to the parameter list to which parameters need to be added.| 
| name | Name of the parameter to be added.| 
| str | Value of the parameter to be added.| 

**Returns**

Pointer to the parameter list that contains the parameters added.


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
| name | Configuration item name.| 
| value | Configuration item value.| 

**Returns**

Configuration result.


### OH_HiAppEvent_CreateParamList()

```
ParamList OH_HiAppEvent_CreateParamList (void )
```

**Description**

Creates a pointer to a parameter list object.

**Since**: 8

**Returns**

Pointer to the parameter list object.


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
| list | Pointer to the parameter list object.| 


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
| domain | Event domain. You can customize event domains as required.| 
| name | Event name. You can customize event names as required.| 
| type | Event type, which is defined in [EventType](#eventtype).| 
| list | List of event parameters. Each parameter consists of a parameter name and a parameter value.| 

**Returns**

The value **0** indicates that the event parameter verification is successful, and the event will be written to the event file asynchronously. A value greater than **0** indicates that invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored. A value smaller than **0** indicates that the event parameter verification fails, and the event will not be written to the event file.

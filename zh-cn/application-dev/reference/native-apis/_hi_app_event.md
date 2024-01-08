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
| [hiappevent.h](hiappevent_8h.md) | HiAppEvent模块的应用事件打点函数定义。<br/>**引用文件**：<br/>**库**： | 
| [hiappevent_cfg.h](hiappevent__cfg_8h.md) | 定义事件打点配置函数的所有配置项名称。<br/>**引用文件**：<br/>**库**： | 
| [hiappevent_event.h](hiappevent__event_8h.md) | 定义所有预定义事件的事件名称。<br/>**引用文件**：<br/>**库**： | 
| [hiappevent_param.h](hiappevent__param_8h.md) | 定义所有预定义事件的参数名称。<br/>**引用文件**：<br/>**库**： | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [DISABLE](#disable)   "disable" | 事件打点开关。 | 
| [MAX_STORAGE](#max_storage)   "max_storage" | 事件文件目录存储配额大小。 | 
| [EVENT_USER_LOGIN](#event_user_login)   "hiappevent.user_login" | 用户登录事件。 | 
| [EVENT_USER_LOGOUT](#event_user_logout)   "hiappevent.user_logout" | 用户登出事件。 | 
| [EVENT_DISTRIBUTED_SERVICE_START](#event_distributed_service_start)   "hiappevent.distributed_service_start" | 分布式服务事件。 | 
| [PARAM_USER_ID](#param_user_id)   "user_id" | 用户ID。 | 
| [PARAM_DISTRIBUTED_SERVICE_NAME](#param_distributed_service_name)   "ds_name" | 分布式服务名称。 | 
| [PARAM_DISTRIBUTED_SERVICE_INSTANCE_ID](#param_distributed_service_instance_id)   "ds_instance_id" | 分布式服务实例ID。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct ParamListNode \* [ParamList](#paramlist) | 事件参数列表节点。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EventType](#eventtype) { FAULT = 1, STATISTIC = 2, SECURITY = 3, BEHAVIOR = 4 } | 事件类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ParamList](#paramlist) [OH_HiAppEvent_CreateParamList](#oh_hiappevent_createparamlist) (void) | 创建一个指向参数列表对象的指针。 | 
| void [OH_HiAppEvent_DestroyParamList](#oh_hiappevent_destroyparamlist) ([ParamList](#paramlist) list) | 销毁一个指向参数列表对象的指针，释放其分配内存。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolParam](#oh_hiappevent_addboolparam) ([ParamList](#paramlist) list, const char \*name, bool boolean) | 添加一个布尔参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddBoolArrayParam](#oh_hiappevent_addboolarrayparam) ([ParamList](#paramlist) list, const char \*name, const bool \*booleans, int arrSize) | 添加一个布尔数组参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8Param](#oh_hiappevent_addint8param) ([ParamList](#paramlist) list, const char \*name, int8_t num) | 添加一个int8_t参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt8ArrayParam](#oh_hiappevent_addint8arrayparam) ([ParamList](#paramlist) list, const char \*name, const int8_t \*nums, int arrSize) | 添加一个int8_t数组参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16Param](#oh_hiappevent_addint16param) ([ParamList](#paramlist) list, const char \*name, int16_t num) | 添加一个int16_t参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt16ArrayParam](#oh_hiappevent_addint16arrayparam) ([ParamList](#paramlist) list, const char \*name, const int16_t \*nums, int arrSize) | 添加一个int16_t数组参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32Param](#oh_hiappevent_addint32param) ([ParamList](#paramlist) list, const char \*name, int32_t num) | 添加一个int32_t参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt32ArrayParam](#oh_hiappevent_addint32arrayparam) ([ParamList](#paramlist) list, const char \*name, const int32_t \*nums, int arrSize) | 添加一个int32_t数组参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64Param](#oh_hiappevent_addint64param) ([ParamList](#paramlist) list, const char \*name, int64_t num) | 添加一个int64_t参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddInt64ArrayParam](#oh_hiappevent_addint64arrayparam) ([ParamList](#paramlist) list, const char \*name, const int64_t \*nums, int arrSize) | 添加一个int64_t数组参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatParam](#oh_hiappevent_addfloatparam) ([ParamList](#paramlist) list, const char \*name, float num) | 添加一个float参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddFloatArrayParam](#oh_hiappevent_addfloatarrayparam) ([ParamList](#paramlist) list, const char \*name, const float \*nums, int arrSize) | 添加一个float数组参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleParam](#oh_hiappevent_adddoubleparam) ([ParamList](#paramlist) list, const char \*name, double num) | 添加一个double参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddDoubleArrayParam](#oh_hiappevent_adddoublearrayparam) ([ParamList](#paramlist) list, const char \*name, const double \*nums, int arrSize) | 添加一个double数组参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringParam](#oh_hiappevent_addstringparam) ([ParamList](#paramlist) list, const char \*name, const char \*str) | 添加一个字符串参数到参数列表中。 | 
| [ParamList](#paramlist) [OH_HiAppEvent_AddStringArrayParam](#oh_hiappevent_addstringarrayparam) ([ParamList](#paramlist) list, const char \*name, const char \*const \*strs, int arrSize) | 添加一个字符串数组参数到参数列表中。 | 
| int [OH_HiAppEvent_Write](#oh_hiappevent_write) (const char \*domain, const char \*name, enum [EventType](#eventtype) type, const [ParamList](#paramlist) list) | 实现对参数为列表类型的应用事件打点。 | 
| bool [OH_HiAppEvent_Configure](#oh_hiappevent_configure) (const char \*name, const char \*value) | 实现应用事件打点的配置功能。 | 


## 宏定义说明


### DISABLE

```
#define DISABLE   "disable"
```

**描述**

事件打点开关。

**起始版本：** 8


### EVENT_DISTRIBUTED_SERVICE_START

```
#define EVENT_DISTRIBUTED_SERVICE_START   "hiappevent.distributed_service_start"
```

**描述**

分布式服务事件。

**起始版本：** 8


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

事件文件目录存储配额大小。

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
| FAULT | 故障事件类型 | 
| STATISTIC | 统计事件类型 | 
| SECURITY | 安全事件类型 | 
| BEHAVIOR | 行为事件类型 | 


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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| booleans | 需要添加的布尔数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| boolean | 需要添加的布尔参数值。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| nums | 需要添加的double数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| num | 需要添加的double参数值。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| nums | 需要添加的float数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| num | 需要添加的float参数值。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| nums | 需要添加的int16_t数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| num | 需要添加的int16_t参数值。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| nums | 需要添加的int32_t数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| num | 需要添加的int32_t参数值。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| nums | 需要添加的int64_t数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| num | 需要添加的int64_t参数值。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| nums | 需要添加的int8_t数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| num | 需要添加的int8_t参数值。 | 

**返回：**

添加参数后的参数列表指针。


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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| strs | 需要添加的字符串数组参数值。 | 
| arrSize | 需要添加的参数数组大小。 | 

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
| list | 需要添加参数的参数列表指针。 | 
| name | 需要添加的参数名称。 | 
| str | 需要添加的字符串参数值。 | 

**返回：**

添加参数后的参数列表指针。


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
| name | 配置项名称。 | 
| value | 配置项值。 | 

**返回：**

配置结果。


### OH_HiAppEvent_CreateParamList()

```
ParamList OH_HiAppEvent_CreateParamList (void )
```

**描述**

创建一个指向参数列表对象的指针。

**起始版本：** 8

**返回：**

指向参数列表对象的指针。


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
| list | 参数列表对象指针。 | 


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
| domain | 事件领域。您可以根据需要自定义事件领域。 | 
| name | 事件名称。您可以根据需要自定义事件名称。 | 
| type | 事件类型，在[EventType](#eventtype)中定义。 | 
| list | 事件参数列表，每个参数由参数名和参数值组成。 | 

**返回：**

如果事件参数校验成功，则返回0，将事件写入事件文件；如果事件中存在无效参数，则返回正值，丢弃无效参数后将事件写入事件文件；如果事件参数校验失败，则返回负值，并且事件将不会写入事件文件。

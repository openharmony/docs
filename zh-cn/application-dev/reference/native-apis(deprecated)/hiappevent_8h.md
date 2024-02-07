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

**起始版本：** 8

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct ParamListNode \* [ParamList](_hi_app_event.md#paramlist) | 事件参数列表节点。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EventType](_hi_app_event.md#eventtype) { FAULT = 1, STATISTIC = 2, SECURITY = 3, BEHAVIOR = 4 } | 事件类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_CreateParamList](_hi_app_event.md#oh_hiappevent_createparamlist) (void) | 创建一个指向参数列表对象的指针。 | 
| void [OH_HiAppEvent_DestroyParamList](_hi_app_event.md#oh_hiappevent_destroyparamlist) ([ParamList](_hi_app_event.md#paramlist) list) | 销毁一个指向参数列表对象的指针，释放其分配内存。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddBoolParam](_hi_app_event.md#oh_hiappevent_addboolparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, bool boolean) | 添加一个布尔参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddBoolArrayParam](_hi_app_event.md#oh_hiappevent_addboolarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const bool \*booleans, int arrSize) | 添加一个布尔数组参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt8Param](_hi_app_event.md#oh_hiappevent_addint8param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int8_t num) | 添加一个int8_t参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt8ArrayParam](_hi_app_event.md#oh_hiappevent_addint8arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int8_t \*nums, int arrSize) | 添加一个int8_t数组参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt16Param](_hi_app_event.md#oh_hiappevent_addint16param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int16_t num) | 添加一个int16_t参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt16ArrayParam](_hi_app_event.md#oh_hiappevent_addint16arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int16_t \*nums, int arrSize) | 添加一个int16_t数组参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt32Param](_hi_app_event.md#oh_hiappevent_addint32param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int32_t num) | 添加一个int32_t参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt32ArrayParam](_hi_app_event.md#oh_hiappevent_addint32arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int32_t \*nums, int arrSize) | 添加一个int32_t数组参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt64Param](_hi_app_event.md#oh_hiappevent_addint64param) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, int64_t num) | 添加一个int64_t参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddInt64ArrayParam](_hi_app_event.md#oh_hiappevent_addint64arrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const int64_t \*nums, int arrSize) | 添加一个int64_t数组参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddFloatParam](_hi_app_event.md#oh_hiappevent_addfloatparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, float num) | 添加一个float参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddFloatArrayParam](_hi_app_event.md#oh_hiappevent_addfloatarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const float \*nums, int arrSize) | 添加一个float数组参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddDoubleParam](_hi_app_event.md#oh_hiappevent_adddoubleparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, double num) | 添加一个double参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddDoubleArrayParam](_hi_app_event.md#oh_hiappevent_adddoublearrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const double \*nums, int arrSize) | 添加一个double数组参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddStringParam](_hi_app_event.md#oh_hiappevent_addstringparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const char \*str) | 添加一个字符串参数到参数列表中。 | 
| [ParamList](_hi_app_event.md#paramlist) [OH_HiAppEvent_AddStringArrayParam](_hi_app_event.md#oh_hiappevent_addstringarrayparam) ([ParamList](_hi_app_event.md#paramlist) list, const char \*name, const char \*const \*strs, int arrSize) | 添加一个字符串数组参数到参数列表中。 | 
| int [OH_HiAppEvent_Write](_hi_app_event.md#oh_hiappevent_write) (const char \*domain, const char \*name, enum [EventType](_hi_app_event.md#eventtype) type, const [ParamList](_hi_app_event.md#paramlist) list) | 实现对参数为列表类型的应用事件打点。 | 
| bool [OH_HiAppEvent_Configure](_hi_app_event.md#oh_hiappevent_configure) (const char \*name, const char \*value) | 实现应用事件打点的配置功能。 | 

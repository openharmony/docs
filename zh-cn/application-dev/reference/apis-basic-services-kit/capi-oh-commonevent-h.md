# oh_commonevent.h
<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @HuYueRong-->
<!--Designer: @dongqingran-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

## 概述

本模块定义了发布、订阅/取消订阅公共事件、事件回调数据访问、有序事件控制等关键操作函数，以及错误码枚举与核心数据类型定义。

**API 组合使用关系说明：**

本模块存在三条明确的API调用流程：订阅流程、发布流程、有序事件处理流程。

**组合一：订阅并处理公共事件**

1. 通过`OH_CommonEvent_CreateSubscribeInfo`创建订阅者信息，声明需要订阅的事件名称，可选设置发布方权限与包名，用于过滤事件来源。
2. 通过`OH_CommonEvent_CreateSubscriber`创建订阅者并注册接收事件回调函数，再通过`OH_CommonEvent_Subscribe`发起事件订阅，订阅生效后即可在回调中等待事件投递。
3. 事件到达时，从回调参数`CommonEvent_RcvData`中获取事件名、code数据、data数据以及发布方包名等信息，然后进行业务逻辑处理。
4. 不再需要订阅时，调用`OH_CommonEvent_UnSubscribe`取消订阅，并释放相关资源。

**组合二：发布带附加信息的公共事件**

1. 通过`OH_CommonEvent_CreatePublishInfo`创建公共事件属性对象，并按需设置code数据、data数据、订阅者包名、订阅者权限与附加信息等属性。
2. 通过`OH_CommonEvent_PublishWithInfo`发布携带属性的事件。

> 若无需附加属性，可直接调用便捷接口`OH_CommonEvent_Publish(event)`发布事件。

**组合三：有序公共事件处理**

有序公共事件在订阅回调内通过订阅者句柄进行控制，订阅者句柄需在创建订阅者时保存，以便在回调中使用。

1. 发布公共事件时，通过`OH_CommonEvent_CreatePublishInfo(true)`创建有序事件属性，事件将按订阅者优先级依次投递。
2. 订阅者可在回调中通过`OH_CommonEvent_SetCodeToSubscriber`、`OH_CommonEvent_SetDataToSubscriber`设置传递给后续订阅者的code与data数据；通过`OH_CommonEvent_AbortCommonEvent`可标记事件为中止状态，终止其向后续订阅者投递。
3. 回调处理完成后，必须调用`OH_CommonEvent_FinishCommonEvent`结束处理，否则事件无法继续投递给后续订阅者。

需注意本模块遵循典型的"创建—使用—释放"生命周期：

- **订阅侧对象**：`CommonEvent_SubscribeInfo`→`CommonEvent_Subscriber`。创建后订阅生效，取消订阅后需依次销毁订阅者和订阅信息，避免内存泄漏。
- **发布侧对象**：`CommonEvent_PublishInfo`与`CommonEvent_Parameters`。发布完成后需分别销毁，二者相互独立。


**库：** libohcommonevent.so

**引用文件：** <BasicServicesKit/oh_commonevent.h>

**系统能力：** SystemCapability.Notification.CommonEvent

**起始版本：** 12

**相关模块：** [OH_CommonEvent](capi-oh-commonevent.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CommonEvent_SubscribeInfo](capi-oh-commonevent-commonevent-subscribeinfo.md) | CommonEvent_SubscribeInfo | 提供CommonEvent_SubscribeInfo订阅者信息结构体声明。 |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md) | CommonEvent_PublishInfo | 发布公共事件时使用的公共事件属性对象。 |
| [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md) | CommonEvent_RcvData | 提供CommonEvent_RcvData公共事件回调数据结构体声明。 |

### 变量

| 名称 | typedef关键字 | 描述 |
|----|------------|----|
| void  | CommonEvent_Subscriber    | 提供CommonEvent_Subscriber订阅者声明。   |
| void  | CommonEvent_Parameters    | 提供CommonEvent_Parameters公共事件附加信息声明。  |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | CommonEvent_ErrCode | 枚举错误码。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*CommonEvent_ReceiveCallback)(const CommonEvent_RcvData *data)](#commonevent_receivecallback) | CommonEvent_ReceiveCallback | 提供CommonEvent_ReceiveCallback回调函数声明。 |
| [CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum)](#oh_commonevent_createsubscribeinfo) | - | 创建订阅者信息。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetPublisherPermission(CommonEvent_SubscribeInfo* info, const char* permission)](#oh_commonevent_setpublisherpermission) | - | 设置发布方权限。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetPublisherBundleName(CommonEvent_SubscribeInfo* info, const char* bundleName)](#oh_commonevent_setpublisherbundlename) | - | 设置发布方包名称。 |
| [void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info)](#oh_commonevent_destroysubscribeinfo) | - | 释放订阅者信息。 |
| [CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info,CommonEvent_ReceiveCallback callback)](#oh_commonevent_createsubscriber) | - | 创建订阅者。 |
| [void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber)](#oh_commonevent_destroysubscriber) | - | 释放订阅者。 |
| [CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber)](#oh_commonevent_subscribe) | - | 订阅公共事件。 |
| [CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber)](#oh_commonevent_unsubscribe) | - | 退订公共事件。 |
| [const char* OH_CommonEvent_GetEventFromRcvData(const CommonEvent_RcvData* rcvData)](#oh_commonevent_geteventfromrcvdata) | - | 获取当前接收的公共事件名称。 |
| [int32_t OH_CommonEvent_GetCodeFromRcvData(const CommonEvent_RcvData* rcvData)](#oh_commonevent_getcodefromrcvdata) | - | 获取公共事件传递的Code数据，整数类型。 |
| [const char* OH_CommonEvent_GetDataStrFromRcvData(const CommonEvent_RcvData* rcvData)](#oh_commonevent_getdatastrfromrcvdata) | - | 获取公共事件传递的数据，字符串类型。 |
| [const char* OH_CommonEvent_GetBundleNameFromRcvData(const CommonEvent_RcvData* rcvData)](#oh_commonevent_getbundlenamefromrcvdata) | - | 获取接收到的公共事件的包名称信息。 |
| [const CommonEvent_Parameters* OH_CommonEvent_GetParametersFromRcvData(const CommonEvent_RcvData* rcvData)](#oh_commonevent_getparametersfromrcvdata) | - | 获取公共事件附加信息。 |
| [CommonEvent_PublishInfo* OH_CommonEvent_CreatePublishInfo(bool ordered)](#oh_commonevent_createpublishinfo) | - | 创建公共事件属性对象。 |
| [void OH_CommonEvent_DestroyPublishInfo(CommonEvent_PublishInfo* info)](#oh_commonevent_destroypublishinfo) | - | 销毁公共事件属性对象。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoBundleName(CommonEvent_PublishInfo* info, const char* bundleName)](#oh_commonevent_setpublishinfobundlename) | - | 设置公共事件订阅者包名称。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoPermissions(CommonEvent_PublishInfo* info,const char* permissions[], int32_t num)](#oh_commonevent_setpublishinfopermissions) | - | 设置公共事件订阅者权限。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoCode(CommonEvent_PublishInfo* info, int32_t code)](#oh_commonevent_setpublishinfocode) | - | 设置公共事件传递的数据，整数类型。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoData(CommonEvent_PublishInfo* info,const char* data, size_t length)](#oh_commonevent_setpublishinfodata) | - | 设置公共事件传递的数据，字符串类型。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoParameters(CommonEvent_PublishInfo* info,CommonEvent_Parameters* param)](#oh_commonevent_setpublishinfoparameters) | - | 设置公共事件附加信息。 |
| [CommonEvent_Parameters* OH_CommonEvent_CreateParameters()](#oh_commonevent_createparameters) | - | 创建公共事件附加信息对象。 |
| [void OH_CommonEvent_DestroyParameters(CommonEvent_Parameters* param)](#oh_commonevent_destroyparameters) | - | 销毁公共事件附加信息对象。 |
| [bool OH_CommonEvent_HasKeyInParameters(const CommonEvent_Parameters* para, const char* key)](#oh_commonevent_haskeyinparameters) | - | 检查附加信息中是否包含键值对信息。 |
| [int OH_CommonEvent_GetIntFromParameters(const CommonEvent_Parameters* para, const char* key, const int defaultValue)](#oh_commonevent_getintfromparameters) | - | 获取公共事件附加信息中键为key的int类型内容。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetIntToParameters(CommonEvent_Parameters* param, const char* key, int value)](#oh_commonevent_setinttoparameters) | - | 设置公共事件附加信息的int类型内容。 |
| [int32_t OH_CommonEvent_GetIntArrayFromParameters(const CommonEvent_Parameters* para, const char* key, int** array)](#oh_commonevent_getintarrayfromparameters) | - | 获取公共事件附加信息中键为key的int数组数据。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetIntArrayToParameters(CommonEvent_Parameters* param, const char* key,const int* value, size_t num)](#oh_commonevent_setintarraytoparameters) | - | 设置公共事件附加信息的int数组内容。 |
| [long OH_CommonEvent_GetLongFromParameters(const CommonEvent_Parameters* para, const char* key, const long defaultValue)](#oh_commonevent_getlongfromparameters) | - | 获取公共事件附加信息中键为key的long类型数据。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetLongToParameters(CommonEvent_Parameters* param, const char* key, long value)](#oh_commonevent_setlongtoparameters) | - | 设置公共事件附加信息的long类型内容。 |
| [int32_t OH_CommonEvent_GetLongArrayFromParameters(const CommonEvent_Parameters* para, const char* key, long** array)](#oh_commonevent_getlongarrayfromparameters) | - | 获取公共事件附加信息的long数组内容。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetLongArrayToParameters(CommonEvent_Parameters* param, const char* key,const long* value, size_t num)](#oh_commonevent_setlongarraytoparameters) | - | 设置公共事件附加信息的long数组内容。 |
| [bool OH_CommonEvent_GetBoolFromParameters(const CommonEvent_Parameters* para, const char* key, const bool defaultValue)](#oh_commonevent_getboolfromparameters) | - | 获取公共事件附加信息中键为key的布尔类型数据。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetBoolToParameters(CommonEvent_Parameters* param, const char* key, bool value)](#oh_commonevent_setbooltoparameters) | - | 设置公共事件附加信息的布尔类型内容。 |
| [int32_t OH_CommonEvent_GetBoolArrayFromParameters(const CommonEvent_Parameters* para, const char* key, bool** array)](#oh_commonevent_getboolarrayfromparameters) | - | 获取公共事件附加信息的布尔数组内容。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetBoolArrayToParameters(CommonEvent_Parameters* param, const char* key,const bool* value, size_t num)](#oh_commonevent_setboolarraytoparameters) | - | 设置公共事件附加信息的布尔数组内容。 |
| [char OH_CommonEvent_GetCharFromParameters(const CommonEvent_Parameters* para, const char* key, const char defaultValue)](#oh_commonevent_getcharfromparameters) | - | 获取公共事件附加信息中键为key的字符类型数据。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetCharToParameters(CommonEvent_Parameters* param, const char* key, char value)](#oh_commonevent_setchartoparameters) | - | 设置公共事件附加信息的字符类型内容。 |
| [int32_t OH_CommonEvent_GetCharArrayFromParameters(const CommonEvent_Parameters* para, const char* key, char** array)](#oh_commonevent_getchararrayfromparameters) | - | 获取公共事件附加信息的字符数组内容。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetCharArrayToParameters(CommonEvent_Parameters* param, const char* key,const char* value, size_t num)](#oh_commonevent_setchararraytoparameters) | - | 设置公共事件附加信息的字符数组内容。 |
| [double OH_CommonEvent_GetDoubleFromParameters(const CommonEvent_Parameters* para, const char* key,const double defaultValue)](#oh_commonevent_getdoublefromparameters) | - | 获取公共事件附加信息的double类型内容。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetDoubleToParameters(CommonEvent_Parameters* param, const char* key,double value)](#oh_commonevent_setdoubletoparameters) | - | 设置公共事件附加信息的double类型内容。 |
| [int32_t OH_CommonEvent_GetDoubleArrayFromParameters(const CommonEvent_Parameters* para, const char* key,double** array)](#oh_commonevent_getdoublearrayfromparameters) | - | 获取公共事件附加信息中键为key的double数组数据。 |
| [CommonEvent_ErrCode OH_CommonEvent_SetDoubleArrayToParameters(CommonEvent_Parameters* param, const char* key,const double* value, size_t num)](#oh_commonevent_setdoublearraytoparameters) | - | 设置公共事件附加信息的double数组内容。 |
| [CommonEvent_ErrCode OH_CommonEvent_Publish(const char* event)](#oh_commonevent_publish) | - | 发布公共事件。 |
| [CommonEvent_ErrCode OH_CommonEvent_PublishWithInfo(const char* event, const CommonEvent_PublishInfo* info)](#oh_commonevent_publishwithinfo) | - | 发布带有指定属性的公共事件。 |
| [bool OH_CommonEvent_IsOrderedCommonEvent(const CommonEvent_Subscriber* subscriber)](#oh_commonevent_isorderedcommonevent) | - | 查询当前公共事件是否为有序公共事件。 |
| [bool OH_CommonEvent_FinishCommonEvent(CommonEvent_Subscriber* subscriber)](#oh_commonevent_finishcommonevent) | - | 用于订阅者结束对当前有序公共事件的处理。 |
| [bool OH_CommonEvent_GetAbortCommonEvent(const CommonEvent_Subscriber* subscriber)](#oh_commonevent_getabortcommonevent) | - | 获取当前有序公共事件是否处于中止状态。 |
| [bool OH_CommonEvent_AbortCommonEvent(CommonEvent_Subscriber* subscriber)](#oh_commonevent_abortcommonevent) | - | 该接口与[OH_CommonEvent_FinishCommonEvent](#oh_commonevent_finishcommonevent)配合使用，可以中止当前的有序公共事件，使该公共事件不再向下一个订阅者传递。 |
| [bool OH_CommonEvent_ClearAbortCommonEvent(CommonEvent_Subscriber* subscriber)](#oh_commonevent_clearabortcommonevent) | - | 该接口与[OH_CommonEvent_FinishCommonEvent](#oh_commonevent_finishcommonevent)配合使用，可以取消当前有序公共事件的中止状态，使该公共事件继续向下一个订阅者传递。 |
| [int32_t OH_CommonEvent_GetCodeFromSubscriber(const CommonEvent_Subscriber* subscriber)](#oh_commonevent_getcodefromsubscriber) | - | 获取有序公共事件传递的数据，整数类型。 |
| [bool OH_CommonEvent_SetCodeToSubscriber(CommonEvent_Subscriber* subscriber, int32_t code)](#oh_commonevent_setcodetosubscriber) | - | 设置有序公共事件传递的数据，整数类型。 |
| [const char* OH_CommonEvent_GetDataFromSubscriber(const CommonEvent_Subscriber* subscriber)](#oh_commonevent_getdatafromsubscriber) | - | 获取有序公共事件传递的数据，字符串类型。 |
| [bool OH_CommonEvent_SetDataToSubscriber(CommonEvent_Subscriber* subscriber, const char* data, size_t length)](#oh_commonevent_setdatatosubscriber) | - | 设置有序公共事件传递的数据，字符串类型。 |

## 枚举类型说明

### CommonEvent_ErrCode

```c
enum CommonEvent_ErrCode
```

**描述**

枚举错误码。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| COMMONEVENT_ERR_OK = 0 | 成功。 |
| COMMONEVENT_ERR_INVALID_PARAMETER = 401 | 参数错误。参数不合法，请检查参数类型、取值范围或参数是否为空。 |
| COMMONEVENT_ERR_SENDING_LIMIT_EXCEEDED = 1500003| 事件发送频率过高。请检查应用是否过于频繁地发送公共事件，如发送频率超过每5毫秒20个，请降低公共事件发送频率或增加发送间隔后重新尝试。<br>**起始版本：** 20 |
| COMMONEVENT_ERR_NOT_SYSTEM_SERVICE = 1500004 | 三方应用无法发送系统公共事件。请检查当前应用是否为系统应用，或当前服务是否为系统服务。 |
| COMMONEVENT_ERR_SENDING_REQUEST_FAILED = 1500007 | IPC发送失败。请勿频繁建立连接，稍后重新尝试。|
| COMMONEVENT_ERR_INIT_UNDONE = 1500008 | 服务未初始化。请稍后重新尝试。 |
| COMMONEVENT_ERR_OBTAIN_SYSTEM_PARAMS = 1500009 | 系统错误。请稍后重新尝试。 |
| COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED = 1500010 | 进程内订阅者数量超过系统限制（200个）。请检查应用内是否存在订阅者未取消订阅，如存在则取消订阅后重新尝试；不存在请稍后重新尝试。 |
| COMMONEVENT_ERR_ALLOC_MEMORY_FAILED = 1500011 | 内存分配失败。请稍后重新尝试。 |


## 函数说明

### CommonEvent_ReceiveCallback()

```c
typedef void (*CommonEvent_ReceiveCallback)(const CommonEvent_RcvData *data)
```

**描述**

提供CommonEvent_ReceiveCallback回调函数声明。

**起始版本：** 12


**参数：**

| 参数项                                 | 描述 |
|-------------------------------------| -- |
| const [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md) *data | 公共事件回调数据。 |

### OH_CommonEvent_CreateSubscribeInfo()

```c
CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum)
```

**描述**

创建订阅者信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* events[] | 订阅的公共事件，实际订阅的数量为`eventsNum`与`events`数组长度的最小值。 |
| int32_t eventsNum | 订阅的公共事件数量，非负整数，取值为`events`数组长度。 |

**返回：**

| 类型                             | 说明 |
|--------------------------------| -- |
| [CommonEvent_SubscribeInfo](capi-oh-commonevent-commonevent-subscribeinfo.md)* | 成功则返回订阅者信息，失败则返回NULL。该指针由内部管理，在[OH_CommonEvent_DestroySubscribeInfo()](#oh_commonevent_destroysubscribeinfo)时释放。 |

### OH_CommonEvent_SetPublisherPermission()

```c
CommonEvent_ErrCode OH_CommonEvent_SetPublisherPermission(CommonEvent_SubscribeInfo* info, const char* permission)
```

**描述**

设置发布方权限。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_SubscribeInfo](capi-oh-commonevent-commonevent-subscribeinfo.md)* info | 待设置发布方权限的订阅者信息对象。 |
| const char* permission | 权限名称。取值为系统已定义的权限名，订阅方将只能接收到具有该权限的发送方发布的事件。不设置时，可接收所有发送方发布的事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_SetPublisherBundleName()

```c
CommonEvent_ErrCode OH_CommonEvent_SetPublisherBundleName(CommonEvent_SubscribeInfo* info, const char* bundleName)
```

**描述**

设置发布方包名称。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_SubscribeInfo](capi-oh-commonevent-commonevent-subscribeinfo.md)* info | 待设置发布方权限的订阅者信息对象。 |
| const char* bundleName | 包名称。用于限制订阅方只接收该bundleName的发布者发布的公共事件。不设置时，可接收所有应用发布的公共事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_DestroySubscribeInfo()

```c
void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info)
```

**描述**

释放订阅者信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_SubscribeInfo](capi-oh-commonevent-commonevent-subscribeinfo.md)* info | 订阅者信息。 |

### OH_CommonEvent_CreateSubscriber()

```c
CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info,CommonEvent_ReceiveCallback callback)
```

**描述**

创建订阅者。

**起始版本：** 12


**参数：**

| 参数项                                                                  | 描述 |
|----------------------------------------------------------------------| -- |
| const [CommonEvent_SubscribeInfo](capi-oh-commonevent-commonevent-subscribeinfo.md)* info                            | 订阅者信息。 |
| [CommonEvent_ReceiveCallback](#commonevent_receivecallback) callback | 公共事件回调函数。当公共事件订阅成功后，事件触发时通过data返回公共事件数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_Subscriber](#变量)* | 成功则返回订阅者，失败则返回NULL。该指针由内部管理，在[OH_CommonEvent_DestroySubscriber()](#oh_commonevent_destroysubscriber)时释放。 |

### OH_CommonEvent_DestroySubscriber()

```c
void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber)
```

**描述**

释放订阅者。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Subscriber](#变量)* subscriber | 订阅者。 |

### OH_CommonEvent_Subscribe()

```c
CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber)
```

**描述**

订阅公共事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Subscriber](#变量)* subscriber | 订阅者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数subscriber无效。<br>         返回[COMMONEVENT_ERR_SENDING_REQUEST_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示IPC请求发送失败。<br>         返回[COMMONEVENT_ERR_INIT_UNDONE](capi-oh-commonevent-h.md#commonevent_errcode)表示公共事件服务未初始化。<br>         返回[COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED](capi-oh-commonevent-h.md#commonevent_errcode)表示进程内订阅者数量超过系统限制（200个）。<br>         返回[COMMONEVENT_ERR_ALLOC_MEMORY_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示系统分配内存失败。 |

### OH_CommonEvent_UnSubscribe()

```c
CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber)
```

**描述**

退订公共事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Subscriber](#变量)* subscriber | 订阅者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数subscriber无效。<br>         返回[COMMONEVENT_ERR_SENDING_REQUEST_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示IPC请求发送失败。<br>         返回[COMMONEVENT_ERR_INIT_UNDONE](capi-oh-commonevent-h.md#commonevent_errcode)表示公共事件服务未初始化。 |

### OH_CommonEvent_GetEventFromRcvData()

```c
const char* OH_CommonEvent_GetEventFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取接收到的公共事件名称。

**起始版本：** 12


**参数：**

| 参数项                                    | 描述 |
|----------------------------------------| -- |
| const [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md)* rcvData | 公共事件回调数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 返回公共事件名称。该指针由系统产生，回调函数[CommonEvent_ReceiveCallback](#commonevent_receivecallback)结束后即刻释放，不可在回调函数外部使用。 |

### OH_CommonEvent_GetCodeFromRcvData()

```c
int32_t OH_CommonEvent_GetCodeFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取接收到的公共事件Code数据，整数类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md)* rcvData | 公共事件回调数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回接收到的公共事件Code数据，整数类型。 |

### OH_CommonEvent_GetDataStrFromRcvData()

```c
const char* OH_CommonEvent_GetDataStrFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取接收到的公共事件数据，字符串类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md)* rcvData | 公共事件回调数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 返回接收到的公共事件数据，字符串类型。该指针由系统产生，回调函数[CommonEvent_ReceiveCallback](#commonevent_receivecallback)结束后即刻释放，不可在回调函数外部使用。 |

### OH_CommonEvent_GetBundleNameFromRcvData()

```c
const char* OH_CommonEvent_GetBundleNameFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取接收到的公共事件的包名称信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md)* rcvData | 公共事件回调数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 返回公共事件的包名称。该指针由系统产生，回调函数[CommonEvent_ReceiveCallback](#commonevent_receivecallback)结束后即刻释放，不可在回调函数外部使用。 |

### OH_CommonEvent_GetParametersFromRcvData()

```c
const CommonEvent_Parameters* OH_CommonEvent_GetParametersFromRcvData(const CommonEvent_RcvData* rcvData)
```

**描述**

获取公共事件附加信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_RcvData](capi-oh-commonevent-commonevent-rcvdata.md)* rcvData | 公共事件回调数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* | 返回公共事件附加信息。 |

### OH_CommonEvent_CreatePublishInfo()

```c
CommonEvent_PublishInfo* OH_CommonEvent_CreatePublishInfo(bool ordered)
```

**描述**

创建公共事件属性对象。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool ordered | 是否为有序公共事件。<br> - true：有序公共事件。<br> - false：无序公共事件。 |

**返回：**

| 类型                           | 说明 |
|------------------------------| -- |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* | 创建的公共事件属性对象，创建失败时，返回NULL。该指针由内部管理，在[OH_CommonEvent_DestroyPublishInfo()](#oh_commonevent_destroypublishinfo)时释放。 |

### OH_CommonEvent_DestroyPublishInfo()

```c
void OH_CommonEvent_DestroyPublishInfo(CommonEvent_PublishInfo* info)
```

**描述**

销毁公共事件属性对象。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* info | 要销毁的公共事件属性对象。 |

### OH_CommonEvent_SetPublishInfoBundleName()

```c
CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoBundleName(CommonEvent_PublishInfo* info, const char* bundleName)
```

**描述**

设置公共事件订阅者包名称。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* info | 公共事件属性对象。 |
| const char* bundleName | 设置的订阅者包名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_SetPublishInfoPermissions()

```c
CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoPermissions(CommonEvent_PublishInfo* info,const char* permissions[], int32_t num)
```

**描述**

设置公共事件订阅者权限。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* info | 公共事件属性对象。 |
| const char* permissions[] | 订阅者权限名称数组，只有具备这些权限的订阅者才能收到该公共事件。生效数量为`num`与`permissions`数组长度的最小值。 |
| int32_t num | 权限名称的数量，取值为`permissions`数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_SetPublishInfoCode()

```c
CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoCode(CommonEvent_PublishInfo* info, int32_t code)
```

**描述**

设置公共事件传递的数据，整数类型。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* info | 公共事件属性对象。 |
| int32_t code | 公共事件传递的数据，整数类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_SetPublishInfoData()

```c
CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoData(CommonEvent_PublishInfo* info, const char* data, size_t length)
```

**描述**

设置公共事件传递的数据，字符串类型。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* info | 公共事件属性对象。 |
| const char* data | 公共事件传递的数据，字符串类型，实际有效数据长度为`length`与`data`字符串长度的最小值。 |
| size_t length | 结果数据的长度，取值为`data`数据字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_SetPublishInfoParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetPublishInfoParameters(CommonEvent_PublishInfo* info,CommonEvent_Parameters* param)
```

**描述**

设置公共事件附加信息。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* info | 公共事件属性对象。 |
| [CommonEvent_Parameters](#变量)* param  | 设置的附加信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_CreateParameters()

```c
CommonEvent_Parameters* OH_CommonEvent_CreateParameters()
```

**描述**

创建公共事件附加信息对象。

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* | 返回公共事件附加信息，创建失败时，返回NULL。该指针由内部管理，在[OH_CommonEvent_DestroyParameters()](#oh_commonevent_destroyparameters)时释放。 |

### OH_CommonEvent_DestroyParameters()

```c
void OH_CommonEvent_DestroyParameters(CommonEvent_Parameters* param)
```

**描述**

销毁公共事件附加信息对象。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |

### OH_CommonEvent_HasKeyInParameters()

```c
bool OH_CommonEvent_HasKeyInParameters(const CommonEvent_Parameters* para, const char* key)
```

**描述**

检查附加信息中是否包含键值对信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回数据键是否存在。<br> - true：存在。<br> - false：不存在。 |

### OH_CommonEvent_GetIntFromParameters()

```c
int OH_CommonEvent_GetIntFromParameters(const CommonEvent_Parameters* para, const char* key, const int defaultValue)
```

**描述**

获取公共事件附加信息中键为key的int类型内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const int defaultValue | 默认值，当指定key不存在时返回此默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回查询的int类型数据。 |

### OH_CommonEvent_SetIntToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetIntToParameters(CommonEvent_Parameters* param, const char* key, int value)
```

**描述**

设置公共事件附加信息的int类型内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| int value | 设置的int类型内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_GetIntArrayFromParameters()

```c
int32_t OH_CommonEvent_GetIntArrayFromParameters(const CommonEvent_Parameters* para, const char* key, int** array)
```

**描述**

获取公共事件附加信息中键为key的int数组数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| int** array | 输出参数，用于接收查询到的int数组数据。该数组内存由函数内部分配，调用者无需预先分配。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回查询的数组长度，默认值为0。 |

### OH_CommonEvent_SetIntArrayToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetIntArrayToParameters(CommonEvent_Parameters* param, const char* key,const int* value, size_t num)
```

**描述**

设置公共事件附加信息的int数组内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const int* value | 设置的int数组内容。实际设置的数量为`num`，value数组长度需大于`num`，否则会有越界访问风险。 |
| size_t num | 设置的int数组内容中元素的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。<br>         返回[COMMONEVENT_ERR_ALLOC_MEMORY_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示内存分配失败。 |

### OH_CommonEvent_GetLongFromParameters()

```c
long OH_CommonEvent_GetLongFromParameters(const CommonEvent_Parameters* para, const char* key, const long defaultValue)
```

**描述**

获取公共事件附加信息中键为key的long类型数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const long defaultValue | 默认值，当指定key不存在时返回此默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| long | 返回查询的long类型数据。 |

### OH_CommonEvent_SetLongToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetLongToParameters(CommonEvent_Parameters* param, const char* key, long value)
```

**描述**

设置公共事件附加信息的long类型内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| long value | 设置的long类型内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_GetLongArrayFromParameters()

```c
int32_t OH_CommonEvent_GetLongArrayFromParameters(const CommonEvent_Parameters* para, const char* key, long** array)
```

**描述**

获取公共事件附加信息的long数组内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| long** array | 输出参数，用于接收查询到的long数组数据。该数组内存由函数内部分配，调用者无需预先分配。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回查询的数组长度，默认值为0。 |

### OH_CommonEvent_SetLongArrayToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetLongArrayToParameters(CommonEvent_Parameters* param, const char* key,const long* value, size_t num)
```

**描述**

设置公共事件附加信息的long数组内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const long* value | 设置的long数组内容。实际设置的数量为`num`，value数组长度需大于`num`，否则会有越界访问风险。 |
| size_t num | 设置的long数组内容中元素的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。<br>         返回[COMMONEVENT_ERR_ALLOC_MEMORY_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示内存分配失败。 |

### OH_CommonEvent_GetBoolFromParameters()

```c
bool OH_CommonEvent_GetBoolFromParameters(const CommonEvent_Parameters* para, const char* key, const bool defaultValue)
```

**描述**

获取公共事件附加信息中键为key的布尔类型数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const bool defaultValue | 默认值，当指定key不存在时返回此默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回查询的bool类型数据。 |

### OH_CommonEvent_SetBoolToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetBoolToParameters(CommonEvent_Parameters* param, const char* key, bool value)
```

**描述**

设置公共事件附加信息的布尔类型内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| bool value | 设置的布尔类型内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_GetBoolArrayFromParameters()

```c
int32_t OH_CommonEvent_GetBoolArrayFromParameters(const CommonEvent_Parameters* para, const char* key, bool** array)
```

**描述**

获取公共事件附加信息的布尔数组内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| bool** array | 输出参数，用于接收查询到的bool数组数据。该数组内存由函数内部分配，调用者无需预先分配。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回查询的数组长度，默认值为0。 |

### OH_CommonEvent_SetBoolArrayToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetBoolArrayToParameters(CommonEvent_Parameters* param, const char* key,const bool* value, size_t num)
```

**描述**

设置公共事件附加信息的布尔数组内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const bool* value | 设置的布尔数组内容。实际设置的数量为`num`，value数组长度需大于`num`，否则会有越界访问风险。 |
| size_t num | 设置的布尔数组内容中元素的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。<br>         返回[COMMONEVENT_ERR_ALLOC_MEMORY_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示内存分配失败。 |

### OH_CommonEvent_GetCharFromParameters()

```c
char OH_CommonEvent_GetCharFromParameters(const CommonEvent_Parameters* para, const char* key, const char defaultValue)
```

**描述**

获取公共事件附加信息中键为key的字符类型数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const char defaultValue | 默认值，当指定key不存在时返回此默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char | 返回查询的char类型数据。 |

### OH_CommonEvent_SetCharToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetCharToParameters(CommonEvent_Parameters* param, const char* key, char value)
```

**描述**

设置公共事件附加信息的字符类型内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| char value | 设置的字符类型内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_GetCharArrayFromParameters()

```c
int32_t OH_CommonEvent_GetCharArrayFromParameters(const CommonEvent_Parameters* para, const char* key, char** array)
```

**描述**

获取公共事件附加信息的字符数组内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| char** array | 输出参数，用于接收查询到的char数组数据。该数组内存由函数内部分配，调用者无需预先分配。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回查询的数组长度，默认值为0。 |

### OH_CommonEvent_SetCharArrayToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetCharArrayToParameters(CommonEvent_Parameters* param, const char* key,const char* value, size_t num)
```

**描述**

设置公共事件附加信息的字符数组内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const char* value | 设置的字符数组内容。实际设置的数量为`num`与`value`数组长度的最小值。 |
| size_t num | 设置的字符数组内容中元素的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_GetDoubleFromParameters()

```c
double OH_CommonEvent_GetDoubleFromParameters(const CommonEvent_Parameters* para, const char* key, const double defaultValue)
```

**描述**

获取公共事件附加信息的double类型内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const double defaultValue | 默认值，当指定key不存在时返回此默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| double | 返回查询的double类型数据。 |

### OH_CommonEvent_SetDoubleToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetDoubleToParameters(CommonEvent_Parameters* param, const char* key,double value)
```

**描述**

设置公共事件附加信息的double类型内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| double value | 设置的double类型内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。 |

### OH_CommonEvent_GetDoubleArrayFromParameters()

```c
int32_t OH_CommonEvent_GetDoubleArrayFromParameters(const CommonEvent_Parameters* para, const char* key,double** array)
```

**描述**

获取公共事件附加信息中键为key的double数组数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Parameters](#变量)* para | 公共事件附加信息。 |
| const char* key | 数据键。 |
| double** array | 输出参数，用于接收查询到的double数组数据。该数组内存由函数内部分配，调用者无需预先分配。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回查询的数组长度，默认值为0。 |

### OH_CommonEvent_SetDoubleArrayToParameters()

```c
CommonEvent_ErrCode OH_CommonEvent_SetDoubleArrayToParameters(CommonEvent_Parameters* param, const char* key,const double* value, size_t num)
```

**描述**

设置公共事件附加信息的double数组内容。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Parameters](#变量)* param | 公共事件附加信息。 |
| const char* key | 数据键。 |
| const double* value | 设置的double数组内容。实际设置的数量为`num`，value数组长度需大于`num`，否则会有越界访问风险。 |
| size_t num | 设置的double数组内容中元素的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。<br>         返回[COMMONEVENT_ERR_ALLOC_MEMORY_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示内存分配失败。 |

### OH_CommonEvent_Publish()

```c
CommonEvent_ErrCode OH_CommonEvent_Publish(const char* event)
```

**描述**

发布公共事件。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* event | 公共事件名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。<br>         返回[COMMONEVENT_ERR_SENDING_LIMIT_EXCEEDED](capi-oh-commonevent-h.md#commonevent_errcode)表示事件发送频率过高。<br>   返回[COMMONEVENT_ERR_SENDING_REQUEST_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示IPC请求发送失败。<br>         返回[COMMONEVENT_ERR_INIT_UNDONE](capi-oh-commonevent-h.md#commonevent_errcode)表示公共事件服务未初始化。 |

### OH_CommonEvent_PublishWithInfo()

```c
CommonEvent_ErrCode OH_CommonEvent_PublishWithInfo(const char* event, const CommonEvent_PublishInfo* info)
```

**描述**

发布带有指定属性的公共事件。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* event | 公共事件名称。 |
| const [CommonEvent_PublishInfo](capi-oh-commonevent-commonevent-publishinfo.md)* info | 设置的公共事件属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [CommonEvent_ErrCode](#commonevent_errcode) | 返回错误码。<br>         返回[COMMONEVENT_ERR_OK](capi-oh-commonevent-h.md#commonevent_errcode)表示成功。<br>         返回[COMMONEVENT_ERR_INVALID_PARAMETER](capi-oh-commonevent-h.md#commonevent_errcode)表示参数错误。<br>        返回[COMMONEVENT_ERR_SENDING_LIMIT_EXCEEDED](capi-oh-commonevent-h.md#commonevent_errcode)表示事件发送频率过高。<br>   返回[COMMONEVENT_ERR_SENDING_REQUEST_FAILED](capi-oh-commonevent-h.md#commonevent_errcode)表示IPC请求发送失败。<br>         返回[COMMONEVENT_ERR_INIT_UNDONE](capi-oh-commonevent-h.md#commonevent_errcode)表示公共事件服务未初始化。 |

### OH_CommonEvent_IsOrderedCommonEvent()

```c
bool OH_CommonEvent_IsOrderedCommonEvent(const CommonEvent_Subscriber* subscriber)
```

**描述**

查询当前公共事件是否为有序公共事件。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示有序公共事件；返回false表示无序公共事件。 |

### OH_CommonEvent_FinishCommonEvent()

```c
bool OH_CommonEvent_FinishCommonEvent(CommonEvent_Subscriber* subscriber)
```

**描述**

用于订阅者结束对当前有序公共事件的处理。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示操作成功；返回false表示操作失败。 |

### OH_CommonEvent_GetAbortCommonEvent()

```c
bool OH_CommonEvent_GetAbortCommonEvent(const CommonEvent_Subscriber* subscriber)
```

**描述**

获取当前有序公共事件是否处于中止状态。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示当前有序公共事件处于中止状态；返回false表示当前有序公共事件没有处于中止状态。 |

### OH_CommonEvent_AbortCommonEvent()

```c
bool OH_CommonEvent_AbortCommonEvent(CommonEvent_Subscriber* subscriber)
```

**描述**

该接口与[OH_CommonEvent_FinishCommonEvent](#oh_commonevent_finishcommonevent)配合使用，可以中止当前的有序公共事件，使该公共事件不再向下一个订阅者传递。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示操作成功；返回false表示操作失败。 |

### OH_CommonEvent_ClearAbortCommonEvent()

```c
bool OH_CommonEvent_ClearAbortCommonEvent(CommonEvent_Subscriber* subscriber)
```

**描述**

该接口与[OH_CommonEvent_FinishCommonEvent](#oh_commonevent_finishcommonevent)配合使用，可以取消当前有序公共事件的中止状态，使该公共事件继续向下一个订阅者传递。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示操作成功；返回false表示操作失败。 |

### OH_CommonEvent_GetCodeFromSubscriber()

```c
int32_t OH_CommonEvent_GetCodeFromSubscriber(const CommonEvent_Subscriber* subscriber)
```

**描述**

获取有序公共事件传递的数据，整数类型。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回有序公共事件传递的数据，整数类型，无法获取时返回0。 |

### OH_CommonEvent_SetCodeToSubscriber()

```c
bool OH_CommonEvent_SetCodeToSubscriber(CommonEvent_Subscriber* subscriber, int32_t code)
```

**描述**

设置有序公共事件传递的数据，整数类型。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |
| int32_t code | 有序公共事件传递的数据，整数类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示操作成功；返回false表示操作失败。 |

### OH_CommonEvent_GetDataFromSubscriber()

```c
const char* OH_CommonEvent_GetDataFromSubscriber(const CommonEvent_Subscriber* subscriber)
```

**描述**

获取有序公共事件传递的数据，字符串类型。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| const char* | 返回有序公共事件传递的数据，字符串类型，无法获取时返回NULL。 |

### OH_CommonEvent_SetDataToSubscriber()

```c
bool OH_CommonEvent_SetDataToSubscriber(CommonEvent_Subscriber* subscriber, const char* data, size_t length)
```

**描述**

设置有序公共事件传递的数据，字符串类型。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [CommonEvent_Subscriber](#变量)* subscriber | 公共事件的订阅者对象。 |
| const char* data | 有序公共事件传递的数据，字符串类型，实际有效数据长度为`length`与`data`字符串长度的最小值。 |
| size_t length | 传递的数据字节长度，取值为`data`字符串长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回true表示操作成功；返回false表示操作失败。 |



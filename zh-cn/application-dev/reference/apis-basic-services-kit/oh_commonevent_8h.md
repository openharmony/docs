# oh_commonevent.h


## 概述

声明公共事件相关的API，包含订阅公共事件与退订公共事件。

**库：** libohcommonevent.so

**系统能力：** SystemCapability.Notification.CommonEvent

**起始版本：** 12

**相关模块：**[CommonEvent](capi-common-event.md)


## 汇总

### 类型定义

| 名称 | 描述 |
| -------- | -------- |
|typedef struct [CommonEvent_SubscribeInfo](./capi-common-event.md#commonevent_subscribeinfo) [CommonEvent_SubscribeInfo](./capi-common-event.md#commonevent_subscribeinfo) | 订阅者信息。 |
|typedef void [CommonEvent_Subscriber](./capi-common-event.md#commonevent_subscriber) | 订阅者。 |
|typedef struct [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) | 公共事件的数据。 |
|typedef void [CommonEvent_Parameters](./capi-common-event.md#commonevent_parameters) | 公共事件的附加信息。 |
|typedef void (*[CommonEvent_ReceiveCallback](./capi-common-event.md#commonevent_receivecallback))(const [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) *data) | 公共事件的回调函数。 |
|typedef struct [CommonEvent_PublishInfo](./capi-common-event.md#commonevent_publishinfo) [CommonEvent_PublishInfo](./capi-common-event.md#commonevent_publishinfo) | 发布自定义公共事件时使用的公共事件属性对象。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [CommonEvent_ErrCode](./capi-common-event.md#commonevent_errcode)  {<br/>COMMONEVENT_ERR_OK = 0,<br>COMMONEVENT_ERR_PERMISSION_ERROR = 201,<br/>COMMONEVENT_ERR_INVALID_PARAMETER = 401,<br/>COMMONEVENT_ERR_NOT_SYSTEM_SERVICE = 1500004,<br/>COMMONEVENT_ERR_SENDING_REQUEST_FAILED = 1500007,<br/>COMMONEVENT_ERR_INIT_UNDONE = 1500008,<br/>COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED = 1500010,<br/>COMMONEVENT_ERR_ALLOC_MEMORY_FAILED = 1500011<br/>} | 枚举错误码。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| CommonEvent_SubscribeInfo* [OH_CommonEvent_CreateSubscribeInfo](./capi-common-event.md#oh_commonevent_createsubscribeinfo)(const char* events[], int32_t eventsNum); | 创建订阅者信息。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetPublisherPermission](./capi-common-event.md#oh_commonevent_setpublisherpermission)(CommonEvent_SubscribeInfo* info, const char* permission); | 设置订阅者权限。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetPublisherBundleName](./capi-common-event.md#oh_commonevent_setpublisherbundlename)(CommonEvent_SubscribeInfo* info, const char* bundleName); | 设置订阅者包名称。 |
| void [OH_CommonEvent_DestroySubscribeInfo](./capi-common-event.md#oh_commonevent_destroysubscribeinfo)(CommonEvent_SubscribeInfo* info); | 销毁订阅者信息。 |
| CommonEvent_Subscriber* [OH_CommonEvent_CreateSubscriber](./capi-common-event.md#oh_commonevent_createsubscriber)(const CommonEvent_SubscribeInfo* info, CommonEvent_ReceiveCallback callback); | 创建订阅者。 |
| void [OH_CommonEvent_DestroySubscriber](./capi-common-event.md#oh_commonevent_destroysubscriber)(CommonEvent_Subscriber* subscriber); | 销毁订阅者。 |
| CommonEvent_ErrCode [OH_CommonEvent_Subscribe](./capi-common-event.md#oh_commonevent_subscribe)(const CommonEvent_Subscriber* subscriber); | 订阅事件。 |
| CommonEvent_ErrCode [OH_CommonEvent_UnSubscribe](./capi-common-event.md#oh_commonevent_unsubscribe)(const CommonEvent_Subscriber* subscriber); | 退订事件。 |
| const char* [OH_CommonEvent_GetEventFromRcvData](./capi-common-event.md#oh_commonevent_geteventfromrcvdata)(const CommonEvent_RcvData* rcvData); | 获取公共事件名称。 |
| int32_t [OH_CommonEvent_GetCodeFromRcvData](./capi-common-event.md#oh_commonevent_getcodefromrcvdata)(const CommonEvent_RcvData* rcvData); | 获取公共事件结果代码。 |
| const char* [OH_CommonEvent_GetDataStrFromRcvData](./capi-common-event.md#oh_commonevent_getdatastrfromrcvdata)(const CommonEvent_RcvData* rcvData); | 获取公共事件自定义结果数据。 |
| const char* [OH_CommonEvent_GetBundleNameFromRcvData](./capi-common-event.md#oh_commonevent_getbundlenamefromrcvdata)(const CommonEvent_RcvData* rcvData); | 获取公共事件包名称。 |
| const CommonEvent_Parameters* [OH_CommonEvent_GetParametersFromRcvData](./capi-common-event.md#oh_commonevent_getparametersfromrcvdata)(const CommonEvent_RcvData* rcvData); | 获取公共事件附加信息。 |
| bool [OH_CommonEvent_HasKeyInParameters](./capi-common-event.md#oh_commonevent_haskeyinparameters)(const CommonEvent_Parameters* para, const char* key); | 检查公共事件附加信息中是否包含某个键值对信息。 |
| int [OH_CommonEvent_GetIntFromParameters](./capi-common-event.md#oh_commonevent_getintfromparameters)(const CommonEvent_Parameters* para, const char* key, const int defaultValue); | 获取公共事件附加信息中int数据信息。 |
| int32_t [OH_CommonEvent_GetIntArrayFromParameters](./capi-common-event.md#oh_commonevent_getintarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, int** array); | 获取公共事件附加信息中int数组信息。 |
| long [OH_CommonEvent_GetLongFromParameters](./capi-common-event.md#oh_commonevent_getlongfromparameters)(const CommonEvent_Parameters* para, const char* key, const long defaultValue);| 获取公共事件附加信息中long数据信息。 |
| int32_t [OH_CommonEvent_GetLongArrayFromParameters](./capi-common-event.md#oh_commonevent_getlongarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, long** array);| 获取公共事件附加信息中long数组信息。 |
| bool [OH_CommonEvent_GetBoolFromParameters](./capi-common-event.md#oh_commonevent_getboolfromparameters)(const CommonEvent_Parameters* para, const char* key, const bool defaultValue);| 获取公共事件附加信息中布尔数据信息。 |
| int32_t [OH_CommonEvent_GetBoolArrayFromParameters](./capi-common-event.md#oh_commonevent_getlongarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, bool** array);| 获取公共事件附加信息中布尔数组信息。 |
| char [OH_CommonEvent_GetCharFromParameters](./capi-common-event.md#oh_commonevent_getcharfromparameters)(const CommonEvent_Parameters* para, const char* key, const char defaultValue);| 获取公共事件附加信息中字符数据信息。 |
| int32_t [OH_CommonEvent_GetCharArrayFromParameters](./capi-common-event.md#oh_commonevent_getchararrayfromparameters)(const CommonEvent_Parameters* para, const char* key, char** array);| 获取公共事件附加信息中字符数组信息。 |
| double [OH_CommonEvent_GetDoubleFromParameters](./capi-common-event.md#oh_commonevent_getdoublefromparameters)(const CommonEvent_Parameters* para, const char* key, const double defaultValue);| 获取公共事件附加信息中double数据信息。 |
| int32_t [OH_CommonEvent_GetDoubleArrayFromParameters](./capi-common-event.md#oh_commonevent_getdoublearrayfromparameters)(const CommonEvent_Parameters* para, const char* key, double** array);| 获取公共事件附加信息中double数组信息。 |
| CommonEvent_Parameters* [OH_CommonEvent_CreateParameters](./capi-common-event.md#oh_commonevent_createparameters)();| 创建公共事件附加信息对象。 |
| void [OH_CommonEvent_DestroyParameters](./capi-common-event.md#oh_commonevent_destroyparameters)(CommonEvent_Parameters* param);| 销毁公共事件附加信息对象。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetIntToParameters](./capi-common-event.md#oh_commonevent_setinttoparameters)(CommonEvent_Parameters* param, const char* key, const int value);| 设置公共事件附加信息的int类型内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetIntArrayToParameters](./capi-common-event.md#oh_commonevent_setintarraytoparameters)(CommonEvent_Parameters* param, const char* key, const int* value, const size_t num);| 设置公共事件附加信息的int数组内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetLongToParameters](./capi-common-event.md#oh_commonevent_setlongtoparameters)(CommonEvent_Parameters* param, const char* key, const long value);| 设置公共事件附加信息的long类型内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetLongArrayToParameters](./capi-common-event.md#oh_commonevent_setlongarraytoparameters)(CommonEvent_Parameters* param, const char* key, const long* value, const size_t num);| 设置公共事件附加信息的long数组内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetDoubleToParameters](./capi-common-event.md#oh_commonevent_setdoubletoparameters)(CommonEvent_Parameters* param, const char* key, const double value);| 设置公共事件附加信息的double类型内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetDoubleArrayToParameters](./capi-common-event.md#oh_commonevent_setdoublearraytoparameters)(CommonEvent_Parameters* param, const char* key, const double* value, const size_t num);| 设置公共事件附加信息的double数组内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetBoolToParameters](./capi-common-event.md#oh_commonevent_setbooltoparameters)(CommonEvent_Parameters* param, const char* key, const bool value);| 设置公共事件附加信息的布尔类型内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetBoolArrayToParameters](./capi-common-event.md#oh_commonevent_setboolarraytoparameters)(CommonEvent_Parameters* param, const char* key, const bool* value, const size_t num);| 设置公共事件附加信息的布尔数组内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetCharToParameters](./capi-common-event.md#oh_commonevent_setchartoparameters)(CommonEvent_Parameters* param, const char* key, const char value);| 设置公共事件附加信息的字符类型内容。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetCharArrayToParameters](./capi-common-event.md#oh_commonevent_setchararraytoparameters)(CommonEvent_Parameters* param, const char* key, const char* value, const size_t num);| 设置公共事件附加信息的字符数组内容。 |
| CommonEvent_PublishInfo* [OH_CommonEvent_CreatePublishInfo](./capi-common-event.md#oh_commonevent_createpublishinfo)(const bool ordered);| 创建公共事件属性对象。 |
| void [OH_CommonEvent_DestroyPublishInfo](./capi-common-event.md#oh_commonevent_destroypublishinfo)(CommonEvent_PublishInfo* info);| 销毁公共事件属性对象。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoBundleName](./capi-common-event.md#oh_commonevent_setpublishinfobundlename)(CommonEvent_PublishInfo* info, const char* bundleName);| 设置公共事件包名称。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoPermissions](./capi-common-event.md#oh_commonevent_setpublishinfopermissions)(CommonEvent_PublishInfo* info，const char* permissions[], const int32_t num);| 设置公共事件权限。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoCode](./capi-common-event.md#oh_commonevent_setpublishinfocode)(CommonEvent_PublishInfo* info, const int32_t code);| 设置公共事件结果码。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoData](./capi-common-event.md#oh_commonevent_setpublishinfodata)(CommonEvent_PublishInfo* info, const char* data, const size_t length);| 设置公共事件结果数据。 |
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoParameters](./capi-common-event.md#oh_commonevent_setpublishinfoparameters)(CommonEvent_PublishInfo* info, CommonEvent_Parameters* param);| 设置公共事件附加信息。 |
| CommonEvent_ErrCode [OH_CommonEvent_Publish](./capi-common-event.md#oh_commonevent_publish)(const char* event);| 发布自定义公共事件。 |
| CommonEvent_ErrCode [OH_CommonEvent_PublishWithInfo](./capi-common-event.md#oh_commonevent_publishwithinfo)(const char* event, const CommonEvent_PublishInfo* info);| 发布带有指定属性的自定义公共事件。 |
| bool [OH_CommonEvent_IsOrderedCommonEvent](./capi-common-event.md#oh_commonevent_isorderedcommonevent)(const CommonEvent_Subscriber* subscriber);| 查询当前公共事件是否为有序公共事件。 |
| bool [OH_CommonEvent_FinishCommonEvent](./capi-common-event.md#oh_commonevent_finishcommonevent)(CommonEvent_Subscriber* subscriber);| 用于订阅者结束对当前有序公共事件的处理。 |
| bool [OH_CommonEvent_GetAbortCommonEvent](./capi-common-event.md#oh_commonevent_getabortcommonevent)(const CommonEvent_Subscriber* subscriber);| 获取当前有序公共事件是否处于中止状态。 |
| bool [OH_CommonEvent_AbortCommonEvent](./capi-common-event.md#oh_commonevent_abortcommonevent)(CommonEvent_Subscriber* subscriber);| 中止当前的有序公共事件。 |
| bool [OH_CommonEvent_ClearAbortCommonEvent](./capi-common-event.md#oh_commonevent_clearabortcommonevent)(CommonEvent_Subscriber* subscriber);| 取消当前有序公共事件的中止状态。 |
| int32_t [OH_CommonEvent_GetCodeFromSubscriber](./capi-common-event.md#oh_commonevent_getcodefromsubscriber)(const CommonEvent_Subscriber* subscriber);| 获取有序公共事件代码。 |
| int32_t [OH_CommonEvent_GetDataFromSubscriber](./capi-common-event.md#oh_commonevent_getdatafromsubscriber)(const CommonEvent_Subscriber* subscriber);| 获取有序公共事件的数据。 |
| int32_t [OH_CommonEvent_SetCodeToSubscriber](./capi-common-event.md#oh_commonevent_setcodetosubscriber)(CommonEvent_Subscriber* subscriber, const int32_t code);| 设置有序公共事件的代码。 |
| int32_t [OH_CommonEvent_SetDataToSubscriber](./capi-common-event.md#oh_commonevent_setdatatosubscriber)(CommonEvent_Subscriber* subscriber, const char* data, const size_t length);| 设置有序公共事件的数据。 |

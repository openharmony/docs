# oh_commonevent.h


## 概述

声明公共事件相关的API，包含订阅公共事件与退订公共事件。。

**库：** libohcommonevent.so

**系统能力：** SystemCapability.Notification.CommonEvent

**起始版本：** 12

**相关模块：**[CommonEvent](capi-common-event.md)


## 汇总

### 类型定义

| 名称 | 描述 |
| -------- | -------- |
|typedef enum CommonEvent_ErrCode CommonEvent_ErrCode | 枚举错误码。 |
|typedef struct CommonEvent_SubscribeInfo CommonEvent_SubscribeInfo | 订阅者信息。 |
|typedef void CommonEvent_Subscriber | 订阅者。 |
|typedef struct CommonEvent_RcvData CommonEvent_RcvData | 公共事件的数据。 |
|typedef void CommonEvent_Parameters | 公共事件的附加信息。 |
|typedef void (*CommonEvent_ReceiveCallback)(const CommonEvent_RcvData *data) | 公共事件的回调函数。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| CommonEvent_ErrCode  {<br/>COMMONEVENT_ERR_OK = 0,<br>COMMONEVENT_ERR_PERMISSION_ERROR = 201,<br/>COMMONEVENT_ERR_INVALID_PARAMETER = 401,<br/>COMMONEVENT_ERR_SENDING_REQUEST_FAILED = 1500007,<br/>COMMONEVENT_ERR_INIT_UNDONE = 1500008,<br/>COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED = 1500010,<br/>COMMONEVENT_ERR_ALLOC_MEMORY_FAILED = 1500011<br/>} | 枚举错误码。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum) | 创建订阅者信息。 |
| CommonEvent_ErrCode OH_CommonEvent_SetPublisherPermission(CommonEvent_SubscribeInfo* info, const char* permission) | 设置订阅者权限。 |
| CommonEvent_ErrCode OH_CommonEvent_SetPublisherBundleName(CommonEvent_SubscribeInfo* info, const char* bundleName); | 设置订阅者包名称。 |
| void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info) | 销毁订阅者信息。 |
| CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info, CommonEvent_ReceiveCallback callback) | 创建订阅者。 |
| void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber); | 销毁订阅者。 |
| CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber); | 订阅事件。 |
| CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber); | 退订事件。 |
| const char* OH_CommonEvent_GetEventFromRcvData(const CommonEvent_RcvData* rcvData); | 获取公共事件名称。 |
| int32_t OH_CommonEvent_GetCodeFromRcvData(const CommonEvent_RcvData* rcvData); | 获取公共事件结果代码。 |
| const char* OH_CommonEvent_GetDataStrFromRcvData(const CommonEvent_RcvData* rcvData); | 获取公共事件自定义结果数据。 |
| const char* OH_CommonEvent_GetBundleNameFromRcvData(const CommonEvent_RcvData* rcvData); | 获取公共事件包名称。 |
| const CommonEvent_Parameters* OH_CommonEvent_GetParametersFromRcvData(const CommonEvent_RcvData* rcvData); | 获取公共事件附加信息。 |
| bool OH_CommonEvent_HasKeyInParameters(const CommonEvent_Parameters* para, const char* key); | 检查公共事件附加信息中是否包含某个键值对信息。 |
| int OH_CommonEvent_GetIntFromParameters(const CommonEvent_Parameters* para, const char* key, const int defaultValue); | 获取公共事件附加信息中int数据信息。 |
| int32_t OH_CommonEvent_GetIntArrayFromParameters(const CommonEvent_Parameters* para, const char* key, int** array); | 获取公共事件附加信息中int数组信息。 |
| long OH_CommonEvent_GetLongFromParameters(const CommonEvent_Parameters* para, const char* key, const long defaultValue);| 获取公共事件附加信息中long数据信息。 |
| int32_t OH_CommonEvent_GetLongArrayFromParameters(const CommonEvent_Parameters* para, const char* key, long** array);| 获取公共事件附加信息中long数组信息。 |
| bool OH_CommonEvent_GetBoolFromParameters(const CommonEvent_Parameters* para, const char* key, const bool defaultValue);| 获取公共事件附加信息中布尔数据信息。 |
| int32_t OH_CommonEvent_GetBoolArrayFromParameters(const CommonEvent_Parameters* para, const char* key, bool** array);| 获取公共事件附加信息中布尔数组信息。 |
| char OH_CommonEvent_GetCharFromParameters(const CommonEvent_Parameters* para, const char* key, const char defaultValue);| 获取公共事件附加信息中字符数据信息。 |
| int32_t OH_CommonEvent_GetCharArrayFromParameters(const CommonEvent_Parameters* para, const char* key, char** array);| 获取公共事件附加信息中字符数组信息。 |
| double OH_CommonEvent_GetDoubleFromParameters(const CommonEvent_Parameters* para, const char* key, const double defaultValue);| 获取公共事件附加信息中double数据信息。 |
| int32_t OH_CommonEvent_GetDoubleArrayFromParameters(const CommonEvent_Parameters* para, const char* key, double** array);| 获取公共事件附加信息中double数组信息。 |

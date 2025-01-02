# oh_commonevent.h


## Overview

Defines the APIs for subscribing to and unsubscribing from common events.

**Library**: libohcommonevent.so

**System capability**: SystemCapability.Notification.CommonEvent

**Since**: 12

**Related module**: [CommonEvent](capi-common-event.md)


## Summary

### Types

| Name| Description|
| -------- | -------- |
|typedef struct [CommonEvent_SubscribeInfo](./capi-common-event.md#commonevent_subscribeinfo) [CommonEvent_SubscribeInfo](./capi-common-event.md#commonevent_subscribeinfo) | Defines the subscriber information.|
|typedef void [CommonEvent_Subscriber](./capi-common-event.md#commonevent_subscriber) | Defines a subscriber.|
|typedef struct [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) | Defines the common event data.|
|typedef void [CommonEvent_Parameters](./capi-common-event.md#commonevent_parameters) | Defines the additional information about a common event.|
|typedef void (*[CommonEvent_ReceiveCallback](./capi-common-event.md#commonevent_receivecallback))(const [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) *data) | Defines the callback function of a common event.|

### Enums

| Name| Description|
| -------- | -------- |
| typedef enum [CommonEvent_ErrCode](./capi-common-event.md#commonevent_errcode)  {<br>COMMONEVENT_ERR_OK = 0,<br>COMMONEVENT_ERR_PERMISSION_ERROR = 201,<br>COMMONEVENT_ERR_INVALID_PARAMETER = 401,<br>COMMONEVENT_ERR_SENDING_REQUEST_FAILED = 1500007,<br>COMMONEVENT_ERR_INIT_UNDONE = 1500008,<br>COMMONEVENT_ERR_SUBSCRIBER_NUM_EXCEEDED = 1500010,<br>COMMONEVENT_ERR_ALLOC_MEMORY_FAILED = 1500011<br>} | Enumerates the error codes.|


### Functions

| Name| Description|
| -------- | -------- |
| CommonEvent_SubscribeInfo* [OH_CommonEvent_CreateSubscribeInfo](./capi-common-event.md#oh_commonevent_createsubscribeinfo)(const char* events[], int32_t eventsNum) | Creates the subscriber information.|
| CommonEvent_ErrCode [OH_CommonEvent_SetPublisherPermission](./capi-common-event.md#oh_commonevent_setpublisherpermission)(CommonEvent_SubscribeInfo* info, const char* permission) | Sets the subscriber permission.|
| CommonEvent_ErrCode [OH_CommonEvent_SetPublisherBundleName](./capi-common-event.md#oh_commonevent_setpublisherbundlename)(CommonEvent_SubscribeInfo* info, const char* bundleName); | Sets a bundle name of the subscriber.|
| void [OH_CommonEvent_DestroySubscribeInfo](./capi-common-event.md#oh_commonevent_destroysubscribeinfo)(CommonEvent_SubscribeInfo* info) | Destroys the subscriber information.|
| CommonEvent_Subscriber* [OH_CommonEvent_CreateSubscriber](./capi-common-event.md#oh_commonevent_createsubscriber)(const CommonEvent_SubscribeInfo* info, CommonEvent_ReceiveCallback callback) | Creates a subscriber.|
| void [OH_CommonEvent_DestroySubscriber](./capi-common-event.md#oh_commonevent_destroysubscriber)(CommonEvent_Subscriber* subscriber); | Destroys a subscriber.|
| CommonEvent_ErrCode [OH_CommonEvent_Subscribe](./capi-common-event.md#oh_commonevent_subscribe)(const CommonEvent_Subscriber* subscriber); | Subscribes to a common event.|
| CommonEvent_ErrCode [OH_CommonEvent_UnSubscribe](./capi-common-event.md#oh_commonevent_unsubscribe)(const CommonEvent_Subscriber* subscriber); | Unsubscribes from a common event.|
| const char* [OH_CommonEvent_GetEventFromRcvData](./capi-common-event.md#oh_commonevent_geteventfromrcvdata)(const CommonEvent_RcvData* rcvData); | Obtains the name of a common event.|
| int32_t [OH_CommonEvent_GetCodeFromRcvData](./capi-common-event.md#oh_commonevent_getcodefromrcvdata)(const CommonEvent_RcvData* rcvData); | Obtains the result code of a common event.|
| const char* [OH_CommonEvent_GetDataStrFromRcvData](./capi-common-event.md#oh_commonevent_getdatastrfromrcvdata)(const CommonEvent_RcvData* rcvData); | Obtains the custom result data of a common event.|
| const char* [OH_CommonEvent_GetBundleNameFromRcvData](./capi-common-event.md#oh_commonevent_getbundlenamefromrcvdata)(const CommonEvent_RcvData* rcvData); | Obtains the bundle name of a common event.|
| const CommonEvent_Parameters* [OH_CommonEvent_GetParametersFromRcvData](./capi-common-event.md#oh_commonevent_getparametersfromrcvdata)(const CommonEvent_RcvData* rcvData); | Obtains the additional information about a common event.|
| bool [OH_CommonEvent_HasKeyInParameters](./capi-common-event.md#oh_commonevent_haskeyinparameters)(const CommonEvent_Parameters* para, const char* key); | Checks whether the additional information of a common event contains a key-value pair.|
| int [OH_CommonEvent_GetIntFromParameters](./capi-common-event.md#oh_commonevent_getintfromparameters)(const CommonEvent_Parameters* para, const char* key, const int defaultValue); | Obtains the **int** data information from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetIntArrayFromParameters](./capi-common-event.md#oh_commonevent_getintarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, int** array); | Obtains the **int** array information from the additional information of a common event.|
| long [OH_CommonEvent_GetLongFromParameters](./capi-common-event.md#oh_commonevent_getlongfromparameters)(const CommonEvent_Parameters* para, const char* key, const long defaultValue);| Obtains the **long** data information from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetLongArrayFromParameters](./capi-common-event.md#oh_commonevent_getlongarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, long** array);| Obtains the **long** array information from the additional information of a common event.|
| bool [OH_CommonEvent_GetBoolFromParameters](./capi-common-event.md#oh_commonevent_getboolfromparameters)(const CommonEvent_Parameters* para, const char* key, const bool defaultValue);| Obtains the **bool** data information from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetBoolArrayFromParameters](./capi-common-event.md#oh_commonevent_getlongarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, bool** array);| Obtains the **bool** array information from the additional information of a common event.|
| char [OH_CommonEvent_GetCharFromParameters](./capi-common-event.md#oh_commonevent_getcharfromparameters)(const CommonEvent_Parameters* para, const char* key, const char defaultValue);| Obtains the **char** data from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetCharArrayFromParameters](./capi-common-event.md#oh_commonevent_getchararrayfromparameters)(const CommonEvent_Parameters* para, const char* key, char** array);| Obtains the **char** array information from the additional information of a common event.|
| double [OH_CommonEvent_GetDoubleFromParameters](./capi-common-event.md#oh_commonevent_getdoublefromparameters)(const CommonEvent_Parameters* para, const char* key, const double defaultValue);| Obtains the **double** data information from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetDoubleArrayFromParameters](./capi-common-event.md#oh_commonevent_getdoublearrayfromparameters)(const CommonEvent_Parameters* para, const char* key, double** array);| Obtains the **double** array information from the additional information of a common event.|

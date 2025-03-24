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
|typedef struct [CommonEvent_SubscribeInfo](./capi-common-event.md#commonevent_subscribeinfo) [CommonEvent_SubscribeInfo](./capi-common-event.md#commonevent_subscribeinfo) | Defines a struct for the subscriber information. |
|typedef void [CommonEvent_Subscriber](./capi-common-event.md#commonevent_subscriber) | Defines a subscriber.|
|typedef struct [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) | Defines a struct for the common event data. |
|typedef void [CommonEvent_Parameters](./capi-common-event.md#commonevent_parameters) | Defines the additional information about a common event.|
|typedef void (*[CommonEvent_ReceiveCallback](./capi-common-event.md#commonevent_receivecallback))(const [CommonEvent_RcvData](./capi-common-event.md#commonevent_rcvdata) *data) | Defines the callback function of a common event.|
|typedef struct [CommonEvent_PublishInfo](./capi-common-event.md#commonevent_publishinfo) [CommonEvent_PublishInfo](./capi-common-event.md#commonevent_publishinfo) | Defines a struct for an attribute object used for publishing a custom common event. |

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
| int [OH_CommonEvent_GetIntFromParameters](./capi-common-event.md#oh_commonevent_getintfromparameters)(const CommonEvent_Parameters* para, const char* key, const int defaultValue); | Obtains the int data from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetIntArrayFromParameters](./capi-common-event.md#oh_commonevent_getintarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, int** array); | Obtains the int array from the additional information of a common event.|
| long [OH_CommonEvent_GetLongFromParameters](./capi-common-event.md#oh_commonevent_getlongfromparameters)(const CommonEvent_Parameters* para, const char* key, const long defaultValue);| Obtains the long data from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetLongArrayFromParameters](./capi-common-event.md#oh_commonevent_getlongarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, long** array);| Obtains the long array from the additional information of a common event.|
| bool [OH_CommonEvent_GetBoolFromParameters](./capi-common-event.md#oh_commonevent_getboolfromparameters)(const CommonEvent_Parameters* para, const char* key, const bool defaultValue);| Obtains the Boolean data from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetBoolArrayFromParameters](./capi-common-event.md#oh_commonevent_getlongarrayfromparameters)(const CommonEvent_Parameters* para, const char* key, bool** array);| Obtains the Boolean array from the additional information of a common event.|
| char [OH_CommonEvent_GetCharFromParameters](./capi-common-event.md#oh_commonevent_getcharfromparameters)(const CommonEvent_Parameters* para, const char* key, const char defaultValue);| Obtains the character data from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetCharArrayFromParameters](./capi-common-event.md#oh_commonevent_getchararrayfromparameters)(const CommonEvent_Parameters* para, const char* key, char** array);| Obtains the character array from the additional information of a common event.|
| double [OH_CommonEvent_GetDoubleFromParameters](./capi-common-event.md#oh_commonevent_getdoublefromparameters)(const CommonEvent_Parameters* para, const char* key, const double defaultValue);| Obtains the double data from the additional information of a common event.|
| int32_t [OH_CommonEvent_GetDoubleArrayFromParameters](./capi-common-event.md#oh_commonevent_getdoublearrayfromparameters)(const CommonEvent_Parameters* para, const char* key, double** array);| Obtains the double array from the additional information of a common event.|
| CommonEvent_Parameters* [OH_CommonEvent_CreateParameters](./capi-common-event.md#oh_commonevent_createparameters)();| Creates an additional information object of a common event.|
| void [OH_CommonEvent_DestroyParameters](./capi-common-event.md#oh_commonevent_destroyparameters)(CommonEvent_Parameters* param);| Destroys an additional information object of a common event.|
| CommonEvent_ErrCode [OH_CommonEvent_SetIntToParameters](./capi-common-event.md#oh_commonevent_setinttoparameters)(CommonEvent_Parameters* param, const char* key, const int value);| Sets the additional information of a common event. The value is the content of the int type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetIntArrayToParameters](./capi-common-event.md#oh_commonevent_setintarraytoparameters)(CommonEvent_Parameters* param, const char* key, const int* value, const size_t num);| Sets the additional information of a common event. The value is the content of the int array type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetLongToParameters](./capi-common-event.md#oh_commonevent_setlongtoparameters)(CommonEvent_Parameters* param, const char* key, const long value);| Sets the additional information of a common event. The value is the content of the long type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetLongArrayToParameters](./capi-common-event.md#oh_commonevent_setlongarraytoparameters)(CommonEvent_Parameters* param, const char* key, const long* value, const size_t num);| Sets the additional information of a common event. The value is the content of the long array type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetDoubleToParameters](./capi-common-event.md#oh_commonevent_setdoubletoparameters)(CommonEvent_Parameters* param, const char* key, const double value);| Sets the additional information of a common event. The value is the content of the double type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetDoubleArrayToParameters](./capi-common-event.md#oh_commonevent_setdoublearraytoparameters)(CommonEvent_Parameters* param, const char* key, const double* value, const size_t num);| Sets the additional information of a common event. The value is the content of the double array type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetBoolToParameters](./capi-common-event.md#oh_commonevent_setbooltoparameters)(CommonEvent_Parameters* param, const char* key, const bool value);| Sets the additional information of a common event. The value is the content of the Boolean type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetBoolArrayToParameters](./capi-common-event.md#oh_commonevent_setboolarraytoparameters)(CommonEvent_Parameters* param, const char* key, const bool* value, const size_t num);| Sets the additional information of a common event. The value is the content of the Boolean array type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetCharToParameters](./capi-common-event.md#oh_commonevent_setchartoparameters)(CommonEvent_Parameters* param, const char* key, const char value);| Sets the additional information of a common event. The value is the content of the character type.|
| CommonEvent_ErrCode [OH_CommonEvent_SetCharArrayToParameters](./capi-common-event.md#oh_commonevent_setchararraytoparameters)(CommonEvent_Parameters* param, const char* key, const char* value, const size_t num);| Sets the additional information of a common event. The value is the content of the character array type.|
| CommonEvent_PublishInfo* [OH_CommonEvent_CreatePublishInfo](./capi-common-event.md#oh_commonevent_createpublishinfo)(const bool ordered);| Creates an attribute object of a common event.|
| void [OH_CommonEvent_DestroyPublishInfo](./capi-common-event.md#oh_commonevent_destroypublishinfo)(CommonEvent_PublishInfo* info);| Destroys an attribute object of a common event.|
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoBundleName](./capi-common-event.md#oh_commonevent_setpublishinfobundlename)(CommonEvent_PublishInfo* info, const char* bundleName);| Sets the bundle name of a common event.|
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoPermissions](./capi-common-event.md#oh_commonevent_setpublishinfopermissions)(CommonEvent_PublishInfo* info, const char* permissions[], const int32_t num);| Sets the common event permissions.|
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoCode](./capi-common-event.md#oh_commonevent_setpublishinfocode)(CommonEvent_PublishInfo* info, const int32_t code);| Sets the result code of a common event.|
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoData](./capi-common-event.md#oh_commonevent_setpublishinfodata)(CommonEvent_PublishInfo* info, const char* data, const size_t length);| Sets the result data of a common event.|
| CommonEvent_ErrCode [OH_CommonEvent_SetPublishInfoParameters](./capi-common-event.md#oh_commonevent_setpublishinfoparameters)(CommonEvent_PublishInfo* info, CommonEvent_Parameters* param);| Sets the additional information of a common event.|
| CommonEvent_ErrCode [OH_CommonEvent_Publish](./capi-common-event.md#oh_commonevent_publish)(const char* event);| Publishes a custom common event.|
| CommonEvent_ErrCode [OH_CommonEvent_PublishWithInfo](./capi-common-event.md#oh_commonevent_publishwithinfo)(const char* event, const CommonEvent_PublishInfo* info);| Publishes a custom common event with specified attributes.|
| bool [OH_CommonEvent_IsOrderedCommonEvent](./capi-common-event.md#oh_commonevent_isorderedcommonevent)(const CommonEvent_Subscriber* subscriber);| Checks whether a common event is an ordered common event.|
| bool [OH_CommonEvent_FinishCommonEvent](./capi-common-event.md#oh_commonevent_finishcommonevent)(CommonEvent_Subscriber* subscriber);| Finishes an ordered common event.|
| bool [OH_CommonEvent_GetAbortCommonEvent](./capi-common-event.md#oh_commonevent_getabortcommonevent)(const CommonEvent_Subscriber* subscriber);| Checks whether an ordered common event is aborted.|
| bool [OH_CommonEvent_AbortCommonEvent](./capi-common-event.md#oh_commonevent_abortcommonevent)(CommonEvent_Subscriber* subscriber);| Aborts an ordered common event.|
| bool [OH_CommonEvent_ClearAbortCommonEvent](./capi-common-event.md#oh_commonevent_clearabortcommonevent)(CommonEvent_Subscriber* subscriber);| Clears the aborted state of an ordered common event.|
| int32_t [OH_CommonEvent_GetCodeFromSubscriber](./capi-common-event.md#oh_commonevent_getcodefromsubscriber)(const CommonEvent_Subscriber* subscriber);| Obtains the result code of an ordered common event.|
| int32_t [OH_CommonEvent_GetDataFromSubscriber](./capi-common-event.md#oh_commonevent_getdatafromsubscriber)(const CommonEvent_Subscriber* subscriber);| Obtains the result data of an ordered common event.|
| int32_t [OH_CommonEvent_SetCodeToSubscriber](./capi-common-event.md#oh_commonevent_setcodetosubscriber)(CommonEvent_Subscriber* subscriber, const int32_t code);| Sets the result code of an ordered common event.|
| int32_t [OH_CommonEvent_SetDataToSubscriber](./capi-common-event.md#oh_commonevent_setdatatosubscriber)(CommonEvent_Subscriber* subscriber, const char* data, const size_t length);| Sets the result data of an ordered common event.|

# Subscribing to Common Events in C


## When to Use

A subscriber created using [OH_CommonEvent_CreateSubscriber](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_createsubscriber) can subscribe to a common event. If a subscribed event is published, the subscriber will receive the event and its parameters. Also, the subscriber object can be used to further process ordered common events.

## Available APIs

For details about the APIs, see [CommonEvent](../../reference/apis-basic-services-kit/capi-common-event.md).

| API                              | Description                                                            |
| ------------------------------------ | ---------------------------------------------------------------- |
|[CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_createsubscribeinfo)|Creates the subscriber information.|
|[void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_destroysubscribeinfo)|Destroys the subscriber information.|
|[CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info, CommonEvent_ReceiveCallback callback)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_createsubscriber)| Creates a subscriber.|
|[void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_destroysubscriber)|Destroys a subscriber.|
|[CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_subscribe)|Subscribes to an event.|
|[bool OH_CommonEvent_AbortCommonEvent(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_abortcommonevent)|Whether to abort an ordered common event.|
|[bool OH_CommonEvent_ClearAbortCommonEvent(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_clearabortcommonevent)|Whether to clear the aborted state of an ordered common event.|
|[bool OH_CommonEvent_FinishCommonEvent(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_finishcommonevent)|Whether to finish processing an ordered common event.|

## How to Develop

1. Reference header files.

   ```c++
   #include <cstdint>
   #include <cstdio>
   #include <cwchar>
   #include <vector>
   #include <string.h>
   #include "hilog/log.h"
   #include "BasicServicesKit/oh_commonevent.h"
   #include "BasicServicesKit/oh_commonevent_support.h"
   ```

2. Add dynamic link libraries to the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohcommonevent.so
   )
   ```

3. Create the subscriber information.

   Use [OH_CommonEvent_CreateSubscribeInfo](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_createsubscribeinfo) to create subscriber information.

   ```c++
   CommonEvent_SubscribeInfo* CreateSubscribeInfo(const char* events[], int32_t eventsNum, const char* permission, const char* bundleName) {
       int32_t ret = -1;
       // Create the subscriber information.
       CommonEvent_SubscribeInfo* info = OH_CommonEvent_CreateSubscribeInfo(events, eventsNum);

       // Set the subscriber permission.
       ret = OH_CommonEvent_SetPublisherPermission(info, permission);
       OH_LOG_INFO(LOG_APP, "OH_CommonEvent_SetPublisherPermission ret <%{public}d>.", ret);
       
       // Set a bundle name of the subscriber.
       ret = OH_CommonEvent_SetPublisherBundleName(info, bundleName);
       OH_LOG_INFO(LOG_APP, "OH_CommonEvent_SetPublisherBundleName ret <%{public}d>.", ret);
       return info;
   }
   
   // Destroy the subscriber information.
   void DestroySubscribeInfo(CommonEvent_SubscribeInfo* info) {
       OH_CommonEvent_DestroySubscribeInfo(info);
       info = nullptr;
   }
   ```

4. Create a subscriber.

   Pass in the callback function [CommonEvent_ReceiveCallback](../../reference/apis-basic-services-kit/capi-common-event.md#commonevent_receivecallback) of the common event when a subscriber is created. When the event is published, the subscriber receives the callback data [CommonEvent_RcvData](../../reference/apis-basic-services-kit/capi-common-event.md#commonevent_rcvdata).

   ```c++
   // Common event callback.
   void OnReceive(const CommonEvent_RcvData *data) {
       // Obtain the name of a common event.
       const char *event = OH_CommonEvent_GetEventFromRcvData(data);
       
       // Obtain the result code of a common event.
       int code = OH_CommonEvent_GetCodeFromRcvData(data);
       
       // Obtain the custom result data of a common event.
       const char *retData = OH_CommonEvent_GetDataStrFromRcvData(data);
       
       // Obtain the bundle name of a common event.
       const char *bundle = OH_CommonEvent_GetBundleNameFromRcvData(data);
       
       // Obtain the additional information of a common event.
       const CommonEvent_Parameters *parameters = OH_CommonEvent_GetParametersFromRcvData(data);
       OH_LOG_INFO(LOG_APP, "event: %{public}s, code: %{public}d, data: %{public}s, bundle: %{public}s", event, code, retData, bundle);
   }
   ```

   Use [CommonEvent_Parameters](../../reference/apis-basic-services-kit/capi-common-event.md#commonevent_parameters) to pass in a key to obtain the additional information.

   ```c++
   void GetParameters(const CommonEvent_RcvData *data) {
       // Obtain the additional information of a common event.
       bool exists = false;
       const CommonEvent_Parameters *parameters = OH_CommonEvent_GetParametersFromRcvData(data);

       // Check whether the additional information of a common event contains a KV pair.
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "intKey");
       // Obtain the int data from the additional information of a common event.
       int intValue = OH_CommonEvent_GetIntFromParameters(parameters, "intKey", 10);
       OH_LOG_INFO(LOG_APP, "exists = %{public}d, intValue = %{public}d", exists, intValue);
       
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "boolKey");
       // Obtain the Boolean data from the additional information of a common event.
       bool boolValue = OH_CommonEvent_GetBoolFromParameters(parameters, "boolKey", false);
       OH_LOG_INFO(LOG_APP, "exists = %{public}d, boolValue = %{public}d", exists, boolValue);
   
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "longKey");
       // Obtain the long data from the additional information of a common event.
       long longValue = OH_CommonEvent_GetLongFromParameters(parameters, "longKey", 1111111111);
       OH_LOG_INFO(LOG_APP, "exists = %{public}d, longValue = %{public}ld", exists, longValue);
   
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "doubleKey");
       // Obtain the double data from the additional information of a common event.
       double doubleValue = OH_CommonEvent_GetDoubleFromParameters(parameters, "doubleKey", 11.11);
       OH_LOG_INFO(LOG_APP, "exists = %{public}d, doubleValue = %{public}f", exists, doubleValue);
   
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "charKey");
       // Obtain the char data from the additional information of a common event.
       char charValue = OH_CommonEvent_GetCharFromParameters(parameters, "charKey", 'A');
       OH_LOG_INFO(LOG_APP, "exists = %{public}d, charValue = %{public}c", exists, charValue);
       
       int** arr = new int*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "intArrayKey");
       // Obtain the int array from the additional information of a common event.
       int32_t intArraySize = OH_CommonEvent_GetIntArrayFromParameters(parameters, "intArrayKey", arr);
       if (intArraySize <= 0 || *arr == nullptr) {
           OH_LOG_ERROR(LOG_APP, "exists = %{public}d, Failed to get int array or invalid size: %{public}d", exists, intArraySize);
       } else {
           OH_LOG_INFO(LOG_APP, "exists = %{public}d, intArraySize = %{public}d", exists, intArraySize);
           for (int i = 0; i < intArraySize; i++) {
               OH_LOG_INFO(LOG_APP, "<%{public}d>", *((*arr) + i));
           }
       }
       
       long** longArray = new long*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "longArrayKey");
       // Obtain the long array from the additional information of a common event.
       int32_t longArraySize = OH_CommonEvent_GetLongArrayFromParameters(parameters, "longArrayKey", longArray);
       if (longArraySize <= 0 || *longArray == nullptr) {
           OH_LOG_ERROR(LOG_APP, "exists = %{public}d, Failed to get long array or invalid size: %{public}d", exists, longArraySize);
       } else {
           OH_LOG_INFO(LOG_APP, "exists = %{public}d, longArraySize = %{public}d", exists, longArraySize);
           for (int i = 0; i < longArraySize; i++) {
               OH_LOG_INFO(LOG_APP, "<%{public}ld>", *((*longArray) + i));
           }
       }
   
       double** doubleArray = new double*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "doubleArrayKey");
       // Obtain the double array from the additional information of a common event.
       int32_t doubleArraySize = OH_CommonEvent_GetDoubleArrayFromParameters(parameters, "doubleArrayKey", doubleArray);
       if (doubleArraySize <= 0 || *doubleArray == nullptr) {
          OH_LOG_ERROR(LOG_APP, "exists = %{public}d, Failed to get double array or invalid size: %{public}d", exists, doubleArraySize);
       } else {
           OH_LOG_INFO(LOG_APP, "exists = %{public}d, doubleArraySize = %{public}d", exists, doubleArraySize);
           for (int i = 0; i < doubleArraySize; i++) {
               OH_LOG_INFO(LOG_APP, "<%{public}f>", *((*doubleArray) + i));
           }
       }
   
       char** charArray = new char*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "charArrayKey");
       // Obtain the char array from the additional information of a common event.
       int32_t charArraySize = OH_CommonEvent_GetCharArrayFromParameters(parameters, "charArrayKey", charArray);
       if (charArraySize <= 0 || *charArray == nullptr) {
           OH_LOG_ERROR(LOG_APP, "exists = %{public}d, Failed to get charArray or invalid size: %{public}d", exists, charArraySize);
       } else {
           OH_LOG_INFO(LOG_APP, "charArray as string: %{public}s", *charArray);
       }
   
       bool** boolArray = new bool*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "boolArrayKey");
       // Obtain the Boolean array from the additional information of a common event.
       int32_t boolArraySize = OH_CommonEvent_GetBoolArrayFromParameters(parameters, "boolArrayKey", boolArray);
       if (boolArraySize <= 0 || *boolArray == nullptr) {
          OH_LOG_ERROR(LOG_APP, "exists = %{public}d, Failed to get boolArray or invalid size: %{public}d", exists, boolArraySize);
       } else {
           OH_LOG_INFO(LOG_APP, "exists = %{public}d, boolArraySize = %{public}d", exists, boolArraySize);
           for (int i = 0; i < boolArraySize; i++) {
               OH_LOG_INFO(LOG_APP, "<%{public}d>", *((*boolArray) + i));
           }
       }
   }
   ```

   Use [OH_CommonEvent_CreateSubscriber](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_createsubscriber) to create a subscriber and pass in the subscriber information [CommonEvent_SubscribeInfo](../../reference/apis-basic-services-kit/capi-common-event.md#commonevent_subscribeinfo) and event callback function [OnReceive](../../reference/apis-basic-services-kit/capi-common-event.md#commonevent_receivecallback).

   ```c++
   // Create a subscriber.
   CommonEvent_Subscriber* CreateSubscriber(CommonEvent_SubscribeInfo* info) {
       return OH_CommonEvent_CreateSubscriber(info, OnReceive);
   }
   
   // Destroy a subscriber.
   void DestroySubscriber(CommonEvent_Subscriber* Subscriber) {
       OH_CommonEvent_DestroySubscriber(Subscriber);
       Subscriber = nullptr;
   }
   ```

5. Subscribe to an event.

   Subscribe to events through [OH_CommonEvent_Subscribe](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_subscribe).

   ```c++
   void Subscribe(CommonEvent_Subscriber* subscriber) {
       // Subscribe to an event by passing a subscriber.
       int32_t ret = OH_CommonEvent_Subscribe(subscriber);
       OH_LOG_INFO(LOG_APP, "OH_CommonEvent_Subscribe ret <%{public}d>.", ret);
   }
   ```

6. (Optional) Further process the subscribed event if this event is an ordered common event.

   Based on the priority set by the subscriber, the common event is preferentially sent to the subscriber with a higher priority. After the subscriber successfully receives the event, the public event is sent to the subscriber with a lower priority. Subscribers with the same priority receive common events in a random order.

   > **NOTE**
   >
   > After receiving a common event, the subscriber can further process the ordered common event through the following API.

   - Abort an ordered common event.

     Use [OH_CommonEvent_AbortCommonEvent](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_abortcommonevent) and [OH_CommonEvent_FinishCommonEvent](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_finishcommonevent) together to abort an ordered common event so that this event is not published to the next subscriber.

     ```c++
     void AbortCommonEvent(CommonEvent_Subscriber* subscriber) {
         // Check whether the event is an ordered common event.
         if(!OH_CommonEvent_IsOrderedCommonEvent(subscriber)) {
             OH_LOG_INFO(LOG_APP, "Not ordered common event.");
             return;
         }
         // Abort an ordered common event.
         if(OH_CommonEvent_AbortCommonEvent(subscriber)) {
             if(OH_CommonEvent_FinishCommonEvent(subscriber)) {
                 // Obtain the result of the abort state of an ordered common event.
                 OH_LOG_INFO(LOG_APP, "Abort common event success, Get abort <%{public}d>.",   OH_CommonEvent_GetAbortCommonEvent(subscriber));
             }
         }
         OH_LOG_ERROR(LOG_APP, "Abort common event failed.");
     }
     ```

   - Clear the aborted state of an ordered common event.

     Use [OH_CommonEvent_ClearAbortCommonEvent](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_clearabortcommonevent) and [OH_CommonEvent_FinishCommonEvent](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_finishcommonevent) together to clear the aborted state of an ordered common event so that this event is published to the next subscriber.

     ```c++
     void ClearAbortCommonEvent(CommonEvent_Subscriber* subscriber) {
         // Check whether the event is an ordered common event.
         if(!OH_CommonEvent_IsOrderedCommonEvent(subscriber)) {
             OH_LOG_INFO(LOG_APP, "Not ordered common event.");
             return;
         }
         // Abort an ordered common event.
         if(!OH_CommonEvent_AbortCommonEvent(subscriber)) {
             OH_LOG_ERROR(LOG_APP, "Abort common event failed.");
             return;
         }
         // Clear the aborted state of an ordered event.
         if(OH_CommonEvent_ClearAbortCommonEvent(subscriber)) {
             if(OH_CommonEvent_FinishCommonEvent(subscriber)) {
                 // Obtain the result of the abort state of an ordered common event.
                 OH_LOG_INFO(LOG_APP, "Clear abort common event success, Get abort <%{public}d>.",   OH_CommonEvent_GetAbortCommonEvent(subscriber));
             }
         }
         OH_LOG_ERROR(LOG_APP, "Clear abort common event failed.");
     }
     ```

   - Modify the content of an ordered common event.

     Use [OH_CommonEvent_SetCodeToSubscriber](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_setcodetosubscriber) and [OH_CommonEvent_SetDataToSubscriber](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_setdatatosubscriber) to set the result code and data of an ordered common event.

     ```c++
     void SetToSubscriber(CommonEvent_Subscriber* subscriber, const int32_t code, const char* data) {
         // Set the result code of an ordered common event.
         if(!OH_CommonEvent_SetCodeToSubscriber(subscriber, code)) {
             OH_LOG_ERROR(LOG_APP, "OH_CommonEvent_SetCodeToSubscriber failed.");
             return;
         }
         // Set the result data for an ordered common event.
         size_t dataLength = strlen(data);
         if(!OH_CommonEvent_SetDataToSubscriber(subscriber, data, dataLength)) {
             OH_LOG_ERROR(LOG_APP, "OH_CommonEvent_SetDataToSubscriber failed.");
             return;
         }
     }
   
     void GetFromSubscriber(CommonEvent_Subscriber* subscriber) {
         // Obtain the result data and code of an ordered common event.
         const char* data = OH_CommonEvent_GetDataFromSubscriber(subscriber);
         int32_t code = OH_CommonEvent_GetCodeFromSubscriber(subscriber);
         OH_LOG_INFO(LOG_APP, "Subscriber data <%{public}s>, code <%{public}d>.", data, code);
     }
     ```
   

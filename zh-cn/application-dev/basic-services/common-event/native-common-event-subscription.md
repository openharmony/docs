# 订阅公共事件（C/C++）


## 场景介绍

通过[OH_CommonEvent_CreateSubscriber](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createsubscriber)创建的订阅者可以对某个公共事件进行订阅，如果有订阅的事件发布那么订阅了这个事件的订阅者将会收到该事件及其传递的参数，也可以通过订阅者对象进一步处理有序公共事件。

## 接口说明

详细的API说明请参考[CommonEvent API参考](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md)。

| 接口名                               | 描述                                                             |
| ------------------------------------ | ---------------------------------------------------------------- |
|[CommonEvent_SubscribeInfo* OH_CommonEvent_CreateSubscribeInfo(const char* events[], int32_t eventsNum)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createsubscribeinfo)|创建订阅者信息。|
|[void OH_CommonEvent_DestroySubscribeInfo(CommonEvent_SubscribeInfo* info)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroysubscribeinfo)|销毁订阅者信息。|
|[CommonEvent_Subscriber* OH_CommonEvent_CreateSubscriber(const CommonEvent_SubscribeInfo* info, CommonEvent_ReceiveCallback callback)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createsubscriber)| 创建订阅者。|
|[void OH_CommonEvent_DestroySubscriber(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroysubscriber)|销毁订阅者。|
|[CommonEvent_ErrCode OH_CommonEvent_Subscribe(const CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_subscribe)|订阅事件。|
|[bool OH_CommonEvent_AbortCommonEvent(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_abortcommonevent)|中止当前的有序公共事件。|
|[bool OH_CommonEvent_ClearAbortCommonEvent(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_clearabortcommonevent)|取消当前有序公共事件的中止状态。|
|[bool OH_CommonEvent_FinishCommonEvent(CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_finishcommonevent)|结束对当前有序公共事件的处理。|

## 开发步骤

1. 引用头文件。

   ```c++
   #include <cstdint>
   #include <cstdio>
   #include <cwchar>
   #include <string.h>
   #include "hilog/log.h"
   #include "BasicServicesKit/oh_commonevent.h"
   ```

2. 在CMake脚本中添加动态链接库。

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohcommonevent.so
   )
   ```

3. 创建订阅者信息。

   通过[OH_CommonEvent_CreateSubscribeInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createsubscribeinfo)创建订阅者信息。

   ```c++
   CommonEvent_SubscribeInfo* CreateSubscribeInfo(const char* events[], int32_t eventsNum, const char* permission, const char* bundleName) {
       int32_t ret = -1;
       // 创建订阅者信息
       CommonEvent_SubscribeInfo* info = OH_CommonEvent_CreateSubscribeInfo(events, eventsNum);

       // 设置发布者权限
       ret = OH_CommonEvent_SetPublisherPermission(info, permission);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublisherPermission ret <%{public}d>.", ret);
       
       // 设置发布者包名称
       ret = OH_CommonEvent_SetPublisherBundleName(info, bundleName);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublisherBundleName ret <%{public}d>.", ret);
       return info;
   }
   
   // 销毁订阅者信息
   void DestroySubscribeInfo(CommonEvent_SubscribeInfo* info) {
       OH_CommonEvent_DestroySubscribeInfo(info);
       info = nullptr;
   }
   ```

4. 创建订阅者。

   先创建订阅者时通过传入公共事件的回调函数[CommonEvent_ReceiveCallback](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#commonevent_receivecallback)，事件发布时，订阅者会接收到回调数据[CommonEvent_RcvData](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#结构体)。

   ```c++
   // 公共事件回调函数
   void OnReceive(const CommonEvent_RcvData *data) {
       // 获取回调公共事件名称
       const char *event = OH_CommonEvent_GetEventFromRcvData(data);
       
       // 获取回调公共事件结果代码
       int code = OH_CommonEvent_GetCodeFromRcvData(data);
       
       // 获取回调公共事件自定义结果数据
       const char *retData = OH_CommonEvent_GetDataStrFromRcvData(data);
       
       // 获取回调公共事件包名称
       const char *bundle = OH_CommonEvent_GetBundleNameFromRcvData(data);
       
       // 获取回调公共事件附件信息
       const CommonEvent_Parameters *parameters = OH_CommonEvent_GetParametersFromRcvData(data);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "event: %{public}s, code: %{public}d, data: %{public}s, bundle: %{public}s", event, code, retData, bundle);
   }
   ```

   通过[CommonEvent_Parameters](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#变量)传入key来获取附加信息内容。

   ```c++
   void GetParameters(const CommonEvent_RcvData *data) {
       // 获取回调公共事件附件信息
       bool exists = false;
       const CommonEvent_Parameters *parameters = OH_CommonEvent_GetParametersFromRcvData(data);

       // 检查公共事件附加信息中是否包含某个键值对信息
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "intKey");
       // 获取公共事件附加信息中int数据信息
       int intValue = OH_CommonEvent_GetIntFromParameters(parameters, "intKey", 10);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, intValue = %{public}d", exists, intValue);
       
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "boolKey");
       // 获取公共事件附加信息中bool数据信息
       bool boolValue = OH_CommonEvent_GetBoolFromParameters(parameters, "boolKey", false);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, boolValue = %{public}d", exists, boolValue);
   
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "longKey");
       // 获取公共事件附加信息中long数据信息
       long longValue = OH_CommonEvent_GetLongFromParameters(parameters, "longKey", 1111111111);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, longValue = %{public}ld", exists, longValue);
   
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "doubleKey");
       // 获取公共事件附加信息中double数据信息
       double doubleValue = OH_CommonEvent_GetDoubleFromParameters(parameters, "doubleKey", 11.11);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, doubleValue = %{public}f", exists, doubleValue);
   
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "charKey");
       // 获取公共事件附加信息中char数据信息
       char charValue = OH_CommonEvent_GetCharFromParameters(parameters, "charKey", 'A');
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, charValue = %{public}c", exists, charValue);
       
       int** arr = new int*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "intArrayKey");
       // 获取公共事件附加信息中int数组信息
       int32_t intArraySize = OH_CommonEvent_GetIntArrayFromParameters(parameters, "intArrayKey", arr);
       if (intArraySize <= 0 || *arr == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "exists = %{public}d, Failed to get int array or invalid size: %{public}d", exists, intArraySize);
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, intArraySize = %{public}d", exists, intArraySize);
           for (int i = 0; i < intArraySize; i++) {
               OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "<%{public}d>", *((*arr) + i));
           }
       }
       
       long** longArray = new long*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "longArrayKey");
       // 获取公共事件附加信息中long数组信息
       int32_t longArraySize = OH_CommonEvent_GetLongArrayFromParameters(parameters, "longArrayKey", longArray);
       if (longArraySize <= 0 || *longArray == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "exists = %{public}d, Failed to get long array or invalid size: %{public}d", exists, longArraySize);
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, longArraySize = %{public}d", exists, longArraySize);
           for (int i = 0; i < longArraySize; i++) {
               OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "<%{public}ld>", *((*longArray) + i));
           }
       }
   
       double** doubleArray = new double*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "doubleArrayKey");
       // 获取公共事件附加信息中double数组信息
       int32_t doubleArraySize = OH_CommonEvent_GetDoubleArrayFromParameters(parameters, "doubleArrayKey", doubleArray);
       if (doubleArraySize <= 0 || *doubleArray == nullptr) {
          OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "exists = %{public}d, Failed to get double array or invalid size: %{public}d", exists, doubleArraySize);
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, doubleArraySize = %{public}d", exists, doubleArraySize);
           for (int i = 0; i < doubleArraySize; i++) {
               OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "<%{public}f>", *((*doubleArray) + i));
           }
       }
   
       char** charArray = new char*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "charArrayKey");
       // 获取公共事件附加信息中char数组信息
       int32_t charArraySize = OH_CommonEvent_GetCharArrayFromParameters(parameters, "charArrayKey", charArray);
       if (charArraySize <= 0 || *charArray == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "exists = %{public}d, Failed to get charArray or invalid size: %{public}d", exists, charArraySize);
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "charArray as string: %{public}s", *charArray);
       }
   
       bool** boolArray = new bool*;
       exists = OH_CommonEvent_HasKeyInParameters(parameters, "boolArrayKey");
       // 获取公共事件附加信息中bool数组信息
       int32_t boolArraySize = OH_CommonEvent_GetBoolArrayFromParameters(parameters, "boolArrayKey", boolArray);
       if (boolArraySize <= 0 || *boolArray == nullptr) {
          OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "exists = %{public}d, Failed to get boolArray or invalid size: %{public}d", exists, boolArraySize);
       } else {
           OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "exists = %{public}d, boolArraySize = %{public}d", exists, boolArraySize);
           for (int i = 0; i < boolArraySize; i++) {
               OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "<%{public}d>", *((*boolArray) + i));
           }
       }
   }
   ```

   通过[OH_CommonEvent_CreateSubscriber](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createsubscriber)创建订阅者，传入订阅者信息[CommonEvent_SubscribeInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#结构体)和事件回调函数[OnReceive](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#commonevent_receivecallback)。

   ```c++
   // 创建订阅者
   CommonEvent_Subscriber* CreateSubscriber(CommonEvent_SubscribeInfo* info) {
       return OH_CommonEvent_CreateSubscriber(info, OnReceive);
   }
   
   // 销毁订阅者
   void DestroySubscriber(CommonEvent_Subscriber* Subscriber) {
       OH_CommonEvent_DestroySubscriber(Subscriber);
       Subscriber = nullptr;
   }
   ```

5. 订阅事件。

   通过[OH_CommonEvent_Subscribe](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_subscribe)订阅事件。

   ```c++
   void Subscribe(CommonEvent_Subscriber* subscriber) {
       // 通过传入订阅者来订阅事件
       int32_t ret = OH_CommonEvent_Subscribe(subscriber);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_Subscribe ret <%{public}d>.", ret);
   }
   ```

6. （可选）当订阅的事件为有序公共事件时，可以选择进一步处理有序公共事件。

   根据订阅者设置的优先级等级，优先将公共事件发送给优先级较高的订阅者，等待其成功接收该公共事件之后再将事件发送给优先级较低的订阅者。如果有多个订阅者具有相同的优先级，则他们将随机接收到公共事件。

   > **注意：**
   >
   > 在订阅者收到公共事件之后，才能通过以下接口进一步处理有序公共事件。

   - 中止当前的有序公共事件。

     通过[OH_CommonEvent_AbortCommonEvent](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_abortcommonevent)与[OH_CommonEvent_FinishCommonEvent](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_finishcommonevent)配合使用，可以中止当前的有序公共事件，使该公共事件不再向下一个订阅者传递。

     ```c++
     void AbortCommonEvent(CommonEvent_Subscriber* subscriber) {
         // 判断是否为有序公共事件
         if(!OH_CommonEvent_IsOrderedCommonEvent(subscriber)) {
             OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "Not ordered common event.");
             return;
         }
         // 中止有序事件
         if(OH_CommonEvent_AbortCommonEvent(subscriber)) {
             if(OH_CommonEvent_FinishCommonEvent(subscriber)) {
                 // 获取当前有序公共事件是否处于中止状态
                 OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "Abort common event success, Get abort <%{public}d>.",   OH_CommonEvent_GetAbortCommonEvent(subscriber));
             }
         } else {
            OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "Abort common event failed.");
         }
     }
     ```

   - 取消当前有序公共事件的中止状态。

     通过[OH_CommonEvent_ClearAbortCommonEvent](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_clearabortcommonevent)与[OH_CommonEvent_FinishCommonEvent](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_finishcommonevent)配合使用，可以取消当前有序公共事件的中止状态，使该公共事件继续向下一个订阅者传递。

     ```c++
     void ClearAbortCommonEvent(CommonEvent_Subscriber* subscriber) {
         // 判断是否为有序公共事件
         if(!OH_CommonEvent_IsOrderedCommonEvent(subscriber)) {
             OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "Not ordered common event.");
             return;
         }
         // 中止有序事件
         if(!OH_CommonEvent_AbortCommonEvent(subscriber)) {
             OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "Abort common event failed.");
             return;
         }
         // 取消中止有序事件
         if(OH_CommonEvent_ClearAbortCommonEvent(subscriber)) {
             if(OH_CommonEvent_FinishCommonEvent(subscriber)) {
                 // 获取当前有序公共事件是否处于中止状态
                 OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "Clear abort common event success, Get abort <%{public}d>.",   OH_CommonEvent_GetAbortCommonEvent(subscriber));
             }
         } else {
            OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "Clear abort common event failed.");
         }
     }
     ```

   - 修改有序公共事件的内容。

     通过[OH_CommonEvent_SetCodeToSubscriber](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_setcodetosubscriber)与[OH_CommonEvent_SetDataToSubscriber](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_setdatatosubscriber)设置有序公共事件的代码和数据。

     ```c++
     void SetToSubscriber(CommonEvent_Subscriber* subscriber, const int32_t code, const char* data) {
         // 设置有序公共事件的代码
         if(!OH_CommonEvent_SetCodeToSubscriber(subscriber, code)) {
             OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "OH_CommonEvent_SetCodeToSubscriber failed.");
             return;
         }
         // 设置有序公共事件的数据
         size_t dataLength = strlen(data);
         if(!OH_CommonEvent_SetDataToSubscriber(subscriber, data, dataLength)) {
             OH_LOG_Print(LOG_APP, LOG_ERROR, 1, "CES_TEST", "OH_CommonEvent_SetDataToSubscriber failed.");
             return;
         }
     }
   
     void GetFromSubscriber(CommonEvent_Subscriber* subscriber) {
         // 获取有序公共事件的数据和代码
         const char* data = OH_CommonEvent_GetDataFromSubscriber(subscriber);
         int32_t code = OH_CommonEvent_GetCodeFromSubscriber(subscriber);
         OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "Subscriber data <%{public}s>, code <%{public}d>.", data, code);
     }
     ```
   

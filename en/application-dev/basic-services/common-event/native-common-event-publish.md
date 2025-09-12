# Publishing Common Events in C

<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

## When to Use

You can use the [OH_CommonEvent_Publish](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publish) and [OH_CommonEvent_PublishWithInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publishwithinfo) methods to publish a common event, which can carry data for subscribers to parse and process.

## Available APIs

For details about the APIs, see [oh_commonevent.h](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md).

| API                              | Description                                                            |
| ------------------------------------ | ---------------------------------------------------------------- |
|[struct CommonEvent_PublishInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#structs)|Defines the property object used for publishing a common event.|
|[CommonEvent_ErrCode OH_CommonEvent_Publish(const char* event)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publish)|Publish a common event.|
|[CommonEvent_ErrCode OH_CommonEvent_PublishWithInfo(const char* event, const CommonEvent_PublishInfo* info)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publishwithinfo)| Publishes a common event with specified properties.|
|[CommonEvent_PublishInfo* OH_CommonEvent_CreatePublishInfo(bool ordered)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createpublishinfo)|Creates an attribute object of a common event.|
|[void OH_CommonEvent_DestroyPublishInfo(CommonEvent_PublishInfo* info)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroypublishinfo)|Destroys an attribute object of a common event.|
|[CommonEvent_Parameters* OH_CommonEvent_CreateParameters()](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createparameters)|Creates an additional information object of a common event.|
|[void OH_CommonEvent_DestroyParameters(CommonEvent_Parameters* param)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroyparameters)|Destroys an additional information object of a common event.|

## How to Develop

1. Reference header files.

   ```c++
   #include <cstdint>
   #include <cstdio>
   #include <cwchar>
   #include <string.h>
   #include "hilog/log.h"
   #include "BasicServicesKit/oh_commonevent.h"
   ```

2. Add dynamic link libraries to the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohcommonevent.so
   )
   ```

3. (Optional) Create an attribute object of a common event.

   When publishing a common event that carries data, you need to create a property object of the common event using [OH_CommonEvent_CreatePublishInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createpublishinfo) and set the properties using the following APIs:

   ```c++
   // Create and add additional information of common event attributes.
   CommonEvent_Parameters* CreateParameters()
   {
       int32_t ret = -1;
       // Create the additional information of a common event.
       CommonEvent_Parameters* param = OH_CommonEvent_CreateParameters();
       
       // Set the additional information and key of the int type.
       ret = OH_CommonEvent_SetIntToParameters(param, "intKey", 10);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetIntToParameters ret <%{public}d>.", ret);

       // Set the additional information and key of the int array type.
       int intArray[] = {123, 234, 567};
       size_t arraySize = 3;
       ret = OH_CommonEvent_SetIntArrayToParameters(param, "intArrayKey", intArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetIntArrayToParameters ret <%{public}d>.", ret);
       
       // Set the additional information and key of the long type.
       ret = OH_CommonEvent_SetLongToParameters(param, "longKey", 2147483646);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetLongToParameters ret <%{public}d>.", ret);

       // Set the additional information and key of the long array type.
       long longArray[] = {2147483646, 555, 2147483645};
       ret = OH_CommonEvent_SetLongArrayToParameters(param, "longArrayKey", longArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetLongArrayToParameters ret <%{public}d>.", ret);
       
       // Set the additional information and key of the double type.
       ret = OH_CommonEvent_SetDoubleToParameters(param, "doubleKey", 11.22);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetDoubleToParameters ret <%{public}d>.", ret);

       // Set the additional information and key of the double array type.
       double doubleArray[] = {11.22, 33.44, 55.66};
       ret = OH_CommonEvent_SetDoubleArrayToParameters(param, "doubleArrayKey", doubleArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetDoubleArrayToParameters ret <%{public}d>.", ret);
       
       // Set the additional information and key of the Boolean type.
       ret = OH_CommonEvent_SetBoolToParameters(param, "boolKey", true);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetBoolToParameters ret <%{public}d>.", ret);

       // Set the additional information and key of the Boolean array type.
       bool boolArray[] = {true, false, true};
       ret = OH_CommonEvent_SetBoolArrayToParameters(param, "boolArrayKey", boolArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetBoolArrayToParameters ret <%{public}d>.", ret);
       
       // Set the additional information and key of the char type.
       ret = OH_CommonEvent_SetCharToParameters(param, "charKey", 'A');
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetCharToParameters ret <%{public}d>.", ret);

       // Set the additional information and key of the char array type.
       const char* value= "Char Array";
       size_t valueLength = strlen(value);
       ret = OH_CommonEvent_SetCharArrayToParameters(param, "charArrayKey", value, valueLength);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetCharArrayToParameters ret <%{public}d>.", ret);
       return param;
   }
   
   // Set common event attributes.
   void SetPublishInfo(const char* bundleName, const char* permissions[], int32_t num, const int32_t code, const char* data)
   {
       int32_t ret = -1;
       // Create publishInfo. Setting the value to true indicates an ordered common event; false indicates an unordered common event.
       CommonEvent_PublishInfo* info = OH_CommonEvent_CreatePublishInfo(true);

       // Set the bundle name of a common event.
       ret = OH_CommonEvent_SetPublishInfoBundleName(info, bundleName);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoBundleName ret <%{public}d>.", ret);

       // Set the common event permission. The parameters consist of the permission array and the number of permissions.
       ret = OH_CommonEvent_SetPublishInfoPermissions(info, permissions, num);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoPermissions ret <%{public}d>.", ret);

       // Set the result code of a common event.
       ret = OH_CommonEvent_SetPublishInfoCode(info, code);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoCode ret <%{public}d>.", ret);

       // Set the result data of a common event.
       size_t dataLength = strlen(data);
       ret = OH_CommonEvent_SetPublishInfoData(info, data, dataLength);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoData ret <%{public}d>.", ret);

       // Set the additional information of a common event.
       CommonEvent_Parameters* param = CreateParameters();
       ret = OH_CommonEvent_SetPublishInfoParameters(info, param);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoParameters ret <%{public}d>.", ret);
   }
   ```

4. Publish a common event.

   - Use [OH_CommonEvent_Publish](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publish) to publish common events that do not carry information.

     > **NOTE**
     >
     > Common events that do not carry information can be published only as unordered common events.

     ```c++
     void Publish(const char* event)
     {
         int32_t ret = OH_CommonEvent_Publish(event);
         OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_Publish ret <%{public}d>.", ret);
     }
     ```

   - Use [OH_CommonEvent_PublishWithInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publishwithinfo) to publish common events that carry information.

     ```c++
     void PublishWithInfo(const char* event, CommonEvent_PublishInfo* info)
     {
         // Create a common event with the attribute object.
         int32_t ret = OH_CommonEvent_PublishWithInfo(event, info);
         OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_PublishWithInfo ret <%{public}d>.", ret);
     }
     ```

5. Destroy a common event object.

   If the created common event object is no longer used to publish a common event, destroy the **CommonEvent_Parameters** object by using [OH_CommonEvent_DestroyParameters](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroyparameters), and then destroy the common event object by using [OH_CommonEvent_DestroyPublishInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroypublishinfo).
   
   ```c++
   void DestroyPublishInfo(CommonEvent_Parameters* param, CommonEvent_PublishInfo* info)
   {
       // First, destroy Parameters.
       OH_CommonEvent_DestroyParameters(param);
       param = nullptr;
       // Second, destroy PublishInfo.
       OH_CommonEvent_DestroyPublishInfo(info);
       info = nullptr;
   }
   ```

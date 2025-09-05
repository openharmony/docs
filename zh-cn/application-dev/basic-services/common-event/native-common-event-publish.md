# 发布公共事件（C/C++）

<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

## 场景介绍

当需要发布某个公共事件时，可以通过[OH_CommonEvent_Publish](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publish)和[OH_CommonEvent_PublishWithInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publishwithinfo)方法发布事件。发布的公共事件可以携带数据，供订阅者解析并进行下一步处理。

## 接口说明

详细的API说明请参考[CommonEvent API参考](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md)。

| 接口名                               | 描述                                                             |
| ------------------------------------ | ---------------------------------------------------------------- |
|[struct CommonEvent_PublishInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#结构体)|发布公共事件时使用的公共事件属性对象。|
|[CommonEvent_ErrCode OH_CommonEvent_Publish(const char* event)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publish)|发布公共事件。|
|[CommonEvent_ErrCode OH_CommonEvent_PublishWithInfo(const char* event, const CommonEvent_PublishInfo* info)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publishwithinfo)| 发布带有指定属性的公共事件。 |
|[CommonEvent_PublishInfo* OH_CommonEvent_CreatePublishInfo(bool ordered)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createpublishinfo)|创建公共事件属性对象。|
|[void OH_CommonEvent_DestroyPublishInfo(CommonEvent_PublishInfo* info)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroypublishinfo)|销毁公共事件属性对象。|
|[CommonEvent_Parameters* OH_CommonEvent_CreateParameters()](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createparameters)|创建公共事件附加信息对象。|
|[void OH_CommonEvent_DestroyParameters(CommonEvent_Parameters* param)](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroyparameters)|销毁公共事件附加信息对象。|

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

3. （可选）创建公共事件属性对象。

   发布携带数据的公共事件时，需要通过[OH_CommonEvent_CreatePublishInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_createpublishinfo)创建公共事件属性对象，并通过以下接口设置公共事件属性。

   ```c++
   // 创建并添加公共事件属性附加信息
   CommonEvent_Parameters* CreateParameters()
   {
       int32_t ret = -1;
       // 创建公共事件附加信息
       CommonEvent_Parameters* param = OH_CommonEvent_CreateParameters();
       
       // 设置int类型附加信息和key
       ret = OH_CommonEvent_SetIntToParameters(param, "intKey", 10);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetIntToParameters ret <%{public}d>.", ret);

       // 设置int数组类型附加信息和key
       int intArray[] = {123, 234, 567};
       size_t arraySize = 3;
       ret = OH_CommonEvent_SetIntArrayToParameters(param, "intArrayKey", intArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetIntArrayToParameters ret <%{public}d>.", ret);
       
       // 设置long类型附加信息和key
       ret = OH_CommonEvent_SetLongToParameters(param, "longKey", 2147483646);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetLongToParameters ret <%{public}d>.", ret);

       // 设置long数组类型附加信息和key
       long longArray[] = {2147483646, 555, 2147483645};
       ret = OH_CommonEvent_SetLongArrayToParameters(param, "longArrayKey", longArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetLongArrayToParameters ret <%{public}d>.", ret);
       
       // 设置double类型附加信息和key
       ret = OH_CommonEvent_SetDoubleToParameters(param, "doubleKey", 11.22);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetDoubleToParameters ret <%{public}d>.", ret);

       // 设置double数组类型附加信息和key
       double doubleArray[] = {11.22, 33.44, 55.66};
       ret = OH_CommonEvent_SetDoubleArrayToParameters(param, "doubleArrayKey", doubleArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetDoubleArrayToParameters ret <%{public}d>.", ret);
       
       // 设置boolean类型附加信息和key
       ret = OH_CommonEvent_SetBoolToParameters(param, "boolKey", true);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetBoolToParameters ret <%{public}d>.", ret);

       // 设置boolean数组类型附加信息和key
       bool boolArray[] = {true, false, true};
       ret = OH_CommonEvent_SetBoolArrayToParameters(param, "boolArrayKey", boolArray, arraySize);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetBoolArrayToParameters ret <%{public}d>.", ret);
       
       // 设置char类型附加信息和key
       ret = OH_CommonEvent_SetCharToParameters(param, "charKey", 'A');
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetCharToParameters ret <%{public}d>.", ret);

       // 设置char数组类型附加信息和key
       const char* value= "Char Array";
       size_t valueLength = strlen(value);
       ret = OH_CommonEvent_SetCharArrayToParameters(param, "charArrayKey", value, valueLength);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetCharArrayToParameters ret <%{public}d>.", ret);
       return param;
   }
   
   // 设置公共事件属性
   void SetPublishInfo(const char* bundleName, const char* permissions[], int32_t num, const int32_t code, const char* data)
   {
       int32_t ret = -1;
       // 创建publishInfo，设置是否为有序公共事件，取值为true，表示有序公共事件；取值为false，表示无序公共事件
       CommonEvent_PublishInfo* info = OH_CommonEvent_CreatePublishInfo(true);

       // 设置公共事件包名称
       ret = OH_CommonEvent_SetPublishInfoBundleName(info, bundleName);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoBundleName ret <%{public}d>.", ret);

       // 设置公共事件权限，参数为权限数组和权限的数量
       ret = OH_CommonEvent_SetPublishInfoPermissions(info, permissions, num);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoPermissions ret <%{public}d>.", ret);

       // 设置公共事件结果码
       ret = OH_CommonEvent_SetPublishInfoCode(info, code);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoCode ret <%{public}d>.", ret);

       // 设置公共事件结果数据
       size_t dataLength = strlen(data);
       ret = OH_CommonEvent_SetPublishInfoData(info, data, dataLength);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoData ret <%{public}d>.", ret);

       // 设置公共事件附加信息
       CommonEvent_Parameters* param = CreateParameters();
       ret = OH_CommonEvent_SetPublishInfoParameters(info, param);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_SetPublishInfoParameters ret <%{public}d>.", ret);
   }
   ```

4. 发布公共事件。

   - 通过[OH_CommonEvent_Publish](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publish)发布不携带信息的公共事件。

     > **说明：**
     >
     > 不携带信息的公共事件，只能发布为无序公共事件。

     ```c++
     void Publish(const char* event)
     {
         int32_t ret = OH_CommonEvent_Publish(event);
         OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_Publish ret <%{public}d>.", ret);
     }
     ```

   - 通过[OH_CommonEvent_PublishWithInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_publishwithinfo)发布携带信息的公共事件。

     ```c++
     void PublishWithInfo(const char* event, CommonEvent_PublishInfo* info)
     {
         // 创建时带入公共事件属性对象
         int32_t ret = OH_CommonEvent_PublishWithInfo(event, info);
         OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_PublishWithInfo ret <%{public}d>.", ret);
     }
     ```

5. 销毁公共事件对象。

   如果后续无需使用已创建的公共事件对象来发布公共事件，需要先通过[OH_CommonEvent_DestroyParameters](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroyparameters)销毁`CommonEvent_Parameters`对象，然后再通过[OH_CommonEvent_DestroyPublishInfo](../../reference/apis-basic-services-kit/capi-oh-commonevent-h.md#oh_commonevent_destroypublishinfo)销毁公共事件对象。
   
   ```c++
   void DestroyPublishInfo(CommonEvent_Parameters* param, CommonEvent_PublishInfo* info)
   {
       // 先销毁Parameters
       OH_CommonEvent_DestroyParameters(param);
       param = nullptr;
       // 销毁PublishInfo
       OH_CommonEvent_DestroyPublishInfo(info);
       info = nullptr;
   }
   ```
# 使用剪贴板进行延迟复制粘贴
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @zhusiyuan2-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->

## 场景介绍

[@ohos.pasteboard](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。

反复执行复制操作时，剪贴板缓存中会存储多余数据从而导致内存增加，为了优化内存以及后续支持指定数据类型粘贴，剪贴板提供了延迟复制粘贴的功能。

用户复制使用延迟复制技术的应用内的数据时，该条真实数据不会立即写入剪贴板服务的缓存中，而是等需要粘贴时，再从应用获取数据。

## 约束限制

- 剪贴板内容包含剪贴板系统服务元数据和应用设置的数据，总大小上限默认为128MB，PC/2in1设备可通过系统配置修改上限，有效范围为1MB~2GB。

- NDK接口仅支持Record级别的延迟复制粘贴。

- 当复制的数据量较小且准备数据所需时间不会影响用户体验时，不建议应用程序使用延迟复制功能，推荐将数据直接写入剪贴板。

## 使用基于Record级别的延迟复制粘贴

本方案可以在粘贴前查询数据type信息，应用可以据此决定是否向剪贴板请求数据，因此建议使用本方案实现延迟复制功能。

从API version 21开始，应用退出不仅可以调用延迟复制接口[OH_Pasteboard_SetData](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_setdata)主动提交所有复制数据，还可以使用同步延迟数据接口[OH_Pasteboard_SyncDelayedDataAsync](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_syncdelayeddataasync)通知剪贴板获取全量数据。

1. 当应用使用延迟复制功能复制时，仅将应用支持的数据类型写入剪贴板。应用应在退出时，重新调用[OH_Pasteboard_SetData](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_setdata)接口主动提交所有复制数据或调用[OH_Pasteboard_SyncDelayedDataAsync](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_syncdelayeddataasync)接口通知剪贴板获取全量数据，等待数据同步完成再继续退出，否则可能导致其他应用粘贴获取不到数据。

2. 调用[OH_Pasteboard_SyncDelayedDataAsync](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_syncdelayeddataasync)接口会延长退出过程，建议应用在复制数据时直接设置数据到剪贴板，而不是调用延迟复制接口[OH_UdmfRecordProvider_SetData](../../reference/apis-arkdata/capi-udmf-h.md#oh_udmfrecordprovider_setdata)和同步延迟数据接口[OH_Pasteboard_SyncDelayedDataAsync](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_syncdelayeddataasync)。

3. 延迟复制场景应用异常退出时，无法触发应用退出延迟数据同步流程，会导致其他应用粘贴时获取不到数据。

### 接口说明

详细接口见[Pasteboard文档](../../reference/apis-basic-services-kit/capi-pasteboard.md)和[UDMF接口文档](../../reference/apis-arkdata/capi-udmf.md)。

| 名称 | 说明                                                                   |
| -------- |----------------------------------------------------------------------|
| OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()        | 创建一个指向统一数据提供者的指针。                          |
| int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize) | 设置统一数据提供者的回调函数。                              |
| int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider) | 将统一数据提供者配置到OH_UdmfRecord中。                     |
| int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data) | 向剪贴板中写入数据。                                    |
| OH_UdmfData * OH_Pasteboard_GetData(OH_Pasteboard* pasteboard, int* status) | 获取剪贴板中的数据。 |
| OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count) | 获取OH_UdmfData中全部的数据记录。                           |
| void OH_Pasteboard_SyncDelayedDataAsync(OH_Pasteboard* pasteboard, void (*callback)(int errorCode)) | 通知剪贴板从应用同步所有延迟数据。 当应用使用延迟复制功能复制时，仅将应用支持的数据类型写入剪贴板。应用应在退出时，重新调用[OH_Pasteboard_SetData](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_setdata)接口主动提交所有复制数据或调用[OH_Pasteboard_SyncDelayedDataAsync](../../reference/apis-basic-services-kit/capi-oh-pasteboard-h.md#oh_pasteboard_syncdelayeddataasync)接口通知剪贴板获取全量数据，等待数据同步完成再继续退出，否则可能导致其他应用粘贴获取不到数据。|

### 开发步骤

 下面以纯文本类型和HTML类型数据为例，说明如何向剪贴板服务设置延迟复制数据。

 为了代码可读性，代码中省略了各个步骤操作结果的校验，实际开发中需要确认每次调用的成功。

1. 引用头文件。
   
   <!-- @[pasteboard_timelapse_Record1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_NDK_sample/entry/src/main/cpp/napi_init.cpp) -->    
   
   ``` C++
   #include <cstring>
   #include <hilog/log.h>
   #include <database/pasteboard/oh_pasteboard.h>
   #include <database/udmf/udmf.h>
   #include <database/udmf/uds.h>
   #include <database/udmf/udmf_meta.h>
   #include <accesstoken/ability_access_control.h>
   ```


2. 定义`OH_UdmfRecordProvider`的数据提供函数和实例注销回调函数。

   <!-- @[pasteboard_timelapse_Record2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_NDK_sample/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   // 1. 获取数据时触发的提供剪贴板数据的回调函数。
   void* GetDataCallback(void* context, const char* type)
   {
       // 纯文本类型
       if (memcmp(type, UDMF_META_PLAIN_TEXT, sizeof(UDMF_META_PLAIN_TEXT) - 1) == 0) {
           // 创建纯文本类型的Uds对象。
           OH_UdsPlainText* udsText = OH_UdsPlainText_Create();
           // 设置纯文本内容。
           OH_UdsPlainText_SetContent(udsText, "hello world");
           return udsText;
       } else if (strcmp(type, UDMF_META_HTML) == 0) {
           // 创建HTML类型的Uds对象。
           OH_UdsHtml* udsHtml = OH_UdsHtml_Create();
           // 设置HTML内容。
           OH_UdsHtml_SetContent(udsHtml, "<div>hello world</div>");
           return udsHtml;
       }
       return nullptr;
   }
   // 2. OH_UdmfRecordProvider销毁时触发的回调函数。
   void ProviderFinalizeCallback(void* context)
   {
       OH_LOG_INFO(LOG_APP, "OH_UdmfRecordProvider finalize.");
   }
   ```


3. 定义`OH_Pasteboard_SyncDelayedDataAsync`的回调函数。

   <!-- @[pasteboard_timelapse_Record3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_NDK_sample/entry/src/main/cpp/napi_init.cpp) -->
   
   ``` C++
   // 3. 定义应用退出时调用延迟同步接口触发的回调函数。
   void SyncCallback(int errorCode)
   {
       // 继续退出
   }
   ```


4. 在剪贴板中准备延迟复制数据。此步骤完成后纯文本类型数据与HTML类型数据并未真正写入剪贴板服务，只有当数据使用者从`OH_UdmfRecord`中获取`OH_UdsPlainText`或`OH_UdsHtml`时，才会触发上文定义的`GetDataCallback`数据提供函数，从中得到数据。
   
   <!-- @[pasteboard_timelapse_Record4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_NDK_sample/entry/src/main/cpp/napi_init.cpp) -->    
   
   ``` C++
   OH_Pasteboard* CreateAndSetPasteboardData()
   {
       // 4. 创建OH_UdmfRecord对象。
       OH_UdmfRecord* record = OH_UdmfRecord_Create();
       // 5. 创建OH_UdmfRecordProvider对象，并设置用于提供延迟数据、析构的两个回调函数。
       OH_UdmfRecordProvider* provider = OH_UdmfRecordProvider_Create();
       OH_UdmfRecordProvider_SetData(provider, (void *)record, GetDataCallback, ProviderFinalizeCallback);
       // 6. 将provider绑定到record，并设置支持的数据类型。
       #define TYPE_COUNT 2
       const char* types[TYPE_COUNT] = {UDMF_META_PLAIN_TEXT, UDMF_META_HTML};
       OH_UdmfRecord_SetProvider(record, types, TYPE_COUNT, provider);
       // 7. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
       OH_UdmfData* setData = OH_UdmfData_Create();
       if (setData != nullptr) {
           OH_UdmfData_AddRecord(setData, record);
       }
       // 8. 创建OH_Pasteboard对象，将数据写入剪贴板中。
       OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
       if (setData != nullptr) {
           OH_Pasteboard_SetData(pasteboard, setData);
       }
       OH_UdmfRecordProvider_Destroy(provider);
       OH_UdmfRecord_Destroy(record);
       OH_UdmfData_Destroy(setData);
       return pasteboard;
   }
   ```


5. 从剪贴板获取延迟复制数据。
   
   <!-- @[pasteboard_timelapse_Record5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_NDK_sample/entry/src/main/cpp/napi_init.cpp) -->    
   
   ``` C++
   void ProcessRecordType(OH_UdmfRecord* record, const char* recordType)
   {
       OH_UdsPlainText* udsText = nullptr;
       OH_UdsHtml* udsHtml = nullptr;
       if (strcmp(recordType, UDMF_META_PLAIN_TEXT) == 0) {
           // 创建纯文本类型的Uds对象
           udsText = OH_UdsPlainText_Create();
           if (udsText != nullptr) {
               // 从record中获取纯文本类型的Uds对象
               OH_UdmfRecord_GetPlainText(record, udsText);
               // 从Uds对象中获取内容
               const char* content = OH_UdsPlainText_GetContent(udsText);
           } else if (strcmp(recordType, UDMF_META_HTML) == 0) {
               // 创建HTML类型的Uds对象
               udsHtml = OH_UdsHtml_Create();
               if (udsHtml != nullptr) {
                   // 从record中获取HTML类型的Uds对象
                   OH_UdmfRecord_GetHtml(record, udsHtml);
                   // 从Uds对象中获取内容
                   const char* content = OH_UdsHtml_GetContent(udsHtml);
               }
           }
       }
   }
   void ProcessRecord(OH_UdmfRecord* record)
   {
       // 13. 查询OH_UdmfRecord中的数据类型。
       unsigned typeCount = 0;
       char** recordTypes = OH_UdmfRecord_GetTypes(record, &typeCount);
       // 14. 遍历数据类型。
       for (unsigned int typeIndex = 0; typeIndex < typeCount; ++typeIndex) {
           const char* recordType = recordTypes[typeIndex];
           ProcessRecordType(record, recordType);
       }
   }
   
   static napi_value NAPI_Pasteboard_time(napi_env env, napi_callback_info info)
   {
       OH_Pasteboard* pasteboard = CreateAndSetPasteboardData();
       // 9. 记录当前的剪贴板数据变化次数。
       uint32_t changeCount = OH_Pasteboard_GetChangeCount(pasteboard);
       // 10. 从剪贴板获取OH_UdmfData。
       int status = -1;
       bool hasPermission = OH_AT_CheckSelfPermission("ohos.permission.READ_PASTEBOARD");
       if (!hasPermission) {
           OH_LOG_ERROR(LOG_APP, "No Permission READ_PASTEBOARD");
       };
       OH_UdmfData* getData = OH_Pasteboard_GetData(pasteboard, &status);
       if (getData == nullptr) {
           // 处理错误情况，清理资源
           OH_LOG_ERROR(LOG_APP, "Failed to get data from pasteboard, status: %d\n", status);
       }
       // 11. 获取OH_UdmfData中的所有OH_UdmfRecord。
       unsigned int recordCount = 0;
       OH_UdmfRecord** getRecords = OH_UdmfData_GetRecords(getData, &recordCount);
       OH_UdsPlainText* udsText = nullptr;
       OH_UdsHtml* udsHtml = nullptr;
       // 12. 遍历OH_UdmfRecord。
       for (unsigned int recordIndex = 0; recordIndex < recordCount; ++recordIndex) {
           OH_UdmfRecord* record = getRecords[recordIndex];
           ProcessRecord(record);
       }
   ```


6. 应用退出时，如果剪贴板内的数据没有变化，则通知剪贴板获取全量数据，等待回调完成再继续退出，否则可能导致其他应用粘贴获取不到数据。

   <!-- @[pasteboard_timelapse_Record6](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_NDK_sample/entry/src/main/cpp/napi_init.cpp) -->    
   
   ``` C++
   // 15. 查询剪贴板内的数据是否变化。
   uint32_t newChangeCount = OH_Pasteboard_GetChangeCount(pasteboard);
   if (newChangeCount == changeCount) {
       // 16. 通知剪贴板获取全量数据。
       OH_Pasteboard_SyncDelayedDataAsync(pasteboard, SyncCallback);
       // 需要等待SyncCallback回调完成再继续退出
   } else {
       // 继续退出
       OH_LOG_INFO(LOG_APP, "No newChangeCount in pasteboard.");
   }
   ```

7. 使用完毕后需要及时释放相关对象的内存。
   
   <!-- @[pasteboard_timelapse_Record7](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/pasteboard/pasteboard_NDK_sample/entry/src/main/cpp/napi_init.cpp) -->    
   
   ``` C++
       OH_UdsPlainText_Destroy(udsText);
       OH_UdsHtml_Destroy(udsHtml);
       OH_UdmfData_Destroy(getData);
       OH_Pasteboard_Destroy(pasteboard);
   }
   ```

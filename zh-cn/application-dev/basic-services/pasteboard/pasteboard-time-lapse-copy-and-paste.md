# 使用剪贴板进行延迟复制粘贴

## 场景介绍

[剪贴板服务](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。

反复执行复制操作时，剪贴板缓存中会存储多余数据从而导致内存增加，为了优化内存以及后续支持指定数据类型粘贴，剪贴板提供了延迟复制粘贴的功能。

用户复制使用延迟粘贴技术的应用内的数据时，该条真实数据不会立即写入剪贴板服务的缓存中，而是等需要粘贴时，再从应用获取数据。

## 约束限制

- 剪贴板内容大小&lt;128MB时支持使用。

## 使用基于Record级别的延迟复制粘贴（推荐）

本方案可以在粘贴前查询数据type信息，应用可以据此决定是否向剪贴板请求数据，因此建议使用本方案实现延迟复制功能。

### 接口说明

详细接口见[Pasteboard文档](../../reference/apis-basic-services-kit/_pasteboard.md)和[UDMF接口文档](../../reference/apis-arkdata/_u_d_m_f.md)。

| 名称 | 说明                                                                   |
| -------- |----------------------------------------------------------------------|
| OH_UdmfRecordProvider* OH_UdmfRecordProvider_Create()        | 创建一个指向统一数据提供者的指针。                          |
| int OH_UdmfRecordProvider_SetData(OH_UdmfRecordProvider* provider, void* context, const OH_UdmfRecordProvider_GetData callback, const UdmfData_Finalize finalize) | 设置统一数据提供者的回调函数。                              |
| int OH_UdmfRecord_SetProvider(OH_UdmfRecord* pThis, const char* const* types, unsigned int count, OH_UdmfRecordProvider* provider) | 将统一数据提供者配置到OH_UdmfRecord中。                     |
| int OH_Pasteboard_SetData(OH_Pasteboard* pasteboard, OH_UdmfData* data) | 向剪贴板中写入数据。                                    |
| OH_UdmfData * OH_Pasteboard_GetData (OH_Pasteboard* pasteboard, int* status) | 获取剪贴板中的数据。 |
| OH_UdmfRecord** OH_UdmfData_GetRecords(OH_UdmfData* pThis, unsigned int* count) | 获取OH_UdmfData中全部的数据记录。                           |

### 开发步骤

 下面以超链接hyperlink类型数据场景为例，说明如何延迟发送数据。

 为了代码可读性，代码中省略了各个步骤操作结果的校验，实际开发中需要确认每次调用的成功。

1. 引用头文件。
   
   ```c
   #include <database/pasteboard/oh_pasteboard.h>
   #include <database/udmf/udmf.h>
   #include <database/udmf/udmf_meta.h>
   #include <database/udmf/uds.h>
   ```

2. 定义OH_UdmfRecordProvider的数据提供函数和实例注销回调函数。
   
   ```c
   // 1. 获取数据时触发的提供剪贴板数据的回调函数。
   void* GetDataCallback(void* context, const char* type) {
      if (strcmp(type, UDMF_META_HYPERLINK) == 0) {
          // 2. 创建超链接hyperlink数据的UDS数据结构。
          OH_UdsHyperlink* hyperlink = OH_UdsHyperlink_Create();
          // 3. 设置hyperlink中的URL和描述信息。
          OH_UdsHyperlink_SetUrl(hyperlink, "www.demo.com");
          OH_UdsHyperlink_SetDescription(hyperlink, "This is www.demo.com description.");
          return hyperlink;
      }
      return nullptr;
   }
   // 4. OH_UdmfRecordProvider销毁时触发的回调函数。
   void ProviderFinalizeCallback(void* context) { printf("OH_UdmfRecordProvider finalize."); }
   ```

3. 在剪贴板中准备延迟复制数据。需要注意，此步骤完成后超链接类型数据并未真正写入数据库，只有当数据使用者从OH_UdmfRecord中获取OH_UdsHyperlink时，才会触发上文定义的`GetDataCallback`数据提供函数，从中得到数据。
   
   ```c
   // 5. 创建一个OH_UdmfRecord对象，并将OH_UdmfRecordProvider配置到其中。
   OH_UdmfRecord* record = OH_UdmfRecord_Create();

   // 6. 创建一个统一数据提供者，并配置它提供数据、销毁时的两个回调函数。
   OH_UdmfRecordProvider* provider = OH_UdmfRecordProvider_Create();
   OH_UdmfRecordProvider_SetData(provider, (void*)record, GetDataCallback, ProviderFinalizeCallback);
   const char* types[1] = { UDMF_META_HYPERLINK };
   OH_UdmfRecord_SetProvider(record, types, 1, provider);

   // 7. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
   OH_UdmfData* setData = OH_UdmfData_Create();
   OH_UdmfData_AddRecord(setData, record);

   // 8. 创建OH_Pasteboard对象，将数据写入剪贴板中。
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   OH_Pasteboard_SetData(pasteboard, setData);
   ```

4. 在剪贴板中获取延迟复制数据。
   
   ```c
   // 9. 剪贴板中获取延迟复制数据
   int status = -1;
   OH_UdmfData* getData = OH_Pasteboard_GetData(pasteboard, &status);

   // 10. 获取数据中records
   unsigned int count = 0;
   OH_UdmfRecord** getRecords = OH_UdmfData_GetRecords(getData, &count);

   // 11. 创建OH_UdsHyperlink对象，并从records中获取超链接类型数据
   OH_UdsHyperlink* getHyperlink = OH_UdsHyperlink_Create();
   OH_UdmfRecord_GetHyperlink(getRecords[0], getHyperlink);

   // 12. 获取超链接类型数据中的URL和描述信息。
   const char* getUrl = OH_UdsHyperlink_GetUrl(getHyperlink);
   const char* getDescription = OH_UdsHyperlink_GetDescription(getHyperlink);
   ```

5. 使用完毕后删除相关对象。
   
   ```c
   OH_UdsHyperlink_Destroy(getHyperlink);
   OH_UdmfRecordProvider_Destroy(provider);
   OH_UdmfRecord_Destroy(record);
   OH_UdmfData_Destroy(setData);
   OH_UdmfData_Destroy(getData);
   OH_Pasteboard_Destroy(pasteboard);
   ```


## 使用基于PasteData级别的延迟复制粘贴

本方案不支持粘贴前对数据type的查询。

### 接口说明

| 名称 | 说明                                                                   |
| -------- |----------------------------------------------------------------------|
| setUnifiedData(data: udc.UnifiedData): Promise\<void> | 将统一数据类型的数据写入系统剪贴板，在使用延迟复制粘贴功能时，不可与getUnifiedDataSync同线程调用。|
| setUnifiedDataSync(data: udc.UnifiedData): void | 将统一数据类型的数据写入系统剪贴板，此接口为同步接口，在使用延迟复制粘贴功能时，不可与getUnifiedDataSync同线程调用。|
| getUnifiedData(): Promise\<udc.UnifiedData> | 从系统剪贴板中读取统一数据类型的数据。|
| getUnifiedDataSync(): udc.UnifiedData | 从系统剪贴板中读取统一数据类型的数据，此接口为同步接口，在使用延迟复制粘贴功能时，不可与setUnifiedData和setUnifiedDataSync同线程调用。|
| setAppShareOptions(shareOptions: ShareOption): void | 应用设置本应用剪贴板数据的可粘贴范围。|
| removeAppShareOptions(): void | 应用删除本应用设置的剪贴板数据可粘贴范围配置。|

### 开发步骤

1. 导入pasteboard,unifiedDataChannel和uniformTypeDescriptor模块。
   
   ```ts\
   import {unifiedDataChannel, uniformTypeDescriptor} from '@kit.ArkData';
   import {BusinessError, pasteboard} from '@kit.BasicServicesKit'
   ```

2. 构造一条PlainText数据,并书写获取延时数据的函数。

   ```ts
   let plainTextData = new unifiedDataChannel.UnifiedData();
   let GetDelayPlainText = ((dataType:string) => {
     let plainText = new unifiedDataChannel.PlainText();
     plainText.details = {
       Key: 'delayPlaintext',
       Value: 'delayPlaintext',
     };
     plainText.textContent = 'delayTextContent';
     plainText.abstract = 'delayTextContent';
     plainTextData.addRecord(plainText);
     return plainTextData;
   });
   ``` 

3. 向系统剪贴板中存入一条PlainText数据。

   ```ts
   let SetDelayPlainText = (() => {
     plainTextData.properties.shareOptions = unifiedDataChannel.ShareOptions.CROSS_APP;
     // 跨应用使用时设置为CROSS_APP，本应用内使用时设置为IN_APP
     plainTextData.properties.getDelayData = GetDelayPlainText;
     pasteboard.getSystemPasteboard().setUnifiedData(plainTextData).then(()=>{
       // 存入成功，处理正常场景
     }).catch((error: BusinessError) => {
       // 处理异常场景
     });
   })
   ```

4. 从系统剪贴板中读取这条text数据。

   ```ts
   let GetPlainTextUnifiedData = (() => {
     pasteboard.getSystemPasteboard().getUnifiedData().then((data) => {
       let outputData = data;
       let records = outputData.getRecords();
       if (records[0].getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
         let record = records[0] as unifiedDataChannel.PlainText;
         console.log('GetPlainText success, type:' + records[0].getType + ', details:' +
         JSON.stringify(record.details) + ', textContent:' + record.textContent + ', abstract:' + record.abstract);
       } else {
         console.log('Get Plain Text Data No Success, Type is: ' + records[0].getType());
       }
     }).catch((error: BusinessError) => {
       //处理异常场景
     })
   })
   ```
   
5. 应用设置本应用剪贴板数据的可粘贴范围。

   ```ts
   let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
   try {
       systemPasteboard.setAppShareOptions(pasteboard.ShareOption.INAPP);
       console.info('Set app share options success.');
   } catch (err) {
       let error: BusinessError = err as BusinessError;
       //处理异常场景
   }
   ```
   
6. 应用删除本应用设置的剪贴板数据可粘贴范围配置。

   ```ts
   let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
   try {
	   systemPasteboard.removeAppShareOptions();
	   console.info('Remove app share options success.');
   } catch (err) {
	   let error: BusinessError = err as BusinessError;
       //处理异常场景
   }
   ```
# 使用剪贴板进行延迟复制粘贴

## 场景介绍

[剪贴板服务](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。

反复执行复制操作时，剪贴板缓存中会存储多余数据从而导致内存增加，为了优化内存以及后续支持指定数据类型粘贴，剪贴板提供了延迟复制粘贴的功能。

用户复制使用延迟复制技术的应用内的数据时，该条真实数据不会立即写入剪贴板服务的缓存中，而是等需要粘贴时，再从应用获取数据。

## 约束限制

- 剪贴板内容大小&lt;128MB时支持使用。

- NDK接口仅支持Record级别的延迟复制粘贴。

- ArkTS接口仅支持PasteData级别的延迟复制粘贴。

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

 下面以纯文本类型和HTML类型数据为例，说明如何向剪贴板服务设置延迟复制数据。

 为了代码可读性，代码中省略了各个步骤操作结果的校验，实际开发中需要确认每次调用的成功。

1. 引用头文件。
   
   ```c
   #include <database/pasteboard/oh_pasteboard.h>
   #include <database/udmf/udmf.h>
   #include <database/udmf/udmf_meta.h>
   #include <database/udmf/uds.h>
   ```

2. 定义`OH_UdmfRecordProvider`的数据提供函数和实例注销回调函数。
   
   ```c
   // 1. 获取数据时触发的提供剪贴板数据的回调函数。
   void* GetDataCallback(void* context, const char* type) {
       // 纯文本类型
       if (strcmp(type, UDMF_META_PLAIN_TEXT) == 0) {
           // 创建纯文本类型的Uds对象。
           OH_UdsPlainText* udsText = OH_UdsPlainText_Create();
           // 设置纯文本内容。
           OH_UdsPlainText_SetContent(udsText, "hello world");
           return udsText;
       }
       // HTML类型
       else if (strcmp(type, UDMF_META_HTML) == 0) {
           // 创建HTML类型的Uds对象。
           OH_UdsHtml* udsHtml = OH_UdsHtml_Create();
           // 设置HTML内容。
           OH_UdsHtml_SetContent(udsHtml, "<div>hello world</div>");
           return udsHtml;
       }
       return nullptr;
   }
   // 2. OH_UdmfRecordProvider销毁时触发的回调函数。
   void ProviderFinalizeCallback(void* context) {
       printf("OH_UdmfRecordProvider finalize.");
   }
   ```

3. 在剪贴板中准备延迟复制数据。需要注意，此步骤完成后纯文本类型数据与HTML类型数据并未真正写入剪贴板服务，只有当数据使用者从`OH_UdmfRecord`中获取`OH_UdsPlainText`或`OH_UdsHtml`时，才会触发上文定义的`GetDataCallback`数据提供函数，从中得到数据。
   
   ```c
   // 3. 创建OH_UdmfRecord对象。
   OH_UdmfRecord* record = OH_UdmfRecord_Create();

   // 4. 创建OH_UdmfRecordProvider对象，并设置用于提供延迟数据、析构的两个回调函数。
   OH_UdmfRecordProvider* provider = OH_UdmfRecordProvider_Create();
   OH_UdmfRecordProvider_SetData(provider, (void*)record, GetDataCallback, ProviderFinalizeCallback);

   // 5. 将provider绑定到record，并设置支持的数据类型。
   const char* types[2] = { UDMF_META_PLAIN_TEXT, UDMF_META_HTML };
   OH_UdmfRecord_SetProvider(record, types, 2, provider);

   // 6. 创建OH_UdmfData对象，并向OH_UdmfData中添加OH_UdmfRecord。
   OH_UdmfData* setData = OH_UdmfData_Create();
   OH_UdmfData_AddRecord(setData, record);

   // 7. 创建OH_Pasteboard对象，将数据写入剪贴板中。
   OH_Pasteboard* pasteboard = OH_Pasteboard_Create();
   OH_Pasteboard_SetData(pasteboard, setData);
   ```

4. 从剪贴板获取延迟复制数据。
   
   ```c
   // 8. 从剪贴板获取OH_UdmfData。
   int status = -1;
   OH_UdmfData* getData = OH_Pasteboard_GetData(pasteboard, &status);

   // 9. 获取OH_UdmfData中的所有OH_UdmfRecord。
   unsigned int recordCount = 0;
   OH_UdmfRecord** getRecords = OH_UdmfData_GetRecords(getData, &recordCount);

   // 10. 遍历OH_UdmfRecord。
   for (unsigned int recordIndex = 0; recordIndex < recordCount; ++recordIndex) {
       OH_UdmfRecord* record = getRecords[recordIndex];

       // 11. 查询OH_UdmfRecord中的数据类型。
       unsigned typeCount = 0;
       char** recordTypes = OH_UdmfRecord_GetTypes(record, &typeCount);

       // 12. 遍历数据类型。
       for (unsigned int typeIndex = 0; typeIndex < typeCount; ++typeCount) {
           char* recordType = recordTypes[typeIndex];

           // 纯文本类型
           if (strcmp(recordType, UDMF_META_PLAIN_TEXT) == 0) {
               // 创建纯文本类型的Uds对象
               OH_UdsPlainText* udsText = OH_UdsPlainText_Create();
               // 从record中获取纯文本类型的Uds对象
               OH_UdmfRecord_GetPlainText(record, udsText);
               // 从Uds对象中获取内容
               const char* content = OH_UdsPlainText_GetContent(udsText);
           }
           // HTML类型
           else if (strcmp(recordType, UDMF_META_HTML) == 0) {
               // 创建HTML类型的Uds对象
               OH_UdsHtml* udsHtml = OH_UdsHtml_Create();
               // 从record中获取HTML类型的Uds对象
               OH_UdmfRecord_GetHtml(record, udsHtml);
               // 从Uds对象中获取内容
               const char* content = OH_UdsHtml_GetContent(udsHtml);
           }
       }
   }
   ```

5. 使用完毕后需要及时释放相关对象的内存。
   
   ```c
   OH_UdsPlainText_Destroy(udsText);
   OH_UdsHtml_Destroy(udsHtml);
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
| setUnifiedData(data: unifiedDataChannel.UnifiedData): Promise\<void> | 将统一数据类型的数据写入系统剪贴板，在使用延迟复制粘贴功能时，不可与getUnifiedDataSync同线程调用。|
| setUnifiedDataSync(data: unifiedDataChannel.UnifiedData): void | 将统一数据类型的数据写入系统剪贴板，此接口为同步接口，在使用延迟复制粘贴功能时，不可与getUnifiedDataSync同线程调用。|
| getUnifiedData(): Promise\<unifiedDataChannel.UnifiedData> | 从系统剪贴板中读取统一数据类型的数据。|
| getUnifiedDataSync(): unifiedDataChannel.UnifiedData | 从系统剪贴板中读取统一数据类型的数据，此接口为同步接口，在使用延迟复制粘贴功能时，不可与setUnifiedData和setUnifiedDataSync同线程调用。|
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
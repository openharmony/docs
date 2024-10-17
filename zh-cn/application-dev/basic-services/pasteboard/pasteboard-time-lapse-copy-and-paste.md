# 使用剪贴板进行延迟复制粘贴

## 场景介绍

[剪贴板服务](../../reference/apis-basic-services-kit/js-apis-pasteboard.md)主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。

反复执行复制操作时，剪贴板缓存中会存储多余数据从而导致内存增加，为了优化内存以及后续支持指定数据类型粘贴，剪贴板提供了延迟复制粘贴的功能。

用户复制使用延迟粘贴技术的应用内的数据时，该条真实数据不会立即写入剪贴板服务的缓存中，而是等需要粘贴时，再从应用获取数据。

## 约束限制

- 剪贴板内容大小&lt;128MB时支持使用。

## 接口说明

| 名称 | 说明                                                                   |
| -------- |----------------------------------------------------------------------|
| setUnifiedData(data: udc.UnifiedData): Promise\<void> | 将统一数据类型的数据写入系统剪贴板，在使用延迟复制粘贴功能时，不可与getUnifiedDataSync同线程调用。|
| setUnifiedDataSync(data: udc.UnifiedData): void | 将统一数据类型的数据写入系统剪贴板，此接口为同步接口，在使用延迟复制粘贴功能时，不可与getUnifiedDataSync同线程调用。|
| getUnifiedData(): Promise\<udc.UnifiedData> | 从系统剪贴板中读取统一数据类型的数据。|
| getUnifiedDataSync(): udc.UnifiedData | 从系统剪贴板中读取统一数据类型的数据，此接口为同步接口，在使用延迟复制粘贴功能时，不可与setUnifiedData和setUnifiedDataSync同线程调用。|

## 开发步骤

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

4. 从系统剪贴板中读取这条text数据

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
# 通过标准化数据通路实现数据共享 (ArkTS)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @jcwen-->
<!--SE: @junathuawei1; @zph000-->
<!--TSE: @lj_liujing; @yippo; @logic42-->


## 场景介绍

在多对多跨应用数据共享的场景下，需要提供一条数据通路能够写入多个不同应用的数据并共享给其他应用进行读取。

UDMF针对多对多跨应用数据共享的不同业务场景提供了标准化的数据通路，提供了标准化的数据写入与读取接口。

## 标准化数据通路的定义和实现

标准化数据通路是为各种业务场景提供的跨应用的数据写入与读取通路，它可以暂存应用需要共享的符合标准化数据定义的统一数据对象，并提供给其他应用进行访问，同时按照一定的策略对暂存数据的修改、删除权限和生命周期进行管理。

标准化数据通路通过UDMF提供的系统服务实现，应用（数据提供方）需要共享公共数据时可以通过UDMF提供的插入接口将数据写入到UDMF的数据通路中，并且可以通过UDMF提供的更新和删除接口对本应用已经存入数据进行更新和删除操作。目标应用（数据访问方）可以通过UDMF提供的读取接口进行数据的访问。

标准化数据通路相关接口不推荐多线程调用。

统一数据对象UnifiedData在UDMF数据通路中具有全局唯一URI标识，其定义为udmf://intention/bundleName/groupId，其中各组成部分的含义分别为：

+ **udmf:** 协议名，表示使用UDMF提供的数据通路。

+ **intention:** UDMF已经支持的数据通路类型枚举值，对应不同的业务场景。

+ **bundleName:** 数据来源应用的包名称。

+ **groupId:** 分组名称，支持批量数据分组管理。

当前UDMF中的跨应用数据共享通路有：**公共数据通路**

**公共数据通路**：应用共享的公用数据共享通路，所有应用均可向通路中写入数据，写入方可以根据写入数据时生成的数据唯一标识符进行数据的更新、删除、指定数据标识符进行查询、全量查询；数据读取方能通过唯一标识符读取指定的数据，也可以设置Intention枚举类型为DATA_HUB来读取当前数据通路中的全量数据。公共数据通路通常仅用于传输应用间的过程数据，无法用于传输沙箱目录下文件等有权限管控的数据。UDMF会统一对数据的生命周期进行管理，每小时定期清理存入时长超过一小时的数据。

## 接口说明

以下是UDMF标准化数据通路的相关接口，均为异步接口。异步接口均有callback和Promise两种返回形式，下表均以callback形式为例，更多接口及使用方式请见[标准化数据通路](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md)和[标准化数据定义与描述](../reference/apis-arkdata/js-apis-data-uniformTypeDescriptor.md)。

| 接口名称                                                                                    | 描述                                          | 
|-----------------------------------------------------------------------------------------|---------------------------------------------|
| insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void | 将数据写入UDMF的公共数据通路中，并生成数据的唯一标识符，使用callback异步回调。 | 
| updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void   | 更新已写入UDMF的公共数据通路的数据，使用callback异步回调。           | 
| queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void        | 查询UDMF公共数据通路的数据，使用callback异步回调。               | 
| deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void       | 删除UDMF公共数据通路的数据，返回删除的数据集，使用callback异步回调。 |


## 开发步骤

以[PlainText](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#plaintext)、[HTML](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#html)、[PixelMap](../reference/apis-arkdata/js-apis-data-uniformDataStruct.md#pixelmap15)三种数据进行多对多数据共享的过程为例说明开发步骤，数据提供方可以通过UMDF提供的insertData接口将数据写入公共数据通路，获取到的返回值（生成的数据的唯一标识符），可用于对其插入的数据进行更新和删除操作。数据访问方则可以通过UDMF提供的查询接口获取当前公共数据通路的全量数据。

### 数据提供方

1. 导入unifiedDataChannel、uniformTypeDescriptor和uniformDataStruct模块。

   ```ts
   import { unifiedDataChannel, uniformTypeDescriptor, uniformDataStruct } from '@kit.ArkData';
   ```
2. 创建一个统一数据对象并插入到UDMF的公共数据通路中。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { image } from '@kit.ImageKit';
   // 准备PlainText文本数据内容
   let plainTextObj : uniformDataStruct.PlainText = {
     uniformDataType: 'general.plain-text',
     textContent : 'Hello world',
     abstract : 'This is abstract',
   }
   let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainTextObj);
   // 准备HTML数据内容
   let htmlObj : uniformDataStruct.HTML = {
     uniformDataType :'general.html',
     htmlContent : '<div><p>Hello world</p></div>',
     plainContent : 'Hello world',
   }
   // 为该记录增加一种样式，两种样式存储的是同一个数据，为不同表达形式
   record.addEntry(uniformTypeDescriptor.UniformDataType.HTML, htmlObj);
   let unifiedData = new unifiedDataChannel.UnifiedData(record);

   // 准备pixelMap数据内容
   let arrayBuffer = new ArrayBuffer(4*3*3);
   let opt : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 3, width: 3 }, alphaType: 3 };
   let pixelMap : uniformDataStruct.PixelMap = {
     uniformDataType : 'openharmony.pixel-map',
     pixelMap : image.createPixelMapSync(arrayBuffer, opt),
   }
   unifiedData.addRecord(new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.OPENHARMONY_PIXEL_MAP, pixelMap));
   // 指定要插入数据的数据通路枚举类型
   let options: unifiedDataChannel.Options = {
     intention: unifiedDataChannel.Intention.DATA_HUB
   }
   try {
     unifiedDataChannel.insertData(options, unifiedData, (err, key) => {
       if (err === undefined) {
         console.info(`Succeeded in inserting data. key = ${key}`);
       } else {
         console.error(`Failed to insert data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch (e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Insert data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```
3. 更新上一步插入的统一数据对象。

   ```ts
   let plainTextUpdate : uniformDataStruct.PlainText = {
     uniformDataType: 'general.plain-text',
     textContent : 'How are you',
     abstract : 'This is abstract',
   }
   let recordUpdate = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainTextUpdate);
   let htmlUpdate : uniformDataStruct.HTML = {
     uniformDataType :'general.html',
     htmlContent : '<div><p>How are you</p></div>',
     plainContent : 'How are you',
   }
   recordUpdate.addEntry(uniformTypeDescriptor.UniformDataType.HTML, htmlUpdate);
   let unifiedDataUpdate = new unifiedDataChannel.UnifiedData(recordUpdate);
   
   // 指定要更新的统一数据对象的URI
   let optionsUpdate: unifiedDataChannel.Options = {
     // 此处的key值仅为示例，不可直接使用，其值与insertData接口回调函数中key保持一致
     key: 'udmf://DataHub/com.ohos.test/0123456789'
   };
   
   try {
     unifiedDataChannel.updateData(optionsUpdate, unifiedDataUpdate, (err) => {
       if (err === undefined) {
         console.info('Succeeded in updating data.');
       } else {
         console.error(`Failed to update data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch (e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Update data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```
4. 删除存储在UDMF公共数据通路中的统一数据对象。

   ```ts
   // 指定要删除数据的数据通路枚举类型
   let optionsDelete: unifiedDataChannel.Options = {
     intention: unifiedDataChannel.Intention.DATA_HUB
   };

   try {
     unifiedDataChannel.deleteData(optionsDelete, (err, data) => {
       if (err === undefined) {
         console.info(`Succeeded in deleting data. size = ${data.length}`);
         for (let i = 0; i < data.length; i++) {
           let records = data[i].getRecords();
           for (let j = 0; j < records.length; j++) {
             let types = records[j].getTypes();
             // 根据业务需要从记录中获取样式数据
             if (types.includes(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT)) {
               let text = records[j].getEntry(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) as uniformDataStruct.PlainText;
               console.info(`${i + 1}.${text.textContent}`);
             }
             if (types.includes(uniformTypeDescriptor.UniformDataType.HTML)) {
               let html = records[j].getEntry(uniformTypeDescriptor.UniformDataType.HTML) as uniformDataStruct.HTML;
               console.info(`${i + 1}.${html.htmlContent}`);
             }
           }
         }
       } else {
         console.error(`Failed to delete data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch (e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Delete data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```
   
### 数据访问方

1. 导入unifiedDataChannel、uniformTypeDescriptor和uniformDataStruct模块。

   ```ts
   import { unifiedDataChannel, uniformTypeDescriptor, uniformDataStruct } from '@kit.ArkData';
   ```
2. 查询存储在UDMF公共数据通路中的全量统一数据对象。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   // 指定要查询数据的数据通路枚举类型
   let options: unifiedDataChannel.Options = {
     intention: unifiedDataChannel.Intention.DATA_HUB
   };

   try {
     unifiedDataChannel.queryData(options, (err, data) => {
       if (err === undefined) {
         console.info(`Succeeded in querying data. size = ${data.length}`);
         for (let i = 0; i < data.length; i++) {
           let records = data[i].getRecords();
           for (let j = 0; j < records.length; j++) {
             let types = records[j].getTypes();
             // 根据业务需要从记录中获取样式数据
             if (types.includes(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT)) {
               let text = records[j].getEntry(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) as uniformDataStruct.PlainText;
               console.info(`${i + 1}.${text.textContent}`);
             }
             if (types.includes(uniformTypeDescriptor.UniformDataType.HTML)) {
               let html = records[j].getEntry(uniformTypeDescriptor.UniformDataType.HTML) as uniformDataStruct.HTML;
               console.info(`${i + 1}.${html.htmlContent}`);
             }
           }
         }
       } else {
         console.error(`Failed to query data. code is ${err.code},message is ${err.message} `);
       }
     });
   } catch(e) {
     let error: BusinessError = e as BusinessError;
     console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);
   }
   ```

# 标准化数据通路


## 场景介绍

UDMF定义了安全、标准化的数据接入与读取通路，为各种业务场景（如跨应用跨设备数据拖拽）提供了跨应用、跨设备的数据接入与读取通路，降低业务跨应用、跨设备数据交互的成本。


## 接口说明

以下是UDMF标准化数据通路的相关接口，均为异步接口。异步接口均有callback和Promise两种返回形式，下表均以callback形式为例，更多接口及使用方式请见[统一数据管理框架](../reference/apis/js-apis-data-udmf.md)。

| 接口名称                                                                                   | 描述                                          | 
|----------------------------------------------------------------------------------------|---------------------------------------------|
| insertData(options: Options, data: UnifiedData, callback: AsyncCallback<string>): void | 将数据写入UDMF的公共存储中，并生成数据的唯一标识符，使用callback异步回调。 | 
| updateData(options: Options, data: UnifiedData, callback: AsyncCallback<void>): void   | 更新已写入UDMF的公共存储的数据，使用callback异步回调。           | 
| queryData(options: Options, callback: AsyncCallback<Array<UnifiedData>>): void         | 查询UDMF公共存储的数据，使用callback异步回调。               | 
| deleteData(options: Options, callback: AsyncCallback<Array<UnifiedData>>): void        | 删除UDMF公共存储的数据，返回删除的数据集，使用callback异步回调。 |


## 开发步骤

以一次统一数据对象的插入、更新、查询和删除为例，说明开发步骤，示例代码均采用Callback形式，Promise形式请见。

1. 导入`@ohos.data.UDMF`模块

   ```js
   import UDMF from '@ohos.data.UDMF';
   ```
2. 创建一个统一数据对象并插入到UDMF的公共存储中。

   ```js
   let plainText = new UDMF.PlainText();
   plainText.textContent = 'hello world!';
   let unifiedData = new UDMF.UnifiedData(plainText);
   
   let options = {
       intention: UDMF.Intention.SUPER_HUB
   }
   try {
       UDMF.insertData(options, unifiedData, (err, data) => {
           if (err === undefined) {
               console.info(`Succeeded in inserting data. key = ${data}`);
           } else {
               console.error(`Failed to insert data. code is ${err.code},message is ${err.message} `);
           }
       });
   } catch(e) {
       console.error(`Insert data throws an exception. code is ${e.code},message is ${e.message} `);
   }
   ```
3. 更新上一步骤插入的统一数据对象。

   ```js
   let plainText = new UDMF.PlainText();
   plainText.textContent = 'hello world!';
   let unifiedData = new UDMF.UnifiedData(plainText);
   
   let options = {
       key: 'udmf://SuperHub/com.ohos.test/0123456789'
   };
   
   try {
       UDMF.updateData(options, unifiedData, (err) => {
           if (err === undefined) {
               console.info('Succeeded in updating data.');
           } else {
               console.error('Failed to update data. code is ${err.code},message is ${err.message} `);
           }
       });
   } catch(e) {
       console.error(`Update data throws an exception. code is ${e.code},message is ${e.message} `);
   }
   ```
4. 查询存储在UDMF公共存储中的统一数据对象。

   ```js
   let options = {
    intention: UDMF.Intention.SUPER_HUB
   };
   
   try {
       UDMF.queryData(options, (err, data) => {
           if (err === undefined) {
               console.info(`Succeeded in querying data. size = ${data.length}`);
               for (let i = 0; i < data.length; i++) {
                   let records = data[i].getRecords();
                   for (let j = 0; j < records.length; j++) {
                       if (records[j].getType() === UDMF.UnifiedDataType.PLAIN_TEXT) {
                           let text = <UDMF.PlainText>(records[j]);
                           console.info(`${i + 1}.${text.textContent}`);
                       }
                   }
               }
           } else {
               console.error(`Failed to query data. code is ${err.code},message is ${err.message} `);
           }
       });
   } catch(e) {
       console.error(`Query data throws an exception. code is ${e.code},message is ${e.message} `);
   }
   ```
5. 删除存储在UDMF公共存储中的统一数据对象。

   ```js
   let options = {
    intention: UDMF.Intention.SUPER_HUB
   };
   
   try {
       UDMF.deleteData(options, (err, data) => {
           if (err === undefined) {
               console.info(`Succeeded in deleting data. size = ${data.length}`);
               for (let i = 0; i < data.length; i++) {
                   let records = data[i].getRecords();
                   for (let j = 0; j < records.length; j++) {
                       if (records[j].getType() === UDMF.UnifiedDataType.PLAIN_TEXT) {
                           let text = <UDMF.PlainText>(records[j]);
                           console.info(`${i + 1}.${text.textContent}`);
                       }
                   }
               }
           } else {
               console.error(`Failed to delete data. code is ${err.code},message is ${err.message} `);
           }
       });
   } catch(e) {
       console.error(`Delete data throws an exception. code is ${e.code},message is ${e.message} `);
   }
   ```

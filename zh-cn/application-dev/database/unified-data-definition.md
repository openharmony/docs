# 标准化数据定义


## 场景介绍

为了构建OpenHarmony数据跨应用/设备交互的标准定义，降低应用/业务数据交互成本，促进数据生态建设，UDMF提供了标准化的数据定义，统一定义了多种常用的数据类型。应用可以使用统一数据管理框架提供的接口创建和使用这些标准化数据类型。


## 约束限制

- UDMF中每条数据记录大小不超过2MB。
- UDMF支持批量数据记录的分组管理，每个分组最多支持512条数据，整体大小不超过4MB。

## 接口说明

以下是键值型数据库持久化功能的相关接口，大部分为异步接口。异步接口均有callback和Promise两种返回形式，下表均以callback形式为例，更多接口及使用方式请见[分布式键值数据库](../reference/apis/js-apis-distributedKVStore.md)。

| 接口名称 | 描述 | 
| -------- | -------- |
| createKVManager(config: KVManagerConfig): KVManager | 创建一个KVManager对象实例，用于管理数据库对象。 | 
| getKVStore&lt;T&gt;(storeId: string, options: Options, callback: AsyncCallback&lt;T&gt;): void | 指定Options和storeId，创建并得到指定类型的KVStore数据库。 | 
| put(key: string, value: Uint8Array\|string\|number\|boolean, callback: AsyncCallback&lt;void&gt;): void | 添加指定类型的键值对到数据库。 | 
| get(key: string, callback: AsyncCallback&lt;Uint8Array\|string\|boolean\|number&gt;): void | 获取指定键的值。 | 
| delete(key: string, callback: AsyncCallback&lt;void&gt;): void | 从数据库中删除指定键值的数据。 | 


## 开发步骤

以一次创建数据（包含图片、纯文本、二进制图片三条数据记录）为例，说明开发步骤。

1. 导入`@ohos.data.UDMF`模块
   
   ```js
   import UDMF from '@ohos.data.UDMF';
   ```
2. 创建图片数据记录，并初始化得到带有该数据记录的UnifiedData对象
   
   （1）创建图片数据记录
   
   ```js
   let image = new UDMF.Image();
   ```
   
   （2）修改对象属性
   
   ```js
   // Image对象包含一个属性imageUri
   image.imageUri = '...';
   ```
   
   （3）访问对象属性
   
   ```js
   console.info(`imageUri = ${image.imageUri}`);
   ```
   
   （4）创建一个统一数据对象实例
   
   ```js
   let unifiedData = new UDMF.UnifiedData(image);
   ```
3. 创建纯文本数据类型记录，将其添加到刚才创建的UnifiedData对象
   
   ```js
   let plainText = new UDMF.PlainText();
   plainText.textContent = 'this is textContent of plainText';
   plainText.abstract = 'abstract of plainText';
   plainText.details = {
     plainKey1: 'plainValue1',
     plainKey2: 'plainValue2',
   };
   unifiedData.addRecord(plainText);
   ```
4. 创建二进制图片数据类型记录，将其添加到UnifiedData对象
   
   ```js
   let sdPixelMap = new UDMF.SystemDefinedPixelMap();
   sdPixelMap.rawData = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
   unifiedData.addRecord(sdPixelMap);
   ```
5. 记录添加完成后，可获取当前UnifiedData对象内的所有数据记录
   
   ```js
   let records = unifiedData.getRecords();
   ```
6. 遍历每条记录，判断该记录的数据类型，转换为子类对象，得到原数据记录
   
   ```js
   for (let i = 0; i < records.length; i ++) {
     // 读取该数据记录的类型
     let type = records[i].getType();
     switch (type) {
       case UDMF.UnifiedDataType.IMAGE:
         // 转换得到原图片数据记录
         let image = <UDMF.Image>(records[i]);
         break;
       case UDMF.UnifiedDataType.PLAIN_TEXT:
         // 转换得到原文本数据记录
         let plainText = <UDMF.PlainText>(records[i]);
         break;
       case UDMF.UnifiedDataType.SYSTEM_DEFINED_PIXEL_MAP:
         // 转换得到原二进制图片数据记录
         let sdPixelMap = <UDMF.SystemDefinedPixelMap>(records[i]);
         break;
       default:
         break;
     }
   }
   ```

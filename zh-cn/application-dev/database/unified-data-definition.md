# 标准化数据定义


## 场景介绍

为了构建OpenHarmony数据跨应用、跨设备交互的标准定义，降低应用/业务数据交互成本，促进数据生态建设，UDMF提供了标准化的数据定义，统一定义了多种常用的数据类型。应用可以使用统一数据管理框架提供的接口创建和使用这些标准化数据类型。


## 约束限制

- UDMF中每条数据记录大小不超过2MB。
- UDMF支持批量数据记录的分组管理，每个分组整体大小不超过4MB。


## 接口说明

UDMF支持的标准化数据类型列表，请见接口参考中的[UnifiedDataType](../reference/apis/js-apis-data-udmf.md#UnifiedDataType)。

UDMF标准化数据类型均为数据记录[UnifiedRecord](../reference/apis/js-apis-data-udmf.md#UnifiedRecord)的子类，如下表所示，
通过基类的getType方法可以获取具体的数据类型。

| 接口名称           | 描述                                                                                            | 
|-------------------|-----------------------------------------------------------------------------------------------|
| getType(): string | 获取当前数据记录对应的具体数据类型，见[UnifiedDataType](../reference/apis/js-apis-data-udmf.md#UnifiedDataType)。 |

UDMF支持批量数据记录的分组管理，通过统一数据对象[UnifiedData](../reference/apis/js-apis-data-udmf.md#UnifiedData)封装一组数据记录，
UnifiedData的接口如下表所示。

| 接口名称                                   | 描述                                                                       | 
|----------------------------------------|--------------------------------------------------------------------------|
| constructor(record: UnifiedRecord)     | 用于创建带有一条数据记录的统一数据对象。                                                     |
| addRecord(record: UnifiedRecord): void | 在当前统一数据对象中添加一条数据记录。                                                      |
| getRecords(): Array<UnifiedRecord>     | 将当前统一数据对象中的所有数据记录取出，通过本接口取出的数据为UnifiedRecord类型，需通过getType获取数据类型后转为子类再使用。 |


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

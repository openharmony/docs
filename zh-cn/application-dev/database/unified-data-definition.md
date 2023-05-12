# 标准化数据定义

## 场景介绍

为了构建OpenHarmony数据跨应用/设备交互的标准定义，降低应用/业务数据交互成本，促进数据生态建设，UDMF提供了标准化的数据定义，统一定义了多种常用的数据类型。应用可以使用统一数据管理框架提供的接口创建和使用这些标准化数据类型。

## 约束限制

- UDMF中每条数据记录大小不超过2MB。
- UDMF支持批量数据记录的分组管理，每个分组最多支持512条数据，整体大小不超过4MB。

## 接口说明

### 导入模块

```js
import UDMF from '@ohos.data.UDMF';
```

### UnifiedDataType

```UnifiedData```中各```UnifiedRecord```数据类型。
**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称                     | 说明             |
| ------------------------ | ---------------- |
| TEXT                     | 文本类型         |
| PLAIN_TEXT               | 纯文本类型       |
| HYPER_LINK               | 超链接类型       |
| HTML                     | 富文本类型       |
| IMAGE                    | 图片类型         |
| VIDEO                    | 视频类型         |
| SYSTEM_DEFINED_RECORD    | 系统服务数据类型 |
| SYSTEM_DEFINED_FORM      | 卡片类型         |
| SYSTEM_DEFINED_APP_ITEM  | 图标类型         |
| SYSTEM_DEFINED_PIXEL_MAP | 二进制图片类型   |

### UnifiedData

表示UDMF数据对象，提供封装一组数据记录的方法。
仅是按照统一数据规范创建数据，并未写入存储中。
**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

#### constructor

constructor(record: UnifiedRecord)
用于创建带有一条数据记录的```UnifiedData```对象。
**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core
**参数：**

| 参数名 | 类型          | 必填 | 说明                        |
| ------ | ------------- | ---- | --------------------------- |
| record | UnifiedRecord | Y    | UnifiedData中携带的数据记录 |

#### addRecord

addRecord(record: UnifiedRecord): void;
在当前```UnifiedData```对象中添加一条记录。
**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core
**参数：**

| 参数名 | 类型          | 必填 | 说明                        |
| ------ | ------------- | ---- | --------------------------- |
| record | UnifiedRecord | Y    | UnifiedData中携带的数据记录 |

**示例：**

```
import UDMF from '@ohos.data.UDMF';

let text = new UDMF.PlainText();
text.textContent = "Hello world!";
let unifiedData = new UDMF.UnifiedData(text);

let text2 = new UDMF.PlainText();
text2.textContent = "Hello, OpenHarmony!";
unifiedData.addRecord(text2);
```

#### getRecords

getRecords(): Array\<UnifiedRecord\>;
将当前UnifiedData对象中的所有UnifiedRecord取出。
**系统能力** ：SystemCapability.DistributedDataManager.UDMF.Core
**返回值：**

| 类型                   | 描述                       |
| ---------------------- | -------------------------- |
| Array\<UnifiedRecord\> | 向当前数据对象内添加的记录 |

**示例：**

```
import UDMF from '@ohos.data.UDMF';

...

let records = unifiedData.getRecords();
console.log("array size is: " + records.size());
```

### Summary

描述某一```UnifiedData```对象的数据摘要。
**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core
**属性定义：**

| 属性名    | 类型                      | 可读 | 可写 | 说明                                                         |
| --------- | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| symmary   | { [key: string]: number } | Y    | N    | 是一个字典类型对象，key为UnifiedDataType类型，value为UnifiedData对象中key类型记录数据量总和（当前文件类型记录仅记录uri大小，非文件大小） |
| totalSize | number                    | Y    | N    | UnifiedData对象内记录总大小                                  |

**示例：**

```
import UDMF from '@ohos.data.UDMF';

getSummaryCallback(data, err) {
    let summary = data;
    console.log("total: " + summary.totalSize);
}
```

### UnifiedRecord

对UDMF数据支持的数据内容的抽象定义，称为记录，一个统一数据对象内包含一条或多条记录，例如一条文本记录，一条图片记录，一条HTML记录等。
UnifiedRecord是一个抽象父类，无法保存具体数据内容，应用在使用时，不能将其添加到UnifiedData中，而应该创建带有数据内容的具体子类，如```Text```，```Image```等。
**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

#### getType

getType(): UnifiedDataType;
获取当前UnifiedRecord的类型。
由于从UnifiedData中调用```getRecords```取出数据都是```UnifiedRecord```对象，因此需要通过该接口查询该条记录的具体类型，将```UnifiedRecord```对象转换为其子类，调用子类接口。
**系统能力** ：SystemCapability.DistributedDataManager.UDMF.Core
**返回值：**

| 类型            | 说明                           |
| --------------- | ------------------------------ |
| UnifiedDataType | 当前数据记录对应的具体数据类型 |

**示例：**

```
import UDMF from '@ohos.data.UDMF';

let text = new UDMF.PlainText();
text.textContent = "Hello world!";
let unifiedData = new UDMF.UnifiedData(text);

let text2 = new UDMF.PlainText();
text2.textContent = "Hello, OpenHarmony!";
unifiedData.addRecord(text2);

let records = unifiedData.getRecords();
if (records[0] != null && records[0].getType() == UnifiedDataType.PlainText) {
    console.log(((UDMF.Text)record[0]).content);
}
```

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

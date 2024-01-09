# 标准化数据结构


## 场景介绍

针对一些UTD标准化数据类型，为了方便业务使用，我们提供了标准化数据结构，例如OpenHarmony系统定义的桌面卡片类型（对应的标准化数据类型标识为为'openharmony.form'），我们明确定义了该数据结构对应的相关描述信息。

某些业务场景下应用可以直接使用我们具体定义的UTD标准化数据结构，例如跨应用拖拽场景。拖出方应用可以按照标准化数据结构将拖拽数据写入[拖拽事件](../reference/arkui-ts/ts-universal-events-drag-drop.md#dragevent说明)，
拖入方应用从拖拽事件中读取拖拽数据并按照标准化数据结构进行数据的解析。这使得不同应用间的数据交互遵从相同的标准定义，有效减少了跨应用数据交互的开发工作量。

## 当前支持的标准化数据结构

UDMF针对部分标准化数据类型定义的标准化数据结构如下所示：

| 数据类型                |       数据结构        | 说明       |
| ----------------------- | :-------------------: | ---------- |
| 'general.text'          |         Text          | 文本       |
| 'general.plain-text'    |       PlainText       | 纯文本     |
| 'general.hyperlink'     |       Hyperlink       | 超链接     |
| 'general.html'          |         HTML          | 富文本     |
| 'general.file'          |         File          | 文件       |
| 'general.image'         |         Image         | 图片       |
| 'general.video'         |         Video         | 视频       |
| 'general.audio'         |         Audio         | 音频       |
| 'general.folder'        |        Folder         | 文件夹     |
| 'openharmony.form'      |   SystemDefinedForm   | 卡片       |
| 'openharmony.app-item'  | SystemDefinedAppItem  | 图标       |
| 'openharmony.pixel-map' | SystemDefinedPixelMap | 二进制图片 |

## 约束限制

- UDMF支持批量数据记录的分组管理，每个分组整体大小不超过200MB，其中PlainText、Hyperlink、HTML内单个属性值数据上限20M。

## 接口说明

UDMF提供了统一数据对象UnifiedData，用于封装一组数据记录UnifiedRecord。数据记录UnifiedRecord则是对UDMF支持的数据内容的抽象定义，例如一条文本记录、一条图片记录等。数据记录中的数据内容类型对应为各数据类型UniformDataType。

以下是标准化数据结构的常用接口说明，更多接口和具体说明，请见[标准化数据通路](../reference/apis/js-apis-data-unifiedDataChannel.md)和[标准化数据定义与描述](../reference/apis/js-apis-data-uniformTypeDescriptor.md)。

| 类名称        | 接口名称                               | 描述                                                         |
| ------------- | -------------------------------------- | ------------------------------------------------------------ |
| UnifiedRecord | getType(): string                      | 获取当前数据记录对应的具体数据类型。                         |
| UnifiedData   | constructor(record: UnifiedRecord)     | 用于创建带有一条数据记录的统一数据对象。                     |
| UnifiedData   | addRecord(record: UnifiedRecord): void | 在当前统一数据对象中添加一条数据记录。                       |
| UnifiedData   | getRecords(): Array\<UnifiedRecord>    | 将当前统一数据对象中的所有数据记录取出，通过本接口取出的数据为UnifiedRecord类型，需通过getType获取数据类型后转为子类再使用。 |


## 开发步骤

以使用标准化数据结构定义数据内容（包含图片、纯文本两条数据记录）为例，提供基本的开发步骤。

1. 导入`@ohos.data.unifiedDataChannel`和`@ohos.data.uniformTypeDescriptor`模块。

   ```ts
   import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
   import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
   ```
2. 创建图片数据记录，并初始化得到带有该数据记录的UnifiedData对象。

   （1）创建图片数据记录。

   ```ts
   let image = new unifiedDataChannel.Image();
   ```

   （2）修改对象属性。

   ```ts
   // Image对象包含一个属性imageUri
   image.imageUri = '...';
   ```

   （3）访问对象属性。

   ```ts
   console.info(`imageUri = ${image.imageUri}`);
   ```

   （4）创建一个统一数据对象实例。

   ```ts
   let unifiedData = new unifiedDataChannel.UnifiedData(image);
   ```
3. 创建纯文本数据类型记录，将其添加到刚才创建的UnifiedData对象。

   ```ts
   let plainText = new unifiedDataChannel.PlainText();
   plainText.textContent = 'this is textContent of plainText';
   plainText.abstract = 'abstract of plainText';
   plainText.details = {
     plainKey1: 'plainValue1',
     plainKey2: 'plainValue2',
   };
   unifiedData.addRecord(plainText);
   ```
4. 记录添加完成后，可获取当前UnifiedData对象内的所有数据记录。

   ```ts
   let records = unifiedData.getRecords();
   ```
5. 遍历每条记录，判断该记录的数据类型，转换为子类对象，得到原数据记录。

   ```ts
   for (let i = 0; i < records.length; i ++) {
     // 读取该数据记录的类型
     let type = records[i].getType();
     switch (type) {
       case uniformTypeDescriptor.UniformDataType.IMAGE:
         // 转换得到原图片数据记录
         let image = records[i] as unifiedDataChannel.Image;
         break;
       case uniformTypeDescriptor.UniformDataType.PLAIN_TEXT:
         // 转换得到原文本数据记录
         let plainText = records[i] as unifiedDataChannel.PlainText;
         break;
       default:
         break;
     }
   }
   ```
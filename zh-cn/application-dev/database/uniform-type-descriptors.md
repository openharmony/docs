# 标准化数据定义与描述


## 场景介绍

标准化数据定义与描述（Uniform Type Descriptor，简称UTD）用于解决OpenHarmony系统中的类型模糊问题，即针对同一种数据类型，存在不同的
类型描述方式：MIME Type、文件扩展名等。例如描述JPG/JPEG类型图片时，可以使用image/jpeg，.jgp，.jpeg或image/picture等方式进行描述。
当相关类型的数据进行跨应用、跨设备传输时，目的端应用/设备需要进行多方面的适配，才能够对数据内容进行推论，且存在无法识别的情况。

UTD通过定义常用的数据类型描述符，构筑OpenHarmony生态内跨应用、跨设备数据交互的基础语言，生态内的应用间、设备间数据交互将会形成统一的
逻辑，进而成为OpenHarmony生态内的数据类型标准，可以极大的减少数据互通的适配成本。

## 标准化数据类型的层级关系

基于MIME Type或文件后缀名进行类型区分，存在另一个不足，即扁平化的数据类型定义；扁平/松散的类型定义难以描述不同类型间的兼容与继承关系，
且在实际使用过程中，会增加应用处理数据类型时的开发复杂度，例如搜索场景，用户从精确地搜索动物相关的任意类型图片，进一步扩展到动物相关的
任意图片、视频或音频资源。为了满足上述场景，我们需要在定义数据类型时，支持类型层级结构。

构建标准类型的层级结构，定义层级结构中的类型归属关系，能够帮助系统、应用实现数据类型的分层、分类管理。当用户进行数据分享或拖拽式，如果
数据中同时包含图片、视频、音频等内容，系统/应用可以根据层级按需对分享内容进行整理，如分享了XX张照片、XX条视频或XX个媒体资源文件等。

## UTD定义

标准化数据定义与描述（Uniform Type Descriptor，简称UTD）包含了标准化数据类型的标识ID、归属类型关系、简要描述等信息，其具体定义如下所示：

+ **typeId：** 定义标准化数据类型的ID，该ID具有唯一性。

+ **belongingToTypes：** 定义标准化数据类型的归属关系，即该标准化数据类型归属于哪个更高层级的类型，允许存在一个标准化数据类型归属于多个类型的情况。

+ **description：** 标准化数据类型的简要说明。

+ **referenceURL：** 标准化数据类型的参考链接URL，用于描述类型的详细信息。

+ **iconFile：** 标准化数据类型的默认图标文件路径，可能为空字符串（即没有默认图标），应用可以自行决定是否使用该默认图标。

UTD中定义的标准化数据类型分为两类，物理&逻辑，如下图所示（图中涉及的标准化数据类型详见UniformDataType的接口定义）。物理分类的根节点为general.entity，
用于描述类型的物理属性，比如文件、目录等。逻辑分类的根节点为general.object，用于描述类型的功能性特征，如图片、网页等。

将标准化数据类型分为物理和逻辑两类，可以从两个维度对数据类型进行描述。如描述图片时，可以是一个图片对象，同时也可以是一个文件，并非所有的格式都具有
两个维度，如general.calendar，更多的注重calendar对象的功能性描述。

## 接口说明

以下是UTD常用接口的说明，更多接口和具体说明，请见[标准化数据定义与描述](../reference/apis/js-apis-data-uniformTypeDescriptor.md)。

| 类名称             | 接口名称                                                                                         | 描述                                      | 
|-----------------|----------------------------------------------------------------------------------------------|-----------------------------------------|
| UniformDataType | 例如TEXT等枚举值                                                                                   | OpenHarmony标准化数据类型的枚举定义。 |
| TypeDescriptor  | belongsTo(type: string): boolean                                                             | 判断当前标准化数据类型是否归属于指定的标准化数据类型。             |
| TypeDescriptor  | isLowerLevelType(type: string): boolean                                                      | 判断当前标准化数据类型是否是指定标准化数据类型的低层级类型。          |
| TypeDescriptor  | isHigherLevelType(type: string): boolean                                                     | 判断当前标准化数据类型是否是指定标准化数据类型的高层级类型。 |
| 无               | getUniformDataTypeByFilenameExtension(filenameExtension: string, belongsTo?: string): string | 根据给定的文件后缀名和所归属的标准化数据类型查询标准化数据类型的ID。 |
| 无               | getUniformDataTypeByMIMEType(mimeType: string, belongsTo?: string): string                   | 根据给定的MIME类型和所归属的标准化数据类型查询标准化数据类型的ID。 |

## 开发步骤

下面以媒体类文件的归属类型查询场景为例，说明如何使用UTD。

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

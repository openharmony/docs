# @ohos.data.UDMF（统一数据管理框架）

本模块提供数据统一管理的能力，包括对文本、图片等数据类型的标准化定义。通过调用对应数据类型的接口，应用程序可将各种数据封装为统一数据对象。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import UDMF from '@ohos.data.UDMF';
```

## UnifiedDataType

[统一数据对象](#unifieddata)中各[数据记录](#unifiedrecord)的数据类型。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称                         | 值                            | 说明        |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'Text'                       | 文本类型。     |
| PLAIN_TEXT                 | 'Text.PlainText'             | 纯文本类型。    |
| HYPERLINK                  | 'Text.Hyperlink'             | 超链接类型。    |
| HTML                       | 'Text.HTML'                  | 富文本类型。    |
| FILE                       | 'File'                       | 文件类型。     |
| IMAGE                      | 'File.Media.Image'           | 图片类型。     |
| VIDEO                      | 'File.Media.Video'           | 视频类型。     |
| FOLDER                     | 'File.Folder'                | 文件夹类型。    |
| SYSTEM_DEFINED_RECORD      | 'SystemDefinedType'          | 系统服务数据类型。 |
| SYSTEM_DEFINED_FORM        | 'SystemDefinedType.Form'     | 卡片类型。     |
| SYSTEM_DEFINED_APP_ITEM    | 'SystemDefinedType.AppItem'  | 图标类型。     |
| SYSTEM_DEFINED_PIXEL_MAP   | 'SystemDefinedType.PixelMap' | 二进制图片类型。  |
| APPLICATION_DEFINED_RECORD | 'ApplicationDefinedType'     | 应用自定义类型。  |

## UnifiedData

表示UDMF统一数据对象，提供封装一组数据记录的方法。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

### constructor

constructor(record: UnifiedRecord)

用于创建带有一条数据记录的统一数据对象。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                                      |
| ------ | ------------------------------- | ---- |-----------------------------------------|
| record | [UnifiedRecord](#unifiedrecord) | 是   | 要添加到统一数据对象中的数据记录，该记录为UnifiedRecord子类对象。 |

**示例：**

```js
let text = new UDMF.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new UDMF.UnifiedData(text);
```

### addRecord

addRecord(record: UnifiedRecord): void

在当前统一数据对象中添加一条数据记录。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                                          |
| ------ | ------------------------------- | ---- |---------------------------------------------|
| record | [UnifiedRecord](#unifiedrecord) | 是   | 要添加到统一数据对象中的数据记录，该记录为UnifiedRecord子类对象。|

**示例：**

```js
let text1 = new UDMF.PlainText();
text1.textContent = 'this is textContent of text1';
let unifiedData = new UDMF.UnifiedData(text1);

let text2 = new UDMF.PlainText();
text2.textContent = 'this is textContent of text2';
unifiedData.addRecord(text2);
```

### getRecords

getRecords(): Array\<UnifiedRecord\>

将当前统一数据对象中的所有数据记录取出。通过本接口取出的数据为UnifiedRecord类型，需通过[getType](#gettype)获取数据类型后转为子类再使用。

**系统能力** ：SystemCapability.DistributedDataManager.UDMF.Core

**返回值：**

| 类型                                     | 说明                      |
| ---------------------------------------- |-------------------------|
| Array\<[UnifiedRecord](#unifiedrecord)\> | 当前统一数据对象内所添加的记录。 |

**示例：**

```js
let text = new UDMF.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new UDMF.UnifiedData(text);

let link = new UDMF.HyperLink();
link.url = 'www.XXX.com';
unifiedData.addRecord(link);

let records = unifiedData.getRecords();
for (let i = 0; i < records.length; i++) {
  let record = records[i];
  if (record.getType() == UDMF.UnifiedDataType.PLAIN_TEXT) {
    let plainText = <UDMF.PlainText> (record);
    console.info(`textContent: ${plainText.textContent}`);
  } else if (record.getType() == UDMF.UnifiedDataType.HYPERLINK) {
    let hyperLink = <UDMF.HYPERLINK> (record);
    console.info(`linkUrl: ${hyperLink.url}`);
  }
}
```

## Summary

描述某一统一数据对象的数据摘要，包括所含数据类型及大小，当前暂不支持。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称      | 类型                      | 可读 | 可写 | 说明                                                                                |
| --------- | ------------------------- | ---- | ---- |-----------------------------------------------------------------------------------|
| summary   | { [key: string]: number } | 是   | 否   | 是一个字典类型对象，key表示数据类型（见[UnifiedDataType](#unifieddatatype)），value为统一数据对象中该类型记录大小总和（单位：Byte）。 |
| totalSize | number                    | 是   | 否   | 统一数据对象内记录总大小（单位：Byte）。                                                                     |

## UnifiedRecord

对UDMF支持的数据内容的抽象定义，称为数据记录。一个统一数据对象内包含一条或多条数据记录，例如一条文本记录、一条图片记录、一条HTML记录等。

UnifiedRecord是一个抽象父类，无法保存具体数据内容，应用在使用时，不能将其添加到统一数据对象中，而应该创建带有数据内容的具体子类，如Text、Image等。

### getType

getType(): string

获取当前数据记录的类型。由于从统一数据对象中调用[getRecords](#getrecords)所取出的数据是UnifiedRecord对象，因此需要通过本接口查询此记录的具体类型，再将该UnifiedRecord对象转换为其子类，调用子类接口。

**系统能力** ：SystemCapability.DistributedDataManager.UDMF.Core

**返回值：**

| 类型   | 说明                                                   |
| ------ |------------------------------------------------------|
| string | 当前数据记录对应的具体数据类型，见[UnifiedDataType](#UnifiedDataType)。|

**示例：**

```js
let text = new UDMF.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new UDMF.UnifiedData(text);

let records = unifiedData.getRecords();
if (records[0].getType() == UDMF.UnifiedDataType.PLAIN_TEXT) {
    let plainText = <UDMF.PlainText> (records[0]);
    console.info(`textContent: ${plainText.textContent}`);
}
```

## Text

文本类型数据，是[UnifiedRecord](#unifiedrecord)的子类，也是文本类型数据的基类，用于描述文本类数据，推荐开发者优先使用Text的子类描述数据，如[PlainText](#plaintext)、[HyperLink](#hyperlink)、[HTML](#html)等具体子类。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称    | 类型                      | 可读 | 可写 | 说明                                                                                                                                                  |
| ------- | ------------------------- | ---- | ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------|
| details | { [key: string]: string } | 是   | 是   | 是一个字典类型对象，key和value都是string类型，用于描述文本内容。例如，可生成一个details内容为<br />{<br />"title":"标题",<br />"content":"内容"<br />}<br />的数据对象，用于描述一篇文章。非必填字段，默认值为空字典对象。 |

**示例：**

```js
let text = new UDMF.Text();
text.details = {
  title: 'MyTitle',
  content: 'this is content',
};
let unifiedData = new UDMF.UnifiedData(text);
```

## PlainText

纯文本类型数据，是[Text](#text)的子类，用于描述纯文本类数据。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称        | 类型   | 可读 | 可写 | 说明                    |
| ----------- | ------ | ---- | ---- |-----------------------|
| textContent | string | 是   | 是   | 纯文本内容。                |
| abstract    | string | 是   | 是   | 纯文本摘要，非必填字段，默认值为空字符串。 |

**示例：**

```js
let text = new UDMF.PlainText();
text.textContent = 'this is textContent';
text.abstract = 'this is abstract';
```

## HyperLink

超链接类型数据，是[Text](#text)的子类，用于描述超链接类型数据。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称        | 类型   | 可读 | 可写 | 说明           |
| ----------- | ------ | ---- | ---- |--------------|
| url         | string | 是   | 是   | 链接url。       |
| description | string | 是   | 是   | 链接内容描述，非必填字段，默认值为空字符串。 |

**示例：**

```js
let link = new UDMF.HyperLink();
link.url = 'www.XXX.com';
link.description = 'this is description';
```

## HTML

HTML类型数据，是[Text](#text)的子类，用于描述超文本标记语言数据。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称         | 类型   | 可读 | 可写 | 说明                    |
| ------------ | ------ | ---- | ---- |-----------------------|
| htmlContent  | string | 是   | 是   | html格式内容。             |
| plainContent | string | 是   | 是   | 去除html标签后的纯文本内容，非必填字段，默认值为空字符串。 |

**示例：**

```js
let html = new UDMF.HTML();
html.htmlContent = '<div><p>标题</p></div>';
html.plainContent = 'this is plainContent';
```

## File

File类型数据，是[UnifiedRecord](#unifiedrecord)的子类，也是文件类型数据的基类，用于描述文件类型数据，推荐开发者优先使用File的子类描述数据，如[Image](#image)、[Video](#video)、[Folder](#folder)等具体子类。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称      | 类型                        | 可读 | 可写 | 说明                                                                                                                                                   |
|---------|---------------------------| ---- | ---- |------------------------------------------------------------------------------------------------------------------------------------------------------|
| details | { [key: string]: string } | 是   | 是   | 是一个字典类型对象，key和value都是string类型，用于描述文件相关信息。例如，可生成一个details内容为<br />{<br />"name":"文件名",<br />"type":"文件类型"<br />}<br />的数据对象，用于描述一个文件。非必填字段，默认值为空字典对象。 |
| uri     | string                    | 是   | 是   | 文件数据uri。                                                                                                                                             |

**示例：**

```js
let file = new UDMF.File();
file.details = {
    name: 'test',
    type: 'txt',
};
file.uri = 'schema://com.samples.test/files/test.txt';
```

## Image

图片类型数据，是[File](#file)的子类，用于描述图片文件。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称     | 类型   | 可读 | 可写 | 说明       |
| -------- | ------ | ---- | ---- |----------|
| imageUri | string | 是   | 是   | 图片数据uri。 |

**示例：**

```js
let image = new UDMF.Image();
image.imageUri = 'schema://com.samples.test/files/test.jpg';
```

## Video

视频类型数据，是[File](#file)的子类，用于描述视频文件。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称     | 类型   | 可读 | 可写 | 说明       |
| -------- | ------ | ---- | ---- |----------|
| videoUri | string | 是   | 是   | 视频数据uri。 |

**示例：**

```js
let video = new UDMF.Video();
video.videoUri = 'schema://com.samples.test/files/test.mp4';
```

## Folder

文件夹类型数据，是[File](#file)的子类，用于描述文件夹。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称     | 类型   | 可读 | 可写 | 说明      |
| -------- | ------ | ---- | ---- |---------|
| folderUri | string | 是   | 是   | 文件夹uri。 |

**示例：**

```js
let folder = new UDMF.Folder();
folder.folderUri = 'schema://com.samples.test/files/folder/';
```

## SystemDefinedRecord

SystemDefinedRecord是[UnifiedRecord](#unifiedrecord)的子类，也是OpenHarmony系统特有数据类型的基类，用于描述仅在OpenHarmony系统范围内流通的特有数据类型，推荐开发者优先使用SystemDefinedRecord的子类描述数据，如[SystemDefinedForm](#systemdefinedform)、[SystemDefinedAppItem](#systemdefinedappitem)、[SystemDefinedPixelMap](#systemdefinedpixelmap)等具体子类。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称    | 类型                       | 可读 | 可写 | 说明                                                         |
| ------- |--------------------------| ---- | ---- | ------------------------------------------------------------ |
| details | { [key: string]: number \| string \| Uint8Array } | 是   | 是   | 是一个字典类型对象，key是string类型，value可以写入number（数值类型）、string（字符串类型）、Uint8Array（二进制字节数组）类型数据。非必填字段，默认值为空字典对象。|

**示例：**

```js
let sdr = new UDMF.SystenDefinedReocrd();
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
sdr.details = {
    title: 'recordTitle',
    version: 1,
    content: u8Array,
};
let unifiedData = new UDMF.UnifiedData(sdr);
```

## SystemDefinedForm

卡片类型数据，是[SystemDefinedRecord](#systemdefinedrecord)的子类。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称        | 类型   | 可读 | 可写 | 说明             |
| ----------- | ------ | ---- | ---- |----------------|
| formId      | number | 是   | 是   | 卡片id。          |
| formName    | string | 是   | 是   | 卡片名称。          |
| bundleName  | string | 是   | 是   | 卡片所属的bundle名。   |
| abilityName | string | 是   | 是   | 卡片对应的ability名。 |
| module      | string | 是   | 是   | 卡片所属的module名。   |

**示例：**

```js
let form = new UDMF.SystemDefinedForm();
form.formId = 123456;
form.formName = 'MyFormName';
form.bundleName = 'MyBundleName';
form.abilityName = 'MyAbilityName';
form.module = 'MyModule';
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
form.details = {
  formKey1: 123,
  formKey2: 'formValue',
  formKey3: u8Array,
};
let unifiedData = new UDMF.UnifiedData(form);
```

## SystemDefinedAppItem

图标类型数据，是[SystemDefinedRecord](#systemdefinedrecord)的子类。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称        | 类型   | 可读 | 可写 | 说明              |
| ----------- | ------ | ---- | ---- |-----------------|
| appId       | string | 是   | 是   | 图标对应的应用id。      |
| appName     | string | 是   | 是   | 图标对应的应用名。       |
| appIconId   | string | 是   | 是   | 图标的图片id。        |
| appLabelId  | string | 是   | 是   | 图标名称对应的标签id。    |
| bundleName  | string | 是   | 是   | 图标对应的应用bundle名。 |
| abilityName | string | 是   | 是   | 图标对应的应用ability名。 |

**示例：**

```js
let appItem = new UDMF.SystemDefinedAppItem();
appItem.appId = 'MyAppId';
appItem.appName = 'MyAppName';
appItem.appIconId = 'MyAppIconId';
appItem.appLabelId = 'MyAppLabelId';
appItem.bundleName = 'MyBundleName';
appItem.abilityName = 'MyAbilityName';
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
appItem.details = {
    appItemKey1: 123,
    appItemKey2: 'appItemValue',
    appItemKey3: u8Array,
};
let unifiedData = new UDMF.UnifiedData(appItem);
```

## SystemDefinedPixelMap

与系统侧定义的[PixelMap](js-apis-image.md#pixelmap7)数据类型对应的图片数据类型，是[SystemDefinedRecord](#systemdefinedrecord)的子类，仅保存PixelMap的二进制数据。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称    | 类型       | 可读 | 可写 | 说明                |
| ------- | ---------- | ---- | ---- |-------------------|
| rawData | Uint8Array | 是   | 是   | PixelMap对象的二进制数据。 |

**示例：**

```js
import image from '@ohos.multimedia.image'; // PixelMap类定义所在模块

const color = new ArrayBuffer(96); // 创建pixelmap对象
let opts = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } }
image.createPixelMap(color, opts, (error, pixelmap) => {
    if(error) {
        console.log('Failed to create pixelmap.');
    } else {
        console.log('Succeeded in creating pixelmap.');
        let arrayBuf = new ArrayBuffer(pixelmap.getPixelBytesNumber());
        pixelmap.readPixelsToBuffer(arrayBuf);
        let u8Array = new Uint8Array(arrayBuf);
        let sdpixel = new UDMF.SystemDefinedPixelMap();
        sdpixel.rawData = u8Array;
        let unifiedData = new UDMF.UnifiedData(sdpixel);
    }
})
```

## ApplicationDefinedRecord

ApplicationDefinedRecord是[UnifiedRecord](#unifiedrecord)的子类，也是应用自定义数据类型的基类，用于描述仅在应用生态内部流通的自定义数据类型，应用可基于此类进行自定义数据类型的扩展。

**系统能力**：SystemCapability.DistributedDataManager.UDMF.Core

| 名称                     | 类型         | 可读 | 可写 | 说明                                    |
|------------------------|------------| ---- | ---- |---------------------------------------|
| applicationDefinedType | string     | 是   | 是   | 应用自定义类型标识符，必须以'ApplicationDefined'开头。 |
| rawData                | Uint8Array | 是   | 是   | 应用自定义数据类型的二进制数据。                      |

**示例：**

```js
let record = new UDMF.ApplicationDefinedRecord();
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
record.applicationDefinedType = 'ApplicationDefinedType';
record.rawData = u8Array;
let unifiedData = new UDMF.UnifiedData(record);
```

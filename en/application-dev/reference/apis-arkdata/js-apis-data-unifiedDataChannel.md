# @ohos.data.unifiedDataChannel (Unified Data Channel)

As a part of the Unified Data Management Framework (UDMF), the **unifiedDataChannel** module provides unified data channels and standard data access interfaces for many-to-many data sharing across applications. It also provides definitions for uniform data types, such as text and image, to streamline data interaction between different applications and minimize the workload of data type adaptation.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { unifiedDataChannel } from '@kit.ArkData';
```

## ShareOptions<sup>12+</sup>

Enumerates the options for using **UnifiedData** in a device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name         | Value| Description               |
|-------------|---|-------------------|
| IN_APP       | 0 | **UnifiedData** can be used only in the same application of a device.|
| CROSS_APP | 1 | **UnifiedData** can be used across applications of a device.|

## GetDelayData<sup>12+</sup>

type GetDelayData = (type: string) => UnifiedData

A type that defines a function used to obtain a deferred **UnifiedData** object. Currently, it can be used only in the pasteboard application of the same device.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Identifier of the deferred encapsulation.|

**Return value**

| Type                                    | Description                     |
| ---------------------------------------- |-------------------------|
| [UnifiedData](#unifieddata) | **UnifiedData** object.|

**Example**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';

let getDelayData: unifiedDataChannel.GetDelayData = ((type: string) => {
  if (type == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
    let text = new unifiedDataChannel.Text();
    text.details = {
      Key: 'textKey',
      Value: 'textValue',
    };
    let textData = new unifiedDataChannel.UnifiedData(text);
    return textData;
  }
  return new unifiedDataChannel.UnifiedData();
});
```

## ValueType<sup>12+</sup>

type ValueType = number | string | boolean | image.PixelMap | Want | ArrayBuffer | object | null | undefined

Enumerates the data field types allowed in a unified data record.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Type| Description|
| -------- | -------- |
| number | Number.|
| string | String.|
| boolean | Boolean.|
| image.PixelMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7).|
| Want | [Want](../apis-ability-kit/js-apis-app-ability-want.md).|
| ArrayBuffer | ArrayBuffer.|
| object | Object.|
| null | Null.|
| undefined | Undefined.|

## UnifiedDataProperties<sup>12+</sup>

Defines the properties of the data records in the unified data object, including the timestamp, tag, pasting range, and additional data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| extras<sup>12+</sup> | Record<string, object> | No| Yes| Object of the dictionary type used to set other properties. The default value is an empty dictionary object.|
| tag<sup>12+</sup> | string | No| Yes| Customized tag. The default value is an empty string.|
| timestamp<sup>12+</sup> | Date | Yes| Yes| Timestamp when [UnifiedData](#unifieddata) is generated. The default value is January 1, 1970 (UTC).|
| shareOptions<sup>12+</sup> | [ShareOptions](#shareoptions12) | No| Yes| Range, in which [UnifiedData](#unifieddata) can be used. The default value is **CROSS_APP**.|
| getDelayData<sup>12+</sup> | [GetDelayData](#getdelaydata12) | No| Yes| Callback for obtaining the deferred data. Currently, it can be used only in the pasteboard application of the same device. The default value is **undefined**.|

**Example**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';

let properties = new unifiedDataChannel.UnifiedDataProperties();
properties.extras = {
  key: {
    title: 'MyTitle',
    content: 'MyContent'
  }
};
properties.tag = "this is tag of properties";
properties.shareOptions = unifiedDataChannel.ShareOptions.CROSS_APP;
properties.getDelayData = ((type: string) => {
  if (type == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
    let text = new unifiedDataChannel.Text();
    text.details = {
      Key: 'textKey',
      Value: 'textValue',
    };
    let textData = new unifiedDataChannel.UnifiedData(text);
    return textData;
  }
  return new unifiedDataChannel.UnifiedData();
});
```

## UnifiedData

Provides APIs for encapsulating a set of data records.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

### Properties

| Name| Type| Read-Only| Optional| Description                                                                                             |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------|
| properties<sup>12+</sup> | [UnifiedDataProperties](#unifieddataproperties12) | No| No| Properties of all the data records in a unified data object, including the timestamp, tag, application range, and additional data.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

### constructor<sup>12+</sup>

constructor()

A constructor used to create a **UnifiedData** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Example**

```ts
let unifiedData = new unifiedDataChannel.UnifiedData();
```

### constructor

constructor(record: UnifiedRecord)

A constructor used to create a **UnifiedData** object with a data record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name| Type                           | Mandatory| Description                                     |
| ------ | ------------------------------- | ---- |-----------------------------------------|
| record | [UnifiedRecord](#unifiedrecord) | Yes  | Data record in the **UnifiedData** object. It is a **UnifiedRecord** object or its child class object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new unifiedDataChannel.UnifiedData(text);
```

### addRecord

addRecord(record: UnifiedRecord): void

Adds a data record to this **UnifiedRecord** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name| Type                           | Mandatory| Description                                         |
| ------ | ------------------------------- | ---- |---------------------------------------------|
| record | [UnifiedRecord](#unifiedrecord) | Yes  | Data record to add. It is a **UnifiedRecord** child class object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
let text1 = new unifiedDataChannel.PlainText();
text1.textContent = 'this is textContent of text1';
let unifiedData = new unifiedDataChannel.UnifiedData(text1);

let text2 = new unifiedDataChannel.PlainText();
text2.textContent = 'this is textContent of text2';
unifiedData.addRecord(text2);
```

### getRecords

getRecords(): Array\<UnifiedRecord\>

Obtains all data records from this **UnifiedData** object. The data obtained is of the **UnifiedRecord** type. Before using the data, you need to use [getType](#gettype) to obtain the data type and convert the data type to a child class.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Return value**

| Type                                    | Description                     |
| ---------------------------------------- |-------------------------|
| Array\<[UnifiedRecord](#unifiedrecord)\> | Records in the **UnifiedData** object obtained.|

**Example**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';

let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new unifiedDataChannel.UnifiedData(text);

let link = new unifiedDataChannel.Hyperlink();
link.url = 'www.XXX.com';
unifiedData.addRecord(link);

let records = unifiedData.getRecords();
for (let i = 0; i < records.length; i++) {
  let record = records[i];
  if (record.getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
    let plainText = record as unifiedDataChannel.PlainText;
    console.info(`textContent: ${plainText.textContent}`);
  } else if (record.getType() == uniformTypeDescriptor.UniformDataType.HYPERLINK) {
    let hyperlink = record as unifiedDataChannel.Hyperlink;
    console.info(`linkUrl: ${hyperlink.url}`);
  }
}
```

### hasType<sup>12+</sup>

hasType(type: string): boolean

Checks whether this **UnifiedData** object has the specified data type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type                           | Mandatory| Description                                         |
| ------ | ------------------------------- | ---- |---------------------------------------------|
| type | string | Yes  | Data type to check. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype).|

**Return value**

| Type                                    | Description                     |
| ---------------------------------------- |-------------------------|
| boolean | Returns **true** if the specified data type exists; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';

let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new unifiedDataChannel.UnifiedData(text);

let link = new unifiedDataChannel.Hyperlink();
link.url = 'www.XXX.com';
unifiedData.addRecord(link);

let hasPlainText = unifiedData.hasType(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT);
let hasLink = unifiedData.hasType(uniformTypeDescriptor.UniformDataType.HYPERLINK);
```

### getTypes<sup>12+</sup>

getTypes(): Array\<string\>

Obtains the types of all data records in this **UnifiedData** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Return value**

| Type                                    | Description                     |
| ---------------------------------------- |-------------------------|
| Array\<string\> | Array of the [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype) types obtained.|

**Example**

```ts
let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new unifiedDataChannel.UnifiedData(text);

let link = new unifiedDataChannel.Hyperlink();
link.url = 'www.XXX.com';
unifiedData.addRecord(link);

let types = unifiedData.getTypes();
```

## Summary

Represents the abstract of a uniform data object, including the data type and size.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| summary   | Record<string, number> | No| No| Dictionary type object, where the key indicates the data type (see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype)), and the value indicates the total size (in bytes) of this type of records in the unified data object.|
| totalSize | number | No| No| Total size of all the records in the **UnifiedData** object, in bytes.|

## UnifiedRecord

An abstract definition of the data content supported by the UDMF. A **UnifiedRecord** object contains one or more data records, for example, a text record, an image record, or an HTML record.

### constructor<sup>12+</sup>

constructor()

A constructor used to create a **UnfiedRecord** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Example**

```ts
let unifiedRecord = new unifiedDataChannel.UnifiedRecord();
```

### constructor<sup>12+</sup>

constructor(type: string, value: ValueType)

A constructor used to create a data record with the specified type and value.<br>If **value** is of the [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) type, **type** must be the value of **OPENHARMONY_PIXEL_MAP** in [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype).<br>If **value** is of the [Want](../apis-ability-kit/js-apis-app-ability-want.md) type, **type** must be the value of **OPENHARMONY_WANT** in [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name| Type                           | Mandatory| Description                                     |
| ------ | ------------------------------- | ---- |-----------------------------------------|
| type | string | Yes  | Type of the data record to create.|
| value | [ValueType](#valuetype12) | Yes  | Value of the data record to create.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed.  |

**Example**

```ts
import { image } from '@kit.ImageKit';
import { uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';
import { Want } from '@kit.AbilityKit';

let text = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, 'this is value of text');
let link = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.HYPERLINK, 'www.XXX.com');
let object: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'entryAbility',
};
let wantRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.OPENHARMONY_WANT, object);

const color = new ArrayBuffer(96);
let opts: image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 4, width: 6 } };
let pixelMap = image.createPixelMapSync(color, opts);
let pixelMapRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.OPENHARMONY_PIXEL_MAP, pixelMap);

let hyperlinkDetails : Record<string, string> = {
  'attr1': 'value1',
  'attr2': 'value2',
}
let hyperlink : uniformDataStruct.Hyperlink = {
  uniformDataType:'general.hyperlink',
  url : 'www.XXX.com',
  description : 'This is the description of this hyperlink',
  details : hyperlinkDetails,
}
let hyperlinkRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.HYPERLINK, hyperlink);
```

### getType

getType(): string

Obtains the type of this **UnfiedRecord**. The data obtained by [getRecords](#getrecords) from the **UnifiedData** object is a **UnifiedRecord** object. You need to use this API to obtain the specific type of the record, convert the **UnifiedRecord** object to its child class, and call the child class interfaces.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Return value**

| Type  | Description                                                  |
| ------ |------------------------------------------------------|
| string | Data type obtained. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype).|

**Example**

```ts
import { uniformTypeDescriptor } from '@kit.ArkData';

let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new unifiedDataChannel.UnifiedData(text);

let records = unifiedData.getRecords();
if (records[0].getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
  let plainText = records[0] as unifiedDataChannel.PlainText;
  console.info(`textContent: ${plainText.textContent}`);
}
```

### getValue<sup>12+</sup>

getValue(): ValueType

Obtains the value of this data record.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Return value**

| Type  | Description                                                  |
| ------ |------------------------------------------------------|
| [ValueType](#valuetype12) | Value obtained.|

**Example**

```ts
import { uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';

let text = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, 'this is value of text');
let value = text.getValue();

let hyperlinkDetails : Record<string, string> = {
  'attr1': 'value1',
  'attr2': 'value2',
}
let hyperlink : uniformDataStruct.Hyperlink = {
  uniformDataType:'general.hyperlink',
  url : 'www.XXX.com',
  description : 'This is the description of this hyperlink',
  details : hyperlinkDetails,
}
let hyperlinkRecord = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.HYPERLINK, hyperlink);
let hyperlinkValue = hyperlinkRecord.getValue();
```

## Text

Represents the text data. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of text data. You are advised to use the child class of **Text**, for example, [PlainText](#plaintext), [Hyperlink](#hyperlink), and [HTML](#html), to describe data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| details | Record<string, string> | No| Yes| A dictionary type object, where both the key and value are of the string type and are used to describe the text content. For example, a data object with the following content can be created to describe a text file:<br>{<br>"title":"Title",<br>"content":"Content"<br>}<br> The default value is an empty dictionary object.|

**Example**

```ts
let text = new unifiedDataChannel.Text();
text.details = {
  title: 'MyTitle',
  content: 'this is content',
};
let unifiedData = new unifiedDataChannel.UnifiedData(text);
```

## PlainText

Represents the plaintext data. It is a child class of [Text](#text) and is used to describe plaintext data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| textContent | string | No| No| Plaintext content.               |
| abstract    | string | No| Yes| Text abstract. This parameter is optional. The default value is an empty string.|

**Example**

```ts
let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent';
text.abstract = 'this is abstract';
```

## Hyperlink

Represents hyperlink data. It is a child class of [Text](#text) and is used to describe data of the hyperlink type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| url         | string | No| No| URL.      |
| description | string | No| Yes| Description of the linked content. This parameter is optional. The default value is an empty string.|

**Example**

```ts
let link = new unifiedDataChannel.Hyperlink();
link.url = 'www.XXX.com';
link.description = 'this is description';
```

## HTML

Represents the HTML data. It is a child class of [Text](#text) and is used to describe HTML data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| htmlContent  | string | No| No| Content in HTML format.            |
| plainContent | string | No| Yes| Plaintext without HTML tags. This parameter is optional. The default value is an empty string.|

**Example**

```ts
let html = new unifiedDataChannel.HTML();
html.htmlContent = '<div><p>Title</p></div>';
html.plainContent = 'this is plainContent';
```

## File

Represents the file data. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of the data of the file type. You are advised to use the child class of **File**, for example, [Image](#image), [Video](#video), and [Folder](#folder), to describe data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| details | Record<string, string> | No| Yes| A dictionary type object, where both the key and value are of the string type and are used to describe file information. For example, a data object with the following content can be created to describe a file:<br>{<br>"name":"File name",<br>"type":"File type"<br>}<br> The default value is an empty dictionary object.|
| uri     | string                    | No| No| URI of the file data.                                                                                                                                            |

**Example**

```ts
let file = new unifiedDataChannel.File();
file.details = {
    name: 'test',
    type: 'txt',
};
file.uri = 'schema://com.samples.test/files/test.txt';
```

## Image

Represents the image data. It is a child class of [File](#file) and is used to describe images.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| imageUri | string | No| No| URI of the image.|

**Example**

```ts
let image = new unifiedDataChannel.Image();
image.imageUri = 'schema://com.samples.test/files/test.jpg';
```

## Video

Represents video data. It is a child class of [File](#file) and is used to describe a video file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| videoUri | string | No| No| URI of the video file.|

**Example**

```ts
let video = new unifiedDataChannel.Video();
video.videoUri = 'schema://com.samples.test/files/test.mp4';
```

## Audio

Represents audio data. It is a child class of [File](#file) and is used to describe an audio file.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| audioUri | string | No| No| Audio data URI.|

**Example**

```ts
let audio = new unifiedDataChannel.Audio();
audio.audioUri = 'schema://com.samples.test/files/test.mp3';
```

## Folder

Represents the folder data. It is a child class of [File](#file) and is used to describe a folder.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| folderUri | string | No| No| URI of the folder.|

**Example**

```ts
let folder = new unifiedDataChannel.Folder();
folder.folderUri = 'schema://com.samples.test/files/folder/';
```

## SystemDefinedRecord

Represents specific data types defined by OpenHarmony. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of OpenHarmony-specific data types. You are advised to use the child class of **SystemDefinedRecord**, for example, [SystemDefinedForm](#systemdefinedform), [SystemDefinedAppItem](#systemdefinedappitem), and [SystemDefinedPixelMap](#systemdefinedpixelmap), to describe OpenHarmony-specific data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| details | Record<string, number \| string \| Uint8Array> | No| Yes| A dictionary type object, where the key is of the string type, and the value can be a number, a string, or a Uint8Array. The default value is an empty dictionary object.|

**Example**

```ts
let sdr = new unifiedDataChannel.SystemDefinedRecord();
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
sdr.details = {
    title: 'recordTitle',
    version: 1,
    content: u8Array,
};
let unifiedData = new unifiedDataChannel.UnifiedData(sdr);
```

## SystemDefinedForm

Represents the service widget data defined by the system. It is a child class of [SystemDefinedRecord](#systemdefinedrecord).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| formId      | number | No| No| Service widget ID.         |
| formName    | string | No| No| Widget name.         |
| bundleName  | string | No| No| Name of the bundle to which the widget belongs.  |
| abilityName | string | No| No| Ability name corresponding to the widget.|
| module      | string | No| No| Name of the module to which the widget belongs.  |

**Example**

```ts
let form = new unifiedDataChannel.SystemDefinedForm();
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
let unifiedData = new unifiedDataChannel.UnifiedData(form);
```

## SystemDefinedAppItem

Represents the data of the home screen icon defined by the system. It is a child class of [SystemDefinedRecord](#systemdefinedrecord).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| appId       | string | No| No| ID of the application, for which the icon is used.     |
| appName     | string | No| No| Name of the application, for which the icon is used.      |
| appIconId   | string | No| No| Image ID of the icon.       |
| appLabelId  | string | No| No| Label ID corresponding to the icon name.   |
| bundleName  | string | No| No| Bundle name corresponding to the icon.|
| abilityName | string | No| No| Application ability name corresponding to the icon.|

**Example**

```ts
let appItem = new unifiedDataChannel.SystemDefinedAppItem();
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
let unifiedData = new unifiedDataChannel.UnifiedData(appItem);
```

## SystemDefinedPixelMap

Represents the image data type corresponding to [PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) defined by the system. It is a child class of [SystemDefinedRecord](#systemdefinedrecord) and holds only binary data of PixelMap.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| rawData | Uint8Array | No| No| Binary data of the **PixelMap** object.|

**Example**

```ts
import { image } from '@kit.ImageKit';  // Module where the PixelMap class is defined.
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

const color = new ArrayBuffer(96); // Create a PixelMap object.
let opts: image.InitializationOptions = {
  editable: true, pixelFormat: 3, size: {
    height: 4, width: 6
  }
}
image.createPixelMap(color, opts, (error, pixelmap) => {
  if (error) {
    console.error('Failed to create pixelmap.');
  } else {
    console.info('Succeeded in creating pixelmap.');
    let arrayBuf = new ArrayBuffer(pixelmap.getPixelBytesNumber());
    pixelmap.readPixelsToBuffer(arrayBuf);
    let u8Array = new Uint8Array(arrayBuf);
    let sdpixel = new unifiedDataChannel.SystemDefinedPixelMap();
    sdpixel.rawData = u8Array;
    let unifiedData = new unifiedDataChannel.UnifiedData(sdpixel);

    // Read the record of the pixelMap type from unifiedData.
    let records = unifiedData.getRecords();
    for (let i = 0; i < records.length; i++) {
      if (records[i].getType() === uniformTypeDescriptor.UniformDataType.OPENHARMONY_PIXEL_MAP) {
        let pixelmapRecord = records[i] as unifiedDataChannel.SystemDefinedPixelMap;
        let newArraybuf = pixelmapRecord.rawData.buffer;
        pixelmap.writeBufferToPixels(newArraybuf).then(() => {
          console.info('Succeeded in writing data from buffer to a pixelMap');
        }).catch((error: BusinessError) => {
          console.error(`Failed to write data from a buffer to a PixelMap. code is ${error.code}, message is ${error.message}`);
        })
      }
    }
  }
})
```

## ApplicationDefinedRecord

Represents the custom data type for applications only. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of custom data types of applications. Applications can extend custom data types based on this class.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| applicationDefinedType | string     | No| No| Application's custom data type identifier, which must start with **ApplicationDefined**.|
| rawData                | Uint8Array | No| No| Binary data of the custom data type.                     |

**Example**

```ts
let record = new unifiedDataChannel.ApplicationDefinedRecord();
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
record.applicationDefinedType = 'ApplicationDefinedType';
record.rawData = u8Array;
let unifiedData = new unifiedDataChannel.UnifiedData(record);
```

## Intention

Enumerates the data channel types supported by the UDMF. It is used to identify different service scenarios, to which the UDMF data channels apply.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name      | Value        | Description     |
|----------|-----------|---------|
| DATA_HUB | 'DataHub' | Public data channel.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|

## Options

Defines the data operation performed by the UDMF. It includes two optional parameters: **intention** and **key**. The two parameters have no default value, and can be left unspecified. For details, see the parameter description of the specific API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core


| Name      | Type                   | Read-Only| Optional| Description                                                                                                                                                                                                                               |
|-----------|-------------------------|----|----|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| intention | [Intention](#intention) | No | Yes | Type of the data channel related to the data operation.                                                                                                                                                                                                                 |
| key       | string                  | No | Yes | Unique identifier of the data object in the UDMF, which can be obtained from the value returned by [insertData](#unifieddatachannelinsertdata).<br>The key consists of **udmf:/**, **intention**, **bundleName**, and **groupId** with a (/) in between, for example, **udmf://DataHub/com.ohos.test/0123456789**.<br>**udmf:/** is fixed, **DataHub** is an enum of **intention**, **com.ohos.test** is the bundle name, and **0123456789** is a group ID randomly generated.|



## unifiedDataChannel.insertData

insertData(options: Options, data: UnifiedData, callback: AsyncCallback&lt;string&gt;): void

Inserts data to the UDMF public data channel. This API uses an asynchronous callback to return the unique identifier of the data inserted.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                        | Mandatory| Description                          |
|----------|----------------------------|----|------------------------------|
| options  | [Options](#options)        | Yes | Configuration parameters. Only the **intention** is required.       |
| data     | [UnifiedData](#unifieddata) | Yes | Data to insert.                       |
| callback | AsyncCallback&lt;string&gt; | Yes | Callback used to return the key (unique identifier) of the data inserted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let plainText = new unifiedDataChannel.PlainText();
plainText.textContent = 'hello world!';
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);

let options: unifiedDataChannel.Options = {
  intention: unifiedDataChannel.Intention.DATA_HUB
}
try {
  unifiedDataChannel.insertData(options, unifiedData, (err, data) => {
    if (err === undefined) {
      console.info(`Succeeded in inserting data. key = ${data}`);
    } else {
      console.error(`Failed to insert data. code is ${err.code},message is ${err.message} `);
    }
  });
  } catch (e) {
    let error: BusinessError = e as BusinessError;
    console.error(`Insert data throws an exception. code is ${error.code},message is ${error.message} `);
}

```

## unifiedDataChannel.insertData

insertData(options: Options, data: UnifiedData): Promise&lt;string&gt;

Inserts data to the UDMF public data channel. This API uses a promise to return the unique identifier of the data inserted.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name    | Type                         | Mandatory| Description                   |
|---------|-----------------------------|----|-----------------------|
| options | [Options](#options)         | Yes | Configuration parameters. Only the **intention** is required.|
| data    | [UnifiedData](#unifieddata) | Yes | Data to insert.                |

**Return value**

| Type                   | Description                               |
|-----------------------|-----------------------------------|
| Promise&lt;string&gt; | Promise used to return the key of the data inserted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let plainText = new unifiedDataChannel.PlainText();
plainText.textContent = 'hello world!';
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);

let options: unifiedDataChannel.Options = {
  intention: unifiedDataChannel.Intention.DATA_HUB
}
try {
  unifiedDataChannel.insertData(options, unifiedData).then((data) => {
    console.info(`Succeeded in inserting data. key = ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to insert data. code is ${err.code},message is ${err.message} `);
  });
} catch (e) {
  let error: BusinessError = e as BusinessError;
  console.error(`Insert data throws an exception. code is ${error.code},message is ${error.message} `);
}
```

## unifiedDataChannel.updateData

updateData(options: Options, data: UnifiedData, callback: AsyncCallback&lt;void&gt;): void

Updates the data in the UDMF public data channel. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                         | Mandatory| Description                                 |
|----------|-----------------------------|----|-------------------------------------|
| options  | [Options](#options)         | Yes | Configuration parameters. Only the value of **key** is required.                    |
| data     | [UnifiedData](#unifieddata) | Yes | New data.                              |
| callback | AsyncCallback&lt;void&gt;   | Yes | Callback used to return the result. If the data is updated successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let plainText = new unifiedDataChannel.PlainText();
plainText.textContent = 'hello world!';
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);

let options: unifiedDataChannel.Options = {
  key: 'udmf://DataHub/com.ohos.test/0123456789'
};

try {
  unifiedDataChannel.updateData(options, unifiedData, (err) => {
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

## unifiedDataChannel.updateData

updateData(options: Options, data: UnifiedData): Promise&lt;void&gt;

Updates the data in the UDMF public data channel. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name    | Type                         | Mandatory| Description             |
|---------|-----------------------------|----|-----------------|
| options | [Options](#options)         | Yes | Configuration parameters. Only the value of **key** is required.|
| data    | [UnifiedData](#unifieddata) | Yes | New data.          |

**Return value**

| Type                 | Description                        |
|---------------------|----------------------------|
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let plainText = new unifiedDataChannel.PlainText();
plainText.textContent = 'hello world!';
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);

let options: unifiedDataChannel.Options = {
  key: 'udmf://DataHub/com.ohos.test/0123456789'
};

try {
  unifiedDataChannel.updateData(options, unifiedData).then(() => {
    console.info('Succeeded in updating data.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to update data. code is ${err.code},message is ${err.message} `);
  });
} catch (e) {
  let error: BusinessError = e as BusinessError;
  console.error(`Update data throws an exception. code is ${error.code},message is ${error.message} `);
}
```

## unifiedDataChannel.queryData

queryData(options: Options, callback: AsyncCallback&lt;Array&lt;UnifiedData&gt;&gt;): void

Queries data in the UDMF public data channel. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                                                           | Mandatory| Description                                                                                                                                                              |
|----------|---------------------------------------------------------------|----|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| options  | [Options](#options)                                           | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.                                                                                                                   |
| callback | AsyncCallback&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Yes | Callback used to return the queried data.<br>If only the **key** is specified in **options**, the data corresponding to the key is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** is returned.<br>If both **intention** and **key** are specified, the intersection of the two is returned, which is the result obtained when only **key** is specified. If there is no intersection between the specified **intention** and **key**, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

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
          if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
            let text = records[j] as unifiedDataChannel.PlainText;
            console.info(`${i + 1}.${text.textContent}`);
          }
        }
      }
    } else {
      console.error(`Failed to query data. code is ${err.code},message is ${err.message} `);
    }
  });
} catch (e) {
  let error: BusinessError = e as BusinessError;
  console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);
}
```

## unifiedDataChannel.queryData

queryData(options: Options): Promise&lt;Array&lt;UnifiedData&gt;&gt;

Queries data in the UDMF public data channel. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                                           |
|---------|---------------------|----|-----------------------------------------------|
| options | [Options](#options) | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.|

**Return value**

| Type                                                     | Description                                                                                                                                 |
|---------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------|
| Promise&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Promise used to return the result.<br>If only the **key** is specified in **options**, the data corresponding to the key is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** is returned.<br>If both **intention** and **key** are specified, the intersection of the two is returned, which is the result obtained when only **key** is specified. If there is no intersection between the specified **intention** and **key**, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let options: unifiedDataChannel.Options = {
  key: 'udmf://DataHub/com.ohos.test/0123456789'
};

try {
  unifiedDataChannel.queryData(options).then((data) => {
    console.info(`Succeeded in querying data. size = ${data.length}`);
    for (let i = 0; i < data.length; i++) {
      let records = data[i].getRecords();
      for (let j = 0; j < records.length; j++) {
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
          let text = records[j] as unifiedDataChannel.PlainText;
          console.info(`${i + 1}.${text.textContent}`);
        }
      }
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to query data. code is ${err.code},message is ${err.message} `);
  });
} catch (e) {
  let error: BusinessError = e as BusinessError;
  console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);
}
```

## unifiedDataChannel.deleteData

deleteData(options: Options, callback: AsyncCallback&lt;Array&lt;UnifiedData&gt;&gt;): void

Deletes data from the UDMF public data channel. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                                                           | Mandatory| Description                                                                                                                                                                                    |
|----------|---------------------------------------------------------------|----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| options  | [Options](#options)                                           | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.                                                                                                                                         |
| callback | AsyncCallback&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Yes | Callback used to return the data deleted.<br>If only the **key** is specified in **options**, the data corresponding to the key deleted is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** deleted is returned.<br>If both **intention** and **key** are specified, the intersection of the two deleted is returned. If there is no intersection between the two, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let options: unifiedDataChannel.Options = {
  intention: unifiedDataChannel.Intention.DATA_HUB
};

try {
  unifiedDataChannel.deleteData(options, (err, data) => {
    if (err === undefined) {
      console.info(`Succeeded in deleting data. size = ${data.length}`);
      for (let i = 0; i < data.length; i++) {
        let records = data[i].getRecords();
        for (let j = 0; j < records.length; j++) {
          if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
            let text = records[j] as unifiedDataChannel.PlainText;
            console.info(`${i + 1}.${text.textContent}`);
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

## unifiedDataChannel.deleteData

deleteData(options: Options): Promise&lt;Array&lt;UnifiedData&gt;&gt;

Deletes data from the UDMF public data channel. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name    | Type                 | Mandatory| Description    |
|---------|---------------------|----|--------|
| options | [Options](#options) | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.|

**Return value**

| Type                                                     | Description                                                                                                                                                         |
|---------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Promise&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Promise used to return the data deleted.<br>If only the **key** is specified in **options**, the data corresponding to the key deleted is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** deleted is returned.<br>If both **intention** and **key** are specified, the intersection of the two deleted is returned. If there is no intersection between the two, an error object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                               |
| ------------ | ------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types.  |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';
import { uniformTypeDescriptor } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let options: unifiedDataChannel.Options = {
  key: 'udmf://DataHub/com.ohos.test/0123456789'
};

try {
  unifiedDataChannel.deleteData(options).then((data) => {
    console.info(`Succeeded in deleting data. size = ${data.length}`);
    for (let i = 0; i < data.length; i++) {
      let records = data[i].getRecords();
      for (let j = 0; j < records.length; j++) {
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
          let text = records[j] as unifiedDataChannel.PlainText;
          console.info(`${i + 1}.${text.textContent}`);
        }
      }
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to delete data. code is ${err.code},message is ${err.message} `);
  });
} catch (e) {
  let error: BusinessError = e as BusinessError;
  console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);
}
```

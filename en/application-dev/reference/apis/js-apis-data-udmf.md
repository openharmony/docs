# @ohos.data.UDMF (Unified Data Management Framework)

The **UDMF** module provides unified data management capabilities, including standard definition of data types, such as text and image. By calling the APIs provided by this module, applications can encapsulate a variety of data into unified data objects.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import UDMF from '@ohos.data.UDMF';
```

## UnifiedDataType

Enumerates the types of the [data records](#unifiedrecord) in the [unifiedData](#unifieddata) object.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name                        | Value                           | Description       |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'Text'                       | Text.    |
| PLAIN_TEXT                 | 'Text.PlainText'             | Plaintext.   |
| HYPERLINK                  | 'Text.Hyperlink'             | Hyperlink.   |
| HTML                       | 'Text.HTML'                  | HyperText Markup Language (HTML).   |
| FILE                       | 'File'                       | File.    |
| IMAGE                      | 'File.Media.Image'           | Image.    |
| VIDEO                      | 'File.Media.Video'           | Video.    |
| FOLDER                     | 'File.Folder'                | Folder.   |
| SYSTEM_DEFINED_RECORD      | 'SystemDefinedType'          | System service data.|
| SYSTEM_DEFINED_FORM        | 'SystemDefinedType.Form'     | Widget.    |
| SYSTEM_DEFINED_APP_ITEM    | 'SystemDefinedType.AppItem'  | Icon.    |
| SYSTEM_DEFINED_PIXEL_MAP   | 'SystemDefinedType.PixelMap' | Pixel map. |
| APPLICATION_DEFINED_RECORD | 'ApplicationDefinedType'     | Application-defined type. |

## UnifiedData

Provides APIs for encapsulating a set of data records.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

### constructor

constructor(record: UnifiedRecord)

A constructor used to create a **UnifiedData** object with a data record.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name| Type                           | Mandatory| Description                                     |
| ------ | ------------------------------- | ---- |-----------------------------------------|
| record | [UnifiedRecord](#unifiedrecord) | Yes  | Data record in the **UnifiedData** object. It is a **UnifiedRecord** child class object.|

**Example**

```js
let text = new UDMF.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new UDMF.UnifiedData(text);
```

### addRecord

addRecord(record: UnifiedRecord): void

Adds a data record to this **UnifiedRecord** object.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name| Type                           | Mandatory| Description                                         |
| ------ | ------------------------------- | ---- |---------------------------------------------|
| record | [UnifiedRecord](#unifiedrecord) | Yes  | Data record to add. It is a **UnifiedRecord** child class object.|

**Example**

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

Obtains all data records from this **UnifiedData** object. The data obtained is of the **UnifiedRecord** type. Before using the data, you need to use [getType](#gettype) to obtain the data type and convert the data type to a child class.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Return value**

| Type                                    | Description                     |
| ---------------------------------------- |-------------------------|
| Array\<[UnifiedRecord](#unifiedrecord)\> | Records in the **UnifiedData** object obtained.|

**Example**

```js
let text = new UDMF.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new UDMF.UnifiedData(text);

let link = new UDMF.Hyperlink();
link.url = 'www.XXX.com';
unifiedData.addRecord(link);

let records = unifiedData.getRecords();
for (let i = 0; i < records.length; i++) {
  let record = records[i];
  if (record.getType() == UDMF.UnifiedDataType.PLAIN_TEXT) {
    let plainText = <UDMF.PlainText> (record);
    console.info(`textContent: ${plainText.textContent}`);
  } else if (record.getType() == UDMF.UnifiedDataType.HYPERLINK) {
    let hyperlink = <UDMF.Hyperlink> (record);
    console.info(`linkUrl: ${hyperlink.url}`);
  }
}
```

## Summary

Defines the summary of a **UnifiedData object**, including the data types and sizes. Currently, it is not supported.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name     | Type                     | Readable| Writable| Description                                                                               |
| --------- | ------------------------- | ---- | ---- |-----------------------------------------------------------------------------------|
| summary   | { [key: string]: number } | Yes  | No  | A directory type object, where **key** indicates the data type (see [UnifiedDataType](#unifieddatatype)), and the value indicates the total size (in bytes) of this type of records in the **UnifiedData** object.|
| totalSize | number                    | Yes  | No  | Total size of all the records in the **UnifiedData** object, in bytes.                                                                    |

## UnifiedRecord

An abstract definition of the data content supported by the UDMF. A **UnifiedRecord** object contains one or more data records, for example, a text record, an image record, or an HTML record.

**UnifiedRecord** is an abstract parent class that does not hold specific data content. It cannot be added to a **UnifiedData** object directly. Instead, a child class with specific content, such as text and image, must be created.

### getType

getType(): string

Obtains the type of this **UnfiedRecord**. The data obtained by [getRecords](#getrecords) from the **UnifiedData** object is a **UnifiedRecord** object. You need to use this API to obtain the specific type of the record, convert the **UnifiedRecord** object to its child class, and call the child class interfaces.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Return value**

| Type  | Description                                                  |
| ------ |------------------------------------------------------|
| string | Data type obtained. For details, see [UnifiedDataType](#unifieddatatype).|

**Example**

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

Represents the text data. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of text data. You are advised to use the child class of **Text**, for example, [PlainText](#plaintext), [Hyperlink](#hyperlink), and [HTML](#html), to describe data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type                     | Readable| Writable| Description                                                                                                                                                 |
| ------- | ------------------------- | ---- | ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------|
| details | { [key: string]: string } | Yes  | Yes  | A dictionary type object, where both the key and value are of the string type and are used to describe the text content. For example, a data object with the following content can be created to describe a text file:<br>{<br>title: 'Title',<br>"content":"Content"<br>}<br>This parameter is optional. The default value is an empty dictionary object.|

**Example**

```js
let text = new UDMF.Text();
text.details = {
  title: 'MyTitle',
  content: 'this is content',
};
let unifiedData = new UDMF.UnifiedData(text);
```

## PlainText

Represents the plaintext data. It is a child class of [Text](#text) and is used to describe plaintext data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Readable| Writable| Description                   |
| ----------- | ------ | ---- | ---- |-----------------------|
| textContent | string | Yes  | Yes  | Plaintext content.               |
| abstract    | string | Yes  | Yes  | Text abstract. This parameter is optional. The default value is an empty string.|

**Example**

```js
let text = new UDMF.PlainText();
text.textContent = 'this is textContent';
text.abstract = 'this is abstract';
```

## Hyperlink

Represents hyperlink data. It is a child class of [Text](#text) and is used to describe data of the hyperlink type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Readable| Writable| Description          |
| ----------- | ------ | ---- | ---- |--------------|
| url         | string | Yes  | Yes  | URL.      |
| description | string | Yes  | Yes  | Description of the linked content. This parameter is optional. The default value is an empty string.|

**Example**

```js
let link = new UDMF.Hyperlink();
link.url = 'www.XXX.com';
link.description = 'this is description';
```

## HTML

Represents the HTML data. It is a child class of [Text](#text) and is used to describe HTML data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name        | Type  | Readable| Writable| Description                   |
| ------------ | ------ | ---- | ---- |-----------------------|
| htmlContent  | string | Yes  | Yes  | Content in HTML format.            |
| plainContent | string | Yes  | Yes  | Plaintext without HTML tags. This parameter is optional. The default value is an empty string.|

**Example**

```js
let html = new UDMF.HTML();
html.htmlContent = '<div><p>Title</p></div>';
html.plainContent = 'this is plainContent';
```

## File

Represents the file data. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of the data of the file type. You are advised to use the child class of **File**, for example, [Image](#image), [Video](#video), and [Folder](#folder), to describe data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name     | Type                       | Readable| Writable| Description                                                                                                                                                  |
|---------|---------------------------| ---- | ---- |------------------------------------------------------------------------------------------------------------------------------------------------------|
| details | { [key: string]: string } | Yes  | Yes  | A dictionary type object, where Both the key and value are of the string type and are used to describe file information. For example, a data object with the following content can be created to describe a file:<br>{<br>"name":"File name",<br>"type":"File type"<br>}<br>This parameter is optional. The default value is an empty dictionary object.|
| uri     | string                    | Yes  | Yes  | URI of the file data.                                                                                                                                            |

**Example**

```js
let file = new UDMF.File();
file.details = {
    name: 'test',
    type: 'txt',
};
file.uri = 'schema://com.samples.test/files/test.txt';
```

## Image

Represents the image data. It is a child class of [File](#file) and is used to describe images.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name    | Type  | Readable| Writable| Description      |
| -------- | ------ | ---- | ---- |----------|
| imageUri | string | Yes  | Yes  | URI of the image.|

**Example**

```js
let image = new UDMF.Image();
image.imageUri = 'schema://com.samples.test/files/test.jpg';
```

## Video

Represents video data. It is a child class of [File](#file) and is used to describe a video file.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name    | Type  | Readable| Writable| Description      |
| -------- | ------ | ---- | ---- |----------|
| videoUri | string | Yes  | Yes  | URI of the video file.|

**Example**

```js
let video = new UDMF.Video();
video.videoUri = 'schema://com.samples.test/files/test.mp4';
```

## Folder

Represents the folder data. It is a child class of [File](#file) and is used to describe a folder.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name    | Type  | Readable| Writable| Description     |
| -------- | ------ | ---- | ---- |---------|
| folderUri | string | Yes  | Yes  | URI of the folder.|

**Example**

```js
let folder = new UDMF.Folder();
folder.folderUri = 'schema://com.samples.test/files/folder/';
```

## SystemDefinedRecord

Represents specific data types defined by OpenHarmony. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of OpenHarmony-specific data types. You are advised to use the child class of **SystemDefinedRecord**, for example, [SystemDefinedForm](#systemdefinedform), [SystemDefinedAppItem](#systemdefinedappitem), and [SystemDefinedPixelMap](#systemdefinedpixelmap), to describe OpenHarmony-specific data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type                      | Readable| Writable| Description                                                        |
| ------- |--------------------------| ---- | ---- | ------------------------------------------------------------ |
| details | { [key: string]: number \| string \| Uint8Array } | Yes  | Yes  | A dictionary type object, where the key is of the string type, and the value can be a number, a string, or a Uint8Array.<br/>This parameter is optional. The default value is an empty dictionary object. |

**Example**

```js
let sdr = new UDMF.SystemDefinedRecord();
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
sdr.details = {
    title: 'recordTitle',
    version: 1,
    content: u8Array,
};
let unifiedData = new UDMF.UnifiedData(sdr);
```

## SystemDefinedForm

Represents the widget data. It is a child class of [SystemDefinedRecord](#systemdefinedrecord).

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Readable| Writable| Description            |
| ----------- | ------ | ---- | ---- |----------------|
| formId      | number | Yes  | Yes  | Service widget ID.         |
| formName    | string | Yes  | Yes  | Widget name.         |
| bundleName  | string | Yes  | Yes  | Name of the bundle to which a widget belongs.  |
| abilityName | string | Yes  | Yes  | Ability name corresponding to the widget.|
| module      | string | Yes  | Yes  | Name of the module to which the widget belongs.  |

**Example**

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

Represents the icon data. It is a child class of [SystemDefinedRecord](#systemdefinedrecord).

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Readable| Writable| Description             |
| ----------- | ------ | ---- | ---- |-----------------|
| appId       | string | Yes  | Yes  | ID of the application, for which the icon is used.     |
| appName     | string | Yes  | Yes  | Name of the application, for which the icon is used.      |
| appIconId   | string | Yes  | Yes  | Image ID of the icon.       |
| appLabelId  | string | Yes  | Yes  | Label ID corresponding to the icon name.   |
| bundleName  | string | Yes  | Yes  | Bundle name corresponding to the icon.|
| abilityName | string | Yes  | Yes  | Application ability name corresponding to the icon.|

**Example**

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

Represents the image data corresponding to the [PixelMap](js-apis-image.md#pixelmap7) defined by OpenHarmony. It is a child class of [SystemDefinedRecord](#systemdefinedrecord) and used to store only the binary data of **PixelMap**.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type      | Readable| Writable| Description               |
| ------- | ---------- | ---- | ---- |-------------------|
| rawData | Uint8Array | Yes  | Yes  | Binary data of the **PixelMap** object.|

**Example**

```js
import image from '@ohos.multimedia.image'; // Module where the PixelMap class is defined.

const color = new ArrayBuffer(96); // Create a PixelMap object.
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

Represents the custom data type for applications only. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of custom data types of applications. Applications can extend custom data types based on this class.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name                    | Type        | Readable| Writable| Description                                   |
|------------------------|------------| ---- | ---- |---------------------------------------|
| applicationDefinedType | string     | Yes  | Yes  | Application's custom data type identifier, which must start with **ApplicationDefined**.|
| rawData                | Uint8Array | Yes  | Yes  | Binary data of the custom data type.                     |

**Example**

```js
let record = new UDMF.ApplicationDefinedRecord();
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
record.applicationDefinedType = 'ApplicationDefinedType';
record.rawData = u8Array;
let unifiedData = new UDMF.UnifiedData(record);
```

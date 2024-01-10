# @ohos.data.unifiedDataChannel (Unified Data Channel)

As a part of the Unified Data Management Framework (UDMF), the **unifiedDataChannel** module provides unified data channels and standard data access interfaces for many-to-many data sharing across applications. It also provides definitions for uniform data types, such as text and image, to streamline data interaction between different applications and minimize the workload of data type adaptation.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
```

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
let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new unifiedDataChannel.UnifiedData(text);
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

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Return value**

| Type                                    | Description                     |
| ---------------------------------------- |-------------------------|
| Array\<[UnifiedRecord](#unifiedrecord)\> | Records in the **UnifiedData** object obtained.|

**Example**

```js
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';

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

## Summary

Defines the summary of a **UnifiedData object**, including the data types and sizes. Currently, it is not supported.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name     | Type                     | Readable| Writable| Description                                                                               |
| --------- | ------------------------- | ---- | ---- |-----------------------------------------------------------------------------------|
| summary   | { [key: string]: number } | Yes  | No  | Dictionary type object, where the key indicates the data type (see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype)), and the value indicates the total size (in bytes) of this type of records in the **UnifiedData** object.|
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
| string | Data type obtained. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype).|

**Example**

```js
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';

let text = new unifiedDataChannel.PlainText();
text.textContent = 'this is textContent of text';
let unifiedData = new unifiedDataChannel.UnifiedData(text);

let records = unifiedData.getRecords();
if (records[0].getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
  let plainText = records[0] as unifiedDataChannel.PlainText;
  console.info(`textContent: ${plainText.textContent}`);
}
```

## Text

Represents the text data. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of text data. You are advised to use the child class of **Text**, for example, [PlainText](#plaintext), [Hyperlink](#hyperlink), and [HTML](#html), to describe data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type                     | Readable| Writable| Description                                                                                                                                                 |
| ------- | ------------------------- | ---- | ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------|
| details | { [key: string]: string } | Yes  | Yes  | A dictionary type object, where both the key and value are of the string type and are used to describe the text content. For example, a data object with the following content can be created to describe a text file:<br>{<br>"title":"Title",<br>"content":"Content"<br>}<br>This parameter is optional. The default value is an empty dictionary object.|

**Example**

```js
let text = new unifiedDataChannel.Text();
text.details = {
  title: 'MyTitle',
  content: 'this is content',
};
let unifiedData = new unifiedDataChannel.UnifiedData(text);
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
let text = new unifiedDataChannel.PlainText();
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
let link = new unifiedDataChannel.Hyperlink();
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
let html = new unifiedDataChannel.HTML();
html.htmlContent = '<div><p>Title</p></div>';
html.plainContent = 'this is plainContent';
```

## File

Represents the file data. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of the data of the file type. You are advised to use the child class of **File**, for example, [Image](#image), [Video](#video), and [Folder](#folder), to describe data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name     | Type                       | Readable| Writable| Description                                                                                                                                                  |
|---------|---------------------------| ---- | ---- |------------------------------------------------------------------------------------------------------------------------------------------------------|
| details | { [key: string]: string } | Yes  | Yes  | A dictionary type object, where both the key and value are of the string type and are used to describe file information. For example, a data object with the following content can be created to describe a file:<br>{<br>"name":"File name",<br>"type":"File type"<br>}<br>This parameter is optional. The default value is an empty dictionary object.|
| uri     | string                    | Yes  | Yes  | URI of the file data.                                                                                                                                            |

**Example**

```js
let file = new unifiedDataChannel.File();
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
let image = new unifiedDataChannel.Image();
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
let video = new unifiedDataChannel.Video();
video.videoUri = 'schema://com.samples.test/files/test.mp4';
```

## Audio

Represents video data. It is a child class of [File](#file) and is used to describe a video file.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name      | Type    | Readable| Writable| Description      |
|----------|--------|----|----|----------|
| audioUri | string | Yes | Yes | Audio data URI.|

**Example**

```js
let audio = new unifiedDataChannel.Audio();
audio.audioUri = 'schema://com.samples.test/files/test.mp3';
```

## Folder

Represents the folder data. It is a child class of [File](#file) and is used to describe a folder.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name    | Type  | Readable| Writable| Description     |
| -------- | ------ | ---- | ---- |---------|
| folderUri | string | Yes  | Yes  | URI of the folder.|

**Example**

```js
let folder = new unifiedDataChannel.Folder();
folder.folderUri = 'schema://com.samples.test/files/folder/';
```

## SystemDefinedRecord

Represents specific data types defined by OpenHarmony. It is a child class of [UnifiedRecord](#unifiedrecord) and a base class of OpenHarmony-specific data types. You are advised to use the child class of **SystemDefinedRecord**, for example, [SystemDefinedForm](#systemdefinedform), [SystemDefinedAppItem](#systemdefinedappitem), and [SystemDefinedPixelMap](#systemdefinedpixelmap), to describe OpenHarmony-specific data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type                      | Readable| Writable| Description                                                        |
| ------- |--------------------------| ---- | ---- | ------------------------------------------------------------ |
| details | { [key: string]: number \| string \| Uint8Array } | Yes  | Yes  | A dictionary type object, where the key is of the string type, and the value can be a number, a string, or a Uint8Array.<br/>This parameter is optional. The default value is an empty dictionary object.|

**Example**

```js
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

Represents the service widget data defined by the system, which is a child class of [SystemDefinedRecord](#systemdefinedrecord).

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Readable| Writable| Description            |
| ----------- | ------ | ---- | ---- |----------------|
| formId      | number | Yes  | Yes  | Service widget ID.         |
| formName    | string | Yes  | Yes  | Widget name.         |
| bundleName  | string | Yes  | Yes  | Name of the bundle to which the widget belongs.  |
| abilityName | string | Yes  | Yes  | Ability name corresponding to the widget.|
| module      | string | Yes  | Yes  | Name of the module to which the widget belongs.  |

**Example**

```js
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

Represents the image data corresponding to the [PixelMap](js-apis-image.md#pixelmap7) defined by OpenHarmony. It is a child class of [SystemDefinedRecord](#systemdefinedrecord) and used to store only the binary data of **PixelMap**.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name   | Type      | Readable| Writable| Description               |
| ------- | ---------- | ---- | ---- |-------------------|
| rawData | Uint8Array | Yes  | Yes  | Binary data of the **PixelMap** object.|

**Example**

```js
import image from '@ohos.multimedia.image'; // Module where the PixelMap class is defined.

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
| DATA_HUB | 'DataHub' | Public data channel.|

## Options

Defines the data operation performed by the UDMF. It includes two optional parameters: **intention** and **key**. The two parameters have no default value, and can be left unspecified. For details, see the parameter description of the specific API.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core


| Name      | Type                     | Readable| Writable| Mandatory| Description                                                                                                                                                                                                                               |
|-----------|-------------------------|----|----|----|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| intention | [Intention](#intention) | Yes | Yes | No | Type of the data channel related to the data operation.                                                                                                                                                                                                                 |
| key       | string                  | Yes | Yes | No | Unique identifier of the data object in the UDMF, which can be obtained from the value returned by [insertData](#unifieddatachannelinsertdata).<br>The key consists of **udmf:/**, **intention**, **bundleName**, and **groupId** with a (/) in between, for example, **udmf://DataHub/com.ohos.test/0123456789**.<br>**udmf:/** is fixed, **DataHub** is an enum of **intention**, **com.ohos.test** is the bundle name, and **0123456789** is a group ID randomly generated.|



## unifiedDataChannel.insertData

insertData(options: Options, data: UnifiedData, callback: AsyncCallback&lt;string&gt;): void

Inserts data to the UDMF public data channel. This API uses an asynchronous callback to return the unique identifier of the data inserted.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                        | Mandatory| Description                          |
|----------|----------------------------|----|------------------------------|
| options  | [Options](#options)        | Yes | Configuration parameters. Only the **intention** is required.       |
| data     | [UnifiedData](#unifieddata) | Yes | Data to insert.                       |
| callback | AsyncCallback&lt;string&gt; | Yes | Callback invoked to return the key (unique identifier) of the data inserted.|

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import { BusinessError } from '@ohos.base';

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

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import { BusinessError } from '@ohos.base';

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

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                         | Mandatory| Description                                 |
|----------|-----------------------------|----|-------------------------------------|
| options  | [Options](#options)         | Yes | Configuration parameters. Only the value of **key** is required.                    |
| data     | [UnifiedData](#unifieddata) | Yes | New data.                              |
| callback | AsyncCallback&lt;void&gt;   | Yes | Callback invoked to return the result. If the data is updated successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import { BusinessError } from '@ohos.base';

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

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import { BusinessError } from '@ohos.base';

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

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                                                           | Mandatory| Description                                                                                                                                                              |
|----------|---------------------------------------------------------------|----|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| options  | [Options](#options)                                           | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.                                                                                                                   |
| callback | AsyncCallback&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Yes | Callback invoked to return the queried data.<br>If only the **key** is specified in **options**, the data corresponding to the key is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** is returned.<br>If both **intention** and **key** are specified, the intersection of the two is returned, which is the result obtained when only **key** is specified. If there is no intersection between the specified **intention** and **key**, an error object is returned.|

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

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

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                                           |
|---------|---------------------|----|-----------------------------------------------|
| options | [Options](#options) | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.|

**Return value**

| Type                                                     | Description                                                                                                                                 |
|---------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------|
| Promise&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Promise used to return the result.<br>If only the **key** is specified in **options**, the data corresponding to the key is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** is returned.<br>If both **intention** and **key** are specified, the intersection of the two is returned, which is the result obtained when only **key** is specified. If there is no intersection between the specified **intention** and **key**, an error object is returned.|

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

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

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name     | Type                                                           | Mandatory| Description                                                                                                                                                                                    |
|----------|---------------------------------------------------------------|----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| options  | [Options](#options)                                           | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.                                                                                                                                         |
| callback | AsyncCallback&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Yes | Callback invoked to return the data deleted.<br>If only the **key** is specified in **options**, the data corresponding to the key deleted is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** deleted is returned.<br>If both **intention** and **key** are specified, the intersection of the two deleted is returned. If there is no intersection between the two, an error object is returned.|

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

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

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

**Parameters**

| Name    | Type                 | Mandatory| Description    |
|---------|---------------------|----|--------|
| options | [Options](#options) | Yes | Configuration parameters. Both the **key** and **intention** are optional, and the return value varies depending on the parameters passed in.|

**Return value**

| Type                                                     | Description                                                                                                                                                         |
|---------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Promise&lt;Array&lt;[UnifiedData](#unifieddata)&gt;&gt; | Promise used to return the data deleted.<br>If only the **key** is specified in **options**, the data corresponding to the key deleted is returned.<br>If only the **intention** is specified in **options**, all data in the **intention** deleted is returned.<br>If both **intention** and **key** are specified, the intersection of the two deleted is returned. If there is no intersection between the two, an error object is returned.|

**Example**

```ts
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
import { BusinessError } from '@ohos.base';

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

# @ohos.file.picker (Picker)

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **picker** module encapsulates APIs of **PhotoViewPicker**, **DocumentViewPicker**, and **AudioViewPicker** to provide capabilities for selecting and saving images and videos, documents, and audio clips. The application can select the picker as required. The APIs of this module must be called in a UIAbility. Otherwise, the **photoPicker** or **FilePicker** application cannot be started.

## Modules to Import

```ts
import  { picker } from '@kit.CoreFileKit';
```

## DocumentViewPicker

Provides APIs for selecting and saving documents in different formats. Before using the APIs of **DocumentViewPicker**, you need to create a **DocumentViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>12+</sup>

constructor(context: Context)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create a **DocumentViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getContext](../apis-arkui/js-apis-getContext.md).

**Example**

```ts
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            let context = getContext (this) as common.Context; // Ensure that getContext (this) returns UIAbilityContext.
            let documentPicker = new picker.DocumentViewPicker(context);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### constructor<sup>12+</sup>

constructor()

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create a **DocumentViewPicker** instance. This constructor is not recommended because there is a possibility that the operation fails.

**Example**

```ts
let documentPicker = new picker.DocumentViewPicker(); // Construction without parameter is not recommended. There is a possibility that the DocumentViewPicker instance fails to start.
```

### select

select(option?: DocumentSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **documentPicker** page for the user to select one or more documents. This API uses a promise to return the result. You can pass in **DocumentSelectOptions**.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | No  | Options for selecting documents. If this parameter is not specified, the **documentPicker** page is displayed by default.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the documents selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example07(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    }).catch((err: BusinessError) => {
      console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(option: DocumentSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to select one or more documents. This API uses an asynchronous callback to return the result. You can pass in **DocumentSelectOptions**.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | Yes  | Options for selecting documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example08(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.select(documentSelectOptions, (err: BusinessError, documentSelectResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to select one or more documents. This API uses an asynchronous callback to return the result.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example09(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.select((err: BusinessError, documentSelectResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option?: DocumentSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **documentPicker** page for the user to save one or more documents. This API uses a promise to return the result. You can pass in **DocumentSaveOptions** to specify the file names to save.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | No  | Options for saving the documents. If this parameter is not specified, a **documentPicker** page will be displayed for the user to enter the names of the documents to save.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the documents saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example10(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    }).catch((err: BusinessError) => {
      console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option: DocumentSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to save one or more documents. This API uses an asynchronous callback to return the result. You can pass in **DocumentSaveOptions** to specify the file names to save.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | Yes  | Options for saving the documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example11(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save(documentSaveOptions, (err: BusinessError, documentSaveResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to save one or more documents. This API uses an asynchronous callback to return the result.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example12(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save((err: BusinessError, documentSaveResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('DocumentViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

## AudioViewPicker

Provides APIs for selecting and saving audio clips. Before using the APIs of **AudioViewPicker**, you need to create an **AudioViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>12+</sup>

constructor(context: Context)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create an **AudioViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getContext](../apis-arkui/js-apis-getContext.md).

**Example**

```ts
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            let context = getContext (this) as common.Context; // Ensure that getContext (this) returns UIAbilityContext.
            let audioPicker = new picker.AudioViewPicker(context);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
### constructor<sup>12+</sup>

constructor()

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create an **AudioViewPicker** instance. This constructor is not recommended because there is a possibility that the operation fails.

**Example**

```ts
let audioPicker = new picker.AudioViewPicker(); // Construction without parameter is not recommended. There is a possibility that the AudioViewPicker instance fails to start.
```

### select

select(option?: AudioSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses a promise to return the result. You can pass in **AudioSelectOptions**.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | No  | Options for selecting the audio clips. If this parameter is not specified, the **audioPicker** page is displayed by default. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example13(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    }).catch((err: BusinessError) => {
      console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(option: AudioSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses an asynchronous callback to return the result. You can pass in **AudioSelectOptions**.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | Yes  | Options for selecting audio clips.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example14(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.select(audioSelectOptions, (err: BusinessError, audioSelectResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses an asynchronous callback to return the result.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example15(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.select((err: BusinessError, audioSelectResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option?: AudioSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses a promise to return the result. You can pass in **AudioSaveOptions** to specify the file names of the audio clips to save.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | No  | Options for saving audio clips. If this parameter is not specified, an **audioPicker** page will be displayed for the user to enter the names of the files to save.|

**Return value**

| Type                           | Description   |
| ----------------------------- | ---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the audio clips saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example16(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.save(audioSaveOptions).then((audioSaveResult: Array<string>) => {
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult))
    }).catch((err: BusinessError) => {
      console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(option: AudioSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses an asynchronous callback to return the result. You can pass in **AudioSaveOptions** to specify the file names of the audio clips to save.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | Yes  | Options for saving audio clips.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example17(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.save(audioSaveOptions, (err: BusinessError, audioSaveResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses an asynchronous callback to return the result.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example18(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.save((err: BusinessError, audioSaveResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('AudioViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

## DocumentSelectMode<sup>11+</sup>

Enumerates the types of files that can be selected by Picker.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| FILE  | 0  | File. |
| FOLDER | 1  | Folder. |
| MIXED | 2  | File and folder. |

## DocumentSelectOptions

Defines the options for selecting documents.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Mandatory| Description                                      |
| :---------------------- |---------------------------------------------| ---- |------------------------------------------|
| maxSelectNumber<sup>10+</sup>       | number                                      | No  | Maximum number of documents that can be selected.<br>Value range: 1 to 500.<br>Only the devices that have the required system capability can select folders, and only one folder can be selected at a time. <br>Default value: **1**. <br/>**System capability**: SystemCapability.FileManagement.UserFileService |
| defaultFilePathUri<sup>10+</sup>    | string                                      | No  | Path of the documents or folder to select.                           |
| fileSuffixFilters<sup>10+</sup>     | Array&lt;string&gt;                         | No  | File name extension types of the documents to select. <br/>The value is a string array. Each element specifies an option, which includes at most two parts with a vertical bar (\|) in between. The first part is the description (optional), and the second part is the file name extension information. If there is no "\|", the option does not have the description. Multiple file name extensions separated by a commas (,) are allowed in an option. The number of elements in an string array cannot exceed 100. <br/>By default, all documents are selected.<br/>This parameter is available only to the devices that have the required system capability.  <br/>**System capability**: SystemCapability.FileManagement.UserFileService |
| selectMode<sup>11+</sup>         | [DocumentSelectMode](#documentselectmode11) | No  | Resource types that can be selected, for example, file, folder, or both. The default value is **File**.<br/>This parameter is available only to the devices that have the required system capability. <br/>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |
| authMode<sup>12+</sup>    | boolean                              | No  | Whether to start Picker.<br>Default value: **false**. <br/>If **authMode** is **true**, **defaultFilePathUri** is mandatory, which specifies the URI of the file allowed to access. <br/>This parameter is available only to the devices that have the required system capability.<br>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |

## DocumentPickerMode<sup>12+</sup>

Enumerates the types of files that can be selected by Picker.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| DEFAULT  | 0  | Standard mode.|
| DOWNLOAD | 1  | Download mode.|

## DocumentSaveOptions

Defines the options for saving documents.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames            | Array&lt;string&gt;    | No  | Names of the documents to save. If this parameter is not specified, the user needs to enter the document names.  |
| defaultFilePathUri<sup>10+</sup>    | string  | No  | Path of the documents or folder to save. |
| fileSuffixChoices<sup>10+</sup>     | Array&lt;string&gt; | No  | File name extensions of the documents to save.<br/>The value is a string array. Each element specifies an option, which includes at most two parts with a vertical bar which includes at most two parts with a vertical bar (\|) in between. The first part is the description, and the second part is the file name extension information. If there is no "\|", the option does not have the description.<br/>By default, all documents are saved. |
| pickerMode<sup>12+</sup>     | [DocumentPickerMode](#documentpickermode12) | No  | Mode for starting Picker.<br>Default value: **DEFAULT**. <br/>If **pickerMode** is **DOWNLOAD**, the settings of **newFileNames**, **defaultFilePathUri**, and **fileSuffixChoices** do not take effect. |

## AudioSelectOptions

Defines the options for selecting audio clips.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService
| Name                   | Type                                         | Mandatory| Description                                      |
| :---------------------- |---------------------------------------------| ---- |------------------------------------------|
| maxSelectNumber<sup>12+</sup>       | number                                      | No  | Maximum number of audio clips that can be selected.<br>Default value: **1**<br>Value range: 1 to 500|

## AudioSaveOptions

Defines the options for saving audio clips.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | No | Names of the audio clips to save. If this parameter is not specified, the user needs to enter the file names.|

## PhotoViewPicker<sup>(deprecated)</sup>

Provides APIs for selecting and saving images/videos. You are advised to use [PhotoViewPicker of PhotoAccessHelper](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker) to select files. Before using the APIs of **PhotoViewPicker**, you need to create a **PhotoViewPicker** instance.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker) instead.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>12+</sup>

constructor(context: Context)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create a **PhotoViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getContext](../apis-arkui/js-apis-getContext.md).

**Example**

```ts
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
@Entry
@Component
struct Index {
  @State message: string = 'hello World';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(()=>{
            let context = getContext (this) as common.Context; // Ensure that getContext (this) returns UIAbilityContext.
            let photoPicker = new picker.PhotoViewPicker(context);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### constructor<sup>12+</sup>

constructor()

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create a **PhotoViewPicker** instance. This constructor is not recommended because there is a possibility that the operation fails.

**Example**

```ts
let photoPicker = new picker.PhotoViewPicker(); // Construction without parameter is not recommended. There is a possibility that the PhotoViewPicker instance fails to start.
```

### select<sup>(deprecated)</sup>

select(option?: PhotoSelectOptions): Promise&lt;PhotoSelectResult&gt;

Starts a **photoPicker** page for the user to select one or more images/videos. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/js-apis-photoAccessHelper.md#select) instead.
>
> The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptionsdeprecated) | No  | Options for selecting images/videos. By default, images and videos are selected, and the maximum number of files that can be selected is 50.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt; | Promise used to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example01(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.select(photoSelectOptions).then((photoSelectResult: picker.PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    }).catch((err: BusinessError) => {
      console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select<sup>(deprecated)</sup>

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

Starts a **photoPicker** page for the user to select one or more images/videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/js-apis-photoAccessHelper.md#select-1) instead.
>
> The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptionsdeprecated) | Yes  | Options for selecting images/videos.|
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt;      | Yes  | Callback invoked to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example02(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.select(photoSelectOptions, (err: BusinessError, photoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select<sup>(deprecated)</sup>

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

Starts a **photoPicker** page for the user to select one or more images/videos. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/js-apis-photoAccessHelper.md#select-2) instead.
>
> The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt;      | Yes  | Callback invoked to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example03(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.select((err: BusinessError, photoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save<sup>(deprecated)</sup>

save(option?: PhotoSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **photoPicker** page for the user to save one or more images/videos. This API uses a promise to return the result. You can pass in **PhotoSaveOptions** to specify the file names of the images/videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebutton) instead.
>
> This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptionsdeprecated) | No  | Options for saving files. If this parameter is not specified, a **photoPicker** page will be displayed for the user to enter the names of the files to save.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example04(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.save(photoSaveOptions).then((photoSaveResult: Array<string>) => {
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    }).catch((err: BusinessError) => {
      console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
      console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save<sup>(deprecated)</sup>

save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **photoPicker** page for the user to save one or more images/videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSaveOptions** to specify the file names of the images/videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebutton) instead.
>
> This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptionsdeprecated) | Yes  | Options for saving images/videos.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example05(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg','PhotoViewPicker02.mp4'];
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.save(photoSaveOptions, (err: BusinessError, photoSaveResult: Array<string>) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### save<sup>(deprecated)</sup>

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **photoPicker** page for the user to save one or more images/videos. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebutton) instead.
>
> This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example06(context: common.Context) {// Ensure that context is converted from UIAbilityContext.
  try {
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.save((err: BusinessError, photoSaveResult: Array<string>) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

## PhotoViewMIMETypes<sup>(deprecated)</sup>

Enumerates the media file types that can be selected.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewMIMETypes](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewmimetypes) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| IMAGE_TYPE  |  'image/*' | Image. |
| VIDEO_TYPE |  'video/*' | Video. |
| IMAGE_VIDEO_TYPE |  '\*/*' | Image and video. |

## PhotoSelectOptions<sup>(deprecated)</sup>

Defines the options for selecting images/videos.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoSelectOptions](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoselectoptions) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType              | [PhotoViewMIMETypes](#photoviewmimetypesdeprecated)   | No  | Types of the media files to select. **IMAGE_VIDEO_TYPE** is used by default. |
| maxSelectNumber       | number | No  | Maximum number of media files to select. The default value is **50**, and the maximum value is **500**.     |

## PhotoSelectResult<sup>(deprecated)</sup>

Defines information about the images/videos selected.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoSelectResult](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoselectresult) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory| Description                          |
| ----------------------- | ------------------- | ----| ------------------------------ |
| photoUris        | Array&lt;string&gt;    | Yes  | Array of the URIs of the images/videos selected. This URI array can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |
| isOriginalPhoto        | boolean    | Yes  | Whether the selected image is the original one. The value **true** means the selected image is the original one, and **false** means the opposite. |

## PhotoSaveOptions<sup>(deprecated)</sup>

Defines the options for saving images or videos.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. There is no substitute API.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | No | Names of the files to save. If this parameter is not specified, the user needs to enter the file names.|

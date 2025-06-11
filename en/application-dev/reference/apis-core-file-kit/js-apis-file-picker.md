# @ohos.file.picker (Picker)

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **Picker** module encapsulates APIs such as **DocumentViewPicker**, **AudioViewPicker**, and **PhotoViewPicker** to provide capabilities of selecting and saving files of different types. An application can select the API as required. The APIs of this module must be called in UIAbility. Otherwise, the **FilePicker**, **AudioPicker**, or **PhotoPicker** cannot be started.
Chinese characters and non-digit characters in the path are compiled into the corresponding ASCII code and concatenated to the URI returned by calling these APIs.

## Modules to Import

```ts
import  { picker } from '@kit.CoreFileKit';
```

## DocumentViewPicker

Provides APIs for selecting and saving documents in different formats. Before using the APIs of **DocumentViewPicker**, you need to create a **DocumentViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>12+</sup>

constructor(context: Context)

A constructor used to create a **DocumentViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getHostContext](../apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context| Yes  | Application context (only **UIAbilityContext** is supported). For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|

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
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
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

A constructor used to create a **DocumentViewPicker** instance. This constructor is not recommended due to the potential risk of operation failure.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let documentPicker = new picker.DocumentViewPicker(); // Construction without parameter is not recommended. There is a possibility that the DocumentViewPicker instance fails to start.
```

### constructor<sup>13+</sup>

constructor(context: Context, window: window.Window)

A constructor used to create a **DocumentViewPicker** object in a window created by an application. In other scenarios, you are advised to use **constructor(context: Context)** to create a **DocumentViewPicker** object.

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context| Yes  | Application context (only **UIAbilityContext** is supported). For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| window  | [window.Window](../apis-arkui/js-apis-window.md#window)  | Yes  | Window instance created by the application.|

> **NOTE**
>
> Currently, only mobile phones are supported.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
import { window } from '@kit.ArkUI';
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
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
            let windowClass: window.Window | undefined = undefined;
            windowClass = window.findWindow('test'); // Ensure that the window has been created. Here, 'test' is the value of the name parameter when the window is created.
            let documentPicker = new picker.DocumentViewPicker(context, windowClass);
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### select

select(option?: DocumentSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **documentPicker** page for the user to select one or more documents. This API uses a promise to return the result. You can pass in **DocumentSelectOptions** to specify the URIs of the documents to select.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example07(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.select(documentSelectOptions).then((documentSelectResult: Array<string>) => {
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    }).catch((err: BusinessError) => {
      console.error(`DocumentViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### select

select(option: DocumentSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to select one or more documents. This API uses an asynchronous callback to return the result. You can pass in **DocumentSelectOptions** to specify the URIs of the documents to select.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example08(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.select(documentSelectOptions, (err: BusinessError, documentSelectResult: Array<string>) => {
      if (err) {
        console.error(`DocumentViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to select one or more documents. This API uses an asynchronous callback to return the URIs of the documents selected.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example09(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.select((err: BusinessError, documentSelectResult: Array<string>) => {
      if (err) {
        console.error(`DocumentViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('DocumentViewPicker.select successfully, documentSelectResult uri: ' + JSON.stringify(documentSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save

save(option?: DocumentSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **documentPicker** page for the user to save one or more documents. This API uses a promise to return the result. You can pass in **DocumentSaveOptions** to specify the URIs of the documents to save.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example10(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    }).catch((err: BusinessError) => {
      console.error(`DocumentViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save

save(option: DocumentSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to save one or more documents. This API uses an asynchronous callback to return the result. You can pass in **DocumentSaveOptions** to specify the URIs of the documents to save.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example11(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save(documentSaveOptions, (err: BusinessError, documentSaveResult: Array<string>) => {
      if (err) {
        console.error(`DocumentViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **documentPicker** page for the user to save one or more documents. This API uses an asynchronous callback to return the URIs of the documents to save.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example12(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save((err: BusinessError, documentSaveResult: Array<string>) => {
      if (err) {
        console.error(`DocumentViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### getSelectedIndex<sup>14+</sup>

getSelectedIndex(): number

Obtains the index of the file suffix type of the file saved.

Only 2-in-1 devices are supported.

This method takes effect only when used with [save()](#save).

This method can be used only after [DocumentSaveOptions.fileSuffixChoices](#documentsaveoptions) is configured.

The index (number) returned by this method indicates the location of the file suffix specified in [DocumentSaveOptions.fileSuffixChoices](#documentsaveoptions). If no file suffix is specified, **getSelectedIndex()** returns **-1**.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function exampleIndex(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    // Name of the file to save.
    documentSaveOptions.newFileNames = ['DocumentViewPicker01'];
    // File suffix of the file to save.
    documentSaveOptions.fileSuffixChoices = ['txt', 'mp4', 'pdf'];
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
      if (documentSaveOptions.fileSuffixChoices != undefined && documentSaveResult != undefined) {
        // Obtain the index of the file suffix type of the file saved.
        let index = documentPicker.getSelectedIndex();
        // Obtain the file suffix type of the file saved.
        let selectedsuffix = documentSaveOptions.fileSuffixChoices[index];
        console.info ('DocumentViewPicker.save selectedsuffix is ' + selectedsuffix);
      }
      console.info('DocumentViewPicker.save successfully, documentSaveResult uri: ' + JSON.stringify(documentSaveResult));
    }).catch((err: BusinessError) => {
      console.error(`DocumentViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`DocumentViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

## AudioViewPicker

Provides APIs for selecting and saving audio clips. Before using the APIs of **AudioViewPicker**, you need to create an **AudioViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>12+</sup>

constructor(context: Context)

A constructor used to create an **AudioViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getHostContext](../apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context| Yes  | Application context (only **UIAbilityContext** is supported). For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|

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
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
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

A constructor used to create an **AudioViewPicker** instance. This constructor is not recommended due to the potential risk of operation failure.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let audioPicker = new picker.AudioViewPicker(); // Construction without parameter is not recommended. There is a possibility that the AudioViewPicker instance fails to start.
```

### select

select(option?: AudioSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses a promise to return the result. You can pass in **AudioSelectOptions** to specify the URIs of the audio clips to select.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | No  | Options for selecting audio clips. If this parameter is not specified, the **audioPicker** page is displayed by default. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example13(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.select(audioSelectOptions).then((audioSelectResult: Array<string>) => {
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    }).catch((err: BusinessError) => {
      console.error(`AudioViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`AudioViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### select

select(option: AudioSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses an asynchronous callback to return the result. You can pass in **AudioSelectOptions** to specify the URIs of the audio clips to select.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

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
async function example14(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.select(audioSelectOptions, (err: BusinessError, audioSelectResult: Array<string>) => {
      if (err) {
        console.error(`AudioViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`AudioViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses an asynchronous callback to return the URIs of the audio clips selected.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

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
async function example15(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.select((err: BusinessError, audioSelectResult: Array<string>) => {
      if (err) {
        console.error(`AudioViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('AudioViewPicker.select successfully, audioSelectResult uri: ' + JSON.stringify(audioSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`AudioViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save

save(option?: AudioSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses a promise to return the result. You can pass in **AudioSaveOptions** to specify the URIs of the audio clips to save.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example16(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.save(audioSaveOptions).then((audioSaveResult: Array<string>) => {
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult))
    }).catch((err: BusinessError) => {
      console.error(`AudioViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`AudioViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save

save(option: AudioSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses an asynchronous callback to return the result. You can pass in **AudioSaveOptions** to specify the URIs of the audio clips to save.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example17(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.save(audioSaveOptions, (err: BusinessError, audioSaveResult: Array<string>) => {
      if (err) {
        console.error(`AudioViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`AudioViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses an asynchronous callback to return the URIs of the audio clips saved.

**NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
async function example18(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.save((err: BusinessError, audioSaveResult: Array<string>) => {
      if (err) {
        console.error(`AudioViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
        console.error(`AudioViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

## DocumentSelectMode<sup>11+</sup>

Enumerates the types of documents selected.

Only 2-in-1 devices are supported.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| FILE  | 0  | File (default).|
| FOLDER | 1  | Folder. |
| MIXED | 2  | Mixed type of files and folders. |

## DocumentSelectOptions

Defines the options for selecting documents.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| maxSelectNumber<sup>10+</sup>       | number                                      | No  | Yes| Maximum number of documents that can be selected.<br>Value range: 1 to 500.<br>Only the devices with the required system capability can select directories, and only one directory can be selected at a time. <br>Default value: **1**.<br>**System capability**: SystemCapability.FileManagement.UserFileService |
| defaultFilePathUri<sup>10+</sup>    | string                                      | No  |  Yes| Path of the document or directory to select. It is empty by default (the recently opened page is displayed).          |
| fileSuffixFilters<sup>10+</sup>     | Array&lt;string&gt;                         | No  |  Yes| Document suffix of the document to select.<br>The value is a string array. Each element specifies an option, which includes at most two parts with a vertical bar (\|) in between. The first part is the description, and the second part is the document suffix. If there is no "\|", the option does not have the description. Multiple document suffixes separated by a comma (,) are allowed in an option. The number of elements in a string array cannot exceed 100.<br>By default, no filtering is performed, that is, all documents are selected. The wildcard ['All files (\*.\*)\\.*'] can be used on 2-in-1 devices to display all files. (Mobile phones can support this configuration since API version 17.)<br>This parameter is available only to the devices that have the required system capability.<br>**System capability**: SystemCapability.FileManagement.UserFileService  |
| selectMode<sup>11+</sup>         | [DocumentSelectMode](#documentselectmode11) | No  |  Yes| Only 2-in-1 devices are supported. The default value is **FILE**.<br>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |
| authMode<sup>12+</sup>    | boolean                              | No  |  Yes| Whether to start Picker.<br>Default value: **false**. If **authMode** is **true**, **defaultFilePathUri** is mandatory, which specifies the URI of the file allowed to access. Only 2-in-1 devices are supported.<br>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |
|multiAuthMode<sup>15+</sup>  | boolean                             |No   |  Yes| Whether to enable the batch authorization mode.<br>The value **false** (default) means to disable the batch authorization mode; the value **true** means to enable the batch authorization mode. The **multiUriArray** parameter only takes effect when **multAuthMode** is set to **true**. Only mobile phones are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
|multiUriArray<sup>15+</sup>  | Array&lt;string&gt;                             |No   |  Yes| Whether to pass the URIs for batch authorization (only files are supported). <br>This parameter is used with **multAuthMode**, and does not take effect when **multAuthMode** is set to **false**. By default, this parameter is left empty. (The files displayed on the batch authorization page are empty.) Only mobile phones are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
|mergeMode<sup>15+</sup>  | [MergeTypeMode](#mergetypemode15)                             |No   |  Yes| Whether to enable the aggregation view mode for a file management application. The default value is **DEFAULT**, indicating that this parameter does not take effect and the aggregation view is disabled. If this parameter is set to a value other than **DEFAULT**, other parameters do not take effect. Only mobile phones are supported.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
|isEncryptionSupported<sup>19+</sup>    | boolean |No   |  Yes| Whether to support encryption (only files are supported). The default value is **false**. If this parameter is set to **true**, files can be encrypted on the Picker page.<br>**Atomic service API**: This API can be used in atomic services since API version 19. |

## DocumentPickerMode<sup>12+</sup>

Enumerates the modes for saving documents.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| DEFAULT  | 0  | Standard mode.|
| DOWNLOAD | 1  | Download mode.|

## MergeTypeMode<sup>15+</sup>

Enumerates file aggregation types. Only mobile phones are supported.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name |  Value|  Description|
| ----- | ---- | ---- |
| DEFAULT  | 0  | Default mode, indicating that this parameter does not take effect.|
| AUDIO | 1  | Audio mode.|
| VIDEO  | 2  | Video mode.|
| DOCUMENT | 3  | Document mode.|
| PICTURE  | 4  | Image mode.|

## DocumentSaveOptions

Defines the options for saving documents.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames            | Array&lt;string&gt;    | No  | Name of the document to save. If this parameter is not specified, the user needs to enter the document name. |
| defaultFilePathUri<sup>10+</sup>    | string  | No  | Path of the document or directory to save. |
| fileSuffixChoices<sup>10+</sup>     | Array&lt;string&gt; | No  | Document suffix of the document to save.<br>The value is a string array. Each element specifies an option, which includes at most two parts with a vertical bar (\|) in between. The first part is the description, and the second part is the document suffix. If there is no "\|", the option does not have the description. By default, all documents are saved.|
| pickerMode<sup>12+</sup>     | [DocumentPickerMode](#documentpickermode12) | No  | Mode for starting Picker.<br>Default value: **DEFAULT**. If **pickerMode** is **DOWNLOAD**, the settings of **newFileNames**, **defaultFilePathUri**, and **fileSuffixChoices** do not take effect.|

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
| newFileNames              | Array&lt;string&gt;    | No | File name of the audio clip to save. If this parameter is not specified, the user needs to enter the file name.|

## PhotoViewPicker<sup>(deprecated)</sup>

Provides APIs for selecting and saving images or videos. You are advised to use [PhotoViewPicker of PhotoAccessHelper](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker) to select files. Before using the APIs of **PhotoViewPicker**, you need to create a **PhotoViewPicker** instance.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker) instead.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>12+</sup>

constructor(context: Context)

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create a **PhotoViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getHostContext](../apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12).

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
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext; // Ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
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

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create a **PhotoViewPicker** instance. This constructor is not recommended due to the potential risk of operation failure.

**Example**

```ts
let photoPicker = new picker.PhotoViewPicker(); // Construction without parameter is not recommended. There is a possibility that the PhotoViewPicker instance fails to start.
```

### select

select(option?: PhotoSelectOptions): Promise&lt;PhotoSelectResult&gt;

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/js-apis-photoAccessHelper.md#select) instead.

**NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptionsdeprecated) | No  | Options for selecting images or videos. If this parameter is not specified, images and videos are selected by default. A maximum of 50 files can be selected.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt; | Promise used to return the URIs of the images or videos selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example01(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
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

### select

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/js-apis-photoAccessHelper.md#select-1) instead.

**NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptionsdeprecated) | Yes  | Options for selecting images or videos.|
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt;      | Yes  | Callback used to return the images or videos selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example02(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
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

### select

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/js-apis-photoAccessHelper.md#select-2) instead.

**NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt;      | Yes  | Callback used to return the images or videos selected.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example03(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
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

### save

save(option?: PhotoSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **photoPicker** page for the user to save one or more images or videos. This API uses a promise to return the result. You can pass in **PhotoSaveOptions** to specify the URIs of the images or videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebutton) instead.

**NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptionsdeprecated) | No  | Options for saving images or videos. If this parameter is not specified, a **photoPicker** page will be displayed for the user to enter the names of the files to save.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the images or videos saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example04(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
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

### save

save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **photoPicker** page for the user to save one or more images or videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSaveOptions** to specify the URIs of the images or videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebutton) instead.

**NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptionsdeprecated) | Yes  | Options for saving images or videos.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the images or videos saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example05(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
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

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **photoPicker** page for the user to save one or more images or videos. This API uses an asynchronous callback to return the URIs of the images or videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebutton) instead.

**NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the images or videos saved.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import  { picker } from '@kit.CoreFileKit';
async function example06(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
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

Defines the options for selecting images or videos.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoSelectOptions](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoselectoptions) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType              | [PhotoViewMIMETypes](#photoviewmimetypesdeprecated)   | No  | Media file types to select. If this parameter is not specified, **IMAGE_VIDEO_TYPE** is used by default. |
| maxSelectNumber       | number | No  | Maximum number of media files that can be selected. The default value is **50**, and the maximum value is **500**.     |

## PhotoSelectResult<sup>(deprecated)</sup>

Defines information about the images or videos selected.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [photoAccessHelper.PhotoSelectResult](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoselectresult) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory| Description                          |
| ----------------------- | ------------------- | ----| ------------------------------ |
| photoUris        | Array&lt;string&gt;    | Yes  | URIs of the media files selected. This URI array can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |
| isOriginalPhoto        | boolean    | Yes  | Whether the selected image is the original one. The value **true** means the selected image is the original one; the value **false** means the opposite. |

## PhotoSaveOptions<sup>(deprecated)</sup>

Defines the options for saving images or videos.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. There is no substitute API.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | No | File name of the image or video to save. If this parameter is not specified, the user needs to enter the file name.|

# @ohos.file.picker (Picker)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @yangwei_814916-->
<!--Designer: @hwzhangchuang; @Dyylll-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=8b6cf89b37c32b3dffd1d378ad719228fa45e034 translatedAt=2026-08-14T11:53:11.642Z pushedAt=2026-08-18T02:53:56.259Z -->

The **Picker** module encapsulates APIs such as **DocumentViewPicker**, **AudioViewPicker**, and **PhotoViewPicker** to provide capabilities of selecting and saving files of different types. The **Picker** module can be used to start the system file selection page, where users can select or save files in a secure and controllable environment. Apps can use this module without requesting any permissions. An application can select the API as required. The APIs of this module must be called in UIAbility. Otherwise, the **FilePicker**, **AudioPicker**, or **PhotoPicker** cannot be started.

Chinese characters and non-digit characters in the URI are compiled into the corresponding ASCII code and concatenated to the URI returned by calling these APIs.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { picker } from '@kit.CoreFileKit';
```

## DocumentViewPicker

Provides APIs for selecting and saving documents in different formats. Before using the APIs of **DocumentViewPicker**, you need to create a **DocumentViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>12+</sup>

constructor(context: Context)

A constructor used to create a **DocumentViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getHostContext](../apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context| Yes  | Application context (only **UIAbilityContext** is supported). For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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
          .onClick(() => {
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

When a window is created by an app, a constructor is used to create a **DocumentViewPicker** object. In other scenarios, you are advised to use **constructor(context: Context)** to create a **DocumentViewPicker** object.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context| Yes  | Application context (only **UIAbilityContext** is supported). For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| window  | [window.Window](../apis-arkui/arkts-apis-window-Window.md)  | Yes  | Window instance created by the application.|

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
          .onClick(() => {
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

Starts a **documentPicker** page for the user to select one or more documents. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | No | **documentPicker** options, which are used to configure file selection parameters, such as the maximum number of files that can be selected and file name extension filtering. If this parameter is not specified, the **documentPicker** page is displayed by default. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the documents selected.<br> **Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts a **documentPicker** page for the user to select one or more documents. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | Yes | **documentPicker** selection options, which are used to configure file selection parameters, such as the maximum number of files that can be selected and file name extension filtering. |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes | Callback used to return the URIs of the documents selected.<br>**Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts a **documentPicker** page for the user to select one or more documents. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes   | Callback used to return the URIs of the documents selected.<br>**Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts a **documentPicker** page for the user to save one or more documents. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | No   | **documentPicker** saving options, which are used to configure the parameters for saving documents, such as the document name, default save path, and file name extension. If this parameter is not specified, a **documentPicker** page will be displayed for the user to enter the names of the documents to save. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the documents saved. If the call fails, **reject** throws **BusinessError**.<br>**Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts a **documentPicker** page for the user to save one or more documents. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | Yes | **documentPicker** saving options, which are used to configure the parameters for saving documents, such as the document name, default save path, and file name extension. |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes | Callback used to return the URIs of the documents saved.<br>**Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts a **documentPicker** page for the user to save one or more documents. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes   | Callback invoked to return the URIs of the documents saved.<br>**Note:** For details about how to use the URI array returned by this API, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

This method takes effect only when used with [save()](#save).

This method can be used only after [DocumentSaveOptions.fileSuffixChoices](#documentsaveoptions) is configured.

The index (number) returned by this method indicates the location of the file suffix specified in [DocumentSaveOptions.fileSuffixChoices](#documentsaveoptions). If no file suffix is specified, **getSelectedIndex()** returns **-1**. Before using the return value as the array index, check whether the return value is greater than or equal to 0 to avoid out-of-bounds array access.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| number| Subscript (number) of the selected suffix type in [DocumentSaveOptions.fileSuffixChoices](#documentsaveoptions). The default value is **–1**. |

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function exampleIndex(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    // Name of the file to save.
    documentSaveOptions.newFileNames = ['DocumentViewPicker01'];
    // File name extension of of the file to save.
    documentSaveOptions.fileSuffixChoices = ['txt', 'mp4', 'pdf'];
    let documentPicker = new picker.DocumentViewPicker(context);
    documentPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
      if (documentSaveOptions.fileSuffixChoices != undefined && documentSaveResult != undefined) {
        // Obtain the subscript of the file name extension of the file to save.
        let index = documentPicker.getSelectedIndex();
        // Obtain the file name extension of the file to save.
        let selectedSuffix = documentSaveOptions.fileSuffixChoices[index];
        console.info('DocumentViewPicker.save selectedSuffix is ' + selectedSuffix);
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

A constructor used to create an **AudioViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getHostContext](../apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context| Yes  | Application context (only **UIAbilityContext** is supported). For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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
          .onClick(() => {
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

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | No   | **audioPicker** options, which are used to configure audio file selection parameters, such as the maximum number of files that can be selected. If this parameter is not specified, the **audioPicker** page is displayed by default. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the audio clips selected. If the call fails, **reject** throws **BusinessError**. <br>**Note:** For details about how to use the returned URIs, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | Yes | **audioPicker** options, which are used to configure audio file selection parameters, such as the maximum number of files that can be selected. |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes | Callback used to return the URIs of the audio clips selected.<br>**Note:** For details about how to use the returned URIs, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts an **audioPicker** page for the user to select one or more audio clips. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes   | Callback used to return the URIs of the audio clips selected.<br>**Note:** For details about how to use the returned URIs, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | No  | Options for saving audio clips. If this parameter is not specified, an **audioPicker** page will be displayed for the user to enter the names of the files to save.|

**Return value**

| Type                            | Description    |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result set after the audioPicker saves the audio files. If the operation fails, an error message is thrown through reject with a BusinessError object. <br>**Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function example16(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker(context);
    audioPicker.save(audioSaveOptions).then((audioSaveResult: Array<string>) => {
      console.info('AudioViewPicker.save successfully, audioSaveResult uri: ' + JSON.stringify(audioSaveResult));
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

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | Yes | Options for saving audio clips., which are used to configure audio clip saving parameters such as the file name. |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes | Callback used to return the URIs of the audio files saved.<br>**Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to save one or more audio clips. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes   | Callback used to return the result set after the audioPicker saves the audio files. <br>**Note:** For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| FILE  | 0  | File (default).|
| FOLDER | 1  | Folder. |
| MIXED | 2  | Mixed type of files and folders.<br>**Device behavior differences**: This parameter can be used on 2-in-1 devices but has no effect on other devices.|

## DocumentSelectOptions

Defines the options for selecting documents.

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| maxSelectNumber<sup>10+</sup>       | number                                      | No   | Yes | Maximum number of files that can be selected.<br>In API version 20 and earlier versions, a maximum of 500 files can be selected at a time. The default value is 500. Directories can be selected only on devices that have the system capability. A maximum of one directory can be selected at a time.<br>In API version 21 and later versions, the maximum number of files that can be selected at a time is not limited. Due to system capability restrictions, if too many files are selected at a time, the functionality may be abnormal or the processing performance may be poor. It is recommended that a maximum of 10,000 files be selected at a time. In API version 23 and later versions, the maximum number of files that can be selected at a time is not limited.<br>**Device behavior differences**: Multiple directories cannot be selected for this parameter on phones.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService   |
| defaultFilePathUri<sup>10+</sup>    | string                                      | No   |  Yes | URI of the selected file or directory. The default value is empty (the recently visited page is displayed). To improve user experience, **FilePicker** remembers the last location navigated to by the user and prefers this path as the start path, instead of always using the path specified by **defaultFilePathUri.**<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService          |
| fileSuffixFilters<sup>10+</sup>     | Array&lt;string&gt;                         | No  |  Yes| File name extensions that can be selected. The value is a string array. Each element specifies an option, which includes at most two parts with a vertical bar (\|) in between. The first part is the description, and the second part is the extension. If there is no vertical bar (\|) in between, the option does not have the description. Multiple file name extensions can be set for an option, separated by commas (,) , for example, ['Image (.png, .jpg) |.png, .jpg', 'Document|.txt', 'Video|.mp4', '.pdf']. The size of the array cannot exceed 100.<br>All files are displayed by default. The wildcard ['All files (*.*)|.*'] can be used on 2-in-1 devices to display all files. Mobile phones support this configuration since API version 17.<br>This parameter is available only to the devices that have the required system capability.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService  |
| selectMode<sup>11+</sup>         | [DocumentSelectMode](#documentselectmode11) | No  |  Yes| Type of the document selected by Picker. The default value is **FILE** (file type).<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |
| authMode<sup>12+</sup>    | boolean                              | No  |  Yes| Whether to start Picker.<br>Default value: **false**. If **authMode** is **true**, **defaultFilePathUri** is mandatory, which specifies the URI of the file allowed to access.<br>**Device behavior differences**: This parameter can be used on 2-in-1 devices but has no effect on other devices.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |
|multiAuthMode<sup>15+</sup>  | boolean                             |No   |  Yes| Whether to enable the batch authorization mode.<br>The value **false** (default) means to disable the batch authorization mode; the value **true** means to enable the batch authorization mode. The **multiUriArray** parameter only takes effect when **multiAuthMode** is set to **true**.<br> **Device behavior differences**: This parameter can be used on smartphones but has no effect on other devices.<br>**Atomic service API**: This API can be used in atomic services since API version 15.<br>**System capability**: SystemCapability.FileManagement.UserFileService|
|multiUriArray<sup>15+</sup>  | Array&lt;string&gt;                             |No   |  Yes| Whether to pass the URIs for batch authorization (only files are supported). This parameter is used together with **multiAuthMode** and does not take effect when **multiAuthMode** is set to **false**. By default, this parameter is left empty. (The files displayed on the batch authorization page are empty.)<br> **Device behavior differences**: This parameter can be used on smartphones but has no effect on other devices.<br>**Atomic service API**: This API can be used in atomic services since API version 15.<br>**System capability**: SystemCapability.FileManagement.UserFileService|
|mergeMode<sup>15+</sup>  | [MergeTypeMode](#mergetypemode15)                             |No    |  Yes | Whether to enable the aggregation view mode for a file management application. The default value is **DEFAULT**, indicating that this parameter does not take effect and the aggregation view is disabled. If this parameter is set to a value other than **DEFAULT**, other parameters do not take effect.<br>For API version 26.0.0 and later versions, only the **fileSuffixFilters** parameter takes effect when this parameter is set to a value other than **DEFAULT**.<br> **Device behavior differences**: This parameter can be used on smartphones but has no effect on other devices.<br>**Atomic service API**: This API can be used in atomic services since API version 15.<br>**System capability**: SystemCapability.FileManagement.UserFileService|
|isEncryptionSupported<sup>19+</sup>    | boolean |No   |  Yes| Whether to support encryption (only files are supported). The default value is **false**. If this parameter is set to **true**, files can be encrypted on the Picker page.<br>**Atomic service API**: This API can be used in atomic services since API version 19.<br> **System capability**: SystemCapability.FileManagement.UserFileService|
| allowsMulFolderSelection       | boolean                                      | No  | Yes| Whether multiple folders can be selected. The value **true** indicates that multiple folders can be selected, and the value **false** indicates the opposite. The default value is **false**.<br>This parameter must be used together with **selectMode**. When **selectMode** is set to **FOLDER** or **MIXED** and **allowsMulFolderSelection** is set to **true**, the function of selecting multiple folders takes effect.<br>**Since**: 26.0.0<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>**Model restriction**: This API can be used only in the stage model.<br> **System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection|

## DocumentPickerMode<sup>12+</sup>

Enumerates the modes for saving documents.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| DEFAULT  | 0  | Standard mode, which is applicable to saving common files. You can customize the saving behavior by setting parameters such as **newFileNames**, **defaultFilePathUri**, and **fileSuffixChoices**. |
| DOWNLOAD | 1  | Download mode, which simplifies the saving process for file download. You can save files without specifying the file name and extension. <br>**Note:** The directories created in DOWNLOAD mode are used only to save files. There is no access isolation between directories. You are advised not to save sensitive appl data. |

## MergeTypeMode<sup>15+</sup>

Enumerates file aggregation types.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.FileManagement.UserFileService

**Device behavior differences**: This API can be called on mobile phones but has no effect on other devices.

| Name |  Value|  Description|
| ----- | ---- | ---- |
| DEFAULT  | 0  | Default mode, indicating that this parameter does not take effect.|
| AUDIO | 1  | Audio file mode, in which audio files are displayed in the the aggregation view. |
| VIDEO  | 2  | Video file mode, in which video files are displayed in the aggregation view. |
| DOCUMENT | 3  | Document file mode, in which documents are displayed in the aggregation view. |
| PICTURE  | 4  | Image file mode, in which images are displayed in the aggregation view. |

## DocumentSaveOptions

Defines the options for saving documents.

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| newFileNames            | Array&lt;string&gt;   | No| Yes  | Name of the document to save. If this parameter is not specified, the user needs to enter the file name.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService |
| defaultFilePathUri<sup>10+</sup>    | string  | No| Yes   | URI of the file or directory to save. This parameter is left empty by default.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService |
| fileSuffixChoices<sup>10+</sup>     | Array&lt;string&gt; | No| Yes   | Document suffix of the document to save. The value is a string array. Each element specifies an option, which includes at most two parts with a vertical bar (\|) in between. The first part is the description, and the second part is the extension to be saved. If there is no vertical bar (\|) in between, the option does not have the description. By default, all documents are saved.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService|
| pickerMode<sup>12+</sup>     | [DocumentPickerMode](#documentpickermode12) | No| Yes    | Mode for starting Picker. The default value is **DEFAULT**. If **pickerMode** is **DOWNLOAD**, the settings of **newFileNames**, **defaultFilePathUri**, and **fileSuffixChoices** do not take effect.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**System capability**: SystemCapability.FileManagement.UserFileService |
| autoCreateEmptyFile<sup>23+</sup> | boolean | No| Yes| A Boolean value indicates whether to pre-create empty files when saving files. The default value is **true**, in which case the Picker pre-creates empty files and returns an array of the file URIs. If it is set to **false**, no empty files are pre-created, and only an array of the file URIs is returned.<br>**Model restriction**: This API can be used only in the stage model.<br>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection|

## AudioSelectOptions

Defines the options for selecting audio clips.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| maxSelectNumber<sup>12+</sup>       | number                                   | No    | Yes  | Maximum number of audio clips that can be selected.<br>Default value: **1**<br>Value range: 1 to 500|

## AudioSaveOptions

Defines the options for saving audio clips.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| ---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| newFileNames              | Array&lt;string&gt;   | No| Yes | File name of the audio clip to save. If this parameter is not specified, the user needs to enter the file name.|

## PhotoViewPicker<sup>(deprecated)</sup>

Provides APIs for selecting and saving images or videos. You are advised to use [PhotoViewPicker](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md) of **PhotoAccessHelper** to select a file. Before using the APIs of **PhotoViewPicker**, you need to create a **PhotoViewPicker** instance.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [photoAccessHelper.PhotoViewPicker](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md) instead.

**System capability**: SystemCapability.FileManagement.UserFileService

### constructor<sup>(deprecated)</sup>

constructor(context: Context)

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context| Yes  | Application context (only **UIAbilityContext** is supported). For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|

A constructor used to create a **PhotoViewPicker** instance. This constructor is recommended. For details about how to obtain the context, see [getHostContext](../apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12).

> **NOTE**
>
> This API is supported since API version 12 and deprecated since API version 18. You are advised to use [photoAccessHelper.PhotoViewPicker](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md) instead.

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
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
          .onClick(() => {
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

### constructor<sup>(deprecated)</sup>

constructor()

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.UserFileService

A constructor used to create a **PhotoViewPicker** instance. This constructor is not recommended due to the potential risk of operation failure.

> **NOTE**
>
> This API is supported since API version 12 and deprecated since API version 18. You are advised to use [photoAccessHelper.PhotoViewPicker](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md) instead.

**Example**

```ts
let photoPicker = new picker.PhotoViewPicker(); // Construction without parameter is not recommended. There is a possibility that the PhotoViewPicker instance fails to start.
```

### select<sup>(deprecated)</sup>

select(option?: PhotoSelectOptions): Promise&lt;PhotoSelectResult&gt;

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md#select) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptionsdeprecated) | No | **photoPicker** options, which are used to configure image/video selection parameters, including the media file type and the maximum number of files that can be selected. If this parameter is not specified, images and videos are selected by default. A maximum of 50 files can be selected. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt; | Promise used to return  information about the images or videos selected. If the call fails, **reject** throws **BusinessError**. <br>**Note:** The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function example01(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.select(photoSelectOptions).then((photoSelectResult: picker.PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    }).catch((err: BusinessError) => {
      console.error(`PhotoViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### select<sup>(deprecated)</sup>

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md#select-1) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptionsdeprecated) | Yes | **photoPicker** options, which are used to configure image/video selection parameters, including the media file type and the maximum number of files that can be selected. |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt; | Yes | Callback used to return information about the images or videos selected.<br>**Note:** The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function example02(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.select(photoSelectOptions, (err: BusinessError, photoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error(`PhotoViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### select<sup>(deprecated)</sup>

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;): void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [photoAccessHelper.PhotoViewPicker#select](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md#select-2) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresultdeprecated)&gt; | Yes | Callback used to return information about the images or videos selected.<br>**Note:** The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function example03(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.select((err: BusinessError, photoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error(`PhotoViewPicker.select failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('PhotoViewPicker.select successfully, photoSelectResult uri: ' + JSON.stringify(photoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save<sup>(deprecated)</sup>

save(option?: PhotoSaveOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **photoPicker** page for the user to save one or more images or videos. This API uses a promise to return the result. You can pass in **PhotoSaveOptions** to specify the URIs of the images or videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md) instead.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptionsdeprecated) | No | **PhotoPicker** options for saving images or video files, which are used to configure the image/video saving parameters such as the file name. If this parameter is not specified, a **photoPicker** page will be displayed for the user to enter the names of the files to save. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the images or videos saved. If the call fails, **reject** throws **BusinessError**.<br>**Note:** This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function example04(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.save(photoSaveOptions).then((photoSaveResult: Array<string>) => {
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    }).catch((err: BusinessError) => {
      console.error(`PhotoViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save<sup>(deprecated)</sup>

save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **photoPicker** page for the user to save one or more images or videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSaveOptions** to specify the URIs of the images or videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md) instead.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptionsdeprecated) | Yes | **photoPicker** options for saving image or video files, which are used to configure the image/video saving parameters such as the file name. |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes | Callback used to return information about the images or videos saved.<br>**Note:** This API saves the files to the file manager instead of the gallery. For details, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function example05(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg', 'PhotoViewPicker02.mp4'];
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.save(photoSaveOptions, (err: BusinessError, photoSaveResult: Array<string>) => {
      if (err) {
        console.error(`PhotoViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

### save<sup>(deprecated)</sup>

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts a **photoPicker** page for the user to save one or more images or videos. This API uses an asynchronous callback to return the URIs of the images or videos to save.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButton](../apis-arkui/arkui-ts/ts-security-components-savebutton.md) instead.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes   | Callback used to return the URIs of the images or videos saved.<br>**Note:** This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { picker } from '@kit.CoreFileKit';
async function example06(context: common.UIAbilityContext) { // Ensure that context is converted from UIAbilityContext.
  try {
    let photoPicker = new picker.PhotoViewPicker(context);
    photoPicker.save((err: BusinessError, photoSaveResult: Array<string>) => {
      if (err) {
        console.error(`PhotoViewPicker.save failed with err, code is: ${err.code}, message is: ${err.message}`);
        return;
      }
      console.info('PhotoViewPicker.save successfully, photoSaveResult uri: ' + JSON.stringify(photoSaveResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err, code is: ${err.code}, message is: ${err.message}`);
  }
}
```

## PhotoViewMIMETypes<sup>(deprecated)</sup>

Enumerates the media file types that can be selected.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [photoAccessHelper.PhotoViewMIMETypes](../apis-media-library-kit/arkts-apis-photoAccessHelper-e.md#photoviewmimetypes) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| IMAGE_TYPE  |  'image/*' | Image.<br>**Note**: This API is supported since API version 9 and deprecated since API version 18. |
| VIDEO_TYPE |  'video/*' | Video.<br>**Note**: This API is supported since API version 9 and deprecated since API version 18.|
| IMAGE_VIDEO_TYPE |  '\*/*' | Image and video.<br>**Note**: This API is supported since API version 9 and deprecated since API version 18. |

## PhotoSelectOptions<sup>(deprecated)</sup>

Defines the options for selecting images or videos.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [photoAccessHelper.PhotoSelectOptions](../apis-media-library-kit/arkts-apis-photoAccessHelper-class.md#photoselectoptions) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| MIMEType              | [PhotoViewMIMETypes](#photoviewmimetypesdeprecated)  | No | Yes  | Media file types to select. If this parameter is not specified, **IMAGE_VIDEO_TYPE** is used by default.<br>**Note**: This API is supported since API version 9 and deprecated since API version 18. |
| maxSelectNumber       | number  | No | Yes   | Maximum number of media files that can be selected. The value range is [1, 500], and the default value is **50**. If the value is out of range, the input value does not take effect and the default value is used.<br>**Note:** This API is supported since API version 9 and deprecated since API version 18.      |

## PhotoSelectResult<sup>(deprecated)</sup>

Defines information about the images or videos selected.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. You are advised to use [photoAccessHelper.PhotoSelectResult](../apis-media-library-kit/arkts-apis-photoAccessHelper-class.md#photoselectresult) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| photoUris        | Array&lt;string&gt;    | No| No | URIs of the media files selected. This URI array can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).<br>**Note**: This API is supported since API version 9 and deprecated since API version 18. |
| isOriginalPhoto        | boolean   | No | No  | Whether the selected image is the original one. The value **true** means the selected image is the original one; the value **false** means the opposite.<br>**Note**: This API is supported since API version 9 and deprecated since API version 18. |

## PhotoSaveOptions<sup>(deprecated)</sup>

Defines the options for saving images or videos.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 12. Use [SaveButtonOptions](../apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebuttonoptions) instead.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Read-Only| Optional| Description                                      |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| newFileNames              | Array&lt;string&gt;    | No| Yes | File name of the image or video to save. If this parameter is not specified, the user needs to enter the file name.<br>**Note**: This API is supported since API version 9 and deprecated since API version 18.|
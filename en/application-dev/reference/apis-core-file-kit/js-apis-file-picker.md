# @ohos.file.picker (Picker)

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**picker** encapsulates APIs such as **PhotoViewPicker**, **DocumentViewPicker**, and **AudioViewPicker** to provide capabilities for selecting and saving images and videos, audio clips, or documents. The application can select the picker as required. The APIs of this module must be called in UIAbility. Otherwise, the **photoPicker** or **FilePicker** application cannot be started.

## Modules to Import

```ts
import picker from '@ohos.file.picker';
```

## PhotoViewPicker

Provides APIs for selecting and saving images/videos. You are advised to use [PhotoViewPicker of PhotoAccessHelper](../apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewpicker) to select files. Before using the APIs of **PhotoViewPicker**, you need to create a **PhotoViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let photoPicker = new picker.PhotoViewPicker();
```

### select

select(option?: PhotoSelectOptions): Promise&lt;PhotoSelectResult&gt;

Starts a **photoPicker** page for the user to select one or more images/videos. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | No  | Options for selecting images/videos. By default, images and videos are selected, and the maximum number of files that can be selected is 50.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresult)&gt; | Promise used to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example01() {
  try {  
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
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

Starts a **photoPicker** page for the user to select one or more images/videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | Yes  | Options for selecting images/videos.|
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example02() {
  try {
    let photoSelectOptions = new picker.PhotoSelectOptions();
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
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

Starts a **photoPicker** page for the user to select one or more images/videos. This API uses an asynchronous callback to return the result.

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example03() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
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

Starts a **photoPicker** page for the user to save one or more images/videos. This API uses a promise to return the result. You can pass in **PhotoSaveOptions** to specify the file names of the images/videos to save.

> **NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptions) | No  | Options for saving files. If this parameter is not specified, a **photoPicker** page will be displayed for the user to enter the names of the files to save.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example04() {
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
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

Starts a **photoPicker** page for the user to save one or more images/videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSaveOptions** to specify the file names of the images/videos to save.

> **NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptions) | Yes  | Options for saving images/videos.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example05() {
  try {
    let photoSaveOptions = new picker.PhotoSaveOptions();
    photoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg','PhotoViewPicker02.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
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

Starts a **photoPicker** page for the user to save one or more images/videos. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example06() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
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

## DocumentViewPicker

Provides APIs for selecting and saving documents in different formats. Before using the APIs of **DocumentViewPicker**, you need to create a **DocumentViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let documentPicker = new picker.DocumentViewPicker();
```

### select

select(option?: DocumentSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts a **documentPicker** page for the user to select one or more documents. This API uses a promise to return the result. You can pass in **DocumentSelectOptions**.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example07() {
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
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

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | Yes  | Options for selecting documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example08() {
  try {
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
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

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example09() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
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
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example10() {
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker();
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

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | Yes  | Options for saving the documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example11() {
  try {
    let documentSaveOptions = new picker.DocumentSaveOptions();
    documentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];
    let documentPicker = new picker.DocumentViewPicker();
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

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example12() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
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

**Example**

```ts
let audioPicker = new picker.AudioViewPicker();
```

### select

select(option?: AudioSelectOptions): Promise&lt;Array&lt;string&gt;&gt;

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to select one or more audio clips. This API uses a promise to return the result. You can pass in **AudioSelectOptions**.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

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
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example13() {
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
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

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to select one or more audio clips. This API uses an asynchronous callback to return the result. You can pass in **AudioSelectOptions**.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | Yes  | Options for selecting audio clips.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example14() {
  try {
    let audioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
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

Starts an **audioPicker** page (currently, a **documentPicker** page is displayed) for the user to select one or more audio clips. This API uses an asynchronous callback to return the result.

> **NOTE**<br>For details about how to use the returned URIs, see [Using a Document URI](../../file-management/user-file-uri-intro.md#using-a-document-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example15() {
  try {
    let audioPicker = new picker.AudioViewPicker();
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
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example16() {
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker();
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
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example17() {
  try {
    let audioSaveOptions = new picker.AudioSaveOptions();
    audioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];
    let audioPicker = new picker.AudioViewPicker();
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
import { BusinessError } from '@ohos.base';
import picker from '@ohos.file.picker';
async function example18() {
  try {
    let audioPicker = new picker.AudioViewPicker();
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

## PhotoViewMIMETypes

Enumerates the media file types that can be selected.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| IMAGE_TYPE  |  'image/*' | Image.|
| VIDEO_TYPE |  'video/*' | Video.|
| IMAGE_VIDEO_TYPE |  '\*/*' | Image and video.|

## PhotoSelectOptions

Defines the options for selecting images/videos.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType              | [PhotoViewMIMETypes](#photoviewmimetypes)   | No  | Types of the media files to select. **IMAGE_VIDEO_TYPE** is used by default.|
| maxSelectNumber       | number | No  | Maximum number of media files to select. The default value is **50**, and the maximum value is **500**.     |

## PhotoSelectResult

Defines information about the images/videos selected.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Readable| Writable| Description                          |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| photoUris        | Array&lt;string&gt;    | Yes  | Yes  | Array of the URIs of the images/videos selected. This URI array can be used only by [photoAccessHelper.getAssets](../apis-media-library-kit/js-apis-photoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).|
| isOriginalPhoto        | boolean    | Yes  | Yes  | Whether the selected image is the original one.|

## PhotoSaveOptions

Defines the options for saving images or videos.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | No | Names of the files to save. If this parameter is not specified, the user needs to enter the file names.|

## DocumentSelectMode<sup>11+</sup>

Enumerates the types of assets that can be selected by picker.

**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| FILE  | 0  | File.|
| FOLDER | 1  | Folder.|
| MIXED | 2  | File and folder.|

## DocumentSelectOptions

Defines the options for selecting documents.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type                                         | Mandatory| Description                                      |
| :---------------------- |---------------------------------------------| ---- |------------------------------------------|
| maxSelectNumber<sup>10+</sup>       | number                                      | No  | Maximum number of files that can be selected.<br>Value range: 1 to 500<br>Default value: **1**<br>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection<br/>Only the devices with the required system capability can select folders, and only one folder can be selected at a time. <br/> |
| defaultFilePathUri<sup>10+</sup>    | string                                      | No  | Path of the document or directory to select.                           |
| fileSuffixFilters<sup>10+</sup>     | Array&lt;string&gt;                         | No  | File name extensions that can be selected. Use a comma to separate multiple file name extensions. A maximum of 100 file name extension types can be added. This parameter is available only to the devices with the required system capability. <br/>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |
| selectMode<sup>11+</sup>         | [DocumentSelectMode](#documentselectmode11) | No  | Resource types that can be selected, for example, file, folder, both. This parameter is available only to the devices with the required system capability. The default value is **File**. <br/>**System capability**: SystemCapability.FileManagement.UserFileService.FolderSelection |


## DocumentSaveOptions

Defines the options for saving documents.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames            | Array&lt;string&gt;    | No  | Names of the documents to save. If this parameter is not specified, the user needs to enter the document names. |
| defaultFilePathUri<sup>10+</sup>    | string  | No  | Path of the file or folder to save.|
| fileSuffixChoices<sup>10+</sup>     | Array&lt;string&gt; | No  | File name extensions of the documents to save.|

## AudioSelectOptions

Defines the options for selecting audio clips. Currently, this parameter cannot be configured.

**System capability**: SystemCapability.FileManagement.UserFileService

## AudioSaveOptions

Defines the options for saving audio clips.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | No | Names of the audio clips to save. If this parameter is not specified, the user needs to enter the file names.|

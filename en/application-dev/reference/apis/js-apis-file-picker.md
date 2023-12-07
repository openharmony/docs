# @ohos.file.picker (Picker)

**picker** encapsulates APIs such as **PhotoViewPicker**, **DocumentViewPicker**, and **AudioViewPicker** to provide capabilities for selecting and saving images and videos, audio clips, or documents. The application can select the picker as required. The APIs of this module must be called in UIAbility. Otherwise, the **photoPicker** or **FilePicker** application cannot be started.
> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```ts
import picker from '@ohos.file.picker';
```

## PhotoViewPicker

Provides APIs for selecting and saving images and videos. Before using the APIs of **PhotoViewPicker**, you need to create a **PhotoViewPicker** instance. 
You are advised to use [PhotoViewPicker of PhotoAccessHelper](js-apis-photoAccessHelper.md) to select images and videos. 

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let photoPicker = new picker.PhotoViewPicker();
```

### select

select(option?: PhotoSelectOptions): Promise&lt;PhotoSelectResult&gt;

Starts a **photoPicker** page for the user to select one or more images/videos. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the type and maximum number of the files to select.

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by calling [photoAccessHelper.getAssets()](js-apis-photoAccessHelper.md#getassets) with temporary authorization. For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

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
async function example01() {
  try {  
    let PhotoSelectOptions = new picker.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult: picker.PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
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

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by calling [photoAccessHelper.getAssets()](js-apis-photoAccessHelper.md#getassets) with temporary authorization. For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | Yes  | Options for selecting images/videos.|
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example02() {
  try {
    let PhotoSelectOptions = new picker.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions, (err: BusinessError, PhotoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
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

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by calling [photoAccessHelper.getAssets()](js-apis-photoAccessHelper.md#getassets) with temporary authorization. For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return a **PhotoSelectResult** object.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example03() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select((err: BusinessError, PhotoSelectResult: picker.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
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

> **NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

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
async function example04() {
  try {
    let PhotoSaveOptions = new picker.PhotoSaveOptions();
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(PhotoSaveOptions).then((PhotoSaveResult: Array<string>) => {
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
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

> **NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptions) | Yes  | Options for saving images/videos.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example05() {
  try {
    let PhotoSaveOptions = new picker.PhotoSaveOptions();
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg','PhotoViewPicker02.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(PhotoSaveOptions, (err: BusinessError, PhotoSaveResult: Array<string>) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
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

> **NOTE**<br>This API saves files in **Files**, not in **Gallery**. For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example06() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save((err: BusinessError, PhotoSaveResult: Array<string>) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

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
async function example07() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(DocumentSelectOptions).then((DocumentSelectResult: Array<string>) => {
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | Yes  | Options for selecting documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example08() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(DocumentSelectOptions, (err: BusinessError, DocumentSelectResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example09() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select((err: BusinessError, DocumentSelectResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

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
async function example10() {
  try {
    let DocumentSaveOptions = new picker.DocumentSaveOptions();
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(DocumentSaveOptions).then((DocumentSaveResult: Array<string>) => {
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | Yes  | Options for saving the documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example11() {
  try {
    let DocumentSaveOptions = new picker.DocumentSaveOptions();
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(DocumentSaveOptions, (err: BusinessError, DocumentSaveResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example12() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save((err: BusinessError, DocumentSaveResult: Array<string>) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

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
async function example13() {
  try {
    let AudioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(AudioSelectOptions).then((AudioSelectResult: Array<string>) => {
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | Yes  | Options for selecting audio clips.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example14() {
  try {
    let AudioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(AudioSelectOptions, (err: BusinessError, AudioSelectResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips selected.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example15() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select((err: BusinessError, AudioSelectResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

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
async function example16() {
  try {
    let AudioSaveOptions = new picker.AudioSaveOptions();
    AudioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(AudioSaveOptions).then((AudioSaveResult: Array<string>) => {
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult))
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | Yes  | Options for saving audio clips.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example17() {
  try {
    let AudioSaveOptions = new picker.AudioSaveOptions();
    AudioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(AudioSaveOptions, (err: BusinessError, AudioSaveResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult));
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

> **NOTE**<br>For details about how to use the returned URIs, see [Using a File URI](../../file-management/user-file-uri-intro.md#using-a-file-uri).

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio clips saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example18() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save((err: BusinessError, AudioSaveResult: Array<string>) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult));
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
| photoUris        | Array&lt;string&gt;    | Yes  | Yes  | URIs of the images/videos selected. The URI array can be used only by calling [photoAccessHelper.getAssets](js-apis-photoAccessHelper.md#getassets) with temporary authorization. For details about how to use the media file URI, see [Using a Media File URI] (../../file-management/user-file-uri-intro.md#using-a-media-file-uri).|
| isOriginalPhoto        | boolean    | Yes  | Yes  | Whether the selected image is the original one.|

## PhotoSaveOptions

Defines the options for saving images/videos.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames              | Array&lt;string&gt;    | No | Names of the files to save. If this parameter is not specified, the user needs to enter the file names.|

## DocumentSelectOptions

Defines the options for selecting documents.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| maxSelectNumber<sup>10+</sup>       | number  | No  | Maximum number of documents or folders that can be selected.<br>Value range: 1 to 500            |
| defaultFilePathUri<sup>10+</sup>    | string  | No  | Path of the document or directory to select.|
| fileSuffixFilters<sup>10+</sup>     | Array&lt;string&gt; | No  | File name extension types to select. Use a comma (,) to separate multiple file name extensions.|

## DocumentSaveOptions

Defines the options for saving documents.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames            | Array&lt;string&gt;    | No  | Names of the documents to save. If this parameter is not specified, the user needs to enter the document names. |
| defaultFilePathUri<sup>10+</sup>    | string  | No  | Path of the file or directory to save.|
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

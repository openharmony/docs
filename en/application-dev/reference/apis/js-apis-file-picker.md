# @ohos.file.picker (File Picker)

**Picker** encapsulates the system applications such as **PhotoViewPicker**, **DocumentViewPicker** and **AudioViewPicker** to provide capabilities of selecting and saving files of different types. The application can select the picker as required.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import picker from '@ohos.file.picker';
```

## PhotoViewPicker

Provides APIs for selecting and saving images and videos. Before using the APIs of **PhotoViewPicker**, you need to create a **PhotoViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let photoPicker = new picker.PhotoViewPicker();
```

### select

select(option?: PhotoSelectOptions) : Promise&lt;PhotoSelectResult&gt;

Selects one or more images or videos in a **photoPicker** page. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the media file type and the maximum number of files to select.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | No  | Options for selecting files. If this parameter is not specified, images and videos are selected by default. A maximum of 50 files can be selected.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresult)&gt; | Promise used to return information about the images or videos selected.|

**Example**

```ts
async function example() {
  try {  
    let PhotoSelectOptions = new picker.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    }).catch((err) => {
      console.error('PhotoViewPicker.select failed with err: ' + err);
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### select

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

Selects one or more images or videos in a **photoPicker** page. This API uses an asynchronous callback to return the result. You can pass in **PhotoSelectOptions** to specify the media file type and the maximum number of files to select.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | Yes  | Options for selecting images or videos.|
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return information about the images or videos selected.|

**Example**

```ts
async function example() {
  try {   
    let PhotoSelectOptions = new picker.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions, (err, PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### select

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

Selects one or more images or videos in a **photoPicker** page. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return information about the images or videos selected.|

**Example**

```ts
async function example() {
  try {   
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.select((err, PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### save

save(option?: PhotoSaveOptions) : Promise&lt;Array&lt;string&gt;&gt;

Saves one or more images or videos in a **photoPicker** page. This API uses a promise to return the result. You can pass in **PhotoSaveOptions** to specify the file names of the images or videos to save.

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
async function example() {
  try {   
    let PhotoSaveOptions = new picker.PhotoSaveOptions();
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker01.jpg', 'PhotoViewPicker01.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(PhotoSaveOptions).then((PhotoSaveResult) => {
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
    }).catch((err) => {
      console.error('PhotoViewPicker.save failed with err: ' + err);
    });
  } catch (err) {
      console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### save

save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Saves one or more images or videos in a **photoPicker** page. This API uses an asynchronous callback to return the result. You can pass in **PhotoSaveOptions** to specify the file names of the images or videos to save.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSaveOptions](#photosaveoptions) | Yes  | Options for saving images or videos.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
async function example() {
  try {
    let PhotoSaveOptions = new picker.PhotoSaveOptions();
    PhotoSaveOptions.newFileNames = ['PhotoViewPicker02.jpg','PhotoViewPicker02.mp4'];
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save(PhotoSaveOptions, (err, PhotoSaveResult) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Saves one or more images or videos in a **photoPicker** page. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the files saved.|

**Example**

```ts
async function example() {
  try {
    let photoPicker = new picker.PhotoViewPicker();
    photoPicker.save((err, PhotoSaveResult) => {
      if (err) {
        console.error('PhotoViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('PhotoViewPicker.save successfully, PhotoSaveResult uri: ' + JSON.stringify(PhotoSaveResult));
    });
  } catch (err) {
    console.error('PhotoViewPicker failed with err: ' + err);
  }
}
```

## DocumentViewPicker

Provides APIs for selecting and saving non-media files, for example, documents in a variety of formats. Before using the APIs of **DocumentViewPicker**, you need to create a **DocumentViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let documentPicker = new picker.DocumentViewPicker();
```

### select

select(option?: DocumentSelectOptions) : Promise&lt;Array&lt;string&gt;&gt;

Selects one or more documents in a **documentPicker** page. This API uses a promise to return the result. You can pass in **DocumentSelectOptions**.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | No  | Options for select documents. If this parameter is not specified, the **documentPicker** page is displayed by default.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the documents selected.|

**Example**

```ts
async function example() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(DocumentSelectOptions).then((DocumentSelectResult) => {
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
    }).catch((err) => {
      console.error('DocumentViewPicker.select failed with err: ' + err);
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### select

select(option: DocumentSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Selects one or more documents in a **documentPicker** page. This API uses an asynchronous callback to return the result. You can pass in **DocumentSelectOptions**.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSelectOptions](#documentselectoptions) | Yes  | Options for selecting documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
async function example() {
  try {
    let DocumentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select(DocumentSelectOptions, (err, DocumentSelectResult) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Selects one or more documents in a **documentPicker** page. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents selected.|

**Example**

```ts
async function example() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.select((err, DocumentSelectResult) => {
      if (err) {
        console.error('DocumentViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.select successfully, DocumentSelectResult uri: ' + JSON.stringify(DocumentSelectResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```


### save

save(option?: DocumentSaveOptions) : Promise&lt;Array&lt;string&gt;&gt;

Saves one or more documents in a **documentPicker** page. This API uses a promise to return the result. You can pass in **DocumentSaveOptions** to specify the file names to save.

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
async function example() {
  try {
    let DocumentSaveOptions = new picker.DocumentSaveOptions();
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker01.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(DocumentSaveOptions).then((DocumentSaveResult) => {
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
    }).catch((err) => {
      console.error('DocumentViewPicker.save failed with err: ' + err);
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### save

save(option: DocumentSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Saves one or more documents in a **documentPicker** page. This API uses an asynchronous callback to return the result. You can pass in **DocumentSaveOptions** to specify the file names to save.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [DocumentSaveOptions](#documentsaveoptions) | Yes  | Options for saving the documents.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
async function example() {
  try {
    let DocumentSaveOptions = new picker.DocumentSaveOptions();
    DocumentSaveOptions.newFileNames = ['DocumentViewPicker02.txt'];
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save(DocumentSaveOptions, (err, DocumentSaveResult) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Saves one or more documents in a **documentPicker** page. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the documents saved.|

**Example**

```ts
async function example() {
  try {
    let documentPicker = new picker.DocumentViewPicker();
    documentPicker.save((err, DocumentSaveResult) => {
      if (err) {
        console.error('DocumentViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('DocumentViewPicker.save successfully, DocumentSaveResult uri: ' + JSON.stringify(DocumentSaveResult));
    });
  } catch (err) {
    console.error('DocumentViewPicker failed with err: ' + err);
  }
}
```

## AudioViewPicker

Provides APIs for selecting and saving audio files. Before using the APIs of **AudioViewPicker**, you need to create an **AudioViewPicker** instance.

**System capability**: SystemCapability.FileManagement.UserFileService

**Example**

```ts
let audioPicker = new picker.AudioViewPicker();
```

### select

select(option?: AudioSelectOptions) : Promise&lt;Array&lt;string&gt;&gt;

Selects one or more audio files in an **audioPicker** page (currently, a **documentPicker** page is displayed). This API uses a promise to return the result. You can pass in **AudioSelectOptions**.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | No  | Options for selecting the audio files. If this parameter is not specified, the **audioPicker** page is displayed by default. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the audio files selected.|

**Example**

```ts
async function example() {
  try {
    let AudioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(AudioSelectOptions).then((AudioSelectResult) => {
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
    }).catch((err) => {
      console.error('AudioViewPicker.select failed with err: ' + err);
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### select

select(option: AudioSelectOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Selects one or more audio files in an **audioPicker** page (currently, a **documentPicker** page is displayed). This API uses an asynchronous callback to return the result. You can pass in **AudioSelectOptions**.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSelectOptions](#audioselectoptions) | Yes  | Options for selecting audio files.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio files selected.|

**Example**

```ts
async function example() {
  try {
    let AudioSelectOptions = new picker.AudioSelectOptions();
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select(AudioSelectOptions, (err, AudioSelectResult) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### select

select(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Selects one or more audio files in an **audioPicker** page (currently, a **documentPicker** page is displayed). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio files selected.|

**Example**

```ts
async function example() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.select((err, AudioSelectResult) => {
      if (err) {
        console.error('AudioViewPicker.select failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.select successfully, AudioSelectResult uri: ' + JSON.stringify(AudioSelectResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### save

save(option?: AudioSaveOptions) : Promise&lt;Array&lt;string&gt;&gt;

Saves one or more audio files in an **audioPicker** page (currently, a **documentPicker** page is displayed). This API uses a promise to return the result. You can pass in **AudioSaveOptions** to specify the names of the audio files to save.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | No  | Options for saving audio files. If this parameter is not specified, an **audioPicker** page will be displayed for the user to enter the names of the files to save.|

**Return value**

| Type                           | Description   |
| ----------------------------- | ---- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the audio files saved.|

**Example**

```ts
async function example() {
  try {
    let AudioSaveOptions = new picker.AudioSaveOptions();
    AudioSaveOptions.newFileNames = ['AudioViewPicker01.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(AudioSaveOptions).then((AudioSaveResult) => {
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult))
    }).catch((err) => {
      console.error('AudioViewPicker.save failed with err: ' + err);
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### save

save(option: AudioSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Saves one or more audio files in an **audioPicker** page (currently, a **documentPicker** page is displayed). This API uses an asynchronous callback to return the result. You can pass in **AudioSaveOptions** to specify the names of the audio files to save.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [AudioSaveOptions](#audiosaveoptions) | Yes  | Options for saving audio files.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio files saved.|

**Example**

```ts
async function example() {
  try {
    let AudioSaveOptions = new picker.AudioSaveOptions();
    AudioSaveOptions.newFileNames = ['AudioViewPicker02.mp3'];
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save(AudioSaveOptions, (err, AudioSaveResult) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
  }
}
```

### save

save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void

Saves one or more audio files in an **audioPicker** page (currently, a **documentPicker** page is displayed). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileService

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;      | Yes  | Callback invoked to return the URIs of the audio files saved.|

**Example**

```ts
async function example() {
  try {
    let audioPicker = new picker.AudioViewPicker();
    audioPicker.save((err, AudioSaveResult) => {
      if (err) {
        console.error('AudioViewPicker.save failed with err: ' + err);
        return;
      }
      console.info('AudioViewPicker.save successfully, AudioSaveResult uri: ' + JSON.stringify(AudioSaveResult));
    });
  } catch (err) {
    console.error('AudioViewPicker failed with err: ' + err);
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

Defines the options for selecting images or videos.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType?              | [PhotoViewMIMETypes](#photoviewmimetypes)   | No  | Available media file types. **IMAGE_VIDEO_TYPE** is used by default.|
| maxSelectNumber?       | number | No  | Maximum number of media files to select. The default value is **50**, and the maximum value is **500**.     |

## PhotoSelectResult

Defines information about the images or videos selected.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Readable| Writable| Description                          |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| photoUris        | Array&lt;string&gt;    | Yes  | Yes  | URIs of the media files selected.|
| isOriginalPhoto        | boolean    | Yes  | Yes  | Whether the selected media file is the original image.|

## PhotoSaveOptions

Defines the options for saving images or videos.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames?              | Array&lt;string&gt;    | No | Names of the files to save. If this parameter is not specified, the user needs to enter the file names.|

## DocumentSelectOptions

Defines the options for selecting documents. Currently, this parameter cannot be configured.

**System capability**: SystemCapability.FileManagement.UserFileService

## DocumentSaveOptions

Defines the options for saving documents.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames?            | Array&lt;string&gt;    | No  | Names of the documents to save. If this parameter is not specified, the user needs to enter the document names. |

## AudioSelectOptions

Defines the options for selecting audio files. Currently, this parameter cannot be configured.

**System capability**: SystemCapability.FileManagement.UserFileService

## AudioSaveOptions

Defines the options for saving audio files.

**System capability**: SystemCapability.FileManagement.UserFileService

| Name                   | Type               | Mandatory|  Description                          |
| ----------------------- | ------------------- | ---- | ---------------------------- |
| newFileNames?              | Array&lt;string&gt;    | No | Name of the audio files to save. If this parameter is not specified, the user needs to enter the file names.|

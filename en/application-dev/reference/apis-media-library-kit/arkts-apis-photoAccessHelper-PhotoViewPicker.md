# Class (PhotoViewPicker)

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

PhotoViewPicker provides APIs for the user to select images and videos. Before using the APIs of PhotoViewPicker, you need to create a PhotoViewPicker instance.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Example**

```ts
let photoPicker = new photoAccessHelper.PhotoViewPicker();
```

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## select

select(option?: PhotoSelectOptions) : Promise&lt;PhotoSelectResult&gt;

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the media file type and the maximum number of files to select.

**NOTE**: The **photoUris** in the PhotoSelectResult object returned by this API has permanent authorization and can be used only by calling [photoAccessHelper.getAssets()](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](arkts-apis-photoAccessHelper-class.md#photoselectoptions) | No  | Options for selecting files. If this parameter is not specified, up to 50 images and videos are selected by default.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](arkts-apis-photoAccessHelper-class.md#photoselectresult)&gt; | Promise used to return information about the images or videos selected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900042      | Unknown error.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example01(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let PhotoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    }).catch((err: BusinessError) => {
      console.error(`PhotoViewPicker.select failed with err: ${err.code}, ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err: ${err.code}, ${err.message}`);
  }
}
```

## select

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSelectOptions** to specify the media file type and the maximum number of files to select.

**NOTE**: The **photoUris** in the PhotoSelectResult object returned by this API has permanent authorization and can be used only by calling [photoAccessHelper.getAssets()](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](arkts-apis-photoAccessHelper-class.md#photoselectoptions) | Yes  | Options for selecting images or videos.|
| callback | AsyncCallback&lt;[PhotoSelectResult](arkts-apis-photoAccessHelper-class.md#photoselectresult)&gt;      | Yes  | Callback used to return information about the images or videos selected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900042      | Unknown error.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example02(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let PhotoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions, (err: BusinessError, PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
      if (err) {
        console.error(`PhotoViewPicker.select failed with err: ${err.code}, ${err.message}`);
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err: ${err.code}, ${err.message}`);
  }
}
```

## select

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result.

**NOTE**: The **photoUris** in the PhotoSelectResult object returned by this API has permanent authorization and can be used only by calling [photoAccessHelper.getAssets()](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets). For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](arkts-apis-photoAccessHelper-class.md#photoselectresult)&gt;      | Yes  | Callback used to return information about the images or videos selected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900042      | Unknown error.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example03(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select((err: BusinessError, PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
      if (err) {
        console.error(`PhotoViewPicker.select failed with err: ${err.code}, ${err.message}`);
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err: ${err.code}, ${err.message}`);
  }
}
```

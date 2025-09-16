# @ohos.file.sendablePhotoAccessHelper (Album Management Based on a Sendable Object)
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

The module provides APIs for album management, including creating an album and accessing and modifying media data in an album, based on a [Sendable](../../arkts-utils/arkts-sendable.md) object.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { sendablePhotoAccessHelper } from '@kit.MediaLibraryKit';
```

## sendablePhotoAccessHelper.getPhotoAccessHelper

getPhotoAccessHelper(context: Context): PhotoAccessHelper

Obtains a PhotoAccessHelper instance, which can be used for accessing and modifying media files in an album.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                      |
| ------- | ------------------------------------------------------------ | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|

**Return value**

| Type                                   | Description                |
| --------------------------------------- | :------------------- |
| [PhotoAccessHelper](#photoaccesshelper) | PhotoAccessHelper instance obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
// The phAccessHelper instance obtained is a global object. It is used by default in subsequent operations. If the code snippet is not added, an error will be reported indicating that phAccessHelper is not defined.
// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Button("example").onClick(async () => {
        let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let phAccessHelper = sendablePhotoAccessHelper.getPhotoAccessHelper(context);
      }).width('100%')
    }
    .height('90%')
  }
}
```

## PhotoAccessHelper

### getAssets

getAssets(options: photoAccessHelper.FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

Obtains media assets. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

If the caller does not have the ohos.permission.READ_IMAGEVIDEO permission, use Picker to access the file and then call this API based on the URI obtained by Picker. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).

**Parameters**

| Name | Type                                                     | Mandatory| Description                |
| ------- | --------------------------------------------------------- | ---- | -------------------- |
| options | [photoAccessHelper.FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes  | Retrieval options.|

**Return value**

| Type                                                        | Description                                   |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PhotoAsset](#photoasset)&gt;&gt; | Promise used to return the media assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    if (fetchResult !== undefined) {
      console.info('fetchResult success');
      let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset !== undefined) {
        console.info('photoAsset.displayName :' + photoAsset.displayName);
      }
    }
  } catch (err) {
    console.error(`getAssets failed, error: ${err.code}, ${err.message}`);
  }
}
```

### getBurstAssets

getBurstAssets(burstKey: string, options: photoAccessHelper.FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

Obtains burst assets. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| burstKey | string                                                    | Yes  | Universally Unique Identifier (UUID) of a group of burst photos, that is, **BURST_KEY** of [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys). The value is a string of 36 characters.|
| options  | [photoAccessHelper.FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes  | Retrieval options.                                          |

**Return value**

| Type                                                        | Description                                 |
| ------------------------------------------------------------ | ------------------------------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PhotoAsset](#photoasset)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error.                                       |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getBurstAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<sendablePhotoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let photoAsset: sendablePhotoAccessHelper.PhotoAsset;
  // burstKey is a 36-bit UUID, which can be obtained from photoAccessHelper.PhotoKeys.
  for(photoAsset of photoAssetList){
    let burstKey: string = photoAccessHelper.PhotoKeys.BURST_KEY.toString();
    let photoAccessBurstKey: photoAccessHelper.MemberType = photoAsset.get(burstKey).toString();
    try {
      let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await
      phAccessHelper.getBurstAssets(photoAccessBurstKey, fetchOption);
      if (fetchResult !== undefined) {
        console.info('fetchResult success');
        let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
        if (photoAsset !== undefined) {
          console.info('photoAsset.displayName :' + photoAsset.displayName);
        }
      }
    } catch (err) {
      console.error(`getBurstAssets failed, error: ${err.code}, ${err.message}`);
    }
  }
}
```

### createAsset

createAsset(photoType: PhotoType, extension: string, options?: photoAccessHelper.CreateOptions): Promise&lt;string&gt;

Creates an image or video asset with the specified file type, file name extension, and options. This API uses a promise to return the result.

If the caller does not have the ohos.permission.WRITE_IMAGEVIDEO permission, you can create a media asset by using a security component. For details, see [Creating a Media Asset Using a Security Component](../../media/medialibrary/photoAccessHelper-savebutton.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name   | Type                                                       | Mandatory| Description                                |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------ |
| photoType | [PhotoType](#phototype)                                     | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.|
| extension | string                                                      | Yes  | File name extension, for example, **'jpg'**. The value contains 1 to 255 characters.       |
| options   | [photoAccessHelper.CreateOptions](arkts-apis-photoAccessHelper-i.md#createoptions) | No  | Options for creating the media asset, for example, **{title: 'testPhoto'}**.<br>The file name must not contain any invalid characters.<br>Starting from API version 18, the following characters are considered invalid: \ / : * ? " < > \| <br>For API versions 10 to 17, the following characters are considered invalid: . .. \ / : * ? " ' ` < > \| { } [ ]|

**Return value**

| Type                 | Description                                    |
| --------------------- | ---------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the created media asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetDemo');
  try {
    let photoType: sendablePhotoAccessHelper.PhotoType = sendablePhotoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let options: photoAccessHelper.CreateOptions = {
      title: 'testPhoto'
    }
    let uri: string = await phAccessHelper.createAsset(photoType, extension, options);
    console.info('createAsset uri' + uri);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

### getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, options?: photoAccessHelper.FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains albums based on the specified options and album type. This API uses a promise to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type                                                     | Mandatory| Description                                  |
| ------- | --------------------------------------------------------- | ---- | -------------------------------------- |
| type    | [AlbumType](#albumtype)                                   | Yes  | Type of the albums to obtain.                            |
| subtype | [AlbumSubtype](#albumsubtype)                             | Yes  | Subtype of the album.                          |
| options | [photoAccessHelper.FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | No  | Retrieval options. If this parameter is not specified, the albums are obtained based on the album type by default.|

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getAlbums(sendablePhotoAccessHelper.AlbumType.USER, sendablePhotoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album: sendablePhotoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getAlbumsPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

### getAlbums

getAlbums(options: photoAccessHelper.FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains albums. This API uses a promise to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type                                                     | Mandatory| Description    |
| ------- | --------------------------------------------------------- | ---- | -------- |
| options | [photoAccessHelper.FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes  | Retrieval options.|

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getAlbums(fetchOptions).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album: sendablePhotoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getAlbumsPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

### release

release(): Promise&lt;void&gt;

Releases this PhotoAccessHelper instance. This API uses a promise to return the result.
Call this API when the APIs of the PhotoAccessHelper instance are no longer used.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('releaseDemo');
  try {
    console.info('use function...');
  } catch (err) {
    console.error(`function error ...`);
  }finally{
      try{
          phAccessHelper?.release();
          console.info(`release success`);
      } catch(e){
          console.error(`release error :${e}`);
      }
  }
}
```

## PhotoAsset

Provides APIs for encapsulating file asset attributes.

### Properties

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name       | Type                   | Read-Only| Optional| Description                                                        |
| ----------- | ----------------------- | ---- | ---- | ------------------------------------------------------------ |
| uri<sup>12+</sup>         | string                  | Yes  | No  | Media asset URI, for example, **file://media/Photo/1/IMG_datetime_0001/displayName.jpg**. For details, see [Media File URI](../../file-management/user-file-uri-intro.md#media-file-uri).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| photoType   | [PhotoType](#phototype) | Yes  | No  | Type of the file.                                              |
| displayName | string                  | Yes  | No  | File name, including the file name extension, to display. The value contains 1 to 255 characters.                                    |

### convertToPhotoAsset

convertToPhotoAsset():  photoAccessHelper.PhotoAsset

Converts a Sendable PhotoAsset object to a non-Sendable PhotoAsset object.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                        | Description                                                        |
| ---------------------------- | ------------------------------------------------------------ |
| photoAccessHelper.PhotoAsset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md) of the non-Sendable type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('convertToPhotoAssetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let sendablePhotoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let photoAsset: photoAccessHelper.PhotoAsset = sendablePhotoAsset.convertToPhotoAsset();
    console.log(`get no sendable uri success : ${photoAsset.uri}`);
  } catch (err) {
    console.error(`convertToPhotoAsset failed. error: ${err.code}, ${err.message}`);
  }
}
```

### get

get(member: string): photoAccessHelper.MemberType

Obtains a **PhotoAsset** member parameter.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| member | string | Yes  | Name of the member parameter to obtain. <br>Except **'uri'**, **'media_type'**, **'subtype'**, and **'display_name'**, you must pass in [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys) in **fetchColumns**. For example, to obtain the title, pass in **fetchColumns: ['title']**.|

**Return value**

| Type                                                 | Description                        |
| ----------------------------------------------------- | ---------------------------- |
| [photoAccessHelper.MemberType](arkts-apis-photoAccessHelper-t.md#membertype) | **PhotoAsset** member parameter obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('photoAssetGetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;
    let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title.toString());
    console.info('photoAsset Get photoAssetTitle = ', photoAssetTitle);
  } catch (err) {
    console.error(`get failed. error: ${err.code}, ${err.message}`);
  }
}
```

### set

set(member: string, value: string): void

Sets a **PhotoAsset** member parameter.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| member | string | Yes  | Name of the parameter to set, for example, [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).TITLE. The value contains 1 to 255 characters.|
| value  | string | Yes  | Value to set. Only the value of [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).TITLE can be changed. The title must meet the following requirements:<br>- It must not contain a file name extension.<br>- The total length of the file name, which is in the format of title+file name extension, must be between 1 and 255 characters.<br>- It must not contain any invalid characters, which are:\ / : * ? " ' ` < > \| { } [ ]  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('photoAssetSetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
    photoAsset.set(title, 'newTitle');
  } catch (err) {
    console.error(`set failed. error: ${err.code}, ${err.message}`);
  }
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

Commits the modification on the file metadata to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
  let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
  console.info('photoAsset get photoAssetTitle = ', photoAssetTitle);
  photoAsset.set(title, 'newTitle3');
  try {
    await photoAsset.commitModify();
    let newPhotoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
    console.info('photoAsset get newPhotoAssetTitle = ', newPhotoAssetTitle);
  } catch (err) {
    console.error(`commitModify failed. error: ${err.code}, ${err.message}`);
  }
}
```

### getThumbnail

getThumbnail(size?: image.Size): Promise&lt;image.PixelMap&gt;

Obtains the file thumbnail of the given size. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type                                                 | Mandatory| Description        |
| ------ | ----------------------------------------------------- | ---- | ------------ |
| size   | [image.Size](../apis-image-kit/arkts-apis-image-i.md#size) | No  | Size of the thumbnail.|

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise used to return the PixelMap of the thumbnail.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err: BusinessError) => {
    console.error(`getThumbnail fail with error: ${err.code}, ${err.message}`);
  });
}
```

## FetchResult

Provides APIs to manage the file retrieval result.

### getCount

getCount(): number

Obtains the total number of files in the result set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Total number of files obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getCountDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let fetchCount = fetchResult.getCount();
  console.info('fetchCount = ', fetchCount);
}
```

### isAfterLast

isAfterLast(): boolean

Checks whether the cursor is in the last row of the result set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type   | Description                                                       |
| ------- | ----------------------------------------------------------- |
| boolean | Returns **true** if the cursor is in the last row of the result set; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let fetchCount = fetchResult.getCount();
  console.info('count:' + fetchCount);
  let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getLastObject();
  if (fetchResult.isAfterLast()) {
    console.info('photoAsset isAfterLast displayName = ', photoAsset.displayName);
  } else {
    console.info('photoAsset not isAfterLast.');
  }
}
```

### close

close(): void

Closes this FetchResult instance to invalidate it. After this instance is closed, the APIs in this instance cannot be invoked.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('fetchResultCloseDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    fetchResult.close();
    console.info('close succeed.');
  } catch (err) {
    console.error(`close fail. error: ${err.code}, ${err.message}`);
  }
}
```

### getFirstObject

getFirstObject(): Promise&lt;T&gt;

Obtains the first asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type            | Description                                 |
| ---------------- | ------------------------------------- |
| Promise&lt;T&gt; | Promise used to return the first object in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getFirstObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  console.info('photoAsset displayName: ', photoAsset.displayName);
}
```

### getNextObject

getNextObject(): Promise&lt;T&gt;

Obtains the next asset in the result set. This API uses a promise to return the result.
Before using this API, you must use [isAfterLast()](#isafterlast) to check whether the current position is the end of the result set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type            | Description                                 |
| ---------------- | ------------------------------------- |
| Promise&lt;T&gt; | Promise used to return the next object in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getNextObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  await fetchResult.getFirstObject();
  let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getNextObject();
  console.info('photoAsset displayName: ', photoAsset.displayName);
}
```

### getLastObject

getLastObject(): Promise&lt;T&gt;

Obtains the last asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type            | Description                                   |
| ---------------- | --------------------------------------- |
| Promise&lt;T&gt; | Promise used to return the last object in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getLastObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getLastObject();
  console.info('photoAsset displayName: ', photoAsset.displayName);
}
```

### getObjectByPosition

getObjectByPosition(index: number): Promise&lt;T&gt;

Obtains the asset with the given index in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type  | Mandatory| Description                         |
| ------ | ------ | ---- | ----------------------------- |
| index  | number | Yes  | Index of the asset to obtain. The value starts from **0**.|

**Return value**

| Type            | Description                                         |
| ---------------- | --------------------------------------------- |
| Promise&lt;T&gt; | Promise used to return the asset obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getObjectByPositionDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getObjectByPosition(0);
  console.info('photoAsset displayName: ', photoAsset.displayName);
}
```

### getAllObjects

getAllObjects(): Promise&lt;Array&lt;T&gt;&gt;

Obtains all the file assets in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                         | Description                                       |
| ----------------------------- | ------------------------------------------- |
| Promise&lt;Array&lt;T&gt;&gt; | Promise used to return all the assets in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('getAllObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<sendablePhotoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  console.info('photoAssetList length: ', photoAssetList.length);
}
```

## Album

Provides APIs to manage albums.

### Properties

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name        | Type                         | Read-Only                        | Optional| Description            |
| ------------ | ----------------------------- | ---------------------------- | ---- | ---------------- |
| albumType    | [AlbumType](#albumtype)       | Yes                          | No  | Type of the album.      |
| albumSubtype | [AlbumSubtype](#albumsubtype) | Yes                          | No  | Subtype of the album.    |
| albumName    | string                        | Yes for a user album; no for a system album.| No  | Name of the album.      |
| albumUri     | string                        | Yes                          | No  | URI of the album.       |
| count        | number                        | Yes                          | No  | Number of files in the album.|
| coverUri     | string                        | Yes                          | No  | URI of the cover file of the album.   |
| imageCount   | number                        | Yes                          | Yes  | Number of images in the album.|
| videoCount   | number                        | Yes                          | Yes  | Number of videos in the album.|

### convertToPhotoAlbum

convertToPhotoAlbum(): photoAccessHelper.Album

Converts this Sendable album to a non-Sendable album.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                        | Description                                                        |
| ---------------------------- | ------------------------------------------------------------ |
| [photoAccessHelper.Album](arkts-apis-photoAccessHelper-Album.md) | Album of the non-Sendable type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('convertToPhotoAlbumDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.Album> = await phAccessHelper.getAlbums(sendablePhotoAccessHelper.AlbumType.USER, sendablePhotoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  let sendableAlbum: sendablePhotoAccessHelper.Album = await albumList.getFirstObject();
  let album: photoAccessHelper.Album = sendableAlbum.convertToPhotoAlbum();
  album.getAssets(fetchOption).then((albumFetchResult) => {
    console.info('convertToPhotoAlbum successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err: BusinessError) => {
    console.error(`convertToPhotoAlbum failed with error: ${err.code}, ${err.message}`);
  });
}
```

### getAssets

getAssets(options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

Obtains media assets. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type                                                     | Mandatory| Description      |
| ------- | --------------------------------------------------------- | ---- | ---------- |
| options | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes  | Retrieval options.|

**Return value**

| Type                                                        | Description                                   |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PhotoAsset](#photoasset)&gt;&gt; | Promise used to return the media assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 13900020 | Invalid argument.                                            |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('albumGetAssetsDemoPromise');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.Album> = await phAccessHelper.getAlbums(sendablePhotoAccessHelper.AlbumType.USER, sendablePhotoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  let album: sendablePhotoAccessHelper.Album = await albumList.getFirstObject();
  album.getAssets(fetchOption).then((albumFetchResult) => {
    console.info('album getAssets successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err: BusinessError) => {
    console.error(`album getAssets failed with error: ${err.code}, ${err.message}`);
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

Commits the modification on the album attributes to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 14000011 | Internal system error.                                        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [sendablePhotoAccessHelper.getPhotoAccessHelper](#sendablephotoaccesshelpergetphotoaccesshelper).

<!--code_no_check-->
```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: sendablePhotoAccessHelper.PhotoAccessHelper) {
  console.info('albumCommitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.Album> = await phAccessHelper.getAlbums(sendablePhotoAccessHelper.AlbumType.USER, sendablePhotoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  let album: sendablePhotoAccessHelper.Album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify().then(() => {
    console.info('commitModify successfully');
  }).catch((err: BusinessError) => {
    console.error(`commitModify failed with error: ${err.code}, ${err.message}`);
  });
}
```

## PhotoType

Enumerates media file types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Value  | Description  |
| ----- | ---- | ------ |
| IMAGE | 1    | Image.|
| VIDEO | 2    | Video.|

## PhotoSubtype<sup>14+</sup>

Enumerates the [PhotoAsset](#photoasset) types.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  Photo, which is the default type.|
| MOVING_PHOTO |  3 |  Moving photo.|
| BURST |  4 |  Burst photo.|

## DynamicRangeType<sup>14+</sup>

Enumerates the dynamic range types of media assets.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| SDR |  0 |  Standard dynamic range (SDR).|
| HDR |  1 |  High dynamic range (HDR). |

## AlbumType

Enumerates the album types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name  | Value  | Description          |
| ------ | ---- | -------------- |
| USER   | 0    | User album.    |
| SYSTEM | 1024 | System album.|

## AlbumSubtype

Enumerate the album subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value        | Description      |
| ------------- | ---------- | ---------- |
| USER\_GENERIC | 1          | User album.|
| FAVORITE      | 1025       | Favorites.  |
| VIDEO         | 1026       | Video album.|
| IMAGE         | 1031       | Photo album.|
| ANY           | 2147483647 | Any album.|

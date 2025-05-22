# @ohos.file.sendablePhotoAccessHelper (Album Management Based on a Sendable Object) (System API)

The sendablePhotoAccessHelper module provides APIs for album management, including creating an album and accessing and modifying media data in an album, based on a [Sendable](../../arkts-utils/arkts-sendable.md) object.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.sendablePhotoAccessHelper (Album Management Based on a Sendable Object)](js-apis-sendablePhotoAccessHelper.md).

## Modules to Import

```ts
import { sendablePhotoAccessHelper } from '@kit.MediaLibraryKit';
```

## PhotoAccessHelper

### createAsset

createAsset(displayName: string): Promise&lt;PhotoAsset&gt;

Creates an asset with the specified file name. This API uses a promise to return the result.

The file name must comply with the following specifications:
- The file name consists of a valid file name and an image or video file name extension.
- The file name cannot exceed 255 characters.
- The file name cannot contain any of the following characters:<br> . .. \ / : * ? " ' ` < > | { } [ ]

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | -------------------------- |
| displayName | string | Yes  | File name of the asset to create.|

**Return value**

| Type                                    | Description                                   |
| ---------------------------------------- | --------------------------------------- |
| Promise&lt;[PhotoAsset](#photoasset)&gt; | Promise used to return the created asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 13900020 | Invalid argument.                                            |
| 14000001 | Invalid display name.                                        |
| 14000011 | Internal system error                                        |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
    console.info('createAsset file displayName' + photoAsset.displayName);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

### createAsset

createAsset(displayName: string, options: PhotoCreateOptions): Promise&lt;PhotoAsset&gt;

Creates an asset with the specified file name and options. This API uses a promise to return the result.

The file name must comply with the following specifications:
- The file name consists of a valid file name and an image or video file name extension.
- The file name cannot exceed 255 characters.
- The file name cannot contain any of the following characters:<br> . .. \ / : * ? " ' ` < > | { } [ ]

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name     | Type                                                        | Mandatory| Description                      |
| ----------- | ------------------------------------------------------------ | ---- | -------------------------- |
| displayName | string                                                       | Yes  | File name of the asset to create.|
| options     | [PhotoCreateOptions](js-apis-photoAccessHelper-sys.md#photocreateoptions) | Yes  | Options for creating the asset.    |

**Return value**

| Type                                    | Description                                   |
| ---------------------------------------- | --------------------------------------- |
| Promise&lt;[PhotoAsset](#photoasset)&gt; | Promise used to return the created asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201      | Permission denied.                                           |
| 13900020 | Invalid argument.                                            |
| 14000001 | Invalid display name.                                        |
| 14000011 | Internal system error                                        |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  try {
    let testFileName:string = 'testFile' + Date.now() + '.jpg';
    let createOption: photoAccessHelper.PhotoCreateOptions = {
      subtype: photoAccessHelper.PhotoSubtype.DEFAULT
    }
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName, createOption);
    console.info('createAsset file displayName' + photoAsset.displayName);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

### getHiddenAlbums

getHiddenAlbums(mode: HiddenPhotosDisplayMode, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains hidden albums based on the specified display mode and retrieval options. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                                          |
| ------- | ------------------------------------------------------------ | ---- | ---------------------------------------------- |
| mode    | [HiddenPhotosDisplayMode](js-apis-photoAccessHelper-sys.md#hiddenphotosdisplaymode11) | Yes  | Display mode of hidden albums.                              |
| options | [FetchOptions](js-apis-photoAccessHelper.md#fetchoptions)    | No  | Options for retrieving the albums. If this parameter is not specified, the albums are retrieved based on the display mode.|

**Return value**

| Type                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise&lt;[FetchResult](js-apis-photoAccessHelper.md#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error.                                        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the preset hidden album.
async function getSysHiddenAlbum() {
  console.info('getSysHiddenAlbumDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ASSETS_MODE)
    .then( async (fetchResult) => {
      if (fetchResult === undefined) {
        console.error('getSysHiddenAlbumPromise fetchResult is undefined');
        return;
      }
      let hiddenAlbum: sendablePhotoAccessHelper.Album = await fetchResult.getFirstObject();
      console.info('getAlbumsPromise successfully, albumUri: ' + hiddenAlbum.albumUri);
      fetchResult.close();
    }).catch((err: BusinessError) => {
      console.error(`getSysHiddenAlbumPromise failed with err: ${err.code}, ${err.message}`);
    });
}

// Obtain the hidden albums displayed by album, that is, the albums with hidden files. Such albums do not include the preset hidden album and the albums in the trash.
async function getHiddenAlbumsView() {
  console.info('getHiddenAlbumsViewDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getHiddenAlbumsViewPromise fetchResult is undefined');
      return;
    }
    let albums: Array<sendablePhotoAccessHelper.Album> = await fetchResult.getAllObjects();
    console.info('getHiddenAlbumsViewPromise successfully, albums size: ' + albums.length);

    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    for (let i = 0; i < albums.length; i++) {
      // Obtain hidden files in the album.
      albums[i].getAssets(fetchOption).then((assetFetchResult) => {
        console.info('album get hidden assets successfully, getCount: ' + assetFetchResult.getCount());
      }).catch((err: BusinessError) => {
        console.error(`album get hidden assets failed with error: ${err.code}, ${err.message}`);
      });
    }
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getHiddenAlbumsViewPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

## PhotoAsset

Provides APIs for encapsulating file asset attributes.

### requestSource

requestSource(): Promise&lt;number&gt;

Opens the source file to obtain the file descriptor (FD). This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the FD obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011 | Internal system error                                        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('requsetSourcePromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let fd = await photoAsset.requestSource();
    console.info('Source fd is ' + fd);
  } catch (err) {
    console.error(`requsetSourcePromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getAnalysisData

getAnalysisData(analysisType: AnalysisType): Promise\<string>

Obtains analysis data. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name      | Type                                                        | Mandatory| Description                    |
| :----------- | :----------------------------------------------------------- | :--- | :----------------------- |
| analysisType | [AnalysisType](js-apis-photoAccessHelper-sys.md#analysistype11) | Yes  | Smart analysis type.|

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the analysis result obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| :------- | :----------------------------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error                                        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getAnalysisDataDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let fetchResult: sendablePhotoAccessHelper.FetchResult<sendablePhotoAccessHelper.PhotoAsset> =
      await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: sendablePhotoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (photoAsset != undefined) {
      let analysisData: string = await photoAsset.getAnalysisData(
        photoAccessHelper.AnalysisType.ANALYSIS_OCR);
      console.info('get ocr result: ' + JSON.stringify(analysisData));
    }
    fetchResult.close();
  } catch (err) {
    console.error(`getAnalysisDataDemofailed with error: ${err.code}, ${err.message}`);
  }
}
```

### getFaceId<sup>13+</sup>

getFaceId(): Promise\<string>

Obtains the face identifier on the cover of a portrait album or group photo album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise used to return **tag_id**  of the portrait album, **group_tag** of the group photo album, or an empty string if no face identifier is found.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| :------- | :----------------------------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 14000011 | Internal system error                                        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getFaceIdDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo("user_display_level", 1);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult =
      await phAccessHelper.getAlbums(sendablePhotoAccessHelper.AlbumType.SMART,
        sendablePhotoAccessHelper.AlbumSubtype.PORTRAIT,
        fetchOptions);
    let album = await fetchResult?.getFirstObject();
    let faceId = await album?.getFaceId();
    console.info(`getFaceId successfully, faceId: ${faceId}`);
    fetchResult.close();
  } catch (err) {
    console.error(`getFaceId failed with err: ${err.code}, ${err.message}`);
  }
}
```

## Album

Provides APIs to manage albums.

## AlbumType

Enumerates the album types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Value  | Description                                          |
| ----- | ---- | ---------------------------------------------- |
| SMART | 4096 | Smart analysis album. **System API**: This is a system API.|

## AlbumSubtype

Enumerate the album subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                 | Value  | Description                                                      |
| --------------------- | ---- | ---------------------------------------------------------- |
| HIDDEN                | 1027 | Hidden album. <br>**System API**: This is a system API.                |
| TRASH                 | 1028 | Trash. <br>**System API**: This is a system API.                  |
| SCREENSHOT            | 1029 | Album for screenshots and screen recording files. <br>**System API**: This is a system API.          |
| CAMERA                | 1030 | Album for photos and videos taken by the camera. <br>**System API**: This is a system API.|
| SOURCE\_GENERIC       | 2049 | Source album. <br>**System API**: This is a system API.                |
| CLASSIFY              | 4097 | Classified album. <br>**System API**: This is a system API.                |
| GEOGRAPHY\_LOCATION   | 4099 | Geographic location album. <br>**System API**: This is a system API.                |
| GEOGRAPHY\_CITY       | 4100 | City album. <br>**System API**: This is a system API.                |
| SHOOTING\_MODE        | 4101 | Shooting mode album. <br>**System API**: This is a system API.            |
| PORTRAIT              | 4102 | Portrait album. <br>**System API**: This is a system API.                |
| GROUP_PHOTO           | 4103 | Group photo album. <br>**System API**: This is a system API.                |
| HIGHLIGHT             | 4104 | Highlights album. <br>**System API**: This is a system API.                |
| HIGHLIGHT_SUGGESTIONS | 4105 | Highlights suggestion album. <br>**System API**: This is a system API.            |

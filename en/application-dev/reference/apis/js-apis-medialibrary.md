# MediaLibrary

> **NOTE**
>
> The APIs of this module are supported since API version 6. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
```

## mediaLibrary.getMediaLibrary<sup>8+</sup>

getMediaLibrary(context: Context): MediaLibrary

Obtains a **MediaLibrary** instance, which is used to access and modify personal media data such as audios, videos, images, and documents.

This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | Context | Yes  | Context of the ability.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| [MediaLibrary](#medialibrary) | **MediaLibrary** instance.|

**Example (from API version 9)**

```ts
const context = getContext(this);
let media = mediaLibrary.getMediaLibrary(context);
```

**Example (API version 8)**

```js
import featureAbility from '@ohos.ability.featureAbility';

let context = featureAbility.getContext();
let media = mediaLibrary.getMediaLibrary(context);
```
## mediaLibrary.getMediaLibrary

getMediaLibrary(): MediaLibrary

Obtains a **MediaLibrary** instance, which is used to access and modify personal media data such as audios, videos, images, and documents.

This API can be used only in the FA model.

> **NOTE**
>
> This API is no longer maintained since API version 8. You are advised to use [mediaLibrary.getMediaLibrary<sup>8+</sup>](#medialibrarygetmedialibrary8) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                         | Description      |
| ----------------------------- | :--------- |
| [MediaLibrary](#medialibrary) | **MediaLibrary** instance.|

**Example**

```js
let media = mediaLibrary.getMediaLibrary();
```

## MediaLibrary

### getFileAssets<sup>7+</sup>


getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void 

Obtains file assets (also called files). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                             |
| -------- | --------------------------------------------------- | ---- | --------------------------------- |
| options  | [MediaFetchOptions](#mediafetchoptions7)            | Yes  | Options for fetching the files.                     |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult7)> | Yes  | Asynchronous callback of **FetchFileResult**.|

**Example**

```js
let fileKeyObj = mediaLibrary.FileKey;
let imageType = mediaLibrary.MediaType.IMAGE;
let imagesFetchOp = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
};
media.getFileAssets(imagesFetchOp, (error, fetchFileResult) => {
    if (fetchFileResult == undefined) {
        console.error('Failed to get fetchFileResult: ' + error);
        return;
    }
    const count = fetchFileResult.getCount();
    if (count < 0) {
        console.error('Failed to get count from fetchFileResult: count: ' + count);
        return;
    }
    if (count == 0) {
        console.info('The count of fetchFileResult is zero');
        return;
    }

    console.info('Get fetchFileResult success, count: ' + count);
    fetchFileResult.getFirstObject((err, fileAsset) => {
        if (fileAsset == undefined) {
            console.error('Failed to get first object: ' + err);
            return;
        }
        console.log('fileAsset.displayName ' + ': ' + fileAsset.displayName);
        for (let i = 1; i < count; i++) {
            fetchFileResult.getNextObject((err, fileAsset) => {
                if (fileAsset == undefined) {
                    console.error('Failed to get next object: ' + err);
                    return;
                }
                console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
            })
        }
    });
});
```
### getFileAssets<sup>7+</sup>

getFileAssets(options: MediaFetchOptions): Promise&lt;FetchFileResult&gt;

Obtains file assets. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type                                    | Mandatory| Description        |
| ------- | ---------------------------------------- | ---- | ------------ |
| options | [MediaFetchOptions](#mediafetchoptions7) | Yes  | Options for fetching the files.|

**Return value**

| Type                                | Description          |
| ------------------------------------ | -------------- |
| [FetchFileResult](#fetchfileresult7) | Result set of the file retrieval operation.|

**Example**

```js
let fileKeyObj = mediaLibrary.FileKey;
let imageType = mediaLibrary.MediaType.IMAGE;
let imagesFetchOp = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
};
media.getFileAssets(imagesFetchOp).then(function(fetchFileResult) {
    const count = fetchFileResult.getCount();
    if (count < 0) {
        console.error('Failed to get count from fetchFileResult: count: ' + count);
        return;
    }
    if (count == 0) {
        console.info('The count of fetchFileResult is zero');
        return;
    }
    console.info('Get fetchFileResult success, count: ' + count);
    fetchFileResult.getFirstObject().then(function(fileAsset) {
        console.log('fileAsset.displayName ' + ': ' + fileAsset.displayName);
        for (let i = 1; i < count; i++) {
            fetchFileResult.getNextObject().then(function(fileAsset) {
                console.log('fileAsset.displayName ' + ': ' + fileAsset.displayName);
            }).catch(function(err) {
                console.error('Failed to get next object: ' + err);
            })
        }
    }).catch(function(err) {
        console.error('Failed to get first object: ' + err);
    });
}).catch(function(err){
    console.error("Failed to get file assets: " + err);
});
```

### on<sup>8+</sup>

on(type: 'deviceChange'|'albumChange'|'imageChange'|'audioChange'|'videoChange'|'fileChange'|'remoteFileChange', callback: Callback&lt;void&gt;): void

Subscribes to the media library changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| type     | string               | Yes   | Media type.<br>'deviceChange': registered device change<br>'albumChange': album change<br>'imageChange': image file change<br>'audioChange': audio file change<br>'videoChange': video file change<br>'fileChange': file change<br>'remoteFileChange': file change on the registered device|
| callback | callback&lt;void&gt; | Yes   | Void callback.                                   |

**Example**

```js
media.on('imageChange', () => {
    // image file had changed, do something
})
```
### off<sup>8+</sup>

off(type: 'deviceChange'|'albumChange'|'imageChange'|'audioChange'|'videoChange'|'fileChange'|'remoteFileChange', callback?: Callback&lt;void&gt;): void

Unsubscribes from the media library changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| type     | string               | Yes   | Media type.<br>'deviceChange': registered device change<br>'albumChange': album change<br>'imageChange': image file change<br>'audioChange': audio file change<br>'videoChange': video file change<br>'fileChange': file change<br>'remoteFileChange': file change on the registered device|
| callback | callback&lt;void&gt; | No   | Void callback.                                   |

**Example**

```js
media.off('imageChange', () => {
    // stop listening success
})
```

### createAsset<sup>8+</sup>

createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback&lt;FileAsset&gt;): void

Creates a media asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                                                        |
| ------------ | --------------------------------------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype8)                | Yes  | Media type.                                                    |
| displayName  | string                                  | Yes  | Display file name.                                                  |
| relativePath | string                                  | Yes  | Path for storing the file. You can use [getPublicDirectory](#getpublicdirectory8) to obtain the paths for storing different types of files.|
| callback     | AsyncCallback<[FileAsset](#fileasset7)> | Yes  | Asynchronous callback for **FileAsset**.                         |

**Example**

```js
async function example() {
    // Create an image file in callback mode.
    let mediaType = mediaLibrary.MediaType.IMAGE;
    let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
    const path = await media.getPublicDirectory(DIR_IMAGE);
    media.createAsset(mediaType, 'imageCallBack.jpg', path + 'myPicture/', (err, fileAsset) => {
        if (fileAsset != undefined) {
            console.info('createAsset successfully, message = ' + err);
        } else {
            console.info('createAsset failed, message = ' + err);
        }
    });
}
```

### createAsset<sup>8+</sup>

createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise&lt;FileAsset&gt;

Creates a media asset. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                                                        |
| ------------ | ------------------------ | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype8) | Yes  | Media type.                                                    |
| displayName  | string                   | Yes  | Display file name.                                                  |
| relativePath | string                   | Yes  | Relative path. You can use [getPublicDirectory](#getpublicdirectory8) to obtain the relative path of the level-1 directory of different types of media files.|

**Return value**

| Type                    | Description             |
| ------------------------ | ----------------- |
| [FileAsset](#fileasset7) | Media data (FileAsset).|

**Example**

```js
let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
media.getPublicDirectory(DIR_CAMERA).then(function(dicResult){
    console.info("getPublicDirectory successfully:"+ JSON.stringify(dicResult));
}).catch(function(err){
    console.info("getPublicDirectory failed with error:"+ err);
});
```

### deleteAsset<sup>8+</sup>

deleteAsset(uri: string): Promise\<void>

Deletes a file asset. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | Yes   | URI of the file asset to delete.|

**Return value**
| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let fileType = mediaLibrary.MediaType.FILE;
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    let asset = await fetchFileResult.getFirstObject();
    if (asset == undefined) {
        console.error('asset not exist')
        return
    }
    media.deleteAsset(asset.uri).then(() => {
        console.info("deleteAsset successfully");
    }).catch((err) => {
        console.info("deleteAsset failed with error:"+ err);
    });
}
```

### deleteAsset<sup>8+</sup>
deleteAsset(uri: string, callback: AsyncCallback\<void>): void

Deletes a file asset. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | Yes   | URI of the file asset to delete.|
|callback |AsyncCallback\<void>| Yes |Callback used to return the result.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let fileType = mediaLibrary.MediaType.FILE;
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    let asset = await fetchFileResult.getFirstObject();
    if (asset == undefined) {
        console.error('asset not exist')
        return
    }
    media.deleteAsset(asset.uri, (err) => {
        if (err != undefined) {
            console.info("deleteAsset successfully");
        } else {
            console.info("deleteAsset failed with error:"+ err);
        }
    });
}
```

### getPublicDirectory<sup>8+</sup>

getPublicDirectory(type: DirectoryType, callback: AsyncCallback&lt;string&gt;): void

Obtains a public directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                            | Mandatory| Description                     |
| -------- | -------------------------------- | ---- | ------------------------- |
| type     | [DirectoryType](#directorytype8) | Yes  | Type of the public directory.             |
| callback | AsyncCallback&lt;string&gt;      | Yes  | Callback used to return the public directory.|

**Example**

```js
let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
media.getPublicDirectory(DIR_CAMERA, (err, dicResult) => {
    if (dicResult == 'Camera/') {
        console.info('mediaLibraryTest : getPublicDirectory passed');
    } else {
        console.info('mediaLibraryTest : getPublicDirectory failed');
    }
});
```

### getPublicDirectory<sup>8+</sup>

getPublicDirectory(type: DirectoryType): Promise&lt;string&gt;

Obtains a public directory. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name| Type                            | Mandatory| Description        |
| ------ | -------------------------------- | ---- | ------------ |
| type   | [DirectoryType](#directorytype8) | Yes  | Type of the public directory.|

**Return value**

| Type            | Description            |
| ---------------- | ---------------- |
| Promise\<string> | Promise used to return the public directory.|

**Example**

```js
async function example() {
    let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
    const dicResult = await media.getPublicDirectory(DIR_CAMERA);
    if (dicResult == 'Camera/') {
        console.info('MediaLibraryTest : getPublicDirectory');
    } else {
        console.info('MediaLibraryTest : getPublicDirectory failed');
    }
}
```

### getAlbums<sup>7+</sup>

getAlbums(options: MediaFetchOptions, callback: AsyncCallback<Array&lt;Album&gt;>): void

Obtains the albums. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                       |
| -------- | -------------------------------------------- | ---- | --------------------------- |
| options  | [MediaFetchOptions](#mediafetchoptions7)     | Yes  | Options for fetching the albums.               |
| callback | AsyncCallback&lt;Array<[Album](#album7)>&gt; | Yes  | Callback used to return the albums.|

**Example**

```js
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
media.getAlbums(AlbumNoArgsfetchOp, (err, albumList) => {
    if (albumList != undefined) {
        const album = albumList[0];
        console.info('album.albumName = ' + album.albumName);
        console.info('album.count = ' + album.count);
     } else {
        console.info('getAlbum fail, message = ' + err);
     }
})
```

### getAlbums<sup>7+</sup>

getAlbums(options: MediaFetchOptions): Promise<Array&lt;Album&gt;>

Obtains the albums. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type                                    | Mandatory| Description        |
| ------- | ---------------------------------------- | ---- | ------------ |
| options | [MediaFetchOptions](#mediafetchoptions7) | Yes  | Options for fetching the albums.|

**Return value**

| Type                            | Description         |
| -------------------------------- | ------------- |
| Promise<Array<[Album](#album7)>> | Promise used to return the albums.|

**Example**

```js
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
media.getAlbums(AlbumNoArgsfetchOp).then(function(albumList){
    console.info("getAlbums successfully:"+ JSON.stringify(albumList));
}).catch(function(err){
    console.info("getAlbums failed with error:"+ err);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback&lt;void&gt;): void

Releases this **MediaLibrary** instance.
Call this API when you no longer need to use the APIs in the **MediaLibrary** instance.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description        |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the execution result.|

**Example**

```js
var media = mediaLibrary.getMediaLibrary(context);
media.release((err) => {
    // do something
});
```

### release<sup>8+</sup>

release(): Promise&lt;void&gt;

Releases this **MediaLibrary** instance.
Call this API when you no longer need to use the APIs in the **MediaLibrary** instance.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Example**

```js
media.release()
```

### storeMediaAsset<sup>(deprecated)</sup>

storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback&lt;string&gt;): void

Stores a media asset. This API uses an asynchronous callback to return the URI that stores the media asset.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                   | Mandatory  | Description                     |
| -------- | ------------------------------------- | ---- | ----------------------- |
| option   | [MediaAssetOption](#mediaassetoption) | Yes   | Media asset option.                |
| callback | AsyncCallback&lt;string&gt;           | Yes   | Callback used to return the URI that stores the media asset.|

**Example**

```js
let option = {
    src : "/data/storage/el2/base/haps/entry/image.png",
    mimeType : "image/*",
    relativePath : "Pictures/"
};
mediaLibrary.getMediaLibrary().storeMediaAsset(option, (err, value) => {
    if (err) {
        console.log("An error occurred when storing the media asset.");
        return;
    }
    console.log("Media asset stored.");
    // Obtain the URI that stores the media asset.
});
```


### storeMediaAsset<sup>(deprecated)</sup>

storeMediaAsset(option: MediaAssetOption): Promise&lt;string&gt;

Stores a media asset. This API uses a promise to return the URI that stores the media asset.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                                   | Mandatory  | Description     |
| ------ | ------------------------------------- | ---- | ------- |
| option | [MediaAssetOption](#mediaassetoption) | Yes   | Media asset option.|

**Return value**

| Type                   | Description                          |
| --------------------- | ---------------------------- |
| Promise&lt;string&gt; | Promise used to return the URI that stores the media asset.|

**Example**

```js
let option = {
    src : "/data/storage/el2/base/haps/entry/image.png",
    mimeType : "image/*",
    relativePath : "Pictures/"
};
mediaLibrary.getMediaLibrary().storeMediaAsset(option).then((value) => {
    console.log("Media asset stored.");
    // Obtain the URI that stores the media asset.
}).catch((err) => {
    console.log("An error occurred when storing the media assets.");
});
```


### startImagePreview<sup>(deprecated)</sup>

startImagePreview(images: Array&lt;string&gt;, index: number, callback: AsyncCallback&lt;void&gt;): void

Starts image preview, with the first image to preview specified. This API can be used to preview local images whose URIs start with **dataability://** or online images whose URIs start with **https://**. It uses an asynchronous callback to return the execution result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use the **\<[Image](../arkui-ts/ts-basic-components-image.md)>** component instead. The **\<Image>** component can be used to render and display local and online images.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| images   | Array&lt;string&gt;       | Yes   | URIs of the images to preview. The value can start with either **dataability://** or **https://**.|
| index    | number                    | Yes   | Index of the first image to preview.                              |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the image preview result. If the preview fails, an error message is returned.                       |

**Example**

```js
let images = [
    "dataability:///media/xxxx/2",
    "dataability:///media/xxxx/3"
];
/* Preview online images.
let images = [
    "https://media.xxxx.com/image1.jpg",
    "https://media.xxxx.com/image2.jpg"
];
*/
let index = 1;
mediaLibrary.getMediaLibrary().startImagePreview(images, index, (err) => {
    if (err) {
        console.log("An error occurred when previewing the images.");
        return;
    }
    console.log("Succeeded in previewing the images.");
});
```


### startImagePreview<sup>(deprecated)</sup>

startImagePreview(images: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Starts image preview. This API can be used to preview local images whose URIs start with **dataability://** or online images whose URIs start with **https://**. It uses an asynchronous callback to return the execution result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use the **\<[Image](../arkui-ts/ts-basic-components-image.md)>** component instead. The **\<Image>** component can be used to render and display local and online images.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| images   | Array&lt;string&gt;       | Yes   | URIs of the images to preview. The value can start with either **https://** or **dataability://**.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the image preview result. If the preview fails, an error message is returned.                       |

**Example**

```js
let images = [
    "dataability:///media/xxxx/2",
    "dataability:///media/xxxx/3"
];
/* Preview online images.
let images = [
    "https://media.xxxx.com/image1.jpg",
    "https://media.xxxx.com/image2.jpg"
];
*/
mediaLibrary.getMediaLibrary().startImagePreview(images, (err) => {
    if (err) {
        console.log("An error occurred when previewing the images.");
        return;
    }
    console.log("Succeeded in previewing the images.");
});
```


### startImagePreview<sup>(deprecated)</sup>

startImagePreview(images: Array&lt;string&gt;, index?: number): Promise&lt;void&gt;

Starts image preview, with the first image to preview specified. This API can be used to preview local images whose URIs start with dataability:// or online images whose URIs start with https://. It uses a promise to return the execution result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use the **\<[Image](../arkui-ts/ts-basic-components-image.md)>** component instead. The **\<Image>** component can be used to render and display local and online images.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                 | Mandatory  | Description                                      |
| ------ | ------------------- | ---- | ---------------------------------------- |
| images | Array&lt;string&gt; | Yes   | URIs of the images to preview. The value can start with either **dataability://** or **https://**.|
| index  | number              | No   | Index of the first image to preview. If this parameter is not specified, the default value **0** is used.                     |

**Return value**

| Type                 | Description                             |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the image preview result. If the preview fails, an error message is returned.|

**Example**

```js
let images = [
    "dataability:///media/xxxx/2",
    "dataability:///media/xxxx/3"
];
/* Preview online images.
let images = [
    "https://media.xxxx.com/image1.jpg",
    "https://media.xxxx.com/image2.jpg"
];
*/
let index = 1;
mediaLibrary.getMediaLibrary().startImagePreview(images, index).then(() => {
    console.log("Succeeded in previewing the images.");
}).catch((err) => {
    console.log("An error occurred when previewing the images.");
});
```


### startMediaSelect<sup>(deprecated)</sup>

startMediaSelect(option: MediaSelectOption, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts media selection. This API uses an asynchronous callback to return the list of URIs that store the selected media assets.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use the system app Gallery instead. Gallery is a built-in visual resource access application that provides features such as image and video management and browsing. For details about how to use Gallery, visit [OpenHarmony/applications_photos](https://gitee.com/openharmony/applications_photos).

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| option   | [MediaSelectOption](#mediaselectoptiondeprecated)  | Yes   | Media selection option.                             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the list of URIs (starting with **dataability://**) that store the selected media assets.|

**Example**

```js
let option : mediaLibrary.MediaSelectOption = {
    type : "media",
    count : 2
};
mediaLibrary.getMediaLibrary().startMediaSelect(option, (err, value) => {
    if (err) {
        console.log("An error occurred when selecting the media asset.");
        return;
    }
    console.log("Media asset selected.");
    // Obtain the media selection value.
});
```


### startMediaSelect<sup>(deprecated)</sup>

startMediaSelect(option: MediaSelectOption): Promise&lt;Array&lt;string&gt;&gt;

Starts media selection. This API uses a promise to return the list of URIs that store the selected media assets.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use the system app Gallery instead. Gallery is a built-in visual resource access application that provides features such as image and video management and browsing. For details about how to use Gallery, visit [OpenHarmony/applications_photos](https://gitee.com/openharmony/applications_photos).

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                                     | Mandatory  | Description     |
| ------ | --------------------------------------- | ---- | ------- |
| option | [MediaSelectOption](#mediaselectoptiondeprecated) | Yes   | Media selection option.|

**Return value**

| Type                                | Description                                      |
| ---------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the list of URIs (starting with **dataability://**) that store the selected media assets.|

**Example**

```js
let option : mediaLibrary.MediaSelectOption = {
    type : "media",
    count : 2
};
mediaLibrary.getMediaLibrary().startMediaSelect(option).then((value) => {
    console.log("Media asset selected.");
    // Obtain the media selection value.
}).catch((err) => {
    console.log("An error occurred when selecting the media assets.");
});

```
### getActivePeers<sup>8+</sup>

getActivePeers(): Promise\<Array\<PeerInfo>>;

Obtains information about online peer devices. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
|  Promise\<Array\<PeerInfo>> | Promise used to return the online peer devices, in an array of **PeerInfo** objects.|

**Example**

```js
async function example() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    media.getActivePeers().then((devicesInfo) => {
        if (devicesInfo != undefined) {
            for (let i = 0; i < devicesInfo.length; i++) {
            console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
            }
        } else {
            console.info('get distributed info is undefined!')
        }
    }).catch((err) => {
        console.info("get distributed info failed with error:" + err);
    });
}
```

### getActivePeers<sup>8+</sup>

getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

Obtains information about online peer devices. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<PeerInfo>> | Promise used to return the online peer devices, in an array of **PeerInfo** objects.|

**Example**

```js
async function example() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    media.getActivePeers((err, devicesInfo) => {
        if (devicesInfo != undefined) {
            for (let i = 0; i < devicesInfo.length; i++) {
                console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
            }
        } else {
            console.info('get distributed fail, message = ' + err)
        }
    })
}
```


### getAllPeers<sup>8+</sup>

getAllPeers(): Promise\<Array\<PeerInfo>>;

Obtains information about all peer devices. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
|  Promise\<Array\<PeerInfo>> | Promise used to return all peer devices, in an array of **PeerInfo** objects.|

**Example**

```js
async function example() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    media.getAllPeers().then((devicesInfo) => {
        if (devicesInfo != undefined) {
            for (let i = 0; i < devicesInfo.length; i++) {
                console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
            }
        } else {
            console.info('get distributed info is undefined!')
        }
    }).catch((err) => {
        console.info("get distributed info failed with error:" + err);
    });
}
```

### getAllPeers<sup>8+</sup>

getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

Obtains information about online peer devices. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<PeerInfo>> | Promise used to return all peer devices, in an array of **PeerInfo** objects.|

**Example**

```js
async function example() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    media.getAllPeers((err, devicesInfo) => {
        if (devicesInfo != undefined) {
            for (let i = 0; i < devicesInfo.length; i++) {
            console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
            }
        } else {
            console.info('get distributed fail, message = ' + err)
        }
    })
}
```

## FileAsset<sup>7+</sup>

Provides APIs for encapsulating file asset attributes.

### Attributes

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name                     | Type                    | Readable| Writable| Description                                                  |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| id                        | number                   | Yes  | No  | File asset ID.                                          |
| uri                       | string                   | Yes  | No  | File asset URI, for example, **dataability:///media/image/2**.        |
| mimeType                  | string                   | Yes  | No  | Extended file attributes.                                          |
| mediaType<sup>8+</sup>    | [MediaType](#mediatype8) | Yes  | No  | Media type.                                              |
| displayName               | string                   | Yes  | Yes  | Display file name, including the file name extension.                                |
| title                     | string                   | Yes  | Yes  | Title in the file.                                              |
| relativePath<sup>8+</sup> | string                   | Yes  | Yes  | Relative public directory of the file.                                      |
| parent<sup>8+</sup>       | number                   | Yes  | No  | Parent directory ID.                                              |
| size                      | number                   | Yes  | No  | File size, in bytes.                                |
| dateAdded                 | number                   | Yes  | No  | Date when the file was added. (The value is the number of seconds elapsed since the Epoch time.)        |
| dateModified              | number                   | Yes  | No  | Date when the file was modified. (The value is the number of seconds elapsed since the Epoch time.)        |
| dateTaken                 | number                   | Yes  | No  | Date when the file (photo) was taken. (The value is the number of seconds elapsed since the Epoch time.)        |
| artist<sup>8+</sup>       | string                   | Yes  | No  | Artist of the file.                                                  |
| audioAlbum<sup>8+</sup>   | string                   | Yes  | No  | Audio album.                                                  |
| width                     | number                   | Yes  | No  | Image width, in pixels.                                |
| height                    | number                   | Yes  | No  | Image height, in pixels.                                |
| orientation               | number                   | Yes  | Yes  | Image display direction (clockwise rotation angle, for example, 0, 90, or 180, in degrees).|
| duration<sup>8+</sup>     | number                   | Yes  | No  | Duration, in ms.                                  |
| albumId                   | number                   | Yes  | No  | ID of the album to which the file belongs.                                  |
| albumUri<sup>8+</sup>     | string                   | Yes  | No  | URI of the album to which the file belongs.                                     |
| albumName                 | string                   | Yes  | No  | Name of the album to which the file belongs.                                    |


### isDirectory<sup>8+</sup>

isDirectory(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is a directory. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                 |
| -------- | ---------------------------- | ---- | ------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return whether the file asset is a directory.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isDirectory((err, isDirectory) => {
        // do something
    });
}
```

### isDirectory<sup>8+</sup>

isDirectory():Promise&lt;boolean&gt;

Checks whether this file asset is a directory. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                    | Description                          |
| ---------------------- | ---------------------------- |
| Promise&lt;boolean&gt; | Promise used to return whether the file asset is a directory.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isDirectory().then(function(isDirectory){
        console.info("isDirectory result:"+ isDirectory);
    }).catch(function(err){
        console.info("isDirectory failed with error:"+ err);
    });
}
```

### commitModify<sup>8+</sup>

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification in this file asset to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Void callback.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.title = 'newtitle';
    asset.commitModify(() => {
        console.info('commitModify success');   
    });
}
```

### commitModify<sup>8+</sup>

commitModify(): Promise&lt;void&gt;

Commits the modification in this file asset to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Void promise.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.title = 'newtitle';
    asset.commitModify();
}
```

### open<sup>8+</sup>

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens this file asset. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> Currently, the write operations are mutually exclusive. After the write operation is complete, you must call **close** to release the resource.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | Yes   | Mode of opening the file, for example, **'r'** (read-only), **'w'** (write-only), and **'rw'** (read-write).|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the file handle.                           |

**Example**

```js
async function example() {
    let mediaType = mediaLibrary.MediaType.IMAGE;
    let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
    const path = await media.getPublicDirectory(DIR_IMAGE);
    const asset = await media.createAsset(mediaType, "image00003.jpg", path);
    asset.open('rw', (openError, fd) => {
            if(fd > 0){
                asset.close(fd);
            }else{
                console.info('File Open Failed!' + openError);
            }
    });
}
```

### open<sup>8+</sup>

open(mode: string): Promise&lt;number&gt;

Opens this file asset. This API uses a promise to return the result.

>  **NOTE**
>  
> Currently, the write operations are mutually exclusive. After the write operation is complete, you must call **close** to release the resource.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type    | Mandatory  | Description                                 |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | Yes   | Mode of opening the file, for example, **'r'** (read-only), **'w'** (write-only), and **'rw'** (read-write).|

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise used to return the file handle.|

**Example**

```js
async function example() {
    let mediaType = mediaLibrary.MediaType.IMAGE;
    let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
    const path = await media.getPublicDirectory(DIR_IMAGE);
    const asset = await media.createAsset(mediaType, "image00003.jpg", path);
    asset.open('rw')
        .then((fd) => {
            console.info('File fd!' + fd);
        })
        .catch((err) => {
            console.info('File err!' + err);
        });
}
```

### close<sup>8+</sup>

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

Closes this file asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | Yes   | File descriptor.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Void callback.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.open('rw').then((fd) => {
        console.info('File fd!' + fd);
        asset.close(fd, (closeErr) => {
            if (closeErr != undefined) {
                console.info('mediaLibraryTest : close : FAIL ' + closeErr);
                console.info('mediaLibraryTest : ASSET_CALLBACK : FAIL');
            } else {
                console.info("=======asset.close success====>");
            }
        });
    })
    .catch((err) => {
        console.info('File err!' + err);
    });
}
```

### close<sup>8+</sup>

close(fd: number): Promise&lt;void&gt;

Closes this file asset. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| fd   | number | Yes   | File descriptor.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Void promise.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.open('rw').then((fd) => {
        console.info('File fd!' + fd);
        asset.close(fd).then((closeErr) => {
            if (closeErr != undefined) {
                console.info('mediaLibraryTest : close : FAIL ' + closeErr);
                console.info('mediaLibraryTest : ASSET_CALLBACK : FAIL');

            } else {
                console.info("=======asset.close success====>");
            }
        });
    })
    .catch((err) => {
        console.info('File err!' + err);
    });
}
```

### getThumbnail<sup>8+</sup>

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the thumbnail of this file asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes   | Callback used to return the pixel map of the thumbnail.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.getThumbnail((err, pixelmap) => {
        console.info('mediaLibraryTest : getThumbnail Successful '+ pixelmap);
    });
}
```

### getThumbnail<sup>8+</sup>

getThumbnail(size: Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the thumbnail of this file asset, with the thumbnail size passed. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [Size](#size8)                      | Yes   | Size of the thumbnail.           |
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes   | Callback used to return the pixel map of the thumbnail.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let size = { width: 720, height: 720 };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.getThumbnail(size, (err, pixelmap) => {
        console.info('mediaLibraryTest : getThumbnail Successful '+ pixelmap);
    });
}
```

### getThumbnail<sup>8+</sup>

getThumbnail(size?: Size): Promise&lt;image.PixelMap&gt;

Obtains the thumbnail of this file asset, with the thumbnail size passed. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| size | [Size](#size8) | No   | Size of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;image.PixelMap&gt; | Promise to return the pixel map of the thumbnail.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
    let size = { width: 720, height: 720 };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.getThumbnail(size)
    .then((pixelmap) => {
        console.info('mediaLibraryTest : getThumbnail Successful '+ pixelmap);
    })
    .catch((err) => {
        console.info('mediaLibraryTest : getThumbnail fail'+ err);
    });
}
```

### favorite<sup>8+</sup>

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void

Favorites or unfavorites this file asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | Yes   | Whether to favorite or unfavorite the file. The value **true** means to favorite the file, and **false** means to unfavorite the file.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Void callback.                             |

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.favorite(true,function(err){
        // do something
    });
}
```

### favorite<sup>8+</sup>

favorite(isFavorite: boolean): Promise&lt;void&gt;

Favorites or unfavorites this file asset. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| isFavorite | boolean | Yes   | Whether to favorite or unfavorite the file. The value **true** means to favorite the file, and **false** means to unfavorite the file.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Void promise.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.favorite(true).then(function() {
        console.info("favorite successfully");
    }).catch(function(err){
        console.info("favorite failed with error:"+ err);
    });
}
```

### isFavorite<sup>8+</sup>

isFavorite(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is favorited. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description         |
| -------- | ---------------------------- | ---- | ----------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return whether the file asset is favorited.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isFavorite((err, isFavorite) => {
        if (isFavorite) {
            console.info('FileAsset is favorite');
        }else{
            console.info('FileAsset is not favorite');
        }
    });
}
```

### isFavorite<sup>8+</sup>

isFavorite():Promise&lt;boolean&gt;

Checks whether this file asset is favorited. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                    | Description                |
| ---------------------- | ------------------ |
| Promise&lt;boolean&gt; | Promise used to return whether the file asset is favorited.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isFavorite().then(function(isFavorite){
        console.info("isFavorite result:"+ isFavorite);
    }).catch(function(err){
        console.info("isFavorite failed with error:"+ err);
    });
}
```

### trash<sup>8+</sup>

trash(isTrash: boolean, callback: AsyncCallback&lt;void&gt;): void

Moves this file asset to the trash. This API uses an asynchronous callback to return the result.

Files in the trash are not actually deleted. You can set **isTrash** to **false** to restore the files from the trash.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description       |
| -------- | ------------------------- | ---- | --------- |
| isTrash  | boolean                   | Yes   | Whether to move the file asset to the trash. The value **true** means to move the file asset to the trash, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Void callback.    |

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.trash(true, trashCallBack);
    function trashCallBack(err, trash) {
        console.info('mediaLibraryTest : ASSET_CALLBACK ASSET_CALLBACK trash');
    }
}
```

### trash<sup>8+</sup>

trash(isTrash: boolean): Promise&lt;void&gt;

Moves this file asset to the trash. This API uses a promise to return the result.

Files in the trash are not actually deleted. You can set **isTrash** to **false** to restore the files from the trash.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name    | Type     | Mandatory  | Description       |
| ------- | ------- | ---- | --------- |
| isTrash | boolean | Yes   | Whether to move the file asset to the trash. The value **true** means to move the file asset to the trash, and **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Void promise.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.trash(true).then(function() {
        console.info("trash successfully");
    }).catch(function(err){
        console.info("trash failed with error:"+ err);
    });
}
```

### isTrash<sup>8+</sup>

isTrash(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is in the trash. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return whether the file asset is in the trash. If the file asset is in the trash, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isTrash((err, isTrash) => {
      if (isTrash == undefined) {
        console.error('Failed to get trash state: ' + err);
        return;
      }
      console.info('Get trash state success: ' + isTrash);
    });
}
```

### isTrash<sup>8+</sup>

isTrash():Promise&lt;boolean&gt;

Checks whether this file asset is in the trash. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise used to return whether the file asset is in the trash. If the file asset is in the trash, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
    };
    const fetchFileResult = await media.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isTrash().then(function(isTrash){
      console.info("isTrash result: " + isTrash);
    }).catch(function(err){
      console.error("isTrash failed with error: " + err);
    });
}
```

## FetchFileResult<sup>7+</sup>

Implements the result set of the file retrieval operation.

### getCount<sup>7+</sup>

getCount(): number

Obtains the total number of files in the result set.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Total number of files.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let fileType = mediaLibrary.MediaType.FILE;
    let getFileCountOneOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getFileCountOneOp);
    const fetchCount = fetchFileResult.getCount();
}
```

### isAfterLast<sup>7+</sup>

isAfterLast(): boolean

Checks whether the cursor is in the last row of the result set.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type     | Description                                |
| ------- | ---------------------------------- |
| boolean | Returns **true** if the cursor is in the last row of the result set; returns *false* otherwise.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    const fetchCount = fetchFileResult.getCount();
    console.info('mediaLibraryTest : count:' + fetchCount);
    let fileAsset = await fetchFileResult.getFirstObject();
    for (var i = 1; i < fetchCount; i++) {
            fileAsset = await fetchFileResult.getNextObject();
            if(i == fetchCount - 1) {
              console.info('mediaLibraryTest : isLast');
              var result = fetchFileResult.isAfterLast();
              console.info('mediaLibraryTest : isAfterLast:' + result);
              console.info('mediaLibraryTest : isAfterLast end');
              fetchFileResult.close();

            }
    }
}
```

### close<sup>7+</sup>

close(): void

Releases and invalidates this **FetchFileResult** instance. Other APIs in this instance cannot be invoked after it is released.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.close();
}
```

### getFirstObject<sup>7+</sup>

getFirstObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the first file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes  | Callback used to return the first file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.getFirstObject((err, fileAsset) => {
       if (err) {
           console.error('Failed ');
           return;
       }
       console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getFirstObject<sup>7+</sup>

getFirstObject(): Promise&lt;FileAsset&gt;

Obtains the first file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.getFirstObject().then(function(fileAsset){
        console.info("getFirstObject successfully:"+ JSON.stringify(fileAsset));
    }).catch(function(err){
        console.info("getFirstObject failed with error:"+ err);
    });
}
```

### getNextObject<sup>7+</sup>

 getNextObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the next file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                                         | Mandatory| Description                                     |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes  | Callback used to return the next file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.getNextObject((err, fileAsset) => {
       if (err) {
           console.error('Failed ');
           return;
       }
       console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getNextObject<sup>7+</sup>

 getNextObject(): Promise&lt;FileAsset&gt;

Obtains the next file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the next file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    const fetchCount = fetchFileResult.getCount();
    console.info('mediaLibraryTest : count:' + fetchCount);
    let fileAsset = await fetchFileResult.getNextObject();
}
```

### getLastObject<sup>7+</sup>

getLastObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the last file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                       |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes  | Callback used to return the last file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.getLastObject((err, fileAsset) => {
       if (err) {
           console.error('Failed ');
           return;
       }
       console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getLastObject<sup>7+</sup>

getLastObject(): Promise&lt;FileAsset&gt;

Obtains the last file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the next file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    let lastObject = await fetchFileResult.getLastObject();
}
```

### getPositionObject<sup>7+</sup>

getPositionObject(index: number, callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains a file asset with the specified index in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | Yes   | Index of the file asset to obtain. The value starts from **0**.    |
| callback | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes   | Callback used to return the last file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.getPositionObject(0, (err, fileAsset) => {
       if (err) {
           console.error('Failed ');
           return;
       }
       console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getPositionObject<sup>7+</sup>

getPositionObject(index: number): Promise&lt;FileAsset&gt;

Obtains a file asset with the specified index in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type    | Mandatory  | Description            |
| ----- | ------ | ---- | -------------- |
| index | number | Yes   | Index of the file asset to obtain. The value starts from **0**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the next file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.getPositionObject(1) .then(function (fileAsset){
        console.log('fileAsset.displayName : ' + fileAsset.displayName);
    }).catch(function (err) {
        console.info("getFileAssets failed with error:" + err);
    });
}
```

### getAllObject<sup>7+</sup>

getAllObject(callback: AsyncCallback&lt;Array&lt;FileAsset&gt;&gt;): void

Obtains all the file assets in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                  |
| -------- | ---------------------------------------- | ---- | -------------------- |
| callback | AsyncCallback<Array<[FileAsset](#fileasset7)>> | Yes   | Callback used to return the file assets.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    fetchFileResult.getAllObject((err, fileAsset) => {
        if (err) {
           console.error('Failed ');
           return;
        }
        for (let i = 0; i < fetchFileResult.getCount(); i++) {
            console.log('fileAsset.displayName : ' + fileAsset[i].displayName);
        } 
    })
}
```

### getAllObject<sup>7+</sup>

getAllObject(): Promise&lt;Array&lt;FileAsset&gt;&gt;

Obtains all the file assets in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                    | Description                 |
| ---------------------------------------- | --------------------- |
| Promise<Array<[FileAsset](#fileasset7)>> | Promise used to return the file assets.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()],
      order: fileKeyObj.DATE_ADDED + " DESC",
      extendArgs: "",
    };
    let fetchFileResult = await media.getFileAssets(getImageOp);
    var data = fetchFileResult.getAllObject();
}
```

## Album<sup>7+</sup>

Provides APIs to implement a physical album.

### Attributes

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name          | Type   | Readable  | Writable  | Description     |
| ------------ | ------ | ---- | ---- | ------- |
| albumId | number | Yes   | No   | Album ID.   |
| albumName | string | Yes   | Yes   | Album name.   |
| albumUri<sup>8+</sup> | string | Yes   | No   | Album URI.  |
| dateModified | number | Yes   | No   | Date when the album was modified.   |
| count<sup>8+</sup> | number | Yes   | No   | Number of files in the album.|
| relativePath<sup>8+</sup> | string | Yes   | No   | Relative path of the album.   |
| coverUri<sup>8+</sup> | string | Yes   | No   | URI of the cover file of the album.|

### commitModify<sup>8+</sup>

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification in the album attributes to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Void callback.|

**Example**

```js
async function example() {
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    const album = albumList[0];
    album.albumName = 'hello';
    album.commitModify((err) => {
       if (err) {
           console.error('Failed ');
           return;
       }
       console.log('Modify successful.');
    })
}
```

### commitModify<sup>8+</sup>

commitModify(): Promise&lt;void&gt;

Commits the modification in the album attributes to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Void promise.|

**Example**

```js
async function example() {
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    const album = albumList[0];
    album.albumName = 'hello';
    album.commitModify().then(function() {
        console.info("commitModify successfully");
    }).catch(function(err){
        console.info("commitModify failed with error:"+ err);
    });
}
```

### getFileAssets<sup>7+</sup>

getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void

Obtains the file assets in this album. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                               |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| options  | [MediaFetchOptions](#mediafetchoptions7)            | Yes  | Options for fetching the files.                     |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult7)> | Yes  | Callback used to return the file assets.|

**Example**

```js
async function example() {
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    let fileNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
    }
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    const album = albumList[0];
    album.getFileAssets(fileNoArgsfetchOp, getFileAssetsCallBack);
    function getFileAssetsCallBack(err, fetchFileResult) {
        // do something
    }
}
```

### getFileAssets<sup>7+</sup>

 getFileAssets(options?: MediaFetchOptions): Promise&lt;FetchFileResult&gt;

Obtains the file assets in this album. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type                                    | Mandatory| Description          |
| ------- | ---------------------------------------- | ---- | -------------- |
| options | [MediaFetchOptions](#mediafetchoptions7) | No  | Options for fetching the files.|

**Return value**

| Type                                         | Description                     |
| --------------------------------------------- | ------------------------- |
| Promise<[FetchFileResult](#fetchfileresult7)> | Promise used to return the file assets.|

**Example**

```js
async function example() {
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    let fileNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
    };
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    const album = albumList[0];
    album.getFileAssets(fileNoArgsfetchOp).then(function(albumFetchFileResult){
        console.info("getFileAssets successfully:"+ JSON.stringify(albumFetchFileResult));
    }).catch(function(err){
        console.info("getFileAssets failed with error:"+ err);
    });
}
```

## PeerInfo<sup>8+</sup>

Describes information about a registered device.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

| Name      | Type                      | Readable| Writable| Description            |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | Yes  | No  | Name of the registered device.  |
| networkId  | string                     | Yes  | No  | Network ID of the registered device.|
| deviceType | [DeviceType](#devicetype8) | Yes  | No  | Type of the registered device.        |
| isOnline   | boolean                    | Yes  | No  | Whether the registered device is online.        |



## MediaType<sup>8+</sup>

Enumerates media types.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name |  Description|
| ----- |  ---- |
| FILE  |  File.|
| IMAGE |  Image.|
| VIDEO |  Video.|
| AUDIO |  Audio.|

## FileKey<sup>8+</sup>

Enumerates key file information.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name         | Default Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| ID            | file_id             | File ID.                                                  |
| RELATIVE_PATH | relative_path       | Relative public directory of the file.                                          |
| DISPLAY_NAME  | display_name        | Display file name.                                                  |
| PARENT        | parent              | Parent directory ID.                                                  |
| MIME_TYPE     | mime_type           | Extended file attributes.                                              |
| MEDIA_TYPE    | media_type          | Media type.                                                  |
| SIZE          | size                | File size, in bytes.                                    |
| DATE_ADDED    | date_added          | Date when the file was added. (The value is the number of seconds elapsed since the Epoch time.)            |
| DATE_MODIFIED | date_modified       | Date when the file was modified. (The value is the number of seconds elapsed since the Epoch time.)            |
| DATE_TAKEN    | date_taken          | Date when the file (photo) was taken. (The value is the number of seconds elapsed since the Epoch time.)            |
| TITLE         | title               | Title in the file.                                                  |
| ARTIST        | artist              | Artist of the file.                                                      |
| AUDIOALBUM    | audio_album         | Audio album.                                                      |
| DURATION      | duration            | Duration, in ms.                                      |
| WIDTH         | width               | Image width, in pixels.                                    |
| HEIGHT        | height              | Image height, in pixels.                                    |
| ORIENTATION   | orientation         | Image display direction (clockwise rotation angle, for example, 0, 90, and 180, in degrees).|
| ALBUM_ID      | bucket_id           | ID of the album to which the file belongs.                                      |
| ALBUM_NAME    | bucket_display_name | Name of the album to which the file belongs.                                        |

## DirectoryType<sup>8+</sup>

Enumerates directory types.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name         |  Description              |
| ------------- |  ------------------ |
| DIR_CAMERA    |  Directory of camera files.|
| DIR_VIDEO     |  Directory of video files.      |
| DIR_IMAGE     |  Directory of image files.      |
| DIR_AUDIO     |  Directory of audio files.      |
| DIR_DOCUMENTS |  Directory of documents.      |
| DIR_DOWNLOAD  |  Download directory.      |

## DeviceType<sup>8+</sup>

Enumerates device types.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

| Name        |  Description      |
| ------------ |  ---------- |
| TYPE_UNKNOWN |  Unknown.|
| TYPE_LAPTOP  |  Laptop.|
| TYPE_PHONE   |  Phone.      |
| TYPE_TABLET  |  Tablet.  |
| TYPE_WATCH   |  Smart watch.  |
| TYPE_CAR     |  Vehicle-mounted device.  |
| TYPE_TV      |  TV.  |

## MediaFetchOptions<sup>7+</sup>

Describes options for fetching media files.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name                   | Type               | Readable| Writable| Mandatory| Description                                                        |
| ----------------------- | ------------------- | ---- | ---- | ---- | ------------------------------------------------------------ |
| selections              | string              | Yes  | Yes  | Yes  | Conditions for fetching files. The enumerated values in [FileKey](#filekey8) are used as the column names of the conditions. Example:<br>selections: mediaLibrary.FileKey.MEDIA_TYPE + '= ? OR ' +mediaLibrary.FileKey.MEDIA_TYPE + '= ?', |
| selectionArgs           | Array&lt;string&gt; | Yes  | Yes  | Yes  | Value of the condition, which corresponds to the value of the condition column in **selections**.<br>Example:<br>selectionArgs: [mediaLibrary.MediaType.IMAGE.toString(), mediaLibrary.MediaType.VIDEO.toString()], |
| order                   | string              | Yes  | Yes  | No  | Sorting mode of the search results, which can be ascending or descending. The enumerated values in [FileKey](#filekey8) are used as the columns for sorting the search results. Example:<br>Ascending: order: mediaLibrary.FileKey.DATE_ADDED + " ASC"<br>Descending: order: mediaLibrary.FileKey.DATE_ADDED + " DESC"|
| uri<sup>8+</sup>        | string              | Yes  | Yes  | No  | File URI.                                                     |
| networkId<sup>8+</sup>  | string              | Yes  | Yes  | No  | Network ID of the registered device.                                              |
| extendArgs<sup>8+</sup> | string              | Yes  | Yes  | No  | Extended parameters for fetching the files. Currently, no extended parameters are available.                        |

## Size<sup>8+</sup>

Describes the image size.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name    | Type    | Readable  | Writable  | Description      |
| ------ | ------ | ---- | ---- | -------- |
| width  | number | Yes   | Yes   | Image width, in pixels.|
| height | number | Yes   | Yes   | Image height, in pixels.|

## MediaAssetOption<sup>(deprecated)</sup>

Implements the media asset option.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core


| Name        | Type  | Mandatory| Description                                                        |
| ------------ | ------ | ---- | ------------------------------------------------------------ |
| src          | string | Yes  | Application sandbox oath of the local file.                                      |
| mimeType     | string | Yes  | Multipurpose Internet Mail Extensions (MIME) type of the media.<br>The value can be 'image/\*', 'video/\*', 'audio/\*' or 'file\*'.|
| relativePath | string | No  | Custom path for storing media assets, for example, 'Pictures/'. If this parameter is unspecified, media assets are stored in the default path.<br> Default path of images: 'Pictures/'<br> Default path of videos: 'Videos/'<br> Default path of audios: 'Audios/'<br> Default path of files: 'Documents/'|

## MediaSelectOption<sup>(deprecated)</sup>

Describes media selection option.

> **NOTE**
>
> This API is deprecated since API version 9.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name   | Type    | Mandatory  | Description                  |
| ----- | ------ | ---- | -------------------- |
| type  | string | Yes   | Media type, which can be **image**, **media**, or **video**. Currently, only **media** is supported.|
| count | number | Yes   | Number of media assets selected. The value starts from 1, which indicates that one media asset can be selected.           |

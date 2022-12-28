# Media Asset Management

Your applications can use the APIs provided by the **mediaLibrary** module to perform operations on media assets such as audios, videos, images, and files.

> **NOTE**
>
> Before developing features, read [MediaLibrary Overview](medialibrary-overview.md) to learn how to obtain a **MediaLibrary** instance and request the permissions to call the APIs of **MediaLibrary**.

To maximize the application running efficiency, most **MediaLibrary** API calls are asynchronous in callback or promise mode. The following code samples use the promise mode. For details about the APIs, see [MediaLibrary API Reference](../reference/apis/js-apis-medialibrary.md).

## Querying Media Assets

You can query media assets by condition such as the media type, date, or album name.

To do so, call [MediaLibrary.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-1), with a **MediaFetchOptions** object passed in to specify the conditions. In this object, **MediaFetchOptions.selections** are the retrieval conditions, and the enumerated values of **FileKey** are used as the column names of the conditions; **MediaFetchOptions.selectionArgs** are the values of the conditions. You can also specify **order** (sorting mode of the search result), **uri** (file URI), and **networkId** (network ID of the registered device) as the conditions.

To obtain the object at the specified position (for example, the first, the last, or with the specified index) in the result set, call [FetchFileResult](../reference/apis/js-apis-medialibrary.md#fetchfileresult7). In this section, **getNextObject** is used cyclically to obtain all media assets in the result set.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.READ_MEDIA**.

### Querying Media Assets with the Specified Media Type

The following describes how to obtain images.

**How to Develop**

To specify the media type as the retrieval condition, set **selections** to **FileKey.MEDIA_TYPE**.

To specify the image as the media type, set **selectionArgs** to **MediaType.IMAGE**.

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.IMAGE
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

### Querying Media Assets with the Specified Date

The following describes how to obtain media assets that are added on the specified date. You can also use the modification date and shooting date as the retrieval conditions.

To specify the date when the files are added as the retrieval condition, set **selections** to **FileKey.DATE_ADDED**.

To specify the date 2022-8-5, set **selectionArgs** to **2022-8-5**.

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let option = {
        selections: fileKeyObj.DATE_ADDED + '= ?',
        selectionArgs: ['2022-8-5'],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

### Querying Media Assets and Sorting Them

The following describes how to query images and sort them in descending order by the date when they are added. You can also sort them in ascending order.

To sort files in descending order by the date when they are added, set **order** to **FileKey.DATE_ADDED + " DESC"**.

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.IMAGE
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

### Querying Media Assets with the Specified Album Name

The following describes how to query media assets in **myAlbum**.

To specify the album name as the retrieval condition, set **selections** to **FileKey.ALBUM_NAME**.

To specify the album name **'myAlbum'**, set **selectionArgs** to **'myAlbum'**.

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.IMAGE
    let option = {
        selections: fileKeyObj.ALBUM_NAME + '= ?',
        selectionArgs: ['myAlbum'],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

## Obtaining Images and Videos in an Album

You can obtain media assets in an album in either of the following ways:

- Call [MediaLibrary.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-1) with an album specified, as described in [Querying Media Assets with the Specfied Album Name](#querying-media-assets-with-the-specified-album-name).
- Call [Album.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-3) to obtain an **Album** instance, so as to obtain the media assets in it.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.READ_MEDIA**.

**How to Develop**

The following describes how to obtain videos in an album named **New Album 1**.

1. Create a retrieval condition for obtaining the target **Album** instance.

   ```ts
   let fileKeyObj = mediaLibrary.FileKey;
   let AlbumNoArgsFetchOp = {
       selections: fileKeyObj.ALBUM_NAME + '= ?',
       selectionArgs:['New Album 1']
   }
   ```

2. Create a retrieval condition for obtaining videos in the target album.

   ```ts
   let fileKeyObj = mediaLibrary.FileKey;
   let imageType = mediaLibrary.MediaType.VIDEO;
   let imagesFetchOp  = {
       selections: fileKeyObj.MEDIA_TYPE + '= ?',
       selectionArgs: [imageType.toString()],
   }
   ```

3. Call **Album.getFileAssets** to obtain the videos in the target album.

Complete sample code:

```ts
async function getCameraImagePromise() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let imagesFetchOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
    }
    let AlbumNoArgsFetchOp = {
        selections: fileKeyObj.ALBUM_NAME + '= ?',
        selectionArgs:['New Album 1']
    }

    let albumList = await media.getAlbums(AlbumNoArgsFetchOp);
    if (albumList.length > 0) {
        const album = albumList[0];
        let fetchFileResult = await album.getFileAssets(imagesFetchOp);
        let count = fetchFileResult.getCount();
        console.info("get mediaLibrary IMAGE number", count);
    } else {
        console.info('getAlbum list is: 0');
    }
}
```

## Obtaining the Thumbnail of an Image or a Video

You can call [FileAsset.getThumbnail](../reference/apis/js-apis-medialibrary.md#getthumbnail8-2) with the thumbnail size passed in to obtain the thumbnail of an image or a video. Your application can use thumbnails to offer a quick preview on images and videos.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.READ_MEDIA**.

### Obtaining the Thumbnail of an Image

The following describes how to obtain the thumbnail (size: 720 x 720) of the first image in the album.

**How to Develop**

1. Create a retrieval condition for obtaining images in the target album.
2. Call **getFileAssets** to obtain the images in the target album.
3. Call **getFirstObject** to obtain the first image among all the images obtained.
4. Call **getThumbnail** to obtain the thumbnail of the first image.

```ts
async function getFirstThumbnailPromise() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let imagesFetchOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
    }

    let size = { width: 720, height: 720 };
    const fetchFileResult = await media.getFileAssets(imagesFetchOp);
    if (fetchFileResult != undefined) {
        const asset = await fetchFileResult.getFirstObject();
        asset.getThumbnail(size).then((pixelMap) => {
          pixelMap.getImageInfo().then((info) => {
              console.info('get Thumbnail info: ' + "width: " + info.size.width + " height: " + info.size.height);
          }).catch((err) => {
              console.info("getImageInfo failed with error:" + err);
          });
        }).catch((err) => {
            console.info("getImageInfo failed with error:" + err);
        });
    } else {
        console.info("get image failed with error");
    }
}
```

## Creating a Media Asset

You can call [MediaLibrary.createAsset](../reference/apis/js-apis-medialibrary.md#createasset8-1) to create a media asset.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.WRITE_MEDIA**.
- [You have obtained a public directory](medialibrary-filepath-guidelines.md).

The following describes how to create a file of the **MediaType.FILE** type.

```ts
async function example() {
    let mediaType = mediaLibrary.MediaType.FILE;
    let DIR_DOCUMENTS = mediaLibrary.DirectoryType.DIR_DOCUMENTS;
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const path = await media.getPublicDirectory(DIR_DOCUMENTS);
    media.createAsset(mediaType, "testFile.text", path).then ((asset) => {
        console.info("createAsset successfully:"+ JSON.stringify(asset));
    }).catch((err) => {
        console.info("createAsset failed with error:"+ err);
    });
}
```

## Moving a Media Asset to the Recycle Bin

You can use [FileAsset.trash](../reference/apis/js-apis-medialibrary.md#trash8) to move a media asset to the recycle bin.

By default, files in the recycle bin will be stored for 30 days before being permanently removed. During this period, you can set **isTrash** in **trash** to **false** to recover the files. Application users can also recover the files through the system applications **Files** or **Gallery**.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.WRITE_MEDIA**.

The following describes how to move the first file in the result set to the recycle bin.

**How to Develop**

1. Create a retrieval condition for obtaining images in the target album.
2. Call **getFileAssets** to obtain the images in the target album.
3. Call **getFirstObject** to obtain the first image among all the images obtained.
4. Call **trash** to move the first image to the recycle bin.

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.FILE
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
    // Void callback.
    asset.trash(true).then(() => {
        console.info("trash successfully");
    }).catch((err) => {
        console.info("trash failed with error:"+ err);
    });
}
```

## Renaming a Media Asset

To rename a media asset, modify the **FileAsset.displayName** attribute (which specifies the displayed file name, including the file name extension) and commit the modification through [FileAsset.commitModify](../reference/apis/js-apis-medialibrary.md#commitmodify8-1).

Before renaming a file, you must obtain the file, for example, by calling [FetchFileResult](../reference/apis/js-apis-medialibrary.md#fetchfileresult7).

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.WRITE_MEDIA**.

The following describes how to rename the first file in the result set as **newtitle.text**.

**How to Develop**

1. Create a retrieval condition for obtaining images in the target album.
2. Call **getFileAssets** to obtain the images in the target album.
3. Call **getFirstObject** to obtain the first image among all the images obtained.
4. Rename the image as **newImage.jpg**.
5. Call **FileAsset.commitModify** to commit the modification to the database.

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.FILE
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
    asset.displayName = 'newImage.jpg';
    // Void callback.
    asset.commitModify((err) => {
       if (err) {
           console.error('fileRename Failed ');
           return;
       }
       console.log('fileRename successful.');
    })
}
```

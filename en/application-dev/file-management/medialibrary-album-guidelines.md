# Album Management

You can use the APIs provided by the **mediaLibrary** module to create and delete an album and obtain images in the album.

> **NOTE**
>
> Before developing features, read [MediaLibrary Overview](medialibrary-overview.md) to learn how to obtain a **MediaLibrary** instance and request the permissions to call the APIs of **MediaLibrary**.

To ensure the application running efficiency, most **MediaLibrary** API calls are asynchronous, and both callback and promise modes are provided for these APIs. The following code samples use the promise mode. For details about the APIs, see [MediaLibrary API Reference](../reference/apis/js-apis-medialibrary.md).

## Obtaining Images and Videos in an Album

You can obtain images and videos in an album in either of the following ways:

- Call [MediaLibrary.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-1) with an album specified to obtain the media assets. For details, see [Querying Media Assets with the Specified Album Name](medialibrary-resource-guidelines.md#querying-media-assets-with-the-specified-album-name).

- Call [Album.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-3) to obtain an **Album** instance, so as to obtain the media assets in it. For details, see [Obtaining Images and Videos in an Album](medialibrary-resource-guidelines.md#obtaining-images-and-videos-in-an-album).

## Creating an Album

You can use [MediaLibrary.createAsset](../reference/apis/js-apis-medialibrary.md#createasset8-1), with the relative path set, to create an album while adding a media asset to the album. The relative path is the album name.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.WRITE_MEDIA**.

The following describes how to create an album named **myAlbum**.

**How to Develop**

1. Call **getPublicDirectory** to obtain the public directory that stores files of a certain type.

   For details about the operation, see [Obtaining a Public Directory](medialibrary-filepath-guidelines.md#obtaining-a-public-directory).

2. Call **createAsset** to create an image, with the relative path set to **path + 'myAlbum/'**.

   This operation creates an album and adds an image to it.

```ts
async function example() {
    let mediaType = mediaLibrary.MediaType.IMAGE;
    let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const path = await media.getPublicDirectory(DIR_IMAGE)
    // myAlbum is the path for storing the new file and the name of the new album.
    media.createAsset(mediaType, 'test.jpg', path + 'myAlbum/', (err, fileAsset) => {
        if (fileAsset != undefined) {
        console.info('createAlbum successfully, message = ' + fileAsset);
        } else {
        console.info('createAlbum failed, message = ' + err);
        }
    });
}
```

## Renaming an Album

Renaming modifies the **FileAsset.albumName** attribute of the album, that is, the album name. After the modification, call [Album.commitModify](../reference/apis/js-apis-medialibrary.md#commitmodify8-3) to commit the modification to the database.

**Prerequisites**

- You have obtained a **MediaLibrary** instance.
- You have granted the permission **ohos.permission.WRITE_MEDIA**.

The following describes how to rename the album **newAlbum**.

**How to Develop**

1. Create a retrieval condition for obtaining the target album.
2. Call **getAlbums** to obtain the album list.
3. Rename the album **newAlbum**.
4. Call **Album.commitModify** to commit the modification of the attributes to the database.

```ts
async function example() {
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    let albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    let album = albumList[0];
    album.albumName = 'newAlbum';
    // Void callback.
    album.commitModify().then(function() {
        console.info("albumRename successfully");
    }).catch(function(err){
        console.info("albumRename failed with error:"+ err);
    });
}
```

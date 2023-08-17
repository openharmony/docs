# File Subsystem Changelog


## cl.file.1 Change of the mediaLibrary Interface Compatibility

Changed the compatibility of some **mediaLibrary** APIs.

**Change Impact**

The compatibility of some [mediaLibrary](../../../application-dev/reference/apis/js-apis-medialibrary.md) APIs is changed.
For applications developed based on earlier versions, pay attention to the iterative update of deprecated APIs.

**Key API/Component Changes**

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void | Interface compatibility changed    |
| medialibrary   |  **function** getFileAssets(options: MediaFetchOptions): Promise&lt;FetchFileResult&gt; | Interface compatibility changed    |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback&lt;FileAsset&gt;): void| Interface compatibility changed    |
| medialibrary   |  **function** createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise&lt;FileAsset&gt;| Interface compatibility changed    |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions, callback: AsyncCallback&lt;Array&lt;Album&gt;&gt;): void | Interface compatibility changed    |
| medialibrary   |  **function** getAlbums(options: MediaFetchOptions): Promise&lt;Array&lt;Album&gt;&gt; | Interface compatibility changed    |
| medialibrary   |  **function** FileAsset.commitModify(callback: AsyncCallback&lt;void&gt;): void | Interface compatibility changed    |
| medialibrary   |  **function** FileAsset.commitModify(): Promise&lt;void&gt; | Interface compatibility changed    |

**Adaptation Guide**

**getFileAssets**

From API version 10, the albums represented by physical directories are replaced by logical albums, which allow multiple files in an album and presence of a file in multiple albums. This design, however, makes **parent**, **albumId**, **albumUri**, and **albumName** incompatible. They cannot be used as parameters of **MediaFetchOptions** in **getFileAssets()**. The following is an example of incorrect use of the APIs.

1. Call **getMediaLibrary** to obtain a **MediaLibrary** instance.
2. Create the file fetching options.
3. Call **getFileAssets** to obtain file assets.

**Example (incorrect)**:

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let albumId = 1;
    let getImageOp = {
      selections: fileKeyObj.ALBUM_ID + '= ?', // File assets cannot be obtained based on the parent, albumId, albumUri, and albumName attributes.
      selectionArgs: [albumId.toString()],
    };
    const fetchFileResult = await media.getFileAssets(getImageOp); // The obtained fetchFileResult is empty.
    const fileAsset = await fetchFileResult.getFirstObject();
    console.info('mediaLibrary fileAsset displayName: ' + fileAsset.displayName);
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

Use **getFileAssets()** as follows:

**Example (correct)**:

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
      selections: fileKeyObj.MEDIA_TYPE + '= ?',
      selectionArgs: [imageType.toString()], // Query all files of the image type.
    };
    const fetchFileResult = await media.getFileAssets(getImageOp); 
    const fileAsset = await fetchFileResult.getFirstObject();
    console.info('mediaLibrary fileAsset displayName: ' + fileAsset.displayName);
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

**createAsset**

Since the SDK of API version 10, **relativePath** is no longer associated with an album. After a file is created, the last-level directory of **relativePath** is not displayed as an album.

**getAlbums**

Since the SDK of API version 10, **relativePath** is no longer associated with an album. Therefore, **relativePath** cannot be used as a search criterion in **getAlbums**, and the values of **ALBUM_NAME** can be **Camera** and **Screenshots** only. The following is an example of incorrect use of the APIs.

1. Call **getMediaLibrary** to obtain a **MediaLibrary** instance.
2. Create the album fetching options.
3. Call **getAlbums** to obtain albums.

**Example (incorrect)**:

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let AlbumNoArgsfetchOp = {
      selections: mediaLibrary.FileKey.ALBUM_NAME + ' = ?',
      selectionArgs:['New album 1'], //Obtain the album named New album 1.
    };
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp); // The fetchFileResult returned is empty.
    for (let i = 0; i < albumList.length; i++) {
      console.info('mediaLibrary album albumName: ' + albumList[i].albumName);
    }
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

The following example shows how to obtain **Camera** and **Screenshots** albums:

**Example (correct)**:

```js
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

async function example() {
  try {
    let context = getContext(this);
    let media = mediaLibrary.getMediaLibrary(context);
    let AlbumNoArgsfetchOp = {
      selections: mediaLibrary.FileKey.ALBUM_NAME + ' = ? OR ' + mediaLibrary.FileKey.ALBUM_NAME + ' = ?',
      selectionArgs: ['Camera', 'Screenshots'], // Obtain the camera and screenshot albums.
    };
    const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    for (let i = 0; i < albumList.length; i++) {
      console.info('mediaLibrary album albumName: ' + albumList[i].albumName);
    }
  } catch (err) {
    console.error('mediaLibrary fail, err: ' + err);
  }
}
```

**FileAsset.commitModify**

The **orientation** attribute for audio is deleted from the SDK of API version 10. When **commitModify** is used, the **orientation** attribute of audio resources cannot be modified.
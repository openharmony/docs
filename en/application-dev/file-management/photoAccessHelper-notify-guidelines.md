# Managing Media Asset Change Notifications

The **photoAccessHelper** module provides APIs for listening for media asset (image, video, and album) changes.

> **NOTE**
>
> - Before you start, you need to obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [photoAccessHelper Overview](photoAccessHelper-overview.md).
> - By default, the **PhotoAccessHelper** instance obtained in [photoAccessHelper Overview](photoAccessHelper-overview.md) is used when **photoAccessHelper** APIs are used. If the code for obtaining the **PhotoAccessHelper** instance is not added, an error indicating that **photoAccessHelper** is not defined is reported.

The APIs related to media asset change notifications can be called asynchronously only in callback mode. This topic describes how to use some APIs. For more information about the APIs, see [Album Management](../reference/apis/js-apis-photoAccessHelper.md).
Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

## Listening for the Specified URI

Use [registerChange](../reference/apis/js-apis-photoAccessHelper.md#registerchange) to listen for the specified URI. When the observed object changes, the value of the listener callback will be returned.

### Listening for a PhotoAsset

Register a listener for the specified **PhotoAsset**. When the observed **PhotoAsset** changes, the listener callback will be invoked to return the change.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Listener for changes of an image. When the image is favorited, the listener callback will be invoked.

**How to Develop**

1. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
2. Register a listener for a **PhotoAsset**.
3. Add the **PhotoAsset** to **Favorites**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.uri : ' + fileAsset.uri);

    let onCallback = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(fileAsset.uri, false, onCallback);
    await fileAsset.setFavorite(true);
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```

### Listening for an Album

Register a listener for an album. When the observed album changes, the listener callback will be invoked to return the change.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Listener for a user album. When the album is renamed, the listener callback will be invoked.

**How to Develop**

1. [Obtain a user album](photoAccessHelper-userAlbum-guidelines.md#obtaining-a-user-album).
2. Register a listener for the user album.
3. Rename the user album.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  predicates.equalTo(albumName, 'albumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbums successfullyfully, albumName: ' + album.albumUri);

    let onCallback = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(album.albumUri, false, onCallback);
    album.albumName = 'newAlbumName' + Date.now();
    await album.commitModify();
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```

## Fuzzy Listening

You can set **forChildUris** to **true** to enable fuzzy listening.

If **uri** is an album URI, the value **true** of **forChildUris** enables listening for the changes of the files in the album, and the value **false** enables listening for only the changes of the album itself. 

If **uri** is the URI of a **photoAsset**, there is no difference between **true** and **false** for **forChildUris**.

If **uri** is **DefaultChangeUri**, **forChildUris** must be set to **true**. If **forChildUris** is **false**, the URI cannot be found and no notification can be received.

### Listening for All PhotoAssets

Register a listener for all **PhotoAssets**. When a **PhotoAsset** changes, the listener callback will be invoked.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Register a listener for all **PhotoAssets**. When a **PhotoAsset** is favorited, the listener callback will be invoked.

**How to Develop**

1. Register a listener for all **PhotoAssets**.
2. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
3. Add the media asset to **Favorites**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let onCallback = (changeData: photoAccessHelper.ChangeData) => {
    console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(photoAccessHelper.DefaultChangeUri.DEFAULT_PHOTO_URI, true, onCallback);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    await photoAsset.setFavorite(true);
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```

## Unregistering Listening for a URI

Use [unRegisterChange](../reference/apis/js-apis-photoAccessHelper.md#unregisterchange) to unregister the listening for the specified URI. Multiple listeners can be registered for a URI. If multiple listener callbacks exist, you can unregister a listener callback registered. If callback is not specified, all listeners of the URI will be unregistered.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Unregister listening for an image. After that, the unregistered listener callback will not be invoked when the image favorite status is changed.

**How to Develop**

1. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
2. Unregister listening for the URI of the media asset obtained.
3. Add the media asset to **Favorites**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);

    let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback1, changData: ' + JSON.stringify(changeData));
    }
    let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback2, changData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);
    phAccessHelper.unRegisterChange(photoAsset.uri, onCallback1);
    await photoAsset.setFavorite(true);
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```

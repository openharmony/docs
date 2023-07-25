# Media Asset (Image, Video, and Album) Change Notification Management

The **photoAccessHelper** module provides APIs for listening for media asset changes.

> **NOTE**
>
> Before you start, refer to [photoAccessHelper Overview](photoAccessHelper-overview.md) to learn how to obtain a **photoAccessHelper** instance and apply for permissions required.
> By default, the **photoAccessHelper** instance obtained in [photoAccessHelper Overview](photoAccessHelper-overview.md) is used when **photoAccessHelper** APIs are used. If the code for obtaining the **photoAccessHelper** instance is not added, an error indicating that **photoAccessHelper** is not defined is reported.

The APIs related to media asset change notifications can be called asynchronously only in callback mode. This topic describes how to use some APIs. For more information about the APIs, see [Album Management](../reference/apis/js-apis-photoAccessHelper.md).
Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

## Listening for the Specified URI

Use [registerChange](../reference/apis/js-apis-photoAccessHelper.md#registerchange) to listen for the specified URI. When the observed object changes, the value of the listener callback will be returned.

### Registering a Listener for a File Asset

Registers a listener for the specified file asset. When the observed file asset changes, the listener callback will be invoked to return the change.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Register a listener for an image. When the image is favorited, the listener callback will be invoked.

**How to Develop**

1. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
2. Register a listener for the media asset obtained.
3. Add the media asset to **Favorites**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo(photoAccessHelper.ImageVideoKey.DISPLAY_NAME, 'test.jpg');
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('getAssets fileAsset.uri : ' + fileAsset.uri);

  let onCallback = (changeData) => {
    console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(fileAsset.uri, false, onCallback);

  await fileAsset.favorite(true);
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```

### Registering a Listener for an Album

Registers a listener for an album. When the observed album changes, the listener callback will be invoked to return the change.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Register a listener for a user album. When the album is renamed, the listener callback will be invoked.

**How to Develop**

1. [Obtain the user album](photoAccessHelper-userAlbum-guidelines.md#obtaining-a-use-album].
2. Register a listener for the user album.
3. Rename the user album.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
let albumName = photoAccessHelper.AlbumKey.ALBUM_NAME;
predicates.equalTo(albumName, 'albumName');
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
  let album = await fetchResult.getFirstObject();
  console.info('getAlbums successfullyfully, albumName: ' + album.albumUri);

  let onCallback = (changeData) => {
    console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(album.albumUri, false, onCallback);

  album.albumName = 'newAlbumName' + Date.now();
  await album.commitModify();
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```

## Fuzzy Listening

You can set **forChildUris** to **true** to register fuzzy listening. When **uri** is an album URI, the value **true** of **forChildUris** listens for the changes of the files in the album, and the value **false** listens for only the changes of the album itself. <br>If **uri** is the URI of a **fileAsset**, there is no difference between **true** and **false** for **forChildUris**.<br>If **uri** is **DefaultChangeUri**, **forChildUris** must be set to **true**. If **forChildUris** is **false**, the URI cannot be found and no message can be received.

### Registering a Listener for All FileAssets

Register listening for all FileAssets. When an observed FileAsset changes, the listener callback will be invoked.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Register a listener for all FileAssets. When an observed FileAsset is favorited, the listener callback will be invoked.

**How to Develop**

1. Register a listener for all FileAssets.
2. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
3. Add the media asset obtained to **Favorites**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let onCallback = (changeData) => {
  console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
}
phAccessHelper.registerChange(photoAccessHelper.DefaultChangeUri.DEFAULT_PHOTO_URI, true, onCallback);

let predicates = new dataSharePredicates.DataSharePredicates();
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('getAssets fileAsset.uri : ' + fileAsset.uri);
  await fileAsset.favorite(true);
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```

## Unregistering the Listening for a URI

Use [unRegisterChange](../reference/apis/js-apis-photoAccessHelper.md#unregisterchange) to unregister the listening for the specified URI. Multiple listeners can be registered for a URI. If multiple listener callbacks exist, you can unregister a listener callback registered. If callback is not specified, all listeners of the URI will be unregistered.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Unregister the listening for an image. After that, the corresponding listener callback is not triggered when the image favorites status is changed.

**How to Develop**

1. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
2. Unregister the listening for the URI of the media asset obtained.
3. Add the media asset obtained to **Favorites**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo(photoAccessHelper.ImageVideoKey.DISPLAY_NAME, 'test.jpg');
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('getAssets fileAsset.uri : ' + fileAsset.uri);

  let onCallback1 = (changeData) => {
    console.info('onCallback1, changData: ' + JSON.stringify(changeData));
  }
  let onCallback2 = (changeData) => {
    console.info('onCallback2, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(fileAsset.uri, false, onCallback1);
  phAccessHelper.registerChange(fileAsset.uri, false, onCallback2);
  phAccessHelper.unRegisterChange(fileAsset.uri, onCallback1);

  await fileAsset.favorite(true);
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```

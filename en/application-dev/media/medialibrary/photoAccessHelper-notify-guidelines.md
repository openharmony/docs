# Observing Media Assets

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=00d7cb908705b920a9ee7ee48de288635f9580c9 translatedAt=2026-08-11T01:56:47.488Z pushedAt=2026-08-12T03:40:32.588Z -->

The photoAccessHelper module provides APIs to listen for changes of specified media assets.

> **NOTE**
>
> Before you get started, obtain a PhotoAccessHelper instance and apply for required permissions. For details, see [Before You Start](photoAccessHelper-preparation.md).
> Unless otherwise specified, the PhotoAccessHelper instance obtained in [Before You Start](photoAccessHelper-preparation.md) is used to call photoAccessHelper APIs. If the code for obtaining the PhotoAccessHelper instance is missing, an error will be reported to indicate that photoAccessHelper is not defined.

The APIs related to media asset change notifications can be called asynchronously only in callback mode. This section covers only some of these APIs. For details about all available APIs, see [Module Description](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md).

Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

## Listening for a URI

Use [registerChange](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#registerchange) to listen for a URI. When the observed object changes, the registered callback will be invoked to return the value.

### Listening for a Media Asset

Register a listener for a PhotoAsset instance. When the observed PhotoAsset changes, the registered callback will be invoked to return the change.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.

- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

The following example describes how to register a listener for an image and then delete the image. A callback will be invoked when the image is deleted.

**How to Develop**

1. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-media-assets).

2. Register a listener for the media asset.

3. Delete the media asset.

<!-- @[register_listener_to_photo_asset](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MediaResourceChangeNotificationsSample/entry/src/main/ets/registerlistenertophotoassetability/RegisterListenerToPhotoAssetAbility.ets) -->  

``` TypeScript
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

// ...

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> | null = null;
  try {
    fetchResult = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    let onCallback = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback successfully, changeData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback);
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    // ...
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
    // ...
  } finally {
    if (fetchResult !== null) {
      fetchResult.close();
    }
  }
}
```

### Listening for an Album

Register a listener for an album. When the observed album changes, the registered callback will be invoked to return the change.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.

- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

The following example describes how to register a listener for a user album and then rename the album. A callback will be invoked when the album is renamed.

**How to Develop**

1. [Obtain a user album](photoAccessHelper-userAlbum-guidelines.md#obtaining-a-user-album).

2. Register a listener for the user album.

3. Rename the user album.

<!-- @[register_listener_to_album](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MediaResourceChangeNotificationsSample/entry/src/main/ets/registerlistenertoalbumability/RegisterListenerToAlbumAbility.ets) -->  

``` TypeScript
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

// ...

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  predicates.equalTo(albumName, 'test');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> | null = null;
  try {
    fetchResult = await phAccessHelper.getAlbums(
      photoAccessHelper.AlbumType.USER,
      photoAccessHelper.AlbumSubtype.USER_GENERIC,
      fetchOptions);
        
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbums successfully, albumUri: ' + album.albumUri);

    let onCallback = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback successfully, changeData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(album.albumUri, false, onCallback);
    album.albumName = 'newAlbumName' + Date.now();
    await album.commitModify();
    // ...
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
    // ...
  } finally {
    if (fetchResult !== null) {
      fetchResult.close();
    }
  }
}
```

## Fuzzy Listening

1. You can set **forChildUris** to **true** to enable fuzzy listening.<br>If **uri** is an album URI, the value **true** of **forChildUris** enables listening for the changes of the files in the album, and the value **false** enables listening for only the changes of the album itself.

2. If **uri** is **photoAsset**, there is no difference whether **forChildUris** is **true** or **false**.

3. If **uri** is **DefaultChangeUri**, **forChildUris** must be **true**. If **forChildUris** is set to **false**, the URI cannot be found and no message can be received.

### Listening for All PhotoAssets

Register a listener for all PhotoAsset instances. When a PhotoAsset instance changes, the registered callback will be invoked.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.

- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

The following example describes how to register a listener for all media assets and then delete a media asset. A callback will be invoked when the media asset is deleted.

**How to Develop**

1. Register a listener for all media assets.

2. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-media-assets).

3. Delete the media asset.

<!-- @[register_for_monitoring_all_assets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MediaResourceChangeNotificationsSample/entry/src/main/ets/registerformonitoringallassetsability/RegisterForMonitoringAllAssetsAbility.ets) -->  

``` TypeScript
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

// ...

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  let onCallback = (changeData: photoAccessHelper.ChangeData) => {
    console.info('onCallback successfully, changeData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(photoAccessHelper.DefaultChangeUri.DEFAULT_PHOTO_URI, true, onCallback);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> | null = null;
  try {
    fetchResult = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    // ...
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
    // ...
  } finally {
    if (fetchResult !== null) {
      fetchResult.close();
    }
  }
}
```

## Unregistering Listening for a URI

Use [unRegisterChange](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#unregisterchange) to unregister the listening for the specified URI. Multiple listeners can be registered for a URI. If multiple listener callbacks exist, you can specify a callback to unregister a specific listener. If no callback is specified, all listeners of the URI will be unregistered.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.

- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

The following example describes how to unregister the listening for an image and then delete the image. The unregistered listener callback will not be invoked when the image is deleted.

**How to Develop**

1. [Obtain a media asset](photoAccessHelper-resource-guidelines.md#obtaining-media-assets).

2. Unregister listening for the URI of the media asset obtained.

3. Delete the media asset.

<!-- @[cancel_listening_uri](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MediaResourceChangeNotificationsSample/entry/src/main/ets/cancellisteninguriability/CancelListeningURIAbility.ets) -->  

``` TypeScript
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

// ...

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> | null = null;
  try {
    fetchResult = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback1, changeData: ' + JSON.stringify(changeData));
    }
    let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback2, changeData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);
    phAccessHelper.unRegisterChange(photoAsset.uri, onCallback1);
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    // ...
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
    // ...
  } finally {
    if (fetchResult !== null) {
      fetchResult.close();
    }
  }
}
```
# Media Library Kit Changelog

## cl.medialibrary.1 Changed the Behavior of Certain APIs in @ohos.file.photoAccessHelper

**Access Level**

Public API

**Reason for Change**

To make the asset storage logic clearer, the mappings between assets and albums in the media library are modified. Previously, an image or video can exist in multiple logical albums through mapping, but now each photo can belong to only one physical album.

**Change Impact**

This change is a non-compatible change.

1. Adding assets to an album with **addAssets**

    Before: The assets obtained from query are directly added.

    After: A copy of the asset is added.

2. Removing assets from an album with **removeAssets**

    Before: The mapping between the album and asset is removed.

    After: The asset is moved to the recycle bin.

3. Setting the album name with **setAlbumName** and **commitModify**

    Before: The album_name attribute of the album is directly changed.
  
    After: The album is deleted, and a new one with the same metadata is created with the new name.

4. Registering a listener for the specified URI with **registerChange**

    Before: The listener is registered for the asset URI obtained from query, and notifications are sent to that asset URI for any additions, deletions, or modifications.

    After: Operations such as Add and Remove are performed on the copies. Therefore, notifications are sent to the copy URI.


**Start API Level**

10 and API 11

**Change Since**

OpenHarmony 5.0.0.43

**Key API/Component Changes**

1. Adding assets to an album: addAssets(assets: Array\<PhotoAsset>): void

2. Removing assets from an album: removeAssets(assets: Array\<PhotoAsset>): void

3. Setting the album name:

   setAlbumName(name: string):void,

   commitModify(callback: AsyncCallback\<void>): void

4. Registering a listener for a specified URI: registerChange(uri: string, forChildUris: boolean, callback: Callback\<ChangeData>): void

**Adaptation Guide**

The API usage does not change, and no additional adaptation is required during API calls. However, since the API behavior changes, you should pay attention to the changes and make appropriate adjustments.

1. When **addAssets** is used to add a photo, the copy instead of the original photo is added to the album. Any subsequent operations on the asset should be performed on the copied asset within the album.

2. When using **removeAssets**, note that the asset is moved to the recycle bin.

3. When using **deleteAlbums**, note that all assets within the album are moved to the recycle bin.

4. When renaming an album with **setAlbumName** and **commitModify**, the original album is deleted and a new one is created. To continue working with the album, you should perform operations on the new album. After renaming, call [getAlbums](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2) to obtain the new album name for subsequent operations.

5. When using **registerChange**, note that you will receive notifications for the addition of copied assets when **addAssets** is called, deletion notifications for assets within the album when **removeAssets** and **deleteAlbums** are called, and update notifications for the album when **setAlbumName** and **commitModify** are called.

# Managing User Albums

The **photoAccessHelper** module provides APIs for user album management, including creating or deleting a user album, adding images and videos to a user album, and deleting images and videos from a user album.

> **NOTE**
>
> - Before you get started, obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [Before You Start](photoAccessHelper-preparation.md).
> - Unless otherwise specified, the **PhotoAccessHelper** instance obtained in the **Before You Start** section is used to call **photoAccessHelper** APIs. If the code for obtaining the **PhotoAccessHelper** instance is missing, an error will be reported to indicate that **photoAccessHelper** is not defined.

To ensure application running efficiency, most **PhotoAccessHelper** APIs are asynchronously implemented in callback or promise mode. The following examples use promise-based APIs. For details about the APIs, see [Album Management](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md).
Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

<!--Del-->
## Creating a User Album (for System Applications Only)

Use [MediaAlbumChangeRequest.createAlbumRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#createalbumrequest11) and [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to create a user album.

The album name must meet the following requirements:

- The album name cannot exceed 255 characters.
- The album name cannot contain any of the following characters:<br>. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.WRITE_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Create a user album.

**How to Develop**

1. Set the name of the album.
2. Call **MediaAlbumChangeRequest.createAlbumRequest** to create an album change request object.
3. Call **PhotoAccessHelper.applyChanges** to apply the changes.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let albumName = 'albumName';
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = photoAccessHelper.MediaAlbumChangeRequest.createAlbumRequest(context, albumName);
    await phAccessHelper.applyChanges(albumChangeRequest);
    let album: photoAccessHelper.Album = albumChangeRequest.getAlbum();
    console.info('create album successfully, album name: ' + album.albumName + ' uri: ' + album.albumUri);
  } catch (err) {
    console.error('create album failed with err: ' + err);
  }
}
```
<!--DelEnd-->

## Obtaining a User Album

Use [PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2) to obtain user albums.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Obtain the user album **albumName**.

**How to Develop**

1. Set **fetchOptions** for obtaining the user album.
2. Call **PhotoAccessHelper.getAlbums** to obtain user albums.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first user album.

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
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    fetchResult.close();
  } catch (err) {
    console.error('getAlbums failed with err: ' + err);
  }
}
```

## Renaming a User Album

To rename a user album, modify the **Album.albumName** attribute of the album.

Use the [FetchResult](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#fetchresult) APIs to obtain the user album to rename, use [MediaAlbumChangeRequest.setAlbumName](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#setalbumname11) to rename the user album, and use [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to apply the changes to the database.

The new user album names must comply with the following requirements:

- The album name cannot exceed 255 characters.
- The album name cannot contain any of the following characters:<br>. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Rename the user album **albumName**.

**How to Develop**

1. Set **fetchOptions** for obtaining the user album.
2. Call **PhotoAccessHelper.getAlbums** to obtain user albums.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first user album.
4. Call **MediaAlbumChangeRequest.setAlbumName** to set a new album name.
5. Call **PhotoAccessHelper.applyChanges** to save the new album name to the database.

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
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    let newAlbumName: string = 'newAlbumName';
    albumChangeRequest.setAlbumName(newAlbumName);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('setAlbumName successfully, new albumName: ' + album.albumName);
    fetchResult.close();
  } catch (err) {
    console.error('setAlbumName failed with err: ' + err);
  }
}
```

## Adding Images or Videos to a User Album

[Obtain the user album](#obtaining-a-user-album) and the images or videos to be added to the album, and then call [MediaAlbumChangeRequest.addAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addassets11) and [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to add the images or videos to the user album.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Add an image to the user album **albumName**.

**How to Develop**

1. Set **albumFetchOptions** for obtaining the user album.
2. Set **photoFetchOptions** for obtaining the image.
3. Call **PhotoAccessHelper.getAlbums** to obtain user albums.
4. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first user album.
5. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets) to obtain image assets.
6. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first image from the result set.
7. Call **MediaAlbumChangeRequest.addAssets** to add the image to the user album.
8. Call **PhotoAccessHelper.applyChanges** to apply the changes.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let albumPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  albumPredicates.equalTo(albumName, 'albumName');
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: albumPredicates
  };

  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(photoFetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('getAssets successfully, albumName: ' + photoAsset.displayName);
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.addAssets([photoAsset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('succeed to add ' + photoAsset.displayName + ' to ' + album.albumName);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('addAssets failed with err: ' + err);
  }
}
```

## Obtaining Images and Videos in a User Album

[Obtain the user album](#obtaining-a-user-album), and call [Album.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-3) to obtain the assets in the user album.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Obtain an image in the user album **albumName**.

**How to Develop**

1. Set **albumFetchOptions** for obtaining the user album.
2. Set **photoFetchOptions** for obtaining the image.
3. Call **PhotoAccessHelper.getAlbums** to obtain user albums.
4. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first user album.
5. Call **Album.getAssets** to obtain the media assets in the user album.
6. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the result set.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let albumPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  albumPredicates.equalTo(albumName, 'albumName');
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: albumPredicates
  };

  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    let photoFetchResult = await album.getAssets(photoFetchOptions);
    let photoAsset = await photoFetchResult.getFirstObject();
    console.info('album getAssets successfully, albumName: ' + photoAsset.displayName);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('album getAssets failed with err: ' + err);
  }
}
```

## Removing Images and Videos from a User Album

[Obtain the user album](#obtaining-a-user-album), and call [Album.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-3) to obtain the assets in the user album.

Select the assets to remove, and use [MediaAlbumChangeRequest.removeAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#removeassets11) and [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to remove the selected media assets.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Remove an image from the user album **albumName**.

**How to Develop**

1. Set **albumFetchOptions** for obtaining the user album.
2. Set **photoFetchOptions** for obtaining the image.
3. Call **PhotoAccessHelper.getAlbums** to obtain user albums.
4. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first user album.
5. Call **Album.getAssets** to obtain the media assets.
6. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the result set.
7. Call **MediaAlbumChangeRequest.removeAssets** to remove the image from the user album.
8. Call **PhotoAccessHelper.applyChanges** to apply the changes.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let albumPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  albumPredicates.equalTo(albumName, 'albumName');
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: albumPredicates
  };

  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    let photoFetchResult = await album.getAssets(photoFetchOptions);
    let photoAsset = await photoFetchResult.getFirstObject();
    console.info('album getAssets successfully, albumName: ' + photoAsset.displayName);
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.removeAssets([photoAsset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('succeed to remove ' + photoAsset.displayName + ' from ' + album.albumName);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('removeAssets failed with err: ' + err);
  }
}
```

<!--Del-->
## Deleting a User Album (for System Applications Only)

[Obtain the user album](#obtaining-a-user-album), and call [MediaAlbumChangeRequest.deleteAlbums](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#deletealbums11) to delete the user album.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Delete the user album **albumName**.

**How to Develop**

1. Set **fetchOptions** for obtaining the user album.
2. Call **PhotoAccessHelper.getAlbums** to obtain user albums.
3. Call **FetchResult.getFirstObject** to obtain the first user album.
4. Call **MediaAlbumChangeRequest.deleteAlbums** to delete the user album.

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
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    await photoAccessHelper.MediaAlbumChangeRequest.deleteAlbums(context, [album]);
    fetchResult.close();
  } catch (err) {
    console.error('deleteAlbums failed with err: ' + err);
  }
}
```
<!--DelEnd-->

# Managing System Albums

The **photoAccessHelper** module provides APIs for managing system albums, including **Favorites**, **Videos**, and **Screenshots**.

> **NOTE**
>
> - Before you get started, obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [Before You Start](photoAccessHelper-preparation.md).
> - Unless otherwise specified, the **PhotoAccessHelper** instance obtained in the **Before You Start** section is used to call **photoAccessHelper** APIs. If the code for obtaining the **PhotoAccessHelper** instance is missing, an error will be reported to indicate that **photoAccessHelper** is not defined.

To ensure application running efficiency, most **PhotoAccessHelper** APIs are asynchronously implemented in callback or promise mode. The following examples use promise-based APIs. For details about the APIs, see [Album Management](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md).

Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

## Favorites

**Favorites** is a system album. Favoriting an image or video adds the image or video to **Favorites**; unfavoriting an image or video removes the image or video from **Favorites**.

### Obtaining a Favorites Object

Use [PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2) to obtain a **Favorites** object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.FAVORITE**.
2. Call **PhotoAccessHelper.getAlbums** to obtain a **Favorites** object.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('get favorite album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get favorite album failed with err: ' + err);
  }
}
```

<!--Del-->
### Favoriting an Image or Video (for System Applications Only)

Use [MediaAssetChangeRequest.setFavorite](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#setfavorite11) and [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to add an image or video to **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Favorite an image.

**How to Develop**

1. [Obtain the image](photoAccessHelper-resource-guidelines.md#obtaining-media-assets).
2. Call **MediaAssetChangeRequest.setFavorite** to set **favoriteState** to **true**.
3. Call **PhotoAccessHelper.applyChanges** to apply the changes.

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
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    let favoriteState = true;
    assetChangeRequest.setFavorite(favoriteState);
    await phAccessHelper.applyChanges(assetChangeRequest);
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```
<!--DelEnd-->

### Obtaining Images and Videos in Favorites

[Obtain a **Favorites** object](#obtaining-a-favorites-object), and call [Album.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-3) to obtain the assets in **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Obtain an image from **Favorites**.

**How to Develop**

1. [Obtain a **Favorites** object](#obtaining-a-favorites-object).
2. Set **fetchOptions** for obtaining the image.
3. Call **Album.getAssets** to obtain the image assets.
4. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the result set.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get favorite album successfully, albumUri: ' + album.albumUri);

    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('favorite failed with err: ' + err);
  }
}
```

<!--Del-->
### Unfavoriting an Image or Video (for System Applications Only)

Use [MediaAssetChangeRequest.setFavorite](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#setfavorite11) and [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to remove an image or video from **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Unfavorite an image.

**How to Develop**

1. [Obtain the image in **Favorites**](#obtaining-images-and-videos-in-favorites).
2. Call **MediaAssetChangeRequest.setFavorite** to set **favoriteState** to **false**.
3. Call **PhotoAccessHelper.applyChanges** to apply the changes.


```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get favorite album successfully, albumUri: ' + album.albumUri);

    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);

    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    let favoriteState = false;
    assetChangeRequest.setFavorite(favoriteState);
    await phAccessHelper.applyChanges(assetChangeRequest);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```
<!--DelEnd-->

## Videos

**Videos** is a system album that holds media assets of the video type in user files.

### Obtaining a Videos Object

Use [PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2) to obtain a **Videos** object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.VIDEO**.
2. Use **PhotoAccessHelper.getAlbums** to obtain a **Videos** object.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('get video album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get video album failed with err: ' + err);
  }
}
```

### Obtaining a Video from Videos

[Obtain a **Videos** object](#obtaining-a-videos-object), and call [Album.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-3) to obtain video assets in the **Videos** album.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Obtain a video in **Videos**.

**How to Develop**

1. [Obtain a **Videos** object](#obtaining-a-videos-object).
2. Set **fetchOptions** for obtaining the video.
3. Call **Album.getAssets** to obtain video assets.
4. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first video.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get video album successfully, albumUri: ' + album.albumUri);

    let videoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await videoFetchResult.getFirstObject();
    console.info('video album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);
    videoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('video failed with err: ' + err);
  }
}
```

<!--Del-->
## Screenshots (for System Applications Only)

**Screenshots** is a system album that holds user's screenshots and screen recording files.

### Obtaining a Screenshots Object

Use [PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2) to obtain a **Screenshots** object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.SCREENSHOT**.
2. call **PhotoAccessHelper.getAlbums** to obtain a **Screenshots** object.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.SCREENSHOT);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('get screenshot album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get screenshot album failed with err: ' + err);
  }
}
```

### Obtaining Media Assets in Screenshots

[Obtain a **Screenshots** object](#obtaining-a-screenshots-object), and call [Album.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-3) to obtain the media assets in **Screenshots**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Obtain a media asset from **Screenshots**.

**How to Develop**

1. [Obtain a **Screenshots** object](#obtaining-a-screenshots-object).
2. Set **fetchOptions** for obtaining the media asset.
3. Call **Album.getAssets** to obtain media assets.
4. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first media asset.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.SCREENSHOT);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get screenshot album successfully, albumUri: ' + album.albumUri);

    let screenshotFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await screenshotFetchResult.getFirstObject();
    console.info('screenshot album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);
    screenshotFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('screenshot album failed with err: ' + err);
  }
}
```
<!--DelEnd-->

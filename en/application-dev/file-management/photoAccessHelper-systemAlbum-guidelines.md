# Managing System Albums

The **photoAccessHelper** module provides APIs for managing system albums, including **Favorites**, **Videos**, and **Screenshots**.

> **NOTE**
>
> - Before you start, you need to obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [photoAccessHelper Overview](photoAccessHelper-overview.md).
> - Unless otherwise specified, the **PhotoAccessHelper** instance obtained in [photoAccessHelper Overview](photoAccessHelper-overview.md) is used to call **photoAccessHelper** APIs. If the code for obtaining the **PhotoAccessHelper** instance is missing, an error will be reported to indicate that **photoAccessHelper** is not defined.

To ensure application running efficiency, most **photoAccessHelper** APIs are asynchronously implemented in callback or promise mode. The following code samples use promise-based APIs. For details about the APIs, see [Album Management](../reference/apis/js-apis-photoAccessHelper.md).

Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

## Favorites

**Favorites** is a system album. Favoriting an image or video adds the image or video to **Favorites**; unfavoriting an image or video removes the image or video from **Favorites**.

### Obtaining a Favorites Object

Call [PhotoAccessHelper.getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums-2) to obtain a **Favorites** object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

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
    console.info('get favorite Album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get favorite Album failed with err: ' + err);
  }
}
```

### Favoriting an Image or Video

Use [PhotoAsset.setFavorite](../reference/apis/js-apis-photoAccessHelper.md#setfavorite-1) to add an image or video to **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Favorite an image.

**How to Develop**

1. [Obtain the image](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
2. Set **favoriteState** to **true** to favorite the image.
3. Call **PhotoAsset.setFavorite** to set favorites.

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
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    let favoriteState = true;
    await photoAsset.setFavorite(favoriteState);
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```

### Obtaining Images and Videos in Favorites

[Obtain a **Favorites** object](#obtaining-a-favorites-object), and call [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-3) to obtain the assets in **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain an image from **Favorites**.

**How to Develop**

1. [Obtain a **Favorites** object](#obtaining-a-favorites-object).
2. Set **fetchOptions** for obtaining the image.
3. Call **Album.getAssets** to obtain the image assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the result set.

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
    console.info('get favorite Album successfully, albumUri: ' + album.albumUri);

    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, albumName: ' + photoAsset.displayName);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('favorite failed with err: ' + err);
  }
}
```

### Unfavoriting an Image or Video

Use [PhotoAsset.setFavorite](../reference/apis/js-apis-photoAccessHelper.md#setfavorite-1) to remove an image or video from **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Unfavorite an image.

**How to Develop**

1. [Obtain the image in **Favorites**](#obtaining-images-and-videos-in-favorites).
2. Set **favoriteState** to **false**.
3. Call **PhotoAsset.setFavorite** to set favorites.


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
    console.info('get favorite Album successfully, albumUri: ' + album.albumUri);

    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, albumName: ' + photoAsset.displayName);
    let favoriteState = false;
    await photoAsset.setFavorite(favoriteState);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```

## Videos

**Videos** is a system album that holds media assets of the video type in user files.

### Obtaining a Videos Object

Call [PhotoAccessHelper.getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums-2) to obtain a **Videos** object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

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
    console.info('get video Album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get video Album failed with err: ' + err);
  }
}
```

### Obtaining a Video from Videos

[Obtain a **Videos** object](#obtaining-a-videos-object), and call [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-3) to obtain video assets in **Videos**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain a video in **Videos**.

**How to Develop**

1. [Obtain a videos object](#obtaining-a-videos-object).
2. Set **fetchOptions** for obtaining the video.
3. Call **Album.getAssets** to obtain video assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first video.

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
    console.info('get video Album successfully, albumUri: ' + album.albumUri);

    let videoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await videoFetchResult.getFirstObject();
    console.info('video album getAssets successfully, albumName: ' + photoAsset.displayName);
    videoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('video failed with err: ' + err);
  }
}
```

## Screenshots

**Screenshots** is a system album that holds user's screenshots and screen recording files.

### Obtaining a Screenshots Object

Use [getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums-2) to obtain a **Screenshots** object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.SCREENSHOT**.
2. Use **PhotoAccessHelper.getAlbums** to obtain a **Screenshots** object.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.SCREENSHOT);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('get screenshot Album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get screenshot Album failed with err: ' + err);
  }
}
```

### Obtaining Media Assets in Screenshots

[Obtain a **Screenshots** object](#obtaining-a-screenshots-object), and call [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-3) to obtain the media assets in **Screenshots**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain a media asset from **Screenshots**.

**How to Develop**

1. [Obtain a **Screenshots** object](#obtaining-a-screenshots-object).
2. Set **fetchOptions** for obtaining the media asset.
3. Call **Album.getAssets** to obtain media assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first media asset.

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
    console.info('screenshot album getAssets successfully, albumName: ' + photoAsset.displayName);
    screenshotFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('screenshot album failed with err: ' + err);
  }
}
```

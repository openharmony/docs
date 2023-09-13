# Managing System Albums

The **photoAccessHelper** module provides APIs for managing system albums, including the **Favorites**, **Videos**, **Screenshots**.

> **NOTE**
>
> Before you start, you need to obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [photoAccessHelper Overview](photoAccessHelper-overview.md).
>
> By default, the **PhotoAccessHelper** instance obtained in [photoAccessHelper Overview](photoAccessHelper-overview.md) is used when **photoAccessHelper** APIs are used. If the code for obtaining the **PhotoAccessHelper** instance is not added, an error indicating that **PhotoAccessHelper** is not defined is reported.

To ensure application running efficiency, most **photoAccessHelper** APIs are asynchronously implemented in callback or promise mode. The following code samples use promise-based APIs. For details about the APIs, see [Album Management](../reference/apis/js-apis-photoAccessHelper.md).
Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

## Favorites

**Favorites** is a system album. Favoriting a photo or video adds the photo or video to **Favorites**; unfavoriting a photo or video removes the photo or video from **Favorites**.

### Obtaining a Favorites Object

Use [getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums) to obtain a **Favorites** object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.FAVORITE**.
2. Call **getAlbums** to obtain a **Favorites** object.

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

Use [setFavorite](../reference/apis/js-apis-photoAccessHelper.md#setfavorite) to add an image or video to **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Favorite an image.

**How to Develop**

1. [Obtain media assets](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
2. Set **favoriteState** to **true** to favorite the image.
3. Call **FileAsset.setFavorite** to add the image to **Favorites**.

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
    let fileAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
    let favoriteState = true;
    await fileAsset.setFavorite(favoriteState);
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```

### Obtaining Images and Videos in Favorites

[Obtain a **Favorites** object](#obtaining-a-favorites-object), and call [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-2) to obtain the assets in **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain an image from **Favorites**.

**How to Develop**

1. [Obtain a **Favorites** object](#obtaining-a-favorites-object).
2. Set **fetchOptions** for obtaining the image.
3. Call **Album.getAssets** to obtain the image assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first image from the result set.

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
    let fileAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, albumName: ' + fileAsset.displayName);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('favorite failed with err: ' + err);
  }
}
```

### Unfavoriting an Image or Video

Use [setFavorite](../reference/apis/js-apis-photoAccessHelper.md#setfavorite) to remove images or videos from **Favorites**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Unfavorite an image.

**How to Develop**

1. [Obtain the images and videos in **Favorites**](#obtaining-images-and-videos-in-favorites).
2. Set **favoriteState** to **false**.
3. Call **FileAsset.setFavorite** to unfavorite an image or video.


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
    let fileAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, albumName: ' + fileAsset.displayName);
    let favoriteState = false;
    await fileAsset.setFavorite(favoriteState);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```

## Videos

**Videos** is a system album that holds media assets of the video type in user files.

### Obtaining a Video Album Object

Use [getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums) to obtain a video album object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.VIDEO**.
2. Use **getAlbums** to obtain the video album object.

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

[Obtain a video album object](#obtaining-a-video-album-object), and use [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-2) to obtain video assets in **Videos**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain a video in **Videos**.

**How to Develop**

1. [Obtain a video album object](#obtaining-a-video-album-object).
2. Set **fetchOptions** for obtaining the video.
3. Call **Album.getAssets** to obtain video assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first video.

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
    let fileAsset: photoAccessHelper.PhotoAsset = await videoFetchResult.getFirstObject();
    console.info('video album getAssets successfully, albumName: ' + fileAsset.displayName);
    videoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('video failed with err: ' + err);
  }
}
```

## Screenshots

**Screenshots** is a system album that holds user's screenshots and screen recording files.

### Obtaining a Screenshot Album Object

Use [getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums) to obtain a screenshot album object.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.SCREENSHOT**.
2. Use **getAlbums** to obtain a screenshot album object.

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

[Obtain a screenshot album object](#obtaining-a-screenshot-album-object), and call [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-2) to obtain the media assets in the album.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain a media asset from **Screenshots**.

**How to Develop**

1. [Obtain a screenshot album object](#obtaining-a-screenshot-album-object).
2. Set **fetchOptions** for obtaining the media asset.
3. Call **Album.getAssets** to obtain media assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first media asset.

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
    let fileAsset: photoAccessHelper.PhotoAsset = await screenshotFetchResult.getFirstObject();
    console.info('screenshot album getAssets successfully, albumName: ' + fileAsset.displayName);
    screenshotFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('screenshot album failed with err: ' + err);
  }
}
```

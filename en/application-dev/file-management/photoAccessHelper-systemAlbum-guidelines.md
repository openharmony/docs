# System Album Management

The **photoAccessHelper** module provides APIs for managing system albums, including the **Favorites**, video album, and screenshot album.

> **NOTE**
>
> Before you start, refer to [photoAccessHelper Overview](photoAccessHelper-overview.md) to learn how to obtain a **photoAccessHelper** instance and apply for permissions required.
> By default, the **PhotoAccessHelper** instance obtained in [photoAccessHelper Overview](photoAccessHelper-overview.md) is used when **PhotoAccessHelper** APIs are used. If the code for obtaining the **PhotoAccessHelper** instance is not added, an error indicating that **PhotoAccessHelper** is not defined is reported.

To ensure application running efficiency, most **photoAccessHelper** calls are asynchronous in callback or promise mode. The following code samples use promise-based APIs. For details about the APIs, see [Album Management](../reference/apis/js-apis-photoAccessHelper.md).
Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

## Favorites

The **Favorites** is a system album. When you favorite a photo or video, the photo or video is added to **Favorites**. When you favorite a photo or video, the photo or video is removed from **Favorites**.

### Obtaining a Favorites Object

Use [getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums) to obtain a **Favorites** object.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.FAVORITE**.
2. Call **getAlbums** to obtain a **Favorites** object.

```ts
try {
  let fetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
  let album = await fetchResult.getFirstObject();
  console.info('get favorite Album successfully, albumUri: ' + album.albumUri);
  fetchResult.close();
} catch (err) {
  console.error('get favorite Album failed with err: ' + err);
}
```

### Favoriting an Image or Video

Use [setFavorite](../reference/apis/js-apis-photoAccessHelper.md#setfavorite) to add images or videos to **Favorites**.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Favorite an image.

**How to Develop**

1. [Obtain media assets](photoAccessHelper-resource-guidelines.md#obtaining-the-specified-media-assets).
2. Set **favoriteState** to **true** to favorite the image.
3. Use **FileAsset.setFavorite** to add the image to **Favorites**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo(photoAccessHelper.ImageVideoKey.DISPLAY_NAME, 'test.jpg');
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let photoFetchResult = await phAccessHelper.getAssets(fetchOptions);
  let fileAsset = await photoFetchResult.getFirstObject();
  console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
  let favoriteState = true;
  await fileAsset.setFavorite(favoriteState);
} catch (err) {
  console.error('setFavorite failed with err: ' + err);
}
```

### Obtaining Images and Videos in Favorites

[Obtain a **Favorites** object](#obtaining-a-favorites-object), and call [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-2) to obtain the assets in **Favorites**.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain an image from **Favorites**.

**How to Develop**

1. [Obtain a **Favorites** object](#obtaining-a-favorites-object).
2. Set **fetchOptions** for obtaining the image.
3. Call **Album.getAssets** to obtain the image assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first image from the result set.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let albumFetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
  let album = await albumFetchResult.getFirstObject();
  console.info('get favorite Album successfully, albumUri: ' + album.albumUri);

  let photoFetchResult = await album.getAssets(fetchOptions);
  let fileAsset = await photoFetchResult.getFirstObject();
  console.info('favorite album getAssets successfully, albumName: ' + fileAsset.displayName);
  photoFetchResult.close();
  albumFetchResult.close();
} catch (err) {
  console.error('favorite failed with err: ' + err);
}
```

### Unfavoriting an Image or Video

Use [setFavorite](../reference/apis/js-apis-photoAccessHelper.md#setfavorite) to remove an image or video from **Favorites**.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** and **ohos.permission.WRITE_IMAGEVIDEO** permissions.

Example: Unfavorite an image.

**How to Develop**

1. [Obtain the image and videos in **Favorites**](#obtaining-images-and-videos-in-favorites).
2. Set **favoriteState** to **false**.
3. Use **FileAsset.setFavorite** to remove the image from **Favorites**.


```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let albumFetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
  let album = await albumFetchResult.getFirstObject();
  console.info('get favorite Album successfully, albumUri: ' + album.albumUri);

  let photoFetchResult = await album.getAssets(fetchOptions);
  let fileAsset = await photoFetchResult.getFirstObject();
  console.info('favorite album getAssets successfully, albumName: ' + fileAsset.displayName);
  let favoriteState = false;
  await fileAsset.setFavorite(favoriteState);
  photoFetchResult.close();
  albumFetchResult.close();
} catch (err) {
  console.error('setFavorite failed with err: ' + err);
}
```

## Video Album

The video album is a system album. The media assets of the video type in user files are automatically added to the video album.

### Obtaining a Video Album Object

Use [getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums) to obtain a video album object.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.VIDEO**.
2. Use **getAlbums** to obtain the video album object.

```ts
try {
  let fetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO);
  let album = await fetchResult.getFirstObject();
  console.info('get video Album successfully, albumUri: ' + album.albumUri);
  fetchResult.close();
} catch (err) {
  console.error('get video Album failed with err: ' + err);
}
```

### Obtaining Videos from the Video Album

[Obtain a video album object](#obtaining-a-video-album-object). Use [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-2) to obtain video assets in the video album.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain a video in the video album.

**How to Develop**

1. [Obtain a video album object](#obtaining-a-video-album-object).
2. Set **fetchOptions** for obtaining the video.
3. Call **Album.getAssets** to obtain video assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first video.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let albumFetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO);
  let album = await albumFetchResult.getFirstObject();
  console.info('get video Album successfully, albumUri: ' + album.albumUri);

  let videoFetchResult = await album.getAssets(fetchOptions);
  let fileAsset = await videoFetchResult.getFirstObject();
  console.info('video album getAssets successfully, albumName: ' + fileAsset.displayName);
  videoFetchResult.close();
  albumFetchResult.close();
} catch (err) {
  console.error('video failed with err: ' + err);
}
```

## Screenshot Album

The screenshot album is a system album. The user's screenshots and screen recording files are automatically added to this album.

### Obtaining a Screenshot Album Object

Use [getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums) to obtain a screenshot album.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

**How to Develop**

1. Set the album type to **photoAccessHelper.AlbumType.SYSTEM** and the album subtype to **photoAccessHelper.AlbumSubtype.SCREENSHOT**.
2. Use **getAlbums** to obtain a screenshot album object.

```ts
try {
  let fetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.SCREENSHOT);
  let album = await fetchResult.getFirstObject();
  console.info('get screenshot Album successfully, albumUri: ' + album.albumUri);
  fetchResult.close();
} catch (err) {
  console.error('get screenshot Album failed with err: ' + err);
}
```

### Obtaining Media Assets in the Screenshot Album

[Obtain a screenshot album object](#obtaining-a-screenshot-album-object), and call [Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-2) to obtain the media assets in the album.

**Prerequisites**

- A **photoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.

Example: Obtain a media asset from the screenshot album.

**How to Develop**

1. [Obtain a screenshot album object](#obtaining-a-screenshot-album-object).
2. Set **fetchOptions** for obtaining the media asset.
3. Call **Album.getAssets** to obtain media assets.
4. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first media asset.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let albumFetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.SCREENSHOT);
  let album = await albumFetchResult.getFirstObject();
  console.info('get screenshot album successfully, albumUri: ' + album.albumUri);

  let screenshotFetchResult = await album.getAssets(fetchOptions);
  let fileAsset = await screenshotFetchResult.getFirstObject();
  console.info('screenshot album getAssets successfully, albumName: ' + fileAsset.displayName);
  screenshotFetchResult.close();
  albumFetchResult.close();
} catch (err) {
  console.error('screenshot album failed with err: ' + err);
}
```

# Managing Media Assets

Applications can call **photoAccessHelper** APIs to manage media assets (images and videos).

> **NOTE**
>
> Before you start, you need to obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [photoAccessHelper Overview](photoAccessHelper-overview.md).
>
> By default, the **PhotoAccessHelper** instance obtained in [photoAccessHelper Overview](photoAccessHelper-overview.md) is used when **photoAccessHelper** APIs are used. If the code for obtaining the **PhotoAccessHelper** instance is not added, an error indicating that **photoAccessHelper** is not defined is reported.

To ensure application running efficiency, most **photoAccessHelper** APIs are asynchronously implemented in callback or promise mode. The following code samples use promise-based APIs. For details about the APIs, see [Album Management](../reference/apis/js-apis-photoAccessHelper.md).

## Obtaining the Specified Media Assets

You can obtain media assets by media type, date, or album name.

Use [PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets) with the [FetchOptions](../reference/apis/js-apis-photoAccessHelper.md#fetchoptions) object to specify search criteria. Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

To obtain the object at the specified position (for example, the first, the last, or object with the specified index) in the result set, use [FetchFileResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult).

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.
- The [dataSharePredicates](../reference/apis/js-apis-data-dataSharePredicates.md) module is imported.

### Obtaining an Image or Video by Name

Example: Obtain the image **test.jpg**.

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
    console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

### Obtaining an Image or Video by URI

Example: Obtain the image with the file URI **file://media/Photo/1**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.URI, 'file://media/Photo/1');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.uri : ' + fileAsset.uri);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

### Obtaining Images or Videos by Time

Example: Obtain the media assets added between 2022-06-01 and 2023-06-01.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let startTime = Date.parse(new Date('2022-06-01').toString()) / 1000; // The value of the start time is the number of seconds elapsed since the Epoch time.
  let endTime = Date.parse(new Date('2023-06-01').toString()) / 1000;   // The value of the end time is the number of seconds elapsed since the Epoch time.
  let date_added: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.DATE_ADDED;
  predicates.between(date_added, startTime, endTime);
  predicates.orderByDesc(date_added);                                   // Sort the obtained records in descending order.
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [date_added],                                         // The date_added attribute is not a default option and needs to be added.
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    console.info('getAssets count: ' + fetchResult.getCount());
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

## Obtaining an Image or Video Thumbnail

Use [FileAsset.getThumbnail](../reference/apis/js-apis-photoAccessHelper.md#getthumbnail) with the thumbnail size passed in to obtain the image or video thumbnail. The thumbnails offer a quick preview on images and videos.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.
- The [dataSharePredicates](../reference/apis/js-apis-data-dataSharePredicates.md) module is imported.

### Obtaining the Thumbnail of an Image

Your application may need to obtain the thumbnail of an image or video for preview purposes.

Example: Obtain the thumbnail of 720 x 720 of an image.

**How to Develop**

1. Set the fetch options.
2. Call **PhotoAccessHelper.getAssets** to obtain image assets.
3. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first image from the result set.
4. Call **getThumbnail** to obtain the [PixelMap](../reference/apis/js-apis-image.md#pixelmap7) of the thumbnail of the image.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import image from '@ohos.multimedia.image';
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
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.displayName : ' + fileAsset.displayName);
    let size: image.Size = { width: 720, height: 720 };
    let pixelMap: image.PixelMap =  await fileAsset.getThumbnail(size);
    let imageInfo: image.ImageInfo = await pixelMap.getImageInfo()
    console.info('getThumbnail successful, pixelMap ImageInfo size: ' + JSON.stringify(imageInfo.size));
    fetchResult.close();
  } catch (err) {
    console.error('getThumbnail failed with err: ' + err);
  }
}
```

## Creating a Media Asset

Use [createAsset](../reference/apis/js-apis-photoAccessHelper.md#createasset) to create a media asset.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.WRITE_IMAGEVIDEO** permission.

### Creating an Image or Video

Example: Create an image asset.

**How to Develop**

1. Set the file name and create **createOption** for setting attributes for the image asset to create.
2. Call **createAsset** to create an image asset.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let displayName: string = 'testPhoto' + Date.now() + '.jpg';
    let createOption: photoAccessHelper.PhotoCreateOptions = {
      subtype: photoAccessHelper.PhotoSubtype.DEFAULT
    };

    let fileAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(displayName, createOption);
    console.info('createAsset successfully, file displayName: ' + fileAsset.displayName);
  } catch (err) {
    console.error('createAsset failed, message = ', err);
  }
}
```

## Renaming a Media Asset

Set the **FileAsset.displayName** attribute to modify the file name (including the file name extension) displayed.

After the modification, use [FileAsset.commitModify](../reference/apis/js-apis-photoAccessHelper.md#commitmodify) to update the modification to the database.

Before renaming a file, use [FetchResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult) to obtain the file.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.WRITE_IMAGEVIDEO** and **ohos.permission.READ_IMAGEVIDEO** permissions.

Example: Rename the first file in the obtained image assets.

**How to Develop**

1. Set the fetch options.
2. Call **getAssets** to obtain image assets.
3. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first image from the obtained file assets.
4. Call **FileAsset.set** to rename the image.
5. Call **FileAsset.commitModify** to update the modified image attributes to the database.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let newTitle = 'newTestPhoto';

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;
    let fileAssetTitle: photoAccessHelper.MemberType = fileAsset.get(title);
    console.info('getAssets fileAsset.title : ' + fileAssetTitle);
    fileAsset.set(title, newTitle);
    await fileAsset.commitModify();
    fetchResult.close();
  } catch (err) {
    console.error('commitModify failed with err: ' + err);
  }
}
```

## Moving Media Assets to the Trash

You can use [deleteAssets](../reference/apis/js-apis-photoAccessHelper.md#deleteassets) to move files to the trash.

The files moved to the trash will be retained for 30 days, and deleted permanently after 30 days. Before a file is deleted permanently from the trash, the user can restore it using the system application **FileManager** or **Gallery**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.WRITE_IMAGEVIDEO** and **ohos.permission.READ_IMAGEVIDEO** permissions.

Example: Move the first file in the result set to the trash.

**How to Develop**

1. Set the fetch options.
2. Call **PhotoAccessHelper.getAssets** to obtain image assets.
3. Call [**FetchResult.getFirstObject**](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject) to obtain the first image, that is, the image object to be moved to the trash.
4. Call **deleteAssets** to move the file to the trash.

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
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let fileAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets fileAsset.uri : ' + fileAsset.uri);
    await phAccessHelper.deleteAssets([fileAsset.uri]);
    fetchResult.close();
  } catch (err) {
    console.error('deleteAssets failed with err: ' + err);
  }
}
```

# Managing Media Assets

Applications can call **photoAccessHelper** APIs to manage media assets (images and videos).

> **NOTE**
>
> - Before you get started, obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [Before You Start](photoAccessHelper-preparation.md).
> - Unless otherwise specified, the **PhotoAccessHelper** instance obtained in the **Before You Start** section is used to call **photoAccessHelper** APIs. If the code for obtaining the **PhotoAccessHelper** instance is missing, an error will be reported to indicate that **photoAccessHelper** is not defined.

To ensure application running efficiency, most **PhotoAccessHelper** APIs are asynchronously implemented in callback or promise mode. The following examples use promise-based APIs. For details about the APIs, see [Album Management](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md).

## Obtaining Media Assets

You can obtain media assets based on the specified conditions, such as the media type, date, or album name.

Use [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-1) with the [FetchOptions](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#fetchoptions) object to specify the search criteria. Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

To obtain the object at the specified position (for example, the first one, the last one, or the one with the specified index) in the result set, use [FetchResult](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#fetchresult).

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission.
- The [dataSharePredicates](../../reference/apis-arkdata/js-apis-data-dataSharePredicates.md) module is imported.

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

### Obtaining an Image or Video by URI

Example: Obtain the image that matches the URI **file://media/Photo/1/IMG_datetime_0001/displayName.jpg**.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let uri = 'file://media/Photo/1/IMG_datetime_0001/displayName.jpg' // The URI must exist.
  predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uri.toString());
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
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
  let endTime = Date.parse(new Date('2023-06-01').toString()) / 1000;  // The value of the end time is the number of seconds elapsed since the Epoch time.
  let date_added: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.DATE_ADDED;
  predicates.between(date_added, startTime, endTime);
  predicates.orderByDesc(date_added); // Sort the obtained records in descending order.
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [date_added], // The date_added attribute is not a default option and needs to be added.
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    console.info('getAssets count: ' + fetchResult.getCount());
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

## Obtaining an Image or Video Thumbnail

The thumbnails offer a quick preview on images and videos. You can use [PhotoAsset.getThumbnail](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getthumbnail-2)  with the thumbnail size specified to obtain the image or video thumbnail.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission.
- The [dataSharePredicates](../../reference/apis-arkdata/js-apis-data-dataSharePredicates.md) module is imported.

### Obtaining the Thumbnail of an Image

Your application may need to obtain the thumbnail of an image or video for preview purposes.

For example, obtain the file descriptor (FD) of an image, and decode the image into a pixel map for display or processing. For details, see [Image Decoding](../image/image-decoding.md).

Example: Obtain the thumbnail at the size of 720 x 720 of an image.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the result set.
4. Call **PhotoAsset.getThumbnail** to obtain the [PixelMap](../../reference/apis-image-kit/js-apis-image.md#pixelmap7) of the thumbnail of the image.

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    let size: image.Size = { width: 720, height: 720 };
    let pixelMap: image.PixelMap =  await photoAsset.getThumbnail(size);
    let imageInfo: image.ImageInfo = await pixelMap.getImageInfo()
    console.info('getThumbnail successful, pixelMap ImageInfo size: ' + JSON.stringify(imageInfo.size));
    fetchResult.close();
  } catch (err) {
    console.error('getThumbnail failed with err: ' + err);
  }
}
```

## Creating a Media Asset

Use [MediaAssetChangeRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#mediaassetchangerequest11) to create a media asset change request object for a media asset, and use [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to apply the changes.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.WRITE_IMAGEVIDEO permission.

### Creating an Image or Video Asset (for System Applications Only)

Example: Create an image asset.

**How to Develop**

1. Set the file name and create **createOption** for setting attributes for the image asset to create.
2. Call **MediaAssetChangeRequest.createAssetRequest** to create a media asset change request object.
3. Call **MediaAssetChangeRequest.getWriteCacheHandler** to obtain the handle of the file to write and write the content of the image asset.
4. Call **PhotoAccessHelper.applyChanges** to apply the changes to the image.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
import fs from '@ohos.file.fs';
let context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let displayName: string = 'testPhoto' + Date.now() + '.jpg';
    let createOption: photoAccessHelper.PhotoCreateOptions = {
      subtype: photoAccessHelper.PhotoSubtype.DEFAULT
    };
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, displayName, createOption);
    let fd: number = await assetChangeRequest.getWriteCacheHandler();
    // write date into fd
    await fs.close(fd);
    await phAccessHelper.applyChanges(assetChangeRequest);
  } catch (err) {
    console.error(`create asset failed with error: ${err.code}, ${err.message}`);
  }
}
```

You can also use **MediaAssetChangeRequest.addResource** to specify the data source information of the media asset, including the [application sandbox](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addresource11), [ArrayBuffer](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addresource11-1), and [PhotoProxy](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#addresource11).

## Creating a Media Asset Using a Security Component

Example: Create an image asset using a security component. When using a security component to create a media asset, you do not need to apply for the ohos.permission.WRITE_IMAGEVIDEO permission for your application. For details, see [\<SaveButton>](../../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md).

**How to Develop**

1. Set the attributes of the security component.
2. Create a security component.
3. Use [MediaAssetChangeRequest.createImageAssetRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#createimageassetrequest11) and [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to create an image asset.

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  @State saveButtonOptions: SaveButtonOptions = {
    icon: SaveIconStyle.FULL_FILLED,
    text: SaveDescription.SAVE_IMAGE,
    buttonType: ButtonType.Capsule
  } // Set the attributes of the security component.

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        SaveButton(this.saveButtonOptions) // Create a security component.
          .onClick(async (event, result: SaveButtonOnClickResult) => {
             if (result == SaveButtonOnClickResult.SUCCESS) {
               try {
                 let context = getContext();
                 let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
                 // Ensure that the asset specified by fileUri exists.
                 let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
                 let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createImageAssetRequest(context, fileUri);
                 await phAccessHelper.applyChanges(assetChangeRequest);
                 console.info('createAsset successfully, uri: ' + assetChangeRequest.getAsset().uri);
               } catch (err) {
                 console.error(`create asset failed with error: ${err.code}, ${err.message}`);
               }
             } else {
               console.error('SaveButtonOnClickResult create asset failed');
             }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Renaming a Media Asset

To rename a media asset, change the **PhotoAsset.displayName** attribute, that is, the file name (including the file name extension) displayed.

Obtain the media asset using [FetchResult](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#fetchresult) APIs, use [MediaAssetChangeRequest.setTitle](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#settitle11) to rename the file, and use use [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to apply the changes to the database.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.WRITE_IMAGEVIDEO and ohos.permission.READ_IMAGEVIDEO permissions.

Example: Rename the first image in the obtained image assets.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the obtained file assets.
4. Call [MediaAssetChangeRequest.setTitle](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#settitle11) to rename the image.
5. Call [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to save the modification to the database.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
let context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let newTitle: string = 'newTestPhoto';

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    assetChangeRequest.setTitle(newTitle);
    await phAccessHelper.applyChanges(assetChangeRequest);
    fetchResult.close();
  } catch (err) {
    console.error(`rename failed with error: ${err.code}, ${err.message}`);
  }
}
```

## Moving a Media Asset to the Trash

You can use [MediaAssetChangeRequest.deleteAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#deleteassets11) to move files to the trash.

The file moved to the trash will be retained for 30 days before being deleted permanently. Before a file is deleted permanently from the trash, the user can restore it using the system application **FileManager** or **Gallery**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the ohos.permission.WRITE_IMAGEVIDEO and ohos.permission.READ_IMAGEVIDEO permissions.

Example: Move the first image in the result set to the trash.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image.
4. Call [MediaAssetChangeRequest.deleteAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#deleteassets11) to move the image to the trash.

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
let context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    fetchResult.close();
  } catch (err) {
    console.error(`deleteAssets failed with error: ${err.code}, ${err.message}`);
  }
}
```

## Using Picker to Select Media Assets

When a user needs to share files such as images and videos, use a specific API to start **Gallery** for the user to select the files to share. No permission is required for this API. Currently, UIAbility is used to start **Gallery** by the window component. The procedure is as follows:

1. Import the **picker** and **fs** modules.

   ```ts
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import fs from '@ohos.file.fs';
   import { BusinessError } from '@ohos.base';
   ```

2. Create a **PhotoSelectOptions** instance.

   ```ts
   const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   ```

3. Set the file type and the maximum number of media files to select.
   The following uses images as an example. For details about the media file types, see [PhotoViewMIMETypes](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewmimetypes).

   ```ts
   photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
   ```

4. Create a **photoViewPicker** instance and call [PhotoViewPicker.select](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#select) to open the **Gallery** page for the user to select images. After the images are selected, [PhotoSelectResult](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#photoselectresult) is returned.

   The permission on the URIs returned by **select()** is read-only. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   If metadata needs to be obtained, you can use the [@ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md) and [@ohos.file.fileuri](../../reference/apis-core-file-kit/js-apis-file-fileuri.md) APIs to obtain file attribute information, such as the file name, size, access time, modification time, and path, based on the URI.

   ```ts
   let uris: Array<string> = [];
   const photoViewPicker = new photoAccessHelper.PhotoViewPicker();
   photoViewPicker.select(photoSelectOptions).then((photoSelectResult: photoAccessHelper.PhotoSelectResult) => {
     uris = photoSelectResult.photoUris;
     console.info('photoViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

5. After the UI is returned from **Gallery**, use a button to trigger the application's API. Use [fs.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open a file based on the URI. After the file is opened, the FD is returned. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. Use [fs.readSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#readsync) to read the file based on the FD, and use **closeSync** to close the file.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

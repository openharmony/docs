# Managing Media Assets

Applications can call **photoAccessHelper** APIs to manage media assets (images and videos).

> **NOTE**
>
> - Before you start, you need to obtain a **PhotoAccessHelper** instance and apply for required permissions. For details, see [photoAccessHelper Overview](photoAccessHelper-overview.md).
> - Unless otherwise specified, the **PhotoAccessHelper** instance obtained in [photoAccessHelper Overview](photoAccessHelper-overview.md) is used to call **photoAccessHelper** APIs. If the code for obtaining the **PhotoAccessHelper** instance is missing, an error will be reported to indicate that **photoAccessHelper** is not defined.

To ensure application running efficiency, most **PhotoAccessHelper** APIs are asynchronously implemented in callback or promise mode. The following code samples use promise-based APIs. For details about the APIs, see [Album Management](../reference/apis/js-apis-photoAccessHelper.md).

## Obtaining the Specified Media Assets

You can obtain media assets based on the specified conditions, such as the media type, date, or album name.

Use [PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1) with the [FetchOptions](../reference/apis/js-apis-photoAccessHelper.md#fetchoptions) object to specify the search criteria. Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained when the sample code is executed, check whether the media assets exist in the database.

To obtain the object at the specified position (for example, the first one, the last one, or the one with the specified index) in the result set, use [FetchResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult).

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

The thumbnails offer a quick preview on images and videos. You can use [PhotoAsset.getThumbnail](../reference/apis/js-apis-photoAccessHelper.md#getthumbnail-2) with the thumbnail size specified to obtain the image or video thumbnail. 

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.READ_IMAGEVIDEO** permission.
- The [dataSharePredicates](../reference/apis/js-apis-data-dataSharePredicates.md) module is imported.

### Obtaining the Thumbnail of an Image

Your application may need to obtain the thumbnail of an image or video for preview purposes.

Example: Obtain the thumbnail at the size of 720 x 720 of an image.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the result set.
4. Call **PhotoAsset.getThumbnail** to obtain the [PixelMap](../reference/apis/js-apis-image.md#pixelmap7) of the thumbnail of the image.

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

Use [PhotoAccessHelper.createAsset](../reference/apis/js-apis-photoAccessHelper.md#createasset-3) to create a media asset.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.WRITE_IMAGEVIDEO** permission.

### Creating an Image or Video Asset

Example: Create an image asset.

**How to Develop**

1. Set the file name and create **createOption** for setting attributes for the image asset to create.
2. Call **PhotoAccessHelper.createAsset** to create an image asset.

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

    let photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(displayName, createOption);
    console.info('createAsset successfully, file displayName: ' + photoAsset.displayName);
  } catch (err) {
    console.error('createAsset failed, message = ', err);
  }
}
```

## Creating a Media Asset Using a Security Component

Example: Create an image asset using a security component. When using a security component to create a media asset, you do not need to apply for the **ohos.permission.WRITE_IMAGEVIDEO** permission for your application. For details, see [\<SaveButton>](../reference/arkui-ts/ts-security-components-savebutton.md).

**How to Develop**

1. Set the attributes of the security component.
2. Create a security component.
3. Create an image asset by calling [PhotoAccessHelper.createAsset](../reference/apis/js-apis-photoAccessHelper.md#createasset-6).

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper'
import fs from '@ohos.file.fs';

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
                 let uri = await phAccessHelper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'jpg'); // Create a media asset.
                 console.info('createAsset successfully, uri: ' + uri);
                 let file = await fs.open(uri, fs.OpenMode.READ_WRITE);
                 await fs.close(file);
               } catch (err) {
                 console.error('createAsset failed, message = ', err);
               }
             } else {
               console.error('SaveButtonOnClickResult createAsset failed');
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

Obtain the media asset using [FetchResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult), set the **PhotoAsset.displayName** attribute to modify the file name (including the file name extension) displayed, and use [PhotoAsset.commitModify](../reference/apis/js-apis-photoAccessHelper.md#commitmodify-1) to save the modification to the database.



**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.WRITE_IMAGEVIDEO** and **ohos.permission.READ_IMAGEVIDEO** permissions.

Example: Rename the first image in the obtained image assets.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image from the obtained file assets.
4. Call [PhotoAsset.set](../reference/apis/js-apis-photoAccessHelper.md#set) to rename the image.
5. Call **PhotoAsset.commitModify** to save the modification to the database.

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;
    let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
    console.info('getAssets photoAsset.title : ' + photoAssetTitle);
    photoAsset.set(title, newTitle);
    await photoAsset.commitModify();
    fetchResult.close();
  } catch (err) {
    console.error('commitModify failed with err: ' + err);
  }
}
```

## Moving a Media Asset to the Trash

You can use [PhotoAccessHelper.deleteAssets](../reference/apis/js-apis-photoAccessHelper.md#deleteassets-1) to move a file to the trash.

The file moved to the trash will be retained for 30 days before being deleted permanently. Before a file is deleted permanently from the trash, the user can restore it through the system application **Files** or **Gallery**.

**Prerequisites**

- A **PhotoAccessHelper** instance is obtained.
- The application has the **ohos.permission.WRITE_IMAGEVIDEO** and **ohos.permission.READ_IMAGEVIDEO** permissions.

Example: Move the first image in the result set to the trash.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the first image, that is, the image object to be moved to the trash.
4. Call **PhotoAccessHelper.deleteAssets** to move the image to the trash.

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
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    await phAccessHelper.deleteAssets([photoAsset.uri]);
    fetchResult.close();
  } catch (err) {
    console.error('deleteAssets failed with err: ' + err);
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
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   
   const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   ```

3. Set the file type and the maximum number of media files to select.
   For example, select a maximum of five images. For details about the media file types, see [PhotoViewMIMETypes](../reference/apis/js-apis-photoAccessHelper.md#photoviewmimetypes).

   ```ts
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   
   photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images to select.
   ```

4. Create a **photoViewPicker** instance and call [PhotoViewPicker.select](../reference/apis/js-apis-photoAccessHelper.md#select) to open the **Gallery** page for the user to select files. After the files are selected, the [PhotoSelectResult](../reference/apis/js-apis-photoAccessHelper.md#photoselectresult) is returned.

   The permission on the URIs returned by **select()** is read-only. Note that the URI cannot be directly used in the **picker** callback to open a file. You need to define a global variable to save the URI and use a button to trigger file opening.

   If metadata needs to be obtained, you can use [file management](../reference/apis/js-apis-file-fs.md) and [file URI](../reference/apis/js-apis-file-fileuri.md) APIs to obtain file attribute information, such as the file size, access time, modification time, file name, and file path, based on the URI.

   ```ts
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import { BusinessError } from '@ohos.base';
   
   let uris: Array<string> = [];
   const photoViewPicker = new photoAccessHelper.PhotoViewPicker();
   photoViewPicker.select(photoSelectOptions).then((photoSelectResult: photoAccessHelper.PhotoSelectResult) => {
     uris = photoSelectResult.photoUris;
     console.info('photoViewPicker.select to file succeed and uris are:' + uris);
   }).catch((err: BusinessError) => {
     console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

5. After the UI is returned from the **Gallery** page, use a button to trigger API calling. Use [fs.openSync()](../reference/apis/js-apis-file-fs.md#fsopensync) to open the file based on the URI and obtain the FD. Note that the **mode** parameter of **fs.openSync()** must be **fs.OpenMode.READ_ONLY**.

   ```ts
   import fs from '@ohos.file.fs';
   
   let uri: string = '';
   let file = fs.openSync(uri, fs.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

6. Use [fs.readSync()](../reference/apis/js-apis-file-fs.md#readsync) to read the file based on the FD. After the data is read, close the FD.

   ```ts
   import fs from '@ohos.file.fs';
   
   let buffer = new ArrayBuffer(4096);
   let readLen = fs.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fs.closeSync(file);
   ```

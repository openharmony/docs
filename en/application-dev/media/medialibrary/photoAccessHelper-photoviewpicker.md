# Selecting Media Assets Using Picker

When a user needs to share files such as images and videos, use Picker to start **Gallery** for the user to select the files to share. No permission is required when Picker is used. Currently, a UIAbility is used to start **Gallery** with the window component. The procedure is as follows:

1. Import modules.

   ```ts
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Create a **PhotoSelectOptions** instance.

   ```ts
   const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   ```

3. Set the type and maximum number of the files to select.
   The following uses images as an example. For details about the media file types, see [PhotoViewMIMETypes](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#photoviewmimetypes).

   ```ts
   photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images that can be selected.
   ```

4. Create a **photoViewPicker** instance and call [PhotoViewPicker.select](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#select) to open the **Gallery** page for the user to select images. After the images are selected, [PhotoSelectResult](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#photoselectresult) is returned.

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

   The permission on the URIs returned by **select()** is read-only. File data can be read based on the URI. Note that the URI cannot be directly used in the Picker callback to open a file. You need to define a global variable to save the URI and use a button to open the file. For details, see [Reading File Data by URI](#reading-file-data-by-uri).

   You can also [obtain an image or video based on the URI](#obtaining-an-image-or-video-by-uri).

   If metadata needs to be obtained, you can use the [@ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md) and [@ohos.file.fileuri](../../reference/apis-core-file-kit/js-apis-file-fileuri.md) APIs to obtain file attribute information, such as the file name, size, access time, modification time, and path, based on the URI.

## Reading File Data by URI

1. After the application UI is returned from **Gallery**, use a button to trigger the application's API. Use [fileIo.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open an image based on the URI. After the image is opened, the FD is returned. Note that the **mode** parameter of **fileIo.openSync()** must be **fileIo.OpenMode.READ_ONLY**.

   ```ts
   let uri: string = '';
   let file = fileIo.openSync(uri, fileIo.OpenMode.READ_ONLY);
   console.info('file fd: ' + file.fd);
   ```

2. Use [fileIo.readSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#readsync) to read the file based on the FD, and close the FD after the data is read.

   ```ts
   let buffer = new ArrayBuffer(4096);
   let readLen = fileIo.readSync(file.fd, buffer);
   console.info('readSync data to file succeed and buffer size is:' + readLen);
   fileIo.closeSync(file);
   ```

## Obtaining an Image or Video by URI

After an image or video is selected by Picker, the URI of the image or video is returned. You can obtain the image or video based on the URI. The following example demonstrates how to obtain the image based on the URI **file://media/Photo/1/IMG_datetime_0001/displayName.jpg**.

```ts
import { dataSharePredicates } from '@kit.ArkData';

const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
  onDataPrepared(data: ArrayBuffer) {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    console.info('on image data prepared');
    // Customize the logic for processing data.
  }
}

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let uri = 'file://media/Photo/1/IMG_datetime_0001/displayName.jpg' // The URI must exist.
  predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uri.toString());
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [photoAccessHelper.PhotoKeys.TITLE],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    // Obtain the file attribute information, such as the title. If the attribute to obtain is not a default one, add the column name to fetchColumns.
    console.info('title : ' + photoAsset.get(photoAccessHelper.PhotoKeys.TITLE));
    // Request image data.
    let requestOptions: photoAccessHelper.RequestOptions = {
      deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
    }
    await photoAccessHelper.MediaAssetManager.requestImageData(context, photoAsset, requestOptions, new MediaDataHandler());
    console.info('requestImageData successfully');
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

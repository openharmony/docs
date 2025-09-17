# Selecting Media Assets Using Picker
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

When a user needs to share files such as images and videos, use **Picker** to start Gallery for the user to select the files to share. No permission is required when Picker is used. Currently, a UIAbility is used to start Gallery with the window component. The procedure is as follows:

> **NOTE**
>
> Media Library Kit handles image and video management. If you need to read and save audio files, use [AudioViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker).

1. Import modules.

   ```ts
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Create a PhotoSelectOptions instance.

   ```ts
   const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   ```

3. Set the type and maximum number of media files to select.
   The following uses images as an example. For details about the media file types, see [PhotoViewMIMETypes](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-e.md#photoviewmimetypes).

   ```ts
   photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE; // Select images.
   photoSelectOptions.maxSelectNumber = 5; // Set the maximum number of images that can be selected.
   ```

4. Create a photoViewPicker instance and call [PhotoViewPicker.select](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md#select) to open Gallery for the user to select images. After the images are selected, [PhotoSelectResult](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-class.md#photoselectresult) is returned.

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

1. After the UI returns from Gallery, use a button to call other functions. Specifically, use[fileIo.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fsopensync) to open the file and obtain its FD through the [media file URI](../../file-management/user-file-uri-intro.md#media-file-uri). Note that the **mode** parameter of **fileIo.openSync()** must be **fileIo.OpenMode.READ_ONLY**.

   ```ts
   try {
     let uri: string = '';
     let file = fileIo.openSync(uri, fileIo.OpenMode.READ_ONLY);
     console.info('file fd: ' + file.fd);
   } catch (error) {
     console.error('openSync failed with err: ' + error);
   }
   ```

2. Call [fileIo.readSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#readsync) to read the file based on the FD, and close the FD after the data is read.

   ```ts
   try {
     // buffer indicates the buffer length, which is user-defined.
     let buffer = new ArrayBuffer(4096);
     let readLen = fileIo.readSync(file.fd, buffer);
     console.info('readSync data to file succeed and buffer size is:' + readLen);
     fileIo.closeSync(file);
   } catch (error) {
     console.error('readSync or closeSync failed with err: ' + error);
   }
   ```

## Obtaining an Image or Video by URI

The media library allows **Picker** to select a [media file URI](../../file-management/user-file-uri-intro.md#media-file-uri) and obtain the corresponding image or video. The following describes how to query a URI named **'file://media/Photo/1/IMG_datetime_0001/displayName.jpg'**.

1. Define a media asset handler called [MediaAssetDataHandler](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetDataHandler.md). The system calls back to the application with **onDataPrepared** when the asset is ready.

   ```ts
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { dataSharePredicates } from '@kit.ArkData';
   
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
   ```

2. Call [getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1) to obtain the assets, and call [requestImageData](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetManager.md#requestimagedata11) to obtain the specific asset.

   ```ts
   async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
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

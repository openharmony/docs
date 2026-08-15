# Selecting Media Assets Using Picker

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=8bc6eb9b043e320094531d7c2aa0228f7356e5c7 translatedAt=2026-08-15T01:57:44.442Z pushedAt=2026-08-15T09:04:52.663Z -->

When a user needs to share files such as images and videos, use **Picker** to start Gallery for the user to select the files to share. No permission is required when Picker is used. Currently, a UIAbility is used to start Gallery with the window component. The procedure is as follows:

> **NOTE**
> Media Library Kit handles image and video management. If you need to read and save audio files, use [AudioViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker).

1. Import modules.

   <!-- @[PickerMediaLibrary_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->  

   ``` TypeScript
   import { fileIo } from '@kit.CoreFileKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   ```

2. Create a PhotoSelectOptions instance for image-video files.

   <!-- @[PickerMediaLibrary_createOptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   const photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
   ```

3. Set the type and maximum number of media files to select.

    The following example uses image selection. For media file types, see [PhotoViewMIMETypes](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-e.md#photoviewmimetypes).

    <!-- @[PickerMediaLibrary_configOptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   photoSelectOptions.maxSelectNumber = 5;
   photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
   photoSelectOptions.isPhotoTakingSupported = true;
   ```

4. Create a photoViewPicker instance and call [PhotoViewPicker.select](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoViewPicker.md#select) to open Gallery for the user to select images. After the images are selected, [PhotoSelectResult](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-class.md#photoselectresult) is returned.

   <!-- @[PickerMediaLibrary_select](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/pages/Index.ets) -->  

   ``` TypeScript
   const result = await photoViewPicker.select(photoSelectOptions);
               
   // After the files are selected, PhotoSelectResult is returned.
   console.info('Selection successful, returning result: ' + JSON.stringify(result));
   console.info('Number of selected files: ' + result.photoUris.length);
         
   // Update the list of selected URIs.
   this.selectedUris = result.photoUris;
   // Use the first selected URI as the default URI for read operations.
   if (this.selectedUris.length > 0) {
     this.selectedUriForRead = this.selectedUris[0];
   }
         
   // Invoke the utility class to process the result.
   this.processedItems = MediaLibraryPickerUtils.handleSelectResult(this.selectedUris);
   console.info('Number of processed results: ' + this.processedItems.length);
   ```

   The permission on the URIs returned by **select()** is read-only. File data can be read based on the URI. Note that the URI cannot be directly used in the Picker callback to open a file. You need to define a global variable to save the URI and use a button to open the file. For details, see [Reading File Data by URI](#reading-file-data-by-uri).

   You can also [obtain an image or video based on the URI](#obtaining-an-image-or-video-by-uri).

   If you need to obtain metadata, you can use [@ohos.file.fs (File Management)](../../reference/apis-core-file-kit/js-apis-file-fs.md) and [File URI](../../reference/apis-core-file-kit/js-apis-file-fileuri.md) to get some file attribute information based on the URI, such as file size, access time, modification time, file name, and file path.

## Reading File Data by URI

1. After the UI returns from Gallery, use a button-like component to call another function. In the function, call the [fileIo.openSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#fileioopensync) API to open the media file using the [media file URI](../../file-management/user-file-uri-intro.md#media-file-uri) and obtain the file descriptor (FD). Note that the **mode** parameter of **fileIo.openSync()** must be **fileIo.OpenMode.READ_ONLY**.

   <!-- @[PickerMediaLibrary_openFile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->

   ``` TypeScript
   try {
     const file = fileIo.openSync(uri, fileIo.OpenMode.READ_ONLY);
     console.info('file fd: ' + file.fd);
     return { fd: file.fd, file: file };
   } catch (error) {
     console.error('openSync failed with err: ' + error);
     return null;
   }
   ```

2. Call [fileIo.readSync](../../reference/apis-core-file-kit/js-apis-file-fs.md#readsync) to read the file based on the FD, and close the FD after the data is read.

   <!-- @[PickerMediaLibrary_readFileData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->

   ``` TypeScript
   try {
     const buffer = new ArrayBuffer(bufferSize);
     const readLen = fileIo.readSync(fileObj.fd, buffer);
     console.info('readSync data to file succeed and buffer size is:' + readLen);
     return { data: buffer, length: readLen };
   } catch (error) {
     console.error('readSync failed with err: ' + error);
     return null;
   }
   ```

## Obtaining an Image or Video by URI

The media library allows **Picker** to select a [media file URI](../../file-management/user-file-uri-intro.md#media-file-uri) and obtain the corresponding image or video. The following describes how to query a URI named **file://media/Photo/1/IMG_datetime_0001/displayName.jpg**.

1. Define a media asset handler called [MediaAssetDataHandler](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetDataHandler.md). The system calls back to the application with **onDataPrepared** when the asset is ready.

   <!-- @[PickerMediaLibrary_handler](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->  

   ``` TypeScript
   export class MediaAssetDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
     private callback?: MediaDataHandlerCallback;
     
     constructor(callback?: MediaDataHandlerCallback) {
       this.callback = callback;
     }
   
     // Use the arrow function to ensure that the this reference is not lost.
     onDataPrepared = (data: ArrayBuffer, map?: Map<string, string>) => {
       if (data === undefined) {
         console.error('Error occurred when preparing data');
         return;
       }
       console.info('on image data prepared, photo quality is ' + map?.get('quality'));
       // Now this always points to the MediaAssetDataHandler instance.
       if (this.callback) {
         this.callback(data);
       }
     };
   }
   ```

2. Call [getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1) to obtain the assets, and call [requestImageData](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetManager.md#requestimagedata11) to obtain the specific asset.

   > **NOTE**
   > To protect user privacy, sensitive EXIF metadata, including geographical location and shooting parameters, is automatically anonymized in media files. To retrieve the original, non-anonymized EXIF information, your application must [request the permission](photoAccessHelper-preparation.md#requesting-permissions) ohos.permission.MEDIA_LOCATION from the **PhotoAccessHelper** module.

   <!-- @[PickerMediaLibrary_getMediaResource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Picker/PickerMediaLibrarySample/entry/src/main/ets/common/utils/MediaLibraryPickerUtils.ets) -->  

   ``` TypeScript
   static async getMediaResourceByUri(uri: string, context: common.Context, callback?: MediaDataHandlerCallback)
   : Promise<void> {
     let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> | null = null;
     try {
       // Create a PhotoAccessHelper instance.
       const phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
         
       // Create query conditions.
       const predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
       predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uri);
         
       // Configure query options.
       const fetchOptions: photoAccessHelper.FetchOptions = {
         fetchColumns: [photoAccessHelper.PhotoKeys.TITLE],
         predicates: predicates
       };
   
       // Query assets.
       fetchResult = await phAccessHelper.getAssets(fetchOptions);
         
       const photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
       if (photoAsset) {
         console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
         // Obtain the title property.
         console.info('title : ' + photoAsset.get(photoAccessHelper.PhotoKeys.TITLE));
           
         // Configure request options.
         const requestOptions: photoAccessHelper.RequestOptions = {
           deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
         };
           
         // Request image data.
         await photoAccessHelper.MediaAssetManager.requestImageData(
           context, photoAsset, requestOptions, new MediaAssetDataHandler(callback));
           
         console.info('requestImageData successfully');
       } else {
         console.error('No asset found for URI: ' + uri);
       }
         
     } catch (err) {
       console.error('getMediaResourceByUri failed with err: ' + err);
     } finally {
        // Close the query result.
        if (fetchResult !== null) {
          fetchResult.close();
        }
     }
   }
   ```
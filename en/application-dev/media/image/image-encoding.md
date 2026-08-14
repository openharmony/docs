# Using ImagePacker to Encode Images

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:45:41.927Z pushedAt=2026-08-11T06:40:05.995Z -->

Image encoding refers to the process of compressing a PixelMap into different image file formats for the purpose of saving and transferring.

[PackToData](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtodata13-1) and [PackToFile](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtofile11-2) can be used to encode a [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) into JPEG, WebP, PNG, HEIC, and TIFF formats.

Starting from API version 18, you can use [PackToDataFromPixelmapSequence](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtodatafrompixelmapsequence18) and [PackToFileFromPixelmapSequence](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtofilefrompixelmapsequence18) to encode multiple PixelMaps into the GIF format.

Starting from API version 26.0.0, [PackBinaryImageToTiffFile](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packbinaryimagetotifffile) and [PackBinaryImageToTiffData](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packbinaryimagetotiffdata) can be used to encode binary image data into TIFF format.

## How to Develop

For details about image encoding APIs, see [ImagePacker](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md).

### Encoding Images into File Streams

1. Import the required modules.

   <!-- @[encodingPixelMap_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/EncodingPixelMap.ets) -->    

   ``` TypeScript
   // Import related modules.
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { resourceManager } from '@kit.LocalizationKit';
   ```

2. Set the encoding options [PackingOption](../../reference/apis-image-kit/arkts-apis-image-i.md#packingoption).

   2.1 This example encodes an image in JPEG format. The target encoding format follows the MIME standard, so `PackingOption.format` must be set to `image/jpeg`, and the encoded file extension can be `.jpg` or `.jpeg`.

   <!-- @[create_packOpts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

   ``` TypeScript
   // The default quality value is 0, and a value no less than 80 is recommended. In this example, it is uniformly set to 90 to balance image quality and file size.
   let packOpts : image.PackingOption = { format: 'image/jpeg', quality: 90 };
   ```

   2.2 When the image source is HDR and you want to encode it as an HDR image file, you must additionally configure `desiredDynamicRange`.

   <!-- @[packOpts_isHdr](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

   ``` TypeScript
   // If the resource is HDR and the device supports HDR encoding, the content is encoded as HDR (requires the resource to be HDR and the device to support HDR encoding; JPEG format is supported).
   packOpts.desiredDynamicRange = image.PackingDynamicRange.AUTO;
   ```

3. Encapsulate a function that accepts an `imageSource` or `pixelMap`. Use [packToData](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtodata13) to encode the image into an `ArrayBuffer`, or [packToFile](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtofile11) to encode the image into a file.

   > **NOTE**
   >
   > Before encoding, obtain an `imageSource` or `pixelMap` first. For details, see [Using ImageSource to Decode Images](./image-decoding.md).

   - Define `copyData` to obtain the encoded file stream for subsequent saving as an image or decoding for display.

     <!-- @[create_copyData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     let copyData: ArrayBuffer = new ArrayBuffer(0);
     ```

   - Encode a `pixelMap` to an `ArrayBuffer`.

     <!-- @[packToData_pixelMap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     async function packToDataFromPixelMap(pixelMap : image.PixelMap) {
       const imagePackerApi = image.createImagePacker();
       // The default value of quality is 0, and a value no lower than 80 is recommended. In this example, quality is uniformly set to 90 to balance image quality and file size.
       let packOpts : image.PackingOption = { format: 'image/jpeg', quality: 90 };
       // If the resource itself is HDR and the device supports HDR encoding, the content is encoded as HDR (the resource must be HDR, the device must support HDR encoding, and the JPEG format is supported).
       packOpts.desiredDynamicRange = image.PackingDynamicRange.AUTO;
       try{
         let data = await imagePackerApi.packToData(pixelMap, packOpts);
         // data is the file stream obtained from encoding. Write it to a file to save an image.
         copyData = new ArrayBuffer(0);
         copyData = data;
       } catch (error) {
         console.error('Failed to pack the pixelMap to data. And the error is: ' + error);
       }
     }
     ```

   - Encode an `imageSource` to an `ArrayBuffer`.

     <!-- @[packToData_imageSource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->  

     ``` TypeScript
     async function packToDataFromImageSource(imageSource : image.ImageSource) {
       const imagePackerApi = image.createImagePacker();
       // The default value of quality is 0. It is recommended to set it to no less than 80. In this example, it is uniformly set to 90 to balance image quality and file size.
       let packOpts : image.PackingOption = { format: 'image/jpeg', quality: 90 };
       try {
         let data = await imagePackerApi.packToData(imageSource, packOpts);
         // data is the file stream obtained from encoding. Write it to a file to save an image.
         copyData = new ArrayBuffer(0);
         copyData = data;
       } catch (error) {
         console.error('Failed to pack the imageSource to data. And the error is: ' + error);
       }
     }
     ```

   - Encode a `pixelMap` to a file.

     <!-- @[packToFile_pixelMap](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->    

     ``` TypeScript
     async function packToFileFromPixelMap(context : Context, pixelMap : image.PixelMap) {
       const imagePackerApi = image.createImagePacker();
       // The default value of quality is 0, and a value no lower than 80 is recommended. In this example, it is uniformly set to 90 to balance image quality and file size.
       let packOpts : image.PackingOption = { format: 'image/jpeg', quality: 90 };
       const path : string = context.cacheDir + '/pixel_map.jpg';
       let file: fileIo.File | undefined = undefined;
       try {
         file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
         await imagePackerApi.packToFile(pixelMap, file.fd, packOpts);
       } catch (error) {
         console.error('Failed to pack the pixelMap to file. And the error is: ' + error);
       } finally {
         if (file) {
           fileIo.closeSync(file.fd);
         }
       }
     }
     ```

   - Encode an `imageSource` to a file.

     <!-- @[packToFile_imageSource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->    

     ``` TypeScript
     async function packToFileFromImageSource(context : Context, imageSource : image.ImageSource) {
       const imagePackerApi = image.createImagePacker();
       // The default value of quality is 0, and a value no lower than 80 is recommended. In this example, quality is uniformly set to 90 to balance image quality and file size.
       let packOpts : image.PackingOption = { format: 'image/jpeg', quality: 90 };
       const filePath : string = context.cacheDir + '/image_source.jpg';
       let file: fileIo.File | undefined = undefined;
       try {
         file = fileIo.openSync(filePath, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
         await imagePackerApi.packToFile(imageSource, file.fd, packOpts);
       } catch (error) {
         console.error('Failed to pack the imageSource to file. And the error is: ' + error);
       } finally {
         if (file) {
           fileIo.closeSync(file.fd);
         }
       }
     }
     ```

4. Save the image to the gallery.

After encoding the image to an `ArrayBuffer` or file, you can use the relevant APIs of [Media Library Kit](../medialibrary/photoAccessHelper-overview.md) to [save media library resources](../medialibrary/photoAccessHelper-savebutton.md) to the gallery.

<!--RP1-->
<!--RP1End-->
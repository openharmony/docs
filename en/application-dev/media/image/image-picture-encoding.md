# Using ImagePacker to Encode Pictures

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:46:10.017Z pushedAt=2026-08-11T07:34:53.240Z -->

Image encoding refers to the process of encoding a [Picture](../../reference/apis-image-kit/arkts-apis-image-Picture.md) object into image files of different formats (currently only JPEG and HEIF formats are supported) for subsequent processing, such as saving and transmission.

## How to Develop

For details about image encoding APIs, see [ImagePacker](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md).

1. Import the required modules.

   <!-- @[encodingPicture_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/EncodingPicture.ets) -->    

   ``` TypeScript
   // Import the related modules.
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { resourceManager } from '@kit.LocalizationKit';
   ```

2. Set the encoding options [PackingOption](../../reference/apis-image-kit/arkts-apis-image-i.md#packingoption).

   > **NOTE**
   >
   > Here, encoding to a JPEG image is used as an example. The target encoding format follows the MIME standard. Therefore, **PackingOption.format** must be set to `image/jpeg`, and the encoded file extension can be `.jpg` or `.jpeg`.

   <!-- @[create_picturePackOpts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->    

   ``` TypeScript
   let packOpts: image.PackingOption = {
     format: 'image/jpeg',
     // The default value of quality is 0. It is recommended to set it to no less than 80. In this example, it is set to 90 to balance image quality and file size.
     quality: 90,
     needsPackProperties: true
   };
   ```

3. Encapsulate a function, pass in `picture`, and use the [packing](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packing13) API to encode to an ArrayBuffer, or use the [packToFile](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md#packtofile11-2) API to encode to a file.

   > **NOTE**
   >
   > Before encoding, you need to obtain the picture through decoding. For details, see [Using ImageSource to Decode Pictures](./image-picture-decoding.md).

   - Encode the `picture` to an ArrayBuffer.

     <!-- @[packToData_picture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->    

     ``` TypeScript
     async function packing(picture: image.Picture, packOpts: image.PackingOption) {
       const imagePackerApi = image.createImagePacker();
       try {
         let data = await imagePackerApi.packing(picture, packOpts);
         copyData = data;
         console.info('Succeeded in packing the image.');
       } catch (error) {
         console.error('Failed to pack the picture to data. And the error is: ' + error);
       } finally {
         await imagePackerApi.release();
       }
     }
     ```

   - Encode the picture to a file.

     <!-- @[packToFile_picture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->    

     ``` TypeScript
     async function packToFile(picture: image.Picture, packOpts: image.PackingOption, context: Context) {
       let imagePackerApi: image.ImagePacker | undefined = undefined;
       let file: fileIo.File | undefined = undefined;
       try {
         const path : string = context.cacheDir + '/picture.jpg';
         file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
         imagePackerApi = image.createImagePacker();
         await imagePackerApi.packToFile(picture, file.fd, packOpts);
       } catch (error) {
         console.error('Failed to pack the picture to file. And the error is: ' + error);
       } finally {
         if (file) {
           fileIo.closeSync(file.fd);
         }
         if (imagePackerApi) {
           await imagePackerApi.release();
         }
       }
     }
     ```
# Reading and Editing Image Exif Data

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=ccdf26d9d10c53eff04ea24e30d31cc6f6b71655 translatedAt=2026-08-11T01:48:26.525Z pushedAt=2026-08-11T09:49:38.827Z -->

Image Kit provides the capabilities of reading and editing Exchangeable Image File Format (Exif) data.

Exchangeable image file format (Exif) is a file format dedicated for photos taken by digital cameras and is used to record attribute information and shooting data of digital photos. The image must contain Exif data.

In applications such as Gallery, camera, and image editing, you can read Exif data including shooting time, orientation, focal length, and geographic location, and modify part of the Exif data when needed. For example, when the manual lens parameters of the camera are not automatically written as part of the Exif data, or when the shooting time is incorrect due to a camera power failure, you can manually correct the corresponding Exif data.

Currently, the system allows you to read and modify only part of the Exif data. For details about the supported range, see [PropertyKey](../../reference/apis-image-kit/arkts-apis-image-e.md#propertykey7). The following table lists the read and write support for Exif data across different image formats.

| Image Format | Read Exif Data | Modify Exif Data |
| -------- | -------- | -------- |
| JPG/JPEG | Supported | Supported |
| PNG | Supported | Supported |
| HEIF | Supported | Supported |
| WebP<sup>23+</sup> | Supported | Supported |
| DNG<sup>23+</sup> | Supported | Not supported |

## Available APIs

The following APIs are used for reading and editing Exif data. For details, see [ImageSource](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md).

| API | Description |
| -------- | -------- |
| [getImageProperty](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#getimageproperty11) | Obtains the Exif data of a specified attribute key. |
| [modifyImageProperty](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#modifyimageproperty11) | Modifies the Exif data of a specified attribute key. |

## Precautions

- You must create an [ImageSource](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md) object before reading or editing Exif data.

- Before reading the Exif data of an image, ensure that the app has the read permission on the target image. Before modifying the Exif data of an image, ensure that the app has the write permission on the target image.

- In certain image source or access scenarios, the system may remove privacy information such as GPS data even if the app has the read permission on the image. In such cases, the corresponding Exif data cannot be obtained.

- The image file must contain Exif data. For images that do not contain Exif data or do not include the target attribute key, the read result may be empty or return a default value.

- Before modifying Exif data, ensure that the image format and the target attribute key support writing.

- Image metadata may contain privacy information such as shooting location. Before displaying, uploading, or sharing images, ensure that you have obtained proper user authorization and implemented privacy protection based on your service scenario.

## How to Develop

After obtaining the image and creating an ImageSource object, you can read or edit Exif data. The sample code is as follows:

1. Import the required modules.

   <!-- @[editExif_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ExifUtility.ets) -->   

   ``` TypeScript
   // Import the related modules.
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the Exif data of a specified key.

   <!-- @[get_exif](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ExifUtility.ets) -->   

   ``` TypeScript
   // Example for obtaining Exif data of a specified key.
   async getExif(imageSourceApi: image.ImageSource | undefined, key: image.PropertyKey): Promise<string> {
     let info: string = '';
     if (imageSourceApi) {
       console.info('getExif: The imageSourceApi is not undefined.');
       // Obtain Exif data of a specified key.
       let options: image.ImagePropertyOptions = { index: 0, defaultValue: 'This key has no value!' };
       try {
         let data = await imageSourceApi.getImageProperty(key, options);
         info = `Succeeded in getting the ${key}'s value: ${data}.`;
         console.info(info);
         return info; // Return the key if it is obtained successfully.
       } catch (error) {
         info =
           `Failed to get the value of the ${key} with error: ${error}.`;
         console.error(info);
         return info; // Return an error message if the key fails to be obtained.
       }
     } else {
       info = 'getExif: The imageSourceApi is undefined.';
       console.info(info);
       return info; // Return the information if imageSourceApi is undefined.
     }
   }
   ```

3. Modify the Exif data of a specified key.

   <!-- @[modify_exif](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ExifUtility.ets) -->   

   ``` TypeScript
   // Example for modifying Exif data of a specified key.
   async modifyExif(imageSourceApi: image.ImageSource | undefined, key: image.PropertyKey, value: string)
     : Promise<string> {
     let info: string = '';
     if (imageSourceApi) {
       // Edit the Exif data.
       try {
         await imageSourceApi.modifyImageProperty(key, value);
         try {
           let modifyValue = await imageSourceApi.getImageProperty(key)
           info = `The ${key}'s value is modified to ${modifyValue}.`
           console.info(info);
           return info; // Return a success message if the key is obtained successfully.
         } catch (error) {
           console.error(`Failed to get the ${key}'s value with ${error}`);
           console.error(info);
           return info; // Return an error message if the key fails to be obtained.
         }
       } catch (error) {
         info = `Failed to modify the ${key}'s value with ${error}`;
         console.error(info);
         return info; // Return an error message if the key fails to be modified.
       }
     } else {
       info = 'modifyExif: The imageSourceApi is undefined.';
       console.info(info);
       return info; // Return the information if imageSourceApi is undefined.
     }
   }
   ```
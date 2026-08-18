# Using ImageSource to Decode Pictures

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=5ebc42431866e478171b45f0c3c1a73229dae334 translatedAt=2026-08-11T01:46:39.513Z pushedAt=2026-08-11T07:31:05.659Z -->

You can decode an image file in a supported format into a [Picture](image-overview.md#basic-concepts) object for HDR image display, auxiliary picture processing, and other operations in an app or system. Currently supported image file formats include JPEG and HEIF.

Picture is a multi-picture object that contains a main picture, auxiliary pictures, and metadata. The main picture contains the primary image information, auxiliary pictures store additional information related to the main picture (such as `GAINMAP`, the HDR Gain Map), and metadata stores other image-related information. Picture is suitable for scenarios such as HDR image processing and HEIF professional format decoding.

## Differences Between Picture and PixelMap

Picture and PixelMap are two different image decoding objects, each suitable for different scenarios.

| Object Type | Applicable Scenario | Feature |
|---|---|---|
| [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) | Single-image display, basic image processing | Contains single pixel data, supports image transformations (cropping, scaling, rotation, etc.) and PixelMap operations, and can be directly passed to the Image component for display. |
| [Picture](../../reference/apis-image-kit/arkts-apis-image-Picture.md) | HDR images, HEIF professional format, auxiliary picture processing | Contains main picture + auxiliary pictures + metadata. You can extract the main picture, gain map, or composite HDR image as a PixelMap for display or processing. Supports auxiliary picture and metadata operations. |

> **Selection advice:**
> - Use PixelMap when you need to directly display a single image or perform image processing such as cropping, scaling, and rotation.
> - Use Picture when you need to process HDR images, obtain auxiliary pictures (such as GAINMAP), or operate on image metadata. If you need to crop or scale the content of a Picture, you can extract a PixelMap through methods such as [getMainPixelmap](../../reference/apis-image-kit/arkts-apis-image-Picture.md#getmainpixelmap13) and then process it.

## How to Develop

For details about the APIs related to image decoding, see [ImageSource](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md).

1. Import the image module.

   <!-- @[decodingPicture_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/DecodingPicture.ets) -->    

   ``` TypeScript
   // Import the required modules.
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { resourceManager } from '@kit.LocalizationKit';
   ```

2. Obtain an image.

   - Method 1: Directly obtain the image through the sandbox path. This method applies only to images in the application sandbox path. For details about how to obtain the sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).

     <!-- @[get_filePath](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     function getFilePath(context: Context, fileName: string): string {
       const filePath: string = context.cacheDir + '/' + fileName;
       return filePath;
     }
     ```

   - Method 2: Obtain the file descriptor of the image via the sandbox path. For details, see [@ohos.file.fs (File Management)](../../reference/apis-core-file-kit/js-apis-file-fs.md). This method requires importing the \@kit.CoreFileKit module.

     <!-- @[get_fileFd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     function getFileFd(context: Context, fileName: string): number | undefined {
       try {
         const filePath: string = context.cacheDir + '/' + fileName;
         const file: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_ONLY);
         const fd: number = file?.fd;
         return fd;
       } catch (err) {
         console.error(`Failed to get the fileFd with error: ${err}.`);
         return undefined;
       }
     }
     ```

   - Method 3: Obtain the `ArrayBuffer` of a resource file through the resource manager. For details, see [getRawFileContent](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfilecontent9-1). This method requires importing the \@kit.LocalizationKit module.

     <!-- @[get_fileBuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->    

     ``` TypeScript
     async function getFileBuffer(context: Context, fileName: string): Promise<ArrayBuffer | undefined> {
       try {
         const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
         // Obtain the resource file content. The Uint8Array is returned.
         const fileData: Uint8Array = await resourceMgr.getRawFileContent(fileName);
         console.info('Successfully get the RawFileContent.');
         // Convert the array to an ArrayBuffer and return the ArrayBuffer.
         const buffer: ArrayBuffer = fileData.buffer.slice(0);
         return buffer;
       } catch (error) {
         console.error(`Failed to get the RawFileContent with error: ${error}.`);
         return undefined;
       }
     }
     ```

   - Method 4: Obtain the `RawFileDescriptor` of a resource file through the resource manager. For details, see [getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9-1). This method requires importing the \@kit.LocalizationKit module.

     <!-- @[get_RawFd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     async function getRawFd(context: Context, fileName: string): Promise<resourceManager.RawFileDescriptor | undefined> {
       try {
         const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
         const rawFileDescriptor: resourceManager.RawFileDescriptor = await resourceMgr.getRawFd(fileName);
         console.info('Successfully get the RawFileDescriptor.');
         return rawFileDescriptor;
       } catch (error) {
         console.error(`Failed to get the RawFileDescriptor with error: ${error}.`);
         return undefined;
       }
     }
     ```

3. Create an ImageSource instance.

   - Method 1: Create an ImageSource instance using the sandbox path. The sandbox path can be obtained by using method 1 in step 2.

     <!-- @[createImageSource_filePath](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     // path indicates the obtained sandbox path.
     const imageSource : image.ImageSource = image.createImageSource(filePath);
     ```

   - Method 2: Create an ImageSource instance using the file descriptor. The file descriptor can be obtained by using method 2 in step 2.

     <!-- @[createImageSource_fd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->  

     ``` TypeScript
     // fd is the obtained file descriptor.
     const imageSource: image.ImageSource = image.createImageSource(fd);
     ```

   - Method 3: Create an ImageSource instance using an array buffer. The array buffer can be obtained by using method 3 in step 2.

     <!-- @[createImageSource_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->  

     ``` TypeScript
     const imageSource: image.ImageSource = image.createImageSource(buffer);
     ```

   - Method 4: Create an ImageSource instance using the raw file descriptor of the resource file. The raw file descriptor can be obtained by using method 4 in step 2.

     <!-- @[createImageSource_rawFd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     const imageSource: image.ImageSource = image.createImageSource(rawFileDescriptor);
     ```

4. Set the decoding parameter `DecodingOptionsForPicture` and decode to obtain a Picture object.

   During decoding, you can specify the auxiliary picture types to decode. Auxiliary pictures are not directly displayed as standalone images; instead, they serve as auxiliary data in image processing (such as HDR compositing and depth information extraction). Common auxiliary picture types include:

   | Auxiliary Picture Type | Description |
   |---|---|
   | GAINMAP | Gain map, used for high dynamic range rendering of HDR images. |
   | DEPTH_MAP | Depth map, stores pixel distance information for scenarios such as 3D reconstruction and background separation. |
   | UNREFOCUS_MAP | Unrefocused original image, used for portrait bokeh post-processing. |
   | LINEAR_MAP | Linear map, used for visual effect enhancement and color post-processing. |
   | FRAGMENT_MAP | Watermark crop map, used for scenarios such as watermark removal and original image restoration. |

   > **NOTE**
   >
   > Not all images contain auxiliary pictures. Before obtaining an auxiliary picture, call the [getAuxiliaryPicture](../../reference/apis-image-kit/arkts-apis-image-Picture.md#getauxiliarypicture13) method of Picture to attempt to retrieve it. For other auxiliary picture types, see [AuxiliaryPictureType](../../reference/apis-image-kit/arkts-apis-image-e.md#auxiliarypicturetype13).

   <!-- @[create_picture](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

   ``` TypeScript
   async createPicture(imageSource : image.ImageSource | undefined, isReturnAux: Boolean)
     : Promise<image.PixelMap | undefined | image.Picture> {
     // Set the decoding options.
     let options: image.DecodingOptionsForPicture = {
       desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP indicates the type of the auxiliary picture to be decoded.
     };
     let returnPixelMap: image.PixelMap | undefined = undefined;
     // Create a Picture instance.
     try {
       let picture = await imageSource?.createPicture(options);
       if (picture) {
         // Return the auxiliary picture obtained after decoding.
         if (isReturnAux) {
           // type is the type of the auxiliary picture contained in the decoding options.
           let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
           let auxPicture: image.AuxiliaryPicture | null = picture.getAuxiliaryPicture(type);
           // Obtain the information of the auxiliary picture.
           if (auxPicture != null) {
             let auxInfo: image.AuxiliaryPictureInfo = auxPicture.getAuxiliaryPictureInfo();
             console.info('GetAuxiliaryPictureInfo type: ' + auxInfo.auxiliaryPictureType +
               ' height: ' + auxInfo.size.height + ' width: ' + auxInfo.size.width +
               ' rowStride: ' + auxInfo.rowStride + ' pixelFormat: ' + auxInfo.pixelFormat +
               ' colorSpace: ' + auxInfo.colorSpace);
             // Read data of the auxiliary picture and write the data to an ArrayBuffer.
             try {
               let pixelsBuffer = await auxPicture.readPixelsToBuffer();
               let opts: image.InitializationOptions = { size: auxInfo.size };
               try {
                 returnPixelMap = image.createPixelMapSync(pixelsBuffer, opts) as image.PixelMap;
                 console.info(`Create PixelMap with buffer successfully.`);
               } catch (error) {
                 console.error(`Create PixelMap failed with ${error}.`);
               }
             } catch (error) {
               console.error(`Read pixels to buffer failed, error.code: ${error.code},
                 error.message: ${error.message}`);
             }
             auxPicture.release();
           }
           return returnPixelMap;
         } else {
           return picture; // Return the decoded Picture instance.
         }
       }
       return returnPixelMap;
     } catch (error) {
       console.error(`Create picture failed: ${error}.`);
     }
     return returnPixelMap;
   }
   ```

5. Release the Picture instance.

   Ensure that the asynchronous operations of the Picture instance have finished executing. After these variables are no longer needed, you can manually call the APIs below to release it.

   <!-- @[release_pictureDecoder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

   ``` TypeScript
   async release(picture: image.Picture) {
     picture?.release();
   }
   ```
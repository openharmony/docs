# Using ImageSource to Obtain RAW Data 

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=51871fad202ca89cea4824e5e1f6eae94c62de6c translatedAt=2026-08-11T01:46:17.587Z pushedAt=2026-08-11T08:28:50.459Z -->

Image RAW data is the raw data directly obtained from the image sensor, which fully retains all sensor information without any compression loss. By using RAW data, you can obtain the highest quality image information and customize image processing algorithms based on specific requirements, enabling more flexible image processing and optimization.

Starting from API version 24, you can decode image files in supported formats into [ImageRawData](../../reference/apis-image-kit/arkts-apis-image-i.md#imagerawdata24) to obtain RAW data in your app or system. RAW data includes the image buffer and bits per pixel.

The currently supported image file format is DNG.

## How to Develop

For details about the APIs for obtaining image RAW data, see [createImageRawData](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#createimagerawdata24).

1. Import the `Image` module globally, and import the corresponding Kit modules as needed.

   <!-- @[decodingPixelMap_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/DecodingPixelMap.ets) -->    

   ``` TypeScript
   // Import the required modules.
   import { image } from '@kit.ImageKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { resourceManager } from '@kit.LocalizationKit';
   ```

2. Obtain the image.

   - Method 1: Obtain the image directly through the sandbox path. This method is **only applicable** to images in the app sandbox. For details about how to obtain the path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).

     <!-- @[get_filePath](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     function getFilePath(context: Context, fileName: string): string {
       const filePath: string = context.cacheDir + '/' + fileName;
       return filePath;
     }
     ```

   - Method 2: Obtain the file descriptor of the image through the sandbox path. For details, see [@ohos.file.fs (File Management)](../../reference/apis-core-file-kit/js-apis-file-fs.md). This method requires importing the \@kit.CoreFileKit module.

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

   - Method 3: Obtain the `ArrayBuffer` of a resource file through the resource manager. For details, see [getRawFileContent](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfilecontent9-1). This method requires importing the @kit.LocalizationKit module.

     <!-- @[get_fileBuffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     async function getFileBuffer(context: Context, fileName: string): Promise<ArrayBuffer | undefined> {
       try {
         const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
         // Obtain the resource file content and return a Uint8Array.
         const fileData: Uint8Array = await resourceMgr.getRawFileContent(fileName);
         console.info('Successfully get the RawFileContent.');
         // Convert to ArrayBuffer and return.
         const buffer: ArrayBuffer = fileData.buffer.slice(0);
         return buffer;
       } catch (error) {
         console.error(`Failed to get the RawFileContent with error: ${error}.`);
         return undefined;
       }
     }
     ```

   - Method 4: Obtain the `RawFileDescriptor` of a resource file through the resource manager. For details, see [getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9-1). This method requires importing the @kit.LocalizationKit module.

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

3. Create an `ImageSource` instance.

   - Method 1: Create an `ImageSource` using a sandbox path. The sandbox path can be obtained through method 1 in step 2.

     <!-- @[createImageSource_filePath](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     // path is the obtained sandbox path.
     const imageSource : image.ImageSource = image.createImageSource(filePath);
     ```

   - Method 2: Create an `ImageSource` using a file descriptor (fd). The fd can be obtained through method 2 in step 2.

     <!-- @[createImageSource_fd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     // fd is the obtained file descriptor.
     const imageSource: image.ImageSource = image.createImageSource(fd);
     ```

   - Method 3: Create an `ImageSource` using a buffer array. The buffer array can be obtained through method 3 in step 2.

     <!-- @[createImageSource_buffer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     const imageSource: image.ImageSource = image.createImageSource(buffer);
     ```

   - Method 4: Create an `ImageSource` using the `RawFileDescriptor` of a resource file. The `RawFileDescriptor` can be obtained through method 4 in step 2.

     <!-- @[createImageSource_rawFd](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->   

     ``` TypeScript
     const imageSource: image.ImageSource = image.createImageSource(rawFileDescriptor);
     ```

4. Obtain the `ImageRawData` object and print the pixel values.

   <!-- @[createImageRawData](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/CodecUtility.ets) -->      

   ``` TypeScript
   async createImageRawData(imageSource: image.ImageSource | undefined) : Promise<image.ImageRawData | undefined> {
     if (!imageSource) {
       console.error('imageSource is undefined.');
       return undefined;
     }
     try {
       const data = await imageSource.createImageRawData();
       if (data.bitsPerPixel == 16 && data.buffer) {
         let array: Uint16Array = new Uint16Array(data.buffer);
         let length = array.byteLength.valueOf();
         console.info(`uint16Array length: ${length}`);
         let value: string = '';
         for (let i = 0; i < array.length && i < 10; i++) {
           value += array[i] + ', ';
         }
         console.info(`get dng rawdata is:${value}.`);
       }
       return data;
     } catch (err) {
       console.error(`get dng rawdata failed.err: ${JSON.stringify(err)}`);
       return undefined;
     }
   }
   ```

5. Release the `imageSource`.

   After confirming that the asynchronous method of `imageSource` has completed execution and the variable is no longer in use, you can manually call the following method to release it as needed.

   <!-- @[release_pixelMapDecoder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/pages/DecodingPixelMap.ets) -->    

   ``` TypeScript
   async release() {
     try {
       await this.pixelMap?.release();
     } catch (error) {
       console.error(`Failed to release PixelMap: ${error}.`);
     } finally {
       this.pixelMap = undefined;
     }
   
     try {
       await this.imageSource?.release();
     } catch (error) {
       console.error(`Failed to release ImageSource: ${error}.`);
     } finally {
       this.imageSource = undefined;
     }
   }
   ```
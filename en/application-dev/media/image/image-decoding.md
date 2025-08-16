# Using ImageSource to Decode Images
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

Image decoding refers to the process of decoding an image in a supported format into a [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) for image display or processing. Currently, the following image formats are supported: JPEG, PNG, GIF, WebP, BMP, SVG, ICO, DNG, and HEIF. The supported formats may vary depending on the hardware.

## How to Develop

Read the [API reference](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md) for APIs related to image decoding.

1. Import the image module.

   ```ts
   import { image } from '@kit.ImageKit';
   ```

2. Obtain an image.
   - Method 1: Directly obtain the image through the sandbox path. This method applies only to images in the application sandbox path. For details about how to obtain the sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).

      ```ts
      function getFilePath(context: Context): string {
        const filePath: string = context.cacheDir + '/test.jpg';
        return filePath;
      }
      ```

   - Method 2: Obtain the file descriptor of the image through the sandbox path. For details, see [file.fs API Reference](../../reference/apis-core-file-kit/js-apis-file-fs.md). To use this method, you must import the \@kit.CoreFileKit module first.

      ```ts
      import { fileIo as fs } from '@kit.CoreFileKit';

      function getFileFd(context: Context): number | undefined {
        const filePath: string = context.cacheDir + '/test.jpg';
        const file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
        const fd: number = file?.fd;
        return fd;
      }
      ```

   - Method 3: Obtain the array buffer of the resource file through the resource manager. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfilecontent9-1). To use this method, you must import the \@kit.LocalizationKit module first.

      ```ts
      import { resourceManager } from '@kit.LocalizationKit';

      async function getFileBuffer(context: Context): Promise<ArrayBuffer | undefined> {
         try {
            const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
            // Obtain the resource file content. The Uint8Array is returned.
            const fileData: Uint8Array = await resourceMgr.getRawFileContent('test.jpg');
            console.info('Successfully got RawFileContent');
            // Convert the array to an ArrayBuffer and return the ArrayBuffer.
            const buffer: ArrayBuffer = fileData.buffer.slice(0);
            return buffer;
         } catch (error) {
            console.error("Failed to get RawFileContent");
            return undefined;
         }
      }
      ```

   - Method 4: Obtain the raw file descriptor of the resource file through the resource manager. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9-1). To use this method, you must import the \@kit.LocalizationKit module first.
      ```ts
      import { resourceManager } from '@kit.LocalizationKit';

      async function getRawFd(context: Context): Promise<resourceManager.RawFileDescriptor | undefined> {
         try {
            const resourceMgr: resourceManager.ResourceManager = context.resourceManager;
            const rawFileDescriptor: resourceManager.RawFileDescriptor = await resourceMgr.getRawFd('test.jpg');
            console.info('Successfully got RawFileDescriptor');
            return rawFileDescriptor;
         } catch (error) {
            console.error('Failed to get RawFileDescriptor:');
            return undefined;
         }
      }
      ```

3. Create an ImageSource instance.

   - Method 1: Create an ImageSource instance using the sandbox path. The sandbox path can be obtained by using method 1 in step 2.

      ```ts
      // path indicates the obtained sandbox path.
      const imageSource : image.ImageSource = image.createImageSource(filePath);
      ```

   - Method 2: Create an ImageSource instance using the file descriptor. The file descriptor can be obtained by using method 2 in step 2.

      ```ts
      // fd is the obtained file descriptor.
      const imageSource : image.ImageSource = image.createImageSource(fd);
      ```

   - Method 3: Create an ImageSource instance using an array buffer. The array buffer can be obtained by using method 3 in step 2.

      ```ts
      const imageSource : image.ImageSource = image.createImageSource(buffer);
      ```

   - Method 4: Create an ImageSource instance using the raw file descriptor of the resource file. The raw file descriptor can be obtained by using method 4 in step 2.

      ```ts
      const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
      ```

4. Set **DecodingOptions** and decode the image to obtain a PixelMap.
   - Set the expected format for decoding.
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import { image } from '@kit.ImageKit';

      // Create an ImageSource object. Select a proper method in step 3 to replace the preceding code.
      let fd : number = 0;
      let imageSource : image.ImageSource = image.createImageSource(fd);
      // Set the decoding options.
      let decodingOptions : image.DecodingOptions = {
         editable: true,
         desiredPixelFormat: image.PixelMapFormat.RGBA_8888,
      };
      // Create a PixelMap.
      imageSource.createPixelMap(decodingOptions).then((pixelMap : image.PixelMap) => {
         console.info("Succeeded in creating PixelMap");
      }).catch((err : BusinessError) => {
         console.error("Failed to create PixelMap");
      });
      ```
   - Decode an HDR image.
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import { image } from '@kit.ImageKit';

      // Create an ImageSource object. Select a proper method in step 3 to replace the preceding code.
      let fd : number = 0;
      let imageSource : image.ImageSource = image.createImageSource(fd);
      // Set the decoding options.
      let decodingOptions : image.DecodingOptions = {
         // If IMAGE_DYNAMIC_RANGE_AUTO is passed in, decoding is performed based on the image format. If the image is an HDR resource, an HDR PixelMap is obtained after decoding.
         desiredDynamicRange: image.DecodingDynamicRange.AUTO,
      };
      // Create a PixelMap.
      imageSource.createPixelMap(decodingOptions).then((pixelMap : image.PixelMap) => {
         console.info("Succeeded in creating PixelMap");
         // Check whether the PixelMap is the HDR content.
         let info = pixelMap.getImageInfoSync();
         console.info("pixelmap isHdr:" + info.isHdr);
      }).catch((err : BusinessError) => {
         console.error("Failed to create PixelMap");
      });
      ```
   After the decoding is complete and the PixelMap is obtained, you can perform subsequent [image processing](image-transformation.md).

5. Release the PixelMap and ImageSource instances.

   Ensure that the asynchronous operations of the PixelMap and ImageSource instances have finished executing. After these variables are no longer needed, you can manually call the APIs below to release them.
   ```ts
   pixelMap.release();
   imageSource.release();
   ```

   > **NOTE**
   > 1. When to release the ImageSource instance: After successfully executing **createPixelMap** and obtaining the PixelMap instance, if you are certain that no other APIs of ImageSource will be used, you can manually release the ImageSource instance. Since the PixelMap instance obtained from decoding is independent, releasing the ImageSource instance will not make the PixelMap instance unusable.
   > 2. When to release the PixelMap instance: If you are using the [**Image** component](../../reference/apis-arkui/arkui-ts/ts-basic-components-image.md) for displaying images, there is no need to manually release the PixelMap instance, as the Image component will automatically manage the PixelMap instance passed to it. If your application handles the PixelMap instance on its own, you are advised to manually release the PixelMap instance of the old page during page transitions or when the application switches to the background. In scenarios where memory resources are tight, you are advised to release the PixelMap instances of all invisible pages except the current one.

<!--RP1-->
<!--RP1End-->

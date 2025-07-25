# Using ImageSource to Decode Pictures

Image decoding refers to the process of decoding an image in a supported format (JPEG and HEIF currently) into a [picture](image-overview.md).  

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

4. Set **DecodingOptions** and decode the image to obtain a picture. Manipulate the picture, for example, obtaining an auxiliary picture. For details about how to manipulate a picture and auxiliary picture, see [Image API](../../reference/apis-image-kit/arkts-apis-image-Picture.md).

   Set the expected format for decoding.
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import { image } from '@kit.ImageKit';
      // Create an ImageSource object. Select a proper method in step 3 to replace the preceding code.
      let fd : number = 0;
      let imageSource : image.ImageSource = image.createImageSource(fd);
      // Set the decoding options.
      let options: image.DecodingOptionsForPicture = {
         desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP indicates the type of the auxiliary picture to be decoded.
      };
      // Create a Picture instance.
      imageSource.createPicture(options).then((picture: image.Picture) => {
         console.info("Create picture succeeded.");
         let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
         let auxPicture: image.AuxiliaryPicture | null = picture.getAuxiliaryPicture(type);
         // Obtain the information of the auxiliary picture.
         if(auxPicture != null) {
            let auxinfo: image.AuxiliaryPictureInfo = auxPicture.getAuxiliaryPictureInfo();
            console.info('GetAuxiliaryPictureInfo Type: ' + auxinfo.auxiliaryPictureType +
               ' height: ' + auxinfo.size.height + ' width: ' + auxinfo.size.width +
               ' rowStride: ' +  auxinfo.rowStride +  ' pixelFormat: ' + auxinfo.pixelFormat +
               ' colorSpace: ' +  auxinfo.colorSpace);
            // Read data of the auxiliary picture and write the data to an ArrayBuffer.
            auxPicture.readPixelsToBuffer().then((pixelsBuffer: ArrayBuffer) => {
               console.info('Read pixels to buffer success.');
            }).catch((error: BusinessError) => {
               console.error('Read pixels to buffer failed error.code: ' + JSON.stringify(error.code) + ' ,error.message:' + JSON.stringify(error.message));
            });
            auxPicture.release();
         }
      }).catch((err: BusinessError) => {
         console.error("Create picture failed.");
      });
      ```

5. Release the Picture instance.

   Ensure that the asynchronous operations of the Picture instance have finished executing. After these variables are no longer needed, you can manually call the APIs below to release it.
   ```ts
   picture.release();
   ```

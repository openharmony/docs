# Using ImageSource to Decode Pictures

Image decoding refers to the process of decoding an image in a supported format (JPEG and HEIF currently) into a [picture](image-overview.md). Currently, the supported image formats include JPEG and HEIF.

## How to Develop

Read [Image](../../reference/apis-image-kit/js-apis-image.md#imagesource) for APIs related to image decoding.

1. Import the image module.

   ```ts
   import { image } from '@kit.ImageKit';
   ```

2. Obtain an image.
   - Method 1: Directly obtain the image through the sandbox path. This method applies only to images in the application sandbox path. For details about how to obtain the sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).

      ```ts
      const context : Context = getContext(this);
      const filePath : string = context.cacheDir + '/test.jpg';
      ```

   - Method 2: Obtain the file descriptor of the image through the sandbox path. For details, see [file.fs API Reference](../../reference/apis-core-file-kit/js-apis-file-fs.md). To use this method, you must import the \@kit.CoreFileKit module first.

      ```ts
      import { fileIo } from '@kit.CoreFileKit';
      ```

      Then call **fileIo.openSync()** to obtain the file descriptor.
  
      ```ts
      const context = getContext(this);
      const filePath = context.cacheDir + '/test.jpg';
      const file : fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
      const fd : number = file?.fd;
      ```

   - Method 3: Obtain the array buffer of the resource file through the resource manager. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfilecontent9-1).

      ```ts
      const context : Context = getContext(this);
      // Obtain a resource manager.
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      The method of obtaining the resource manager varies according to the application model. After obtaining the resource manager, call **resourceMgr.getRawFileContent()** to obtain the array buffer of the resource file.

      ```ts
      resourceMgr.getRawFileContent('test.jpg').then((fileData : Uint8Array) => {
         console.log("Succeeded in getting RawFileContent")
         // Obtain the array buffer of the image.
         const buffer = fileData.buffer.slice(0);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileContent")
      });
      
      ```

   - Method 4: Obtain the raw file descriptor of the resource file through the resource manager. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9-1).

      ```ts
      const context : Context = getContext(this);
      // Obtain a resource manager.
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      The method of obtaining the resource manager varies according to the application model. After obtaining the resource manager, call **resourceMgr.getRawFd()** to obtain the raw file descriptor of the resource file.

      ```ts
      
      resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor : resourceManager.RawFileDescriptor) => {
         console.log("Succeeded in getting RawFileDescriptor")
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileDescriptor")
      });
      ```

3. Create an **ImageSource** instance.

   - Method 1: Create an **ImageSource** instance using the sandbox path. The sandbox path can be obtained by using method 1 in step 2.

      ```ts
      // path indicates the obtained sandbox path.
      const imageSource : image.ImageSource = image.createImageSource(filePath);
      ```

   - Method 2: Create an **ImageSource** instance using the file descriptor. The file descriptor can be obtained by using method 2 in step 2.

      ```ts
      // fd is the obtained file descriptor.
      const imageSource : image.ImageSource = image.createImageSource(fd);
      ```

   - Method 3: Create an **ImageSource** instance using an array buffer. The array buffer can be obtained by using method 3 in step 2.

      ```ts
      const imageSource : image.ImageSource = image.createImageSource(buffer);
      ```

   - Method 4: Create an **ImageSource** instance using the raw file descriptor of the resource file. The raw file descriptor can be obtained by using method 4 in step 2.

      ```ts
      const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
      ```

4. Set **DecodingOptions** and decode the image to obtain a picture.

   Set the expected format for decoding.
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import image from '@kit.ImageKit';
      let img = await getContext(this).resourceManager.getMediaContent($r('app.media.picture'));
      let imageSource:image.ImageSource = image.createImageSource(img.buffer.slice(0));
      let options: image.DecodingOptionsForPicture = {
         desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP indicates the type of the auxiliary picture to be decoded.
      };
      // Create a Picture instance.
      imageSource.createPicture(options).then((picture: image.Picture) => {
         console.log("Create picture succeeded.")
      }).catch((err: BusinessError) => {
         console.error("Create picture failed.")
      });
      ```

5. Manipulate the picture, for example, obtaining an auxiliary picture. For details about how to manipulate a picture and auxiliary picture, see [Image API](../../reference/apis-image-kit/js-apis-image.md#picture13).

   ```ts
   // Obtain an auxiliary picture.
   let type: image.AuxiliaryPictureType = image.AuxiliaryPictureType.GAINMAP;
   let auxPicture: image.AuxiliaryPicture | null = picture.getAuxiliaryPicture(type);
   // Obtain the information of the auxiliary picture.
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
   ```

6. Release the **Picture** instance.

   ```ts
   picture.release();
   ```

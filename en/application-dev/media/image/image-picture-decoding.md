# Using ImageSource to Decode Pictures

Image decoding refers to the process of decoding an archived image in a supported format (JPEG and HEIF currently) into a [picture](image-overview.md).  

## How to Develop

Read [Image](../../reference/apis-image-kit/js-apis-image.md#imagesource) for APIs related to image decoding.

1. Import the image module.

   ```ts
   import { image } from '@kit.ImageKit';
   ```

2. Obtain an image.
   - Method 1: Obtain the sandbox path. For details about how to obtain the sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).

      ```ts
      // Code on the stage model
      const context : Context = getContext(this);
      const filePath : string = context.cacheDir + '/test.jpg';
      ```

      ```ts
      // Code on the FA model
      import { featureAbility } from '@kit.AbilityKit';
      
      const context = featureAbility.getContext();
      const filePath = context.getCacheDir() + "/test.jpg";
      ```

   - Method 2: Obtain the file descriptor of the image through the sandbox path. For details, see [file.fs API Reference](../../reference/apis-core-file-kit/js-apis-file-fs.md).
      To use this method, you must import the \@kit.CoreFileKit module first.

      ```ts
      import { fileIo } from '@kit.CoreFileKit';
      ```

      Then call **fileIo.openSync()** to obtain the file descriptor.
  
      ```ts
      // Code on the stage model
      const context = getContext(this);
      const filePath = context.cacheDir + '/test.jpg';
      const file : fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE);
      const fd : number = file?.fd;
      ```

      ```ts
      // Code on the FA model
      import { featureAbility } from '@kit.AbilityKit';
      
      const context = featureAbility.getContext();
      const filePath = context.getCacheDir() + "/test.jpg";
      const file : fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
      const fd : number = file?.fd;
      ```

   - Method 3: Obtain the array buffer of the resource file through the resource manager. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfilecontent9-1).

      ```ts
      // Code on the stage model
      const context : Context = getContext(this);
      // Obtain a resource manager.
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      ```ts
      // Code on the FA model
      // Import the resourceManager module.
      import { resourceManager } from '@kit.LocalizationKit';
      import { BusinessError } from '@kit.BasicServicesKit';
      resourceManager.getResourceManager().then((resourceMgr : resourceManager.ResourceManager) => {
         console.log("Succeeded in getting resourceManager")
      }).catch((err : BusinessError) => {
         console.error("Failed to get resourceManager")
      });
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
      // Code on the stage model
      const context : Context = getContext(this);
      // Obtain a resource manager.
      const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
      ```

      ```ts
      // Code on the FA model
      // Import the resourceManager module.
      import { resourceManager } from '@kit.LocalizationKit';
      import { BusinessError } from '@kit.BasicServicesKit';
      resourceManager.getResourceManager().then((resourceMgr : resourceManager.ResourceManager) => {
         console.log("Succeeded in getting resourceManager")
      }).catch((err : BusinessError) => {
         console.error("Failed to get resourceManager")
      });
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

5. Release the **Picture** instance.

   ```ts
   picture.release();
   ```

## Sample Code - Decoding an Image in Resource Files

1. Obtain a resource manager.

   ```ts
   const context : Context = getContext(this);
   // Obtain a resource manager.
   const resourceMgr : resourceManager.ResourceManager = context.resourceManager;
   ```

2. Create an **ImageSource** instance.
   - Create an **ImageSource** instance by using the array buffer of **test.jpg** in the **rawfile** folder.

     ```ts
      resourceMgr.getRawFileContent('test.jpg').then((fileData : Uint8Array) => {
         console.log("Succeeded in getting RawFileContent")
         // Obtain the array buffer of the image.
         const buffer = fileData.buffer.slice(0);
         const imageSource : image.ImageSource = image.createImageSource(buffer);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFileContent")
      });
     ```

   - Create an **ImageSource** instance by using the raw file descriptor of **test.jpg** in the **rawfile** folder.

     ```ts
      resourceMgr.getRawFd('test.jpg').then((rawFileDescriptor : resourceManager.RawFileDescriptor) => {
         console.log("Succeeded in getting RawFd")
         const imageSource : image.ImageSource = image.createImageSource(rawFileDescriptor);
      }).catch((err : BusinessError) => {
         console.error("Failed to get RawFd")
      });
     ```

3. Create a **Picture** instance.

   ```ts
   let options: image.DecodingOptionsForPicture = {
      desiredAuxiliaryPictures: [image.AuxiliaryPictureType.GAINMAP] // GAINMAP indicates the type of the auxiliary picture to be decoded.
   };
   imageSource.createPicture(options).then((picture: image.Picture) => {
      console.log("Create picture succeeded.")
   }).catch((err : BusinessError) => {
      console.error("Create picture failed.")
   });
   ```

4. Release the **Picture** instance.

   ```ts
   picture.release();
   ```

# Using ImageSource to Decode Images

Image decoding refers to the process of decoding an archived image in a supported format into a [PixelMap](image-overview.md) for image display or [processing](image-transformation.md). Currently, the following image formats are supported: JPEG, PNG, GIF, WebP, BMP, SVG, ICO, DNG, and HEIF (depending on the hardware).

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
      import { fileIo as fs } from '@kit.CoreFileKit';
      ```

      Then call **fs.openSync()** to obtain the file descriptor.
  
      ```ts
      // Code on the stage model
      const context = getContext(this);
      const filePath = context.cacheDir + '/test.jpg';
      const file : fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE);
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

4. Set **DecodingOptions** and decode the image to obtain a PixelMap.
   - Set the expected format for decoding.
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import image from '@ohos.multimedia.image';
      let img = await getContext(this).resourceManager.getMediaContent($r('app.media.image'));
      let imageSource:image.ImageSource = image.createImageSource(img.buffer.slice(0));
      let decodingOptions : image.DecodingOptions = {
         editable: true,
         desiredPixelFormat: 3,
      }
      // Create a PixelMap.
      imageSource.createPixelMap(decodingOptions).then((pixelMap : image.PixelMap) => {
         console.log("Succeeded in creating PixelMap")
      }).catch((err : BusinessError) => {
         console.error("Failed to create PixelMap")
      });
      ```
   - Decode an HDR image.
      ```ts
      import { BusinessError } from '@kit.BasicServicesKit';
      import image from '@ohos.multimedia.image';
      let img = await getContext(this).resourceManager.getMediaContent($r('app.media.CUVAHdr'));
      let imageSource:image.ImageSource = image.createImageSource(img.buffer.slice(0));
      let decodingOptions : image.DecodingOptions = {
         // If IMAGE_DYNAMIC_RANGE_AUTO is passed in, decoding is performed based on the image format. If the image is an HDR resource, an HDR PixelMap is obtained after decoding.
         desiredDynamicRange: image.DecodingDynamicRange.AUTO,
      }
      // Create a PixelMap.
      imageSource.createPixelMap(decodingOptions).then((pixelMap : image.PixelMap) => {
         console.log("Succeeded in creating PixelMap")
         // Check whether the PixelMap is the HDR content.
         let info = pixelMap.getImageInfoSync();
         console.log("pixelmap isHdr:" + info.isHdr);
      }).catch((err : BusinessError) => {
         console.error("Failed to create PixelMap")
      });
      ```
   After the decoding is complete and the PixelMap is obtained, you can perform subsequent [image processing](image-transformation.md).

5. Release the **PixelMap** instance.

   ```ts
   pixelMap.release();
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

3. Create a **PixelMap** instance.

   ```ts
   imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
      console.log("Succeeded in creating PixelMap")
   }).catch((err : BusinessError) => {
      console.error("Failed to creating PixelMap")
   });
   ```

4. Release the **PixelMap** instance.

   ```ts
   pixelMap.release();
   ```

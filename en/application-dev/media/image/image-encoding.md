# Using ImagePacker to Encode Images
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

Image encoding refers to the process of encoding a PixelMap into an image in different formats for subsequent processing, such as storage and transmission. Currently, images can be encoded only into the JPEG, WebP, PNG, or HEIF format (depending on the hardware).

## How to Develop

Read the [API reference](../../reference/apis-image-kit/arkts-apis-image-ImagePacker.md) for APIs related to image encoding.

### Encoding Images into File Streams

1. Create an ImagePacker object.

   ```ts
   // Import the required module.
   import { image } from '@kit.ImageKit';
   
   const imagePackerApi = image.createImagePacker();
   ```

2. Set the encoding output stream and encoding parameters.

    - **format** indicates the image encoding format, and **quality** indicates the image quality. The value ranges from 0 to 100, and the value 100 indicates the optimal quality.

      > **NOTE**
      >
      > According to the MIME protocol, the standard encoding format is image/jpeg. When the APIs provided by the image module are used for encoding, **PackingOption.format** must be set to **image/jpeg**. The file name extension of the encoded image file can be .jpg or .jpeg, and the file can be used on platforms that support image/jpeg decoding.

      ```ts
      let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 };
      ```

    - Encode the content as HDR content. (The resource must be HDR resource and the JPEG format must be supported.)
      ```ts
      packOpts.desiredDynamicRange = image.PackingDynamicRange.AUTO;
      ```

3. Create a PixelMap object or an ImageSource object.
   ```ts
   import { common } from '@kit.AbilityKit';

   // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
   let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
   // 'test.jpg' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
   const path: string = context.filesDir + "/test.jpg";
   const imageSource: image.ImageSource = image.createImageSource(path);
   let decodingOptions : image.DecodingOptions = { editable: true, desiredPixelFormat: image.PixelMapFormat.RGBA_8888 };
   let pixelmap = imageSource.createPixelMapSync(decodingOptions);
   ```

4. Encode the image and save the encoded image.

   Method 1: Use **PixelMap** for encoding.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   imagePackerApi.packToData(pixelMap, packOpts).then( (data : ArrayBuffer) => {
     // data is the file stream obtained after encoding. You can write the file and save it to obtain an image.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

   Method 2: Use **ImageSource** for encoding.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   imagePackerApi.packToData(imageSource, packOpts).then( (data : ArrayBuffer) => {
       // data is the file stream obtained after encoding. You can write the file and save it to obtain an image.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

### Encoding Images into Files

During encoding, you can pass in a file path so that the encoded memory data is directly written to the file.

   Method 1: Use **PixelMap** to encode the image and pack it into a file.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   const path : string = context.cacheDir + "/pixel_map.jpg";
   let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
   imagePackerApi.packToFile(pixelMap, file.fd, packOpts).then(() => {
       // Encode the data directly into the file.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   }).finally(()=>{
     fs.closeSync(file.fd);
   })
   ```

   Method 2: Use **ImageSource** to encode the image and pack it into a file.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo as fs } from '@kit.CoreFileKit';
   const filePath : string = context.cacheDir + "/image_source.jpg";
   let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
   imagePackerApi.packToFile(imageSource, file.fd, packOpts).then(() => {
       // Encode the data directly into the file.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   }).finally(()=>{
     fs.closeSync(file.fd);
   })
   ```

### Saving Encoded Images to Gallery

You can save the encoded image to the application sandbox, and use the media file management APIs to [save media library resources](../medialibrary/photoAccessHelper-savebutton.md).

<!--RP1-->
<!--RP1End-->

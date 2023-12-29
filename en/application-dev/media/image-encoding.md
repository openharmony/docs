# Image Encoding (ArkTS)

Image encoding refers to the process of encoding a pixel map into an archived image in different formats (only in JPEG, WebP, and PNG currently) for subsequent processing, such as storage and transmission.

## How to Develop

Read [Image API Reference](../reference/apis/js-apis-image.md#imagepacker) for APIs related to image encoding.

### Encoding Images into File Streams

1. Create an **ImagePacker** object.
   
   ```ts
   // Import the required module.
   import image from '@ohos.multimedia.image';
   
   const imagePackerApi = image.createImagePacker();
   ```

2. Set the encoding output stream and encoding parameters.
   
   **format** indicates the image encoding format, and **quality** indicates the image quality. The value ranges from 0 to 100, and the value 100 indicates the optimal quality.

   ```ts
   let packOpts : image.PackingOption = { format:"image/jpeg", quality:98 };
   ```

3. [Create a PixelMap object or an ImageSource object](image-decoding.md).

4. Encode the image and save the encoded image.
   
   Method 1: Use **PixelMap** for encoding.

   ```ts
   import {BusinessError} from '@ohos.base'
   imagePackerApi.packing(pixelMap, packOpts).then( (data : ArrayBuffer) => {
     // data is the file stream obtained after packing. You can write the file and save it to obtain an image.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

   Method 2: Use **ImageSource** for encoding.

   ```ts
   import {BusinessError} from '@ohos.base'
   imagePackerApi.packing(imageSource, packOpts).then( (data : ArrayBuffer) => {
       // data is the file stream obtained after packing. You can write the file and save it to obtain an image.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

### Encoding Images into Files

During encoding, you can pass in a file path so that the encoded memory data is directly written to the file.

Method 1: Use **PixelMap** to encode the image and pack it into a file.

   ```ts
   import {BusinessError} from '@ohos.base'
   import fs from '@ohos.file.fs'
   const context : Context = getContext(this);
   const path : string = context.cacheDir + "/pixel_map.jpg";
   let file = fs.openSync(path, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
   imagePackerApi.packToFile(pixelMap, file.fd, packOpts).then(() => {
       // Pack the image into the file.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

Method 2: Use **ImageSource** to encode the image and pack it into a file.

   ```ts
   import {BusinessError} from '@ohos.base'
   import fs from '@ohos.file.fs'
   const context : Context = getContext(this);
   const filePath : string = context.cacheDir + "/image_source.jpg";
   let file = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
   imagePackerApi.packToFile(imageSource, file.fd, packOpts).then(() => {
       // Pack the image into the file.
   }).catch((error : BusinessError) => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

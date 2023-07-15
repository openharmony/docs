# Image Encoding

Image encoding refers to the process of encoding a pixel map into an archived image in different formats (only in JPEG and WebP currently) for subsequent processing, such as storage and transmission.

## How to Develop

Read [Image](../reference/apis/js-apis-image.md#imagepacker) for APIs related to image encoding.

1. Create an **ImagePacker** object.
   
   ```ts
   // Import the required module.
   import image from '@ohos.multimedia.image';
   
   const imagePackerApi = image.createImagePacker();
   ```

2. Set the encoding output stream and encoding parameters.
   
   **format** indicates the image encoding format, and **quality** indicates the image quality. The value ranges from 0 to 100, and the value 100 indicates the optimal quality.

   ```ts
   let packOpts = { format:"image/jpeg", quality:98 };
   ```

3. [Create a PixelMap object or an ImageSource object](image-decoding.md).

4. Encode the image and save the encoded image.
   
   Method 1: Use the **PixelMap** object for encoding.

   ```ts
   imagePackerApi.packing(pixelMap, packOpts).then( data => {
     // data is the file stream obtained after packing. You can write the file and save it to obtain an image.
   }).catch(error => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

   Method 2: Use the **ImageSource** object for encoding.

   ```ts
   imagePackerApi.packing(imageSource, packOpts).then( data => {
       // data is the file stream obtained after packing. You can write the file and save it to obtain an image.
   }).catch(error => { 
     console.error('Failed to pack the image. And the error is: ' + error); 
   })
   ```

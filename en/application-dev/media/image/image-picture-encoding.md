# Using ImagePacker to Encode Pictures
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Image encoding refers to the process of encoding a picture into an image in different formats (only in JPEG and HEIF currently) for subsequent processing, such as storage and transmission.

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

   **format** indicates the image encoding format, and **quality** indicates the image quality. The value ranges from 0 to 100, and the value 100 indicates the optimal quality.

      > **NOTE**
      >
      > According to the MIME protocol, the standard encoding format is image/jpeg. When the APIs provided by the image module are used for encoding, **PackingOption.format** must be set to **image/jpeg**. The file name extension of the encoded image file can be .jpg or .jpeg, and the file can be used on platforms that support image/jpeg decoding.

      ```ts
      let packOpts: image.PackingOption = {
        format: "image/jpeg",
        quality: 98,
        bufferSize: 10,
        desiredDynamicRange: image.PackingDynamicRange.AUTO,
        needsPackProperties: true
      };
      ```

3. Encode the image and save the encoded image. Before encoding, you need to obtain a Picture object through decoding. For details, see [Using ImageSource to Decode Pictures](./image-picture-decoding.md).

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   function packing(picture: image.Picture, packOpts: image.PackingOption) {
     const imagePackerApi = image.createImagePacker();
     imagePackerApi.packing(picture, packOpts).then( (data : ArrayBuffer) => {
       console.info('Succeeded in packing the image.'+ data);
     }).catch((error : BusinessError) => { 
       console.error(`Failed to pack the image, error.code: ${error.code}, error.message: ${error.message}`); 
     })
   }
   ```

### Encoding Images into Files

During encoding, you can pass in a file path so that the encoded memory data is directly written to the file. Before encoding, you need to obtain a Picture object through decoding. For details, see [Using ImageSource to Decode Pictures](./image-picture-decoding.md).

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { image } from '@kit.ImageKit';

function packToFile(picture: image.Picture, packOpts: image.PackingOption, context: Context) {
  const path : string = context.cacheDir + "/picture.jpg";
  let file = fileIo.openSync(path, fileIo.OpenMode.CREATE | fileIo.OpenMode.READ_WRITE);
  const imagePackerApi = image.createImagePacker();
  imagePackerApi.packToFile(picture, file.fd, packOpts).then(() => {
    console.info('Succeeded in packing the image to file.');
  }).catch((error : BusinessError) => {
    console.error('Failed to pack the image. And the error is: ' + error);
  })
}
  ```

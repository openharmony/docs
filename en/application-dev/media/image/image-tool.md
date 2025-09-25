# Editing EXIF Data
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Image Kit provides the capabilities of reading and editing Exchangeable Image File Format (EXIF) data.

EXIF is a file format dedicated for photos taken by digital cameras and is used to record attributes and shooting data of the photos. Currently, JPEG, PNG, and HEIF images that contain EXIF data are supported.

Users may need to view or modify the EXIF data of photos in the Gallery application, for example, when the manual lens parameters of the camera are not automatically written as part of the EXIF data or the shooting time is incorrect due to camera power-off.

Currently, OpenHarmony allows you to view and modify part of EXIF data. For details, see [Exif](../../reference/apis-image-kit/arkts-apis-image-e.md#propertykey7).

## How to Develop

Read the [API reference](../../reference/apis-image-kit/arkts-apis-image-ImageSource.md#getimageproperty11) for APIs used to read and edit EXIF data.

Obtain the image and create an ImageSource object. Read and edit EXIF data. The code snippet is as follows:

```ts
// Import the required module.
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the sandbox path and create an ImageSource object.
const fd : number = 0; // Obtain the file descriptor of the image to be processed.
const imageSourceApi : image.ImageSource = image.createImageSource(fd);

// Read the EXIF data, where BitsPerSample indicates the number of bits per pixel.
let options : image.ImagePropertyOptions = { index: 0, defaultValue: 'This key has no value!' };
imageSourceApi.getImageProperty(image.PropertyKey.BITS_PER_SAMPLE, options).then((data : string) => {
  console.info('Succeeded in getting the value of the specified attribute key of the image.');
}).catch((error : BusinessError) => {
  console.error(`Failed to get the value of the specified attribute key of the image, error.code: ${error.code}, error.message: ${error.message}`);
})

// Edit the EXIF data.
imageSourceApi.modifyImageProperty(image.PropertyKey.IMAGE_WIDTH, "120").then(() => {
  imageSourceApi.getImageProperty(image.PropertyKey.IMAGE_WIDTH).then((width : string) => {
    console.info('The new imageWidth is ' + width);
  }).catch((error : BusinessError) => {
    console.error(`Failed to get the Image Width, error.code: ${error.code}, error.message: ${error.message}`);
  })
}).catch((error : BusinessError) => {
  console.error(`Failed to modify the Image Width, error.code: ${error.code}, error.message: ${error.message}`);
})
```

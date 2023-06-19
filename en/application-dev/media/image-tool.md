# Image Tool

The image tool provides the capabilities of reading and editing Exchangeable Image File Format (EXIF) data of an image.

EXIF is a file format dedicated for photos taken by digital cameras and is used to record attributes and shooting data of the photos. Currently, the image tool supports images in JPEG format only.

Users may need to view or modify the EXIF data of photos in the Gallery application, for example, when the manual lens parameters of the camera are not automatically written as part of the EXIF data or the shooting time is incorrect due to camera power-off.

Currently, OpenHarmony allows you to view and modify part of EXIF data. For details, see [EIXF](../reference/apis/js-apis-image.md#propertykey7).

## How to Develop

Read [Image](../reference/apis/js-apis-image.md#getimageproperty7) for APIs used to read and edit EXIF data.

1. Obtain the image and create an **ImageSource** object.
     
   ```ts
   // Import the required module.
   import image from '@ohos.multimedia.image';
   
   // Obtain the sandbox path and create an ImageSource object.
   const fd =...; //Obtain the file descriptor of the image to be processed.
   const imageSource = image.createImageSource(fd);
   ```

2. Read and edit EXIF data.
     
   ```ts
   // Read the EXIF data, where BitsPerSample indicates the number of bits per pixel.
   imageSource.getImageProperty('BitsPerSample', (error, data) => {
     if (error) {
       console.error('Failed to get the value of the specified attribute key of the image.And the error is: ' + error);
     } else {
       console.info('Succeeded in getting the value of the specified attribute key of the image ' + data);
     }
   })
   
   // Edit the EXIF data.
   imageSource.modifyImageProperty('ImageWidth', '120').then(() => {
     const width = imageSource.getImageProperty("ImageWidth");
     console.info('The new imageWidth is ' + width);
   })
   ```

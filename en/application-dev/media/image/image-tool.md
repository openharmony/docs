# Editing EXIF Data

The image tool provides the capabilities of reading and editing Exchangeable Image File Format (EXIF) data of an image.

EXIF is a file format dedicated for photos taken by digital cameras and is used to record attributes and shooting data of the photos. Currently, the image tool supports images in JPEG format only.

Users may need to view or modify the EXIF data of photos in the Gallery application, for example, when the manual lens parameters of the camera are not automatically written as part of the EXIF data or the shooting time is incorrect due to camera power-off.

Currently, OpenHarmony allows you to view and modify part of EXIF data. For details, see [Exif](../../reference/apis-image-kit/js-apis-image.md#propertykey7).

## How to Develop

Read [Image](../../reference/apis-image-kit/js-apis-image.md#getimageproperty11) for APIs used to read and edit EXIF data.

1. Obtain the image and create an **ImageSource** object.

   ```ts
   // Import the required module.
   import { image } from '@kit.ImageKit';

   // Obtain the sandbox path and create an ImageSource object.
   const fd : number = 0; // Obtain the file descriptor of the image to be processed.
   const imageSourceApi : image.ImageSource = image.createImageSource(fd);
   ```

2. Read and edit EXIF data.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    // Read the EXIF data, where BitsPerSample indicates the number of bits per pixel.
    let options : image.ImagePropertyOptions = { index: 0, defaultValue: '9999' }
    imageSourceApi.getImageProperty(image.PropertyKey.BITS_PER_SAMPLE, options).then((data : string) => {
        console.log('Succeeded in getting the value of the specified attribute key of the image.');
    }).catch((error : BusinessError) => {
        console.error('Failed to get the value of the specified attribute key of the image.');
    })

    // Edit the EXIF data.
    imageSourceApi.modifyImageProperty(image.PropertyKey.IMAGE_WIDTH, "120").then(() => {
        imageSourceApi.getImageProperty(image.PropertyKey.IMAGE_WIDTH).then((width : string) => {
            console.info('The new imageWidth is ' + width);
        }).catch((error : BusinessError) => {
            console.error('Failed to get the Image Width.');
        })
    }).catch((error : BusinessError) => {
        console.error('Failed to modify the Image Width');
    })
    ```

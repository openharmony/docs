# Using ImageReceiver to Receive Images
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

You can use the **ImageReceiver** class to obtain the surface ID of a component, read the latest image or the next image, and release ImageReceiver instances.

> **NOTE**
>
> The ImageReceiver works as a consumer and needs a matching producer to provide data to work properly. Typical producers are the camera's photo or preview streams. The ImageReceiver merely serves as the recipient and consumer of images. The properties set in ImageReceiver, such as size and format, do not actually take effect. The parameters passed when creating the ImageReceiver object do not have a practical impact. Image properties need to be configured on the sending side (the producer), such as when setting up the [profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile) for a [camera preview stream](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput).

The ImageReceiver can receive images from the camera's preview stream, allowing for [dual-channel preview](../camera/camera-dual-channel-preview.md).

Read [Image](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md) for APIs related to ImageReceiver.

## How to Develop

Create an ImageReceiver object, obtain the surface ID to create a preview stream, register image listeners, and process each frame of the image in the preview stream as required.

1. Create an ImageReceiver object, through which you can obtain the surface ID of the preview stream.

    ```ts
    import { image } from '@kit.ImageKit';
    let imageWidth: number = 1920; // Use the width in the profile size supported by the device.
    let imageHeight: number = 1080; // Use the height in the profile size supported by the device.

    async function initImageReceiver():Promise<void>{
      // Create an ImageReceiver object. The parameters in createImageReceiver do not have any impact on the received data.
      let size: image.Size = { width: imageWidth, height: imageHeight };
      let imageReceiver = image.createImageReceiver(size, image.ImageFormat.JPEG, 8);
      // Obtain the preview stream surface ID.
      let imageReceiverSurfaceId = await imageReceiver.getReceivingSurfaceId();
      console.info(`initImageReceiver imageReceiverSurfaceId:${imageReceiverSurfaceId}`);
    }
    ```

2. Register a listener to process each frame of image data in the preview stream. Specifically, use the **imageArrival** event in the ImageReceiver object to obtain the image data returned by the bottom layer. For details, see [Image API Reference](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md).

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { image } from '@kit.ImageKit';

    function onImageArrival(receiver: image.ImageReceiver): void {
      // Subscribe to the imageArrival event.
      receiver.on('imageArrival', () => {
        // Obtain an image.
        receiver.readNextImage((err: BusinessError, nextImage: image.Image) => {
          if (err || nextImage === undefined) {
            console.error('readNextImage failed');
            return;
          }
          // Parse the image.
          nextImage.getComponent(image.ComponentType.JPEG, async (err: BusinessError, imgComponent: image.Component) => {
            if (err || imgComponent === undefined) {
              console.error('getComponent failed');
            }
            if (imgComponent.byteBuffer) {
              // For details, see the description of parsing the image buffer data below. This example uses method 1.
              let width = nextImage.size.width; // Obtain the image width.
              let height = nextImage.size.height; // Obtain the image height.
              let stride = imgComponent.rowStride; // Obtain the image stride.
              console.debug(`getComponent with width:${width} height:${height} stride:${stride}`);
              // The value of stride is the same as that of width.
              if (stride == width) {
                let pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
                  size: { height: height, width: width },
                  srcPixelFormat: 8,
                })
              } else {
                // The value of stride is different from that of width.
                const dstBufferSize = width * height * 1.5
                const dstArr = new Uint8Array(dstBufferSize)
                for (let j = 0; j < height * 1.5; j++) {
                  const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width)
                  dstArr.set(srcBuf, j * width)
                }
                let pixelMap = await image.createPixelMap(dstArr.buffer, {
                  size: { height: height, width: width },
                  srcPixelFormat: 8,
                })
              }
            } else {
              console.error('byteBuffer is null');
            }
            // Release the resource when the buffer is not in use.
            // If an asynchronous operation is performed on the buffer, call nextImage.release() to release the resource after the asynchronous operation is complete.
            nextImage.release();
          })
        })
      })
    }
    ```


    The following methods are available for parsing the image buffer data by using [image.Component](../../reference/apis-image-kit/arkts-apis-image-i.md#component9).

    > **NOTE**
    >
    > Check whether the width of the image is the same as **rowStride**. If they are different, perform the following operations:

    Method 1: Remove the stride data from **imgComponent.byteBuffer**, obtain a new buffer by means of copy, and process the buffer by calling the API that does not support stride.

    ```ts
    // For example, for NV21 (images in YUV_420_SP format), the formula for calculating the YUV_420_SP memory is as follows: YUV_420_SP memory = Width * Height + (Width * Height)/2.
    const dstBufferSize = width * height * 1.5;
    const dstArr = new Uint8Array(dstBufferSize);
    // Read the buffer data line by line.
    for (let j = 0; j < height * 1.5; j++) {
      // Copy the first width bytes of each line of data in imgComponent.byteBuffer to dstArr.
      const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width);
      dstArr.set(srcBuf, j * width);
    }
    let pixelMap = await image.createPixelMap(dstArr.buffer, {
      size: { height: height, width: width }, srcPixelFormat: 8
    });
    ```

    Method 2: Create a PixelMap based on the value of stride * height, and call **cropSync** of the PixelMap to crop redundant pixels.

    ```ts
    // Create a PixelMap, with width set to the value of stride.
    let pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
      size:{height: height, width: stride}, srcPixelFormat: 8});
    // Crop extra pixels.
    pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0});
    ```

    Method 3: Pass **imgComponent.byteBuffer** and **stride** to the API that supports stride.

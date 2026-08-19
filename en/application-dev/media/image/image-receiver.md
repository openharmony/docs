# Using ImageReceiver to Receive Images

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9c84817ecfdb73f1ad172057d38a83c345823e4f translatedAt=2026-08-11T01:47:39.792Z pushedAt=2026-08-11T08:37:23.400Z -->

You can use the **ImageReceiver** class to obtain the surface ID of a component, read the latest image or the next image, and release ImageReceiver instances.

> **NOTE**
> As a consumer, the Receiver requires a corresponding producer to provide data for full functionality. Common producers are the camera's capture stream or preview stream. **ImageReceiver** only serves as the image receiver and consumer. Properties such as size and format set on **ImageReceiver** do not actually take effect, and parameters passed when creating **ImageReceiver** have no actual impact. Image properties must be set on the sender (producer) side, for example, by configuring [profile](../../reference/apis-camera-kit/arkts-apis-camera-i.md#profile) when using [createpreviewoutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput) to create a camera preview stream.

The ImageReceiver can receive images from the camera's preview stream, allowing for [dual-channel preview](../camera/camera-dual-channel-preview.md).

For detailed information about related APIs, see [ImageReceiver](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md).

## How to Develop

Create an ImageReceiver object, obtain the surface ID to create a preview stream, register image listeners, and process each frame of the image in the preview stream as required.

1. Import the required modules.

   <!-- @[receiver_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ReceiverUtility.ets) -->  

   ``` TypeScript
   import { image } from '@kit.ImageKit'
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit'
   import { hilog } from '@kit.PerformanceAnalysisKit';
   ```

2. Create an ImageReceiver object, through which you can obtain the surface ID of the preview stream.

   <!-- @[init_receiver](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ReceiverUtility.ets) -->    

   ``` TypeScript
   async function initImageReceiver(): Promise<void> {
     // Create an ImageReceiver object. The parameters in createImageReceiver do not have any impact on the received data.
     let size: image.Size = { width: imageWidth, height: imageHeight };
     // capacity specifies the expected number of caches. The actual value depends on the device capability, and 8 is only an example.
     let imageReceiver = image.createImageReceiver(size, image.ImageFormat.JPEG, 8);
     // Obtain the preview stream surface ID.
     let imageReceiverSurfaceId = await imageReceiver.getReceivingSurfaceId();
     console.info(`initImageReceiver imageReceiverSurfaceId:${imageReceiverSurfaceId}`);
   }
   ```

3. Register a listener to process each frame of image data in the preview stream. The image data is returned from the underlying layer through the imageArrival event in ImageReceiver. For details about the APIs, see [ImageReceiver](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md).

   <!-- @[On_imageArrival](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ReceiverUtility.ets) -->   

   ``` TypeScript
   function onImageArrival(receiver: image.ImageReceiver) {
     // Subscribe to the imageArrival event.
     receiver.on('imageArrival', () => {
       // Obtain an image.
       receiver.readNextImage((err: BusinessError, nextImage: image.Image) => {
         if (err || nextImage === undefined) {
           console.error('readNextImage failed');
           return;
         }
         // Parse the image.
         (async () => {
           try {
             let imgComponent = await nextImage.getComponent(image.ComponentType.JPEG);
             if (!imgComponent.byteBuffer) {
               console.error('byteBuffer is null');
               return;
             }
             // For details, see the description of parsing the image buffer data below. This example uses method 1.
             let width = nextImage.size.width; // Obtain the image width.
             let height = nextImage.size.height; // Obtain the image height.
             let stride = imgComponent.rowStride; // Obtain the image stride.
             console.debug(`getComponent with width:${width} height:${height} stride:${stride}`);
             // The value of stride is the same as that of width.
             if (stride == width) {
               let pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
                 size: { height: height, width: width },
                 srcPixelFormat: image.PixelMapFormat.NV21,
               })
             } else {
               // The value of stride is different from that of width.
               const dstBufferSize = width * height * 1.5;
               const dstArr = new Uint8Array(dstBufferSize);
               for (let j = 0; j < height * 1.5; j++) {
                 // Different devices have different memory capacities. If the memory is insufficient, it might not be able to complete the write operation.
                 const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width);
                 dstArr.set(srcBuf, j * width);
               }
               let pixelMap = await image.createPixelMap(dstArr.buffer, {
                 size: { height: height, width: width },
                 srcPixelFormat: image.PixelMapFormat.NV21,
               })
             }
           } catch (error) {
             console.error('getComponent failed');
           } finally {
             // Ensure that the current buffer is not in use before releasing resources.
             // If asynchronous operations are performed on the buffer, release the resource after the asynchronous operations are complete (nextImage.release()).
             await nextImage.release();
           }
         })();
       })
     })
   }
   ```

The following methods are available for parsing the image buffer data by using [image.Component](../../reference/apis-image-kit/arkts-apis-image-i.md#component9).

> **NOTE**
>
> Check whether the image width matches the row stride. If they do not match, you can preprocess the data using either of the two methods outlined below.

Method 1: Remove the stride data from **imgComponent.byteBuffer**, obtain a new buffer by means of copy, and process the buffer by calling the API that does not support stride.

<!-- @[adjust_bufferSize](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ReceiverUtility.ets) -->   

``` TypeScript
// The value of stride is different from that of width.
const dstBufferSize = width * height * 1.5
const dstArr = new Uint8Array(dstBufferSize)
for (let j = 0; j < height * 1.5; j++) {
  const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width)
  dstArr.set(srcBuf, j * width)
}
let pixelMap = await image.createPixelMap(dstArr.buffer, {
  size: { height: height, width: width },
  srcPixelFormat: image.PixelMapFormat.NV21,
})
```

Method 2: Create a PixelMap based on the value of stride * height, and call **cropSync** of the PixelMap to crop redundant pixels.

<!-- @[adjust_width](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Image/ImageArkTSSample/entry/src/main/ets/tools/ReceiverUtility.ets) -->   

``` TypeScript
// Create a pixelMap and pass the stride value to width.
let pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
  size:{height: height, width: stride}, srcPixelFormat: image.PixelMapFormat.NV21});
// Crop extra pixels.
try {
  pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0});
} catch (err) {
  hilog.error(0x00000, TAG, `adjust bufferSize failed: ${err}!`);
}
```
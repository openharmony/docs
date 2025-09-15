# Dual-Channel Preview (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Before developing a camera application, you must [request required permissions](camera-preparation.md).

Dual-channel preview means that an application can use two preview streams at the same time. One preview stream is used for display on the screen, and the other is used for other operations such as image processing, so as to improve the processing efficiency.

The camera application controls the camera device to implement basic operations such as image display (preview), photo saving (photo capture), and video recording. The camera model is developed on the surface model, meaning that an application transfers data through the surface. Specifically, it obtains the photo stream data through the surface of an ImageReceiver object and the preview stream data through the surface of an **XComponent**.

To implement dual-channel preview (there are two preview streams instead of one preview stream plus one photo stream), you must create a previewOutput object through the surface of an ImageReceiver object. Other processes are the same as those of the photo stream and preview stream.

Read [Camera](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

## Constraints

- Currently, streams cannot be dynamically added. In other words, you cannot call [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) to add streams without calling [session.stop](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#stop11) first.
- After an ImageReceiver object processes image data obtained, it must release the image buffer so that the buffer queue of the surface properly rotates.

## API Calling Process

The figure below shows the recommended API calling process of the dual-channel preview solution.

![dual-preview-streams-instructions](figures/dual-preview-streams-instructions.png)

## How to Develop

- For the first preview stream used for image processing, create an ImageReceiver object, obtain the surface ID to create the first preview stream, register an image listener, and process each frame of image data in the preview stream as required.
- For the second preview stream used for image display, create an **XComponent**, obtain the surface ID to create the second preview stream, and render the preview stream data in the component.
- To enable both preview streams to obtain data, configure a camera session for both preview streams, and start the session.

### First Preview Stream Used for Image Processing

1. Import dependencies, including dependencies related to image and camera framework.

    ```ts
    import { image } from '@kit.ImageKit';
    import { camera } from '@kit.CameraKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Obtain the surface ID for the first preview stream. Specifically, create an ImageReceiver object, and obtain the surface ID through the object.

    ```ts
    let imageWidth: number = 1920; // Use the width in the profile size supported by the device.
    let imageHeight: number = 1080; // Use the height in the profile size supported by the device.

    async function initImageReceiver():Promise<void>{
      // Create an ImageReceiver object.
      let size: image.Size = { width: imageWidth, height: imageHeight };
      let imageReceiver: image.ImageReceiver | undefined;
      try {
        imageReceiver = image.createImageReceiver(size, image.ImageFormat.JPEG, 8);
      }  catch (error) {
        let err = error as BusinessError;
        console.error(`Init image receiver failed. error code: ${err.code}`);
        return;
      }
      // Obtain the surface ID for the first preview stream.
      let imageReceiverSurfaceId = await imageReceiver.getReceivingSurfaceId();
      console.info(`initImageReceiver imageReceiverSurfaceId:${imageReceiverSurfaceId}`);
    }
    ```
3. Obtain the image or PixelMap formats of the preview stream received by ImageReceiver. For details about the image format, see the **format** parameter in [Image](../../reference/apis-image-kit/arkts-apis-image-Image.md). For details about the [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) format, see [PixelMapFormat](../../reference/apis-image-kit/arkts-apis-image-e.md#pixelmapformat7).

    ```ts
    // Mappings between image formats and PixelMap formats.
    let formatToPixelMapFormatMap = new Map<number, image.PixelMapFormat>([
      [12, image.PixelMapFormat.RGBA_8888],
      [25, image.PixelMapFormat.NV21],
      [35, image.PixelMapFormat.YCBCR_P010],
      [36, image.PixelMapFormat.YCRCB_P010]
    ]);
    // Mapping of the size of a single pixel for each PixelMapFormat.
    let pixelMapFormatToSizeMap = new Map<image.PixelMapFormat, number>([
      [image.PixelMapFormat.RGBA_8888, 4],
      [image.PixelMapFormat.NV21, 1.5],
      [image.PixelMapFormat.YCBCR_P010, 3],
      [image.PixelMapFormat.YCRCB_P010, 3]
    ]);
    ```

4. Register a listener to process each frame of image data in the preview stream. Specifically, use the **imageArrival** event in the ImageReceiver object to obtain the image data returned by the bottom layer. For details, see [Image API Reference](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md).

    > **NOTE**
    >
    > - When you create a [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) instance using the [createPixelMap](../../reference/apis-image-kit/arkts-apis-image-f.md#imagecreatepixelmap8) API, the properties such as **Size** and **srcPixelFormat** must match **Size** and **Format** configured in preview output stream's preview profile. For details about the image pixel format of ImageReceiver, see [PixelMapFormat](../../reference/apis-image-kit/arkts-apis-image-e.md#pixelmapformat7). For details about the output format the preview profile, see [CameraFormat](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraformat).
    > - Due to the variability across different devices, you must obtain the preview profiles supported by the current device by calling [getSupportedOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedoutputcapability11) before creating a preview output stream. Then based on actual service requirements, select a suitable preview profile that meets the required [CameraFormat](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraformat) and [Size](../../reference/apis-camera-kit/arkts-apis-camera-i.md#size).
    > - The actual format of the preview stream image data received by ImageReceiver is determined by the **format** parameter in the preview profile that you select based on service requirements when creating the preview output stream. For details, see [Enabling a Preview Stream to Obtain Data](camera-dual-channel-preview.md#enabling-a-preview-stream-to-obtain-data).

    ```ts
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
              let imageFormat = nextImage.format; // Obtain the image format.
              let pixelMapFormat = formatToPixelMapFormatMap.get(imageFormat) ?? image.PixelMapFormat.NV21;
              let mSize = pixelMapFormatToSizeMap.get(pixelMapFormat) ?? 1.5;
              console.info(`getComponent with width:${width} height:${height} stride:${stride}`);
              // If PixelMap is required, refer to the following logic.
              // The values of size and srcPixelFormat used during PixelMap creation must match size and format in the preview profile of the preview output stream.
              // The value of stride is the same as that of width.
              let pixelMap : image.PixelMap;
              if (stride == width) {
                pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
                  size: { height: height, width: width },
                  srcPixelFormat: pixelMapFormat,
                })
              } else {
                // The value of stride is different from that of width.
                const dstBufferSize = width * height * mSize
                const dstArr = new Uint8Array(dstBufferSize)
                for (let j = 0; j < height * mSize; j++) {
                  const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width)
                  dstArr.set(srcBuf, j * width)
                }
                pixelMap = await image.createPixelMap(dstArr.buffer, {
                  size: { height: height, width: width },
                  srcPixelFormat: pixelMapFormat,
                })
              }
              // Release the resource when the pixelMap is not in use.
              if (pixelMap != undefined) {
                await pixelMap.release().then(() => {
                  console.info('Succeeded in releasing pixelMap object.');
                }).catch((error: BusinessError) => {
                  console.error(`Failed to release pixelMap object. code is ${error.code}, message is ${error.message}`);
                })
              }
            } else {
              console.error('byteBuffer is null');
            }
            // Release the resource when the pixelMap is not in use.
            if (pixelMap != undefined) {
              await pixelMap.release().then(() => {
                console.info('Succeeded in releasing pixelMap object.');
              }).catch((error: BusinessError) => {
                console.error(`Failed to release pixelMap object. code is ${error.code}, message is ${error.message}`);
              })
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
// The values of size and srcPixelFormat used during PixelMap creation must match size and format in the preview profile of the preview output stream.
const dstBufferSize = width * height * mSize;
const dstArr = new Uint8Array(dstBufferSize);
// Read the buffer data line by line.
for (let j = 0; j < height * mSize; j++) {
  // Copy the first width bytes of each line of data in imgComponent.byteBuffer to dstArr.
  const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width);
  dstArr.set(srcBuf, j * width);
}
let pixelMap = await image.createPixelMap(dstArr.buffer, {
  size: { height: height, width: width }, srcPixelFormat: pixelMapFormat

});
```

Method 2: Create a PixelMap based on the value of stride * height, and call **cropSync** of the PixelMap to crop redundant pixels.

```ts
// Create a PixelMap, with width set to the value of stride.
let pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
  size:{height: height, width: stride}, srcPixelFormat: pixelMapFormat});
// Crop extra pixels.
pixelMap.cropSync({size:{width:width, height:height}, x:0, y:0});
```

Method 3: Pass **imgComponent.byteBuffer** and **stride** to the API that supports stride.

### Second Preview Stream Used for Image Display

To obtain the surface ID of the second preview stream, you must first create an **XComponent** for displaying the preview stream. For details about how to obtain the surface ID, see [getXComponentSurfaceId](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9). The **XComponent** capability is provided by the UI. For details, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

```ts
@Component
struct example {
  xComponentCtl: XComponentController = new XComponentController();
  surfaceId:string = '';
  imageWidth: number = 1920;
  imageHeight: number = 1080;
  private uiContext: UIContext = this.getUIContext();

  build() {
    XComponent({
      id: 'componentId',
      type: XComponentType.SURFACE,
      controller: this.xComponentCtl
    })
      .onLoad(async () => {
        console.info('onLoad is called');
        this.surfaceId = this.xComponentCtl.getXComponentSurfaceId(); // Obtain the surface ID of the component.
        // Use the surface ID to create a preview stream and start the camera. The component renders the preview stream data of each frame in real time.
      })
      // The width and height of the surface are opposite to those of the XComponent. Alternatively, you can use .renderFit(RenderFit.RESIZE_CONTAIN) to automatically adjust the display without manually setting the width and height.
      .width(this.uiContext.px2vp(this.imageHeight))
      .height(this.uiContext.px2vp(this.imageWidth))
  }
}
```

### Enabling a Preview Stream to Obtain Data

Create two preview outputs with two surface IDs, add the outputs to a camera session, and start the camera session to obtain the preview stream data.

```ts
function createDualPreviewOutput(cameraManager: camera.CameraManager, previewProfile: camera.Profile,
  session: camera.Session, imageReceiverSurfaceId: string, xComponentSurfaceId: string): void {
  try {
    // Create the first preview output by using imageReceiverSurfaceId.
    let previewOutput1 = cameraManager.createPreviewOutput(previewProfile, imageReceiverSurfaceId);
    if (!previewOutput1) {
      console.error('createPreviewOutput1 error');
      return;
    }
    // Create the second preview output by using xComponentSurfaceId.
    let previewOutput2 = cameraManager.createPreviewOutput(previewProfile, xComponentSurfaceId);
    if (!previewOutput2) {
      console.error('createPreviewOutput2 error');
      return;
    }
    // Add the output of the first preview stream.
    session.addOutput(previewOutput1);
    // Add the output of the second preview stream.
    session.addOutput(previewOutput2);
  } catch (error) {
    console.error('createDualPreviewOutput  call failed');
  }
}
```

## Complete Sample Code

```ts
import { camera } from '@kit.CameraKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';

interface CameraResources {
  videoOutput?: camera.VideoOutput;
  cameraInput?: camera.CameraInput;
  previewOutput1?: camera.PreviewOutput;
  previewOutput2?: camera.PreviewOutput;
  session?: camera.VideoSession;
}

@Entry
@Component
struct Index {
  private imageReceiver: image.ImageReceiver | undefined = undefined;
  private imageReceiverSurfaceId: string = '';
  private xComponentCtl: XComponentController = new XComponentController();
  private xComponentSurfaceId: string = '';
  @State imageWidth: number = 1920;
  @State imageHeight: number = 1080;
  private cameraManager: camera.CameraManager | undefined = undefined;
  private cameras: Array<camera.CameraDevice> | undefined = [];
  private uiContext: UIContext = this.getUIContext();
  private context: Context | undefined = this.uiContext.getHostContext();
  private cameraPermission: Permissions = 'ohos.permission.CAMERA'; // For details about how to request permissions, see the instructions provided at the beginning of this topic.
  @State isShow: boolean = false;
  private cameraResources: CameraResources = {};

  async requestPermissionsFn(): Promise<void> {
    let atManager = abilityAccessCtrl.createAtManager();
    if (this.context) {
      let res = await atManager.requestPermissionsFromUser(this.context, [this.cameraPermission]);
      if (!res || !res.permissions || res.permissions.length === 0) {
        console.error('requestPermissionsFromUser interface call fails');
        return;
      }
      if (res.permissions.length !== res.authResults.length) {
        console.error('Authentication result mismatch');
        return;
      }
      res.permissions.forEach((value: string, index: number, permissions: string[]) => {
        if (this.cameraPermission.toString() === value && res.authResults[index] === 0) {
          this.isShow = true;
        }
      })
    }
  }

  aboutToAppear(): void {
    this.requestPermissionsFn();
  }

  onPageShow(): void {
    console.info('onPageShow');
    this.initImageReceiver();
    if (this.xComponentSurfaceId !== '') {
      this.initCamera();
    }
  }

  onPageHide(): void {
    console.info('onPageHide');
    this.releaseCamera();
  }

  /**
   * Obtain the surface ID of the ImageReceiver object.
   * @param receiver
   * @returns
   */
  async initImageReceiver(): Promise<void> {
    if (!this.imageReceiver) {
      // Create an ImageReceiver object.
      let size: image.Size = { width: this.imageWidth, height: this.imageHeight };
      try {
        this.imageReceiver = image.createImageReceiver(size, image.ImageFormat.JPEG, 8);
      } catch (error) {
        let err = error as BusinessError;
        console.error(`Init image receiver failed. error code: ${err.code}`);
        return;
      }
      // Obtain the surface ID for the first preview stream.
      this.imageReceiverSurfaceId = await this.imageReceiver.getReceivingSurfaceId();
      console.info(`initImageReceiver imageReceiverSurfaceId:${this.imageReceiverSurfaceId}`);
      // Register a listener to listen for and process the image data of each frame in the preview stream.
      this.onImageArrival(this.imageReceiver);
    }
  }

  // Mappings between image formats and PixelMap formats.
  private formatToPixelMapFormatMap = new Map<number, image.PixelMapFormat>([
    [12, image.PixelMapFormat.RGBA_8888],
    [25, image.PixelMapFormat.NV21],
    [35, image.PixelMapFormat.YCBCR_P010],
    [36, image.PixelMapFormat.YCRCB_P010]
  ]);
  // Mapping of the size of a single pixel for each PixelMapFormat.
  private pixelMapFormatToSizeMap = new Map<image.PixelMapFormat, number>([
    [image.PixelMapFormat.RGBA_8888, 4],
    [image.PixelMapFormat.NV21, 1.5],
    [image.PixelMapFormat.YCBCR_P010, 3],
    [image.PixelMapFormat.YCRCB_P010, 3]
  ]);

  /**
   * Register a listener for the ImageReceiver object.
   * @param receiver
   */
  onImageArrival(receiver: image.ImageReceiver): void {
    // Subscribe to the imageArrival event.
    receiver.on('imageArrival', () => {
      console.info('image arrival');
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
            // Parse the buffer data by referring to step 7. This example uses method 1 as an example.
            let width = nextImage.size.width; // Obtain the image width.
            let height = nextImage.size.height; // Obtain the image height.
            let stride = imgComponent.rowStride; // Obtain the image stride.
            let imageFormat = nextImage.format; // Obtain the image format.
            let pixelMapFormat = this.formatToPixelMapFormatMap.get(imageFormat) ?? image.PixelMapFormat.NV21;
            let mSize =  this.pixelMapFormatToSizeMap.get(pixelMapFormat) ?? 1.5;
            console.info(`getComponent with width:${width} height:${height} stride:${stride}`);
            // The values of size and srcPixelFormat used during PixelMap creation must match size and format in the preview profile of the preview output stream. The NV21 format is used as an example.
            // The value of stride is the same as that of width.
            let pixelMap: image.PixelMap;
            if (stride == width) {
              pixelMap = await image.createPixelMap(imgComponent.byteBuffer, {
                size: { height: height, width: width },
                srcPixelFormat: pixelMapFormat,
              })
            } else {
              // The value of stride is different from that of width.
              const dstBufferSize = width * height * mSize // For example, for NV21 (images in YUV_420_SP format), the formula for calculating the YUV_420_SP memory is as follows: YUV_420_SP memory = Width * Height + (Width * Height)/2
              const dstArr = new Uint8Array(dstBufferSize)
              for (let j = 0; j < height * mSize; j++) {
                const srcBuf = new Uint8Array(imgComponent.byteBuffer, j * stride, width)
                dstArr.set(srcBuf, j * width)
              }
              pixelMap = await image.createPixelMap(dstArr.buffer, {
                size: { height: height, width: width },
                srcPixelFormat: pixelMapFormat,
              })
            }
            // Release the resource when the pixelMap is not in use.
            if (pixelMap != undefined) {
              await pixelMap.release().then(() => {
                console.info('Succeeded in releasing pixelMap object.');
              }).catch((error: BusinessError) => {
                console.error(`Failed to release pixelMap object. code is ${error.code}, message is ${error.message}`);
              })
            }
          } else {
            console.error('byteBuffer is null');
          }
          // Release the resource when the pixelMap is not in use.
          if (pixelMap != undefined) {
            await pixelMap.release().then(() => {
              console.info('Succeeded in releasing pixelMap object.');
            }).catch((error: BusinessError) => {
              console.error(`Failed to release pixelMap object. code is ${error.code}, message is ${error.message}`);
            })
          }
          // Release the resource when the buffer is not in use.
          // If an asynchronous operation is performed on the buffer, call nextImage.release() to release the resource after the asynchronous operation is complete.
          nextImage.release();
          console.info('image process done');
        })
      })
    })
  }

  build() {
    Column() {
      if (this.isShow) {
        XComponent({
          id: 'componentId',
          type: XComponentType.SURFACE,
          controller: this.xComponentCtl
        })
          .onLoad(async () => {
            console.info('onLoad is called');
            this.xComponentSurfaceId = this.xComponentCtl.getXComponentSurfaceId(); // Obtain the surface ID of the component.
            // Initialize the camera. The component renders the preview stream data of each frame in real time.
            this.initCamera()
          })
          .width(this.uiContext.px2vp(this.imageHeight))
          .height(this.uiContext.px2vp(this.imageWidth))
      }
    }
    .justifyContent(FlexAlign.Center)
    .height('100%')
    .width('100%')
  }

  // Initialize a camera.
  async initCamera(): Promise<void> {
    console.info(`initCamera imageReceiverSurfaceId:${this.imageReceiverSurfaceId} xComponentSurfaceId:${this.xComponentSurfaceId}`);
    try {
      // Obtain a camera manager instance.
      this.cameraManager = camera.getCameraManager(this.context);
      if (!this.cameraManager) {
        console.error('getCameraManager call failed');
        return;
      }
      // Obtain the list of cameras supported by the device.
      this.cameras = this.cameraManager.getSupportedCameras();
      if (!this.cameras || this.cameras.length === 0) {
        console.error('getSupportedCameras call failed');
        return;
      }
      // Select a camera device and create a CameraInput object.
      this.cameraResources.cameraInput = this.cameraManager.createCameraInput(this.cameras[0]);
      if (!this.cameraResources.cameraInput) {
        console.error('createCameraInput call failed');
        return;
      }
      // Open the camera.
      await this.cameraResources.cameraInput.open();
      // Obtain the profile supported by the camera device.
      let capability: camera.CameraOutputCapability =
        this.cameraManager.getSupportedOutputCapability(this.cameras[0], camera.SceneMode.NORMAL_VIDEO);
      if (!capability) {
        console.error('getSupportedOutputCapability call failed');
        this.releaseCamera();
        return;
      }
      let minRatioDiff : number = 0.1;
      let surfaceRatio : number = this.imageWidth / this.imageHeight; // The closest aspect ratio to 16:9.
      let previewProfile: camera.Profile = capability.previewProfiles[0];
      // Select a supported preview stream profile based on service requirements.
      // The following uses the preview stream profile with the CAMERA_FORMAT_YUV_420_SP (NV21) format that meets the resolution constraints as an example.
      for (let index = 0; index < capability.previewProfiles.length; index++) {
        const tempProfile = capability.previewProfiles[index];
        let tempRatio = tempProfile.size.width >= tempProfile.size.height ?
          tempProfile.size.width / tempProfile.size.height : tempProfile.size.height / tempProfile.size.width;
        let currentRatio = Math.abs(tempRatio - surfaceRatio);
        if (currentRatio <= minRatioDiff && tempProfile.format == camera.CameraFormat.CAMERA_FORMAT_YUV_420_SP) {
          previewProfile = tempProfile;
          break;
        }
      }
      this.imageWidth = previewProfile.size.width; // Update the width of the XComponent.
      this.imageHeight = previewProfile.size.height; // Update the height of the XComponent.
      console.info(`initCamera imageWidth:${this.imageWidth} imageHeight:${this.imageHeight}`);
      // Create the first preview output by using imageReceiverSurfaceId.
      this.cameraResources.previewOutput1 = this.cameraManager.createPreviewOutput(previewProfile, this.imageReceiverSurfaceId);
      if (!this.cameraResources.previewOutput1) {
        console.error('initCamera createPreviewOutput1');
        this.releaseCamera();
        return;
      }
      // Create the second preview output by using xComponentSurfaceId.
      this.cameraResources.previewOutput2 = this.cameraManager.createPreviewOutput(previewProfile, this.xComponentSurfaceId);
      if (!this.cameraResources.previewOutput2) {
        console.error('initCamera createPreviewOutput2');
        this.releaseCamera();
        return;
      }
      // Create a camera session in recording mode.
      let session = this.cameraManager.createSession(camera.SceneMode.NORMAL_VIDEO)
      if (!session) {
        console.error('session is null');
        this.releaseCamera();
        return;
      }
      this.cameraResources.session = session as camera.VideoSession;
      // Start configuration for the session.
      this.cameraResources.session.beginConfig();
      // Add a camera input.
      this.cameraResources.session.addInput(this.cameraResources.cameraInput);
      // Add the output of the first preview stream.
      this.cameraResources.session.addOutput(this.cameraResources.previewOutput1);
      // Add the output of the second preview stream.
      this.cameraResources.session.addOutput(this.cameraResources.previewOutput2);
      // Commit the session configuration.
      await this.cameraResources.session.commitConfig();
      // Start the configured input and output streams.
      await this.cameraResources.session.start();
    } catch (error) {
      console.error(`initCamera fail: ${JSON.stringify(error)}`);
      this.releaseCamera();
    }
  }

  // Release the camera.
  async releaseCamera(): Promise<void> {
    console.info('releaseCamera E');
    try {
      // Stop the session.
      await this.cameraResources.session?.stop();
    } catch (error) {
      console.error(`session.stop call failed, error: ${JSON.stringify(error)}`);
    }
    try {
      // Release the camera input stream.
      await this.cameraResources.cameraInput?.close();
    } catch (error) {
      console.error(`camera close fail: ${JSON.stringify(error)}`);
    }
    try {
      // Release the preview output stream.
      await this.cameraResources.previewOutput1?.release();
    } catch (error) {
      console.error(`previewOutput1 release fail: ${JSON.stringify(error)}`);
    }
    try {
      // Release the photo output stream.
      await this.cameraResources.previewOutput2?.release();
    } catch (error) {
      console.error(`previewOutput2 release fail: ${JSON.stringify(error)}`);
    }
    try {
      // Release the session.
      await this.cameraResources.session?.release();
    } catch (error) {
      console.error(`session release fail: ${JSON.stringify(error)}`);
    }
  }
}
```

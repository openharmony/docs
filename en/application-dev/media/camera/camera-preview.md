# Preview (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

Before developing a camera application, request permissions by following the instructions provided in [Requesting Camera Development Permissions](camera-preparation.md).

Preview is the image you see after you start the camera application but before you take photos or record videos.

## How to Develop

Read [Module Description](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.
     
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Create a surface.

    The camera development model relies on the surface model, which uses surface for data interaction. When developing the camera application UI, you need to create an XComponent to provide a surface for the preview stream, and then obtain the surface ID associated with the XComponent to create a preview stream. The preview stream can be directly rendered within the XComponent. For details about how to obtain the surface ID, see [getXComponentSurfaceId](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9). The capabilities of the XComponent are provided by the UI. For details, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

    > **NOTE**
    >
    > The preview stream and video output stream must have the same aspect ratio of the resolution. For example, the aspect ratio of the surface of the **XComponent** is 1920:1080 (which is equal to 16:9), then the aspect ratio of the resolution of the preview stream must also be 16:9. This means that the resolution can be 640:360, 960:540, 1920:1080, or the like.

    ```ts
    @Entry
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

3. Use **previewProfiles** in the [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability) class to obtain the preview output capabilities, in the format of an **previewProfilesArray** array, supported by the current device. Then call [createPreviewOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createpreviewoutput) to create a PreviewOutput object, with the first parameter set to the preview profile supported by the camera and the second parameter set to the surface ID obtained in step 2.
     
   ```ts
   function getPreviewOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability, surfaceId: string): camera.PreviewOutput | undefined {
     let previewProfilesArray: Array<camera.Profile> = cameraOutputCapability.previewProfiles;
     let previewOutput: camera.PreviewOutput | undefined = undefined;
     try {
       // Choose the preview profile from previewProfilesArray that matches the aspect ratio set in Step 2. Selecting the first item in the array is for illustrative purposes only.
       previewOutput = cameraManager.createPreviewOutput(previewProfilesArray[0], surfaceId);
     } catch (error) {
       let err = error as BusinessError;
       console.error("Failed to create the PreviewOutput instance. error code: " + err.code);
     }
     return previewOutput;
   }
   ```

4. Call [Session.start](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#start11) to start outputting the preview stream. If the call fails, an error code is returned. For details, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).
     
   ```ts
   async function startPreviewOutput(cameraManager: camera.CameraManager, previewOutput: camera.PreviewOutput): Promise<void> {
     let cameraArray: Array<camera.CameraDevice> = [];
     cameraArray = cameraManager.getSupportedCameras();
     if (cameraArray.length == 0) {
       console.error('no camera.');
       return;
     }
     // Obtain the supported modes.
     let sceneModes: Array<camera.SceneMode> = cameraManager.getSupportedSceneModes(cameraArray[0]);
     let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
     if (!isSupportPhotoMode) {
       console.error('photo mode not support');
       return;
     }
     let cameraInput: camera.CameraInput | undefined = undefined;
     cameraInput = cameraManager.createCameraInput(cameraArray[0]);
     if (cameraInput === undefined) {
       console.error('cameraInput is undefined');
       return;
     }
     // Open the camera.
     await cameraInput.open();
     let session: camera.PhotoSession = cameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
     session.beginConfig();
     session.addInput(cameraInput);
     session.addOutput(previewOutput);
     await session.commitConfig();
     await session.start();
   }
   ```


## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the **'frameStart'** event to listen for preview start events. This event can be registered when a PreviewOutput object is created and is triggered when the bottom layer starts exposure for the first time. The preview stream starts as long as a result is returned.
    
  ```ts
  function onPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameStart', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Preview frame started');
    });
  }
  ```

- Register the **'frameEnd'** event to listen for preview end events. This event can be registered when a PreviewOutput object is created and is triggered when the last frame of preview ends. The preview stream ends as long as a result is returned.
    
  ```ts
  function onPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameEnd', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Preview frame ended');
    });
  }
  ```

- Register the **'error'** event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).
    
  ```ts
  function onPreviewOutputError(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('error', (previewOutputError: BusinessError) => {
      console.error(`Preview output error code: ${previewOutputError.code}`);
    });
  }
  ```

## Sample Code

```ts
import { camera } from '@kit.CameraKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, Permissions } from '@kit.AbilityKit';


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
  private cameras: Array<camera.CameraDevice> | Array<camera.CameraDevice> = [];
  private cameraInput: camera.CameraInput | undefined = undefined;
  private previewOutput: camera.PreviewOutput | undefined = undefined;
  private session: camera.VideoSession | undefined = undefined;
  private uiContext: UIContext = this.getUIContext();
  private context: Context | undefined = this.uiContext.getHostContext();
  private cameraPermission: Permissions = 'ohos.permission.CAMERA'; // For details about how to request permissions, see the instructions provided at the beginning of this topic.
  @State isShow: boolean = false;


  async requestPermissionsFn(): Promise<void> {
    let atManager = abilityAccessCtrl.createAtManager();
    if (this.context) {
      let res = await atManager.requestPermissionsFromUser(this.context, [this.cameraPermission]);
      for (let i =0; i < res.permissions.length; i++) {
        if (this.cameraPermission.toString() === res.permissions[i] && res.authResults[i] === 0) {
          this.isShow = true;
        }
      }
    }
  }

  aboutToAppear(): void {
    this.requestPermissionsFn();
  }

  onPageShow(): void {
    console.info('onPageShow');
    if (this.xComponentSurfaceId !== '') {
      this.initCamera();
    }
  }

  onPageHide(): void {
    console.info('onPageHide');
    this.releaseCamera();
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
    console.info(`initCamera previewOutput xComponentSurfaceId:${this.xComponentSurfaceId}`);
    try {
      // Obtain a camera manager instance.
      this.cameraManager = camera.getCameraManager(this.context);
      if (!this.cameraManager) {
        console.error('initCamera getCameraManager');
      }
      // Obtain the list of cameras supported by the device.
      this.cameras = this.cameraManager.getSupportedCameras();
      if (!this.cameras) {
        console.error('initCamera getSupportedCameras');
      }
      // Select a camera device and create a CameraInput object.
      this.cameraInput = this.cameraManager.createCameraInput(this.cameras[0]);
      if (!this.cameraInput) {
        console.error('initCamera createCameraInput');
      }
      // Open the camera.
      await this.cameraInput.open().catch((err: BusinessError) => {
        console.error(`initCamera open fail: ${err}`);
      })
      // Obtain the profile supported by the camera device.
      let capability: camera.CameraOutputCapability =
        this.cameraManager.getSupportedOutputCapability(this.cameras[0], camera.SceneMode.NORMAL_VIDEO);
      if (!capability) {
        console.error('initCamera getSupportedOutputCapability');
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

      // Create a preview using xComponentSurfaceId.
      this.previewOutput = this.cameraManager.createPreviewOutput(previewProfile, this.xComponentSurfaceId);
      if (!this.previewOutput) {
        console.error('initCamera createPreviewOutput');
      }
      // Create a camera session in recording mode.
      this.session = this.cameraManager.createSession(camera.SceneMode.NORMAL_VIDEO) as camera.VideoSession;
      if (!this.session) {
        console.error('initCamera createSession');
      }
      // Start configuration for the session.
      this.session.beginConfig();
      // Add a camera input.
      this.session.addInput(this.cameraInput);
      // Add a preview output stream.
      this.session.addOutput(this.previewOutput);
      // Commit the session configuration.
      await this.session.commitConfig();
      // Start the configured input and output streams.
      await this.session.start();
    } catch (error) {
      console.error(`initCamera fail: ${error}`);
    }
  }


  // Release the camera.
  async releaseCamera(): Promise<void> {
    console.info('releaseCamera E');
    try {
      // Stop the session.
      await this.session?.stop();
      // Release the camera input stream.
      await this.cameraInput?.close();
      // Release the preview output stream.
      await this.previewOutput?.release();
      // Release the session.
      await this.session?.release();
    } catch (error) {
      console.error(`initCamera fail: ${error}`);
    }
  }
}
```
